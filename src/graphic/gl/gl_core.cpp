/// @file
/// @brief OpneGL core functionality wrapper.
/// @author Fedorov Alexey
/// @date 21.06.2018

#include <graphic/gl/gl_core.hpp>
#include <graphic/gl/gl_utils.hpp>

namespace
{
using namespace ::framework;

using GLenum = uint32;

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

using glFinish_ptr         = void (*)(void);
glFinish_ptr glFinish_proc = nullptr;

using glFlush_ptr        = void (*)(void);
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

using glGetError_ptr           = GLenum (*)(void);
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
    using namespace ::framework::graphic::utils;

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
    using namespace ::framework::graphic::utils;

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
    using namespace ::framework::graphic::utils;

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
    using namespace ::framework::graphic::utils;

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

using glBLENDFUNCSEPARATE_ptr = void (*)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
using glMULTIDRAWARRAYS_ptr   = void (*)(GLenum mode, const int32* first, const int32* count, int32 drawcount);
using glMULTIDRAWELEMENTS_ptr =
void (*)(GLenum mode, const int32* count, GLenum type, const void* const* indices, int32 drawcount);
using glPOINTPARAMETERF_ptr  = void (*)(GLenum pname, float32 param);
using glPOINTPARAMETERFV_ptr = void (*)(GLenum pname, const float32* params);
using glPOINTPARAMETERI_ptr  = void (*)(GLenum pname, int32 param);
using glPOINTPARAMETERIV_ptr = void (*)(GLenum pname, const int32* params);
using glBLENDCOLOR_ptr       = void (*)(float32 red, float32 green, float32 blue, float32 alpha);
using glBLENDEQUATION_ptr    = void (*)(GLenum mode);

#pragma endregion

#pragma region gl_version_1_5

using glGENQUERIES_ptr           = void (*)(int32 n, uint32* ids);
using glDELETEQUERIES_ptr        = void (*)(int32 n, const uint32* ids);
using glISQUERY_ptr              = bool (*)(uint32 id);
using glBEGINQUERY_ptr           = void (*)(GLenum target, uint32 id);
using glENDQUERY_ptr             = void (*)(GLenum target);
using glGETQUERYIV_ptr           = void (*)(GLenum target, GLenum pname, int32* params);
using glGETQUERYOBJECTIV_ptr     = void (*)(uint32 id, GLenum pname, int32* params);
using glGETQUERYOBJECTUIV_ptr    = void (*)(uint32 id, GLenum pname, uint32* params);
using glBINDBUFFER_ptr           = void (*)(GLenum target, uint32 buffer);
using glDELETEBUFFERS_ptr        = void (*)(int32 n, const uint32* buffers);
using glGENBUFFERS_ptr           = void (*)(int32 n, uint32* buffers);
using glISBUFFER_ptr             = bool (*)(uint32 buffer);
using glBUFFERDATA_ptr           = void (*)(GLenum target, ptrdiff size, const void* data, GLenum usage);
using glBUFFERSUBDATA_ptr        = void (*)(GLenum target, ptrdiff offset, ptrdiff size, const void* data);
using glGETBUFFERSUBDATA_ptr     = void (*)(GLenum target, ptrdiff offset, ptrdiff size, void* data);
using glMAPBUFFER_ptr            = void* (*)(GLenum target, GLenum access);
using glUNMAPBUFFER_ptr          = bool (*)(GLenum target);
using glGETBUFFERPARAMETERIV_ptr = void (*)(GLenum target, GLenum pname, int32* params);
using glGETBUFFERPOINTERV_ptr    = void (*)(GLenum target, GLenum pname, void** params);

#pragma endregion

#pragma region gl_version_2_0

using glBLENDEQUATIONSEPARATE_ptr    = void (*)(GLenum modeRGB, GLenum modeAlpha);
using glDRAWBUFFERS_ptr              = void (*)(int32 n, const GLenum* bufs);
using glSTENCILOPSEPARATE_ptr        = void (*)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
using glSTENCILFUNCSEPARATE_ptr      = void (*)(GLenum face, GLenum func, int32 ref, uint32 mask);
using glSTENCILMASKSEPARATE_ptr      = void (*)(GLenum face, uint32 mask);
using glATTACHSHADER_ptr             = void (*)(uint32 program, uint32 shader);
using glBINDATTRIBLOCATION_ptr       = void (*)(uint32 program, uint32 index, const char* name);
using glCOMPILESHADER_ptr            = void (*)(uint32 shader);
using glCREATEPROGRAM_ptr            = uint32 (*)(void);
using glCREATESHADER_ptr             = uint32 (*)(GLenum type);
using glDELETEPROGRAM_ptr            = void (*)(uint32 program);
using glDELETESHADER_ptr             = void (*)(uint32 shader);
using glDETACHSHADER_ptr             = void (*)(uint32 program, uint32 shader);
using glDISABLEVERTEXATTRIBARRAY_ptr = void (*)(uint32 index);
using glENABLEVERTEXATTRIBARRAY_ptr  = void (*)(uint32 index);
using glGETACTIVEATTRIB_ptr =
void (*)(uint32 program, uint32 index, int32 bufSize, int32* length, int32* size, GLenum* type, char* name);
using glGETACTIVEUNIFORM_ptr =
void (*)(uint32 program, uint32 index, int32 bufSize, int32* length, int32* size, GLenum* type, char* name);
using glGETATTACHEDSHADERS_ptr      = void (*)(uint32 program, int32 maxCount, int32* count, uint32* shaders);
using glGETATTRIBLOCATION_ptr       = int32 (*)(uint32 program, const char* name);
using glGETPROGRAMIV_ptr            = void (*)(uint32 program, GLenum pname, int32* params);
using glGETPROGRAMINFOLOG_ptr       = void (*)(uint32 program, int32 bufSize, int32* length, char* infoLog);
using glGETSHADERIV_ptr             = void (*)(uint32 shader, GLenum pname, int32* params);
using glGETSHADERINFOLOG_ptr        = void (*)(uint32 shader, int32 bufSize, int32* length, char* infoLog);
using glGETSHADERSOURCE_ptr         = void (*)(uint32 shader, int32 bufSize, int32* length, char* source);
using glGETUNIFORMLOCATION_ptr      = int32 (*)(uint32 program, const char* name);
using glGETUNIFORMFV_ptr            = void (*)(uint32 program, int32 location, float32* params);
using glGETUNIFORMIV_ptr            = void (*)(uint32 program, int32 location, int32* params);
using glGETVERTEXATTRIBDV_ptr       = void (*)(uint32 index, GLenum pname, float64* params);
using glGETVERTEXATTRIBFV_ptr       = void (*)(uint32 index, GLenum pname, float32* params);
using glGETVERTEXATTRIBIV_ptr       = void (*)(uint32 index, GLenum pname, int32* params);
using glGETVERTEXATTRIBPOINTERV_ptr = void (*)(uint32 index, GLenum pname, void** pointer);
using glISPROGRAM_ptr               = bool (*)(uint32 program);
using glISSHADER_ptr                = bool (*)(uint32 shader);
using glLINKPROGRAM_ptr             = void (*)(uint32 program);
using glSHADERSOURCE_ptr      = void (*)(uint32 shader, int32 count, const char* const* string, const int32* length);
using glUSEPROGRAM_ptr        = void (*)(uint32 program);
using glUNIFORM1F_ptr         = void (*)(int32 location, float32 v0);
using glUNIFORM2F_ptr         = void (*)(int32 location, float32 v0, float32 v1);
using glUNIFORM3F_ptr         = void (*)(int32 location, float32 v0, float32 v1, float32 v2);
using glUNIFORM4F_ptr         = void (*)(int32 location, float32 v0, float32 v1, float32 v2, float32 v3);
using glUNIFORM1I_ptr         = void (*)(int32 location, int32 v0);
using glUNIFORM2I_ptr         = void (*)(int32 location, int32 v0, int32 v1);
using glUNIFORM3I_ptr         = void (*)(int32 location, int32 v0, int32 v1, int32 v2);
using glUNIFORM4I_ptr         = void (*)(int32 location, int32 v0, int32 v1, int32 v2, int32 v3);
using glUNIFORM1FV_ptr        = void (*)(int32 location, int32 count, const float32* value);
using glUNIFORM2FV_ptr        = void (*)(int32 location, int32 count, const float32* value);
using glUNIFORM3FV_ptr        = void (*)(int32 location, int32 count, const float32* value);
using glUNIFORM4FV_ptr        = void (*)(int32 location, int32 count, const float32* value);
using glUNIFORM1IV_ptr        = void (*)(int32 location, int32 count, const int32* value);
using glUNIFORM2IV_ptr        = void (*)(int32 location, int32 count, const int32* value);
using glUNIFORM3IV_ptr        = void (*)(int32 location, int32 count, const int32* value);
using glUNIFORM4IV_ptr        = void (*)(int32 location, int32 count, const int32* value);
using glUNIFORMMATRIX2FV_ptr  = void (*)(int32 location, int32 count, bool transpose, const float32* value);
using glUNIFORMMATRIX3FV_ptr  = void (*)(int32 location, int32 count, bool transpose, const float32* value);
using glUNIFORMMATRIX4FV_ptr  = void (*)(int32 location, int32 count, bool transpose, const float32* value);
using glVALIDATEPROGRAM_ptr   = void (*)(uint32 program);
using glVERTEXATTRIB1D_ptr    = void (*)(uint32 index, float64 x);
using glVERTEXATTRIB1DV_ptr   = void (*)(uint32 index, const float64* v);
using glVERTEXATTRIB1F_ptr    = void (*)(uint32 index, float32 x);
using glVERTEXATTRIB1FV_ptr   = void (*)(uint32 index, const float32* v);
using glVERTEXATTRIB1S_ptr    = void (*)(uint32 index, int16 x);
using glVERTEXATTRIB1SV_ptr   = void (*)(uint32 index, const int16* v);
using glVERTEXATTRIB2D_ptr    = void (*)(uint32 index, float64 x, float64 y);
using glVERTEXATTRIB2DV_ptr   = void (*)(uint32 index, const float64* v);
using glVERTEXATTRIB2F_ptr    = void (*)(uint32 index, float32 x, float32 y);
using glVERTEXATTRIB2FV_ptr   = void (*)(uint32 index, const float32* v);
using glVERTEXATTRIB2S_ptr    = void (*)(uint32 index, int16 x, int16 y);
using glVERTEXATTRIB2SV_ptr   = void (*)(uint32 index, const int16* v);
using glVERTEXATTRIB3D_ptr    = void (*)(uint32 index, float64 x, float64 y, float64 z);
using glVERTEXATTRIB3DV_ptr   = void (*)(uint32 index, const float64* v);
using glVERTEXATTRIB3F_ptr    = void (*)(uint32 index, float32 x, float32 y, float32 z);
using glVERTEXATTRIB3FV_ptr   = void (*)(uint32 index, const float32* v);
using glVERTEXATTRIB3S_ptr    = void (*)(uint32 index, int16 x, int16 y, int16 z);
using glVERTEXATTRIB3SV_ptr   = void (*)(uint32 index, const int16* v);
using glVERTEXATTRIB4NBV_ptr  = void (*)(uint32 index, const int8* v);
using glVERTEXATTRIB4NIV_ptr  = void (*)(uint32 index, const int32* v);
using glVERTEXATTRIB4NSV_ptr  = void (*)(uint32 index, const int16* v);
using glVERTEXATTRIB4NUB_ptr  = void (*)(uint32 index, uint8 x, uint8 y, uint8 z, uint8 w);
using glVERTEXATTRIB4NUBV_ptr = void (*)(uint32 index, const uint8* v);
using glVERTEXATTRIB4NUIV_ptr = void (*)(uint32 index, const uint32* v);
using glVERTEXATTRIB4NUSV_ptr = void (*)(uint32 index, const uint16* v);
using glVERTEXATTRIB4BV_ptr   = void (*)(uint32 index, const int8* v);
using glVERTEXATTRIB4D_ptr    = void (*)(uint32 index, float64 x, float64 y, float64 z, float64 w);
using glVERTEXATTRIB4DV_ptr   = void (*)(uint32 index, const float64* v);
using glVERTEXATTRIB4F_ptr    = void (*)(uint32 index, float32 x, float32 y, float32 z, float32 w);
using glVERTEXATTRIB4FV_ptr   = void (*)(uint32 index, const float32* v);
using glVERTEXATTRIB4IV_ptr   = void (*)(uint32 index, const int32* v);
using glVERTEXATTRIB4S_ptr    = void (*)(uint32 index, int16 x, int16 y, int16 z, int16 w);
using glVERTEXATTRIB4SV_ptr   = void (*)(uint32 index, const int16* v);
using glVERTEXATTRIB4UBV_ptr  = void (*)(uint32 index, const uint8* v);
using glVERTEXATTRIB4UIV_ptr  = void (*)(uint32 index, const uint32* v);
using glVERTEXATTRIB4USV_ptr  = void (*)(uint32 index, const uint16* v);
using glVERTEXATTRIBPOINTER_ptr =
void (*)(uint32 index, int32 size, GLenum type, bool normalized, int32 stride, const void* pointer);

#pragma endregion

#pragma region gl_version_2_1

using glUNIFORMMATRIX2X3FV_ptr = void (*)(int32 location, int32 count, bool transpose, const float32* value);
using glUNIFORMMATRIX3X2FV_ptr = void (*)(int32 location, int32 count, bool transpose, const float32* value);
using glUNIFORMMATRIX2X4FV_ptr = void (*)(int32 location, int32 count, bool transpose, const float32* value);
using glUNIFORMMATRIX4X2FV_ptr = void (*)(int32 location, int32 count, bool transpose, const float32* value);
using glUNIFORMMATRIX3X4FV_ptr = void (*)(int32 location, int32 count, bool transpose, const float32* value);
using glUNIFORMMATRIX4X3FV_ptr = void (*)(int32 location, int32 count, bool transpose, const float32* value);

#pragma endregion

#pragma region gl_version_3_0

using GLCOLORMASKI_ptr             = void (*)(uint32 index, bool r, bool g, bool b, bool a);
using GLGETBOOLEANI_V_ptr          = void (*)(GLenum target, uint32 index, bool* data);
using GLGETINTEGERI_V_ptr          = void (*)(GLenum target, uint32 index, int32* data);
using GLENABLEI_ptr                = void (*)(GLenum target, uint32 index);
using GLDISABLEI_ptr               = void (*)(GLenum target, uint32 index);
using GLISENABLEDI_ptr             = bool (*)(GLenum target, uint32 index);
using GLBEGINTRANSFORMFEEDBACK_ptr = void (*)(GLenum primitiveMode);
using GLENDTRANSFORMFEEDBACK_ptr   = void (*)(void);
using GLBINDBUFFERRANGE_ptr        = void (*)(GLenum target, uint32 index, uint32 buffer, ptrdiff offset, ptrdiff size);
using GLBINDBUFFERBASE_ptr         = void (*)(GLenum target, uint32 index, uint32 buffer);
using GLTRANSFORMFEEDBACKVARYINGS_ptr = void (*)(uint32 program,
                                                 int32 count,
                                                 const char* const* varyings,
                                                 GLenum bufferMode);
using GLGETTRANSFORMFEEDBACKVARYING_ptr =
void (*)(uint32 program, uint32 index, int32 bufSize, int32* length, int32* size, GLenum* type, char* name);
using GLCLAMPCOLOR_ptr             = void (*)(GLenum target, GLenum clamp);
using GLBEGINCONDITIONALRENDER_ptr = void (*)(uint32 id, GLenum mode);
using GLENDCONDITIONALRENDER_ptr   = void (*)(void);
using GLVERTEXATTRIBIPOINTER_ptr   = void (*)(uint32 index, int32 size, GLenum type, int32 stride, const void* pointer);
using GLGETVERTEXATTRIBIIV_ptr     = void (*)(uint32 index, GLenum pname, int32* params);
using GLGETVERTEXATTRIBIUIV_ptr    = void (*)(uint32 index, GLenum pname, uint32* params);
using GLVERTEXATTRIBI1I_ptr        = void (*)(uint32 index, int32 x);
using GLVERTEXATTRIBI2I_ptr        = void (*)(uint32 index, int32 x, int32 y);
using GLVERTEXATTRIBI3I_ptr        = void (*)(uint32 index, int32 x, int32 y, int32 z);
using GLVERTEXATTRIBI4I_ptr        = void (*)(uint32 index, int32 x, int32 y, int32 z, int32 w);
using GLVERTEXATTRIBI1UI_ptr       = void (*)(uint32 index, uint32 x);
using GLVERTEXATTRIBI2UI_ptr       = void (*)(uint32 index, uint32 x, uint32 y);
using GLVERTEXATTRIBI3UI_ptr       = void (*)(uint32 index, uint32 x, uint32 y, uint32 z);
using GLVERTEXATTRIBI4UI_ptr       = void (*)(uint32 index, uint32 x, uint32 y, uint32 z, uint32 w);
using GLVERTEXATTRIBI1IV_ptr       = void (*)(uint32 index, const int32* v);
using GLVERTEXATTRIBI2IV_ptr       = void (*)(uint32 index, const int32* v);
using GLVERTEXATTRIBI3IV_ptr       = void (*)(uint32 index, const int32* v);
using GLVERTEXATTRIBI4IV_ptr       = void (*)(uint32 index, const int32* v);
using GLVERTEXATTRIBI1UIV_ptr      = void (*)(uint32 index, const uint32* v);
using GLVERTEXATTRIBI2UIV_ptr      = void (*)(uint32 index, const uint32* v);
using GLVERTEXATTRIBI3UIV_ptr      = void (*)(uint32 index, const uint32* v);
using GLVERTEXATTRIBI4UIV_ptr      = void (*)(uint32 index, const uint32* v);
using GLVERTEXATTRIBI4BV_ptr       = void (*)(uint32 index, const int8* v);
using GLVERTEXATTRIBI4SV_ptr       = void (*)(uint32 index, const int16* v);
using GLVERTEXATTRIBI4UBV_ptr      = void (*)(uint32 index, const uint8* v);
using GLVERTEXATTRIBI4USV_ptr      = void (*)(uint32 index, const uint16* v);
using GLGETUNIFORMUIV_ptr          = void (*)(uint32 program, int32 location, uint32* params);
using GLBINDFRAGDATALOCATION_ptr   = void (*)(uint32 program, uint32 color, const char* name);
using GLGETFRAGDATALOCATION_ptr    = int32 (*)(uint32 program, const char* name);
using GLUNIFORM1UI_ptr             = void (*)(int32 location, uint32 v0);
using GLUNIFORM2UI_ptr             = void (*)(int32 location, uint32 v0, uint32 v1);
using GLUNIFORM3UI_ptr             = void (*)(int32 location, uint32 v0, uint32 v1, uint32 v2);
using GLUNIFORM4UI_ptr             = void (*)(int32 location, uint32 v0, uint32 v1, uint32 v2, uint32 v3);
using GLUNIFORM1UIV_ptr            = void (*)(int32 location, int32 count, const uint32* value);
using GLUNIFORM2UIV_ptr            = void (*)(int32 location, int32 count, const uint32* value);
using GLUNIFORM3UIV_ptr            = void (*)(int32 location, int32 count, const uint32* value);
using GLUNIFORM4UIV_ptr            = void (*)(int32 location, int32 count, const uint32* value);
using GLTEXPARAMETERIIV_ptr        = void (*)(GLenum target, GLenum pname, const int32* params);
using GLTEXPARAMETERIUIV_ptr       = void (*)(GLenum target, GLenum pname, const uint32* params);
using GLGETTEXPARAMETERIIV_ptr     = void (*)(GLenum target, GLenum pname, int32* params);
using GLGETTEXPARAMETERIUIV_ptr    = void (*)(GLenum target, GLenum pname, uint32* params);
using GLCLEARBUFFERIV_ptr          = void (*)(GLenum buffer, int32 drawbuffer, const int32* value);
using GLCLEARBUFFERUIV_ptr         = void (*)(GLenum buffer, int32 drawbuffer, const uint32* value);
using GLCLEARBUFFERFV_ptr          = void (*)(GLenum buffer, int32 drawbuffer, const float32* value);
using GLCLEARBUFFERFI_ptr          = void (*)(GLenum buffer, int32 drawbuffer, float32 depth, int32 stencil);
using GLGETSTRINGI_ptr             = const uint8* (*)(GLenum name, uint32 index);
using GLISRENDERBUFFER_ptr         = bool (*)(uint32 renderbuffer);
using GLBINDRENDERBUFFER_ptr       = void (*)(GLenum target, uint32 renderbuffer);
using GLDELETERENDERBUFFERS_ptr    = void (*)(int32 n, const uint32* renderbuffers);
using GLGENRENDERBUFFERS_ptr       = void (*)(int32 n, uint32* renderbuffers);
using GLRENDERBUFFERSTORAGE_ptr    = void (*)(GLenum target, GLenum internalformat, int32 width, int32 height);
using GLGETRENDERBUFFERPARAMETERIV_ptr = void (*)(GLenum target, GLenum pname, int32* params);
using GLISFRAMEBUFFER_ptr              = bool (*)(uint32 framebuffer);
using GLBINDFRAMEBUFFER_ptr            = void (*)(GLenum target, uint32 framebuffer);
using GLDELETEFRAMEBUFFERS_ptr         = void (*)(int32 n, const uint32* framebuffers);
using GLGENFRAMEBUFFERS_ptr            = void (*)(int32 n, uint32* framebuffers);
using GLCHECKFRAMEBUFFERSTATUS_ptr     = GLenum (*)(GLenum target);
using GLFRAMEBUFFERTEXTURE1D_ptr =
void (*)(GLenum target, GLenum attachment, GLenum textarget, uint32 texture, int32 level);
using GLFRAMEBUFFERTEXTURE2D_ptr =
void (*)(GLenum target, GLenum attachment, GLenum textarget, uint32 texture, int32 level);
using GLFRAMEBUFFERTEXTURE3D_ptr =
void (*)(GLenum target, GLenum attachment, GLenum textarget, uint32 texture, int32 level, int32 zoffset);
using GLFRAMEBUFFERRENDERBUFFER_ptr             = void (*)(GLenum target,
                                               GLenum attachment,
                                               GLenum renderbuffertarget,
                                               uint32 renderbuffer);
using GLGETFRAMEBUFFERATTACHMENTPARAMETERIV_ptr = void (*)(GLenum target,
                                                           GLenum attachment,
                                                           GLenum pname,
                                                           int32* params);
using GLGENERATEMIPMAP_ptr                      = void (*)(GLenum target);
using GLBLITFRAMEBUFFER_ptr                     = void (*)(int32 srcX0,
                                       int32 srcY0,
                                       int32 srcX1,
                                       int32 srcY1,
                                       int32 dstX0,
                                       int32 dstY0,
                                       int32 dstX1,
                                       int32 dstY1,
                                       uint32 mask,
                                       GLenum filter);
using GLRENDERBUFFERSTORAGEMULTISAMPLE_ptr =
void (*)(GLenum target, int32 samples, GLenum internalformat, int32 width, int32 height);
using GLFRAMEBUFFERTEXTURELAYER_ptr =
void (*)(GLenum target, GLenum attachment, uint32 texture, int32 level, int32 layer);
using GLMAPBUFFERRANGE_ptr         = void* (*)(GLenum target, ptrdiff offset, ptrdiff length, uint32 access);
using GLFLUSHMAPPEDBUFFERRANGE_ptr = void (*)(GLenum target, ptrdiff offset, ptrdiff length);
using GLBINDVERTEXARRAY_ptr        = void (*)(uint32 array);
using GLDELETEVERTEXARRAYS_ptr     = void (*)(int32 n, const uint32* arrays);
using GLGENVERTEXARRAYS_ptr        = void (*)(int32 n, uint32* arrays);
using GLISVERTEXARRAY_ptr          = bool (*)(uint32 array);

#pragma endregion

#pragma region gl_version_3_1

using GLDRAWARRAYSINSTANCED_ptr = void (*)(GLenum mode, int32 first, int32 count, int32 instancecount);
using GLDRAWELEMENTSINSTANCED_ptr =
void (*)(GLenum mode, int32 count, GLenum type, const void* indices, int32 instancecount);
using GLTEXBUFFER_ptr             = void (*)(GLenum target, GLenum internalformat, uint32 buffer);
using GLPRIMITIVERESTARTINDEX_ptr = void (*)(uint32 index);
using GLCOPYBUFFERSUBDATA_ptr =
void (*)(GLenum readTarget, GLenum writeTarget, ptrdiff readOffset, ptrdiff writeOffset, ptrdiff size);
using GLGETUNIFORMINDICES_ptr = void (*)(uint32 program,
                                         int32 uniformCount,
                                         const char* const* uniformNames,
                                         uint32* uniformIndices);
using GLGETACTIVEUNIFORMSIV_ptr =
void (*)(uint32 program, int32 uniformCount, const uint32* uniformIndices, GLenum pname, int32* params);
using GLGETACTIVEUNIFORMNAME_ptr =
void (*)(uint32 program, uint32 uniformIndex, int32 bufSize, int32* length, char* uniformName);
using GLGETUNIFORMBLOCKINDEX_ptr    = uint32 (*)(uint32 program, const char* uniformBlockName);
using GLGETACTIVEUNIFORMBLOCKIV_ptr = void (*)(uint32 program, uint32 uniformBlockIndex, GLenum pname, int32* params);
using GLGETACTIVEUNIFORMBLOCKNAME_ptr =
void (*)(uint32 program, uint32 uniformBlockIndex, int32 bufSize, int32* length, char* uniformBlockName);
using GLUNIFORMBLOCKBINDING_ptr = void (*)(uint32 program, uint32 uniformBlockIndex, uint32 uniformBlockBinding);

#pragma endregion

#pragma region gl_versoin_3_2

using GLsync = graphic::gl::GLsync;

using GLDRAWELEMENTSBASEVERTEX_ptr =
void (*)(GLenum mode, int32 count, GLenum type, const void* indices, int32 basevertex);
using GLDRAWRANGEELEMENTSBASEVERTEX_ptr =
void (*)(GLenum mode, uint32 start, uint32 end, int32 count, GLenum type, const void* indices, int32 basevertex);
using GLDRAWELEMENTSINSTANCEDBASEVERTEX_ptr =
void (*)(GLenum mode, int32 count, GLenum type, const void* indices, int32 instancecount, int32 basevertex);
using GLMULTIDRAWELEMENTSBASEVERTEX_ptr = void (*)(GLenum mode,
                                                   const int32* count,
                                                   GLenum type,
                                                   const void* const* indices,
                                                   int32 drawcount,
                                                   const int32* basevertex);
using GLPROVOKINGVERTEX_ptr             = void (*)(GLenum mode);
using GLFENCESYNC_ptr                   = GLsync (*)(GLenum condition, uint32 flags);
using GLISSYNC_ptr                      = bool (*)(GLsync sync);
using GLDELETESYNC_ptr                  = void (*)(GLsync sync);
using GLCLIENTWAITSYNC_ptr              = GLenum (*)(GLsync sync, uint32 flags, uint64 timeout);
using GLWAITSYNC_ptr                    = void (*)(GLsync sync, uint32 flags, uint64 timeout);
using GLGETINTEGER64V_ptr               = void (*)(GLenum pname, int64* data);
using GLGETSYNCIV_ptr              = void (*)(GLsync sync, GLenum pname, int32 bufSize, int32* length, int32* values);
using GLGETINTEGER64I_V_ptr        = void (*)(GLenum target, uint32 index, int64* data);
using GLGETBUFFERPARAMETERI64V_ptr = void (*)(GLenum target, GLenum pname, int64* params);
using GLFRAMEBUFFERTEXTURE_ptr     = void (*)(GLenum target, GLenum attachment, uint32 texture, int32 level);
using GLTEXIMAGE2DMULTISAMPLE_ptr =
void (*)(GLenum target, int32 samples, GLenum internalformat, int32 width, int32 height, bool fixedsamplelocations);
using GLTEXIMAGE3DMULTISAMPLE_ptr = void (*)(GLenum target,
                                             int32 samples,
                                             GLenum internalformat,
                                             int32 width,
                                             int32 height,
                                             int32 depth,
                                             bool fixedsamplelocations);
using GLGETMULTISAMPLEFV_ptr      = void (*)(GLenum pname, uint32 index, float32* val);
using GLSAMPLEMASKI_ptr           = void (*)(uint32 maskNumber, uint32 mask);

#pragma endregion

#pragma region gl_version_3_3

using GLBINDFRAGDATALOCATIONINDEXED_ptr = void (*)(uint32 program, uint32 colorNumber, uint32 index, const char* name);
using GLGETFRAGDATAINDEX_ptr            = int32 (*)(uint32 program, const char* name);
using GLGENSAMPLERS_ptr                 = void (*)(int32 count, uint32* samplers);
using GLDELETESAMPLERS_ptr              = void (*)(int32 count, const uint32* samplers);
using GLISSAMPLER_ptr                   = bool (*)(uint32 sampler);
using GLBINDSAMPLER_ptr                 = void (*)(uint32 unit, uint32 sampler);
using GLSAMPLERPARAMETERI_ptr           = void (*)(uint32 sampler, GLenum pname, int32 param);
using GLSAMPLERPARAMETERIV_ptr          = void (*)(uint32 sampler, GLenum pname, const int32* param);
using GLSAMPLERPARAMETERF_ptr           = void (*)(uint32 sampler, GLenum pname, float32 param);
using GLSAMPLERPARAMETERFV_ptr          = void (*)(uint32 sampler, GLenum pname, const float32* param);
using GLSAMPLERPARAMETERIIV_ptr         = void (*)(uint32 sampler, GLenum pname, const int32* param);
using GLSAMPLERPARAMETERIUIV_ptr        = void (*)(uint32 sampler, GLenum pname, const uint32* param);
using GLGETSAMPLERPARAMETERIV_ptr       = void (*)(uint32 sampler, GLenum pname, int32* params);
using GLGETSAMPLERPARAMETERIIV_ptr      = void (*)(uint32 sampler, GLenum pname, int32* params);
using GLGETSAMPLERPARAMETERFV_ptr       = void (*)(uint32 sampler, GLenum pname, float32* params);
using GLGETSAMPLERPARAMETERIUIV_ptr     = void (*)(uint32 sampler, GLenum pname, uint32* params);
using GLQUERYCOUNTER_ptr                = void (*)(uint32 id, GLenum target);
using GLGETQUERYOBJECTI64V_ptr          = void (*)(uint32 id, GLenum pname, int64* params);
using GLGETQUERYOBJECTUI64V_ptr         = void (*)(uint32 id, GLenum pname, uint64* params);
using GLVERTEXATTRIBDIVISOR_ptr         = void (*)(uint32 index, uint32 divisor);
using GLVERTEXATTRIBP1UI_ptr            = void (*)(uint32 index, GLenum type, bool normalized, uint32 value);
using GLVERTEXATTRIBP1UIV_ptr           = void (*)(uint32 index, GLenum type, bool normalized, const uint32* value);
using GLVERTEXATTRIBP2UI_ptr            = void (*)(uint32 index, GLenum type, bool normalized, uint32 value);
using GLVERTEXATTRIBP2UIV_ptr           = void (*)(uint32 index, GLenum type, bool normalized, const uint32* value);
using GLVERTEXATTRIBP3UI_ptr            = void (*)(uint32 index, GLenum type, bool normalized, uint32 value);
using GLVERTEXATTRIBP3UIV_ptr           = void (*)(uint32 index, GLenum type, bool normalized, const uint32* value);
using GLVERTEXATTRIBP4UI_ptr            = void (*)(uint32 index, GLenum type, bool normalized, uint32 value);
using GLVERTEXATTRIBP4UIV_ptr           = void (*)(uint32 index, GLenum type, bool normalized, const uint32* value);

#pragma endregion

#pragma region gl_version_4_0

using GLMINSAMPLESHADING_ptr       = void (*)(float32 value);
using GLBLENDEQUATIONI_ptr         = void (*)(uint32 buf, GLenum mode);
using GLBLENDEQUATIONSEPARATEI_ptr = void (*)(uint32 buf, GLenum modeRGB, GLenum modeAlpha);
using GLBLENDFUNCI_ptr             = void (*)(uint32 buf, GLenum src, GLenum dst);
using GLBLENDFUNCSEPARATEI_ptr   = void (*)(uint32 buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
using GLDRAWARRAYSINDIRECT_ptr   = void (*)(GLenum mode, const void* indirect);
using GLDRAWELEMENTSINDIRECT_ptr = void (*)(GLenum mode, GLenum type, const void* indirect);
using GLUNIFORM1D_ptr            = void (*)(int32 location, float64 x);
using GLUNIFORM2D_ptr            = void (*)(int32 location, float64 x, float64 y);
using GLUNIFORM3D_ptr            = void (*)(int32 location, float64 x, float64 y, float64 z);
using GLUNIFORM4D_ptr            = void (*)(int32 location, float64 x, float64 y, float64 z, float64 w);
using GLUNIFORM1DV_ptr           = void (*)(int32 location, int32 count, const float64* value);
using GLUNIFORM2DV_ptr           = void (*)(int32 location, int32 count, const float64* value);
using GLUNIFORM3DV_ptr           = void (*)(int32 location, int32 count, const float64* value);
using GLUNIFORM4DV_ptr           = void (*)(int32 location, int32 count, const float64* value);
using GLUNIFORMMATRIX2DV_ptr     = void (*)(int32 location, int32 count, bool transpose, const float64* value);
using GLUNIFORMMATRIX3DV_ptr     = void (*)(int32 location, int32 count, bool transpose, const float64* value);
using GLUNIFORMMATRIX4DV_ptr     = void (*)(int32 location, int32 count, bool transpose, const float64* value);
using GLUNIFORMMATRIX2X3DV_ptr   = void (*)(int32 location, int32 count, bool transpose, const float64* value);
using GLUNIFORMMATRIX2X4DV_ptr   = void (*)(int32 location, int32 count, bool transpose, const float64* value);
using GLUNIFORMMATRIX3X2DV_ptr   = void (*)(int32 location, int32 count, bool transpose, const float64* value);
using GLUNIFORMMATRIX3X4DV_ptr   = void (*)(int32 location, int32 count, bool transpose, const float64* value);
using GLUNIFORMMATRIX4X2DV_ptr   = void (*)(int32 location, int32 count, bool transpose, const float64* value);
using GLUNIFORMMATRIX4X3DV_ptr   = void (*)(int32 location, int32 count, bool transpose, const float64* value);
using GLGETUNIFORMDV_ptr         = void (*)(uint32 program, int32 location, float64* params);
using GLGETSUBROUTINEUNIFORMLOCATION_ptr = int32 (*)(uint32 program, GLenum shadertype, const char* name);
using GLGETSUBROUTINEINDEX_ptr           = uint32 (*)(uint32 program, GLenum shadertype, const char* name);
using GLGETACTIVESUBROUTINEUNIFORMIV_ptr =
void (*)(uint32 program, GLenum shadertype, uint32 index, GLenum pname, int32* values);
using GLGETACTIVESUBROUTINEUNIFORMNAME_ptr =
void (*)(uint32 program, GLenum shadertype, uint32 index, int32 bufsize, int32* length, char* name);
using GLGETACTIVESUBROUTINENAME_ptr =
void (*)(uint32 program, GLenum shadertype, uint32 index, int32 bufsize, int32* length, char* name);
using GLUNIFORMSUBROUTINESUIV_ptr       = void (*)(GLenum shadertype, int32 count, const uint32* indices);
using GLGETUNIFORMSUBROUTINEUIV_ptr     = void (*)(GLenum shadertype, int32 location, uint32* params);
using GLGETPROGRAMSTAGEIV_ptr           = void (*)(uint32 program, GLenum shadertype, GLenum pname, int32* values);
using GLPATCHPARAMETERI_ptr             = void (*)(GLenum pname, int32 value);
using GLPATCHPARAMETERFV_ptr            = void (*)(GLenum pname, const float32* values);
using GLBINDTRANSFORMFEEDBACK_ptr       = void (*)(GLenum target, uint32 id);
using GLDELETETRANSFORMFEEDBACKS_ptr    = void (*)(int32 n, const uint32* ids);
using GLGENTRANSFORMFEEDBACKS_ptr       = void (*)(int32 n, uint32* ids);
using GLISTRANSFORMFEEDBACK_ptr         = bool (*)(uint32 id);
using GLPAUSETRANSFORMFEEDBACK_ptr      = void (*)(void);
using GLRESUMETRANSFORMFEEDBACK_ptr     = void (*)(void);
using GLDRAWTRANSFORMFEEDBACK_ptr       = void (*)(GLenum mode, uint32 id);
using GLDRAWTRANSFORMFEEDBACKSTREAM_ptr = void (*)(GLenum mode, uint32 id, uint32 stream);
using GLBEGINQUERYINDEXED_ptr           = void (*)(GLenum target, uint32 index, uint32 id);
using GLENDQUERYINDEXED_ptr             = void (*)(GLenum target, uint32 index);
using GLGETQUERYINDEXEDIV_ptr           = void (*)(GLenum target, uint32 index, GLenum pname, int32* params);

#pragma endregion

#pragma region gl_version_4_1

using GLRELEASESHADERCOMPILER_ptr = void (*)(void);
using GLSHADERBINARY_ptr =
void (*)(int32 count, const uint32* shaders, GLenum binaryformat, const void* binary, int32 length);
using GLGETSHADERPRECISIONFORMAT_ptr = void (*)(GLenum shadertype, GLenum precisiontype, int32* range, int32* precision);
using GLDEPTHRANGEF_ptr              = void (*)(float32 n, float32 f);
using GLCLEARDEPTHF_ptr              = void (*)(float32 d);
using GLGETPROGRAMBINARY_ptr =
void (*)(uint32 program, int32 bufSize, int32* length, GLenum* binaryFormat, void* binary);
using GLPROGRAMBINARY_ptr          = void (*)(uint32 program, GLenum binaryFormat, const void* binary, int32 length);
using GLPROGRAMPARAMETERI_ptr      = void (*)(uint32 program, GLenum pname, int32 value);
using GLUSEPROGRAMSTAGES_ptr       = void (*)(uint32 pipeline, uint32 stages, uint32 program);
using GLACTIVESHADERPROGRAM_ptr    = void (*)(uint32 pipeline, uint32 program);
using GLCREATESHADERPROGRAMV_ptr   = uint32 (*)(GLenum type, int32 count, const char* const* strings);
using GLBINDPROGRAMPIPELINE_ptr    = void (*)(uint32 pipeline);
using GLDELETEPROGRAMPIPELINES_ptr = void (*)(int32 n, const uint32* pipelines);
using GLGENPROGRAMPIPELINES_ptr    = void (*)(int32 n, uint32* pipelines);
using GLISPROGRAMPIPELINE_ptr      = bool (*)(uint32 pipeline);
using GLGETPROGRAMPIPELINEIV_ptr   = void (*)(uint32 pipeline, GLenum pname, int32* params);
using GLPROGRAMUNIFORM1I_ptr       = void (*)(uint32 program, int32 location, int32 v0);
using GLPROGRAMUNIFORM1IV_ptr      = void (*)(uint32 program, int32 location, int32 count, const int32* value);
using GLPROGRAMUNIFORM1F_ptr       = void (*)(uint32 program, int32 location, float32 v0);
using GLPROGRAMUNIFORM1FV_ptr      = void (*)(uint32 program, int32 location, int32 count, const float32* value);
using GLPROGRAMUNIFORM1D_ptr       = void (*)(uint32 program, int32 location, float64 v0);
using GLPROGRAMUNIFORM1DV_ptr      = void (*)(uint32 program, int32 location, int32 count, const float64* value);
using GLPROGRAMUNIFORM1UI_ptr      = void (*)(uint32 program, int32 location, uint32 v0);
using GLPROGRAMUNIFORM1UIV_ptr     = void (*)(uint32 program, int32 location, int32 count, const uint32* value);
using GLPROGRAMUNIFORM2I_ptr       = void (*)(uint32 program, int32 location, int32 v0, int32 v1);
using GLPROGRAMUNIFORM2IV_ptr      = void (*)(uint32 program, int32 location, int32 count, const int32* value);
using GLPROGRAMUNIFORM2F_ptr       = void (*)(uint32 program, int32 location, float32 v0, float32 v1);
using GLPROGRAMUNIFORM2FV_ptr      = void (*)(uint32 program, int32 location, int32 count, const float32* value);
using GLPROGRAMUNIFORM2D_ptr       = void (*)(uint32 program, int32 location, float64 v0, float64 v1);
using GLPROGRAMUNIFORM2DV_ptr      = void (*)(uint32 program, int32 location, int32 count, const float64* value);
using GLPROGRAMUNIFORM2UI_ptr      = void (*)(uint32 program, int32 location, uint32 v0, uint32 v1);
using GLPROGRAMUNIFORM2UIV_ptr     = void (*)(uint32 program, int32 location, int32 count, const uint32* value);
using GLPROGRAMUNIFORM3I_ptr       = void (*)(uint32 program, int32 location, int32 v0, int32 v1, int32 v2);
using GLPROGRAMUNIFORM3IV_ptr      = void (*)(uint32 program, int32 location, int32 count, const int32* value);
using GLPROGRAMUNIFORM3F_ptr       = void (*)(uint32 program, int32 location, float32 v0, float32 v1, float32 v2);
using GLPROGRAMUNIFORM3FV_ptr      = void (*)(uint32 program, int32 location, int32 count, const float32* value);
using GLPROGRAMUNIFORM3D_ptr       = void (*)(uint32 program, int32 location, float64 v0, float64 v1, float64 v2);
using GLPROGRAMUNIFORM3DV_ptr      = void (*)(uint32 program, int32 location, int32 count, const float64* value);
using GLPROGRAMUNIFORM3UI_ptr      = void (*)(uint32 program, int32 location, uint32 v0, uint32 v1, uint32 v2);
using GLPROGRAMUNIFORM3UIV_ptr     = void (*)(uint32 program, int32 location, int32 count, const uint32* value);
using GLPROGRAMUNIFORM4I_ptr       = void (*)(uint32 program, int32 location, int32 v0, int32 v1, int32 v2, int32 v3);
using GLPROGRAMUNIFORM4IV_ptr      = void (*)(uint32 program, int32 location, int32 count, const int32* value);
using GLPROGRAMUNIFORM4F_ptr = void (*)(uint32 program, int32 location, float32 v0, float32 v1, float32 v2, float32 v3);
using GLPROGRAMUNIFORM4FV_ptr = void (*)(uint32 program, int32 location, int32 count, const float32* value);
using GLPROGRAMUNIFORM4D_ptr = void (*)(uint32 program, int32 location, float64 v0, float64 v1, float64 v2, float64 v3);
using GLPROGRAMUNIFORM4DV_ptr  = void (*)(uint32 program, int32 location, int32 count, const float64* value);
using GLPROGRAMUNIFORM4UI_ptr  = void (*)(uint32 program, int32 location, uint32 v0, uint32 v1, uint32 v2, uint32 v3);
using GLPROGRAMUNIFORM4UIV_ptr = void (*)(uint32 program, int32 location, int32 count, const uint32* value);
using GLPROGRAMUNIFORMMATRIX2FV_ptr =
void (*)(uint32 program, int32 location, int32 count, bool transpose, const float32* value);
using GLPROGRAMUNIFORMMATRIX3FV_ptr =
void (*)(uint32 program, int32 location, int32 count, bool transpose, const float32* value);
using GLPROGRAMUNIFORMMATRIX4FV_ptr =
void (*)(uint32 program, int32 location, int32 count, bool transpose, const float32* value);
using GLPROGRAMUNIFORMMATRIX2DV_ptr =
void (*)(uint32 program, int32 location, int32 count, bool transpose, const float64* value);
using GLPROGRAMUNIFORMMATRIX3DV_ptr =
void (*)(uint32 program, int32 location, int32 count, bool transpose, const float64* value);
using GLPROGRAMUNIFORMMATRIX4DV_ptr =
void (*)(uint32 program, int32 location, int32 count, bool transpose, const float64* value);
using GLPROGRAMUNIFORMMATRIX2X3FV_ptr =
void (*)(uint32 program, int32 location, int32 count, bool transpose, const float32* value);
using GLPROGRAMUNIFORMMATRIX3X2FV_ptr =
void (*)(uint32 program, int32 location, int32 count, bool transpose, const float32* value);
using GLPROGRAMUNIFORMMATRIX2X4FV_ptr =
void (*)(uint32 program, int32 location, int32 count, bool transpose, const float32* value);
using GLPROGRAMUNIFORMMATRIX4X2FV_ptr =
void (*)(uint32 program, int32 location, int32 count, bool transpose, const float32* value);
using GLPROGRAMUNIFORMMATRIX3X4FV_ptr =
void (*)(uint32 program, int32 location, int32 count, bool transpose, const float32* value);
using GLPROGRAMUNIFORMMATRIX4X3FV_ptr =
void (*)(uint32 program, int32 location, int32 count, bool transpose, const float32* value);
using GLPROGRAMUNIFORMMATRIX2X3DV_ptr =
void (*)(uint32 program, int32 location, int32 count, bool transpose, const float64* value);
using GLPROGRAMUNIFORMMATRIX3X2DV_ptr =
void (*)(uint32 program, int32 location, int32 count, bool transpose, const float64* value);
using GLPROGRAMUNIFORMMATRIX2X4DV_ptr =
void (*)(uint32 program, int32 location, int32 count, bool transpose, const float64* value);
using GLPROGRAMUNIFORMMATRIX4X2DV_ptr =
void (*)(uint32 program, int32 location, int32 count, bool transpose, const float64* value);
using GLPROGRAMUNIFORMMATRIX3X4DV_ptr =
void (*)(uint32 program, int32 location, int32 count, bool transpose, const float64* value);
using GLPROGRAMUNIFORMMATRIX4X3DV_ptr =
void (*)(uint32 program, int32 location, int32 count, bool transpose, const float64* value);
using GLVALIDATEPROGRAMPIPELINE_ptr   = void (*)(uint32 pipeline);
using GLGETPROGRAMPIPELINEINFOLOG_ptr = void (*)(uint32 pipeline, int32 bufSize, int32* length, char* infoLog);
using GLVERTEXATTRIBL1D_ptr           = void (*)(uint32 index, float64 x);
using GLVERTEXATTRIBL2D_ptr           = void (*)(uint32 index, float64 x, float64 y);
using GLVERTEXATTRIBL3D_ptr           = void (*)(uint32 index, float64 x, float64 y, float64 z);
using GLVERTEXATTRIBL4D_ptr           = void (*)(uint32 index, float64 x, float64 y, float64 z, float64 w);
using GLVERTEXATTRIBL1DV_ptr          = void (*)(uint32 index, const float64* v);
using GLVERTEXATTRIBL2DV_ptr          = void (*)(uint32 index, const float64* v);
using GLVERTEXATTRIBL3DV_ptr          = void (*)(uint32 index, const float64* v);
using GLVERTEXATTRIBL4DV_ptr          = void (*)(uint32 index, const float64* v);
using GLVERTEXATTRIBLPOINTER_ptr = void (*)(uint32 index, int32 size, GLenum type, int32 stride, const void* pointer);
using GLGETVERTEXATTRIBLDV_ptr   = void (*)(uint32 index, GLenum pname, float64* params);
using GLVIEWPORTARRAYV_ptr       = void (*)(uint32 first, int32 count, const float32* v);
using GLVIEWPORTINDEXEDF_ptr     = void (*)(uint32 index, float32 x, float32 y, float32 w, float32 h);
using GLVIEWPORTINDEXEDFV_ptr    = void (*)(uint32 index, const float32* v);
using GLSCISSORARRAYV_ptr        = void (*)(uint32 first, int32 count, const int32* v);
using GLSCISSORINDEXED_ptr       = void (*)(uint32 index, int32 left, int32 bottom, int32 width, int32 height);
using GLSCISSORINDEXEDV_ptr      = void (*)(uint32 index, const int32* v);
using GLDEPTHRANGEARRAYV_ptr     = void (*)(uint32 first, int32 count, const float64* v);
using GLDEPTHRANGEINDEXED_ptr    = void (*)(uint32 index, float64 n, float64 f);
using GLGETFLOATI_V_ptr          = void (*)(GLenum target, uint32 index, float32* data);
using GLGETDOUBLEI_V_ptr         = void (*)(GLenum target, uint32 index, float64* data);

#pragma endregion

#pragma region gl_version_4_2

using GLDRAWARRAYSINSTANCEDBASEINSTANCE_ptr =
void (*)(GLenum mode, int32 first, int32 count, int32 instancecount, uint32 baseinstance);
using GLDRAWELEMENTSINSTANCEDBASEINSTANCE_ptr =
void (*)(GLenum mode, int32 count, GLenum type, const void* indices, int32 instancecount, uint32 baseinstance);
using GLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCE_ptr = void (*)(GLenum mode,
                                                                   int32 count,
                                                                   GLenum type,
                                                                   const void* indices,
                                                                   int32 instancecount,
                                                                   int32 basevertex,
                                                                   uint32 baseinstance);
using GLGETINTERNALFORMATIV_ptr =
void (*)(GLenum target, GLenum internalformat, GLenum pname, int32 bufSize, int32* params);
using GLGETACTIVEATOMICCOUNTERBUFFERIV_ptr = void (*)(uint32 program, uint32 bufferIndex, GLenum pname, int32* params);
using GLBINDIMAGETEXTURE_ptr =
void (*)(uint32 unit, uint32 texture, int32 level, bool layered, int32 layer, GLenum access, GLenum format);
using GLMEMORYBARRIER_ptr = void (*)(uint32 barriers);
using GLTEXSTORAGE1D_ptr  = void (*)(GLenum target, int32 levels, GLenum internalformat, int32 width);
using GLTEXSTORAGE2D_ptr  = void (*)(GLenum target, int32 levels, GLenum internalformat, int32 width, int32 height);
using GLTEXSTORAGE3D_ptr =
void (*)(GLenum target, int32 levels, GLenum internalformat, int32 width, int32 height, int32 depth);
using GLDRAWTRANSFORMFEEDBACKINSTANCED_ptr       = void (*)(GLenum mode, uint32 id, int32 instancecount);
using GLDRAWTRANSFORMFEEDBACKSTREAMINSTANCED_ptr = void (*)(GLenum mode, uint32 id, uint32 stream, int32 instancecount);

#pragma endregion

#pragma region gl_version_4_3

using debug_proc_callback = graphic::gl::debug_proc_callback;

using GLCLEARBUFFERDATA_ptr =
void (*)(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void* data);
using GLCLEARBUFFERSUBDATA_ptr        = void (*)(GLenum target,
                                          GLenum internalformat,
                                          ptrdiff offset,
                                          ptrdiff size,
                                          GLenum format,
                                          GLenum type,
                                          const void* data);
using GLDISPATCHCOMPUTE_ptr           = void (*)(uint32 num_groups_x, uint32 num_groups_y, uint32 num_groups_z);
using GLDISPATCHCOMPUTEINDIRECT_ptr   = void (*)(ptrdiff indirect);
using GLCOPYIMAGESUBDATA_ptr          = void (*)(uint32 srcName,
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
using GLFRAMEBUFFERPARAMETERI_ptr     = void (*)(GLenum target, GLenum pname, int32 param);
using GLGETFRAMEBUFFERPARAMETERIV_ptr = void (*)(GLenum target, GLenum pname, int32* params);
using GLGETINTERNALFORMATI64V_ptr =
void (*)(GLenum target, GLenum internalformat, GLenum pname, int32 bufSize, int64* params);
using GLINVALIDATETEXSUBIMAGE_ptr   = void (*)(uint32 texture,
                                             int32 level,
                                             int32 xoffset,
                                             int32 yoffset,
                                             int32 zoffset,
                                             int32 width,
                                             int32 height,
                                             int32 depth);
using GLINVALIDATETEXIMAGE_ptr      = void (*)(uint32 texture, int32 level);
using GLINVALIDATEBUFFERSUBDATA_ptr = void (*)(uint32 buffer, ptrdiff offset, ptrdiff length);
using GLINVALIDATEBUFFERDATA_ptr    = void (*)(uint32 buffer);
using GLINVALIDATEFRAMEBUFFER_ptr   = void (*)(GLenum target, int32 numAttachments, const GLenum* attachments);
using GLINVALIDATESUBFRAMEBUFFER_ptr =
void (*)(GLenum target, int32 numAttachments, const GLenum* attachments, int32 x, int32 y, int32 width, int32 height);
using GLMULTIDRAWARRAYSINDIRECT_ptr = void (*)(GLenum mode, const void* indirect, int32 drawcount, int32 stride);
using GLMULTIDRAWELEMENTSINDIRECT_ptr =
void (*)(GLenum mode, GLenum type, const void* indirect, int32 drawcount, int32 stride);
using GLGETPROGRAMINTERFACEIV_ptr   = void (*)(uint32 program, GLenum programInterface, GLenum pname, int32* params);
using GLGETPROGRAMRESOURCEINDEX_ptr = uint32 (*)(uint32 program, GLenum programInterface, const char* name);
using GLGETPROGRAMRESOURCENAME_ptr =
void (*)(uint32 program, GLenum programInterface, uint32 index, int32 bufSize, int32* length, char* name);
using GLGETPROGRAMRESOURCEIV_ptr            = void (*)(uint32 program,
                                            GLenum programInterface,
                                            uint32 index,
                                            int32 propCount,
                                            const GLenum* props,
                                            int32 bufSize,
                                            int32* length,
                                            int32* params);
using GLGETPROGRAMRESOURCELOCATION_ptr      = int32 (*)(uint32 program, GLenum programInterface, const char* name);
using GLGETPROGRAMRESOURCELOCATIONINDEX_ptr = int32 (*)(uint32 program, GLenum programInterface, const char* name);
using GLSHADERSTORAGEBLOCKBINDING_ptr = void (*)(uint32 program, uint32 storageBlockIndex, uint32 storageBlockBinding);
using GLTEXBUFFERRANGE_ptr = void (*)(GLenum target, GLenum internalformat, uint32 buffer, ptrdiff offset, ptrdiff size);
using GLTEXSTORAGE2DMULTISAMPLE_ptr =
void (*)(GLenum target, int32 samples, GLenum internalformat, int32 width, int32 height, bool fixedsamplelocations);
using GLTEXSTORAGE3DMULTISAMPLE_ptr = void (*)(GLenum target,
                                               int32 samples,
                                               GLenum internalformat,
                                               int32 width,
                                               int32 height,
                                               int32 depth,
                                               bool fixedsamplelocations);
using GLTEXTUREVIEW_ptr             = void (*)(uint32 texture,
                                   GLenum target,
                                   uint32 origtexture,
                                   GLenum internalformat,
                                   uint32 minlevel,
                                   uint32 numlevels,
                                   uint32 minlayer,
                                   uint32 numlayers);
using GLBINDVERTEXBUFFER_ptr        = void (*)(uint32 bindingindex, uint32 buffer, ptrdiff offset, int32 stride);
using GLVERTEXATTRIBFORMAT_ptr =
void (*)(uint32 attribindex, int32 size, GLenum type, bool normalized, uint32 relativeoffset);
using GLVERTEXATTRIBIFORMAT_ptr  = void (*)(uint32 attribindex, int32 size, GLenum type, uint32 relativeoffset);
using GLVERTEXATTRIBLFORMAT_ptr  = void (*)(uint32 attribindex, int32 size, GLenum type, uint32 relativeoffset);
using GLVERTEXATTRIBBINDING_ptr  = void (*)(uint32 attribindex, uint32 bindingindex);
using GLVERTEXBINDINGDIVISOR_ptr = void (*)(uint32 bindingindex, uint32 divisor);
using GLDEBUGMESSAGECONTROL_ptr =
void (*)(GLenum source, GLenum type, GLenum severity, int32 count, const uint32* ids, bool enabled);
using GLDEBUGMESSAGEINSERT_ptr =
void (*)(GLenum source, GLenum type, uint32 id, GLenum severity, int32 length, const char* buf);
using GLDEBUGMESSAGECALLBACK_ptr = void (*)(debug_proc_callback callback, const void* userParam);
using GLGETDEBUGMESSAGELOG_ptr   = uint32 (*)(uint32 count,
                                            int32 bufSize,
                                            GLenum* sources,
                                            GLenum* types,
                                            uint32* ids,
                                            GLenum* severities,
                                            int32* lengths,
                                            char* messageLog);
using GLPUSHDEBUGGROUP_ptr       = void (*)(GLenum source, uint32 id, int32 length, const char* message);
using GLPOPDEBUGGROUP_ptr        = void (*)(void);
using GLOBJECTLABEL_ptr          = void (*)(GLenum identifier, uint32 name, int32 length, const char* label);
using GLGETOBJECTLABEL_ptr       = void (*)(GLenum identifier, uint32 name, int32 bufSize, int32* length, char* label);
using GLOBJECTPTRLABEL_ptr       = void (*)(const void* ptr, int32 length, const char* label);
using GLGETOBJECTPTRLABEL_ptr    = void (*)(const void* ptr, int32 bufSize, int32* length, char* label);

#pragma endregion

#pragma region gl_versino_4_4

using GLBUFFERSTORAGE_ptr    = void (*)(GLenum target, ptrdiff size, const void* data, uint32 flags);
using GLCLEARTEXIMAGE_ptr    = void (*)(uint32 texture, int32 level, GLenum format, GLenum type, const void* data);
using GLCLEARTEXSUBIMAGE_ptr = void (*)(uint32 texture,
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
using GLBINDBUFFERSBASE_ptr  = void (*)(GLenum target, uint32 first, int32 count, const uint32* buffers);
using GLBINDBUFFERSRANGE_ptr =
void (*)(GLenum target, uint32 first, int32 count, const uint32* buffers, const ptrdiff* offsets, const ptrdiff* sizes);
using GLBINDTEXTURES_ptr      = void (*)(uint32 first, int32 count, const uint32* textures);
using GLBINDSAMPLERS_ptr      = void (*)(uint32 first, int32 count, const uint32* samplers);
using GLBINDIMAGETEXTURES_ptr = void (*)(uint32 first, int32 count, const uint32* textures);
using GLBINDVERTEXBUFFERS_ptr =
void (*)(uint32 first, int32 count, const uint32* buffers, const ptrdiff* offsets, const int32* strides);

#pragma endregion

#pragma region gl_version_4_5

using GLCLIPCONTROL_ptr                 = void (*)(GLenum origin, GLenum depth);
using GLCREATETRANSFORMFEEDBACKS_ptr    = void (*)(int32 n, uint32* ids);
using GLTRANSFORMFEEDBACKBUFFERBASE_ptr = void (*)(uint32 xfb, uint32 index, uint32 buffer);
using GLTRANSFORMFEEDBACKBUFFERRANGE_ptr =
void (*)(uint32 xfb, uint32 index, uint32 buffer, ptrdiff offset, ptrdiff size);
using GLGETTRANSFORMFEEDBACKIV_ptr    = void (*)(uint32 xfb, GLenum pname, int32* param);
using GLGETTRANSFORMFEEDBACKI_V_ptr   = void (*)(uint32 xfb, GLenum pname, uint32 index, int32* param);
using GLGETTRANSFORMFEEDBACKI64_V_ptr = void (*)(uint32 xfb, GLenum pname, uint32 index, int64* param);
using GLCREATEBUFFERS_ptr             = void (*)(int32 n, uint32* buffers);
using GLNAMEDBUFFERSTORAGE_ptr        = void (*)(uint32 buffer, ptrdiff size, const void* data, uint32 flags);
using GLNAMEDBUFFERDATA_ptr           = void (*)(uint32 buffer, ptrdiff size, const void* data, GLenum usage);
using GLNAMEDBUFFERSUBDATA_ptr        = void (*)(uint32 buffer, ptrdiff offset, ptrdiff size, const void* data);
using GLCOPYNAMEDBUFFERSUBDATA_ptr =
void (*)(uint32 readBuffer, uint32 writeBuffer, ptrdiff readOffset, ptrdiff writeOffset, ptrdiff size);
using GLCLEARNAMEDBUFFERDATA_ptr =
void (*)(uint32 buffer, GLenum internalformat, GLenum format, GLenum type, const void* data);
using GLCLEARNAMEDBUFFERSUBDATA_ptr      = void (*)(uint32 buffer,
                                               GLenum internalformat,
                                               ptrdiff offset,
                                               ptrdiff size,
                                               GLenum format,
                                               GLenum type,
                                               const void* data);
using GLMAPNAMEDBUFFER_ptr               = void* (*)(uint32 buffer, GLenum access);
using GLMAPNAMEDBUFFERRANGE_ptr          = void* (*)(uint32 buffer, ptrdiff offset, ptrdiff length, uint32 access);
using GLUNMAPNAMEDBUFFER_ptr             = bool (*)(uint32 buffer);
using GLFLUSHMAPPEDNAMEDBUFFERRANGE_ptr  = void (*)(uint32 buffer, ptrdiff offset, ptrdiff length);
using GLGETNAMEDBUFFERPARAMETERIV_ptr    = void (*)(uint32 buffer, GLenum pname, int32* params);
using GLGETNAMEDBUFFERPARAMETERI64V_ptr  = void (*)(uint32 buffer, GLenum pname, int64* params);
using GLGETNAMEDBUFFERPOINTERV_ptr       = void (*)(uint32 buffer, GLenum pname, void** params);
using GLGETNAMEDBUFFERSUBDATA_ptr        = void (*)(uint32 buffer, ptrdiff offset, ptrdiff size, void* data);
using GLCREATEFRAMEBUFFERS_ptr           = void (*)(int32 n, uint32* framebuffers);
using GLNAMEDFRAMEBUFFERRENDERBUFFER_ptr = void (*)(uint32 framebuffer,
                                                    GLenum attachment,
                                                    GLenum renderbuffertarget,
                                                    uint32 renderbuffer);
using GLNAMEDFRAMEBUFFERPARAMETERI_ptr   = void (*)(uint32 framebuffer, GLenum pname, int32 param);
using GLNAMEDFRAMEBUFFERTEXTURE_ptr      = void (*)(uint32 framebuffer, GLenum attachment, uint32 texture, int32 level);
using GLNAMEDFRAMEBUFFERTEXTURELAYER_ptr =
void (*)(uint32 framebuffer, GLenum attachment, uint32 texture, int32 level, int32 layer);
using GLNAMEDFRAMEBUFFERDRAWBUFFER_ptr        = void (*)(uint32 framebuffer, GLenum buf);
using GLNAMEDFRAMEBUFFERDRAWBUFFERS_ptr       = void (*)(uint32 framebuffer, int32 n, const GLenum* bufs);
using GLNAMEDFRAMEBUFFERREADBUFFER_ptr        = void (*)(uint32 framebuffer, GLenum src);
using GLINVALIDATENAMEDFRAMEBUFFERDATA_ptr    = void (*)(uint32 framebuffer,
                                                      int32 numAttachments,
                                                      const GLenum* attachments);
using GLINVALIDATENAMEDFRAMEBUFFERSUBDATA_ptr = void (*)(uint32 framebuffer,
                                                         int32 numAttachments,
                                                         const GLenum* attachments,
                                                         int32 x,
                                                         int32 y,
                                                         int32 width,
                                                         int32 height);
using GLCLEARNAMEDFRAMEBUFFERIV_ptr = void (*)(uint32 framebuffer, GLenum buffer, int32 drawbuffer, const int32* value);
using GLCLEARNAMEDFRAMEBUFFERUIV_ptr = void (*)(uint32 framebuffer,
                                                GLenum buffer,
                                                int32 drawbuffer,
                                                const uint32* value);
using GLCLEARNAMEDFRAMEBUFFERFV_ptr  = void (*)(uint32 framebuffer,
                                               GLenum buffer,
                                               int32 drawbuffer,
                                               const float32* value);
using GLCLEARNAMEDFRAMEBUFFERFI_ptr =
void (*)(uint32 framebuffer, GLenum buffer, int32 drawbuffer, float32 depth, int32 stencil);
using GLBLITNAMEDFRAMEBUFFER_ptr                     = void (*)(uint32 readFramebuffer,
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
using GLCHECKNAMEDFRAMEBUFFERSTATUS_ptr              = GLenum (*)(uint32 framebuffer, GLenum target);
using GLGETNAMEDFRAMEBUFFERPARAMETERIV_ptr           = void (*)(uint32 framebuffer, GLenum pname, int32* param);
using GLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIV_ptr = void (*)(uint32 framebuffer,
                                                                GLenum attachment,
                                                                GLenum pname,
                                                                int32* params);
using GLCREATERENDERBUFFERS_ptr                      = void (*)(int32 n, uint32* renderbuffers);
using GLNAMEDRENDERBUFFERSTORAGE_ptr = void (*)(uint32 renderbuffer, GLenum internalformat, int32 width, int32 height);
using GLNAMEDRENDERBUFFERSTORAGEMULTISAMPLE_ptr =
void (*)(uint32 renderbuffer, int32 samples, GLenum internalformat, int32 width, int32 height);
using GLGETNAMEDRENDERBUFFERPARAMETERIV_ptr = void (*)(uint32 renderbuffer, GLenum pname, int32* params);
using GLCREATETEXTURES_ptr                  = void (*)(GLenum target, int32 n, uint32* textures);
using GLTEXTUREBUFFER_ptr                   = void (*)(uint32 texture, GLenum internalformat, uint32 buffer);
using GLTEXTUREBUFFERRANGE_ptr =
void (*)(uint32 texture, GLenum internalformat, uint32 buffer, ptrdiff offset, ptrdiff size);
using GLTEXTURESTORAGE1D_ptr = void (*)(uint32 texture, int32 levels, GLenum internalformat, int32 width);
using GLTEXTURESTORAGE2D_ptr = void (*)(uint32 texture, int32 levels, GLenum internalformat, int32 width, int32 height);
using GLTEXTURESTORAGE3D_ptr =
void (*)(uint32 texture, int32 levels, GLenum internalformat, int32 width, int32 height, int32 depth);
using GLTEXTURESTORAGE2DMULTISAMPLE_ptr =
void (*)(uint32 texture, int32 samples, GLenum internalformat, int32 width, int32 height, bool fixedsamplelocations);
using GLTEXTURESTORAGE3DMULTISAMPLE_ptr = void (*)(uint32 texture,
                                                   int32 samples,
                                                   GLenum internalformat,
                                                   int32 width,
                                                   int32 height,
                                                   int32 depth,
                                                   bool fixedsamplelocations);
using GLTEXTURESUBIMAGE1D_ptr =
void (*)(uint32 texture, int32 level, int32 xoffset, int32 width, GLenum format, GLenum type, const void* pixels);
using GLTEXTURESUBIMAGE2D_ptr = void (*)(uint32 texture,
                                         int32 level,
                                         int32 xoffset,
                                         int32 yoffset,
                                         int32 width,
                                         int32 height,
                                         GLenum format,
                                         GLenum type,
                                         const void* pixels);
using GLTEXTURESUBIMAGE3D_ptr = void (*)(uint32 texture,
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
using GLCOMPRESSEDTEXTURESUBIMAGE1D_ptr =
void (*)(uint32 texture, int32 level, int32 xoffset, int32 width, GLenum format, int32 imageSize, const void* data);
using GLCOMPRESSEDTEXTURESUBIMAGE2D_ptr = void (*)(uint32 texture,
                                                   int32 level,
                                                   int32 xoffset,
                                                   int32 yoffset,
                                                   int32 width,
                                                   int32 height,
                                                   GLenum format,
                                                   int32 imageSize,
                                                   const void* data);
using GLCOMPRESSEDTEXTURESUBIMAGE3D_ptr = void (*)(uint32 texture,
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
using GLCOPYTEXTURESUBIMAGE1D_ptr = void (*)(uint32 texture, int32 level, int32 xoffset, int32 x, int32 y, int32 width);
using GLCOPYTEXTURESUBIMAGE2D_ptr =
void (*)(uint32 texture, int32 level, int32 xoffset, int32 yoffset, int32 x, int32 y, int32 width, int32 height);
using GLCOPYTEXTURESUBIMAGE3D_ptr = void (*)(uint32 texture,
                                             int32 level,
                                             int32 xoffset,
                                             int32 yoffset,
                                             int32 zoffset,
                                             int32 x,
                                             int32 y,
                                             int32 width,
                                             int32 height);
using GLTEXTUREPARAMETERF_ptr     = void (*)(uint32 texture, GLenum pname, float32 param);
using GLTEXTUREPARAMETERFV_ptr    = void (*)(uint32 texture, GLenum pname, const float32* param);
using GLTEXTUREPARAMETERI_ptr     = void (*)(uint32 texture, GLenum pname, int32 param);
using GLTEXTUREPARAMETERIIV_ptr   = void (*)(uint32 texture, GLenum pname, const int32* params);
using GLTEXTUREPARAMETERIUIV_ptr  = void (*)(uint32 texture, GLenum pname, const uint32* params);
using GLTEXTUREPARAMETERIV_ptr    = void (*)(uint32 texture, GLenum pname, const int32* param);
using GLGENERATETEXTUREMIPMAP_ptr = void (*)(uint32 texture);
using GLBINDTEXTUREUNIT_ptr       = void (*)(uint32 unit, uint32 texture);
using GLGETTEXTUREIMAGE_ptr =
void (*)(uint32 texture, int32 level, GLenum format, GLenum type, int32 bufSize, void* pixels);
using GLGETCOMPRESSEDTEXTUREIMAGE_ptr  = void (*)(uint32 texture, int32 level, int32 bufSize, void* pixels);
using GLGETTEXTURELEVELPARAMETERFV_ptr = void (*)(uint32 texture, int32 level, GLenum pname, float32* params);
using GLGETTEXTURELEVELPARAMETERIV_ptr = void (*)(uint32 texture, int32 level, GLenum pname, int32* params);
using GLGETTEXTUREPARAMETERFV_ptr      = void (*)(uint32 texture, GLenum pname, float32* params);
using GLGETTEXTUREPARAMETERIIV_ptr     = void (*)(uint32 texture, GLenum pname, int32* params);
using GLGETTEXTUREPARAMETERIUIV_ptr    = void (*)(uint32 texture, GLenum pname, uint32* params);
using GLGETTEXTUREPARAMETERIV_ptr      = void (*)(uint32 texture, GLenum pname, int32* params);
using GLCREATEVERTEXARRAYS_ptr         = void (*)(int32 n, uint32* arrays);
using GLDISABLEVERTEXARRAYATTRIB_ptr   = void (*)(uint32 vaobj, uint32 index);
using GLENABLEVERTEXARRAYATTRIB_ptr    = void (*)(uint32 vaobj, uint32 index);
using GLVERTEXARRAYELEMENTBUFFER_ptr   = void (*)(uint32 vaobj, uint32 buffer);
using GLVERTEXARRAYVERTEXBUFFER_ptr =
void (*)(uint32 vaobj, uint32 bindingindex, uint32 buffer, ptrdiff offset, int32 stride);
using GLVERTEXARRAYVERTEXBUFFERS_ptr =
void (*)(uint32 vaobj, uint32 first, int32 count, const uint32* buffers, const ptrdiff* offsets, const int32* strides);
using GLVERTEXARRAYATTRIBBINDING_ptr = void (*)(uint32 vaobj, uint32 attribindex, uint32 bindingindex);
using GLVERTEXARRAYATTRIBFORMAT_ptr =
void (*)(uint32 vaobj, uint32 attribindex, int32 size, GLenum type, bool normalized, uint32 relativeoffset);
using GLVERTEXARRAYATTRIBIFORMAT_ptr =
void (*)(uint32 vaobj, uint32 attribindex, int32 size, GLenum type, uint32 relativeoffset);
using GLVERTEXARRAYATTRIBLFORMAT_ptr =
void (*)(uint32 vaobj, uint32 attribindex, int32 size, GLenum type, uint32 relativeoffset);
using GLVERTEXARRAYBINDINGDIVISOR_ptr    = void (*)(uint32 vaobj, uint32 bindingindex, uint32 divisor);
using GLGETVERTEXARRAYIV_ptr             = void (*)(uint32 vaobj, GLenum pname, int32* param);
using GLGETVERTEXARRAYINDEXEDIV_ptr      = void (*)(uint32 vaobj, uint32 index, GLenum pname, int32* param);
using GLGETVERTEXARRAYINDEXED64IV_ptr    = void (*)(uint32 vaobj, uint32 index, GLenum pname, int64* param);
using GLCREATESAMPLERS_ptr               = void (*)(int32 n, uint32* samplers);
using GLCREATEPROGRAMPIPELINES_ptr       = void (*)(int32 n, uint32* pipelines);
using GLCREATEQUERIES_ptr                = void (*)(GLenum target, int32 n, uint32* ids);
using GLGETQUERYBUFFEROBJECTI64V_ptr     = void (*)(uint32 id, uint32 buffer, GLenum pname, ptrdiff offset);
using GLGETQUERYBUFFEROBJECTIV_ptr       = void (*)(uint32 id, uint32 buffer, GLenum pname, ptrdiff offset);
using GLGETQUERYBUFFEROBJECTUI64V_ptr    = void (*)(uint32 id, uint32 buffer, GLenum pname, ptrdiff offset);
using GLGETQUERYBUFFEROBJECTUIV_ptr      = void (*)(uint32 id, uint32 buffer, GLenum pname, ptrdiff offset);
using GLMEMORYBARRIERBYREGION_ptr        = void (*)(uint32 barriers);
using GLGETTEXTURESUBIMAGE_ptr           = void (*)(uint32 texture,
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
using GLGETCOMPRESSEDTEXTURESUBIMAGE_ptr = void (*)(uint32 texture,
                                                    int32 level,
                                                    int32 xoffset,
                                                    int32 yoffset,
                                                    int32 zoffset,
                                                    int32 width,
                                                    int32 height,
                                                    int32 depth,
                                                    int32 bufSize,
                                                    void* pixels);
using GLGETGRAPHICSRESETSTATUS_ptr       = GLenum (*)(void);
using GLGETNCOMPRESSEDTEXIMAGE_ptr       = void (*)(GLenum target, int32 lod, int32 bufSize, void* pixels);
using GLGETNTEXIMAGE_ptr = void (*)(GLenum target, int32 level, GLenum format, GLenum type, int32 bufSize, void* pixels);
using GLGETNUNIFORMDV_ptr  = void (*)(uint32 program, int32 location, int32 bufSize, float64* params);
using GLGETNUNIFORMFV_ptr  = void (*)(uint32 program, int32 location, int32 bufSize, float32* params);
using GLGETNUNIFORMIV_ptr  = void (*)(uint32 program, int32 location, int32 bufSize, int32* params);
using GLGETNUNIFORMUIV_ptr = void (*)(uint32 program, int32 location, int32 bufSize, uint32* params);
using GLREADNPIXELS_ptr =
void (*)(int32 x, int32 y, int32 width, int32 height, GLenum format, GLenum type, int32 bufSize, void* data);
using GLTEXTUREBARRIER_ptr = void (*)(void);

#pragma endregion

#pragma region gl_version_4_6

using GLSPECIALIZESHADER_ptr = void (*)(uint32 shader,
                                        const char* pEntryPoint,
                                        uint32 numSpecializationConstants,
                                        const uint32* pConstantIndex,
                                        const uint32* pConstantValue);
using GLMULTIDRAWARRAYSINDIRECTCOUNT_ptr =
void (*)(GLenum mode, const void* indirect, ptrdiff drawcount, int32 maxdrawcount, int32 stride);
using GLMULTIDRAWELEMENTSINDIRECTCOUNT_ptr =
void (*)(GLenum mode, GLenum type, const void* indirect, ptrdiff drawcount, int32 maxdrawcount, int32 stride);
using GLPOLYGONOFFSETCLAMP_ptr = void (*)(float32 factor, float32 units, float32 clamp);

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
    return init_gl_version_1_0() && init_gl_version_1_1() && init_gl_version_1_2() && init_gl_version_1_3();
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

void glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
void glMultiDrawArrays(GLenum mode, const int32* first, const int32* count, int32 drawcount);
void glMultiDrawElements(GLenum mode, const int32* count, GLenum type, const void* const* indices, int32 drawcount);
void glPointParameterf(GLenum pname, float32 param);
void glPointParameterfv(GLenum pname, const float32* params);
void glPointParameteri(GLenum pname, int32 param);
void glPointParameteriv(GLenum pname, const int32* params);
void glBlendColor(float32 red, float32 green, float32 blue, float32 alpha);
void glBlendEquation(GLenum mode);

#pragma endregion
/// @}

/// @name gl_version_1_5
/// @{
#pragma region gl_version_1_5

void glGenQueries(int32 n, uint32* ids);
void glDeleteQueries(int32 n, const uint32* ids);
bool glIsQuery(uint32 id);
void glBeginQuery(GLenum target, uint32 id);
void glEndQuery(GLenum target);
void glGetQueryiv(GLenum target, GLenum pname, int32* params);
void glGetQueryObjectiv(uint32 id, GLenum pname, int32* params);
void glGetQueryObjectuiv(uint32 id, GLenum pname, uint32* params);
void glBindBuffer(GLenum target, uint32 buffer);
void glDeleteBuffers(int32 n, const uint32* buffers);
void glGenBuffers(int32 n, uint32* buffers);
bool glIsBuffer(uint32 buffer);
void glBufferData(GLenum target, ptrdiff size, const void* data, GLenum usage);
void glBufferSubData(GLenum target, ptrdiff offset, ptrdiff size, const void* data);
void glGetBufferSubData(GLenum target, ptrdiff offset, ptrdiff size, void* data);
void* glMapBuffer(GLenum target, GLenum access);
bool glUnmapBuffer(GLenum target);
void glGetBufferParameteriv(GLenum target, GLenum pname, int32* params);
void glGetBufferPointerv(GLenum target, GLenum pname, void** params);

#pragma endregion
/// @}

/// @name gl_version_2_0
/// @{
#pragma region gl_version_2_0

void glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha);
void glDrawBuffers(int32 n, const GLenum* bufs);
void glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
void glStencilFuncSeparate(GLenum face, GLenum func, int32 ref, uint32 mask);
void glStencilMaskSeparate(GLenum face, uint32 mask);
void glAttachShader(uint32 program, uint32 shader);
void glBindAttribLocation(uint32 program, uint32 index, const char* name);
void glCompileShader(uint32 shader);
uint32 glCreateProgram();
uint32 glCreateShader(GLenum type);
void glDeleteProgram(uint32 program);
void glDeleteShader(uint32 shader);
void glDetachShader(uint32 program, uint32 shader);
void glDisableVertexAttribArray(uint32 index);
void glEnableVertexAttribArray(uint32 index);
void glGetActiveAttrib(uint32 program,
                       uint32 index,
                       int32 bufSize,
                       int32* length,
                       int32* size,
                       GLenum* type,
                       char* name);
void glGetActiveUniform(uint32 program,
                        uint32 index,
                        int32 bufSize,
                        int32* length,
                        int32* size,
                        GLenum* type,
                        char* name);
void glGetAttachedShaders(uint32 program, int32 maxCount, int32* count, uint32* shaders);
int32 glGetAttribLocation(uint32 program, const char* name);
void glGetProgramiv(uint32 program, GLenum pname, int32* params);
void glGetProgramInfoLog(uint32 program, int32 bufSize, int32* length, char* infoLog);
void glGetShaderiv(uint32 shader, GLenum pname, int32* params);
void glGetShaderInfoLog(uint32 shader, int32 bufSize, int32* length, char* infoLog);
void glGetShaderSource(uint32 shader, int32 bufSize, int32* length, char* source);
int32 glGetUniformLocation(uint32 program, const char* name);
void glGetUniformfv(uint32 program, int32 location, float32* params);
void glGetUniformiv(uint32 program, int32 location, int32* params);
void glGetVertexAttribdv(uint32 index, GLenum pname, float64* params);
void glGetVertexAttribfv(uint32 index, GLenum pname, float32* params);
void glGetVertexAttribiv(uint32 index, GLenum pname, int32* params);
void glGetVertexAttribPointerv(uint32 index, GLenum pname, void** pointer);
bool glIsProgram(uint32 program);
bool glIsShader(uint32 shader);
void glLinkProgram(uint32 program);
void glShaderSource(uint32 shader, int32 count, const char* const* string, const int32* length);
void glUseProgram(uint32 program);
void glUniform1f(int32 location, float32 v0);
void glUniform2f(int32 location, float32 v0, float32 v1);
void glUniform3f(int32 location, float32 v0, float32 v1, float32 v2);
void glUniform4f(int32 location, float32 v0, float32 v1, float32 v2, float32 v3);
void glUniform1i(int32 location, int32 v0);
void glUniform2i(int32 location, int32 v0, int32 v1);
void glUniform3i(int32 location, int32 v0, int32 v1, int32 v2);
void glUniform4i(int32 location, int32 v0, int32 v1, int32 v2, int32 v3);
void glUniform1fv(int32 location, int32 count, const float32* value);
void glUniform2fv(int32 location, int32 count, const float32* value);
void glUniform3fv(int32 location, int32 count, const float32* value);
void glUniform4fv(int32 location, int32 count, const float32* value);
void glUniform1iv(int32 location, int32 count, const int32* value);
void glUniform2iv(int32 location, int32 count, const int32* value);
void glUniform3iv(int32 location, int32 count, const int32* value);
void glUniform4iv(int32 location, int32 count, const int32* value);
void glUniformMatrix2fv(int32 location, int32 count, bool transpose, const float32* value);
void glUniformMatrix3fv(int32 location, int32 count, bool transpose, const float32* value);
void glUniformMatrix4fv(int32 location, int32 count, bool transpose, const float32* value);
void glValidateProgram(uint32 program);
void glVertexAttrib1d(uint32 index, float64 x);
void glVertexAttrib1dv(uint32 index, const float64* v);
void glVertexAttrib1f(uint32 index, float32 x);
void glVertexAttrib1fv(uint32 index, const float32* v);
void glVertexAttrib1s(uint32 index, int16 x);
void glVertexAttrib1sv(uint32 index, const int16* v);
void glVertexAttrib2d(uint32 index, float64 x, float64 y);
void glVertexAttrib2dv(uint32 index, const float64* v);
void glVertexAttrib2f(uint32 index, float32 x, float32 y);
void glVertexAttrib2fv(uint32 index, const float32* v);
void glVertexAttrib2s(uint32 index, int16 x, int16 y);
void glVertexAttrib2sv(uint32 index, const int16* v);
void glVertexAttrib3d(uint32 index, float64 x, float64 y, float64 z);
void glVertexAttrib3dv(uint32 index, const float64* v);
void glVertexAttrib3f(uint32 index, float32 x, float32 y, float32 z);
void glVertexAttrib3fv(uint32 index, const float32* v);
void glVertexAttrib3s(uint32 index, int16 x, int16 y, int16 z);
void glVertexAttrib3sv(uint32 index, const int16* v);
void glVertexAttrib4Nbv(uint32 index, const int8* v);
void glVertexAttrib4Niv(uint32 index, const int32* v);
void glVertexAttrib4Nsv(uint32 index, const int16* v);
void glVertexAttrib4Nub(uint32 index, uint8 x, uint8 y, uint8 z, uint8 w);
void glVertexAttrib4Nubv(uint32 index, const uint8* v);
void glVertexAttrib4Nuiv(uint32 index, const uint32* v);
void glVertexAttrib4Nusv(uint32 index, const uint16* v);
void glVertexAttrib4bv(uint32 index, const int8* v);
void glVertexAttrib4d(uint32 index, float64 x, float64 y, float64 z, float64 w);
void glVertexAttrib4dv(uint32 index, const float64* v);
void glVertexAttrib4f(uint32 index, float32 x, float32 y, float32 z, float32 w);
void glVertexAttrib4fv(uint32 index, const float32* v);
void glVertexAttrib4iv(uint32 index, const int32* v);
void glVertexAttrib4s(uint32 index, int16 x, int16 y, int16 z, int16 w);
void glVertexAttrib4sv(uint32 index, const int16* v);
void glVertexAttrib4ubv(uint32 index, const uint8* v);
void glVertexAttrib4uiv(uint32 index, const uint32* v);
void glVertexAttrib4usv(uint32 index, const uint16* v);
void glVertexAttribPointer(uint32 index, int32 size, GLenum type, bool normalized, int32 stride, const void* pointer);

#pragma endregion
/// @}

/// @name gl_version_2_1
/// @{
#pragma region gl_version_2_1

void glUniformMatrix2x3fv(int32 location, int32 count, bool transpose, const float32* value);
void glUniformMatrix3x2fv(int32 location, int32 count, bool transpose, const float32* value);
void glUniformMatrix2x4fv(int32 location, int32 count, bool transpose, const float32* value);
void glUniformMatrix4x2fv(int32 location, int32 count, bool transpose, const float32* value);
void glUniformMatrix3x4fv(int32 location, int32 count, bool transpose, const float32* value);
void glUniformMatrix4x3fv(int32 location, int32 count, bool transpose, const float32* value);

#pragma endregion
/// @}

/// @name gl_version_3_0
/// @{
#pragma region gl_version_3_0

void glColorMaski(uint32 index, bool r, bool g, bool b, bool a);
void glGetBooleani_v(GLenum target, uint32 index, bool* data);
void glGetIntegeri_v(GLenum target, uint32 index, int32* data);
void glEnablei(GLenum target, uint32 index);
void glDisablei(GLenum target, uint32 index);
bool glIsEnabledi(GLenum target, uint32 index);
void glBeginTransformFeedback(GLenum primitiveMode);
void glEndTransformFeedback();
void glBindBufferRange(GLenum target, uint32 index, uint32 buffer, ptrdiff offset, ptrdiff size);
void glBindBufferBase(GLenum target, uint32 index, uint32 buffer);
void glTransformFeedbackVaryings(uint32 program, int32 count, const char* const* varyings, GLenum bufferMode);
void glGetTransformFeedbackVarying(uint32 program,
                                   uint32 index,
                                   int32 bufSize,
                                   int32* length,
                                   int32* size,
                                   GLenum* type,
                                   char* name);
void glClampColor(GLenum target, GLenum clamp);
void glBeginConditionalRender(uint32 id, GLenum mode);
void glEndConditionalRender();
void glVertexAttribIPointer(uint32 index, int32 size, GLenum type, int32 stride, const void* pointer);
void glGetVertexAttribIiv(uint32 index, GLenum pname, int32* params);
void glGetVertexAttribIuiv(uint32 index, GLenum pname, uint32* params);
void glVertexAttribI1i(uint32 index, int32 x);
void glVertexAttribI2i(uint32 index, int32 x, int32 y);
void glVertexAttribI3i(uint32 index, int32 x, int32 y, int32 z);
void glVertexAttribI4i(uint32 index, int32 x, int32 y, int32 z, int32 w);
void glVertexAttribI1ui(uint32 index, uint32 x);
void glVertexAttribI2ui(uint32 index, uint32 x, uint32 y);
void glVertexAttribI3ui(uint32 index, uint32 x, uint32 y, uint32 z);
void glVertexAttribI4ui(uint32 index, uint32 x, uint32 y, uint32 z, uint32 w);
void glVertexAttribI1iv(uint32 index, const int32* v);
void glVertexAttribI2iv(uint32 index, const int32* v);
void glVertexAttribI3iv(uint32 index, const int32* v);
void glVertexAttribI4iv(uint32 index, const int32* v);
void glVertexAttribI1uiv(uint32 index, const uint32* v);
void glVertexAttribI2uiv(uint32 index, const uint32* v);
void glVertexAttribI3uiv(uint32 index, const uint32* v);
void glVertexAttribI4uiv(uint32 index, const uint32* v);
void glVertexAttribI4bv(uint32 index, const int8* v);
void glVertexAttribI4sv(uint32 index, const int16* v);
void glVertexAttribI4ubv(uint32 index, const uint8* v);
void glVertexAttribI4usv(uint32 index, const uint16* v);
void glGetUniformuiv(uint32 program, int32 location, uint32* params);
void glBindFragDataLocation(uint32 program, uint32 color, const char* name);
int32 glGetFragDataLocation(uint32 program, const char* name);
void glUniform1ui(int32 location, uint32 v0);
void glUniform2ui(int32 location, uint32 v0, uint32 v1);
void glUniform3ui(int32 location, uint32 v0, uint32 v1, uint32 v2);
void glUniform4ui(int32 location, uint32 v0, uint32 v1, uint32 v2, uint32 v3);
void glUniform1uiv(int32 location, int32 count, const uint32* value);
void glUniform2uiv(int32 location, int32 count, const uint32* value);
void glUniform3uiv(int32 location, int32 count, const uint32* value);
void glUniform4uiv(int32 location, int32 count, const uint32* value);
void glTexParameterIiv(GLenum target, GLenum pname, const int32* params);
void glTexParameterIuiv(GLenum target, GLenum pname, const uint32* params);
void glGetTexParameterIiv(GLenum target, GLenum pname, int32* params);
void glGetTexParameterIuiv(GLenum target, GLenum pname, uint32* params);
void glClearBufferiv(GLenum buffer, int32 drawbuffer, const int32* value);
void glClearBufferuiv(GLenum buffer, int32 drawbuffer, const uint32* value);
void glClearBufferfv(GLenum buffer, int32 drawbuffer, const float32* value);
void glClearBufferfi(GLenum buffer, int32 drawbuffer, float32 depth, int32 stencil);
const uint8* glGetStringi(GLenum name, uint32 index);
bool glIsRenderbuffer(uint32 renderbuffer);
void glBindRenderbuffer(GLenum target, uint32 renderbuffer);
void glDeleteRenderbuffers(int32 n, const uint32* renderbuffers);
void glGenRenderbuffers(int32 n, uint32* renderbuffers);
void glRenderbufferStorage(GLenum target, GLenum internalformat, int32 width, int32 height);
void glGetRenderbufferParameteriv(GLenum target, GLenum pname, int32* params);
bool glIsFramebuffer(uint32 framebuffer);
void glBindFramebuffer(GLenum target, uint32 framebuffer);
void glDeleteFramebuffers(int32 n, const uint32* framebuffers);
void glGenFramebuffers(int32 n, uint32* framebuffers);
GLenum glCheckFramebufferStatus(GLenum target);
void glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, uint32 texture, int32 level);
void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, uint32 texture, int32 level);
void glFramebufferTexture3D(GLenum target,
                            GLenum attachment,
                            GLenum textarget,
                            uint32 texture,
                            int32 level,
                            int32 zoffset);
void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, uint32 renderbuffer);
void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, int32* params);
void glGenerateMipmap(GLenum target);
void glBlitFramebuffer(int32 srcX0,
                       int32 srcY0,
                       int32 srcX1,
                       int32 srcY1,
                       int32 dstX0,
                       int32 dstY0,
                       int32 dstX1,
                       int32 dstY1,
                       uint32 mask,
                       GLenum filter);
void glRenderbufferStorageMultisample(GLenum target, int32 samples, GLenum internalformat, int32 width, int32 height);
void glFramebufferTextureLayer(GLenum target, GLenum attachment, uint32 texture, int32 level, int32 layer);
void* glMapBufferRange(GLenum target, ptrdiff offset, ptrdiff length, uint32 access);
void glFlushMappedBufferRange(GLenum target, ptrdiff offset, ptrdiff length);
void glBindVertexArray(uint32 array);
void glDeleteVertexArrays(int32 n, const uint32* arrays);
void glGenVertexArrays(int32 n, uint32* arrays);
bool glIsVertexArray(uint32 array);

#pragma endregion
/// @}

/// @name gl_version_3_1
/// @{
#pragma region gl_version_3_1

void glDrawArraysInstanced(GLenum mode, int32 first, int32 count, int32 instancecount);
void glDrawElementsInstanced(GLenum mode, int32 count, GLenum type, const void* indices, int32 instancecount);
void glTexBuffer(GLenum target, GLenum internalformat, uint32 buffer);
void glPrimitiveRestartIndex(uint32 index);
void glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, ptrdiff readOffset, ptrdiff writeOffset, ptrdiff size);
void glGetUniformIndices(uint32 program, int32 uniformCount, const char* const* uniformNames, uint32* uniformIndices);
void glGetActiveUniformsiv(uint32 program,
                           int32 uniformCount,
                           const uint32* uniformIndices,
                           GLenum pname,
                           int32* params);
void glGetActiveUniformName(uint32 program, uint32 uniformIndex, int32 bufSize, int32* length, char* uniformName);
uint32 glGetUniformBlockIndex(uint32 program, const char* uniformBlockName);
void glGetActiveUniformBlockiv(uint32 program, uint32 uniformBlockIndex, GLenum pname, int32* params);
void glGetActiveUniformBlockName(uint32 program,
                                 uint32 uniformBlockIndex,
                                 int32 bufSize,
                                 int32* length,
                                 char* uniformBlockName);
void glUniformBlockBinding(uint32 program, uint32 uniformBlockIndex, uint32 uniformBlockBinding);

#pragma endregion
/// @}

/// @name gl_version_3_2
/// @{
#pragma region gl_version_3_2

void glDrawElementsBaseVertex(GLenum mode, int32 count, GLenum type, const void* indices, int32 basevertex);
void glDrawRangeElementsBaseVertex(GLenum mode,
                                   uint32 start,
                                   uint32 end,
                                   int32 count,
                                   GLenum type,
                                   const void* indices,
                                   int32 basevertex);
void glDrawElementsInstancedBaseVertex(GLenum mode,
                                       int32 count,
                                       GLenum type,
                                       const void* indices,
                                       int32 instancecount,
                                       int32 basevertex);
void glMultiDrawElementsBaseVertex(GLenum mode,
                                   const int32* count,
                                   GLenum type,
                                   const void* const* indices,
                                   int32 drawcount,
                                   const int32* basevertex);
void glProvokingVertex(GLenum mode);
GLsync glFenceSync(GLenum condition, uint32 flags);
bool glIsSync(GLsync sync);
void glDeleteSync(GLsync sync);
GLenum glClientWaitSync(GLsync sync, uint32 flags, uint64 timeout);
void glWaitSync(GLsync sync, uint32 flags, uint64 timeout);
void glGetInteger64v(GLenum pname, int64* data);
void glGetSynciv(GLsync sync, GLenum pname, int32 bufSize, int32* length, int32* values);
void glGetInteger64i_v(GLenum target, uint32 index, int64* data);
void glGetBufferParameteri64v(GLenum target, GLenum pname, int64* params);
void glFramebufferTexture(GLenum target, GLenum attachment, uint32 texture, int32 level);
void glTexImage2DMultisample(GLenum target,
                             int32 samples,
                             GLenum internalformat,
                             int32 width,
                             int32 height,
                             bool fixedsamplelocations);
void glTexImage3DMultisample(GLenum target,
                             int32 samples,
                             GLenum internalformat,
                             int32 width,
                             int32 height,
                             int32 depth,
                             bool fixedsamplelocations);
void glGetMultisamplefv(GLenum pname, uint32 index, float32* val);
void glSampleMaski(uint32 maskNumber, uint32 mask);

#pragma endregion
/// @}

/// @name gl_version_3_3
/// @{
#pragma region gl_version_3_3

void glBindFragDataLocationIndexed(uint32 program, uint32 colorNumber, uint32 index, const char* name);
int32 glGetFragDataIndex(uint32 program, const char* name);
void glGenSamplers(int32 count, uint32* samplers);
void glDeleteSamplers(int32 count, const uint32* samplers);
bool glIsSampler(uint32 sampler);
void glBindSampler(uint32 unit, uint32 sampler);
void glSamplerParameteri(uint32 sampler, GLenum pname, int32 param);
void glSamplerParameteriv(uint32 sampler, GLenum pname, const int32* param);
void glSamplerParameterf(uint32 sampler, GLenum pname, float32 param);
void glSamplerParameterfv(uint32 sampler, GLenum pname, const float32* param);
void glSamplerParameterIiv(uint32 sampler, GLenum pname, const int32* param);
void glSamplerParameterIuiv(uint32 sampler, GLenum pname, const uint32* param);
void glGetSamplerParameteriv(uint32 sampler, GLenum pname, int32* params);
void glGetSamplerParameterIiv(uint32 sampler, GLenum pname, int32* params);
void glGetSamplerParameterfv(uint32 sampler, GLenum pname, float32* params);
void glGetSamplerParameterIuiv(uint32 sampler, GLenum pname, uint32* params);
void glQueryCounter(uint32 id, GLenum target);
void glGetQueryObjecti64v(uint32 id, GLenum pname, int64* params);
void glGetQueryObjectui64v(uint32 id, GLenum pname, uint64* params);
void glVertexAttribDivisor(uint32 index, uint32 divisor);
void glVertexAttribP1ui(uint32 index, GLenum type, bool normalized, uint32 value);
void glVertexAttribP1uiv(uint32 index, GLenum type, bool normalized, const uint32* value);
void glVertexAttribP2ui(uint32 index, GLenum type, bool normalized, uint32 value);
void glVertexAttribP2uiv(uint32 index, GLenum type, bool normalized, const uint32* value);
void glVertexAttribP3ui(uint32 index, GLenum type, bool normalized, uint32 value);
void glVertexAttribP3uiv(uint32 index, GLenum type, bool normalized, const uint32* value);
void glVertexAttribP4ui(uint32 index, GLenum type, bool normalized, uint32 value);
void glVertexAttribP4uiv(uint32 index, GLenum type, bool normalized, const uint32* value);

#pragma endregion
/// @}

/// @name gl_version_4_0
/// @{
#pragma region gl_version_4_0

void glMinSampleShading(float32 value);
void glBlendEquationi(uint32 buf, GLenum mode);
void glBlendEquationSeparatei(uint32 buf, GLenum modeRGB, GLenum modeAlpha);
void glBlendFunci(uint32 buf, GLenum src, GLenum dst);
void glBlendFuncSeparatei(uint32 buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
void glDrawArraysIndirect(GLenum mode, const void* indirect);
void glDrawElementsIndirect(GLenum mode, GLenum type, const void* indirect);
void glUniform1d(int32 location, float64 x);
void glUniform2d(int32 location, float64 x, float64 y);
void glUniform3d(int32 location, float64 x, float64 y, float64 z);
void glUniform4d(int32 location, float64 x, float64 y, float64 z, float64 w);
void glUniform1dv(int32 location, int32 count, const float64* value);
void glUniform2dv(int32 location, int32 count, const float64* value);
void glUniform3dv(int32 location, int32 count, const float64* value);
void glUniform4dv(int32 location, int32 count, const float64* value);
void glUniformMatrix2dv(int32 location, int32 count, bool transpose, const float64* value);
void glUniformMatrix3dv(int32 location, int32 count, bool transpose, const float64* value);
void glUniformMatrix4dv(int32 location, int32 count, bool transpose, const float64* value);
void glUniformMatrix2x3dv(int32 location, int32 count, bool transpose, const float64* value);
void glUniformMatrix2x4dv(int32 location, int32 count, bool transpose, const float64* value);
void glUniformMatrix3x2dv(int32 location, int32 count, bool transpose, const float64* value);
void glUniformMatrix3x4dv(int32 location, int32 count, bool transpose, const float64* value);
void glUniformMatrix4x2dv(int32 location, int32 count, bool transpose, const float64* value);
void glUniformMatrix4x3dv(int32 location, int32 count, bool transpose, const float64* value);
void glGetUniformdv(uint32 program, int32 location, float64* params);
int32 glGetSubroutineUniformLocation(uint32 program, GLenum shadertype, const char* name);
uint32 glGetSubroutineIndex(uint32 program, GLenum shadertype, const char* name);
void glGetActiveSubroutineUniformiv(uint32 program, GLenum shadertype, uint32 index, GLenum pname, int32* values);
void glGetActiveSubroutineUniformName(uint32 program,
                                      GLenum shadertype,
                                      uint32 index,
                                      int32 bufsize,
                                      int32* length,
                                      char* name);
void glGetActiveSubroutineName(uint32 program,
                               GLenum shadertype,
                               uint32 index,
                               int32 bufsize,
                               int32* length,
                               char* name);
void glUniformSubroutinesuiv(GLenum shadertype, int32 count, const uint32* indices);
void glGetUniformSubroutineuiv(GLenum shadertype, int32 location, uint32* params);
void glGetProgramStageiv(uint32 program, GLenum shadertype, GLenum pname, int32* values);
void glPatchParameteri(GLenum pname, int32 value);
void glPatchParameterfv(GLenum pname, const float32* values);
void glBindTransformFeedback(GLenum target, uint32 id);
void glDeleteTransformFeedbacks(int32 n, const uint32* ids);
void glGenTransformFeedbacks(int32 n, uint32* ids);
bool glIsTransformFeedback(uint32 id);
void glPauseTransformFeedback();
void glResumeTransformFeedback();
void glDrawTransformFeedback(GLenum mode, uint32 id);
void glDrawTransformFeedbackStream(GLenum mode, uint32 id, uint32 stream);
void glBeginQueryIndexed(GLenum target, uint32 index, uint32 id);
void glEndQueryIndexed(GLenum target, uint32 index);
void glGetQueryIndexediv(GLenum target, uint32 index, GLenum pname, int32* params);

#pragma endregion
/// @}

/// @name gl_version_4_1
/// @{
#pragma region gl_version_4_1

void glReleaseShaderCompiler(void);
void glShaderBinary(int32 count, const uint32* shaders, GLenum binaryformat, const void* binary, int32 length);
void glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, int32* range, int32* precision);
void glDepthRangef(float32 n, float32 f);
void glClearDepthf(float32 d);
void glGetProgramBinary(uint32 program, int32 bufSize, int32* length, GLenum* binaryFormat, void* binary);
void glProgramBinary(uint32 program, GLenum binaryFormat, const void* binary, int32 length);
void glProgramParameteri(uint32 program, GLenum pname, int32 value);
void glUseProgramStages(uint32 pipeline, uint32 stages, uint32 program);
void glActiveShaderProgram(uint32 pipeline, uint32 program);
uint32 glCreateShaderProgramv(GLenum type, int32 count, const char* const* strings);
void glBindProgramPipeline(uint32 pipeline);
void glDeleteProgramPipelines(int32 n, const uint32* pipelines);
void glGenProgramPipelines(int32 n, uint32* pipelines);
bool glIsProgramPipeline(uint32 pipeline);
void glGetProgramPipelineiv(uint32 pipeline, GLenum pname, int32* params);
void glProgramUniform1i(uint32 program, int32 location, int32 v0);
void glProgramUniform1iv(uint32 program, int32 location, int32 count, const int32* value);
void glProgramUniform1f(uint32 program, int32 location, float32 v0);
void glProgramUniform1fv(uint32 program, int32 location, int32 count, const float32* value);
void glProgramUniform1d(uint32 program, int32 location, float64 v0);
void glProgramUniform1dv(uint32 program, int32 location, int32 count, const float64* value);
void glProgramUniform1ui(uint32 program, int32 location, uint32 v0);
void glProgramUniform1uiv(uint32 program, int32 location, int32 count, const uint32* value);
void glProgramUniform2i(uint32 program, int32 location, int32 v0, int32 v1);
void glProgramUniform2iv(uint32 program, int32 location, int32 count, const int32* value);
void glProgramUniform2f(uint32 program, int32 location, float32 v0, float32 v1);
void glProgramUniform2fv(uint32 program, int32 location, int32 count, const float32* value);
void glProgramUniform2d(uint32 program, int32 location, float64 v0, float64 v1);
void glProgramUniform2dv(uint32 program, int32 location, int32 count, const float64* value);
void glProgramUniform2ui(uint32 program, int32 location, uint32 v0, uint32 v1);
void glProgramUniform2uiv(uint32 program, int32 location, int32 count, const uint32* value);
void glProgramUniform3i(uint32 program, int32 location, int32 v0, int32 v1, int32 v2);
void glProgramUniform3iv(uint32 program, int32 location, int32 count, const int32* value);
void glProgramUniform3f(uint32 program, int32 location, float32 v0, float32 v1, float32 v2);
void glProgramUniform3fv(uint32 program, int32 location, int32 count, const float32* value);
void glProgramUniform3d(uint32 program, int32 location, float64 v0, float64 v1, float64 v2);
void glProgramUniform3dv(uint32 program, int32 location, int32 count, const float64* value);
void glProgramUniform3ui(uint32 program, int32 location, uint32 v0, uint32 v1, uint32 v2);
void glProgramUniform3uiv(uint32 program, int32 location, int32 count, const uint32* value);
void glProgramUniform4i(uint32 program, int32 location, int32 v0, int32 v1, int32 v2, int32 v3);
void glProgramUniform4iv(uint32 program, int32 location, int32 count, const int32* value);
void glProgramUniform4f(uint32 program, int32 location, float32 v0, float32 v1, float32 v2, float32 v3);
void glProgramUniform4fv(uint32 program, int32 location, int32 count, const float32* value);
void glProgramUniform4d(uint32 program, int32 location, float64 v0, float64 v1, float64 v2, float64 v3);
void glProgramUniform4dv(uint32 program, int32 location, int32 count, const float64* value);
void glProgramUniform4ui(uint32 program, int32 location, uint32 v0, uint32 v1, uint32 v2, uint32 v3);
void glProgramUniform4uiv(uint32 program, int32 location, int32 count, const uint32* value);
void glProgramUniformMatrix2fv(uint32 program, int32 location, int32 count, bool transpose, const float32* value);
void glProgramUniformMatrix3fv(uint32 program, int32 location, int32 count, bool transpose, const float32* value);
void glProgramUniformMatrix4fv(uint32 program, int32 location, int32 count, bool transpose, const float32* value);
void glProgramUniformMatrix2dv(uint32 program, int32 location, int32 count, bool transpose, const float64* value);
void glProgramUniformMatrix3dv(uint32 program, int32 location, int32 count, bool transpose, const float64* value);
void glProgramUniformMatrix4dv(uint32 program, int32 location, int32 count, bool transpose, const float64* value);
void glProgramUniformMatrix2x3fv(uint32 program, int32 location, int32 count, bool transpose, const float32* value);
void glProgramUniformMatrix3x2fv(uint32 program, int32 location, int32 count, bool transpose, const float32* value);
void glProgramUniformMatrix2x4fv(uint32 program, int32 location, int32 count, bool transpose, const float32* value);
void glProgramUniformMatrix4x2fv(uint32 program, int32 location, int32 count, bool transpose, const float32* value);
void glProgramUniformMatrix3x4fv(uint32 program, int32 location, int32 count, bool transpose, const float32* value);
void glProgramUniformMatrix4x3fv(uint32 program, int32 location, int32 count, bool transpose, const float32* value);
void glProgramUniformMatrix2x3dv(uint32 program, int32 location, int32 count, bool transpose, const float64* value);
void glProgramUniformMatrix3x2dv(uint32 program, int32 location, int32 count, bool transpose, const float64* value);
void glProgramUniformMatrix2x4dv(uint32 program, int32 location, int32 count, bool transpose, const float64* value);
void glProgramUniformMatrix4x2dv(uint32 program, int32 location, int32 count, bool transpose, const float64* value);
void glProgramUniformMatrix3x4dv(uint32 program, int32 location, int32 count, bool transpose, const float64* value);
void glProgramUniformMatrix4x3dv(uint32 program, int32 location, int32 count, bool transpose, const float64* value);
void glValidateProgramPipeline(uint32 pipeline);
void glGetProgramPipelineInfoLog(uint32 pipeline, int32 bufSize, int32* length, char* infoLog);
void glVertexAttribL1d(uint32 index, float64 x);
void glVertexAttribL2d(uint32 index, float64 x, float64 y);
void glVertexAttribL3d(uint32 index, float64 x, float64 y, float64 z);
void glVertexAttribL4d(uint32 index, float64 x, float64 y, float64 z, float64 w);
void glVertexAttribL1dv(uint32 index, const float64* v);
void glVertexAttribL2dv(uint32 index, const float64* v);
void glVertexAttribL3dv(uint32 index, const float64* v);
void glVertexAttribL4dv(uint32 index, const float64* v);
void glVertexAttribLPointer(uint32 index, int32 size, GLenum type, int32 stride, const void* pointer);
void glGetVertexAttribLdv(uint32 index, GLenum pname, float64* params);
void glViewportArrayv(uint32 first, int32 count, const float32* v);
void glViewportIndexedf(uint32 index, float32 x, float32 y, float32 w, float32 h);
void glViewportIndexedfv(uint32 index, const float32* v);
void glScissorArrayv(uint32 first, int32 count, const int32* v);
void glScissorIndexed(uint32 index, int32 left, int32 bottom, int32 width, int32 height);
void glScissorIndexedv(uint32 index, const int32* v);
void glDepthRangeArrayv(uint32 first, int32 count, const float64* v);
void glDepthRangeIndexed(uint32 index, float64 n, float64 f);
void glGetFloati_v(GLenum target, uint32 index, float32* data);
void glGetDoublei_v(GLenum target, uint32 index, float64* data);

#pragma endregion
/// @}

/// @name gl_version_4_2
/// @{
#pragma region gl_version_4_2

void glDrawArraysInstancedBaseInstance(GLenum mode, int32 first, int32 count, int32 instancecount, uint32 baseinstance);
void glDrawElementsInstancedBaseInstance(GLenum mode,
                                         int32 count,
                                         GLenum type,
                                         const void* indices,
                                         int32 instancecount,
                                         uint32 baseinstance);
void glDrawElementsInstancedBaseVertexBaseInstance(GLenum mode,
                                                   int32 count,
                                                   GLenum type,
                                                   const void* indices,
                                                   int32 instancecount,
                                                   int32 basevertex,
                                                   uint32 baseinstance);
void glGetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, int32 bufSize, int32* params);
void glGetActiveAtomicCounterBufferiv(uint32 program, uint32 bufferIndex, GLenum pname, int32* params);
void glBindImageTexture(uint32 unit,
                        uint32 texture,
                        int32 level,
                        bool layered,
                        int32 layer,
                        GLenum access,
                        GLenum format);
void glMemoryBarrier(uint32 barriers);
void glTexStorage1D(GLenum target, int32 levels, GLenum internalformat, int32 width);
void glTexStorage2D(GLenum target, int32 levels, GLenum internalformat, int32 width, int32 height);
void glTexStorage3D(GLenum target, int32 levels, GLenum internalformat, int32 width, int32 height, int32 depth);
void glDrawTransformFeedbackInstanced(GLenum mode, uint32 id, int32 instancecount);
void glDrawTransformFeedbackStreamInstanced(GLenum mode, uint32 id, uint32 stream, int32 instancecount);

#pragma endregion
/// @}

/// @name gl_version_4_3
/// @{
#pragma region gl_version_4_3

void glClearBufferData(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void* data);
void glClearBufferSubData(GLenum target,
                          GLenum internalformat,
                          ptrdiff offset,
                          ptrdiff size,
                          GLenum format,
                          GLenum type,
                          const void* data);
void glDispatchCompute(uint32 num_groups_x, uint32 num_groups_y, uint32 num_groups_z);
void glDispatchComputeIndirect(ptrdiff indirect);
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
                        int32 srcDepth);
void glFramebufferParameteri(GLenum target, GLenum pname, int32 param);
void glGetFramebufferParameteriv(GLenum target, GLenum pname, int32* params);
void glGetInternalformati64v(GLenum target, GLenum internalformat, GLenum pname, int32 bufSize, int64* params);
void glInvalidateTexSubImage(uint32 texture,
                             int32 level,
                             int32 xoffset,
                             int32 yoffset,
                             int32 zoffset,
                             int32 width,
                             int32 height,
                             int32 depth);
void glInvalidateTexImage(uint32 texture, int32 level);
void glInvalidateBufferSubData(uint32 buffer, ptrdiff offset, ptrdiff length);
void glInvalidateBufferData(uint32 buffer);
void glInvalidateFramebuffer(GLenum target, int32 numAttachments, const GLenum* attachments);
void glInvalidateSubFramebuffer(GLenum target,
                                int32 numAttachments,
                                const GLenum* attachments,
                                int32 x,
                                int32 y,
                                int32 width,
                                int32 height);
void glMultiDrawArraysIndirect(GLenum mode, const void* indirect, int32 drawcount, int32 stride);
void glMultiDrawElementsIndirect(GLenum mode, GLenum type, const void* indirect, int32 drawcount, int32 stride);
void glGetProgramInterfaceiv(uint32 program, GLenum programInterface, GLenum pname, int32* params);
uint32 glGetProgramResourceIndex(uint32 program, GLenum programInterface, const char* name);
void glGetProgramResourceName(uint32 program,
                              GLenum programInterface,
                              uint32 index,
                              int32 bufSize,
                              int32* length,
                              char* name);
void glGetProgramResourceiv(uint32 program,
                            GLenum programInterface,
                            uint32 index,
                            int32 propCount,
                            const GLenum* props,
                            int32 bufSize,
                            int32* length,
                            int32* params);
int32 glGetProgramResourceLocation(uint32 program, GLenum programInterface, const char* name);
int32 glGetProgramResourceLocationIndex(uint32 program, GLenum programInterface, const char* name);
void glShaderStorageBlockBinding(uint32 program, uint32 storageBlockIndex, uint32 storageBlockBinding);
void glTexBufferRange(GLenum target, GLenum internalformat, uint32 buffer, ptrdiff offset, ptrdiff size);
void glTexStorage2DMultisample(GLenum target,
                               int32 samples,
                               GLenum internalformat,
                               int32 width,
                               int32 height,
                               bool fixedsamplelocations);
void glTexStorage3DMultisample(GLenum target,
                               int32 samples,
                               GLenum internalformat,
                               int32 width,
                               int32 height,
                               int32 depth,
                               bool fixedsamplelocations);
void glTextureView(uint32 texture,
                   GLenum target,
                   uint32 origtexture,
                   GLenum internalformat,
                   uint32 minlevel,
                   uint32 numlevels,
                   uint32 minlayer,
                   uint32 numlayers);
void glBindVertexBuffer(uint32 bindingindex, uint32 buffer, ptrdiff offset, int32 stride);
void glVertexAttribFormat(uint32 attribindex, int32 size, GLenum type, bool normalized, uint32 relativeoffset);
void glVertexAttribIFormat(uint32 attribindex, int32 size, GLenum type, uint32 relativeoffset);
void glVertexAttribLFormat(uint32 attribindex, int32 size, GLenum type, uint32 relativeoffset);
void glVertexAttribBinding(uint32 attribindex, uint32 bindingindex);
void glVertexBindingDivisor(uint32 bindingindex, uint32 divisor);
void glDebugMessageControl(GLenum source, GLenum type, GLenum severity, int32 count, const uint32* ids, bool enabled);
void glDebugMessageInsert(GLenum source, GLenum type, uint32 id, GLenum severity, int32 length, const char* buf);
void glDebugMessageCallback(debug_proc_callback callback, const void* userParam);
uint32 glGetDebugMessageLog(uint32 count,
                            int32 bufSize,
                            GLenum* sources,
                            GLenum* types,
                            uint32* ids,
                            GLenum* severities,
                            int32* lengths,
                            char* messageLog);
void glPushDebugGroup(GLenum source, uint32 id, int32 length, const char* message);
void glPopDebugGroup();
void glObjectLabel(GLenum identifier, uint32 name, int32 length, const char* label);
void glGetObjectLabel(GLenum identifier, uint32 name, int32 bufSize, int32* length, char* label);
void glObjectPtrLabel(const void* ptr, int32 length, const char* label);
void glGetObjectPtrLabel(const void* ptr, int32 bufSize, int32* length, char* label);

#pragma endregion
/// @}

/// @name gl_version_4_4
/// @{
#pragma region gl_version_4_4

void glBufferStorage(GLenum target, ptrdiff size, const void* data, uint32 flags);
void glClearTexImage(uint32 texture, int32 level, GLenum format, GLenum type, const void* data);
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
                        const void* data);
void glBindBuffersBase(GLenum target, uint32 first, int32 count, const uint32* buffers);
void glBindBuffersRange(GLenum target,
                        uint32 first,
                        int32 count,
                        const uint32* buffers,
                        const ptrdiff* offsets,
                        const ptrdiff* sizes);
void glBindTextures(uint32 first, int32 count, const uint32* textures);
void glBindSamplers(uint32 first, int32 count, const uint32* samplers);
void glBindImageTextures(uint32 first, int32 count, const uint32* textures);
void glBindVertexBuffers(uint32 first, int32 count, const uint32* buffers, const ptrdiff* offsets, const int32* strides);

#pragma endregion
/// @}

/// @name gl_version_4_5
/// @{
#pragma region gl_version_4_5

void glClipControl(GLenum origin, GLenum depth);
void glCreateTransformFeedbacks(int32 n, uint32* ids);
void glTransformFeedbackBufferBase(uint32 xfb, uint32 index, uint32 buffer);
void glTransformFeedbackBufferRange(uint32 xfb, uint32 index, uint32 buffer, ptrdiff offset, ptrdiff size);
void glGetTransformFeedbackiv(uint32 xfb, GLenum pname, int32* param);
void glGetTransformFeedbacki_v(uint32 xfb, GLenum pname, uint32 index, int32* param);
void glGetTransformFeedbacki64_v(uint32 xfb, GLenum pname, uint32 index, int64* param);
void glCreateBuffers(int32 n, uint32* buffers);
void glNamedBufferStorage(uint32 buffer, ptrdiff size, const void* data, uint32 flags);
void glNamedBufferData(uint32 buffer, ptrdiff size, const void* data, GLenum usage);
void glNamedBufferSubData(uint32 buffer, ptrdiff offset, ptrdiff size, const void* data);
void glCopyNamedBufferSubData(uint32 readBuffer,
                              uint32 writeBuffer,
                              ptrdiff readOffset,
                              ptrdiff writeOffset,
                              ptrdiff size);
void glClearNamedBufferData(uint32 buffer, GLenum internalformat, GLenum format, GLenum type, const void* data);
void glClearNamedBufferSubData(uint32 buffer,
                               GLenum internalformat,
                               ptrdiff offset,
                               ptrdiff size,
                               GLenum format,
                               GLenum type,
                               const void* data);
void* glMapNamedBuffer(uint32 buffer, GLenum access);
void* glMapNamedBufferRange(uint32 buffer, ptrdiff offset, ptrdiff length, uint32 access);
bool glUnmapNamedBuffer(uint32 buffer);
void glFlushMappedNamedBufferRange(uint32 buffer, ptrdiff offset, ptrdiff length);
void glGetNamedBufferParameteriv(uint32 buffer, GLenum pname, int32* params);
void glGetNamedBufferParameteri64v(uint32 buffer, GLenum pname, int64* params);
void glGetNamedBufferPointerv(uint32 buffer, GLenum pname, void** params);
void glGetNamedBufferSubData(uint32 buffer, ptrdiff offset, ptrdiff size, void* data);
void glCreateFramebuffers(int32 n, uint32* framebuffers);
void glNamedFramebufferRenderbuffer(uint32 framebuffer,
                                    GLenum attachment,
                                    GLenum renderbuffertarget,
                                    uint32 renderbuffer);
void glNamedFramebufferParameteri(uint32 framebuffer, GLenum pname, int32 param);
void glNamedFramebufferTexture(uint32 framebuffer, GLenum attachment, uint32 texture, int32 level);
void glNamedFramebufferTextureLayer(uint32 framebuffer, GLenum attachment, uint32 texture, int32 level, int32 layer);
void glNamedFramebufferDrawBuffer(uint32 framebuffer, GLenum buf);
void glNamedFramebufferDrawBuffers(uint32 framebuffer, int32 n, const GLenum* bufs);
void glNamedFramebufferReadBuffer(uint32 framebuffer, GLenum src);
void glInvalidateNamedFramebufferData(uint32 framebuffer, int32 numAttachments, const GLenum* attachments);
void glInvalidateNamedFramebufferSubData(uint32 framebuffer,
                                         int32 numAttachments,
                                         const GLenum* attachments,
                                         int32 x,
                                         int32 y,
                                         int32 width,
                                         int32 height);
void glClearNamedFramebufferiv(uint32 framebuffer, GLenum buffer, int32 drawbuffer, const int32* value);
void glClearNamedFramebufferuiv(uint32 framebuffer, GLenum buffer, int32 drawbuffer, const uint32* value);
void glClearNamedFramebufferfv(uint32 framebuffer, GLenum buffer, int32 drawbuffer, const float32* value);
void glClearNamedFramebufferfi(uint32 framebuffer, GLenum buffer, int32 drawbuffer, float32 depth, int32 stencil);
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
                            GLenum filter);
GLenum glCheckNamedFramebufferStatus(uint32 framebuffer, GLenum target);
void glGetNamedFramebufferParameteriv(uint32 framebuffer, GLenum pname, int32* param);
void glGetNamedFramebufferAttachmentParameteriv(uint32 framebuffer, GLenum attachment, GLenum pname, int32* params);
void glCreateRenderbuffers(int32 n, uint32* renderbuffers);
void glNamedRenderbufferStorage(uint32 renderbuffer, GLenum internalformat, int32 width, int32 height);
void glNamedRenderbufferStorageMultisample(uint32 renderbuffer,
                                           int32 samples,
                                           GLenum internalformat,
                                           int32 width,
                                           int32 height);
void glGetNamedRenderbufferParameteriv(uint32 renderbuffer, GLenum pname, int32* params);
void glCreateTextures(GLenum target, int32 n, uint32* textures);
void glTextureBuffer(uint32 texture, GLenum internalformat, uint32 buffer);
void glTextureBufferRange(uint32 texture, GLenum internalformat, uint32 buffer, ptrdiff offset, ptrdiff size);
void glTextureStorage1D(uint32 texture, int32 levels, GLenum internalformat, int32 width);
void glTextureStorage2D(uint32 texture, int32 levels, GLenum internalformat, int32 width, int32 height);
void glTextureStorage3D(uint32 texture, int32 levels, GLenum internalformat, int32 width, int32 height, int32 depth);
void glTextureStorage2DMultisample(uint32 texture,
                                   int32 samples,
                                   GLenum internalformat,
                                   int32 width,
                                   int32 height,
                                   bool fixedsamplelocations);
void glTextureStorage3DMultisample(uint32 texture,
                                   int32 samples,
                                   GLenum internalformat,
                                   int32 width,
                                   int32 height,
                                   int32 depth,
                                   bool fixedsamplelocations);
void glTextureSubImage1D(uint32 texture,
                         int32 level,
                         int32 xoffset,
                         int32 width,
                         GLenum format,
                         GLenum type,
                         const void* pixels);
void glTextureSubImage2D(uint32 texture,
                         int32 level,
                         int32 xoffset,
                         int32 yoffset,
                         int32 width,
                         int32 height,
                         GLenum format,
                         GLenum type,
                         const void* pixels);
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
                         const void* pixels);
void glCompressedTextureSubImage1D(uint32 texture,
                                   int32 level,
                                   int32 xoffset,
                                   int32 width,
                                   GLenum format,
                                   int32 imageSize,
                                   const void* data);
void glCompressedTextureSubImage2D(uint32 texture,
                                   int32 level,
                                   int32 xoffset,
                                   int32 yoffset,
                                   int32 width,
                                   int32 height,
                                   GLenum format,
                                   int32 imageSize,
                                   const void* data);
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
                                   const void* data);
void glCopyTextureSubImage1D(uint32 texture, int32 level, int32 xoffset, int32 x, int32 y, int32 width);
void glCopyTextureSubImage2D(uint32 texture,
                             int32 level,
                             int32 xoffset,
                             int32 yoffset,
                             int32 x,
                             int32 y,
                             int32 width,
                             int32 height);
void glCopyTextureSubImage3D(uint32 texture,
                             int32 level,
                             int32 xoffset,
                             int32 yoffset,
                             int32 zoffset,
                             int32 x,
                             int32 y,
                             int32 width,
                             int32 height);
void glTextureParameterf(uint32 texture, GLenum pname, float32 param);
void glTextureParameterfv(uint32 texture, GLenum pname, const float32* param);
void glTextureParameteri(uint32 texture, GLenum pname, int32 param);
void glTextureParameterIiv(uint32 texture, GLenum pname, const int32* params);
void glTextureParameterIuiv(uint32 texture, GLenum pname, const uint32* params);
void glTextureParameteriv(uint32 texture, GLenum pname, const int32* param);
void glGenerateTextureMipmap(uint32 texture);
void glBindTextureUnit(uint32 unit, uint32 texture);
void glGetTextureImage(uint32 texture, int32 level, GLenum format, GLenum type, int32 bufSize, void* pixels);
void glGetCompressedTextureImage(uint32 texture, int32 level, int32 bufSize, void* pixels);
void glGetTextureLevelParameterfv(uint32 texture, int32 level, GLenum pname, float32* params);
void glGetTextureLevelParameteriv(uint32 texture, int32 level, GLenum pname, int32* params);
void glGetTextureParameterfv(uint32 texture, GLenum pname, float32* params);
void glGetTextureParameterIiv(uint32 texture, GLenum pname, int32* params);
void glGetTextureParameterIuiv(uint32 texture, GLenum pname, uint32* params);
void glGetTextureParameteriv(uint32 texture, GLenum pname, int32* params);
void glCreateVertexArrays(int32 n, uint32* arrays);
void glDisableVertexArrayAttrib(uint32 vaobj, uint32 index);
void glEnableVertexArrayAttrib(uint32 vaobj, uint32 index);
void glVertexArrayElementBuffer(uint32 vaobj, uint32 buffer);
void glVertexArrayVertexBuffer(uint32 vaobj, uint32 bindingindex, uint32 buffer, ptrdiff offset, int32 stride);
void glVertexArrayVertexBuffers(uint32 vaobj,
                                uint32 first,
                                int32 count,
                                const uint32* buffers,
                                const ptrdiff* offsets,
                                const int32* strides);
void glVertexArrayAttribBinding(uint32 vaobj, uint32 attribindex, uint32 bindingindex);
void glVertexArrayAttribFormat(uint32 vaobj,
                               uint32 attribindex,
                               int32 size,
                               GLenum type,
                               bool normalized,
                               uint32 relativeoffset);
void glVertexArrayAttribIFormat(uint32 vaobj, uint32 attribindex, int32 size, GLenum type, uint32 relativeoffset);
void glVertexArrayAttribLFormat(uint32 vaobj, uint32 attribindex, int32 size, GLenum type, uint32 relativeoffset);
void glVertexArrayBindingDivisor(uint32 vaobj, uint32 bindingindex, uint32 divisor);
void glGetVertexArrayiv(uint32 vaobj, GLenum pname, int32* param);
void glGetVertexArrayIndexediv(uint32 vaobj, uint32 index, GLenum pname, int32* param);
void glGetVertexArrayIndexed64iv(uint32 vaobj, uint32 index, GLenum pname, int64* param);
void glCreateSamplers(int32 n, uint32* samplers);
void glCreateProgramPipelines(int32 n, uint32* pipelines);
void glCreateQueries(GLenum target, int32 n, uint32* ids);
void glGetQueryBufferObjecti64v(uint32 id, uint32 buffer, GLenum pname, ptrdiff offset);
void glGetQueryBufferObjectiv(uint32 id, uint32 buffer, GLenum pname, ptrdiff offset);
void glGetQueryBufferObjectui64v(uint32 id, uint32 buffer, GLenum pname, ptrdiff offset);
void glGetQueryBufferObjectuiv(uint32 id, uint32 buffer, GLenum pname, ptrdiff offset);
void glMemoryBarrierByRegion(uint32 barriers);
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
                          void* pixels);
void glGetCompressedTextureSubImage(uint32 texture,
                                    int32 level,
                                    int32 xoffset,
                                    int32 yoffset,
                                    int32 zoffset,
                                    int32 width,
                                    int32 height,
                                    int32 depth,
                                    int32 bufSize,
                                    void* pixels);
GLenum glGetGraphicsResetStatus();
void glGetnCompressedTexImage(GLenum target, int32 lod, int32 bufSize, void* pixels);
void glGetnTexImage(GLenum target, int32 level, GLenum format, GLenum type, int32 bufSize, void* pixels);
void glGetnUniformdv(uint32 program, int32 location, int32 bufSize, float64* params);
void glGetnUniformfv(uint32 program, int32 location, int32 bufSize, float32* params);
void glGetnUniformiv(uint32 program, int32 location, int32 bufSize, int32* params);
void glGetnUniformuiv(uint32 program, int32 location, int32 bufSize, uint32* params);
void glReadnPixels(int32 x, int32 y, int32 width, int32 height, GLenum format, GLenum type, int32 bufSize, void* data);
void glTextureBarrier();

#pragma endregion
/// @}

/// @name gl_version_4_6
/// @{
#pragma region gl_version_4_6

void glSpecializeShader(uint32 shader,
                        const char* pEntryPoint,
                        uint32 numSpecializationConstants,
                        const uint32* pConstantIndex,
                        const uint32* pConstantValue);
void glMultiDrawArraysIndirectCount(GLenum mode,
                                    const void* indirect,
                                    ptrdiff drawcount,
                                    int32 maxdrawcount,
                                    int32 stride);
void glMultiDrawElementsIndirectCount(GLenum mode,
                                      GLenum type,
                                      const void* indirect,
                                      ptrdiff drawcount,
                                      int32 maxdrawcount,
                                      int32 stride);
void glPolygonOffsetClamp(float32 factor, float32 units, float32 clamp);

#pragma endregion
/// @}

} // namespace gl

} // namespace graphic

} // namespace framework
