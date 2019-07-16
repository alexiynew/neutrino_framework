/// @file
/// @brief Implementation of matrix type.
/// @author Fedorov Alexey
/// @date 11.07.2017

// =============================================================================
// MIT License
//
// Copyright (c) 2017-2019 Fedorov Alexey
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// =============================================================================

#ifndef FRAMEWORK_MATH_DETAILS
#error You should include math/math.hpp instead of matrix_type.hpp
#endif

#ifndef FRAMEWORK_MATH_INC_MATRIX_TYPE_HPP
#define FRAMEWORK_MATH_INC_MATRIX_TYPE_HPP

#include <cassert>

#include <common/types.hpp>

#include <math/inc/matrix_type_details.hpp>
#include <math/inc/vector_type.hpp>

namespace framework
{
namespace math
{
/// @addtogroup math_matrix_implementation
/// @{

/// @brief Matrix template declaration.
///
/// @see matrix<4, 4, T>, matrix<4, 3, T>, matrix<4, 2, T>,
///      matrix<3, 4, T>, matrix<3, 3, T>, matrix<3, 2, T>,
///      matrix<2, 4, T>, matrix<2, 3, T>, matrix<2, 2, T>
template <uint32 C, uint32 R, typename T>
struct matrix;

/// @brief matrix<4, 4, T> type specialization.
///
/// @note Can be instantiated only with arithmetic type.
template <typename T>
struct matrix<4, 4, T> final
{
    static_assert(std::is_arithmetic<T>::value, "Expected floating-point or integer type.");

    using value_type  = T;            ///< Value type
    using column_type = vector<4, T>; ///< Column type
    using row_type    = vector<4, T>; ///< Row type

    /// @brief Default constructor.
    ///
    /// Creates an identity matrix.
    constexpr matrix() noexcept;

    /// @brief Initializes matrices with provided values.
    ///
    /// @param value00 Value for first column.
    /// @param value01 Value for first column.
    /// @param value02 Value for first column.
    /// @param value03 Value for first column.
    /// @param value10 Value for second column.
    /// @param value11 Value for second column.
    /// @param value12 Value for second column.
    /// @param value13 Value for second column.
    /// @param value20 Value for third column.
    /// @param value21 Value for third column.
    /// @param value22 Value for third column.
    /// @param value23 Value for third column.
    /// @param value30 Value for fourth column.
    /// @param value31 Value for fourth column.
    /// @param value32 Value for fourth column.
    /// @param value33 Value for fourth column.

    // clang-format off
    constexpr matrix(const T& value00, const T& value01, const T& value02, const T& value03,
                     const T& value10, const T& value11, const T& value12, const T& value13,
                     const T& value20, const T& value21, const T& value22, const T& value23,
                     const T& value30, const T& value31, const T& value32, const T& value33);
    // clang-format on

    /// @brief Initialize the main diagonal of matrix with provided value.
    ///
    /// @param value Floating-point or integral value.
    explicit constexpr matrix(const T& value) noexcept;

    /// @brief Initializes all components of matrix from pointer to values.
    ///
    /// @param pointer Const pointer to values that should be taken.
    ///
    /// @warning May cause memory access error.
    template <typename U>
    explicit matrix(const U* pointer);

    /// @brief Initializes all components of matrix from pointer to values.
    ///
    /// @param pointer Pointer to values that should be taken.
    ///
    /// @warning May cause memory access error.
    template <typename U>
    explicit matrix(U* pointer);

    /// @brief Initializes matrices with provided vectors.
    ///
    /// @param column0 Vector for first column.
    /// @param column1 Vector for second column.
    /// @param column2 Vector for third column.
    /// @param column3 Vector for fourth column.
    template <typename U0, typename U1, typename U2, typename U3>
    constexpr matrix(const vector<4, U0>& column0,
                     const vector<4, U1>& column1,
                     const vector<4, U2>& column2,
                     const vector<4, U3>& column3);

    /// @brief Initializes matrices with provided vectors and scalar values.
    ///
    /// @param vector0 First part for first column.
    /// @param w0 Last component for first column.
    /// @param vector1 First part for second column.
    /// @param w1 Last component for second column.
    /// @param vector2 First part for third column.
    /// @param w2 Last component for third column.
    /// @param vector3 First part for fourth column.
    /// @param w3 Last component for fourth column.

    // clang-format off
    template <typename U0, typename W0,
              typename U1, typename W1,
              typename U2, typename W2,
              typename U3, typename W3>
    constexpr matrix(const vector<3, U0>& vector0, const W0& w0,
                     const vector<3, U1>& vector1, const W1& w1,
                     const vector<3, U2>& vector2, const W2& w2,
                     const vector<3, U3>& vector3, const W3& w3);
    // clang-format on

    /// @brief Initializes matrices with provided scalar values and vectors.
    ///
    /// @param x0 First component for first column.
    /// @param vector0 Last part for first column.
    /// @param x1 First component for second column.
    /// @param vector1 Last part for second column.
    /// @param x2 First component for third column.
    /// @param vector2 Last part for third column.
    /// @param x3 First component for fourth column.
    /// @param vector3 Last part for fourth column.

    // clang-format off
    template <typename X0, typename U0,
              typename X1, typename U1,
              typename X2, typename U2,
              typename X3, typename U3>
    constexpr matrix(const X0& x0, const vector<3, U0>& vector0,
                     const X1& x1, const vector<3, U1>& vector1,
                     const X2& x2, const vector<3, U2>& vector2,
                     const X3& x3, const vector<3, U3>& vector3);
    // clang-format on

    /// @brief Initializes matrices with provided vectors and values.
    ///
    /// @param vector00 First part for first column.
    /// @param vector01 Last part for first column.
    /// @param vector10 First part for second column.
    /// @param vector11 Last part for second column.
    /// @param vector20 First part for third column.
    /// @param vector21 Last part for third column.
    /// @param vector30 First part for fourth column.
    /// @param vector31 Last part for fourth column.

    // clang-format off
    template <typename U00, typename U01,
              typename U10, typename U11,
              typename U20, typename U21,
              typename U30, typename U31>
    constexpr matrix(const vector<2, U00>& vector00, const vector<2, U01>& vector01,
                     const vector<2, U10>& vector10, const vector<2, U11>& vector11,
                     const vector<2, U20>& vector20, const vector<2, U21>& vector21,
                     const vector<2, U30>& vector30, const vector<2, U31>& vector31);
    // clang-format on

    /// @brief Initializes matrices with provided vectors and values.
    ///
    /// @param vector0 First part for first column.
    /// @param z0 Z component for first column.
    /// @param w0 W component for first column.
    /// @param vector1 First part for second column.
    /// @param z1 Z component for second column.
    /// @param w1 W component for second column.
    /// @param vector2 First part for third column.
    /// @param z2 Z component for third column.
    /// @param w2 W component for third column.
    /// @param vector3 First part for fourth column.
    /// @param z3 Z component for fourth column.
    /// @param w3 W component for fourth column.

    // clang-format off
    template <typename U0, typename Z0, typename W0,
              typename U1, typename Z1, typename W1,
              typename U2, typename Z2, typename W2,
              typename U3, typename Z3, typename W3>
    constexpr matrix(const vector<2, U0>& vector0, const Z0& z0, const W0& w0,
                     const vector<2, U1>& vector1, const Z1& z1, const W1& w1,
                     const vector<2, U2>& vector2, const Z2& z2, const W2& w2,
                     const vector<2, U3>& vector3, const Z3& z3, const W3& w3);
    // clang-format on

    /// @brief Initializes matrices with provided vectors and values.
    ///
    /// @param x0 X component for first column.
    /// @param vector0 Middle part for first column.
    /// @param w0 W component for first column.
    /// @param x1 X component for second column.
    /// @param vector1 Middle part for second column.
    /// @param w1 W component for second column.
    /// @param x2 X component for third column.
    /// @param vector2 Middle part for third column.
    /// @param w2 W component for third column.
    /// @param x3 X component for fourth column.
    /// @param vector3 Middle part for fourth column.
    /// @param w3 W component for fourth column.

    // clang-format off
    template <typename X0, typename U0, typename W0,
              typename X1, typename U1, typename W1,
              typename X2, typename U2, typename W2,
              typename X3, typename U3, typename W3>
    constexpr matrix(const X0& x0, const vector<2, U0>& vector0, const W0& w0,
                     const X1& x1, const vector<2, U1>& vector1, const W1& w1,
                     const X2& x2, const vector<2, U2>& vector2, const W2& w2,
                     const X3& x3, const vector<2, U3>& vector3, const W3& w3);
    // clang-format on

    /// @brief Initializes matrices with provided vectors and values.
    ///
    /// @param x0 X component for first column.
    /// @param y0 Y component for first column.
    /// @param vector0 Last part for first column.
    /// @param x1 X component for second column.
    /// @param y1 Y component for second column.
    /// @param vector1 Last part for second column.
    /// @param x2 X component for third column.
    /// @param y2 Y component for third column.
    /// @param vector2 Last part for third column.
    /// @param x3 X component for fourth column.
    /// @param y3 Y component for fourth column.
    /// @param vector3 Last part for fourth column.

    // clang-format off
    template <typename X0, typename Y0, typename U0,
              typename X1, typename Y1, typename U1,
              typename X2, typename Y2, typename U2,
              typename X3, typename Y3, typename U3>
    constexpr matrix(const X0& x0, const Y0& y0, const vector<2, U0>& vector0,
                     const X1& x1, const Y1& y1, const vector<2, U1>& vector1,
                     const X2& x2, const Y2& y2, const vector<2, U2>& vector2,
                     const X3& x3, const Y3& y3, const vector<2, U3>& vector3);
    // clang-format on

    /// @brief Initializes matrix from another one.
    ///
    /// @param other Matrix of integral or floating-point type.
    ///
    /// @note The remain components will be initialized as in identity matrix.
    template <uint32 C, uint32 R, typename U>
    explicit constexpr matrix(const matrix<C, R, U>& other);

    /// @brief Access operator.
    ///
    /// @param index Index of column.
    ///
    /// @return Reference to column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    column_type& operator[](uint32 index);

    /// @brief Const access operator.
    ///
    /// @param index Index of column.
    ///
    /// @return Reference to constant column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    const column_type& operator[](uint32 index) const;

    /// @brief Size of matrix.
    ///
    /// @return Count of columns in matrix.
    constexpr uint32 size() const noexcept;

    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the x component of first column.
    value_type* data() noexcept;

    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the x component of first column.
    const value_type* data() const noexcept;

    /// @brief Provides access to columns of the matrix.
    ///
    /// @param index Index of column.
    ///
    /// @return Copy of column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    column_type column(uint32 index) const noexcept;

    /// @brief Provides access to rows of the matrix.
    ///
    /// @param index Index of row.
    ///
    /// @return Copy of row at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    row_type row(uint32 index) const noexcept;

private:
    column_type m_data[4];
};

/// @brief matrix<4, 3, T> type specialization.
///
/// @note Can be instantiated only with arithmetic type.
template <typename T>
struct matrix<4, 3, T> final
{
    static_assert(std::is_arithmetic<T>::value, "Expected floating-point or integer type.");

    using value_type  = T;            ///< Value type
    using column_type = vector<3, T>; ///< Column type
    using row_type    = vector<4, T>; ///< Row type

    /// @brief Default constructor.
    ///
    /// Creates an identity matrix.
    constexpr matrix() noexcept;

    /// @brief Initializes matrices with provided values.
    ///
    /// @param value00 Value for first column.
    /// @param value01 Value for first column.
    /// @param value02 Value for first column.
    /// @param value10 Value for second column.
    /// @param value11 Value for second column.
    /// @param value12 Value for second column.
    /// @param value20 Value for third column.
    /// @param value21 Value for third column.
    /// @param value22 Value for third column.
    /// @param value30 Value for fourth column.
    /// @param value31 Value for fourth column.
    /// @param value32 Value for fourth column.

    // clang-format off
    constexpr matrix(const T& value00, const T& value01, const T& value02,
                     const T& value10, const T& value11, const T& value12,
                     const T& value20, const T& value21, const T& value22,
                     const T& value30, const T& value31, const T& value32);
    // clang-format on

    /// @brief Initialize the main diagonal of matrix with provided value.
    ///
    /// @param value Floating-point or integral value.
    explicit constexpr matrix(const T& value) noexcept;

    /// @brief Initializes all components of matrix from pointer to values.
    ///
    /// @param pointer Const pointer to values that should be taken.
    ///
    /// @warning May cause memory access error.
    template <typename U>
    explicit matrix(const U* pointer);

    /// @brief Initializes all components of matrix from pointer to values.
    ///
    /// @param pointer Pointer to values that should be taken.
    ///
    /// @warning May cause memory access error.
    template <typename U>
    explicit matrix(U* pointer);

    /// @brief Initializes matrices with provided vectors.
    ///
    /// @param column0 Vector for first column.
    /// @param column1 Vector for second column.
    /// @param column2 Vector for third column.
    /// @param column3 Vector for fourth column.
    template <typename U0, typename U1, typename U2, typename U3>
    constexpr matrix(const vector<4, U0>& column0,
                     const vector<4, U1>& column1,
                     const vector<4, U2>& column2,
                     const vector<4, U3>& column3);

    /// @brief Initializes matrices with provided vectors.
    ///
    /// @param column0 Vector for first column.
    /// @param column1 Vector for second column.
    /// @param column2 Vector for third column.
    /// @param column3 Vector for fourth column.
    template <typename U0, typename U1, typename U2, typename U3>
    constexpr matrix(const vector<3, U0>& column0,
                     const vector<3, U1>& column1,
                     const vector<3, U2>& column2,
                     const vector<3, U3>& column3);

    /// @brief Initializes matrices with provided vectors and values.
    ///
    /// @param vector0 First part for first column.
    /// @param z0 Z component for first column.
    /// @param vector1 First part for second column.
    /// @param z1 Z component for second column.
    /// @param vector2 First part for third column.
    /// @param z2 Z component for third column.
    /// @param vector3 First part for fourth column.
    /// @param z3 Z component for fourth column.

    // clang-format off
    template <typename U0, typename Z0,
              typename U1, typename Z1,
              typename U2, typename Z2,
              typename U3, typename Z3>
    constexpr matrix(const vector<2, U0>& vector0, const Z0& z0,
                     const vector<2, U1>& vector1, const Z1& z1,
                     const vector<2, U2>& vector2, const Z2& z2,
                     const vector<2, U3>& vector3, const Z3& z3);
    // clang-format on

    /// @brief Initializes matrices with provided vectors and values.
    ///
    /// @param x0 X component for first column.
    /// @param vector0 Last part for first column.
    /// @param x1 X component for second column.
    /// @param vector1 Last part for second column.
    /// @param x2 X component for third column.
    /// @param vector2 Last part for third column.
    /// @param x3 X component for fourth column.
    /// @param vector3 Last part for fourth column.

    // clang-format off
    template <typename X0, typename U0,
              typename X1, typename U1,
              typename X2, typename U2,
              typename X3, typename U3>
    constexpr matrix(const X0& x0, const vector<2, U0>& vector0,
                     const X1& x1, const vector<2, U1>& vector1,
                     const X2& x2, const vector<2, U2>& vector2,
                     const X3& x3, const vector<2, U3>& vector3);
    // clang-format on

    /// @brief Initializes matrix from another one.
    ///
    /// @param other Matrix of integral or floating-point type.
    ///
    /// @note The remain components will be initialized as in identity matrix.
    template <uint32 C, uint32 R, typename U>
    explicit constexpr matrix(const matrix<C, R, U>& other);

    /// @brief Access operator.
    ///
    /// @param index Index of column.
    ///
    /// @return Reference to column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    column_type& operator[](uint32 index);

    /// @brief Const access operator.
    ///
    /// @param index Index of column.
    ///
    /// @return Reference to constant column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    const column_type& operator[](uint32 index) const;

    /// @brief Size of matrix.
    ///
    /// @return Count of columns in matrix.
    constexpr uint32 size() const noexcept;

    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the x component of first column.
    value_type* data() noexcept;

    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the x component of first column.
    const value_type* data() const noexcept;

    /// @brief Provides access to columns of the matrix.
    ///
    /// @param index Index of column.
    ///
    /// @return Copy of column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    column_type column(uint32 index) const noexcept;

    /// @brief Provides access to rows of the matrix.
    ///
    /// @param index Index of row.
    ///
    /// @return Copy of row at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    row_type row(uint32 index) const noexcept;

private:
    column_type m_data[4];
};

/// @brief matrix<4, 2, T> type specialization.
///
/// @note Can be instantiated only with arithmetic type.
template <typename T>
struct matrix<4, 2, T> final
{
    static_assert(std::is_arithmetic<T>::value, "Expected floating-point or integer type.");

    using value_type  = T;            ///< Value type
    using column_type = vector<2, T>; ///< Column type
    using row_type    = vector<4, T>; ///< Row type

    /// @brief Default constructor.
    ///
    /// Creates an identity matrix.
    constexpr matrix() noexcept;

    /// @brief Initializes matrices with provided values.
    ///
    /// @param value00 Value for first column.
    /// @param value01 Value for first column.
    /// @param value10 Value for second column.
    /// @param value11 Value for second column.
    /// @param value20 Value for third column.
    /// @param value21 Value for third column.
    /// @param value30 Value for fourth column.
    /// @param value31 Value for fourth column.

    // clang-format off
    constexpr matrix(const T& value00, const T& value01,
                     const T& value10, const T& value11,
                     const T& value20, const T& value21,
                     const T& value30, const T& value31);
    // clang-format on

    /// @brief Initialize the main diagonal of matrix with provided value.
    ///
    /// @param value Floating-point or integral value.
    explicit constexpr matrix(const T& value) noexcept;

    /// @brief Initializes all components of matrix from pointer to values.
    ///
    /// @param pointer Const pointer to values that should be taken.
    ///
    /// @warning May cause memory access error.
    template <typename U>
    explicit matrix(const U* pointer);

    /// @brief Initializes all components of matrix from pointer to values.
    ///
    /// @param pointer Pointer to values that should be taken.
    ///
    /// @warning May cause memory access error.
    template <typename U>
    explicit matrix(U* pointer);

    /// @brief Initializes matrices with provided vectors.
    ///
    /// @param column0 Vector for first column.
    /// @param column1 Vector for second column.
    /// @param column2 Vector for third column.
    /// @param column3 Vector for fourth column.
    template <typename U0, typename U1, typename U2, typename U3>
    constexpr matrix(const vector<4, U0>& column0,
                     const vector<4, U1>& column1,
                     const vector<4, U2>& column2,
                     const vector<4, U3>& column3);

    /// @brief Initializes matrices with provided vectors.
    ///
    /// @param column0 Vector for first column.
    /// @param column1 Vector for second column.
    /// @param column2 Vector for third column.
    /// @param column3 Vector for fourth column.
    template <typename U0, typename U1, typename U2, typename U3>
    constexpr matrix(const vector<3, U0>& column0,
                     const vector<3, U1>& column1,
                     const vector<3, U2>& column2,
                     const vector<3, U3>& column3);

    /// @brief Initializes matrices with provided vectors.
    ///
    /// @param column0 Vector for first column.
    /// @param column1 Vector for second column.
    /// @param column2 Vector for third column.
    /// @param column3 Vector for fourth column.

    // clang-format off
    template <typename U0,
              typename U1,
              typename U2,
              typename U3>
    constexpr matrix(const vector<2, U0>& column0,
                     const vector<2, U1>& column1,
                     const vector<2, U2>& column2,
                     const vector<2, U3>& column3);
    // clang-format on

    /// @brief Initializes matrix from another one.
    ///
    /// @param other Matrix of integral or floating-point type.
    ///
    /// @note The remain components will be initialized as in identity matrix.
    template <uint32 C, uint32 R, typename U>
    explicit constexpr matrix(const matrix<C, R, U>& other);

    /// @brief Access operator.
    ///
    /// @param index Index of column.
    ///
    /// @return Reference to column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    column_type& operator[](uint32 index);

    /// @brief Const access operator.
    ///
    /// @param index Index of column.
    ///
    /// @return Reference to constant column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    const column_type& operator[](uint32 index) const;

    /// @brief Size of matrix.
    ///
    /// @return Count of columns in matrix.
    constexpr uint32 size() const noexcept;

    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the x component of first column.
    value_type* data() noexcept;

    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the x component of first column.
    const value_type* data() const noexcept;

    /// @brief Provides access to columns of the matrix.
    ///
    /// @param index Index of column.
    ///
    /// @return Copy of column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    column_type column(uint32 index) const noexcept;

    /// @brief Provides access to rows of the matrix.
    ///
    /// @param index Index of row.
    ///
    /// @return Copy of row at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    row_type row(uint32 index) const noexcept;

private:
    column_type m_data[4];
};

/// @brief matrix<3, 4, T> type specialization.
///
/// @note Can be instantiated only with arithmetic type.
template <typename T>
struct matrix<3, 4, T> final
{
    static_assert(std::is_arithmetic<T>::value, "Expected floating-point or integer type.");

    using value_type  = T;            ///< Value type
    using column_type = vector<4, T>; ///< Column type
    using row_type    = vector<3, T>; ///< Row type

    /// @brief Default constructor.
    ///
    /// Creates an identity matrix.
    constexpr matrix() noexcept;

    /// @brief Initializes matrices with provided values.
    ///
    /// @param value00 Value for first column.
    /// @param value01 Value for first column.
    /// @param value02 Value for first column.
    /// @param value03 Value for first column.
    /// @param value10 Value for second column.
    /// @param value11 Value for second column.
    /// @param value12 Value for second column.
    /// @param value13 Value for second column.
    /// @param value20 Value for third column.
    /// @param value21 Value for third column.
    /// @param value22 Value for third column.
    /// @param value23 Value for third column.

    // clang-format off
    constexpr matrix(const T& value00, const T& value01, const T& value02, const T& value03,
                     const T& value10, const T& value11, const T& value12, const T& value13,
                     const T& value20, const T& value21, const T& value22, const T& value23);
    // clang-format on

    /// @brief Initialize the main diagonal of matrix with provided value.
    ///
    /// @param value Floating-point or integral value.
    explicit constexpr matrix(const T& value) noexcept;

    /// @brief Initializes all components of matrix from pointer to values.
    ///
    /// @param pointer Const pointer to values that should be taken.
    ///
    /// @warning May cause memory access error.
    template <typename U>
    explicit matrix(const U* pointer);

    /// @brief Initializes all components of matrix from pointer to values.
    ///
    /// @param pointer Pointer to values that should be taken.
    ///
    /// @warning May cause memory access error.
    template <typename U>
    explicit matrix(U* pointer);

    /// @brief Initializes matrices with provided vectors.
    ///
    /// @param column0 Vector for first column.
    /// @param column1 Vector for second column.
    /// @param column2 Vector for third column.
    template <typename U0, typename U1, typename U2>
    constexpr matrix(const vector<4, U0>& column0, const vector<4, U1>& column1, const vector<4, U2>& column2);

    /// @brief Initializes matrices with provided vectors and scalar values.
    ///
    /// @param vector0 First part for first column.
    /// @param w0 Last component for first column.
    /// @param vector1 First part for second column.
    /// @param w1 Last component for second column.
    /// @param vector2 First part for third column.
    /// @param w2 Last component for third column.

    // clang-format off
    template <typename U0, typename W0,
              typename U1, typename W1,
              typename U2, typename W2>
    constexpr matrix(const vector<3, U0>& vector0, const W0& w0,
                     const vector<3, U1>& vector1, const W1& w1,
                     const vector<3, U2>& vector2, const W2& w2);
    // clang-format on

    /// @brief Initializes matrices with provided scalar values and vectors.
    ///
    /// @param x0 First component for first column.
    /// @param vector0 Last part for first column.
    /// @param x1 First component for second column.
    /// @param vector1 Last part for second column.
    /// @param x2 First component for third column.
    /// @param vector2 Last part for third column.

    // clang-format off
    template <typename X0, typename U0,
              typename X1, typename U1,
              typename X2, typename U2>
    constexpr matrix(const X0& x0, const vector<3, U0>& vector0,
                     const X1& x1, const vector<3, U1>& vector1,
                     const X2& x2, const vector<3, U2>& vector2);
    // clang-format on

    /// @brief Initializes matrices with provided vectors and values.
    ///
    /// @param vector00 First part for first column.
    /// @param vector01 Last part for first column.
    /// @param vector10 First part for second column.
    /// @param vector11 Last part for second column.
    /// @param vector20 First part for third column.
    /// @param vector21 Last part for third column.

    // clang-format off
    template <typename U00, typename U01,
              typename U10, typename U11,
              typename U20, typename U21>
    constexpr matrix(const vector<2, U00>& vector00, const vector<2, U01>& vector01,
                     const vector<2, U10>& vector10, const vector<2, U11>& vector11,
                     const vector<2, U20>& vector20, const vector<2, U21>& vector21);
    // clang-format on

    /// @brief Initializes matrices with provided vectors and values.
    ///
    /// @param vector0 First part for first column.
    /// @param z0 Z component for first column.
    /// @param w0 W component for first column.
    /// @param vector1 First part for second column.
    /// @param z1 Z component for second column.
    /// @param w1 W component for second column.
    /// @param vector2 First part for third column.
    /// @param z2 Z component for third column.
    /// @param w2 W component for third column.

    // clang-format off
    template <typename U0, typename Z0, typename W0,
              typename U1, typename Z1, typename W1,
              typename U2, typename Z2, typename W2>
    constexpr matrix(const vector<2, U0>& vector0, const Z0& z0, const W0& w0,
                     const vector<2, U1>& vector1, const Z1& z1, const W1& w1,
                     const vector<2, U2>& vector2, const Z2& z2, const W2& w2);
    // clang-format on

    /// @brief Initializes matrices with provided vectors and values.
    ///
    /// @param x0 X component for first column.
    /// @param vector0 Middle part for first column.
    /// @param w0 W component for first column.
    /// @param x1 X component for second column.
    /// @param vector1 Middle part for second column.
    /// @param w1 W component for second column.
    /// @param x2 X component for third column.
    /// @param vector2 Middle part for third column.
    /// @param w2 W component for third column.

    // clang-format off
    template <typename X0, typename U0, typename W0,
              typename X1, typename U1, typename W1,
              typename X2, typename U2, typename W2>
    constexpr matrix(const X0& x0, const vector<2, U0>& vector0, const W0& w0,
                     const X1& x1, const vector<2, U1>& vector1, const W1& w1,
                     const X2& x2, const vector<2, U2>& vector2, const W2& w2);
    // clang-format on

    /// @brief Initializes matrices with provided vectors and values.
    ///
    /// @param x0 X component for first column.
    /// @param y0 Y component for first column.
    /// @param vector0 Last part for first column.
    /// @param x1 X component for second column.
    /// @param y1 Y component for second column.
    /// @param vector1 Last part for second column.
    /// @param x2 X component for third column.
    /// @param y2 Y component for third column.
    /// @param vector2 Last part for third column.

    // clang-format off
    template <typename X0, typename Y0, typename U0,
              typename X1, typename Y1, typename U1,
              typename X2, typename Y2, typename U2>
    constexpr matrix(const X0& x0, const Y0& y0, const vector<2, U0>& vector0,
                     const X1& x1, const Y1& y1, const vector<2, U1>& vector1,
                     const X2& x2, const Y2& y2, const vector<2, U2>& vector2);
    // clang-format on

    /// @brief Initializes matrix from another one.
    ///
    /// @param other Matrix of integral or floating-point type.
    ///
    /// @note The remain components will be initialized as in identity matrix.
    template <uint32 C, uint32 R, typename U>
    explicit constexpr matrix(const matrix<C, R, U>& other);

    /// @brief Access operator.
    ///
    /// @param index Index of column.
    ///
    /// @return Reference to column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    column_type& operator[](uint32 index);

    /// @brief Const access operator.
    ///
    /// @param index Index of column.
    ///
    /// @return Reference to constant column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    const column_type& operator[](uint32 index) const;

    /// @brief Size of matrix.
    ///
    /// @return Count of columns in matrix.
    constexpr uint32 size() const noexcept;

    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the x component of first column.
    value_type* data() noexcept;

    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the x component of first column.
    const value_type* data() const noexcept;

    /// @brief Provides access to columns of the matrix.
    ///
    /// @param index Index of column.
    ///
    /// @return Copy of column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    column_type column(uint32 index) const noexcept;

    /// @brief Provides access to rows of the matrix.
    ///
    /// @param index Index of row.
    ///
    /// @return Copy of row at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    row_type row(uint32 index) const noexcept;

private:
    column_type m_data[3];
};

/// @brief matrix<3, 3, T> type specialization.
///
/// @note Can be instantiated only with arithmetic type.
template <typename T>
struct matrix<3, 3, T> final
{
    static_assert(std::is_arithmetic<T>::value, "Expected floating-point or integer type.");

    using value_type  = T;            ///< Value type
    using column_type = vector<3, T>; ///< Column type
    using row_type    = vector<3, T>; ///< Row type

    /// @brief Default constructor.
    ///
    /// Creates an identity matrix.
    constexpr matrix() noexcept;

    /// @brief Initializes matrices with provided values.
    ///
    /// @param value00 Value for first column.
    /// @param value01 Value for first column.
    /// @param value02 Value for first column.
    /// @param value10 Value for second column.
    /// @param value11 Value for second column.
    /// @param value12 Value for second column.
    /// @param value20 Value for third column.
    /// @param value21 Value for third column.
    /// @param value22 Value for third column.

    // clang-format off
    constexpr matrix(const T& value00, const T& value01, const T& value02,
                     const T& value10, const T& value11, const T& value12,
                     const T& value20, const T& value21, const T& value22);
    // clang-format on

    /// @brief Initialize the main diagonal of matrix with provided value.
    ///
    /// @param value Floating-point or integral value.
    explicit constexpr matrix(const T& value) noexcept;

    /// @brief Initializes all components of matrix from pointer to values.
    ///
    /// @param pointer Const pointer to values that should be taken.
    ///
    /// @warning May cause memory access error.
    template <typename U>
    explicit matrix(const U* pointer);

    /// @brief Initializes all components of matrix from pointer to values.
    ///
    /// @param pointer Pointer to values that should be taken.
    ///
    /// @warning May cause memory access error.
    template <typename U>
    explicit matrix(U* pointer);

    /// @brief Initializes matrices with provided vectors.
    ///
    /// @param column0 Vector for first column.
    /// @param column1 Vector for second column.
    /// @param column2 Vector for third column.
    template <typename U0, typename U1, typename U2>
    constexpr matrix(const vector<4, U0>& column0, const vector<4, U1>& column1, const vector<4, U2>& column2);

    /// @brief Initializes matrices with provided vectors.
    ///
    /// @param column0 Vector for first column.
    /// @param column1 Vector for second column.
    /// @param column2 Vector for third column.
    template <typename U0, typename U1, typename U2>
    constexpr matrix(const vector<3, U0>& column0, const vector<3, U1>& column1, const vector<3, U2>& column2);

    /// @brief Initializes matrices with provided vectors and values.
    ///
    /// @param vector0 First part for first column.
    /// @param z0 Z component for first column.
    /// @param vector1 First part for second column.
    /// @param z1 Z component for second column.
    /// @param vector2 First part for third column.
    /// @param z2 Z component for third column.

    // clang-format off
    template <typename U0, typename Z0,
              typename U1, typename Z1,
              typename U2, typename Z2>
    constexpr matrix(const vector<2, U0>& vector0, const Z0& z0,
                     const vector<2, U1>& vector1, const Z1& z1,
                     const vector<2, U2>& vector2, const Z2& z2);
    // clang-format on

    /// @brief Initializes matrices with provided vectors and values.
    ///
    /// @param x0 X component for first column.
    /// @param vector0 Last part for first column.
    /// @param x1 X component for second column.
    /// @param vector1 Last part for second column.
    /// @param x2 X component for third column.
    /// @param vector2 Last part for third column.

    // clang-format off
    template <typename X0, typename U0,
              typename X1, typename U1,
              typename X2, typename U2>
    constexpr matrix(const X0& x0, const vector<2, U0>& vector0,
                     const X1& x1, const vector<2, U1>& vector1,
                     const X2& x2, const vector<2, U2>& vector2);
    // clang-format on

    /// @brief Initializes matrix from another one.
    ///
    /// @param other Matrix of integral or floating-point type.
    ///
    /// @note The remain components will be initialized as in identity matrix.
    template <uint32 C, uint32 R, typename U>
    explicit constexpr matrix(const matrix<C, R, U>& other);

    /// @brief Access operator.
    ///
    /// @param index Index of column.
    ///
    /// @return Reference to column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    column_type& operator[](uint32 index);

    /// @brief Const access operator.
    ///
    /// @param index Index of column.
    ///
    /// @return Reference to constant column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    const column_type& operator[](uint32 index) const;

    /// @brief Size of matrix.
    ///
    /// @return Count of columns in matrix.
    constexpr uint32 size() const noexcept;

    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the x component of first column.
    value_type* data() noexcept;

    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the x component of first column.
    const value_type* data() const noexcept;

    /// @brief Provides access to columns of the matrix.
    ///
    /// @param index Index of column.
    ///
    /// @return Copy of column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    column_type column(uint32 index) const noexcept;

    /// @brief Provides access to rows of the matrix.
    ///
    /// @param index Index of row.
    ///
    /// @return Copy of row at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    row_type row(uint32 index) const noexcept;

private:
    column_type m_data[3];
};

/// @brief matrix<3, 2, T> type specialization.
///
/// @note Can be instantiated only with arithmetic type.
template <typename T>
struct matrix<3, 2, T> final
{
    static_assert(std::is_arithmetic<T>::value, "Expected floating-point or integer type.");

    using value_type  = T;            ///< Value type
    using column_type = vector<2, T>; ///< Column type
    using row_type    = vector<3, T>; ///< Row type

    /// @brief Default constructor.
    ///
    /// Creates an identity matrix.
    constexpr matrix() noexcept;

    /// @brief Initializes matrices with provided values.
    ///
    /// @param value00 Value for first column.
    /// @param value01 Value for first column.
    /// @param value10 Value for second column.
    /// @param value11 Value for second column.
    /// @param value20 Value for third column.
    /// @param value21 Value for third column.

    // clang-format off
    constexpr matrix(const T& value00, const T& value01,
                     const T& value10, const T& value11,
                     const T& value20, const T& value21);
    // clang-format on

    /// @brief Initialize the main diagonal of matrix with provided value.
    ///
    /// @param value Floating-point or integral value.
    explicit constexpr matrix(const T& value) noexcept;

    /// @brief Initializes all components of matrix from pointer to values.
    ///
    /// @param pointer Const pointer to values that should be taken.
    ///
    /// @warning May cause memory access error.
    template <typename U>
    explicit matrix(const U* pointer);

    /// @brief Initializes all components of matrix from pointer to values.
    ///
    /// @param pointer Pointer to values that should be taken.
    ///
    /// @warning May cause memory access error.
    template <typename U>
    explicit matrix(U* pointer);

    /// @brief Initializes matrices with provided vectors.
    ///
    /// @param column0 Vector for first column.
    /// @param column1 Vector for second column.
    /// @param column2 Vector for third column.
    template <typename U0, typename U1, typename U2>
    constexpr matrix(const vector<4, U0>& column0, const vector<4, U1>& column1, const vector<4, U2>& column2);

    /// @brief Initializes matrices with provided vectors.
    ///
    /// @param column0 Vector for first column.
    /// @param column1 Vector for second column.
    /// @param column2 Vector for third column.
    template <typename U0, typename U1, typename U2>
    constexpr matrix(const vector<3, U0>& column0, const vector<3, U1>& column1, const vector<3, U2>& column2);

    /// @brief Initializes matrices with provided vectors.
    ///
    /// @param column0 Vector for first column.
    /// @param column1 Vector for second column.
    /// @param column2 Vector for third column.

    // clang-format off
    template <typename U0,
              typename U1,
              typename U2>
    constexpr matrix(const vector<2, U0>& column0,
                     const vector<2, U1>& column1,
                     const vector<2, U2>& column2);
    // clang-format on

    /// @brief Initializes matrix from another one.
    ///
    /// @param other Matrix of integral or floating-point type.
    ///
    /// @note The remain components will be initialized as in identity matrix.
    template <uint32 C, uint32 R, typename U>
    explicit constexpr matrix(const matrix<C, R, U>& other);

    /// @brief Access operator.
    ///
    /// @param index Index of column.
    ///
    /// @return Reference to column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    column_type& operator[](uint32 index);

    /// @brief Const access operator.
    ///
    /// @param index Index of column.
    ///
    /// @return Reference to constant column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    const column_type& operator[](uint32 index) const;

    /// @brief Size of matrix.
    ///
    /// @return Count of columns in matrix.
    constexpr uint32 size() const noexcept;

    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the x component of first column.
    value_type* data() noexcept;

    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the x component of first column.
    const value_type* data() const noexcept;

    /// @brief Provides access to columns of the matrix.
    ///
    /// @param index Index of column.
    ///
    /// @return Copy of column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    column_type column(uint32 index) const noexcept;

    /// @brief Provides access to rows of the matrix.
    ///
    /// @param index Index of row.
    ///
    /// @return Copy of row at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    row_type row(uint32 index) const noexcept;

private:
    column_type m_data[3];
};

/// @brief matrix<2, 4, T> type specialization.
///
/// @note Can be instantiated only with arithmetic type.
template <typename T>
struct matrix<2, 4, T> final
{
    static_assert(std::is_arithmetic<T>::value, "Expected floating-point or integer type.");

    using value_type  = T;            ///< Value type
    using column_type = vector<4, T>; ///< Column type
    using row_type    = vector<2, T>; ///< Row type

    /// @brief Default constructor.
    ///
    /// Creates an identity matrix.
    constexpr matrix() noexcept;

    /// @brief Initializes matrices with provided values.
    ///
    /// @param value00 Value for first column.
    /// @param value01 Value for first column.
    /// @param value02 Value for first column.
    /// @param value03 Value for first column.
    /// @param value10 Value for second column.
    /// @param value11 Value for second column.
    /// @param value12 Value for second column.
    /// @param value13 Value for second column.

    // clang-format off
    constexpr matrix(const T& value00, const T& value01, const T& value02, const T& value03,
                     const T& value10, const T& value11, const T& value12, const T& value13);
    // clang-format on

    /// @brief Initialize the main diagonal of matrix with provided value.
    ///
    /// @param value Floating-point or integral value.
    explicit constexpr matrix(const T& value) noexcept;

    /// @brief Initializes all components of matrix from pointer to values.
    ///
    /// @param pointer Const pointer to values that should be taken.
    ///
    /// @warning May cause memory access error.
    template <typename U>
    explicit matrix(const U* pointer);

    /// @brief Initializes all components of matrix from pointer to values.
    ///
    /// @param pointer Pointer to values that should be taken.
    ///
    /// @warning May cause memory access error.
    template <typename U>
    explicit matrix(U* pointer);

    /// @brief Initializes matrices with provided vectors.
    ///
    /// @param column0 Vector for first column.
    /// @param column1 Vector for second column.
    template <typename U0, typename U1>
    constexpr matrix(const vector<4, U0>& column0, const vector<4, U1>& column1);

    /// @brief Initializes matrices with provided vectors and scalar values.
    ///
    /// @param vector0 First part for first column.
    /// @param w0 Last component for first column.
    /// @param vector1 First part for second column.
    /// @param w1 Last component for second column.

    // clang-format off
    template <typename U0, typename W0,
              typename U1, typename W1>
    constexpr matrix(const vector<3, U0>& vector0, const W0& w0,
                     const vector<3, U1>& vector1, const W1& w1);
    // clang-format on

    /// @brief Initializes matrices with provided scalar values and vectors.
    ///
    /// @param x0 First component for first column.
    /// @param vector0 Last part for first column.
    /// @param x1 First component for second column.
    /// @param vector1 Last part for second column.

    // clang-format off
    template <typename X0, typename U0,
              typename X1, typename U1>
    constexpr matrix(const X0& x0, const vector<3, U0>& vector0,
                     const X1& x1, const vector<3, U1>& vector1);
    // clang-format on

    /// @brief Initializes matrices with provided vectors and values.
    ///
    /// @param vector00 First part for first column.
    /// @param vector01 Last part for first column.
    /// @param vector10 First part for second column.
    /// @param vector11 Last part for second column.

    // clang-format off
    template <typename U00, typename U01,
              typename U10, typename U11>
    constexpr matrix(const vector<2, U00>& vector00, const vector<2, U01>& vector01,
                     const vector<2, U10>& vector10, const vector<2, U11>& vector11);
    // clang-format on

    /// @brief Initializes matrices with provided vectors and values.
    ///
    /// @param vector0 First part for first column.
    /// @param z0 Z component for first column.
    /// @param w0 W component for first column.
    /// @param vector1 First part for second column.
    /// @param z1 Z component for second column.
    /// @param w1 W component for second column.

    // clang-format off
    template <typename U0, typename Z0, typename W0,
              typename U1, typename Z1, typename W1>
    constexpr matrix(const vector<2, U0>& vector0, const Z0& z0, const W0& w0,
                     const vector<2, U1>& vector1, const Z1& z1, const W1& w1);
    // clang-format on

    /// @brief Initializes matrices with provided vectors and values.
    ///
    /// @param x0 X component for first column.
    /// @param vector0 Middle part for first column.
    /// @param w0 W component for first column.
    /// @param x1 X component for second column.
    /// @param vector1 Middle part for second column.
    /// @param w1 W component for second column.

    // clang-format off
    template <typename X0, typename U0, typename W0,
              typename X1, typename U1, typename W1>
    constexpr matrix(const X0& x0, const vector<2, U0>& vector0, const W0& w0,
                     const X1& x1, const vector<2, U1>& vector1, const W1& w1);
    // clang-format on

    /// @brief Initializes matrices with provided vectors and values.
    ///
    /// @param x0 X component for first column.
    /// @param y0 Y component for first column.
    /// @param vector0 Last part for first column.
    /// @param x1 X component for second column.
    /// @param y1 Y component for second column.
    /// @param vector1 Last part for second column.

    // clang-format off
    template <typename X0, typename Y0, typename U0,
              typename X1, typename Y1, typename U1>
    constexpr matrix(const X0& x0, const Y0& y0, const vector<2, U0>& vector0,
                     const X1& x1, const Y1& y1, const vector<2, U1>& vector1);
    // clang-format on

    /// @brief Initializes matrix from another one.
    ///
    /// @param other Matrix of integral or floating-point type.
    ///
    /// @note The remain components will be initialized as in identity matrix.
    template <uint32 C, uint32 R, typename U>
    explicit constexpr matrix(const matrix<C, R, U>& other);

    /// @brief Access operator.
    ///
    /// @param index Index of column.
    ///
    /// @return Reference to column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    column_type& operator[](uint32 index);

    /// @brief Const access operator.
    ///
    /// @param index Index of column.
    ///
    /// @return Reference to constant column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    const column_type& operator[](uint32 index) const;

    /// @brief Size of matrix.
    ///
    /// @return Count of columns in matrix.
    constexpr uint32 size() const noexcept;

    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the x component of first column.
    value_type* data() noexcept;

    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the x component of first column.
    const value_type* data() const noexcept;

    /// @brief Provides access to columns of the matrix.
    ///
    /// @param index Index of column.
    ///
    /// @return Copy of column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    column_type column(uint32 index) const noexcept;

    /// @brief Provides access to rows of the matrix.
    ///
    /// @param index Index of row.
    ///
    /// @return Copy of row at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    row_type row(uint32 index) const noexcept;

private:
    column_type m_data[2];
};

/// @brief matrix<2, 3, T> type specialization.
///
/// @note Can be instantiated only with arithmetic type.
template <typename T>
struct matrix<2, 3, T> final
{
    static_assert(std::is_arithmetic<T>::value, "Expected floating-point or integer type.");

    using value_type  = T;            ///< Value type
    using column_type = vector<3, T>; ///< Column type
    using row_type    = vector<2, T>; ///< Row type

    /// @brief Default constructor.
    ///
    /// Creates an identity matrix.
    constexpr matrix() noexcept;

    /// @brief Initializes matrices with provided values.
    ///
    /// @param value00 Value for first column.
    /// @param value01 Value for first column.
    /// @param value02 Value for first column.
    /// @param value10 Value for second column.
    /// @param value11 Value for second column.
    /// @param value12 Value for second column.

    // clang-format off
    constexpr matrix(const T& value00, const T& value01, const T& value02,
                     const T& value10, const T& value11, const T& value12);
    // clang-format on

    /// @brief Initialize the main diagonal of matrix with provided value.
    ///
    /// @param value Floating-point or integral value.
    explicit constexpr matrix(const T& value) noexcept;

    /// @brief Initializes all components of matrix from pointer to values.
    ///
    /// @param pointer Const pointer to values that should be taken.
    ///
    /// @warning May cause memory access error.
    template <typename U>
    explicit matrix(const U* pointer);

    /// @brief Initializes all components of matrix from pointer to values.
    ///
    /// @param pointer Pointer to values that should be taken.
    ///
    /// @warning May cause memory access error.
    template <typename U>
    explicit matrix(U* pointer);

    /// @brief Initializes matrices with provided vectors.
    ///
    /// @param column0 Vector for first column.
    /// @param column1 Vector for second column.
    template <typename U0, typename U1>
    constexpr matrix(const vector<4, U0>& column0, const vector<4, U1>& column1);

    /// @brief Initializes matrices with provided vectors.
    ///
    /// @param column0 Vector for first column.
    /// @param column1 Vector for second column.
    template <typename U0, typename U1>
    constexpr matrix(const vector<3, U0>& column0, const vector<3, U1>& column1);

    /// @brief Initializes matrices with provided vectors and values.
    ///
    /// @param vector0 First part for first column.
    /// @param z0 Z component for first column.
    /// @param vector1 First part for second column.
    /// @param z1 Z component for second column.

    // clang-format off
    template <typename U0, typename Z0,
              typename U1, typename Z1>
    constexpr matrix(const vector<2, U0>& vector0, const Z0& z0,
                     const vector<2, U1>& vector1, const Z1& z1);
    // clang-format on

    /// @brief Initializes matrices with provided vectors and values.
    ///
    /// @param x0 X component for first column.
    /// @param vector0 Last part for first column.
    /// @param x1 X component for second column.
    /// @param vector1 Last part for second column.

    // clang-format off
    template <typename X0, typename U0,
              typename X1, typename U1>
    constexpr matrix(const X0& x0, const vector<2, U0>& vector0,
                     const X1& x1, const vector<2, U1>& vector1);
    // clang-format on

    /// @brief Initializes matrix from another one.
    ///
    /// @param other Matrix of integral or floating-point type.
    ///
    /// @note The remain components will be initialized as in identity matrix.
    template <uint32 C, uint32 R, typename U>
    explicit constexpr matrix(const matrix<C, R, U>& other);

    /// @brief Access operator.
    ///
    /// @param index Index of column.
    ///
    /// @return Reference to column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    column_type& operator[](uint32 index);

    /// @brief Const access operator.
    ///
    /// @param index Index of column.
    ///
    /// @return Reference to constant column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    const column_type& operator[](uint32 index) const;

    /// @brief Size of matrix.
    ///
    /// @return Count of columns in matrix.
    constexpr uint32 size() const noexcept;

    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the x component of first column.
    value_type* data() noexcept;

    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the x component of first column.
    const value_type* data() const noexcept;

    /// @brief Provides access to columns of the matrix.
    ///
    /// @param index Index of column.
    ///
    /// @return Copy of column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    column_type column(uint32 index) const noexcept;

    /// @brief Provides access to rows of the matrix.
    ///
    /// @param index Index of row.
    ///
    /// @return Copy of row at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    row_type row(uint32 index) const noexcept;

private:
    column_type m_data[2];
};

/// @brief matrix<2, 2, T> type specialization.
///
/// @note Can be instantiated only with arithmetic type.
template <typename T>
struct matrix<2, 2, T> final
{
    static_assert(std::is_arithmetic<T>::value, "Expected floating-point or integer type.");

    using value_type  = T;            ///< Value type
    using column_type = vector<2, T>; ///< Column type
    using row_type    = vector<2, T>; ///< Row type

    /// @brief Default constructor.
    ///
    /// Creates an identity matrix.
    constexpr matrix() noexcept;

    /// @brief Initializes matrices with provided values.
    ///
    /// @param value00 Value for first column.
    /// @param value01 Value for first column.
    /// @param value10 Value for second column.
    /// @param value11 Value for second column.
    constexpr matrix(const T& value00, const T& value01, const T& value10, const T& value11);

    /// @brief Initialize the main diagonal of matrix with provided value.
    ///
    /// @param value Floating-point or integral value.
    explicit constexpr matrix(const T& value) noexcept;

    /// @brief Initializes all components of matrix from pointer to values.
    ///
    /// @param pointer Const pointer to values that should be taken.
    ///
    /// @warning May cause memory access error.
    template <typename U>
    explicit matrix(const U* pointer);

    /// @brief Initializes all components of matrix from pointer to values.
    ///
    /// @param pointer Pointer to values that should be taken.
    ///
    /// @warning May cause memory access error.
    template <typename U>
    explicit matrix(U* pointer);

    /// @brief Initializes matrices with provided vectors.
    ///
    /// @param column0 Vector for first column.
    /// @param column1 Vector for second column.
    template <typename U0, typename U1>
    constexpr matrix(const vector<4, U0>& column0, const vector<4, U1>& column1);

    /// @brief Initializes matrices with provided vectors.
    ///
    /// @param column0 Vector for first column.
    /// @param column1 Vector for second column.
    template <typename U0, typename U1>
    constexpr matrix(const vector<3, U0>& column0, const vector<3, U1>& column1);

    /// @brief Initializes matrices with provided vectors.
    ///
    /// @param column0 Vector for first column.
    /// @param column1 Vector for second column.
    template <typename U0, typename U1>
    constexpr matrix(const vector<2, U0>& column0, const vector<2, U1>& column1);

    /// @brief Initializes matrix from another one.
    ///
    /// @param other Matrix of integral or floating-point type.
    ///
    /// @note The remain components will be initialized as in identity matrix.
    template <uint32 C, uint32 R, typename U>
    explicit constexpr matrix(const matrix<C, R, U>& other);

    /// @brief Access operator.
    ///
    /// @param index Index of column.
    ///
    /// @return Reference to column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    column_type& operator[](uint32 index);

    /// @brief Const access operator.
    ///
    /// @param index Index of column.
    ///
    /// @return Reference to constant column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    const column_type& operator[](uint32 index) const;

    /// @brief Size of matrix.
    ///
    /// @return Count of columns in matrix.
    constexpr uint32 size() const noexcept;

    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the x component of first column.
    value_type* data() noexcept;

    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the x component of first column.
    const value_type* data() const noexcept;

    /// @brief Provides access to columns of the matrix.
    ///
    /// @param index Index of column.
    ///
    /// @return Copy of column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    column_type column(uint32 index) const noexcept;

    /// @brief Provides access to rows of the matrix.
    ///
    /// @param index Index of row.
    ///
    /// @return Copy of row at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    row_type row(uint32 index) const noexcept;

private:
    column_type m_data[2];
};
/// @}

/// @name matrix<4, 4, T> constructors.
/// @{
template <typename T>
inline constexpr matrix<4, 4, T>::matrix() noexcept : matrix(T{1})
{}

// clang-format off
template <typename T>
inline constexpr matrix<4, 4, T>::matrix(const T& value00, const T& value01, const T& value02, const T& value03,
                                         const T& value10, const T& value11, const T& value12, const T& value13,
                                         const T& value20, const T& value21, const T& value22, const T& value23,
                                         const T& value30, const T& value31, const T& value32, const T& value33)
    : m_data{column_type(value00, value01, value02, value03),
             column_type(value10, value11, value12, value13),
             column_type(value20, value21, value22, value23),
             column_type(value30, value31, value32, value33)}
{
}
// clang-format on

// clang-format off
template <typename T>
inline constexpr matrix<4, 4, T>::matrix(const T& value) noexcept
    : m_data{column_type(value, 0, 0, 0),
             column_type(0, value, 0, 0),
             column_type(0, 0, value, 0),
             column_type(0, 0, 0, value)}
{
}
// clang-format on

template <typename T>
template <typename U>
inline matrix<4, 4, T>::matrix(const U* pointer)
    : m_data{column_type(pointer), column_type(pointer + 4), column_type(pointer + 8), column_type(pointer + 12)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

template <typename T>
template <typename U>
inline matrix<4, 4, T>::matrix(U* pointer)
    : m_data{column_type(pointer), column_type(pointer + 4), column_type(pointer + 8), column_type(pointer + 12)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

template <typename T>
template <typename U0, typename U1, typename U2, typename U3>
inline constexpr matrix<4, 4, T>::matrix(const vector<4, U0>& column0,
                                         const vector<4, U1>& column1,
                                         const vector<4, U2>& column2,
                                         const vector<4, U3>& column3)
    : m_data{column_type(column0), column_type(column1), column_type(column2), column_type(column3)}
{}

// clang-format off
template <typename T>
template <typename U0, typename W0,
          typename U1, typename W1,
          typename U2, typename W2,
          typename U3, typename W3>
inline constexpr matrix<4, 4, T>::matrix(const vector<3, U0>& vector0, const W0& w0,
                                         const vector<3, U1>& vector1, const W1& w1,
                                         const vector<3, U2>& vector2, const W2& w2,
                                         const vector<3, U3>& vector3, const W3& w3)
    : m_data{column_type(vector0, w0),
             column_type(vector1, w1),
             column_type(vector2, w2),
             column_type(vector3, w3)}
{
}
// clang-format on

// clang-format off
template <typename T>
template <typename X0, typename U0,
          typename X1, typename U1,
          typename X2, typename U2,
          typename X3, typename U3>
inline constexpr matrix<4, 4, T>::matrix(const X0& x0, const vector<3, U0>& vector0,
                                         const X1& x1, const vector<3, U1>& vector1,
                                         const X2& x2, const vector<3, U2>& vector2,
                                         const X3& x3, const vector<3, U3>& vector3)
    : m_data{column_type(x0, vector0),
             column_type(x1, vector1),
             column_type(x2, vector2),
             column_type(x3, vector3)}
{
}
// clang-format on

// clang-format off
template <typename T>
template <typename U00, typename U01,
          typename U10, typename U11,
          typename U20, typename U21,
          typename U30, typename U31>
inline constexpr matrix<4, 4, T>::matrix(const vector<2, U00>& vector00, const vector<2, U01>& vector01,
                                         const vector<2, U10>& vector10, const vector<2, U11>& vector11,
                                         const vector<2, U20>& vector20, const vector<2, U21>& vector21,
                                         const vector<2, U30>& vector30, const vector<2, U31>& vector31)
    : m_data{column_type(vector00, vector01),
             column_type(vector10, vector11),
             column_type(vector20, vector21),
             column_type(vector30, vector31)}
{
}
// clang-format on

// clang-format off
template <typename T>
template <typename U0, typename Z0, typename W0,
          typename U1, typename Z1, typename W1,
          typename U2, typename Z2, typename W2,
          typename U3, typename Z3, typename W3>
inline constexpr matrix<4, 4, T>::matrix(const vector<2, U0>& vector0, const Z0& z0, const W0& w0,
                                         const vector<2, U1>& vector1, const Z1& z1, const W1& w1,
                                         const vector<2, U2>& vector2, const Z2& z2, const W2& w2,
                                         const vector<2, U3>& vector3, const Z3& z3, const W3& w3)
    : m_data{column_type(vector0, z0, w0),
             column_type(vector1, z1, w1),
             column_type(vector2, z2, w2),
             column_type(vector3, z3, w3)}
{
}
// clang-format on

// clang-format off
template <typename T>
template <typename X0, typename U0, typename W0,
          typename X1, typename U1, typename W1,
          typename X2, typename U2, typename W2,
          typename X3, typename U3, typename W3>
inline constexpr matrix<4, 4, T>::matrix(const X0& x0, const vector<2, U0>& vector0, const W0& w0,
                                         const X1& x1, const vector<2, U1>& vector1, const W1& w1,
                                         const X2& x2, const vector<2, U2>& vector2, const W2& w2,
                                         const X3& x3, const vector<2, U3>& vector3, const W3& w3)
    : m_data{column_type(x0, vector0, w0),
             column_type(x1, vector1, w1),
             column_type(x2, vector2, w2),
             column_type(x3, vector3, w3)}
{
}
// clang-format on

// clang-format off
template <typename T>
template <typename X0, typename Y0, typename U0,
          typename X1, typename Y1, typename U1,
          typename X2, typename Y2, typename U2,
          typename X3, typename Y3, typename U3>
inline constexpr matrix<4, 4, T>::matrix(const X0& x0, const Y0& y0, const vector<2, U0>& vector0,
                 const X1& x1, const Y1& y1, const vector<2, U1>& vector1,
                 const X2& x2, const Y2& y2, const vector<2, U2>& vector2,
                 const X3& x3, const Y3& y3, const vector<2, U3>& vector3)
    : m_data{column_type(x0, y0, vector0),
             column_type(x1, y1, vector1),
             column_type(x2, y2, vector2),
             column_type(x3, y3, vector3)}
{
}
// clang-format on

template <typename T>
template <uint32 C, uint32 R, typename U>
inline constexpr matrix<4, 4, T>::matrix(const matrix<C, R, U>& other)
    : m_data{matrix_type_details::get_column<0, C>(other, column_type(1, 0, 0, 0)),
             matrix_type_details::get_column<1, C>(other, column_type(0, 1, 0, 0)),
             matrix_type_details::get_column<2, C>(other, column_type(0, 0, 1, 0)),
             matrix_type_details::get_column<3, C>(other, column_type(0, 0, 0, 1))}
{}
/// @}

/// @name matrix<4, 4, T> operators.
/// @{
template <typename T>
inline typename matrix<4, 4, T>::column_type& matrix<4, 4, T>::operator[](uint32 index)
{
    assert(index < 4);
    return m_data[index];
}

template <typename T>
inline const typename matrix<4, 4, T>::column_type& matrix<4, 4, T>::operator[](uint32 index) const
{
    assert(index < 4);
    return m_data[index];
}
/// @}

/// @name matrix<4, 4, T> methods.
/// @{
template <typename T>
inline constexpr uint32 matrix<4, 4, T>::size() const noexcept
{
    return 4;
}

template <typename T>
inline typename matrix<4, 4, T>::value_type* matrix<4, 4, T>::data() noexcept
{
    return m_data[0].data();
}

template <typename T>
const typename matrix<4, 4, T>::value_type* matrix<4, 4, T>::data() const noexcept
{
    return m_data[0].data();
}

template <typename T>
inline typename matrix<4, 4, T>::column_type matrix<4, 4, T>::column(uint32 index) const noexcept
{
    assert(index < 4);
    return m_data[index];
}

template <typename T>
inline typename matrix<4, 4, T>::row_type matrix<4, 4, T>::row(uint32 index) const noexcept
{
    assert(index < 4);
    return matrix<4, 4, T>::row_type(m_data[0][index], m_data[1][index], m_data[2][index], m_data[3][index]);
}
/// @}

/// @name matrix<4, 3, T> constructors.
/// @{
template <typename T>
inline constexpr matrix<4, 3, T>::matrix() noexcept : matrix(T{1})
{}

// clang-format off
template <typename T>
inline constexpr matrix<4, 3, T>::matrix(const T& value00, const T& value01, const T& value02,
                                         const T& value10, const T& value11, const T& value12,
                                         const T& value20, const T& value21, const T& value22,
                                         const T& value30, const T& value31, const T& value32)
    : m_data{column_type(value00, value01, value02),
             column_type(value10, value11, value12),
             column_type(value20, value21, value22),
             column_type(value30, value31, value32)}
{
}
// clang-format on

// clang-format off
template <typename T>
inline constexpr matrix<4, 3, T>::matrix(const T& value) noexcept
    : m_data{column_type(value, 0, 0),
             column_type(0, value, 0),
             column_type(0, 0, value),
             column_type(0, 0, 0)}
{
}
// clang-format on

template <typename T>
template <typename U>
inline matrix<4, 3, T>::matrix(const U* pointer)
    : m_data{column_type(pointer), column_type(pointer + 3), column_type(pointer + 6), column_type(pointer + 9)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

template <typename T>
template <typename U>
inline matrix<4, 3, T>::matrix(U* pointer)
    : m_data{column_type(pointer), column_type(pointer + 3), column_type(pointer + 6), column_type(pointer + 9)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

template <typename T>
template <typename U0, typename U1, typename U2, typename U3>
inline constexpr matrix<4, 3, T>::matrix(const vector<4, U0>& column0,
                                         const vector<4, U1>& column1,
                                         const vector<4, U2>& column2,
                                         const vector<4, U3>& column3)
    : m_data{column_type(column0), column_type(column1), column_type(column2), column_type(column3)}
{}

template <typename T>
template <typename U0, typename U1, typename U2, typename U3>
inline constexpr matrix<4, 3, T>::matrix(const vector<3, U0>& column0,
                                         const vector<3, U1>& column1,
                                         const vector<3, U2>& column2,
                                         const vector<3, U3>& column3)
    : m_data{column_type(column0), column_type(column1), column_type(column2), column_type(column3)}
{}

// clang-format off
template <typename T>
template <typename U0, typename Z0,
          typename U1, typename Z1,
          typename U2, typename Z2,
          typename U3, typename Z3>
inline constexpr matrix<4, 3, T>::matrix(const vector<2, U0>& vector0, const Z0& z0,
                                         const vector<2, U1>& vector1, const Z1& z1,
                                         const vector<2, U2>& vector2, const Z2& z2,
                                         const vector<2, U3>& vector3, const Z3& z3)
    : m_data{column_type(vector0, z0),
             column_type(vector1, z1),
             column_type(vector2, z2),
             column_type(vector3, z3)}
{
}
// clang-format on

// clang-format off
template <typename T>
template <typename X0, typename U0,
          typename X1, typename U1,
          typename X2, typename U2,
          typename X3, typename U3>
inline constexpr matrix<4, 3, T>::matrix(const X0& x0, const vector<2, U0>& vector0,
                                         const X1& x1, const vector<2, U1>& vector1,
                                         const X2& x2, const vector<2, U2>& vector2,
                                         const X3& x3, const vector<2, U3>& vector3)
    : m_data{column_type(x0, vector0),
             column_type(x1, vector1),
             column_type(x2, vector2),
             column_type(x3, vector3)}
{
}
// clang-format on

template <typename T>
template <uint32 C, uint32 R, typename U>
inline constexpr matrix<4, 3, T>::matrix(const matrix<C, R, U>& other)
    : m_data{matrix_type_details::get_column<0, C>(other, column_type(1, 0, 0)),
             matrix_type_details::get_column<1, C>(other, column_type(0, 1, 0)),
             matrix_type_details::get_column<2, C>(other, column_type(0, 0, 1)),
             matrix_type_details::get_column<3, C>(other, column_type(0, 0, 0))}
{}
/// @}

/// @name matrix<4, 3, T> operators.
/// @{
template <typename T>
inline typename matrix<4, 3, T>::column_type& matrix<4, 3, T>::operator[](uint32 index)
{
    assert(index < 4);
    return m_data[index];
}

template <typename T>
inline const typename matrix<4, 3, T>::column_type& matrix<4, 3, T>::operator[](uint32 index) const
{
    assert(index < 4);
    return m_data[index];
}
/// @}

/// @name matrix<4, 3, T> methods.
/// @{
template <typename T>
inline constexpr uint32 matrix<4, 3, T>::size() const noexcept
{
    return 4;
}

template <typename T>
inline typename matrix<4, 3, T>::value_type* matrix<4, 3, T>::data() noexcept
{
    return m_data[0].data();
}

template <typename T>
const typename matrix<4, 3, T>::value_type* matrix<4, 3, T>::data() const noexcept
{
    return m_data[0].data();
}

template <typename T>
inline typename matrix<4, 3, T>::column_type matrix<4, 3, T>::column(uint32 index) const noexcept
{
    assert(index < 4);
    return m_data[index];
}

template <typename T>
inline typename matrix<4, 3, T>::row_type matrix<4, 3, T>::row(uint32 index) const noexcept
{
    assert(index < 3);
    return matrix<4, 3, T>::row_type(m_data[0][index], m_data[1][index], m_data[2][index], m_data[3][index]);
}
/// @}

/// @name matrix<4, 2, T> constructors.
/// @{
template <typename T>
inline constexpr matrix<4, 2, T>::matrix() noexcept : matrix(T{1})
{}

// clang-format off
template <typename T>
inline constexpr matrix<4, 2, T>::matrix(const T& value00, const T& value01,
                                         const T& value10, const T& value11,
                                         const T& value20, const T& value21,
                                         const T& value30, const T& value31)
    : m_data{column_type(value00, value01),
             column_type(value10, value11),
             column_type(value20, value21),
             column_type(value30, value31)}
{
}
// clang-format on

// clang-format off
template <typename T>
inline constexpr matrix<4, 2, T>::matrix(const T& value) noexcept
    : m_data{column_type(value, 0),
             column_type(0, value),
             column_type(0, 0),
             column_type(0, 0)}
{
}
// clang-format on

template <typename T>
template <typename U>
inline matrix<4, 2, T>::matrix(const U* pointer)
    : m_data{column_type(pointer), column_type(pointer + 2), column_type(pointer + 4), column_type(pointer + 6)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

template <typename T>
template <typename U>
inline matrix<4, 2, T>::matrix(U* pointer)
    : m_data{column_type(pointer), column_type(pointer + 2), column_type(pointer + 4), column_type(pointer + 6)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

template <typename T>
template <typename U0, typename U1, typename U2, typename U3>
inline constexpr matrix<4, 2, T>::matrix(const vector<4, U0>& column0,
                                         const vector<4, U1>& column1,
                                         const vector<4, U2>& column2,
                                         const vector<4, U3>& column3)
    : m_data{column_type(column0), column_type(column1), column_type(column2), column_type(column3)}
{}

template <typename T>
template <typename U0, typename U1, typename U2, typename U3>
inline constexpr matrix<4, 2, T>::matrix(const vector<3, U0>& column0,
                                         const vector<3, U1>& column1,
                                         const vector<3, U2>& column2,
                                         const vector<3, U3>& column3)
    : m_data{column_type(column0), column_type(column1), column_type(column2), column_type(column3)}
{}

template <typename T>
template <typename U0, typename U1, typename U2, typename U3>
inline constexpr matrix<4, 2, T>::matrix(const vector<2, U0>& column0,
                                         const vector<2, U1>& column1,
                                         const vector<2, U2>& column2,
                                         const vector<2, U3>& column3)
    : m_data{column_type(column0), column_type(column1), column_type(column2), column_type(column3)}
{}

template <typename T>
template <uint32 C, uint32 R, typename U>
inline constexpr matrix<4, 2, T>::matrix(const matrix<C, R, U>& other)
    : m_data{matrix_type_details::get_column<0, C>(other, column_type(1, 0)),
             matrix_type_details::get_column<1, C>(other, column_type(0, 1)),
             matrix_type_details::get_column<2, C>(other, column_type(0, 0)),
             matrix_type_details::get_column<3, C>(other, column_type(0, 0))}
{}
/// @}

/// @name matrix<4, 2, T> operators.
/// @{
template <typename T>
inline typename matrix<4, 2, T>::column_type& matrix<4, 2, T>::operator[](uint32 index)
{
    assert(index < 4);
    return m_data[index];
}

template <typename T>
inline const typename matrix<4, 2, T>::column_type& matrix<4, 2, T>::operator[](uint32 index) const
{
    assert(index < 4);
    return m_data[index];
}
/// @}

/// @name matrix<4, 2, T> methods.
/// @{
template <typename T>
inline constexpr uint32 matrix<4, 2, T>::size() const noexcept
{
    return 4;
}

template <typename T>
inline typename matrix<4, 2, T>::value_type* matrix<4, 2, T>::data() noexcept
{
    return m_data[0].data();
}

template <typename T>
const typename matrix<4, 2, T>::value_type* matrix<4, 2, T>::data() const noexcept
{
    return m_data[0].data();
}

template <typename T>
inline typename matrix<4, 2, T>::column_type matrix<4, 2, T>::column(uint32 index) const noexcept
{
    assert(index < 4);
    return m_data[index];
}

template <typename T>
inline typename matrix<4, 2, T>::row_type matrix<4, 2, T>::row(uint32 index) const noexcept
{
    assert(index < 2);
    return matrix<4, 2, T>::row_type(m_data[0][index], m_data[1][index], m_data[2][index], m_data[3][index]);
}
/// @}

/// @name matrix<3, 4, T> constructors.
/// @{
template <typename T>
inline constexpr matrix<3, 4, T>::matrix() noexcept : matrix(T{1})
{}

// clang-format off
template <typename T>
inline constexpr matrix<3, 4, T>::matrix(const T& value00, const T& value01, const T& value02, const T& value03,
                                         const T& value10, const T& value11, const T& value12, const T& value13,
                                         const T& value20, const T& value21, const T& value22, const T& value23)
    : m_data{column_type(value00, value01, value02, value03),
             column_type(value10, value11, value12, value13),
             column_type(value20, value21, value22, value23)}
{
}
// clang-format on

// clang-format off
template <typename T>
inline constexpr matrix<3, 4, T>::matrix(const T& value) noexcept
    : m_data{column_type(value, 0, 0, 0),
             column_type(0, value, 0, 0),
             column_type(0, 0, value, 0)}
{
}
// clang-format on

template <typename T>
template <typename U>
inline matrix<3, 4, T>::matrix(const U* pointer)
    : m_data{column_type(pointer), column_type(pointer + 4), column_type(pointer + 8)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

template <typename T>
template <typename U>
inline matrix<3, 4, T>::matrix(U* pointer)
    : m_data{column_type(pointer), column_type(pointer + 4), column_type(pointer + 8)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

// clang-format off
template <typename T>
template <typename U0, typename U1, typename U2>
inline constexpr matrix<3, 4, T>::matrix(const vector<4, U0>& column0,
                                         const vector<4, U1>& column1,
                                         const vector<4, U2>& column2)
    : m_data{column_type(column0), column_type(column1), column_type(column2)}
{
}
// clang-format on

// clang-format off
template <typename T>
template <typename U0, typename W0,
          typename U1, typename W1,
          typename U2, typename W2>
inline constexpr matrix<3, 4, T>::matrix(const vector<3, U0>& vector0, const W0& w0,
                                         const vector<3, U1>& vector1, const W1& w1,
                                         const vector<3, U2>& vector2, const W2& w2)
    : m_data{column_type(vector0, w0),
             column_type(vector1, w1),
             column_type(vector2, w2)}
{
}
// clang-format on

// clang-format off
template <typename T>
template <typename X0, typename U0,
          typename X1, typename U1,
          typename X2, typename U2>
inline constexpr matrix<3, 4, T>::matrix(const X0& x0, const vector<3, U0>& vector0,
                                         const X1& x1, const vector<3, U1>& vector1,
                                         const X2& x2, const vector<3, U2>& vector2)
    : m_data{column_type(x0, vector0),
             column_type(x1, vector1),
             column_type(x2, vector2)}
{
}
// clang-format on

// clang-format off
template <typename T>
template <typename U00, typename U01,
          typename U10, typename U11,
          typename U20, typename U21>
inline constexpr matrix<3, 4, T>::matrix(const vector<2, U00>& vector00, const vector<2, U01>& vector01,
                                         const vector<2, U10>& vector10, const vector<2, U11>& vector11,
                                         const vector<2, U20>& vector20, const vector<2, U21>& vector21)
    : m_data{column_type(vector00, vector01),
             column_type(vector10, vector11),
             column_type(vector20, vector21)}
{
}
// clang-format on

// clang-format off
template <typename T>
template <typename U0, typename Z0, typename W0,
          typename U1, typename Z1, typename W1,
          typename U2, typename Z2, typename W2>
inline constexpr matrix<3, 4, T>::matrix(const vector<2, U0>& vector0, const Z0& z0, const W0& w0,
                                         const vector<2, U1>& vector1, const Z1& z1, const W1& w1,
                                         const vector<2, U2>& vector2, const Z2& z2, const W2& w2)
    : m_data{column_type(vector0, z0, w0),
             column_type(vector1, z1, w1),
             column_type(vector2, z2, w2)}
{
}
// clang-format on

// clang-format off
template <typename T>
template <typename X0, typename U0, typename W0,
          typename X1, typename U1, typename W1,
          typename X2, typename U2, typename W2>
inline constexpr matrix<3, 4, T>::matrix(const X0& x0, const vector<2, U0>& vector0, const W0& w0,
                                         const X1& x1, const vector<2, U1>& vector1, const W1& w1,
                                         const X2& x2, const vector<2, U2>& vector2, const W2& w2)
    : m_data{column_type(x0, vector0, w0),
             column_type(x1, vector1, w1),
             column_type(x2, vector2, w2)}
{
}
// clang-format on

// clang-format off
template <typename T>
template <typename X0, typename Y0, typename U0,
          typename X1, typename Y1, typename U1,
          typename X2, typename Y2, typename U2>
inline constexpr matrix<3, 4, T>::matrix(const X0& x0, const Y0& y0, const vector<2, U0>& vector0,
                                         const X1& x1, const Y1& y1, const vector<2, U1>& vector1,
                                         const X2& x2, const Y2& y2, const vector<2, U2>& vector2)
    : m_data{column_type(x0, y0, vector0),
             column_type(x1, y1, vector1),
             column_type(x2, y2, vector2)}
{
}
// clang-format on

template <typename T>
template <uint32 C, uint32 R, typename U>
inline constexpr matrix<3, 4, T>::matrix(const matrix<C, R, U>& other)
    : m_data{matrix_type_details::get_column<0, C>(other, column_type(1, 0, 0, 0)),
             matrix_type_details::get_column<1, C>(other, column_type(0, 1, 0, 0)),
             matrix_type_details::get_column<2, C>(other, column_type(0, 0, 1, 0))}
{}
/// @}

/// @name matrix<3, 4, T> operators.
/// @{
template <typename T>
inline typename matrix<3, 4, T>::column_type& matrix<3, 4, T>::operator[](uint32 index)
{
    assert(index < 3);
    return m_data[index];
}

template <typename T>
inline const typename matrix<3, 4, T>::column_type& matrix<3, 4, T>::operator[](uint32 index) const
{
    assert(index < 3);
    return m_data[index];
}
/// @}

/// @name matrix<3, 4, T> methods.
/// @{
template <typename T>
inline constexpr uint32 matrix<3, 4, T>::size() const noexcept
{
    return 3;
}

template <typename T>
inline typename matrix<3, 4, T>::value_type* matrix<3, 4, T>::data() noexcept
{
    return m_data[0].data();
}

template <typename T>
const typename matrix<3, 4, T>::value_type* matrix<3, 4, T>::data() const noexcept
{
    return m_data[0].data();
}

template <typename T>
inline typename matrix<3, 4, T>::column_type matrix<3, 4, T>::column(uint32 index) const noexcept
{
    assert(index < 3);
    return m_data[index];
}

template <typename T>
inline typename matrix<3, 4, T>::row_type matrix<3, 4, T>::row(uint32 index) const noexcept
{
    assert(index < 4);
    return matrix<3, 4, T>::row_type(m_data[0][index], m_data[1][index], m_data[2][index]);
}
/// @}

/// @name matrix<3, 3, T> constructors.
/// @{
template <typename T>
inline constexpr matrix<3, 3, T>::matrix() noexcept : matrix(T{1})
{}

// clang-format off
template <typename T>
inline constexpr matrix<3, 3, T>::matrix(const T& value00, const T& value01, const T& value02,
                                         const T& value10, const T& value11, const T& value12,
                                         const T& value20, const T& value21, const T& value22)
    : m_data{column_type(value00, value01, value02),
             column_type(value10, value11, value12),
             column_type(value20, value21, value22)}
{
}
// clang-format on

// clang-format off
template <typename T>
inline constexpr matrix<3, 3, T>::matrix(const T& value) noexcept
    : m_data{column_type(value, 0, 0),
             column_type(0, value, 0),
             column_type(0, 0, value)}
{
}
// clang-format on

template <typename T>
template <typename U>
inline matrix<3, 3, T>::matrix(const U* pointer)
    : m_data{column_type(pointer), column_type(pointer + 3), column_type(pointer + 6)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

template <typename T>
template <typename U>
inline matrix<3, 3, T>::matrix(U* pointer)
    : m_data{column_type(pointer), column_type(pointer + 3), column_type(pointer + 6)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

// clang-format off
template <typename T>
template <typename U0, typename U1, typename U2>
inline constexpr matrix<3, 3, T>::matrix(const vector<4, U0>& column0,
                                         const vector<4, U1>& column1,
                                         const vector<4, U2>& column2)
    : m_data{column_type(column0), column_type(column1), column_type(column2)}
{
}
// clang-format on

// clang-format off
template <typename T>
template <typename U0, typename U1, typename U2>
inline constexpr matrix<3, 3, T>::matrix(const vector<3, U0>& column0,
                                         const vector<3, U1>& column1,
                                         const vector<3, U2>& column2)
    : m_data{column_type(column0), column_type(column1), column_type(column2)}
{
}
// clang-format on

// clang-format off
template <typename T>
template <typename U0, typename Z0,
          typename U1, typename Z1,
          typename U2, typename Z2>
inline constexpr matrix<3, 3, T>::matrix(const vector<2, U0>& vector0, const Z0& z0,
                                         const vector<2, U1>& vector1, const Z1& z1,
                                         const vector<2, U2>& vector2, const Z2& z2)
    : m_data{column_type(vector0, z0),
             column_type(vector1, z1),
             column_type(vector2, z2)}
{
}
// clang-format on

// clang-format off
template <typename T>
template <typename X0, typename U0,
          typename X1, typename U1,
          typename X2, typename U2>
inline constexpr matrix<3, 3, T>::matrix(const X0& x0, const vector<2, U0>& vector0,
                                         const X1& x1, const vector<2, U1>& vector1,
                                         const X2& x2, const vector<2, U2>& vector2)
    : m_data{column_type(x0, vector0),
             column_type(x1, vector1),
             column_type(x2, vector2)}
{
}
// clang-format on

template <typename T>
template <uint32 C, uint32 R, typename U>
inline constexpr matrix<3, 3, T>::matrix(const matrix<C, R, U>& other)
    : m_data{matrix_type_details::get_column<0, C>(other, column_type(1, 0, 0)),
             matrix_type_details::get_column<1, C>(other, column_type(0, 1, 0)),
             matrix_type_details::get_column<2, C>(other, column_type(0, 0, 1))}
{}
/// @}

/// @name matrix<3, 3, T> operators.
/// @{
template <typename T>
inline typename matrix<3, 3, T>::column_type& matrix<3, 3, T>::operator[](uint32 index)
{
    assert(index < 3);
    return m_data[index];
}

template <typename T>
inline const typename matrix<3, 3, T>::column_type& matrix<3, 3, T>::operator[](uint32 index) const
{
    assert(index < 3);
    return m_data[index];
}
/// @}

/// @name matrix<3, 3, T> methods.
/// @{
template <typename T>
inline constexpr uint32 matrix<3, 3, T>::size() const noexcept
{
    return 3;
}

template <typename T>
inline typename matrix<3, 3, T>::value_type* matrix<3, 3, T>::data() noexcept
{
    return m_data[0].data();
}

template <typename T>
const typename matrix<3, 3, T>::value_type* matrix<3, 3, T>::data() const noexcept
{
    return m_data[0].data();
}

template <typename T>
inline typename matrix<3, 3, T>::column_type matrix<3, 3, T>::column(uint32 index) const noexcept
{
    assert(index < 3);
    return m_data[index];
}

template <typename T>
inline typename matrix<3, 3, T>::row_type matrix<3, 3, T>::row(uint32 index) const noexcept
{
    assert(index < 3);
    return matrix<3, 3, T>::row_type(m_data[0][index], m_data[1][index], m_data[2][index]);
}
/// @}

/// @name matrix<3, 2, T> constructors.
/// @{
template <typename T>
inline constexpr matrix<3, 2, T>::matrix() noexcept : matrix(T{1})
{}

// clang-format off
template <typename T>
inline constexpr matrix<3, 2, T>::matrix(const T& value00, const T& value01,
                                         const T& value10, const T& value11,
                                         const T& value20, const T& value21)
    : m_data{column_type(value00, value01),
             column_type(value10, value11),
             column_type(value20, value21)}
{
}
// clang-format on

// clang-format off
 template <typename T>
 inline constexpr matrix<3, 2, T>::matrix(const T& value) noexcept
    : m_data{column_type(value, 0),
             column_type(0, value),
             column_type(0, 0)}
 {
 }
// clang-format on

template <typename T>
template <typename U>
inline matrix<3, 2, T>::matrix(const U* pointer)
    : m_data{column_type(pointer), column_type(pointer + 2), column_type(pointer + 4)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

template <typename T>
template <typename U>
inline matrix<3, 2, T>::matrix(U* pointer)
    : m_data{column_type(pointer), column_type(pointer + 2), column_type(pointer + 4)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

template <typename T>
template <typename U0, typename U1, typename U2>
inline constexpr matrix<3, 2, T>::matrix(const vector<4, U0>& column0,
                                         const vector<4, U1>& column1,
                                         const vector<4, U2>& column2)
    : m_data{column_type(column0), column_type(column1), column_type(column2)}
{}

template <typename T>
template <typename U0, typename U1, typename U2>
inline constexpr matrix<3, 2, T>::matrix(const vector<3, U0>& column0,
                                         const vector<3, U1>& column1,
                                         const vector<3, U2>& column2)
    : m_data{column_type(column0), column_type(column1), column_type(column2)}
{}

template <typename T>
template <typename U0, typename U1, typename U2>
inline constexpr matrix<3, 2, T>::matrix(const vector<2, U0>& column0,
                                         const vector<2, U1>& column1,
                                         const vector<2, U2>& column2)
    : m_data{column_type(column0), column_type(column1), column_type(column2)}
{}

template <typename T>
template <uint32 C, uint32 R, typename U>
inline constexpr matrix<3, 2, T>::matrix(const matrix<C, R, U>& other)
    : m_data{matrix_type_details::get_column<0, C>(other, column_type(1, 0)),
             matrix_type_details::get_column<1, C>(other, column_type(0, 1)),
             matrix_type_details::get_column<2, C>(other, column_type(0, 0))}
{}
/// @}

/// @name matrix<3, 2, T> operators.
/// @{
template <typename T>
inline typename matrix<3, 2, T>::column_type& matrix<3, 2, T>::operator[](uint32 index)
{
    assert(index < 3);
    return m_data[index];
}

template <typename T>
inline const typename matrix<3, 2, T>::column_type& matrix<3, 2, T>::operator[](uint32 index) const
{
    assert(index < 3);
    return m_data[index];
}
/// @}

/// @name matrix<3, 2, T> methods.
/// @{
template <typename T>
inline constexpr uint32 matrix<3, 2, T>::size() const noexcept
{
    return 3;
}

template <typename T>
inline typename matrix<3, 2, T>::value_type* matrix<3, 2, T>::data() noexcept
{
    return m_data[0].data();
}

template <typename T>
const typename matrix<3, 2, T>::value_type* matrix<3, 2, T>::data() const noexcept
{
    return m_data[0].data();
}

template <typename T>
inline typename matrix<3, 2, T>::column_type matrix<3, 2, T>::column(uint32 index) const noexcept
{
    assert(index < 3);
    return m_data[index];
}

template <typename T>
inline typename matrix<3, 2, T>::row_type matrix<3, 2, T>::row(uint32 index) const noexcept
{
    assert(index < 2);
    return matrix<3, 2, T>::row_type(m_data[0][index], m_data[1][index], m_data[2][index]);
}
/// @}

/// @name matrix<2, 4, T> constructors.
/// @{
template <typename T>
inline constexpr matrix<2, 4, T>::matrix() noexcept : matrix(T{1})
{}

// clang-format off
template <typename T>
inline constexpr matrix<2, 4, T>::matrix(const T& value00, const T& value01, const T& value02, const T& value03,
                                         const T& value10, const T& value11, const T& value12, const T& value13)
    : m_data{column_type(value00, value01, value02, value03),
             column_type(value10, value11, value12, value13)}
{
}
// clang-format on

// clang-format off
template <typename T>
inline constexpr matrix<2, 4, T>::matrix(const T& value) noexcept
    : m_data{column_type(value, 0, 0, 0),
             column_type(0, value, 0, 0)}
{
}
// clang-format on

template <typename T>
template <typename U>
inline matrix<2, 4, T>::matrix(const U* pointer) : m_data{column_type(pointer), column_type(pointer + 4)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

template <typename T>
template <typename U>
inline matrix<2, 4, T>::matrix(U* pointer) : m_data{column_type(pointer), column_type(pointer + 4)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

template <typename T>
template <typename U0, typename U1>
inline constexpr matrix<2, 4, T>::matrix(const vector<4, U0>& column0, const vector<4, U1>& column1)
    : m_data{column_type(column0), column_type(column1)}
{}

// clang-format off
template <typename T>
template <typename U0, typename W0,
          typename U1, typename W1>
inline constexpr matrix<2, 4, T>::matrix(const vector<3, U0>& vector0, const W0& w0,
                                         const vector<3, U1>& vector1, const W1& w1)
    : m_data{column_type(vector0, w0),
             column_type(vector1, w1)}
{
}
// clang-format on

// clang-format off
template <typename T>
template <typename X0, typename U0,
          typename X1, typename U1>
inline constexpr matrix<2, 4, T>::matrix(const X0& x0, const vector<3, U0>& vector0,
                                         const X1& x1, const vector<3, U1>& vector1)
    : m_data{column_type(x0, vector0),
             column_type(x1, vector1)}
{
}
// clang-format on

// clang-format off
template <typename T>
template <typename U00, typename U01,
          typename U10, typename U11>
inline constexpr matrix<2, 4, T>::matrix(const vector<2, U00>& vector00, const vector<2, U01>& vector01,
                                         const vector<2, U10>& vector10, const vector<2, U11>& vector11)
    : m_data{column_type(vector00, vector01),
             column_type(vector10, vector11)}
{
}
// clang-format on

// clang-format off
template <typename T>
template <typename U0, typename Z0, typename W0,
          typename U1, typename Z1, typename W1>
inline constexpr matrix<2, 4, T>::matrix(const vector<2, U0>& vector0, const Z0& z0, const W0& w0,
                                         const vector<2, U1>& vector1, const Z1& z1, const W1& w1)
    : m_data{column_type(vector0, z0, w0),
           column_type(vector1, z1, w1)}
{
}
// clang-format on

// clang-format off
template <typename T>
template <typename X0, typename U0, typename W0,
          typename X1, typename U1, typename W1>
inline constexpr matrix<2, 4, T>::matrix(const X0& x0, const vector<2, U0>& vector0, const W0& w0,
                                         const X1& x1, const vector<2, U1>& vector1, const W1& w1)
    : m_data{column_type(x0, vector0, w0),
             column_type(x1, vector1, w1)}
{
}
// clang-format on

// clang-format off
template <typename T>
template <typename X0, typename Y0, typename U0,
          typename X1, typename Y1, typename U1>
inline constexpr matrix<2, 4, T>::matrix(const X0& x0, const Y0& y0, const vector<2, U0>& vector0,
                                         const X1& x1, const Y1& y1, const vector<2, U1>& vector1)
    : m_data{column_type(x0, y0, vector0),
             column_type(x1, y1, vector1)}
{
}
// clang-format on

template <typename T>
template <uint32 C, uint32 R, typename U>
inline constexpr matrix<2, 4, T>::matrix(const matrix<C, R, U>& other)
    : m_data{matrix_type_details::get_column<0, C>(other, column_type(1, 0, 0, 0)),
             matrix_type_details::get_column<1, C>(other, column_type(0, 1, 0, 0))}
{}
/// @}

/// @name matrix<2, 4, T> operators.
/// @{
template <typename T>
inline typename matrix<2, 4, T>::column_type& matrix<2, 4, T>::operator[](uint32 index)
{
    assert(index < 2);
    return m_data[index];
}

template <typename T>
inline const typename matrix<2, 4, T>::column_type& matrix<2, 4, T>::operator[](uint32 index) const
{
    assert(index < 2);
    return m_data[index];
}
/// @}

/// @name matrix<2, 4, T> methods.
/// @{
template <typename T>
inline constexpr uint32 matrix<2, 4, T>::size() const noexcept
{
    return 2;
}

template <typename T>
inline typename matrix<2, 4, T>::value_type* matrix<2, 4, T>::data() noexcept
{
    return m_data[0].data();
}

template <typename T>
const typename matrix<2, 4, T>::value_type* matrix<2, 4, T>::data() const noexcept
{
    return m_data[0].data();
}

template <typename T>
inline typename matrix<2, 4, T>::column_type matrix<2, 4, T>::column(uint32 index) const noexcept
{
    assert(index < 2);
    return m_data[index];
}

template <typename T>
inline typename matrix<2, 4, T>::row_type matrix<2, 4, T>::row(uint32 index) const noexcept
{
    assert(index < 4);
    return matrix<2, 4, T>::row_type(m_data[0][index], m_data[1][index]);
}
/// @}

/// @name matrix<2, 3, T> constructors.
/// @{
template <typename T>
inline constexpr matrix<2, 3, T>::matrix() noexcept : matrix(T{1})
{}

// clang-format off
template <typename T>
inline constexpr matrix<2, 3, T>::matrix(const T& value00, const T& value01, const T& value02,
                                         const T& value10, const T& value11, const T& value12)
    : m_data{column_type(value00, value01, value02),
             column_type(value10, value11, value12)}
{
}
// clang-format on

// clang-format off
template <typename T>
inline constexpr matrix<2, 3, T>::matrix(const T& value) noexcept
    : m_data{column_type(value, 0, 0),
             column_type(0, value, 0)}
{
}
// clang-format on

template <typename T>
template <typename U>
inline matrix<2, 3, T>::matrix(const U* pointer) : m_data{column_type(pointer), column_type(pointer + 3)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

template <typename T>
template <typename U>
inline matrix<2, 3, T>::matrix(U* pointer) : m_data{column_type(pointer), column_type(pointer + 3)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

template <typename T>
template <typename U0, typename U1>
inline constexpr matrix<2, 3, T>::matrix(const vector<4, U0>& column0, const vector<4, U1>& column1)
    : m_data{column_type(column0), column_type(column1)}
{}

template <typename T>
template <typename U0, typename U1>
inline constexpr matrix<2, 3, T>::matrix(const vector<3, U0>& column0, const vector<3, U1>& column1)
    : m_data{column_type(column0), column_type(column1)}
{}

// clang-format off
template <typename T>
template <typename U0, typename Z0,
          typename U1, typename Z1>
inline constexpr matrix<2, 3, T>::matrix(const vector<2, U0>& vector0, const Z0& z0,
                                         const vector<2, U1>& vector1, const Z1& z1)
    : m_data{column_type(vector0, z0),
             column_type(vector1, z1)}
{
}
// clang-format on

// clang-format off
template <typename T>
template <typename X0, typename U0,
          typename X1, typename U1>
inline constexpr matrix<2, 3, T>::matrix(const X0& x0, const vector<2, U0>& vector0,
                                         const X1& x1, const vector<2, U1>& vector1)
    : m_data{column_type(x0, vector0),
             column_type(x1, vector1)}
{
}
// clang-format on

template <typename T>
template <uint32 C, uint32 R, typename U>
inline constexpr matrix<2, 3, T>::matrix(const matrix<C, R, U>& other)
    : m_data{matrix_type_details::get_column<0, C>(other, column_type(1, 0, 0)),
             matrix_type_details::get_column<1, C>(other, column_type(0, 1, 0))}
{}
/// @}

/// @name matrix<2, 3, T> operators.
/// @{
template <typename T>
inline typename matrix<2, 3, T>::column_type& matrix<2, 3, T>::operator[](uint32 index)
{
    assert(index < 2);
    return m_data[index];
}

template <typename T>
inline const typename matrix<2, 3, T>::column_type& matrix<2, 3, T>::operator[](uint32 index) const
{
    assert(index < 2);
    return m_data[index];
}
/// @}

/// @name matrix<2, 3, T> methods.
/// @{
template <typename T>
inline constexpr uint32 matrix<2, 3, T>::size() const noexcept
{
    return 2;
}

template <typename T>
inline typename matrix<2, 3, T>::value_type* matrix<2, 3, T>::data() noexcept
{
    return m_data[0].data();
}

template <typename T>
const typename matrix<2, 3, T>::value_type* matrix<2, 3, T>::data() const noexcept
{
    return m_data[0].data();
}

template <typename T>
inline typename matrix<2, 3, T>::column_type matrix<2, 3, T>::column(uint32 index) const noexcept
{
    assert(index < 2);
    return m_data[index];
}

template <typename T>
inline typename matrix<2, 3, T>::row_type matrix<2, 3, T>::row(uint32 index) const noexcept
{
    assert(index < 3);
    return matrix<2, 3, T>::row_type(m_data[0][index], m_data[1][index]);
}
/// @}

/// @name matrix<2, 2, T> constructors.
/// @{
template <typename T>
inline constexpr matrix<2, 2, T>::matrix() noexcept : matrix(T{1})
{}

// clang-format off
template <typename T>
inline constexpr matrix<2, 2, T>::matrix(const T& value00, const T& value01,
                                         const T& value10, const T& value11)
    : m_data{column_type(value00, value01),
             column_type(value10, value11)}
{
}
// clang-format on

// clang-format off
template <typename T>
inline constexpr matrix<2, 2, T>::matrix(const T& value) noexcept
    : m_data{column_type(value, 0),
             column_type(0, value)}
{
}
// clang-format on

template <typename T>
template <typename U>
inline matrix<2, 2, T>::matrix(const U* pointer) : m_data{column_type(pointer), column_type(pointer + 2)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

template <typename T>
template <typename U>
inline matrix<2, 2, T>::matrix(U* pointer) : m_data{column_type(pointer), column_type(pointer + 2)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

template <typename T>
template <typename U0, typename U1>
inline constexpr matrix<2, 2, T>::matrix(const vector<4, U0>& column0, const vector<4, U1>& column1)
    : m_data{column_type(column0), column_type(column1)}
{}

template <typename T>
template <typename U0, typename U1>
inline constexpr matrix<2, 2, T>::matrix(const vector<3, U0>& column0, const vector<3, U1>& column1)
    : m_data{column_type(column0), column_type(column1)}
{}

template <typename T>
template <typename U0, typename U1>
inline constexpr matrix<2, 2, T>::matrix(const vector<2, U0>& column0, const vector<2, U1>& column1)
    : m_data{column_type(column0), column_type(column1)}
{}

template <typename T>
template <uint32 C, uint32 R, typename U>
inline constexpr matrix<2, 2, T>::matrix(const matrix<C, R, U>& other)
    : m_data{static_cast<column_type>(other[0]), static_cast<column_type>(other[1])}
{}
/// @}

/// @name matrix<2, 2, T> operators.
/// @{
template <typename T>
inline typename matrix<2, 2, T>::column_type& matrix<2, 2, T>::operator[](uint32 index)
{
    assert(index < 2);
    return m_data[index];
}

template <typename T>
inline const typename matrix<2, 2, T>::column_type& matrix<2, 2, T>::operator[](uint32 index) const
{
    assert(index < 2);
    return m_data[index];
}
/// @}

/// @name matrix<2, 2, T> methods.
/// @{
template <typename T>
inline constexpr uint32 matrix<2, 2, T>::size() const noexcept
{
    return 2;
}

template <typename T>
inline typename matrix<2, 2, T>::value_type* matrix<2, 2, T>::data() noexcept
{
    return m_data[0].data();
}

template <typename T>
const typename matrix<2, 2, T>::value_type* matrix<2, 2, T>::data() const noexcept
{
    return m_data[0].data();
}

template <typename T>
inline typename matrix<2, 2, T>::column_type matrix<2, 2, T>::column(uint32 index) const noexcept
{
    assert(index < 2);
    return m_data[index];
}

template <typename T>
inline typename matrix<2, 2, T>::row_type matrix<2, 2, T>::row(uint32 index) const noexcept
{
    assert(index < 2);
    return matrix<2, 2, T>::row_type(m_data[0][index], m_data[1][index]);
}
/// @}

/// @name Matrix operators and functions.
/// @addtogroup math_matrix_implementation
/// @{

/// @name Matrix unary operators.
/// @{

/// @brief Unary plus operator.
///
/// @param matrix Matrix to return.
///
/// @return The same matrix.
template <uint32 C, uint32 R, typename T>
inline matrix<C, R, T> operator+(const matrix<C, R, T>& matrix)
{
    return matrix;
}

/// @brief Unary minus operator.
///
/// @param matrix Matrix to invert.
///
/// @return Matrix witch is equal to `matrix * -1`.
template <uint32 C, uint32 R, typename T>
inline matrix<C, R, T> operator-(matrix<C, R, T> matrix)
{
    return matrix *= -T{1};
}

/// @brief Addition assignment operator.
///
/// @param lhs First addend.
/// @param rhs Second addend.
///
/// @return Reference to component-wise sum of two matrices.
template <uint32 C, uint32 R, typename T, typename U>
inline matrix<C, R, T>& operator+=(matrix<C, R, T>& lhs, const matrix<C, R, U>& rhs)
{
    for (uint32 i = 0; i < C; ++i) {
        lhs[i] += rhs[i];
    }
    return lhs;
}

/// @brief Subtractions assignment operator.
///
/// @param lhs Vector to subtract from.
/// @param rhs Vector to subtract.
///
/// @return Reference to component-wise difference of two matrices.
template <uint32 C, uint32 R, typename T, typename U>
inline matrix<C, R, T>& operator-=(matrix<C, R, T>& lhs, const matrix<C, R, U>& rhs)
{
    for (uint32 i = 0; i < C; ++i) {
        lhs[i] -= rhs[i];
    }
    return lhs;
}

/// @brief Multiplication assignment operator.
///
/// @param lhs First multiplier.
/// @param rhs Second multiplier.
///
/// @return Reference to product of two matrices.
template <uint32 C, uint32 R, typename T, typename U>
inline matrix<C, R, T>& operator*=(matrix<C, R, T>& lhs, const matrix<C, C, U>& rhs)
{
    return (lhs = lhs * rhs);
}

/// @brief Addition assignment operator.
///
/// @param lhs First addend.
/// @param rhs Second addend.
///
/// @return Reference to component-wise sum of matrix and scalar value.
template <uint32 C,
          uint32 R,
          typename T,
          typename U,
          typename std::enable_if<std::is_arithmetic<U>::value, int32>::type = 0>
inline matrix<C, R, T>& operator+=(matrix<C, R, T>& lhs, const U& rhs)
{
    for (uint32 i = 0; i < C; ++i) {
        lhs[i] += rhs;
    }
    return lhs;
}

/// @brief Subtractions assignment operator.
///
/// @param lhs Vector to subtract from.
/// @param rhs Scalar value to subtract.
///
/// @return Reference to component-wise difference of the matrix and scalar value.
template <uint32 C,
          uint32 R,
          typename T,
          typename U,
          typename std::enable_if<std::is_arithmetic<U>::value, int32>::type = 0>
inline matrix<C, R, T>& operator-=(matrix<C, R, T>& lhs, const U& rhs)
{
    for (uint32 i = 0; i < C; ++i) {
        lhs[i] -= rhs;
    }
    return lhs;
}

/// @brief Multiplication assignment operator.
///
/// @param lhs First multiplier.
/// @param rhs Second multiplier.
///
/// @return Reference to component-wise product of the matrix and scalar value.
template <uint32 C,
          uint32 R,
          typename T,
          typename U,
          typename std::enable_if<std::is_arithmetic<U>::value, int32>::type = 0>
inline matrix<C, R, T>& operator*=(matrix<C, R, T>& lhs, const U& rhs)
{
    for (uint32 i = 0; i < C; ++i) {
        lhs[i] *= rhs;
    }
    return lhs;
}

/// @brief Division assignment operator.
///
/// @param lhs Dividend vector.
/// @param rhs Divider scalar value.
///
/// @return Reference to component-wise quotient of the matrix and scalar value.
template <uint32 C,
          uint32 R,
          typename T,
          typename U,
          typename std::enable_if<std::is_arithmetic<U>::value, int32>::type = 0>
inline matrix<C, R, T>& operator/=(matrix<C, R, T>& lhs, const U& rhs)
{
    for (uint32 i = 0; i < C; ++i) {
        lhs[i] /= rhs;
    }
    return lhs;
}
/// @}

/// @name Common binary operator for matrices.
/// @{

/// @brief Addition operator.
///
/// @param lhs First addend.
/// @param rhs Second addend.
///
/// @return Component-wise sum of two matrices.
template <uint32 C, uint32 R, typename T, typename U, typename RT = typename matrix_type_details::common_type<T, U>::type>
inline const matrix<C, R, RT> operator+(const matrix<C, R, T>& lhs, const matrix<C, R, U>& rhs) noexcept
{
    matrix<C, R, RT> temp{lhs};
    return temp += rhs;
}

/// @brief Subtraction operator.
///
/// @param lhs Vector to subtract from.
/// @param rhs Scalar value to subtract.
///
/// @return Component-wise difference of two matrices.
template <uint32 C, uint32 R, typename T, typename U, typename RT = typename matrix_type_details::common_type<T, U>::type>
inline const matrix<C, R, RT> operator-(const matrix<C, R, T>& lhs, const matrix<C, R, U>& rhs) noexcept
{
    matrix<C, R, RT> temp{lhs};
    return temp -= rhs;
}

/// @brief Multiplication operator.
///
/// @param lhs Matrix of floating-point or integral type.
/// @param rhs Matrix of floating-point or integral type.
///
/// @return Product of two matrices.
template <uint32 C,
          uint32 R,
          uint32 N,
          typename T,
          typename U,
          typename RT = typename matrix_type_details::common_type<T, U>::type>
inline const matrix<N, R, RT> operator*(const matrix<C, R, T>& lhs, const matrix<N, C, U>& rhs) noexcept
{
    matrix<N, R, RT> temp(0);

    for (uint32 n = 0; n < N; ++n) {
        for (uint32 c = 0; c < C; ++c) {
            for (uint32 r = 0; r < R; ++r) {
                temp[n][r] += lhs[c][r] * rhs[n][c];
            }
        }
    }

    return temp;
}

/// @brief Multiplication operator.
///
/// @param lhs Vector of floating-point or integral type.
/// @param rhs Matrix of floating-point or integral type.
///
/// @return Product of vector and matrix.
template <uint32 C, uint32 R, typename T, typename U, typename RT = typename matrix_type_details::common_type<T, U>::type>
inline const vector<C, RT> operator*(const vector<R, T>& lhs, const matrix<C, R, U>& rhs) noexcept
{
    vector<C, RT> temp(0);

    for (uint32 c = 0; c < C; ++c) {
        for (uint32 r = 0; r < R; ++r) {
            temp[c] += lhs[r] * rhs[c][r];
        }
    }

    return temp;
}

/// @brief Multiplication operator.
///
/// @param lhs Matrix of floating-point or integral type.
/// @param rhs Vector of floating-point or integral type.
///
/// @return Product of vector and matrix.
template <uint32 C, uint32 R, typename T, typename U, typename RT = typename matrix_type_details::common_type<T, U>::type>
inline const vector<R, RT> operator*(const matrix<C, R, T>& lhs, const vector<C, U>& rhs) noexcept
{
    vector<R, RT> temp(0);

    for (uint32 r = 0; r < R; ++r) {
        for (uint32 c = 0; c < C; ++c) {
            temp[r] += lhs[c][r] * rhs[c];
        }
    }

    return temp;
}
/// @}

/// @name Common binary operators with matrices and scalar values.
/// @{

/// @brief Addition operator.
///
/// @param lhs Matrix of floating-point or integral type.
/// @param rhs Value of floating-point or integral type.
///
/// @return Component-wise sum of matrix and scalar value.
template <uint32 C, uint32 R, typename T, typename U, typename RT = typename matrix_type_details::common_type<T, U>::type>
inline const matrix<C, R, RT> operator+(const matrix<C, R, T>& lhs, const U& rhs) noexcept
{
    matrix<C, R, RT> temp{lhs};
    return temp += rhs;
}

/// @brief Subtractions operator.
///
/// @param lhs Matrix of floating-point or integral type.
/// @param rhs Value of floating-point or integral type.
///
/// @return Component-wise difference of matrix and scalar value.
template <uint32 C, uint32 R, typename T, typename U, typename RT = typename matrix_type_details::common_type<T, U>::type>
inline const matrix<C, R, RT> operator-(const matrix<C, R, T>& lhs, const U& rhs) noexcept
{
    matrix<C, R, RT> temp{lhs};
    return temp -= rhs;
}

/// @brief Multiplication operator.
///
/// @param lhs Matrix of floating-point or integral type.
/// @param rhs Value of floating-point or integral type.
///
/// @return Component-wise product of matrix and scalar value.
template <uint32 C, uint32 R, typename T, typename U, typename RT = typename matrix_type_details::common_type<T, U>::type>
inline const matrix<C, R, RT> operator*(const matrix<C, R, T>& lhs, const U& rhs) noexcept
{
    matrix<C, R, RT> temp{lhs};
    return temp *= rhs;
}

/// @brief Division operator.
///
/// @param lhs Matrix of floating-point or integral type.
/// @param rhs Value of floating-point or integral type.
///
/// @return Component-wise quotient of matrix and scalar value.
template <uint32 C, uint32 R, typename T, typename U, typename RT = typename matrix_type_details::common_type<T, U>::type>
inline const matrix<C, R, RT> operator/(const matrix<C, R, T>& lhs, const U& rhs) noexcept
{
    matrix<C, R, RT> temp{lhs};
    return temp /= rhs;
}
/// @}

/// @name Common binary operators with scalar values and matrices.
/// @{

/// @brief Addition operator.
///
/// @param lhs Value of floating-point or integral type.
/// @param rhs Matrix of floating-point or integral type.
///
/// @return Component-wise sum of matrix and scalar value.
template <uint32 C, uint32 R, typename T, typename U, typename RT = typename matrix_type_details::common_type<T, U>::type>
inline const matrix<C, R, RT> operator+(const T& lhs, const matrix<C, R, U>& rhs) noexcept
{
    matrix<C, R, RT> temp{0};

    for (uint32 i = 0; i < C; ++i) {
        temp[i] = lhs + rhs[i];
    }

    return temp;
}

/// @brief Subtractions operator.
///
/// @param lhs Value of floating-point or integral type.
/// @param rhs Matrix of floating-point or integral type.
///
/// @return Component-wise difference of matrix and scalar value.
template <uint32 C, uint32 R, typename T, typename U, typename RT = typename matrix_type_details::common_type<T, U>::type>
inline const matrix<C, R, RT> operator-(const T& lhs, const matrix<C, R, U>& rhs) noexcept
{
    matrix<C, R, RT> temp{0};

    for (uint32 i = 0; i < C; ++i) {
        temp[i] = lhs - rhs[i];
    }

    return temp;
}

/// @brief Multiplication operator.
///
/// @param lhs Value of floating-point or integral type.
/// @param rhs Matrix of floating-point or integral type.
///
/// @return Component-wise product of matrix and scalar value.
template <uint32 C, uint32 R, typename T, typename U, typename RT = typename matrix_type_details::common_type<T, U>::type>
inline const matrix<C, R, RT> operator*(const T& lhs, const matrix<C, R, U>& rhs) noexcept
{
    matrix<C, R, RT> temp{0};

    for (uint32 i = 0; i < C; ++i) {
        temp[i] = lhs * rhs[i];
    }

    return temp;
}

/// @brief Division operator.
///
/// @param lhs Value of floating-point or integral type.
/// @param rhs Matrix of floating-point or integral type.
///
/// @return Component-wise quotient of matrix and scalar value.
template <uint32 C, uint32 R, typename T, typename U, typename RT = typename matrix_type_details::common_type<T, U>::type>
inline const matrix<C, R, RT> operator/(const T& lhs, const matrix<C, R, U>& rhs) noexcept
{
    matrix<C, R, RT> temp{0};

    for (uint32 i = 0; i < C; ++i) {
        temp[i] = lhs / rhs[i];
    }

    return temp;
}
/// @}

/// @name Matrix equality operators.
/// @{

/// @brief Equality operator.
///
/// @param lhs Matrix of floating-point or integral type.
/// @param rhs Matrix of floating-point or integral type.
///
/// @return `true` if lhs equals rhs, otherwise `false`.
template <uint32 R, typename T>
inline constexpr bool operator==(const matrix<4, R, T>& lhs, const matrix<4, R, T>& rhs)
{
    return lhs[0] == rhs[0] && lhs[1] == rhs[1] && lhs[2] == rhs[2] && lhs[3] == rhs[3];
}

/// @brief Equality operator.
///
/// @param lhs Matrix of floating-point or integral type.
/// @param rhs Matrix of floating-point or integral type.
///
/// @return `true` if lhs equals rhs, otherwise `false`.
template <uint32 R, typename T>
inline constexpr bool operator==(const matrix<3, R, T>& lhs, const matrix<3, R, T>& rhs)
{
    return lhs[0] == rhs[0] && lhs[1] == rhs[1] && lhs[2] == rhs[2];
}

/// @brief Equality operator.
///
/// @param lhs Matrix of floating-point or integral type.
/// @param rhs Matrix of floating-point or integral type.
///
/// @return `true` if lhs equals rhs, otherwise `false`.
template <uint32 R, typename T>
inline constexpr bool operator==(const matrix<2, R, T>& lhs, const matrix<2, R, T>& rhs)
{
    return lhs[0] == rhs[0] && lhs[1] == rhs[1];
}

/// @brief Equality operator.
///
/// @param lhs Matrix of floating-point or integral type.
/// @param rhs Matrix of floating-point or integral type.
///
/// @return `true` if lhs isn't equal rhs, otherwise `false`.
template <uint32 R, typename T>
inline constexpr bool operator!=(const matrix<4, R, T>& lhs, const matrix<4, R, T>& rhs)
{
    return (lhs[0] != rhs[0]) || (lhs[1] != rhs[1]) || (lhs[2] != rhs[2]) || (lhs[3] != rhs[3]);
}

/// @brief Equality operator.
///
/// @param lhs Matrix of floating-point or integral type.
/// @param rhs Matrix of floating-point or integral type.
///
/// @return `true` if lhs isn't equal rhs, otherwise `false`.
template <uint32 R, typename T>
inline constexpr bool operator!=(const matrix<3, R, T>& lhs, const matrix<3, R, T>& rhs)
{
    return (lhs[0] != rhs[0]) || (lhs[1] != rhs[1]) || (lhs[2] != rhs[2]);
}

/// @brief Equality operator.
///
/// @param lhs Matrix of floating-point or integral type.
/// @param rhs Matrix of floating-point or integral type.
///
/// @return `true` if lhs isn't equal rhs, otherwise `false`.
template <uint32 R, typename T>
inline constexpr bool operator!=(const matrix<2, R, T>& lhs, const matrix<2, R, T>& rhs)
{
    return (lhs[0] != rhs[0]) || (lhs[1] != rhs[1]);
}
/// @}

/// @}

} // namespace math

} // namespace framework

#endif
