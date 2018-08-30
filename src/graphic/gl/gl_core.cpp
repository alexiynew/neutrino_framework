/// @file
/// @brief OpneGL core functionality wrapper.
/// @author Fedorov Alexey
/// @date 21.06.2018

// =============================================================================
// MIT License
//
// Copyright (c) 2017-2018 Fedorov Alexey
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

#include <graphic/gl/gl_core.hpp>
#include <graphic/gl/gl_utils.hpp>

namespace
{
using ::framework::int8;
using ::framework::uint8;

using ::framework::int16;
using ::framework::uint16;

using ::framework::int32;
using ::framework::uint32;

using ::framework::int64;
using ::framework::uint64;

using ::framework::float32;
using ::framework::float64;

using ::framework::ptrdiff;

using GLenum = ::framework::uint32;

#pragma region gl_version_1_0

using glCullFace_ptr           = void (*)(GLenum mode);
glCullFace_ptr glCullFace_proc = nullptr;

using glFrontFace_ptr            = void (*)(GLenum mode);
glFrontFace_ptr glFrontFace_proc = nullptr;

using glHint_ptr       = void (*)(GLenum target, GLenum mode);
glHint_ptr glHint_proc = nullptr;

using glLineWidth_ptr            = void (*)(float32 width);
glLineWidth_ptr glLineWidth_proc = nullptr;

using glPointSize_ptr            = void (*)(float32 size);
glPointSize_ptr glPointSize_proc = nullptr;

using glPolygonMode_ptr              = void (*)(GLenum face, GLenum mode);
glPolygonMode_ptr glPolygonMode_proc = nullptr;

using glScissor_ptr          = void (*)(int32 x, int32 y, int32 width, int32 height);
glScissor_ptr glScissor_proc = nullptr;

using glTexParameterf_ptr                = void (*)(GLenum target, GLenum pname, float32 param);
glTexParameterf_ptr glTexParameterf_proc = nullptr;

using glTexParameterfv_ptr                 = void (*)(GLenum target, GLenum pname, const float32* params);
glTexParameterfv_ptr glTexParameterfv_proc = nullptr;

using glTexParameteri_ptr                = void (*)(GLenum target, GLenum pname, int32 param);
glTexParameteri_ptr glTexParameteri_proc = nullptr;

using glTexParameteriv_ptr                 = void (*)(GLenum target, GLenum pname, const int32* params);
glTexParameteriv_ptr glTexParameteriv_proc = nullptr;

using glTexImage1D_ptr             = void (*)(GLenum target,
                                  int32 level,
                                  int32 internalformat,
                                  int32 width,
                                  int32 border,
                                  GLenum format,
                                  GLenum type,
                                  const void* pixels);
glTexImage1D_ptr glTexImage1D_proc = nullptr;

using glTexImage2D_ptr             = void (*)(GLenum target,
                                  int32 level,
                                  int32 internalformat,
                                  int32 width,
                                  int32 height,
                                  int32 border,
                                  GLenum format,
                                  GLenum type,
                                  const void* pixels);
glTexImage2D_ptr glTexImage2D_proc = nullptr;

using glDrawBuffer_ptr             = void (*)(GLenum buf);
glDrawBuffer_ptr glDrawBuffer_proc = nullptr;

using glClear_ptr        = void (*)(uint32 mask);
glClear_ptr glClear_proc = nullptr;

using glClearColor_ptr             = void (*)(float32 red, float32 green, float32 blue, float32 alpha);
glClearColor_ptr glClearColor_proc = nullptr;

using glClearStencil_ptr               = void (*)(int32 s);
glClearStencil_ptr glClearStencil_proc = nullptr;

using glClearDepth_ptr             = void (*)(float64 depth);
glClearDepth_ptr glClearDepth_proc = nullptr;

using glStencilMask_ptr              = void (*)(uint32 mask);
glStencilMask_ptr glStencilMask_proc = nullptr;

using glColorMask_ptr            = void (*)(bool red, bool green, bool blue, bool alpha);
glColorMask_ptr glColorMask_proc = nullptr;

using glDepthMask_ptr            = void (*)(bool flag);
glDepthMask_ptr glDepthMask_proc = nullptr;

using glDisable_ptr          = void (*)(GLenum cap);
glDisable_ptr glDisable_proc = nullptr;

using glEnable_ptr         = void (*)(GLenum cap);
glEnable_ptr glEnable_proc = nullptr;

using glFinish_ptr         = void (*)();
glFinish_ptr glFinish_proc = nullptr;

using glFlush_ptr        = void (*)();
glFlush_ptr glFlush_proc = nullptr;

using glBlendFunc_ptr            = void (*)(GLenum sfactor, GLenum dfactor);
glBlendFunc_ptr glBlendFunc_proc = nullptr;

using glLogicOp_ptr          = void (*)(GLenum opcode);
glLogicOp_ptr glLogicOp_proc = nullptr;

using glStencilFunc_ptr              = void (*)(GLenum func, int32 ref, uint32 mask);
glStencilFunc_ptr glStencilFunc_proc = nullptr;

using glStencilOp_ptr            = void (*)(GLenum fail, GLenum zfail, GLenum zpass);
glStencilOp_ptr glStencilOp_proc = nullptr;

using glDepthFunc_ptr            = void (*)(GLenum func);
glDepthFunc_ptr glDepthFunc_proc = nullptr;

using glPixelStoref_ptr              = void (*)(GLenum pname, float32 param);
glPixelStoref_ptr glPixelStoref_proc = nullptr;

using glPixelStorei_ptr              = void (*)(GLenum pname, int32 param);
glPixelStorei_ptr glPixelStorei_proc = nullptr;

using glReadBuffer_ptr             = void (*)(GLenum src);
glReadBuffer_ptr glReadBuffer_proc = nullptr;

using glReadPixels_ptr = void (*)(int32 x, int32 y, int32 width, int32 height, GLenum format, GLenum type, void* pixels);
glReadPixels_ptr glReadPixels_proc = nullptr;

using glGetBooleanv_ptr              = void (*)(GLenum pname, bool* data);
glGetBooleanv_ptr glGetBooleanv_proc = nullptr;

using glGetDoublev_ptr             = void (*)(GLenum pname, float64* data);
glGetDoublev_ptr glGetDoublev_proc = nullptr;

using glGetError_ptr           = GLenum (*)();
glGetError_ptr glGetError_proc = nullptr;

using glGetFloatv_ptr            = void (*)(GLenum pname, float32* data);
glGetFloatv_ptr glGetFloatv_proc = nullptr;

using glGetIntegerv_ptr              = void (*)(GLenum pname, int32* data);
glGetIntegerv_ptr glGetIntegerv_proc = nullptr;

using glGetString_ptr            = const uint8* (*)(GLenum name);
glGetString_ptr glGetString_proc = nullptr;

using glGetTexImage_ptr              = void (*)(GLenum target, int32 level, GLenum format, GLenum type, void* pixels);
glGetTexImage_ptr glGetTexImage_proc = nullptr;

using glGetTexParameterfv_ptr                    = void (*)(GLenum target, GLenum pname, float32* params);
glGetTexParameterfv_ptr glGetTexParameterfv_proc = nullptr;

using glGetTexParameteriv_ptr                    = void (*)(GLenum target, GLenum pname, int32* params);
glGetTexParameteriv_ptr glGetTexParameteriv_proc = nullptr;

using glGetTexLevelParameterfv_ptr = void (*)(GLenum target, int32 level, GLenum pname, float32* params);
glGetTexLevelParameterfv_ptr glGetTexLevelParameterfv_proc = nullptr;

using glGetTexLevelParameteriv_ptr = void (*)(GLenum target, int32 level, GLenum pname, int32* params);
glGetTexLevelParameteriv_ptr glGetTexLevelParameteriv_proc = nullptr;

using glIsEnabled_ptr            = bool (*)(GLenum cap);
glIsEnabled_ptr glIsEnabled_proc = nullptr;

using glDepthRange_ptr             = void (*)(float64 near, float64 far);
glDepthRange_ptr glDepthRange_proc = nullptr;

using glViewport_ptr           = void (*)(int32 x, int32 y, int32 width, int32 height);
glViewport_ptr glViewport_proc = nullptr;

bool init_gl_version_1_0()
{
    using ::framework::graphic::utils::get_function;

    bool result = true;

    result = result && (glCullFace_proc = get_function<glCullFace_ptr>("glCullFace")) != nullptr;
    result = result && (glFrontFace_proc = get_function<glFrontFace_ptr>("glFrontFace")) != nullptr;
    result = result && (glHint_proc = get_function<glHint_ptr>("glHint")) != nullptr;
    result = result && (glLineWidth_proc = get_function<glLineWidth_ptr>("glLineWidth")) != nullptr;
    result = result && (glPointSize_proc = get_function<glPointSize_ptr>("glPointSize")) != nullptr;
    result = result && (glPolygonMode_proc = get_function<glPolygonMode_ptr>("glPolygonMode")) != nullptr;
    result = result && (glScissor_proc = get_function<glScissor_ptr>("glScissor")) != nullptr;
    result = result && (glTexParameterf_proc = get_function<glTexParameterf_ptr>("glTexParameterf")) != nullptr;
    result = result && (glTexParameterfv_proc = get_function<glTexParameterfv_ptr>("glTexParameterfv")) != nullptr;
    result = result && (glTexParameteri_proc = get_function<glTexParameteri_ptr>("glTexParameteri")) != nullptr;
    result = result && (glTexParameteriv_proc = get_function<glTexParameteriv_ptr>("glTexParameteriv")) != nullptr;
    result = result && (glTexImage1D_proc = get_function<glTexImage1D_ptr>("glTexImage1D")) != nullptr;
    result = result && (glTexImage2D_proc = get_function<glTexImage2D_ptr>("glTexImage2D")) != nullptr;
    result = result && (glDrawBuffer_proc = get_function<glDrawBuffer_ptr>("glDrawBuffer")) != nullptr;
    result = result && (glClear_proc = get_function<glClear_ptr>("glClear")) != nullptr;
    result = result && (glClearColor_proc = get_function<glClearColor_ptr>("glClearColor")) != nullptr;
    result = result && (glClearStencil_proc = get_function<glClearStencil_ptr>("glClearStencil")) != nullptr;
    result = result && (glClearDepth_proc = get_function<glClearDepth_ptr>("glClearDepth")) != nullptr;
    result = result && (glStencilMask_proc = get_function<glStencilMask_ptr>("glStencilMask")) != nullptr;
    result = result && (glColorMask_proc = get_function<glColorMask_ptr>("glColorMask")) != nullptr;
    result = result && (glDepthMask_proc = get_function<glDepthMask_ptr>("glDepthMask")) != nullptr;
    result = result && (glDisable_proc = get_function<glDisable_ptr>("glDisable")) != nullptr;
    result = result && (glEnable_proc = get_function<glEnable_ptr>("glEnable")) != nullptr;
    result = result && (glFinish_proc = get_function<glFinish_ptr>("glFinish")) != nullptr;
    result = result && (glFlush_proc = get_function<glFlush_ptr>("glFlush")) != nullptr;
    result = result && (glBlendFunc_proc = get_function<glBlendFunc_ptr>("glBlendFunc")) != nullptr;
    result = result && (glLogicOp_proc = get_function<glLogicOp_ptr>("glLogicOp")) != nullptr;
    result = result && (glStencilFunc_proc = get_function<glStencilFunc_ptr>("glStencilFunc")) != nullptr;
    result = result && (glStencilOp_proc = get_function<glStencilOp_ptr>("glStencilOp")) != nullptr;
    result = result && (glDepthFunc_proc = get_function<glDepthFunc_ptr>("glDepthFunc")) != nullptr;
    result = result && (glPixelStoref_proc = get_function<glPixelStoref_ptr>("glPixelStoref")) != nullptr;
    result = result && (glPixelStorei_proc = get_function<glPixelStorei_ptr>("glPixelStorei")) != nullptr;
    result = result && (glReadBuffer_proc = get_function<glReadBuffer_ptr>("glReadBuffer")) != nullptr;
    result = result && (glReadPixels_proc = get_function<glReadPixels_ptr>("glReadPixels")) != nullptr;
    result = result && (glGetBooleanv_proc = get_function<glGetBooleanv_ptr>("glGetBooleanv")) != nullptr;
    result = result && (glGetDoublev_proc = get_function<glGetDoublev_ptr>("glGetDoublev")) != nullptr;
    result = result && (glGetError_proc = get_function<glGetError_ptr>("glGetError")) != nullptr;
    result = result && (glGetFloatv_proc = get_function<glGetFloatv_ptr>("glGetFloatv")) != nullptr;
    result = result && (glGetIntegerv_proc = get_function<glGetIntegerv_ptr>("glGetIntegerv")) != nullptr;
    result = result && (glGetString_proc = get_function<glGetString_ptr>("glGetString")) != nullptr;
    result = result && (glGetTexImage_proc = get_function<glGetTexImage_ptr>("glGetTexImage")) != nullptr;
    result = result &&
             (glGetTexParameterfv_proc = get_function<glGetTexParameterfv_ptr>("glGetTexParameterfv")) != nullptr;
    result = result &&
             (glGetTexParameteriv_proc = get_function<glGetTexParameteriv_ptr>("glGetTexParameteriv")) != nullptr;
    result = result &&
             (glGetTexLevelParameterfv_proc = get_function<glGetTexLevelParameterfv_ptr>("glGetTexLevelParameterfv")) !=
             nullptr;
    result = result &&
             (glGetTexLevelParameteriv_proc = get_function<glGetTexLevelParameteriv_ptr>("glGetTexLevelParameteriv")) !=
             nullptr;
    result = result && (glIsEnabled_proc = get_function<glIsEnabled_ptr>("glIsEnabled")) != nullptr;
    result = result && (glDepthRange_proc = get_function<glDepthRange_ptr>("glDepthRange")) != nullptr;
    result = result && (glViewport_proc = get_function<glViewport_ptr>("glViewport")) != nullptr;

    return result;
}

#pragma endregion

#pragma region gl_version_1_1

using glDrawArrays_ptr             = void (*)(GLenum mode, int32 first, int32 count);
glDrawArrays_ptr glDrawArrays_proc = nullptr;

using glDrawElements_ptr               = void (*)(GLenum mode, int32 count, GLenum type, const void* indices);
glDrawElements_ptr glDrawElements_proc = nullptr;

using glGetPointerv_ptr              = void (*)(GLenum pname, void** params);
glGetPointerv_ptr glGetPointerv_proc = nullptr;

using glPolygonOffset_ptr                = void (*)(float32 factor, float32 units);
glPolygonOffset_ptr glPolygonOffset_proc = nullptr;

using glCopyTexImage1D_ptr =
void (*)(GLenum target, int32 level, GLenum internalformat, int32 x, int32 y, int32 width, int32 border);
glCopyTexImage1D_ptr glCopyTexImage1D_proc = nullptr;

using glCopyTexImage2D_ptr =
void (*)(GLenum target, int32 level, GLenum internalformat, int32 x, int32 y, int32 width, int32 height, int32 border);
glCopyTexImage2D_ptr glCopyTexImage2D_proc = nullptr;

using glCopyTexSubImage1D_ptr = void (*)(GLenum target, int32 level, int32 xoffset, int32 x, int32 y, int32 width);
glCopyTexSubImage1D_ptr glCopyTexSubImage1D_proc = nullptr;

using glCopyTexSubImage2D_ptr =
void (*)(GLenum target, int32 level, int32 xoffset, int32 yoffset, int32 x, int32 y, int32 width, int32 height);
glCopyTexSubImage2D_ptr glCopyTexSubImage2D_proc = nullptr;

using glTexSubImage1D_ptr =
void (*)(GLenum target, int32 level, int32 xoffset, int32 width, GLenum format, GLenum type, const void* pixels);
glTexSubImage1D_ptr glTexSubImage1D_proc = nullptr;

using glTexSubImage2D_ptr                = void (*)(GLenum target,
                                     int32 level,
                                     int32 xoffset,
                                     int32 yoffset,
                                     int32 width,
                                     int32 height,
                                     GLenum format,
                                     GLenum type,
                                     const void* pixels);
glTexSubImage2D_ptr glTexSubImage2D_proc = nullptr;

using glBindTexture_ptr              = void (*)(GLenum target, uint32 texture);
glBindTexture_ptr glBindTexture_proc = nullptr;

using glDeleteTextures_ptr                 = void (*)(int32 n, const uint32* textures);
glDeleteTextures_ptr glDeleteTextures_proc = nullptr;

using glGenTextures_ptr              = void (*)(int32 n, uint32* textures);
glGenTextures_ptr glGenTextures_proc = nullptr;

using glIsTexture_ptr            = bool (*)(uint32 texture);
glIsTexture_ptr glIsTexture_proc = nullptr;

bool init_gl_version_1_1()
{
    using ::framework::graphic::utils::get_function;

    bool result = true;

    result = result && (glDrawArrays_proc = get_function<glDrawArrays_ptr>("glDrawArrays")) != nullptr;
    result = result && (glDrawElements_proc = get_function<glDrawElements_ptr>("glDrawElements")) != nullptr;
    result = result && (glGetPointerv_proc = get_function<glGetPointerv_ptr>("glGetPointerv")) != nullptr;
    result = result && (glPolygonOffset_proc = get_function<glPolygonOffset_ptr>("glPolygonOffset")) != nullptr;
    result = result && (glCopyTexImage1D_proc = get_function<glCopyTexImage1D_ptr>("glCopyTexImage1D")) != nullptr;
    result = result && (glCopyTexImage2D_proc = get_function<glCopyTexImage2D_ptr>("glCopyTexImage2D")) != nullptr;
    result = result &&
             (glCopyTexSubImage1D_proc = get_function<glCopyTexSubImage1D_ptr>("glCopyTexSubImage1D")) != nullptr;
    result = result &&
             (glCopyTexSubImage2D_proc = get_function<glCopyTexSubImage2D_ptr>("glCopyTexSubImage2D")) != nullptr;
    result = result && (glTexSubImage1D_proc = get_function<glTexSubImage1D_ptr>("glTexSubImage1D")) != nullptr;
    result = result && (glTexSubImage2D_proc = get_function<glTexSubImage2D_ptr>("glTexSubImage2D")) != nullptr;
    result = result && (glBindTexture_proc = get_function<glBindTexture_ptr>("glBindTexture")) != nullptr;
    result = result && (glDeleteTextures_proc = get_function<glDeleteTextures_ptr>("glDeleteTextures")) != nullptr;
    result = result && (glGenTextures_proc = get_function<glGenTextures_ptr>("glGenTextures")) != nullptr;
    result = result && (glIsTexture_proc = get_function<glIsTexture_ptr>("glIsTexture")) != nullptr;

    return result;
}

#pragma endregion

#pragma region gl_version_1_2

using glDrawRangeElements_ptr =
void (*)(GLenum mode, uint32 start, uint32 end, int32 count, GLenum type, const void* indices);
glDrawRangeElements_ptr glDrawRangeElements_proc = nullptr;

using glTexImage3D_ptr             = void (*)(GLenum target,
                                  int32 level,
                                  int32 internalformat,
                                  int32 width,
                                  int32 height,
                                  int32 depth,
                                  int32 border,
                                  GLenum format,
                                  GLenum type,
                                  const void* pixels);
glTexImage3D_ptr glTexImage3D_proc = nullptr;

using glTexSubImage3D_ptr                = void (*)(GLenum target,
                                     int32 level,
                                     int32 xoffset,
                                     int32 yoffset,
                                     int32 zoffset,
                                     int32 width,
                                     int32 height,
                                     int32 depth,
                                     GLenum format,
                                     GLenum type,
                                     const void* pixels);
glTexSubImage3D_ptr glTexSubImage3D_proc = nullptr;

using glCopyTexSubImage3D_ptr                    = void (*)(GLenum target,
                                         int32 level,
                                         int32 xoffset,
                                         int32 yoffset,
                                         int32 zoffset,
                                         int32 x,
                                         int32 y,
                                         int32 width,
                                         int32 height);
glCopyTexSubImage3D_ptr glCopyTexSubImage3D_proc = nullptr;

bool init_gl_version_1_2()
{
    using ::framework::graphic::utils::get_function;

    bool result = true;

    result = result &&
             (glDrawRangeElements_proc = get_function<glDrawRangeElements_ptr>("glDrawRangeElements")) != nullptr;
    result = result && (glTexImage3D_proc = get_function<glTexImage3D_ptr>("glTexImage3D")) != nullptr;
    result = result && (glTexSubImage3D_proc = get_function<glTexSubImage3D_ptr>("glTexSubImage3D")) != nullptr;
    result = result &&
             (glCopyTexSubImage3D_proc = get_function<glCopyTexSubImage3D_ptr>("glCopyTexSubImage3D")) != nullptr;

    return result;
}

#pragma endregion

#pragma region gl_version_1_3

using glActiveTexture_ptr                = void (*)(GLenum texture);
glActiveTexture_ptr glActiveTexture_proc = nullptr;

using glSampleCoverage_ptr                 = void (*)(float32 value, bool invert);
glSampleCoverage_ptr glSampleCoverage_proc = nullptr;

using glCompressedTexImage3D_ptr                       = void (*)(GLenum target,
                                            int32 level,
                                            GLenum internalformat,
                                            int32 width,
                                            int32 height,
                                            int32 depth,
                                            int32 border,
                                            int32 imageSize,
                                            const void* data);
glCompressedTexImage3D_ptr glCompressedTexImage3D_proc = nullptr;

using glCompressedTexImage2D_ptr                       = void (*)(GLenum target,
                                            int32 level,
                                            GLenum internalformat,
                                            int32 width,
                                            int32 height,
                                            int32 border,
                                            int32 imageSize,
                                            const void* data);
glCompressedTexImage2D_ptr glCompressedTexImage2D_proc = nullptr;

using glCompressedTexImage1D_ptr                       = void (*)(GLenum target,
                                            int32 level,
                                            GLenum internalformat,
                                            int32 width,
                                            int32 border,
                                            int32 imageSize,
                                            const void* data);
glCompressedTexImage1D_ptr glCompressedTexImage1D_proc = nullptr;

using glCompressedTexSubImage3D_ptr                          = void (*)(GLenum target,
                                               int32 level,
                                               int32 xoffset,
                                               int32 yoffset,
                                               int32 zoffset,
                                               int32 width,
                                               int32 height,
                                               int32 depth,
                                               GLenum format,
                                               int32 imageSize,
                                               const void* data);
glCompressedTexSubImage3D_ptr glCompressedTexSubImage3D_proc = nullptr;

using glCompressedTexSubImage2D_ptr                          = void (*)(GLenum target,
                                               int32 level,
                                               int32 xoffset,
                                               int32 yoffset,
                                               int32 width,
                                               int32 height,
                                               GLenum format,
                                               int32 imageSize,
                                               const void* data);
glCompressedTexSubImage2D_ptr glCompressedTexSubImage2D_proc = nullptr;

using glCompressedTexSubImage1D_ptr =
void (*)(GLenum target, int32 level, int32 xoffset, int32 width, GLenum format, int32 imageSize, const void* data);
glCompressedTexSubImage1D_ptr glCompressedTexSubImage1D_proc = nullptr;

using glGetCompressedTexImage_ptr                        = void (*)(GLenum target, int32 level, void* img);
glGetCompressedTexImage_ptr glGetCompressedTexImage_proc = nullptr;

bool init_gl_version_1_3()
{
    using ::framework::graphic::utils::get_function;

    bool result = true;
    result      = result && (glActiveTexture_proc = get_function<glActiveTexture_ptr>("glActiveTexture")) != nullptr;
    result      = result && (glSampleCoverage_proc = get_function<glSampleCoverage_ptr>("glSampleCoverage")) != nullptr;
    result      = result &&
             (glCompressedTexImage3D_proc = get_function<glCompressedTexImage3D_ptr>("glCompressedTexImage3D")) !=
             nullptr;
    result = result &&
             (glCompressedTexImage2D_proc = get_function<glCompressedTexImage2D_ptr>("glCompressedTexImage2D")) !=
             nullptr;
    result = result &&
             (glCompressedTexImage1D_proc = get_function<glCompressedTexImage1D_ptr>("glCompressedTexImage1D")) !=
             nullptr;
    result = result && (glCompressedTexSubImage3D_proc = get_function<glCompressedTexSubImage3D_ptr>(
                        "glCompressedTexSubImage3D")) != nullptr;
    result = result && (glCompressedTexSubImage2D_proc = get_function<glCompressedTexSubImage2D_ptr>(
                        "glCompressedTexSubImage2D")) != nullptr;

    result = result && (glCompressedTexSubImage1D_proc = get_function<glCompressedTexSubImage1D_ptr>(
                        "glCompressedTexSubImage1D")) != nullptr;
    result = result &&
             (glGetCompressedTexImage_proc = get_function<glGetCompressedTexImage_ptr>("glGetCompressedTexImage")) !=
             nullptr;

    return result;
}

#pragma endregion

#pragma region gl_version_1_4

using glBlendFuncSeparate_ptr = void (*)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
glBlendFuncSeparate_ptr glBlendFuncSeparate_proc = nullptr;

using glMultiDrawArrays_ptr = void (*)(GLenum mode, const int32* first, const int32* count, int32 drawcount);
glMultiDrawArrays_ptr glMultiDrawArrays_proc = nullptr;

using glMultiDrawElements_ptr =
void (*)(GLenum mode, const int32* count, GLenum type, const void* const* indices, int32 drawcount);
glMultiDrawElements_ptr glMultiDrawElements_proc = nullptr;

using glPointParameterf_ptr                  = void (*)(GLenum pname, float32 param);
glPointParameterf_ptr glPointParameterf_proc = nullptr;

using glPointParameterfv_ptr                   = void (*)(GLenum pname, const float32* params);
glPointParameterfv_ptr glPointParameterfv_proc = nullptr;

using glPointParameteri_ptr                  = void (*)(GLenum pname, int32 param);
glPointParameteri_ptr glPointParameteri_proc = nullptr;

using glPointParameteriv_ptr                   = void (*)(GLenum pname, const int32* params);
glPointParameteriv_ptr glPointParameteriv_proc = nullptr;

using glBlendColor_ptr             = void (*)(float32 red, float32 green, float32 blue, float32 alpha);
glBlendColor_ptr glBlendColor_proc = nullptr;

using glBlendEquation_ptr                = void (*)(GLenum mode);
glBlendEquation_ptr glBlendEquation_proc = nullptr;

bool init_gl_version_1_4()
{
    using ::framework::graphic::utils::get_function;

    bool result = true;

    result = result &&
             (glBlendFuncSeparate_proc = get_function<glBlendFuncSeparate_ptr>("glBlendFuncSeparate")) != nullptr;
    result = result && (glMultiDrawArrays_proc = get_function<glMultiDrawArrays_ptr>("glMultiDrawArrays")) != nullptr;
    result = result &&
             (glMultiDrawElements_proc = get_function<glMultiDrawElements_ptr>("glMultiDrawElements")) != nullptr;
    result = result && (glPointParameterf_proc = get_function<glPointParameterf_ptr>("glPointParameterf")) != nullptr;
    result = result &&
             (glPointParameterfv_proc = get_function<glPointParameterfv_ptr>("glPointParameterfv")) != nullptr;
    result = result && (glPointParameteri_proc = get_function<glPointParameteri_ptr>("glPointParameteri")) != nullptr;
    result = result &&
             (glPointParameteriv_proc = get_function<glPointParameteriv_ptr>("glPointParameteriv")) != nullptr;
    result = result && (glBlendColor_proc = get_function<glBlendColor_ptr>("glBlendColor")) != nullptr;
    result = result && (glBlendEquation_proc = get_function<glBlendEquation_ptr>("glBlendEquation")) != nullptr;

    return result;
}

#pragma endregion

#pragma region gl_version_1_5

using glGenQueries_ptr             = void (*)(int32 n, uint32* ids);
glGenQueries_ptr glGenQueries_proc = nullptr;

using glDeleteQueries_ptr                = void (*)(int32 n, const uint32* ids);
glDeleteQueries_ptr glDeleteQueries_proc = nullptr;

using glIsQuery_ptr          = bool (*)(uint32 id);
glIsQuery_ptr glIsQuery_proc = nullptr;

using glBeginQuery_ptr             = void (*)(GLenum target, uint32 id);
glBeginQuery_ptr glBeginQuery_proc = nullptr;

using glEndQuery_ptr           = void (*)(GLenum target);
glEndQuery_ptr glEndQuery_proc = nullptr;

using glGetQueryiv_ptr             = void (*)(GLenum target, GLenum pname, int32* params);
glGetQueryiv_ptr glGetQueryiv_proc = nullptr;

using glGetQueryObjectiv_ptr                   = void (*)(uint32 id, GLenum pname, int32* params);
glGetQueryObjectiv_ptr glGetQueryObjectiv_proc = nullptr;

using glGetQueryObjectuiv_ptr                    = void (*)(uint32 id, GLenum pname, uint32* params);
glGetQueryObjectuiv_ptr glGetQueryObjectuiv_proc = nullptr;

using glBindBuffer_ptr             = void (*)(GLenum target, uint32 buffer);
glBindBuffer_ptr glBindBuffer_proc = nullptr;

using glDeleteBuffers_ptr                = void (*)(int32 n, const uint32* buffers);
glDeleteBuffers_ptr glDeleteBuffers_proc = nullptr;

using glGenBuffers_ptr             = void (*)(int32 n, uint32* buffers);
glGenBuffers_ptr glGenBuffers_proc = nullptr;

using glIsBuffer_ptr           = bool (*)(uint32 buffer);
glIsBuffer_ptr glIsBuffer_proc = nullptr;

using glBufferData_ptr             = void (*)(GLenum target, ptrdiff size, const void* data, GLenum usage);
glBufferData_ptr glBufferData_proc = nullptr;

using glBufferSubData_ptr                = void (*)(GLenum target, ptrdiff offset, ptrdiff size, const void* data);
glBufferSubData_ptr glBufferSubData_proc = nullptr;

using glGetBufferSubData_ptr                   = void (*)(GLenum target, ptrdiff offset, ptrdiff size, void* data);
glGetBufferSubData_ptr glGetBufferSubData_proc = nullptr;

using glMapBuffer_ptr            = void* (*)(GLenum target, GLenum access);
glMapBuffer_ptr glMapBuffer_proc = nullptr;

using glUnmapBuffer_ptr              = bool (*)(GLenum target);
glUnmapBuffer_ptr glUnmapBuffer_proc = nullptr;

using glGetBufferParameteriv_ptr                       = void (*)(GLenum target, GLenum pname, int32* params);
glGetBufferParameteriv_ptr glGetBufferParameteriv_proc = nullptr;

using glGetBufferPointerv_ptr                    = void (*)(GLenum target, GLenum pname, void** params);
glGetBufferPointerv_ptr glGetBufferPointerv_proc = nullptr;

bool init_gl_version_1_5()
{
    using ::framework::graphic::utils::get_function;

    bool result = true;

    result = result && (glGenQueries_proc = get_function<glGenQueries_ptr>("glGenQueries")) != nullptr;
    result = result && (glDeleteQueries_proc = get_function<glDeleteQueries_ptr>("glDeleteQueries")) != nullptr;
    result = result && (glIsQuery_proc = get_function<glIsQuery_ptr>("glIsQuery")) != nullptr;
    result = result && (glBeginQuery_proc = get_function<glBeginQuery_ptr>("glBeginQuery")) != nullptr;
    result = result && (glEndQuery_proc = get_function<glEndQuery_ptr>("glEndQuery")) != nullptr;
    result = result && (glGetQueryiv_proc = get_function<glGetQueryiv_ptr>("glGetQueryiv")) != nullptr;
    result = result &&
             (glGetQueryObjectiv_proc = get_function<glGetQueryObjectiv_ptr>("glGetQueryObjectiv")) != nullptr;
    result = result &&
             (glGetQueryObjectuiv_proc = get_function<glGetQueryObjectuiv_ptr>("glGetQueryObjectuiv")) != nullptr;
    result = result && (glBindBuffer_proc = get_function<glBindBuffer_ptr>("glBindBuffer")) != nullptr;
    result = result && (glDeleteBuffers_proc = get_function<glDeleteBuffers_ptr>("glDeleteBuffers")) != nullptr;
    result = result && (glGenBuffers_proc = get_function<glGenBuffers_ptr>("glGenBuffers")) != nullptr;
    result = result && (glIsBuffer_proc = get_function<glIsBuffer_ptr>("glIsBuffer")) != nullptr;
    result = result && (glBufferData_proc = get_function<glBufferData_ptr>("glBufferData")) != nullptr;
    result = result && (glBufferSubData_proc = get_function<glBufferSubData_ptr>("glBufferSubData")) != nullptr;
    result = result &&
             (glGetBufferSubData_proc = get_function<glGetBufferSubData_ptr>("glGetBufferSubData")) != nullptr;
    result = result && (glMapBuffer_proc = get_function<glMapBuffer_ptr>("glMapBuffer")) != nullptr;
    result = result && (glUnmapBuffer_proc = get_function<glUnmapBuffer_ptr>("glUnmapBuffer")) != nullptr;
    result = result &&
             (glGetBufferParameteriv_proc = get_function<glGetBufferParameteriv_ptr>("glGetBufferParameteriv")) !=
             nullptr;
    result = result &&
             (glGetBufferPointerv_proc = get_function<glGetBufferPointerv_ptr>("glGetBufferPointerv")) != nullptr;

    return result;
}

#pragma endregion

#pragma region gl_version_2_0

using glBlendEquationSeparate_ptr                        = void (*)(GLenum modeRGB, GLenum modeAlpha);
glBlendEquationSeparate_ptr glBlendEquationSeparate_proc = nullptr;

using glDrawBuffers_ptr              = void (*)(int32 n, const GLenum* bufs);
glDrawBuffers_ptr glDrawBuffers_proc = nullptr;

using glStencilOpSeparate_ptr                    = void (*)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
glStencilOpSeparate_ptr glStencilOpSeparate_proc = nullptr;

using glStencilFuncSeparate_ptr                      = void (*)(GLenum face, GLenum func, int32 ref, uint32 mask);
glStencilFuncSeparate_ptr glStencilFuncSeparate_proc = nullptr;

using glStencilMaskSeparate_ptr                      = void (*)(GLenum face, uint32 mask);
glStencilMaskSeparate_ptr glStencilMaskSeparate_proc = nullptr;

using glAttachShader_ptr               = void (*)(uint32 program, uint32 shader);
glAttachShader_ptr glAttachShader_proc = nullptr;

using glBindAttribLocation_ptr                     = void (*)(uint32 program, uint32 index, const char* name);
glBindAttribLocation_ptr glBindAttribLocation_proc = nullptr;

using glCompileShader_ptr                = void (*)(uint32 shader);
glCompileShader_ptr glCompileShader_proc = nullptr;

using glCreateProgram_ptr                = uint32 (*)();
glCreateProgram_ptr glCreateProgram_proc = nullptr;

using glCreateShader_ptr               = uint32 (*)(GLenum type);
glCreateShader_ptr glCreateShader_proc = nullptr;

using glDeleteProgram_ptr                = void (*)(uint32 program);
glDeleteProgram_ptr glDeleteProgram_proc = nullptr;

using glDeleteShader_ptr               = void (*)(uint32 shader);
glDeleteShader_ptr glDeleteShader_proc = nullptr;

using glDetachShader_ptr               = void (*)(uint32 program, uint32 shader);
glDetachShader_ptr glDetachShader_proc = nullptr;

using glDisableVertexAttribArray_ptr                           = void (*)(uint32 index);
glDisableVertexAttribArray_ptr glDisableVertexAttribArray_proc = nullptr;

using glEnableVertexAttribArray_ptr                          = void (*)(uint32 index);
glEnableVertexAttribArray_ptr glEnableVertexAttribArray_proc = nullptr;

using glGetActiveAttrib_ptr =
void (*)(uint32 program, uint32 index, int32 bufSize, int32* length, int32* size, GLenum* type, char* name);
glGetActiveAttrib_ptr glGetActiveAttrib_proc = nullptr;

using glGetActiveUniform_ptr =
void (*)(uint32 program, uint32 index, int32 bufSize, int32* length, int32* size, GLenum* type, char* name);
glGetActiveUniform_ptr glGetActiveUniform_proc = nullptr;

using glGetAttachedShaders_ptr = void (*)(uint32 program, int32 maxCount, int32* count, uint32* shaders);
glGetAttachedShaders_ptr glGetAttachedShaders_proc = nullptr;

using glGetAttribLocation_ptr                    = int32 (*)(uint32 program, const char* name);
glGetAttribLocation_ptr glGetAttribLocation_proc = nullptr;

using glGetProgramiv_ptr               = void (*)(uint32 program, GLenum pname, int32* params);
glGetProgramiv_ptr glGetProgramiv_proc = nullptr;

using glGetProgramInfoLog_ptr = void (*)(uint32 program, int32 bufSize, int32* length, char* infoLog);
glGetProgramInfoLog_ptr glGetProgramInfoLog_proc = nullptr;

using glGetShaderiv_ptr              = void (*)(uint32 shader, GLenum pname, int32* params);
glGetShaderiv_ptr glGetShaderiv_proc = nullptr;

using glGetShaderInfoLog_ptr                   = void (*)(uint32 shader, int32 bufSize, int32* length, char* infoLog);
glGetShaderInfoLog_ptr glGetShaderInfoLog_proc = nullptr;

using glGetShaderSource_ptr                  = void (*)(uint32 shader, int32 bufSize, int32* length, char* source);
glGetShaderSource_ptr glGetShaderSource_proc = nullptr;

using glGetUniformLocation_ptr                     = int32 (*)(uint32 program, const char* name);
glGetUniformLocation_ptr glGetUniformLocation_proc = nullptr;

using glGetUniformfv_ptr               = void (*)(uint32 program, int32 location, float32* params);
glGetUniformfv_ptr glGetUniformfv_proc = nullptr;

using glGetUniformiv_ptr               = void (*)(uint32 program, int32 location, int32* params);
glGetUniformiv_ptr glGetUniformiv_proc = nullptr;

using glGetVertexAttribdv_ptr                    = void (*)(uint32 index, GLenum pname, float64* params);
glGetVertexAttribdv_ptr glGetVertexAttribdv_proc = nullptr;

using glGetVertexAttribfv_ptr                    = void (*)(uint32 index, GLenum pname, float32* params);
glGetVertexAttribfv_ptr glGetVertexAttribfv_proc = nullptr;

using glGetVertexAttribiv_ptr                    = void (*)(uint32 index, GLenum pname, int32* params);
glGetVertexAttribiv_ptr glGetVertexAttribiv_proc = nullptr;

using glGetVertexAttribPointerv_ptr                          = void (*)(uint32 index, GLenum pname, void** pointer);
glGetVertexAttribPointerv_ptr glGetVertexAttribPointerv_proc = nullptr;

using glIsProgram_ptr            = bool (*)(uint32 program);
glIsProgram_ptr glIsProgram_proc = nullptr;

using glIsShader_ptr           = bool (*)(uint32 shader);
glIsShader_ptr glIsShader_proc = nullptr;

using glLinkProgram_ptr              = void (*)(uint32 program);
glLinkProgram_ptr glLinkProgram_proc = nullptr;

using glShaderSource_ptr = void (*)(uint32 shader, int32 count, const char* const* string, const int32* length);
glShaderSource_ptr glShaderSource_proc = nullptr;

using glUseProgram_ptr             = void (*)(uint32 program);
glUseProgram_ptr glUseProgram_proc = nullptr;

using glUniform1f_ptr            = void (*)(int32 location, float32 v0);
glUniform1f_ptr glUniform1f_proc = nullptr;

using glUniform2f_ptr            = void (*)(int32 location, float32 v0, float32 v1);
glUniform2f_ptr glUniform2f_proc = nullptr;

using glUniform3f_ptr            = void (*)(int32 location, float32 v0, float32 v1, float32 v2);
glUniform3f_ptr glUniform3f_proc = nullptr;

using glUniform4f_ptr            = void (*)(int32 location, float32 v0, float32 v1, float32 v2, float32 v3);
glUniform4f_ptr glUniform4f_proc = nullptr;

using glUniform1i_ptr            = void (*)(int32 location, int32 v0);
glUniform1i_ptr glUniform1i_proc = nullptr;

using glUniform2i_ptr            = void (*)(int32 location, int32 v0, int32 v1);
glUniform2i_ptr glUniform2i_proc = nullptr;

using glUniform3i_ptr            = void (*)(int32 location, int32 v0, int32 v1, int32 v2);
glUniform3i_ptr glUniform3i_proc = nullptr;

using glUniform4i_ptr            = void (*)(int32 location, int32 v0, int32 v1, int32 v2, int32 v3);
glUniform4i_ptr glUniform4i_proc = nullptr;

using glUniform1fv_ptr             = void (*)(int32 location, int32 count, const float32* value);
glUniform1fv_ptr glUniform1fv_proc = nullptr;

using glUniform2fv_ptr             = void (*)(int32 location, int32 count, const float32* value);
glUniform2fv_ptr glUniform2fv_proc = nullptr;

using glUniform3fv_ptr             = void (*)(int32 location, int32 count, const float32* value);
glUniform3fv_ptr glUniform3fv_proc = nullptr;

using glUniform4fv_ptr             = void (*)(int32 location, int32 count, const float32* value);
glUniform4fv_ptr glUniform4fv_proc = nullptr;

using glUniform1iv_ptr             = void (*)(int32 location, int32 count, const int32* value);
glUniform1iv_ptr glUniform1iv_proc = nullptr;

using glUniform2iv_ptr             = void (*)(int32 location, int32 count, const int32* value);
glUniform2iv_ptr glUniform2iv_proc = nullptr;

using glUniform3iv_ptr             = void (*)(int32 location, int32 count, const int32* value);
glUniform3iv_ptr glUniform3iv_proc = nullptr;

using glUniform4iv_ptr             = void (*)(int32 location, int32 count, const int32* value);
glUniform4iv_ptr glUniform4iv_proc = nullptr;

using glUniformMatrix2fv_ptr = void (*)(int32 location, int32 count, bool transpose, const float32* value);
glUniformMatrix2fv_ptr glUniformMatrix2fv_proc = nullptr;

using glUniformMatrix3fv_ptr = void (*)(int32 location, int32 count, bool transpose, const float32* value);
glUniformMatrix3fv_ptr glUniformMatrix3fv_proc = nullptr;

using glUniformMatrix4fv_ptr = void (*)(int32 location, int32 count, bool transpose, const float32* value);
glUniformMatrix4fv_ptr glUniformMatrix4fv_proc = nullptr;

using glValidateProgram_ptr                  = void (*)(uint32 program);
glValidateProgram_ptr glValidateProgram_proc = nullptr;

using glVertexAttrib1d_ptr                 = void (*)(uint32 index, float64 x);
glVertexAttrib1d_ptr glVertexAttrib1d_proc = nullptr;

using glVertexAttrib1dv_ptr                  = void (*)(uint32 index, const float64* v);
glVertexAttrib1dv_ptr glVertexAttrib1dv_proc = nullptr;

using glVertexAttrib1f_ptr                 = void (*)(uint32 index, float32 x);
glVertexAttrib1f_ptr glVertexAttrib1f_proc = nullptr;

using glVertexAttrib1fv_ptr                  = void (*)(uint32 index, const float32* v);
glVertexAttrib1fv_ptr glVertexAttrib1fv_proc = nullptr;

using glVertexAttrib1s_ptr                 = void (*)(uint32 index, int16 x);
glVertexAttrib1s_ptr glVertexAttrib1s_proc = nullptr;

using glVertexAttrib1sv_ptr                  = void (*)(uint32 index, const int16* v);
glVertexAttrib1sv_ptr glVertexAttrib1sv_proc = nullptr;

using glVertexAttrib2d_ptr                 = void (*)(uint32 index, float64 x, float64 y);
glVertexAttrib2d_ptr glVertexAttrib2d_proc = nullptr;

using glVertexAttrib2dv_ptr                  = void (*)(uint32 index, const float64* v);
glVertexAttrib2dv_ptr glVertexAttrib2dv_proc = nullptr;

using glVertexAttrib2f_ptr                 = void (*)(uint32 index, float32 x, float32 y);
glVertexAttrib2f_ptr glVertexAttrib2f_proc = nullptr;

using glVertexAttrib2fv_ptr                  = void (*)(uint32 index, const float32* v);
glVertexAttrib2fv_ptr glVertexAttrib2fv_proc = nullptr;

using glVertexAttrib2s_ptr                 = void (*)(uint32 index, int16 x, int16 y);
glVertexAttrib2s_ptr glVertexAttrib2s_proc = nullptr;

using glVertexAttrib2sv_ptr                  = void (*)(uint32 index, const int16* v);
glVertexAttrib2sv_ptr glVertexAttrib2sv_proc = nullptr;

using glVertexAttrib3d_ptr                 = void (*)(uint32 index, float64 x, float64 y, float64 z);
glVertexAttrib3d_ptr glVertexAttrib3d_proc = nullptr;

using glVertexAttrib3dv_ptr                  = void (*)(uint32 index, const float64* v);
glVertexAttrib3dv_ptr glVertexAttrib3dv_proc = nullptr;

using glVertexAttrib3f_ptr                 = void (*)(uint32 index, float32 x, float32 y, float32 z);
glVertexAttrib3f_ptr glVertexAttrib3f_proc = nullptr;

using glVertexAttrib3fv_ptr                  = void (*)(uint32 index, const float32* v);
glVertexAttrib3fv_ptr glVertexAttrib3fv_proc = nullptr;

using glVertexAttrib3s_ptr                 = void (*)(uint32 index, int16 x, int16 y, int16 z);
glVertexAttrib3s_ptr glVertexAttrib3s_proc = nullptr;

using glVertexAttrib3sv_ptr                  = void (*)(uint32 index, const int16* v);
glVertexAttrib3sv_ptr glVertexAttrib3sv_proc = nullptr;

using glVertexAttrib4Nbv_ptr                   = void (*)(uint32 index, const int8* v);
glVertexAttrib4Nbv_ptr glVertexAttrib4Nbv_proc = nullptr;

using glVertexAttrib4Niv_ptr                   = void (*)(uint32 index, const int32* v);
glVertexAttrib4Niv_ptr glVertexAttrib4Niv_proc = nullptr;

using glVertexAttrib4Nsv_ptr                   = void (*)(uint32 index, const int16* v);
glVertexAttrib4Nsv_ptr glVertexAttrib4Nsv_proc = nullptr;

using glVertexAttrib4Nub_ptr                   = void (*)(uint32 index, uint8 x, uint8 y, uint8 z, uint8 w);
glVertexAttrib4Nub_ptr glVertexAttrib4Nub_proc = nullptr;

using glVertexAttrib4Nubv_ptr                    = void (*)(uint32 index, const uint8* v);
glVertexAttrib4Nubv_ptr glVertexAttrib4Nubv_proc = nullptr;

using glVertexAttrib4Nuiv_ptr                    = void (*)(uint32 index, const uint32* v);
glVertexAttrib4Nuiv_ptr glVertexAttrib4Nuiv_proc = nullptr;

using glVertexAttrib4Nusv_ptr                    = void (*)(uint32 index, const uint16* v);
glVertexAttrib4Nusv_ptr glVertexAttrib4Nusv_proc = nullptr;

using glVertexAttrib4bv_ptr                  = void (*)(uint32 index, const int8* v);
glVertexAttrib4bv_ptr glVertexAttrib4bv_proc = nullptr;

using glVertexAttrib4d_ptr                 = void (*)(uint32 index, float64 x, float64 y, float64 z, float64 w);
glVertexAttrib4d_ptr glVertexAttrib4d_proc = nullptr;

using glVertexAttrib4dv_ptr                  = void (*)(uint32 index, const float64* v);
glVertexAttrib4dv_ptr glVertexAttrib4dv_proc = nullptr;

using glVertexAttrib4f_ptr                 = void (*)(uint32 index, float32 x, float32 y, float32 z, float32 w);
glVertexAttrib4f_ptr glVertexAttrib4f_proc = nullptr;

using glVertexAttrib4fv_ptr                  = void (*)(uint32 index, const float32* v);
glVertexAttrib4fv_ptr glVertexAttrib4fv_proc = nullptr;

using glVertexAttrib4iv_ptr                  = void (*)(uint32 index, const int32* v);
glVertexAttrib4iv_ptr glVertexAttrib4iv_proc = nullptr;

using glVertexAttrib4s_ptr                 = void (*)(uint32 index, int16 x, int16 y, int16 z, int16 w);
glVertexAttrib4s_ptr glVertexAttrib4s_proc = nullptr;

using glVertexAttrib4sv_ptr                  = void (*)(uint32 index, const int16* v);
glVertexAttrib4sv_ptr glVertexAttrib4sv_proc = nullptr;

using glVertexAttrib4ubv_ptr                   = void (*)(uint32 index, const uint8* v);
glVertexAttrib4ubv_ptr glVertexAttrib4ubv_proc = nullptr;

using glVertexAttrib4uiv_ptr                   = void (*)(uint32 index, const uint32* v);
glVertexAttrib4uiv_ptr glVertexAttrib4uiv_proc = nullptr;

using glVertexAttrib4usv_ptr                   = void (*)(uint32 index, const uint16* v);
glVertexAttrib4usv_ptr glVertexAttrib4usv_proc = nullptr;

using glVertexAttribPointer_ptr =
void (*)(uint32 index, int32 size, GLenum type, bool normalized, int32 stride, const void* pointer);
glVertexAttribPointer_ptr glVertexAttribPointer_proc = nullptr;

bool init_gl_version_2_0()
{
    using ::framework::graphic::utils::get_function;

    bool result = true;

    result = result &&
             (glBlendEquationSeparate_proc = get_function<glBlendEquationSeparate_ptr>("glBlendEquationSeparate")) !=
             nullptr;
    result = result && (glDrawBuffers_proc = get_function<glDrawBuffers_ptr>("glDrawBuffers")) != nullptr;
    result = result &&
             (glStencilOpSeparate_proc = get_function<glStencilOpSeparate_ptr>("glStencilOpSeparate")) != nullptr;
    result = result &&
             (glStencilFuncSeparate_proc = get_function<glStencilFuncSeparate_ptr>("glStencilFuncSeparate")) != nullptr;
    result = result &&
             (glStencilMaskSeparate_proc = get_function<glStencilMaskSeparate_ptr>("glStencilMaskSeparate")) != nullptr;
    result = result && (glAttachShader_proc = get_function<glAttachShader_ptr>("glAttachShader")) != nullptr;
    result = result &&
             (glBindAttribLocation_proc = get_function<glBindAttribLocation_ptr>("glBindAttribLocation")) != nullptr;
    result = result && (glCompileShader_proc = get_function<glCompileShader_ptr>("glCompileShader")) != nullptr;
    result = result && (glCreateProgram_proc = get_function<glCreateProgram_ptr>("glCreateProgram")) != nullptr;
    result = result && (glCreateShader_proc = get_function<glCreateShader_ptr>("glCreateShader")) != nullptr;
    result = result && (glDeleteProgram_proc = get_function<glDeleteProgram_ptr>("glDeleteProgram")) != nullptr;
    result = result && (glDeleteShader_proc = get_function<glDeleteShader_ptr>("glDeleteShader")) != nullptr;
    result = result && (glDetachShader_proc = get_function<glDetachShader_ptr>("glDetachShader")) != nullptr;
    result = result && (glDisableVertexAttribArray_proc = get_function<glDisableVertexAttribArray_ptr>(
                        "glDisableVertexAttribArray")) != nullptr;
    result = result && (glEnableVertexAttribArray_proc = get_function<glEnableVertexAttribArray_ptr>(
                        "glEnableVertexAttribArray")) != nullptr;
    result = result && (glGetActiveAttrib_proc = get_function<glGetActiveAttrib_ptr>("glGetActiveAttrib")) != nullptr;
    result = result &&
             (glGetActiveUniform_proc = get_function<glGetActiveUniform_ptr>("glGetActiveUniform")) != nullptr;
    result = result &&
             (glGetAttachedShaders_proc = get_function<glGetAttachedShaders_ptr>("glGetAttachedShaders")) != nullptr;
    result = result &&
             (glGetAttribLocation_proc = get_function<glGetAttribLocation_ptr>("glGetAttribLocation")) != nullptr;
    result = result && (glGetProgramiv_proc = get_function<glGetProgramiv_ptr>("glGetProgramiv")) != nullptr;
    result = result &&
             (glGetProgramInfoLog_proc = get_function<glGetProgramInfoLog_ptr>("glGetProgramInfoLog")) != nullptr;
    result = result && (glGetShaderiv_proc = get_function<glGetShaderiv_ptr>("glGetShaderiv")) != nullptr;
    result = result &&
             (glGetShaderInfoLog_proc = get_function<glGetShaderInfoLog_ptr>("glGetShaderInfoLog")) != nullptr;
    result = result && (glGetShaderSource_proc = get_function<glGetShaderSource_ptr>("glGetShaderSource")) != nullptr;
    result = result &&
             (glGetUniformLocation_proc = get_function<glGetUniformLocation_ptr>("glGetUniformLocation")) != nullptr;
    result = result && (glGetUniformfv_proc = get_function<glGetUniformfv_ptr>("glGetUniformfv")) != nullptr;
    result = result && (glGetUniformiv_proc = get_function<glGetUniformiv_ptr>("glGetUniformiv")) != nullptr;
    result = result &&
             (glGetVertexAttribdv_proc = get_function<glGetVertexAttribdv_ptr>("glGetVertexAttribdv")) != nullptr;
    result = result &&
             (glGetVertexAttribfv_proc = get_function<glGetVertexAttribfv_ptr>("glGetVertexAttribfv")) != nullptr;
    result = result &&
             (glGetVertexAttribiv_proc = get_function<glGetVertexAttribiv_ptr>("glGetVertexAttribiv")) != nullptr;
    result = result && (glGetVertexAttribPointerv_proc = get_function<glGetVertexAttribPointerv_ptr>(
                        "glGetVertexAttribPointerv")) != nullptr;
    result = result && (glIsProgram_proc = get_function<glIsProgram_ptr>("glIsProgram")) != nullptr;
    result = result && (glIsShader_proc = get_function<glIsShader_ptr>("glIsShader")) != nullptr;
    result = result && (glLinkProgram_proc = get_function<glLinkProgram_ptr>("glLinkProgram")) != nullptr;
    result = result && (glShaderSource_proc = get_function<glShaderSource_ptr>("glShaderSource")) != nullptr;
    result = result && (glUseProgram_proc = get_function<glUseProgram_ptr>("glUseProgram")) != nullptr;
    result = result && (glUniform1f_proc = get_function<glUniform1f_ptr>("glUniform1f")) != nullptr;
    result = result && (glUniform2f_proc = get_function<glUniform2f_ptr>("glUniform2f")) != nullptr;
    result = result && (glUniform3f_proc = get_function<glUniform3f_ptr>("glUniform3f")) != nullptr;
    result = result && (glUniform4f_proc = get_function<glUniform4f_ptr>("glUniform4f")) != nullptr;
    result = result && (glUniform1i_proc = get_function<glUniform1i_ptr>("glUniform1i")) != nullptr;
    result = result && (glUniform2i_proc = get_function<glUniform2i_ptr>("glUniform2i")) != nullptr;
    result = result && (glUniform3i_proc = get_function<glUniform3i_ptr>("glUniform3i")) != nullptr;
    result = result && (glUniform4i_proc = get_function<glUniform4i_ptr>("glUniform4i")) != nullptr;
    result = result && (glUniform1fv_proc = get_function<glUniform1fv_ptr>("glUniform1fv")) != nullptr;
    result = result && (glUniform2fv_proc = get_function<glUniform2fv_ptr>("glUniform2fv")) != nullptr;
    result = result && (glUniform3fv_proc = get_function<glUniform3fv_ptr>("glUniform3fv")) != nullptr;
    result = result && (glUniform4fv_proc = get_function<glUniform4fv_ptr>("glUniform4fv")) != nullptr;
    result = result && (glUniform1iv_proc = get_function<glUniform1iv_ptr>("glUniform1iv")) != nullptr;
    result = result && (glUniform2iv_proc = get_function<glUniform2iv_ptr>("glUniform2iv")) != nullptr;
    result = result && (glUniform3iv_proc = get_function<glUniform3iv_ptr>("glUniform3iv")) != nullptr;
    result = result && (glUniform4iv_proc = get_function<glUniform4iv_ptr>("glUniform4iv")) != nullptr;
    result = result &&
             (glUniformMatrix2fv_proc = get_function<glUniformMatrix2fv_ptr>("glUniformMatrix2fv")) != nullptr;
    result = result &&
             (glUniformMatrix3fv_proc = get_function<glUniformMatrix3fv_ptr>("glUniformMatrix3fv")) != nullptr;
    result = result &&
             (glUniformMatrix4fv_proc = get_function<glUniformMatrix4fv_ptr>("glUniformMatrix4fv")) != nullptr;
    result = result && (glValidateProgram_proc = get_function<glValidateProgram_ptr>("glValidateProgram")) != nullptr;
    result = result && (glVertexAttrib1d_proc = get_function<glVertexAttrib1d_ptr>("glVertexAttrib1d")) != nullptr;
    result = result && (glVertexAttrib1dv_proc = get_function<glVertexAttrib1dv_ptr>("glVertexAttrib1dv")) != nullptr;
    result = result && (glVertexAttrib1f_proc = get_function<glVertexAttrib1f_ptr>("glVertexAttrib1f")) != nullptr;
    result = result && (glVertexAttrib1fv_proc = get_function<glVertexAttrib1fv_ptr>("glVertexAttrib1fv")) != nullptr;
    result = result && (glVertexAttrib1s_proc = get_function<glVertexAttrib1s_ptr>("glVertexAttrib1s")) != nullptr;
    result = result && (glVertexAttrib1sv_proc = get_function<glVertexAttrib1sv_ptr>("glVertexAttrib1sv")) != nullptr;
    result = result && (glVertexAttrib2d_proc = get_function<glVertexAttrib2d_ptr>("glVertexAttrib2d")) != nullptr;
    result = result && (glVertexAttrib2dv_proc = get_function<glVertexAttrib2dv_ptr>("glVertexAttrib2dv")) != nullptr;
    result = result && (glVertexAttrib2f_proc = get_function<glVertexAttrib2f_ptr>("glVertexAttrib2f")) != nullptr;
    result = result && (glVertexAttrib2fv_proc = get_function<glVertexAttrib2fv_ptr>("glVertexAttrib2fv")) != nullptr;
    result = result && (glVertexAttrib2s_proc = get_function<glVertexAttrib2s_ptr>("glVertexAttrib2s")) != nullptr;
    result = result && (glVertexAttrib2sv_proc = get_function<glVertexAttrib2sv_ptr>("glVertexAttrib2sv")) != nullptr;
    result = result && (glVertexAttrib3d_proc = get_function<glVertexAttrib3d_ptr>("glVertexAttrib3d")) != nullptr;
    result = result && (glVertexAttrib3dv_proc = get_function<glVertexAttrib3dv_ptr>("glVertexAttrib3dv")) != nullptr;
    result = result && (glVertexAttrib3f_proc = get_function<glVertexAttrib3f_ptr>("glVertexAttrib3f")) != nullptr;
    result = result && (glVertexAttrib3fv_proc = get_function<glVertexAttrib3fv_ptr>("glVertexAttrib3fv")) != nullptr;
    result = result && (glVertexAttrib3s_proc = get_function<glVertexAttrib3s_ptr>("glVertexAttrib3s")) != nullptr;
    result = result && (glVertexAttrib3sv_proc = get_function<glVertexAttrib3sv_ptr>("glVertexAttrib3sv")) != nullptr;
    result = result &&
             (glVertexAttrib4Nbv_proc = get_function<glVertexAttrib4Nbv_ptr>("glVertexAttrib4Nbv")) != nullptr;
    result = result &&
             (glVertexAttrib4Niv_proc = get_function<glVertexAttrib4Niv_ptr>("glVertexAttrib4Niv")) != nullptr;
    result = result &&
             (glVertexAttrib4Nsv_proc = get_function<glVertexAttrib4Nsv_ptr>("glVertexAttrib4Nsv")) != nullptr;
    result = result &&
             (glVertexAttrib4Nub_proc = get_function<glVertexAttrib4Nub_ptr>("glVertexAttrib4Nub")) != nullptr;
    result = result &&
             (glVertexAttrib4Nubv_proc = get_function<glVertexAttrib4Nubv_ptr>("glVertexAttrib4Nubv")) != nullptr;
    result = result &&
             (glVertexAttrib4Nuiv_proc = get_function<glVertexAttrib4Nuiv_ptr>("glVertexAttrib4Nuiv")) != nullptr;
    result = result &&
             (glVertexAttrib4Nusv_proc = get_function<glVertexAttrib4Nusv_ptr>("glVertexAttrib4Nusv")) != nullptr;
    result = result && (glVertexAttrib4bv_proc = get_function<glVertexAttrib4bv_ptr>("glVertexAttrib4bv")) != nullptr;
    result = result && (glVertexAttrib4d_proc = get_function<glVertexAttrib4d_ptr>("glVertexAttrib4d")) != nullptr;
    result = result && (glVertexAttrib4dv_proc = get_function<glVertexAttrib4dv_ptr>("glVertexAttrib4dv")) != nullptr;
    result = result && (glVertexAttrib4f_proc = get_function<glVertexAttrib4f_ptr>("glVertexAttrib4f")) != nullptr;
    result = result && (glVertexAttrib4fv_proc = get_function<glVertexAttrib4fv_ptr>("glVertexAttrib4fv")) != nullptr;
    result = result && (glVertexAttrib4iv_proc = get_function<glVertexAttrib4iv_ptr>("glVertexAttrib4iv")) != nullptr;
    result = result && (glVertexAttrib4s_proc = get_function<glVertexAttrib4s_ptr>("glVertexAttrib4s")) != nullptr;
    result = result && (glVertexAttrib4sv_proc = get_function<glVertexAttrib4sv_ptr>("glVertexAttrib4sv")) != nullptr;
    result = result &&
             (glVertexAttrib4ubv_proc = get_function<glVertexAttrib4ubv_ptr>("glVertexAttrib4ubv")) != nullptr;
    result = result &&
             (glVertexAttrib4uiv_proc = get_function<glVertexAttrib4uiv_ptr>("glVertexAttrib4uiv")) != nullptr;
    result = result &&
             (glVertexAttrib4usv_proc = get_function<glVertexAttrib4usv_ptr>("glVertexAttrib4usv")) != nullptr;
    result = result &&
             (glVertexAttribPointer_proc = get_function<glVertexAttribPointer_ptr>("glVertexAttribPointer")) != nullptr;

    return result;
}

#pragma endregion

#pragma region gl_version_2_1

using glUniformMatrix2x3fv_ptr = void (*)(int32 location, int32 count, bool transpose, const float32* value);
glUniformMatrix2x3fv_ptr glUniformMatrix2x3fv_proc = nullptr;

using glUniformMatrix3x2fv_ptr = void (*)(int32 location, int32 count, bool transpose, const float32* value);
glUniformMatrix3x2fv_ptr glUniformMatrix3x2fv_proc = nullptr;

using glUniformMatrix2x4fv_ptr = void (*)(int32 location, int32 count, bool transpose, const float32* value);
glUniformMatrix2x4fv_ptr glUniformMatrix2x4fv_proc = nullptr;

using glUniformMatrix4x2fv_ptr = void (*)(int32 location, int32 count, bool transpose, const float32* value);
glUniformMatrix4x2fv_ptr glUniformMatrix4x2fv_proc = nullptr;

using glUniformMatrix3x4fv_ptr = void (*)(int32 location, int32 count, bool transpose, const float32* value);
glUniformMatrix3x4fv_ptr glUniformMatrix3x4fv_proc = nullptr;

using glUniformMatrix4x3fv_ptr = void (*)(int32 location, int32 count, bool transpose, const float32* value);
glUniformMatrix4x3fv_ptr glUniformMatrix4x3fv_proc = nullptr;

bool init_gl_version_2_1()
{
    using ::framework::graphic::utils::get_function;

    bool result = true;

    result = result &&
             (glUniformMatrix2x3fv_proc = get_function<glUniformMatrix2x3fv_ptr>("glUniformMatrix2x3fv")) != nullptr;
    result = result &&
             (glUniformMatrix3x2fv_proc = get_function<glUniformMatrix3x2fv_ptr>("glUniformMatrix3x2fv")) != nullptr;
    result = result &&
             (glUniformMatrix2x4fv_proc = get_function<glUniformMatrix2x4fv_ptr>("glUniformMatrix2x4fv")) != nullptr;
    result = result &&
             (glUniformMatrix4x2fv_proc = get_function<glUniformMatrix4x2fv_ptr>("glUniformMatrix4x2fv")) != nullptr;
    result = result &&
             (glUniformMatrix3x4fv_proc = get_function<glUniformMatrix3x4fv_ptr>("glUniformMatrix3x4fv")) != nullptr;
    result = result &&
             (glUniformMatrix4x3fv_proc = get_function<glUniformMatrix4x3fv_ptr>("glUniformMatrix4x3fv")) != nullptr;

    return result;
}

#pragma endregion

#pragma region gl_version_3_0

using glColorMaski_ptr             = void (*)(uint32 index, bool r, bool g, bool b, bool a);
glColorMaski_ptr glColorMaski_proc = nullptr;

using glGetBooleani_v_ptr                = void (*)(GLenum target, uint32 index, bool* data);
glGetBooleani_v_ptr glGetBooleani_v_proc = nullptr;

using glGetIntegeri_v_ptr                = void (*)(GLenum target, uint32 index, int32* data);
glGetIntegeri_v_ptr glGetIntegeri_v_proc = nullptr;

using glEnablei_ptr          = void (*)(GLenum target, uint32 index);
glEnablei_ptr glEnablei_proc = nullptr;

using glDisablei_ptr           = void (*)(GLenum target, uint32 index);
glDisablei_ptr glDisablei_proc = nullptr;

using glIsEnabledi_ptr             = bool (*)(GLenum target, uint32 index);
glIsEnabledi_ptr glIsEnabledi_proc = nullptr;

using glBeginTransformFeedback_ptr                         = void (*)(GLenum primitiveMode);
glBeginTransformFeedback_ptr glBeginTransformFeedback_proc = nullptr;

using glEndTransformFeedback_ptr                       = void (*)();
glEndTransformFeedback_ptr glEndTransformFeedback_proc = nullptr;

using glBindBufferRange_ptr = void (*)(GLenum target, uint32 index, uint32 buffer, ptrdiff offset, ptrdiff size);
glBindBufferRange_ptr glBindBufferRange_proc = nullptr;

using glBindBufferBase_ptr                 = void (*)(GLenum target, uint32 index, uint32 buffer);
glBindBufferBase_ptr glBindBufferBase_proc = nullptr;

using glTransformFeedbackVaryings_ptr                            = void (*)(uint32 program,
                                                 int32 count,
                                                 const char* const* varyings,
                                                 GLenum bufferMode);
glTransformFeedbackVaryings_ptr glTransformFeedbackVaryings_proc = nullptr;

using glGetTransformFeedbackVarying_ptr =
void (*)(uint32 program, uint32 index, int32 bufSize, int32* length, int32* size, GLenum* type, char* name);
glGetTransformFeedbackVarying_ptr glGetTransformFeedbackVarying_proc = nullptr;

using glClampColor_ptr             = void (*)(GLenum target, GLenum clamp);
glClampColor_ptr glClampColor_proc = nullptr;

using glBeginConditionalRender_ptr                         = void (*)(uint32 id, GLenum mode);
glBeginConditionalRender_ptr glBeginConditionalRender_proc = nullptr;

using glEndConditionalRender_ptr                       = void (*)();
glEndConditionalRender_ptr glEndConditionalRender_proc = nullptr;

using glVertexAttribIPointer_ptr = void (*)(uint32 index, int32 size, GLenum type, int32 stride, const void* pointer);
glVertexAttribIPointer_ptr glVertexAttribIPointer_proc = nullptr;

using glGetVertexAttribIiv_ptr                     = void (*)(uint32 index, GLenum pname, int32* params);
glGetVertexAttribIiv_ptr glGetVertexAttribIiv_proc = nullptr;

using glGetVertexAttribIuiv_ptr                      = void (*)(uint32 index, GLenum pname, uint32* params);
glGetVertexAttribIuiv_ptr glGetVertexAttribIuiv_proc = nullptr;

using glVertexAttribI1i_ptr                  = void (*)(uint32 index, int32 x);
glVertexAttribI1i_ptr glVertexAttribI1i_proc = nullptr;

using glVertexAttribI2i_ptr                  = void (*)(uint32 index, int32 x, int32 y);
glVertexAttribI2i_ptr glVertexAttribI2i_proc = nullptr;

using glVertexAttribI3i_ptr                  = void (*)(uint32 index, int32 x, int32 y, int32 z);
glVertexAttribI3i_ptr glVertexAttribI3i_proc = nullptr;

using glVertexAttribI4i_ptr                  = void (*)(uint32 index, int32 x, int32 y, int32 z, int32 w);
glVertexAttribI4i_ptr glVertexAttribI4i_proc = nullptr;

using glVertexAttribI1ui_ptr                   = void (*)(uint32 index, uint32 x);
glVertexAttribI1ui_ptr glVertexAttribI1ui_proc = nullptr;

using glVertexAttribI2ui_ptr                   = void (*)(uint32 index, uint32 x, uint32 y);
glVertexAttribI2ui_ptr glVertexAttribI2ui_proc = nullptr;

using glVertexAttribI3ui_ptr                   = void (*)(uint32 index, uint32 x, uint32 y, uint32 z);
glVertexAttribI3ui_ptr glVertexAttribI3ui_proc = nullptr;

using glVertexAttribI4ui_ptr                   = void (*)(uint32 index, uint32 x, uint32 y, uint32 z, uint32 w);
glVertexAttribI4ui_ptr glVertexAttribI4ui_proc = nullptr;

using glVertexAttribI1iv_ptr                   = void (*)(uint32 index, const int32* v);
glVertexAttribI1iv_ptr glVertexAttribI1iv_proc = nullptr;

using glVertexAttribI2iv_ptr                   = void (*)(uint32 index, const int32* v);
glVertexAttribI2iv_ptr glVertexAttribI2iv_proc = nullptr;

using glVertexAttribI3iv_ptr                   = void (*)(uint32 index, const int32* v);
glVertexAttribI3iv_ptr glVertexAttribI3iv_proc = nullptr;

using glVertexAttribI4iv_ptr                   = void (*)(uint32 index, const int32* v);
glVertexAttribI4iv_ptr glVertexAttribI4iv_proc = nullptr;

using glVertexAttribI1uiv_ptr                    = void (*)(uint32 index, const uint32* v);
glVertexAttribI1uiv_ptr glVertexAttribI1uiv_proc = nullptr;

using glVertexAttribI2uiv_ptr                    = void (*)(uint32 index, const uint32* v);
glVertexAttribI2uiv_ptr glVertexAttribI2uiv_proc = nullptr;

using glVertexAttribI3uiv_ptr                    = void (*)(uint32 index, const uint32* v);
glVertexAttribI3uiv_ptr glVertexAttribI3uiv_proc = nullptr;

using glVertexAttribI4uiv_ptr                    = void (*)(uint32 index, const uint32* v);
glVertexAttribI4uiv_ptr glVertexAttribI4uiv_proc = nullptr;

using glVertexAttribI4bv_ptr                   = void (*)(uint32 index, const int8* v);
glVertexAttribI4bv_ptr glVertexAttribI4bv_proc = nullptr;

using glVertexAttribI4sv_ptr                   = void (*)(uint32 index, const int16* v);
glVertexAttribI4sv_ptr glVertexAttribI4sv_proc = nullptr;

using glVertexAttribI4ubv_ptr                    = void (*)(uint32 index, const uint8* v);
glVertexAttribI4ubv_ptr glVertexAttribI4ubv_proc = nullptr;

using glVertexAttribI4usv_ptr                    = void (*)(uint32 index, const uint16* v);
glVertexAttribI4usv_ptr glVertexAttribI4usv_proc = nullptr;

using glGetUniformuiv_ptr                = void (*)(uint32 program, int32 location, uint32* params);
glGetUniformuiv_ptr glGetUniformuiv_proc = nullptr;

using glBindFragDataLocation_ptr                       = void (*)(uint32 program, uint32 color, const char* name);
glBindFragDataLocation_ptr glBindFragDataLocation_proc = nullptr;

using glGetFragDataLocation_ptr                      = int32 (*)(uint32 program, const char* name);
glGetFragDataLocation_ptr glGetFragDataLocation_proc = nullptr;

using glUniform1ui_ptr             = void (*)(int32 location, uint32 v0);
glUniform1ui_ptr glUniform1ui_proc = nullptr;

using glUniform2ui_ptr             = void (*)(int32 location, uint32 v0, uint32 v1);
glUniform2ui_ptr glUniform2ui_proc = nullptr;

using glUniform3ui_ptr             = void (*)(int32 location, uint32 v0, uint32 v1, uint32 v2);
glUniform3ui_ptr glUniform3ui_proc = nullptr;

using glUniform4ui_ptr             = void (*)(int32 location, uint32 v0, uint32 v1, uint32 v2, uint32 v3);
glUniform4ui_ptr glUniform4ui_proc = nullptr;

using glUniform1uiv_ptr              = void (*)(int32 location, int32 count, const uint32* value);
glUniform1uiv_ptr glUniform1uiv_proc = nullptr;

using glUniform2uiv_ptr              = void (*)(int32 location, int32 count, const uint32* value);
glUniform2uiv_ptr glUniform2uiv_proc = nullptr;

using glUniform3uiv_ptr              = void (*)(int32 location, int32 count, const uint32* value);
glUniform3uiv_ptr glUniform3uiv_proc = nullptr;

using glUniform4uiv_ptr              = void (*)(int32 location, int32 count, const uint32* value);
glUniform4uiv_ptr glUniform4uiv_proc = nullptr;

using glTexParameterIiv_ptr                  = void (*)(GLenum target, GLenum pname, const int32* params);
glTexParameterIiv_ptr glTexParameterIiv_proc = nullptr;

using glTexParameterIuiv_ptr                   = void (*)(GLenum target, GLenum pname, const uint32* params);
glTexParameterIuiv_ptr glTexParameterIuiv_proc = nullptr;

using glGetTexParameterIiv_ptr                     = void (*)(GLenum target, GLenum pname, int32* params);
glGetTexParameterIiv_ptr glGetTexParameterIiv_proc = nullptr;

using glGetTexParameterIuiv_ptr                      = void (*)(GLenum target, GLenum pname, uint32* params);
glGetTexParameterIuiv_ptr glGetTexParameterIuiv_proc = nullptr;

using glClearBufferiv_ptr                = void (*)(GLenum buffer, int32 drawbuffer, const int32* value);
glClearBufferiv_ptr glClearBufferiv_proc = nullptr;

using glClearBufferuiv_ptr                 = void (*)(GLenum buffer, int32 drawbuffer, const uint32* value);
glClearBufferuiv_ptr glClearBufferuiv_proc = nullptr;

using glClearBufferfv_ptr                = void (*)(GLenum buffer, int32 drawbuffer, const float32* value);
glClearBufferfv_ptr glClearBufferfv_proc = nullptr;

using glClearBufferfi_ptr                = void (*)(GLenum buffer, int32 drawbuffer, float32 depth, int32 stencil);
glClearBufferfi_ptr glClearBufferfi_proc = nullptr;

using glGetStringi_ptr             = const uint8* (*)(GLenum name, uint32 index);
glGetStringi_ptr glGetStringi_proc = nullptr;

using glIsRenderbuffer_ptr                 = bool (*)(uint32 renderbuffer);
glIsRenderbuffer_ptr glIsRenderbuffer_proc = nullptr;

using glBindRenderbuffer_ptr                   = void (*)(GLenum target, uint32 renderbuffer);
glBindRenderbuffer_ptr glBindRenderbuffer_proc = nullptr;

using glDeleteRenderbuffers_ptr                      = void (*)(int32 n, const uint32* renderbuffers);
glDeleteRenderbuffers_ptr glDeleteRenderbuffers_proc = nullptr;

using glGenRenderbuffers_ptr                   = void (*)(int32 n, uint32* renderbuffers);
glGenRenderbuffers_ptr glGenRenderbuffers_proc = nullptr;

using glRenderbufferStorage_ptr = void (*)(GLenum target, GLenum internalformat, int32 width, int32 height);
glRenderbufferStorage_ptr glRenderbufferStorage_proc = nullptr;

using glGetRenderbufferParameteriv_ptr = void (*)(GLenum target, GLenum pname, int32* params);
glGetRenderbufferParameteriv_ptr glGetRenderbufferParameteriv_proc = nullptr;

using glIsFramebuffer_ptr                = bool (*)(uint32 framebuffer);
glIsFramebuffer_ptr glIsFramebuffer_proc = nullptr;

using glBindFramebuffer_ptr                  = void (*)(GLenum target, uint32 framebuffer);
glBindFramebuffer_ptr glBindFramebuffer_proc = nullptr;

using glDeleteFramebuffers_ptr                     = void (*)(int32 n, const uint32* framebuffers);
glDeleteFramebuffers_ptr glDeleteFramebuffers_proc = nullptr;

using glGenFramebuffers_ptr                  = void (*)(int32 n, uint32* framebuffers);
glGenFramebuffers_ptr glGenFramebuffers_proc = nullptr;

using glCheckFramebufferStatus_ptr                         = GLenum (*)(GLenum target);
glCheckFramebufferStatus_ptr glCheckFramebufferStatus_proc = nullptr;

using glFramebufferTexture1D_ptr =
void (*)(GLenum target, GLenum attachment, GLenum textarget, uint32 texture, int32 level);
glFramebufferTexture1D_ptr glFramebufferTexture1D_proc = nullptr;

using glFramebufferTexture2D_ptr =
void (*)(GLenum target, GLenum attachment, GLenum textarget, uint32 texture, int32 level);
glFramebufferTexture2D_ptr glFramebufferTexture2D_proc = nullptr;

using glFramebufferTexture3D_ptr =
void (*)(GLenum target, GLenum attachment, GLenum textarget, uint32 texture, int32 level, int32 zoffset);
glFramebufferTexture3D_ptr glFramebufferTexture3D_proc = nullptr;

using glFramebufferRenderbuffer_ptr                          = void (*)(GLenum target,
                                               GLenum attachment,
                                               GLenum renderbuffertarget,
                                               uint32 renderbuffer);
glFramebufferRenderbuffer_ptr glFramebufferRenderbuffer_proc = nullptr;

using glGetFramebufferAttachmentParameteriv_ptr                                      = void (*)(GLenum target,
                                                           GLenum attachment,
                                                           GLenum pname,
                                                           int32* params);
glGetFramebufferAttachmentParameteriv_ptr glGetFramebufferAttachmentParameteriv_proc = nullptr;

using glGenerateMipmap_ptr                 = void (*)(GLenum target);
glGenerateMipmap_ptr glGenerateMipmap_proc = nullptr;

using glBlitFramebuffer_ptr                  = void (*)(int32 srcX0,
                                       int32 srcY0,
                                       int32 srcX1,
                                       int32 srcY1,
                                       int32 dstX0,
                                       int32 dstY0,
                                       int32 dstX1,
                                       int32 dstY1,
                                       uint32 mask,
                                       GLenum filter);
glBlitFramebuffer_ptr glBlitFramebuffer_proc = nullptr;

using glRenderbufferStorageMultisample_ptr =
void (*)(GLenum target, int32 samples, GLenum internalformat, int32 width, int32 height);
glRenderbufferStorageMultisample_ptr glRenderbufferStorageMultisample_proc = nullptr;

using glFramebufferTextureLayer_ptr =
void (*)(GLenum target, GLenum attachment, uint32 texture, int32 level, int32 layer);
glFramebufferTextureLayer_ptr glFramebufferTextureLayer_proc = nullptr;

using glMapBufferRange_ptr                 = void* (*)(GLenum target, ptrdiff offset, ptrdiff length, uint32 access);
glMapBufferRange_ptr glMapBufferRange_proc = nullptr;

using glFlushMappedBufferRange_ptr                         = void (*)(GLenum target, ptrdiff offset, ptrdiff length);
glFlushMappedBufferRange_ptr glFlushMappedBufferRange_proc = nullptr;

using glBindVertexArray_ptr                  = void (*)(uint32 array);
glBindVertexArray_ptr glBindVertexArray_proc = nullptr;

using glDeleteVertexArrays_ptr                     = void (*)(int32 n, const uint32* arrays);
glDeleteVertexArrays_ptr glDeleteVertexArrays_proc = nullptr;

using glGenVertexArrays_ptr                  = void (*)(int32 n, uint32* arrays);
glGenVertexArrays_ptr glGenVertexArrays_proc = nullptr;

using glIsVertexArray_ptr                = bool (*)(uint32 array);
glIsVertexArray_ptr glIsVertexArray_proc = nullptr;

bool init_gl_version_3_0()
{
    using ::framework::graphic::utils::get_function;

    bool result = true;

    result = result && (glColorMaski_proc = get_function<glColorMaski_ptr>("glColorMaski")) != nullptr;
    result = result && (glGetBooleani_v_proc = get_function<glGetBooleani_v_ptr>("glGetBooleani_v")) != nullptr;
    result = result && (glGetIntegeri_v_proc = get_function<glGetIntegeri_v_ptr>("glGetIntegeri_v")) != nullptr;
    result = result && (glEnablei_proc = get_function<glEnablei_ptr>("glEnablei")) != nullptr;
    result = result && (glDisablei_proc = get_function<glDisablei_ptr>("glDisablei")) != nullptr;
    result = result && (glIsEnabledi_proc = get_function<glIsEnabledi_ptr>("glIsEnabledi")) != nullptr;
    result = result &&
             (glBeginTransformFeedback_proc = get_function<glBeginTransformFeedback_ptr>("glBeginTransformFeedback")) !=
             nullptr;
    result = result &&
             (glEndTransformFeedback_proc = get_function<glEndTransformFeedback_ptr>("glEndTransformFeedback")) !=
             nullptr;
    result = result && (glBindBufferRange_proc = get_function<glBindBufferRange_ptr>("glBindBufferRange")) != nullptr;
    result = result && (glBindBufferBase_proc = get_function<glBindBufferBase_ptr>("glBindBufferBase")) != nullptr;
    result = result && (glTransformFeedbackVaryings_proc = get_function<glTransformFeedbackVaryings_ptr>(
                        "glTransformFeedbackVaryings")) != nullptr;
    result = result && (glGetTransformFeedbackVarying_proc = get_function<glGetTransformFeedbackVarying_ptr>(
                        "glGetTransformFeedbackVarying")) != nullptr;
    result = result && (glClampColor_proc = get_function<glClampColor_ptr>("glClampColor")) != nullptr;
    result = result &&
             (glBeginConditionalRender_proc = get_function<glBeginConditionalRender_ptr>("glBeginConditionalRender")) !=
             nullptr;
    result = result &&
             (glEndConditionalRender_proc = get_function<glEndConditionalRender_ptr>("glEndConditionalRender")) !=
             nullptr;
    result = result &&
             (glVertexAttribIPointer_proc = get_function<glVertexAttribIPointer_ptr>("glVertexAttribIPointer")) !=
             nullptr;
    result = result &&
             (glGetVertexAttribIiv_proc = get_function<glGetVertexAttribIiv_ptr>("glGetVertexAttribIiv")) != nullptr;
    result = result &&
             (glGetVertexAttribIuiv_proc = get_function<glGetVertexAttribIuiv_ptr>("glGetVertexAttribIuiv")) != nullptr;
    result = result && (glVertexAttribI1i_proc = get_function<glVertexAttribI1i_ptr>("glVertexAttribI1i")) != nullptr;
    result = result && (glVertexAttribI2i_proc = get_function<glVertexAttribI2i_ptr>("glVertexAttribI2i")) != nullptr;
    result = result && (glVertexAttribI3i_proc = get_function<glVertexAttribI3i_ptr>("glVertexAttribI3i")) != nullptr;
    result = result && (glVertexAttribI4i_proc = get_function<glVertexAttribI4i_ptr>("glVertexAttribI4i")) != nullptr;
    result = result &&
             (glVertexAttribI1ui_proc = get_function<glVertexAttribI1ui_ptr>("glVertexAttribI1ui")) != nullptr;
    result = result &&
             (glVertexAttribI2ui_proc = get_function<glVertexAttribI2ui_ptr>("glVertexAttribI2ui")) != nullptr;
    result = result &&
             (glVertexAttribI3ui_proc = get_function<glVertexAttribI3ui_ptr>("glVertexAttribI3ui")) != nullptr;
    result = result &&
             (glVertexAttribI4ui_proc = get_function<glVertexAttribI4ui_ptr>("glVertexAttribI4ui")) != nullptr;
    result = result &&
             (glVertexAttribI1iv_proc = get_function<glVertexAttribI1iv_ptr>("glVertexAttribI1iv")) != nullptr;
    result = result &&
             (glVertexAttribI2iv_proc = get_function<glVertexAttribI2iv_ptr>("glVertexAttribI2iv")) != nullptr;
    result = result &&
             (glVertexAttribI3iv_proc = get_function<glVertexAttribI3iv_ptr>("glVertexAttribI3iv")) != nullptr;
    result = result &&
             (glVertexAttribI4iv_proc = get_function<glVertexAttribI4iv_ptr>("glVertexAttribI4iv")) != nullptr;
    result = result &&
             (glVertexAttribI1uiv_proc = get_function<glVertexAttribI1uiv_ptr>("glVertexAttribI1uiv")) != nullptr;
    result = result &&
             (glVertexAttribI2uiv_proc = get_function<glVertexAttribI2uiv_ptr>("glVertexAttribI2uiv")) != nullptr;
    result = result &&
             (glVertexAttribI3uiv_proc = get_function<glVertexAttribI3uiv_ptr>("glVertexAttribI3uiv")) != nullptr;
    result = result &&
             (glVertexAttribI4uiv_proc = get_function<glVertexAttribI4uiv_ptr>("glVertexAttribI4uiv")) != nullptr;
    result = result &&
             (glVertexAttribI4bv_proc = get_function<glVertexAttribI4bv_ptr>("glVertexAttribI4bv")) != nullptr;
    result = result &&
             (glVertexAttribI4sv_proc = get_function<glVertexAttribI4sv_ptr>("glVertexAttribI4sv")) != nullptr;
    result = result &&
             (glVertexAttribI4ubv_proc = get_function<glVertexAttribI4ubv_ptr>("glVertexAttribI4ubv")) != nullptr;
    result = result &&
             (glVertexAttribI4usv_proc = get_function<glVertexAttribI4usv_ptr>("glVertexAttribI4usv")) != nullptr;
    result = result && (glGetUniformuiv_proc = get_function<glGetUniformuiv_ptr>("glGetUniformuiv")) != nullptr;
    result = result &&
             (glBindFragDataLocation_proc = get_function<glBindFragDataLocation_ptr>("glBindFragDataLocation")) !=
             nullptr;
    result = result &&
             (glGetFragDataLocation_proc = get_function<glGetFragDataLocation_ptr>("glGetFragDataLocation")) != nullptr;
    result = result && (glUniform1ui_proc = get_function<glUniform1ui_ptr>("glUniform1ui")) != nullptr;
    result = result && (glUniform2ui_proc = get_function<glUniform2ui_ptr>("glUniform2ui")) != nullptr;
    result = result && (glUniform3ui_proc = get_function<glUniform3ui_ptr>("glUniform3ui")) != nullptr;
    result = result && (glUniform4ui_proc = get_function<glUniform4ui_ptr>("glUniform4ui")) != nullptr;
    result = result && (glUniform1uiv_proc = get_function<glUniform1uiv_ptr>("glUniform1uiv")) != nullptr;
    result = result && (glUniform2uiv_proc = get_function<glUniform2uiv_ptr>("glUniform2uiv")) != nullptr;
    result = result && (glUniform3uiv_proc = get_function<glUniform3uiv_ptr>("glUniform3uiv")) != nullptr;
    result = result && (glUniform4uiv_proc = get_function<glUniform4uiv_ptr>("glUniform4uiv")) != nullptr;
    result = result && (glTexParameterIiv_proc = get_function<glTexParameterIiv_ptr>("glTexParameterIiv")) != nullptr;
    result = result &&
             (glTexParameterIuiv_proc = get_function<glTexParameterIuiv_ptr>("glTexParameterIuiv")) != nullptr;
    result = result &&
             (glGetTexParameterIiv_proc = get_function<glGetTexParameterIiv_ptr>("glGetTexParameterIiv")) != nullptr;
    result = result &&
             (glGetTexParameterIuiv_proc = get_function<glGetTexParameterIuiv_ptr>("glGetTexParameterIuiv")) != nullptr;
    result = result && (glClearBufferiv_proc = get_function<glClearBufferiv_ptr>("glClearBufferiv")) != nullptr;
    result = result && (glClearBufferuiv_proc = get_function<glClearBufferuiv_ptr>("glClearBufferuiv")) != nullptr;
    result = result && (glClearBufferfv_proc = get_function<glClearBufferfv_ptr>("glClearBufferfv")) != nullptr;
    result = result && (glClearBufferfi_proc = get_function<glClearBufferfi_ptr>("glClearBufferfi")) != nullptr;
    result = result && (glGetStringi_proc = get_function<glGetStringi_ptr>("glGetStringi")) != nullptr;
    result = result && (glIsRenderbuffer_proc = get_function<glIsRenderbuffer_ptr>("glIsRenderbuffer")) != nullptr;
    result = result &&
             (glBindRenderbuffer_proc = get_function<glBindRenderbuffer_ptr>("glBindRenderbuffer")) != nullptr;
    result = result &&
             (glDeleteRenderbuffers_proc = get_function<glDeleteRenderbuffers_ptr>("glDeleteRenderbuffers")) != nullptr;
    result = result &&
             (glGenRenderbuffers_proc = get_function<glGenRenderbuffers_ptr>("glGenRenderbuffers")) != nullptr;
    result = result &&
             (glRenderbufferStorage_proc = get_function<glRenderbufferStorage_ptr>("glRenderbufferStorage")) != nullptr;
    result = result && (glGetRenderbufferParameteriv_proc = get_function<glGetRenderbufferParameteriv_ptr>(
                        "glGetRenderbufferParameteriv")) != nullptr;
    result = result && (glIsFramebuffer_proc = get_function<glIsFramebuffer_ptr>("glIsFramebuffer")) != nullptr;
    result = result && (glBindFramebuffer_proc = get_function<glBindFramebuffer_ptr>("glBindFramebuffer")) != nullptr;
    result = result &&
             (glDeleteFramebuffers_proc = get_function<glDeleteFramebuffers_ptr>("glDeleteFramebuffers")) != nullptr;
    result = result && (glGenFramebuffers_proc = get_function<glGenFramebuffers_ptr>("glGenFramebuffers")) != nullptr;
    result = result &&
             (glCheckFramebufferStatus_proc = get_function<glCheckFramebufferStatus_ptr>("glCheckFramebufferStatus")) !=
             nullptr;
    result = result &&
             (glFramebufferTexture1D_proc = get_function<glFramebufferTexture1D_ptr>("glFramebufferTexture1D")) !=
             nullptr;
    result = result &&
             (glFramebufferTexture2D_proc = get_function<glFramebufferTexture2D_ptr>("glFramebufferTexture2D")) !=
             nullptr;
    result = result &&
             (glFramebufferTexture3D_proc = get_function<glFramebufferTexture3D_ptr>("glFramebufferTexture3D")) !=
             nullptr;
    result = result && (glFramebufferRenderbuffer_proc = get_function<glFramebufferRenderbuffer_ptr>(
                        "glFramebufferRenderbuffer")) != nullptr;
    result = result &&
             (glGetFramebufferAttachmentParameteriv_proc = get_function<glGetFramebufferAttachmentParameteriv_ptr>(
              "glGetFramebufferAttachmentParameteriv")) != nullptr;
    result = result && (glGenerateMipmap_proc = get_function<glGenerateMipmap_ptr>("glGenerateMipmap")) != nullptr;
    result = result && (glBlitFramebuffer_proc = get_function<glBlitFramebuffer_ptr>("glBlitFramebuffer")) != nullptr;
    result = result && (glRenderbufferStorageMultisample_proc = get_function<glRenderbufferStorageMultisample_ptr>(
                        "glRenderbufferStorageMultisample")) != nullptr;
    result = result && (glFramebufferTextureLayer_proc = get_function<glFramebufferTextureLayer_ptr>(
                        "glFramebufferTextureLayer")) != nullptr;
    result = result && (glMapBufferRange_proc = get_function<glMapBufferRange_ptr>("glMapBufferRange")) != nullptr;
    result = result &&
             (glFlushMappedBufferRange_proc = get_function<glFlushMappedBufferRange_ptr>("glFlushMappedBufferRange")) !=
             nullptr;
    result = result && (glBindVertexArray_proc = get_function<glBindVertexArray_ptr>("glBindVertexArray")) != nullptr;
    result = result &&
             (glDeleteVertexArrays_proc = get_function<glDeleteVertexArrays_ptr>("glDeleteVertexArrays")) != nullptr;
    result = result && (glGenVertexArrays_proc = get_function<glGenVertexArrays_ptr>("glGenVertexArrays")) != nullptr;
    result = result && (glIsVertexArray_proc = get_function<glIsVertexArray_ptr>("glIsVertexArray")) != nullptr;

    return result;
}

#pragma endregion

#pragma region gl_version_3_1

using glDrawArraysInstanced_ptr = void (*)(GLenum mode, int32 first, int32 count, int32 instancecount);
glDrawArraysInstanced_ptr glDrawArraysInstanced_proc = nullptr;

using glDrawElementsInstanced_ptr =
void (*)(GLenum mode, int32 count, GLenum type, const void* indices, int32 instancecount);
glDrawElementsInstanced_ptr glDrawElementsInstanced_proc = nullptr;

using glTexBuffer_ptr            = void (*)(GLenum target, GLenum internalformat, uint32 buffer);
glTexBuffer_ptr glTexBuffer_proc = nullptr;

using glPrimitiveRestartIndex_ptr                        = void (*)(uint32 index);
glPrimitiveRestartIndex_ptr glPrimitiveRestartIndex_proc = nullptr;

using glCopyBufferSubData_ptr =
void (*)(GLenum readTarget, GLenum writeTarget, ptrdiff readOffset, ptrdiff writeOffset, ptrdiff size);
glCopyBufferSubData_ptr glCopyBufferSubData_proc = nullptr;

using glGetUniformIndices_ptr                    = void (*)(uint32 program,
                                         int32 uniformCount,
                                         const char* const* uniformNames,
                                         uint32* uniformIndices);
glGetUniformIndices_ptr glGetUniformIndices_proc = nullptr;

using glGetActiveUniformsiv_ptr =
void (*)(uint32 program, int32 uniformCount, const uint32* uniformIndices, GLenum pname, int32* params);
glGetActiveUniformsiv_ptr glGetActiveUniformsiv_proc = nullptr;

using glGetActiveUniformName_ptr =
void (*)(uint32 program, uint32 uniformIndex, int32 bufSize, int32* length, char* uniformName);
glGetActiveUniformName_ptr glGetActiveUniformName_proc = nullptr;

using glGetUniformBlockIndex_ptr                       = uint32 (*)(uint32 program, const char* uniformBlockName);
glGetUniformBlockIndex_ptr glGetUniformBlockIndex_proc = nullptr;

using glGetActiveUniformBlockiv_ptr = void (*)(uint32 program, uint32 uniformBlockIndex, GLenum pname, int32* params);
glGetActiveUniformBlockiv_ptr glGetActiveUniformBlockiv_proc = nullptr;

using glGetActiveUniformBlockName_ptr =
void (*)(uint32 program, uint32 uniformBlockIndex, int32 bufSize, int32* length, char* uniformBlockName);
glGetActiveUniformBlockName_ptr glGetActiveUniformBlockName_proc = nullptr;

using glUniformBlockBinding_ptr = void (*)(uint32 program, uint32 uniformBlockIndex, uint32 uniformBlockBinding);
glUniformBlockBinding_ptr glUniformBlockBinding_proc = nullptr;

bool init_gl_version_3_1()
{
    using ::framework::graphic::utils::get_function;

    bool result = true;

    result = result &&
             (glDrawArraysInstanced_proc = get_function<glDrawArraysInstanced_ptr>("glDrawArraysInstanced")) != nullptr;
    result = result &&
             (glDrawElementsInstanced_proc = get_function<glDrawElementsInstanced_ptr>("glDrawElementsInstanced")) !=
             nullptr;
    result = result && (glTexBuffer_proc = get_function<glTexBuffer_ptr>("glTexBuffer")) != nullptr;
    result = result &&
             (glPrimitiveRestartIndex_proc = get_function<glPrimitiveRestartIndex_ptr>("glPrimitiveRestartIndex")) !=
             nullptr;
    result = result &&
             (glCopyBufferSubData_proc = get_function<glCopyBufferSubData_ptr>("glCopyBufferSubData")) != nullptr;
    result = result &&
             (glGetUniformIndices_proc = get_function<glGetUniformIndices_ptr>("glGetUniformIndices")) != nullptr;
    result = result &&
             (glGetActiveUniformsiv_proc = get_function<glGetActiveUniformsiv_ptr>("glGetActiveUniformsiv")) != nullptr;
    result = result &&
             (glGetActiveUniformName_proc = get_function<glGetActiveUniformName_ptr>("glGetActiveUniformName")) !=
             nullptr;
    result = result &&
             (glGetUniformBlockIndex_proc = get_function<glGetUniformBlockIndex_ptr>("glGetUniformBlockIndex")) !=
             nullptr;
    result = result && (glGetActiveUniformBlockiv_proc = get_function<glGetActiveUniformBlockiv_ptr>(
                        "glGetActiveUniformBlockiv")) != nullptr;
    result = result && (glGetActiveUniformBlockName_proc = get_function<glGetActiveUniformBlockName_ptr>(
                        "glGetActiveUniformBlockName")) != nullptr;
    result = result &&
             (glUniformBlockBinding_proc = get_function<glUniformBlockBinding_ptr>("glUniformBlockBinding")) != nullptr;

    return result;
}

#pragma endregion

#pragma region gl_versoin_3_2

using GLsync = ::framework::graphic::gl::GLsync;

using glDrawElementsBaseVertex_ptr =
void (*)(GLenum mode, int32 count, GLenum type, const void* indices, int32 basevertex);
glDrawElementsBaseVertex_ptr glDrawElementsBaseVertex_proc = nullptr;

using glDrawRangeElementsBaseVertex_ptr =
void (*)(GLenum mode, uint32 start, uint32 end, int32 count, GLenum type, const void* indices, int32 basevertex);
glDrawRangeElementsBaseVertex_ptr glDrawRangeElementsBaseVertex_proc = nullptr;

using glDrawElementsInstancedBaseVertex_ptr =
void (*)(GLenum mode, int32 count, GLenum type, const void* indices, int32 instancecount, int32 basevertex);
glDrawElementsInstancedBaseVertex_ptr glDrawElementsInstancedBaseVertex_proc = nullptr;

using glMultiDrawElementsBaseVertex_ptr                              = void (*)(GLenum mode,
                                                   const int32* count,
                                                   GLenum type,
                                                   const void* const* indices,
                                                   int32 drawcount,
                                                   const int32* basevertex);
glMultiDrawElementsBaseVertex_ptr glMultiDrawElementsBaseVertex_proc = nullptr;

using glProvokingVertex_ptr                  = void (*)(GLenum mode);
glProvokingVertex_ptr glProvokingVertex_proc = nullptr;

using glFenceSync_ptr            = GLsync (*)(GLenum condition, uint32 flags);
glFenceSync_ptr glFenceSync_proc = nullptr;

using glIsSync_ptr         = bool (*)(GLsync sync);
glIsSync_ptr glIsSync_proc = nullptr;

using glDeleteSync_ptr             = void (*)(GLsync sync);
glDeleteSync_ptr glDeleteSync_proc = nullptr;

using glClientWaitSync_ptr                 = GLenum (*)(GLsync sync, uint32 flags, uint64 timeout);
glClientWaitSync_ptr glClientWaitSync_proc = nullptr;

using glWaitSync_ptr           = void (*)(GLsync sync, uint32 flags, uint64 timeout);
glWaitSync_ptr glWaitSync_proc = nullptr;

using glGetInteger64v_ptr                = void (*)(GLenum pname, int64* data);
glGetInteger64v_ptr glGetInteger64v_proc = nullptr;

using glGetSynciv_ptr            = void (*)(GLsync sync, GLenum pname, int32 bufSize, int32* length, int32* values);
glGetSynciv_ptr glGetSynciv_proc = nullptr;

using glGetInteger64i_v_ptr                  = void (*)(GLenum target, uint32 index, int64* data);
glGetInteger64i_v_ptr glGetInteger64i_v_proc = nullptr;

using glGetBufferParameteri64v_ptr                         = void (*)(GLenum target, GLenum pname, int64* params);
glGetBufferParameteri64v_ptr glGetBufferParameteri64v_proc = nullptr;

using glFramebufferTexture_ptr = void (*)(GLenum target, GLenum attachment, uint32 texture, int32 level);
glFramebufferTexture_ptr glFramebufferTexture_proc = nullptr;

using glTexImage2DMultisample_ptr =
void (*)(GLenum target, int32 samples, GLenum internalformat, int32 width, int32 height, bool fixedsamplelocations);
glTexImage2DMultisample_ptr glTexImage2DMultisample_proc = nullptr;

using glTexImage3DMultisample_ptr                        = void (*)(GLenum target,
                                             int32 samples,
                                             GLenum internalformat,
                                             int32 width,
                                             int32 height,
                                             int32 depth,
                                             bool fixedsamplelocations);
glTexImage3DMultisample_ptr glTexImage3DMultisample_proc = nullptr;

using glGetMultisamplefv_ptr                   = void (*)(GLenum pname, uint32 index, float32* val);
glGetMultisamplefv_ptr glGetMultisamplefv_proc = nullptr;

using glSampleMaski_ptr              = void (*)(uint32 maskNumber, uint32 mask);
glSampleMaski_ptr glSampleMaski_proc = nullptr;

bool init_gl_version_3_2()
{
    using ::framework::graphic::utils::get_function;

    bool result = true;

    result = result &&
             (glDrawElementsBaseVertex_proc = get_function<glDrawElementsBaseVertex_ptr>("glDrawElementsBaseVertex")) !=
             nullptr;
    result = result && (glDrawRangeElementsBaseVertex_proc = get_function<glDrawRangeElementsBaseVertex_ptr>(
                        "glDrawRangeElementsBaseVertex")) != nullptr;
    result = result && (glDrawElementsInstancedBaseVertex_proc = get_function<glDrawElementsInstancedBaseVertex_ptr>(
                        "glDrawElementsInstancedBaseVertex")) != nullptr;
    result = result && (glMultiDrawElementsBaseVertex_proc = get_function<glMultiDrawElementsBaseVertex_ptr>(
                        "glMultiDrawElementsBaseVertex")) != nullptr;
    result = result && (glProvokingVertex_proc = get_function<glProvokingVertex_ptr>("glProvokingVertex")) != nullptr;
    result = result && (glFenceSync_proc = get_function<glFenceSync_ptr>("glFenceSync")) != nullptr;
    result = result && (glIsSync_proc = get_function<glIsSync_ptr>("glIsSync")) != nullptr;
    result = result && (glDeleteSync_proc = get_function<glDeleteSync_ptr>("glDeleteSync")) != nullptr;
    result = result && (glClientWaitSync_proc = get_function<glClientWaitSync_ptr>("glClientWaitSync")) != nullptr;
    result = result && (glWaitSync_proc = get_function<glWaitSync_ptr>("glWaitSync")) != nullptr;
    result = result && (glGetInteger64v_proc = get_function<glGetInteger64v_ptr>("glGetInteger64v")) != nullptr;
    result = result && (glGetSynciv_proc = get_function<glGetSynciv_ptr>("glGetSynciv")) != nullptr;
    result = result && (glGetInteger64i_v_proc = get_function<glGetInteger64i_v_ptr>("glGetInteger64i_v")) != nullptr;
    result = result &&
             (glGetBufferParameteri64v_proc = get_function<glGetBufferParameteri64v_ptr>("glGetBufferParameteri64v")) !=
             nullptr;
    result = result &&
             (glFramebufferTexture_proc = get_function<glFramebufferTexture_ptr>("glFramebufferTexture")) != nullptr;
    result = result &&
             (glTexImage2DMultisample_proc = get_function<glTexImage2DMultisample_ptr>("glTexImage2DMultisample")) !=
             nullptr;
    result = result &&
             (glTexImage3DMultisample_proc = get_function<glTexImage3DMultisample_ptr>("glTexImage3DMultisample")) !=
             nullptr;
    result = result &&
             (glGetMultisamplefv_proc = get_function<glGetMultisamplefv_ptr>("glGetMultisamplefv")) != nullptr;
    result = result && (glSampleMaski_proc = get_function<glSampleMaski_ptr>("glSampleMaski")) != nullptr;

    return result;
}

#pragma endregion

#pragma region gl_version_3_3

using glBindFragDataLocationIndexed_ptr = void (*)(uint32 program, uint32 colorNumber, uint32 index, const char* name);
glBindFragDataLocationIndexed_ptr glBindFragDataLocationIndexed_proc = nullptr;

using glGetFragDataIndex_ptr                   = int32 (*)(uint32 program, const char* name);
glGetFragDataIndex_ptr glGetFragDataIndex_proc = nullptr;

using glGenSamplers_ptr              = void (*)(int32 count, uint32* samplers);
glGenSamplers_ptr glGenSamplers_proc = nullptr;

using glDeleteSamplers_ptr                 = void (*)(int32 count, const uint32* samplers);
glDeleteSamplers_ptr glDeleteSamplers_proc = nullptr;

using glIsSampler_ptr            = bool (*)(uint32 sampler);
glIsSampler_ptr glIsSampler_proc = nullptr;

using glBindSampler_ptr              = void (*)(uint32 unit, uint32 sampler);
glBindSampler_ptr glBindSampler_proc = nullptr;

using glSamplerParameteri_ptr                    = void (*)(uint32 sampler, GLenum pname, int32 param);
glSamplerParameteri_ptr glSamplerParameteri_proc = nullptr;

using glSamplerParameteriv_ptr                     = void (*)(uint32 sampler, GLenum pname, const int32* param);
glSamplerParameteriv_ptr glSamplerParameteriv_proc = nullptr;

using glSamplerParameterf_ptr                    = void (*)(uint32 sampler, GLenum pname, float32 param);
glSamplerParameterf_ptr glSamplerParameterf_proc = nullptr;

using glSamplerParameterfv_ptr                     = void (*)(uint32 sampler, GLenum pname, const float32* param);
glSamplerParameterfv_ptr glSamplerParameterfv_proc = nullptr;

using glSamplerParameterIiv_ptr                      = void (*)(uint32 sampler, GLenum pname, const int32* param);
glSamplerParameterIiv_ptr glSamplerParameterIiv_proc = nullptr;

using glSamplerParameterIuiv_ptr                       = void (*)(uint32 sampler, GLenum pname, const uint32* param);
glSamplerParameterIuiv_ptr glSamplerParameterIuiv_proc = nullptr;

using glGetSamplerParameteriv_ptr                        = void (*)(uint32 sampler, GLenum pname, int32* params);
glGetSamplerParameteriv_ptr glGetSamplerParameteriv_proc = nullptr;

using glGetSamplerParameterIiv_ptr                         = void (*)(uint32 sampler, GLenum pname, int32* params);
glGetSamplerParameterIiv_ptr glGetSamplerParameterIiv_proc = nullptr;

using glGetSamplerParameterfv_ptr                        = void (*)(uint32 sampler, GLenum pname, float32* params);
glGetSamplerParameterfv_ptr glGetSamplerParameterfv_proc = nullptr;

using glGetSamplerParameterIuiv_ptr                          = void (*)(uint32 sampler, GLenum pname, uint32* params);
glGetSamplerParameterIuiv_ptr glGetSamplerParameterIuiv_proc = nullptr;

using glQueryCounter_ptr               = void (*)(uint32 id, GLenum target);
glQueryCounter_ptr glQueryCounter_proc = nullptr;

using glGetQueryObjecti64v_ptr                     = void (*)(uint32 id, GLenum pname, int64* params);
glGetQueryObjecti64v_ptr glGetQueryObjecti64v_proc = nullptr;

using glGetQueryObjectui64v_ptr                      = void (*)(uint32 id, GLenum pname, uint64* params);
glGetQueryObjectui64v_ptr glGetQueryObjectui64v_proc = nullptr;

using glVertexAttribDivisor_ptr                      = void (*)(uint32 index, uint32 divisor);
glVertexAttribDivisor_ptr glVertexAttribDivisor_proc = nullptr;

using glVertexAttribP1ui_ptr                   = void (*)(uint32 index, GLenum type, bool normalized, uint32 value);
glVertexAttribP1ui_ptr glVertexAttribP1ui_proc = nullptr;

using glVertexAttribP1uiv_ptr = void (*)(uint32 index, GLenum type, bool normalized, const uint32* value);
glVertexAttribP1uiv_ptr glVertexAttribP1uiv_proc = nullptr;

using glVertexAttribP2ui_ptr                   = void (*)(uint32 index, GLenum type, bool normalized, uint32 value);
glVertexAttribP2ui_ptr glVertexAttribP2ui_proc = nullptr;

using glVertexAttribP2uiv_ptr = void (*)(uint32 index, GLenum type, bool normalized, const uint32* value);
glVertexAttribP2uiv_ptr glVertexAttribP2uiv_proc = nullptr;

using glVertexAttribP3ui_ptr                   = void (*)(uint32 index, GLenum type, bool normalized, uint32 value);
glVertexAttribP3ui_ptr glVertexAttribP3ui_proc = nullptr;

using glVertexAttribP3uiv_ptr = void (*)(uint32 index, GLenum type, bool normalized, const uint32* value);
glVertexAttribP3uiv_ptr glVertexAttribP3uiv_proc = nullptr;

using glVertexAttribP4ui_ptr                   = void (*)(uint32 index, GLenum type, bool normalized, uint32 value);
glVertexAttribP4ui_ptr glVertexAttribP4ui_proc = nullptr;

using glVertexAttribP4uiv_ptr = void (*)(uint32 index, GLenum type, bool normalized, const uint32* value);
glVertexAttribP4uiv_ptr glVertexAttribP4uiv_proc = nullptr;

bool init_gl_version_3_3()
{
    using ::framework::graphic::utils::get_function;

    bool result = true;

    result = result && (glBindFragDataLocationIndexed_proc = get_function<glBindFragDataLocationIndexed_ptr>(
                        "glBindFragDataLocationIndexed")) != nullptr;
    result = result &&
             (glGetFragDataIndex_proc = get_function<glGetFragDataIndex_ptr>("glGetFragDataIndex")) != nullptr;
    result = result && (glGenSamplers_proc = get_function<glGenSamplers_ptr>("glGenSamplers")) != nullptr;
    result = result && (glDeleteSamplers_proc = get_function<glDeleteSamplers_ptr>("glDeleteSamplers")) != nullptr;
    result = result && (glIsSampler_proc = get_function<glIsSampler_ptr>("glIsSampler")) != nullptr;
    result = result && (glBindSampler_proc = get_function<glBindSampler_ptr>("glBindSampler")) != nullptr;
    result = result &&
             (glSamplerParameteri_proc = get_function<glSamplerParameteri_ptr>("glSamplerParameteri")) != nullptr;
    result = result &&
             (glSamplerParameteriv_proc = get_function<glSamplerParameteriv_ptr>("glSamplerParameteriv")) != nullptr;
    result = result &&
             (glSamplerParameterf_proc = get_function<glSamplerParameterf_ptr>("glSamplerParameterf")) != nullptr;
    result = result &&
             (glSamplerParameterfv_proc = get_function<glSamplerParameterfv_ptr>("glSamplerParameterfv")) != nullptr;
    result = result &&
             (glSamplerParameterIiv_proc = get_function<glSamplerParameterIiv_ptr>("glSamplerParameterIiv")) != nullptr;
    result = result &&
             (glSamplerParameterIuiv_proc = get_function<glSamplerParameterIuiv_ptr>("glSamplerParameterIuiv")) !=
             nullptr;
    result = result &&
             (glGetSamplerParameteriv_proc = get_function<glGetSamplerParameteriv_ptr>("glGetSamplerParameteriv")) !=
             nullptr;
    result = result &&
             (glGetSamplerParameterIiv_proc = get_function<glGetSamplerParameterIiv_ptr>("glGetSamplerParameterIiv")) !=
             nullptr;
    result = result &&
             (glGetSamplerParameterfv_proc = get_function<glGetSamplerParameterfv_ptr>("glGetSamplerParameterfv")) !=
             nullptr;
    result = result && (glGetSamplerParameterIuiv_proc = get_function<glGetSamplerParameterIuiv_ptr>(
                        "glGetSamplerParameterIuiv")) != nullptr;
    result = result && (glQueryCounter_proc = get_function<glQueryCounter_ptr>("glQueryCounter")) != nullptr;
    result = result &&
             (glGetQueryObjecti64v_proc = get_function<glGetQueryObjecti64v_ptr>("glGetQueryObjecti64v")) != nullptr;
    result = result &&
             (glGetQueryObjectui64v_proc = get_function<glGetQueryObjectui64v_ptr>("glGetQueryObjectui64v")) != nullptr;
    result = result &&
             (glVertexAttribDivisor_proc = get_function<glVertexAttribDivisor_ptr>("glVertexAttribDivisor")) != nullptr;
    result = result &&
             (glVertexAttribP1ui_proc = get_function<glVertexAttribP1ui_ptr>("glVertexAttribP1ui")) != nullptr;
    result = result &&
             (glVertexAttribP1uiv_proc = get_function<glVertexAttribP1uiv_ptr>("glVertexAttribP1uiv")) != nullptr;
    result = result &&
             (glVertexAttribP2ui_proc = get_function<glVertexAttribP2ui_ptr>("glVertexAttribP2ui")) != nullptr;
    result = result &&
             (glVertexAttribP2uiv_proc = get_function<glVertexAttribP2uiv_ptr>("glVertexAttribP2uiv")) != nullptr;
    result = result &&
             (glVertexAttribP3ui_proc = get_function<glVertexAttribP3ui_ptr>("glVertexAttribP3ui")) != nullptr;
    result = result &&
             (glVertexAttribP3uiv_proc = get_function<glVertexAttribP3uiv_ptr>("glVertexAttribP3uiv")) != nullptr;
    result = result &&
             (glVertexAttribP4ui_proc = get_function<glVertexAttribP4ui_ptr>("glVertexAttribP4ui")) != nullptr;
    result = result &&
             (glVertexAttribP4uiv_proc = get_function<glVertexAttribP4uiv_ptr>("glVertexAttribP4uiv")) != nullptr;

    return result;
}

#pragma endregion

#pragma region gl_version_4_0

using glMinSampleShading_ptr                   = void (*)(float32 value);
glMinSampleShading_ptr glMinSampleShading_proc = nullptr;

using glBlendEquationi_ptr                 = void (*)(uint32 buf, GLenum mode);
glBlendEquationi_ptr glBlendEquationi_proc = nullptr;

using glBlendEquationSeparatei_ptr                         = void (*)(uint32 buf, GLenum modeRGB, GLenum modeAlpha);
glBlendEquationSeparatei_ptr glBlendEquationSeparatei_proc = nullptr;

using glBlendFunci_ptr             = void (*)(uint32 buf, GLenum src, GLenum dst);
glBlendFunci_ptr glBlendFunci_proc = nullptr;

using glBlendFuncSeparatei_ptr = void (*)(uint32 buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
glBlendFuncSeparatei_ptr glBlendFuncSeparatei_proc = nullptr;

using glDrawArraysIndirect_ptr                     = void (*)(GLenum mode, const void* indirect);
glDrawArraysIndirect_ptr glDrawArraysIndirect_proc = nullptr;

using glDrawElementsIndirect_ptr                       = void (*)(GLenum mode, GLenum type, const void* indirect);
glDrawElementsIndirect_ptr glDrawElementsIndirect_proc = nullptr;

using glUniform1d_ptr            = void (*)(int32 location, float64 x);
glUniform1d_ptr glUniform1d_proc = nullptr;

using glUniform2d_ptr            = void (*)(int32 location, float64 x, float64 y);
glUniform2d_ptr glUniform2d_proc = nullptr;

using glUniform3d_ptr            = void (*)(int32 location, float64 x, float64 y, float64 z);
glUniform3d_ptr glUniform3d_proc = nullptr;

using glUniform4d_ptr            = void (*)(int32 location, float64 x, float64 y, float64 z, float64 w);
glUniform4d_ptr glUniform4d_proc = nullptr;

using glUniform1dv_ptr             = void (*)(int32 location, int32 count, const float64* value);
glUniform1dv_ptr glUniform1dv_proc = nullptr;

using glUniform2dv_ptr             = void (*)(int32 location, int32 count, const float64* value);
glUniform2dv_ptr glUniform2dv_proc = nullptr;

using glUniform3dv_ptr             = void (*)(int32 location, int32 count, const float64* value);
glUniform3dv_ptr glUniform3dv_proc = nullptr;

using glUniform4dv_ptr             = void (*)(int32 location, int32 count, const float64* value);
glUniform4dv_ptr glUniform4dv_proc = nullptr;

using glUniformMatrix2dv_ptr = void (*)(int32 location, int32 count, bool transpose, const float64* value);
glUniformMatrix2dv_ptr glUniformMatrix2dv_proc = nullptr;

using glUniformMatrix3dv_ptr = void (*)(int32 location, int32 count, bool transpose, const float64* value);
glUniformMatrix3dv_ptr glUniformMatrix3dv_proc = nullptr;

using glUniformMatrix4dv_ptr = void (*)(int32 location, int32 count, bool transpose, const float64* value);
glUniformMatrix4dv_ptr glUniformMatrix4dv_proc = nullptr;

using glUniformMatrix2x3dv_ptr = void (*)(int32 location, int32 count, bool transpose, const float64* value);
glUniformMatrix2x3dv_ptr glUniformMatrix2x3dv_proc = nullptr;

using glUniformMatrix2x4dv_ptr = void (*)(int32 location, int32 count, bool transpose, const float64* value);
glUniformMatrix2x4dv_ptr glUniformMatrix2x4dv_proc = nullptr;

using glUniformMatrix3x2dv_ptr = void (*)(int32 location, int32 count, bool transpose, const float64* value);
glUniformMatrix3x2dv_ptr glUniformMatrix3x2dv_proc = nullptr;

using glUniformMatrix3x4dv_ptr = void (*)(int32 location, int32 count, bool transpose, const float64* value);
glUniformMatrix3x4dv_ptr glUniformMatrix3x4dv_proc = nullptr;

using glUniformMatrix4x2dv_ptr = void (*)(int32 location, int32 count, bool transpose, const float64* value);
glUniformMatrix4x2dv_ptr glUniformMatrix4x2dv_proc = nullptr;

using glUniformMatrix4x3dv_ptr = void (*)(int32 location, int32 count, bool transpose, const float64* value);
glUniformMatrix4x3dv_ptr glUniformMatrix4x3dv_proc = nullptr;

using glGetUniformdv_ptr               = void (*)(uint32 program, int32 location, float64* params);
glGetUniformdv_ptr glGetUniformdv_proc = nullptr;

using glGetSubroutineUniformLocation_ptr = int32 (*)(uint32 program, GLenum shadertype, const char* name);
glGetSubroutineUniformLocation_ptr glGetSubroutineUniformLocation_proc = nullptr;

using glGetSubroutineIndex_ptr                     = uint32 (*)(uint32 program, GLenum shadertype, const char* name);
glGetSubroutineIndex_ptr glGetSubroutineIndex_proc = nullptr;

using glGetActiveSubroutineUniformiv_ptr =
void (*)(uint32 program, GLenum shadertype, uint32 index, GLenum pname, int32* values);
glGetActiveSubroutineUniformiv_ptr glGetActiveSubroutineUniformiv_proc = nullptr;

using glGetActiveSubroutineUniformName_ptr =
void (*)(uint32 program, GLenum shadertype, uint32 index, int32 bufsize, int32* length, char* name);
glGetActiveSubroutineUniformName_ptr glGetActiveSubroutineUniformName_proc = nullptr;

using glGetActiveSubroutineName_ptr =
void (*)(uint32 program, GLenum shadertype, uint32 index, int32 bufsize, int32* length, char* name);
glGetActiveSubroutineName_ptr glGetActiveSubroutineName_proc = nullptr;

using glUniformSubroutinesuiv_ptr = void (*)(GLenum shadertype, int32 count, const uint32* indices);
glUniformSubroutinesuiv_ptr glUniformSubroutinesuiv_proc = nullptr;

using glGetUniformSubroutineuiv_ptr = void (*)(GLenum shadertype, int32 location, uint32* params);
glGetUniformSubroutineuiv_ptr glGetUniformSubroutineuiv_proc = nullptr;

using glGetProgramStageiv_ptr = void (*)(uint32 program, GLenum shadertype, GLenum pname, int32* values);
glGetProgramStageiv_ptr glGetProgramStageiv_proc = nullptr;

using glPatchParameteri_ptr                  = void (*)(GLenum pname, int32 value);
glPatchParameteri_ptr glPatchParameteri_proc = nullptr;

using glPatchParameterfv_ptr                   = void (*)(GLenum pname, const float32* values);
glPatchParameterfv_ptr glPatchParameterfv_proc = nullptr;

using glBindTransformFeedback_ptr                        = void (*)(GLenum target, uint32 id);
glBindTransformFeedback_ptr glBindTransformFeedback_proc = nullptr;

using glDeleteTransformFeedbacks_ptr                           = void (*)(int32 n, const uint32* ids);
glDeleteTransformFeedbacks_ptr glDeleteTransformFeedbacks_proc = nullptr;

using glGenTransformFeedbacks_ptr                        = void (*)(int32 n, uint32* ids);
glGenTransformFeedbacks_ptr glGenTransformFeedbacks_proc = nullptr;

using glIsTransformFeedback_ptr                      = bool (*)(uint32 id);
glIsTransformFeedback_ptr glIsTransformFeedback_proc = nullptr;

using glPauseTransformFeedback_ptr                         = void (*)();
glPauseTransformFeedback_ptr glPauseTransformFeedback_proc = nullptr;

using glResumeTransformFeedback_ptr                          = void (*)();
glResumeTransformFeedback_ptr glResumeTransformFeedback_proc = nullptr;

using glDrawTransformFeedback_ptr                        = void (*)(GLenum mode, uint32 id);
glDrawTransformFeedback_ptr glDrawTransformFeedback_proc = nullptr;

using glDrawTransformFeedbackStream_ptr                              = void (*)(GLenum mode, uint32 id, uint32 stream);
glDrawTransformFeedbackStream_ptr glDrawTransformFeedbackStream_proc = nullptr;

using glBeginQueryIndexed_ptr                    = void (*)(GLenum target, uint32 index, uint32 id);
glBeginQueryIndexed_ptr glBeginQueryIndexed_proc = nullptr;

using glEndQueryIndexed_ptr                  = void (*)(GLenum target, uint32 index);
glEndQueryIndexed_ptr glEndQueryIndexed_proc = nullptr;

using glGetQueryIndexediv_ptr                    = void (*)(GLenum target, uint32 index, GLenum pname, int32* params);
glGetQueryIndexediv_ptr glGetQueryIndexediv_proc = nullptr;

bool init_gl_version_4_0()
{
    using ::framework::graphic::utils::get_function;

    bool result = true;

    result = result &&
             (glMinSampleShading_proc = get_function<glMinSampleShading_ptr>("glMinSampleShading")) != nullptr;
    result = result && (glBlendEquationi_proc = get_function<glBlendEquationi_ptr>("glBlendEquationi")) != nullptr;
    result = result &&
             (glBlendEquationSeparatei_proc = get_function<glBlendEquationSeparatei_ptr>("glBlendEquationSeparatei")) !=
             nullptr;
    result = result && (glBlendFunci_proc = get_function<glBlendFunci_ptr>("glBlendFunci")) != nullptr;
    result = result &&
             (glBlendFuncSeparatei_proc = get_function<glBlendFuncSeparatei_ptr>("glBlendFuncSeparatei")) != nullptr;
    result = result &&
             (glDrawArraysIndirect_proc = get_function<glDrawArraysIndirect_ptr>("glDrawArraysIndirect")) != nullptr;
    result = result &&
             (glDrawElementsIndirect_proc = get_function<glDrawElementsIndirect_ptr>("glDrawElementsIndirect")) !=
             nullptr;
    result = result && (glUniform1d_proc = get_function<glUniform1d_ptr>("glUniform1d")) != nullptr;
    result = result && (glUniform2d_proc = get_function<glUniform2d_ptr>("glUniform2d")) != nullptr;
    result = result && (glUniform3d_proc = get_function<glUniform3d_ptr>("glUniform3d")) != nullptr;
    result = result && (glUniform4d_proc = get_function<glUniform4d_ptr>("glUniform4d")) != nullptr;
    result = result && (glUniform1dv_proc = get_function<glUniform1dv_ptr>("glUniform1dv")) != nullptr;
    result = result && (glUniform2dv_proc = get_function<glUniform2dv_ptr>("glUniform2dv")) != nullptr;
    result = result && (glUniform3dv_proc = get_function<glUniform3dv_ptr>("glUniform3dv")) != nullptr;
    result = result && (glUniform4dv_proc = get_function<glUniform4dv_ptr>("glUniform4dv")) != nullptr;
    result = result &&
             (glUniformMatrix2dv_proc = get_function<glUniformMatrix2dv_ptr>("glUniformMatrix2dv")) != nullptr;
    result = result &&
             (glUniformMatrix3dv_proc = get_function<glUniformMatrix3dv_ptr>("glUniformMatrix3dv")) != nullptr;
    result = result &&
             (glUniformMatrix4dv_proc = get_function<glUniformMatrix4dv_ptr>("glUniformMatrix4dv")) != nullptr;
    result = result &&
             (glUniformMatrix2x3dv_proc = get_function<glUniformMatrix2x3dv_ptr>("glUniformMatrix2x3dv")) != nullptr;
    result = result &&
             (glUniformMatrix2x4dv_proc = get_function<glUniformMatrix2x4dv_ptr>("glUniformMatrix2x4dv")) != nullptr;
    result = result &&
             (glUniformMatrix3x2dv_proc = get_function<glUniformMatrix3x2dv_ptr>("glUniformMatrix3x2dv")) != nullptr;
    result = result &&
             (glUniformMatrix3x4dv_proc = get_function<glUniformMatrix3x4dv_ptr>("glUniformMatrix3x4dv")) != nullptr;
    result = result &&
             (glUniformMatrix4x2dv_proc = get_function<glUniformMatrix4x2dv_ptr>("glUniformMatrix4x2dv")) != nullptr;
    result = result &&
             (glUniformMatrix4x3dv_proc = get_function<glUniformMatrix4x3dv_ptr>("glUniformMatrix4x3dv")) != nullptr;
    result = result && (glGetUniformdv_proc = get_function<glGetUniformdv_ptr>("glGetUniformdv")) != nullptr;
    result = result && (glGetSubroutineUniformLocation_proc = get_function<glGetSubroutineUniformLocation_ptr>(
                        "glGetSubroutineUniformLocation")) != nullptr;
    result = result &&
             (glGetSubroutineIndex_proc = get_function<glGetSubroutineIndex_ptr>("glGetSubroutineIndex")) != nullptr;
    result = result && (glGetActiveSubroutineUniformiv_proc = get_function<glGetActiveSubroutineUniformiv_ptr>(
                        "glGetActiveSubroutineUniformiv")) != nullptr;
    result = result && (glGetActiveSubroutineUniformName_proc = get_function<glGetActiveSubroutineUniformName_ptr>(
                        "glGetActiveSubroutineUniformName")) != nullptr;
    result = result && (glGetActiveSubroutineName_proc = get_function<glGetActiveSubroutineName_ptr>(
                        "glGetActiveSubroutineName")) != nullptr;
    result = result &&
             (glUniformSubroutinesuiv_proc = get_function<glUniformSubroutinesuiv_ptr>("glUniformSubroutinesuiv")) !=
             nullptr;
    result = result && (glGetUniformSubroutineuiv_proc = get_function<glGetUniformSubroutineuiv_ptr>(
                        "glGetUniformSubroutineuiv")) != nullptr;
    result = result &&
             (glGetProgramStageiv_proc = get_function<glGetProgramStageiv_ptr>("glGetProgramStageiv")) != nullptr;
    result = result && (glPatchParameteri_proc = get_function<glPatchParameteri_ptr>("glPatchParameteri")) != nullptr;
    result = result &&
             (glPatchParameterfv_proc = get_function<glPatchParameterfv_ptr>("glPatchParameterfv")) != nullptr;
    result = result &&
             (glBindTransformFeedback_proc = get_function<glBindTransformFeedback_ptr>("glBindTransformFeedback")) !=
             nullptr;
    result = result && (glDeleteTransformFeedbacks_proc = get_function<glDeleteTransformFeedbacks_ptr>(
                        "glDeleteTransformFeedbacks")) != nullptr;
    result = result &&
             (glGenTransformFeedbacks_proc = get_function<glGenTransformFeedbacks_ptr>("glGenTransformFeedbacks")) !=
             nullptr;
    result = result &&
             (glIsTransformFeedback_proc = get_function<glIsTransformFeedback_ptr>("glIsTransformFeedback")) != nullptr;
    result = result &&
             (glPauseTransformFeedback_proc = get_function<glPauseTransformFeedback_ptr>("glPauseTransformFeedback")) !=
             nullptr;
    result = result && (glResumeTransformFeedback_proc = get_function<glResumeTransformFeedback_ptr>(
                        "glResumeTransformFeedback")) != nullptr;
    result = result &&
             (glDrawTransformFeedback_proc = get_function<glDrawTransformFeedback_ptr>("glDrawTransformFeedback")) !=
             nullptr;
    result = result && (glDrawTransformFeedbackStream_proc = get_function<glDrawTransformFeedbackStream_ptr>(
                        "glDrawTransformFeedbackStream")) != nullptr;
    result = result &&
             (glBeginQueryIndexed_proc = get_function<glBeginQueryIndexed_ptr>("glBeginQueryIndexed")) != nullptr;
    result = result && (glEndQueryIndexed_proc = get_function<glEndQueryIndexed_ptr>("glEndQueryIndexed")) != nullptr;
    result = result &&
             (glGetQueryIndexediv_proc = get_function<glGetQueryIndexediv_ptr>("glGetQueryIndexediv")) != nullptr;

    return result;
}

#pragma endregion

#pragma region gl_version_4_1

using glReleaseShaderCompiler_ptr                        = void (*)();
glReleaseShaderCompiler_ptr glReleaseShaderCompiler_proc = nullptr;

using glShaderBinary_ptr =
void (*)(int32 count, const uint32* shaders, GLenum binaryformat, const void* binary, int32 length);
glShaderBinary_ptr glShaderBinary_proc = nullptr;

using glGetShaderPrecisionFormat_ptr = void (*)(GLenum shadertype, GLenum precisiontype, int32* range, int32* precision);
glGetShaderPrecisionFormat_ptr glGetShaderPrecisionFormat_proc = nullptr;

using glDepthRangef_ptr              = void (*)(float32 n, float32 f);
glDepthRangef_ptr glDepthRangef_proc = nullptr;

using glClearDepthf_ptr              = void (*)(float32 d);
glClearDepthf_ptr glClearDepthf_proc = nullptr;

using glGetProgramBinary_ptr =
void (*)(uint32 program, int32 bufSize, int32* length, GLenum* binaryFormat, void* binary);
glGetProgramBinary_ptr glGetProgramBinary_proc = nullptr;

using glProgramBinary_ptr = void (*)(uint32 program, GLenum binaryFormat, const void* binary, int32 length);
glProgramBinary_ptr glProgramBinary_proc = nullptr;

using glProgramParameteri_ptr                    = void (*)(uint32 program, GLenum pname, int32 value);
glProgramParameteri_ptr glProgramParameteri_proc = nullptr;

using glUseProgramStages_ptr                   = void (*)(uint32 pipeline, uint32 stages, uint32 program);
glUseProgramStages_ptr glUseProgramStages_proc = nullptr;

using glActiveShaderProgram_ptr                      = void (*)(uint32 pipeline, uint32 program);
glActiveShaderProgram_ptr glActiveShaderProgram_proc = nullptr;

using glCreateShaderProgramv_ptr = uint32 (*)(GLenum type, int32 count, const char* const* strings);
glCreateShaderProgramv_ptr glCreateShaderProgramv_proc = nullptr;

using glBindProgramPipeline_ptr                      = void (*)(uint32 pipeline);
glBindProgramPipeline_ptr glBindProgramPipeline_proc = nullptr;

using glDeleteProgramPipelines_ptr                         = void (*)(int32 n, const uint32* pipelines);
glDeleteProgramPipelines_ptr glDeleteProgramPipelines_proc = nullptr;

using glGenProgramPipelines_ptr                      = void (*)(int32 n, uint32* pipelines);
glGenProgramPipelines_ptr glGenProgramPipelines_proc = nullptr;

using glIsProgramPipeline_ptr                    = bool (*)(uint32 pipeline);
glIsProgramPipeline_ptr glIsProgramPipeline_proc = nullptr;

using glGetProgramPipelineiv_ptr                       = void (*)(uint32 pipeline, GLenum pname, int32* params);
glGetProgramPipelineiv_ptr glGetProgramPipelineiv_proc = nullptr;

using glProgramUniform1i_ptr                   = void (*)(uint32 program, int32 location, int32 v0);
glProgramUniform1i_ptr glProgramUniform1i_proc = nullptr;

using glProgramUniform1iv_ptr = void (*)(uint32 program, int32 location, int32 count, const int32* value);
glProgramUniform1iv_ptr glProgramUniform1iv_proc = nullptr;

using glProgramUniform1f_ptr                   = void (*)(uint32 program, int32 location, float32 v0);
glProgramUniform1f_ptr glProgramUniform1f_proc = nullptr;

using glProgramUniform1fv_ptr = void (*)(uint32 program, int32 location, int32 count, const float32* value);
glProgramUniform1fv_ptr glProgramUniform1fv_proc = nullptr;

using glProgramUniform1d_ptr                   = void (*)(uint32 program, int32 location, float64 v0);
glProgramUniform1d_ptr glProgramUniform1d_proc = nullptr;

using glProgramUniform1dv_ptr = void (*)(uint32 program, int32 location, int32 count, const float64* value);
glProgramUniform1dv_ptr glProgramUniform1dv_proc = nullptr;

using glProgramUniform1ui_ptr                    = void (*)(uint32 program, int32 location, uint32 v0);
glProgramUniform1ui_ptr glProgramUniform1ui_proc = nullptr;

using glProgramUniform1uiv_ptr = void (*)(uint32 program, int32 location, int32 count, const uint32* value);
glProgramUniform1uiv_ptr glProgramUniform1uiv_proc = nullptr;

using glProgramUniform2i_ptr                   = void (*)(uint32 program, int32 location, int32 v0, int32 v1);
glProgramUniform2i_ptr glProgramUniform2i_proc = nullptr;

using glProgramUniform2iv_ptr = void (*)(uint32 program, int32 location, int32 count, const int32* value);
glProgramUniform2iv_ptr glProgramUniform2iv_proc = nullptr;

using glProgramUniform2f_ptr                   = void (*)(uint32 program, int32 location, float32 v0, float32 v1);
glProgramUniform2f_ptr glProgramUniform2f_proc = nullptr;

using glProgramUniform2fv_ptr = void (*)(uint32 program, int32 location, int32 count, const float32* value);
glProgramUniform2fv_ptr glProgramUniform2fv_proc = nullptr;

using glProgramUniform2d_ptr                   = void (*)(uint32 program, int32 location, float64 v0, float64 v1);
glProgramUniform2d_ptr glProgramUniform2d_proc = nullptr;

using glProgramUniform2dv_ptr = void (*)(uint32 program, int32 location, int32 count, const float64* value);
glProgramUniform2dv_ptr glProgramUniform2dv_proc = nullptr;

using glProgramUniform2ui_ptr                    = void (*)(uint32 program, int32 location, uint32 v0, uint32 v1);
glProgramUniform2ui_ptr glProgramUniform2ui_proc = nullptr;

using glProgramUniform2uiv_ptr = void (*)(uint32 program, int32 location, int32 count, const uint32* value);
glProgramUniform2uiv_ptr glProgramUniform2uiv_proc = nullptr;

using glProgramUniform3i_ptr                   = void (*)(uint32 program, int32 location, int32 v0, int32 v1, int32 v2);
glProgramUniform3i_ptr glProgramUniform3i_proc = nullptr;

using glProgramUniform3iv_ptr = void (*)(uint32 program, int32 location, int32 count, const int32* value);
glProgramUniform3iv_ptr glProgramUniform3iv_proc = nullptr;

using glProgramUniform3f_ptr = void (*)(uint32 program, int32 location, float32 v0, float32 v1, float32 v2);
glProgramUniform3f_ptr glProgramUniform3f_proc = nullptr;

using glProgramUniform3fv_ptr = void (*)(uint32 program, int32 location, int32 count, const float32* value);
glProgramUniform3fv_ptr glProgramUniform3fv_proc = nullptr;

using glProgramUniform3d_ptr = void (*)(uint32 program, int32 location, float64 v0, float64 v1, float64 v2);
glProgramUniform3d_ptr glProgramUniform3d_proc = nullptr;

using glProgramUniform3dv_ptr = void (*)(uint32 program, int32 location, int32 count, const float64* value);
glProgramUniform3dv_ptr glProgramUniform3dv_proc = nullptr;

using glProgramUniform3ui_ptr = void (*)(uint32 program, int32 location, uint32 v0, uint32 v1, uint32 v2);
glProgramUniform3ui_ptr glProgramUniform3ui_proc = nullptr;

using glProgramUniform3uiv_ptr = void (*)(uint32 program, int32 location, int32 count, const uint32* value);
glProgramUniform3uiv_ptr glProgramUniform3uiv_proc = nullptr;

using glProgramUniform4i_ptr = void (*)(uint32 program, int32 location, int32 v0, int32 v1, int32 v2, int32 v3);
glProgramUniform4i_ptr glProgramUniform4i_proc = nullptr;

using glProgramUniform4iv_ptr = void (*)(uint32 program, int32 location, int32 count, const int32* value);
glProgramUniform4iv_ptr glProgramUniform4iv_proc = nullptr;

using glProgramUniform4f_ptr = void (*)(uint32 program, int32 location, float32 v0, float32 v1, float32 v2, float32 v3);
glProgramUniform4f_ptr glProgramUniform4f_proc = nullptr;

using glProgramUniform4fv_ptr = void (*)(uint32 program, int32 location, int32 count, const float32* value);
glProgramUniform4fv_ptr glProgramUniform4fv_proc = nullptr;

using glProgramUniform4d_ptr = void (*)(uint32 program, int32 location, float64 v0, float64 v1, float64 v2, float64 v3);
glProgramUniform4d_ptr glProgramUniform4d_proc = nullptr;

using glProgramUniform4dv_ptr = void (*)(uint32 program, int32 location, int32 count, const float64* value);
glProgramUniform4dv_ptr glProgramUniform4dv_proc = nullptr;

using glProgramUniform4ui_ptr = void (*)(uint32 program, int32 location, uint32 v0, uint32 v1, uint32 v2, uint32 v3);
glProgramUniform4ui_ptr glProgramUniform4ui_proc = nullptr;

using glProgramUniform4uiv_ptr = void (*)(uint32 program, int32 location, int32 count, const uint32* value);
glProgramUniform4uiv_ptr glProgramUniform4uiv_proc = nullptr;

using glProgramUniformMatrix2fv_ptr =
void (*)(uint32 program, int32 location, int32 count, bool transpose, const float32* value);
glProgramUniformMatrix2fv_ptr glProgramUniformMatrix2fv_proc = nullptr;

using glProgramUniformMatrix3fv_ptr =
void (*)(uint32 program, int32 location, int32 count, bool transpose, const float32* value);
glProgramUniformMatrix3fv_ptr glProgramUniformMatrix3fv_proc = nullptr;

using glProgramUniformMatrix4fv_ptr =
void (*)(uint32 program, int32 location, int32 count, bool transpose, const float32* value);
glProgramUniformMatrix4fv_ptr glProgramUniformMatrix4fv_proc = nullptr;

using glProgramUniformMatrix2dv_ptr =
void (*)(uint32 program, int32 location, int32 count, bool transpose, const float64* value);
glProgramUniformMatrix2dv_ptr glProgramUniformMatrix2dv_proc = nullptr;

using glProgramUniformMatrix3dv_ptr =
void (*)(uint32 program, int32 location, int32 count, bool transpose, const float64* value);
glProgramUniformMatrix3dv_ptr glProgramUniformMatrix3dv_proc = nullptr;

using glProgramUniformMatrix4dv_ptr =
void (*)(uint32 program, int32 location, int32 count, bool transpose, const float64* value);
glProgramUniformMatrix4dv_ptr glProgramUniformMatrix4dv_proc = nullptr;

using glProgramUniformMatrix2x3fv_ptr =
void (*)(uint32 program, int32 location, int32 count, bool transpose, const float32* value);
glProgramUniformMatrix2x3fv_ptr glProgramUniformMatrix2x3fv_proc = nullptr;

using glProgramUniformMatrix3x2fv_ptr =
void (*)(uint32 program, int32 location, int32 count, bool transpose, const float32* value);
glProgramUniformMatrix3x2fv_ptr glProgramUniformMatrix3x2fv_proc = nullptr;

using glProgramUniformMatrix2x4fv_ptr =
void (*)(uint32 program, int32 location, int32 count, bool transpose, const float32* value);
glProgramUniformMatrix2x4fv_ptr glProgramUniformMatrix2x4fv_proc = nullptr;

using glProgramUniformMatrix4x2fv_ptr =
void (*)(uint32 program, int32 location, int32 count, bool transpose, const float32* value);
glProgramUniformMatrix4x2fv_ptr glProgramUniformMatrix4x2fv_proc = nullptr;

using glProgramUniformMatrix3x4fv_ptr =
void (*)(uint32 program, int32 location, int32 count, bool transpose, const float32* value);
glProgramUniformMatrix3x4fv_ptr glProgramUniformMatrix3x4fv_proc = nullptr;

using glProgramUniformMatrix4x3fv_ptr =
void (*)(uint32 program, int32 location, int32 count, bool transpose, const float32* value);
glProgramUniformMatrix4x3fv_ptr glProgramUniformMatrix4x3fv_proc = nullptr;

using glProgramUniformMatrix2x3dv_ptr =
void (*)(uint32 program, int32 location, int32 count, bool transpose, const float64* value);
glProgramUniformMatrix2x3dv_ptr glProgramUniformMatrix2x3dv_proc = nullptr;

using glProgramUniformMatrix3x2dv_ptr =
void (*)(uint32 program, int32 location, int32 count, bool transpose, const float64* value);
glProgramUniformMatrix3x2dv_ptr glProgramUniformMatrix3x2dv_proc = nullptr;

using glProgramUniformMatrix2x4dv_ptr =
void (*)(uint32 program, int32 location, int32 count, bool transpose, const float64* value);
glProgramUniformMatrix2x4dv_ptr glProgramUniformMatrix2x4dv_proc = nullptr;

using glProgramUniformMatrix4x2dv_ptr =
void (*)(uint32 program, int32 location, int32 count, bool transpose, const float64* value);
glProgramUniformMatrix4x2dv_ptr glProgramUniformMatrix4x2dv_proc = nullptr;

using glProgramUniformMatrix3x4dv_ptr =
void (*)(uint32 program, int32 location, int32 count, bool transpose, const float64* value);
glProgramUniformMatrix3x4dv_ptr glProgramUniformMatrix3x4dv_proc = nullptr;

using glProgramUniformMatrix4x3dv_ptr =
void (*)(uint32 program, int32 location, int32 count, bool transpose, const float64* value);
glProgramUniformMatrix4x3dv_ptr glProgramUniformMatrix4x3dv_proc = nullptr;

using glValidateProgramPipeline_ptr                          = void (*)(uint32 pipeline);
glValidateProgramPipeline_ptr glValidateProgramPipeline_proc = nullptr;

using glGetProgramPipelineInfoLog_ptr = void (*)(uint32 pipeline, int32 bufSize, int32* length, char* infoLog);
glGetProgramPipelineInfoLog_ptr glGetProgramPipelineInfoLog_proc = nullptr;

using glVertexAttribL1d_ptr                  = void (*)(uint32 index, float64 x);
glVertexAttribL1d_ptr glVertexAttribL1d_proc = nullptr;

using glVertexAttribL2d_ptr                  = void (*)(uint32 index, float64 x, float64 y);
glVertexAttribL2d_ptr glVertexAttribL2d_proc = nullptr;

using glVertexAttribL3d_ptr                  = void (*)(uint32 index, float64 x, float64 y, float64 z);
glVertexAttribL3d_ptr glVertexAttribL3d_proc = nullptr;

using glVertexAttribL4d_ptr                  = void (*)(uint32 index, float64 x, float64 y, float64 z, float64 w);
glVertexAttribL4d_ptr glVertexAttribL4d_proc = nullptr;

using glVertexAttribL1dv_ptr                   = void (*)(uint32 index, const float64* v);
glVertexAttribL1dv_ptr glVertexAttribL1dv_proc = nullptr;

using glVertexAttribL2dv_ptr                   = void (*)(uint32 index, const float64* v);
glVertexAttribL2dv_ptr glVertexAttribL2dv_proc = nullptr;

using glVertexAttribL3dv_ptr                   = void (*)(uint32 index, const float64* v);
glVertexAttribL3dv_ptr glVertexAttribL3dv_proc = nullptr;

using glVertexAttribL4dv_ptr                   = void (*)(uint32 index, const float64* v);
glVertexAttribL4dv_ptr glVertexAttribL4dv_proc = nullptr;

using glVertexAttribLPointer_ptr = void (*)(uint32 index, int32 size, GLenum type, int32 stride, const void* pointer);
glVertexAttribLPointer_ptr glVertexAttribLPointer_proc = nullptr;

using glGetVertexAttribLdv_ptr                     = void (*)(uint32 index, GLenum pname, float64* params);
glGetVertexAttribLdv_ptr glGetVertexAttribLdv_proc = nullptr;

using glViewportArrayv_ptr                 = void (*)(uint32 first, int32 count, const float32* v);
glViewportArrayv_ptr glViewportArrayv_proc = nullptr;

using glViewportIndexedf_ptr                   = void (*)(uint32 index, float32 x, float32 y, float32 w, float32 h);
glViewportIndexedf_ptr glViewportIndexedf_proc = nullptr;

using glViewportIndexedfv_ptr                    = void (*)(uint32 index, const float32* v);
glViewportIndexedfv_ptr glViewportIndexedfv_proc = nullptr;

using glScissorArrayv_ptr                = void (*)(uint32 first, int32 count, const int32* v);
glScissorArrayv_ptr glScissorArrayv_proc = nullptr;

using glScissorIndexed_ptr = void (*)(uint32 index, int32 left, int32 bottom, int32 width, int32 height);
glScissorIndexed_ptr glScissorIndexed_proc = nullptr;

using glScissorIndexedv_ptr                  = void (*)(uint32 index, const int32* v);
glScissorIndexedv_ptr glScissorIndexedv_proc = nullptr;

using glDepthRangeArrayv_ptr                   = void (*)(uint32 first, int32 count, const float64* v);
glDepthRangeArrayv_ptr glDepthRangeArrayv_proc = nullptr;

using glDepthRangeIndexed_ptr                    = void (*)(uint32 index, float64 n, float64 f);
glDepthRangeIndexed_ptr glDepthRangeIndexed_proc = nullptr;

using glGetFloati_v_ptr              = void (*)(GLenum target, uint32 index, float32* data);
glGetFloati_v_ptr glGetFloati_v_proc = nullptr;

using glGetDoublei_v_ptr               = void (*)(GLenum target, uint32 index, float64* data);
glGetDoublei_v_ptr glGetDoublei_v_proc = nullptr;

bool init_gl_version_4_1()
{
    using ::framework::graphic::utils::get_function;

    bool result = true;

    result = result &&
             (glReleaseShaderCompiler_proc = get_function<glReleaseShaderCompiler_ptr>("glReleaseShaderCompiler")) !=
             nullptr;
    result = result && (glShaderBinary_proc = get_function<glShaderBinary_ptr>("glShaderBinary")) != nullptr;
    result = result && (glGetShaderPrecisionFormat_proc = get_function<glGetShaderPrecisionFormat_ptr>(
                        "glGetShaderPrecisionFormat")) != nullptr;
    result = result && (glDepthRangef_proc = get_function<glDepthRangef_ptr>("glDepthRangef")) != nullptr;
    result = result && (glClearDepthf_proc = get_function<glClearDepthf_ptr>("glClearDepthf")) != nullptr;
    result = result &&
             (glGetProgramBinary_proc = get_function<glGetProgramBinary_ptr>("glGetProgramBinary")) != nullptr;
    result = result && (glProgramBinary_proc = get_function<glProgramBinary_ptr>("glProgramBinary")) != nullptr;
    result = result &&
             (glProgramParameteri_proc = get_function<glProgramParameteri_ptr>("glProgramParameteri")) != nullptr;
    result = result &&
             (glUseProgramStages_proc = get_function<glUseProgramStages_ptr>("glUseProgramStages")) != nullptr;
    result = result &&
             (glActiveShaderProgram_proc = get_function<glActiveShaderProgram_ptr>("glActiveShaderProgram")) != nullptr;
    result = result &&
             (glCreateShaderProgramv_proc = get_function<glCreateShaderProgramv_ptr>("glCreateShaderProgramv")) !=
             nullptr;
    result = result &&
             (glBindProgramPipeline_proc = get_function<glBindProgramPipeline_ptr>("glBindProgramPipeline")) != nullptr;
    result = result &&
             (glDeleteProgramPipelines_proc = get_function<glDeleteProgramPipelines_ptr>("glDeleteProgramPipelines")) !=
             nullptr;
    result = result &&
             (glGenProgramPipelines_proc = get_function<glGenProgramPipelines_ptr>("glGenProgramPipelines")) != nullptr;
    result = result &&
             (glIsProgramPipeline_proc = get_function<glIsProgramPipeline_ptr>("glIsProgramPipeline")) != nullptr;
    result = result &&
             (glGetProgramPipelineiv_proc = get_function<glGetProgramPipelineiv_ptr>("glGetProgramPipelineiv")) !=
             nullptr;
    result = result &&
             (glProgramUniform1i_proc = get_function<glProgramUniform1i_ptr>("glProgramUniform1i")) != nullptr;
    result = result &&
             (glProgramUniform1iv_proc = get_function<glProgramUniform1iv_ptr>("glProgramUniform1iv")) != nullptr;
    result = result &&
             (glProgramUniform1f_proc = get_function<glProgramUniform1f_ptr>("glProgramUniform1f")) != nullptr;
    result = result &&
             (glProgramUniform1fv_proc = get_function<glProgramUniform1fv_ptr>("glProgramUniform1fv")) != nullptr;
    result = result &&
             (glProgramUniform1d_proc = get_function<glProgramUniform1d_ptr>("glProgramUniform1d")) != nullptr;
    result = result &&
             (glProgramUniform1dv_proc = get_function<glProgramUniform1dv_ptr>("glProgramUniform1dv")) != nullptr;
    result = result &&
             (glProgramUniform1ui_proc = get_function<glProgramUniform1ui_ptr>("glProgramUniform1ui")) != nullptr;
    result = result &&
             (glProgramUniform1uiv_proc = get_function<glProgramUniform1uiv_ptr>("glProgramUniform1uiv")) != nullptr;
    result = result &&
             (glProgramUniform2i_proc = get_function<glProgramUniform2i_ptr>("glProgramUniform2i")) != nullptr;
    result = result &&
             (glProgramUniform2iv_proc = get_function<glProgramUniform2iv_ptr>("glProgramUniform2iv")) != nullptr;
    result = result &&
             (glProgramUniform2f_proc = get_function<glProgramUniform2f_ptr>("glProgramUniform2f")) != nullptr;
    result = result &&
             (glProgramUniform2fv_proc = get_function<glProgramUniform2fv_ptr>("glProgramUniform2fv")) != nullptr;
    result = result &&
             (glProgramUniform2d_proc = get_function<glProgramUniform2d_ptr>("glProgramUniform2d")) != nullptr;
    result = result &&
             (glProgramUniform2dv_proc = get_function<glProgramUniform2dv_ptr>("glProgramUniform2dv")) != nullptr;
    result = result &&
             (glProgramUniform2ui_proc = get_function<glProgramUniform2ui_ptr>("glProgramUniform2ui")) != nullptr;
    result = result &&
             (glProgramUniform2uiv_proc = get_function<glProgramUniform2uiv_ptr>("glProgramUniform2uiv")) != nullptr;
    result = result &&
             (glProgramUniform3i_proc = get_function<glProgramUniform3i_ptr>("glProgramUniform3i")) != nullptr;
    result = result &&
             (glProgramUniform3iv_proc = get_function<glProgramUniform3iv_ptr>("glProgramUniform3iv")) != nullptr;
    result = result &&
             (glProgramUniform3f_proc = get_function<glProgramUniform3f_ptr>("glProgramUniform3f")) != nullptr;
    result = result &&
             (glProgramUniform3fv_proc = get_function<glProgramUniform3fv_ptr>("glProgramUniform3fv")) != nullptr;
    result = result &&
             (glProgramUniform3d_proc = get_function<glProgramUniform3d_ptr>("glProgramUniform3d")) != nullptr;
    result = result &&
             (glProgramUniform3dv_proc = get_function<glProgramUniform3dv_ptr>("glProgramUniform3dv")) != nullptr;
    result = result &&
             (glProgramUniform3ui_proc = get_function<glProgramUniform3ui_ptr>("glProgramUniform3ui")) != nullptr;
    result = result &&
             (glProgramUniform3uiv_proc = get_function<glProgramUniform3uiv_ptr>("glProgramUniform3uiv")) != nullptr;
    result = result &&
             (glProgramUniform4i_proc = get_function<glProgramUniform4i_ptr>("glProgramUniform4i")) != nullptr;
    result = result &&
             (glProgramUniform4iv_proc = get_function<glProgramUniform4iv_ptr>("glProgramUniform4iv")) != nullptr;
    result = result &&
             (glProgramUniform4f_proc = get_function<glProgramUniform4f_ptr>("glProgramUniform4f")) != nullptr;
    result = result &&
             (glProgramUniform4fv_proc = get_function<glProgramUniform4fv_ptr>("glProgramUniform4fv")) != nullptr;
    result = result &&
             (glProgramUniform4d_proc = get_function<glProgramUniform4d_ptr>("glProgramUniform4d")) != nullptr;
    result = result &&
             (glProgramUniform4dv_proc = get_function<glProgramUniform4dv_ptr>("glProgramUniform4dv")) != nullptr;
    result = result &&
             (glProgramUniform4ui_proc = get_function<glProgramUniform4ui_ptr>("glProgramUniform4ui")) != nullptr;
    result = result &&
             (glProgramUniform4uiv_proc = get_function<glProgramUniform4uiv_ptr>("glProgramUniform4uiv")) != nullptr;
    result = result && (glProgramUniformMatrix2fv_proc = get_function<glProgramUniformMatrix2fv_ptr>(
                        "glProgramUniformMatrix2fv")) != nullptr;
    result = result && (glProgramUniformMatrix3fv_proc = get_function<glProgramUniformMatrix3fv_ptr>(
                        "glProgramUniformMatrix3fv")) != nullptr;
    result = result && (glProgramUniformMatrix4fv_proc = get_function<glProgramUniformMatrix4fv_ptr>(
                        "glProgramUniformMatrix4fv")) != nullptr;
    result = result && (glProgramUniformMatrix2dv_proc = get_function<glProgramUniformMatrix2dv_ptr>(
                        "glProgramUniformMatrix2dv")) != nullptr;
    result = result && (glProgramUniformMatrix3dv_proc = get_function<glProgramUniformMatrix3dv_ptr>(
                        "glProgramUniformMatrix3dv")) != nullptr;
    result = result && (glProgramUniformMatrix4dv_proc = get_function<glProgramUniformMatrix4dv_ptr>(
                        "glProgramUniformMatrix4dv")) != nullptr;
    result = result && (glProgramUniformMatrix2x3fv_proc = get_function<glProgramUniformMatrix2x3fv_ptr>(
                        "glProgramUniformMatrix2x3fv")) != nullptr;
    result = result && (glProgramUniformMatrix3x2fv_proc = get_function<glProgramUniformMatrix3x2fv_ptr>(
                        "glProgramUniformMatrix3x2fv")) != nullptr;
    result = result && (glProgramUniformMatrix2x4fv_proc = get_function<glProgramUniformMatrix2x4fv_ptr>(
                        "glProgramUniformMatrix2x4fv")) != nullptr;
    result = result && (glProgramUniformMatrix4x2fv_proc = get_function<glProgramUniformMatrix4x2fv_ptr>(
                        "glProgramUniformMatrix4x2fv")) != nullptr;
    result = result && (glProgramUniformMatrix3x4fv_proc = get_function<glProgramUniformMatrix3x4fv_ptr>(
                        "glProgramUniformMatrix3x4fv")) != nullptr;
    result = result && (glProgramUniformMatrix4x3fv_proc = get_function<glProgramUniformMatrix4x3fv_ptr>(
                        "glProgramUniformMatrix4x3fv")) != nullptr;
    result = result && (glProgramUniformMatrix2x3dv_proc = get_function<glProgramUniformMatrix2x3dv_ptr>(
                        "glProgramUniformMatrix2x3dv")) != nullptr;
    result = result && (glProgramUniformMatrix3x2dv_proc = get_function<glProgramUniformMatrix3x2dv_ptr>(
                        "glProgramUniformMatrix3x2dv")) != nullptr;
    result = result && (glProgramUniformMatrix2x4dv_proc = get_function<glProgramUniformMatrix2x4dv_ptr>(
                        "glProgramUniformMatrix2x4dv")) != nullptr;
    result = result && (glProgramUniformMatrix4x2dv_proc = get_function<glProgramUniformMatrix4x2dv_ptr>(
                        "glProgramUniformMatrix4x2dv")) != nullptr;
    result = result && (glProgramUniformMatrix3x4dv_proc = get_function<glProgramUniformMatrix3x4dv_ptr>(
                        "glProgramUniformMatrix3x4dv")) != nullptr;
    result = result && (glProgramUniformMatrix4x3dv_proc = get_function<glProgramUniformMatrix4x3dv_ptr>(
                        "glProgramUniformMatrix4x3dv")) != nullptr;
    result = result && (glValidateProgramPipeline_proc = get_function<glValidateProgramPipeline_ptr>(
                        "glValidateProgramPipeline")) != nullptr;
    result = result && (glGetProgramPipelineInfoLog_proc = get_function<glGetProgramPipelineInfoLog_ptr>(
                        "glGetProgramPipelineInfoLog")) != nullptr;
    result = result && (glVertexAttribL1d_proc = get_function<glVertexAttribL1d_ptr>("glVertexAttribL1d")) != nullptr;
    result = result && (glVertexAttribL2d_proc = get_function<glVertexAttribL2d_ptr>("glVertexAttribL2d")) != nullptr;
    result = result && (glVertexAttribL3d_proc = get_function<glVertexAttribL3d_ptr>("glVertexAttribL3d")) != nullptr;
    result = result && (glVertexAttribL4d_proc = get_function<glVertexAttribL4d_ptr>("glVertexAttribL4d")) != nullptr;
    result = result &&
             (glVertexAttribL1dv_proc = get_function<glVertexAttribL1dv_ptr>("glVertexAttribL1dv")) != nullptr;
    result = result &&
             (glVertexAttribL2dv_proc = get_function<glVertexAttribL2dv_ptr>("glVertexAttribL2dv")) != nullptr;
    result = result &&
             (glVertexAttribL3dv_proc = get_function<glVertexAttribL3dv_ptr>("glVertexAttribL3dv")) != nullptr;
    result = result &&
             (glVertexAttribL4dv_proc = get_function<glVertexAttribL4dv_ptr>("glVertexAttribL4dv")) != nullptr;
    result = result &&
             (glVertexAttribLPointer_proc = get_function<glVertexAttribLPointer_ptr>("glVertexAttribLPointer")) !=
             nullptr;
    result = result &&
             (glGetVertexAttribLdv_proc = get_function<glGetVertexAttribLdv_ptr>("glGetVertexAttribLdv")) != nullptr;
    result = result && (glViewportArrayv_proc = get_function<glViewportArrayv_ptr>("glViewportArrayv")) != nullptr;
    result = result &&
             (glViewportIndexedf_proc = get_function<glViewportIndexedf_ptr>("glViewportIndexedf")) != nullptr;
    result = result &&
             (glViewportIndexedfv_proc = get_function<glViewportIndexedfv_ptr>("glViewportIndexedfv")) != nullptr;
    result = result && (glScissorArrayv_proc = get_function<glScissorArrayv_ptr>("glScissorArrayv")) != nullptr;
    result = result && (glScissorIndexed_proc = get_function<glScissorIndexed_ptr>("glScissorIndexed")) != nullptr;
    result = result && (glScissorIndexedv_proc = get_function<glScissorIndexedv_ptr>("glScissorIndexedv")) != nullptr;
    result = result &&
             (glDepthRangeArrayv_proc = get_function<glDepthRangeArrayv_ptr>("glDepthRangeArrayv")) != nullptr;
    result = result &&
             (glDepthRangeIndexed_proc = get_function<glDepthRangeIndexed_ptr>("glDepthRangeIndexed")) != nullptr;
    result = result && (glGetFloati_v_proc = get_function<glGetFloati_v_ptr>("glGetFloati_v")) != nullptr;
    result = result && (glGetDoublei_v_proc = get_function<glGetDoublei_v_ptr>("glGetDoublei_v")) != nullptr;

    return result;
}

#pragma endregion

#pragma region gl_version_4_2

using glDrawArraysInstancedBaseInstance_ptr =
void (*)(GLenum mode, int32 first, int32 count, int32 instancecount, uint32 baseinstance);
glDrawArraysInstancedBaseInstance_ptr glDrawArraysInstancedBaseInstance_proc = nullptr;

using glDrawElementsInstancedBaseInstance_ptr =
void (*)(GLenum mode, int32 count, GLenum type, const void* indices, int32 instancecount, uint32 baseinstance);
glDrawElementsInstancedBaseInstance_ptr glDrawElementsInstancedBaseInstance_proc = nullptr;

using glDrawElementsInstancedBaseVertexBaseInstance_ptr = void (*)(GLenum mode,
                                                                   int32 count,
                                                                   GLenum type,
                                                                   const void* indices,
                                                                   int32 instancecount,
                                                                   int32 basevertex,
                                                                   uint32 baseinstance);
glDrawElementsInstancedBaseVertexBaseInstance_ptr glDrawElementsInstancedBaseVertexBaseInstance_proc = nullptr;

using glGetInternalformativ_ptr =
void (*)(GLenum target, GLenum internalformat, GLenum pname, int32 bufSize, int32* params);
glGetInternalformativ_ptr glGetInternalformativ_proc = nullptr;

using glGetActiveAtomicCounterBufferiv_ptr = void (*)(uint32 program, uint32 bufferIndex, GLenum pname, int32* params);
glGetActiveAtomicCounterBufferiv_ptr glGetActiveAtomicCounterBufferiv_proc = nullptr;

using glBindImageTexture_ptr =
void (*)(uint32 unit, uint32 texture, int32 level, bool layered, int32 layer, GLenum access, GLenum format);
glBindImageTexture_ptr glBindImageTexture_proc = nullptr;

using glMemoryBarrier_ptr                = void (*)(uint32 barriers);
glMemoryBarrier_ptr glMemoryBarrier_proc = nullptr;

using glTexStorage1D_ptr               = void (*)(GLenum target, int32 levels, GLenum internalformat, int32 width);
glTexStorage1D_ptr glTexStorage1D_proc = nullptr;

using glTexStorage2D_ptr = void (*)(GLenum target, int32 levels, GLenum internalformat, int32 width, int32 height);
glTexStorage2D_ptr glTexStorage2D_proc = nullptr;

using glTexStorage3D_ptr =
void (*)(GLenum target, int32 levels, GLenum internalformat, int32 width, int32 height, int32 depth);
glTexStorage3D_ptr glTexStorage3D_proc = nullptr;

using glDrawTransformFeedbackInstanced_ptr = void (*)(GLenum mode, uint32 id, int32 instancecount);
glDrawTransformFeedbackInstanced_ptr glDrawTransformFeedbackInstanced_proc = nullptr;

using glDrawTransformFeedbackStreamInstanced_ptr = void (*)(GLenum mode, uint32 id, uint32 stream, int32 instancecount);
glDrawTransformFeedbackStreamInstanced_ptr glDrawTransformFeedbackStreamInstanced_proc = nullptr;

bool init_gl_version_4_2()
{
    using ::framework::graphic::utils::get_function;

    bool result = true;

    result = result && (glDrawArraysInstancedBaseInstance_proc = get_function<glDrawArraysInstancedBaseInstance_ptr>(
                        "glDrawArraysInstancedBaseInstance")) != nullptr;
    result = result &&
             (glDrawElementsInstancedBaseInstance_proc = get_function<glDrawElementsInstancedBaseInstance_ptr>(
              "glDrawElementsInstancedBaseInstance")) != nullptr;
    result = result &&
             (glDrawElementsInstancedBaseVertexBaseInstance_proc = get_function<
              glDrawElementsInstancedBaseVertexBaseInstance_ptr>("glDrawElementsInstancedBaseVertexBaseInstance")) !=
             nullptr;
    result = result &&
             (glGetInternalformativ_proc = get_function<glGetInternalformativ_ptr>("glGetInternalformativ")) != nullptr;
    result = result && (glGetActiveAtomicCounterBufferiv_proc = get_function<glGetActiveAtomicCounterBufferiv_ptr>(
                        "glGetActiveAtomicCounterBufferiv")) != nullptr;
    result = result &&
             (glBindImageTexture_proc = get_function<glBindImageTexture_ptr>("glBindImageTexture")) != nullptr;
    result = result && (glMemoryBarrier_proc = get_function<glMemoryBarrier_ptr>("glMemoryBarrier")) != nullptr;
    result = result && (glTexStorage1D_proc = get_function<glTexStorage1D_ptr>("glTexStorage1D")) != nullptr;
    result = result && (glTexStorage2D_proc = get_function<glTexStorage2D_ptr>("glTexStorage2D")) != nullptr;
    result = result && (glTexStorage3D_proc = get_function<glTexStorage3D_ptr>("glTexStorage3D")) != nullptr;
    result = result && (glDrawTransformFeedbackInstanced_proc = get_function<glDrawTransformFeedbackInstanced_ptr>(
                        "glDrawTransformFeedbackInstanced")) != nullptr;
    result = result &&
             (glDrawTransformFeedbackStreamInstanced_proc = get_function<glDrawTransformFeedbackStreamInstanced_ptr>(
              "glDrawTransformFeedbackStreamInstanced")) != nullptr;

    return result;
}

#pragma endregion

#pragma region gl_version_4_3

using debug_proc_callback = ::framework::graphic::gl::debug_proc_callback;

using glClearBufferData_ptr =
void (*)(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void* data);
glClearBufferData_ptr glClearBufferData_proc = nullptr;

using glClearBufferSubData_ptr                     = void (*)(GLenum target,
                                          GLenum internalformat,
                                          ptrdiff offset,
                                          ptrdiff size,
                                          GLenum format,
                                          GLenum type,
                                          const void* data);
glClearBufferSubData_ptr glClearBufferSubData_proc = nullptr;

using glDispatchCompute_ptr                  = void (*)(uint32 num_groups_x, uint32 num_groups_y, uint32 num_groups_z);
glDispatchCompute_ptr glDispatchCompute_proc = nullptr;

using glDispatchComputeIndirect_ptr                          = void (*)(ptrdiff indirect);
glDispatchComputeIndirect_ptr glDispatchComputeIndirect_proc = nullptr;

using glCopyImageSubData_ptr                   = void (*)(uint32 srcName,
                                        GLenum srcTarget,
                                        int32 srcLevel,
                                        int32 srcX,
                                        int32 srcY,
                                        int32 srcZ,
                                        uint32 dstName,
                                        GLenum dstTarget,
                                        int32 dstLevel,
                                        int32 dstX,
                                        int32 dstY,
                                        int32 dstZ,
                                        int32 srcWidth,
                                        int32 srcHeight,
                                        int32 srcDepth);
glCopyImageSubData_ptr glCopyImageSubData_proc = nullptr;

using glFramebufferParameteri_ptr                        = void (*)(GLenum target, GLenum pname, int32 param);
glFramebufferParameteri_ptr glFramebufferParameteri_proc = nullptr;

using glGetFramebufferParameteriv_ptr                            = void (*)(GLenum target, GLenum pname, int32* params);
glGetFramebufferParameteriv_ptr glGetFramebufferParameteriv_proc = nullptr;

using glGetInternalformati64v_ptr =
void (*)(GLenum target, GLenum internalformat, GLenum pname, int32 bufSize, int64* params);
glGetInternalformati64v_ptr glGetInternalformati64v_proc = nullptr;

using glInvalidateTexSubImage_ptr                        = void (*)(uint32 texture,
                                             int32 level,
                                             int32 xoffset,
                                             int32 yoffset,
                                             int32 zoffset,
                                             int32 width,
                                             int32 height,
                                             int32 depth);
glInvalidateTexSubImage_ptr glInvalidateTexSubImage_proc = nullptr;

using glInvalidateTexImage_ptr                     = void (*)(uint32 texture, int32 level);
glInvalidateTexImage_ptr glInvalidateTexImage_proc = nullptr;

using glInvalidateBufferSubData_ptr                          = void (*)(uint32 buffer, ptrdiff offset, ptrdiff length);
glInvalidateBufferSubData_ptr glInvalidateBufferSubData_proc = nullptr;

using glInvalidateBufferData_ptr                       = void (*)(uint32 buffer);
glInvalidateBufferData_ptr glInvalidateBufferData_proc = nullptr;

using glInvalidateFramebuffer_ptr = void (*)(GLenum target, int32 numAttachments, const GLenum* attachments);
glInvalidateFramebuffer_ptr glInvalidateFramebuffer_proc = nullptr;

using glInvalidateSubFramebuffer_ptr =
void (*)(GLenum target, int32 numAttachments, const GLenum* attachments, int32 x, int32 y, int32 width, int32 height);
glInvalidateSubFramebuffer_ptr glInvalidateSubFramebuffer_proc = nullptr;

using glMultiDrawArraysIndirect_ptr = void (*)(GLenum mode, const void* indirect, int32 drawcount, int32 stride);
glMultiDrawArraysIndirect_ptr glMultiDrawArraysIndirect_proc = nullptr;

using glMultiDrawElementsIndirect_ptr =
void (*)(GLenum mode, GLenum type, const void* indirect, int32 drawcount, int32 stride);
glMultiDrawElementsIndirect_ptr glMultiDrawElementsIndirect_proc = nullptr;

using glGetProgramInterfaceiv_ptr = void (*)(uint32 program, GLenum programInterface, GLenum pname, int32* params);
glGetProgramInterfaceiv_ptr glGetProgramInterfaceiv_proc = nullptr;

using glGetProgramResourceIndex_ptr = uint32 (*)(uint32 program, GLenum programInterface, const char* name);
glGetProgramResourceIndex_ptr glGetProgramResourceIndex_proc = nullptr;

using glGetProgramResourceName_ptr =
void (*)(uint32 program, GLenum programInterface, uint32 index, int32 bufSize, int32* length, char* name);
glGetProgramResourceName_ptr glGetProgramResourceName_proc = nullptr;

using glGetProgramResourceiv_ptr                       = void (*)(uint32 program,
                                            GLenum programInterface,
                                            uint32 index,
                                            int32 propCount,
                                            const GLenum* props,
                                            int32 bufSize,
                                            int32* length,
                                            int32* params);
glGetProgramResourceiv_ptr glGetProgramResourceiv_proc = nullptr;

using glGetProgramResourceLocation_ptr = int32 (*)(uint32 program, GLenum programInterface, const char* name);
glGetProgramResourceLocation_ptr glGetProgramResourceLocation_proc = nullptr;

using glGetProgramResourceLocationIndex_ptr = int32 (*)(uint32 program, GLenum programInterface, const char* name);
glGetProgramResourceLocationIndex_ptr glGetProgramResourceLocationIndex_proc = nullptr;

using glShaderStorageBlockBinding_ptr = void (*)(uint32 program, uint32 storageBlockIndex, uint32 storageBlockBinding);
glShaderStorageBlockBinding_ptr glShaderStorageBlockBinding_proc = nullptr;

using glTexBufferRange_ptr = void (*)(GLenum target, GLenum internalformat, uint32 buffer, ptrdiff offset, ptrdiff size);
glTexBufferRange_ptr glTexBufferRange_proc = nullptr;

using glTexStorage2DMultisample_ptr =
void (*)(GLenum target, int32 samples, GLenum internalformat, int32 width, int32 height, bool fixedsamplelocations);
glTexStorage2DMultisample_ptr glTexStorage2DMultisample_proc = nullptr;

using glTexStorage3DMultisample_ptr                          = void (*)(GLenum target,
                                               int32 samples,
                                               GLenum internalformat,
                                               int32 width,
                                               int32 height,
                                               int32 depth,
                                               bool fixedsamplelocations);
glTexStorage3DMultisample_ptr glTexStorage3DMultisample_proc = nullptr;

using glTextureView_ptr              = void (*)(uint32 texture,
                                   GLenum target,
                                   uint32 origtexture,
                                   GLenum internalformat,
                                   uint32 minlevel,
                                   uint32 numlevels,
                                   uint32 minlayer,
                                   uint32 numlayers);
glTextureView_ptr glTextureView_proc = nullptr;

using glBindVertexBuffer_ptr = void (*)(uint32 bindingindex, uint32 buffer, ptrdiff offset, int32 stride);
glBindVertexBuffer_ptr glBindVertexBuffer_proc = nullptr;

using glVertexAttribFormat_ptr =
void (*)(uint32 attribindex, int32 size, GLenum type, bool normalized, uint32 relativeoffset);
glVertexAttribFormat_ptr glVertexAttribFormat_proc = nullptr;

using glVertexAttribIFormat_ptr = void (*)(uint32 attribindex, int32 size, GLenum type, uint32 relativeoffset);
glVertexAttribIFormat_ptr glVertexAttribIFormat_proc = nullptr;

using glVertexAttribLFormat_ptr = void (*)(uint32 attribindex, int32 size, GLenum type, uint32 relativeoffset);
glVertexAttribLFormat_ptr glVertexAttribLFormat_proc = nullptr;

using glVertexAttribBinding_ptr                      = void (*)(uint32 attribindex, uint32 bindingindex);
glVertexAttribBinding_ptr glVertexAttribBinding_proc = nullptr;

using glVertexBindingDivisor_ptr                       = void (*)(uint32 bindingindex, uint32 divisor);
glVertexBindingDivisor_ptr glVertexBindingDivisor_proc = nullptr;

using glDebugMessageControl_ptr =
void (*)(GLenum source, GLenum type, GLenum severity, int32 count, const uint32* ids, bool enabled);
glDebugMessageControl_ptr glDebugMessageControl_proc = nullptr;

using glDebugMessageInsert_ptr =
void (*)(GLenum source, GLenum type, uint32 id, GLenum severity, int32 length, const char* buf);
glDebugMessageInsert_ptr glDebugMessageInsert_proc = nullptr;

using glDebugMessageCallback_ptr                       = void (*)(debug_proc_callback callback, const void* userParam);
glDebugMessageCallback_ptr glDebugMessageCallback_proc = nullptr;

using glGetDebugMessageLog_ptr                     = uint32 (*)(uint32 count,
                                            int32 bufSize,
                                            GLenum* sources,
                                            GLenum* types,
                                            uint32* ids,
                                            GLenum* severities,
                                            int32* lengths,
                                            char* messageLog);
glGetDebugMessageLog_ptr glGetDebugMessageLog_proc = nullptr;

using glPushDebugGroup_ptr                 = void (*)(GLenum source, uint32 id, int32 length, const char* message);
glPushDebugGroup_ptr glPushDebugGroup_proc = nullptr;

using glPopDebugGroup_ptr                = void (*)();
glPopDebugGroup_ptr glPopDebugGroup_proc = nullptr;

using glObjectLabel_ptr              = void (*)(GLenum identifier, uint32 name, int32 length, const char* label);
glObjectLabel_ptr glObjectLabel_proc = nullptr;

using glGetObjectLabel_ptr = void (*)(GLenum identifier, uint32 name, int32 bufSize, int32* length, char* label);
glGetObjectLabel_ptr glGetObjectLabel_proc = nullptr;

using glObjectPtrLabel_ptr                 = void (*)(const void* ptr, int32 length, const char* label);
glObjectPtrLabel_ptr glObjectPtrLabel_proc = nullptr;

using glGetObjectPtrLabel_ptr                    = void (*)(const void* ptr, int32 bufSize, int32* length, char* label);
glGetObjectPtrLabel_ptr glGetObjectPtrLabel_proc = nullptr;

bool init_gl_version_4_3()
{
    using ::framework::graphic::utils::get_function;

    bool result = true;

    result = result && (glClearBufferData_proc = get_function<glClearBufferData_ptr>("glClearBufferData")) != nullptr;
    result = result &&
             (glClearBufferSubData_proc = get_function<glClearBufferSubData_ptr>("glClearBufferSubData")) != nullptr;
    result = result && (glDispatchCompute_proc = get_function<glDispatchCompute_ptr>("glDispatchCompute")) != nullptr;
    result = result && (glDispatchComputeIndirect_proc = get_function<glDispatchComputeIndirect_ptr>(
                        "glDispatchComputeIndirect")) != nullptr;
    result = result &&
             (glCopyImageSubData_proc = get_function<glCopyImageSubData_ptr>("glCopyImageSubData")) != nullptr;
    result = result &&
             (glFramebufferParameteri_proc = get_function<glFramebufferParameteri_ptr>("glFramebufferParameteri")) !=
             nullptr;
    result = result && (glGetFramebufferParameteriv_proc = get_function<glGetFramebufferParameteriv_ptr>(
                        "glGetFramebufferParameteriv")) != nullptr;
    result = result &&
             (glGetInternalformati64v_proc = get_function<glGetInternalformati64v_ptr>("glGetInternalformati64v")) !=
             nullptr;
    result = result &&
             (glInvalidateTexSubImage_proc = get_function<glInvalidateTexSubImage_ptr>("glInvalidateTexSubImage")) !=
             nullptr;
    result = result &&
             (glInvalidateTexImage_proc = get_function<glInvalidateTexImage_ptr>("glInvalidateTexImage")) != nullptr;
    result = result && (glInvalidateBufferSubData_proc = get_function<glInvalidateBufferSubData_ptr>(
                        "glInvalidateBufferSubData")) != nullptr;
    result = result &&
             (glInvalidateBufferData_proc = get_function<glInvalidateBufferData_ptr>("glInvalidateBufferData")) !=
             nullptr;
    result = result &&
             (glInvalidateFramebuffer_proc = get_function<glInvalidateFramebuffer_ptr>("glInvalidateFramebuffer")) !=
             nullptr;
    result = result && (glInvalidateSubFramebuffer_proc = get_function<glInvalidateSubFramebuffer_ptr>(
                        "glInvalidateSubFramebuffer")) != nullptr;
    result = result && (glMultiDrawArraysIndirect_proc = get_function<glMultiDrawArraysIndirect_ptr>(
                        "glMultiDrawArraysIndirect")) != nullptr;
    result = result && (glMultiDrawElementsIndirect_proc = get_function<glMultiDrawElementsIndirect_ptr>(
                        "glMultiDrawElementsIndirect")) != nullptr;
    result = result &&
             (glGetProgramInterfaceiv_proc = get_function<glGetProgramInterfaceiv_ptr>("glGetProgramInterfaceiv")) !=
             nullptr;
    result = result && (glGetProgramResourceIndex_proc = get_function<glGetProgramResourceIndex_ptr>(
                        "glGetProgramResourceIndex")) != nullptr;
    result = result &&
             (glGetProgramResourceName_proc = get_function<glGetProgramResourceName_ptr>("glGetProgramResourceName")) !=
             nullptr;
    result = result &&
             (glGetProgramResourceiv_proc = get_function<glGetProgramResourceiv_ptr>("glGetProgramResourceiv")) !=
             nullptr;
    result = result && (glGetProgramResourceLocation_proc = get_function<glGetProgramResourceLocation_ptr>(
                        "glGetProgramResourceLocation")) != nullptr;
    result = result && (glGetProgramResourceLocationIndex_proc = get_function<glGetProgramResourceLocationIndex_ptr>(
                        "glGetProgramResourceLocationIndex")) != nullptr;
    result = result && (glShaderStorageBlockBinding_proc = get_function<glShaderStorageBlockBinding_ptr>(
                        "glShaderStorageBlockBinding")) != nullptr;
    result = result && (glTexBufferRange_proc = get_function<glTexBufferRange_ptr>("glTexBufferRange")) != nullptr;
    result = result && (glTexStorage2DMultisample_proc = get_function<glTexStorage2DMultisample_ptr>(
                        "glTexStorage2DMultisample")) != nullptr;
    result = result && (glTexStorage3DMultisample_proc = get_function<glTexStorage3DMultisample_ptr>(
                        "glTexStorage3DMultisample")) != nullptr;
    result = result && (glTextureView_proc = get_function<glTextureView_ptr>("glTextureView")) != nullptr;
    result = result &&
             (glBindVertexBuffer_proc = get_function<glBindVertexBuffer_ptr>("glBindVertexBuffer")) != nullptr;
    result = result &&
             (glVertexAttribFormat_proc = get_function<glVertexAttribFormat_ptr>("glVertexAttribFormat")) != nullptr;
    result = result &&
             (glVertexAttribIFormat_proc = get_function<glVertexAttribIFormat_ptr>("glVertexAttribIFormat")) != nullptr;
    result = result &&
             (glVertexAttribLFormat_proc = get_function<glVertexAttribLFormat_ptr>("glVertexAttribLFormat")) != nullptr;
    result = result &&
             (glVertexAttribBinding_proc = get_function<glVertexAttribBinding_ptr>("glVertexAttribBinding")) != nullptr;
    result = result &&
             (glVertexBindingDivisor_proc = get_function<glVertexBindingDivisor_ptr>("glVertexBindingDivisor")) !=
             nullptr;
    result = result &&
             (glDebugMessageControl_proc = get_function<glDebugMessageControl_ptr>("glDebugMessageControl")) != nullptr;
    result = result &&
             (glDebugMessageInsert_proc = get_function<glDebugMessageInsert_ptr>("glDebugMessageInsert")) != nullptr;
    result = result &&
             (glDebugMessageCallback_proc = get_function<glDebugMessageCallback_ptr>("glDebugMessageCallback")) !=
             nullptr;
    result = result &&
             (glGetDebugMessageLog_proc = get_function<glGetDebugMessageLog_ptr>("glGetDebugMessageLog")) != nullptr;
    result = result && (glPushDebugGroup_proc = get_function<glPushDebugGroup_ptr>("glPushDebugGroup")) != nullptr;
    result = result && (glPopDebugGroup_proc = get_function<glPopDebugGroup_ptr>("glPopDebugGroup")) != nullptr;
    result = result && (glObjectLabel_proc = get_function<glObjectLabel_ptr>("glObjectLabel")) != nullptr;
    result = result && (glGetObjectLabel_proc = get_function<glGetObjectLabel_ptr>("glGetObjectLabel")) != nullptr;
    result = result && (glObjectPtrLabel_proc = get_function<glObjectPtrLabel_ptr>("glObjectPtrLabel")) != nullptr;
    result = result &&
             (glGetObjectPtrLabel_proc = get_function<glGetObjectPtrLabel_ptr>("glGetObjectPtrLabel")) != nullptr;

    return result;
}

#pragma endregion

#pragma region gl_versino_4_4

using glBufferStorage_ptr                = void (*)(GLenum target, ptrdiff size, const void* data, uint32 flags);
glBufferStorage_ptr glBufferStorage_proc = nullptr;

using glClearTexImage_ptr = void (*)(uint32 texture, int32 level, GLenum format, GLenum type, const void* data);
glClearTexImage_ptr glClearTexImage_proc = nullptr;

using glClearTexSubImage_ptr                   = void (*)(uint32 texture,
                                        int32 level,
                                        int32 xoffset,
                                        int32 yoffset,
                                        int32 zoffset,
                                        int32 width,
                                        int32 height,
                                        int32 depth,
                                        GLenum format,
                                        GLenum type,
                                        const void* data);
glClearTexSubImage_ptr glClearTexSubImage_proc = nullptr;

using glBindBuffersBase_ptr = void (*)(GLenum target, uint32 first, int32 count, const uint32* buffers);
glBindBuffersBase_ptr glBindBuffersBase_proc = nullptr;

using glBindBuffersRange_ptr =
void (*)(GLenum target, uint32 first, int32 count, const uint32* buffers, const ptrdiff* offsets, const ptrdiff* sizes);
glBindBuffersRange_ptr glBindBuffersRange_proc = nullptr;

using glBindTextures_ptr               = void (*)(uint32 first, int32 count, const uint32* textures);
glBindTextures_ptr glBindTextures_proc = nullptr;

using glBindSamplers_ptr               = void (*)(uint32 first, int32 count, const uint32* samplers);
glBindSamplers_ptr glBindSamplers_proc = nullptr;

using glBindImageTextures_ptr                    = void (*)(uint32 first, int32 count, const uint32* textures);
glBindImageTextures_ptr glBindImageTextures_proc = nullptr;

using glBindVertexBuffers_ptr =
void (*)(uint32 first, int32 count, const uint32* buffers, const ptrdiff* offsets, const int32* strides);
glBindVertexBuffers_ptr glBindVertexBuffers_proc = nullptr;

bool init_gl_version_4_4()
{
    using ::framework::graphic::utils::get_function;

    bool result = true;

    result = result && (glBufferStorage_proc = get_function<glBufferStorage_ptr>("glBufferStorage")) != nullptr;
    result = result && (glClearTexImage_proc = get_function<glClearTexImage_ptr>("glClearTexImage")) != nullptr;
    result = result &&
             (glClearTexSubImage_proc = get_function<glClearTexSubImage_ptr>("glClearTexSubImage")) != nullptr;
    result = result && (glBindBuffersBase_proc = get_function<glBindBuffersBase_ptr>("glBindBuffersBase")) != nullptr;
    result = result &&
             (glBindBuffersRange_proc = get_function<glBindBuffersRange_ptr>("glBindBuffersRange")) != nullptr;
    result = result && (glBindTextures_proc = get_function<glBindTextures_ptr>("glBindTextures")) != nullptr;
    result = result && (glBindSamplers_proc = get_function<glBindSamplers_ptr>("glBindSamplers")) != nullptr;
    result = result &&
             (glBindImageTextures_proc = get_function<glBindImageTextures_ptr>("glBindImageTextures")) != nullptr;
    result = result &&
             (glBindVertexBuffers_proc = get_function<glBindVertexBuffers_ptr>("glBindVertexBuffers")) != nullptr;

    return result;
}

#pragma endregion

#pragma region gl_version_4_5

using glClipControl_ptr              = void (*)(GLenum origin, GLenum depth);
glClipControl_ptr glClipControl_proc = nullptr;

using glCreateTransformFeedbacks_ptr                           = void (*)(int32 n, uint32* ids);
glCreateTransformFeedbacks_ptr glCreateTransformFeedbacks_proc = nullptr;

using glTransformFeedbackBufferBase_ptr = void (*)(uint32 xfb, uint32 index, uint32 buffer);
glTransformFeedbackBufferBase_ptr glTransformFeedbackBufferBase_proc = nullptr;

using glTransformFeedbackBufferRange_ptr =
void (*)(uint32 xfb, uint32 index, uint32 buffer, ptrdiff offset, ptrdiff size);
glTransformFeedbackBufferRange_ptr glTransformFeedbackBufferRange_proc = nullptr;

using glGetTransformFeedbackiv_ptr                         = void (*)(uint32 xfb, GLenum pname, int32* param);
glGetTransformFeedbackiv_ptr glGetTransformFeedbackiv_proc = nullptr;

using glGetTransformFeedbacki_v_ptr = void (*)(uint32 xfb, GLenum pname, uint32 index, int32* param);
glGetTransformFeedbacki_v_ptr glGetTransformFeedbacki_v_proc = nullptr;

using glGetTransformFeedbacki64_v_ptr = void (*)(uint32 xfb, GLenum pname, uint32 index, int64* param);
glGetTransformFeedbacki64_v_ptr glGetTransformFeedbacki64_v_proc = nullptr;

using glCreateBuffers_ptr                = void (*)(int32 n, uint32* buffers);
glCreateBuffers_ptr glCreateBuffers_proc = nullptr;

using glNamedBufferStorage_ptr = void (*)(uint32 buffer, ptrdiff size, const void* data, uint32 flags);
glNamedBufferStorage_ptr glNamedBufferStorage_proc = nullptr;

using glNamedBufferData_ptr                  = void (*)(uint32 buffer, ptrdiff size, const void* data, GLenum usage);
glNamedBufferData_ptr glNamedBufferData_proc = nullptr;

using glNamedBufferSubData_ptr = void (*)(uint32 buffer, ptrdiff offset, ptrdiff size, const void* data);
glNamedBufferSubData_ptr glNamedBufferSubData_proc = nullptr;

using glCopyNamedBufferSubData_ptr =
void (*)(uint32 readBuffer, uint32 writeBuffer, ptrdiff readOffset, ptrdiff writeOffset, ptrdiff size);
glCopyNamedBufferSubData_ptr glCopyNamedBufferSubData_proc = nullptr;

using glClearNamedBufferData_ptr =
void (*)(uint32 buffer, GLenum internalformat, GLenum format, GLenum type, const void* data);
glClearNamedBufferData_ptr glClearNamedBufferData_proc = nullptr;

using glClearNamedBufferSubData_ptr                          = void (*)(uint32 buffer,
                                               GLenum internalformat,
                                               ptrdiff offset,
                                               ptrdiff size,
                                               GLenum format,
                                               GLenum type,
                                               const void* data);
glClearNamedBufferSubData_ptr glClearNamedBufferSubData_proc = nullptr;

using glMapNamedBuffer_ptr                 = void* (*)(uint32 buffer, GLenum access);
glMapNamedBuffer_ptr glMapNamedBuffer_proc = nullptr;

using glMapNamedBufferRange_ptr = void* (*)(uint32 buffer, ptrdiff offset, ptrdiff length, uint32 access);
glMapNamedBufferRange_ptr glMapNamedBufferRange_proc = nullptr;

using glUnmapNamedBuffer_ptr                   = bool (*)(uint32 buffer);
glUnmapNamedBuffer_ptr glUnmapNamedBuffer_proc = nullptr;

using glFlushMappedNamedBufferRange_ptr = void (*)(uint32 buffer, ptrdiff offset, ptrdiff length);
glFlushMappedNamedBufferRange_ptr glFlushMappedNamedBufferRange_proc = nullptr;

using glGetNamedBufferParameteriv_ptr                            = void (*)(uint32 buffer, GLenum pname, int32* params);
glGetNamedBufferParameteriv_ptr glGetNamedBufferParameteriv_proc = nullptr;

using glGetNamedBufferParameteri64v_ptr = void (*)(uint32 buffer, GLenum pname, int64* params);
glGetNamedBufferParameteri64v_ptr glGetNamedBufferParameteri64v_proc = nullptr;

using glGetNamedBufferPointerv_ptr                         = void (*)(uint32 buffer, GLenum pname, void** params);
glGetNamedBufferPointerv_ptr glGetNamedBufferPointerv_proc = nullptr;

using glGetNamedBufferSubData_ptr = void (*)(uint32 buffer, ptrdiff offset, ptrdiff size, void* data);
glGetNamedBufferSubData_ptr glGetNamedBufferSubData_proc = nullptr;

using glCreateFramebuffers_ptr                     = void (*)(int32 n, uint32* framebuffers);
glCreateFramebuffers_ptr glCreateFramebuffers_proc = nullptr;

using glNamedFramebufferRenderbuffer_ptr                               = void (*)(uint32 framebuffer,
                                                    GLenum attachment,
                                                    GLenum renderbuffertarget,
                                                    uint32 renderbuffer);
glNamedFramebufferRenderbuffer_ptr glNamedFramebufferRenderbuffer_proc = nullptr;

using glNamedFramebufferParameteri_ptr = void (*)(uint32 framebuffer, GLenum pname, int32 param);
glNamedFramebufferParameteri_ptr glNamedFramebufferParameteri_proc = nullptr;

using glNamedFramebufferTexture_ptr = void (*)(uint32 framebuffer, GLenum attachment, uint32 texture, int32 level);
glNamedFramebufferTexture_ptr glNamedFramebufferTexture_proc = nullptr;

using glNamedFramebufferTextureLayer_ptr =
void (*)(uint32 framebuffer, GLenum attachment, uint32 texture, int32 level, int32 layer);
glNamedFramebufferTextureLayer_ptr glNamedFramebufferTextureLayer_proc = nullptr;

using glNamedFramebufferDrawBuffer_ptr                             = void (*)(uint32 framebuffer, GLenum buf);
glNamedFramebufferDrawBuffer_ptr glNamedFramebufferDrawBuffer_proc = nullptr;

using glNamedFramebufferDrawBuffers_ptr = void (*)(uint32 framebuffer, int32 n, const GLenum* bufs);
glNamedFramebufferDrawBuffers_ptr glNamedFramebufferDrawBuffers_proc = nullptr;

using glNamedFramebufferReadBuffer_ptr                             = void (*)(uint32 framebuffer, GLenum src);
glNamedFramebufferReadBuffer_ptr glNamedFramebufferReadBuffer_proc = nullptr;

using glInvalidateNamedFramebufferData_ptr                                 = void (*)(uint32 framebuffer,
                                                      int32 numAttachments,
                                                      const GLenum* attachments);
glInvalidateNamedFramebufferData_ptr glInvalidateNamedFramebufferData_proc = nullptr;

using glInvalidateNamedFramebufferSubData_ptr                                    = void (*)(uint32 framebuffer,
                                                         int32 numAttachments,
                                                         const GLenum* attachments,
                                                         int32 x,
                                                         int32 y,
                                                         int32 width,
                                                         int32 height);
glInvalidateNamedFramebufferSubData_ptr glInvalidateNamedFramebufferSubData_proc = nullptr;

using glClearNamedFramebufferiv_ptr = void (*)(uint32 framebuffer, GLenum buffer, int32 drawbuffer, const int32* value);
glClearNamedFramebufferiv_ptr glClearNamedFramebufferiv_proc = nullptr;

using glClearNamedFramebufferuiv_ptr                           = void (*)(uint32 framebuffer,
                                                GLenum buffer,
                                                int32 drawbuffer,
                                                const uint32* value);
glClearNamedFramebufferuiv_ptr glClearNamedFramebufferuiv_proc = nullptr;

using glClearNamedFramebufferfv_ptr                          = void (*)(uint32 framebuffer,
                                               GLenum buffer,
                                               int32 drawbuffer,
                                               const float32* value);
glClearNamedFramebufferfv_ptr glClearNamedFramebufferfv_proc = nullptr;

using glClearNamedFramebufferfi_ptr =
void (*)(uint32 framebuffer, GLenum buffer, int32 drawbuffer, float32 depth, int32 stencil);
glClearNamedFramebufferfi_ptr glClearNamedFramebufferfi_proc = nullptr;

using glBlitNamedFramebuffer_ptr                       = void (*)(uint32 readFramebuffer,
                                            uint32 drawFramebuffer,
                                            int32 srcX0,
                                            int32 srcY0,
                                            int32 srcX1,
                                            int32 srcY1,
                                            int32 dstX0,
                                            int32 dstY0,
                                            int32 dstX1,
                                            int32 dstY1,
                                            uint32 mask,
                                            GLenum filter);
glBlitNamedFramebuffer_ptr glBlitNamedFramebuffer_proc = nullptr;

using glCheckNamedFramebufferStatus_ptr                              = GLenum (*)(uint32 framebuffer, GLenum target);
glCheckNamedFramebufferStatus_ptr glCheckNamedFramebufferStatus_proc = nullptr;

using glGetNamedFramebufferParameteriv_ptr = void (*)(uint32 framebuffer, GLenum pname, int32* param);
glGetNamedFramebufferParameteriv_ptr glGetNamedFramebufferParameteriv_proc = nullptr;

using glGetNamedFramebufferAttachmentParameteriv_ptr = void (*)(uint32 framebuffer,
                                                                GLenum attachment,
                                                                GLenum pname,
                                                                int32* params);
glGetNamedFramebufferAttachmentParameteriv_ptr glGetNamedFramebufferAttachmentParameteriv_proc = nullptr;

using glCreateRenderbuffers_ptr                      = void (*)(int32 n, uint32* renderbuffers);
glCreateRenderbuffers_ptr glCreateRenderbuffers_proc = nullptr;

using glNamedRenderbufferStorage_ptr = void (*)(uint32 renderbuffer, GLenum internalformat, int32 width, int32 height);
glNamedRenderbufferStorage_ptr glNamedRenderbufferStorage_proc = nullptr;

using glNamedRenderbufferStorageMultisample_ptr =
void (*)(uint32 renderbuffer, int32 samples, GLenum internalformat, int32 width, int32 height);
glNamedRenderbufferStorageMultisample_ptr glNamedRenderbufferStorageMultisample_proc = nullptr;

using glGetNamedRenderbufferParameteriv_ptr = void (*)(uint32 renderbuffer, GLenum pname, int32* params);
glGetNamedRenderbufferParameteriv_ptr glGetNamedRenderbufferParameteriv_proc = nullptr;

using glCreateTextures_ptr                 = void (*)(GLenum target, int32 n, uint32* textures);
glCreateTextures_ptr glCreateTextures_proc = nullptr;

using glTextureBuffer_ptr                = void (*)(uint32 texture, GLenum internalformat, uint32 buffer);
glTextureBuffer_ptr glTextureBuffer_proc = nullptr;

using glTextureBufferRange_ptr =
void (*)(uint32 texture, GLenum internalformat, uint32 buffer, ptrdiff offset, ptrdiff size);
glTextureBufferRange_ptr glTextureBufferRange_proc = nullptr;

using glTextureStorage1D_ptr = void (*)(uint32 texture, int32 levels, GLenum internalformat, int32 width);
glTextureStorage1D_ptr glTextureStorage1D_proc = nullptr;

using glTextureStorage2D_ptr = void (*)(uint32 texture, int32 levels, GLenum internalformat, int32 width, int32 height);
glTextureStorage2D_ptr glTextureStorage2D_proc = nullptr;

using glTextureStorage3D_ptr =
void (*)(uint32 texture, int32 levels, GLenum internalformat, int32 width, int32 height, int32 depth);
glTextureStorage3D_ptr glTextureStorage3D_proc = nullptr;

using glTextureStorage2DMultisample_ptr =
void (*)(uint32 texture, int32 samples, GLenum internalformat, int32 width, int32 height, bool fixedsamplelocations);
glTextureStorage2DMultisample_ptr glTextureStorage2DMultisample_proc = nullptr;

using glTextureStorage3DMultisample_ptr                              = void (*)(uint32 texture,
                                                   int32 samples,
                                                   GLenum internalformat,
                                                   int32 width,
                                                   int32 height,
                                                   int32 depth,
                                                   bool fixedsamplelocations);
glTextureStorage3DMultisample_ptr glTextureStorage3DMultisample_proc = nullptr;

using glTextureSubImage1D_ptr =
void (*)(uint32 texture, int32 level, int32 xoffset, int32 width, GLenum format, GLenum type, const void* pixels);
glTextureSubImage1D_ptr glTextureSubImage1D_proc = nullptr;

using glTextureSubImage2D_ptr                    = void (*)(uint32 texture,
                                         int32 level,
                                         int32 xoffset,
                                         int32 yoffset,
                                         int32 width,
                                         int32 height,
                                         GLenum format,
                                         GLenum type,
                                         const void* pixels);
glTextureSubImage2D_ptr glTextureSubImage2D_proc = nullptr;

using glTextureSubImage3D_ptr                    = void (*)(uint32 texture,
                                         int32 level,
                                         int32 xoffset,
                                         int32 yoffset,
                                         int32 zoffset,
                                         int32 width,
                                         int32 height,
                                         int32 depth,
                                         GLenum format,
                                         GLenum type,
                                         const void* pixels);
glTextureSubImage3D_ptr glTextureSubImage3D_proc = nullptr;

using glCompressedTextureSubImage1D_ptr =
void (*)(uint32 texture, int32 level, int32 xoffset, int32 width, GLenum format, int32 imageSize, const void* data);
glCompressedTextureSubImage1D_ptr glCompressedTextureSubImage1D_proc = nullptr;

using glCompressedTextureSubImage2D_ptr                              = void (*)(uint32 texture,
                                                   int32 level,
                                                   int32 xoffset,
                                                   int32 yoffset,
                                                   int32 width,
                                                   int32 height,
                                                   GLenum format,
                                                   int32 imageSize,
                                                   const void* data);
glCompressedTextureSubImage2D_ptr glCompressedTextureSubImage2D_proc = nullptr;

using glCompressedTextureSubImage3D_ptr                              = void (*)(uint32 texture,
                                                   int32 level,
                                                   int32 xoffset,
                                                   int32 yoffset,
                                                   int32 zoffset,
                                                   int32 width,
                                                   int32 height,
                                                   int32 depth,
                                                   GLenum format,
                                                   int32 imageSize,
                                                   const void* data);
glCompressedTextureSubImage3D_ptr glCompressedTextureSubImage3D_proc = nullptr;

using glCopyTextureSubImage1D_ptr = void (*)(uint32 texture, int32 level, int32 xoffset, int32 x, int32 y, int32 width);
glCopyTextureSubImage1D_ptr glCopyTextureSubImage1D_proc = nullptr;

using glCopyTextureSubImage2D_ptr =
void (*)(uint32 texture, int32 level, int32 xoffset, int32 yoffset, int32 x, int32 y, int32 width, int32 height);
glCopyTextureSubImage2D_ptr glCopyTextureSubImage2D_proc = nullptr;

using glCopyTextureSubImage3D_ptr                        = void (*)(uint32 texture,
                                             int32 level,
                                             int32 xoffset,
                                             int32 yoffset,
                                             int32 zoffset,
                                             int32 x,
                                             int32 y,
                                             int32 width,
                                             int32 height);
glCopyTextureSubImage3D_ptr glCopyTextureSubImage3D_proc = nullptr;

using glTextureParameterf_ptr                    = void (*)(uint32 texture, GLenum pname, float32 param);
glTextureParameterf_ptr glTextureParameterf_proc = nullptr;

using glTextureParameterfv_ptr                     = void (*)(uint32 texture, GLenum pname, const float32* param);
glTextureParameterfv_ptr glTextureParameterfv_proc = nullptr;

using glTextureParameteri_ptr                    = void (*)(uint32 texture, GLenum pname, int32 param);
glTextureParameteri_ptr glTextureParameteri_proc = nullptr;

using glTextureParameterIiv_ptr                      = void (*)(uint32 texture, GLenum pname, const int32* params);
glTextureParameterIiv_ptr glTextureParameterIiv_proc = nullptr;

using glTextureParameterIuiv_ptr                       = void (*)(uint32 texture, GLenum pname, const uint32* params);
glTextureParameterIuiv_ptr glTextureParameterIuiv_proc = nullptr;

using glTextureParameteriv_ptr                     = void (*)(uint32 texture, GLenum pname, const int32* param);
glTextureParameteriv_ptr glTextureParameteriv_proc = nullptr;

using glGenerateTextureMipmap_ptr                        = void (*)(uint32 texture);
glGenerateTextureMipmap_ptr glGenerateTextureMipmap_proc = nullptr;

using glBindTextureUnit_ptr                  = void (*)(uint32 unit, uint32 texture);
glBindTextureUnit_ptr glBindTextureUnit_proc = nullptr;

using glGetTextureImage_ptr =
void (*)(uint32 texture, int32 level, GLenum format, GLenum type, int32 bufSize, void* pixels);
glGetTextureImage_ptr glGetTextureImage_proc = nullptr;

using glGetCompressedTextureImage_ptr = void (*)(uint32 texture, int32 level, int32 bufSize, void* pixels);
glGetCompressedTextureImage_ptr glGetCompressedTextureImage_proc = nullptr;

using glGetTextureLevelParameterfv_ptr = void (*)(uint32 texture, int32 level, GLenum pname, float32* params);
glGetTextureLevelParameterfv_ptr glGetTextureLevelParameterfv_proc = nullptr;

using glGetTextureLevelParameteriv_ptr = void (*)(uint32 texture, int32 level, GLenum pname, int32* params);
glGetTextureLevelParameteriv_ptr glGetTextureLevelParameteriv_proc = nullptr;

using glGetTextureParameterfv_ptr                        = void (*)(uint32 texture, GLenum pname, float32* params);
glGetTextureParameterfv_ptr glGetTextureParameterfv_proc = nullptr;

using glGetTextureParameterIiv_ptr                         = void (*)(uint32 texture, GLenum pname, int32* params);
glGetTextureParameterIiv_ptr glGetTextureParameterIiv_proc = nullptr;

using glGetTextureParameterIuiv_ptr                          = void (*)(uint32 texture, GLenum pname, uint32* params);
glGetTextureParameterIuiv_ptr glGetTextureParameterIuiv_proc = nullptr;

using glGetTextureParameteriv_ptr                        = void (*)(uint32 texture, GLenum pname, int32* params);
glGetTextureParameteriv_ptr glGetTextureParameteriv_proc = nullptr;

using glCreateVertexArrays_ptr                     = void (*)(int32 n, uint32* arrays);
glCreateVertexArrays_ptr glCreateVertexArrays_proc = nullptr;

using glDisableVertexArrayAttrib_ptr                           = void (*)(uint32 vaobj, uint32 index);
glDisableVertexArrayAttrib_ptr glDisableVertexArrayAttrib_proc = nullptr;

using glEnableVertexArrayAttrib_ptr                          = void (*)(uint32 vaobj, uint32 index);
glEnableVertexArrayAttrib_ptr glEnableVertexArrayAttrib_proc = nullptr;

using glVertexArrayElementBuffer_ptr                           = void (*)(uint32 vaobj, uint32 buffer);
glVertexArrayElementBuffer_ptr glVertexArrayElementBuffer_proc = nullptr;

using glVertexArrayVertexBuffer_ptr =
void (*)(uint32 vaobj, uint32 bindingindex, uint32 buffer, ptrdiff offset, int32 stride);
glVertexArrayVertexBuffer_ptr glVertexArrayVertexBuffer_proc = nullptr;

using glVertexArrayVertexBuffers_ptr =
void (*)(uint32 vaobj, uint32 first, int32 count, const uint32* buffers, const ptrdiff* offsets, const int32* strides);
glVertexArrayVertexBuffers_ptr glVertexArrayVertexBuffers_proc = nullptr;

using glVertexArrayAttribBinding_ptr = void (*)(uint32 vaobj, uint32 attribindex, uint32 bindingindex);
glVertexArrayAttribBinding_ptr glVertexArrayAttribBinding_proc = nullptr;

using glVertexArrayAttribFormat_ptr =
void (*)(uint32 vaobj, uint32 attribindex, int32 size, GLenum type, bool normalized, uint32 relativeoffset);
glVertexArrayAttribFormat_ptr glVertexArrayAttribFormat_proc = nullptr;

using glVertexArrayAttribIFormat_ptr =
void (*)(uint32 vaobj, uint32 attribindex, int32 size, GLenum type, uint32 relativeoffset);
glVertexArrayAttribIFormat_ptr glVertexArrayAttribIFormat_proc = nullptr;

using glVertexArrayAttribLFormat_ptr =
void (*)(uint32 vaobj, uint32 attribindex, int32 size, GLenum type, uint32 relativeoffset);
glVertexArrayAttribLFormat_ptr glVertexArrayAttribLFormat_proc = nullptr;

using glVertexArrayBindingDivisor_ptr = void (*)(uint32 vaobj, uint32 bindingindex, uint32 divisor);
glVertexArrayBindingDivisor_ptr glVertexArrayBindingDivisor_proc = nullptr;

using glGetVertexArrayiv_ptr                   = void (*)(uint32 vaobj, GLenum pname, int32* param);
glGetVertexArrayiv_ptr glGetVertexArrayiv_proc = nullptr;

using glGetVertexArrayIndexediv_ptr = void (*)(uint32 vaobj, uint32 index, GLenum pname, int32* param);
glGetVertexArrayIndexediv_ptr glGetVertexArrayIndexediv_proc = nullptr;

using glGetVertexArrayIndexed64iv_ptr = void (*)(uint32 vaobj, uint32 index, GLenum pname, int64* param);
glGetVertexArrayIndexed64iv_ptr glGetVertexArrayIndexed64iv_proc = nullptr;

using glCreateSamplers_ptr                 = void (*)(int32 n, uint32* samplers);
glCreateSamplers_ptr glCreateSamplers_proc = nullptr;

using glCreateProgramPipelines_ptr                         = void (*)(int32 n, uint32* pipelines);
glCreateProgramPipelines_ptr glCreateProgramPipelines_proc = nullptr;

using glCreateQueries_ptr                = void (*)(GLenum target, int32 n, uint32* ids);
glCreateQueries_ptr glCreateQueries_proc = nullptr;

using glGetQueryBufferObjecti64v_ptr = void (*)(uint32 id, uint32 buffer, GLenum pname, ptrdiff offset);
glGetQueryBufferObjecti64v_ptr glGetQueryBufferObjecti64v_proc = nullptr;

using glGetQueryBufferObjectiv_ptr = void (*)(uint32 id, uint32 buffer, GLenum pname, ptrdiff offset);
glGetQueryBufferObjectiv_ptr glGetQueryBufferObjectiv_proc = nullptr;

using glGetQueryBufferObjectui64v_ptr = void (*)(uint32 id, uint32 buffer, GLenum pname, ptrdiff offset);
glGetQueryBufferObjectui64v_ptr glGetQueryBufferObjectui64v_proc = nullptr;

using glGetQueryBufferObjectuiv_ptr = void (*)(uint32 id, uint32 buffer, GLenum pname, ptrdiff offset);
glGetQueryBufferObjectuiv_ptr glGetQueryBufferObjectuiv_proc = nullptr;

using glMemoryBarrierByRegion_ptr                        = void (*)(uint32 barriers);
glMemoryBarrierByRegion_ptr glMemoryBarrierByRegion_proc = nullptr;

using glGetTextureSubImage_ptr                     = void (*)(uint32 texture,
                                          int32 level,
                                          int32 xoffset,
                                          int32 yoffset,
                                          int32 zoffset,
                                          int32 width,
                                          int32 height,
                                          int32 depth,
                                          GLenum format,
                                          GLenum type,
                                          int32 bufSize,
                                          void* pixels);
glGetTextureSubImage_ptr glGetTextureSubImage_proc = nullptr;

using glGetCompressedTextureSubImage_ptr                               = void (*)(uint32 texture,
                                                    int32 level,
                                                    int32 xoffset,
                                                    int32 yoffset,
                                                    int32 zoffset,
                                                    int32 width,
                                                    int32 height,
                                                    int32 depth,
                                                    int32 bufSize,
                                                    void* pixels);
glGetCompressedTextureSubImage_ptr glGetCompressedTextureSubImage_proc = nullptr;

using glGetGraphicsResetStatus_ptr                         = GLenum (*)();
glGetGraphicsResetStatus_ptr glGetGraphicsResetStatus_proc = nullptr;

using glGetnCompressedTexImage_ptr = void (*)(GLenum target, int32 lod, int32 bufSize, void* pixels);
glGetnCompressedTexImage_ptr glGetnCompressedTexImage_proc = nullptr;

using glGetnTexImage_ptr = void (*)(GLenum target, int32 level, GLenum format, GLenum type, int32 bufSize, void* pixels);
glGetnTexImage_ptr glGetnTexImage_proc = nullptr;

using glGetnUniformdv_ptr                = void (*)(uint32 program, int32 location, int32 bufSize, float64* params);
glGetnUniformdv_ptr glGetnUniformdv_proc = nullptr;

using glGetnUniformfv_ptr                = void (*)(uint32 program, int32 location, int32 bufSize, float32* params);
glGetnUniformfv_ptr glGetnUniformfv_proc = nullptr;

using glGetnUniformiv_ptr                = void (*)(uint32 program, int32 location, int32 bufSize, int32* params);
glGetnUniformiv_ptr glGetnUniformiv_proc = nullptr;

using glGetnUniformuiv_ptr                 = void (*)(uint32 program, int32 location, int32 bufSize, uint32* params);
glGetnUniformuiv_ptr glGetnUniformuiv_proc = nullptr;

using glReadnPixels_ptr =
void (*)(int32 x, int32 y, int32 width, int32 height, GLenum format, GLenum type, int32 bufSize, void* data);
glReadnPixels_ptr glReadnPixels_proc = nullptr;

using glTextureBarrier_ptr                 = void (*)();
glTextureBarrier_ptr glTextureBarrier_proc = nullptr;

bool init_gl_version_4_5()
{
    using ::framework::graphic::utils::get_function;

    bool result = true;

    result = result && (glClipControl_proc = get_function<glClipControl_ptr>("glClipControl")) != nullptr;
    result = result && (glCreateTransformFeedbacks_proc = get_function<glCreateTransformFeedbacks_ptr>(
                        "glCreateTransformFeedbacks")) != nullptr;
    result = result && (glTransformFeedbackBufferBase_proc = get_function<glTransformFeedbackBufferBase_ptr>(
                        "glTransformFeedbackBufferBase")) != nullptr;
    result = result && (glTransformFeedbackBufferRange_proc = get_function<glTransformFeedbackBufferRange_ptr>(
                        "glTransformFeedbackBufferRange")) != nullptr;
    result = result &&
             (glGetTransformFeedbackiv_proc = get_function<glGetTransformFeedbackiv_ptr>("glGetTransformFeedbackiv")) !=
             nullptr;
    result = result && (glGetTransformFeedbacki_v_proc = get_function<glGetTransformFeedbacki_v_ptr>(
                        "glGetTransformFeedbacki_v")) != nullptr;
    result = result && (glGetTransformFeedbacki64_v_proc = get_function<glGetTransformFeedbacki64_v_ptr>(
                        "glGetTransformFeedbacki64_v")) != nullptr;
    result = result && (glCreateBuffers_proc = get_function<glCreateBuffers_ptr>("glCreateBuffers")) != nullptr;
    result = result &&
             (glNamedBufferStorage_proc = get_function<glNamedBufferStorage_ptr>("glNamedBufferStorage")) != nullptr;
    result = result && (glNamedBufferData_proc = get_function<glNamedBufferData_ptr>("glNamedBufferData")) != nullptr;
    result = result &&
             (glNamedBufferSubData_proc = get_function<glNamedBufferSubData_ptr>("glNamedBufferSubData")) != nullptr;
    result = result &&
             (glCopyNamedBufferSubData_proc = get_function<glCopyNamedBufferSubData_ptr>("glCopyNamedBufferSubData")) !=
             nullptr;
    result = result &&
             (glClearNamedBufferData_proc = get_function<glClearNamedBufferData_ptr>("glClearNamedBufferData")) !=
             nullptr;
    result = result && (glClearNamedBufferSubData_proc = get_function<glClearNamedBufferSubData_ptr>(
                        "glClearNamedBufferSubData")) != nullptr;
    result = result && (glMapNamedBuffer_proc = get_function<glMapNamedBuffer_ptr>("glMapNamedBuffer")) != nullptr;
    result = result &&
             (glMapNamedBufferRange_proc = get_function<glMapNamedBufferRange_ptr>("glMapNamedBufferRange")) != nullptr;
    result = result &&
             (glUnmapNamedBuffer_proc = get_function<glUnmapNamedBuffer_ptr>("glUnmapNamedBuffer")) != nullptr;
    result = result && (glFlushMappedNamedBufferRange_proc = get_function<glFlushMappedNamedBufferRange_ptr>(
                        "glFlushMappedNamedBufferRange")) != nullptr;
    result = result && (glGetNamedBufferParameteriv_proc = get_function<glGetNamedBufferParameteriv_ptr>(
                        "glGetNamedBufferParameteriv")) != nullptr;
    result = result && (glGetNamedBufferParameteri64v_proc = get_function<glGetNamedBufferParameteri64v_ptr>(
                        "glGetNamedBufferParameteri64v")) != nullptr;
    result = result &&
             (glGetNamedBufferPointerv_proc = get_function<glGetNamedBufferPointerv_ptr>("glGetNamedBufferPointerv")) !=
             nullptr;
    result = result &&
             (glGetNamedBufferSubData_proc = get_function<glGetNamedBufferSubData_ptr>("glGetNamedBufferSubData")) !=
             nullptr;
    result = result &&
             (glCreateFramebuffers_proc = get_function<glCreateFramebuffers_ptr>("glCreateFramebuffers")) != nullptr;
    result = result && (glNamedFramebufferRenderbuffer_proc = get_function<glNamedFramebufferRenderbuffer_ptr>(
                        "glNamedFramebufferRenderbuffer")) != nullptr;
    result = result && (glNamedFramebufferParameteri_proc = get_function<glNamedFramebufferParameteri_ptr>(
                        "glNamedFramebufferParameteri")) != nullptr;
    result = result && (glNamedFramebufferTexture_proc = get_function<glNamedFramebufferTexture_ptr>(
                        "glNamedFramebufferTexture")) != nullptr;
    result = result && (glNamedFramebufferTextureLayer_proc = get_function<glNamedFramebufferTextureLayer_ptr>(
                        "glNamedFramebufferTextureLayer")) != nullptr;
    result = result && (glNamedFramebufferDrawBuffer_proc = get_function<glNamedFramebufferDrawBuffer_ptr>(
                        "glNamedFramebufferDrawBuffer")) != nullptr;
    result = result && (glNamedFramebufferDrawBuffers_proc = get_function<glNamedFramebufferDrawBuffers_ptr>(
                        "glNamedFramebufferDrawBuffers")) != nullptr;
    result = result && (glNamedFramebufferReadBuffer_proc = get_function<glNamedFramebufferReadBuffer_ptr>(
                        "glNamedFramebufferReadBuffer")) != nullptr;
    result = result && (glInvalidateNamedFramebufferData_proc = get_function<glInvalidateNamedFramebufferData_ptr>(
                        "glInvalidateNamedFramebufferData")) != nullptr;
    result = result &&
             (glInvalidateNamedFramebufferSubData_proc = get_function<glInvalidateNamedFramebufferSubData_ptr>(
              "glInvalidateNamedFramebufferSubData")) != nullptr;
    result = result && (glClearNamedFramebufferiv_proc = get_function<glClearNamedFramebufferiv_ptr>(
                        "glClearNamedFramebufferiv")) != nullptr;
    result = result && (glClearNamedFramebufferuiv_proc = get_function<glClearNamedFramebufferuiv_ptr>(
                        "glClearNamedFramebufferuiv")) != nullptr;
    result = result && (glClearNamedFramebufferfv_proc = get_function<glClearNamedFramebufferfv_ptr>(
                        "glClearNamedFramebufferfv")) != nullptr;
    result = result && (glClearNamedFramebufferfi_proc = get_function<glClearNamedFramebufferfi_ptr>(
                        "glClearNamedFramebufferfi")) != nullptr;
    result = result &&
             (glBlitNamedFramebuffer_proc = get_function<glBlitNamedFramebuffer_ptr>("glBlitNamedFramebuffer")) !=
             nullptr;
    result = result && (glCheckNamedFramebufferStatus_proc = get_function<glCheckNamedFramebufferStatus_ptr>(
                        "glCheckNamedFramebufferStatus")) != nullptr;
    result = result && (glGetNamedFramebufferParameteriv_proc = get_function<glGetNamedFramebufferParameteriv_ptr>(
                        "glGetNamedFramebufferParameteriv")) != nullptr;
    result = result &&
             (glGetNamedFramebufferAttachmentParameteriv_proc = get_function<
              glGetNamedFramebufferAttachmentParameteriv_ptr>("glGetNamedFramebufferAttachmentParameteriv")) != nullptr;
    result = result &&
             (glCreateRenderbuffers_proc = get_function<glCreateRenderbuffers_ptr>("glCreateRenderbuffers")) != nullptr;
    result = result && (glNamedRenderbufferStorage_proc = get_function<glNamedRenderbufferStorage_ptr>(
                        "glNamedRenderbufferStorage")) != nullptr;
    result = result &&
             (glNamedRenderbufferStorageMultisample_proc = get_function<glNamedRenderbufferStorageMultisample_ptr>(
              "glNamedRenderbufferStorageMultisample")) != nullptr;
    result = result && (glGetNamedRenderbufferParameteriv_proc = get_function<glGetNamedRenderbufferParameteriv_ptr>(
                        "glGetNamedRenderbufferParameteriv")) != nullptr;
    result = result && (glCreateTextures_proc = get_function<glCreateTextures_ptr>("glCreateTextures")) != nullptr;
    result = result && (glTextureBuffer_proc = get_function<glTextureBuffer_ptr>("glTextureBuffer")) != nullptr;
    result = result &&
             (glTextureBufferRange_proc = get_function<glTextureBufferRange_ptr>("glTextureBufferRange")) != nullptr;
    result = result &&
             (glTextureStorage1D_proc = get_function<glTextureStorage1D_ptr>("glTextureStorage1D")) != nullptr;
    result = result &&
             (glTextureStorage2D_proc = get_function<glTextureStorage2D_ptr>("glTextureStorage2D")) != nullptr;
    result = result &&
             (glTextureStorage3D_proc = get_function<glTextureStorage3D_ptr>("glTextureStorage3D")) != nullptr;
    result = result && (glTextureStorage2DMultisample_proc = get_function<glTextureStorage2DMultisample_ptr>(
                        "glTextureStorage2DMultisample")) != nullptr;
    result = result && (glTextureStorage3DMultisample_proc = get_function<glTextureStorage3DMultisample_ptr>(
                        "glTextureStorage3DMultisample")) != nullptr;
    result = result &&
             (glTextureSubImage1D_proc = get_function<glTextureSubImage1D_ptr>("glTextureSubImage1D")) != nullptr;
    result = result &&
             (glTextureSubImage2D_proc = get_function<glTextureSubImage2D_ptr>("glTextureSubImage2D")) != nullptr;
    result = result &&
             (glTextureSubImage3D_proc = get_function<glTextureSubImage3D_ptr>("glTextureSubImage3D")) != nullptr;
    result = result && (glCompressedTextureSubImage1D_proc = get_function<glCompressedTextureSubImage1D_ptr>(
                        "glCompressedTextureSubImage1D")) != nullptr;
    result = result && (glCompressedTextureSubImage2D_proc = get_function<glCompressedTextureSubImage2D_ptr>(
                        "glCompressedTextureSubImage2D")) != nullptr;
    result = result && (glCompressedTextureSubImage3D_proc = get_function<glCompressedTextureSubImage3D_ptr>(
                        "glCompressedTextureSubImage3D")) != nullptr;
    result = result &&
             (glCopyTextureSubImage1D_proc = get_function<glCopyTextureSubImage1D_ptr>("glCopyTextureSubImage1D")) !=
             nullptr;
    result = result &&
             (glCopyTextureSubImage2D_proc = get_function<glCopyTextureSubImage2D_ptr>("glCopyTextureSubImage2D")) !=
             nullptr;
    result = result &&
             (glCopyTextureSubImage3D_proc = get_function<glCopyTextureSubImage3D_ptr>("glCopyTextureSubImage3D")) !=
             nullptr;
    result = result &&
             (glTextureParameterf_proc = get_function<glTextureParameterf_ptr>("glTextureParameterf")) != nullptr;
    result = result &&
             (glTextureParameterfv_proc = get_function<glTextureParameterfv_ptr>("glTextureParameterfv")) != nullptr;
    result = result &&
             (glTextureParameteri_proc = get_function<glTextureParameteri_ptr>("glTextureParameteri")) != nullptr;
    result = result &&
             (glTextureParameterIiv_proc = get_function<glTextureParameterIiv_ptr>("glTextureParameterIiv")) != nullptr;
    result = result &&
             (glTextureParameterIuiv_proc = get_function<glTextureParameterIuiv_ptr>("glTextureParameterIuiv")) !=
             nullptr;
    result = result &&
             (glTextureParameteriv_proc = get_function<glTextureParameteriv_ptr>("glTextureParameteriv")) != nullptr;
    result = result &&
             (glGenerateTextureMipmap_proc = get_function<glGenerateTextureMipmap_ptr>("glGenerateTextureMipmap")) !=
             nullptr;
    result = result && (glBindTextureUnit_proc = get_function<glBindTextureUnit_ptr>("glBindTextureUnit")) != nullptr;
    result = result && (glGetTextureImage_proc = get_function<glGetTextureImage_ptr>("glGetTextureImage")) != nullptr;
    result = result && (glGetCompressedTextureImage_proc = get_function<glGetCompressedTextureImage_ptr>(
                        "glGetCompressedTextureImage")) != nullptr;
    result = result && (glGetTextureLevelParameterfv_proc = get_function<glGetTextureLevelParameterfv_ptr>(
                        "glGetTextureLevelParameterfv")) != nullptr;
    result = result && (glGetTextureLevelParameteriv_proc = get_function<glGetTextureLevelParameteriv_ptr>(
                        "glGetTextureLevelParameteriv")) != nullptr;
    result = result &&
             (glGetTextureParameterfv_proc = get_function<glGetTextureParameterfv_ptr>("glGetTextureParameterfv")) !=
             nullptr;
    result = result &&
             (glGetTextureParameterIiv_proc = get_function<glGetTextureParameterIiv_ptr>("glGetTextureParameterIiv")) !=
             nullptr;
    result = result && (glGetTextureParameterIuiv_proc = get_function<glGetTextureParameterIuiv_ptr>(
                        "glGetTextureParameterIuiv")) != nullptr;
    result = result &&
             (glGetTextureParameteriv_proc = get_function<glGetTextureParameteriv_ptr>("glGetTextureParameteriv")) !=
             nullptr;
    result = result &&
             (glCreateVertexArrays_proc = get_function<glCreateVertexArrays_ptr>("glCreateVertexArrays")) != nullptr;
    result = result && (glDisableVertexArrayAttrib_proc = get_function<glDisableVertexArrayAttrib_ptr>(
                        "glDisableVertexArrayAttrib")) != nullptr;
    result = result && (glEnableVertexArrayAttrib_proc = get_function<glEnableVertexArrayAttrib_ptr>(
                        "glEnableVertexArrayAttrib")) != nullptr;
    result = result && (glVertexArrayElementBuffer_proc = get_function<glVertexArrayElementBuffer_ptr>(
                        "glVertexArrayElementBuffer")) != nullptr;
    result = result && (glVertexArrayVertexBuffer_proc = get_function<glVertexArrayVertexBuffer_ptr>(
                        "glVertexArrayVertexBuffer")) != nullptr;
    result = result && (glVertexArrayVertexBuffers_proc = get_function<glVertexArrayVertexBuffers_ptr>(
                        "glVertexArrayVertexBuffers")) != nullptr;
    result = result && (glVertexArrayAttribBinding_proc = get_function<glVertexArrayAttribBinding_ptr>(
                        "glVertexArrayAttribBinding")) != nullptr;
    result = result && (glVertexArrayAttribFormat_proc = get_function<glVertexArrayAttribFormat_ptr>(
                        "glVertexArrayAttribFormat")) != nullptr;
    result = result && (glVertexArrayAttribIFormat_proc = get_function<glVertexArrayAttribIFormat_ptr>(
                        "glVertexArrayAttribIFormat")) != nullptr;
    result = result && (glVertexArrayAttribLFormat_proc = get_function<glVertexArrayAttribLFormat_ptr>(
                        "glVertexArrayAttribLFormat")) != nullptr;
    result = result && (glVertexArrayBindingDivisor_proc = get_function<glVertexArrayBindingDivisor_ptr>(
                        "glVertexArrayBindingDivisor")) != nullptr;
    result = result &&
             (glGetVertexArrayiv_proc = get_function<glGetVertexArrayiv_ptr>("glGetVertexArrayiv")) != nullptr;
    result = result && (glGetVertexArrayIndexediv_proc = get_function<glGetVertexArrayIndexediv_ptr>(
                        "glGetVertexArrayIndexediv")) != nullptr;
    result = result && (glGetVertexArrayIndexed64iv_proc = get_function<glGetVertexArrayIndexed64iv_ptr>(
                        "glGetVertexArrayIndexed64iv")) != nullptr;
    result = result && (glCreateSamplers_proc = get_function<glCreateSamplers_ptr>("glCreateSamplers")) != nullptr;
    result = result &&
             (glCreateProgramPipelines_proc = get_function<glCreateProgramPipelines_ptr>("glCreateProgramPipelines")) !=
             nullptr;
    result = result && (glCreateQueries_proc = get_function<glCreateQueries_ptr>("glCreateQueries")) != nullptr;
    result = result && (glGetQueryBufferObjecti64v_proc = get_function<glGetQueryBufferObjecti64v_ptr>(
                        "glGetQueryBufferObjecti64v")) != nullptr;
    result = result &&
             (glGetQueryBufferObjectiv_proc = get_function<glGetQueryBufferObjectiv_ptr>("glGetQueryBufferObjectiv")) !=
             nullptr;
    result = result && (glGetQueryBufferObjectui64v_proc = get_function<glGetQueryBufferObjectui64v_ptr>(
                        "glGetQueryBufferObjectui64v")) != nullptr;
    result = result && (glGetQueryBufferObjectuiv_proc = get_function<glGetQueryBufferObjectuiv_ptr>(
                        "glGetQueryBufferObjectuiv")) != nullptr;
    result = result &&
             (glMemoryBarrierByRegion_proc = get_function<glMemoryBarrierByRegion_ptr>("glMemoryBarrierByRegion")) !=
             nullptr;
    result = result &&
             (glGetTextureSubImage_proc = get_function<glGetTextureSubImage_ptr>("glGetTextureSubImage")) != nullptr;
    result = result && (glGetCompressedTextureSubImage_proc = get_function<glGetCompressedTextureSubImage_ptr>(
                        "glGetCompressedTextureSubImage")) != nullptr;
    result = result &&
             (glGetGraphicsResetStatus_proc = get_function<glGetGraphicsResetStatus_ptr>("glGetGraphicsResetStatus")) !=
             nullptr;
    result = result &&
             (glGetnCompressedTexImage_proc = get_function<glGetnCompressedTexImage_ptr>("glGetnCompressedTexImage")) !=
             nullptr;
    result = result && (glGetnTexImage_proc = get_function<glGetnTexImage_ptr>("glGetnTexImage")) != nullptr;
    result = result && (glGetnUniformdv_proc = get_function<glGetnUniformdv_ptr>("glGetnUniformdv")) != nullptr;
    result = result && (glGetnUniformfv_proc = get_function<glGetnUniformfv_ptr>("glGetnUniformfv")) != nullptr;
    result = result && (glGetnUniformiv_proc = get_function<glGetnUniformiv_ptr>("glGetnUniformiv")) != nullptr;
    result = result && (glGetnUniformuiv_proc = get_function<glGetnUniformuiv_ptr>("glGetnUniformuiv")) != nullptr;
    result = result && (glReadnPixels_proc = get_function<glReadnPixels_ptr>("glReadnPixels")) != nullptr;
    result = result && (glTextureBarrier_proc = get_function<glTextureBarrier_ptr>("glTextureBarrier")) != nullptr;

    return result;
}

#pragma endregion

#pragma region gl_version_4_6

using glSpecializeShader_ptr                   = void (*)(uint32 shader,
                                        const char* pEntryPoint,
                                        uint32 numSpecializationConstants,
                                        const uint32* pConstantIndex,
                                        const uint32* pConstantValue);
glSpecializeShader_ptr glSpecializeShader_proc = nullptr;

using glMultiDrawArraysIndirectCount_ptr =
void (*)(GLenum mode, const void* indirect, ptrdiff drawcount, int32 maxdrawcount, int32 stride);
glMultiDrawArraysIndirectCount_ptr glMultiDrawArraysIndirectCount_proc = nullptr;

using glMultiDrawElementsIndirectCount_ptr =
void (*)(GLenum mode, GLenum type, const void* indirect, ptrdiff drawcount, int32 maxdrawcount, int32 stride);
glMultiDrawElementsIndirectCount_ptr glMultiDrawElementsIndirectCount_proc = nullptr;

using glPolygonOffsetClamp_ptr                     = void (*)(float32 factor, float32 units, float32 clamp);
glPolygonOffsetClamp_ptr glPolygonOffsetClamp_proc = nullptr;

bool init_gl_version_4_6()
{
    using ::framework::graphic::utils::get_function;

    bool result = true;

    result = result &&
             (glSpecializeShader_proc = get_function<glSpecializeShader_ptr>("glSpecializeShader")) != nullptr;
    result = result && (glMultiDrawArraysIndirectCount_proc = get_function<glMultiDrawArraysIndirectCount_ptr>(
                        "glMultiDrawArraysIndirectCount")) != nullptr;
    result = result && (glMultiDrawElementsIndirectCount_proc = get_function<glMultiDrawElementsIndirectCount_ptr>(
                        "glMultiDrawElementsIndirectCount")) != nullptr;
    result = result &&
             (glPolygonOffsetClamp_proc = get_function<glPolygonOffsetClamp_ptr>("glPolygonOffsetClamp")) != nullptr;

    return result;
}

#pragma endregion

} // namespace

namespace framework
{
namespace graphic
{
namespace gl
{
bool init_core()
{
    bool result = true;

    result = result && init_gl_version_1_0();
    result = result && init_gl_version_1_1();
    result = result && init_gl_version_1_2();
    result = result && init_gl_version_1_3();
    result = result && init_gl_version_1_4();
    result = result && init_gl_version_1_5();
    result = result && init_gl_version_2_0();
    result = result && init_gl_version_2_1();
    result = result && init_gl_version_3_0();
    result = result && init_gl_version_3_1();
    result = result && init_gl_version_3_2();
    result = result && init_gl_version_3_3();
    result = result && init_gl_version_4_0();
    result = result && init_gl_version_4_1();
    result = result && init_gl_version_4_2();
    result = result && init_gl_version_4_3();
    result = result && init_gl_version_4_4();
    result = result && init_gl_version_4_5();
    result = result && init_gl_version_4_6();

    return result;
}

/// @name gl_version_1_0
/// @{
#pragma region gl_version_1_0

void glCullFace(GLenum mode)
{
    glCullFace_proc(mode);
}

void glFrontFace(GLenum mode)
{
    glFrontFace_proc(mode);
}

void glHint(GLenum target, GLenum mode)
{
    glHint_proc(target, mode);
}

void glLineWidth(float32 width)
{
    glLineWidth_proc(width);
}

void glPointSize(float32 size)
{
    glPointSize_proc(size);
}

void glPolygonMode(GLenum face, GLenum mode)
{
    glPolygonMode_proc(face, mode);
}

void glScissor(int32 x, int32 y, int32 width, int32 height)
{
    glScissor_proc(x, y, width, height);
}

void glTexParameterf(GLenum target, GLenum pname, float32 param)
{
    glTexParameterf_proc(target, pname, param);
}

void glTexParameterfv(GLenum target, GLenum pname, const float32* params)
{
    glTexParameterfv_proc(target, pname, params);
}

void glTexParameteri(GLenum target, GLenum pname, int32 param)
{
    glTexParameteri_proc(target, pname, param);
}

void glTexParameteriv(GLenum target, GLenum pname, const int32* params)
{
    glTexParameteriv_proc(target, pname, params);
}

void glTexImage1D(GLenum target,
                  int32 level,
                  int32 internalformat,
                  int32 width,
                  int32 border,
                  GLenum format,
                  GLenum type,
                  const void* pixels)
{
    glTexImage1D_proc(target, level, internalformat, width, border, format, type, pixels);
}

void glTexImage2D(GLenum target,
                  int32 level,
                  int32 internalformat,
                  int32 width,
                  int32 height,
                  int32 border,
                  GLenum format,
                  GLenum type,
                  const void* pixels)
{
    glTexImage2D_proc(target, level, internalformat, width, height, border, format, type, pixels);
}

void glDrawBuffer(GLenum buf)
{
    glDrawBuffer_proc(buf);
}

void glClear(uint32 mask)
{
    glClear_proc(mask);
}

void glClearColor(float32 red, float32 green, float32 blue, float32 alpha)
{
    glClearColor_proc(red, green, blue, alpha);
}

void glClearStencil(int32 s)
{
    glClearStencil_proc(s);
}

void glClearDepth(float64 depth)
{
    glClearDepth_proc(depth);
}

void glStencilMask(uint32 mask)
{
    glStencilMask_proc(mask);
}

void glColorMask(bool red, bool green, bool blue, bool alpha)
{
    glColorMask_proc(red, green, blue, alpha);
}

void glDepthMask(bool flag)
{
    glDepthMask_proc(flag);
}

void glDisable(GLenum cap)
{
    glDisable_proc(cap);
}

void glEnable(GLenum cap)
{
    glEnable_proc(cap);
}

void glFinish()
{
    glFinish_proc();
}

void glFlush()
{
    glFlush_proc();
}

void glBlendFunc(GLenum sfactor, GLenum dfactor)
{
    glBlendFunc_proc(sfactor, dfactor);
}

void glLogicOp(GLenum opcode)
{
    glLogicOp_proc(opcode);
}

void glStencilFunc(GLenum func, int32 ref, uint32 mask)
{
    glStencilFunc_proc(func, ref, mask);
}

void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass)
{
    glStencilOp_proc(fail, zfail, zpass);
}

void glDepthFunc(GLenum func)
{
    glDepthFunc_proc(func);
}

void glPixelStoref(GLenum pname, float32 param)
{
    glPixelStoref_proc(pname, param);
}

void glPixelStorei(GLenum pname, int32 param)
{
    glPixelStorei_proc(pname, param);
}

void glReadBuffer(GLenum src)
{
    glReadBuffer_proc(src);
}

void glReadPixels(int32 x, int32 y, int32 width, int32 height, GLenum format, GLenum type, void* pixels)
{
    glReadPixels_proc(x, y, width, height, format, type, pixels);
}

void glGetBooleanv(GLenum pname, bool* data)
{
    glGetBooleanv_proc(pname, data);
}

void glGetDoublev(GLenum pname, float64* data)
{
    glGetDoublev_proc(pname, data);
}

GLenum glGetError()
{
    return glGetError_proc();
}

void glGetFloatv(GLenum pname, float32* data)
{
    glGetFloatv_proc(pname, data);
}

void glGetIntegerv(GLenum pname, int32* data)
{
    glGetIntegerv_proc(pname, data);
}

const uint8* glGetString(GLenum name)
{
    return glGetString_proc(name);
}

void glGetTexImage(GLenum target, int32 level, GLenum format, GLenum type, void* pixels)
{
    glGetTexImage_proc(target, level, format, type, pixels);
}

void glGetTexParameterfv(GLenum target, GLenum pname, float32* params)
{
    glGetTexParameterfv_proc(target, pname, params);
}

void glGetTexParameteriv(GLenum target, GLenum pname, int32* params)
{
    glGetTexParameteriv_proc(target, pname, params);
}

void glGetTexLevelParameterfv(GLenum target, int32 level, GLenum pname, float32* params)
{
    glGetTexLevelParameterfv_proc(target, level, pname, params);
}

void glGetTexLevelParameteriv(GLenum target, int32 level, GLenum pname, int32* params)
{
    glGetTexLevelParameteriv_proc(target, level, pname, params);
}

bool glIsEnabled(GLenum cap)
{
    return glIsEnabled_proc(cap);
}

void glDepthRange(float64 near, float64 far)
{
    glDepthRange_proc(near, far);
}

void glViewport(int32 x, int32 y, int32 width, int32 height)
{
    glViewport_proc(x, y, width, height);
}

#pragma endregion
/// @}

/// @name gl_version_1_1
/// @{
#pragma region gl_version_1_1

void glDrawArrays(GLenum mode, int32 first, int32 count)
{
    glDrawArrays_proc(mode, first, count);
}

void glDrawElements(GLenum mode, int32 count, GLenum type, const void* indices)
{
    glDrawElements_proc(mode, count, type, indices);
}

void glGetPointerv(GLenum pname, void** params)
{
    glGetPointerv_proc(pname, params);
}

void glPolygonOffset(float32 factor, float32 units)
{
    glPolygonOffset_proc(factor, units);
}

void glCopyTexImage1D(GLenum target, int32 level, GLenum internalformat, int32 x, int32 y, int32 width, int32 border)
{
    glCopyTexImage1D_proc(target, level, internalformat, x, y, width, border);
}

void glCopyTexImage2D(GLenum target,
                      int32 level,
                      GLenum internalformat,
                      int32 x,
                      int32 y,
                      int32 width,
                      int32 height,
                      int32 border)
{
    glCopyTexImage2D_proc(target, level, internalformat, x, y, width, height, border);
}

void glCopyTexSubImage1D(GLenum target, int32 level, int32 xoffset, int32 x, int32 y, int32 width)
{
    glCopyTexSubImage1D_proc(target, level, xoffset, x, y, width);
}

void glCopyTexSubImage2D(GLenum target,
                         int32 level,
                         int32 xoffset,
                         int32 yoffset,
                         int32 x,
                         int32 y,
                         int32 width,
                         int32 height)
{
    glCopyTexSubImage2D_proc(target, level, xoffset, yoffset, x, y, width, height);
}

void glTexSubImage1D(GLenum target,
                     int32 level,
                     int32 xoffset,
                     int32 width,
                     GLenum format,
                     GLenum type,
                     const void* pixels)
{
    glTexSubImage1D_proc(target, level, xoffset, width, format, type, pixels);
}

void glTexSubImage2D(GLenum target,
                     int32 level,
                     int32 xoffset,
                     int32 yoffset,
                     int32 width,
                     int32 height,
                     GLenum format,
                     GLenum type,
                     const void* pixels)
{
    glTexSubImage2D_proc(target, level, xoffset, yoffset, width, height, format, type, pixels);
}

void glBindTexture(GLenum target, uint32 texture)
{
    glBindTexture_proc(target, texture);
}

void glDeleteTextures(int32 n, const uint32* textures)
{
    glDeleteTextures_proc(n, textures);
}

void glGenTextures(int32 n, uint32* textures)
{
    glGenTextures_proc(n, textures);
}

bool glIsTexture(uint32 texture)
{
    return glIsTexture_proc(texture);
}

#pragma endregion
/// @}

/// @name gl_version_1_2
/// @{
#pragma region gl_version_1_2

void glDrawRangeElements(GLenum mode, uint32 start, uint32 end, int32 count, GLenum type, const void* indices)
{
    glDrawRangeElements_proc(mode, start, end, count, type, indices);
}

void glTexImage3D(GLenum target,
                  int32 level,
                  int32 internalformat,
                  int32 width,
                  int32 height,
                  int32 depth,
                  int32 border,
                  GLenum format,
                  GLenum type,
                  const void* pixels)
{
    glTexImage3D_proc(target, level, internalformat, width, height, depth, border, format, type, pixels);
}

void glTexSubImage3D(GLenum target,
                     int32 level,
                     int32 xoffset,
                     int32 yoffset,
                     int32 zoffset,
                     int32 width,
                     int32 height,
                     int32 depth,
                     GLenum format,
                     GLenum type,
                     const void* pixels)
{
    glTexSubImage3D_proc(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}

void glCopyTexSubImage3D(GLenum target,
                         int32 level,
                         int32 xoffset,
                         int32 yoffset,
                         int32 zoffset,
                         int32 x,
                         int32 y,
                         int32 width,
                         int32 height)
{
    glCopyTexSubImage3D_proc(target, level, xoffset, yoffset, zoffset, x, y, width, height);
}

#pragma endregion
/// @}

/// @name gl_version_1_3
/// @{
#pragma region gl_version_1_3

void glActiveTexture(GLenum texture)
{
    glActiveTexture_proc(texture);
}

void glSampleCoverage(float32 value, bool invert)
{
    glSampleCoverage_proc(value, invert);
}

void glCompressedTexImage3D(GLenum target,
                            int32 level,
                            GLenum internalformat,
                            int32 width,
                            int32 height,
                            int32 depth,
                            int32 border,
                            int32 imageSize,
                            const void* data)
{
    glCompressedTexImage3D_proc(target, level, internalformat, width, height, depth, border, imageSize, data);
}

void glCompressedTexImage2D(GLenum target,
                            int32 level,
                            GLenum internalformat,
                            int32 width,
                            int32 height,
                            int32 border,
                            int32 imageSize,
                            const void* data)
{
    glCompressedTexImage2D_proc(target, level, internalformat, width, height, border, imageSize, data);
}

void glCompressedTexImage1D(GLenum target,
                            int32 level,
                            GLenum internalformat,
                            int32 width,
                            int32 border,
                            int32 imageSize,
                            const void* data)
{
    glCompressedTexImage1D_proc(target, level, internalformat, width, border, imageSize, data);
}

void glCompressedTexSubImage3D(GLenum target,
                               int32 level,
                               int32 xoffset,
                               int32 yoffset,
                               int32 zoffset,
                               int32 width,
                               int32 height,
                               int32 depth,
                               GLenum format,
                               int32 imageSize,
                               const void* data)
{
    glCompressedTexSubImage3D_proc(target,
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
                               int32 level,
                               int32 xoffset,
                               int32 yoffset,
                               int32 width,
                               int32 height,
                               GLenum format,
                               int32 imageSize,
                               const void* data)
{
    glCompressedTexSubImage2D_proc(target, level, xoffset, yoffset, width, height, format, imageSize, data);
}

void glCompressedTexSubImage1D(GLenum target,
                               int32 level,
                               int32 xoffset,
                               int32 width,
                               GLenum format,
                               int32 imageSize,
                               const void* data)
{
    glCompressedTexSubImage1D_proc(target, level, xoffset, width, format, imageSize, data);
}

void glGetCompressedTexImage(GLenum target, int32 level, void* img)
{
    glGetCompressedTexImage_proc(target, level, img);
}

#pragma endregion
/// @}

/// @name gl_version_1_4
/// @{
#pragma region gl_version_1_4

void glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha)
{
    glBlendFuncSeparate_proc(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}

void glMultiDrawArrays(GLenum mode, const int32* first, const int32* count, int32 drawcount)
{
    glMultiDrawArrays_proc(mode, first, count, drawcount);
}

void glMultiDrawElements(GLenum mode, const int32* count, GLenum type, const void* const* indices, int32 drawcount)
{
    glMultiDrawElements_proc(mode, count, type, indices, drawcount);
}

void glPointParameterf(GLenum pname, float32 param)
{
    glPointParameterf_proc(pname, param);
}

void glPointParameterfv(GLenum pname, const float32* params)
{
    glPointParameterfv_proc(pname, params);
}

void glPointParameteri(GLenum pname, int32 param)
{
    glPointParameteri_proc(pname, param);
}

void glPointParameteriv(GLenum pname, const int32* params)
{
    glPointParameteriv_proc(pname, params);
}

void glBlendColor(float32 red, float32 green, float32 blue, float32 alpha)
{
    glBlendColor_proc(red, green, blue, alpha);
}

void glBlendEquation(GLenum mode)
{
    glBlendEquation_proc(mode);
}

#pragma endregion
/// @}

/// @name gl_version_1_5
/// @{
#pragma region gl_version_1_5

void glGenQueries(int32 n, uint32* ids)
{
    glGenQueries_proc(n, ids);
}

void glDeleteQueries(int32 n, const uint32* ids)
{
    glDeleteQueries_proc(n, ids);
}

bool glIsQuery(uint32 id)
{
    return glIsQuery_proc(id);
}

void glBeginQuery(GLenum target, uint32 id)
{
    glBeginQuery_proc(target, id);
}

void glEndQuery(GLenum target)
{
    glEndQuery_proc(target);
}

void glGetQueryiv(GLenum target, GLenum pname, int32* params)
{
    glGetQueryiv_proc(target, pname, params);
}

void glGetQueryObjectiv(uint32 id, GLenum pname, int32* params)
{
    glGetQueryObjectiv_proc(id, pname, params);
}

void glGetQueryObjectuiv(uint32 id, GLenum pname, uint32* params)
{
    glGetQueryObjectuiv_proc(id, pname, params);
}

void glBindBuffer(GLenum target, uint32 buffer)
{
    glBindBuffer_proc(target, buffer);
}

void glDeleteBuffers(int32 n, const uint32* buffers)
{
    glDeleteBuffers_proc(n, buffers);
}

void glGenBuffers(int32 n, uint32* buffers)
{
    glGenBuffers_proc(n, buffers);
}

bool glIsBuffer(uint32 buffer)
{
    return glIsBuffer_proc(buffer);
}

void glBufferData(GLenum target, ptrdiff size, const void* data, GLenum usage)
{
    glBufferData_proc(target, size, data, usage);
}

void glBufferSubData(GLenum target, ptrdiff offset, ptrdiff size, const void* data)
{
    glBufferSubData_proc(target, offset, size, data);
}

void glGetBufferSubData(GLenum target, ptrdiff offset, ptrdiff size, void* data)
{
    glGetBufferSubData_proc(target, offset, size, data);
}

void* glMapBuffer(GLenum target, GLenum access)
{
    return glMapBuffer_proc(target, access);
}

bool glUnmapBuffer(GLenum target)
{
    return glUnmapBuffer_proc(target);
}

void glGetBufferParameteriv(GLenum target, GLenum pname, int32* params)
{
    glGetBufferParameteriv_proc(target, pname, params);
}

void glGetBufferPointerv(GLenum target, GLenum pname, void** params)
{
    glGetBufferPointerv_proc(target, pname, params);
}

#pragma endregion
/// @}

/// @name gl_version_2_0
/// @{
#pragma region gl_version_2_0

void glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha)
{
    glBlendEquationSeparate_proc(modeRGB, modeAlpha);
}

void glDrawBuffers(int32 n, const GLenum* bufs)
{
    glDrawBuffers_proc(n, bufs);
}

void glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass)
{
    glStencilOpSeparate_proc(face, sfail, dpfail, dppass);
}

void glStencilFuncSeparate(GLenum face, GLenum func, int32 ref, uint32 mask)
{
    glStencilFuncSeparate_proc(face, func, ref, mask);
}

void glStencilMaskSeparate(GLenum face, uint32 mask)
{
    glStencilMaskSeparate_proc(face, mask);
}

void glAttachShader(uint32 program, uint32 shader)
{
    glAttachShader_proc(program, shader);
}

void glBindAttribLocation(uint32 program, uint32 index, const char* name)
{
    glBindAttribLocation_proc(program, index, name);
}

void glCompileShader(uint32 shader)
{
    glCompileShader_proc(shader);
}

uint32 glCreateProgram()
{
    return glCreateProgram_proc();
}

uint32 glCreateShader(GLenum type)
{
    return glCreateShader_proc(type);
}

void glDeleteProgram(uint32 program)
{
    glDeleteProgram_proc(program);
}

void glDeleteShader(uint32 shader)
{
    glDeleteShader_proc(shader);
}

void glDetachShader(uint32 program, uint32 shader)
{
    glDetachShader_proc(program, shader);
}

void glDisableVertexAttribArray(uint32 index)
{
    glDisableVertexAttribArray_proc(index);
}

void glEnableVertexAttribArray(uint32 index)
{
    glEnableVertexAttribArray_proc(index);
}

void glGetActiveAttrib(uint32 program, uint32 index, int32 bufSize, int32* length, int32* size, GLenum* type, char* name)
{
    glGetActiveAttrib_proc(program, index, bufSize, length, size, type, name);
}

void glGetActiveUniform(uint32 program,
                        uint32 index,
                        int32 bufSize,
                        int32* length,
                        int32* size,
                        GLenum* type,
                        char* name)
{
    glGetActiveUniform_proc(program, index, bufSize, length, size, type, name);
}

void glGetAttachedShaders(uint32 program, int32 maxCount, int32* count, uint32* shaders)
{
    glGetAttachedShaders_proc(program, maxCount, count, shaders);
}

int32 glGetAttribLocation(uint32 program, const char* name)
{
    return glGetAttribLocation_proc(program, name);
}

void glGetProgramiv(uint32 program, GLenum pname, int32* params)
{
    glGetProgramiv_proc(program, pname, params);
}

void glGetProgramInfoLog(uint32 program, int32 bufSize, int32* length, char* infoLog)
{
    glGetProgramInfoLog_proc(program, bufSize, length, infoLog);
}

void glGetShaderiv(uint32 shader, GLenum pname, int32* params)
{
    glGetShaderiv_proc(shader, pname, params);
}

void glGetShaderInfoLog(uint32 shader, int32 bufSize, int32* length, char* infoLog)
{
    glGetShaderInfoLog_proc(shader, bufSize, length, infoLog);
}

void glGetShaderSource(uint32 shader, int32 bufSize, int32* length, char* source)
{
    glGetShaderSource_proc(shader, bufSize, length, source);
}

int32 glGetUniformLocation(uint32 program, const char* name)
{
    return glGetUniformLocation_proc(program, name);
}

void glGetUniformfv(uint32 program, int32 location, float32* params)
{
    glGetUniformfv_proc(program, location, params);
}

void glGetUniformiv(uint32 program, int32 location, int32* params)
{
    glGetUniformiv_proc(program, location, params);
}

void glGetVertexAttribdv(uint32 index, GLenum pname, float64* params)
{
    glGetVertexAttribdv_proc(index, pname, params);
}

void glGetVertexAttribfv(uint32 index, GLenum pname, float32* params)
{
    glGetVertexAttribfv_proc(index, pname, params);
}

void glGetVertexAttribiv(uint32 index, GLenum pname, int32* params)
{
    glGetVertexAttribiv_proc(index, pname, params);
}

void glGetVertexAttribPointerv(uint32 index, GLenum pname, void** pointer)
{
    glGetVertexAttribPointerv_proc(index, pname, pointer);
}

bool glIsProgram(uint32 program)
{
    return glIsProgram_proc(program);
}

bool glIsShader(uint32 shader)
{
    return glIsShader_proc(shader);
}

void glLinkProgram(uint32 program)
{
    glLinkProgram_proc(program);
}

void glShaderSource(uint32 shader, int32 count, const char* const* string, const int32* length)
{
    glShaderSource_proc(shader, count, string, length);
}

void glUseProgram(uint32 program)
{
    glUseProgram_proc(program);
}

void glUniform1f(int32 location, float32 v0)
{
    glUniform1f_proc(location, v0);
}

void glUniform2f(int32 location, float32 v0, float32 v1)
{
    glUniform2f_proc(location, v0, v1);
}

void glUniform3f(int32 location, float32 v0, float32 v1, float32 v2)
{
    glUniform3f_proc(location, v0, v1, v2);
}

void glUniform4f(int32 location, float32 v0, float32 v1, float32 v2, float32 v3)
{
    glUniform4f_proc(location, v0, v1, v2, v3);
}

void glUniform1i(int32 location, int32 v0)
{
    glUniform1i_proc(location, v0);
}

void glUniform2i(int32 location, int32 v0, int32 v1)
{
    glUniform2i_proc(location, v0, v1);
}

void glUniform3i(int32 location, int32 v0, int32 v1, int32 v2)
{
    glUniform3i_proc(location, v0, v1, v2);
}

void glUniform4i(int32 location, int32 v0, int32 v1, int32 v2, int32 v3)
{
    glUniform4i_proc(location, v0, v1, v2, v3);
}

void glUniform1fv(int32 location, int32 count, const float32* value)
{
    glUniform1fv_proc(location, count, value);
}

void glUniform2fv(int32 location, int32 count, const float32* value)
{
    glUniform2fv_proc(location, count, value);
}

void glUniform3fv(int32 location, int32 count, const float32* value)
{
    glUniform3fv_proc(location, count, value);
}

void glUniform4fv(int32 location, int32 count, const float32* value)
{
    glUniform4fv_proc(location, count, value);
}

void glUniform1iv(int32 location, int32 count, const int32* value)
{
    glUniform1iv_proc(location, count, value);
}

void glUniform2iv(int32 location, int32 count, const int32* value)
{
    glUniform2iv_proc(location, count, value);
}

void glUniform3iv(int32 location, int32 count, const int32* value)
{
    glUniform3iv_proc(location, count, value);
}

void glUniform4iv(int32 location, int32 count, const int32* value)
{
    glUniform4iv_proc(location, count, value);
}

void glUniformMatrix2fv(int32 location, int32 count, bool transpose, const float32* value)
{
    glUniformMatrix2fv_proc(location, count, transpose, value);
}

void glUniformMatrix3fv(int32 location, int32 count, bool transpose, const float32* value)
{
    glUniformMatrix3fv_proc(location, count, transpose, value);
}

void glUniformMatrix4fv(int32 location, int32 count, bool transpose, const float32* value)
{
    glUniformMatrix4fv_proc(location, count, transpose, value);
}

void glValidateProgram(uint32 program)
{
    glValidateProgram_proc(program);
}

void glVertexAttrib1d(uint32 index, float64 x)
{
    glVertexAttrib1d_proc(index, x);
}

void glVertexAttrib1dv(uint32 index, const float64* v)
{
    glVertexAttrib1dv_proc(index, v);
}

void glVertexAttrib1f(uint32 index, float32 x)
{
    glVertexAttrib1f_proc(index, x);
}

void glVertexAttrib1fv(uint32 index, const float32* v)
{
    glVertexAttrib1fv_proc(index, v);
}

void glVertexAttrib1s(uint32 index, int16 x)
{
    glVertexAttrib1s_proc(index, x);
}

void glVertexAttrib1sv(uint32 index, const int16* v)
{
    glVertexAttrib1sv_proc(index, v);
}

void glVertexAttrib2d(uint32 index, float64 x, float64 y)
{
    glVertexAttrib2d_proc(index, x, y);
}

void glVertexAttrib2dv(uint32 index, const float64* v)
{
    glVertexAttrib2dv_proc(index, v);
}

void glVertexAttrib2f(uint32 index, float32 x, float32 y)
{
    glVertexAttrib2f_proc(index, x, y);
}

void glVertexAttrib2fv(uint32 index, const float32* v)
{
    glVertexAttrib2fv_proc(index, v);
}

void glVertexAttrib2s(uint32 index, int16 x, int16 y)
{
    glVertexAttrib2s_proc(index, x, y);
}

void glVertexAttrib2sv(uint32 index, const int16* v)
{
    glVertexAttrib2sv_proc(index, v);
}

void glVertexAttrib3d(uint32 index, float64 x, float64 y, float64 z)
{
    glVertexAttrib3d_proc(index, x, y, z);
}

void glVertexAttrib3dv(uint32 index, const float64* v)
{
    glVertexAttrib3dv_proc(index, v);
}

void glVertexAttrib3f(uint32 index, float32 x, float32 y, float32 z)
{
    glVertexAttrib3f_proc(index, x, y, z);
}

void glVertexAttrib3fv(uint32 index, const float32* v)
{
    glVertexAttrib3fv_proc(index, v);
}

void glVertexAttrib3s(uint32 index, int16 x, int16 y, int16 z)
{
    glVertexAttrib3s_proc(index, x, y, z);
}

void glVertexAttrib3sv(uint32 index, const int16* v)
{
    glVertexAttrib3sv_proc(index, v);
}

void glVertexAttrib4Nbv(uint32 index, const int8* v)
{
    glVertexAttrib4Nbv_proc(index, v);
}

void glVertexAttrib4Niv(uint32 index, const int32* v)
{
    glVertexAttrib4Niv_proc(index, v);
}

void glVertexAttrib4Nsv(uint32 index, const int16* v)
{
    glVertexAttrib4Nsv_proc(index, v);
}

void glVertexAttrib4Nub(uint32 index, uint8 x, uint8 y, uint8 z, uint8 w)
{
    glVertexAttrib4Nub_proc(index, x, y, z, w);
}

void glVertexAttrib4Nubv(uint32 index, const uint8* v)
{
    glVertexAttrib4Nubv_proc(index, v);
}

void glVertexAttrib4Nuiv(uint32 index, const uint32* v)
{
    glVertexAttrib4Nuiv_proc(index, v);
}

void glVertexAttrib4Nusv(uint32 index, const uint16* v)
{
    glVertexAttrib4Nusv_proc(index, v);
}

void glVertexAttrib4bv(uint32 index, const int8* v)
{
    glVertexAttrib4bv_proc(index, v);
}

void glVertexAttrib4d(uint32 index, float64 x, float64 y, float64 z, float64 w)
{
    glVertexAttrib4d_proc(index, x, y, z, w);
}

void glVertexAttrib4dv(uint32 index, const float64* v)
{
    glVertexAttrib4dv_proc(index, v);
}

void glVertexAttrib4f(uint32 index, float32 x, float32 y, float32 z, float32 w)
{
    glVertexAttrib4f_proc(index, x, y, z, w);
}

void glVertexAttrib4fv(uint32 index, const float32* v)
{
    glVertexAttrib4fv_proc(index, v);
}

void glVertexAttrib4iv(uint32 index, const int32* v)
{
    glVertexAttrib4iv_proc(index, v);
}

void glVertexAttrib4s(uint32 index, int16 x, int16 y, int16 z, int16 w)
{
    glVertexAttrib4s_proc(index, x, y, z, w);
}

void glVertexAttrib4sv(uint32 index, const int16* v)
{
    glVertexAttrib4sv_proc(index, v);
}

void glVertexAttrib4ubv(uint32 index, const uint8* v)
{
    glVertexAttrib4ubv_proc(index, v);
}

void glVertexAttrib4uiv(uint32 index, const uint32* v)
{
    glVertexAttrib4uiv_proc(index, v);
}

void glVertexAttrib4usv(uint32 index, const uint16* v)
{
    glVertexAttrib4usv_proc(index, v);
}

void glVertexAttribPointer(uint32 index, int32 size, GLenum type, bool normalized, int32 stride, const void* pointer)
{
    glVertexAttribPointer_proc(index, size, type, normalized, stride, pointer);
}

#pragma endregion
/// @}

/// @name gl_version_2_1
/// @{
#pragma region gl_version_2_1

void glUniformMatrix2x3fv(int32 location, int32 count, bool transpose, const float32* value)
{
    glUniformMatrix2x3fv_proc(location, count, transpose, value);
}

void glUniformMatrix3x2fv(int32 location, int32 count, bool transpose, const float32* value)
{
    glUniformMatrix3x2fv_proc(location, count, transpose, value);
}

void glUniformMatrix2x4fv(int32 location, int32 count, bool transpose, const float32* value)
{
    glUniformMatrix2x4fv_proc(location, count, transpose, value);
}

void glUniformMatrix4x2fv(int32 location, int32 count, bool transpose, const float32* value)
{
    glUniformMatrix4x2fv_proc(location, count, transpose, value);
}

void glUniformMatrix3x4fv(int32 location, int32 count, bool transpose, const float32* value)
{
    glUniformMatrix3x4fv_proc(location, count, transpose, value);
}

void glUniformMatrix4x3fv(int32 location, int32 count, bool transpose, const float32* value)
{
    glUniformMatrix4x3fv_proc(location, count, transpose, value);
}

#pragma endregion
/// @}

/// @name gl_version_3_0
/// @{
#pragma region gl_version_3_0

void glColorMaski(uint32 index, bool r, bool g, bool b, bool a)
{
    glColorMaski_proc(index, r, g, b, a);
}

void glGetBooleani_v(GLenum target, uint32 index, bool* data)
{
    glGetBooleani_v_proc(target, index, data);
}

void glGetIntegeri_v(GLenum target, uint32 index, int32* data)
{
    glGetIntegeri_v_proc(target, index, data);
}

void glEnablei(GLenum target, uint32 index)
{
    glEnablei_proc(target, index);
}

void glDisablei(GLenum target, uint32 index)
{
    glDisablei_proc(target, index);
}

bool glIsEnabledi(GLenum target, uint32 index)
{
    return glIsEnabledi_proc(target, index);
}

void glBeginTransformFeedback(GLenum primitiveMode)
{
    glBeginTransformFeedback_proc(primitiveMode);
}

void glEndTransformFeedback()
{
    glEndTransformFeedback_proc();
}

void glBindBufferRange(GLenum target, uint32 index, uint32 buffer, ptrdiff offset, ptrdiff size)
{
    glBindBufferRange_proc(target, index, buffer, offset, size);
}

void glBindBufferBase(GLenum target, uint32 index, uint32 buffer)
{
    glBindBufferBase_proc(target, index, buffer);
}

void glTransformFeedbackVaryings(uint32 program, int32 count, const char* const* varyings, GLenum bufferMode)
{
    glTransformFeedbackVaryings_proc(program, count, varyings, bufferMode);
}

void glGetTransformFeedbackVarying(uint32 program,
                                   uint32 index,
                                   int32 bufSize,
                                   int32* length,
                                   int32* size,
                                   GLenum* type,
                                   char* name)
{
    glGetTransformFeedbackVarying_proc(program, index, bufSize, length, size, type, name);
}

void glClampColor(GLenum target, GLenum clamp)
{
    glClampColor_proc(target, clamp);
}

void glBeginConditionalRender(uint32 id, GLenum mode)
{
    glBeginConditionalRender_proc(id, mode);
}

void glEndConditionalRender()
{
    glEndConditionalRender_proc();
}

void glVertexAttribIPointer(uint32 index, int32 size, GLenum type, int32 stride, const void* pointer)
{
    glVertexAttribIPointer_proc(index, size, type, stride, pointer);
}

void glGetVertexAttribIiv(uint32 index, GLenum pname, int32* params)
{
    glGetVertexAttribIiv_proc(index, pname, params);
}

void glGetVertexAttribIuiv(uint32 index, GLenum pname, uint32* params)
{
    glGetVertexAttribIuiv_proc(index, pname, params);
}

void glVertexAttribI1i(uint32 index, int32 x)
{
    glVertexAttribI1i_proc(index, x);
}

void glVertexAttribI2i(uint32 index, int32 x, int32 y)
{
    glVertexAttribI2i_proc(index, x, y);
}

void glVertexAttribI3i(uint32 index, int32 x, int32 y, int32 z)
{
    glVertexAttribI3i_proc(index, x, y, z);
}

void glVertexAttribI4i(uint32 index, int32 x, int32 y, int32 z, int32 w)
{
    glVertexAttribI4i_proc(index, x, y, z, w);
}

void glVertexAttribI1ui(uint32 index, uint32 x)
{
    glVertexAttribI1ui_proc(index, x);
}

void glVertexAttribI2ui(uint32 index, uint32 x, uint32 y)
{
    glVertexAttribI2ui_proc(index, x, y);
}

void glVertexAttribI3ui(uint32 index, uint32 x, uint32 y, uint32 z)
{
    glVertexAttribI3ui_proc(index, x, y, z);
}

void glVertexAttribI4ui(uint32 index, uint32 x, uint32 y, uint32 z, uint32 w)
{
    glVertexAttribI4ui_proc(index, x, y, z, w);
}

void glVertexAttribI1iv(uint32 index, const int32* v)
{
    glVertexAttribI1iv_proc(index, v);
}

void glVertexAttribI2iv(uint32 index, const int32* v)
{
    glVertexAttribI2iv_proc(index, v);
}

void glVertexAttribI3iv(uint32 index, const int32* v)
{
    glVertexAttribI3iv_proc(index, v);
}

void glVertexAttribI4iv(uint32 index, const int32* v)
{
    glVertexAttribI4iv_proc(index, v);
}

void glVertexAttribI1uiv(uint32 index, const uint32* v)
{
    glVertexAttribI1uiv_proc(index, v);
}

void glVertexAttribI2uiv(uint32 index, const uint32* v)
{
    glVertexAttribI2uiv_proc(index, v);
}

void glVertexAttribI3uiv(uint32 index, const uint32* v)
{
    glVertexAttribI3uiv_proc(index, v);
}

void glVertexAttribI4uiv(uint32 index, const uint32* v)
{
    glVertexAttribI4uiv_proc(index, v);
}

void glVertexAttribI4bv(uint32 index, const int8* v)
{
    glVertexAttribI4bv_proc(index, v);
}

void glVertexAttribI4sv(uint32 index, const int16* v)
{
    glVertexAttribI4sv_proc(index, v);
}

void glVertexAttribI4ubv(uint32 index, const uint8* v)
{
    glVertexAttribI4ubv_proc(index, v);
}

void glVertexAttribI4usv(uint32 index, const uint16* v)
{
    glVertexAttribI4usv_proc(index, v);
}

void glGetUniformuiv(uint32 program, int32 location, uint32* params)
{
    glGetUniformuiv_proc(program, location, params);
}

void glBindFragDataLocation(uint32 program, uint32 color, const char* name)
{
    glBindFragDataLocation_proc(program, color, name);
}

int32 glGetFragDataLocation(uint32 program, const char* name)
{
    return glGetFragDataLocation_proc(program, name);
}

void glUniform1ui(int32 location, uint32 v0)
{
    glUniform1ui_proc(location, v0);
}

void glUniform2ui(int32 location, uint32 v0, uint32 v1)
{
    glUniform2ui_proc(location, v0, v1);
}

void glUniform3ui(int32 location, uint32 v0, uint32 v1, uint32 v2)
{
    glUniform3ui_proc(location, v0, v1, v2);
}

void glUniform4ui(int32 location, uint32 v0, uint32 v1, uint32 v2, uint32 v3)
{
    glUniform4ui_proc(location, v0, v1, v2, v3);
}

void glUniform1uiv(int32 location, int32 count, const uint32* value)
{
    glUniform1uiv_proc(location, count, value);
}

void glUniform2uiv(int32 location, int32 count, const uint32* value)
{
    glUniform2uiv_proc(location, count, value);
}

void glUniform3uiv(int32 location, int32 count, const uint32* value)
{
    glUniform3uiv_proc(location, count, value);
}

void glUniform4uiv(int32 location, int32 count, const uint32* value)
{
    glUniform4uiv_proc(location, count, value);
}

void glTexParameterIiv(GLenum target, GLenum pname, const int32* params)
{
    glTexParameterIiv_proc(target, pname, params);
}

void glTexParameterIuiv(GLenum target, GLenum pname, const uint32* params)
{
    glTexParameterIuiv_proc(target, pname, params);
}

void glGetTexParameterIiv(GLenum target, GLenum pname, int32* params)
{
    glGetTexParameterIiv_proc(target, pname, params);
}

void glGetTexParameterIuiv(GLenum target, GLenum pname, uint32* params)
{
    glGetTexParameterIuiv_proc(target, pname, params);
}

void glClearBufferiv(GLenum buffer, int32 drawbuffer, const int32* value)
{
    glClearBufferiv_proc(buffer, drawbuffer, value);
}

void glClearBufferuiv(GLenum buffer, int32 drawbuffer, const uint32* value)
{
    glClearBufferuiv_proc(buffer, drawbuffer, value);
}

void glClearBufferfv(GLenum buffer, int32 drawbuffer, const float32* value)
{
    glClearBufferfv_proc(buffer, drawbuffer, value);
}

void glClearBufferfi(GLenum buffer, int32 drawbuffer, float32 depth, int32 stencil)
{
    glClearBufferfi_proc(buffer, drawbuffer, depth, stencil);
}

const uint8* glGetStringi(GLenum name, uint32 index)
{
    return glGetStringi_proc(name, index);
}

bool glIsRenderbuffer(uint32 renderbuffer)
{
    return glIsRenderbuffer_proc(renderbuffer);
}

void glBindRenderbuffer(GLenum target, uint32 renderbuffer)
{
    glBindRenderbuffer_proc(target, renderbuffer);
}

void glDeleteRenderbuffers(int32 n, const uint32* renderbuffers)
{
    glDeleteRenderbuffers_proc(n, renderbuffers);
}

void glGenRenderbuffers(int32 n, uint32* renderbuffers)
{
    glGenRenderbuffers_proc(n, renderbuffers);
}

void glRenderbufferStorage(GLenum target, GLenum internalformat, int32 width, int32 height)
{
    glRenderbufferStorage_proc(target, internalformat, width, height);
}

void glGetRenderbufferParameteriv(GLenum target, GLenum pname, int32* params)
{
    glGetRenderbufferParameteriv_proc(target, pname, params);
}

bool glIsFramebuffer(uint32 framebuffer)
{
    return glIsFramebuffer_proc(framebuffer);
}

void glBindFramebuffer(GLenum target, uint32 framebuffer)
{
    glBindFramebuffer_proc(target, framebuffer);
}

void glDeleteFramebuffers(int32 n, const uint32* framebuffers)
{
    glDeleteFramebuffers_proc(n, framebuffers);
}

void glGenFramebuffers(int32 n, uint32* framebuffers)
{
    glGenFramebuffers_proc(n, framebuffers);
}

GLenum glCheckFramebufferStatus(GLenum target)
{
    return glCheckFramebufferStatus_proc(target);
}

void glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, uint32 texture, int32 level)
{
    glFramebufferTexture1D_proc(target, attachment, textarget, texture, level);
}

void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, uint32 texture, int32 level)
{
    glFramebufferTexture2D_proc(target, attachment, textarget, texture, level);
}

void glFramebufferTexture3D(GLenum target,
                            GLenum attachment,
                            GLenum textarget,
                            uint32 texture,
                            int32 level,
                            int32 zoffset)
{
    glFramebufferTexture3D_proc(target, attachment, textarget, texture, level, zoffset);
}

void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, uint32 renderbuffer)
{
    glFramebufferRenderbuffer_proc(target, attachment, renderbuffertarget, renderbuffer);
}

void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, int32* params)
{
    glGetFramebufferAttachmentParameteriv_proc(target, attachment, pname, params);
}

void glGenerateMipmap(GLenum target)
{
    glGenerateMipmap_proc(target);
}

void glBlitFramebuffer(int32 srcX0,
                       int32 srcY0,
                       int32 srcX1,
                       int32 srcY1,
                       int32 dstX0,
                       int32 dstY0,
                       int32 dstX1,
                       int32 dstY1,
                       uint32 mask,
                       GLenum filter)
{
    glBlitFramebuffer_proc(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}

void glRenderbufferStorageMultisample(GLenum target, int32 samples, GLenum internalformat, int32 width, int32 height)
{
    glRenderbufferStorageMultisample_proc(target, samples, internalformat, width, height);
}

void glFramebufferTextureLayer(GLenum target, GLenum attachment, uint32 texture, int32 level, int32 layer)
{
    glFramebufferTextureLayer_proc(target, attachment, texture, level, layer);
}

void* glMapBufferRange(GLenum target, ptrdiff offset, ptrdiff length, uint32 access)
{
    return glMapBufferRange_proc(target, offset, length, access);
}

void glFlushMappedBufferRange(GLenum target, ptrdiff offset, ptrdiff length)
{
    glFlushMappedBufferRange_proc(target, offset, length);
}

void glBindVertexArray(uint32 array)
{
    glBindVertexArray_proc(array);
}

void glDeleteVertexArrays(int32 n, const uint32* arrays)
{
    glDeleteVertexArrays_proc(n, arrays);
}

void glGenVertexArrays(int32 n, uint32* arrays)
{
    glGenVertexArrays_proc(n, arrays);
}

bool glIsVertexArray(uint32 array)
{
    return glIsVertexArray_proc(array);
}

#pragma endregion
/// @}

/// @name gl_version_3_1
/// @{
#pragma region gl_version_3_1

void glDrawArraysInstanced(GLenum mode, int32 first, int32 count, int32 instancecount)
{
    glDrawArraysInstanced_proc(mode, first, count, instancecount);
}

void glDrawElementsInstanced(GLenum mode, int32 count, GLenum type, const void* indices, int32 instancecount)
{
    glDrawElementsInstanced_proc(mode, count, type, indices, instancecount);
}

void glTexBuffer(GLenum target, GLenum internalformat, uint32 buffer)
{
    glTexBuffer_proc(target, internalformat, buffer);
}

void glPrimitiveRestartIndex(uint32 index)
{
    glPrimitiveRestartIndex_proc(index);
}

void glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, ptrdiff readOffset, ptrdiff writeOffset, ptrdiff size)
{
    glCopyBufferSubData_proc(readTarget, writeTarget, readOffset, writeOffset, size);
}

void glGetUniformIndices(uint32 program, int32 uniformCount, const char* const* uniformNames, uint32* uniformIndices)
{
    glGetUniformIndices_proc(program, uniformCount, uniformNames, uniformIndices);
}

void glGetActiveUniformsiv(uint32 program, int32 uniformCount, const uint32* uniformIndices, GLenum pname, int32* params)
{
    glGetActiveUniformsiv_proc(program, uniformCount, uniformIndices, pname, params);
}

void glGetActiveUniformName(uint32 program, uint32 uniformIndex, int32 bufSize, int32* length, char* uniformName)
{
    glGetActiveUniformName_proc(program, uniformIndex, bufSize, length, uniformName);
}

uint32 glGetUniformBlockIndex(uint32 program, const char* uniformBlockName)
{
    return glGetUniformBlockIndex_proc(program, uniformBlockName);
}

void glGetActiveUniformBlockiv(uint32 program, uint32 uniformBlockIndex, GLenum pname, int32* params)
{
    glGetActiveUniformBlockiv_proc(program, uniformBlockIndex, pname, params);
}

void glGetActiveUniformBlockName(uint32 program,
                                 uint32 uniformBlockIndex,
                                 int32 bufSize,
                                 int32* length,
                                 char* uniformBlockName)
{
    glGetActiveUniformBlockName_proc(program, uniformBlockIndex, bufSize, length, uniformBlockName);
}

void glUniformBlockBinding(uint32 program, uint32 uniformBlockIndex, uint32 uniformBlockBinding)
{
    glUniformBlockBinding_proc(program, uniformBlockIndex, uniformBlockBinding);
}

#pragma endregion
/// @}

/// @name gl_version_3_2
/// @{
#pragma region gl_version_3_2

void glDrawElementsBaseVertex(GLenum mode, int32 count, GLenum type, const void* indices, int32 basevertex)
{
    glDrawElementsBaseVertex_proc(mode, count, type, indices, basevertex);
}

void glDrawRangeElementsBaseVertex(GLenum mode,
                                   uint32 start,
                                   uint32 end,
                                   int32 count,
                                   GLenum type,
                                   const void* indices,
                                   int32 basevertex)
{
    glDrawRangeElementsBaseVertex_proc(mode, start, end, count, type, indices, basevertex);
}

void glDrawElementsInstancedBaseVertex(GLenum mode,
                                       int32 count,
                                       GLenum type,
                                       const void* indices,
                                       int32 instancecount,
                                       int32 basevertex)
{
    glDrawElementsInstancedBaseVertex_proc(mode, count, type, indices, instancecount, basevertex);
}

void glMultiDrawElementsBaseVertex(GLenum mode,
                                   const int32* count,
                                   GLenum type,
                                   const void* const* indices,
                                   int32 drawcount,
                                   const int32* basevertex)
{
    glMultiDrawElementsBaseVertex_proc(mode, count, type, indices, drawcount, basevertex);
}

void glProvokingVertex(GLenum mode)
{
    glProvokingVertex_proc(mode);
}

GLsync glFenceSync(GLenum condition, uint32 flags)
{
    return glFenceSync_proc(condition, flags);
}

bool glIsSync(GLsync sync)
{
    return glIsSync_proc(sync);
}

void glDeleteSync(GLsync sync)
{
    glDeleteSync_proc(sync);
}

GLenum glClientWaitSync(GLsync sync, uint32 flags, uint64 timeout)
{
    return glClientWaitSync_proc(sync, flags, timeout);
}

void glWaitSync(GLsync sync, uint32 flags, uint64 timeout)
{
    glWaitSync_proc(sync, flags, timeout);
}

void glGetInteger64v(GLenum pname, int64* data)
{
    glGetInteger64v_proc(pname, data);
}

void glGetSynciv(GLsync sync, GLenum pname, int32 bufSize, int32* length, int32* values)
{
    glGetSynciv_proc(sync, pname, bufSize, length, values);
}

void glGetInteger64i_v(GLenum target, uint32 index, int64* data)
{
    glGetInteger64i_v_proc(target, index, data);
}

void glGetBufferParameteri64v(GLenum target, GLenum pname, int64* params)
{
    glGetBufferParameteri64v_proc(target, pname, params);
}

void glFramebufferTexture(GLenum target, GLenum attachment, uint32 texture, int32 level)
{
    glFramebufferTexture_proc(target, attachment, texture, level);
}

void glTexImage2DMultisample(GLenum target,
                             int32 samples,
                             GLenum internalformat,
                             int32 width,
                             int32 height,
                             bool fixedsamplelocations)
{
    glTexImage2DMultisample_proc(target, samples, internalformat, width, height, fixedsamplelocations);
}

void glTexImage3DMultisample(GLenum target,
                             int32 samples,
                             GLenum internalformat,
                             int32 width,
                             int32 height,
                             int32 depth,
                             bool fixedsamplelocations)
{
    glTexImage3DMultisample_proc(target, samples, internalformat, width, height, depth, fixedsamplelocations);
}

void glGetMultisamplefv(GLenum pname, uint32 index, float32* val)
{
    glGetMultisamplefv_proc(pname, index, val);
}

void glSampleMaski(uint32 maskNumber, uint32 mask)
{
    glSampleMaski_proc(maskNumber, mask);
}

#pragma endregion
/// @}

/// @name gl_version_3_3
/// @{
#pragma region gl_version_3_3

void glBindFragDataLocationIndexed(uint32 program, uint32 colorNumber, uint32 index, const char* name)
{
    glBindFragDataLocationIndexed_proc(program, colorNumber, index, name);
}

int32 glGetFragDataIndex(uint32 program, const char* name)
{
    return glGetFragDataIndex_proc(program, name);
}

void glGenSamplers(int32 count, uint32* samplers)
{
    glGenSamplers_proc(count, samplers);
}

void glDeleteSamplers(int32 count, const uint32* samplers)
{
    glDeleteSamplers_proc(count, samplers);
}

bool glIsSampler(uint32 sampler)
{
    return glIsSampler_proc(sampler);
}

void glBindSampler(uint32 unit, uint32 sampler)
{
    glBindSampler_proc(unit, sampler);
}

void glSamplerParameteri(uint32 sampler, GLenum pname, int32 param)
{
    glSamplerParameteri_proc(sampler, pname, param);
}

void glSamplerParameteriv(uint32 sampler, GLenum pname, const int32* param)
{
    glSamplerParameteriv_proc(sampler, pname, param);
}

void glSamplerParameterf(uint32 sampler, GLenum pname, float32 param)
{
    glSamplerParameterf_proc(sampler, pname, param);
}

void glSamplerParameterfv(uint32 sampler, GLenum pname, const float32* param)
{
    glSamplerParameterfv_proc(sampler, pname, param);
}

void glSamplerParameterIiv(uint32 sampler, GLenum pname, const int32* param)
{
    glSamplerParameterIiv_proc(sampler, pname, param);
}

void glSamplerParameterIuiv(uint32 sampler, GLenum pname, const uint32* param)
{
    glSamplerParameterIuiv_proc(sampler, pname, param);
}

void glGetSamplerParameteriv(uint32 sampler, GLenum pname, int32* params)
{
    glGetSamplerParameteriv_proc(sampler, pname, params);
}

void glGetSamplerParameterIiv(uint32 sampler, GLenum pname, int32* params)
{
    glGetSamplerParameterIiv_proc(sampler, pname, params);
}

void glGetSamplerParameterfv(uint32 sampler, GLenum pname, float32* params)
{
    glGetSamplerParameterfv_proc(sampler, pname, params);
}

void glGetSamplerParameterIuiv(uint32 sampler, GLenum pname, uint32* params)
{
    glGetSamplerParameterIuiv_proc(sampler, pname, params);
}

void glQueryCounter(uint32 id, GLenum target)
{
    glQueryCounter_proc(id, target);
}

void glGetQueryObjecti64v(uint32 id, GLenum pname, int64* params)
{
    glGetQueryObjecti64v_proc(id, pname, params);
}

void glGetQueryObjectui64v(uint32 id, GLenum pname, uint64* params)
{
    glGetQueryObjectui64v_proc(id, pname, params);
}

void glVertexAttribDivisor(uint32 index, uint32 divisor)
{
    glVertexAttribDivisor_proc(index, divisor);
}

void glVertexAttribP1ui(uint32 index, GLenum type, bool normalized, uint32 value)
{
    glVertexAttribP1ui_proc(index, type, normalized, value);
}

void glVertexAttribP1uiv(uint32 index, GLenum type, bool normalized, const uint32* value)
{
    glVertexAttribP1uiv_proc(index, type, normalized, value);
}

void glVertexAttribP2ui(uint32 index, GLenum type, bool normalized, uint32 value)
{
    glVertexAttribP2ui_proc(index, type, normalized, value);
}

void glVertexAttribP2uiv(uint32 index, GLenum type, bool normalized, const uint32* value)
{
    glVertexAttribP2uiv_proc(index, type, normalized, value);
}

void glVertexAttribP3ui(uint32 index, GLenum type, bool normalized, uint32 value)
{
    glVertexAttribP3ui_proc(index, type, normalized, value);
}

void glVertexAttribP3uiv(uint32 index, GLenum type, bool normalized, const uint32* value)
{
    glVertexAttribP3uiv_proc(index, type, normalized, value);
}

void glVertexAttribP4ui(uint32 index, GLenum type, bool normalized, uint32 value)
{
    glVertexAttribP4ui_proc(index, type, normalized, value);
}

void glVertexAttribP4uiv(uint32 index, GLenum type, bool normalized, const uint32* value)
{
    glVertexAttribP4uiv_proc(index, type, normalized, value);
}

#pragma endregion

/// @}

/// @name gl_version_4_0
/// @{
#pragma region gl_version_4_0

void glMinSampleShading(float32 value)
{
    glMinSampleShading_proc(value);
}

void glBlendEquationi(uint32 buf, GLenum mode)
{
    glBlendEquationi_proc(buf, mode);
}

void glBlendEquationSeparatei(uint32 buf, GLenum modeRGB, GLenum modeAlpha)
{
    glBlendEquationSeparatei_proc(buf, modeRGB, modeAlpha);
}

void glBlendFunci(uint32 buf, GLenum src, GLenum dst)
{
    glBlendFunci_proc(buf, src, dst);
}

void glBlendFuncSeparatei(uint32 buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)
{
    glBlendFuncSeparatei_proc(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
}

void glDrawArraysIndirect(GLenum mode, const void* indirect)
{
    glDrawArraysIndirect_proc(mode, indirect);
}

void glDrawElementsIndirect(GLenum mode, GLenum type, const void* indirect)
{
    glDrawElementsIndirect_proc(mode, type, indirect);
}

void glUniform1d(int32 location, float64 x)
{
    glUniform1d_proc(location, x);
}

void glUniform2d(int32 location, float64 x, float64 y)
{
    glUniform2d_proc(location, x, y);
}

void glUniform3d(int32 location, float64 x, float64 y, float64 z)
{
    glUniform3d_proc(location, x, y, z);
}

void glUniform4d(int32 location, float64 x, float64 y, float64 z, float64 w)
{
    glUniform4d_proc(location, x, y, z, w);
}

void glUniform1dv(int32 location, int32 count, const float64* value)
{
    glUniform1dv_proc(location, count, value);
}

void glUniform2dv(int32 location, int32 count, const float64* value)
{
    glUniform2dv_proc(location, count, value);
}

void glUniform3dv(int32 location, int32 count, const float64* value)
{
    glUniform3dv_proc(location, count, value);
}

void glUniform4dv(int32 location, int32 count, const float64* value)
{
    glUniform4dv_proc(location, count, value);
}

void glUniformMatrix2dv(int32 location, int32 count, bool transpose, const float64* value)
{
    glUniformMatrix2dv_proc(location, count, transpose, value);
}

void glUniformMatrix3dv(int32 location, int32 count, bool transpose, const float64* value)
{
    glUniformMatrix3dv_proc(location, count, transpose, value);
}

void glUniformMatrix4dv(int32 location, int32 count, bool transpose, const float64* value)
{
    glUniformMatrix4dv_proc(location, count, transpose, value);
}

void glUniformMatrix2x3dv(int32 location, int32 count, bool transpose, const float64* value)
{
    glUniformMatrix2x3dv_proc(location, count, transpose, value);
}

void glUniformMatrix2x4dv(int32 location, int32 count, bool transpose, const float64* value)
{
    glUniformMatrix2x4dv_proc(location, count, transpose, value);
}

void glUniformMatrix3x2dv(int32 location, int32 count, bool transpose, const float64* value)
{
    glUniformMatrix3x2dv_proc(location, count, transpose, value);
}

void glUniformMatrix3x4dv(int32 location, int32 count, bool transpose, const float64* value)
{
    glUniformMatrix3x4dv_proc(location, count, transpose, value);
}

void glUniformMatrix4x2dv(int32 location, int32 count, bool transpose, const float64* value)
{
    glUniformMatrix4x2dv_proc(location, count, transpose, value);
}

void glUniformMatrix4x3dv(int32 location, int32 count, bool transpose, const float64* value)
{
    glUniformMatrix4x3dv_proc(location, count, transpose, value);
}

void glGetUniformdv(uint32 program, int32 location, float64* params)
{
    glGetUniformdv_proc(program, location, params);
}

int32 glGetSubroutineUniformLocation(uint32 program, GLenum shadertype, const char* name)
{
    return glGetSubroutineUniformLocation_proc(program, shadertype, name);
}

uint32 glGetSubroutineIndex(uint32 program, GLenum shadertype, const char* name)
{
    return glGetSubroutineIndex_proc(program, shadertype, name);
}

void glGetActiveSubroutineUniformiv(uint32 program, GLenum shadertype, uint32 index, GLenum pname, int32* values)
{
    glGetActiveSubroutineUniformiv_proc(program, shadertype, index, pname, values);
}

void glGetActiveSubroutineUniformName(uint32 program,
                                      GLenum shadertype,
                                      uint32 index,
                                      int32 bufsize,
                                      int32* length,
                                      char* name)
{
    glGetActiveSubroutineUniformName_proc(program, shadertype, index, bufsize, length, name);
}

void glGetActiveSubroutineName(uint32 program, GLenum shadertype, uint32 index, int32 bufsize, int32* length, char* name)
{
    glGetActiveSubroutineName_proc(program, shadertype, index, bufsize, length, name);
}

void glUniformSubroutinesuiv(GLenum shadertype, int32 count, const uint32* indices)
{
    glUniformSubroutinesuiv_proc(shadertype, count, indices);
}

void glGetUniformSubroutineuiv(GLenum shadertype, int32 location, uint32* params)
{
    glGetUniformSubroutineuiv_proc(shadertype, location, params);
}

void glGetProgramStageiv(uint32 program, GLenum shadertype, GLenum pname, int32* values)
{
    glGetProgramStageiv_proc(program, shadertype, pname, values);
}

void glPatchParameteri(GLenum pname, int32 value)
{
    glPatchParameteri_proc(pname, value);
}

void glPatchParameterfv(GLenum pname, const float32* values)
{
    glPatchParameterfv_proc(pname, values);
}

void glBindTransformFeedback(GLenum target, uint32 id)
{
    glBindTransformFeedback_proc(target, id);
}

void glDeleteTransformFeedbacks(int32 n, const uint32* ids)
{
    glDeleteTransformFeedbacks_proc(n, ids);
}

void glGenTransformFeedbacks(int32 n, uint32* ids)
{
    glGenTransformFeedbacks_proc(n, ids);
}

bool glIsTransformFeedback(uint32 id)
{
    return glIsTransformFeedback_proc(id);
}

void glPauseTransformFeedback()
{
    glPauseTransformFeedback_proc();
}

void glResumeTransformFeedback()
{
    glResumeTransformFeedback_proc();
}

void glDrawTransformFeedback(GLenum mode, uint32 id)
{
    glDrawTransformFeedback_proc(mode, id);
}

void glDrawTransformFeedbackStream(GLenum mode, uint32 id, uint32 stream)
{
    glDrawTransformFeedbackStream_proc(mode, id, stream);
}

void glBeginQueryIndexed(GLenum target, uint32 index, uint32 id)
{
    glBeginQueryIndexed_proc(target, index, id);
}

void glEndQueryIndexed(GLenum target, uint32 index)
{
    glEndQueryIndexed_proc(target, index);
}

void glGetQueryIndexediv(GLenum target, uint32 index, GLenum pname, int32* params)
{
    glGetQueryIndexediv_proc(target, index, pname, params);
}

#pragma endregion
/// @}

/// @name gl_version_4_1
/// @{
#pragma region gl_version_4_1

void glReleaseShaderCompiler()
{
    glReleaseShaderCompiler_proc();
}

void glShaderBinary(int32 count, const uint32* shaders, GLenum binaryformat, const void* binary, int32 length)
{
    glShaderBinary_proc(count, shaders, binaryformat, binary, length);
}

void glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, int32* range, int32* precision)
{
    glGetShaderPrecisionFormat_proc(shadertype, precisiontype, range, precision);
}

void glDepthRangef(float32 n, float32 f)
{
    glDepthRangef_proc(n, f);
}

void glClearDepthf(float32 d)
{
    glClearDepthf_proc(d);
}

void glGetProgramBinary(uint32 program, int32 bufSize, int32* length, GLenum* binaryFormat, void* binary)
{
    glGetProgramBinary_proc(program, bufSize, length, binaryFormat, binary);
}

void glProgramBinary(uint32 program, GLenum binaryFormat, const void* binary, int32 length)
{
    glProgramBinary_proc(program, binaryFormat, binary, length);
}

void glProgramParameteri(uint32 program, GLenum pname, int32 value)
{
    glProgramParameteri_proc(program, pname, value);
}

void glUseProgramStages(uint32 pipeline, uint32 stages, uint32 program)
{
    glUseProgramStages_proc(pipeline, stages, program);
}

void glActiveShaderProgram(uint32 pipeline, uint32 program)
{
    glActiveShaderProgram_proc(pipeline, program);
}

uint32 glCreateShaderProgramv(GLenum type, int32 count, const char* const* strings)
{
    return glCreateShaderProgramv_proc(type, count, strings);
}

void glBindProgramPipeline(uint32 pipeline)
{
    glBindProgramPipeline_proc(pipeline);
}

void glDeleteProgramPipelines(int32 n, const uint32* pipelines)
{
    glDeleteProgramPipelines_proc(n, pipelines);
}

void glGenProgramPipelines(int32 n, uint32* pipelines)
{
    glGenProgramPipelines_proc(n, pipelines);
}

bool glIsProgramPipeline(uint32 pipeline)
{
    return glIsProgramPipeline_proc(pipeline);
}

void glGetProgramPipelineiv(uint32 pipeline, GLenum pname, int32* params)
{
    glGetProgramPipelineiv_proc(pipeline, pname, params);
}

void glProgramUniform1i(uint32 program, int32 location, int32 v0)
{
    glProgramUniform1i_proc(program, location, v0);
}

void glProgramUniform1iv(uint32 program, int32 location, int32 count, const int32* value)
{
    glProgramUniform1iv_proc(program, location, count, value);
}

void glProgramUniform1f(uint32 program, int32 location, float32 v0)
{
    glProgramUniform1f_proc(program, location, v0);
}

void glProgramUniform1fv(uint32 program, int32 location, int32 count, const float32* value)
{
    glProgramUniform1fv_proc(program, location, count, value);
}

void glProgramUniform1d(uint32 program, int32 location, float64 v0)
{
    glProgramUniform1d_proc(program, location, v0);
}

void glProgramUniform1dv(uint32 program, int32 location, int32 count, const float64* value)
{
    glProgramUniform1dv_proc(program, location, count, value);
}

void glProgramUniform1ui(uint32 program, int32 location, uint32 v0)
{
    glProgramUniform1ui_proc(program, location, v0);
}

void glProgramUniform1uiv(uint32 program, int32 location, int32 count, const uint32* value)
{
    glProgramUniform1uiv_proc(program, location, count, value);
}

void glProgramUniform2i(uint32 program, int32 location, int32 v0, int32 v1)
{
    glProgramUniform2i_proc(program, location, v0, v1);
}

void glProgramUniform2iv(uint32 program, int32 location, int32 count, const int32* value)
{
    glProgramUniform2iv_proc(program, location, count, value);
}

void glProgramUniform2f(uint32 program, int32 location, float32 v0, float32 v1)
{
    glProgramUniform2f_proc(program, location, v0, v1);
}

void glProgramUniform2fv(uint32 program, int32 location, int32 count, const float32* value)
{
    glProgramUniform2fv_proc(program, location, count, value);
}

void glProgramUniform2d(uint32 program, int32 location, float64 v0, float64 v1)
{
    glProgramUniform2d_proc(program, location, v0, v1);
}

void glProgramUniform2dv(uint32 program, int32 location, int32 count, const float64* value)
{
    glProgramUniform2dv_proc(program, location, count, value);
}

void glProgramUniform2ui(uint32 program, int32 location, uint32 v0, uint32 v1)
{
    glProgramUniform2ui_proc(program, location, v0, v1);
}

void glProgramUniform2uiv(uint32 program, int32 location, int32 count, const uint32* value)
{
    glProgramUniform2uiv_proc(program, location, count, value);
}

void glProgramUniform3i(uint32 program, int32 location, int32 v0, int32 v1, int32 v2)
{
    glProgramUniform3i_proc(program, location, v0, v1, v2);
}

void glProgramUniform3iv(uint32 program, int32 location, int32 count, const int32* value)
{
    glProgramUniform3iv_proc(program, location, count, value);
}

void glProgramUniform3f(uint32 program, int32 location, float32 v0, float32 v1, float32 v2)
{
    glProgramUniform3f_proc(program, location, v0, v1, v2);
}

void glProgramUniform3fv(uint32 program, int32 location, int32 count, const float32* value)
{
    glProgramUniform3fv_proc(program, location, count, value);
}

void glProgramUniform3d(uint32 program, int32 location, float64 v0, float64 v1, float64 v2)
{
    glProgramUniform3d_proc(program, location, v0, v1, v2);
}

void glProgramUniform3dv(uint32 program, int32 location, int32 count, const float64* value)
{
    glProgramUniform3dv_proc(program, location, count, value);
}

void glProgramUniform3ui(uint32 program, int32 location, uint32 v0, uint32 v1, uint32 v2)
{
    glProgramUniform3ui_proc(program, location, v0, v1, v2);
}

void glProgramUniform3uiv(uint32 program, int32 location, int32 count, const uint32* value)
{
    glProgramUniform3uiv_proc(program, location, count, value);
}

void glProgramUniform4i(uint32 program, int32 location, int32 v0, int32 v1, int32 v2, int32 v3)
{
    glProgramUniform4i_proc(program, location, v0, v1, v2, v3);
}

void glProgramUniform4iv(uint32 program, int32 location, int32 count, const int32* value)
{
    glProgramUniform4iv_proc(program, location, count, value);
}

void glProgramUniform4f(uint32 program, int32 location, float32 v0, float32 v1, float32 v2, float32 v3)
{
    glProgramUniform4f_proc(program, location, v0, v1, v2, v3);
}

void glProgramUniform4fv(uint32 program, int32 location, int32 count, const float32* value)
{
    glProgramUniform4fv_proc(program, location, count, value);
}

void glProgramUniform4d(uint32 program, int32 location, float64 v0, float64 v1, float64 v2, float64 v3)
{
    glProgramUniform4d_proc(program, location, v0, v1, v2, v3);
}

void glProgramUniform4dv(uint32 program, int32 location, int32 count, const float64* value)
{
    glProgramUniform4dv_proc(program, location, count, value);
}

void glProgramUniform4ui(uint32 program, int32 location, uint32 v0, uint32 v1, uint32 v2, uint32 v3)
{
    glProgramUniform4ui_proc(program, location, v0, v1, v2, v3);
}

void glProgramUniform4uiv(uint32 program, int32 location, int32 count, const uint32* value)
{
    glProgramUniform4uiv_proc(program, location, count, value);
}

void glProgramUniformMatrix2fv(uint32 program, int32 location, int32 count, bool transpose, const float32* value)
{
    glProgramUniformMatrix2fv_proc(program, location, count, transpose, value);
}

void glProgramUniformMatrix3fv(uint32 program, int32 location, int32 count, bool transpose, const float32* value)
{
    glProgramUniformMatrix3fv_proc(program, location, count, transpose, value);
}

void glProgramUniformMatrix4fv(uint32 program, int32 location, int32 count, bool transpose, const float32* value)
{
    glProgramUniformMatrix4fv_proc(program, location, count, transpose, value);
}

void glProgramUniformMatrix2dv(uint32 program, int32 location, int32 count, bool transpose, const float64* value)
{
    glProgramUniformMatrix2dv_proc(program, location, count, transpose, value);
}

void glProgramUniformMatrix3dv(uint32 program, int32 location, int32 count, bool transpose, const float64* value)
{
    glProgramUniformMatrix3dv_proc(program, location, count, transpose, value);
}

void glProgramUniformMatrix4dv(uint32 program, int32 location, int32 count, bool transpose, const float64* value)
{
    glProgramUniformMatrix4dv_proc(program, location, count, transpose, value);
}

void glProgramUniformMatrix2x3fv(uint32 program, int32 location, int32 count, bool transpose, const float32* value)
{
    glProgramUniformMatrix2x3fv_proc(program, location, count, transpose, value);
}

void glProgramUniformMatrix3x2fv(uint32 program, int32 location, int32 count, bool transpose, const float32* value)
{
    glProgramUniformMatrix3x2fv_proc(program, location, count, transpose, value);
}

void glProgramUniformMatrix2x4fv(uint32 program, int32 location, int32 count, bool transpose, const float32* value)
{
    glProgramUniformMatrix2x4fv_proc(program, location, count, transpose, value);
}

void glProgramUniformMatrix4x2fv(uint32 program, int32 location, int32 count, bool transpose, const float32* value)
{
    glProgramUniformMatrix4x2fv_proc(program, location, count, transpose, value);
}

void glProgramUniformMatrix3x4fv(uint32 program, int32 location, int32 count, bool transpose, const float32* value)
{
    glProgramUniformMatrix3x4fv_proc(program, location, count, transpose, value);
}

void glProgramUniformMatrix4x3fv(uint32 program, int32 location, int32 count, bool transpose, const float32* value)
{
    glProgramUniformMatrix4x3fv_proc(program, location, count, transpose, value);
}

void glProgramUniformMatrix2x3dv(uint32 program, int32 location, int32 count, bool transpose, const float64* value)
{
    glProgramUniformMatrix2x3dv_proc(program, location, count, transpose, value);
}

void glProgramUniformMatrix3x2dv(uint32 program, int32 location, int32 count, bool transpose, const float64* value)
{
    glProgramUniformMatrix3x2dv_proc(program, location, count, transpose, value);
}

void glProgramUniformMatrix2x4dv(uint32 program, int32 location, int32 count, bool transpose, const float64* value)
{
    glProgramUniformMatrix2x4dv_proc(program, location, count, transpose, value);
}

void glProgramUniformMatrix4x2dv(uint32 program, int32 location, int32 count, bool transpose, const float64* value)
{
    glProgramUniformMatrix4x2dv_proc(program, location, count, transpose, value);
}

void glProgramUniformMatrix3x4dv(uint32 program, int32 location, int32 count, bool transpose, const float64* value)
{
    glProgramUniformMatrix3x4dv_proc(program, location, count, transpose, value);
}

void glProgramUniformMatrix4x3dv(uint32 program, int32 location, int32 count, bool transpose, const float64* value)
{
    glProgramUniformMatrix4x3dv_proc(program, location, count, transpose, value);
}

void glValidateProgramPipeline(uint32 pipeline)
{
    glValidateProgramPipeline_proc(pipeline);
}

void glGetProgramPipelineInfoLog(uint32 pipeline, int32 bufSize, int32* length, char* infoLog)
{
    glGetProgramPipelineInfoLog_proc(pipeline, bufSize, length, infoLog);
}

void glVertexAttribL1d(uint32 index, float64 x)
{
    glVertexAttribL1d_proc(index, x);
}

void glVertexAttribL2d(uint32 index, float64 x, float64 y)
{
    glVertexAttribL2d_proc(index, x, y);
}

void glVertexAttribL3d(uint32 index, float64 x, float64 y, float64 z)
{
    glVertexAttribL3d_proc(index, x, y, z);
}

void glVertexAttribL4d(uint32 index, float64 x, float64 y, float64 z, float64 w)
{
    glVertexAttribL4d_proc(index, x, y, z, w);
}

void glVertexAttribL1dv(uint32 index, const float64* v)
{
    glVertexAttribL1dv_proc(index, v);
}

void glVertexAttribL2dv(uint32 index, const float64* v)
{
    glVertexAttribL2dv_proc(index, v);
}

void glVertexAttribL3dv(uint32 index, const float64* v)
{
    glVertexAttribL3dv_proc(index, v);
}

void glVertexAttribL4dv(uint32 index, const float64* v)
{
    glVertexAttribL4dv_proc(index, v);
}

void glVertexAttribLPointer(uint32 index, int32 size, GLenum type, int32 stride, const void* pointer)
{
    glVertexAttribLPointer_proc(index, size, type, stride, pointer);
}

void glGetVertexAttribLdv(uint32 index, GLenum pname, float64* params)
{
    glGetVertexAttribLdv_proc(index, pname, params);
}

void glViewportArrayv(uint32 first, int32 count, const float32* v)
{
    glViewportArrayv_proc(first, count, v);
}

void glViewportIndexedf(uint32 index, float32 x, float32 y, float32 w, float32 h)
{
    glViewportIndexedf_proc(index, x, y, w, h);
}

void glViewportIndexedfv(uint32 index, const float32* v)
{
    glViewportIndexedfv_proc(index, v);
}

void glScissorArrayv(uint32 first, int32 count, const int32* v)
{
    glScissorArrayv_proc(first, count, v);
}

void glScissorIndexed(uint32 index, int32 left, int32 bottom, int32 width, int32 height)
{
    glScissorIndexed_proc(index, left, bottom, width, height);
}

void glScissorIndexedv(uint32 index, const int32* v)
{
    glScissorIndexedv_proc(index, v);
}

void glDepthRangeArrayv(uint32 first, int32 count, const float64* v)
{
    glDepthRangeArrayv_proc(first, count, v);
}

void glDepthRangeIndexed(uint32 index, float64 n, float64 f)
{
    glDepthRangeIndexed_proc(index, n, f);
}

void glGetFloati_v(GLenum target, uint32 index, float32* data)
{
    glGetFloati_v_proc(target, index, data);
}

void glGetDoublei_v(GLenum target, uint32 index, float64* data)
{
    glGetDoublei_v_proc(target, index, data);
}

#pragma endregion

/// @}

/// @name gl_version_4_2
/// @{
#pragma region gl_version_4_2

void glDrawArraysInstancedBaseInstance(GLenum mode, int32 first, int32 count, int32 instancecount, uint32 baseinstance)
{
    glDrawArraysInstancedBaseInstance_proc(mode, first, count, instancecount, baseinstance);
}

void glDrawElementsInstancedBaseInstance(GLenum mode,
                                         int32 count,
                                         GLenum type,
                                         const void* indices,
                                         int32 instancecount,
                                         uint32 baseinstance)
{
    glDrawElementsInstancedBaseInstance_proc(mode, count, type, indices, instancecount, baseinstance);
}

void glDrawElementsInstancedBaseVertexBaseInstance(GLenum mode,
                                                   int32 count,
                                                   GLenum type,
                                                   const void* indices,
                                                   int32 instancecount,
                                                   int32 basevertex,
                                                   uint32 baseinstance)
{
    glDrawElementsInstancedBaseVertexBaseInstance_proc(mode,
                                                       count,
                                                       type,
                                                       indices,
                                                       instancecount,
                                                       basevertex,
                                                       baseinstance);
}

void glGetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, int32 bufSize, int32* params)
{
    glGetInternalformativ_proc(target, internalformat, pname, bufSize, params);
}

void glGetActiveAtomicCounterBufferiv(uint32 program, uint32 bufferIndex, GLenum pname, int32* params)
{
    glGetActiveAtomicCounterBufferiv_proc(program, bufferIndex, pname, params);
}

void glBindImageTexture(uint32 unit,
                        uint32 texture,
                        int32 level,
                        bool layered,
                        int32 layer,
                        GLenum access,
                        GLenum format)
{
    glBindImageTexture_proc(unit, texture, level, layered, layer, access, format);
}

void glMemoryBarrier(uint32 barriers)
{
    glMemoryBarrier_proc(barriers);
}

void glTexStorage1D(GLenum target, int32 levels, GLenum internalformat, int32 width)
{
    glTexStorage1D_proc(target, levels, internalformat, width);
}

void glTexStorage2D(GLenum target, int32 levels, GLenum internalformat, int32 width, int32 height)
{
    glTexStorage2D_proc(target, levels, internalformat, width, height);
}

void glTexStorage3D(GLenum target, int32 levels, GLenum internalformat, int32 width, int32 height, int32 depth)
{
    glTexStorage3D_proc(target, levels, internalformat, width, height, depth);
}

void glDrawTransformFeedbackInstanced(GLenum mode, uint32 id, int32 instancecount)
{
    glDrawTransformFeedbackInstanced_proc(mode, id, instancecount);
}

void glDrawTransformFeedbackStreamInstanced(GLenum mode, uint32 id, uint32 stream, int32 instancecount)
{
    glDrawTransformFeedbackStreamInstanced_proc(mode, id, stream, instancecount);
}

#pragma endregion
/// @}

/// @name gl_version_4_3
/// @{
#pragma region gl_version_4_3

void glClearBufferData(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void* data)
{
    glClearBufferData_proc(target, internalformat, format, type, data);
}

void glClearBufferSubData(GLenum target,
                          GLenum internalformat,
                          ptrdiff offset,
                          ptrdiff size,
                          GLenum format,
                          GLenum type,
                          const void* data)
{
    glClearBufferSubData_proc(target, internalformat, offset, size, format, type, data);
}

void glDispatchCompute(uint32 num_groups_x, uint32 num_groups_y, uint32 num_groups_z)
{
    glDispatchCompute_proc(num_groups_x, num_groups_y, num_groups_z);
}

void glDispatchComputeIndirect(ptrdiff indirect)
{
    glDispatchComputeIndirect_proc(indirect);
}

void glCopyImageSubData(uint32 srcName,
                        GLenum srcTarget,
                        int32 srcLevel,
                        int32 srcX,
                        int32 srcY,
                        int32 srcZ,
                        uint32 dstName,
                        GLenum dstTarget,
                        int32 dstLevel,
                        int32 dstX,
                        int32 dstY,
                        int32 dstZ,
                        int32 srcWidth,
                        int32 srcHeight,
                        int32 srcDepth)
{
    glCopyImageSubData_proc(srcName,
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

void glFramebufferParameteri(GLenum target, GLenum pname, int32 param)
{
    glFramebufferParameteri_proc(target, pname, param);
}

void glGetFramebufferParameteriv(GLenum target, GLenum pname, int32* params)
{
    glGetFramebufferParameteriv_proc(target, pname, params);
}

void glGetInternalformati64v(GLenum target, GLenum internalformat, GLenum pname, int32 bufSize, int64* params)
{
    glGetInternalformati64v_proc(target, internalformat, pname, bufSize, params);
}

void glInvalidateTexSubImage(uint32 texture,
                             int32 level,
                             int32 xoffset,
                             int32 yoffset,
                             int32 zoffset,
                             int32 width,
                             int32 height,
                             int32 depth)
{
    glInvalidateTexSubImage_proc(texture, level, xoffset, yoffset, zoffset, width, height, depth);
}

void glInvalidateTexImage(uint32 texture, int32 level)
{
    glInvalidateTexImage_proc(texture, level);
}

void glInvalidateBufferSubData(uint32 buffer, ptrdiff offset, ptrdiff length)
{
    glInvalidateBufferSubData_proc(buffer, offset, length);
}

void glInvalidateBufferData(uint32 buffer)
{
    glInvalidateBufferData_proc(buffer);
}

void glInvalidateFramebuffer(GLenum target, int32 numAttachments, const GLenum* attachments)
{
    glInvalidateFramebuffer_proc(target, numAttachments, attachments);
}

void glInvalidateSubFramebuffer(GLenum target,
                                int32 numAttachments,
                                const GLenum* attachments,
                                int32 x,
                                int32 y,
                                int32 width,
                                int32 height)
{
    glInvalidateSubFramebuffer_proc(target, numAttachments, attachments, x, y, width, height);
}

void glMultiDrawArraysIndirect(GLenum mode, const void* indirect, int32 drawcount, int32 stride)
{
    glMultiDrawArraysIndirect_proc(mode, indirect, drawcount, stride);
}

void glMultiDrawElementsIndirect(GLenum mode, GLenum type, const void* indirect, int32 drawcount, int32 stride)
{
    glMultiDrawElementsIndirect_proc(mode, type, indirect, drawcount, stride);
}

void glGetProgramInterfaceiv(uint32 program, GLenum programInterface, GLenum pname, int32* params)
{
    glGetProgramInterfaceiv_proc(program, programInterface, pname, params);
}

uint32 glGetProgramResourceIndex(uint32 program, GLenum programInterface, const char* name)
{
    return glGetProgramResourceIndex_proc(program, programInterface, name);
}

void glGetProgramResourceName(uint32 program,
                              GLenum programInterface,
                              uint32 index,
                              int32 bufSize,
                              int32* length,
                              char* name)
{
    glGetProgramResourceName_proc(program, programInterface, index, bufSize, length, name);
}

void glGetProgramResourceiv(uint32 program,
                            GLenum programInterface,
                            uint32 index,
                            int32 propCount,
                            const GLenum* props,
                            int32 bufSize,
                            int32* length,
                            int32* params)
{
    glGetProgramResourceiv_proc(program, programInterface, index, propCount, props, bufSize, length, params);
}

int32 glGetProgramResourceLocation(uint32 program, GLenum programInterface, const char* name)
{
    return glGetProgramResourceLocation_proc(program, programInterface, name);
}

int32 glGetProgramResourceLocationIndex(uint32 program, GLenum programInterface, const char* name)
{
    return glGetProgramResourceLocationIndex_proc(program, programInterface, name);
}

void glShaderStorageBlockBinding(uint32 program, uint32 storageBlockIndex, uint32 storageBlockBinding)
{
    glShaderStorageBlockBinding_proc(program, storageBlockIndex, storageBlockBinding);
}

void glTexBufferRange(GLenum target, GLenum internalformat, uint32 buffer, ptrdiff offset, ptrdiff size)
{
    glTexBufferRange_proc(target, internalformat, buffer, offset, size);
}

void glTexStorage2DMultisample(GLenum target,
                               int32 samples,
                               GLenum internalformat,
                               int32 width,
                               int32 height,
                               bool fixedsamplelocations)
{
    glTexStorage2DMultisample_proc(target, samples, internalformat, width, height, fixedsamplelocations);
}

void glTexStorage3DMultisample(GLenum target,
                               int32 samples,
                               GLenum internalformat,
                               int32 width,
                               int32 height,
                               int32 depth,
                               bool fixedsamplelocations)
{
    glTexStorage3DMultisample_proc(target, samples, internalformat, width, height, depth, fixedsamplelocations);
}

void glTextureView(uint32 texture,
                   GLenum target,
                   uint32 origtexture,
                   GLenum internalformat,
                   uint32 minlevel,
                   uint32 numlevels,
                   uint32 minlayer,
                   uint32 numlayers)
{
    glTextureView_proc(texture, target, origtexture, internalformat, minlevel, numlevels, minlayer, numlayers);
}

void glBindVertexBuffer(uint32 bindingindex, uint32 buffer, ptrdiff offset, int32 stride)
{
    glBindVertexBuffer_proc(bindingindex, buffer, offset, stride);
}

void glVertexAttribFormat(uint32 attribindex, int32 size, GLenum type, bool normalized, uint32 relativeoffset)
{
    glVertexAttribFormat_proc(attribindex, size, type, normalized, relativeoffset);
}

void glVertexAttribIFormat(uint32 attribindex, int32 size, GLenum type, uint32 relativeoffset)
{
    glVertexAttribIFormat_proc(attribindex, size, type, relativeoffset);
}

void glVertexAttribLFormat(uint32 attribindex, int32 size, GLenum type, uint32 relativeoffset)
{
    glVertexAttribLFormat_proc(attribindex, size, type, relativeoffset);
}

void glVertexAttribBinding(uint32 attribindex, uint32 bindingindex)
{
    glVertexAttribBinding_proc(attribindex, bindingindex);
}

void glVertexBindingDivisor(uint32 bindingindex, uint32 divisor)
{
    glVertexBindingDivisor_proc(bindingindex, divisor);
}

void glDebugMessageControl(GLenum source, GLenum type, GLenum severity, int32 count, const uint32* ids, bool enabled)
{
    glDebugMessageControl_proc(source, type, severity, count, ids, enabled);
}

void glDebugMessageInsert(GLenum source, GLenum type, uint32 id, GLenum severity, int32 length, const char* buf)
{
    glDebugMessageInsert_proc(source, type, id, severity, length, buf);
}

void glDebugMessageCallback(debug_proc_callback callback, const void* userParam)
{
    glDebugMessageCallback_proc(callback, userParam);
}

uint32 glGetDebugMessageLog(uint32 count,
                            int32 bufSize,
                            GLenum* sources,
                            GLenum* types,
                            uint32* ids,
                            GLenum* severities,
                            int32* lengths,
                            char* messageLog)
{
    return glGetDebugMessageLog_proc(count, bufSize, sources, types, ids, severities, lengths, messageLog);
}

void glPushDebugGroup(GLenum source, uint32 id, int32 length, const char* message)
{
    glPushDebugGroup_proc(source, id, length, message);
}

void glPopDebugGroup()
{
    glPopDebugGroup_proc();
}

void glObjectLabel(GLenum identifier, uint32 name, int32 length, const char* label)
{
    glObjectLabel_proc(identifier, name, length, label);
}

void glGetObjectLabel(GLenum identifier, uint32 name, int32 bufSize, int32* length, char* label)
{
    glGetObjectLabel_proc(identifier, name, bufSize, length, label);
}

void glObjectPtrLabel(const void* ptr, int32 length, const char* label)
{
    glObjectPtrLabel_proc(ptr, length, label);
}

void glGetObjectPtrLabel(const void* ptr, int32 bufSize, int32* length, char* label)
{
    glGetObjectPtrLabel_proc(ptr, bufSize, length, label);
}

#pragma endregion
/// @}

/// @name gl_version_4_4
/// @{
#pragma region gl_version_4_4

void glBufferStorage(GLenum target, ptrdiff size, const void* data, uint32 flags)
{
    glBufferStorage_proc(target, size, data, flags);
}

void glClearTexImage(uint32 texture, int32 level, GLenum format, GLenum type, const void* data)
{
    glClearTexImage_proc(texture, level, format, type, data);
}

void glClearTexSubImage(uint32 texture,
                        int32 level,
                        int32 xoffset,
                        int32 yoffset,
                        int32 zoffset,
                        int32 width,
                        int32 height,
                        int32 depth,
                        GLenum format,
                        GLenum type,
                        const void* data)
{
    glClearTexSubImage_proc(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, data);
}

void glBindBuffersBase(GLenum target, uint32 first, int32 count, const uint32* buffers)
{
    glBindBuffersBase_proc(target, first, count, buffers);
}

void glBindBuffersRange(GLenum target,
                        uint32 first,
                        int32 count,
                        const uint32* buffers,
                        const ptrdiff* offsets,
                        const ptrdiff* sizes)
{
    glBindBuffersRange_proc(target, first, count, buffers, offsets, sizes);
}

void glBindTextures(uint32 first, int32 count, const uint32* textures)
{
    glBindTextures_proc(first, count, textures);
}

void glBindSamplers(uint32 first, int32 count, const uint32* samplers)
{
    glBindSamplers_proc(first, count, samplers);
}

void glBindImageTextures(uint32 first, int32 count, const uint32* textures)
{
    glBindImageTextures_proc(first, count, textures);
}

void glBindVertexBuffers(uint32 first, int32 count, const uint32* buffers, const ptrdiff* offsets, const int32* strides)
{
    glBindVertexBuffers_proc(first, count, buffers, offsets, strides);
}

#pragma endregion
/// @}

/// @name gl_version_4_5
/// @{
#pragma region gl_version_4_5

void glClipControl(GLenum origin, GLenum depth)
{
    glClipControl_proc(origin, depth);
}

void glCreateTransformFeedbacks(int32 n, uint32* ids)
{
    glCreateTransformFeedbacks_proc(n, ids);
}

void glTransformFeedbackBufferBase(uint32 xfb, uint32 index, uint32 buffer)
{
    glTransformFeedbackBufferBase_proc(xfb, index, buffer);
}

void glTransformFeedbackBufferRange(uint32 xfb, uint32 index, uint32 buffer, ptrdiff offset, ptrdiff size)
{
    glTransformFeedbackBufferRange_proc(xfb, index, buffer, offset, size);
}

void glGetTransformFeedbackiv(uint32 xfb, GLenum pname, int32* param)
{
    glGetTransformFeedbackiv_proc(xfb, pname, param);
}

void glGetTransformFeedbacki_v(uint32 xfb, GLenum pname, uint32 index, int32* param)
{
    glGetTransformFeedbacki_v_proc(xfb, pname, index, param);
}

void glGetTransformFeedbacki64_v(uint32 xfb, GLenum pname, uint32 index, int64* param)
{
    glGetTransformFeedbacki64_v_proc(xfb, pname, index, param);
}

void glCreateBuffers(int32 n, uint32* buffers)
{
    glCreateBuffers_proc(n, buffers);
}

void glNamedBufferStorage(uint32 buffer, ptrdiff size, const void* data, uint32 flags)
{
    glNamedBufferStorage_proc(buffer, size, data, flags);
}

void glNamedBufferData(uint32 buffer, ptrdiff size, const void* data, GLenum usage)
{
    glNamedBufferData_proc(buffer, size, data, usage);
}

void glNamedBufferSubData(uint32 buffer, ptrdiff offset, ptrdiff size, const void* data)
{
    glNamedBufferSubData_proc(buffer, offset, size, data);
}

void glCopyNamedBufferSubData(uint32 readBuffer,
                              uint32 writeBuffer,
                              ptrdiff readOffset,
                              ptrdiff writeOffset,
                              ptrdiff size)
{
    glCopyNamedBufferSubData_proc(readBuffer, writeBuffer, readOffset, writeOffset, size);
}

void glClearNamedBufferData(uint32 buffer, GLenum internalformat, GLenum format, GLenum type, const void* data)
{
    glClearNamedBufferData_proc(buffer, internalformat, format, type, data);
}

void glClearNamedBufferSubData(uint32 buffer,
                               GLenum internalformat,
                               ptrdiff offset,
                               ptrdiff size,
                               GLenum format,
                               GLenum type,
                               const void* data)
{
    glClearNamedBufferSubData_proc(buffer, internalformat, offset, size, format, type, data);
}

void* glMapNamedBuffer(uint32 buffer, GLenum access)
{
    return glMapNamedBuffer_proc(buffer, access);
}

void* glMapNamedBufferRange(uint32 buffer, ptrdiff offset, ptrdiff length, uint32 access)
{
    return glMapNamedBufferRange_proc(buffer, offset, length, access);
}

bool glUnmapNamedBuffer(uint32 buffer)
{
    return glUnmapNamedBuffer_proc(buffer);
}

void glFlushMappedNamedBufferRange(uint32 buffer, ptrdiff offset, ptrdiff length)
{
    glFlushMappedNamedBufferRange_proc(buffer, offset, length);
}

void glGetNamedBufferParameteriv(uint32 buffer, GLenum pname, int32* params)
{
    glGetNamedBufferParameteriv_proc(buffer, pname, params);
}

void glGetNamedBufferParameteri64v(uint32 buffer, GLenum pname, int64* params)
{
    glGetNamedBufferParameteri64v_proc(buffer, pname, params);
}

void glGetNamedBufferPointerv(uint32 buffer, GLenum pname, void** params)
{
    glGetNamedBufferPointerv_proc(buffer, pname, params);
}

void glGetNamedBufferSubData(uint32 buffer, ptrdiff offset, ptrdiff size, void* data)
{
    glGetNamedBufferSubData_proc(buffer, offset, size, data);
}

void glCreateFramebuffers(int32 n, uint32* framebuffers)
{
    glCreateFramebuffers_proc(n, framebuffers);
}

void glNamedFramebufferRenderbuffer(uint32 framebuffer,
                                    GLenum attachment,
                                    GLenum renderbuffertarget,
                                    uint32 renderbuffer)
{
    glNamedFramebufferRenderbuffer_proc(framebuffer, attachment, renderbuffertarget, renderbuffer);
}

void glNamedFramebufferParameteri(uint32 framebuffer, GLenum pname, int32 param)
{
    glNamedFramebufferParameteri_proc(framebuffer, pname, param);
}

void glNamedFramebufferTexture(uint32 framebuffer, GLenum attachment, uint32 texture, int32 level)
{
    glNamedFramebufferTexture_proc(framebuffer, attachment, texture, level);
}

void glNamedFramebufferTextureLayer(uint32 framebuffer, GLenum attachment, uint32 texture, int32 level, int32 layer)
{
    glNamedFramebufferTextureLayer_proc(framebuffer, attachment, texture, level, layer);
}

void glNamedFramebufferDrawBuffer(uint32 framebuffer, GLenum buf)
{
    glNamedFramebufferDrawBuffer_proc(framebuffer, buf);
}

void glNamedFramebufferDrawBuffers(uint32 framebuffer, int32 n, const GLenum* bufs)
{
    glNamedFramebufferDrawBuffers_proc(framebuffer, n, bufs);
}

void glNamedFramebufferReadBuffer(uint32 framebuffer, GLenum src)
{
    glNamedFramebufferReadBuffer_proc(framebuffer, src);
}

void glInvalidateNamedFramebufferData(uint32 framebuffer, int32 numAttachments, const GLenum* attachments)
{
    glInvalidateNamedFramebufferData_proc(framebuffer, numAttachments, attachments);
}

void glInvalidateNamedFramebufferSubData(uint32 framebuffer,
                                         int32 numAttachments,
                                         const GLenum* attachments,
                                         int32 x,
                                         int32 y,
                                         int32 width,
                                         int32 height)
{
    glInvalidateNamedFramebufferSubData_proc(framebuffer, numAttachments, attachments, x, y, width, height);
}

void glClearNamedFramebufferiv(uint32 framebuffer, GLenum buffer, int32 drawbuffer, const int32* value)
{
    glClearNamedFramebufferiv_proc(framebuffer, buffer, drawbuffer, value);
}

void glClearNamedFramebufferuiv(uint32 framebuffer, GLenum buffer, int32 drawbuffer, const uint32* value)
{
    glClearNamedFramebufferuiv_proc(framebuffer, buffer, drawbuffer, value);
}

void glClearNamedFramebufferfv(uint32 framebuffer, GLenum buffer, int32 drawbuffer, const float32* value)
{
    glClearNamedFramebufferfv_proc(framebuffer, buffer, drawbuffer, value);
}

void glClearNamedFramebufferfi(uint32 framebuffer, GLenum buffer, int32 drawbuffer, float32 depth, int32 stencil)
{
    glClearNamedFramebufferfi_proc(framebuffer, buffer, drawbuffer, depth, stencil);
}

void glBlitNamedFramebuffer(uint32 readFramebuffer,
                            uint32 drawFramebuffer,
                            int32 srcX0,
                            int32 srcY0,
                            int32 srcX1,
                            int32 srcY1,
                            int32 dstX0,
                            int32 dstY0,
                            int32 dstX1,
                            int32 dstY1,
                            uint32 mask,
                            GLenum filter)
{
    glBlitNamedFramebuffer_proc(readFramebuffer,
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

GLenum glCheckNamedFramebufferStatus(uint32 framebuffer, GLenum target)
{
    return glCheckNamedFramebufferStatus_proc(framebuffer, target);
}

void glGetNamedFramebufferParameteriv(uint32 framebuffer, GLenum pname, int32* param)
{
    glGetNamedFramebufferParameteriv_proc(framebuffer, pname, param);
}

void glGetNamedFramebufferAttachmentParameteriv(uint32 framebuffer, GLenum attachment, GLenum pname, int32* params)
{
    glGetNamedFramebufferAttachmentParameteriv_proc(framebuffer, attachment, pname, params);
}

void glCreateRenderbuffers(int32 n, uint32* renderbuffers)
{
    glCreateRenderbuffers_proc(n, renderbuffers);
}

void glNamedRenderbufferStorage(uint32 renderbuffer, GLenum internalformat, int32 width, int32 height)
{
    glNamedRenderbufferStorage_proc(renderbuffer, internalformat, width, height);
}

void glNamedRenderbufferStorageMultisample(uint32 renderbuffer,
                                           int32 samples,
                                           GLenum internalformat,
                                           int32 width,
                                           int32 height)
{
    glNamedRenderbufferStorageMultisample_proc(renderbuffer, samples, internalformat, width, height);
}

void glGetNamedRenderbufferParameteriv(uint32 renderbuffer, GLenum pname, int32* params)
{
    glGetNamedRenderbufferParameteriv_proc(renderbuffer, pname, params);
}

void glCreateTextures(GLenum target, int32 n, uint32* textures)
{
    glCreateTextures_proc(target, n, textures);
}

void glTextureBuffer(uint32 texture, GLenum internalformat, uint32 buffer)
{
    glTextureBuffer_proc(texture, internalformat, buffer);
}

void glTextureBufferRange(uint32 texture, GLenum internalformat, uint32 buffer, ptrdiff offset, ptrdiff size)
{
    glTextureBufferRange_proc(texture, internalformat, buffer, offset, size);
}

void glTextureStorage1D(uint32 texture, int32 levels, GLenum internalformat, int32 width)
{
    glTextureStorage1D_proc(texture, levels, internalformat, width);
}

void glTextureStorage2D(uint32 texture, int32 levels, GLenum internalformat, int32 width, int32 height)
{
    glTextureStorage2D_proc(texture, levels, internalformat, width, height);
}

void glTextureStorage3D(uint32 texture, int32 levels, GLenum internalformat, int32 width, int32 height, int32 depth)
{
    glTextureStorage3D_proc(texture, levels, internalformat, width, height, depth);
}

void glTextureStorage2DMultisample(uint32 texture,
                                   int32 samples,
                                   GLenum internalformat,
                                   int32 width,
                                   int32 height,
                                   bool fixedsamplelocations)
{
    glTextureStorage2DMultisample_proc(texture, samples, internalformat, width, height, fixedsamplelocations);
}

void glTextureStorage3DMultisample(uint32 texture,
                                   int32 samples,
                                   GLenum internalformat,
                                   int32 width,
                                   int32 height,
                                   int32 depth,
                                   bool fixedsamplelocations)
{
    glTextureStorage3DMultisample_proc(texture, samples, internalformat, width, height, depth, fixedsamplelocations);
}

void glTextureSubImage1D(uint32 texture,
                         int32 level,
                         int32 xoffset,
                         int32 width,
                         GLenum format,
                         GLenum type,
                         const void* pixels)
{
    glTextureSubImage1D_proc(texture, level, xoffset, width, format, type, pixels);
}

void glTextureSubImage2D(uint32 texture,
                         int32 level,
                         int32 xoffset,
                         int32 yoffset,
                         int32 width,
                         int32 height,
                         GLenum format,
                         GLenum type,
                         const void* pixels)
{
    glTextureSubImage2D_proc(texture, level, xoffset, yoffset, width, height, format, type, pixels);
}

void glTextureSubImage3D(uint32 texture,
                         int32 level,
                         int32 xoffset,
                         int32 yoffset,
                         int32 zoffset,
                         int32 width,
                         int32 height,
                         int32 depth,
                         GLenum format,
                         GLenum type,
                         const void* pixels)
{
    glTextureSubImage3D_proc(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}

void glCompressedTextureSubImage1D(uint32 texture,
                                   int32 level,
                                   int32 xoffset,
                                   int32 width,
                                   GLenum format,
                                   int32 imageSize,
                                   const void* data)
{
    glCompressedTextureSubImage1D_proc(texture, level, xoffset, width, format, imageSize, data);
}

void glCompressedTextureSubImage2D(uint32 texture,
                                   int32 level,
                                   int32 xoffset,
                                   int32 yoffset,
                                   int32 width,
                                   int32 height,
                                   GLenum format,
                                   int32 imageSize,
                                   const void* data)
{
    glCompressedTextureSubImage2D_proc(texture, level, xoffset, yoffset, width, height, format, imageSize, data);
}

void glCompressedTextureSubImage3D(uint32 texture,
                                   int32 level,
                                   int32 xoffset,
                                   int32 yoffset,
                                   int32 zoffset,
                                   int32 width,
                                   int32 height,
                                   int32 depth,
                                   GLenum format,
                                   int32 imageSize,
                                   const void* data)
{
    glCompressedTextureSubImage3D_proc(texture,
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

void glCopyTextureSubImage1D(uint32 texture, int32 level, int32 xoffset, int32 x, int32 y, int32 width)
{
    glCopyTextureSubImage1D_proc(texture, level, xoffset, x, y, width);
}

void glCopyTextureSubImage2D(uint32 texture,
                             int32 level,
                             int32 xoffset,
                             int32 yoffset,
                             int32 x,
                             int32 y,
                             int32 width,
                             int32 height)
{
    glCopyTextureSubImage2D_proc(texture, level, xoffset, yoffset, x, y, width, height);
}

void glCopyTextureSubImage3D(uint32 texture,
                             int32 level,
                             int32 xoffset,
                             int32 yoffset,
                             int32 zoffset,
                             int32 x,
                             int32 y,
                             int32 width,
                             int32 height)
{
    glCopyTextureSubImage3D_proc(texture, level, xoffset, yoffset, zoffset, x, y, width, height);
}

void glTextureParameterf(uint32 texture, GLenum pname, float32 param)
{
    glTextureParameterf_proc(texture, pname, param);
}

void glTextureParameterfv(uint32 texture, GLenum pname, const float32* param)
{
    glTextureParameterfv_proc(texture, pname, param);
}

void glTextureParameteri(uint32 texture, GLenum pname, int32 param)
{
    glTextureParameteri_proc(texture, pname, param);
}

void glTextureParameterIiv(uint32 texture, GLenum pname, const int32* params)
{
    glTextureParameterIiv_proc(texture, pname, params);
}

void glTextureParameterIuiv(uint32 texture, GLenum pname, const uint32* params)
{
    glTextureParameterIuiv_proc(texture, pname, params);
}

void glTextureParameteriv(uint32 texture, GLenum pname, const int32* param)
{
    glTextureParameteriv_proc(texture, pname, param);
}

void glGenerateTextureMipmap(uint32 texture)
{
    glGenerateTextureMipmap_proc(texture);
}

void glBindTextureUnit(uint32 unit, uint32 texture)
{
    glBindTextureUnit_proc(unit, texture);
}

void glGetTextureImage(uint32 texture, int32 level, GLenum format, GLenum type, int32 bufSize, void* pixels)
{
    glGetTextureImage_proc(texture, level, format, type, bufSize, pixels);
}

void glGetCompressedTextureImage(uint32 texture, int32 level, int32 bufSize, void* pixels)
{
    glGetCompressedTextureImage_proc(texture, level, bufSize, pixels);
}

void glGetTextureLevelParameterfv(uint32 texture, int32 level, GLenum pname, float32* params)
{
    glGetTextureLevelParameterfv_proc(texture, level, pname, params);
}

void glGetTextureLevelParameteriv(uint32 texture, int32 level, GLenum pname, int32* params)
{
    glGetTextureLevelParameteriv_proc(texture, level, pname, params);
}

void glGetTextureParameterfv(uint32 texture, GLenum pname, float32* params)
{
    glGetTextureParameterfv_proc(texture, pname, params);
}

void glGetTextureParameterIiv(uint32 texture, GLenum pname, int32* params)
{
    glGetTextureParameterIiv_proc(texture, pname, params);
}

void glGetTextureParameterIuiv(uint32 texture, GLenum pname, uint32* params)
{
    glGetTextureParameterIuiv_proc(texture, pname, params);
}

void glGetTextureParameteriv(uint32 texture, GLenum pname, int32* params)
{
    glGetTextureParameteriv_proc(texture, pname, params);
}

void glCreateVertexArrays(int32 n, uint32* arrays)
{
    glCreateVertexArrays_proc(n, arrays);
}

void glDisableVertexArrayAttrib(uint32 vaobj, uint32 index)
{
    glDisableVertexArrayAttrib_proc(vaobj, index);
}

void glEnableVertexArrayAttrib(uint32 vaobj, uint32 index)
{
    glEnableVertexArrayAttrib_proc(vaobj, index);
}

void glVertexArrayElementBuffer(uint32 vaobj, uint32 buffer)
{
    glVertexArrayElementBuffer_proc(vaobj, buffer);
}

void glVertexArrayVertexBuffer(uint32 vaobj, uint32 bindingindex, uint32 buffer, ptrdiff offset, int32 stride)
{
    glVertexArrayVertexBuffer_proc(vaobj, bindingindex, buffer, offset, stride);
}

void glVertexArrayVertexBuffers(uint32 vaobj,
                                uint32 first,
                                int32 count,
                                const uint32* buffers,
                                const ptrdiff* offsets,
                                const int32* strides)
{
    glVertexArrayVertexBuffers_proc(vaobj, first, count, buffers, offsets, strides);
}

void glVertexArrayAttribBinding(uint32 vaobj, uint32 attribindex, uint32 bindingindex)
{
    glVertexArrayAttribBinding_proc(vaobj, attribindex, bindingindex);
}

void glVertexArrayAttribFormat(uint32 vaobj,
                               uint32 attribindex,
                               int32 size,
                               GLenum type,
                               bool normalized,
                               uint32 relativeoffset)
{
    glVertexArrayAttribFormat_proc(vaobj, attribindex, size, type, normalized, relativeoffset);
}

void glVertexArrayAttribIFormat(uint32 vaobj, uint32 attribindex, int32 size, GLenum type, uint32 relativeoffset)
{
    glVertexArrayAttribIFormat_proc(vaobj, attribindex, size, type, relativeoffset);
}

void glVertexArrayAttribLFormat(uint32 vaobj, uint32 attribindex, int32 size, GLenum type, uint32 relativeoffset)
{
    glVertexArrayAttribLFormat_proc(vaobj, attribindex, size, type, relativeoffset);
}

void glVertexArrayBindingDivisor(uint32 vaobj, uint32 bindingindex, uint32 divisor)
{
    glVertexArrayBindingDivisor_proc(vaobj, bindingindex, divisor);
}

void glGetVertexArrayiv(uint32 vaobj, GLenum pname, int32* param)
{
    glGetVertexArrayiv_proc(vaobj, pname, param);
}

void glGetVertexArrayIndexediv(uint32 vaobj, uint32 index, GLenum pname, int32* param)
{
    glGetVertexArrayIndexediv_proc(vaobj, index, pname, param);
}

void glGetVertexArrayIndexed64iv(uint32 vaobj, uint32 index, GLenum pname, int64* param)
{
    glGetVertexArrayIndexed64iv_proc(vaobj, index, pname, param);
}

void glCreateSamplers(int32 n, uint32* samplers)
{
    glCreateSamplers_proc(n, samplers);
}

void glCreateProgramPipelines(int32 n, uint32* pipelines)
{
    glCreateProgramPipelines_proc(n, pipelines);
}

void glCreateQueries(GLenum target, int32 n, uint32* ids)
{
    glCreateQueries_proc(target, n, ids);
}

void glGetQueryBufferObjecti64v(uint32 id, uint32 buffer, GLenum pname, ptrdiff offset)
{
    glGetQueryBufferObjecti64v_proc(id, buffer, pname, offset);
}

void glGetQueryBufferObjectiv(uint32 id, uint32 buffer, GLenum pname, ptrdiff offset)
{
    glGetQueryBufferObjectiv_proc(id, buffer, pname, offset);
}

void glGetQueryBufferObjectui64v(uint32 id, uint32 buffer, GLenum pname, ptrdiff offset)
{
    glGetQueryBufferObjectui64v_proc(id, buffer, pname, offset);
}

void glGetQueryBufferObjectuiv(uint32 id, uint32 buffer, GLenum pname, ptrdiff offset)
{
    glGetQueryBufferObjectuiv_proc(id, buffer, pname, offset);
}

void glMemoryBarrierByRegion(uint32 barriers)
{
    glMemoryBarrierByRegion_proc(barriers);
}

void glGetTextureSubImage(uint32 texture,
                          int32 level,
                          int32 xoffset,
                          int32 yoffset,
                          int32 zoffset,
                          int32 width,
                          int32 height,
                          int32 depth,
                          GLenum format,
                          GLenum type,
                          int32 bufSize,
                          void* pixels)
{
    glGetTextureSubImage_proc(texture,
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

void glGetCompressedTextureSubImage(uint32 texture,
                                    int32 level,
                                    int32 xoffset,
                                    int32 yoffset,
                                    int32 zoffset,
                                    int32 width,
                                    int32 height,
                                    int32 depth,
                                    int32 bufSize,
                                    void* pixels)
{
    glGetCompressedTextureSubImage_proc(texture, level, xoffset, yoffset, zoffset, width, height, depth, bufSize, pixels);
}

GLenum glGetGraphicsResetStatus()
{
    return glGetGraphicsResetStatus_proc();
}

void glGetnCompressedTexImage(GLenum target, int32 lod, int32 bufSize, void* pixels)
{
    glGetnCompressedTexImage_proc(target, lod, bufSize, pixels);
}

void glGetnTexImage(GLenum target, int32 level, GLenum format, GLenum type, int32 bufSize, void* pixels)
{
    glGetnTexImage_proc(target, level, format, type, bufSize, pixels);
}

void glGetnUniformdv(uint32 program, int32 location, int32 bufSize, float64* params)
{
    glGetnUniformdv_proc(program, location, bufSize, params);
}

void glGetnUniformfv(uint32 program, int32 location, int32 bufSize, float32* params)
{
    glGetnUniformfv_proc(program, location, bufSize, params);
}

void glGetnUniformiv(uint32 program, int32 location, int32 bufSize, int32* params)
{
    glGetnUniformiv_proc(program, location, bufSize, params);
}

void glGetnUniformuiv(uint32 program, int32 location, int32 bufSize, uint32* params)
{
    glGetnUniformuiv_proc(program, location, bufSize, params);
}

void glReadnPixels(int32 x, int32 y, int32 width, int32 height, GLenum format, GLenum type, int32 bufSize, void* data)
{
    glReadnPixels_proc(x, y, width, height, format, type, bufSize, data);
}

void glTextureBarrier()
{
    glTextureBarrier_proc();
}

#pragma endregion
/// @}

/// @name gl_version_4_6
/// @{
#pragma region gl_version_4_6

void glSpecializeShader(uint32 shader,
                        const char* pEntryPoint,
                        uint32 numSpecializationConstants,
                        const uint32* pConstantIndex,
                        const uint32* pConstantValue)
{
    glSpecializeShader_proc(shader, pEntryPoint, numSpecializationConstants, pConstantIndex, pConstantValue);
}

void glMultiDrawArraysIndirectCount(GLenum mode,
                                    const void* indirect,
                                    ptrdiff drawcount,
                                    int32 maxdrawcount,
                                    int32 stride)
{
    glMultiDrawArraysIndirectCount_proc(mode, indirect, drawcount, maxdrawcount, stride);
}

void glMultiDrawElementsIndirectCount(GLenum mode,
                                      GLenum type,
                                      const void* indirect,
                                      ptrdiff drawcount,
                                      int32 maxdrawcount,
                                      int32 stride)
{
    glMultiDrawElementsIndirectCount_proc(mode, type, indirect, drawcount, maxdrawcount, stride);
}

void glPolygonOffsetClamp(float32 factor, float32 units, float32 clamp)
{
    glPolygonOffsetClamp_proc(factor, units, clamp);
}

#pragma endregion
/// @}

} // namespace gl

} // namespace graphic

} // namespace framework
