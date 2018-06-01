/// @file
/// @brief Graphic context.
/// @author Fedorov Alexey
/// @date 29.06.2018

#ifndef FRAMEWORK_GRAPHIC_CONTEXT_HPP
#define FRAMEWORK_GRAPHIC_CONTEXT_HPP

#include <memory>

namespace framework {

namespace graphic {

class context
{
public:
    class implementation;

    context();

    ~context();

    void make_current();
    void swap_buffers();

private:
    std::unique_ptr<implementation> m_implementation;
};

} // namespace graphic

} // namespace framework

#endif
