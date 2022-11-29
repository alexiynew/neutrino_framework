#ifndef GRAPHICS_FONT_HPP
#define GRAPHICS_FONT_HPP

#include <filesystem>
#include <string>
#include <unordered_map>
#include <vector>

#include <common/global_defines.hpp>
#include <common/utf.hpp>
#include <graphics/color.hpp>
#include <graphics/mesh.hpp>

namespace neutrino::graphics
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
    LIBRARY_API explicit Font(QualityType quality = 1);

    LIBRARY_API Font(const Font& other);
    LIBRARY_API Font(Font&& other) noexcept;

    LIBRARY_API ~Font();

    LIBRARY_API Font& operator=(const Font& other);
    LIBRARY_API Font& operator=(Font&& other) noexcept;

    /// @brief Load font from file.
    ///
    /// @param filepath File to load.
    ///
    /// @return LoadResult::Success if loading is successful or error code otherwise.
    LIBRARY_API LoadResult load(const std::filesystem::path& filepath);

    LIBRARY_API Mesh create_text_mesh(const std::string& text);

private:
    class FontData;

    LIBRARY_API friend void swap(Font& lhs, Font& rhs) noexcept;

    LoadResult parse(const std::filesystem::path& filepath);

    void precache(const std::string& chars);

    std::unique_ptr<FontData> m_data;
    QualityType m_quality = 1;
};

/// @brief Swaps two Fonts.
///
/// @param lhs Font to swap.
/// @param rhs Font to swap.
LIBRARY_API void swap(Font& lhs, Font& rhs) noexcept;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

} // namespace neutrino::graphics

#endif
