
// =============================================================================
// MIT License
//
// Copyright (c) 2017-2018 Fedorov Alexey
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// =============================================================================

#include <common/crc.hpp>
#include <unit_test/suite.hpp>

class crc_test : public framework::unit_test::suite
{
public:
    crc_test() : suite("crc_test")
    {
        add_test([this]() { crc8(); }, "crc8");
        add_test([this]() { crc16(); }, "crc16");
        add_test([this]() { crc32(); }, "crc32");
    }

private:

    void crc8()
    {
        using framework::utils::crc8;
        
        std::vector<framework::uint8> data = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        
        // clang-format off
        TEST_ASSERT(0xF4 == crc8(0x07, 0x00, false, false, 0x00).calculate(data.begin(), data.end()), "CRC-8 Failed.");
        TEST_ASSERT(0xDA == crc8(0x9B, 0xFF, false, false, 0x00).calculate(data.begin(), data.end()), "CRC-8/CDMA2000 Failed.");
        TEST_ASSERT(0x15 == crc8(0x39, 0x00, true,  true,  0x00).calculate(data.begin(), data.end()), "CRC-8/DARC Failed.");
        TEST_ASSERT(0xBC == crc8(0xD5, 0x00, false, false, 0x00).calculate(data.begin(), data.end()), "CRC-8/DVB-S2 Failed.");
        TEST_ASSERT(0x97 == crc8(0x1D, 0xFF, true,  true,  0x00).calculate(data.begin(), data.end()), "CRC-8/EBU Failed.");
        TEST_ASSERT(0x7E == crc8(0x1D, 0xFD, false, false, 0x00).calculate(data.begin(), data.end()), "CRC-8/I-CODE Failed.");
        TEST_ASSERT(0xA1 == crc8(0x07, 0x00, false, false, 0x55).calculate(data.begin(), data.end()), "CRC-8/ITU Failed.");
        TEST_ASSERT(0xA1 == crc8(0x31, 0x00, true,  true,  0x00).calculate(data.begin(), data.end()), "CRC-8/MAXIM Failed.");
        TEST_ASSERT(0xD0 == crc8(0x07, 0xFF, true,  true,  0x00).calculate(data.begin(), data.end()), "CRC-8/ROHC Failed.");
        TEST_ASSERT(0x25 == crc8(0x9B, 0x00, true,  true,  0x00).calculate(data.begin(), data.end()), "CRC-8/WCDMA Failed.");
        // clang-format on
    }
    
    void crc16()
    {
        using framework::utils::crc16;
        
        std::vector<framework::uint8> data = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        
        // clang-format off
        TEST_ASSERT(0x29B1 == crc16(0x1021, 0xFFFF, false, false, 0x0000).calculate(data.begin(), data.end()), "CRC-16/CCITT-FALSE Failed.");
        TEST_ASSERT(0xBB3D == crc16(0x8005, 0x0000, true,  true,  0x0000).calculate(data.begin(), data.end()), "CRC-16/ARC Failed.");
        TEST_ASSERT(0xE5CC == crc16(0x1021, 0x1D0F, false, false, 0x0000).calculate(data.begin(), data.end()), "CRC-16/AUG-CCITT Failed.");
        TEST_ASSERT(0xFEE8 == crc16(0x8005, 0x0000, false, false, 0x0000).calculate(data.begin(), data.end()), "CRC-16/BUYPAS Failed.");
        TEST_ASSERT(0x4C06 == crc16(0xC867, 0xFFFF, false, false, 0x0000).calculate(data.begin(), data.end()), "CRC-16/CDMA2000 Failed.");
        TEST_ASSERT(0x9ECF == crc16(0x8005, 0x800D, false, false, 0x0000).calculate(data.begin(), data.end()), "CRC-16/DDS-110 Failed.");
        TEST_ASSERT(0x007E == crc16(0x0589, 0x0000, false, false, 0x0001).calculate(data.begin(), data.end()), "CRC-16/DECT-R Failed.");
        TEST_ASSERT(0x007F == crc16(0x0589, 0x0000, false, false, 0x0000).calculate(data.begin(), data.end()), "CRC-16/DECT-X Failed.");
        TEST_ASSERT(0xD64E == crc16(0x1021, 0xFFFF, false, false, 0xFFFF).calculate(data.begin(), data.end()), "CRC-16/GENIBUS Failed.");
        TEST_ASSERT(0x44C2 == crc16(0x8005, 0x0000, true,  true,  0xFFFF).calculate(data.begin(), data.end()), "CRC-16/MAXIM Failed.");
        TEST_ASSERT(0x6F91 == crc16(0x1021, 0xFFFF, true,  true,  0x0000).calculate(data.begin(), data.end()), "CRC-16/MCRF4XX Failed.");
        TEST_ASSERT(0x63D0 == crc16(0x1021, 0xB2AA, true,  true,  0x0000).calculate(data.begin(), data.end()), "CRC-16/RIELLO Failed.");
        TEST_ASSERT(0xD0DB == crc16(0x8BB7, 0x0000, false, false, 0x0000).calculate(data.begin(), data.end()), "CRC-16/T0-DIF Failed.");
        TEST_ASSERT(0x0FB3 == crc16(0xA097, 0x0000, false, false, 0x0000).calculate(data.begin(), data.end()), "CRC-16/TELEDISK Failed.");
        TEST_ASSERT(0x26B1 == crc16(0x1021, 0x89EC, true,  true,  0x0000).calculate(data.begin(), data.end()), "CRC-16/TMS37157 Failed.");
        TEST_ASSERT(0xB4C8 == crc16(0x8005, 0xFFFF, true,  true,  0xFFFF).calculate(data.begin(), data.end()), "CRC-16/USB Failed.");
        TEST_ASSERT(0xBF05 == crc16(0x1021, 0xC6C6, true,  true,  0x0000).calculate(data.begin(), data.end()), "CRC-A Failed.");
        TEST_ASSERT(0x2189 == crc16(0x1021, 0x0000, true,  true,  0x0000).calculate(data.begin(), data.end()), "CRC-16/KERMIT Failed.");
        TEST_ASSERT(0x4B37 == crc16(0x8005, 0xFFFF, true,  true,  0x0000).calculate(data.begin(), data.end()), "CRC-16/MODBUS Failed.");
        TEST_ASSERT(0x906E == crc16(0x1021, 0xFFFF, true,  true,  0xFFFF).calculate(data.begin(), data.end()), "CRC-16/X-25 Failed.");
        TEST_ASSERT(0x31C3 == crc16(0x1021, 0x0000, false, false, 0x0000).calculate(data.begin(), data.end()), "CRC-16/XMODEM Failed.");
        // clang-format on
    }
    
    void crc32()
    {
        using framework::utils::crc32;
        
        std::vector<framework::uint8> data = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        
        // clang-format off
        TEST_ASSERT(0xCBF43926 == crc32(0x04C11DB7, 0xFFFFFFFF, true,  true,  0xFFFFFFFF).calculate(data.begin(), data.end()), "CRC-32 failed.");
        TEST_ASSERT(0xFC891918 == crc32(0x04C11DB7, 0xFFFFFFFF, false, false, 0xFFFFFFFF).calculate(data.begin(), data.end()), "CRC-32/BZIP2 failed.");
        TEST_ASSERT(0xE3069283 == crc32(0x1EDC6F41, 0xFFFFFFFF, true,  true,  0xFFFFFFFF).calculate(data.begin(), data.end()), "CRC-32C failed.");
        TEST_ASSERT(0x87315576 == crc32(0xA833982B, 0xFFFFFFFF, true,  true,  0xFFFFFFFF).calculate(data.begin(), data.end()), "CRC-32D failed.");
        TEST_ASSERT(0x0376E6E7 == crc32(0x04C11DB7, 0xFFFFFFFF, false, false, 0x00000000).calculate(data.begin(), data.end()), "CRC-32/MPEG-2 failed.");
        TEST_ASSERT(0x765E7680 == crc32(0x04C11DB7, 0x00000000, false, false, 0xFFFFFFFF).calculate(data.begin(), data.end()), "CRC-32/POSIX failed.");
        TEST_ASSERT(0x3010BF7F == crc32(0x814141AB, 0x00000000, false, false, 0x00000000).calculate(data.begin(), data.end()), "CRC-32Q failed.");
        TEST_ASSERT(0x340BC6D9 == crc32(0x04C11DB7, 0xFFFFFFFF, true,  true,  0x00000000).calculate(data.begin(), data.end()), "CRC-32/JAMCRC failed.");
        TEST_ASSERT(0xBD0BE338 == crc32(0x000000AF, 0x00000000, false, false, 0x00000000).calculate(data.begin(), data.end()), "CRC-32/XFER failed.");
        // clang-format on
    }
};


int main()
{
    return run_tests(crc_test());
}
