#ifndef FRAMEWORK_MATH_INC_VECTOR_TYPE_HPP
#define FRAMEWORK_MATH_INC_VECTOR_TYPE_HPP

#ifndef FRAMEWORK_MATH_DETAILS
    #error You should include math/math.hpp instead of vector_type.hpp
#endif

#include <cassert>

#include <math/inc/vector_type_details.hpp>

namespace framework::math
{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @addtogroup math_vector_implementation
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Vector template declaration.
///
/// @see Vector<4, T>, Vector<3, T>, Vector<2, T>
template <std::size_t N, typename T>
struct Vector;

/// @brief Vector<4, T> type specialization.
///
/// @note Can be instantiated only with arithmetic type.
template <typename T>
struct Vector<4, T> final
{
    static_assert(std::is_arithmetic_v<T>, "Expected floating-point or integer type.");

    using ValueType = T; ///< Value type

    static constexpr std::size_t components_count = 4; ///< Components in vector

    /// @brief Default constructor.
    ///
    /// Initializes vector as {0, 0, 0, 1}@n
    /// For bool vector initializes as {false, false, false, false}
    constexpr Vector() noexcept;

    /// @brief Initializes vector with provided values.
    ///
    /// @param x_value Value for x component.
    /// @param y_value Value for y component.
    /// @param z_value Value for z component.
    /// @param w_value Value for w component.
    template <typename X,
              typename Y,
              typename Z,
              typename W,
              typename C = std::enable_if_t<std::is_arithmetic_v<X> && std::is_arithmetic_v<Y> &&
                                            std::is_arithmetic_v<Z> && std::is_arithmetic_v<W>>>
    constexpr Vector(const X& x_value, const Y& y_value, const Z& z_value, const W& w_value) noexcept;

    /// @brief Initializes all components of vector with same value.
    ///
    /// @param value Value for x, y, z and w components.
    template <typename U, typename C = std::enable_if_t<std::is_arithmetic_v<U>>>
    explicit constexpr Vector(const U& value) noexcept;

    /// @brief Initializes all components of vector from pointer to values.
    ///
    /// @param pointer Const pointer to values that should be taken.
    ///
    /// @warning May cause memory access error.
    explicit Vector(const ValueType* pointer);

    /// @brief Initializes vector from another one.
    ///
    /// @param other Vector to initialize x, y, z and w components.
    template <typename U>
    explicit constexpr Vector(const Vector<4, U>& other) noexcept;

    /// @brief Initializes vector from another one.
    ///
    /// @param other Vector to initialize x, y and z components.
    ///
    /// @note The w component will be initialized with default value.
    template <typename U>
    explicit constexpr Vector(const Vector<3, U>& other) noexcept;

    /// @brief Initializes vector from scalar value and other vector.
    ///
    /// @param x_value Value for x component.
    /// @param other Vector to initialize y, z and w components.
    template <typename U, typename X>
    constexpr Vector(const X& x_value, const Vector<3, U>& other) noexcept;

    /// @brief Initializes vector from vector and scalar value.
    ///
    /// @param other Vector to initialize x, y and z components.
    /// @param w_value Value for w component.
    template <typename U, typename W>
    constexpr Vector(const Vector<3, U>& other, const W& w_value) noexcept;

    /// @brief Initializes vector from other vector.
    ///
    /// @param other Vector to initialize x and y components.
    ///
    /// @note The z and y components will be initialized with default value.
    template <typename U>
    explicit constexpr Vector(const Vector<2, U>& other) noexcept;

    /// @brief Initializes vector from 2 vectors.
    ///
    /// @param first_part Vector to initialize x and y components.
    /// @param second_part Vector to initialize z and w components.
    template <typename U1, typename U2>
    constexpr Vector(const Vector<2, U1>& first_part, const Vector<2, U2>& second_part) noexcept;

    /// @brief Initializes vector from 2 scalar values and vector.
    ///
    /// @param x_value Value for x component.
    /// @param y_value Value for y component.
    /// @param other Vector to initialize z and w components.
    template <typename U, typename X, typename Y>
    constexpr Vector(const X& x_value, const Y& y_value, const Vector<2, U>& other) noexcept;

    /// @brief Initializes vector from scalar value, vector and another scalar
    /// value.
    ///
    /// @param x_value Value for x component.
    /// @param other Vector to initialize y and z components.
    /// @param w_value Value for w component.
    template <typename U, typename X, typename W>
    constexpr Vector(const X& x_value, const Vector<2, U>& other, const W& w_value) noexcept;

    /// @brief Initializes vector from vector and 2 scalar values.
    ///
    /// @param other Vector to initialize x and y components.
    /// @param z_value Value for z component.
    /// @param w_value Value for w component.
    template <typename U, typename Z, typename W>
    constexpr Vector(const Vector<2, U>& other, const Z& z_value, const W& w_value) noexcept;

    /// @brief Access operator.
    ///
    /// @param index Index of component.
    ///
    /// @return Reference to component of vector.
    ///
    /// @warning There is no size check. May cause memory access error.
    ValueType& operator[](std::size_t index);

    /// @brief Const access operator.
    ///
    /// @param index Index of component.
    ///
    /// @return Reference to constant component of vector.
    ///
    /// @warning There is no size check. May cause memory access error.
    const ValueType& operator[](std::size_t index) const;

    /// @brief Size of vector.
    ///
    /// @return Count of components in vector.
    constexpr std::size_t size() const noexcept;

    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the x component.
    ValueType* data() noexcept;

    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the x component.
    const ValueType* data() const noexcept;

    ValueType x; ///< The x component.
    ValueType y; ///< The y component.
    ValueType z; ///< The z component.
    ValueType w; ///< The w component.
};

/// @brief Vector<3, T> type specialization.
///
/// @note Can be instantiated only with arithmetic type.
template <typename T>
struct Vector<3, T> final
{
    static_assert(std::is_arithmetic_v<T>, "Expected floating-point or integer type.");

    using ValueType = T; ///< Value type

    static constexpr std::size_t components_count = 3; ///< Components in vector

    /// @brief Default constructor.
    ///
    /// Initializes vector as {0, 0, 0}
    constexpr Vector() noexcept;

    /// @brief Initializes vector with provided values.
    ///
    /// @param x_value Value for x component.
    /// @param y_value Value for y component.
    /// @param z_value Value for z component.
    template <
    typename X,
    typename Y,
    typename Z,
    typename C = std::enable_if_t<std::is_arithmetic_v<X> && std::is_arithmetic_v<Y> && std::is_arithmetic_v<Z>>>
    constexpr Vector(const X& x_value, const Y& y_value, const Z& z_value) noexcept;

    /// @brief Initializes all components of vector with same value.
    ///
    /// @param value Value for x, y and z components.
    template <typename U, typename C = std::enable_if_t<std::is_arithmetic_v<U>>>
    explicit constexpr Vector(const U& value) noexcept;

    /// @brief Initializes all components of vector from pointer to values.
    ///
    /// @param pointer Const pointer to values that should be taken.
    ///
    /// @warning May cause memory access error.
    explicit Vector(const ValueType* pointer);

    /// @brief Initializes vector from another one.
    ///
    /// @param other Vector to initialize x, y and z components.
    template <typename U>
    explicit constexpr Vector(const Vector<4, U>& other) noexcept;

    /// @brief Initializes vector from another one.
    ///
    /// @param other Vector to initialize x, y and z components.
    template <typename U>
    explicit constexpr Vector(const Vector<3, U>& other) noexcept;

    /// @brief Initializes vector from another one.
    ///
    /// @param other Vector to initialize x and y components.
    ///
    /// @note The z component will be initialized with default value.
    template <typename U>
    explicit constexpr Vector(const Vector<2, U>& other) noexcept;

    /// @brief Initializes vector from scalar value and other vector.
    ///
    /// @param x_value Value for x component.
    /// @param other Vector to initialize y and z components.
    template <typename U, typename X>
    constexpr Vector(const X& x_value, const Vector<2, U>& other) noexcept;

    /// @brief Initializes vector from vector and scalar value.
    ///
    /// @param other Vector to initialize x and y components.
    /// @param z_value Value for z component.
    template <typename U, typename Z>
    constexpr Vector(const Vector<2, U>& other, const Z& z_value) noexcept;

    /// @brief Access operator.
    ///
    /// @param index Index of component.
    ///
    /// @return Reference to component of vector.
    ///
    /// @warning There is no size check. May cause memory access error.
    ValueType& operator[](std::size_t index);

    /// @brief Const access operator.
    ///
    /// @param index Index of component.
    ///
    /// @return Reference to constant component of vector.
    ///
    /// @warning There is no size check. May cause memory access error.
    const ValueType& operator[](std::size_t index) const;

    /// @brief Size of vector.
    ///
    /// @return Count of components in vector.
    constexpr std::size_t size() const noexcept;

    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the x component.
    ValueType* data() noexcept;

    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the x component.
    const ValueType* data() const noexcept;

    ValueType x; ///< The x component.
    ValueType y; ///< The y component.
    ValueType z; ///< The z component.
};

/// @brief Vector<2, T> type specialization.
///
/// @note Can be instantiated only with arithmetic type.
template <typename T>
struct Vector<2, T> final
{
    static_assert(std::is_arithmetic_v<T>, "Expected floating-point or integer type.");

    using ValueType = T; ///< Value type

    static constexpr std::size_t components_count = 2; ///< Components in vector

    /// @brief Default constructor.
    ///
    /// Initializes vector as {0, 0}
    constexpr Vector() noexcept;

    /// @brief Initializes vector with provided values.
    ///
    /// @param x_value Value for x component.
    /// @param y_value Value for y component.
    template <typename X, typename Y, typename C = std::enable_if_t<std::is_arithmetic_v<X> && std::is_arithmetic_v<Y>>>
    constexpr Vector(const X& x_value, const Y& y_value) noexcept;

    /// @brief Initializes all components of vector with same value.
    ///
    /// @param value Value for x and y components.
    template <typename U, typename C = std::enable_if_t<std::is_arithmetic_v<U>>>
    explicit constexpr Vector(const U& value) noexcept;

    /// @brief Initializes all components of vector from pointer to values.
    ///
    /// @param pointer Const pointer to values that should be taken.
    ///
    /// @warning May cause memory access error.
    explicit Vector(const ValueType* pointer);

    /// @brief Initializes vector from another one.
    ///
    /// @param other Vector to initialize x and y components.
    template <typename U>
    explicit constexpr Vector(const Vector<4, U>& other) noexcept;

    /// @brief Initializes vector from another one.
    ///
    /// @param other Vector to initialize x and y components.
    template <typename U>
    explicit constexpr Vector(const Vector<3, U>& other) noexcept;

    /// @brief Initializes vector from another one.
    ///
    /// @param other Vector to initialize x and y components.
    template <typename U>
    explicit constexpr Vector(const Vector<2, U>& other) noexcept;

    /// @brief Access operator.
    ///
    /// @param index Index of component.
    ///
    /// @return Reference to component of vector.
    ///
    /// @warning There is no size check. May cause memory access error.
    ValueType& operator[](std::size_t index);

    /// @brief Const access operator.
    ///
    /// @param index Index of component.
    ///
    /// @return Reference to constant component of vector.
    ///
    /// @warning There is no size check. May cause memory access error.
    const ValueType& operator[](std::size_t index) const;

    /// @brief Size of vector.
    ///
    /// @return Count of components in vector.
    constexpr std::size_t size() const noexcept;

    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the x component.
    ValueType* data() noexcept;

    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the x component.
    const ValueType* data() const noexcept;

    ValueType x; ///< The x component.
    ValueType y; ///< The y component.
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name Vector<4, T> constructors.
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline constexpr Vector<4, T>::Vector() noexcept
    : x{T(0)}
    , y{T(0)}
    , z{T(0)}
    , w{std::is_same_v<T, bool> ? T(0) : T(1)}
{}

template <typename T>
template <typename X, typename Y, typename Z, typename W, typename C>

inline constexpr Vector<4, T>::Vector(const X& x_value, const Y& y_value, const Z& z_value, const W& w_value) noexcept
    : x{vector_type_details::cast_to<T>::from(x_value)}
    , y{vector_type_details::cast_to<T>::from(y_value)}
    , z{vector_type_details::cast_to<T>::from(z_value)}
    , w{vector_type_details::cast_to<T>::from(w_value)}
{}

template <typename T>
template <typename U, typename C>
inline constexpr Vector<4, T>::Vector(const U& value) noexcept
    : Vector{value, value, value, value}
{}

template <typename T>
inline Vector<4, T>::Vector(const Vector<4, T>::ValueType* pointer)
    : Vector{*pointer, *(pointer + 1), *(pointer + 2), *(pointer + 3)}
{}

template <typename T>
template <typename U>
inline constexpr Vector<4, T>::Vector(const Vector<4, U>& other) noexcept
    : Vector{other.x, other.y, other.z, other.w}
{}

template <typename T>
template <typename U>
inline constexpr Vector<4, T>::Vector(const Vector<3, U>& other) noexcept
    : Vector{other.x, other.y, other.z, std::is_same_v<T, bool> ? T(0) : T(1)}
{}

template <typename T>
template <typename U, typename X>
inline constexpr Vector<4, T>::Vector(const X& x_value, const Vector<3, U>& other) noexcept
    : Vector{x_value, other.x, other.y, other.z}
{}

template <typename T>
template <typename U, typename W>
inline constexpr Vector<4, T>::Vector(const Vector<3, U>& other, const W& w_value) noexcept
    : Vector{other.x, other.y, other.z, w_value}
{}

template <typename T>
template <typename U>
inline constexpr Vector<4, T>::Vector(const Vector<2, U>& other) noexcept
    : Vector{other.x, other.y, T(0), std::is_same_v<T, bool> ? T(0) : T(1)}
{}

template <typename T>
template <typename U1, typename U2>
inline constexpr Vector<4, T>::Vector(const Vector<2, U1>& first_part, const Vector<2, U2>& second_part) noexcept
    : Vector{first_part.x, first_part.y, second_part.x, second_part.y}
{}

template <typename T>
template <typename U, typename X, typename Y>
inline constexpr Vector<4, T>::Vector(const X& x_value, const Y& y_value, const Vector<2, U>& other) noexcept
    : Vector{x_value, y_value, other.x, other.y}
{}

template <typename T>
template <typename U, typename X, typename W>
inline constexpr Vector<4, T>::Vector(const X& x_value, const Vector<2, U>& other, const W& w_value) noexcept
    : Vector{x_value, other.x, other.y, w_value}
{}

template <typename T>
template <typename U, typename Z, typename W>
inline constexpr Vector<4, T>::Vector(const Vector<2, U>& other, const Z& z_value, const W& w_value) noexcept
    : Vector{other.x, other.y, z_value, w_value}
{}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name Vector<4, T> operators.
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline typename Vector<4, T>::ValueType& Vector<4, T>::operator[](std::size_t index)
{
    assert(index < 4);
    return data()[index];
}

template <typename T>
inline const typename Vector<4, T>::ValueType& Vector<4, T>::operator[](std::size_t index) const
{
    assert(index < 4);
    return data()[index];
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name Vector<4, T> methods.
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline constexpr std::size_t Vector<4, T>::size() const noexcept
{
    return 4;
}

template <typename T>
inline typename Vector<4, T>::ValueType* Vector<4, T>::data() noexcept
{
    return &(this->x);
}

template <typename T>
inline const typename Vector<4, T>::ValueType* Vector<4, T>::data() const noexcept
{
    return &(this->x);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name Vector<3, T> constructors.
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline constexpr Vector<3, T>::Vector() noexcept
    : x{T(0)}
    , y{T(0)}
    , z{T(0)}
{}

template <typename T>
template <typename X, typename Y, typename Z, typename C>
inline constexpr Vector<3, T>::Vector(const X& x_value, const Y& y_value, const Z& z_value) noexcept
    : x{vector_type_details::cast_to<T>::from(x_value)}
    , y{vector_type_details::cast_to<T>::from(y_value)}
    , z{vector_type_details::cast_to<T>::from(z_value)}
{}

template <typename T>
template <typename U, typename C>
inline constexpr Vector<3, T>::Vector(const U& value) noexcept
    : Vector{value, value, value}
{}

template <typename T>
inline Vector<3, T>::Vector(const Vector<3, T>::ValueType* pointer)
    : Vector{*pointer, *(pointer + 1), *(pointer + 2)}
{}

template <typename T>
template <typename U>
inline constexpr Vector<3, T>::Vector(const Vector<4, U>& other) noexcept
    : Vector{other.x, other.y, other.z}
{}

template <typename T>
template <typename U>
inline constexpr Vector<3, T>::Vector(const Vector<3, U>& other) noexcept
    : Vector{other.x, other.y, other.z}
{}

template <typename T>
template <typename U>
inline constexpr Vector<3, T>::Vector(const Vector<2, U>& other) noexcept
    : Vector{other.x, other.y, T(0)}
{}

template <typename T>
template <typename U, typename X>
inline constexpr Vector<3, T>::Vector(const X& x_value, const Vector<2, U>& other) noexcept
    : Vector{x_value, other.x, other.y}
{}

template <typename T>
template <typename U, typename Z>
inline constexpr Vector<3, T>::Vector(const Vector<2, U>& other, const Z& z_value) noexcept
    : Vector{other.x, other.y, z_value}
{}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name Vector<3, T> operators.
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline typename Vector<3, T>::ValueType& Vector<3, T>::operator[](std::size_t index)
{
    assert(index < 3);
    return data()[index];
}

template <typename T>
inline const typename Vector<3, T>::ValueType& Vector<3, T>::operator[](std::size_t index) const
{
    assert(index < 3);
    return data()[index];
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name Vector<3, T> methods.
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline constexpr std::size_t Vector<3, T>::size() const noexcept
{
    return 3;
}

template <typename T>
inline typename Vector<3, T>::ValueType* Vector<3, T>::data() noexcept
{
    return &(this->x);
}

template <typename T>
inline const typename Vector<3, T>::ValueType* Vector<3, T>::data() const noexcept
{
    return &(this->x);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name Vector<2, T> constructors.
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline constexpr Vector<2, T>::Vector() noexcept
    : x{T(0)}
    , y{T(0)}
{}

template <typename T>
template <typename X, typename Y, typename C>
inline constexpr Vector<2, T>::Vector(const X& x_value, const Y& y_value) noexcept
    : x{vector_type_details::cast_to<T>::from(x_value)}
    , y{vector_type_details::cast_to<T>::from(y_value)}
{}

template <typename T>
template <typename U, typename C>
inline constexpr Vector<2, T>::Vector(const U& value) noexcept
    : Vector{value, value}
{}

template <typename T>
inline Vector<2, T>::Vector(const typename Vector<2, T>::ValueType* pointer)
    : Vector{*pointer, *(pointer + 1)}
{}

template <typename T>
template <typename U>
inline constexpr Vector<2, T>::Vector(const Vector<4, U>& other) noexcept
    : Vector{other.x, other.y}
{}

template <typename T>
template <typename U>
inline constexpr Vector<2, T>::Vector(const Vector<3, U>& other) noexcept
    : Vector{other.x, other.y}
{}
template <typename T>
template <typename U>
inline constexpr Vector<2, T>::Vector(const Vector<2, U>& other) noexcept
    : Vector{other.x, other.y}
{}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name Vector<2, T> operators.
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline typename Vector<2, T>::ValueType& Vector<2, T>::operator[](std::size_t index)
{
    assert(index < 2);
    return data()[index];
}

template <typename T>
inline const typename Vector<2, T>::ValueType& Vector<2, T>::operator[](std::size_t index) const
{
    assert(index < 2);
    return data()[index];
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name Vector<2, T> methods.
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline constexpr std::size_t Vector<2, T>::size() const noexcept
{
    return 2;
}

template <typename T>
inline typename Vector<2, T>::ValueType* Vector<2, T>::data() noexcept
{
    return &(this->x);
}

template <typename T>
inline const typename Vector<2, T>::ValueType* Vector<2, T>::data() const noexcept
{
    return &(this->x);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name Vector operators and functions.
/// @addtogroup math_vector_implementation
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name Vector unary operators.
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Unary plus operator.
///
/// @param vector Vector to return.
///
/// @return The same vector.
template <std::size_t N, typename T>
inline constexpr Vector<N, T> operator+(const Vector<N, T>& vector) noexcept
{
    return vector;
}

/// @brief Unary minus operator.
///
/// @param vector Vector to invert.
///
/// @return Inverted version of vector.
template <typename T>
inline constexpr Vector<4, T> operator-(const Vector<4, T>& vector) noexcept
{
    return {-vector.x, -vector.y, -vector.z, -vector.w};
}

template <typename T>
inline constexpr Vector<3, T> operator-(const Vector<3, T>& vector) noexcept
{
    return {-vector.x, -vector.y, -vector.z};
}

template <typename T>
inline constexpr Vector<2, T> operator-(const Vector<2, T>& vector) noexcept
{
    return {-vector.x, -vector.y};
}

/// @brief Addition assignment operator.
///
/// @param lhs First addend.
/// @param rhs Second addend.
///
/// @return Reference to sum of two vectors.
template <typename T>
inline constexpr Vector<4, T>& operator+=(Vector<4, T>& lhs, const Vector<4, T>& rhs) noexcept
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    lhs.z += rhs.z;
    lhs.w += rhs.w;

    return lhs;
}

template <typename T>
inline constexpr Vector<3, T>& operator+=(Vector<3, T>& lhs, const Vector<3, T>& rhs) noexcept
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    lhs.z += rhs.z;

    return lhs;
}

template <typename T>
inline constexpr Vector<2, T>& operator+=(Vector<2, T>& lhs, const Vector<2, T>& rhs) noexcept
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;

    return lhs;
}

/// @brief Subtractions assignment operator.
///
/// @param lhs Vector to subtract from.
/// @param rhs Vector to subtract.
///
/// @return Reference to difference of two vectors.
template <typename T>
inline constexpr Vector<4, T>& operator-=(Vector<4, T>& lhs, const Vector<4, T>& rhs) noexcept
{
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    lhs.z -= rhs.z;
    lhs.w -= rhs.w;

    return lhs;
}

template <typename T>
inline constexpr Vector<3, T>& operator-=(Vector<3, T>& lhs, const Vector<3, T>& rhs) noexcept
{
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    lhs.z -= rhs.z;

    return lhs;
}

template <typename T>
inline constexpr Vector<2, T>& operator-=(Vector<2, T>& lhs, const Vector<2, T>& rhs) noexcept
{
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;

    return lhs;
}

/// @brief Multiplication assignment operator.
///
/// @param lhs First multiplier.
/// @param rhs Second multiplier.
///
/// @return Reference to product of two vectors.
template <typename T>
inline constexpr Vector<4, T>& operator*=(Vector<4, T>& lhs, const Vector<4, T>& rhs) noexcept
{
    lhs.x *= rhs.x;
    lhs.y *= rhs.y;
    lhs.z *= rhs.z;
    lhs.w *= rhs.w;

    return lhs;
}

template <typename T>
inline constexpr Vector<3, T>& operator*=(Vector<3, T>& lhs, const Vector<3, T>& rhs) noexcept
{
    lhs.x *= rhs.x;
    lhs.y *= rhs.y;
    lhs.z *= rhs.z;

    return lhs;
}

template <typename T>
inline constexpr Vector<2, T>& operator*=(Vector<2, T>& lhs, const Vector<2, T>& rhs) noexcept
{
    lhs.x *= rhs.x;
    lhs.y *= rhs.y;

    return lhs;
}

/// @brief Division assignment operator.
///
/// @param lhs Dividend vector.
/// @param rhs Divider vector.
///
/// @return Reference to quotient of two vectors.
template <typename T>
inline constexpr Vector<4, T>& operator/=(Vector<4, T>& lhs, const Vector<4, T>& rhs) noexcept
{
    lhs.x /= rhs.x;
    lhs.y /= rhs.y;
    lhs.z /= rhs.z;
    lhs.w /= rhs.w;

    return lhs;
}

template <typename T>
inline constexpr Vector<3, T>& operator/=(Vector<3, T>& lhs, const Vector<3, T>& rhs) noexcept
{
    lhs.x /= rhs.x;
    lhs.y /= rhs.y;
    lhs.z /= rhs.z;

    return lhs;
}

template <typename T>
inline constexpr Vector<2, T>& operator/=(Vector<2, T>& lhs, const Vector<2, T>& rhs) noexcept
{
    lhs.x /= rhs.x;
    lhs.y /= rhs.y;

    return lhs;
}

/// @brief Addition assignment operator.
///
/// @param lhs First addend.
/// @param rhs Second addend.
///
/// @return Reference to sum of vector and scalar value.
template <typename T>
inline constexpr Vector<4, T>& operator+=(Vector<4, T>& lhs, T rhs) noexcept
{
    lhs.x += rhs;
    lhs.y += rhs;
    lhs.z += rhs;
    lhs.w += rhs;

    return lhs;
}

template <typename T>
inline constexpr Vector<3, T>& operator+=(Vector<3, T>& lhs, T rhs) noexcept
{
    lhs.x += rhs;
    lhs.y += rhs;
    lhs.z += rhs;

    return lhs;
}

template <typename T>
inline constexpr Vector<2, T>& operator+=(Vector<2, T>& lhs, T rhs) noexcept
{
    lhs.x += rhs;
    lhs.y += rhs;

    return lhs;
}

/// @brief Subtractions assignment operator.
///
/// @param lhs Vector to subtract from.
/// @param rhs Scalar value to subtract.
///
/// @return Reference to difference of vector and scalar value.
template <typename T>
inline constexpr Vector<4, T>& operator-=(Vector<4, T>& lhs, T rhs) noexcept
{
    lhs.x -= rhs;
    lhs.y -= rhs;
    lhs.z -= rhs;
    lhs.w -= rhs;

    return lhs;
}

template <typename T>
inline constexpr Vector<3, T>& operator-=(Vector<3, T>& lhs, T rhs) noexcept
{
    lhs.x -= rhs;
    lhs.y -= rhs;
    lhs.z -= rhs;

    return lhs;
}

template <typename T>
inline constexpr Vector<2, T>& operator-=(Vector<2, T>& lhs, T rhs) noexcept
{
    lhs.x -= rhs;
    lhs.y -= rhs;

    return lhs;
}

/// @brief Multiplication assignment operator.
///
/// @param lhs First multiplier.
/// @param rhs Second multiplier.
///
/// @return Reference to product of vector and scalar value.
template <typename T>
inline constexpr Vector<4, T>& operator*=(Vector<4, T>& lhs, T rhs) noexcept
{
    lhs.x *= rhs;
    lhs.y *= rhs;
    lhs.z *= rhs;
    lhs.w *= rhs;

    return lhs;
}

template <typename T>
inline constexpr Vector<3, T>& operator*=(Vector<3, T>& lhs, T rhs) noexcept
{
    lhs.x *= rhs;
    lhs.y *= rhs;
    lhs.z *= rhs;

    return lhs;
}

template <typename T>
inline constexpr Vector<2, T>& operator*=(Vector<2, T>& lhs, T rhs) noexcept
{
    lhs.x *= rhs;
    lhs.y *= rhs;

    return lhs;
}

/// @brief Division assignment operator.
///
/// @param lhs Dividend vector.
/// @param rhs Divider scalar value.
///
/// @return Reference to quotient of vector and scalar value.
template <typename T>
inline constexpr Vector<4, T>& operator/=(Vector<4, T>& lhs, T rhs) noexcept
{
    lhs.x /= rhs;
    lhs.y /= rhs;
    lhs.z /= rhs;
    lhs.w /= rhs;

    return lhs;
}

template <typename T>
inline constexpr Vector<3, T>& operator/=(Vector<3, T>& lhs, T rhs) noexcept
{
    lhs.x /= rhs;
    lhs.y /= rhs;
    lhs.z /= rhs;

    return lhs;
}

template <typename T>
inline constexpr Vector<2, T>& operator/=(Vector<2, T>& lhs, T rhs) noexcept
{
    lhs.x /= rhs;
    lhs.y /= rhs;

    return lhs;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name Common binary operators for vector and vector.
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Addition operator.
///
/// @param lhs First addend.
/// @param rhs Second addend.
///
/// @return Sum of two vectors.
template <typename T, typename U, typename R = std::common_type_t<T, U>>
inline constexpr Vector<4, R> operator+(const Vector<4, T>& lhs, const Vector<4, U>& rhs) noexcept
{
    return {lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w};
}

template <typename T, typename U, typename R = std::common_type_t<T, U>>
inline constexpr Vector<3, R> operator+(const Vector<3, T>& lhs, const Vector<3, U>& rhs) noexcept
{
    return {lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z};
}

template <typename T, typename U, typename R = std::common_type_t<T, U>>
inline constexpr Vector<2, R> operator+(const Vector<2, T>& lhs, const Vector<2, U>& rhs) noexcept
{
    return {lhs.x + rhs.x, lhs.y + rhs.y};
}

/// @brief Subtraction operator.
///
/// @param lhs Vector to subtract from.
/// @param rhs Scalar value to subtract.
///
/// @return Difference of two vectors.
template <typename T, typename U, typename R = std::common_type_t<T, U>>
inline constexpr Vector<4, R> operator-(const Vector<4, T>& lhs, const Vector<4, U>& rhs) noexcept
{
    return {lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w};
}

template <typename T, typename U, typename R = std::common_type_t<T, U>>
inline constexpr Vector<3, R> operator-(const Vector<3, T>& lhs, const Vector<3, U>& rhs) noexcept
{
    return {lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z};
}

template <typename T, typename U, typename R = std::common_type_t<T, U>>
inline constexpr Vector<2, R> operator-(const Vector<2, T>& lhs, const Vector<2, U>& rhs) noexcept
{
    return {lhs.x - rhs.x, lhs.y - rhs.y};
}

/// @brief Multiplication operator.
///
/// @param lhs First multiplier.
/// @param rhs Second multiplier.
///
/// @return Product of two vectors.
template <typename T, typename U, typename R = std::common_type_t<T, U>>
inline constexpr Vector<4, R> operator*(const Vector<4, T>& lhs, const Vector<4, U>& rhs) noexcept
{
    return {lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w};
}

template <typename T, typename U, typename R = std::common_type_t<T, U>>
inline constexpr Vector<3, R> operator*(const Vector<3, T>& lhs, const Vector<3, U>& rhs) noexcept
{
    return {lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z};
}

template <typename T, typename U, typename R = std::common_type_t<T, U>>
inline constexpr Vector<2, R> operator*(const Vector<2, T>& lhs, const Vector<2, U>& rhs) noexcept
{
    return {lhs.x * rhs.x, lhs.y * rhs.y};
}

/// @brief Division operator.
///
/// @param lhs Dividend vector.
/// @param rhs Divider vector.
///
/// @return Quotient of two vectors.
template <typename T, typename U, typename R = std::common_type_t<T, U>>
inline constexpr Vector<4, R> operator/(const Vector<4, T>& lhs, const Vector<4, U>& rhs) noexcept
{
    return {lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z, lhs.w / rhs.w};
}

template <typename T, typename U, typename R = std::common_type_t<T, U>>
inline constexpr Vector<3, R> operator/(const Vector<3, T>& lhs, const Vector<3, U>& rhs) noexcept
{
    return {lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z};
}

template <typename T, typename U, typename R = std::common_type_t<T, U>>
inline constexpr Vector<2, R> operator/(const Vector<2, T>& lhs, const Vector<2, U>& rhs) noexcept
{
    return {lhs.x / rhs.x, lhs.y / rhs.y};
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name Common binary operators for vector and scalar.
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Addition operator.
///
/// @param lhs First addend.
/// @param rhs Second addend.
///
/// @return Sum of vector and scalar value.
template <typename T, typename U, typename R = std::common_type_t<T, U>>
inline constexpr Vector<4, R> operator+(const Vector<4, T>& lhs, const U& rhs) noexcept
{
    return {lhs.x + rhs, lhs.y + rhs, lhs.z + rhs, lhs.w + rhs};
}

template <typename T, typename U, typename R = std::common_type_t<T, U>>
inline constexpr Vector<3, R> operator+(const Vector<3, T>& lhs, const U& rhs) noexcept
{
    return {lhs.x + rhs, lhs.y + rhs, lhs.z + rhs};
}

template <typename T, typename U, typename R = std::common_type_t<T, U>>
inline constexpr Vector<2, R> operator+(const Vector<2, T>& lhs, const U& rhs) noexcept
{
    return {lhs.x + rhs, lhs.y + rhs};
}

/// @brief Subtractions operator.
///
/// @param lhs Vector to subtract from.
/// @param rhs Scalar value to subtract.
///
/// @return Difference of vector and scalar value.
template <typename T, typename U, typename R = std::common_type_t<T, U>>
inline constexpr Vector<4, R> operator-(const Vector<4, T>& lhs, const U& rhs) noexcept
{
    return {lhs.x - rhs, lhs.y - rhs, lhs.z - rhs, lhs.w - rhs};
}

template <typename T, typename U, typename R = std::common_type_t<T, U>>
inline constexpr Vector<3, R> operator-(const Vector<3, T>& lhs, const U& rhs) noexcept
{
    return {lhs.x - rhs, lhs.y - rhs, lhs.z - rhs};
}

template <typename T, typename U, typename R = std::common_type_t<T, U>>
inline constexpr Vector<2, R> operator-(const Vector<2, T>& lhs, const U& rhs) noexcept
{
    return {lhs.x - rhs, lhs.y - rhs};
}

/// @brief Multiplication operator.
///
/// @param lhs First multiplier.
/// @param rhs Second multiplier.
///
/// @return Product of vector and scalar value.
template <typename T, typename U, typename R = std::common_type_t<T, U>>
inline constexpr Vector<4, R> operator*(const Vector<4, T>& lhs, const U& rhs) noexcept
{
    return {lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.w * rhs};
}

template <typename T, typename U, typename R = std::common_type_t<T, U>>
inline constexpr Vector<3, R> operator*(const Vector<3, T>& lhs, const U& rhs) noexcept
{
    return {lhs.x * rhs, lhs.y * rhs, lhs.z * rhs};
}

template <typename T, typename U, typename R = std::common_type_t<T, U>>
inline constexpr Vector<2, R> operator*(const Vector<2, T>& lhs, const U& rhs) noexcept
{
    return {lhs.x * rhs, lhs.y * rhs};
}

/// @brief Division operator.
///
/// @param lhs Dividend vector.
/// @param rhs Divider scalar value.
///
/// @return Quotient of vector and scalar value.
template <typename T, typename U, typename R = std::common_type_t<T, U>>
inline constexpr Vector<4, R> operator/(const Vector<4, T>& lhs, const U& rhs) noexcept
{
    return {lhs.x / rhs, lhs.y / rhs, lhs.z / rhs, lhs.w / rhs};
}

template <typename T, typename U, typename R = std::common_type_t<T, U>>
inline constexpr Vector<3, R> operator/(const Vector<3, T>& lhs, const U& rhs) noexcept
{
    return {lhs.x / rhs, lhs.y / rhs, lhs.z / rhs};
}

template <typename T, typename U, typename R = std::common_type_t<T, U>>
inline constexpr Vector<2, R> operator/(const Vector<2, T>& lhs, const U& rhs) noexcept
{
    return {lhs.x / rhs, lhs.y / rhs};
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name Common binary operators for scalar and vector.
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Addition operator.
///
/// @param lhs First addend.
/// @param rhs Second addend.
///
/// @return Sum of scalar value and vector.
template <typename T, typename U, typename R = std::common_type_t<T, U>>
inline constexpr Vector<4, R> operator+(const T& lhs, const Vector<4, U>& rhs) noexcept
{
    return {lhs + rhs.x, lhs + rhs.y, lhs + rhs.z, lhs + rhs.w};
}

template <typename T, typename U, typename R = std::common_type_t<T, U>>
inline constexpr Vector<3, R> operator+(const T& lhs, const Vector<3, U>& rhs) noexcept
{
    return {lhs + rhs.x, lhs + rhs.y, lhs + rhs.z};
}

template <typename T, typename U, typename R = std::common_type_t<T, U>>
inline constexpr Vector<2, R> operator+(const T& lhs, const Vector<2, U>& rhs) noexcept
{
    return {lhs + rhs.x, lhs + rhs.y};
}

/// @brief Subtractions operator.
///
/// @param lhs Scalar value to subtract from.
/// @param rhs Vector to subtract.
///
/// @return Difference of scalar value and vector.
template <typename T, typename U, typename R = std::common_type_t<T, U>>
inline constexpr Vector<4, R> operator-(const T& lhs, const Vector<4, U>& rhs) noexcept
{
    return {lhs - rhs.x, lhs - rhs.y, lhs - rhs.z, lhs - rhs.w};
}

template <typename T, typename U, typename R = std::common_type_t<T, U>>
inline constexpr Vector<3, R> operator-(const T& lhs, const Vector<3, U>& rhs) noexcept
{
    return {lhs - rhs.x, lhs - rhs.y, lhs - rhs.z};
}

template <typename T, typename U, typename R = std::common_type_t<T, U>>
inline constexpr Vector<2, R> operator-(const T& lhs, const Vector<2, U>& rhs) noexcept
{
    return {lhs - rhs.x, lhs - rhs.y};
}

/// @brief Multiplication operator.
///
/// @param lhs First multiplier.
/// @param rhs Second multiplier.
///
/// @return Product of scalar value and vector.
template <typename T, typename U, typename R = std::common_type_t<T, U>>
inline constexpr Vector<4, R> operator*(const T& lhs, const Vector<4, U>& rhs) noexcept
{
    return {lhs * rhs.x, lhs * rhs.y, lhs * rhs.z, lhs * rhs.w};
}

template <typename T, typename U, typename R = std::common_type_t<T, U>>
inline constexpr Vector<3, R> operator*(const T& lhs, const Vector<3, U>& rhs) noexcept
{
    return {lhs * rhs.x, lhs * rhs.y, lhs * rhs.z};
}

template <typename T, typename U, typename R = std::common_type_t<T, U>>
inline constexpr Vector<2, R> operator*(const T& lhs, const Vector<2, U>& rhs) noexcept
{
    return {lhs * rhs.x, lhs * rhs.y};
}

/// @brief Division operator.
///
/// @param lhs Dividend scalar value.
/// @param rhs Divider vector.
///
/// @return Quotient of scalar value and vector.
template <typename T, typename U, typename R = std::common_type_t<T, U>>
inline constexpr Vector<4, R> operator/(const T& lhs, const Vector<4, U>& rhs) noexcept
{
    return {lhs / rhs.x, lhs / rhs.y, lhs / rhs.z, lhs / rhs.w};
}

template <typename T, typename U, typename R = std::common_type_t<T, U>>
inline constexpr Vector<3, R> operator/(const T& lhs, const Vector<3, U>& rhs) noexcept
{
    return {lhs / rhs.x, lhs / rhs.y, lhs / rhs.z};
}

template <typename T, typename U, typename R = std::common_type_t<T, U>>
inline constexpr Vector<2, R> operator/(const T& lhs, const Vector<2, U>& rhs) noexcept
{
    return {lhs / rhs.x, lhs / rhs.y};
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name Vector equality operators.
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Equality operator.
///
/// @param lhs Vector to test.
/// @param rhs Vector to test.
///
/// @return `true` if lhs equals rhs, otherwise `false`.
template <typename T>
inline constexpr bool operator==(const Vector<4, T>& lhs, const Vector<4, T>& rhs) noexcept
{
    using vector_type_details::equals;
    return equals(lhs.x, rhs.x) && equals(lhs.y, rhs.y) && equals(lhs.z, rhs.z) && equals(lhs.w, rhs.w);
}

/// @brief Equality operator.
///
/// @param lhs Vector to test.
/// @param rhs Vector to test.
///
/// @return `true` if lhs equals rhs, otherwise `false`.
template <typename T>
inline constexpr bool operator==(const Vector<3, T>& lhs, const Vector<3, T>& rhs) noexcept
{
    using vector_type_details::equals;
    return equals(lhs.x, rhs.x) && equals(lhs.y, rhs.y) && equals(lhs.z, rhs.z);
}

/// @brief Equality operator.
///
/// @param lhs Vector to test.
/// @param rhs Vector to test.
///
/// @return `true` if lhs equals rhs, otherwise `false`.
template <typename T>
inline constexpr bool operator==(const Vector<2, T>& lhs, const Vector<2, T>& rhs) noexcept
{
    using vector_type_details::equals;
    return equals(lhs.x, rhs.x) && equals(lhs.y, rhs.y);
}

/// @brief Inequality operator.
///
/// @param lhs Vector to test.
/// @param rhs Vector to test.
///
/// @return `true` if lhs isn't equal rhs, otherwise `false`.
template <typename T>
inline constexpr bool operator!=(const Vector<4, T>& lhs, const Vector<4, T>& rhs) noexcept
{
    using vector_type_details::equals;
    return !equals(lhs.x, rhs.x) || !equals(lhs.y, rhs.y) || !equals(lhs.z, rhs.z) || !equals(lhs.w, rhs.w);
}

/// @brief Inequality operator.
///
/// @param lhs Vector to test.
/// @param rhs Vector to test.
///
/// @return `true` if lhs isn't equal rhs, otherwise `false`.
template <typename T>
inline constexpr bool operator!=(const Vector<3, T>& lhs, const Vector<3, T>& rhs) noexcept
{
    using vector_type_details::equals;
    return !equals(lhs.x, rhs.x) || !equals(lhs.y, rhs.y) || !equals(lhs.z, rhs.z);
}

/// @brief Inequality operator.
///
/// @param lhs Vector to test.
/// @param rhs Vector to test.
///
/// @return `true` if lhs isn't equal rhs, otherwise `false`.
template <typename T>
inline constexpr bool operator!=(const Vector<2, T>& lhs, const Vector<2, T>& rhs) noexcept
{
    using vector_type_details::equals;
    return !equals(lhs.x, rhs.x) || !equals(lhs.y, rhs.y);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name Vector helper functions
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Creates new vector by applying the function to every component
/// of provided vector.
///
/// New components are computed as:
/// `x = function(value.x), y = function(value.y), ...`.
///
/// @param value Vector to transform.
/// @param function Function to apply.
///
/// @return New vector.
template <std::size_t N, typename T, typename F, typename R = std::invoke_result_t<F, const T&>>
inline constexpr Vector<N, R> transform(const Vector<N, T>& value, F&& function) noexcept
{
    return vector_type_details::transform_details<N>::template create<Vector<N, R>>(std::forward<F>(function), value);
}

/// @brief Creates new vector by applying the function to every component
/// of provided vectors.
///
/// New components are computed as:
/// `x = function(first.x, second.x), y = function(first.y, second.y), ...`.
///
/// @param first Vector to transform.
/// @param second Vector to transform.
/// @param function Function to apply.
///
/// @return New vector.
template <std::size_t N, typename T, typename U, typename F, typename R = std::invoke_result_t<F, const T&, const U&>>
inline constexpr Vector<N, R> transform(const Vector<N, T>& first, const Vector<N, U>& second, F&& function) noexcept
{
    return vector_type_details::transform_details<N>::template create<Vector<N, R>>(std::forward<F>(function),
                                                                                    first,
                                                                                    second);
}

/// @brief Helper function to print vectior into the stream.
///
/// @param ostream Output stream.
/// @param vector Vector to print.
///
/// @return Standard output stream.
template <typename S, std::size_t N, typename T>
inline S& operator<<(S& ostream, const Vector<N, T>& vector)
{
    ostream << "[";

    for (std::size_t i = 0; i < N; ++i) {
        ostream << vector[i] << (i + 1 < N ? ", " : "");
    }

    ostream << "]";
    return ostream;
}

/// @brief Helper function to swap vectiors.
///
/// @param a Vector to swap.
/// @param b Vector to swap.
template <std::size_t N, typename T>
inline void swap(Vector<N, T>& a, Vector<N, T>& b) noexcept
{
    using std::swap;

    for (std::size_t i = 0; i < N; ++i) {
        swap(a[i], b[i]);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

} // namespace framework::math

#endif
