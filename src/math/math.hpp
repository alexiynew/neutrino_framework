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

#pragma mark - Vector Type

/**
 * @defgroup common_vectors Common vector types
 * @ingroup math_module
 * @{
 */
using Vector2D = Vector<2, double>;
using Vector3D = Vector<3, double>;
using Vector4D = Vector<4, double>;

using Vector2F = Vector<2, float>;
using Vector3F = Vector<3, float>;
using Vector4F = Vector<4, float>;

using Vector2I = Vector<2, int>;
using Vector3I = Vector<3, int>;
using Vector4I = Vector<4, int>;

using Vector2U = Vector<2, unsigned int>;
using Vector3U = Vector<3, unsigned int>;
using Vector4U = Vector<4, unsigned int>;

using Vector2B = Vector<2, bool>;
using Vector3B = Vector<3, bool>;
using Vector4B = Vector<4, bool>;
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
