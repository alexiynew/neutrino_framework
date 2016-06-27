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
struct vec_base
{
};

// vector interface
template <U32 N, typename T>
struct vec : public vec_base<N, T>
{
    using base_type  = vec_base<N, T>;
    using value_type = typename base_type::value_type;

    constexpr vec();

    constexpr vec(const vec<N, T>&) = default;
    constexpr vec(vec<N, T>&&)      = default;

    // import constructors from vec_base<N, T>
    using base_type::base_type;

    constexpr U32 size() const;

    T* data();
    const T* data() const;

    vec<N, T>& operator=(const vec<N, T>&) = default;
    vec<N, T>& operator=(vec<N, T>&&) = default;

    template <typename U>
    vec<N, T>& operator=(const vec<N, U>& other);

    template <typename U>
    vec<N, T>& operator+=(const vec<N, U>& other);

    template <typename U>
    vec<N, T>& operator-=(const vec<N, U>& other);

    template <typename U>
    vec<N, T>& operator*=(const vec<N, U>& other);

    template <typename U>
    vec<N, T>& operator/=(const vec<N, U>& other);

    template <typename U>
    vec<N, T>& operator+=(const U& scalar);

    template <typename U>
    vec<N, T>& operator-=(const U& scalar);

    template <typename U>
    vec<N, T>& operator*=(const U& scalar);

    template <typename U>
    vec<N, T>& operator/=(const U& scalar);

    value_type& operator[](U32 index);
    const value_type& operator[](U32 index) const;
};

// vector of bool specialization
template <U32 N>
struct vec<N, bool> : public vec_base<N, bool>
{
    using base_type  = vec_base<N, bool>;
    using value_type = typename base_type::value_type;

    constexpr vec();

    constexpr vec(const vec<N, bool>&) = default;
    constexpr vec(vec<N, bool>&&)      = default;

    constexpr U32 size() const;

    value_type* data();
    const value_type* data() const;

    // import constructors from vec_base<N, bool>
    using base_type::base_type;

    vec<N, bool>& operator=(const vec<N, bool>&) = default;
    vec<N, bool>& operator=(vec<N, bool>&&) = default;

    template <typename U>
    vec<N, bool>& operator=(const vec<N, U>& other);

    value_type& operator[](U32 index);
    const value_type& operator[](U32 index) const;
};

// vector base
template <typename T>
struct vec_base<4, T>
{
    static_assert(std::is_arithmetic<T>::value, "integral or floating point type required");
    using value_type = T;

    T x, y, z, w;

    constexpr vec_base() : x{0}, y{0}, z{0}, w{utils::default_value<value_type>::value}
    {
    }

    constexpr vec_base(const T& xx, const T& yy, const T& zz, const T& ww) : x{xx}, y{yy}, z{zz}, w{ww}
    {
    }

    explicit constexpr vec_base(const T& v) : x{v}, y{v}, z{v}, w{v}
    {
    }

    template <typename U>
    explicit constexpr vec_base(const U* const p) : x{*p}, y{*(p + 1)}, z{*(p + 2)}, w{*(p + 3)}
    {
        static_assert(std::is_same<T, U>::value, "only valid pointer type is acceptable");
    }

    template <typename U>
    explicit constexpr vec_base(const vec<4, U>& v)
    : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)), z(static_cast<T>(v.z)), w(static_cast<T>(v.w))
    {
    }

    template <typename U>
    explicit constexpr vec_base(const vec<3, U>& v)
    : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)), z(static_cast<T>(v.z)), w(utils::default_value<value_type>::value)
    {
    }

    template <typename U, typename S>
    constexpr vec_base(const S& s, const vec<3, U>& v)
    : x(static_cast<T>(s)), y(static_cast<T>(v.x)), z(static_cast<T>(v.y)), w(static_cast<T>(v.z))
    {
    }

    template <typename U, typename S>
    constexpr vec_base(const vec<3, U>& v, const S& s)
    : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)), z(static_cast<T>(v.z)), w(static_cast<T>(s))
    {
    }

    template <typename U>
    explicit constexpr vec_base(const vec<2, U>& v)
    : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)), z(0), w(utils::default_value<value_type>::value)
    {
    }

    template <typename U1, typename U2>
    constexpr vec_base(const vec<2, U1>& v1, const vec<2, U2>& v2)
    : x(static_cast<T>(v1.x)), y(static_cast<T>(v1.y)), z(static_cast<T>(v2.x)), w(static_cast<T>(v2.y))
    {
    }

    template <typename U, typename S1, typename S2>
    constexpr vec_base(const S1& xx, const S2& yy, const vec<2, U>& v)
    : x(static_cast<T>(xx)), y(static_cast<T>(yy)), z(static_cast<T>(v.x)), w(static_cast<T>(v.y))
    {
    }

    template <typename U, typename S1, typename S2>
    constexpr vec_base(const S1& xx, const vec<2, U>& v, const S2& ww)
    : x(static_cast<T>(xx)), y(static_cast<T>(v.x)), z(static_cast<T>(v.y)), w(static_cast<T>(ww))
    {
    }

    template <typename U, typename S1, typename S2>
    constexpr vec_base(const vec<2, U>& v, const S1& zz, const S2& ww)
    : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)), z(static_cast<T>(zz)), w(static_cast<T>(ww))
    {
    }
};

template <typename T>
struct vec_base<3, T>
{
    static_assert(std::is_arithmetic<T>::value, "integral or floating point type required");
    using value_type = T;

    T x, y, z;

    constexpr vec_base() : x{0}, y{0}, z{0}
    {
    }

    constexpr vec_base(const T& xx, const T& yy, const T& zz) : x{xx}, y{yy}, z{zz}
    {
    }

    explicit constexpr vec_base(const T& v) : x{v}, y{v}, z{v}
    {
    }

    template <typename U>
    explicit constexpr vec_base(const U* const p) : x{*p}, y{*(p + 1)}, z{*(p + 2)}
    {
        static_assert(std::is_same<T, U>::value, "only valid pointer type is acceptable");
    }

    template <typename U>
    explicit constexpr vec_base(const vec<4, U>& v)
    : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)), z(static_cast<T>(v.z))
    {
    }

    template <typename U>
    explicit constexpr vec_base(const vec<3, U>& v)
    : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)), z(static_cast<T>(v.z))
    {
    }

    template <typename U>
    explicit constexpr vec_base(const vec<2, U>& v) : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)), z(0)
    {
    }

    template <typename U, typename S>
    constexpr vec_base(const S& xx, const vec<2, U>& v)
    : x(static_cast<T>(xx)), y(static_cast<T>(v.x)), z(static_cast<T>(v.y))
    {
    }

    template <typename U, typename S>
    constexpr vec_base(const vec<2, U>& v, const S& zz)
    : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)), z(static_cast<T>(zz))
    {
    }
};

template <typename T>
struct vec_base<2, T>
{
    static_assert(std::is_arithmetic<T>::value, "integral or floating point type required");
    using value_type = T;

    T x, y;

    constexpr vec_base() : x{0}, y{0}
    {
    }

    constexpr vec_base(const T& xx, const T& yy) : x{xx}, y{yy}
    {
    }

    explicit constexpr vec_base(const T& v) : x{v}, y{v}
    {
    }

    template <typename U>
    explicit constexpr vec_base(const U* p) : x{*p}, y{*(p + 1)}
    {
        static_assert(std::is_same<T, U>::value, "only valid pointer type is acceptable");
    }

    template <typename U>
    explicit constexpr vec_base(const vec<4, U>& v) : x(static_cast<T>(v.x)), y(static_cast<T>(v.y))
    {
    }

    template <typename U>
    explicit constexpr vec_base(const vec<3, U>& v) : x(static_cast<T>(v.x)), y(static_cast<T>(v.y))
    {
    }

    template <typename U>
    explicit constexpr vec_base(const vec<2, U>& v) : x(static_cast<T>(v.x)), y(static_cast<T>(v.y))
    {
    }
};

// vector<N, T> implementation

// default constructor
template <U32 N, typename T>
constexpr vec<N, T>::vec() : base_type()
{
}

// vector methods
template <U32 N, typename T>
inline constexpr U32 vec<N, T>::size() const
{
    return N;
}

template <U32 N, typename T>
inline T* vec<N, T>::data()
{
    return &(this->x);
}

template <U32 N, typename T>
inline const T* vec<N, T>::data() const
{
    return &(this->x);
}

// access operator
template <U32 N, typename T>
inline typename vec<N, T>::value_type& vec<N, T>::operator[](U32 index)
{
    assert_msg(index >= 0 && index < N, "Worng index");
    return data()[index];
}

template <U32 N, typename T>
const typename vec<N, T>::value_type& vec<N, T>::operator[](U32 index) const
{
    assert_msg(index >= 0 && index < N, "Wrong index");
    return data()[index];
}

// assignment operator
template <U32 N, typename T>
template <typename U>
inline vec<N, T>& vec<N, T>::operator=(const vec<N, U>& other)
{
    for (U32 i = 0; i < N; ++i) {
        (*this)[i] = static_cast<T>(other[i]);
    }
    return *this;
}


// vector<N, bool> implementation

// default constructor
template <U32 N>
constexpr vec<N, bool>::vec() : base_type()
{
}

// vector methods
template <U32 N>
inline constexpr U32 vec<N, bool>::size() const
{
    return N;
}

template <U32 N>
inline typename vec<N, bool>::value_type* vec<N, bool>::data()
{
    return &(this->x);
}

template <U32 N>
inline const typename vec<N, bool>::value_type* vec<N, bool>::data() const
{
    return &(this->x);
}

// access operator
template <U32 N>
inline typename vec<N, bool>::value_type& vec<N, bool>::operator[](U32 index)
{
    assert_msg(index >= 0 && index < N, "Worng index");
    return data()[index];
}

template <U32 N>
const typename vec<N, bool>::value_type& vec<N, bool>::operator[](U32 index) const
{
    assert_msg(index >= 0 && index < N, "Wrong index");
    return data()[index];
}

// assignment operator
template <U32 N>
template <typename U>
inline vec<N, bool>& vec<N, bool>::operator=(const vec<N, U>& other)
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
inline vec<N, T>& vec<N, T>::operator+=(const vec<N, U>& other)
{
    for (U32 i = 0; i < N; ++i) {
        (*this)[i] += static_cast<T>(other[i]);
    }
    return *this;
}

template <U32 N, typename T>
template <typename U>
inline vec<N, T>& vec<N, T>::operator-=(const vec<N, U>& other)
{
    for (U32 i = 0; i < N; ++i) {
        (*this)[i] -= static_cast<T>(other[i]);
    };
    return *this;
}

template <U32 N, typename T>
template <typename U>
inline vec<N, T>& vec<N, T>::operator*=(const vec<N, U>& other)
{
    for (U32 i = 0; i < N; ++i) {
        (*this)[i] *= static_cast<T>(other[i]);
    };
    return *this;
}

template <U32 N, typename T>
template <typename U>
inline vec<N, T>& vec<N, T>::operator/=(const vec<N, U>& other)
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
inline vec<N, T>& vec<N, T>::operator+=(const U& scalar)
{
    for (U32 i = 0; i < N; ++i) {
        (*this)[i] += static_cast<T>(scalar);
    }
    return *this;
}

template <U32 N, typename T>
template <typename U>
inline vec<N, T>& vec<N, T>::operator-=(const U& scalar)
{
    for (U32 i = 0; i < N; ++i) {
        (*this)[i] -= static_cast<T>(scalar);
    }
    return *this;
}

template <U32 N, typename T>
template <typename U>
inline vec<N, T>& vec<N, T>::operator*=(const U& scalar)
{
    for (U32 i = 0; i < N; ++i) {
        (*this)[i] *= static_cast<T>(scalar);
    }
    return *this;
}

template <U32 N, typename T>
template <typename U>
inline vec<N, T>& vec<N, T>::operator/=(const U& scalar)
{
    for (U32 i = 0; i < N; ++i) {
        (*this)[i] /= static_cast<T>(scalar);
    }
    return *this;
}

// unary minus
template <U32 N, typename T>
inline vec<N, T> operator-(const vec<N, T>& v)
{
    return utils::vec_helper<N>::apply(v, [](const T& a) { return -a; });
}

// unary plus
template <U32 N, typename T>
inline vec<N, T> operator+(const vec<N, T>& v)
{
    return v;
}

// binary operators
// vector - vector
template <U32 N, typename T>
inline const vec<N, T> operator+(const vec<N, T>& lhs, const vec<N, T>& rhs)
{
    return utils::vec_helper<N>::apply(lhs, rhs, [](const T& a, const T& b) { return a + b; });
}

template <U32 N, typename T>
inline const vec<N, T> operator-(const vec<N, T>& lhs, const vec<N, T>& rhs)
{
    return utils::vec_helper<N>::apply(lhs, rhs, [](const T& a, const T& b) { return a - b; });
}

template <U32 N, typename T>
inline const vec<N, T> operator*(const vec<N, T>& lhs, const vec<N, T>& rhs)
{
    return utils::vec_helper<N>::apply(lhs, rhs, [](const T& a, const T& b) { return a * b; });
}

template <U32 N, typename T>
inline const vec<N, T> operator/(const vec<N, T>& lhs, const vec<N, T>& rhs)
{
    return utils::vec_helper<N>::apply(lhs, rhs, [](const T& a, const T& b) { return a / b; });
}

// binary operators
// vector - scalar
template <U32 N, typename T>
inline const vec<N, T> operator+(const vec<N, T>& vector, const T& scalar)
{
    return utils::vec_helper<N>::apply(vector, [&scalar](const T& a) { return a + scalar; });
}

template <U32 N, typename T>
inline const vec<N, T> operator-(const vec<N, T>& vector, const T& scalar)
{
    return utils::vec_helper<N>::apply(vector, [&scalar](const T& a) { return a - scalar; });
}

template <U32 N, typename T>
inline const vec<N, T> operator*(const vec<N, T>& vector, const T& scalar)
{
    return utils::vec_helper<N>::apply(vector, [&scalar](const T& a) { return a * scalar; });
}

template <U32 N, typename T>
inline const vec<N, T> operator/(const vec<N, T>& vector, const T& scalar)
{
    return utils::vec_helper<N>::apply(vector, [&scalar](const T& a) { return a / scalar; });
}

// binary operators
// scalar - vector
template <U32 N, typename T>
inline const vec<N, T> operator+(const T& scalar, const vec<N, T>& vector)
{
    return utils::vec_helper<N>::apply(vec<N, T>(scalar), vector, [](const T& a, const T& b) { return a + b; });
}

template <U32 N, typename T>
inline const vec<N, T> operator-(const T& scalar, const vec<N, T>& vector)
{
    return utils::vec_helper<N>::apply(vec<N, T>(scalar), vector, [](const T& a, const T& b) { return a - b; });
}

template <U32 N, typename T>
inline const vec<N, T> operator*(const T& scalar, const vec<N, T>& vector)
{
    return utils::vec_helper<N>::apply(vec<N, T>(scalar), vector, [](const T& a, const T& b) { return a * b; });
}

template <U32 N, typename T>
inline const vec<N, T> operator/(const T& scalar, const vec<N, T>& vector)
{
    return utils::vec_helper<N>::apply(vec<N, T>(scalar), vector, [](const T& a, const T& b) { return a / b; });
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wfloat-equal"

// vectors equality
template <typename T>
inline constexpr bool operator==(const vec<4, T>& a, const vec<4, T>& b)
{
    return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w;
}

template <typename T>
inline constexpr bool operator==(const vec<3, T>& a, const vec<3, T>& b)
{
    return a.x == b.x && a.y == b.y && a.z == b.z;
}

template <typename T>
inline constexpr bool operator==(const vec<2, T>& a, const vec<2, T>& b)
{
    return a.x == b.x && a.y == b.y;
}

template <typename T>
inline constexpr bool operator!=(const vec<4, T>& a, const vec<4, T>& b)
{
    return (a.x != b.x) || (a.y != b.y) || (a.z != b.z) || (a.w != b.w);
}

template <typename T>
inline constexpr bool operator!=(const vec<3, T>& a, const vec<3, T>& b)
{
    return (a.x != b.x) || (a.y != b.y) || (a.z != b.z);
}

template <typename T>
inline constexpr bool operator!=(const vec<2, T>& a, const vec<2, T>& b)
{
    return (a.x != b.x) || (a.y != b.y);
}

#pragma clang diagnostic pop

} // namespace vector_impl

} // namespace math

} // namespace framework

#endif // FRAMEWORK_MATH_VECTOR_TYPE_H
