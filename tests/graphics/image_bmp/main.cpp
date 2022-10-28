#include <sstream>

#include <graphics/image.hpp>
#include <unit_test/suite.hpp>

class BmpImageTest : public framework::unit_test::Suite
{
public:
    BmpImageTest()
        : Suite("BmpImageTest")
    {
        add_test([this]() { bmp_load_good(); }, "bmp_load_good");
        add_test([this]() { bmp_load_questionable(); }, "bmp_load_questionable");
        add_test([this]() { bmp_load_bad(); }, "bmp_load_bad");
    }

private:
    void bmp_load_good()
    {
        using framework::graphics::Image;

        const std::vector<std::string> files =
        {"bmp/good/pal1.bmp",          "bmp/good/pal1bg.bmp",       "bmp/good/pal1wb.bmp",
         "bmp/good/pal4.bmp",          "bmp/good/pal4gs.bmp",       "bmp/good/pal4rle.bmp",
         "bmp/good/pal8-0.bmp",        "bmp/good/pal8.bmp",         "bmp/good/pal8gs.bmp",
         "bmp/good/pal8nonsquare.bmp", "bmp/good/pal8os2.bmp",      "bmp/good/pal8rle.bmp",
         "bmp/good/pal8topdown.bmp",   "bmp/good/pal8v4.bmp",       "bmp/good/pal8v5.bmp",
         "bmp/good/pal8w124.bmp",      "bmp/good/pal8w125.bmp",     "bmp/good/pal8w126.bmp",
         "bmp/good/rgb16-565.bmp",     "bmp/good/rgb16-565pal.bmp", "bmp/good/rgb16.bmp",
         "bmp/good/rgb16bfdef.bmp",    "bmp/good/rgb24.bmp",        "bmp/good/rgb24pal.bmp",
         "bmp/good/rgb32.bmp",         "bmp/good/rgb32bf.bmp",      "bmp/good/rgb32bfdef.bmp"};

        for (const auto& file : files) {
            Image img;
            const auto result = img.load(file);

            std::stringstream error_msg;
            error_msg << "Loading of " << file << " failed";

            TEST_ASSERT(result == Image::LoadResult::Success, error_msg.str());
        }
    }

    void bmp_load_questionable()
    {
        using framework::graphics::Image;

        const std::vector<std::string> good_files =
        {"bmp/questionable/pal1p1.bmp",         "bmp/questionable/pal2.bmp",
         "bmp/questionable/pal2color.bmp",      "bmp/questionable/pal4rlecut.bmp",
         "bmp/questionable/pal4rletrns.bmp",    "bmp/questionable/pal8offs.bmp",
         "bmp/questionable/pal8os2-hs.bmp",     "bmp/questionable/pal8os2-sz.bmp",
         "bmp/questionable/pal8os2sp.bmp",      "bmp/questionable/pal8os2v2-16.bmp",
         "bmp/questionable/pal8os2v2-40sz.bmp", "bmp/questionable/pal8os2v2-sz.bmp",
         "bmp/questionable/pal8os2v2.bmp",      "bmp/questionable/pal8oversizepal.bmp",
         "bmp/questionable/pal8rlecut.bmp",     "bmp/questionable/pal8rletrns.bmp",
         "bmp/questionable/rgb16-231.bmp",      "bmp/questionable/rgb16-3103.bmp",
         "bmp/questionable/rgb16faketrns.bmp",  "bmp/questionable/rgb24largepal.bmp",
         "bmp/questionable/rgb32-111110.bmp",   "bmp/questionable/rgb32-7187.bmp",
         "bmp/questionable/rgb32-xbgr.bmp",     "bmp/questionable/rgb32fakealpha.bmp",
         "bmp/questionable/rgb32h52.bmp",       "bmp/questionable/rgba16-1924.bmp",
         "bmp/questionable/rgba16-4444.bmp",    "bmp/questionable/rgba16-5551.bmp",
         "bmp/questionable/rgba32-1010102.bmp", "bmp/questionable/rgba32-61754.bmp",
         "bmp/questionable/rgba32-81284.bmp",   "bmp/questionable/rgba32.bmp",
         "bmp/questionable/rgba32abf.bmp",      "bmp/questionable/rgba32h56.bmp"};

        for (const auto& file : good_files) {
            Image img;
            const auto result = img.load(file);

            std::stringstream error_msg;
            error_msg << "Loading of " << file << " failed";

            TEST_ASSERT(result == Image::LoadResult::Success, error_msg.str());
        }

        const std::vector<std::string> bad_files = {"bmp/questionable/pal1huff.bmp",
                                                    "bmp/questionable/rgb24jpeg.bmp",
                                                    "bmp/questionable/rgb24lprof.bmp",
                                                    "bmp/questionable/rgb24png.bmp",
                                                    "bmp/questionable/rgb24prof.bmp",
                                                    "bmp/questionable/rgb24prof2.bmp"};

        for (const auto& file : bad_files) {
            Image img;
            const auto result = img.load(file);

            std::stringstream error_msg;
            error_msg << "Loading of " << file << " failed. Should return the DataParsingError.";

            TEST_ASSERT(result == Image::LoadResult::DataParsingError, error_msg.str());
        }
    }

    void bmp_load_bad()
    {
        using framework::graphics::Image;

        const std::vector<std::string> good_files = {"bmp/bad/badrle.bmp",
                                                     "bmp/bad/rgb16-880.bmp",
                                                     "bmp/bad/shortfile.bmp"};

        for (const auto& file : good_files) {
            Image img;
            const auto result = img.load(file);

            std::stringstream error_msg;
            error_msg << "Loading of " << file << " failed";

            TEST_ASSERT(result == Image::LoadResult::Success, error_msg.str());
        }

        const std::vector<std::string> bad_files = {"bmp/bad/badbitcount.bmp",
                                                    "bmp/bad/badbitssize.bmp",
                                                    "bmp/bad/baddens1.bmp",
                                                    "bmp/bad/baddens2.bmp",
                                                    "bmp/bad/badrle4.bmp",
                                                    "bmp/bad/pal8badindex.bmp",
                                                    "bmp/bad/badrle4bis.bmp",
                                                    "bmp/bad/badrle4ter.bmp",
                                                    "bmp/bad/badrlebis.bmp",
                                                    "bmp/bad/badrleter.bmp",
                                                    "bmp/bad/badfilesize.bmp",
                                                    "bmp/bad/badheadersize.bmp",
                                                    "bmp/bad/badpalettesize.bmp",
                                                    "bmp/bad/badplanes.bmp",
                                                    "bmp/bad/badwidth.bmp",
                                                    "bmp/bad/reallybig.bmp",
                                                    "bmp/bad/rletopdown.bmp"};

        for (const auto& file : bad_files) {
            Image img;
            const auto result = img.load(file);

            std::stringstream error_msg;
            error_msg << "Loading of " << file << " should fail.";

            TEST_ASSERT(result != Image::LoadResult::Success, error_msg.str());
        }
    }
};

int main()
{
    return run_tests(BmpImageTest());
}
