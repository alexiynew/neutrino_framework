
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

class bmp_image_test : public framework::unit_test::suite
{
public:
    bmp_image_test() : suite("bmp_image_test")
    {
        add_test([this]() { bmp_load_good(); }, "bmp_load_good");
        add_test([this]() { bmp_load_questionable(); }, "bmp_load_questionable");
        add_test([this]() { bmp_load_bad(); }, "bmp_load_bad");
    }

private:
    void bmp_load_good()
    {
        framework::graphics::image img;
        TEST_ASSERT(img.load("good_pal1.bmp"), "Loading of good_pal1.bmp failed.");

        TEST_ASSERT(img.width() == 127, "Loading of good_pal1.bmp failed.");
        TEST_ASSERT(img.height() == 64, "Loading of good_pal1.bmp failed.");
        TEST_ASSERT(img.is_bottom_up() == true, "Loading of good_pal1.bmp failed.");

        TEST_ASSERT(img.load("good_pal1bg.bmp"), "Loading of good_pal1bg.bmp failed.");
        TEST_ASSERT(img.load("good_pal1wb.bmp"), "Loading of good_pal1wb.bmp failed.");
        TEST_ASSERT(img.load("good_pal4.bmp"), "Loading of good_pal4.bmp failed.");
        TEST_ASSERT(img.load("good_pal4gs.bmp"), "Loading of good_pal4gs.bmp failed.");
        TEST_ASSERT(img.load("good_pal4rle.bmp"), "Loading of good_pal4rle.bmp failed.");
        TEST_ASSERT(img.load("good_pal8-0.bmp"), "Loading of good_pal8-0 failed.");
        TEST_ASSERT(img.load("good_pal8.bmp"), "Loading of good_pal8.bmp failed.");
        TEST_ASSERT(img.load("good_pal8gs.bmp"), "Loading of good_pal8gs.bmp failed.");
        TEST_ASSERT(img.load("good_pal8nonsquare.bmp"), "Loading of good_pal8nonsquare.bmp failed.");
        TEST_ASSERT(img.load("good_pal8os2.bmp"), "Loading of good_pal8os2.bmp failed.");
        TEST_ASSERT(img.load("good_pal8rle.bmp"), "Loading of good_pal8rle.bmp failed.");

        TEST_ASSERT(img.load("good_pal8topdown.bmp"), "Loading of good_pal8topdown.bmp failed.");
        TEST_ASSERT(img.is_bottom_up() == false, "Loading of good_pal8topdown.bmp failed.");
        img.flip_vertically();
        TEST_ASSERT(img.is_bottom_up() == true, "Image flip_vertically failed.");

        TEST_ASSERT(img.load("good_pal8v4.bmp"), "Loading of good_pal8v4.bmp failed.");
        TEST_ASSERT(img.load("good_pal8v5.bmp"), "Loading of good_pal8v5.bmp failed.");
        TEST_ASSERT(img.load("good_pal8w124.bmp"), "Loading of good_pal8w124.bmp failed.");
        TEST_ASSERT(img.load("good_pal8w125.bmp"), "Loading of good_pal8w125.bmp failed.");
        TEST_ASSERT(img.load("good_pal8w126.bmp"), "Loading of good_pal8w126.bmp failed.");
        TEST_ASSERT(img.load("good_rgb16-565.bmp"), "Loading of good_rgb16-565.bmp failed.");
        TEST_ASSERT(img.load("good_rgb16-565pal.bmp"), "Loading of good_rgb16-565pal.bmp failed.");
        TEST_ASSERT(img.load("good_rgb16.bmp"), "Loading of good_rgb16.bmp failed.");
        TEST_ASSERT(img.load("good_rgb16bfdef.bmp"), "Loading of good_rgb16bfdef.bmp failed.");
        TEST_ASSERT(img.load("good_rgb24.bmp"), "Loading of good_rgb24.bmp failed.");
        TEST_ASSERT(img.load("good_rgb24pal.bmp"), "Loading of good_rgb24pal.bmp failed.");
        TEST_ASSERT(img.load("good_rgb32.bmp"), "Loading of good_rgb32.bmp failed.");
        TEST_ASSERT(img.load("good_rgb32bf.bmp"), "Loading of good_rgb32bf.bmp failed.");
        TEST_ASSERT(img.load("good_rgb32bfdef.bmp"), "Loading of good_rgb32bfdef.bmp failed.");
    }

    void bmp_load_questionable()
    {
        framework::graphics::image img;
        TEST_ASSERT(img.load("questionable_pal1p1.bmp"), "Loading of questionable_pal1p1.bmp failed.");
        TEST_ASSERT(img.load("questionable_pal2.bmp"), "Loading of questionable_pal2.bmp failed.");
        TEST_ASSERT(img.load("questionable_pal2color.bmp"), "Loading of questionable_pal2color.bmp failed.");
        TEST_ASSERT(img.load("questionable_pal4rlecut.bmp"), "Loading of questionable_pal4rlecut.bmp failed.");
        TEST_ASSERT(img.load("questionable_pal4rletrns.bmp"), "Loading of questionable_pal4rletrns.bmp failed.");
        TEST_ASSERT(img.load("questionable_pal8offs.bmp"), "Loading of questionable_pal8offs.bmp failed.");
        TEST_ASSERT(img.load("questionable_pal8os2-hs.bmp"), "Loading of questionable_pal8os2-hs.bmp failed.");
        TEST_ASSERT(img.load("questionable_pal8os2-sz.bmp"), "Loading of questionable_pal8os2-sz.bmp failed.");
        TEST_ASSERT(img.load("questionable_pal8os2sp.bmp"), "Loading of questionable_pal8os2sp.bmp failed.");
        TEST_ASSERT(img.load("questionable_pal8os2v2-16.bmp"), "Loading of questionable_pal8os2v2-16.bmp failed.");
        TEST_ASSERT(img.load("questionable_pal8os2v2-40sz.bmp"), "Loading of questionable_pal8os2v2-40sz.bmp failed.");
        TEST_ASSERT(img.load("questionable_pal8os2v2-sz.bmp"), "Loading of questionable_pal8os2v2-sz.bmp failed.");
        TEST_ASSERT(img.load("questionable_pal8os2v2.bmp"), "Loading of questionable_pal8os2v2.bmp failed.");
        TEST_ASSERT(img.load("questionable_pal8oversizepal.bmp"),
                    "Loading of questionable_pal8oversizepal.bmp failed.");
        TEST_ASSERT(img.load("questionable_pal8rlecut.bmp"), "Loading of questionable_pal8rlecut.bmp failed.");
        TEST_ASSERT(img.load("questionable_pal8rletrns.bmp"), "Loading of questionable_pal8rletrns.bmp failed.");
        TEST_ASSERT(img.load("questionable_rgb16-231.bmp"), "Loading of questionable_rgb16-231.bmp failed.");
        TEST_ASSERT(img.load("questionable_rgb16-3103.bmp"), "Loading of questionable_rgb16-3103.bmp failed.");
        TEST_ASSERT(img.load("questionable_rgb16faketrns.bmp"), "Loading of questionable_rgb16faketrns.bmp failed.");
        TEST_ASSERT(img.load("questionable_rgb24largepal.bmp"), "Loading of questionable_rgb24largepal.bmp failed.");
        TEST_ASSERT(img.load("questionable_rgb32-111110.bmp"), "Loading of questionable_rgb32-111110.bmp failed.");
        TEST_ASSERT(img.load("questionable_rgb32-7187.bmp"), "Loading of questionable_rgb32-7187.bmp failed.");
        TEST_ASSERT(img.load("questionable_rgb32-xbgr.bmp"), "Loading of questionable_rgb32-xbgr.bmp failed.");
        TEST_ASSERT(img.load("questionable_rgb32fakealpha.bmp"), "Loading of questionable_rgb32fakealpha.bmp failed.");
        TEST_ASSERT(img.load("questionable_rgb32h52.bmp"), "Loading of questionable_rgb32h52.bmp failed.");
        TEST_ASSERT(img.load("questionable_rgba16-1924.bmp"), "Loading of questionable_rgba16-1924.bmp failed.");
        TEST_ASSERT(img.load("questionable_rgba16-4444.bmp"), "Loading of questionable_rgba16-4444.bmp failed.");
        TEST_ASSERT(img.load("questionable_rgba16-5551.bmp"), "Loading of questionable_rgba16-5551.bmp failed.");
        TEST_ASSERT(img.load("questionable_rgba32-1010102.bmp"), "Loading of questionable_rgba32-1010102.bmp failed.");
        TEST_ASSERT(img.load("questionable_rgba32-61754.bmp"), "Loading of questionable_rgba32-61754.bmp failed.");
        TEST_ASSERT(img.load("questionable_rgba32-81284.bmp"), "Loading of questionable_rgba32-81284.bmp failed.");
        TEST_ASSERT(img.load("questionable_rgba32.bmp"), "Loading of questionable_rgba32.bmp failed.");
        TEST_ASSERT(img.load("questionable_rgba32abf.bmp"), "Loading of questionable_rgba32abf.bmp failed.");
        TEST_ASSERT(img.load("questionable_rgba32h56.bmp"), "Loading of questionable_rgba32h56.bmp failed.");

        TEST_ASSERT(!img.load("questionable_pal1huff.bmp"), "Loading of questionable_pal1huff.bmp failed.");
        TEST_ASSERT(!img.load("questionable_rgb24jpeg.bmp"), "Loading of questionable_rgb24jpeg.bmp failed.");
        TEST_ASSERT(!img.load("questionable_rgb24lprof.bmp"), "Loading of questionable_rgb24lprof.bmp failed.");
        TEST_ASSERT(!img.load("questionable_rgb24png.bmp"), "Loading of questionable_rgb24png.bmp failed.");
        TEST_ASSERT(!img.load("questionable_rgb24prof.bmp"), "Loading of questionable_rgb24prof.bmp failed.");
        TEST_ASSERT(!img.load("questionable_rgb24prof2.bmp"), "Loading of questionable_rgb24prof2.bmp failed.");
    }

    void bmp_load_bad()
    {
        framework::graphics::image img;

        img.load("bad_badbitcount.bmp");
        img.load("bad_badbitssize.bmp");
        img.load("bad_baddens1.bmp");
        img.load("bad_baddens2.bmp");
        img.load("bad_badfilesize.bmp");
        img.load("bad_badheadersize.bmp");
        img.load("bad_badpalettesize.bmp");
        img.load("bad_badplanes.bmp");
        img.load("bad_badrle.bmp");
        img.load("bad_badrle4.bmp");
        img.load("bad_badrle4bis.bmp");
        img.load("bad_badrle4ter.bmp");
        img.load("bad_badrlebis.bmp ");
        img.load("bad_badrleter.bmp");
        img.load("bad_badwidth.bmp");
        img.load("bad_pal8badindex.bmp ");
        img.load("bad_reallybig.bmp ");
        img.load("bad_rgb16-880.bmp");
        img.load("bad_rletopdown.bmp ");
        img.load("bad_shortfile.bmp ");
    }
};

int main()
{
    return run_tests(bmp_image_test());
}
