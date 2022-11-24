#ifndef GRAPHICS_IMAGE_HPP
#define GRAPHICS_IMAGE_HPP

#include <filesystem>
#include <vector>

#include <common/global_defines.hpp>
#include <graphics/color.hpp>

namespace neutrino::graphics
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

    using ColorDataType = std::vector<Color>;

    LIBRARY_API Image();

    /// @brief Creates image with Color data.
    ///
    /// @param data Image color data.
    /// @param width Image width.
    /// @param height Inage height.
    LIBRARY_API Image(const ColorDataType& data, std::size_t width, std::size_t height);

    Image(const Image&)     = default;
    Image(Image&&) noexcept = default;

    Image& operator=(const Image&)     = default;
    Image& operator=(Image&&) noexcept = default;

    /// @brief Load image from file.
    ///
    /// @param file File to load.
    ///
    /// @return LoadResult::Success if loading is successful or error code otherwise.
    LIBRARY_API LoadResult load(const std::filesystem::path& file);

    /// @brief Get image width.
    ///
    /// @return Image width.
    LIBRARY_API std::size_t width() const;

    /// @brief Get image height.
    ///
    /// @return Image height.
    LIBRARY_API std::size_t height() const;

    /// @brief Get image gamma.
    ///
    /// @return Image gamma.
    LIBRARY_API float gamma() const;

    /// @brief Get image color data.
    ///
    /// @return Const reference to data storage.
    LIBRARY_API const ColorDataType& data() const;

    /// @brief Get image color data.
    ///
    /// @return reference to data storage.
    LIBRARY_API ColorDataType& data();

private:
    static constexpr float default_gamma = 2.2f;

    LIBRARY_API friend void swap(Image& lhs, Image& rhs) noexcept;

    ColorDataType m_data;

    std::size_t m_width  = 0;
    std::size_t m_height = 0;

    float m_gamma = default_gamma;
};

////////////////////////////////////////////////////////////////////////////////
/// @brief Equality operator for Images.
///
/// @param lhs Image to compate.
/// @param rhs Image to compare.
////////////////////////////////////////////////////////////////////////////////
LIBRARY_API bool operator==(const Image& lhs, const Image& rhs) noexcept;

////////////////////////////////////////////////////////////////////////////////
/// @brief Inequality operator for Images.
///
/// @param lhs Image to compate.
/// @param rhs Image to compare.
////////////////////////////////////////////////////////////////////////////////
LIBRARY_API bool operator!=(const Image& lhs, const Image& rhs) noexcept;

////////////////////////////////////////////////////////////////////////////////
/// @brief Swaps two Images.
///
/// @param lhs Image to swap.
/// @param rhs Image to swap.
////////////////////////////////////////////////////////////////////////////////
LIBRARY_API void swap(Image& lhs, Image& rhs) noexcept;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

} // namespace neutrino::graphics

#endif
