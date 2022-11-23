#include <array>
#include <cmath>
#include <cstring>
#include <iterator>
#include <tuple>
#include <vector>

#include <common/zlib.hpp>

namespace
{
using namespace neutrino;

constexpr static std::uint32_t max_code_size   = 16;
constexpr static std::uint32_t max_window_size = 32768;
constexpr static std::uint32_t max_block_size  = 65535;

constexpr static std::uint32_t deflate_compression_method = 8;

constexpr static std::uint32_t litlen_alphabet_size   = 288;
constexpr static std::uint32_t distance_alphabet_size = 32;

constexpr static std::uint32_t end_of_block_code = 256;
constexpr static std::uint32_t invalid_code      = 300;

enum class CompressionAlgorithm
{
    fastest           = 0, // - compressor used fastest algorithm
    fast              = 1, // - compressor used fast algorithm
    default_algorithm = 2, // - compressor used default algorithm
    maximum           = 3, // - compressor used maximum compression, slowest algorithm
};

class BitStream
{
public:
    explicit BitStream(const std::vector<std::uint8_t>& data)
        : m_data(data)
    {}

    template <typename T>
    T get(std::uint32_t count)
    {
        return static_cast<T>(get_implementation(static_cast<std::uint32_t>(count % (sizeof(T) * 8 + 1))));
    }

    void skip_this_byte()
    {
        m_buffer = static_cast<std::uint32_t>(m_buffer >> m_bits);
        m_bits   = 0;
    }

    operator bool() const
    {
        return m_byte < m_data.size() || m_bits > 0;
    }

private:
    std::uint32_t get_implementation(std::uint32_t count)
    {
        constexpr static std::uint32_t mask[33] = {
        0x00000000,                                                                                     //
        0x00000001, 0x00000003, 0x00000007, 0x0000000F, 0x0000001F, 0x0000003F, 0x0000007F, 0x000000FF, // 1 - 8
        0x000001FF, 0x000003FF, 0x000007FF, 0x00000FFF, 0x00001FFF, 0x00003FFF, 0x00007FFF, 0x0000FFFF, // 9 - 16
        0x0001FFFF, 0x0003FFFF, 0x0007FFFF, 0x000FFFFF, 0x001FFFFF, 0x003FFFFF, 0x007FFFFF, 0x00FFFFFF, // 17 - 24
        0x01FFFFFF, 0x03FFFFFF, 0x07FFFFFF, 0x0FFFFFFF, 0x1FFFFFFF, 0x3FFFFFFF, 0x7FFFFFFF, 0xFFFFFFFF, // 25 - 32
        };

        while (m_bits < count && m_byte < m_data.size()) {
            m_buffer = static_cast<std::uint32_t>(m_buffer | static_cast<std::uint32_t>(m_data[m_byte] << m_bits));
            m_bits += 8;
            m_byte++;
        }

        if (!(this->operator bool())) {
            return 0;
        }

        count = std::min(m_bits, count);

        const std::uint32_t res = static_cast<std::uint32_t>(m_buffer & mask[count]);

        m_buffer = static_cast<std::uint32_t>(m_buffer >> count);
        m_bits -= count;

        return res;
    }

    std::uint32_t m_buffer = 0;
    std::uint32_t m_bits   = 0;
    std::size_t m_byte     = 0;
    const std::vector<std::uint8_t>& m_data;
};

std::uint16_t reflect(std::uint16_t value, std::uint8_t size)
{
    std::uint16_t ref = 0;

    for (std::size_t bit = 0; bit < size; ++bit) {
        if (value & 1) {
            ref = static_cast<std::uint16_t>(ref | 1 << (size - 1 - bit));
        }
        value = static_cast<std::uint16_t>(value >> 1);
    }

    return ref;
}

class HuffmanCodeTable
{
public:
    explicit HuffmanCodeTable(const std::vector<std::uint8_t>& codes_lengths)
    {
        build_codes(codes_lengths);
    }

    std::uint16_t decode(BitStream& in) const
    {
        std::uint8_t value_len = m_min_codes_length;
        std::uint16_t value    = reflect(in.get<std::uint16_t>(value_len), value_len);

        auto get_literal = [this](std::uint16_t val, std::uint8_t len) -> std::uint16_t {
            if (len >= max_code_size) {
                return invalid_code;
            }

            const std::size_t index = val - m_start_code[len];
            if (index >= m_codes[len].size()) {
                return invalid_code;
            }

            return m_codes[len][index];
        };

        std::uint16_t lit = get_literal(value, value_len);
        while (lit == invalid_code && value_len < max_code_size) {
            value = static_cast<std::uint16_t>((value << 1) | in.get<std::uint16_t>(1));
            value_len++;
            lit = get_literal(value, value_len);
        }

        return lit;
    }

private:
    void build_codes(const std::vector<std::uint8_t>& lengths)
    {
        std::vector<std::uint8_t> bl_count(max_code_size);

        for (auto len : lengths) {
            if (len >= max_code_size) {
                return; // error
            }

            if (len > 0 && len < m_min_codes_length) {
                m_min_codes_length = len;
            }

            bl_count[len]++;
        }
        bl_count[0] = 0;

        m_start_code.clear();
        m_start_code.resize(max_code_size);

        std::uint16_t code = 0;
        for (std::size_t bits = 1; bits < bl_count.size(); bits++) {
            code = static_cast<std::uint16_t>((code + bl_count[bits - 1]) << 1);

            m_start_code[bits] = code;
        }

        m_codes.clear();
        m_codes.resize(max_code_size);

        for (std::size_t i = 0; i < bl_count.size(); ++i) {
            m_codes[i].resize(bl_count[i], invalid_code);
        }

        auto next_code = m_start_code;
        for (std::size_t n = 0; n < lengths.size(); n++) {
            std::size_t len = lengths[n];

            if (len != 0) {
                const std::size_t index = next_code[len] - m_start_code[len];
                m_codes[len][index]     = static_cast<std::uint16_t>(n);
                next_code[len]++;
            }
        }
    }

    std::vector<std::vector<std::uint16_t>> m_codes;
    std::vector<std::uint16_t> m_start_code;
    std::uint8_t m_min_codes_length = sizeof(std::uint16_t) * 8;
}; // namespace

using LitLenDistanceCodes = std::tuple<HuffmanCodeTable, HuffmanCodeTable>;

struct ZlibHeader
{
    std::uint8_t cm : 4;
    std::uint8_t cinfo : 4;
    std::uint8_t fcheck : 5;
    std::uint8_t fdict : 1;
    std::uint8_t flevel : 3;

    ZlibHeader() = default;

    explicit ZlibHeader(std::uint16_t value)
    {
        memcpy(this, &value, sizeof(value));
    }

    std::uint16_t as_value() const
    {
        std::uint16_t tmp;
        memcpy(&tmp, this, sizeof(std::uint16_t));

        const std::uint16_t res = static_cast<std::uint16_t>(((tmp & 0xFF) << 8) | ((tmp >> 8) & 0xFF));
        return res;
    }
};

struct BlockHeader
{
    enum Type
    {
        no_compression  = 0,
        dynamic_huffman = 2,
        fixed_huffman   = 1,
        reserved        = 3,
    };

    std::uint8_t bfinal : 1;
    std::uint8_t btype : 2;

    BlockHeader()
        : bfinal(0)
        , btype(no_compression)
    {}

    explicit BlockHeader(std::uint8_t value)
    {
        memcpy(this, &value, sizeof(value));
    }

    operator std::uint8_t() const
    {
        std::uint8_t res;
        memcpy(&res, this, sizeof(std::uint8_t));
        return res;
    }
};

LitLenDistanceCodes fixed_huffman_codes()
{
    /*
     Lit Value    Bits   Count   Codes
     ---------    ----   -----   -----
       0 - 143     8     144     00110000  through 10111111
     144 - 255     9     112     110010000 through 111111111
     256 - 279     7     24      0000000   through 0010111
     280 - 287     8     8       11000000  through 11000111
    */

    auto init_litlen_alphabet = []() {
        std::vector<std::uint8_t> data(litlen_alphabet_size);
        for (std::size_t i = 0; i < data.size(); ++i) {
            data[i] = ((i <= 143 || i >= 280) ? 8 : (i >= 144 && i <= 255 ? 9 : 7));
        }
        return data;
    };

    static const std::vector<std::uint8_t> litlen_alphabet = init_litlen_alphabet();
    static const std::vector<std::uint8_t> distance_alphabet(distance_alphabet_size, 5);
    static const auto codes = std::make_tuple(HuffmanCodeTable(litlen_alphabet), HuffmanCodeTable(distance_alphabet));

    return codes;
}

LitLenDistanceCodes dynamic_huffman_codes(BitStream& in)
{
    constexpr static std::array<std::uint8_t, 19> length_order = {
    16, 17, 18, 0, 8, 7, 9, 6, 10, 5, 11, 4, 12, 3, 13, 2, 14, 1, 15,
    };

    const std::uint16_t hlit  = in.get<std::uint16_t>(5);
    const std::uint16_t hdist = in.get<std::uint16_t>(5);
    const std::uint16_t hclen = in.get<std::uint16_t>(4);

    const std::size_t lit_len_codes_count  = hlit + 257;
    const std::size_t distance_codes_count = hdist + 1;
    const std::size_t code_len_codes_count = hclen + 4;

    std::vector<std::uint8_t> code_lengths(19);

    for (std::size_t i = 0; i < code_len_codes_count; ++i) {
        code_lengths[length_order[i]] = static_cast<std::uint8_t>(in.get<std::uint16_t>(3));
    }

    const HuffmanCodeTable len_huffman(code_lengths);

    std::vector<std::uint8_t> lengths;
    lengths.reserve(lit_len_codes_count + distance_codes_count);
    for (std::size_t i = 0; i < lit_len_codes_count + distance_codes_count;) {
        const std::uint8_t len = static_cast<std::uint8_t>(len_huffman.decode(in));
        if (len <= 15) {
            lengths.push_back(len);
            i++;
        } else if (len == 16 && lengths.size() > 0) {
            const std::uint8_t count = static_cast<std::uint8_t>(in.get<std::uint8_t>(2) + 3);
            lengths.insert(lengths.end(), count, lengths.back());
            i += count;
        } else if (len == 17) {
            const std::uint8_t count = static_cast<std::uint8_t>(in.get<std::uint8_t>(3) + 3);
            lengths.insert(lengths.end(), count, 0);
            i += count;
        } else if (len == 18) {
            const std::uint8_t count = static_cast<std::uint8_t>(in.get<std::uint8_t>(7) + 11);
            lengths.insert(lengths.end(), count, 0);
            i += count;
        }
    }

    const auto first_dist_code = next(begin(lengths), static_cast<std::ptrdiff_t>(lit_len_codes_count));
    const std::vector<std::uint8_t> litlen(begin(lengths), first_dist_code);
    const std::vector<std::uint8_t> dist(first_dist_code, end(lengths));

    return std::make_tuple(HuffmanCodeTable(litlen), HuffmanCodeTable(dist));
}

std::uint16_t read_length(std::uint16_t value, BitStream& in)
{
    //      Extra               Extra               Extra
    // Code Bits Length(s) Code Bits Lengths   Code Bits Length(s)
    // 257   0     3       267   1   15,16     277   4   67-82
    // 258   0     4       268   1   17,18     278   4   83-98
    // 259   0     5       269   2   19-22     279   4   99-114
    // 260   0     6       270   2   23-26     280   4  115-130
    // 261   0     7       271   2   27-30     281   5  131-162
    // 262   0     8       272   2   31-34     282   5  163-194
    // 263   0     9       273   3   35-42     283   5  195-226
    // 264   0    10       274   3   43-50     284   5  227-257
    // 265   1  11,12      275   3   51-58     285   0    258
    // 266   1  13,14      276   3   59-66

    constexpr static std::uint16_t start_len = 257;

    constexpr static std::array<std::uint32_t, 29> extra_bits_description = {
    0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 0,
    };

    constexpr static std::array<std::uint32_t, 29> start_value_description = {
    3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 15, 17, 19, 23, 27, 31, 35, 43, 51, 59, 67, 83, 99, 115, 131, 163, 195, 227, 258,
    };

    const std::uint32_t extra_bits  = extra_bits_description[value - start_len];
    const std::uint32_t start_value = start_value_description[value - start_len];

    std::uint32_t result = start_value;
    if (extra_bits > 0) {
        result += in.get<std::uint16_t>(extra_bits);
    }

    return static_cast<std::uint16_t>(result);
}

std::uint16_t read_distance(std::uint16_t value, BitStream& in)
{
    //      Extra           Extra                Extra
    // Code Bits Dist  Code Bits   Dist     Code Bits Distance
    // ---- ---- ----  ---- ----  ------    ---- ---- --------
    // 0    0    1     10   4     33-48     20    9     1025-1536
    // 1    0    2     11   4     49-64     21    9     1537-2048
    // 2    0    3     12   5     65-96     22   10     2049-3072
    // 3    0    4     13   5     97-128    23   10     3073-4096
    // 4    1   5,6    14   6    129-192    24   11     4097-6144
    // 5    1   7,8    15   6    193-256    25   11     6145-8192
    // 6    2   9-12   16   7    257-384    26   12    8193-12288
    // 7    2  13-16   17   7    385-512    27   12   12289-16384
    // 8    3  17-24   18   8    513-768    28   13   16385-24576
    // 9    3  25-32   19   8   769-1024    29   13   24577-32768

    constexpr static std::array<std::uint32_t, 30> extra_bits_description = {
    0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13,
    };

    constexpr static std::array<std::uint32_t, 30> start_value_description = {
    1,   2,   3,   4,   5,   7,    9,    13,   17,   25,   33,   49,   65,    97,    129,
    193, 257, 385, 513, 769, 1025, 1537, 2049, 3073, 4097, 6145, 8193, 12289, 16385, 24577,
    };

    const std::uint32_t extra_bits  = extra_bits_description[value];
    const std::uint32_t start_value = start_value_description[value];

    std::uint32_t result = start_value;
    if (extra_bits > 0) {
        result += in.get<std::uint16_t>(extra_bits);
    }

    return static_cast<std::uint16_t>(result);
}

void inflate_no_compression(BitStream& in, std::vector<std::uint8_t>& output)
{
    in.skip_this_byte();
    std::uint16_t len = in.get<std::uint16_t>(16);

    [[maybe_unused]] std::uint16_t nlen = in.get<std::uint16_t>(16);

    for (std::size_t i = 0; i < len; ++i) {
        output.push_back(in.get<std::uint8_t>(8));
    }
}

void inflate_compression(const LitLenDistanceCodes& codes_pair, BitStream& in, std::vector<std::uint8_t>& output)
{
    const auto [codes, distances] = codes_pair;

    while (in) {
        const std::uint16_t value = codes.decode(in);
        if (value < end_of_block_code) {
            output.push_back(static_cast<std::uint8_t>(value));
        } else if (value > end_of_block_code && value < litlen_alphabet_size) {
            const std::uint16_t length    = read_length(value, in);
            const std::uint16_t dist_code = distances.decode(in);
            const std::uint16_t distance  = read_distance(dist_code, in);

            if (distance >= output.size()) {
                break; // error
            }

            for (std::size_t i = 0, pos = output.size() - distance; i < length; ++i, ++pos) {
                output.push_back(output[pos]);
            }
        } else {
            break; // error
        }
    }
}

inline void inflate_fixed_huffman(BitStream& in, std::vector<std::uint8_t>& output)
{
    const auto codes_pair = fixed_huffman_codes();
    inflate_compression(codes_pair, in, output);
}

inline void inflate_dynamic_huffman(BitStream& in, std::vector<std::uint8_t>& output)
{
    const auto codes_pair = dynamic_huffman_codes(in);
    inflate_compression(codes_pair, in, output);
}

void deflate_no_compression(const std::vector<std::uint8_t>& data, std::vector<std::uint8_t>& output)
{
    const std::size_t blocks_count = (data.size() / max_block_size) + 1;

    for (std::size_t block = 0; block < blocks_count; ++block) {
        BlockHeader b_header;
        b_header.bfinal = ((block + 1) >= blocks_count ? 1 : 0);
        b_header.btype  = BlockHeader::no_compression;

        output.push_back(static_cast<std::uint8_t>(b_header));

        const std::uint16_t len = static_cast<std::uint16_t>(
        std::min(max_block_size, static_cast<std::uint32_t>(data.size() - block * max_block_size)));

        output.push_back(static_cast<std::uint8_t>(len & 0xFF));
        output.push_back(static_cast<std::uint8_t>((len >> 8) & 0xFF));

        const std::uint16_t nlen = static_cast<std::uint16_t>(~len);
        output.push_back(static_cast<std::uint8_t>(nlen & 0xFF));
        output.push_back(static_cast<std::uint8_t>((nlen >> 8) & 0xFF));

        for (std::size_t i = 0; i < max_block_size && i < data.size(); ++i) {
            output.push_back(data[block * max_block_size + i]);
        }
    }
}

std::uint32_t adler32(const std::vector<std::uint8_t>& data)
{
    constexpr std::uint32_t base = 65521; // largest prime smaller than 65536

    std::uint32_t s1 = 1 & 0xffff;
    std::uint32_t s2 = (1 >> 16) & 0xffff;

    for (auto v : data) {
        s1 = (s1 + v) % base;
        s2 = (s2 + s1) % base;
    }

    const std::uint32_t adler = (s2 << 16) + s1;

    return ((adler & 0xFF) << 24) | (((adler >> 8) & 0xFF) << 16) | (((adler >> 16) & 0xFF) << 8) |
           ((adler >> 24) & 0xFF);
}

} // namespace

namespace neutrino::zlib
{
std::vector<std::uint8_t> inflate(const std::vector<std::uint8_t>& data)
{
    if (data.empty()) {
        return std::vector<std::uint8_t>();
    }

    BitStream in(data);

    const ZlibHeader zlib_header = ZlibHeader(in.get<std::uint16_t>(16));

    if (zlib_header.cm != deflate_compression_method || zlib_header.cinfo > 7) {
        return std::vector<std::uint8_t>();
    }

    const std::uint32_t window_size = static_cast<std::uint32_t>(std::pow(2, zlib_header.cinfo + 8));
    if (window_size > max_window_size) {
        return std::vector<std::uint8_t>();
    }

    // TODO Add DICT support;

    std::vector<std::uint8_t> output;

    while (in) {
        BlockHeader header = BlockHeader(in.get<std::uint8_t>(3));

        switch (header.btype) {
            case BlockHeader::reserved: return output; // error
            case BlockHeader::no_compression: inflate_no_compression(in, output); break;
            case BlockHeader::fixed_huffman: inflate_fixed_huffman(in, output); break;
            case BlockHeader::dynamic_huffman: inflate_dynamic_huffman(in, output); break;
        }

        if (header.bfinal) {
            break;
        }
    }

    in.skip_this_byte();

    if (!in) {
        return std::vector<std::uint8_t>();
    }

    const std::uint32_t adler          = adler32(output);
    const std::uint32_t original_adler = in.get<std::uint32_t>(32);

    return adler == original_adler ? output : std::vector<std::uint8_t>();
}

std::vector<std::uint8_t> deflate(const std::vector<std::uint8_t>& data)
{
    if (data.empty()) {
        return std::vector<std::uint8_t>();
    }

    std::vector<std::uint8_t> output;
    ZlibHeader zlib_header;
    zlib_header.cm     = deflate_compression_method;
    zlib_header.cinfo  = static_cast<std::uint8_t>(std::log2(max_window_size) - 8);
    zlib_header.fdict  = 0;
    zlib_header.flevel = static_cast<std::uint8_t>(CompressionAlgorithm::fastest);
    zlib_header.fcheck = 0;

    std::uint16_t header_value = zlib_header.as_value();
    if (header_value % 31 != 0) {
        header_value = static_cast<std::uint16_t>((header_value / 31 + 1) * 31);
    }

    output.push_back(static_cast<std::uint8_t>((header_value >> 8) & 0xFF));
    output.push_back(static_cast<std::uint8_t>(header_value & 0xFF));

    deflate_no_compression(data, output);

    std::uint32_t adler = adler32(data);

    output.push_back(static_cast<std::uint8_t>(adler & 0xFF));
    output.push_back(static_cast<std::uint8_t>((adler >> 8) & 0xFF));
    output.push_back(static_cast<std::uint8_t>((adler >> 16) & 0xFF));
    output.push_back(static_cast<std::uint8_t>((adler >> 24) & 0xFF));

    return output;
}

} // namespace neutrino::zlib
