/**
 * @file
 * @brief Implementation of geometric vector.
 * @author Fedorov Alexey
 * @date 12.03.2017
 */

#ifndef FRAMEWORK_MATH_VECTOR_TYPE_HPP
#define FRAMEWORK_MATH_VECTOR_TYPE_HPP

#include <functional>

namespace framework {

namespace math {

/**
 * @brief Contains vector type implementation details.
 */
namespace vector_details {

/**
 * @brief Workaround to cast float numbers to bool without warnings.
 * @{
 */
template <typename T>
struct cast_to
{
    /**
     * @brief Casts value to a specified type.
     */
    template <typename U, typename R = typename std::enable_if<std::is_arithmetic<U>::value, T>::type>
    inline static constexpr R from(const U& value)
    {
        return static_cast<R>(value);
    }
};

template <>
struct cast_to<bool>
{
    /**
     * @brief Casts value to a specified type.
     */
    template <typename U, typename R = typename std::enable_if<std::is_arithmetic<U>::value, bool>::type>
    inline static constexpr R from(const U& value)
    {
        return std::not_equal_to<U>()(value, U{0});
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
    /**
     * @brief `true` if all provided types are arithmetic.
     */
    static constexpr bool value = std::is_arithmetic<T>::value && are_all_arithmetic<Args...>::value;
};

template <typename T>
struct are_all_arithmetic<T>
{
    /**
     * @brief `true` if provided type are arithmetic.
     */
    static constexpr bool value = std::is_arithmetic<T>::value;
};


template <bool C, typename... Args>
struct common_type_details
{
};
/**
 * @}
 */

/**
 * @brief Helper that give common type for all presented types.
 * @{
 */
template <typename T, typename... Args>
struct common_type_details<true, T, Args...>
{
    /**
     * @brief Common type for all provided types.
     */
    using type = typename std::common_type<T, typename common_type_details<true, Args...>::type>::type;
};

template <typename T>
struct common_type_details<true, T>
{
    /**
     * @brief Common type is T.
     */
    using type = T;
};

/**
 * @brief Shortcut to get the common type.
 * Also used for SFINAE to get correct overload of vector operators.
 */
template <typename... Args>
using common_type = common_type_details<are_all_arithmetic<Args...>::value, Args...>;

/**
 * @}
 */

/**
 * @brief Implementation of transform function.
 * @{
 */
template <unsigned int N>
struct transform_details;

template <>
struct transform_details<4>
{
    /**
     * @brief Creates new vector of type R with provided function and arguments.
     */
    template <typename R, typename F, typename... Args>
    static inline constexpr R create(F&& function, Args&&... value)
    {
        return R(std::forward<F>(function)(std::forward<Args>(value).x...),
                 std::forward<F>(function)(std::forward<Args>(value).y...),
                 std::forward<F>(function)(std::forward<Args>(value).z...),
                 std::forward<F>(function)(std::forward<Args>(value).w...));
    }
};

template <>
struct transform_details<3>
{
    /**
     * @brief Creates new vector of type R with provided function and arguments.
     */
    template <typename R, typename F, typename... Args>
    static inline constexpr R create(F&& function, Args&&... value)
    {
        return R(std::forward<F>(function)(std::forward<Args>(value).x...),
                 std::forward<F>(function)(std::forward<Args>(value).y...),
                 std::forward<F>(function)(std::forward<Args>(value).z...));
    }
};

template <>
struct transform_details<2>
{
    /**
     * @brief Creates new vector of type R with provided function and arguments.
     */
    template <typename R, typename F, typename... Args>
    static inline constexpr R create(F&& function, Args&&... value)
    {
        return R(std::forward<F>(function)(std::forward<Args>(value).x...),
                 std::forward<F>(function)(std::forward<Args>(value).y...));
    }
};
/**
 * @}
 */

} // namespace vector_details

/**
 * @brief Vector type implementation.
 *
 * @defgroup vector_implementation Vector type
 * @ingroup math_module
 * @{
 */

/**
 * @brief Vector template declaration.
 *
 * @see vector<4, T>, vector<3, T>, vector<2, T>
 */
template <unsigned int N, typename T>
struct vector;

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
     *
     * @param other Vector to copy from.
     */
    constexpr vector(const vector<4, value_type>& other) noexcept;

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
     * @brief Initializes vector from another one.
     *
     * @param other Vector to initialize x, y, z and w components.
     */
    template <typename U>
    explicit constexpr vector(const vector<4, U>& other) noexcept;

    /**
     * @brief Initializes vector from another one.
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
     *
     * @param other Vector to copy from.
     *
     * @return Reference to itself.
     */
    vector<4, value_type>& operator=(const vector<4, value_type>& other) noexcept;

    /**
     * @brief Access operator.
     *
     * @param index Index of component.
     *
     * @return Reference to component of vector.
     *
     * @warning There is no size check. May cause memory access error.
     */
    value_type& operator[](unsigned int index);

    /**
     * @brief Const access operator.
     *
     * @param index Index of component.
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

    value_type x; /**< The x component. */
    value_type y; /**< The y component. */
    value_type z; /**< The z component. */
    value_type w; /**< The w component. */
};

/**
 * @brief Vector<3, T> type specialization.
 *
 * @note Can be instantiated only with arithmetic type.
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
     * @brief Default copy constructor.
     *
     * @param other Vector to copy from.
     */
    constexpr vector(const vector<3, value_type>& other) noexcept;

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
     * @brief Initializes vector from another one.
     *
     * @param other Vector to initialize x, y and z components.
     */
    template <typename U>
    explicit constexpr vector(const vector<4, U>& other) noexcept;

    /**
     * @brief Initializes vector from another one.
     *
     * @param other Vector to initialize x, y and z components.
     */
    template <typename U>
    explicit constexpr vector(const vector<3, U>& other) noexcept;

    /**
     * @brief Initializes vector from another one.
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
    constexpr vector(const vector<2, U>& other, const Z& z_value) noexcept;

    /**
     * @brief Default assignment operator.
     *
     * @param other Vector to copy from.
     *
     * @return Reference to itself.
     */
    vector<3, value_type>& operator=(const vector<3, value_type>& other) noexcept;

    /**
     * @brief Access operator.
     *
     * @param index Index of component.
     *
     * @return Reference to component of vector.
     *
     * @warning There is no size check. May cause memory access error.
     */
    value_type& operator[](unsigned int index);

    /**
     * @brief Const access operator.
     *
     * @param index Index of component.
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

    value_type x; /**< The x component. */
    value_type y; /**< The y component. */
    value_type z; /**< The z component. */
};

/**
 * @brief Vector<2, T> type specialization.
 *
 * @note Can be instantiated only with arithmetic type.
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
     * @brief Default copy constructor.
     *
     * @param other Vector to copy from.
     */
    constexpr vector(const vector<2, value_type>& other) noexcept;

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
     * @brief Initializes vector from another one.
     *
     * @param other Vector to initialize x and y components.
     */
    template <typename U>
    explicit constexpr vector(const vector<4, U>& other) noexcept;

    /**
     * @brief Initializes vector from another one.
     *
     * @param other Vector to initialize x and y components.
     */
    template <typename U>
    explicit constexpr vector(const vector<3, U>& other) noexcept;

    /**
     * @brief Initializes vector from another one.
     *
     * @param other Vector to initialize x and y components.
     */
    template <typename U>
    explicit constexpr vector(const vector<2, U>& other) noexcept;

    /**
     * @brief Default assignment operator.
     *
     * @param other Vector to copy from.
     *
     * @return Reference to itself.
     */
    vector<2, value_type>& operator=(const vector<2, value_type>& other) noexcept;

    /**
     * @brief Access operator.
     *
     * @param index Index of component.
     *
     * @return Reference to component of vector.
     *
     * @warning There is no size check. May cause memory access error.
     */
    value_type& operator[](unsigned int index);

    /**
     * @brief Const access operator.
     *
     * @param index Index of component.
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

    value_type x; /**< The x component. */
    value_type y; /**< The y component. */
};

/**
 * @}
 */

/**
 * @name vector<4, T> constructors.
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
inline constexpr vector<4, T>::vector(const vector<4, T>& other) noexcept = default;

template <typename T>
template <typename X, typename Y, typename Z, typename W>
inline constexpr vector<4, T>::vector(const X& x_value, const Y& y_value, const Z& z_value, const W& w_value) noexcept
    : x{vector_details::cast_to<T>::from(x_value)}
    , y{vector_details::cast_to<T>::from(y_value)}
    , z{vector_details::cast_to<T>::from(z_value)}
    , w{vector_details::cast_to<T>::from(w_value)}
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
 * @name vector<4, T> operators.
 * @{
 */
template <typename T>
inline vector<4, T>& vector<4, T>::operator=(const vector<4, T>&) noexcept = default;

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
 * @name vector<4, T> methods.
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

/**
 * @name vector<3, T> constructors.
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
inline constexpr vector<3, T>::vector(const vector<3, T>& other) noexcept = default;

template <typename T>
template <typename X, typename Y, typename Z>
inline constexpr vector<3, T>::vector(const X& x_value, const Y& y_value, const Z& z_value) noexcept
    : x{vector_details::cast_to<T>::from(x_value)}
    , y{vector_details::cast_to<T>::from(y_value)}
    , z{vector_details::cast_to<T>::from(z_value)}
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
 * @name vector<3, T> operators.
 * @{
 */
template <typename T>
inline vector<3, T>& vector<3, T>::operator=(const vector<3, T>&) noexcept = default;

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
 * @name vector<3, T> methods.
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

/**
 * @name vector<2, T> constructors.
 * @{
 */
template <typename T>
inline constexpr vector<2, T>::vector() noexcept
    : x{T(0)}
    , y{T(0)}
{
}

template <typename T>
inline constexpr vector<2, T>::vector(const vector<2, T>&) noexcept = default;

template <typename T>
template <typename X, typename Y>
inline constexpr vector<2, T>::vector(const X& x_value, const Y& y_value) noexcept
    : x{vector_details::cast_to<T>::from(x_value)}
    , y{vector_details::cast_to<T>::from(y_value)}
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
 * @name vector<2, T> operators.
 * @{
 */
template <typename T>
inline vector<2, T>& vector<2, T>::operator=(const vector<2, T>&) noexcept = default;

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
 * @name vector<2, T> methods.
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

/**
 * @name Vector operators and functions.
 * @addtogroup vector_implementation
 * @{
 */

/**
 * @name Common unary operators.
 * @{
 */

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
 * @brief Unary minus operator.
 *
 * @param vector Vector to invert.
 *
 * @return Inverted version of vector.
 */
template <unsigned int N, typename T>
inline vector<N, T> operator-(vector<N, T> vector)
{
    return vector *= -T{1};
}

/**
 * @brief Addition assignment operator.
 *
 * @param lhs First addend.
 * @param rhs Second addend.
 *
 * @return Reference to sum of two vectors.
 */
template <unsigned int N, typename T, typename U>
inline vector<N, T>& operator+=(vector<N, T>& lhs, const vector<N, U>& rhs)
{
    for (unsigned int i = 0; i < N; ++i) {
        lhs[i] += vector_details::cast_to<T>::from(rhs[i]);
    }

    return lhs;
}

/**
 * @brief Subtractions assignment operator.
 *
 * @param lhs Vector to subtract from.
 * @param rhs Vector to subtract.
 *
 * @return Reference to difference of two vectors.
 */
template <unsigned int N, typename T, typename U>
inline vector<N, T>& operator-=(vector<N, T>& lhs, const vector<N, U>& rhs)
{
    for (unsigned int i = 0; i < N; ++i) {
        lhs[i] -= vector_details::cast_to<T>::from(rhs[i]);
    }

    return lhs;
}

/**
 * @brief Multiplication assignment operator.
 *
 * @param lhs First multiplier.
 * @param rhs Second multiplier.
 *
 * @return Reference to product of two vectors.
 */
template <unsigned int N, typename T, typename U>
inline vector<N, T>& operator*=(vector<N, T>& lhs, const vector<N, U>& rhs)
{
    for (unsigned int i = 0; i < N; ++i) {
        lhs[i] *= vector_details::cast_to<T>::from(rhs[i]);
    }

    return lhs;
}

/**
 * @brief Division assignment operator.
 *
 * @param lhs Dividend vector.
 * @param rhs Divider vector.
 *
 * @return Reference to quotient of two vectors.
 */
template <unsigned int N, typename T, typename U>
inline vector<N, T>& operator/=(vector<N, T>& lhs, const vector<N, U>& rhs)
{
    for (unsigned int i = 0; i < N; ++i) {
        lhs[i] /= vector_details::cast_to<T>::from(rhs[i]);
    }

    return lhs;
}

/**
 * @brief Addition assignment operator.
 *
 * @param lhs First addend.
 * @param rhs Second addend.
 *
 * @return Reference to sum of vector and scalar value.
 */
template <unsigned int N, typename T, typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
inline vector<N, T>& operator+=(vector<N, T>& lhs, const U& rhs)
{
    for (unsigned int i = 0; i < N; ++i) {
        lhs[i] += vector_details::cast_to<T>::from(rhs);
    }

    return lhs;
}

/**
 * @brief Subtractions assignment operator.
 *
 * @param lhs Vector to subtract from.
 * @param rhs Scalar value to subtract.
 *
 * @return Reference to difference of vector and scalar value.
 */
template <unsigned int N, typename T, typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
inline vector<N, T>& operator-=(vector<N, T>& lhs, const U& rhs)
{
    for (unsigned int i = 0; i < N; ++i) {
        lhs[i] -= vector_details::cast_to<T>::from(rhs);
    }

    return lhs;
}

/**
 * @brief Multiplication assignment operator.
 *
 * @param lhs First multiplier.
 * @param rhs Second multiplier.
 *
 * @return Reference to product of vector and scalar value.
 */
template <unsigned int N, typename T, typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
inline vector<N, T>& operator*=(vector<N, T>& lhs, const U& rhs)
{
    for (unsigned int i = 0; i < N; ++i) {
        lhs[i] *= vector_details::cast_to<T>::from(rhs);
    }

    return lhs;
}

/**
 * @brief Division assignment operator.
 *
 * @param lhs Dividend vector.
 * @param rhs Divider scalar value.
 *
 * @return Reference to quotient of vector and scalar value.
 */
template <unsigned int N, typename T, typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
inline vector<N, T>& operator/=(vector<N, T>& lhs, const U& rhs)
{
    for (unsigned int i = 0; i < N; ++i) {
        lhs[i] /= vector_details::cast_to<T>::from(rhs);
    }

    return lhs;
}
/**
 * @}
 */

/**
 * @name Common binary operators for vector and vector.
 * @{
 */

/**
 * @brief Addition operator.
 *
 * @param lhs First addend.
 * @param rhs Second addend.
 *
 * @return Sum of two vectors.
 */
template <unsigned int N, typename T, typename U, typename R = typename vector_details::common_type<T, U>::type>
inline const vector<N, R> operator+(const vector<N, T>& lhs, const vector<N, U>& rhs)
{
    vector<N, R> temp{lhs};
    return temp += rhs;
}

/**
 * @brief Subtraction operator.
 *
 * @param lhs Vector to subtract from.
 * @param rhs Scalar value to subtract.
 *
 * @return Difference of two vectors.
 */
template <unsigned int N, typename T, typename U, typename R = typename vector_details::common_type<T, U>::type>
inline const vector<N, R> operator-(const vector<N, T>& lhs, const vector<N, U>& rhs)
{
    vector<N, R> temp{lhs};
    return temp -= rhs;
}

/**
 * @brief Multiplication operator.
 *
 * @param lhs First multiplier.
 * @param rhs Second multiplier.
 *
 * @return Product of two vectors.
 */

template <unsigned int N, typename T, typename U, typename R = typename vector_details::common_type<T, U>::type>
inline const vector<N, R> operator*(const vector<N, T>& lhs, const vector<N, U>& rhs)
{
    vector<N, R> temp{lhs};
    return temp *= rhs;
}

/**
 * @brief Division operator.
 *
 * @param lhs Dividend vector.
 * @param rhs Divider vector.
 *
 * @return Quotient of two vectors.
 */

template <unsigned int N, typename T, typename U, typename R = typename vector_details::common_type<T, U>::type>
inline const vector<N, R> operator/(const vector<N, T>& lhs, const vector<N, U>& rhs)
{
    vector<N, R> temp{lhs};
    return temp /= rhs;
}
/**
 * @}
 */

/**
 * @name Common binary operators for vector and scalar.
 * @{
 */

/**
 * @brief Addition operator.
 *
 * @param lhs First addend.
 * @param rhs Second addend.
 *
 * @return Sum of vector and scalar value.
 */
template <unsigned int N, typename T, typename U, typename R = typename vector_details::common_type<T, U>::type>
inline const vector<N, R> operator+(const vector<N, T>& lhs, const U& rhs)
{
    vector<N, R> temp{lhs};
    return temp += rhs;
}

/**
 * @brief Subtractions operator.
 *
 * @param lhs Vector to subtract from.
 * @param rhs Scalar value to subtract.
 *
 * @return Difference of vector and scalar value.
 */
template <unsigned int N, typename T, typename U, typename R = typename vector_details::common_type<T, U>::type>
inline const vector<N, R> operator-(const vector<N, T>& lhs, const U& rhs)
{
    vector<N, R> temp{lhs};
    return temp -= rhs;
}

/**
 * @brief Multiplication operator.
 *
 * @param lhs First multiplier.
 * @param rhs Second multiplier.
 *
 * @return Product of vector and scalar value.
 */
template <unsigned int N, typename T, typename U, typename R = typename vector_details::common_type<T, U>::type>
inline const vector<N, R> operator*(const vector<N, T>& lhs, const U& rhs)
{
    vector<N, R> temp{lhs};
    return temp *= rhs;
}

/**
 * @brief Division operator.
 *
 * @param lhs Dividend vector.
 * @param rhs Divider scalar value.
 *
 * @return Quotient of vector and scalar value.
 */
template <unsigned int N, typename T, typename U, typename R = typename vector_details::common_type<T, U>::type>
inline const vector<N, R> operator/(const vector<N, T>& lhs, const U& rhs)
{
    vector<N, R> temp{lhs};
    return temp /= rhs;
}
/**
 * @}
 */

/**
 * @name Common binary operators for scalar and vector.
 * @{
 */

/**
 * @brief Addition operator.
 *
 * @param lhs First addend.
 * @param rhs Second addend.
 *
 * @return Sum of scalar value and vector.
 */
template <unsigned int N, typename T, typename U, typename R = typename vector_details::common_type<T, U>::type>
inline const vector<N, R> operator+(const T& lhs, const vector<N, U>& rhs)
{
    vector<N, R> temp{lhs};
    return temp += rhs;
}

/**
 * @brief Subtractions operator.
 *
 * @param lhs Scalar value to subtract from.
 * @param rhs Vector to subtract.
 *
 * @return Difference of scalar value and vector.
 */
template <unsigned int N, typename T, typename U, typename R = typename vector_details::common_type<T, U>::type>
inline const vector<N, R> operator-(const T& lhs, const vector<N, U>& rhs)
{
    vector<N, R> temp{lhs};
    return temp -= rhs;
}

/**
 * @brief Multiplication operator.
 *
 * @param lhs First multiplier.
 * @param rhs Second multiplier.
 *
 * @return Product of scalar value and vector.
 */
template <unsigned int N, typename T, typename U, typename R = typename vector_details::common_type<T, U>::type>
inline const vector<N, R> operator*(const T& lhs, const vector<N, U>& rhs)
{
    vector<N, R> temp{lhs};
    return temp *= rhs;
}

/**
 * @brief Division operator.
 *
 * @param lhs Dividend scalar value.
 * @param rhs Divider vector.
 *
 * @return Quotient of scalar value and vector.
 */
template <unsigned int N, typename T, typename U, typename R = typename vector_details::common_type<T, U>::type>
inline const vector<N, R> operator/(const T& lhs, const vector<N, U>& rhs)
{
    vector<N, R> temp{lhs};
    return temp /= rhs;
}
/**
 * @}
 */

/**
 * @name Common equality operators.
 * @{
 */

/**
 * @brief Equality operator.
 *
 * @param lhs Vector to test.
 * @param rhs Vector to test.
 *
 * @return `true` if lhs equals rhs, otherwise `false`.
 */
template <typename T>
inline constexpr bool operator==(const vector<4, T>& lhs, const vector<4, T>& rhs)
{
    constexpr auto equal = std::equal_to<T>();
    return equal(lhs.x, rhs.x) && equal(lhs.y, rhs.y) && equal(lhs.z, rhs.z) && equal(lhs.w, rhs.w);
}

/**
 * @brief Equality operator.
 *
 * @param lhs Vector to test.
 * @param rhs Vector to test.
 *
 * @return `true` if lhs equals rhs, otherwise `false`.
 */
template <typename T>
inline constexpr bool operator==(const vector<3, T>& lhs, const vector<3, T>& rhs)
{
    constexpr auto equal = std::equal_to<T>();
    return equal(lhs.x, rhs.x) && equal(lhs.y, rhs.y) && equal(lhs.z, rhs.z);
}

/**
 * @brief Equality operator.
 *
 * @param lhs Vector to test.
 * @param rhs Vector to test.
 *
 * @return `true` if lhs equals rhs, otherwise `false`.
 */
template <typename T>
inline constexpr bool operator==(const vector<2, T>& lhs, const vector<2, T>& rhs)
{
    constexpr auto equal = std::equal_to<T>();
    return equal(lhs.x, rhs.x) && equal(lhs.y, rhs.y);
}

/**
 * @brief Inequality operator.
 *
 * @param lhs Vector to test.
 * @param rhs Vector to test.
 *
 * @return `true` if lhs isn't equal rhs, otherwise `false`.
 */
template <typename T>
inline constexpr bool operator!=(const vector<4, T>& lhs, const vector<4, T>& rhs)
{
    constexpr auto not_equal = std::not_equal_to<T>();
    return not_equal(lhs.x, rhs.x) && not_equal(lhs.y, rhs.y) && not_equal(lhs.z, rhs.z) && not_equal(lhs.w, rhs.w);
}

/**
 * @brief Inequality operator.
 *
 * @param lhs Vector to test.
 * @param rhs Vector to test.
 *
 * @return `true` if lhs isn't equal rhs, otherwise `false`.
 */
template <typename T>
inline constexpr bool operator!=(const vector<3, T>& lhs, const vector<3, T>& rhs)
{
    constexpr auto not_equal = std::not_equal_to<T>();
    return not_equal(lhs.x, rhs.x) && not_equal(lhs.y, rhs.y) && not_equal(lhs.z, rhs.z);
}

/**
 * @brief Inequality operator.
 *
 * @param lhs Vector to test.
 * @param rhs Vector to test.
 *
 * @return `true` if lhs isn't equal rhs, otherwise `false`.
 */
template <typename T>
inline constexpr bool operator!=(const vector<2, T>& lhs, const vector<2, T>& rhs)
{
    constexpr auto not_equal = std::not_equal_to<T>();
    return not_equal(lhs.x, rhs.x) && not_equal(lhs.y, rhs.y);
}
/**
 * @}
 */

/**
 * @name Helper functions
 * @{
 */

/**
 * @brief Creates new vector by applying the function to every component of provided vector.
 * New components are computed as: `x = function(value.x), y = function(value.y), ...`.
 *
 * @param value Vector to transform.
 * @param function Function to apply.
 *
 * @return New vector.
 */
template <unsigned int N, typename T, typename F, typename R = typename std::result_of<F(const T&)>::type>
inline constexpr vector<N, R> transform(const vector<N, T>& value, F&& function)
{
    return vector_details::transform_details<N>::template create<vector<N, R>>(std::forward<F>(function), value);
}

/**
 * @brief Creates new vector by applying the function to every component of provided vectors.
 * New components are computed as: `x = function(first.x, second.x), y = function(first.y, second.y), ...`.
 *
 * @param first Vector to transform.
 * @param second Vector to transform.
 * @param function Function to apply.
 *
 * @return New vector.
 */
template <unsigned int N, typename T, typename U, typename F, typename R = typename std::result_of<F(const T&, const U&)>::type>
inline constexpr vector<N, R> transform(const vector<N, T>& first, const vector<N, U>& second, F&& function)
{
    return vector_details::transform_details<N>::template create<vector<N, R>>(std::forward<F>(function), first, second);
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
