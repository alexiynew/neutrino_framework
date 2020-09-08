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

#ifndef FRAMEWORK_COMMON_INC_UTILS_DETAILS_HPP
#define FRAMEWORK_COMMON_INC_UTILS_DETAILS_HPP

#include <cstdint>
#include <istream>
#include <memory>

namespace framework::utils::details
{

#pragma region Random Numbers

template <typename T>
auto get_distribution(T min_value, T max_value)
{
    if constexpr (std::is_integral<T>::value == true) {
        return std::uniform_int_distribution<T>(min_value, max_value);
    } else {
        return std::uniform_real_distribution<T>(min_value, max_value);
    }
}

#pragma endregion

#pragma region Read Value Form

namespace members_count
{
struct Any
{
    template <typename T>
    operator T();
};

template <std::size_t I>
using AnyArg = Any;

template <typename T, typename... Args>
auto is_aggregate_constructible_impl(int) -> decltype(T{std::declval<Args>()...}, void(), std::true_type{});

template <typename T, typename... Args>
auto is_aggregate_constructible_impl(...) -> std::false_type;

template <typename T, typename... Args>
using is_aggregate_constructible = decltype(is_aggregate_constructible_impl<T, Args...>(0));

template <class T, size_t... I>
constexpr size_t members_count(const std::index_sequence<I...>&)
{
    if constexpr (is_aggregate_constructible<T, AnyArg<I>...>()) {
        return sizeof...(I);
    } else {
        return members_count<T>(std::make_index_sequence<sizeof...(I) - 1>());
    }
}

template <class T>
constexpr size_t members_count()
{
    return members_count<T>(std::make_index_sequence<sizeof(T) / sizeof(char)>());
}

} // namespace members_count

template <typename T, size_t N>
inline auto to_tuple_impl(const T& value) noexcept
{
    if constexpr (N == 1) {
        auto [e0] = value;
        return std::make_tuple(e0);
    } else if constexpr (N == 2) {
        auto [e0, e1] = value;
        return std::make_tuple(e0, e1);
    } else if constexpr (N == 3) {
        auto [e0, e1, e2] = value;
        return std::make_tuple(e0, e1, e2);
    } else if constexpr (N == 4) {
        auto [e0, e1, e2, e3] = value;
        return std::make_tuple(e0, e1, e2, e3);
    } else if constexpr (N == 5) {
        auto [e0, e1, e2, e3, e4] = value;
        return std::make_tuple(e0, e1, e2, e3, e4);
    } else if constexpr (N == 6) {
        auto [e0, e1, e2, e3, e4, e5] = value;
        return std::make_tuple(e0, e1, e2, e3, e4, e5);
    } else if constexpr (N == 7) {
        auto [e0, e1, e2, e3, e4, e5, e6] = value;
        return std::make_tuple(e0, e1, e2, e3, e4, e5, e6);
    } else if constexpr (N == 8) {
        auto [e0, e1, e2, e3, e4, e5, e6, e7] = value;
        return std::make_tuple(e0, e1, e2, e3, e4, e5, e6, e7);
    } else if constexpr (N == 9) {
        auto [e0, e1, e2, e3, e4, e5, e6, e7, e8] = value;
        return std::make_tuple(e0, e1, e2, e3, e4, e5, e6, e7, e8);
    } else if constexpr (N == 10) {
        auto [e0, e1, e2, e3, e4, e5, e6, e7, e8, e9] = value;
        return std::make_tuple(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9);
    } else if constexpr (N == 11) {
        auto [e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10] = value;
        return std::make_tuple(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10);
    } else if constexpr (N == 12) {
        auto [e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11] = value;
        return std::make_tuple(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11);
    } else if constexpr (N == 13) {
        auto [e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12] = value;
        return std::make_tuple(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12);
    } else if constexpr (N == 14) {
        auto [e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13] = value;
        return std::make_tuple(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13);
    } else if constexpr (N == 15) {
        auto [e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14] = value;
        return std::make_tuple(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14);
    } else if constexpr (N == 16) {
        auto [e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15] = value;
        return std::make_tuple(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15);
    } else if constexpr (N == 17) {
        auto [e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16] = value;
        return std::make_tuple(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16);
    } else if constexpr (N == 18) {
        auto [e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17] = value;
        return std::make_tuple(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17);
    } else {
        static_assert(false, "Need more structured binding options");
    }
}

template <typename T>
using TupleType = decltype(to_tuple_impl<T, members_count::members_count<T>()>(std::declval<T>()));

template <typename T>
inline TupleType<T> to_tuple(const T& value) noexcept
{
    return to_tuple_impl<T, members_count::members_count<T>()>(value);
}

template <typename T, typename Tuple, size_t... I>
inline T from_tuple_impl(const Tuple& tuple, const std::index_sequence<I...>&) noexcept
{
    using std::get;
    return T{get<I>(tuple)...};
}

template <typename T, typename Tuple>
inline T from_tuple(const Tuple& tuple) noexcept
{
    return from_tuple_impl<T>(tuple, std::make_index_sequence<std::tuple_size_v<Tuple>>());
}

struct BigEndianTag
{};

struct LittleEndianTag
{};

template <typename T>
using FundamentalOrEnumReturnType = std::enable_if_t<std::disjunction_v<std::is_fundamental<T>, std::is_enum<T>>, T>;

template <typename T>
using TrivialConstructableReturnType = std::enable_if_t<std::conjunction_v<std::is_class<T>, std::is_standard_layout<T>>, T>;

struct BufferReader
{
    template <typename Tuple, typename EndianTag, typename BufferType, size_t N = 0>
    static void assign_form_buffer(Tuple& tuple, const BufferType* buffer, size_t idx)
    {
        using ValueType = std::tuple_element_t<N, Tuple>;
        if (N == idx) {
            std::get<N>(tuple) = tagged_endian_value_impl<ValueType, EndianTag>(buffer);
            return;
        }

        if constexpr (N + 1 < std::tuple_size_v<Tuple>) {
            assign_form_buffer<Tuple, EndianTag, BufferType, N + 1>(tuple, buffer + sizeof(ValueType), idx);
        }
    }

    // Interprets buffer as value of type T in specified endian byte order.
    // overload for fundamentals types
    template <typename T, typename EndianTag, typename BufferType>
    static FundamentalOrEnumReturnType<T> tagged_endian_value_impl(const BufferType* buffer)
    {
        constexpr size_t size = sizeof(T);

        T result;

        const std::uint8_t* in = reinterpret_cast<const std::uint8_t*>(buffer);
        std::uint8_t* out      = reinterpret_cast<std::uint8_t*>(&result);

        if constexpr (std::is_same_v<EndianTag, BigEndianTag>) {
            std::reverse_copy(in, in + size, out);
        } else if constexpr (std::is_same_v<EndianTag, LittleEndianTag>) {
            std::copy(in, in + size, out);
        } else {
            static_assert(false, "Wrong endian tag type.");
        }

        return result;
    }

    // Interprets buffer as value of type T in specified endian byte order.
    // overload for structures
    template <typename T, typename EndianTag, typename BufferType>
    static TrivialConstructableReturnType<T> tagged_endian_value_impl(const BufferType* buffer)
    {
        constexpr size_t count = members_count::members_count<T>();

        TupleType<T> tuple;
        for (size_t i = 0; i < count; ++i) {
            assign_form_buffer<TupleType<T>, EndianTag>(tuple, buffer, i);
        }

        return from_tuple<T>(tuple);
    }
};

template <typename... Args>
constexpr inline std::size_t size_in_bytes(const std::tuple<Args...>&) noexcept
{
    return (sizeof(Args) + ...);
}

struct StreamReader
{
    // Read value of type T in specified endian byte order.
    // overload for fundamentals types
    template <typename T, typename EndianTag, typename Stream>
    static FundamentalOrEnumReturnType<T> tagged_endian_value_impl(Stream& in)
    {
        constexpr size_t buffer_size = sizeof(T);

        char buffer[buffer_size] = {0};
        in.read(buffer, buffer_size);

        return BufferReader::tagged_endian_value_impl<T, EndianTag>(buffer);
    }

    // Read value of type T in specified endian byte order.
    // overload for structures
    template <typename T, typename EndianTag, typename Stream>
    static TrivialConstructableReturnType<T> tagged_endian_value_impl(Stream& in)
    {
        constexpr size_t buffer_size = size_in_bytes(TupleType<T>{});

        char buffer[buffer_size] = {0};
        in.read(buffer, buffer_size);

        return BufferReader::tagged_endian_value_impl<T, EndianTag>(buffer);
    }
};

#pragma endregion

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
