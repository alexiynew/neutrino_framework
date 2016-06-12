#ifndef FRAMEWORK_MATH_H
#define FRAMEWORK_MATH_H

#include <common_types.h>

#include <math/vector_type.h>
#include <math/matrix_type.h>

#include <math/constants.h>
#include <math/common_func.h>
#include <math/relational_func.h>
#include <math/exponential_func.h>
#include <math/geometric_func.h>
#include <math/trigonometric_func.h>
#include <math/matrix_func.h>

namespace framework {

namespace math {

template <U32 N, typename T>
using vec = vector_impl::vec<N, T>;

using vec2d = vec<2, F64>;
using vec3d = vec<3, F64>;
using vec4d = vec<4, F64>;

using vec2f = vec<2, F32>;
using vec3f = vec<3, F32>;
using vec4f = vec<4, F32>;

using vec2i = vec<2, I32>;
using vec3i = vec<3, I32>;
using vec4i = vec<4, I32>;

using vec2u = vec<2, U32>;
using vec3u = vec<3, U32>;
using vec4u = vec<4, U32>;

using vec2b = vec<2, bool>;
using vec3b = vec<3, bool>;
using vec4b = vec<4, bool>;

template <U32 C, U32 R, typename T>
using mat = matrix_impl::matrix<C, R, T>;

using mat2d   = mat<2, 2, F64>;
using mat2x2d = mat<2, 2, F64>;
using mat2x3d = mat<2, 3, F64>;
using mat2x4d = mat<2, 4, F64>;

using mat3d   = mat<3, 3, F64>;
using mat3x3d = mat<3, 3, F64>;
using mat3x2d = mat<3, 2, F64>;
using mat3x4d = mat<3, 4, F64>;

using mat4d   = mat<4, 4, F64>;
using mat4x4d = mat<4, 4, F64>;
using mat4x2d = mat<4, 2, F64>;
using mat4x3d = mat<4, 3, F64>;

using mat2f   = mat<2, 2, F32>;
using mat2x2f = mat<2, 2, F32>;
using mat2x3f = mat<2, 3, F32>;
using mat2x4f = mat<2, 4, F32>;

using mat3f   = mat<3, 3, F32>;
using mat3x3f = mat<3, 3, F32>;
using mat3x2f = mat<3, 2, F32>;
using mat3x4f = mat<3, 4, F32>;

using mat4f   = mat<4, 4, F32>;
using mat4x4f = mat<4, 4, F32>;
using mat4x2f = mat<4, 2, F32>;
using mat4x3f = mat<4, 3, F32>;

} // namespace math

} // namespace framework

#endif // FRAMEWORK_MATH_H
