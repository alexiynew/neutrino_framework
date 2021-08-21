////////////////////////////////////////////////////////////////////////////////
/// @file
/// @brief Main file in math module.
/// @author Fedorov Alexey
/// @date 04.03.2017
///
/// You should include this file only.
/// It includes all math stuff and declarations of main types for vectors
/// and matrices.
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

#ifndef FRAMEWORK_MATH_MATH_HPP
#define FRAMEWORK_MATH_MATH_HPP

#define FRAMEWORK_MATH_DETAILS

#include <math/inc/common_functions.hpp>
#include <math/inc/constants.hpp>
#include <math/inc/exponential_functions.hpp>
#include <math/inc/geometric_functions.hpp>
#include <math/inc/matrix_functions.hpp>
#include <math/inc/matrix_type.hpp>
#include <math/inc/relational_functions.hpp>
#include <math/inc/transform_functions.hpp>
#include <math/inc/trigonometric_functions.hpp>
#include <math/inc/vector_type.hpp>

#undef FRAMEWORK_MATH_DETAILS

////////////////////////////////////////////////////////////////////////////////
/// @brief 3D Math module
///
/// @details
/// The math library for 3D graphics systems.@n
/// It provides types and functions for different calculations from geometric
/// and linear algebra domains.
///
/// TODO: More detailed description
/// TODO: Code examples
///
/// @defgroup math_module Math
/// @{
/// @defgroup math_predefined_constants Predefined constants
/// @defgroup math_vector_implementation Vector type
/// @defgroup math_matrix_implementation Matrix type
/// @defgroup math_common_functions Common functions
/// @defgroup math_exponential_functions Exponential functions
/// @defgroup math_geometric_functions Geometric functions
/// @defgroup math_matrix_functions Matrix functions
/// @defgroup math_relational_functions Relational functions
/// @defgroup math_transform_functions Transform functions
/// @defgroup math_trigonometric_functions Trigonometric functions
/// @}
////////////////////////////////////////////////////////////////////////////////

namespace framework::math
{
////////////////////////////////////////////////////////////////////////////////
/// @addtogroup math_module
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name Vector types.
/// @{
////////////////////////////////////////////////////////////////////////////////

using Vector2d = Vector<2, double>; ///< Vector of 2 double values.
using Vector3d = Vector<3, double>; ///< Vector of 3 double values.
using Vector4d = Vector<4, double>; ///< Vector of 4 double values.

using Vector2f = Vector<2, float>; ///< Vector of 2 float values.
using Vector3f = Vector<3, float>; ///< Vector of 3 float values.
using Vector4f = Vector<4, float>; ///< Vector of 4 float values.

using Vector2i = Vector<2, int>; ///< Vector of 2 int values.
using Vector3i = Vector<3, int>; ///< Vector of 3 int values.
using Vector4i = Vector<4, int>; ///< Vector of 4 int values.

using Vector2u = Vector<2, unsigned int>; ///< Vector of 2 unsigned int values.
using Vector3u = Vector<3, unsigned int>; ///< Vector of 3 unsigned int values.
using Vector4u = Vector<4, unsigned int>; ///< Vector of 4 unsigned int values.

using Vector2b = Vector<2, bool>; ///< Vector of 2 bool values.
using Vector3b = Vector<3, bool>; ///< Vector of 3 bool values.
using Vector4b = Vector<4, bool>; ///< Vector of 4 bool values.

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name Matrix types.
/// @{
////////////////////////////////////////////////////////////////////////////////

using Matrix2d   = Matrix<2, 2, double>; ///< Matrix with 2 columns and 2 rows of double type values.
using Matrix2x2d = Matrix<2, 2, double>; ///< Matrix with 2 columns and 2 rows of double type values.
using Matrix2x3d = Matrix<2, 3, double>; ///< Matrix with 2 columns and 3 rows of double type values.
using Matrix2x4d = Matrix<2, 4, double>; ///< Matrix with 2 columns and 4 rows of double type values.

using Matrix3d   = Matrix<3, 3, double>; ///< Matrix with 3 columns and 3 rows of double type values.
using Matrix3x3d = Matrix<3, 3, double>; ///< Matrix with 3 columns and 3 rows of double type values.
using Matrix3x2d = Matrix<3, 2, double>; ///< Matrix with 3 columns and 2 rows of double type values.
using Matrix3x4d = Matrix<3, 4, double>; ///< Matrix with 3 columns and 4 rows of double type values.

using Matrix4d   = Matrix<4, 4, double>; ///< Matrix with 4 columns and 4 rows of double type values.
using Matrix4x4d = Matrix<4, 4, double>; ///< Matrix with 4 columns and 4 rows of double type values.
using Matrix4x2d = Matrix<4, 2, double>; ///< Matrix with 4 columns and 2 rows of double type values.
using Matrix4x3d = Matrix<4, 3, double>; ///< Matrix with 4 columns and 4 rows of double type values.

using Matrix2f   = Matrix<2, 2, float>; ///< Matrix with 2 columns and 2 rows of float type values.
using Matrix2x2f = Matrix<2, 2, float>; ///< Matrix with 2 columns and 2 rows of float type values.
using Matrix2x3f = Matrix<2, 3, float>; ///< Matrix with 2 columns and 3 rows of float type values.
using Matrix2x4f = Matrix<2, 4, float>; ///< Matrix with 2 columns and 4 rows of float type values.

using Matrix3f   = Matrix<3, 3, float>; ///< Matrix with 3 columns and 3 rows of float type values.
using Matrix3x3f = Matrix<3, 3, float>; ///< Matrix with 3 columns and 3 rows of float type values.
using Matrix3x2f = Matrix<3, 2, float>; ///< Matrix with 3 columns and 2 rows of float type values.
using Matrix3x4f = Matrix<3, 4, float>; ///< Matrix with 3 columns and 4 rows of float type values.

using Matrix4f   = Matrix<4, 4, float>; ///< Matrix with 4 columns and 4 rows of float type values.
using Matrix4x4f = Matrix<4, 4, float>; ///< Matrix with 4 columns and 4 rows of float type values.
using Matrix4x2f = Matrix<4, 2, float>; ///< Matrix with 4 columns and 2 rows of float type values.
using Matrix4x3f = Matrix<4, 3, float>; ///< Matrix with 4 columns and 4 rows of float type values.

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

} // namespace framework::math

#endif
