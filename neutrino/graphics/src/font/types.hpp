#ifndef FRAMEWORK_GRAPHICS_SRC_FONT_TYPES_HPP
#define FRAMEWORK_GRAPHICS_SRC_FONT_TYPES_HPP

#include <cstdint>
#include <stdexcept>

namespace framework::graphics::details::font
{

std::uint32_t inline constexpr make_tag(char c1, char c2, char c3, char c4)
{
    return static_cast<std::uint32_t>(c1 << 24 | c2 << 16 | c3 << 8 | c4);
}

using FWord    = std::int16_t;  // int16 that describes a quantity in font design units.
using UFWord   = std::uint16_t; // uint16 that describes a quantity in font design units.
using Fixed    = std::int32_t;  // 32-bit signed fixed-point number (16.16)
using DateTime = std::int64_t;  // Date represented in number of seconds since 12:00 midnight, January 1, 1904.
using F2Dot14  = std::int16_t;  // 16-bit signed fixed number with the low 14 bits of fraction (2.14).
using Offset16 = std::uint16_t;
using Offset32 = std::uint32_t;

enum class PlatformId : std::uint16_t
{
    Unicode   = 0,
    Macintosh = 1,
    ISO       = 2, // deprecated
    Windows   = 3,
    Custom    = 4,

    Undefined = 0xFFFF,
};

enum class Tag : std::uint32_t
{
    Invalid = 0,

    // Required tables
    Cmap = make_tag('c', 'm', 'a', 'p'), // Character to glyph mapping
    Head = make_tag('h', 'e', 'a', 'd'), // Font header
    Hhea = make_tag('h', 'h', 'e', 'a'), // Horizontal header
    Hmtx = make_tag('h', 'm', 't', 'x'), // Horizontal metrics
    Maxp = make_tag('m', 'a', 'x', 'p'), // Maximum profile
    Name = make_tag('n', 'a', 'm', 'e'), // Naming table
    Os2  = make_tag('O', 'S', '/', '2'), // OS/2 and Windows specific metrics
    Post = make_tag('p', 'o', 's', 't'), // PostScript information

    // TrueType Outlines
    Cvt  = make_tag('c', 'v', 't', ' '), //	Control Value Table (optional table)
    Fpgm = make_tag('f', 'p', 'g', 'm'), //	Font program (optional table)
    Glyf = make_tag('g', 'l', 'y', 'f'), //	Glyph data
    Loca = make_tag('l', 'o', 'c', 'a'), //	Index to location
    Prep = make_tag('p', 'r', 'e', 'p'), //	CVT Program (optional table)
    Gasp = make_tag('g', 'a', 's', 'p'), //	Grid-fitting/Scan-conversion (optional table)

    // CFF Outlines
    Cff  = make_tag('C', 'F', 'F', ' '), //	Compact Font Format 1.0
    Cff2 = make_tag('C', 'F', 'F', '2'), //	Compact Font Format 2.0
    Vorg = make_tag('V', 'O', 'R', 'G'), //	Vertical Origin (optional table)

    //  SVG Outlines
    Svg = make_tag('S', 'V', 'G', ' '), //	The SVG (Scalable Vector Graphics) table

    // Bitmap Glyphs
    Ebdt = make_tag('E', 'B', 'D', 'T'), //	Embedded bitmap data
    Eblc = make_tag('E', 'B', 'L', 'C'), //	Embedded bitmap location data
    Ebsc = make_tag('E', 'B', 'S', 'C'), //	Embedded bitmap scaling data
    Cbdt = make_tag('C', 'B', 'D', 'T'), //	Color bitmap data
    Cblc = make_tag('C', 'B', 'L', 'C'), //	Color bitmap location data
    Sbix = make_tag('s', 'b', 'i', 'x'), //	Standard bitmap graphics

    // Advanced Typographic
    Base = make_tag('B', 'A', 'S', 'E'), //	Baseline data
    Gdef = make_tag('G', 'D', 'E', 'F'), //	Glyph definition data
    Gpos = make_tag('G', 'P', 'O', 'S'), //	Glyph positioning data
    Gsub = make_tag('G', 'S', 'U', 'B'), //	Glyph substitution data
    Jstf = make_tag('J', 'S', 'T', 'F'), //	Justification data
    Math = make_tag('M', 'A', 'T', 'H'), //	Math layout data

    // OpenType Font Variations
    Avar = make_tag('a', 'v', 'a', 'r'), //	Axis variations
    Cvar = make_tag('c', 'v', 'a', 'r'), //	CVT variations (TrueType outlines only)
    Fvar = make_tag('f', 'v', 'a', 'r'), //	Font variations
    Gvar = make_tag('g', 'v', 'a', 'r'), //	Glyph variations (TrueType outlines only)
    Hvar = make_tag('H', 'V', 'A', 'R'), //	Horizontal metrics variations
    Mvar = make_tag('M', 'V', 'A', 'R'), //	Metrics variations
    Stat = make_tag('S', 'T', 'A', 'T'), //	Style attributes
                                         // (required for variable fonts, optional for non-variable fonts)
    Vvar = make_tag('V', 'V', 'A', 'R'), //	Vertical metrics variations

    // Color Fonts
    Colr = make_tag('C', 'O', 'L', 'R'), //	Color table
    Cpal = make_tag('C', 'P', 'A', 'L'), //	Color palette table

    // OpenType Tables
    Dsig = make_tag('D', 'S', 'I', 'G'), //	Digital signature
    Hdmx = make_tag('h', 'd', 'm', 'x'), //	Horizontal device metrics
    Kern = make_tag('k', 'e', 'r', 'n'), //	Kerning
    Ltsh = make_tag('L', 'T', 'S', 'H'), //	Linear threshold data
    Merg = make_tag('M', 'E', 'R', 'G'), //	Merge
    Meta = make_tag('m', 'e', 't', 'a'), //	Metadata
    Pclt = make_tag('P', 'C', 'L', 'T'), //	PCL 5 data
    Vdmx = make_tag('V', 'D', 'M', 'X'), //	Vertical device metrics
    Vhea = make_tag('v', 'h', 'e', 'a'), //	Vertical Metrics header
    Vmtx = make_tag('v', 'm', 't', 'x'), //	Vertical Metrics
};

class UnsupportedError final : public std::runtime_error
{
    using std::runtime_error::runtime_error;
};

class UnimplementedError final : public std::runtime_error
{
    using std::runtime_error::runtime_error;
};

} // namespace framework::graphics::details::font

#endif
