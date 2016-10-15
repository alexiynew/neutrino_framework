#ifndef FRAMEWORK_MATH_H
#define FRAMEWORK_MATH_H

#include <common_types.h>

#include <math/constants.h>

#include <math/matrix_type.h>
#include <math/vector_type.h>

#include <math/common_func.h>
#include <math/exponential_func.h>
#include <math/geometric_func.h>
#include <math/matrix_func.h>
#include <math/relational_func.h>
#include <math/transform_func.h>
#include <math/trigonometric_func.h>

namespace framework {

namespace math {

#pragma mark - Vector Type
template <U32 N, typename T>
using Vector = vector_impl::Vector<N, T>;

using Vector2D = Vector<2, F64>;
using Vector3D = Vector<3, F64>;
using Vector4D = Vector<4, F64>;

using Vector2F = Vector<2, F32>;
using Vector3F = Vector<3, F32>;
using Vector4F = Vector<4, F32>;

using Vector2I = Vector<2, I32>;
using Vector3I = Vector<3, I32>;
using Vector4I = Vector<4, I32>;

using Vector2U = Vector<2, U32>;
using Vector3U = Vector<3, U32>;
using Vector4U = Vector<4, U32>;

using Vector2B = Vector<2, bool>;
using Vector3B = Vector<3, bool>;
using Vector4B = Vector<4, bool>;

#pragma mark - Matrix Type
template <U32 C, U32 R, typename T>
using Matrix = matrix_impl::Matrix<C, R, T>;

using Matrix2D   = Matrix<2, 2, F64>;
using Matrix2x2D = Matrix<2, 2, F64>;
using Matrix2x3D = Matrix<2, 3, F64>;
using Matrix2x4D = Matrix<2, 4, F64>;

using Matrix3D   = Matrix<3, 3, F64>;
using Matrix3x3D = Matrix<3, 3, F64>;
using Matrix3x2D = Matrix<3, 2, F64>;
using Matrix3x4D = Matrix<3, 4, F64>;

using Matrix4D   = Matrix<4, 4, F64>;
using Matrix4x4D = Matrix<4, 4, F64>;
using Matrix4x2D = Matrix<4, 2, F64>;
using Matrix4x3D = Matrix<4, 3, F64>;

using Matrix2F   = Matrix<2, 2, F32>;
using Matrix2x2F = Matrix<2, 2, F32>;
using Matrix2x3F = Matrix<2, 3, F32>;
using Matrix2x4F = Matrix<2, 4, F32>;

using Matrix3F   = Matrix<3, 3, F32>;
using Matrix3x3F = Matrix<3, 3, F32>;
using Matrix3x2F = Matrix<3, 2, F32>;
using Matrix3x4F = Matrix<3, 4, F32>;

using Matrix4F   = Matrix<4, 4, F32>;
using Matrix4x4F = Matrix<4, 4, F32>;
using Matrix4x2F = Matrix<4, 2, F32>;
using Matrix4x3F = Matrix<4, 3, F32>;

} // namespace math

} // namespace framework

#endif // FRAMEWORK_MATH_H
