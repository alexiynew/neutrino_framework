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
#include <math/common_functions.hpp>
#include <math/constants.hpp>
#include <math/exponential_functions.hpp>
#include <math/geometric_functions.hpp>
#include <math/matrix_functions.hpp>
#include <math/matrix_type.hpp>
#include <math/relational_functions.hpp>
#include <math/transform_functions.hpp>
#include <math/trigonometric_functions.hpp>
#include <math/vector_type.hpp>

namespace framework
{
/// @brief Contains all math stuff.
/// @defgroup math_module Math
/// @{

/// @brief Predefined constants.
/// @defgroup predefined_constants Predefined constants

/// @brief Vector type implementation.
/// @defgroup vector_implementation Vector type

/// @brief Matrix type implementation.
/// @defgroup matrix_implementation Matrix type

/// @brief Defines common math functions.
/// @defgroup common_functions Common functions

/// @brief Defines exponential math functions.
/// @defgroup exponential_functions Exponential functions

/// @brief Defines geometric math functions.
/// @defgroup geometric_functions Geometric functions

/// @brief Defines matrix specific math functions.
/// @defgroup matrix_functions Matrix functions

/// @brief Defines rational math functions.
/// @defgroup relational_functions Relational functions

/// @brief Defines transform functions.
/// @defgroup transform_functions Transform functions

/// @brief Defines trigonometric math functions.
/// @defgroup trigonometric_functions Trigonometric functions

/// @brief Contains all math stuff.
namespace math
{
/// @name Common vector types.
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

/// @name Common matrix types.
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

} // namespace framework

#endif
