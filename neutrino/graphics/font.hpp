#ifndef FRAMEWORK_GRAPHICS_FONT_HPP
#define FRAMEWORK_GRAPHICS_FONT_HPP

#include <filesystem>
#include <string>
#include <unordered_map>
#include <vector>

#include <common/instance_id.hpp>
#include <common/utf.hpp>

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

    Font();
    Font(const Font& other);
    Font(Font&& other) noexcept;

    ~Font();

    Font& operator=(const Font& other);
    Font& operator=(Font&& other) noexcept;

    /// @brief Load font from file.
    ///
    /// @param filepath File to load.
    ///
    /// @return LoadResult::Success if loading is successful
    ///         or error code otherwise.
    LoadResult load(const std::filesystem::path& filepath);

    /// @brief Chache texture and mesh for selected characters in renderer.
    ///
    /// Font data must be loaded before characters can be cached.
    ///
    /// @param chars String to cache characters from.
    ///
    /// @see load
    void precache(const std::string& chars);

    /// @brief Get Font instance id. Guaranted to be unique.
    ///
    /// @return Font instance id.
    InstanceId instance_id() const;

private:
    class FontData;

    friend void swap(Font& lhs, Font& rhs) noexcept;

    LoadResult parse(const std::filesystem::path& filepath);

    InstanceId m_instance_id;
    std::unique_ptr<FontData> m_data;
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
