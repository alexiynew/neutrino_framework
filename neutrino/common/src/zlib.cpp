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

using huffman_code_table = std::unordered_map<uint16, uint16>;

constexpr int deflate_compression_method = 8;

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
        fixed_huffman   = 1,
        dynamic_huffman = 2,
        reserved        = 3,
    };

    uint8 bfinal : 1;
    uint8 btype : 2;

    block_header(uint8 value)
    {
        memcpy(this, &value, sizeof(value));
    }
};

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

    const uint8 bl_count[10] = {0, 0, 0, 0, 0, 0, 0, 24, 144 + 8, 112};
    uint16 next_code[10]     = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    uint8 len[288]           = {};
    memset(len, 0, sizeof(len));

    for (int i = 0; i < 288; ++i) {
        len[i] = ((i <= 143 || i >= 280) ? 8 : (i >= 144 && i <= 255 ? 9 : 7));
    }

    uint16 code = 0;
    for (int bits = 1; bits <= 9; bits++) {
        code = static_cast<uint16>((code + bl_count[bits - 1]) << 1);

        next_code[bits] = code;
    }

    static huffman_code_table codes;
    for (int n = 0; n <= 288; n++) {
        int l = len[n];

        if (l != 0) {
            codes[next_code[l]] = n;
            next_code[l]++;
        }
    }

    return codes;
}

uint16 decode(const huffman_code_table& table, bit_stream& in)
{}

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
                // read table
                // codes = huffman_code_table();
            }
                [[fallthrough]];

            case block_header::fixed_huffman: {
                uint16 value = decode(codes, in);
                while (value != 256) {
                    if (value < 256) {
                        output.push_back(static_cast<uint8>(value));
                    } else if (value > 256) {
                        // decode distance from input stream

                        // move backwards distance bytes in the output
                        // stream, and copy length bytes from this
                        // position to the output stream.
                    }
                    value = decode(codes, in);
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