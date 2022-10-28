#ifndef SYSTEM_SRC_OSX_OSX_CONTEXT_HPP
#define SYSTEM_SRC_OSX_OSX_CONTEXT_HPP

#include <system/context.hpp>

#import <AppKit/AppKit.h>

namespace framework::system::details
{
class OsxContext : public Context
{
public:
    OsxContext(NSView* view, const ContextSettings& settings);
    ~OsxContext() override;

    OsxContext(const OsxContext&) = default;
    OsxContext(OsxContext&&)      = default;

    OsxContext& operator=(const OsxContext&) noexcept = default;
    OsxContext& operator=(OsxContext&&) noexcept      = default;

    bool is_valid() const override;
    bool is_current() const override;
    Api api_type() const override;

    void make_current() override;
    void swap_buffers() override;

    void update();

private:
    using VoidFunctionPtr = void (*)();

    VoidFunctionPtr get_function(const char* function_name) const;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
    NSView* m_view             = nullptr;
    NSOpenGLContext* m_context = nullptr;
#pragma clang diagnostic pop
};

} // namespace framework::system::details

#endif
