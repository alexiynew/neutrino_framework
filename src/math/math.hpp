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
 */

/**
 * @brief Contains all math stuff.
 * @ingroup math_module
 */
namespace math {

#pragma mark - vector Type

/**
 * @defgroup common_vectors Common vector types
 * @ingroup math_module
 * @{
 */
using vector2D = vector<2, double>;
using vector3D = vector<3, double>;
using vector4D = vector<4, double>;

using vector2F = vector<2, float>;
using vector3F = vector<3, float>;
using vector4F = vector<4, float>;

using vector2I = vector<2, int>;
using vector3I = vector<3, int>;
using vector4I = vector<4, int>;

using vector2U = vector<2, unsigned int>;
using vector3U = vector<3, unsigned int>;
using vector4U = vector<4, unsigned int>;

using vector2B = vector<2, bool>;
using vector3B = vector<3, bool>;
using vector4B = vector<4, bool>;
/**
 * @}
 */

#pragma mark - Matrix Type

/**
 * @defgroup common_matrices Common matrix types
 * @ingroup math_module
 * @{
 */
using Matrix2D   = matrix_impl::Matrix<2, 2, double>;
using Matrix2x2D = matrix_impl::Matrix<2, 2, double>;
using Matrix2x3D = matrix_impl::Matrix<2, 3, double>;
using Matrix2x4D = matrix_impl::Matrix<2, 4, double>;

using Matrix3D   = matrix_impl::Matrix<3, 3, double>;
using Matrix3x3D = matrix_impl::Matrix<3, 3, double>;
using Matrix3x2D = matrix_impl::Matrix<3, 2, double>;
using Matrix3x4D = matrix_impl::Matrix<3, 4, double>;

using Matrix4D   = matrix_impl::Matrix<4, 4, double>;
using Matrix4x4D = matrix_impl::Matrix<4, 4, double>;
using Matrix4x2D = matrix_impl::Matrix<4, 2, double>;
using Matrix4x3D = matrix_impl::Matrix<4, 3, double>;

using Matrix2F   = matrix_impl::Matrix<2, 2, float>;
using Matrix2x2F = matrix_impl::Matrix<2, 2, float>;
using Matrix2x3F = matrix_impl::Matrix<2, 3, float>;
using Matrix2x4F = matrix_impl::Matrix<2, 4, float>;

using Matrix3F   = matrix_impl::Matrix<3, 3, float>;
using Matrix3x3F = matrix_impl::Matrix<3, 3, float>;
using Matrix3x2F = matrix_impl::Matrix<3, 2, float>;
using Matrix3x4F = matrix_impl::Matrix<3, 4, float>;

using Matrix4F   = matrix_impl::Matrix<4, 4, float>;
using Matrix4x4F = matrix_impl::Matrix<4, 4, float>;
using Matrix4x2F = matrix_impl::Matrix<4, 2, float>;
using Matrix4x3F = matrix_impl::Matrix<4, 3, float>;
/**
 * @}
 */

} // namespace math

} // namespace framework

#endif
