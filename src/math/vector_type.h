#ifndef FRAMEWORK_MATH_VECTOR_TYPE_H
#define FRAMEWORK_MATH_VECTOR_TYPE_H

#include <common_types.h>
#include <debug.h>

#include <math/utils.h>

namespace framework {

namespace math {

namespace vector_impl {

#pragma mark - Vector template declaration
template <U32 N, typename T>
struct Vector;

#pragma mark - Vector<4, T> type specialization
template <typename T>
struct Vector<4, T> final
{
    static_assert(std::is_arithmetic<T>::value, "Expected floating-point or integer type.");
    using ValueType = T;

    constexpr Vector();

    constexpr Vector(const Vector<4, ValueType>&) = default;
    constexpr Vector(Vector<4, ValueType>&&)      = default;

    constexpr Vector(const ValueType& xx, const ValueType& yy, const ValueType& zz, const ValueType& ww);
    explicit constexpr Vector(const ValueType& v);

    template <typename U>
    explicit constexpr Vector(const U* const p);

    template <typename U>
    explicit constexpr Vector(const Vector<4, U>& v);

    template <typename U>
    explicit constexpr Vector(const Vector<3, U>& v);

    template <typename U, typename S>
    constexpr Vector(const S& s, const Vector<3, U>& v);

    template <typename U, typename S>
    constexpr Vector(const Vector<3, U>& v, const S& s);

    template <typename U>
    explicit constexpr Vector(const Vector<2, U>& v);

    template <typename U1, typename U2>
    constexpr Vector(const Vector<2, U1>& v1, const Vector<2, U2>& v2);

    template <typename U, typename S1, typename S2>
    constexpr Vector(const S1& xx, const S2& yy, const Vector<2, U>& v);

    template <typename U, typename S1, typename S2>
    constexpr Vector(const S1& xx, const Vector<2, U>& v, const S2& ww);

    template <typename U, typename S1, typename S2>
    constexpr Vector(const Vector<2, U>& v, const S1& zz, const S2& ww);

    Vector<4, ValueType>& operator=(const Vector<4, ValueType>&) = default;
    Vector<4, ValueType>& operator=(Vector<4, ValueType>&&) = default;

    template <typename U>
    Vector<4, ValueType>& operator=(const Vector<4, U>& other);

    template <typename U>
    Vector<4, ValueType>& operator+=(const Vector<4, U>& other);

    template <typename U>
    Vector<4, ValueType>& operator-=(const Vector<4, U>& other);

    template <typename U>
    Vector<4, ValueType>& operator*=(const Vector<4, U>& other);

    template <typename U>
    Vector<4, ValueType>& operator/=(const Vector<4, U>& other);

    template <typename U>
    Vector<4, ValueType>& operator+=(const U& scalar);

    template <typename U>
    Vector<4, ValueType>& operator-=(const U& scalar);

    template <typename U>
    Vector<4, ValueType>& operator*=(const U& scalar);

    template <typename U>
    Vector<4, ValueType>& operator/=(const U& scalar);

    ValueType& operator[](U32 index);
    const ValueType& operator[](U32 index) const;

    constexpr U32 size() const;

    ValueType* data();
    const ValueType* data() const;

    ValueType x, y, z, w;
};

#pragma mark - Vector<3, T> type specialization
template <typename T>
struct Vector<3, T> final
{
    static_assert(std::is_arithmetic<T>::value, "Expected floating-point or integer type.");
    using ValueType = T;

    constexpr Vector();

    constexpr Vector(const Vector<3, ValueType>&) = default;
    constexpr Vector(Vector<3, ValueType>&&)      = default;

    constexpr Vector(const ValueType& xx, const ValueType& yy, const ValueType& zz);

    explicit constexpr Vector(const ValueType& v);

    template <typename U>
    explicit constexpr Vector(const U* const p);

    template <typename U>
    explicit constexpr Vector(const Vector<4, U>& v);

    template <typename U>
    explicit constexpr Vector(const Vector<3, U>& v);

    template <typename U>
    explicit constexpr Vector(const Vector<2, U>& v);

    template <typename U, typename S>
    constexpr Vector(const S& xx, const Vector<2, U>& v);

    template <typename U, typename S>
    constexpr Vector(const Vector<2, U>& v, const S& zz);

    Vector<3, ValueType>& operator=(const Vector<3, ValueType>&) = default;
    Vector<3, ValueType>& operator=(Vector<3, ValueType>&&) = default;

    template <typename U>
    Vector<3, ValueType>& operator=(const Vector<3, U>& other);

    template <typename U>
    Vector<3, ValueType>& operator+=(const Vector<3, U>& other);

    template <typename U>
    Vector<3, ValueType>& operator-=(const Vector<3, U>& other);

    template <typename U>
    Vector<3, ValueType>& operator*=(const Vector<3, U>& other);

    template <typename U>
    Vector<3, ValueType>& operator/=(const Vector<3, U>& other);

    template <typename U>
    Vector<3, ValueType>& operator+=(const U& scalar);

    template <typename U>
    Vector<3, ValueType>& operator-=(const U& scalar);

    template <typename U>
    Vector<3, ValueType>& operator*=(const U& scalar);

    template <typename U>
    Vector<3, ValueType>& operator/=(const U& scalar);

    ValueType& operator[](U32 index);
    const ValueType& operator[](U32 index) const;

    constexpr U32 size() const;

    ValueType* data();
    const ValueType* data() const;

    ValueType x, y, z;
};

#pragma mark - Vector<2, T> type specialization
template <typename T>
struct Vector<2, T> final
{
    static_assert(std::is_arithmetic<T>::value, "Expected floating-point or integer type.");
    using ValueType = T;

    constexpr Vector();

    constexpr Vector(const Vector<2, ValueType>&) = default;
    constexpr Vector(Vector<2, ValueType>&&)      = default;

    constexpr Vector(const ValueType& xx, const ValueType& yy);

    explicit constexpr Vector(const ValueType& v);

    template <typename U>
    explicit constexpr Vector(const U* p);

    template <typename U>
    explicit constexpr Vector(const Vector<4, U>& v);

    template <typename U>
    explicit constexpr Vector(const Vector<3, U>& v);

    template <typename U>
    explicit constexpr Vector(const Vector<2, U>& v);

    Vector<2, ValueType>& operator=(const Vector<2, ValueType>&) = default;
    Vector<2, ValueType>& operator=(Vector<2, ValueType>&&) = default;

    template <typename U>
    Vector<2, ValueType>& operator=(const Vector<2, U>& other);

    template <typename U>
    Vector<2, ValueType>& operator+=(const Vector<2, U>& other);

    template <typename U>
    Vector<2, ValueType>& operator-=(const Vector<2, U>& other);

    template <typename U>
    Vector<2, ValueType>& operator*=(const Vector<2, U>& other);

    template <typename U>
    Vector<2, ValueType>& operator/=(const Vector<2, U>& other);

    template <typename U>
    Vector<2, ValueType>& operator+=(const U& scalar);

    template <typename U>
    Vector<2, ValueType>& operator-=(const U& scalar);

    template <typename U>
    Vector<2, ValueType>& operator*=(const U& scalar);

    template <typename U>
    Vector<2, ValueType>& operator/=(const U& scalar);

    ValueType& operator[](U32 index);
    const ValueType& operator[](U32 index) const;

    constexpr U32 size() const;

    ValueType* data();
    const ValueType* data() const;

    ValueType x, y;
};

#pragma mark - Vector<4, T> implementation

// constructors
template <typename T>
inline constexpr Vector<4, T>::Vector()
    : x{0}, y{0}, z{0}, w{T(not std::is_same<T, bool>::value)}
{}

template <typename T>
inline constexpr Vector<4, T>::Vector(const T& xx, const T& yy, const T& zz, const T& ww)
    : x{xx}
    , y{yy}
    , z{zz}
    , w{ww}
{}

template <typename T>
inline constexpr Vector<4, T>::Vector(const T& v)
    : x{v}
    , y{v}
    , z{v}
    , w{v}
{}

template <typename T>
template <typename U>
inline constexpr Vector<4, T>::Vector(const U* const p)
    : x{*p}
    , y{*(p + 1)}
    , z{*(p + 2)}
    , w{*(p + 3)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

template <typename T>
template <typename U>
inline constexpr Vector<4, T>::Vector(const Vector<4, U>& v)
    : x{static_cast<T>(v.x)}
    , y{static_cast<T>(v.y)}
    , z{static_cast<T>(v.z)}
    , w{static_cast<T>(v.w)}
{}

template <typename T>
template <typename U>
inline constexpr Vector<4, T>::Vector(const Vector<3, U>& v)
    : x{static_cast<T>(v.x)}
    , y{static_cast<T>(v.y)}
    , z{static_cast<T>(v.z)}
    , w{T(1)}
{}

template <typename T>
template <typename U, typename S>
inline constexpr Vector<4, T>::Vector(const S& s, const Vector<3, U>& v)
    : x{static_cast<T>(s)}
    , y{static_cast<T>(v.x)}
    , z{static_cast<T>(v.y)}
    , w{static_cast<T>(v.z)}
{}

template <typename T>
template <typename U, typename S>
inline constexpr Vector<4, T>::Vector(const Vector<3, U>& v, const S& s)
    : x{static_cast<T>(v.x)}
    , y{static_cast<T>(v.y)}
    , z{static_cast<T>(v.z)}
    , w{static_cast<T>(s)}
{}

template <typename T>
template <typename U>
inline constexpr Vector<4, T>::Vector(const Vector<2, U>& v)
    : x{static_cast<T>(v.x)}
    , y{static_cast<T>(v.y)}
    , z{T(0)}
    , w{T(1)}
{}

template <typename T>
template <typename U1, typename U2>
inline constexpr Vector<4, T>::Vector(const Vector<2, U1>& v1, const Vector<2, U2>& v2)
    : x{static_cast<T>(v1.x)}
    , y{static_cast<T>(v1.y)}
    , z{static_cast<T>(v2.x)}
    , w{static_cast<T>(v2.y)}
{}

template <typename T>
template <typename U, typename S1, typename S2>
inline constexpr Vector<4, T>::Vector(const S1& xx, const S2& yy, const Vector<2, U>& v)
    : x{static_cast<T>(xx)}
    , y{static_cast<T>(yy)}
    , z{static_cast<T>(v.x)}
    , w{static_cast<T>(v.y)}
{}

template <typename T>
template <typename U, typename S1, typename S2>
inline constexpr Vector<4, T>::Vector(const S1& xx, const Vector<2, U>& v, const S2& ww)
    : x{static_cast<T>(xx)}
    , y{static_cast<T>(v.x)}
    , z{static_cast<T>(v.y)}
    , w{static_cast<T>(ww)}
{}

template <typename T>
template <typename U, typename S1, typename S2>
inline constexpr Vector<4, T>::Vector(const Vector<2, U>& v, const S1& zz, const S2& ww)
    : x{static_cast<T>(v.x)}
    , y{static_cast<T>(v.y)}
    , z{static_cast<T>(zz)}
    , w{static_cast<T>(ww)}
{}

// operators
template <typename T>
template <typename U>
inline Vector<4, T>& Vector<4, T>::operator=(const Vector<4, U>& other)
{
    x = static_cast<T>(other.x);
    y = static_cast<T>(other.y);
    z = static_cast<T>(other.z);
    w = static_cast<T>(other.w);

    return *this;
}

template <typename T>
template <typename U>
inline Vector<4, T>& Vector<4, T>::operator+=(const Vector<4, U>& other)
{
    x += static_cast<T>(other.x);
    y += static_cast<T>(other.y);
    z += static_cast<T>(other.z);
    w += static_cast<T>(other.w);

    return *this;
}

template <typename T>
template <typename U>
inline Vector<4, T>& Vector<4, T>::operator-=(const Vector<4, U>& other)
{
    x -= static_cast<T>(other.x);
    y -= static_cast<T>(other.y);
    z -= static_cast<T>(other.z);
    w -= static_cast<T>(other.w);

    return *this;
}

template <typename T>
template <typename U>
inline Vector<4, T>& Vector<4, T>::operator*=(const Vector<4, U>& other)
{
    x *= static_cast<T>(other.x);
    y *= static_cast<T>(other.y);
    z *= static_cast<T>(other.z);
    w *= static_cast<T>(other.w);

    return *this;
}

template <typename T>
template <typename U>
inline Vector<4, T>& Vector<4, T>::operator/=(const Vector<4, U>& other)
{
    x /= static_cast<T>(other.x);
    y /= static_cast<T>(other.y);
    z /= static_cast<T>(other.z);
    w /= static_cast<T>(other.w);

    return *this;
}

template <typename T>
template <typename U>
inline Vector<4, T>& Vector<4, T>::operator+=(const U& scalar)
{
    x += static_cast<T>(scalar);
    y += static_cast<T>(scalar);
    z += static_cast<T>(scalar);
    w += static_cast<T>(scalar);

    return *this;
}

template <typename T>
template <typename U>
inline Vector<4, T>& Vector<4, T>::operator-=(const U& scalar)
{
    x -= static_cast<T>(scalar);
    y -= static_cast<T>(scalar);
    z -= static_cast<T>(scalar);
    w -= static_cast<T>(scalar);

    return *this;
}

template <typename T>
template <typename U>
inline Vector<4, T>& Vector<4, T>::operator*=(const U& scalar)
{
    x *= static_cast<T>(scalar);
    y *= static_cast<T>(scalar);
    z *= static_cast<T>(scalar);
    w *= static_cast<T>(scalar);

    return *this;
}

template <typename T>
template <typename U>
inline Vector<4, T>& Vector<4, T>::operator/=(const U& scalar)
{
    x /= static_cast<T>(scalar);
    y /= static_cast<T>(scalar);
    z /= static_cast<T>(scalar);
    w /= static_cast<T>(scalar);

    return *this;
}

// access operator
template <typename T>
inline typename Vector<4, T>::ValueType& Vector<4, T>::operator[](U32 index)
{
    ASSERT_MSG(index >= 0 && index < 4, "Wrong index.");
    return data()[index];
}

template <typename T>
inline const typename Vector<4, T>::ValueType& Vector<4, T>::operator[](U32 index) const
{
    ASSERT_MSG(index >= 0 && index < 4, "Wrong index.");
    return data()[index];
}

// methods
template <typename T>
inline constexpr U32 Vector<4, T>::size() const
{
    return 4;
}

template <typename T>
inline typename Vector<4, T>::ValueType* Vector<4, T>::data()
{
    return &(this->x);
}

template <typename T>
inline const typename Vector<4, T>::ValueType* Vector<4, T>::data() const
{
    return &(this->x);
}

#pragma mark - Vector<3, T> implementation

// constructors
template <typename T>
inline constexpr Vector<3, T>::Vector()
    : x{0}
    , y{0}
    , z{0}
{}

template <typename T>
inline constexpr Vector<3, T>::Vector(const T& xx, const T& yy, const T& zz)
    : x{xx}
    , y{yy}
    , z{zz}
{}

template <typename T>
inline constexpr Vector<3, T>::Vector(const T& v)
    : x{v}
    , y{v}
    , z{v}
{
}

template <typename T>
template <typename U>
inline constexpr Vector<3, T>::Vector(const U* const p)
    : x{*p}
    , y{*(p + 1)}
    , z{*(p + 2)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

template <typename T>
template <typename U>
inline constexpr Vector<3, T>::Vector(const Vector<4, U>& v)
    : x{static_cast<T>(v.x)}
    , y{static_cast<T>(v.y)}
    , z{static_cast<T>(v.z)}
{
}

template <typename T>
template <typename U>
inline constexpr Vector<3, T>::Vector(const Vector<3, U>& v)
    : x{static_cast<T>(v.x)}
    , y{static_cast<T>(v.y)}
    , z{static_cast<T>(v.z)}
{
}

template <typename T>
template <typename U>
inline constexpr Vector<3, T>::Vector(const Vector<2, U>& v)
    : x{static_cast<T>(v.x)}
    , y{static_cast<T>(v.y)}
    , z{T(0)}
{
}

template <typename T>
template <typename U, typename S>
inline constexpr Vector<3, T>::Vector(const S& xx, const Vector<2, U>& v)
    : x{static_cast<T>(xx)}
    , y{static_cast<T>(v.x)}
    , z{static_cast<T>(v.y)}
{
}

template <typename T>
template <typename U, typename S>
inline constexpr Vector<3, T>::Vector(const Vector<2, U>& v, const S& zz)
    : x{static_cast<T>(v.x)}
    , y{static_cast<T>(v.y)}
    , z{static_cast<T>(zz)}
{
}

// operators
template <typename T>
template <typename U>
inline Vector<3, T>& Vector<3, T>::operator=(const Vector<3, U>& other)
{
    x = static_cast<T>(other.x);
    y = static_cast<T>(other.y);
    z = static_cast<T>(other.z);

    return *this;
}

template <typename T>
template <typename U>
inline Vector<3, T>& Vector<3, T>::operator+=(const Vector<3, U>& other)
{
    x += static_cast<T>(other.x);
    y += static_cast<T>(other.y);
    z += static_cast<T>(other.z);

    return *this;
}

template <typename T>
template <typename U>
inline Vector<3, T>& Vector<3, T>::operator-=(const Vector<3, U>& other)
{
    x -= static_cast<T>(other.x);
    y -= static_cast<T>(other.y);
    z -= static_cast<T>(other.z);

    return *this;
}

template <typename T>
template <typename U>
inline Vector<3, T>& Vector<3, T>::operator*=(const Vector<3, U>& other)
{
    x *= static_cast<T>(other.x);
    y *= static_cast<T>(other.y);
    z *= static_cast<T>(other.z);

    return *this;
}

template <typename T>
template <typename U>
inline Vector<3, T>& Vector<3, T>::operator/=(const Vector<3, U>& other)
{
    x /= static_cast<T>(other.x);
    y /= static_cast<T>(other.y);
    z /= static_cast<T>(other.z);

    return *this;
}

template <typename T>
template <typename U>
inline Vector<3, T>& Vector<3, T>::operator+=(const U& scalar)
{
    x += static_cast<T>(scalar);
    y += static_cast<T>(scalar);
    z += static_cast<T>(scalar);

    return *this;
}

template <typename T>
template <typename U>
inline Vector<3, T>& Vector<3, T>::operator-=(const U& scalar)
{
    x -= static_cast<T>(scalar);
    y -= static_cast<T>(scalar);
    z -= static_cast<T>(scalar);

    return *this;
}

template <typename T>
template <typename U>
inline Vector<3, T>& Vector<3, T>::operator*=(const U& scalar)
{
    x *= static_cast<T>(scalar);
    y *= static_cast<T>(scalar);
    z *= static_cast<T>(scalar);

    return *this;
}

template <typename T>
template <typename U>
inline Vector<3, T>& Vector<3, T>::operator/=(const U& scalar)
{
    x /= static_cast<T>(scalar);
    y /= static_cast<T>(scalar);
    z /= static_cast<T>(scalar);

    return *this;
}

// access operator
template <typename T>
inline typename Vector<3, T>::ValueType& Vector<3, T>::operator[](U32 index)
{
    ASSERT_MSG(index >= 0 && index < 3, "Wrong index.");
    return data()[index];
}

template <typename T>
inline const typename Vector<3, T>::ValueType& Vector<3, T>::operator[](U32 index) const
{
    ASSERT_MSG(index >= 0 && index < 3, "Wrong index.");
    return data()[index];
}

// methods
template <typename T>
inline constexpr U32 Vector<3, T>::size() const
{
    return 3;
}

template <typename T>
inline typename Vector<3, T>::ValueType* Vector<3, T>::data()
{
    return &(this->x);
}

template <typename T>
inline const typename Vector<3, T>::ValueType* Vector<3, T>::data() const
{
    return &(this->x);
}

#pragma mark - Vector<2, T> implementation

// constructors
template <typename T>
inline constexpr Vector<2, T>::Vector()
    : x{0}
    , y{0}
{
}

template <typename T>
inline constexpr Vector<2, T>::Vector(const T& xx, const T& yy)
    : x{xx}
    , y{yy}
{
}

template <typename T>
inline constexpr Vector<2, T>::Vector(const T& v)
    : x{v}
    , y{v}
{
}

template <typename T>
template <typename U>
inline constexpr Vector<2, T>::Vector(const U* p)
    : x{*p}
    , y{*(p + 1)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

template <typename T>
template <typename U>
inline constexpr Vector<2, T>::Vector(const Vector<4, U>& v)
    : x{static_cast<T>(v.x)}
    , y{static_cast<T>(v.y)}
{
}

template <typename T>
template <typename U>
inline constexpr Vector<2, T>::Vector(const Vector<3, U>& v)
    : x{static_cast<T>(v.x)}
    , y{static_cast<T>(v.y)}
{
}
template <typename T>
template <typename U>
inline constexpr Vector<2, T>::Vector(const Vector<2, U>& v)
    : x{static_cast<T>(v.x)}
    , y{static_cast<T>(v.y)}
{
}

// operators
template <typename T>
template <typename U>
inline Vector<2, T>& Vector<2, T>::operator=(const Vector<2, U>& other)
{
    x = static_cast<T>(other.x);
    y = static_cast<T>(other.y);

    return *this;
}

template <typename T>
template <typename U>
inline Vector<2, T>& Vector<2, T>::operator+=(const Vector<2, U>& other)
{
    x += static_cast<T>(other.x);
    y += static_cast<T>(other.y);

    return *this;
}

template <typename T>
template <typename U>
inline Vector<2, T>& Vector<2, T>::operator-=(const Vector<2, U>& other)
{
    x -= static_cast<T>(other.x);
    y -= static_cast<T>(other.y);

    return *this;
}

template <typename T>
template <typename U>
inline Vector<2, T>& Vector<2, T>::operator*=(const Vector<2, U>& other)
{
    x *= static_cast<T>(other.x);
    y *= static_cast<T>(other.y);

    return *this;
}

template <typename T>
template <typename U>
inline Vector<2, T>& Vector<2, T>::operator/=(const Vector<2, U>& other)
{
    x /= static_cast<T>(other.x);
    y /= static_cast<T>(other.y);

    return *this;
}

template <typename T>
template <typename U>
inline Vector<2, T>& Vector<2, T>::operator+=(const U& scalar)
{
    x += static_cast<T>(scalar);
    y += static_cast<T>(scalar);

    return *this;
}

template <typename T>
template <typename U>
inline Vector<2, T>& Vector<2, T>::operator-=(const U& scalar)
{
    x -= static_cast<T>(scalar);
    y -= static_cast<T>(scalar);

    return *this;
}

template <typename T>
template <typename U>
inline Vector<2, T>& Vector<2, T>::operator*=(const U& scalar)
{
    x *= static_cast<T>(scalar);
    y *= static_cast<T>(scalar);

    return *this;
}

template <typename T>
template <typename U>
inline Vector<2, T>& Vector<2, T>::operator/=(const U& scalar)
{
    x /= static_cast<T>(scalar);
    y /= static_cast<T>(scalar);

    return *this;
}

// access operator
template <typename T>
inline typename Vector<2, T>::ValueType& Vector<2, T>::operator[](U32 index)
{
    ASSERT_MSG(index >= 0 && index < 2, "Wrong index.");
    return data()[index];
}

template <typename T>
inline const typename Vector<2, T>::ValueType& Vector<2, T>::operator[](U32 index) const
{
    ASSERT_MSG(index >= 0 && index < 2, "Wrong index.");
    return data()[index];
}

// methods
template <typename T>
inline constexpr U32 Vector<2, T>::size() const
{
    return 2;
}

template <typename T>
inline typename Vector<2, T>::ValueType* Vector<2, T>::data()
{
    return &(this->x);
}

template <typename T>
inline const typename Vector<2, T>::ValueType* Vector<2, T>::data() const
{
    return &(this->x);
}


#pragma mark - unary minus
template <U32 N, typename T>
inline Vector<N, T> operator-(const Vector<N, T>& v)
{
    return utils::createVector(v, [](const T& a) { return -a; });
}

// unary plus
template <U32 N, typename T>
inline Vector<N, T> operator+(const Vector<N, T>& v)
{
    return v;
}

#pragma mark - binary operators: vector - vector
template <U32 N, typename T>
inline const Vector<N, T> operator+(const Vector<N, T>& lhs, const Vector<N, T>& rhs)
{
    return utils::createVector(lhs, rhs, [](const T& a, const T& b) { return a + b; });
}

template <U32 N, typename T>
inline const Vector<N, T> operator-(const Vector<N, T>& lhs, const Vector<N, T>& rhs)
{
    return utils::createVector(lhs, rhs, [](const T& a, const T& b) { return a - b; });
}

template <U32 N, typename T>
inline const Vector<N, T> operator*(const Vector<N, T>& lhs, const Vector<N, T>& rhs)
{
    return utils::createVector(lhs, rhs, [](const T& a, const T& b) { return a * b; });
}

template <U32 N, typename T>
inline const Vector<N, T> operator/(const Vector<N, T>& lhs, const Vector<N, T>& rhs)
{
    return utils::createVector(lhs, rhs, [](const T& a, const T& b) { return a / b; });
}

#pragma mark - binary operators: vector - scalar
template <U32 N, typename T>
inline const Vector<N, T> operator+(const Vector<N, T>& vector, const T& scalar)
{
    return utils::createVector(vector, [&scalar](const T& a) { return a + scalar; });
}

template <U32 N, typename T>
inline const Vector<N, T> operator-(const Vector<N, T>& vector, const T& scalar)
{
    return utils::createVector(vector, [&scalar](const T& a) { return a - scalar; });
}

template <U32 N, typename T>
inline const Vector<N, T> operator*(const Vector<N, T>& vector, const T& scalar)
{
    return utils::createVector(vector, [&scalar](const T& a) { return a * scalar; });
}

template <U32 N, typename T>
inline const Vector<N, T> operator/(const Vector<N, T>& vector, const T& scalar)
{
    return utils::createVector(vector, [&scalar](const T& a) { return a / scalar; });
}

#pragma mark - binary operators: scalar - vector
template <U32 N, typename T>
inline const Vector<N, T> operator+(const T& scalar, const Vector<N, T>& vector)
{
    return utils::createVector(Vector<N, T>(scalar), vector, [](const T& a, const T& b) { return a + b; });
}

template <U32 N, typename T>
inline const Vector<N, T> operator-(const T& scalar, const Vector<N, T>& vector)
{
    return utils::createVector(Vector<N, T>(scalar), vector, [](const T& a, const T& b) { return a - b; });
}

template <U32 N, typename T>
inline const Vector<N, T> operator*(const T& scalar, const Vector<N, T>& vector)
{
    return utils::createVector(Vector<N, T>(scalar), vector, [](const T& a, const T& b) { return a * b; });
}

template <U32 N, typename T>
inline const Vector<N, T> operator/(const T& scalar, const Vector<N, T>& vector)
{
    return utils::createVector(Vector<N, T>(scalar), vector, [](const T& a, const T& b) { return a / b; });
}

#pragma mark - vectors equality

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wfloat-equal"

template <typename T>
inline constexpr bool operator==(const Vector<4, T>& a, const Vector<4, T>& b)
{
    return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w;
}

template <typename T>
inline constexpr bool operator==(const Vector<3, T>& a, const Vector<3, T>& b)
{
    return a.x == b.x && a.y == b.y && a.z == b.z;
}

template <typename T>
inline constexpr bool operator==(const Vector<2, T>& a, const Vector<2, T>& b)
{
    return a.x == b.x && a.y == b.y;
}

template <typename T>
inline constexpr bool operator!=(const Vector<4, T>& a, const Vector<4, T>& b)
{
    return (a.x != b.x) || (a.y != b.y) || (a.z != b.z) || (a.w != b.w);
}

template <typename T>
inline constexpr bool operator!=(const Vector<3, T>& a, const Vector<3, T>& b)
{
    return (a.x != b.x) || (a.y != b.y) || (a.z != b.z);
}

template <typename T>
inline constexpr bool operator!=(const Vector<2, T>& a, const Vector<2, T>& b)
{
    return (a.x != b.x) || (a.y != b.y);
}

#pragma clang diagnostic pop

} // namespace vector_impl

} // namespace math

} // namespace framework

#endif // FRAMEWORK_MATH_VECTOR_TYPE_H
