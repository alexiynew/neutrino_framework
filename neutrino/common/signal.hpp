/// @file
/// @brief Different helper functions
/// @author Fedorov Alexey
/// @date 03.03.2020

// =============================================================================
// MIT License
//
// Copyright (c) 2017-2019 Fedorov Alexey
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// =============================================================================

#ifndef FRAMEWORK_COMMON_SIGNAL_HPP
#define FRAMEWORK_COMMON_SIGNAL_HPP

#include <common/types.hpp>

#include <unordered_map>
#include <functional>
#include <algorithm>

namespace framework
{
    template <typename... Args>
    class Signal
    {
    public:
        using Slot = std::function<void(Args...)>;
        using SlotId = int32;

        Signal() = default;

        Signal(const Signal&) = delete;
        Signal& operator=(const Signal&) = delete;

        Signal(Signal&&) = default;
        Signal& operator=(Signal&&) = default;

        SlotId connect(Slot&& slot)
        {
            const auto& [id, result] = m_slots.emplace(m_current_index, std::move(slot));
            m_current_index++;
            return id->first;
        }

        template<typename T>
        SlotId connect(T &inst, void (T::*func)(Args...))
        {
            if constexpr (sizeof...(Args) == 0) {
                return connect([&inst, func]() { (inst.*func)(); });
            } else {
                return connect([&inst, func](Args... args) { (inst.*func)(std::forward<Args...>(args...)); });
            }
        }

        template<typename T>
        SlotId connect(T &inst, void (T::*func)(Args...) const)
        {
            if constexpr (sizeof...(Args) == 0) {
                return connect([&inst, func]() { (inst.*func)(); });
            } else {
                return connect([&inst, func](Args... args) { (inst.*func)(std::forward<Args...>(args...)); });
            }
        }

        void disconnect(SlotId id)
        {
            m_slots.erase(id);
        }

        void clear()
        {
            m_slots.clear();
        }

        void operator()(Args&&... args)
        {
            for (const auto&[id, slot] : m_slots)
            {
                if constexpr (sizeof...(Args) == 0) {
                    slot();
                } else {
                    slot(std::forward<Args...>(args...));
                }
            }
        }

    private:
        std::unordered_map<SlotId, Slot> m_slots;
        int32 m_current_index = 0;
    };
}

#endif
