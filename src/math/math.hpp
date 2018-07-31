/// @file
/// @brief Main file in math module.
/// @author Fedorov Alexey
/// @date 04.03.2017
///
/// You should include this file only.
/// It includes all math stuff and declarations of main types for vectors and matrices.

#ifndef FRAMEWORK_MATH_MATH_HPP
#define FRAMEWORK_MATH_MATH_HPP

#include <common/types.hpp>

#define FRAMEWORK_MATH_DETAILS

#include <math/details/common_functions.hpp>
#include <math/details/constants.hpp>
#include <math/details/exponential_functions.hpp>
#include <math/details/geometric_functions.hpp>
#include <math/details/matrix_functions.hpp>
#include <math/details/matrix_type.hpp>
#include <math/details/relational_functions.hpp>
#include <math/details/transform_functions.hpp>
#include <math/details/trigonometric_functions.hpp>
#include <math/details/vector_type.hpp>

#undef FRAMEWORK_MATH_DETAILS

namespace framework
{
/// @details
///
/// Math detailed description.
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

/// @brief Contains all math stuff.
namespace math
{
/// @addtogroup math_module
/// @{

/// @name Vector types.
/// @{

using vector2d = vector<2, float64>; ///< Vector of 2 float64 values.
using vector3d = vector<3, float64>; ///< Vector of 3 float64 values.
using vector4d = vector<4, float64>; ///< Vector of 4 float64 values.

using vector2f = vector<2, float32>; ///< Vector of 2 float32 values.
using vector3f = vector<3, float32>; ///< Vector of 3 float32 values.
using vector4f = vector<4, float32>; ///< Vector of 4 float32 values.

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

/// @name Matrix types.
/// @{

using matrix2d   = matrix<2, 2, float64>; ///< Matrix with 2 columns and 2 rows of float64 type values.
using matrix2x2d = matrix<2, 2, float64>; ///< Matrix with 2 columns and 2 rows of float64 type values.
using matrix2x3d = matrix<2, 3, float64>; ///< Matrix with 2 columns and 3 rows of float64 type values.
using matrix2x4d = matrix<2, 4, float64>; ///< Matrix with 2 columns and 4 rows of float64 type values.

using matrix3d   = matrix<3, 3, float64>; ///< Matrix with 3 columns and 3 rows of float64 type values.
using matrix3x3d = matrix<3, 3, float64>; ///< Matrix with 3 columns and 3 rows of float64 type values.
using matrix3x2d = matrix<3, 2, float64>; ///< Matrix with 3 columns and 2 rows of float64 type values.
using matrix3x4d = matrix<3, 4, float64>; ///< Matrix with 3 columns and 4 rows of float64 type values.

using matrix4d   = matrix<4, 4, float64>; ///< Matrix with 4 columns and 4 rows of float64 type values.
using matrix4x4d = matrix<4, 4, float64>; ///< Matrix with 4 columns and 4 rows of float64 type values.
using matrix4x2d = matrix<4, 2, float64>; ///< Matrix with 4 columns and 2 rows of float64 type values.
using matrix4x3d = matrix<4, 3, float64>; ///< Matrix with 4 columns and 4 rows of float64 type values.

using matrix2f   = matrix<2, 2, float32>; ///< Matrix with 2 columns and 2 rows of float32 type values.
using matrix2x2f = matrix<2, 2, float32>; ///< Matrix with 2 columns and 2 rows of float32 type values.
using matrix2x3f = matrix<2, 3, float32>; ///< Matrix with 2 columns and 3 rows of float32 type values.
using matrix2x4f = matrix<2, 4, float32>; ///< Matrix with 2 columns and 4 rows of float32 type values.

using matrix3f   = matrix<3, 3, float32>; ///< Matrix with 3 columns and 3 rows of float32 type values.
using matrix3x3f = matrix<3, 3, float32>; ///< Matrix with 3 columns and 3 rows of float32 type values.
using matrix3x2f = matrix<3, 2, float32>; ///< Matrix with 3 columns and 2 rows of float32 type values.
using matrix3x4f = matrix<3, 4, float32>; ///< Matrix with 3 columns and 4 rows of float32 type values.

using matrix4f   = matrix<4, 4, float32>; ///< Matrix with 4 columns and 4 rows of float32 type values.
using matrix4x4f = matrix<4, 4, float32>; ///< Matrix with 4 columns and 4 rows of float32 type values.
using matrix4x2f = matrix<4, 2, float32>; ///< Matrix with 4 columns and 2 rows of float32 type values.
using matrix4x3f = matrix<4, 3, float32>; ///< Matrix with 4 columns and 4 rows of float32 type values.

/// @}

/// @}

} // namespace math

/// @}

} // namespace framework

#endif
