/**
 * @file vector_type.hpp
 * @brief Implementation of geometric vector.
 * @author Fedorov Alexey
 * @date 12.03.2017
 */

#ifndef FRAMEWORK_MATH_VECTOR_TYPE_HPP
#define FRAMEWORK_MATH_VECTOR_TYPE_HPP

#include <math/common_func.hpp>

namespace framework {

namespace math {

/**
 * @defgroup vector_implementation Vector type implementation
 * @ingroup math_module
 * @{
 */

/**
 * @brief Contains vector type implementation details.
 */
namespace vector_impl {

/**
 * @brief Workaround to cast float numbers to boolean without warnings.
 * @{
 */
template <typename T>
struct cast_to
{
    template <typename U>
    inline static constexpr T from(const U& value)
    {
        return static_cast<T>(value);
    }
};

template <>
struct cast_to<bool>
{
    template <typename U>
    inline static constexpr bool from(const U& value)
    {
        return ::framework::math::abs(value) > 0;
    }
};

/**
 * @}
 */

/**
 * @brief Helper that checks if all presented types are arithmetic.
 * @{
 */
template <typename T, typename... Args>
struct are_all_arithmetic
{
    static constexpr bool value = std::is_arithmetic<T>::value && are_all_arithmetic<Args...>::value;
};

template <typename T>
struct are_all_arithmetic<T>
{
    static constexpr bool value = std::is_arithmetic<T>::value;
};

/**
 * @}
 */

/**
 * @brief Helper that give common type for all presented types.
 * @{
 */
template <bool C, typename... Args>
struct common_type_impl
{
};

template <typename T, typename... Args>
struct common_type_impl<true, T, Args...>
{
    using type = typename std::common_type<T, typename common_type_impl<true, Args...>::type>::type;
};

template <typename T>
struct common_type_impl<true, T>
{
    using type = T;
};

/**
 * @}
 */

/**
 * @brief Shortcut to get the common type.
 * Also used for SFINAE to get correct overload of vector operators.
 */
template <typename... Args>
using common_type = common_type_impl<are_all_arithmetic<Args...>::value, Args...>;


} // namespace vector_impl

#pragma mark - vector template declaration

/**
 * @brief Base template declaration.
 * @see vector<4, T>, vector<3, T>, vector<2, T>
 */
template <unsigned int N, typename T>
struct vector;

/**
 * @name Vector specializations.
 * @{
 */

#pragma mark - vector<4, T> type specialization

/**
 * @brief Vector<4, T> type specialization.
 *
 * @note Can be instantiated only with arithmetic type.
 */
template <typename T>
struct vector<4, T> final
{
    static_assert(std::is_arithmetic<T>::value, "Expected floating-point or integer type.");

    /**
     * @brief Values type.
     */
    using value_type = T;

    /**
     * @brief Default constructor.
     *
     * Initializes vector as {0, 0, 0, 1}
     * For bool vector initializes as {false, false, false, false}
     */
    constexpr vector() noexcept;

    /**
     * @brief Default copy constructor.
     */
    constexpr vector(const vector<4, value_type>&) noexcept = default;

    /**
     * @brief Default move constructor.
     */
    constexpr vector(vector<4, value_type>&&) noexcept = default;

    /**
     * @brief Initializes vector with provided values.
     *
     * @param x_value Value for x component.
     * @param y_value Value for y component.
     * @param z_value Value for z component.
     * @param w_value Value for w component.
     */
    template <typename X, typename Y, typename Z, typename W>
    constexpr vector(const X& x_value, const Y& y_value, const Z& z_value, const W& w_value) noexcept;

    /**
     * @brief Initializes all components of vector with same value.
     *
     * @param value Value for x, y, z and w components.
     */
    template <typename U>
    explicit constexpr vector(const U& value) noexcept;

    /**
     * @brief Initializes all components of vector from pointer to values.
     *
     * @param pointer Pointer to values that should be taken.
     *
     * @warning May cause memory access error.
     */
    template <typename U>
    explicit constexpr vector(const U* const pointer);

    /**
     * @brief Initializes vector from other one.
     *
     * @param other Vector to initialize x, y, z and w components.
     */
    template <typename U>
    explicit constexpr vector(const vector<4, U>& other) noexcept;

    /**
     * @brief Initializes vector from other one.
     *
     * @param other Vector to initialize x, y and z components.
     *
     * @note The w component will be initialized with default value.
     */
    template <typename U>
    explicit constexpr vector(const vector<3, U>& other) noexcept;

    /**
     * @brief Initializes vector from scalar value and other vector.
     *
     * @param x_value Value for x component.
     * @param other Vector to initialize y, z and w components.
     */
    template <typename U, typename X>
    constexpr vector(const X& x_value, const vector<3, U>& other) noexcept;

    /**
     * @brief Initializes vector from vector and scalar value.
     *
     * @param other Vector to initialize x, y and z components.
     * @param w_value Value for w component.
     */
    template <typename U, typename W>
    constexpr vector(const vector<3, U>& other, const W& w_value) noexcept;

    /**
     * @brief Initializes vector from other vector.
     *
     * @param other Vector to initialize x and y components.
     *
     * @note The z and y components will be initialized with default value.
     */
    template <typename U>
    explicit constexpr vector(const vector<2, U>& other) noexcept;

    /**
     * @brief Initializes vector from 2 vectors.
     *
     * @param first_part Vector to initialize x and y components.
     * @param second_part Vector to initialize z and w components.
     */
    template <typename U1, typename U2>
    constexpr vector(const vector<2, U1>& first_part, const vector<2, U2>& second_part) noexcept;

    /**
     * @brief Initializes vector from 2 scalar values and vector.
     *
     * @param x_value Value for x component.
     * @param y_value Value for y component.
     * @param other Vector to initialize z and w components.
     */
    template <typename U, typename X, typename Y>
    constexpr vector(const X& x_value, const Y& y_value, const vector<2, U>& other) noexcept;

    /**
     * @brief Initializes vector from scalar value, vector and another scalar value.
     *
     * @param x_value Value for x component.
     * @param other Vector to initialize y and z components.
     * @param w_value Value for w component.
     */
    template <typename U, typename X, typename W>
    constexpr vector(const X& x_value, const vector<2, U>& other, const W& w_value) noexcept;

    /**
     * @brief Initializes vector from vector and 2 scalar values.
     *
     * @param other Vector to initialize x and y components.
     * @param z_value Value for z component.
     * @param w_value Value for w component.
     */
    template <typename U, typename Z, typename W>
    constexpr vector(const vector<2, U>& other, const Z& z_value, const W& w_value) noexcept;

    /**
     * @brief Default assignment operator.
     */
    vector<4, value_type>& operator=(const vector<4, value_type>&) noexcept = default;

    /**
     * @brief Default move assignment operator.
     */
    vector<4, value_type>& operator=(vector<4, value_type>&&) noexcept = default;

    /**
     * @brief Assignment operator.
     */
    template <typename U>
    vector<4, value_type>& operator=(const vector<4, U>& other) noexcept;

    /**
     * @brief Access operator.
     *
     * @return Reference to component of vector.
     *
     * @warning There is no size check. May cause memory access error.
     */
    value_type& operator[](unsigned int index);

    /**
     * @brief Const access operator.
     *
     * @return Reference to constant component of vector.
     *
     * @warning There is no size check. May cause memory access error.
     */
    const value_type& operator[](unsigned int index) const;

    /**
     * @brief Size of vector.
     *
     * @return Count of components in vector.
     */
    constexpr unsigned int size() const noexcept;

    /**
     * @brief Provides direct access to internal content.
     *
     * @return A pointer to the x component.
     */
    value_type* data() noexcept;

    /**
     * @brief Provides direct access to internal content.
     *
     * @return A pointer to the x component.
     */
    const value_type* data() const noexcept;

    value_type x; /**< The x component */
    value_type y; /**< The y component */
    value_type z; /**< The z component */
    value_type w; /**< The w component */
};

#pragma mark - vector<3, T> type specialization

/**
 * @brief Vector<3, T> type specialization.
 */
template <typename T>
struct vector<3, T> final
{
    static_assert(std::is_arithmetic<T>::value, "Expected floating-point or integer type.");

    /**
     * @brief Values type.
     */
    using value_type = T;

    /**
     * @brief Default constructor.
     *
     * Initializes vector as {0, 0, 0}
     */
    constexpr vector() noexcept;

    /**
     * @brief Default copy constructor
     */
    constexpr vector(const vector<3, value_type>&) noexcept = default;

    /**
     * @brief Default move constructor
     */
    constexpr vector(vector<3, value_type>&&) noexcept = default;

    /**
     * @brief Initializes vector with provided values.
     *
     * @param x_value Value for x component.
     * @param y_value Value for y component.
     * @param z_value Value for z component.
     */
    template <typename X, typename Y, typename Z>
    constexpr vector(const X& x_value, const Y& y_value, const Z& z_value) noexcept;

    /**
     * @brief Initializes all components of vector with same value.
     *
     * @param value Value for x, y and z components.
     */
    template <typename U>
    explicit constexpr vector(const U& value) noexcept;

    /**
     * @brief Initializes all components of vector from pointer to values.
     *
     * @param pointer Pointer to values that should be taken.
     *
     * @warning May cause memory access error.
     */
    template <typename U>
    explicit constexpr vector(const U* const pointer);

    /**
     * @brief Initializes vector from other one.
     *
     * @param other Vector to initialize x, y and z components.
     */
    template <typename U>
    explicit constexpr vector(const vector<4, U>& other) noexcept;

    /**
     * @brief Initializes vector from other one.
     *
     * @param other Vector to initialize x, y and z components.
     */
    template <typename U>
    explicit constexpr vector(const vector<3, U>& other) noexcept;

    /**
     * @brief Initializes vector from other one.
     *
     * @param other Vector to initialize x and y components.
     *
     * @note The z component will be initialized with default value.
     */
    template <typename U>
    explicit constexpr vector(const vector<2, U>& other) noexcept;

    /**
     * @brief Initializes vector from scalar value and other vector.
     *
     * @param x_value Value for x component.
     * @param other Vector to initialize y and z components.
     */
    template <typename U, typename X>
    constexpr vector(const X& x_value, const vector<2, U>& other) noexcept;

    /**
     * @brief Initializes vector from vector and scalar value.
     *
     * @param other Vector to initialize x and y components.
     * @param z_value Value for z component.
     */
    template <typename U, typename Z>
    constexpr vector(const vector<2, U>& v, const Z& z_value) noexcept;

    /**
     * @brief Default assignment operator.
     */
    vector<3, value_type>& operator=(const vector<3, value_type>&) noexcept = default;

    /**
     * @brief Default move assignment operator.
     */
    vector<3, value_type>& operator=(vector<3, value_type>&&) noexcept = default;

    /**
     * @brief Assignment operator.
     */
    template <typename U>
    vector<3, value_type>& operator=(const vector<3, U>& other) noexcept;

    /**
     * @brief Access operator.
     *
     * @return Reference to component of vector.
     *
     * @warning There is no size check. May cause memory access error.
     */
    value_type& operator[](unsigned int index);

    /**
     * @brief Const access operator.
     *
     * @return Reference to constant component of vector.
     *
     * @warning There is no size check. May cause memory access error.
     */
    const value_type& operator[](unsigned int index) const;

    /**
     * @brief Size of vector.
     *
     * @return Count of components in vector.
     */
    constexpr unsigned int size() const noexcept;

    /**
     * @brief Provides direct access to internal content.
     *
     * @return A pointer to the x component.
     */
    value_type* data() noexcept;

    /**
     * @brief Provides direct access to internal content.
     *
     * @return A pointer to the x component.
     */
    const value_type* data() const noexcept;

    value_type x; /**< The x component */
    value_type y; /**< The y component */
    value_type z; /**< The z component */
};

#pragma mark - vector<2, T> type specialization

/**
 * @brief Vector<2, T> type specialization.
 */
template <typename T>
struct vector<2, T> final
{
    static_assert(std::is_arithmetic<T>::value, "Expected floating-point or integer type.");

    /**
     * @brief Values type.
     */
    using value_type = T;

    /**
     * @brief Default constructor.
     *
     * Initializes vector as {0, 0}
     */
    constexpr vector() noexcept;

    /**
     * @brief Default copy constructor
     */
    constexpr vector(const vector<2, value_type>&) noexcept = default;

    /**
     * @brief Default move constructor
     */
    constexpr vector(vector<2, value_type>&&) noexcept = default;

    /**
     * @brief Initializes vector with provided values.
     *
     * @param x_value Value for x component.
     * @param y_value Value for y component.
     */
    template <typename X, typename Y>
    constexpr vector(const X& x_value, const Y& y_value) noexcept;

    /**
     * @brief Initializes all components of vector with same value.
     *
     * @param value Value for x and y components.
     */
    template <typename U>
    explicit constexpr vector(const U& value) noexcept;

    /**
     * @brief Initializes all components of vector from pointer to values.
     *
     * @param pointer Pointer to values that should be taken.
     *
     * @warning May cause memory access error.
     */
    template <typename U>
    explicit constexpr vector(const U* pointer);

    /**
     * @brief Initializes vector from other one.
     *
     * @param other Vector to initialize x and y components.
     */
    template <typename U>
    explicit constexpr vector(const vector<4, U>& other) noexcept;

    /**
     * @brief Initializes vector from other one.
     *
     * @param other Vector to initialize x and y components.
     */
    template <typename U>
    explicit constexpr vector(const vector<3, U>& other) noexcept;

    /**
     * @brief Initializes vector from other one.
     *
     * @param other Vector to initialize x and y components.
     */
    template <typename U>
    explicit constexpr vector(const vector<2, U>& other) noexcept;

    /**
     * @brief Default assignment operator.
     */
    vector<2, value_type>& operator=(const vector<2, value_type>&) noexcept = default;

    /**
     * @brief Default move assignment operator.
     */
    vector<2, value_type>& operator=(vector<2, value_type>&&) noexcept = default;

    /**
     * @brief Assignment operator.
     */
    template <typename U>
    vector<2, value_type>& operator=(const vector<2, U>& other) noexcept;

    /**
     * @brief Access operator.
     *
     * @return Reference to component of vector.
     *
     * @warning There is no size check. May cause memory access error.
     */
    value_type& operator[](unsigned int index);

    /**
     * @brief Const access operator.
     *
     * @return Reference to constant component of vector.
     *
     * @warning There is no size check. May cause memory access error.
     */
    const value_type& operator[](unsigned int index) const;

    /**
     * @brief Size of vector.
     *
     * @return Count of components in vector.
     */
    constexpr unsigned int size() const noexcept;

    /**
     * @brief Provides direct access to internal content.
     *
     * @return A pointer to the x component.
     */
    value_type* data() noexcept;

    /**
     * @brief Provides direct access to internal content.
     *
     * @return A pointer to the x component.
     */
    const value_type* data() const noexcept;

    value_type x; /**< The x component */
    value_type y; /**< The y component */
};

/**
 * @}
 */

#pragma mark - vector<4, T> implementation

/**
 * @name Vector<4, T> constructors.
 * @{
 */
template <typename T>
inline constexpr vector<4, T>::vector() noexcept
    : x{T(0)}
    , y{T(0)}
    , z{T(0)}
    , w{std::is_same<T, bool>::value ? T(0) : T(1)}
{
}

template <typename T>
template <typename X, typename Y, typename Z, typename W>
inline constexpr vector<4, T>::vector(const X& x_value, const Y& y_value, const Z& z_value, const W& w_value) noexcept
    : x{vector_impl::cast_to<T>::from(x_value)}
    , y{vector_impl::cast_to<T>::from(y_value)}
    , z{vector_impl::cast_to<T>::from(z_value)}
    , w{vector_impl::cast_to<T>::from(w_value)}
{
}

template <typename T>
template <typename U>
inline constexpr vector<4, T>::vector(const U& value) noexcept
    : vector{value, value, value, value}
{
}

template <typename T>
template <typename U>
inline constexpr vector<4, T>::vector(const U* const pointer)
    : vector{*pointer, *(pointer + 1), *(pointer + 2), *(pointer + 3)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}


template <typename T>
template <typename U>
inline constexpr vector<4, T>::vector(const vector<4, U>& other) noexcept
    : vector{other.x, other.y, other.z, other.w}
{
}

template <typename T>
template <typename U>
inline constexpr vector<4, T>::vector(const vector<3, U>& other) noexcept
    : vector{other.x, other.y, other.z, std::is_same<T, bool>::value ? T(0) : T(1)}
{
}

template <typename T>
template <typename U, typename X>
inline constexpr vector<4, T>::vector(const X& x_value, const vector<3, U>& other) noexcept
    : vector{x_value, other.x, other.y, other.z}
{
}

template <typename T>
template <typename U, typename W>
inline constexpr vector<4, T>::vector(const vector<3, U>& other, const W& w_value) noexcept
    : vector{other.x, other.y, other.z, w_value}
{
}

template <typename T>
template <typename U>
inline constexpr vector<4, T>::vector(const vector<2, U>& other) noexcept
    : vector{other.x, other.y, T(0), std::is_same<T, bool>::value ? T(0) : T(1)}
{
}

template <typename T>
template <typename U1, typename U2>
inline constexpr vector<4, T>::vector(const vector<2, U1>& first_part, const vector<2, U2>& second_part) noexcept
    : vector{first_part.x, first_part.y, second_part.x, second_part.y}
{
}

template <typename T>
template <typename U, typename X, typename Y>
inline constexpr vector<4, T>::vector(const X& x_value, const Y& y_value, const vector<2, U>& other) noexcept
    : vector{x_value, y_value, other.x, other.y}
{
}

template <typename T>
template <typename U, typename X, typename W>
inline constexpr vector<4, T>::vector(const X& x_value, const vector<2, U>& other, const W& w_value) noexcept
    : vector{x_value, other.x, other.y, w_value}
{
}

template <typename T>
template <typename U, typename Z, typename W>
inline constexpr vector<4, T>::vector(const vector<2, U>& other, const Z& z_value, const W& w_value) noexcept
    : vector{other.x, other.y, z_value, w_value}
{
}

/**
 * @}
 */

/**
 * @name Vector<4, T> operators.
 * @{
 */

template <typename T>
template <typename U>
inline vector<4, T>& vector<4, T>::operator=(const vector<4, U>& other) noexcept
{
    x = vector_impl::cast_to<T>::from(other.x);
    y = vector_impl::cast_to<T>::from(other.y);
    z = vector_impl::cast_to<T>::from(other.z);
    w = vector_impl::cast_to<T>::from(other.w);

    return *this;
}

// access operator
template <typename T>
inline typename vector<4, T>::value_type& vector<4, T>::operator[](unsigned int index)
{
    return data()[index];
}

template <typename T>
inline const typename vector<4, T>::value_type& vector<4, T>::operator[](unsigned int index) const
{
    return data()[index];
}

/**
 * @}
 */

/**
 * @name Vector<4, T> methods.
 * @{
 */

template <typename T>
inline constexpr unsigned int vector<4, T>::size() const noexcept
{
    return 4;
}

template <typename T>
inline typename vector<4, T>::value_type* vector<4, T>::data() noexcept
{
    return &(this->x);
}

template <typename T>
inline const typename vector<4, T>::value_type* vector<4, T>::data() const noexcept
{
    return &(this->x);
}

/**
 * @}
 */

#pragma mark - vector<3, T> implementation

/**
 * @name Vector<3, T> constructors.
 * @{
 */
template <typename T>
inline constexpr vector<3, T>::vector() noexcept
    : x{T(0)}
    , y{T(0)}
    , z{T(0)}
{
}

template <typename T>
template <typename X, typename Y, typename Z>
inline constexpr vector<3, T>::vector(const X& x_value, const Y& y_value, const Z& z_value) noexcept
    : x{vector_impl::cast_to<T>::from(x_value)}
    , y{vector_impl::cast_to<T>::from(y_value)}
    , z{vector_impl::cast_to<T>::from(z_value)}
{
}

template <typename T>
template <typename U>
inline constexpr vector<3, T>::vector(const U& value) noexcept
    : vector{value, value, value}
{
}

template <typename T>
template <typename U>
inline constexpr vector<3, T>::vector(const U* const pointer)
    : vector{*pointer, *(pointer + 1), *(pointer + 2)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

template <typename T>
template <typename U>
inline constexpr vector<3, T>::vector(const vector<4, U>& other) noexcept
    : vector{other.x, other.y, other.z}
{
}

template <typename T>
template <typename U>
inline constexpr vector<3, T>::vector(const vector<3, U>& other) noexcept
    : vector{other.x, other.y, other.z}
{
}

template <typename T>
template <typename U>
inline constexpr vector<3, T>::vector(const vector<2, U>& other) noexcept
    : vector{other.x, other.y, T(0)}
{
}

template <typename T>
template <typename U, typename X>
inline constexpr vector<3, T>::vector(const X& x_value, const vector<2, U>& other) noexcept
    : vector{x_value, other.x, other.y}
{
}

template <typename T>
template <typename U, typename Z>
inline constexpr vector<3, T>::vector(const vector<2, U>& other, const Z& z_value) noexcept
    : vector{other.x, other.y, z_value}
{
}

/**
 * @}
 */

/**
 * @name Vector<3, T> operators.
 * @{
 */

template <typename T>
template <typename U>
inline vector<3, T>& vector<3, T>::operator=(const vector<3, U>& other) noexcept
{
    x = vector_impl::cast_to<T>::from(other.x);
    y = vector_impl::cast_to<T>::from(other.y);
    z = vector_impl::cast_to<T>::from(other.z);

    return *this;
}

// access operator
template <typename T>
inline typename vector<3, T>::value_type& vector<3, T>::operator[](unsigned int index)
{
    return data()[index];
}

template <typename T>
inline const typename vector<3, T>::value_type& vector<3, T>::operator[](unsigned int index) const
{
    return data()[index];
}

/**
 * @}
 */

/**
 * @name Vector<3, T> methods.
 * @{
 */

template <typename T>
inline constexpr unsigned int vector<3, T>::size() const noexcept
{
    return 3;
}

template <typename T>
inline typename vector<3, T>::value_type* vector<3, T>::data() noexcept
{
    return &(this->x);
}

template <typename T>
inline const typename vector<3, T>::value_type* vector<3, T>::data() const noexcept
{
    return &(this->x);
}

/**
 * @}
 */

#pragma mark - vector<2, T> implementation

/**
 * @name Vector<2, T> constructors.
 * @{
 */

template <typename T>
inline constexpr vector<2, T>::vector() noexcept
    : x{T(0)}
    , y{T(0)}
{
}

template <typename T>
template <typename X, typename Y>
inline constexpr vector<2, T>::vector(const X& x_value, const Y& y_value) noexcept
    : x{vector_impl::cast_to<T>::from(x_value)}
    , y{vector_impl::cast_to<T>::from(y_value)}
{
}

template <typename T>
template <typename U>
inline constexpr vector<2, T>::vector(const U& value) noexcept
    : vector{value, value}
{
}

template <typename T>
template <typename U>
inline constexpr vector<2, T>::vector(const U* pointer)
    : vector{*pointer, *(pointer + 1)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

template <typename T>
template <typename U>
inline constexpr vector<2, T>::vector(const vector<4, U>& other) noexcept
    : vector{other.x, other.y}
{
}

template <typename T>
template <typename U>
inline constexpr vector<2, T>::vector(const vector<3, U>& other) noexcept
    : vector{other.x, other.y}
{
}
template <typename T>
template <typename U>
inline constexpr vector<2, T>::vector(const vector<2, U>& other) noexcept
    : vector{other.x, other.y}
{
}

/**
 * @}
 */

/**
 * @name Vector<2, T> operators.
 * @{
 */

template <typename T>
template <typename U>
inline vector<2, T>& vector<2, T>::operator=(const vector<2, U>& other) noexcept
{
    x = vector_impl::cast_to<T>::from(other.x);
    y = vector_impl::cast_to<T>::from(other.y);

    return *this;
}

// access operator
template <typename T>
inline typename vector<2, T>::value_type& vector<2, T>::operator[](unsigned int index)
{
    return data()[index];
}

template <typename T>
inline const typename vector<2, T>::value_type& vector<2, T>::operator[](unsigned int index) const
{
    return data()[index];
}

/**
 * @}
 */

/**
 * @name Vector<2, T> methods.
 * @{
 */

template <typename T>
inline constexpr unsigned int vector<2, T>::size() const noexcept
{
    return 2;
}

template <typename T>
inline typename vector<2, T>::value_type* vector<2, T>::data() noexcept
{
    return &(this->x);
}

template <typename T>
inline const typename vector<2, T>::value_type* vector<2, T>::data() const noexcept
{
    return &(this->x);
}

/**
 * @}
 */

#pragma mark - unary operators

/**
 * @name Common unary operators.
 * @{
 */

/**
 * @brief Unary minus operator.
 *
 * @param vector Vector to invert.
 *
 * @return Inverted version of vector.
 */
template <unsigned int N, typename T>
inline vector<N, T> operator-(vector<N, T> vector)
{
    return vector *= -T(1);
}

/**
 * @brief Unary plus operator.
 *
 * @param vector Vector to return.
 *
 * @return The same vector.
 */
template <unsigned int N, typename T>
inline vector<N, T> operator+(const vector<N, T>& vector)
{
    return vector;
}

/**
 * @brief Addition assignment operator.
 *
 * @param left First addend.
 * @param right Second addend.
 *
 * @return Reference to sum of two vectors.
 */
template <unsigned int N, typename T, typename U>
inline vector<N, T>& operator+=(vector<N, T>& left, const vector<N, U>& right)
{
    for (unsigned int i = 0; i < N; ++i) {
        left[i] += vector_impl::cast_to<T>::from(right[i]);
    }

    return left;
}

/**
 * @brief Subtractions assignment operator.
 *
 * @param left Vector to subtract from.
 * @param right Vector to subtract.
 *
 * @return Reference to difference of two vectors.
 */
template <unsigned int N, typename T, typename U>
inline vector<N, T>& operator-=(vector<N, T>& left, const vector<N, U>& right)
{
    for (unsigned int i = 0; i < N; ++i) {
        left[i] -= vector_impl::cast_to<T>::from(right[i]);
    }

    return left;
}

/**
 * @brief Multiplication assignment operator.
 *
 * @param left First multiplier.
 * @param right Second multiplier.
 *
 * @return Reference to product of two vectors.
 */
template <unsigned int N, typename T, typename U>
inline vector<N, T>& operator*=(vector<N, T>& left, const vector<N, U>& right)
{
    for (unsigned int i = 0; i < N; ++i) {
        left[i] *= vector_impl::cast_to<T>::from(right[i]);
    }

    return left;
}

/**
 * @brief Division assignment operator.
 *
 * @param left Dividend vector.
 * @param right Divider vector.
 *
 * @return Reference to quotient of two vectors.
 */
template <unsigned int N, typename T, typename U>
inline vector<N, T>& operator/=(vector<N, T>& left, const vector<N, U>& right)
{
    for (unsigned int i = 0; i < N; ++i) {
        left[i] /= vector_impl::cast_to<T>::from(right[i]);
    }

    return left;
}

/**
 * @brief Addition assignment operator.
 *
 * @param left First addend.
 * @param right Second addend.
 *
 * @return Reference to sum of vector and scalar value.
 */
template <unsigned int N, typename T, typename U>
inline vector<N, T>& operator+=(vector<N, T>& left, const U& right)
{
    for (unsigned int i = 0; i < N; ++i) {
        left[i] += vector_impl::cast_to<T>::from(right);
    }

    return left;
}

/**
 * @brief Subtractions assignment operator.
 *
 * @param left Vector to subtract from.
 * @param right Scalar value to subtract.
 *
 * @return Reference to difference of vector and scalar value.
 */
template <unsigned int N, typename T, typename U>
inline vector<N, T>& operator-=(vector<N, T>& left, const U& right)
{
    for (unsigned int i = 0; i < N; ++i) {
        left[i] -= vector_impl::cast_to<T>::from(right);
    }

    return left;
}

/**
 * @brief Multiplication assignment operator.
 *
 * @param left First multiplier.
 * @param right Second multiplier.
 *
 * @return Reference to product of vector and scalar value.
 */
template <unsigned int N, typename T, typename U>
inline vector<N, T>& operator*=(vector<N, T>& left, const U& right)
{
    for (unsigned int i = 0; i < N; ++i) {
        left[i] *= vector_impl::cast_to<T>::from(right);
    }

    return left;
}

/**
 * @brief Division assignment operator.
 *
 * @param left Dividend vector.
 * @param right Divider scalar value.
 *
 * @return Reference to quotient of vector and scalar value.
 */
template <unsigned int N, typename T, typename U>
inline vector<N, T>& operator/=(vector<N, T>& left, const U& right)
{
    for (unsigned int i = 0; i < N; ++i) {
        left[i] /= vector_impl::cast_to<T>::from(right);
    }

    return left;
}

/**
 * @}
 */

#pragma mark - binary operators: vector - vector

/**
 * @name Common binary operators for vector and vector.
 * @{
 */

/**
 * @brief Addition operator.
 *
 * @param left First addend.
 * @param right Second addend.
 *
 * @return Sum of two vectors.
 */
template <unsigned int N, typename T, typename U, typename R = typename std::common_type<T, U>::type>
inline const vector<N, R> operator+(const vector<N, T>& left, const vector<N, U>& right)
{
    vector<N, R> temp{left};
    return temp += right;
}

/**
 * @brief Subtraction operator.
 *
 * @param left Vector to subtract from.
 * @param right Scalar value to subtract.
 *
 * @return Difference of two vectors.
 */
template <unsigned int N, typename T, typename U, typename R = typename std::common_type<T, U>::type>
inline const vector<N, R> operator-(const vector<N, T>& left, const vector<N, U>& right)
{
    vector<N, R> temp{left};
    return temp -= right;
}

/**
 * @brief Multiplication operator.
 *
 * @param left First multiplier.
 * @param right Second multiplier.
 *
 * @return Product of two vectors.
 */

template <unsigned int N, typename T, typename U, typename R = typename std::common_type<T, U>::type>
inline const vector<N, R> operator*(const vector<N, T>& left, const vector<N, U>& right)
{
    vector<N, R> temp{left};
    return temp *= right;
}

/**
 * @brief Division operator.
 *
 * @param left Dividend vector.
 * @param right Divider vector.
 *
 * @return Quotient of two vectors.
 */

template <unsigned int N, typename T, typename U, typename R = typename std::common_type<T, U>::type>
inline const vector<N, R> operator/(const vector<N, T>& left, const vector<N, U>& right)
{
    vector<N, R> temp{left};
    return temp /= right;
}

/**
 * @}
 */

#pragma mark - binary operators: vector - scalar

/**
 * @name Common binary operators for vector and scalar.
 * @{
 */

/**
 * @brief Addition operator.
 *
 * @param left First addend.
 * @param right Second addend.
 *
 * @return Sum of vector and scalar value.
 */
template <unsigned int N, typename T, typename U, typename R = typename vector_impl::common_type<T, U>::type>
inline const vector<N, R> operator+(const vector<N, T>& left, const U& right)
{
    vector<N, R> temp{left};
    return temp += right;
}

/**
 * @brief Subtractions operator.
 *
 * @param left Vector to subtract from.
 * @param right Scalar value to subtract.
 *
 * @return Difference of vector and scalar value.
 */
template <unsigned int N, typename T, typename U, typename R = typename vector_impl::common_type<T, U>::type>
inline const vector<N, R> operator-(const vector<N, T>& left, const U& right)
{
    vector<N, R> temp{left};
    return temp -= right;
}

/**
 * @brief Multiplication operator.
 *
 * @param left First multiplier.
 * @param right Second multiplier.
 *
 * @return Product of vector and scalar value.
 */
template <unsigned int N, typename T, typename U, typename R = typename vector_impl::common_type<T, U>::type>
inline const vector<N, R> operator*(const vector<N, T>& left, const U& right)
{
    vector<N, R> temp{left};
    return temp *= right;
}

/**
 * @brief Division operator.
 *
 * @param left Dividend vector.
 * @param right Divider scalar value.
 *
 * @return Quotient of vector and scalar value.
 */
template <unsigned int N, typename T, typename U, typename R = typename vector_impl::common_type<T, U>::type>
inline const vector<N, R> operator/(const vector<N, T>& left, const U& right)
{
    vector<N, R> temp{left};
    return temp /= right;
}

/**
 * @}
 */

#pragma mark - binary operators: scalar - vector

/**
 * @name Common binary operators for scalar and vector.
 * @{
 */

/**
 * @brief Addition operator.
 *
 * @param left First addend.
 * @param right Second addend.
 *
 * @return Sum of scalar value and vector.
 */
template <unsigned int N, typename T, typename U, typename R = typename vector_impl::common_type<T, U>::type>
inline const vector<N, R> operator+(const T& left, const vector<N, U>& right)
{
    vector<N, R> temp{left};
    return temp += right;
}

/**
 * @brief Subtractions operator.
 *
 * @param left Scalar value to subtract from.
 * @param right Vector to subtract.
 *
 * @return Difference of scalar value and vector.
 */
template <unsigned int N, typename T, typename U, typename R = typename vector_impl::common_type<T, U>::type>
inline const vector<N, R> operator-(const T& left, const vector<N, U>& right)
{
    vector<N, R> temp{left};
    return temp -= right;
}

/**
 * @brief Multiplication operator.
 *
 * @param left First multiplier.
 * @param right Second multiplier.
 *
 * @return Product of scalar value and vector.
 */
template <unsigned int N, typename T, typename U, typename R = typename vector_impl::common_type<T, U>::type>
inline const vector<N, R> operator*(const T& left, const vector<N, U>& right)
{
    vector<N, R> temp{left};
    return temp *= right;
}

/**
 * @brief Division operator.
 *
 * @param left Dividend scalar value.
 * @param right Divider vector.
 *
 * @return Quotient of scalar value and vector.
 */
template <unsigned int N, typename T, typename U, typename R = typename vector_impl::common_type<T, U>::type>
inline const vector<N, R> operator/(const T& left, const vector<N, U>& right)
{
    vector<N, R> temp{left};
    return temp /= right;
}

/**
 * @}
 */

#pragma mark - vectors equality

/**
 * @name Common equality operators.
 * @{
 */

/**
 * @brief Equality operator.
 *
 * @param left Vector to test.
 * @param right Vector to test.
 *
 * @return @b true if left equals right, otherwise @b false.
 */
template <typename T>
inline constexpr bool operator==(const vector<4, T>& left, const vector<4, T>& right)
{
    const auto& abs = ::framework::math::abs<T>;
    return abs(left.x - right.x) <= 0 && abs(left.y - right.y) <= 0 && abs(left.z - right.z) <= 0 &&
           abs(left.w - right.w) <= 0;
}

/**
 * @brief Equality operator.
 *
 * @param left Vector to test.
 * @param right Vector to test.
 *
 * @return @b true if left equals right, otherwise @b false.
 */
template <typename T>
inline constexpr bool operator==(const vector<3, T>& left, const vector<3, T>& right)
{
    const auto& abs = ::framework::math::abs<T>;
    return abs(left.x - right.x) <= 0 && abs(left.y - right.y) <= 0 && abs(left.z - right.z) <= 0;
}

/**
 * @brief Equality operator.
 *
 * @param left Vector to test.
 * @param right Vector to test.
 *
 * @return @b true if left equals right, otherwise @b false.
 */
template <typename T>
inline constexpr bool operator==(const vector<2, T>& left, const vector<2, T>& right)
{
    const auto& abs = ::framework::math::abs<T>;
    return abs(left.x - right.x) <= 0 && abs(left.y - right.y) <= 0;
}

/**
 * @brief Inequality operator.
 *
 * @param left Vector to test.
 * @param right Vector to test.
 *
 * @return @b true if left isn't equal right, otherwise @b false.
 */
template <typename T>
inline constexpr bool operator!=(const vector<4, T>& left, const vector<4, T>& right)
{
    const auto& abs = ::framework::math::abs<T>;
    return abs(left.x - right.x) > 0 && abs(left.y - right.y) > 0 && abs(left.z - right.z) > 0 && abs(left.w - right.w) > 0;
}

/**
 * @brief Inequality operator.
 *
 * @param left Vector to test.
 * @param right Vector to test.
 *
 * @return @b true if left isn't equal right, otherwise @b false.
 */
template <typename T>
inline constexpr bool operator!=(const vector<3, T>& left, const vector<3, T>& right)
{
    const auto& abs = ::framework::math::abs<T>;
    return abs(left.x - right.x) > 0 && abs(left.y - right.y) > 0 && abs(left.z - right.z) > 0;
}

/**
 * @brief Inequality operator.
 *
 * @param left Vector to test.
 * @param right Vector to test.
 *
 * @return @b true if left isn't equal right, otherwise @b false.
 */
template <typename T>
inline constexpr bool operator!=(const vector<2, T>& left, const vector<2, T>& right)
{
    const auto& abs = ::framework::math::abs<T>;
    return abs(left.x - right.x) > 0 && abs(left.y - right.y);
}

/**
 * @}
 */

/**
 * @}
 */

} // namespace math

} // namespace framework

#endif
