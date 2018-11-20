
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
        using namespace framework::utils;

        std::vector<framework::uint8> data = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

        TEST_ASSERT(0xF4 == crc8::calculate(data.begin(), data.end()), "CRC-8 Failed.");
        TEST_ASSERT(0xDA == crc8_cdma2000::calculate(data.begin(), data.end()), "CRC-8/CDMA2000 Failed.");
        TEST_ASSERT(0x15 == crc8_darc::calculate(data.begin(), data.end()), "CRC-8/DARC Failed.");
        TEST_ASSERT(0xBC == crc8_dvb_s2::calculate(data.begin(), data.end()), "CRC-8/DVB-S2 Failed.");
        TEST_ASSERT(0x97 == crc8_ebu::calculate(data.begin(), data.end()), "CRC-8/EBU Failed.");
        TEST_ASSERT(0x7E == crc8_i_code::calculate(data.begin(), data.end()), "CRC-8/I-CODE Failed.");
        TEST_ASSERT(0xA1 == crc8_itu::calculate(data.begin(), data.end()), "CRC-8/ITU Failed.");
        TEST_ASSERT(0xA1 == crc8_maxim::calculate(data.begin(), data.end()), "CRC-8/MAXIM Failed.");
        TEST_ASSERT(0xD0 == crc8_rohc::calculate(data.begin(), data.end()), "CRC-8/ROHC Failed.");
        TEST_ASSERT(0x25 == crc8_wcdma::calculate(data.begin(), data.end()), "CRC-8/WCDMA Failed.");
    }

    void crc16()
    {
        using namespace framework::utils;

        std::vector<framework::uint8> data = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

        // clang-format off
        TEST_ASSERT(0x29B1 == crc16_ccitt_false::calculate(data.begin(), data.end()), "CRC-16/CCITT-FALSE Failed.");
        TEST_ASSERT(0xBB3D == crc16_arc::calculate(data.begin(), data.end()), "CRC-16/ARC Failed.");
        TEST_ASSERT(0xE5CC == crc16_aug_ccitt::calculate(data.begin(), data.end()), "CRC-16/AUG-CCITT Failed.");
        TEST_ASSERT(0xFEE8 == crc16_buypas::calculate(data.begin(), data.end()), "CRC-16/BUYPAS Failed.");
        TEST_ASSERT(0x4C06 == crc16_cdma2000::calculate(data.begin(), data.end()), "CRC-16/CDMA2000 Failed.");
        TEST_ASSERT(0x9ECF == crc16_dds_110::calculate(data.begin(), data.end()), "CRC-16/DDS-110 Failed.");
        TEST_ASSERT(0x007E == crc16_dect_r::calculate(data.begin(), data.end()), "CRC-16/DECT-R Failed.");
        TEST_ASSERT(0x007F == crc16_dect_x::calculate(data.begin(), data.end()), "CRC-16/DECT-X Failed.");
        TEST_ASSERT(0xD64E == crc16_genibus::calculate(data.begin(), data.end()), "CRC-16/GENIBUS Failed.");
        TEST_ASSERT(0x44C2 == crc16_maxim::calculate(data.begin(), data.end()), "CRC-16/MAXIM Failed.");
        TEST_ASSERT(0x6F91 == crc16_mcrf4xx::calculate(data.begin(), data.end()), "CRC-16/MCRF4XX Failed.");
        TEST_ASSERT(0x63D0 == crc16_riello::calculate(data.begin(), data.end()), "CRC-16/RIELLO Failed.");
        TEST_ASSERT(0xD0DB == crc16_t0_dif::calculate(data.begin(), data.end()), "CRC-16/T0-DIF Failed.");
        TEST_ASSERT(0x0FB3 == crc16_teledisk::calculate(data.begin(), data.end()), "CRC-16/TELEDISK Failed.");
        TEST_ASSERT(0x26B1 == crc16_tms37157::calculate(data.begin(), data.end()), "CRC-16/TMS37157 Failed.");
        TEST_ASSERT(0xB4C8 == crc16_usb::calculate(data.begin(), data.end()), "CRC-16/USB Failed.");
        TEST_ASSERT(0xBF05 == crc16_a::calculate(data.begin(), data.end()), "CRC-A Failed.");
        TEST_ASSERT(0x2189 == crc16_kermit::calculate(data.begin(), data.end()), "CRC-16/KERMIT Failed.");
        TEST_ASSERT(0x4B37 == crc16_modbus::calculate(data.begin(), data.end()), "CRC-16/MODBUS Failed.");
        TEST_ASSERT(0x906E == crc16_x_25::calculate(data.begin(), data.end()), "CRC-16/X-25 Failed.");
        TEST_ASSERT(0x31C3 == crc16_xmodem::calculate(data.begin(), data.end()), "CRC-16/XMODEM Failed.");
        // clang-format on
    }

    void crc32()
    {
        using namespace framework::utils;

        std::vector<framework::uint8> data = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

        // clang-format off
        TEST_ASSERT(0xCBF43926 == crc32::calculate(data.begin(), data.end()), "CRC-32 Failed.");
        TEST_ASSERT(0xFC891918 == crc32_bzip2::calculate(data.begin(), data.end()), "CRC-32/BZIP2 Failed.");
        TEST_ASSERT(0xE3069283 == crc32c::calculate(data.begin(), data.end()), "CRC-32C Failed.");
        TEST_ASSERT(0x87315576 == crc32d::calculate(data.begin(), data.end()), "CRC-32D Failed.");
        TEST_ASSERT(0x0376E6E7 == crc32_mpeg_2::calculate(data.begin(), data.end()), "CRC-32/MPEG-2 Failed.");
        TEST_ASSERT(0x765E7680 == crc32_posix::calculate(data.begin(), data.end()), "CRC-32/POSIX Failed.");
        TEST_ASSERT(0x3010BF7F == crc32q::calculate(data.begin(), data.end()), "CRC-32Q Failed.");
        TEST_ASSERT(0x340BC6D9 == crc32_jamcrc::calculate(data.begin(), data.end()), "CRC-32/JAMCRC Failed.");
        TEST_ASSERT(0xBD0BE338 == crc32_xfer::calculate(data.begin(), data.end()), "CRC-32/XFER Failed.");
        // clang-format on
    }
};

int main()
{
    return run_tests(crc_test());
}
