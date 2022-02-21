#ifndef FRAMEWORK_GRAPHICS_FONT_HPP
#define FRAMEWORK_GRAPHICS_FONT_HPP

#include <string>
#include <unordered_map>

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
    /// @brief Load font from file.
    ///
    /// @param filename Font to load.
    ///
    /// @return `true` if file loaded successfully.
    bool load(const std::string& filename);

private:
    bool parse(const std::string& filename);
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

} // namespace framework::graphics

#endif
