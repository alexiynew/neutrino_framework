////////////////////////////////////////////////////////////////////////////////
/// @file
/// @brief Implementation of Matrix type.
/// @author Fedorov Alexey
/// @date 11.07.2017
////////////////////////////////////////////////////////////////////////////////

// =============================================================================
// MIT License
//
// Copyright (c) 2017-2021 Fedorov Alexey
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

    #include <math/inc/matrix_type_details.hpp>
    #include <math/inc/vector_type.hpp>

namespace framework::math
{
////////////////////////////////////////////////////////////////////////////////
/// @addtogroup math_matrix_implementation
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief Matrix template declaration.
///
/// @see Matrix<4, 4, T>, Matrix<4, 3, T>, Matrix<4, 2, T>,
///      Matrix<3, 4, T>, Matrix<3, 3, T>, Matrix<3, 2, T>,
///      Matrix<2, 4, T>, Matrix<2, 3, T>, Matrix<2, 2, T>
////////////////////////////////////////////////////////////////////////////////
template <std::size_t C, std::size_t R, typename T>
struct Matrix;

////////////////////////////////////////////////////////////////////////////////
/// @brief Matrix<4, 4, T> type specialization.
///
/// @note Can be instantiated only with arithmetic type.
////////////////////////////////////////////////////////////////////////////////
template <typename T>
struct Matrix<4, 4, T> final
{
    static_assert(std::is_arithmetic_v<T>, "Expected floating-point or integer type.");

    using ValueType  = T;            ///< Value type
    using ColumnType = Vector<4, T>; ///< Column type
    using RowType    = Vector<4, T>; ///< Row type

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Default constructor.
    ///
    /// Creates an identity Matrix.
    ////////////////////////////////////////////////////////////////////////////
    constexpr Matrix() noexcept;

    ////////////////////////////////////////////////////////////////////////////
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
    ////////////////////////////////////////////////////////////////////////////

    // clang-format off
    constexpr Matrix(const T& value00, const T& value01, const T& value02, const T& value03,
                     const T& value10, const T& value11, const T& value12, const T& value13,
                     const T& value20, const T& value21, const T& value22, const T& value23,
                     const T& value30, const T& value31, const T& value32, const T& value33);
    // clang-format on

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initialize the main diagonal of Matrix with provided value.
    ///
    /// @param value Floating-point or integral value.
    ////////////////////////////////////////////////////////////////////////////
    explicit constexpr Matrix(const T& value) noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes all components of Matrix from pointer to values.
    ///
    /// @param pointer Const pointer to values that should be taken.
    ///
    /// @warning May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    template <typename U>
    explicit Matrix(const U* pointer);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes all components of Matrix from pointer to values.
    ///
    /// @param pointer Pointer to values that should be taken.
    ///
    /// @warning May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    template <typename U>
    explicit Matrix(U* pointer);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes matrices with provided vectors.
    ///
    /// @param column0 Vector for first column.
    /// @param column1 Vector for second column.
    /// @param column2 Vector for third column.
    /// @param column3 Vector for fourth column.
    ////////////////////////////////////////////////////////////////////////////
    template <typename U0, typename U1, typename U2, typename U3>
    constexpr Matrix(const Vector<4, U0>& column0,
                     const Vector<4, U1>& column1,
                     const Vector<4, U2>& column2,
                     const Vector<4, U3>& column3);

    ////////////////////////////////////////////////////////////////////////////
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
    ////////////////////////////////////////////////////////////////////////////

    // clang-format off
    template <typename U0, typename W0,
              typename U1, typename W1,
              typename U2, typename W2,
              typename U3, typename W3>
    constexpr Matrix(const Vector<3, U0>& vector0, const W0& w0,
                     const Vector<3, U1>& vector1, const W1& w1,
                     const Vector<3, U2>& vector2, const W2& w2,
                     const Vector<3, U3>& vector3, const W3& w3);
    // clang-format on

    ////////////////////////////////////////////////////////////////////////////
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
    ////////////////////////////////////////////////////////////////////////////

    // clang-format off
    template <typename X0, typename U0,
              typename X1, typename U1,
              typename X2, typename U2,
              typename X3, typename U3>
    constexpr Matrix(const X0& x0, const Vector<3, U0>& vector0,
                     const X1& x1, const Vector<3, U1>& vector1,
                     const X2& x2, const Vector<3, U2>& vector2,
                     const X3& x3, const Vector<3, U3>& vector3);
    // clang-format on

    ////////////////////////////////////////////////////////////////////////////
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
    ////////////////////////////////////////////////////////////////////////////

    // clang-format off
    template <typename U00, typename U01,
              typename U10, typename U11,
              typename U20, typename U21,
              typename U30, typename U31>
    constexpr Matrix(const Vector<2, U00>& vector00, const Vector<2, U01>& vector01,
                     const Vector<2, U10>& vector10, const Vector<2, U11>& vector11,
                     const Vector<2, U20>& vector20, const Vector<2, U21>& vector21,
                     const Vector<2, U30>& vector30, const Vector<2, U31>& vector31);
    // clang-format on

    ////////////////////////////////////////////////////////////////////////////
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
    ////////////////////////////////////////////////////////////////////////////

    // clang-format off
    template <typename U0, typename Z0, typename W0,
              typename U1, typename Z1, typename W1,
              typename U2, typename Z2, typename W2,
              typename U3, typename Z3, typename W3>
    constexpr Matrix(const Vector<2, U0>& vector0, const Z0& z0, const W0& w0,
                     const Vector<2, U1>& vector1, const Z1& z1, const W1& w1,
                     const Vector<2, U2>& vector2, const Z2& z2, const W2& w2,
                     const Vector<2, U3>& vector3, const Z3& z3, const W3& w3);
    // clang-format on

    ////////////////////////////////////////////////////////////////////////////
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
    ////////////////////////////////////////////////////////////////////////////

    // clang-format off
    template <typename X0, typename U0, typename W0,
              typename X1, typename U1, typename W1,
              typename X2, typename U2, typename W2,
              typename X3, typename U3, typename W3>
    constexpr Matrix(const X0& x0, const Vector<2, U0>& vector0, const W0& w0,
                     const X1& x1, const Vector<2, U1>& vector1, const W1& w1,
                     const X2& x2, const Vector<2, U2>& vector2, const W2& w2,
                     const X3& x3, const Vector<2, U3>& vector3, const W3& w3);
    // clang-format on

    ////////////////////////////////////////////////////////////////////////////
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
    ////////////////////////////////////////////////////////////////////////////

    // clang-format off
    template <typename X0, typename Y0, typename U0,
              typename X1, typename Y1, typename U1,
              typename X2, typename Y2, typename U2,
              typename X3, typename Y3, typename U3>
    constexpr Matrix(const X0& x0, const Y0& y0, const Vector<2, U0>& vector0,
                     const X1& x1, const Y1& y1, const Vector<2, U1>& vector1,
                     const X2& x2, const Y2& y2, const Vector<2, U2>& vector2,
                     const X3& x3, const Y3& y3, const Vector<2, U3>& vector3);
    // clang-format on

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes Matrix from another one.
    ///
    /// @param other Matrix of integral or floating-point type.
    ///
    /// @note The remain components will be initialized as in identity Matrix.
    ////////////////////////////////////////////////////////////////////////////
    template <std::size_t C, std::size_t R, typename U>
    explicit constexpr Matrix(const Matrix<C, R, U>& other);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Access operator.
    ///
    /// @param index Index of column.
    ///
    /// @return Reference to column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    ColumnType& operator[](std::size_t index);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Const access operator.
    ///
    /// @param index Index of column.
    ///
    /// @return Reference to constant column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    const ColumnType& operator[](std::size_t index) const;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Size of Matrix.
    ///
    /// @return Count of columns in Matrix.
    ////////////////////////////////////////////////////////////////////////////
    constexpr std::size_t size() const noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the x component of first column.
    ////////////////////////////////////////////////////////////////////////////
    ValueType* data() noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the x component of first column.
    ////////////////////////////////////////////////////////////////////////////
    const ValueType* data() const noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Provides access to columns of the Matrix.
    ///
    /// @param index Index of column.
    ///
    /// @return Copy of column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    ColumnType column(std::size_t index) const noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Provides access to rows of the Matrix.
    ///
    /// @param index Index of row.
    ///
    /// @return Copy of row at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    RowType row(std::size_t index) const noexcept;

private:
    ColumnType m_data[4];
};

////////////////////////////////////////////////////////////////////////////////
/// @brief Matrix<4, 3, T> type specialization.
///
/// @note Can be instantiated only with arithmetic type.
////////////////////////////////////////////////////////////////////////////////
template <typename T>
struct Matrix<4, 3, T> final
{
    static_assert(std::is_arithmetic_v<T>, "Expected floating-point or integer type.");

    using ValueType  = T;            ///< Value type
    using ColumnType = Vector<3, T>; ///< Column type
    using RowType    = Vector<4, T>; ///< Row type

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Default constructor.
    ///
    /// Creates an identity Matrix.
    ////////////////////////////////////////////////////////////////////////////
    constexpr Matrix() noexcept;

    ////////////////////////////////////////////////////////////////////////////
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
    ////////////////////////////////////////////////////////////////////////////

    // clang-format off
    constexpr Matrix(const T& value00, const T& value01, const T& value02,
                     const T& value10, const T& value11, const T& value12,
                     const T& value20, const T& value21, const T& value22,
                     const T& value30, const T& value31, const T& value32);
    // clang-format on

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initialize the main diagonal of Matrix with provided value.
    ///
    /// @param value Floating-point or integral value.
    ////////////////////////////////////////////////////////////////////////////
    explicit constexpr Matrix(const T& value) noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes all components of Matrix from pointer to values.
    ///
    /// @param pointer Const pointer to values that should be taken.
    ///
    /// @warning May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    template <typename U>
    explicit Matrix(const U* pointer);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes all components of Matrix from pointer to values.
    ///
    /// @param pointer Pointer to values that should be taken.
    ///
    /// @warning May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    template <typename U>
    explicit Matrix(U* pointer);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes matrices with provided vectors.
    ///
    /// @param column0 Vector for first column.
    /// @param column1 Vector for second column.
    /// @param column2 Vector for third column.
    /// @param column3 Vector for fourth column.
    ////////////////////////////////////////////////////////////////////////////
    template <typename U0, typename U1, typename U2, typename U3>
    constexpr Matrix(const Vector<4, U0>& column0,
                     const Vector<4, U1>& column1,
                     const Vector<4, U2>& column2,
                     const Vector<4, U3>& column3);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes matrices with provided vectors.
    ///
    /// @param column0 Vector for first column.
    /// @param column1 Vector for second column.
    /// @param column2 Vector for third column.
    /// @param column3 Vector for fourth column.
    ////////////////////////////////////////////////////////////////////////////
    template <typename U0, typename U1, typename U2, typename U3>
    constexpr Matrix(const Vector<3, U0>& column0,
                     const Vector<3, U1>& column1,
                     const Vector<3, U2>& column2,
                     const Vector<3, U3>& column3);

    ////////////////////////////////////////////////////////////////////////////
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
    ////////////////////////////////////////////////////////////////////////////

    // clang-format off
    template <typename U0, typename Z0,
              typename U1, typename Z1,
              typename U2, typename Z2,
              typename U3, typename Z3>
    constexpr Matrix(const Vector<2, U0>& vector0, const Z0& z0,
                     const Vector<2, U1>& vector1, const Z1& z1,
                     const Vector<2, U2>& vector2, const Z2& z2,
                     const Vector<2, U3>& vector3, const Z3& z3);
    // clang-format on

    ////////////////////////////////////////////////////////////////////////////
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
    ////////////////////////////////////////////////////////////////////////////

    // clang-format off
    template <typename X0, typename U0,
              typename X1, typename U1,
              typename X2, typename U2,
              typename X3, typename U3>
    constexpr Matrix(const X0& x0, const Vector<2, U0>& vector0,
                     const X1& x1, const Vector<2, U1>& vector1,
                     const X2& x2, const Vector<2, U2>& vector2,
                     const X3& x3, const Vector<2, U3>& vector3);
    // clang-format on

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes Matrix from another one.
    ///
    /// @param other Matrix of integral or floating-point type.
    ///
    /// @note The remain components will be initialized as in identity Matrix.
    ////////////////////////////////////////////////////////////////////////////
    template <std::size_t C, std::size_t R, typename U>
    explicit constexpr Matrix(const Matrix<C, R, U>& other);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Access operator.
    ///
    /// @param index Index of column.
    ///
    /// @return Reference to column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    ColumnType& operator[](std::size_t index);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Const access operator.
    ///
    /// @param index Index of column.
    ///
    /// @return Reference to constant column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    const ColumnType& operator[](std::size_t index) const;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Size of Matrix.
    ///
    /// @return Count of columns in Matrix.
    ////////////////////////////////////////////////////////////////////////////
    constexpr std::size_t size() const noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the x component of first column.
    ////////////////////////////////////////////////////////////////////////////
    ValueType* data() noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the x component of first column.
    ////////////////////////////////////////////////////////////////////////////
    const ValueType* data() const noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Provides access to columns of the Matrix.
    ///
    /// @param index Index of column.
    ///
    /// @return Copy of column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    ColumnType column(std::size_t index) const noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Provides access to rows of the Matrix.
    ///
    /// @param index Index of row.
    ///
    /// @return Copy of row at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    RowType row(std::size_t index) const noexcept;

private:
    ColumnType m_data[4];
};

////////////////////////////////////////////////////////////////////////////////
/// @brief Matrix<4, 2, T> type specialization.
///
/// @note Can be instantiated only with arithmetic type.
////////////////////////////////////////////////////////////////////////////////
template <typename T>
struct Matrix<4, 2, T> final
{
    static_assert(std::is_arithmetic_v<T>, "Expected floating-point or integer type.");

    using ValueType  = T;            ///< Value type
    using ColumnType = Vector<2, T>; ///< Column type
    using RowType    = Vector<4, T>; ///< Row type

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Default constructor.
    ///
    /// Creates an identity Matrix.
    ////////////////////////////////////////////////////////////////////////////
    constexpr Matrix() noexcept;

    ////////////////////////////////////////////////////////////////////////////
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
    ////////////////////////////////////////////////////////////////////////////

    // clang-format off
    constexpr Matrix(const T& value00, const T& value01,
                     const T& value10, const T& value11,
                     const T& value20, const T& value21,
                     const T& value30, const T& value31);
    // clang-format on

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initialize the main diagonal of Matrix with provided value.
    ///
    /// @param value Floating-point or integral value.
    ////////////////////////////////////////////////////////////////////////////
    explicit constexpr Matrix(const T& value) noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes all components of Matrix from pointer to values.
    ///
    /// @param pointer Const pointer to values that should be taken.
    ///
    /// @warning May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    template <typename U>
    explicit Matrix(const U* pointer);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes all components of Matrix from pointer to values.
    ///
    /// @param pointer Pointer to values that should be taken.
    ///
    /// @warning May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    template <typename U>
    explicit Matrix(U* pointer);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes matrices with provided vectors.
    ///
    /// @param column0 Vector for first column.
    /// @param column1 Vector for second column.
    /// @param column2 Vector for third column.
    /// @param column3 Vector for fourth column.
    ////////////////////////////////////////////////////////////////////////////
    template <typename U0, typename U1, typename U2, typename U3>
    constexpr Matrix(const Vector<4, U0>& column0,
                     const Vector<4, U1>& column1,
                     const Vector<4, U2>& column2,
                     const Vector<4, U3>& column3);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes matrices with provided vectors.
    ///
    /// @param column0 Vector for first column.
    /// @param column1 Vector for second column.
    /// @param column2 Vector for third column.
    /// @param column3 Vector for fourth column.
    ////////////////////////////////////////////////////////////////////////////
    template <typename U0, typename U1, typename U2, typename U3>
    constexpr Matrix(const Vector<3, U0>& column0,
                     const Vector<3, U1>& column1,
                     const Vector<3, U2>& column2,
                     const Vector<3, U3>& column3);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes matrices with provided vectors.
    ///
    /// @param column0 Vector for first column.
    /// @param column1 Vector for second column.
    /// @param column2 Vector for third column.
    /// @param column3 Vector for fourth column.
    ////////////////////////////////////////////////////////////////////////////

    // clang-format off
    template <typename U0,
              typename U1,
              typename U2,
              typename U3>
    constexpr Matrix(const Vector<2, U0>& column0,
                     const Vector<2, U1>& column1,
                     const Vector<2, U2>& column2,
                     const Vector<2, U3>& column3);
    // clang-format on

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes Matrix from another one.
    ///
    /// @param other Matrix of integral or floating-point type.
    ///
    /// @note The remain components will be initialized as in identity Matrix.
    ////////////////////////////////////////////////////////////////////////////
    template <std::size_t C, std::size_t R, typename U>
    explicit constexpr Matrix(const Matrix<C, R, U>& other);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Access operator.
    ///
    /// @param index Index of column.
    ///
    /// @return Reference to column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    ColumnType& operator[](std::size_t index);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Const access operator.
    ///
    /// @param index Index of column.
    ///
    /// @return Reference to constant column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    const ColumnType& operator[](std::size_t index) const;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Size of Matrix.
    ///
    /// @return Count of columns in Matrix.
    ////////////////////////////////////////////////////////////////////////////
    constexpr std::size_t size() const noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the x component of first column.
    ////////////////////////////////////////////////////////////////////////////
    ValueType* data() noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the x component of first column.
    ////////////////////////////////////////////////////////////////////////////
    const ValueType* data() const noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Provides access to columns of the Matrix.
    ///
    /// @param index Index of column.
    ///
    /// @return Copy of column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    ColumnType column(std::size_t index) const noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Provides access to rows of the Matrix.
    ///
    /// @param index Index of row.
    ///
    /// @return Copy of row at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    RowType row(std::size_t index) const noexcept;

private:
    ColumnType m_data[4];
};

////////////////////////////////////////////////////////////////////////////////
/// @brief Matrix<3, 4, T> type specialization.
///
/// @note Can be instantiated only with arithmetic type.
////////////////////////////////////////////////////////////////////////////////
template <typename T>
struct Matrix<3, 4, T> final
{
    static_assert(std::is_arithmetic_v<T>, "Expected floating-point or integer type.");

    using ValueType  = T;            ///< Value type
    using ColumnType = Vector<4, T>; ///< Column type
    using RowType    = Vector<3, T>; ///< Row type

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Default constructor.
    ///
    /// Creates an identity Matrix.
    ////////////////////////////////////////////////////////////////////////////
    constexpr Matrix() noexcept;

    ////////////////////////////////////////////////////////////////////////////
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
    ////////////////////////////////////////////////////////////////////////////

    // clang-format off
    constexpr Matrix(const T& value00, const T& value01, const T& value02, const T& value03,
                     const T& value10, const T& value11, const T& value12, const T& value13,
                     const T& value20, const T& value21, const T& value22, const T& value23);
    // clang-format on

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initialize the main diagonal of Matrix with provided value.
    ///
    /// @param value Floating-point or integral value.
    ////////////////////////////////////////////////////////////////////////////
    explicit constexpr Matrix(const T& value) noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes all components of Matrix from pointer to values.
    ///
    /// @param pointer Const pointer to values that should be taken.
    ///
    /// @warning May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    template <typename U>
    explicit Matrix(const U* pointer);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes all components of Matrix from pointer to values.
    ///
    /// @param pointer Pointer to values that should be taken.
    ///
    /// @warning May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    template <typename U>
    explicit Matrix(U* pointer);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes matrices with provided vectors.
    ///
    /// @param column0 Vector for first column.
    /// @param column1 Vector for second column.
    /// @param column2 Vector for third column.
    ////////////////////////////////////////////////////////////////////////////
    template <typename U0, typename U1, typename U2>
    constexpr Matrix(const Vector<4, U0>& column0, const Vector<4, U1>& column1, const Vector<4, U2>& column2);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes matrices with provided vectors and scalar values.
    ///
    /// @param vector0 First part for first column.
    /// @param w0 Last component for first column.
    /// @param vector1 First part for second column.
    /// @param w1 Last component for second column.
    /// @param vector2 First part for third column.
    /// @param w2 Last component for third column.
    ////////////////////////////////////////////////////////////////////////////

    // clang-format off
    template <typename U0, typename W0,
              typename U1, typename W1,
              typename U2, typename W2>
    constexpr Matrix(const Vector<3, U0>& vector0, const W0& w0,
                     const Vector<3, U1>& vector1, const W1& w1,
                     const Vector<3, U2>& vector2, const W2& w2);
    // clang-format on

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes matrices with provided scalar values and vectors.
    ///
    /// @param x0 First component for first column.
    /// @param vector0 Last part for first column.
    /// @param x1 First component for second column.
    /// @param vector1 Last part for second column.
    /// @param x2 First component for third column.
    /// @param vector2 Last part for third column.
    ////////////////////////////////////////////////////////////////////////////

    // clang-format off
    template <typename X0, typename U0,
              typename X1, typename U1,
              typename X2, typename U2>
    constexpr Matrix(const X0& x0, const Vector<3, U0>& vector0,
                     const X1& x1, const Vector<3, U1>& vector1,
                     const X2& x2, const Vector<3, U2>& vector2);
    // clang-format on

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes matrices with provided vectors and values.
    ///
    /// @param vector00 First part for first column.
    /// @param vector01 Last part for first column.
    /// @param vector10 First part for second column.
    /// @param vector11 Last part for second column.
    /// @param vector20 First part for third column.
    /// @param vector21 Last part for third column.
    ////////////////////////////////////////////////////////////////////////////

    // clang-format off
    template <typename U00, typename U01,
              typename U10, typename U11,
              typename U20, typename U21>
    constexpr Matrix(const Vector<2, U00>& vector00, const Vector<2, U01>& vector01,
                     const Vector<2, U10>& vector10, const Vector<2, U11>& vector11,
                     const Vector<2, U20>& vector20, const Vector<2, U21>& vector21);
    // clang-format on

    ////////////////////////////////////////////////////////////////////////////
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
    ////////////////////////////////////////////////////////////////////////////

    // clang-format off
    template <typename U0, typename Z0, typename W0,
              typename U1, typename Z1, typename W1,
              typename U2, typename Z2, typename W2>
    constexpr Matrix(const Vector<2, U0>& vector0, const Z0& z0, const W0& w0,
                     const Vector<2, U1>& vector1, const Z1& z1, const W1& w1,
                     const Vector<2, U2>& vector2, const Z2& z2, const W2& w2);
    // clang-format on

    ////////////////////////////////////////////////////////////////////////////
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
    ////////////////////////////////////////////////////////////////////////////

    // clang-format off
    template <typename X0, typename U0, typename W0,
              typename X1, typename U1, typename W1,
              typename X2, typename U2, typename W2>
    constexpr Matrix(const X0& x0, const Vector<2, U0>& vector0, const W0& w0,
                     const X1& x1, const Vector<2, U1>& vector1, const W1& w1,
                     const X2& x2, const Vector<2, U2>& vector2, const W2& w2);
    // clang-format on

    ////////////////////////////////////////////////////////////////////////////
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
    ////////////////////////////////////////////////////////////////////////////

    // clang-format off
    template <typename X0, typename Y0, typename U0,
              typename X1, typename Y1, typename U1,
              typename X2, typename Y2, typename U2>
    constexpr Matrix(const X0& x0, const Y0& y0, const Vector<2, U0>& vector0,
                     const X1& x1, const Y1& y1, const Vector<2, U1>& vector1,
                     const X2& x2, const Y2& y2, const Vector<2, U2>& vector2);
    // clang-format on

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes Matrix from another one.
    ///
    /// @param other Matrix of integral or floating-point type.
    ///
    /// @note The remain components will be initialized as in identity Matrix.
    ////////////////////////////////////////////////////////////////////////////
    template <std::size_t C, std::size_t R, typename U>
    explicit constexpr Matrix(const Matrix<C, R, U>& other);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Access operator.
    ///
    /// @param index Index of column.
    ///
    /// @return Reference to column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    ColumnType& operator[](std::size_t index);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Const access operator.
    ///
    /// @param index Index of column.
    ///
    /// @return Reference to constant column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    const ColumnType& operator[](std::size_t index) const;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Size of Matrix.
    ///
    /// @return Count of columns in Matrix.
    ////////////////////////////////////////////////////////////////////////////
    constexpr std::size_t size() const noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the x component of first column.
    ValueType* data() noexcept;
    ////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the x component of first column.
    ////////////////////////////////////////////////////////////////////////////
    const ValueType* data() const noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Provides access to columns of the Matrix.
    ///
    /// @param index Index of column.
    ///
    /// @return Copy of column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    ColumnType column(std::size_t index) const noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Provides access to rows of the Matrix.
    ///
    /// @param index Index of row.
    ///
    /// @return Copy of row at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    RowType row(std::size_t index) const noexcept;

private:
    ColumnType m_data[3];
};

////////////////////////////////////////////////////////////////////////////////
/// @brief Matrix<3, 3, T> type specialization.
///
/// @note Can be instantiated only with arithmetic type.
////////////////////////////////////////////////////////////////////////////////
template <typename T>
struct Matrix<3, 3, T> final
{
    static_assert(std::is_arithmetic_v<T>, "Expected floating-point or integer type.");

    using ValueType  = T;            ///< Value type
    using ColumnType = Vector<3, T>; ///< Column type
    using RowType    = Vector<3, T>; ///< Row type

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Default constructor.
    ///
    /// Creates an identity Matrix.
    ////////////////////////////////////////////////////////////////////////////
    constexpr Matrix() noexcept;

    ////////////////////////////////////////////////////////////////////////////
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
    ////////////////////////////////////////////////////////////////////////////

    // clang-format off
    constexpr Matrix(const T& value00, const T& value01, const T& value02,
                     const T& value10, const T& value11, const T& value12,
                     const T& value20, const T& value21, const T& value22);
    // clang-format on

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initialize the main diagonal of Matrix with provided value.
    ///
    /// @param value Floating-point or integral value.
    ////////////////////////////////////////////////////////////////////////////
    explicit constexpr Matrix(const T& value) noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes all components of Matrix from pointer to values.
    ///
    /// @param pointer Const pointer to values that should be taken.
    ///
    /// @warning May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    template <typename U>
    explicit Matrix(const U* pointer);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes all components of Matrix from pointer to values.
    ///
    /// @param pointer Pointer to values that should be taken.
    ///
    /// @warning May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    template <typename U>
    explicit Matrix(U* pointer);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes matrices with provided vectors.
    ///
    /// @param column0 Vector for first column.
    /// @param column1 Vector for second column.
    /// @param column2 Vector for third column.
    ////////////////////////////////////////////////////////////////////////////
    template <typename U0, typename U1, typename U2>
    constexpr Matrix(const Vector<4, U0>& column0, const Vector<4, U1>& column1, const Vector<4, U2>& column2);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes matrices with provided vectors.
    ///
    /// @param column0 Vector for first column.
    /// @param column1 Vector for second column.
    /// @param column2 Vector for third column.
    ////////////////////////////////////////////////////////////////////////////
    template <typename U0, typename U1, typename U2>
    constexpr Matrix(const Vector<3, U0>& column0, const Vector<3, U1>& column1, const Vector<3, U2>& column2);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes matrices with provided vectors and values.
    ///
    /// @param vector0 First part for first column.
    /// @param z0 Z component for first column.
    /// @param vector1 First part for second column.
    /// @param z1 Z component for second column.
    /// @param vector2 First part for third column.
    /// @param z2 Z component for third column.
    ////////////////////////////////////////////////////////////////////////////

    // clang-format off
    template <typename U0, typename Z0,
              typename U1, typename Z1,
              typename U2, typename Z2>
    constexpr Matrix(const Vector<2, U0>& vector0, const Z0& z0,
                     const Vector<2, U1>& vector1, const Z1& z1,
                     const Vector<2, U2>& vector2, const Z2& z2);
    // clang-format on

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes matrices with provided vectors and values.
    ///
    /// @param x0 X component for first column.
    /// @param vector0 Last part for first column.
    /// @param x1 X component for second column.
    /// @param vector1 Last part for second column.
    /// @param x2 X component for third column.
    /// @param vector2 Last part for third column.
    ////////////////////////////////////////////////////////////////////////////

    // clang-format off
    template <typename X0, typename U0,
              typename X1, typename U1,
              typename X2, typename U2>
    constexpr Matrix(const X0& x0, const Vector<2, U0>& vector0,
                     const X1& x1, const Vector<2, U1>& vector1,
                     const X2& x2, const Vector<2, U2>& vector2);
    // clang-format on

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes Matrix from another one.
    ///
    /// @param other Matrix of integral or floating-point type.
    ///
    /// @note The remain components will be initialized as in identity Matrix.
    ////////////////////////////////////////////////////////////////////////////
    template <std::size_t C, std::size_t R, typename U>
    explicit constexpr Matrix(const Matrix<C, R, U>& other);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Access operator.
    ///
    /// @param index Index of column.
    ///
    /// @return Reference to column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    ColumnType& operator[](std::size_t index);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Const access operator.
    ///
    /// @param index Index of column.
    ///
    /// @return Reference to constant column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    const ColumnType& operator[](std::size_t index) const;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Size of Matrix.
    ///
    /// @return Count of columns in Matrix.
    ////////////////////////////////////////////////////////////////////////////
    constexpr std::size_t size() const noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the x component of first column.
    ////////////////////////////////////////////////////////////////////////////
    ValueType* data() noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the x component of first column.
    ////////////////////////////////////////////////////////////////////////////
    const ValueType* data() const noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Provides access to columns of the Matrix.
    ///
    /// @param index Index of column.
    ///
    /// @return Copy of column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    ColumnType column(std::size_t index) const noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Provides access to rows of the Matrix.
    ///
    /// @param index Index of row.
    ///
    /// @return Copy of row at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    RowType row(std::size_t index) const noexcept;

private:
    ColumnType m_data[3];
};

////////////////////////////////////////////////////////////////////////////////
/// @brief Matrix<3, 2, T> type specialization.
///
/// @note Can be instantiated only with arithmetic type.
////////////////////////////////////////////////////////////////////////////////
template <typename T>
struct Matrix<3, 2, T> final
{
    static_assert(std::is_arithmetic_v<T>, "Expected floating-point or integer type.");

    using ValueType  = T;            ///< Value type
    using ColumnType = Vector<2, T>; ///< Column type
    using RowType    = Vector<3, T>; ///< Row type

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Default constructor.
    ///
    /// Creates an identity Matrix.
    ////////////////////////////////////////////////////////////////////////////
    constexpr Matrix() noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes matrices with provided values.
    ///
    /// @param value00 Value for first column.
    /// @param value01 Value for first column.
    /// @param value10 Value for second column.
    /// @param value11 Value for second column.
    /// @param value20 Value for third column.
    /// @param value21 Value for third column.
    ////////////////////////////////////////////////////////////////////////////

    // clang-format off
    constexpr Matrix(const T& value00, const T& value01,
                     const T& value10, const T& value11,
                     const T& value20, const T& value21);
    // clang-format on

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initialize the main diagonal of Matrix with provided value.
    ///
    /// @param value Floating-point or integral value.
    ////////////////////////////////////////////////////////////////////////////
    explicit constexpr Matrix(const T& value) noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes all components of Matrix from pointer to values.
    ///
    /// @param pointer Const pointer to values that should be taken.
    ///
    /// @warning May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    template <typename U>
    explicit Matrix(const U* pointer);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes all components of Matrix from pointer to values.
    ///
    /// @param pointer Pointer to values that should be taken.
    ///
    /// @warning May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    template <typename U>
    explicit Matrix(U* pointer);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes matrices with provided vectors.
    ///
    /// @param column0 Vector for first column.
    /// @param column1 Vector for second column.
    /// @param column2 Vector for third column.
    ////////////////////////////////////////////////////////////////////////////
    template <typename U0, typename U1, typename U2>
    constexpr Matrix(const Vector<4, U0>& column0, const Vector<4, U1>& column1, const Vector<4, U2>& column2);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes matrices with provided vectors.
    ///
    /// @param column0 Vector for first column.
    /// @param column1 Vector for second column.
    /// @param column2 Vector for third column.
    ////////////////////////////////////////////////////////////////////////////
    template <typename U0, typename U1, typename U2>
    constexpr Matrix(const Vector<3, U0>& column0, const Vector<3, U1>& column1, const Vector<3, U2>& column2);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes matrices with provided vectors.
    ///
    /// @param column0 Vector for first column.
    /// @param column1 Vector for second column.
    /// @param column2 Vector for third column.
    ////////////////////////////////////////////////////////////////////////////

    // clang-format off
    template <typename U0,
              typename U1,
              typename U2>
    constexpr Matrix(const Vector<2, U0>& column0,
                     const Vector<2, U1>& column1,
                     const Vector<2, U2>& column2);
    // clang-format on

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes Matrix from another one.
    ///
    /// @param other Matrix of integral or floating-point type.
    ///
    /// @note The remain components will be initialized as in identity Matrix.
    ////////////////////////////////////////////////////////////////////////////
    template <std::size_t C, std::size_t R, typename U>
    explicit constexpr Matrix(const Matrix<C, R, U>& other);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Access operator.
    ///
    /// @param index Index of column.
    ///
    /// @return Reference to column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    ColumnType& operator[](std::size_t index);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Const access operator.
    ///
    /// @param index Index of column.
    ///
    /// @return Reference to constant column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    const ColumnType& operator[](std::size_t index) const;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Size of Matrix.
    ///
    /// @return Count of columns in Matrix.
    ////////////////////////////////////////////////////////////////////////////
    constexpr std::size_t size() const noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the x component of first column.
    ////////////////////////////////////////////////////////////////////////////
    ValueType* data() noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the x component of first column.
    ////////////////////////////////////////////////////////////////////////////
    const ValueType* data() const noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Provides access to columns of the Matrix.
    ///
    /// @param index Index of column.
    ///
    /// @return Copy of column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    ColumnType column(std::size_t index) const noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Provides access to rows of the Matrix.
    ///
    /// @param index Index of row.
    ///
    /// @return Copy of row at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    RowType row(std::size_t index) const noexcept;

private:
    ColumnType m_data[3];
};

////////////////////////////////////////////////////////////////////////////////
/// @brief Matrix<2, 4, T> type specialization.
///
/// @note Can be instantiated only with arithmetic type.
////////////////////////////////////////////////////////////////////////////////
template <typename T>
struct Matrix<2, 4, T> final
{
    static_assert(std::is_arithmetic_v<T>, "Expected floating-point or integer type.");

    using ValueType  = T;            ///< Value type
    using ColumnType = Vector<4, T>; ///< Column type
    using RowType    = Vector<2, T>; ///< Row type

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Default constructor.
    ///
    /// Creates an identity Matrix.
    ////////////////////////////////////////////////////////////////////////////
    constexpr Matrix() noexcept;

    ////////////////////////////////////////////////////////////////////////////
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
    ////////////////////////////////////////////////////////////////////////////

    // clang-format off
    constexpr Matrix(const T& value00, const T& value01, const T& value02, const T& value03,
                     const T& value10, const T& value11, const T& value12, const T& value13);
    // clang-format on

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initialize the main diagonal of Matrix with provided value.
    ///
    /// @param value Floating-point or integral value.
    ////////////////////////////////////////////////////////////////////////////
    explicit constexpr Matrix(const T& value) noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes all components of Matrix from pointer to values.
    ///
    /// @param pointer Const pointer to values that should be taken.
    ///
    /// @warning May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    template <typename U>
    explicit Matrix(const U* pointer);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes all components of Matrix from pointer to values.
    ///
    /// @param pointer Pointer to values that should be taken.
    ///
    /// @warning May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    template <typename U>
    explicit Matrix(U* pointer);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes matrices with provided vectors.
    ///
    /// @param column0 Vector for first column.
    /// @param column1 Vector for second column.
    ////////////////////////////////////////////////////////////////////////////
    template <typename U0, typename U1>
    constexpr Matrix(const Vector<4, U0>& column0, const Vector<4, U1>& column1);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes matrices with provided vectors and scalar values.
    ///
    /// @param vector0 First part for first column.
    /// @param w0 Last component for first column.
    /// @param vector1 First part for second column.
    /// @param w1 Last component for second column.
    ////////////////////////////////////////////////////////////////////////////

    // clang-format off
    template <typename U0, typename W0,
              typename U1, typename W1>
    constexpr Matrix(const Vector<3, U0>& vector0, const W0& w0,
                     const Vector<3, U1>& vector1, const W1& w1);
    // clang-format on

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes matrices with provided scalar values and vectors.
    ///
    /// @param x0 First component for first column.
    /// @param vector0 Last part for first column.
    /// @param x1 First component for second column.
    /// @param vector1 Last part for second column.
    ////////////////////////////////////////////////////////////////////////////

    // clang-format off
    template <typename X0, typename U0,
              typename X1, typename U1>
    constexpr Matrix(const X0& x0, const Vector<3, U0>& vector0,
                     const X1& x1, const Vector<3, U1>& vector1);
    // clang-format on

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes matrices with provided vectors and values.
    ///
    /// @param vector00 First part for first column.
    /// @param vector01 Last part for first column.
    /// @param vector10 First part for second column.
    /// @param vector11 Last part for second column.
    ////////////////////////////////////////////////////////////////////////////

    // clang-format off
    template <typename U00, typename U01,
              typename U10, typename U11>
    constexpr Matrix(const Vector<2, U00>& vector00, const Vector<2, U01>& vector01,
                     const Vector<2, U10>& vector10, const Vector<2, U11>& vector11);
    // clang-format on

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes matrices with provided vectors and values.
    ///
    /// @param vector0 First part for first column.
    /// @param z0 Z component for first column.
    /// @param w0 W component for first column.
    /// @param vector1 First part for second column.
    /// @param z1 Z component for second column.
    /// @param w1 W component for second column.
    ////////////////////////////////////////////////////////////////////////////

    // clang-format off
    template <typename U0, typename Z0, typename W0,
              typename U1, typename Z1, typename W1>
    constexpr Matrix(const Vector<2, U0>& vector0, const Z0& z0, const W0& w0,
                     const Vector<2, U1>& vector1, const Z1& z1, const W1& w1);
    // clang-format on

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes matrices with provided vectors and values.
    ///
    /// @param x0 X component for first column.
    /// @param vector0 Middle part for first column.
    /// @param w0 W component for first column.
    /// @param x1 X component for second column.
    /// @param vector1 Middle part for second column.
    /// @param w1 W component for second column.
    ////////////////////////////////////////////////////////////////////////////

    // clang-format off
    template <typename X0, typename U0, typename W0,
              typename X1, typename U1, typename W1>
    constexpr Matrix(const X0& x0, const Vector<2, U0>& vector0, const W0& w0,
                     const X1& x1, const Vector<2, U1>& vector1, const W1& w1);
    // clang-format on

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes matrices with provided vectors and values.
    ///
    /// @param x0 X component for first column.
    /// @param y0 Y component for first column.
    /// @param vector0 Last part for first column.
    /// @param x1 X component for second column.
    /// @param y1 Y component for second column.
    /// @param vector1 Last part for second column.
    ////////////////////////////////////////////////////////////////////////////

    // clang-format off
    template <typename X0, typename Y0, typename U0,
              typename X1, typename Y1, typename U1>
    constexpr Matrix(const X0& x0, const Y0& y0, const Vector<2, U0>& vector0,
                     const X1& x1, const Y1& y1, const Vector<2, U1>& vector1);
    // clang-format on

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes Matrix from another one.
    ///
    /// @param other Matrix of integral or floating-point type.
    ///
    /// @note The remain components will be initialized as in identity Matrix.
    ////////////////////////////////////////////////////////////////////////////
    template <std::size_t C, std::size_t R, typename U>
    explicit constexpr Matrix(const Matrix<C, R, U>& other);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Access operator.
    ///
    /// @param index Index of column.
    ///
    /// @return Reference to column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    ColumnType& operator[](std::size_t index);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Const access operator.
    ///
    /// @param index Index of column.
    ///
    /// @return Reference to constant column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    const ColumnType& operator[](std::size_t index) const;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Size of Matrix.
    ///
    /// @return Count of columns in Matrix.
    ////////////////////////////////////////////////////////////////////////////
    constexpr std::size_t size() const noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the x component of first column.
    ////////////////////////////////////////////////////////////////////////////
    ValueType* data() noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the x component of first column.
    ////////////////////////////////////////////////////////////////////////////
    const ValueType* data() const noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Provides access to columns of the Matrix.
    ///
    /// @param index Index of column.
    ///
    /// @return Copy of column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    ColumnType column(std::size_t index) const noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Provides access to rows of the Matrix.
    ///
    /// @param index Index of row.
    ///
    /// @return Copy of row at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    RowType row(std::size_t index) const noexcept;

private:
    ColumnType m_data[2];
};

////////////////////////////////////////////////////////////////////////////////
/// @brief Matrix<2, 3, T> type specialization.
///
/// @note Can be instantiated only with arithmetic type.
////////////////////////////////////////////////////////////////////////////////
template <typename T>
struct Matrix<2, 3, T> final
{
    static_assert(std::is_arithmetic_v<T>, "Expected floating-point or integer type.");

    using ValueType  = T;            ///< Value type
    using ColumnType = Vector<3, T>; ///< Column type
    using RowType    = Vector<2, T>; ///< Row type

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Default constructor.
    ///
    /// Creates an identity Matrix.
    ////////////////////////////////////////////////////////////////////////////
    constexpr Matrix() noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes matrices with provided values.
    ///
    /// @param value00 Value for first column.
    /// @param value01 Value for first column.
    /// @param value02 Value for first column.
    /// @param value10 Value for second column.
    /// @param value11 Value for second column.
    /// @param value12 Value for second column.
    ////////////////////////////////////////////////////////////////////////////

    // clang-format off
    constexpr Matrix(const T& value00, const T& value01, const T& value02,
                     const T& value10, const T& value11, const T& value12);
    // clang-format on

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initialize the main diagonal of Matrix with provided value.
    ///
    /// @param value Floating-point or integral value.
    ////////////////////////////////////////////////////////////////////////////
    explicit constexpr Matrix(const T& value) noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes all components of Matrix from pointer to values.
    ///
    /// @param pointer Const pointer to values that should be taken.
    ///
    /// @warning May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    template <typename U>
    explicit Matrix(const U* pointer);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes all components of Matrix from pointer to values.
    ///
    /// @param pointer Pointer to values that should be taken.
    ///
    /// @warning May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    template <typename U>
    explicit Matrix(U* pointer);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes matrices with provided vectors.
    ///
    /// @param column0 Vector for first column.
    /// @param column1 Vector for second column.
    ////////////////////////////////////////////////////////////////////////////
    template <typename U0, typename U1>
    constexpr Matrix(const Vector<4, U0>& column0, const Vector<4, U1>& column1);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes matrices with provided vectors.
    ///
    /// @param column0 Vector for first column.
    /// @param column1 Vector for second column.
    ////////////////////////////////////////////////////////////////////////////
    template <typename U0, typename U1>
    constexpr Matrix(const Vector<3, U0>& column0, const Vector<3, U1>& column1);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes matrices with provided vectors and values.
    ///
    /// @param vector0 First part for first column.
    /// @param z0 Z component for first column.
    /// @param vector1 First part for second column.
    /// @param z1 Z component for second column.
    ////////////////////////////////////////////////////////////////////////////

    // clang-format off
    template <typename U0, typename Z0,
              typename U1, typename Z1>
    constexpr Matrix(const Vector<2, U0>& vector0, const Z0& z0,
                     const Vector<2, U1>& vector1, const Z1& z1);
    // clang-format on

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes matrices with provided vectors and values.
    ///
    /// @param x0 X component for first column.
    /// @param vector0 Last part for first column.
    /// @param x1 X component for second column.
    /// @param vector1 Last part for second column.
    ////////////////////////////////////////////////////////////////////////////

    // clang-format off
    template <typename X0, typename U0,
              typename X1, typename U1>
    constexpr Matrix(const X0& x0, const Vector<2, U0>& vector0,
                     const X1& x1, const Vector<2, U1>& vector1);
    // clang-format on

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes Matrix from another one.
    ///
    /// @param other Matrix of integral or floating-point type.
    ///
    /// @note The remain components will be initialized as in identity Matrix.
    ////////////////////////////////////////////////////////////////////////////
    template <std::size_t C, std::size_t R, typename U>
    explicit constexpr Matrix(const Matrix<C, R, U>& other);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Access operator.
    ///
    /// @param index Index of column.
    ///
    /// @return Reference to column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    ColumnType& operator[](std::size_t index);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Const access operator.
    ///
    /// @param index Index of column.
    ///
    /// @return Reference to constant column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    const ColumnType& operator[](std::size_t index) const;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Size of Matrix.
    ///
    /// @return Count of columns in Matrix.
    ////////////////////////////////////////////////////////////////////////////
    constexpr std::size_t size() const noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the x component of first column.
    ////////////////////////////////////////////////////////////////////////////
    ValueType* data() noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the x component of first column.
    ////////////////////////////////////////////////////////////////////////////
    const ValueType* data() const noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Provides access to columns of the Matrix.
    ///
    /// @param index Index of column.
    ///
    /// @return Copy of column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    ColumnType column(std::size_t index) const noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Provides access to rows of the Matrix.
    ///
    /// @param index Index of row.
    ///
    /// @return Copy of row at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    RowType row(std::size_t index) const noexcept;

private:
    ColumnType m_data[2];
};

////////////////////////////////////////////////////////////////////////////////
/// @brief Matrix<2, 2, T> type specialization.
///
/// @note Can be instantiated only with arithmetic type.
////////////////////////////////////////////////////////////////////////////////
template <typename T>
struct Matrix<2, 2, T> final
{
    static_assert(std::is_arithmetic_v<T>, "Expected floating-point or integer type.");

    using ValueType  = T;            ///< Value type
    using ColumnType = Vector<2, T>; ///< Column type
    using RowType    = Vector<2, T>; ///< Row type

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Default constructor.
    ///
    /// Creates an identity Matrix.
    ////////////////////////////////////////////////////////////////////////////
    constexpr Matrix() noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes matrices with provided values.
    ///
    /// @param value00 Value for first column.
    /// @param value01 Value for first column.
    /// @param value10 Value for second column.
    /// @param value11 Value for second column.
    ////////////////////////////////////////////////////////////////////////////
    constexpr Matrix(const T& value00, const T& value01, const T& value10, const T& value11);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initialize the main diagonal of Matrix with provided value.
    ///
    /// @param value Floating-point or integral value.
    ////////////////////////////////////////////////////////////////////////////
    explicit constexpr Matrix(const T& value) noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes all components of Matrix from pointer to values.
    ///
    /// @param pointer Const pointer to values that should be taken.
    ///
    /// @warning May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    template <typename U>
    explicit Matrix(const U* pointer);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes all components of Matrix from pointer to values.
    ///
    /// @param pointer Pointer to values that should be taken.
    ///
    /// @warning May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    template <typename U>
    explicit Matrix(U* pointer);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes matrices with provided vectors.
    ///
    /// @param column0 Vector for first column.
    /// @param column1 Vector for second column.
    ////////////////////////////////////////////////////////////////////////////
    template <typename U0, typename U1>
    constexpr Matrix(const Vector<4, U0>& column0, const Vector<4, U1>& column1);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes matrices with provided vectors.
    ///
    /// @param column0 Vector for first column.
    /// @param column1 Vector for second column.
    ////////////////////////////////////////////////////////////////////////////
    template <typename U0, typename U1>
    constexpr Matrix(const Vector<3, U0>& column0, const Vector<3, U1>& column1);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes matrices with provided vectors.
    ///
    /// @param column0 Vector for first column.
    /// @param column1 Vector for second column.
    ////////////////////////////////////////////////////////////////////////////
    template <typename U0, typename U1>
    constexpr Matrix(const Vector<2, U0>& column0, const Vector<2, U1>& column1);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Initializes Matrix from another one.
    ///
    /// @param other Matrix of integral or floating-point type.
    ///
    /// @note The remain components will be initialized as in identity Matrix.
    ////////////////////////////////////////////////////////////////////////////
    template <std::size_t C, std::size_t R, typename U>
    explicit constexpr Matrix(const Matrix<C, R, U>& other);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Access operator.
    ///
    /// @param index Index of column.
    ///
    /// @return Reference to column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    ColumnType& operator[](std::size_t index);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Const access operator.
    ///
    /// @param index Index of column.
    ///
    /// @return Reference to constant column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    const ColumnType& operator[](std::size_t index) const;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Size of Matrix.
    ///
    /// @return Count of columns in Matrix.
    ////////////////////////////////////////////////////////////////////////////
    constexpr std::size_t size() const noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the x component of first column.
    ////////////////////////////////////////////////////////////////////////////
    ValueType* data() noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Provides direct access to internal content.
    ///
    /// @return A pointer to the x component of first column.
    ////////////////////////////////////////////////////////////////////////////
    const ValueType* data() const noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Provides access to columns of the Matrix.
    ///
    /// @param index Index of column.
    ///
    /// @return Copy of column at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    ColumnType column(std::size_t index) const noexcept;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Provides access to rows of the Matrix.
    ///
    /// @param index Index of row.
    ///
    /// @return Copy of row at index.
    ///
    /// @warning There is no size check. May cause memory access error.
    ////////////////////////////////////////////////////////////////////////////
    RowType row(std::size_t index) const noexcept;

private:
    ColumnType m_data[2];
};
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name Matrix<4, 4, T> constructors.
/// @{
////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline constexpr Matrix<4, 4, T>::Matrix() noexcept
    : Matrix(T{1})
{}

// clang-format off
template <typename T>
inline constexpr Matrix<4, 4, T>::Matrix(const T& value00, const T& value01, const T& value02, const T& value03,
                                         const T& value10, const T& value11, const T& value12, const T& value13,
                                         const T& value20, const T& value21, const T& value22, const T& value23,
                                         const T& value30, const T& value31, const T& value32, const T& value33)
    : m_data{ColumnType(value00, value01, value02, value03),
             ColumnType(value10, value11, value12, value13),
             ColumnType(value20, value21, value22, value23),
             ColumnType(value30, value31, value32, value33)}
{
}
// clang-format on

// clang-format off
template <typename T>
inline constexpr Matrix<4, 4, T>::Matrix(const T& value) noexcept
    : m_data{ColumnType(value, 0, 0, 0),
             ColumnType(0, value, 0, 0),
             ColumnType(0, 0, value, 0),
             ColumnType(0, 0, 0, value)}
{
}
// clang-format on

template <typename T>
template <typename U>
inline Matrix<4, 4, T>::Matrix(const U* pointer)
    : m_data{ColumnType(pointer), ColumnType(pointer + 4), ColumnType(pointer + 8), ColumnType(pointer + 12)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

template <typename T>
template <typename U>
inline Matrix<4, 4, T>::Matrix(U* pointer)
    : m_data{ColumnType(pointer), ColumnType(pointer + 4), ColumnType(pointer + 8), ColumnType(pointer + 12)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

template <typename T>
template <typename U0, typename U1, typename U2, typename U3>
inline constexpr Matrix<4, 4, T>::Matrix(const Vector<4, U0>& column0,
                                         const Vector<4, U1>& column1,
                                         const Vector<4, U2>& column2,
                                         const Vector<4, U3>& column3)
    : m_data{ColumnType(column0), ColumnType(column1), ColumnType(column2), ColumnType(column3)}
{}

// clang-format off
template <typename T>
template <typename U0, typename W0,
          typename U1, typename W1,
          typename U2, typename W2,
          typename U3, typename W3>
inline constexpr Matrix<4, 4, T>::Matrix(const Vector<3, U0>& vector0, const W0& w0,
                                         const Vector<3, U1>& vector1, const W1& w1,
                                         const Vector<3, U2>& vector2, const W2& w2,
                                         const Vector<3, U3>& vector3, const W3& w3)
    : m_data{ColumnType(vector0, w0),
             ColumnType(vector1, w1),
             ColumnType(vector2, w2),
             ColumnType(vector3, w3)}
{
}
// clang-format on

// clang-format off
template <typename T>
template <typename X0, typename U0,
          typename X1, typename U1,
          typename X2, typename U2,
          typename X3, typename U3>
inline constexpr Matrix<4, 4, T>::Matrix(const X0& x0, const Vector<3, U0>& vector0,
                                         const X1& x1, const Vector<3, U1>& vector1,
                                         const X2& x2, const Vector<3, U2>& vector2,
                                         const X3& x3, const Vector<3, U3>& vector3)
    : m_data{ColumnType(x0, vector0),
             ColumnType(x1, vector1),
             ColumnType(x2, vector2),
             ColumnType(x3, vector3)}
{
}
// clang-format on

// clang-format off
template <typename T>
template <typename U00, typename U01,
          typename U10, typename U11,
          typename U20, typename U21,
          typename U30, typename U31>
inline constexpr Matrix<4, 4, T>::Matrix(const Vector<2, U00>& vector00, const Vector<2, U01>& vector01,
                                         const Vector<2, U10>& vector10, const Vector<2, U11>& vector11,
                                         const Vector<2, U20>& vector20, const Vector<2, U21>& vector21,
                                         const Vector<2, U30>& vector30, const Vector<2, U31>& vector31)
    : m_data{ColumnType(vector00, vector01),
             ColumnType(vector10, vector11),
             ColumnType(vector20, vector21),
             ColumnType(vector30, vector31)}
{
}
// clang-format on

// clang-format off
template <typename T>
template <typename U0, typename Z0, typename W0,
          typename U1, typename Z1, typename W1,
          typename U2, typename Z2, typename W2,
          typename U3, typename Z3, typename W3>
inline constexpr Matrix<4, 4, T>::Matrix(const Vector<2, U0>& vector0, const Z0& z0, const W0& w0,
                                         const Vector<2, U1>& vector1, const Z1& z1, const W1& w1,
                                         const Vector<2, U2>& vector2, const Z2& z2, const W2& w2,
                                         const Vector<2, U3>& vector3, const Z3& z3, const W3& w3)
    : m_data{ColumnType(vector0, z0, w0),
             ColumnType(vector1, z1, w1),
             ColumnType(vector2, z2, w2),
             ColumnType(vector3, z3, w3)}
{
}
// clang-format on

// clang-format off
template <typename T>
template <typename X0, typename U0, typename W0,
          typename X1, typename U1, typename W1,
          typename X2, typename U2, typename W2,
          typename X3, typename U3, typename W3>
inline constexpr Matrix<4, 4, T>::Matrix(const X0& x0, const Vector<2, U0>& vector0, const W0& w0,
                                         const X1& x1, const Vector<2, U1>& vector1, const W1& w1,
                                         const X2& x2, const Vector<2, U2>& vector2, const W2& w2,
                                         const X3& x3, const Vector<2, U3>& vector3, const W3& w3)
    : m_data{ColumnType(x0, vector0, w0),
             ColumnType(x1, vector1, w1),
             ColumnType(x2, vector2, w2),
             ColumnType(x3, vector3, w3)}
{
}
// clang-format on

// clang-format off
template <typename T>
template <typename X0, typename Y0, typename U0,
          typename X1, typename Y1, typename U1,
          typename X2, typename Y2, typename U2,
          typename X3, typename Y3, typename U3>
inline constexpr Matrix<4, 4, T>::Matrix(const X0& x0, const Y0& y0, const Vector<2, U0>& vector0,
                 const X1& x1, const Y1& y1, const Vector<2, U1>& vector1,
                 const X2& x2, const Y2& y2, const Vector<2, U2>& vector2,
                 const X3& x3, const Y3& y3, const Vector<2, U3>& vector3)
    : m_data{ColumnType(x0, y0, vector0),
             ColumnType(x1, y1, vector1),
             ColumnType(x2, y2, vector2),
             ColumnType(x3, y3, vector3)}
{
}
// clang-format on

template <typename T>
template <std::size_t C, std::size_t R, typename U>
inline constexpr Matrix<4, 4, T>::Matrix(const Matrix<C, R, U>& other)
    : m_data{matrix_type_details::get_column<0, C>(other, ColumnType(1, 0, 0, 0)),
             matrix_type_details::get_column<1, C>(other, ColumnType(0, 1, 0, 0)),
             matrix_type_details::get_column<2, C>(other, ColumnType(0, 0, 1, 0)),
             matrix_type_details::get_column<3, C>(other, ColumnType(0, 0, 0, 1))}
{}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name Matrix<4, 4, T> operators.
/// @{
////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline typename Matrix<4, 4, T>::ColumnType& Matrix<4, 4, T>::operator[](std::size_t index)
{
    assert(index < 4);
    return m_data[index];
}

template <typename T>
inline const typename Matrix<4, 4, T>::ColumnType& Matrix<4, 4, T>::operator[](std::size_t index) const
{
    assert(index < 4);
    return m_data[index];
}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name Matrix<4, 4, T> methods.
/// @{
////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline constexpr std::size_t Matrix<4, 4, T>::size() const noexcept
{
    return 4;
}

template <typename T>
inline typename Matrix<4, 4, T>::ValueType* Matrix<4, 4, T>::data() noexcept
{
    return m_data[0].data();
}

template <typename T>
const typename Matrix<4, 4, T>::ValueType* Matrix<4, 4, T>::data() const noexcept
{
    return m_data[0].data();
}

template <typename T>
inline typename Matrix<4, 4, T>::ColumnType Matrix<4, 4, T>::column(std::size_t index) const noexcept
{
    assert(index < 4);
    return m_data[index];
}

template <typename T>
inline typename Matrix<4, 4, T>::RowType Matrix<4, 4, T>::row(std::size_t index) const noexcept
{
    assert(index < 4);
    return Matrix<4, 4, T>::RowType(m_data[0][index], m_data[1][index], m_data[2][index], m_data[3][index]);
}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name Matrix<4, 3, T> constructors.
/// @{
////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline constexpr Matrix<4, 3, T>::Matrix() noexcept
    : Matrix(T{1})
{}

// clang-format off
template <typename T>
inline constexpr Matrix<4, 3, T>::Matrix(const T& value00, const T& value01, const T& value02,
                                         const T& value10, const T& value11, const T& value12,
                                         const T& value20, const T& value21, const T& value22,
                                         const T& value30, const T& value31, const T& value32)
    : m_data{ColumnType(value00, value01, value02),
             ColumnType(value10, value11, value12),
             ColumnType(value20, value21, value22),
             ColumnType(value30, value31, value32)}
{
}
// clang-format on

// clang-format off
template <typename T>
inline constexpr Matrix<4, 3, T>::Matrix(const T& value) noexcept
    : m_data{ColumnType(value, 0, 0),
             ColumnType(0, value, 0),
             ColumnType(0, 0, value),
             ColumnType(0, 0, 0)}
{
}
// clang-format on

template <typename T>
template <typename U>
inline Matrix<4, 3, T>::Matrix(const U* pointer)
    : m_data{ColumnType(pointer), ColumnType(pointer + 3), ColumnType(pointer + 6), ColumnType(pointer + 9)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

template <typename T>
template <typename U>
inline Matrix<4, 3, T>::Matrix(U* pointer)
    : m_data{ColumnType(pointer), ColumnType(pointer + 3), ColumnType(pointer + 6), ColumnType(pointer + 9)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

template <typename T>
template <typename U0, typename U1, typename U2, typename U3>
inline constexpr Matrix<4, 3, T>::Matrix(const Vector<4, U0>& column0,
                                         const Vector<4, U1>& column1,
                                         const Vector<4, U2>& column2,
                                         const Vector<4, U3>& column3)
    : m_data{ColumnType(column0), ColumnType(column1), ColumnType(column2), ColumnType(column3)}
{}

template <typename T>
template <typename U0, typename U1, typename U2, typename U3>
inline constexpr Matrix<4, 3, T>::Matrix(const Vector<3, U0>& column0,
                                         const Vector<3, U1>& column1,
                                         const Vector<3, U2>& column2,
                                         const Vector<3, U3>& column3)
    : m_data{ColumnType(column0), ColumnType(column1), ColumnType(column2), ColumnType(column3)}
{}

// clang-format off
template <typename T>
template <typename U0, typename Z0,
          typename U1, typename Z1,
          typename U2, typename Z2,
          typename U3, typename Z3>
inline constexpr Matrix<4, 3, T>::Matrix(const Vector<2, U0>& vector0, const Z0& z0,
                                         const Vector<2, U1>& vector1, const Z1& z1,
                                         const Vector<2, U2>& vector2, const Z2& z2,
                                         const Vector<2, U3>& vector3, const Z3& z3)
    : m_data{ColumnType(vector0, z0),
             ColumnType(vector1, z1),
             ColumnType(vector2, z2),
             ColumnType(vector3, z3)}
{
}
// clang-format on

// clang-format off
template <typename T>
template <typename X0, typename U0,
          typename X1, typename U1,
          typename X2, typename U2,
          typename X3, typename U3>
inline constexpr Matrix<4, 3, T>::Matrix(const X0& x0, const Vector<2, U0>& vector0,
                                         const X1& x1, const Vector<2, U1>& vector1,
                                         const X2& x2, const Vector<2, U2>& vector2,
                                         const X3& x3, const Vector<2, U3>& vector3)
    : m_data{ColumnType(x0, vector0),
             ColumnType(x1, vector1),
             ColumnType(x2, vector2),
             ColumnType(x3, vector3)}
{
}
// clang-format on

template <typename T>
template <std::size_t C, std::size_t R, typename U>
inline constexpr Matrix<4, 3, T>::Matrix(const Matrix<C, R, U>& other)
    : m_data{matrix_type_details::get_column<0, C>(other, ColumnType(1, 0, 0)),
             matrix_type_details::get_column<1, C>(other, ColumnType(0, 1, 0)),
             matrix_type_details::get_column<2, C>(other, ColumnType(0, 0, 1)),
             matrix_type_details::get_column<3, C>(other, ColumnType(0, 0, 0))}
{}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name Matrix<4, 3, T> operators.
/// @{
////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline typename Matrix<4, 3, T>::ColumnType& Matrix<4, 3, T>::operator[](std::size_t index)
{
    assert(index < 4);
    return m_data[index];
}

template <typename T>
inline const typename Matrix<4, 3, T>::ColumnType& Matrix<4, 3, T>::operator[](std::size_t index) const
{
    assert(index < 4);
    return m_data[index];
}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name Matrix<4, 3, T> methods.
/// @{
////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline constexpr std::size_t Matrix<4, 3, T>::size() const noexcept
{
    return 4;
}

template <typename T>
inline typename Matrix<4, 3, T>::ValueType* Matrix<4, 3, T>::data() noexcept
{
    return m_data[0].data();
}

template <typename T>
const typename Matrix<4, 3, T>::ValueType* Matrix<4, 3, T>::data() const noexcept
{
    return m_data[0].data();
}

template <typename T>
inline typename Matrix<4, 3, T>::ColumnType Matrix<4, 3, T>::column(std::size_t index) const noexcept
{
    assert(index < 4);
    return m_data[index];
}

template <typename T>
inline typename Matrix<4, 3, T>::RowType Matrix<4, 3, T>::row(std::size_t index) const noexcept
{
    assert(index < 3);
    return Matrix<4, 3, T>::RowType(m_data[0][index], m_data[1][index], m_data[2][index], m_data[3][index]);
}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name Matrix<4, 2, T> constructors.
/// @{
////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline constexpr Matrix<4, 2, T>::Matrix() noexcept
    : Matrix(T{1})
{}

// clang-format off
template <typename T>
inline constexpr Matrix<4, 2, T>::Matrix(const T& value00, const T& value01,
                                         const T& value10, const T& value11,
                                         const T& value20, const T& value21,
                                         const T& value30, const T& value31)
    : m_data{ColumnType(value00, value01),
             ColumnType(value10, value11),
             ColumnType(value20, value21),
             ColumnType(value30, value31)}
{
}
// clang-format on

// clang-format off
template <typename T>
inline constexpr Matrix<4, 2, T>::Matrix(const T& value) noexcept
    : m_data{ColumnType(value, 0),
             ColumnType(0, value),
             ColumnType(0, 0),
             ColumnType(0, 0)}
{
}
// clang-format on

template <typename T>
template <typename U>
inline Matrix<4, 2, T>::Matrix(const U* pointer)
    : m_data{ColumnType(pointer), ColumnType(pointer + 2), ColumnType(pointer + 4), ColumnType(pointer + 6)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

template <typename T>
template <typename U>
inline Matrix<4, 2, T>::Matrix(U* pointer)
    : m_data{ColumnType(pointer), ColumnType(pointer + 2), ColumnType(pointer + 4), ColumnType(pointer + 6)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

template <typename T>
template <typename U0, typename U1, typename U2, typename U3>
inline constexpr Matrix<4, 2, T>::Matrix(const Vector<4, U0>& column0,
                                         const Vector<4, U1>& column1,
                                         const Vector<4, U2>& column2,
                                         const Vector<4, U3>& column3)
    : m_data{ColumnType(column0), ColumnType(column1), ColumnType(column2), ColumnType(column3)}
{}

template <typename T>
template <typename U0, typename U1, typename U2, typename U3>
inline constexpr Matrix<4, 2, T>::Matrix(const Vector<3, U0>& column0,
                                         const Vector<3, U1>& column1,
                                         const Vector<3, U2>& column2,
                                         const Vector<3, U3>& column3)
    : m_data{ColumnType(column0), ColumnType(column1), ColumnType(column2), ColumnType(column3)}
{}

template <typename T>
template <typename U0, typename U1, typename U2, typename U3>
inline constexpr Matrix<4, 2, T>::Matrix(const Vector<2, U0>& column0,
                                         const Vector<2, U1>& column1,
                                         const Vector<2, U2>& column2,
                                         const Vector<2, U3>& column3)
    : m_data{ColumnType(column0), ColumnType(column1), ColumnType(column2), ColumnType(column3)}
{}

template <typename T>
template <std::size_t C, std::size_t R, typename U>
inline constexpr Matrix<4, 2, T>::Matrix(const Matrix<C, R, U>& other)
    : m_data{matrix_type_details::get_column<0, C>(other, ColumnType(1, 0)),
             matrix_type_details::get_column<1, C>(other, ColumnType(0, 1)),
             matrix_type_details::get_column<2, C>(other, ColumnType(0, 0)),
             matrix_type_details::get_column<3, C>(other, ColumnType(0, 0))}
{}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name Matrix<4, 2, T> operators.
/// @{
////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline typename Matrix<4, 2, T>::ColumnType& Matrix<4, 2, T>::operator[](std::size_t index)
{
    assert(index < 4);
    return m_data[index];
}

template <typename T>
inline const typename Matrix<4, 2, T>::ColumnType& Matrix<4, 2, T>::operator[](std::size_t index) const
{
    assert(index < 4);
    return m_data[index];
}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name Matrix<4, 2, T> methods.
/// @{
////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline constexpr std::size_t Matrix<4, 2, T>::size() const noexcept
{
    return 4;
}

template <typename T>
inline typename Matrix<4, 2, T>::ValueType* Matrix<4, 2, T>::data() noexcept
{
    return m_data[0].data();
}

template <typename T>
const typename Matrix<4, 2, T>::ValueType* Matrix<4, 2, T>::data() const noexcept
{
    return m_data[0].data();
}

template <typename T>
inline typename Matrix<4, 2, T>::ColumnType Matrix<4, 2, T>::column(std::size_t index) const noexcept
{
    assert(index < 4);
    return m_data[index];
}

template <typename T>
inline typename Matrix<4, 2, T>::RowType Matrix<4, 2, T>::row(std::size_t index) const noexcept
{
    assert(index < 2);
    return Matrix<4, 2, T>::RowType(m_data[0][index], m_data[1][index], m_data[2][index], m_data[3][index]);
}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name Matrix<3, 4, T> constructors.
/// @{
////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline constexpr Matrix<3, 4, T>::Matrix() noexcept
    : Matrix(T{1})
{}

// clang-format off
template <typename T>
inline constexpr Matrix<3, 4, T>::Matrix(const T& value00, const T& value01, const T& value02, const T& value03,
                                         const T& value10, const T& value11, const T& value12, const T& value13,
                                         const T& value20, const T& value21, const T& value22, const T& value23)
    : m_data{ColumnType(value00, value01, value02, value03),
             ColumnType(value10, value11, value12, value13),
             ColumnType(value20, value21, value22, value23)}
{
}
// clang-format on

// clang-format off
template <typename T>
inline constexpr Matrix<3, 4, T>::Matrix(const T& value) noexcept
    : m_data{ColumnType(value, 0, 0, 0),
             ColumnType(0, value, 0, 0),
             ColumnType(0, 0, value, 0)}
{
}
// clang-format on

template <typename T>
template <typename U>
inline Matrix<3, 4, T>::Matrix(const U* pointer)
    : m_data{ColumnType(pointer), ColumnType(pointer + 4), ColumnType(pointer + 8)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

template <typename T>
template <typename U>
inline Matrix<3, 4, T>::Matrix(U* pointer)
    : m_data{ColumnType(pointer), ColumnType(pointer + 4), ColumnType(pointer + 8)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

// clang-format off
template <typename T>
template <typename U0, typename U1, typename U2>
inline constexpr Matrix<3, 4, T>::Matrix(const Vector<4, U0>& column0,
                                         const Vector<4, U1>& column1,
                                         const Vector<4, U2>& column2)
    : m_data{ColumnType(column0), ColumnType(column1), ColumnType(column2)}
{
}
// clang-format on

// clang-format off
template <typename T>
template <typename U0, typename W0,
          typename U1, typename W1,
          typename U2, typename W2>
inline constexpr Matrix<3, 4, T>::Matrix(const Vector<3, U0>& vector0, const W0& w0,
                                         const Vector<3, U1>& vector1, const W1& w1,
                                         const Vector<3, U2>& vector2, const W2& w2)
    : m_data{ColumnType(vector0, w0),
             ColumnType(vector1, w1),
             ColumnType(vector2, w2)}
{
}
// clang-format on

// clang-format off
template <typename T>
template <typename X0, typename U0,
          typename X1, typename U1,
          typename X2, typename U2>
inline constexpr Matrix<3, 4, T>::Matrix(const X0& x0, const Vector<3, U0>& vector0,
                                         const X1& x1, const Vector<3, U1>& vector1,
                                         const X2& x2, const Vector<3, U2>& vector2)
    : m_data{ColumnType(x0, vector0),
             ColumnType(x1, vector1),
             ColumnType(x2, vector2)}
{
}
// clang-format on

// clang-format off
template <typename T>
template <typename U00, typename U01,
          typename U10, typename U11,
          typename U20, typename U21>
inline constexpr Matrix<3, 4, T>::Matrix(const Vector<2, U00>& vector00, const Vector<2, U01>& vector01,
                                         const Vector<2, U10>& vector10, const Vector<2, U11>& vector11,
                                         const Vector<2, U20>& vector20, const Vector<2, U21>& vector21)
    : m_data{ColumnType(vector00, vector01),
             ColumnType(vector10, vector11),
             ColumnType(vector20, vector21)}
{
}
// clang-format on

// clang-format off
template <typename T>
template <typename U0, typename Z0, typename W0,
          typename U1, typename Z1, typename W1,
          typename U2, typename Z2, typename W2>
inline constexpr Matrix<3, 4, T>::Matrix(const Vector<2, U0>& vector0, const Z0& z0, const W0& w0,
                                         const Vector<2, U1>& vector1, const Z1& z1, const W1& w1,
                                         const Vector<2, U2>& vector2, const Z2& z2, const W2& w2)
    : m_data{ColumnType(vector0, z0, w0),
             ColumnType(vector1, z1, w1),
             ColumnType(vector2, z2, w2)}
{
}
// clang-format on

// clang-format off
template <typename T>
template <typename X0, typename U0, typename W0,
          typename X1, typename U1, typename W1,
          typename X2, typename U2, typename W2>
inline constexpr Matrix<3, 4, T>::Matrix(const X0& x0, const Vector<2, U0>& vector0, const W0& w0,
                                         const X1& x1, const Vector<2, U1>& vector1, const W1& w1,
                                         const X2& x2, const Vector<2, U2>& vector2, const W2& w2)
    : m_data{ColumnType(x0, vector0, w0),
             ColumnType(x1, vector1, w1),
             ColumnType(x2, vector2, w2)}
{
}
// clang-format on

// clang-format off
template <typename T>
template <typename X0, typename Y0, typename U0,
          typename X1, typename Y1, typename U1,
          typename X2, typename Y2, typename U2>
inline constexpr Matrix<3, 4, T>::Matrix(const X0& x0, const Y0& y0, const Vector<2, U0>& vector0,
                                         const X1& x1, const Y1& y1, const Vector<2, U1>& vector1,
                                         const X2& x2, const Y2& y2, const Vector<2, U2>& vector2)
    : m_data{ColumnType(x0, y0, vector0),
             ColumnType(x1, y1, vector1),
             ColumnType(x2, y2, vector2)}
{
}
// clang-format on

template <typename T>
template <std::size_t C, std::size_t R, typename U>
inline constexpr Matrix<3, 4, T>::Matrix(const Matrix<C, R, U>& other)
    : m_data{matrix_type_details::get_column<0, C>(other, ColumnType(1, 0, 0, 0)),
             matrix_type_details::get_column<1, C>(other, ColumnType(0, 1, 0, 0)),
             matrix_type_details::get_column<2, C>(other, ColumnType(0, 0, 1, 0))}
{}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name Matrix<3, 4, T> operators.
/// @{
////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline typename Matrix<3, 4, T>::ColumnType& Matrix<3, 4, T>::operator[](std::size_t index)
{
    assert(index < 3);
    return m_data[index];
}

template <typename T>
inline const typename Matrix<3, 4, T>::ColumnType& Matrix<3, 4, T>::operator[](std::size_t index) const
{
    assert(index < 3);
    return m_data[index];
}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name Matrix<3, 4, T> methods.
/// @{
////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline constexpr std::size_t Matrix<3, 4, T>::size() const noexcept
{
    return 3;
}

template <typename T>
inline typename Matrix<3, 4, T>::ValueType* Matrix<3, 4, T>::data() noexcept
{
    return m_data[0].data();
}

template <typename T>
const typename Matrix<3, 4, T>::ValueType* Matrix<3, 4, T>::data() const noexcept
{
    return m_data[0].data();
}

template <typename T>
inline typename Matrix<3, 4, T>::ColumnType Matrix<3, 4, T>::column(std::size_t index) const noexcept
{
    assert(index < 3);
    return m_data[index];
}

template <typename T>
inline typename Matrix<3, 4, T>::RowType Matrix<3, 4, T>::row(std::size_t index) const noexcept
{
    assert(index < 4);
    return Matrix<3, 4, T>::RowType(m_data[0][index], m_data[1][index], m_data[2][index]);
}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name Matrix<3, 3, T> constructors.
/// @{
////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline constexpr Matrix<3, 3, T>::Matrix() noexcept
    : Matrix(T{1})
{}

// clang-format off
template <typename T>
inline constexpr Matrix<3, 3, T>::Matrix(const T& value00, const T& value01, const T& value02,
                                         const T& value10, const T& value11, const T& value12,
                                         const T& value20, const T& value21, const T& value22)
    : m_data{ColumnType(value00, value01, value02),
             ColumnType(value10, value11, value12),
             ColumnType(value20, value21, value22)}
{
}
// clang-format on

// clang-format off
template <typename T>
inline constexpr Matrix<3, 3, T>::Matrix(const T& value) noexcept
    : m_data{ColumnType(value, 0, 0),
             ColumnType(0, value, 0),
             ColumnType(0, 0, value)}
{
}
// clang-format on

template <typename T>
template <typename U>
inline Matrix<3, 3, T>::Matrix(const U* pointer)
    : m_data{ColumnType(pointer), ColumnType(pointer + 3), ColumnType(pointer + 6)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

template <typename T>
template <typename U>
inline Matrix<3, 3, T>::Matrix(U* pointer)
    : m_data{ColumnType(pointer), ColumnType(pointer + 3), ColumnType(pointer + 6)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

// clang-format off
template <typename T>
template <typename U0, typename U1, typename U2>
inline constexpr Matrix<3, 3, T>::Matrix(const Vector<4, U0>& column0,
                                         const Vector<4, U1>& column1,
                                         const Vector<4, U2>& column2)
    : m_data{ColumnType(column0), ColumnType(column1), ColumnType(column2)}
{
}
// clang-format on

// clang-format off
template <typename T>
template <typename U0, typename U1, typename U2>
inline constexpr Matrix<3, 3, T>::Matrix(const Vector<3, U0>& column0,
                                         const Vector<3, U1>& column1,
                                         const Vector<3, U2>& column2)
    : m_data{ColumnType(column0), ColumnType(column1), ColumnType(column2)}
{
}
// clang-format on

// clang-format off
template <typename T>
template <typename U0, typename Z0,
          typename U1, typename Z1,
          typename U2, typename Z2>
inline constexpr Matrix<3, 3, T>::Matrix(const Vector<2, U0>& vector0, const Z0& z0,
                                         const Vector<2, U1>& vector1, const Z1& z1,
                                         const Vector<2, U2>& vector2, const Z2& z2)
    : m_data{ColumnType(vector0, z0),
             ColumnType(vector1, z1),
             ColumnType(vector2, z2)}
{
}
// clang-format on

// clang-format off
template <typename T>
template <typename X0, typename U0,
          typename X1, typename U1,
          typename X2, typename U2>
inline constexpr Matrix<3, 3, T>::Matrix(const X0& x0, const Vector<2, U0>& vector0,
                                         const X1& x1, const Vector<2, U1>& vector1,
                                         const X2& x2, const Vector<2, U2>& vector2)
    : m_data{ColumnType(x0, vector0),
             ColumnType(x1, vector1),
             ColumnType(x2, vector2)}
{
}
// clang-format on

template <typename T>
template <std::size_t C, std::size_t R, typename U>
inline constexpr Matrix<3, 3, T>::Matrix(const Matrix<C, R, U>& other)
    : m_data{matrix_type_details::get_column<0, C>(other, ColumnType(1, 0, 0)),
             matrix_type_details::get_column<1, C>(other, ColumnType(0, 1, 0)),
             matrix_type_details::get_column<2, C>(other, ColumnType(0, 0, 1))}
{}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name Matrix<3, 3, T> operators.
/// @{
////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline typename Matrix<3, 3, T>::ColumnType& Matrix<3, 3, T>::operator[](std::size_t index)
{
    assert(index < 3);
    return m_data[index];
}

template <typename T>
inline const typename Matrix<3, 3, T>::ColumnType& Matrix<3, 3, T>::operator[](std::size_t index) const
{
    assert(index < 3);
    return m_data[index];
}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name Matrix<3, 3, T> methods.
/// @{
////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline constexpr std::size_t Matrix<3, 3, T>::size() const noexcept
{
    return 3;
}

template <typename T>
inline typename Matrix<3, 3, T>::ValueType* Matrix<3, 3, T>::data() noexcept
{
    return m_data[0].data();
}

template <typename T>
const typename Matrix<3, 3, T>::ValueType* Matrix<3, 3, T>::data() const noexcept
{
    return m_data[0].data();
}

template <typename T>
inline typename Matrix<3, 3, T>::ColumnType Matrix<3, 3, T>::column(std::size_t index) const noexcept
{
    assert(index < 3);
    return m_data[index];
}

template <typename T>
inline typename Matrix<3, 3, T>::RowType Matrix<3, 3, T>::row(std::size_t index) const noexcept
{
    assert(index < 3);
    return Matrix<3, 3, T>::RowType(m_data[0][index], m_data[1][index], m_data[2][index]);
}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name Matrix<3, 2, T> constructors.
/// @{
////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline constexpr Matrix<3, 2, T>::Matrix() noexcept
    : Matrix(T{1})
{}

// clang-format off
template <typename T>
inline constexpr Matrix<3, 2, T>::Matrix(const T& value00, const T& value01,
                                         const T& value10, const T& value11,
                                         const T& value20, const T& value21)
    : m_data{ColumnType(value00, value01),
             ColumnType(value10, value11),
             ColumnType(value20, value21)}
{
}
// clang-format on

// clang-format off
 template <typename T>
 inline constexpr Matrix<3, 2, T>::Matrix(const T& value) noexcept
    : m_data{ColumnType(value, 0),
             ColumnType(0, value),
             ColumnType(0, 0)}
 {
 }
// clang-format on

template <typename T>
template <typename U>
inline Matrix<3, 2, T>::Matrix(const U* pointer)
    : m_data{ColumnType(pointer), ColumnType(pointer + 2), ColumnType(pointer + 4)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

template <typename T>
template <typename U>
inline Matrix<3, 2, T>::Matrix(U* pointer)
    : m_data{ColumnType(pointer), ColumnType(pointer + 2), ColumnType(pointer + 4)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

template <typename T>
template <typename U0, typename U1, typename U2>
inline constexpr Matrix<3, 2, T>::Matrix(const Vector<4, U0>& column0,
                                         const Vector<4, U1>& column1,
                                         const Vector<4, U2>& column2)
    : m_data{ColumnType(column0), ColumnType(column1), ColumnType(column2)}
{}

template <typename T>
template <typename U0, typename U1, typename U2>
inline constexpr Matrix<3, 2, T>::Matrix(const Vector<3, U0>& column0,
                                         const Vector<3, U1>& column1,
                                         const Vector<3, U2>& column2)
    : m_data{ColumnType(column0), ColumnType(column1), ColumnType(column2)}
{}

template <typename T>
template <typename U0, typename U1, typename U2>
inline constexpr Matrix<3, 2, T>::Matrix(const Vector<2, U0>& column0,
                                         const Vector<2, U1>& column1,
                                         const Vector<2, U2>& column2)
    : m_data{ColumnType(column0), ColumnType(column1), ColumnType(column2)}
{}

template <typename T>
template <std::size_t C, std::size_t R, typename U>
inline constexpr Matrix<3, 2, T>::Matrix(const Matrix<C, R, U>& other)
    : m_data{matrix_type_details::get_column<0, C>(other, ColumnType(1, 0)),
             matrix_type_details::get_column<1, C>(other, ColumnType(0, 1)),
             matrix_type_details::get_column<2, C>(other, ColumnType(0, 0))}
{}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name Matrix<3, 2, T> operators.
/// @{
////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline typename Matrix<3, 2, T>::ColumnType& Matrix<3, 2, T>::operator[](std::size_t index)
{
    assert(index < 3);
    return m_data[index];
}

template <typename T>
inline const typename Matrix<3, 2, T>::ColumnType& Matrix<3, 2, T>::operator[](std::size_t index) const
{
    assert(index < 3);
    return m_data[index];
}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name Matrix<3, 2, T> methods.
/// @{
////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline constexpr std::size_t Matrix<3, 2, T>::size() const noexcept
{
    return 3;
}

template <typename T>
inline typename Matrix<3, 2, T>::ValueType* Matrix<3, 2, T>::data() noexcept
{
    return m_data[0].data();
}

template <typename T>
const typename Matrix<3, 2, T>::ValueType* Matrix<3, 2, T>::data() const noexcept
{
    return m_data[0].data();
}

template <typename T>
inline typename Matrix<3, 2, T>::ColumnType Matrix<3, 2, T>::column(std::size_t index) const noexcept
{
    assert(index < 3);
    return m_data[index];
}

template <typename T>
inline typename Matrix<3, 2, T>::RowType Matrix<3, 2, T>::row(std::size_t index) const noexcept
{
    assert(index < 2);
    return Matrix<3, 2, T>::RowType(m_data[0][index], m_data[1][index], m_data[2][index]);
}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name Matrix<2, 4, T> constructors.
/// @{
////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline constexpr Matrix<2, 4, T>::Matrix() noexcept
    : Matrix(T{1})
{}

// clang-format off
template <typename T>
inline constexpr Matrix<2, 4, T>::Matrix(const T& value00, const T& value01, const T& value02, const T& value03,
                                         const T& value10, const T& value11, const T& value12, const T& value13)
    : m_data{ColumnType(value00, value01, value02, value03),
             ColumnType(value10, value11, value12, value13)}
{
}
// clang-format on

// clang-format off
template <typename T>
inline constexpr Matrix<2, 4, T>::Matrix(const T& value) noexcept
    : m_data{ColumnType(value, 0, 0, 0),
             ColumnType(0, value, 0, 0)}
{
}
// clang-format on

template <typename T>
template <typename U>
inline Matrix<2, 4, T>::Matrix(const U* pointer)
    : m_data{ColumnType(pointer), ColumnType(pointer + 4)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

template <typename T>
template <typename U>
inline Matrix<2, 4, T>::Matrix(U* pointer)
    : m_data{ColumnType(pointer), ColumnType(pointer + 4)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

template <typename T>
template <typename U0, typename U1>
inline constexpr Matrix<2, 4, T>::Matrix(const Vector<4, U0>& column0, const Vector<4, U1>& column1)
    : m_data{ColumnType(column0), ColumnType(column1)}
{}

// clang-format off
template <typename T>
template <typename U0, typename W0,
          typename U1, typename W1>
inline constexpr Matrix<2, 4, T>::Matrix(const Vector<3, U0>& vector0, const W0& w0,
                                         const Vector<3, U1>& vector1, const W1& w1)
    : m_data{ColumnType(vector0, w0),
             ColumnType(vector1, w1)}
{
}
// clang-format on

// clang-format off
template <typename T>
template <typename X0, typename U0,
          typename X1, typename U1>
inline constexpr Matrix<2, 4, T>::Matrix(const X0& x0, const Vector<3, U0>& vector0,
                                         const X1& x1, const Vector<3, U1>& vector1)
    : m_data{ColumnType(x0, vector0),
             ColumnType(x1, vector1)}
{
}
// clang-format on

// clang-format off
template <typename T>
template <typename U00, typename U01,
          typename U10, typename U11>
inline constexpr Matrix<2, 4, T>::Matrix(const Vector<2, U00>& vector00, const Vector<2, U01>& vector01,
                                         const Vector<2, U10>& vector10, const Vector<2, U11>& vector11)
    : m_data{ColumnType(vector00, vector01),
             ColumnType(vector10, vector11)}
{
}
// clang-format on

// clang-format off
template <typename T>
template <typename U0, typename Z0, typename W0,
          typename U1, typename Z1, typename W1>
inline constexpr Matrix<2, 4, T>::Matrix(const Vector<2, U0>& vector0, const Z0& z0, const W0& w0,
                                         const Vector<2, U1>& vector1, const Z1& z1, const W1& w1)
    : m_data{ColumnType(vector0, z0, w0),
           ColumnType(vector1, z1, w1)}
{
}
// clang-format on

// clang-format off
template <typename T>
template <typename X0, typename U0, typename W0,
          typename X1, typename U1, typename W1>
inline constexpr Matrix<2, 4, T>::Matrix(const X0& x0, const Vector<2, U0>& vector0, const W0& w0,
                                         const X1& x1, const Vector<2, U1>& vector1, const W1& w1)
    : m_data{ColumnType(x0, vector0, w0),
             ColumnType(x1, vector1, w1)}
{
}
// clang-format on

// clang-format off
template <typename T>
template <typename X0, typename Y0, typename U0,
          typename X1, typename Y1, typename U1>
inline constexpr Matrix<2, 4, T>::Matrix(const X0& x0, const Y0& y0, const Vector<2, U0>& vector0,
                                         const X1& x1, const Y1& y1, const Vector<2, U1>& vector1)
    : m_data{ColumnType(x0, y0, vector0),
             ColumnType(x1, y1, vector1)}
{
}
// clang-format on

template <typename T>
template <std::size_t C, std::size_t R, typename U>
inline constexpr Matrix<2, 4, T>::Matrix(const Matrix<C, R, U>& other)
    : m_data{matrix_type_details::get_column<0, C>(other, ColumnType(1, 0, 0, 0)),
             matrix_type_details::get_column<1, C>(other, ColumnType(0, 1, 0, 0))}
{}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name Matrix<2, 4, T> operators.
/// @{
////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline typename Matrix<2, 4, T>::ColumnType& Matrix<2, 4, T>::operator[](std::size_t index)
{
    assert(index < 2);
    return m_data[index];
}

template <typename T>
inline const typename Matrix<2, 4, T>::ColumnType& Matrix<2, 4, T>::operator[](std::size_t index) const
{
    assert(index < 2);
    return m_data[index];
}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name Matrix<2, 4, T> methods.
/// @{
////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline constexpr std::size_t Matrix<2, 4, T>::size() const noexcept
{
    return 2;
}

template <typename T>
inline typename Matrix<2, 4, T>::ValueType* Matrix<2, 4, T>::data() noexcept
{
    return m_data[0].data();
}

template <typename T>
const typename Matrix<2, 4, T>::ValueType* Matrix<2, 4, T>::data() const noexcept
{
    return m_data[0].data();
}

template <typename T>
inline typename Matrix<2, 4, T>::ColumnType Matrix<2, 4, T>::column(std::size_t index) const noexcept
{
    assert(index < 2);
    return m_data[index];
}

template <typename T>
inline typename Matrix<2, 4, T>::RowType Matrix<2, 4, T>::row(std::size_t index) const noexcept
{
    assert(index < 4);
    return Matrix<2, 4, T>::RowType(m_data[0][index], m_data[1][index]);
}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name Matrix<2, 3, T> constructors.
/// @{
////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline constexpr Matrix<2, 3, T>::Matrix() noexcept
    : Matrix(T{1})
{}

// clang-format off
template <typename T>
inline constexpr Matrix<2, 3, T>::Matrix(const T& value00, const T& value01, const T& value02,
                                         const T& value10, const T& value11, const T& value12)
    : m_data{ColumnType(value00, value01, value02),
             ColumnType(value10, value11, value12)}
{
}
// clang-format on

// clang-format off
template <typename T>
inline constexpr Matrix<2, 3, T>::Matrix(const T& value) noexcept
    : m_data{ColumnType(value, 0, 0),
             ColumnType(0, value, 0)}
{
}
// clang-format on

template <typename T>
template <typename U>
inline Matrix<2, 3, T>::Matrix(const U* pointer)
    : m_data{ColumnType(pointer), ColumnType(pointer + 3)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

template <typename T>
template <typename U>
inline Matrix<2, 3, T>::Matrix(U* pointer)
    : m_data{ColumnType(pointer), ColumnType(pointer + 3)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

template <typename T>
template <typename U0, typename U1>
inline constexpr Matrix<2, 3, T>::Matrix(const Vector<4, U0>& column0, const Vector<4, U1>& column1)
    : m_data{ColumnType(column0), ColumnType(column1)}
{}

template <typename T>
template <typename U0, typename U1>
inline constexpr Matrix<2, 3, T>::Matrix(const Vector<3, U0>& column0, const Vector<3, U1>& column1)
    : m_data{ColumnType(column0), ColumnType(column1)}
{}

// clang-format off
template <typename T>
template <typename U0, typename Z0,
          typename U1, typename Z1>
inline constexpr Matrix<2, 3, T>::Matrix(const Vector<2, U0>& vector0, const Z0& z0,
                                         const Vector<2, U1>& vector1, const Z1& z1)
    : m_data{ColumnType(vector0, z0),
             ColumnType(vector1, z1)}
{
}
// clang-format on

// clang-format off
template <typename T>
template <typename X0, typename U0,
          typename X1, typename U1>
inline constexpr Matrix<2, 3, T>::Matrix(const X0& x0, const Vector<2, U0>& vector0,
                                         const X1& x1, const Vector<2, U1>& vector1)
    : m_data{ColumnType(x0, vector0),
             ColumnType(x1, vector1)}
{
}
// clang-format on

template <typename T>
template <std::size_t C, std::size_t R, typename U>
inline constexpr Matrix<2, 3, T>::Matrix(const Matrix<C, R, U>& other)
    : m_data{matrix_type_details::get_column<0, C>(other, ColumnType(1, 0, 0)),
             matrix_type_details::get_column<1, C>(other, ColumnType(0, 1, 0))}
{}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name Matrix<2, 3, T> operators.
/// @{
////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline typename Matrix<2, 3, T>::ColumnType& Matrix<2, 3, T>::operator[](std::size_t index)
{
    assert(index < 2);
    return m_data[index];
}

template <typename T>
inline const typename Matrix<2, 3, T>::ColumnType& Matrix<2, 3, T>::operator[](std::size_t index) const
{
    assert(index < 2);
    return m_data[index];
}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name Matrix<2, 3, T> methods.
/// @{
////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline constexpr std::size_t Matrix<2, 3, T>::size() const noexcept
{
    return 2;
}

template <typename T>
inline typename Matrix<2, 3, T>::ValueType* Matrix<2, 3, T>::data() noexcept
{
    return m_data[0].data();
}

template <typename T>
const typename Matrix<2, 3, T>::ValueType* Matrix<2, 3, T>::data() const noexcept
{
    return m_data[0].data();
}

template <typename T>
inline typename Matrix<2, 3, T>::ColumnType Matrix<2, 3, T>::column(std::size_t index) const noexcept
{
    assert(index < 2);
    return m_data[index];
}

template <typename T>
inline typename Matrix<2, 3, T>::RowType Matrix<2, 3, T>::row(std::size_t index) const noexcept
{
    assert(index < 3);
    return Matrix<2, 3, T>::RowType(m_data[0][index], m_data[1][index]);
}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name Matrix<2, 2, T> constructors.
/// @{
////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline constexpr Matrix<2, 2, T>::Matrix() noexcept
    : Matrix(T{1})
{}

// clang-format off
template <typename T>
inline constexpr Matrix<2, 2, T>::Matrix(const T& value00, const T& value01,
                                         const T& value10, const T& value11)
    : m_data{ColumnType(value00, value01),
             ColumnType(value10, value11)}
{
}
// clang-format on

// clang-format off
template <typename T>
inline constexpr Matrix<2, 2, T>::Matrix(const T& value) noexcept
    : m_data{ColumnType(value, 0),
             ColumnType(0, value)}
{
}
// clang-format on

template <typename T>
template <typename U>
inline Matrix<2, 2, T>::Matrix(const U* pointer)
    : m_data{ColumnType(pointer), ColumnType(pointer + 2)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

template <typename T>
template <typename U>
inline Matrix<2, 2, T>::Matrix(U* pointer)
    : m_data{ColumnType(pointer), ColumnType(pointer + 2)}
{
    static_assert(std::is_same<T, U>::value, "Only pointer for the same type is acceptable.");
}

template <typename T>
template <typename U0, typename U1>
inline constexpr Matrix<2, 2, T>::Matrix(const Vector<4, U0>& column0, const Vector<4, U1>& column1)
    : m_data{ColumnType(column0), ColumnType(column1)}
{}

template <typename T>
template <typename U0, typename U1>
inline constexpr Matrix<2, 2, T>::Matrix(const Vector<3, U0>& column0, const Vector<3, U1>& column1)
    : m_data{ColumnType(column0), ColumnType(column1)}
{}

template <typename T>
template <typename U0, typename U1>
inline constexpr Matrix<2, 2, T>::Matrix(const Vector<2, U0>& column0, const Vector<2, U1>& column1)
    : m_data{ColumnType(column0), ColumnType(column1)}
{}

template <typename T>
template <std::size_t C, std::size_t R, typename U>
inline constexpr Matrix<2, 2, T>::Matrix(const Matrix<C, R, U>& other)
    : m_data{static_cast<ColumnType>(other[0]), static_cast<ColumnType>(other[1])}
{}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name Matrix<2, 2, T> operators.
/// @{
////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline typename Matrix<2, 2, T>::ColumnType& Matrix<2, 2, T>::operator[](std::size_t index)
{
    assert(index < 2);
    return m_data[index];
}

template <typename T>
inline const typename Matrix<2, 2, T>::ColumnType& Matrix<2, 2, T>::operator[](std::size_t index) const
{
    assert(index < 2);
    return m_data[index];
}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name Matrix<2, 2, T> methods.
/// @{
////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline constexpr std::size_t Matrix<2, 2, T>::size() const noexcept
{
    return 2;
}

template <typename T>
inline typename Matrix<2, 2, T>::ValueType* Matrix<2, 2, T>::data() noexcept
{
    return m_data[0].data();
}

template <typename T>
const typename Matrix<2, 2, T>::ValueType* Matrix<2, 2, T>::data() const noexcept
{
    return m_data[0].data();
}

template <typename T>
inline typename Matrix<2, 2, T>::ColumnType Matrix<2, 2, T>::column(std::size_t index) const noexcept
{
    assert(index < 2);
    return m_data[index];
}

template <typename T>
inline typename Matrix<2, 2, T>::RowType Matrix<2, 2, T>::row(std::size_t index) const noexcept
{
    assert(index < 2);
    return Matrix<2, 2, T>::RowType(m_data[0][index], m_data[1][index]);
}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name Matrix operators and functions.
/// @addtogroup math_matrix_implementation
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name Matrix unary operators.
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief Unary plus operator.
///
/// @param Matrix Matrix to return.
///
/// @return The same Matrix.
////////////////////////////////////////////////////////////////////////////////
template <std::size_t C, std::size_t R, typename T>
inline Matrix<C, R, T> operator+(const Matrix<C, R, T>& Matrix)
{
    return Matrix;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Unary minus operator.
///
/// @param Matrix Matrix to invert.
///
/// @return Matrix witch is equal to `Matrix * -1`.
////////////////////////////////////////////////////////////////////////////////
template <std::size_t C, std::size_t R, typename T>
inline Matrix<C, R, T> operator-(Matrix<C, R, T> Matrix)
{
    return Matrix *= -T{1};
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Addition assignment operator.
///
/// @param lhs First addend.
/// @param rhs Second addend.
///
/// @return Reference to component-wise sum of two matrices.
////////////////////////////////////////////////////////////////////////////////
template <std::size_t C, std::size_t R, typename T, typename U>
inline Matrix<C, R, T>& operator+=(Matrix<C, R, T>& lhs, const Matrix<C, R, U>& rhs)
{
    for (std::size_t i = 0; i < C; ++i) {
        lhs[i] += rhs[i];
    }
    return lhs;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Subtractions assignment operator.
///
/// @param lhs Vector to subtract from.
/// @param rhs Vector to subtract.
///
/// @return Reference to component-wise difference of two matrices.
////////////////////////////////////////////////////////////////////////////////
template <std::size_t C, std::size_t R, typename T, typename U>
inline Matrix<C, R, T>& operator-=(Matrix<C, R, T>& lhs, const Matrix<C, R, U>& rhs)
{
    for (std::size_t i = 0; i < C; ++i) {
        lhs[i] -= rhs[i];
    }
    return lhs;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Multiplication assignment operator.
///
/// @param lhs First multiplier.
/// @param rhs Second multiplier.
///
/// @return Reference to product of two matrices.
////////////////////////////////////////////////////////////////////////////////
template <std::size_t C, std::size_t R, typename T, typename U>
inline Matrix<C, R, T>& operator*=(Matrix<C, R, T>& lhs, const Matrix<C, C, U>& rhs)
{
    return (lhs = lhs * rhs);
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Addition assignment operator.
///
/// @param lhs First addend.
/// @param rhs Second addend.
///
/// @return Reference to component-wise sum of Matrix and scalar value.
////////////////////////////////////////////////////////////////////////////////
template <std::size_t C,
          std::size_t R,
          typename T,
          typename U,
          typename std::enable_if<std::is_arithmetic<U>::value, int32>::type = 0>
inline Matrix<C, R, T>& operator+=(Matrix<C, R, T>& lhs, const U& rhs)
{
    for (std::size_t i = 0; i < C; ++i) {
        lhs[i] += rhs;
    }
    return lhs;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Subtractions assignment operator.
///
/// @param lhs Vector to subtract from.
/// @param rhs Scalar value to subtract.
///
/// @return Reference to component-wise difference of the Matrix and scalar value.
////////////////////////////////////////////////////////////////////////////////
template <std::size_t C,
          std::size_t R,
          typename T,
          typename U,
          typename std::enable_if<std::is_arithmetic<U>::value, int32>::type = 0>
inline Matrix<C, R, T>& operator-=(Matrix<C, R, T>& lhs, const U& rhs)
{
    for (std::size_t i = 0; i < C; ++i) {
        lhs[i] -= rhs;
    }
    return lhs;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Multiplication assignment operator.
///
/// @param lhs First multiplier.
/// @param rhs Second multiplier.
///
/// @return Reference to component-wise product of the Matrix and scalar value.
////////////////////////////////////////////////////////////////////////////////
template <std::size_t C,
          std::size_t R,
          typename T,
          typename U,
          typename std::enable_if<std::is_arithmetic<U>::value, int32>::type = 0>
inline Matrix<C, R, T>& operator*=(Matrix<C, R, T>& lhs, const U& rhs)
{
    for (std::size_t i = 0; i < C; ++i) {
        lhs[i] *= rhs;
    }
    return lhs;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Division assignment operator.
///
/// @param lhs Dividend vector.
/// @param rhs Divider scalar value.
///
/// @return Reference to component-wise quotient of the Matrix and scalar value.
////////////////////////////////////////////////////////////////////////////////
template <std::size_t C,
          std::size_t R,
          typename T,
          typename U,
          typename std::enable_if<std::is_arithmetic<U>::value, int32>::type = 0>
inline Matrix<C, R, T>& operator/=(Matrix<C, R, T>& lhs, const U& rhs)
{
    for (std::size_t i = 0; i < C; ++i) {
        lhs[i] /= rhs;
    }
    return lhs;
}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name Common binary operator for matrices.
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief Addition operator.
///
/// @param lhs First addend.
/// @param rhs Second addend.
///
/// @return Component-wise sum of two matrices.
////////////////////////////////////////////////////////////////////////////////
template <std::size_t C,
          std::size_t R,
          typename T,
          typename U,
          typename RT = typename matrix_type_details::common_type<T, U>::type>
inline const Matrix<C, R, RT> operator+(const Matrix<C, R, T>& lhs, const Matrix<C, R, U>& rhs) noexcept
{
    Matrix<C, R, RT> temp{lhs};
    return temp += rhs;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Subtraction operator.
///
/// @param lhs Vector to subtract from.
/// @param rhs Scalar value to subtract.
///
/// @return Component-wise difference of two matrices.
////////////////////////////////////////////////////////////////////////////////
template <std::size_t C,
          std::size_t R,
          typename T,
          typename U,
          typename RT = typename matrix_type_details::common_type<T, U>::type>
inline const Matrix<C, R, RT> operator-(const Matrix<C, R, T>& lhs, const Matrix<C, R, U>& rhs) noexcept
{
    Matrix<C, R, RT> temp{lhs};
    return temp -= rhs;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Multiplication operator.
///
/// @param lhs Matrix of floating-point or integral type.
/// @param rhs Matrix of floating-point or integral type.
///
/// @return Product of two matrices.
////////////////////////////////////////////////////////////////////////////////
template <std::size_t C,
          std::size_t R,
          std::size_t N,
          typename T,
          typename U,
          typename RT = typename matrix_type_details::common_type<T, U>::type>
inline const Matrix<N, R, RT> operator*(const Matrix<C, R, T>& lhs, const Matrix<N, C, U>& rhs) noexcept
{
    Matrix<N, R, RT> temp(0);

    for (std::size_t n = 0; n < N; ++n) {
        for (std::size_t c = 0; c < C; ++c) {
            for (std::size_t r = 0; r < R; ++r) {
                temp[n][r] += lhs[c][r] * rhs[n][c];
            }
        }
    }

    return temp;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Multiplication operator.
///
/// @param lhs Vector of floating-point or integral type.
/// @param rhs Matrix of floating-point or integral type.
///
/// @return Product of vector and Matrix.
////////////////////////////////////////////////////////////////////////////////
template <std::size_t C,
          std::size_t R,
          typename T,
          typename U,
          typename RT = typename matrix_type_details::common_type<T, U>::type>
inline const Vector<C, RT> operator*(const Vector<R, T>& lhs, const Matrix<C, R, U>& rhs) noexcept
{
    Vector<C, RT> temp(0);

    for (std::size_t c = 0; c < C; ++c) {
        for (std::size_t r = 0; r < R; ++r) {
            temp[c] += lhs[r] * rhs[c][r];
        }
    }

    return temp;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Multiplication operator.
///
/// @param lhs Matrix of floating-point or integral type.
/// @param rhs Vector of floating-point or integral type.
///
/// @return Product of vector and Matrix.
////////////////////////////////////////////////////////////////////////////////
template <std::size_t C,
          std::size_t R,
          typename T,
          typename U,
          typename RT = typename matrix_type_details::common_type<T, U>::type>
inline const Vector<R, RT> operator*(const Matrix<C, R, T>& lhs, const Vector<C, U>& rhs) noexcept
{
    Vector<R, RT> temp(0);

    for (std::size_t r = 0; r < R; ++r) {
        for (std::size_t c = 0; c < C; ++c) {
            temp[r] += lhs[c][r] * rhs[c];
        }
    }

    return temp;
}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name Common binary operators with matrices and scalar values.
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief Addition operator.
///
/// @param lhs Matrix of floating-point or integral type.
/// @param rhs Value of floating-point or integral type.
///
/// @return Component-wise sum of Matrix and scalar value.
////////////////////////////////////////////////////////////////////////////////
template <std::size_t C,
          std::size_t R,
          typename T,
          typename U,
          typename RT = typename matrix_type_details::common_type<T, U>::type>
inline const Matrix<C, R, RT> operator+(const Matrix<C, R, T>& lhs, const U& rhs) noexcept
{
    Matrix<C, R, RT> temp{lhs};
    return temp += rhs;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Subtractions operator.
///
/// @param lhs Matrix of floating-point or integral type.
/// @param rhs Value of floating-point or integral type.
///
/// @return Component-wise difference of Matrix and scalar value.
////////////////////////////////////////////////////////////////////////////////
template <std::size_t C,
          std::size_t R,
          typename T,
          typename U,
          typename RT = typename matrix_type_details::common_type<T, U>::type>
inline const Matrix<C, R, RT> operator-(const Matrix<C, R, T>& lhs, const U& rhs) noexcept
{
    Matrix<C, R, RT> temp{lhs};
    return temp -= rhs;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Multiplication operator.
///
/// @param lhs Matrix of floating-point or integral type.
/// @param rhs Value of floating-point or integral type.
///
/// @return Component-wise product of Matrix and scalar value.
////////////////////////////////////////////////////////////////////////////////
template <std::size_t C,
          std::size_t R,
          typename T,
          typename U,
          typename RT = typename matrix_type_details::common_type<T, U>::type>
inline const Matrix<C, R, RT> operator*(const Matrix<C, R, T>& lhs, const U& rhs) noexcept
{
    Matrix<C, R, RT> temp{lhs};
    return temp *= rhs;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Division operator.
///
/// @param lhs Matrix of floating-point or integral type.
/// @param rhs Value of floating-point or integral type.
///
/// @return Component-wise quotient of Matrix and scalar value.
////////////////////////////////////////////////////////////////////////////////
template <std::size_t C,
          std::size_t R,
          typename T,
          typename U,
          typename RT = typename matrix_type_details::common_type<T, U>::type>
inline const Matrix<C, R, RT> operator/(const Matrix<C, R, T>& lhs, const U& rhs) noexcept
{
    Matrix<C, R, RT> temp{lhs};
    return temp /= rhs;
}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name Common binary operators with scalar values and matrices.
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief Addition operator.
///
/// @param lhs Value of floating-point or integral type.
/// @param rhs Matrix of floating-point or integral type.
///
/// @return Component-wise sum of Matrix and scalar value.
////////////////////////////////////////////////////////////////////////////////
template <std::size_t C,
          std::size_t R,
          typename T,
          typename U,
          typename RT = typename matrix_type_details::common_type<T, U>::type>
inline const Matrix<C, R, RT> operator+(const T& lhs, const Matrix<C, R, U>& rhs) noexcept
{
    Matrix<C, R, RT> temp{0};

    for (std::size_t i = 0; i < C; ++i) {
        temp[i] = lhs + rhs[i];
    }

    return temp;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Subtractions operator.
///
/// @param lhs Value of floating-point or integral type.
/// @param rhs Matrix of floating-point or integral type.
///
/// @return Component-wise difference of Matrix and scalar value.
////////////////////////////////////////////////////////////////////////////////
template <std::size_t C,
          std::size_t R,
          typename T,
          typename U,
          typename RT = typename matrix_type_details::common_type<T, U>::type>
inline const Matrix<C, R, RT> operator-(const T& lhs, const Matrix<C, R, U>& rhs) noexcept
{
    Matrix<C, R, RT> temp{0};

    for (std::size_t i = 0; i < C; ++i) {
        temp[i] = lhs - rhs[i];
    }

    return temp;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Multiplication operator.
///
/// @param lhs Value of floating-point or integral type.
/// @param rhs Matrix of floating-point or integral type.
///
/// @return Component-wise product of Matrix and scalar value.
////////////////////////////////////////////////////////////////////////////////
template <std::size_t C,
          std::size_t R,
          typename T,
          typename U,
          typename RT = typename matrix_type_details::common_type<T, U>::type>
inline const Matrix<C, R, RT> operator*(const T& lhs, const Matrix<C, R, U>& rhs) noexcept
{
    Matrix<C, R, RT> temp{0};

    for (std::size_t i = 0; i < C; ++i) {
        temp[i] = lhs * rhs[i];
    }

    return temp;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Division operator.
///
/// @param lhs Value of floating-point or integral type.
/// @param rhs Matrix of floating-point or integral type.
///
/// @return Component-wise quotient of Matrix and scalar value.
////////////////////////////////////////////////////////////////////////////////
template <std::size_t C,
          std::size_t R,
          typename T,
          typename U,
          typename RT = typename matrix_type_details::common_type<T, U>::type>
inline const Matrix<C, R, RT> operator/(const T& lhs, const Matrix<C, R, U>& rhs) noexcept
{
    Matrix<C, R, RT> temp{0};

    for (std::size_t i = 0; i < C; ++i) {
        temp[i] = lhs / rhs[i];
    }

    return temp;
}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name Matrix equality operators.
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief Equality operator.
///
/// @param lhs Matrix of floating-point or integral type.
/// @param rhs Matrix of floating-point or integral type.
///
/// @return `true` if lhs equals rhs, otherwise `false`.
////////////////////////////////////////////////////////////////////////////////
template <std::size_t R, typename T>
inline constexpr bool operator==(const Matrix<4, R, T>& lhs, const Matrix<4, R, T>& rhs)
{
    return lhs[0] == rhs[0] && lhs[1] == rhs[1] && lhs[2] == rhs[2] && lhs[3] == rhs[3];
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Equality operator.
///
/// @param lhs Matrix of floating-point or integral type.
/// @param rhs Matrix of floating-point or integral type.
///
/// @return `true` if lhs equals rhs, otherwise `false`.
////////////////////////////////////////////////////////////////////////////////
template <std::size_t R, typename T>
inline constexpr bool operator==(const Matrix<3, R, T>& lhs, const Matrix<3, R, T>& rhs)
{
    return lhs[0] == rhs[0] && lhs[1] == rhs[1] && lhs[2] == rhs[2];
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Equality operator.
///
/// @param lhs Matrix of floating-point or integral type.
/// @param rhs Matrix of floating-point or integral type.
///
/// @return `true` if lhs equals rhs, otherwise `false`.
////////////////////////////////////////////////////////////////////////////////
template <std::size_t R, typename T>
inline constexpr bool operator==(const Matrix<2, R, T>& lhs, const Matrix<2, R, T>& rhs)
{
    return lhs[0] == rhs[0] && lhs[1] == rhs[1];
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Equality operator.
///
/// @param lhs Matrix of floating-point or integral type.
/// @param rhs Matrix of floating-point or integral type.
///
/// @return `true` if lhs isn't equal rhs, otherwise `false`.
////////////////////////////////////////////////////////////////////////////////
template <std::size_t R, typename T>
inline constexpr bool operator!=(const Matrix<4, R, T>& lhs, const Matrix<4, R, T>& rhs)
{
    return (lhs[0] != rhs[0]) || (lhs[1] != rhs[1]) || (lhs[2] != rhs[2]) || (lhs[3] != rhs[3]);
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Equality operator.
///
/// @param lhs Matrix of floating-point or integral type.
/// @param rhs Matrix of floating-point or integral type.
///
/// @return `true` if lhs isn't equal rhs, otherwise `false`.
////////////////////////////////////////////////////////////////////////////////
template <std::size_t R, typename T>
inline constexpr bool operator!=(const Matrix<3, R, T>& lhs, const Matrix<3, R, T>& rhs)
{
    return (lhs[0] != rhs[0]) || (lhs[1] != rhs[1]) || (lhs[2] != rhs[2]);
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Equality operator.
///
/// @param lhs Matrix of floating-point or integral type.
/// @param rhs Matrix of floating-point or integral type.
///
/// @return `true` if lhs isn't equal rhs, otherwise `false`.
////////////////////////////////////////////////////////////////////////////////
template <std::size_t R, typename T>
inline constexpr bool operator!=(const Matrix<2, R, T>& lhs, const Matrix<2, R, T>& rhs)
{
    return (lhs[0] != rhs[0]) || (lhs[1] != rhs[1]);
}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

} // namespace framework::math

#endif
