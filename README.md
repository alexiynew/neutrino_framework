# Neutrino framework

The lightweight game framework, with no third-party dependencies, made for fun.

## It's crossplatform
Kinda. By now Linux, Windows, and macOS are supported. 
In a level 'it works on my machine'.

## It's lightweight
No need to install and build a bunch of third-party libraries. 
All that is needed is implemented inside the framework, this gives a single code base and the consistency of the modules.

## It's made for fun
This is a hobby project. I make it in my free time. 
The main idea is to do everything with my own hands, couse it is interesting.
On the other hand. This means that the project is developing slowly. 
It is poorly tested. It may not support something that you need. 
It may contain a **LOT OF BUGS**.

## Modules

| module                   | description                    |
| ------------------------ | ------------------------------ |
| @ref common_types_module | @copybrief common_types_module |
| @ref common_utils_module | @copybrief common_utils_module |
| @ref math_module         | @copybrief math_module         |
| @ref log_module          | @copybrief log_module          |
| @ref graphics_module     | @copybrief graphics_module     |
| @ref game_core_module    | @copybrief game_core_module    |
| @ref system_module       | @copybrief system_module       |
| @ref unit_test_module    | @copybrief unit_test_module    |


## How to build

**Reqired**: cmake v3.18, cpp compiller with cpp 17 support.
### Linux

Additional packages are required to be installed in the system 
to support OpenGL and X11
```
libx11-dev libgl1-mesa-dev mesa-common-dev
```

To build project run in terminal:

``` bash
> mkdir build
> cd build
> cmake ../
> cmake --build .
```

To run tests:

``` bash
> cmake --build . -t check
```

#### Windows
To generate Visual Studio project run in terminal:

``` bash
> mkdir build
> cd build
> cmake ../ -G "Visual Studio 16 2019"
```

To run tests:  
Build the 'check' target in VS.
#### MacOS

To generate XCode project run in terminal:

``` bash
> mkdir build
> cd build
> cmake ../ -G XCode
```

To run tests:  
Build the 'check' scheme in XCode.

## Code example
TODO


