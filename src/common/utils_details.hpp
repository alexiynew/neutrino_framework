/// @file
/// @brief Implementation details of utils functions
/// @author Fedorov Alexey
/// @date 11.07.2018

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

#ifndef FRAMEWORK_COMMON_UTILS_DETAILS_HPP
#define FRAMEWORK_COMMON_UTILS_DETAILS_HPP

#include <iostream>
#include <memory>
#include <random>

namespace framework::utils::details
{
template <typename T>
auto get_distribution(T min_value, T max_value)
{
    if constexpr (std::is_integral<T>::value == true) {
        return std::uniform_int_distribution<T>(min_value, max_value);
    } else {
        return std::uniform_real_distribution<T>(min_value, max_value);
    }
}

/*
namespace format_details
{
struct value_base
{
    virtual ~value_base()                         = default;
    virtual void print_to(std::ostream& os) const = 0;
};

template <typename T>
struct value_holder : public value_base
{
    value_holder(const T& v) : value(v)
    {}
    void print_to(std::ostream& os) const override
    {
        os << value;
    }
    const T& value;
};

template <typename T>
inline std::unique_ptr<value_base> make_value_holder_ptr(const T& t)
{
    return std::unique_ptr<value_base>(new value_holder<T>(t));
}

std::string make_string_impl(const std::string& str,
                             const std::unique_ptr<value_base>* const values,
                             const size_t values_count);

} // namespace format_details

*/
} // namespace framework::utils::details

#endif
