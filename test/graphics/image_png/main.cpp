#include <sstream>

#include <graphics/image.hpp>
#include <unit_test/suite.hpp>

class PngImageTest : public framework::unit_test::Suite
{
public:
    PngImageTest()
        : Suite("PngImageTest")
    {
        add_test([this]() { png_load(); }, "png_load");
    }

private:
    void png_load()
    {
        const std::vector<std::string> good_files =
        {"png/basi0g01.png", "png/basi0g02.png", "png/basi0g04.png", "png/basi0g08.png", "png/basi0g16.png",
         "png/basi2c08.png", "png/basi2c16.png", "png/basi3p01.png", "png/basi3p02.png", "png/basi3p04.png",
         "png/basi3p08.png", "png/basi4a08.png", "png/basi4a16.png", "png/basi6a08.png", "png/basi6a16.png",
         "png/basn0g01.png", "png/basn0g02.png", "png/basn0g04.png", "png/basn0g08.png", "png/basn0g16.png",
         "png/basn2c08.png", "png/basn2c16.png", "png/basn3p01.png", "png/basn3p02.png", "png/basn3p04.png",
         "png/basn3p08.png", "png/basn4a08.png", "png/basn4a16.png", "png/basn6a08.png", "png/basn6a16.png",
         "png/bgai4a08.png", "png/bgai4a16.png", "png/bgan6a08.png", "png/bgan6a16.png", "png/bgbn4a08.png",
         "png/bggn4a16.png", "png/bgwn6a08.png", "png/bgyn6a16.png", "png/ccwn2c08.png", "png/ccwn3p08.png",
         "png/cdfn2c08.png", "png/cdhn2c08.png", "png/cdsn2c08.png", "png/cdun2c08.png", "png/ch1n3p04.png",
         "png/ch2n3p08.png", "png/cm0n0g04.png", "png/cm7n0g04.png", "png/cm9n0g04.png", "png/cs3n2c16.png",
         "png/cs3n3p08.png", "png/cs5n2c08.png", "png/cs5n3p08.png", "png/cs8n2c08.png", "png/cs8n3p08.png",
         "png/ct0n0g04.png", "png/ct1n0g04.png", "png/cten0g04.png", "png/ctfn0g04.png", "png/ctgn0g04.png",
         "png/cthn0g04.png", "png/ctjn0g04.png", "png/ctzn0g04.png", "png/exif2c08.png", "png/f00n0g08.png",
         "png/f00n2c08.png", "png/f01n0g08.png", "png/f01n2c08.png", "png/f02n0g08.png", "png/f02n2c08.png",
         "png/f03n0g08.png", "png/f03n2c08.png", "png/f04n0g08.png", "png/f04n2c08.png", "png/f99n0g04.png",
         "png/g03n0g16.png", "png/g03n2c08.png", "png/g03n3p04.png", "png/g04n0g16.png", "png/g04n2c08.png",
         "png/g04n3p04.png", "png/g05n0g16.png", "png/g05n2c08.png", "png/g05n3p04.png", "png/g07n0g16.png",
         "png/g07n2c08.png", "png/g07n3p04.png", "png/g10n0g16.png", "png/g10n2c08.png", "png/g10n3p04.png",
         "png/g25n0g16.png", "png/g25n2c08.png", "png/g25n3p04.png", "png/oi1n0g16.png", "png/oi1n2c16.png",
         "png/oi2n0g16.png", "png/oi2n2c16.png", "png/oi4n0g16.png", "png/oi4n2c16.png", "png/oi9n0g16.png",
         "png/oi9n2c16.png", "png/pp0n2c16.png", "png/pp0n6a08.png", "png/ps1n0g08.png", "png/ps1n2c16.png",
         "png/ps2n0g08.png", "png/ps2n2c16.png", "png/s01i3p01.png", "png/s01n3p01.png", "png/s02i3p01.png",
         "png/s02n3p01.png", "png/s03i3p01.png", "png/s03n3p01.png", "png/s04i3p01.png", "png/s04n3p01.png",
         "png/s05i3p02.png", "png/s05n3p02.png", "png/s06i3p02.png", "png/s06n3p02.png", "png/s07i3p02.png",
         "png/s07n3p02.png", "png/s08i3p02.png", "png/s08n3p02.png", "png/s09i3p02.png", "png/s09n3p02.png",
         "png/s32i3p04.png", "png/s32n3p04.png", "png/s33i3p04.png", "png/s33n3p04.png", "png/s34i3p04.png",
         "png/s34n3p04.png", "png/s35i3p04.png", "png/s35n3p04.png", "png/s36i3p04.png", "png/s36n3p04.png",
         "png/s37i3p04.png", "png/s37n3p04.png", "png/s38i3p04.png", "png/s38n3p04.png", "png/s39i3p04.png",
         "png/s39n3p04.png", "png/s40i3p04.png", "png/s40n3p04.png", "png/tbbn0g04.png", "png/tbbn2c16.png",
         "png/tbbn3p08.png", "png/tbgn2c16.png", "png/tbgn3p08.png", "png/tbrn2c08.png", "png/tbwn0g16.png",
         "png/tbwn3p08.png", "png/tbyn3p08.png", "png/tm3n3p02.png", "png/tp0n0g08.png", "png/tp0n2c08.png",
         "png/tp0n3p08.png", "png/tp1n3p08.png", "png/z00n2c08.png", "png/z03n2c08.png", "png/z06n2c08.png",
         "png/z09n2c08.png"};

        for (const auto& file : good_files) {
            framework::graphics::Image img;
            const auto& [loaded, error] = img.load(file);

            std::stringstream out;
            out << "Loading of " << file << " failed, error: " << error;

            TEST_ASSERT(loaded && error.empty(), out.str());
        }

        const std::vector<std::string> bad_files = {"png/xc1n0g08.png",
                                                    "png/xc9n2c08.png",
                                                    "png/xcrn0g04.png",
                                                    "png/xcsn0g01.png",
                                                    "png/xd0n2c08.png",
                                                    "png/xd3n2c08.png",
                                                    "png/xd9n2c08.png",
                                                    "png/xdtn0g01.png",
                                                    "png/xhdn0g08.png",
                                                    "png/xlfn0g04.png",
                                                    "png/xs1n0g01.png",
                                                    "png/xs2n0g01.png",
                                                    "png/xs4n0g01.png",
                                                    "png/xs7n0g01.png"};

        for (const auto& file : bad_files) {
            framework::graphics::Image img;
            const auto& [loaded, error] = img.load(file);

            std::stringstream out;
            out << "Loading of " << file << " failed, error: " << error;

            TEST_ASSERT(!loaded && !error.empty(), out.str());
        }
    }
};

int main()
{
    return run_tests(PngImageTest());
}
