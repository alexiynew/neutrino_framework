#ifndef GAME_CORE_FPS_COUNTER_HPP
#define GAME_CORE_FPS_COUNTER_HPP

#include <atomic>
#include <thread>

#include <common/global_defines.hpp>

namespace neutrino
{
////////////////////////////////////////////////////////////////////////////////
/// @addtogroup utils_utils_module
/// @{
////////////////////////////////////////////////////////////////////////////////

/// @brief Fps counter
class FpsCounter final
{
public:
    LIBRARY_API FpsCounter();
    LIBRARY_API ~FpsCounter();

    FpsCounter(const FpsCounter&)            = delete;
    FpsCounter& operator=(const FpsCounter&) = delete;

    /// @brief Count a frame.
    ///
    /// Should be called once per frame.
    LIBRARY_API void tick();

    /// @brief Frames per second.
    ///
    /// @return Frames count.
    LIBRARY_API std::uint32_t fps() const;

    /// @brief Total frames count.
    ///
    /// @return Total frames count.
    LIBRARY_API std::uint32_t total_fames() const;

private:
    void slice_fps();

    std::atomic<bool> m_should_stop           = false;
    std::atomic<std::uint32_t> m_frames_total = 0;
    std::atomic<std::uint32_t> m_frames       = 0;
    std::atomic<std::uint32_t> m_fps          = 0;
    std::thread m_fps_thread;
};

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

} // namespace neutrino

#endif
