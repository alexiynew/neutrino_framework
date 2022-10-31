#ifndef GRAPHICS_SRC_IMAGE_BMP_HPP
#define GRAPHICS_SRC_IMAGE_BMP_HPP

#include <filesystem>

#include <graphics/src/image/image_info.hpp>

namespace neutrino::graphics::details::image::bmp
{
ImageInfo load(const std::filesystem::path& filepath);

bool is_bmp(const std::filesystem::path& filepath);

} // namespace neutrino::graphics::details::image::bmp

#endif
