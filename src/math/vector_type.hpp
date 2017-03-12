#ifndef FRAMEWORK_MATH_VECTOR_TYPE_HPP
#define FRAMEWORK_MATH_VECTOR_TYPE_HPP

#include <math/common_func.hpp>

namespace framework {

namespace math {

namespace vector_impl {

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

#pragma mark - Vector template declaration

template <unsigned int N, typename T>
struct Vector;

#pragma mark - Vector<4, T> type specialization

template <typename T>
struct Vector<4, T> final
{
    static_assert(std::is_arithmetic<T>::value, "Expected floating-point or integer type.");
    using value_type = T;

    constexpr Vector() noexcept;

    constexpr Vector(const Vector<4, value_type>&) noexcept = default;
    constexpr Vector(Vector<4, value_type>&&) noexcept      = default;

    template <typename X, typename Y, typename Z, typename W>
    constexpr Vector(const X& xx, const Y& yy, const Z& zz, const W& ww) noexcept;

    template <typename U>
    explicit constexpr Vector(const U& v) noexcept;

    template <typename U>
    explicit constexpr Vector(const U* const p) noexcept;

    template <typename U>
    explicit constexpr Vector(const Vector<4, U>& v) noexcept;

    template <typename U>
    explicit constexpr Vector(const Vector<3, U>& v) noexcept;

    template <typename U, typename S>
    constexpr Vector(const S& s, const Vector<3, U>& v) noexcept;

    template <typename U, typename S>
    constexpr Vector(const Vector<3, U>& v, const S& s) noexcept;

    template <typename U>
    explicit constexpr Vector(const Vector<2, U>& v) noexcept;

    template <typename U1, typename U2>
    constexpr Vector(const Vector<2, U1>& v1, const Vector<2, U2>& v2) noexcept;

    template <typename U, typename S1, typename S2>
    constexpr Vector(const S1& xx, const S2& yy, const Vector<2, U>& v) noexcept;

    template <typename U, typename S1, typename S2>
    constexpr Vector(const S1& xx, const Vector<2, U>& v, const S2& ww) noexcept;

    template <typename U, typename S1, typename S2>
    constexpr Vector(const Vector<2, U>& v, const S1& zz, const S2& ww) noexcept;

    Vector<4, value_type>& operator=(const Vector<4, value_type>&) noexcept = default;
    Vector<4, value_type>& operator=(Vector<4, value_type>&&) noexcept = default;

    template <typename U>
    Vector<4, value_type>& operator=(const Vector<4, U>& other) noexcept;

    value_type& operator[](unsigned int index);
    const value_type& operator[](unsigned int index) const;

    constexpr unsigned int size() const noexcept;

    value_type* data() noexcept;
    const value_type* data() const noexcept;

    T x, y, z, w;
};


#pragma mark - Vector<3, T> type specialization

template <typename T>
struct Vector<3, T> final
{
    static_assert(std::is_arithmetic<T>::value, "Expected floating-point or integer type.");
    using value_type = T;

    constexpr Vector() noexcept;

    constexpr Vector(const Vector<3, value_type>&) noexcept = default;
    constexpr Vector(Vector<3, value_type>&&) noexcept      = default;

    template <typename X, typename Y, typename Z>
    constexpr Vector(const X& xx, const Y& yy, const Z& zz) noexcept;

    template <typename U>
    explicit constexpr Vector(const U& v) noexcept;

    template <typename U>
    explicit constexpr Vector(const U* const p) noexcept;

    template <typename U>
    explicit constexpr Vector(const Vector<4, U>& v) noexcept;

    template <typename U>
    explicit constexpr Vector(const Vector<3, U>& v) noexcept;

    template <typename U>
    explicit constexpr Vector(const Vector<2, U>& v) noexcept;

    template <typename U, typename S>
    constexpr Vector(const S& xx, const Vector<2, U>& v) noexcept;

    template <typename U, typename S>
    constexpr Vector(const Vector<2, U>& v, const S& zz) noexcept;

    Vector<3, value_type>& operator=(const Vector<3, value_type>&) noexcept = default;
    Vector<3, value_type>& operator=(Vector<3, value_type>&&) noexcept = default;

    template <typename U>
    Vector<3, value_type>& operator=(const Vector<3, U>& other) noexcept;

    value_type& operator[](unsigned int index);
    const value_type& operator[](unsigned int index) const;

    constexpr unsigned int size() const noexcept;

    value_type* data() noexcept;
    const value_type* data() const noexcept;

    T x, y, z;
};

#pragma mark - Vector<2, T> type specialization

template <typename T>
struct Vector<2, T> final
{
    static_assert(std::is_arithmetic<T>::value, "Expected floating-point or integer type.");
    using value_type = T;

    constexpr Vector() noexcept;

    constexpr Vector(const Vector<2, value_type>&) noexcept = default;
    constexpr Vector(Vector<2, value_type>&&) noexcept      = default;

    template <typename X, typename Y>
    constexpr Vector(const X& xx, const Y& yy) noexcept;

    template <typename U>
    explicit constexpr Vector(const U& v) noexcept;

    template <typename U>
    explicit constexpr Vector(const U* p) noexcept;

    template <typename U>
    explicit constexpr Vector(const Vector<4, U>& v) noexcept;

    template <typename U>
    explicit constexpr Vector(const Vector<3, U>& v) noexcept;

    template <typename U>
    explicit constexpr Vector(const Vector<2, U>& v) noexcept;

    Vector<2, value_type>& operator=(const Vector<2, value_type>&) noexcept = default;
    Vector<2, value_type>& operator=(Vector<2, value_type>&&) noexcept = default;

    template <typename U>
    Vector<2, value_type>& operator=(const Vector<2, U>& other) noexcept;

    value_type& operator[](unsigned int index);
    const value_type& operator[](unsigned int index) const;

    constexpr unsigned int size() const noexcept;

    value_type* data() noexcept;
    const value_type* data() const noexcept;

    T x, y;
};

#pragma mark - Vector<4, T> implementation

// constructors
template <typename T>
inline constexpr Vector<4, T>::Vector() noexcept : x{T(0)},
                                                   y{T(0)},
                                                   z{T(0)},
                                                   w{T(static_cast<T>(not std::is_same<T, bool>::value))}
{
}

template <typename T>
template <typename X, typename Y, typename Z, typename W>
inline constexpr Vector<4, T>::Vector(const X& xx, const Y& yy, const Z& zz, const W& ww) noexcept
: x{create_value_of_type<T>::from(xx)},
  y{create_value_of_type<T>::from(yy)},
  z{create_value_of_type<T>::from(zz)},
  w{create_value_of_type<T>::from(ww)}
{
}

template <typename T>
template <typename U>
inline constexpr Vector<4, T>::Vector(const U& v) noexcept : Vector{v, v, v, v}
{
}

template <typename T>
template <typename U>
inline constexpr Vector<4, T>::Vector(const U* const p) noexcept : Vector{*p, *(p + 1), *(p + 2), *(p + 3)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}


template <typename T>
template <typename U>
inline constexpr Vector<4, T>::Vector(const Vector<4, U>& v) noexcept : Vector{v.x, v.y, v.z, v.w}
{
}

template <typename T>
template <typename U>
inline constexpr Vector<4, T>::Vector(const Vector<3, U>& v) noexcept
: Vector{v.x, v.y, v.z, static_cast<T>(not std::is_same<T, bool>::value)}
// TODO add test for this
{
}

template <typename T>
template <typename U, typename S>
inline constexpr Vector<4, T>::Vector(const S& s, const Vector<3, U>& v) noexcept : Vector{s, v.x, v.y, v.z}
{
}

template <typename T>
template <typename U, typename S>
inline constexpr Vector<4, T>::Vector(const Vector<3, U>& v, const S& s) noexcept : Vector{v.x, v.y, v.z, s}
{
}

template <typename T>
template <typename U>
inline constexpr Vector<4, T>::Vector(const Vector<2, U>& v) noexcept
: Vector{v.x, v.y, T(0), static_cast<T>(not std::is_same<T, bool>::value)}
// TODO add test for this
{
}

template <typename T>
template <typename U1, typename U2>
inline constexpr Vector<4, T>::Vector(const Vector<2, U1>& v1, const Vector<2, U2>& v2) noexcept
: Vector{v1.x, v1.y, v2.x, v2.y}
{
}

template <typename T>
template <typename U, typename S1, typename S2>
inline constexpr Vector<4, T>::Vector(const S1& xx, const S2& yy, const Vector<2, U>& v) noexcept
: Vector{xx, yy, v.x, v.y}
{
}

template <typename T>
template <typename U, typename S1, typename S2>
inline constexpr Vector<4, T>::Vector(const S1& xx, const Vector<2, U>& v, const S2& ww) noexcept : Vector{xx, v.x, v.y, ww}
{
}

template <typename T>
template <typename U, typename S1, typename S2>
inline constexpr Vector<4, T>::Vector(const Vector<2, U>& v, const S1& zz, const S2& ww) noexcept : Vector{v.x, v.y, zz, ww}
{
}

// operators
template <typename T>
template <typename U>
inline Vector<4, T>& Vector<4, T>::operator=(const Vector<4, U>& other) noexcept
{
    x = create_value_of_type<T>::from(other.x);
    y = create_value_of_type<T>::from(other.y);
    z = create_value_of_type<T>::from(other.z);
    w = create_value_of_type<T>::from(other.w);

    return *this;
}

// access operator
template <typename T>
inline typename Vector<4, T>::value_type& Vector<4, T>::operator[](unsigned int index)
{
    return data()[index];
}

template <typename T>
inline const typename Vector<4, T>::value_type& Vector<4, T>::operator[](unsigned int index) const
{
    return data()[index];
}

// methods
template <typename T>
inline constexpr unsigned int Vector<4, T>::size() const noexcept
{
    return 4;
}

template <typename T>
inline typename Vector<4, T>::value_type* Vector<4, T>::data() noexcept
{
    return &(this->x);
}

template <typename T>
inline const typename Vector<4, T>::value_type* Vector<4, T>::data() const noexcept
{
    return &(this->x);
}

#pragma mark - Vector<3, T> implementation

// constructors
template <typename T>
inline constexpr Vector<3, T>::Vector() noexcept : x{T(0)}, y{T(0)}, z{T(0)}
{
}

template <typename T>
template <typename X, typename Y, typename Z>
inline constexpr Vector<3, T>::Vector(const X& xx, const Y& yy, const Z& zz) noexcept
: x{create_value_of_type<T>::from(xx)},
  y{create_value_of_type<T>::from(yy)},
  z{create_value_of_type<T>::from(zz)}
{
}

template <typename T>
template <typename U>
inline constexpr Vector<3, T>::Vector(const U& v) noexcept : Vector{v, v, v}
{
}

template <typename T>
template <typename U>
inline constexpr Vector<3, T>::Vector(const U* const p) noexcept : Vector{*p, *(p + 1), *(p + 2)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

template <typename T>
template <typename U>
inline constexpr Vector<3, T>::Vector(const Vector<4, U>& v) noexcept : Vector{v.x, v.y, v.z}
{
}

template <typename T>
template <typename U>
inline constexpr Vector<3, T>::Vector(const Vector<3, U>& v) noexcept : Vector{v.x, v.y, v.z}
{
}

template <typename T>
template <typename U>
inline constexpr Vector<3, T>::Vector(const Vector<2, U>& v) noexcept : Vector{v.x, v.y, T(0)}
{
}

template <typename T>
template <typename U, typename S>
inline constexpr Vector<3, T>::Vector(const S& xx, const Vector<2, U>& v) noexcept : Vector{xx, v.x, v.y}
{
}

template <typename T>
template <typename U, typename S>
inline constexpr Vector<3, T>::Vector(const Vector<2, U>& v, const S& zz) noexcept : Vector{v.x, v.y, zz}
{
}

// operators
template <typename T>
template <typename U>
inline Vector<3, T>& Vector<3, T>::operator=(const Vector<3, U>& other) noexcept
{
    x = create_value_of_type<T>::from(other.x);
    y = create_value_of_type<T>::from(other.y);
    z = create_value_of_type<T>::from(other.z);

    return *this;
}

// access operator
template <typename T>
inline typename Vector<3, T>::value_type& Vector<3, T>::operator[](unsigned int index)
{
    return data()[index];
}

template <typename T>
inline const typename Vector<3, T>::value_type& Vector<3, T>::operator[](unsigned int index) const
{
    return data()[index];
}

// methods
template <typename T>
inline constexpr unsigned int Vector<3, T>::size() const noexcept
{
    return 3;
}

template <typename T>
inline typename Vector<3, T>::value_type* Vector<3, T>::data() noexcept
{
    return &(this->x);
}

template <typename T>
inline const typename Vector<3, T>::value_type* Vector<3, T>::data() const noexcept
{
    return &(this->x);
}

#pragma mark - Vector<2, T> implementation

// constructors
template <typename T>
inline constexpr Vector<2, T>::Vector() noexcept : x{T(0)}, y{T(0)}
{
}

template <typename T>
template <typename X, typename Y>
inline constexpr Vector<2, T>::Vector(const X& xx, const Y& yy) noexcept : x{create_value_of_type<T>::from(xx)},
                                                                           y{create_value_of_type<T>::from(yy)}
{
}

template <typename T>
template <typename U>
inline constexpr Vector<2, T>::Vector(const U& v) noexcept : Vector{v, v}
{
}

template <typename T>
template <typename U>
inline constexpr Vector<2, T>::Vector(const U* p) noexcept : Vector{*p, *(p + 1)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

template <typename T>
template <typename U>
inline constexpr Vector<2, T>::Vector(const Vector<4, U>& v) noexcept : Vector{v.x, v.y}
{
}

template <typename T>
template <typename U>
inline constexpr Vector<2, T>::Vector(const Vector<3, U>& v) noexcept : Vector{v.x, v.y}
{
}
template <typename T>
template <typename U>
inline constexpr Vector<2, T>::Vector(const Vector<2, U>& v) noexcept : Vector{v.x, v.y}
{
}

// operators
template <typename T>
template <typename U>
inline Vector<2, T>& Vector<2, T>::operator=(const Vector<2, U>& other) noexcept
{
    x = create_value_of_type<T>::from(other.x);
    y = create_value_of_type<T>::from(other.y);

    return *this;
}

// access operator
template <typename T>
inline typename Vector<2, T>::value_type& Vector<2, T>::operator[](unsigned int index)
{
    return data()[index];
}

template <typename T>
inline const typename Vector<2, T>::value_type& Vector<2, T>::operator[](unsigned int index) const
{
    return data()[index];
}

// methods
template <typename T>
inline constexpr unsigned int Vector<2, T>::size() const noexcept
{
    return 2;
}

template <typename T>
inline typename Vector<2, T>::value_type* Vector<2, T>::data() noexcept
{
    return &(this->x);
}

template <typename T>
inline const typename Vector<2, T>::value_type* Vector<2, T>::data() const noexcept
{
    return &(this->x);
}

#pragma mark - unary operators

template <unsigned int N, typename T>
inline Vector<N, T> operator-(Vector<N, T> vector)
{
    return vector *= -T(1);
}

template <unsigned int N, typename T>
inline Vector<N, T> operator+(const Vector<N, T>& vector)
{
    return vector;
}


template <unsigned int N, typename T, typename U>
inline Vector<N, T>& operator+=(Vector<N, T>& lhs, const Vector<N, U>& rhs)
{
    for (unsigned int i = 0; i < N; ++i) {
        lhs[i] += create_value_of_type<T>::from(rhs[i]);
    }

    return lhs;
}

template <unsigned int N, typename T, typename U>
inline Vector<N, T>& operator-=(Vector<N, T>& lhs, const Vector<N, U>& rhs)
{
    for (unsigned int i = 0; i < N; ++i) {
        lhs[i] -= create_value_of_type<T>::from(rhs[i]);
    }

    return lhs;
}

template <unsigned int N, typename T, typename U>
inline Vector<N, T>& operator*=(Vector<N, T>& lhs, const Vector<N, U>& rhs)
{
    for (unsigned int i = 0; i < N; ++i) {
        lhs[i] *= create_value_of_type<T>::from(rhs[i]);
    }

    return lhs;
}

template <unsigned int N, typename T, typename U>
inline Vector<N, T>& operator/=(Vector<N, T>& lhs, const Vector<N, U>& rhs)
{
    for (unsigned int i = 0; i < N; ++i) {
        lhs[i] /= create_value_of_type<T>::from(rhs[i]);
    }

    return lhs;
}


template <unsigned int N, typename T, typename U>
inline Vector<N, T>& operator+=(Vector<N, T>& lhs, const U& rhs)
{
    for (unsigned int i = 0; i < N; ++i) {
        lhs[i] += create_value_of_type<T>::from(rhs);
    }

    return lhs;
}

template <unsigned int N, typename T, typename U>
inline Vector<N, T>& operator-=(Vector<N, T>& lhs, const U& rhs)
{
    for (unsigned int i = 0; i < N; ++i) {
        lhs[i] -= create_value_of_type<T>::from(rhs);
    }

    return lhs;
}

template <unsigned int N, typename T, typename U>
inline Vector<N, T>& operator*=(Vector<N, T>& lhs, const U& rhs)
{
    for (unsigned int i = 0; i < N; ++i) {
        lhs[i] *= create_value_of_type<T>::from(rhs);
    }

    return lhs;
}

template <unsigned int N, typename T, typename U>
inline Vector<N, T>& operator/=(Vector<N, T>& lhs, const U& rhs)
{
    for (unsigned int i = 0; i < N; ++i) {
        lhs[i] /= create_value_of_type<T>::from(rhs);
    }

    return lhs;
}

#pragma mark - binary operators: vector - vector

template <unsigned int N, typename T>
inline const Vector<N, T> operator+(Vector<N, T> lhs, const Vector<N, T>& rhs)
{
    return lhs += rhs;
}

template <unsigned int N, typename T>
inline const Vector<N, T> operator-(Vector<N, T> lhs, const Vector<N, T>& rhs)
{
    return lhs -= rhs;
}

template <unsigned int N, typename T>
inline const Vector<N, T> operator*(Vector<N, T> lhs, const Vector<N, T>& rhs)
{
    return lhs *= rhs;
}

template <unsigned int N, typename T>
inline const Vector<N, T> operator/(Vector<N, T> lhs, const Vector<N, T>& rhs)
{
    return lhs /= rhs;
}

#pragma mark - binary operators: vector - scalar

template <unsigned int N, typename T>
inline const Vector<N, T> operator+(Vector<N, T> vector, const T& scalar)
{
    return vector += scalar;
}

template <unsigned int N, typename T>
inline const Vector<N, T> operator-(Vector<N, T> vector, const T& scalar)
{
    return vector -= scalar;
}

template <unsigned int N, typename T>
inline const Vector<N, T> operator*(Vector<N, T> vector, const T& scalar)
{
    return vector *= scalar;
}

template <unsigned int N, typename T>
inline const Vector<N, T> operator/(Vector<N, T> vector, const T& scalar)
{
    return vector /= scalar;
}

#pragma mark - binary operators: scalar - vector

template <unsigned int N, typename T>
inline const Vector<N, T> operator+(const T& scalar, const Vector<N, T>& vector)
{
    Vector<N, T> tmp{scalar};
    return tmp += vector;
}

template <unsigned int N, typename T>
inline const Vector<N, T> operator-(const T& scalar, const Vector<N, T>& vector)
{
    Vector<N, T> tmp{scalar};
    return tmp -= vector;
}

template <unsigned int N, typename T>
inline const Vector<N, T> operator*(const T& scalar, const Vector<N, T>& vector)
{
    Vector<N, T> tmp{scalar};
    return tmp *= vector;
}

template <unsigned int N, typename T>
inline const Vector<N, T> operator/(const T& scalar, const Vector<N, T>& vector)
{
    Vector<N, T> tmp{scalar};
    return tmp /= vector;
}

#pragma mark - vectors equality

template <typename T>
inline constexpr bool operator==(const Vector<4, T>& a, const Vector<4, T>& b)
{
    const auto& abs = ::framework::math::abs<T>;
    return abs(a.x - b.x) <= 0 && abs(a.y - b.y) <= 0 && abs(a.z - b.z) <= 0 && abs(a.w - b.w) <= 0;
}

template <typename T>
inline constexpr bool operator==(const Vector<3, T>& a, const Vector<3, T>& b)
{
    const auto& abs = ::framework::math::abs<T>;
    return abs(a.x - b.x) <= 0 && abs(a.y - b.y) <= 0 && abs(a.z - b.z) <= 0;
}

template <typename T>
inline constexpr bool operator==(const Vector<2, T>& a, const Vector<2, T>& b)
{
    const auto& abs = ::framework::math::abs<T>;
    return abs(a.x - b.x) <= 0 && abs(a.y - b.y) <= 0;
}

template <typename T>
inline constexpr bool operator!=(const Vector<4, T>& a, const Vector<4, T>& b)
{
    const auto& abs = ::framework::math::abs<T>;
    return abs(a.x - b.x) > 0 && abs(a.y - b.y) > 0 && abs(a.z - b.z) > 0 && abs(a.w - b.w) > 0;
}

template <typename T>
inline constexpr bool operator!=(const Vector<3, T>& a, const Vector<3, T>& b)
{
    const auto& abs = ::framework::math::abs<T>;
    return abs(a.x - b.x) > 0 && abs(a.y - b.y) > 0 && abs(a.z - b.z) > 0;
}

template <typename T>
inline constexpr bool operator!=(const Vector<2, T>& a, const Vector<2, T>& b)
{
    const auto& abs = ::framework::math::abs<T>;
    return abs(a.x - b.x) > 0 && abs(a.y - b.y);
}

} // namespace vector_impl

} // namespace math

} // namespace framework

#endif
