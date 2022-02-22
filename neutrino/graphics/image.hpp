#ifndef FRAMEWORK_GRAPHICS_IMAGE_HPP
#define FRAMEWORK_GRAPHICS_IMAGE_HPP

#include <filesystem>
#include <tuple>
#include <vector>

#include <graphics/color.hpp>

namespace framework::graphics
{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @addtogroup graphics_image_module
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Image class.
///
/// Image can be loaded from a file or created with color data.
/// Data stored as Color values in a row from left to right.
/// Rows stored from bottom to top, so the image is upside down.
///
/// @code
/// Image img;
/// if (!img.load(file)) {
///     throw std::runtime_error(std::string("Can't load image: ") + file);
/// }
/// @endcode
class Image
{
public:
    /// @brief Supported image types.
    enum class FileType
    {
        bmp,
        png,
    };

    /// @brief Type of data container
    using DataType = std::vector<Color>;

    /// @brief Result of loading operation.
    using LoadResult = std::tuple<bool, std::string>;

    Image();

    /// @brief Creates image with Color data.
    ///
    /// @param data Image color data.
    /// @param width Image width.
    /// @param height Inage height.
    Image(const DataType& data, int width, int height);

    Image(const Image&)     = default;
    Image(Image&&) noexcept = default;

    Image& operator=(const Image&) = default;
    Image& operator=(Image&&) noexcept = default;

    /// @brief Load image from file.
    ///
    /// FileType detected automatically.
    ///
    /// @param file File to load.
    ///
    /// @return `LoadResult<true, "">` if load successful or
    ///         `LoadResult<false, "error description">` otherwise.
    LoadResult load(const std::filesystem::path& file);

    /// @brief Load image from file.
    ///
    /// @param file File to load.
    /// @param type Image Ffle type.
    ///
    /// @return `LoadResult<true, "">` if load successful or
    ///         `LoadResult<false, "error description">` otherwise.
    LoadResult load(const std::filesystem::path& file, FileType type);

    /// @brief Get image width.
    ///
    /// @return Image width.
    int width() const;

    /// @brief Get image height.
    ///
    /// @return Image height.
    int height() const;

    /// @brief Get image gamma.
    ///
    /// @return Image gamma.
    float gamma() const;

    /// @brief Get image color data.
    ///
    /// @return Pointer to the first pixel.
    const Color* data() const;

private:
    static constexpr float default_gamma = 2.2f;

    friend void swap(Image& lhs, Image& rhs) noexcept;

    DataType m_data;

    int m_width  = 0;
    int m_height = 0;

    float m_gamma = default_gamma;
};

////////////////////////////////////////////////////////////////////////////////
/// @brief Swaps two Images.
///
/// @param lhs Image to swap.
/// @param rhs Image to swap.
////////////////////////////////////////////////////////////////////////////////
void swap(Image& lhs, Image& rhs) noexcept;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

} // namespace framework::graphics

#endif
