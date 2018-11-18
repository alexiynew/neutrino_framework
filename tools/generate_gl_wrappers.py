#!/usr/bin/python3
"""Generates extension wrapper for gl, glx, wgl functions."""

from generate_gl_wrappers import *

generator.generate(gl.data)
generator.generate(wgl.data)
generator.generate(glx.data)
