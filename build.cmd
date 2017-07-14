rmdir /Q /S .\build
rmdir /Q /S .\output
md build
cd build
cmake -G "Visual Studio 15 2017 Win64" -DCMAKE_BUILD_TYPE="Release" -DBUILD_TESTS=ON ../
cd ../
