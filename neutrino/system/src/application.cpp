#include <system/application.hpp>

namespace framework::system
{

void Application::set_name(const std::string& name)
{
    instance().m_name = name;
}

const std::string& Application::name()
{
    return instance().m_name;
}

/// TODO: make threadsafe
Application& Application::instance()
{
    static Application app;
    return app;
}

} // namespace framework::system
