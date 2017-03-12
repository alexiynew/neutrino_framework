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
 * @brief Used to cast float numbers to boolean without warnings.
 * @{
 */
template <typename T>
struct create_value_of_type
{
    template <typename U>
    inline static constexpr T from(const U& value)
    {
        return static_cast<T>(value);
    }
};

template <>
struct create_value_of_type<bool>
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
 */
template <typename T>
struct vector<4, T> final
{
    static_assert(std::is_arithmetic<T>::value, "Expected floating-point or integer type.");
    using value_type = T;

    constexpr vector() noexcept;

    constexpr vector(const vector<4, value_type>&) noexcept = default;
    constexpr vector(vector<4, value_type>&&) noexcept      = default;

    template <typename X, typename Y, typename Z, typename W>
    constexpr vector(const X& xx, const Y& yy, const Z& zz, const W& ww) noexcept;

    template <typename U>
    explicit constexpr vector(const U& v) noexcept;

    template <typename U>
    explicit constexpr vector(const U* const p) noexcept;

    template <typename U>
    explicit constexpr vector(const vector<4, U>& v) noexcept;

    template <typename U>
    explicit constexpr vector(const vector<3, U>& v) noexcept;

    template <typename U, typename S>
    constexpr vector(const S& s, const vector<3, U>& v) noexcept;

    template <typename U, typename S>
    constexpr vector(const vector<3, U>& v, const S& s) noexcept;

    template <typename U>
    explicit constexpr vector(const vector<2, U>& v) noexcept;

    template <typename U1, typename U2>
    constexpr vector(const vector<2, U1>& v1, const vector<2, U2>& v2) noexcept;

    template <typename U, typename S1, typename S2>
    constexpr vector(const S1& xx, const S2& yy, const vector<2, U>& v) noexcept;

    template <typename U, typename S1, typename S2>
    constexpr vector(const S1& xx, const vector<2, U>& v, const S2& ww) noexcept;

    template <typename U, typename S1, typename S2>
    constexpr vector(const vector<2, U>& v, const S1& zz, const S2& ww) noexcept;

    vector<4, value_type>& operator=(const vector<4, value_type>&) noexcept = default;
    vector<4, value_type>& operator=(vector<4, value_type>&&) noexcept = default;

    template <typename U>
    vector<4, value_type>& operator=(const vector<4, U>& other) noexcept;

    value_type& operator[](unsigned int index);
    const value_type& operator[](unsigned int index) const;

    constexpr unsigned int size() const noexcept;

    value_type* data() noexcept;
    const value_type* data() const noexcept;

    T x, y, z, w;
};

#pragma mark - vector<3, T> type specialization

/**
 * @brief Vector<3, T> type specialization.
 */
template <typename T>
struct vector<3, T> final
{
    static_assert(std::is_arithmetic<T>::value, "Expected floating-point or integer type.");
    using value_type = T;

    constexpr vector() noexcept;

    constexpr vector(const vector<3, value_type>&) noexcept = default;
    constexpr vector(vector<3, value_type>&&) noexcept      = default;

    template <typename X, typename Y, typename Z>
    constexpr vector(const X& xx, const Y& yy, const Z& zz) noexcept;

    template <typename U>
    explicit constexpr vector(const U& v) noexcept;

    template <typename U>
    explicit constexpr vector(const U* const p) noexcept;

    template <typename U>
    explicit constexpr vector(const vector<4, U>& v) noexcept;

    template <typename U>
    explicit constexpr vector(const vector<3, U>& v) noexcept;

    template <typename U>
    explicit constexpr vector(const vector<2, U>& v) noexcept;

    template <typename U, typename S>
    constexpr vector(const S& xx, const vector<2, U>& v) noexcept;

    template <typename U, typename S>
    constexpr vector(const vector<2, U>& v, const S& zz) noexcept;

    vector<3, value_type>& operator=(const vector<3, value_type>&) noexcept = default;
    vector<3, value_type>& operator=(vector<3, value_type>&&) noexcept = default;

    template <typename U>
    vector<3, value_type>& operator=(const vector<3, U>& other) noexcept;

    value_type& operator[](unsigned int index);
    const value_type& operator[](unsigned int index) const;

    constexpr unsigned int size() const noexcept;

    value_type* data() noexcept;
    const value_type* data() const noexcept;

    T x, y, z;
};

#pragma mark - vector<2, T> type specialization

/**
 * @brief Vector<2, T> type specialization.
 */
template <typename T>
struct vector<2, T> final
{
    static_assert(std::is_arithmetic<T>::value, "Expected floating-point or integer type.");
    using value_type = T;

    constexpr vector() noexcept;

    constexpr vector(const vector<2, value_type>&) noexcept = default;
    constexpr vector(vector<2, value_type>&&) noexcept      = default;

    template <typename X, typename Y>
    constexpr vector(const X& xx, const Y& yy) noexcept;

    template <typename U>
    explicit constexpr vector(const U& v) noexcept;

    template <typename U>
    explicit constexpr vector(const U* p) noexcept;

    template <typename U>
    explicit constexpr vector(const vector<4, U>& v) noexcept;

    template <typename U>
    explicit constexpr vector(const vector<3, U>& v) noexcept;

    template <typename U>
    explicit constexpr vector(const vector<2, U>& v) noexcept;

    vector<2, value_type>& operator=(const vector<2, value_type>&) noexcept = default;
    vector<2, value_type>& operator=(vector<2, value_type>&&) noexcept = default;

    template <typename U>
    vector<2, value_type>& operator=(const vector<2, U>& other) noexcept;

    value_type& operator[](unsigned int index);
    const value_type& operator[](unsigned int index) const;

    constexpr unsigned int size() const noexcept;

    value_type* data() noexcept;
    const value_type* data() const noexcept;

    T x, y;
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
inline constexpr vector<4, T>::vector() noexcept : x{T(0)},
                                                   y{T(0)},
                                                   z{T(0)},
                                                   w{T(static_cast<T>(not std::is_same<T, bool>::value))}
{
}

template <typename T>
template <typename X, typename Y, typename Z, typename W>
inline constexpr vector<4, T>::vector(const X& xx, const Y& yy, const Z& zz, const W& ww) noexcept
: x{vector_impl::create_value_of_type<T>::from(xx)},
  y{vector_impl::create_value_of_type<T>::from(yy)},
  z{vector_impl::create_value_of_type<T>::from(zz)},
  w{vector_impl::create_value_of_type<T>::from(ww)}
{
}

template <typename T>
template <typename U>
inline constexpr vector<4, T>::vector(const U& v) noexcept : vector{v, v, v, v}
{
}

template <typename T>
template <typename U>
inline constexpr vector<4, T>::vector(const U* const p) noexcept : vector{*p, *(p + 1), *(p + 2), *(p + 3)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}


template <typename T>
template <typename U>
inline constexpr vector<4, T>::vector(const vector<4, U>& v) noexcept : vector{v.x, v.y, v.z, v.w}
{
}

template <typename T>
template <typename U>
inline constexpr vector<4, T>::vector(const vector<3, U>& v) noexcept
: vector{v.x, v.y, v.z, static_cast<T>(not std::is_same<T, bool>::value)}
// TODO add test for this
{
}

template <typename T>
template <typename U, typename S>
inline constexpr vector<4, T>::vector(const S& s, const vector<3, U>& v) noexcept : vector{s, v.x, v.y, v.z}
{
}

template <typename T>
template <typename U, typename S>
inline constexpr vector<4, T>::vector(const vector<3, U>& v, const S& s) noexcept : vector{v.x, v.y, v.z, s}
{
}

template <typename T>
template <typename U>
inline constexpr vector<4, T>::vector(const vector<2, U>& v) noexcept
: vector{v.x, v.y, T(0), static_cast<T>(not std::is_same<T, bool>::value)}
// TODO add test for this
{
}

template <typename T>
template <typename U1, typename U2>
inline constexpr vector<4, T>::vector(const vector<2, U1>& v1, const vector<2, U2>& v2) noexcept
: vector{v1.x, v1.y, v2.x, v2.y}
{
}

template <typename T>
template <typename U, typename S1, typename S2>
inline constexpr vector<4, T>::vector(const S1& xx, const S2& yy, const vector<2, U>& v) noexcept
: vector{xx, yy, v.x, v.y}
{
}

template <typename T>
template <typename U, typename S1, typename S2>
inline constexpr vector<4, T>::vector(const S1& xx, const vector<2, U>& v, const S2& ww) noexcept : vector{xx, v.x, v.y, ww}
{
}

template <typename T>
template <typename U, typename S1, typename S2>
inline constexpr vector<4, T>::vector(const vector<2, U>& v, const S1& zz, const S2& ww) noexcept : vector{v.x, v.y, zz, ww}
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
    x = vector_impl::create_value_of_type<T>::from(other.x);
    y = vector_impl::create_value_of_type<T>::from(other.y);
    z = vector_impl::create_value_of_type<T>::from(other.z);
    w = vector_impl::create_value_of_type<T>::from(other.w);

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
inline constexpr vector<3, T>::vector() noexcept : x{T(0)}, y{T(0)}, z{T(0)}
{
}

template <typename T>
template <typename X, typename Y, typename Z>
inline constexpr vector<3, T>::vector(const X& xx, const Y& yy, const Z& zz) noexcept
: x{vector_impl::create_value_of_type<T>::from(xx)},
  y{vector_impl::create_value_of_type<T>::from(yy)},
  z{vector_impl::create_value_of_type<T>::from(zz)}
{
}

template <typename T>
template <typename U>
inline constexpr vector<3, T>::vector(const U& v) noexcept : vector{v, v, v}
{
}

template <typename T>
template <typename U>
inline constexpr vector<3, T>::vector(const U* const p) noexcept : vector{*p, *(p + 1), *(p + 2)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

template <typename T>
template <typename U>
inline constexpr vector<3, T>::vector(const vector<4, U>& v) noexcept : vector{v.x, v.y, v.z}
{
}

template <typename T>
template <typename U>
inline constexpr vector<3, T>::vector(const vector<3, U>& v) noexcept : vector{v.x, v.y, v.z}
{
}

template <typename T>
template <typename U>
inline constexpr vector<3, T>::vector(const vector<2, U>& v) noexcept : vector{v.x, v.y, T(0)}
{
}

template <typename T>
template <typename U, typename S>
inline constexpr vector<3, T>::vector(const S& xx, const vector<2, U>& v) noexcept : vector{xx, v.x, v.y}
{
}

template <typename T>
template <typename U, typename S>
inline constexpr vector<3, T>::vector(const vector<2, U>& v, const S& zz) noexcept : vector{v.x, v.y, zz}
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
    x = vector_impl::create_value_of_type<T>::from(other.x);
    y = vector_impl::create_value_of_type<T>::from(other.y);
    z = vector_impl::create_value_of_type<T>::from(other.z);

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
inline constexpr vector<2, T>::vector() noexcept : x{T(0)}, y{T(0)}
{
}

template <typename T>
template <typename X, typename Y>
inline constexpr vector<2, T>::vector(const X& xx, const Y& yy) noexcept
: x{vector_impl::create_value_of_type<T>::from(xx)},
  y{vector_impl::create_value_of_type<T>::from(yy)}
{
}

template <typename T>
template <typename U>
inline constexpr vector<2, T>::vector(const U& v) noexcept : vector{v, v}
{
}

template <typename T>
template <typename U>
inline constexpr vector<2, T>::vector(const U* p) noexcept : vector{*p, *(p + 1)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

template <typename T>
template <typename U>
inline constexpr vector<2, T>::vector(const vector<4, U>& v) noexcept : vector{v.x, v.y}
{
}

template <typename T>
template <typename U>
inline constexpr vector<2, T>::vector(const vector<3, U>& v) noexcept : vector{v.x, v.y}
{
}
template <typename T>
template <typename U>
inline constexpr vector<2, T>::vector(const vector<2, U>& v) noexcept : vector{v.x, v.y}
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
    x = vector_impl::create_value_of_type<T>::from(other.x);
    y = vector_impl::create_value_of_type<T>::from(other.y);

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

template <unsigned int N, typename T>
inline vector<N, T> operator-(vector<N, T> vector)
{
    return vector *= -T(1);
}

template <unsigned int N, typename T>
inline vector<N, T> operator+(const vector<N, T>& vector)
{
    return vector;
}

template <unsigned int N, typename T, typename U>
inline vector<N, T>& operator+=(vector<N, T>& lhs, const vector<N, U>& rhs)
{
    for (unsigned int i = 0; i < N; ++i) {
        lhs[i] += vector_impl::create_value_of_type<T>::from(rhs[i]);
    }

    return lhs;
}

template <unsigned int N, typename T, typename U>
inline vector<N, T>& operator-=(vector<N, T>& lhs, const vector<N, U>& rhs)
{
    for (unsigned int i = 0; i < N; ++i) {
        lhs[i] -= vector_impl::create_value_of_type<T>::from(rhs[i]);
    }

    return lhs;
}

template <unsigned int N, typename T, typename U>
inline vector<N, T>& operator*=(vector<N, T>& lhs, const vector<N, U>& rhs)
{
    for (unsigned int i = 0; i < N; ++i) {
        lhs[i] *= vector_impl::create_value_of_type<T>::from(rhs[i]);
    }

    return lhs;
}

template <unsigned int N, typename T, typename U>
inline vector<N, T>& operator/=(vector<N, T>& lhs, const vector<N, U>& rhs)
{
    for (unsigned int i = 0; i < N; ++i) {
        lhs[i] /= vector_impl::create_value_of_type<T>::from(rhs[i]);
    }

    return lhs;
}


template <unsigned int N, typename T, typename U>
inline vector<N, T>& operator+=(vector<N, T>& lhs, const U& rhs)
{
    for (unsigned int i = 0; i < N; ++i) {
        lhs[i] += vector_impl::create_value_of_type<T>::from(rhs);
    }

    return lhs;
}

template <unsigned int N, typename T, typename U>
inline vector<N, T>& operator-=(vector<N, T>& lhs, const U& rhs)
{
    for (unsigned int i = 0; i < N; ++i) {
        lhs[i] -= vector_impl::create_value_of_type<T>::from(rhs);
    }

    return lhs;
}

template <unsigned int N, typename T, typename U>
inline vector<N, T>& operator*=(vector<N, T>& lhs, const U& rhs)
{
    for (unsigned int i = 0; i < N; ++i) {
        lhs[i] *= vector_impl::create_value_of_type<T>::from(rhs);
    }

    return lhs;
}

template <unsigned int N, typename T, typename U>
inline vector<N, T>& operator/=(vector<N, T>& lhs, const U& rhs)
{
    for (unsigned int i = 0; i < N; ++i) {
        lhs[i] /= vector_impl::create_value_of_type<T>::from(rhs);
    }

    return lhs;
}

/**
 * @}
 */

#pragma mark - binary operators: vector - vector

/**
 * @name Common binary operators for vector and vector.
 * @{
 */

template <unsigned int N, typename T>
inline const vector<N, T> operator+(vector<N, T> lhs, const vector<N, T>& rhs)
{
    return lhs += rhs;
}

template <unsigned int N, typename T>
inline const vector<N, T> operator-(vector<N, T> lhs, const vector<N, T>& rhs)
{
    return lhs -= rhs;
}

template <unsigned int N, typename T>
inline const vector<N, T> operator*(vector<N, T> lhs, const vector<N, T>& rhs)
{
    return lhs *= rhs;
}

template <unsigned int N, typename T>
inline const vector<N, T> operator/(vector<N, T> lhs, const vector<N, T>& rhs)
{
    return lhs /= rhs;
}

/**
 * @}
 */

#pragma mark - binary operators: vector - scalar

/**
 * @name Common binary operators for vector and scalar.
 * @{
 */

template <unsigned int N, typename T>
inline const vector<N, T> operator+(vector<N, T> v, const T& scalar)
{
    return v += scalar;
}

template <unsigned int N, typename T>
inline const vector<N, T> operator-(vector<N, T> v, const T& scalar)
{
    return v -= scalar;
}

template <unsigned int N, typename T>
inline const vector<N, T> operator*(vector<N, T> v, const T& scalar)
{
    return v *= scalar;
}

template <unsigned int N, typename T>
inline const vector<N, T> operator/(vector<N, T> v, const T& scalar)
{
    return v /= scalar;
}

/**
 * @}
 */

#pragma mark - binary operators: scalar - vector

/**
 * @name Common binary operators for scalar and vector.
 * @{
 */

template <unsigned int N, typename T>
inline const vector<N, T> operator+(const T& scalar, const vector<N, T>& v)
{
    vector<N, T> tmp{scalar};
    return tmp += v;
}

template <unsigned int N, typename T>
inline const vector<N, T> operator-(const T& scalar, const vector<N, T>& v)
{
    vector<N, T> tmp{scalar};
    return tmp -= v;
}

template <unsigned int N, typename T>
inline const vector<N, T> operator*(const T& scalar, const vector<N, T>& v)
{
    vector<N, T> tmp{scalar};
    return tmp *= v;
}

template <unsigned int N, typename T>
inline const vector<N, T> operator/(const T& scalar, const vector<N, T>& v)
{
    vector<N, T> tmp{scalar};
    return tmp /= v;
}

/**
 * @}
 */

#pragma mark - vectors equality

/**
 * @name Common equality operators.
 * @{
 */

template <typename T>
inline constexpr bool operator==(const vector<4, T>& a, const vector<4, T>& b)
{
    const auto& abs = ::framework::math::abs<T>;
    return abs(a.x - b.x) <= 0 && abs(a.y - b.y) <= 0 && abs(a.z - b.z) <= 0 && abs(a.w - b.w) <= 0;
}

template <typename T>
inline constexpr bool operator==(const vector<3, T>& a, const vector<3, T>& b)
{
    const auto& abs = ::framework::math::abs<T>;
    return abs(a.x - b.x) <= 0 && abs(a.y - b.y) <= 0 && abs(a.z - b.z) <= 0;
}

template <typename T>
inline constexpr bool operator==(const vector<2, T>& a, const vector<2, T>& b)
{
    const auto& abs = ::framework::math::abs<T>;
    return abs(a.x - b.x) <= 0 && abs(a.y - b.y) <= 0;
}

template <typename T>
inline constexpr bool operator!=(const vector<4, T>& a, const vector<4, T>& b)
{
    const auto& abs = ::framework::math::abs<T>;
    return abs(a.x - b.x) > 0 && abs(a.y - b.y) > 0 && abs(a.z - b.z) > 0 && abs(a.w - b.w) > 0;
}

template <typename T>
inline constexpr bool operator!=(const vector<3, T>& a, const vector<3, T>& b)
{
    const auto& abs = ::framework::math::abs<T>;
    return abs(a.x - b.x) > 0 && abs(a.y - b.y) > 0 && abs(a.z - b.z) > 0;
}

template <typename T>
inline constexpr bool operator!=(const vector<2, T>& a, const vector<2, T>& b)
{
    const auto& abs = ::framework::math::abs<T>;
    return abs(a.x - b.x) > 0 && abs(a.y - b.y);
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
