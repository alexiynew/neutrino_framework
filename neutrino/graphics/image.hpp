#ifndef FRAMEWORK_GRAPHICS_IMAGE_HPP
#define FRAMEWORK_GRAPHICS_IMAGE_HPP

#include <filesystem>
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

    /// @brief Result of loading operation.
    enum class LoadResult
    {
        Success,          ///< Success loading
        FileNotExists,    ///< Can't find file
        OpenFileError,    ///< Can't open file for reading
        InvalidFileType,  ///< File type is unknown or not supported
        DataParsingError, ///< Can't parse image data
        Unsupported,      ///< Unsupported version of table or data
        UnknownError,     ///< Unknown error
    };

    Image();

    /// @brief Creates image with Color data.
    ///
    /// @param data Image color data.
    /// @param width Image width.
    /// @param height Inage height.
    Image(const std::vector<Color>& data, std::size_t width, std::size_t height);

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
    /// @return LoadResult::Success if loading is successful or error code otherwise.
    LoadResult load(const std::filesystem::path& file);

    /// @brief Get image width.
    ///
    /// @return Image width.
    std::size_t width() const;

    /// @brief Get image height.
    ///
    /// @return Image height.
    std::size_t height() const;

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

    std::vector<Color> m_data;

    std::size_t m_width  = 0;
    std::size_t m_height = 0;

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
