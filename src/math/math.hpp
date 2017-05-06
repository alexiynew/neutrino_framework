/**
 * @file math.hpp
 * @brief Main file in math module.
 * @author Fedorov Alexey
 * @date 04.03.2017
 *
 * You should include this file only.
 * It includes all math stuff and declarations of main types for vectors and matrices.
 */

#ifndef FRAMEWORK_MATH_HPP
#define FRAMEWORK_MATH_HPP

#include <math/constants.hpp>

#include <math/vector_type.hpp>

#include <math/matrix_type.hpp>

#include <math/common_func.hpp>
#include <math/exponential_func.hpp>
#include <math/geometric_func.hpp>
#include <math/matrix_func.hpp>
#include <math/relational_func.hpp>
#include <math/transform_func.hpp>
#include <math/trigonometric_func.hpp>

namespace framework {

/**
 * @defgroup math_module Math module
 * @brief Contains all math stuff.
 * @{
 */

/**
 * @brief Contains all math stuff.
 */
namespace math {

/**
 * @name Common vector types.
 * @{
 */
using vector2d = vector<2, double>; /**< @brief Vector of 2 double values. */
using vector3d = vector<3, double>; /**< @brief Vector of 3 double values. */
using vector4d = vector<4, double>; /**< @brief Vector of 4 double values. */

using vector2f = vector<2, float>; /**< @brief Vector of 2 float values. */
using vector3f = vector<3, float>; /**< @brief Vector of 3 float values. */
using vector4f = vector<4, float>; /**< @brief Vector of 4 float values. */

using vector2i = vector<2, int>; /**< @brief Vector of 2 int values. */
using vector3i = vector<3, int>; /**< @brief Vector of 3 int values. */
using vector4i = vector<4, int>; /**< @brief Vector of 4 int values. */

using vector2u = vector<2, unsigned int>; /**< @brief Vector of 2 unsigned int values. */
using vector3u = vector<3, unsigned int>; /**< @brief Vector of 3 unsigned int values. */
using vector4u = vector<4, unsigned int>; /**< @brief Vector of 4 unsigned int values. */

using vector2b = vector<2, bool>; /**< @brief Vector of 2 bool values. */
using vector3b = vector<3, bool>; /**< @brief Vector of 3 bool values. */
using vector4b = vector<4, bool>; /**< @brief Vector of 4 bool values. */
/**
 * @}
 */

/**
 * @name Common matrix types.
 * @{
 */
using Matrix2D =
matrix_impl::Matrix<2, 2, double>; /**< @brief Matrix with 2 columns and 2 rows of double type values. */
using Matrix2x2D =
matrix_impl::Matrix<2, 2, double>; /**< @brief Matrix with 2 columns and 2 rows of double type values. */
using Matrix2x3D =
matrix_impl::Matrix<2, 3, double>; /**< @brief Matrix with 2 columns and 3 rows of double type values. */
using Matrix2x4D =
matrix_impl::Matrix<2, 4, double>; /**< @brief Matrix with 2 columns and 4 rows of double type values. */

using Matrix3D =
matrix_impl::Matrix<3, 3, double>; /**< @brief Matrix with 3 columns and 3 rows of double type values. */
using Matrix3x3D =
matrix_impl::Matrix<3, 3, double>; /**< @brief Matrix with 3 columns and 3 rows of double type values. */
using Matrix3x2D =
matrix_impl::Matrix<3, 2, double>; /**< @brief Matrix with 3 columns and 2 rows of double type values. */
using Matrix3x4D =
matrix_impl::Matrix<3, 4, double>; /**< @brief Matrix with 3 columns and 4 rows of double type values. */

using Matrix4D =
matrix_impl::Matrix<4, 4, double>; /**< @brief Matrix with 4 columns and 4 rows of double type values. */
using Matrix4x4D =
matrix_impl::Matrix<4, 4, double>; /**< @brief Matrix with 4 columns and 4 rows of double type values. */
using Matrix4x2D =
matrix_impl::Matrix<4, 2, double>; /**< @brief Matrix with 4 columns and 2 rows of double type values. */
using Matrix4x3D =
matrix_impl::Matrix<4, 3, double>; /**< @brief Matrix with 4 columns and 4 rows of double type values. */

using Matrix2F = matrix_impl::Matrix<2, 2, float>; /**< @brief Matrix with 2 columns and 2 rows of float type values. */
using Matrix2x2F =
matrix_impl::Matrix<2, 2, float>; /**< @brief Matrix with 2 columns and 2 rows of float type values. */
using Matrix2x3F =
matrix_impl::Matrix<2, 3, float>; /**< @brief Matrix with 2 columns and 3 rows of float type values. */
using Matrix2x4F =
matrix_impl::Matrix<2, 4, float>; /**< @brief Matrix with 2 columns and 4 rows of float type values. */

using Matrix3F = matrix_impl::Matrix<3, 3, float>; /**< @brief Matrix with 3 columns and 3 rows of float type values. */
using Matrix3x3F =
matrix_impl::Matrix<3, 3, float>; /**< @brief Matrix with 3 columns and 3 rows of float type values. */
using Matrix3x2F =
matrix_impl::Matrix<3, 2, float>; /**< @brief Matrix with 3 columns and 2 rows of float type values. */
using Matrix3x4F =
matrix_impl::Matrix<3, 4, float>; /**< @brief Matrix with 3 columns and 4 rows of float type values. */

using Matrix4F = matrix_impl::Matrix<4, 4, float>; /**< @brief Matrix with 4 columns and 4 rows of float type values. */
using Matrix4x4F =
matrix_impl::Matrix<4, 4, float>; /**< @brief Matrix with 4 columns and 4 rows of float type values. */
using Matrix4x2F =
matrix_impl::Matrix<4, 2, float>; /**< @brief Matrix with 4 columns and 2 rows of float type values. */
using Matrix4x3F =
matrix_impl::Matrix<4, 3, float>; /**< @brief Matrix with 4 columns and 4 rows of float type values. */
/**
 * @}
 */

/**
 * @}
 */

} // namespace math

} // namespace framework

#endif
