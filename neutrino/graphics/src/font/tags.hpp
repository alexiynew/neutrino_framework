////////////////////////////////////////////////////////////////////////////////
/// @file
/// @brief Font tags
/// @author Fedorov Alexey
/// @date 04.09.2020
////////////////////////////////////////////////////////////////////////////////

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

#ifndef FRAMEWORK_GRAPHICS_SRC_FONT_TAGS_HPP
#define FRAMEWORK_GRAPHICS_SRC_FONT_TAGS_HPP

#include <cstdint>

namespace framework::graphics::details::font
{

std::uint32_t inline constexpr make_tag(char c1, char c2, char c3, char c4)
{
    return (c1 << 24 | c2 << 16 | c3 << 8 | c4);
}

enum class Tag : std::uint32_t
{
    invalid = 0,

    // Required tables
    cmap = make_tag('c', 'm', 'a', 'p'), // Character to glyph mapping
    head = make_tag('h', 'e', 'a', 'd'), // Font header
    hhea = make_tag('h', 'h', 'e', 'a'), // Horizontal header
    hmtx = make_tag('h', 'm', 't', 'x'), // Horizontal metrics
    maxp = make_tag('m', 'a', 'x', 'p'), // Maximum profile
    name = make_tag('n', 'a', 'm', 'e'), // Naming table
    OS2  = make_tag('O', 'S', '/', '2'), // OS/2 and Windows specific metrics
    post = make_tag('p', 'o', 's', 't'), // PostScript information

    // TrueType Outlines
    cvt  = make_tag('c', 'v', 't', ' '), //	Control Value Table (optional table)
    fpgm = make_tag('f', 'p', 'g', 'm'), //	Font program (optional table)
    glyf = make_tag('g', 'l', 'y', 'f'), //	Glyph data
    loca = make_tag('l', 'o', 'c', 'a'), //	Index to location
    prep = make_tag('p', 'r', 'e', 'p'), //	CVT Program (optional table)
    gasp = make_tag('g', 'a', 's', 'p'), //	Grid-fitting/Scan-conversion (optional table)

    // CFF Outlines
    CFF  = make_tag('C', 'F', 'F', ' '), //	Compact Font Format 1.0
    CFF2 = make_tag('C', 'F', 'F', '2'), //	Compact Font Format 2.0
    VORG = make_tag('V', 'O', 'R', 'G'), //	Vertical Origin (optional table)

    //  SVG Outlines
    SVG = make_tag('S', 'V', 'G', ' '), //	The SVG (Scalable Vector Graphics) table

    // Bitmap Glyphs
    EBDT = make_tag('E', 'B', 'D', 'T'), //	Embedded bitmap data
    EBLC = make_tag('E', 'B', 'L', 'C'), //	Embedded bitmap location data
    EBSC = make_tag('E', 'B', 'S', 'C'), //	Embedded bitmap scaling data
    CBDT = make_tag('C', 'B', 'D', 'T'), //	Color bitmap data
    CBLC = make_tag('C', 'B', 'L', 'C'), //	Color bitmap location data
    sbix = make_tag('s', 'b', 'i', 'x'), //	Standard bitmap graphics

    // Advanced Typographic
    BASE = make_tag('B', 'A', 'S', 'E'), //	Baseline data
    GDEF = make_tag('G', 'D', 'E', 'F'), //	Glyph definition data
    GPOS = make_tag('G', 'P', 'O', 'S'), //	Glyph positioning data
    GSUB = make_tag('G', 'S', 'U', 'B'), //	Glyph substitution data
    JSTF = make_tag('J', 'S', 'T', 'F'), //	Justification data
    MATH = make_tag('M', 'A', 'T', 'H'), //	Math layout data

    // OpenType Font Variations
    avar = make_tag('a', 'v', 'a', 'r'), //	Axis variations
    cvar = make_tag('c', 'v', 'a', 'r'), //	CVT variations (TrueType outlines only)
    fvar = make_tag('f', 'v', 'a', 'r'), //	Font variations
    gvar = make_tag('g', 'v', 'a', 'r'), //	Glyph variations (TrueType outlines only)
    HVAR = make_tag('H', 'V', 'A', 'R'), //	Horizontal metrics variations
    MVAR = make_tag('M', 'V', 'A', 'R'), //	Metrics variations
    STAT = make_tag('S', 'T', 'A', 'T'), //	Style attributes
                                         // (required for variable fonts, optional for non-variable fonts)
    VVAR = make_tag('V', 'V', 'A', 'R'), //	Vertical metrics variations

    // Color Fonts
    COLR = make_tag('C', 'O', 'L', 'R'), //	Color table
    CPAL = make_tag('C', 'P', 'A', 'L'), //	Color palette table

    // OpenType Tables
    DSIG = make_tag('D', 'S', 'I', 'G'), //	Digital signature
    hdmx = make_tag('h', 'd', 'm', 'x'), //	Horizontal device metrics
    kern = make_tag('k', 'e', 'r', 'n'), //	Kerning
    LTSH = make_tag('L', 'T', 'S', 'H'), //	Linear threshold data
    MERG = make_tag('M', 'E', 'R', 'G'), //	Merge
    meta = make_tag('m', 'e', 't', 'a'), //	Metadata
    PCLT = make_tag('P', 'C', 'L', 'T'), //	PCL 5 data
    VDMX = make_tag('V', 'D', 'M', 'X'), //	Vertical device metrics
    vhea = make_tag('v', 'h', 'e', 'a'), //	Vertical Metrics header
    vmtx = make_tag('v', 'm', 't', 'x'), //	Vertical Metrics
};


}

#endif

