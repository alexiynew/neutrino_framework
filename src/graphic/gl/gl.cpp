/// @file
/// @brief OpneGL functions wrapper.
/// @author Fedorov Alexey
/// @date 21.06.2018

#include <graphic/gl/gl.hpp>

namespace framework
{
namespace graphic
{
namespace gl
{
bool init()
{
    return init_core(); // && init_extensions();
}

} // namespace gl

} // namespace graphic

} // namespace framework
