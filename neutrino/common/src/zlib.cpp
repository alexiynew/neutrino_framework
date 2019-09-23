#include <cmath>
#include <cstring>
#include <unordered_map>

#include <common/zlib.hpp>

namespace
{
using framework::int32;
using framework::uint16;
using framework::uint32;
using framework::uint8;
using framework::usize;

constexpr int deflate_compression_method = 8;
constexpr int huffman_alphabet_size      = 288;
constexpr int huffman_end_of_block       = 256;
constexpr int huffman_invalid_code       = 300;

using alphabet_description = std::array<uint8, huffman_alphabet_size>;

class bit_stream
{
public:
    bit_stream(const std::vector<uint8>& data) : m_data(data)
    {}

    template <typename T>
    T get(int32 count)
    {
        return static_cast<T>(get_implementation(static_cast<int32>(count % (sizeof(T) * 8 + 1))));
    }

private:
    uint32 m_buffer = 0;
    int32 m_bits    = 0;
    usize m_byte    = 0;
    const std::vector<uint8>& m_data;

    uint32 get_implementation(int32 count)
    {
        constexpr uint32 mask[33] = {
        0x00000000,                                                                                     //
        0x00000001, 0x00000003, 0x00000007, 0x0000000F, 0x0000001F, 0x0000003F, 0x0000007F, 0x000000FF, // 1 - 8
        0x000001FF, 0x000003FF, 0x000007FF, 0x00000FFF, 0x00001FFF, 0x00003FFF, 0x00007FFF, 0x0000FFFF, // 9 - 16
        0x0001FFFF, 0x0003FFFF, 0x0007FFFF, 0x000FFFFF, 0x001FFFFF, 0x003FFFFF, 0x007FFFFF, 0x00FFFFFF, // 17 - 24
        0x01FFFFFF, 0x03FFFFFF, 0x07FFFFFF, 0x0FFFFFFF, 0x1FFFFFFF, 0x3FFFFFFF, 0x7FFFFFFF, 0xFFFFFFFF, // 25 - 32
        };

        count %= 33;

        while (m_bits < count && m_byte < m_data.size()) {
            m_buffer = static_cast<uint32>(m_buffer | (m_data[m_byte] << m_bits));
            m_bits += 8;
            m_byte++;
        }

        if (m_byte >= m_data.size() && m_bits == 0) {
            return 0;
        }

        count = std::min(m_bits, count);

        uint32 res = static_cast<uint32>(m_buffer & mask[count]);

        m_buffer = static_cast<uint32>(m_buffer >> count);
        m_bits -= count;

        return res;
    }
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
    huffman_code_table(const alphabet_description& lengts)
    {
        std::vector<uint8> bl_count(8);

        for (auto len : lengts) {
            while (bl_count.size() <= len) {
                bl_count.push_back(0);
            }

            if (len > 0 && len < m_min_length) {
                m_min_length = len;
            }

            bl_count[len]++;
        }

        std::vector<uint16> next_code(bl_count.size() + 1);

        uint16 code = 0;
        for (usize bits = 1; bits <= bl_count.size(); bits++) {
            code = static_cast<uint16>((code + bl_count[bits - 1]) << 1);

            next_code[bits] = code;
        }

        m_codes.clear();
        m_codes.resize(code + huffman_alphabet_size, huffman_invalid_code);
        for (usize n = 0; n < lengts.size(); n++) {
            int len = lengts[n];

            if (len != 0) {
                m_codes[next_code[len]] = static_cast<uint16>(n);
                next_code[len]++;
            }
        }
    }

    uint16 decode(bit_stream& in)
    {
        uint16 value = in.get<uint16>(m_min_length);

        value = reflect(value, m_min_length);
        while (m_codes[value] == huffman_invalid_code) {
            value = static_cast<uint16>((value << 1) | in.get<uint16>(1));
        }

        return m_codes[value];
    }

private:
    std::vector<uint16> m_codes;
    uint8 m_min_length = sizeof(uint16) * 8;
};

struct zlib_header_t
{
    uint8 cm : 4;
    uint8 cinfo : 4;
    uint8 fcheck : 5;
    uint8 fdict : 1;
    uint8 flevel : 3;

    zlib_header_t(uint16 value)
    {
        memcpy(this, &value, sizeof(value));
    }
};

struct block_header
{
    enum type_t
    {
        no_compression  = 0,
        dynamic_huffman = 1,
        fixed_huffman   = 2,
        reserved        = 3,
    };

    uint8 bfinal : 1;
    uint8 btype : 2;

    block_header(uint8 value)
    {
        memcpy(this, &value, sizeof(value));
    }
};

huffman_code_table& fixed_huffman_codes()
{
    /*
     Lit Value    Bits   Count   Codes
     ---------    ----   -----   -----
       0 - 143     8     144     00110000  through 10111111
     144 - 255     9     112     110010000 through 111111111
     256 - 279     7     24      0000000   through 0010111
     280 - 287     8     8       11000000  through 11000111
    */

    alphabet_description alphabet;

    for (usize i = 0; i < alphabet.size(); ++i) {
        alphabet[i] = ((i <= 143 || i >= 280) ? 8 : (i >= 144 && i <= 255 ? 9 : 7));
    }

    static huffman_code_table fixed(alphabet);

    return fixed;
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

    const zlib_header_t zlib_header = in.get<uint16>(16);

    if (zlib_header.cm != deflate_compression_method || zlib_header.cinfo > 7) {
        return std::vector<uint8>();
    }

    const uint32 window_size = static_cast<uint32>(std::pow(2, zlib_header.cinfo + 8));

    // TODO Add DICT support;

    // 0 - compressor used fastest algorithm
    // 1 - compressor used fast algorithm
    // 2 - compressor used default algorithm
    // 3 - compressor used maximum compression, slowest algorithm

    if (!window_size) {
    }

    std::vector<uint8> output;

    while (true) {
        block_header header       = in.get<uint8>(3);
        huffman_code_table& codes = fixed_huffman_codes();

        switch (header.btype) {
            case block_header::no_compression: {
                // skip any remaining bits in current partially processed byte
                // read LEN and NLEN (see next section)
                // copy LEN bytes of data to output
            } break;

            case block_header::dynamic_huffman: {
                /*
                HLIT -- 5 бит; [число, такое, что] количество-литералов-и-длин = HLIT + 257. Фактически HLIT это
                количество длин, так как первые 257 элементов, которые всегда присутствуют это символы и признак конца
                блока.

                HDIST -- 5 бит; количество-смещений = HDIST + 1

                HCLEN -- 4 бита; количество-команд-длин = HCLEN + 4
                */
                uint16 hlit  = reflect(in.get<uint16>(5), 5);
                uint16 hdist = reflect(in.get<uint16>(5), 5);
                uint16 hclen = reflect(in.get<uint16>(4), 4);

                if (hlit && hdist && hclen) {
                }

                // read table
                // codes = huffman_code_table();
            }
                [[fallthrough]];

            case block_header::fixed_huffman: {
                while (true) {
                    const uint16 value = codes.decode(in);
                    if (value < huffman_end_of_block) {
                        output.push_back(static_cast<uint8>(value));
                    } else if (value > huffman_end_of_block) {
                        // decode distance from input stream

                        // move backwards distance bytes in the output
                        // stream, and copy length bytes from this
                        // position to the output stream.
                    } else {
                        break;
                    }
                }
            } break;

            case block_header::reserved:
            default:
                // error
                return std::vector<uint8>();
        }

        if (header.bfinal) {
            break;
        }
    }

    return output;
}

std::vector<uint8> deflate(const std::vector<uint8>& data, compression /*compr*/)
{
    if (data.empty()) {
        return std::vector<uint8>();
    }

    return std::vector<uint8>();
}
} // namespace framework::utils::zlib