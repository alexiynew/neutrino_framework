#ifndef GRAPHICS_FONT_HPP
#define GRAPHICS_FONT_HPP

#include <filesystem>
#include <string>
#include <unordered_map>
#include <vector>

#include <common/utf.hpp>
#include <graphics/mesh.hpp>

namespace framework::graphics
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @addtogroup graphics_font_module
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Font rendering
class Font
{
public:
    /// @brief Result of loading operation.
    enum class LoadResult
    {
        Success,            ///< Success loading
        FileNotExists,      ///< Can't find file
        OpenFileError,      ///< Can't open file for reading
        InvalidOffsetTable, ///< Can't read information about tables
        FileStructureError, ///< File is invalid
        TableReadError,     ///< Can't read data from file or data is invalid
        TableParsingError,  ///< Table data is corrupted
        Unsupported,        ///< Unsupported version of table or data
        UnknownError,       ///< Unknown error
    };

    /// @brief Represents font mesh qualyty. I.e. amount of points on a curves to make it look more smooth.
    using QualityType = std::size_t;

    /// @brief Creates font
    ///
    /// The quality value defines how many additional points on glyphs outline to generate for one bezier curve.
    /// Lager value results smoothed contours, but more complicated mesh would be generated.
    /// Value from 1 to 3 is good enough for many cases. Max quality is clumped to 32 points.
    ///
    /// @param quality Mesh quality.
    explicit Font(QualityType quality = 1);

    Font(const Font& other);
    Font(Font&& other) noexcept;

    ~Font();

    Font& operator=(const Font& other);
    Font& operator=(Font&& other) noexcept;

    /// @brief Load font from file.
    ///
    /// @param filepath File to load.
    ///
    /// @return LoadResult::Success if loading is successful or error code otherwise.
    LoadResult load(const std::filesystem::path& filepath);

    Mesh create_text_mesh(const std::string& text);

private:
    class FontData;

    friend void swap(Font& lhs, Font& rhs) noexcept;

    LoadResult parse(const std::filesystem::path& filepath);

    void precache(const std::string& chars);

    std::unique_ptr<FontData> m_data;
    QualityType m_quality = 1;
};

/// @brief Swaps two Fonts.
///
/// @param lhs Font to swap.
/// @param rhs Font to swap.
void swap(Font& lhs, Font& rhs) noexcept;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

} // namespace framework::graphics

#endif
