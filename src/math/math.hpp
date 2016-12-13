#ifndef FRAMEWORK_MATH_HPP
#define FRAMEWORK_MATH_HPP

#include <math/constants.hpp>

#include <math/matrix_type.hpp>
#include <math/vector_type.hpp>

#include <math/common_func.hpp>
#include <math/exponential_func.hpp>
#include <math/geometric_func.hpp>
#include <math/matrix_func.hpp>
#include <math/relational_func.hpp>
#include <math/transform_func.hpp>
#include <math/trigonometric_func.hpp>

namespace framework {

namespace math {

#pragma mark - Vector Type
template <unsigned int N, typename T>
using Vector = vector_impl::Vector<N, T>;

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

#pragma mark - Matrix Type
template <unsigned int C, unsigned int R, typename T>
using Matrix = matrix_impl::Matrix<C, R, T>;

using Matrix2D   = Matrix<2, 2, double>;
using Matrix2x2D = Matrix<2, 2, double>;
using Matrix2x3D = Matrix<2, 3, double>;
using Matrix2x4D = Matrix<2, 4, double>;

using Matrix3D   = Matrix<3, 3, double>;
using Matrix3x3D = Matrix<3, 3, double>;
using Matrix3x2D = Matrix<3, 2, double>;
using Matrix3x4D = Matrix<3, 4, double>;

using Matrix4D   = Matrix<4, 4, double>;
using Matrix4x4D = Matrix<4, 4, double>;
using Matrix4x2D = Matrix<4, 2, double>;
using Matrix4x3D = Matrix<4, 3, double>;

using Matrix2F   = Matrix<2, 2, float>;
using Matrix2x2F = Matrix<2, 2, float>;
using Matrix2x3F = Matrix<2, 3, float>;
using Matrix2x4F = Matrix<2, 4, float>;

using Matrix3F   = Matrix<3, 3, float>;
using Matrix3x3F = Matrix<3, 3, float>;
using Matrix3x2F = Matrix<3, 2, float>;
using Matrix3x4F = Matrix<3, 4, float>;

using Matrix4F   = Matrix<4, 4, float>;
using Matrix4x4F = Matrix<4, 4, float>;
using Matrix4x2F = Matrix<4, 2, float>;
using Matrix4x3F = Matrix<4, 3, float>;

} // namespace math

} // namespace framework

#endif
