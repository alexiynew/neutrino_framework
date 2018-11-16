module_name = meson.current_source_dir().split('/').get(-1)

message('\tAdd module: ' + module_name)

public = files('math.hpp')


public += files('details/matrix_type.hpp',
                'details/vector_type.hpp')

public += files('details/constants.hpp',
                'details/common_functions.hpp',
                'details/exponential_functions.hpp',
                'details/geometric_functions.hpp',
                'details/matrix_functions.hpp',
                'details/relational_functions.hpp',
                'details/transform_functions.hpp')

public += files('details/vector_type_details.hpp',
                'details/matrix_type_details.hpp')

public += files('details/common_functions_details.hpp',
                'details/geometric_functions_details.hpp',
                'details/matrix_functions_details.hpp',
                'details/relational_functions_details.hpp',
                'details/trigonometric_functions.hpp')

framework_sources += public