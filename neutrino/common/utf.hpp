#ifndef FRAMEWORK_COMMON_UTF_HPP
#define FRAMEWORK_COMMON_UTF_HPP

#include <cstdint>
#include <string>

namespace framework::utf
{

using CodePoint = std::uint32_t;

std::string to_utf8(const std::u16string& str);
std::string to_utf8(const std::u32string& str);

} // namespace framework::utf

#endif
