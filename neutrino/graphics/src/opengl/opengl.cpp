// =============================================================================
// MIT License
//
// Copyright (c) 2017-2021 Fedorov Alexey
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// =============================================================================

#include <mutex>

#include <graphics/src/opengl/opengl.hpp>

namespace
{

using namespace framework::graphics::details::opengl;

#pragma region GL_VERSION_1_0

using glCullFacePtr               = std::add_pointer_t<decltype(glCullFace)>;
using glFrontFacePtr              = std::add_pointer_t<decltype(glFrontFace)>;
using glHintPtr                   = std::add_pointer_t<decltype(glHint)>;
using glLineWidthPtr              = std::add_pointer_t<decltype(glLineWidth)>;
using glPointSizePtr              = std::add_pointer_t<decltype(glPointSize)>;
using glPolygonModePtr            = std::add_pointer_t<decltype(glPolygonMode)>;
using glScissorPtr                = std::add_pointer_t<decltype(glScissor)>;
using glTexParameterfPtr          = std::add_pointer_t<decltype(glTexParameterf)>;
using glTexParameterfvPtr         = std::add_pointer_t<decltype(glTexParameterfv)>;
using glTexParameteriPtr          = std::add_pointer_t<decltype(glTexParameteri)>;
using glTexParameterivPtr         = std::add_pointer_t<decltype(glTexParameteriv)>;
using glTexImage1DPtr             = std::add_pointer_t<decltype(glTexImage1D)>;
using glTexImage2DPtr             = std::add_pointer_t<decltype(glTexImage2D)>;
using glDrawBufferPtr             = std::add_pointer_t<decltype(glDrawBuffer)>;
using glClearPtr                  = std::add_pointer_t<decltype(glClear)>;
using glClearColorPtr             = std::add_pointer_t<decltype(glClearColor)>;
using glClearStencilPtr           = std::add_pointer_t<decltype(glClearStencil)>;
using glClearDepthPtr             = std::add_pointer_t<decltype(glClearDepth)>;
using glStencilMaskPtr            = std::add_pointer_t<decltype(glStencilMask)>;
using glColorMaskPtr              = std::add_pointer_t<decltype(glColorMask)>;
using glDepthMaskPtr              = std::add_pointer_t<decltype(glDepthMask)>;
using glDisablePtr                = std::add_pointer_t<decltype(glDisable)>;
using glEnablePtr                 = std::add_pointer_t<decltype(glEnable)>;
using glFinishPtr                 = std::add_pointer_t<decltype(glFinish)>;
using glFlushPtr                  = std::add_pointer_t<decltype(glFlush)>;
using glBlendFuncPtr              = std::add_pointer_t<decltype(glBlendFunc)>;
using glLogicOpPtr                = std::add_pointer_t<decltype(glLogicOp)>;
using glStencilFuncPtr            = std::add_pointer_t<decltype(glStencilFunc)>;
using glStencilOpPtr              = std::add_pointer_t<decltype(glStencilOp)>;
using glDepthFuncPtr              = std::add_pointer_t<decltype(glDepthFunc)>;
using glPixelStorefPtr            = std::add_pointer_t<decltype(glPixelStoref)>;
using glPixelStoreiPtr            = std::add_pointer_t<decltype(glPixelStorei)>;
using glReadBufferPtr             = std::add_pointer_t<decltype(glReadBuffer)>;
using glReadPixelsPtr             = std::add_pointer_t<decltype(glReadPixels)>;
using glGetBooleanvPtr            = std::add_pointer_t<decltype(glGetBooleanv)>;
using glGetDoublevPtr             = std::add_pointer_t<decltype(glGetDoublev)>;
using glGetErrorPtr               = std::add_pointer_t<decltype(glGetError)>;
using glGetFloatvPtr              = std::add_pointer_t<decltype(glGetFloatv)>;
using glGetIntegervPtr            = std::add_pointer_t<decltype(glGetIntegerv)>;
using glGetStringPtr              = std::add_pointer_t<decltype(glGetString)>;
using glGetTexImagePtr            = std::add_pointer_t<decltype(glGetTexImage)>;
using glGetTexParameterfvPtr      = std::add_pointer_t<decltype(glGetTexParameterfv)>;
using glGetTexParameterivPtr      = std::add_pointer_t<decltype(glGetTexParameteriv)>;
using glGetTexLevelParameterfvPtr = std::add_pointer_t<decltype(glGetTexLevelParameterfv)>;
using glGetTexLevelParameterivPtr = std::add_pointer_t<decltype(glGetTexLevelParameteriv)>;
using glIsEnabledPtr              = std::add_pointer_t<decltype(glIsEnabled)>;
using glDepthRangePtr             = std::add_pointer_t<decltype(glDepthRange)>;
using glViewportPtr               = std::add_pointer_t<decltype(glViewport)>;

glCullFacePtr glCullFace_ptr                             = nullptr;
glFrontFacePtr glFrontFace_ptr                           = nullptr;
glHintPtr glHint_ptr                                     = nullptr;
glLineWidthPtr glLineWidth_ptr                           = nullptr;
glPointSizePtr glPointSize_ptr                           = nullptr;
glPolygonModePtr glPolygonMode_ptr                       = nullptr;
glScissorPtr glScissor_ptr                               = nullptr;
glTexParameterfPtr glTexParameterf_ptr                   = nullptr;
glTexParameterfvPtr glTexParameterfv_ptr                 = nullptr;
glTexParameteriPtr glTexParameteri_ptr                   = nullptr;
glTexParameterivPtr glTexParameteriv_ptr                 = nullptr;
glTexImage1DPtr glTexImage1D_ptr                         = nullptr;
glTexImage2DPtr glTexImage2D_ptr                         = nullptr;
glDrawBufferPtr glDrawBuffer_ptr                         = nullptr;
glClearPtr glClear_ptr                                   = nullptr;
glClearColorPtr glClearColor_ptr                         = nullptr;
glClearStencilPtr glClearStencil_ptr                     = nullptr;
glClearDepthPtr glClearDepth_ptr                         = nullptr;
glStencilMaskPtr glStencilMask_ptr                       = nullptr;
glColorMaskPtr glColorMask_ptr                           = nullptr;
glDepthMaskPtr glDepthMask_ptr                           = nullptr;
glDisablePtr glDisable_ptr                               = nullptr;
glEnablePtr glEnable_ptr                                 = nullptr;
glFinishPtr glFinish_ptr                                 = nullptr;
glFlushPtr glFlush_ptr                                   = nullptr;
glBlendFuncPtr glBlendFunc_ptr                           = nullptr;
glLogicOpPtr glLogicOp_ptr                               = nullptr;
glStencilFuncPtr glStencilFunc_ptr                       = nullptr;
glStencilOpPtr glStencilOp_ptr                           = nullptr;
glDepthFuncPtr glDepthFunc_ptr                           = nullptr;
glPixelStorefPtr glPixelStoref_ptr                       = nullptr;
glPixelStoreiPtr glPixelStorei_ptr                       = nullptr;
glReadBufferPtr glReadBuffer_ptr                         = nullptr;
glReadPixelsPtr glReadPixels_ptr                         = nullptr;
glGetBooleanvPtr glGetBooleanv_ptr                       = nullptr;
glGetDoublevPtr glGetDoublev_ptr                         = nullptr;
glGetErrorPtr glGetError_ptr                             = nullptr;
glGetFloatvPtr glGetFloatv_ptr                           = nullptr;
glGetIntegervPtr glGetIntegerv_ptr                       = nullptr;
glGetStringPtr glGetString_ptr                           = nullptr;
glGetTexImagePtr glGetTexImage_ptr                       = nullptr;
glGetTexParameterfvPtr glGetTexParameterfv_ptr           = nullptr;
glGetTexParameterivPtr glGetTexParameteriv_ptr           = nullptr;
glGetTexLevelParameterfvPtr glGetTexLevelParameterfv_ptr = nullptr;
glGetTexLevelParameterivPtr glGetTexLevelParameteriv_ptr = nullptr;
glIsEnabledPtr glIsEnabled_ptr                           = nullptr;
glDepthRangePtr glDepthRange_ptr                         = nullptr;
glViewportPtr glViewport_ptr                             = nullptr;

bool init_gl_version_1_0([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glCullFace_ptr = reinterpret_cast<glCullFacePtr>(get_function("glCullFace"))) == nullptr || result;
    result = (glFrontFace_ptr = reinterpret_cast<glFrontFacePtr>(get_function("glFrontFace"))) == nullptr || result;
    result = (glHint_ptr = reinterpret_cast<glHintPtr>(get_function("glHint"))) == nullptr || result;
    result = (glLineWidth_ptr = reinterpret_cast<glLineWidthPtr>(get_function("glLineWidth"))) == nullptr || result;
    result = (glPointSize_ptr = reinterpret_cast<glPointSizePtr>(get_function("glPointSize"))) == nullptr || result;
    result = (glPolygonMode_ptr = reinterpret_cast<glPolygonModePtr>(get_function("glPolygonMode"))) == nullptr || result;
    result = (glScissor_ptr = reinterpret_cast<glScissorPtr>(get_function("glScissor"))) == nullptr || result;
    result = (glTexParameterf_ptr = reinterpret_cast<glTexParameterfPtr>(get_function("glTexParameterf"))) == nullptr || result;
    result = (glTexParameterfv_ptr = reinterpret_cast<glTexParameterfvPtr>(get_function("glTexParameterfv"))) == nullptr || result;
    result = (glTexParameteri_ptr = reinterpret_cast<glTexParameteriPtr>(get_function("glTexParameteri"))) == nullptr || result;
    result = (glTexParameteriv_ptr = reinterpret_cast<glTexParameterivPtr>(get_function("glTexParameteriv"))) == nullptr || result;
    result = (glTexImage1D_ptr = reinterpret_cast<glTexImage1DPtr>(get_function("glTexImage1D"))) == nullptr || result;
    result = (glTexImage2D_ptr = reinterpret_cast<glTexImage2DPtr>(get_function("glTexImage2D"))) == nullptr || result;
    result = (glDrawBuffer_ptr = reinterpret_cast<glDrawBufferPtr>(get_function("glDrawBuffer"))) == nullptr || result;
    result = (glClear_ptr = reinterpret_cast<glClearPtr>(get_function("glClear"))) == nullptr || result;
    result = (glClearColor_ptr = reinterpret_cast<glClearColorPtr>(get_function("glClearColor"))) == nullptr || result;
    result = (glClearStencil_ptr = reinterpret_cast<glClearStencilPtr>(get_function("glClearStencil"))) == nullptr || result;
    result = (glClearDepth_ptr = reinterpret_cast<glClearDepthPtr>(get_function("glClearDepth"))) == nullptr || result;
    result = (glStencilMask_ptr = reinterpret_cast<glStencilMaskPtr>(get_function("glStencilMask"))) == nullptr || result;
    result = (glColorMask_ptr = reinterpret_cast<glColorMaskPtr>(get_function("glColorMask"))) == nullptr || result;
    result = (glDepthMask_ptr = reinterpret_cast<glDepthMaskPtr>(get_function("glDepthMask"))) == nullptr || result;
    result = (glDisable_ptr = reinterpret_cast<glDisablePtr>(get_function("glDisable"))) == nullptr || result;
    result = (glEnable_ptr = reinterpret_cast<glEnablePtr>(get_function("glEnable"))) == nullptr || result;
    result = (glFinish_ptr = reinterpret_cast<glFinishPtr>(get_function("glFinish"))) == nullptr || result;
    result = (glFlush_ptr = reinterpret_cast<glFlushPtr>(get_function("glFlush"))) == nullptr || result;
    result = (glBlendFunc_ptr = reinterpret_cast<glBlendFuncPtr>(get_function("glBlendFunc"))) == nullptr || result;
    result = (glLogicOp_ptr = reinterpret_cast<glLogicOpPtr>(get_function("glLogicOp"))) == nullptr || result;
    result = (glStencilFunc_ptr = reinterpret_cast<glStencilFuncPtr>(get_function("glStencilFunc"))) == nullptr || result;
    result = (glStencilOp_ptr = reinterpret_cast<glStencilOpPtr>(get_function("glStencilOp"))) == nullptr || result;
    result = (glDepthFunc_ptr = reinterpret_cast<glDepthFuncPtr>(get_function("glDepthFunc"))) == nullptr || result;
    result = (glPixelStoref_ptr = reinterpret_cast<glPixelStorefPtr>(get_function("glPixelStoref"))) == nullptr || result;
    result = (glPixelStorei_ptr = reinterpret_cast<glPixelStoreiPtr>(get_function("glPixelStorei"))) == nullptr || result;
    result = (glReadBuffer_ptr = reinterpret_cast<glReadBufferPtr>(get_function("glReadBuffer"))) == nullptr || result;
    result = (glReadPixels_ptr = reinterpret_cast<glReadPixelsPtr>(get_function("glReadPixels"))) == nullptr || result;
    result = (glGetBooleanv_ptr = reinterpret_cast<glGetBooleanvPtr>(get_function("glGetBooleanv"))) == nullptr || result;
    result = (glGetDoublev_ptr = reinterpret_cast<glGetDoublevPtr>(get_function("glGetDoublev"))) == nullptr || result;
    result = (glGetError_ptr = reinterpret_cast<glGetErrorPtr>(get_function("glGetError"))) == nullptr || result;
    result = (glGetFloatv_ptr = reinterpret_cast<glGetFloatvPtr>(get_function("glGetFloatv"))) == nullptr || result;
    result = (glGetIntegerv_ptr = reinterpret_cast<glGetIntegervPtr>(get_function("glGetIntegerv"))) == nullptr || result;
    result = (glGetString_ptr = reinterpret_cast<glGetStringPtr>(get_function("glGetString"))) == nullptr || result;
    result = (glGetTexImage_ptr = reinterpret_cast<glGetTexImagePtr>(get_function("glGetTexImage"))) == nullptr || result;
    result = (glGetTexParameterfv_ptr = reinterpret_cast<glGetTexParameterfvPtr>(get_function("glGetTexParameterfv"))) == nullptr || result;
    result = (glGetTexParameteriv_ptr = reinterpret_cast<glGetTexParameterivPtr>(get_function("glGetTexParameteriv"))) == nullptr || result;
    result = (glGetTexLevelParameterfv_ptr = reinterpret_cast<glGetTexLevelParameterfvPtr>(get_function("glGetTexLevelParameterfv"))) == nullptr || result;
    result = (glGetTexLevelParameteriv_ptr = reinterpret_cast<glGetTexLevelParameterivPtr>(get_function("glGetTexLevelParameteriv"))) == nullptr || result;
    result = (glIsEnabled_ptr = reinterpret_cast<glIsEnabledPtr>(get_function("glIsEnabled"))) == nullptr || result;
    result = (glDepthRange_ptr = reinterpret_cast<glDepthRangePtr>(get_function("glDepthRange"))) == nullptr || result;
    result = (glViewport_ptr = reinterpret_cast<glViewportPtr>(get_function("glViewport"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_VERSION_1_1

using glDrawArraysPtr        = std::add_pointer_t<decltype(glDrawArrays)>;
using glDrawElementsPtr      = std::add_pointer_t<decltype(glDrawElements)>;
using glPolygonOffsetPtr     = std::add_pointer_t<decltype(glPolygonOffset)>;
using glCopyTexImage1DPtr    = std::add_pointer_t<decltype(glCopyTexImage1D)>;
using glCopyTexImage2DPtr    = std::add_pointer_t<decltype(glCopyTexImage2D)>;
using glCopyTexSubImage1DPtr = std::add_pointer_t<decltype(glCopyTexSubImage1D)>;
using glCopyTexSubImage2DPtr = std::add_pointer_t<decltype(glCopyTexSubImage2D)>;
using glTexSubImage1DPtr     = std::add_pointer_t<decltype(glTexSubImage1D)>;
using glTexSubImage2DPtr     = std::add_pointer_t<decltype(glTexSubImage2D)>;
using glBindTexturePtr       = std::add_pointer_t<decltype(glBindTexture)>;
using glDeleteTexturesPtr    = std::add_pointer_t<decltype(glDeleteTextures)>;
using glGenTexturesPtr       = std::add_pointer_t<decltype(glGenTextures)>;
using glIsTexturePtr         = std::add_pointer_t<decltype(glIsTexture)>;

glDrawArraysPtr glDrawArrays_ptr               = nullptr;
glDrawElementsPtr glDrawElements_ptr           = nullptr;
glPolygonOffsetPtr glPolygonOffset_ptr         = nullptr;
glCopyTexImage1DPtr glCopyTexImage1D_ptr       = nullptr;
glCopyTexImage2DPtr glCopyTexImage2D_ptr       = nullptr;
glCopyTexSubImage1DPtr glCopyTexSubImage1D_ptr = nullptr;
glCopyTexSubImage2DPtr glCopyTexSubImage2D_ptr = nullptr;
glTexSubImage1DPtr glTexSubImage1D_ptr         = nullptr;
glTexSubImage2DPtr glTexSubImage2D_ptr         = nullptr;
glBindTexturePtr glBindTexture_ptr             = nullptr;
glDeleteTexturesPtr glDeleteTextures_ptr       = nullptr;
glGenTexturesPtr glGenTextures_ptr             = nullptr;
glIsTexturePtr glIsTexture_ptr                 = nullptr;

bool init_gl_version_1_1([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glDrawArrays_ptr = reinterpret_cast<glDrawArraysPtr>(get_function("glDrawArrays"))) == nullptr || result;
    result = (glDrawElements_ptr = reinterpret_cast<glDrawElementsPtr>(get_function("glDrawElements"))) == nullptr || result;
    result = (glPolygonOffset_ptr = reinterpret_cast<glPolygonOffsetPtr>(get_function("glPolygonOffset"))) == nullptr || result;
    result = (glCopyTexImage1D_ptr = reinterpret_cast<glCopyTexImage1DPtr>(get_function("glCopyTexImage1D"))) == nullptr || result;
    result = (glCopyTexImage2D_ptr = reinterpret_cast<glCopyTexImage2DPtr>(get_function("glCopyTexImage2D"))) == nullptr || result;
    result = (glCopyTexSubImage1D_ptr = reinterpret_cast<glCopyTexSubImage1DPtr>(get_function("glCopyTexSubImage1D"))) == nullptr || result;
    result = (glCopyTexSubImage2D_ptr = reinterpret_cast<glCopyTexSubImage2DPtr>(get_function("glCopyTexSubImage2D"))) == nullptr || result;
    result = (glTexSubImage1D_ptr = reinterpret_cast<glTexSubImage1DPtr>(get_function("glTexSubImage1D"))) == nullptr || result;
    result = (glTexSubImage2D_ptr = reinterpret_cast<glTexSubImage2DPtr>(get_function("glTexSubImage2D"))) == nullptr || result;
    result = (glBindTexture_ptr = reinterpret_cast<glBindTexturePtr>(get_function("glBindTexture"))) == nullptr || result;
    result = (glDeleteTextures_ptr = reinterpret_cast<glDeleteTexturesPtr>(get_function("glDeleteTextures"))) == nullptr || result;
    result = (glGenTextures_ptr = reinterpret_cast<glGenTexturesPtr>(get_function("glGenTextures"))) == nullptr || result;
    result = (glIsTexture_ptr = reinterpret_cast<glIsTexturePtr>(get_function("glIsTexture"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_VERSION_1_2

using glDrawRangeElementsPtr = std::add_pointer_t<decltype(glDrawRangeElements)>;
using glTexImage3DPtr        = std::add_pointer_t<decltype(glTexImage3D)>;
using glTexSubImage3DPtr     = std::add_pointer_t<decltype(glTexSubImage3D)>;
using glCopyTexSubImage3DPtr = std::add_pointer_t<decltype(glCopyTexSubImage3D)>;

glDrawRangeElementsPtr glDrawRangeElements_ptr = nullptr;
glTexImage3DPtr glTexImage3D_ptr               = nullptr;
glTexSubImage3DPtr glTexSubImage3D_ptr         = nullptr;
glCopyTexSubImage3DPtr glCopyTexSubImage3D_ptr = nullptr;

bool init_gl_version_1_2([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glDrawRangeElements_ptr = reinterpret_cast<glDrawRangeElementsPtr>(get_function("glDrawRangeElements"))) == nullptr || result;
    result = (glTexImage3D_ptr = reinterpret_cast<glTexImage3DPtr>(get_function("glTexImage3D"))) == nullptr || result;
    result = (glTexSubImage3D_ptr = reinterpret_cast<glTexSubImage3DPtr>(get_function("glTexSubImage3D"))) == nullptr || result;
    result = (glCopyTexSubImage3D_ptr = reinterpret_cast<glCopyTexSubImage3DPtr>(get_function("glCopyTexSubImage3D"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_VERSION_1_3

using glActiveTexturePtr           = std::add_pointer_t<decltype(glActiveTexture)>;
using glSampleCoveragePtr          = std::add_pointer_t<decltype(glSampleCoverage)>;
using glCompressedTexImage3DPtr    = std::add_pointer_t<decltype(glCompressedTexImage3D)>;
using glCompressedTexImage2DPtr    = std::add_pointer_t<decltype(glCompressedTexImage2D)>;
using glCompressedTexImage1DPtr    = std::add_pointer_t<decltype(glCompressedTexImage1D)>;
using glCompressedTexSubImage3DPtr = std::add_pointer_t<decltype(glCompressedTexSubImage3D)>;
using glCompressedTexSubImage2DPtr = std::add_pointer_t<decltype(glCompressedTexSubImage2D)>;
using glCompressedTexSubImage1DPtr = std::add_pointer_t<decltype(glCompressedTexSubImage1D)>;
using glGetCompressedTexImagePtr   = std::add_pointer_t<decltype(glGetCompressedTexImage)>;

glActiveTexturePtr glActiveTexture_ptr                     = nullptr;
glSampleCoveragePtr glSampleCoverage_ptr                   = nullptr;
glCompressedTexImage3DPtr glCompressedTexImage3D_ptr       = nullptr;
glCompressedTexImage2DPtr glCompressedTexImage2D_ptr       = nullptr;
glCompressedTexImage1DPtr glCompressedTexImage1D_ptr       = nullptr;
glCompressedTexSubImage3DPtr glCompressedTexSubImage3D_ptr = nullptr;
glCompressedTexSubImage2DPtr glCompressedTexSubImage2D_ptr = nullptr;
glCompressedTexSubImage1DPtr glCompressedTexSubImage1D_ptr = nullptr;
glGetCompressedTexImagePtr glGetCompressedTexImage_ptr     = nullptr;

bool init_gl_version_1_3([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glActiveTexture_ptr = reinterpret_cast<glActiveTexturePtr>(get_function("glActiveTexture"))) == nullptr || result;
    result = (glSampleCoverage_ptr = reinterpret_cast<glSampleCoveragePtr>(get_function("glSampleCoverage"))) == nullptr || result;
    result = (glCompressedTexImage3D_ptr = reinterpret_cast<glCompressedTexImage3DPtr>(get_function("glCompressedTexImage3D"))) == nullptr || result;
    result = (glCompressedTexImage2D_ptr = reinterpret_cast<glCompressedTexImage2DPtr>(get_function("glCompressedTexImage2D"))) == nullptr || result;
    result = (glCompressedTexImage1D_ptr = reinterpret_cast<glCompressedTexImage1DPtr>(get_function("glCompressedTexImage1D"))) == nullptr || result;
    result = (glCompressedTexSubImage3D_ptr = reinterpret_cast<glCompressedTexSubImage3DPtr>(get_function("glCompressedTexSubImage3D"))) == nullptr || result;
    result = (glCompressedTexSubImage2D_ptr = reinterpret_cast<glCompressedTexSubImage2DPtr>(get_function("glCompressedTexSubImage2D"))) == nullptr || result;
    result = (glCompressedTexSubImage1D_ptr = reinterpret_cast<glCompressedTexSubImage1DPtr>(get_function("glCompressedTexSubImage1D"))) == nullptr || result;
    result = (glGetCompressedTexImage_ptr = reinterpret_cast<glGetCompressedTexImagePtr>(get_function("glGetCompressedTexImage"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_VERSION_1_4

using glBlendFuncSeparatePtr = std::add_pointer_t<decltype(glBlendFuncSeparate)>;
using glMultiDrawArraysPtr   = std::add_pointer_t<decltype(glMultiDrawArrays)>;
using glMultiDrawElementsPtr = std::add_pointer_t<decltype(glMultiDrawElements)>;
using glPointParameterfPtr   = std::add_pointer_t<decltype(glPointParameterf)>;
using glPointParameterfvPtr  = std::add_pointer_t<decltype(glPointParameterfv)>;
using glPointParameteriPtr   = std::add_pointer_t<decltype(glPointParameteri)>;
using glPointParameterivPtr  = std::add_pointer_t<decltype(glPointParameteriv)>;
using glBlendColorPtr        = std::add_pointer_t<decltype(glBlendColor)>;
using glBlendEquationPtr     = std::add_pointer_t<decltype(glBlendEquation)>;

glBlendFuncSeparatePtr glBlendFuncSeparate_ptr = nullptr;
glMultiDrawArraysPtr glMultiDrawArrays_ptr     = nullptr;
glMultiDrawElementsPtr glMultiDrawElements_ptr = nullptr;
glPointParameterfPtr glPointParameterf_ptr     = nullptr;
glPointParameterfvPtr glPointParameterfv_ptr   = nullptr;
glPointParameteriPtr glPointParameteri_ptr     = nullptr;
glPointParameterivPtr glPointParameteriv_ptr   = nullptr;
glBlendColorPtr glBlendColor_ptr               = nullptr;
glBlendEquationPtr glBlendEquation_ptr         = nullptr;

bool init_gl_version_1_4([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glBlendFuncSeparate_ptr = reinterpret_cast<glBlendFuncSeparatePtr>(get_function("glBlendFuncSeparate"))) == nullptr || result;
    result = (glMultiDrawArrays_ptr = reinterpret_cast<glMultiDrawArraysPtr>(get_function("glMultiDrawArrays"))) == nullptr || result;
    result = (glMultiDrawElements_ptr = reinterpret_cast<glMultiDrawElementsPtr>(get_function("glMultiDrawElements"))) == nullptr || result;
    result = (glPointParameterf_ptr = reinterpret_cast<glPointParameterfPtr>(get_function("glPointParameterf"))) == nullptr || result;
    result = (glPointParameterfv_ptr = reinterpret_cast<glPointParameterfvPtr>(get_function("glPointParameterfv"))) == nullptr || result;
    result = (glPointParameteri_ptr = reinterpret_cast<glPointParameteriPtr>(get_function("glPointParameteri"))) == nullptr || result;
    result = (glPointParameteriv_ptr = reinterpret_cast<glPointParameterivPtr>(get_function("glPointParameteriv"))) == nullptr || result;
    result = (glBlendColor_ptr = reinterpret_cast<glBlendColorPtr>(get_function("glBlendColor"))) == nullptr || result;
    result = (glBlendEquation_ptr = reinterpret_cast<glBlendEquationPtr>(get_function("glBlendEquation"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_VERSION_1_5

using glGenQueriesPtr           = std::add_pointer_t<decltype(glGenQueries)>;
using glDeleteQueriesPtr        = std::add_pointer_t<decltype(glDeleteQueries)>;
using glIsQueryPtr              = std::add_pointer_t<decltype(glIsQuery)>;
using glBeginQueryPtr           = std::add_pointer_t<decltype(glBeginQuery)>;
using glEndQueryPtr             = std::add_pointer_t<decltype(glEndQuery)>;
using glGetQueryivPtr           = std::add_pointer_t<decltype(glGetQueryiv)>;
using glGetQueryObjectivPtr     = std::add_pointer_t<decltype(glGetQueryObjectiv)>;
using glGetQueryObjectuivPtr    = std::add_pointer_t<decltype(glGetQueryObjectuiv)>;
using glBindBufferPtr           = std::add_pointer_t<decltype(glBindBuffer)>;
using glDeleteBuffersPtr        = std::add_pointer_t<decltype(glDeleteBuffers)>;
using glGenBuffersPtr           = std::add_pointer_t<decltype(glGenBuffers)>;
using glIsBufferPtr             = std::add_pointer_t<decltype(glIsBuffer)>;
using glBufferDataPtr           = std::add_pointer_t<decltype(glBufferData)>;
using glBufferSubDataPtr        = std::add_pointer_t<decltype(glBufferSubData)>;
using glGetBufferSubDataPtr     = std::add_pointer_t<decltype(glGetBufferSubData)>;
using glMapBufferPtr            = std::add_pointer_t<decltype(glMapBuffer)>;
using glUnmapBufferPtr          = std::add_pointer_t<decltype(glUnmapBuffer)>;
using glGetBufferParameterivPtr = std::add_pointer_t<decltype(glGetBufferParameteriv)>;
using glGetBufferPointervPtr    = std::add_pointer_t<decltype(glGetBufferPointerv)>;

glGenQueriesPtr glGenQueries_ptr                     = nullptr;
glDeleteQueriesPtr glDeleteQueries_ptr               = nullptr;
glIsQueryPtr glIsQuery_ptr                           = nullptr;
glBeginQueryPtr glBeginQuery_ptr                     = nullptr;
glEndQueryPtr glEndQuery_ptr                         = nullptr;
glGetQueryivPtr glGetQueryiv_ptr                     = nullptr;
glGetQueryObjectivPtr glGetQueryObjectiv_ptr         = nullptr;
glGetQueryObjectuivPtr glGetQueryObjectuiv_ptr       = nullptr;
glBindBufferPtr glBindBuffer_ptr                     = nullptr;
glDeleteBuffersPtr glDeleteBuffers_ptr               = nullptr;
glGenBuffersPtr glGenBuffers_ptr                     = nullptr;
glIsBufferPtr glIsBuffer_ptr                         = nullptr;
glBufferDataPtr glBufferData_ptr                     = nullptr;
glBufferSubDataPtr glBufferSubData_ptr               = nullptr;
glGetBufferSubDataPtr glGetBufferSubData_ptr         = nullptr;
glMapBufferPtr glMapBuffer_ptr                       = nullptr;
glUnmapBufferPtr glUnmapBuffer_ptr                   = nullptr;
glGetBufferParameterivPtr glGetBufferParameteriv_ptr = nullptr;
glGetBufferPointervPtr glGetBufferPointerv_ptr       = nullptr;

bool init_gl_version_1_5([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glGenQueries_ptr = reinterpret_cast<glGenQueriesPtr>(get_function("glGenQueries"))) == nullptr || result;
    result = (glDeleteQueries_ptr = reinterpret_cast<glDeleteQueriesPtr>(get_function("glDeleteQueries"))) == nullptr || result;
    result = (glIsQuery_ptr = reinterpret_cast<glIsQueryPtr>(get_function("glIsQuery"))) == nullptr || result;
    result = (glBeginQuery_ptr = reinterpret_cast<glBeginQueryPtr>(get_function("glBeginQuery"))) == nullptr || result;
    result = (glEndQuery_ptr = reinterpret_cast<glEndQueryPtr>(get_function("glEndQuery"))) == nullptr || result;
    result = (glGetQueryiv_ptr = reinterpret_cast<glGetQueryivPtr>(get_function("glGetQueryiv"))) == nullptr || result;
    result = (glGetQueryObjectiv_ptr = reinterpret_cast<glGetQueryObjectivPtr>(get_function("glGetQueryObjectiv"))) == nullptr || result;
    result = (glGetQueryObjectuiv_ptr = reinterpret_cast<glGetQueryObjectuivPtr>(get_function("glGetQueryObjectuiv"))) == nullptr || result;
    result = (glBindBuffer_ptr = reinterpret_cast<glBindBufferPtr>(get_function("glBindBuffer"))) == nullptr || result;
    result = (glDeleteBuffers_ptr = reinterpret_cast<glDeleteBuffersPtr>(get_function("glDeleteBuffers"))) == nullptr || result;
    result = (glGenBuffers_ptr = reinterpret_cast<glGenBuffersPtr>(get_function("glGenBuffers"))) == nullptr || result;
    result = (glIsBuffer_ptr = reinterpret_cast<glIsBufferPtr>(get_function("glIsBuffer"))) == nullptr || result;
    result = (glBufferData_ptr = reinterpret_cast<glBufferDataPtr>(get_function("glBufferData"))) == nullptr || result;
    result = (glBufferSubData_ptr = reinterpret_cast<glBufferSubDataPtr>(get_function("glBufferSubData"))) == nullptr || result;
    result = (glGetBufferSubData_ptr = reinterpret_cast<glGetBufferSubDataPtr>(get_function("glGetBufferSubData"))) == nullptr || result;
    result = (glMapBuffer_ptr = reinterpret_cast<glMapBufferPtr>(get_function("glMapBuffer"))) == nullptr || result;
    result = (glUnmapBuffer_ptr = reinterpret_cast<glUnmapBufferPtr>(get_function("glUnmapBuffer"))) == nullptr || result;
    result = (glGetBufferParameteriv_ptr = reinterpret_cast<glGetBufferParameterivPtr>(get_function("glGetBufferParameteriv"))) == nullptr || result;
    result = (glGetBufferPointerv_ptr = reinterpret_cast<glGetBufferPointervPtr>(get_function("glGetBufferPointerv"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_VERSION_2_0

using glBlendEquationSeparatePtr    = std::add_pointer_t<decltype(glBlendEquationSeparate)>;
using glDrawBuffersPtr              = std::add_pointer_t<decltype(glDrawBuffers)>;
using glStencilOpSeparatePtr        = std::add_pointer_t<decltype(glStencilOpSeparate)>;
using glStencilFuncSeparatePtr      = std::add_pointer_t<decltype(glStencilFuncSeparate)>;
using glStencilMaskSeparatePtr      = std::add_pointer_t<decltype(glStencilMaskSeparate)>;
using glAttachShaderPtr             = std::add_pointer_t<decltype(glAttachShader)>;
using glBindAttribLocationPtr       = std::add_pointer_t<decltype(glBindAttribLocation)>;
using glCompileShaderPtr            = std::add_pointer_t<decltype(glCompileShader)>;
using glCreateProgramPtr            = std::add_pointer_t<decltype(glCreateProgram)>;
using glCreateShaderPtr             = std::add_pointer_t<decltype(glCreateShader)>;
using glDeleteProgramPtr            = std::add_pointer_t<decltype(glDeleteProgram)>;
using glDeleteShaderPtr             = std::add_pointer_t<decltype(glDeleteShader)>;
using glDetachShaderPtr             = std::add_pointer_t<decltype(glDetachShader)>;
using glDisableVertexAttribArrayPtr = std::add_pointer_t<decltype(glDisableVertexAttribArray)>;
using glEnableVertexAttribArrayPtr  = std::add_pointer_t<decltype(glEnableVertexAttribArray)>;
using glGetActiveAttribPtr          = std::add_pointer_t<decltype(glGetActiveAttrib)>;
using glGetActiveUniformPtr         = std::add_pointer_t<decltype(glGetActiveUniform)>;
using glGetAttachedShadersPtr       = std::add_pointer_t<decltype(glGetAttachedShaders)>;
using glGetAttribLocationPtr        = std::add_pointer_t<decltype(glGetAttribLocation)>;
using glGetProgramivPtr             = std::add_pointer_t<decltype(glGetProgramiv)>;
using glGetProgramInfoLogPtr        = std::add_pointer_t<decltype(glGetProgramInfoLog)>;
using glGetShaderivPtr              = std::add_pointer_t<decltype(glGetShaderiv)>;
using glGetShaderInfoLogPtr         = std::add_pointer_t<decltype(glGetShaderInfoLog)>;
using glGetShaderSourcePtr          = std::add_pointer_t<decltype(glGetShaderSource)>;
using glGetUniformLocationPtr       = std::add_pointer_t<decltype(glGetUniformLocation)>;
using glGetUniformfvPtr             = std::add_pointer_t<decltype(glGetUniformfv)>;
using glGetUniformivPtr             = std::add_pointer_t<decltype(glGetUniformiv)>;
using glGetVertexAttribdvPtr        = std::add_pointer_t<decltype(glGetVertexAttribdv)>;
using glGetVertexAttribfvPtr        = std::add_pointer_t<decltype(glGetVertexAttribfv)>;
using glGetVertexAttribivPtr        = std::add_pointer_t<decltype(glGetVertexAttribiv)>;
using glGetVertexAttribPointervPtr  = std::add_pointer_t<decltype(glGetVertexAttribPointerv)>;
using glIsProgramPtr                = std::add_pointer_t<decltype(glIsProgram)>;
using glIsShaderPtr                 = std::add_pointer_t<decltype(glIsShader)>;
using glLinkProgramPtr              = std::add_pointer_t<decltype(glLinkProgram)>;
using glShaderSourcePtr             = std::add_pointer_t<decltype(glShaderSource)>;
using glUseProgramPtr               = std::add_pointer_t<decltype(glUseProgram)>;
using glUniform1fPtr                = std::add_pointer_t<decltype(glUniform1f)>;
using glUniform2fPtr                = std::add_pointer_t<decltype(glUniform2f)>;
using glUniform3fPtr                = std::add_pointer_t<decltype(glUniform3f)>;
using glUniform4fPtr                = std::add_pointer_t<decltype(glUniform4f)>;
using glUniform1iPtr                = std::add_pointer_t<decltype(glUniform1i)>;
using glUniform2iPtr                = std::add_pointer_t<decltype(glUniform2i)>;
using glUniform3iPtr                = std::add_pointer_t<decltype(glUniform3i)>;
using glUniform4iPtr                = std::add_pointer_t<decltype(glUniform4i)>;
using glUniform1fvPtr               = std::add_pointer_t<decltype(glUniform1fv)>;
using glUniform2fvPtr               = std::add_pointer_t<decltype(glUniform2fv)>;
using glUniform3fvPtr               = std::add_pointer_t<decltype(glUniform3fv)>;
using glUniform4fvPtr               = std::add_pointer_t<decltype(glUniform4fv)>;
using glUniform1ivPtr               = std::add_pointer_t<decltype(glUniform1iv)>;
using glUniform2ivPtr               = std::add_pointer_t<decltype(glUniform2iv)>;
using glUniform3ivPtr               = std::add_pointer_t<decltype(glUniform3iv)>;
using glUniform4ivPtr               = std::add_pointer_t<decltype(glUniform4iv)>;
using glUniformMatrix2fvPtr         = std::add_pointer_t<decltype(glUniformMatrix2fv)>;
using glUniformMatrix3fvPtr         = std::add_pointer_t<decltype(glUniformMatrix3fv)>;
using glUniformMatrix4fvPtr         = std::add_pointer_t<decltype(glUniformMatrix4fv)>;
using glValidateProgramPtr          = std::add_pointer_t<decltype(glValidateProgram)>;
using glVertexAttrib1dPtr           = std::add_pointer_t<decltype(glVertexAttrib1d)>;
using glVertexAttrib1dvPtr          = std::add_pointer_t<decltype(glVertexAttrib1dv)>;
using glVertexAttrib1fPtr           = std::add_pointer_t<decltype(glVertexAttrib1f)>;
using glVertexAttrib1fvPtr          = std::add_pointer_t<decltype(glVertexAttrib1fv)>;
using glVertexAttrib1sPtr           = std::add_pointer_t<decltype(glVertexAttrib1s)>;
using glVertexAttrib1svPtr          = std::add_pointer_t<decltype(glVertexAttrib1sv)>;
using glVertexAttrib2dPtr           = std::add_pointer_t<decltype(glVertexAttrib2d)>;
using glVertexAttrib2dvPtr          = std::add_pointer_t<decltype(glVertexAttrib2dv)>;
using glVertexAttrib2fPtr           = std::add_pointer_t<decltype(glVertexAttrib2f)>;
using glVertexAttrib2fvPtr          = std::add_pointer_t<decltype(glVertexAttrib2fv)>;
using glVertexAttrib2sPtr           = std::add_pointer_t<decltype(glVertexAttrib2s)>;
using glVertexAttrib2svPtr          = std::add_pointer_t<decltype(glVertexAttrib2sv)>;
using glVertexAttrib3dPtr           = std::add_pointer_t<decltype(glVertexAttrib3d)>;
using glVertexAttrib3dvPtr          = std::add_pointer_t<decltype(glVertexAttrib3dv)>;
using glVertexAttrib3fPtr           = std::add_pointer_t<decltype(glVertexAttrib3f)>;
using glVertexAttrib3fvPtr          = std::add_pointer_t<decltype(glVertexAttrib3fv)>;
using glVertexAttrib3sPtr           = std::add_pointer_t<decltype(glVertexAttrib3s)>;
using glVertexAttrib3svPtr          = std::add_pointer_t<decltype(glVertexAttrib3sv)>;
using glVertexAttrib4NbvPtr         = std::add_pointer_t<decltype(glVertexAttrib4Nbv)>;
using glVertexAttrib4NivPtr         = std::add_pointer_t<decltype(glVertexAttrib4Niv)>;
using glVertexAttrib4NsvPtr         = std::add_pointer_t<decltype(glVertexAttrib4Nsv)>;
using glVertexAttrib4NubPtr         = std::add_pointer_t<decltype(glVertexAttrib4Nub)>;
using glVertexAttrib4NubvPtr        = std::add_pointer_t<decltype(glVertexAttrib4Nubv)>;
using glVertexAttrib4NuivPtr        = std::add_pointer_t<decltype(glVertexAttrib4Nuiv)>;
using glVertexAttrib4NusvPtr        = std::add_pointer_t<decltype(glVertexAttrib4Nusv)>;
using glVertexAttrib4bvPtr          = std::add_pointer_t<decltype(glVertexAttrib4bv)>;
using glVertexAttrib4dPtr           = std::add_pointer_t<decltype(glVertexAttrib4d)>;
using glVertexAttrib4dvPtr          = std::add_pointer_t<decltype(glVertexAttrib4dv)>;
using glVertexAttrib4fPtr           = std::add_pointer_t<decltype(glVertexAttrib4f)>;
using glVertexAttrib4fvPtr          = std::add_pointer_t<decltype(glVertexAttrib4fv)>;
using glVertexAttrib4ivPtr          = std::add_pointer_t<decltype(glVertexAttrib4iv)>;
using glVertexAttrib4sPtr           = std::add_pointer_t<decltype(glVertexAttrib4s)>;
using glVertexAttrib4svPtr          = std::add_pointer_t<decltype(glVertexAttrib4sv)>;
using glVertexAttrib4ubvPtr         = std::add_pointer_t<decltype(glVertexAttrib4ubv)>;
using glVertexAttrib4uivPtr         = std::add_pointer_t<decltype(glVertexAttrib4uiv)>;
using glVertexAttrib4usvPtr         = std::add_pointer_t<decltype(glVertexAttrib4usv)>;
using glVertexAttribPointerPtr      = std::add_pointer_t<decltype(glVertexAttribPointer)>;

glBlendEquationSeparatePtr glBlendEquationSeparate_ptr       = nullptr;
glDrawBuffersPtr glDrawBuffers_ptr                           = nullptr;
glStencilOpSeparatePtr glStencilOpSeparate_ptr               = nullptr;
glStencilFuncSeparatePtr glStencilFuncSeparate_ptr           = nullptr;
glStencilMaskSeparatePtr glStencilMaskSeparate_ptr           = nullptr;
glAttachShaderPtr glAttachShader_ptr                         = nullptr;
glBindAttribLocationPtr glBindAttribLocation_ptr             = nullptr;
glCompileShaderPtr glCompileShader_ptr                       = nullptr;
glCreateProgramPtr glCreateProgram_ptr                       = nullptr;
glCreateShaderPtr glCreateShader_ptr                         = nullptr;
glDeleteProgramPtr glDeleteProgram_ptr                       = nullptr;
glDeleteShaderPtr glDeleteShader_ptr                         = nullptr;
glDetachShaderPtr glDetachShader_ptr                         = nullptr;
glDisableVertexAttribArrayPtr glDisableVertexAttribArray_ptr = nullptr;
glEnableVertexAttribArrayPtr glEnableVertexAttribArray_ptr   = nullptr;
glGetActiveAttribPtr glGetActiveAttrib_ptr                   = nullptr;
glGetActiveUniformPtr glGetActiveUniform_ptr                 = nullptr;
glGetAttachedShadersPtr glGetAttachedShaders_ptr             = nullptr;
glGetAttribLocationPtr glGetAttribLocation_ptr               = nullptr;
glGetProgramivPtr glGetProgramiv_ptr                         = nullptr;
glGetProgramInfoLogPtr glGetProgramInfoLog_ptr               = nullptr;
glGetShaderivPtr glGetShaderiv_ptr                           = nullptr;
glGetShaderInfoLogPtr glGetShaderInfoLog_ptr                 = nullptr;
glGetShaderSourcePtr glGetShaderSource_ptr                   = nullptr;
glGetUniformLocationPtr glGetUniformLocation_ptr             = nullptr;
glGetUniformfvPtr glGetUniformfv_ptr                         = nullptr;
glGetUniformivPtr glGetUniformiv_ptr                         = nullptr;
glGetVertexAttribdvPtr glGetVertexAttribdv_ptr               = nullptr;
glGetVertexAttribfvPtr glGetVertexAttribfv_ptr               = nullptr;
glGetVertexAttribivPtr glGetVertexAttribiv_ptr               = nullptr;
glGetVertexAttribPointervPtr glGetVertexAttribPointerv_ptr   = nullptr;
glIsProgramPtr glIsProgram_ptr                               = nullptr;
glIsShaderPtr glIsShader_ptr                                 = nullptr;
glLinkProgramPtr glLinkProgram_ptr                           = nullptr;
glShaderSourcePtr glShaderSource_ptr                         = nullptr;
glUseProgramPtr glUseProgram_ptr                             = nullptr;
glUniform1fPtr glUniform1f_ptr                               = nullptr;
glUniform2fPtr glUniform2f_ptr                               = nullptr;
glUniform3fPtr glUniform3f_ptr                               = nullptr;
glUniform4fPtr glUniform4f_ptr                               = nullptr;
glUniform1iPtr glUniform1i_ptr                               = nullptr;
glUniform2iPtr glUniform2i_ptr                               = nullptr;
glUniform3iPtr glUniform3i_ptr                               = nullptr;
glUniform4iPtr glUniform4i_ptr                               = nullptr;
glUniform1fvPtr glUniform1fv_ptr                             = nullptr;
glUniform2fvPtr glUniform2fv_ptr                             = nullptr;
glUniform3fvPtr glUniform3fv_ptr                             = nullptr;
glUniform4fvPtr glUniform4fv_ptr                             = nullptr;
glUniform1ivPtr glUniform1iv_ptr                             = nullptr;
glUniform2ivPtr glUniform2iv_ptr                             = nullptr;
glUniform3ivPtr glUniform3iv_ptr                             = nullptr;
glUniform4ivPtr glUniform4iv_ptr                             = nullptr;
glUniformMatrix2fvPtr glUniformMatrix2fv_ptr                 = nullptr;
glUniformMatrix3fvPtr glUniformMatrix3fv_ptr                 = nullptr;
glUniformMatrix4fvPtr glUniformMatrix4fv_ptr                 = nullptr;
glValidateProgramPtr glValidateProgram_ptr                   = nullptr;
glVertexAttrib1dPtr glVertexAttrib1d_ptr                     = nullptr;
glVertexAttrib1dvPtr glVertexAttrib1dv_ptr                   = nullptr;
glVertexAttrib1fPtr glVertexAttrib1f_ptr                     = nullptr;
glVertexAttrib1fvPtr glVertexAttrib1fv_ptr                   = nullptr;
glVertexAttrib1sPtr glVertexAttrib1s_ptr                     = nullptr;
glVertexAttrib1svPtr glVertexAttrib1sv_ptr                   = nullptr;
glVertexAttrib2dPtr glVertexAttrib2d_ptr                     = nullptr;
glVertexAttrib2dvPtr glVertexAttrib2dv_ptr                   = nullptr;
glVertexAttrib2fPtr glVertexAttrib2f_ptr                     = nullptr;
glVertexAttrib2fvPtr glVertexAttrib2fv_ptr                   = nullptr;
glVertexAttrib2sPtr glVertexAttrib2s_ptr                     = nullptr;
glVertexAttrib2svPtr glVertexAttrib2sv_ptr                   = nullptr;
glVertexAttrib3dPtr glVertexAttrib3d_ptr                     = nullptr;
glVertexAttrib3dvPtr glVertexAttrib3dv_ptr                   = nullptr;
glVertexAttrib3fPtr glVertexAttrib3f_ptr                     = nullptr;
glVertexAttrib3fvPtr glVertexAttrib3fv_ptr                   = nullptr;
glVertexAttrib3sPtr glVertexAttrib3s_ptr                     = nullptr;
glVertexAttrib3svPtr glVertexAttrib3sv_ptr                   = nullptr;
glVertexAttrib4NbvPtr glVertexAttrib4Nbv_ptr                 = nullptr;
glVertexAttrib4NivPtr glVertexAttrib4Niv_ptr                 = nullptr;
glVertexAttrib4NsvPtr glVertexAttrib4Nsv_ptr                 = nullptr;
glVertexAttrib4NubPtr glVertexAttrib4Nub_ptr                 = nullptr;
glVertexAttrib4NubvPtr glVertexAttrib4Nubv_ptr               = nullptr;
glVertexAttrib4NuivPtr glVertexAttrib4Nuiv_ptr               = nullptr;
glVertexAttrib4NusvPtr glVertexAttrib4Nusv_ptr               = nullptr;
glVertexAttrib4bvPtr glVertexAttrib4bv_ptr                   = nullptr;
glVertexAttrib4dPtr glVertexAttrib4d_ptr                     = nullptr;
glVertexAttrib4dvPtr glVertexAttrib4dv_ptr                   = nullptr;
glVertexAttrib4fPtr glVertexAttrib4f_ptr                     = nullptr;
glVertexAttrib4fvPtr glVertexAttrib4fv_ptr                   = nullptr;
glVertexAttrib4ivPtr glVertexAttrib4iv_ptr                   = nullptr;
glVertexAttrib4sPtr glVertexAttrib4s_ptr                     = nullptr;
glVertexAttrib4svPtr glVertexAttrib4sv_ptr                   = nullptr;
glVertexAttrib4ubvPtr glVertexAttrib4ubv_ptr                 = nullptr;
glVertexAttrib4uivPtr glVertexAttrib4uiv_ptr                 = nullptr;
glVertexAttrib4usvPtr glVertexAttrib4usv_ptr                 = nullptr;
glVertexAttribPointerPtr glVertexAttribPointer_ptr           = nullptr;

bool init_gl_version_2_0([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glBlendEquationSeparate_ptr = reinterpret_cast<glBlendEquationSeparatePtr>(get_function("glBlendEquationSeparate"))) == nullptr || result;
    result = (glDrawBuffers_ptr = reinterpret_cast<glDrawBuffersPtr>(get_function("glDrawBuffers"))) == nullptr || result;
    result = (glStencilOpSeparate_ptr = reinterpret_cast<glStencilOpSeparatePtr>(get_function("glStencilOpSeparate"))) == nullptr || result;
    result = (glStencilFuncSeparate_ptr = reinterpret_cast<glStencilFuncSeparatePtr>(get_function("glStencilFuncSeparate"))) == nullptr || result;
    result = (glStencilMaskSeparate_ptr = reinterpret_cast<glStencilMaskSeparatePtr>(get_function("glStencilMaskSeparate"))) == nullptr || result;
    result = (glAttachShader_ptr = reinterpret_cast<glAttachShaderPtr>(get_function("glAttachShader"))) == nullptr || result;
    result = (glBindAttribLocation_ptr = reinterpret_cast<glBindAttribLocationPtr>(get_function("glBindAttribLocation"))) == nullptr || result;
    result = (glCompileShader_ptr = reinterpret_cast<glCompileShaderPtr>(get_function("glCompileShader"))) == nullptr || result;
    result = (glCreateProgram_ptr = reinterpret_cast<glCreateProgramPtr>(get_function("glCreateProgram"))) == nullptr || result;
    result = (glCreateShader_ptr = reinterpret_cast<glCreateShaderPtr>(get_function("glCreateShader"))) == nullptr || result;
    result = (glDeleteProgram_ptr = reinterpret_cast<glDeleteProgramPtr>(get_function("glDeleteProgram"))) == nullptr || result;
    result = (glDeleteShader_ptr = reinterpret_cast<glDeleteShaderPtr>(get_function("glDeleteShader"))) == nullptr || result;
    result = (glDetachShader_ptr = reinterpret_cast<glDetachShaderPtr>(get_function("glDetachShader"))) == nullptr || result;
    result = (glDisableVertexAttribArray_ptr = reinterpret_cast<glDisableVertexAttribArrayPtr>(get_function("glDisableVertexAttribArray"))) == nullptr || result;
    result = (glEnableVertexAttribArray_ptr = reinterpret_cast<glEnableVertexAttribArrayPtr>(get_function("glEnableVertexAttribArray"))) == nullptr || result;
    result = (glGetActiveAttrib_ptr = reinterpret_cast<glGetActiveAttribPtr>(get_function("glGetActiveAttrib"))) == nullptr || result;
    result = (glGetActiveUniform_ptr = reinterpret_cast<glGetActiveUniformPtr>(get_function("glGetActiveUniform"))) == nullptr || result;
    result = (glGetAttachedShaders_ptr = reinterpret_cast<glGetAttachedShadersPtr>(get_function("glGetAttachedShaders"))) == nullptr || result;
    result = (glGetAttribLocation_ptr = reinterpret_cast<glGetAttribLocationPtr>(get_function("glGetAttribLocation"))) == nullptr || result;
    result = (glGetProgramiv_ptr = reinterpret_cast<glGetProgramivPtr>(get_function("glGetProgramiv"))) == nullptr || result;
    result = (glGetProgramInfoLog_ptr = reinterpret_cast<glGetProgramInfoLogPtr>(get_function("glGetProgramInfoLog"))) == nullptr || result;
    result = (glGetShaderiv_ptr = reinterpret_cast<glGetShaderivPtr>(get_function("glGetShaderiv"))) == nullptr || result;
    result = (glGetShaderInfoLog_ptr = reinterpret_cast<glGetShaderInfoLogPtr>(get_function("glGetShaderInfoLog"))) == nullptr || result;
    result = (glGetShaderSource_ptr = reinterpret_cast<glGetShaderSourcePtr>(get_function("glGetShaderSource"))) == nullptr || result;
    result = (glGetUniformLocation_ptr = reinterpret_cast<glGetUniformLocationPtr>(get_function("glGetUniformLocation"))) == nullptr || result;
    result = (glGetUniformfv_ptr = reinterpret_cast<glGetUniformfvPtr>(get_function("glGetUniformfv"))) == nullptr || result;
    result = (glGetUniformiv_ptr = reinterpret_cast<glGetUniformivPtr>(get_function("glGetUniformiv"))) == nullptr || result;
    result = (glGetVertexAttribdv_ptr = reinterpret_cast<glGetVertexAttribdvPtr>(get_function("glGetVertexAttribdv"))) == nullptr || result;
    result = (glGetVertexAttribfv_ptr = reinterpret_cast<glGetVertexAttribfvPtr>(get_function("glGetVertexAttribfv"))) == nullptr || result;
    result = (glGetVertexAttribiv_ptr = reinterpret_cast<glGetVertexAttribivPtr>(get_function("glGetVertexAttribiv"))) == nullptr || result;
    result = (glGetVertexAttribPointerv_ptr = reinterpret_cast<glGetVertexAttribPointervPtr>(get_function("glGetVertexAttribPointerv"))) == nullptr || result;
    result = (glIsProgram_ptr = reinterpret_cast<glIsProgramPtr>(get_function("glIsProgram"))) == nullptr || result;
    result = (glIsShader_ptr = reinterpret_cast<glIsShaderPtr>(get_function("glIsShader"))) == nullptr || result;
    result = (glLinkProgram_ptr = reinterpret_cast<glLinkProgramPtr>(get_function("glLinkProgram"))) == nullptr || result;
    result = (glShaderSource_ptr = reinterpret_cast<glShaderSourcePtr>(get_function("glShaderSource"))) == nullptr || result;
    result = (glUseProgram_ptr = reinterpret_cast<glUseProgramPtr>(get_function("glUseProgram"))) == nullptr || result;
    result = (glUniform1f_ptr = reinterpret_cast<glUniform1fPtr>(get_function("glUniform1f"))) == nullptr || result;
    result = (glUniform2f_ptr = reinterpret_cast<glUniform2fPtr>(get_function("glUniform2f"))) == nullptr || result;
    result = (glUniform3f_ptr = reinterpret_cast<glUniform3fPtr>(get_function("glUniform3f"))) == nullptr || result;
    result = (glUniform4f_ptr = reinterpret_cast<glUniform4fPtr>(get_function("glUniform4f"))) == nullptr || result;
    result = (glUniform1i_ptr = reinterpret_cast<glUniform1iPtr>(get_function("glUniform1i"))) == nullptr || result;
    result = (glUniform2i_ptr = reinterpret_cast<glUniform2iPtr>(get_function("glUniform2i"))) == nullptr || result;
    result = (glUniform3i_ptr = reinterpret_cast<glUniform3iPtr>(get_function("glUniform3i"))) == nullptr || result;
    result = (glUniform4i_ptr = reinterpret_cast<glUniform4iPtr>(get_function("glUniform4i"))) == nullptr || result;
    result = (glUniform1fv_ptr = reinterpret_cast<glUniform1fvPtr>(get_function("glUniform1fv"))) == nullptr || result;
    result = (glUniform2fv_ptr = reinterpret_cast<glUniform2fvPtr>(get_function("glUniform2fv"))) == nullptr || result;
    result = (glUniform3fv_ptr = reinterpret_cast<glUniform3fvPtr>(get_function("glUniform3fv"))) == nullptr || result;
    result = (glUniform4fv_ptr = reinterpret_cast<glUniform4fvPtr>(get_function("glUniform4fv"))) == nullptr || result;
    result = (glUniform1iv_ptr = reinterpret_cast<glUniform1ivPtr>(get_function("glUniform1iv"))) == nullptr || result;
    result = (glUniform2iv_ptr = reinterpret_cast<glUniform2ivPtr>(get_function("glUniform2iv"))) == nullptr || result;
    result = (glUniform3iv_ptr = reinterpret_cast<glUniform3ivPtr>(get_function("glUniform3iv"))) == nullptr || result;
    result = (glUniform4iv_ptr = reinterpret_cast<glUniform4ivPtr>(get_function("glUniform4iv"))) == nullptr || result;
    result = (glUniformMatrix2fv_ptr = reinterpret_cast<glUniformMatrix2fvPtr>(get_function("glUniformMatrix2fv"))) == nullptr || result;
    result = (glUniformMatrix3fv_ptr = reinterpret_cast<glUniformMatrix3fvPtr>(get_function("glUniformMatrix3fv"))) == nullptr || result;
    result = (glUniformMatrix4fv_ptr = reinterpret_cast<glUniformMatrix4fvPtr>(get_function("glUniformMatrix4fv"))) == nullptr || result;
    result = (glValidateProgram_ptr = reinterpret_cast<glValidateProgramPtr>(get_function("glValidateProgram"))) == nullptr || result;
    result = (glVertexAttrib1d_ptr = reinterpret_cast<glVertexAttrib1dPtr>(get_function("glVertexAttrib1d"))) == nullptr || result;
    result = (glVertexAttrib1dv_ptr = reinterpret_cast<glVertexAttrib1dvPtr>(get_function("glVertexAttrib1dv"))) == nullptr || result;
    result = (glVertexAttrib1f_ptr = reinterpret_cast<glVertexAttrib1fPtr>(get_function("glVertexAttrib1f"))) == nullptr || result;
    result = (glVertexAttrib1fv_ptr = reinterpret_cast<glVertexAttrib1fvPtr>(get_function("glVertexAttrib1fv"))) == nullptr || result;
    result = (glVertexAttrib1s_ptr = reinterpret_cast<glVertexAttrib1sPtr>(get_function("glVertexAttrib1s"))) == nullptr || result;
    result = (glVertexAttrib1sv_ptr = reinterpret_cast<glVertexAttrib1svPtr>(get_function("glVertexAttrib1sv"))) == nullptr || result;
    result = (glVertexAttrib2d_ptr = reinterpret_cast<glVertexAttrib2dPtr>(get_function("glVertexAttrib2d"))) == nullptr || result;
    result = (glVertexAttrib2dv_ptr = reinterpret_cast<glVertexAttrib2dvPtr>(get_function("glVertexAttrib2dv"))) == nullptr || result;
    result = (glVertexAttrib2f_ptr = reinterpret_cast<glVertexAttrib2fPtr>(get_function("glVertexAttrib2f"))) == nullptr || result;
    result = (glVertexAttrib2fv_ptr = reinterpret_cast<glVertexAttrib2fvPtr>(get_function("glVertexAttrib2fv"))) == nullptr || result;
    result = (glVertexAttrib2s_ptr = reinterpret_cast<glVertexAttrib2sPtr>(get_function("glVertexAttrib2s"))) == nullptr || result;
    result = (glVertexAttrib2sv_ptr = reinterpret_cast<glVertexAttrib2svPtr>(get_function("glVertexAttrib2sv"))) == nullptr || result;
    result = (glVertexAttrib3d_ptr = reinterpret_cast<glVertexAttrib3dPtr>(get_function("glVertexAttrib3d"))) == nullptr || result;
    result = (glVertexAttrib3dv_ptr = reinterpret_cast<glVertexAttrib3dvPtr>(get_function("glVertexAttrib3dv"))) == nullptr || result;
    result = (glVertexAttrib3f_ptr = reinterpret_cast<glVertexAttrib3fPtr>(get_function("glVertexAttrib3f"))) == nullptr || result;
    result = (glVertexAttrib3fv_ptr = reinterpret_cast<glVertexAttrib3fvPtr>(get_function("glVertexAttrib3fv"))) == nullptr || result;
    result = (glVertexAttrib3s_ptr = reinterpret_cast<glVertexAttrib3sPtr>(get_function("glVertexAttrib3s"))) == nullptr || result;
    result = (glVertexAttrib3sv_ptr = reinterpret_cast<glVertexAttrib3svPtr>(get_function("glVertexAttrib3sv"))) == nullptr || result;
    result = (glVertexAttrib4Nbv_ptr = reinterpret_cast<glVertexAttrib4NbvPtr>(get_function("glVertexAttrib4Nbv"))) == nullptr || result;
    result = (glVertexAttrib4Niv_ptr = reinterpret_cast<glVertexAttrib4NivPtr>(get_function("glVertexAttrib4Niv"))) == nullptr || result;
    result = (glVertexAttrib4Nsv_ptr = reinterpret_cast<glVertexAttrib4NsvPtr>(get_function("glVertexAttrib4Nsv"))) == nullptr || result;
    result = (glVertexAttrib4Nub_ptr = reinterpret_cast<glVertexAttrib4NubPtr>(get_function("glVertexAttrib4Nub"))) == nullptr || result;
    result = (glVertexAttrib4Nubv_ptr = reinterpret_cast<glVertexAttrib4NubvPtr>(get_function("glVertexAttrib4Nubv"))) == nullptr || result;
    result = (glVertexAttrib4Nuiv_ptr = reinterpret_cast<glVertexAttrib4NuivPtr>(get_function("glVertexAttrib4Nuiv"))) == nullptr || result;
    result = (glVertexAttrib4Nusv_ptr = reinterpret_cast<glVertexAttrib4NusvPtr>(get_function("glVertexAttrib4Nusv"))) == nullptr || result;
    result = (glVertexAttrib4bv_ptr = reinterpret_cast<glVertexAttrib4bvPtr>(get_function("glVertexAttrib4bv"))) == nullptr || result;
    result = (glVertexAttrib4d_ptr = reinterpret_cast<glVertexAttrib4dPtr>(get_function("glVertexAttrib4d"))) == nullptr || result;
    result = (glVertexAttrib4dv_ptr = reinterpret_cast<glVertexAttrib4dvPtr>(get_function("glVertexAttrib4dv"))) == nullptr || result;
    result = (glVertexAttrib4f_ptr = reinterpret_cast<glVertexAttrib4fPtr>(get_function("glVertexAttrib4f"))) == nullptr || result;
    result = (glVertexAttrib4fv_ptr = reinterpret_cast<glVertexAttrib4fvPtr>(get_function("glVertexAttrib4fv"))) == nullptr || result;
    result = (glVertexAttrib4iv_ptr = reinterpret_cast<glVertexAttrib4ivPtr>(get_function("glVertexAttrib4iv"))) == nullptr || result;
    result = (glVertexAttrib4s_ptr = reinterpret_cast<glVertexAttrib4sPtr>(get_function("glVertexAttrib4s"))) == nullptr || result;
    result = (glVertexAttrib4sv_ptr = reinterpret_cast<glVertexAttrib4svPtr>(get_function("glVertexAttrib4sv"))) == nullptr || result;
    result = (glVertexAttrib4ubv_ptr = reinterpret_cast<glVertexAttrib4ubvPtr>(get_function("glVertexAttrib4ubv"))) == nullptr || result;
    result = (glVertexAttrib4uiv_ptr = reinterpret_cast<glVertexAttrib4uivPtr>(get_function("glVertexAttrib4uiv"))) == nullptr || result;
    result = (glVertexAttrib4usv_ptr = reinterpret_cast<glVertexAttrib4usvPtr>(get_function("glVertexAttrib4usv"))) == nullptr || result;
    result = (glVertexAttribPointer_ptr = reinterpret_cast<glVertexAttribPointerPtr>(get_function("glVertexAttribPointer"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_VERSION_2_1

using glUniformMatrix2x3fvPtr = std::add_pointer_t<decltype(glUniformMatrix2x3fv)>;
using glUniformMatrix3x2fvPtr = std::add_pointer_t<decltype(glUniformMatrix3x2fv)>;
using glUniformMatrix2x4fvPtr = std::add_pointer_t<decltype(glUniformMatrix2x4fv)>;
using glUniformMatrix4x2fvPtr = std::add_pointer_t<decltype(glUniformMatrix4x2fv)>;
using glUniformMatrix3x4fvPtr = std::add_pointer_t<decltype(glUniformMatrix3x4fv)>;
using glUniformMatrix4x3fvPtr = std::add_pointer_t<decltype(glUniformMatrix4x3fv)>;

glUniformMatrix2x3fvPtr glUniformMatrix2x3fv_ptr = nullptr;
glUniformMatrix3x2fvPtr glUniformMatrix3x2fv_ptr = nullptr;
glUniformMatrix2x4fvPtr glUniformMatrix2x4fv_ptr = nullptr;
glUniformMatrix4x2fvPtr glUniformMatrix4x2fv_ptr = nullptr;
glUniformMatrix3x4fvPtr glUniformMatrix3x4fv_ptr = nullptr;
glUniformMatrix4x3fvPtr glUniformMatrix4x3fv_ptr = nullptr;

bool init_gl_version_2_1([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glUniformMatrix2x3fv_ptr = reinterpret_cast<glUniformMatrix2x3fvPtr>(get_function("glUniformMatrix2x3fv"))) == nullptr || result;
    result = (glUniformMatrix3x2fv_ptr = reinterpret_cast<glUniformMatrix3x2fvPtr>(get_function("glUniformMatrix3x2fv"))) == nullptr || result;
    result = (glUniformMatrix2x4fv_ptr = reinterpret_cast<glUniformMatrix2x4fvPtr>(get_function("glUniformMatrix2x4fv"))) == nullptr || result;
    result = (glUniformMatrix4x2fv_ptr = reinterpret_cast<glUniformMatrix4x2fvPtr>(get_function("glUniformMatrix4x2fv"))) == nullptr || result;
    result = (glUniformMatrix3x4fv_ptr = reinterpret_cast<glUniformMatrix3x4fvPtr>(get_function("glUniformMatrix3x4fv"))) == nullptr || result;
    result = (glUniformMatrix4x3fv_ptr = reinterpret_cast<glUniformMatrix4x3fvPtr>(get_function("glUniformMatrix4x3fv"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_VERSION_3_0

using glColorMaskiPtr                          = std::add_pointer_t<decltype(glColorMaski)>;
using glGetBooleani_vPtr                       = std::add_pointer_t<decltype(glGetBooleani_v)>;
using glGetIntegeri_vPtr                       = std::add_pointer_t<decltype(glGetIntegeri_v)>;
using glEnableiPtr                             = std::add_pointer_t<decltype(glEnablei)>;
using glDisableiPtr                            = std::add_pointer_t<decltype(glDisablei)>;
using glIsEnablediPtr                          = std::add_pointer_t<decltype(glIsEnabledi)>;
using glBeginTransformFeedbackPtr              = std::add_pointer_t<decltype(glBeginTransformFeedback)>;
using glEndTransformFeedbackPtr                = std::add_pointer_t<decltype(glEndTransformFeedback)>;
using glBindBufferRangePtr                     = std::add_pointer_t<decltype(glBindBufferRange)>;
using glBindBufferBasePtr                      = std::add_pointer_t<decltype(glBindBufferBase)>;
using glTransformFeedbackVaryingsPtr           = std::add_pointer_t<decltype(glTransformFeedbackVaryings)>;
using glGetTransformFeedbackVaryingPtr         = std::add_pointer_t<decltype(glGetTransformFeedbackVarying)>;
using glClampColorPtr                          = std::add_pointer_t<decltype(glClampColor)>;
using glBeginConditionalRenderPtr              = std::add_pointer_t<decltype(glBeginConditionalRender)>;
using glEndConditionalRenderPtr                = std::add_pointer_t<decltype(glEndConditionalRender)>;
using glVertexAttribIPointerPtr                = std::add_pointer_t<decltype(glVertexAttribIPointer)>;
using glGetVertexAttribIivPtr                  = std::add_pointer_t<decltype(glGetVertexAttribIiv)>;
using glGetVertexAttribIuivPtr                 = std::add_pointer_t<decltype(glGetVertexAttribIuiv)>;
using glVertexAttribI1iPtr                     = std::add_pointer_t<decltype(glVertexAttribI1i)>;
using glVertexAttribI2iPtr                     = std::add_pointer_t<decltype(glVertexAttribI2i)>;
using glVertexAttribI3iPtr                     = std::add_pointer_t<decltype(glVertexAttribI3i)>;
using glVertexAttribI4iPtr                     = std::add_pointer_t<decltype(glVertexAttribI4i)>;
using glVertexAttribI1uiPtr                    = std::add_pointer_t<decltype(glVertexAttribI1ui)>;
using glVertexAttribI2uiPtr                    = std::add_pointer_t<decltype(glVertexAttribI2ui)>;
using glVertexAttribI3uiPtr                    = std::add_pointer_t<decltype(glVertexAttribI3ui)>;
using glVertexAttribI4uiPtr                    = std::add_pointer_t<decltype(glVertexAttribI4ui)>;
using glVertexAttribI1ivPtr                    = std::add_pointer_t<decltype(glVertexAttribI1iv)>;
using glVertexAttribI2ivPtr                    = std::add_pointer_t<decltype(glVertexAttribI2iv)>;
using glVertexAttribI3ivPtr                    = std::add_pointer_t<decltype(glVertexAttribI3iv)>;
using glVertexAttribI4ivPtr                    = std::add_pointer_t<decltype(glVertexAttribI4iv)>;
using glVertexAttribI1uivPtr                   = std::add_pointer_t<decltype(glVertexAttribI1uiv)>;
using glVertexAttribI2uivPtr                   = std::add_pointer_t<decltype(glVertexAttribI2uiv)>;
using glVertexAttribI3uivPtr                   = std::add_pointer_t<decltype(glVertexAttribI3uiv)>;
using glVertexAttribI4uivPtr                   = std::add_pointer_t<decltype(glVertexAttribI4uiv)>;
using glVertexAttribI4bvPtr                    = std::add_pointer_t<decltype(glVertexAttribI4bv)>;
using glVertexAttribI4svPtr                    = std::add_pointer_t<decltype(glVertexAttribI4sv)>;
using glVertexAttribI4ubvPtr                   = std::add_pointer_t<decltype(glVertexAttribI4ubv)>;
using glVertexAttribI4usvPtr                   = std::add_pointer_t<decltype(glVertexAttribI4usv)>;
using glGetUniformuivPtr                       = std::add_pointer_t<decltype(glGetUniformuiv)>;
using glBindFragDataLocationPtr                = std::add_pointer_t<decltype(glBindFragDataLocation)>;
using glGetFragDataLocationPtr                 = std::add_pointer_t<decltype(glGetFragDataLocation)>;
using glUniform1uiPtr                          = std::add_pointer_t<decltype(glUniform1ui)>;
using glUniform2uiPtr                          = std::add_pointer_t<decltype(glUniform2ui)>;
using glUniform3uiPtr                          = std::add_pointer_t<decltype(glUniform3ui)>;
using glUniform4uiPtr                          = std::add_pointer_t<decltype(glUniform4ui)>;
using glUniform1uivPtr                         = std::add_pointer_t<decltype(glUniform1uiv)>;
using glUniform2uivPtr                         = std::add_pointer_t<decltype(glUniform2uiv)>;
using glUniform3uivPtr                         = std::add_pointer_t<decltype(glUniform3uiv)>;
using glUniform4uivPtr                         = std::add_pointer_t<decltype(glUniform4uiv)>;
using glTexParameterIivPtr                     = std::add_pointer_t<decltype(glTexParameterIiv)>;
using glTexParameterIuivPtr                    = std::add_pointer_t<decltype(glTexParameterIuiv)>;
using glGetTexParameterIivPtr                  = std::add_pointer_t<decltype(glGetTexParameterIiv)>;
using glGetTexParameterIuivPtr                 = std::add_pointer_t<decltype(glGetTexParameterIuiv)>;
using glClearBufferivPtr                       = std::add_pointer_t<decltype(glClearBufferiv)>;
using glClearBufferuivPtr                      = std::add_pointer_t<decltype(glClearBufferuiv)>;
using glClearBufferfvPtr                       = std::add_pointer_t<decltype(glClearBufferfv)>;
using glClearBufferfiPtr                       = std::add_pointer_t<decltype(glClearBufferfi)>;
using glGetStringiPtr                          = std::add_pointer_t<decltype(glGetStringi)>;
using glIsRenderbufferPtr                      = std::add_pointer_t<decltype(glIsRenderbuffer)>;
using glBindRenderbufferPtr                    = std::add_pointer_t<decltype(glBindRenderbuffer)>;
using glDeleteRenderbuffersPtr                 = std::add_pointer_t<decltype(glDeleteRenderbuffers)>;
using glGenRenderbuffersPtr                    = std::add_pointer_t<decltype(glGenRenderbuffers)>;
using glRenderbufferStoragePtr                 = std::add_pointer_t<decltype(glRenderbufferStorage)>;
using glGetRenderbufferParameterivPtr          = std::add_pointer_t<decltype(glGetRenderbufferParameteriv)>;
using glIsFramebufferPtr                       = std::add_pointer_t<decltype(glIsFramebuffer)>;
using glBindFramebufferPtr                     = std::add_pointer_t<decltype(glBindFramebuffer)>;
using glDeleteFramebuffersPtr                  = std::add_pointer_t<decltype(glDeleteFramebuffers)>;
using glGenFramebuffersPtr                     = std::add_pointer_t<decltype(glGenFramebuffers)>;
using glCheckFramebufferStatusPtr              = std::add_pointer_t<decltype(glCheckFramebufferStatus)>;
using glFramebufferTexture1DPtr                = std::add_pointer_t<decltype(glFramebufferTexture1D)>;
using glFramebufferTexture2DPtr                = std::add_pointer_t<decltype(glFramebufferTexture2D)>;
using glFramebufferTexture3DPtr                = std::add_pointer_t<decltype(glFramebufferTexture3D)>;
using glFramebufferRenderbufferPtr             = std::add_pointer_t<decltype(glFramebufferRenderbuffer)>;
using glGetFramebufferAttachmentParameterivPtr = std::add_pointer_t<decltype(glGetFramebufferAttachmentParameteriv)>;
using glGenerateMipmapPtr                      = std::add_pointer_t<decltype(glGenerateMipmap)>;
using glBlitFramebufferPtr                     = std::add_pointer_t<decltype(glBlitFramebuffer)>;
using glRenderbufferStorageMultisamplePtr      = std::add_pointer_t<decltype(glRenderbufferStorageMultisample)>;
using glFramebufferTextureLayerPtr             = std::add_pointer_t<decltype(glFramebufferTextureLayer)>;
using glMapBufferRangePtr                      = std::add_pointer_t<decltype(glMapBufferRange)>;
using glFlushMappedBufferRangePtr              = std::add_pointer_t<decltype(glFlushMappedBufferRange)>;
using glBindVertexArrayPtr                     = std::add_pointer_t<decltype(glBindVertexArray)>;
using glDeleteVertexArraysPtr                  = std::add_pointer_t<decltype(glDeleteVertexArrays)>;
using glGenVertexArraysPtr                     = std::add_pointer_t<decltype(glGenVertexArrays)>;
using glIsVertexArrayPtr                       = std::add_pointer_t<decltype(glIsVertexArray)>;

glColorMaskiPtr glColorMaski_ptr                                                   = nullptr;
glGetBooleani_vPtr glGetBooleani_v_ptr                                             = nullptr;
glGetIntegeri_vPtr glGetIntegeri_v_ptr                                             = nullptr;
glEnableiPtr glEnablei_ptr                                                         = nullptr;
glDisableiPtr glDisablei_ptr                                                       = nullptr;
glIsEnablediPtr glIsEnabledi_ptr                                                   = nullptr;
glBeginTransformFeedbackPtr glBeginTransformFeedback_ptr                           = nullptr;
glEndTransformFeedbackPtr glEndTransformFeedback_ptr                               = nullptr;
glBindBufferRangePtr glBindBufferRange_ptr                                         = nullptr;
glBindBufferBasePtr glBindBufferBase_ptr                                           = nullptr;
glTransformFeedbackVaryingsPtr glTransformFeedbackVaryings_ptr                     = nullptr;
glGetTransformFeedbackVaryingPtr glGetTransformFeedbackVarying_ptr                 = nullptr;
glClampColorPtr glClampColor_ptr                                                   = nullptr;
glBeginConditionalRenderPtr glBeginConditionalRender_ptr                           = nullptr;
glEndConditionalRenderPtr glEndConditionalRender_ptr                               = nullptr;
glVertexAttribIPointerPtr glVertexAttribIPointer_ptr                               = nullptr;
glGetVertexAttribIivPtr glGetVertexAttribIiv_ptr                                   = nullptr;
glGetVertexAttribIuivPtr glGetVertexAttribIuiv_ptr                                 = nullptr;
glVertexAttribI1iPtr glVertexAttribI1i_ptr                                         = nullptr;
glVertexAttribI2iPtr glVertexAttribI2i_ptr                                         = nullptr;
glVertexAttribI3iPtr glVertexAttribI3i_ptr                                         = nullptr;
glVertexAttribI4iPtr glVertexAttribI4i_ptr                                         = nullptr;
glVertexAttribI1uiPtr glVertexAttribI1ui_ptr                                       = nullptr;
glVertexAttribI2uiPtr glVertexAttribI2ui_ptr                                       = nullptr;
glVertexAttribI3uiPtr glVertexAttribI3ui_ptr                                       = nullptr;
glVertexAttribI4uiPtr glVertexAttribI4ui_ptr                                       = nullptr;
glVertexAttribI1ivPtr glVertexAttribI1iv_ptr                                       = nullptr;
glVertexAttribI2ivPtr glVertexAttribI2iv_ptr                                       = nullptr;
glVertexAttribI3ivPtr glVertexAttribI3iv_ptr                                       = nullptr;
glVertexAttribI4ivPtr glVertexAttribI4iv_ptr                                       = nullptr;
glVertexAttribI1uivPtr glVertexAttribI1uiv_ptr                                     = nullptr;
glVertexAttribI2uivPtr glVertexAttribI2uiv_ptr                                     = nullptr;
glVertexAttribI3uivPtr glVertexAttribI3uiv_ptr                                     = nullptr;
glVertexAttribI4uivPtr glVertexAttribI4uiv_ptr                                     = nullptr;
glVertexAttribI4bvPtr glVertexAttribI4bv_ptr                                       = nullptr;
glVertexAttribI4svPtr glVertexAttribI4sv_ptr                                       = nullptr;
glVertexAttribI4ubvPtr glVertexAttribI4ubv_ptr                                     = nullptr;
glVertexAttribI4usvPtr glVertexAttribI4usv_ptr                                     = nullptr;
glGetUniformuivPtr glGetUniformuiv_ptr                                             = nullptr;
glBindFragDataLocationPtr glBindFragDataLocation_ptr                               = nullptr;
glGetFragDataLocationPtr glGetFragDataLocation_ptr                                 = nullptr;
glUniform1uiPtr glUniform1ui_ptr                                                   = nullptr;
glUniform2uiPtr glUniform2ui_ptr                                                   = nullptr;
glUniform3uiPtr glUniform3ui_ptr                                                   = nullptr;
glUniform4uiPtr glUniform4ui_ptr                                                   = nullptr;
glUniform1uivPtr glUniform1uiv_ptr                                                 = nullptr;
glUniform2uivPtr glUniform2uiv_ptr                                                 = nullptr;
glUniform3uivPtr glUniform3uiv_ptr                                                 = nullptr;
glUniform4uivPtr glUniform4uiv_ptr                                                 = nullptr;
glTexParameterIivPtr glTexParameterIiv_ptr                                         = nullptr;
glTexParameterIuivPtr glTexParameterIuiv_ptr                                       = nullptr;
glGetTexParameterIivPtr glGetTexParameterIiv_ptr                                   = nullptr;
glGetTexParameterIuivPtr glGetTexParameterIuiv_ptr                                 = nullptr;
glClearBufferivPtr glClearBufferiv_ptr                                             = nullptr;
glClearBufferuivPtr glClearBufferuiv_ptr                                           = nullptr;
glClearBufferfvPtr glClearBufferfv_ptr                                             = nullptr;
glClearBufferfiPtr glClearBufferfi_ptr                                             = nullptr;
glGetStringiPtr glGetStringi_ptr                                                   = nullptr;
glIsRenderbufferPtr glIsRenderbuffer_ptr                                           = nullptr;
glBindRenderbufferPtr glBindRenderbuffer_ptr                                       = nullptr;
glDeleteRenderbuffersPtr glDeleteRenderbuffers_ptr                                 = nullptr;
glGenRenderbuffersPtr glGenRenderbuffers_ptr                                       = nullptr;
glRenderbufferStoragePtr glRenderbufferStorage_ptr                                 = nullptr;
glGetRenderbufferParameterivPtr glGetRenderbufferParameteriv_ptr                   = nullptr;
glIsFramebufferPtr glIsFramebuffer_ptr                                             = nullptr;
glBindFramebufferPtr glBindFramebuffer_ptr                                         = nullptr;
glDeleteFramebuffersPtr glDeleteFramebuffers_ptr                                   = nullptr;
glGenFramebuffersPtr glGenFramebuffers_ptr                                         = nullptr;
glCheckFramebufferStatusPtr glCheckFramebufferStatus_ptr                           = nullptr;
glFramebufferTexture1DPtr glFramebufferTexture1D_ptr                               = nullptr;
glFramebufferTexture2DPtr glFramebufferTexture2D_ptr                               = nullptr;
glFramebufferTexture3DPtr glFramebufferTexture3D_ptr                               = nullptr;
glFramebufferRenderbufferPtr glFramebufferRenderbuffer_ptr                         = nullptr;
glGetFramebufferAttachmentParameterivPtr glGetFramebufferAttachmentParameteriv_ptr = nullptr;
glGenerateMipmapPtr glGenerateMipmap_ptr                                           = nullptr;
glBlitFramebufferPtr glBlitFramebuffer_ptr                                         = nullptr;
glRenderbufferStorageMultisamplePtr glRenderbufferStorageMultisample_ptr           = nullptr;
glFramebufferTextureLayerPtr glFramebufferTextureLayer_ptr                         = nullptr;
glMapBufferRangePtr glMapBufferRange_ptr                                           = nullptr;
glFlushMappedBufferRangePtr glFlushMappedBufferRange_ptr                           = nullptr;
glBindVertexArrayPtr glBindVertexArray_ptr                                         = nullptr;
glDeleteVertexArraysPtr glDeleteVertexArrays_ptr                                   = nullptr;
glGenVertexArraysPtr glGenVertexArrays_ptr                                         = nullptr;
glIsVertexArrayPtr glIsVertexArray_ptr                                             = nullptr;

bool init_gl_version_3_0([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glColorMaski_ptr = reinterpret_cast<glColorMaskiPtr>(get_function("glColorMaski"))) == nullptr || result;
    result = (glGetBooleani_v_ptr = reinterpret_cast<glGetBooleani_vPtr>(get_function("glGetBooleani_v"))) == nullptr || result;
    result = (glGetIntegeri_v_ptr = reinterpret_cast<glGetIntegeri_vPtr>(get_function("glGetIntegeri_v"))) == nullptr || result;
    result = (glEnablei_ptr = reinterpret_cast<glEnableiPtr>(get_function("glEnablei"))) == nullptr || result;
    result = (glDisablei_ptr = reinterpret_cast<glDisableiPtr>(get_function("glDisablei"))) == nullptr || result;
    result = (glIsEnabledi_ptr = reinterpret_cast<glIsEnablediPtr>(get_function("glIsEnabledi"))) == nullptr || result;
    result = (glBeginTransformFeedback_ptr = reinterpret_cast<glBeginTransformFeedbackPtr>(get_function("glBeginTransformFeedback"))) == nullptr || result;
    result = (glEndTransformFeedback_ptr = reinterpret_cast<glEndTransformFeedbackPtr>(get_function("glEndTransformFeedback"))) == nullptr || result;
    result = (glBindBufferRange_ptr = reinterpret_cast<glBindBufferRangePtr>(get_function("glBindBufferRange"))) == nullptr || result;
    result = (glBindBufferBase_ptr = reinterpret_cast<glBindBufferBasePtr>(get_function("glBindBufferBase"))) == nullptr || result;
    result = (glTransformFeedbackVaryings_ptr = reinterpret_cast<glTransformFeedbackVaryingsPtr>(get_function("glTransformFeedbackVaryings"))) == nullptr || result;
    result = (glGetTransformFeedbackVarying_ptr = reinterpret_cast<glGetTransformFeedbackVaryingPtr>(get_function("glGetTransformFeedbackVarying"))) == nullptr || result;
    result = (glClampColor_ptr = reinterpret_cast<glClampColorPtr>(get_function("glClampColor"))) == nullptr || result;
    result = (glBeginConditionalRender_ptr = reinterpret_cast<glBeginConditionalRenderPtr>(get_function("glBeginConditionalRender"))) == nullptr || result;
    result = (glEndConditionalRender_ptr = reinterpret_cast<glEndConditionalRenderPtr>(get_function("glEndConditionalRender"))) == nullptr || result;
    result = (glVertexAttribIPointer_ptr = reinterpret_cast<glVertexAttribIPointerPtr>(get_function("glVertexAttribIPointer"))) == nullptr || result;
    result = (glGetVertexAttribIiv_ptr = reinterpret_cast<glGetVertexAttribIivPtr>(get_function("glGetVertexAttribIiv"))) == nullptr || result;
    result = (glGetVertexAttribIuiv_ptr = reinterpret_cast<glGetVertexAttribIuivPtr>(get_function("glGetVertexAttribIuiv"))) == nullptr || result;
    result = (glVertexAttribI1i_ptr = reinterpret_cast<glVertexAttribI1iPtr>(get_function("glVertexAttribI1i"))) == nullptr || result;
    result = (glVertexAttribI2i_ptr = reinterpret_cast<glVertexAttribI2iPtr>(get_function("glVertexAttribI2i"))) == nullptr || result;
    result = (glVertexAttribI3i_ptr = reinterpret_cast<glVertexAttribI3iPtr>(get_function("glVertexAttribI3i"))) == nullptr || result;
    result = (glVertexAttribI4i_ptr = reinterpret_cast<glVertexAttribI4iPtr>(get_function("glVertexAttribI4i"))) == nullptr || result;
    result = (glVertexAttribI1ui_ptr = reinterpret_cast<glVertexAttribI1uiPtr>(get_function("glVertexAttribI1ui"))) == nullptr || result;
    result = (glVertexAttribI2ui_ptr = reinterpret_cast<glVertexAttribI2uiPtr>(get_function("glVertexAttribI2ui"))) == nullptr || result;
    result = (glVertexAttribI3ui_ptr = reinterpret_cast<glVertexAttribI3uiPtr>(get_function("glVertexAttribI3ui"))) == nullptr || result;
    result = (glVertexAttribI4ui_ptr = reinterpret_cast<glVertexAttribI4uiPtr>(get_function("glVertexAttribI4ui"))) == nullptr || result;
    result = (glVertexAttribI1iv_ptr = reinterpret_cast<glVertexAttribI1ivPtr>(get_function("glVertexAttribI1iv"))) == nullptr || result;
    result = (glVertexAttribI2iv_ptr = reinterpret_cast<glVertexAttribI2ivPtr>(get_function("glVertexAttribI2iv"))) == nullptr || result;
    result = (glVertexAttribI3iv_ptr = reinterpret_cast<glVertexAttribI3ivPtr>(get_function("glVertexAttribI3iv"))) == nullptr || result;
    result = (glVertexAttribI4iv_ptr = reinterpret_cast<glVertexAttribI4ivPtr>(get_function("glVertexAttribI4iv"))) == nullptr || result;
    result = (glVertexAttribI1uiv_ptr = reinterpret_cast<glVertexAttribI1uivPtr>(get_function("glVertexAttribI1uiv"))) == nullptr || result;
    result = (glVertexAttribI2uiv_ptr = reinterpret_cast<glVertexAttribI2uivPtr>(get_function("glVertexAttribI2uiv"))) == nullptr || result;
    result = (glVertexAttribI3uiv_ptr = reinterpret_cast<glVertexAttribI3uivPtr>(get_function("glVertexAttribI3uiv"))) == nullptr || result;
    result = (glVertexAttribI4uiv_ptr = reinterpret_cast<glVertexAttribI4uivPtr>(get_function("glVertexAttribI4uiv"))) == nullptr || result;
    result = (glVertexAttribI4bv_ptr = reinterpret_cast<glVertexAttribI4bvPtr>(get_function("glVertexAttribI4bv"))) == nullptr || result;
    result = (glVertexAttribI4sv_ptr = reinterpret_cast<glVertexAttribI4svPtr>(get_function("glVertexAttribI4sv"))) == nullptr || result;
    result = (glVertexAttribI4ubv_ptr = reinterpret_cast<glVertexAttribI4ubvPtr>(get_function("glVertexAttribI4ubv"))) == nullptr || result;
    result = (glVertexAttribI4usv_ptr = reinterpret_cast<glVertexAttribI4usvPtr>(get_function("glVertexAttribI4usv"))) == nullptr || result;
    result = (glGetUniformuiv_ptr = reinterpret_cast<glGetUniformuivPtr>(get_function("glGetUniformuiv"))) == nullptr || result;
    result = (glBindFragDataLocation_ptr = reinterpret_cast<glBindFragDataLocationPtr>(get_function("glBindFragDataLocation"))) == nullptr || result;
    result = (glGetFragDataLocation_ptr = reinterpret_cast<glGetFragDataLocationPtr>(get_function("glGetFragDataLocation"))) == nullptr || result;
    result = (glUniform1ui_ptr = reinterpret_cast<glUniform1uiPtr>(get_function("glUniform1ui"))) == nullptr || result;
    result = (glUniform2ui_ptr = reinterpret_cast<glUniform2uiPtr>(get_function("glUniform2ui"))) == nullptr || result;
    result = (glUniform3ui_ptr = reinterpret_cast<glUniform3uiPtr>(get_function("glUniform3ui"))) == nullptr || result;
    result = (glUniform4ui_ptr = reinterpret_cast<glUniform4uiPtr>(get_function("glUniform4ui"))) == nullptr || result;
    result = (glUniform1uiv_ptr = reinterpret_cast<glUniform1uivPtr>(get_function("glUniform1uiv"))) == nullptr || result;
    result = (glUniform2uiv_ptr = reinterpret_cast<glUniform2uivPtr>(get_function("glUniform2uiv"))) == nullptr || result;
    result = (glUniform3uiv_ptr = reinterpret_cast<glUniform3uivPtr>(get_function("glUniform3uiv"))) == nullptr || result;
    result = (glUniform4uiv_ptr = reinterpret_cast<glUniform4uivPtr>(get_function("glUniform4uiv"))) == nullptr || result;
    result = (glTexParameterIiv_ptr = reinterpret_cast<glTexParameterIivPtr>(get_function("glTexParameterIiv"))) == nullptr || result;
    result = (glTexParameterIuiv_ptr = reinterpret_cast<glTexParameterIuivPtr>(get_function("glTexParameterIuiv"))) == nullptr || result;
    result = (glGetTexParameterIiv_ptr = reinterpret_cast<glGetTexParameterIivPtr>(get_function("glGetTexParameterIiv"))) == nullptr || result;
    result = (glGetTexParameterIuiv_ptr = reinterpret_cast<glGetTexParameterIuivPtr>(get_function("glGetTexParameterIuiv"))) == nullptr || result;
    result = (glClearBufferiv_ptr = reinterpret_cast<glClearBufferivPtr>(get_function("glClearBufferiv"))) == nullptr || result;
    result = (glClearBufferuiv_ptr = reinterpret_cast<glClearBufferuivPtr>(get_function("glClearBufferuiv"))) == nullptr || result;
    result = (glClearBufferfv_ptr = reinterpret_cast<glClearBufferfvPtr>(get_function("glClearBufferfv"))) == nullptr || result;
    result = (glClearBufferfi_ptr = reinterpret_cast<glClearBufferfiPtr>(get_function("glClearBufferfi"))) == nullptr || result;
    result = (glGetStringi_ptr = reinterpret_cast<glGetStringiPtr>(get_function("glGetStringi"))) == nullptr || result;
    result = (glIsRenderbuffer_ptr = reinterpret_cast<glIsRenderbufferPtr>(get_function("glIsRenderbuffer"))) == nullptr || result;
    result = (glBindRenderbuffer_ptr = reinterpret_cast<glBindRenderbufferPtr>(get_function("glBindRenderbuffer"))) == nullptr || result;
    result = (glDeleteRenderbuffers_ptr = reinterpret_cast<glDeleteRenderbuffersPtr>(get_function("glDeleteRenderbuffers"))) == nullptr || result;
    result = (glGenRenderbuffers_ptr = reinterpret_cast<glGenRenderbuffersPtr>(get_function("glGenRenderbuffers"))) == nullptr || result;
    result = (glRenderbufferStorage_ptr = reinterpret_cast<glRenderbufferStoragePtr>(get_function("glRenderbufferStorage"))) == nullptr || result;
    result = (glGetRenderbufferParameteriv_ptr = reinterpret_cast<glGetRenderbufferParameterivPtr>(get_function("glGetRenderbufferParameteriv"))) == nullptr || result;
    result = (glIsFramebuffer_ptr = reinterpret_cast<glIsFramebufferPtr>(get_function("glIsFramebuffer"))) == nullptr || result;
    result = (glBindFramebuffer_ptr = reinterpret_cast<glBindFramebufferPtr>(get_function("glBindFramebuffer"))) == nullptr || result;
    result = (glDeleteFramebuffers_ptr = reinterpret_cast<glDeleteFramebuffersPtr>(get_function("glDeleteFramebuffers"))) == nullptr || result;
    result = (glGenFramebuffers_ptr = reinterpret_cast<glGenFramebuffersPtr>(get_function("glGenFramebuffers"))) == nullptr || result;
    result = (glCheckFramebufferStatus_ptr = reinterpret_cast<glCheckFramebufferStatusPtr>(get_function("glCheckFramebufferStatus"))) == nullptr || result;
    result = (glFramebufferTexture1D_ptr = reinterpret_cast<glFramebufferTexture1DPtr>(get_function("glFramebufferTexture1D"))) == nullptr || result;
    result = (glFramebufferTexture2D_ptr = reinterpret_cast<glFramebufferTexture2DPtr>(get_function("glFramebufferTexture2D"))) == nullptr || result;
    result = (glFramebufferTexture3D_ptr = reinterpret_cast<glFramebufferTexture3DPtr>(get_function("glFramebufferTexture3D"))) == nullptr || result;
    result = (glFramebufferRenderbuffer_ptr = reinterpret_cast<glFramebufferRenderbufferPtr>(get_function("glFramebufferRenderbuffer"))) == nullptr || result;
    result = (glGetFramebufferAttachmentParameteriv_ptr = reinterpret_cast<glGetFramebufferAttachmentParameterivPtr>(get_function("glGetFramebufferAttachmentParameteriv"))) == nullptr || result;
    result = (glGenerateMipmap_ptr = reinterpret_cast<glGenerateMipmapPtr>(get_function("glGenerateMipmap"))) == nullptr || result;
    result = (glBlitFramebuffer_ptr = reinterpret_cast<glBlitFramebufferPtr>(get_function("glBlitFramebuffer"))) == nullptr || result;
    result = (glRenderbufferStorageMultisample_ptr = reinterpret_cast<glRenderbufferStorageMultisamplePtr>(get_function("glRenderbufferStorageMultisample"))) == nullptr || result;
    result = (glFramebufferTextureLayer_ptr = reinterpret_cast<glFramebufferTextureLayerPtr>(get_function("glFramebufferTextureLayer"))) == nullptr || result;
    result = (glMapBufferRange_ptr = reinterpret_cast<glMapBufferRangePtr>(get_function("glMapBufferRange"))) == nullptr || result;
    result = (glFlushMappedBufferRange_ptr = reinterpret_cast<glFlushMappedBufferRangePtr>(get_function("glFlushMappedBufferRange"))) == nullptr || result;
    result = (glBindVertexArray_ptr = reinterpret_cast<glBindVertexArrayPtr>(get_function("glBindVertexArray"))) == nullptr || result;
    result = (glDeleteVertexArrays_ptr = reinterpret_cast<glDeleteVertexArraysPtr>(get_function("glDeleteVertexArrays"))) == nullptr || result;
    result = (glGenVertexArrays_ptr = reinterpret_cast<glGenVertexArraysPtr>(get_function("glGenVertexArrays"))) == nullptr || result;
    result = (glIsVertexArray_ptr = reinterpret_cast<glIsVertexArrayPtr>(get_function("glIsVertexArray"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_VERSION_3_1

using glDrawArraysInstancedPtr       = std::add_pointer_t<decltype(glDrawArraysInstanced)>;
using glDrawElementsInstancedPtr     = std::add_pointer_t<decltype(glDrawElementsInstanced)>;
using glTexBufferPtr                 = std::add_pointer_t<decltype(glTexBuffer)>;
using glPrimitiveRestartIndexPtr     = std::add_pointer_t<decltype(glPrimitiveRestartIndex)>;
using glCopyBufferSubDataPtr         = std::add_pointer_t<decltype(glCopyBufferSubData)>;
using glGetUniformIndicesPtr         = std::add_pointer_t<decltype(glGetUniformIndices)>;
using glGetActiveUniformsivPtr       = std::add_pointer_t<decltype(glGetActiveUniformsiv)>;
using glGetActiveUniformNamePtr      = std::add_pointer_t<decltype(glGetActiveUniformName)>;
using glGetUniformBlockIndexPtr      = std::add_pointer_t<decltype(glGetUniformBlockIndex)>;
using glGetActiveUniformBlockivPtr   = std::add_pointer_t<decltype(glGetActiveUniformBlockiv)>;
using glGetActiveUniformBlockNamePtr = std::add_pointer_t<decltype(glGetActiveUniformBlockName)>;
using glUniformBlockBindingPtr       = std::add_pointer_t<decltype(glUniformBlockBinding)>;

glDrawArraysInstancedPtr glDrawArraysInstanced_ptr             = nullptr;
glDrawElementsInstancedPtr glDrawElementsInstanced_ptr         = nullptr;
glTexBufferPtr glTexBuffer_ptr                                 = nullptr;
glPrimitiveRestartIndexPtr glPrimitiveRestartIndex_ptr         = nullptr;
glCopyBufferSubDataPtr glCopyBufferSubData_ptr                 = nullptr;
glGetUniformIndicesPtr glGetUniformIndices_ptr                 = nullptr;
glGetActiveUniformsivPtr glGetActiveUniformsiv_ptr             = nullptr;
glGetActiveUniformNamePtr glGetActiveUniformName_ptr           = nullptr;
glGetUniformBlockIndexPtr glGetUniformBlockIndex_ptr           = nullptr;
glGetActiveUniformBlockivPtr glGetActiveUniformBlockiv_ptr     = nullptr;
glGetActiveUniformBlockNamePtr glGetActiveUniformBlockName_ptr = nullptr;
glUniformBlockBindingPtr glUniformBlockBinding_ptr             = nullptr;

bool init_gl_version_3_1([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glDrawArraysInstanced_ptr = reinterpret_cast<glDrawArraysInstancedPtr>(get_function("glDrawArraysInstanced"))) == nullptr || result;
    result = (glDrawElementsInstanced_ptr = reinterpret_cast<glDrawElementsInstancedPtr>(get_function("glDrawElementsInstanced"))) == nullptr || result;
    result = (glTexBuffer_ptr = reinterpret_cast<glTexBufferPtr>(get_function("glTexBuffer"))) == nullptr || result;
    result = (glPrimitiveRestartIndex_ptr = reinterpret_cast<glPrimitiveRestartIndexPtr>(get_function("glPrimitiveRestartIndex"))) == nullptr || result;
    result = (glCopyBufferSubData_ptr = reinterpret_cast<glCopyBufferSubDataPtr>(get_function("glCopyBufferSubData"))) == nullptr || result;
    result = (glGetUniformIndices_ptr = reinterpret_cast<glGetUniformIndicesPtr>(get_function("glGetUniformIndices"))) == nullptr || result;
    result = (glGetActiveUniformsiv_ptr = reinterpret_cast<glGetActiveUniformsivPtr>(get_function("glGetActiveUniformsiv"))) == nullptr || result;
    result = (glGetActiveUniformName_ptr = reinterpret_cast<glGetActiveUniformNamePtr>(get_function("glGetActiveUniformName"))) == nullptr || result;
    result = (glGetUniformBlockIndex_ptr = reinterpret_cast<glGetUniformBlockIndexPtr>(get_function("glGetUniformBlockIndex"))) == nullptr || result;
    result = (glGetActiveUniformBlockiv_ptr = reinterpret_cast<glGetActiveUniformBlockivPtr>(get_function("glGetActiveUniformBlockiv"))) == nullptr || result;
    result = (glGetActiveUniformBlockName_ptr = reinterpret_cast<glGetActiveUniformBlockNamePtr>(get_function("glGetActiveUniformBlockName"))) == nullptr || result;
    result = (glUniformBlockBinding_ptr = reinterpret_cast<glUniformBlockBindingPtr>(get_function("glUniformBlockBinding"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_VERSION_3_2

using glDrawElementsBaseVertexPtr          = std::add_pointer_t<decltype(glDrawElementsBaseVertex)>;
using glDrawRangeElementsBaseVertexPtr     = std::add_pointer_t<decltype(glDrawRangeElementsBaseVertex)>;
using glDrawElementsInstancedBaseVertexPtr = std::add_pointer_t<decltype(glDrawElementsInstancedBaseVertex)>;
using glMultiDrawElementsBaseVertexPtr     = std::add_pointer_t<decltype(glMultiDrawElementsBaseVertex)>;
using glProvokingVertexPtr                 = std::add_pointer_t<decltype(glProvokingVertex)>;
using glFenceSyncPtr                       = std::add_pointer_t<decltype(glFenceSync)>;
using glIsSyncPtr                          = std::add_pointer_t<decltype(glIsSync)>;
using glDeleteSyncPtr                      = std::add_pointer_t<decltype(glDeleteSync)>;
using glClientWaitSyncPtr                  = std::add_pointer_t<decltype(glClientWaitSync)>;
using glWaitSyncPtr                        = std::add_pointer_t<decltype(glWaitSync)>;
using glGetInteger64vPtr                   = std::add_pointer_t<decltype(glGetInteger64v)>;
using glGetSyncivPtr                       = std::add_pointer_t<decltype(glGetSynciv)>;
using glGetInteger64i_vPtr                 = std::add_pointer_t<decltype(glGetInteger64i_v)>;
using glGetBufferParameteri64vPtr          = std::add_pointer_t<decltype(glGetBufferParameteri64v)>;
using glFramebufferTexturePtr              = std::add_pointer_t<decltype(glFramebufferTexture)>;
using glTexImage2DMultisamplePtr           = std::add_pointer_t<decltype(glTexImage2DMultisample)>;
using glTexImage3DMultisamplePtr           = std::add_pointer_t<decltype(glTexImage3DMultisample)>;
using glGetMultisamplefvPtr                = std::add_pointer_t<decltype(glGetMultisamplefv)>;
using glSampleMaskiPtr                     = std::add_pointer_t<decltype(glSampleMaski)>;

glDrawElementsBaseVertexPtr glDrawElementsBaseVertex_ptr                   = nullptr;
glDrawRangeElementsBaseVertexPtr glDrawRangeElementsBaseVertex_ptr         = nullptr;
glDrawElementsInstancedBaseVertexPtr glDrawElementsInstancedBaseVertex_ptr = nullptr;
glMultiDrawElementsBaseVertexPtr glMultiDrawElementsBaseVertex_ptr         = nullptr;
glProvokingVertexPtr glProvokingVertex_ptr                                 = nullptr;
glFenceSyncPtr glFenceSync_ptr                                             = nullptr;
glIsSyncPtr glIsSync_ptr                                                   = nullptr;
glDeleteSyncPtr glDeleteSync_ptr                                           = nullptr;
glClientWaitSyncPtr glClientWaitSync_ptr                                   = nullptr;
glWaitSyncPtr glWaitSync_ptr                                               = nullptr;
glGetInteger64vPtr glGetInteger64v_ptr                                     = nullptr;
glGetSyncivPtr glGetSynciv_ptr                                             = nullptr;
glGetInteger64i_vPtr glGetInteger64i_v_ptr                                 = nullptr;
glGetBufferParameteri64vPtr glGetBufferParameteri64v_ptr                   = nullptr;
glFramebufferTexturePtr glFramebufferTexture_ptr                           = nullptr;
glTexImage2DMultisamplePtr glTexImage2DMultisample_ptr                     = nullptr;
glTexImage3DMultisamplePtr glTexImage3DMultisample_ptr                     = nullptr;
glGetMultisamplefvPtr glGetMultisamplefv_ptr                               = nullptr;
glSampleMaskiPtr glSampleMaski_ptr                                         = nullptr;

bool init_gl_version_3_2([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glDrawElementsBaseVertex_ptr = reinterpret_cast<glDrawElementsBaseVertexPtr>(get_function("glDrawElementsBaseVertex"))) == nullptr || result;
    result = (glDrawRangeElementsBaseVertex_ptr = reinterpret_cast<glDrawRangeElementsBaseVertexPtr>(get_function("glDrawRangeElementsBaseVertex"))) == nullptr || result;
    result = (glDrawElementsInstancedBaseVertex_ptr = reinterpret_cast<glDrawElementsInstancedBaseVertexPtr>(get_function("glDrawElementsInstancedBaseVertex"))) == nullptr || result;
    result = (glMultiDrawElementsBaseVertex_ptr = reinterpret_cast<glMultiDrawElementsBaseVertexPtr>(get_function("glMultiDrawElementsBaseVertex"))) == nullptr || result;
    result = (glProvokingVertex_ptr = reinterpret_cast<glProvokingVertexPtr>(get_function("glProvokingVertex"))) == nullptr || result;
    result = (glFenceSync_ptr = reinterpret_cast<glFenceSyncPtr>(get_function("glFenceSync"))) == nullptr || result;
    result = (glIsSync_ptr = reinterpret_cast<glIsSyncPtr>(get_function("glIsSync"))) == nullptr || result;
    result = (glDeleteSync_ptr = reinterpret_cast<glDeleteSyncPtr>(get_function("glDeleteSync"))) == nullptr || result;
    result = (glClientWaitSync_ptr = reinterpret_cast<glClientWaitSyncPtr>(get_function("glClientWaitSync"))) == nullptr || result;
    result = (glWaitSync_ptr = reinterpret_cast<glWaitSyncPtr>(get_function("glWaitSync"))) == nullptr || result;
    result = (glGetInteger64v_ptr = reinterpret_cast<glGetInteger64vPtr>(get_function("glGetInteger64v"))) == nullptr || result;
    result = (glGetSynciv_ptr = reinterpret_cast<glGetSyncivPtr>(get_function("glGetSynciv"))) == nullptr || result;
    result = (glGetInteger64i_v_ptr = reinterpret_cast<glGetInteger64i_vPtr>(get_function("glGetInteger64i_v"))) == nullptr || result;
    result = (glGetBufferParameteri64v_ptr = reinterpret_cast<glGetBufferParameteri64vPtr>(get_function("glGetBufferParameteri64v"))) == nullptr || result;
    result = (glFramebufferTexture_ptr = reinterpret_cast<glFramebufferTexturePtr>(get_function("glFramebufferTexture"))) == nullptr || result;
    result = (glTexImage2DMultisample_ptr = reinterpret_cast<glTexImage2DMultisamplePtr>(get_function("glTexImage2DMultisample"))) == nullptr || result;
    result = (glTexImage3DMultisample_ptr = reinterpret_cast<glTexImage3DMultisamplePtr>(get_function("glTexImage3DMultisample"))) == nullptr || result;
    result = (glGetMultisamplefv_ptr = reinterpret_cast<glGetMultisamplefvPtr>(get_function("glGetMultisamplefv"))) == nullptr || result;
    result = (glSampleMaski_ptr = reinterpret_cast<glSampleMaskiPtr>(get_function("glSampleMaski"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_VERSION_3_3

using glBindFragDataLocationIndexedPtr = std::add_pointer_t<decltype(glBindFragDataLocationIndexed)>;
using glGetFragDataIndexPtr            = std::add_pointer_t<decltype(glGetFragDataIndex)>;
using glGenSamplersPtr                 = std::add_pointer_t<decltype(glGenSamplers)>;
using glDeleteSamplersPtr              = std::add_pointer_t<decltype(glDeleteSamplers)>;
using glIsSamplerPtr                   = std::add_pointer_t<decltype(glIsSampler)>;
using glBindSamplerPtr                 = std::add_pointer_t<decltype(glBindSampler)>;
using glSamplerParameteriPtr           = std::add_pointer_t<decltype(glSamplerParameteri)>;
using glSamplerParameterivPtr          = std::add_pointer_t<decltype(glSamplerParameteriv)>;
using glSamplerParameterfPtr           = std::add_pointer_t<decltype(glSamplerParameterf)>;
using glSamplerParameterfvPtr          = std::add_pointer_t<decltype(glSamplerParameterfv)>;
using glSamplerParameterIivPtr         = std::add_pointer_t<decltype(glSamplerParameterIiv)>;
using glSamplerParameterIuivPtr        = std::add_pointer_t<decltype(glSamplerParameterIuiv)>;
using glGetSamplerParameterivPtr       = std::add_pointer_t<decltype(glGetSamplerParameteriv)>;
using glGetSamplerParameterIivPtr      = std::add_pointer_t<decltype(glGetSamplerParameterIiv)>;
using glGetSamplerParameterfvPtr       = std::add_pointer_t<decltype(glGetSamplerParameterfv)>;
using glGetSamplerParameterIuivPtr     = std::add_pointer_t<decltype(glGetSamplerParameterIuiv)>;
using glQueryCounterPtr                = std::add_pointer_t<decltype(glQueryCounter)>;
using glGetQueryObjecti64vPtr          = std::add_pointer_t<decltype(glGetQueryObjecti64v)>;
using glGetQueryObjectui64vPtr         = std::add_pointer_t<decltype(glGetQueryObjectui64v)>;
using glVertexAttribDivisorPtr         = std::add_pointer_t<decltype(glVertexAttribDivisor)>;
using glVertexAttribP1uiPtr            = std::add_pointer_t<decltype(glVertexAttribP1ui)>;
using glVertexAttribP1uivPtr           = std::add_pointer_t<decltype(glVertexAttribP1uiv)>;
using glVertexAttribP2uiPtr            = std::add_pointer_t<decltype(glVertexAttribP2ui)>;
using glVertexAttribP2uivPtr           = std::add_pointer_t<decltype(glVertexAttribP2uiv)>;
using glVertexAttribP3uiPtr            = std::add_pointer_t<decltype(glVertexAttribP3ui)>;
using glVertexAttribP3uivPtr           = std::add_pointer_t<decltype(glVertexAttribP3uiv)>;
using glVertexAttribP4uiPtr            = std::add_pointer_t<decltype(glVertexAttribP4ui)>;
using glVertexAttribP4uivPtr           = std::add_pointer_t<decltype(glVertexAttribP4uiv)>;

glBindFragDataLocationIndexedPtr glBindFragDataLocationIndexed_ptr = nullptr;
glGetFragDataIndexPtr glGetFragDataIndex_ptr                       = nullptr;
glGenSamplersPtr glGenSamplers_ptr                                 = nullptr;
glDeleteSamplersPtr glDeleteSamplers_ptr                           = nullptr;
glIsSamplerPtr glIsSampler_ptr                                     = nullptr;
glBindSamplerPtr glBindSampler_ptr                                 = nullptr;
glSamplerParameteriPtr glSamplerParameteri_ptr                     = nullptr;
glSamplerParameterivPtr glSamplerParameteriv_ptr                   = nullptr;
glSamplerParameterfPtr glSamplerParameterf_ptr                     = nullptr;
glSamplerParameterfvPtr glSamplerParameterfv_ptr                   = nullptr;
glSamplerParameterIivPtr glSamplerParameterIiv_ptr                 = nullptr;
glSamplerParameterIuivPtr glSamplerParameterIuiv_ptr               = nullptr;
glGetSamplerParameterivPtr glGetSamplerParameteriv_ptr             = nullptr;
glGetSamplerParameterIivPtr glGetSamplerParameterIiv_ptr           = nullptr;
glGetSamplerParameterfvPtr glGetSamplerParameterfv_ptr             = nullptr;
glGetSamplerParameterIuivPtr glGetSamplerParameterIuiv_ptr         = nullptr;
glQueryCounterPtr glQueryCounter_ptr                               = nullptr;
glGetQueryObjecti64vPtr glGetQueryObjecti64v_ptr                   = nullptr;
glGetQueryObjectui64vPtr glGetQueryObjectui64v_ptr                 = nullptr;
glVertexAttribDivisorPtr glVertexAttribDivisor_ptr                 = nullptr;
glVertexAttribP1uiPtr glVertexAttribP1ui_ptr                       = nullptr;
glVertexAttribP1uivPtr glVertexAttribP1uiv_ptr                     = nullptr;
glVertexAttribP2uiPtr glVertexAttribP2ui_ptr                       = nullptr;
glVertexAttribP2uivPtr glVertexAttribP2uiv_ptr                     = nullptr;
glVertexAttribP3uiPtr glVertexAttribP3ui_ptr                       = nullptr;
glVertexAttribP3uivPtr glVertexAttribP3uiv_ptr                     = nullptr;
glVertexAttribP4uiPtr glVertexAttribP4ui_ptr                       = nullptr;
glVertexAttribP4uivPtr glVertexAttribP4uiv_ptr                     = nullptr;

bool init_gl_version_3_3([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glBindFragDataLocationIndexed_ptr = reinterpret_cast<glBindFragDataLocationIndexedPtr>(get_function("glBindFragDataLocationIndexed"))) == nullptr || result;
    result = (glGetFragDataIndex_ptr = reinterpret_cast<glGetFragDataIndexPtr>(get_function("glGetFragDataIndex"))) == nullptr || result;
    result = (glGenSamplers_ptr = reinterpret_cast<glGenSamplersPtr>(get_function("glGenSamplers"))) == nullptr || result;
    result = (glDeleteSamplers_ptr = reinterpret_cast<glDeleteSamplersPtr>(get_function("glDeleteSamplers"))) == nullptr || result;
    result = (glIsSampler_ptr = reinterpret_cast<glIsSamplerPtr>(get_function("glIsSampler"))) == nullptr || result;
    result = (glBindSampler_ptr = reinterpret_cast<glBindSamplerPtr>(get_function("glBindSampler"))) == nullptr || result;
    result = (glSamplerParameteri_ptr = reinterpret_cast<glSamplerParameteriPtr>(get_function("glSamplerParameteri"))) == nullptr || result;
    result = (glSamplerParameteriv_ptr = reinterpret_cast<glSamplerParameterivPtr>(get_function("glSamplerParameteriv"))) == nullptr || result;
    result = (glSamplerParameterf_ptr = reinterpret_cast<glSamplerParameterfPtr>(get_function("glSamplerParameterf"))) == nullptr || result;
    result = (glSamplerParameterfv_ptr = reinterpret_cast<glSamplerParameterfvPtr>(get_function("glSamplerParameterfv"))) == nullptr || result;
    result = (glSamplerParameterIiv_ptr = reinterpret_cast<glSamplerParameterIivPtr>(get_function("glSamplerParameterIiv"))) == nullptr || result;
    result = (glSamplerParameterIuiv_ptr = reinterpret_cast<glSamplerParameterIuivPtr>(get_function("glSamplerParameterIuiv"))) == nullptr || result;
    result = (glGetSamplerParameteriv_ptr = reinterpret_cast<glGetSamplerParameterivPtr>(get_function("glGetSamplerParameteriv"))) == nullptr || result;
    result = (glGetSamplerParameterIiv_ptr = reinterpret_cast<glGetSamplerParameterIivPtr>(get_function("glGetSamplerParameterIiv"))) == nullptr || result;
    result = (glGetSamplerParameterfv_ptr = reinterpret_cast<glGetSamplerParameterfvPtr>(get_function("glGetSamplerParameterfv"))) == nullptr || result;
    result = (glGetSamplerParameterIuiv_ptr = reinterpret_cast<glGetSamplerParameterIuivPtr>(get_function("glGetSamplerParameterIuiv"))) == nullptr || result;
    result = (glQueryCounter_ptr = reinterpret_cast<glQueryCounterPtr>(get_function("glQueryCounter"))) == nullptr || result;
    result = (glGetQueryObjecti64v_ptr = reinterpret_cast<glGetQueryObjecti64vPtr>(get_function("glGetQueryObjecti64v"))) == nullptr || result;
    result = (glGetQueryObjectui64v_ptr = reinterpret_cast<glGetQueryObjectui64vPtr>(get_function("glGetQueryObjectui64v"))) == nullptr || result;
    result = (glVertexAttribDivisor_ptr = reinterpret_cast<glVertexAttribDivisorPtr>(get_function("glVertexAttribDivisor"))) == nullptr || result;
    result = (glVertexAttribP1ui_ptr = reinterpret_cast<glVertexAttribP1uiPtr>(get_function("glVertexAttribP1ui"))) == nullptr || result;
    result = (glVertexAttribP1uiv_ptr = reinterpret_cast<glVertexAttribP1uivPtr>(get_function("glVertexAttribP1uiv"))) == nullptr || result;
    result = (glVertexAttribP2ui_ptr = reinterpret_cast<glVertexAttribP2uiPtr>(get_function("glVertexAttribP2ui"))) == nullptr || result;
    result = (glVertexAttribP2uiv_ptr = reinterpret_cast<glVertexAttribP2uivPtr>(get_function("glVertexAttribP2uiv"))) == nullptr || result;
    result = (glVertexAttribP3ui_ptr = reinterpret_cast<glVertexAttribP3uiPtr>(get_function("glVertexAttribP3ui"))) == nullptr || result;
    result = (glVertexAttribP3uiv_ptr = reinterpret_cast<glVertexAttribP3uivPtr>(get_function("glVertexAttribP3uiv"))) == nullptr || result;
    result = (glVertexAttribP4ui_ptr = reinterpret_cast<glVertexAttribP4uiPtr>(get_function("glVertexAttribP4ui"))) == nullptr || result;
    result = (glVertexAttribP4uiv_ptr = reinterpret_cast<glVertexAttribP4uivPtr>(get_function("glVertexAttribP4uiv"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_VERSION_4_0

using glMinSampleShadingPtr               = std::add_pointer_t<decltype(glMinSampleShading)>;
using glBlendEquationiPtr                 = std::add_pointer_t<decltype(glBlendEquationi)>;
using glBlendEquationSeparateiPtr         = std::add_pointer_t<decltype(glBlendEquationSeparatei)>;
using glBlendFunciPtr                     = std::add_pointer_t<decltype(glBlendFunci)>;
using glBlendFuncSeparateiPtr             = std::add_pointer_t<decltype(glBlendFuncSeparatei)>;
using glDrawArraysIndirectPtr             = std::add_pointer_t<decltype(glDrawArraysIndirect)>;
using glDrawElementsIndirectPtr           = std::add_pointer_t<decltype(glDrawElementsIndirect)>;
using glUniform1dPtr                      = std::add_pointer_t<decltype(glUniform1d)>;
using glUniform2dPtr                      = std::add_pointer_t<decltype(glUniform2d)>;
using glUniform3dPtr                      = std::add_pointer_t<decltype(glUniform3d)>;
using glUniform4dPtr                      = std::add_pointer_t<decltype(glUniform4d)>;
using glUniform1dvPtr                     = std::add_pointer_t<decltype(glUniform1dv)>;
using glUniform2dvPtr                     = std::add_pointer_t<decltype(glUniform2dv)>;
using glUniform3dvPtr                     = std::add_pointer_t<decltype(glUniform3dv)>;
using glUniform4dvPtr                     = std::add_pointer_t<decltype(glUniform4dv)>;
using glUniformMatrix2dvPtr               = std::add_pointer_t<decltype(glUniformMatrix2dv)>;
using glUniformMatrix3dvPtr               = std::add_pointer_t<decltype(glUniformMatrix3dv)>;
using glUniformMatrix4dvPtr               = std::add_pointer_t<decltype(glUniformMatrix4dv)>;
using glUniformMatrix2x3dvPtr             = std::add_pointer_t<decltype(glUniformMatrix2x3dv)>;
using glUniformMatrix2x4dvPtr             = std::add_pointer_t<decltype(glUniformMatrix2x4dv)>;
using glUniformMatrix3x2dvPtr             = std::add_pointer_t<decltype(glUniformMatrix3x2dv)>;
using glUniformMatrix3x4dvPtr             = std::add_pointer_t<decltype(glUniformMatrix3x4dv)>;
using glUniformMatrix4x2dvPtr             = std::add_pointer_t<decltype(glUniformMatrix4x2dv)>;
using glUniformMatrix4x3dvPtr             = std::add_pointer_t<decltype(glUniformMatrix4x3dv)>;
using glGetUniformdvPtr                   = std::add_pointer_t<decltype(glGetUniformdv)>;
using glGetSubroutineUniformLocationPtr   = std::add_pointer_t<decltype(glGetSubroutineUniformLocation)>;
using glGetSubroutineIndexPtr             = std::add_pointer_t<decltype(glGetSubroutineIndex)>;
using glGetActiveSubroutineUniformivPtr   = std::add_pointer_t<decltype(glGetActiveSubroutineUniformiv)>;
using glGetActiveSubroutineUniformNamePtr = std::add_pointer_t<decltype(glGetActiveSubroutineUniformName)>;
using glGetActiveSubroutineNamePtr        = std::add_pointer_t<decltype(glGetActiveSubroutineName)>;
using glUniformSubroutinesuivPtr          = std::add_pointer_t<decltype(glUniformSubroutinesuiv)>;
using glGetUniformSubroutineuivPtr        = std::add_pointer_t<decltype(glGetUniformSubroutineuiv)>;
using glGetProgramStageivPtr              = std::add_pointer_t<decltype(glGetProgramStageiv)>;
using glPatchParameteriPtr                = std::add_pointer_t<decltype(glPatchParameteri)>;
using glPatchParameterfvPtr               = std::add_pointer_t<decltype(glPatchParameterfv)>;
using glBindTransformFeedbackPtr          = std::add_pointer_t<decltype(glBindTransformFeedback)>;
using glDeleteTransformFeedbacksPtr       = std::add_pointer_t<decltype(glDeleteTransformFeedbacks)>;
using glGenTransformFeedbacksPtr          = std::add_pointer_t<decltype(glGenTransformFeedbacks)>;
using glIsTransformFeedbackPtr            = std::add_pointer_t<decltype(glIsTransformFeedback)>;
using glPauseTransformFeedbackPtr         = std::add_pointer_t<decltype(glPauseTransformFeedback)>;
using glResumeTransformFeedbackPtr        = std::add_pointer_t<decltype(glResumeTransformFeedback)>;
using glDrawTransformFeedbackPtr          = std::add_pointer_t<decltype(glDrawTransformFeedback)>;
using glDrawTransformFeedbackStreamPtr    = std::add_pointer_t<decltype(glDrawTransformFeedbackStream)>;
using glBeginQueryIndexedPtr              = std::add_pointer_t<decltype(glBeginQueryIndexed)>;
using glEndQueryIndexedPtr                = std::add_pointer_t<decltype(glEndQueryIndexed)>;
using glGetQueryIndexedivPtr              = std::add_pointer_t<decltype(glGetQueryIndexediv)>;

glMinSampleShadingPtr glMinSampleShading_ptr                             = nullptr;
glBlendEquationiPtr glBlendEquationi_ptr                                 = nullptr;
glBlendEquationSeparateiPtr glBlendEquationSeparatei_ptr                 = nullptr;
glBlendFunciPtr glBlendFunci_ptr                                         = nullptr;
glBlendFuncSeparateiPtr glBlendFuncSeparatei_ptr                         = nullptr;
glDrawArraysIndirectPtr glDrawArraysIndirect_ptr                         = nullptr;
glDrawElementsIndirectPtr glDrawElementsIndirect_ptr                     = nullptr;
glUniform1dPtr glUniform1d_ptr                                           = nullptr;
glUniform2dPtr glUniform2d_ptr                                           = nullptr;
glUniform3dPtr glUniform3d_ptr                                           = nullptr;
glUniform4dPtr glUniform4d_ptr                                           = nullptr;
glUniform1dvPtr glUniform1dv_ptr                                         = nullptr;
glUniform2dvPtr glUniform2dv_ptr                                         = nullptr;
glUniform3dvPtr glUniform3dv_ptr                                         = nullptr;
glUniform4dvPtr glUniform4dv_ptr                                         = nullptr;
glUniformMatrix2dvPtr glUniformMatrix2dv_ptr                             = nullptr;
glUniformMatrix3dvPtr glUniformMatrix3dv_ptr                             = nullptr;
glUniformMatrix4dvPtr glUniformMatrix4dv_ptr                             = nullptr;
glUniformMatrix2x3dvPtr glUniformMatrix2x3dv_ptr                         = nullptr;
glUniformMatrix2x4dvPtr glUniformMatrix2x4dv_ptr                         = nullptr;
glUniformMatrix3x2dvPtr glUniformMatrix3x2dv_ptr                         = nullptr;
glUniformMatrix3x4dvPtr glUniformMatrix3x4dv_ptr                         = nullptr;
glUniformMatrix4x2dvPtr glUniformMatrix4x2dv_ptr                         = nullptr;
glUniformMatrix4x3dvPtr glUniformMatrix4x3dv_ptr                         = nullptr;
glGetUniformdvPtr glGetUniformdv_ptr                                     = nullptr;
glGetSubroutineUniformLocationPtr glGetSubroutineUniformLocation_ptr     = nullptr;
glGetSubroutineIndexPtr glGetSubroutineIndex_ptr                         = nullptr;
glGetActiveSubroutineUniformivPtr glGetActiveSubroutineUniformiv_ptr     = nullptr;
glGetActiveSubroutineUniformNamePtr glGetActiveSubroutineUniformName_ptr = nullptr;
glGetActiveSubroutineNamePtr glGetActiveSubroutineName_ptr               = nullptr;
glUniformSubroutinesuivPtr glUniformSubroutinesuiv_ptr                   = nullptr;
glGetUniformSubroutineuivPtr glGetUniformSubroutineuiv_ptr               = nullptr;
glGetProgramStageivPtr glGetProgramStageiv_ptr                           = nullptr;
glPatchParameteriPtr glPatchParameteri_ptr                               = nullptr;
glPatchParameterfvPtr glPatchParameterfv_ptr                             = nullptr;
glBindTransformFeedbackPtr glBindTransformFeedback_ptr                   = nullptr;
glDeleteTransformFeedbacksPtr glDeleteTransformFeedbacks_ptr             = nullptr;
glGenTransformFeedbacksPtr glGenTransformFeedbacks_ptr                   = nullptr;
glIsTransformFeedbackPtr glIsTransformFeedback_ptr                       = nullptr;
glPauseTransformFeedbackPtr glPauseTransformFeedback_ptr                 = nullptr;
glResumeTransformFeedbackPtr glResumeTransformFeedback_ptr               = nullptr;
glDrawTransformFeedbackPtr glDrawTransformFeedback_ptr                   = nullptr;
glDrawTransformFeedbackStreamPtr glDrawTransformFeedbackStream_ptr       = nullptr;
glBeginQueryIndexedPtr glBeginQueryIndexed_ptr                           = nullptr;
glEndQueryIndexedPtr glEndQueryIndexed_ptr                               = nullptr;
glGetQueryIndexedivPtr glGetQueryIndexediv_ptr                           = nullptr;

bool init_gl_version_4_0([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glMinSampleShading_ptr = reinterpret_cast<glMinSampleShadingPtr>(get_function("glMinSampleShading"))) == nullptr || result;
    result = (glBlendEquationi_ptr = reinterpret_cast<glBlendEquationiPtr>(get_function("glBlendEquationi"))) == nullptr || result;
    result = (glBlendEquationSeparatei_ptr = reinterpret_cast<glBlendEquationSeparateiPtr>(get_function("glBlendEquationSeparatei"))) == nullptr || result;
    result = (glBlendFunci_ptr = reinterpret_cast<glBlendFunciPtr>(get_function("glBlendFunci"))) == nullptr || result;
    result = (glBlendFuncSeparatei_ptr = reinterpret_cast<glBlendFuncSeparateiPtr>(get_function("glBlendFuncSeparatei"))) == nullptr || result;
    result = (glDrawArraysIndirect_ptr = reinterpret_cast<glDrawArraysIndirectPtr>(get_function("glDrawArraysIndirect"))) == nullptr || result;
    result = (glDrawElementsIndirect_ptr = reinterpret_cast<glDrawElementsIndirectPtr>(get_function("glDrawElementsIndirect"))) == nullptr || result;
    result = (glUniform1d_ptr = reinterpret_cast<glUniform1dPtr>(get_function("glUniform1d"))) == nullptr || result;
    result = (glUniform2d_ptr = reinterpret_cast<glUniform2dPtr>(get_function("glUniform2d"))) == nullptr || result;
    result = (glUniform3d_ptr = reinterpret_cast<glUniform3dPtr>(get_function("glUniform3d"))) == nullptr || result;
    result = (glUniform4d_ptr = reinterpret_cast<glUniform4dPtr>(get_function("glUniform4d"))) == nullptr || result;
    result = (glUniform1dv_ptr = reinterpret_cast<glUniform1dvPtr>(get_function("glUniform1dv"))) == nullptr || result;
    result = (glUniform2dv_ptr = reinterpret_cast<glUniform2dvPtr>(get_function("glUniform2dv"))) == nullptr || result;
    result = (glUniform3dv_ptr = reinterpret_cast<glUniform3dvPtr>(get_function("glUniform3dv"))) == nullptr || result;
    result = (glUniform4dv_ptr = reinterpret_cast<glUniform4dvPtr>(get_function("glUniform4dv"))) == nullptr || result;
    result = (glUniformMatrix2dv_ptr = reinterpret_cast<glUniformMatrix2dvPtr>(get_function("glUniformMatrix2dv"))) == nullptr || result;
    result = (glUniformMatrix3dv_ptr = reinterpret_cast<glUniformMatrix3dvPtr>(get_function("glUniformMatrix3dv"))) == nullptr || result;
    result = (glUniformMatrix4dv_ptr = reinterpret_cast<glUniformMatrix4dvPtr>(get_function("glUniformMatrix4dv"))) == nullptr || result;
    result = (glUniformMatrix2x3dv_ptr = reinterpret_cast<glUniformMatrix2x3dvPtr>(get_function("glUniformMatrix2x3dv"))) == nullptr || result;
    result = (glUniformMatrix2x4dv_ptr = reinterpret_cast<glUniformMatrix2x4dvPtr>(get_function("glUniformMatrix2x4dv"))) == nullptr || result;
    result = (glUniformMatrix3x2dv_ptr = reinterpret_cast<glUniformMatrix3x2dvPtr>(get_function("glUniformMatrix3x2dv"))) == nullptr || result;
    result = (glUniformMatrix3x4dv_ptr = reinterpret_cast<glUniformMatrix3x4dvPtr>(get_function("glUniformMatrix3x4dv"))) == nullptr || result;
    result = (glUniformMatrix4x2dv_ptr = reinterpret_cast<glUniformMatrix4x2dvPtr>(get_function("glUniformMatrix4x2dv"))) == nullptr || result;
    result = (glUniformMatrix4x3dv_ptr = reinterpret_cast<glUniformMatrix4x3dvPtr>(get_function("glUniformMatrix4x3dv"))) == nullptr || result;
    result = (glGetUniformdv_ptr = reinterpret_cast<glGetUniformdvPtr>(get_function("glGetUniformdv"))) == nullptr || result;
    result = (glGetSubroutineUniformLocation_ptr = reinterpret_cast<glGetSubroutineUniformLocationPtr>(get_function("glGetSubroutineUniformLocation"))) == nullptr || result;
    result = (glGetSubroutineIndex_ptr = reinterpret_cast<glGetSubroutineIndexPtr>(get_function("glGetSubroutineIndex"))) == nullptr || result;
    result = (glGetActiveSubroutineUniformiv_ptr = reinterpret_cast<glGetActiveSubroutineUniformivPtr>(get_function("glGetActiveSubroutineUniformiv"))) == nullptr || result;
    result = (glGetActiveSubroutineUniformName_ptr = reinterpret_cast<glGetActiveSubroutineUniformNamePtr>(get_function("glGetActiveSubroutineUniformName"))) == nullptr || result;
    result = (glGetActiveSubroutineName_ptr = reinterpret_cast<glGetActiveSubroutineNamePtr>(get_function("glGetActiveSubroutineName"))) == nullptr || result;
    result = (glUniformSubroutinesuiv_ptr = reinterpret_cast<glUniformSubroutinesuivPtr>(get_function("glUniformSubroutinesuiv"))) == nullptr || result;
    result = (glGetUniformSubroutineuiv_ptr = reinterpret_cast<glGetUniformSubroutineuivPtr>(get_function("glGetUniformSubroutineuiv"))) == nullptr || result;
    result = (glGetProgramStageiv_ptr = reinterpret_cast<glGetProgramStageivPtr>(get_function("glGetProgramStageiv"))) == nullptr || result;
    result = (glPatchParameteri_ptr = reinterpret_cast<glPatchParameteriPtr>(get_function("glPatchParameteri"))) == nullptr || result;
    result = (glPatchParameterfv_ptr = reinterpret_cast<glPatchParameterfvPtr>(get_function("glPatchParameterfv"))) == nullptr || result;
    result = (glBindTransformFeedback_ptr = reinterpret_cast<glBindTransformFeedbackPtr>(get_function("glBindTransformFeedback"))) == nullptr || result;
    result = (glDeleteTransformFeedbacks_ptr = reinterpret_cast<glDeleteTransformFeedbacksPtr>(get_function("glDeleteTransformFeedbacks"))) == nullptr || result;
    result = (glGenTransformFeedbacks_ptr = reinterpret_cast<glGenTransformFeedbacksPtr>(get_function("glGenTransformFeedbacks"))) == nullptr || result;
    result = (glIsTransformFeedback_ptr = reinterpret_cast<glIsTransformFeedbackPtr>(get_function("glIsTransformFeedback"))) == nullptr || result;
    result = (glPauseTransformFeedback_ptr = reinterpret_cast<glPauseTransformFeedbackPtr>(get_function("glPauseTransformFeedback"))) == nullptr || result;
    result = (glResumeTransformFeedback_ptr = reinterpret_cast<glResumeTransformFeedbackPtr>(get_function("glResumeTransformFeedback"))) == nullptr || result;
    result = (glDrawTransformFeedback_ptr = reinterpret_cast<glDrawTransformFeedbackPtr>(get_function("glDrawTransformFeedback"))) == nullptr || result;
    result = (glDrawTransformFeedbackStream_ptr = reinterpret_cast<glDrawTransformFeedbackStreamPtr>(get_function("glDrawTransformFeedbackStream"))) == nullptr || result;
    result = (glBeginQueryIndexed_ptr = reinterpret_cast<glBeginQueryIndexedPtr>(get_function("glBeginQueryIndexed"))) == nullptr || result;
    result = (glEndQueryIndexed_ptr = reinterpret_cast<glEndQueryIndexedPtr>(get_function("glEndQueryIndexed"))) == nullptr || result;
    result = (glGetQueryIndexediv_ptr = reinterpret_cast<glGetQueryIndexedivPtr>(get_function("glGetQueryIndexediv"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_VERSION_4_1

using glReleaseShaderCompilerPtr     = std::add_pointer_t<decltype(glReleaseShaderCompiler)>;
using glShaderBinaryPtr              = std::add_pointer_t<decltype(glShaderBinary)>;
using glGetShaderPrecisionFormatPtr  = std::add_pointer_t<decltype(glGetShaderPrecisionFormat)>;
using glDepthRangefPtr               = std::add_pointer_t<decltype(glDepthRangef)>;
using glClearDepthfPtr               = std::add_pointer_t<decltype(glClearDepthf)>;
using glGetProgramBinaryPtr          = std::add_pointer_t<decltype(glGetProgramBinary)>;
using glProgramBinaryPtr             = std::add_pointer_t<decltype(glProgramBinary)>;
using glProgramParameteriPtr         = std::add_pointer_t<decltype(glProgramParameteri)>;
using glUseProgramStagesPtr          = std::add_pointer_t<decltype(glUseProgramStages)>;
using glActiveShaderProgramPtr       = std::add_pointer_t<decltype(glActiveShaderProgram)>;
using glCreateShaderProgramvPtr      = std::add_pointer_t<decltype(glCreateShaderProgramv)>;
using glBindProgramPipelinePtr       = std::add_pointer_t<decltype(glBindProgramPipeline)>;
using glDeleteProgramPipelinesPtr    = std::add_pointer_t<decltype(glDeleteProgramPipelines)>;
using glGenProgramPipelinesPtr       = std::add_pointer_t<decltype(glGenProgramPipelines)>;
using glIsProgramPipelinePtr         = std::add_pointer_t<decltype(glIsProgramPipeline)>;
using glGetProgramPipelineivPtr      = std::add_pointer_t<decltype(glGetProgramPipelineiv)>;
using glProgramUniform1iPtr          = std::add_pointer_t<decltype(glProgramUniform1i)>;
using glProgramUniform1ivPtr         = std::add_pointer_t<decltype(glProgramUniform1iv)>;
using glProgramUniform1fPtr          = std::add_pointer_t<decltype(glProgramUniform1f)>;
using glProgramUniform1fvPtr         = std::add_pointer_t<decltype(glProgramUniform1fv)>;
using glProgramUniform1dPtr          = std::add_pointer_t<decltype(glProgramUniform1d)>;
using glProgramUniform1dvPtr         = std::add_pointer_t<decltype(glProgramUniform1dv)>;
using glProgramUniform1uiPtr         = std::add_pointer_t<decltype(glProgramUniform1ui)>;
using glProgramUniform1uivPtr        = std::add_pointer_t<decltype(glProgramUniform1uiv)>;
using glProgramUniform2iPtr          = std::add_pointer_t<decltype(glProgramUniform2i)>;
using glProgramUniform2ivPtr         = std::add_pointer_t<decltype(glProgramUniform2iv)>;
using glProgramUniform2fPtr          = std::add_pointer_t<decltype(glProgramUniform2f)>;
using glProgramUniform2fvPtr         = std::add_pointer_t<decltype(glProgramUniform2fv)>;
using glProgramUniform2dPtr          = std::add_pointer_t<decltype(glProgramUniform2d)>;
using glProgramUniform2dvPtr         = std::add_pointer_t<decltype(glProgramUniform2dv)>;
using glProgramUniform2uiPtr         = std::add_pointer_t<decltype(glProgramUniform2ui)>;
using glProgramUniform2uivPtr        = std::add_pointer_t<decltype(glProgramUniform2uiv)>;
using glProgramUniform3iPtr          = std::add_pointer_t<decltype(glProgramUniform3i)>;
using glProgramUniform3ivPtr         = std::add_pointer_t<decltype(glProgramUniform3iv)>;
using glProgramUniform3fPtr          = std::add_pointer_t<decltype(glProgramUniform3f)>;
using glProgramUniform3fvPtr         = std::add_pointer_t<decltype(glProgramUniform3fv)>;
using glProgramUniform3dPtr          = std::add_pointer_t<decltype(glProgramUniform3d)>;
using glProgramUniform3dvPtr         = std::add_pointer_t<decltype(glProgramUniform3dv)>;
using glProgramUniform3uiPtr         = std::add_pointer_t<decltype(glProgramUniform3ui)>;
using glProgramUniform3uivPtr        = std::add_pointer_t<decltype(glProgramUniform3uiv)>;
using glProgramUniform4iPtr          = std::add_pointer_t<decltype(glProgramUniform4i)>;
using glProgramUniform4ivPtr         = std::add_pointer_t<decltype(glProgramUniform4iv)>;
using glProgramUniform4fPtr          = std::add_pointer_t<decltype(glProgramUniform4f)>;
using glProgramUniform4fvPtr         = std::add_pointer_t<decltype(glProgramUniform4fv)>;
using glProgramUniform4dPtr          = std::add_pointer_t<decltype(glProgramUniform4d)>;
using glProgramUniform4dvPtr         = std::add_pointer_t<decltype(glProgramUniform4dv)>;
using glProgramUniform4uiPtr         = std::add_pointer_t<decltype(glProgramUniform4ui)>;
using glProgramUniform4uivPtr        = std::add_pointer_t<decltype(glProgramUniform4uiv)>;
using glProgramUniformMatrix2fvPtr   = std::add_pointer_t<decltype(glProgramUniformMatrix2fv)>;
using glProgramUniformMatrix3fvPtr   = std::add_pointer_t<decltype(glProgramUniformMatrix3fv)>;
using glProgramUniformMatrix4fvPtr   = std::add_pointer_t<decltype(glProgramUniformMatrix4fv)>;
using glProgramUniformMatrix2dvPtr   = std::add_pointer_t<decltype(glProgramUniformMatrix2dv)>;
using glProgramUniformMatrix3dvPtr   = std::add_pointer_t<decltype(glProgramUniformMatrix3dv)>;
using glProgramUniformMatrix4dvPtr   = std::add_pointer_t<decltype(glProgramUniformMatrix4dv)>;
using glProgramUniformMatrix2x3fvPtr = std::add_pointer_t<decltype(glProgramUniformMatrix2x3fv)>;
using glProgramUniformMatrix3x2fvPtr = std::add_pointer_t<decltype(glProgramUniformMatrix3x2fv)>;
using glProgramUniformMatrix2x4fvPtr = std::add_pointer_t<decltype(glProgramUniformMatrix2x4fv)>;
using glProgramUniformMatrix4x2fvPtr = std::add_pointer_t<decltype(glProgramUniformMatrix4x2fv)>;
using glProgramUniformMatrix3x4fvPtr = std::add_pointer_t<decltype(glProgramUniformMatrix3x4fv)>;
using glProgramUniformMatrix4x3fvPtr = std::add_pointer_t<decltype(glProgramUniformMatrix4x3fv)>;
using glProgramUniformMatrix2x3dvPtr = std::add_pointer_t<decltype(glProgramUniformMatrix2x3dv)>;
using glProgramUniformMatrix3x2dvPtr = std::add_pointer_t<decltype(glProgramUniformMatrix3x2dv)>;
using glProgramUniformMatrix2x4dvPtr = std::add_pointer_t<decltype(glProgramUniformMatrix2x4dv)>;
using glProgramUniformMatrix4x2dvPtr = std::add_pointer_t<decltype(glProgramUniformMatrix4x2dv)>;
using glProgramUniformMatrix3x4dvPtr = std::add_pointer_t<decltype(glProgramUniformMatrix3x4dv)>;
using glProgramUniformMatrix4x3dvPtr = std::add_pointer_t<decltype(glProgramUniformMatrix4x3dv)>;
using glValidateProgramPipelinePtr   = std::add_pointer_t<decltype(glValidateProgramPipeline)>;
using glGetProgramPipelineInfoLogPtr = std::add_pointer_t<decltype(glGetProgramPipelineInfoLog)>;
using glVertexAttribL1dPtr           = std::add_pointer_t<decltype(glVertexAttribL1d)>;
using glVertexAttribL2dPtr           = std::add_pointer_t<decltype(glVertexAttribL2d)>;
using glVertexAttribL3dPtr           = std::add_pointer_t<decltype(glVertexAttribL3d)>;
using glVertexAttribL4dPtr           = std::add_pointer_t<decltype(glVertexAttribL4d)>;
using glVertexAttribL1dvPtr          = std::add_pointer_t<decltype(glVertexAttribL1dv)>;
using glVertexAttribL2dvPtr          = std::add_pointer_t<decltype(glVertexAttribL2dv)>;
using glVertexAttribL3dvPtr          = std::add_pointer_t<decltype(glVertexAttribL3dv)>;
using glVertexAttribL4dvPtr          = std::add_pointer_t<decltype(glVertexAttribL4dv)>;
using glVertexAttribLPointerPtr      = std::add_pointer_t<decltype(glVertexAttribLPointer)>;
using glGetVertexAttribLdvPtr        = std::add_pointer_t<decltype(glGetVertexAttribLdv)>;
using glViewportArrayvPtr            = std::add_pointer_t<decltype(glViewportArrayv)>;
using glViewportIndexedfPtr          = std::add_pointer_t<decltype(glViewportIndexedf)>;
using glViewportIndexedfvPtr         = std::add_pointer_t<decltype(glViewportIndexedfv)>;
using glScissorArrayvPtr             = std::add_pointer_t<decltype(glScissorArrayv)>;
using glScissorIndexedPtr            = std::add_pointer_t<decltype(glScissorIndexed)>;
using glScissorIndexedvPtr           = std::add_pointer_t<decltype(glScissorIndexedv)>;
using glDepthRangeArrayvPtr          = std::add_pointer_t<decltype(glDepthRangeArrayv)>;
using glDepthRangeIndexedPtr         = std::add_pointer_t<decltype(glDepthRangeIndexed)>;
using glGetFloati_vPtr               = std::add_pointer_t<decltype(glGetFloati_v)>;
using glGetDoublei_vPtr              = std::add_pointer_t<decltype(glGetDoublei_v)>;

glReleaseShaderCompilerPtr glReleaseShaderCompiler_ptr         = nullptr;
glShaderBinaryPtr glShaderBinary_ptr                           = nullptr;
glGetShaderPrecisionFormatPtr glGetShaderPrecisionFormat_ptr   = nullptr;
glDepthRangefPtr glDepthRangef_ptr                             = nullptr;
glClearDepthfPtr glClearDepthf_ptr                             = nullptr;
glGetProgramBinaryPtr glGetProgramBinary_ptr                   = nullptr;
glProgramBinaryPtr glProgramBinary_ptr                         = nullptr;
glProgramParameteriPtr glProgramParameteri_ptr                 = nullptr;
glUseProgramStagesPtr glUseProgramStages_ptr                   = nullptr;
glActiveShaderProgramPtr glActiveShaderProgram_ptr             = nullptr;
glCreateShaderProgramvPtr glCreateShaderProgramv_ptr           = nullptr;
glBindProgramPipelinePtr glBindProgramPipeline_ptr             = nullptr;
glDeleteProgramPipelinesPtr glDeleteProgramPipelines_ptr       = nullptr;
glGenProgramPipelinesPtr glGenProgramPipelines_ptr             = nullptr;
glIsProgramPipelinePtr glIsProgramPipeline_ptr                 = nullptr;
glGetProgramPipelineivPtr glGetProgramPipelineiv_ptr           = nullptr;
glProgramUniform1iPtr glProgramUniform1i_ptr                   = nullptr;
glProgramUniform1ivPtr glProgramUniform1iv_ptr                 = nullptr;
glProgramUniform1fPtr glProgramUniform1f_ptr                   = nullptr;
glProgramUniform1fvPtr glProgramUniform1fv_ptr                 = nullptr;
glProgramUniform1dPtr glProgramUniform1d_ptr                   = nullptr;
glProgramUniform1dvPtr glProgramUniform1dv_ptr                 = nullptr;
glProgramUniform1uiPtr glProgramUniform1ui_ptr                 = nullptr;
glProgramUniform1uivPtr glProgramUniform1uiv_ptr               = nullptr;
glProgramUniform2iPtr glProgramUniform2i_ptr                   = nullptr;
glProgramUniform2ivPtr glProgramUniform2iv_ptr                 = nullptr;
glProgramUniform2fPtr glProgramUniform2f_ptr                   = nullptr;
glProgramUniform2fvPtr glProgramUniform2fv_ptr                 = nullptr;
glProgramUniform2dPtr glProgramUniform2d_ptr                   = nullptr;
glProgramUniform2dvPtr glProgramUniform2dv_ptr                 = nullptr;
glProgramUniform2uiPtr glProgramUniform2ui_ptr                 = nullptr;
glProgramUniform2uivPtr glProgramUniform2uiv_ptr               = nullptr;
glProgramUniform3iPtr glProgramUniform3i_ptr                   = nullptr;
glProgramUniform3ivPtr glProgramUniform3iv_ptr                 = nullptr;
glProgramUniform3fPtr glProgramUniform3f_ptr                   = nullptr;
glProgramUniform3fvPtr glProgramUniform3fv_ptr                 = nullptr;
glProgramUniform3dPtr glProgramUniform3d_ptr                   = nullptr;
glProgramUniform3dvPtr glProgramUniform3dv_ptr                 = nullptr;
glProgramUniform3uiPtr glProgramUniform3ui_ptr                 = nullptr;
glProgramUniform3uivPtr glProgramUniform3uiv_ptr               = nullptr;
glProgramUniform4iPtr glProgramUniform4i_ptr                   = nullptr;
glProgramUniform4ivPtr glProgramUniform4iv_ptr                 = nullptr;
glProgramUniform4fPtr glProgramUniform4f_ptr                   = nullptr;
glProgramUniform4fvPtr glProgramUniform4fv_ptr                 = nullptr;
glProgramUniform4dPtr glProgramUniform4d_ptr                   = nullptr;
glProgramUniform4dvPtr glProgramUniform4dv_ptr                 = nullptr;
glProgramUniform4uiPtr glProgramUniform4ui_ptr                 = nullptr;
glProgramUniform4uivPtr glProgramUniform4uiv_ptr               = nullptr;
glProgramUniformMatrix2fvPtr glProgramUniformMatrix2fv_ptr     = nullptr;
glProgramUniformMatrix3fvPtr glProgramUniformMatrix3fv_ptr     = nullptr;
glProgramUniformMatrix4fvPtr glProgramUniformMatrix4fv_ptr     = nullptr;
glProgramUniformMatrix2dvPtr glProgramUniformMatrix2dv_ptr     = nullptr;
glProgramUniformMatrix3dvPtr glProgramUniformMatrix3dv_ptr     = nullptr;
glProgramUniformMatrix4dvPtr glProgramUniformMatrix4dv_ptr     = nullptr;
glProgramUniformMatrix2x3fvPtr glProgramUniformMatrix2x3fv_ptr = nullptr;
glProgramUniformMatrix3x2fvPtr glProgramUniformMatrix3x2fv_ptr = nullptr;
glProgramUniformMatrix2x4fvPtr glProgramUniformMatrix2x4fv_ptr = nullptr;
glProgramUniformMatrix4x2fvPtr glProgramUniformMatrix4x2fv_ptr = nullptr;
glProgramUniformMatrix3x4fvPtr glProgramUniformMatrix3x4fv_ptr = nullptr;
glProgramUniformMatrix4x3fvPtr glProgramUniformMatrix4x3fv_ptr = nullptr;
glProgramUniformMatrix2x3dvPtr glProgramUniformMatrix2x3dv_ptr = nullptr;
glProgramUniformMatrix3x2dvPtr glProgramUniformMatrix3x2dv_ptr = nullptr;
glProgramUniformMatrix2x4dvPtr glProgramUniformMatrix2x4dv_ptr = nullptr;
glProgramUniformMatrix4x2dvPtr glProgramUniformMatrix4x2dv_ptr = nullptr;
glProgramUniformMatrix3x4dvPtr glProgramUniformMatrix3x4dv_ptr = nullptr;
glProgramUniformMatrix4x3dvPtr glProgramUniformMatrix4x3dv_ptr = nullptr;
glValidateProgramPipelinePtr glValidateProgramPipeline_ptr     = nullptr;
glGetProgramPipelineInfoLogPtr glGetProgramPipelineInfoLog_ptr = nullptr;
glVertexAttribL1dPtr glVertexAttribL1d_ptr                     = nullptr;
glVertexAttribL2dPtr glVertexAttribL2d_ptr                     = nullptr;
glVertexAttribL3dPtr glVertexAttribL3d_ptr                     = nullptr;
glVertexAttribL4dPtr glVertexAttribL4d_ptr                     = nullptr;
glVertexAttribL1dvPtr glVertexAttribL1dv_ptr                   = nullptr;
glVertexAttribL2dvPtr glVertexAttribL2dv_ptr                   = nullptr;
glVertexAttribL3dvPtr glVertexAttribL3dv_ptr                   = nullptr;
glVertexAttribL4dvPtr glVertexAttribL4dv_ptr                   = nullptr;
glVertexAttribLPointerPtr glVertexAttribLPointer_ptr           = nullptr;
glGetVertexAttribLdvPtr glGetVertexAttribLdv_ptr               = nullptr;
glViewportArrayvPtr glViewportArrayv_ptr                       = nullptr;
glViewportIndexedfPtr glViewportIndexedf_ptr                   = nullptr;
glViewportIndexedfvPtr glViewportIndexedfv_ptr                 = nullptr;
glScissorArrayvPtr glScissorArrayv_ptr                         = nullptr;
glScissorIndexedPtr glScissorIndexed_ptr                       = nullptr;
glScissorIndexedvPtr glScissorIndexedv_ptr                     = nullptr;
glDepthRangeArrayvPtr glDepthRangeArrayv_ptr                   = nullptr;
glDepthRangeIndexedPtr glDepthRangeIndexed_ptr                 = nullptr;
glGetFloati_vPtr glGetFloati_v_ptr                             = nullptr;
glGetDoublei_vPtr glGetDoublei_v_ptr                           = nullptr;

bool init_gl_version_4_1([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glReleaseShaderCompiler_ptr = reinterpret_cast<glReleaseShaderCompilerPtr>(get_function("glReleaseShaderCompiler"))) == nullptr || result;
    result = (glShaderBinary_ptr = reinterpret_cast<glShaderBinaryPtr>(get_function("glShaderBinary"))) == nullptr || result;
    result = (glGetShaderPrecisionFormat_ptr = reinterpret_cast<glGetShaderPrecisionFormatPtr>(get_function("glGetShaderPrecisionFormat"))) == nullptr || result;
    result = (glDepthRangef_ptr = reinterpret_cast<glDepthRangefPtr>(get_function("glDepthRangef"))) == nullptr || result;
    result = (glClearDepthf_ptr = reinterpret_cast<glClearDepthfPtr>(get_function("glClearDepthf"))) == nullptr || result;
    result = (glGetProgramBinary_ptr = reinterpret_cast<glGetProgramBinaryPtr>(get_function("glGetProgramBinary"))) == nullptr || result;
    result = (glProgramBinary_ptr = reinterpret_cast<glProgramBinaryPtr>(get_function("glProgramBinary"))) == nullptr || result;
    result = (glProgramParameteri_ptr = reinterpret_cast<glProgramParameteriPtr>(get_function("glProgramParameteri"))) == nullptr || result;
    result = (glUseProgramStages_ptr = reinterpret_cast<glUseProgramStagesPtr>(get_function("glUseProgramStages"))) == nullptr || result;
    result = (glActiveShaderProgram_ptr = reinterpret_cast<glActiveShaderProgramPtr>(get_function("glActiveShaderProgram"))) == nullptr || result;
    result = (glCreateShaderProgramv_ptr = reinterpret_cast<glCreateShaderProgramvPtr>(get_function("glCreateShaderProgramv"))) == nullptr || result;
    result = (glBindProgramPipeline_ptr = reinterpret_cast<glBindProgramPipelinePtr>(get_function("glBindProgramPipeline"))) == nullptr || result;
    result = (glDeleteProgramPipelines_ptr = reinterpret_cast<glDeleteProgramPipelinesPtr>(get_function("glDeleteProgramPipelines"))) == nullptr || result;
    result = (glGenProgramPipelines_ptr = reinterpret_cast<glGenProgramPipelinesPtr>(get_function("glGenProgramPipelines"))) == nullptr || result;
    result = (glIsProgramPipeline_ptr = reinterpret_cast<glIsProgramPipelinePtr>(get_function("glIsProgramPipeline"))) == nullptr || result;
    result = (glGetProgramPipelineiv_ptr = reinterpret_cast<glGetProgramPipelineivPtr>(get_function("glGetProgramPipelineiv"))) == nullptr || result;
    result = (glProgramUniform1i_ptr = reinterpret_cast<glProgramUniform1iPtr>(get_function("glProgramUniform1i"))) == nullptr || result;
    result = (glProgramUniform1iv_ptr = reinterpret_cast<glProgramUniform1ivPtr>(get_function("glProgramUniform1iv"))) == nullptr || result;
    result = (glProgramUniform1f_ptr = reinterpret_cast<glProgramUniform1fPtr>(get_function("glProgramUniform1f"))) == nullptr || result;
    result = (glProgramUniform1fv_ptr = reinterpret_cast<glProgramUniform1fvPtr>(get_function("glProgramUniform1fv"))) == nullptr || result;
    result = (glProgramUniform1d_ptr = reinterpret_cast<glProgramUniform1dPtr>(get_function("glProgramUniform1d"))) == nullptr || result;
    result = (glProgramUniform1dv_ptr = reinterpret_cast<glProgramUniform1dvPtr>(get_function("glProgramUniform1dv"))) == nullptr || result;
    result = (glProgramUniform1ui_ptr = reinterpret_cast<glProgramUniform1uiPtr>(get_function("glProgramUniform1ui"))) == nullptr || result;
    result = (glProgramUniform1uiv_ptr = reinterpret_cast<glProgramUniform1uivPtr>(get_function("glProgramUniform1uiv"))) == nullptr || result;
    result = (glProgramUniform2i_ptr = reinterpret_cast<glProgramUniform2iPtr>(get_function("glProgramUniform2i"))) == nullptr || result;
    result = (glProgramUniform2iv_ptr = reinterpret_cast<glProgramUniform2ivPtr>(get_function("glProgramUniform2iv"))) == nullptr || result;
    result = (glProgramUniform2f_ptr = reinterpret_cast<glProgramUniform2fPtr>(get_function("glProgramUniform2f"))) == nullptr || result;
    result = (glProgramUniform2fv_ptr = reinterpret_cast<glProgramUniform2fvPtr>(get_function("glProgramUniform2fv"))) == nullptr || result;
    result = (glProgramUniform2d_ptr = reinterpret_cast<glProgramUniform2dPtr>(get_function("glProgramUniform2d"))) == nullptr || result;
    result = (glProgramUniform2dv_ptr = reinterpret_cast<glProgramUniform2dvPtr>(get_function("glProgramUniform2dv"))) == nullptr || result;
    result = (glProgramUniform2ui_ptr = reinterpret_cast<glProgramUniform2uiPtr>(get_function("glProgramUniform2ui"))) == nullptr || result;
    result = (glProgramUniform2uiv_ptr = reinterpret_cast<glProgramUniform2uivPtr>(get_function("glProgramUniform2uiv"))) == nullptr || result;
    result = (glProgramUniform3i_ptr = reinterpret_cast<glProgramUniform3iPtr>(get_function("glProgramUniform3i"))) == nullptr || result;
    result = (glProgramUniform3iv_ptr = reinterpret_cast<glProgramUniform3ivPtr>(get_function("glProgramUniform3iv"))) == nullptr || result;
    result = (glProgramUniform3f_ptr = reinterpret_cast<glProgramUniform3fPtr>(get_function("glProgramUniform3f"))) == nullptr || result;
    result = (glProgramUniform3fv_ptr = reinterpret_cast<glProgramUniform3fvPtr>(get_function("glProgramUniform3fv"))) == nullptr || result;
    result = (glProgramUniform3d_ptr = reinterpret_cast<glProgramUniform3dPtr>(get_function("glProgramUniform3d"))) == nullptr || result;
    result = (glProgramUniform3dv_ptr = reinterpret_cast<glProgramUniform3dvPtr>(get_function("glProgramUniform3dv"))) == nullptr || result;
    result = (glProgramUniform3ui_ptr = reinterpret_cast<glProgramUniform3uiPtr>(get_function("glProgramUniform3ui"))) == nullptr || result;
    result = (glProgramUniform3uiv_ptr = reinterpret_cast<glProgramUniform3uivPtr>(get_function("glProgramUniform3uiv"))) == nullptr || result;
    result = (glProgramUniform4i_ptr = reinterpret_cast<glProgramUniform4iPtr>(get_function("glProgramUniform4i"))) == nullptr || result;
    result = (glProgramUniform4iv_ptr = reinterpret_cast<glProgramUniform4ivPtr>(get_function("glProgramUniform4iv"))) == nullptr || result;
    result = (glProgramUniform4f_ptr = reinterpret_cast<glProgramUniform4fPtr>(get_function("glProgramUniform4f"))) == nullptr || result;
    result = (glProgramUniform4fv_ptr = reinterpret_cast<glProgramUniform4fvPtr>(get_function("glProgramUniform4fv"))) == nullptr || result;
    result = (glProgramUniform4d_ptr = reinterpret_cast<glProgramUniform4dPtr>(get_function("glProgramUniform4d"))) == nullptr || result;
    result = (glProgramUniform4dv_ptr = reinterpret_cast<glProgramUniform4dvPtr>(get_function("glProgramUniform4dv"))) == nullptr || result;
    result = (glProgramUniform4ui_ptr = reinterpret_cast<glProgramUniform4uiPtr>(get_function("glProgramUniform4ui"))) == nullptr || result;
    result = (glProgramUniform4uiv_ptr = reinterpret_cast<glProgramUniform4uivPtr>(get_function("glProgramUniform4uiv"))) == nullptr || result;
    result = (glProgramUniformMatrix2fv_ptr = reinterpret_cast<glProgramUniformMatrix2fvPtr>(get_function("glProgramUniformMatrix2fv"))) == nullptr || result;
    result = (glProgramUniformMatrix3fv_ptr = reinterpret_cast<glProgramUniformMatrix3fvPtr>(get_function("glProgramUniformMatrix3fv"))) == nullptr || result;
    result = (glProgramUniformMatrix4fv_ptr = reinterpret_cast<glProgramUniformMatrix4fvPtr>(get_function("glProgramUniformMatrix4fv"))) == nullptr || result;
    result = (glProgramUniformMatrix2dv_ptr = reinterpret_cast<glProgramUniformMatrix2dvPtr>(get_function("glProgramUniformMatrix2dv"))) == nullptr || result;
    result = (glProgramUniformMatrix3dv_ptr = reinterpret_cast<glProgramUniformMatrix3dvPtr>(get_function("glProgramUniformMatrix3dv"))) == nullptr || result;
    result = (glProgramUniformMatrix4dv_ptr = reinterpret_cast<glProgramUniformMatrix4dvPtr>(get_function("glProgramUniformMatrix4dv"))) == nullptr || result;
    result = (glProgramUniformMatrix2x3fv_ptr = reinterpret_cast<glProgramUniformMatrix2x3fvPtr>(get_function("glProgramUniformMatrix2x3fv"))) == nullptr || result;
    result = (glProgramUniformMatrix3x2fv_ptr = reinterpret_cast<glProgramUniformMatrix3x2fvPtr>(get_function("glProgramUniformMatrix3x2fv"))) == nullptr || result;
    result = (glProgramUniformMatrix2x4fv_ptr = reinterpret_cast<glProgramUniformMatrix2x4fvPtr>(get_function("glProgramUniformMatrix2x4fv"))) == nullptr || result;
    result = (glProgramUniformMatrix4x2fv_ptr = reinterpret_cast<glProgramUniformMatrix4x2fvPtr>(get_function("glProgramUniformMatrix4x2fv"))) == nullptr || result;
    result = (glProgramUniformMatrix3x4fv_ptr = reinterpret_cast<glProgramUniformMatrix3x4fvPtr>(get_function("glProgramUniformMatrix3x4fv"))) == nullptr || result;
    result = (glProgramUniformMatrix4x3fv_ptr = reinterpret_cast<glProgramUniformMatrix4x3fvPtr>(get_function("glProgramUniformMatrix4x3fv"))) == nullptr || result;
    result = (glProgramUniformMatrix2x3dv_ptr = reinterpret_cast<glProgramUniformMatrix2x3dvPtr>(get_function("glProgramUniformMatrix2x3dv"))) == nullptr || result;
    result = (glProgramUniformMatrix3x2dv_ptr = reinterpret_cast<glProgramUniformMatrix3x2dvPtr>(get_function("glProgramUniformMatrix3x2dv"))) == nullptr || result;
    result = (glProgramUniformMatrix2x4dv_ptr = reinterpret_cast<glProgramUniformMatrix2x4dvPtr>(get_function("glProgramUniformMatrix2x4dv"))) == nullptr || result;
    result = (glProgramUniformMatrix4x2dv_ptr = reinterpret_cast<glProgramUniformMatrix4x2dvPtr>(get_function("glProgramUniformMatrix4x2dv"))) == nullptr || result;
    result = (glProgramUniformMatrix3x4dv_ptr = reinterpret_cast<glProgramUniformMatrix3x4dvPtr>(get_function("glProgramUniformMatrix3x4dv"))) == nullptr || result;
    result = (glProgramUniformMatrix4x3dv_ptr = reinterpret_cast<glProgramUniformMatrix4x3dvPtr>(get_function("glProgramUniformMatrix4x3dv"))) == nullptr || result;
    result = (glValidateProgramPipeline_ptr = reinterpret_cast<glValidateProgramPipelinePtr>(get_function("glValidateProgramPipeline"))) == nullptr || result;
    result = (glGetProgramPipelineInfoLog_ptr = reinterpret_cast<glGetProgramPipelineInfoLogPtr>(get_function("glGetProgramPipelineInfoLog"))) == nullptr || result;
    result = (glVertexAttribL1d_ptr = reinterpret_cast<glVertexAttribL1dPtr>(get_function("glVertexAttribL1d"))) == nullptr || result;
    result = (glVertexAttribL2d_ptr = reinterpret_cast<glVertexAttribL2dPtr>(get_function("glVertexAttribL2d"))) == nullptr || result;
    result = (glVertexAttribL3d_ptr = reinterpret_cast<glVertexAttribL3dPtr>(get_function("glVertexAttribL3d"))) == nullptr || result;
    result = (glVertexAttribL4d_ptr = reinterpret_cast<glVertexAttribL4dPtr>(get_function("glVertexAttribL4d"))) == nullptr || result;
    result = (glVertexAttribL1dv_ptr = reinterpret_cast<glVertexAttribL1dvPtr>(get_function("glVertexAttribL1dv"))) == nullptr || result;
    result = (glVertexAttribL2dv_ptr = reinterpret_cast<glVertexAttribL2dvPtr>(get_function("glVertexAttribL2dv"))) == nullptr || result;
    result = (glVertexAttribL3dv_ptr = reinterpret_cast<glVertexAttribL3dvPtr>(get_function("glVertexAttribL3dv"))) == nullptr || result;
    result = (glVertexAttribL4dv_ptr = reinterpret_cast<glVertexAttribL4dvPtr>(get_function("glVertexAttribL4dv"))) == nullptr || result;
    result = (glVertexAttribLPointer_ptr = reinterpret_cast<glVertexAttribLPointerPtr>(get_function("glVertexAttribLPointer"))) == nullptr || result;
    result = (glGetVertexAttribLdv_ptr = reinterpret_cast<glGetVertexAttribLdvPtr>(get_function("glGetVertexAttribLdv"))) == nullptr || result;
    result = (glViewportArrayv_ptr = reinterpret_cast<glViewportArrayvPtr>(get_function("glViewportArrayv"))) == nullptr || result;
    result = (glViewportIndexedf_ptr = reinterpret_cast<glViewportIndexedfPtr>(get_function("glViewportIndexedf"))) == nullptr || result;
    result = (glViewportIndexedfv_ptr = reinterpret_cast<glViewportIndexedfvPtr>(get_function("glViewportIndexedfv"))) == nullptr || result;
    result = (glScissorArrayv_ptr = reinterpret_cast<glScissorArrayvPtr>(get_function("glScissorArrayv"))) == nullptr || result;
    result = (glScissorIndexed_ptr = reinterpret_cast<glScissorIndexedPtr>(get_function("glScissorIndexed"))) == nullptr || result;
    result = (glScissorIndexedv_ptr = reinterpret_cast<glScissorIndexedvPtr>(get_function("glScissorIndexedv"))) == nullptr || result;
    result = (glDepthRangeArrayv_ptr = reinterpret_cast<glDepthRangeArrayvPtr>(get_function("glDepthRangeArrayv"))) == nullptr || result;
    result = (glDepthRangeIndexed_ptr = reinterpret_cast<glDepthRangeIndexedPtr>(get_function("glDepthRangeIndexed"))) == nullptr || result;
    result = (glGetFloati_v_ptr = reinterpret_cast<glGetFloati_vPtr>(get_function("glGetFloati_v"))) == nullptr || result;
    result = (glGetDoublei_v_ptr = reinterpret_cast<glGetDoublei_vPtr>(get_function("glGetDoublei_v"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_VERSION_4_2

using glDrawArraysInstancedBaseInstancePtr   = std::add_pointer_t<decltype(glDrawArraysInstancedBaseInstance)>;
using glDrawElementsInstancedBaseInstancePtr = std::add_pointer_t<decltype(glDrawElementsInstancedBaseInstance)>;
using glDrawElementsInstancedBaseVertexBaseInstancePtr = std::add_pointer_t<
decltype(glDrawElementsInstancedBaseVertexBaseInstance)>;
using glGetInternalformativPtr                  = std::add_pointer_t<decltype(glGetInternalformativ)>;
using glGetActiveAtomicCounterBufferivPtr       = std::add_pointer_t<decltype(glGetActiveAtomicCounterBufferiv)>;
using glBindImageTexturePtr                     = std::add_pointer_t<decltype(glBindImageTexture)>;
using glMemoryBarrierPtr                        = std::add_pointer_t<decltype(glMemoryBarrier)>;
using glTexStorage1DPtr                         = std::add_pointer_t<decltype(glTexStorage1D)>;
using glTexStorage2DPtr                         = std::add_pointer_t<decltype(glTexStorage2D)>;
using glTexStorage3DPtr                         = std::add_pointer_t<decltype(glTexStorage3D)>;
using glDrawTransformFeedbackInstancedPtr       = std::add_pointer_t<decltype(glDrawTransformFeedbackInstanced)>;
using glDrawTransformFeedbackStreamInstancedPtr = std::add_pointer_t<decltype(glDrawTransformFeedbackStreamInstanced)>;

glDrawArraysInstancedBaseInstancePtr glDrawArraysInstancedBaseInstance_ptr                         = nullptr;
glDrawElementsInstancedBaseInstancePtr glDrawElementsInstancedBaseInstance_ptr                     = nullptr;
glDrawElementsInstancedBaseVertexBaseInstancePtr glDrawElementsInstancedBaseVertexBaseInstance_ptr = nullptr;
glGetInternalformativPtr glGetInternalformativ_ptr                                                 = nullptr;
glGetActiveAtomicCounterBufferivPtr glGetActiveAtomicCounterBufferiv_ptr                           = nullptr;
glBindImageTexturePtr glBindImageTexture_ptr                                                       = nullptr;
glMemoryBarrierPtr glMemoryBarrier_ptr                                                             = nullptr;
glTexStorage1DPtr glTexStorage1D_ptr                                                               = nullptr;
glTexStorage2DPtr glTexStorage2D_ptr                                                               = nullptr;
glTexStorage3DPtr glTexStorage3D_ptr                                                               = nullptr;
glDrawTransformFeedbackInstancedPtr glDrawTransformFeedbackInstanced_ptr                           = nullptr;
glDrawTransformFeedbackStreamInstancedPtr glDrawTransformFeedbackStreamInstanced_ptr               = nullptr;

bool init_gl_version_4_2([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glDrawArraysInstancedBaseInstance_ptr = reinterpret_cast<glDrawArraysInstancedBaseInstancePtr>(get_function("glDrawArraysInstancedBaseInstance"))) == nullptr || result;
    result = (glDrawElementsInstancedBaseInstance_ptr = reinterpret_cast<glDrawElementsInstancedBaseInstancePtr>(get_function("glDrawElementsInstancedBaseInstance"))) == nullptr || result;
    result = (glDrawElementsInstancedBaseVertexBaseInstance_ptr = reinterpret_cast<glDrawElementsInstancedBaseVertexBaseInstancePtr>(get_function("glDrawElementsInstancedBaseVertexBaseInstance"))) == nullptr || result;
    result = (glGetInternalformativ_ptr = reinterpret_cast<glGetInternalformativPtr>(get_function("glGetInternalformativ"))) == nullptr || result;
    result = (glGetActiveAtomicCounterBufferiv_ptr = reinterpret_cast<glGetActiveAtomicCounterBufferivPtr>(get_function("glGetActiveAtomicCounterBufferiv"))) == nullptr || result;
    result = (glBindImageTexture_ptr = reinterpret_cast<glBindImageTexturePtr>(get_function("glBindImageTexture"))) == nullptr || result;
    result = (glMemoryBarrier_ptr = reinterpret_cast<glMemoryBarrierPtr>(get_function("glMemoryBarrier"))) == nullptr || result;
    result = (glTexStorage1D_ptr = reinterpret_cast<glTexStorage1DPtr>(get_function("glTexStorage1D"))) == nullptr || result;
    result = (glTexStorage2D_ptr = reinterpret_cast<glTexStorage2DPtr>(get_function("glTexStorage2D"))) == nullptr || result;
    result = (glTexStorage3D_ptr = reinterpret_cast<glTexStorage3DPtr>(get_function("glTexStorage3D"))) == nullptr || result;
    result = (glDrawTransformFeedbackInstanced_ptr = reinterpret_cast<glDrawTransformFeedbackInstancedPtr>(get_function("glDrawTransformFeedbackInstanced"))) == nullptr || result;
    result = (glDrawTransformFeedbackStreamInstanced_ptr = reinterpret_cast<glDrawTransformFeedbackStreamInstancedPtr>(get_function("glDrawTransformFeedbackStreamInstanced"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_VERSION_4_3

using glClearBufferDataPtr                 = std::add_pointer_t<decltype(glClearBufferData)>;
using glClearBufferSubDataPtr              = std::add_pointer_t<decltype(glClearBufferSubData)>;
using glDispatchComputePtr                 = std::add_pointer_t<decltype(glDispatchCompute)>;
using glDispatchComputeIndirectPtr         = std::add_pointer_t<decltype(glDispatchComputeIndirect)>;
using glCopyImageSubDataPtr                = std::add_pointer_t<decltype(glCopyImageSubData)>;
using glFramebufferParameteriPtr           = std::add_pointer_t<decltype(glFramebufferParameteri)>;
using glGetFramebufferParameterivPtr       = std::add_pointer_t<decltype(glGetFramebufferParameteriv)>;
using glGetInternalformati64vPtr           = std::add_pointer_t<decltype(glGetInternalformati64v)>;
using glInvalidateTexSubImagePtr           = std::add_pointer_t<decltype(glInvalidateTexSubImage)>;
using glInvalidateTexImagePtr              = std::add_pointer_t<decltype(glInvalidateTexImage)>;
using glInvalidateBufferSubDataPtr         = std::add_pointer_t<decltype(glInvalidateBufferSubData)>;
using glInvalidateBufferDataPtr            = std::add_pointer_t<decltype(glInvalidateBufferData)>;
using glInvalidateFramebufferPtr           = std::add_pointer_t<decltype(glInvalidateFramebuffer)>;
using glInvalidateSubFramebufferPtr        = std::add_pointer_t<decltype(glInvalidateSubFramebuffer)>;
using glMultiDrawArraysIndirectPtr         = std::add_pointer_t<decltype(glMultiDrawArraysIndirect)>;
using glMultiDrawElementsIndirectPtr       = std::add_pointer_t<decltype(glMultiDrawElementsIndirect)>;
using glGetProgramInterfaceivPtr           = std::add_pointer_t<decltype(glGetProgramInterfaceiv)>;
using glGetProgramResourceIndexPtr         = std::add_pointer_t<decltype(glGetProgramResourceIndex)>;
using glGetProgramResourceNamePtr          = std::add_pointer_t<decltype(glGetProgramResourceName)>;
using glGetProgramResourceivPtr            = std::add_pointer_t<decltype(glGetProgramResourceiv)>;
using glGetProgramResourceLocationPtr      = std::add_pointer_t<decltype(glGetProgramResourceLocation)>;
using glGetProgramResourceLocationIndexPtr = std::add_pointer_t<decltype(glGetProgramResourceLocationIndex)>;
using glShaderStorageBlockBindingPtr       = std::add_pointer_t<decltype(glShaderStorageBlockBinding)>;
using glTexBufferRangePtr                  = std::add_pointer_t<decltype(glTexBufferRange)>;
using glTexStorage2DMultisamplePtr         = std::add_pointer_t<decltype(glTexStorage2DMultisample)>;
using glTexStorage3DMultisamplePtr         = std::add_pointer_t<decltype(glTexStorage3DMultisample)>;
using glTextureViewPtr                     = std::add_pointer_t<decltype(glTextureView)>;
using glBindVertexBufferPtr                = std::add_pointer_t<decltype(glBindVertexBuffer)>;
using glVertexAttribFormatPtr              = std::add_pointer_t<decltype(glVertexAttribFormat)>;
using glVertexAttribIFormatPtr             = std::add_pointer_t<decltype(glVertexAttribIFormat)>;
using glVertexAttribLFormatPtr             = std::add_pointer_t<decltype(glVertexAttribLFormat)>;
using glVertexAttribBindingPtr             = std::add_pointer_t<decltype(glVertexAttribBinding)>;
using glVertexBindingDivisorPtr            = std::add_pointer_t<decltype(glVertexBindingDivisor)>;
using glDebugMessageControlPtr             = std::add_pointer_t<decltype(glDebugMessageControl)>;
using glDebugMessageInsertPtr              = std::add_pointer_t<decltype(glDebugMessageInsert)>;
using glDebugMessageCallbackPtr            = std::add_pointer_t<decltype(glDebugMessageCallback)>;
using glGetDebugMessageLogPtr              = std::add_pointer_t<decltype(glGetDebugMessageLog)>;
using glPushDebugGroupPtr                  = std::add_pointer_t<decltype(glPushDebugGroup)>;
using glPopDebugGroupPtr                   = std::add_pointer_t<decltype(glPopDebugGroup)>;
using glObjectLabelPtr                     = std::add_pointer_t<decltype(glObjectLabel)>;
using glGetObjectLabelPtr                  = std::add_pointer_t<decltype(glGetObjectLabel)>;
using glObjectPtrLabelPtr                  = std::add_pointer_t<decltype(glObjectPtrLabel)>;
using glGetObjectPtrLabelPtr               = std::add_pointer_t<decltype(glGetObjectPtrLabel)>;

glClearBufferDataPtr glClearBufferData_ptr                                 = nullptr;
glClearBufferSubDataPtr glClearBufferSubData_ptr                           = nullptr;
glDispatchComputePtr glDispatchCompute_ptr                                 = nullptr;
glDispatchComputeIndirectPtr glDispatchComputeIndirect_ptr                 = nullptr;
glCopyImageSubDataPtr glCopyImageSubData_ptr                               = nullptr;
glFramebufferParameteriPtr glFramebufferParameteri_ptr                     = nullptr;
glGetFramebufferParameterivPtr glGetFramebufferParameteriv_ptr             = nullptr;
glGetInternalformati64vPtr glGetInternalformati64v_ptr                     = nullptr;
glInvalidateTexSubImagePtr glInvalidateTexSubImage_ptr                     = nullptr;
glInvalidateTexImagePtr glInvalidateTexImage_ptr                           = nullptr;
glInvalidateBufferSubDataPtr glInvalidateBufferSubData_ptr                 = nullptr;
glInvalidateBufferDataPtr glInvalidateBufferData_ptr                       = nullptr;
glInvalidateFramebufferPtr glInvalidateFramebuffer_ptr                     = nullptr;
glInvalidateSubFramebufferPtr glInvalidateSubFramebuffer_ptr               = nullptr;
glMultiDrawArraysIndirectPtr glMultiDrawArraysIndirect_ptr                 = nullptr;
glMultiDrawElementsIndirectPtr glMultiDrawElementsIndirect_ptr             = nullptr;
glGetProgramInterfaceivPtr glGetProgramInterfaceiv_ptr                     = nullptr;
glGetProgramResourceIndexPtr glGetProgramResourceIndex_ptr                 = nullptr;
glGetProgramResourceNamePtr glGetProgramResourceName_ptr                   = nullptr;
glGetProgramResourceivPtr glGetProgramResourceiv_ptr                       = nullptr;
glGetProgramResourceLocationPtr glGetProgramResourceLocation_ptr           = nullptr;
glGetProgramResourceLocationIndexPtr glGetProgramResourceLocationIndex_ptr = nullptr;
glShaderStorageBlockBindingPtr glShaderStorageBlockBinding_ptr             = nullptr;
glTexBufferRangePtr glTexBufferRange_ptr                                   = nullptr;
glTexStorage2DMultisamplePtr glTexStorage2DMultisample_ptr                 = nullptr;
glTexStorage3DMultisamplePtr glTexStorage3DMultisample_ptr                 = nullptr;
glTextureViewPtr glTextureView_ptr                                         = nullptr;
glBindVertexBufferPtr glBindVertexBuffer_ptr                               = nullptr;
glVertexAttribFormatPtr glVertexAttribFormat_ptr                           = nullptr;
glVertexAttribIFormatPtr glVertexAttribIFormat_ptr                         = nullptr;
glVertexAttribLFormatPtr glVertexAttribLFormat_ptr                         = nullptr;
glVertexAttribBindingPtr glVertexAttribBinding_ptr                         = nullptr;
glVertexBindingDivisorPtr glVertexBindingDivisor_ptr                       = nullptr;
glDebugMessageControlPtr glDebugMessageControl_ptr                         = nullptr;
glDebugMessageInsertPtr glDebugMessageInsert_ptr                           = nullptr;
glDebugMessageCallbackPtr glDebugMessageCallback_ptr                       = nullptr;
glGetDebugMessageLogPtr glGetDebugMessageLog_ptr                           = nullptr;
glPushDebugGroupPtr glPushDebugGroup_ptr                                   = nullptr;
glPopDebugGroupPtr glPopDebugGroup_ptr                                     = nullptr;
glObjectLabelPtr glObjectLabel_ptr                                         = nullptr;
glGetObjectLabelPtr glGetObjectLabel_ptr                                   = nullptr;
glObjectPtrLabelPtr glObjectPtrLabel_ptr                                   = nullptr;
glGetObjectPtrLabelPtr glGetObjectPtrLabel_ptr                             = nullptr;

bool init_gl_version_4_3([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glClearBufferData_ptr = reinterpret_cast<glClearBufferDataPtr>(get_function("glClearBufferData"))) == nullptr || result;
    result = (glClearBufferSubData_ptr = reinterpret_cast<glClearBufferSubDataPtr>(get_function("glClearBufferSubData"))) == nullptr || result;
    result = (glDispatchCompute_ptr = reinterpret_cast<glDispatchComputePtr>(get_function("glDispatchCompute"))) == nullptr || result;
    result = (glDispatchComputeIndirect_ptr = reinterpret_cast<glDispatchComputeIndirectPtr>(get_function("glDispatchComputeIndirect"))) == nullptr || result;
    result = (glCopyImageSubData_ptr = reinterpret_cast<glCopyImageSubDataPtr>(get_function("glCopyImageSubData"))) == nullptr || result;
    result = (glFramebufferParameteri_ptr = reinterpret_cast<glFramebufferParameteriPtr>(get_function("glFramebufferParameteri"))) == nullptr || result;
    result = (glGetFramebufferParameteriv_ptr = reinterpret_cast<glGetFramebufferParameterivPtr>(get_function("glGetFramebufferParameteriv"))) == nullptr || result;
    result = (glGetInternalformati64v_ptr = reinterpret_cast<glGetInternalformati64vPtr>(get_function("glGetInternalformati64v"))) == nullptr || result;
    result = (glInvalidateTexSubImage_ptr = reinterpret_cast<glInvalidateTexSubImagePtr>(get_function("glInvalidateTexSubImage"))) == nullptr || result;
    result = (glInvalidateTexImage_ptr = reinterpret_cast<glInvalidateTexImagePtr>(get_function("glInvalidateTexImage"))) == nullptr || result;
    result = (glInvalidateBufferSubData_ptr = reinterpret_cast<glInvalidateBufferSubDataPtr>(get_function("glInvalidateBufferSubData"))) == nullptr || result;
    result = (glInvalidateBufferData_ptr = reinterpret_cast<glInvalidateBufferDataPtr>(get_function("glInvalidateBufferData"))) == nullptr || result;
    result = (glInvalidateFramebuffer_ptr = reinterpret_cast<glInvalidateFramebufferPtr>(get_function("glInvalidateFramebuffer"))) == nullptr || result;
    result = (glInvalidateSubFramebuffer_ptr = reinterpret_cast<glInvalidateSubFramebufferPtr>(get_function("glInvalidateSubFramebuffer"))) == nullptr || result;
    result = (glMultiDrawArraysIndirect_ptr = reinterpret_cast<glMultiDrawArraysIndirectPtr>(get_function("glMultiDrawArraysIndirect"))) == nullptr || result;
    result = (glMultiDrawElementsIndirect_ptr = reinterpret_cast<glMultiDrawElementsIndirectPtr>(get_function("glMultiDrawElementsIndirect"))) == nullptr || result;
    result = (glGetProgramInterfaceiv_ptr = reinterpret_cast<glGetProgramInterfaceivPtr>(get_function("glGetProgramInterfaceiv"))) == nullptr || result;
    result = (glGetProgramResourceIndex_ptr = reinterpret_cast<glGetProgramResourceIndexPtr>(get_function("glGetProgramResourceIndex"))) == nullptr || result;
    result = (glGetProgramResourceName_ptr = reinterpret_cast<glGetProgramResourceNamePtr>(get_function("glGetProgramResourceName"))) == nullptr || result;
    result = (glGetProgramResourceiv_ptr = reinterpret_cast<glGetProgramResourceivPtr>(get_function("glGetProgramResourceiv"))) == nullptr || result;
    result = (glGetProgramResourceLocation_ptr = reinterpret_cast<glGetProgramResourceLocationPtr>(get_function("glGetProgramResourceLocation"))) == nullptr || result;
    result = (glGetProgramResourceLocationIndex_ptr = reinterpret_cast<glGetProgramResourceLocationIndexPtr>(get_function("glGetProgramResourceLocationIndex"))) == nullptr || result;
    result = (glShaderStorageBlockBinding_ptr = reinterpret_cast<glShaderStorageBlockBindingPtr>(get_function("glShaderStorageBlockBinding"))) == nullptr || result;
    result = (glTexBufferRange_ptr = reinterpret_cast<glTexBufferRangePtr>(get_function("glTexBufferRange"))) == nullptr || result;
    result = (glTexStorage2DMultisample_ptr = reinterpret_cast<glTexStorage2DMultisamplePtr>(get_function("glTexStorage2DMultisample"))) == nullptr || result;
    result = (glTexStorage3DMultisample_ptr = reinterpret_cast<glTexStorage3DMultisamplePtr>(get_function("glTexStorage3DMultisample"))) == nullptr || result;
    result = (glTextureView_ptr = reinterpret_cast<glTextureViewPtr>(get_function("glTextureView"))) == nullptr || result;
    result = (glBindVertexBuffer_ptr = reinterpret_cast<glBindVertexBufferPtr>(get_function("glBindVertexBuffer"))) == nullptr || result;
    result = (glVertexAttribFormat_ptr = reinterpret_cast<glVertexAttribFormatPtr>(get_function("glVertexAttribFormat"))) == nullptr || result;
    result = (glVertexAttribIFormat_ptr = reinterpret_cast<glVertexAttribIFormatPtr>(get_function("glVertexAttribIFormat"))) == nullptr || result;
    result = (glVertexAttribLFormat_ptr = reinterpret_cast<glVertexAttribLFormatPtr>(get_function("glVertexAttribLFormat"))) == nullptr || result;
    result = (glVertexAttribBinding_ptr = reinterpret_cast<glVertexAttribBindingPtr>(get_function("glVertexAttribBinding"))) == nullptr || result;
    result = (glVertexBindingDivisor_ptr = reinterpret_cast<glVertexBindingDivisorPtr>(get_function("glVertexBindingDivisor"))) == nullptr || result;
    result = (glDebugMessageControl_ptr = reinterpret_cast<glDebugMessageControlPtr>(get_function("glDebugMessageControl"))) == nullptr || result;
    result = (glDebugMessageInsert_ptr = reinterpret_cast<glDebugMessageInsertPtr>(get_function("glDebugMessageInsert"))) == nullptr || result;
    result = (glDebugMessageCallback_ptr = reinterpret_cast<glDebugMessageCallbackPtr>(get_function("glDebugMessageCallback"))) == nullptr || result;
    result = (glGetDebugMessageLog_ptr = reinterpret_cast<glGetDebugMessageLogPtr>(get_function("glGetDebugMessageLog"))) == nullptr || result;
    result = (glPushDebugGroup_ptr = reinterpret_cast<glPushDebugGroupPtr>(get_function("glPushDebugGroup"))) == nullptr || result;
    result = (glPopDebugGroup_ptr = reinterpret_cast<glPopDebugGroupPtr>(get_function("glPopDebugGroup"))) == nullptr || result;
    result = (glObjectLabel_ptr = reinterpret_cast<glObjectLabelPtr>(get_function("glObjectLabel"))) == nullptr || result;
    result = (glGetObjectLabel_ptr = reinterpret_cast<glGetObjectLabelPtr>(get_function("glGetObjectLabel"))) == nullptr || result;
    result = (glObjectPtrLabel_ptr = reinterpret_cast<glObjectPtrLabelPtr>(get_function("glObjectPtrLabel"))) == nullptr || result;
    result = (glGetObjectPtrLabel_ptr = reinterpret_cast<glGetObjectPtrLabelPtr>(get_function("glGetObjectPtrLabel"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_VERSION_4_4

using glBufferStoragePtr     = std::add_pointer_t<decltype(glBufferStorage)>;
using glClearTexImagePtr     = std::add_pointer_t<decltype(glClearTexImage)>;
using glClearTexSubImagePtr  = std::add_pointer_t<decltype(glClearTexSubImage)>;
using glBindBuffersBasePtr   = std::add_pointer_t<decltype(glBindBuffersBase)>;
using glBindBuffersRangePtr  = std::add_pointer_t<decltype(glBindBuffersRange)>;
using glBindTexturesPtr      = std::add_pointer_t<decltype(glBindTextures)>;
using glBindSamplersPtr      = std::add_pointer_t<decltype(glBindSamplers)>;
using glBindImageTexturesPtr = std::add_pointer_t<decltype(glBindImageTextures)>;
using glBindVertexBuffersPtr = std::add_pointer_t<decltype(glBindVertexBuffers)>;

glBufferStoragePtr glBufferStorage_ptr         = nullptr;
glClearTexImagePtr glClearTexImage_ptr         = nullptr;
glClearTexSubImagePtr glClearTexSubImage_ptr   = nullptr;
glBindBuffersBasePtr glBindBuffersBase_ptr     = nullptr;
glBindBuffersRangePtr glBindBuffersRange_ptr   = nullptr;
glBindTexturesPtr glBindTextures_ptr           = nullptr;
glBindSamplersPtr glBindSamplers_ptr           = nullptr;
glBindImageTexturesPtr glBindImageTextures_ptr = nullptr;
glBindVertexBuffersPtr glBindVertexBuffers_ptr = nullptr;

bool init_gl_version_4_4([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glBufferStorage_ptr = reinterpret_cast<glBufferStoragePtr>(get_function("glBufferStorage"))) == nullptr || result;
    result = (glClearTexImage_ptr = reinterpret_cast<glClearTexImagePtr>(get_function("glClearTexImage"))) == nullptr || result;
    result = (glClearTexSubImage_ptr = reinterpret_cast<glClearTexSubImagePtr>(get_function("glClearTexSubImage"))) == nullptr || result;
    result = (glBindBuffersBase_ptr = reinterpret_cast<glBindBuffersBasePtr>(get_function("glBindBuffersBase"))) == nullptr || result;
    result = (glBindBuffersRange_ptr = reinterpret_cast<glBindBuffersRangePtr>(get_function("glBindBuffersRange"))) == nullptr || result;
    result = (glBindTextures_ptr = reinterpret_cast<glBindTexturesPtr>(get_function("glBindTextures"))) == nullptr || result;
    result = (glBindSamplers_ptr = reinterpret_cast<glBindSamplersPtr>(get_function("glBindSamplers"))) == nullptr || result;
    result = (glBindImageTextures_ptr = reinterpret_cast<glBindImageTexturesPtr>(get_function("glBindImageTextures"))) == nullptr || result;
    result = (glBindVertexBuffers_ptr = reinterpret_cast<glBindVertexBuffersPtr>(get_function("glBindVertexBuffers"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_VERSION_4_5

using glClipControlPtr                              = std::add_pointer_t<decltype(glClipControl)>;
using glCreateTransformFeedbacksPtr                 = std::add_pointer_t<decltype(glCreateTransformFeedbacks)>;
using glTransformFeedbackBufferBasePtr              = std::add_pointer_t<decltype(glTransformFeedbackBufferBase)>;
using glTransformFeedbackBufferRangePtr             = std::add_pointer_t<decltype(glTransformFeedbackBufferRange)>;
using glGetTransformFeedbackivPtr                   = std::add_pointer_t<decltype(glGetTransformFeedbackiv)>;
using glGetTransformFeedbacki_vPtr                  = std::add_pointer_t<decltype(glGetTransformFeedbacki_v)>;
using glGetTransformFeedbacki64_vPtr                = std::add_pointer_t<decltype(glGetTransformFeedbacki64_v)>;
using glCreateBuffersPtr                            = std::add_pointer_t<decltype(glCreateBuffers)>;
using glNamedBufferStoragePtr                       = std::add_pointer_t<decltype(glNamedBufferStorage)>;
using glNamedBufferDataPtr                          = std::add_pointer_t<decltype(glNamedBufferData)>;
using glNamedBufferSubDataPtr                       = std::add_pointer_t<decltype(glNamedBufferSubData)>;
using glCopyNamedBufferSubDataPtr                   = std::add_pointer_t<decltype(glCopyNamedBufferSubData)>;
using glClearNamedBufferDataPtr                     = std::add_pointer_t<decltype(glClearNamedBufferData)>;
using glClearNamedBufferSubDataPtr                  = std::add_pointer_t<decltype(glClearNamedBufferSubData)>;
using glMapNamedBufferPtr                           = std::add_pointer_t<decltype(glMapNamedBuffer)>;
using glMapNamedBufferRangePtr                      = std::add_pointer_t<decltype(glMapNamedBufferRange)>;
using glUnmapNamedBufferPtr                         = std::add_pointer_t<decltype(glUnmapNamedBuffer)>;
using glFlushMappedNamedBufferRangePtr              = std::add_pointer_t<decltype(glFlushMappedNamedBufferRange)>;
using glGetNamedBufferParameterivPtr                = std::add_pointer_t<decltype(glGetNamedBufferParameteriv)>;
using glGetNamedBufferParameteri64vPtr              = std::add_pointer_t<decltype(glGetNamedBufferParameteri64v)>;
using glGetNamedBufferPointervPtr                   = std::add_pointer_t<decltype(glGetNamedBufferPointerv)>;
using glGetNamedBufferSubDataPtr                    = std::add_pointer_t<decltype(glGetNamedBufferSubData)>;
using glCreateFramebuffersPtr                       = std::add_pointer_t<decltype(glCreateFramebuffers)>;
using glNamedFramebufferRenderbufferPtr             = std::add_pointer_t<decltype(glNamedFramebufferRenderbuffer)>;
using glNamedFramebufferParameteriPtr               = std::add_pointer_t<decltype(glNamedFramebufferParameteri)>;
using glNamedFramebufferTexturePtr                  = std::add_pointer_t<decltype(glNamedFramebufferTexture)>;
using glNamedFramebufferTextureLayerPtr             = std::add_pointer_t<decltype(glNamedFramebufferTextureLayer)>;
using glNamedFramebufferDrawBufferPtr               = std::add_pointer_t<decltype(glNamedFramebufferDrawBuffer)>;
using glNamedFramebufferDrawBuffersPtr              = std::add_pointer_t<decltype(glNamedFramebufferDrawBuffers)>;
using glNamedFramebufferReadBufferPtr               = std::add_pointer_t<decltype(glNamedFramebufferReadBuffer)>;
using glInvalidateNamedFramebufferDataPtr           = std::add_pointer_t<decltype(glInvalidateNamedFramebufferData)>;
using glInvalidateNamedFramebufferSubDataPtr        = std::add_pointer_t<decltype(glInvalidateNamedFramebufferSubData)>;
using glClearNamedFramebufferivPtr                  = std::add_pointer_t<decltype(glClearNamedFramebufferiv)>;
using glClearNamedFramebufferuivPtr                 = std::add_pointer_t<decltype(glClearNamedFramebufferuiv)>;
using glClearNamedFramebufferfvPtr                  = std::add_pointer_t<decltype(glClearNamedFramebufferfv)>;
using glClearNamedFramebufferfiPtr                  = std::add_pointer_t<decltype(glClearNamedFramebufferfi)>;
using glBlitNamedFramebufferPtr                     = std::add_pointer_t<decltype(glBlitNamedFramebuffer)>;
using glCheckNamedFramebufferStatusPtr              = std::add_pointer_t<decltype(glCheckNamedFramebufferStatus)>;
using glGetNamedFramebufferParameterivPtr           = std::add_pointer_t<decltype(glGetNamedFramebufferParameteriv)>;
using glGetNamedFramebufferAttachmentParameterivPtr = std::add_pointer_t<
decltype(glGetNamedFramebufferAttachmentParameteriv)>;
using glCreateRenderbuffersPtr                 = std::add_pointer_t<decltype(glCreateRenderbuffers)>;
using glNamedRenderbufferStoragePtr            = std::add_pointer_t<decltype(glNamedRenderbufferStorage)>;
using glNamedRenderbufferStorageMultisamplePtr = std::add_pointer_t<decltype(glNamedRenderbufferStorageMultisample)>;
using glGetNamedRenderbufferParameterivPtr     = std::add_pointer_t<decltype(glGetNamedRenderbufferParameteriv)>;
using glCreateTexturesPtr                      = std::add_pointer_t<decltype(glCreateTextures)>;
using glTextureBufferPtr                       = std::add_pointer_t<decltype(glTextureBuffer)>;
using glTextureBufferRangePtr                  = std::add_pointer_t<decltype(glTextureBufferRange)>;
using glTextureStorage1DPtr                    = std::add_pointer_t<decltype(glTextureStorage1D)>;
using glTextureStorage2DPtr                    = std::add_pointer_t<decltype(glTextureStorage2D)>;
using glTextureStorage3DPtr                    = std::add_pointer_t<decltype(glTextureStorage3D)>;
using glTextureStorage2DMultisamplePtr         = std::add_pointer_t<decltype(glTextureStorage2DMultisample)>;
using glTextureStorage3DMultisamplePtr         = std::add_pointer_t<decltype(glTextureStorage3DMultisample)>;
using glTextureSubImage1DPtr                   = std::add_pointer_t<decltype(glTextureSubImage1D)>;
using glTextureSubImage2DPtr                   = std::add_pointer_t<decltype(glTextureSubImage2D)>;
using glTextureSubImage3DPtr                   = std::add_pointer_t<decltype(glTextureSubImage3D)>;
using glCompressedTextureSubImage1DPtr         = std::add_pointer_t<decltype(glCompressedTextureSubImage1D)>;
using glCompressedTextureSubImage2DPtr         = std::add_pointer_t<decltype(glCompressedTextureSubImage2D)>;
using glCompressedTextureSubImage3DPtr         = std::add_pointer_t<decltype(glCompressedTextureSubImage3D)>;
using glCopyTextureSubImage1DPtr               = std::add_pointer_t<decltype(glCopyTextureSubImage1D)>;
using glCopyTextureSubImage2DPtr               = std::add_pointer_t<decltype(glCopyTextureSubImage2D)>;
using glCopyTextureSubImage3DPtr               = std::add_pointer_t<decltype(glCopyTextureSubImage3D)>;
using glTextureParameterfPtr                   = std::add_pointer_t<decltype(glTextureParameterf)>;
using glTextureParameterfvPtr                  = std::add_pointer_t<decltype(glTextureParameterfv)>;
using glTextureParameteriPtr                   = std::add_pointer_t<decltype(glTextureParameteri)>;
using glTextureParameterIivPtr                 = std::add_pointer_t<decltype(glTextureParameterIiv)>;
using glTextureParameterIuivPtr                = std::add_pointer_t<decltype(glTextureParameterIuiv)>;
using glTextureParameterivPtr                  = std::add_pointer_t<decltype(glTextureParameteriv)>;
using glGenerateTextureMipmapPtr               = std::add_pointer_t<decltype(glGenerateTextureMipmap)>;
using glBindTextureUnitPtr                     = std::add_pointer_t<decltype(glBindTextureUnit)>;
using glGetTextureImagePtr                     = std::add_pointer_t<decltype(glGetTextureImage)>;
using glGetCompressedTextureImagePtr           = std::add_pointer_t<decltype(glGetCompressedTextureImage)>;
using glGetTextureLevelParameterfvPtr          = std::add_pointer_t<decltype(glGetTextureLevelParameterfv)>;
using glGetTextureLevelParameterivPtr          = std::add_pointer_t<decltype(glGetTextureLevelParameteriv)>;
using glGetTextureParameterfvPtr               = std::add_pointer_t<decltype(glGetTextureParameterfv)>;
using glGetTextureParameterIivPtr              = std::add_pointer_t<decltype(glGetTextureParameterIiv)>;
using glGetTextureParameterIuivPtr             = std::add_pointer_t<decltype(glGetTextureParameterIuiv)>;
using glGetTextureParameterivPtr               = std::add_pointer_t<decltype(glGetTextureParameteriv)>;
using glCreateVertexArraysPtr                  = std::add_pointer_t<decltype(glCreateVertexArrays)>;
using glDisableVertexArrayAttribPtr            = std::add_pointer_t<decltype(glDisableVertexArrayAttrib)>;
using glEnableVertexArrayAttribPtr             = std::add_pointer_t<decltype(glEnableVertexArrayAttrib)>;
using glVertexArrayElementBufferPtr            = std::add_pointer_t<decltype(glVertexArrayElementBuffer)>;
using glVertexArrayVertexBufferPtr             = std::add_pointer_t<decltype(glVertexArrayVertexBuffer)>;
using glVertexArrayVertexBuffersPtr            = std::add_pointer_t<decltype(glVertexArrayVertexBuffers)>;
using glVertexArrayAttribBindingPtr            = std::add_pointer_t<decltype(glVertexArrayAttribBinding)>;
using glVertexArrayAttribFormatPtr             = std::add_pointer_t<decltype(glVertexArrayAttribFormat)>;
using glVertexArrayAttribIFormatPtr            = std::add_pointer_t<decltype(glVertexArrayAttribIFormat)>;
using glVertexArrayAttribLFormatPtr            = std::add_pointer_t<decltype(glVertexArrayAttribLFormat)>;
using glVertexArrayBindingDivisorPtr           = std::add_pointer_t<decltype(glVertexArrayBindingDivisor)>;
using glGetVertexArrayivPtr                    = std::add_pointer_t<decltype(glGetVertexArrayiv)>;
using glGetVertexArrayIndexedivPtr             = std::add_pointer_t<decltype(glGetVertexArrayIndexediv)>;
using glGetVertexArrayIndexed64ivPtr           = std::add_pointer_t<decltype(glGetVertexArrayIndexed64iv)>;
using glCreateSamplersPtr                      = std::add_pointer_t<decltype(glCreateSamplers)>;
using glCreateProgramPipelinesPtr              = std::add_pointer_t<decltype(glCreateProgramPipelines)>;
using glCreateQueriesPtr                       = std::add_pointer_t<decltype(glCreateQueries)>;
using glGetQueryBufferObjecti64vPtr            = std::add_pointer_t<decltype(glGetQueryBufferObjecti64v)>;
using glGetQueryBufferObjectivPtr              = std::add_pointer_t<decltype(glGetQueryBufferObjectiv)>;
using glGetQueryBufferObjectui64vPtr           = std::add_pointer_t<decltype(glGetQueryBufferObjectui64v)>;
using glGetQueryBufferObjectuivPtr             = std::add_pointer_t<decltype(glGetQueryBufferObjectuiv)>;
using glMemoryBarrierByRegionPtr               = std::add_pointer_t<decltype(glMemoryBarrierByRegion)>;
using glGetTextureSubImagePtr                  = std::add_pointer_t<decltype(glGetTextureSubImage)>;
using glGetCompressedTextureSubImagePtr        = std::add_pointer_t<decltype(glGetCompressedTextureSubImage)>;
using glGetGraphicsResetStatusPtr              = std::add_pointer_t<decltype(glGetGraphicsResetStatus)>;
using glGetnCompressedTexImagePtr              = std::add_pointer_t<decltype(glGetnCompressedTexImage)>;
using glGetnTexImagePtr                        = std::add_pointer_t<decltype(glGetnTexImage)>;
using glGetnUniformdvPtr                       = std::add_pointer_t<decltype(glGetnUniformdv)>;
using glGetnUniformfvPtr                       = std::add_pointer_t<decltype(glGetnUniformfv)>;
using glGetnUniformivPtr                       = std::add_pointer_t<decltype(glGetnUniformiv)>;
using glGetnUniformuivPtr                      = std::add_pointer_t<decltype(glGetnUniformuiv)>;
using glReadnPixelsPtr                         = std::add_pointer_t<decltype(glReadnPixels)>;
using glTextureBarrierPtr                      = std::add_pointer_t<decltype(glTextureBarrier)>;

glClipControlPtr glClipControl_ptr                                                           = nullptr;
glCreateTransformFeedbacksPtr glCreateTransformFeedbacks_ptr                                 = nullptr;
glTransformFeedbackBufferBasePtr glTransformFeedbackBufferBase_ptr                           = nullptr;
glTransformFeedbackBufferRangePtr glTransformFeedbackBufferRange_ptr                         = nullptr;
glGetTransformFeedbackivPtr glGetTransformFeedbackiv_ptr                                     = nullptr;
glGetTransformFeedbacki_vPtr glGetTransformFeedbacki_v_ptr                                   = nullptr;
glGetTransformFeedbacki64_vPtr glGetTransformFeedbacki64_v_ptr                               = nullptr;
glCreateBuffersPtr glCreateBuffers_ptr                                                       = nullptr;
glNamedBufferStoragePtr glNamedBufferStorage_ptr                                             = nullptr;
glNamedBufferDataPtr glNamedBufferData_ptr                                                   = nullptr;
glNamedBufferSubDataPtr glNamedBufferSubData_ptr                                             = nullptr;
glCopyNamedBufferSubDataPtr glCopyNamedBufferSubData_ptr                                     = nullptr;
glClearNamedBufferDataPtr glClearNamedBufferData_ptr                                         = nullptr;
glClearNamedBufferSubDataPtr glClearNamedBufferSubData_ptr                                   = nullptr;
glMapNamedBufferPtr glMapNamedBuffer_ptr                                                     = nullptr;
glMapNamedBufferRangePtr glMapNamedBufferRange_ptr                                           = nullptr;
glUnmapNamedBufferPtr glUnmapNamedBuffer_ptr                                                 = nullptr;
glFlushMappedNamedBufferRangePtr glFlushMappedNamedBufferRange_ptr                           = nullptr;
glGetNamedBufferParameterivPtr glGetNamedBufferParameteriv_ptr                               = nullptr;
glGetNamedBufferParameteri64vPtr glGetNamedBufferParameteri64v_ptr                           = nullptr;
glGetNamedBufferPointervPtr glGetNamedBufferPointerv_ptr                                     = nullptr;
glGetNamedBufferSubDataPtr glGetNamedBufferSubData_ptr                                       = nullptr;
glCreateFramebuffersPtr glCreateFramebuffers_ptr                                             = nullptr;
glNamedFramebufferRenderbufferPtr glNamedFramebufferRenderbuffer_ptr                         = nullptr;
glNamedFramebufferParameteriPtr glNamedFramebufferParameteri_ptr                             = nullptr;
glNamedFramebufferTexturePtr glNamedFramebufferTexture_ptr                                   = nullptr;
glNamedFramebufferTextureLayerPtr glNamedFramebufferTextureLayer_ptr                         = nullptr;
glNamedFramebufferDrawBufferPtr glNamedFramebufferDrawBuffer_ptr                             = nullptr;
glNamedFramebufferDrawBuffersPtr glNamedFramebufferDrawBuffers_ptr                           = nullptr;
glNamedFramebufferReadBufferPtr glNamedFramebufferReadBuffer_ptr                             = nullptr;
glInvalidateNamedFramebufferDataPtr glInvalidateNamedFramebufferData_ptr                     = nullptr;
glInvalidateNamedFramebufferSubDataPtr glInvalidateNamedFramebufferSubData_ptr               = nullptr;
glClearNamedFramebufferivPtr glClearNamedFramebufferiv_ptr                                   = nullptr;
glClearNamedFramebufferuivPtr glClearNamedFramebufferuiv_ptr                                 = nullptr;
glClearNamedFramebufferfvPtr glClearNamedFramebufferfv_ptr                                   = nullptr;
glClearNamedFramebufferfiPtr glClearNamedFramebufferfi_ptr                                   = nullptr;
glBlitNamedFramebufferPtr glBlitNamedFramebuffer_ptr                                         = nullptr;
glCheckNamedFramebufferStatusPtr glCheckNamedFramebufferStatus_ptr                           = nullptr;
glGetNamedFramebufferParameterivPtr glGetNamedFramebufferParameteriv_ptr                     = nullptr;
glGetNamedFramebufferAttachmentParameterivPtr glGetNamedFramebufferAttachmentParameteriv_ptr = nullptr;
glCreateRenderbuffersPtr glCreateRenderbuffers_ptr                                           = nullptr;
glNamedRenderbufferStoragePtr glNamedRenderbufferStorage_ptr                                 = nullptr;
glNamedRenderbufferStorageMultisamplePtr glNamedRenderbufferStorageMultisample_ptr           = nullptr;
glGetNamedRenderbufferParameterivPtr glGetNamedRenderbufferParameteriv_ptr                   = nullptr;
glCreateTexturesPtr glCreateTextures_ptr                                                     = nullptr;
glTextureBufferPtr glTextureBuffer_ptr                                                       = nullptr;
glTextureBufferRangePtr glTextureBufferRange_ptr                                             = nullptr;
glTextureStorage1DPtr glTextureStorage1D_ptr                                                 = nullptr;
glTextureStorage2DPtr glTextureStorage2D_ptr                                                 = nullptr;
glTextureStorage3DPtr glTextureStorage3D_ptr                                                 = nullptr;
glTextureStorage2DMultisamplePtr glTextureStorage2DMultisample_ptr                           = nullptr;
glTextureStorage3DMultisamplePtr glTextureStorage3DMultisample_ptr                           = nullptr;
glTextureSubImage1DPtr glTextureSubImage1D_ptr                                               = nullptr;
glTextureSubImage2DPtr glTextureSubImage2D_ptr                                               = nullptr;
glTextureSubImage3DPtr glTextureSubImage3D_ptr                                               = nullptr;
glCompressedTextureSubImage1DPtr glCompressedTextureSubImage1D_ptr                           = nullptr;
glCompressedTextureSubImage2DPtr glCompressedTextureSubImage2D_ptr                           = nullptr;
glCompressedTextureSubImage3DPtr glCompressedTextureSubImage3D_ptr                           = nullptr;
glCopyTextureSubImage1DPtr glCopyTextureSubImage1D_ptr                                       = nullptr;
glCopyTextureSubImage2DPtr glCopyTextureSubImage2D_ptr                                       = nullptr;
glCopyTextureSubImage3DPtr glCopyTextureSubImage3D_ptr                                       = nullptr;
glTextureParameterfPtr glTextureParameterf_ptr                                               = nullptr;
glTextureParameterfvPtr glTextureParameterfv_ptr                                             = nullptr;
glTextureParameteriPtr glTextureParameteri_ptr                                               = nullptr;
glTextureParameterIivPtr glTextureParameterIiv_ptr                                           = nullptr;
glTextureParameterIuivPtr glTextureParameterIuiv_ptr                                         = nullptr;
glTextureParameterivPtr glTextureParameteriv_ptr                                             = nullptr;
glGenerateTextureMipmapPtr glGenerateTextureMipmap_ptr                                       = nullptr;
glBindTextureUnitPtr glBindTextureUnit_ptr                                                   = nullptr;
glGetTextureImagePtr glGetTextureImage_ptr                                                   = nullptr;
glGetCompressedTextureImagePtr glGetCompressedTextureImage_ptr                               = nullptr;
glGetTextureLevelParameterfvPtr glGetTextureLevelParameterfv_ptr                             = nullptr;
glGetTextureLevelParameterivPtr glGetTextureLevelParameteriv_ptr                             = nullptr;
glGetTextureParameterfvPtr glGetTextureParameterfv_ptr                                       = nullptr;
glGetTextureParameterIivPtr glGetTextureParameterIiv_ptr                                     = nullptr;
glGetTextureParameterIuivPtr glGetTextureParameterIuiv_ptr                                   = nullptr;
glGetTextureParameterivPtr glGetTextureParameteriv_ptr                                       = nullptr;
glCreateVertexArraysPtr glCreateVertexArrays_ptr                                             = nullptr;
glDisableVertexArrayAttribPtr glDisableVertexArrayAttrib_ptr                                 = nullptr;
glEnableVertexArrayAttribPtr glEnableVertexArrayAttrib_ptr                                   = nullptr;
glVertexArrayElementBufferPtr glVertexArrayElementBuffer_ptr                                 = nullptr;
glVertexArrayVertexBufferPtr glVertexArrayVertexBuffer_ptr                                   = nullptr;
glVertexArrayVertexBuffersPtr glVertexArrayVertexBuffers_ptr                                 = nullptr;
glVertexArrayAttribBindingPtr glVertexArrayAttribBinding_ptr                                 = nullptr;
glVertexArrayAttribFormatPtr glVertexArrayAttribFormat_ptr                                   = nullptr;
glVertexArrayAttribIFormatPtr glVertexArrayAttribIFormat_ptr                                 = nullptr;
glVertexArrayAttribLFormatPtr glVertexArrayAttribLFormat_ptr                                 = nullptr;
glVertexArrayBindingDivisorPtr glVertexArrayBindingDivisor_ptr                               = nullptr;
glGetVertexArrayivPtr glGetVertexArrayiv_ptr                                                 = nullptr;
glGetVertexArrayIndexedivPtr glGetVertexArrayIndexediv_ptr                                   = nullptr;
glGetVertexArrayIndexed64ivPtr glGetVertexArrayIndexed64iv_ptr                               = nullptr;
glCreateSamplersPtr glCreateSamplers_ptr                                                     = nullptr;
glCreateProgramPipelinesPtr glCreateProgramPipelines_ptr                                     = nullptr;
glCreateQueriesPtr glCreateQueries_ptr                                                       = nullptr;
glGetQueryBufferObjecti64vPtr glGetQueryBufferObjecti64v_ptr                                 = nullptr;
glGetQueryBufferObjectivPtr glGetQueryBufferObjectiv_ptr                                     = nullptr;
glGetQueryBufferObjectui64vPtr glGetQueryBufferObjectui64v_ptr                               = nullptr;
glGetQueryBufferObjectuivPtr glGetQueryBufferObjectuiv_ptr                                   = nullptr;
glMemoryBarrierByRegionPtr glMemoryBarrierByRegion_ptr                                       = nullptr;
glGetTextureSubImagePtr glGetTextureSubImage_ptr                                             = nullptr;
glGetCompressedTextureSubImagePtr glGetCompressedTextureSubImage_ptr                         = nullptr;
glGetGraphicsResetStatusPtr glGetGraphicsResetStatus_ptr                                     = nullptr;
glGetnCompressedTexImagePtr glGetnCompressedTexImage_ptr                                     = nullptr;
glGetnTexImagePtr glGetnTexImage_ptr                                                         = nullptr;
glGetnUniformdvPtr glGetnUniformdv_ptr                                                       = nullptr;
glGetnUniformfvPtr glGetnUniformfv_ptr                                                       = nullptr;
glGetnUniformivPtr glGetnUniformiv_ptr                                                       = nullptr;
glGetnUniformuivPtr glGetnUniformuiv_ptr                                                     = nullptr;
glReadnPixelsPtr glReadnPixels_ptr                                                           = nullptr;
glTextureBarrierPtr glTextureBarrier_ptr                                                     = nullptr;

bool init_gl_version_4_5([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glClipControl_ptr = reinterpret_cast<glClipControlPtr>(get_function("glClipControl"))) == nullptr || result;
    result = (glCreateTransformFeedbacks_ptr = reinterpret_cast<glCreateTransformFeedbacksPtr>(get_function("glCreateTransformFeedbacks"))) == nullptr || result;
    result = (glTransformFeedbackBufferBase_ptr = reinterpret_cast<glTransformFeedbackBufferBasePtr>(get_function("glTransformFeedbackBufferBase"))) == nullptr || result;
    result = (glTransformFeedbackBufferRange_ptr = reinterpret_cast<glTransformFeedbackBufferRangePtr>(get_function("glTransformFeedbackBufferRange"))) == nullptr || result;
    result = (glGetTransformFeedbackiv_ptr = reinterpret_cast<glGetTransformFeedbackivPtr>(get_function("glGetTransformFeedbackiv"))) == nullptr || result;
    result = (glGetTransformFeedbacki_v_ptr = reinterpret_cast<glGetTransformFeedbacki_vPtr>(get_function("glGetTransformFeedbacki_v"))) == nullptr || result;
    result = (glGetTransformFeedbacki64_v_ptr = reinterpret_cast<glGetTransformFeedbacki64_vPtr>(get_function("glGetTransformFeedbacki64_v"))) == nullptr || result;
    result = (glCreateBuffers_ptr = reinterpret_cast<glCreateBuffersPtr>(get_function("glCreateBuffers"))) == nullptr || result;
    result = (glNamedBufferStorage_ptr = reinterpret_cast<glNamedBufferStoragePtr>(get_function("glNamedBufferStorage"))) == nullptr || result;
    result = (glNamedBufferData_ptr = reinterpret_cast<glNamedBufferDataPtr>(get_function("glNamedBufferData"))) == nullptr || result;
    result = (glNamedBufferSubData_ptr = reinterpret_cast<glNamedBufferSubDataPtr>(get_function("glNamedBufferSubData"))) == nullptr || result;
    result = (glCopyNamedBufferSubData_ptr = reinterpret_cast<glCopyNamedBufferSubDataPtr>(get_function("glCopyNamedBufferSubData"))) == nullptr || result;
    result = (glClearNamedBufferData_ptr = reinterpret_cast<glClearNamedBufferDataPtr>(get_function("glClearNamedBufferData"))) == nullptr || result;
    result = (glClearNamedBufferSubData_ptr = reinterpret_cast<glClearNamedBufferSubDataPtr>(get_function("glClearNamedBufferSubData"))) == nullptr || result;
    result = (glMapNamedBuffer_ptr = reinterpret_cast<glMapNamedBufferPtr>(get_function("glMapNamedBuffer"))) == nullptr || result;
    result = (glMapNamedBufferRange_ptr = reinterpret_cast<glMapNamedBufferRangePtr>(get_function("glMapNamedBufferRange"))) == nullptr || result;
    result = (glUnmapNamedBuffer_ptr = reinterpret_cast<glUnmapNamedBufferPtr>(get_function("glUnmapNamedBuffer"))) == nullptr || result;
    result = (glFlushMappedNamedBufferRange_ptr = reinterpret_cast<glFlushMappedNamedBufferRangePtr>(get_function("glFlushMappedNamedBufferRange"))) == nullptr || result;
    result = (glGetNamedBufferParameteriv_ptr = reinterpret_cast<glGetNamedBufferParameterivPtr>(get_function("glGetNamedBufferParameteriv"))) == nullptr || result;
    result = (glGetNamedBufferParameteri64v_ptr = reinterpret_cast<glGetNamedBufferParameteri64vPtr>(get_function("glGetNamedBufferParameteri64v"))) == nullptr || result;
    result = (glGetNamedBufferPointerv_ptr = reinterpret_cast<glGetNamedBufferPointervPtr>(get_function("glGetNamedBufferPointerv"))) == nullptr || result;
    result = (glGetNamedBufferSubData_ptr = reinterpret_cast<glGetNamedBufferSubDataPtr>(get_function("glGetNamedBufferSubData"))) == nullptr || result;
    result = (glCreateFramebuffers_ptr = reinterpret_cast<glCreateFramebuffersPtr>(get_function("glCreateFramebuffers"))) == nullptr || result;
    result = (glNamedFramebufferRenderbuffer_ptr = reinterpret_cast<glNamedFramebufferRenderbufferPtr>(get_function("glNamedFramebufferRenderbuffer"))) == nullptr || result;
    result = (glNamedFramebufferParameteri_ptr = reinterpret_cast<glNamedFramebufferParameteriPtr>(get_function("glNamedFramebufferParameteri"))) == nullptr || result;
    result = (glNamedFramebufferTexture_ptr = reinterpret_cast<glNamedFramebufferTexturePtr>(get_function("glNamedFramebufferTexture"))) == nullptr || result;
    result = (glNamedFramebufferTextureLayer_ptr = reinterpret_cast<glNamedFramebufferTextureLayerPtr>(get_function("glNamedFramebufferTextureLayer"))) == nullptr || result;
    result = (glNamedFramebufferDrawBuffer_ptr = reinterpret_cast<glNamedFramebufferDrawBufferPtr>(get_function("glNamedFramebufferDrawBuffer"))) == nullptr || result;
    result = (glNamedFramebufferDrawBuffers_ptr = reinterpret_cast<glNamedFramebufferDrawBuffersPtr>(get_function("glNamedFramebufferDrawBuffers"))) == nullptr || result;
    result = (glNamedFramebufferReadBuffer_ptr = reinterpret_cast<glNamedFramebufferReadBufferPtr>(get_function("glNamedFramebufferReadBuffer"))) == nullptr || result;
    result = (glInvalidateNamedFramebufferData_ptr = reinterpret_cast<glInvalidateNamedFramebufferDataPtr>(get_function("glInvalidateNamedFramebufferData"))) == nullptr || result;
    result = (glInvalidateNamedFramebufferSubData_ptr = reinterpret_cast<glInvalidateNamedFramebufferSubDataPtr>(get_function("glInvalidateNamedFramebufferSubData"))) == nullptr || result;
    result = (glClearNamedFramebufferiv_ptr = reinterpret_cast<glClearNamedFramebufferivPtr>(get_function("glClearNamedFramebufferiv"))) == nullptr || result;
    result = (glClearNamedFramebufferuiv_ptr = reinterpret_cast<glClearNamedFramebufferuivPtr>(get_function("glClearNamedFramebufferuiv"))) == nullptr || result;
    result = (glClearNamedFramebufferfv_ptr = reinterpret_cast<glClearNamedFramebufferfvPtr>(get_function("glClearNamedFramebufferfv"))) == nullptr || result;
    result = (glClearNamedFramebufferfi_ptr = reinterpret_cast<glClearNamedFramebufferfiPtr>(get_function("glClearNamedFramebufferfi"))) == nullptr || result;
    result = (glBlitNamedFramebuffer_ptr = reinterpret_cast<glBlitNamedFramebufferPtr>(get_function("glBlitNamedFramebuffer"))) == nullptr || result;
    result = (glCheckNamedFramebufferStatus_ptr = reinterpret_cast<glCheckNamedFramebufferStatusPtr>(get_function("glCheckNamedFramebufferStatus"))) == nullptr || result;
    result = (glGetNamedFramebufferParameteriv_ptr = reinterpret_cast<glGetNamedFramebufferParameterivPtr>(get_function("glGetNamedFramebufferParameteriv"))) == nullptr || result;
    result = (glGetNamedFramebufferAttachmentParameteriv_ptr = reinterpret_cast<glGetNamedFramebufferAttachmentParameterivPtr>(get_function("glGetNamedFramebufferAttachmentParameteriv"))) == nullptr || result;
    result = (glCreateRenderbuffers_ptr = reinterpret_cast<glCreateRenderbuffersPtr>(get_function("glCreateRenderbuffers"))) == nullptr || result;
    result = (glNamedRenderbufferStorage_ptr = reinterpret_cast<glNamedRenderbufferStoragePtr>(get_function("glNamedRenderbufferStorage"))) == nullptr || result;
    result = (glNamedRenderbufferStorageMultisample_ptr = reinterpret_cast<glNamedRenderbufferStorageMultisamplePtr>(get_function("glNamedRenderbufferStorageMultisample"))) == nullptr || result;
    result = (glGetNamedRenderbufferParameteriv_ptr = reinterpret_cast<glGetNamedRenderbufferParameterivPtr>(get_function("glGetNamedRenderbufferParameteriv"))) == nullptr || result;
    result = (glCreateTextures_ptr = reinterpret_cast<glCreateTexturesPtr>(get_function("glCreateTextures"))) == nullptr || result;
    result = (glTextureBuffer_ptr = reinterpret_cast<glTextureBufferPtr>(get_function("glTextureBuffer"))) == nullptr || result;
    result = (glTextureBufferRange_ptr = reinterpret_cast<glTextureBufferRangePtr>(get_function("glTextureBufferRange"))) == nullptr || result;
    result = (glTextureStorage1D_ptr = reinterpret_cast<glTextureStorage1DPtr>(get_function("glTextureStorage1D"))) == nullptr || result;
    result = (glTextureStorage2D_ptr = reinterpret_cast<glTextureStorage2DPtr>(get_function("glTextureStorage2D"))) == nullptr || result;
    result = (glTextureStorage3D_ptr = reinterpret_cast<glTextureStorage3DPtr>(get_function("glTextureStorage3D"))) == nullptr || result;
    result = (glTextureStorage2DMultisample_ptr = reinterpret_cast<glTextureStorage2DMultisamplePtr>(get_function("glTextureStorage2DMultisample"))) == nullptr || result;
    result = (glTextureStorage3DMultisample_ptr = reinterpret_cast<glTextureStorage3DMultisamplePtr>(get_function("glTextureStorage3DMultisample"))) == nullptr || result;
    result = (glTextureSubImage1D_ptr = reinterpret_cast<glTextureSubImage1DPtr>(get_function("glTextureSubImage1D"))) == nullptr || result;
    result = (glTextureSubImage2D_ptr = reinterpret_cast<glTextureSubImage2DPtr>(get_function("glTextureSubImage2D"))) == nullptr || result;
    result = (glTextureSubImage3D_ptr = reinterpret_cast<glTextureSubImage3DPtr>(get_function("glTextureSubImage3D"))) == nullptr || result;
    result = (glCompressedTextureSubImage1D_ptr = reinterpret_cast<glCompressedTextureSubImage1DPtr>(get_function("glCompressedTextureSubImage1D"))) == nullptr || result;
    result = (glCompressedTextureSubImage2D_ptr = reinterpret_cast<glCompressedTextureSubImage2DPtr>(get_function("glCompressedTextureSubImage2D"))) == nullptr || result;
    result = (glCompressedTextureSubImage3D_ptr = reinterpret_cast<glCompressedTextureSubImage3DPtr>(get_function("glCompressedTextureSubImage3D"))) == nullptr || result;
    result = (glCopyTextureSubImage1D_ptr = reinterpret_cast<glCopyTextureSubImage1DPtr>(get_function("glCopyTextureSubImage1D"))) == nullptr || result;
    result = (glCopyTextureSubImage2D_ptr = reinterpret_cast<glCopyTextureSubImage2DPtr>(get_function("glCopyTextureSubImage2D"))) == nullptr || result;
    result = (glCopyTextureSubImage3D_ptr = reinterpret_cast<glCopyTextureSubImage3DPtr>(get_function("glCopyTextureSubImage3D"))) == nullptr || result;
    result = (glTextureParameterf_ptr = reinterpret_cast<glTextureParameterfPtr>(get_function("glTextureParameterf"))) == nullptr || result;
    result = (glTextureParameterfv_ptr = reinterpret_cast<glTextureParameterfvPtr>(get_function("glTextureParameterfv"))) == nullptr || result;
    result = (glTextureParameteri_ptr = reinterpret_cast<glTextureParameteriPtr>(get_function("glTextureParameteri"))) == nullptr || result;
    result = (glTextureParameterIiv_ptr = reinterpret_cast<glTextureParameterIivPtr>(get_function("glTextureParameterIiv"))) == nullptr || result;
    result = (glTextureParameterIuiv_ptr = reinterpret_cast<glTextureParameterIuivPtr>(get_function("glTextureParameterIuiv"))) == nullptr || result;
    result = (glTextureParameteriv_ptr = reinterpret_cast<glTextureParameterivPtr>(get_function("glTextureParameteriv"))) == nullptr || result;
    result = (glGenerateTextureMipmap_ptr = reinterpret_cast<glGenerateTextureMipmapPtr>(get_function("glGenerateTextureMipmap"))) == nullptr || result;
    result = (glBindTextureUnit_ptr = reinterpret_cast<glBindTextureUnitPtr>(get_function("glBindTextureUnit"))) == nullptr || result;
    result = (glGetTextureImage_ptr = reinterpret_cast<glGetTextureImagePtr>(get_function("glGetTextureImage"))) == nullptr || result;
    result = (glGetCompressedTextureImage_ptr = reinterpret_cast<glGetCompressedTextureImagePtr>(get_function("glGetCompressedTextureImage"))) == nullptr || result;
    result = (glGetTextureLevelParameterfv_ptr = reinterpret_cast<glGetTextureLevelParameterfvPtr>(get_function("glGetTextureLevelParameterfv"))) == nullptr || result;
    result = (glGetTextureLevelParameteriv_ptr = reinterpret_cast<glGetTextureLevelParameterivPtr>(get_function("glGetTextureLevelParameteriv"))) == nullptr || result;
    result = (glGetTextureParameterfv_ptr = reinterpret_cast<glGetTextureParameterfvPtr>(get_function("glGetTextureParameterfv"))) == nullptr || result;
    result = (glGetTextureParameterIiv_ptr = reinterpret_cast<glGetTextureParameterIivPtr>(get_function("glGetTextureParameterIiv"))) == nullptr || result;
    result = (glGetTextureParameterIuiv_ptr = reinterpret_cast<glGetTextureParameterIuivPtr>(get_function("glGetTextureParameterIuiv"))) == nullptr || result;
    result = (glGetTextureParameteriv_ptr = reinterpret_cast<glGetTextureParameterivPtr>(get_function("glGetTextureParameteriv"))) == nullptr || result;
    result = (glCreateVertexArrays_ptr = reinterpret_cast<glCreateVertexArraysPtr>(get_function("glCreateVertexArrays"))) == nullptr || result;
    result = (glDisableVertexArrayAttrib_ptr = reinterpret_cast<glDisableVertexArrayAttribPtr>(get_function("glDisableVertexArrayAttrib"))) == nullptr || result;
    result = (glEnableVertexArrayAttrib_ptr = reinterpret_cast<glEnableVertexArrayAttribPtr>(get_function("glEnableVertexArrayAttrib"))) == nullptr || result;
    result = (glVertexArrayElementBuffer_ptr = reinterpret_cast<glVertexArrayElementBufferPtr>(get_function("glVertexArrayElementBuffer"))) == nullptr || result;
    result = (glVertexArrayVertexBuffer_ptr = reinterpret_cast<glVertexArrayVertexBufferPtr>(get_function("glVertexArrayVertexBuffer"))) == nullptr || result;
    result = (glVertexArrayVertexBuffers_ptr = reinterpret_cast<glVertexArrayVertexBuffersPtr>(get_function("glVertexArrayVertexBuffers"))) == nullptr || result;
    result = (glVertexArrayAttribBinding_ptr = reinterpret_cast<glVertexArrayAttribBindingPtr>(get_function("glVertexArrayAttribBinding"))) == nullptr || result;
    result = (glVertexArrayAttribFormat_ptr = reinterpret_cast<glVertexArrayAttribFormatPtr>(get_function("glVertexArrayAttribFormat"))) == nullptr || result;
    result = (glVertexArrayAttribIFormat_ptr = reinterpret_cast<glVertexArrayAttribIFormatPtr>(get_function("glVertexArrayAttribIFormat"))) == nullptr || result;
    result = (glVertexArrayAttribLFormat_ptr = reinterpret_cast<glVertexArrayAttribLFormatPtr>(get_function("glVertexArrayAttribLFormat"))) == nullptr || result;
    result = (glVertexArrayBindingDivisor_ptr = reinterpret_cast<glVertexArrayBindingDivisorPtr>(get_function("glVertexArrayBindingDivisor"))) == nullptr || result;
    result = (glGetVertexArrayiv_ptr = reinterpret_cast<glGetVertexArrayivPtr>(get_function("glGetVertexArrayiv"))) == nullptr || result;
    result = (glGetVertexArrayIndexediv_ptr = reinterpret_cast<glGetVertexArrayIndexedivPtr>(get_function("glGetVertexArrayIndexediv"))) == nullptr || result;
    result = (glGetVertexArrayIndexed64iv_ptr = reinterpret_cast<glGetVertexArrayIndexed64ivPtr>(get_function("glGetVertexArrayIndexed64iv"))) == nullptr || result;
    result = (glCreateSamplers_ptr = reinterpret_cast<glCreateSamplersPtr>(get_function("glCreateSamplers"))) == nullptr || result;
    result = (glCreateProgramPipelines_ptr = reinterpret_cast<glCreateProgramPipelinesPtr>(get_function("glCreateProgramPipelines"))) == nullptr || result;
    result = (glCreateQueries_ptr = reinterpret_cast<glCreateQueriesPtr>(get_function("glCreateQueries"))) == nullptr || result;
    result = (glGetQueryBufferObjecti64v_ptr = reinterpret_cast<glGetQueryBufferObjecti64vPtr>(get_function("glGetQueryBufferObjecti64v"))) == nullptr || result;
    result = (glGetQueryBufferObjectiv_ptr = reinterpret_cast<glGetQueryBufferObjectivPtr>(get_function("glGetQueryBufferObjectiv"))) == nullptr || result;
    result = (glGetQueryBufferObjectui64v_ptr = reinterpret_cast<glGetQueryBufferObjectui64vPtr>(get_function("glGetQueryBufferObjectui64v"))) == nullptr || result;
    result = (glGetQueryBufferObjectuiv_ptr = reinterpret_cast<glGetQueryBufferObjectuivPtr>(get_function("glGetQueryBufferObjectuiv"))) == nullptr || result;
    result = (glMemoryBarrierByRegion_ptr = reinterpret_cast<glMemoryBarrierByRegionPtr>(get_function("glMemoryBarrierByRegion"))) == nullptr || result;
    result = (glGetTextureSubImage_ptr = reinterpret_cast<glGetTextureSubImagePtr>(get_function("glGetTextureSubImage"))) == nullptr || result;
    result = (glGetCompressedTextureSubImage_ptr = reinterpret_cast<glGetCompressedTextureSubImagePtr>(get_function("glGetCompressedTextureSubImage"))) == nullptr || result;
    result = (glGetGraphicsResetStatus_ptr = reinterpret_cast<glGetGraphicsResetStatusPtr>(get_function("glGetGraphicsResetStatus"))) == nullptr || result;
    result = (glGetnCompressedTexImage_ptr = reinterpret_cast<glGetnCompressedTexImagePtr>(get_function("glGetnCompressedTexImage"))) == nullptr || result;
    result = (glGetnTexImage_ptr = reinterpret_cast<glGetnTexImagePtr>(get_function("glGetnTexImage"))) == nullptr || result;
    result = (glGetnUniformdv_ptr = reinterpret_cast<glGetnUniformdvPtr>(get_function("glGetnUniformdv"))) == nullptr || result;
    result = (glGetnUniformfv_ptr = reinterpret_cast<glGetnUniformfvPtr>(get_function("glGetnUniformfv"))) == nullptr || result;
    result = (glGetnUniformiv_ptr = reinterpret_cast<glGetnUniformivPtr>(get_function("glGetnUniformiv"))) == nullptr || result;
    result = (glGetnUniformuiv_ptr = reinterpret_cast<glGetnUniformuivPtr>(get_function("glGetnUniformuiv"))) == nullptr || result;
    result = (glReadnPixels_ptr = reinterpret_cast<glReadnPixelsPtr>(get_function("glReadnPixels"))) == nullptr || result;
    result = (glTextureBarrier_ptr = reinterpret_cast<glTextureBarrierPtr>(get_function("glTextureBarrier"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_VERSION_4_6

using glSpecializeShaderPtr               = std::add_pointer_t<decltype(glSpecializeShader)>;
using glMultiDrawArraysIndirectCountPtr   = std::add_pointer_t<decltype(glMultiDrawArraysIndirectCount)>;
using glMultiDrawElementsIndirectCountPtr = std::add_pointer_t<decltype(glMultiDrawElementsIndirectCount)>;
using glPolygonOffsetClampPtr             = std::add_pointer_t<decltype(glPolygonOffsetClamp)>;

glSpecializeShaderPtr glSpecializeShader_ptr                             = nullptr;
glMultiDrawArraysIndirectCountPtr glMultiDrawArraysIndirectCount_ptr     = nullptr;
glMultiDrawElementsIndirectCountPtr glMultiDrawElementsIndirectCount_ptr = nullptr;
glPolygonOffsetClampPtr glPolygonOffsetClamp_ptr                         = nullptr;

bool init_gl_version_4_6([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glSpecializeShader_ptr = reinterpret_cast<glSpecializeShaderPtr>(get_function("glSpecializeShader"))) == nullptr || result;
    result = (glMultiDrawArraysIndirectCount_ptr = reinterpret_cast<glMultiDrawArraysIndirectCountPtr>(get_function("glMultiDrawArraysIndirectCount"))) == nullptr || result;
    result = (glMultiDrawElementsIndirectCount_ptr = reinterpret_cast<glMultiDrawElementsIndirectCountPtr>(get_function("glMultiDrawElementsIndirectCount"))) == nullptr || result;
    result = (glPolygonOffsetClamp_ptr = reinterpret_cast<glPolygonOffsetClampPtr>(get_function("glPolygonOffsetClamp"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_AMD_framebuffer_multisample_advanced

using glRenderbufferStorageMultisampleAdvancedAMDPtr = std::add_pointer_t<
decltype(glRenderbufferStorageMultisampleAdvancedAMD)>;
using glNamedRenderbufferStorageMultisampleAdvancedAMDPtr = std::add_pointer_t<
decltype(glNamedRenderbufferStorageMultisampleAdvancedAMD)>;

glRenderbufferStorageMultisampleAdvancedAMDPtr glRenderbufferStorageMultisampleAdvancedAMD_ptr           = nullptr;
glNamedRenderbufferStorageMultisampleAdvancedAMDPtr glNamedRenderbufferStorageMultisampleAdvancedAMD_ptr = nullptr;

bool init_gl_amd_framebuffer_multisample_advanced([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glRenderbufferStorageMultisampleAdvancedAMD_ptr = reinterpret_cast<glRenderbufferStorageMultisampleAdvancedAMDPtr>(get_function("glRenderbufferStorageMultisampleAdvancedAMD"))) == nullptr || result;
    result = (glNamedRenderbufferStorageMultisampleAdvancedAMD_ptr = reinterpret_cast<glNamedRenderbufferStorageMultisampleAdvancedAMDPtr>(get_function("glNamedRenderbufferStorageMultisampleAdvancedAMD"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_AMD_performance_monitor

using glGetPerfMonitorGroupsAMDPtr        = std::add_pointer_t<decltype(glGetPerfMonitorGroupsAMD)>;
using glGetPerfMonitorCountersAMDPtr      = std::add_pointer_t<decltype(glGetPerfMonitorCountersAMD)>;
using glGetPerfMonitorGroupStringAMDPtr   = std::add_pointer_t<decltype(glGetPerfMonitorGroupStringAMD)>;
using glGetPerfMonitorCounterStringAMDPtr = std::add_pointer_t<decltype(glGetPerfMonitorCounterStringAMD)>;
using glGetPerfMonitorCounterInfoAMDPtr   = std::add_pointer_t<decltype(glGetPerfMonitorCounterInfoAMD)>;
using glGenPerfMonitorsAMDPtr             = std::add_pointer_t<decltype(glGenPerfMonitorsAMD)>;
using glDeletePerfMonitorsAMDPtr          = std::add_pointer_t<decltype(glDeletePerfMonitorsAMD)>;
using glSelectPerfMonitorCountersAMDPtr   = std::add_pointer_t<decltype(glSelectPerfMonitorCountersAMD)>;
using glBeginPerfMonitorAMDPtr            = std::add_pointer_t<decltype(glBeginPerfMonitorAMD)>;
using glEndPerfMonitorAMDPtr              = std::add_pointer_t<decltype(glEndPerfMonitorAMD)>;
using glGetPerfMonitorCounterDataAMDPtr   = std::add_pointer_t<decltype(glGetPerfMonitorCounterDataAMD)>;

glGetPerfMonitorGroupsAMDPtr glGetPerfMonitorGroupsAMD_ptr               = nullptr;
glGetPerfMonitorCountersAMDPtr glGetPerfMonitorCountersAMD_ptr           = nullptr;
glGetPerfMonitorGroupStringAMDPtr glGetPerfMonitorGroupStringAMD_ptr     = nullptr;
glGetPerfMonitorCounterStringAMDPtr glGetPerfMonitorCounterStringAMD_ptr = nullptr;
glGetPerfMonitorCounterInfoAMDPtr glGetPerfMonitorCounterInfoAMD_ptr     = nullptr;
glGenPerfMonitorsAMDPtr glGenPerfMonitorsAMD_ptr                         = nullptr;
glDeletePerfMonitorsAMDPtr glDeletePerfMonitorsAMD_ptr                   = nullptr;
glSelectPerfMonitorCountersAMDPtr glSelectPerfMonitorCountersAMD_ptr     = nullptr;
glBeginPerfMonitorAMDPtr glBeginPerfMonitorAMD_ptr                       = nullptr;
glEndPerfMonitorAMDPtr glEndPerfMonitorAMD_ptr                           = nullptr;
glGetPerfMonitorCounterDataAMDPtr glGetPerfMonitorCounterDataAMD_ptr     = nullptr;

bool init_gl_amd_performance_monitor([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glGetPerfMonitorGroupsAMD_ptr = reinterpret_cast<glGetPerfMonitorGroupsAMDPtr>(get_function("glGetPerfMonitorGroupsAMD"))) == nullptr || result;
    result = (glGetPerfMonitorCountersAMD_ptr = reinterpret_cast<glGetPerfMonitorCountersAMDPtr>(get_function("glGetPerfMonitorCountersAMD"))) == nullptr || result;
    result = (glGetPerfMonitorGroupStringAMD_ptr = reinterpret_cast<glGetPerfMonitorGroupStringAMDPtr>(get_function("glGetPerfMonitorGroupStringAMD"))) == nullptr || result;
    result = (glGetPerfMonitorCounterStringAMD_ptr = reinterpret_cast<glGetPerfMonitorCounterStringAMDPtr>(get_function("glGetPerfMonitorCounterStringAMD"))) == nullptr || result;
    result = (glGetPerfMonitorCounterInfoAMD_ptr = reinterpret_cast<glGetPerfMonitorCounterInfoAMDPtr>(get_function("glGetPerfMonitorCounterInfoAMD"))) == nullptr || result;
    result = (glGenPerfMonitorsAMD_ptr = reinterpret_cast<glGenPerfMonitorsAMDPtr>(get_function("glGenPerfMonitorsAMD"))) == nullptr || result;
    result = (glDeletePerfMonitorsAMD_ptr = reinterpret_cast<glDeletePerfMonitorsAMDPtr>(get_function("glDeletePerfMonitorsAMD"))) == nullptr || result;
    result = (glSelectPerfMonitorCountersAMD_ptr = reinterpret_cast<glSelectPerfMonitorCountersAMDPtr>(get_function("glSelectPerfMonitorCountersAMD"))) == nullptr || result;
    result = (glBeginPerfMonitorAMD_ptr = reinterpret_cast<glBeginPerfMonitorAMDPtr>(get_function("glBeginPerfMonitorAMD"))) == nullptr || result;
    result = (glEndPerfMonitorAMD_ptr = reinterpret_cast<glEndPerfMonitorAMDPtr>(get_function("glEndPerfMonitorAMD"))) == nullptr || result;
    result = (glGetPerfMonitorCounterDataAMD_ptr = reinterpret_cast<glGetPerfMonitorCounterDataAMDPtr>(get_function("glGetPerfMonitorCounterDataAMD"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_APPLE_rgb_422

bool init_gl_apple_rgb_422([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_ES2_compatibility

bool init_gl_arb_es2_compatibility([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_ES3_1_compatibility

bool init_gl_arb_es3_1_compatibility([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_ES3_2_compatibility

using glPrimitiveBoundingBoxARBPtr = std::add_pointer_t<decltype(glPrimitiveBoundingBoxARB)>;

glPrimitiveBoundingBoxARBPtr glPrimitiveBoundingBoxARB_ptr = nullptr;

bool init_gl_arb_es3_2_compatibility([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glPrimitiveBoundingBoxARB_ptr = reinterpret_cast<glPrimitiveBoundingBoxARBPtr>(get_function("glPrimitiveBoundingBoxARB"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_ARB_ES3_compatibility

bool init_gl_arb_es3_compatibility([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_arrays_of_arrays

bool init_gl_arb_arrays_of_arrays([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_base_instance

bool init_gl_arb_base_instance([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_bindless_texture

using glGetTextureHandleARBPtr             = std::add_pointer_t<decltype(glGetTextureHandleARB)>;
using glGetTextureSamplerHandleARBPtr      = std::add_pointer_t<decltype(glGetTextureSamplerHandleARB)>;
using glMakeTextureHandleResidentARBPtr    = std::add_pointer_t<decltype(glMakeTextureHandleResidentARB)>;
using glMakeTextureHandleNonResidentARBPtr = std::add_pointer_t<decltype(glMakeTextureHandleNonResidentARB)>;
using glGetImageHandleARBPtr               = std::add_pointer_t<decltype(glGetImageHandleARB)>;
using glMakeImageHandleResidentARBPtr      = std::add_pointer_t<decltype(glMakeImageHandleResidentARB)>;
using glMakeImageHandleNonResidentARBPtr   = std::add_pointer_t<decltype(glMakeImageHandleNonResidentARB)>;
using glUniformHandleui64ARBPtr            = std::add_pointer_t<decltype(glUniformHandleui64ARB)>;
using glUniformHandleui64vARBPtr           = std::add_pointer_t<decltype(glUniformHandleui64vARB)>;
using glProgramUniformHandleui64ARBPtr     = std::add_pointer_t<decltype(glProgramUniformHandleui64ARB)>;
using glProgramUniformHandleui64vARBPtr    = std::add_pointer_t<decltype(glProgramUniformHandleui64vARB)>;
using glIsTextureHandleResidentARBPtr      = std::add_pointer_t<decltype(glIsTextureHandleResidentARB)>;
using glIsImageHandleResidentARBPtr        = std::add_pointer_t<decltype(glIsImageHandleResidentARB)>;
using glVertexAttribL1ui64ARBPtr           = std::add_pointer_t<decltype(glVertexAttribL1ui64ARB)>;
using glVertexAttribL1ui64vARBPtr          = std::add_pointer_t<decltype(glVertexAttribL1ui64vARB)>;
using glGetVertexAttribLui64vARBPtr        = std::add_pointer_t<decltype(glGetVertexAttribLui64vARB)>;

glGetTextureHandleARBPtr glGetTextureHandleARB_ptr                         = nullptr;
glGetTextureSamplerHandleARBPtr glGetTextureSamplerHandleARB_ptr           = nullptr;
glMakeTextureHandleResidentARBPtr glMakeTextureHandleResidentARB_ptr       = nullptr;
glMakeTextureHandleNonResidentARBPtr glMakeTextureHandleNonResidentARB_ptr = nullptr;
glGetImageHandleARBPtr glGetImageHandleARB_ptr                             = nullptr;
glMakeImageHandleResidentARBPtr glMakeImageHandleResidentARB_ptr           = nullptr;
glMakeImageHandleNonResidentARBPtr glMakeImageHandleNonResidentARB_ptr     = nullptr;
glUniformHandleui64ARBPtr glUniformHandleui64ARB_ptr                       = nullptr;
glUniformHandleui64vARBPtr glUniformHandleui64vARB_ptr                     = nullptr;
glProgramUniformHandleui64ARBPtr glProgramUniformHandleui64ARB_ptr         = nullptr;
glProgramUniformHandleui64vARBPtr glProgramUniformHandleui64vARB_ptr       = nullptr;
glIsTextureHandleResidentARBPtr glIsTextureHandleResidentARB_ptr           = nullptr;
glIsImageHandleResidentARBPtr glIsImageHandleResidentARB_ptr               = nullptr;
glVertexAttribL1ui64ARBPtr glVertexAttribL1ui64ARB_ptr                     = nullptr;
glVertexAttribL1ui64vARBPtr glVertexAttribL1ui64vARB_ptr                   = nullptr;
glGetVertexAttribLui64vARBPtr glGetVertexAttribLui64vARB_ptr               = nullptr;

bool init_gl_arb_bindless_texture([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glGetTextureHandleARB_ptr = reinterpret_cast<glGetTextureHandleARBPtr>(get_function("glGetTextureHandleARB"))) == nullptr || result;
    result = (glGetTextureSamplerHandleARB_ptr = reinterpret_cast<glGetTextureSamplerHandleARBPtr>(get_function("glGetTextureSamplerHandleARB"))) == nullptr || result;
    result = (glMakeTextureHandleResidentARB_ptr = reinterpret_cast<glMakeTextureHandleResidentARBPtr>(get_function("glMakeTextureHandleResidentARB"))) == nullptr || result;
    result = (glMakeTextureHandleNonResidentARB_ptr = reinterpret_cast<glMakeTextureHandleNonResidentARBPtr>(get_function("glMakeTextureHandleNonResidentARB"))) == nullptr || result;
    result = (glGetImageHandleARB_ptr = reinterpret_cast<glGetImageHandleARBPtr>(get_function("glGetImageHandleARB"))) == nullptr || result;
    result = (glMakeImageHandleResidentARB_ptr = reinterpret_cast<glMakeImageHandleResidentARBPtr>(get_function("glMakeImageHandleResidentARB"))) == nullptr || result;
    result = (glMakeImageHandleNonResidentARB_ptr = reinterpret_cast<glMakeImageHandleNonResidentARBPtr>(get_function("glMakeImageHandleNonResidentARB"))) == nullptr || result;
    result = (glUniformHandleui64ARB_ptr = reinterpret_cast<glUniformHandleui64ARBPtr>(get_function("glUniformHandleui64ARB"))) == nullptr || result;
    result = (glUniformHandleui64vARB_ptr = reinterpret_cast<glUniformHandleui64vARBPtr>(get_function("glUniformHandleui64vARB"))) == nullptr || result;
    result = (glProgramUniformHandleui64ARB_ptr = reinterpret_cast<glProgramUniformHandleui64ARBPtr>(get_function("glProgramUniformHandleui64ARB"))) == nullptr || result;
    result = (glProgramUniformHandleui64vARB_ptr = reinterpret_cast<glProgramUniformHandleui64vARBPtr>(get_function("glProgramUniformHandleui64vARB"))) == nullptr || result;
    result = (glIsTextureHandleResidentARB_ptr = reinterpret_cast<glIsTextureHandleResidentARBPtr>(get_function("glIsTextureHandleResidentARB"))) == nullptr || result;
    result = (glIsImageHandleResidentARB_ptr = reinterpret_cast<glIsImageHandleResidentARBPtr>(get_function("glIsImageHandleResidentARB"))) == nullptr || result;
    result = (glVertexAttribL1ui64ARB_ptr = reinterpret_cast<glVertexAttribL1ui64ARBPtr>(get_function("glVertexAttribL1ui64ARB"))) == nullptr || result;
    result = (glVertexAttribL1ui64vARB_ptr = reinterpret_cast<glVertexAttribL1ui64vARBPtr>(get_function("glVertexAttribL1ui64vARB"))) == nullptr || result;
    result = (glGetVertexAttribLui64vARB_ptr = reinterpret_cast<glGetVertexAttribLui64vARBPtr>(get_function("glGetVertexAttribLui64vARB"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_ARB_blend_func_extended

bool init_gl_arb_blend_func_extended([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_buffer_storage

bool init_gl_arb_buffer_storage([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_cl_event

using glCreateSyncFromCLeventARBPtr = std::add_pointer_t<decltype(glCreateSyncFromCLeventARB)>;

glCreateSyncFromCLeventARBPtr glCreateSyncFromCLeventARB_ptr = nullptr;

bool init_gl_arb_cl_event([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glCreateSyncFromCLeventARB_ptr = reinterpret_cast<glCreateSyncFromCLeventARBPtr>(get_function("glCreateSyncFromCLeventARB"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_ARB_clear_buffer_object

bool init_gl_arb_clear_buffer_object([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_clear_texture

bool init_gl_arb_clear_texture([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_clip_control

bool init_gl_arb_clip_control([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_compressed_texture_pixel_storage

bool init_gl_arb_compressed_texture_pixel_storage([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_compute_shader

bool init_gl_arb_compute_shader([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_compute_variable_group_size

using glDispatchComputeGroupSizeARBPtr = std::add_pointer_t<decltype(glDispatchComputeGroupSizeARB)>;

glDispatchComputeGroupSizeARBPtr glDispatchComputeGroupSizeARB_ptr = nullptr;

bool init_gl_arb_compute_variable_group_size([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glDispatchComputeGroupSizeARB_ptr = reinterpret_cast<glDispatchComputeGroupSizeARBPtr>(get_function("glDispatchComputeGroupSizeARB"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_ARB_conditional_render_inverted

bool init_gl_arb_conditional_render_inverted([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_conservative_depth

bool init_gl_arb_conservative_depth([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_copy_buffer

bool init_gl_arb_copy_buffer([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_copy_image

bool init_gl_arb_copy_image([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_cull_distance

bool init_gl_arb_cull_distance([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_debug_output

using glDebugMessageControlARBPtr  = std::add_pointer_t<decltype(glDebugMessageControlARB)>;
using glDebugMessageInsertARBPtr   = std::add_pointer_t<decltype(glDebugMessageInsertARB)>;
using glDebugMessageCallbackARBPtr = std::add_pointer_t<decltype(glDebugMessageCallbackARB)>;
using glGetDebugMessageLogARBPtr   = std::add_pointer_t<decltype(glGetDebugMessageLogARB)>;

glDebugMessageControlARBPtr glDebugMessageControlARB_ptr   = nullptr;
glDebugMessageInsertARBPtr glDebugMessageInsertARB_ptr     = nullptr;
glDebugMessageCallbackARBPtr glDebugMessageCallbackARB_ptr = nullptr;
glGetDebugMessageLogARBPtr glGetDebugMessageLogARB_ptr     = nullptr;

bool init_gl_arb_debug_output([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glDebugMessageControlARB_ptr = reinterpret_cast<glDebugMessageControlARBPtr>(get_function("glDebugMessageControlARB"))) == nullptr || result;
    result = (glDebugMessageInsertARB_ptr = reinterpret_cast<glDebugMessageInsertARBPtr>(get_function("glDebugMessageInsertARB"))) == nullptr || result;
    result = (glDebugMessageCallbackARB_ptr = reinterpret_cast<glDebugMessageCallbackARBPtr>(get_function("glDebugMessageCallbackARB"))) == nullptr || result;
    result = (glGetDebugMessageLogARB_ptr = reinterpret_cast<glGetDebugMessageLogARBPtr>(get_function("glGetDebugMessageLogARB"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_ARB_depth_buffer_float

bool init_gl_arb_depth_buffer_float([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_depth_clamp

bool init_gl_arb_depth_clamp([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_derivative_control

bool init_gl_arb_derivative_control([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_direct_state_access

bool init_gl_arb_direct_state_access([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_draw_buffers_blend

using glBlendEquationiARBPtr         = std::add_pointer_t<decltype(glBlendEquationiARB)>;
using glBlendEquationSeparateiARBPtr = std::add_pointer_t<decltype(glBlendEquationSeparateiARB)>;
using glBlendFunciARBPtr             = std::add_pointer_t<decltype(glBlendFunciARB)>;
using glBlendFuncSeparateiARBPtr     = std::add_pointer_t<decltype(glBlendFuncSeparateiARB)>;

glBlendEquationiARBPtr glBlendEquationiARB_ptr                 = nullptr;
glBlendEquationSeparateiARBPtr glBlendEquationSeparateiARB_ptr = nullptr;
glBlendFunciARBPtr glBlendFunciARB_ptr                         = nullptr;
glBlendFuncSeparateiARBPtr glBlendFuncSeparateiARB_ptr         = nullptr;

bool init_gl_arb_draw_buffers_blend([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glBlendEquationiARB_ptr = reinterpret_cast<glBlendEquationiARBPtr>(get_function("glBlendEquationiARB"))) == nullptr || result;
    result = (glBlendEquationSeparateiARB_ptr = reinterpret_cast<glBlendEquationSeparateiARBPtr>(get_function("glBlendEquationSeparateiARB"))) == nullptr || result;
    result = (glBlendFunciARB_ptr = reinterpret_cast<glBlendFunciARBPtr>(get_function("glBlendFunciARB"))) == nullptr || result;
    result = (glBlendFuncSeparateiARB_ptr = reinterpret_cast<glBlendFuncSeparateiARBPtr>(get_function("glBlendFuncSeparateiARB"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_ARB_draw_elements_base_vertex

bool init_gl_arb_draw_elements_base_vertex([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_draw_indirect

bool init_gl_arb_draw_indirect([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_draw_instanced

using glDrawArraysInstancedARBPtr   = std::add_pointer_t<decltype(glDrawArraysInstancedARB)>;
using glDrawElementsInstancedARBPtr = std::add_pointer_t<decltype(glDrawElementsInstancedARB)>;

glDrawArraysInstancedARBPtr glDrawArraysInstancedARB_ptr     = nullptr;
glDrawElementsInstancedARBPtr glDrawElementsInstancedARB_ptr = nullptr;

bool init_gl_arb_draw_instanced([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glDrawArraysInstancedARB_ptr = reinterpret_cast<glDrawArraysInstancedARBPtr>(get_function("glDrawArraysInstancedARB"))) == nullptr || result;
    result = (glDrawElementsInstancedARB_ptr = reinterpret_cast<glDrawElementsInstancedARBPtr>(get_function("glDrawElementsInstancedARB"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_ARB_enhanced_layouts

bool init_gl_arb_enhanced_layouts([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_explicit_attrib_location

bool init_gl_arb_explicit_attrib_location([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_explicit_uniform_location

bool init_gl_arb_explicit_uniform_location([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_fragment_coord_conventions

bool init_gl_arb_fragment_coord_conventions([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_fragment_layer_viewport

bool init_gl_arb_fragment_layer_viewport([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_fragment_shader_interlock

bool init_gl_arb_fragment_shader_interlock([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_framebuffer_no_attachments

bool init_gl_arb_framebuffer_no_attachments([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_framebuffer_object

bool init_gl_arb_framebuffer_object([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_framebuffer_sRGB

bool init_gl_arb_framebuffer_srgb([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_geometry_shader4

using glProgramParameteriARBPtr       = std::add_pointer_t<decltype(glProgramParameteriARB)>;
using glFramebufferTextureARBPtr      = std::add_pointer_t<decltype(glFramebufferTextureARB)>;
using glFramebufferTextureLayerARBPtr = std::add_pointer_t<decltype(glFramebufferTextureLayerARB)>;
using glFramebufferTextureFaceARBPtr  = std::add_pointer_t<decltype(glFramebufferTextureFaceARB)>;

glProgramParameteriARBPtr glProgramParameteriARB_ptr             = nullptr;
glFramebufferTextureARBPtr glFramebufferTextureARB_ptr           = nullptr;
glFramebufferTextureLayerARBPtr glFramebufferTextureLayerARB_ptr = nullptr;
glFramebufferTextureFaceARBPtr glFramebufferTextureFaceARB_ptr   = nullptr;

bool init_gl_arb_geometry_shader4([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glProgramParameteriARB_ptr = reinterpret_cast<glProgramParameteriARBPtr>(get_function("glProgramParameteriARB"))) == nullptr || result;
    result = (glFramebufferTextureARB_ptr = reinterpret_cast<glFramebufferTextureARBPtr>(get_function("glFramebufferTextureARB"))) == nullptr || result;
    result = (glFramebufferTextureLayerARB_ptr = reinterpret_cast<glFramebufferTextureLayerARBPtr>(get_function("glFramebufferTextureLayerARB"))) == nullptr || result;
    result = (glFramebufferTextureFaceARB_ptr = reinterpret_cast<glFramebufferTextureFaceARBPtr>(get_function("glFramebufferTextureFaceARB"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_ARB_get_program_binary

bool init_gl_arb_get_program_binary([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_get_texture_sub_image

bool init_gl_arb_get_texture_sub_image([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_gl_spirv

using glSpecializeShaderARBPtr = std::add_pointer_t<decltype(glSpecializeShaderARB)>;

glSpecializeShaderARBPtr glSpecializeShaderARB_ptr = nullptr;

bool init_gl_arb_gl_spirv([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glSpecializeShaderARB_ptr = reinterpret_cast<glSpecializeShaderARBPtr>(get_function("glSpecializeShaderARB"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_ARB_gpu_shader5

bool init_gl_arb_gpu_shader5([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_gpu_shader_fp64

bool init_gl_arb_gpu_shader_fp64([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_gpu_shader_int64

using glUniform1i64ARBPtr          = std::add_pointer_t<decltype(glUniform1i64ARB)>;
using glUniform2i64ARBPtr          = std::add_pointer_t<decltype(glUniform2i64ARB)>;
using glUniform3i64ARBPtr          = std::add_pointer_t<decltype(glUniform3i64ARB)>;
using glUniform4i64ARBPtr          = std::add_pointer_t<decltype(glUniform4i64ARB)>;
using glUniform1i64vARBPtr         = std::add_pointer_t<decltype(glUniform1i64vARB)>;
using glUniform2i64vARBPtr         = std::add_pointer_t<decltype(glUniform2i64vARB)>;
using glUniform3i64vARBPtr         = std::add_pointer_t<decltype(glUniform3i64vARB)>;
using glUniform4i64vARBPtr         = std::add_pointer_t<decltype(glUniform4i64vARB)>;
using glUniform1ui64ARBPtr         = std::add_pointer_t<decltype(glUniform1ui64ARB)>;
using glUniform2ui64ARBPtr         = std::add_pointer_t<decltype(glUniform2ui64ARB)>;
using glUniform3ui64ARBPtr         = std::add_pointer_t<decltype(glUniform3ui64ARB)>;
using glUniform4ui64ARBPtr         = std::add_pointer_t<decltype(glUniform4ui64ARB)>;
using glUniform1ui64vARBPtr        = std::add_pointer_t<decltype(glUniform1ui64vARB)>;
using glUniform2ui64vARBPtr        = std::add_pointer_t<decltype(glUniform2ui64vARB)>;
using glUniform3ui64vARBPtr        = std::add_pointer_t<decltype(glUniform3ui64vARB)>;
using glUniform4ui64vARBPtr        = std::add_pointer_t<decltype(glUniform4ui64vARB)>;
using glGetUniformi64vARBPtr       = std::add_pointer_t<decltype(glGetUniformi64vARB)>;
using glGetUniformui64vARBPtr      = std::add_pointer_t<decltype(glGetUniformui64vARB)>;
using glGetnUniformi64vARBPtr      = std::add_pointer_t<decltype(glGetnUniformi64vARB)>;
using glGetnUniformui64vARBPtr     = std::add_pointer_t<decltype(glGetnUniformui64vARB)>;
using glProgramUniform1i64ARBPtr   = std::add_pointer_t<decltype(glProgramUniform1i64ARB)>;
using glProgramUniform2i64ARBPtr   = std::add_pointer_t<decltype(glProgramUniform2i64ARB)>;
using glProgramUniform3i64ARBPtr   = std::add_pointer_t<decltype(glProgramUniform3i64ARB)>;
using glProgramUniform4i64ARBPtr   = std::add_pointer_t<decltype(glProgramUniform4i64ARB)>;
using glProgramUniform1i64vARBPtr  = std::add_pointer_t<decltype(glProgramUniform1i64vARB)>;
using glProgramUniform2i64vARBPtr  = std::add_pointer_t<decltype(glProgramUniform2i64vARB)>;
using glProgramUniform3i64vARBPtr  = std::add_pointer_t<decltype(glProgramUniform3i64vARB)>;
using glProgramUniform4i64vARBPtr  = std::add_pointer_t<decltype(glProgramUniform4i64vARB)>;
using glProgramUniform1ui64ARBPtr  = std::add_pointer_t<decltype(glProgramUniform1ui64ARB)>;
using glProgramUniform2ui64ARBPtr  = std::add_pointer_t<decltype(glProgramUniform2ui64ARB)>;
using glProgramUniform3ui64ARBPtr  = std::add_pointer_t<decltype(glProgramUniform3ui64ARB)>;
using glProgramUniform4ui64ARBPtr  = std::add_pointer_t<decltype(glProgramUniform4ui64ARB)>;
using glProgramUniform1ui64vARBPtr = std::add_pointer_t<decltype(glProgramUniform1ui64vARB)>;
using glProgramUniform2ui64vARBPtr = std::add_pointer_t<decltype(glProgramUniform2ui64vARB)>;
using glProgramUniform3ui64vARBPtr = std::add_pointer_t<decltype(glProgramUniform3ui64vARB)>;
using glProgramUniform4ui64vARBPtr = std::add_pointer_t<decltype(glProgramUniform4ui64vARB)>;

glUniform1i64ARBPtr glUniform1i64ARB_ptr                   = nullptr;
glUniform2i64ARBPtr glUniform2i64ARB_ptr                   = nullptr;
glUniform3i64ARBPtr glUniform3i64ARB_ptr                   = nullptr;
glUniform4i64ARBPtr glUniform4i64ARB_ptr                   = nullptr;
glUniform1i64vARBPtr glUniform1i64vARB_ptr                 = nullptr;
glUniform2i64vARBPtr glUniform2i64vARB_ptr                 = nullptr;
glUniform3i64vARBPtr glUniform3i64vARB_ptr                 = nullptr;
glUniform4i64vARBPtr glUniform4i64vARB_ptr                 = nullptr;
glUniform1ui64ARBPtr glUniform1ui64ARB_ptr                 = nullptr;
glUniform2ui64ARBPtr glUniform2ui64ARB_ptr                 = nullptr;
glUniform3ui64ARBPtr glUniform3ui64ARB_ptr                 = nullptr;
glUniform4ui64ARBPtr glUniform4ui64ARB_ptr                 = nullptr;
glUniform1ui64vARBPtr glUniform1ui64vARB_ptr               = nullptr;
glUniform2ui64vARBPtr glUniform2ui64vARB_ptr               = nullptr;
glUniform3ui64vARBPtr glUniform3ui64vARB_ptr               = nullptr;
glUniform4ui64vARBPtr glUniform4ui64vARB_ptr               = nullptr;
glGetUniformi64vARBPtr glGetUniformi64vARB_ptr             = nullptr;
glGetUniformui64vARBPtr glGetUniformui64vARB_ptr           = nullptr;
glGetnUniformi64vARBPtr glGetnUniformi64vARB_ptr           = nullptr;
glGetnUniformui64vARBPtr glGetnUniformui64vARB_ptr         = nullptr;
glProgramUniform1i64ARBPtr glProgramUniform1i64ARB_ptr     = nullptr;
glProgramUniform2i64ARBPtr glProgramUniform2i64ARB_ptr     = nullptr;
glProgramUniform3i64ARBPtr glProgramUniform3i64ARB_ptr     = nullptr;
glProgramUniform4i64ARBPtr glProgramUniform4i64ARB_ptr     = nullptr;
glProgramUniform1i64vARBPtr glProgramUniform1i64vARB_ptr   = nullptr;
glProgramUniform2i64vARBPtr glProgramUniform2i64vARB_ptr   = nullptr;
glProgramUniform3i64vARBPtr glProgramUniform3i64vARB_ptr   = nullptr;
glProgramUniform4i64vARBPtr glProgramUniform4i64vARB_ptr   = nullptr;
glProgramUniform1ui64ARBPtr glProgramUniform1ui64ARB_ptr   = nullptr;
glProgramUniform2ui64ARBPtr glProgramUniform2ui64ARB_ptr   = nullptr;
glProgramUniform3ui64ARBPtr glProgramUniform3ui64ARB_ptr   = nullptr;
glProgramUniform4ui64ARBPtr glProgramUniform4ui64ARB_ptr   = nullptr;
glProgramUniform1ui64vARBPtr glProgramUniform1ui64vARB_ptr = nullptr;
glProgramUniform2ui64vARBPtr glProgramUniform2ui64vARB_ptr = nullptr;
glProgramUniform3ui64vARBPtr glProgramUniform3ui64vARB_ptr = nullptr;
glProgramUniform4ui64vARBPtr glProgramUniform4ui64vARB_ptr = nullptr;

bool init_gl_arb_gpu_shader_int64([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glUniform1i64ARB_ptr = reinterpret_cast<glUniform1i64ARBPtr>(get_function("glUniform1i64ARB"))) == nullptr || result;
    result = (glUniform2i64ARB_ptr = reinterpret_cast<glUniform2i64ARBPtr>(get_function("glUniform2i64ARB"))) == nullptr || result;
    result = (glUniform3i64ARB_ptr = reinterpret_cast<glUniform3i64ARBPtr>(get_function("glUniform3i64ARB"))) == nullptr || result;
    result = (glUniform4i64ARB_ptr = reinterpret_cast<glUniform4i64ARBPtr>(get_function("glUniform4i64ARB"))) == nullptr || result;
    result = (glUniform1i64vARB_ptr = reinterpret_cast<glUniform1i64vARBPtr>(get_function("glUniform1i64vARB"))) == nullptr || result;
    result = (glUniform2i64vARB_ptr = reinterpret_cast<glUniform2i64vARBPtr>(get_function("glUniform2i64vARB"))) == nullptr || result;
    result = (glUniform3i64vARB_ptr = reinterpret_cast<glUniform3i64vARBPtr>(get_function("glUniform3i64vARB"))) == nullptr || result;
    result = (glUniform4i64vARB_ptr = reinterpret_cast<glUniform4i64vARBPtr>(get_function("glUniform4i64vARB"))) == nullptr || result;
    result = (glUniform1ui64ARB_ptr = reinterpret_cast<glUniform1ui64ARBPtr>(get_function("glUniform1ui64ARB"))) == nullptr || result;
    result = (glUniform2ui64ARB_ptr = reinterpret_cast<glUniform2ui64ARBPtr>(get_function("glUniform2ui64ARB"))) == nullptr || result;
    result = (glUniform3ui64ARB_ptr = reinterpret_cast<glUniform3ui64ARBPtr>(get_function("glUniform3ui64ARB"))) == nullptr || result;
    result = (glUniform4ui64ARB_ptr = reinterpret_cast<glUniform4ui64ARBPtr>(get_function("glUniform4ui64ARB"))) == nullptr || result;
    result = (glUniform1ui64vARB_ptr = reinterpret_cast<glUniform1ui64vARBPtr>(get_function("glUniform1ui64vARB"))) == nullptr || result;
    result = (glUniform2ui64vARB_ptr = reinterpret_cast<glUniform2ui64vARBPtr>(get_function("glUniform2ui64vARB"))) == nullptr || result;
    result = (glUniform3ui64vARB_ptr = reinterpret_cast<glUniform3ui64vARBPtr>(get_function("glUniform3ui64vARB"))) == nullptr || result;
    result = (glUniform4ui64vARB_ptr = reinterpret_cast<glUniform4ui64vARBPtr>(get_function("glUniform4ui64vARB"))) == nullptr || result;
    result = (glGetUniformi64vARB_ptr = reinterpret_cast<glGetUniformi64vARBPtr>(get_function("glGetUniformi64vARB"))) == nullptr || result;
    result = (glGetUniformui64vARB_ptr = reinterpret_cast<glGetUniformui64vARBPtr>(get_function("glGetUniformui64vARB"))) == nullptr || result;
    result = (glGetnUniformi64vARB_ptr = reinterpret_cast<glGetnUniformi64vARBPtr>(get_function("glGetnUniformi64vARB"))) == nullptr || result;
    result = (glGetnUniformui64vARB_ptr = reinterpret_cast<glGetnUniformui64vARBPtr>(get_function("glGetnUniformui64vARB"))) == nullptr || result;
    result = (glProgramUniform1i64ARB_ptr = reinterpret_cast<glProgramUniform1i64ARBPtr>(get_function("glProgramUniform1i64ARB"))) == nullptr || result;
    result = (glProgramUniform2i64ARB_ptr = reinterpret_cast<glProgramUniform2i64ARBPtr>(get_function("glProgramUniform2i64ARB"))) == nullptr || result;
    result = (glProgramUniform3i64ARB_ptr = reinterpret_cast<glProgramUniform3i64ARBPtr>(get_function("glProgramUniform3i64ARB"))) == nullptr || result;
    result = (glProgramUniform4i64ARB_ptr = reinterpret_cast<glProgramUniform4i64ARBPtr>(get_function("glProgramUniform4i64ARB"))) == nullptr || result;
    result = (glProgramUniform1i64vARB_ptr = reinterpret_cast<glProgramUniform1i64vARBPtr>(get_function("glProgramUniform1i64vARB"))) == nullptr || result;
    result = (glProgramUniform2i64vARB_ptr = reinterpret_cast<glProgramUniform2i64vARBPtr>(get_function("glProgramUniform2i64vARB"))) == nullptr || result;
    result = (glProgramUniform3i64vARB_ptr = reinterpret_cast<glProgramUniform3i64vARBPtr>(get_function("glProgramUniform3i64vARB"))) == nullptr || result;
    result = (glProgramUniform4i64vARB_ptr = reinterpret_cast<glProgramUniform4i64vARBPtr>(get_function("glProgramUniform4i64vARB"))) == nullptr || result;
    result = (glProgramUniform1ui64ARB_ptr = reinterpret_cast<glProgramUniform1ui64ARBPtr>(get_function("glProgramUniform1ui64ARB"))) == nullptr || result;
    result = (glProgramUniform2ui64ARB_ptr = reinterpret_cast<glProgramUniform2ui64ARBPtr>(get_function("glProgramUniform2ui64ARB"))) == nullptr || result;
    result = (glProgramUniform3ui64ARB_ptr = reinterpret_cast<glProgramUniform3ui64ARBPtr>(get_function("glProgramUniform3ui64ARB"))) == nullptr || result;
    result = (glProgramUniform4ui64ARB_ptr = reinterpret_cast<glProgramUniform4ui64ARBPtr>(get_function("glProgramUniform4ui64ARB"))) == nullptr || result;
    result = (glProgramUniform1ui64vARB_ptr = reinterpret_cast<glProgramUniform1ui64vARBPtr>(get_function("glProgramUniform1ui64vARB"))) == nullptr || result;
    result = (glProgramUniform2ui64vARB_ptr = reinterpret_cast<glProgramUniform2ui64vARBPtr>(get_function("glProgramUniform2ui64vARB"))) == nullptr || result;
    result = (glProgramUniform3ui64vARB_ptr = reinterpret_cast<glProgramUniform3ui64vARBPtr>(get_function("glProgramUniform3ui64vARB"))) == nullptr || result;
    result = (glProgramUniform4ui64vARB_ptr = reinterpret_cast<glProgramUniform4ui64vARBPtr>(get_function("glProgramUniform4ui64vARB"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_ARB_half_float_vertex

bool init_gl_arb_half_float_vertex([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_imaging

bool init_gl_arb_imaging([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_indirect_parameters

using glMultiDrawArraysIndirectCountARBPtr   = std::add_pointer_t<decltype(glMultiDrawArraysIndirectCountARB)>;
using glMultiDrawElementsIndirectCountARBPtr = std::add_pointer_t<decltype(glMultiDrawElementsIndirectCountARB)>;

glMultiDrawArraysIndirectCountARBPtr glMultiDrawArraysIndirectCountARB_ptr     = nullptr;
glMultiDrawElementsIndirectCountARBPtr glMultiDrawElementsIndirectCountARB_ptr = nullptr;

bool init_gl_arb_indirect_parameters([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glMultiDrawArraysIndirectCountARB_ptr = reinterpret_cast<glMultiDrawArraysIndirectCountARBPtr>(get_function("glMultiDrawArraysIndirectCountARB"))) == nullptr || result;
    result = (glMultiDrawElementsIndirectCountARB_ptr = reinterpret_cast<glMultiDrawElementsIndirectCountARBPtr>(get_function("glMultiDrawElementsIndirectCountARB"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_ARB_instanced_arrays

using glVertexAttribDivisorARBPtr = std::add_pointer_t<decltype(glVertexAttribDivisorARB)>;

glVertexAttribDivisorARBPtr glVertexAttribDivisorARB_ptr = nullptr;

bool init_gl_arb_instanced_arrays([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glVertexAttribDivisorARB_ptr = reinterpret_cast<glVertexAttribDivisorARBPtr>(get_function("glVertexAttribDivisorARB"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_ARB_internalformat_query

bool init_gl_arb_internalformat_query([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_internalformat_query2

bool init_gl_arb_internalformat_query2([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_invalidate_subdata

bool init_gl_arb_invalidate_subdata([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_map_buffer_alignment

bool init_gl_arb_map_buffer_alignment([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_map_buffer_range

bool init_gl_arb_map_buffer_range([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_multi_bind

bool init_gl_arb_multi_bind([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_multi_draw_indirect

bool init_gl_arb_multi_draw_indirect([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_occlusion_query2

bool init_gl_arb_occlusion_query2([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_parallel_shader_compile

using glMaxShaderCompilerThreadsARBPtr = std::add_pointer_t<decltype(glMaxShaderCompilerThreadsARB)>;

glMaxShaderCompilerThreadsARBPtr glMaxShaderCompilerThreadsARB_ptr = nullptr;

bool init_gl_arb_parallel_shader_compile([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glMaxShaderCompilerThreadsARB_ptr = reinterpret_cast<glMaxShaderCompilerThreadsARBPtr>(get_function("glMaxShaderCompilerThreadsARB"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_ARB_pipeline_statistics_query

bool init_gl_arb_pipeline_statistics_query([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_pixel_buffer_object

bool init_gl_arb_pixel_buffer_object([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_polygon_offset_clamp

bool init_gl_arb_polygon_offset_clamp([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_post_depth_coverage

bool init_gl_arb_post_depth_coverage([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_program_interface_query

bool init_gl_arb_program_interface_query([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_provoking_vertex

bool init_gl_arb_provoking_vertex([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_query_buffer_object

bool init_gl_arb_query_buffer_object([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_robust_buffer_access_behavior

bool init_gl_arb_robust_buffer_access_behavior([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_robustness

using glGetGraphicsResetStatusARBPtr = std::add_pointer_t<decltype(glGetGraphicsResetStatusARB)>;
using glGetnTexImageARBPtr           = std::add_pointer_t<decltype(glGetnTexImageARB)>;
using glReadnPixelsARBPtr            = std::add_pointer_t<decltype(glReadnPixelsARB)>;
using glGetnCompressedTexImageARBPtr = std::add_pointer_t<decltype(glGetnCompressedTexImageARB)>;
using glGetnUniformfvARBPtr          = std::add_pointer_t<decltype(glGetnUniformfvARB)>;
using glGetnUniformivARBPtr          = std::add_pointer_t<decltype(glGetnUniformivARB)>;
using glGetnUniformuivARBPtr         = std::add_pointer_t<decltype(glGetnUniformuivARB)>;
using glGetnUniformdvARBPtr          = std::add_pointer_t<decltype(glGetnUniformdvARB)>;

glGetGraphicsResetStatusARBPtr glGetGraphicsResetStatusARB_ptr = nullptr;
glGetnTexImageARBPtr glGetnTexImageARB_ptr                     = nullptr;
glReadnPixelsARBPtr glReadnPixelsARB_ptr                       = nullptr;
glGetnCompressedTexImageARBPtr glGetnCompressedTexImageARB_ptr = nullptr;
glGetnUniformfvARBPtr glGetnUniformfvARB_ptr                   = nullptr;
glGetnUniformivARBPtr glGetnUniformivARB_ptr                   = nullptr;
glGetnUniformuivARBPtr glGetnUniformuivARB_ptr                 = nullptr;
glGetnUniformdvARBPtr glGetnUniformdvARB_ptr                   = nullptr;

bool init_gl_arb_robustness([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glGetGraphicsResetStatusARB_ptr = reinterpret_cast<glGetGraphicsResetStatusARBPtr>(get_function("glGetGraphicsResetStatusARB"))) == nullptr || result;
    result = (glGetnTexImageARB_ptr = reinterpret_cast<glGetnTexImageARBPtr>(get_function("glGetnTexImageARB"))) == nullptr || result;
    result = (glReadnPixelsARB_ptr = reinterpret_cast<glReadnPixelsARBPtr>(get_function("glReadnPixelsARB"))) == nullptr || result;
    result = (glGetnCompressedTexImageARB_ptr = reinterpret_cast<glGetnCompressedTexImageARBPtr>(get_function("glGetnCompressedTexImageARB"))) == nullptr || result;
    result = (glGetnUniformfvARB_ptr = reinterpret_cast<glGetnUniformfvARBPtr>(get_function("glGetnUniformfvARB"))) == nullptr || result;
    result = (glGetnUniformivARB_ptr = reinterpret_cast<glGetnUniformivARBPtr>(get_function("glGetnUniformivARB"))) == nullptr || result;
    result = (glGetnUniformuivARB_ptr = reinterpret_cast<glGetnUniformuivARBPtr>(get_function("glGetnUniformuivARB"))) == nullptr || result;
    result = (glGetnUniformdvARB_ptr = reinterpret_cast<glGetnUniformdvARBPtr>(get_function("glGetnUniformdvARB"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_ARB_robustness_isolation

bool init_gl_arb_robustness_isolation([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_sample_locations

using glFramebufferSampleLocationsfvARBPtr      = std::add_pointer_t<decltype(glFramebufferSampleLocationsfvARB)>;
using glNamedFramebufferSampleLocationsfvARBPtr = std::add_pointer_t<decltype(glNamedFramebufferSampleLocationsfvARB)>;
using glEvaluateDepthValuesARBPtr               = std::add_pointer_t<decltype(glEvaluateDepthValuesARB)>;

glFramebufferSampleLocationsfvARBPtr glFramebufferSampleLocationsfvARB_ptr           = nullptr;
glNamedFramebufferSampleLocationsfvARBPtr glNamedFramebufferSampleLocationsfvARB_ptr = nullptr;
glEvaluateDepthValuesARBPtr glEvaluateDepthValuesARB_ptr                             = nullptr;

bool init_gl_arb_sample_locations([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glFramebufferSampleLocationsfvARB_ptr = reinterpret_cast<glFramebufferSampleLocationsfvARBPtr>(get_function("glFramebufferSampleLocationsfvARB"))) == nullptr || result;
    result = (glNamedFramebufferSampleLocationsfvARB_ptr = reinterpret_cast<glNamedFramebufferSampleLocationsfvARBPtr>(get_function("glNamedFramebufferSampleLocationsfvARB"))) == nullptr || result;
    result = (glEvaluateDepthValuesARB_ptr = reinterpret_cast<glEvaluateDepthValuesARBPtr>(get_function("glEvaluateDepthValuesARB"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_ARB_sample_shading

using glMinSampleShadingARBPtr = std::add_pointer_t<decltype(glMinSampleShadingARB)>;

glMinSampleShadingARBPtr glMinSampleShadingARB_ptr = nullptr;

bool init_gl_arb_sample_shading([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glMinSampleShadingARB_ptr = reinterpret_cast<glMinSampleShadingARBPtr>(get_function("glMinSampleShadingARB"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_ARB_sampler_objects

bool init_gl_arb_sampler_objects([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_seamless_cube_map

bool init_gl_arb_seamless_cube_map([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_seamless_cubemap_per_texture

bool init_gl_arb_seamless_cubemap_per_texture([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_separate_shader_objects

bool init_gl_arb_separate_shader_objects([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_shader_atomic_counter_ops

bool init_gl_arb_shader_atomic_counter_ops([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_shader_atomic_counters

bool init_gl_arb_shader_atomic_counters([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_shader_ballot

bool init_gl_arb_shader_ballot([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_shader_bit_encoding

bool init_gl_arb_shader_bit_encoding([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_shader_clock

bool init_gl_arb_shader_clock([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_shader_draw_parameters

bool init_gl_arb_shader_draw_parameters([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_shader_group_vote

bool init_gl_arb_shader_group_vote([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_shader_image_load_store

bool init_gl_arb_shader_image_load_store([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_shader_image_size

bool init_gl_arb_shader_image_size([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_shader_precision

bool init_gl_arb_shader_precision([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_shader_stencil_export

bool init_gl_arb_shader_stencil_export([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_shader_storage_buffer_object

bool init_gl_arb_shader_storage_buffer_object([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_shader_subroutine

bool init_gl_arb_shader_subroutine([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_shader_texture_image_samples

bool init_gl_arb_shader_texture_image_samples([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_shader_viewport_layer_array

bool init_gl_arb_shader_viewport_layer_array([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_shading_language_420pack

bool init_gl_arb_shading_language_420pack([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_shading_language_include

using glNamedStringARBPtr          = std::add_pointer_t<decltype(glNamedStringARB)>;
using glDeleteNamedStringARBPtr    = std::add_pointer_t<decltype(glDeleteNamedStringARB)>;
using glCompileShaderIncludeARBPtr = std::add_pointer_t<decltype(glCompileShaderIncludeARB)>;
using glIsNamedStringARBPtr        = std::add_pointer_t<decltype(glIsNamedStringARB)>;
using glGetNamedStringARBPtr       = std::add_pointer_t<decltype(glGetNamedStringARB)>;
using glGetNamedStringivARBPtr     = std::add_pointer_t<decltype(glGetNamedStringivARB)>;

glNamedStringARBPtr glNamedStringARB_ptr                   = nullptr;
glDeleteNamedStringARBPtr glDeleteNamedStringARB_ptr       = nullptr;
glCompileShaderIncludeARBPtr glCompileShaderIncludeARB_ptr = nullptr;
glIsNamedStringARBPtr glIsNamedStringARB_ptr               = nullptr;
glGetNamedStringARBPtr glGetNamedStringARB_ptr             = nullptr;
glGetNamedStringivARBPtr glGetNamedStringivARB_ptr         = nullptr;

bool init_gl_arb_shading_language_include([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glNamedStringARB_ptr = reinterpret_cast<glNamedStringARBPtr>(get_function("glNamedStringARB"))) == nullptr || result;
    result = (glDeleteNamedStringARB_ptr = reinterpret_cast<glDeleteNamedStringARBPtr>(get_function("glDeleteNamedStringARB"))) == nullptr || result;
    result = (glCompileShaderIncludeARB_ptr = reinterpret_cast<glCompileShaderIncludeARBPtr>(get_function("glCompileShaderIncludeARB"))) == nullptr || result;
    result = (glIsNamedStringARB_ptr = reinterpret_cast<glIsNamedStringARBPtr>(get_function("glIsNamedStringARB"))) == nullptr || result;
    result = (glGetNamedStringARB_ptr = reinterpret_cast<glGetNamedStringARBPtr>(get_function("glGetNamedStringARB"))) == nullptr || result;
    result = (glGetNamedStringivARB_ptr = reinterpret_cast<glGetNamedStringivARBPtr>(get_function("glGetNamedStringivARB"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_ARB_shading_language_packing

bool init_gl_arb_shading_language_packing([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_sparse_buffer

using glBufferPageCommitmentARBPtr      = std::add_pointer_t<decltype(glBufferPageCommitmentARB)>;
using glNamedBufferPageCommitmentEXTPtr = std::add_pointer_t<decltype(glNamedBufferPageCommitmentEXT)>;
using glNamedBufferPageCommitmentARBPtr = std::add_pointer_t<decltype(glNamedBufferPageCommitmentARB)>;

glBufferPageCommitmentARBPtr glBufferPageCommitmentARB_ptr           = nullptr;
glNamedBufferPageCommitmentEXTPtr glNamedBufferPageCommitmentEXT_ptr = nullptr;
glNamedBufferPageCommitmentARBPtr glNamedBufferPageCommitmentARB_ptr = nullptr;

bool init_gl_arb_sparse_buffer([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glBufferPageCommitmentARB_ptr = reinterpret_cast<glBufferPageCommitmentARBPtr>(get_function("glBufferPageCommitmentARB"))) == nullptr || result;
    result = (glNamedBufferPageCommitmentEXT_ptr = reinterpret_cast<glNamedBufferPageCommitmentEXTPtr>(get_function("glNamedBufferPageCommitmentEXT"))) == nullptr || result;
    result = (glNamedBufferPageCommitmentARB_ptr = reinterpret_cast<glNamedBufferPageCommitmentARBPtr>(get_function("glNamedBufferPageCommitmentARB"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_ARB_sparse_texture

using glTexPageCommitmentARBPtr = std::add_pointer_t<decltype(glTexPageCommitmentARB)>;

glTexPageCommitmentARBPtr glTexPageCommitmentARB_ptr = nullptr;

bool init_gl_arb_sparse_texture([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glTexPageCommitmentARB_ptr = reinterpret_cast<glTexPageCommitmentARBPtr>(get_function("glTexPageCommitmentARB"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_ARB_sparse_texture2

bool init_gl_arb_sparse_texture2([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_sparse_texture_clamp

bool init_gl_arb_sparse_texture_clamp([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_spirv_extensions

bool init_gl_arb_spirv_extensions([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_stencil_texturing

bool init_gl_arb_stencil_texturing([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_sync

bool init_gl_arb_sync([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_tessellation_shader

bool init_gl_arb_tessellation_shader([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_texture_barrier

bool init_gl_arb_texture_barrier([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_texture_border_clamp

bool init_gl_arb_texture_border_clamp([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_texture_buffer_object

using glTexBufferARBPtr = std::add_pointer_t<decltype(glTexBufferARB)>;

glTexBufferARBPtr glTexBufferARB_ptr = nullptr;

bool init_gl_arb_texture_buffer_object([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glTexBufferARB_ptr = reinterpret_cast<glTexBufferARBPtr>(get_function("glTexBufferARB"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_ARB_texture_buffer_object_rgb32

bool init_gl_arb_texture_buffer_object_rgb32([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_texture_buffer_range

bool init_gl_arb_texture_buffer_range([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_texture_compression_bptc

bool init_gl_arb_texture_compression_bptc([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_texture_compression_rgtc

bool init_gl_arb_texture_compression_rgtc([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_texture_cube_map_array

bool init_gl_arb_texture_cube_map_array([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_texture_filter_anisotropic

bool init_gl_arb_texture_filter_anisotropic([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_texture_filter_minmax

bool init_gl_arb_texture_filter_minmax([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_texture_gather

bool init_gl_arb_texture_gather([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_texture_mirror_clamp_to_edge

bool init_gl_arb_texture_mirror_clamp_to_edge([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_texture_mirrored_repeat

bool init_gl_arb_texture_mirrored_repeat([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_texture_multisample

bool init_gl_arb_texture_multisample([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_texture_non_power_of_two

bool init_gl_arb_texture_non_power_of_two([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_texture_query_levels

bool init_gl_arb_texture_query_levels([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_texture_query_lod

bool init_gl_arb_texture_query_lod([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_texture_rg

bool init_gl_arb_texture_rg([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_texture_rgb10_a2ui

bool init_gl_arb_texture_rgb10_a2ui([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_texture_stencil8

bool init_gl_arb_texture_stencil8([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_texture_storage

bool init_gl_arb_texture_storage([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_texture_storage_multisample

bool init_gl_arb_texture_storage_multisample([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_texture_swizzle

bool init_gl_arb_texture_swizzle([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_texture_view

bool init_gl_arb_texture_view([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_timer_query

bool init_gl_arb_timer_query([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_transform_feedback2

bool init_gl_arb_transform_feedback2([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_transform_feedback3

bool init_gl_arb_transform_feedback3([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_transform_feedback_instanced

bool init_gl_arb_transform_feedback_instanced([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_transform_feedback_overflow_query

bool init_gl_arb_transform_feedback_overflow_query([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_uniform_buffer_object

bool init_gl_arb_uniform_buffer_object([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_vertex_array_bgra

bool init_gl_arb_vertex_array_bgra([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_vertex_array_object

bool init_gl_arb_vertex_array_object([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_vertex_attrib_64bit

bool init_gl_arb_vertex_attrib_64bit([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_vertex_attrib_binding

bool init_gl_arb_vertex_attrib_binding([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_vertex_type_10f_11f_11f_rev

bool init_gl_arb_vertex_type_10f_11f_11f_rev([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_vertex_type_2_10_10_10_rev

bool init_gl_arb_vertex_type_2_10_10_10_rev([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_ARB_viewport_array

using glDepthRangeArraydvNVPtr  = std::add_pointer_t<decltype(glDepthRangeArraydvNV)>;
using glDepthRangeIndexeddNVPtr = std::add_pointer_t<decltype(glDepthRangeIndexeddNV)>;

glDepthRangeArraydvNVPtr glDepthRangeArraydvNV_ptr   = nullptr;
glDepthRangeIndexeddNVPtr glDepthRangeIndexeddNV_ptr = nullptr;

bool init_gl_arb_viewport_array([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glDepthRangeArraydvNV_ptr = reinterpret_cast<glDepthRangeArraydvNVPtr>(get_function("glDepthRangeArraydvNV"))) == nullptr || result;
    result = (glDepthRangeIndexeddNV_ptr = reinterpret_cast<glDepthRangeIndexeddNVPtr>(get_function("glDepthRangeIndexeddNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_EXT_EGL_image_storage

using glEGLImageTargetTexStorageEXTPtr     = std::add_pointer_t<decltype(glEGLImageTargetTexStorageEXT)>;
using glEGLImageTargetTextureStorageEXTPtr = std::add_pointer_t<decltype(glEGLImageTargetTextureStorageEXT)>;

glEGLImageTargetTexStorageEXTPtr glEGLImageTargetTexStorageEXT_ptr         = nullptr;
glEGLImageTargetTextureStorageEXTPtr glEGLImageTargetTextureStorageEXT_ptr = nullptr;

bool init_gl_ext_egl_image_storage([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glEGLImageTargetTexStorageEXT_ptr = reinterpret_cast<glEGLImageTargetTexStorageEXTPtr>(get_function("glEGLImageTargetTexStorageEXT"))) == nullptr || result;
    result = (glEGLImageTargetTextureStorageEXT_ptr = reinterpret_cast<glEGLImageTargetTextureStorageEXTPtr>(get_function("glEGLImageTargetTextureStorageEXT"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_EXT_EGL_sync

bool init_gl_ext_egl_sync([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_EXT_debug_label

using glLabelObjectEXTPtr    = std::add_pointer_t<decltype(glLabelObjectEXT)>;
using glGetObjectLabelEXTPtr = std::add_pointer_t<decltype(glGetObjectLabelEXT)>;

glLabelObjectEXTPtr glLabelObjectEXT_ptr       = nullptr;
glGetObjectLabelEXTPtr glGetObjectLabelEXT_ptr = nullptr;

bool init_gl_ext_debug_label([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glLabelObjectEXT_ptr = reinterpret_cast<glLabelObjectEXTPtr>(get_function("glLabelObjectEXT"))) == nullptr || result;
    result = (glGetObjectLabelEXT_ptr = reinterpret_cast<glGetObjectLabelEXTPtr>(get_function("glGetObjectLabelEXT"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_EXT_debug_marker

using glInsertEventMarkerEXTPtr = std::add_pointer_t<decltype(glInsertEventMarkerEXT)>;
using glPushGroupMarkerEXTPtr   = std::add_pointer_t<decltype(glPushGroupMarkerEXT)>;
using glPopGroupMarkerEXTPtr    = std::add_pointer_t<decltype(glPopGroupMarkerEXT)>;

glInsertEventMarkerEXTPtr glInsertEventMarkerEXT_ptr = nullptr;
glPushGroupMarkerEXTPtr glPushGroupMarkerEXT_ptr     = nullptr;
glPopGroupMarkerEXTPtr glPopGroupMarkerEXT_ptr       = nullptr;

bool init_gl_ext_debug_marker([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glInsertEventMarkerEXT_ptr = reinterpret_cast<glInsertEventMarkerEXTPtr>(get_function("glInsertEventMarkerEXT"))) == nullptr || result;
    result = (glPushGroupMarkerEXT_ptr = reinterpret_cast<glPushGroupMarkerEXTPtr>(get_function("glPushGroupMarkerEXT"))) == nullptr || result;
    result = (glPopGroupMarkerEXT_ptr = reinterpret_cast<glPopGroupMarkerEXTPtr>(get_function("glPopGroupMarkerEXT"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_EXT_direct_state_access

using glMatrixLoadfEXTPtr                       = std::add_pointer_t<decltype(glMatrixLoadfEXT)>;
using glMatrixLoaddEXTPtr                       = std::add_pointer_t<decltype(glMatrixLoaddEXT)>;
using glMatrixMultfEXTPtr                       = std::add_pointer_t<decltype(glMatrixMultfEXT)>;
using glMatrixMultdEXTPtr                       = std::add_pointer_t<decltype(glMatrixMultdEXT)>;
using glMatrixLoadIdentityEXTPtr                = std::add_pointer_t<decltype(glMatrixLoadIdentityEXT)>;
using glMatrixRotatefEXTPtr                     = std::add_pointer_t<decltype(glMatrixRotatefEXT)>;
using glMatrixRotatedEXTPtr                     = std::add_pointer_t<decltype(glMatrixRotatedEXT)>;
using glMatrixScalefEXTPtr                      = std::add_pointer_t<decltype(glMatrixScalefEXT)>;
using glMatrixScaledEXTPtr                      = std::add_pointer_t<decltype(glMatrixScaledEXT)>;
using glMatrixTranslatefEXTPtr                  = std::add_pointer_t<decltype(glMatrixTranslatefEXT)>;
using glMatrixTranslatedEXTPtr                  = std::add_pointer_t<decltype(glMatrixTranslatedEXT)>;
using glMatrixFrustumEXTPtr                     = std::add_pointer_t<decltype(glMatrixFrustumEXT)>;
using glMatrixOrthoEXTPtr                       = std::add_pointer_t<decltype(glMatrixOrthoEXT)>;
using glMatrixPopEXTPtr                         = std::add_pointer_t<decltype(glMatrixPopEXT)>;
using glMatrixPushEXTPtr                        = std::add_pointer_t<decltype(glMatrixPushEXT)>;
using glClientAttribDefaultEXTPtr               = std::add_pointer_t<decltype(glClientAttribDefaultEXT)>;
using glPushClientAttribDefaultEXTPtr           = std::add_pointer_t<decltype(glPushClientAttribDefaultEXT)>;
using glTextureParameterfEXTPtr                 = std::add_pointer_t<decltype(glTextureParameterfEXT)>;
using glTextureParameterfvEXTPtr                = std::add_pointer_t<decltype(glTextureParameterfvEXT)>;
using glTextureParameteriEXTPtr                 = std::add_pointer_t<decltype(glTextureParameteriEXT)>;
using glTextureParameterivEXTPtr                = std::add_pointer_t<decltype(glTextureParameterivEXT)>;
using glTextureImage1DEXTPtr                    = std::add_pointer_t<decltype(glTextureImage1DEXT)>;
using glTextureImage2DEXTPtr                    = std::add_pointer_t<decltype(glTextureImage2DEXT)>;
using glTextureSubImage1DEXTPtr                 = std::add_pointer_t<decltype(glTextureSubImage1DEXT)>;
using glTextureSubImage2DEXTPtr                 = std::add_pointer_t<decltype(glTextureSubImage2DEXT)>;
using glCopyTextureImage1DEXTPtr                = std::add_pointer_t<decltype(glCopyTextureImage1DEXT)>;
using glCopyTextureImage2DEXTPtr                = std::add_pointer_t<decltype(glCopyTextureImage2DEXT)>;
using glCopyTextureSubImage1DEXTPtr             = std::add_pointer_t<decltype(glCopyTextureSubImage1DEXT)>;
using glCopyTextureSubImage2DEXTPtr             = std::add_pointer_t<decltype(glCopyTextureSubImage2DEXT)>;
using glGetTextureImageEXTPtr                   = std::add_pointer_t<decltype(glGetTextureImageEXT)>;
using glGetTextureParameterfvEXTPtr             = std::add_pointer_t<decltype(glGetTextureParameterfvEXT)>;
using glGetTextureParameterivEXTPtr             = std::add_pointer_t<decltype(glGetTextureParameterivEXT)>;
using glGetTextureLevelParameterfvEXTPtr        = std::add_pointer_t<decltype(glGetTextureLevelParameterfvEXT)>;
using glGetTextureLevelParameterivEXTPtr        = std::add_pointer_t<decltype(glGetTextureLevelParameterivEXT)>;
using glTextureImage3DEXTPtr                    = std::add_pointer_t<decltype(glTextureImage3DEXT)>;
using glTextureSubImage3DEXTPtr                 = std::add_pointer_t<decltype(glTextureSubImage3DEXT)>;
using glCopyTextureSubImage3DEXTPtr             = std::add_pointer_t<decltype(glCopyTextureSubImage3DEXT)>;
using glBindMultiTextureEXTPtr                  = std::add_pointer_t<decltype(glBindMultiTextureEXT)>;
using glMultiTexCoordPointerEXTPtr              = std::add_pointer_t<decltype(glMultiTexCoordPointerEXT)>;
using glMultiTexEnvfEXTPtr                      = std::add_pointer_t<decltype(glMultiTexEnvfEXT)>;
using glMultiTexEnvfvEXTPtr                     = std::add_pointer_t<decltype(glMultiTexEnvfvEXT)>;
using glMultiTexEnviEXTPtr                      = std::add_pointer_t<decltype(glMultiTexEnviEXT)>;
using glMultiTexEnvivEXTPtr                     = std::add_pointer_t<decltype(glMultiTexEnvivEXT)>;
using glMultiTexGendEXTPtr                      = std::add_pointer_t<decltype(glMultiTexGendEXT)>;
using glMultiTexGendvEXTPtr                     = std::add_pointer_t<decltype(glMultiTexGendvEXT)>;
using glMultiTexGenfEXTPtr                      = std::add_pointer_t<decltype(glMultiTexGenfEXT)>;
using glMultiTexGenfvEXTPtr                     = std::add_pointer_t<decltype(glMultiTexGenfvEXT)>;
using glMultiTexGeniEXTPtr                      = std::add_pointer_t<decltype(glMultiTexGeniEXT)>;
using glMultiTexGenivEXTPtr                     = std::add_pointer_t<decltype(glMultiTexGenivEXT)>;
using glGetMultiTexEnvfvEXTPtr                  = std::add_pointer_t<decltype(glGetMultiTexEnvfvEXT)>;
using glGetMultiTexEnvivEXTPtr                  = std::add_pointer_t<decltype(glGetMultiTexEnvivEXT)>;
using glGetMultiTexGendvEXTPtr                  = std::add_pointer_t<decltype(glGetMultiTexGendvEXT)>;
using glGetMultiTexGenfvEXTPtr                  = std::add_pointer_t<decltype(glGetMultiTexGenfvEXT)>;
using glGetMultiTexGenivEXTPtr                  = std::add_pointer_t<decltype(glGetMultiTexGenivEXT)>;
using glMultiTexParameteriEXTPtr                = std::add_pointer_t<decltype(glMultiTexParameteriEXT)>;
using glMultiTexParameterivEXTPtr               = std::add_pointer_t<decltype(glMultiTexParameterivEXT)>;
using glMultiTexParameterfEXTPtr                = std::add_pointer_t<decltype(glMultiTexParameterfEXT)>;
using glMultiTexParameterfvEXTPtr               = std::add_pointer_t<decltype(glMultiTexParameterfvEXT)>;
using glMultiTexImage1DEXTPtr                   = std::add_pointer_t<decltype(glMultiTexImage1DEXT)>;
using glMultiTexImage2DEXTPtr                   = std::add_pointer_t<decltype(glMultiTexImage2DEXT)>;
using glMultiTexSubImage1DEXTPtr                = std::add_pointer_t<decltype(glMultiTexSubImage1DEXT)>;
using glMultiTexSubImage2DEXTPtr                = std::add_pointer_t<decltype(glMultiTexSubImage2DEXT)>;
using glCopyMultiTexImage1DEXTPtr               = std::add_pointer_t<decltype(glCopyMultiTexImage1DEXT)>;
using glCopyMultiTexImage2DEXTPtr               = std::add_pointer_t<decltype(glCopyMultiTexImage2DEXT)>;
using glCopyMultiTexSubImage1DEXTPtr            = std::add_pointer_t<decltype(glCopyMultiTexSubImage1DEXT)>;
using glCopyMultiTexSubImage2DEXTPtr            = std::add_pointer_t<decltype(glCopyMultiTexSubImage2DEXT)>;
using glGetMultiTexImageEXTPtr                  = std::add_pointer_t<decltype(glGetMultiTexImageEXT)>;
using glGetMultiTexParameterfvEXTPtr            = std::add_pointer_t<decltype(glGetMultiTexParameterfvEXT)>;
using glGetMultiTexParameterivEXTPtr            = std::add_pointer_t<decltype(glGetMultiTexParameterivEXT)>;
using glGetMultiTexLevelParameterfvEXTPtr       = std::add_pointer_t<decltype(glGetMultiTexLevelParameterfvEXT)>;
using glGetMultiTexLevelParameterivEXTPtr       = std::add_pointer_t<decltype(glGetMultiTexLevelParameterivEXT)>;
using glMultiTexImage3DEXTPtr                   = std::add_pointer_t<decltype(glMultiTexImage3DEXT)>;
using glMultiTexSubImage3DEXTPtr                = std::add_pointer_t<decltype(glMultiTexSubImage3DEXT)>;
using glCopyMultiTexSubImage3DEXTPtr            = std::add_pointer_t<decltype(glCopyMultiTexSubImage3DEXT)>;
using glEnableClientStateIndexedEXTPtr          = std::add_pointer_t<decltype(glEnableClientStateIndexedEXT)>;
using glDisableClientStateIndexedEXTPtr         = std::add_pointer_t<decltype(glDisableClientStateIndexedEXT)>;
using glGetFloatIndexedvEXTPtr                  = std::add_pointer_t<decltype(glGetFloatIndexedvEXT)>;
using glGetDoubleIndexedvEXTPtr                 = std::add_pointer_t<decltype(glGetDoubleIndexedvEXT)>;
using glGetPointerIndexedvEXTPtr                = std::add_pointer_t<decltype(glGetPointerIndexedvEXT)>;
using glEnableIndexedEXTPtr                     = std::add_pointer_t<decltype(glEnableIndexedEXT)>;
using glDisableIndexedEXTPtr                    = std::add_pointer_t<decltype(glDisableIndexedEXT)>;
using glIsEnabledIndexedEXTPtr                  = std::add_pointer_t<decltype(glIsEnabledIndexedEXT)>;
using glGetIntegerIndexedvEXTPtr                = std::add_pointer_t<decltype(glGetIntegerIndexedvEXT)>;
using glGetBooleanIndexedvEXTPtr                = std::add_pointer_t<decltype(glGetBooleanIndexedvEXT)>;
using glCompressedTextureImage3DEXTPtr          = std::add_pointer_t<decltype(glCompressedTextureImage3DEXT)>;
using glCompressedTextureImage2DEXTPtr          = std::add_pointer_t<decltype(glCompressedTextureImage2DEXT)>;
using glCompressedTextureImage1DEXTPtr          = std::add_pointer_t<decltype(glCompressedTextureImage1DEXT)>;
using glCompressedTextureSubImage3DEXTPtr       = std::add_pointer_t<decltype(glCompressedTextureSubImage3DEXT)>;
using glCompressedTextureSubImage2DEXTPtr       = std::add_pointer_t<decltype(glCompressedTextureSubImage2DEXT)>;
using glCompressedTextureSubImage1DEXTPtr       = std::add_pointer_t<decltype(glCompressedTextureSubImage1DEXT)>;
using glGetCompressedTextureImageEXTPtr         = std::add_pointer_t<decltype(glGetCompressedTextureImageEXT)>;
using glCompressedMultiTexImage3DEXTPtr         = std::add_pointer_t<decltype(glCompressedMultiTexImage3DEXT)>;
using glCompressedMultiTexImage2DEXTPtr         = std::add_pointer_t<decltype(glCompressedMultiTexImage2DEXT)>;
using glCompressedMultiTexImage1DEXTPtr         = std::add_pointer_t<decltype(glCompressedMultiTexImage1DEXT)>;
using glCompressedMultiTexSubImage3DEXTPtr      = std::add_pointer_t<decltype(glCompressedMultiTexSubImage3DEXT)>;
using glCompressedMultiTexSubImage2DEXTPtr      = std::add_pointer_t<decltype(glCompressedMultiTexSubImage2DEXT)>;
using glCompressedMultiTexSubImage1DEXTPtr      = std::add_pointer_t<decltype(glCompressedMultiTexSubImage1DEXT)>;
using glGetCompressedMultiTexImageEXTPtr        = std::add_pointer_t<decltype(glGetCompressedMultiTexImageEXT)>;
using glMatrixLoadTransposefEXTPtr              = std::add_pointer_t<decltype(glMatrixLoadTransposefEXT)>;
using glMatrixLoadTransposedEXTPtr              = std::add_pointer_t<decltype(glMatrixLoadTransposedEXT)>;
using glMatrixMultTransposefEXTPtr              = std::add_pointer_t<decltype(glMatrixMultTransposefEXT)>;
using glMatrixMultTransposedEXTPtr              = std::add_pointer_t<decltype(glMatrixMultTransposedEXT)>;
using glNamedBufferDataEXTPtr                   = std::add_pointer_t<decltype(glNamedBufferDataEXT)>;
using glNamedBufferSubDataEXTPtr                = std::add_pointer_t<decltype(glNamedBufferSubDataEXT)>;
using glMapNamedBufferEXTPtr                    = std::add_pointer_t<decltype(glMapNamedBufferEXT)>;
using glUnmapNamedBufferEXTPtr                  = std::add_pointer_t<decltype(glUnmapNamedBufferEXT)>;
using glGetNamedBufferParameterivEXTPtr         = std::add_pointer_t<decltype(glGetNamedBufferParameterivEXT)>;
using glGetNamedBufferPointervEXTPtr            = std::add_pointer_t<decltype(glGetNamedBufferPointervEXT)>;
using glGetNamedBufferSubDataEXTPtr             = std::add_pointer_t<decltype(glGetNamedBufferSubDataEXT)>;
using glProgramUniform1fEXTPtr                  = std::add_pointer_t<decltype(glProgramUniform1fEXT)>;
using glProgramUniform2fEXTPtr                  = std::add_pointer_t<decltype(glProgramUniform2fEXT)>;
using glProgramUniform3fEXTPtr                  = std::add_pointer_t<decltype(glProgramUniform3fEXT)>;
using glProgramUniform4fEXTPtr                  = std::add_pointer_t<decltype(glProgramUniform4fEXT)>;
using glProgramUniform1iEXTPtr                  = std::add_pointer_t<decltype(glProgramUniform1iEXT)>;
using glProgramUniform2iEXTPtr                  = std::add_pointer_t<decltype(glProgramUniform2iEXT)>;
using glProgramUniform3iEXTPtr                  = std::add_pointer_t<decltype(glProgramUniform3iEXT)>;
using glProgramUniform4iEXTPtr                  = std::add_pointer_t<decltype(glProgramUniform4iEXT)>;
using glProgramUniform1fvEXTPtr                 = std::add_pointer_t<decltype(glProgramUniform1fvEXT)>;
using glProgramUniform2fvEXTPtr                 = std::add_pointer_t<decltype(glProgramUniform2fvEXT)>;
using glProgramUniform3fvEXTPtr                 = std::add_pointer_t<decltype(glProgramUniform3fvEXT)>;
using glProgramUniform4fvEXTPtr                 = std::add_pointer_t<decltype(glProgramUniform4fvEXT)>;
using glProgramUniform1ivEXTPtr                 = std::add_pointer_t<decltype(glProgramUniform1ivEXT)>;
using glProgramUniform2ivEXTPtr                 = std::add_pointer_t<decltype(glProgramUniform2ivEXT)>;
using glProgramUniform3ivEXTPtr                 = std::add_pointer_t<decltype(glProgramUniform3ivEXT)>;
using glProgramUniform4ivEXTPtr                 = std::add_pointer_t<decltype(glProgramUniform4ivEXT)>;
using glProgramUniformMatrix2fvEXTPtr           = std::add_pointer_t<decltype(glProgramUniformMatrix2fvEXT)>;
using glProgramUniformMatrix3fvEXTPtr           = std::add_pointer_t<decltype(glProgramUniformMatrix3fvEXT)>;
using glProgramUniformMatrix4fvEXTPtr           = std::add_pointer_t<decltype(glProgramUniformMatrix4fvEXT)>;
using glProgramUniformMatrix2x3fvEXTPtr         = std::add_pointer_t<decltype(glProgramUniformMatrix2x3fvEXT)>;
using glProgramUniformMatrix3x2fvEXTPtr         = std::add_pointer_t<decltype(glProgramUniformMatrix3x2fvEXT)>;
using glProgramUniformMatrix2x4fvEXTPtr         = std::add_pointer_t<decltype(glProgramUniformMatrix2x4fvEXT)>;
using glProgramUniformMatrix4x2fvEXTPtr         = std::add_pointer_t<decltype(glProgramUniformMatrix4x2fvEXT)>;
using glProgramUniformMatrix3x4fvEXTPtr         = std::add_pointer_t<decltype(glProgramUniformMatrix3x4fvEXT)>;
using glProgramUniformMatrix4x3fvEXTPtr         = std::add_pointer_t<decltype(glProgramUniformMatrix4x3fvEXT)>;
using glTextureBufferEXTPtr                     = std::add_pointer_t<decltype(glTextureBufferEXT)>;
using glMultiTexBufferEXTPtr                    = std::add_pointer_t<decltype(glMultiTexBufferEXT)>;
using glTextureParameterIivEXTPtr               = std::add_pointer_t<decltype(glTextureParameterIivEXT)>;
using glTextureParameterIuivEXTPtr              = std::add_pointer_t<decltype(glTextureParameterIuivEXT)>;
using glGetTextureParameterIivEXTPtr            = std::add_pointer_t<decltype(glGetTextureParameterIivEXT)>;
using glGetTextureParameterIuivEXTPtr           = std::add_pointer_t<decltype(glGetTextureParameterIuivEXT)>;
using glMultiTexParameterIivEXTPtr              = std::add_pointer_t<decltype(glMultiTexParameterIivEXT)>;
using glMultiTexParameterIuivEXTPtr             = std::add_pointer_t<decltype(glMultiTexParameterIuivEXT)>;
using glGetMultiTexParameterIivEXTPtr           = std::add_pointer_t<decltype(glGetMultiTexParameterIivEXT)>;
using glGetMultiTexParameterIuivEXTPtr          = std::add_pointer_t<decltype(glGetMultiTexParameterIuivEXT)>;
using glProgramUniform1uiEXTPtr                 = std::add_pointer_t<decltype(glProgramUniform1uiEXT)>;
using glProgramUniform2uiEXTPtr                 = std::add_pointer_t<decltype(glProgramUniform2uiEXT)>;
using glProgramUniform3uiEXTPtr                 = std::add_pointer_t<decltype(glProgramUniform3uiEXT)>;
using glProgramUniform4uiEXTPtr                 = std::add_pointer_t<decltype(glProgramUniform4uiEXT)>;
using glProgramUniform1uivEXTPtr                = std::add_pointer_t<decltype(glProgramUniform1uivEXT)>;
using glProgramUniform2uivEXTPtr                = std::add_pointer_t<decltype(glProgramUniform2uivEXT)>;
using glProgramUniform3uivEXTPtr                = std::add_pointer_t<decltype(glProgramUniform3uivEXT)>;
using glProgramUniform4uivEXTPtr                = std::add_pointer_t<decltype(glProgramUniform4uivEXT)>;
using glNamedProgramLocalParameters4fvEXTPtr    = std::add_pointer_t<decltype(glNamedProgramLocalParameters4fvEXT)>;
using glNamedProgramLocalParameterI4iEXTPtr     = std::add_pointer_t<decltype(glNamedProgramLocalParameterI4iEXT)>;
using glNamedProgramLocalParameterI4ivEXTPtr    = std::add_pointer_t<decltype(glNamedProgramLocalParameterI4ivEXT)>;
using glNamedProgramLocalParametersI4ivEXTPtr   = std::add_pointer_t<decltype(glNamedProgramLocalParametersI4ivEXT)>;
using glNamedProgramLocalParameterI4uiEXTPtr    = std::add_pointer_t<decltype(glNamedProgramLocalParameterI4uiEXT)>;
using glNamedProgramLocalParameterI4uivEXTPtr   = std::add_pointer_t<decltype(glNamedProgramLocalParameterI4uivEXT)>;
using glNamedProgramLocalParametersI4uivEXTPtr  = std::add_pointer_t<decltype(glNamedProgramLocalParametersI4uivEXT)>;
using glGetNamedProgramLocalParameterIivEXTPtr  = std::add_pointer_t<decltype(glGetNamedProgramLocalParameterIivEXT)>;
using glGetNamedProgramLocalParameterIuivEXTPtr = std::add_pointer_t<decltype(glGetNamedProgramLocalParameterIuivEXT)>;
using glEnableClientStateiEXTPtr                = std::add_pointer_t<decltype(glEnableClientStateiEXT)>;
using glDisableClientStateiEXTPtr               = std::add_pointer_t<decltype(glDisableClientStateiEXT)>;
using glGetFloati_vEXTPtr                       = std::add_pointer_t<decltype(glGetFloati_vEXT)>;
using glGetDoublei_vEXTPtr                      = std::add_pointer_t<decltype(glGetDoublei_vEXT)>;
using glGetPointeri_vEXTPtr                     = std::add_pointer_t<decltype(glGetPointeri_vEXT)>;
using glNamedProgramStringEXTPtr                = std::add_pointer_t<decltype(glNamedProgramStringEXT)>;
using glNamedProgramLocalParameter4dEXTPtr      = std::add_pointer_t<decltype(glNamedProgramLocalParameter4dEXT)>;
using glNamedProgramLocalParameter4dvEXTPtr     = std::add_pointer_t<decltype(glNamedProgramLocalParameter4dvEXT)>;
using glNamedProgramLocalParameter4fEXTPtr      = std::add_pointer_t<decltype(glNamedProgramLocalParameter4fEXT)>;
using glNamedProgramLocalParameter4fvEXTPtr     = std::add_pointer_t<decltype(glNamedProgramLocalParameter4fvEXT)>;
using glGetNamedProgramLocalParameterdvEXTPtr   = std::add_pointer_t<decltype(glGetNamedProgramLocalParameterdvEXT)>;
using glGetNamedProgramLocalParameterfvEXTPtr   = std::add_pointer_t<decltype(glGetNamedProgramLocalParameterfvEXT)>;
using glGetNamedProgramivEXTPtr                 = std::add_pointer_t<decltype(glGetNamedProgramivEXT)>;
using glGetNamedProgramStringEXTPtr             = std::add_pointer_t<decltype(glGetNamedProgramStringEXT)>;
using glNamedRenderbufferStorageEXTPtr          = std::add_pointer_t<decltype(glNamedRenderbufferStorageEXT)>;
using glGetNamedRenderbufferParameterivEXTPtr   = std::add_pointer_t<decltype(glGetNamedRenderbufferParameterivEXT)>;
using glNamedRenderbufferStorageMultisampleEXTPtr = std::add_pointer_t<
decltype(glNamedRenderbufferStorageMultisampleEXT)>;
using glNamedRenderbufferStorageMultisampleCoverageEXTPtr = std::add_pointer_t<
decltype(glNamedRenderbufferStorageMultisampleCoverageEXT)>;
using glCheckNamedFramebufferStatusEXTPtr  = std::add_pointer_t<decltype(glCheckNamedFramebufferStatusEXT)>;
using glNamedFramebufferTexture1DEXTPtr    = std::add_pointer_t<decltype(glNamedFramebufferTexture1DEXT)>;
using glNamedFramebufferTexture2DEXTPtr    = std::add_pointer_t<decltype(glNamedFramebufferTexture2DEXT)>;
using glNamedFramebufferTexture3DEXTPtr    = std::add_pointer_t<decltype(glNamedFramebufferTexture3DEXT)>;
using glNamedFramebufferRenderbufferEXTPtr = std::add_pointer_t<decltype(glNamedFramebufferRenderbufferEXT)>;
using glGetNamedFramebufferAttachmentParameterivEXTPtr = std::add_pointer_t<
decltype(glGetNamedFramebufferAttachmentParameterivEXT)>;
using glGenerateTextureMipmapEXTPtr           = std::add_pointer_t<decltype(glGenerateTextureMipmapEXT)>;
using glGenerateMultiTexMipmapEXTPtr          = std::add_pointer_t<decltype(glGenerateMultiTexMipmapEXT)>;
using glFramebufferDrawBufferEXTPtr           = std::add_pointer_t<decltype(glFramebufferDrawBufferEXT)>;
using glFramebufferDrawBuffersEXTPtr          = std::add_pointer_t<decltype(glFramebufferDrawBuffersEXT)>;
using glFramebufferReadBufferEXTPtr           = std::add_pointer_t<decltype(glFramebufferReadBufferEXT)>;
using glGetFramebufferParameterivEXTPtr       = std::add_pointer_t<decltype(glGetFramebufferParameterivEXT)>;
using glNamedCopyBufferSubDataEXTPtr          = std::add_pointer_t<decltype(glNamedCopyBufferSubDataEXT)>;
using glNamedFramebufferTextureEXTPtr         = std::add_pointer_t<decltype(glNamedFramebufferTextureEXT)>;
using glNamedFramebufferTextureLayerEXTPtr    = std::add_pointer_t<decltype(glNamedFramebufferTextureLayerEXT)>;
using glNamedFramebufferTextureFaceEXTPtr     = std::add_pointer_t<decltype(glNamedFramebufferTextureFaceEXT)>;
using glTextureRenderbufferEXTPtr             = std::add_pointer_t<decltype(glTextureRenderbufferEXT)>;
using glMultiTexRenderbufferEXTPtr            = std::add_pointer_t<decltype(glMultiTexRenderbufferEXT)>;
using glVertexArrayVertexOffsetEXTPtr         = std::add_pointer_t<decltype(glVertexArrayVertexOffsetEXT)>;
using glVertexArrayColorOffsetEXTPtr          = std::add_pointer_t<decltype(glVertexArrayColorOffsetEXT)>;
using glVertexArrayEdgeFlagOffsetEXTPtr       = std::add_pointer_t<decltype(glVertexArrayEdgeFlagOffsetEXT)>;
using glVertexArrayIndexOffsetEXTPtr          = std::add_pointer_t<decltype(glVertexArrayIndexOffsetEXT)>;
using glVertexArrayNormalOffsetEXTPtr         = std::add_pointer_t<decltype(glVertexArrayNormalOffsetEXT)>;
using glVertexArrayTexCoordOffsetEXTPtr       = std::add_pointer_t<decltype(glVertexArrayTexCoordOffsetEXT)>;
using glVertexArrayMultiTexCoordOffsetEXTPtr  = std::add_pointer_t<decltype(glVertexArrayMultiTexCoordOffsetEXT)>;
using glVertexArrayFogCoordOffsetEXTPtr       = std::add_pointer_t<decltype(glVertexArrayFogCoordOffsetEXT)>;
using glVertexArraySecondaryColorOffsetEXTPtr = std::add_pointer_t<decltype(glVertexArraySecondaryColorOffsetEXT)>;
using glVertexArrayVertexAttribOffsetEXTPtr   = std::add_pointer_t<decltype(glVertexArrayVertexAttribOffsetEXT)>;
using glVertexArrayVertexAttribIOffsetEXTPtr  = std::add_pointer_t<decltype(glVertexArrayVertexAttribIOffsetEXT)>;
using glEnableVertexArrayEXTPtr               = std::add_pointer_t<decltype(glEnableVertexArrayEXT)>;
using glDisableVertexArrayEXTPtr              = std::add_pointer_t<decltype(glDisableVertexArrayEXT)>;
using glEnableVertexArrayAttribEXTPtr         = std::add_pointer_t<decltype(glEnableVertexArrayAttribEXT)>;
using glDisableVertexArrayAttribEXTPtr        = std::add_pointer_t<decltype(glDisableVertexArrayAttribEXT)>;
using glGetVertexArrayIntegervEXTPtr          = std::add_pointer_t<decltype(glGetVertexArrayIntegervEXT)>;
using glGetVertexArrayPointervEXTPtr          = std::add_pointer_t<decltype(glGetVertexArrayPointervEXT)>;
using glGetVertexArrayIntegeri_vEXTPtr        = std::add_pointer_t<decltype(glGetVertexArrayIntegeri_vEXT)>;
using glGetVertexArrayPointeri_vEXTPtr        = std::add_pointer_t<decltype(glGetVertexArrayPointeri_vEXT)>;
using glMapNamedBufferRangeEXTPtr             = std::add_pointer_t<decltype(glMapNamedBufferRangeEXT)>;
using glFlushMappedNamedBufferRangeEXTPtr     = std::add_pointer_t<decltype(glFlushMappedNamedBufferRangeEXT)>;
using glNamedBufferStorageEXTPtr              = std::add_pointer_t<decltype(glNamedBufferStorageEXT)>;
using glClearNamedBufferDataEXTPtr            = std::add_pointer_t<decltype(glClearNamedBufferDataEXT)>;
using glClearNamedBufferSubDataEXTPtr         = std::add_pointer_t<decltype(glClearNamedBufferSubDataEXT)>;
using glNamedFramebufferParameteriEXTPtr      = std::add_pointer_t<decltype(glNamedFramebufferParameteriEXT)>;
using glGetNamedFramebufferParameterivEXTPtr  = std::add_pointer_t<decltype(glGetNamedFramebufferParameterivEXT)>;
using glProgramUniform1dEXTPtr                = std::add_pointer_t<decltype(glProgramUniform1dEXT)>;
using glProgramUniform2dEXTPtr                = std::add_pointer_t<decltype(glProgramUniform2dEXT)>;
using glProgramUniform3dEXTPtr                = std::add_pointer_t<decltype(glProgramUniform3dEXT)>;
using glProgramUniform4dEXTPtr                = std::add_pointer_t<decltype(glProgramUniform4dEXT)>;
using glProgramUniform1dvEXTPtr               = std::add_pointer_t<decltype(glProgramUniform1dvEXT)>;
using glProgramUniform2dvEXTPtr               = std::add_pointer_t<decltype(glProgramUniform2dvEXT)>;
using glProgramUniform3dvEXTPtr               = std::add_pointer_t<decltype(glProgramUniform3dvEXT)>;
using glProgramUniform4dvEXTPtr               = std::add_pointer_t<decltype(glProgramUniform4dvEXT)>;
using glProgramUniformMatrix2dvEXTPtr         = std::add_pointer_t<decltype(glProgramUniformMatrix2dvEXT)>;
using glProgramUniformMatrix3dvEXTPtr         = std::add_pointer_t<decltype(glProgramUniformMatrix3dvEXT)>;
using glProgramUniformMatrix4dvEXTPtr         = std::add_pointer_t<decltype(glProgramUniformMatrix4dvEXT)>;
using glProgramUniformMatrix2x3dvEXTPtr       = std::add_pointer_t<decltype(glProgramUniformMatrix2x3dvEXT)>;
using glProgramUniformMatrix2x4dvEXTPtr       = std::add_pointer_t<decltype(glProgramUniformMatrix2x4dvEXT)>;
using glProgramUniformMatrix3x2dvEXTPtr       = std::add_pointer_t<decltype(glProgramUniformMatrix3x2dvEXT)>;
using glProgramUniformMatrix3x4dvEXTPtr       = std::add_pointer_t<decltype(glProgramUniformMatrix3x4dvEXT)>;
using glProgramUniformMatrix4x2dvEXTPtr       = std::add_pointer_t<decltype(glProgramUniformMatrix4x2dvEXT)>;
using glProgramUniformMatrix4x3dvEXTPtr       = std::add_pointer_t<decltype(glProgramUniformMatrix4x3dvEXT)>;
using glTextureBufferRangeEXTPtr              = std::add_pointer_t<decltype(glTextureBufferRangeEXT)>;
using glTextureStorage1DEXTPtr                = std::add_pointer_t<decltype(glTextureStorage1DEXT)>;
using glTextureStorage2DEXTPtr                = std::add_pointer_t<decltype(glTextureStorage2DEXT)>;
using glTextureStorage3DEXTPtr                = std::add_pointer_t<decltype(glTextureStorage3DEXT)>;
using glTextureStorage2DMultisampleEXTPtr     = std::add_pointer_t<decltype(glTextureStorage2DMultisampleEXT)>;
using glTextureStorage3DMultisampleEXTPtr     = std::add_pointer_t<decltype(glTextureStorage3DMultisampleEXT)>;
using glVertexArrayBindVertexBufferEXTPtr     = std::add_pointer_t<decltype(glVertexArrayBindVertexBufferEXT)>;
using glVertexArrayVertexAttribFormatEXTPtr   = std::add_pointer_t<decltype(glVertexArrayVertexAttribFormatEXT)>;
using glVertexArrayVertexAttribIFormatEXTPtr  = std::add_pointer_t<decltype(glVertexArrayVertexAttribIFormatEXT)>;
using glVertexArrayVertexAttribLFormatEXTPtr  = std::add_pointer_t<decltype(glVertexArrayVertexAttribLFormatEXT)>;
using glVertexArrayVertexAttribBindingEXTPtr  = std::add_pointer_t<decltype(glVertexArrayVertexAttribBindingEXT)>;
using glVertexArrayVertexBindingDivisorEXTPtr = std::add_pointer_t<decltype(glVertexArrayVertexBindingDivisorEXT)>;
using glVertexArrayVertexAttribLOffsetEXTPtr  = std::add_pointer_t<decltype(glVertexArrayVertexAttribLOffsetEXT)>;
using glTexturePageCommitmentEXTPtr           = std::add_pointer_t<decltype(glTexturePageCommitmentEXT)>;
using glVertexArrayVertexAttribDivisorEXTPtr  = std::add_pointer_t<decltype(glVertexArrayVertexAttribDivisorEXT)>;

glMatrixLoadfEXTPtr glMatrixLoadfEXT_ptr                                                                 = nullptr;
glMatrixLoaddEXTPtr glMatrixLoaddEXT_ptr                                                                 = nullptr;
glMatrixMultfEXTPtr glMatrixMultfEXT_ptr                                                                 = nullptr;
glMatrixMultdEXTPtr glMatrixMultdEXT_ptr                                                                 = nullptr;
glMatrixLoadIdentityEXTPtr glMatrixLoadIdentityEXT_ptr                                                   = nullptr;
glMatrixRotatefEXTPtr glMatrixRotatefEXT_ptr                                                             = nullptr;
glMatrixRotatedEXTPtr glMatrixRotatedEXT_ptr                                                             = nullptr;
glMatrixScalefEXTPtr glMatrixScalefEXT_ptr                                                               = nullptr;
glMatrixScaledEXTPtr glMatrixScaledEXT_ptr                                                               = nullptr;
glMatrixTranslatefEXTPtr glMatrixTranslatefEXT_ptr                                                       = nullptr;
glMatrixTranslatedEXTPtr glMatrixTranslatedEXT_ptr                                                       = nullptr;
glMatrixFrustumEXTPtr glMatrixFrustumEXT_ptr                                                             = nullptr;
glMatrixOrthoEXTPtr glMatrixOrthoEXT_ptr                                                                 = nullptr;
glMatrixPopEXTPtr glMatrixPopEXT_ptr                                                                     = nullptr;
glMatrixPushEXTPtr glMatrixPushEXT_ptr                                                                   = nullptr;
glClientAttribDefaultEXTPtr glClientAttribDefaultEXT_ptr                                                 = nullptr;
glPushClientAttribDefaultEXTPtr glPushClientAttribDefaultEXT_ptr                                         = nullptr;
glTextureParameterfEXTPtr glTextureParameterfEXT_ptr                                                     = nullptr;
glTextureParameterfvEXTPtr glTextureParameterfvEXT_ptr                                                   = nullptr;
glTextureParameteriEXTPtr glTextureParameteriEXT_ptr                                                     = nullptr;
glTextureParameterivEXTPtr glTextureParameterivEXT_ptr                                                   = nullptr;
glTextureImage1DEXTPtr glTextureImage1DEXT_ptr                                                           = nullptr;
glTextureImage2DEXTPtr glTextureImage2DEXT_ptr                                                           = nullptr;
glTextureSubImage1DEXTPtr glTextureSubImage1DEXT_ptr                                                     = nullptr;
glTextureSubImage2DEXTPtr glTextureSubImage2DEXT_ptr                                                     = nullptr;
glCopyTextureImage1DEXTPtr glCopyTextureImage1DEXT_ptr                                                   = nullptr;
glCopyTextureImage2DEXTPtr glCopyTextureImage2DEXT_ptr                                                   = nullptr;
glCopyTextureSubImage1DEXTPtr glCopyTextureSubImage1DEXT_ptr                                             = nullptr;
glCopyTextureSubImage2DEXTPtr glCopyTextureSubImage2DEXT_ptr                                             = nullptr;
glGetTextureImageEXTPtr glGetTextureImageEXT_ptr                                                         = nullptr;
glGetTextureParameterfvEXTPtr glGetTextureParameterfvEXT_ptr                                             = nullptr;
glGetTextureParameterivEXTPtr glGetTextureParameterivEXT_ptr                                             = nullptr;
glGetTextureLevelParameterfvEXTPtr glGetTextureLevelParameterfvEXT_ptr                                   = nullptr;
glGetTextureLevelParameterivEXTPtr glGetTextureLevelParameterivEXT_ptr                                   = nullptr;
glTextureImage3DEXTPtr glTextureImage3DEXT_ptr                                                           = nullptr;
glTextureSubImage3DEXTPtr glTextureSubImage3DEXT_ptr                                                     = nullptr;
glCopyTextureSubImage3DEXTPtr glCopyTextureSubImage3DEXT_ptr                                             = nullptr;
glBindMultiTextureEXTPtr glBindMultiTextureEXT_ptr                                                       = nullptr;
glMultiTexCoordPointerEXTPtr glMultiTexCoordPointerEXT_ptr                                               = nullptr;
glMultiTexEnvfEXTPtr glMultiTexEnvfEXT_ptr                                                               = nullptr;
glMultiTexEnvfvEXTPtr glMultiTexEnvfvEXT_ptr                                                             = nullptr;
glMultiTexEnviEXTPtr glMultiTexEnviEXT_ptr                                                               = nullptr;
glMultiTexEnvivEXTPtr glMultiTexEnvivEXT_ptr                                                             = nullptr;
glMultiTexGendEXTPtr glMultiTexGendEXT_ptr                                                               = nullptr;
glMultiTexGendvEXTPtr glMultiTexGendvEXT_ptr                                                             = nullptr;
glMultiTexGenfEXTPtr glMultiTexGenfEXT_ptr                                                               = nullptr;
glMultiTexGenfvEXTPtr glMultiTexGenfvEXT_ptr                                                             = nullptr;
glMultiTexGeniEXTPtr glMultiTexGeniEXT_ptr                                                               = nullptr;
glMultiTexGenivEXTPtr glMultiTexGenivEXT_ptr                                                             = nullptr;
glGetMultiTexEnvfvEXTPtr glGetMultiTexEnvfvEXT_ptr                                                       = nullptr;
glGetMultiTexEnvivEXTPtr glGetMultiTexEnvivEXT_ptr                                                       = nullptr;
glGetMultiTexGendvEXTPtr glGetMultiTexGendvEXT_ptr                                                       = nullptr;
glGetMultiTexGenfvEXTPtr glGetMultiTexGenfvEXT_ptr                                                       = nullptr;
glGetMultiTexGenivEXTPtr glGetMultiTexGenivEXT_ptr                                                       = nullptr;
glMultiTexParameteriEXTPtr glMultiTexParameteriEXT_ptr                                                   = nullptr;
glMultiTexParameterivEXTPtr glMultiTexParameterivEXT_ptr                                                 = nullptr;
glMultiTexParameterfEXTPtr glMultiTexParameterfEXT_ptr                                                   = nullptr;
glMultiTexParameterfvEXTPtr glMultiTexParameterfvEXT_ptr                                                 = nullptr;
glMultiTexImage1DEXTPtr glMultiTexImage1DEXT_ptr                                                         = nullptr;
glMultiTexImage2DEXTPtr glMultiTexImage2DEXT_ptr                                                         = nullptr;
glMultiTexSubImage1DEXTPtr glMultiTexSubImage1DEXT_ptr                                                   = nullptr;
glMultiTexSubImage2DEXTPtr glMultiTexSubImage2DEXT_ptr                                                   = nullptr;
glCopyMultiTexImage1DEXTPtr glCopyMultiTexImage1DEXT_ptr                                                 = nullptr;
glCopyMultiTexImage2DEXTPtr glCopyMultiTexImage2DEXT_ptr                                                 = nullptr;
glCopyMultiTexSubImage1DEXTPtr glCopyMultiTexSubImage1DEXT_ptr                                           = nullptr;
glCopyMultiTexSubImage2DEXTPtr glCopyMultiTexSubImage2DEXT_ptr                                           = nullptr;
glGetMultiTexImageEXTPtr glGetMultiTexImageEXT_ptr                                                       = nullptr;
glGetMultiTexParameterfvEXTPtr glGetMultiTexParameterfvEXT_ptr                                           = nullptr;
glGetMultiTexParameterivEXTPtr glGetMultiTexParameterivEXT_ptr                                           = nullptr;
glGetMultiTexLevelParameterfvEXTPtr glGetMultiTexLevelParameterfvEXT_ptr                                 = nullptr;
glGetMultiTexLevelParameterivEXTPtr glGetMultiTexLevelParameterivEXT_ptr                                 = nullptr;
glMultiTexImage3DEXTPtr glMultiTexImage3DEXT_ptr                                                         = nullptr;
glMultiTexSubImage3DEXTPtr glMultiTexSubImage3DEXT_ptr                                                   = nullptr;
glCopyMultiTexSubImage3DEXTPtr glCopyMultiTexSubImage3DEXT_ptr                                           = nullptr;
glEnableClientStateIndexedEXTPtr glEnableClientStateIndexedEXT_ptr                                       = nullptr;
glDisableClientStateIndexedEXTPtr glDisableClientStateIndexedEXT_ptr                                     = nullptr;
glGetFloatIndexedvEXTPtr glGetFloatIndexedvEXT_ptr                                                       = nullptr;
glGetDoubleIndexedvEXTPtr glGetDoubleIndexedvEXT_ptr                                                     = nullptr;
glGetPointerIndexedvEXTPtr glGetPointerIndexedvEXT_ptr                                                   = nullptr;
glEnableIndexedEXTPtr glEnableIndexedEXT_ptr                                                             = nullptr;
glDisableIndexedEXTPtr glDisableIndexedEXT_ptr                                                           = nullptr;
glIsEnabledIndexedEXTPtr glIsEnabledIndexedEXT_ptr                                                       = nullptr;
glGetIntegerIndexedvEXTPtr glGetIntegerIndexedvEXT_ptr                                                   = nullptr;
glGetBooleanIndexedvEXTPtr glGetBooleanIndexedvEXT_ptr                                                   = nullptr;
glCompressedTextureImage3DEXTPtr glCompressedTextureImage3DEXT_ptr                                       = nullptr;
glCompressedTextureImage2DEXTPtr glCompressedTextureImage2DEXT_ptr                                       = nullptr;
glCompressedTextureImage1DEXTPtr glCompressedTextureImage1DEXT_ptr                                       = nullptr;
glCompressedTextureSubImage3DEXTPtr glCompressedTextureSubImage3DEXT_ptr                                 = nullptr;
glCompressedTextureSubImage2DEXTPtr glCompressedTextureSubImage2DEXT_ptr                                 = nullptr;
glCompressedTextureSubImage1DEXTPtr glCompressedTextureSubImage1DEXT_ptr                                 = nullptr;
glGetCompressedTextureImageEXTPtr glGetCompressedTextureImageEXT_ptr                                     = nullptr;
glCompressedMultiTexImage3DEXTPtr glCompressedMultiTexImage3DEXT_ptr                                     = nullptr;
glCompressedMultiTexImage2DEXTPtr glCompressedMultiTexImage2DEXT_ptr                                     = nullptr;
glCompressedMultiTexImage1DEXTPtr glCompressedMultiTexImage1DEXT_ptr                                     = nullptr;
glCompressedMultiTexSubImage3DEXTPtr glCompressedMultiTexSubImage3DEXT_ptr                               = nullptr;
glCompressedMultiTexSubImage2DEXTPtr glCompressedMultiTexSubImage2DEXT_ptr                               = nullptr;
glCompressedMultiTexSubImage1DEXTPtr glCompressedMultiTexSubImage1DEXT_ptr                               = nullptr;
glGetCompressedMultiTexImageEXTPtr glGetCompressedMultiTexImageEXT_ptr                                   = nullptr;
glMatrixLoadTransposefEXTPtr glMatrixLoadTransposefEXT_ptr                                               = nullptr;
glMatrixLoadTransposedEXTPtr glMatrixLoadTransposedEXT_ptr                                               = nullptr;
glMatrixMultTransposefEXTPtr glMatrixMultTransposefEXT_ptr                                               = nullptr;
glMatrixMultTransposedEXTPtr glMatrixMultTransposedEXT_ptr                                               = nullptr;
glNamedBufferDataEXTPtr glNamedBufferDataEXT_ptr                                                         = nullptr;
glNamedBufferSubDataEXTPtr glNamedBufferSubDataEXT_ptr                                                   = nullptr;
glMapNamedBufferEXTPtr glMapNamedBufferEXT_ptr                                                           = nullptr;
glUnmapNamedBufferEXTPtr glUnmapNamedBufferEXT_ptr                                                       = nullptr;
glGetNamedBufferParameterivEXTPtr glGetNamedBufferParameterivEXT_ptr                                     = nullptr;
glGetNamedBufferPointervEXTPtr glGetNamedBufferPointervEXT_ptr                                           = nullptr;
glGetNamedBufferSubDataEXTPtr glGetNamedBufferSubDataEXT_ptr                                             = nullptr;
glProgramUniform1fEXTPtr glProgramUniform1fEXT_ptr                                                       = nullptr;
glProgramUniform2fEXTPtr glProgramUniform2fEXT_ptr                                                       = nullptr;
glProgramUniform3fEXTPtr glProgramUniform3fEXT_ptr                                                       = nullptr;
glProgramUniform4fEXTPtr glProgramUniform4fEXT_ptr                                                       = nullptr;
glProgramUniform1iEXTPtr glProgramUniform1iEXT_ptr                                                       = nullptr;
glProgramUniform2iEXTPtr glProgramUniform2iEXT_ptr                                                       = nullptr;
glProgramUniform3iEXTPtr glProgramUniform3iEXT_ptr                                                       = nullptr;
glProgramUniform4iEXTPtr glProgramUniform4iEXT_ptr                                                       = nullptr;
glProgramUniform1fvEXTPtr glProgramUniform1fvEXT_ptr                                                     = nullptr;
glProgramUniform2fvEXTPtr glProgramUniform2fvEXT_ptr                                                     = nullptr;
glProgramUniform3fvEXTPtr glProgramUniform3fvEXT_ptr                                                     = nullptr;
glProgramUniform4fvEXTPtr glProgramUniform4fvEXT_ptr                                                     = nullptr;
glProgramUniform1ivEXTPtr glProgramUniform1ivEXT_ptr                                                     = nullptr;
glProgramUniform2ivEXTPtr glProgramUniform2ivEXT_ptr                                                     = nullptr;
glProgramUniform3ivEXTPtr glProgramUniform3ivEXT_ptr                                                     = nullptr;
glProgramUniform4ivEXTPtr glProgramUniform4ivEXT_ptr                                                     = nullptr;
glProgramUniformMatrix2fvEXTPtr glProgramUniformMatrix2fvEXT_ptr                                         = nullptr;
glProgramUniformMatrix3fvEXTPtr glProgramUniformMatrix3fvEXT_ptr                                         = nullptr;
glProgramUniformMatrix4fvEXTPtr glProgramUniformMatrix4fvEXT_ptr                                         = nullptr;
glProgramUniformMatrix2x3fvEXTPtr glProgramUniformMatrix2x3fvEXT_ptr                                     = nullptr;
glProgramUniformMatrix3x2fvEXTPtr glProgramUniformMatrix3x2fvEXT_ptr                                     = nullptr;
glProgramUniformMatrix2x4fvEXTPtr glProgramUniformMatrix2x4fvEXT_ptr                                     = nullptr;
glProgramUniformMatrix4x2fvEXTPtr glProgramUniformMatrix4x2fvEXT_ptr                                     = nullptr;
glProgramUniformMatrix3x4fvEXTPtr glProgramUniformMatrix3x4fvEXT_ptr                                     = nullptr;
glProgramUniformMatrix4x3fvEXTPtr glProgramUniformMatrix4x3fvEXT_ptr                                     = nullptr;
glTextureBufferEXTPtr glTextureBufferEXT_ptr                                                             = nullptr;
glMultiTexBufferEXTPtr glMultiTexBufferEXT_ptr                                                           = nullptr;
glTextureParameterIivEXTPtr glTextureParameterIivEXT_ptr                                                 = nullptr;
glTextureParameterIuivEXTPtr glTextureParameterIuivEXT_ptr                                               = nullptr;
glGetTextureParameterIivEXTPtr glGetTextureParameterIivEXT_ptr                                           = nullptr;
glGetTextureParameterIuivEXTPtr glGetTextureParameterIuivEXT_ptr                                         = nullptr;
glMultiTexParameterIivEXTPtr glMultiTexParameterIivEXT_ptr                                               = nullptr;
glMultiTexParameterIuivEXTPtr glMultiTexParameterIuivEXT_ptr                                             = nullptr;
glGetMultiTexParameterIivEXTPtr glGetMultiTexParameterIivEXT_ptr                                         = nullptr;
glGetMultiTexParameterIuivEXTPtr glGetMultiTexParameterIuivEXT_ptr                                       = nullptr;
glProgramUniform1uiEXTPtr glProgramUniform1uiEXT_ptr                                                     = nullptr;
glProgramUniform2uiEXTPtr glProgramUniform2uiEXT_ptr                                                     = nullptr;
glProgramUniform3uiEXTPtr glProgramUniform3uiEXT_ptr                                                     = nullptr;
glProgramUniform4uiEXTPtr glProgramUniform4uiEXT_ptr                                                     = nullptr;
glProgramUniform1uivEXTPtr glProgramUniform1uivEXT_ptr                                                   = nullptr;
glProgramUniform2uivEXTPtr glProgramUniform2uivEXT_ptr                                                   = nullptr;
glProgramUniform3uivEXTPtr glProgramUniform3uivEXT_ptr                                                   = nullptr;
glProgramUniform4uivEXTPtr glProgramUniform4uivEXT_ptr                                                   = nullptr;
glNamedProgramLocalParameters4fvEXTPtr glNamedProgramLocalParameters4fvEXT_ptr                           = nullptr;
glNamedProgramLocalParameterI4iEXTPtr glNamedProgramLocalParameterI4iEXT_ptr                             = nullptr;
glNamedProgramLocalParameterI4ivEXTPtr glNamedProgramLocalParameterI4ivEXT_ptr                           = nullptr;
glNamedProgramLocalParametersI4ivEXTPtr glNamedProgramLocalParametersI4ivEXT_ptr                         = nullptr;
glNamedProgramLocalParameterI4uiEXTPtr glNamedProgramLocalParameterI4uiEXT_ptr                           = nullptr;
glNamedProgramLocalParameterI4uivEXTPtr glNamedProgramLocalParameterI4uivEXT_ptr                         = nullptr;
glNamedProgramLocalParametersI4uivEXTPtr glNamedProgramLocalParametersI4uivEXT_ptr                       = nullptr;
glGetNamedProgramLocalParameterIivEXTPtr glGetNamedProgramLocalParameterIivEXT_ptr                       = nullptr;
glGetNamedProgramLocalParameterIuivEXTPtr glGetNamedProgramLocalParameterIuivEXT_ptr                     = nullptr;
glEnableClientStateiEXTPtr glEnableClientStateiEXT_ptr                                                   = nullptr;
glDisableClientStateiEXTPtr glDisableClientStateiEXT_ptr                                                 = nullptr;
glGetFloati_vEXTPtr glGetFloati_vEXT_ptr                                                                 = nullptr;
glGetDoublei_vEXTPtr glGetDoublei_vEXT_ptr                                                               = nullptr;
glGetPointeri_vEXTPtr glGetPointeri_vEXT_ptr                                                             = nullptr;
glNamedProgramStringEXTPtr glNamedProgramStringEXT_ptr                                                   = nullptr;
glNamedProgramLocalParameter4dEXTPtr glNamedProgramLocalParameter4dEXT_ptr                               = nullptr;
glNamedProgramLocalParameter4dvEXTPtr glNamedProgramLocalParameter4dvEXT_ptr                             = nullptr;
glNamedProgramLocalParameter4fEXTPtr glNamedProgramLocalParameter4fEXT_ptr                               = nullptr;
glNamedProgramLocalParameter4fvEXTPtr glNamedProgramLocalParameter4fvEXT_ptr                             = nullptr;
glGetNamedProgramLocalParameterdvEXTPtr glGetNamedProgramLocalParameterdvEXT_ptr                         = nullptr;
glGetNamedProgramLocalParameterfvEXTPtr glGetNamedProgramLocalParameterfvEXT_ptr                         = nullptr;
glGetNamedProgramivEXTPtr glGetNamedProgramivEXT_ptr                                                     = nullptr;
glGetNamedProgramStringEXTPtr glGetNamedProgramStringEXT_ptr                                             = nullptr;
glNamedRenderbufferStorageEXTPtr glNamedRenderbufferStorageEXT_ptr                                       = nullptr;
glGetNamedRenderbufferParameterivEXTPtr glGetNamedRenderbufferParameterivEXT_ptr                         = nullptr;
glNamedRenderbufferStorageMultisampleEXTPtr glNamedRenderbufferStorageMultisampleEXT_ptr                 = nullptr;
glNamedRenderbufferStorageMultisampleCoverageEXTPtr glNamedRenderbufferStorageMultisampleCoverageEXT_ptr = nullptr;
glCheckNamedFramebufferStatusEXTPtr glCheckNamedFramebufferStatusEXT_ptr                                 = nullptr;
glNamedFramebufferTexture1DEXTPtr glNamedFramebufferTexture1DEXT_ptr                                     = nullptr;
glNamedFramebufferTexture2DEXTPtr glNamedFramebufferTexture2DEXT_ptr                                     = nullptr;
glNamedFramebufferTexture3DEXTPtr glNamedFramebufferTexture3DEXT_ptr                                     = nullptr;
glNamedFramebufferRenderbufferEXTPtr glNamedFramebufferRenderbufferEXT_ptr                               = nullptr;
glGetNamedFramebufferAttachmentParameterivEXTPtr glGetNamedFramebufferAttachmentParameterivEXT_ptr       = nullptr;
glGenerateTextureMipmapEXTPtr glGenerateTextureMipmapEXT_ptr                                             = nullptr;
glGenerateMultiTexMipmapEXTPtr glGenerateMultiTexMipmapEXT_ptr                                           = nullptr;
glFramebufferDrawBufferEXTPtr glFramebufferDrawBufferEXT_ptr                                             = nullptr;
glFramebufferDrawBuffersEXTPtr glFramebufferDrawBuffersEXT_ptr                                           = nullptr;
glFramebufferReadBufferEXTPtr glFramebufferReadBufferEXT_ptr                                             = nullptr;
glGetFramebufferParameterivEXTPtr glGetFramebufferParameterivEXT_ptr                                     = nullptr;
glNamedCopyBufferSubDataEXTPtr glNamedCopyBufferSubDataEXT_ptr                                           = nullptr;
glNamedFramebufferTextureEXTPtr glNamedFramebufferTextureEXT_ptr                                         = nullptr;
glNamedFramebufferTextureLayerEXTPtr glNamedFramebufferTextureLayerEXT_ptr                               = nullptr;
glNamedFramebufferTextureFaceEXTPtr glNamedFramebufferTextureFaceEXT_ptr                                 = nullptr;
glTextureRenderbufferEXTPtr glTextureRenderbufferEXT_ptr                                                 = nullptr;
glMultiTexRenderbufferEXTPtr glMultiTexRenderbufferEXT_ptr                                               = nullptr;
glVertexArrayVertexOffsetEXTPtr glVertexArrayVertexOffsetEXT_ptr                                         = nullptr;
glVertexArrayColorOffsetEXTPtr glVertexArrayColorOffsetEXT_ptr                                           = nullptr;
glVertexArrayEdgeFlagOffsetEXTPtr glVertexArrayEdgeFlagOffsetEXT_ptr                                     = nullptr;
glVertexArrayIndexOffsetEXTPtr glVertexArrayIndexOffsetEXT_ptr                                           = nullptr;
glVertexArrayNormalOffsetEXTPtr glVertexArrayNormalOffsetEXT_ptr                                         = nullptr;
glVertexArrayTexCoordOffsetEXTPtr glVertexArrayTexCoordOffsetEXT_ptr                                     = nullptr;
glVertexArrayMultiTexCoordOffsetEXTPtr glVertexArrayMultiTexCoordOffsetEXT_ptr                           = nullptr;
glVertexArrayFogCoordOffsetEXTPtr glVertexArrayFogCoordOffsetEXT_ptr                                     = nullptr;
glVertexArraySecondaryColorOffsetEXTPtr glVertexArraySecondaryColorOffsetEXT_ptr                         = nullptr;
glVertexArrayVertexAttribOffsetEXTPtr glVertexArrayVertexAttribOffsetEXT_ptr                             = nullptr;
glVertexArrayVertexAttribIOffsetEXTPtr glVertexArrayVertexAttribIOffsetEXT_ptr                           = nullptr;
glEnableVertexArrayEXTPtr glEnableVertexArrayEXT_ptr                                                     = nullptr;
glDisableVertexArrayEXTPtr glDisableVertexArrayEXT_ptr                                                   = nullptr;
glEnableVertexArrayAttribEXTPtr glEnableVertexArrayAttribEXT_ptr                                         = nullptr;
glDisableVertexArrayAttribEXTPtr glDisableVertexArrayAttribEXT_ptr                                       = nullptr;
glGetVertexArrayIntegervEXTPtr glGetVertexArrayIntegervEXT_ptr                                           = nullptr;
glGetVertexArrayPointervEXTPtr glGetVertexArrayPointervEXT_ptr                                           = nullptr;
glGetVertexArrayIntegeri_vEXTPtr glGetVertexArrayIntegeri_vEXT_ptr                                       = nullptr;
glGetVertexArrayPointeri_vEXTPtr glGetVertexArrayPointeri_vEXT_ptr                                       = nullptr;
glMapNamedBufferRangeEXTPtr glMapNamedBufferRangeEXT_ptr                                                 = nullptr;
glFlushMappedNamedBufferRangeEXTPtr glFlushMappedNamedBufferRangeEXT_ptr                                 = nullptr;
glNamedBufferStorageEXTPtr glNamedBufferStorageEXT_ptr                                                   = nullptr;
glClearNamedBufferDataEXTPtr glClearNamedBufferDataEXT_ptr                                               = nullptr;
glClearNamedBufferSubDataEXTPtr glClearNamedBufferSubDataEXT_ptr                                         = nullptr;
glNamedFramebufferParameteriEXTPtr glNamedFramebufferParameteriEXT_ptr                                   = nullptr;
glGetNamedFramebufferParameterivEXTPtr glGetNamedFramebufferParameterivEXT_ptr                           = nullptr;
glProgramUniform1dEXTPtr glProgramUniform1dEXT_ptr                                                       = nullptr;
glProgramUniform2dEXTPtr glProgramUniform2dEXT_ptr                                                       = nullptr;
glProgramUniform3dEXTPtr glProgramUniform3dEXT_ptr                                                       = nullptr;
glProgramUniform4dEXTPtr glProgramUniform4dEXT_ptr                                                       = nullptr;
glProgramUniform1dvEXTPtr glProgramUniform1dvEXT_ptr                                                     = nullptr;
glProgramUniform2dvEXTPtr glProgramUniform2dvEXT_ptr                                                     = nullptr;
glProgramUniform3dvEXTPtr glProgramUniform3dvEXT_ptr                                                     = nullptr;
glProgramUniform4dvEXTPtr glProgramUniform4dvEXT_ptr                                                     = nullptr;
glProgramUniformMatrix2dvEXTPtr glProgramUniformMatrix2dvEXT_ptr                                         = nullptr;
glProgramUniformMatrix3dvEXTPtr glProgramUniformMatrix3dvEXT_ptr                                         = nullptr;
glProgramUniformMatrix4dvEXTPtr glProgramUniformMatrix4dvEXT_ptr                                         = nullptr;
glProgramUniformMatrix2x3dvEXTPtr glProgramUniformMatrix2x3dvEXT_ptr                                     = nullptr;
glProgramUniformMatrix2x4dvEXTPtr glProgramUniformMatrix2x4dvEXT_ptr                                     = nullptr;
glProgramUniformMatrix3x2dvEXTPtr glProgramUniformMatrix3x2dvEXT_ptr                                     = nullptr;
glProgramUniformMatrix3x4dvEXTPtr glProgramUniformMatrix3x4dvEXT_ptr                                     = nullptr;
glProgramUniformMatrix4x2dvEXTPtr glProgramUniformMatrix4x2dvEXT_ptr                                     = nullptr;
glProgramUniformMatrix4x3dvEXTPtr glProgramUniformMatrix4x3dvEXT_ptr                                     = nullptr;
glTextureBufferRangeEXTPtr glTextureBufferRangeEXT_ptr                                                   = nullptr;
glTextureStorage1DEXTPtr glTextureStorage1DEXT_ptr                                                       = nullptr;
glTextureStorage2DEXTPtr glTextureStorage2DEXT_ptr                                                       = nullptr;
glTextureStorage3DEXTPtr glTextureStorage3DEXT_ptr                                                       = nullptr;
glTextureStorage2DMultisampleEXTPtr glTextureStorage2DMultisampleEXT_ptr                                 = nullptr;
glTextureStorage3DMultisampleEXTPtr glTextureStorage3DMultisampleEXT_ptr                                 = nullptr;
glVertexArrayBindVertexBufferEXTPtr glVertexArrayBindVertexBufferEXT_ptr                                 = nullptr;
glVertexArrayVertexAttribFormatEXTPtr glVertexArrayVertexAttribFormatEXT_ptr                             = nullptr;
glVertexArrayVertexAttribIFormatEXTPtr glVertexArrayVertexAttribIFormatEXT_ptr                           = nullptr;
glVertexArrayVertexAttribLFormatEXTPtr glVertexArrayVertexAttribLFormatEXT_ptr                           = nullptr;
glVertexArrayVertexAttribBindingEXTPtr glVertexArrayVertexAttribBindingEXT_ptr                           = nullptr;
glVertexArrayVertexBindingDivisorEXTPtr glVertexArrayVertexBindingDivisorEXT_ptr                         = nullptr;
glVertexArrayVertexAttribLOffsetEXTPtr glVertexArrayVertexAttribLOffsetEXT_ptr                           = nullptr;
glTexturePageCommitmentEXTPtr glTexturePageCommitmentEXT_ptr                                             = nullptr;
glVertexArrayVertexAttribDivisorEXTPtr glVertexArrayVertexAttribDivisorEXT_ptr                           = nullptr;

bool init_gl_ext_direct_state_access([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glMatrixLoadfEXT_ptr = reinterpret_cast<glMatrixLoadfEXTPtr>(get_function("glMatrixLoadfEXT"))) == nullptr || result;
    result = (glMatrixLoaddEXT_ptr = reinterpret_cast<glMatrixLoaddEXTPtr>(get_function("glMatrixLoaddEXT"))) == nullptr || result;
    result = (glMatrixMultfEXT_ptr = reinterpret_cast<glMatrixMultfEXTPtr>(get_function("glMatrixMultfEXT"))) == nullptr || result;
    result = (glMatrixMultdEXT_ptr = reinterpret_cast<glMatrixMultdEXTPtr>(get_function("glMatrixMultdEXT"))) == nullptr || result;
    result = (glMatrixLoadIdentityEXT_ptr = reinterpret_cast<glMatrixLoadIdentityEXTPtr>(get_function("glMatrixLoadIdentityEXT"))) == nullptr || result;
    result = (glMatrixRotatefEXT_ptr = reinterpret_cast<glMatrixRotatefEXTPtr>(get_function("glMatrixRotatefEXT"))) == nullptr || result;
    result = (glMatrixRotatedEXT_ptr = reinterpret_cast<glMatrixRotatedEXTPtr>(get_function("glMatrixRotatedEXT"))) == nullptr || result;
    result = (glMatrixScalefEXT_ptr = reinterpret_cast<glMatrixScalefEXTPtr>(get_function("glMatrixScalefEXT"))) == nullptr || result;
    result = (glMatrixScaledEXT_ptr = reinterpret_cast<glMatrixScaledEXTPtr>(get_function("glMatrixScaledEXT"))) == nullptr || result;
    result = (glMatrixTranslatefEXT_ptr = reinterpret_cast<glMatrixTranslatefEXTPtr>(get_function("glMatrixTranslatefEXT"))) == nullptr || result;
    result = (glMatrixTranslatedEXT_ptr = reinterpret_cast<glMatrixTranslatedEXTPtr>(get_function("glMatrixTranslatedEXT"))) == nullptr || result;
    result = (glMatrixFrustumEXT_ptr = reinterpret_cast<glMatrixFrustumEXTPtr>(get_function("glMatrixFrustumEXT"))) == nullptr || result;
    result = (glMatrixOrthoEXT_ptr = reinterpret_cast<glMatrixOrthoEXTPtr>(get_function("glMatrixOrthoEXT"))) == nullptr || result;
    result = (glMatrixPopEXT_ptr = reinterpret_cast<glMatrixPopEXTPtr>(get_function("glMatrixPopEXT"))) == nullptr || result;
    result = (glMatrixPushEXT_ptr = reinterpret_cast<glMatrixPushEXTPtr>(get_function("glMatrixPushEXT"))) == nullptr || result;
    result = (glClientAttribDefaultEXT_ptr = reinterpret_cast<glClientAttribDefaultEXTPtr>(get_function("glClientAttribDefaultEXT"))) == nullptr || result;
    result = (glPushClientAttribDefaultEXT_ptr = reinterpret_cast<glPushClientAttribDefaultEXTPtr>(get_function("glPushClientAttribDefaultEXT"))) == nullptr || result;
    result = (glTextureParameterfEXT_ptr = reinterpret_cast<glTextureParameterfEXTPtr>(get_function("glTextureParameterfEXT"))) == nullptr || result;
    result = (glTextureParameterfvEXT_ptr = reinterpret_cast<glTextureParameterfvEXTPtr>(get_function("glTextureParameterfvEXT"))) == nullptr || result;
    result = (glTextureParameteriEXT_ptr = reinterpret_cast<glTextureParameteriEXTPtr>(get_function("glTextureParameteriEXT"))) == nullptr || result;
    result = (glTextureParameterivEXT_ptr = reinterpret_cast<glTextureParameterivEXTPtr>(get_function("glTextureParameterivEXT"))) == nullptr || result;
    result = (glTextureImage1DEXT_ptr = reinterpret_cast<glTextureImage1DEXTPtr>(get_function("glTextureImage1DEXT"))) == nullptr || result;
    result = (glTextureImage2DEXT_ptr = reinterpret_cast<glTextureImage2DEXTPtr>(get_function("glTextureImage2DEXT"))) == nullptr || result;
    result = (glTextureSubImage1DEXT_ptr = reinterpret_cast<glTextureSubImage1DEXTPtr>(get_function("glTextureSubImage1DEXT"))) == nullptr || result;
    result = (glTextureSubImage2DEXT_ptr = reinterpret_cast<glTextureSubImage2DEXTPtr>(get_function("glTextureSubImage2DEXT"))) == nullptr || result;
    result = (glCopyTextureImage1DEXT_ptr = reinterpret_cast<glCopyTextureImage1DEXTPtr>(get_function("glCopyTextureImage1DEXT"))) == nullptr || result;
    result = (glCopyTextureImage2DEXT_ptr = reinterpret_cast<glCopyTextureImage2DEXTPtr>(get_function("glCopyTextureImage2DEXT"))) == nullptr || result;
    result = (glCopyTextureSubImage1DEXT_ptr = reinterpret_cast<glCopyTextureSubImage1DEXTPtr>(get_function("glCopyTextureSubImage1DEXT"))) == nullptr || result;
    result = (glCopyTextureSubImage2DEXT_ptr = reinterpret_cast<glCopyTextureSubImage2DEXTPtr>(get_function("glCopyTextureSubImage2DEXT"))) == nullptr || result;
    result = (glGetTextureImageEXT_ptr = reinterpret_cast<glGetTextureImageEXTPtr>(get_function("glGetTextureImageEXT"))) == nullptr || result;
    result = (glGetTextureParameterfvEXT_ptr = reinterpret_cast<glGetTextureParameterfvEXTPtr>(get_function("glGetTextureParameterfvEXT"))) == nullptr || result;
    result = (glGetTextureParameterivEXT_ptr = reinterpret_cast<glGetTextureParameterivEXTPtr>(get_function("glGetTextureParameterivEXT"))) == nullptr || result;
    result = (glGetTextureLevelParameterfvEXT_ptr = reinterpret_cast<glGetTextureLevelParameterfvEXTPtr>(get_function("glGetTextureLevelParameterfvEXT"))) == nullptr || result;
    result = (glGetTextureLevelParameterivEXT_ptr = reinterpret_cast<glGetTextureLevelParameterivEXTPtr>(get_function("glGetTextureLevelParameterivEXT"))) == nullptr || result;
    result = (glTextureImage3DEXT_ptr = reinterpret_cast<glTextureImage3DEXTPtr>(get_function("glTextureImage3DEXT"))) == nullptr || result;
    result = (glTextureSubImage3DEXT_ptr = reinterpret_cast<glTextureSubImage3DEXTPtr>(get_function("glTextureSubImage3DEXT"))) == nullptr || result;
    result = (glCopyTextureSubImage3DEXT_ptr = reinterpret_cast<glCopyTextureSubImage3DEXTPtr>(get_function("glCopyTextureSubImage3DEXT"))) == nullptr || result;
    result = (glBindMultiTextureEXT_ptr = reinterpret_cast<glBindMultiTextureEXTPtr>(get_function("glBindMultiTextureEXT"))) == nullptr || result;
    result = (glMultiTexCoordPointerEXT_ptr = reinterpret_cast<glMultiTexCoordPointerEXTPtr>(get_function("glMultiTexCoordPointerEXT"))) == nullptr || result;
    result = (glMultiTexEnvfEXT_ptr = reinterpret_cast<glMultiTexEnvfEXTPtr>(get_function("glMultiTexEnvfEXT"))) == nullptr || result;
    result = (glMultiTexEnvfvEXT_ptr = reinterpret_cast<glMultiTexEnvfvEXTPtr>(get_function("glMultiTexEnvfvEXT"))) == nullptr || result;
    result = (glMultiTexEnviEXT_ptr = reinterpret_cast<glMultiTexEnviEXTPtr>(get_function("glMultiTexEnviEXT"))) == nullptr || result;
    result = (glMultiTexEnvivEXT_ptr = reinterpret_cast<glMultiTexEnvivEXTPtr>(get_function("glMultiTexEnvivEXT"))) == nullptr || result;
    result = (glMultiTexGendEXT_ptr = reinterpret_cast<glMultiTexGendEXTPtr>(get_function("glMultiTexGendEXT"))) == nullptr || result;
    result = (glMultiTexGendvEXT_ptr = reinterpret_cast<glMultiTexGendvEXTPtr>(get_function("glMultiTexGendvEXT"))) == nullptr || result;
    result = (glMultiTexGenfEXT_ptr = reinterpret_cast<glMultiTexGenfEXTPtr>(get_function("glMultiTexGenfEXT"))) == nullptr || result;
    result = (glMultiTexGenfvEXT_ptr = reinterpret_cast<glMultiTexGenfvEXTPtr>(get_function("glMultiTexGenfvEXT"))) == nullptr || result;
    result = (glMultiTexGeniEXT_ptr = reinterpret_cast<glMultiTexGeniEXTPtr>(get_function("glMultiTexGeniEXT"))) == nullptr || result;
    result = (glMultiTexGenivEXT_ptr = reinterpret_cast<glMultiTexGenivEXTPtr>(get_function("glMultiTexGenivEXT"))) == nullptr || result;
    result = (glGetMultiTexEnvfvEXT_ptr = reinterpret_cast<glGetMultiTexEnvfvEXTPtr>(get_function("glGetMultiTexEnvfvEXT"))) == nullptr || result;
    result = (glGetMultiTexEnvivEXT_ptr = reinterpret_cast<glGetMultiTexEnvivEXTPtr>(get_function("glGetMultiTexEnvivEXT"))) == nullptr || result;
    result = (glGetMultiTexGendvEXT_ptr = reinterpret_cast<glGetMultiTexGendvEXTPtr>(get_function("glGetMultiTexGendvEXT"))) == nullptr || result;
    result = (glGetMultiTexGenfvEXT_ptr = reinterpret_cast<glGetMultiTexGenfvEXTPtr>(get_function("glGetMultiTexGenfvEXT"))) == nullptr || result;
    result = (glGetMultiTexGenivEXT_ptr = reinterpret_cast<glGetMultiTexGenivEXTPtr>(get_function("glGetMultiTexGenivEXT"))) == nullptr || result;
    result = (glMultiTexParameteriEXT_ptr = reinterpret_cast<glMultiTexParameteriEXTPtr>(get_function("glMultiTexParameteriEXT"))) == nullptr || result;
    result = (glMultiTexParameterivEXT_ptr = reinterpret_cast<glMultiTexParameterivEXTPtr>(get_function("glMultiTexParameterivEXT"))) == nullptr || result;
    result = (glMultiTexParameterfEXT_ptr = reinterpret_cast<glMultiTexParameterfEXTPtr>(get_function("glMultiTexParameterfEXT"))) == nullptr || result;
    result = (glMultiTexParameterfvEXT_ptr = reinterpret_cast<glMultiTexParameterfvEXTPtr>(get_function("glMultiTexParameterfvEXT"))) == nullptr || result;
    result = (glMultiTexImage1DEXT_ptr = reinterpret_cast<glMultiTexImage1DEXTPtr>(get_function("glMultiTexImage1DEXT"))) == nullptr || result;
    result = (glMultiTexImage2DEXT_ptr = reinterpret_cast<glMultiTexImage2DEXTPtr>(get_function("glMultiTexImage2DEXT"))) == nullptr || result;
    result = (glMultiTexSubImage1DEXT_ptr = reinterpret_cast<glMultiTexSubImage1DEXTPtr>(get_function("glMultiTexSubImage1DEXT"))) == nullptr || result;
    result = (glMultiTexSubImage2DEXT_ptr = reinterpret_cast<glMultiTexSubImage2DEXTPtr>(get_function("glMultiTexSubImage2DEXT"))) == nullptr || result;
    result = (glCopyMultiTexImage1DEXT_ptr = reinterpret_cast<glCopyMultiTexImage1DEXTPtr>(get_function("glCopyMultiTexImage1DEXT"))) == nullptr || result;
    result = (glCopyMultiTexImage2DEXT_ptr = reinterpret_cast<glCopyMultiTexImage2DEXTPtr>(get_function("glCopyMultiTexImage2DEXT"))) == nullptr || result;
    result = (glCopyMultiTexSubImage1DEXT_ptr = reinterpret_cast<glCopyMultiTexSubImage1DEXTPtr>(get_function("glCopyMultiTexSubImage1DEXT"))) == nullptr || result;
    result = (glCopyMultiTexSubImage2DEXT_ptr = reinterpret_cast<glCopyMultiTexSubImage2DEXTPtr>(get_function("glCopyMultiTexSubImage2DEXT"))) == nullptr || result;
    result = (glGetMultiTexImageEXT_ptr = reinterpret_cast<glGetMultiTexImageEXTPtr>(get_function("glGetMultiTexImageEXT"))) == nullptr || result;
    result = (glGetMultiTexParameterfvEXT_ptr = reinterpret_cast<glGetMultiTexParameterfvEXTPtr>(get_function("glGetMultiTexParameterfvEXT"))) == nullptr || result;
    result = (glGetMultiTexParameterivEXT_ptr = reinterpret_cast<glGetMultiTexParameterivEXTPtr>(get_function("glGetMultiTexParameterivEXT"))) == nullptr || result;
    result = (glGetMultiTexLevelParameterfvEXT_ptr = reinterpret_cast<glGetMultiTexLevelParameterfvEXTPtr>(get_function("glGetMultiTexLevelParameterfvEXT"))) == nullptr || result;
    result = (glGetMultiTexLevelParameterivEXT_ptr = reinterpret_cast<glGetMultiTexLevelParameterivEXTPtr>(get_function("glGetMultiTexLevelParameterivEXT"))) == nullptr || result;
    result = (glMultiTexImage3DEXT_ptr = reinterpret_cast<glMultiTexImage3DEXTPtr>(get_function("glMultiTexImage3DEXT"))) == nullptr || result;
    result = (glMultiTexSubImage3DEXT_ptr = reinterpret_cast<glMultiTexSubImage3DEXTPtr>(get_function("glMultiTexSubImage3DEXT"))) == nullptr || result;
    result = (glCopyMultiTexSubImage3DEXT_ptr = reinterpret_cast<glCopyMultiTexSubImage3DEXTPtr>(get_function("glCopyMultiTexSubImage3DEXT"))) == nullptr || result;
    result = (glEnableClientStateIndexedEXT_ptr = reinterpret_cast<glEnableClientStateIndexedEXTPtr>(get_function("glEnableClientStateIndexedEXT"))) == nullptr || result;
    result = (glDisableClientStateIndexedEXT_ptr = reinterpret_cast<glDisableClientStateIndexedEXTPtr>(get_function("glDisableClientStateIndexedEXT"))) == nullptr || result;
    result = (glGetFloatIndexedvEXT_ptr = reinterpret_cast<glGetFloatIndexedvEXTPtr>(get_function("glGetFloatIndexedvEXT"))) == nullptr || result;
    result = (glGetDoubleIndexedvEXT_ptr = reinterpret_cast<glGetDoubleIndexedvEXTPtr>(get_function("glGetDoubleIndexedvEXT"))) == nullptr || result;
    result = (glGetPointerIndexedvEXT_ptr = reinterpret_cast<glGetPointerIndexedvEXTPtr>(get_function("glGetPointerIndexedvEXT"))) == nullptr || result;
    result = (glEnableIndexedEXT_ptr = reinterpret_cast<glEnableIndexedEXTPtr>(get_function("glEnableIndexedEXT"))) == nullptr || result;
    result = (glDisableIndexedEXT_ptr = reinterpret_cast<glDisableIndexedEXTPtr>(get_function("glDisableIndexedEXT"))) == nullptr || result;
    result = (glIsEnabledIndexedEXT_ptr = reinterpret_cast<glIsEnabledIndexedEXTPtr>(get_function("glIsEnabledIndexedEXT"))) == nullptr || result;
    result = (glGetIntegerIndexedvEXT_ptr = reinterpret_cast<glGetIntegerIndexedvEXTPtr>(get_function("glGetIntegerIndexedvEXT"))) == nullptr || result;
    result = (glGetBooleanIndexedvEXT_ptr = reinterpret_cast<glGetBooleanIndexedvEXTPtr>(get_function("glGetBooleanIndexedvEXT"))) == nullptr || result;
    result = (glCompressedTextureImage3DEXT_ptr = reinterpret_cast<glCompressedTextureImage3DEXTPtr>(get_function("glCompressedTextureImage3DEXT"))) == nullptr || result;
    result = (glCompressedTextureImage2DEXT_ptr = reinterpret_cast<glCompressedTextureImage2DEXTPtr>(get_function("glCompressedTextureImage2DEXT"))) == nullptr || result;
    result = (glCompressedTextureImage1DEXT_ptr = reinterpret_cast<glCompressedTextureImage1DEXTPtr>(get_function("glCompressedTextureImage1DEXT"))) == nullptr || result;
    result = (glCompressedTextureSubImage3DEXT_ptr = reinterpret_cast<glCompressedTextureSubImage3DEXTPtr>(get_function("glCompressedTextureSubImage3DEXT"))) == nullptr || result;
    result = (glCompressedTextureSubImage2DEXT_ptr = reinterpret_cast<glCompressedTextureSubImage2DEXTPtr>(get_function("glCompressedTextureSubImage2DEXT"))) == nullptr || result;
    result = (glCompressedTextureSubImage1DEXT_ptr = reinterpret_cast<glCompressedTextureSubImage1DEXTPtr>(get_function("glCompressedTextureSubImage1DEXT"))) == nullptr || result;
    result = (glGetCompressedTextureImageEXT_ptr = reinterpret_cast<glGetCompressedTextureImageEXTPtr>(get_function("glGetCompressedTextureImageEXT"))) == nullptr || result;
    result = (glCompressedMultiTexImage3DEXT_ptr = reinterpret_cast<glCompressedMultiTexImage3DEXTPtr>(get_function("glCompressedMultiTexImage3DEXT"))) == nullptr || result;
    result = (glCompressedMultiTexImage2DEXT_ptr = reinterpret_cast<glCompressedMultiTexImage2DEXTPtr>(get_function("glCompressedMultiTexImage2DEXT"))) == nullptr || result;
    result = (glCompressedMultiTexImage1DEXT_ptr = reinterpret_cast<glCompressedMultiTexImage1DEXTPtr>(get_function("glCompressedMultiTexImage1DEXT"))) == nullptr || result;
    result = (glCompressedMultiTexSubImage3DEXT_ptr = reinterpret_cast<glCompressedMultiTexSubImage3DEXTPtr>(get_function("glCompressedMultiTexSubImage3DEXT"))) == nullptr || result;
    result = (glCompressedMultiTexSubImage2DEXT_ptr = reinterpret_cast<glCompressedMultiTexSubImage2DEXTPtr>(get_function("glCompressedMultiTexSubImage2DEXT"))) == nullptr || result;
    result = (glCompressedMultiTexSubImage1DEXT_ptr = reinterpret_cast<glCompressedMultiTexSubImage1DEXTPtr>(get_function("glCompressedMultiTexSubImage1DEXT"))) == nullptr || result;
    result = (glGetCompressedMultiTexImageEXT_ptr = reinterpret_cast<glGetCompressedMultiTexImageEXTPtr>(get_function("glGetCompressedMultiTexImageEXT"))) == nullptr || result;
    result = (glMatrixLoadTransposefEXT_ptr = reinterpret_cast<glMatrixLoadTransposefEXTPtr>(get_function("glMatrixLoadTransposefEXT"))) == nullptr || result;
    result = (glMatrixLoadTransposedEXT_ptr = reinterpret_cast<glMatrixLoadTransposedEXTPtr>(get_function("glMatrixLoadTransposedEXT"))) == nullptr || result;
    result = (glMatrixMultTransposefEXT_ptr = reinterpret_cast<glMatrixMultTransposefEXTPtr>(get_function("glMatrixMultTransposefEXT"))) == nullptr || result;
    result = (glMatrixMultTransposedEXT_ptr = reinterpret_cast<glMatrixMultTransposedEXTPtr>(get_function("glMatrixMultTransposedEXT"))) == nullptr || result;
    result = (glNamedBufferDataEXT_ptr = reinterpret_cast<glNamedBufferDataEXTPtr>(get_function("glNamedBufferDataEXT"))) == nullptr || result;
    result = (glNamedBufferSubDataEXT_ptr = reinterpret_cast<glNamedBufferSubDataEXTPtr>(get_function("glNamedBufferSubDataEXT"))) == nullptr || result;
    result = (glMapNamedBufferEXT_ptr = reinterpret_cast<glMapNamedBufferEXTPtr>(get_function("glMapNamedBufferEXT"))) == nullptr || result;
    result = (glUnmapNamedBufferEXT_ptr = reinterpret_cast<glUnmapNamedBufferEXTPtr>(get_function("glUnmapNamedBufferEXT"))) == nullptr || result;
    result = (glGetNamedBufferParameterivEXT_ptr = reinterpret_cast<glGetNamedBufferParameterivEXTPtr>(get_function("glGetNamedBufferParameterivEXT"))) == nullptr || result;
    result = (glGetNamedBufferPointervEXT_ptr = reinterpret_cast<glGetNamedBufferPointervEXTPtr>(get_function("glGetNamedBufferPointervEXT"))) == nullptr || result;
    result = (glGetNamedBufferSubDataEXT_ptr = reinterpret_cast<glGetNamedBufferSubDataEXTPtr>(get_function("glGetNamedBufferSubDataEXT"))) == nullptr || result;
    result = (glProgramUniform1fEXT_ptr = reinterpret_cast<glProgramUniform1fEXTPtr>(get_function("glProgramUniform1fEXT"))) == nullptr || result;
    result = (glProgramUniform2fEXT_ptr = reinterpret_cast<glProgramUniform2fEXTPtr>(get_function("glProgramUniform2fEXT"))) == nullptr || result;
    result = (glProgramUniform3fEXT_ptr = reinterpret_cast<glProgramUniform3fEXTPtr>(get_function("glProgramUniform3fEXT"))) == nullptr || result;
    result = (glProgramUniform4fEXT_ptr = reinterpret_cast<glProgramUniform4fEXTPtr>(get_function("glProgramUniform4fEXT"))) == nullptr || result;
    result = (glProgramUniform1iEXT_ptr = reinterpret_cast<glProgramUniform1iEXTPtr>(get_function("glProgramUniform1iEXT"))) == nullptr || result;
    result = (glProgramUniform2iEXT_ptr = reinterpret_cast<glProgramUniform2iEXTPtr>(get_function("glProgramUniform2iEXT"))) == nullptr || result;
    result = (glProgramUniform3iEXT_ptr = reinterpret_cast<glProgramUniform3iEXTPtr>(get_function("glProgramUniform3iEXT"))) == nullptr || result;
    result = (glProgramUniform4iEXT_ptr = reinterpret_cast<glProgramUniform4iEXTPtr>(get_function("glProgramUniform4iEXT"))) == nullptr || result;
    result = (glProgramUniform1fvEXT_ptr = reinterpret_cast<glProgramUniform1fvEXTPtr>(get_function("glProgramUniform1fvEXT"))) == nullptr || result;
    result = (glProgramUniform2fvEXT_ptr = reinterpret_cast<glProgramUniform2fvEXTPtr>(get_function("glProgramUniform2fvEXT"))) == nullptr || result;
    result = (glProgramUniform3fvEXT_ptr = reinterpret_cast<glProgramUniform3fvEXTPtr>(get_function("glProgramUniform3fvEXT"))) == nullptr || result;
    result = (glProgramUniform4fvEXT_ptr = reinterpret_cast<glProgramUniform4fvEXTPtr>(get_function("glProgramUniform4fvEXT"))) == nullptr || result;
    result = (glProgramUniform1ivEXT_ptr = reinterpret_cast<glProgramUniform1ivEXTPtr>(get_function("glProgramUniform1ivEXT"))) == nullptr || result;
    result = (glProgramUniform2ivEXT_ptr = reinterpret_cast<glProgramUniform2ivEXTPtr>(get_function("glProgramUniform2ivEXT"))) == nullptr || result;
    result = (glProgramUniform3ivEXT_ptr = reinterpret_cast<glProgramUniform3ivEXTPtr>(get_function("glProgramUniform3ivEXT"))) == nullptr || result;
    result = (glProgramUniform4ivEXT_ptr = reinterpret_cast<glProgramUniform4ivEXTPtr>(get_function("glProgramUniform4ivEXT"))) == nullptr || result;
    result = (glProgramUniformMatrix2fvEXT_ptr = reinterpret_cast<glProgramUniformMatrix2fvEXTPtr>(get_function("glProgramUniformMatrix2fvEXT"))) == nullptr || result;
    result = (glProgramUniformMatrix3fvEXT_ptr = reinterpret_cast<glProgramUniformMatrix3fvEXTPtr>(get_function("glProgramUniformMatrix3fvEXT"))) == nullptr || result;
    result = (glProgramUniformMatrix4fvEXT_ptr = reinterpret_cast<glProgramUniformMatrix4fvEXTPtr>(get_function("glProgramUniformMatrix4fvEXT"))) == nullptr || result;
    result = (glProgramUniformMatrix2x3fvEXT_ptr = reinterpret_cast<glProgramUniformMatrix2x3fvEXTPtr>(get_function("glProgramUniformMatrix2x3fvEXT"))) == nullptr || result;
    result = (glProgramUniformMatrix3x2fvEXT_ptr = reinterpret_cast<glProgramUniformMatrix3x2fvEXTPtr>(get_function("glProgramUniformMatrix3x2fvEXT"))) == nullptr || result;
    result = (glProgramUniformMatrix2x4fvEXT_ptr = reinterpret_cast<glProgramUniformMatrix2x4fvEXTPtr>(get_function("glProgramUniformMatrix2x4fvEXT"))) == nullptr || result;
    result = (glProgramUniformMatrix4x2fvEXT_ptr = reinterpret_cast<glProgramUniformMatrix4x2fvEXTPtr>(get_function("glProgramUniformMatrix4x2fvEXT"))) == nullptr || result;
    result = (glProgramUniformMatrix3x4fvEXT_ptr = reinterpret_cast<glProgramUniformMatrix3x4fvEXTPtr>(get_function("glProgramUniformMatrix3x4fvEXT"))) == nullptr || result;
    result = (glProgramUniformMatrix4x3fvEXT_ptr = reinterpret_cast<glProgramUniformMatrix4x3fvEXTPtr>(get_function("glProgramUniformMatrix4x3fvEXT"))) == nullptr || result;
    result = (glTextureBufferEXT_ptr = reinterpret_cast<glTextureBufferEXTPtr>(get_function("glTextureBufferEXT"))) == nullptr || result;
    result = (glMultiTexBufferEXT_ptr = reinterpret_cast<glMultiTexBufferEXTPtr>(get_function("glMultiTexBufferEXT"))) == nullptr || result;
    result = (glTextureParameterIivEXT_ptr = reinterpret_cast<glTextureParameterIivEXTPtr>(get_function("glTextureParameterIivEXT"))) == nullptr || result;
    result = (glTextureParameterIuivEXT_ptr = reinterpret_cast<glTextureParameterIuivEXTPtr>(get_function("glTextureParameterIuivEXT"))) == nullptr || result;
    result = (glGetTextureParameterIivEXT_ptr = reinterpret_cast<glGetTextureParameterIivEXTPtr>(get_function("glGetTextureParameterIivEXT"))) == nullptr || result;
    result = (glGetTextureParameterIuivEXT_ptr = reinterpret_cast<glGetTextureParameterIuivEXTPtr>(get_function("glGetTextureParameterIuivEXT"))) == nullptr || result;
    result = (glMultiTexParameterIivEXT_ptr = reinterpret_cast<glMultiTexParameterIivEXTPtr>(get_function("glMultiTexParameterIivEXT"))) == nullptr || result;
    result = (glMultiTexParameterIuivEXT_ptr = reinterpret_cast<glMultiTexParameterIuivEXTPtr>(get_function("glMultiTexParameterIuivEXT"))) == nullptr || result;
    result = (glGetMultiTexParameterIivEXT_ptr = reinterpret_cast<glGetMultiTexParameterIivEXTPtr>(get_function("glGetMultiTexParameterIivEXT"))) == nullptr || result;
    result = (glGetMultiTexParameterIuivEXT_ptr = reinterpret_cast<glGetMultiTexParameterIuivEXTPtr>(get_function("glGetMultiTexParameterIuivEXT"))) == nullptr || result;
    result = (glProgramUniform1uiEXT_ptr = reinterpret_cast<glProgramUniform1uiEXTPtr>(get_function("glProgramUniform1uiEXT"))) == nullptr || result;
    result = (glProgramUniform2uiEXT_ptr = reinterpret_cast<glProgramUniform2uiEXTPtr>(get_function("glProgramUniform2uiEXT"))) == nullptr || result;
    result = (glProgramUniform3uiEXT_ptr = reinterpret_cast<glProgramUniform3uiEXTPtr>(get_function("glProgramUniform3uiEXT"))) == nullptr || result;
    result = (glProgramUniform4uiEXT_ptr = reinterpret_cast<glProgramUniform4uiEXTPtr>(get_function("glProgramUniform4uiEXT"))) == nullptr || result;
    result = (glProgramUniform1uivEXT_ptr = reinterpret_cast<glProgramUniform1uivEXTPtr>(get_function("glProgramUniform1uivEXT"))) == nullptr || result;
    result = (glProgramUniform2uivEXT_ptr = reinterpret_cast<glProgramUniform2uivEXTPtr>(get_function("glProgramUniform2uivEXT"))) == nullptr || result;
    result = (glProgramUniform3uivEXT_ptr = reinterpret_cast<glProgramUniform3uivEXTPtr>(get_function("glProgramUniform3uivEXT"))) == nullptr || result;
    result = (glProgramUniform4uivEXT_ptr = reinterpret_cast<glProgramUniform4uivEXTPtr>(get_function("glProgramUniform4uivEXT"))) == nullptr || result;
    result = (glNamedProgramLocalParameters4fvEXT_ptr = reinterpret_cast<glNamedProgramLocalParameters4fvEXTPtr>(get_function("glNamedProgramLocalParameters4fvEXT"))) == nullptr || result;
    result = (glNamedProgramLocalParameterI4iEXT_ptr = reinterpret_cast<glNamedProgramLocalParameterI4iEXTPtr>(get_function("glNamedProgramLocalParameterI4iEXT"))) == nullptr || result;
    result = (glNamedProgramLocalParameterI4ivEXT_ptr = reinterpret_cast<glNamedProgramLocalParameterI4ivEXTPtr>(get_function("glNamedProgramLocalParameterI4ivEXT"))) == nullptr || result;
    result = (glNamedProgramLocalParametersI4ivEXT_ptr = reinterpret_cast<glNamedProgramLocalParametersI4ivEXTPtr>(get_function("glNamedProgramLocalParametersI4ivEXT"))) == nullptr || result;
    result = (glNamedProgramLocalParameterI4uiEXT_ptr = reinterpret_cast<glNamedProgramLocalParameterI4uiEXTPtr>(get_function("glNamedProgramLocalParameterI4uiEXT"))) == nullptr || result;
    result = (glNamedProgramLocalParameterI4uivEXT_ptr = reinterpret_cast<glNamedProgramLocalParameterI4uivEXTPtr>(get_function("glNamedProgramLocalParameterI4uivEXT"))) == nullptr || result;
    result = (glNamedProgramLocalParametersI4uivEXT_ptr = reinterpret_cast<glNamedProgramLocalParametersI4uivEXTPtr>(get_function("glNamedProgramLocalParametersI4uivEXT"))) == nullptr || result;
    result = (glGetNamedProgramLocalParameterIivEXT_ptr = reinterpret_cast<glGetNamedProgramLocalParameterIivEXTPtr>(get_function("glGetNamedProgramLocalParameterIivEXT"))) == nullptr || result;
    result = (glGetNamedProgramLocalParameterIuivEXT_ptr = reinterpret_cast<glGetNamedProgramLocalParameterIuivEXTPtr>(get_function("glGetNamedProgramLocalParameterIuivEXT"))) == nullptr || result;
    result = (glEnableClientStateiEXT_ptr = reinterpret_cast<glEnableClientStateiEXTPtr>(get_function("glEnableClientStateiEXT"))) == nullptr || result;
    result = (glDisableClientStateiEXT_ptr = reinterpret_cast<glDisableClientStateiEXTPtr>(get_function("glDisableClientStateiEXT"))) == nullptr || result;
    result = (glGetFloati_vEXT_ptr = reinterpret_cast<glGetFloati_vEXTPtr>(get_function("glGetFloati_vEXT"))) == nullptr || result;
    result = (glGetDoublei_vEXT_ptr = reinterpret_cast<glGetDoublei_vEXTPtr>(get_function("glGetDoublei_vEXT"))) == nullptr || result;
    result = (glGetPointeri_vEXT_ptr = reinterpret_cast<glGetPointeri_vEXTPtr>(get_function("glGetPointeri_vEXT"))) == nullptr || result;
    result = (glNamedProgramStringEXT_ptr = reinterpret_cast<glNamedProgramStringEXTPtr>(get_function("glNamedProgramStringEXT"))) == nullptr || result;
    result = (glNamedProgramLocalParameter4dEXT_ptr = reinterpret_cast<glNamedProgramLocalParameter4dEXTPtr>(get_function("glNamedProgramLocalParameter4dEXT"))) == nullptr || result;
    result = (glNamedProgramLocalParameter4dvEXT_ptr = reinterpret_cast<glNamedProgramLocalParameter4dvEXTPtr>(get_function("glNamedProgramLocalParameter4dvEXT"))) == nullptr || result;
    result = (glNamedProgramLocalParameter4fEXT_ptr = reinterpret_cast<glNamedProgramLocalParameter4fEXTPtr>(get_function("glNamedProgramLocalParameter4fEXT"))) == nullptr || result;
    result = (glNamedProgramLocalParameter4fvEXT_ptr = reinterpret_cast<glNamedProgramLocalParameter4fvEXTPtr>(get_function("glNamedProgramLocalParameter4fvEXT"))) == nullptr || result;
    result = (glGetNamedProgramLocalParameterdvEXT_ptr = reinterpret_cast<glGetNamedProgramLocalParameterdvEXTPtr>(get_function("glGetNamedProgramLocalParameterdvEXT"))) == nullptr || result;
    result = (glGetNamedProgramLocalParameterfvEXT_ptr = reinterpret_cast<glGetNamedProgramLocalParameterfvEXTPtr>(get_function("glGetNamedProgramLocalParameterfvEXT"))) == nullptr || result;
    result = (glGetNamedProgramivEXT_ptr = reinterpret_cast<glGetNamedProgramivEXTPtr>(get_function("glGetNamedProgramivEXT"))) == nullptr || result;
    result = (glGetNamedProgramStringEXT_ptr = reinterpret_cast<glGetNamedProgramStringEXTPtr>(get_function("glGetNamedProgramStringEXT"))) == nullptr || result;
    result = (glNamedRenderbufferStorageEXT_ptr = reinterpret_cast<glNamedRenderbufferStorageEXTPtr>(get_function("glNamedRenderbufferStorageEXT"))) == nullptr || result;
    result = (glGetNamedRenderbufferParameterivEXT_ptr = reinterpret_cast<glGetNamedRenderbufferParameterivEXTPtr>(get_function("glGetNamedRenderbufferParameterivEXT"))) == nullptr || result;
    result = (glNamedRenderbufferStorageMultisampleEXT_ptr = reinterpret_cast<glNamedRenderbufferStorageMultisampleEXTPtr>(get_function("glNamedRenderbufferStorageMultisampleEXT"))) == nullptr || result;
    result = (glNamedRenderbufferStorageMultisampleCoverageEXT_ptr = reinterpret_cast<glNamedRenderbufferStorageMultisampleCoverageEXTPtr>(get_function("glNamedRenderbufferStorageMultisampleCoverageEXT"))) == nullptr || result;
    result = (glCheckNamedFramebufferStatusEXT_ptr = reinterpret_cast<glCheckNamedFramebufferStatusEXTPtr>(get_function("glCheckNamedFramebufferStatusEXT"))) == nullptr || result;
    result = (glNamedFramebufferTexture1DEXT_ptr = reinterpret_cast<glNamedFramebufferTexture1DEXTPtr>(get_function("glNamedFramebufferTexture1DEXT"))) == nullptr || result;
    result = (glNamedFramebufferTexture2DEXT_ptr = reinterpret_cast<glNamedFramebufferTexture2DEXTPtr>(get_function("glNamedFramebufferTexture2DEXT"))) == nullptr || result;
    result = (glNamedFramebufferTexture3DEXT_ptr = reinterpret_cast<glNamedFramebufferTexture3DEXTPtr>(get_function("glNamedFramebufferTexture3DEXT"))) == nullptr || result;
    result = (glNamedFramebufferRenderbufferEXT_ptr = reinterpret_cast<glNamedFramebufferRenderbufferEXTPtr>(get_function("glNamedFramebufferRenderbufferEXT"))) == nullptr || result;
    result = (glGetNamedFramebufferAttachmentParameterivEXT_ptr = reinterpret_cast<glGetNamedFramebufferAttachmentParameterivEXTPtr>(get_function("glGetNamedFramebufferAttachmentParameterivEXT"))) == nullptr || result;
    result = (glGenerateTextureMipmapEXT_ptr = reinterpret_cast<glGenerateTextureMipmapEXTPtr>(get_function("glGenerateTextureMipmapEXT"))) == nullptr || result;
    result = (glGenerateMultiTexMipmapEXT_ptr = reinterpret_cast<glGenerateMultiTexMipmapEXTPtr>(get_function("glGenerateMultiTexMipmapEXT"))) == nullptr || result;
    result = (glFramebufferDrawBufferEXT_ptr = reinterpret_cast<glFramebufferDrawBufferEXTPtr>(get_function("glFramebufferDrawBufferEXT"))) == nullptr || result;
    result = (glFramebufferDrawBuffersEXT_ptr = reinterpret_cast<glFramebufferDrawBuffersEXTPtr>(get_function("glFramebufferDrawBuffersEXT"))) == nullptr || result;
    result = (glFramebufferReadBufferEXT_ptr = reinterpret_cast<glFramebufferReadBufferEXTPtr>(get_function("glFramebufferReadBufferEXT"))) == nullptr || result;
    result = (glGetFramebufferParameterivEXT_ptr = reinterpret_cast<glGetFramebufferParameterivEXTPtr>(get_function("glGetFramebufferParameterivEXT"))) == nullptr || result;
    result = (glNamedCopyBufferSubDataEXT_ptr = reinterpret_cast<glNamedCopyBufferSubDataEXTPtr>(get_function("glNamedCopyBufferSubDataEXT"))) == nullptr || result;
    result = (glNamedFramebufferTextureEXT_ptr = reinterpret_cast<glNamedFramebufferTextureEXTPtr>(get_function("glNamedFramebufferTextureEXT"))) == nullptr || result;
    result = (glNamedFramebufferTextureLayerEXT_ptr = reinterpret_cast<glNamedFramebufferTextureLayerEXTPtr>(get_function("glNamedFramebufferTextureLayerEXT"))) == nullptr || result;
    result = (glNamedFramebufferTextureFaceEXT_ptr = reinterpret_cast<glNamedFramebufferTextureFaceEXTPtr>(get_function("glNamedFramebufferTextureFaceEXT"))) == nullptr || result;
    result = (glTextureRenderbufferEXT_ptr = reinterpret_cast<glTextureRenderbufferEXTPtr>(get_function("glTextureRenderbufferEXT"))) == nullptr || result;
    result = (glMultiTexRenderbufferEXT_ptr = reinterpret_cast<glMultiTexRenderbufferEXTPtr>(get_function("glMultiTexRenderbufferEXT"))) == nullptr || result;
    result = (glVertexArrayVertexOffsetEXT_ptr = reinterpret_cast<glVertexArrayVertexOffsetEXTPtr>(get_function("glVertexArrayVertexOffsetEXT"))) == nullptr || result;
    result = (glVertexArrayColorOffsetEXT_ptr = reinterpret_cast<glVertexArrayColorOffsetEXTPtr>(get_function("glVertexArrayColorOffsetEXT"))) == nullptr || result;
    result = (glVertexArrayEdgeFlagOffsetEXT_ptr = reinterpret_cast<glVertexArrayEdgeFlagOffsetEXTPtr>(get_function("glVertexArrayEdgeFlagOffsetEXT"))) == nullptr || result;
    result = (glVertexArrayIndexOffsetEXT_ptr = reinterpret_cast<glVertexArrayIndexOffsetEXTPtr>(get_function("glVertexArrayIndexOffsetEXT"))) == nullptr || result;
    result = (glVertexArrayNormalOffsetEXT_ptr = reinterpret_cast<glVertexArrayNormalOffsetEXTPtr>(get_function("glVertexArrayNormalOffsetEXT"))) == nullptr || result;
    result = (glVertexArrayTexCoordOffsetEXT_ptr = reinterpret_cast<glVertexArrayTexCoordOffsetEXTPtr>(get_function("glVertexArrayTexCoordOffsetEXT"))) == nullptr || result;
    result = (glVertexArrayMultiTexCoordOffsetEXT_ptr = reinterpret_cast<glVertexArrayMultiTexCoordOffsetEXTPtr>(get_function("glVertexArrayMultiTexCoordOffsetEXT"))) == nullptr || result;
    result = (glVertexArrayFogCoordOffsetEXT_ptr = reinterpret_cast<glVertexArrayFogCoordOffsetEXTPtr>(get_function("glVertexArrayFogCoordOffsetEXT"))) == nullptr || result;
    result = (glVertexArraySecondaryColorOffsetEXT_ptr = reinterpret_cast<glVertexArraySecondaryColorOffsetEXTPtr>(get_function("glVertexArraySecondaryColorOffsetEXT"))) == nullptr || result;
    result = (glVertexArrayVertexAttribOffsetEXT_ptr = reinterpret_cast<glVertexArrayVertexAttribOffsetEXTPtr>(get_function("glVertexArrayVertexAttribOffsetEXT"))) == nullptr || result;
    result = (glVertexArrayVertexAttribIOffsetEXT_ptr = reinterpret_cast<glVertexArrayVertexAttribIOffsetEXTPtr>(get_function("glVertexArrayVertexAttribIOffsetEXT"))) == nullptr || result;
    result = (glEnableVertexArrayEXT_ptr = reinterpret_cast<glEnableVertexArrayEXTPtr>(get_function("glEnableVertexArrayEXT"))) == nullptr || result;
    result = (glDisableVertexArrayEXT_ptr = reinterpret_cast<glDisableVertexArrayEXTPtr>(get_function("glDisableVertexArrayEXT"))) == nullptr || result;
    result = (glEnableVertexArrayAttribEXT_ptr = reinterpret_cast<glEnableVertexArrayAttribEXTPtr>(get_function("glEnableVertexArrayAttribEXT"))) == nullptr || result;
    result = (glDisableVertexArrayAttribEXT_ptr = reinterpret_cast<glDisableVertexArrayAttribEXTPtr>(get_function("glDisableVertexArrayAttribEXT"))) == nullptr || result;
    result = (glGetVertexArrayIntegervEXT_ptr = reinterpret_cast<glGetVertexArrayIntegervEXTPtr>(get_function("glGetVertexArrayIntegervEXT"))) == nullptr || result;
    result = (glGetVertexArrayPointervEXT_ptr = reinterpret_cast<glGetVertexArrayPointervEXTPtr>(get_function("glGetVertexArrayPointervEXT"))) == nullptr || result;
    result = (glGetVertexArrayIntegeri_vEXT_ptr = reinterpret_cast<glGetVertexArrayIntegeri_vEXTPtr>(get_function("glGetVertexArrayIntegeri_vEXT"))) == nullptr || result;
    result = (glGetVertexArrayPointeri_vEXT_ptr = reinterpret_cast<glGetVertexArrayPointeri_vEXTPtr>(get_function("glGetVertexArrayPointeri_vEXT"))) == nullptr || result;
    result = (glMapNamedBufferRangeEXT_ptr = reinterpret_cast<glMapNamedBufferRangeEXTPtr>(get_function("glMapNamedBufferRangeEXT"))) == nullptr || result;
    result = (glFlushMappedNamedBufferRangeEXT_ptr = reinterpret_cast<glFlushMappedNamedBufferRangeEXTPtr>(get_function("glFlushMappedNamedBufferRangeEXT"))) == nullptr || result;
    result = (glNamedBufferStorageEXT_ptr = reinterpret_cast<glNamedBufferStorageEXTPtr>(get_function("glNamedBufferStorageEXT"))) == nullptr || result;
    result = (glClearNamedBufferDataEXT_ptr = reinterpret_cast<glClearNamedBufferDataEXTPtr>(get_function("glClearNamedBufferDataEXT"))) == nullptr || result;
    result = (glClearNamedBufferSubDataEXT_ptr = reinterpret_cast<glClearNamedBufferSubDataEXTPtr>(get_function("glClearNamedBufferSubDataEXT"))) == nullptr || result;
    result = (glNamedFramebufferParameteriEXT_ptr = reinterpret_cast<glNamedFramebufferParameteriEXTPtr>(get_function("glNamedFramebufferParameteriEXT"))) == nullptr || result;
    result = (glGetNamedFramebufferParameterivEXT_ptr = reinterpret_cast<glGetNamedFramebufferParameterivEXTPtr>(get_function("glGetNamedFramebufferParameterivEXT"))) == nullptr || result;
    result = (glProgramUniform1dEXT_ptr = reinterpret_cast<glProgramUniform1dEXTPtr>(get_function("glProgramUniform1dEXT"))) == nullptr || result;
    result = (glProgramUniform2dEXT_ptr = reinterpret_cast<glProgramUniform2dEXTPtr>(get_function("glProgramUniform2dEXT"))) == nullptr || result;
    result = (glProgramUniform3dEXT_ptr = reinterpret_cast<glProgramUniform3dEXTPtr>(get_function("glProgramUniform3dEXT"))) == nullptr || result;
    result = (glProgramUniform4dEXT_ptr = reinterpret_cast<glProgramUniform4dEXTPtr>(get_function("glProgramUniform4dEXT"))) == nullptr || result;
    result = (glProgramUniform1dvEXT_ptr = reinterpret_cast<glProgramUniform1dvEXTPtr>(get_function("glProgramUniform1dvEXT"))) == nullptr || result;
    result = (glProgramUniform2dvEXT_ptr = reinterpret_cast<glProgramUniform2dvEXTPtr>(get_function("glProgramUniform2dvEXT"))) == nullptr || result;
    result = (glProgramUniform3dvEXT_ptr = reinterpret_cast<glProgramUniform3dvEXTPtr>(get_function("glProgramUniform3dvEXT"))) == nullptr || result;
    result = (glProgramUniform4dvEXT_ptr = reinterpret_cast<glProgramUniform4dvEXTPtr>(get_function("glProgramUniform4dvEXT"))) == nullptr || result;
    result = (glProgramUniformMatrix2dvEXT_ptr = reinterpret_cast<glProgramUniformMatrix2dvEXTPtr>(get_function("glProgramUniformMatrix2dvEXT"))) == nullptr || result;
    result = (glProgramUniformMatrix3dvEXT_ptr = reinterpret_cast<glProgramUniformMatrix3dvEXTPtr>(get_function("glProgramUniformMatrix3dvEXT"))) == nullptr || result;
    result = (glProgramUniformMatrix4dvEXT_ptr = reinterpret_cast<glProgramUniformMatrix4dvEXTPtr>(get_function("glProgramUniformMatrix4dvEXT"))) == nullptr || result;
    result = (glProgramUniformMatrix2x3dvEXT_ptr = reinterpret_cast<glProgramUniformMatrix2x3dvEXTPtr>(get_function("glProgramUniformMatrix2x3dvEXT"))) == nullptr || result;
    result = (glProgramUniformMatrix2x4dvEXT_ptr = reinterpret_cast<glProgramUniformMatrix2x4dvEXTPtr>(get_function("glProgramUniformMatrix2x4dvEXT"))) == nullptr || result;
    result = (glProgramUniformMatrix3x2dvEXT_ptr = reinterpret_cast<glProgramUniformMatrix3x2dvEXTPtr>(get_function("glProgramUniformMatrix3x2dvEXT"))) == nullptr || result;
    result = (glProgramUniformMatrix3x4dvEXT_ptr = reinterpret_cast<glProgramUniformMatrix3x4dvEXTPtr>(get_function("glProgramUniformMatrix3x4dvEXT"))) == nullptr || result;
    result = (glProgramUniformMatrix4x2dvEXT_ptr = reinterpret_cast<glProgramUniformMatrix4x2dvEXTPtr>(get_function("glProgramUniformMatrix4x2dvEXT"))) == nullptr || result;
    result = (glProgramUniformMatrix4x3dvEXT_ptr = reinterpret_cast<glProgramUniformMatrix4x3dvEXTPtr>(get_function("glProgramUniformMatrix4x3dvEXT"))) == nullptr || result;
    result = (glTextureBufferRangeEXT_ptr = reinterpret_cast<glTextureBufferRangeEXTPtr>(get_function("glTextureBufferRangeEXT"))) == nullptr || result;
    result = (glTextureStorage1DEXT_ptr = reinterpret_cast<glTextureStorage1DEXTPtr>(get_function("glTextureStorage1DEXT"))) == nullptr || result;
    result = (glTextureStorage2DEXT_ptr = reinterpret_cast<glTextureStorage2DEXTPtr>(get_function("glTextureStorage2DEXT"))) == nullptr || result;
    result = (glTextureStorage3DEXT_ptr = reinterpret_cast<glTextureStorage3DEXTPtr>(get_function("glTextureStorage3DEXT"))) == nullptr || result;
    result = (glTextureStorage2DMultisampleEXT_ptr = reinterpret_cast<glTextureStorage2DMultisampleEXTPtr>(get_function("glTextureStorage2DMultisampleEXT"))) == nullptr || result;
    result = (glTextureStorage3DMultisampleEXT_ptr = reinterpret_cast<glTextureStorage3DMultisampleEXTPtr>(get_function("glTextureStorage3DMultisampleEXT"))) == nullptr || result;
    result = (glVertexArrayBindVertexBufferEXT_ptr = reinterpret_cast<glVertexArrayBindVertexBufferEXTPtr>(get_function("glVertexArrayBindVertexBufferEXT"))) == nullptr || result;
    result = (glVertexArrayVertexAttribFormatEXT_ptr = reinterpret_cast<glVertexArrayVertexAttribFormatEXTPtr>(get_function("glVertexArrayVertexAttribFormatEXT"))) == nullptr || result;
    result = (glVertexArrayVertexAttribIFormatEXT_ptr = reinterpret_cast<glVertexArrayVertexAttribIFormatEXTPtr>(get_function("glVertexArrayVertexAttribIFormatEXT"))) == nullptr || result;
    result = (glVertexArrayVertexAttribLFormatEXT_ptr = reinterpret_cast<glVertexArrayVertexAttribLFormatEXTPtr>(get_function("glVertexArrayVertexAttribLFormatEXT"))) == nullptr || result;
    result = (glVertexArrayVertexAttribBindingEXT_ptr = reinterpret_cast<glVertexArrayVertexAttribBindingEXTPtr>(get_function("glVertexArrayVertexAttribBindingEXT"))) == nullptr || result;
    result = (glVertexArrayVertexBindingDivisorEXT_ptr = reinterpret_cast<glVertexArrayVertexBindingDivisorEXTPtr>(get_function("glVertexArrayVertexBindingDivisorEXT"))) == nullptr || result;
    result = (glVertexArrayVertexAttribLOffsetEXT_ptr = reinterpret_cast<glVertexArrayVertexAttribLOffsetEXTPtr>(get_function("glVertexArrayVertexAttribLOffsetEXT"))) == nullptr || result;
    result = (glTexturePageCommitmentEXT_ptr = reinterpret_cast<glTexturePageCommitmentEXTPtr>(get_function("glTexturePageCommitmentEXT"))) == nullptr || result;
    result = (glVertexArrayVertexAttribDivisorEXT_ptr = reinterpret_cast<glVertexArrayVertexAttribDivisorEXTPtr>(get_function("glVertexArrayVertexAttribDivisorEXT"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_EXT_draw_instanced

using glDrawArraysInstancedEXTPtr   = std::add_pointer_t<decltype(glDrawArraysInstancedEXT)>;
using glDrawElementsInstancedEXTPtr = std::add_pointer_t<decltype(glDrawElementsInstancedEXT)>;

glDrawArraysInstancedEXTPtr glDrawArraysInstancedEXT_ptr     = nullptr;
glDrawElementsInstancedEXTPtr glDrawElementsInstancedEXT_ptr = nullptr;

bool init_gl_ext_draw_instanced([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glDrawArraysInstancedEXT_ptr = reinterpret_cast<glDrawArraysInstancedEXTPtr>(get_function("glDrawArraysInstancedEXT"))) == nullptr || result;
    result = (glDrawElementsInstancedEXT_ptr = reinterpret_cast<glDrawElementsInstancedEXTPtr>(get_function("glDrawElementsInstancedEXT"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_EXT_multiview_tessellation_geometry_shader

bool init_gl_ext_multiview_tessellation_geometry_shader([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_EXT_multiview_texture_multisample

bool init_gl_ext_multiview_texture_multisample([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_EXT_multiview_timer_query

bool init_gl_ext_multiview_timer_query([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_EXT_polygon_offset_clamp

using glPolygonOffsetClampEXTPtr = std::add_pointer_t<decltype(glPolygonOffsetClampEXT)>;

glPolygonOffsetClampEXTPtr glPolygonOffsetClampEXT_ptr = nullptr;

bool init_gl_ext_polygon_offset_clamp([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glPolygonOffsetClampEXT_ptr = reinterpret_cast<glPolygonOffsetClampEXTPtr>(get_function("glPolygonOffsetClampEXT"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_EXT_post_depth_coverage

bool init_gl_ext_post_depth_coverage([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_EXT_raster_multisample

using glRasterSamplesEXTPtr = std::add_pointer_t<decltype(glRasterSamplesEXT)>;

glRasterSamplesEXTPtr glRasterSamplesEXT_ptr = nullptr;

bool init_gl_ext_raster_multisample([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glRasterSamplesEXT_ptr = reinterpret_cast<glRasterSamplesEXTPtr>(get_function("glRasterSamplesEXT"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_EXT_separate_shader_objects

using glUseShaderProgramEXTPtr          = std::add_pointer_t<decltype(glUseShaderProgramEXT)>;
using glActiveProgramEXTPtr             = std::add_pointer_t<decltype(glActiveProgramEXT)>;
using glCreateShaderProgramEXTPtr       = std::add_pointer_t<decltype(glCreateShaderProgramEXT)>;
using glActiveShaderProgramEXTPtr       = std::add_pointer_t<decltype(glActiveShaderProgramEXT)>;
using glBindProgramPipelineEXTPtr       = std::add_pointer_t<decltype(glBindProgramPipelineEXT)>;
using glCreateShaderProgramvEXTPtr      = std::add_pointer_t<decltype(glCreateShaderProgramvEXT)>;
using glDeleteProgramPipelinesEXTPtr    = std::add_pointer_t<decltype(glDeleteProgramPipelinesEXT)>;
using glGenProgramPipelinesEXTPtr       = std::add_pointer_t<decltype(glGenProgramPipelinesEXT)>;
using glGetProgramPipelineInfoLogEXTPtr = std::add_pointer_t<decltype(glGetProgramPipelineInfoLogEXT)>;
using glGetProgramPipelineivEXTPtr      = std::add_pointer_t<decltype(glGetProgramPipelineivEXT)>;
using glIsProgramPipelineEXTPtr         = std::add_pointer_t<decltype(glIsProgramPipelineEXT)>;
using glProgramParameteriEXTPtr         = std::add_pointer_t<decltype(glProgramParameteriEXT)>;
using glUseProgramStagesEXTPtr          = std::add_pointer_t<decltype(glUseProgramStagesEXT)>;
using glValidateProgramPipelineEXTPtr   = std::add_pointer_t<decltype(glValidateProgramPipelineEXT)>;

glUseShaderProgramEXTPtr glUseShaderProgramEXT_ptr                   = nullptr;
glActiveProgramEXTPtr glActiveProgramEXT_ptr                         = nullptr;
glCreateShaderProgramEXTPtr glCreateShaderProgramEXT_ptr             = nullptr;
glActiveShaderProgramEXTPtr glActiveShaderProgramEXT_ptr             = nullptr;
glBindProgramPipelineEXTPtr glBindProgramPipelineEXT_ptr             = nullptr;
glCreateShaderProgramvEXTPtr glCreateShaderProgramvEXT_ptr           = nullptr;
glDeleteProgramPipelinesEXTPtr glDeleteProgramPipelinesEXT_ptr       = nullptr;
glGenProgramPipelinesEXTPtr glGenProgramPipelinesEXT_ptr             = nullptr;
glGetProgramPipelineInfoLogEXTPtr glGetProgramPipelineInfoLogEXT_ptr = nullptr;
glGetProgramPipelineivEXTPtr glGetProgramPipelineivEXT_ptr           = nullptr;
glIsProgramPipelineEXTPtr glIsProgramPipelineEXT_ptr                 = nullptr;
glProgramParameteriEXTPtr glProgramParameteriEXT_ptr                 = nullptr;
glUseProgramStagesEXTPtr glUseProgramStagesEXT_ptr                   = nullptr;
glValidateProgramPipelineEXTPtr glValidateProgramPipelineEXT_ptr     = nullptr;

bool init_gl_ext_separate_shader_objects([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glUseShaderProgramEXT_ptr = reinterpret_cast<glUseShaderProgramEXTPtr>(get_function("glUseShaderProgramEXT"))) == nullptr || result;
    result = (glActiveProgramEXT_ptr = reinterpret_cast<glActiveProgramEXTPtr>(get_function("glActiveProgramEXT"))) == nullptr || result;
    result = (glCreateShaderProgramEXT_ptr = reinterpret_cast<glCreateShaderProgramEXTPtr>(get_function("glCreateShaderProgramEXT"))) == nullptr || result;
    result = (glActiveShaderProgramEXT_ptr = reinterpret_cast<glActiveShaderProgramEXTPtr>(get_function("glActiveShaderProgramEXT"))) == nullptr || result;
    result = (glBindProgramPipelineEXT_ptr = reinterpret_cast<glBindProgramPipelineEXTPtr>(get_function("glBindProgramPipelineEXT"))) == nullptr || result;
    result = (glCreateShaderProgramvEXT_ptr = reinterpret_cast<glCreateShaderProgramvEXTPtr>(get_function("glCreateShaderProgramvEXT"))) == nullptr || result;
    result = (glDeleteProgramPipelinesEXT_ptr = reinterpret_cast<glDeleteProgramPipelinesEXTPtr>(get_function("glDeleteProgramPipelinesEXT"))) == nullptr || result;
    result = (glGenProgramPipelinesEXT_ptr = reinterpret_cast<glGenProgramPipelinesEXTPtr>(get_function("glGenProgramPipelinesEXT"))) == nullptr || result;
    result = (glGetProgramPipelineInfoLogEXT_ptr = reinterpret_cast<glGetProgramPipelineInfoLogEXTPtr>(get_function("glGetProgramPipelineInfoLogEXT"))) == nullptr || result;
    result = (glGetProgramPipelineivEXT_ptr = reinterpret_cast<glGetProgramPipelineivEXTPtr>(get_function("glGetProgramPipelineivEXT"))) == nullptr || result;
    result = (glIsProgramPipelineEXT_ptr = reinterpret_cast<glIsProgramPipelineEXTPtr>(get_function("glIsProgramPipelineEXT"))) == nullptr || result;
    result = (glProgramParameteriEXT_ptr = reinterpret_cast<glProgramParameteriEXTPtr>(get_function("glProgramParameteriEXT"))) == nullptr || result;
    result = (glUseProgramStagesEXT_ptr = reinterpret_cast<glUseProgramStagesEXTPtr>(get_function("glUseProgramStagesEXT"))) == nullptr || result;
    result = (glValidateProgramPipelineEXT_ptr = reinterpret_cast<glValidateProgramPipelineEXTPtr>(get_function("glValidateProgramPipelineEXT"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_EXT_shader_framebuffer_fetch

bool init_gl_ext_shader_framebuffer_fetch([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_EXT_shader_framebuffer_fetch_non_coherent

using glFramebufferFetchBarrierEXTPtr = std::add_pointer_t<decltype(glFramebufferFetchBarrierEXT)>;

glFramebufferFetchBarrierEXTPtr glFramebufferFetchBarrierEXT_ptr = nullptr;

bool init_gl_ext_shader_framebuffer_fetch_non_coherent([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glFramebufferFetchBarrierEXT_ptr = reinterpret_cast<glFramebufferFetchBarrierEXTPtr>(get_function("glFramebufferFetchBarrierEXT"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_EXT_shader_integer_mix

bool init_gl_ext_shader_integer_mix([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_EXT_texture_compression_s3tc

bool init_gl_ext_texture_compression_s3tc([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_EXT_texture_filter_minmax

bool init_gl_ext_texture_filter_minmax([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_EXT_texture_sRGB_R8

bool init_gl_ext_texture_srgb_r8([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_EXT_texture_sRGB_decode

bool init_gl_ext_texture_srgb_decode([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_EXT_window_rectangles

using glWindowRectanglesEXTPtr = std::add_pointer_t<decltype(glWindowRectanglesEXT)>;

glWindowRectanglesEXTPtr glWindowRectanglesEXT_ptr = nullptr;

bool init_gl_ext_window_rectangles([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glWindowRectanglesEXT_ptr = reinterpret_cast<glWindowRectanglesEXTPtr>(get_function("glWindowRectanglesEXT"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_INTEL_conservative_rasterization

bool init_gl_intel_conservative_rasterization([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_INTEL_framebuffer_CMAA

using glApplyFramebufferAttachmentCMAAINTELPtr = std::add_pointer_t<decltype(glApplyFramebufferAttachmentCMAAINTEL)>;

glApplyFramebufferAttachmentCMAAINTELPtr glApplyFramebufferAttachmentCMAAINTEL_ptr = nullptr;

bool init_gl_intel_framebuffer_cmaa([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glApplyFramebufferAttachmentCMAAINTEL_ptr = reinterpret_cast<glApplyFramebufferAttachmentCMAAINTELPtr>(get_function("glApplyFramebufferAttachmentCMAAINTEL"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_INTEL_blackhole_render

bool init_gl_intel_blackhole_render([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_INTEL_performance_query

using glBeginPerfQueryINTELPtr       = std::add_pointer_t<decltype(glBeginPerfQueryINTEL)>;
using glCreatePerfQueryINTELPtr      = std::add_pointer_t<decltype(glCreatePerfQueryINTEL)>;
using glDeletePerfQueryINTELPtr      = std::add_pointer_t<decltype(glDeletePerfQueryINTEL)>;
using glEndPerfQueryINTELPtr         = std::add_pointer_t<decltype(glEndPerfQueryINTEL)>;
using glGetFirstPerfQueryIdINTELPtr  = std::add_pointer_t<decltype(glGetFirstPerfQueryIdINTEL)>;
using glGetNextPerfQueryIdINTELPtr   = std::add_pointer_t<decltype(glGetNextPerfQueryIdINTEL)>;
using glGetPerfCounterInfoINTELPtr   = std::add_pointer_t<decltype(glGetPerfCounterInfoINTEL)>;
using glGetPerfQueryDataINTELPtr     = std::add_pointer_t<decltype(glGetPerfQueryDataINTEL)>;
using glGetPerfQueryIdByNameINTELPtr = std::add_pointer_t<decltype(glGetPerfQueryIdByNameINTEL)>;
using glGetPerfQueryInfoINTELPtr     = std::add_pointer_t<decltype(glGetPerfQueryInfoINTEL)>;

glBeginPerfQueryINTELPtr glBeginPerfQueryINTEL_ptr             = nullptr;
glCreatePerfQueryINTELPtr glCreatePerfQueryINTEL_ptr           = nullptr;
glDeletePerfQueryINTELPtr glDeletePerfQueryINTEL_ptr           = nullptr;
glEndPerfQueryINTELPtr glEndPerfQueryINTEL_ptr                 = nullptr;
glGetFirstPerfQueryIdINTELPtr glGetFirstPerfQueryIdINTEL_ptr   = nullptr;
glGetNextPerfQueryIdINTELPtr glGetNextPerfQueryIdINTEL_ptr     = nullptr;
glGetPerfCounterInfoINTELPtr glGetPerfCounterInfoINTEL_ptr     = nullptr;
glGetPerfQueryDataINTELPtr glGetPerfQueryDataINTEL_ptr         = nullptr;
glGetPerfQueryIdByNameINTELPtr glGetPerfQueryIdByNameINTEL_ptr = nullptr;
glGetPerfQueryInfoINTELPtr glGetPerfQueryInfoINTEL_ptr         = nullptr;

bool init_gl_intel_performance_query([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glBeginPerfQueryINTEL_ptr = reinterpret_cast<glBeginPerfQueryINTELPtr>(get_function("glBeginPerfQueryINTEL"))) == nullptr || result;
    result = (glCreatePerfQueryINTEL_ptr = reinterpret_cast<glCreatePerfQueryINTELPtr>(get_function("glCreatePerfQueryINTEL"))) == nullptr || result;
    result = (glDeletePerfQueryINTEL_ptr = reinterpret_cast<glDeletePerfQueryINTELPtr>(get_function("glDeletePerfQueryINTEL"))) == nullptr || result;
    result = (glEndPerfQueryINTEL_ptr = reinterpret_cast<glEndPerfQueryINTELPtr>(get_function("glEndPerfQueryINTEL"))) == nullptr || result;
    result = (glGetFirstPerfQueryIdINTEL_ptr = reinterpret_cast<glGetFirstPerfQueryIdINTELPtr>(get_function("glGetFirstPerfQueryIdINTEL"))) == nullptr || result;
    result = (glGetNextPerfQueryIdINTEL_ptr = reinterpret_cast<glGetNextPerfQueryIdINTELPtr>(get_function("glGetNextPerfQueryIdINTEL"))) == nullptr || result;
    result = (glGetPerfCounterInfoINTEL_ptr = reinterpret_cast<glGetPerfCounterInfoINTELPtr>(get_function("glGetPerfCounterInfoINTEL"))) == nullptr || result;
    result = (glGetPerfQueryDataINTEL_ptr = reinterpret_cast<glGetPerfQueryDataINTELPtr>(get_function("glGetPerfQueryDataINTEL"))) == nullptr || result;
    result = (glGetPerfQueryIdByNameINTEL_ptr = reinterpret_cast<glGetPerfQueryIdByNameINTELPtr>(get_function("glGetPerfQueryIdByNameINTEL"))) == nullptr || result;
    result = (glGetPerfQueryInfoINTEL_ptr = reinterpret_cast<glGetPerfQueryInfoINTELPtr>(get_function("glGetPerfQueryInfoINTEL"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_KHR_blend_equation_advanced

using glBlendBarrierKHRPtr = std::add_pointer_t<decltype(glBlendBarrierKHR)>;

glBlendBarrierKHRPtr glBlendBarrierKHR_ptr = nullptr;

bool init_gl_khr_blend_equation_advanced([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glBlendBarrierKHR_ptr = reinterpret_cast<glBlendBarrierKHRPtr>(get_function("glBlendBarrierKHR"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_KHR_blend_equation_advanced_coherent

bool init_gl_khr_blend_equation_advanced_coherent([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_KHR_context_flush_control

bool init_gl_khr_context_flush_control([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_KHR_debug

using glDebugMessageControlKHRPtr  = std::add_pointer_t<decltype(glDebugMessageControlKHR)>;
using glDebugMessageInsertKHRPtr   = std::add_pointer_t<decltype(glDebugMessageInsertKHR)>;
using glDebugMessageCallbackKHRPtr = std::add_pointer_t<decltype(glDebugMessageCallbackKHR)>;
using glGetDebugMessageLogKHRPtr   = std::add_pointer_t<decltype(glGetDebugMessageLogKHR)>;
using glPushDebugGroupKHRPtr       = std::add_pointer_t<decltype(glPushDebugGroupKHR)>;
using glPopDebugGroupKHRPtr        = std::add_pointer_t<decltype(glPopDebugGroupKHR)>;
using glObjectLabelKHRPtr          = std::add_pointer_t<decltype(glObjectLabelKHR)>;
using glGetObjectLabelKHRPtr       = std::add_pointer_t<decltype(glGetObjectLabelKHR)>;
using glObjectPtrLabelKHRPtr       = std::add_pointer_t<decltype(glObjectPtrLabelKHR)>;
using glGetObjectPtrLabelKHRPtr    = std::add_pointer_t<decltype(glGetObjectPtrLabelKHR)>;
using glGetPointervKHRPtr          = std::add_pointer_t<decltype(glGetPointervKHR)>;

glDebugMessageControlKHRPtr glDebugMessageControlKHR_ptr   = nullptr;
glDebugMessageInsertKHRPtr glDebugMessageInsertKHR_ptr     = nullptr;
glDebugMessageCallbackKHRPtr glDebugMessageCallbackKHR_ptr = nullptr;
glGetDebugMessageLogKHRPtr glGetDebugMessageLogKHR_ptr     = nullptr;
glPushDebugGroupKHRPtr glPushDebugGroupKHR_ptr             = nullptr;
glPopDebugGroupKHRPtr glPopDebugGroupKHR_ptr               = nullptr;
glObjectLabelKHRPtr glObjectLabelKHR_ptr                   = nullptr;
glGetObjectLabelKHRPtr glGetObjectLabelKHR_ptr             = nullptr;
glObjectPtrLabelKHRPtr glObjectPtrLabelKHR_ptr             = nullptr;
glGetObjectPtrLabelKHRPtr glGetObjectPtrLabelKHR_ptr       = nullptr;
glGetPointervKHRPtr glGetPointervKHR_ptr                   = nullptr;

bool init_gl_khr_debug([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glDebugMessageControlKHR_ptr = reinterpret_cast<glDebugMessageControlKHRPtr>(get_function("glDebugMessageControlKHR"))) == nullptr || result;
    result = (glDebugMessageInsertKHR_ptr = reinterpret_cast<glDebugMessageInsertKHRPtr>(get_function("glDebugMessageInsertKHR"))) == nullptr || result;
    result = (glDebugMessageCallbackKHR_ptr = reinterpret_cast<glDebugMessageCallbackKHRPtr>(get_function("glDebugMessageCallbackKHR"))) == nullptr || result;
    result = (glGetDebugMessageLogKHR_ptr = reinterpret_cast<glGetDebugMessageLogKHRPtr>(get_function("glGetDebugMessageLogKHR"))) == nullptr || result;
    result = (glPushDebugGroupKHR_ptr = reinterpret_cast<glPushDebugGroupKHRPtr>(get_function("glPushDebugGroupKHR"))) == nullptr || result;
    result = (glPopDebugGroupKHR_ptr = reinterpret_cast<glPopDebugGroupKHRPtr>(get_function("glPopDebugGroupKHR"))) == nullptr || result;
    result = (glObjectLabelKHR_ptr = reinterpret_cast<glObjectLabelKHRPtr>(get_function("glObjectLabelKHR"))) == nullptr || result;
    result = (glGetObjectLabelKHR_ptr = reinterpret_cast<glGetObjectLabelKHRPtr>(get_function("glGetObjectLabelKHR"))) == nullptr || result;
    result = (glObjectPtrLabelKHR_ptr = reinterpret_cast<glObjectPtrLabelKHRPtr>(get_function("glObjectPtrLabelKHR"))) == nullptr || result;
    result = (glGetObjectPtrLabelKHR_ptr = reinterpret_cast<glGetObjectPtrLabelKHRPtr>(get_function("glGetObjectPtrLabelKHR"))) == nullptr || result;
    result = (glGetPointervKHR_ptr = reinterpret_cast<glGetPointervKHRPtr>(get_function("glGetPointervKHR"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_KHR_no_error

bool init_gl_khr_no_error([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_KHR_robust_buffer_access_behavior

bool init_gl_khr_robust_buffer_access_behavior([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_KHR_robustness

using glGetGraphicsResetStatusKHRPtr = std::add_pointer_t<decltype(glGetGraphicsResetStatusKHR)>;
using glReadnPixelsKHRPtr            = std::add_pointer_t<decltype(glReadnPixelsKHR)>;
using glGetnUniformfvKHRPtr          = std::add_pointer_t<decltype(glGetnUniformfvKHR)>;
using glGetnUniformivKHRPtr          = std::add_pointer_t<decltype(glGetnUniformivKHR)>;
using glGetnUniformuivKHRPtr         = std::add_pointer_t<decltype(glGetnUniformuivKHR)>;

glGetGraphicsResetStatusKHRPtr glGetGraphicsResetStatusKHR_ptr = nullptr;
glReadnPixelsKHRPtr glReadnPixelsKHR_ptr                       = nullptr;
glGetnUniformfvKHRPtr glGetnUniformfvKHR_ptr                   = nullptr;
glGetnUniformivKHRPtr glGetnUniformivKHR_ptr                   = nullptr;
glGetnUniformuivKHRPtr glGetnUniformuivKHR_ptr                 = nullptr;

bool init_gl_khr_robustness([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glGetGraphicsResetStatusKHR_ptr = reinterpret_cast<glGetGraphicsResetStatusKHRPtr>(get_function("glGetGraphicsResetStatusKHR"))) == nullptr || result;
    result = (glReadnPixelsKHR_ptr = reinterpret_cast<glReadnPixelsKHRPtr>(get_function("glReadnPixelsKHR"))) == nullptr || result;
    result = (glGetnUniformfvKHR_ptr = reinterpret_cast<glGetnUniformfvKHRPtr>(get_function("glGetnUniformfvKHR"))) == nullptr || result;
    result = (glGetnUniformivKHR_ptr = reinterpret_cast<glGetnUniformivKHRPtr>(get_function("glGetnUniformivKHR"))) == nullptr || result;
    result = (glGetnUniformuivKHR_ptr = reinterpret_cast<glGetnUniformuivKHRPtr>(get_function("glGetnUniformuivKHR"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_KHR_shader_subgroup

bool init_gl_khr_shader_subgroup([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_KHR_texture_compression_astc_hdr

bool init_gl_khr_texture_compression_astc_hdr([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_KHR_texture_compression_astc_ldr

bool init_gl_khr_texture_compression_astc_ldr([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_KHR_texture_compression_astc_sliced_3d

bool init_gl_khr_texture_compression_astc_sliced_3d([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_KHR_parallel_shader_compile

using glMaxShaderCompilerThreadsKHRPtr = std::add_pointer_t<decltype(glMaxShaderCompilerThreadsKHR)>;

glMaxShaderCompilerThreadsKHRPtr glMaxShaderCompilerThreadsKHR_ptr = nullptr;

bool init_gl_khr_parallel_shader_compile([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glMaxShaderCompilerThreadsKHR_ptr = reinterpret_cast<glMaxShaderCompilerThreadsKHRPtr>(get_function("glMaxShaderCompilerThreadsKHR"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_MESA_framebuffer_flip_y

using glFramebufferParameteriMESAPtr     = std::add_pointer_t<decltype(glFramebufferParameteriMESA)>;
using glGetFramebufferParameterivMESAPtr = std::add_pointer_t<decltype(glGetFramebufferParameterivMESA)>;

glFramebufferParameteriMESAPtr glFramebufferParameteriMESA_ptr         = nullptr;
glGetFramebufferParameterivMESAPtr glGetFramebufferParameterivMESA_ptr = nullptr;

bool init_gl_mesa_framebuffer_flip_y([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glFramebufferParameteriMESA_ptr = reinterpret_cast<glFramebufferParameteriMESAPtr>(get_function("glFramebufferParameteriMESA"))) == nullptr || result;
    result = (glGetFramebufferParameterivMESA_ptr = reinterpret_cast<glGetFramebufferParameterivMESAPtr>(get_function("glGetFramebufferParameterivMESA"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_NV_bindless_multi_draw_indirect

using glMultiDrawArraysIndirectBindlessNVPtr   = std::add_pointer_t<decltype(glMultiDrawArraysIndirectBindlessNV)>;
using glMultiDrawElementsIndirectBindlessNVPtr = std::add_pointer_t<decltype(glMultiDrawElementsIndirectBindlessNV)>;

glMultiDrawArraysIndirectBindlessNVPtr glMultiDrawArraysIndirectBindlessNV_ptr     = nullptr;
glMultiDrawElementsIndirectBindlessNVPtr glMultiDrawElementsIndirectBindlessNV_ptr = nullptr;

bool init_gl_nv_bindless_multi_draw_indirect([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glMultiDrawArraysIndirectBindlessNV_ptr = reinterpret_cast<glMultiDrawArraysIndirectBindlessNVPtr>(get_function("glMultiDrawArraysIndirectBindlessNV"))) == nullptr || result;
    result = (glMultiDrawElementsIndirectBindlessNV_ptr = reinterpret_cast<glMultiDrawElementsIndirectBindlessNVPtr>(get_function("glMultiDrawElementsIndirectBindlessNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_NV_bindless_multi_draw_indirect_count

using glMultiDrawArraysIndirectBindlessCountNVPtr = std::add_pointer_t<
decltype(glMultiDrawArraysIndirectBindlessCountNV)>;
using glMultiDrawElementsIndirectBindlessCountNVPtr = std::add_pointer_t<
decltype(glMultiDrawElementsIndirectBindlessCountNV)>;

glMultiDrawArraysIndirectBindlessCountNVPtr glMultiDrawArraysIndirectBindlessCountNV_ptr     = nullptr;
glMultiDrawElementsIndirectBindlessCountNVPtr glMultiDrawElementsIndirectBindlessCountNV_ptr = nullptr;

bool init_gl_nv_bindless_multi_draw_indirect_count([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glMultiDrawArraysIndirectBindlessCountNV_ptr = reinterpret_cast<glMultiDrawArraysIndirectBindlessCountNVPtr>(get_function("glMultiDrawArraysIndirectBindlessCountNV"))) == nullptr || result;
    result = (glMultiDrawElementsIndirectBindlessCountNV_ptr = reinterpret_cast<glMultiDrawElementsIndirectBindlessCountNVPtr>(get_function("glMultiDrawElementsIndirectBindlessCountNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_NV_bindless_texture

using glGetTextureHandleNVPtr             = std::add_pointer_t<decltype(glGetTextureHandleNV)>;
using glGetTextureSamplerHandleNVPtr      = std::add_pointer_t<decltype(glGetTextureSamplerHandleNV)>;
using glMakeTextureHandleResidentNVPtr    = std::add_pointer_t<decltype(glMakeTextureHandleResidentNV)>;
using glMakeTextureHandleNonResidentNVPtr = std::add_pointer_t<decltype(glMakeTextureHandleNonResidentNV)>;
using glGetImageHandleNVPtr               = std::add_pointer_t<decltype(glGetImageHandleNV)>;
using glMakeImageHandleResidentNVPtr      = std::add_pointer_t<decltype(glMakeImageHandleResidentNV)>;
using glMakeImageHandleNonResidentNVPtr   = std::add_pointer_t<decltype(glMakeImageHandleNonResidentNV)>;
using glUniformHandleui64NVPtr            = std::add_pointer_t<decltype(glUniformHandleui64NV)>;
using glUniformHandleui64vNVPtr           = std::add_pointer_t<decltype(glUniformHandleui64vNV)>;
using glProgramUniformHandleui64NVPtr     = std::add_pointer_t<decltype(glProgramUniformHandleui64NV)>;
using glProgramUniformHandleui64vNVPtr    = std::add_pointer_t<decltype(glProgramUniformHandleui64vNV)>;
using glIsTextureHandleResidentNVPtr      = std::add_pointer_t<decltype(glIsTextureHandleResidentNV)>;
using glIsImageHandleResidentNVPtr        = std::add_pointer_t<decltype(glIsImageHandleResidentNV)>;

glGetTextureHandleNVPtr glGetTextureHandleNV_ptr                         = nullptr;
glGetTextureSamplerHandleNVPtr glGetTextureSamplerHandleNV_ptr           = nullptr;
glMakeTextureHandleResidentNVPtr glMakeTextureHandleResidentNV_ptr       = nullptr;
glMakeTextureHandleNonResidentNVPtr glMakeTextureHandleNonResidentNV_ptr = nullptr;
glGetImageHandleNVPtr glGetImageHandleNV_ptr                             = nullptr;
glMakeImageHandleResidentNVPtr glMakeImageHandleResidentNV_ptr           = nullptr;
glMakeImageHandleNonResidentNVPtr glMakeImageHandleNonResidentNV_ptr     = nullptr;
glUniformHandleui64NVPtr glUniformHandleui64NV_ptr                       = nullptr;
glUniformHandleui64vNVPtr glUniformHandleui64vNV_ptr                     = nullptr;
glProgramUniformHandleui64NVPtr glProgramUniformHandleui64NV_ptr         = nullptr;
glProgramUniformHandleui64vNVPtr glProgramUniformHandleui64vNV_ptr       = nullptr;
glIsTextureHandleResidentNVPtr glIsTextureHandleResidentNV_ptr           = nullptr;
glIsImageHandleResidentNVPtr glIsImageHandleResidentNV_ptr               = nullptr;

bool init_gl_nv_bindless_texture([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glGetTextureHandleNV_ptr = reinterpret_cast<glGetTextureHandleNVPtr>(get_function("glGetTextureHandleNV"))) == nullptr || result;
    result = (glGetTextureSamplerHandleNV_ptr = reinterpret_cast<glGetTextureSamplerHandleNVPtr>(get_function("glGetTextureSamplerHandleNV"))) == nullptr || result;
    result = (glMakeTextureHandleResidentNV_ptr = reinterpret_cast<glMakeTextureHandleResidentNVPtr>(get_function("glMakeTextureHandleResidentNV"))) == nullptr || result;
    result = (glMakeTextureHandleNonResidentNV_ptr = reinterpret_cast<glMakeTextureHandleNonResidentNVPtr>(get_function("glMakeTextureHandleNonResidentNV"))) == nullptr || result;
    result = (glGetImageHandleNV_ptr = reinterpret_cast<glGetImageHandleNVPtr>(get_function("glGetImageHandleNV"))) == nullptr || result;
    result = (glMakeImageHandleResidentNV_ptr = reinterpret_cast<glMakeImageHandleResidentNVPtr>(get_function("glMakeImageHandleResidentNV"))) == nullptr || result;
    result = (glMakeImageHandleNonResidentNV_ptr = reinterpret_cast<glMakeImageHandleNonResidentNVPtr>(get_function("glMakeImageHandleNonResidentNV"))) == nullptr || result;
    result = (glUniformHandleui64NV_ptr = reinterpret_cast<glUniformHandleui64NVPtr>(get_function("glUniformHandleui64NV"))) == nullptr || result;
    result = (glUniformHandleui64vNV_ptr = reinterpret_cast<glUniformHandleui64vNVPtr>(get_function("glUniformHandleui64vNV"))) == nullptr || result;
    result = (glProgramUniformHandleui64NV_ptr = reinterpret_cast<glProgramUniformHandleui64NVPtr>(get_function("glProgramUniformHandleui64NV"))) == nullptr || result;
    result = (glProgramUniformHandleui64vNV_ptr = reinterpret_cast<glProgramUniformHandleui64vNVPtr>(get_function("glProgramUniformHandleui64vNV"))) == nullptr || result;
    result = (glIsTextureHandleResidentNV_ptr = reinterpret_cast<glIsTextureHandleResidentNVPtr>(get_function("glIsTextureHandleResidentNV"))) == nullptr || result;
    result = (glIsImageHandleResidentNV_ptr = reinterpret_cast<glIsImageHandleResidentNVPtr>(get_function("glIsImageHandleResidentNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_NV_blend_equation_advanced

using glBlendParameteriNVPtr = std::add_pointer_t<decltype(glBlendParameteriNV)>;
using glBlendBarrierNVPtr    = std::add_pointer_t<decltype(glBlendBarrierNV)>;

glBlendParameteriNVPtr glBlendParameteriNV_ptr = nullptr;
glBlendBarrierNVPtr glBlendBarrierNV_ptr       = nullptr;

bool init_gl_nv_blend_equation_advanced([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glBlendParameteriNV_ptr = reinterpret_cast<glBlendParameteriNVPtr>(get_function("glBlendParameteriNV"))) == nullptr || result;
    result = (glBlendBarrierNV_ptr = reinterpret_cast<glBlendBarrierNVPtr>(get_function("glBlendBarrierNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_NV_blend_equation_advanced_coherent

bool init_gl_nv_blend_equation_advanced_coherent([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_NV_blend_minmax_factor

bool init_gl_nv_blend_minmax_factor([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_NV_clip_space_w_scaling

using glViewportPositionWScaleNVPtr = std::add_pointer_t<decltype(glViewportPositionWScaleNV)>;

glViewportPositionWScaleNVPtr glViewportPositionWScaleNV_ptr = nullptr;

bool init_gl_nv_clip_space_w_scaling([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glViewportPositionWScaleNV_ptr = reinterpret_cast<glViewportPositionWScaleNVPtr>(get_function("glViewportPositionWScaleNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_NV_command_list

using glCreateStatesNVPtr                 = std::add_pointer_t<decltype(glCreateStatesNV)>;
using glDeleteStatesNVPtr                 = std::add_pointer_t<decltype(glDeleteStatesNV)>;
using glIsStateNVPtr                      = std::add_pointer_t<decltype(glIsStateNV)>;
using glStateCaptureNVPtr                 = std::add_pointer_t<decltype(glStateCaptureNV)>;
using glGetCommandHeaderNVPtr             = std::add_pointer_t<decltype(glGetCommandHeaderNV)>;
using glGetStageIndexNVPtr                = std::add_pointer_t<decltype(glGetStageIndexNV)>;
using glDrawCommandsNVPtr                 = std::add_pointer_t<decltype(glDrawCommandsNV)>;
using glDrawCommandsAddressNVPtr          = std::add_pointer_t<decltype(glDrawCommandsAddressNV)>;
using glDrawCommandsStatesNVPtr           = std::add_pointer_t<decltype(glDrawCommandsStatesNV)>;
using glDrawCommandsStatesAddressNVPtr    = std::add_pointer_t<decltype(glDrawCommandsStatesAddressNV)>;
using glCreateCommandListsNVPtr           = std::add_pointer_t<decltype(glCreateCommandListsNV)>;
using glDeleteCommandListsNVPtr           = std::add_pointer_t<decltype(glDeleteCommandListsNV)>;
using glIsCommandListNVPtr                = std::add_pointer_t<decltype(glIsCommandListNV)>;
using glListDrawCommandsStatesClientNVPtr = std::add_pointer_t<decltype(glListDrawCommandsStatesClientNV)>;
using glCommandListSegmentsNVPtr          = std::add_pointer_t<decltype(glCommandListSegmentsNV)>;
using glCompileCommandListNVPtr           = std::add_pointer_t<decltype(glCompileCommandListNV)>;
using glCallCommandListNVPtr              = std::add_pointer_t<decltype(glCallCommandListNV)>;

glCreateStatesNVPtr glCreateStatesNV_ptr                                 = nullptr;
glDeleteStatesNVPtr glDeleteStatesNV_ptr                                 = nullptr;
glIsStateNVPtr glIsStateNV_ptr                                           = nullptr;
glStateCaptureNVPtr glStateCaptureNV_ptr                                 = nullptr;
glGetCommandHeaderNVPtr glGetCommandHeaderNV_ptr                         = nullptr;
glGetStageIndexNVPtr glGetStageIndexNV_ptr                               = nullptr;
glDrawCommandsNVPtr glDrawCommandsNV_ptr                                 = nullptr;
glDrawCommandsAddressNVPtr glDrawCommandsAddressNV_ptr                   = nullptr;
glDrawCommandsStatesNVPtr glDrawCommandsStatesNV_ptr                     = nullptr;
glDrawCommandsStatesAddressNVPtr glDrawCommandsStatesAddressNV_ptr       = nullptr;
glCreateCommandListsNVPtr glCreateCommandListsNV_ptr                     = nullptr;
glDeleteCommandListsNVPtr glDeleteCommandListsNV_ptr                     = nullptr;
glIsCommandListNVPtr glIsCommandListNV_ptr                               = nullptr;
glListDrawCommandsStatesClientNVPtr glListDrawCommandsStatesClientNV_ptr = nullptr;
glCommandListSegmentsNVPtr glCommandListSegmentsNV_ptr                   = nullptr;
glCompileCommandListNVPtr glCompileCommandListNV_ptr                     = nullptr;
glCallCommandListNVPtr glCallCommandListNV_ptr                           = nullptr;

bool init_gl_nv_command_list([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glCreateStatesNV_ptr = reinterpret_cast<glCreateStatesNVPtr>(get_function("glCreateStatesNV"))) == nullptr || result;
    result = (glDeleteStatesNV_ptr = reinterpret_cast<glDeleteStatesNVPtr>(get_function("glDeleteStatesNV"))) == nullptr || result;
    result = (glIsStateNV_ptr = reinterpret_cast<glIsStateNVPtr>(get_function("glIsStateNV"))) == nullptr || result;
    result = (glStateCaptureNV_ptr = reinterpret_cast<glStateCaptureNVPtr>(get_function("glStateCaptureNV"))) == nullptr || result;
    result = (glGetCommandHeaderNV_ptr = reinterpret_cast<glGetCommandHeaderNVPtr>(get_function("glGetCommandHeaderNV"))) == nullptr || result;
    result = (glGetStageIndexNV_ptr = reinterpret_cast<glGetStageIndexNVPtr>(get_function("glGetStageIndexNV"))) == nullptr || result;
    result = (glDrawCommandsNV_ptr = reinterpret_cast<glDrawCommandsNVPtr>(get_function("glDrawCommandsNV"))) == nullptr || result;
    result = (glDrawCommandsAddressNV_ptr = reinterpret_cast<glDrawCommandsAddressNVPtr>(get_function("glDrawCommandsAddressNV"))) == nullptr || result;
    result = (glDrawCommandsStatesNV_ptr = reinterpret_cast<glDrawCommandsStatesNVPtr>(get_function("glDrawCommandsStatesNV"))) == nullptr || result;
    result = (glDrawCommandsStatesAddressNV_ptr = reinterpret_cast<glDrawCommandsStatesAddressNVPtr>(get_function("glDrawCommandsStatesAddressNV"))) == nullptr || result;
    result = (glCreateCommandListsNV_ptr = reinterpret_cast<glCreateCommandListsNVPtr>(get_function("glCreateCommandListsNV"))) == nullptr || result;
    result = (glDeleteCommandListsNV_ptr = reinterpret_cast<glDeleteCommandListsNVPtr>(get_function("glDeleteCommandListsNV"))) == nullptr || result;
    result = (glIsCommandListNV_ptr = reinterpret_cast<glIsCommandListNVPtr>(get_function("glIsCommandListNV"))) == nullptr || result;
    result = (glListDrawCommandsStatesClientNV_ptr = reinterpret_cast<glListDrawCommandsStatesClientNVPtr>(get_function("glListDrawCommandsStatesClientNV"))) == nullptr || result;
    result = (glCommandListSegmentsNV_ptr = reinterpret_cast<glCommandListSegmentsNVPtr>(get_function("glCommandListSegmentsNV"))) == nullptr || result;
    result = (glCompileCommandListNV_ptr = reinterpret_cast<glCompileCommandListNVPtr>(get_function("glCompileCommandListNV"))) == nullptr || result;
    result = (glCallCommandListNV_ptr = reinterpret_cast<glCallCommandListNVPtr>(get_function("glCallCommandListNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_NV_compute_shader_derivatives

bool init_gl_nv_compute_shader_derivatives([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_NV_conditional_render

using glBeginConditionalRenderNVPtr = std::add_pointer_t<decltype(glBeginConditionalRenderNV)>;
using glEndConditionalRenderNVPtr   = std::add_pointer_t<decltype(glEndConditionalRenderNV)>;

glBeginConditionalRenderNVPtr glBeginConditionalRenderNV_ptr = nullptr;
glEndConditionalRenderNVPtr glEndConditionalRenderNV_ptr     = nullptr;

bool init_gl_nv_conditional_render([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glBeginConditionalRenderNV_ptr = reinterpret_cast<glBeginConditionalRenderNVPtr>(get_function("glBeginConditionalRenderNV"))) == nullptr || result;
    result = (glEndConditionalRenderNV_ptr = reinterpret_cast<glEndConditionalRenderNVPtr>(get_function("glEndConditionalRenderNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_NV_conservative_raster

using glSubpixelPrecisionBiasNVPtr = std::add_pointer_t<decltype(glSubpixelPrecisionBiasNV)>;

glSubpixelPrecisionBiasNVPtr glSubpixelPrecisionBiasNV_ptr = nullptr;

bool init_gl_nv_conservative_raster([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glSubpixelPrecisionBiasNV_ptr = reinterpret_cast<glSubpixelPrecisionBiasNVPtr>(get_function("glSubpixelPrecisionBiasNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_NV_conservative_raster_dilate

using glConservativeRasterParameterfNVPtr = std::add_pointer_t<decltype(glConservativeRasterParameterfNV)>;

glConservativeRasterParameterfNVPtr glConservativeRasterParameterfNV_ptr = nullptr;

bool init_gl_nv_conservative_raster_dilate([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glConservativeRasterParameterfNV_ptr = reinterpret_cast<glConservativeRasterParameterfNVPtr>(get_function("glConservativeRasterParameterfNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_NV_conservative_raster_pre_snap

bool init_gl_nv_conservative_raster_pre_snap([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_NV_conservative_raster_pre_snap_triangles

using glConservativeRasterParameteriNVPtr = std::add_pointer_t<decltype(glConservativeRasterParameteriNV)>;

glConservativeRasterParameteriNVPtr glConservativeRasterParameteriNV_ptr = nullptr;

bool init_gl_nv_conservative_raster_pre_snap_triangles([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glConservativeRasterParameteriNV_ptr = reinterpret_cast<glConservativeRasterParameteriNVPtr>(get_function("glConservativeRasterParameteriNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_NV_conservative_raster_underestimation

bool init_gl_nv_conservative_raster_underestimation([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_NV_depth_buffer_float

using glDepthRangedNVPtr  = std::add_pointer_t<decltype(glDepthRangedNV)>;
using glClearDepthdNVPtr  = std::add_pointer_t<decltype(glClearDepthdNV)>;
using glDepthBoundsdNVPtr = std::add_pointer_t<decltype(glDepthBoundsdNV)>;

glDepthRangedNVPtr glDepthRangedNV_ptr   = nullptr;
glClearDepthdNVPtr glClearDepthdNV_ptr   = nullptr;
glDepthBoundsdNVPtr glDepthBoundsdNV_ptr = nullptr;

bool init_gl_nv_depth_buffer_float([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glDepthRangedNV_ptr = reinterpret_cast<glDepthRangedNVPtr>(get_function("glDepthRangedNV"))) == nullptr || result;
    result = (glClearDepthdNV_ptr = reinterpret_cast<glClearDepthdNVPtr>(get_function("glClearDepthdNV"))) == nullptr || result;
    result = (glDepthBoundsdNV_ptr = reinterpret_cast<glDepthBoundsdNVPtr>(get_function("glDepthBoundsdNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_NV_draw_vulkan_image

using glDrawVkImageNVPtr       = std::add_pointer_t<decltype(glDrawVkImageNV)>;
using glGetVkProcAddrNVPtr     = std::add_pointer_t<decltype(glGetVkProcAddrNV)>;
using glWaitVkSemaphoreNVPtr   = std::add_pointer_t<decltype(glWaitVkSemaphoreNV)>;
using glSignalVkSemaphoreNVPtr = std::add_pointer_t<decltype(glSignalVkSemaphoreNV)>;
using glSignalVkFenceNVPtr     = std::add_pointer_t<decltype(glSignalVkFenceNV)>;

glDrawVkImageNVPtr glDrawVkImageNV_ptr             = nullptr;
glGetVkProcAddrNVPtr glGetVkProcAddrNV_ptr         = nullptr;
glWaitVkSemaphoreNVPtr glWaitVkSemaphoreNV_ptr     = nullptr;
glSignalVkSemaphoreNVPtr glSignalVkSemaphoreNV_ptr = nullptr;
glSignalVkFenceNVPtr glSignalVkFenceNV_ptr         = nullptr;

bool init_gl_nv_draw_vulkan_image([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glDrawVkImageNV_ptr = reinterpret_cast<glDrawVkImageNVPtr>(get_function("glDrawVkImageNV"))) == nullptr || result;
    result = (glGetVkProcAddrNV_ptr = reinterpret_cast<glGetVkProcAddrNVPtr>(get_function("glGetVkProcAddrNV"))) == nullptr || result;
    result = (glWaitVkSemaphoreNV_ptr = reinterpret_cast<glWaitVkSemaphoreNVPtr>(get_function("glWaitVkSemaphoreNV"))) == nullptr || result;
    result = (glSignalVkSemaphoreNV_ptr = reinterpret_cast<glSignalVkSemaphoreNVPtr>(get_function("glSignalVkSemaphoreNV"))) == nullptr || result;
    result = (glSignalVkFenceNV_ptr = reinterpret_cast<glSignalVkFenceNVPtr>(get_function("glSignalVkFenceNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_NV_fill_rectangle

bool init_gl_nv_fill_rectangle([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_NV_fragment_coverage_to_color

using glFragmentCoverageColorNVPtr = std::add_pointer_t<decltype(glFragmentCoverageColorNV)>;

glFragmentCoverageColorNVPtr glFragmentCoverageColorNV_ptr = nullptr;

bool init_gl_nv_fragment_coverage_to_color([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glFragmentCoverageColorNV_ptr = reinterpret_cast<glFragmentCoverageColorNVPtr>(get_function("glFragmentCoverageColorNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_NV_fragment_shader_barycentric

bool init_gl_nv_fragment_shader_barycentric([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_NV_fragment_shader_interlock

bool init_gl_nv_fragment_shader_interlock([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_NV_framebuffer_mixed_samples

using glCoverageModulationTableNVPtr    = std::add_pointer_t<decltype(glCoverageModulationTableNV)>;
using glGetCoverageModulationTableNVPtr = std::add_pointer_t<decltype(glGetCoverageModulationTableNV)>;
using glCoverageModulationNVPtr         = std::add_pointer_t<decltype(glCoverageModulationNV)>;

glCoverageModulationTableNVPtr glCoverageModulationTableNV_ptr       = nullptr;
glGetCoverageModulationTableNVPtr glGetCoverageModulationTableNV_ptr = nullptr;
glCoverageModulationNVPtr glCoverageModulationNV_ptr                 = nullptr;

bool init_gl_nv_framebuffer_mixed_samples([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glCoverageModulationTableNV_ptr = reinterpret_cast<glCoverageModulationTableNVPtr>(get_function("glCoverageModulationTableNV"))) == nullptr || result;
    result = (glGetCoverageModulationTableNV_ptr = reinterpret_cast<glGetCoverageModulationTableNVPtr>(get_function("glGetCoverageModulationTableNV"))) == nullptr || result;
    result = (glCoverageModulationNV_ptr = reinterpret_cast<glCoverageModulationNVPtr>(get_function("glCoverageModulationNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_NV_framebuffer_multisample_coverage

using glRenderbufferStorageMultisampleCoverageNVPtr = std::add_pointer_t<
decltype(glRenderbufferStorageMultisampleCoverageNV)>;

glRenderbufferStorageMultisampleCoverageNVPtr glRenderbufferStorageMultisampleCoverageNV_ptr = nullptr;

bool init_gl_nv_framebuffer_multisample_coverage([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glRenderbufferStorageMultisampleCoverageNV_ptr = reinterpret_cast<glRenderbufferStorageMultisampleCoverageNVPtr>(get_function("glRenderbufferStorageMultisampleCoverageNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_NV_geometry_shader_passthrough

bool init_gl_nv_geometry_shader_passthrough([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_NV_gpu_shader5

using glUniform1i64NVPtr          = std::add_pointer_t<decltype(glUniform1i64NV)>;
using glUniform2i64NVPtr          = std::add_pointer_t<decltype(glUniform2i64NV)>;
using glUniform3i64NVPtr          = std::add_pointer_t<decltype(glUniform3i64NV)>;
using glUniform4i64NVPtr          = std::add_pointer_t<decltype(glUniform4i64NV)>;
using glUniform1i64vNVPtr         = std::add_pointer_t<decltype(glUniform1i64vNV)>;
using glUniform2i64vNVPtr         = std::add_pointer_t<decltype(glUniform2i64vNV)>;
using glUniform3i64vNVPtr         = std::add_pointer_t<decltype(glUniform3i64vNV)>;
using glUniform4i64vNVPtr         = std::add_pointer_t<decltype(glUniform4i64vNV)>;
using glUniform1ui64NVPtr         = std::add_pointer_t<decltype(glUniform1ui64NV)>;
using glUniform2ui64NVPtr         = std::add_pointer_t<decltype(glUniform2ui64NV)>;
using glUniform3ui64NVPtr         = std::add_pointer_t<decltype(glUniform3ui64NV)>;
using glUniform4ui64NVPtr         = std::add_pointer_t<decltype(glUniform4ui64NV)>;
using glUniform1ui64vNVPtr        = std::add_pointer_t<decltype(glUniform1ui64vNV)>;
using glUniform2ui64vNVPtr        = std::add_pointer_t<decltype(glUniform2ui64vNV)>;
using glUniform3ui64vNVPtr        = std::add_pointer_t<decltype(glUniform3ui64vNV)>;
using glUniform4ui64vNVPtr        = std::add_pointer_t<decltype(glUniform4ui64vNV)>;
using glGetUniformi64vNVPtr       = std::add_pointer_t<decltype(glGetUniformi64vNV)>;
using glProgramUniform1i64NVPtr   = std::add_pointer_t<decltype(glProgramUniform1i64NV)>;
using glProgramUniform2i64NVPtr   = std::add_pointer_t<decltype(glProgramUniform2i64NV)>;
using glProgramUniform3i64NVPtr   = std::add_pointer_t<decltype(glProgramUniform3i64NV)>;
using glProgramUniform4i64NVPtr   = std::add_pointer_t<decltype(glProgramUniform4i64NV)>;
using glProgramUniform1i64vNVPtr  = std::add_pointer_t<decltype(glProgramUniform1i64vNV)>;
using glProgramUniform2i64vNVPtr  = std::add_pointer_t<decltype(glProgramUniform2i64vNV)>;
using glProgramUniform3i64vNVPtr  = std::add_pointer_t<decltype(glProgramUniform3i64vNV)>;
using glProgramUniform4i64vNVPtr  = std::add_pointer_t<decltype(glProgramUniform4i64vNV)>;
using glProgramUniform1ui64NVPtr  = std::add_pointer_t<decltype(glProgramUniform1ui64NV)>;
using glProgramUniform2ui64NVPtr  = std::add_pointer_t<decltype(glProgramUniform2ui64NV)>;
using glProgramUniform3ui64NVPtr  = std::add_pointer_t<decltype(glProgramUniform3ui64NV)>;
using glProgramUniform4ui64NVPtr  = std::add_pointer_t<decltype(glProgramUniform4ui64NV)>;
using glProgramUniform1ui64vNVPtr = std::add_pointer_t<decltype(glProgramUniform1ui64vNV)>;
using glProgramUniform2ui64vNVPtr = std::add_pointer_t<decltype(glProgramUniform2ui64vNV)>;
using glProgramUniform3ui64vNVPtr = std::add_pointer_t<decltype(glProgramUniform3ui64vNV)>;
using glProgramUniform4ui64vNVPtr = std::add_pointer_t<decltype(glProgramUniform4ui64vNV)>;

glUniform1i64NVPtr glUniform1i64NV_ptr                   = nullptr;
glUniform2i64NVPtr glUniform2i64NV_ptr                   = nullptr;
glUniform3i64NVPtr glUniform3i64NV_ptr                   = nullptr;
glUniform4i64NVPtr glUniform4i64NV_ptr                   = nullptr;
glUniform1i64vNVPtr glUniform1i64vNV_ptr                 = nullptr;
glUniform2i64vNVPtr glUniform2i64vNV_ptr                 = nullptr;
glUniform3i64vNVPtr glUniform3i64vNV_ptr                 = nullptr;
glUniform4i64vNVPtr glUniform4i64vNV_ptr                 = nullptr;
glUniform1ui64NVPtr glUniform1ui64NV_ptr                 = nullptr;
glUniform2ui64NVPtr glUniform2ui64NV_ptr                 = nullptr;
glUniform3ui64NVPtr glUniform3ui64NV_ptr                 = nullptr;
glUniform4ui64NVPtr glUniform4ui64NV_ptr                 = nullptr;
glUniform1ui64vNVPtr glUniform1ui64vNV_ptr               = nullptr;
glUniform2ui64vNVPtr glUniform2ui64vNV_ptr               = nullptr;
glUniform3ui64vNVPtr glUniform3ui64vNV_ptr               = nullptr;
glUniform4ui64vNVPtr glUniform4ui64vNV_ptr               = nullptr;
glGetUniformi64vNVPtr glGetUniformi64vNV_ptr             = nullptr;
glProgramUniform1i64NVPtr glProgramUniform1i64NV_ptr     = nullptr;
glProgramUniform2i64NVPtr glProgramUniform2i64NV_ptr     = nullptr;
glProgramUniform3i64NVPtr glProgramUniform3i64NV_ptr     = nullptr;
glProgramUniform4i64NVPtr glProgramUniform4i64NV_ptr     = nullptr;
glProgramUniform1i64vNVPtr glProgramUniform1i64vNV_ptr   = nullptr;
glProgramUniform2i64vNVPtr glProgramUniform2i64vNV_ptr   = nullptr;
glProgramUniform3i64vNVPtr glProgramUniform3i64vNV_ptr   = nullptr;
glProgramUniform4i64vNVPtr glProgramUniform4i64vNV_ptr   = nullptr;
glProgramUniform1ui64NVPtr glProgramUniform1ui64NV_ptr   = nullptr;
glProgramUniform2ui64NVPtr glProgramUniform2ui64NV_ptr   = nullptr;
glProgramUniform3ui64NVPtr glProgramUniform3ui64NV_ptr   = nullptr;
glProgramUniform4ui64NVPtr glProgramUniform4ui64NV_ptr   = nullptr;
glProgramUniform1ui64vNVPtr glProgramUniform1ui64vNV_ptr = nullptr;
glProgramUniform2ui64vNVPtr glProgramUniform2ui64vNV_ptr = nullptr;
glProgramUniform3ui64vNVPtr glProgramUniform3ui64vNV_ptr = nullptr;
glProgramUniform4ui64vNVPtr glProgramUniform4ui64vNV_ptr = nullptr;

bool init_gl_nv_gpu_shader5([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glUniform1i64NV_ptr = reinterpret_cast<glUniform1i64NVPtr>(get_function("glUniform1i64NV"))) == nullptr || result;
    result = (glUniform2i64NV_ptr = reinterpret_cast<glUniform2i64NVPtr>(get_function("glUniform2i64NV"))) == nullptr || result;
    result = (glUniform3i64NV_ptr = reinterpret_cast<glUniform3i64NVPtr>(get_function("glUniform3i64NV"))) == nullptr || result;
    result = (glUniform4i64NV_ptr = reinterpret_cast<glUniform4i64NVPtr>(get_function("glUniform4i64NV"))) == nullptr || result;
    result = (glUniform1i64vNV_ptr = reinterpret_cast<glUniform1i64vNVPtr>(get_function("glUniform1i64vNV"))) == nullptr || result;
    result = (glUniform2i64vNV_ptr = reinterpret_cast<glUniform2i64vNVPtr>(get_function("glUniform2i64vNV"))) == nullptr || result;
    result = (glUniform3i64vNV_ptr = reinterpret_cast<glUniform3i64vNVPtr>(get_function("glUniform3i64vNV"))) == nullptr || result;
    result = (glUniform4i64vNV_ptr = reinterpret_cast<glUniform4i64vNVPtr>(get_function("glUniform4i64vNV"))) == nullptr || result;
    result = (glUniform1ui64NV_ptr = reinterpret_cast<glUniform1ui64NVPtr>(get_function("glUniform1ui64NV"))) == nullptr || result;
    result = (glUniform2ui64NV_ptr = reinterpret_cast<glUniform2ui64NVPtr>(get_function("glUniform2ui64NV"))) == nullptr || result;
    result = (glUniform3ui64NV_ptr = reinterpret_cast<glUniform3ui64NVPtr>(get_function("glUniform3ui64NV"))) == nullptr || result;
    result = (glUniform4ui64NV_ptr = reinterpret_cast<glUniform4ui64NVPtr>(get_function("glUniform4ui64NV"))) == nullptr || result;
    result = (glUniform1ui64vNV_ptr = reinterpret_cast<glUniform1ui64vNVPtr>(get_function("glUniform1ui64vNV"))) == nullptr || result;
    result = (glUniform2ui64vNV_ptr = reinterpret_cast<glUniform2ui64vNVPtr>(get_function("glUniform2ui64vNV"))) == nullptr || result;
    result = (glUniform3ui64vNV_ptr = reinterpret_cast<glUniform3ui64vNVPtr>(get_function("glUniform3ui64vNV"))) == nullptr || result;
    result = (glUniform4ui64vNV_ptr = reinterpret_cast<glUniform4ui64vNVPtr>(get_function("glUniform4ui64vNV"))) == nullptr || result;
    result = (glGetUniformi64vNV_ptr = reinterpret_cast<glGetUniformi64vNVPtr>(get_function("glGetUniformi64vNV"))) == nullptr || result;
    result = (glProgramUniform1i64NV_ptr = reinterpret_cast<glProgramUniform1i64NVPtr>(get_function("glProgramUniform1i64NV"))) == nullptr || result;
    result = (glProgramUniform2i64NV_ptr = reinterpret_cast<glProgramUniform2i64NVPtr>(get_function("glProgramUniform2i64NV"))) == nullptr || result;
    result = (glProgramUniform3i64NV_ptr = reinterpret_cast<glProgramUniform3i64NVPtr>(get_function("glProgramUniform3i64NV"))) == nullptr || result;
    result = (glProgramUniform4i64NV_ptr = reinterpret_cast<glProgramUniform4i64NVPtr>(get_function("glProgramUniform4i64NV"))) == nullptr || result;
    result = (glProgramUniform1i64vNV_ptr = reinterpret_cast<glProgramUniform1i64vNVPtr>(get_function("glProgramUniform1i64vNV"))) == nullptr || result;
    result = (glProgramUniform2i64vNV_ptr = reinterpret_cast<glProgramUniform2i64vNVPtr>(get_function("glProgramUniform2i64vNV"))) == nullptr || result;
    result = (glProgramUniform3i64vNV_ptr = reinterpret_cast<glProgramUniform3i64vNVPtr>(get_function("glProgramUniform3i64vNV"))) == nullptr || result;
    result = (glProgramUniform4i64vNV_ptr = reinterpret_cast<glProgramUniform4i64vNVPtr>(get_function("glProgramUniform4i64vNV"))) == nullptr || result;
    result = (glProgramUniform1ui64NV_ptr = reinterpret_cast<glProgramUniform1ui64NVPtr>(get_function("glProgramUniform1ui64NV"))) == nullptr || result;
    result = (glProgramUniform2ui64NV_ptr = reinterpret_cast<glProgramUniform2ui64NVPtr>(get_function("glProgramUniform2ui64NV"))) == nullptr || result;
    result = (glProgramUniform3ui64NV_ptr = reinterpret_cast<glProgramUniform3ui64NVPtr>(get_function("glProgramUniform3ui64NV"))) == nullptr || result;
    result = (glProgramUniform4ui64NV_ptr = reinterpret_cast<glProgramUniform4ui64NVPtr>(get_function("glProgramUniform4ui64NV"))) == nullptr || result;
    result = (glProgramUniform1ui64vNV_ptr = reinterpret_cast<glProgramUniform1ui64vNVPtr>(get_function("glProgramUniform1ui64vNV"))) == nullptr || result;
    result = (glProgramUniform2ui64vNV_ptr = reinterpret_cast<glProgramUniform2ui64vNVPtr>(get_function("glProgramUniform2ui64vNV"))) == nullptr || result;
    result = (glProgramUniform3ui64vNV_ptr = reinterpret_cast<glProgramUniform3ui64vNVPtr>(get_function("glProgramUniform3ui64vNV"))) == nullptr || result;
    result = (glProgramUniform4ui64vNV_ptr = reinterpret_cast<glProgramUniform4ui64vNVPtr>(get_function("glProgramUniform4ui64vNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_NV_internalformat_sample_query

using glGetInternalformatSampleivNVPtr = std::add_pointer_t<decltype(glGetInternalformatSampleivNV)>;

glGetInternalformatSampleivNVPtr glGetInternalformatSampleivNV_ptr = nullptr;

bool init_gl_nv_internalformat_sample_query([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glGetInternalformatSampleivNV_ptr = reinterpret_cast<glGetInternalformatSampleivNVPtr>(get_function("glGetInternalformatSampleivNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_NV_memory_attachment

using glGetMemoryObjectDetachedResourcesuivNVPtr = std::add_pointer_t<decltype(glGetMemoryObjectDetachedResourcesuivNV)>;
using glResetMemoryObjectParameterNVPtr          = std::add_pointer_t<decltype(glResetMemoryObjectParameterNV)>;
using glTexAttachMemoryNVPtr                     = std::add_pointer_t<decltype(glTexAttachMemoryNV)>;
using glBufferAttachMemoryNVPtr                  = std::add_pointer_t<decltype(glBufferAttachMemoryNV)>;
using glTextureAttachMemoryNVPtr                 = std::add_pointer_t<decltype(glTextureAttachMemoryNV)>;
using glNamedBufferAttachMemoryNVPtr             = std::add_pointer_t<decltype(glNamedBufferAttachMemoryNV)>;

glGetMemoryObjectDetachedResourcesuivNVPtr glGetMemoryObjectDetachedResourcesuivNV_ptr = nullptr;
glResetMemoryObjectParameterNVPtr glResetMemoryObjectParameterNV_ptr                   = nullptr;
glTexAttachMemoryNVPtr glTexAttachMemoryNV_ptr                                         = nullptr;
glBufferAttachMemoryNVPtr glBufferAttachMemoryNV_ptr                                   = nullptr;
glTextureAttachMemoryNVPtr glTextureAttachMemoryNV_ptr                                 = nullptr;
glNamedBufferAttachMemoryNVPtr glNamedBufferAttachMemoryNV_ptr                         = nullptr;

bool init_gl_nv_memory_attachment([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glGetMemoryObjectDetachedResourcesuivNV_ptr = reinterpret_cast<glGetMemoryObjectDetachedResourcesuivNVPtr>(get_function("glGetMemoryObjectDetachedResourcesuivNV"))) == nullptr || result;
    result = (glResetMemoryObjectParameterNV_ptr = reinterpret_cast<glResetMemoryObjectParameterNVPtr>(get_function("glResetMemoryObjectParameterNV"))) == nullptr || result;
    result = (glTexAttachMemoryNV_ptr = reinterpret_cast<glTexAttachMemoryNVPtr>(get_function("glTexAttachMemoryNV"))) == nullptr || result;
    result = (glBufferAttachMemoryNV_ptr = reinterpret_cast<glBufferAttachMemoryNVPtr>(get_function("glBufferAttachMemoryNV"))) == nullptr || result;
    result = (glTextureAttachMemoryNV_ptr = reinterpret_cast<glTextureAttachMemoryNVPtr>(get_function("glTextureAttachMemoryNV"))) == nullptr || result;
    result = (glNamedBufferAttachMemoryNV_ptr = reinterpret_cast<glNamedBufferAttachMemoryNVPtr>(get_function("glNamedBufferAttachMemoryNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_NV_mesh_shader

using glDrawMeshTasksNVPtr                   = std::add_pointer_t<decltype(glDrawMeshTasksNV)>;
using glDrawMeshTasksIndirectNVPtr           = std::add_pointer_t<decltype(glDrawMeshTasksIndirectNV)>;
using glMultiDrawMeshTasksIndirectNVPtr      = std::add_pointer_t<decltype(glMultiDrawMeshTasksIndirectNV)>;
using glMultiDrawMeshTasksIndirectCountNVPtr = std::add_pointer_t<decltype(glMultiDrawMeshTasksIndirectCountNV)>;

glDrawMeshTasksNVPtr glDrawMeshTasksNV_ptr                                     = nullptr;
glDrawMeshTasksIndirectNVPtr glDrawMeshTasksIndirectNV_ptr                     = nullptr;
glMultiDrawMeshTasksIndirectNVPtr glMultiDrawMeshTasksIndirectNV_ptr           = nullptr;
glMultiDrawMeshTasksIndirectCountNVPtr glMultiDrawMeshTasksIndirectCountNV_ptr = nullptr;

bool init_gl_nv_mesh_shader([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glDrawMeshTasksNV_ptr = reinterpret_cast<glDrawMeshTasksNVPtr>(get_function("glDrawMeshTasksNV"))) == nullptr || result;
    result = (glDrawMeshTasksIndirectNV_ptr = reinterpret_cast<glDrawMeshTasksIndirectNVPtr>(get_function("glDrawMeshTasksIndirectNV"))) == nullptr || result;
    result = (glMultiDrawMeshTasksIndirectNV_ptr = reinterpret_cast<glMultiDrawMeshTasksIndirectNVPtr>(get_function("glMultiDrawMeshTasksIndirectNV"))) == nullptr || result;
    result = (glMultiDrawMeshTasksIndirectCountNV_ptr = reinterpret_cast<glMultiDrawMeshTasksIndirectCountNVPtr>(get_function("glMultiDrawMeshTasksIndirectCountNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_NV_path_rendering

using glGenPathsNVPtr                            = std::add_pointer_t<decltype(glGenPathsNV)>;
using glDeletePathsNVPtr                         = std::add_pointer_t<decltype(glDeletePathsNV)>;
using glIsPathNVPtr                              = std::add_pointer_t<decltype(glIsPathNV)>;
using glPathCommandsNVPtr                        = std::add_pointer_t<decltype(glPathCommandsNV)>;
using glPathCoordsNVPtr                          = std::add_pointer_t<decltype(glPathCoordsNV)>;
using glPathSubCommandsNVPtr                     = std::add_pointer_t<decltype(glPathSubCommandsNV)>;
using glPathSubCoordsNVPtr                       = std::add_pointer_t<decltype(glPathSubCoordsNV)>;
using glPathStringNVPtr                          = std::add_pointer_t<decltype(glPathStringNV)>;
using glPathGlyphsNVPtr                          = std::add_pointer_t<decltype(glPathGlyphsNV)>;
using glPathGlyphRangeNVPtr                      = std::add_pointer_t<decltype(glPathGlyphRangeNV)>;
using glWeightPathsNVPtr                         = std::add_pointer_t<decltype(glWeightPathsNV)>;
using glCopyPathNVPtr                            = std::add_pointer_t<decltype(glCopyPathNV)>;
using glInterpolatePathsNVPtr                    = std::add_pointer_t<decltype(glInterpolatePathsNV)>;
using glTransformPathNVPtr                       = std::add_pointer_t<decltype(glTransformPathNV)>;
using glPathParameterivNVPtr                     = std::add_pointer_t<decltype(glPathParameterivNV)>;
using glPathParameteriNVPtr                      = std::add_pointer_t<decltype(glPathParameteriNV)>;
using glPathParameterfvNVPtr                     = std::add_pointer_t<decltype(glPathParameterfvNV)>;
using glPathParameterfNVPtr                      = std::add_pointer_t<decltype(glPathParameterfNV)>;
using glPathDashArrayNVPtr                       = std::add_pointer_t<decltype(glPathDashArrayNV)>;
using glPathStencilFuncNVPtr                     = std::add_pointer_t<decltype(glPathStencilFuncNV)>;
using glPathStencilDepthOffsetNVPtr              = std::add_pointer_t<decltype(glPathStencilDepthOffsetNV)>;
using glStencilFillPathNVPtr                     = std::add_pointer_t<decltype(glStencilFillPathNV)>;
using glStencilStrokePathNVPtr                   = std::add_pointer_t<decltype(glStencilStrokePathNV)>;
using glStencilFillPathInstancedNVPtr            = std::add_pointer_t<decltype(glStencilFillPathInstancedNV)>;
using glStencilStrokePathInstancedNVPtr          = std::add_pointer_t<decltype(glStencilStrokePathInstancedNV)>;
using glPathCoverDepthFuncNVPtr                  = std::add_pointer_t<decltype(glPathCoverDepthFuncNV)>;
using glCoverFillPathNVPtr                       = std::add_pointer_t<decltype(glCoverFillPathNV)>;
using glCoverStrokePathNVPtr                     = std::add_pointer_t<decltype(glCoverStrokePathNV)>;
using glCoverFillPathInstancedNVPtr              = std::add_pointer_t<decltype(glCoverFillPathInstancedNV)>;
using glCoverStrokePathInstancedNVPtr            = std::add_pointer_t<decltype(glCoverStrokePathInstancedNV)>;
using glGetPathParameterivNVPtr                  = std::add_pointer_t<decltype(glGetPathParameterivNV)>;
using glGetPathParameterfvNVPtr                  = std::add_pointer_t<decltype(glGetPathParameterfvNV)>;
using glGetPathCommandsNVPtr                     = std::add_pointer_t<decltype(glGetPathCommandsNV)>;
using glGetPathCoordsNVPtr                       = std::add_pointer_t<decltype(glGetPathCoordsNV)>;
using glGetPathDashArrayNVPtr                    = std::add_pointer_t<decltype(glGetPathDashArrayNV)>;
using glGetPathMetricsNVPtr                      = std::add_pointer_t<decltype(glGetPathMetricsNV)>;
using glGetPathMetricRangeNVPtr                  = std::add_pointer_t<decltype(glGetPathMetricRangeNV)>;
using glGetPathSpacingNVPtr                      = std::add_pointer_t<decltype(glGetPathSpacingNV)>;
using glIsPointInFillPathNVPtr                   = std::add_pointer_t<decltype(glIsPointInFillPathNV)>;
using glIsPointInStrokePathNVPtr                 = std::add_pointer_t<decltype(glIsPointInStrokePathNV)>;
using glGetPathLengthNVPtr                       = std::add_pointer_t<decltype(glGetPathLengthNV)>;
using glPointAlongPathNVPtr                      = std::add_pointer_t<decltype(glPointAlongPathNV)>;
using glMatrixLoad3x2fNVPtr                      = std::add_pointer_t<decltype(glMatrixLoad3x2fNV)>;
using glMatrixLoad3x3fNVPtr                      = std::add_pointer_t<decltype(glMatrixLoad3x3fNV)>;
using glMatrixLoadTranspose3x3fNVPtr             = std::add_pointer_t<decltype(glMatrixLoadTranspose3x3fNV)>;
using glMatrixMult3x2fNVPtr                      = std::add_pointer_t<decltype(glMatrixMult3x2fNV)>;
using glMatrixMult3x3fNVPtr                      = std::add_pointer_t<decltype(glMatrixMult3x3fNV)>;
using glMatrixMultTranspose3x3fNVPtr             = std::add_pointer_t<decltype(glMatrixMultTranspose3x3fNV)>;
using glStencilThenCoverFillPathNVPtr            = std::add_pointer_t<decltype(glStencilThenCoverFillPathNV)>;
using glStencilThenCoverStrokePathNVPtr          = std::add_pointer_t<decltype(glStencilThenCoverStrokePathNV)>;
using glStencilThenCoverFillPathInstancedNVPtr   = std::add_pointer_t<decltype(glStencilThenCoverFillPathInstancedNV)>;
using glStencilThenCoverStrokePathInstancedNVPtr = std::add_pointer_t<decltype(glStencilThenCoverStrokePathInstancedNV)>;
using glPathGlyphIndexRangeNVPtr                 = std::add_pointer_t<decltype(glPathGlyphIndexRangeNV)>;
using glPathGlyphIndexArrayNVPtr                 = std::add_pointer_t<decltype(glPathGlyphIndexArrayNV)>;
using glPathMemoryGlyphIndexArrayNVPtr           = std::add_pointer_t<decltype(glPathMemoryGlyphIndexArrayNV)>;
using glProgramPathFragmentInputGenNVPtr         = std::add_pointer_t<decltype(glProgramPathFragmentInputGenNV)>;
using glGetProgramResourcefvNVPtr                = std::add_pointer_t<decltype(glGetProgramResourcefvNV)>;

glGenPathsNVPtr glGenPathsNV_ptr                                                       = nullptr;
glDeletePathsNVPtr glDeletePathsNV_ptr                                                 = nullptr;
glIsPathNVPtr glIsPathNV_ptr                                                           = nullptr;
glPathCommandsNVPtr glPathCommandsNV_ptr                                               = nullptr;
glPathCoordsNVPtr glPathCoordsNV_ptr                                                   = nullptr;
glPathSubCommandsNVPtr glPathSubCommandsNV_ptr                                         = nullptr;
glPathSubCoordsNVPtr glPathSubCoordsNV_ptr                                             = nullptr;
glPathStringNVPtr glPathStringNV_ptr                                                   = nullptr;
glPathGlyphsNVPtr glPathGlyphsNV_ptr                                                   = nullptr;
glPathGlyphRangeNVPtr glPathGlyphRangeNV_ptr                                           = nullptr;
glWeightPathsNVPtr glWeightPathsNV_ptr                                                 = nullptr;
glCopyPathNVPtr glCopyPathNV_ptr                                                       = nullptr;
glInterpolatePathsNVPtr glInterpolatePathsNV_ptr                                       = nullptr;
glTransformPathNVPtr glTransformPathNV_ptr                                             = nullptr;
glPathParameterivNVPtr glPathParameterivNV_ptr                                         = nullptr;
glPathParameteriNVPtr glPathParameteriNV_ptr                                           = nullptr;
glPathParameterfvNVPtr glPathParameterfvNV_ptr                                         = nullptr;
glPathParameterfNVPtr glPathParameterfNV_ptr                                           = nullptr;
glPathDashArrayNVPtr glPathDashArrayNV_ptr                                             = nullptr;
glPathStencilFuncNVPtr glPathStencilFuncNV_ptr                                         = nullptr;
glPathStencilDepthOffsetNVPtr glPathStencilDepthOffsetNV_ptr                           = nullptr;
glStencilFillPathNVPtr glStencilFillPathNV_ptr                                         = nullptr;
glStencilStrokePathNVPtr glStencilStrokePathNV_ptr                                     = nullptr;
glStencilFillPathInstancedNVPtr glStencilFillPathInstancedNV_ptr                       = nullptr;
glStencilStrokePathInstancedNVPtr glStencilStrokePathInstancedNV_ptr                   = nullptr;
glPathCoverDepthFuncNVPtr glPathCoverDepthFuncNV_ptr                                   = nullptr;
glCoverFillPathNVPtr glCoverFillPathNV_ptr                                             = nullptr;
glCoverStrokePathNVPtr glCoverStrokePathNV_ptr                                         = nullptr;
glCoverFillPathInstancedNVPtr glCoverFillPathInstancedNV_ptr                           = nullptr;
glCoverStrokePathInstancedNVPtr glCoverStrokePathInstancedNV_ptr                       = nullptr;
glGetPathParameterivNVPtr glGetPathParameterivNV_ptr                                   = nullptr;
glGetPathParameterfvNVPtr glGetPathParameterfvNV_ptr                                   = nullptr;
glGetPathCommandsNVPtr glGetPathCommandsNV_ptr                                         = nullptr;
glGetPathCoordsNVPtr glGetPathCoordsNV_ptr                                             = nullptr;
glGetPathDashArrayNVPtr glGetPathDashArrayNV_ptr                                       = nullptr;
glGetPathMetricsNVPtr glGetPathMetricsNV_ptr                                           = nullptr;
glGetPathMetricRangeNVPtr glGetPathMetricRangeNV_ptr                                   = nullptr;
glGetPathSpacingNVPtr glGetPathSpacingNV_ptr                                           = nullptr;
glIsPointInFillPathNVPtr glIsPointInFillPathNV_ptr                                     = nullptr;
glIsPointInStrokePathNVPtr glIsPointInStrokePathNV_ptr                                 = nullptr;
glGetPathLengthNVPtr glGetPathLengthNV_ptr                                             = nullptr;
glPointAlongPathNVPtr glPointAlongPathNV_ptr                                           = nullptr;
glMatrixLoad3x2fNVPtr glMatrixLoad3x2fNV_ptr                                           = nullptr;
glMatrixLoad3x3fNVPtr glMatrixLoad3x3fNV_ptr                                           = nullptr;
glMatrixLoadTranspose3x3fNVPtr glMatrixLoadTranspose3x3fNV_ptr                         = nullptr;
glMatrixMult3x2fNVPtr glMatrixMult3x2fNV_ptr                                           = nullptr;
glMatrixMult3x3fNVPtr glMatrixMult3x3fNV_ptr                                           = nullptr;
glMatrixMultTranspose3x3fNVPtr glMatrixMultTranspose3x3fNV_ptr                         = nullptr;
glStencilThenCoverFillPathNVPtr glStencilThenCoverFillPathNV_ptr                       = nullptr;
glStencilThenCoverStrokePathNVPtr glStencilThenCoverStrokePathNV_ptr                   = nullptr;
glStencilThenCoverFillPathInstancedNVPtr glStencilThenCoverFillPathInstancedNV_ptr     = nullptr;
glStencilThenCoverStrokePathInstancedNVPtr glStencilThenCoverStrokePathInstancedNV_ptr = nullptr;
glPathGlyphIndexRangeNVPtr glPathGlyphIndexRangeNV_ptr                                 = nullptr;
glPathGlyphIndexArrayNVPtr glPathGlyphIndexArrayNV_ptr                                 = nullptr;
glPathMemoryGlyphIndexArrayNVPtr glPathMemoryGlyphIndexArrayNV_ptr                     = nullptr;
glProgramPathFragmentInputGenNVPtr glProgramPathFragmentInputGenNV_ptr                 = nullptr;
glGetProgramResourcefvNVPtr glGetProgramResourcefvNV_ptr                               = nullptr;

bool init_gl_nv_path_rendering([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glGenPathsNV_ptr = reinterpret_cast<glGenPathsNVPtr>(get_function("glGenPathsNV"))) == nullptr || result;
    result = (glDeletePathsNV_ptr = reinterpret_cast<glDeletePathsNVPtr>(get_function("glDeletePathsNV"))) == nullptr || result;
    result = (glIsPathNV_ptr = reinterpret_cast<glIsPathNVPtr>(get_function("glIsPathNV"))) == nullptr || result;
    result = (glPathCommandsNV_ptr = reinterpret_cast<glPathCommandsNVPtr>(get_function("glPathCommandsNV"))) == nullptr || result;
    result = (glPathCoordsNV_ptr = reinterpret_cast<glPathCoordsNVPtr>(get_function("glPathCoordsNV"))) == nullptr || result;
    result = (glPathSubCommandsNV_ptr = reinterpret_cast<glPathSubCommandsNVPtr>(get_function("glPathSubCommandsNV"))) == nullptr || result;
    result = (glPathSubCoordsNV_ptr = reinterpret_cast<glPathSubCoordsNVPtr>(get_function("glPathSubCoordsNV"))) == nullptr || result;
    result = (glPathStringNV_ptr = reinterpret_cast<glPathStringNVPtr>(get_function("glPathStringNV"))) == nullptr || result;
    result = (glPathGlyphsNV_ptr = reinterpret_cast<glPathGlyphsNVPtr>(get_function("glPathGlyphsNV"))) == nullptr || result;
    result = (glPathGlyphRangeNV_ptr = reinterpret_cast<glPathGlyphRangeNVPtr>(get_function("glPathGlyphRangeNV"))) == nullptr || result;
    result = (glWeightPathsNV_ptr = reinterpret_cast<glWeightPathsNVPtr>(get_function("glWeightPathsNV"))) == nullptr || result;
    result = (glCopyPathNV_ptr = reinterpret_cast<glCopyPathNVPtr>(get_function("glCopyPathNV"))) == nullptr || result;
    result = (glInterpolatePathsNV_ptr = reinterpret_cast<glInterpolatePathsNVPtr>(get_function("glInterpolatePathsNV"))) == nullptr || result;
    result = (glTransformPathNV_ptr = reinterpret_cast<glTransformPathNVPtr>(get_function("glTransformPathNV"))) == nullptr || result;
    result = (glPathParameterivNV_ptr = reinterpret_cast<glPathParameterivNVPtr>(get_function("glPathParameterivNV"))) == nullptr || result;
    result = (glPathParameteriNV_ptr = reinterpret_cast<glPathParameteriNVPtr>(get_function("glPathParameteriNV"))) == nullptr || result;
    result = (glPathParameterfvNV_ptr = reinterpret_cast<glPathParameterfvNVPtr>(get_function("glPathParameterfvNV"))) == nullptr || result;
    result = (glPathParameterfNV_ptr = reinterpret_cast<glPathParameterfNVPtr>(get_function("glPathParameterfNV"))) == nullptr || result;
    result = (glPathDashArrayNV_ptr = reinterpret_cast<glPathDashArrayNVPtr>(get_function("glPathDashArrayNV"))) == nullptr || result;
    result = (glPathStencilFuncNV_ptr = reinterpret_cast<glPathStencilFuncNVPtr>(get_function("glPathStencilFuncNV"))) == nullptr || result;
    result = (glPathStencilDepthOffsetNV_ptr = reinterpret_cast<glPathStencilDepthOffsetNVPtr>(get_function("glPathStencilDepthOffsetNV"))) == nullptr || result;
    result = (glStencilFillPathNV_ptr = reinterpret_cast<glStencilFillPathNVPtr>(get_function("glStencilFillPathNV"))) == nullptr || result;
    result = (glStencilStrokePathNV_ptr = reinterpret_cast<glStencilStrokePathNVPtr>(get_function("glStencilStrokePathNV"))) == nullptr || result;
    result = (glStencilFillPathInstancedNV_ptr = reinterpret_cast<glStencilFillPathInstancedNVPtr>(get_function("glStencilFillPathInstancedNV"))) == nullptr || result;
    result = (glStencilStrokePathInstancedNV_ptr = reinterpret_cast<glStencilStrokePathInstancedNVPtr>(get_function("glStencilStrokePathInstancedNV"))) == nullptr || result;
    result = (glPathCoverDepthFuncNV_ptr = reinterpret_cast<glPathCoverDepthFuncNVPtr>(get_function("glPathCoverDepthFuncNV"))) == nullptr || result;
    result = (glCoverFillPathNV_ptr = reinterpret_cast<glCoverFillPathNVPtr>(get_function("glCoverFillPathNV"))) == nullptr || result;
    result = (glCoverStrokePathNV_ptr = reinterpret_cast<glCoverStrokePathNVPtr>(get_function("glCoverStrokePathNV"))) == nullptr || result;
    result = (glCoverFillPathInstancedNV_ptr = reinterpret_cast<glCoverFillPathInstancedNVPtr>(get_function("glCoverFillPathInstancedNV"))) == nullptr || result;
    result = (glCoverStrokePathInstancedNV_ptr = reinterpret_cast<glCoverStrokePathInstancedNVPtr>(get_function("glCoverStrokePathInstancedNV"))) == nullptr || result;
    result = (glGetPathParameterivNV_ptr = reinterpret_cast<glGetPathParameterivNVPtr>(get_function("glGetPathParameterivNV"))) == nullptr || result;
    result = (glGetPathParameterfvNV_ptr = reinterpret_cast<glGetPathParameterfvNVPtr>(get_function("glGetPathParameterfvNV"))) == nullptr || result;
    result = (glGetPathCommandsNV_ptr = reinterpret_cast<glGetPathCommandsNVPtr>(get_function("glGetPathCommandsNV"))) == nullptr || result;
    result = (glGetPathCoordsNV_ptr = reinterpret_cast<glGetPathCoordsNVPtr>(get_function("glGetPathCoordsNV"))) == nullptr || result;
    result = (glGetPathDashArrayNV_ptr = reinterpret_cast<glGetPathDashArrayNVPtr>(get_function("glGetPathDashArrayNV"))) == nullptr || result;
    result = (glGetPathMetricsNV_ptr = reinterpret_cast<glGetPathMetricsNVPtr>(get_function("glGetPathMetricsNV"))) == nullptr || result;
    result = (glGetPathMetricRangeNV_ptr = reinterpret_cast<glGetPathMetricRangeNVPtr>(get_function("glGetPathMetricRangeNV"))) == nullptr || result;
    result = (glGetPathSpacingNV_ptr = reinterpret_cast<glGetPathSpacingNVPtr>(get_function("glGetPathSpacingNV"))) == nullptr || result;
    result = (glIsPointInFillPathNV_ptr = reinterpret_cast<glIsPointInFillPathNVPtr>(get_function("glIsPointInFillPathNV"))) == nullptr || result;
    result = (glIsPointInStrokePathNV_ptr = reinterpret_cast<glIsPointInStrokePathNVPtr>(get_function("glIsPointInStrokePathNV"))) == nullptr || result;
    result = (glGetPathLengthNV_ptr = reinterpret_cast<glGetPathLengthNVPtr>(get_function("glGetPathLengthNV"))) == nullptr || result;
    result = (glPointAlongPathNV_ptr = reinterpret_cast<glPointAlongPathNVPtr>(get_function("glPointAlongPathNV"))) == nullptr || result;
    result = (glMatrixLoad3x2fNV_ptr = reinterpret_cast<glMatrixLoad3x2fNVPtr>(get_function("glMatrixLoad3x2fNV"))) == nullptr || result;
    result = (glMatrixLoad3x3fNV_ptr = reinterpret_cast<glMatrixLoad3x3fNVPtr>(get_function("glMatrixLoad3x3fNV"))) == nullptr || result;
    result = (glMatrixLoadTranspose3x3fNV_ptr = reinterpret_cast<glMatrixLoadTranspose3x3fNVPtr>(get_function("glMatrixLoadTranspose3x3fNV"))) == nullptr || result;
    result = (glMatrixMult3x2fNV_ptr = reinterpret_cast<glMatrixMult3x2fNVPtr>(get_function("glMatrixMult3x2fNV"))) == nullptr || result;
    result = (glMatrixMult3x3fNV_ptr = reinterpret_cast<glMatrixMult3x3fNVPtr>(get_function("glMatrixMult3x3fNV"))) == nullptr || result;
    result = (glMatrixMultTranspose3x3fNV_ptr = reinterpret_cast<glMatrixMultTranspose3x3fNVPtr>(get_function("glMatrixMultTranspose3x3fNV"))) == nullptr || result;
    result = (glStencilThenCoverFillPathNV_ptr = reinterpret_cast<glStencilThenCoverFillPathNVPtr>(get_function("glStencilThenCoverFillPathNV"))) == nullptr || result;
    result = (glStencilThenCoverStrokePathNV_ptr = reinterpret_cast<glStencilThenCoverStrokePathNVPtr>(get_function("glStencilThenCoverStrokePathNV"))) == nullptr || result;
    result = (glStencilThenCoverFillPathInstancedNV_ptr = reinterpret_cast<glStencilThenCoverFillPathInstancedNVPtr>(get_function("glStencilThenCoverFillPathInstancedNV"))) == nullptr || result;
    result = (glStencilThenCoverStrokePathInstancedNV_ptr = reinterpret_cast<glStencilThenCoverStrokePathInstancedNVPtr>(get_function("glStencilThenCoverStrokePathInstancedNV"))) == nullptr || result;
    result = (glPathGlyphIndexRangeNV_ptr = reinterpret_cast<glPathGlyphIndexRangeNVPtr>(get_function("glPathGlyphIndexRangeNV"))) == nullptr || result;
    result = (glPathGlyphIndexArrayNV_ptr = reinterpret_cast<glPathGlyphIndexArrayNVPtr>(get_function("glPathGlyphIndexArrayNV"))) == nullptr || result;
    result = (glPathMemoryGlyphIndexArrayNV_ptr = reinterpret_cast<glPathMemoryGlyphIndexArrayNVPtr>(get_function("glPathMemoryGlyphIndexArrayNV"))) == nullptr || result;
    result = (glProgramPathFragmentInputGenNV_ptr = reinterpret_cast<glProgramPathFragmentInputGenNVPtr>(get_function("glProgramPathFragmentInputGenNV"))) == nullptr || result;
    result = (glGetProgramResourcefvNV_ptr = reinterpret_cast<glGetProgramResourcefvNVPtr>(get_function("glGetProgramResourcefvNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_NV_path_rendering_shared_edge

bool init_gl_nv_path_rendering_shared_edge([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_NV_representative_fragment_test

bool init_gl_nv_representative_fragment_test([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_NV_sample_locations

using glFramebufferSampleLocationsfvNVPtr      = std::add_pointer_t<decltype(glFramebufferSampleLocationsfvNV)>;
using glNamedFramebufferSampleLocationsfvNVPtr = std::add_pointer_t<decltype(glNamedFramebufferSampleLocationsfvNV)>;
using glResolveDepthValuesNVPtr                = std::add_pointer_t<decltype(glResolveDepthValuesNV)>;

glFramebufferSampleLocationsfvNVPtr glFramebufferSampleLocationsfvNV_ptr           = nullptr;
glNamedFramebufferSampleLocationsfvNVPtr glNamedFramebufferSampleLocationsfvNV_ptr = nullptr;
glResolveDepthValuesNVPtr glResolveDepthValuesNV_ptr                               = nullptr;

bool init_gl_nv_sample_locations([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glFramebufferSampleLocationsfvNV_ptr = reinterpret_cast<glFramebufferSampleLocationsfvNVPtr>(get_function("glFramebufferSampleLocationsfvNV"))) == nullptr || result;
    result = (glNamedFramebufferSampleLocationsfvNV_ptr = reinterpret_cast<glNamedFramebufferSampleLocationsfvNVPtr>(get_function("glNamedFramebufferSampleLocationsfvNV"))) == nullptr || result;
    result = (glResolveDepthValuesNV_ptr = reinterpret_cast<glResolveDepthValuesNVPtr>(get_function("glResolveDepthValuesNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_NV_sample_mask_override_coverage

bool init_gl_nv_sample_mask_override_coverage([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_NV_scissor_exclusive

using glScissorExclusiveNVPtr       = std::add_pointer_t<decltype(glScissorExclusiveNV)>;
using glScissorExclusiveArrayvNVPtr = std::add_pointer_t<decltype(glScissorExclusiveArrayvNV)>;

glScissorExclusiveNVPtr glScissorExclusiveNV_ptr             = nullptr;
glScissorExclusiveArrayvNVPtr glScissorExclusiveArrayvNV_ptr = nullptr;

bool init_gl_nv_scissor_exclusive([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glScissorExclusiveNV_ptr = reinterpret_cast<glScissorExclusiveNVPtr>(get_function("glScissorExclusiveNV"))) == nullptr || result;
    result = (glScissorExclusiveArrayvNV_ptr = reinterpret_cast<glScissorExclusiveArrayvNVPtr>(get_function("glScissorExclusiveArrayvNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_NV_shader_atomic_counters

bool init_gl_nv_shader_atomic_counters([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_NV_shader_atomic_float

bool init_gl_nv_shader_atomic_float([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_NV_shader_atomic_float64

bool init_gl_nv_shader_atomic_float64([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_NV_shader_atomic_fp16_vector

bool init_gl_nv_shader_atomic_fp16_vector([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_NV_shader_atomic_int64

bool init_gl_nv_shader_atomic_int64([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_NV_shader_buffer_load

using glMakeBufferResidentNVPtr           = std::add_pointer_t<decltype(glMakeBufferResidentNV)>;
using glMakeBufferNonResidentNVPtr        = std::add_pointer_t<decltype(glMakeBufferNonResidentNV)>;
using glIsBufferResidentNVPtr             = std::add_pointer_t<decltype(glIsBufferResidentNV)>;
using glMakeNamedBufferResidentNVPtr      = std::add_pointer_t<decltype(glMakeNamedBufferResidentNV)>;
using glMakeNamedBufferNonResidentNVPtr   = std::add_pointer_t<decltype(glMakeNamedBufferNonResidentNV)>;
using glIsNamedBufferResidentNVPtr        = std::add_pointer_t<decltype(glIsNamedBufferResidentNV)>;
using glGetBufferParameterui64vNVPtr      = std::add_pointer_t<decltype(glGetBufferParameterui64vNV)>;
using glGetNamedBufferParameterui64vNVPtr = std::add_pointer_t<decltype(glGetNamedBufferParameterui64vNV)>;
using glGetIntegerui64vNVPtr              = std::add_pointer_t<decltype(glGetIntegerui64vNV)>;
using glUniformui64NVPtr                  = std::add_pointer_t<decltype(glUniformui64NV)>;
using glUniformui64vNVPtr                 = std::add_pointer_t<decltype(glUniformui64vNV)>;
using glGetUniformui64vNVPtr              = std::add_pointer_t<decltype(glGetUniformui64vNV)>;
using glProgramUniformui64NVPtr           = std::add_pointer_t<decltype(glProgramUniformui64NV)>;
using glProgramUniformui64vNVPtr          = std::add_pointer_t<decltype(glProgramUniformui64vNV)>;

glMakeBufferResidentNVPtr glMakeBufferResidentNV_ptr                     = nullptr;
glMakeBufferNonResidentNVPtr glMakeBufferNonResidentNV_ptr               = nullptr;
glIsBufferResidentNVPtr glIsBufferResidentNV_ptr                         = nullptr;
glMakeNamedBufferResidentNVPtr glMakeNamedBufferResidentNV_ptr           = nullptr;
glMakeNamedBufferNonResidentNVPtr glMakeNamedBufferNonResidentNV_ptr     = nullptr;
glIsNamedBufferResidentNVPtr glIsNamedBufferResidentNV_ptr               = nullptr;
glGetBufferParameterui64vNVPtr glGetBufferParameterui64vNV_ptr           = nullptr;
glGetNamedBufferParameterui64vNVPtr glGetNamedBufferParameterui64vNV_ptr = nullptr;
glGetIntegerui64vNVPtr glGetIntegerui64vNV_ptr                           = nullptr;
glUniformui64NVPtr glUniformui64NV_ptr                                   = nullptr;
glUniformui64vNVPtr glUniformui64vNV_ptr                                 = nullptr;
glGetUniformui64vNVPtr glGetUniformui64vNV_ptr                           = nullptr;
glProgramUniformui64NVPtr glProgramUniformui64NV_ptr                     = nullptr;
glProgramUniformui64vNVPtr glProgramUniformui64vNV_ptr                   = nullptr;

bool init_gl_nv_shader_buffer_load([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glMakeBufferResidentNV_ptr = reinterpret_cast<glMakeBufferResidentNVPtr>(get_function("glMakeBufferResidentNV"))) == nullptr || result;
    result = (glMakeBufferNonResidentNV_ptr = reinterpret_cast<glMakeBufferNonResidentNVPtr>(get_function("glMakeBufferNonResidentNV"))) == nullptr || result;
    result = (glIsBufferResidentNV_ptr = reinterpret_cast<glIsBufferResidentNVPtr>(get_function("glIsBufferResidentNV"))) == nullptr || result;
    result = (glMakeNamedBufferResidentNV_ptr = reinterpret_cast<glMakeNamedBufferResidentNVPtr>(get_function("glMakeNamedBufferResidentNV"))) == nullptr || result;
    result = (glMakeNamedBufferNonResidentNV_ptr = reinterpret_cast<glMakeNamedBufferNonResidentNVPtr>(get_function("glMakeNamedBufferNonResidentNV"))) == nullptr || result;
    result = (glIsNamedBufferResidentNV_ptr = reinterpret_cast<glIsNamedBufferResidentNVPtr>(get_function("glIsNamedBufferResidentNV"))) == nullptr || result;
    result = (glGetBufferParameterui64vNV_ptr = reinterpret_cast<glGetBufferParameterui64vNVPtr>(get_function("glGetBufferParameterui64vNV"))) == nullptr || result;
    result = (glGetNamedBufferParameterui64vNV_ptr = reinterpret_cast<glGetNamedBufferParameterui64vNVPtr>(get_function("glGetNamedBufferParameterui64vNV"))) == nullptr || result;
    result = (glGetIntegerui64vNV_ptr = reinterpret_cast<glGetIntegerui64vNVPtr>(get_function("glGetIntegerui64vNV"))) == nullptr || result;
    result = (glUniformui64NV_ptr = reinterpret_cast<glUniformui64NVPtr>(get_function("glUniformui64NV"))) == nullptr || result;
    result = (glUniformui64vNV_ptr = reinterpret_cast<glUniformui64vNVPtr>(get_function("glUniformui64vNV"))) == nullptr || result;
    result = (glGetUniformui64vNV_ptr = reinterpret_cast<glGetUniformui64vNVPtr>(get_function("glGetUniformui64vNV"))) == nullptr || result;
    result = (glProgramUniformui64NV_ptr = reinterpret_cast<glProgramUniformui64NVPtr>(get_function("glProgramUniformui64NV"))) == nullptr || result;
    result = (glProgramUniformui64vNV_ptr = reinterpret_cast<glProgramUniformui64vNVPtr>(get_function("glProgramUniformui64vNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_NV_shader_buffer_store

bool init_gl_nv_shader_buffer_store([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_NV_shader_subgroup_partitioned

bool init_gl_nv_shader_subgroup_partitioned([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_NV_shader_texture_footprint

bool init_gl_nv_shader_texture_footprint([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_NV_shader_thread_group

bool init_gl_nv_shader_thread_group([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_NV_shader_thread_shuffle

bool init_gl_nv_shader_thread_shuffle([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_NV_shading_rate_image

using glBindShadingRateImageNVPtr           = std::add_pointer_t<decltype(glBindShadingRateImageNV)>;
using glGetShadingRateImagePaletteNVPtr     = std::add_pointer_t<decltype(glGetShadingRateImagePaletteNV)>;
using glGetShadingRateSampleLocationivNVPtr = std::add_pointer_t<decltype(glGetShadingRateSampleLocationivNV)>;
using glShadingRateImageBarrierNVPtr        = std::add_pointer_t<decltype(glShadingRateImageBarrierNV)>;
using glShadingRateImagePaletteNVPtr        = std::add_pointer_t<decltype(glShadingRateImagePaletteNV)>;
using glShadingRateSampleOrderNVPtr         = std::add_pointer_t<decltype(glShadingRateSampleOrderNV)>;
using glShadingRateSampleOrderCustomNVPtr   = std::add_pointer_t<decltype(glShadingRateSampleOrderCustomNV)>;

glBindShadingRateImageNVPtr glBindShadingRateImageNV_ptr                     = nullptr;
glGetShadingRateImagePaletteNVPtr glGetShadingRateImagePaletteNV_ptr         = nullptr;
glGetShadingRateSampleLocationivNVPtr glGetShadingRateSampleLocationivNV_ptr = nullptr;
glShadingRateImageBarrierNVPtr glShadingRateImageBarrierNV_ptr               = nullptr;
glShadingRateImagePaletteNVPtr glShadingRateImagePaletteNV_ptr               = nullptr;
glShadingRateSampleOrderNVPtr glShadingRateSampleOrderNV_ptr                 = nullptr;
glShadingRateSampleOrderCustomNVPtr glShadingRateSampleOrderCustomNV_ptr     = nullptr;

bool init_gl_nv_shading_rate_image([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glBindShadingRateImageNV_ptr = reinterpret_cast<glBindShadingRateImageNVPtr>(get_function("glBindShadingRateImageNV"))) == nullptr || result;
    result = (glGetShadingRateImagePaletteNV_ptr = reinterpret_cast<glGetShadingRateImagePaletteNVPtr>(get_function("glGetShadingRateImagePaletteNV"))) == nullptr || result;
    result = (glGetShadingRateSampleLocationivNV_ptr = reinterpret_cast<glGetShadingRateSampleLocationivNVPtr>(get_function("glGetShadingRateSampleLocationivNV"))) == nullptr || result;
    result = (glShadingRateImageBarrierNV_ptr = reinterpret_cast<glShadingRateImageBarrierNVPtr>(get_function("glShadingRateImageBarrierNV"))) == nullptr || result;
    result = (glShadingRateImagePaletteNV_ptr = reinterpret_cast<glShadingRateImagePaletteNVPtr>(get_function("glShadingRateImagePaletteNV"))) == nullptr || result;
    result = (glShadingRateSampleOrderNV_ptr = reinterpret_cast<glShadingRateSampleOrderNVPtr>(get_function("glShadingRateSampleOrderNV"))) == nullptr || result;
    result = (glShadingRateSampleOrderCustomNV_ptr = reinterpret_cast<glShadingRateSampleOrderCustomNVPtr>(get_function("glShadingRateSampleOrderCustomNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_NV_stereo_view_rendering

bool init_gl_nv_stereo_view_rendering([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_NV_texture_barrier

using glTextureBarrierNVPtr = std::add_pointer_t<decltype(glTextureBarrierNV)>;

glTextureBarrierNVPtr glTextureBarrierNV_ptr = nullptr;

bool init_gl_nv_texture_barrier([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glTextureBarrierNV_ptr = reinterpret_cast<glTextureBarrierNVPtr>(get_function("glTextureBarrierNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_NV_texture_rectangle_compressed

bool init_gl_nv_texture_rectangle_compressed([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_NV_uniform_buffer_unified_memory

bool init_gl_nv_uniform_buffer_unified_memory([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_NV_vertex_attrib_integer_64bit

using glVertexAttribL1i64NVPtr     = std::add_pointer_t<decltype(glVertexAttribL1i64NV)>;
using glVertexAttribL2i64NVPtr     = std::add_pointer_t<decltype(glVertexAttribL2i64NV)>;
using glVertexAttribL3i64NVPtr     = std::add_pointer_t<decltype(glVertexAttribL3i64NV)>;
using glVertexAttribL4i64NVPtr     = std::add_pointer_t<decltype(glVertexAttribL4i64NV)>;
using glVertexAttribL1i64vNVPtr    = std::add_pointer_t<decltype(glVertexAttribL1i64vNV)>;
using glVertexAttribL2i64vNVPtr    = std::add_pointer_t<decltype(glVertexAttribL2i64vNV)>;
using glVertexAttribL3i64vNVPtr    = std::add_pointer_t<decltype(glVertexAttribL3i64vNV)>;
using glVertexAttribL4i64vNVPtr    = std::add_pointer_t<decltype(glVertexAttribL4i64vNV)>;
using glVertexAttribL1ui64NVPtr    = std::add_pointer_t<decltype(glVertexAttribL1ui64NV)>;
using glVertexAttribL2ui64NVPtr    = std::add_pointer_t<decltype(glVertexAttribL2ui64NV)>;
using glVertexAttribL3ui64NVPtr    = std::add_pointer_t<decltype(glVertexAttribL3ui64NV)>;
using glVertexAttribL4ui64NVPtr    = std::add_pointer_t<decltype(glVertexAttribL4ui64NV)>;
using glVertexAttribL1ui64vNVPtr   = std::add_pointer_t<decltype(glVertexAttribL1ui64vNV)>;
using glVertexAttribL2ui64vNVPtr   = std::add_pointer_t<decltype(glVertexAttribL2ui64vNV)>;
using glVertexAttribL3ui64vNVPtr   = std::add_pointer_t<decltype(glVertexAttribL3ui64vNV)>;
using glVertexAttribL4ui64vNVPtr   = std::add_pointer_t<decltype(glVertexAttribL4ui64vNV)>;
using glGetVertexAttribLi64vNVPtr  = std::add_pointer_t<decltype(glGetVertexAttribLi64vNV)>;
using glGetVertexAttribLui64vNVPtr = std::add_pointer_t<decltype(glGetVertexAttribLui64vNV)>;
using glVertexAttribLFormatNVPtr   = std::add_pointer_t<decltype(glVertexAttribLFormatNV)>;

glVertexAttribL1i64NVPtr glVertexAttribL1i64NV_ptr         = nullptr;
glVertexAttribL2i64NVPtr glVertexAttribL2i64NV_ptr         = nullptr;
glVertexAttribL3i64NVPtr glVertexAttribL3i64NV_ptr         = nullptr;
glVertexAttribL4i64NVPtr glVertexAttribL4i64NV_ptr         = nullptr;
glVertexAttribL1i64vNVPtr glVertexAttribL1i64vNV_ptr       = nullptr;
glVertexAttribL2i64vNVPtr glVertexAttribL2i64vNV_ptr       = nullptr;
glVertexAttribL3i64vNVPtr glVertexAttribL3i64vNV_ptr       = nullptr;
glVertexAttribL4i64vNVPtr glVertexAttribL4i64vNV_ptr       = nullptr;
glVertexAttribL1ui64NVPtr glVertexAttribL1ui64NV_ptr       = nullptr;
glVertexAttribL2ui64NVPtr glVertexAttribL2ui64NV_ptr       = nullptr;
glVertexAttribL3ui64NVPtr glVertexAttribL3ui64NV_ptr       = nullptr;
glVertexAttribL4ui64NVPtr glVertexAttribL4ui64NV_ptr       = nullptr;
glVertexAttribL1ui64vNVPtr glVertexAttribL1ui64vNV_ptr     = nullptr;
glVertexAttribL2ui64vNVPtr glVertexAttribL2ui64vNV_ptr     = nullptr;
glVertexAttribL3ui64vNVPtr glVertexAttribL3ui64vNV_ptr     = nullptr;
glVertexAttribL4ui64vNVPtr glVertexAttribL4ui64vNV_ptr     = nullptr;
glGetVertexAttribLi64vNVPtr glGetVertexAttribLi64vNV_ptr   = nullptr;
glGetVertexAttribLui64vNVPtr glGetVertexAttribLui64vNV_ptr = nullptr;
glVertexAttribLFormatNVPtr glVertexAttribLFormatNV_ptr     = nullptr;

bool init_gl_nv_vertex_attrib_integer_64bit([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glVertexAttribL1i64NV_ptr = reinterpret_cast<glVertexAttribL1i64NVPtr>(get_function("glVertexAttribL1i64NV"))) == nullptr || result;
    result = (glVertexAttribL2i64NV_ptr = reinterpret_cast<glVertexAttribL2i64NVPtr>(get_function("glVertexAttribL2i64NV"))) == nullptr || result;
    result = (glVertexAttribL3i64NV_ptr = reinterpret_cast<glVertexAttribL3i64NVPtr>(get_function("glVertexAttribL3i64NV"))) == nullptr || result;
    result = (glVertexAttribL4i64NV_ptr = reinterpret_cast<glVertexAttribL4i64NVPtr>(get_function("glVertexAttribL4i64NV"))) == nullptr || result;
    result = (glVertexAttribL1i64vNV_ptr = reinterpret_cast<glVertexAttribL1i64vNVPtr>(get_function("glVertexAttribL1i64vNV"))) == nullptr || result;
    result = (glVertexAttribL2i64vNV_ptr = reinterpret_cast<glVertexAttribL2i64vNVPtr>(get_function("glVertexAttribL2i64vNV"))) == nullptr || result;
    result = (glVertexAttribL3i64vNV_ptr = reinterpret_cast<glVertexAttribL3i64vNVPtr>(get_function("glVertexAttribL3i64vNV"))) == nullptr || result;
    result = (glVertexAttribL4i64vNV_ptr = reinterpret_cast<glVertexAttribL4i64vNVPtr>(get_function("glVertexAttribL4i64vNV"))) == nullptr || result;
    result = (glVertexAttribL1ui64NV_ptr = reinterpret_cast<glVertexAttribL1ui64NVPtr>(get_function("glVertexAttribL1ui64NV"))) == nullptr || result;
    result = (glVertexAttribL2ui64NV_ptr = reinterpret_cast<glVertexAttribL2ui64NVPtr>(get_function("glVertexAttribL2ui64NV"))) == nullptr || result;
    result = (glVertexAttribL3ui64NV_ptr = reinterpret_cast<glVertexAttribL3ui64NVPtr>(get_function("glVertexAttribL3ui64NV"))) == nullptr || result;
    result = (glVertexAttribL4ui64NV_ptr = reinterpret_cast<glVertexAttribL4ui64NVPtr>(get_function("glVertexAttribL4ui64NV"))) == nullptr || result;
    result = (glVertexAttribL1ui64vNV_ptr = reinterpret_cast<glVertexAttribL1ui64vNVPtr>(get_function("glVertexAttribL1ui64vNV"))) == nullptr || result;
    result = (glVertexAttribL2ui64vNV_ptr = reinterpret_cast<glVertexAttribL2ui64vNVPtr>(get_function("glVertexAttribL2ui64vNV"))) == nullptr || result;
    result = (glVertexAttribL3ui64vNV_ptr = reinterpret_cast<glVertexAttribL3ui64vNVPtr>(get_function("glVertexAttribL3ui64vNV"))) == nullptr || result;
    result = (glVertexAttribL4ui64vNV_ptr = reinterpret_cast<glVertexAttribL4ui64vNVPtr>(get_function("glVertexAttribL4ui64vNV"))) == nullptr || result;
    result = (glGetVertexAttribLi64vNV_ptr = reinterpret_cast<glGetVertexAttribLi64vNVPtr>(get_function("glGetVertexAttribLi64vNV"))) == nullptr || result;
    result = (glGetVertexAttribLui64vNV_ptr = reinterpret_cast<glGetVertexAttribLui64vNVPtr>(get_function("glGetVertexAttribLui64vNV"))) == nullptr || result;
    result = (glVertexAttribLFormatNV_ptr = reinterpret_cast<glVertexAttribLFormatNVPtr>(get_function("glVertexAttribLFormatNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_NV_vertex_buffer_unified_memory

using glBufferAddressRangeNVPtr   = std::add_pointer_t<decltype(glBufferAddressRangeNV)>;
using glVertexFormatNVPtr         = std::add_pointer_t<decltype(glVertexFormatNV)>;
using glNormalFormatNVPtr         = std::add_pointer_t<decltype(glNormalFormatNV)>;
using glColorFormatNVPtr          = std::add_pointer_t<decltype(glColorFormatNV)>;
using glIndexFormatNVPtr          = std::add_pointer_t<decltype(glIndexFormatNV)>;
using glTexCoordFormatNVPtr       = std::add_pointer_t<decltype(glTexCoordFormatNV)>;
using glEdgeFlagFormatNVPtr       = std::add_pointer_t<decltype(glEdgeFlagFormatNV)>;
using glSecondaryColorFormatNVPtr = std::add_pointer_t<decltype(glSecondaryColorFormatNV)>;
using glFogCoordFormatNVPtr       = std::add_pointer_t<decltype(glFogCoordFormatNV)>;
using glVertexAttribFormatNVPtr   = std::add_pointer_t<decltype(glVertexAttribFormatNV)>;
using glVertexAttribIFormatNVPtr  = std::add_pointer_t<decltype(glVertexAttribIFormatNV)>;
using glGetIntegerui64i_vNVPtr    = std::add_pointer_t<decltype(glGetIntegerui64i_vNV)>;

glBufferAddressRangeNVPtr glBufferAddressRangeNV_ptr     = nullptr;
glVertexFormatNVPtr glVertexFormatNV_ptr                 = nullptr;
glNormalFormatNVPtr glNormalFormatNV_ptr                 = nullptr;
glColorFormatNVPtr glColorFormatNV_ptr                   = nullptr;
glIndexFormatNVPtr glIndexFormatNV_ptr                   = nullptr;
glTexCoordFormatNVPtr glTexCoordFormatNV_ptr             = nullptr;
glEdgeFlagFormatNVPtr glEdgeFlagFormatNV_ptr             = nullptr;
glSecondaryColorFormatNVPtr glSecondaryColorFormatNV_ptr = nullptr;
glFogCoordFormatNVPtr glFogCoordFormatNV_ptr             = nullptr;
glVertexAttribFormatNVPtr glVertexAttribFormatNV_ptr     = nullptr;
glVertexAttribIFormatNVPtr glVertexAttribIFormatNV_ptr   = nullptr;
glGetIntegerui64i_vNVPtr glGetIntegerui64i_vNV_ptr       = nullptr;

bool init_gl_nv_vertex_buffer_unified_memory([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glBufferAddressRangeNV_ptr = reinterpret_cast<glBufferAddressRangeNVPtr>(get_function("glBufferAddressRangeNV"))) == nullptr || result;
    result = (glVertexFormatNV_ptr = reinterpret_cast<glVertexFormatNVPtr>(get_function("glVertexFormatNV"))) == nullptr || result;
    result = (glNormalFormatNV_ptr = reinterpret_cast<glNormalFormatNVPtr>(get_function("glNormalFormatNV"))) == nullptr || result;
    result = (glColorFormatNV_ptr = reinterpret_cast<glColorFormatNVPtr>(get_function("glColorFormatNV"))) == nullptr || result;
    result = (glIndexFormatNV_ptr = reinterpret_cast<glIndexFormatNVPtr>(get_function("glIndexFormatNV"))) == nullptr || result;
    result = (glTexCoordFormatNV_ptr = reinterpret_cast<glTexCoordFormatNVPtr>(get_function("glTexCoordFormatNV"))) == nullptr || result;
    result = (glEdgeFlagFormatNV_ptr = reinterpret_cast<glEdgeFlagFormatNVPtr>(get_function("glEdgeFlagFormatNV"))) == nullptr || result;
    result = (glSecondaryColorFormatNV_ptr = reinterpret_cast<glSecondaryColorFormatNVPtr>(get_function("glSecondaryColorFormatNV"))) == nullptr || result;
    result = (glFogCoordFormatNV_ptr = reinterpret_cast<glFogCoordFormatNVPtr>(get_function("glFogCoordFormatNV"))) == nullptr || result;
    result = (glVertexAttribFormatNV_ptr = reinterpret_cast<glVertexAttribFormatNVPtr>(get_function("glVertexAttribFormatNV"))) == nullptr || result;
    result = (glVertexAttribIFormatNV_ptr = reinterpret_cast<glVertexAttribIFormatNVPtr>(get_function("glVertexAttribIFormatNV"))) == nullptr || result;
    result = (glGetIntegerui64i_vNV_ptr = reinterpret_cast<glGetIntegerui64i_vNVPtr>(get_function("glGetIntegerui64i_vNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_NV_viewport_array2

bool init_gl_nv_viewport_array2([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_NV_viewport_swizzle

using glViewportSwizzleNVPtr = std::add_pointer_t<decltype(glViewportSwizzleNV)>;

glViewportSwizzleNVPtr glViewportSwizzleNV_ptr = nullptr;

bool init_gl_nv_viewport_swizzle([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glViewportSwizzleNV_ptr = reinterpret_cast<glViewportSwizzleNVPtr>(get_function("glViewportSwizzleNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_OVR_multiview

using glFramebufferTextureMultiviewOVRPtr = std::add_pointer_t<decltype(glFramebufferTextureMultiviewOVR)>;

glFramebufferTextureMultiviewOVRPtr glFramebufferTextureMultiviewOVR_ptr = nullptr;

bool init_gl_ovr_multiview([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glFramebufferTextureMultiviewOVR_ptr = reinterpret_cast<glFramebufferTextureMultiviewOVRPtr>(get_function("glFramebufferTextureMultiviewOVR"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GL_OVR_multiview2

bool init_gl_ovr_multiview2([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GL_EXT_texture_shadow_lod

bool init_gl_ext_texture_shadow_lod([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

std::once_flag init_flag;

bool feature_cache[19] = {};

bool extension_cache[236] = {};

void init_features([[maybe_unused]] const GetFunction& get_function)
{
    // clang-format off
    feature_cache[static_cast<int>(Feature::GL_VERSION_1_0)] = init_gl_version_1_0(get_function);
    feature_cache[static_cast<int>(Feature::GL_VERSION_1_1)] = init_gl_version_1_1(get_function);
    feature_cache[static_cast<int>(Feature::GL_VERSION_1_2)] = init_gl_version_1_2(get_function);
    feature_cache[static_cast<int>(Feature::GL_VERSION_1_3)] = init_gl_version_1_3(get_function);
    feature_cache[static_cast<int>(Feature::GL_VERSION_1_4)] = init_gl_version_1_4(get_function);
    feature_cache[static_cast<int>(Feature::GL_VERSION_1_5)] = init_gl_version_1_5(get_function);
    feature_cache[static_cast<int>(Feature::GL_VERSION_2_0)] = init_gl_version_2_0(get_function);
    feature_cache[static_cast<int>(Feature::GL_VERSION_2_1)] = init_gl_version_2_1(get_function);
    feature_cache[static_cast<int>(Feature::GL_VERSION_3_0)] = init_gl_version_3_0(get_function);
    feature_cache[static_cast<int>(Feature::GL_VERSION_3_1)] = init_gl_version_3_1(get_function);
    feature_cache[static_cast<int>(Feature::GL_VERSION_3_2)] = init_gl_version_3_2(get_function);
    feature_cache[static_cast<int>(Feature::GL_VERSION_3_3)] = init_gl_version_3_3(get_function);
    feature_cache[static_cast<int>(Feature::GL_VERSION_4_0)] = init_gl_version_4_0(get_function);
    feature_cache[static_cast<int>(Feature::GL_VERSION_4_1)] = init_gl_version_4_1(get_function);
    feature_cache[static_cast<int>(Feature::GL_VERSION_4_2)] = init_gl_version_4_2(get_function);
    feature_cache[static_cast<int>(Feature::GL_VERSION_4_3)] = init_gl_version_4_3(get_function);
    feature_cache[static_cast<int>(Feature::GL_VERSION_4_4)] = init_gl_version_4_4(get_function);
    feature_cache[static_cast<int>(Feature::GL_VERSION_4_5)] = init_gl_version_4_5(get_function);
    feature_cache[static_cast<int>(Feature::GL_VERSION_4_6)] = init_gl_version_4_6(get_function);
    // clang-format on
}

void init_extensions([[maybe_unused]] const GetFunction& get_function)
{
    // clang-format off
    extension_cache[static_cast<int>(Extension::GL_AMD_framebuffer_multisample_advanced)] = init_gl_amd_framebuffer_multisample_advanced(get_function);
    extension_cache[static_cast<int>(Extension::GL_AMD_performance_monitor)] = init_gl_amd_performance_monitor(get_function);
    extension_cache[static_cast<int>(Extension::GL_APPLE_rgb_422)] = init_gl_apple_rgb_422(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_ES2_compatibility)] = init_gl_arb_es2_compatibility(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_ES3_1_compatibility)] = init_gl_arb_es3_1_compatibility(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_ES3_2_compatibility)] = init_gl_arb_es3_2_compatibility(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_ES3_compatibility)] = init_gl_arb_es3_compatibility(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_arrays_of_arrays)] = init_gl_arb_arrays_of_arrays(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_base_instance)] = init_gl_arb_base_instance(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_bindless_texture)] = init_gl_arb_bindless_texture(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_blend_func_extended)] = init_gl_arb_blend_func_extended(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_buffer_storage)] = init_gl_arb_buffer_storage(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_cl_event)] = init_gl_arb_cl_event(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_clear_buffer_object)] = init_gl_arb_clear_buffer_object(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_clear_texture)] = init_gl_arb_clear_texture(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_clip_control)] = init_gl_arb_clip_control(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_compressed_texture_pixel_storage)] = init_gl_arb_compressed_texture_pixel_storage(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_compute_shader)] = init_gl_arb_compute_shader(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_compute_variable_group_size)] = init_gl_arb_compute_variable_group_size(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_conditional_render_inverted)] = init_gl_arb_conditional_render_inverted(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_conservative_depth)] = init_gl_arb_conservative_depth(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_copy_buffer)] = init_gl_arb_copy_buffer(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_copy_image)] = init_gl_arb_copy_image(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_cull_distance)] = init_gl_arb_cull_distance(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_debug_output)] = init_gl_arb_debug_output(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_depth_buffer_float)] = init_gl_arb_depth_buffer_float(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_depth_clamp)] = init_gl_arb_depth_clamp(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_derivative_control)] = init_gl_arb_derivative_control(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_direct_state_access)] = init_gl_arb_direct_state_access(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_draw_buffers_blend)] = init_gl_arb_draw_buffers_blend(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_draw_elements_base_vertex)] = init_gl_arb_draw_elements_base_vertex(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_draw_indirect)] = init_gl_arb_draw_indirect(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_draw_instanced)] = init_gl_arb_draw_instanced(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_enhanced_layouts)] = init_gl_arb_enhanced_layouts(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_explicit_attrib_location)] = init_gl_arb_explicit_attrib_location(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_explicit_uniform_location)] = init_gl_arb_explicit_uniform_location(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_fragment_coord_conventions)] = init_gl_arb_fragment_coord_conventions(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_fragment_layer_viewport)] = init_gl_arb_fragment_layer_viewport(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_fragment_shader_interlock)] = init_gl_arb_fragment_shader_interlock(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_framebuffer_no_attachments)] = init_gl_arb_framebuffer_no_attachments(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_framebuffer_object)] = init_gl_arb_framebuffer_object(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_framebuffer_sRGB)] = init_gl_arb_framebuffer_srgb(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_geometry_shader4)] = init_gl_arb_geometry_shader4(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_get_program_binary)] = init_gl_arb_get_program_binary(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_get_texture_sub_image)] = init_gl_arb_get_texture_sub_image(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_gl_spirv)] = init_gl_arb_gl_spirv(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_gpu_shader5)] = init_gl_arb_gpu_shader5(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_gpu_shader_fp64)] = init_gl_arb_gpu_shader_fp64(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_gpu_shader_int64)] = init_gl_arb_gpu_shader_int64(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_half_float_vertex)] = init_gl_arb_half_float_vertex(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_imaging)] = init_gl_arb_imaging(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_indirect_parameters)] = init_gl_arb_indirect_parameters(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_instanced_arrays)] = init_gl_arb_instanced_arrays(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_internalformat_query)] = init_gl_arb_internalformat_query(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_internalformat_query2)] = init_gl_arb_internalformat_query2(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_invalidate_subdata)] = init_gl_arb_invalidate_subdata(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_map_buffer_alignment)] = init_gl_arb_map_buffer_alignment(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_map_buffer_range)] = init_gl_arb_map_buffer_range(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_multi_bind)] = init_gl_arb_multi_bind(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_multi_draw_indirect)] = init_gl_arb_multi_draw_indirect(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_occlusion_query2)] = init_gl_arb_occlusion_query2(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_parallel_shader_compile)] = init_gl_arb_parallel_shader_compile(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_pipeline_statistics_query)] = init_gl_arb_pipeline_statistics_query(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_pixel_buffer_object)] = init_gl_arb_pixel_buffer_object(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_polygon_offset_clamp)] = init_gl_arb_polygon_offset_clamp(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_post_depth_coverage)] = init_gl_arb_post_depth_coverage(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_program_interface_query)] = init_gl_arb_program_interface_query(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_provoking_vertex)] = init_gl_arb_provoking_vertex(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_query_buffer_object)] = init_gl_arb_query_buffer_object(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_robust_buffer_access_behavior)] = init_gl_arb_robust_buffer_access_behavior(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_robustness)] = init_gl_arb_robustness(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_robustness_isolation)] = init_gl_arb_robustness_isolation(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_sample_locations)] = init_gl_arb_sample_locations(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_sample_shading)] = init_gl_arb_sample_shading(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_sampler_objects)] = init_gl_arb_sampler_objects(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_seamless_cube_map)] = init_gl_arb_seamless_cube_map(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_seamless_cubemap_per_texture)] = init_gl_arb_seamless_cubemap_per_texture(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_separate_shader_objects)] = init_gl_arb_separate_shader_objects(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_shader_atomic_counter_ops)] = init_gl_arb_shader_atomic_counter_ops(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_shader_atomic_counters)] = init_gl_arb_shader_atomic_counters(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_shader_ballot)] = init_gl_arb_shader_ballot(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_shader_bit_encoding)] = init_gl_arb_shader_bit_encoding(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_shader_clock)] = init_gl_arb_shader_clock(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_shader_draw_parameters)] = init_gl_arb_shader_draw_parameters(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_shader_group_vote)] = init_gl_arb_shader_group_vote(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_shader_image_load_store)] = init_gl_arb_shader_image_load_store(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_shader_image_size)] = init_gl_arb_shader_image_size(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_shader_precision)] = init_gl_arb_shader_precision(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_shader_stencil_export)] = init_gl_arb_shader_stencil_export(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_shader_storage_buffer_object)] = init_gl_arb_shader_storage_buffer_object(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_shader_subroutine)] = init_gl_arb_shader_subroutine(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_shader_texture_image_samples)] = init_gl_arb_shader_texture_image_samples(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_shader_viewport_layer_array)] = init_gl_arb_shader_viewport_layer_array(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_shading_language_420pack)] = init_gl_arb_shading_language_420pack(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_shading_language_include)] = init_gl_arb_shading_language_include(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_shading_language_packing)] = init_gl_arb_shading_language_packing(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_sparse_buffer)] = init_gl_arb_sparse_buffer(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_sparse_texture)] = init_gl_arb_sparse_texture(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_sparse_texture2)] = init_gl_arb_sparse_texture2(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_sparse_texture_clamp)] = init_gl_arb_sparse_texture_clamp(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_spirv_extensions)] = init_gl_arb_spirv_extensions(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_stencil_texturing)] = init_gl_arb_stencil_texturing(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_sync)] = init_gl_arb_sync(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_tessellation_shader)] = init_gl_arb_tessellation_shader(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_texture_barrier)] = init_gl_arb_texture_barrier(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_texture_border_clamp)] = init_gl_arb_texture_border_clamp(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_texture_buffer_object)] = init_gl_arb_texture_buffer_object(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_texture_buffer_object_rgb32)] = init_gl_arb_texture_buffer_object_rgb32(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_texture_buffer_range)] = init_gl_arb_texture_buffer_range(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_texture_compression_bptc)] = init_gl_arb_texture_compression_bptc(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_texture_compression_rgtc)] = init_gl_arb_texture_compression_rgtc(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_texture_cube_map_array)] = init_gl_arb_texture_cube_map_array(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_texture_filter_anisotropic)] = init_gl_arb_texture_filter_anisotropic(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_texture_filter_minmax)] = init_gl_arb_texture_filter_minmax(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_texture_gather)] = init_gl_arb_texture_gather(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_texture_mirror_clamp_to_edge)] = init_gl_arb_texture_mirror_clamp_to_edge(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_texture_mirrored_repeat)] = init_gl_arb_texture_mirrored_repeat(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_texture_multisample)] = init_gl_arb_texture_multisample(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_texture_non_power_of_two)] = init_gl_arb_texture_non_power_of_two(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_texture_query_levels)] = init_gl_arb_texture_query_levels(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_texture_query_lod)] = init_gl_arb_texture_query_lod(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_texture_rg)] = init_gl_arb_texture_rg(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_texture_rgb10_a2ui)] = init_gl_arb_texture_rgb10_a2ui(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_texture_stencil8)] = init_gl_arb_texture_stencil8(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_texture_storage)] = init_gl_arb_texture_storage(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_texture_storage_multisample)] = init_gl_arb_texture_storage_multisample(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_texture_swizzle)] = init_gl_arb_texture_swizzle(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_texture_view)] = init_gl_arb_texture_view(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_timer_query)] = init_gl_arb_timer_query(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_transform_feedback2)] = init_gl_arb_transform_feedback2(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_transform_feedback3)] = init_gl_arb_transform_feedback3(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_transform_feedback_instanced)] = init_gl_arb_transform_feedback_instanced(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_transform_feedback_overflow_query)] = init_gl_arb_transform_feedback_overflow_query(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_uniform_buffer_object)] = init_gl_arb_uniform_buffer_object(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_vertex_array_bgra)] = init_gl_arb_vertex_array_bgra(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_vertex_array_object)] = init_gl_arb_vertex_array_object(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_vertex_attrib_64bit)] = init_gl_arb_vertex_attrib_64bit(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_vertex_attrib_binding)] = init_gl_arb_vertex_attrib_binding(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_vertex_type_10f_11f_11f_rev)] = init_gl_arb_vertex_type_10f_11f_11f_rev(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_vertex_type_2_10_10_10_rev)] = init_gl_arb_vertex_type_2_10_10_10_rev(get_function);
    extension_cache[static_cast<int>(Extension::GL_ARB_viewport_array)] = init_gl_arb_viewport_array(get_function);
    extension_cache[static_cast<int>(Extension::GL_EXT_EGL_image_storage)] = init_gl_ext_egl_image_storage(get_function);
    extension_cache[static_cast<int>(Extension::GL_EXT_EGL_sync)] = init_gl_ext_egl_sync(get_function);
    extension_cache[static_cast<int>(Extension::GL_EXT_debug_label)] = init_gl_ext_debug_label(get_function);
    extension_cache[static_cast<int>(Extension::GL_EXT_debug_marker)] = init_gl_ext_debug_marker(get_function);
    extension_cache[static_cast<int>(Extension::GL_EXT_direct_state_access)] = init_gl_ext_direct_state_access(get_function);
    extension_cache[static_cast<int>(Extension::GL_EXT_draw_instanced)] = init_gl_ext_draw_instanced(get_function);
    extension_cache[static_cast<int>(Extension::GL_EXT_multiview_tessellation_geometry_shader)] = init_gl_ext_multiview_tessellation_geometry_shader(get_function);
    extension_cache[static_cast<int>(Extension::GL_EXT_multiview_texture_multisample)] = init_gl_ext_multiview_texture_multisample(get_function);
    extension_cache[static_cast<int>(Extension::GL_EXT_multiview_timer_query)] = init_gl_ext_multiview_timer_query(get_function);
    extension_cache[static_cast<int>(Extension::GL_EXT_polygon_offset_clamp)] = init_gl_ext_polygon_offset_clamp(get_function);
    extension_cache[static_cast<int>(Extension::GL_EXT_post_depth_coverage)] = init_gl_ext_post_depth_coverage(get_function);
    extension_cache[static_cast<int>(Extension::GL_EXT_raster_multisample)] = init_gl_ext_raster_multisample(get_function);
    extension_cache[static_cast<int>(Extension::GL_EXT_separate_shader_objects)] = init_gl_ext_separate_shader_objects(get_function);
    extension_cache[static_cast<int>(Extension::GL_EXT_shader_framebuffer_fetch)] = init_gl_ext_shader_framebuffer_fetch(get_function);
    extension_cache[static_cast<int>(Extension::GL_EXT_shader_framebuffer_fetch_non_coherent)] = init_gl_ext_shader_framebuffer_fetch_non_coherent(get_function);
    extension_cache[static_cast<int>(Extension::GL_EXT_shader_integer_mix)] = init_gl_ext_shader_integer_mix(get_function);
    extension_cache[static_cast<int>(Extension::GL_EXT_texture_compression_s3tc)] = init_gl_ext_texture_compression_s3tc(get_function);
    extension_cache[static_cast<int>(Extension::GL_EXT_texture_filter_minmax)] = init_gl_ext_texture_filter_minmax(get_function);
    extension_cache[static_cast<int>(Extension::GL_EXT_texture_sRGB_R8)] = init_gl_ext_texture_srgb_r8(get_function);
    extension_cache[static_cast<int>(Extension::GL_EXT_texture_sRGB_decode)] = init_gl_ext_texture_srgb_decode(get_function);
    extension_cache[static_cast<int>(Extension::GL_EXT_window_rectangles)] = init_gl_ext_window_rectangles(get_function);
    extension_cache[static_cast<int>(Extension::GL_INTEL_conservative_rasterization)] = init_gl_intel_conservative_rasterization(get_function);
    extension_cache[static_cast<int>(Extension::GL_INTEL_framebuffer_CMAA)] = init_gl_intel_framebuffer_cmaa(get_function);
    extension_cache[static_cast<int>(Extension::GL_INTEL_blackhole_render)] = init_gl_intel_blackhole_render(get_function);
    extension_cache[static_cast<int>(Extension::GL_INTEL_performance_query)] = init_gl_intel_performance_query(get_function);
    extension_cache[static_cast<int>(Extension::GL_KHR_blend_equation_advanced)] = init_gl_khr_blend_equation_advanced(get_function);
    extension_cache[static_cast<int>(Extension::GL_KHR_blend_equation_advanced_coherent)] = init_gl_khr_blend_equation_advanced_coherent(get_function);
    extension_cache[static_cast<int>(Extension::GL_KHR_context_flush_control)] = init_gl_khr_context_flush_control(get_function);
    extension_cache[static_cast<int>(Extension::GL_KHR_debug)] = init_gl_khr_debug(get_function);
    extension_cache[static_cast<int>(Extension::GL_KHR_no_error)] = init_gl_khr_no_error(get_function);
    extension_cache[static_cast<int>(Extension::GL_KHR_robust_buffer_access_behavior)] = init_gl_khr_robust_buffer_access_behavior(get_function);
    extension_cache[static_cast<int>(Extension::GL_KHR_robustness)] = init_gl_khr_robustness(get_function);
    extension_cache[static_cast<int>(Extension::GL_KHR_shader_subgroup)] = init_gl_khr_shader_subgroup(get_function);
    extension_cache[static_cast<int>(Extension::GL_KHR_texture_compression_astc_hdr)] = init_gl_khr_texture_compression_astc_hdr(get_function);
    extension_cache[static_cast<int>(Extension::GL_KHR_texture_compression_astc_ldr)] = init_gl_khr_texture_compression_astc_ldr(get_function);
    extension_cache[static_cast<int>(Extension::GL_KHR_texture_compression_astc_sliced_3d)] = init_gl_khr_texture_compression_astc_sliced_3d(get_function);
    extension_cache[static_cast<int>(Extension::GL_KHR_parallel_shader_compile)] = init_gl_khr_parallel_shader_compile(get_function);
    extension_cache[static_cast<int>(Extension::GL_MESA_framebuffer_flip_y)] = init_gl_mesa_framebuffer_flip_y(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_bindless_multi_draw_indirect)] = init_gl_nv_bindless_multi_draw_indirect(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_bindless_multi_draw_indirect_count)] = init_gl_nv_bindless_multi_draw_indirect_count(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_bindless_texture)] = init_gl_nv_bindless_texture(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_blend_equation_advanced)] = init_gl_nv_blend_equation_advanced(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_blend_equation_advanced_coherent)] = init_gl_nv_blend_equation_advanced_coherent(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_blend_minmax_factor)] = init_gl_nv_blend_minmax_factor(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_clip_space_w_scaling)] = init_gl_nv_clip_space_w_scaling(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_command_list)] = init_gl_nv_command_list(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_compute_shader_derivatives)] = init_gl_nv_compute_shader_derivatives(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_conditional_render)] = init_gl_nv_conditional_render(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_conservative_raster)] = init_gl_nv_conservative_raster(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_conservative_raster_dilate)] = init_gl_nv_conservative_raster_dilate(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_conservative_raster_pre_snap)] = init_gl_nv_conservative_raster_pre_snap(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_conservative_raster_pre_snap_triangles)] = init_gl_nv_conservative_raster_pre_snap_triangles(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_conservative_raster_underestimation)] = init_gl_nv_conservative_raster_underestimation(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_depth_buffer_float)] = init_gl_nv_depth_buffer_float(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_draw_vulkan_image)] = init_gl_nv_draw_vulkan_image(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_fill_rectangle)] = init_gl_nv_fill_rectangle(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_fragment_coverage_to_color)] = init_gl_nv_fragment_coverage_to_color(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_fragment_shader_barycentric)] = init_gl_nv_fragment_shader_barycentric(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_fragment_shader_interlock)] = init_gl_nv_fragment_shader_interlock(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_framebuffer_mixed_samples)] = init_gl_nv_framebuffer_mixed_samples(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_framebuffer_multisample_coverage)] = init_gl_nv_framebuffer_multisample_coverage(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_geometry_shader_passthrough)] = init_gl_nv_geometry_shader_passthrough(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_gpu_shader5)] = init_gl_nv_gpu_shader5(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_internalformat_sample_query)] = init_gl_nv_internalformat_sample_query(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_memory_attachment)] = init_gl_nv_memory_attachment(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_mesh_shader)] = init_gl_nv_mesh_shader(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_path_rendering)] = init_gl_nv_path_rendering(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_path_rendering_shared_edge)] = init_gl_nv_path_rendering_shared_edge(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_representative_fragment_test)] = init_gl_nv_representative_fragment_test(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_sample_locations)] = init_gl_nv_sample_locations(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_sample_mask_override_coverage)] = init_gl_nv_sample_mask_override_coverage(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_scissor_exclusive)] = init_gl_nv_scissor_exclusive(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_shader_atomic_counters)] = init_gl_nv_shader_atomic_counters(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_shader_atomic_float)] = init_gl_nv_shader_atomic_float(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_shader_atomic_float64)] = init_gl_nv_shader_atomic_float64(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_shader_atomic_fp16_vector)] = init_gl_nv_shader_atomic_fp16_vector(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_shader_atomic_int64)] = init_gl_nv_shader_atomic_int64(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_shader_buffer_load)] = init_gl_nv_shader_buffer_load(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_shader_buffer_store)] = init_gl_nv_shader_buffer_store(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_shader_subgroup_partitioned)] = init_gl_nv_shader_subgroup_partitioned(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_shader_texture_footprint)] = init_gl_nv_shader_texture_footprint(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_shader_thread_group)] = init_gl_nv_shader_thread_group(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_shader_thread_shuffle)] = init_gl_nv_shader_thread_shuffle(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_shading_rate_image)] = init_gl_nv_shading_rate_image(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_stereo_view_rendering)] = init_gl_nv_stereo_view_rendering(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_texture_barrier)] = init_gl_nv_texture_barrier(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_texture_rectangle_compressed)] = init_gl_nv_texture_rectangle_compressed(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_uniform_buffer_unified_memory)] = init_gl_nv_uniform_buffer_unified_memory(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_vertex_attrib_integer_64bit)] = init_gl_nv_vertex_attrib_integer_64bit(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_vertex_buffer_unified_memory)] = init_gl_nv_vertex_buffer_unified_memory(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_viewport_array2)] = init_gl_nv_viewport_array2(get_function);
    extension_cache[static_cast<int>(Extension::GL_NV_viewport_swizzle)] = init_gl_nv_viewport_swizzle(get_function);
    extension_cache[static_cast<int>(Extension::GL_OVR_multiview)] = init_gl_ovr_multiview(get_function);
    extension_cache[static_cast<int>(Extension::GL_OVR_multiview2)] = init_gl_ovr_multiview2(get_function);
    extension_cache[static_cast<int>(Extension::GL_EXT_texture_shadow_lod)] = init_gl_ext_texture_shadow_lod(get_function);
    // clang-format on
}

} // namespace

namespace framework::graphics::details::opengl
{

#pragma region GL_VERSION_1_0

void glCullFace(GLenum mode)
{
    glCullFace_ptr(mode);
}

void glFrontFace(GLenum mode)
{
    glFrontFace_ptr(mode);
}

void glHint(GLenum target, GLenum mode)
{
    glHint_ptr(target, mode);
}

void glLineWidth(GLfloat width)
{
    glLineWidth_ptr(width);
}

void glPointSize(GLfloat size)
{
    glPointSize_ptr(size);
}

void glPolygonMode(GLenum face, GLenum mode)
{
    glPolygonMode_ptr(face, mode);
}

void glScissor(GLint x, GLint y, GLsizei width, GLsizei height)
{
    glScissor_ptr(x, y, width, height);
}

void glTexParameterf(GLenum target, GLenum pname, GLfloat param)
{
    glTexParameterf_ptr(target, pname, param);
}

void glTexParameterfv(GLenum target, GLenum pname, const GLfloat* params)
{
    glTexParameterfv_ptr(target, pname, params);
}

void glTexParameteri(GLenum target, GLenum pname, GLint param)
{
    glTexParameteri_ptr(target, pname, param);
}

void glTexParameteriv(GLenum target, GLenum pname, const GLint* params)
{
    glTexParameteriv_ptr(target, pname, params);
}

void glTexImage1D(GLenum target,
                  GLint level,
                  GLint internalformat,
                  GLsizei width,
                  GLint border,
                  GLenum format,
                  GLenum type,
                  const void* pixels)
{
    glTexImage1D_ptr(target, level, internalformat, width, border, format, type, pixels);
}

void glTexImage2D(GLenum target,
                  GLint level,
                  GLint internalformat,
                  GLsizei width,
                  GLsizei height,
                  GLint border,
                  GLenum format,
                  GLenum type,
                  const void* pixels)
{
    glTexImage2D_ptr(target, level, internalformat, width, height, border, format, type, pixels);
}

void glDrawBuffer(GLenum buf)
{
    glDrawBuffer_ptr(buf);
}

void glClear(GLbitfield mask)
{
    glClear_ptr(mask);
}

void glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
    glClearColor_ptr(red, green, blue, alpha);
}

void glClearStencil(GLint s)
{
    glClearStencil_ptr(s);
}

void glClearDepth(GLdouble depth)
{
    glClearDepth_ptr(depth);
}

void glStencilMask(GLuint mask)
{
    glStencilMask_ptr(mask);
}

void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)
{
    glColorMask_ptr(red, green, blue, alpha);
}

void glDepthMask(GLboolean flag)
{
    glDepthMask_ptr(flag);
}

void glDisable(GLenum cap)
{
    glDisable_ptr(cap);
}

void glEnable(GLenum cap)
{
    glEnable_ptr(cap);
}

void glFinish()
{
    glFinish_ptr();
}

void glFlush()
{
    glFlush_ptr();
}

void glBlendFunc(GLenum sfactor, GLenum dfactor)
{
    glBlendFunc_ptr(sfactor, dfactor);
}

void glLogicOp(GLenum opcode)
{
    glLogicOp_ptr(opcode);
}

void glStencilFunc(GLenum func, GLint ref, GLuint mask)
{
    glStencilFunc_ptr(func, ref, mask);
}

void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass)
{
    glStencilOp_ptr(fail, zfail, zpass);
}

void glDepthFunc(GLenum func)
{
    glDepthFunc_ptr(func);
}

void glPixelStoref(GLenum pname, GLfloat param)
{
    glPixelStoref_ptr(pname, param);
}

void glPixelStorei(GLenum pname, GLint param)
{
    glPixelStorei_ptr(pname, param);
}

void glReadBuffer(GLenum src)
{
    glReadBuffer_ptr(src);
}

void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void* pixels)
{
    glReadPixels_ptr(x, y, width, height, format, type, pixels);
}

void glGetBooleanv(GLenum pname, GLboolean* data)
{
    glGetBooleanv_ptr(pname, data);
}

void glGetDoublev(GLenum pname, GLdouble* data)
{
    glGetDoublev_ptr(pname, data);
}

GLenum glGetError()
{
    return glGetError_ptr();
}

void glGetFloatv(GLenum pname, GLfloat* data)
{
    glGetFloatv_ptr(pname, data);
}

void glGetIntegerv(GLenum pname, GLint* data)
{
    glGetIntegerv_ptr(pname, data);
}

const GLubyte* glGetString(GLenum name)
{
    return glGetString_ptr(name);
}

void glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, void* pixels)
{
    glGetTexImage_ptr(target, level, format, type, pixels);
}

void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat* params)
{
    glGetTexParameterfv_ptr(target, pname, params);
}

void glGetTexParameteriv(GLenum target, GLenum pname, GLint* params)
{
    glGetTexParameteriv_ptr(target, pname, params);
}

void glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat* params)
{
    glGetTexLevelParameterfv_ptr(target, level, pname, params);
}

void glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint* params)
{
    glGetTexLevelParameteriv_ptr(target, level, pname, params);
}

GLboolean glIsEnabled(GLenum cap)
{
    return glIsEnabled_ptr(cap);
}

void glDepthRange(GLdouble n, GLdouble f)
{
    glDepthRange_ptr(n, f);
}

void glViewport(GLint x, GLint y, GLsizei width, GLsizei height)
{
    glViewport_ptr(x, y, width, height);
}

#pragma endregion

#pragma region GL_VERSION_1_1

void glDrawArrays(GLenum mode, GLint first, GLsizei count)
{
    glDrawArrays_ptr(mode, first, count);
}

void glDrawElements(GLenum mode, GLsizei count, GLenum type, const void* indices)
{
    glDrawElements_ptr(mode, count, type, indices);
}

void glPolygonOffset(GLfloat factor, GLfloat units)
{
    glPolygonOffset_ptr(factor, units);
}

void glCopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border)
{
    glCopyTexImage1D_ptr(target, level, internalformat, x, y, width, border);
}

void glCopyTexImage2D(GLenum target,
                      GLint level,
                      GLenum internalformat,
                      GLint x,
                      GLint y,
                      GLsizei width,
                      GLsizei height,
                      GLint border)
{
    glCopyTexImage2D_ptr(target, level, internalformat, x, y, width, height, border);
}

void glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width)
{
    glCopyTexSubImage1D_ptr(target, level, xoffset, x, y, width);
}

void glCopyTexSubImage2D(GLenum target,
                         GLint level,
                         GLint xoffset,
                         GLint yoffset,
                         GLint x,
                         GLint y,
                         GLsizei width,
                         GLsizei height)
{
    glCopyTexSubImage2D_ptr(target, level, xoffset, yoffset, x, y, width, height);
}

void glTexSubImage1D(GLenum target,
                     GLint level,
                     GLint xoffset,
                     GLsizei width,
                     GLenum format,
                     GLenum type,
                     const void* pixels)
{
    glTexSubImage1D_ptr(target, level, xoffset, width, format, type, pixels);
}

void glTexSubImage2D(GLenum target,
                     GLint level,
                     GLint xoffset,
                     GLint yoffset,
                     GLsizei width,
                     GLsizei height,
                     GLenum format,
                     GLenum type,
                     const void* pixels)
{
    glTexSubImage2D_ptr(target, level, xoffset, yoffset, width, height, format, type, pixels);
}

void glBindTexture(GLenum target, GLuint texture)
{
    glBindTexture_ptr(target, texture);
}

void glDeleteTextures(GLsizei n, const GLuint* textures)
{
    glDeleteTextures_ptr(n, textures);
}

void glGenTextures(GLsizei n, GLuint* textures)
{
    glGenTextures_ptr(n, textures);
}

GLboolean glIsTexture(GLuint texture)
{
    return glIsTexture_ptr(texture);
}

#pragma endregion

#pragma region GL_VERSION_1_2

void glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices)
{
    glDrawRangeElements_ptr(mode, start, end, count, type, indices);
}

void glTexImage3D(GLenum target,
                  GLint level,
                  GLint internalformat,
                  GLsizei width,
                  GLsizei height,
                  GLsizei depth,
                  GLint border,
                  GLenum format,
                  GLenum type,
                  const void* pixels)
{
    glTexImage3D_ptr(target, level, internalformat, width, height, depth, border, format, type, pixels);
}

void glTexSubImage3D(GLenum target,
                     GLint level,
                     GLint xoffset,
                     GLint yoffset,
                     GLint zoffset,
                     GLsizei width,
                     GLsizei height,
                     GLsizei depth,
                     GLenum format,
                     GLenum type,
                     const void* pixels)
{
    glTexSubImage3D_ptr(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}

void glCopyTexSubImage3D(GLenum target,
                         GLint level,
                         GLint xoffset,
                         GLint yoffset,
                         GLint zoffset,
                         GLint x,
                         GLint y,
                         GLsizei width,
                         GLsizei height)
{
    glCopyTexSubImage3D_ptr(target, level, xoffset, yoffset, zoffset, x, y, width, height);
}

#pragma endregion

#pragma region GL_VERSION_1_3

void glActiveTexture(GLenum texture)
{
    glActiveTexture_ptr(texture);
}

void glSampleCoverage(GLfloat value, GLboolean invert)
{
    glSampleCoverage_ptr(value, invert);
}

void glCompressedTexImage3D(GLenum target,
                            GLint level,
                            GLenum internalformat,
                            GLsizei width,
                            GLsizei height,
                            GLsizei depth,
                            GLint border,
                            GLsizei imageSize,
                            const void* data)
{
    glCompressedTexImage3D_ptr(target, level, internalformat, width, height, depth, border, imageSize, data);
}

void glCompressedTexImage2D(GLenum target,
                            GLint level,
                            GLenum internalformat,
                            GLsizei width,
                            GLsizei height,
                            GLint border,
                            GLsizei imageSize,
                            const void* data)
{
    glCompressedTexImage2D_ptr(target, level, internalformat, width, height, border, imageSize, data);
}

void glCompressedTexImage1D(GLenum target,
                            GLint level,
                            GLenum internalformat,
                            GLsizei width,
                            GLint border,
                            GLsizei imageSize,
                            const void* data)
{
    glCompressedTexImage1D_ptr(target, level, internalformat, width, border, imageSize, data);
}

void glCompressedTexSubImage3D(GLenum target,
                               GLint level,
                               GLint xoffset,
                               GLint yoffset,
                               GLint zoffset,
                               GLsizei width,
                               GLsizei height,
                               GLsizei depth,
                               GLenum format,
                               GLsizei imageSize,
                               const void* data)
{
    glCompressedTexSubImage3D_ptr(target,
                                  level,
                                  xoffset,
                                  yoffset,
                                  zoffset,
                                  width,
                                  height,
                                  depth,
                                  format,
                                  imageSize,
                                  data);
}

void glCompressedTexSubImage2D(GLenum target,
                               GLint level,
                               GLint xoffset,
                               GLint yoffset,
                               GLsizei width,
                               GLsizei height,
                               GLenum format,
                               GLsizei imageSize,
                               const void* data)
{
    glCompressedTexSubImage2D_ptr(target, level, xoffset, yoffset, width, height, format, imageSize, data);
}

void glCompressedTexSubImage1D(GLenum target,
                               GLint level,
                               GLint xoffset,
                               GLsizei width,
                               GLenum format,
                               GLsizei imageSize,
                               const void* data)
{
    glCompressedTexSubImage1D_ptr(target, level, xoffset, width, format, imageSize, data);
}

void glGetCompressedTexImage(GLenum target, GLint level, void* img)
{
    glGetCompressedTexImage_ptr(target, level, img);
}

#pragma endregion

#pragma region GL_VERSION_1_4

void glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha)
{
    glBlendFuncSeparate_ptr(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}

void glMultiDrawArrays(GLenum mode, const GLint* first, const GLsizei* count, GLsizei drawcount)
{
    glMultiDrawArrays_ptr(mode, first, count, drawcount);
}

void glMultiDrawElements(GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawcount)
{
    glMultiDrawElements_ptr(mode, count, type, indices, drawcount);
}

void glPointParameterf(GLenum pname, GLfloat param)
{
    glPointParameterf_ptr(pname, param);
}

void glPointParameterfv(GLenum pname, const GLfloat* params)
{
    glPointParameterfv_ptr(pname, params);
}

void glPointParameteri(GLenum pname, GLint param)
{
    glPointParameteri_ptr(pname, param);
}

void glPointParameteriv(GLenum pname, const GLint* params)
{
    glPointParameteriv_ptr(pname, params);
}

void glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
    glBlendColor_ptr(red, green, blue, alpha);
}

void glBlendEquation(GLenum mode)
{
    glBlendEquation_ptr(mode);
}

#pragma endregion

#pragma region GL_VERSION_1_5

void glGenQueries(GLsizei n, GLuint* ids)
{
    glGenQueries_ptr(n, ids);
}

void glDeleteQueries(GLsizei n, const GLuint* ids)
{
    glDeleteQueries_ptr(n, ids);
}

GLboolean glIsQuery(GLuint id)
{
    return glIsQuery_ptr(id);
}

void glBeginQuery(GLenum target, GLuint id)
{
    glBeginQuery_ptr(target, id);
}

void glEndQuery(GLenum target)
{
    glEndQuery_ptr(target);
}

void glGetQueryiv(GLenum target, GLenum pname, GLint* params)
{
    glGetQueryiv_ptr(target, pname, params);
}

void glGetQueryObjectiv(GLuint id, GLenum pname, GLint* params)
{
    glGetQueryObjectiv_ptr(id, pname, params);
}

void glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint* params)
{
    glGetQueryObjectuiv_ptr(id, pname, params);
}

void glBindBuffer(GLenum target, GLuint buffer)
{
    glBindBuffer_ptr(target, buffer);
}

void glDeleteBuffers(GLsizei n, const GLuint* buffers)
{
    glDeleteBuffers_ptr(n, buffers);
}

void glGenBuffers(GLsizei n, GLuint* buffers)
{
    glGenBuffers_ptr(n, buffers);
}

GLboolean glIsBuffer(GLuint buffer)
{
    return glIsBuffer_ptr(buffer);
}

void glBufferData(GLenum target, GLsizeiptr size, const void* data, GLenum usage)
{
    glBufferData_ptr(target, size, data, usage);
}

void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void* data)
{
    glBufferSubData_ptr(target, offset, size, data);
}

void glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, void* data)
{
    glGetBufferSubData_ptr(target, offset, size, data);
}

void* glMapBuffer(GLenum target, GLenum access)
{
    return glMapBuffer_ptr(target, access);
}

GLboolean glUnmapBuffer(GLenum target)
{
    return glUnmapBuffer_ptr(target);
}

void glGetBufferParameteriv(GLenum target, GLenum pname, GLint* params)
{
    glGetBufferParameteriv_ptr(target, pname, params);
}

void glGetBufferPointerv(GLenum target, GLenum pname, void** params)
{
    glGetBufferPointerv_ptr(target, pname, params);
}

#pragma endregion

#pragma region GL_VERSION_2_0

void glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha)
{
    glBlendEquationSeparate_ptr(modeRGB, modeAlpha);
}

void glDrawBuffers(GLsizei n, const GLenum* bufs)
{
    glDrawBuffers_ptr(n, bufs);
}

void glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass)
{
    glStencilOpSeparate_ptr(face, sfail, dpfail, dppass);
}

void glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask)
{
    glStencilFuncSeparate_ptr(face, func, ref, mask);
}

void glStencilMaskSeparate(GLenum face, GLuint mask)
{
    glStencilMaskSeparate_ptr(face, mask);
}

void glAttachShader(GLuint program, GLuint shader)
{
    glAttachShader_ptr(program, shader);
}

void glBindAttribLocation(GLuint program, GLuint index, const GLchar* name)
{
    glBindAttribLocation_ptr(program, index, name);
}

void glCompileShader(GLuint shader)
{
    glCompileShader_ptr(shader);
}

GLuint glCreateProgram()
{
    return glCreateProgram_ptr();
}

GLuint glCreateShader(GLenum type)
{
    return glCreateShader_ptr(type);
}

void glDeleteProgram(GLuint program)
{
    glDeleteProgram_ptr(program);
}

void glDeleteShader(GLuint shader)
{
    glDeleteShader_ptr(shader);
}

void glDetachShader(GLuint program, GLuint shader)
{
    glDetachShader_ptr(program, shader);
}

void glDisableVertexAttribArray(GLuint index)
{
    glDisableVertexAttribArray_ptr(index);
}

void glEnableVertexAttribArray(GLuint index)
{
    glEnableVertexAttribArray_ptr(index);
}

void glGetActiveAttrib(GLuint program,
                       GLuint index,
                       GLsizei bufSize,
                       GLsizei* length,
                       GLint* size,
                       GLenum* type,
                       GLchar* name)
{
    glGetActiveAttrib_ptr(program, index, bufSize, length, size, type, name);
}

void glGetActiveUniform(GLuint program,
                        GLuint index,
                        GLsizei bufSize,
                        GLsizei* length,
                        GLint* size,
                        GLenum* type,
                        GLchar* name)
{
    glGetActiveUniform_ptr(program, index, bufSize, length, size, type, name);
}

void glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei* count, GLuint* shaders)
{
    glGetAttachedShaders_ptr(program, maxCount, count, shaders);
}

GLint glGetAttribLocation(GLuint program, const GLchar* name)
{
    return glGetAttribLocation_ptr(program, name);
}

void glGetProgramiv(GLuint program, GLenum pname, GLint* params)
{
    glGetProgramiv_ptr(program, pname, params);
}

void glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog)
{
    glGetProgramInfoLog_ptr(program, bufSize, length, infoLog);
}

void glGetShaderiv(GLuint shader, GLenum pname, GLint* params)
{
    glGetShaderiv_ptr(shader, pname, params);
}

void glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog)
{
    glGetShaderInfoLog_ptr(shader, bufSize, length, infoLog);
}

void glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* source)
{
    glGetShaderSource_ptr(shader, bufSize, length, source);
}

GLint glGetUniformLocation(GLuint program, const GLchar* name)
{
    return glGetUniformLocation_ptr(program, name);
}

void glGetUniformfv(GLuint program, GLint location, GLfloat* params)
{
    glGetUniformfv_ptr(program, location, params);
}

void glGetUniformiv(GLuint program, GLint location, GLint* params)
{
    glGetUniformiv_ptr(program, location, params);
}

void glGetVertexAttribdv(GLuint index, GLenum pname, GLdouble* params)
{
    glGetVertexAttribdv_ptr(index, pname, params);
}

void glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat* params)
{
    glGetVertexAttribfv_ptr(index, pname, params);
}

void glGetVertexAttribiv(GLuint index, GLenum pname, GLint* params)
{
    glGetVertexAttribiv_ptr(index, pname, params);
}

void glGetVertexAttribPointerv(GLuint index, GLenum pname, void** pointer)
{
    glGetVertexAttribPointerv_ptr(index, pname, pointer);
}

GLboolean glIsProgram(GLuint program)
{
    return glIsProgram_ptr(program);
}

GLboolean glIsShader(GLuint shader)
{
    return glIsShader_ptr(shader);
}

void glLinkProgram(GLuint program)
{
    glLinkProgram_ptr(program);
}

void glShaderSource(GLuint shader, GLsizei count, const GLchar* const* string, const GLint* length)
{
    glShaderSource_ptr(shader, count, string, length);
}

void glUseProgram(GLuint program)
{
    glUseProgram_ptr(program);
}

void glUniform1f(GLint location, GLfloat v0)
{
    glUniform1f_ptr(location, v0);
}

void glUniform2f(GLint location, GLfloat v0, GLfloat v1)
{
    glUniform2f_ptr(location, v0, v1);
}

void glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2)
{
    glUniform3f_ptr(location, v0, v1, v2);
}

void glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)
{
    glUniform4f_ptr(location, v0, v1, v2, v3);
}

void glUniform1i(GLint location, GLint v0)
{
    glUniform1i_ptr(location, v0);
}

void glUniform2i(GLint location, GLint v0, GLint v1)
{
    glUniform2i_ptr(location, v0, v1);
}

void glUniform3i(GLint location, GLint v0, GLint v1, GLint v2)
{
    glUniform3i_ptr(location, v0, v1, v2);
}

void glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3)
{
    glUniform4i_ptr(location, v0, v1, v2, v3);
}

void glUniform1fv(GLint location, GLsizei count, const GLfloat* value)
{
    glUniform1fv_ptr(location, count, value);
}

void glUniform2fv(GLint location, GLsizei count, const GLfloat* value)
{
    glUniform2fv_ptr(location, count, value);
}

void glUniform3fv(GLint location, GLsizei count, const GLfloat* value)
{
    glUniform3fv_ptr(location, count, value);
}

void glUniform4fv(GLint location, GLsizei count, const GLfloat* value)
{
    glUniform4fv_ptr(location, count, value);
}

void glUniform1iv(GLint location, GLsizei count, const GLint* value)
{
    glUniform1iv_ptr(location, count, value);
}

void glUniform2iv(GLint location, GLsizei count, const GLint* value)
{
    glUniform2iv_ptr(location, count, value);
}

void glUniform3iv(GLint location, GLsizei count, const GLint* value)
{
    glUniform3iv_ptr(location, count, value);
}

void glUniform4iv(GLint location, GLsizei count, const GLint* value)
{
    glUniform4iv_ptr(location, count, value);
}

void glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
{
    glUniformMatrix2fv_ptr(location, count, transpose, value);
}

void glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
{
    glUniformMatrix3fv_ptr(location, count, transpose, value);
}

void glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
{
    glUniformMatrix4fv_ptr(location, count, transpose, value);
}

void glValidateProgram(GLuint program)
{
    glValidateProgram_ptr(program);
}

void glVertexAttrib1d(GLuint index, GLdouble x)
{
    glVertexAttrib1d_ptr(index, x);
}

void glVertexAttrib1dv(GLuint index, const GLdouble* v)
{
    glVertexAttrib1dv_ptr(index, v);
}

void glVertexAttrib1f(GLuint index, GLfloat x)
{
    glVertexAttrib1f_ptr(index, x);
}

void glVertexAttrib1fv(GLuint index, const GLfloat* v)
{
    glVertexAttrib1fv_ptr(index, v);
}

void glVertexAttrib1s(GLuint index, GLshort x)
{
    glVertexAttrib1s_ptr(index, x);
}

void glVertexAttrib1sv(GLuint index, const GLshort* v)
{
    glVertexAttrib1sv_ptr(index, v);
}

void glVertexAttrib2d(GLuint index, GLdouble x, GLdouble y)
{
    glVertexAttrib2d_ptr(index, x, y);
}

void glVertexAttrib2dv(GLuint index, const GLdouble* v)
{
    glVertexAttrib2dv_ptr(index, v);
}

void glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y)
{
    glVertexAttrib2f_ptr(index, x, y);
}

void glVertexAttrib2fv(GLuint index, const GLfloat* v)
{
    glVertexAttrib2fv_ptr(index, v);
}

void glVertexAttrib2s(GLuint index, GLshort x, GLshort y)
{
    glVertexAttrib2s_ptr(index, x, y);
}

void glVertexAttrib2sv(GLuint index, const GLshort* v)
{
    glVertexAttrib2sv_ptr(index, v);
}

void glVertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z)
{
    glVertexAttrib3d_ptr(index, x, y, z);
}

void glVertexAttrib3dv(GLuint index, const GLdouble* v)
{
    glVertexAttrib3dv_ptr(index, v);
}

void glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z)
{
    glVertexAttrib3f_ptr(index, x, y, z);
}

void glVertexAttrib3fv(GLuint index, const GLfloat* v)
{
    glVertexAttrib3fv_ptr(index, v);
}

void glVertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z)
{
    glVertexAttrib3s_ptr(index, x, y, z);
}

void glVertexAttrib3sv(GLuint index, const GLshort* v)
{
    glVertexAttrib3sv_ptr(index, v);
}

void glVertexAttrib4Nbv(GLuint index, const GLbyte* v)
{
    glVertexAttrib4Nbv_ptr(index, v);
}

void glVertexAttrib4Niv(GLuint index, const GLint* v)
{
    glVertexAttrib4Niv_ptr(index, v);
}

void glVertexAttrib4Nsv(GLuint index, const GLshort* v)
{
    glVertexAttrib4Nsv_ptr(index, v);
}

void glVertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w)
{
    glVertexAttrib4Nub_ptr(index, x, y, z, w);
}

void glVertexAttrib4Nubv(GLuint index, const GLubyte* v)
{
    glVertexAttrib4Nubv_ptr(index, v);
}

void glVertexAttrib4Nuiv(GLuint index, const GLuint* v)
{
    glVertexAttrib4Nuiv_ptr(index, v);
}

void glVertexAttrib4Nusv(GLuint index, const GLushort* v)
{
    glVertexAttrib4Nusv_ptr(index, v);
}

void glVertexAttrib4bv(GLuint index, const GLbyte* v)
{
    glVertexAttrib4bv_ptr(index, v);
}

void glVertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
    glVertexAttrib4d_ptr(index, x, y, z, w);
}

void glVertexAttrib4dv(GLuint index, const GLdouble* v)
{
    glVertexAttrib4dv_ptr(index, v);
}

void glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
    glVertexAttrib4f_ptr(index, x, y, z, w);
}

void glVertexAttrib4fv(GLuint index, const GLfloat* v)
{
    glVertexAttrib4fv_ptr(index, v);
}

void glVertexAttrib4iv(GLuint index, const GLint* v)
{
    glVertexAttrib4iv_ptr(index, v);
}

void glVertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w)
{
    glVertexAttrib4s_ptr(index, x, y, z, w);
}

void glVertexAttrib4sv(GLuint index, const GLshort* v)
{
    glVertexAttrib4sv_ptr(index, v);
}

void glVertexAttrib4ubv(GLuint index, const GLubyte* v)
{
    glVertexAttrib4ubv_ptr(index, v);
}

void glVertexAttrib4uiv(GLuint index, const GLuint* v)
{
    glVertexAttrib4uiv_ptr(index, v);
}

void glVertexAttrib4usv(GLuint index, const GLushort* v)
{
    glVertexAttrib4usv_ptr(index, v);
}

void glVertexAttribPointer(GLuint index,
                           GLint size,
                           GLenum type,
                           GLboolean normalized,
                           GLsizei stride,
                           const void* pointer)
{
    glVertexAttribPointer_ptr(index, size, type, normalized, stride, pointer);
}

#pragma endregion

#pragma region GL_VERSION_2_1

void glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
{
    glUniformMatrix2x3fv_ptr(location, count, transpose, value);
}

void glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
{
    glUniformMatrix3x2fv_ptr(location, count, transpose, value);
}

void glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
{
    glUniformMatrix2x4fv_ptr(location, count, transpose, value);
}

void glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
{
    glUniformMatrix4x2fv_ptr(location, count, transpose, value);
}

void glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
{
    glUniformMatrix3x4fv_ptr(location, count, transpose, value);
}

void glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
{
    glUniformMatrix4x3fv_ptr(location, count, transpose, value);
}

#pragma endregion

#pragma region GL_VERSION_3_0

void glColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a)
{
    glColorMaski_ptr(index, r, g, b, a);
}

void glGetBooleani_v(GLenum target, GLuint index, GLboolean* data)
{
    glGetBooleani_v_ptr(target, index, data);
}

void glGetIntegeri_v(GLenum target, GLuint index, GLint* data)
{
    glGetIntegeri_v_ptr(target, index, data);
}

void glEnablei(GLenum target, GLuint index)
{
    glEnablei_ptr(target, index);
}

void glDisablei(GLenum target, GLuint index)
{
    glDisablei_ptr(target, index);
}

GLboolean glIsEnabledi(GLenum target, GLuint index)
{
    return glIsEnabledi_ptr(target, index);
}

void glBeginTransformFeedback(GLenum primitiveMode)
{
    glBeginTransformFeedback_ptr(primitiveMode);
}

void glEndTransformFeedback()
{
    glEndTransformFeedback_ptr();
}

void glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size)
{
    glBindBufferRange_ptr(target, index, buffer, offset, size);
}

void glBindBufferBase(GLenum target, GLuint index, GLuint buffer)
{
    glBindBufferBase_ptr(target, index, buffer);
}

void glTransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar* const* varyings, GLenum bufferMode)
{
    glTransformFeedbackVaryings_ptr(program, count, varyings, bufferMode);
}

void glGetTransformFeedbackVarying(GLuint program,
                                   GLuint index,
                                   GLsizei bufSize,
                                   GLsizei* length,
                                   GLsizei* size,
                                   GLenum* type,
                                   GLchar* name)
{
    glGetTransformFeedbackVarying_ptr(program, index, bufSize, length, size, type, name);
}

void glClampColor(GLenum target, GLenum clamp)
{
    glClampColor_ptr(target, clamp);
}

void glBeginConditionalRender(GLuint id, GLenum mode)
{
    glBeginConditionalRender_ptr(id, mode);
}

void glEndConditionalRender()
{
    glEndConditionalRender_ptr();
}

void glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer)
{
    glVertexAttribIPointer_ptr(index, size, type, stride, pointer);
}

void glGetVertexAttribIiv(GLuint index, GLenum pname, GLint* params)
{
    glGetVertexAttribIiv_ptr(index, pname, params);
}

void glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint* params)
{
    glGetVertexAttribIuiv_ptr(index, pname, params);
}

void glVertexAttribI1i(GLuint index, GLint x)
{
    glVertexAttribI1i_ptr(index, x);
}

void glVertexAttribI2i(GLuint index, GLint x, GLint y)
{
    glVertexAttribI2i_ptr(index, x, y);
}

void glVertexAttribI3i(GLuint index, GLint x, GLint y, GLint z)
{
    glVertexAttribI3i_ptr(index, x, y, z);
}

void glVertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w)
{
    glVertexAttribI4i_ptr(index, x, y, z, w);
}

void glVertexAttribI1ui(GLuint index, GLuint x)
{
    glVertexAttribI1ui_ptr(index, x);
}

void glVertexAttribI2ui(GLuint index, GLuint x, GLuint y)
{
    glVertexAttribI2ui_ptr(index, x, y);
}

void glVertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z)
{
    glVertexAttribI3ui_ptr(index, x, y, z);
}

void glVertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w)
{
    glVertexAttribI4ui_ptr(index, x, y, z, w);
}

void glVertexAttribI1iv(GLuint index, const GLint* v)
{
    glVertexAttribI1iv_ptr(index, v);
}

void glVertexAttribI2iv(GLuint index, const GLint* v)
{
    glVertexAttribI2iv_ptr(index, v);
}

void glVertexAttribI3iv(GLuint index, const GLint* v)
{
    glVertexAttribI3iv_ptr(index, v);
}

void glVertexAttribI4iv(GLuint index, const GLint* v)
{
    glVertexAttribI4iv_ptr(index, v);
}

void glVertexAttribI1uiv(GLuint index, const GLuint* v)
{
    glVertexAttribI1uiv_ptr(index, v);
}

void glVertexAttribI2uiv(GLuint index, const GLuint* v)
{
    glVertexAttribI2uiv_ptr(index, v);
}

void glVertexAttribI3uiv(GLuint index, const GLuint* v)
{
    glVertexAttribI3uiv_ptr(index, v);
}

void glVertexAttribI4uiv(GLuint index, const GLuint* v)
{
    glVertexAttribI4uiv_ptr(index, v);
}

void glVertexAttribI4bv(GLuint index, const GLbyte* v)
{
    glVertexAttribI4bv_ptr(index, v);
}

void glVertexAttribI4sv(GLuint index, const GLshort* v)
{
    glVertexAttribI4sv_ptr(index, v);
}

void glVertexAttribI4ubv(GLuint index, const GLubyte* v)
{
    glVertexAttribI4ubv_ptr(index, v);
}

void glVertexAttribI4usv(GLuint index, const GLushort* v)
{
    glVertexAttribI4usv_ptr(index, v);
}

void glGetUniformuiv(GLuint program, GLint location, GLuint* params)
{
    glGetUniformuiv_ptr(program, location, params);
}

void glBindFragDataLocation(GLuint program, GLuint color, const GLchar* name)
{
    glBindFragDataLocation_ptr(program, color, name);
}

GLint glGetFragDataLocation(GLuint program, const GLchar* name)
{
    return glGetFragDataLocation_ptr(program, name);
}

void glUniform1ui(GLint location, GLuint v0)
{
    glUniform1ui_ptr(location, v0);
}

void glUniform2ui(GLint location, GLuint v0, GLuint v1)
{
    glUniform2ui_ptr(location, v0, v1);
}

void glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2)
{
    glUniform3ui_ptr(location, v0, v1, v2);
}

void glUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3)
{
    glUniform4ui_ptr(location, v0, v1, v2, v3);
}

void glUniform1uiv(GLint location, GLsizei count, const GLuint* value)
{
    glUniform1uiv_ptr(location, count, value);
}

void glUniform2uiv(GLint location, GLsizei count, const GLuint* value)
{
    glUniform2uiv_ptr(location, count, value);
}

void glUniform3uiv(GLint location, GLsizei count, const GLuint* value)
{
    glUniform3uiv_ptr(location, count, value);
}

void glUniform4uiv(GLint location, GLsizei count, const GLuint* value)
{
    glUniform4uiv_ptr(location, count, value);
}

void glTexParameterIiv(GLenum target, GLenum pname, const GLint* params)
{
    glTexParameterIiv_ptr(target, pname, params);
}

void glTexParameterIuiv(GLenum target, GLenum pname, const GLuint* params)
{
    glTexParameterIuiv_ptr(target, pname, params);
}

void glGetTexParameterIiv(GLenum target, GLenum pname, GLint* params)
{
    glGetTexParameterIiv_ptr(target, pname, params);
}

void glGetTexParameterIuiv(GLenum target, GLenum pname, GLuint* params)
{
    glGetTexParameterIuiv_ptr(target, pname, params);
}

void glClearBufferiv(GLenum buffer, GLint drawbuffer, const GLint* value)
{
    glClearBufferiv_ptr(buffer, drawbuffer, value);
}

void glClearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint* value)
{
    glClearBufferuiv_ptr(buffer, drawbuffer, value);
}

void glClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat* value)
{
    glClearBufferfv_ptr(buffer, drawbuffer, value);
}

void glClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil)
{
    glClearBufferfi_ptr(buffer, drawbuffer, depth, stencil);
}

const GLubyte* glGetStringi(GLenum name, GLuint index)
{
    return glGetStringi_ptr(name, index);
}

GLboolean glIsRenderbuffer(GLuint renderbuffer)
{
    return glIsRenderbuffer_ptr(renderbuffer);
}

void glBindRenderbuffer(GLenum target, GLuint renderbuffer)
{
    glBindRenderbuffer_ptr(target, renderbuffer);
}

void glDeleteRenderbuffers(GLsizei n, const GLuint* renderbuffers)
{
    glDeleteRenderbuffers_ptr(n, renderbuffers);
}

void glGenRenderbuffers(GLsizei n, GLuint* renderbuffers)
{
    glGenRenderbuffers_ptr(n, renderbuffers);
}

void glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height)
{
    glRenderbufferStorage_ptr(target, internalformat, width, height);
}

void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint* params)
{
    glGetRenderbufferParameteriv_ptr(target, pname, params);
}

GLboolean glIsFramebuffer(GLuint framebuffer)
{
    return glIsFramebuffer_ptr(framebuffer);
}

void glBindFramebuffer(GLenum target, GLuint framebuffer)
{
    glBindFramebuffer_ptr(target, framebuffer);
}

void glDeleteFramebuffers(GLsizei n, const GLuint* framebuffers)
{
    glDeleteFramebuffers_ptr(n, framebuffers);
}

void glGenFramebuffers(GLsizei n, GLuint* framebuffers)
{
    glGenFramebuffers_ptr(n, framebuffers);
}

GLenum glCheckFramebufferStatus(GLenum target)
{
    return glCheckFramebufferStatus_ptr(target);
}

void glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
{
    glFramebufferTexture1D_ptr(target, attachment, textarget, texture, level);
}

void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
{
    glFramebufferTexture2D_ptr(target, attachment, textarget, texture, level);
}

void glFramebufferTexture3D(GLenum target,
                            GLenum attachment,
                            GLenum textarget,
                            GLuint texture,
                            GLint level,
                            GLint zoffset)
{
    glFramebufferTexture3D_ptr(target, attachment, textarget, texture, level, zoffset);
}

void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)
{
    glFramebufferRenderbuffer_ptr(target, attachment, renderbuffertarget, renderbuffer);
}

void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint* params)
{
    glGetFramebufferAttachmentParameteriv_ptr(target, attachment, pname, params);
}

void glGenerateMipmap(GLenum target)
{
    glGenerateMipmap_ptr(target);
}

void glBlitFramebuffer(GLint srcX0,
                       GLint srcY0,
                       GLint srcX1,
                       GLint srcY1,
                       GLint dstX0,
                       GLint dstY0,
                       GLint dstX1,
                       GLint dstY1,
                       GLbitfield mask,
                       GLenum filter)
{
    glBlitFramebuffer_ptr(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}

void glRenderbufferStorageMultisample(GLenum target,
                                      GLsizei samples,
                                      GLenum internalformat,
                                      GLsizei width,
                                      GLsizei height)
{
    glRenderbufferStorageMultisample_ptr(target, samples, internalformat, width, height);
}

void glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer)
{
    glFramebufferTextureLayer_ptr(target, attachment, texture, level, layer);
}

void* glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access)
{
    return glMapBufferRange_ptr(target, offset, length, access);
}

void glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length)
{
    glFlushMappedBufferRange_ptr(target, offset, length);
}

void glBindVertexArray(GLuint array)
{
    glBindVertexArray_ptr(array);
}

void glDeleteVertexArrays(GLsizei n, const GLuint* arrays)
{
    glDeleteVertexArrays_ptr(n, arrays);
}

void glGenVertexArrays(GLsizei n, GLuint* arrays)
{
    glGenVertexArrays_ptr(n, arrays);
}

GLboolean glIsVertexArray(GLuint array)
{
    return glIsVertexArray_ptr(array);
}

#pragma endregion

#pragma region GL_VERSION_3_1

void glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount)
{
    glDrawArraysInstanced_ptr(mode, first, count, instancecount);
}

void glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount)
{
    glDrawElementsInstanced_ptr(mode, count, type, indices, instancecount);
}

void glTexBuffer(GLenum target, GLenum internalformat, GLuint buffer)
{
    glTexBuffer_ptr(target, internalformat, buffer);
}

void glPrimitiveRestartIndex(GLuint index)
{
    glPrimitiveRestartIndex_ptr(index);
}

void glCopyBufferSubData(GLenum readTarget,
                         GLenum writeTarget,
                         GLintptr readOffset,
                         GLintptr writeOffset,
                         GLsizeiptr size)
{
    glCopyBufferSubData_ptr(readTarget, writeTarget, readOffset, writeOffset, size);
}

void glGetUniformIndices(GLuint program, GLsizei uniformCount, const GLchar* const* uniformNames, GLuint* uniformIndices)
{
    glGetUniformIndices_ptr(program, uniformCount, uniformNames, uniformIndices);
}

void glGetActiveUniformsiv(GLuint program,
                           GLsizei uniformCount,
                           const GLuint* uniformIndices,
                           GLenum pname,
                           GLint* params)
{
    glGetActiveUniformsiv_ptr(program, uniformCount, uniformIndices, pname, params);
}

void glGetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformName)
{
    glGetActiveUniformName_ptr(program, uniformIndex, bufSize, length, uniformName);
}

GLuint glGetUniformBlockIndex(GLuint program, const GLchar* uniformBlockName)
{
    return glGetUniformBlockIndex_ptr(program, uniformBlockName);
}

void glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params)
{
    glGetActiveUniformBlockiv_ptr(program, uniformBlockIndex, pname, params);
}

void glGetActiveUniformBlockName(GLuint program,
                                 GLuint uniformBlockIndex,
                                 GLsizei bufSize,
                                 GLsizei* length,
                                 GLchar* uniformBlockName)
{
    glGetActiveUniformBlockName_ptr(program, uniformBlockIndex, bufSize, length, uniformBlockName);
}

void glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding)
{
    glUniformBlockBinding_ptr(program, uniformBlockIndex, uniformBlockBinding);
}

#pragma endregion

#pragma region GL_VERSION_3_2

void glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const void* indices, GLint basevertex)
{
    glDrawElementsBaseVertex_ptr(mode, count, type, indices, basevertex);
}

void glDrawRangeElementsBaseVertex(GLenum mode,
                                   GLuint start,
                                   GLuint end,
                                   GLsizei count,
                                   GLenum type,
                                   const void* indices,
                                   GLint basevertex)
{
    glDrawRangeElementsBaseVertex_ptr(mode, start, end, count, type, indices, basevertex);
}

void glDrawElementsInstancedBaseVertex(GLenum mode,
                                       GLsizei count,
                                       GLenum type,
                                       const void* indices,
                                       GLsizei instancecount,
                                       GLint basevertex)
{
    glDrawElementsInstancedBaseVertex_ptr(mode, count, type, indices, instancecount, basevertex);
}

void glMultiDrawElementsBaseVertex(GLenum mode,
                                   const GLsizei* count,
                                   GLenum type,
                                   const void* const* indices,
                                   GLsizei drawcount,
                                   const GLint* basevertex)
{
    glMultiDrawElementsBaseVertex_ptr(mode, count, type, indices, drawcount, basevertex);
}

void glProvokingVertex(GLenum mode)
{
    glProvokingVertex_ptr(mode);
}

GLsync glFenceSync(GLenum condition, GLbitfield flags)
{
    return glFenceSync_ptr(condition, flags);
}

GLboolean glIsSync(GLsync sync)
{
    return glIsSync_ptr(sync);
}

void glDeleteSync(GLsync sync)
{
    glDeleteSync_ptr(sync);
}

GLenum glClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout)
{
    return glClientWaitSync_ptr(sync, flags, timeout);
}

void glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout)
{
    glWaitSync_ptr(sync, flags, timeout);
}

void glGetInteger64v(GLenum pname, GLint64* data)
{
    glGetInteger64v_ptr(pname, data);
}

void glGetSynciv(GLsync sync, GLenum pname, GLsizei count, GLsizei* length, GLint* values)
{
    glGetSynciv_ptr(sync, pname, count, length, values);
}

void glGetInteger64i_v(GLenum target, GLuint index, GLint64* data)
{
    glGetInteger64i_v_ptr(target, index, data);
}

void glGetBufferParameteri64v(GLenum target, GLenum pname, GLint64* params)
{
    glGetBufferParameteri64v_ptr(target, pname, params);
}

void glFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level)
{
    glFramebufferTexture_ptr(target, attachment, texture, level);
}

void glTexImage2DMultisample(GLenum target,
                             GLsizei samples,
                             GLenum internalformat,
                             GLsizei width,
                             GLsizei height,
                             GLboolean fixedsamplelocations)
{
    glTexImage2DMultisample_ptr(target, samples, internalformat, width, height, fixedsamplelocations);
}

void glTexImage3DMultisample(GLenum target,
                             GLsizei samples,
                             GLenum internalformat,
                             GLsizei width,
                             GLsizei height,
                             GLsizei depth,
                             GLboolean fixedsamplelocations)
{
    glTexImage3DMultisample_ptr(target, samples, internalformat, width, height, depth, fixedsamplelocations);
}

void glGetMultisamplefv(GLenum pname, GLuint index, GLfloat* val)
{
    glGetMultisamplefv_ptr(pname, index, val);
}

void glSampleMaski(GLuint maskNumber, GLbitfield mask)
{
    glSampleMaski_ptr(maskNumber, mask);
}

#pragma endregion

#pragma region GL_VERSION_3_3

void glBindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, const GLchar* name)
{
    glBindFragDataLocationIndexed_ptr(program, colorNumber, index, name);
}

GLint glGetFragDataIndex(GLuint program, const GLchar* name)
{
    return glGetFragDataIndex_ptr(program, name);
}

void glGenSamplers(GLsizei count, GLuint* samplers)
{
    glGenSamplers_ptr(count, samplers);
}

void glDeleteSamplers(GLsizei count, const GLuint* samplers)
{
    glDeleteSamplers_ptr(count, samplers);
}

GLboolean glIsSampler(GLuint sampler)
{
    return glIsSampler_ptr(sampler);
}

void glBindSampler(GLuint unit, GLuint sampler)
{
    glBindSampler_ptr(unit, sampler);
}

void glSamplerParameteri(GLuint sampler, GLenum pname, GLint param)
{
    glSamplerParameteri_ptr(sampler, pname, param);
}

void glSamplerParameteriv(GLuint sampler, GLenum pname, const GLint* param)
{
    glSamplerParameteriv_ptr(sampler, pname, param);
}

void glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param)
{
    glSamplerParameterf_ptr(sampler, pname, param);
}

void glSamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat* param)
{
    glSamplerParameterfv_ptr(sampler, pname, param);
}

void glSamplerParameterIiv(GLuint sampler, GLenum pname, const GLint* param)
{
    glSamplerParameterIiv_ptr(sampler, pname, param);
}

void glSamplerParameterIuiv(GLuint sampler, GLenum pname, const GLuint* param)
{
    glSamplerParameterIuiv_ptr(sampler, pname, param);
}

void glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint* params)
{
    glGetSamplerParameteriv_ptr(sampler, pname, params);
}

void glGetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint* params)
{
    glGetSamplerParameterIiv_ptr(sampler, pname, params);
}

void glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat* params)
{
    glGetSamplerParameterfv_ptr(sampler, pname, params);
}

void glGetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint* params)
{
    glGetSamplerParameterIuiv_ptr(sampler, pname, params);
}

void glQueryCounter(GLuint id, GLenum target)
{
    glQueryCounter_ptr(id, target);
}

void glGetQueryObjecti64v(GLuint id, GLenum pname, GLint64* params)
{
    glGetQueryObjecti64v_ptr(id, pname, params);
}

void glGetQueryObjectui64v(GLuint id, GLenum pname, GLuint64* params)
{
    glGetQueryObjectui64v_ptr(id, pname, params);
}

void glVertexAttribDivisor(GLuint index, GLuint divisor)
{
    glVertexAttribDivisor_ptr(index, divisor);
}

void glVertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value)
{
    glVertexAttribP1ui_ptr(index, type, normalized, value);
}

void glVertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value)
{
    glVertexAttribP1uiv_ptr(index, type, normalized, value);
}

void glVertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value)
{
    glVertexAttribP2ui_ptr(index, type, normalized, value);
}

void glVertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value)
{
    glVertexAttribP2uiv_ptr(index, type, normalized, value);
}

void glVertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value)
{
    glVertexAttribP3ui_ptr(index, type, normalized, value);
}

void glVertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value)
{
    glVertexAttribP3uiv_ptr(index, type, normalized, value);
}

void glVertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value)
{
    glVertexAttribP4ui_ptr(index, type, normalized, value);
}

void glVertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value)
{
    glVertexAttribP4uiv_ptr(index, type, normalized, value);
}

#pragma endregion

#pragma region GL_VERSION_4_0

void glMinSampleShading(GLfloat value)
{
    glMinSampleShading_ptr(value);
}

void glBlendEquationi(GLuint buf, GLenum mode)
{
    glBlendEquationi_ptr(buf, mode);
}

void glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha)
{
    glBlendEquationSeparatei_ptr(buf, modeRGB, modeAlpha);
}

void glBlendFunci(GLuint buf, GLenum src, GLenum dst)
{
    glBlendFunci_ptr(buf, src, dst);
}

void glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)
{
    glBlendFuncSeparatei_ptr(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
}

void glDrawArraysIndirect(GLenum mode, const void* indirect)
{
    glDrawArraysIndirect_ptr(mode, indirect);
}

void glDrawElementsIndirect(GLenum mode, GLenum type, const void* indirect)
{
    glDrawElementsIndirect_ptr(mode, type, indirect);
}

void glUniform1d(GLint location, GLdouble x)
{
    glUniform1d_ptr(location, x);
}

void glUniform2d(GLint location, GLdouble x, GLdouble y)
{
    glUniform2d_ptr(location, x, y);
}

void glUniform3d(GLint location, GLdouble x, GLdouble y, GLdouble z)
{
    glUniform3d_ptr(location, x, y, z);
}

void glUniform4d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
    glUniform4d_ptr(location, x, y, z, w);
}

void glUniform1dv(GLint location, GLsizei count, const GLdouble* value)
{
    glUniform1dv_ptr(location, count, value);
}

void glUniform2dv(GLint location, GLsizei count, const GLdouble* value)
{
    glUniform2dv_ptr(location, count, value);
}

void glUniform3dv(GLint location, GLsizei count, const GLdouble* value)
{
    glUniform3dv_ptr(location, count, value);
}

void glUniform4dv(GLint location, GLsizei count, const GLdouble* value)
{
    glUniform4dv_ptr(location, count, value);
}

void glUniformMatrix2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value)
{
    glUniformMatrix2dv_ptr(location, count, transpose, value);
}

void glUniformMatrix3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value)
{
    glUniformMatrix3dv_ptr(location, count, transpose, value);
}

void glUniformMatrix4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value)
{
    glUniformMatrix4dv_ptr(location, count, transpose, value);
}

void glUniformMatrix2x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value)
{
    glUniformMatrix2x3dv_ptr(location, count, transpose, value);
}

void glUniformMatrix2x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value)
{
    glUniformMatrix2x4dv_ptr(location, count, transpose, value);
}

void glUniformMatrix3x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value)
{
    glUniformMatrix3x2dv_ptr(location, count, transpose, value);
}

void glUniformMatrix3x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value)
{
    glUniformMatrix3x4dv_ptr(location, count, transpose, value);
}

void glUniformMatrix4x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value)
{
    glUniformMatrix4x2dv_ptr(location, count, transpose, value);
}

void glUniformMatrix4x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value)
{
    glUniformMatrix4x3dv_ptr(location, count, transpose, value);
}

void glGetUniformdv(GLuint program, GLint location, GLdouble* params)
{
    glGetUniformdv_ptr(program, location, params);
}

GLint glGetSubroutineUniformLocation(GLuint program, GLenum shadertype, const GLchar* name)
{
    return glGetSubroutineUniformLocation_ptr(program, shadertype, name);
}

GLuint glGetSubroutineIndex(GLuint program, GLenum shadertype, const GLchar* name)
{
    return glGetSubroutineIndex_ptr(program, shadertype, name);
}

void glGetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint* values)
{
    glGetActiveSubroutineUniformiv_ptr(program, shadertype, index, pname, values);
}

void glGetActiveSubroutineUniformName(GLuint program,
                                      GLenum shadertype,
                                      GLuint index,
                                      GLsizei bufSize,
                                      GLsizei* length,
                                      GLchar* name)
{
    glGetActiveSubroutineUniformName_ptr(program, shadertype, index, bufSize, length, name);
}

void glGetActiveSubroutineName(GLuint program,
                               GLenum shadertype,
                               GLuint index,
                               GLsizei bufSize,
                               GLsizei* length,
                               GLchar* name)
{
    glGetActiveSubroutineName_ptr(program, shadertype, index, bufSize, length, name);
}

void glUniformSubroutinesuiv(GLenum shadertype, GLsizei count, const GLuint* indices)
{
    glUniformSubroutinesuiv_ptr(shadertype, count, indices);
}

void glGetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint* params)
{
    glGetUniformSubroutineuiv_ptr(shadertype, location, params);
}

void glGetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLint* values)
{
    glGetProgramStageiv_ptr(program, shadertype, pname, values);
}

void glPatchParameteri(GLenum pname, GLint value)
{
    glPatchParameteri_ptr(pname, value);
}

void glPatchParameterfv(GLenum pname, const GLfloat* values)
{
    glPatchParameterfv_ptr(pname, values);
}

void glBindTransformFeedback(GLenum target, GLuint id)
{
    glBindTransformFeedback_ptr(target, id);
}

void glDeleteTransformFeedbacks(GLsizei n, const GLuint* ids)
{
    glDeleteTransformFeedbacks_ptr(n, ids);
}

void glGenTransformFeedbacks(GLsizei n, GLuint* ids)
{
    glGenTransformFeedbacks_ptr(n, ids);
}

GLboolean glIsTransformFeedback(GLuint id)
{
    return glIsTransformFeedback_ptr(id);
}

void glPauseTransformFeedback()
{
    glPauseTransformFeedback_ptr();
}

void glResumeTransformFeedback()
{
    glResumeTransformFeedback_ptr();
}

void glDrawTransformFeedback(GLenum mode, GLuint id)
{
    glDrawTransformFeedback_ptr(mode, id);
}

void glDrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream)
{
    glDrawTransformFeedbackStream_ptr(mode, id, stream);
}

void glBeginQueryIndexed(GLenum target, GLuint index, GLuint id)
{
    glBeginQueryIndexed_ptr(target, index, id);
}

void glEndQueryIndexed(GLenum target, GLuint index)
{
    glEndQueryIndexed_ptr(target, index);
}

void glGetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLint* params)
{
    glGetQueryIndexediv_ptr(target, index, pname, params);
}

#pragma endregion

#pragma region GL_VERSION_4_1

void glReleaseShaderCompiler()
{
    glReleaseShaderCompiler_ptr();
}

void glShaderBinary(GLsizei count, const GLuint* shaders, GLenum binaryformat, const void* binary, GLsizei length)
{
    glShaderBinary_ptr(count, shaders, binaryformat, binary, length);
}

void glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision)
{
    glGetShaderPrecisionFormat_ptr(shadertype, precisiontype, range, precision);
}

void glDepthRangef(GLfloat n, GLfloat f)
{
    glDepthRangef_ptr(n, f);
}

void glClearDepthf(GLfloat d)
{
    glClearDepthf_ptr(d);
}

void glGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei* length, GLenum* binaryFormat, void* binary)
{
    glGetProgramBinary_ptr(program, bufSize, length, binaryFormat, binary);
}

void glProgramBinary(GLuint program, GLenum binaryFormat, const void* binary, GLsizei length)
{
    glProgramBinary_ptr(program, binaryFormat, binary, length);
}

void glProgramParameteri(GLuint program, GLenum pname, GLint value)
{
    glProgramParameteri_ptr(program, pname, value);
}

void glUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program)
{
    glUseProgramStages_ptr(pipeline, stages, program);
}

void glActiveShaderProgram(GLuint pipeline, GLuint program)
{
    glActiveShaderProgram_ptr(pipeline, program);
}

GLuint glCreateShaderProgramv(GLenum type, GLsizei count, const GLchar* const* strings)
{
    return glCreateShaderProgramv_ptr(type, count, strings);
}

void glBindProgramPipeline(GLuint pipeline)
{
    glBindProgramPipeline_ptr(pipeline);
}

void glDeleteProgramPipelines(GLsizei n, const GLuint* pipelines)
{
    glDeleteProgramPipelines_ptr(n, pipelines);
}

void glGenProgramPipelines(GLsizei n, GLuint* pipelines)
{
    glGenProgramPipelines_ptr(n, pipelines);
}

GLboolean glIsProgramPipeline(GLuint pipeline)
{
    return glIsProgramPipeline_ptr(pipeline);
}

void glGetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint* params)
{
    glGetProgramPipelineiv_ptr(pipeline, pname, params);
}

void glProgramUniform1i(GLuint program, GLint location, GLint v0)
{
    glProgramUniform1i_ptr(program, location, v0);
}

void glProgramUniform1iv(GLuint program, GLint location, GLsizei count, const GLint* value)
{
    glProgramUniform1iv_ptr(program, location, count, value);
}

void glProgramUniform1f(GLuint program, GLint location, GLfloat v0)
{
    glProgramUniform1f_ptr(program, location, v0);
}

void glProgramUniform1fv(GLuint program, GLint location, GLsizei count, const GLfloat* value)
{
    glProgramUniform1fv_ptr(program, location, count, value);
}

void glProgramUniform1d(GLuint program, GLint location, GLdouble v0)
{
    glProgramUniform1d_ptr(program, location, v0);
}

void glProgramUniform1dv(GLuint program, GLint location, GLsizei count, const GLdouble* value)
{
    glProgramUniform1dv_ptr(program, location, count, value);
}

void glProgramUniform1ui(GLuint program, GLint location, GLuint v0)
{
    glProgramUniform1ui_ptr(program, location, v0);
}

void glProgramUniform1uiv(GLuint program, GLint location, GLsizei count, const GLuint* value)
{
    glProgramUniform1uiv_ptr(program, location, count, value);
}

void glProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1)
{
    glProgramUniform2i_ptr(program, location, v0, v1);
}

void glProgramUniform2iv(GLuint program, GLint location, GLsizei count, const GLint* value)
{
    glProgramUniform2iv_ptr(program, location, count, value);
}

void glProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1)
{
    glProgramUniform2f_ptr(program, location, v0, v1);
}

void glProgramUniform2fv(GLuint program, GLint location, GLsizei count, const GLfloat* value)
{
    glProgramUniform2fv_ptr(program, location, count, value);
}

void glProgramUniform2d(GLuint program, GLint location, GLdouble v0, GLdouble v1)
{
    glProgramUniform2d_ptr(program, location, v0, v1);
}

void glProgramUniform2dv(GLuint program, GLint location, GLsizei count, const GLdouble* value)
{
    glProgramUniform2dv_ptr(program, location, count, value);
}

void glProgramUniform2ui(GLuint program, GLint location, GLuint v0, GLuint v1)
{
    glProgramUniform2ui_ptr(program, location, v0, v1);
}

void glProgramUniform2uiv(GLuint program, GLint location, GLsizei count, const GLuint* value)
{
    glProgramUniform2uiv_ptr(program, location, count, value);
}

void glProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2)
{
    glProgramUniform3i_ptr(program, location, v0, v1, v2);
}

void glProgramUniform3iv(GLuint program, GLint location, GLsizei count, const GLint* value)
{
    glProgramUniform3iv_ptr(program, location, count, value);
}

void glProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2)
{
    glProgramUniform3f_ptr(program, location, v0, v1, v2);
}

void glProgramUniform3fv(GLuint program, GLint location, GLsizei count, const GLfloat* value)
{
    glProgramUniform3fv_ptr(program, location, count, value);
}

void glProgramUniform3d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2)
{
    glProgramUniform3d_ptr(program, location, v0, v1, v2);
}

void glProgramUniform3dv(GLuint program, GLint location, GLsizei count, const GLdouble* value)
{
    glProgramUniform3dv_ptr(program, location, count, value);
}

void glProgramUniform3ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2)
{
    glProgramUniform3ui_ptr(program, location, v0, v1, v2);
}

void glProgramUniform3uiv(GLuint program, GLint location, GLsizei count, const GLuint* value)
{
    glProgramUniform3uiv_ptr(program, location, count, value);
}

void glProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3)
{
    glProgramUniform4i_ptr(program, location, v0, v1, v2, v3);
}

void glProgramUniform4iv(GLuint program, GLint location, GLsizei count, const GLint* value)
{
    glProgramUniform4iv_ptr(program, location, count, value);
}

void glProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)
{
    glProgramUniform4f_ptr(program, location, v0, v1, v2, v3);
}

void glProgramUniform4fv(GLuint program, GLint location, GLsizei count, const GLfloat* value)
{
    glProgramUniform4fv_ptr(program, location, count, value);
}

void glProgramUniform4d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3)
{
    glProgramUniform4d_ptr(program, location, v0, v1, v2, v3);
}

void glProgramUniform4dv(GLuint program, GLint location, GLsizei count, const GLdouble* value)
{
    glProgramUniform4dv_ptr(program, location, count, value);
}

void glProgramUniform4ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3)
{
    glProgramUniform4ui_ptr(program, location, v0, v1, v2, v3);
}

void glProgramUniform4uiv(GLuint program, GLint location, GLsizei count, const GLuint* value)
{
    glProgramUniform4uiv_ptr(program, location, count, value);
}

void glProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
{
    glProgramUniformMatrix2fv_ptr(program, location, count, transpose, value);
}

void glProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
{
    glProgramUniformMatrix3fv_ptr(program, location, count, transpose, value);
}

void glProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
{
    glProgramUniformMatrix4fv_ptr(program, location, count, transpose, value);
}

void glProgramUniformMatrix2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value)
{
    glProgramUniformMatrix2dv_ptr(program, location, count, transpose, value);
}

void glProgramUniformMatrix3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value)
{
    glProgramUniformMatrix3dv_ptr(program, location, count, transpose, value);
}

void glProgramUniformMatrix4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value)
{
    glProgramUniformMatrix4dv_ptr(program, location, count, transpose, value);
}

void glProgramUniformMatrix2x3fv(GLuint program,
                                 GLint location,
                                 GLsizei count,
                                 GLboolean transpose,
                                 const GLfloat* value)
{
    glProgramUniformMatrix2x3fv_ptr(program, location, count, transpose, value);
}

void glProgramUniformMatrix3x2fv(GLuint program,
                                 GLint location,
                                 GLsizei count,
                                 GLboolean transpose,
                                 const GLfloat* value)
{
    glProgramUniformMatrix3x2fv_ptr(program, location, count, transpose, value);
}

void glProgramUniformMatrix2x4fv(GLuint program,
                                 GLint location,
                                 GLsizei count,
                                 GLboolean transpose,
                                 const GLfloat* value)
{
    glProgramUniformMatrix2x4fv_ptr(program, location, count, transpose, value);
}

void glProgramUniformMatrix4x2fv(GLuint program,
                                 GLint location,
                                 GLsizei count,
                                 GLboolean transpose,
                                 const GLfloat* value)
{
    glProgramUniformMatrix4x2fv_ptr(program, location, count, transpose, value);
}

void glProgramUniformMatrix3x4fv(GLuint program,
                                 GLint location,
                                 GLsizei count,
                                 GLboolean transpose,
                                 const GLfloat* value)
{
    glProgramUniformMatrix3x4fv_ptr(program, location, count, transpose, value);
}

void glProgramUniformMatrix4x3fv(GLuint program,
                                 GLint location,
                                 GLsizei count,
                                 GLboolean transpose,
                                 const GLfloat* value)
{
    glProgramUniformMatrix4x3fv_ptr(program, location, count, transpose, value);
}

void glProgramUniformMatrix2x3dv(GLuint program,
                                 GLint location,
                                 GLsizei count,
                                 GLboolean transpose,
                                 const GLdouble* value)
{
    glProgramUniformMatrix2x3dv_ptr(program, location, count, transpose, value);
}

void glProgramUniformMatrix3x2dv(GLuint program,
                                 GLint location,
                                 GLsizei count,
                                 GLboolean transpose,
                                 const GLdouble* value)
{
    glProgramUniformMatrix3x2dv_ptr(program, location, count, transpose, value);
}

void glProgramUniformMatrix2x4dv(GLuint program,
                                 GLint location,
                                 GLsizei count,
                                 GLboolean transpose,
                                 const GLdouble* value)
{
    glProgramUniformMatrix2x4dv_ptr(program, location, count, transpose, value);
}

void glProgramUniformMatrix4x2dv(GLuint program,
                                 GLint location,
                                 GLsizei count,
                                 GLboolean transpose,
                                 const GLdouble* value)
{
    glProgramUniformMatrix4x2dv_ptr(program, location, count, transpose, value);
}

void glProgramUniformMatrix3x4dv(GLuint program,
                                 GLint location,
                                 GLsizei count,
                                 GLboolean transpose,
                                 const GLdouble* value)
{
    glProgramUniformMatrix3x4dv_ptr(program, location, count, transpose, value);
}

void glProgramUniformMatrix4x3dv(GLuint program,
                                 GLint location,
                                 GLsizei count,
                                 GLboolean transpose,
                                 const GLdouble* value)
{
    glProgramUniformMatrix4x3dv_ptr(program, location, count, transpose, value);
}

void glValidateProgramPipeline(GLuint pipeline)
{
    glValidateProgramPipeline_ptr(pipeline);
}

void glGetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei* length, GLchar* infoLog)
{
    glGetProgramPipelineInfoLog_ptr(pipeline, bufSize, length, infoLog);
}

void glVertexAttribL1d(GLuint index, GLdouble x)
{
    glVertexAttribL1d_ptr(index, x);
}

void glVertexAttribL2d(GLuint index, GLdouble x, GLdouble y)
{
    glVertexAttribL2d_ptr(index, x, y);
}

void glVertexAttribL3d(GLuint index, GLdouble x, GLdouble y, GLdouble z)
{
    glVertexAttribL3d_ptr(index, x, y, z);
}

void glVertexAttribL4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
    glVertexAttribL4d_ptr(index, x, y, z, w);
}

void glVertexAttribL1dv(GLuint index, const GLdouble* v)
{
    glVertexAttribL1dv_ptr(index, v);
}

void glVertexAttribL2dv(GLuint index, const GLdouble* v)
{
    glVertexAttribL2dv_ptr(index, v);
}

void glVertexAttribL3dv(GLuint index, const GLdouble* v)
{
    glVertexAttribL3dv_ptr(index, v);
}

void glVertexAttribL4dv(GLuint index, const GLdouble* v)
{
    glVertexAttribL4dv_ptr(index, v);
}

void glVertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer)
{
    glVertexAttribLPointer_ptr(index, size, type, stride, pointer);
}

void glGetVertexAttribLdv(GLuint index, GLenum pname, GLdouble* params)
{
    glGetVertexAttribLdv_ptr(index, pname, params);
}

void glViewportArrayv(GLuint first, GLsizei count, const GLfloat* v)
{
    glViewportArrayv_ptr(first, count, v);
}

void glViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h)
{
    glViewportIndexedf_ptr(index, x, y, w, h);
}

void glViewportIndexedfv(GLuint index, const GLfloat* v)
{
    glViewportIndexedfv_ptr(index, v);
}

void glScissorArrayv(GLuint first, GLsizei count, const GLint* v)
{
    glScissorArrayv_ptr(first, count, v);
}

void glScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height)
{
    glScissorIndexed_ptr(index, left, bottom, width, height);
}

void glScissorIndexedv(GLuint index, const GLint* v)
{
    glScissorIndexedv_ptr(index, v);
}

void glDepthRangeArrayv(GLuint first, GLsizei count, const GLdouble* v)
{
    glDepthRangeArrayv_ptr(first, count, v);
}

void glDepthRangeIndexed(GLuint index, GLdouble n, GLdouble f)
{
    glDepthRangeIndexed_ptr(index, n, f);
}

void glGetFloati_v(GLenum target, GLuint index, GLfloat* data)
{
    glGetFloati_v_ptr(target, index, data);
}

void glGetDoublei_v(GLenum target, GLuint index, GLdouble* data)
{
    glGetDoublei_v_ptr(target, index, data);
}

#pragma endregion

#pragma region GL_VERSION_4_2

void glDrawArraysInstancedBaseInstance(GLenum mode,
                                       GLint first,
                                       GLsizei count,
                                       GLsizei instancecount,
                                       GLuint baseinstance)
{
    glDrawArraysInstancedBaseInstance_ptr(mode, first, count, instancecount, baseinstance);
}

void glDrawElementsInstancedBaseInstance(GLenum mode,
                                         GLsizei count,
                                         GLenum type,
                                         const void* indices,
                                         GLsizei instancecount,
                                         GLuint baseinstance)
{
    glDrawElementsInstancedBaseInstance_ptr(mode, count, type, indices, instancecount, baseinstance);
}

void glDrawElementsInstancedBaseVertexBaseInstance(GLenum mode,
                                                   GLsizei count,
                                                   GLenum type,
                                                   const void* indices,
                                                   GLsizei instancecount,
                                                   GLint basevertex,
                                                   GLuint baseinstance)
{
    glDrawElementsInstancedBaseVertexBaseInstance_ptr(mode,
                                                      count,
                                                      type,
                                                      indices,
                                                      instancecount,
                                                      basevertex,
                                                      baseinstance);
}

void glGetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint* params)
{
    glGetInternalformativ_ptr(target, internalformat, pname, count, params);
}

void glGetActiveAtomicCounterBufferiv(GLuint program, GLuint bufferIndex, GLenum pname, GLint* params)
{
    glGetActiveAtomicCounterBufferiv_ptr(program, bufferIndex, pname, params);
}

void glBindImageTexture(GLuint unit,
                        GLuint texture,
                        GLint level,
                        GLboolean layered,
                        GLint layer,
                        GLenum access,
                        GLenum format)
{
    glBindImageTexture_ptr(unit, texture, level, layered, layer, access, format);
}

void glMemoryBarrier(GLbitfield barriers)
{
    glMemoryBarrier_ptr(barriers);
}

void glTexStorage1D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width)
{
    glTexStorage1D_ptr(target, levels, internalformat, width);
}

void glTexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height)
{
    glTexStorage2D_ptr(target, levels, internalformat, width, height);
}

void glTexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth)
{
    glTexStorage3D_ptr(target, levels, internalformat, width, height, depth);
}

void glDrawTransformFeedbackInstanced(GLenum mode, GLuint id, GLsizei instancecount)
{
    glDrawTransformFeedbackInstanced_ptr(mode, id, instancecount);
}

void glDrawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount)
{
    glDrawTransformFeedbackStreamInstanced_ptr(mode, id, stream, instancecount);
}

#pragma endregion

#pragma region GL_VERSION_4_3

void glClearBufferData(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void* data)
{
    glClearBufferData_ptr(target, internalformat, format, type, data);
}

void glClearBufferSubData(GLenum target,
                          GLenum internalformat,
                          GLintptr offset,
                          GLsizeiptr size,
                          GLenum format,
                          GLenum type,
                          const void* data)
{
    glClearBufferSubData_ptr(target, internalformat, offset, size, format, type, data);
}

void glDispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z)
{
    glDispatchCompute_ptr(num_groups_x, num_groups_y, num_groups_z);
}

void glDispatchComputeIndirect(GLintptr indirect)
{
    glDispatchComputeIndirect_ptr(indirect);
}

void glCopyImageSubData(GLuint srcName,
                        GLenum srcTarget,
                        GLint srcLevel,
                        GLint srcX,
                        GLint srcY,
                        GLint srcZ,
                        GLuint dstName,
                        GLenum dstTarget,
                        GLint dstLevel,
                        GLint dstX,
                        GLint dstY,
                        GLint dstZ,
                        GLsizei srcWidth,
                        GLsizei srcHeight,
                        GLsizei srcDepth)
{
    glCopyImageSubData_ptr(srcName,
                           srcTarget,
                           srcLevel,
                           srcX,
                           srcY,
                           srcZ,
                           dstName,
                           dstTarget,
                           dstLevel,
                           dstX,
                           dstY,
                           dstZ,
                           srcWidth,
                           srcHeight,
                           srcDepth);
}

void glFramebufferParameteri(GLenum target, GLenum pname, GLint param)
{
    glFramebufferParameteri_ptr(target, pname, param);
}

void glGetFramebufferParameteriv(GLenum target, GLenum pname, GLint* params)
{
    glGetFramebufferParameteriv_ptr(target, pname, params);
}

void glGetInternalformati64v(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint64* params)
{
    glGetInternalformati64v_ptr(target, internalformat, pname, count, params);
}

void glInvalidateTexSubImage(GLuint texture,
                             GLint level,
                             GLint xoffset,
                             GLint yoffset,
                             GLint zoffset,
                             GLsizei width,
                             GLsizei height,
                             GLsizei depth)
{
    glInvalidateTexSubImage_ptr(texture, level, xoffset, yoffset, zoffset, width, height, depth);
}

void glInvalidateTexImage(GLuint texture, GLint level)
{
    glInvalidateTexImage_ptr(texture, level);
}

void glInvalidateBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr length)
{
    glInvalidateBufferSubData_ptr(buffer, offset, length);
}

void glInvalidateBufferData(GLuint buffer)
{
    glInvalidateBufferData_ptr(buffer);
}

void glInvalidateFramebuffer(GLenum target, GLsizei numAttachments, const GLenum* attachments)
{
    glInvalidateFramebuffer_ptr(target, numAttachments, attachments);
}

void glInvalidateSubFramebuffer(GLenum target,
                                GLsizei numAttachments,
                                const GLenum* attachments,
                                GLint x,
                                GLint y,
                                GLsizei width,
                                GLsizei height)
{
    glInvalidateSubFramebuffer_ptr(target, numAttachments, attachments, x, y, width, height);
}

void glMultiDrawArraysIndirect(GLenum mode, const void* indirect, GLsizei drawcount, GLsizei stride)
{
    glMultiDrawArraysIndirect_ptr(mode, indirect, drawcount, stride);
}

void glMultiDrawElementsIndirect(GLenum mode, GLenum type, const void* indirect, GLsizei drawcount, GLsizei stride)
{
    glMultiDrawElementsIndirect_ptr(mode, type, indirect, drawcount, stride);
}

void glGetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum pname, GLint* params)
{
    glGetProgramInterfaceiv_ptr(program, programInterface, pname, params);
}

GLuint glGetProgramResourceIndex(GLuint program, GLenum programInterface, const GLchar* name)
{
    return glGetProgramResourceIndex_ptr(program, programInterface, name);
}

void glGetProgramResourceName(GLuint program,
                              GLenum programInterface,
                              GLuint index,
                              GLsizei bufSize,
                              GLsizei* length,
                              GLchar* name)
{
    glGetProgramResourceName_ptr(program, programInterface, index, bufSize, length, name);
}

void glGetProgramResourceiv(GLuint program,
                            GLenum programInterface,
                            GLuint index,
                            GLsizei propCount,
                            const GLenum* props,
                            GLsizei count,
                            GLsizei* length,
                            GLint* params)
{
    glGetProgramResourceiv_ptr(program, programInterface, index, propCount, props, count, length, params);
}

GLint glGetProgramResourceLocation(GLuint program, GLenum programInterface, const GLchar* name)
{
    return glGetProgramResourceLocation_ptr(program, programInterface, name);
}

GLint glGetProgramResourceLocationIndex(GLuint program, GLenum programInterface, const GLchar* name)
{
    return glGetProgramResourceLocationIndex_ptr(program, programInterface, name);
}

void glShaderStorageBlockBinding(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding)
{
    glShaderStorageBlockBinding_ptr(program, storageBlockIndex, storageBlockBinding);
}

void glTexBufferRange(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size)
{
    glTexBufferRange_ptr(target, internalformat, buffer, offset, size);
}

void glTexStorage2DMultisample(GLenum target,
                               GLsizei samples,
                               GLenum internalformat,
                               GLsizei width,
                               GLsizei height,
                               GLboolean fixedsamplelocations)
{
    glTexStorage2DMultisample_ptr(target, samples, internalformat, width, height, fixedsamplelocations);
}

void glTexStorage3DMultisample(GLenum target,
                               GLsizei samples,
                               GLenum internalformat,
                               GLsizei width,
                               GLsizei height,
                               GLsizei depth,
                               GLboolean fixedsamplelocations)
{
    glTexStorage3DMultisample_ptr(target, samples, internalformat, width, height, depth, fixedsamplelocations);
}

void glTextureView(GLuint texture,
                   GLenum target,
                   GLuint origtexture,
                   GLenum internalformat,
                   GLuint minlevel,
                   GLuint numlevels,
                   GLuint minlayer,
                   GLuint numlayers)
{
    glTextureView_ptr(texture, target, origtexture, internalformat, minlevel, numlevels, minlayer, numlayers);
}

void glBindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride)
{
    glBindVertexBuffer_ptr(bindingindex, buffer, offset, stride);
}

void glVertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset)
{
    glVertexAttribFormat_ptr(attribindex, size, type, normalized, relativeoffset);
}

void glVertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset)
{
    glVertexAttribIFormat_ptr(attribindex, size, type, relativeoffset);
}

void glVertexAttribLFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset)
{
    glVertexAttribLFormat_ptr(attribindex, size, type, relativeoffset);
}

void glVertexAttribBinding(GLuint attribindex, GLuint bindingindex)
{
    glVertexAttribBinding_ptr(attribindex, bindingindex);
}

void glVertexBindingDivisor(GLuint bindingindex, GLuint divisor)
{
    glVertexBindingDivisor_ptr(bindingindex, divisor);
}

void glDebugMessageControl(GLenum source,
                           GLenum type,
                           GLenum severity,
                           GLsizei count,
                           const GLuint* ids,
                           GLboolean enabled)
{
    glDebugMessageControl_ptr(source, type, severity, count, ids, enabled);
}

void glDebugMessageInsert(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf)
{
    glDebugMessageInsert_ptr(source, type, id, severity, length, buf);
}

void glDebugMessageCallback(GLDEBUGPROC callback, const void* userParam)
{
    glDebugMessageCallback_ptr(callback, userParam);
}

GLuint glGetDebugMessageLog(GLuint count,
                            GLsizei bufSize,
                            GLenum* sources,
                            GLenum* types,
                            GLuint* ids,
                            GLenum* severities,
                            GLsizei* lengths,
                            GLchar* messageLog)
{
    return glGetDebugMessageLog_ptr(count, bufSize, sources, types, ids, severities, lengths, messageLog);
}

void glPushDebugGroup(GLenum source, GLuint id, GLsizei length, const GLchar* message)
{
    glPushDebugGroup_ptr(source, id, length, message);
}

void glPopDebugGroup()
{
    glPopDebugGroup_ptr();
}

void glObjectLabel(GLenum identifier, GLuint name, GLsizei length, const GLchar* label)
{
    glObjectLabel_ptr(identifier, name, length, label);
}

void glGetObjectLabel(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei* length, GLchar* label)
{
    glGetObjectLabel_ptr(identifier, name, bufSize, length, label);
}

void glObjectPtrLabel(const void* ptr, GLsizei length, const GLchar* label)
{
    glObjectPtrLabel_ptr(ptr, length, label);
}

void glGetObjectPtrLabel(const void* ptr, GLsizei bufSize, GLsizei* length, GLchar* label)
{
    glGetObjectPtrLabel_ptr(ptr, bufSize, length, label);
}

#pragma endregion

#pragma region GL_VERSION_4_4

void glBufferStorage(GLenum target, GLsizeiptr size, const void* data, GLbitfield flags)
{
    glBufferStorage_ptr(target, size, data, flags);
}

void glClearTexImage(GLuint texture, GLint level, GLenum format, GLenum type, const void* data)
{
    glClearTexImage_ptr(texture, level, format, type, data);
}

void glClearTexSubImage(GLuint texture,
                        GLint level,
                        GLint xoffset,
                        GLint yoffset,
                        GLint zoffset,
                        GLsizei width,
                        GLsizei height,
                        GLsizei depth,
                        GLenum format,
                        GLenum type,
                        const void* data)
{
    glClearTexSubImage_ptr(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, data);
}

void glBindBuffersBase(GLenum target, GLuint first, GLsizei count, const GLuint* buffers)
{
    glBindBuffersBase_ptr(target, first, count, buffers);
}

void glBindBuffersRange(GLenum target,
                        GLuint first,
                        GLsizei count,
                        const GLuint* buffers,
                        const GLintptr* offsets,
                        const GLsizeiptr* sizes)
{
    glBindBuffersRange_ptr(target, first, count, buffers, offsets, sizes);
}

void glBindTextures(GLuint first, GLsizei count, const GLuint* textures)
{
    glBindTextures_ptr(first, count, textures);
}

void glBindSamplers(GLuint first, GLsizei count, const GLuint* samplers)
{
    glBindSamplers_ptr(first, count, samplers);
}

void glBindImageTextures(GLuint first, GLsizei count, const GLuint* textures)
{
    glBindImageTextures_ptr(first, count, textures);
}

void glBindVertexBuffers(GLuint first,
                         GLsizei count,
                         const GLuint* buffers,
                         const GLintptr* offsets,
                         const GLsizei* strides)
{
    glBindVertexBuffers_ptr(first, count, buffers, offsets, strides);
}

#pragma endregion

#pragma region GL_VERSION_4_5

void glClipControl(GLenum origin, GLenum depth)
{
    glClipControl_ptr(origin, depth);
}

void glCreateTransformFeedbacks(GLsizei n, GLuint* ids)
{
    glCreateTransformFeedbacks_ptr(n, ids);
}

void glTransformFeedbackBufferBase(GLuint xfb, GLuint index, GLuint buffer)
{
    glTransformFeedbackBufferBase_ptr(xfb, index, buffer);
}

void glTransformFeedbackBufferRange(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size)
{
    glTransformFeedbackBufferRange_ptr(xfb, index, buffer, offset, size);
}

void glGetTransformFeedbackiv(GLuint xfb, GLenum pname, GLint* param)
{
    glGetTransformFeedbackiv_ptr(xfb, pname, param);
}

void glGetTransformFeedbacki_v(GLuint xfb, GLenum pname, GLuint index, GLint* param)
{
    glGetTransformFeedbacki_v_ptr(xfb, pname, index, param);
}

void glGetTransformFeedbacki64_v(GLuint xfb, GLenum pname, GLuint index, GLint64* param)
{
    glGetTransformFeedbacki64_v_ptr(xfb, pname, index, param);
}

void glCreateBuffers(GLsizei n, GLuint* buffers)
{
    glCreateBuffers_ptr(n, buffers);
}

void glNamedBufferStorage(GLuint buffer, GLsizeiptr size, const void* data, GLbitfield flags)
{
    glNamedBufferStorage_ptr(buffer, size, data, flags);
}

void glNamedBufferData(GLuint buffer, GLsizeiptr size, const void* data, GLenum usage)
{
    glNamedBufferData_ptr(buffer, size, data, usage);
}

void glNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, const void* data)
{
    glNamedBufferSubData_ptr(buffer, offset, size, data);
}

void glCopyNamedBufferSubData(GLuint readBuffer,
                              GLuint writeBuffer,
                              GLintptr readOffset,
                              GLintptr writeOffset,
                              GLsizeiptr size)
{
    glCopyNamedBufferSubData_ptr(readBuffer, writeBuffer, readOffset, writeOffset, size);
}

void glClearNamedBufferData(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void* data)
{
    glClearNamedBufferData_ptr(buffer, internalformat, format, type, data);
}

void glClearNamedBufferSubData(GLuint buffer,
                               GLenum internalformat,
                               GLintptr offset,
                               GLsizeiptr size,
                               GLenum format,
                               GLenum type,
                               const void* data)
{
    glClearNamedBufferSubData_ptr(buffer, internalformat, offset, size, format, type, data);
}

void* glMapNamedBuffer(GLuint buffer, GLenum access)
{
    return glMapNamedBuffer_ptr(buffer, access);
}

void* glMapNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access)
{
    return glMapNamedBufferRange_ptr(buffer, offset, length, access);
}

GLboolean glUnmapNamedBuffer(GLuint buffer)
{
    return glUnmapNamedBuffer_ptr(buffer);
}

void glFlushMappedNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length)
{
    glFlushMappedNamedBufferRange_ptr(buffer, offset, length);
}

void glGetNamedBufferParameteriv(GLuint buffer, GLenum pname, GLint* params)
{
    glGetNamedBufferParameteriv_ptr(buffer, pname, params);
}

void glGetNamedBufferParameteri64v(GLuint buffer, GLenum pname, GLint64* params)
{
    glGetNamedBufferParameteri64v_ptr(buffer, pname, params);
}

void glGetNamedBufferPointerv(GLuint buffer, GLenum pname, void** params)
{
    glGetNamedBufferPointerv_ptr(buffer, pname, params);
}

void glGetNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, void* data)
{
    glGetNamedBufferSubData_ptr(buffer, offset, size, data);
}

void glCreateFramebuffers(GLsizei n, GLuint* framebuffers)
{
    glCreateFramebuffers_ptr(n, framebuffers);
}

void glNamedFramebufferRenderbuffer(GLuint framebuffer,
                                    GLenum attachment,
                                    GLenum renderbuffertarget,
                                    GLuint renderbuffer)
{
    glNamedFramebufferRenderbuffer_ptr(framebuffer, attachment, renderbuffertarget, renderbuffer);
}

void glNamedFramebufferParameteri(GLuint framebuffer, GLenum pname, GLint param)
{
    glNamedFramebufferParameteri_ptr(framebuffer, pname, param);
}

void glNamedFramebufferTexture(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level)
{
    glNamedFramebufferTexture_ptr(framebuffer, attachment, texture, level);
}

void glNamedFramebufferTextureLayer(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer)
{
    glNamedFramebufferTextureLayer_ptr(framebuffer, attachment, texture, level, layer);
}

void glNamedFramebufferDrawBuffer(GLuint framebuffer, GLenum buf)
{
    glNamedFramebufferDrawBuffer_ptr(framebuffer, buf);
}

void glNamedFramebufferDrawBuffers(GLuint framebuffer, GLsizei n, const GLenum* bufs)
{
    glNamedFramebufferDrawBuffers_ptr(framebuffer, n, bufs);
}

void glNamedFramebufferReadBuffer(GLuint framebuffer, GLenum src)
{
    glNamedFramebufferReadBuffer_ptr(framebuffer, src);
}

void glInvalidateNamedFramebufferData(GLuint framebuffer, GLsizei numAttachments, const GLenum* attachments)
{
    glInvalidateNamedFramebufferData_ptr(framebuffer, numAttachments, attachments);
}

void glInvalidateNamedFramebufferSubData(GLuint framebuffer,
                                         GLsizei numAttachments,
                                         const GLenum* attachments,
                                         GLint x,
                                         GLint y,
                                         GLsizei width,
                                         GLsizei height)
{
    glInvalidateNamedFramebufferSubData_ptr(framebuffer, numAttachments, attachments, x, y, width, height);
}

void glClearNamedFramebufferiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint* value)
{
    glClearNamedFramebufferiv_ptr(framebuffer, buffer, drawbuffer, value);
}

void glClearNamedFramebufferuiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint* value)
{
    glClearNamedFramebufferuiv_ptr(framebuffer, buffer, drawbuffer, value);
}

void glClearNamedFramebufferfv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat* value)
{
    glClearNamedFramebufferfv_ptr(framebuffer, buffer, drawbuffer, value);
}

void glClearNamedFramebufferfi(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil)
{
    glClearNamedFramebufferfi_ptr(framebuffer, buffer, drawbuffer, depth, stencil);
}

void glBlitNamedFramebuffer(GLuint readFramebuffer,
                            GLuint drawFramebuffer,
                            GLint srcX0,
                            GLint srcY0,
                            GLint srcX1,
                            GLint srcY1,
                            GLint dstX0,
                            GLint dstY0,
                            GLint dstX1,
                            GLint dstY1,
                            GLbitfield mask,
                            GLenum filter)
{
    glBlitNamedFramebuffer_ptr(readFramebuffer,
                               drawFramebuffer,
                               srcX0,
                               srcY0,
                               srcX1,
                               srcY1,
                               dstX0,
                               dstY0,
                               dstX1,
                               dstY1,
                               mask,
                               filter);
}

GLenum glCheckNamedFramebufferStatus(GLuint framebuffer, GLenum target)
{
    return glCheckNamedFramebufferStatus_ptr(framebuffer, target);
}

void glGetNamedFramebufferParameteriv(GLuint framebuffer, GLenum pname, GLint* param)
{
    glGetNamedFramebufferParameteriv_ptr(framebuffer, pname, param);
}

void glGetNamedFramebufferAttachmentParameteriv(GLuint framebuffer, GLenum attachment, GLenum pname, GLint* params)
{
    glGetNamedFramebufferAttachmentParameteriv_ptr(framebuffer, attachment, pname, params);
}

void glCreateRenderbuffers(GLsizei n, GLuint* renderbuffers)
{
    glCreateRenderbuffers_ptr(n, renderbuffers);
}

void glNamedRenderbufferStorage(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height)
{
    glNamedRenderbufferStorage_ptr(renderbuffer, internalformat, width, height);
}

void glNamedRenderbufferStorageMultisample(GLuint renderbuffer,
                                           GLsizei samples,
                                           GLenum internalformat,
                                           GLsizei width,
                                           GLsizei height)
{
    glNamedRenderbufferStorageMultisample_ptr(renderbuffer, samples, internalformat, width, height);
}

void glGetNamedRenderbufferParameteriv(GLuint renderbuffer, GLenum pname, GLint* params)
{
    glGetNamedRenderbufferParameteriv_ptr(renderbuffer, pname, params);
}

void glCreateTextures(GLenum target, GLsizei n, GLuint* textures)
{
    glCreateTextures_ptr(target, n, textures);
}

void glTextureBuffer(GLuint texture, GLenum internalformat, GLuint buffer)
{
    glTextureBuffer_ptr(texture, internalformat, buffer);
}

void glTextureBufferRange(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size)
{
    glTextureBufferRange_ptr(texture, internalformat, buffer, offset, size);
}

void glTextureStorage1D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width)
{
    glTextureStorage1D_ptr(texture, levels, internalformat, width);
}

void glTextureStorage2D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height)
{
    glTextureStorage2D_ptr(texture, levels, internalformat, width, height);
}

void glTextureStorage3D(GLuint texture,
                        GLsizei levels,
                        GLenum internalformat,
                        GLsizei width,
                        GLsizei height,
                        GLsizei depth)
{
    glTextureStorage3D_ptr(texture, levels, internalformat, width, height, depth);
}

void glTextureStorage2DMultisample(GLuint texture,
                                   GLsizei samples,
                                   GLenum internalformat,
                                   GLsizei width,
                                   GLsizei height,
                                   GLboolean fixedsamplelocations)
{
    glTextureStorage2DMultisample_ptr(texture, samples, internalformat, width, height, fixedsamplelocations);
}

void glTextureStorage3DMultisample(GLuint texture,
                                   GLsizei samples,
                                   GLenum internalformat,
                                   GLsizei width,
                                   GLsizei height,
                                   GLsizei depth,
                                   GLboolean fixedsamplelocations)
{
    glTextureStorage3DMultisample_ptr(texture, samples, internalformat, width, height, depth, fixedsamplelocations);
}

void glTextureSubImage1D(GLuint texture,
                         GLint level,
                         GLint xoffset,
                         GLsizei width,
                         GLenum format,
                         GLenum type,
                         const void* pixels)
{
    glTextureSubImage1D_ptr(texture, level, xoffset, width, format, type, pixels);
}

void glTextureSubImage2D(GLuint texture,
                         GLint level,
                         GLint xoffset,
                         GLint yoffset,
                         GLsizei width,
                         GLsizei height,
                         GLenum format,
                         GLenum type,
                         const void* pixels)
{
    glTextureSubImage2D_ptr(texture, level, xoffset, yoffset, width, height, format, type, pixels);
}

void glTextureSubImage3D(GLuint texture,
                         GLint level,
                         GLint xoffset,
                         GLint yoffset,
                         GLint zoffset,
                         GLsizei width,
                         GLsizei height,
                         GLsizei depth,
                         GLenum format,
                         GLenum type,
                         const void* pixels)
{
    glTextureSubImage3D_ptr(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}

void glCompressedTextureSubImage1D(GLuint texture,
                                   GLint level,
                                   GLint xoffset,
                                   GLsizei width,
                                   GLenum format,
                                   GLsizei imageSize,
                                   const void* data)
{
    glCompressedTextureSubImage1D_ptr(texture, level, xoffset, width, format, imageSize, data);
}

void glCompressedTextureSubImage2D(GLuint texture,
                                   GLint level,
                                   GLint xoffset,
                                   GLint yoffset,
                                   GLsizei width,
                                   GLsizei height,
                                   GLenum format,
                                   GLsizei imageSize,
                                   const void* data)
{
    glCompressedTextureSubImage2D_ptr(texture, level, xoffset, yoffset, width, height, format, imageSize, data);
}

void glCompressedTextureSubImage3D(GLuint texture,
                                   GLint level,
                                   GLint xoffset,
                                   GLint yoffset,
                                   GLint zoffset,
                                   GLsizei width,
                                   GLsizei height,
                                   GLsizei depth,
                                   GLenum format,
                                   GLsizei imageSize,
                                   const void* data)
{
    glCompressedTextureSubImage3D_ptr(texture,
                                      level,
                                      xoffset,
                                      yoffset,
                                      zoffset,
                                      width,
                                      height,
                                      depth,
                                      format,
                                      imageSize,
                                      data);
}

void glCopyTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width)
{
    glCopyTextureSubImage1D_ptr(texture, level, xoffset, x, y, width);
}

void glCopyTextureSubImage2D(GLuint texture,
                             GLint level,
                             GLint xoffset,
                             GLint yoffset,
                             GLint x,
                             GLint y,
                             GLsizei width,
                             GLsizei height)
{
    glCopyTextureSubImage2D_ptr(texture, level, xoffset, yoffset, x, y, width, height);
}

void glCopyTextureSubImage3D(GLuint texture,
                             GLint level,
                             GLint xoffset,
                             GLint yoffset,
                             GLint zoffset,
                             GLint x,
                             GLint y,
                             GLsizei width,
                             GLsizei height)
{
    glCopyTextureSubImage3D_ptr(texture, level, xoffset, yoffset, zoffset, x, y, width, height);
}

void glTextureParameterf(GLuint texture, GLenum pname, GLfloat param)
{
    glTextureParameterf_ptr(texture, pname, param);
}

void glTextureParameterfv(GLuint texture, GLenum pname, const GLfloat* param)
{
    glTextureParameterfv_ptr(texture, pname, param);
}

void glTextureParameteri(GLuint texture, GLenum pname, GLint param)
{
    glTextureParameteri_ptr(texture, pname, param);
}

void glTextureParameterIiv(GLuint texture, GLenum pname, const GLint* params)
{
    glTextureParameterIiv_ptr(texture, pname, params);
}

void glTextureParameterIuiv(GLuint texture, GLenum pname, const GLuint* params)
{
    glTextureParameterIuiv_ptr(texture, pname, params);
}

void glTextureParameteriv(GLuint texture, GLenum pname, const GLint* param)
{
    glTextureParameteriv_ptr(texture, pname, param);
}

void glGenerateTextureMipmap(GLuint texture)
{
    glGenerateTextureMipmap_ptr(texture);
}

void glBindTextureUnit(GLuint unit, GLuint texture)
{
    glBindTextureUnit_ptr(unit, texture);
}

void glGetTextureImage(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* pixels)
{
    glGetTextureImage_ptr(texture, level, format, type, bufSize, pixels);
}

void glGetCompressedTextureImage(GLuint texture, GLint level, GLsizei bufSize, void* pixels)
{
    glGetCompressedTextureImage_ptr(texture, level, bufSize, pixels);
}

void glGetTextureLevelParameterfv(GLuint texture, GLint level, GLenum pname, GLfloat* params)
{
    glGetTextureLevelParameterfv_ptr(texture, level, pname, params);
}

void glGetTextureLevelParameteriv(GLuint texture, GLint level, GLenum pname, GLint* params)
{
    glGetTextureLevelParameteriv_ptr(texture, level, pname, params);
}

void glGetTextureParameterfv(GLuint texture, GLenum pname, GLfloat* params)
{
    glGetTextureParameterfv_ptr(texture, pname, params);
}

void glGetTextureParameterIiv(GLuint texture, GLenum pname, GLint* params)
{
    glGetTextureParameterIiv_ptr(texture, pname, params);
}

void glGetTextureParameterIuiv(GLuint texture, GLenum pname, GLuint* params)
{
    glGetTextureParameterIuiv_ptr(texture, pname, params);
}

void glGetTextureParameteriv(GLuint texture, GLenum pname, GLint* params)
{
    glGetTextureParameteriv_ptr(texture, pname, params);
}

void glCreateVertexArrays(GLsizei n, GLuint* arrays)
{
    glCreateVertexArrays_ptr(n, arrays);
}

void glDisableVertexArrayAttrib(GLuint vaobj, GLuint index)
{
    glDisableVertexArrayAttrib_ptr(vaobj, index);
}

void glEnableVertexArrayAttrib(GLuint vaobj, GLuint index)
{
    glEnableVertexArrayAttrib_ptr(vaobj, index);
}

void glVertexArrayElementBuffer(GLuint vaobj, GLuint buffer)
{
    glVertexArrayElementBuffer_ptr(vaobj, buffer);
}

void glVertexArrayVertexBuffer(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride)
{
    glVertexArrayVertexBuffer_ptr(vaobj, bindingindex, buffer, offset, stride);
}

void glVertexArrayVertexBuffers(GLuint vaobj,
                                GLuint first,
                                GLsizei count,
                                const GLuint* buffers,
                                const GLintptr* offsets,
                                const GLsizei* strides)
{
    glVertexArrayVertexBuffers_ptr(vaobj, first, count, buffers, offsets, strides);
}

void glVertexArrayAttribBinding(GLuint vaobj, GLuint attribindex, GLuint bindingindex)
{
    glVertexArrayAttribBinding_ptr(vaobj, attribindex, bindingindex);
}

void glVertexArrayAttribFormat(GLuint vaobj,
                               GLuint attribindex,
                               GLint size,
                               GLenum type,
                               GLboolean normalized,
                               GLuint relativeoffset)
{
    glVertexArrayAttribFormat_ptr(vaobj, attribindex, size, type, normalized, relativeoffset);
}

void glVertexArrayAttribIFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset)
{
    glVertexArrayAttribIFormat_ptr(vaobj, attribindex, size, type, relativeoffset);
}

void glVertexArrayAttribLFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset)
{
    glVertexArrayAttribLFormat_ptr(vaobj, attribindex, size, type, relativeoffset);
}

void glVertexArrayBindingDivisor(GLuint vaobj, GLuint bindingindex, GLuint divisor)
{
    glVertexArrayBindingDivisor_ptr(vaobj, bindingindex, divisor);
}

void glGetVertexArrayiv(GLuint vaobj, GLenum pname, GLint* param)
{
    glGetVertexArrayiv_ptr(vaobj, pname, param);
}

void glGetVertexArrayIndexediv(GLuint vaobj, GLuint index, GLenum pname, GLint* param)
{
    glGetVertexArrayIndexediv_ptr(vaobj, index, pname, param);
}

void glGetVertexArrayIndexed64iv(GLuint vaobj, GLuint index, GLenum pname, GLint64* param)
{
    glGetVertexArrayIndexed64iv_ptr(vaobj, index, pname, param);
}

void glCreateSamplers(GLsizei n, GLuint* samplers)
{
    glCreateSamplers_ptr(n, samplers);
}

void glCreateProgramPipelines(GLsizei n, GLuint* pipelines)
{
    glCreateProgramPipelines_ptr(n, pipelines);
}

void glCreateQueries(GLenum target, GLsizei n, GLuint* ids)
{
    glCreateQueries_ptr(target, n, ids);
}

void glGetQueryBufferObjecti64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset)
{
    glGetQueryBufferObjecti64v_ptr(id, buffer, pname, offset);
}

void glGetQueryBufferObjectiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset)
{
    glGetQueryBufferObjectiv_ptr(id, buffer, pname, offset);
}

void glGetQueryBufferObjectui64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset)
{
    glGetQueryBufferObjectui64v_ptr(id, buffer, pname, offset);
}

void glGetQueryBufferObjectuiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset)
{
    glGetQueryBufferObjectuiv_ptr(id, buffer, pname, offset);
}

void glMemoryBarrierByRegion(GLbitfield barriers)
{
    glMemoryBarrierByRegion_ptr(barriers);
}

void glGetTextureSubImage(GLuint texture,
                          GLint level,
                          GLint xoffset,
                          GLint yoffset,
                          GLint zoffset,
                          GLsizei width,
                          GLsizei height,
                          GLsizei depth,
                          GLenum format,
                          GLenum type,
                          GLsizei bufSize,
                          void* pixels)
{
    glGetTextureSubImage_ptr(texture,
                             level,
                             xoffset,
                             yoffset,
                             zoffset,
                             width,
                             height,
                             depth,
                             format,
                             type,
                             bufSize,
                             pixels);
}

void glGetCompressedTextureSubImage(GLuint texture,
                                    GLint level,
                                    GLint xoffset,
                                    GLint yoffset,
                                    GLint zoffset,
                                    GLsizei width,
                                    GLsizei height,
                                    GLsizei depth,
                                    GLsizei bufSize,
                                    void* pixels)
{
    glGetCompressedTextureSubImage_ptr(texture, level, xoffset, yoffset, zoffset, width, height, depth, bufSize, pixels);
}

GLenum glGetGraphicsResetStatus()
{
    return glGetGraphicsResetStatus_ptr();
}

void glGetnCompressedTexImage(GLenum target, GLint lod, GLsizei bufSize, void* pixels)
{
    glGetnCompressedTexImage_ptr(target, lod, bufSize, pixels);
}

void glGetnTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* pixels)
{
    glGetnTexImage_ptr(target, level, format, type, bufSize, pixels);
}

void glGetnUniformdv(GLuint program, GLint location, GLsizei bufSize, GLdouble* params)
{
    glGetnUniformdv_ptr(program, location, bufSize, params);
}

void glGetnUniformfv(GLuint program, GLint location, GLsizei bufSize, GLfloat* params)
{
    glGetnUniformfv_ptr(program, location, bufSize, params);
}

void glGetnUniformiv(GLuint program, GLint location, GLsizei bufSize, GLint* params)
{
    glGetnUniformiv_ptr(program, location, bufSize, params);
}

void glGetnUniformuiv(GLuint program, GLint location, GLsizei bufSize, GLuint* params)
{
    glGetnUniformuiv_ptr(program, location, bufSize, params);
}

void glReadnPixels(GLint x,
                   GLint y,
                   GLsizei width,
                   GLsizei height,
                   GLenum format,
                   GLenum type,
                   GLsizei bufSize,
                   void* data)
{
    glReadnPixels_ptr(x, y, width, height, format, type, bufSize, data);
}

void glTextureBarrier()
{
    glTextureBarrier_ptr();
}

#pragma endregion

#pragma region GL_VERSION_4_6

void glSpecializeShader(GLuint shader,
                        const GLchar* pEntryPoint,
                        GLuint numSpecializationConstants,
                        const GLuint* pConstantIndex,
                        const GLuint* pConstantValue)
{
    glSpecializeShader_ptr(shader, pEntryPoint, numSpecializationConstants, pConstantIndex, pConstantValue);
}

void glMultiDrawArraysIndirectCount(GLenum mode,
                                    const void* indirect,
                                    GLintptr drawcount,
                                    GLsizei maxdrawcount,
                                    GLsizei stride)
{
    glMultiDrawArraysIndirectCount_ptr(mode, indirect, drawcount, maxdrawcount, stride);
}

void glMultiDrawElementsIndirectCount(GLenum mode,
                                      GLenum type,
                                      const void* indirect,
                                      GLintptr drawcount,
                                      GLsizei maxdrawcount,
                                      GLsizei stride)
{
    glMultiDrawElementsIndirectCount_ptr(mode, type, indirect, drawcount, maxdrawcount, stride);
}

void glPolygonOffsetClamp(GLfloat factor, GLfloat units, GLfloat clamp)
{
    glPolygonOffsetClamp_ptr(factor, units, clamp);
}

#pragma endregion

#pragma region GL_AMD_framebuffer_multisample_advanced

void glRenderbufferStorageMultisampleAdvancedAMD(GLenum target,
                                                 GLsizei samples,
                                                 GLsizei storageSamples,
                                                 GLenum internalformat,
                                                 GLsizei width,
                                                 GLsizei height)
{
    glRenderbufferStorageMultisampleAdvancedAMD_ptr(target, samples, storageSamples, internalformat, width, height);
}

void glNamedRenderbufferStorageMultisampleAdvancedAMD(GLuint renderbuffer,
                                                      GLsizei samples,
                                                      GLsizei storageSamples,
                                                      GLenum internalformat,
                                                      GLsizei width,
                                                      GLsizei height)
{
    glNamedRenderbufferStorageMultisampleAdvancedAMD_ptr(renderbuffer,
                                                         samples,
                                                         storageSamples,
                                                         internalformat,
                                                         width,
                                                         height);
}

#pragma endregion

#pragma region GL_AMD_performance_monitor

void glGetPerfMonitorGroupsAMD(GLint* numGroups, GLsizei groupsSize, GLuint* groups)
{
    glGetPerfMonitorGroupsAMD_ptr(numGroups, groupsSize, groups);
}

void glGetPerfMonitorCountersAMD(GLuint group,
                                 GLint* numCounters,
                                 GLint* maxActiveCounters,
                                 GLsizei counterSize,
                                 GLuint* counters)
{
    glGetPerfMonitorCountersAMD_ptr(group, numCounters, maxActiveCounters, counterSize, counters);
}

void glGetPerfMonitorGroupStringAMD(GLuint group, GLsizei bufSize, GLsizei* length, GLchar* groupString)
{
    glGetPerfMonitorGroupStringAMD_ptr(group, bufSize, length, groupString);
}

void glGetPerfMonitorCounterStringAMD(GLuint group,
                                      GLuint counter,
                                      GLsizei bufSize,
                                      GLsizei* length,
                                      GLchar* counterString)
{
    glGetPerfMonitorCounterStringAMD_ptr(group, counter, bufSize, length, counterString);
}

void glGetPerfMonitorCounterInfoAMD(GLuint group, GLuint counter, GLenum pname, void* data)
{
    glGetPerfMonitorCounterInfoAMD_ptr(group, counter, pname, data);
}

void glGenPerfMonitorsAMD(GLsizei n, GLuint* monitors)
{
    glGenPerfMonitorsAMD_ptr(n, monitors);
}

void glDeletePerfMonitorsAMD(GLsizei n, GLuint* monitors)
{
    glDeletePerfMonitorsAMD_ptr(n, monitors);
}

void glSelectPerfMonitorCountersAMD(GLuint monitor,
                                    GLboolean enable,
                                    GLuint group,
                                    GLint numCounters,
                                    GLuint* counterList)
{
    glSelectPerfMonitorCountersAMD_ptr(monitor, enable, group, numCounters, counterList);
}

void glBeginPerfMonitorAMD(GLuint monitor)
{
    glBeginPerfMonitorAMD_ptr(monitor);
}

void glEndPerfMonitorAMD(GLuint monitor)
{
    glEndPerfMonitorAMD_ptr(monitor);
}

void glGetPerfMonitorCounterDataAMD(GLuint monitor, GLenum pname, GLsizei dataSize, GLuint* data, GLint* bytesWritten)
{
    glGetPerfMonitorCounterDataAMD_ptr(monitor, pname, dataSize, data, bytesWritten);
}

#pragma endregion

#pragma region GL_APPLE_rgb_422

#pragma endregion

#pragma region GL_ARB_ES2_compatibility

#pragma endregion

#pragma region GL_ARB_ES3_1_compatibility

#pragma endregion

#pragma region GL_ARB_ES3_2_compatibility

void glPrimitiveBoundingBoxARB(GLfloat minX,
                               GLfloat minY,
                               GLfloat minZ,
                               GLfloat minW,
                               GLfloat maxX,
                               GLfloat maxY,
                               GLfloat maxZ,
                               GLfloat maxW)
{
    glPrimitiveBoundingBoxARB_ptr(minX, minY, minZ, minW, maxX, maxY, maxZ, maxW);
}

#pragma endregion

#pragma region GL_ARB_ES3_compatibility

#pragma endregion

#pragma region GL_ARB_arrays_of_arrays

#pragma endregion

#pragma region GL_ARB_base_instance

#pragma endregion

#pragma region GL_ARB_bindless_texture

GLuint64 glGetTextureHandleARB(GLuint texture)
{
    return glGetTextureHandleARB_ptr(texture);
}

GLuint64 glGetTextureSamplerHandleARB(GLuint texture, GLuint sampler)
{
    return glGetTextureSamplerHandleARB_ptr(texture, sampler);
}

void glMakeTextureHandleResidentARB(GLuint64 handle)
{
    glMakeTextureHandleResidentARB_ptr(handle);
}

void glMakeTextureHandleNonResidentARB(GLuint64 handle)
{
    glMakeTextureHandleNonResidentARB_ptr(handle);
}

GLuint64 glGetImageHandleARB(GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format)
{
    return glGetImageHandleARB_ptr(texture, level, layered, layer, format);
}

void glMakeImageHandleResidentARB(GLuint64 handle, GLenum access)
{
    glMakeImageHandleResidentARB_ptr(handle, access);
}

void glMakeImageHandleNonResidentARB(GLuint64 handle)
{
    glMakeImageHandleNonResidentARB_ptr(handle);
}

void glUniformHandleui64ARB(GLint location, GLuint64 value)
{
    glUniformHandleui64ARB_ptr(location, value);
}

void glUniformHandleui64vARB(GLint location, GLsizei count, const GLuint64* value)
{
    glUniformHandleui64vARB_ptr(location, count, value);
}

void glProgramUniformHandleui64ARB(GLuint program, GLint location, GLuint64 value)
{
    glProgramUniformHandleui64ARB_ptr(program, location, value);
}

void glProgramUniformHandleui64vARB(GLuint program, GLint location, GLsizei count, const GLuint64* values)
{
    glProgramUniformHandleui64vARB_ptr(program, location, count, values);
}

GLboolean glIsTextureHandleResidentARB(GLuint64 handle)
{
    return glIsTextureHandleResidentARB_ptr(handle);
}

GLboolean glIsImageHandleResidentARB(GLuint64 handle)
{
    return glIsImageHandleResidentARB_ptr(handle);
}

void glVertexAttribL1ui64ARB(GLuint index, GLuint64EXT x)
{
    glVertexAttribL1ui64ARB_ptr(index, x);
}

void glVertexAttribL1ui64vARB(GLuint index, const GLuint64EXT* v)
{
    glVertexAttribL1ui64vARB_ptr(index, v);
}

void glGetVertexAttribLui64vARB(GLuint index, GLenum pname, GLuint64EXT* params)
{
    glGetVertexAttribLui64vARB_ptr(index, pname, params);
}

#pragma endregion

#pragma region GL_ARB_blend_func_extended

#pragma endregion

#pragma region GL_ARB_buffer_storage

#pragma endregion

#pragma region GL_ARB_cl_event

GLsync glCreateSyncFromCLeventARB(struct _cl_context* context, struct _cl_event* event, GLbitfield flags)
{
    return glCreateSyncFromCLeventARB_ptr(context, event, flags);
}

#pragma endregion

#pragma region GL_ARB_clear_buffer_object

#pragma endregion

#pragma region GL_ARB_clear_texture

#pragma endregion

#pragma region GL_ARB_clip_control

#pragma endregion

#pragma region GL_ARB_compressed_texture_pixel_storage

#pragma endregion

#pragma region GL_ARB_compute_shader

#pragma endregion

#pragma region GL_ARB_compute_variable_group_size

void glDispatchComputeGroupSizeARB(GLuint num_groups_x,
                                   GLuint num_groups_y,
                                   GLuint num_groups_z,
                                   GLuint group_size_x,
                                   GLuint group_size_y,
                                   GLuint group_size_z)
{
    glDispatchComputeGroupSizeARB_ptr(num_groups_x,
                                      num_groups_y,
                                      num_groups_z,
                                      group_size_x,
                                      group_size_y,
                                      group_size_z);
}

#pragma endregion

#pragma region GL_ARB_conditional_render_inverted

#pragma endregion

#pragma region GL_ARB_conservative_depth

#pragma endregion

#pragma region GL_ARB_copy_buffer

#pragma endregion

#pragma region GL_ARB_copy_image

#pragma endregion

#pragma region GL_ARB_cull_distance

#pragma endregion

#pragma region GL_ARB_debug_output

void glDebugMessageControlARB(GLenum source,
                              GLenum type,
                              GLenum severity,
                              GLsizei count,
                              const GLuint* ids,
                              GLboolean enabled)
{
    glDebugMessageControlARB_ptr(source, type, severity, count, ids, enabled);
}

void glDebugMessageInsertARB(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf)
{
    glDebugMessageInsertARB_ptr(source, type, id, severity, length, buf);
}

void glDebugMessageCallbackARB(GLDEBUGPROCARB callback, const void* userParam)
{
    glDebugMessageCallbackARB_ptr(callback, userParam);
}

GLuint glGetDebugMessageLogARB(GLuint count,
                               GLsizei bufSize,
                               GLenum* sources,
                               GLenum* types,
                               GLuint* ids,
                               GLenum* severities,
                               GLsizei* lengths,
                               GLchar* messageLog)
{
    return glGetDebugMessageLogARB_ptr(count, bufSize, sources, types, ids, severities, lengths, messageLog);
}

#pragma endregion

#pragma region GL_ARB_depth_buffer_float

#pragma endregion

#pragma region GL_ARB_depth_clamp

#pragma endregion

#pragma region GL_ARB_derivative_control

#pragma endregion

#pragma region GL_ARB_direct_state_access

#pragma endregion

#pragma region GL_ARB_draw_buffers_blend

void glBlendEquationiARB(GLuint buf, GLenum mode)
{
    glBlendEquationiARB_ptr(buf, mode);
}

void glBlendEquationSeparateiARB(GLuint buf, GLenum modeRGB, GLenum modeAlpha)
{
    glBlendEquationSeparateiARB_ptr(buf, modeRGB, modeAlpha);
}

void glBlendFunciARB(GLuint buf, GLenum src, GLenum dst)
{
    glBlendFunciARB_ptr(buf, src, dst);
}

void glBlendFuncSeparateiARB(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)
{
    glBlendFuncSeparateiARB_ptr(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
}

#pragma endregion

#pragma region GL_ARB_draw_elements_base_vertex

#pragma endregion

#pragma region GL_ARB_draw_indirect

#pragma endregion

#pragma region GL_ARB_draw_instanced

void glDrawArraysInstancedARB(GLenum mode, GLint first, GLsizei count, GLsizei primcount)
{
    glDrawArraysInstancedARB_ptr(mode, first, count, primcount);
}

void glDrawElementsInstancedARB(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei primcount)
{
    glDrawElementsInstancedARB_ptr(mode, count, type, indices, primcount);
}

#pragma endregion

#pragma region GL_ARB_enhanced_layouts

#pragma endregion

#pragma region GL_ARB_explicit_attrib_location

#pragma endregion

#pragma region GL_ARB_explicit_uniform_location

#pragma endregion

#pragma region GL_ARB_fragment_coord_conventions

#pragma endregion

#pragma region GL_ARB_fragment_layer_viewport

#pragma endregion

#pragma region GL_ARB_fragment_shader_interlock

#pragma endregion

#pragma region GL_ARB_framebuffer_no_attachments

#pragma endregion

#pragma region GL_ARB_framebuffer_object

#pragma endregion

#pragma region GL_ARB_framebuffer_sRGB

#pragma endregion

#pragma region GL_ARB_geometry_shader4

void glProgramParameteriARB(GLuint program, GLenum pname, GLint value)
{
    glProgramParameteriARB_ptr(program, pname, value);
}

void glFramebufferTextureARB(GLenum target, GLenum attachment, GLuint texture, GLint level)
{
    glFramebufferTextureARB_ptr(target, attachment, texture, level);
}

void glFramebufferTextureLayerARB(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer)
{
    glFramebufferTextureLayerARB_ptr(target, attachment, texture, level, layer);
}

void glFramebufferTextureFaceARB(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face)
{
    glFramebufferTextureFaceARB_ptr(target, attachment, texture, level, face);
}

#pragma endregion

#pragma region GL_ARB_get_program_binary

#pragma endregion

#pragma region GL_ARB_get_texture_sub_image

#pragma endregion

#pragma region GL_ARB_gl_spirv

void glSpecializeShaderARB(GLuint shader,
                           const GLchar* pEntryPoint,
                           GLuint numSpecializationConstants,
                           const GLuint* pConstantIndex,
                           const GLuint* pConstantValue)
{
    glSpecializeShaderARB_ptr(shader, pEntryPoint, numSpecializationConstants, pConstantIndex, pConstantValue);
}

#pragma endregion

#pragma region GL_ARB_gpu_shader5

#pragma endregion

#pragma region GL_ARB_gpu_shader_fp64

#pragma endregion

#pragma region GL_ARB_gpu_shader_int64

void glUniform1i64ARB(GLint location, GLint64 x)
{
    glUniform1i64ARB_ptr(location, x);
}

void glUniform2i64ARB(GLint location, GLint64 x, GLint64 y)
{
    glUniform2i64ARB_ptr(location, x, y);
}

void glUniform3i64ARB(GLint location, GLint64 x, GLint64 y, GLint64 z)
{
    glUniform3i64ARB_ptr(location, x, y, z);
}

void glUniform4i64ARB(GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w)
{
    glUniform4i64ARB_ptr(location, x, y, z, w);
}

void glUniform1i64vARB(GLint location, GLsizei count, const GLint64* value)
{
    glUniform1i64vARB_ptr(location, count, value);
}

void glUniform2i64vARB(GLint location, GLsizei count, const GLint64* value)
{
    glUniform2i64vARB_ptr(location, count, value);
}

void glUniform3i64vARB(GLint location, GLsizei count, const GLint64* value)
{
    glUniform3i64vARB_ptr(location, count, value);
}

void glUniform4i64vARB(GLint location, GLsizei count, const GLint64* value)
{
    glUniform4i64vARB_ptr(location, count, value);
}

void glUniform1ui64ARB(GLint location, GLuint64 x)
{
    glUniform1ui64ARB_ptr(location, x);
}

void glUniform2ui64ARB(GLint location, GLuint64 x, GLuint64 y)
{
    glUniform2ui64ARB_ptr(location, x, y);
}

void glUniform3ui64ARB(GLint location, GLuint64 x, GLuint64 y, GLuint64 z)
{
    glUniform3ui64ARB_ptr(location, x, y, z);
}

void glUniform4ui64ARB(GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w)
{
    glUniform4ui64ARB_ptr(location, x, y, z, w);
}

void glUniform1ui64vARB(GLint location, GLsizei count, const GLuint64* value)
{
    glUniform1ui64vARB_ptr(location, count, value);
}

void glUniform2ui64vARB(GLint location, GLsizei count, const GLuint64* value)
{
    glUniform2ui64vARB_ptr(location, count, value);
}

void glUniform3ui64vARB(GLint location, GLsizei count, const GLuint64* value)
{
    glUniform3ui64vARB_ptr(location, count, value);
}

void glUniform4ui64vARB(GLint location, GLsizei count, const GLuint64* value)
{
    glUniform4ui64vARB_ptr(location, count, value);
}

void glGetUniformi64vARB(GLuint program, GLint location, GLint64* params)
{
    glGetUniformi64vARB_ptr(program, location, params);
}

void glGetUniformui64vARB(GLuint program, GLint location, GLuint64* params)
{
    glGetUniformui64vARB_ptr(program, location, params);
}

void glGetnUniformi64vARB(GLuint program, GLint location, GLsizei bufSize, GLint64* params)
{
    glGetnUniformi64vARB_ptr(program, location, bufSize, params);
}

void glGetnUniformui64vARB(GLuint program, GLint location, GLsizei bufSize, GLuint64* params)
{
    glGetnUniformui64vARB_ptr(program, location, bufSize, params);
}

void glProgramUniform1i64ARB(GLuint program, GLint location, GLint64 x)
{
    glProgramUniform1i64ARB_ptr(program, location, x);
}

void glProgramUniform2i64ARB(GLuint program, GLint location, GLint64 x, GLint64 y)
{
    glProgramUniform2i64ARB_ptr(program, location, x, y);
}

void glProgramUniform3i64ARB(GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z)
{
    glProgramUniform3i64ARB_ptr(program, location, x, y, z);
}

void glProgramUniform4i64ARB(GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w)
{
    glProgramUniform4i64ARB_ptr(program, location, x, y, z, w);
}

void glProgramUniform1i64vARB(GLuint program, GLint location, GLsizei count, const GLint64* value)
{
    glProgramUniform1i64vARB_ptr(program, location, count, value);
}

void glProgramUniform2i64vARB(GLuint program, GLint location, GLsizei count, const GLint64* value)
{
    glProgramUniform2i64vARB_ptr(program, location, count, value);
}

void glProgramUniform3i64vARB(GLuint program, GLint location, GLsizei count, const GLint64* value)
{
    glProgramUniform3i64vARB_ptr(program, location, count, value);
}

void glProgramUniform4i64vARB(GLuint program, GLint location, GLsizei count, const GLint64* value)
{
    glProgramUniform4i64vARB_ptr(program, location, count, value);
}

void glProgramUniform1ui64ARB(GLuint program, GLint location, GLuint64 x)
{
    glProgramUniform1ui64ARB_ptr(program, location, x);
}

void glProgramUniform2ui64ARB(GLuint program, GLint location, GLuint64 x, GLuint64 y)
{
    glProgramUniform2ui64ARB_ptr(program, location, x, y);
}

void glProgramUniform3ui64ARB(GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z)
{
    glProgramUniform3ui64ARB_ptr(program, location, x, y, z);
}

void glProgramUniform4ui64ARB(GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w)
{
    glProgramUniform4ui64ARB_ptr(program, location, x, y, z, w);
}

void glProgramUniform1ui64vARB(GLuint program, GLint location, GLsizei count, const GLuint64* value)
{
    glProgramUniform1ui64vARB_ptr(program, location, count, value);
}

void glProgramUniform2ui64vARB(GLuint program, GLint location, GLsizei count, const GLuint64* value)
{
    glProgramUniform2ui64vARB_ptr(program, location, count, value);
}

void glProgramUniform3ui64vARB(GLuint program, GLint location, GLsizei count, const GLuint64* value)
{
    glProgramUniform3ui64vARB_ptr(program, location, count, value);
}

void glProgramUniform4ui64vARB(GLuint program, GLint location, GLsizei count, const GLuint64* value)
{
    glProgramUniform4ui64vARB_ptr(program, location, count, value);
}

#pragma endregion

#pragma region GL_ARB_half_float_vertex

#pragma endregion

#pragma region GL_ARB_imaging

#pragma endregion

#pragma region GL_ARB_indirect_parameters

void glMultiDrawArraysIndirectCountARB(GLenum mode,
                                       const void* indirect,
                                       GLintptr drawcount,
                                       GLsizei maxdrawcount,
                                       GLsizei stride)
{
    glMultiDrawArraysIndirectCountARB_ptr(mode, indirect, drawcount, maxdrawcount, stride);
}

void glMultiDrawElementsIndirectCountARB(GLenum mode,
                                         GLenum type,
                                         const void* indirect,
                                         GLintptr drawcount,
                                         GLsizei maxdrawcount,
                                         GLsizei stride)
{
    glMultiDrawElementsIndirectCountARB_ptr(mode, type, indirect, drawcount, maxdrawcount, stride);
}

#pragma endregion

#pragma region GL_ARB_instanced_arrays

void glVertexAttribDivisorARB(GLuint index, GLuint divisor)
{
    glVertexAttribDivisorARB_ptr(index, divisor);
}

#pragma endregion

#pragma region GL_ARB_internalformat_query

#pragma endregion

#pragma region GL_ARB_internalformat_query2

#pragma endregion

#pragma region GL_ARB_invalidate_subdata

#pragma endregion

#pragma region GL_ARB_map_buffer_alignment

#pragma endregion

#pragma region GL_ARB_map_buffer_range

#pragma endregion

#pragma region GL_ARB_multi_bind

#pragma endregion

#pragma region GL_ARB_multi_draw_indirect

#pragma endregion

#pragma region GL_ARB_occlusion_query2

#pragma endregion

#pragma region GL_ARB_parallel_shader_compile

void glMaxShaderCompilerThreadsARB(GLuint count)
{
    glMaxShaderCompilerThreadsARB_ptr(count);
}

#pragma endregion

#pragma region GL_ARB_pipeline_statistics_query

#pragma endregion

#pragma region GL_ARB_pixel_buffer_object

#pragma endregion

#pragma region GL_ARB_polygon_offset_clamp

#pragma endregion

#pragma region GL_ARB_post_depth_coverage

#pragma endregion

#pragma region GL_ARB_program_interface_query

#pragma endregion

#pragma region GL_ARB_provoking_vertex

#pragma endregion

#pragma region GL_ARB_query_buffer_object

#pragma endregion

#pragma region GL_ARB_robust_buffer_access_behavior

#pragma endregion

#pragma region GL_ARB_robustness

GLenum glGetGraphicsResetStatusARB()
{
    return glGetGraphicsResetStatusARB_ptr();
}

void glGetnTexImageARB(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* img)
{
    glGetnTexImageARB_ptr(target, level, format, type, bufSize, img);
}

void glReadnPixelsARB(GLint x,
                      GLint y,
                      GLsizei width,
                      GLsizei height,
                      GLenum format,
                      GLenum type,
                      GLsizei bufSize,
                      void* data)
{
    glReadnPixelsARB_ptr(x, y, width, height, format, type, bufSize, data);
}

void glGetnCompressedTexImageARB(GLenum target, GLint lod, GLsizei bufSize, void* img)
{
    glGetnCompressedTexImageARB_ptr(target, lod, bufSize, img);
}

void glGetnUniformfvARB(GLuint program, GLint location, GLsizei bufSize, GLfloat* params)
{
    glGetnUniformfvARB_ptr(program, location, bufSize, params);
}

void glGetnUniformivARB(GLuint program, GLint location, GLsizei bufSize, GLint* params)
{
    glGetnUniformivARB_ptr(program, location, bufSize, params);
}

void glGetnUniformuivARB(GLuint program, GLint location, GLsizei bufSize, GLuint* params)
{
    glGetnUniformuivARB_ptr(program, location, bufSize, params);
}

void glGetnUniformdvARB(GLuint program, GLint location, GLsizei bufSize, GLdouble* params)
{
    glGetnUniformdvARB_ptr(program, location, bufSize, params);
}

#pragma endregion

#pragma region GL_ARB_robustness_isolation

#pragma endregion

#pragma region GL_ARB_sample_locations

void glFramebufferSampleLocationsfvARB(GLenum target, GLuint start, GLsizei count, const GLfloat* v)
{
    glFramebufferSampleLocationsfvARB_ptr(target, start, count, v);
}

void glNamedFramebufferSampleLocationsfvARB(GLuint framebuffer, GLuint start, GLsizei count, const GLfloat* v)
{
    glNamedFramebufferSampleLocationsfvARB_ptr(framebuffer, start, count, v);
}

void glEvaluateDepthValuesARB()
{
    glEvaluateDepthValuesARB_ptr();
}

#pragma endregion

#pragma region GL_ARB_sample_shading

void glMinSampleShadingARB(GLfloat value)
{
    glMinSampleShadingARB_ptr(value);
}

#pragma endregion

#pragma region GL_ARB_sampler_objects

#pragma endregion

#pragma region GL_ARB_seamless_cube_map

#pragma endregion

#pragma region GL_ARB_seamless_cubemap_per_texture

#pragma endregion

#pragma region GL_ARB_separate_shader_objects

#pragma endregion

#pragma region GL_ARB_shader_atomic_counter_ops

#pragma endregion

#pragma region GL_ARB_shader_atomic_counters

#pragma endregion

#pragma region GL_ARB_shader_ballot

#pragma endregion

#pragma region GL_ARB_shader_bit_encoding

#pragma endregion

#pragma region GL_ARB_shader_clock

#pragma endregion

#pragma region GL_ARB_shader_draw_parameters

#pragma endregion

#pragma region GL_ARB_shader_group_vote

#pragma endregion

#pragma region GL_ARB_shader_image_load_store

#pragma endregion

#pragma region GL_ARB_shader_image_size

#pragma endregion

#pragma region GL_ARB_shader_precision

#pragma endregion

#pragma region GL_ARB_shader_stencil_export

#pragma endregion

#pragma region GL_ARB_shader_storage_buffer_object

#pragma endregion

#pragma region GL_ARB_shader_subroutine

#pragma endregion

#pragma region GL_ARB_shader_texture_image_samples

#pragma endregion

#pragma region GL_ARB_shader_viewport_layer_array

#pragma endregion

#pragma region GL_ARB_shading_language_420pack

#pragma endregion

#pragma region GL_ARB_shading_language_include

void glNamedStringARB(GLenum type, GLint namelen, const GLchar* name, GLint stringlen, const GLchar* string)
{
    glNamedStringARB_ptr(type, namelen, name, stringlen, string);
}

void glDeleteNamedStringARB(GLint namelen, const GLchar* name)
{
    glDeleteNamedStringARB_ptr(namelen, name);
}

void glCompileShaderIncludeARB(GLuint shader, GLsizei count, const GLchar* const* path, const GLint* length)
{
    glCompileShaderIncludeARB_ptr(shader, count, path, length);
}

GLboolean glIsNamedStringARB(GLint namelen, const GLchar* name)
{
    return glIsNamedStringARB_ptr(namelen, name);
}

void glGetNamedStringARB(GLint namelen, const GLchar* name, GLsizei bufSize, GLint* stringlen, GLchar* string)
{
    glGetNamedStringARB_ptr(namelen, name, bufSize, stringlen, string);
}

void glGetNamedStringivARB(GLint namelen, const GLchar* name, GLenum pname, GLint* params)
{
    glGetNamedStringivARB_ptr(namelen, name, pname, params);
}

#pragma endregion

#pragma region GL_ARB_shading_language_packing

#pragma endregion

#pragma region GL_ARB_sparse_buffer

void glBufferPageCommitmentARB(GLenum target, GLintptr offset, GLsizeiptr size, GLboolean commit)
{
    glBufferPageCommitmentARB_ptr(target, offset, size, commit);
}

void glNamedBufferPageCommitmentEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit)
{
    glNamedBufferPageCommitmentEXT_ptr(buffer, offset, size, commit);
}

void glNamedBufferPageCommitmentARB(GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit)
{
    glNamedBufferPageCommitmentARB_ptr(buffer, offset, size, commit);
}

#pragma endregion

#pragma region GL_ARB_sparse_texture

void glTexPageCommitmentARB(GLenum target,
                            GLint level,
                            GLint xoffset,
                            GLint yoffset,
                            GLint zoffset,
                            GLsizei width,
                            GLsizei height,
                            GLsizei depth,
                            GLboolean commit)
{
    glTexPageCommitmentARB_ptr(target, level, xoffset, yoffset, zoffset, width, height, depth, commit);
}

#pragma endregion

#pragma region GL_ARB_sparse_texture2

#pragma endregion

#pragma region GL_ARB_sparse_texture_clamp

#pragma endregion

#pragma region GL_ARB_spirv_extensions

#pragma endregion

#pragma region GL_ARB_stencil_texturing

#pragma endregion

#pragma region GL_ARB_sync

#pragma endregion

#pragma region GL_ARB_tessellation_shader

#pragma endregion

#pragma region GL_ARB_texture_barrier

#pragma endregion

#pragma region GL_ARB_texture_border_clamp

#pragma endregion

#pragma region GL_ARB_texture_buffer_object

void glTexBufferARB(GLenum target, GLenum internalformat, GLuint buffer)
{
    glTexBufferARB_ptr(target, internalformat, buffer);
}

#pragma endregion

#pragma region GL_ARB_texture_buffer_object_rgb32

#pragma endregion

#pragma region GL_ARB_texture_buffer_range

#pragma endregion

#pragma region GL_ARB_texture_compression_bptc

#pragma endregion

#pragma region GL_ARB_texture_compression_rgtc

#pragma endregion

#pragma region GL_ARB_texture_cube_map_array

#pragma endregion

#pragma region GL_ARB_texture_filter_anisotropic

#pragma endregion

#pragma region GL_ARB_texture_filter_minmax

#pragma endregion

#pragma region GL_ARB_texture_gather

#pragma endregion

#pragma region GL_ARB_texture_mirror_clamp_to_edge

#pragma endregion

#pragma region GL_ARB_texture_mirrored_repeat

#pragma endregion

#pragma region GL_ARB_texture_multisample

#pragma endregion

#pragma region GL_ARB_texture_non_power_of_two

#pragma endregion

#pragma region GL_ARB_texture_query_levels

#pragma endregion

#pragma region GL_ARB_texture_query_lod

#pragma endregion

#pragma region GL_ARB_texture_rg

#pragma endregion

#pragma region GL_ARB_texture_rgb10_a2ui

#pragma endregion

#pragma region GL_ARB_texture_stencil8

#pragma endregion

#pragma region GL_ARB_texture_storage

#pragma endregion

#pragma region GL_ARB_texture_storage_multisample

#pragma endregion

#pragma region GL_ARB_texture_swizzle

#pragma endregion

#pragma region GL_ARB_texture_view

#pragma endregion

#pragma region GL_ARB_timer_query

#pragma endregion

#pragma region GL_ARB_transform_feedback2

#pragma endregion

#pragma region GL_ARB_transform_feedback3

#pragma endregion

#pragma region GL_ARB_transform_feedback_instanced

#pragma endregion

#pragma region GL_ARB_transform_feedback_overflow_query

#pragma endregion

#pragma region GL_ARB_uniform_buffer_object

#pragma endregion

#pragma region GL_ARB_vertex_array_bgra

#pragma endregion

#pragma region GL_ARB_vertex_array_object

#pragma endregion

#pragma region GL_ARB_vertex_attrib_64bit

#pragma endregion

#pragma region GL_ARB_vertex_attrib_binding

#pragma endregion

#pragma region GL_ARB_vertex_type_10f_11f_11f_rev

#pragma endregion

#pragma region GL_ARB_vertex_type_2_10_10_10_rev

#pragma endregion

#pragma region GL_ARB_viewport_array

void glDepthRangeArraydvNV(GLuint first, GLsizei count, const GLdouble* v)
{
    glDepthRangeArraydvNV_ptr(first, count, v);
}

void glDepthRangeIndexeddNV(GLuint index, GLdouble n, GLdouble f)
{
    glDepthRangeIndexeddNV_ptr(index, n, f);
}

#pragma endregion

#pragma region GL_EXT_EGL_image_storage

void glEGLImageTargetTexStorageEXT(GLenum target, GLeglImageOES image, const GLint* attrib_list)
{
    glEGLImageTargetTexStorageEXT_ptr(target, image, attrib_list);
}

void glEGLImageTargetTextureStorageEXT(GLuint texture, GLeglImageOES image, const GLint* attrib_list)
{
    glEGLImageTargetTextureStorageEXT_ptr(texture, image, attrib_list);
}

#pragma endregion

#pragma region GL_EXT_EGL_sync

#pragma endregion

#pragma region GL_EXT_debug_label

void glLabelObjectEXT(GLenum type, GLuint object, GLsizei length, const GLchar* label)
{
    glLabelObjectEXT_ptr(type, object, length, label);
}

void glGetObjectLabelEXT(GLenum type, GLuint object, GLsizei bufSize, GLsizei* length, GLchar* label)
{
    glGetObjectLabelEXT_ptr(type, object, bufSize, length, label);
}

#pragma endregion

#pragma region GL_EXT_debug_marker

void glInsertEventMarkerEXT(GLsizei length, const GLchar* marker)
{
    glInsertEventMarkerEXT_ptr(length, marker);
}

void glPushGroupMarkerEXT(GLsizei length, const GLchar* marker)
{
    glPushGroupMarkerEXT_ptr(length, marker);
}

void glPopGroupMarkerEXT()
{
    glPopGroupMarkerEXT_ptr();
}

#pragma endregion

#pragma region GL_EXT_direct_state_access

void glMatrixLoadfEXT(GLenum mode, const GLfloat* m)
{
    glMatrixLoadfEXT_ptr(mode, m);
}

void glMatrixLoaddEXT(GLenum mode, const GLdouble* m)
{
    glMatrixLoaddEXT_ptr(mode, m);
}

void glMatrixMultfEXT(GLenum mode, const GLfloat* m)
{
    glMatrixMultfEXT_ptr(mode, m);
}

void glMatrixMultdEXT(GLenum mode, const GLdouble* m)
{
    glMatrixMultdEXT_ptr(mode, m);
}

void glMatrixLoadIdentityEXT(GLenum mode)
{
    glMatrixLoadIdentityEXT_ptr(mode);
}

void glMatrixRotatefEXT(GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z)
{
    glMatrixRotatefEXT_ptr(mode, angle, x, y, z);
}

void glMatrixRotatedEXT(GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z)
{
    glMatrixRotatedEXT_ptr(mode, angle, x, y, z);
}

void glMatrixScalefEXT(GLenum mode, GLfloat x, GLfloat y, GLfloat z)
{
    glMatrixScalefEXT_ptr(mode, x, y, z);
}

void glMatrixScaledEXT(GLenum mode, GLdouble x, GLdouble y, GLdouble z)
{
    glMatrixScaledEXT_ptr(mode, x, y, z);
}

void glMatrixTranslatefEXT(GLenum mode, GLfloat x, GLfloat y, GLfloat z)
{
    glMatrixTranslatefEXT_ptr(mode, x, y, z);
}

void glMatrixTranslatedEXT(GLenum mode, GLdouble x, GLdouble y, GLdouble z)
{
    glMatrixTranslatedEXT_ptr(mode, x, y, z);
}

void glMatrixFrustumEXT(GLenum mode,
                        GLdouble left,
                        GLdouble right,
                        GLdouble bottom,
                        GLdouble top,
                        GLdouble zNear,
                        GLdouble zFar)
{
    glMatrixFrustumEXT_ptr(mode, left, right, bottom, top, zNear, zFar);
}

void glMatrixOrthoEXT(GLenum mode,
                      GLdouble left,
                      GLdouble right,
                      GLdouble bottom,
                      GLdouble top,
                      GLdouble zNear,
                      GLdouble zFar)
{
    glMatrixOrthoEXT_ptr(mode, left, right, bottom, top, zNear, zFar);
}

void glMatrixPopEXT(GLenum mode)
{
    glMatrixPopEXT_ptr(mode);
}

void glMatrixPushEXT(GLenum mode)
{
    glMatrixPushEXT_ptr(mode);
}

void glClientAttribDefaultEXT(GLbitfield mask)
{
    glClientAttribDefaultEXT_ptr(mask);
}

void glPushClientAttribDefaultEXT(GLbitfield mask)
{
    glPushClientAttribDefaultEXT_ptr(mask);
}

void glTextureParameterfEXT(GLuint texture, GLenum target, GLenum pname, GLfloat param)
{
    glTextureParameterfEXT_ptr(texture, target, pname, param);
}

void glTextureParameterfvEXT(GLuint texture, GLenum target, GLenum pname, const GLfloat* params)
{
    glTextureParameterfvEXT_ptr(texture, target, pname, params);
}

void glTextureParameteriEXT(GLuint texture, GLenum target, GLenum pname, GLint param)
{
    glTextureParameteriEXT_ptr(texture, target, pname, param);
}

void glTextureParameterivEXT(GLuint texture, GLenum target, GLenum pname, const GLint* params)
{
    glTextureParameterivEXT_ptr(texture, target, pname, params);
}

void glTextureImage1DEXT(GLuint texture,
                         GLenum target,
                         GLint level,
                         GLint internalformat,
                         GLsizei width,
                         GLint border,
                         GLenum format,
                         GLenum type,
                         const void* pixels)
{
    glTextureImage1DEXT_ptr(texture, target, level, internalformat, width, border, format, type, pixels);
}

void glTextureImage2DEXT(GLuint texture,
                         GLenum target,
                         GLint level,
                         GLint internalformat,
                         GLsizei width,
                         GLsizei height,
                         GLint border,
                         GLenum format,
                         GLenum type,
                         const void* pixels)
{
    glTextureImage2DEXT_ptr(texture, target, level, internalformat, width, height, border, format, type, pixels);
}

void glTextureSubImage1DEXT(GLuint texture,
                            GLenum target,
                            GLint level,
                            GLint xoffset,
                            GLsizei width,
                            GLenum format,
                            GLenum type,
                            const void* pixels)
{
    glTextureSubImage1DEXT_ptr(texture, target, level, xoffset, width, format, type, pixels);
}

void glTextureSubImage2DEXT(GLuint texture,
                            GLenum target,
                            GLint level,
                            GLint xoffset,
                            GLint yoffset,
                            GLsizei width,
                            GLsizei height,
                            GLenum format,
                            GLenum type,
                            const void* pixels)
{
    glTextureSubImage2DEXT_ptr(texture, target, level, xoffset, yoffset, width, height, format, type, pixels);
}

void glCopyTextureImage1DEXT(GLuint texture,
                             GLenum target,
                             GLint level,
                             GLenum internalformat,
                             GLint x,
                             GLint y,
                             GLsizei width,
                             GLint border)
{
    glCopyTextureImage1DEXT_ptr(texture, target, level, internalformat, x, y, width, border);
}

void glCopyTextureImage2DEXT(GLuint texture,
                             GLenum target,
                             GLint level,
                             GLenum internalformat,
                             GLint x,
                             GLint y,
                             GLsizei width,
                             GLsizei height,
                             GLint border)
{
    glCopyTextureImage2DEXT_ptr(texture, target, level, internalformat, x, y, width, height, border);
}

void glCopyTextureSubImage1DEXT(GLuint texture,
                                GLenum target,
                                GLint level,
                                GLint xoffset,
                                GLint x,
                                GLint y,
                                GLsizei width)
{
    glCopyTextureSubImage1DEXT_ptr(texture, target, level, xoffset, x, y, width);
}

void glCopyTextureSubImage2DEXT(GLuint texture,
                                GLenum target,
                                GLint level,
                                GLint xoffset,
                                GLint yoffset,
                                GLint x,
                                GLint y,
                                GLsizei width,
                                GLsizei height)
{
    glCopyTextureSubImage2DEXT_ptr(texture, target, level, xoffset, yoffset, x, y, width, height);
}

void glGetTextureImageEXT(GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, void* pixels)
{
    glGetTextureImageEXT_ptr(texture, target, level, format, type, pixels);
}

void glGetTextureParameterfvEXT(GLuint texture, GLenum target, GLenum pname, GLfloat* params)
{
    glGetTextureParameterfvEXT_ptr(texture, target, pname, params);
}

void glGetTextureParameterivEXT(GLuint texture, GLenum target, GLenum pname, GLint* params)
{
    glGetTextureParameterivEXT_ptr(texture, target, pname, params);
}

void glGetTextureLevelParameterfvEXT(GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat* params)
{
    glGetTextureLevelParameterfvEXT_ptr(texture, target, level, pname, params);
}

void glGetTextureLevelParameterivEXT(GLuint texture, GLenum target, GLint level, GLenum pname, GLint* params)
{
    glGetTextureLevelParameterivEXT_ptr(texture, target, level, pname, params);
}

void glTextureImage3DEXT(GLuint texture,
                         GLenum target,
                         GLint level,
                         GLint internalformat,
                         GLsizei width,
                         GLsizei height,
                         GLsizei depth,
                         GLint border,
                         GLenum format,
                         GLenum type,
                         const void* pixels)
{
    glTextureImage3DEXT_ptr(texture, target, level, internalformat, width, height, depth, border, format, type, pixels);
}

void glTextureSubImage3DEXT(GLuint texture,
                            GLenum target,
                            GLint level,
                            GLint xoffset,
                            GLint yoffset,
                            GLint zoffset,
                            GLsizei width,
                            GLsizei height,
                            GLsizei depth,
                            GLenum format,
                            GLenum type,
                            const void* pixels)
{
    glTextureSubImage3DEXT_ptr(texture,
                               target,
                               level,
                               xoffset,
                               yoffset,
                               zoffset,
                               width,
                               height,
                               depth,
                               format,
                               type,
                               pixels);
}

void glCopyTextureSubImage3DEXT(GLuint texture,
                                GLenum target,
                                GLint level,
                                GLint xoffset,
                                GLint yoffset,
                                GLint zoffset,
                                GLint x,
                                GLint y,
                                GLsizei width,
                                GLsizei height)
{
    glCopyTextureSubImage3DEXT_ptr(texture, target, level, xoffset, yoffset, zoffset, x, y, width, height);
}

void glBindMultiTextureEXT(GLenum texunit, GLenum target, GLuint texture)
{
    glBindMultiTextureEXT_ptr(texunit, target, texture);
}

void glMultiTexCoordPointerEXT(GLenum texunit, GLint size, GLenum type, GLsizei stride, const void* pointer)
{
    glMultiTexCoordPointerEXT_ptr(texunit, size, type, stride, pointer);
}

void glMultiTexEnvfEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat param)
{
    glMultiTexEnvfEXT_ptr(texunit, target, pname, param);
}

void glMultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum pname, const GLfloat* params)
{
    glMultiTexEnvfvEXT_ptr(texunit, target, pname, params);
}

void glMultiTexEnviEXT(GLenum texunit, GLenum target, GLenum pname, GLint param)
{
    glMultiTexEnviEXT_ptr(texunit, target, pname, param);
}

void glMultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum pname, const GLint* params)
{
    glMultiTexEnvivEXT_ptr(texunit, target, pname, params);
}

void glMultiTexGendEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble param)
{
    glMultiTexGendEXT_ptr(texunit, coord, pname, param);
}

void glMultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum pname, const GLdouble* params)
{
    glMultiTexGendvEXT_ptr(texunit, coord, pname, params);
}

void glMultiTexGenfEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat param)
{
    glMultiTexGenfEXT_ptr(texunit, coord, pname, param);
}

void glMultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum pname, const GLfloat* params)
{
    glMultiTexGenfvEXT_ptr(texunit, coord, pname, params);
}

void glMultiTexGeniEXT(GLenum texunit, GLenum coord, GLenum pname, GLint param)
{
    glMultiTexGeniEXT_ptr(texunit, coord, pname, param);
}

void glMultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum pname, const GLint* params)
{
    glMultiTexGenivEXT_ptr(texunit, coord, pname, params);
}

void glGetMultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat* params)
{
    glGetMultiTexEnvfvEXT_ptr(texunit, target, pname, params);
}

void glGetMultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum pname, GLint* params)
{
    glGetMultiTexEnvivEXT_ptr(texunit, target, pname, params);
}

void glGetMultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble* params)
{
    glGetMultiTexGendvEXT_ptr(texunit, coord, pname, params);
}

void glGetMultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat* params)
{
    glGetMultiTexGenfvEXT_ptr(texunit, coord, pname, params);
}

void glGetMultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum pname, GLint* params)
{
    glGetMultiTexGenivEXT_ptr(texunit, coord, pname, params);
}

void glMultiTexParameteriEXT(GLenum texunit, GLenum target, GLenum pname, GLint param)
{
    glMultiTexParameteriEXT_ptr(texunit, target, pname, param);
}

void glMultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum pname, const GLint* params)
{
    glMultiTexParameterivEXT_ptr(texunit, target, pname, params);
}

void glMultiTexParameterfEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat param)
{
    glMultiTexParameterfEXT_ptr(texunit, target, pname, param);
}

void glMultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum pname, const GLfloat* params)
{
    glMultiTexParameterfvEXT_ptr(texunit, target, pname, params);
}

void glMultiTexImage1DEXT(GLenum texunit,
                          GLenum target,
                          GLint level,
                          GLint internalformat,
                          GLsizei width,
                          GLint border,
                          GLenum format,
                          GLenum type,
                          const void* pixels)
{
    glMultiTexImage1DEXT_ptr(texunit, target, level, internalformat, width, border, format, type, pixels);
}

void glMultiTexImage2DEXT(GLenum texunit,
                          GLenum target,
                          GLint level,
                          GLint internalformat,
                          GLsizei width,
                          GLsizei height,
                          GLint border,
                          GLenum format,
                          GLenum type,
                          const void* pixels)
{
    glMultiTexImage2DEXT_ptr(texunit, target, level, internalformat, width, height, border, format, type, pixels);
}

void glMultiTexSubImage1DEXT(GLenum texunit,
                             GLenum target,
                             GLint level,
                             GLint xoffset,
                             GLsizei width,
                             GLenum format,
                             GLenum type,
                             const void* pixels)
{
    glMultiTexSubImage1DEXT_ptr(texunit, target, level, xoffset, width, format, type, pixels);
}

void glMultiTexSubImage2DEXT(GLenum texunit,
                             GLenum target,
                             GLint level,
                             GLint xoffset,
                             GLint yoffset,
                             GLsizei width,
                             GLsizei height,
                             GLenum format,
                             GLenum type,
                             const void* pixels)
{
    glMultiTexSubImage2DEXT_ptr(texunit, target, level, xoffset, yoffset, width, height, format, type, pixels);
}

void glCopyMultiTexImage1DEXT(GLenum texunit,
                              GLenum target,
                              GLint level,
                              GLenum internalformat,
                              GLint x,
                              GLint y,
                              GLsizei width,
                              GLint border)
{
    glCopyMultiTexImage1DEXT_ptr(texunit, target, level, internalformat, x, y, width, border);
}

void glCopyMultiTexImage2DEXT(GLenum texunit,
                              GLenum target,
                              GLint level,
                              GLenum internalformat,
                              GLint x,
                              GLint y,
                              GLsizei width,
                              GLsizei height,
                              GLint border)
{
    glCopyMultiTexImage2DEXT_ptr(texunit, target, level, internalformat, x, y, width, height, border);
}

void glCopyMultiTexSubImage1DEXT(GLenum texunit,
                                 GLenum target,
                                 GLint level,
                                 GLint xoffset,
                                 GLint x,
                                 GLint y,
                                 GLsizei width)
{
    glCopyMultiTexSubImage1DEXT_ptr(texunit, target, level, xoffset, x, y, width);
}

void glCopyMultiTexSubImage2DEXT(GLenum texunit,
                                 GLenum target,
                                 GLint level,
                                 GLint xoffset,
                                 GLint yoffset,
                                 GLint x,
                                 GLint y,
                                 GLsizei width,
                                 GLsizei height)
{
    glCopyMultiTexSubImage2DEXT_ptr(texunit, target, level, xoffset, yoffset, x, y, width, height);
}

void glGetMultiTexImageEXT(GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, void* pixels)
{
    glGetMultiTexImageEXT_ptr(texunit, target, level, format, type, pixels);
}

void glGetMultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat* params)
{
    glGetMultiTexParameterfvEXT_ptr(texunit, target, pname, params);
}

void glGetMultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum pname, GLint* params)
{
    glGetMultiTexParameterivEXT_ptr(texunit, target, pname, params);
}

void glGetMultiTexLevelParameterfvEXT(GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat* params)
{
    glGetMultiTexLevelParameterfvEXT_ptr(texunit, target, level, pname, params);
}

void glGetMultiTexLevelParameterivEXT(GLenum texunit, GLenum target, GLint level, GLenum pname, GLint* params)
{
    glGetMultiTexLevelParameterivEXT_ptr(texunit, target, level, pname, params);
}

void glMultiTexImage3DEXT(GLenum texunit,
                          GLenum target,
                          GLint level,
                          GLint internalformat,
                          GLsizei width,
                          GLsizei height,
                          GLsizei depth,
                          GLint border,
                          GLenum format,
                          GLenum type,
                          const void* pixels)
{
    glMultiTexImage3DEXT_ptr(texunit, target, level, internalformat, width, height, depth, border, format, type, pixels);
}

void glMultiTexSubImage3DEXT(GLenum texunit,
                             GLenum target,
                             GLint level,
                             GLint xoffset,
                             GLint yoffset,
                             GLint zoffset,
                             GLsizei width,
                             GLsizei height,
                             GLsizei depth,
                             GLenum format,
                             GLenum type,
                             const void* pixels)
{
    glMultiTexSubImage3DEXT_ptr(texunit,
                                target,
                                level,
                                xoffset,
                                yoffset,
                                zoffset,
                                width,
                                height,
                                depth,
                                format,
                                type,
                                pixels);
}

void glCopyMultiTexSubImage3DEXT(GLenum texunit,
                                 GLenum target,
                                 GLint level,
                                 GLint xoffset,
                                 GLint yoffset,
                                 GLint zoffset,
                                 GLint x,
                                 GLint y,
                                 GLsizei width,
                                 GLsizei height)
{
    glCopyMultiTexSubImage3DEXT_ptr(texunit, target, level, xoffset, yoffset, zoffset, x, y, width, height);
}

void glEnableClientStateIndexedEXT(GLenum array, GLuint index)
{
    glEnableClientStateIndexedEXT_ptr(array, index);
}

void glDisableClientStateIndexedEXT(GLenum array, GLuint index)
{
    glDisableClientStateIndexedEXT_ptr(array, index);
}

void glGetFloatIndexedvEXT(GLenum target, GLuint index, GLfloat* data)
{
    glGetFloatIndexedvEXT_ptr(target, index, data);
}

void glGetDoubleIndexedvEXT(GLenum target, GLuint index, GLdouble* data)
{
    glGetDoubleIndexedvEXT_ptr(target, index, data);
}

void glGetPointerIndexedvEXT(GLenum target, GLuint index, void** data)
{
    glGetPointerIndexedvEXT_ptr(target, index, data);
}

void glEnableIndexedEXT(GLenum target, GLuint index)
{
    glEnableIndexedEXT_ptr(target, index);
}

void glDisableIndexedEXT(GLenum target, GLuint index)
{
    glDisableIndexedEXT_ptr(target, index);
}

GLboolean glIsEnabledIndexedEXT(GLenum target, GLuint index)
{
    return glIsEnabledIndexedEXT_ptr(target, index);
}

void glGetIntegerIndexedvEXT(GLenum target, GLuint index, GLint* data)
{
    glGetIntegerIndexedvEXT_ptr(target, index, data);
}

void glGetBooleanIndexedvEXT(GLenum target, GLuint index, GLboolean* data)
{
    glGetBooleanIndexedvEXT_ptr(target, index, data);
}

void glCompressedTextureImage3DEXT(GLuint texture,
                                   GLenum target,
                                   GLint level,
                                   GLenum internalformat,
                                   GLsizei width,
                                   GLsizei height,
                                   GLsizei depth,
                                   GLint border,
                                   GLsizei imageSize,
                                   const void* bits)
{
    glCompressedTextureImage3DEXT_ptr(texture,
                                      target,
                                      level,
                                      internalformat,
                                      width,
                                      height,
                                      depth,
                                      border,
                                      imageSize,
                                      bits);
}

void glCompressedTextureImage2DEXT(GLuint texture,
                                   GLenum target,
                                   GLint level,
                                   GLenum internalformat,
                                   GLsizei width,
                                   GLsizei height,
                                   GLint border,
                                   GLsizei imageSize,
                                   const void* bits)
{
    glCompressedTextureImage2DEXT_ptr(texture, target, level, internalformat, width, height, border, imageSize, bits);
}

void glCompressedTextureImage1DEXT(GLuint texture,
                                   GLenum target,
                                   GLint level,
                                   GLenum internalformat,
                                   GLsizei width,
                                   GLint border,
                                   GLsizei imageSize,
                                   const void* bits)
{
    glCompressedTextureImage1DEXT_ptr(texture, target, level, internalformat, width, border, imageSize, bits);
}

void glCompressedTextureSubImage3DEXT(GLuint texture,
                                      GLenum target,
                                      GLint level,
                                      GLint xoffset,
                                      GLint yoffset,
                                      GLint zoffset,
                                      GLsizei width,
                                      GLsizei height,
                                      GLsizei depth,
                                      GLenum format,
                                      GLsizei imageSize,
                                      const void* bits)
{
    glCompressedTextureSubImage3DEXT_ptr(texture,
                                         target,
                                         level,
                                         xoffset,
                                         yoffset,
                                         zoffset,
                                         width,
                                         height,
                                         depth,
                                         format,
                                         imageSize,
                                         bits);
}

void glCompressedTextureSubImage2DEXT(GLuint texture,
                                      GLenum target,
                                      GLint level,
                                      GLint xoffset,
                                      GLint yoffset,
                                      GLsizei width,
                                      GLsizei height,
                                      GLenum format,
                                      GLsizei imageSize,
                                      const void* bits)
{
    glCompressedTextureSubImage2DEXT_ptr(texture,
                                         target,
                                         level,
                                         xoffset,
                                         yoffset,
                                         width,
                                         height,
                                         format,
                                         imageSize,
                                         bits);
}

void glCompressedTextureSubImage1DEXT(GLuint texture,
                                      GLenum target,
                                      GLint level,
                                      GLint xoffset,
                                      GLsizei width,
                                      GLenum format,
                                      GLsizei imageSize,
                                      const void* bits)
{
    glCompressedTextureSubImage1DEXT_ptr(texture, target, level, xoffset, width, format, imageSize, bits);
}

void glGetCompressedTextureImageEXT(GLuint texture, GLenum target, GLint lod, void* img)
{
    glGetCompressedTextureImageEXT_ptr(texture, target, lod, img);
}

void glCompressedMultiTexImage3DEXT(GLenum texunit,
                                    GLenum target,
                                    GLint level,
                                    GLenum internalformat,
                                    GLsizei width,
                                    GLsizei height,
                                    GLsizei depth,
                                    GLint border,
                                    GLsizei imageSize,
                                    const void* bits)
{
    glCompressedMultiTexImage3DEXT_ptr(texunit,
                                       target,
                                       level,
                                       internalformat,
                                       width,
                                       height,
                                       depth,
                                       border,
                                       imageSize,
                                       bits);
}

void glCompressedMultiTexImage2DEXT(GLenum texunit,
                                    GLenum target,
                                    GLint level,
                                    GLenum internalformat,
                                    GLsizei width,
                                    GLsizei height,
                                    GLint border,
                                    GLsizei imageSize,
                                    const void* bits)
{
    glCompressedMultiTexImage2DEXT_ptr(texunit, target, level, internalformat, width, height, border, imageSize, bits);
}

void glCompressedMultiTexImage1DEXT(GLenum texunit,
                                    GLenum target,
                                    GLint level,
                                    GLenum internalformat,
                                    GLsizei width,
                                    GLint border,
                                    GLsizei imageSize,
                                    const void* bits)
{
    glCompressedMultiTexImage1DEXT_ptr(texunit, target, level, internalformat, width, border, imageSize, bits);
}

void glCompressedMultiTexSubImage3DEXT(GLenum texunit,
                                       GLenum target,
                                       GLint level,
                                       GLint xoffset,
                                       GLint yoffset,
                                       GLint zoffset,
                                       GLsizei width,
                                       GLsizei height,
                                       GLsizei depth,
                                       GLenum format,
                                       GLsizei imageSize,
                                       const void* bits)
{
    glCompressedMultiTexSubImage3DEXT_ptr(texunit,
                                          target,
                                          level,
                                          xoffset,
                                          yoffset,
                                          zoffset,
                                          width,
                                          height,
                                          depth,
                                          format,
                                          imageSize,
                                          bits);
}

void glCompressedMultiTexSubImage2DEXT(GLenum texunit,
                                       GLenum target,
                                       GLint level,
                                       GLint xoffset,
                                       GLint yoffset,
                                       GLsizei width,
                                       GLsizei height,
                                       GLenum format,
                                       GLsizei imageSize,
                                       const void* bits)
{
    glCompressedMultiTexSubImage2DEXT_ptr(texunit,
                                          target,
                                          level,
                                          xoffset,
                                          yoffset,
                                          width,
                                          height,
                                          format,
                                          imageSize,
                                          bits);
}

void glCompressedMultiTexSubImage1DEXT(GLenum texunit,
                                       GLenum target,
                                       GLint level,
                                       GLint xoffset,
                                       GLsizei width,
                                       GLenum format,
                                       GLsizei imageSize,
                                       const void* bits)
{
    glCompressedMultiTexSubImage1DEXT_ptr(texunit, target, level, xoffset, width, format, imageSize, bits);
}

void glGetCompressedMultiTexImageEXT(GLenum texunit, GLenum target, GLint lod, void* img)
{
    glGetCompressedMultiTexImageEXT_ptr(texunit, target, lod, img);
}

void glMatrixLoadTransposefEXT(GLenum mode, const GLfloat* m)
{
    glMatrixLoadTransposefEXT_ptr(mode, m);
}

void glMatrixLoadTransposedEXT(GLenum mode, const GLdouble* m)
{
    glMatrixLoadTransposedEXT_ptr(mode, m);
}

void glMatrixMultTransposefEXT(GLenum mode, const GLfloat* m)
{
    glMatrixMultTransposefEXT_ptr(mode, m);
}

void glMatrixMultTransposedEXT(GLenum mode, const GLdouble* m)
{
    glMatrixMultTransposedEXT_ptr(mode, m);
}

void glNamedBufferDataEXT(GLuint buffer, GLsizeiptr size, const void* data, GLenum usage)
{
    glNamedBufferDataEXT_ptr(buffer, size, data, usage);
}

void glNamedBufferSubDataEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, const void* data)
{
    glNamedBufferSubDataEXT_ptr(buffer, offset, size, data);
}

void* glMapNamedBufferEXT(GLuint buffer, GLenum access)
{
    return glMapNamedBufferEXT_ptr(buffer, access);
}

GLboolean glUnmapNamedBufferEXT(GLuint buffer)
{
    return glUnmapNamedBufferEXT_ptr(buffer);
}

void glGetNamedBufferParameterivEXT(GLuint buffer, GLenum pname, GLint* params)
{
    glGetNamedBufferParameterivEXT_ptr(buffer, pname, params);
}

void glGetNamedBufferPointervEXT(GLuint buffer, GLenum pname, void** params)
{
    glGetNamedBufferPointervEXT_ptr(buffer, pname, params);
}

void glGetNamedBufferSubDataEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, void* data)
{
    glGetNamedBufferSubDataEXT_ptr(buffer, offset, size, data);
}

void glProgramUniform1fEXT(GLuint program, GLint location, GLfloat v0)
{
    glProgramUniform1fEXT_ptr(program, location, v0);
}

void glProgramUniform2fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1)
{
    glProgramUniform2fEXT_ptr(program, location, v0, v1);
}

void glProgramUniform3fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2)
{
    glProgramUniform3fEXT_ptr(program, location, v0, v1, v2);
}

void glProgramUniform4fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)
{
    glProgramUniform4fEXT_ptr(program, location, v0, v1, v2, v3);
}

void glProgramUniform1iEXT(GLuint program, GLint location, GLint v0)
{
    glProgramUniform1iEXT_ptr(program, location, v0);
}

void glProgramUniform2iEXT(GLuint program, GLint location, GLint v0, GLint v1)
{
    glProgramUniform2iEXT_ptr(program, location, v0, v1);
}

void glProgramUniform3iEXT(GLuint program, GLint location, GLint v0, GLint v1, GLint v2)
{
    glProgramUniform3iEXT_ptr(program, location, v0, v1, v2);
}

void glProgramUniform4iEXT(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3)
{
    glProgramUniform4iEXT_ptr(program, location, v0, v1, v2, v3);
}

void glProgramUniform1fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat* value)
{
    glProgramUniform1fvEXT_ptr(program, location, count, value);
}

void glProgramUniform2fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat* value)
{
    glProgramUniform2fvEXT_ptr(program, location, count, value);
}

void glProgramUniform3fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat* value)
{
    glProgramUniform3fvEXT_ptr(program, location, count, value);
}

void glProgramUniform4fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat* value)
{
    glProgramUniform4fvEXT_ptr(program, location, count, value);
}

void glProgramUniform1ivEXT(GLuint program, GLint location, GLsizei count, const GLint* value)
{
    glProgramUniform1ivEXT_ptr(program, location, count, value);
}

void glProgramUniform2ivEXT(GLuint program, GLint location, GLsizei count, const GLint* value)
{
    glProgramUniform2ivEXT_ptr(program, location, count, value);
}

void glProgramUniform3ivEXT(GLuint program, GLint location, GLsizei count, const GLint* value)
{
    glProgramUniform3ivEXT_ptr(program, location, count, value);
}

void glProgramUniform4ivEXT(GLuint program, GLint location, GLsizei count, const GLint* value)
{
    glProgramUniform4ivEXT_ptr(program, location, count, value);
}

void glProgramUniformMatrix2fvEXT(GLuint program,
                                  GLint location,
                                  GLsizei count,
                                  GLboolean transpose,
                                  const GLfloat* value)
{
    glProgramUniformMatrix2fvEXT_ptr(program, location, count, transpose, value);
}

void glProgramUniformMatrix3fvEXT(GLuint program,
                                  GLint location,
                                  GLsizei count,
                                  GLboolean transpose,
                                  const GLfloat* value)
{
    glProgramUniformMatrix3fvEXT_ptr(program, location, count, transpose, value);
}

void glProgramUniformMatrix4fvEXT(GLuint program,
                                  GLint location,
                                  GLsizei count,
                                  GLboolean transpose,
                                  const GLfloat* value)
{
    glProgramUniformMatrix4fvEXT_ptr(program, location, count, transpose, value);
}

void glProgramUniformMatrix2x3fvEXT(GLuint program,
                                    GLint location,
                                    GLsizei count,
                                    GLboolean transpose,
                                    const GLfloat* value)
{
    glProgramUniformMatrix2x3fvEXT_ptr(program, location, count, transpose, value);
}

void glProgramUniformMatrix3x2fvEXT(GLuint program,
                                    GLint location,
                                    GLsizei count,
                                    GLboolean transpose,
                                    const GLfloat* value)
{
    glProgramUniformMatrix3x2fvEXT_ptr(program, location, count, transpose, value);
}

void glProgramUniformMatrix2x4fvEXT(GLuint program,
                                    GLint location,
                                    GLsizei count,
                                    GLboolean transpose,
                                    const GLfloat* value)
{
    glProgramUniformMatrix2x4fvEXT_ptr(program, location, count, transpose, value);
}

void glProgramUniformMatrix4x2fvEXT(GLuint program,
                                    GLint location,
                                    GLsizei count,
                                    GLboolean transpose,
                                    const GLfloat* value)
{
    glProgramUniformMatrix4x2fvEXT_ptr(program, location, count, transpose, value);
}

void glProgramUniformMatrix3x4fvEXT(GLuint program,
                                    GLint location,
                                    GLsizei count,
                                    GLboolean transpose,
                                    const GLfloat* value)
{
    glProgramUniformMatrix3x4fvEXT_ptr(program, location, count, transpose, value);
}

void glProgramUniformMatrix4x3fvEXT(GLuint program,
                                    GLint location,
                                    GLsizei count,
                                    GLboolean transpose,
                                    const GLfloat* value)
{
    glProgramUniformMatrix4x3fvEXT_ptr(program, location, count, transpose, value);
}

void glTextureBufferEXT(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer)
{
    glTextureBufferEXT_ptr(texture, target, internalformat, buffer);
}

void glMultiTexBufferEXT(GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer)
{
    glMultiTexBufferEXT_ptr(texunit, target, internalformat, buffer);
}

void glTextureParameterIivEXT(GLuint texture, GLenum target, GLenum pname, const GLint* params)
{
    glTextureParameterIivEXT_ptr(texture, target, pname, params);
}

void glTextureParameterIuivEXT(GLuint texture, GLenum target, GLenum pname, const GLuint* params)
{
    glTextureParameterIuivEXT_ptr(texture, target, pname, params);
}

void glGetTextureParameterIivEXT(GLuint texture, GLenum target, GLenum pname, GLint* params)
{
    glGetTextureParameterIivEXT_ptr(texture, target, pname, params);
}

void glGetTextureParameterIuivEXT(GLuint texture, GLenum target, GLenum pname, GLuint* params)
{
    glGetTextureParameterIuivEXT_ptr(texture, target, pname, params);
}

void glMultiTexParameterIivEXT(GLenum texunit, GLenum target, GLenum pname, const GLint* params)
{
    glMultiTexParameterIivEXT_ptr(texunit, target, pname, params);
}

void glMultiTexParameterIuivEXT(GLenum texunit, GLenum target, GLenum pname, const GLuint* params)
{
    glMultiTexParameterIuivEXT_ptr(texunit, target, pname, params);
}

void glGetMultiTexParameterIivEXT(GLenum texunit, GLenum target, GLenum pname, GLint* params)
{
    glGetMultiTexParameterIivEXT_ptr(texunit, target, pname, params);
}

void glGetMultiTexParameterIuivEXT(GLenum texunit, GLenum target, GLenum pname, GLuint* params)
{
    glGetMultiTexParameterIuivEXT_ptr(texunit, target, pname, params);
}

void glProgramUniform1uiEXT(GLuint program, GLint location, GLuint v0)
{
    glProgramUniform1uiEXT_ptr(program, location, v0);
}

void glProgramUniform2uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1)
{
    glProgramUniform2uiEXT_ptr(program, location, v0, v1);
}

void glProgramUniform3uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2)
{
    glProgramUniform3uiEXT_ptr(program, location, v0, v1, v2);
}

void glProgramUniform4uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3)
{
    glProgramUniform4uiEXT_ptr(program, location, v0, v1, v2, v3);
}

void glProgramUniform1uivEXT(GLuint program, GLint location, GLsizei count, const GLuint* value)
{
    glProgramUniform1uivEXT_ptr(program, location, count, value);
}

void glProgramUniform2uivEXT(GLuint program, GLint location, GLsizei count, const GLuint* value)
{
    glProgramUniform2uivEXT_ptr(program, location, count, value);
}

void glProgramUniform3uivEXT(GLuint program, GLint location, GLsizei count, const GLuint* value)
{
    glProgramUniform3uivEXT_ptr(program, location, count, value);
}

void glProgramUniform4uivEXT(GLuint program, GLint location, GLsizei count, const GLuint* value)
{
    glProgramUniform4uivEXT_ptr(program, location, count, value);
}

void glNamedProgramLocalParameters4fvEXT(GLuint program,
                                         GLenum target,
                                         GLuint index,
                                         GLsizei count,
                                         const GLfloat* params)
{
    glNamedProgramLocalParameters4fvEXT_ptr(program, target, index, count, params);
}

void glNamedProgramLocalParameterI4iEXT(GLuint program, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w)
{
    glNamedProgramLocalParameterI4iEXT_ptr(program, target, index, x, y, z, w);
}

void glNamedProgramLocalParameterI4ivEXT(GLuint program, GLenum target, GLuint index, const GLint* params)
{
    glNamedProgramLocalParameterI4ivEXT_ptr(program, target, index, params);
}

void glNamedProgramLocalParametersI4ivEXT(GLuint program,
                                          GLenum target,
                                          GLuint index,
                                          GLsizei count,
                                          const GLint* params)
{
    glNamedProgramLocalParametersI4ivEXT_ptr(program, target, index, count, params);
}

void glNamedProgramLocalParameterI4uiEXT(GLuint program,
                                         GLenum target,
                                         GLuint index,
                                         GLuint x,
                                         GLuint y,
                                         GLuint z,
                                         GLuint w)
{
    glNamedProgramLocalParameterI4uiEXT_ptr(program, target, index, x, y, z, w);
}

void glNamedProgramLocalParameterI4uivEXT(GLuint program, GLenum target, GLuint index, const GLuint* params)
{
    glNamedProgramLocalParameterI4uivEXT_ptr(program, target, index, params);
}

void glNamedProgramLocalParametersI4uivEXT(GLuint program,
                                           GLenum target,
                                           GLuint index,
                                           GLsizei count,
                                           const GLuint* params)
{
    glNamedProgramLocalParametersI4uivEXT_ptr(program, target, index, count, params);
}

void glGetNamedProgramLocalParameterIivEXT(GLuint program, GLenum target, GLuint index, GLint* params)
{
    glGetNamedProgramLocalParameterIivEXT_ptr(program, target, index, params);
}

void glGetNamedProgramLocalParameterIuivEXT(GLuint program, GLenum target, GLuint index, GLuint* params)
{
    glGetNamedProgramLocalParameterIuivEXT_ptr(program, target, index, params);
}

void glEnableClientStateiEXT(GLenum array, GLuint index)
{
    glEnableClientStateiEXT_ptr(array, index);
}

void glDisableClientStateiEXT(GLenum array, GLuint index)
{
    glDisableClientStateiEXT_ptr(array, index);
}

void glGetFloati_vEXT(GLenum pname, GLuint index, GLfloat* params)
{
    glGetFloati_vEXT_ptr(pname, index, params);
}

void glGetDoublei_vEXT(GLenum pname, GLuint index, GLdouble* params)
{
    glGetDoublei_vEXT_ptr(pname, index, params);
}

void glGetPointeri_vEXT(GLenum pname, GLuint index, void** params)
{
    glGetPointeri_vEXT_ptr(pname, index, params);
}

void glNamedProgramStringEXT(GLuint program, GLenum target, GLenum format, GLsizei len, const void* string)
{
    glNamedProgramStringEXT_ptr(program, target, format, len, string);
}

void glNamedProgramLocalParameter4dEXT(GLuint program,
                                       GLenum target,
                                       GLuint index,
                                       GLdouble x,
                                       GLdouble y,
                                       GLdouble z,
                                       GLdouble w)
{
    glNamedProgramLocalParameter4dEXT_ptr(program, target, index, x, y, z, w);
}

void glNamedProgramLocalParameter4dvEXT(GLuint program, GLenum target, GLuint index, const GLdouble* params)
{
    glNamedProgramLocalParameter4dvEXT_ptr(program, target, index, params);
}

void glNamedProgramLocalParameter4fEXT(GLuint program,
                                       GLenum target,
                                       GLuint index,
                                       GLfloat x,
                                       GLfloat y,
                                       GLfloat z,
                                       GLfloat w)
{
    glNamedProgramLocalParameter4fEXT_ptr(program, target, index, x, y, z, w);
}

void glNamedProgramLocalParameter4fvEXT(GLuint program, GLenum target, GLuint index, const GLfloat* params)
{
    glNamedProgramLocalParameter4fvEXT_ptr(program, target, index, params);
}

void glGetNamedProgramLocalParameterdvEXT(GLuint program, GLenum target, GLuint index, GLdouble* params)
{
    glGetNamedProgramLocalParameterdvEXT_ptr(program, target, index, params);
}

void glGetNamedProgramLocalParameterfvEXT(GLuint program, GLenum target, GLuint index, GLfloat* params)
{
    glGetNamedProgramLocalParameterfvEXT_ptr(program, target, index, params);
}

void glGetNamedProgramivEXT(GLuint program, GLenum target, GLenum pname, GLint* params)
{
    glGetNamedProgramivEXT_ptr(program, target, pname, params);
}

void glGetNamedProgramStringEXT(GLuint program, GLenum target, GLenum pname, void* string)
{
    glGetNamedProgramStringEXT_ptr(program, target, pname, string);
}

void glNamedRenderbufferStorageEXT(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height)
{
    glNamedRenderbufferStorageEXT_ptr(renderbuffer, internalformat, width, height);
}

void glGetNamedRenderbufferParameterivEXT(GLuint renderbuffer, GLenum pname, GLint* params)
{
    glGetNamedRenderbufferParameterivEXT_ptr(renderbuffer, pname, params);
}

void glNamedRenderbufferStorageMultisampleEXT(GLuint renderbuffer,
                                              GLsizei samples,
                                              GLenum internalformat,
                                              GLsizei width,
                                              GLsizei height)
{
    glNamedRenderbufferStorageMultisampleEXT_ptr(renderbuffer, samples, internalformat, width, height);
}

void glNamedRenderbufferStorageMultisampleCoverageEXT(GLuint renderbuffer,
                                                      GLsizei coverageSamples,
                                                      GLsizei colorSamples,
                                                      GLenum internalformat,
                                                      GLsizei width,
                                                      GLsizei height)
{
    glNamedRenderbufferStorageMultisampleCoverageEXT_ptr(renderbuffer,
                                                         coverageSamples,
                                                         colorSamples,
                                                         internalformat,
                                                         width,
                                                         height);
}

GLenum glCheckNamedFramebufferStatusEXT(GLuint framebuffer, GLenum target)
{
    return glCheckNamedFramebufferStatusEXT_ptr(framebuffer, target);
}

void glNamedFramebufferTexture1DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
{
    glNamedFramebufferTexture1DEXT_ptr(framebuffer, attachment, textarget, texture, level);
}

void glNamedFramebufferTexture2DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
{
    glNamedFramebufferTexture2DEXT_ptr(framebuffer, attachment, textarget, texture, level);
}

void glNamedFramebufferTexture3DEXT(GLuint framebuffer,
                                    GLenum attachment,
                                    GLenum textarget,
                                    GLuint texture,
                                    GLint level,
                                    GLint zoffset)
{
    glNamedFramebufferTexture3DEXT_ptr(framebuffer, attachment, textarget, texture, level, zoffset);
}

void glNamedFramebufferRenderbufferEXT(GLuint framebuffer,
                                       GLenum attachment,
                                       GLenum renderbuffertarget,
                                       GLuint renderbuffer)
{
    glNamedFramebufferRenderbufferEXT_ptr(framebuffer, attachment, renderbuffertarget, renderbuffer);
}

void glGetNamedFramebufferAttachmentParameterivEXT(GLuint framebuffer, GLenum attachment, GLenum pname, GLint* params)
{
    glGetNamedFramebufferAttachmentParameterivEXT_ptr(framebuffer, attachment, pname, params);
}

void glGenerateTextureMipmapEXT(GLuint texture, GLenum target)
{
    glGenerateTextureMipmapEXT_ptr(texture, target);
}

void glGenerateMultiTexMipmapEXT(GLenum texunit, GLenum target)
{
    glGenerateMultiTexMipmapEXT_ptr(texunit, target);
}

void glFramebufferDrawBufferEXT(GLuint framebuffer, GLenum mode)
{
    glFramebufferDrawBufferEXT_ptr(framebuffer, mode);
}

void glFramebufferDrawBuffersEXT(GLuint framebuffer, GLsizei n, const GLenum* bufs)
{
    glFramebufferDrawBuffersEXT_ptr(framebuffer, n, bufs);
}

void glFramebufferReadBufferEXT(GLuint framebuffer, GLenum mode)
{
    glFramebufferReadBufferEXT_ptr(framebuffer, mode);
}

void glGetFramebufferParameterivEXT(GLuint framebuffer, GLenum pname, GLint* params)
{
    glGetFramebufferParameterivEXT_ptr(framebuffer, pname, params);
}

void glNamedCopyBufferSubDataEXT(GLuint readBuffer,
                                 GLuint writeBuffer,
                                 GLintptr readOffset,
                                 GLintptr writeOffset,
                                 GLsizeiptr size)
{
    glNamedCopyBufferSubDataEXT_ptr(readBuffer, writeBuffer, readOffset, writeOffset, size);
}

void glNamedFramebufferTextureEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level)
{
    glNamedFramebufferTextureEXT_ptr(framebuffer, attachment, texture, level);
}

void glNamedFramebufferTextureLayerEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer)
{
    glNamedFramebufferTextureLayerEXT_ptr(framebuffer, attachment, texture, level, layer);
}

void glNamedFramebufferTextureFaceEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face)
{
    glNamedFramebufferTextureFaceEXT_ptr(framebuffer, attachment, texture, level, face);
}

void glTextureRenderbufferEXT(GLuint texture, GLenum target, GLuint renderbuffer)
{
    glTextureRenderbufferEXT_ptr(texture, target, renderbuffer);
}

void glMultiTexRenderbufferEXT(GLenum texunit, GLenum target, GLuint renderbuffer)
{
    glMultiTexRenderbufferEXT_ptr(texunit, target, renderbuffer);
}

void glVertexArrayVertexOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset)
{
    glVertexArrayVertexOffsetEXT_ptr(vaobj, buffer, size, type, stride, offset);
}

void glVertexArrayColorOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset)
{
    glVertexArrayColorOffsetEXT_ptr(vaobj, buffer, size, type, stride, offset);
}

void glVertexArrayEdgeFlagOffsetEXT(GLuint vaobj, GLuint buffer, GLsizei stride, GLintptr offset)
{
    glVertexArrayEdgeFlagOffsetEXT_ptr(vaobj, buffer, stride, offset);
}

void glVertexArrayIndexOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset)
{
    glVertexArrayIndexOffsetEXT_ptr(vaobj, buffer, type, stride, offset);
}

void glVertexArrayNormalOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset)
{
    glVertexArrayNormalOffsetEXT_ptr(vaobj, buffer, type, stride, offset);
}

void glVertexArrayTexCoordOffsetEXT(GLuint vaobj,
                                    GLuint buffer,
                                    GLint size,
                                    GLenum type,
                                    GLsizei stride,
                                    GLintptr offset)
{
    glVertexArrayTexCoordOffsetEXT_ptr(vaobj, buffer, size, type, stride, offset);
}

void glVertexArrayMultiTexCoordOffsetEXT(GLuint vaobj,
                                         GLuint buffer,
                                         GLenum texunit,
                                         GLint size,
                                         GLenum type,
                                         GLsizei stride,
                                         GLintptr offset)
{
    glVertexArrayMultiTexCoordOffsetEXT_ptr(vaobj, buffer, texunit, size, type, stride, offset);
}

void glVertexArrayFogCoordOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset)
{
    glVertexArrayFogCoordOffsetEXT_ptr(vaobj, buffer, type, stride, offset);
}

void glVertexArraySecondaryColorOffsetEXT(GLuint vaobj,
                                          GLuint buffer,
                                          GLint size,
                                          GLenum type,
                                          GLsizei stride,
                                          GLintptr offset)
{
    glVertexArraySecondaryColorOffsetEXT_ptr(vaobj, buffer, size, type, stride, offset);
}

void glVertexArrayVertexAttribOffsetEXT(GLuint vaobj,
                                        GLuint buffer,
                                        GLuint index,
                                        GLint size,
                                        GLenum type,
                                        GLboolean normalized,
                                        GLsizei stride,
                                        GLintptr offset)
{
    glVertexArrayVertexAttribOffsetEXT_ptr(vaobj, buffer, index, size, type, normalized, stride, offset);
}

void glVertexArrayVertexAttribIOffsetEXT(GLuint vaobj,
                                         GLuint buffer,
                                         GLuint index,
                                         GLint size,
                                         GLenum type,
                                         GLsizei stride,
                                         GLintptr offset)
{
    glVertexArrayVertexAttribIOffsetEXT_ptr(vaobj, buffer, index, size, type, stride, offset);
}

void glEnableVertexArrayEXT(GLuint vaobj, GLenum array)
{
    glEnableVertexArrayEXT_ptr(vaobj, array);
}

void glDisableVertexArrayEXT(GLuint vaobj, GLenum array)
{
    glDisableVertexArrayEXT_ptr(vaobj, array);
}

void glEnableVertexArrayAttribEXT(GLuint vaobj, GLuint index)
{
    glEnableVertexArrayAttribEXT_ptr(vaobj, index);
}

void glDisableVertexArrayAttribEXT(GLuint vaobj, GLuint index)
{
    glDisableVertexArrayAttribEXT_ptr(vaobj, index);
}

void glGetVertexArrayIntegervEXT(GLuint vaobj, GLenum pname, GLint* param)
{
    glGetVertexArrayIntegervEXT_ptr(vaobj, pname, param);
}

void glGetVertexArrayPointervEXT(GLuint vaobj, GLenum pname, void** param)
{
    glGetVertexArrayPointervEXT_ptr(vaobj, pname, param);
}

void glGetVertexArrayIntegeri_vEXT(GLuint vaobj, GLuint index, GLenum pname, GLint* param)
{
    glGetVertexArrayIntegeri_vEXT_ptr(vaobj, index, pname, param);
}

void glGetVertexArrayPointeri_vEXT(GLuint vaobj, GLuint index, GLenum pname, void** param)
{
    glGetVertexArrayPointeri_vEXT_ptr(vaobj, index, pname, param);
}

void* glMapNamedBufferRangeEXT(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access)
{
    return glMapNamedBufferRangeEXT_ptr(buffer, offset, length, access);
}

void glFlushMappedNamedBufferRangeEXT(GLuint buffer, GLintptr offset, GLsizeiptr length)
{
    glFlushMappedNamedBufferRangeEXT_ptr(buffer, offset, length);
}

void glNamedBufferStorageEXT(GLuint buffer, GLsizeiptr size, const void* data, GLbitfield flags)
{
    glNamedBufferStorageEXT_ptr(buffer, size, data, flags);
}

void glClearNamedBufferDataEXT(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void* data)
{
    glClearNamedBufferDataEXT_ptr(buffer, internalformat, format, type, data);
}

void glClearNamedBufferSubDataEXT(GLuint buffer,
                                  GLenum internalformat,
                                  GLsizeiptr offset,
                                  GLsizeiptr size,
                                  GLenum format,
                                  GLenum type,
                                  const void* data)
{
    glClearNamedBufferSubDataEXT_ptr(buffer, internalformat, offset, size, format, type, data);
}

void glNamedFramebufferParameteriEXT(GLuint framebuffer, GLenum pname, GLint param)
{
    glNamedFramebufferParameteriEXT_ptr(framebuffer, pname, param);
}

void glGetNamedFramebufferParameterivEXT(GLuint framebuffer, GLenum pname, GLint* params)
{
    glGetNamedFramebufferParameterivEXT_ptr(framebuffer, pname, params);
}

void glProgramUniform1dEXT(GLuint program, GLint location, GLdouble x)
{
    glProgramUniform1dEXT_ptr(program, location, x);
}

void glProgramUniform2dEXT(GLuint program, GLint location, GLdouble x, GLdouble y)
{
    glProgramUniform2dEXT_ptr(program, location, x, y);
}

void glProgramUniform3dEXT(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z)
{
    glProgramUniform3dEXT_ptr(program, location, x, y, z);
}

void glProgramUniform4dEXT(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
    glProgramUniform4dEXT_ptr(program, location, x, y, z, w);
}

void glProgramUniform1dvEXT(GLuint program, GLint location, GLsizei count, const GLdouble* value)
{
    glProgramUniform1dvEXT_ptr(program, location, count, value);
}

void glProgramUniform2dvEXT(GLuint program, GLint location, GLsizei count, const GLdouble* value)
{
    glProgramUniform2dvEXT_ptr(program, location, count, value);
}

void glProgramUniform3dvEXT(GLuint program, GLint location, GLsizei count, const GLdouble* value)
{
    glProgramUniform3dvEXT_ptr(program, location, count, value);
}

void glProgramUniform4dvEXT(GLuint program, GLint location, GLsizei count, const GLdouble* value)
{
    glProgramUniform4dvEXT_ptr(program, location, count, value);
}

void glProgramUniformMatrix2dvEXT(GLuint program,
                                  GLint location,
                                  GLsizei count,
                                  GLboolean transpose,
                                  const GLdouble* value)
{
    glProgramUniformMatrix2dvEXT_ptr(program, location, count, transpose, value);
}

void glProgramUniformMatrix3dvEXT(GLuint program,
                                  GLint location,
                                  GLsizei count,
                                  GLboolean transpose,
                                  const GLdouble* value)
{
    glProgramUniformMatrix3dvEXT_ptr(program, location, count, transpose, value);
}

void glProgramUniformMatrix4dvEXT(GLuint program,
                                  GLint location,
                                  GLsizei count,
                                  GLboolean transpose,
                                  const GLdouble* value)
{
    glProgramUniformMatrix4dvEXT_ptr(program, location, count, transpose, value);
}

void glProgramUniformMatrix2x3dvEXT(GLuint program,
                                    GLint location,
                                    GLsizei count,
                                    GLboolean transpose,
                                    const GLdouble* value)
{
    glProgramUniformMatrix2x3dvEXT_ptr(program, location, count, transpose, value);
}

void glProgramUniformMatrix2x4dvEXT(GLuint program,
                                    GLint location,
                                    GLsizei count,
                                    GLboolean transpose,
                                    const GLdouble* value)
{
    glProgramUniformMatrix2x4dvEXT_ptr(program, location, count, transpose, value);
}

void glProgramUniformMatrix3x2dvEXT(GLuint program,
                                    GLint location,
                                    GLsizei count,
                                    GLboolean transpose,
                                    const GLdouble* value)
{
    glProgramUniformMatrix3x2dvEXT_ptr(program, location, count, transpose, value);
}

void glProgramUniformMatrix3x4dvEXT(GLuint program,
                                    GLint location,
                                    GLsizei count,
                                    GLboolean transpose,
                                    const GLdouble* value)
{
    glProgramUniformMatrix3x4dvEXT_ptr(program, location, count, transpose, value);
}

void glProgramUniformMatrix4x2dvEXT(GLuint program,
                                    GLint location,
                                    GLsizei count,
                                    GLboolean transpose,
                                    const GLdouble* value)
{
    glProgramUniformMatrix4x2dvEXT_ptr(program, location, count, transpose, value);
}

void glProgramUniformMatrix4x3dvEXT(GLuint program,
                                    GLint location,
                                    GLsizei count,
                                    GLboolean transpose,
                                    const GLdouble* value)
{
    glProgramUniformMatrix4x3dvEXT_ptr(program, location, count, transpose, value);
}

void glTextureBufferRangeEXT(GLuint texture,
                             GLenum target,
                             GLenum internalformat,
                             GLuint buffer,
                             GLintptr offset,
                             GLsizeiptr size)
{
    glTextureBufferRangeEXT_ptr(texture, target, internalformat, buffer, offset, size);
}

void glTextureStorage1DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width)
{
    glTextureStorage1DEXT_ptr(texture, target, levels, internalformat, width);
}

void glTextureStorage2DEXT(GLuint texture,
                           GLenum target,
                           GLsizei levels,
                           GLenum internalformat,
                           GLsizei width,
                           GLsizei height)
{
    glTextureStorage2DEXT_ptr(texture, target, levels, internalformat, width, height);
}

void glTextureStorage3DEXT(GLuint texture,
                           GLenum target,
                           GLsizei levels,
                           GLenum internalformat,
                           GLsizei width,
                           GLsizei height,
                           GLsizei depth)
{
    glTextureStorage3DEXT_ptr(texture, target, levels, internalformat, width, height, depth);
}

void glTextureStorage2DMultisampleEXT(GLuint texture,
                                      GLenum target,
                                      GLsizei samples,
                                      GLenum internalformat,
                                      GLsizei width,
                                      GLsizei height,
                                      GLboolean fixedsamplelocations)
{
    glTextureStorage2DMultisampleEXT_ptr(texture, target, samples, internalformat, width, height, fixedsamplelocations);
}

void glTextureStorage3DMultisampleEXT(GLuint texture,
                                      GLenum target,
                                      GLsizei samples,
                                      GLenum internalformat,
                                      GLsizei width,
                                      GLsizei height,
                                      GLsizei depth,
                                      GLboolean fixedsamplelocations)
{
    glTextureStorage3DMultisampleEXT_ptr(texture,
                                         target,
                                         samples,
                                         internalformat,
                                         width,
                                         height,
                                         depth,
                                         fixedsamplelocations);
}

void glVertexArrayBindVertexBufferEXT(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride)
{
    glVertexArrayBindVertexBufferEXT_ptr(vaobj, bindingindex, buffer, offset, stride);
}

void glVertexArrayVertexAttribFormatEXT(GLuint vaobj,
                                        GLuint attribindex,
                                        GLint size,
                                        GLenum type,
                                        GLboolean normalized,
                                        GLuint relativeoffset)
{
    glVertexArrayVertexAttribFormatEXT_ptr(vaobj, attribindex, size, type, normalized, relativeoffset);
}

void glVertexArrayVertexAttribIFormatEXT(GLuint vaobj,
                                         GLuint attribindex,
                                         GLint size,
                                         GLenum type,
                                         GLuint relativeoffset)
{
    glVertexArrayVertexAttribIFormatEXT_ptr(vaobj, attribindex, size, type, relativeoffset);
}

void glVertexArrayVertexAttribLFormatEXT(GLuint vaobj,
                                         GLuint attribindex,
                                         GLint size,
                                         GLenum type,
                                         GLuint relativeoffset)
{
    glVertexArrayVertexAttribLFormatEXT_ptr(vaobj, attribindex, size, type, relativeoffset);
}

void glVertexArrayVertexAttribBindingEXT(GLuint vaobj, GLuint attribindex, GLuint bindingindex)
{
    glVertexArrayVertexAttribBindingEXT_ptr(vaobj, attribindex, bindingindex);
}

void glVertexArrayVertexBindingDivisorEXT(GLuint vaobj, GLuint bindingindex, GLuint divisor)
{
    glVertexArrayVertexBindingDivisorEXT_ptr(vaobj, bindingindex, divisor);
}

void glVertexArrayVertexAttribLOffsetEXT(GLuint vaobj,
                                         GLuint buffer,
                                         GLuint index,
                                         GLint size,
                                         GLenum type,
                                         GLsizei stride,
                                         GLintptr offset)
{
    glVertexArrayVertexAttribLOffsetEXT_ptr(vaobj, buffer, index, size, type, stride, offset);
}

void glTexturePageCommitmentEXT(GLuint texture,
                                GLint level,
                                GLint xoffset,
                                GLint yoffset,
                                GLint zoffset,
                                GLsizei width,
                                GLsizei height,
                                GLsizei depth,
                                GLboolean commit)
{
    glTexturePageCommitmentEXT_ptr(texture, level, xoffset, yoffset, zoffset, width, height, depth, commit);
}

void glVertexArrayVertexAttribDivisorEXT(GLuint vaobj, GLuint index, GLuint divisor)
{
    glVertexArrayVertexAttribDivisorEXT_ptr(vaobj, index, divisor);
}

#pragma endregion

#pragma region GL_EXT_draw_instanced

void glDrawArraysInstancedEXT(GLenum mode, GLint start, GLsizei count, GLsizei primcount)
{
    glDrawArraysInstancedEXT_ptr(mode, start, count, primcount);
}

void glDrawElementsInstancedEXT(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei primcount)
{
    glDrawElementsInstancedEXT_ptr(mode, count, type, indices, primcount);
}

#pragma endregion

#pragma region GL_EXT_multiview_tessellation_geometry_shader

#pragma endregion

#pragma region GL_EXT_multiview_texture_multisample

#pragma endregion

#pragma region GL_EXT_multiview_timer_query

#pragma endregion

#pragma region GL_EXT_polygon_offset_clamp

void glPolygonOffsetClampEXT(GLfloat factor, GLfloat units, GLfloat clamp)
{
    glPolygonOffsetClampEXT_ptr(factor, units, clamp);
}

#pragma endregion

#pragma region GL_EXT_post_depth_coverage

#pragma endregion

#pragma region GL_EXT_raster_multisample

void glRasterSamplesEXT(GLuint samples, GLboolean fixedsamplelocations)
{
    glRasterSamplesEXT_ptr(samples, fixedsamplelocations);
}

#pragma endregion

#pragma region GL_EXT_separate_shader_objects

void glUseShaderProgramEXT(GLenum type, GLuint program)
{
    glUseShaderProgramEXT_ptr(type, program);
}

void glActiveProgramEXT(GLuint program)
{
    glActiveProgramEXT_ptr(program);
}

GLuint glCreateShaderProgramEXT(GLenum type, const GLchar* string)
{
    return glCreateShaderProgramEXT_ptr(type, string);
}

void glActiveShaderProgramEXT(GLuint pipeline, GLuint program)
{
    glActiveShaderProgramEXT_ptr(pipeline, program);
}

void glBindProgramPipelineEXT(GLuint pipeline)
{
    glBindProgramPipelineEXT_ptr(pipeline);
}

GLuint glCreateShaderProgramvEXT(GLenum type, GLsizei count, const GLchar** strings)
{
    return glCreateShaderProgramvEXT_ptr(type, count, strings);
}

void glDeleteProgramPipelinesEXT(GLsizei n, const GLuint* pipelines)
{
    glDeleteProgramPipelinesEXT_ptr(n, pipelines);
}

void glGenProgramPipelinesEXT(GLsizei n, GLuint* pipelines)
{
    glGenProgramPipelinesEXT_ptr(n, pipelines);
}

void glGetProgramPipelineInfoLogEXT(GLuint pipeline, GLsizei bufSize, GLsizei* length, GLchar* infoLog)
{
    glGetProgramPipelineInfoLogEXT_ptr(pipeline, bufSize, length, infoLog);
}

void glGetProgramPipelineivEXT(GLuint pipeline, GLenum pname, GLint* params)
{
    glGetProgramPipelineivEXT_ptr(pipeline, pname, params);
}

GLboolean glIsProgramPipelineEXT(GLuint pipeline)
{
    return glIsProgramPipelineEXT_ptr(pipeline);
}

void glProgramParameteriEXT(GLuint program, GLenum pname, GLint value)
{
    glProgramParameteriEXT_ptr(program, pname, value);
}

void glUseProgramStagesEXT(GLuint pipeline, GLbitfield stages, GLuint program)
{
    glUseProgramStagesEXT_ptr(pipeline, stages, program);
}

void glValidateProgramPipelineEXT(GLuint pipeline)
{
    glValidateProgramPipelineEXT_ptr(pipeline);
}

#pragma endregion

#pragma region GL_EXT_shader_framebuffer_fetch

#pragma endregion

#pragma region GL_EXT_shader_framebuffer_fetch_non_coherent

void glFramebufferFetchBarrierEXT()
{
    glFramebufferFetchBarrierEXT_ptr();
}

#pragma endregion

#pragma region GL_EXT_shader_integer_mix

#pragma endregion

#pragma region GL_EXT_texture_compression_s3tc

#pragma endregion

#pragma region GL_EXT_texture_filter_minmax

#pragma endregion

#pragma region GL_EXT_texture_sRGB_R8

#pragma endregion

#pragma region GL_EXT_texture_sRGB_decode

#pragma endregion

#pragma region GL_EXT_window_rectangles

void glWindowRectanglesEXT(GLenum mode, GLsizei count, const GLint* box)
{
    glWindowRectanglesEXT_ptr(mode, count, box);
}

#pragma endregion

#pragma region GL_INTEL_conservative_rasterization

#pragma endregion

#pragma region GL_INTEL_framebuffer_CMAA

void glApplyFramebufferAttachmentCMAAINTEL()
{
    glApplyFramebufferAttachmentCMAAINTEL_ptr();
}

#pragma endregion

#pragma region GL_INTEL_blackhole_render

#pragma endregion

#pragma region GL_INTEL_performance_query

void glBeginPerfQueryINTEL(GLuint queryHandle)
{
    glBeginPerfQueryINTEL_ptr(queryHandle);
}

void glCreatePerfQueryINTEL(GLuint queryId, GLuint* queryHandle)
{
    glCreatePerfQueryINTEL_ptr(queryId, queryHandle);
}

void glDeletePerfQueryINTEL(GLuint queryHandle)
{
    glDeletePerfQueryINTEL_ptr(queryHandle);
}

void glEndPerfQueryINTEL(GLuint queryHandle)
{
    glEndPerfQueryINTEL_ptr(queryHandle);
}

void glGetFirstPerfQueryIdINTEL(GLuint* queryId)
{
    glGetFirstPerfQueryIdINTEL_ptr(queryId);
}

void glGetNextPerfQueryIdINTEL(GLuint queryId, GLuint* nextQueryId)
{
    glGetNextPerfQueryIdINTEL_ptr(queryId, nextQueryId);
}

void glGetPerfCounterInfoINTEL(GLuint queryId,
                               GLuint counterId,
                               GLuint counterNameLength,
                               GLchar* counterName,
                               GLuint counterDescLength,
                               GLchar* counterDesc,
                               GLuint* counterOffset,
                               GLuint* counterDataSize,
                               GLuint* counterTypeEnum,
                               GLuint* counterDataTypeEnum,
                               GLuint64* rawCounterMaxValue)
{
    glGetPerfCounterInfoINTEL_ptr(queryId,
                                  counterId,
                                  counterNameLength,
                                  counterName,
                                  counterDescLength,
                                  counterDesc,
                                  counterOffset,
                                  counterDataSize,
                                  counterTypeEnum,
                                  counterDataTypeEnum,
                                  rawCounterMaxValue);
}

void glGetPerfQueryDataINTEL(GLuint queryHandle, GLuint flags, GLsizei dataSize, void* data, GLuint* bytesWritten)
{
    glGetPerfQueryDataINTEL_ptr(queryHandle, flags, dataSize, data, bytesWritten);
}

void glGetPerfQueryIdByNameINTEL(GLchar* queryName, GLuint* queryId)
{
    glGetPerfQueryIdByNameINTEL_ptr(queryName, queryId);
}

void glGetPerfQueryInfoINTEL(GLuint queryId,
                             GLuint queryNameLength,
                             GLchar* queryName,
                             GLuint* dataSize,
                             GLuint* noCounters,
                             GLuint* noInstances,
                             GLuint* capsMask)
{
    glGetPerfQueryInfoINTEL_ptr(queryId, queryNameLength, queryName, dataSize, noCounters, noInstances, capsMask);
}

#pragma endregion

#pragma region GL_KHR_blend_equation_advanced

void glBlendBarrierKHR()
{
    glBlendBarrierKHR_ptr();
}

#pragma endregion

#pragma region GL_KHR_blend_equation_advanced_coherent

#pragma endregion

#pragma region GL_KHR_context_flush_control

#pragma endregion

#pragma region GL_KHR_debug

void glDebugMessageControlKHR(GLenum source,
                              GLenum type,
                              GLenum severity,
                              GLsizei count,
                              const GLuint* ids,
                              GLboolean enabled)
{
    glDebugMessageControlKHR_ptr(source, type, severity, count, ids, enabled);
}

void glDebugMessageInsertKHR(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf)
{
    glDebugMessageInsertKHR_ptr(source, type, id, severity, length, buf);
}

void glDebugMessageCallbackKHR(GLDEBUGPROCKHR callback, const void* userParam)
{
    glDebugMessageCallbackKHR_ptr(callback, userParam);
}

GLuint glGetDebugMessageLogKHR(GLuint count,
                               GLsizei bufSize,
                               GLenum* sources,
                               GLenum* types,
                               GLuint* ids,
                               GLenum* severities,
                               GLsizei* lengths,
                               GLchar* messageLog)
{
    return glGetDebugMessageLogKHR_ptr(count, bufSize, sources, types, ids, severities, lengths, messageLog);
}

void glPushDebugGroupKHR(GLenum source, GLuint id, GLsizei length, const GLchar* message)
{
    glPushDebugGroupKHR_ptr(source, id, length, message);
}

void glPopDebugGroupKHR()
{
    glPopDebugGroupKHR_ptr();
}

void glObjectLabelKHR(GLenum identifier, GLuint name, GLsizei length, const GLchar* label)
{
    glObjectLabelKHR_ptr(identifier, name, length, label);
}

void glGetObjectLabelKHR(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei* length, GLchar* label)
{
    glGetObjectLabelKHR_ptr(identifier, name, bufSize, length, label);
}

void glObjectPtrLabelKHR(const void* ptr, GLsizei length, const GLchar* label)
{
    glObjectPtrLabelKHR_ptr(ptr, length, label);
}

void glGetObjectPtrLabelKHR(const void* ptr, GLsizei bufSize, GLsizei* length, GLchar* label)
{
    glGetObjectPtrLabelKHR_ptr(ptr, bufSize, length, label);
}

void glGetPointervKHR(GLenum pname, void** params)
{
    glGetPointervKHR_ptr(pname, params);
}

#pragma endregion

#pragma region GL_KHR_no_error

#pragma endregion

#pragma region GL_KHR_robust_buffer_access_behavior

#pragma endregion

#pragma region GL_KHR_robustness

GLenum glGetGraphicsResetStatusKHR()
{
    return glGetGraphicsResetStatusKHR_ptr();
}

void glReadnPixelsKHR(GLint x,
                      GLint y,
                      GLsizei width,
                      GLsizei height,
                      GLenum format,
                      GLenum type,
                      GLsizei bufSize,
                      void* data)
{
    glReadnPixelsKHR_ptr(x, y, width, height, format, type, bufSize, data);
}

void glGetnUniformfvKHR(GLuint program, GLint location, GLsizei bufSize, GLfloat* params)
{
    glGetnUniformfvKHR_ptr(program, location, bufSize, params);
}

void glGetnUniformivKHR(GLuint program, GLint location, GLsizei bufSize, GLint* params)
{
    glGetnUniformivKHR_ptr(program, location, bufSize, params);
}

void glGetnUniformuivKHR(GLuint program, GLint location, GLsizei bufSize, GLuint* params)
{
    glGetnUniformuivKHR_ptr(program, location, bufSize, params);
}

#pragma endregion

#pragma region GL_KHR_shader_subgroup

#pragma endregion

#pragma region GL_KHR_texture_compression_astc_hdr

#pragma endregion

#pragma region GL_KHR_texture_compression_astc_ldr

#pragma endregion

#pragma region GL_KHR_texture_compression_astc_sliced_3d

#pragma endregion

#pragma region GL_KHR_parallel_shader_compile

void glMaxShaderCompilerThreadsKHR(GLuint count)
{
    glMaxShaderCompilerThreadsKHR_ptr(count);
}

#pragma endregion

#pragma region GL_MESA_framebuffer_flip_y

void glFramebufferParameteriMESA(GLenum target, GLenum pname, GLint param)
{
    glFramebufferParameteriMESA_ptr(target, pname, param);
}

void glGetFramebufferParameterivMESA(GLenum target, GLenum pname, GLint* params)
{
    glGetFramebufferParameterivMESA_ptr(target, pname, params);
}

#pragma endregion

#pragma region GL_NV_bindless_multi_draw_indirect

void glMultiDrawArraysIndirectBindlessNV(GLenum mode,
                                         const void* indirect,
                                         GLsizei drawCount,
                                         GLsizei stride,
                                         GLint vertexBufferCount)
{
    glMultiDrawArraysIndirectBindlessNV_ptr(mode, indirect, drawCount, stride, vertexBufferCount);
}

void glMultiDrawElementsIndirectBindlessNV(GLenum mode,
                                           GLenum type,
                                           const void* indirect,
                                           GLsizei drawCount,
                                           GLsizei stride,
                                           GLint vertexBufferCount)
{
    glMultiDrawElementsIndirectBindlessNV_ptr(mode, type, indirect, drawCount, stride, vertexBufferCount);
}

#pragma endregion

#pragma region GL_NV_bindless_multi_draw_indirect_count

void glMultiDrawArraysIndirectBindlessCountNV(GLenum mode,
                                              const void* indirect,
                                              GLsizei drawCount,
                                              GLsizei maxDrawCount,
                                              GLsizei stride,
                                              GLint vertexBufferCount)
{
    glMultiDrawArraysIndirectBindlessCountNV_ptr(mode, indirect, drawCount, maxDrawCount, stride, vertexBufferCount);
}

void glMultiDrawElementsIndirectBindlessCountNV(GLenum mode,
                                                GLenum type,
                                                const void* indirect,
                                                GLsizei drawCount,
                                                GLsizei maxDrawCount,
                                                GLsizei stride,
                                                GLint vertexBufferCount)
{
    glMultiDrawElementsIndirectBindlessCountNV_ptr(mode,
                                                   type,
                                                   indirect,
                                                   drawCount,
                                                   maxDrawCount,
                                                   stride,
                                                   vertexBufferCount);
}

#pragma endregion

#pragma region GL_NV_bindless_texture

GLuint64 glGetTextureHandleNV(GLuint texture)
{
    return glGetTextureHandleNV_ptr(texture);
}

GLuint64 glGetTextureSamplerHandleNV(GLuint texture, GLuint sampler)
{
    return glGetTextureSamplerHandleNV_ptr(texture, sampler);
}

void glMakeTextureHandleResidentNV(GLuint64 handle)
{
    glMakeTextureHandleResidentNV_ptr(handle);
}

void glMakeTextureHandleNonResidentNV(GLuint64 handle)
{
    glMakeTextureHandleNonResidentNV_ptr(handle);
}

GLuint64 glGetImageHandleNV(GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format)
{
    return glGetImageHandleNV_ptr(texture, level, layered, layer, format);
}

void glMakeImageHandleResidentNV(GLuint64 handle, GLenum access)
{
    glMakeImageHandleResidentNV_ptr(handle, access);
}

void glMakeImageHandleNonResidentNV(GLuint64 handle)
{
    glMakeImageHandleNonResidentNV_ptr(handle);
}

void glUniformHandleui64NV(GLint location, GLuint64 value)
{
    glUniformHandleui64NV_ptr(location, value);
}

void glUniformHandleui64vNV(GLint location, GLsizei count, const GLuint64* value)
{
    glUniformHandleui64vNV_ptr(location, count, value);
}

void glProgramUniformHandleui64NV(GLuint program, GLint location, GLuint64 value)
{
    glProgramUniformHandleui64NV_ptr(program, location, value);
}

void glProgramUniformHandleui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64* values)
{
    glProgramUniformHandleui64vNV_ptr(program, location, count, values);
}

GLboolean glIsTextureHandleResidentNV(GLuint64 handle)
{
    return glIsTextureHandleResidentNV_ptr(handle);
}

GLboolean glIsImageHandleResidentNV(GLuint64 handle)
{
    return glIsImageHandleResidentNV_ptr(handle);
}

#pragma endregion

#pragma region GL_NV_blend_equation_advanced

void glBlendParameteriNV(GLenum pname, GLint value)
{
    glBlendParameteriNV_ptr(pname, value);
}

void glBlendBarrierNV()
{
    glBlendBarrierNV_ptr();
}

#pragma endregion

#pragma region GL_NV_blend_equation_advanced_coherent

#pragma endregion

#pragma region GL_NV_blend_minmax_factor

#pragma endregion

#pragma region GL_NV_clip_space_w_scaling

void glViewportPositionWScaleNV(GLuint index, GLfloat xcoeff, GLfloat ycoeff)
{
    glViewportPositionWScaleNV_ptr(index, xcoeff, ycoeff);
}

#pragma endregion

#pragma region GL_NV_command_list

void glCreateStatesNV(GLsizei n, GLuint* states)
{
    glCreateStatesNV_ptr(n, states);
}

void glDeleteStatesNV(GLsizei n, const GLuint* states)
{
    glDeleteStatesNV_ptr(n, states);
}

GLboolean glIsStateNV(GLuint state)
{
    return glIsStateNV_ptr(state);
}

void glStateCaptureNV(GLuint state, GLenum mode)
{
    glStateCaptureNV_ptr(state, mode);
}

GLuint glGetCommandHeaderNV(GLenum tokenID, GLuint size)
{
    return glGetCommandHeaderNV_ptr(tokenID, size);
}

GLushort glGetStageIndexNV(GLenum shadertype)
{
    return glGetStageIndexNV_ptr(shadertype);
}

void glDrawCommandsNV(GLenum primitiveMode, GLuint buffer, const GLintptr* indirects, const GLsizei* sizes, GLuint count)
{
    glDrawCommandsNV_ptr(primitiveMode, buffer, indirects, sizes, count);
}

void glDrawCommandsAddressNV(GLenum primitiveMode, const GLuint64* indirects, const GLsizei* sizes, GLuint count)
{
    glDrawCommandsAddressNV_ptr(primitiveMode, indirects, sizes, count);
}

void glDrawCommandsStatesNV(GLuint buffer,
                            const GLintptr* indirects,
                            const GLsizei* sizes,
                            const GLuint* states,
                            const GLuint* fbos,
                            GLuint count)
{
    glDrawCommandsStatesNV_ptr(buffer, indirects, sizes, states, fbos, count);
}

void glDrawCommandsStatesAddressNV(const GLuint64* indirects,
                                   const GLsizei* sizes,
                                   const GLuint* states,
                                   const GLuint* fbos,
                                   GLuint count)
{
    glDrawCommandsStatesAddressNV_ptr(indirects, sizes, states, fbos, count);
}

void glCreateCommandListsNV(GLsizei n, GLuint* lists)
{
    glCreateCommandListsNV_ptr(n, lists);
}

void glDeleteCommandListsNV(GLsizei n, const GLuint* lists)
{
    glDeleteCommandListsNV_ptr(n, lists);
}

GLboolean glIsCommandListNV(GLuint list)
{
    return glIsCommandListNV_ptr(list);
}

void glListDrawCommandsStatesClientNV(GLuint list,
                                      GLuint segment,
                                      const void** indirects,
                                      const GLsizei* sizes,
                                      const GLuint* states,
                                      const GLuint* fbos,
                                      GLuint count)
{
    glListDrawCommandsStatesClientNV_ptr(list, segment, indirects, sizes, states, fbos, count);
}

void glCommandListSegmentsNV(GLuint list, GLuint segments)
{
    glCommandListSegmentsNV_ptr(list, segments);
}

void glCompileCommandListNV(GLuint list)
{
    glCompileCommandListNV_ptr(list);
}

void glCallCommandListNV(GLuint list)
{
    glCallCommandListNV_ptr(list);
}

#pragma endregion

#pragma region GL_NV_compute_shader_derivatives

#pragma endregion

#pragma region GL_NV_conditional_render

void glBeginConditionalRenderNV(GLuint id, GLenum mode)
{
    glBeginConditionalRenderNV_ptr(id, mode);
}

void glEndConditionalRenderNV()
{
    glEndConditionalRenderNV_ptr();
}

#pragma endregion

#pragma region GL_NV_conservative_raster

void glSubpixelPrecisionBiasNV(GLuint xbits, GLuint ybits)
{
    glSubpixelPrecisionBiasNV_ptr(xbits, ybits);
}

#pragma endregion

#pragma region GL_NV_conservative_raster_dilate

void glConservativeRasterParameterfNV(GLenum pname, GLfloat value)
{
    glConservativeRasterParameterfNV_ptr(pname, value);
}

#pragma endregion

#pragma region GL_NV_conservative_raster_pre_snap

#pragma endregion

#pragma region GL_NV_conservative_raster_pre_snap_triangles

void glConservativeRasterParameteriNV(GLenum pname, GLint param)
{
    glConservativeRasterParameteriNV_ptr(pname, param);
}

#pragma endregion

#pragma region GL_NV_conservative_raster_underestimation

#pragma endregion

#pragma region GL_NV_depth_buffer_float

void glDepthRangedNV(GLdouble zNear, GLdouble zFar)
{
    glDepthRangedNV_ptr(zNear, zFar);
}

void glClearDepthdNV(GLdouble depth)
{
    glClearDepthdNV_ptr(depth);
}

void glDepthBoundsdNV(GLdouble zmin, GLdouble zmax)
{
    glDepthBoundsdNV_ptr(zmin, zmax);
}

#pragma endregion

#pragma region GL_NV_draw_vulkan_image

void glDrawVkImageNV(GLuint64 vkImage,
                     GLuint sampler,
                     GLfloat x0,
                     GLfloat y0,
                     GLfloat x1,
                     GLfloat y1,
                     GLfloat z,
                     GLfloat s0,
                     GLfloat t0,
                     GLfloat s1,
                     GLfloat t1)
{
    glDrawVkImageNV_ptr(vkImage, sampler, x0, y0, x1, y1, z, s0, t0, s1, t1);
}

GLVULKANPROCNV glGetVkProcAddrNV(const GLchar* name)
{
    return glGetVkProcAddrNV_ptr(name);
}

void glWaitVkSemaphoreNV(GLuint64 vkSemaphore)
{
    glWaitVkSemaphoreNV_ptr(vkSemaphore);
}

void glSignalVkSemaphoreNV(GLuint64 vkSemaphore)
{
    glSignalVkSemaphoreNV_ptr(vkSemaphore);
}

void glSignalVkFenceNV(GLuint64 vkFence)
{
    glSignalVkFenceNV_ptr(vkFence);
}

#pragma endregion

#pragma region GL_NV_fill_rectangle

#pragma endregion

#pragma region GL_NV_fragment_coverage_to_color

void glFragmentCoverageColorNV(GLuint color)
{
    glFragmentCoverageColorNV_ptr(color);
}

#pragma endregion

#pragma region GL_NV_fragment_shader_barycentric

#pragma endregion

#pragma region GL_NV_fragment_shader_interlock

#pragma endregion

#pragma region GL_NV_framebuffer_mixed_samples

void glCoverageModulationTableNV(GLsizei n, const GLfloat* v)
{
    glCoverageModulationTableNV_ptr(n, v);
}

void glGetCoverageModulationTableNV(GLsizei bufSize, GLfloat* v)
{
    glGetCoverageModulationTableNV_ptr(bufSize, v);
}

void glCoverageModulationNV(GLenum components)
{
    glCoverageModulationNV_ptr(components);
}

#pragma endregion

#pragma region GL_NV_framebuffer_multisample_coverage

void glRenderbufferStorageMultisampleCoverageNV(GLenum target,
                                                GLsizei coverageSamples,
                                                GLsizei colorSamples,
                                                GLenum internalformat,
                                                GLsizei width,
                                                GLsizei height)
{
    glRenderbufferStorageMultisampleCoverageNV_ptr(target, coverageSamples, colorSamples, internalformat, width, height);
}

#pragma endregion

#pragma region GL_NV_geometry_shader_passthrough

#pragma endregion

#pragma region GL_NV_gpu_shader5

void glUniform1i64NV(GLint location, GLint64EXT x)
{
    glUniform1i64NV_ptr(location, x);
}

void glUniform2i64NV(GLint location, GLint64EXT x, GLint64EXT y)
{
    glUniform2i64NV_ptr(location, x, y);
}

void glUniform3i64NV(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z)
{
    glUniform3i64NV_ptr(location, x, y, z);
}

void glUniform4i64NV(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w)
{
    glUniform4i64NV_ptr(location, x, y, z, w);
}

void glUniform1i64vNV(GLint location, GLsizei count, const GLint64EXT* value)
{
    glUniform1i64vNV_ptr(location, count, value);
}

void glUniform2i64vNV(GLint location, GLsizei count, const GLint64EXT* value)
{
    glUniform2i64vNV_ptr(location, count, value);
}

void glUniform3i64vNV(GLint location, GLsizei count, const GLint64EXT* value)
{
    glUniform3i64vNV_ptr(location, count, value);
}

void glUniform4i64vNV(GLint location, GLsizei count, const GLint64EXT* value)
{
    glUniform4i64vNV_ptr(location, count, value);
}

void glUniform1ui64NV(GLint location, GLuint64EXT x)
{
    glUniform1ui64NV_ptr(location, x);
}

void glUniform2ui64NV(GLint location, GLuint64EXT x, GLuint64EXT y)
{
    glUniform2ui64NV_ptr(location, x, y);
}

void glUniform3ui64NV(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z)
{
    glUniform3ui64NV_ptr(location, x, y, z);
}

void glUniform4ui64NV(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w)
{
    glUniform4ui64NV_ptr(location, x, y, z, w);
}

void glUniform1ui64vNV(GLint location, GLsizei count, const GLuint64EXT* value)
{
    glUniform1ui64vNV_ptr(location, count, value);
}

void glUniform2ui64vNV(GLint location, GLsizei count, const GLuint64EXT* value)
{
    glUniform2ui64vNV_ptr(location, count, value);
}

void glUniform3ui64vNV(GLint location, GLsizei count, const GLuint64EXT* value)
{
    glUniform3ui64vNV_ptr(location, count, value);
}

void glUniform4ui64vNV(GLint location, GLsizei count, const GLuint64EXT* value)
{
    glUniform4ui64vNV_ptr(location, count, value);
}

void glGetUniformi64vNV(GLuint program, GLint location, GLint64EXT* params)
{
    glGetUniformi64vNV_ptr(program, location, params);
}

void glProgramUniform1i64NV(GLuint program, GLint location, GLint64EXT x)
{
    glProgramUniform1i64NV_ptr(program, location, x);
}

void glProgramUniform2i64NV(GLuint program, GLint location, GLint64EXT x, GLint64EXT y)
{
    glProgramUniform2i64NV_ptr(program, location, x, y);
}

void glProgramUniform3i64NV(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z)
{
    glProgramUniform3i64NV_ptr(program, location, x, y, z);
}

void glProgramUniform4i64NV(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w)
{
    glProgramUniform4i64NV_ptr(program, location, x, y, z, w);
}

void glProgramUniform1i64vNV(GLuint program, GLint location, GLsizei count, const GLint64EXT* value)
{
    glProgramUniform1i64vNV_ptr(program, location, count, value);
}

void glProgramUniform2i64vNV(GLuint program, GLint location, GLsizei count, const GLint64EXT* value)
{
    glProgramUniform2i64vNV_ptr(program, location, count, value);
}

void glProgramUniform3i64vNV(GLuint program, GLint location, GLsizei count, const GLint64EXT* value)
{
    glProgramUniform3i64vNV_ptr(program, location, count, value);
}

void glProgramUniform4i64vNV(GLuint program, GLint location, GLsizei count, const GLint64EXT* value)
{
    glProgramUniform4i64vNV_ptr(program, location, count, value);
}

void glProgramUniform1ui64NV(GLuint program, GLint location, GLuint64EXT x)
{
    glProgramUniform1ui64NV_ptr(program, location, x);
}

void glProgramUniform2ui64NV(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y)
{
    glProgramUniform2ui64NV_ptr(program, location, x, y);
}

void glProgramUniform3ui64NV(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z)
{
    glProgramUniform3ui64NV_ptr(program, location, x, y, z);
}

void glProgramUniform4ui64NV(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w)
{
    glProgramUniform4ui64NV_ptr(program, location, x, y, z, w);
}

void glProgramUniform1ui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT* value)
{
    glProgramUniform1ui64vNV_ptr(program, location, count, value);
}

void glProgramUniform2ui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT* value)
{
    glProgramUniform2ui64vNV_ptr(program, location, count, value);
}

void glProgramUniform3ui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT* value)
{
    glProgramUniform3ui64vNV_ptr(program, location, count, value);
}

void glProgramUniform4ui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT* value)
{
    glProgramUniform4ui64vNV_ptr(program, location, count, value);
}

#pragma endregion

#pragma region GL_NV_internalformat_sample_query

void glGetInternalformatSampleivNV(GLenum target,
                                   GLenum internalformat,
                                   GLsizei samples,
                                   GLenum pname,
                                   GLsizei count,
                                   GLint* params)
{
    glGetInternalformatSampleivNV_ptr(target, internalformat, samples, pname, count, params);
}

#pragma endregion

#pragma region GL_NV_memory_attachment

void glGetMemoryObjectDetachedResourcesuivNV(GLuint memory, GLenum pname, GLint first, GLsizei count, GLuint* params)
{
    glGetMemoryObjectDetachedResourcesuivNV_ptr(memory, pname, first, count, params);
}

void glResetMemoryObjectParameterNV(GLuint memory, GLenum pname)
{
    glResetMemoryObjectParameterNV_ptr(memory, pname);
}

void glTexAttachMemoryNV(GLenum target, GLuint memory, GLuint64 offset)
{
    glTexAttachMemoryNV_ptr(target, memory, offset);
}

void glBufferAttachMemoryNV(GLenum target, GLuint memory, GLuint64 offset)
{
    glBufferAttachMemoryNV_ptr(target, memory, offset);
}

void glTextureAttachMemoryNV(GLuint texture, GLuint memory, GLuint64 offset)
{
    glTextureAttachMemoryNV_ptr(texture, memory, offset);
}

void glNamedBufferAttachMemoryNV(GLuint buffer, GLuint memory, GLuint64 offset)
{
    glNamedBufferAttachMemoryNV_ptr(buffer, memory, offset);
}

#pragma endregion

#pragma region GL_NV_mesh_shader

void glDrawMeshTasksNV(GLuint first, GLuint count)
{
    glDrawMeshTasksNV_ptr(first, count);
}

void glDrawMeshTasksIndirectNV(GLintptr indirect)
{
    glDrawMeshTasksIndirectNV_ptr(indirect);
}

void glMultiDrawMeshTasksIndirectNV(GLintptr indirect, GLsizei drawcount, GLsizei stride)
{
    glMultiDrawMeshTasksIndirectNV_ptr(indirect, drawcount, stride);
}

void glMultiDrawMeshTasksIndirectCountNV(GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride)
{
    glMultiDrawMeshTasksIndirectCountNV_ptr(indirect, drawcount, maxdrawcount, stride);
}

#pragma endregion

#pragma region GL_NV_path_rendering

GLuint glGenPathsNV(GLsizei range)
{
    return glGenPathsNV_ptr(range);
}

void glDeletePathsNV(GLuint path, GLsizei range)
{
    glDeletePathsNV_ptr(path, range);
}

GLboolean glIsPathNV(GLuint path)
{
    return glIsPathNV_ptr(path);
}

void glPathCommandsNV(GLuint path,
                      GLsizei numCommands,
                      const GLubyte* commands,
                      GLsizei numCoords,
                      GLenum coordType,
                      const void* coords)
{
    glPathCommandsNV_ptr(path, numCommands, commands, numCoords, coordType, coords);
}

void glPathCoordsNV(GLuint path, GLsizei numCoords, GLenum coordType, const void* coords)
{
    glPathCoordsNV_ptr(path, numCoords, coordType, coords);
}

void glPathSubCommandsNV(GLuint path,
                         GLsizei commandStart,
                         GLsizei commandsToDelete,
                         GLsizei numCommands,
                         const GLubyte* commands,
                         GLsizei numCoords,
                         GLenum coordType,
                         const void* coords)
{
    glPathSubCommandsNV_ptr(path, commandStart, commandsToDelete, numCommands, commands, numCoords, coordType, coords);
}

void glPathSubCoordsNV(GLuint path, GLsizei coordStart, GLsizei numCoords, GLenum coordType, const void* coords)
{
    glPathSubCoordsNV_ptr(path, coordStart, numCoords, coordType, coords);
}

void glPathStringNV(GLuint path, GLenum format, GLsizei length, const void* pathString)
{
    glPathStringNV_ptr(path, format, length, pathString);
}

void glPathGlyphsNV(GLuint firstPathName,
                    GLenum fontTarget,
                    const void* fontName,
                    GLbitfield fontStyle,
                    GLsizei numGlyphs,
                    GLenum type,
                    const void* charcodes,
                    GLenum handleMissingGlyphs,
                    GLuint pathParameterTemplate,
                    GLfloat emScale)
{
    glPathGlyphsNV_ptr(firstPathName,
                       fontTarget,
                       fontName,
                       fontStyle,
                       numGlyphs,
                       type,
                       charcodes,
                       handleMissingGlyphs,
                       pathParameterTemplate,
                       emScale);
}

void glPathGlyphRangeNV(GLuint firstPathName,
                        GLenum fontTarget,
                        const void* fontName,
                        GLbitfield fontStyle,
                        GLuint firstGlyph,
                        GLsizei numGlyphs,
                        GLenum handleMissingGlyphs,
                        GLuint pathParameterTemplate,
                        GLfloat emScale)
{
    glPathGlyphRangeNV_ptr(firstPathName,
                           fontTarget,
                           fontName,
                           fontStyle,
                           firstGlyph,
                           numGlyphs,
                           handleMissingGlyphs,
                           pathParameterTemplate,
                           emScale);
}

void glWeightPathsNV(GLuint resultPath, GLsizei numPaths, const GLuint* paths, const GLfloat* weights)
{
    glWeightPathsNV_ptr(resultPath, numPaths, paths, weights);
}

void glCopyPathNV(GLuint resultPath, GLuint srcPath)
{
    glCopyPathNV_ptr(resultPath, srcPath);
}

void glInterpolatePathsNV(GLuint resultPath, GLuint pathA, GLuint pathB, GLfloat weight)
{
    glInterpolatePathsNV_ptr(resultPath, pathA, pathB, weight);
}

void glTransformPathNV(GLuint resultPath, GLuint srcPath, GLenum transformType, const GLfloat* transformValues)
{
    glTransformPathNV_ptr(resultPath, srcPath, transformType, transformValues);
}

void glPathParameterivNV(GLuint path, GLenum pname, const GLint* value)
{
    glPathParameterivNV_ptr(path, pname, value);
}

void glPathParameteriNV(GLuint path, GLenum pname, GLint value)
{
    glPathParameteriNV_ptr(path, pname, value);
}

void glPathParameterfvNV(GLuint path, GLenum pname, const GLfloat* value)
{
    glPathParameterfvNV_ptr(path, pname, value);
}

void glPathParameterfNV(GLuint path, GLenum pname, GLfloat value)
{
    glPathParameterfNV_ptr(path, pname, value);
}

void glPathDashArrayNV(GLuint path, GLsizei dashCount, const GLfloat* dashArray)
{
    glPathDashArrayNV_ptr(path, dashCount, dashArray);
}

void glPathStencilFuncNV(GLenum func, GLint ref, GLuint mask)
{
    glPathStencilFuncNV_ptr(func, ref, mask);
}

void glPathStencilDepthOffsetNV(GLfloat factor, GLfloat units)
{
    glPathStencilDepthOffsetNV_ptr(factor, units);
}

void glStencilFillPathNV(GLuint path, GLenum fillMode, GLuint mask)
{
    glStencilFillPathNV_ptr(path, fillMode, mask);
}

void glStencilStrokePathNV(GLuint path, GLint reference, GLuint mask)
{
    glStencilStrokePathNV_ptr(path, reference, mask);
}

void glStencilFillPathInstancedNV(GLsizei numPaths,
                                  GLenum pathNameType,
                                  const void* paths,
                                  GLuint pathBase,
                                  GLenum fillMode,
                                  GLuint mask,
                                  GLenum transformType,
                                  const GLfloat* transformValues)
{
    glStencilFillPathInstancedNV_ptr(numPaths,
                                     pathNameType,
                                     paths,
                                     pathBase,
                                     fillMode,
                                     mask,
                                     transformType,
                                     transformValues);
}

void glStencilStrokePathInstancedNV(GLsizei numPaths,
                                    GLenum pathNameType,
                                    const void* paths,
                                    GLuint pathBase,
                                    GLint reference,
                                    GLuint mask,
                                    GLenum transformType,
                                    const GLfloat* transformValues)
{
    glStencilStrokePathInstancedNV_ptr(numPaths,
                                       pathNameType,
                                       paths,
                                       pathBase,
                                       reference,
                                       mask,
                                       transformType,
                                       transformValues);
}

void glPathCoverDepthFuncNV(GLenum func)
{
    glPathCoverDepthFuncNV_ptr(func);
}

void glCoverFillPathNV(GLuint path, GLenum coverMode)
{
    glCoverFillPathNV_ptr(path, coverMode);
}

void glCoverStrokePathNV(GLuint path, GLenum coverMode)
{
    glCoverStrokePathNV_ptr(path, coverMode);
}

void glCoverFillPathInstancedNV(GLsizei numPaths,
                                GLenum pathNameType,
                                const void* paths,
                                GLuint pathBase,
                                GLenum coverMode,
                                GLenum transformType,
                                const GLfloat* transformValues)
{
    glCoverFillPathInstancedNV_ptr(numPaths, pathNameType, paths, pathBase, coverMode, transformType, transformValues);
}

void glCoverStrokePathInstancedNV(GLsizei numPaths,
                                  GLenum pathNameType,
                                  const void* paths,
                                  GLuint pathBase,
                                  GLenum coverMode,
                                  GLenum transformType,
                                  const GLfloat* transformValues)
{
    glCoverStrokePathInstancedNV_ptr(numPaths, pathNameType, paths, pathBase, coverMode, transformType, transformValues);
}

void glGetPathParameterivNV(GLuint path, GLenum pname, GLint* value)
{
    glGetPathParameterivNV_ptr(path, pname, value);
}

void glGetPathParameterfvNV(GLuint path, GLenum pname, GLfloat* value)
{
    glGetPathParameterfvNV_ptr(path, pname, value);
}

void glGetPathCommandsNV(GLuint path, GLubyte* commands)
{
    glGetPathCommandsNV_ptr(path, commands);
}

void glGetPathCoordsNV(GLuint path, GLfloat* coords)
{
    glGetPathCoordsNV_ptr(path, coords);
}

void glGetPathDashArrayNV(GLuint path, GLfloat* dashArray)
{
    glGetPathDashArrayNV_ptr(path, dashArray);
}

void glGetPathMetricsNV(GLbitfield metricQueryMask,
                        GLsizei numPaths,
                        GLenum pathNameType,
                        const void* paths,
                        GLuint pathBase,
                        GLsizei stride,
                        GLfloat* metrics)
{
    glGetPathMetricsNV_ptr(metricQueryMask, numPaths, pathNameType, paths, pathBase, stride, metrics);
}

void glGetPathMetricRangeNV(GLbitfield metricQueryMask,
                            GLuint firstPathName,
                            GLsizei numPaths,
                            GLsizei stride,
                            GLfloat* metrics)
{
    glGetPathMetricRangeNV_ptr(metricQueryMask, firstPathName, numPaths, stride, metrics);
}

void glGetPathSpacingNV(GLenum pathListMode,
                        GLsizei numPaths,
                        GLenum pathNameType,
                        const void* paths,
                        GLuint pathBase,
                        GLfloat advanceScale,
                        GLfloat kerningScale,
                        GLenum transformType,
                        GLfloat* returnedSpacing)
{
    glGetPathSpacingNV_ptr(pathListMode,
                           numPaths,
                           pathNameType,
                           paths,
                           pathBase,
                           advanceScale,
                           kerningScale,
                           transformType,
                           returnedSpacing);
}

GLboolean glIsPointInFillPathNV(GLuint path, GLuint mask, GLfloat x, GLfloat y)
{
    return glIsPointInFillPathNV_ptr(path, mask, x, y);
}

GLboolean glIsPointInStrokePathNV(GLuint path, GLfloat x, GLfloat y)
{
    return glIsPointInStrokePathNV_ptr(path, x, y);
}

GLfloat glGetPathLengthNV(GLuint path, GLsizei startSegment, GLsizei numSegments)
{
    return glGetPathLengthNV_ptr(path, startSegment, numSegments);
}

GLboolean glPointAlongPathNV(GLuint path,
                             GLsizei startSegment,
                             GLsizei numSegments,
                             GLfloat distance,
                             GLfloat* x,
                             GLfloat* y,
                             GLfloat* tangentX,
                             GLfloat* tangentY)
{
    return glPointAlongPathNV_ptr(path, startSegment, numSegments, distance, x, y, tangentX, tangentY);
}

void glMatrixLoad3x2fNV(GLenum matrixMode, const GLfloat* m)
{
    glMatrixLoad3x2fNV_ptr(matrixMode, m);
}

void glMatrixLoad3x3fNV(GLenum matrixMode, const GLfloat* m)
{
    glMatrixLoad3x3fNV_ptr(matrixMode, m);
}

void glMatrixLoadTranspose3x3fNV(GLenum matrixMode, const GLfloat* m)
{
    glMatrixLoadTranspose3x3fNV_ptr(matrixMode, m);
}

void glMatrixMult3x2fNV(GLenum matrixMode, const GLfloat* m)
{
    glMatrixMult3x2fNV_ptr(matrixMode, m);
}

void glMatrixMult3x3fNV(GLenum matrixMode, const GLfloat* m)
{
    glMatrixMult3x3fNV_ptr(matrixMode, m);
}

void glMatrixMultTranspose3x3fNV(GLenum matrixMode, const GLfloat* m)
{
    glMatrixMultTranspose3x3fNV_ptr(matrixMode, m);
}

void glStencilThenCoverFillPathNV(GLuint path, GLenum fillMode, GLuint mask, GLenum coverMode)
{
    glStencilThenCoverFillPathNV_ptr(path, fillMode, mask, coverMode);
}

void glStencilThenCoverStrokePathNV(GLuint path, GLint reference, GLuint mask, GLenum coverMode)
{
    glStencilThenCoverStrokePathNV_ptr(path, reference, mask, coverMode);
}

void glStencilThenCoverFillPathInstancedNV(GLsizei numPaths,
                                           GLenum pathNameType,
                                           const void* paths,
                                           GLuint pathBase,
                                           GLenum fillMode,
                                           GLuint mask,
                                           GLenum coverMode,
                                           GLenum transformType,
                                           const GLfloat* transformValues)
{
    glStencilThenCoverFillPathInstancedNV_ptr(numPaths,
                                              pathNameType,
                                              paths,
                                              pathBase,
                                              fillMode,
                                              mask,
                                              coverMode,
                                              transformType,
                                              transformValues);
}

void glStencilThenCoverStrokePathInstancedNV(GLsizei numPaths,
                                             GLenum pathNameType,
                                             const void* paths,
                                             GLuint pathBase,
                                             GLint reference,
                                             GLuint mask,
                                             GLenum coverMode,
                                             GLenum transformType,
                                             const GLfloat* transformValues)
{
    glStencilThenCoverStrokePathInstancedNV_ptr(numPaths,
                                                pathNameType,
                                                paths,
                                                pathBase,
                                                reference,
                                                mask,
                                                coverMode,
                                                transformType,
                                                transformValues);
}

GLenum glPathGlyphIndexRangeNV(GLenum fontTarget,
                               const void* fontName,
                               GLbitfield fontStyle,
                               GLuint pathParameterTemplate,
                               GLfloat emScale,
                               GLuint baseAndCount[2])
{
    return glPathGlyphIndexRangeNV_ptr(fontTarget, fontName, fontStyle, pathParameterTemplate, emScale, baseAndCount);
}

GLenum glPathGlyphIndexArrayNV(GLuint firstPathName,
                               GLenum fontTarget,
                               const void* fontName,
                               GLbitfield fontStyle,
                               GLuint firstGlyphIndex,
                               GLsizei numGlyphs,
                               GLuint pathParameterTemplate,
                               GLfloat emScale)
{
    return glPathGlyphIndexArrayNV_ptr(firstPathName,
                                       fontTarget,
                                       fontName,
                                       fontStyle,
                                       firstGlyphIndex,
                                       numGlyphs,
                                       pathParameterTemplate,
                                       emScale);
}

GLenum glPathMemoryGlyphIndexArrayNV(GLuint firstPathName,
                                     GLenum fontTarget,
                                     GLsizeiptr fontSize,
                                     const void* fontData,
                                     GLsizei faceIndex,
                                     GLuint firstGlyphIndex,
                                     GLsizei numGlyphs,
                                     GLuint pathParameterTemplate,
                                     GLfloat emScale)
{
    return glPathMemoryGlyphIndexArrayNV_ptr(firstPathName,
                                             fontTarget,
                                             fontSize,
                                             fontData,
                                             faceIndex,
                                             firstGlyphIndex,
                                             numGlyphs,
                                             pathParameterTemplate,
                                             emScale);
}

void glProgramPathFragmentInputGenNV(GLuint program,
                                     GLint location,
                                     GLenum genMode,
                                     GLint components,
                                     const GLfloat* coeffs)
{
    glProgramPathFragmentInputGenNV_ptr(program, location, genMode, components, coeffs);
}

void glGetProgramResourcefvNV(GLuint program,
                              GLenum programInterface,
                              GLuint index,
                              GLsizei propCount,
                              const GLenum* props,
                              GLsizei count,
                              GLsizei* length,
                              GLfloat* params)
{
    glGetProgramResourcefvNV_ptr(program, programInterface, index, propCount, props, count, length, params);
}

#pragma endregion

#pragma region GL_NV_path_rendering_shared_edge

#pragma endregion

#pragma region GL_NV_representative_fragment_test

#pragma endregion

#pragma region GL_NV_sample_locations

void glFramebufferSampleLocationsfvNV(GLenum target, GLuint start, GLsizei count, const GLfloat* v)
{
    glFramebufferSampleLocationsfvNV_ptr(target, start, count, v);
}

void glNamedFramebufferSampleLocationsfvNV(GLuint framebuffer, GLuint start, GLsizei count, const GLfloat* v)
{
    glNamedFramebufferSampleLocationsfvNV_ptr(framebuffer, start, count, v);
}

void glResolveDepthValuesNV()
{
    glResolveDepthValuesNV_ptr();
}

#pragma endregion

#pragma region GL_NV_sample_mask_override_coverage

#pragma endregion

#pragma region GL_NV_scissor_exclusive

void glScissorExclusiveNV(GLint x, GLint y, GLsizei width, GLsizei height)
{
    glScissorExclusiveNV_ptr(x, y, width, height);
}

void glScissorExclusiveArrayvNV(GLuint first, GLsizei count, const GLint* v)
{
    glScissorExclusiveArrayvNV_ptr(first, count, v);
}

#pragma endregion

#pragma region GL_NV_shader_atomic_counters

#pragma endregion

#pragma region GL_NV_shader_atomic_float

#pragma endregion

#pragma region GL_NV_shader_atomic_float64

#pragma endregion

#pragma region GL_NV_shader_atomic_fp16_vector

#pragma endregion

#pragma region GL_NV_shader_atomic_int64

#pragma endregion

#pragma region GL_NV_shader_buffer_load

void glMakeBufferResidentNV(GLenum target, GLenum access)
{
    glMakeBufferResidentNV_ptr(target, access);
}

void glMakeBufferNonResidentNV(GLenum target)
{
    glMakeBufferNonResidentNV_ptr(target);
}

GLboolean glIsBufferResidentNV(GLenum target)
{
    return glIsBufferResidentNV_ptr(target);
}

void glMakeNamedBufferResidentNV(GLuint buffer, GLenum access)
{
    glMakeNamedBufferResidentNV_ptr(buffer, access);
}

void glMakeNamedBufferNonResidentNV(GLuint buffer)
{
    glMakeNamedBufferNonResidentNV_ptr(buffer);
}

GLboolean glIsNamedBufferResidentNV(GLuint buffer)
{
    return glIsNamedBufferResidentNV_ptr(buffer);
}

void glGetBufferParameterui64vNV(GLenum target, GLenum pname, GLuint64EXT* params)
{
    glGetBufferParameterui64vNV_ptr(target, pname, params);
}

void glGetNamedBufferParameterui64vNV(GLuint buffer, GLenum pname, GLuint64EXT* params)
{
    glGetNamedBufferParameterui64vNV_ptr(buffer, pname, params);
}

void glGetIntegerui64vNV(GLenum value, GLuint64EXT* result)
{
    glGetIntegerui64vNV_ptr(value, result);
}

void glUniformui64NV(GLint location, GLuint64EXT value)
{
    glUniformui64NV_ptr(location, value);
}

void glUniformui64vNV(GLint location, GLsizei count, const GLuint64EXT* value)
{
    glUniformui64vNV_ptr(location, count, value);
}

void glGetUniformui64vNV(GLuint program, GLint location, GLuint64EXT* params)
{
    glGetUniformui64vNV_ptr(program, location, params);
}

void glProgramUniformui64NV(GLuint program, GLint location, GLuint64EXT value)
{
    glProgramUniformui64NV_ptr(program, location, value);
}

void glProgramUniformui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT* value)
{
    glProgramUniformui64vNV_ptr(program, location, count, value);
}

#pragma endregion

#pragma region GL_NV_shader_buffer_store

#pragma endregion

#pragma region GL_NV_shader_subgroup_partitioned

#pragma endregion

#pragma region GL_NV_shader_texture_footprint

#pragma endregion

#pragma region GL_NV_shader_thread_group

#pragma endregion

#pragma region GL_NV_shader_thread_shuffle

#pragma endregion

#pragma region GL_NV_shading_rate_image

void glBindShadingRateImageNV(GLuint texture)
{
    glBindShadingRateImageNV_ptr(texture);
}

void glGetShadingRateImagePaletteNV(GLuint viewport, GLuint entry, GLenum* rate)
{
    glGetShadingRateImagePaletteNV_ptr(viewport, entry, rate);
}

void glGetShadingRateSampleLocationivNV(GLenum rate, GLuint samples, GLuint index, GLint* location)
{
    glGetShadingRateSampleLocationivNV_ptr(rate, samples, index, location);
}

void glShadingRateImageBarrierNV(GLboolean synchronize)
{
    glShadingRateImageBarrierNV_ptr(synchronize);
}

void glShadingRateImagePaletteNV(GLuint viewport, GLuint first, GLsizei count, const GLenum* rates)
{
    glShadingRateImagePaletteNV_ptr(viewport, first, count, rates);
}

void glShadingRateSampleOrderNV(GLenum order)
{
    glShadingRateSampleOrderNV_ptr(order);
}

void glShadingRateSampleOrderCustomNV(GLenum rate, GLuint samples, const GLint* locations)
{
    glShadingRateSampleOrderCustomNV_ptr(rate, samples, locations);
}

#pragma endregion

#pragma region GL_NV_stereo_view_rendering

#pragma endregion

#pragma region GL_NV_texture_barrier

void glTextureBarrierNV()
{
    glTextureBarrierNV_ptr();
}

#pragma endregion

#pragma region GL_NV_texture_rectangle_compressed

#pragma endregion

#pragma region GL_NV_uniform_buffer_unified_memory

#pragma endregion

#pragma region GL_NV_vertex_attrib_integer_64bit

void glVertexAttribL1i64NV(GLuint index, GLint64EXT x)
{
    glVertexAttribL1i64NV_ptr(index, x);
}

void glVertexAttribL2i64NV(GLuint index, GLint64EXT x, GLint64EXT y)
{
    glVertexAttribL2i64NV_ptr(index, x, y);
}

void glVertexAttribL3i64NV(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z)
{
    glVertexAttribL3i64NV_ptr(index, x, y, z);
}

void glVertexAttribL4i64NV(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w)
{
    glVertexAttribL4i64NV_ptr(index, x, y, z, w);
}

void glVertexAttribL1i64vNV(GLuint index, const GLint64EXT* v)
{
    glVertexAttribL1i64vNV_ptr(index, v);
}

void glVertexAttribL2i64vNV(GLuint index, const GLint64EXT* v)
{
    glVertexAttribL2i64vNV_ptr(index, v);
}

void glVertexAttribL3i64vNV(GLuint index, const GLint64EXT* v)
{
    glVertexAttribL3i64vNV_ptr(index, v);
}

void glVertexAttribL4i64vNV(GLuint index, const GLint64EXT* v)
{
    glVertexAttribL4i64vNV_ptr(index, v);
}

void glVertexAttribL1ui64NV(GLuint index, GLuint64EXT x)
{
    glVertexAttribL1ui64NV_ptr(index, x);
}

void glVertexAttribL2ui64NV(GLuint index, GLuint64EXT x, GLuint64EXT y)
{
    glVertexAttribL2ui64NV_ptr(index, x, y);
}

void glVertexAttribL3ui64NV(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z)
{
    glVertexAttribL3ui64NV_ptr(index, x, y, z);
}

void glVertexAttribL4ui64NV(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w)
{
    glVertexAttribL4ui64NV_ptr(index, x, y, z, w);
}

void glVertexAttribL1ui64vNV(GLuint index, const GLuint64EXT* v)
{
    glVertexAttribL1ui64vNV_ptr(index, v);
}

void glVertexAttribL2ui64vNV(GLuint index, const GLuint64EXT* v)
{
    glVertexAttribL2ui64vNV_ptr(index, v);
}

void glVertexAttribL3ui64vNV(GLuint index, const GLuint64EXT* v)
{
    glVertexAttribL3ui64vNV_ptr(index, v);
}

void glVertexAttribL4ui64vNV(GLuint index, const GLuint64EXT* v)
{
    glVertexAttribL4ui64vNV_ptr(index, v);
}

void glGetVertexAttribLi64vNV(GLuint index, GLenum pname, GLint64EXT* params)
{
    glGetVertexAttribLi64vNV_ptr(index, pname, params);
}

void glGetVertexAttribLui64vNV(GLuint index, GLenum pname, GLuint64EXT* params)
{
    glGetVertexAttribLui64vNV_ptr(index, pname, params);
}

void glVertexAttribLFormatNV(GLuint index, GLint size, GLenum type, GLsizei stride)
{
    glVertexAttribLFormatNV_ptr(index, size, type, stride);
}

#pragma endregion

#pragma region GL_NV_vertex_buffer_unified_memory

void glBufferAddressRangeNV(GLenum pname, GLuint index, GLuint64EXT address, GLsizeiptr length)
{
    glBufferAddressRangeNV_ptr(pname, index, address, length);
}

void glVertexFormatNV(GLint size, GLenum type, GLsizei stride)
{
    glVertexFormatNV_ptr(size, type, stride);
}

void glNormalFormatNV(GLenum type, GLsizei stride)
{
    glNormalFormatNV_ptr(type, stride);
}

void glColorFormatNV(GLint size, GLenum type, GLsizei stride)
{
    glColorFormatNV_ptr(size, type, stride);
}

void glIndexFormatNV(GLenum type, GLsizei stride)
{
    glIndexFormatNV_ptr(type, stride);
}

void glTexCoordFormatNV(GLint size, GLenum type, GLsizei stride)
{
    glTexCoordFormatNV_ptr(size, type, stride);
}

void glEdgeFlagFormatNV(GLsizei stride)
{
    glEdgeFlagFormatNV_ptr(stride);
}

void glSecondaryColorFormatNV(GLint size, GLenum type, GLsizei stride)
{
    glSecondaryColorFormatNV_ptr(size, type, stride);
}

void glFogCoordFormatNV(GLenum type, GLsizei stride)
{
    glFogCoordFormatNV_ptr(type, stride);
}

void glVertexAttribFormatNV(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride)
{
    glVertexAttribFormatNV_ptr(index, size, type, normalized, stride);
}

void glVertexAttribIFormatNV(GLuint index, GLint size, GLenum type, GLsizei stride)
{
    glVertexAttribIFormatNV_ptr(index, size, type, stride);
}

void glGetIntegerui64i_vNV(GLenum value, GLuint index, GLuint64EXT* result)
{
    glGetIntegerui64i_vNV_ptr(value, index, result);
}

#pragma endregion

#pragma region GL_NV_viewport_array2

#pragma endregion

#pragma region GL_NV_viewport_swizzle

void glViewportSwizzleNV(GLuint index, GLenum swizzlex, GLenum swizzley, GLenum swizzlez, GLenum swizzlew)
{
    glViewportSwizzleNV_ptr(index, swizzlex, swizzley, swizzlez, swizzlew);
}

#pragma endregion

#pragma region GL_OVR_multiview

void glFramebufferTextureMultiviewOVR(GLenum target,
                                      GLenum attachment,
                                      GLuint texture,
                                      GLint level,
                                      GLint baseViewIndex,
                                      GLsizei numViews)
{
    glFramebufferTextureMultiviewOVR_ptr(target, attachment, texture, level, baseViewIndex, numViews);
}

#pragma endregion

#pragma region GL_OVR_multiview2

#pragma endregion

#pragma region GL_EXT_texture_shadow_lod

#pragma endregion

void init_opengl(const GetFunction& get_function)
{
    std::call_once(init_flag, [&get_function]() {
        init_features(get_function);
        init_extensions(get_function);
    });
}

bool is_supported(Feature feature)
{
    return feature_cache[static_cast<int>(feature)];
}

bool is_supported(Extension extension)
{
    return extension_cache[static_cast<int>(extension)];
}

} // namespace framework::graphics::details::opengl
