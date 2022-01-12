#ifndef FRAMEWORK_GRAPHICS_SRC_IMAGE_IMAGE_INFO_HPP
#define FRAMEWORK_GRAPHICS_SRC_IMAGE_IMAGE_INFO_HPP

#include <optional>
#include <tuple>
#include <variant>
#include <vector>

#include <common/types.hpp>
#include <graphics/color.hpp>

namespace framework::graphics::details::image
{
constexpr float default_gamma = 2.2f;

namespace error
{
inline constexpr char invalid_file_type[]      = "Invalid file type.";
inline constexpr char invalid_file_signature[] = "Invalid file signature.";
inline constexpr char open_file_error[]        = "Can't open file.";
inline constexpr char file_offset_error[]      = "File offset error.";
inline constexpr char read_header_error[]      = "Can't read image header.";
inline constexpr char read_data_error[]        = "Can't read image data.";
inline constexpr char unknown_error[]          = "Unknown error.";
} // namespace error

struct ImageInfo
{
    int32 width  = 0;
    int32 height = 0;

    float gamma = default_gamma;

    std::vector<Color> data;
};

using ErrorDescription = std::string;
using LoadResult       = std::variant<ImageInfo, ErrorDescription>;

} // namespace framework::graphics::details::image

#endif
