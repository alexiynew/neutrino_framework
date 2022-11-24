#ifndef COMMON_UTF_HPP
#define COMMON_UTF_HPP

#include <cstdint>
#include <string>
#include <vector>

#include <common/global_defines.hpp>

namespace neutrino::utf
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @addtogroup utils_utf_implementation
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Unicode code point
using CodePoint = std::uint32_t;

/// @brief Converts string to utf8 string without BOM.
///
/// @param str String to convert.
///
/// @return The utf8 string.
LIBRARY_API std::string to_utf8(const std::u16string& str);

/// @brief Converts string to utf8 string without BOM.
///
/// @param str String to convert.
///
/// @return The utf8 string.
LIBRARY_API std::string to_utf8(const std::u32string& str);

/// @brief Converts wide characters string to utf8 string without BOM.
///
/// @param str String to convert.
///
/// @return The utf8 string.
LIBRARY_API std::string to_utf8(const std::wstring& str);

/// @brief Converts string to utf16 string without BOM.
///
/// @param str String to convert.
///
/// @return The utf16 string.
LIBRARY_API std::u16string to_utf16(const std::string& str);

/// @brief Converts string to utf16 string without BOM.
///
/// @param str String to convert.
///
/// @return The utf16 string.
LIBRARY_API std::u16string to_utf16(const std::u32string& str);

/// @brief Converts wide characters string to utf16 string without BOM.
///
/// @param str String to convert.
///
/// @return The utf16 string.
LIBRARY_API std::u16string to_utf16(const std::wstring& str);

/// @brief Converts string to utf32 string.
///
/// @param str String to convert.
///
/// @return The utf32 string.
LIBRARY_API std::u32string to_utf32(const std::string& str);

/// @brief Converts string to utf32 string.
///
/// @param str String to convert.
///
/// @return The utf32 string.
LIBRARY_API std::u32string to_utf32(const std::u16string& str);

/// @brief Converts wide charaters string to utf32 string.
///
/// @param str String to convert.
///
/// @return The utf32 string.
LIBRARY_API std::u32string to_utf32(const std::wstring& str);

/// @brief Converts string to wide string
///
/// @param str String to convert.
///
/// @return The wide characters string.
LIBRARY_API std::wstring to_wstring(const std::string& str);

/// @brief Converts string to wide string
///
/// @param str String to convert.
///
/// @return The wide characters string.
LIBRARY_API std::wstring to_wstring(const std::u16string& str);

/// @brief Converts string to wide string
///
/// @param str String to convert.
///
/// @return The wide characters string.
LIBRARY_API std::wstring to_wstring(const std::u32string& str);

/// @brief Converts string to a sequence of Unicode code points.
///
/// @param str String to convert.
///
/// @return Vector of code points.
LIBRARY_API std::vector<CodePoint> to_codepoints(const std::string& str);

/// @brief Converts string to a sequence of Unicode code points.
///
/// @param str String to convert.
///
/// @return Vector of code points.
LIBRARY_API std::vector<CodePoint> to_codepoints(const std::u16string& str);

/// @brief Converts string to a sequence of Unicode code points.
///
/// @param str String to convert.
///
/// @return Vector of code points.
LIBRARY_API std::vector<CodePoint> to_codepoints(const std::u32string& str);

/// @brief Converts wide charactres string to a sequence of Unicode code points.
///
/// @param str String to convert.
///
/// @return Vector of code points.
LIBRARY_API std::vector<CodePoint> to_codepoints(const std::wstring& str);

/// @brief Hack to support poorly added char8_t (cpp20).
///
/// @param buf UTF8 char to convert.
///
/// @return Normal std::string.
inline std::string to_string(const char8_t* buf)
{
    return std::string(reinterpret_cast<const char*>(buf));
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

} // namespace neutrino::utf

#endif
