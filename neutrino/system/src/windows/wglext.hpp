/// @file
/// @brief WGL extension functions wrapper.
/// @author Fedorov Alexey
/// @date 17.09.2018

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

#ifndef FRAMEWORK_SYSTEM_SRC_WINDOWS_WGLEXT_HPP
#define FRAMEWORK_SYSTEM_SRC_WINDOWS_WGLEXT_HPP

#include <functional>

#include <Windows.h>

typedef void GLvoid;
typedef unsigned int GLenum;
typedef float GLfloat;
typedef int GLint;
typedef int GLsizei;
typedef unsigned int GLbitfield;
typedef double GLdouble;
typedef unsigned int GLuint;
typedef unsigned char GLboolean;
typedef unsigned char GLubyte;
typedef unsigned short GLushort;

namespace framework::system::details::wgl
{

#pragma region WGL_3DFX_multisample

constexpr int WGL_SAMPLE_BUFFERS_3DFX = 0x2060;
constexpr int WGL_SAMPLES_3DFX        = 0x2061;

#pragma endregion

#pragma region WGL_3DL_stereo_control

constexpr int WGL_STEREO_EMITTER_ENABLE_3DL  = 0x2055;
constexpr int WGL_STEREO_EMITTER_DISABLE_3DL = 0x2056;
constexpr int WGL_STEREO_POLARITY_NORMAL_3DL = 0x2057;
constexpr int WGL_STEREO_POLARITY_INVERT_3DL = 0x2058;

BOOL wglSetStereoEmitterState3DL(HDC hDC, UINT uState);

#pragma endregion

#pragma region WGL_AMD_gpu_association

constexpr int WGL_GPU_VENDOR_AMD                = 0x1F00;
constexpr int WGL_GPU_RENDERER_STRING_AMD       = 0x1F01;
constexpr int WGL_GPU_OPENGL_VERSION_STRING_AMD = 0x1F02;
constexpr int WGL_GPU_FASTEST_TARGET_GPUS_AMD   = 0x21A2;
constexpr int WGL_GPU_RAM_AMD                   = 0x21A3;
constexpr int WGL_GPU_CLOCK_AMD                 = 0x21A4;
constexpr int WGL_GPU_NUM_PIPES_AMD             = 0x21A5;
constexpr int WGL_GPU_NUM_SIMD_AMD              = 0x21A6;
constexpr int WGL_GPU_NUM_RB_AMD                = 0x21A7;
constexpr int WGL_GPU_NUM_SPI_AMD               = 0x21A8;

UINT wglGetGPUIDsAMD(UINT maxCount, UINT* ids);
INT wglGetGPUInfoAMD(UINT id, INT property, GLenum dataType, UINT size, void* data);
UINT wglGetContextGPUIDAMD(HGLRC hglrc);
HGLRC wglCreateAssociatedContextAMD(UINT id);
HGLRC wglCreateAssociatedContextAttribsAMD(UINT id, HGLRC hShareContext, const int* attribList);
BOOL wglDeleteAssociatedContextAMD(HGLRC hglrc);
BOOL wglMakeAssociatedContextCurrentAMD(HGLRC hglrc);
HGLRC wglGetCurrentAssociatedContextAMD();
VOID wglBlitContextFramebufferAMD(HGLRC dstCtx,
                                  GLint srcX0,
                                  GLint srcY0,
                                  GLint srcX1,
                                  GLint srcY1,
                                  GLint dstX0,
                                  GLint dstY0,
                                  GLint dstX1,
                                  GLint dstY1,
                                  GLbitfield mask,
                                  GLenum filter);

#pragma endregion

#pragma region WGL_ARB_buffer_region

constexpr int WGL_FRONT_COLOR_BUFFER_BIT_ARB = 0x00000001;
constexpr int WGL_BACK_COLOR_BUFFER_BIT_ARB  = 0x00000002;
constexpr int WGL_DEPTH_BUFFER_BIT_ARB       = 0x00000004;
constexpr int WGL_STENCIL_BUFFER_BIT_ARB     = 0x00000008;

HANDLE wglCreateBufferRegionARB(HDC hDC, int iLayerPlane, UINT uType);
VOID wglDeleteBufferRegionARB(HANDLE hRegion);
BOOL wglSaveBufferRegionARB(HANDLE hRegion, int x, int y, int width, int height);
BOOL wglRestoreBufferRegionARB(HANDLE hRegion, int x, int y, int width, int height, int xSrc, int ySrc);

#pragma endregion

#pragma region WGL_ARB_context_flush_control

constexpr int WGL_CONTEXT_RELEASE_BEHAVIOR_ARB       = 0x2097;
constexpr int WGL_CONTEXT_RELEASE_BEHAVIOR_NONE_ARB  = 0;
constexpr int WGL_CONTEXT_RELEASE_BEHAVIOR_FLUSH_ARB = 0x2098;

#pragma endregion

#pragma region WGL_ARB_create_context

constexpr int WGL_CONTEXT_DEBUG_BIT_ARB              = 0x00000001;
constexpr int WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB = 0x00000002;
constexpr int WGL_CONTEXT_MAJOR_VERSION_ARB          = 0x2091;
constexpr int WGL_CONTEXT_MINOR_VERSION_ARB          = 0x2092;
constexpr int WGL_CONTEXT_LAYER_PLANE_ARB            = 0x2093;
constexpr int WGL_CONTEXT_FLAGS_ARB                  = 0x2094;
constexpr int ERROR_INVALID_VERSION_ARB              = 0x2095;

HGLRC wglCreateContextAttribsARB(HDC hDC, HGLRC hShareContext, const int* attribList);

#pragma endregion

#pragma region WGL_ARB_create_context_no_error

constexpr int WGL_CONTEXT_OPENGL_NO_ERROR_ARB = 0x31B3;

#pragma endregion

#pragma region WGL_ARB_create_context_profile

constexpr int WGL_CONTEXT_PROFILE_MASK_ARB              = 0x9126;
constexpr int WGL_CONTEXT_CORE_PROFILE_BIT_ARB          = 0x00000001;
constexpr int WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB = 0x00000002;
constexpr int ERROR_INVALID_PROFILE_ARB                 = 0x2096;

#pragma endregion

#pragma region WGL_ARB_create_context_robustness

constexpr int WGL_CONTEXT_ROBUST_ACCESS_BIT_ARB           = 0x00000004;
constexpr int WGL_LOSE_CONTEXT_ON_RESET_ARB               = 0x8252;
constexpr int WGL_CONTEXT_RESET_NOTIFICATION_STRATEGY_ARB = 0x8256;
constexpr int WGL_NO_RESET_NOTIFICATION_ARB               = 0x8261;

#pragma endregion

#pragma region WGL_ARB_extensions_string

const char* wglGetExtensionsStringARB(HDC hdc);

#pragma endregion

#pragma region WGL_ARB_framebuffer_sRGB

constexpr int WGL_FRAMEBUFFER_SRGB_CAPABLE_ARB = 0x20A9;

#pragma endregion

#pragma region WGL_ARB_make_current_read

constexpr int ERROR_INVALID_PIXEL_TYPE_ARB           = 0x2043;
constexpr int ERROR_INCOMPATIBLE_DEVICE_CONTEXTS_ARB = 0x2054;

BOOL wglMakeContextCurrentARB(HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
HDC wglGetCurrentReadDCARB();

#pragma endregion

#pragma region WGL_ARB_multisample

constexpr int WGL_SAMPLE_BUFFERS_ARB = 0x2041;
constexpr int WGL_SAMPLES_ARB        = 0x2042;

#pragma endregion

#pragma region WGL_ARB_pbuffer

DECLARE_HANDLE(HPBUFFERARB);

constexpr int WGL_DRAW_TO_PBUFFER_ARB    = 0x202D;
constexpr int WGL_MAX_PBUFFER_PIXELS_ARB = 0x202E;
constexpr int WGL_MAX_PBUFFER_WIDTH_ARB  = 0x202F;
constexpr int WGL_MAX_PBUFFER_HEIGHT_ARB = 0x2030;
constexpr int WGL_PBUFFER_LARGEST_ARB    = 0x2033;
constexpr int WGL_PBUFFER_WIDTH_ARB      = 0x2034;
constexpr int WGL_PBUFFER_HEIGHT_ARB     = 0x2035;
constexpr int WGL_PBUFFER_LOST_ARB       = 0x2036;

HPBUFFERARB wglCreatePbufferARB(HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int* piAttribList);
HDC wglGetPbufferDCARB(HPBUFFERARB hPbuffer);
int wglReleasePbufferDCARB(HPBUFFERARB hPbuffer, HDC hDC);
BOOL wglDestroyPbufferARB(HPBUFFERARB hPbuffer);
BOOL wglQueryPbufferARB(HPBUFFERARB hPbuffer, int iAttribute, int* piValue);

#pragma endregion

#pragma region WGL_ARB_pixel_format

constexpr int WGL_NUMBER_PIXEL_FORMATS_ARB    = 0x2000;
constexpr int WGL_DRAW_TO_WINDOW_ARB          = 0x2001;
constexpr int WGL_DRAW_TO_BITMAP_ARB          = 0x2002;
constexpr int WGL_ACCELERATION_ARB            = 0x2003;
constexpr int WGL_NEED_PALETTE_ARB            = 0x2004;
constexpr int WGL_NEED_SYSTEM_PALETTE_ARB     = 0x2005;
constexpr int WGL_SWAP_LAYER_BUFFERS_ARB      = 0x2006;
constexpr int WGL_SWAP_METHOD_ARB             = 0x2007;
constexpr int WGL_NUMBER_OVERLAYS_ARB         = 0x2008;
constexpr int WGL_NUMBER_UNDERLAYS_ARB        = 0x2009;
constexpr int WGL_TRANSPARENT_ARB             = 0x200A;
constexpr int WGL_TRANSPARENT_RED_VALUE_ARB   = 0x2037;
constexpr int WGL_TRANSPARENT_GREEN_VALUE_ARB = 0x2038;
constexpr int WGL_TRANSPARENT_BLUE_VALUE_ARB  = 0x2039;
constexpr int WGL_TRANSPARENT_ALPHA_VALUE_ARB = 0x203A;
constexpr int WGL_TRANSPARENT_INDEX_VALUE_ARB = 0x203B;
constexpr int WGL_SHARE_DEPTH_ARB             = 0x200C;
constexpr int WGL_SHARE_STENCIL_ARB           = 0x200D;
constexpr int WGL_SHARE_ACCUM_ARB             = 0x200E;
constexpr int WGL_SUPPORT_GDI_ARB             = 0x200F;
constexpr int WGL_SUPPORT_OPENGL_ARB          = 0x2010;
constexpr int WGL_DOUBLE_BUFFER_ARB           = 0x2011;
constexpr int WGL_STEREO_ARB                  = 0x2012;
constexpr int WGL_PIXEL_TYPE_ARB              = 0x2013;
constexpr int WGL_COLOR_BITS_ARB              = 0x2014;
constexpr int WGL_RED_BITS_ARB                = 0x2015;
constexpr int WGL_RED_SHIFT_ARB               = 0x2016;
constexpr int WGL_GREEN_BITS_ARB              = 0x2017;
constexpr int WGL_GREEN_SHIFT_ARB             = 0x2018;
constexpr int WGL_BLUE_BITS_ARB               = 0x2019;
constexpr int WGL_BLUE_SHIFT_ARB              = 0x201A;
constexpr int WGL_ALPHA_BITS_ARB              = 0x201B;
constexpr int WGL_ALPHA_SHIFT_ARB             = 0x201C;
constexpr int WGL_ACCUM_BITS_ARB              = 0x201D;
constexpr int WGL_ACCUM_RED_BITS_ARB          = 0x201E;
constexpr int WGL_ACCUM_GREEN_BITS_ARB        = 0x201F;
constexpr int WGL_ACCUM_BLUE_BITS_ARB         = 0x2020;
constexpr int WGL_ACCUM_ALPHA_BITS_ARB        = 0x2021;
constexpr int WGL_DEPTH_BITS_ARB              = 0x2022;
constexpr int WGL_STENCIL_BITS_ARB            = 0x2023;
constexpr int WGL_AUX_BUFFERS_ARB             = 0x2024;
constexpr int WGL_NO_ACCELERATION_ARB         = 0x2025;
constexpr int WGL_GENERIC_ACCELERATION_ARB    = 0x2026;
constexpr int WGL_FULL_ACCELERATION_ARB       = 0x2027;
constexpr int WGL_SWAP_EXCHANGE_ARB           = 0x2028;
constexpr int WGL_SWAP_COPY_ARB               = 0x2029;
constexpr int WGL_SWAP_UNDEFINED_ARB          = 0x202A;
constexpr int WGL_TYPE_RGBA_ARB               = 0x202B;
constexpr int WGL_TYPE_COLORINDEX_ARB         = 0x202C;

BOOL wglGetPixelFormatAttribivARB(HDC hdc,
                                  int iPixelFormat,
                                  int iLayerPlane,
                                  UINT nAttributes,
                                  const int* piAttributes,
                                  int* piValues);
BOOL wglGetPixelFormatAttribfvARB(HDC hdc,
                                  int iPixelFormat,
                                  int iLayerPlane,
                                  UINT nAttributes,
                                  const int* piAttributes,
                                  FLOAT* pfValues);
BOOL wglChoosePixelFormatARB(HDC hdc,
                             const int* piAttribIList,
                             const FLOAT* pfAttribFList,
                             UINT nMaxFormats,
                             int* piFormats,
                             UINT* nNumFormats);

#pragma endregion

#pragma region WGL_ARB_pixel_format_float

constexpr int WGL_TYPE_RGBA_FLOAT_ARB = 0x21A0;

#pragma endregion

#pragma region WGL_ARB_render_texture

constexpr int WGL_BIND_TO_TEXTURE_RGB_ARB         = 0x2070;
constexpr int WGL_BIND_TO_TEXTURE_RGBA_ARB        = 0x2071;
constexpr int WGL_TEXTURE_FORMAT_ARB              = 0x2072;
constexpr int WGL_TEXTURE_TARGET_ARB              = 0x2073;
constexpr int WGL_MIPMAP_TEXTURE_ARB              = 0x2074;
constexpr int WGL_TEXTURE_RGB_ARB                 = 0x2075;
constexpr int WGL_TEXTURE_RGBA_ARB                = 0x2076;
constexpr int WGL_NO_TEXTURE_ARB                  = 0x2077;
constexpr int WGL_TEXTURE_CUBE_MAP_ARB            = 0x2078;
constexpr int WGL_TEXTURE_1D_ARB                  = 0x2079;
constexpr int WGL_TEXTURE_2D_ARB                  = 0x207A;
constexpr int WGL_MIPMAP_LEVEL_ARB                = 0x207B;
constexpr int WGL_CUBE_MAP_FACE_ARB               = 0x207C;
constexpr int WGL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB = 0x207D;
constexpr int WGL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB = 0x207E;
constexpr int WGL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB = 0x207F;
constexpr int WGL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB = 0x2080;
constexpr int WGL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB = 0x2081;
constexpr int WGL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB = 0x2082;
constexpr int WGL_FRONT_LEFT_ARB                  = 0x2083;
constexpr int WGL_FRONT_RIGHT_ARB                 = 0x2084;
constexpr int WGL_BACK_LEFT_ARB                   = 0x2085;
constexpr int WGL_BACK_RIGHT_ARB                  = 0x2086;
constexpr int WGL_AUX0_ARB                        = 0x2087;
constexpr int WGL_AUX1_ARB                        = 0x2088;
constexpr int WGL_AUX2_ARB                        = 0x2089;
constexpr int WGL_AUX3_ARB                        = 0x208A;
constexpr int WGL_AUX4_ARB                        = 0x208B;
constexpr int WGL_AUX5_ARB                        = 0x208C;
constexpr int WGL_AUX6_ARB                        = 0x208D;
constexpr int WGL_AUX7_ARB                        = 0x208E;
constexpr int WGL_AUX8_ARB                        = 0x208F;
constexpr int WGL_AUX9_ARB                        = 0x2090;

BOOL wglBindTexImageARB(HPBUFFERARB hPbuffer, int iBuffer);
BOOL wglReleaseTexImageARB(HPBUFFERARB hPbuffer, int iBuffer);
BOOL wglSetPbufferAttribARB(HPBUFFERARB hPbuffer, const int* piAttribList);

#pragma endregion

#pragma region WGL_ARB_robustness_application_isolation

constexpr int WGL_CONTEXT_RESET_ISOLATION_BIT_ARB = 0x00000008;

#pragma endregion

#pragma region WGL_ARB_robustness_share_group_isolation

#pragma endregion

#pragma region WGL_ATI_pixel_format_float

constexpr int WGL_TYPE_RGBA_FLOAT_ATI = 0x21A0;

#pragma endregion

#pragma region WGL_ATI_render_texture_rectangle

constexpr int WGL_TEXTURE_RECTANGLE_ATI = 0x21A5;

#pragma endregion

#pragma region WGL_EXT_colorspace

constexpr int WGL_COLORSPACE_EXT        = 0x309D;
constexpr int WGL_COLORSPACE_SRGB_EXT   = 0x3089;
constexpr int WGL_COLORSPACE_LINEAR_EXT = 0x308A;

#pragma endregion

#pragma region WGL_EXT_create_context_es_profile

constexpr int WGL_CONTEXT_ES_PROFILE_BIT_EXT = 0x00000004;

#pragma endregion

#pragma region WGL_EXT_create_context_es2_profile

constexpr int WGL_CONTEXT_ES2_PROFILE_BIT_EXT = 0x00000004;

#pragma endregion

#pragma region WGL_EXT_depth_float

constexpr int WGL_DEPTH_FLOAT_EXT = 0x2040;

#pragma endregion

#pragma region WGL_EXT_display_color_table

GLboolean wglCreateDisplayColorTableEXT(GLushort id);
GLboolean wglLoadDisplayColorTableEXT(const GLushort* table, GLuint length);
GLboolean wglBindDisplayColorTableEXT(GLushort id);
VOID wglDestroyDisplayColorTableEXT(GLushort id);

#pragma endregion

#pragma region WGL_EXT_extensions_string

const char* wglGetExtensionsStringEXT();

#pragma endregion

#pragma region WGL_EXT_framebuffer_sRGB

constexpr int WGL_FRAMEBUFFER_SRGB_CAPABLE_EXT = 0x20A9;

#pragma endregion

#pragma region WGL_EXT_make_current_read

constexpr int ERROR_INVALID_PIXEL_TYPE_EXT = 0x2043;

BOOL wglMakeContextCurrentEXT(HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
HDC wglGetCurrentReadDCEXT();

#pragma endregion

#pragma region WGL_EXT_multisample

constexpr int WGL_SAMPLE_BUFFERS_EXT = 0x2041;
constexpr int WGL_SAMPLES_EXT        = 0x2042;

#pragma endregion

#pragma region WGL_EXT_pbuffer

DECLARE_HANDLE(HPBUFFEREXT);

constexpr int WGL_DRAW_TO_PBUFFER_EXT        = 0x202D;
constexpr int WGL_MAX_PBUFFER_PIXELS_EXT     = 0x202E;
constexpr int WGL_MAX_PBUFFER_WIDTH_EXT      = 0x202F;
constexpr int WGL_MAX_PBUFFER_HEIGHT_EXT     = 0x2030;
constexpr int WGL_OPTIMAL_PBUFFER_WIDTH_EXT  = 0x2031;
constexpr int WGL_OPTIMAL_PBUFFER_HEIGHT_EXT = 0x2032;
constexpr int WGL_PBUFFER_LARGEST_EXT        = 0x2033;
constexpr int WGL_PBUFFER_WIDTH_EXT          = 0x2034;
constexpr int WGL_PBUFFER_HEIGHT_EXT         = 0x2035;

HPBUFFEREXT wglCreatePbufferEXT(HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int* piAttribList);
HDC wglGetPbufferDCEXT(HPBUFFEREXT hPbuffer);
int wglReleasePbufferDCEXT(HPBUFFEREXT hPbuffer, HDC hDC);
BOOL wglDestroyPbufferEXT(HPBUFFEREXT hPbuffer);
BOOL wglQueryPbufferEXT(HPBUFFEREXT hPbuffer, int iAttribute, int* piValue);

#pragma endregion

#pragma region WGL_EXT_pixel_format

constexpr int WGL_NUMBER_PIXEL_FORMATS_EXT = 0x2000;
constexpr int WGL_DRAW_TO_WINDOW_EXT       = 0x2001;
constexpr int WGL_DRAW_TO_BITMAP_EXT       = 0x2002;
constexpr int WGL_ACCELERATION_EXT         = 0x2003;
constexpr int WGL_NEED_PALETTE_EXT         = 0x2004;
constexpr int WGL_NEED_SYSTEM_PALETTE_EXT  = 0x2005;
constexpr int WGL_SWAP_LAYER_BUFFERS_EXT   = 0x2006;
constexpr int WGL_SWAP_METHOD_EXT          = 0x2007;
constexpr int WGL_NUMBER_OVERLAYS_EXT      = 0x2008;
constexpr int WGL_NUMBER_UNDERLAYS_EXT     = 0x2009;
constexpr int WGL_TRANSPARENT_EXT          = 0x200A;
constexpr int WGL_TRANSPARENT_VALUE_EXT    = 0x200B;
constexpr int WGL_SHARE_DEPTH_EXT          = 0x200C;
constexpr int WGL_SHARE_STENCIL_EXT        = 0x200D;
constexpr int WGL_SHARE_ACCUM_EXT          = 0x200E;
constexpr int WGL_SUPPORT_GDI_EXT          = 0x200F;
constexpr int WGL_SUPPORT_OPENGL_EXT       = 0x2010;
constexpr int WGL_DOUBLE_BUFFER_EXT        = 0x2011;
constexpr int WGL_STEREO_EXT               = 0x2012;
constexpr int WGL_PIXEL_TYPE_EXT           = 0x2013;
constexpr int WGL_COLOR_BITS_EXT           = 0x2014;
constexpr int WGL_RED_BITS_EXT             = 0x2015;
constexpr int WGL_RED_SHIFT_EXT            = 0x2016;
constexpr int WGL_GREEN_BITS_EXT           = 0x2017;
constexpr int WGL_GREEN_SHIFT_EXT          = 0x2018;
constexpr int WGL_BLUE_BITS_EXT            = 0x2019;
constexpr int WGL_BLUE_SHIFT_EXT           = 0x201A;
constexpr int WGL_ALPHA_BITS_EXT           = 0x201B;
constexpr int WGL_ALPHA_SHIFT_EXT          = 0x201C;
constexpr int WGL_ACCUM_BITS_EXT           = 0x201D;
constexpr int WGL_ACCUM_RED_BITS_EXT       = 0x201E;
constexpr int WGL_ACCUM_GREEN_BITS_EXT     = 0x201F;
constexpr int WGL_ACCUM_BLUE_BITS_EXT      = 0x2020;
constexpr int WGL_ACCUM_ALPHA_BITS_EXT     = 0x2021;
constexpr int WGL_DEPTH_BITS_EXT           = 0x2022;
constexpr int WGL_STENCIL_BITS_EXT         = 0x2023;
constexpr int WGL_AUX_BUFFERS_EXT          = 0x2024;
constexpr int WGL_NO_ACCELERATION_EXT      = 0x2025;
constexpr int WGL_GENERIC_ACCELERATION_EXT = 0x2026;
constexpr int WGL_FULL_ACCELERATION_EXT    = 0x2027;
constexpr int WGL_SWAP_EXCHANGE_EXT        = 0x2028;
constexpr int WGL_SWAP_COPY_EXT            = 0x2029;
constexpr int WGL_SWAP_UNDEFINED_EXT       = 0x202A;
constexpr int WGL_TYPE_RGBA_EXT            = 0x202B;
constexpr int WGL_TYPE_COLORINDEX_EXT      = 0x202C;

BOOL wglGetPixelFormatAttribivEXT(HDC hdc,
                                  int iPixelFormat,
                                  int iLayerPlane,
                                  UINT nAttributes,
                                  int* piAttributes,
                                  int* piValues);
BOOL wglGetPixelFormatAttribfvEXT(HDC hdc,
                                  int iPixelFormat,
                                  int iLayerPlane,
                                  UINT nAttributes,
                                  int* piAttributes,
                                  FLOAT* pfValues);
BOOL wglChoosePixelFormatEXT(HDC hdc,
                             const int* piAttribIList,
                             const FLOAT* pfAttribFList,
                             UINT nMaxFormats,
                             int* piFormats,
                             UINT* nNumFormats);

#pragma endregion

#pragma region WGL_EXT_pixel_format_packed_float

constexpr int WGL_TYPE_RGBA_UNSIGNED_FLOAT_EXT = 0x20A8;

#pragma endregion

#pragma region WGL_EXT_swap_control

BOOL wglSwapIntervalEXT(int interval);
int wglGetSwapIntervalEXT();

#pragma endregion

#pragma region WGL_EXT_swap_control_tear

#pragma endregion

#pragma region WGL_I3D_digital_video_control

constexpr int WGL_DIGITAL_VIDEO_CURSOR_ALPHA_FRAMEBUFFER_I3D = 0x2050;
constexpr int WGL_DIGITAL_VIDEO_CURSOR_ALPHA_VALUE_I3D       = 0x2051;
constexpr int WGL_DIGITAL_VIDEO_CURSOR_INCLUDED_I3D          = 0x2052;
constexpr int WGL_DIGITAL_VIDEO_GAMMA_CORRECTED_I3D          = 0x2053;

BOOL wglGetDigitalVideoParametersI3D(HDC hDC, int iAttribute, int* piValue);
BOOL wglSetDigitalVideoParametersI3D(HDC hDC, int iAttribute, const int* piValue);

#pragma endregion

#pragma region WGL_I3D_gamma

constexpr int WGL_GAMMA_TABLE_SIZE_I3D      = 0x204E;
constexpr int WGL_GAMMA_EXCLUDE_DESKTOP_I3D = 0x204F;

BOOL wglGetGammaTableParametersI3D(HDC hDC, int iAttribute, int* piValue);
BOOL wglSetGammaTableParametersI3D(HDC hDC, int iAttribute, const int* piValue);
BOOL wglGetGammaTableI3D(HDC hDC, int iEntries, USHORT* puRed, USHORT* puGreen, USHORT* puBlue);
BOOL wglSetGammaTableI3D(HDC hDC, int iEntries, const USHORT* puRed, const USHORT* puGreen, const USHORT* puBlue);

#pragma endregion

#pragma region WGL_I3D_genlock

constexpr int WGL_GENLOCK_SOURCE_MULTIVIEW_I3D      = 0x2044;
constexpr int WGL_GENLOCK_SOURCE_EXTERNAL_SYNC_I3D  = 0x2045;
constexpr int WGL_GENLOCK_SOURCE_EXTERNAL_FIELD_I3D = 0x2046;
constexpr int WGL_GENLOCK_SOURCE_EXTERNAL_TTL_I3D   = 0x2047;
constexpr int WGL_GENLOCK_SOURCE_DIGITAL_SYNC_I3D   = 0x2048;
constexpr int WGL_GENLOCK_SOURCE_DIGITAL_FIELD_I3D  = 0x2049;
constexpr int WGL_GENLOCK_SOURCE_EDGE_FALLING_I3D   = 0x204A;
constexpr int WGL_GENLOCK_SOURCE_EDGE_RISING_I3D    = 0x204B;
constexpr int WGL_GENLOCK_SOURCE_EDGE_BOTH_I3D      = 0x204C;

BOOL wglEnableGenlockI3D(HDC hDC);
BOOL wglDisableGenlockI3D(HDC hDC);
BOOL wglIsEnabledGenlockI3D(HDC hDC, BOOL* pFlag);
BOOL wglGenlockSourceI3D(HDC hDC, UINT uSource);
BOOL wglGetGenlockSourceI3D(HDC hDC, UINT* uSource);
BOOL wglGenlockSourceEdgeI3D(HDC hDC, UINT uEdge);
BOOL wglGetGenlockSourceEdgeI3D(HDC hDC, UINT* uEdge);
BOOL wglGenlockSampleRateI3D(HDC hDC, UINT uRate);
BOOL wglGetGenlockSampleRateI3D(HDC hDC, UINT* uRate);
BOOL wglGenlockSourceDelayI3D(HDC hDC, UINT uDelay);
BOOL wglGetGenlockSourceDelayI3D(HDC hDC, UINT* uDelay);
BOOL wglQueryGenlockMaxSourceDelayI3D(HDC hDC, UINT* uMaxLineDelay, UINT* uMaxPixelDelay);

#pragma endregion

#pragma region WGL_I3D_image_buffer

constexpr int WGL_IMAGE_BUFFER_MIN_ACCESS_I3D = 0x00000001;
constexpr int WGL_IMAGE_BUFFER_LOCK_I3D       = 0x00000002;

LPVOID wglCreateImageBufferI3D(HDC hDC, DWORD dwSize, UINT uFlags);
BOOL wglDestroyImageBufferI3D(HDC hDC, LPVOID pAddress);
BOOL wglAssociateImageBufferEventsI3D(HDC hDC,
                                      const HANDLE* pEvent,
                                      const LPVOID* pAddress,
                                      const DWORD* pSize,
                                      UINT count);
BOOL wglReleaseImageBufferEventsI3D(HDC hDC, const LPVOID* pAddress, UINT count);

#pragma endregion

#pragma region WGL_I3D_swap_frame_lock

BOOL wglEnableFrameLockI3D();
BOOL wglDisableFrameLockI3D();
BOOL wglIsEnabledFrameLockI3D(BOOL* pFlag);
BOOL wglQueryFrameLockMasterI3D(BOOL* pFlag);

#pragma endregion

#pragma region WGL_I3D_swap_frame_usage

BOOL wglGetFrameUsageI3D(float* pUsage);
BOOL wglBeginFrameTrackingI3D();
BOOL wglEndFrameTrackingI3D();
BOOL wglQueryFrameTrackingI3D(DWORD* pFrameCount, DWORD* pMissedFrames, float* pLastMissedUsage);

#pragma endregion

#pragma region WGL_NV_copy_image

BOOL wglCopyImageSubDataNV(HGLRC hSrcRC,
                           GLuint srcName,
                           GLenum srcTarget,
                           GLint srcLevel,
                           GLint srcX,
                           GLint srcY,
                           GLint srcZ,
                           HGLRC hDstRC,
                           GLuint dstName,
                           GLenum dstTarget,
                           GLint dstLevel,
                           GLint dstX,
                           GLint dstY,
                           GLint dstZ,
                           GLsizei width,
                           GLsizei height,
                           GLsizei depth);

#pragma endregion

#pragma region WGL_NV_delay_before_swap

BOOL wglDelayBeforeSwapNV(HDC hDC, GLfloat seconds);

#pragma endregion

#pragma region WGL_NV_DX_interop

constexpr int WGL_ACCESS_READ_ONLY_NV     = 0x00000000;
constexpr int WGL_ACCESS_READ_WRITE_NV    = 0x00000001;
constexpr int WGL_ACCESS_WRITE_DISCARD_NV = 0x00000002;

BOOL wglDXSetResourceShareHandleNV(void* dxObject, HANDLE shareHandle);
HANDLE wglDXOpenDeviceNV(void* dxDevice);
BOOL wglDXCloseDeviceNV(HANDLE hDevice);
HANDLE wglDXRegisterObjectNV(HANDLE hDevice, void* dxObject, GLuint name, GLenum type, GLenum access);
BOOL wglDXUnregisterObjectNV(HANDLE hDevice, HANDLE hObject);
BOOL wglDXObjectAccessNV(HANDLE hObject, GLenum access);
BOOL wglDXLockObjectsNV(HANDLE hDevice, GLint count, HANDLE* hObjects);
BOOL wglDXUnlockObjectsNV(HANDLE hDevice, GLint count, HANDLE* hObjects);

#pragma endregion

#pragma region WGL_NV_DX_interop2

#pragma endregion

#pragma region WGL_NV_float_buffer

constexpr int WGL_FLOAT_COMPONENTS_NV                     = 0x20B0;
constexpr int WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_R_NV    = 0x20B1;
constexpr int WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RG_NV   = 0x20B2;
constexpr int WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RGB_NV  = 0x20B3;
constexpr int WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RGBA_NV = 0x20B4;
constexpr int WGL_TEXTURE_FLOAT_R_NV                      = 0x20B5;
constexpr int WGL_TEXTURE_FLOAT_RG_NV                     = 0x20B6;
constexpr int WGL_TEXTURE_FLOAT_RGB_NV                    = 0x20B7;
constexpr int WGL_TEXTURE_FLOAT_RGBA_NV                   = 0x20B8;

#pragma endregion

#pragma region WGL_NV_gpu_affinity

struct _GPU_DEVICE
{
    DWORD cb;
    CHAR DeviceName[32];
    CHAR DeviceString[128];
    DWORD Flags;
    RECT rcVirtualScreen;
};
DECLARE_HANDLE(HGPUNV);
typedef struct _GPU_DEVICE* PGPU_DEVICE;

constexpr int ERROR_INCOMPATIBLE_AFFINITY_MASKS_NV = 0x20D0;
constexpr int ERROR_MISSING_AFFINITY_MASK_NV       = 0x20D1;

BOOL wglEnumGpusNV(UINT iGpuIndex, HGPUNV* phGpu);
BOOL wglEnumGpuDevicesNV(HGPUNV hGpu, UINT iDeviceIndex, PGPU_DEVICE lpGpuDevice);
HDC wglCreateAffinityDCNV(const HGPUNV* phGpuList);
BOOL wglEnumGpusFromAffinityDCNV(HDC hAffinityDC, UINT iGpuIndex, HGPUNV* hGpu);
BOOL wglDeleteDCNV(HDC hdc);

#pragma endregion

#pragma region WGL_NV_multisample_coverage

constexpr int WGL_COVERAGE_SAMPLES_NV = 0x2042;
constexpr int WGL_COLOR_SAMPLES_NV    = 0x20B9;

#pragma endregion

#pragma region WGL_NV_present_video

DECLARE_HANDLE(HVIDEOOUTPUTDEVICENV);

constexpr int WGL_NUM_VIDEO_SLOTS_NV = 0x20F0;

int wglEnumerateVideoDevicesNV(HDC hDc, HVIDEOOUTPUTDEVICENV* phDeviceList);
BOOL wglBindVideoDeviceNV(HDC hDc, unsigned int uVideoSlot, HVIDEOOUTPUTDEVICENV hVideoDevice, const int* piAttribList);
BOOL wglQueryCurrentContextNV(int iAttribute, int* piValue);

#pragma endregion

#pragma region WGL_NV_render_depth_texture

constexpr int WGL_BIND_TO_TEXTURE_DEPTH_NV           = 0x20A3;
constexpr int WGL_BIND_TO_TEXTURE_RECTANGLE_DEPTH_NV = 0x20A4;
constexpr int WGL_DEPTH_TEXTURE_FORMAT_NV            = 0x20A5;
constexpr int WGL_TEXTURE_DEPTH_COMPONENT_NV         = 0x20A6;
constexpr int WGL_DEPTH_COMPONENT_NV                 = 0x20A7;

#pragma endregion

#pragma region WGL_NV_render_texture_rectangle

constexpr int WGL_BIND_TO_TEXTURE_RECTANGLE_RGB_NV  = 0x20A0;
constexpr int WGL_BIND_TO_TEXTURE_RECTANGLE_RGBA_NV = 0x20A1;
constexpr int WGL_TEXTURE_RECTANGLE_NV              = 0x20A2;

#pragma endregion

#pragma region WGL_NV_swap_group

BOOL wglJoinSwapGroupNV(HDC hDC, GLuint group);
BOOL wglBindSwapBarrierNV(GLuint group, GLuint barrier);
BOOL wglQuerySwapGroupNV(HDC hDC, GLuint* group, GLuint* barrier);
BOOL wglQueryMaxSwapGroupsNV(HDC hDC, GLuint* maxGroups, GLuint* maxBarriers);
BOOL wglQueryFrameCountNV(HDC hDC, GLuint* count);
BOOL wglResetFrameCountNV(HDC hDC);

#pragma endregion

#pragma region WGL_NV_video_capture

DECLARE_HANDLE(HVIDEOINPUTDEVICENV);

constexpr int WGL_UNIQUE_ID_NV               = 0x20CE;
constexpr int WGL_NUM_VIDEO_CAPTURE_SLOTS_NV = 0x20CF;

BOOL wglBindVideoCaptureDeviceNV(UINT uVideoSlot, HVIDEOINPUTDEVICENV hDevice);
UINT wglEnumerateVideoCaptureDevicesNV(HDC hDc, HVIDEOINPUTDEVICENV* phDeviceList);
BOOL wglLockVideoCaptureDeviceNV(HDC hDc, HVIDEOINPUTDEVICENV hDevice);
BOOL wglQueryVideoCaptureDeviceNV(HDC hDc, HVIDEOINPUTDEVICENV hDevice, int iAttribute, int* piValue);
BOOL wglReleaseVideoCaptureDeviceNV(HDC hDc, HVIDEOINPUTDEVICENV hDevice);

#pragma endregion

#pragma region WGL_NV_video_output

DECLARE_HANDLE(HPVIDEODEV);

constexpr int WGL_BIND_TO_VIDEO_RGB_NV           = 0x20C0;
constexpr int WGL_BIND_TO_VIDEO_RGBA_NV          = 0x20C1;
constexpr int WGL_BIND_TO_VIDEO_RGB_AND_DEPTH_NV = 0x20C2;
constexpr int WGL_VIDEO_OUT_COLOR_NV             = 0x20C3;
constexpr int WGL_VIDEO_OUT_ALPHA_NV             = 0x20C4;
constexpr int WGL_VIDEO_OUT_DEPTH_NV             = 0x20C5;
constexpr int WGL_VIDEO_OUT_COLOR_AND_ALPHA_NV   = 0x20C6;
constexpr int WGL_VIDEO_OUT_COLOR_AND_DEPTH_NV   = 0x20C7;
constexpr int WGL_VIDEO_OUT_FRAME                = 0x20C8;
constexpr int WGL_VIDEO_OUT_FIELD_1              = 0x20C9;
constexpr int WGL_VIDEO_OUT_FIELD_2              = 0x20CA;
constexpr int WGL_VIDEO_OUT_STACKED_FIELDS_1_2   = 0x20CB;
constexpr int WGL_VIDEO_OUT_STACKED_FIELDS_2_1   = 0x20CC;

BOOL wglGetVideoDeviceNV(HDC hDC, int numDevices, HPVIDEODEV* hVideoDevice);
BOOL wglReleaseVideoDeviceNV(HPVIDEODEV hVideoDevice);
BOOL wglBindVideoImageNV(HPVIDEODEV hVideoDevice, HPBUFFERARB hPbuffer, int iVideoBuffer);
BOOL wglReleaseVideoImageNV(HPBUFFERARB hPbuffer, int iVideoBuffer);
BOOL wglSendPbufferToVideoNV(HPBUFFERARB hPbuffer, int iBufferType, unsigned long* pulCounterPbuffer, BOOL bBlock);
BOOL wglGetVideoInfoNV(HPVIDEODEV hpVideoDevice,
                       unsigned long* pulCounterOutputPbuffer,
                       unsigned long* pulCounterOutputVideo);

#pragma endregion

#pragma region WGL_NV_vertex_array_range

void* wglAllocateMemoryNV(GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority);
void wglFreeMemoryNV(void* pointer);

#pragma endregion

#pragma region WGL_OML_sync_control

BOOL wglGetSyncValuesOML(HDC hdc, INT64* ust, INT64* msc, INT64* sbc);
BOOL wglGetMscRateOML(HDC hdc, INT32* numerator, INT32* denominator);
INT64 wglSwapBuffersMscOML(HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder);
INT64 wglSwapLayerBuffersMscOML(HDC hdc, INT fuPlanes, INT64 target_msc, INT64 divisor, INT64 remainder);
BOOL wglWaitForMscOML(HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder, INT64* ust, INT64* msc, INT64* sbc);
BOOL wglWaitForSbcOML(HDC hdc, INT64 target_sbc, INT64* ust, INT64* msc, INT64* sbc);

#pragma endregion

#pragma region WGL_NV_multigpu_context

constexpr int WGL_CONTEXT_MULTIGPU_ATTRIB_NV                         = 0x20AA;
constexpr int WGL_CONTEXT_MULTIGPU_ATTRIB_SINGLE_NV                  = 0x20AB;
constexpr int WGL_CONTEXT_MULTIGPU_ATTRIB_AFR_NV                     = 0x20AC;
constexpr int WGL_CONTEXT_MULTIGPU_ATTRIB_MULTICAST_NV               = 0x20AD;
constexpr int WGL_CONTEXT_MULTIGPU_ATTRIB_MULTI_DISPLAY_MULTICAST_NV = 0x20AE;

#pragma endregion

enum class Feature
{

};

enum class Extension
{
    WGL_3DFX_multisample,
    WGL_3DL_stereo_control,
    WGL_AMD_gpu_association,
    WGL_ARB_buffer_region,
    WGL_ARB_context_flush_control,
    WGL_ARB_create_context,
    WGL_ARB_create_context_no_error,
    WGL_ARB_create_context_profile,
    WGL_ARB_create_context_robustness,
    WGL_ARB_extensions_string,
    WGL_ARB_framebuffer_sRGB,
    WGL_ARB_make_current_read,
    WGL_ARB_multisample,
    WGL_ARB_pbuffer,
    WGL_ARB_pixel_format,
    WGL_ARB_pixel_format_float,
    WGL_ARB_render_texture,
    WGL_ARB_robustness_application_isolation,
    WGL_ARB_robustness_share_group_isolation,
    WGL_ATI_pixel_format_float,
    WGL_ATI_render_texture_rectangle,
    WGL_EXT_colorspace,
    WGL_EXT_create_context_es_profile,
    WGL_EXT_create_context_es2_profile,
    WGL_EXT_depth_float,
    WGL_EXT_display_color_table,
    WGL_EXT_extensions_string,
    WGL_EXT_framebuffer_sRGB,
    WGL_EXT_make_current_read,
    WGL_EXT_multisample,
    WGL_EXT_pbuffer,
    WGL_EXT_pixel_format,
    WGL_EXT_pixel_format_packed_float,
    WGL_EXT_swap_control,
    WGL_EXT_swap_control_tear,
    WGL_I3D_digital_video_control,
    WGL_I3D_gamma,
    WGL_I3D_genlock,
    WGL_I3D_image_buffer,
    WGL_I3D_swap_frame_lock,
    WGL_I3D_swap_frame_usage,
    WGL_NV_copy_image,
    WGL_NV_delay_before_swap,
    WGL_NV_DX_interop,
    WGL_NV_DX_interop2,
    WGL_NV_float_buffer,
    WGL_NV_gpu_affinity,
    WGL_NV_multisample_coverage,
    WGL_NV_present_video,
    WGL_NV_render_depth_texture,
    WGL_NV_render_texture_rectangle,
    WGL_NV_swap_group,
    WGL_NV_video_capture,
    WGL_NV_video_output,
    WGL_NV_vertex_array_range,
    WGL_OML_sync_control,
    WGL_NV_multigpu_context,
};

using VoidFunctionPtr = void (*)();
using GetFunction     = std::function<VoidFunctionPtr(const char*)>;

void init_wgl(const GetFunction& get_function);

bool is_supported(Feature feature);
bool is_supported(Extension extension);

} // namespace framework::system::details::wgl

#endif
