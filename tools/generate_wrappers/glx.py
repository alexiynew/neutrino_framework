#!/usr/bin/python3
"""Generates extension wrapper for glx functions."""

SOURCE = "./dependencies/GL/glxext.h"

DESTHPP = "./neutrino/gl/inc/glxext_wrapper.hpp"
DESTCPP = "./neutrino/gl/src/glxext_wrapper.cpp"

GROUP_REGEX = r'#ifndef\s([\w\d_]+)\s#define\s\1\s1\s(.*?)#endif\s/\*\s\1\s\*/'
TYPE_REGEX = r'typedef.*\(\s?\*(PFN.*PROC)\).*;'
NAME_REGEX = r'.*(glX[\w\d_]+)\s?\(.*;'

EXCLUDE = ["PFNGLXGETPROCADDRESSARBPROC", "PFNGLXASSOCIATEDMPBUFFERSGIXPROC",
           "PFNGLXCREATEGLXVIDEOSOURCESGIXPROC", "PFNGLXDESTROYGLXVIDEOSOURCESGIXPROC"]

HEADER_FILE = "gl/inc/glxext_wrapper.hpp"

BRIEF = "GLX extension functions wrapper."
DATE = "17.09.2018"

NAMESPACE = "framework::gl::glx"

INCLUDE_GUARD = "FRAMEWORK_GL_INC_GLXEXT_WRAPPER_HPP"

INCLUDE_FILES = ["GL/glx.h"]

INIT_FUNCTION_NAME = "init_glx_functions"

data = dict(source=SOURCE,
            desthpp=DESTHPP,
            destcpp=DESTCPP,
            group_regex=GROUP_REGEX,
            type_regex=TYPE_REGEX,
            name_regex=NAME_REGEX,
            exclude=EXCLUDE,
            header_file=HEADER_FILE,
            brief=BRIEF,
            date=DATE,
            namespace=NAMESPACE,
            include_guard=INCLUDE_GUARD,
            include_files=INCLUDE_FILES,
            init_function_name=INIT_FUNCTION_NAME)
