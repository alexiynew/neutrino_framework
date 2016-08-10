#ifndef FRAMEWORK_MATH_VECTOR_TYPE_H
#define FRAMEWORK_MATH_VECTOR_TYPE_H

#include <common_types.h>
#include <debug.h>

#include <math/utils.h>

namespace framework {

namespace math {

namespace vector_impl {

// base classes for vectors of different size
template <U32 N, typename T>
struct VectorBase
{
};

// vector interface
template <U32 N, typename T>
struct Vector : public VectorBase<N, T>
{
    using BaseType  = VectorBase<N, T>;
    using ValueType = typename BaseType::ValueType;

    constexpr Vector();

    constexpr Vector(const Vector<N, T>&) = default;
    constexpr Vector(Vector<N, T>&&)      = default;

    // import constructors from VectorBase<N, T>
    using BaseType::BaseType;

    constexpr U32 size() const;

    T* data();
    const T* data() const;

    Vector<N, T>& operator=(const Vector<N, T>&) = default;
    Vector<N, T>& operator=(Vector<N, T>&&) = default;

    template <typename U>
    Vector<N, T>& operator=(const Vector<N, U>& other);

    template <typename U>
    Vector<N, T>& operator+=(const Vector<N, U>& other);

    template <typename U>
    Vector<N, T>& operator-=(const Vector<N, U>& other);

    template <typename U>
    Vector<N, T>& operator*=(const Vector<N, U>& other);

    template <typename U>
    Vector<N, T>& operator/=(const Vector<N, U>& other);

    template <typename U>
    Vector<N, T>& operator+=(const U& scalar);

    template <typename U>
    Vector<N, T>& operator-=(const U& scalar);

    template <typename U>
    Vector<N, T>& operator*=(const U& scalar);

    template <typename U>
    Vector<N, T>& operator/=(const U& scalar);

    ValueType& operator[](U32 index);
    const ValueType& operator[](U32 index) const;
};

// vector of bool specialization
template <U32 N>
struct Vector<N, bool> : public VectorBase<N, bool>
{
    using BaseType  = VectorBase<N, bool>;
    using ValueType = typename BaseType::ValueType;

    constexpr Vector();

    constexpr Vector(const Vector<N, bool>&) = default;
    constexpr Vector(Vector<N, bool>&&)      = default;

    constexpr U32 size() const;

    ValueType* data();
    const ValueType* data() const;

    // import constructors from VectorBase<N, bool>
    using BaseType::BaseType;

    Vector<N, bool>& operator=(const Vector<N, bool>&) = default;
    Vector<N, bool>& operator=(Vector<N, bool>&&) = default;

    template <typename U>
    Vector<N, bool>& operator=(const Vector<N, U>& other);

    ValueType& operator[](U32 index);
    const ValueType& operator[](U32 index) const;
};

// vector base
template <typename T>
struct VectorBase<4, T>
{
    static_assert(std::is_arithmetic<T>::value, "Expected floating-point or integer type.");
    using ValueType = T;

    T x, y, z, w;

    constexpr VectorBase() : x{0}, y{0}, z{0}, w{utils::default_value<ValueType>::value}
    {
    }

    constexpr VectorBase(const T& xx, const T& yy, const T& zz, const T& ww) : x{xx}, y{yy}, z{zz}, w{ww}
    {
    }

    explicit constexpr VectorBase(const T& v) : x{v}, y{v}, z{v}, w{v}
    {
    }

    template <typename U>
    explicit constexpr VectorBase(const U* const p) : x{*p}, y{*(p + 1)}, z{*(p + 2)}, w{*(p + 3)}
    {
        static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
    }

    template <typename U>
    explicit constexpr VectorBase(const Vector<4, U>& v)
    : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)), z(static_cast<T>(v.z)), w(static_cast<T>(v.w))
    {
    }

    template <typename U>
    explicit constexpr VectorBase(const Vector<3, U>& v)
    : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)), z(static_cast<T>(v.z)), w(utils::default_value<ValueType>::value)
    {
    }

    template <typename U, typename S>
    constexpr VectorBase(const S& s, const Vector<3, U>& v)
    : x(static_cast<T>(s)), y(static_cast<T>(v.x)), z(static_cast<T>(v.y)), w(static_cast<T>(v.z))
    {
    }

    template <typename U, typename S>
    constexpr VectorBase(const Vector<3, U>& v, const S& s)
    : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)), z(static_cast<T>(v.z)), w(static_cast<T>(s))
    {
    }

    template <typename U>
    explicit constexpr VectorBase(const Vector<2, U>& v)
    : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)), z(0), w(utils::default_value<ValueType>::value)
    {
    }

    template <typename U1, typename U2>
    constexpr VectorBase(const Vector<2, U1>& v1, const Vector<2, U2>& v2)
    : x(static_cast<T>(v1.x)), y(static_cast<T>(v1.y)), z(static_cast<T>(v2.x)), w(static_cast<T>(v2.y))
    {
    }

    template <typename U, typename S1, typename S2>
    constexpr VectorBase(const S1& xx, const S2& yy, const Vector<2, U>& v)
    : x(static_cast<T>(xx)), y(static_cast<T>(yy)), z(static_cast<T>(v.x)), w(static_cast<T>(v.y))
    {
    }

    template <typename U, typename S1, typename S2>
    constexpr VectorBase(const S1& xx, const Vector<2, U>& v, const S2& ww)
    : x(static_cast<T>(xx)), y(static_cast<T>(v.x)), z(static_cast<T>(v.y)), w(static_cast<T>(ww))
    {
    }

    template <typename U, typename S1, typename S2>
    constexpr VectorBase(const Vector<2, U>& v, const S1& zz, const S2& ww)
    : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)), z(static_cast<T>(zz)), w(static_cast<T>(ww))
    {
    }
};

template <typename T>
struct VectorBase<3, T>
{
    static_assert(std::is_arithmetic<T>::value, "Expected floating-point or integer type.");
    using ValueType = T;

    T x, y, z;

    constexpr VectorBase() : x{0}, y{0}, z{0}
    {
    }

    constexpr VectorBase(const T& xx, const T& yy, const T& zz) : x{xx}, y{yy}, z{zz}
    {
    }

    explicit constexpr VectorBase(const T& v) : x{v}, y{v}, z{v}
    {
    }

    template <typename U>
    explicit constexpr VectorBase(const U* const p) : x{*p}, y{*(p + 1)}, z{*(p + 2)}
    {
        static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
    }

    template <typename U>
    explicit constexpr VectorBase(const Vector<4, U>& v)
    : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)), z(static_cast<T>(v.z))
    {
    }

    template <typename U>
    explicit constexpr VectorBase(const Vector<3, U>& v)
    : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)), z(static_cast<T>(v.z))
    {
    }

    template <typename U>
    explicit constexpr VectorBase(const Vector<2, U>& v) : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)), z(0)
    {
    }

    template <typename U, typename S>
    constexpr VectorBase(const S& xx, const Vector<2, U>& v)
    : x(static_cast<T>(xx)), y(static_cast<T>(v.x)), z(static_cast<T>(v.y))
    {
    }

    template <typename U, typename S>
    constexpr VectorBase(const Vector<2, U>& v, const S& zz)
    : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)), z(static_cast<T>(zz))
    {
    }
};

template <typename T>
struct VectorBase<2, T>
{
    static_assert(std::is_arithmetic<T>::value, "Expected floating-point or integer type.");
    using ValueType = T;

    T x, y;

    constexpr VectorBase() : x{0}, y{0}
    {
    }

    constexpr VectorBase(const T& xx, const T& yy) : x{xx}, y{yy}
    {
    }

    explicit constexpr VectorBase(const T& v) : x{v}, y{v}
    {
    }

    template <typename U>
    explicit constexpr VectorBase(const U* p) : x{*p}, y{*(p + 1)}
    {
        static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
    }

    template <typename U>
    explicit constexpr VectorBase(const Vector<4, U>& v) : x(static_cast<T>(v.x)), y(static_cast<T>(v.y))
    {
    }

    template <typename U>
    explicit constexpr VectorBase(const Vector<3, U>& v) : x(static_cast<T>(v.x)), y(static_cast<T>(v.y))
    {
    }

    template <typename U>
    explicit constexpr VectorBase(const Vector<2, U>& v) : x(static_cast<T>(v.x)), y(static_cast<T>(v.y))
    {
    }
};

// vector<N, T> implementation

// default constructor
template <U32 N, typename T>
constexpr Vector<N, T>::Vector() : BaseType()
{
}

// vector methods
template <U32 N, typename T>
inline constexpr U32 Vector<N, T>::size() const
{
    return N;
}

template <U32 N, typename T>
inline T* Vector<N, T>::data()
{
    return &(this->x);
}

template <U32 N, typename T>
inline const T* Vector<N, T>::data() const
{
    return &(this->x);
}

// access operator
template <U32 N, typename T>
inline typename Vector<N, T>::ValueType& Vector<N, T>::operator[](U32 index)
{
    ASSERT_MSG(index >= 0 && index < N, "Worng index.");
    return data()[index];
}

template <U32 N, typename T>
const typename Vector<N, T>::ValueType& Vector<N, T>::operator[](U32 index) const
{
    ASSERT_MSG(index >= 0 && index < N, "Wrong index.");
    return data()[index];
}

// assignment operator
template <U32 N, typename T>
template <typename U>
inline Vector<N, T>& Vector<N, T>::operator=(const Vector<N, U>& other)
{
    for (U32 i = 0; i < N; ++i) {
        (*this)[i] = static_cast<T>(other[i]);
    }
    return *this;
}


// vector<N, bool> implementation

// default constructor
template <U32 N>
constexpr Vector<N, bool>::Vector() : BaseType()
{
}

// vector methods
template <U32 N>
inline constexpr U32 Vector<N, bool>::size() const
{
    return N;
}

template <U32 N>
inline typename Vector<N, bool>::ValueType* Vector<N, bool>::data()
{
    return &(this->x);
}

template <U32 N>
inline const typename Vector<N, bool>::ValueType* Vector<N, bool>::data() const
{
    return &(this->x);
}

// access operator
template <U32 N>
inline typename Vector<N, bool>::ValueType& Vector<N, bool>::operator[](U32 index)
{
    ASSERT_MSG(index >= 0 && index < N, "Worng index.");
    return data()[index];
}

template <U32 N>
const typename Vector<N, bool>::ValueType& Vector<N, bool>::operator[](U32 index) const
{
    ASSERT_MSG(index >= 0 && index < N, "Wrong index.");
    return data()[index];
}

// assignment operator
template <U32 N>
template <typename U>
inline Vector<N, bool>& Vector<N, bool>::operator=(const Vector<N, U>& other)
{
    for (U32 i = 0; i < N; ++i) {
        (*this)[i] = static_cast<bool>(other[i]);
    }
    return *this;
}

// unary operators
// vector - vector
template <U32 N, typename T>
template <typename U>
inline Vector<N, T>& Vector<N, T>::operator+=(const Vector<N, U>& other)
{
    for (U32 i = 0; i < N; ++i) {
        (*this)[i] += static_cast<T>(other[i]);
    }
    return *this;
}

template <U32 N, typename T>
template <typename U>
inline Vector<N, T>& Vector<N, T>::operator-=(const Vector<N, U>& other)
{
    for (U32 i = 0; i < N; ++i) {
        (*this)[i] -= static_cast<T>(other[i]);
    };
    return *this;
}

template <U32 N, typename T>
template <typename U>
inline Vector<N, T>& Vector<N, T>::operator*=(const Vector<N, U>& other)
{
    for (U32 i = 0; i < N; ++i) {
        (*this)[i] *= static_cast<T>(other[i]);
    };
    return *this;
}

template <U32 N, typename T>
template <typename U>
inline Vector<N, T>& Vector<N, T>::operator/=(const Vector<N, U>& other)
{
    for (U32 i = 0; i < N; ++i) {
        (*this)[i] /= static_cast<T>(other[i]);
    };
    return *this;
}

// unary operators
// vector - scalar
template <U32 N, typename T>
template <typename U>
inline Vector<N, T>& Vector<N, T>::operator+=(const U& scalar)
{
    for (U32 i = 0; i < N; ++i) {
        (*this)[i] += static_cast<T>(scalar);
    }
    return *this;
}

template <U32 N, typename T>
template <typename U>
inline Vector<N, T>& Vector<N, T>::operator-=(const U& scalar)
{
    for (U32 i = 0; i < N; ++i) {
        (*this)[i] -= static_cast<T>(scalar);
    }
    return *this;
}

template <U32 N, typename T>
template <typename U>
inline Vector<N, T>& Vector<N, T>::operator*=(const U& scalar)
{
    for (U32 i = 0; i < N; ++i) {
        (*this)[i] *= static_cast<T>(scalar);
    }
    return *this;
}

template <U32 N, typename T>
template <typename U>
inline Vector<N, T>& Vector<N, T>::operator/=(const U& scalar)
{
    for (U32 i = 0; i < N; ++i) {
        (*this)[i] /= static_cast<T>(scalar);
    }
    return *this;
}

// unary minus
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

// binary operators
// vector - vector
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

// binary operators
// vector - scalar
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

// binary operators
// scalar - vector
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

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wfloat-equal"

// vectors equality
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
