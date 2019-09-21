#include <cmath>
#include <cstring>

#include <common/zlib.hpp>

namespace
{
using framework::int32;
using framework::uint16;
using framework::uint32;
using framework::uint8;
using framework::usize;

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

    while (true) {
        block_header header = in.get<uint8>(3);

        switch (header.btype) {
            case 0x00: {
                // no compression
            } break;

            case 2: {
                // dynamik huffman
                // read table
            }
                [[fallthrough]];

            case 1: {
                // fixed huffman
            } break;

            case 3: [[fallthrough]];
            default:
                // error
                return std::vector<uint8>();
        }

        if (header.bfinal) {
            break;
        }
    }

    /*do
        read block header from input stream.
        if stored with no compression
            skip any remaining bits in current partially
                processed byte
            read LEN and NLEN (see next section)
            copy LEN bytes of data to output
        otherwise
            if compressed with dynamic Huffman codes
                read representation of code trees (see
                    subsection below)
            loop (until end of block code recognized)
                decode literal/length value from input stream
                if value < 256
                    copy value (literal byte) to output stream
                otherwise
                    if value = end of block (256)
                        break from loop
                    otherwise (value = 257..285)
                        decode distance from input stream

                        move backwards distance bytes in the output
                        stream, and copy length bytes from this
                        position to the output stream.
            end loop
    while not last block
    */
    return std::vector<uint8>();
} // namespace framework::utils::zlib

std::vector<uint8> deflate(const std::vector<uint8>& data, compression /*compr*/)
{
    if (data.empty()) {
        return std::vector<uint8>();
    }

    return std::vector<uint8>();
}
} // namespace framework::utils::zlib