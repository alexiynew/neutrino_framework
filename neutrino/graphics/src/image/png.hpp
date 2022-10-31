#ifndef GRAPHICS_SRC_IMAGE_PNG_HPP
#define GRAPHICS_SRC_IMAGE_PNG_HPP

#include <filesystem>

#include <graphics/src/image/image_info.hpp>

namespace neutrino::graphics::details::image::png
{
ImageInfo load(const std::filesystem::path& filepath);

bool is_png(const std::filesystem::path& filepath);

} // namespace neutrino::graphics::details::image::png

#endif
