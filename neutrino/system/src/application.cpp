#include <system/application.hpp>

namespace neutrino::system
{

std::mutex Application::m_data_mutex;

void Application::set_name(const std::string& name)
{
    std::scoped_lock lock(m_data_mutex);
    instance().m_name = name;
}

const std::string& Application::name()
{
    std::scoped_lock lock(m_data_mutex);
    return instance().m_name;
}

Application& Application::instance()
{
    static Application app;
    return app;
}

} // namespace neutrino::system
