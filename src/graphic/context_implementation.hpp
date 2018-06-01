/// @file
/// @brief Graphic context implementation.
/// @author Fedorov Alexey
/// @date 29.06.2018

#ifndef FRAMEWORK_GRAPHIC_CONTEXT_IMPLEMENTATION_HPP
#define FRAMEWORK_GRAPHIC_CONTEXT_IMPLEMENTATION_HPP

#include <memory>

#include <graphic/context.hpp>

namespace framework {

namespace graphic {

class context::implementation
{
public:
    static std::unique_ptr<implementation> create();

    implementation()          = default;
    virtual ~implementation() = default;

    implementation(const implementation&) = delete;
    implementation& operator=(const implementation&) = delete;

    virtual void make_current() = 0;
    virtual void swap_buffers() = 0;
};

} // namespace graphic

} // namespace framework

#endif
