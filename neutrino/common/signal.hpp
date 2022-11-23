#ifndef COMMON_SIGNAL_HPP
#define COMMON_SIGNAL_HPP

#include <algorithm>
#include <functional>
#include <memory>
#include <vector>

namespace neutrino
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @addtogroup utils_types_module
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Signal - Slot comunication
///
/// Signals emits when some system wants to notify any other system about some
/// events. Slots can be connected to a Signal to react to signal emission.
template <typename... Args>
class Signal
{
public:
    using Slot   = std::function<void(Args...)>;
    using SlotId = std::size_t;

    Signal() = default;

    Signal(const Signal&) = delete;
    Signal(Signal&&)      = default;

    Signal& operator=(const Signal&) = delete;
    Signal& operator=(Signal&&)      = default;

    /// @brief Connect function to signal
    ///
    /// @param slot Function to react to signal
    ///
    /// @return Id of connection
    SlotId connect(Slot&& slot);

    /// @brief Connect member function to signal
    ///
    /// @param inst Object instance
    /// @param func Member function
    ///
    /// @return Id of connection
    template <typename T>
    SlotId connect(T& inst, void (T::*func)(Args...));

    /// @brief Connect const member function to signal
    ///
    /// @param inst Object instance
    /// @param func Member function
    ///
    /// @return Id of connection
    template <typename T>
    SlotId connect(const T& inst, void (T::*func)(Args...) const);

    /// @brief Remove slot connection by SlotId
    ///
    /// @param id Connection to remove
    void disconnect(SlotId id);

    /// @brief Remove all connection from signal
    void clear();

    /// @brief Check if signal has connections
    ///
    /// @return `true` if some Slot connected to the Signal
    bool has_connections() const;

    /// @brief Emit signal
    ///
    /// @param args Any parameters to Slot.
    void operator()(Args... args);

    /// @brief Emit signal
    ///
    /// @param args Any parameters to Slot.
    void operator()(Args... args) const;

private:
    std::vector<std::shared_ptr<Slot>> m_slots;
    std::vector<SlotId> m_free_ids;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename... Args>
inline typename Signal<Args...>::SlotId Signal<Args...>::connect(typename Signal<Args...>::Slot&& slot)
{
    if (m_free_ids.empty()) {
        m_slots.push_back(std::make_shared<Slot>(std::move(slot)));
        return m_slots.size() - 1;
    } else {
        SlotId id = m_free_ids.back();
        m_free_ids.pop_back();
        m_slots[id] = std::make_shared<Slot>(std::move(slot));
        return id;
    }
}

template <typename... Args>
template <typename T>
inline typename Signal<Args...>::SlotId Signal<Args...>::connect(T& inst, void (T::*func)(Args...))
{
    if constexpr (sizeof...(Args) == 0) {
        return connect([&inst, func]() { (inst.*func)(); });
    } else {
        return connect([&inst, func](Args... args) { (inst.*func)(std::forward<Args>(args)...); });
    }
}

template <typename... Args>
template <typename T>
inline typename Signal<Args...>::SlotId Signal<Args...>::connect(const T& inst, void (T::*func)(Args...) const)
{
    if constexpr (sizeof...(Args) == 0) {
        return connect([&inst, func]() { (inst.*func)(); });
    } else {
        return connect([&inst, func](Args... args) { (inst.*func)(std::forward<Args>(args)...); });
    }
}

template <typename... Args>
inline void Signal<Args...>::disconnect(typename Signal<Args...>::SlotId id)
{
    if (id < m_slots.size()) {
        m_slots[id] = nullptr;
        m_free_ids.push_back(id);
    }
}

template <typename... Args>
inline void Signal<Args...>::clear()
{
    m_slots.clear();
    m_free_ids.clear();
}

template <typename... Args>
inline bool Signal<Args...>::has_connections() const
{
    if (m_slots.empty()) {
        return false;
    }

    auto it = std::find_if(m_slots.begin(), m_slots.end(), [](const std::shared_ptr<Slot>& slot) {
        return slot != nullptr;
    });
    return it != m_slots.end();
}

template <typename... Args>
inline void Signal<Args...>::operator()(Args... args)
{
    for (std::size_t index = 0; index < m_slots.size(); ++index) {
        if (m_slots[index] == nullptr) {
            continue;
        }

        std::shared_ptr<Slot> slot = m_slots[index];
        if constexpr (sizeof...(Args) == 0) {
            (*slot)();
        } else {
            (*slot)(std::forward<Args>(args)...);
        }
    }
}

template <typename... Args>
inline void Signal<Args...>::operator()(Args... args) const
{
    for (std::size_t index = 0; index < m_slots.size(); ++index) {
        if (m_slots[index] == nullptr) {
            continue;
        }

        std::shared_ptr<Slot> slot = m_slots[index];
        if constexpr (sizeof...(Args) == 0) {
            (*slot)();
        } else {
            (*slot)(std::forward<Args>(args)...);
        }
    }
}

} // namespace neutrino

#endif
