
# =============================================================================
# MIT License
#
# Copyright (c) 2017-2019 Fedorov Alexey
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
# =============================================================================

set_sources(PRIVATE_SOURCES
    main.cpp
)

add_executable(${TEST_NAME} EXCLUDE_FROM_ALL "")

target_sources(${TEST_NAME} PRIVATE ${PRIVATE_SOURCES})

target_link_libraries(${TEST_NAME} ${PROJECT_NAME}_static)
target_include_directories(${TEST_NAME} PRIVATE $<TARGET_PROPERTY:${PROJECT_NAME},INCLUDE_DIRECTORIES>)

set_target_properties(${TEST_NAME} PROPERTIES FOLDER ${TEST_DIR_NAME}/${GROUP_NAME})

add_test(NAME "${GROUP_NAME}/${TEST_NAME}" COMMAND ${TEST_NAME})
set_tests_properties("${GROUP_NAME}/${TEST_NAME}" PROPERTIES LABELS ${GROUP_NAME})

add_dependencies(${TESTS_TARGET} ${TEST_NAME})

configure_file(${TEST_DIR}/good/pal1.bmp          "good_pal1.bmp"          COPYONLY)
configure_file(${TEST_DIR}/good/pal1bg.bmp        "good_pal1bg.bmp"        COPYONLY)
configure_file(${TEST_DIR}/good/pal1wb.bmp        "good_pal1wb.bmp"        COPYONLY)
configure_file(${TEST_DIR}/good/pal4.bmp          "good_pal4.bmp"          COPYONLY)
configure_file(${TEST_DIR}/good/pal4gs.bmp        "good_pal4gs.bmp"        COPYONLY)
configure_file(${TEST_DIR}/good/pal4rle.bmp       "good_pal4rle.bmp"       COPYONLY)
configure_file(${TEST_DIR}/good/pal8-0.bmp        "good_pal8-0.bmp"        COPYONLY)
configure_file(${TEST_DIR}/good/pal8.bmp          "good_pal8.bmp"          COPYONLY)
configure_file(${TEST_DIR}/good/pal8gs.bmp        "good_pal8gs.bmp"        COPYONLY)
configure_file(${TEST_DIR}/good/pal8nonsquare.bmp "good_pal8nonsquare.bmp" COPYONLY)
configure_file(${TEST_DIR}/good/pal8os2.bmp       "good_pal8os2.bmp"       COPYONLY)
configure_file(${TEST_DIR}/good/pal8rle.bmp       "good_pal8rle.bmp"       COPYONLY)
configure_file(${TEST_DIR}/good/pal8topdown.bmp   "good_pal8topdown.bmp"   COPYONLY)
configure_file(${TEST_DIR}/good/pal8v4.bmp        "good_pal8v4.bmp"        COPYONLY)
configure_file(${TEST_DIR}/good/pal8v5.bmp        "good_pal8v5.bmp"        COPYONLY)
configure_file(${TEST_DIR}/good/pal8w124.bmp      "good_pal8w124.bmp"      COPYONLY)
configure_file(${TEST_DIR}/good/pal8w125.bmp      "good_pal8w125.bmp"      COPYONLY)
configure_file(${TEST_DIR}/good/pal8w126.bmp      "good_pal8w126.bmp"      COPYONLY)
configure_file(${TEST_DIR}/good/rgb16-565.bmp     "good_rgb16-565.bmp"     COPYONLY)
configure_file(${TEST_DIR}/good/rgb16-565pal.bmp  "good_rgb16-565pal.bmp"  COPYONLY)
configure_file(${TEST_DIR}/good/rgb16.bmp         "good_rgb16.bmp"         COPYONLY)
configure_file(${TEST_DIR}/good/rgb16bfdef.bmp    "good_rgb16bfdef.bmp"    COPYONLY)
configure_file(${TEST_DIR}/good/rgb24.bmp         "good_rgb24.bmp"         COPYONLY)
configure_file(${TEST_DIR}/good/rgb24pal.bmp      "good_rgb24pal.bmp"      COPYONLY)
configure_file(${TEST_DIR}/good/rgb32.bmp         "good_rgb32.bmp"         COPYONLY)
configure_file(${TEST_DIR}/good/rgb32bf.bmp       "good_rgb32bf.bmp"       COPYONLY)
configure_file(${TEST_DIR}/good/rgb32bfdef.bmp    "good_rgb32bfdef.bmp"    COPYONLY)

configure_file(${TEST_DIR}/bad/badbitcount.bmp    "bad_badbitcount.bmp"    COPYONLY)
configure_file(${TEST_DIR}/bad/badbitssize.bmp    "bad_badbitssize.bmp"    COPYONLY)
configure_file(${TEST_DIR}/bad/baddens1.bmp       "bad_baddens1.bmp"       COPYONLY)
configure_file(${TEST_DIR}/bad/baddens2.bmp       "bad_baddens2.bmp"       COPYONLY)
configure_file(${TEST_DIR}/bad/badfilesize.bmp    "bad_badfilesize.bmp"    COPYONLY)
configure_file(${TEST_DIR}/bad/badheadersize.bmp  "bad_badheadersize.bmp"  COPYONLY)
configure_file(${TEST_DIR}/bad/badpalettesize.bmp "bad_badpalettesize.bmp" COPYONLY)
configure_file(${TEST_DIR}/bad/badplanes.bmp      "bad_badplanes.bmp"      COPYONLY)
configure_file(${TEST_DIR}/bad/badrle.bmp         "bad_badrle.bmp"         COPYONLY)
configure_file(${TEST_DIR}/bad/badrle4.bmp        "bad_badrle4.bmp"        COPYONLY)
configure_file(${TEST_DIR}/bad/badrle4bis.bmp     "bad_badrle4bis.bmp"     COPYONLY)
configure_file(${TEST_DIR}/bad/badrle4ter.bmp     "bad_badrle4ter.bmp"     COPYONLY)
configure_file(${TEST_DIR}/bad/badrlebis.bmp      "bad_badrlebis.bmp"      COPYONLY)
configure_file(${TEST_DIR}/bad/badrleter.bmp      "bad_badrleter.bmp"      COPYONLY)
configure_file(${TEST_DIR}/bad/badwidth.bmp       "bad_badwidth.bmp"       COPYONLY)
configure_file(${TEST_DIR}/bad/pal8badindex.bmp   "bad_pal8badindex.bmp"   COPYONLY)
configure_file(${TEST_DIR}/bad/reallybig.bmp      "bad_reallybig.bmp"      COPYONLY)
configure_file(${TEST_DIR}/bad/rgb16-880.bmp      "bad_rgb16-880.bmp"      COPYONLY)
configure_file(${TEST_DIR}/bad/rletopdown.bmp     "bad_rletopdown.bmp"     COPYONLY)
configure_file(${TEST_DIR}/bad/shortfile.bmp      "bad_shortfile.bmp"      COPYONLY)

configure_file(${TEST_DIR}/questionable/pal1huff.bmp        "questionable_pal1huff.bmp"        COPYONLY)
configure_file(${TEST_DIR}/questionable/pal1p1.bmp          "questionable_pal1p1.bmp"          COPYONLY)
configure_file(${TEST_DIR}/questionable/pal2.bmp            "questionable_pal2.bmp"            COPYONLY)
configure_file(${TEST_DIR}/questionable/pal2color.bmp       "questionable_pal2color.bmp"       COPYONLY)
configure_file(${TEST_DIR}/questionable/pal4rlecut.bmp      "questionable_pal4rlecut.bmp"      COPYONLY)
configure_file(${TEST_DIR}/questionable/pal4rletrns.bmp     "questionable_pal4rletrns.bmp"     COPYONLY)
configure_file(${TEST_DIR}/questionable/pal8offs.bmp        "questionable_pal8offs.bmp"        COPYONLY)
configure_file(${TEST_DIR}/questionable/pal8os2-hs.bmp      "questionable_pal8os2-hs.bmp"      COPYONLY)
configure_file(${TEST_DIR}/questionable/pal8os2-sz.bmp      "questionable_pal8os2-sz.bmp"      COPYONLY)
configure_file(${TEST_DIR}/questionable/pal8os2sp.bmp       "questionable_pal8os2sp.bmp"       COPYONLY)
configure_file(${TEST_DIR}/questionable/pal8os2v2-16.bmp    "questionable_pal8os2v2-16.bmp"    COPYONLY)
configure_file(${TEST_DIR}/questionable/pal8os2v2-40sz.bmp  "questionable_pal8os2v2-40sz.bmp"  COPYONLY)
configure_file(${TEST_DIR}/questionable/pal8os2v2-sz.bmp    "questionable_pal8os2v2-sz.bmp"    COPYONLY)
configure_file(${TEST_DIR}/questionable/pal8os2v2.bmp       "questionable_pal8os2v2.bmp"       COPYONLY)
configure_file(${TEST_DIR}/questionable/pal8oversizepal.bmp "questionable_pal8oversizepal.bmp" COPYONLY)
configure_file(${TEST_DIR}/questionable/pal8rlecut.bmp      "questionable_pal8rlecut.bmp"      COPYONLY)
configure_file(${TEST_DIR}/questionable/pal8rletrns.bmp     "questionable_pal8rletrns.bmp"     COPYONLY)
configure_file(${TEST_DIR}/questionable/rgb16-231.bmp       "questionable_rgb16-231.bmp"       COPYONLY)
configure_file(${TEST_DIR}/questionable/rgb16-3103.bmp      "questionable_rgb16-3103.bmp"      COPYONLY)
configure_file(${TEST_DIR}/questionable/rgb16faketrns.bmp   "questionable_rgb16faketrns.bmp"   COPYONLY)
configure_file(${TEST_DIR}/questionable/rgb24jpeg.bmp       "questionable_rgb24jpeg.bmp"       COPYONLY)
configure_file(${TEST_DIR}/questionable/rgb24largepal.bmp   "questionable_rgb24largepal.bmp"   COPYONLY)
configure_file(${TEST_DIR}/questionable/rgb24lprof.bmp      "questionable_rgb24lprof.bmp"      COPYONLY)
configure_file(${TEST_DIR}/questionable/rgb24png.bmp        "questionable_rgb24png.bmp"        COPYONLY)
configure_file(${TEST_DIR}/questionable/rgb24prof.bmp       "questionable_rgb24prof.bmp"       COPYONLY)
configure_file(${TEST_DIR}/questionable/rgb24prof2.bmp      "questionable_rgb24prof2.bmp"      COPYONLY)
configure_file(${TEST_DIR}/questionable/rgb32-111110.bmp    "questionable_rgb32-111110.bmp"    COPYONLY)
configure_file(${TEST_DIR}/questionable/rgb32-7187.bmp      "questionable_rgb32-7187.bmp"      COPYONLY)
configure_file(${TEST_DIR}/questionable/rgb32-xbgr.bmp      "questionable_rgb32-xbgr.bmp"      COPYONLY)
configure_file(${TEST_DIR}/questionable/rgb32fakealpha.bmp  "questionable_rgb32fakealpha.bmp"  COPYONLY)
configure_file(${TEST_DIR}/questionable/rgb32h52.bmp        "questionable_rgb32h52.bmp"        COPYONLY)
configure_file(${TEST_DIR}/questionable/rgba16-1924.bmp     "questionable_rgba16-1924.bmp"     COPYONLY)
configure_file(${TEST_DIR}/questionable/rgba16-4444.bmp     "questionable_rgba16-4444.bmp"     COPYONLY)
configure_file(${TEST_DIR}/questionable/rgba16-5551.bmp     "questionable_rgba16-5551.bmp"     COPYONLY)
configure_file(${TEST_DIR}/questionable/rgba32-1010102.bmp  "questionable_rgba32-1010102.bmp"  COPYONLY)
configure_file(${TEST_DIR}/questionable/rgba32-61754.bmp    "questionable_rgba32-61754.bmp"    COPYONLY)
configure_file(${TEST_DIR}/questionable/rgba32-81284.bmp    "questionable_rgba32-81284.bmp"    COPYONLY)
configure_file(${TEST_DIR}/questionable/rgba32.bmp          "questionable_rgba32.bmp"          COPYONLY)
configure_file(${TEST_DIR}/questionable/rgba32abf.bmp       "questionable_rgba32abf.bmp"       COPYONLY)
configure_file(${TEST_DIR}/questionable/rgba32h56.bmp       "questionable_rgba32h56.bmp"       COPYONLY)
