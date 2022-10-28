#include <common/crc.hpp>
#include <unit_test/suite.hpp>

class CrcTest : public framework::unit_test::Suite
{
public:
    CrcTest()
        : Suite("CrcTest")
    {
        add_test([this]() { crc8(); }, "crc8");
        add_test([this]() { crc16(); }, "crc16");
        add_test([this]() { crc32(); }, "crc32");
    }

private:
    void crc8()
    {
        using namespace framework::utils;

        std::vector<std::uint8_t> data = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

        TEST_ASSERT(0xF4 == Crc8::calculate(data.begin(), data.end()), "CRC-8 Failed.");
        TEST_ASSERT(0xDA == Crc8Cdma2000::calculate(data.begin(), data.end()), "CRC-8/CDMA2000 Failed.");
        TEST_ASSERT(0x15 == Crc8Darc::calculate(data.begin(), data.end()), "CRC-8/DARC Failed.");
        TEST_ASSERT(0xBC == Crc8DvbS2::calculate(data.begin(), data.end()), "CRC-8/DVB-S2 Failed.");
        TEST_ASSERT(0x97 == Crc8Ebu::calculate(data.begin(), data.end()), "CRC-8/EBU Failed.");
        TEST_ASSERT(0x7E == Crc8ICode::calculate(data.begin(), data.end()), "CRC-8/I-CODE Failed.");
        TEST_ASSERT(0xA1 == Crc8Itu::calculate(data.begin(), data.end()), "CRC-8/ITU Failed.");
        TEST_ASSERT(0xA1 == Crc8Maxim::calculate(data.begin(), data.end()), "CRC-8/MAXIM Failed.");
        TEST_ASSERT(0xD0 == Crc8Rohc::calculate(data.begin(), data.end()), "CRC-8/ROHC Failed.");
        TEST_ASSERT(0x25 == Crc8Wcdma::calculate(data.begin(), data.end()), "CRC-8/WCDMA Failed.");
    }

    void crc16()
    {
        using namespace framework::utils;

        std::vector<std::uint8_t> data = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

        // clang-format off
        TEST_ASSERT(0x29B1 == Crc16CcittFalse::calculate(data.begin(), data.end()), "CRC-16/CCITT-FALSE Failed.");
        TEST_ASSERT(0xBB3D == Crc16Arc::calculate(data.begin(), data.end()), "CRC-16/ARC Failed.");
        TEST_ASSERT(0xE5CC == Crc16AugCcitt::calculate(data.begin(), data.end()), "CRC-16/AUG-CCITT Failed.");
        TEST_ASSERT(0xFEE8 == Crc16Buypas::calculate(data.begin(), data.end()), "CRC-16/BUYPAS Failed.");
        TEST_ASSERT(0x4C06 == Crc16Cdma2000::calculate(data.begin(), data.end()), "CRC-16/CDMA2000 Failed.");
        TEST_ASSERT(0x9ECF == Crc16Dds110::calculate(data.begin(), data.end()), "CRC-16/DDS-110 Failed.");
        TEST_ASSERT(0x007E == Crc16DectR::calculate(data.begin(), data.end()), "CRC-16/DECT-R Failed.");
        TEST_ASSERT(0x007F == Crc16DectX::calculate(data.begin(), data.end()), "CRC-16/DECT-X Failed.");
        TEST_ASSERT(0xD64E == Crc16Genibus::calculate(data.begin(), data.end()), "CRC-16/GENIBUS Failed.");
        TEST_ASSERT(0x44C2 == Crc16Maxim::calculate(data.begin(), data.end()), "CRC-16/MAXIM Failed.");
        TEST_ASSERT(0x6F91 == Crc16Mcrf4xx::calculate(data.begin(), data.end()), "CRC-16/MCRF4XX Failed.");
        TEST_ASSERT(0x63D0 == Crc16Riello::calculate(data.begin(), data.end()), "CRC-16/RIELLO Failed.");
        TEST_ASSERT(0xD0DB == Crc16T0Dif::calculate(data.begin(), data.end()), "CRC-16/T0-DIF Failed.");
        TEST_ASSERT(0x0FB3 == Crc16Teledisk::calculate(data.begin(), data.end()), "CRC-16/TELEDISK Failed.");
        TEST_ASSERT(0x26B1 == Crc16Tms37157::calculate(data.begin(), data.end()), "CRC-16/TMS37157 Failed.");
        TEST_ASSERT(0xB4C8 == Crc16Usb::calculate(data.begin(), data.end()), "CRC-16/USB Failed.");
        TEST_ASSERT(0xBF05 == Crc16A::calculate(data.begin(), data.end()), "CRC-A Failed.");
        TEST_ASSERT(0x2189 == Crc16Kermit::calculate(data.begin(), data.end()), "CRC-16/KERMIT Failed.");
        TEST_ASSERT(0x4B37 == Crc16Modbus::calculate(data.begin(), data.end()), "CRC-16/MODBUS Failed.");
        TEST_ASSERT(0x906E == Crc16X25::calculate(data.begin(), data.end()), "CRC-16/X-25 Failed.");
        TEST_ASSERT(0x31C3 == Crc16Xmodem::calculate(data.begin(), data.end()), "CRC-16/XMODEM Failed.");
        // clang-format on
    }

    void crc32()
    {
        using namespace framework::utils;

        std::vector<std::uint8_t> data = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

        // clang-format off
        TEST_ASSERT(0xCBF43926 == Crc32::calculate(data.begin(), data.end()), "CRC-32 Failed.");
        TEST_ASSERT(0xFC891918 == Crc32Bzip2::calculate(data.begin(), data.end()), "CRC-32/BZIP2 Failed.");
        TEST_ASSERT(0xE3069283 == Crc32c::calculate(data.begin(), data.end()), "CRC-32C Failed.");
        TEST_ASSERT(0x87315576 == Crc32d::calculate(data.begin(), data.end()), "CRC-32D Failed.");
        TEST_ASSERT(0x0376E6E7 == Crc32Mpeg2::calculate(data.begin(), data.end()), "CRC-32/MPEG-2 Failed.");
        TEST_ASSERT(0x765E7680 == Crc32Posix::calculate(data.begin(), data.end()), "CRC-32/POSIX Failed.");
        TEST_ASSERT(0x3010BF7F == Crc32q::calculate(data.begin(), data.end()), "CRC-32Q Failed.");
        TEST_ASSERT(0x340BC6D9 == Crc32Jamcrc::calculate(data.begin(), data.end()), "CRC-32/JAMCRC Failed.");
        TEST_ASSERT(0xBD0BE338 == Crc32Xfer::calculate(data.begin(), data.end()), "CRC-32/XFER Failed.");
        // clang-format on
    }
};

int main()
{
    return run_tests(CrcTest());
}
