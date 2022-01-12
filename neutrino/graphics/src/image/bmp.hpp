#ifndef FRAMEWORK_GRAPHICS_SRC_IMAGE_BMP_HPP
#define FRAMEWORK_GRAPHICS_SRC_IMAGE_BMP_HPP

#include <filesystem>

#include <graphics/src/image/image_info.hpp>

namespace framework::graphics::details::image::bmp
{
LoadResult load(const std::filesystem::path& filepath);

bool is_bmp(const std::filesystem::path& filepath);

} // namespace framework::graphics::details::image::bmp

#endif
