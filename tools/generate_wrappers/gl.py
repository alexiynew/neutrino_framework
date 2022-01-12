#!/usr/bin/python3
"""Generates extension wrapper for gl functions."""


class GeneratorData:
    def __init__(self):
        self.URL = "https://raw.githubusercontent.com/KhronosGroup/OpenGL-Registry/master/xml"
        self.XML = "gl.xml"

        self.DESTHPP = "./neutrino/graphics/src/opengl/opengl.hpp"
        self.DESTCPP = "./neutrino/graphics/src/opengl/opengl.cpp"

        self.API = "gl"
        self.SUPPORTED = "glcore"
        self.PROFILE = "core"

        self.BRIEF = "OpneGL functions wrapper."
        self.DATE = "17.09.2018"

        self.NAMESPACE = "framework::graphics::details::opengl"

        self.TYPEDEFS = ""

        self.INCLUDE_GUARD = "FRAMEWORK_GRAPHICS_SRC_OPENGL_OPENGL_HPP"

        self.HEADER_INCLUDE_FILES = ["functional", "KHR/khrplatform.h"]
        self.CPP_INCLUDE_FILES = ["mutex", "graphics/src/opengl/opengl.hpp"]

        self.INIT_FUNCTION_NAME = "init_opengl"