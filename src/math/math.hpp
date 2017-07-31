/// @file
/// @brief Main file in math module.
/// @author Fedorov Alexey
/// @date 04.03.2017
///
/// You should include this file only.
/// It includes all math stuff and declarations of main types for vectors and matrices.

#ifndef FRAMEWORK_MATH_HPP
#define FRAMEWORK_MATH_HPP

#include <common/common_types.hpp>

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

/// @brief Contains all math stuff.
///
/// @defgroup math_module Math module
/// @{

/// @defgroup vector_implementation Vector type
/// @defgroup matrix_implementation Matrix type
/// @defgroup common_functions Common functions
/// @defgroup exponential_functions Exponential functions
/// @defgroup geometric_functions Geometric functions
/// @defgroup matrix_functions Matrix functions
/// @defgroup relational_functions Relational functions
/// @defgroup transform_functions Transform functions
/// @defgroup trigonometric_functions Trigonometric functions

/// @brief Contains all math stuff.
namespace math {

/// @name Common vector types.
/// @{
using vector2d = vector<2, real64>; ///< Vector of 2 real64 values.
using vector3d = vector<3, real64>; ///< Vector of 3 real64 values.
using vector4d = vector<4, real64>; ///< Vector of 4 real64 values.

using vector2f = vector<2, real32>; ///< Vector of 2 real32 values.
using vector3f = vector<3, real32>; ///< Vector of 3 real32 values.
using vector4f = vector<4, real32>; ///< Vector of 4 real32 values.

using vector2i = vector<2, int32>; ///< Vector of 2 int32 values.
using vector3i = vector<3, int32>; ///< Vector of 3 int32 values.
using vector4i = vector<4, int32>; ///< Vector of 4 int32 values.

using vector2u = vector<2, uint32>; ///< Vector of 2 uint32 values.
using vector3u = vector<3, uint32>; ///< Vector of 3 uint32 values.
using vector4u = vector<4, uint32>; ///< Vector of 4 uint32 values.

using vector2b = vector<2, bool>; ///< Vector of 2 bool values.
using vector3b = vector<3, bool>; ///< Vector of 3 bool values.
using vector4b = vector<4, bool>; ///< Vector of 4 bool values.

/// @}

/// @name Common matrix types.
/// @{
using matrix2d   = matrix<2, 2, real64>; ///< Matrix with 2 columns and 2 rows of real64 type values.
using matrix2x2d = matrix<2, 2, real64>; ///< Matrix with 2 columns and 2 rows of real64 type values.
using matrix2x3d = matrix<2, 3, real64>; ///< Matrix with 2 columns and 3 rows of real64 type values.
using matrix2x4d = matrix<2, 4, real64>; ///< Matrix with 2 columns and 4 rows of real64 type values.

using matrix3d   = matrix<3, 3, real64>; ///< Matrix with 3 columns and 3 rows of real64 type values.
using matrix3x3d = matrix<3, 3, real64>; ///< Matrix with 3 columns and 3 rows of real64 type values.
using matrix3x2d = matrix<3, 2, real64>; ///< Matrix with 3 columns and 2 rows of real64 type values.
using matrix3x4d = matrix<3, 4, real64>; ///< Matrix with 3 columns and 4 rows of real64 type values.

using matrix4d   = matrix<4, 4, real64>; ///< Matrix with 4 columns and 4 rows of real64 type values.
using matrix4x4d = matrix<4, 4, real64>; ///< Matrix with 4 columns and 4 rows of real64 type values.
using matrix4x2d = matrix<4, 2, real64>; ///< Matrix with 4 columns and 2 rows of real64 type values.
using matrix4x3d = matrix<4, 3, real64>; ///< Matrix with 4 columns and 4 rows of real64 type values.

using matrix2f   = matrix<2, 2, real32>; ///< Matrix with 2 columns and 2 rows of real32 type values.
using matrix2x2f = matrix<2, 2, real32>; ///< Matrix with 2 columns and 2 rows of real32 type values.
using matrix2x3f = matrix<2, 3, real32>; ///< Matrix with 2 columns and 3 rows of real32 type values.
using matrix2x4f = matrix<2, 4, real32>; ///< Matrix with 2 columns and 4 rows of real32 type values.

using matrix3f   = matrix<3, 3, real32>; ///< Matrix with 3 columns and 3 rows of real32 type values.
using matrix3x3f = matrix<3, 3, real32>; ///< Matrix with 3 columns and 3 rows of real32 type values.
using matrix3x2f = matrix<3, 2, real32>; ///< Matrix with 3 columns and 2 rows of real32 type values.
using matrix3x4f = matrix<3, 4, real32>; ///< Matrix with 3 columns and 4 rows of real32 type values.

using matrix4f   = matrix<4, 4, real32>; ///< Matrix with 4 columns and 4 rows of real32 type values.
using matrix4x4f = matrix<4, 4, real32>; ///< Matrix with 4 columns and 4 rows of real32 type values.
using matrix4x2f = matrix<4, 2, real32>; ///< Matrix with 4 columns and 2 rows of real32 type values.
using matrix4x3f = matrix<4, 3, real32>; ///< Matrix with 4 columns and 4 rows of real32 type values.

/// @}

/// @}

} // namespace math

} // namespace framework

#endif
