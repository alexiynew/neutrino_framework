#!/usr/bin/python3
"""Generates extension wrapper for wgl functions."""


class GeneratorData:
    def __init__(self):
        self.URL = "https://raw.githubusercontent.com/KhronosGroup/OpenGL-Registry/master/xml"
        self.XML = "wgl.xml"

        self.DESTHPP = "./neutrino/system/src/windows/wglext.hpp"
        self.DESTCPP = "./neutrino/system/src/windows/wglext.cpp"

        self.API = ""
        self.SUPPORTED = "wgl"
        self.PROFILE = ""

        self.BRIEF = "WGL extension functions wrapper."
        self.DATE = "17.09.2018"

        self.NAMESPACE = "framework::system::details::wgl"

        self.TYPEDEFS = "" \
            "typedef void GLvoid;\n" \
            "typedef unsigned int GLenum;\n" \
            "typedef float GLfloat;\n" \
            "typedef int GLint;\n" \
            "typedef int GLsizei;\n" \
            "typedef unsigned int GLbitfield;\n" \
            "typedef double GLdouble;\n" \
            "typedef unsigned int GLuint;\n" \
            "typedef unsigned char GLboolean;\n" \
            "typedef unsigned char GLubyte;\n" \
            "typedef unsigned short GLushort;\n" \

        self.INCLUDE_GUARD = "FRAMEWORK_SYSTEM_SRC_WINDOWS_WGLEXT_HPP"

        self.HEADER_INCLUDE_FILES = ["Windows.h", "functional"]
        self.CPP_INCLUDE_FILES = ["type_traits", "mutex",
                                  "system/src/windows/wglext.hpp"]

        self.INIT_FUNCTION_NAME = "init_wgl"