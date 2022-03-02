#ifndef FRAMEWORK_COMMON_UTF_HPP
#define FRAMEWORK_COMMON_UTF_HPP

#include <cstdint>
#include <string>
#include <vector>

namespace framework::utf
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @addtogroup utils_utf_implementation
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using CodePoint = std::uint32_t;

std::string to_utf8(const std::u16string& str);
std::string to_utf8(const std::u32string& str);

std::u16string to_utf16(const std::string& str);
std::u16string to_utf16(const std::u32string& str);

std::u32string to_utf32(const std::string& str);
std::u32string to_utf32(const std::u16string& str);

std::vector<CodePoint> to_codepoints(const std::string& str);
std::vector<CodePoint> to_codepoints(const std::u16string& str);
std::vector<CodePoint> to_codepoints(const std::u32string& str);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

} // namespace framework::utf

#endif
