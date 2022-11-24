#ifndef COMMON_UTILS_HPP
#define COMMON_UTILS_HPP

#include <algorithm>
#include <array>
#include <istream>
#include <string>
#include <tuple>
#include <vector>

#include <common/inc/utils_details.hpp>

#include <random>

namespace neutrino::utils
{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @addtogroup utils_utils_module
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Generates bunch of random numbers.
///
/// For integers range is closed, [min. max].
/// For floating-point numbers the range is [min, max).
///
/// @param min Minimum of the generated numbers.
/// @param max Maximum of the generated numbers.
/// @param count How much numbers to generate.
///
/// @return Vector of the `count` size of random numbers in range [min, max].
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

/// @brief Returns elements count in container.
///
/// @param container To get size
///
/// @return Elements count in container.
template <typename C>
constexpr inline std::size_t size(const C& container) noexcept
{
    return container.size();
}

/// @brief Returns elements count in array.
///
/// @return Elements count in array.
template <typename T, std::size_t N>
constexpr inline std::size_t size(const T (&)[N]) noexcept
{
    return N;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name Big-endian value reader
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Interprets bytes from iterator as value of type T in big-endian byte order. No bounds checking is performed.
///
/// @param begin Position to read value from.
///
/// @return Value of type T.
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

/// @brief Wrapper for @ref big_endian_value which takes care of iterators.
///
/// Interprets bytes from range [begin, end) as value of type T in big-endian byte order with bounds checking.
template <typename Iterator>
class BigEndianBufferReader final
{
public:
    using DifferenceType   = typename std::iterator_traits<Iterator>::difference_type;
    using ValueType        = typename std::iterator_traits<Iterator>::value_type;
    using IteratorCategory = typename std::iterator_traits<Iterator>::iterator_category;

    /// @brief Creates BigEndianBufferReader for provided range.
    ///
    /// @param begin Beginning of buffer range.
    /// @param end end of buffer range.
    template <typename = std::enable_if_t<std::is_convertible_v<IteratorCategory, std::forward_iterator_tag>, void>>
    BigEndianBufferReader(const Iterator begin, const Iterator end) noexcept
        : m_begin(begin)
        , m_end(end)
        , m_current(begin)
        , m_bytes_left(std::distance(begin, end))
    {}

    /// @brief Read value of type T form buffer reader.
    ///
    /// If there are not enough bytes in range buffer reader holds, an exception of type std::out_of_range is thrown.
    ///
    /// @return value of type T.
    template <typename T>
    T get()
    {
        constexpr DifferenceType size = sizeof(T);
        if (m_bytes_left < size) {
            throw std::out_of_range("Not enough bytes to read value of size " + std::to_string(size));
        }
        T value = big_endian_value<T>(m_current);

        skip<T>();

        return value;
    }

    /// @brief Read value of type T form buffer reader.
    ///
    /// If there are not enough bytes in range buffer reader holds, an exception of type std::out_of_range is thrown.
    ///
    /// @param value Value to store.
    ///
    /// @return Reference to current BigEndianBufferReader instance.
    template <typename T>
    BigEndianBufferReader& operator>>(T& value)
    {
        value = get<T>();
        return *this;
    }

    /// @brief Skips count of values of type T in a buffer.
    ///
    /// @param count How many values of type T to skip.
    template <typename T>
    void skip(DifferenceType count = 1) noexcept
    {
        DifferenceType step = count * static_cast<DifferenceType>(sizeof(T));

        step = std::clamp(step, DifferenceType(0), m_bytes_left);
        std::advance(m_current, step);
        m_bytes_left -= step;
    }

    /// @brief Checks if the buffer has some bytes in it.
    ///
    /// @return `true` if buffer is not empty.
    operator bool() const noexcept
    {
        return m_bytes_left > 0;
    }

    /// @brief Checks if the buffer has some bytes in it.
    ///
    /// @return `true` if buffer is not empty.
    bool good() const noexcept

    {
        return m_bytes_left > 0;
    }

    /// @brief Start of bytes range.
    ///
    /// @return Iterator to the start of bytes range.
    Iterator begin() const noexcept
    {
        return m_begin;
    }

    /// @brief End of bytes range.
    ///
    /// @return Iterator to the end of bytes range.
    Iterator end() const noexcept
    {
        return m_end;
    }

    /// @brief Current position in bytes range.
    ///
    /// @return Iterator to the current position in bytes range.
    Iterator current() const noexcept
    {
        return m_current;
    }

private:
    const Iterator m_begin;
    const Iterator m_end;
    Iterator m_current;
    DifferenceType m_bytes_left = 0;
};

/// @brief BigEndianBufferReader deduction guide
template <class Iterator>
BigEndianBufferReader(Iterator, Iterator) -> BigEndianBufferReader<Iterator>;

/// @brief Creates an instance of BigEndianBufferReader with the provided range [begin, end).
///
/// @param begin Beginning of buffer range.
/// @param end end of buffer range.
///
/// @return BigEndianBufferReader instance.
template <typename Iterator>
inline BigEndianBufferReader<Iterator> make_big_endian_buffer_reader(const Iterator begin, const Iterator end) noexcept
{
    return BigEndianBufferReader(begin, end);
}

/// @brief Creates an instance of BigEndianBufferReader with the provided container as a buffer to read values from.
///
/// @param container Container to read values from.
///
/// @return BigEndianBufferReader instance.
template <typename Container>
inline auto make_big_endian_buffer_reader(const Container& container) noexcept
{
    return make_big_endian_buffer_reader(std::begin(container), std::end(container));
}

/// @brief Creates an instance of BigEndianBufferReader with an array as a buffer to read values from.
///
/// @param buffer Array to read values from.
///
/// @return BigEndianBufferReader instance.
template <typename T, std::size_t N>
inline auto make_big_endian_buffer_reader(const T (&buffer)[N]) noexcept
{
    return make_big_endian_buffer_reader(std::begin(buffer), std::end(buffer));
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name Little-endian value reader
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Interprets bytes from iterator as value of type T in little-endian byte order. No bounds checking is performed.
///
/// @param begin Position to read value from.
///
/// @return Value of type T.
template <typename T, typename Iterator>
inline T little_endian_value(Iterator begin)
{
    using ValueType        = typename std::iterator_traits<Iterator>::value_type;
    using IteratorCategory = typename std::iterator_traits<Iterator>::iterator_category;

    constexpr bool supported_buffer_type = sizeof(ValueType) == 1;
    static_assert(supported_buffer_type, "Unsupported buffer type");

    constexpr bool supported_return_type = sizeof(T) <= 8;
    static_assert(supported_return_type, "Unsupported return type");

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

/// @brief Wrapper for @ref little_endian_value which takes care of iterators.
///
/// Interprets bytes from range [begin, end) as value of type T in little-endian byte order with bounds checking.
template <typename Iterator>
class LittleEndianBufferReader final
{
public:
    using DifferenceType   = typename std::iterator_traits<Iterator>::difference_type;
    using ValueType        = typename std::iterator_traits<Iterator>::value_type;
    using IteratorCategory = typename std::iterator_traits<Iterator>::iterator_category;

    /// @brief Creates LittleEndianBufferReader for provided range.
    ///
    /// @param begin Beginning of buffer range.
    /// @param end end of buffer range.
    template <typename = std::enable_if_t<std::is_convertible_v<IteratorCategory, std::forward_iterator_tag>, void>>
    LittleEndianBufferReader(const Iterator begin, const Iterator end) noexcept
        : m_begin(begin)
        , m_end(end)
        , m_current(begin)
        , m_bytes_left(std::distance(begin, end))
    {}

    /// @brief Read value of type T form buffer reader.
    ///
    /// If there are not enough bytes in range buffer reader holds, an exception of type std::out_of_range is thrown.
    ///
    /// @return value of type T.
    template <typename T>
    T get()
    {
        constexpr DifferenceType size = sizeof(T);
        if (m_bytes_left < size) {
            throw std::out_of_range("Not enough bytes to read value of size " + std::to_string(size));
        }
        T value = little_endian_value<T>(m_current);

        skip<T>();

        return value;
    }

    /// @brief Read value of type T form buffer reader.
    ///
    /// If there are not enough bytes in range buffer reader holds, an exception of type std::out_of_range is thrown.
    ///
    /// @param value Value to store.
    ///
    /// @return Reference to current LittleEndianBufferReader instance.
    template <typename T>
    LittleEndianBufferReader& operator>>(T& value)
    {
        value = get<T>();
        return *this;
    }

    /// @brief Skips count of values of type T in a buffer.
    ///
    /// @param count How many values of type T to skip.
    template <typename T>
    void skip(DifferenceType count = 1) noexcept
    {
        DifferenceType step = count * static_cast<DifferenceType>(sizeof(T));

        step = std::clamp(step, DifferenceType(0), m_bytes_left);
        std::advance(m_current, step);
        m_bytes_left -= step;
    }

    /// @brief Checks if the buffer has some bytes in it.
    ///
    /// @return `true` if buffer is not empty.
    operator bool() const noexcept
    {
        return m_bytes_left > 0;
    }

    /// @brief Checks if the buffer has some bytes in it.
    ///
    /// @return `true` if buffer is not empty.
    bool good() const noexcept

    {
        return m_bytes_left > 0;
    }

    /// @brief Start of bytes range.
    ///
    /// @return Iterator to the start of bytes range.
    Iterator begin() const noexcept
    {
        return m_begin;
    }

    /// @brief End of bytes range.
    ///
    /// @return Iterator to the end of bytes range.
    Iterator end() const noexcept
    {
        return m_end;
    }

    /// @brief Current position in bytes range.
    ///
    /// @return Iterator to the current position in bytes range.
    Iterator current() const noexcept
    {
        return m_current;
    }

private:
    const Iterator m_begin;
    const Iterator m_end;
    Iterator m_current;
    DifferenceType m_bytes_left = 0;
};

/// @brief LittleEndianBufferReader deduction guide
template <class Iterator>
LittleEndianBufferReader(Iterator, Iterator) -> LittleEndianBufferReader<Iterator>;

/// @brief Creates an instance of LittleEndianBufferReader with the provided range [begin, end).
///
/// @param begin Beginning of buffer range.
/// @param end end of buffer range.
///
/// @return LittleEndianBufferReader instance.
template <typename Iterator>
inline LittleEndianBufferReader<Iterator> make_little_endian_buffer_reader(const Iterator begin,
                                                                           const Iterator end) noexcept
{
    return LittleEndianBufferReader(begin, end);
}

/// @brief Creates an instance of LittleEndianBufferReader with the provided container as a buffer to read values from.
///
/// @param container Container to read values from.
///
/// @return LittleEndianBufferReader instance.
template <typename Container>
inline auto make_little_endian_buffer_reader(const Container& container) noexcept
{
    return make_little_endian_buffer_reader(std::begin(container), std::end(container));
}

/// @brief Creates an instance of LittleEndianBufferReader with an array as a buffer to read values from.
///
/// @param buffer Array to read values from.
///
/// @return LittleEndianBufferReader instance.
template <typename T, std::size_t N>
inline auto make_little_endian_buffer_reader(const T (&buffer)[N]) noexcept
{
    return make_little_endian_buffer_reader(std::begin(buffer), std::end(buffer));
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

} // namespace neutrino::utils

#endif
