#ifndef SYSTEM_APPLICATION_HPP
#define SYSTEM_APPLICATION_HPP

#include <mutex>
#include <string>

#include <common/global_defines.hpp>

namespace neutrino::system
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @addtogroup system_application_class
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Application class.
///
/// Singleton class with global application specific parameters.
class Application
{
public:
    /// @brief Sets the formal name of the application.
    ///
    /// @param name Application name.
    LIBRARY_API static void set_name(const std::string& name);

    /// @brief The formal name of the application.
    ///
    /// Used in window creation to name window class on some OS.
    ///
    /// @return Application name.
    LIBRARY_API static const std::string& name();

    Application(const Application&)            = delete;
    Application& operator=(const Application&) = delete;

private:
    static Application& instance();

    Application()  = default;
    ~Application() = default;

    static std::mutex m_data_mutex;

    std::string m_name = "Neutrino application"; ///< Default application name.
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

} // namespace neutrino::system

#endif
