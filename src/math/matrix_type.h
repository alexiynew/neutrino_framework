#ifndef FRAMEWORK_MATH_MATRIX_TYPE_H
#define FRAMEWORK_MATH_MATRIX_TYPE_H

#include <functional>
#include <type_traits>

#include <debug.h>
#include <math/geometric_func.h>
#include <math/vector_type.h>

namespace framework {

namespace math {

namespace matrix_impl {

// base classes for matrices of different size
template <U32 C, U32 R, typename T>
struct matrix_base
{
};

template <U32 C, U32 R, typename T>
struct matrix : public matrix_base<C, R, T>
{
    using base_type   = matrix_base<C, R, T>;
    using matrix_type = matrix<C, R, T>;
    using value_type  = typename base_type::value_type;
    using column_type = typename base_type::column_type;
    using row_type    = typename base_type::row_type;

    constexpr matrix();

    constexpr matrix(const matrix<C, R, T>&) = default;
    constexpr matrix(matrix<C, R, T>&&)      = default;

    // import constructors from matrix_base<C, R, T>
    using base_type::matrix_base;

    constexpr U32 size() const;

    value_type* data();
    const value_type* data() const;

    column_type column(U32 index) const;
    row_type row(U32 index) const;

    matrix<C, R, T>& operator=(const matrix<C, R, T>&) = default;
    matrix<C, R, T>& operator=(matrix<C, R, T>&&) = default;

    template <typename U>
    matrix<C, R, T>& operator=(const matrix<C, R, U>& other);

    template <typename U>
    matrix<C, R, T>& operator+=(const matrix<C, R, U>& other);

    template <typename U>
    matrix<C, R, T>& operator-=(const matrix<C, R, U>& other);

    template <typename U>
    matrix<C, R, T>& operator*=(const matrix<C, C, U>& other);

    template <typename U>
    matrix<C, R, T>& operator+=(const U& scalar);

    template <typename U>
    matrix<C, R, T>& operator-=(const U& scalar);

    template <typename U>
    matrix<C, R, T>& operator*=(const U& scalar);

    template <typename U>
    matrix<C, R, T>& operator/=(const U& scalar);

    column_type& operator[](U32 index);
    const column_type& operator[](U32 index) const;
};

// matrix base types
template <typename T>
struct matrix_base<4, 4, T>
{
    static_assert(std::is_arithmetic<T>::value, "integral or floating point type required");

    using value_type  = T;
    using column_type = vector_impl::vec<4, T>;
    using row_type    = vector_impl::vec<4, T>;

    explicit constexpr matrix_base(const T& v)
    : data{column_type(v, 0, 0, 0), column_type(0, v, 0, 0), column_type(0, 0, v, 0), column_type(0, 0, 0, v)}
    {
    }

    constexpr matrix_base() : matrix_base(T(1))
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const U* const p)
    : data{column_type(p), column_type(p + 4), column_type(p + 8), column_type(p + 12)}
    {
        static_assert(std::is_same<T, U>::value, "only valid pointer type is acceptable");
    }

    constexpr matrix_base(const T& v00, const T& v01, const T& v02, const T& v03, const T& v10, const T& v11, const T& v12, const T& v13, const T& v20, const T& v21, const T& v22, const T& v23, const T& v30, const T& v31, const T& v32, const T& v33)
    : data{column_type(v00, v01, v02, v03), column_type(v10, v11, v12, v13), column_type(v20, v21, v22, v23), column_type(v30, v31, v32, v33)}
    {
    }

    template <typename X00, typename Y01, typename Z02, typename W03, typename X10, typename Y11, typename Z12, typename W13, typename X20, typename Y21, typename Z22, typename W23, typename X30, typename Y31, typename Z32, typename W33>
    constexpr matrix_base(const X00& v00, const Y01& v01, const Z02& v02, const W03& v03, const X10& v10, const Y11& v11, const Z12& v12, const W13& v13, const X20& v20, const Y21& v21, const Z22& v22, const W23& v23, const X30& v30, const Y31& v31, const Z32& v32, const W33& v33)
    : data{column_type(v00, v01, v02, v03), column_type(v10, v11, v12, v13), column_type(v20, v21, v22, v23), column_type(v30, v31, v32, v33)}
    {
    }

    template <typename U0, typename U1, typename U2, typename U3>
    constexpr matrix_base(const vector_impl::vec<4, U0>& v0, const vector_impl::vec<4, U1>& v1, const vector_impl::vec<4, U2>& v2, const vector_impl::vec<4, U3>& v3)
    : data{column_type(v0), column_type(v1), column_type(v2), column_type(v3)}
    {
    }

    template <typename U0, typename U1, typename U2, typename U3, typename X, typename Y, typename Z, typename W>
    constexpr matrix_base(const vector_impl::vec<3, U0>& v0, const X& s0, const vector_impl::vec<3, U1>& v1, const Y& s1, const vector_impl::vec<3, U2>& v2, const Z& s2, const vector_impl::vec<3, U3>& v3, const W& s3)
    : data{column_type(v0, s0), column_type(v1, s1), column_type(v2, s2), column_type(v3, s3)}
    {
    }

    template <typename U0, typename U1, typename U2, typename U3, typename X, typename Y, typename Z, typename W>
    constexpr matrix_base(const X& s0, const vector_impl::vec<3, U0>& v0, const Y& s1, const vector_impl::vec<3, U1>& v1, const Z& s2, const vector_impl::vec<3, U2>& v2, const W& s3, const vector_impl::vec<3, U3>& v3)
    : data{column_type(s0, v0), column_type(s1, v1), column_type(s2, v2), column_type(s3, v3)}
    {
    }

    template <typename U00, typename U01, typename U10, typename U11, typename U20, typename U21, typename U30, typename U31>
    constexpr matrix_base(const vector_impl::vec<2, U00>& v00, const vector_impl::vec<2, U01>& v01, const vector_impl::vec<2, U10>& v10, const vector_impl::vec<2, U11>& v11, const vector_impl::vec<2, U20>& v20, const vector_impl::vec<2, U21>& v21, const vector_impl::vec<2, U30>& v30, const vector_impl::vec<2, U31>& v31)
    : data{column_type(v00, v01), column_type(v10, v11), column_type(v20, v21), column_type(v30, v31)}
    {
    }

    template <typename U00, typename S01, typename S02, typename U10, typename S11, typename S12, typename U20, typename S21, typename S22, typename U30, typename S31, typename S32>
    constexpr matrix_base(const vector_impl::vec<2, U00>& v00, const S01& s01, const S02& s02, const vector_impl::vec<2, U10>& v10, const S11& s11, const S12& s12, const vector_impl::vec<2, U20>& v20, const S21& s21, const S22& s22, const vector_impl::vec<2, U30>& v30, const S31& s31, const S32& s32)
    : data{column_type(v00, s01, s02), column_type(v10, s11, s12), column_type(v20, s21, s22), column_type(v30, s31, s32)}
    {
    }

    template <typename S00, typename U01, typename S02, typename S10, typename U11, typename S12, typename S20, typename U21, typename S22, typename S30, typename U31, typename S32>
    constexpr matrix_base(const S00& s00, const vector_impl::vec<2, U01>& v01, const S02& s02, const S10& s10, const vector_impl::vec<2, U11>& v11, const S12& s12, const S20& s20, const vector_impl::vec<2, U21>& v21, const S22& s22, const S30& s30, const vector_impl::vec<2, U31>& v31, const S32& s32)
    : data{column_type(s00, v01, s02), column_type(s10, v11, s12), column_type(s20, v21, s22), column_type(s30, v31, s32)}
    {
    }

    template <typename S00, typename S01, typename U02, typename S10, typename S11, typename U12, typename S20, typename S21, typename U22, typename S30, typename S31, typename U32>
    constexpr matrix_base(const S00& s00, const S01& s01, const vector_impl::vec<2, U02>& v02, const S10& s10, const S11& s11, const vector_impl::vec<2, U12>& v12, const S20& s20, const S21& s21, const vector_impl::vec<2, U22>& v22, const S30& s30, const S31& s31, const vector_impl::vec<2, U32>& v32)
    : data{column_type(s00, s01, v02), column_type(s10, s11, v12), column_type(s20, s21, v22), column_type(s30, s31, v32)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<4, 4, U>& other)
    : data{column_type(other[0]), column_type(other[1]), column_type(other[2]), column_type(other[3])}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<4, 3, U>& other)
    : data{column_type(other[0], 0), column_type(other[1], 0), column_type(other[2], 0), column_type(other[3], 1)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<4, 2, U>& other)
    : data{column_type(other[0], 0, 0), column_type(other[1], 0, 0), column_type(other[2], 1, 0), column_type(other[3], 0, 1)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<3, 4, U>& other)
    : data{column_type(other[0]), column_type(other[1]), column_type(other[2]), column_type(0, 0, 0, 1)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<3, 3, U>& other)
    : data{column_type(other[0], 0), column_type(other[1], 0), column_type(other[2], 0), column_type(0, 0, 0, 1)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<3, 2, U>& other)
    : data{column_type(other[0], 0, 0), column_type(other[1], 0, 0), column_type(other[2], 1, 0), column_type(0, 0, 0, 1)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<2, 4, U>& other)
    : data{column_type(other[0]), column_type(other[1]), column_type(0, 0, 1, 0), column_type(0, 0, 0, 1)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<2, 3, U>& other)
    : data{column_type(other[0], 0), column_type(other[1], 0), column_type(0, 0, 1, 0), column_type(0, 0, 0, 1)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<2, 2, U>& other)
    : data{column_type(other[0], 0, 0), column_type(other[1], 0, 0), column_type(0, 0, 1, 0), column_type(0, 0, 0, 1)}
    {
    }

    protected:
    column_type data[4];
};

template <typename T>
struct matrix_base<4, 3, T>
{
    static_assert(std::is_arithmetic<T>::value, "integral or floating point type required");

    using value_type  = T;
    using column_type = vector_impl::vec<3, T>;
    using row_type    = vector_impl::vec<4, T>;

    explicit constexpr matrix_base(const T& v)
    : data{column_type(v, 0, 0), column_type(0, v, 0), column_type(0, 0, v), column_type(0, 0, 0)}
    {
    }

    constexpr matrix_base() : matrix_base(T(1))
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const U* const p)
    : data{column_type(p), column_type(p + 3), column_type(p + 6), column_type(p + 9)}
    {
        static_assert(std::is_same<T, U>::value, "only valid pointer type is acceptable");
    }

    constexpr matrix_base(const T& v00, const T& v01, const T& v02, const T& v10, const T& v11, const T& v12, const T& v20, const T& v21, const T& v22, const T& v30, const T& v31, const T& v32)
    : data{column_type(v00, v01, v02), column_type(v10, v11, v12), column_type(v20, v21, v22), column_type(v30, v31, v32)}
    {
    }

    template <typename X00, typename Y01, typename Z02, typename X10, typename Y11, typename Z12, typename X20, typename Y21, typename Z22, typename X30, typename Y31, typename Z32>
    constexpr matrix_base(const X00& v00, const Y01& v01, const Z02& v02, const X10& v10, const Y11& v11, const Z12& v12, const X20& v20, const Y21& v21, const Z22& v22, const X30& v30, const Y31& v31, const Z32& v32)
    : data{column_type(v00, v01, v02), column_type(v10, v11, v12), column_type(v20, v21, v22), column_type(v30, v31, v32)}
    {
    }

    template <typename U0, typename U1, typename U2, typename U3>
    constexpr matrix_base(const vector_impl::vec<4, U0>& v0, const vector_impl::vec<4, U1>& v1, const vector_impl::vec<4, U2>& v2, const vector_impl::vec<4, U3>& v3)
    : data{column_type(v0), column_type(v1), column_type(v2), column_type(v3)}
    {
    }

    template <typename U0, typename U1, typename U2, typename U3>
    constexpr matrix_base(const vector_impl::vec<3, U0>& v0, const vector_impl::vec<3, U1>& v1, const vector_impl::vec<3, U2>& v2, const vector_impl::vec<3, U3>& v3)
    : data{column_type(v0), column_type(v1), column_type(v2), column_type(v3)}
    {
    }

    template <typename U00, typename S01, typename U10, typename S11, typename U20, typename S21, typename U30, typename S31>
    constexpr matrix_base(const vector_impl::vec<2, U00>& v00, const S01& s01, const vector_impl::vec<2, U10>& v10, const S11& s11, const vector_impl::vec<2, U20>& v20, const S21& s21, const vector_impl::vec<2, U30>& v30, const S31& s31)
    : data{column_type(v00, s01), column_type(v10, s11), column_type(v20, s21), column_type(v30, s31)}
    {
    }

    template <typename S00, typename U01, typename S10, typename U11, typename S20, typename U21, typename S30, typename U31>
    constexpr matrix_base(const S00& s00, const vector_impl::vec<2, U01>& v01, const S10& s10, const vector_impl::vec<2, U11>& v11, const S20& s20, const vector_impl::vec<2, U21>& v21, const S30& s30, const vector_impl::vec<2, U31>& v31)
    : data{column_type(s00, v01), column_type(s10, v11), column_type(s20, v21), column_type(s30, v31)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<4, 4, U>& other)
    : data{column_type(other[0]), column_type(other[1]), column_type(other[2]), column_type(other[3])}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<4, 3, U>& other)
    : data{column_type(other[0]), column_type(other[1]), column_type(other[2]), column_type(other[3])}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<4, 2, U>& other)
    : data{column_type(other[0], 0), column_type(other[1], 0), column_type(other[2], 1), column_type(other[3], 0)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<3, 4, U>& other)
    : data{column_type(other[0]), column_type(other[1]), column_type(other[2]), column_type(0, 0, 0)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<3, 3, U>& other)
    : data{column_type(other[0]), column_type(other[1]), column_type(other[2]), column_type(0, 0, 0)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<3, 2, U>& other)
    : data{column_type(other[0], 0), column_type(other[1], 0), column_type(other[2], 1), column_type(0, 0, 0)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<2, 4, U>& other)
    : data{column_type(other[0]), column_type(other[1]), column_type(0, 0, 1), column_type(0, 0, 0)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<2, 3, U>& other)
    : data{column_type(other[0]), column_type(other[1]), column_type(0, 0, 1), column_type(0, 0, 0)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<2, 2, U>& other)
    : data{column_type(other[0], 0), column_type(other[1], 0), column_type(0, 0, 1), column_type(0, 0, 0)}
    {
    }

    protected:
    column_type data[4];
};

template <typename T>
struct matrix_base<4, 2, T>
{
    static_assert(std::is_arithmetic<T>::value, "integral or floating point type required");

    using value_type  = T;
    using column_type = vector_impl::vec<2, T>;
    using row_type    = vector_impl::vec<4, T>;

    explicit constexpr matrix_base(const T& v)
    : data{column_type(v, 0), column_type(0, v), column_type(0, 0), column_type(0, 0)}
    {
    }

    constexpr matrix_base() : matrix_base(T(1))
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const U* const p)
    : data{column_type(p), column_type(p + 2), column_type(p + 4), column_type(p + 6)}
    {
        static_assert(std::is_same<T, U>::value, "only valid pointer type is acceptable");
    }

    constexpr matrix_base(const T& v00, const T& v01, const T& v10, const T& v11, const T& v20, const T& v21, const T& v30, const T& v31)
    : data{column_type(v00, v01), column_type(v10, v11), column_type(v20, v21), column_type(v30, v31)}
    {
    }

    template <typename X00, typename Y01, typename X10, typename Y11, typename X20, typename Y21, typename X30, typename Y31>
    constexpr matrix_base(const X00& v00, const Y01& v01, const X10& v10, const Y11& v11, const X20& v20, const Y21& v21, const X30& v30, const Y31& v31)
    : data{column_type(v00, v01), column_type(v10, v11), column_type(v20, v21), column_type(v30, v31)}
    {
    }

    template <typename U0, typename U1, typename U2, typename U3>
    constexpr matrix_base(const vector_impl::vec<4, U0>& v0, const vector_impl::vec<4, U1>& v1, const vector_impl::vec<4, U2>& v2, const vector_impl::vec<4, U3>& v3)
    : data{column_type(v0), column_type(v1), column_type(v2), column_type(v3)}
    {
    }

    template <typename U0, typename U1, typename U2, typename U3>
    constexpr matrix_base(const vector_impl::vec<3, U0>& v0, const vector_impl::vec<3, U1>& v1, const vector_impl::vec<3, U2>& v2, const vector_impl::vec<3, U3>& v3)
    : data{column_type(v0), column_type(v1), column_type(v2), column_type(v3)}
    {
    }

    template <typename U0, typename U1, typename U2, typename U3>
    constexpr matrix_base(const vector_impl::vec<2, U0>& v0, const vector_impl::vec<2, U1>& v1, const vector_impl::vec<2, U2>& v2, const vector_impl::vec<2, U3>& v3)
    : data{column_type(v0), column_type(v1), column_type(v2), column_type(v3)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<4, 4, U>& other)
    : data{column_type(other[0]), column_type(other[1]), column_type(other[2]), column_type(other[3])}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<4, 3, U>& other)
    : data{column_type(other[0]), column_type(other[1]), column_type(other[2]), column_type(other[3])}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<4, 2, U>& other)
    : data{column_type(other[0]), column_type(other[1]), column_type(other[2]), column_type(other[3])}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<3, 4, U>& other)
    : data{column_type(other[0]), column_type(other[1]), column_type(other[2]), column_type(0, 0)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<3, 3, U>& other)
    : data{column_type(other[0]), column_type(other[1]), column_type(other[2]), column_type(0, 0)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<3, 2, U>& other)
    : data{column_type(other[0]), column_type(other[1]), column_type(other[2]), column_type(0, 0)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<2, 4, U>& other)
    : data{column_type(other[0]), column_type(other[1]), column_type(0, 0), column_type(0, 0)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<2, 3, U>& other)
    : data{column_type(other[0]), column_type(other[1]), column_type(0, 0), column_type(0, 0)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<2, 2, U>& other)
    : data{column_type(other[0]), column_type(other[1]), column_type(0, 0), column_type(0, 0)}
    {
    }

    protected:
    column_type data[4];
};

template <typename T>
struct matrix_base<3, 4, T>
{
    static_assert(std::is_arithmetic<T>::value, "integral or floating point type required");

    using value_type  = T;
    using column_type = vector_impl::vec<4, T>;
    using row_type    = vector_impl::vec<3, T>;

    explicit constexpr matrix_base(const T& v)
    : data{column_type(v, 0, 0, 0), column_type(0, v, 0, 0), column_type(0, 0, v, 0)}
    {
    }

    constexpr matrix_base() : matrix_base(T(1))
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const U* const p) : data{column_type(p), column_type(p + 4), column_type(p + 8)}
    {
        static_assert(std::is_same<T, U>::value, "only valid pointer type is acceptable");
    }

    constexpr matrix_base(const T& v00, const T& v01, const T& v02, const T& v03, const T& v10, const T& v11, const T& v12, const T& v13, const T& v20, const T& v21, const T& v22, const T& v23)
    : data{column_type(v00, v01, v02, v03), column_type(v10, v11, v12, v13), column_type(v20, v21, v22, v23)}
    {
    }

    template <typename X00, typename Y01, typename Z02, typename W03, typename X10, typename Y11, typename Z12, typename W13, typename X20, typename Y21, typename Z22, typename W23>
    constexpr matrix_base(const X00& v00, const Y01& v01, const Z02& v02, const W03& v03, const X10& v10, const Y11& v11, const Z12& v12, const W13& v13, const X20& v20, const Y21& v21, const Z22& v22, const W23& v23)
    : data{column_type(v00, v01, v02, v03), column_type(v10, v11, v12, v13), column_type(v20, v21, v22, v23)}
    {
    }

    template <typename U0, typename U1, typename U2>
    constexpr matrix_base(const vector_impl::vec<4, U0>& v0, const vector_impl::vec<4, U1>& v1, const vector_impl::vec<4, U2>& v2)
    : data{column_type(v0), column_type(v1), column_type(v2)}
    {
    }

    template <typename U0, typename U1, typename U2, typename X, typename Y, typename Z>
    constexpr matrix_base(const vector_impl::vec<3, U0>& v0, const X& s0, const vector_impl::vec<3, U1>& v1, const Y& s1, const vector_impl::vec<3, U2>& v2, const Z& s2)
    : data{column_type(v0, s0), column_type(v1, s1), column_type(v2, s2)}
    {
    }

    template <typename U0, typename U1, typename U2, typename X, typename Y, typename Z>
    constexpr matrix_base(const X& s0, const vector_impl::vec<3, U0>& v0, const Y& s1, const vector_impl::vec<3, U1>& v1, const Z& s2, const vector_impl::vec<3, U2>& v2)
    : data{column_type(s0, v0), column_type(s1, v1), column_type(s2, v2)}
    {
    }

    template <typename U00, typename U01, typename U10, typename U11, typename U20, typename U21>
    constexpr matrix_base(const vector_impl::vec<2, U00>& v00, const vector_impl::vec<2, U01>& v01, const vector_impl::vec<2, U10>& v10, const vector_impl::vec<2, U11>& v11, const vector_impl::vec<2, U20>& v20, const vector_impl::vec<2, U21>& v21)
    : data{column_type(v00, v01), column_type(v10, v11), column_type(v20, v21)}
    {
    }

    template <typename U00, typename S01, typename S02, typename U10, typename S11, typename S12, typename U20, typename S21, typename S22>
    constexpr matrix_base(const vector_impl::vec<2, U00>& v00, const S01& s01, const S02& s02, const vector_impl::vec<2, U10>& v10, const S11& s11, const S12& s12, const vector_impl::vec<2, U20>& v20, const S21& s21, const S22& s22)
    : data{column_type(v00, s01, s02), column_type(v10, s11, s12), column_type(v20, s21, s22)}
    {
    }

    template <typename S00, typename U01, typename S02, typename S10, typename U11, typename S12, typename S20, typename U21, typename S22>
    constexpr matrix_base(const S00& s00, const vector_impl::vec<2, U01>& v01, const S02& s02, const S10& s10, const vector_impl::vec<2, U11>& v11, const S12& s12, const S20& s20, const vector_impl::vec<2, U21>& v21, const S22& s22)
    : data{column_type(s00, v01, s02), column_type(s10, v11, s12), column_type(s20, v21, s22)}
    {
    }

    template <typename S00, typename S01, typename U02, typename S10, typename S11, typename U12, typename S20, typename S21, typename U22>
    constexpr matrix_base(const S00& s00, const S01& s01, const vector_impl::vec<2, U02>& v02, const S10& s10, const S11& s11, const vector_impl::vec<2, U12>& v12, const S20& s20, const S21& s21, const vector_impl::vec<2, U22>& v22)
    : data{column_type(s00, s01, v02), column_type(s10, s11, v12), column_type(s20, s21, v22)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<4, 4, U>& other)
    : data{column_type(other[0]), column_type(other[1]), column_type(other[2])}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<4, 3, U>& other)
    : data{column_type(other[0], 0), column_type(other[1], 0), column_type(other[2], 0)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<4, 2, U>& other)
    : data{column_type(other[0], 0, 0), column_type(other[1], 0, 0), column_type(other[2], 1, 0)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<3, 4, U>& other)
    : data{column_type(other[0]), column_type(other[1]), column_type(other[2])}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<3, 3, U>& other)
    : data{column_type(other[0], 0), column_type(other[1], 0), column_type(other[2], 0)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<3, 2, U>& other)
    : data{column_type(other[0], 0, 0), column_type(other[1], 0, 0), column_type(other[2], 1, 0)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<2, 4, U>& other)
    : data{column_type(other[0]), column_type(other[1]), column_type(0, 0, 1, 0)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<2, 3, U>& other)
    : data{column_type(other[0], 0), column_type(other[1], 0), column_type(0, 0, 1, 0)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<2, 2, U>& other)
    : data{column_type(other[0], 0, 0), column_type(other[1], 0, 0), column_type(0, 0, 1, 0)}
    {
    }

    protected:
    column_type data[3];
};

template <typename T>
struct matrix_base<3, 3, T>
{
    static_assert(std::is_arithmetic<T>::value, "integral or floating point type required");

    using value_type  = T;
    using column_type = vector_impl::vec<3, T>;
    using row_type    = vector_impl::vec<3, T>;

    explicit constexpr matrix_base(const T& v) : data{column_type(v, 0, 0), column_type(0, v, 0), column_type(0, 0, v)}
    {
    }

    constexpr matrix_base() : matrix_base(T(1))
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const U* const p) : data{column_type(p), column_type(p + 3), column_type(p + 6)}
    {
        static_assert(std::is_same<T, U>::value, "only valid pointer type is acceptable");
    }

    constexpr matrix_base(const T& v00, const T& v01, const T& v02, const T& v10, const T& v11, const T& v12, const T& v20, const T& v21, const T& v22)
    : data{column_type(v00, v01, v02), column_type(v10, v11, v12), column_type(v20, v21, v22)}
    {
    }

    template <typename X00, typename Y01, typename Z02, typename X10, typename Y11, typename Z12, typename X20, typename Y21, typename Z22>
    constexpr matrix_base(const X00& v00, const Y01& v01, const Z02& v02, const X10& v10, const Y11& v11, const Z12& v12, const X20& v20, const Y21& v21, const Z22& v22)
    : data{column_type(v00, v01, v02), column_type(v10, v11, v12), column_type(v20, v21, v22)}
    {
    }

    template <typename U0, typename U1, typename U2>
    constexpr matrix_base(const vector_impl::vec<4, U0>& v0, const vector_impl::vec<4, U1>& v1, const vector_impl::vec<4, U2>& v2)
    : data{column_type(v0), column_type(v1), column_type(v2)}
    {
    }

    template <typename U0, typename U1, typename U2>
    constexpr matrix_base(const vector_impl::vec<3, U0>& v0, const vector_impl::vec<3, U1>& v1, const vector_impl::vec<3, U2>& v2)
    : data{column_type(v0), column_type(v1), column_type(v2)}
    {
    }

    template <typename U00, typename S01, typename U10, typename S11, typename U20, typename S21>
    constexpr matrix_base(const vector_impl::vec<2, U00>& v00, const S01& s01, const vector_impl::vec<2, U10>& v10, const S11& s11, const vector_impl::vec<2, U20>& v20, const S21& s21)
    : data{column_type(v00, s01), column_type(v10, s11), column_type(v20, s21)}
    {
    }

    template <typename S00, typename U01, typename S10, typename U11, typename S20, typename U21>
    constexpr matrix_base(const S00& s00, const vector_impl::vec<2, U01>& v01, const S10& s10, const vector_impl::vec<2, U11>& v11, const S20& s20, const vector_impl::vec<2, U21>& v21)
    : data{column_type(s00, v01), column_type(s10, v11), column_type(s20, v21)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<4, 4, U>& other)
    : data{column_type(other[0]), column_type(other[1]), column_type(other[2])}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<4, 3, U>& other)
    : data{column_type(other[0]), column_type(other[1]), column_type(other[2])}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<4, 2, U>& other)
    : data{column_type(other[0], 0), column_type(other[1], 0), column_type(other[2], 1)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<3, 4, U>& other)
    : data{column_type(other[0]), column_type(other[1]), column_type(other[2])}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<3, 3, U>& other)
    : data{column_type(other[0]), column_type(other[1]), column_type(other[2])}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<3, 2, U>& other)
    : data{column_type(other[0], 0), column_type(other[1], 0), column_type(other[2], 1)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<2, 4, U>& other)
    : data{column_type(other[0]), column_type(other[1]), column_type(0, 0, 1)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<2, 3, U>& other)
    : data{column_type(other[0]), column_type(other[1]), column_type(0, 0, 1)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<2, 2, U>& other)
    : data{column_type(other[0], 0), column_type(other[1], 0), column_type(0, 0, 1)}
    {
    }

    protected:
    column_type data[3];
};

template <typename T>
struct matrix_base<3, 2, T>
{
    static_assert(std::is_arithmetic<T>::value, "integral or floating point type required");

    using value_type  = T;
    using column_type = vector_impl::vec<2, T>;
    using row_type    = vector_impl::vec<3, T>;

    explicit constexpr matrix_base(const T& v) : data{column_type(v, 0), column_type(0, v), column_type(0, 0)}
    {
    }

    constexpr matrix_base() : matrix_base(T(1))
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const U* const p) : data{column_type(p), column_type(p + 2), column_type(p + 4)}
    {
        static_assert(std::is_same<T, U>::value, "only valid pointer type is acceptable");
    }

    constexpr matrix_base(const T& v00, const T& v01, const T& v10, const T& v11, const T& v20, const T& v21)
    : data{column_type(v00, v01), column_type(v10, v11), column_type(v20, v21)}
    {
    }

    template <typename X00, typename Y01, typename X10, typename Y11, typename X20, typename Y21>
    constexpr matrix_base(const X00& v00, const Y01& v01, const X10& v10, const Y11& v11, const X20& v20, const Y21& v21)
    : data{column_type(v00, v01), column_type(v10, v11), column_type(v20, v21)}
    {
    }

    template <typename U0, typename U1, typename U2>
    constexpr matrix_base(const vector_impl::vec<4, U0>& v0, const vector_impl::vec<4, U1>& v1, const vector_impl::vec<4, U2>& v2)
    : data{column_type(v0), column_type(v1), column_type(v2)}
    {
    }

    template <typename U0, typename U1, typename U2>
    constexpr matrix_base(const vector_impl::vec<3, U0>& v0, const vector_impl::vec<3, U1>& v1, const vector_impl::vec<3, U2>& v2)
    : data{column_type(v0), column_type(v1), column_type(v2)}
    {
    }

    template <typename U0, typename U1, typename U2>
    constexpr matrix_base(const vector_impl::vec<2, U0>& v0, const vector_impl::vec<2, U1>& v1, const vector_impl::vec<2, U2>& v2)
    : data{column_type(v0), column_type(v1), column_type(v2)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<4, 4, U>& other)
    : data{column_type(other[0]), column_type(other[1]), column_type(other[2])}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<4, 3, U>& other)
    : data{column_type(other[0]), column_type(other[1]), column_type(other[2])}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<4, 2, U>& other)
    : data{column_type(other[0]), column_type(other[1]), column_type(other[2])}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<3, 4, U>& other)
    : data{column_type(other[0]), column_type(other[1]), column_type(other[2])}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<3, 3, U>& other)
    : data{column_type(other[0]), column_type(other[1]), column_type(other[2])}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<3, 2, U>& other)
    : data{column_type(other[0]), column_type(other[1]), column_type(other[2])}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<2, 4, U>& other)
    : data{column_type(other[0]), column_type(other[1]), column_type(0, 0)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<2, 3, U>& other)
    : data{column_type(other[0]), column_type(other[1]), column_type(0, 0)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<2, 2, U>& other)
    : data{column_type(other[0]), column_type(other[1]), column_type(0, 0)}
    {
    }

    protected:
    column_type data[3];
};

template <typename T>
struct matrix_base<2, 4, T>
{
    static_assert(std::is_arithmetic<T>::value, "integral or floating point type required");

    using value_type  = T;
    using column_type = vector_impl::vec<4, T>;
    using row_type    = vector_impl::vec<2, T>;

    explicit constexpr matrix_base(const T& v) : data{column_type(v, 0, 0, 0), column_type(0, v, 0, 0)}
    {
    }

    constexpr matrix_base() : matrix_base(T(1))
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const U* const p) : data{column_type(p), column_type(p + 4)}
    {
        static_assert(std::is_same<T, U>::value, "only valid pointer type is acceptable");
    }

    constexpr matrix_base(const T& v00, const T& v01, const T& v02, const T& v03, const T& v10, const T& v11, const T& v12, const T& v13)
    : data{column_type(v00, v01, v02, v03), column_type(v10, v11, v12, v13)}
    {
    }

    template <typename X00, typename Y01, typename Z02, typename W03, typename X10, typename Y11, typename Z12, typename W13>
    constexpr matrix_base(const X00& v00, const Y01& v01, const Z02& v02, const W03& v03, const X10& v10, const Y11& v11, const Z12& v12, const W13& v13)
    : data{column_type(v00, v01, v02, v03), column_type(v10, v11, v12, v13)}
    {
    }

    template <typename U0, typename U1>
    constexpr matrix_base(const vector_impl::vec<4, U0>& v0, const vector_impl::vec<4, U1>& v1)
    : data{column_type(v0), column_type(v1)}
    {
    }

    template <typename U0, typename U1, typename X, typename Y>
    constexpr matrix_base(const vector_impl::vec<3, U0>& v0, const X& s0, const vector_impl::vec<3, U1>& v1, const Y& s1)
    : data{column_type(v0, s0), column_type(v1, s1)}
    {
    }

    template <typename U0, typename U1, typename X, typename Y>
    constexpr matrix_base(const X& s0, const vector_impl::vec<3, U0>& v0, const Y& s1, const vector_impl::vec<3, U1>& v1)
    : data{column_type(s0, v0), column_type(s1, v1)}
    {
    }

    template <typename U00, typename U01, typename U10, typename U11>
    constexpr matrix_base(const vector_impl::vec<2, U00>& v00, const vector_impl::vec<2, U01>& v01, const vector_impl::vec<2, U10>& v10, const vector_impl::vec<2, U11>& v11)
    : data{column_type(v00, v01), column_type(v10, v11)}
    {
    }

    template <typename U00, typename S01, typename S02, typename U10, typename S11, typename S12>
    constexpr matrix_base(const vector_impl::vec<2, U00>& v00, const S01& s01, const S02& s02, const vector_impl::vec<2, U10>& v10, const S11& s11, const S12& s12)
    : data{column_type(v00, s01, s02), column_type(v10, s11, s12)}
    {
    }

    template <typename S00, typename U01, typename S02, typename S10, typename U11, typename S12>
    constexpr matrix_base(const S00& s00, const vector_impl::vec<2, U01>& v01, const S02& s02, const S10& s10, const vector_impl::vec<2, U11>& v11, const S12& s12)
    : data{column_type(s00, v01, s02), column_type(s10, v11, s12)}
    {
    }

    template <typename S00, typename S01, typename U02, typename S10, typename S11, typename U12>
    constexpr matrix_base(const S00& s00, const S01& s01, const vector_impl::vec<2, U02>& v02, const S10& s10, const S11& s11, const vector_impl::vec<2, U12>& v12)
    : data{column_type(s00, s01, v02), column_type(s10, s11, v12)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<4, 4, U>& other) : data{column_type(other[0]), column_type(other[1])}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<4, 3, U>& other)
    : data{column_type(other[0], 0), column_type(other[1], 0)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<4, 2, U>& other)
    : data{column_type(other[0], 0, 0), column_type(other[1], 0, 0)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<3, 4, U>& other) : data{column_type(other[0]), column_type(other[1])}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<3, 3, U>& other)
    : data{column_type(other[0], 0), column_type(other[1], 0)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<3, 2, U>& other)
    : data{column_type(other[0], 0, 0), column_type(other[1], 0, 0)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<2, 4, U>& other) : data{column_type(other[0]), column_type(other[1])}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<2, 3, U>& other)
    : data{column_type(other[0], 0), column_type(other[1], 0)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<2, 2, U>& other)
    : data{column_type(other[0], 0, 0), column_type(other[1], 0, 0)}
    {
    }

    protected:
    column_type data[2];
};

template <typename T>
struct matrix_base<2, 3, T>
{
    static_assert(std::is_arithmetic<T>::value, "integral or floating point type required");

    using value_type  = T;
    using column_type = vector_impl::vec<3, T>;
    using row_type    = vector_impl::vec<2, T>;

    explicit constexpr matrix_base(const T& v) : data{column_type(v, 0, 0), column_type(0, v, 0)}
    {
    }

    constexpr matrix_base() : matrix_base(T(1))
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const U* const p) : data{column_type(p), column_type(p + 3)}
    {
        static_assert(std::is_same<T, U>::value, "only valid pointer type is acceptable");
    }

    constexpr matrix_base(const T& v00, const T& v01, const T& v02, const T& v10, const T& v11, const T& v12)
    : data{column_type(v00, v01, v02), column_type(v10, v11, v12)}
    {
    }

    template <typename X00, typename Y01, typename Z02, typename X10, typename Y11, typename Z12>
    constexpr matrix_base(const X00& v00, const Y01& v01, const Z02& v02, const X10& v10, const Y11& v11, const Z12& v12)
    : data{column_type(v00, v01, v02), column_type(v10, v11, v12)}
    {
    }

    template <typename U0, typename U1>
    constexpr matrix_base(const vector_impl::vec<4, U0>& v0, const vector_impl::vec<4, U1>& v1)
    : data{column_type(v0), column_type(v1)}
    {
    }

    template <typename U0, typename U1>
    constexpr matrix_base(const vector_impl::vec<3, U0>& v0, const vector_impl::vec<3, U1>& v1)
    : data{column_type(v0), column_type(v1)}
    {
    }

    template <typename U00, typename S01, typename U10, typename S11>
    constexpr matrix_base(const vector_impl::vec<2, U00>& v00, const S01& s01, const vector_impl::vec<2, U10>& v10, const S11& s11)
    : data{column_type(v00, s01), column_type(v10, s11)}
    {
    }

    template <typename S00, typename U01, typename S10, typename U11>
    constexpr matrix_base(const S00& s00, const vector_impl::vec<2, U01>& v01, const S10& s10, const vector_impl::vec<2, U11>& v11)
    : data{column_type(s00, v01), column_type(s10, v11)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<4, 4, U>& other) : data{column_type(other[0]), column_type(other[1])}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<4, 3, U>& other) : data{column_type(other[0]), column_type(other[1])}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<4, 2, U>& other)
    : data{column_type(other[0], 0), column_type(other[1], 0)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<3, 4, U>& other) : data{column_type(other[0]), column_type(other[1])}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<3, 3, U>& other) : data{column_type(other[0]), column_type(other[1])}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<3, 2, U>& other)
    : data{column_type(other[0], 0), column_type(other[1], 0)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<2, 4, U>& other) : data{column_type(other[0]), column_type(other[1])}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<2, 3, U>& other) : data{column_type(other[0]), column_type(other[1])}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<2, 2, U>& other)
    : data{column_type(other[0], 0), column_type(other[1], 0)}
    {
    }

    protected:
    column_type data[2];
};

template <typename T>
struct matrix_base<2, 2, T>
{
    static_assert(std::is_arithmetic<T>::value, "integral or floating point type required");

    using value_type  = T;
    using column_type = vector_impl::vec<2, T>;
    using row_type    = vector_impl::vec<2, T>;

    explicit constexpr matrix_base(const T& v) : data{column_type(v, 0), column_type(0, v)}
    {
    }

    constexpr matrix_base() : matrix_base(T(1))
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const U* const p) : data{column_type(p), column_type(p + 2)}
    {
        static_assert(std::is_same<T, U>::value, "only valid pointer type is acceptable");
    }

    constexpr matrix_base(const T& v00, const T& v01, const T& v10, const T& v11)
    : data{column_type(v00, v01), column_type(v10, v11)}
    {
    }

    template <typename X00, typename Y01, typename X10, typename Y11>
    constexpr matrix_base(const X00& v00, const Y01& v01, const X10& v10, const Y11& v11)
    : data{column_type(v00, v01), column_type(v10, v11)}
    {
    }

    template <typename U0, typename U1>
    constexpr matrix_base(const vector_impl::vec<4, U0>& v0, const vector_impl::vec<4, U1>& v1)
    : data{column_type(v0), column_type(v1)}
    {
    }

    template <typename U0, typename U1>
    constexpr matrix_base(const vector_impl::vec<3, U0>& v0, const vector_impl::vec<3, U1>& v1)
    : data{column_type(v0), column_type(v1)}
    {
    }

    template <typename U0, typename U1>
    constexpr matrix_base(const vector_impl::vec<2, U0>& v0, const vector_impl::vec<2, U1>& v1)
    : data{column_type(v0), column_type(v1)}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<4, 4, U>& other) : data{column_type(other[0]), column_type(other[1])}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<4, 3, U>& other) : data{column_type(other[0]), column_type(other[1])}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<4, 2, U>& other) : data{column_type(other[0]), column_type(other[1])}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<3, 4, U>& other) : data{column_type(other[0]), column_type(other[1])}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<3, 3, U>& other) : data{column_type(other[0]), column_type(other[1])}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<3, 2, U>& other) : data{column_type(other[0]), column_type(other[1])}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<2, 4, U>& other) : data{column_type(other[0]), column_type(other[1])}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<2, 3, U>& other) : data{column_type(other[0]), column_type(other[1])}
    {
    }

    template <typename U>
    explicit constexpr matrix_base(const matrix<2, 2, U>& other) : data{column_type(other[0]), column_type(other[1])}
    {
    }

    protected:
    column_type data[2];
};

// default constructor
template <U32 C, U32 R, typename T>
constexpr matrix<C, R, T>::matrix() : base_type()
{
}

// matrix methods
template <U32 C, U32 R, typename T>
inline constexpr U32 matrix<C, R, T>::size() const
{
    return C;
}

template <U32 C, U32 R, typename T>
inline typename matrix<C, R, T>::value_type* matrix<C, R, T>::data()
{
    return base_type::data[0].data();
}

template <U32 C, U32 R, typename T>
inline const typename matrix<C, R, T>::value_type* matrix<C, R, T>::data() const
{
    return base_type::data[0].data();
}

template <U32 C, U32 R, typename T>
inline typename matrix<C, R, T>::column_type matrix<C, R, T>::column(U32 index) const
{
    assert_msg(index < C, "Wrong index");
    return base_type::data[index];
}

template <U32 C, U32 R, typename T>
inline typename matrix<C, R, T>::row_type matrix<C, R, T>::row(U32 index) const
{
    assert_msg(index < R, "Wrong index");
    return utils::type_creator<C>::template create<typename matrix<C, R, T>::row_type>(
    [this, index](U32 col) { return base_type::data[col][index]; });
}

// access operator
template <U32 C, U32 R, typename T>
inline typename matrix<C, R, T>::column_type& matrix<C, R, T>::operator[](U32 index)
{
    assert_msg(index < C, "Wrong index");
    return base_type::data[index];
}

template <U32 C, U32 R, typename T>
inline const typename matrix<C, R, T>::column_type& matrix<C, R, T>::operator[](U32 index) const
{
    assert_msg(index < C, "Wrong index");
    return base_type::data[index];
}

// assignment operator
template <U32 C, U32 R, typename T>
template <typename U>
inline matrix<C, R, T>& matrix<C, R, T>::operator=(const matrix<C, R, U>& other)
{
    for (U32 i = 0; i < C; ++i) {
        base_type::data[i] = static_cast<column_type>(other[i]);
    }
    return *this;
}

// unary operators
// matrix - matrix
template <U32 C, U32 R, typename T>
template <typename U>
inline matrix<C, R, T>& matrix<C, R, T>::operator+=(const matrix<C, R, U>& other)
{
    for (U32 i = 0; i < C; ++i) {
        base_type::data[i] += other[i];
    }
    return *this;
}

template <U32 C, U32 R, typename T>
template <typename U>
inline matrix<C, R, T>& matrix<C, R, T>::operator-=(const matrix<C, R, U>& other)
{
    for (U32 i = 0; i < C; ++i) {
        base_type::data[i] -= other[i];
    }
    return *this;
}

template <U32 C, U32 R, typename T>
template <typename U>
inline matrix<C, R, T>& matrix<C, R, T>::operator*=(const matrix<C, C, U>& other)
{
    return (*this = *this * other);
}

// unary operators
// matrix - scalar

template <U32 C, U32 R, typename T>
template <typename U>
inline matrix<C, R, T>& matrix<C, R, T>::operator+=(const U& scalar)
{
    for (U32 i = 0; i < C; ++i) {
        base_type::data[i] += scalar;
    }
    return *this;
}

template <U32 C, U32 R, typename T>
template <typename U>
inline matrix<C, R, T>& matrix<C, R, T>::operator-=(const U& scalar)
{
    for (U32 i = 0; i < C; ++i) {
        base_type::data[i] -= scalar;
    }
    return *this;
}

template <U32 C, U32 R, typename T>
template <typename U>
inline matrix<C, R, T>& matrix<C, R, T>::operator*=(const U& scalar)
{
    for (U32 i = 0; i < C; ++i) {
        base_type::data[i] *= scalar;
    }
    return *this;
}

template <U32 C, U32 R, typename T>
template <typename U>
inline matrix<C, R, T>& matrix<C, R, T>::operator/=(const U& scalar)
{
    for (U32 i = 0; i < C; ++i) {
        base_type::data[i] /= scalar;
    }
    return *this;
}

// unary minus
template <U32 R, typename T>
inline matrix<4, R, T> operator-(const matrix<4, R, T>& m)
{
    return matrix<4, R, T>(-m[0], -m[1], -m[2], -m[3]);
}

template <U32 R, typename T>
inline matrix<3, R, T> operator-(const matrix<3, R, T>& m)
{
    return matrix<3, R, T>(-m[0], -m[1], -m[2]);
}

template <U32 R, typename T>
inline matrix<2, R, T> operator-(const matrix<2, R, T>& m)
{
    return matrix<2, R, T>(-m[0], -m[1]);
}

// unary plus
template <U32 C, U32 R, typename T>
inline matrix<C, R, T> operator+(const matrix<C, R, T>& m)
{
    return m;
}


// TODO make it same type
// binary operators
// TODO: simplify
template <typename T, typename U, typename RT = decltype(std::declval<T>() * std::declval<U>())>
inline const matrix<4, 4, RT> operator*(const matrix<4, 4, T>& lhs, const matrix<4, 4, U>& rhs)
{
    return matrix<4, 4, RT>(lhs[0][0] * rhs[0][0] + lhs[1][0] * rhs[0][1] + lhs[2][0] * rhs[0][2] + lhs[3][0] * rhs[0][3], lhs[0][1] * rhs[0][0] + lhs[1][1] * rhs[0][1] + lhs[2][1] * rhs[0][2] + lhs[3][1] * rhs[0][3], lhs[0][2] * rhs[0][0] + lhs[1][2] * rhs[0][1] + lhs[2][2] * rhs[0][2] + lhs[3][2] * rhs[0][3], lhs[0][3] * rhs[0][0] + lhs[1][3] * rhs[0][1] + lhs[2][3] * rhs[0][2] + lhs[3][3] * rhs[0][3],

                            lhs[0][0] * rhs[1][0] + lhs[1][0] * rhs[1][1] + lhs[2][0] * rhs[1][2] + lhs[3][0] * rhs[1][3], lhs[0][1] * rhs[1][0] + lhs[1][1] * rhs[1][1] + lhs[2][1] * rhs[1][2] + lhs[3][1] * rhs[1][3], lhs[0][2] * rhs[1][0] + lhs[1][2] * rhs[1][1] + lhs[2][2] * rhs[1][2] + lhs[3][2] * rhs[1][3], lhs[0][3] * rhs[1][0] + lhs[1][3] * rhs[1][1] + lhs[2][3] * rhs[1][2] + lhs[3][3] * rhs[1][3],

                            lhs[0][0] * rhs[2][0] + lhs[1][0] * rhs[2][1] + lhs[2][0] * rhs[2][2] + lhs[3][0] * rhs[2][3], lhs[0][1] * rhs[2][0] + lhs[1][1] * rhs[2][1] + lhs[2][1] * rhs[2][2] + lhs[3][1] * rhs[2][3], lhs[0][2] * rhs[2][0] + lhs[1][2] * rhs[2][1] + lhs[2][2] * rhs[2][2] + lhs[3][2] * rhs[2][3], lhs[0][3] * rhs[2][0] + lhs[1][3] * rhs[2][1] + lhs[2][3] * rhs[2][2] + lhs[3][3] * rhs[2][3],

                            lhs[0][0] * rhs[3][0] + lhs[1][0] * rhs[3][1] + lhs[2][0] * rhs[3][2] + lhs[3][0] * rhs[3][3], lhs[0][1] * rhs[3][0] + lhs[1][1] * rhs[3][1] + lhs[2][1] * rhs[3][2] + lhs[3][1] * rhs[3][3], lhs[0][2] * rhs[3][0] + lhs[1][2] * rhs[3][1] + lhs[2][2] * rhs[3][2] + lhs[3][2] * rhs[3][3], lhs[0][3] * rhs[3][0] + lhs[1][3] * rhs[3][1] + lhs[2][3] * rhs[3][2] + lhs[3][3] * rhs[3][3]);
}

template <typename T, typename U, typename RT = decltype(std::declval<T>() * std::declval<U>())>
inline const matrix<3, 4, RT> operator*(const matrix<4, 4, T>& lhs, const matrix<3, 4, U>& rhs)
{
    return matrix<3, 4, RT>(lhs[0][0] * rhs[0][0] + lhs[1][0] * rhs[0][1] + lhs[2][0] * rhs[0][2] + lhs[3][0] * rhs[0][3], lhs[0][1] * rhs[0][0] + lhs[1][1] * rhs[0][1] + lhs[2][1] * rhs[0][2] + lhs[3][1] * rhs[0][3], lhs[0][2] * rhs[0][0] + lhs[1][2] * rhs[0][1] + lhs[2][2] * rhs[0][2] + lhs[3][2] * rhs[0][3], lhs[0][3] * rhs[0][0] + lhs[1][3] * rhs[0][1] + lhs[2][3] * rhs[0][2] + lhs[3][3] * rhs[0][3],

                            lhs[0][0] * rhs[1][0] + lhs[1][0] * rhs[1][1] + lhs[2][0] * rhs[1][2] + lhs[3][0] * rhs[1][3], lhs[0][1] * rhs[1][0] + lhs[1][1] * rhs[1][1] + lhs[2][1] * rhs[1][2] + lhs[3][1] * rhs[1][3], lhs[0][2] * rhs[1][0] + lhs[1][2] * rhs[1][1] + lhs[2][2] * rhs[1][2] + lhs[3][2] * rhs[1][3], lhs[0][3] * rhs[1][0] + lhs[1][3] * rhs[1][1] + lhs[2][3] * rhs[1][2] + lhs[3][3] * rhs[1][3],

                            lhs[0][0] * rhs[2][0] + lhs[1][0] * rhs[2][1] + lhs[2][0] * rhs[2][2] + lhs[3][0] * rhs[2][3], lhs[0][1] * rhs[2][0] + lhs[1][1] * rhs[2][1] + lhs[2][1] * rhs[2][2] + lhs[3][1] * rhs[2][3], lhs[0][2] * rhs[2][0] + lhs[1][2] * rhs[2][1] + lhs[2][2] * rhs[2][2] + lhs[3][2] * rhs[2][3], lhs[0][3] * rhs[2][0] + lhs[1][3] * rhs[2][1] + lhs[2][3] * rhs[2][2] + lhs[3][3] * rhs[2][3]);
}

template <typename T, typename U, typename RT = decltype(std::declval<T>() * std::declval<U>())>
inline const matrix<2, 4, RT> operator*(const matrix<4, 4, T>& lhs, const matrix<2, 4, U>& rhs)
{
    return matrix<2, 4, RT>(lhs[0][0] * rhs[0][0] + lhs[1][0] * rhs[0][1] + lhs[2][0] * rhs[0][2] + lhs[3][0] * rhs[0][3], lhs[0][1] * rhs[0][0] + lhs[1][1] * rhs[0][1] + lhs[2][1] * rhs[0][2] + lhs[3][1] * rhs[0][3], lhs[0][2] * rhs[0][0] + lhs[1][2] * rhs[0][1] + lhs[2][2] * rhs[0][2] + lhs[3][2] * rhs[0][3], lhs[0][3] * rhs[0][0] + lhs[1][3] * rhs[0][1] + lhs[2][3] * rhs[0][2] + lhs[3][3] * rhs[0][3],

                            lhs[0][0] * rhs[1][0] + lhs[1][0] * rhs[1][1] + lhs[2][0] * rhs[1][2] + lhs[3][0] * rhs[1][3], lhs[0][1] * rhs[1][0] + lhs[1][1] * rhs[1][1] + lhs[2][1] * rhs[1][2] + lhs[3][1] * rhs[1][3], lhs[0][2] * rhs[1][0] + lhs[1][2] * rhs[1][1] + lhs[2][2] * rhs[1][2] + lhs[3][2] * rhs[1][3], lhs[0][3] * rhs[1][0] + lhs[1][3] * rhs[1][1] + lhs[2][3] * rhs[1][2] + lhs[3][3] * rhs[1][3]);
}

template <typename T, typename U, typename RT = decltype(std::declval<T>() * std::declval<U>())>
inline const matrix<4, 3, RT> operator*(const matrix<4, 3, T>& lhs, const matrix<4, 4, U>& rhs)
{
    return matrix<4, 3, RT>(lhs[0][0] * rhs[0][0] + lhs[1][0] * rhs[0][1] + lhs[2][0] * rhs[0][2] + lhs[3][0] * rhs[0][3], lhs[0][1] * rhs[0][0] + lhs[1][1] * rhs[0][1] + lhs[2][1] * rhs[0][2] + lhs[3][1] * rhs[0][3], lhs[0][2] * rhs[0][0] + lhs[1][2] * rhs[0][1] + lhs[2][2] * rhs[0][2] + lhs[3][2] * rhs[0][3],

                            lhs[0][0] * rhs[1][0] + lhs[1][0] * rhs[1][1] + lhs[2][0] * rhs[1][2] + lhs[3][0] * rhs[1][3], lhs[0][1] * rhs[1][0] + lhs[1][1] * rhs[1][1] + lhs[2][1] * rhs[1][2] + lhs[3][1] * rhs[1][3], lhs[0][2] * rhs[1][0] + lhs[1][2] * rhs[1][1] + lhs[2][2] * rhs[1][2] + lhs[3][2] * rhs[1][3],

                            lhs[0][0] * rhs[2][0] + lhs[1][0] * rhs[2][1] + lhs[2][0] * rhs[2][2] + lhs[3][0] * rhs[2][3], lhs[0][1] * rhs[2][0] + lhs[1][1] * rhs[2][1] + lhs[2][1] * rhs[2][2] + lhs[3][1] * rhs[2][3], lhs[0][2] * rhs[2][0] + lhs[1][2] * rhs[2][1] + lhs[2][2] * rhs[2][2] + lhs[3][2] * rhs[2][3],

                            lhs[0][0] * rhs[3][0] + lhs[1][0] * rhs[3][1] + lhs[2][0] * rhs[3][2] + lhs[3][0] * rhs[3][3], lhs[0][1] * rhs[3][0] + lhs[1][1] * rhs[3][1] + lhs[2][1] * rhs[3][2] + lhs[3][1] * rhs[3][3], lhs[0][2] * rhs[3][0] + lhs[1][2] * rhs[3][1] + lhs[2][2] * rhs[3][2] + lhs[3][2] * rhs[3][3]);
}

template <typename T, typename U, typename RT = decltype(std::declval<T>() * std::declval<U>())>
inline const matrix<3, 3, RT> operator*(const matrix<4, 3, T>& lhs, const matrix<3, 4, U>& rhs)
{
    return matrix<3, 3, RT>(lhs[0][0] * rhs[0][0] + lhs[1][0] * rhs[0][1] + lhs[2][0] * rhs[0][2] + lhs[3][0] * rhs[0][3], lhs[0][1] * rhs[0][0] + lhs[1][1] * rhs[0][1] + lhs[2][1] * rhs[0][2] + lhs[3][1] * rhs[0][3], lhs[0][2] * rhs[0][0] + lhs[1][2] * rhs[0][1] + lhs[2][2] * rhs[0][2] + lhs[3][2] * rhs[0][3],

                            lhs[0][0] * rhs[1][0] + lhs[1][0] * rhs[1][1] + lhs[2][0] * rhs[1][2] + lhs[3][0] * rhs[1][3], lhs[0][1] * rhs[1][0] + lhs[1][1] * rhs[1][1] + lhs[2][1] * rhs[1][2] + lhs[3][1] * rhs[1][3], lhs[0][2] * rhs[1][0] + lhs[1][2] * rhs[1][1] + lhs[2][2] * rhs[1][2] + lhs[3][2] * rhs[1][3],

                            lhs[0][0] * rhs[2][0] + lhs[1][0] * rhs[2][1] + lhs[2][0] * rhs[2][2] + lhs[3][0] * rhs[2][3], lhs[0][1] * rhs[2][0] + lhs[1][1] * rhs[2][1] + lhs[2][1] * rhs[2][2] + lhs[3][1] * rhs[2][3], lhs[0][2] * rhs[2][0] + lhs[1][2] * rhs[2][1] + lhs[2][2] * rhs[2][2] + lhs[3][2] * rhs[2][3]);
}

template <typename T, typename U, typename RT = decltype(std::declval<T>() * std::declval<U>())>
inline const matrix<2, 3, RT> operator*(const matrix<4, 3, T>& lhs, const matrix<2, 4, U>& rhs)
{
    return matrix<2, 3, RT>(lhs[0][0] * rhs[0][0] + lhs[1][0] * rhs[0][1] + lhs[2][0] * rhs[0][2] + lhs[3][0] * rhs[0][3], lhs[0][1] * rhs[0][0] + lhs[1][1] * rhs[0][1] + lhs[2][1] * rhs[0][2] + lhs[3][1] * rhs[0][3], lhs[0][2] * rhs[0][0] + lhs[1][2] * rhs[0][1] + lhs[2][2] * rhs[0][2] + lhs[3][2] * rhs[0][3],

                            lhs[0][0] * rhs[1][0] + lhs[1][0] * rhs[1][1] + lhs[2][0] * rhs[1][2] + lhs[3][0] * rhs[1][3], lhs[0][1] * rhs[1][0] + lhs[1][1] * rhs[1][1] + lhs[2][1] * rhs[1][2] + lhs[3][1] * rhs[1][3], lhs[0][2] * rhs[1][0] + lhs[1][2] * rhs[1][1] + lhs[2][2] * rhs[1][2] + lhs[3][2] * rhs[1][3]);
}

template <typename T, typename U, typename RT = decltype(std::declval<T>() * std::declval<U>())>
inline const matrix<4, 2, RT> operator*(const matrix<4, 2, T>& lhs, const matrix<4, 4, U>& rhs)
{
    return matrix<4, 2, RT>(lhs[0][0] * rhs[0][0] + lhs[1][0] * rhs[0][1] + lhs[2][0] * rhs[0][2] + lhs[3][0] * rhs[0][3], lhs[0][1] * rhs[0][0] + lhs[1][1] * rhs[0][1] + lhs[2][1] * rhs[0][2] + lhs[3][1] * rhs[0][3],

                            lhs[0][0] * rhs[1][0] + lhs[1][0] * rhs[1][1] + lhs[2][0] * rhs[1][2] + lhs[3][0] * rhs[1][3], lhs[0][1] * rhs[1][0] + lhs[1][1] * rhs[1][1] + lhs[2][1] * rhs[1][2] + lhs[3][1] * rhs[1][3],

                            lhs[0][0] * rhs[2][0] + lhs[1][0] * rhs[2][1] + lhs[2][0] * rhs[2][2] + lhs[3][0] * rhs[2][3], lhs[0][1] * rhs[2][0] + lhs[1][1] * rhs[2][1] + lhs[2][1] * rhs[2][2] + lhs[3][1] * rhs[2][3],

                            lhs[0][0] * rhs[3][0] + lhs[1][0] * rhs[3][1] + lhs[2][0] * rhs[3][2] + lhs[3][0] * rhs[3][3], lhs[0][1] * rhs[3][0] + lhs[1][1] * rhs[3][1] + lhs[2][1] * rhs[3][2] + lhs[3][1] * rhs[3][3]);
}

template <typename T, typename U, typename RT = decltype(std::declval<T>() * std::declval<U>())>
inline const matrix<3, 2, RT> operator*(const matrix<4, 2, T>& lhs, const matrix<3, 4, U>& rhs)
{
    return matrix<3, 2, RT>(lhs[0][0] * rhs[0][0] + lhs[1][0] * rhs[0][1] + lhs[2][0] * rhs[0][2] + lhs[3][0] * rhs[0][3], lhs[0][1] * rhs[0][0] + lhs[1][1] * rhs[0][1] + lhs[2][1] * rhs[0][2] + lhs[3][1] * rhs[0][3],

                            lhs[0][0] * rhs[1][0] + lhs[1][0] * rhs[1][1] + lhs[2][0] * rhs[1][2] + lhs[3][0] * rhs[1][3], lhs[0][1] * rhs[1][0] + lhs[1][1] * rhs[1][1] + lhs[2][1] * rhs[1][2] + lhs[3][1] * rhs[1][3],

                            lhs[0][0] * rhs[2][0] + lhs[1][0] * rhs[2][1] + lhs[2][0] * rhs[2][2] + lhs[3][0] * rhs[2][3], lhs[0][1] * rhs[2][0] + lhs[1][1] * rhs[2][1] + lhs[2][1] * rhs[2][2] + lhs[3][1] * rhs[2][3]);
}

template <typename T, typename U, typename RT = decltype(std::declval<T>() * std::declval<U>())>
inline const matrix<2, 2, RT> operator*(const matrix<4, 2, T>& lhs, const matrix<2, 4, U>& rhs)
{
    return matrix<2, 2, RT>(lhs[0][0] * rhs[0][0] + lhs[1][0] * rhs[0][1] + lhs[2][0] * rhs[0][2] + lhs[3][0] * rhs[0][3], lhs[0][1] * rhs[0][0] + lhs[1][1] * rhs[0][1] + lhs[2][1] * rhs[0][2] + lhs[3][1] * rhs[0][3],

                            lhs[0][0] * rhs[1][0] + lhs[1][0] * rhs[1][1] + lhs[2][0] * rhs[1][2] + lhs[3][0] * rhs[1][3], lhs[0][1] * rhs[1][0] + lhs[1][1] * rhs[1][1] + lhs[2][1] * rhs[1][2] + lhs[3][1] * rhs[1][3]);
}

template <typename T, typename U, typename RT = decltype(std::declval<T>() * std::declval<U>())>
inline const matrix<4, 4, RT> operator*(const matrix<3, 4, T>& lhs, const matrix<4, 3, U>& rhs)
{
    return matrix<4, 4, RT>(lhs[0][0] * rhs[0][0] + lhs[1][0] * rhs[0][1] + lhs[2][0] * rhs[0][2], lhs[0][1] * rhs[0][0] + lhs[1][1] * rhs[0][1] + lhs[2][1] * rhs[0][2], lhs[0][2] * rhs[0][0] + lhs[1][2] * rhs[0][1] + lhs[2][2] * rhs[0][2], lhs[0][3] * rhs[0][0] + lhs[1][3] * rhs[0][1] + lhs[2][3] * rhs[0][2],

                            lhs[0][0] * rhs[1][0] + lhs[1][0] * rhs[1][1] + lhs[2][0] * rhs[1][2], lhs[0][1] * rhs[1][0] + lhs[1][1] * rhs[1][1] + lhs[2][1] * rhs[1][2], lhs[0][2] * rhs[1][0] + lhs[1][2] * rhs[1][1] + lhs[2][2] * rhs[1][2], lhs[0][3] * rhs[1][0] + lhs[1][3] * rhs[1][1] + lhs[2][3] * rhs[1][2],

                            lhs[0][0] * rhs[2][0] + lhs[1][0] * rhs[2][1] + lhs[2][0] * rhs[2][2], lhs[0][1] * rhs[2][0] + lhs[1][1] * rhs[2][1] + lhs[2][1] * rhs[2][2], lhs[0][2] * rhs[2][0] + lhs[1][2] * rhs[2][1] + lhs[2][2] * rhs[2][2], lhs[0][3] * rhs[2][0] + lhs[1][3] * rhs[2][1] + lhs[2][3] * rhs[2][2],

                            lhs[0][0] * rhs[3][0] + lhs[1][0] * rhs[3][1] + lhs[2][0] * rhs[3][2], lhs[0][1] * rhs[3][0] + lhs[1][1] * rhs[3][1] + lhs[2][1] * rhs[3][2], lhs[0][2] * rhs[3][0] + lhs[1][2] * rhs[3][1] + lhs[2][2] * rhs[3][2], lhs[0][3] * rhs[3][0] + lhs[1][3] * rhs[3][1] + lhs[2][3] * rhs[3][2]);
}

template <typename T, typename U, typename RT = decltype(std::declval<T>() * std::declval<U>())>
inline const matrix<3, 4, RT> operator*(const matrix<3, 4, T>& lhs, const matrix<3, 3, U>& rhs)
{
    return matrix<3, 4, RT>(lhs[0][0] * rhs[0][0] + lhs[1][0] * rhs[0][1] + lhs[2][0] * rhs[0][2], lhs[0][1] * rhs[0][0] + lhs[1][1] * rhs[0][1] + lhs[2][1] * rhs[0][2], lhs[0][2] * rhs[0][0] + lhs[1][2] * rhs[0][1] + lhs[2][2] * rhs[0][2], lhs[0][3] * rhs[0][0] + lhs[1][3] * rhs[0][1] + lhs[2][3] * rhs[0][2],

                            lhs[0][0] * rhs[1][0] + lhs[1][0] * rhs[1][1] + lhs[2][0] * rhs[1][2], lhs[0][1] * rhs[1][0] + lhs[1][1] * rhs[1][1] + lhs[2][1] * rhs[1][2], lhs[0][2] * rhs[1][0] + lhs[1][2] * rhs[1][1] + lhs[2][2] * rhs[1][2], lhs[0][3] * rhs[1][0] + lhs[1][3] * rhs[1][1] + lhs[2][3] * rhs[1][2],

                            lhs[0][0] * rhs[2][0] + lhs[1][0] * rhs[2][1] + lhs[2][0] * rhs[2][2], lhs[0][1] * rhs[2][0] + lhs[1][1] * rhs[2][1] + lhs[2][1] * rhs[2][2], lhs[0][2] * rhs[2][0] + lhs[1][2] * rhs[2][1] + lhs[2][2] * rhs[2][2], lhs[0][3] * rhs[2][0] + lhs[1][3] * rhs[2][1] + lhs[2][3] * rhs[2][2]);
}

template <typename T, typename U, typename RT = decltype(std::declval<T>() * std::declval<U>())>
inline const matrix<2, 4, RT> operator*(const matrix<3, 4, T>& lhs, const matrix<2, 3, U>& rhs)
{
    return matrix<2, 4, RT>(lhs[0][0] * rhs[0][0] + lhs[1][0] * rhs[0][1] + lhs[2][0] * rhs[0][2], lhs[0][1] * rhs[0][0] + lhs[1][1] * rhs[0][1] + lhs[2][1] * rhs[0][2], lhs[0][2] * rhs[0][0] + lhs[1][2] * rhs[0][1] + lhs[2][2] * rhs[0][2], lhs[0][3] * rhs[0][0] + lhs[1][3] * rhs[0][1] + lhs[2][3] * rhs[0][2],

                            lhs[0][0] * rhs[1][0] + lhs[1][0] * rhs[1][1] + lhs[2][0] * rhs[1][2], lhs[0][1] * rhs[1][0] + lhs[1][1] * rhs[1][1] + lhs[2][1] * rhs[1][2], lhs[0][2] * rhs[1][0] + lhs[1][2] * rhs[1][1] + lhs[2][2] * rhs[1][2], lhs[0][3] * rhs[1][0] + lhs[1][3] * rhs[1][1] + lhs[2][3] * rhs[1][2]);
}

template <typename T, typename U, typename RT = decltype(std::declval<T>() * std::declval<U>())>
inline const matrix<4, 3, RT> operator*(const matrix<3, 3, T>& lhs, const matrix<4, 3, U>& rhs)
{
    return matrix<4, 3, RT>(lhs[0][0] * rhs[0][0] + lhs[1][0] * rhs[0][1] + lhs[2][0] * rhs[0][2], lhs[0][1] * rhs[0][0] + lhs[1][1] * rhs[0][1] + lhs[2][1] * rhs[0][2], lhs[0][2] * rhs[0][0] + lhs[1][2] * rhs[0][1] + lhs[2][2] * rhs[0][2],

                            lhs[0][0] * rhs[1][0] + lhs[1][0] * rhs[1][1] + lhs[2][0] * rhs[1][2], lhs[0][1] * rhs[1][0] + lhs[1][1] * rhs[1][1] + lhs[2][1] * rhs[1][2], lhs[0][2] * rhs[1][0] + lhs[1][2] * rhs[1][1] + lhs[2][2] * rhs[1][2],

                            lhs[0][0] * rhs[2][0] + lhs[1][0] * rhs[2][1] + lhs[2][0] * rhs[2][2], lhs[0][1] * rhs[2][0] + lhs[1][1] * rhs[2][1] + lhs[2][1] * rhs[2][2], lhs[0][2] * rhs[2][0] + lhs[1][2] * rhs[2][1] + lhs[2][2] * rhs[2][2],

                            lhs[0][0] * rhs[3][0] + lhs[1][0] * rhs[3][1] + lhs[2][0] * rhs[3][2], lhs[0][1] * rhs[3][0] + lhs[1][1] * rhs[3][1] + lhs[2][1] * rhs[3][2], lhs[0][2] * rhs[3][0] + lhs[1][2] * rhs[3][1] + lhs[2][2] * rhs[3][2]);
}

template <typename T, typename U, typename RT = decltype(std::declval<T>() * std::declval<U>())>
inline const matrix<3, 3, RT> operator*(const matrix<3, 3, T>& lhs, const matrix<3, 3, U>& rhs)
{
    return matrix<3, 3, RT>(lhs[0][0] * rhs[0][0] + lhs[1][0] * rhs[0][1] + lhs[2][0] * rhs[0][2], lhs[0][1] * rhs[0][0] + lhs[1][1] * rhs[0][1] + lhs[2][1] * rhs[0][2], lhs[0][2] * rhs[0][0] + lhs[1][2] * rhs[0][1] + lhs[2][2] * rhs[0][2],

                            lhs[0][0] * rhs[1][0] + lhs[1][0] * rhs[1][1] + lhs[2][0] * rhs[1][2], lhs[0][1] * rhs[1][0] + lhs[1][1] * rhs[1][1] + lhs[2][1] * rhs[1][2], lhs[0][2] * rhs[1][0] + lhs[1][2] * rhs[1][1] + lhs[2][2] * rhs[1][2],

                            lhs[0][0] * rhs[2][0] + lhs[1][0] * rhs[2][1] + lhs[2][0] * rhs[2][2], lhs[0][1] * rhs[2][0] + lhs[1][1] * rhs[2][1] + lhs[2][1] * rhs[2][2], lhs[0][2] * rhs[2][0] + lhs[1][2] * rhs[2][1] + lhs[2][2] * rhs[2][2]);
}

template <typename T, typename U, typename RT = decltype(std::declval<T>() * std::declval<U>())>
inline const matrix<2, 3, RT> operator*(const matrix<3, 3, T>& lhs, const matrix<2, 3, U>& rhs)
{
    return matrix<2, 3, RT>(lhs[0][0] * rhs[0][0] + lhs[1][0] * rhs[0][1] + lhs[2][0] * rhs[0][2], lhs[0][1] * rhs[0][0] + lhs[1][1] * rhs[0][1] + lhs[2][1] * rhs[0][2], lhs[0][2] * rhs[0][0] + lhs[1][2] * rhs[0][1] + lhs[2][2] * rhs[0][2],

                            lhs[0][0] * rhs[1][0] + lhs[1][0] * rhs[1][1] + lhs[2][0] * rhs[1][2], lhs[0][1] * rhs[1][0] + lhs[1][1] * rhs[1][1] + lhs[2][1] * rhs[1][2], lhs[0][2] * rhs[1][0] + lhs[1][2] * rhs[1][1] + lhs[2][2] * rhs[1][2]);
}

template <typename T, typename U, typename RT = decltype(std::declval<T>() * std::declval<U>())>
inline const matrix<4, 2, RT> operator*(const matrix<3, 2, T>& lhs, const matrix<4, 3, U>& rhs)
{
    return matrix<4, 2, RT>(lhs[0][0] * rhs[0][0] + lhs[1][0] * rhs[0][1] + lhs[2][0] * rhs[0][2], lhs[0][1] * rhs[0][0] + lhs[1][1] * rhs[0][1] + lhs[2][1] * rhs[0][2],

                            lhs[0][0] * rhs[1][0] + lhs[1][0] * rhs[1][1] + lhs[2][0] * rhs[1][2], lhs[0][1] * rhs[1][0] + lhs[1][1] * rhs[1][1] + lhs[2][1] * rhs[1][2],

                            lhs[0][0] * rhs[2][0] + lhs[1][0] * rhs[2][1] + lhs[2][0] * rhs[2][2], lhs[0][1] * rhs[2][0] + lhs[1][1] * rhs[2][1] + lhs[2][1] * rhs[2][2],

                            lhs[0][0] * rhs[3][0] + lhs[1][0] * rhs[3][1] + lhs[2][0] * rhs[3][2], lhs[0][1] * rhs[3][0] + lhs[1][1] * rhs[3][1] + lhs[2][1] * rhs[3][2]);
}

template <typename T, typename U, typename RT = decltype(std::declval<T>() * std::declval<U>())>
inline const matrix<3, 2, RT> operator*(const matrix<3, 2, T>& lhs, const matrix<3, 3, U>& rhs)
{
    return matrix<3, 2, RT>(lhs[0][0] * rhs[0][0] + lhs[1][0] * rhs[0][1] + lhs[2][0] * rhs[0][2], lhs[0][1] * rhs[0][0] + lhs[1][1] * rhs[0][1] + lhs[2][1] * rhs[0][2],

                            lhs[0][0] * rhs[1][0] + lhs[1][0] * rhs[1][1] + lhs[2][0] * rhs[1][2], lhs[0][1] * rhs[1][0] + lhs[1][1] * rhs[1][1] + lhs[2][1] * rhs[1][2],

                            lhs[0][0] * rhs[2][0] + lhs[1][0] * rhs[2][1] + lhs[2][0] * rhs[2][2], lhs[0][1] * rhs[2][0] + lhs[1][1] * rhs[2][1] + lhs[2][1] * rhs[2][2]);
}

template <typename T, typename U, typename RT = decltype(std::declval<T>() * std::declval<U>())>
inline const matrix<2, 2, RT> operator*(const matrix<3, 2, T>& lhs, const matrix<2, 3, U>& rhs)
{
    return matrix<2, 2, RT>(lhs[0][0] * rhs[0][0] + lhs[1][0] * rhs[0][1] + lhs[2][0] * rhs[0][2], lhs[0][1] * rhs[0][0] + lhs[1][1] * rhs[0][1] + lhs[2][1] * rhs[0][2],

                            lhs[0][0] * rhs[1][0] + lhs[1][0] * rhs[1][1] + lhs[2][0] * rhs[1][2], lhs[0][1] * rhs[1][0] + lhs[1][1] * rhs[1][1] + lhs[2][1] * rhs[1][2]);
}

template <typename T, typename U, typename RT = decltype(std::declval<T>() * std::declval<U>())>
inline const matrix<4, 4, RT> operator*(const matrix<2, 4, T>& lhs, const matrix<4, 2, U>& rhs)
{
    return matrix<4, 4, RT>(lhs[0][0] * rhs[0][0] + lhs[1][0] * rhs[0][1], lhs[0][1] * rhs[0][0] + lhs[1][1] * rhs[0][1], lhs[0][2] * rhs[0][0] + lhs[1][2] * rhs[0][1], lhs[0][3] * rhs[0][0] + lhs[1][3] * rhs[0][1],

                            lhs[0][0] * rhs[1][0] + lhs[1][0] * rhs[1][1], lhs[0][1] * rhs[1][0] + lhs[1][1] * rhs[1][1], lhs[0][2] * rhs[1][0] + lhs[1][2] * rhs[1][1], lhs[0][3] * rhs[1][0] + lhs[1][3] * rhs[1][1],

                            lhs[0][0] * rhs[2][0] + lhs[1][0] * rhs[2][1], lhs[0][1] * rhs[2][0] + lhs[1][1] * rhs[2][1], lhs[0][2] * rhs[2][0] + lhs[1][2] * rhs[2][1], lhs[0][3] * rhs[2][0] + lhs[1][3] * rhs[2][1],

                            lhs[0][0] * rhs[3][0] + lhs[1][0] * rhs[3][1], lhs[0][1] * rhs[3][0] + lhs[1][1] * rhs[3][1], lhs[0][2] * rhs[3][0] + lhs[1][2] * rhs[3][1], lhs[0][3] * rhs[3][0] + lhs[1][3] * rhs[3][1]);
}

template <typename T, typename U, typename RT = decltype(std::declval<T>() * std::declval<U>())>
inline const matrix<3, 4, RT> operator*(const matrix<2, 4, T>& lhs, const matrix<3, 2, U>& rhs)
{
    return matrix<3, 4, RT>(lhs[0][0] * rhs[0][0] + lhs[1][0] * rhs[0][1], lhs[0][1] * rhs[0][0] + lhs[1][1] * rhs[0][1], lhs[0][2] * rhs[0][0] + lhs[1][2] * rhs[0][1], lhs[0][3] * rhs[0][0] + lhs[1][3] * rhs[0][1],

                            lhs[0][0] * rhs[1][0] + lhs[1][0] * rhs[1][1], lhs[0][1] * rhs[1][0] + lhs[1][1] * rhs[1][1], lhs[0][2] * rhs[1][0] + lhs[1][2] * rhs[1][1], lhs[0][3] * rhs[1][0] + lhs[1][3] * rhs[1][1],

                            lhs[0][0] * rhs[2][0] + lhs[1][0] * rhs[2][1], lhs[0][1] * rhs[2][0] + lhs[1][1] * rhs[2][1], lhs[0][2] * rhs[2][0] + lhs[1][2] * rhs[2][1], lhs[0][3] * rhs[2][0] + lhs[1][3] * rhs[2][1]);
}

template <typename T, typename U, typename RT = decltype(std::declval<T>() * std::declval<U>())>
inline const matrix<2, 4, RT> operator*(const matrix<2, 4, T>& lhs, const matrix<2, 2, U>& rhs)
{
    return matrix<2, 4, RT>(lhs[0][0] * rhs[0][0] + lhs[1][0] * rhs[0][1], lhs[0][1] * rhs[0][0] + lhs[1][1] * rhs[0][1], lhs[0][2] * rhs[0][0] + lhs[1][2] * rhs[0][1], lhs[0][3] * rhs[0][0] + lhs[1][3] * rhs[0][1],

                            lhs[0][0] * rhs[1][0] + lhs[1][0] * rhs[1][1], lhs[0][1] * rhs[1][0] + lhs[1][1] * rhs[1][1], lhs[0][2] * rhs[1][0] + lhs[1][2] * rhs[1][1], lhs[0][3] * rhs[1][0] + lhs[1][3] * rhs[1][1]);
}

template <typename T, typename U, typename RT = decltype(std::declval<T>() * std::declval<U>())>
inline const matrix<4, 3, RT> operator*(const matrix<2, 3, T>& lhs, const matrix<4, 2, U>& rhs)
{
    return matrix<4, 3, RT>(lhs[0][0] * rhs[0][0] + lhs[1][0] * rhs[0][1], lhs[0][1] * rhs[0][0] + lhs[1][1] * rhs[0][1], lhs[0][2] * rhs[0][0] + lhs[1][2] * rhs[0][1],

                            lhs[0][0] * rhs[1][0] + lhs[1][0] * rhs[1][1], lhs[0][1] * rhs[1][0] + lhs[1][1] * rhs[1][1], lhs[0][2] * rhs[1][0] + lhs[1][2] * rhs[1][1],

                            lhs[0][0] * rhs[2][0] + lhs[1][0] * rhs[2][1], lhs[0][1] * rhs[2][0] + lhs[1][1] * rhs[2][1], lhs[0][2] * rhs[2][0] + lhs[1][2] * rhs[2][1],

                            lhs[0][0] * rhs[3][0] + lhs[1][0] * rhs[3][1], lhs[0][1] * rhs[3][0] + lhs[1][1] * rhs[3][1], lhs[0][2] * rhs[3][0] + lhs[1][2] * rhs[3][1]);
}

template <typename T, typename U, typename RT = decltype(std::declval<T>() * std::declval<U>())>
inline const matrix<3, 3, RT> operator*(const matrix<2, 3, T>& lhs, const matrix<3, 2, U>& rhs)
{
    return matrix<3, 3, RT>(lhs[0][0] * rhs[0][0] + lhs[1][0] * rhs[0][1], lhs[0][1] * rhs[0][0] + lhs[1][1] * rhs[0][1], lhs[0][2] * rhs[0][0] + lhs[1][2] * rhs[0][1],

                            lhs[0][0] * rhs[1][0] + lhs[1][0] * rhs[1][1], lhs[0][1] * rhs[1][0] + lhs[1][1] * rhs[1][1], lhs[0][2] * rhs[1][0] + lhs[1][2] * rhs[1][1],

                            lhs[0][0] * rhs[2][0] + lhs[1][0] * rhs[2][1], lhs[0][1] * rhs[2][0] + lhs[1][1] * rhs[2][1], lhs[0][2] * rhs[2][0] + lhs[1][2] * rhs[2][1]);
}

template <typename T, typename U, typename RT = decltype(std::declval<T>() * std::declval<U>())>
inline const matrix<2, 3, RT> operator*(const matrix<2, 3, T>& lhs, const matrix<2, 2, U>& rhs)
{
    return matrix<2, 3, RT>(lhs[0][0] * rhs[0][0] + lhs[1][0] * rhs[0][1], lhs[0][1] * rhs[0][0] + lhs[1][1] * rhs[0][1], lhs[0][2] * rhs[0][0] + lhs[1][2] * rhs[0][1],

                            lhs[0][0] * rhs[1][0] + lhs[1][0] * rhs[1][1], lhs[0][1] * rhs[1][0] + lhs[1][1] * rhs[1][1], lhs[0][2] * rhs[1][0] + lhs[1][2] * rhs[1][1]);
}

template <typename T, typename U, typename RT = decltype(std::declval<T>() * std::declval<U>())>
inline const matrix<4, 2, RT> operator*(const matrix<2, 2, T>& lhs, const matrix<4, 2, U>& rhs)
{
    return matrix<4, 2, RT>(lhs[0][0] * rhs[0][0] + lhs[1][0] * rhs[0][1], lhs[0][1] * rhs[0][0] + lhs[1][1] * rhs[0][1],

                            lhs[0][0] * rhs[1][0] + lhs[1][0] * rhs[1][1], lhs[0][1] * rhs[1][0] + lhs[1][1] * rhs[1][1],

                            lhs[0][0] * rhs[2][0] + lhs[1][0] * rhs[2][1], lhs[0][1] * rhs[2][0] + lhs[1][1] * rhs[2][1],

                            lhs[0][0] * rhs[3][0] + lhs[1][0] * rhs[3][1], lhs[0][1] * rhs[3][0] + lhs[1][1] * rhs[3][1]);
}

template <typename T, typename U, typename RT = decltype(std::declval<T>() * std::declval<U>())>
inline const matrix<3, 2, RT> operator*(const matrix<2, 2, T>& lhs, const matrix<3, 2, U>& rhs)
{
    return matrix<3, 2, RT>(lhs[0][0] * rhs[0][0] + lhs[1][0] * rhs[0][1], lhs[0][1] * rhs[0][0] + lhs[1][1] * rhs[0][1],

                            lhs[0][0] * rhs[1][0] + lhs[1][0] * rhs[1][1], lhs[0][1] * rhs[1][0] + lhs[1][1] * rhs[1][1],

                            lhs[0][0] * rhs[2][0] + lhs[1][0] * rhs[2][1], lhs[0][1] * rhs[2][0] + lhs[1][1] * rhs[2][1]);
}

template <typename T, typename U, typename RT = decltype(std::declval<T>() * std::declval<U>())>
inline const matrix<2, 2, RT> operator*(const matrix<2, 2, T>& lhs, const matrix<2, 2, U>& rhs)
{
    return matrix<2, 2, RT>(lhs[0][0] * rhs[0][0] + lhs[1][0] * rhs[0][1], lhs[0][1] * rhs[0][0] + lhs[1][1] * rhs[0][1],

                            lhs[0][0] * rhs[1][0] + lhs[1][0] * rhs[1][1], lhs[0][1] * rhs[1][0] + lhs[1][1] * rhs[1][1]);
}

// vec * matrix
template <U32 R, typename T, template <U32, typename> class TVec>
inline const TVec<4, T> operator*(const TVec<R, T>& v, const matrix<4, R, T>& m)
{
    return TVec<4, T>(dot(v, m[0]), dot(v, m[1]), dot(v, m[2]), dot(v, m[3]));
}

template <U32 R, typename T, template <U32, typename> class TVec>
inline const TVec<3, T> operator*(const TVec<R, T>& v, const matrix<3, R, T>& m)
{
    return TVec<3, T>(dot(v, m[0]), dot(v, m[1]), dot(v, m[2]));
}

template <U32 R, typename T, template <U32, typename> class TVec>
inline const TVec<2, T> operator*(const TVec<R, T>& v, const matrix<2, R, T>& m)
{
    return TVec<2, T>(dot(v, m[0]), dot(v, m[1]));
}

// matrix * vec
template <U32 R, typename T, template <U32, typename> class TVec>
inline const TVec<R, T> operator*(const matrix<4, R, T>& m, const TVec<4, T>& v)
{
    return utils::type_creator<R>::template create<TVec<R, T>>(
    [&m, &v](U32 r) { return m[0][r] * v.x + m[1][r] * v.y + m[2][r] * v.z + m[3][r] * v.w; });
}

template <U32 R, typename T, template <U32, typename> class TVec>
inline const TVec<R, T> operator*(const matrix<3, R, T>& m, const TVec<3, T>& v)
{
    return utils::type_creator<R>::template create<TVec<R, T>>(
    [&m, &v](U32 r) { return m[0][r] * v.x + m[1][r] * v.y + m[2][r] * v.z; });
}

template <U32 R, typename T, template <U32, typename> class TVec>
inline const TVec<R, T> operator*(const matrix<2, R, T>& m, const TVec<2, T>& v)
{
    return utils::type_creator<R>::template create<TVec<R, T>>([&m, &v](U32 r) { return m[0][r] * v.x + m[1][r] * v.y; });
}

// matrix * scalar
template <U32 C, U32 R, typename T>
inline matrix<C, R, T> operator+(const matrix<C, R, T>& m, const T& scalar)
{
    return utils::type_creator<C>::template create<matrix<C, R, T>>(
    [&m, &scalar](U32 index) { return m[index] + scalar; });
}

template <U32 C, U32 R, typename T>
inline matrix<C, R, T> operator-(const matrix<C, R, T>& m, const T& scalar)
{
    return utils::type_creator<C>::template create<matrix<C, R, T>>(
    [&m, &scalar](U32 index) { return m[index] - scalar; });
}

template <U32 C, U32 R, typename T>
inline matrix<C, R, T> operator*(const matrix<C, R, T>& m, const T& scalar)
{
    return utils::type_creator<C>::template create<matrix<C, R, T>>(
    [&m, &scalar](U32 index) { return m[index] * scalar; });
}

template <U32 C, U32 R, typename T>
inline matrix<C, R, T> operator/(const matrix<C, R, T>& m, const T& scalar)
{
    return utils::type_creator<C>::template create<matrix<C, R, T>>(
    [&m, &scalar](U32 index) { return m[index] / scalar; });
}

// scalar * matrix
template <U32 C, U32 R, typename T>
inline matrix<C, R, T> operator+(const T& scalar, const matrix<C, R, T>& m)
{
    return utils::type_creator<C>::template create<matrix<C, R, T>>(
    [&m, &scalar](U32 index) { return scalar + m[index]; });
}

template <U32 C, U32 R, typename T>
inline matrix<C, R, T> operator-(const T& scalar, const matrix<C, R, T>& m)
{
    return utils::type_creator<C>::template create<matrix<C, R, T>>(
    [&m, &scalar](U32 index) { return scalar - m[index]; });
}

template <U32 C, U32 R, typename T>
inline matrix<C, R, T> operator*(const T& scalar, const matrix<C, R, T>& m)
{
    return utils::type_creator<C>::template create<matrix<C, R, T>>(
    [&m, &scalar](U32 index) { return scalar * m[index]; });
}

template <U32 C, U32 R, typename T>
inline matrix<C, R, T> operator/(const T& scalar, const matrix<C, R, T>& m)
{
    return utils::type_creator<C>::template create<matrix<C, R, T>>(
    [&m, &scalar](U32 index) { return scalar / m[index]; });
}

// matrix equality
template <U32 R, typename T>
inline constexpr bool operator==(const matrix<4, R, T>& lhs, const matrix<4, R, T>& rhs)
{
    return lhs[0] == rhs[0] && lhs[1] == rhs[1] && lhs[2] == rhs[2] && lhs[3] == rhs[3];
}

template <U32 R, typename T>
inline constexpr bool operator==(const matrix<3, R, T>& lhs, const matrix<3, R, T>& rhs)
{
    return lhs[0] == rhs[0] && lhs[1] == rhs[1] && lhs[2] == rhs[2];
}

template <U32 R, typename T>
inline constexpr bool operator==(const matrix<2, R, T>& lhs, const matrix<2, R, T>& rhs)
{
    return lhs[0] == rhs[0] && lhs[1] == rhs[1];
}

template <U32 R, typename T>
inline constexpr bool operator!=(const matrix<4, R, T>& lhs, const matrix<4, R, T>& rhs)
{
    return (lhs[0] != rhs[0]) || (lhs[1] != rhs[1]) || (lhs[2] != rhs[2]) || (lhs[3] != rhs[3]);
}

template <U32 R, typename T>
inline constexpr bool operator!=(const matrix<3, R, T>& lhs, const matrix<3, R, T>& rhs)
{
    return (lhs[0] != rhs[0]) || (lhs[1] != rhs[1]) || (lhs[2] != rhs[2]);
}

template <U32 R, typename T>
inline constexpr bool operator!=(const matrix<2, R, T>& lhs, const matrix<2, R, T>& rhs)
{
    return (lhs[0] != rhs[0]) || (lhs[1] != rhs[1]);
}

} // namespace matrix_imp

} // namespace math

} // namespace framework

#endif // FRAMEWORK_MATH_MATRIX_TYPE_H
