#ifndef GRAPHICS_SRC_IMAGE_IMAGE_INFO_HPP
#define GRAPHICS_SRC_IMAGE_IMAGE_INFO_HPP

#include <vector>

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
    std::size_t width  = 0;
    std::size_t height = 0;

    float gamma = default_gamma;

    std::vector<Color> data;
};

} // namespace framework::graphics::details::image

#endif
