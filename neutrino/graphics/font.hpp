#ifndef FRAMEWORK_GRAPHICS_FONT_HPP
#define FRAMEWORK_GRAPHICS_FONT_HPP

#include <filesystem>
#include <string>

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
        Success,            ///< Succes loading
        FileNotExists,      ///< Can't find file
        OpenFileError,      ///< Can't open file for reading
        InvalidOffsetTable, ///< Can't read information about tables
        FileStructureError, ///< File is invalid
        TableReadError,     ///< Can't read data from file or data is invalid
        TableParsingError,  ///< Table data is corrupted
        Unsupported,        ///< Unsupported version of table or data
        UnknownError,       ///< Unknown error
    };

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Load font from file.
    ///
    /// @param filepath File to load.
    ///
    /// @return LoadResult::Success if loading is successful
    ///         or error code otherwise.
    ////////////////////////////////////////////////////////////////////////////
    LoadResult load(const std::filesystem::path& filepath);

private:
    LoadResult parse(const std::filesystem::path& filepath);
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

} // namespace framework::graphics

#endif
