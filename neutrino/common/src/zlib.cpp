#include <array>
#include <cmath>
#include <cstring>
#include <iterator>
#include <tuple>
#include <vector>

#include <common/zlib.hpp>

namespace
{
using framework::uint16;
using framework::uint32;
using framework::uint8;
using framework::usize;

constexpr uint32 max_code_size   = 16;
constexpr uint32 max_window_size = 32768;
constexpr uint32 max_block_size  = 65535;

constexpr uint32 deflate_compression_method = 8;

constexpr uint32 litlen_alphabet_size   = 288;
constexpr uint32 distance_alphabet_size = 32;

constexpr uint32 end_of_block_code = 256;
constexpr uint32 invalid_code      = 300;

enum class compression_algorithm
{
    fastest           = 0, // - compressor used fastest algorithm
    fast              = 1, // - compressor used fast algorithm
    default_algorithm = 2, // - compressor used default algorithm
    maximum           = 3, // - compressor used maximum compression, slowest algorithm
};

class bit_stream
{
public:
    explicit bit_stream(const std::vector<uint8>& data) : m_data(data)
    {}

    template <typename T>
    T get(uint32 count)
    {
        return static_cast<T>(get_implementation(static_cast<uint32>(count % (sizeof(T) * 8 + 1))));
    }

    void skip_this_byte()
    {
        m_buffer = static_cast<uint32>(m_buffer >> m_bits);
        m_bits   = 0;
    }

    operator bool() const
    {
        return m_byte < m_data.size() || m_bits > 0;
    }

private:
    uint32 get_implementation(uint32 count)
    {
        constexpr uint32 mask[33] = {
        0x00000000,                                                                                     //
        0x00000001, 0x00000003, 0x00000007, 0x0000000F, 0x0000001F, 0x0000003F, 0x0000007F, 0x000000FF, // 1 - 8
        0x000001FF, 0x000003FF, 0x000007FF, 0x00000FFF, 0x00001FFF, 0x00003FFF, 0x00007FFF, 0x0000FFFF, // 9 - 16
        0x0001FFFF, 0x0003FFFF, 0x0007FFFF, 0x000FFFFF, 0x001FFFFF, 0x003FFFFF, 0x007FFFFF, 0x00FFFFFF, // 17 - 24
        0x01FFFFFF, 0x03FFFFFF, 0x07FFFFFF, 0x0FFFFFFF, 0x1FFFFFFF, 0x3FFFFFFF, 0x7FFFFFFF, 0xFFFFFFFF, // 25 - 32
        };

        while (m_bits < count && m_byte < m_data.size()) {
            m_buffer = static_cast<uint32>(m_buffer | (m_data[m_byte] << m_bits));
            m_bits += 8;
            m_byte++;
        }

        if (!(this->operator bool())) {
            return 0;
        }

        count = std::min(m_bits, count);

        const uint32 res = static_cast<uint32>(m_buffer & mask[count]);

        m_buffer = static_cast<uint32>(m_buffer >> count);
        m_bits -= count;

        return res;
    }

    uint32 m_buffer = 0;
    uint32 m_bits   = 0;
    usize m_byte    = 0;
    const std::vector<uint8>& m_data;
};

uint16 reflect(uint16 value, uint8 size)
{
    uint16 ref = 0;

    for (usize bit = 0; bit < size; ++bit) {
        if (value & 1) {
            ref = static_cast<uint16>(ref | 1 << (size - 1 - bit));
        }
        value = static_cast<uint16>(value >> 1);
    }

    return ref;
}

class huffman_code_table
{
public:
    huffman_code_table(const std::vector<uint8>& codes_lengths)
    {
        build_codes(codes_lengths);
    }

    uint16 decode(bit_stream& in) const
    {
        uint8 value_len = m_min_codes_length;
        uint16 value    = reflect(in.get<uint16>(value_len), value_len);

        auto get_literal = [this](uint16 val, uint8 len) -> uint16 {
            if (len >= max_code_size) {
                return invalid_code;
            }

            const usize index = val - m_start_code[len];
            if (index >= m_codes[len].size()) {
                return invalid_code;
            }

            return m_codes[len][index];
        };

        uint16 lit = get_literal(value, value_len);
        while (lit == invalid_code && value_len < max_code_size) {
            value = static_cast<uint16>((value << 1) | in.get<uint16>(1));
            value_len++;
            lit = get_literal(value, value_len);
        }

        return lit;
    }

private:
    void build_codes(const std::vector<uint8>& lengths)
    {
        std::vector<uint8> bl_count(max_code_size);

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

        uint16 code = 0;
        for (usize bits = 1; bits <= bl_count.size(); bits++) {
            code = static_cast<uint16>((code + bl_count[bits - 1]) << 1);

            m_start_code[bits] = code;
        }

        m_codes.clear();
        m_codes.resize(max_code_size);

        for (usize i = 0; i < bl_count.size(); ++i) {
            m_codes[i].resize(bl_count[i], invalid_code);
        }

        auto next_code = m_start_code;
        for (usize n = 0; n < lengths.size(); n++) {
            int len = lengths[n];

            if (len != 0) {
                const usize index   = next_code[len] - m_start_code[len];
                m_codes[len][index] = static_cast<uint16>(n);
                next_code[len]++;
            }
        }
    }

    std::vector<std::vector<uint16>> m_codes;
    std::vector<uint16> m_start_code;
    uint8 m_min_codes_length = sizeof(uint16) * 8;
}; // namespace

using litlen_distance_codes_t = std::tuple<huffman_code_table, huffman_code_table>;

struct zlib_header_t
{
    uint8 cm : 4;
    uint8 cinfo : 4;
    uint8 fcheck : 5;
    uint8 fdict : 1;
    uint8 flevel : 3;

    zlib_header_t() = default;

    explicit zlib_header_t(uint16 value)
    {
        memcpy(this, &value, sizeof(value));
    }

    uint16 as_value() const
    {
        uint16 tmp;
        memcpy(&tmp, this, sizeof(uint16));

        const uint16 res = static_cast<uint16>(((tmp & 0xFF) << 8) | ((tmp >> 8) & 0xFF));
        return res;
    }
};

struct block_header_t
{
    enum type_t
    {
        no_compression  = 0,
        dynamic_huffman = 2,
        fixed_huffman   = 1,
        reserved        = 3,
    };

    uint8 bfinal : 1;
    uint8 btype : 2;

    block_header_t() : bfinal(0), btype(no_compression)
    {}

    explicit block_header_t(uint8 value)
    {
        memcpy(this, &value, sizeof(value));
    }

    operator uint8() const
    {
        uint8 res;
        memcpy(&res, this, sizeof(uint8));
        return res;
    }
};

litlen_distance_codes_t fixed_huffman_codes()
{
    /*
     Lit Value    Bits   Count   Codes
     ---------    ----   -----   -----
       0 - 143     8     144     00110000  through 10111111
     144 - 255     9     112     110010000 through 111111111
     256 - 279     7     24      0000000   through 0010111
     280 - 287     8     8       11000000  through 11000111
    */

    std::vector<uint8> litlen_alphabet(litlen_alphabet_size);

    for (usize i = 0; i < litlen_alphabet.size(); ++i) {
        litlen_alphabet[i] = ((i <= 143 || i >= 280) ? 8 : (i >= 144 && i <= 255 ? 9 : 7));
    }

    std::vector<uint8> distance_alphabet(distance_alphabet_size, 5);

    return std::make_tuple(litlen_alphabet, distance_alphabet);
}

litlen_distance_codes_t dynamic_huffman_codes(bit_stream& in)
{
    const uint16 hlit  = in.get<uint16>(5);
    const uint16 hdist = in.get<uint16>(5);
    const uint16 hclen = in.get<uint16>(4);

    const usize lit_len_codes_count  = hlit + 257;
    const usize distance_codes_count = hdist + 1;
    const usize code_len_codes_count = hclen + 4;

    constexpr std::array<uint8, 19> length_order = {
    16, 17, 18, 0, 8, 7, 9, 6, 10, 5, 11, 4, 12, 3, 13, 2, 14, 1, 15,
    };

    std::vector<uint8> code_lengths(19);

    for (usize i = 0; i < code_len_codes_count; ++i) {
        code_lengths[length_order[i]] = static_cast<uint8>(in.get<uint16>(3));
    }

    huffman_code_table len_huffman(code_lengths);

    std::vector<uint8> lengths;
    lengths.reserve(lit_len_codes_count + distance_codes_count);
    for (usize i = 0; i < lit_len_codes_count + distance_codes_count;) {
        const uint8 len = static_cast<uint8>(len_huffman.decode(in));
        if (len <= 15) {
            lengths.push_back(len);
            i++;
        } else if (len == 16 && lengths.size() > 0) {
            const uint8 count = static_cast<uint8>(in.get<uint8>(2) + 3);
            lengths.insert(lengths.end(), count, lengths.back());
            i += count;
        } else if (len == 17) {
            const uint8 count = static_cast<uint8>(in.get<uint8>(3) + 3);
            lengths.insert(lengths.end(), count, 0);
            i += count;
        } else if (len == 18) {
            const uint8 count = static_cast<uint8>(in.get<uint8>(7) + 11);
            lengths.insert(lengths.end(), count, 0);
            i += count;
        }
    }

    const std::vector<uint8> litlen(begin(lengths), next(begin(lengths), lit_len_codes_count));
    const std::vector<uint8> dist(next(begin(lengths), lit_len_codes_count), end(lengths));

    return std::make_tuple(litlen, dist);
}

uint16 read_length(uint16 value, bit_stream& in)
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

    constexpr uint16 start_len = 257;
    constexpr std::array<std::pair<uint8, uint16>, 29> len_description =
    {std::pair(0, 3),   std::pair(0, 4),   std::pair(0, 5),   std::pair(0, 6),   std::pair(0, 7),  std::pair(0, 8),
     std::pair(0, 9),   std::pair(0, 10),  std::pair(1, 11),  std::pair(1, 13),  std::pair(1, 15), std::pair(1, 17),
     std::pair(2, 19),  std::pair(2, 23),  std::pair(2, 27),  std::pair(2, 31),  std::pair(3, 35), std::pair(3, 43),
     std::pair(3, 51),  std::pair(3, 59),  std::pair(4, 67),  std::pair(4, 83),  std::pair(4, 99), std::pair(4, 115),
     std::pair(5, 131), std::pair(5, 163), std::pair(5, 195), std::pair(5, 227), std::pair(0, 258)};

    auto [extra_bits, start_value] = len_description[value - start_len];

    uint16 result = start_value;
    if (extra_bits > 0) {
        result = static_cast<uint16>(result + in.get<uint16>(extra_bits));
    }

    return result;
}

uint16 read_distance(uint16 value, bit_stream& in)
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

    constexpr std::array<std::pair<uint8, uint16>, 30> dist_description =
    {std::pair(0, 1),     std::pair(0, 2),     std::pair(0, 3),      std::pair(0, 4),      std::pair(1, 5),
     std::pair(1, 7),     std::pair(2, 9),     std::pair(2, 13),     std::pair(3, 17),     std::pair(3, 25),
     std::pair(4, 33),    std::pair(4, 49),    std::pair(5, 65),     std::pair(5, 97),     std::pair(6, 129),
     std::pair(6, 193),   std::pair(7, 257),   std::pair(7, 385),    std::pair(8, 513),    std::pair(8, 769),
     std::pair(9, 1025),  std::pair(9, 1537),  std::pair(10, 2049),  std::pair(10, 3073),  std::pair(11, 4097),
     std::pair(11, 6145), std::pair(12, 8193), std::pair(12, 12289), std::pair(13, 16385), std::pair(13, 24577)};

    auto [extra_bits, start_value] = dist_description[value];

    uint16 result = start_value;
    if (extra_bits > 0) {
        result = static_cast<uint16>(result + in.get<uint16>(extra_bits));
    }

    return result;
}

void inflate_no_compression(bit_stream& in, std::vector<uint8>& output)
{
    in.skip_this_byte();
    uint16 len = in.get<uint16>(16);

    [[maybe_unused]] uint16 nlen = in.get<uint16>(16);

    for (usize i = 0; i < len; ++i) {
        output.push_back(in.get<uint8>(8));
    }
}

void inflate_compression(const litlen_distance_codes_t& codes_pair, bit_stream& in, std::vector<uint8>& output)
{
    const auto [codes, distances] = codes_pair;

    while (in) {
        const uint16 value = codes.decode(in);
        if (value < end_of_block_code) {
            output.push_back(static_cast<uint8>(value));
        } else if (value > end_of_block_code && value < litlen_alphabet_size) {
            const uint16 length    = read_length(value, in);
            const uint16 dist_code = distances.decode(in);
            const uint16 distance  = read_distance(dist_code, in);

            if (distance >= output.size()) {
                break; // error
            }

            for (usize i = 0, pos = output.size() - distance; i < length; ++i, ++pos) {
                output.push_back(output[pos]);
            }
        } else {
            break; // error
        }
    }
}

inline void inflate_fixed_huffman(bit_stream& in, std::vector<uint8>& output)
{
    const auto codes_pair = fixed_huffman_codes();
    inflate_compression(codes_pair, in, output);
}

inline void inflate_dynamic_huffman(bit_stream& in, std::vector<uint8>& output)
{
    const auto codes_pair = dynamic_huffman_codes(in);
    inflate_compression(codes_pair, in, output);
}

void deflate_no_compression(const std::vector<uint8>& data, std::vector<uint8>& output)
{
    const usize blocks_count = (data.size() / max_block_size) + 1;

    for (usize block = 0; block < blocks_count; ++block) {
        block_header_t b_header;
        b_header.bfinal = ((block + 1) >= blocks_count ? 1 : 0);
        b_header.btype  = block_header_t::no_compression;

        output.push_back(static_cast<uint8>(b_header));

        const uint16 len = static_cast<uint16>(
        std::min(max_block_size, static_cast<uint32>(data.size() - block * max_block_size)));

        output.push_back(static_cast<uint8>(len & 0xFF));
        output.push_back(static_cast<uint8>((len >> 8) & 0xFF));

        const uint16 nlen = static_cast<uint16>(~len);
        output.push_back(static_cast<uint8>(nlen & 0xFF));
        output.push_back(static_cast<uint8>((nlen >> 8) & 0xFF));

        for (usize i = 0; i < max_block_size && i < data.size(); ++i) {
            output.push_back(data[block * max_block_size + i]);
        }
    }
}

uint32 adler32(const std::vector<uint8>& data)
{
    constexpr uint32 base = 65521; // largest prime smaller than 65536

    uint32 s1 = 1 & 0xffff;
    uint32 s2 = (1 >> 16) & 0xffff;

    for (auto v : data) {
        s1 = (s1 + v) % base;
        s2 = (s2 + s1) % base;
    }

    const uint32 adler = (s2 << 16) + s1;

    return ((adler & 0xFF) << 24) | (((adler >> 8) & 0xFF) << 16) | (((adler >> 16) & 0xFF) << 8) |
           ((adler >> 24) & 0xFF);
}

} // namespace

namespace framework::utils::zlib
{
std::vector<uint8> inflate(const std::vector<uint8>& data)
{
    if (data.empty()) {
        return std::vector<uint8>();
    }

    bit_stream in(data);

    const zlib_header_t zlib_header = zlib_header_t(in.get<uint16>(16));

    if (zlib_header.cm != deflate_compression_method || zlib_header.cinfo > 7) {
        return std::vector<uint8>();
    }

    const uint32 window_size = static_cast<uint32>(std::pow(2, zlib_header.cinfo + 8));
    if (window_size > max_window_size) {
        return std::vector<uint8>();
    }

    // TODO Add DICT support;

    std::vector<uint8> output;

    while (in) {
        block_header_t header = block_header_t(in.get<uint8>(3));

        switch (header.btype) {
            case block_header_t::reserved: return output; // error
            case block_header_t::no_compression: inflate_no_compression(in, output); break;
            case block_header_t::fixed_huffman: inflate_fixed_huffman(in, output); break;
            case block_header_t::dynamic_huffman: inflate_dynamic_huffman(in, output); break;
        }

        if (header.bfinal) {
            break;
        }
    }

    in.skip_this_byte();

    if (!in) {
        return std::vector<uint8>();
    }

    const uint32 adler          = adler32(output);
    const uint32 original_adler = in.get<uint32>(32);

    return adler == original_adler ? output : std::vector<uint8>();
}

std::vector<uint8> deflate(const std::vector<uint8>& data)
{
    if (data.empty()) {
        return std::vector<uint8>();
    }

    std::vector<uint8> output;
    zlib_header_t zlib_header;
    zlib_header.cm     = deflate_compression_method;
    zlib_header.cinfo  = static_cast<uint8>(std::log2(max_window_size) - 8);
    zlib_header.fdict  = 0;
    zlib_header.flevel = static_cast<uint8>(compression_algorithm::fastest);
    zlib_header.fcheck = 0;

    uint16 header_value = zlib_header.as_value();
    if (header_value % 31 != 0) {
        header_value = static_cast<uint16>((header_value / 31 + 1) * 31);
    }

    output.push_back(static_cast<uint8>((header_value >> 8) & 0xFF));
    output.push_back(static_cast<uint8>(header_value & 0xFF));

    deflate_no_compression(data, output);

    uint32 adler = adler32(data);

    output.push_back(static_cast<uint8>(adler & 0xFF));
    output.push_back(static_cast<uint8>((adler >> 8) & 0xFF));
    output.push_back(static_cast<uint8>((adler >> 16) & 0xFF));
    output.push_back(static_cast<uint8>((adler >> 24) & 0xFF));

    return output;
}

} // namespace framework::utils::zlib