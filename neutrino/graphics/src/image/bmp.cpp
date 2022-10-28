#include <algorithm>
#include <cmath>
#include <fstream>
#include <memory>
#include <vector>

#include <common/exceptions.hpp>
#include <common/utils.hpp>
#include <graphics/color.hpp>

#include <graphics/src/image/bmp.hpp>

namespace
{
using namespace framework;
using graphics::Color;
using graphics::details::image::ImageInfo;

//  | signature | file size | reserved | reserved | pixel array offset |
//  |------------------------------------------------------------------|
//  | 2         | 4         | 2        | 2        | 4                  |
struct FileHeader
{
    static FileHeader read(std::ifstream& in);

    bool is_valid() const;

    std::uint16_t signature          = 0;
    std::uint32_t file_size          = 0;
    std::uint32_t pixel_array_offset = 0;
};

FileHeader FileHeader::read(std::ifstream& in)
{
    using std::begin;
    using std::end;

    constexpr size_t size = 14;

    char buffer[size] = {0};
    in.read(buffer, size);

    FileHeader header;
    header.signature          = utils::little_endian_value<std::uint16_t>(begin(buffer));
    header.file_size          = utils::little_endian_value<std::uint32_t>(begin(buffer) + 2);
    header.pixel_array_offset = utils::little_endian_value<std::uint32_t>(begin(buffer) + 10);

    return header;
}

struct InfoHeader
{
    enum class Type
    {
        undefined             = 0,
        bitmapcoreheader      = 12,
        os22xbitmapheader     = 16,
        bitmapinfoheader      = 40,
        bitmapv2infoheader    = 52,
        bitmapv3infoheader    = 56,
        os22xbitmapheaderfull = 64,
        bitmapv4header        = 108,
        bitmapv5header        = 124
    };

    enum class Compression : std::uint32_t
    {
        bi_rgb            = 0, // none
        bi_rle8           = 1, // RLE 8-bit/pixel
        bi_rle4           = 2, // RLE 4-bit/pixel
        bi_bitfields      = 3, // OS22XBITMAPHEADER: Huffman 1D
        bi_jpeg           = 4, //
        bi_png            = 5, //
        bi_alphabitfields = 6, // RGBA bit field masks
    };

    enum class ColorSpace : std::uint32_t
    {
        lcs_calibrated_rgb      = 0,          // Use endpoints
        lcs_srgb                = 0x73524742, // sRGB
        lcs_windows_color_space = 0x57696E20, // System color space (sRBG by default)
        profile_linked          = 0x4C494E4B, // Profile in another file
        profile_embedded        = 0x4D424544, // Profile in this file
    };

    struct CieXYZ
    {
        std::uint32_t x = 0;
        std::uint32_t y = 0;
        std::uint32_t z = 0;
    };

    struct CieXYZTriple
    {
        CieXYZ red;
        CieXYZ green;
        CieXYZ blue;
    };

    using ColorTable = std::vector<Color>;

    static InfoHeader read(std::ifstream& in);
    static ColorTable read_color_table(std::ifstream& in, const InfoHeader& info);

    bool is_valid() const;

    Type type() const;
    bool bottom_up() const;
    std::tuple<std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t> chanel_masks() const;

    // BITMAPCOREHEADER
    std::uint32_t size           = 0;
    std::int32_t width           = 0;
    std::int32_t height          = 0;
    std::uint16_t planes         = 0;
    std::uint16_t bits_per_pixel = 0;

    // BITMAPINFOHEADER
    Compression compression        = Compression::bi_rgb;
    std::uint32_t image_size       = 0;
    std::int32_t x_ppm             = 0;
    std::int32_t y_ppm             = 0;
    std::uint32_t colors_in_table  = 0;
    std::uint32_t important_colors = 0;

    // BITMAPV2INFOHEADER
    std::uint32_t red_chanel_bitmask   = 0; //  +-
    std::uint32_t green_chanel_bitmask = 0; //  | matter only if bits_per_pixel == 16 or 32
    std::uint32_t blue_chanel_bitmask  = 0; //  |
                                            //  |
    // BITMAPV3INFOHEADER            //  |
    std::uint32_t alpha_chanel_bitmask = 0; //  +-

    // BITMAPV4HEADER
    ColorSpace color_space_type = ColorSpace::lcs_calibrated_rgb;
    CieXYZTriple endpoints;        //  +-
    std::uint32_t gamma_red   = 0; //  | matter only if color_space_type == lcs_calibrated_rgb
    std::uint32_t gamma_green = 0; //  |
    std::uint32_t gamma_blue  = 0; //  +-

    // BITMAPV4HEADER
    std::uint32_t intent               = 0;
    std::uint32_t color_profile_offset = 0;
    std::uint32_t color_profile_size   = 0;
    std::uint32_t reserved             = 0;

    ColorTable color_table;
};

inline bool check_signature(const FileHeader& h) noexcept
{
    switch (h.signature) {
        case 0x4D42: return true; // BM
        case 0x4142: return true; // BA
        case 0x4943: return true; // CI
        case 0x5043: return true; // CP
        case 0x4349: return true; // IC
        case 0x5450: return true; // PT
        default: break;
    }

    return false;
}

bool FileHeader::is_valid() const
{
    constexpr std::size_t max_file_size = 1024 * 1024 * 1024;
    return check_signature(*this) && file_size < max_file_size;
}

inline bool check_size(const InfoHeader& h) noexcept
{
    constexpr std::int32_t max_size      = 30000;
    constexpr std::int32_t max_data_size = 1024 * 1024 * 1024;
    constexpr std::int32_t max_ppm       = 10000;
    const std::int32_t abs_height        = std::abs(h.height);

    return h.width > 0 && abs_height > 0 && h.width <= max_size && abs_height <= max_size &&
           h.image_size < max_data_size &&
           h.width * abs_height * static_cast<std::int32_t>(sizeof(Color)) < max_data_size && h.x_ppm < max_ppm &&
           h.y_ppm < max_ppm;
}

inline bool check_compression(const InfoHeader& h) noexcept
{
    if (h.type() == InfoHeader::Type::bitmapcoreheader) {
        return true;
    }

    switch (h.compression) {
        case InfoHeader::Compression::bi_rgb: return h.bits_per_pixel != 0;
        case InfoHeader::Compression::bi_rle8: return h.bits_per_pixel == 8 && h.height > 0;
        case InfoHeader::Compression::bi_rle4: return h.bits_per_pixel == 4 && h.height > 0;
        case InfoHeader::Compression::bi_bitfields: return h.bits_per_pixel == 16 || h.bits_per_pixel == 32;
        case InfoHeader::Compression::bi_jpeg: return false; // unsupported
        case InfoHeader::Compression::bi_png: return false;  // unsupported
        case InfoHeader::Compression::bi_alphabitfields: return h.bits_per_pixel == 16 || h.bits_per_pixel == 32;
    }

    return false;
}

inline bool check_color_space_type(const InfoHeader& h) noexcept
{
    if (h.size < static_cast<std::uint32_t>(InfoHeader::Type::bitmapv4header)) {
        return true;
    }

    switch (h.color_space_type) {
        case InfoHeader::ColorSpace::lcs_calibrated_rgb: return true;
        case InfoHeader::ColorSpace::lcs_srgb: return true;
        case InfoHeader::ColorSpace::lcs_windows_color_space: return true;
        case InfoHeader::ColorSpace::profile_linked: return false;   // unsupported
        case InfoHeader::ColorSpace::profile_embedded: return false; // unsupported
    }

    return false;
}

inline bool check_bits_per_pixel(const InfoHeader& h) noexcept
{
    switch (h.bits_per_pixel) {
        case 1:
        case 2:
        case 4:
        case 8:
        case 16:
        case 24:
        case 32: return true;
        default: break;
    }

    return false;
}

bool InfoHeader::is_valid() const
{
    bool result = type() != InfoHeader::Type::undefined;
    result      = result && planes == 1;
    result      = result && check_size(*this);
    result      = result && check_compression(*this);
    result      = result && check_color_space_type(*this);
    result      = result && check_bits_per_pixel(*this);

    return result;
}

inline InfoHeader::Type InfoHeader::type() const
{
    switch (static_cast<Type>(size)) {
        case Type::undefined: return Type::undefined;

        case Type::bitmapcoreheader:
        case Type::os22xbitmapheader:
        case Type::bitmapinfoheader:
        case Type::bitmapv2infoheader:
        case Type::bitmapv3infoheader:
        case Type::os22xbitmapheaderfull:
        case Type::bitmapv4header:
        case Type::bitmapv5header: return static_cast<Type>(size);
    }

    return Type::undefined;
}

inline bool InfoHeader::bottom_up() const
{
    return type() == InfoHeader::Type::bitmapcoreheader ? true : height > 0;
}

inline std::tuple<std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t> InfoHeader::chanel_masks() const
{
    const std::uint32_t alpha_mask = alpha_chanel_bitmask ? alpha_chanel_bitmask : 0;

    if (red_chanel_bitmask || green_chanel_bitmask || blue_chanel_bitmask) {
        return std::make_tuple(red_chanel_bitmask, green_chanel_bitmask, blue_chanel_bitmask, alpha_mask);
    } else if (bits_per_pixel == 16) {
        return std::make_tuple(0x7C00, 0x03E0, 0x001F, alpha_mask);
    } else if (bits_per_pixel == 32) {
        return std::make_tuple(0xFF0000, 0x00FF00, 0x0000FF, alpha_mask);
    }

    return std::make_tuple(0, 0, 0, 0);
}

InfoHeader InfoHeader::read(std::ifstream& in)
{
    using std::begin;
    using std::end;

    char size_buffer[4];
    in.read(size_buffer, sizeof(size_buffer));

    InfoHeader h;
    h.size = utils::little_endian_value<std::uint32_t>(begin(size_buffer));

    const size_t data_size = h.size - sizeof(size_buffer);
    std::unique_ptr<char[]> buffer(new char[data_size]);
    in.read(buffer.get(), static_cast<std::streamsize>(data_size));

    if (h.type() == Type::bitmapcoreheader) {
        h.width          = utils::little_endian_value<std::uint16_t>(buffer.get());
        h.height         = utils::little_endian_value<std::uint16_t>(buffer.get() + 2);
        h.planes         = utils::little_endian_value<std::uint16_t>(buffer.get() + 4);
        h.bits_per_pixel = utils::little_endian_value<std::uint16_t>(buffer.get() + 6);
    } else {
        h.width          = utils::little_endian_value<std::int32_t>(buffer.get());
        h.height         = utils::little_endian_value<std::int32_t>(buffer.get() + 4);
        h.planes         = utils::little_endian_value<std::uint16_t>(buffer.get() + 8);
        h.bits_per_pixel = utils::little_endian_value<std::uint16_t>(buffer.get() + 10);
    }

    if (h.size >= static_cast<std::uint32_t>(InfoHeader::Type::bitmapinfoheader)) {
        h.compression      = utils::little_endian_value<Compression>(buffer.get() + 12);
        h.image_size       = utils::little_endian_value<std::uint32_t>(buffer.get() + 16);
        h.x_ppm            = utils::little_endian_value<std::int32_t>(buffer.get() + 20);
        h.y_ppm            = utils::little_endian_value<std::int32_t>(buffer.get() + 24);
        h.colors_in_table  = utils::little_endian_value<std::uint32_t>(buffer.get() + 28);
        h.important_colors = utils::little_endian_value<std::uint32_t>(buffer.get() + 32);
    }

    if (h.type() == InfoHeader::Type::bitmapinfoheader &&
        (h.compression == Compression::bi_bitfields || h.compression == Compression::bi_alphabitfields)) {

        const size_t mask_buffer_size      = 3 * sizeof(std::uint32_t);
        char mask_buffer[mask_buffer_size] = {};
        in.read(mask_buffer, sizeof(mask_buffer_size));

        h.red_chanel_bitmask   = utils::little_endian_value<std::uint32_t>(begin(mask_buffer));
        h.green_chanel_bitmask = utils::little_endian_value<std::uint32_t>(begin(mask_buffer) + 4);
        h.blue_chanel_bitmask  = utils::little_endian_value<std::uint32_t>(begin(mask_buffer) + 8);
    }

    if (h.size == static_cast<std::uint32_t>(InfoHeader::Type::bitmapinfoheader) &&
        h.compression == Compression::bi_alphabitfields) {
        char mask_buffer[sizeof(std::uint32_t)] = {};
        in.read(mask_buffer, sizeof(mask_buffer));

        h.alpha_chanel_bitmask = utils::little_endian_value<std::uint32_t>(begin(mask_buffer));
    }

    if (h.size >= static_cast<std::uint32_t>(InfoHeader::Type::bitmapv2infoheader)) {
        h.red_chanel_bitmask   = utils::little_endian_value<std::uint32_t>(buffer.get() + 36);
        h.green_chanel_bitmask = utils::little_endian_value<std::uint32_t>(buffer.get() + 40);
        h.blue_chanel_bitmask  = utils::little_endian_value<std::uint32_t>(buffer.get() + 44);
    }

    if (h.size >= static_cast<std::uint32_t>(InfoHeader::Type::bitmapv3infoheader)) {
        h.alpha_chanel_bitmask = utils::little_endian_value<std::uint32_t>(buffer.get() + 48);
    }

    if (h.size >= static_cast<std::uint32_t>(InfoHeader::Type::bitmapv4header)) {
        h.color_space_type = utils::little_endian_value<ColorSpace>(buffer.get() + 52);

        h.endpoints.red.x   = utils::little_endian_value<std::uint32_t>(buffer.get() + 56);
        h.endpoints.red.y   = utils::little_endian_value<std::uint32_t>(buffer.get() + 60);
        h.endpoints.red.z   = utils::little_endian_value<std::uint32_t>(buffer.get() + 64);
        h.endpoints.green.x = utils::little_endian_value<std::uint32_t>(buffer.get() + 68);
        h.endpoints.green.y = utils::little_endian_value<std::uint32_t>(buffer.get() + 72);
        h.endpoints.green.z = utils::little_endian_value<std::uint32_t>(buffer.get() + 76);
        h.endpoints.blue.x  = utils::little_endian_value<std::uint32_t>(buffer.get() + 80);
        h.endpoints.blue.y  = utils::little_endian_value<std::uint32_t>(buffer.get() + 84);
        h.endpoints.blue.z  = utils::little_endian_value<std::uint32_t>(buffer.get() + 88);

        h.gamma_red   = utils::little_endian_value<std::uint32_t>(buffer.get() + 92);
        h.gamma_green = utils::little_endian_value<std::uint32_t>(buffer.get() + 96);
        h.gamma_blue  = utils::little_endian_value<std::uint32_t>(buffer.get() + 100);
    }

    if (h.size >= static_cast<std::uint32_t>(InfoHeader::Type::bitmapv5header)) {
        h.intent               = utils::little_endian_value<std::uint32_t>(buffer.get() + 104);
        h.color_profile_offset = utils::little_endian_value<std::uint32_t>(buffer.get() + 108);
        h.color_profile_size   = utils::little_endian_value<std::uint32_t>(buffer.get() + 112);
        h.reserved             = utils::little_endian_value<std::uint32_t>(buffer.get() + 116);
    }

    if (h.bits_per_pixel <= 8) {
        h.color_table = read_color_table(in, h);
    }

    return h;
}

InfoHeader::ColorTable InfoHeader::read_color_table(std::ifstream& in, const InfoHeader& info)
{
    const size_t colors_count = [&info]() {
        if (info.bits_per_pixel >= 1 && info.bits_per_pixel <= 8 &&
            (info.type() == Type::bitmapcoreheader || info.colors_in_table == 0)) {
            return static_cast<std::uint32_t>(std::pow(2, info.bits_per_pixel));
        }

        return info.colors_in_table;
    }();

    const size_t cell_size = [&info]() -> size_t {
        switch (info.type()) {
            case Type::undefined: return 0;
            case Type::bitmapcoreheader: return 3;
            case Type::os22xbitmapheader:
            case Type::bitmapinfoheader:
            case Type::bitmapv2infoheader:
            case Type::bitmapv3infoheader:
            case Type::os22xbitmapheaderfull:
            case Type::bitmapv4header:
            case Type::bitmapv5header: return 4;
        }

        return 0;
    }();

    if (colors_count == 0 || cell_size == 0) {
        return ColorTable();
    }

    const size_t buffer_size = colors_count * static_cast<size_t>(cell_size);
    std::unique_ptr<char[]> buffer(new char[buffer_size]);
    in.read(buffer.get(), static_cast<std::streamsize>(buffer_size));

    if (!in) {
        return ColorTable();
    }

    ColorTable table(colors_count);
    for (std::uint32_t i = 0; i < colors_count; ++i) {
        const size_t offset = i * cell_size;

        table[i].r = static_cast<std::uint8_t>(buffer[offset + 2]);
        table[i].g = static_cast<std::uint8_t>(buffer[offset + 1]);
        table[i].b = static_cast<std::uint8_t>(buffer[offset + 0]);
        table[i].a = 255;
    }

    return table;
}

inline ImageInfo make_image_info(const InfoHeader& h, std::vector<Color>&& data) noexcept
{
    return ImageInfo{static_cast<size_t>(h.width),
                     static_cast<size_t>(std::abs(h.height)),
                     graphics::details::image::default_gamma,
                     std::move(data)};
}

inline std::uint32_t get_offset(std::uint32_t value)
{
    std::uint32_t count = 0;
    while ((value & 1) == 0) {
        count++;
        value >>= 1;
    }

    return count;
}

inline std::uint8_t masked_value(std::uint32_t pixel, std::uint32_t mask, std::uint32_t offset)
{
    const std::uint32_t value = (pixel & mask) >> offset;
    const std::uint32_t scale = mask >> offset;
    return scale ? static_cast<std::uint8_t>((static_cast<float>(value) / static_cast<float>(scale)) * 255) : 0;
}

std::vector<Color>::iterator process_row_1bpp(std::vector<std::uint8_t>::iterator in,
                                              std::vector<Color>::iterator out,
                                              const InfoHeader& info)
{
    for (std::int32_t x = 0; x < info.width; ++in) {
        for (std::int32_t bit = 7; bit >= 0 && x < info.width; --bit, ++x) {
            const std::uint32_t color_index = (*in & (1 << bit)) ? 1 : 0;

            *out++ = info.color_table.at(color_index);
        }
    }

    return out;
}

std::vector<Color>::iterator process_row_2bpp(std::vector<std::uint8_t>::iterator in,
                                              std::vector<Color>::iterator out,
                                              const InfoHeader& info)
{
    const auto end = next(out, info.width);

    std::int32_t offset = 6;
    while (out != end) {
        *out++ = info.color_table.at((*in >> offset) & 0x03);

        if (offset == 0) {
            offset = 6;
            in++;
        } else {
            offset -= 2;
        }
    }

    return out;
}

std::vector<Color>::iterator process_row_4bpp(std::vector<std::uint8_t>::iterator in,
                                              std::vector<Color>::iterator out,
                                              const InfoHeader& info)
{
    for (std::int32_t x = 0, offset = 4; x < info.width; ++x, offset = ((offset + 4) % 8)) {
        *out++ = info.color_table.at((*in >> offset) & 0x0F);
        if (offset == 0) {
            in++;
        }
    }
    return out;
}

std::vector<Color>::iterator process_row_8bpp(std::vector<std::uint8_t>::iterator in,
                                              std::vector<Color>::iterator out,
                                              const InfoHeader& info)
{
    for (std::int32_t x = 0; x < info.width; ++x) {
        *out++ = info.color_table.at(*in++);
    }
    return out;
}

std::vector<Color>::iterator process_row_16bpp(std::vector<std::uint8_t>::iterator in,
                                               std::vector<Color>::iterator out,
                                               const InfoHeader& info)
{
    const auto [red_mask, green_mask, blue_mask, alpha_mask] = info.chanel_masks();

    const std::uint32_t red_offset   = (red_mask ? get_offset(red_mask) : 0);
    const std::uint32_t green_offset = (green_mask ? get_offset(green_mask) : 0);
    const std::uint32_t blue_offset  = (blue_mask ? get_offset(blue_mask) : 0);
    const std::uint32_t alpha_offset = (alpha_mask ? get_offset(alpha_mask) : 0);

    for (std::int32_t x = 0; x < info.width; ++x) {
        std::uint32_t pixel = *in++;
        pixel += static_cast<std::uint32_t>(*in++ << 8);

        const Color color(masked_value(pixel, red_mask, red_offset),
                          masked_value(pixel, green_mask, green_offset),
                          masked_value(pixel, blue_mask, blue_offset),
                          (alpha_mask ? masked_value(pixel, alpha_mask, alpha_offset) : 255));
        *out++ = color;
    }

    return out;
}

std::vector<Color>::iterator process_row_24bpp(std::vector<std::uint8_t>::iterator in,
                                               std::vector<Color>::iterator out,
                                               const InfoHeader& info)
{
    for (std::int32_t x = 0; x < info.width; ++x) {
        const Color color(*in++, *in++, *in++, 255U);
        *out++ = color;
    }

    return out;
}

std::vector<Color>::iterator process_row_32bpp(std::vector<std::uint8_t>::iterator in,
                                               std::vector<Color>::iterator out,
                                               const InfoHeader& info)
{
    const auto [red_mask, green_mask, blue_mask, alpha_mask] = info.chanel_masks();
    const std::uint32_t red_offset                           = (red_mask ? get_offset(red_mask) : 0);
    const std::uint32_t green_offset                         = (green_mask ? get_offset(green_mask) : 0);
    const std::uint32_t blue_offset                          = (blue_mask ? get_offset(blue_mask) : 0);
    const std::uint32_t alpha_offset                         = (alpha_mask ? get_offset(alpha_mask) : 0);

    for (std::int32_t x = 0; x < info.width; ++x) {
        std::uint32_t pixel = *in++;
        pixel += static_cast<std::uint32_t>(*in++ << 8);
        pixel += static_cast<std::uint32_t>(*in++ << 16);
        pixel += static_cast<std::uint32_t>(*in++ << 24);

        const Color color(masked_value(pixel, red_mask, red_offset),
                          masked_value(pixel, green_mask, green_offset),
                          masked_value(pixel, blue_mask, blue_offset),
                          (alpha_mask ? masked_value(pixel, alpha_mask, alpha_offset) : 255));
        *out++ = color;
    }

    return out;
}

std::vector<Color>::iterator process_row(std::vector<std::uint8_t>::iterator in,
                                         std::vector<Color>::iterator out,
                                         const InfoHeader& info)
{
    switch (info.bits_per_pixel) {
        case 1: return process_row_1bpp(in, out, info);
        case 2: return process_row_2bpp(in, out, info);
        case 4: return process_row_4bpp(in, out, info);
        case 8: return process_row_8bpp(in, out, info);
        case 16: return process_row_16bpp(in, out, info);
        case 24: return process_row_24bpp(in, out, info);
        case 32: return process_row_32bpp(in, out, info);
        default: break;
    }

    return out;
}

std::vector<Color> read_data_raw(std::ifstream& in, const InfoHeader& info)
{
    const std::int32_t height = std::abs(info.height);
    const size_t image_size   = static_cast<size_t>(info.width * height);
    std::vector<Color> image_data(image_size);

    const std::uint32_t row_size = static_cast<std::uint32_t>(((info.bits_per_pixel * info.width + 31) / 32) * 4);
    std::vector<std::uint8_t> buffer(row_size);

    auto out = begin(image_data);
    for (std::int32_t y = 0; y < height && in; ++y) {
        if (in.read(reinterpret_cast<char*>(buffer.data()), row_size)) {
            out = process_row(buffer.begin(), out, info);
        }
    }

    return image_data;
}

inline std::vector<Color>::iterator fill_with_color_4(std::vector<Color>::iterator out,
                                                      const InfoHeader::ColorTable& color_table,
                                                      const std::vector<std::uint8_t>::iterator it,
                                                      std::int32_t count)
{
    for (std::int32_t c = 0, offset = 4; c < count; ++c) {
        const std::size_t color_index = static_cast<std::size_t>((*it >> offset) & 0x0F);
        *out++ = color_index < color_table.size() ? color_table[color_index] : Color(0x000000FFU);
        offset = (offset == 0 ? 4 : 0);
    }
    return out;
}

inline std::vector<Color>::iterator fill_with_color_8(std::vector<Color>::iterator out,
                                                      const InfoHeader::ColorTable& color_table,
                                                      const std::vector<std::uint8_t>::iterator it,
                                                      std::int32_t count)
{
    const std::size_t color_index = static_cast<std::size_t>(*it);
    const Color color             = color_index < color_table.size() ? color_table[color_index] : Color(0x000000FFU);
    for (std::int32_t c = 0; c < count; ++c) {
        *out++ = color;
    }
    return out;
}

inline std::vector<Color>::iterator fill_from_buffer_4(std::vector<Color>::iterator out,
                                                       const InfoHeader::ColorTable& color_table,
                                                       std::vector<std::uint8_t>::iterator it,
                                                       std::int32_t count)
{
    const std::int32_t colors_in_byte = 2;
    while (count > 0) {
        out = fill_with_color_4(out, color_table, it, (count >= colors_in_byte ? colors_in_byte : 1));
        count -= colors_in_byte;
        it++;
    }
    return out;
}

inline std::vector<Color>::iterator fill_from_buffer_8(std::vector<Color>::iterator out,
                                                       const InfoHeader::ColorTable& color_table,
                                                       std::vector<std::uint8_t>::iterator it,
                                                       std::int32_t count)
{
    while (count-- > 0) {
        const std::size_t color_index = static_cast<std::size_t>(*it++);
        *out++ = color_index < color_table.size() ? color_table[color_index] : Color(0x000000FFU);
    }
    return out;
}

std::vector<Color> read_data_rle(std::ifstream& input, const InfoHeader& info)
{
    const std::int32_t height     = std::abs(info.height);
    const std::int32_t image_size = info.width * height;
    std::vector<Color> image_data(static_cast<std::size_t>(image_size));

    std::vector<std::uint8_t> buffer(info.image_size);
    input.read(reinterpret_cast<char*>(buffer.data()), info.image_size);

    auto in  = begin(buffer);
    auto out = begin(image_data);

    while (in != end(buffer) && out != end(image_data)) {
        if (*in == 0x00) {
            ++in;
            switch (*in) {
                case 0x00: {
                    const std::int32_t d = static_cast<std::int32_t>(distance(image_data.begin(), out)) % info.width;
                    if (d != 0) {
                        advance(out, info.width - d);
                    }
                    in++;
                } break;
                case 0x01: in = end(buffer); break;
                case 0x02: {
                    in++;

                    const std::int32_t w = *in++;
                    const std::int32_t h = *in++;

                    const std::int32_t step = h * info.width + w;
                    const std::int32_t dist = static_cast<std::int32_t>(std::distance(out, image_data.end()));

                    if (step > dist) {
                        throw ParsingError("Bad rle encoding.");
                    }

                    advance(out, step);
                } break;
                default: {
                    const std::int32_t count = *in++;

                    if (next(out, count) > end(image_data)) {
                        out = end(image_data);
                        break;
                    }

                    if (info.bits_per_pixel == 4) {
                        out = fill_from_buffer_4(out, info.color_table, in, count);
                        advance(in, ((count + 3) / 4) * 2);
                    } else {
                        out = fill_from_buffer_8(out, info.color_table, in, count);
                        advance(in, ((count + 1) / 2) * 2);
                    }

                } break;
            }
        } else {
            const std::int32_t count = *in++;

            if (next(out, count) > end(image_data)) {
                out = end(image_data);
                break;
            }

            if (info.bits_per_pixel == 4) {
                out = fill_with_color_4(out, info.color_table, in, count);
            } else {
                out = fill_with_color_8(out, info.color_table, in, count);
            }

            in++;
        }
    }

    return image_data;
}

std::vector<Color> read_data(std::ifstream& in, const InfoHeader& info)
{
    switch (info.compression) {
        case InfoHeader::Compression::bi_rle4:
        case InfoHeader::Compression::bi_rle8: return read_data_rle(in, info);
        case InfoHeader::Compression::bi_rgb:
        case InfoHeader::Compression::bi_bitfields:
        case InfoHeader::Compression::bi_alphabitfields: return read_data_raw(in, info);
        case InfoHeader::Compression::bi_jpeg:
        case InfoHeader::Compression::bi_png: return std::vector<Color>();
    }
    return std::vector<Color>();
}

std::vector<Color> flip_vertically(const InfoHeader& info, const std::vector<Color>& data)
{
    std::vector<Color> tmp;
    tmp.reserve(data.size());

    auto row_end = data.end();

    for (std::size_t y = 0; y < static_cast<std::size_t>(std::abs(info.height)); ++y) {
        auto row_begin = std::prev(row_end, info.width);
        std::copy(row_begin, row_end, std::back_inserter(tmp));
        row_end = row_begin;
    }

    return tmp;
}

} // namespace

namespace framework::graphics::details::image::bmp
{
ImageInfo load(const std::filesystem::path& filepath)
{
    std::ifstream file(filepath, std::ios::in | std::ios::binary);
    if (!file) {
        throw ParsingError(error::open_file_error);
    }

    FileHeader file_header = FileHeader::read(file);
    if (!file_header.is_valid()) {
        throw ParsingError(error::read_header_error);
    }
    if (!file) {
        throw ParsingError(error::file_offset_error);
    }

    InfoHeader info = InfoHeader::read(file);
    if (!info.is_valid()) {
        throw ParsingError(error::read_header_error);
    }
    if (!file) {
        throw ParsingError(error::file_offset_error);
    }

    file.seekg(file_header.pixel_array_offset, std::ios::beg);
    if (!file) {
        throw ParsingError(error::file_offset_error);
    }

    std::vector<Color> data = read_data(file, info);
    if (data.empty()) {
        throw ParsingError(error::read_data_error);
    }

    if (!info.bottom_up()) {
        data = flip_vertically(info, data);
    }

    return make_image_info(info, std::move(data));
}

bool is_bmp(const std::filesystem::path& filepath)
{
    std::ifstream file(filepath, std::ios::in | std::ios::binary);
    if (!file) {
        return false;
    }

    FileHeader header = FileHeader::read(file);
    return header.is_valid();
}

} // namespace framework::graphics::details::image::bmp
