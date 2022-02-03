#include <utility>

#include <system/context.hpp>

namespace framework::system
{
Context::Context(ContextSettings settings) noexcept
    : m_settings(std::move(settings))
{}

Context::~Context() = default;

const ContextSettings& Context::settings() const
{
    return m_settings;
}

void Context::update_settings(const ContextSettings& settings)
{
    m_settings = settings;
}

} // namespace framework::system
