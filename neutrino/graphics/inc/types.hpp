
#ifndef GRAPHICS_TYPES_HPP
#define GRAPHICS_TYPES_HPP

#include <unordered_map>
#include <vector>

#include <graphics/uniform.hpp>

namespace neutrino::graphics
{

using UniformsList = std::vector<Uniform>;
using UniformsMap  = std::unordered_map<std::string, Uniform>;
using ResourceId   = std::uint32_t;

} // namespace neutrino::graphics

#endif
