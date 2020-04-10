#!/usr/bin/python3
"""Generates extension wrapper for gl, glx, wgl functions."""

from generate_wrappers import *


def generate(data):
    reg = parser.parse(data.URL, data.XML)
    generator.generate(reg, data)


generate(gl.GeneratorData())
generate(wgl.GeneratorData())
# generator.generate(glx.data)
