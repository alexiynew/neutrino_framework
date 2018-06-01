/// @file
/// @brief Graphic context.
/// @author Fedorov Alexey
/// @date 29.06.2018

#include <graphic/context.hpp>
#include <graphic/context_implementation.hpp>

namespace framework {

namespace graphic {

context::context() : m_implementation(implementation::create())
{}

context::~context() = default;

void context::make_current()
{
    m_implementation->make_current();
}

void context::swap_buffers()
{
    m_implementation->swap_buffers();
}

} // namespace graphic

} // namespace framework
