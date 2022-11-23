# Math

This is a header-only library for graphics software. For now, It is capable of vector operations and matrix transformations.
To use this module only the `math.hpp` file should be included. 


``` cpp
#include <math/math.hpp>

int main()
{
    using namespace neutrino::math;
    ... 

    Vecotr3f position = {7.0f, 0.0f, 0.0f};

    Matrix4f transform; // indentity matrix

    transform = translate(transform, position);
    transform = rotate(transform, normalize(Vector3f(0, 1, 0)), radians(0.5));

    ... 
}
```
