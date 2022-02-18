#ifndef FRAMEWORK_COMMON_UTILS_HPP
#define FRAMEWORK_COMMON_UTILS_HPP

#include <algorithm>
#include <array>
#include <istream>
#include <string>
#include <tuple>
#include <vector>

#include <common/types.hpp>

#include <common/inc/utils_details.hpp>

#include <random>

namespace framework::utils
{
///////////////////////////////////////////////////////////////////////////////
/// @addtogroup common_utils_module
/// @{
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// @brief Determines if it is the debug build.
///
/// @return `true` in debug mode, `false` otherwise.
///////////////////////////////////////////////////////////////////////////////
inline constexpr bool is_debug() noexcept
{
#ifndef NDEBUG
    return true;
#else
    return false;
#endif
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Generates bunch of random numbers.
///
/// @param min Minimum of the generated numbers.
/// @param max Maximum of the generated numbers.
/// @param count How much numbers to generate.
///
/// @return Vector of the `count` size of random numbers in range [min, max].
///////////////////////////////////////////////////////////////////////////////
template <typename T>
std::vector<T> random_numbers(T min, T max, size_t count)
{
    static_assert(std::is_arithmetic_v<T>, "Expected floating-point or integer type.");

    if (count == 0) {
        return std::vector<T>();
    }

    if (min > max) {
        std::swap(min, max);
    }

    auto get_generator = []() {
        std::random_device rd;
        return std::mt19937(rd());
    };

    std::vector<T> result;
    result.reserve(count);

    static auto generator = get_generator();
    auto distribution     = details::get_distribution(min, max);
    for (size_t i = 0; i < count; ++i) {
        result.push_back(distribution(generator));
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Returns elements count in container.
///
/// @param container To get size
///
/// @return Elements count in container.
///////////////////////////////////////////////////////////////////////////////
template <typename C>
constexpr inline std::size_t size(const C& container) noexcept
{
    return container.size();
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Returns elements count in array.
///
/// @return Elements count in array.
///////////////////////////////////////////////////////////////////////////////
template <typename T, std::size_t N>
constexpr inline std::size_t size(const T (&)[N]) noexcept
{
    return N;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Interprets bytes from iterator as value of type T in
///        big endian byte order. No bounds checking is performed.
///
/// @param begin Position to read value from.
///
/// @return Value of type T.
///////////////////////////////////////////////////////////////////////////////
template <typename T, typename Iterator>
inline T big_endian_value(Iterator begin)
{
    using ValueType        = typename std::iterator_traits<Iterator>::value_type;
    using IteratorCategory = typename std::iterator_traits<Iterator>::iterator_category;

    constexpr bool supported_buffer_type = sizeof(ValueType) == 1;
    static_assert(supported_buffer_type, "Usupported buffer type");

    constexpr bool supported_return_type = sizeof(T) <= 8;
    static_assert(supported_return_type, "Usupported return type");

    constexpr bool is_forward_iterator = std::is_convertible_v<IteratorCategory, std::forward_iterator_tag>;
    static_assert(is_forward_iterator, "Iterator is not forward iterator");

    constexpr bool can_read_from_buffer = std::disjunction_v<std::is_fundamental<T>, std::is_enum<T>>;
    static_assert(can_read_from_buffer, "Can't read value of type T from buffer");

    constexpr int size = sizeof(T);
    ValueType buffer[size];

    for (int i = size - 1; i >= 0; --i) {
        buffer[i] = *(begin++);
    }

    return *reinterpret_cast<T*>(buffer);
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Interprets bytes from iterator as value of type T in
///        little endian byte order. No bounds checking is performed.
///
/// @param begin Position to read value from.
///
/// @return Value of type T.
///////////////////////////////////////////////////////////////////////////////
template <typename T, typename Iterator>
inline T little_endian_value(Iterator begin)
{
    using ValueType        = typename std::iterator_traits<Iterator>::value_type;
    using IteratorCategory = typename std::iterator_traits<Iterator>::iterator_category;

    constexpr bool supported_buffer_type = sizeof(ValueType) == 1;
    static_assert(supported_buffer_type, "Usupported buffer type");

    constexpr bool supported_return_type = sizeof(T) <= 8;
    static_assert(supported_return_type, "Usupported return type");

    constexpr bool is_forward_iterator = std::is_convertible_v<IteratorCategory, std::forward_iterator_tag>;
    static_assert(is_forward_iterator, "Iterator is not forward iterator");

    constexpr bool can_read_from_buffer = std::disjunction_v<std::is_fundamental<T>, std::is_enum<T>>;
    static_assert(can_read_from_buffer, "Can't read value of type T from buffer");

    constexpr int size = sizeof(T);
    ValueType buffer[size];

    for (int i = 0; i < size; ++i) {
        buffer[i] = *(begin++);
    }

    return *reinterpret_cast<T*>(buffer);
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Wrapper for @ref big_endian_value which takes care of iterators.
///////////////////////////////////////////////////////////////////////////////
template <typename Iterator>
class BigEndianBufferReader final
{
public:
    using DifferenceType   = typename std::iterator_traits<Iterator>::difference_type;
    using ValueType        = typename std::iterator_traits<Iterator>::value_type;
    using IteratorCategory = typename std::iterator_traits<Iterator>::iterator_category;

    template <typename = std::enable_if_t<std::is_convertible_v<IteratorCategory, std::forward_iterator_tag>, void>>
    BigEndianBufferReader(const Iterator begin, const Iterator end) noexcept
        : m_current(begin)
        , m_end(end)
        , m_distance(std::distance(begin, end))
    {}

    template <typename T>
    T get()
    {
        constexpr DifferenceType size = sizeof(T);
        if (m_distance < size) {
            throw std::out_of_range("Not enough bytes to read value of size " + std::to_string(size));
        }
        T value = big_endian_value<T>(m_current);

        skip<T>();

        return value;
    }

    template <typename T>
    BigEndianBufferReader& operator>>(T& value)
    {
        value = get<T>();
        return *this;
    }

    template <typename T>
    void skip(DifferenceType count = 1) noexcept
    {
        DifferenceType step = count * static_cast<DifferenceType>(sizeof(T));

        step = std::clamp(step, DifferenceType(0), m_distance);
        std::advance(m_current, step);
        m_distance -= step;
    }

    operator bool() const noexcept
    {
        return m_distance > 0;
    }

    bool good() const noexcept

    {
        return m_distance > 0;
    }

private:
    Iterator m_current;
    const Iterator m_end;
    DifferenceType m_distance = 0;
};

// additional deduction guide
template <class Iterator>
BigEndianBufferReader(Iterator, Iterator) -> BigEndianBufferReader<Iterator>;

// maker function
template <typename Iterator>
inline BigEndianBufferReader<Iterator> make_big_endian_buffer_reader(const Iterator begin, const Iterator end) noexcept
{
    return BigEndianBufferReader(begin, end);
}

template <typename Container>
inline auto make_big_endian_buffer_reader(const Container& container) noexcept
{
    return make_big_endian_buffer_reader(std::begin(container), std::end(container));
}

template <typename T, std::size_t N>
inline auto make_big_endian_buffer_reader(const T (&buffer)[N]) noexcept
{
    return make_big_endian_buffer_reader(std::begin(buffer), std::end(buffer));
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Wrapper for @ref little_endian_value which takes care of iterators.
///////////////////////////////////////////////////////////////////////////////
template <typename Iterator>
class LittleEndianBufferReader final
{
public:
    using DifferenceType   = typename std::iterator_traits<Iterator>::difference_type;
    using ValueType        = typename std::iterator_traits<Iterator>::value_type;
    using IteratorCategory = typename std::iterator_traits<Iterator>::iterator_category;

    template <typename = std::enable_if_t<std::is_convertible_v<IteratorCategory, std::forward_iterator_tag>, void>>
    LittleEndianBufferReader(const Iterator begin, const Iterator end) noexcept
        : m_current(begin)
        , m_end(end)
        , m_distance(std::distance(begin, end))
    {}

    template <typename T>
    T get()
    {
        constexpr DifferenceType size = sizeof(T);
        if (m_distance < size) {
            throw std::out_of_range("Not enough bytes to read value of size " + std::to_string(size));
        }
        T value = little_endian_value<T>(m_current);

        skip<T>();

        return value;
    }

    template <typename T>
    LittleEndianBufferReader& operator>>(T& value)
    {
        value = get<T>();
        return *this;
    }

    template <typename T>
    void skip(DifferenceType count = 1) noexcept
    {
        DifferenceType step = count * static_cast<DifferenceType>(sizeof(T));

        step = std::clamp(step, DifferenceType(0), m_distance);
        std::advance(m_current, step);
        m_distance -= step;
    }

    operator bool() const noexcept
    {
        return m_distance > 0;
    }

    bool good() const noexcept

    {
        return m_distance > 0;
    }

private:
    Iterator m_current;
    const Iterator m_end;
    DifferenceType m_distance = 0;
};

// additional deduction guide
template <class Iterator>
LittleEndianBufferReader(Iterator, Iterator) -> LittleEndianBufferReader<Iterator>;

// maker function
template <typename Iterator>
inline LittleEndianBufferReader<Iterator> make_little_endian_buffer_reader(const Iterator begin,
                                                                           const Iterator end) noexcept
{
    return LittleEndianBufferReader(begin, end);
}

template <typename Container>
inline auto make_little_endian_buffer_reader(const Container& container) noexcept
{
    return make_little_endian_buffer_reader(std::begin(container), std::end(container));
}

template <typename T, std::size_t N>
inline auto make_little_endian_buffer_reader(const T (&buffer)[N]) noexcept
{
    return make_little_endian_buffer_reader(std::begin(buffer), std::end(buffer));
}

/*
template <typename... Args>
std::string format(const std::string& str, Args&&... args)
{
    std::unique_ptr<format_details::value_base> values[sizeof...(args)] = {
    (format_details::make_value_holder_ptr(args))...,
    };
    return format_details::make_string_impl(str, values, sizeof...(args));
}
*/

///////////////////////////////////////////////////////////////////////////////
/// @}
///////////////////////////////////////////////////////////////////////////////

} // namespace framework::utils

#endif
