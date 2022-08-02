#ifndef SYSTEM_CONTEXT_HPP
#define SYSTEM_CONTEXT_HPP

#include <memory>

#include <system/context_settings.hpp>

namespace framework::system
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @addtogroup system_graphic_context
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Graphic context.
class Context
{
public:
    /// @brief Supported graphic api.
    enum class Api
    {
        opengl,
    };

    using VoidFunctionPtr = void (*)();

    /// @brief Creates context with provided ContextSettings.
    explicit Context(ContextSettings settings) noexcept;

    Context(const Context&) = default;
    Context(Context&&)      = default;

    Context& operator=(const Context&) noexcept = default;
    Context& operator=(Context&&) noexcept = default;

    virtual ~Context();

    /// @brief Checks if a context is created properly.
    ///
    /// @return `True` if context can be used.
    virtual bool valid() const = 0;

    /// @brief Checks if a context is current for rendering.
    ///
    /// @return `True` if a context is set up for rendering.
    virtual bool is_current() const = 0;

    /// @brief Graphic API supported by this context.
    ///
    /// @return Supported API.
    virtual Api api_type() const = 0;

    /// @brief Returns OS specific functon pointer by name.
    ///
    /// @param function_name Function to get.
    ///
    /// @return Addres of OS function.
    virtual VoidFunctionPtr get_function(const char* function_name) const = 0;

    /// @brief Set a context as current for rendering.
    virtual void make_current() = 0;

    /// @brief Shows on-screen what has been rendered so far.
    virtual void swap_buffers() = 0;

    /// @brief Current context settings.
    ///
    /// @return Current context settings.
    const ContextSettings& settings() const;

protected:
    void update_settings(const ContextSettings& settings);

private:
    ContextSettings m_settings;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

} // namespace framework::system

#endif
