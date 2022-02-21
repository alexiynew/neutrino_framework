# Documentation

Most of the main classes and functions in modules are documented with Doxygen comments.  
Brief description of modules provided by **README.md** files.  
I try to keep descriptions up to date, but pretty-looking docs are not the point right now. 

Doxygen documentation can be generated like this:

``` bash
> mkdir build
> cd build
> cmake ../
> cmake --build . -t docs
```

After that, the **output/docs** folder would contain generated results.
