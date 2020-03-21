
// =============================================================================
// MIT License
//
// Copyright (c) 2017-2019 Fedorov Alexey
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

#include <graphics/image.hpp>
#include <unit_test/suite.hpp>

class png_image_test : public framework::unit_test::Suite
{
public:
    png_image_test() : Suite("png_image_test")
    {
        add_test([this]() { png_load(); }, "png_load");
    }

private:
    void png_load()
    {
        framework::graphics::Image img;

        TEST_ASSERT(img.load("png/basi0g01.png"), "Failed to load basi0g01.png");
        TEST_ASSERT(img.load("png/basi0g02.png"), "Failed to load basi0g02.png");
        TEST_ASSERT(img.load("png/basi0g04.png"), "Failed to load basi0g04.png");
        TEST_ASSERT(img.load("png/basi0g08.png"), "Failed to load basi0g08.png");
        TEST_ASSERT(img.load("png/basi0g16.png"), "Failed to load basi0g16.png");
        TEST_ASSERT(img.load("png/basi2c08.png"), "Failed to load basi2c08.png");
        TEST_ASSERT(img.load("png/basi2c16.png"), "Failed to load basi2c16.png");
        TEST_ASSERT(img.load("png/basi3p01.png"), "Failed to load basi3p01.png");
        TEST_ASSERT(img.load("png/basi3p02.png"), "Failed to load basi3p02.png");
        TEST_ASSERT(img.load("png/basi3p04.png"), "Failed to load basi3p04.png");
        TEST_ASSERT(img.load("png/basi3p08.png"), "Failed to load basi3p08.png");
        TEST_ASSERT(img.load("png/basi4a08.png"), "Failed to load basi4a08.png");
        TEST_ASSERT(img.load("png/basi4a16.png"), "Failed to load basi4a16.png");
        TEST_ASSERT(img.load("png/basi6a08.png"), "Failed to load basi6a08.png");
        TEST_ASSERT(img.load("png/basi6a16.png"), "Failed to load basi6a16.png");
        TEST_ASSERT(img.load("png/basn0g01.png"), "Failed to load basn0g01.png");
        TEST_ASSERT(img.load("png/basn0g02.png"), "Failed to load basn0g02.png");
        TEST_ASSERT(img.load("png/basn0g04.png"), "Failed to load basn0g04.png");
        TEST_ASSERT(img.load("png/basn0g08.png"), "Failed to load basn0g08.png");
        TEST_ASSERT(img.load("png/basn0g16.png"), "Failed to load basn0g16.png");
        TEST_ASSERT(img.load("png/basn2c08.png"), "Failed to load basn2c08.png");
        TEST_ASSERT(img.load("png/basn2c16.png"), "Failed to load basn2c16.png");
        TEST_ASSERT(img.load("png/basn3p01.png"), "Failed to load basn3p01.png");
        TEST_ASSERT(img.load("png/basn3p02.png"), "Failed to load basn3p02.png");
        TEST_ASSERT(img.load("png/basn3p04.png"), "Failed to load basn3p04.png");
        TEST_ASSERT(img.load("png/basn3p08.png"), "Failed to load basn3p08.png");
        TEST_ASSERT(img.load("png/basn4a08.png"), "Failed to load basn4a08.png");
        TEST_ASSERT(img.load("png/basn4a16.png"), "Failed to load basn4a16.png");
        TEST_ASSERT(img.load("png/basn6a08.png"), "Failed to load basn6a08.png");
        TEST_ASSERT(img.load("png/basn6a16.png"), "Failed to load basn6a16.png");
        TEST_ASSERT(img.load("png/bgai4a08.png"), "Failed to load bgai4a08.png");
        TEST_ASSERT(img.load("png/bgai4a16.png"), "Failed to load bgai4a16.png");
        TEST_ASSERT(img.load("png/bgan6a08.png"), "Failed to load bgan6a08.png");
        TEST_ASSERT(img.load("png/bgan6a16.png"), "Failed to load bgan6a16.png");
        TEST_ASSERT(img.load("png/bgbn4a08.png"), "Failed to load bgbn4a08.png");
        TEST_ASSERT(img.load("png/bggn4a16.png"), "Failed to load bggn4a16.png");
        TEST_ASSERT(img.load("png/bgwn6a08.png"), "Failed to load bgwn6a08.png");
        TEST_ASSERT(img.load("png/bgyn6a16.png"), "Failed to load bgyn6a16.png");
        TEST_ASSERT(img.load("png/ccwn2c08.png"), "Failed to load ccwn2c08.png");
        TEST_ASSERT(img.load("png/ccwn3p08.png"), "Failed to load ccwn3p08.png");
        TEST_ASSERT(img.load("png/cdfn2c08.png"), "Failed to load cdfn2c08.png");
        TEST_ASSERT(img.load("png/cdhn2c08.png"), "Failed to load cdhn2c08.png");
        TEST_ASSERT(img.load("png/cdsn2c08.png"), "Failed to load cdsn2c08.png");
        TEST_ASSERT(img.load("png/cdun2c08.png"), "Failed to load cdun2c08.png");
        TEST_ASSERT(img.load("png/ch1n3p04.png"), "Failed to load ch1n3p04.png");
        TEST_ASSERT(img.load("png/ch2n3p08.png"), "Failed to load ch2n3p08.png");
        TEST_ASSERT(img.load("png/cm0n0g04.png"), "Failed to load cm0n0g04.png");
        TEST_ASSERT(img.load("png/cm7n0g04.png"), "Failed to load cm7n0g04.png");
        TEST_ASSERT(img.load("png/cm9n0g04.png"), "Failed to load cm9n0g04.png");
        TEST_ASSERT(img.load("png/cs3n2c16.png"), "Failed to load cs3n2c16.png");
        TEST_ASSERT(img.load("png/cs3n3p08.png"), "Failed to load cs3n3p08.png");
        TEST_ASSERT(img.load("png/cs5n2c08.png"), "Failed to load cs5n2c08.png");
        TEST_ASSERT(img.load("png/cs5n3p08.png"), "Failed to load cs5n3p08.png");
        TEST_ASSERT(img.load("png/cs8n2c08.png"), "Failed to load cs8n2c08.png");
        TEST_ASSERT(img.load("png/cs8n3p08.png"), "Failed to load cs8n3p08.png");
        TEST_ASSERT(img.load("png/ct0n0g04.png"), "Failed to load ct0n0g04.png");
        TEST_ASSERT(img.load("png/ct1n0g04.png"), "Failed to load ct1n0g04.png");
        TEST_ASSERT(img.load("png/cten0g04.png"), "Failed to load cten0g04.png");
        TEST_ASSERT(img.load("png/ctfn0g04.png"), "Failed to load ctfn0g04.png");
        TEST_ASSERT(img.load("png/ctgn0g04.png"), "Failed to load ctgn0g04.png");
        TEST_ASSERT(img.load("png/cthn0g04.png"), "Failed to load cthn0g04.png");
        TEST_ASSERT(img.load("png/ctjn0g04.png"), "Failed to load ctjn0g04.png");
        TEST_ASSERT(img.load("png/ctzn0g04.png"), "Failed to load ctzn0g04.png");
        TEST_ASSERT(img.load("png/exif2c08.png"), "Failed to load exif2c08.png");
        TEST_ASSERT(img.load("png/f00n0g08.png"), "Failed to load f00n0g08.png");
        TEST_ASSERT(img.load("png/f00n2c08.png"), "Failed to load f00n2c08.png");
        TEST_ASSERT(img.load("png/f01n0g08.png"), "Failed to load f01n0g08.png");
        TEST_ASSERT(img.load("png/f01n2c08.png"), "Failed to load f01n2c08.png");
        TEST_ASSERT(img.load("png/f02n0g08.png"), "Failed to load f02n0g08.png");
        TEST_ASSERT(img.load("png/f02n2c08.png"), "Failed to load f02n2c08.png");
        TEST_ASSERT(img.load("png/f03n0g08.png"), "Failed to load f03n0g08.png");
        TEST_ASSERT(img.load("png/f03n2c08.png"), "Failed to load f03n2c08.png");
        TEST_ASSERT(img.load("png/f04n0g08.png"), "Failed to load f04n0g08.png");
        TEST_ASSERT(img.load("png/f04n2c08.png"), "Failed to load f04n2c08.png");
        TEST_ASSERT(img.load("png/f99n0g04.png"), "Failed to load f99n0g04.png");
        TEST_ASSERT(img.load("png/g03n0g16.png"), "Failed to load g03n0g16.png");
        TEST_ASSERT(img.load("png/g03n2c08.png"), "Failed to load g03n2c08.png");
        TEST_ASSERT(img.load("png/g03n3p04.png"), "Failed to load g03n3p04.png");
        TEST_ASSERT(img.load("png/g04n0g16.png"), "Failed to load g04n0g16.png");
        TEST_ASSERT(img.load("png/g04n2c08.png"), "Failed to load g04n2c08.png");
        TEST_ASSERT(img.load("png/g04n3p04.png"), "Failed to load g04n3p04.png");
        TEST_ASSERT(img.load("png/g05n0g16.png"), "Failed to load g05n0g16.png");
        TEST_ASSERT(img.load("png/g05n2c08.png"), "Failed to load g05n2c08.png");
        TEST_ASSERT(img.load("png/g05n3p04.png"), "Failed to load g05n3p04.png");
        TEST_ASSERT(img.load("png/g07n0g16.png"), "Failed to load g07n0g16.png");
        TEST_ASSERT(img.load("png/g07n2c08.png"), "Failed to load g07n2c08.png");
        TEST_ASSERT(img.load("png/g07n3p04.png"), "Failed to load g07n3p04.png");
        TEST_ASSERT(img.load("png/g10n0g16.png"), "Failed to load g10n0g16.png");
        TEST_ASSERT(img.load("png/g10n2c08.png"), "Failed to load g10n2c08.png");
        TEST_ASSERT(img.load("png/g10n3p04.png"), "Failed to load g10n3p04.png");
        TEST_ASSERT(img.load("png/g25n0g16.png"), "Failed to load g25n0g16.png");
        TEST_ASSERT(img.load("png/g25n2c08.png"), "Failed to load g25n2c08.png");
        TEST_ASSERT(img.load("png/g25n3p04.png"), "Failed to load g25n3p04.png");
        TEST_ASSERT(img.load("png/oi1n0g16.png"), "Failed to load oi1n0g16.png");
        TEST_ASSERT(img.load("png/oi1n2c16.png"), "Failed to load oi1n2c16.png");
        TEST_ASSERT(img.load("png/oi2n0g16.png"), "Failed to load oi2n0g16.png");
        TEST_ASSERT(img.load("png/oi2n2c16.png"), "Failed to load oi2n2c16.png");
        TEST_ASSERT(img.load("png/oi4n0g16.png"), "Failed to load oi4n0g16.png");
        TEST_ASSERT(img.load("png/oi4n2c16.png"), "Failed to load oi4n2c16.png");
        TEST_ASSERT(img.load("png/oi9n0g16.png"), "Failed to load oi9n0g16.png");
        TEST_ASSERT(img.load("png/oi9n2c16.png"), "Failed to load oi9n2c16.png");
        TEST_ASSERT(img.load("png/pp0n2c16.png"), "Failed to load pp0n2c16.png");
        TEST_ASSERT(img.load("png/pp0n6a08.png"), "Failed to load pp0n6a08.png");
        TEST_ASSERT(img.load("png/ps1n0g08.png"), "Failed to load ps1n0g08.png");
        TEST_ASSERT(img.load("png/ps1n2c16.png"), "Failed to load ps1n2c16.png");
        TEST_ASSERT(img.load("png/ps2n0g08.png"), "Failed to load ps2n0g08.png");
        TEST_ASSERT(img.load("png/ps2n2c16.png"), "Failed to load ps2n2c16.png");
        TEST_ASSERT(img.load("png/s01i3p01.png"), "Failed to load s01i3p01.png");
        TEST_ASSERT(img.load("png/s01n3p01.png"), "Failed to load s01n3p01.png");
        TEST_ASSERT(img.load("png/s02i3p01.png"), "Failed to load s02i3p01.png");
        TEST_ASSERT(img.load("png/s02n3p01.png"), "Failed to load s02n3p01.png");
        TEST_ASSERT(img.load("png/s03i3p01.png"), "Failed to load s03i3p01.png");
        TEST_ASSERT(img.load("png/s03n3p01.png"), "Failed to load s03n3p01.png");
        TEST_ASSERT(img.load("png/s04i3p01.png"), "Failed to load s04i3p01.png");
        TEST_ASSERT(img.load("png/s04n3p01.png"), "Failed to load s04n3p01.png");
        TEST_ASSERT(img.load("png/s05i3p02.png"), "Failed to load s05i3p02.png");
        TEST_ASSERT(img.load("png/s05n3p02.png"), "Failed to load s05n3p02.png");
        TEST_ASSERT(img.load("png/s06i3p02.png"), "Failed to load s06i3p02.png");
        TEST_ASSERT(img.load("png/s06n3p02.png"), "Failed to load s06n3p02.png");
        TEST_ASSERT(img.load("png/s07i3p02.png"), "Failed to load s07i3p02.png");
        TEST_ASSERT(img.load("png/s07n3p02.png"), "Failed to load s07n3p02.png");
        TEST_ASSERT(img.load("png/s08i3p02.png"), "Failed to load s08i3p02.png");
        TEST_ASSERT(img.load("png/s08n3p02.png"), "Failed to load s08n3p02.png");
        TEST_ASSERT(img.load("png/s09i3p02.png"), "Failed to load s09i3p02.png");
        TEST_ASSERT(img.load("png/s09n3p02.png"), "Failed to load s09n3p02.png");
        TEST_ASSERT(img.load("png/s32i3p04.png"), "Failed to load s32i3p04.png");
        TEST_ASSERT(img.load("png/s32n3p04.png"), "Failed to load s32n3p04.png");
        TEST_ASSERT(img.load("png/s33i3p04.png"), "Failed to load s33i3p04.png");
        TEST_ASSERT(img.load("png/s33n3p04.png"), "Failed to load s33n3p04.png");
        TEST_ASSERT(img.load("png/s34i3p04.png"), "Failed to load s34i3p04.png");
        TEST_ASSERT(img.load("png/s34n3p04.png"), "Failed to load s34n3p04.png");
        TEST_ASSERT(img.load("png/s35i3p04.png"), "Failed to load s35i3p04.png");
        TEST_ASSERT(img.load("png/s35n3p04.png"), "Failed to load s35n3p04.png");
        TEST_ASSERT(img.load("png/s36i3p04.png"), "Failed to load s36i3p04.png");
        TEST_ASSERT(img.load("png/s36n3p04.png"), "Failed to load s36n3p04.png");
        TEST_ASSERT(img.load("png/s37i3p04.png"), "Failed to load s37i3p04.png");
        TEST_ASSERT(img.load("png/s37n3p04.png"), "Failed to load s37n3p04.png");
        TEST_ASSERT(img.load("png/s38i3p04.png"), "Failed to load s38i3p04.png");
        TEST_ASSERT(img.load("png/s38n3p04.png"), "Failed to load s38n3p04.png");
        TEST_ASSERT(img.load("png/s39i3p04.png"), "Failed to load s39i3p04.png");
        TEST_ASSERT(img.load("png/s39n3p04.png"), "Failed to load s39n3p04.png");
        TEST_ASSERT(img.load("png/s40i3p04.png"), "Failed to load s40i3p04.png");
        TEST_ASSERT(img.load("png/s40n3p04.png"), "Failed to load s40n3p04.png");
        TEST_ASSERT(img.load("png/tbbn0g04.png"), "Failed to load tbbn0g04.png");
        TEST_ASSERT(img.load("png/tbbn2c16.png"), "Failed to load tbbn2c16.png");
        TEST_ASSERT(img.load("png/tbbn3p08.png"), "Failed to load tbbn3p08.png");
        TEST_ASSERT(img.load("png/tbgn2c16.png"), "Failed to load tbgn2c16.png");
        TEST_ASSERT(img.load("png/tbgn3p08.png"), "Failed to load tbgn3p08.png");
        TEST_ASSERT(img.load("png/tbrn2c08.png"), "Failed to load tbrn2c08.png");
        TEST_ASSERT(img.load("png/tbwn0g16.png"), "Failed to load tbwn0g16.png");
        TEST_ASSERT(img.load("png/tbwn3p08.png"), "Failed to load tbwn3p08.png");
        TEST_ASSERT(img.load("png/tbyn3p08.png"), "Failed to load tbyn3p08.png");
        TEST_ASSERT(img.load("png/tm3n3p02.png"), "Failed to load tm3n3p02.png");
        TEST_ASSERT(img.load("png/tp0n0g08.png"), "Failed to load tp0n0g08.png");
        TEST_ASSERT(img.load("png/tp0n2c08.png"), "Failed to load tp0n2c08.png");
        TEST_ASSERT(img.load("png/tp0n3p08.png"), "Failed to load tp0n3p08.png");
        TEST_ASSERT(img.load("png/tp1n3p08.png"), "Failed to load tp1n3p08.png");

        TEST_ASSERT(!img.load("png/xc1n0g08.png"), "Should not load xc1n0g08.png");
        TEST_ASSERT(!img.load("png/xc9n2c08.png"), "Should not load xc9n2c08.png");
        TEST_ASSERT(!img.load("png/xcrn0g04.png"), "Should not load xcrn0g04.png");
        TEST_ASSERT(!img.load("png/xcsn0g01.png"), "Should not load xcsn0g01.png");
        TEST_ASSERT(!img.load("png/xd0n2c08.png"), "Should not load xd0n2c08.png");
        TEST_ASSERT(!img.load("png/xd3n2c08.png"), "Should not load xd3n2c08.png");
        TEST_ASSERT(!img.load("png/xd9n2c08.png"), "Should not load xd9n2c08.png");
        TEST_ASSERT(!img.load("png/xdtn0g01.png"), "Should not load xdtn0g01.png");
        TEST_ASSERT(!img.load("png/xhdn0g08.png"), "Should not load xhdn0g08.png");
        TEST_ASSERT(!img.load("png/xlfn0g04.png"), "Should not load xlfn0g04.png");
        TEST_ASSERT(!img.load("png/xs1n0g01.png"), "Should not load xs1n0g01.png");
        TEST_ASSERT(!img.load("png/xs2n0g01.png"), "Should not load xs2n0g01.png");
        TEST_ASSERT(!img.load("png/xs4n0g01.png"), "Should not load xs4n0g01.png");
        TEST_ASSERT(!img.load("png/xs7n0g01.png"), "Should not load xs7n0g01.png");

        TEST_ASSERT(img.load("png/z00n2c08.png"), "Failed to load z00n2c08.png");
        TEST_ASSERT(img.load("png/z03n2c08.png"), "Failed to load z03n2c08.png");
        TEST_ASSERT(img.load("png/z06n2c08.png"), "Failed to load z06n2c08.png");
        TEST_ASSERT(img.load("png/z09n2c08.png"), "Failed to load z09n2c08.png");
    }
};

int main()
{
    return run_tests(png_image_test());
}
