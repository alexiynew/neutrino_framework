#!/usr/bin/python3
"""Generates extension wrapper for glx functions."""

class GeneratorData:
    def __init__(self):
        self.XML = "glx.xml"

        self.DESTHPP = "./neutrino/system/src/linux/glxext.hpp"
        self.DESTCPP = "./neutrino/system/src/linux/glxext.cpp"

        self.API = ""
        self.SUPPORTED = "glx"
        self.PROFILE = ""

        self.NAMESPACE = "framework::system::details::glx"

        self.TYPEDEFS = ""

        self.INCLUDE_GUARD = "FRAMEWORK_SYSTEM_SRC_LINUX_GLXEXT_HPP"

        self.HEADER_INCLUDE_FILES = ["GL/glx.h", "functional"]
        self.CPP_INCLUDE_FILES = ["type_traits", "mutex",
                                  "system/src/linux/glxext.hpp"]

        self.INIT_FUNCTION_NAME = "init_glx"
