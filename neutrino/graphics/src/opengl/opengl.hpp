/// @file
/// @brief OpneGL functions wrapper.
/// @author Fedorov Alexey
/// @date 17.09.2018

// =============================================================================
// MIT License
//
// Copyright (c) 2017-2019 Fedorov Alexey
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

#ifndef FRAMEWORK_GRAPHICS_SRC_OPENGL_OPENGL_HPP
#define FRAMEWORK_GRAPHICS_SRC_OPENGL_OPENGL_HPP

#include <KHR/khrplatform.h>
#include <functional>

namespace framework::graphics::details::opengl
{
#pragma region GL_VERSION_1_0

typedef void GLvoid;
typedef unsigned int GLenum;
typedef khronos_float_t GLfloat;
typedef int GLint;
typedef int GLsizei;
typedef unsigned int GLbitfield;
typedef double GLdouble;
typedef unsigned int GLuint;
typedef unsigned char GLboolean;
typedef khronos_uint8_t GLubyte;

constexpr int GL_DEPTH_BUFFER_BIT        = 0x00000100;
constexpr int GL_STENCIL_BUFFER_BIT      = 0x00000400;
constexpr int GL_COLOR_BUFFER_BIT        = 0x00004000;
constexpr int GL_FALSE                   = 0;
constexpr int GL_TRUE                    = 1;
constexpr int GL_POINTS                  = 0x0000;
constexpr int GL_LINES                   = 0x0001;
constexpr int GL_LINE_LOOP               = 0x0002;
constexpr int GL_LINE_STRIP              = 0x0003;
constexpr int GL_TRIANGLES               = 0x0004;
constexpr int GL_TRIANGLE_STRIP          = 0x0005;
constexpr int GL_TRIANGLE_FAN            = 0x0006;
constexpr int GL_NEVER                   = 0x0200;
constexpr int GL_LESS                    = 0x0201;
constexpr int GL_EQUAL                   = 0x0202;
constexpr int GL_LEQUAL                  = 0x0203;
constexpr int GL_GREATER                 = 0x0204;
constexpr int GL_NOTEQUAL                = 0x0205;
constexpr int GL_GEQUAL                  = 0x0206;
constexpr int GL_ALWAYS                  = 0x0207;
constexpr int GL_ZERO                    = 0;
constexpr int GL_ONE                     = 1;
constexpr int GL_SRC_COLOR               = 0x0300;
constexpr int GL_ONE_MINUS_SRC_COLOR     = 0x0301;
constexpr int GL_SRC_ALPHA               = 0x0302;
constexpr int GL_ONE_MINUS_SRC_ALPHA     = 0x0303;
constexpr int GL_DST_ALPHA               = 0x0304;
constexpr int GL_ONE_MINUS_DST_ALPHA     = 0x0305;
constexpr int GL_DST_COLOR               = 0x0306;
constexpr int GL_ONE_MINUS_DST_COLOR     = 0x0307;
constexpr int GL_SRC_ALPHA_SATURATE      = 0x0308;
constexpr int GL_NONE                    = 0;
constexpr int GL_FRONT_LEFT              = 0x0400;
constexpr int GL_FRONT_RIGHT             = 0x0401;
constexpr int GL_BACK_LEFT               = 0x0402;
constexpr int GL_BACK_RIGHT              = 0x0403;
constexpr int GL_FRONT                   = 0x0404;
constexpr int GL_BACK                    = 0x0405;
constexpr int GL_LEFT                    = 0x0406;
constexpr int GL_RIGHT                   = 0x0407;
constexpr int GL_FRONT_AND_BACK          = 0x0408;
constexpr int GL_NO_ERROR                = 0;
constexpr int GL_INVALID_ENUM            = 0x0500;
constexpr int GL_INVALID_VALUE           = 0x0501;
constexpr int GL_INVALID_OPERATION       = 0x0502;
constexpr int GL_OUT_OF_MEMORY           = 0x0505;
constexpr int GL_CW                      = 0x0900;
constexpr int GL_CCW                     = 0x0901;
constexpr int GL_POINT_SIZE              = 0x0B11;
constexpr int GL_POINT_SIZE_RANGE        = 0x0B12;
constexpr int GL_POINT_SIZE_GRANULARITY  = 0x0B13;
constexpr int GL_LINE_SMOOTH             = 0x0B20;
constexpr int GL_LINE_WIDTH              = 0x0B21;
constexpr int GL_LINE_WIDTH_RANGE        = 0x0B22;
constexpr int GL_LINE_WIDTH_GRANULARITY  = 0x0B23;
constexpr int GL_POLYGON_MODE            = 0x0B40;
constexpr int GL_POLYGON_SMOOTH          = 0x0B41;
constexpr int GL_CULL_FACE               = 0x0B44;
constexpr int GL_CULL_FACE_MODE          = 0x0B45;
constexpr int GL_FRONT_FACE              = 0x0B46;
constexpr int GL_DEPTH_RANGE             = 0x0B70;
constexpr int GL_DEPTH_TEST              = 0x0B71;
constexpr int GL_DEPTH_WRITEMASK         = 0x0B72;
constexpr int GL_DEPTH_CLEAR_VALUE       = 0x0B73;
constexpr int GL_DEPTH_FUNC              = 0x0B74;
constexpr int GL_STENCIL_TEST            = 0x0B90;
constexpr int GL_STENCIL_CLEAR_VALUE     = 0x0B91;
constexpr int GL_STENCIL_FUNC            = 0x0B92;
constexpr int GL_STENCIL_VALUE_MASK      = 0x0B93;
constexpr int GL_STENCIL_FAIL            = 0x0B94;
constexpr int GL_STENCIL_PASS_DEPTH_FAIL = 0x0B95;
constexpr int GL_STENCIL_PASS_DEPTH_PASS = 0x0B96;
constexpr int GL_STENCIL_REF             = 0x0B97;
constexpr int GL_STENCIL_WRITEMASK       = 0x0B98;
constexpr int GL_VIEWPORT                = 0x0BA2;
constexpr int GL_DITHER                  = 0x0BD0;
constexpr int GL_BLEND_DST               = 0x0BE0;
constexpr int GL_BLEND_SRC               = 0x0BE1;
constexpr int GL_BLEND                   = 0x0BE2;
constexpr int GL_LOGIC_OP_MODE           = 0x0BF0;
constexpr int GL_DRAW_BUFFER             = 0x0C01;
constexpr int GL_READ_BUFFER             = 0x0C02;
constexpr int GL_SCISSOR_BOX             = 0x0C10;
constexpr int GL_SCISSOR_TEST            = 0x0C11;
constexpr int GL_COLOR_CLEAR_VALUE       = 0x0C22;
constexpr int GL_COLOR_WRITEMASK         = 0x0C23;
constexpr int GL_DOUBLEBUFFER            = 0x0C32;
constexpr int GL_STEREO                  = 0x0C33;
constexpr int GL_LINE_SMOOTH_HINT        = 0x0C52;
constexpr int GL_POLYGON_SMOOTH_HINT     = 0x0C53;
constexpr int GL_UNPACK_SWAP_BYTES       = 0x0CF0;
constexpr int GL_UNPACK_LSB_FIRST        = 0x0CF1;
constexpr int GL_UNPACK_ROW_LENGTH       = 0x0CF2;
constexpr int GL_UNPACK_SKIP_ROWS        = 0x0CF3;
constexpr int GL_UNPACK_SKIP_PIXELS      = 0x0CF4;
constexpr int GL_UNPACK_ALIGNMENT        = 0x0CF5;
constexpr int GL_PACK_SWAP_BYTES         = 0x0D00;
constexpr int GL_PACK_LSB_FIRST          = 0x0D01;
constexpr int GL_PACK_ROW_LENGTH         = 0x0D02;
constexpr int GL_PACK_SKIP_ROWS          = 0x0D03;
constexpr int GL_PACK_SKIP_PIXELS        = 0x0D04;
constexpr int GL_PACK_ALIGNMENT          = 0x0D05;
constexpr int GL_MAX_TEXTURE_SIZE        = 0x0D33;
constexpr int GL_MAX_VIEWPORT_DIMS       = 0x0D3A;
constexpr int GL_SUBPIXEL_BITS           = 0x0D50;
constexpr int GL_TEXTURE_1D              = 0x0DE0;
constexpr int GL_TEXTURE_2D              = 0x0DE1;
constexpr int GL_TEXTURE_WIDTH           = 0x1000;
constexpr int GL_TEXTURE_HEIGHT          = 0x1001;
constexpr int GL_TEXTURE_BORDER_COLOR    = 0x1004;
constexpr int GL_DONT_CARE               = 0x1100;
constexpr int GL_FASTEST                 = 0x1101;
constexpr int GL_NICEST                  = 0x1102;
constexpr int GL_BYTE                    = 0x1400;
constexpr int GL_UNSIGNED_BYTE           = 0x1401;
constexpr int GL_SHORT                   = 0x1402;
constexpr int GL_UNSIGNED_SHORT          = 0x1403;
constexpr int GL_INT                     = 0x1404;
constexpr int GL_UNSIGNED_INT            = 0x1405;
constexpr int GL_FLOAT                   = 0x1406;
constexpr int GL_CLEAR                   = 0x1500;
constexpr int GL_AND                     = 0x1501;
constexpr int GL_AND_REVERSE             = 0x1502;
constexpr int GL_COPY                    = 0x1503;
constexpr int GL_AND_INVERTED            = 0x1504;
constexpr int GL_NOOP                    = 0x1505;
constexpr int GL_XOR                     = 0x1506;
constexpr int GL_OR                      = 0x1507;
constexpr int GL_NOR                     = 0x1508;
constexpr int GL_EQUIV                   = 0x1509;
constexpr int GL_INVERT                  = 0x150A;
constexpr int GL_OR_REVERSE              = 0x150B;
constexpr int GL_COPY_INVERTED           = 0x150C;
constexpr int GL_OR_INVERTED             = 0x150D;
constexpr int GL_NAND                    = 0x150E;
constexpr int GL_SET                     = 0x150F;
constexpr int GL_TEXTURE                 = 0x1702;
constexpr int GL_COLOR                   = 0x1800;
constexpr int GL_DEPTH                   = 0x1801;
constexpr int GL_STENCIL                 = 0x1802;
constexpr int GL_STENCIL_INDEX           = 0x1901;
constexpr int GL_DEPTH_COMPONENT         = 0x1902;
constexpr int GL_RED                     = 0x1903;
constexpr int GL_GREEN                   = 0x1904;
constexpr int GL_BLUE                    = 0x1905;
constexpr int GL_ALPHA                   = 0x1906;
constexpr int GL_RGB                     = 0x1907;
constexpr int GL_RGBA                    = 0x1908;
constexpr int GL_POINT                   = 0x1B00;
constexpr int GL_LINE                    = 0x1B01;
constexpr int GL_FILL                    = 0x1B02;
constexpr int GL_KEEP                    = 0x1E00;
constexpr int GL_REPLACE                 = 0x1E01;
constexpr int GL_INCR                    = 0x1E02;
constexpr int GL_DECR                    = 0x1E03;
constexpr int GL_VENDOR                  = 0x1F00;
constexpr int GL_RENDERER                = 0x1F01;
constexpr int GL_VERSION                 = 0x1F02;
constexpr int GL_EXTENSIONS              = 0x1F03;
constexpr int GL_NEAREST                 = 0x2600;
constexpr int GL_LINEAR                  = 0x2601;
constexpr int GL_NEAREST_MIPMAP_NEAREST  = 0x2700;
constexpr int GL_LINEAR_MIPMAP_NEAREST   = 0x2701;
constexpr int GL_NEAREST_MIPMAP_LINEAR   = 0x2702;
constexpr int GL_LINEAR_MIPMAP_LINEAR    = 0x2703;
constexpr int GL_TEXTURE_MAG_FILTER      = 0x2800;
constexpr int GL_TEXTURE_MIN_FILTER      = 0x2801;
constexpr int GL_TEXTURE_WRAP_S          = 0x2802;
constexpr int GL_TEXTURE_WRAP_T          = 0x2803;
constexpr int GL_REPEAT                  = 0x2901;

void glCullFace(GLenum mode);
void glFrontFace(GLenum mode);
void glHint(GLenum target, GLenum mode);
void glLineWidth(GLfloat width);
void glPointSize(GLfloat size);
void glPolygonMode(GLenum face, GLenum mode);
void glScissor(GLint x, GLint y, GLsizei width, GLsizei height);
void glTexParameterf(GLenum target, GLenum pname, GLfloat param);
void glTexParameterfv(GLenum target, GLenum pname, const GLfloat* params);
void glTexParameteri(GLenum target, GLenum pname, GLint param);
void glTexParameteriv(GLenum target, GLenum pname, const GLint* params);
void glTexImage1D(GLenum target,
                  GLint level,
                  GLint internalformat,
                  GLsizei width,
                  GLint border,
                  GLenum format,
                  GLenum type,
                  const void* pixels);
void glTexImage2D(GLenum target,
                  GLint level,
                  GLint internalformat,
                  GLsizei width,
                  GLsizei height,
                  GLint border,
                  GLenum format,
                  GLenum type,
                  const void* pixels);
void glDrawBuffer(GLenum buf);
void glClear(GLbitfield mask);
void glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void glClearStencil(GLint s);
void glClearDepth(GLdouble depth);
void glStencilMask(GLuint mask);
void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
void glDepthMask(GLboolean flag);
void glDisable(GLenum cap);
void glEnable(GLenum cap);
void glFinish();
void glFlush();
void glBlendFunc(GLenum sfactor, GLenum dfactor);
void glLogicOp(GLenum opcode);
void glStencilFunc(GLenum func, GLint ref, GLuint mask);
void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass);
void glDepthFunc(GLenum func);
void glPixelStoref(GLenum pname, GLfloat param);
void glPixelStorei(GLenum pname, GLint param);
void glReadBuffer(GLenum src);
void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void* pixels);
void glGetBooleanv(GLenum pname, GLboolean* data);
void glGetDoublev(GLenum pname, GLdouble* data);
GLenum glGetError();
void glGetFloatv(GLenum pname, GLfloat* data);
void glGetIntegerv(GLenum pname, GLint* data);
const GLubyte* glGetString(GLenum name);
void glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, void* pixels);
void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat* params);
void glGetTexParameteriv(GLenum target, GLenum pname, GLint* params);
void glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat* params);
void glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint* params);
GLboolean glIsEnabled(GLenum cap);
void glDepthRange(GLdouble n, GLdouble f);
void glViewport(GLint x, GLint y, GLsizei width, GLsizei height);

#pragma endregion

#pragma region GL_VERSION_1_1

typedef khronos_float_t GLclampf;
typedef double GLclampd;

constexpr int GL_COLOR_LOGIC_OP          = 0x0BF2;
constexpr int GL_POLYGON_OFFSET_UNITS    = 0x2A00;
constexpr int GL_POLYGON_OFFSET_POINT    = 0x2A01;
constexpr int GL_POLYGON_OFFSET_LINE     = 0x2A02;
constexpr int GL_POLYGON_OFFSET_FILL     = 0x8037;
constexpr int GL_POLYGON_OFFSET_FACTOR   = 0x8038;
constexpr int GL_TEXTURE_BINDING_1D      = 0x8068;
constexpr int GL_TEXTURE_BINDING_2D      = 0x8069;
constexpr int GL_TEXTURE_INTERNAL_FORMAT = 0x1003;
constexpr int GL_TEXTURE_RED_SIZE        = 0x805C;
constexpr int GL_TEXTURE_GREEN_SIZE      = 0x805D;
constexpr int GL_TEXTURE_BLUE_SIZE       = 0x805E;
constexpr int GL_TEXTURE_ALPHA_SIZE      = 0x805F;
constexpr int GL_DOUBLE                  = 0x140A;
constexpr int GL_PROXY_TEXTURE_1D        = 0x8063;
constexpr int GL_PROXY_TEXTURE_2D        = 0x8064;
constexpr int GL_R3_G3_B2                = 0x2A10;
constexpr int GL_RGB4                    = 0x804F;
constexpr int GL_RGB5                    = 0x8050;
constexpr int GL_RGB8                    = 0x8051;
constexpr int GL_RGB10                   = 0x8052;
constexpr int GL_RGB12                   = 0x8053;
constexpr int GL_RGB16                   = 0x8054;
constexpr int GL_RGBA2                   = 0x8055;
constexpr int GL_RGBA4                   = 0x8056;
constexpr int GL_RGB5_A1                 = 0x8057;
constexpr int GL_RGBA8                   = 0x8058;
constexpr int GL_RGB10_A2                = 0x8059;
constexpr int GL_RGBA12                  = 0x805A;
constexpr int GL_RGBA16                  = 0x805B;

void glDrawArrays(GLenum mode, GLint first, GLsizei count);
void glDrawElements(GLenum mode, GLsizei count, GLenum type, const void* indices);
void glPolygonOffset(GLfloat factor, GLfloat units);
void glCopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
void glCopyTexImage2D(GLenum target,
                      GLint level,
                      GLenum internalformat,
                      GLint x,
                      GLint y,
                      GLsizei width,
                      GLsizei height,
                      GLint border);
void glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
void glCopyTexSubImage2D(GLenum target,
                         GLint level,
                         GLint xoffset,
                         GLint yoffset,
                         GLint x,
                         GLint y,
                         GLsizei width,
                         GLsizei height);
void glTexSubImage1D(GLenum target,
                     GLint level,
                     GLint xoffset,
                     GLsizei width,
                     GLenum format,
                     GLenum type,
                     const void* pixels);
void glTexSubImage2D(GLenum target,
                     GLint level,
                     GLint xoffset,
                     GLint yoffset,
                     GLsizei width,
                     GLsizei height,
                     GLenum format,
                     GLenum type,
                     const void* pixels);
void glBindTexture(GLenum target, GLuint texture);
void glDeleteTextures(GLsizei n, const GLuint* textures);
void glGenTextures(GLsizei n, GLuint* textures);
GLboolean glIsTexture(GLuint texture);

#pragma endregion

#pragma region GL_VERSION_1_2

constexpr int GL_UNSIGNED_BYTE_3_3_2           = 0x8032;
constexpr int GL_UNSIGNED_SHORT_4_4_4_4        = 0x8033;
constexpr int GL_UNSIGNED_SHORT_5_5_5_1        = 0x8034;
constexpr int GL_UNSIGNED_INT_8_8_8_8          = 0x8035;
constexpr int GL_UNSIGNED_INT_10_10_10_2       = 0x8036;
constexpr int GL_TEXTURE_BINDING_3D            = 0x806A;
constexpr int GL_PACK_SKIP_IMAGES              = 0x806B;
constexpr int GL_PACK_IMAGE_HEIGHT             = 0x806C;
constexpr int GL_UNPACK_SKIP_IMAGES            = 0x806D;
constexpr int GL_UNPACK_IMAGE_HEIGHT           = 0x806E;
constexpr int GL_TEXTURE_3D                    = 0x806F;
constexpr int GL_PROXY_TEXTURE_3D              = 0x8070;
constexpr int GL_TEXTURE_DEPTH                 = 0x8071;
constexpr int GL_TEXTURE_WRAP_R                = 0x8072;
constexpr int GL_MAX_3D_TEXTURE_SIZE           = 0x8073;
constexpr int GL_UNSIGNED_BYTE_2_3_3_REV       = 0x8362;
constexpr int GL_UNSIGNED_SHORT_5_6_5          = 0x8363;
constexpr int GL_UNSIGNED_SHORT_5_6_5_REV      = 0x8364;
constexpr int GL_UNSIGNED_SHORT_4_4_4_4_REV    = 0x8365;
constexpr int GL_UNSIGNED_SHORT_1_5_5_5_REV    = 0x8366;
constexpr int GL_UNSIGNED_INT_8_8_8_8_REV      = 0x8367;
constexpr int GL_UNSIGNED_INT_2_10_10_10_REV   = 0x8368;
constexpr int GL_BGR                           = 0x80E0;
constexpr int GL_BGRA                          = 0x80E1;
constexpr int GL_MAX_ELEMENTS_VERTICES         = 0x80E8;
constexpr int GL_MAX_ELEMENTS_INDICES          = 0x80E9;
constexpr int GL_CLAMP_TO_EDGE                 = 0x812F;
constexpr int GL_TEXTURE_MIN_LOD               = 0x813A;
constexpr int GL_TEXTURE_MAX_LOD               = 0x813B;
constexpr int GL_TEXTURE_BASE_LEVEL            = 0x813C;
constexpr int GL_TEXTURE_MAX_LEVEL             = 0x813D;
constexpr int GL_SMOOTH_POINT_SIZE_RANGE       = 0x0B12;
constexpr int GL_SMOOTH_POINT_SIZE_GRANULARITY = 0x0B13;
constexpr int GL_SMOOTH_LINE_WIDTH_RANGE       = 0x0B22;
constexpr int GL_SMOOTH_LINE_WIDTH_GRANULARITY = 0x0B23;
constexpr int GL_ALIASED_LINE_WIDTH_RANGE      = 0x846E;

void glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices);
void glTexImage3D(GLenum target,
                  GLint level,
                  GLint internalformat,
                  GLsizei width,
                  GLsizei height,
                  GLsizei depth,
                  GLint border,
                  GLenum format,
                  GLenum type,
                  const void* pixels);
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
                     const void* pixels);
void glCopyTexSubImage3D(GLenum target,
                         GLint level,
                         GLint xoffset,
                         GLint yoffset,
                         GLint zoffset,
                         GLint x,
                         GLint y,
                         GLsizei width,
                         GLsizei height);

#pragma endregion

#pragma region GL_VERSION_1_3

constexpr int GL_TEXTURE0                       = 0x84C0;
constexpr int GL_TEXTURE1                       = 0x84C1;
constexpr int GL_TEXTURE2                       = 0x84C2;
constexpr int GL_TEXTURE3                       = 0x84C3;
constexpr int GL_TEXTURE4                       = 0x84C4;
constexpr int GL_TEXTURE5                       = 0x84C5;
constexpr int GL_TEXTURE6                       = 0x84C6;
constexpr int GL_TEXTURE7                       = 0x84C7;
constexpr int GL_TEXTURE8                       = 0x84C8;
constexpr int GL_TEXTURE9                       = 0x84C9;
constexpr int GL_TEXTURE10                      = 0x84CA;
constexpr int GL_TEXTURE11                      = 0x84CB;
constexpr int GL_TEXTURE12                      = 0x84CC;
constexpr int GL_TEXTURE13                      = 0x84CD;
constexpr int GL_TEXTURE14                      = 0x84CE;
constexpr int GL_TEXTURE15                      = 0x84CF;
constexpr int GL_TEXTURE16                      = 0x84D0;
constexpr int GL_TEXTURE17                      = 0x84D1;
constexpr int GL_TEXTURE18                      = 0x84D2;
constexpr int GL_TEXTURE19                      = 0x84D3;
constexpr int GL_TEXTURE20                      = 0x84D4;
constexpr int GL_TEXTURE21                      = 0x84D5;
constexpr int GL_TEXTURE22                      = 0x84D6;
constexpr int GL_TEXTURE23                      = 0x84D7;
constexpr int GL_TEXTURE24                      = 0x84D8;
constexpr int GL_TEXTURE25                      = 0x84D9;
constexpr int GL_TEXTURE26                      = 0x84DA;
constexpr int GL_TEXTURE27                      = 0x84DB;
constexpr int GL_TEXTURE28                      = 0x84DC;
constexpr int GL_TEXTURE29                      = 0x84DD;
constexpr int GL_TEXTURE30                      = 0x84DE;
constexpr int GL_TEXTURE31                      = 0x84DF;
constexpr int GL_ACTIVE_TEXTURE                 = 0x84E0;
constexpr int GL_MULTISAMPLE                    = 0x809D;
constexpr int GL_SAMPLE_ALPHA_TO_COVERAGE       = 0x809E;
constexpr int GL_SAMPLE_ALPHA_TO_ONE            = 0x809F;
constexpr int GL_SAMPLE_COVERAGE                = 0x80A0;
constexpr int GL_SAMPLE_BUFFERS                 = 0x80A8;
constexpr int GL_SAMPLES                        = 0x80A9;
constexpr int GL_SAMPLE_COVERAGE_VALUE          = 0x80AA;
constexpr int GL_SAMPLE_COVERAGE_INVERT         = 0x80AB;
constexpr int GL_TEXTURE_CUBE_MAP               = 0x8513;
constexpr int GL_TEXTURE_BINDING_CUBE_MAP       = 0x8514;
constexpr int GL_TEXTURE_CUBE_MAP_POSITIVE_X    = 0x8515;
constexpr int GL_TEXTURE_CUBE_MAP_NEGATIVE_X    = 0x8516;
constexpr int GL_TEXTURE_CUBE_MAP_POSITIVE_Y    = 0x8517;
constexpr int GL_TEXTURE_CUBE_MAP_NEGATIVE_Y    = 0x8518;
constexpr int GL_TEXTURE_CUBE_MAP_POSITIVE_Z    = 0x8519;
constexpr int GL_TEXTURE_CUBE_MAP_NEGATIVE_Z    = 0x851A;
constexpr int GL_PROXY_TEXTURE_CUBE_MAP         = 0x851B;
constexpr int GL_MAX_CUBE_MAP_TEXTURE_SIZE      = 0x851C;
constexpr int GL_COMPRESSED_RGB                 = 0x84ED;
constexpr int GL_COMPRESSED_RGBA                = 0x84EE;
constexpr int GL_TEXTURE_COMPRESSION_HINT       = 0x84EF;
constexpr int GL_TEXTURE_COMPRESSED_IMAGE_SIZE  = 0x86A0;
constexpr int GL_TEXTURE_COMPRESSED             = 0x86A1;
constexpr int GL_NUM_COMPRESSED_TEXTURE_FORMATS = 0x86A2;
constexpr int GL_COMPRESSED_TEXTURE_FORMATS     = 0x86A3;
constexpr int GL_CLAMP_TO_BORDER                = 0x812D;

void glActiveTexture(GLenum texture);
void glSampleCoverage(GLfloat value, GLboolean invert);
void glCompressedTexImage3D(GLenum target,
                            GLint level,
                            GLenum internalformat,
                            GLsizei width,
                            GLsizei height,
                            GLsizei depth,
                            GLint border,
                            GLsizei imageSize,
                            const void* data);
void glCompressedTexImage2D(GLenum target,
                            GLint level,
                            GLenum internalformat,
                            GLsizei width,
                            GLsizei height,
                            GLint border,
                            GLsizei imageSize,
                            const void* data);
void glCompressedTexImage1D(GLenum target,
                            GLint level,
                            GLenum internalformat,
                            GLsizei width,
                            GLint border,
                            GLsizei imageSize,
                            const void* data);
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
                               const void* data);
void glCompressedTexSubImage2D(GLenum target,
                               GLint level,
                               GLint xoffset,
                               GLint yoffset,
                               GLsizei width,
                               GLsizei height,
                               GLenum format,
                               GLsizei imageSize,
                               const void* data);
void glCompressedTexSubImage1D(GLenum target,
                               GLint level,
                               GLint xoffset,
                               GLsizei width,
                               GLenum format,
                               GLsizei imageSize,
                               const void* data);
void glGetCompressedTexImage(GLenum target, GLint level, void* img);

#pragma endregion

#pragma region GL_VERSION_1_4

constexpr int GL_BLEND_DST_RGB             = 0x80C8;
constexpr int GL_BLEND_SRC_RGB             = 0x80C9;
constexpr int GL_BLEND_DST_ALPHA           = 0x80CA;
constexpr int GL_BLEND_SRC_ALPHA           = 0x80CB;
constexpr int GL_POINT_FADE_THRESHOLD_SIZE = 0x8128;
constexpr int GL_DEPTH_COMPONENT16         = 0x81A5;
constexpr int GL_DEPTH_COMPONENT24         = 0x81A6;
constexpr int GL_DEPTH_COMPONENT32         = 0x81A7;
constexpr int GL_MIRRORED_REPEAT           = 0x8370;
constexpr int GL_MAX_TEXTURE_LOD_BIAS      = 0x84FD;
constexpr int GL_TEXTURE_LOD_BIAS          = 0x8501;
constexpr int GL_INCR_WRAP                 = 0x8507;
constexpr int GL_DECR_WRAP                 = 0x8508;
constexpr int GL_TEXTURE_DEPTH_SIZE        = 0x884A;
constexpr int GL_TEXTURE_COMPARE_MODE      = 0x884C;
constexpr int GL_TEXTURE_COMPARE_FUNC      = 0x884D;
constexpr int GL_BLEND_COLOR               = 0x8005;
constexpr int GL_BLEND_EQUATION            = 0x8009;
constexpr int GL_CONSTANT_COLOR            = 0x8001;
constexpr int GL_ONE_MINUS_CONSTANT_COLOR  = 0x8002;
constexpr int GL_CONSTANT_ALPHA            = 0x8003;
constexpr int GL_ONE_MINUS_CONSTANT_ALPHA  = 0x8004;
constexpr int GL_FUNC_ADD                  = 0x8006;
constexpr int GL_FUNC_REVERSE_SUBTRACT     = 0x800B;
constexpr int GL_FUNC_SUBTRACT             = 0x800A;
constexpr int GL_MIN                       = 0x8007;
constexpr int GL_MAX                       = 0x8008;

void glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
void glMultiDrawArrays(GLenum mode, const GLint* first, const GLsizei* count, GLsizei drawcount);
void glMultiDrawElements(GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawcount);
void glPointParameterf(GLenum pname, GLfloat param);
void glPointParameterfv(GLenum pname, const GLfloat* params);
void glPointParameteri(GLenum pname, GLint param);
void glPointParameteriv(GLenum pname, const GLint* params);
void glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void glBlendEquation(GLenum mode);

#pragma endregion

#pragma region GL_VERSION_1_5

typedef khronos_ssize_t GLsizeiptr;
typedef khronos_intptr_t GLintptr;

constexpr int GL_BUFFER_SIZE                        = 0x8764;
constexpr int GL_BUFFER_USAGE                       = 0x8765;
constexpr int GL_QUERY_COUNTER_BITS                 = 0x8864;
constexpr int GL_CURRENT_QUERY                      = 0x8865;
constexpr int GL_QUERY_RESULT                       = 0x8866;
constexpr int GL_QUERY_RESULT_AVAILABLE             = 0x8867;
constexpr int GL_ARRAY_BUFFER                       = 0x8892;
constexpr int GL_ELEMENT_ARRAY_BUFFER               = 0x8893;
constexpr int GL_ARRAY_BUFFER_BINDING               = 0x8894;
constexpr int GL_ELEMENT_ARRAY_BUFFER_BINDING       = 0x8895;
constexpr int GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING = 0x889F;
constexpr int GL_READ_ONLY                          = 0x88B8;
constexpr int GL_WRITE_ONLY                         = 0x88B9;
constexpr int GL_READ_WRITE                         = 0x88BA;
constexpr int GL_BUFFER_ACCESS                      = 0x88BB;
constexpr int GL_BUFFER_MAPPED                      = 0x88BC;
constexpr int GL_BUFFER_MAP_POINTER                 = 0x88BD;
constexpr int GL_STREAM_DRAW                        = 0x88E0;
constexpr int GL_STREAM_READ                        = 0x88E1;
constexpr int GL_STREAM_COPY                        = 0x88E2;
constexpr int GL_STATIC_DRAW                        = 0x88E4;
constexpr int GL_STATIC_READ                        = 0x88E5;
constexpr int GL_STATIC_COPY                        = 0x88E6;
constexpr int GL_DYNAMIC_DRAW                       = 0x88E8;
constexpr int GL_DYNAMIC_READ                       = 0x88E9;
constexpr int GL_DYNAMIC_COPY                       = 0x88EA;
constexpr int GL_SAMPLES_PASSED                     = 0x8914;
constexpr int GL_SRC1_ALPHA                         = 0x8589;

void glGenQueries(GLsizei n, GLuint* ids);
void glDeleteQueries(GLsizei n, const GLuint* ids);
GLboolean glIsQuery(GLuint id);
void glBeginQuery(GLenum target, GLuint id);
void glEndQuery(GLenum target);
void glGetQueryiv(GLenum target, GLenum pname, GLint* params);
void glGetQueryObjectiv(GLuint id, GLenum pname, GLint* params);
void glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint* params);
void glBindBuffer(GLenum target, GLuint buffer);
void glDeleteBuffers(GLsizei n, const GLuint* buffers);
void glGenBuffers(GLsizei n, GLuint* buffers);
GLboolean glIsBuffer(GLuint buffer);
void glBufferData(GLenum target, GLsizeiptr size, const void* data, GLenum usage);
void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void* data);
void glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, void* data);
void* glMapBuffer(GLenum target, GLenum access);
GLboolean glUnmapBuffer(GLenum target);
void glGetBufferParameteriv(GLenum target, GLenum pname, GLint* params);
void glGetBufferPointerv(GLenum target, GLenum pname, void** params);

#pragma endregion

#pragma region GL_VERSION_2_0

typedef char GLchar;
typedef khronos_int16_t GLshort;
typedef khronos_int8_t GLbyte;
typedef khronos_uint16_t GLushort;

constexpr int GL_BLEND_EQUATION_RGB               = 0x8009;
constexpr int GL_VERTEX_ATTRIB_ARRAY_ENABLED      = 0x8622;
constexpr int GL_VERTEX_ATTRIB_ARRAY_SIZE         = 0x8623;
constexpr int GL_VERTEX_ATTRIB_ARRAY_STRIDE       = 0x8624;
constexpr int GL_VERTEX_ATTRIB_ARRAY_TYPE         = 0x8625;
constexpr int GL_CURRENT_VERTEX_ATTRIB            = 0x8626;
constexpr int GL_VERTEX_PROGRAM_POINT_SIZE        = 0x8642;
constexpr int GL_VERTEX_ATTRIB_ARRAY_POINTER      = 0x8645;
constexpr int GL_STENCIL_BACK_FUNC                = 0x8800;
constexpr int GL_STENCIL_BACK_FAIL                = 0x8801;
constexpr int GL_STENCIL_BACK_PASS_DEPTH_FAIL     = 0x8802;
constexpr int GL_STENCIL_BACK_PASS_DEPTH_PASS     = 0x8803;
constexpr int GL_MAX_DRAW_BUFFERS                 = 0x8824;
constexpr int GL_DRAW_BUFFER0                     = 0x8825;
constexpr int GL_DRAW_BUFFER1                     = 0x8826;
constexpr int GL_DRAW_BUFFER2                     = 0x8827;
constexpr int GL_DRAW_BUFFER3                     = 0x8828;
constexpr int GL_DRAW_BUFFER4                     = 0x8829;
constexpr int GL_DRAW_BUFFER5                     = 0x882A;
constexpr int GL_DRAW_BUFFER6                     = 0x882B;
constexpr int GL_DRAW_BUFFER7                     = 0x882C;
constexpr int GL_DRAW_BUFFER8                     = 0x882D;
constexpr int GL_DRAW_BUFFER9                     = 0x882E;
constexpr int GL_DRAW_BUFFER10                    = 0x882F;
constexpr int GL_DRAW_BUFFER11                    = 0x8830;
constexpr int GL_DRAW_BUFFER12                    = 0x8831;
constexpr int GL_DRAW_BUFFER13                    = 0x8832;
constexpr int GL_DRAW_BUFFER14                    = 0x8833;
constexpr int GL_DRAW_BUFFER15                    = 0x8834;
constexpr int GL_BLEND_EQUATION_ALPHA             = 0x883D;
constexpr int GL_MAX_VERTEX_ATTRIBS               = 0x8869;
constexpr int GL_VERTEX_ATTRIB_ARRAY_NORMALIZED   = 0x886A;
constexpr int GL_MAX_TEXTURE_IMAGE_UNITS          = 0x8872;
constexpr int GL_FRAGMENT_SHADER                  = 0x8B30;
constexpr int GL_VERTEX_SHADER                    = 0x8B31;
constexpr int GL_MAX_FRAGMENT_UNIFORM_COMPONENTS  = 0x8B49;
constexpr int GL_MAX_VERTEX_UNIFORM_COMPONENTS    = 0x8B4A;
constexpr int GL_MAX_VARYING_FLOATS               = 0x8B4B;
constexpr int GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS   = 0x8B4C;
constexpr int GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS = 0x8B4D;
constexpr int GL_SHADER_TYPE                      = 0x8B4F;
constexpr int GL_FLOAT_VEC2                       = 0x8B50;
constexpr int GL_FLOAT_VEC3                       = 0x8B51;
constexpr int GL_FLOAT_VEC4                       = 0x8B52;
constexpr int GL_INT_VEC2                         = 0x8B53;
constexpr int GL_INT_VEC3                         = 0x8B54;
constexpr int GL_INT_VEC4                         = 0x8B55;
constexpr int GL_BOOL                             = 0x8B56;
constexpr int GL_BOOL_VEC2                        = 0x8B57;
constexpr int GL_BOOL_VEC3                        = 0x8B58;
constexpr int GL_BOOL_VEC4                        = 0x8B59;
constexpr int GL_FLOAT_MAT2                       = 0x8B5A;
constexpr int GL_FLOAT_MAT3                       = 0x8B5B;
constexpr int GL_FLOAT_MAT4                       = 0x8B5C;
constexpr int GL_SAMPLER_1D                       = 0x8B5D;
constexpr int GL_SAMPLER_2D                       = 0x8B5E;
constexpr int GL_SAMPLER_3D                       = 0x8B5F;
constexpr int GL_SAMPLER_CUBE                     = 0x8B60;
constexpr int GL_SAMPLER_1D_SHADOW                = 0x8B61;
constexpr int GL_SAMPLER_2D_SHADOW                = 0x8B62;
constexpr int GL_DELETE_STATUS                    = 0x8B80;
constexpr int GL_COMPILE_STATUS                   = 0x8B81;
constexpr int GL_LINK_STATUS                      = 0x8B82;
constexpr int GL_VALIDATE_STATUS                  = 0x8B83;
constexpr int GL_INFO_LOG_LENGTH                  = 0x8B84;
constexpr int GL_ATTACHED_SHADERS                 = 0x8B85;
constexpr int GL_ACTIVE_UNIFORMS                  = 0x8B86;
constexpr int GL_ACTIVE_UNIFORM_MAX_LENGTH        = 0x8B87;
constexpr int GL_SHADER_SOURCE_LENGTH             = 0x8B88;
constexpr int GL_ACTIVE_ATTRIBUTES                = 0x8B89;
constexpr int GL_ACTIVE_ATTRIBUTE_MAX_LENGTH      = 0x8B8A;
constexpr int GL_FRAGMENT_SHADER_DERIVATIVE_HINT  = 0x8B8B;
constexpr int GL_SHADING_LANGUAGE_VERSION         = 0x8B8C;
constexpr int GL_CURRENT_PROGRAM                  = 0x8B8D;
constexpr int GL_POINT_SPRITE_COORD_ORIGIN        = 0x8CA0;
constexpr int GL_LOWER_LEFT                       = 0x8CA1;
constexpr int GL_UPPER_LEFT                       = 0x8CA2;
constexpr int GL_STENCIL_BACK_REF                 = 0x8CA3;
constexpr int GL_STENCIL_BACK_VALUE_MASK          = 0x8CA4;
constexpr int GL_STENCIL_BACK_WRITEMASK           = 0x8CA5;

void glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha);
void glDrawBuffers(GLsizei n, const GLenum* bufs);
void glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
void glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask);
void glStencilMaskSeparate(GLenum face, GLuint mask);
void glAttachShader(GLuint program, GLuint shader);
void glBindAttribLocation(GLuint program, GLuint index, const GLchar* name);
void glCompileShader(GLuint shader);
GLuint glCreateProgram();
GLuint glCreateShader(GLenum type);
void glDeleteProgram(GLuint program);
void glDeleteShader(GLuint shader);
void glDetachShader(GLuint program, GLuint shader);
void glDisableVertexAttribArray(GLuint index);
void glEnableVertexAttribArray(GLuint index);
void glGetActiveAttrib(GLuint program,
                       GLuint index,
                       GLsizei bufSize,
                       GLsizei* length,
                       GLint* size,
                       GLenum* type,
                       GLchar* name);
void glGetActiveUniform(GLuint program,
                        GLuint index,
                        GLsizei bufSize,
                        GLsizei* length,
                        GLint* size,
                        GLenum* type,
                        GLchar* name);
void glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei* count, GLuint* shaders);
GLint glGetAttribLocation(GLuint program, const GLchar* name);
void glGetProgramiv(GLuint program, GLenum pname, GLint* params);
void glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
void glGetShaderiv(GLuint shader, GLenum pname, GLint* params);
void glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
void glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* source);
GLint glGetUniformLocation(GLuint program, const GLchar* name);
void glGetUniformfv(GLuint program, GLint location, GLfloat* params);
void glGetUniformiv(GLuint program, GLint location, GLint* params);
void glGetVertexAttribdv(GLuint index, GLenum pname, GLdouble* params);
void glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat* params);
void glGetVertexAttribiv(GLuint index, GLenum pname, GLint* params);
void glGetVertexAttribPointerv(GLuint index, GLenum pname, void** pointer);
GLboolean glIsProgram(GLuint program);
GLboolean glIsShader(GLuint shader);
void glLinkProgram(GLuint program);
void glShaderSource(GLuint shader, GLsizei count, const GLchar* const* string, const GLint* length);
void glUseProgram(GLuint program);
void glUniform1f(GLint location, GLfloat v0);
void glUniform2f(GLint location, GLfloat v0, GLfloat v1);
void glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
void glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
void glUniform1i(GLint location, GLint v0);
void glUniform2i(GLint location, GLint v0, GLint v1);
void glUniform3i(GLint location, GLint v0, GLint v1, GLint v2);
void glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
void glUniform1fv(GLint location, GLsizei count, const GLfloat* value);
void glUniform2fv(GLint location, GLsizei count, const GLfloat* value);
void glUniform3fv(GLint location, GLsizei count, const GLfloat* value);
void glUniform4fv(GLint location, GLsizei count, const GLfloat* value);
void glUniform1iv(GLint location, GLsizei count, const GLint* value);
void glUniform2iv(GLint location, GLsizei count, const GLint* value);
void glUniform3iv(GLint location, GLsizei count, const GLint* value);
void glUniform4iv(GLint location, GLsizei count, const GLint* value);
void glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
void glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
void glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
void glValidateProgram(GLuint program);
void glVertexAttrib1d(GLuint index, GLdouble x);
void glVertexAttrib1dv(GLuint index, const GLdouble* v);
void glVertexAttrib1f(GLuint index, GLfloat x);
void glVertexAttrib1fv(GLuint index, const GLfloat* v);
void glVertexAttrib1s(GLuint index, GLshort x);
void glVertexAttrib1sv(GLuint index, const GLshort* v);
void glVertexAttrib2d(GLuint index, GLdouble x, GLdouble y);
void glVertexAttrib2dv(GLuint index, const GLdouble* v);
void glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y);
void glVertexAttrib2fv(GLuint index, const GLfloat* v);
void glVertexAttrib2s(GLuint index, GLshort x, GLshort y);
void glVertexAttrib2sv(GLuint index, const GLshort* v);
void glVertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z);
void glVertexAttrib3dv(GLuint index, const GLdouble* v);
void glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z);
void glVertexAttrib3fv(GLuint index, const GLfloat* v);
void glVertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z);
void glVertexAttrib3sv(GLuint index, const GLshort* v);
void glVertexAttrib4Nbv(GLuint index, const GLbyte* v);
void glVertexAttrib4Niv(GLuint index, const GLint* v);
void glVertexAttrib4Nsv(GLuint index, const GLshort* v);
void glVertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
void glVertexAttrib4Nubv(GLuint index, const GLubyte* v);
void glVertexAttrib4Nuiv(GLuint index, const GLuint* v);
void glVertexAttrib4Nusv(GLuint index, const GLushort* v);
void glVertexAttrib4bv(GLuint index, const GLbyte* v);
void glVertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void glVertexAttrib4dv(GLuint index, const GLdouble* v);
void glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void glVertexAttrib4fv(GLuint index, const GLfloat* v);
void glVertexAttrib4iv(GLuint index, const GLint* v);
void glVertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
void glVertexAttrib4sv(GLuint index, const GLshort* v);
void glVertexAttrib4ubv(GLuint index, const GLubyte* v);
void glVertexAttrib4uiv(GLuint index, const GLuint* v);
void glVertexAttrib4usv(GLuint index, const GLushort* v);
void glVertexAttribPointer(GLuint index,
                           GLint size,
                           GLenum type,
                           GLboolean normalized,
                           GLsizei stride,
                           const void* pointer);

#pragma endregion

#pragma region GL_VERSION_2_1

constexpr int GL_PIXEL_PACK_BUFFER           = 0x88EB;
constexpr int GL_PIXEL_UNPACK_BUFFER         = 0x88EC;
constexpr int GL_PIXEL_PACK_BUFFER_BINDING   = 0x88ED;
constexpr int GL_PIXEL_UNPACK_BUFFER_BINDING = 0x88EF;
constexpr int GL_FLOAT_MAT2x3                = 0x8B65;
constexpr int GL_FLOAT_MAT2x4                = 0x8B66;
constexpr int GL_FLOAT_MAT3x2                = 0x8B67;
constexpr int GL_FLOAT_MAT3x4                = 0x8B68;
constexpr int GL_FLOAT_MAT4x2                = 0x8B69;
constexpr int GL_FLOAT_MAT4x3                = 0x8B6A;
constexpr int GL_SRGB                        = 0x8C40;
constexpr int GL_SRGB8                       = 0x8C41;
constexpr int GL_SRGB_ALPHA                  = 0x8C42;
constexpr int GL_SRGB8_ALPHA8                = 0x8C43;
constexpr int GL_COMPRESSED_SRGB             = 0x8C48;
constexpr int GL_COMPRESSED_SRGB_ALPHA       = 0x8C49;

void glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
void glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
void glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
void glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
void glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
void glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);

#pragma endregion

#pragma region GL_VERSION_3_0

typedef khronos_uint16_t GLhalf;

constexpr int GL_COMPARE_REF_TO_TEXTURE                        = 0x884E;
constexpr int GL_CLIP_DISTANCE0                                = 0x3000;
constexpr int GL_CLIP_DISTANCE1                                = 0x3001;
constexpr int GL_CLIP_DISTANCE2                                = 0x3002;
constexpr int GL_CLIP_DISTANCE3                                = 0x3003;
constexpr int GL_CLIP_DISTANCE4                                = 0x3004;
constexpr int GL_CLIP_DISTANCE5                                = 0x3005;
constexpr int GL_CLIP_DISTANCE6                                = 0x3006;
constexpr int GL_CLIP_DISTANCE7                                = 0x3007;
constexpr int GL_MAX_CLIP_DISTANCES                            = 0x0D32;
constexpr int GL_MAJOR_VERSION                                 = 0x821B;
constexpr int GL_MINOR_VERSION                                 = 0x821C;
constexpr int GL_NUM_EXTENSIONS                                = 0x821D;
constexpr int GL_CONTEXT_FLAGS                                 = 0x821E;
constexpr int GL_COMPRESSED_RED                                = 0x8225;
constexpr int GL_COMPRESSED_RG                                 = 0x8226;
constexpr int GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT           = 0x00000001;
constexpr int GL_RGBA32F                                       = 0x8814;
constexpr int GL_RGB32F                                        = 0x8815;
constexpr int GL_RGBA16F                                       = 0x881A;
constexpr int GL_RGB16F                                        = 0x881B;
constexpr int GL_VERTEX_ATTRIB_ARRAY_INTEGER                   = 0x88FD;
constexpr int GL_MAX_ARRAY_TEXTURE_LAYERS                      = 0x88FF;
constexpr int GL_MIN_PROGRAM_TEXEL_OFFSET                      = 0x8904;
constexpr int GL_MAX_PROGRAM_TEXEL_OFFSET                      = 0x8905;
constexpr int GL_CLAMP_READ_COLOR                              = 0x891C;
constexpr int GL_FIXED_ONLY                                    = 0x891D;
constexpr int GL_MAX_VARYING_COMPONENTS                        = 0x8B4B;
constexpr int GL_TEXTURE_1D_ARRAY                              = 0x8C18;
constexpr int GL_PROXY_TEXTURE_1D_ARRAY                        = 0x8C19;
constexpr int GL_TEXTURE_2D_ARRAY                              = 0x8C1A;
constexpr int GL_PROXY_TEXTURE_2D_ARRAY                        = 0x8C1B;
constexpr int GL_TEXTURE_BINDING_1D_ARRAY                      = 0x8C1C;
constexpr int GL_TEXTURE_BINDING_2D_ARRAY                      = 0x8C1D;
constexpr int GL_R11F_G11F_B10F                                = 0x8C3A;
constexpr int GL_UNSIGNED_INT_10F_11F_11F_REV                  = 0x8C3B;
constexpr int GL_RGB9_E5                                       = 0x8C3D;
constexpr int GL_UNSIGNED_INT_5_9_9_9_REV                      = 0x8C3E;
constexpr int GL_TEXTURE_SHARED_SIZE                           = 0x8C3F;
constexpr int GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH         = 0x8C76;
constexpr int GL_TRANSFORM_FEEDBACK_BUFFER_MODE                = 0x8C7F;
constexpr int GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS    = 0x8C80;
constexpr int GL_TRANSFORM_FEEDBACK_VARYINGS                   = 0x8C83;
constexpr int GL_TRANSFORM_FEEDBACK_BUFFER_START               = 0x8C84;
constexpr int GL_TRANSFORM_FEEDBACK_BUFFER_SIZE                = 0x8C85;
constexpr int GL_PRIMITIVES_GENERATED                          = 0x8C87;
constexpr int GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN         = 0x8C88;
constexpr int GL_RASTERIZER_DISCARD                            = 0x8C89;
constexpr int GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS = 0x8C8A;
constexpr int GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS       = 0x8C8B;
constexpr int GL_INTERLEAVED_ATTRIBS                           = 0x8C8C;
constexpr int GL_SEPARATE_ATTRIBS                              = 0x8C8D;
constexpr int GL_TRANSFORM_FEEDBACK_BUFFER                     = 0x8C8E;
constexpr int GL_TRANSFORM_FEEDBACK_BUFFER_BINDING             = 0x8C8F;
constexpr int GL_RGBA32UI                                      = 0x8D70;
constexpr int GL_RGB32UI                                       = 0x8D71;
constexpr int GL_RGBA16UI                                      = 0x8D76;
constexpr int GL_RGB16UI                                       = 0x8D77;
constexpr int GL_RGBA8UI                                       = 0x8D7C;
constexpr int GL_RGB8UI                                        = 0x8D7D;
constexpr int GL_RGBA32I                                       = 0x8D82;
constexpr int GL_RGB32I                                        = 0x8D83;
constexpr int GL_RGBA16I                                       = 0x8D88;
constexpr int GL_RGB16I                                        = 0x8D89;
constexpr int GL_RGBA8I                                        = 0x8D8E;
constexpr int GL_RGB8I                                         = 0x8D8F;
constexpr int GL_RED_INTEGER                                   = 0x8D94;
constexpr int GL_GREEN_INTEGER                                 = 0x8D95;
constexpr int GL_BLUE_INTEGER                                  = 0x8D96;
constexpr int GL_RGB_INTEGER                                   = 0x8D98;
constexpr int GL_RGBA_INTEGER                                  = 0x8D99;
constexpr int GL_BGR_INTEGER                                   = 0x8D9A;
constexpr int GL_BGRA_INTEGER                                  = 0x8D9B;
constexpr int GL_SAMPLER_1D_ARRAY                              = 0x8DC0;
constexpr int GL_SAMPLER_2D_ARRAY                              = 0x8DC1;
constexpr int GL_SAMPLER_1D_ARRAY_SHADOW                       = 0x8DC3;
constexpr int GL_SAMPLER_2D_ARRAY_SHADOW                       = 0x8DC4;
constexpr int GL_SAMPLER_CUBE_SHADOW                           = 0x8DC5;
constexpr int GL_UNSIGNED_INT_VEC2                             = 0x8DC6;
constexpr int GL_UNSIGNED_INT_VEC3                             = 0x8DC7;
constexpr int GL_UNSIGNED_INT_VEC4                             = 0x8DC8;
constexpr int GL_INT_SAMPLER_1D                                = 0x8DC9;
constexpr int GL_INT_SAMPLER_2D                                = 0x8DCA;
constexpr int GL_INT_SAMPLER_3D                                = 0x8DCB;
constexpr int GL_INT_SAMPLER_CUBE                              = 0x8DCC;
constexpr int GL_INT_SAMPLER_1D_ARRAY                          = 0x8DCE;
constexpr int GL_INT_SAMPLER_2D_ARRAY                          = 0x8DCF;
constexpr int GL_UNSIGNED_INT_SAMPLER_1D                       = 0x8DD1;
constexpr int GL_UNSIGNED_INT_SAMPLER_2D                       = 0x8DD2;
constexpr int GL_UNSIGNED_INT_SAMPLER_3D                       = 0x8DD3;
constexpr int GL_UNSIGNED_INT_SAMPLER_CUBE                     = 0x8DD4;
constexpr int GL_UNSIGNED_INT_SAMPLER_1D_ARRAY                 = 0x8DD6;
constexpr int GL_UNSIGNED_INT_SAMPLER_2D_ARRAY                 = 0x8DD7;
constexpr int GL_QUERY_WAIT                                    = 0x8E13;
constexpr int GL_QUERY_NO_WAIT                                 = 0x8E14;
constexpr int GL_QUERY_BY_REGION_WAIT                          = 0x8E15;
constexpr int GL_QUERY_BY_REGION_NO_WAIT                       = 0x8E16;
constexpr int GL_BUFFER_ACCESS_FLAGS                           = 0x911F;
constexpr int GL_BUFFER_MAP_LENGTH                             = 0x9120;
constexpr int GL_BUFFER_MAP_OFFSET                             = 0x9121;
constexpr int GL_DEPTH_COMPONENT32F                            = 0x8CAC;
constexpr int GL_DEPTH32F_STENCIL8                             = 0x8CAD;
constexpr int GL_FLOAT_32_UNSIGNED_INT_24_8_REV                = 0x8DAD;
constexpr int GL_INVALID_FRAMEBUFFER_OPERATION                 = 0x0506;
constexpr int GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING         = 0x8210;
constexpr int GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE         = 0x8211;
constexpr int GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE               = 0x8212;
constexpr int GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE             = 0x8213;
constexpr int GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE              = 0x8214;
constexpr int GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE             = 0x8215;
constexpr int GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE             = 0x8216;
constexpr int GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE           = 0x8217;
constexpr int GL_FRAMEBUFFER_DEFAULT                           = 0x8218;
constexpr int GL_FRAMEBUFFER_UNDEFINED                         = 0x8219;
constexpr int GL_DEPTH_STENCIL_ATTACHMENT                      = 0x821A;
constexpr int GL_MAX_RENDERBUFFER_SIZE                         = 0x84E8;
constexpr int GL_DEPTH_STENCIL                                 = 0x84F9;
constexpr int GL_UNSIGNED_INT_24_8                             = 0x84FA;
constexpr int GL_DEPTH24_STENCIL8                              = 0x88F0;
constexpr int GL_TEXTURE_STENCIL_SIZE                          = 0x88F1;
constexpr int GL_TEXTURE_RED_TYPE                              = 0x8C10;
constexpr int GL_TEXTURE_GREEN_TYPE                            = 0x8C11;
constexpr int GL_TEXTURE_BLUE_TYPE                             = 0x8C12;
constexpr int GL_TEXTURE_ALPHA_TYPE                            = 0x8C13;
constexpr int GL_TEXTURE_DEPTH_TYPE                            = 0x8C16;
constexpr int GL_UNSIGNED_NORMALIZED                           = 0x8C17;
constexpr int GL_FRAMEBUFFER_BINDING                           = 0x8CA6;
constexpr int GL_DRAW_FRAMEBUFFER_BINDING                      = 0x8CA6;
constexpr int GL_RENDERBUFFER_BINDING                          = 0x8CA7;
constexpr int GL_READ_FRAMEBUFFER                              = 0x8CA8;
constexpr int GL_DRAW_FRAMEBUFFER                              = 0x8CA9;
constexpr int GL_READ_FRAMEBUFFER_BINDING                      = 0x8CAA;
constexpr int GL_RENDERBUFFER_SAMPLES                          = 0x8CAB;
constexpr int GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE            = 0x8CD0;
constexpr int GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME            = 0x8CD1;
constexpr int GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL          = 0x8CD2;
constexpr int GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE  = 0x8CD3;
constexpr int GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER          = 0x8CD4;
constexpr int GL_FRAMEBUFFER_COMPLETE                          = 0x8CD5;
constexpr int GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT             = 0x8CD6;
constexpr int GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT     = 0x8CD7;
constexpr int GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER            = 0x8CDB;
constexpr int GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER            = 0x8CDC;
constexpr int GL_FRAMEBUFFER_UNSUPPORTED                       = 0x8CDD;
constexpr int GL_MAX_COLOR_ATTACHMENTS                         = 0x8CDF;
constexpr int GL_COLOR_ATTACHMENT0                             = 0x8CE0;
constexpr int GL_COLOR_ATTACHMENT1                             = 0x8CE1;
constexpr int GL_COLOR_ATTACHMENT2                             = 0x8CE2;
constexpr int GL_COLOR_ATTACHMENT3                             = 0x8CE3;
constexpr int GL_COLOR_ATTACHMENT4                             = 0x8CE4;
constexpr int GL_COLOR_ATTACHMENT5                             = 0x8CE5;
constexpr int GL_COLOR_ATTACHMENT6                             = 0x8CE6;
constexpr int GL_COLOR_ATTACHMENT7                             = 0x8CE7;
constexpr int GL_COLOR_ATTACHMENT8                             = 0x8CE8;
constexpr int GL_COLOR_ATTACHMENT9                             = 0x8CE9;
constexpr int GL_COLOR_ATTACHMENT10                            = 0x8CEA;
constexpr int GL_COLOR_ATTACHMENT11                            = 0x8CEB;
constexpr int GL_COLOR_ATTACHMENT12                            = 0x8CEC;
constexpr int GL_COLOR_ATTACHMENT13                            = 0x8CED;
constexpr int GL_COLOR_ATTACHMENT14                            = 0x8CEE;
constexpr int GL_COLOR_ATTACHMENT15                            = 0x8CEF;
constexpr int GL_COLOR_ATTACHMENT16                            = 0x8CF0;
constexpr int GL_COLOR_ATTACHMENT17                            = 0x8CF1;
constexpr int GL_COLOR_ATTACHMENT18                            = 0x8CF2;
constexpr int GL_COLOR_ATTACHMENT19                            = 0x8CF3;
constexpr int GL_COLOR_ATTACHMENT20                            = 0x8CF4;
constexpr int GL_COLOR_ATTACHMENT21                            = 0x8CF5;
constexpr int GL_COLOR_ATTACHMENT22                            = 0x8CF6;
constexpr int GL_COLOR_ATTACHMENT23                            = 0x8CF7;
constexpr int GL_COLOR_ATTACHMENT24                            = 0x8CF8;
constexpr int GL_COLOR_ATTACHMENT25                            = 0x8CF9;
constexpr int GL_COLOR_ATTACHMENT26                            = 0x8CFA;
constexpr int GL_COLOR_ATTACHMENT27                            = 0x8CFB;
constexpr int GL_COLOR_ATTACHMENT28                            = 0x8CFC;
constexpr int GL_COLOR_ATTACHMENT29                            = 0x8CFD;
constexpr int GL_COLOR_ATTACHMENT30                            = 0x8CFE;
constexpr int GL_COLOR_ATTACHMENT31                            = 0x8CFF;
constexpr int GL_DEPTH_ATTACHMENT                              = 0x8D00;
constexpr int GL_STENCIL_ATTACHMENT                            = 0x8D20;
constexpr int GL_FRAMEBUFFER                                   = 0x8D40;
constexpr int GL_RENDERBUFFER                                  = 0x8D41;
constexpr int GL_RENDERBUFFER_WIDTH                            = 0x8D42;
constexpr int GL_RENDERBUFFER_HEIGHT                           = 0x8D43;
constexpr int GL_RENDERBUFFER_INTERNAL_FORMAT                  = 0x8D44;
constexpr int GL_STENCIL_INDEX1                                = 0x8D46;
constexpr int GL_STENCIL_INDEX4                                = 0x8D47;
constexpr int GL_STENCIL_INDEX8                                = 0x8D48;
constexpr int GL_STENCIL_INDEX16                               = 0x8D49;
constexpr int GL_RENDERBUFFER_RED_SIZE                         = 0x8D50;
constexpr int GL_RENDERBUFFER_GREEN_SIZE                       = 0x8D51;
constexpr int GL_RENDERBUFFER_BLUE_SIZE                        = 0x8D52;
constexpr int GL_RENDERBUFFER_ALPHA_SIZE                       = 0x8D53;
constexpr int GL_RENDERBUFFER_DEPTH_SIZE                       = 0x8D54;
constexpr int GL_RENDERBUFFER_STENCIL_SIZE                     = 0x8D55;
constexpr int GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE            = 0x8D56;
constexpr int GL_MAX_SAMPLES                                   = 0x8D57;
constexpr int GL_FRAMEBUFFER_SRGB                              = 0x8DB9;
constexpr int GL_HALF_FLOAT                                    = 0x140B;
constexpr int GL_MAP_READ_BIT                                  = 0x0001;
constexpr int GL_MAP_WRITE_BIT                                 = 0x0002;
constexpr int GL_MAP_INVALIDATE_RANGE_BIT                      = 0x0004;
constexpr int GL_MAP_INVALIDATE_BUFFER_BIT                     = 0x0008;
constexpr int GL_MAP_FLUSH_EXPLICIT_BIT                        = 0x0010;
constexpr int GL_MAP_UNSYNCHRONIZED_BIT                        = 0x0020;
constexpr int GL_COMPRESSED_RED_RGTC1                          = 0x8DBB;
constexpr int GL_COMPRESSED_SIGNED_RED_RGTC1                   = 0x8DBC;
constexpr int GL_COMPRESSED_RG_RGTC2                           = 0x8DBD;
constexpr int GL_COMPRESSED_SIGNED_RG_RGTC2                    = 0x8DBE;
constexpr int GL_RG                                            = 0x8227;
constexpr int GL_RG_INTEGER                                    = 0x8228;
constexpr int GL_R8                                            = 0x8229;
constexpr int GL_R16                                           = 0x822A;
constexpr int GL_RG8                                           = 0x822B;
constexpr int GL_RG16                                          = 0x822C;
constexpr int GL_R16F                                          = 0x822D;
constexpr int GL_R32F                                          = 0x822E;
constexpr int GL_RG16F                                         = 0x822F;
constexpr int GL_RG32F                                         = 0x8230;
constexpr int GL_R8I                                           = 0x8231;
constexpr int GL_R8UI                                          = 0x8232;
constexpr int GL_R16I                                          = 0x8233;
constexpr int GL_R16UI                                         = 0x8234;
constexpr int GL_R32I                                          = 0x8235;
constexpr int GL_R32UI                                         = 0x8236;
constexpr int GL_RG8I                                          = 0x8237;
constexpr int GL_RG8UI                                         = 0x8238;
constexpr int GL_RG16I                                         = 0x8239;
constexpr int GL_RG16UI                                        = 0x823A;
constexpr int GL_RG32I                                         = 0x823B;
constexpr int GL_RG32UI                                        = 0x823C;
constexpr int GL_VERTEX_ARRAY_BINDING                          = 0x85B5;

void glColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
void glGetBooleani_v(GLenum target, GLuint index, GLboolean* data);
void glGetIntegeri_v(GLenum target, GLuint index, GLint* data);
void glEnablei(GLenum target, GLuint index);
void glDisablei(GLenum target, GLuint index);
GLboolean glIsEnabledi(GLenum target, GLuint index);
void glBeginTransformFeedback(GLenum primitiveMode);
void glEndTransformFeedback();
void glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
void glBindBufferBase(GLenum target, GLuint index, GLuint buffer);
void glTransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar* const* varyings, GLenum bufferMode);
void glGetTransformFeedbackVarying(GLuint program,
                                   GLuint index,
                                   GLsizei bufSize,
                                   GLsizei* length,
                                   GLsizei* size,
                                   GLenum* type,
                                   GLchar* name);
void glClampColor(GLenum target, GLenum clamp);
void glBeginConditionalRender(GLuint id, GLenum mode);
void glEndConditionalRender();
void glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer);
void glGetVertexAttribIiv(GLuint index, GLenum pname, GLint* params);
void glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint* params);
void glVertexAttribI1i(GLuint index, GLint x);
void glVertexAttribI2i(GLuint index, GLint x, GLint y);
void glVertexAttribI3i(GLuint index, GLint x, GLint y, GLint z);
void glVertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w);
void glVertexAttribI1ui(GLuint index, GLuint x);
void glVertexAttribI2ui(GLuint index, GLuint x, GLuint y);
void glVertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z);
void glVertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
void glVertexAttribI1iv(GLuint index, const GLint* v);
void glVertexAttribI2iv(GLuint index, const GLint* v);
void glVertexAttribI3iv(GLuint index, const GLint* v);
void glVertexAttribI4iv(GLuint index, const GLint* v);
void glVertexAttribI1uiv(GLuint index, const GLuint* v);
void glVertexAttribI2uiv(GLuint index, const GLuint* v);
void glVertexAttribI3uiv(GLuint index, const GLuint* v);
void glVertexAttribI4uiv(GLuint index, const GLuint* v);
void glVertexAttribI4bv(GLuint index, const GLbyte* v);
void glVertexAttribI4sv(GLuint index, const GLshort* v);
void glVertexAttribI4ubv(GLuint index, const GLubyte* v);
void glVertexAttribI4usv(GLuint index, const GLushort* v);
void glGetUniformuiv(GLuint program, GLint location, GLuint* params);
void glBindFragDataLocation(GLuint program, GLuint color, const GLchar* name);
GLint glGetFragDataLocation(GLuint program, const GLchar* name);
void glUniform1ui(GLint location, GLuint v0);
void glUniform2ui(GLint location, GLuint v0, GLuint v1);
void glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2);
void glUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
void glUniform1uiv(GLint location, GLsizei count, const GLuint* value);
void glUniform2uiv(GLint location, GLsizei count, const GLuint* value);
void glUniform3uiv(GLint location, GLsizei count, const GLuint* value);
void glUniform4uiv(GLint location, GLsizei count, const GLuint* value);
void glTexParameterIiv(GLenum target, GLenum pname, const GLint* params);
void glTexParameterIuiv(GLenum target, GLenum pname, const GLuint* params);
void glGetTexParameterIiv(GLenum target, GLenum pname, GLint* params);
void glGetTexParameterIuiv(GLenum target, GLenum pname, GLuint* params);
void glClearBufferiv(GLenum buffer, GLint drawbuffer, const GLint* value);
void glClearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint* value);
void glClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat* value);
void glClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
const GLubyte* glGetStringi(GLenum name, GLuint index);
GLboolean glIsRenderbuffer(GLuint renderbuffer);
void glBindRenderbuffer(GLenum target, GLuint renderbuffer);
void glDeleteRenderbuffers(GLsizei n, const GLuint* renderbuffers);
void glGenRenderbuffers(GLsizei n, GLuint* renderbuffers);
void glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint* params);
GLboolean glIsFramebuffer(GLuint framebuffer);
void glBindFramebuffer(GLenum target, GLuint framebuffer);
void glDeleteFramebuffers(GLsizei n, const GLuint* framebuffers);
void glGenFramebuffers(GLsizei n, GLuint* framebuffers);
GLenum glCheckFramebufferStatus(GLenum target);
void glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
void glFramebufferTexture3D(GLenum target,
                            GLenum attachment,
                            GLenum textarget,
                            GLuint texture,
                            GLint level,
                            GLint zoffset);
void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint* params);
void glGenerateMipmap(GLenum target);
void glBlitFramebuffer(GLint srcX0,
                       GLint srcY0,
                       GLint srcX1,
                       GLint srcY1,
                       GLint dstX0,
                       GLint dstY0,
                       GLint dstX1,
                       GLint dstY1,
                       GLbitfield mask,
                       GLenum filter);
void glRenderbufferStorageMultisample(GLenum target,
                                      GLsizei samples,
                                      GLenum internalformat,
                                      GLsizei width,
                                      GLsizei height);
void glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
void* glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
void glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length);
void glBindVertexArray(GLuint array);
void glDeleteVertexArrays(GLsizei n, const GLuint* arrays);
void glGenVertexArrays(GLsizei n, GLuint* arrays);
GLboolean glIsVertexArray(GLuint array);

#pragma endregion

#pragma region GL_VERSION_3_1

constexpr int GL_SAMPLER_2D_RECT                             = 0x8B63;
constexpr int GL_SAMPLER_2D_RECT_SHADOW                      = 0x8B64;
constexpr int GL_SAMPLER_BUFFER                              = 0x8DC2;
constexpr int GL_INT_SAMPLER_2D_RECT                         = 0x8DCD;
constexpr int GL_INT_SAMPLER_BUFFER                          = 0x8DD0;
constexpr int GL_UNSIGNED_INT_SAMPLER_2D_RECT                = 0x8DD5;
constexpr int GL_UNSIGNED_INT_SAMPLER_BUFFER                 = 0x8DD8;
constexpr int GL_TEXTURE_BUFFER                              = 0x8C2A;
constexpr int GL_MAX_TEXTURE_BUFFER_SIZE                     = 0x8C2B;
constexpr int GL_TEXTURE_BINDING_BUFFER                      = 0x8C2C;
constexpr int GL_TEXTURE_BUFFER_DATA_STORE_BINDING           = 0x8C2D;
constexpr int GL_TEXTURE_RECTANGLE                           = 0x84F5;
constexpr int GL_TEXTURE_BINDING_RECTANGLE                   = 0x84F6;
constexpr int GL_PROXY_TEXTURE_RECTANGLE                     = 0x84F7;
constexpr int GL_MAX_RECTANGLE_TEXTURE_SIZE                  = 0x84F8;
constexpr int GL_R8_SNORM                                    = 0x8F94;
constexpr int GL_RG8_SNORM                                   = 0x8F95;
constexpr int GL_RGB8_SNORM                                  = 0x8F96;
constexpr int GL_RGBA8_SNORM                                 = 0x8F97;
constexpr int GL_R16_SNORM                                   = 0x8F98;
constexpr int GL_RG16_SNORM                                  = 0x8F99;
constexpr int GL_RGB16_SNORM                                 = 0x8F9A;
constexpr int GL_RGBA16_SNORM                                = 0x8F9B;
constexpr int GL_SIGNED_NORMALIZED                           = 0x8F9C;
constexpr int GL_PRIMITIVE_RESTART                           = 0x8F9D;
constexpr int GL_PRIMITIVE_RESTART_INDEX                     = 0x8F9E;
constexpr int GL_COPY_READ_BUFFER                            = 0x8F36;
constexpr int GL_COPY_WRITE_BUFFER                           = 0x8F37;
constexpr int GL_UNIFORM_BUFFER                              = 0x8A11;
constexpr int GL_UNIFORM_BUFFER_BINDING                      = 0x8A28;
constexpr int GL_UNIFORM_BUFFER_START                        = 0x8A29;
constexpr int GL_UNIFORM_BUFFER_SIZE                         = 0x8A2A;
constexpr int GL_MAX_VERTEX_UNIFORM_BLOCKS                   = 0x8A2B;
constexpr int GL_MAX_GEOMETRY_UNIFORM_BLOCKS                 = 0x8A2C;
constexpr int GL_MAX_FRAGMENT_UNIFORM_BLOCKS                 = 0x8A2D;
constexpr int GL_MAX_COMBINED_UNIFORM_BLOCKS                 = 0x8A2E;
constexpr int GL_MAX_UNIFORM_BUFFER_BINDINGS                 = 0x8A2F;
constexpr int GL_MAX_UNIFORM_BLOCK_SIZE                      = 0x8A30;
constexpr int GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS      = 0x8A31;
constexpr int GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS    = 0x8A32;
constexpr int GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS    = 0x8A33;
constexpr int GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT             = 0x8A34;
constexpr int GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH        = 0x8A35;
constexpr int GL_ACTIVE_UNIFORM_BLOCKS                       = 0x8A36;
constexpr int GL_UNIFORM_TYPE                                = 0x8A37;
constexpr int GL_UNIFORM_SIZE                                = 0x8A38;
constexpr int GL_UNIFORM_NAME_LENGTH                         = 0x8A39;
constexpr int GL_UNIFORM_BLOCK_INDEX                         = 0x8A3A;
constexpr int GL_UNIFORM_OFFSET                              = 0x8A3B;
constexpr int GL_UNIFORM_ARRAY_STRIDE                        = 0x8A3C;
constexpr int GL_UNIFORM_MATRIX_STRIDE                       = 0x8A3D;
constexpr int GL_UNIFORM_IS_ROW_MAJOR                        = 0x8A3E;
constexpr int GL_UNIFORM_BLOCK_BINDING                       = 0x8A3F;
constexpr int GL_UNIFORM_BLOCK_DATA_SIZE                     = 0x8A40;
constexpr int GL_UNIFORM_BLOCK_NAME_LENGTH                   = 0x8A41;
constexpr int GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS               = 0x8A42;
constexpr int GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES        = 0x8A43;
constexpr int GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER   = 0x8A44;
constexpr int GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER = 0x8A45;
constexpr int GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER = 0x8A46;
constexpr unsigned int GL_INVALID_INDEX                      = 0xFFFFFFFF;

void glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
void glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount);
void glTexBuffer(GLenum target, GLenum internalformat, GLuint buffer);
void glPrimitiveRestartIndex(GLuint index);
void glCopyBufferSubData(GLenum readTarget,
                         GLenum writeTarget,
                         GLintptr readOffset,
                         GLintptr writeOffset,
                         GLsizeiptr size);
void glGetUniformIndices(GLuint program,
                         GLsizei uniformCount,
                         const GLchar* const* uniformNames,
                         GLuint* uniformIndices);
void glGetActiveUniformsiv(GLuint program,
                           GLsizei uniformCount,
                           const GLuint* uniformIndices,
                           GLenum pname,
                           GLint* params);
void glGetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformName);
GLuint glGetUniformBlockIndex(GLuint program, const GLchar* uniformBlockName);
void glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params);
void glGetActiveUniformBlockName(GLuint program,
                                 GLuint uniformBlockIndex,
                                 GLsizei bufSize,
                                 GLsizei* length,
                                 GLchar* uniformBlockName);
void glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);

#pragma endregion

#pragma region GL_VERSION_3_2

typedef struct __GLsync* GLsync;
typedef khronos_uint64_t GLuint64;
typedef khronos_int64_t GLint64;

constexpr int GL_CONTEXT_CORE_PROFILE_BIT                  = 0x00000001;
constexpr int GL_CONTEXT_COMPATIBILITY_PROFILE_BIT         = 0x00000002;
constexpr int GL_LINES_ADJACENCY                           = 0x000A;
constexpr int GL_LINE_STRIP_ADJACENCY                      = 0x000B;
constexpr int GL_TRIANGLES_ADJACENCY                       = 0x000C;
constexpr int GL_TRIANGLE_STRIP_ADJACENCY                  = 0x000D;
constexpr int GL_PROGRAM_POINT_SIZE                        = 0x8642;
constexpr int GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS          = 0x8C29;
constexpr int GL_FRAMEBUFFER_ATTACHMENT_LAYERED            = 0x8DA7;
constexpr int GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS      = 0x8DA8;
constexpr int GL_GEOMETRY_SHADER                           = 0x8DD9;
constexpr int GL_GEOMETRY_VERTICES_OUT                     = 0x8916;
constexpr int GL_GEOMETRY_INPUT_TYPE                       = 0x8917;
constexpr int GL_GEOMETRY_OUTPUT_TYPE                      = 0x8918;
constexpr int GL_MAX_GEOMETRY_UNIFORM_COMPONENTS           = 0x8DDF;
constexpr int GL_MAX_GEOMETRY_OUTPUT_VERTICES              = 0x8DE0;
constexpr int GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS      = 0x8DE1;
constexpr int GL_MAX_VERTEX_OUTPUT_COMPONENTS              = 0x9122;
constexpr int GL_MAX_GEOMETRY_INPUT_COMPONENTS             = 0x9123;
constexpr int GL_MAX_GEOMETRY_OUTPUT_COMPONENTS            = 0x9124;
constexpr int GL_MAX_FRAGMENT_INPUT_COMPONENTS             = 0x9125;
constexpr int GL_CONTEXT_PROFILE_MASK                      = 0x9126;
constexpr int GL_DEPTH_CLAMP                               = 0x864F;
constexpr int GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION  = 0x8E4C;
constexpr int GL_FIRST_VERTEX_CONVENTION                   = 0x8E4D;
constexpr int GL_LAST_VERTEX_CONVENTION                    = 0x8E4E;
constexpr int GL_PROVOKING_VERTEX                          = 0x8E4F;
constexpr int GL_TEXTURE_CUBE_MAP_SEAMLESS                 = 0x884F;
constexpr int GL_MAX_SERVER_WAIT_TIMEOUT                   = 0x9111;
constexpr int GL_OBJECT_TYPE                               = 0x9112;
constexpr int GL_SYNC_CONDITION                            = 0x9113;
constexpr int GL_SYNC_STATUS                               = 0x9114;
constexpr int GL_SYNC_FLAGS                                = 0x9115;
constexpr int GL_SYNC_FENCE                                = 0x9116;
constexpr int GL_SYNC_GPU_COMMANDS_COMPLETE                = 0x9117;
constexpr int GL_UNSIGNALED                                = 0x9118;
constexpr int GL_SIGNALED                                  = 0x9119;
constexpr int GL_ALREADY_SIGNALED                          = 0x911A;
constexpr int GL_TIMEOUT_EXPIRED                           = 0x911B;
constexpr int GL_CONDITION_SATISFIED                       = 0x911C;
constexpr int GL_WAIT_FAILED                               = 0x911D;
constexpr unsigned long long GL_TIMEOUT_IGNORED            = 0xFFFFFFFFFFFFFFFF;
constexpr int GL_SYNC_FLUSH_COMMANDS_BIT                   = 0x00000001;
constexpr int GL_SAMPLE_POSITION                           = 0x8E50;
constexpr int GL_SAMPLE_MASK                               = 0x8E51;
constexpr int GL_SAMPLE_MASK_VALUE                         = 0x8E52;
constexpr int GL_MAX_SAMPLE_MASK_WORDS                     = 0x8E59;
constexpr int GL_TEXTURE_2D_MULTISAMPLE                    = 0x9100;
constexpr int GL_PROXY_TEXTURE_2D_MULTISAMPLE              = 0x9101;
constexpr int GL_TEXTURE_2D_MULTISAMPLE_ARRAY              = 0x9102;
constexpr int GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY        = 0x9103;
constexpr int GL_TEXTURE_BINDING_2D_MULTISAMPLE            = 0x9104;
constexpr int GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY      = 0x9105;
constexpr int GL_TEXTURE_SAMPLES                           = 0x9106;
constexpr int GL_TEXTURE_FIXED_SAMPLE_LOCATIONS            = 0x9107;
constexpr int GL_SAMPLER_2D_MULTISAMPLE                    = 0x9108;
constexpr int GL_INT_SAMPLER_2D_MULTISAMPLE                = 0x9109;
constexpr int GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE       = 0x910A;
constexpr int GL_SAMPLER_2D_MULTISAMPLE_ARRAY              = 0x910B;
constexpr int GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY          = 0x910C;
constexpr int GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY = 0x910D;
constexpr int GL_MAX_COLOR_TEXTURE_SAMPLES                 = 0x910E;
constexpr int GL_MAX_DEPTH_TEXTURE_SAMPLES                 = 0x910F;
constexpr int GL_MAX_INTEGER_SAMPLES                       = 0x9110;

void glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const void* indices, GLint basevertex);
void glDrawRangeElementsBaseVertex(GLenum mode,
                                   GLuint start,
                                   GLuint end,
                                   GLsizei count,
                                   GLenum type,
                                   const void* indices,
                                   GLint basevertex);
void glDrawElementsInstancedBaseVertex(GLenum mode,
                                       GLsizei count,
                                       GLenum type,
                                       const void* indices,
                                       GLsizei instancecount,
                                       GLint basevertex);
void glMultiDrawElementsBaseVertex(GLenum mode,
                                   const GLsizei* count,
                                   GLenum type,
                                   const void* const* indices,
                                   GLsizei drawcount,
                                   const GLint* basevertex);
void glProvokingVertex(GLenum mode);
GLsync glFenceSync(GLenum condition, GLbitfield flags);
GLboolean glIsSync(GLsync sync);
void glDeleteSync(GLsync sync);
GLenum glClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout);
void glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout);
void glGetInteger64v(GLenum pname, GLint64* data);
void glGetSynciv(GLsync sync, GLenum pname, GLsizei count, GLsizei* length, GLint* values);
void glGetInteger64i_v(GLenum target, GLuint index, GLint64* data);
void glGetBufferParameteri64v(GLenum target, GLenum pname, GLint64* params);
void glFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level);
void glTexImage2DMultisample(GLenum target,
                             GLsizei samples,
                             GLenum internalformat,
                             GLsizei width,
                             GLsizei height,
                             GLboolean fixedsamplelocations);
void glTexImage3DMultisample(GLenum target,
                             GLsizei samples,
                             GLenum internalformat,
                             GLsizei width,
                             GLsizei height,
                             GLsizei depth,
                             GLboolean fixedsamplelocations);
void glGetMultisamplefv(GLenum pname, GLuint index, GLfloat* val);
void glSampleMaski(GLuint maskNumber, GLbitfield mask);

#pragma endregion

#pragma region GL_VERSION_3_3

constexpr int GL_VERTEX_ATTRIB_ARRAY_DIVISOR  = 0x88FE;
constexpr int GL_SRC1_COLOR                   = 0x88F9;
constexpr int GL_ONE_MINUS_SRC1_COLOR         = 0x88FA;
constexpr int GL_ONE_MINUS_SRC1_ALPHA         = 0x88FB;
constexpr int GL_MAX_DUAL_SOURCE_DRAW_BUFFERS = 0x88FC;
constexpr int GL_ANY_SAMPLES_PASSED           = 0x8C2F;
constexpr int GL_SAMPLER_BINDING              = 0x8919;
constexpr int GL_RGB10_A2UI                   = 0x906F;
constexpr int GL_TEXTURE_SWIZZLE_R            = 0x8E42;
constexpr int GL_TEXTURE_SWIZZLE_G            = 0x8E43;
constexpr int GL_TEXTURE_SWIZZLE_B            = 0x8E44;
constexpr int GL_TEXTURE_SWIZZLE_A            = 0x8E45;
constexpr int GL_TEXTURE_SWIZZLE_RGBA         = 0x8E46;
constexpr int GL_TIME_ELAPSED                 = 0x88BF;
constexpr int GL_TIMESTAMP                    = 0x8E28;
constexpr int GL_INT_2_10_10_10_REV           = 0x8D9F;

void glBindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, const GLchar* name);
GLint glGetFragDataIndex(GLuint program, const GLchar* name);
void glGenSamplers(GLsizei count, GLuint* samplers);
void glDeleteSamplers(GLsizei count, const GLuint* samplers);
GLboolean glIsSampler(GLuint sampler);
void glBindSampler(GLuint unit, GLuint sampler);
void glSamplerParameteri(GLuint sampler, GLenum pname, GLint param);
void glSamplerParameteriv(GLuint sampler, GLenum pname, const GLint* param);
void glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param);
void glSamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat* param);
void glSamplerParameterIiv(GLuint sampler, GLenum pname, const GLint* param);
void glSamplerParameterIuiv(GLuint sampler, GLenum pname, const GLuint* param);
void glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint* params);
void glGetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint* params);
void glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat* params);
void glGetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint* params);
void glQueryCounter(GLuint id, GLenum target);
void glGetQueryObjecti64v(GLuint id, GLenum pname, GLint64* params);
void glGetQueryObjectui64v(GLuint id, GLenum pname, GLuint64* params);
void glVertexAttribDivisor(GLuint index, GLuint divisor);
void glVertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
void glVertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
void glVertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
void glVertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
void glVertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
void glVertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
void glVertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
void glVertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value);

#pragma endregion

#pragma region GL_VERSION_4_0

constexpr int GL_SAMPLE_SHADING                                     = 0x8C36;
constexpr int GL_MIN_SAMPLE_SHADING_VALUE                           = 0x8C37;
constexpr int GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET                  = 0x8E5E;
constexpr int GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET                  = 0x8E5F;
constexpr int GL_TEXTURE_CUBE_MAP_ARRAY                             = 0x9009;
constexpr int GL_TEXTURE_BINDING_CUBE_MAP_ARRAY                     = 0x900A;
constexpr int GL_PROXY_TEXTURE_CUBE_MAP_ARRAY                       = 0x900B;
constexpr int GL_SAMPLER_CUBE_MAP_ARRAY                             = 0x900C;
constexpr int GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW                      = 0x900D;
constexpr int GL_INT_SAMPLER_CUBE_MAP_ARRAY                         = 0x900E;
constexpr int GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY                = 0x900F;
constexpr int GL_DRAW_INDIRECT_BUFFER                               = 0x8F3F;
constexpr int GL_DRAW_INDIRECT_BUFFER_BINDING                       = 0x8F43;
constexpr int GL_GEOMETRY_SHADER_INVOCATIONS                        = 0x887F;
constexpr int GL_MAX_GEOMETRY_SHADER_INVOCATIONS                    = 0x8E5A;
constexpr int GL_MIN_FRAGMENT_INTERPOLATION_OFFSET                  = 0x8E5B;
constexpr int GL_MAX_FRAGMENT_INTERPOLATION_OFFSET                  = 0x8E5C;
constexpr int GL_FRAGMENT_INTERPOLATION_OFFSET_BITS                 = 0x8E5D;
constexpr int GL_MAX_VERTEX_STREAMS                                 = 0x8E71;
constexpr int GL_DOUBLE_VEC2                                        = 0x8FFC;
constexpr int GL_DOUBLE_VEC3                                        = 0x8FFD;
constexpr int GL_DOUBLE_VEC4                                        = 0x8FFE;
constexpr int GL_DOUBLE_MAT2                                        = 0x8F46;
constexpr int GL_DOUBLE_MAT3                                        = 0x8F47;
constexpr int GL_DOUBLE_MAT4                                        = 0x8F48;
constexpr int GL_DOUBLE_MAT2x3                                      = 0x8F49;
constexpr int GL_DOUBLE_MAT2x4                                      = 0x8F4A;
constexpr int GL_DOUBLE_MAT3x2                                      = 0x8F4B;
constexpr int GL_DOUBLE_MAT3x4                                      = 0x8F4C;
constexpr int GL_DOUBLE_MAT4x2                                      = 0x8F4D;
constexpr int GL_DOUBLE_MAT4x3                                      = 0x8F4E;
constexpr int GL_ACTIVE_SUBROUTINES                                 = 0x8DE5;
constexpr int GL_ACTIVE_SUBROUTINE_UNIFORMS                         = 0x8DE6;
constexpr int GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS                = 0x8E47;
constexpr int GL_ACTIVE_SUBROUTINE_MAX_LENGTH                       = 0x8E48;
constexpr int GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH               = 0x8E49;
constexpr int GL_MAX_SUBROUTINES                                    = 0x8DE7;
constexpr int GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS                   = 0x8DE8;
constexpr int GL_NUM_COMPATIBLE_SUBROUTINES                         = 0x8E4A;
constexpr int GL_COMPATIBLE_SUBROUTINES                             = 0x8E4B;
constexpr int GL_PATCHES                                            = 0x000E;
constexpr int GL_PATCH_VERTICES                                     = 0x8E72;
constexpr int GL_PATCH_DEFAULT_INNER_LEVEL                          = 0x8E73;
constexpr int GL_PATCH_DEFAULT_OUTER_LEVEL                          = 0x8E74;
constexpr int GL_TESS_CONTROL_OUTPUT_VERTICES                       = 0x8E75;
constexpr int GL_TESS_GEN_MODE                                      = 0x8E76;
constexpr int GL_TESS_GEN_SPACING                                   = 0x8E77;
constexpr int GL_TESS_GEN_VERTEX_ORDER                              = 0x8E78;
constexpr int GL_TESS_GEN_POINT_MODE                                = 0x8E79;
constexpr int GL_ISOLINES                                           = 0x8E7A;
constexpr int GL_FRACTIONAL_ODD                                     = 0x8E7B;
constexpr int GL_FRACTIONAL_EVEN                                    = 0x8E7C;
constexpr int GL_MAX_PATCH_VERTICES                                 = 0x8E7D;
constexpr int GL_MAX_TESS_GEN_LEVEL                                 = 0x8E7E;
constexpr int GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS                = 0x8E7F;
constexpr int GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS             = 0x8E80;
constexpr int GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS               = 0x8E81;
constexpr int GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS            = 0x8E82;
constexpr int GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS                 = 0x8E83;
constexpr int GL_MAX_TESS_PATCH_COMPONENTS                          = 0x8E84;
constexpr int GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS           = 0x8E85;
constexpr int GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS              = 0x8E86;
constexpr int GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS                    = 0x8E89;
constexpr int GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS                 = 0x8E8A;
constexpr int GL_MAX_TESS_CONTROL_INPUT_COMPONENTS                  = 0x886C;
constexpr int GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS               = 0x886D;
constexpr int GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS       = 0x8E1E;
constexpr int GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS    = 0x8E1F;
constexpr int GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER    = 0x84F0;
constexpr int GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER = 0x84F1;
constexpr int GL_TESS_EVALUATION_SHADER                             = 0x8E87;
constexpr int GL_TESS_CONTROL_SHADER                                = 0x8E88;
constexpr int GL_TRANSFORM_FEEDBACK                                 = 0x8E22;
constexpr int GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED                   = 0x8E23;
constexpr int GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE                   = 0x8E24;
constexpr int GL_TRANSFORM_FEEDBACK_BINDING                         = 0x8E25;
constexpr int GL_MAX_TRANSFORM_FEEDBACK_BUFFERS                     = 0x8E70;

void glMinSampleShading(GLfloat value);
void glBlendEquationi(GLuint buf, GLenum mode);
void glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
void glBlendFunci(GLuint buf, GLenum src, GLenum dst);
void glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
void glDrawArraysIndirect(GLenum mode, const void* indirect);
void glDrawElementsIndirect(GLenum mode, GLenum type, const void* indirect);
void glUniform1d(GLint location, GLdouble x);
void glUniform2d(GLint location, GLdouble x, GLdouble y);
void glUniform3d(GLint location, GLdouble x, GLdouble y, GLdouble z);
void glUniform4d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void glUniform1dv(GLint location, GLsizei count, const GLdouble* value);
void glUniform2dv(GLint location, GLsizei count, const GLdouble* value);
void glUniform3dv(GLint location, GLsizei count, const GLdouble* value);
void glUniform4dv(GLint location, GLsizei count, const GLdouble* value);
void glUniformMatrix2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
void glUniformMatrix3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
void glUniformMatrix4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
void glUniformMatrix2x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
void glUniformMatrix2x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
void glUniformMatrix3x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
void glUniformMatrix3x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
void glUniformMatrix4x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
void glUniformMatrix4x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
void glGetUniformdv(GLuint program, GLint location, GLdouble* params);
GLint glGetSubroutineUniformLocation(GLuint program, GLenum shadertype, const GLchar* name);
GLuint glGetSubroutineIndex(GLuint program, GLenum shadertype, const GLchar* name);
void glGetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint* values);
void glGetActiveSubroutineUniformName(GLuint program,
                                      GLenum shadertype,
                                      GLuint index,
                                      GLsizei bufSize,
                                      GLsizei* length,
                                      GLchar* name);
void glGetActiveSubroutineName(GLuint program,
                               GLenum shadertype,
                               GLuint index,
                               GLsizei bufSize,
                               GLsizei* length,
                               GLchar* name);
void glUniformSubroutinesuiv(GLenum shadertype, GLsizei count, const GLuint* indices);
void glGetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint* params);
void glGetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLint* values);
void glPatchParameteri(GLenum pname, GLint value);
void glPatchParameterfv(GLenum pname, const GLfloat* values);
void glBindTransformFeedback(GLenum target, GLuint id);
void glDeleteTransformFeedbacks(GLsizei n, const GLuint* ids);
void glGenTransformFeedbacks(GLsizei n, GLuint* ids);
GLboolean glIsTransformFeedback(GLuint id);
void glPauseTransformFeedback();
void glResumeTransformFeedback();
void glDrawTransformFeedback(GLenum mode, GLuint id);
void glDrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream);
void glBeginQueryIndexed(GLenum target, GLuint index, GLuint id);
void glEndQueryIndexed(GLenum target, GLuint index);
void glGetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLint* params);

#pragma endregion

#pragma region GL_VERSION_4_1

constexpr int GL_FIXED                            = 0x140C;
constexpr int GL_IMPLEMENTATION_COLOR_READ_TYPE   = 0x8B9A;
constexpr int GL_IMPLEMENTATION_COLOR_READ_FORMAT = 0x8B9B;
constexpr int GL_LOW_FLOAT                        = 0x8DF0;
constexpr int GL_MEDIUM_FLOAT                     = 0x8DF1;
constexpr int GL_HIGH_FLOAT                       = 0x8DF2;
constexpr int GL_LOW_INT                          = 0x8DF3;
constexpr int GL_MEDIUM_INT                       = 0x8DF4;
constexpr int GL_HIGH_INT                         = 0x8DF5;
constexpr int GL_SHADER_COMPILER                  = 0x8DFA;
constexpr int GL_SHADER_BINARY_FORMATS            = 0x8DF8;
constexpr int GL_NUM_SHADER_BINARY_FORMATS        = 0x8DF9;
constexpr int GL_MAX_VERTEX_UNIFORM_VECTORS       = 0x8DFB;
constexpr int GL_MAX_VARYING_VECTORS              = 0x8DFC;
constexpr int GL_MAX_FRAGMENT_UNIFORM_VECTORS     = 0x8DFD;
constexpr int GL_RGB565                           = 0x8D62;
constexpr int GL_PROGRAM_BINARY_RETRIEVABLE_HINT  = 0x8257;
constexpr int GL_PROGRAM_BINARY_LENGTH            = 0x8741;
constexpr int GL_NUM_PROGRAM_BINARY_FORMATS       = 0x87FE;
constexpr int GL_PROGRAM_BINARY_FORMATS           = 0x87FF;
constexpr int GL_VERTEX_SHADER_BIT                = 0x00000001;
constexpr int GL_FRAGMENT_SHADER_BIT              = 0x00000002;
constexpr int GL_GEOMETRY_SHADER_BIT              = 0x00000004;
constexpr int GL_TESS_CONTROL_SHADER_BIT          = 0x00000008;
constexpr int GL_TESS_EVALUATION_SHADER_BIT       = 0x00000010;
constexpr int GL_ALL_SHADER_BITS                  = 0xFFFFFFFF;
constexpr int GL_PROGRAM_SEPARABLE                = 0x8258;
constexpr int GL_ACTIVE_PROGRAM                   = 0x8259;
constexpr int GL_PROGRAM_PIPELINE_BINDING         = 0x825A;
constexpr int GL_MAX_VIEWPORTS                    = 0x825B;
constexpr int GL_VIEWPORT_SUBPIXEL_BITS           = 0x825C;
constexpr int GL_VIEWPORT_BOUNDS_RANGE            = 0x825D;
constexpr int GL_LAYER_PROVOKING_VERTEX           = 0x825E;
constexpr int GL_VIEWPORT_INDEX_PROVOKING_VERTEX  = 0x825F;
constexpr int GL_UNDEFINED_VERTEX                 = 0x8260;

void glReleaseShaderCompiler();
void glShaderBinary(GLsizei count, const GLuint* shaders, GLenum binaryformat, const void* binary, GLsizei length);
void glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision);
void glDepthRangef(GLfloat n, GLfloat f);
void glClearDepthf(GLfloat d);
void glGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei* length, GLenum* binaryFormat, void* binary);
void glProgramBinary(GLuint program, GLenum binaryFormat, const void* binary, GLsizei length);
void glProgramParameteri(GLuint program, GLenum pname, GLint value);
void glUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program);
void glActiveShaderProgram(GLuint pipeline, GLuint program);
GLuint glCreateShaderProgramv(GLenum type, GLsizei count, const GLchar* const* strings);
void glBindProgramPipeline(GLuint pipeline);
void glDeleteProgramPipelines(GLsizei n, const GLuint* pipelines);
void glGenProgramPipelines(GLsizei n, GLuint* pipelines);
GLboolean glIsProgramPipeline(GLuint pipeline);
void glGetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint* params);
void glProgramUniform1i(GLuint program, GLint location, GLint v0);
void glProgramUniform1iv(GLuint program, GLint location, GLsizei count, const GLint* value);
void glProgramUniform1f(GLuint program, GLint location, GLfloat v0);
void glProgramUniform1fv(GLuint program, GLint location, GLsizei count, const GLfloat* value);
void glProgramUniform1d(GLuint program, GLint location, GLdouble v0);
void glProgramUniform1dv(GLuint program, GLint location, GLsizei count, const GLdouble* value);
void glProgramUniform1ui(GLuint program, GLint location, GLuint v0);
void glProgramUniform1uiv(GLuint program, GLint location, GLsizei count, const GLuint* value);
void glProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1);
void glProgramUniform2iv(GLuint program, GLint location, GLsizei count, const GLint* value);
void glProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1);
void glProgramUniform2fv(GLuint program, GLint location, GLsizei count, const GLfloat* value);
void glProgramUniform2d(GLuint program, GLint location, GLdouble v0, GLdouble v1);
void glProgramUniform2dv(GLuint program, GLint location, GLsizei count, const GLdouble* value);
void glProgramUniform2ui(GLuint program, GLint location, GLuint v0, GLuint v1);
void glProgramUniform2uiv(GLuint program, GLint location, GLsizei count, const GLuint* value);
void glProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
void glProgramUniform3iv(GLuint program, GLint location, GLsizei count, const GLint* value);
void glProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
void glProgramUniform3fv(GLuint program, GLint location, GLsizei count, const GLfloat* value);
void glProgramUniform3d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
void glProgramUniform3dv(GLuint program, GLint location, GLsizei count, const GLdouble* value);
void glProgramUniform3ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
void glProgramUniform3uiv(GLuint program, GLint location, GLsizei count, const GLuint* value);
void glProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
void glProgramUniform4iv(GLuint program, GLint location, GLsizei count, const GLint* value);
void glProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
void glProgramUniform4fv(GLuint program, GLint location, GLsizei count, const GLfloat* value);
void glProgramUniform4d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
void glProgramUniform4dv(GLuint program, GLint location, GLsizei count, const GLdouble* value);
void glProgramUniform4ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
void glProgramUniform4uiv(GLuint program, GLint location, GLsizei count, const GLuint* value);
void glProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
void glProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
void glProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
void glProgramUniformMatrix2dv(GLuint program,
                               GLint location,
                               GLsizei count,
                               GLboolean transpose,
                               const GLdouble* value);
void glProgramUniformMatrix3dv(GLuint program,
                               GLint location,
                               GLsizei count,
                               GLboolean transpose,
                               const GLdouble* value);
void glProgramUniformMatrix4dv(GLuint program,
                               GLint location,
                               GLsizei count,
                               GLboolean transpose,
                               const GLdouble* value);
void glProgramUniformMatrix2x3fv(GLuint program,
                                 GLint location,
                                 GLsizei count,
                                 GLboolean transpose,
                                 const GLfloat* value);
void glProgramUniformMatrix3x2fv(GLuint program,
                                 GLint location,
                                 GLsizei count,
                                 GLboolean transpose,
                                 const GLfloat* value);
void glProgramUniformMatrix2x4fv(GLuint program,
                                 GLint location,
                                 GLsizei count,
                                 GLboolean transpose,
                                 const GLfloat* value);
void glProgramUniformMatrix4x2fv(GLuint program,
                                 GLint location,
                                 GLsizei count,
                                 GLboolean transpose,
                                 const GLfloat* value);
void glProgramUniformMatrix3x4fv(GLuint program,
                                 GLint location,
                                 GLsizei count,
                                 GLboolean transpose,
                                 const GLfloat* value);
void glProgramUniformMatrix4x3fv(GLuint program,
                                 GLint location,
                                 GLsizei count,
                                 GLboolean transpose,
                                 const GLfloat* value);
void glProgramUniformMatrix2x3dv(GLuint program,
                                 GLint location,
                                 GLsizei count,
                                 GLboolean transpose,
                                 const GLdouble* value);
void glProgramUniformMatrix3x2dv(GLuint program,
                                 GLint location,
                                 GLsizei count,
                                 GLboolean transpose,
                                 const GLdouble* value);
void glProgramUniformMatrix2x4dv(GLuint program,
                                 GLint location,
                                 GLsizei count,
                                 GLboolean transpose,
                                 const GLdouble* value);
void glProgramUniformMatrix4x2dv(GLuint program,
                                 GLint location,
                                 GLsizei count,
                                 GLboolean transpose,
                                 const GLdouble* value);
void glProgramUniformMatrix3x4dv(GLuint program,
                                 GLint location,
                                 GLsizei count,
                                 GLboolean transpose,
                                 const GLdouble* value);
void glProgramUniformMatrix4x3dv(GLuint program,
                                 GLint location,
                                 GLsizei count,
                                 GLboolean transpose,
                                 const GLdouble* value);
void glValidateProgramPipeline(GLuint pipeline);
void glGetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
void glVertexAttribL1d(GLuint index, GLdouble x);
void glVertexAttribL2d(GLuint index, GLdouble x, GLdouble y);
void glVertexAttribL3d(GLuint index, GLdouble x, GLdouble y, GLdouble z);
void glVertexAttribL4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void glVertexAttribL1dv(GLuint index, const GLdouble* v);
void glVertexAttribL2dv(GLuint index, const GLdouble* v);
void glVertexAttribL3dv(GLuint index, const GLdouble* v);
void glVertexAttribL4dv(GLuint index, const GLdouble* v);
void glVertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer);
void glGetVertexAttribLdv(GLuint index, GLenum pname, GLdouble* params);
void glViewportArrayv(GLuint first, GLsizei count, const GLfloat* v);
void glViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
void glViewportIndexedfv(GLuint index, const GLfloat* v);
void glScissorArrayv(GLuint first, GLsizei count, const GLint* v);
void glScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
void glScissorIndexedv(GLuint index, const GLint* v);
void glDepthRangeArrayv(GLuint first, GLsizei count, const GLdouble* v);
void glDepthRangeIndexed(GLuint index, GLdouble n, GLdouble f);
void glGetFloati_v(GLenum target, GLuint index, GLfloat* data);
void glGetDoublei_v(GLenum target, GLuint index, GLdouble* data);

#pragma endregion

#pragma region GL_VERSION_4_2

constexpr int GL_COPY_READ_BUFFER_BINDING                                   = 0x8F36;
constexpr int GL_COPY_WRITE_BUFFER_BINDING                                  = 0x8F37;
constexpr int GL_TRANSFORM_FEEDBACK_ACTIVE                                  = 0x8E24;
constexpr int GL_TRANSFORM_FEEDBACK_PAUSED                                  = 0x8E23;
constexpr int GL_UNPACK_COMPRESSED_BLOCK_WIDTH                              = 0x9127;
constexpr int GL_UNPACK_COMPRESSED_BLOCK_HEIGHT                             = 0x9128;
constexpr int GL_UNPACK_COMPRESSED_BLOCK_DEPTH                              = 0x9129;
constexpr int GL_UNPACK_COMPRESSED_BLOCK_SIZE                               = 0x912A;
constexpr int GL_PACK_COMPRESSED_BLOCK_WIDTH                                = 0x912B;
constexpr int GL_PACK_COMPRESSED_BLOCK_HEIGHT                               = 0x912C;
constexpr int GL_PACK_COMPRESSED_BLOCK_DEPTH                                = 0x912D;
constexpr int GL_PACK_COMPRESSED_BLOCK_SIZE                                 = 0x912E;
constexpr int GL_NUM_SAMPLE_COUNTS                                          = 0x9380;
constexpr int GL_MIN_MAP_BUFFER_ALIGNMENT                                   = 0x90BC;
constexpr int GL_ATOMIC_COUNTER_BUFFER                                      = 0x92C0;
constexpr int GL_ATOMIC_COUNTER_BUFFER_BINDING                              = 0x92C1;
constexpr int GL_ATOMIC_COUNTER_BUFFER_START                                = 0x92C2;
constexpr int GL_ATOMIC_COUNTER_BUFFER_SIZE                                 = 0x92C3;
constexpr int GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE                            = 0x92C4;
constexpr int GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS               = 0x92C5;
constexpr int GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES        = 0x92C6;
constexpr int GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER          = 0x92C7;
constexpr int GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER    = 0x92C8;
constexpr int GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER = 0x92C9;
constexpr int GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER        = 0x92CA;
constexpr int GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER        = 0x92CB;
constexpr int GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS                          = 0x92CC;
constexpr int GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS                    = 0x92CD;
constexpr int GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS                 = 0x92CE;
constexpr int GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS                        = 0x92CF;
constexpr int GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS                        = 0x92D0;
constexpr int GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS                        = 0x92D1;
constexpr int GL_MAX_VERTEX_ATOMIC_COUNTERS                                 = 0x92D2;
constexpr int GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS                           = 0x92D3;
constexpr int GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS                        = 0x92D4;
constexpr int GL_MAX_GEOMETRY_ATOMIC_COUNTERS                               = 0x92D5;
constexpr int GL_MAX_FRAGMENT_ATOMIC_COUNTERS                               = 0x92D6;
constexpr int GL_MAX_COMBINED_ATOMIC_COUNTERS                               = 0x92D7;
constexpr int GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE                             = 0x92D8;
constexpr int GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS                         = 0x92DC;
constexpr int GL_ACTIVE_ATOMIC_COUNTER_BUFFERS                              = 0x92D9;
constexpr int GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX                        = 0x92DA;
constexpr int GL_UNSIGNED_INT_ATOMIC_COUNTER                                = 0x92DB;
constexpr int GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT                            = 0x00000001;
constexpr int GL_ELEMENT_ARRAY_BARRIER_BIT                                  = 0x00000002;
constexpr int GL_UNIFORM_BARRIER_BIT                                        = 0x00000004;
constexpr int GL_TEXTURE_FETCH_BARRIER_BIT                                  = 0x00000008;
constexpr int GL_SHADER_IMAGE_ACCESS_BARRIER_BIT                            = 0x00000020;
constexpr int GL_COMMAND_BARRIER_BIT                                        = 0x00000040;
constexpr int GL_PIXEL_BUFFER_BARRIER_BIT                                   = 0x00000080;
constexpr int GL_TEXTURE_UPDATE_BARRIER_BIT                                 = 0x00000100;
constexpr int GL_BUFFER_UPDATE_BARRIER_BIT                                  = 0x00000200;
constexpr int GL_FRAMEBUFFER_BARRIER_BIT                                    = 0x00000400;
constexpr int GL_TRANSFORM_FEEDBACK_BARRIER_BIT                             = 0x00000800;
constexpr int GL_ATOMIC_COUNTER_BARRIER_BIT                                 = 0x00001000;
constexpr int GL_ALL_BARRIER_BITS                                           = 0xFFFFFFFF;
constexpr int GL_MAX_IMAGE_UNITS                                            = 0x8F38;
constexpr int GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS              = 0x8F39;
constexpr int GL_IMAGE_BINDING_NAME                                         = 0x8F3A;
constexpr int GL_IMAGE_BINDING_LEVEL                                        = 0x8F3B;
constexpr int GL_IMAGE_BINDING_LAYERED                                      = 0x8F3C;
constexpr int GL_IMAGE_BINDING_LAYER                                        = 0x8F3D;
constexpr int GL_IMAGE_BINDING_ACCESS                                       = 0x8F3E;
constexpr int GL_IMAGE_1D                                                   = 0x904C;
constexpr int GL_IMAGE_2D                                                   = 0x904D;
constexpr int GL_IMAGE_3D                                                   = 0x904E;
constexpr int GL_IMAGE_2D_RECT                                              = 0x904F;
constexpr int GL_IMAGE_CUBE                                                 = 0x9050;
constexpr int GL_IMAGE_BUFFER                                               = 0x9051;
constexpr int GL_IMAGE_1D_ARRAY                                             = 0x9052;
constexpr int GL_IMAGE_2D_ARRAY                                             = 0x9053;
constexpr int GL_IMAGE_CUBE_MAP_ARRAY                                       = 0x9054;
constexpr int GL_IMAGE_2D_MULTISAMPLE                                       = 0x9055;
constexpr int GL_IMAGE_2D_MULTISAMPLE_ARRAY                                 = 0x9056;
constexpr int GL_INT_IMAGE_1D                                               = 0x9057;
constexpr int GL_INT_IMAGE_2D                                               = 0x9058;
constexpr int GL_INT_IMAGE_3D                                               = 0x9059;
constexpr int GL_INT_IMAGE_2D_RECT                                          = 0x905A;
constexpr int GL_INT_IMAGE_CUBE                                             = 0x905B;
constexpr int GL_INT_IMAGE_BUFFER                                           = 0x905C;
constexpr int GL_INT_IMAGE_1D_ARRAY                                         = 0x905D;
constexpr int GL_INT_IMAGE_2D_ARRAY                                         = 0x905E;
constexpr int GL_INT_IMAGE_CUBE_MAP_ARRAY                                   = 0x905F;
constexpr int GL_INT_IMAGE_2D_MULTISAMPLE                                   = 0x9060;
constexpr int GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY                             = 0x9061;
constexpr int GL_UNSIGNED_INT_IMAGE_1D                                      = 0x9062;
constexpr int GL_UNSIGNED_INT_IMAGE_2D                                      = 0x9063;
constexpr int GL_UNSIGNED_INT_IMAGE_3D                                      = 0x9064;
constexpr int GL_UNSIGNED_INT_IMAGE_2D_RECT                                 = 0x9065;
constexpr int GL_UNSIGNED_INT_IMAGE_CUBE                                    = 0x9066;
constexpr int GL_UNSIGNED_INT_IMAGE_BUFFER                                  = 0x9067;
constexpr int GL_UNSIGNED_INT_IMAGE_1D_ARRAY                                = 0x9068;
constexpr int GL_UNSIGNED_INT_IMAGE_2D_ARRAY                                = 0x9069;
constexpr int GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY                          = 0x906A;
constexpr int GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE                          = 0x906B;
constexpr int GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY                    = 0x906C;
constexpr int GL_MAX_IMAGE_SAMPLES                                          = 0x906D;
constexpr int GL_IMAGE_BINDING_FORMAT                                       = 0x906E;
constexpr int GL_IMAGE_FORMAT_COMPATIBILITY_TYPE                            = 0x90C7;
constexpr int GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE                         = 0x90C8;
constexpr int GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS                        = 0x90C9;
constexpr int GL_MAX_VERTEX_IMAGE_UNIFORMS                                  = 0x90CA;
constexpr int GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS                            = 0x90CB;
constexpr int GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS                         = 0x90CC;
constexpr int GL_MAX_GEOMETRY_IMAGE_UNIFORMS                                = 0x90CD;
constexpr int GL_MAX_FRAGMENT_IMAGE_UNIFORMS                                = 0x90CE;
constexpr int GL_MAX_COMBINED_IMAGE_UNIFORMS                                = 0x90CF;
constexpr int GL_COMPRESSED_RGBA_BPTC_UNORM                                 = 0x8E8C;
constexpr int GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM                           = 0x8E8D;
constexpr int GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT                           = 0x8E8E;
constexpr int GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT                         = 0x8E8F;
constexpr int GL_TEXTURE_IMMUTABLE_FORMAT                                   = 0x912F;

void glDrawArraysInstancedBaseInstance(GLenum mode,
                                       GLint first,
                                       GLsizei count,
                                       GLsizei instancecount,
                                       GLuint baseinstance);
void glDrawElementsInstancedBaseInstance(GLenum mode,
                                         GLsizei count,
                                         GLenum type,
                                         const void* indices,
                                         GLsizei instancecount,
                                         GLuint baseinstance);
void glDrawElementsInstancedBaseVertexBaseInstance(GLenum mode,
                                                   GLsizei count,
                                                   GLenum type,
                                                   const void* indices,
                                                   GLsizei instancecount,
                                                   GLint basevertex,
                                                   GLuint baseinstance);
void glGetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint* params);
void glGetActiveAtomicCounterBufferiv(GLuint program, GLuint bufferIndex, GLenum pname, GLint* params);
void glBindImageTexture(GLuint unit,
                        GLuint texture,
                        GLint level,
                        GLboolean layered,
                        GLint layer,
                        GLenum access,
                        GLenum format);
void glMemoryBarrier(GLbitfield barriers);
void glTexStorage1D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
void glTexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
void glTexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
void glDrawTransformFeedbackInstanced(GLenum mode, GLuint id, GLsizei instancecount);
void glDrawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);

#pragma endregion

#pragma region GL_VERSION_4_3

typedef void (*GLDEBUGPROC)(GLenum source,
                            GLenum type,
                            GLuint id,
                            GLenum severity,
                            GLsizei length,
                            const GLchar* message,
                            const void* userParam);

constexpr int GL_NUM_SHADING_LANGUAGE_VERSIONS                      = 0x82E9;
constexpr int GL_VERTEX_ATTRIB_ARRAY_LONG                           = 0x874E;
constexpr int GL_COMPRESSED_RGB8_ETC2                               = 0x9274;
constexpr int GL_COMPRESSED_SRGB8_ETC2                              = 0x9275;
constexpr int GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2           = 0x9276;
constexpr int GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2          = 0x9277;
constexpr int GL_COMPRESSED_RGBA8_ETC2_EAC                          = 0x9278;
constexpr int GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC                   = 0x9279;
constexpr int GL_COMPRESSED_R11_EAC                                 = 0x9270;
constexpr int GL_COMPRESSED_SIGNED_R11_EAC                          = 0x9271;
constexpr int GL_COMPRESSED_RG11_EAC                                = 0x9272;
constexpr int GL_COMPRESSED_SIGNED_RG11_EAC                         = 0x9273;
constexpr int GL_PRIMITIVE_RESTART_FIXED_INDEX                      = 0x8D69;
constexpr int GL_ANY_SAMPLES_PASSED_CONSERVATIVE                    = 0x8D6A;
constexpr int GL_MAX_ELEMENT_INDEX                                  = 0x8D6B;
constexpr int GL_COMPUTE_SHADER                                     = 0x91B9;
constexpr int GL_MAX_COMPUTE_UNIFORM_BLOCKS                         = 0x91BB;
constexpr int GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS                    = 0x91BC;
constexpr int GL_MAX_COMPUTE_IMAGE_UNIFORMS                         = 0x91BD;
constexpr int GL_MAX_COMPUTE_SHARED_MEMORY_SIZE                     = 0x8262;
constexpr int GL_MAX_COMPUTE_UNIFORM_COMPONENTS                     = 0x8263;
constexpr int GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS                 = 0x8264;
constexpr int GL_MAX_COMPUTE_ATOMIC_COUNTERS                        = 0x8265;
constexpr int GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS            = 0x8266;
constexpr int GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS                 = 0x90EB;
constexpr int GL_MAX_COMPUTE_WORK_GROUP_COUNT                       = 0x91BE;
constexpr int GL_MAX_COMPUTE_WORK_GROUP_SIZE                        = 0x91BF;
constexpr int GL_COMPUTE_WORK_GROUP_SIZE                            = 0x8267;
constexpr int GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER         = 0x90EC;
constexpr int GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER = 0x90ED;
constexpr int GL_DISPATCH_INDIRECT_BUFFER                           = 0x90EE;
constexpr int GL_DISPATCH_INDIRECT_BUFFER_BINDING                   = 0x90EF;
constexpr int GL_COMPUTE_SHADER_BIT                                 = 0x00000020;
constexpr int GL_DEBUG_OUTPUT_SYNCHRONOUS                           = 0x8242;
constexpr int GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH                   = 0x8243;
constexpr int GL_DEBUG_CALLBACK_FUNCTION                            = 0x8244;
constexpr int GL_DEBUG_CALLBACK_USER_PARAM                          = 0x8245;
constexpr int GL_DEBUG_SOURCE_API                                   = 0x8246;
constexpr int GL_DEBUG_SOURCE_WINDOW_SYSTEM                         = 0x8247;
constexpr int GL_DEBUG_SOURCE_SHADER_COMPILER                       = 0x8248;
constexpr int GL_DEBUG_SOURCE_THIRD_PARTY                           = 0x8249;
constexpr int GL_DEBUG_SOURCE_APPLICATION                           = 0x824A;
constexpr int GL_DEBUG_SOURCE_OTHER                                 = 0x824B;
constexpr int GL_DEBUG_TYPE_ERROR                                   = 0x824C;
constexpr int GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR                     = 0x824D;
constexpr int GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR                      = 0x824E;
constexpr int GL_DEBUG_TYPE_PORTABILITY                             = 0x824F;
constexpr int GL_DEBUG_TYPE_PERFORMANCE                             = 0x8250;
constexpr int GL_DEBUG_TYPE_OTHER                                   = 0x8251;
constexpr int GL_MAX_DEBUG_MESSAGE_LENGTH                           = 0x9143;
constexpr int GL_MAX_DEBUG_LOGGED_MESSAGES                          = 0x9144;
constexpr int GL_DEBUG_LOGGED_MESSAGES                              = 0x9145;
constexpr int GL_DEBUG_SEVERITY_HIGH                                = 0x9146;
constexpr int GL_DEBUG_SEVERITY_MEDIUM                              = 0x9147;
constexpr int GL_DEBUG_SEVERITY_LOW                                 = 0x9148;
constexpr int GL_DEBUG_TYPE_MARKER                                  = 0x8268;
constexpr int GL_DEBUG_TYPE_PUSH_GROUP                              = 0x8269;
constexpr int GL_DEBUG_TYPE_POP_GROUP                               = 0x826A;
constexpr int GL_DEBUG_SEVERITY_NOTIFICATION                        = 0x826B;
constexpr int GL_MAX_DEBUG_GROUP_STACK_DEPTH                        = 0x826C;
constexpr int GL_DEBUG_GROUP_STACK_DEPTH                            = 0x826D;
constexpr int GL_BUFFER                                             = 0x82E0;
constexpr int GL_SHADER                                             = 0x82E1;
constexpr int GL_PROGRAM                                            = 0x82E2;
constexpr int GL_QUERY                                              = 0x82E3;
constexpr int GL_PROGRAM_PIPELINE                                   = 0x82E4;
constexpr int GL_SAMPLER                                            = 0x82E6;
constexpr int GL_MAX_LABEL_LENGTH                                   = 0x82E8;
constexpr int GL_DEBUG_OUTPUT                                       = 0x92E0;
constexpr int GL_CONTEXT_FLAG_DEBUG_BIT                             = 0x00000002;
constexpr int GL_MAX_UNIFORM_LOCATIONS                              = 0x826E;
constexpr int GL_FRAMEBUFFER_DEFAULT_WIDTH                          = 0x9310;
constexpr int GL_FRAMEBUFFER_DEFAULT_HEIGHT                         = 0x9311;
constexpr int GL_FRAMEBUFFER_DEFAULT_LAYERS                         = 0x9312;
constexpr int GL_FRAMEBUFFER_DEFAULT_SAMPLES                        = 0x9313;
constexpr int GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS         = 0x9314;
constexpr int GL_MAX_FRAMEBUFFER_WIDTH                              = 0x9315;
constexpr int GL_MAX_FRAMEBUFFER_HEIGHT                             = 0x9316;
constexpr int GL_MAX_FRAMEBUFFER_LAYERS                             = 0x9317;
constexpr int GL_MAX_FRAMEBUFFER_SAMPLES                            = 0x9318;
constexpr int GL_INTERNALFORMAT_SUPPORTED                           = 0x826F;
constexpr int GL_INTERNALFORMAT_PREFERRED                           = 0x8270;
constexpr int GL_INTERNALFORMAT_RED_SIZE                            = 0x8271;
constexpr int GL_INTERNALFORMAT_GREEN_SIZE                          = 0x8272;
constexpr int GL_INTERNALFORMAT_BLUE_SIZE                           = 0x8273;
constexpr int GL_INTERNALFORMAT_ALPHA_SIZE                          = 0x8274;
constexpr int GL_INTERNALFORMAT_DEPTH_SIZE                          = 0x8275;
constexpr int GL_INTERNALFORMAT_STENCIL_SIZE                        = 0x8276;
constexpr int GL_INTERNALFORMAT_SHARED_SIZE                         = 0x8277;
constexpr int GL_INTERNALFORMAT_RED_TYPE                            = 0x8278;
constexpr int GL_INTERNALFORMAT_GREEN_TYPE                          = 0x8279;
constexpr int GL_INTERNALFORMAT_BLUE_TYPE                           = 0x827A;
constexpr int GL_INTERNALFORMAT_ALPHA_TYPE                          = 0x827B;
constexpr int GL_INTERNALFORMAT_DEPTH_TYPE                          = 0x827C;
constexpr int GL_INTERNALFORMAT_STENCIL_TYPE                        = 0x827D;
constexpr int GL_MAX_WIDTH                                          = 0x827E;
constexpr int GL_MAX_HEIGHT                                         = 0x827F;
constexpr int GL_MAX_DEPTH                                          = 0x8280;
constexpr int GL_MAX_LAYERS                                         = 0x8281;
constexpr int GL_MAX_COMBINED_DIMENSIONS                            = 0x8282;
constexpr int GL_COLOR_COMPONENTS                                   = 0x8283;
constexpr int GL_DEPTH_COMPONENTS                                   = 0x8284;
constexpr int GL_STENCIL_COMPONENTS                                 = 0x8285;
constexpr int GL_COLOR_RENDERABLE                                   = 0x8286;
constexpr int GL_DEPTH_RENDERABLE                                   = 0x8287;
constexpr int GL_STENCIL_RENDERABLE                                 = 0x8288;
constexpr int GL_FRAMEBUFFER_RENDERABLE                             = 0x8289;
constexpr int GL_FRAMEBUFFER_RENDERABLE_LAYERED                     = 0x828A;
constexpr int GL_FRAMEBUFFER_BLEND                                  = 0x828B;
constexpr int GL_READ_PIXELS                                        = 0x828C;
constexpr int GL_READ_PIXELS_FORMAT                                 = 0x828D;
constexpr int GL_READ_PIXELS_TYPE                                   = 0x828E;
constexpr int GL_TEXTURE_IMAGE_FORMAT                               = 0x828F;
constexpr int GL_TEXTURE_IMAGE_TYPE                                 = 0x8290;
constexpr int GL_GET_TEXTURE_IMAGE_FORMAT                           = 0x8291;
constexpr int GL_GET_TEXTURE_IMAGE_TYPE                             = 0x8292;
constexpr int GL_MIPMAP                                             = 0x8293;
constexpr int GL_MANUAL_GENERATE_MIPMAP                             = 0x8294;
constexpr int GL_AUTO_GENERATE_MIPMAP                               = 0x8295;
constexpr int GL_COLOR_ENCODING                                     = 0x8296;
constexpr int GL_SRGB_READ                                          = 0x8297;
constexpr int GL_SRGB_WRITE                                         = 0x8298;
constexpr int GL_FILTER                                             = 0x829A;
constexpr int GL_VERTEX_TEXTURE                                     = 0x829B;
constexpr int GL_TESS_CONTROL_TEXTURE                               = 0x829C;
constexpr int GL_TESS_EVALUATION_TEXTURE                            = 0x829D;
constexpr int GL_GEOMETRY_TEXTURE                                   = 0x829E;
constexpr int GL_FRAGMENT_TEXTURE                                   = 0x829F;
constexpr int GL_COMPUTE_TEXTURE                                    = 0x82A0;
constexpr int GL_TEXTURE_SHADOW                                     = 0x82A1;
constexpr int GL_TEXTURE_GATHER                                     = 0x82A2;
constexpr int GL_TEXTURE_GATHER_SHADOW                              = 0x82A3;
constexpr int GL_SHADER_IMAGE_LOAD                                  = 0x82A4;
constexpr int GL_SHADER_IMAGE_STORE                                 = 0x82A5;
constexpr int GL_SHADER_IMAGE_ATOMIC                                = 0x82A6;
constexpr int GL_IMAGE_TEXEL_SIZE                                   = 0x82A7;
constexpr int GL_IMAGE_COMPATIBILITY_CLASS                          = 0x82A8;
constexpr int GL_IMAGE_PIXEL_FORMAT                                 = 0x82A9;
constexpr int GL_IMAGE_PIXEL_TYPE                                   = 0x82AA;
constexpr int GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST                = 0x82AC;
constexpr int GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST              = 0x82AD;
constexpr int GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE               = 0x82AE;
constexpr int GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE             = 0x82AF;
constexpr int GL_TEXTURE_COMPRESSED_BLOCK_WIDTH                     = 0x82B1;
constexpr int GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT                    = 0x82B2;
constexpr int GL_TEXTURE_COMPRESSED_BLOCK_SIZE                      = 0x82B3;
constexpr int GL_CLEAR_BUFFER                                       = 0x82B4;
constexpr int GL_TEXTURE_VIEW                                       = 0x82B5;
constexpr int GL_VIEW_COMPATIBILITY_CLASS                           = 0x82B6;
constexpr int GL_FULL_SUPPORT                                       = 0x82B7;
constexpr int GL_CAVEAT_SUPPORT                                     = 0x82B8;
constexpr int GL_IMAGE_CLASS_4_X_32                                 = 0x82B9;
constexpr int GL_IMAGE_CLASS_2_X_32                                 = 0x82BA;
constexpr int GL_IMAGE_CLASS_1_X_32                                 = 0x82BB;
constexpr int GL_IMAGE_CLASS_4_X_16                                 = 0x82BC;
constexpr int GL_IMAGE_CLASS_2_X_16                                 = 0x82BD;
constexpr int GL_IMAGE_CLASS_1_X_16                                 = 0x82BE;
constexpr int GL_IMAGE_CLASS_4_X_8                                  = 0x82BF;
constexpr int GL_IMAGE_CLASS_2_X_8                                  = 0x82C0;
constexpr int GL_IMAGE_CLASS_1_X_8                                  = 0x82C1;
constexpr int GL_IMAGE_CLASS_11_11_10                               = 0x82C2;
constexpr int GL_IMAGE_CLASS_10_10_10_2                             = 0x82C3;
constexpr int GL_VIEW_CLASS_128_BITS                                = 0x82C4;
constexpr int GL_VIEW_CLASS_96_BITS                                 = 0x82C5;
constexpr int GL_VIEW_CLASS_64_BITS                                 = 0x82C6;
constexpr int GL_VIEW_CLASS_48_BITS                                 = 0x82C7;
constexpr int GL_VIEW_CLASS_32_BITS                                 = 0x82C8;
constexpr int GL_VIEW_CLASS_24_BITS                                 = 0x82C9;
constexpr int GL_VIEW_CLASS_16_BITS                                 = 0x82CA;
constexpr int GL_VIEW_CLASS_8_BITS                                  = 0x82CB;
constexpr int GL_VIEW_CLASS_S3TC_DXT1_RGB                           = 0x82CC;
constexpr int GL_VIEW_CLASS_S3TC_DXT1_RGBA                          = 0x82CD;
constexpr int GL_VIEW_CLASS_S3TC_DXT3_RGBA                          = 0x82CE;
constexpr int GL_VIEW_CLASS_S3TC_DXT5_RGBA                          = 0x82CF;
constexpr int GL_VIEW_CLASS_RGTC1_RED                               = 0x82D0;
constexpr int GL_VIEW_CLASS_RGTC2_RG                                = 0x82D1;
constexpr int GL_VIEW_CLASS_BPTC_UNORM                              = 0x82D2;
constexpr int GL_VIEW_CLASS_BPTC_FLOAT                              = 0x82D3;
constexpr int GL_UNIFORM                                            = 0x92E1;
constexpr int GL_UNIFORM_BLOCK                                      = 0x92E2;
constexpr int GL_PROGRAM_INPUT                                      = 0x92E3;
constexpr int GL_PROGRAM_OUTPUT                                     = 0x92E4;
constexpr int GL_BUFFER_VARIABLE                                    = 0x92E5;
constexpr int GL_SHADER_STORAGE_BLOCK                               = 0x92E6;
constexpr int GL_VERTEX_SUBROUTINE                                  = 0x92E8;
constexpr int GL_TESS_CONTROL_SUBROUTINE                            = 0x92E9;
constexpr int GL_TESS_EVALUATION_SUBROUTINE                         = 0x92EA;
constexpr int GL_GEOMETRY_SUBROUTINE                                = 0x92EB;
constexpr int GL_FRAGMENT_SUBROUTINE                                = 0x92EC;
constexpr int GL_COMPUTE_SUBROUTINE                                 = 0x92ED;
constexpr int GL_VERTEX_SUBROUTINE_UNIFORM                          = 0x92EE;
constexpr int GL_TESS_CONTROL_SUBROUTINE_UNIFORM                    = 0x92EF;
constexpr int GL_TESS_EVALUATION_SUBROUTINE_UNIFORM                 = 0x92F0;
constexpr int GL_GEOMETRY_SUBROUTINE_UNIFORM                        = 0x92F1;
constexpr int GL_FRAGMENT_SUBROUTINE_UNIFORM                        = 0x92F2;
constexpr int GL_COMPUTE_SUBROUTINE_UNIFORM                         = 0x92F3;
constexpr int GL_TRANSFORM_FEEDBACK_VARYING                         = 0x92F4;
constexpr int GL_ACTIVE_RESOURCES                                   = 0x92F5;
constexpr int GL_MAX_NAME_LENGTH                                    = 0x92F6;
constexpr int GL_MAX_NUM_ACTIVE_VARIABLES                           = 0x92F7;
constexpr int GL_MAX_NUM_COMPATIBLE_SUBROUTINES                     = 0x92F8;
constexpr int GL_NAME_LENGTH                                        = 0x92F9;
constexpr int GL_TYPE                                               = 0x92FA;
constexpr int GL_ARRAY_SIZE                                         = 0x92FB;
constexpr int GL_OFFSET                                             = 0x92FC;
constexpr int GL_BLOCK_INDEX                                        = 0x92FD;
constexpr int GL_ARRAY_STRIDE                                       = 0x92FE;
constexpr int GL_MATRIX_STRIDE                                      = 0x92FF;
constexpr int GL_IS_ROW_MAJOR                                       = 0x9300;
constexpr int GL_ATOMIC_COUNTER_BUFFER_INDEX                        = 0x9301;
constexpr int GL_BUFFER_BINDING                                     = 0x9302;
constexpr int GL_BUFFER_DATA_SIZE                                   = 0x9303;
constexpr int GL_NUM_ACTIVE_VARIABLES                               = 0x9304;
constexpr int GL_ACTIVE_VARIABLES                                   = 0x9305;
constexpr int GL_REFERENCED_BY_VERTEX_SHADER                        = 0x9306;
constexpr int GL_REFERENCED_BY_TESS_CONTROL_SHADER                  = 0x9307;
constexpr int GL_REFERENCED_BY_TESS_EVALUATION_SHADER               = 0x9308;
constexpr int GL_REFERENCED_BY_GEOMETRY_SHADER                      = 0x9309;
constexpr int GL_REFERENCED_BY_FRAGMENT_SHADER                      = 0x930A;
constexpr int GL_REFERENCED_BY_COMPUTE_SHADER                       = 0x930B;
constexpr int GL_TOP_LEVEL_ARRAY_SIZE                               = 0x930C;
constexpr int GL_TOP_LEVEL_ARRAY_STRIDE                             = 0x930D;
constexpr int GL_LOCATION                                           = 0x930E;
constexpr int GL_LOCATION_INDEX                                     = 0x930F;
constexpr int GL_IS_PER_PATCH                                       = 0x92E7;
constexpr int GL_SHADER_STORAGE_BUFFER                              = 0x90D2;
constexpr int GL_SHADER_STORAGE_BUFFER_BINDING                      = 0x90D3;
constexpr int GL_SHADER_STORAGE_BUFFER_START                        = 0x90D4;
constexpr int GL_SHADER_STORAGE_BUFFER_SIZE                         = 0x90D5;
constexpr int GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS                   = 0x90D6;
constexpr int GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS                 = 0x90D7;
constexpr int GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS             = 0x90D8;
constexpr int GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS          = 0x90D9;
constexpr int GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS                 = 0x90DA;
constexpr int GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS                  = 0x90DB;
constexpr int GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS                 = 0x90DC;
constexpr int GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS                 = 0x90DD;
constexpr int GL_MAX_SHADER_STORAGE_BLOCK_SIZE                      = 0x90DE;
constexpr int GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT             = 0x90DF;
constexpr int GL_SHADER_STORAGE_BARRIER_BIT                         = 0x00002000;
constexpr int GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES               = 0x8F39;
constexpr int GL_DEPTH_STENCIL_TEXTURE_MODE                         = 0x90EA;
constexpr int GL_TEXTURE_BUFFER_OFFSET                              = 0x919D;
constexpr int GL_TEXTURE_BUFFER_SIZE                                = 0x919E;
constexpr int GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT                    = 0x919F;
constexpr int GL_TEXTURE_VIEW_MIN_LEVEL                             = 0x82DB;
constexpr int GL_TEXTURE_VIEW_NUM_LEVELS                            = 0x82DC;
constexpr int GL_TEXTURE_VIEW_MIN_LAYER                             = 0x82DD;
constexpr int GL_TEXTURE_VIEW_NUM_LAYERS                            = 0x82DE;
constexpr int GL_TEXTURE_IMMUTABLE_LEVELS                           = 0x82DF;
constexpr int GL_VERTEX_ATTRIB_BINDING                              = 0x82D4;
constexpr int GL_VERTEX_ATTRIB_RELATIVE_OFFSET                      = 0x82D5;
constexpr int GL_VERTEX_BINDING_DIVISOR                             = 0x82D6;
constexpr int GL_VERTEX_BINDING_OFFSET                              = 0x82D7;
constexpr int GL_VERTEX_BINDING_STRIDE                              = 0x82D8;
constexpr int GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET                  = 0x82D9;
constexpr int GL_MAX_VERTEX_ATTRIB_BINDINGS                         = 0x82DA;
constexpr int GL_VERTEX_BINDING_BUFFER                              = 0x8F4F;

void glClearBufferData(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void* data);
void glClearBufferSubData(GLenum target,
                          GLenum internalformat,
                          GLintptr offset,
                          GLsizeiptr size,
                          GLenum format,
                          GLenum type,
                          const void* data);
void glDispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
void glDispatchComputeIndirect(GLintptr indirect);
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
                        GLsizei srcDepth);
void glFramebufferParameteri(GLenum target, GLenum pname, GLint param);
void glGetFramebufferParameteriv(GLenum target, GLenum pname, GLint* params);
void glGetInternalformati64v(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint64* params);
void glInvalidateTexSubImage(GLuint texture,
                             GLint level,
                             GLint xoffset,
                             GLint yoffset,
                             GLint zoffset,
                             GLsizei width,
                             GLsizei height,
                             GLsizei depth);
void glInvalidateTexImage(GLuint texture, GLint level);
void glInvalidateBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr length);
void glInvalidateBufferData(GLuint buffer);
void glInvalidateFramebuffer(GLenum target, GLsizei numAttachments, const GLenum* attachments);
void glInvalidateSubFramebuffer(GLenum target,
                                GLsizei numAttachments,
                                const GLenum* attachments,
                                GLint x,
                                GLint y,
                                GLsizei width,
                                GLsizei height);
void glMultiDrawArraysIndirect(GLenum mode, const void* indirect, GLsizei drawcount, GLsizei stride);
void glMultiDrawElementsIndirect(GLenum mode, GLenum type, const void* indirect, GLsizei drawcount, GLsizei stride);
void glGetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum pname, GLint* params);
GLuint glGetProgramResourceIndex(GLuint program, GLenum programInterface, const GLchar* name);
void glGetProgramResourceName(GLuint program,
                              GLenum programInterface,
                              GLuint index,
                              GLsizei bufSize,
                              GLsizei* length,
                              GLchar* name);
void glGetProgramResourceiv(GLuint program,
                            GLenum programInterface,
                            GLuint index,
                            GLsizei propCount,
                            const GLenum* props,
                            GLsizei count,
                            GLsizei* length,
                            GLint* params);
GLint glGetProgramResourceLocation(GLuint program, GLenum programInterface, const GLchar* name);
GLint glGetProgramResourceLocationIndex(GLuint program, GLenum programInterface, const GLchar* name);
void glShaderStorageBlockBinding(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
void glTexBufferRange(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
void glTexStorage2DMultisample(GLenum target,
                               GLsizei samples,
                               GLenum internalformat,
                               GLsizei width,
                               GLsizei height,
                               GLboolean fixedsamplelocations);
void glTexStorage3DMultisample(GLenum target,
                               GLsizei samples,
                               GLenum internalformat,
                               GLsizei width,
                               GLsizei height,
                               GLsizei depth,
                               GLboolean fixedsamplelocations);
void glTextureView(GLuint texture,
                   GLenum target,
                   GLuint origtexture,
                   GLenum internalformat,
                   GLuint minlevel,
                   GLuint numlevels,
                   GLuint minlayer,
                   GLuint numlayers);
void glBindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
void glVertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
void glVertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
void glVertexAttribLFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
void glVertexAttribBinding(GLuint attribindex, GLuint bindingindex);
void glVertexBindingDivisor(GLuint bindingindex, GLuint divisor);
void glDebugMessageControl(GLenum source,
                           GLenum type,
                           GLenum severity,
                           GLsizei count,
                           const GLuint* ids,
                           GLboolean enabled);
void glDebugMessageInsert(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf);
void glDebugMessageCallback(GLDEBUGPROC callback, const void* userParam);
GLuint glGetDebugMessageLog(GLuint count,
                            GLsizei bufSize,
                            GLenum* sources,
                            GLenum* types,
                            GLuint* ids,
                            GLenum* severities,
                            GLsizei* lengths,
                            GLchar* messageLog);
void glPushDebugGroup(GLenum source, GLuint id, GLsizei length, const GLchar* message);
void glPopDebugGroup();
void glObjectLabel(GLenum identifier, GLuint name, GLsizei length, const GLchar* label);
void glGetObjectLabel(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei* length, GLchar* label);
void glObjectPtrLabel(const void* ptr, GLsizei length, const GLchar* label);
void glGetObjectPtrLabel(const void* ptr, GLsizei bufSize, GLsizei* length, GLchar* label);

#pragma endregion

#pragma region GL_VERSION_4_4

constexpr int GL_MAX_VERTEX_ATTRIB_STRIDE                = 0x82E5;
constexpr int GL_PRIMITIVE_RESTART_FOR_PATCHES_SUPPORTED = 0x8221;
constexpr int GL_TEXTURE_BUFFER_BINDING                  = 0x8C2A;
constexpr int GL_MAP_PERSISTENT_BIT                      = 0x0040;
constexpr int GL_MAP_COHERENT_BIT                        = 0x0080;
constexpr int GL_DYNAMIC_STORAGE_BIT                     = 0x0100;
constexpr int GL_CLIENT_STORAGE_BIT                      = 0x0200;
constexpr int GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT        = 0x00004000;
constexpr int GL_BUFFER_IMMUTABLE_STORAGE                = 0x821F;
constexpr int GL_BUFFER_STORAGE_FLAGS                    = 0x8220;
constexpr int GL_CLEAR_TEXTURE                           = 0x9365;
constexpr int GL_LOCATION_COMPONENT                      = 0x934A;
constexpr int GL_TRANSFORM_FEEDBACK_BUFFER_INDEX         = 0x934B;
constexpr int GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE        = 0x934C;
constexpr int GL_QUERY_BUFFER                            = 0x9192;
constexpr int GL_QUERY_BUFFER_BARRIER_BIT                = 0x00008000;
constexpr int GL_QUERY_BUFFER_BINDING                    = 0x9193;
constexpr int GL_QUERY_RESULT_NO_WAIT                    = 0x9194;
constexpr int GL_MIRROR_CLAMP_TO_EDGE                    = 0x8743;

void glBufferStorage(GLenum target, GLsizeiptr size, const void* data, GLbitfield flags);
void glClearTexImage(GLuint texture, GLint level, GLenum format, GLenum type, const void* data);
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
                        const void* data);
void glBindBuffersBase(GLenum target, GLuint first, GLsizei count, const GLuint* buffers);
void glBindBuffersRange(GLenum target,
                        GLuint first,
                        GLsizei count,
                        const GLuint* buffers,
                        const GLintptr* offsets,
                        const GLsizeiptr* sizes);
void glBindTextures(GLuint first, GLsizei count, const GLuint* textures);
void glBindSamplers(GLuint first, GLsizei count, const GLuint* samplers);
void glBindImageTextures(GLuint first, GLsizei count, const GLuint* textures);
void glBindVertexBuffers(GLuint first,
                         GLsizei count,
                         const GLuint* buffers,
                         const GLintptr* offsets,
                         const GLsizei* strides);

#pragma endregion

#pragma region GL_VERSION_4_5

constexpr int GL_CONTEXT_LOST                         = 0x0507;
constexpr int GL_NEGATIVE_ONE_TO_ONE                  = 0x935E;
constexpr int GL_ZERO_TO_ONE                          = 0x935F;
constexpr int GL_CLIP_ORIGIN                          = 0x935C;
constexpr int GL_CLIP_DEPTH_MODE                      = 0x935D;
constexpr int GL_QUERY_WAIT_INVERTED                  = 0x8E17;
constexpr int GL_QUERY_NO_WAIT_INVERTED               = 0x8E18;
constexpr int GL_QUERY_BY_REGION_WAIT_INVERTED        = 0x8E19;
constexpr int GL_QUERY_BY_REGION_NO_WAIT_INVERTED     = 0x8E1A;
constexpr int GL_MAX_CULL_DISTANCES                   = 0x82F9;
constexpr int GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES = 0x82FA;
constexpr int GL_TEXTURE_TARGET                       = 0x1006;
constexpr int GL_QUERY_TARGET                         = 0x82EA;
constexpr int GL_GUILTY_CONTEXT_RESET                 = 0x8253;
constexpr int GL_INNOCENT_CONTEXT_RESET               = 0x8254;
constexpr int GL_UNKNOWN_CONTEXT_RESET                = 0x8255;
constexpr int GL_RESET_NOTIFICATION_STRATEGY          = 0x8256;
constexpr int GL_LOSE_CONTEXT_ON_RESET                = 0x8252;
constexpr int GL_NO_RESET_NOTIFICATION                = 0x8261;
constexpr int GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT       = 0x00000004;
constexpr int GL_CONTEXT_RELEASE_BEHAVIOR             = 0x82FB;
constexpr int GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH       = 0x82FC;

void glClipControl(GLenum origin, GLenum depth);
void glCreateTransformFeedbacks(GLsizei n, GLuint* ids);
void glTransformFeedbackBufferBase(GLuint xfb, GLuint index, GLuint buffer);
void glTransformFeedbackBufferRange(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
void glGetTransformFeedbackiv(GLuint xfb, GLenum pname, GLint* param);
void glGetTransformFeedbacki_v(GLuint xfb, GLenum pname, GLuint index, GLint* param);
void glGetTransformFeedbacki64_v(GLuint xfb, GLenum pname, GLuint index, GLint64* param);
void glCreateBuffers(GLsizei n, GLuint* buffers);
void glNamedBufferStorage(GLuint buffer, GLsizeiptr size, const void* data, GLbitfield flags);
void glNamedBufferData(GLuint buffer, GLsizeiptr size, const void* data, GLenum usage);
void glNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, const void* data);
void glCopyNamedBufferSubData(GLuint readBuffer,
                              GLuint writeBuffer,
                              GLintptr readOffset,
                              GLintptr writeOffset,
                              GLsizeiptr size);
void glClearNamedBufferData(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void* data);
void glClearNamedBufferSubData(GLuint buffer,
                               GLenum internalformat,
                               GLintptr offset,
                               GLsizeiptr size,
                               GLenum format,
                               GLenum type,
                               const void* data);
void* glMapNamedBuffer(GLuint buffer, GLenum access);
void* glMapNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
GLboolean glUnmapNamedBuffer(GLuint buffer);
void glFlushMappedNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length);
void glGetNamedBufferParameteriv(GLuint buffer, GLenum pname, GLint* params);
void glGetNamedBufferParameteri64v(GLuint buffer, GLenum pname, GLint64* params);
void glGetNamedBufferPointerv(GLuint buffer, GLenum pname, void** params);
void glGetNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, void* data);
void glCreateFramebuffers(GLsizei n, GLuint* framebuffers);
void glNamedFramebufferRenderbuffer(GLuint framebuffer,
                                    GLenum attachment,
                                    GLenum renderbuffertarget,
                                    GLuint renderbuffer);
void glNamedFramebufferParameteri(GLuint framebuffer, GLenum pname, GLint param);
void glNamedFramebufferTexture(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
void glNamedFramebufferTextureLayer(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
void glNamedFramebufferDrawBuffer(GLuint framebuffer, GLenum buf);
void glNamedFramebufferDrawBuffers(GLuint framebuffer, GLsizei n, const GLenum* bufs);
void glNamedFramebufferReadBuffer(GLuint framebuffer, GLenum src);
void glInvalidateNamedFramebufferData(GLuint framebuffer, GLsizei numAttachments, const GLenum* attachments);
void glInvalidateNamedFramebufferSubData(GLuint framebuffer,
                                         GLsizei numAttachments,
                                         const GLenum* attachments,
                                         GLint x,
                                         GLint y,
                                         GLsizei width,
                                         GLsizei height);
void glClearNamedFramebufferiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint* value);
void glClearNamedFramebufferuiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint* value);
void glClearNamedFramebufferfv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat* value);
void glClearNamedFramebufferfi(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
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
                            GLenum filter);
GLenum glCheckNamedFramebufferStatus(GLuint framebuffer, GLenum target);
void glGetNamedFramebufferParameteriv(GLuint framebuffer, GLenum pname, GLint* param);
void glGetNamedFramebufferAttachmentParameteriv(GLuint framebuffer, GLenum attachment, GLenum pname, GLint* params);
void glCreateRenderbuffers(GLsizei n, GLuint* renderbuffers);
void glNamedRenderbufferStorage(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
void glNamedRenderbufferStorageMultisample(GLuint renderbuffer,
                                           GLsizei samples,
                                           GLenum internalformat,
                                           GLsizei width,
                                           GLsizei height);
void glGetNamedRenderbufferParameteriv(GLuint renderbuffer, GLenum pname, GLint* params);
void glCreateTextures(GLenum target, GLsizei n, GLuint* textures);
void glTextureBuffer(GLuint texture, GLenum internalformat, GLuint buffer);
void glTextureBufferRange(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
void glTextureStorage1D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
void glTextureStorage2D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
void glTextureStorage3D(GLuint texture,
                        GLsizei levels,
                        GLenum internalformat,
                        GLsizei width,
                        GLsizei height,
                        GLsizei depth);
void glTextureStorage2DMultisample(GLuint texture,
                                   GLsizei samples,
                                   GLenum internalformat,
                                   GLsizei width,
                                   GLsizei height,
                                   GLboolean fixedsamplelocations);
void glTextureStorage3DMultisample(GLuint texture,
                                   GLsizei samples,
                                   GLenum internalformat,
                                   GLsizei width,
                                   GLsizei height,
                                   GLsizei depth,
                                   GLboolean fixedsamplelocations);
void glTextureSubImage1D(GLuint texture,
                         GLint level,
                         GLint xoffset,
                         GLsizei width,
                         GLenum format,
                         GLenum type,
                         const void* pixels);
void glTextureSubImage2D(GLuint texture,
                         GLint level,
                         GLint xoffset,
                         GLint yoffset,
                         GLsizei width,
                         GLsizei height,
                         GLenum format,
                         GLenum type,
                         const void* pixels);
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
                         const void* pixels);
void glCompressedTextureSubImage1D(GLuint texture,
                                   GLint level,
                                   GLint xoffset,
                                   GLsizei width,
                                   GLenum format,
                                   GLsizei imageSize,
                                   const void* data);
void glCompressedTextureSubImage2D(GLuint texture,
                                   GLint level,
                                   GLint xoffset,
                                   GLint yoffset,
                                   GLsizei width,
                                   GLsizei height,
                                   GLenum format,
                                   GLsizei imageSize,
                                   const void* data);
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
                                   const void* data);
void glCopyTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
void glCopyTextureSubImage2D(GLuint texture,
                             GLint level,
                             GLint xoffset,
                             GLint yoffset,
                             GLint x,
                             GLint y,
                             GLsizei width,
                             GLsizei height);
void glCopyTextureSubImage3D(GLuint texture,
                             GLint level,
                             GLint xoffset,
                             GLint yoffset,
                             GLint zoffset,
                             GLint x,
                             GLint y,
                             GLsizei width,
                             GLsizei height);
void glTextureParameterf(GLuint texture, GLenum pname, GLfloat param);
void glTextureParameterfv(GLuint texture, GLenum pname, const GLfloat* param);
void glTextureParameteri(GLuint texture, GLenum pname, GLint param);
void glTextureParameterIiv(GLuint texture, GLenum pname, const GLint* params);
void glTextureParameterIuiv(GLuint texture, GLenum pname, const GLuint* params);
void glTextureParameteriv(GLuint texture, GLenum pname, const GLint* param);
void glGenerateTextureMipmap(GLuint texture);
void glBindTextureUnit(GLuint unit, GLuint texture);
void glGetTextureImage(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* pixels);
void glGetCompressedTextureImage(GLuint texture, GLint level, GLsizei bufSize, void* pixels);
void glGetTextureLevelParameterfv(GLuint texture, GLint level, GLenum pname, GLfloat* params);
void glGetTextureLevelParameteriv(GLuint texture, GLint level, GLenum pname, GLint* params);
void glGetTextureParameterfv(GLuint texture, GLenum pname, GLfloat* params);
void glGetTextureParameterIiv(GLuint texture, GLenum pname, GLint* params);
void glGetTextureParameterIuiv(GLuint texture, GLenum pname, GLuint* params);
void glGetTextureParameteriv(GLuint texture, GLenum pname, GLint* params);
void glCreateVertexArrays(GLsizei n, GLuint* arrays);
void glDisableVertexArrayAttrib(GLuint vaobj, GLuint index);
void glEnableVertexArrayAttrib(GLuint vaobj, GLuint index);
void glVertexArrayElementBuffer(GLuint vaobj, GLuint buffer);
void glVertexArrayVertexBuffer(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
void glVertexArrayVertexBuffers(GLuint vaobj,
                                GLuint first,
                                GLsizei count,
                                const GLuint* buffers,
                                const GLintptr* offsets,
                                const GLsizei* strides);
void glVertexArrayAttribBinding(GLuint vaobj, GLuint attribindex, GLuint bindingindex);
void glVertexArrayAttribFormat(GLuint vaobj,
                               GLuint attribindex,
                               GLint size,
                               GLenum type,
                               GLboolean normalized,
                               GLuint relativeoffset);
void glVertexArrayAttribIFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
void glVertexArrayAttribLFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
void glVertexArrayBindingDivisor(GLuint vaobj, GLuint bindingindex, GLuint divisor);
void glGetVertexArrayiv(GLuint vaobj, GLenum pname, GLint* param);
void glGetVertexArrayIndexediv(GLuint vaobj, GLuint index, GLenum pname, GLint* param);
void glGetVertexArrayIndexed64iv(GLuint vaobj, GLuint index, GLenum pname, GLint64* param);
void glCreateSamplers(GLsizei n, GLuint* samplers);
void glCreateProgramPipelines(GLsizei n, GLuint* pipelines);
void glCreateQueries(GLenum target, GLsizei n, GLuint* ids);
void glGetQueryBufferObjecti64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
void glGetQueryBufferObjectiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
void glGetQueryBufferObjectui64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
void glGetQueryBufferObjectuiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
void glMemoryBarrierByRegion(GLbitfield barriers);
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
                          void* pixels);
void glGetCompressedTextureSubImage(GLuint texture,
                                    GLint level,
                                    GLint xoffset,
                                    GLint yoffset,
                                    GLint zoffset,
                                    GLsizei width,
                                    GLsizei height,
                                    GLsizei depth,
                                    GLsizei bufSize,
                                    void* pixels);
GLenum glGetGraphicsResetStatus();
void glGetnCompressedTexImage(GLenum target, GLint lod, GLsizei bufSize, void* pixels);
void glGetnTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* pixels);
void glGetnUniformdv(GLuint program, GLint location, GLsizei bufSize, GLdouble* params);
void glGetnUniformfv(GLuint program, GLint location, GLsizei bufSize, GLfloat* params);
void glGetnUniformiv(GLuint program, GLint location, GLsizei bufSize, GLint* params);
void glGetnUniformuiv(GLuint program, GLint location, GLsizei bufSize, GLuint* params);
void glReadnPixels(GLint x,
                   GLint y,
                   GLsizei width,
                   GLsizei height,
                   GLenum format,
                   GLenum type,
                   GLsizei bufSize,
                   void* data);
void glTextureBarrier();

#pragma endregion

#pragma region GL_VERSION_4_6

constexpr int GL_SHADER_BINARY_FORMAT_SPIR_V        = 0x9551;
constexpr int GL_SPIR_V_BINARY                      = 0x9552;
constexpr int GL_PARAMETER_BUFFER                   = 0x80EE;
constexpr int GL_PARAMETER_BUFFER_BINDING           = 0x80EF;
constexpr int GL_CONTEXT_FLAG_NO_ERROR_BIT          = 0x00000008;
constexpr int GL_VERTICES_SUBMITTED                 = 0x82EE;
constexpr int GL_PRIMITIVES_SUBMITTED               = 0x82EF;
constexpr int GL_VERTEX_SHADER_INVOCATIONS          = 0x82F0;
constexpr int GL_TESS_CONTROL_SHADER_PATCHES        = 0x82F1;
constexpr int GL_TESS_EVALUATION_SHADER_INVOCATIONS = 0x82F2;
constexpr int GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED = 0x82F3;
constexpr int GL_FRAGMENT_SHADER_INVOCATIONS        = 0x82F4;
constexpr int GL_COMPUTE_SHADER_INVOCATIONS         = 0x82F5;
constexpr int GL_CLIPPING_INPUT_PRIMITIVES          = 0x82F6;
constexpr int GL_CLIPPING_OUTPUT_PRIMITIVES         = 0x82F7;
constexpr int GL_POLYGON_OFFSET_CLAMP               = 0x8E1B;
constexpr int GL_SPIR_V_EXTENSIONS                  = 0x9553;
constexpr int GL_NUM_SPIR_V_EXTENSIONS              = 0x9554;
constexpr int GL_TEXTURE_MAX_ANISOTROPY             = 0x84FE;
constexpr int GL_MAX_TEXTURE_MAX_ANISOTROPY         = 0x84FF;
constexpr int GL_TRANSFORM_FEEDBACK_OVERFLOW        = 0x82EC;
constexpr int GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW = 0x82ED;

void glSpecializeShader(GLuint shader,
                        const GLchar* pEntryPoint,
                        GLuint numSpecializationConstants,
                        const GLuint* pConstantIndex,
                        const GLuint* pConstantValue);
void glMultiDrawArraysIndirectCount(GLenum mode,
                                    const void* indirect,
                                    GLintptr drawcount,
                                    GLsizei maxdrawcount,
                                    GLsizei stride);
void glMultiDrawElementsIndirectCount(GLenum mode,
                                      GLenum type,
                                      const void* indirect,
                                      GLintptr drawcount,
                                      GLsizei maxdrawcount,
                                      GLsizei stride);
void glPolygonOffsetClamp(GLfloat factor, GLfloat units, GLfloat clamp);

#pragma endregion

#pragma region GL_AMD_framebuffer_multisample_advanced

constexpr int GL_RENDERBUFFER_STORAGE_SAMPLES_AMD          = 0x91B2;
constexpr int GL_MAX_COLOR_FRAMEBUFFER_SAMPLES_AMD         = 0x91B3;
constexpr int GL_MAX_COLOR_FRAMEBUFFER_STORAGE_SAMPLES_AMD = 0x91B4;
constexpr int GL_MAX_DEPTH_STENCIL_FRAMEBUFFER_SAMPLES_AMD = 0x91B5;
constexpr int GL_NUM_SUPPORTED_MULTISAMPLE_MODES_AMD       = 0x91B6;
constexpr int GL_SUPPORTED_MULTISAMPLE_MODES_AMD           = 0x91B7;

void glRenderbufferStorageMultisampleAdvancedAMD(GLenum target,
                                                 GLsizei samples,
                                                 GLsizei storageSamples,
                                                 GLenum internalformat,
                                                 GLsizei width,
                                                 GLsizei height);
void glNamedRenderbufferStorageMultisampleAdvancedAMD(GLuint renderbuffer,
                                                      GLsizei samples,
                                                      GLsizei storageSamples,
                                                      GLenum internalformat,
                                                      GLsizei width,
                                                      GLsizei height);

#pragma endregion

#pragma region GL_AMD_performance_monitor

constexpr int GL_COUNTER_TYPE_AMD             = 0x8BC0;
constexpr int GL_COUNTER_RANGE_AMD            = 0x8BC1;
constexpr int GL_UNSIGNED_INT64_AMD           = 0x8BC2;
constexpr int GL_PERCENTAGE_AMD               = 0x8BC3;
constexpr int GL_PERFMON_RESULT_AVAILABLE_AMD = 0x8BC4;
constexpr int GL_PERFMON_RESULT_SIZE_AMD      = 0x8BC5;
constexpr int GL_PERFMON_RESULT_AMD           = 0x8BC6;

void glGetPerfMonitorGroupsAMD(GLint* numGroups, GLsizei groupsSize, GLuint* groups);
void glGetPerfMonitorCountersAMD(GLuint group,
                                 GLint* numCounters,
                                 GLint* maxActiveCounters,
                                 GLsizei counterSize,
                                 GLuint* counters);
void glGetPerfMonitorGroupStringAMD(GLuint group, GLsizei bufSize, GLsizei* length, GLchar* groupString);
void glGetPerfMonitorCounterStringAMD(GLuint group,
                                      GLuint counter,
                                      GLsizei bufSize,
                                      GLsizei* length,
                                      GLchar* counterString);
void glGetPerfMonitorCounterInfoAMD(GLuint group, GLuint counter, GLenum pname, void* data);
void glGenPerfMonitorsAMD(GLsizei n, GLuint* monitors);
void glDeletePerfMonitorsAMD(GLsizei n, GLuint* monitors);
void glSelectPerfMonitorCountersAMD(GLuint monitor,
                                    GLboolean enable,
                                    GLuint group,
                                    GLint numCounters,
                                    GLuint* counterList);
void glBeginPerfMonitorAMD(GLuint monitor);
void glEndPerfMonitorAMD(GLuint monitor);
void glGetPerfMonitorCounterDataAMD(GLuint monitor, GLenum pname, GLsizei dataSize, GLuint* data, GLint* bytesWritten);

#pragma endregion

#pragma region GL_APPLE_rgb_422

constexpr int GL_RGB_422_APPLE                = 0x8A1F;
constexpr int GL_UNSIGNED_SHORT_8_8_APPLE     = 0x85BA;
constexpr int GL_UNSIGNED_SHORT_8_8_REV_APPLE = 0x85BB;
constexpr int GL_RGB_RAW_422_APPLE            = 0x8A51;

#pragma endregion

#pragma region GL_ARB_ES2_compatibility

#pragma endregion

#pragma region GL_ARB_ES3_1_compatibility

#pragma endregion

#pragma region GL_ARB_ES3_2_compatibility

constexpr int GL_PRIMITIVE_BOUNDING_BOX_ARB             = 0x92BE;
constexpr int GL_MULTISAMPLE_LINE_WIDTH_RANGE_ARB       = 0x9381;
constexpr int GL_MULTISAMPLE_LINE_WIDTH_GRANULARITY_ARB = 0x9382;

void glPrimitiveBoundingBoxARB(GLfloat minX,
                               GLfloat minY,
                               GLfloat minZ,
                               GLfloat minW,
                               GLfloat maxX,
                               GLfloat maxY,
                               GLfloat maxZ,
                               GLfloat maxW);

#pragma endregion

#pragma region GL_ARB_ES3_compatibility

#pragma endregion

#pragma region GL_ARB_arrays_of_arrays

#pragma endregion

#pragma region GL_ARB_base_instance

#pragma endregion

#pragma region GL_ARB_bindless_texture

typedef khronos_uint64_t GLuint64EXT;

constexpr int GL_UNSIGNED_INT64_ARB = 0x140F;

GLuint64 glGetTextureHandleARB(GLuint texture);
GLuint64 glGetTextureSamplerHandleARB(GLuint texture, GLuint sampler);
void glMakeTextureHandleResidentARB(GLuint64 handle);
void glMakeTextureHandleNonResidentARB(GLuint64 handle);
GLuint64 glGetImageHandleARB(GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
void glMakeImageHandleResidentARB(GLuint64 handle, GLenum access);
void glMakeImageHandleNonResidentARB(GLuint64 handle);
void glUniformHandleui64ARB(GLint location, GLuint64 value);
void glUniformHandleui64vARB(GLint location, GLsizei count, const GLuint64* value);
void glProgramUniformHandleui64ARB(GLuint program, GLint location, GLuint64 value);
void glProgramUniformHandleui64vARB(GLuint program, GLint location, GLsizei count, const GLuint64* values);
GLboolean glIsTextureHandleResidentARB(GLuint64 handle);
GLboolean glIsImageHandleResidentARB(GLuint64 handle);
void glVertexAttribL1ui64ARB(GLuint index, GLuint64EXT x);
void glVertexAttribL1ui64vARB(GLuint index, const GLuint64EXT* v);
void glGetVertexAttribLui64vARB(GLuint index, GLenum pname, GLuint64EXT* params);

#pragma endregion

#pragma region GL_ARB_blend_func_extended

#pragma endregion

#pragma region GL_ARB_buffer_storage

#pragma endregion

#pragma region GL_ARB_cl_event

struct _cl_context;
struct _cl_event;

constexpr int GL_SYNC_CL_EVENT_ARB          = 0x8240;
constexpr int GL_SYNC_CL_EVENT_COMPLETE_ARB = 0x8241;

GLsync glCreateSyncFromCLeventARB(struct _cl_context* context, struct _cl_event* event, GLbitfield flags);

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

constexpr int GL_MAX_COMPUTE_VARIABLE_GROUP_INVOCATIONS_ARB = 0x9344;
constexpr int GL_MAX_COMPUTE_FIXED_GROUP_INVOCATIONS_ARB    = 0x90EB;
constexpr int GL_MAX_COMPUTE_VARIABLE_GROUP_SIZE_ARB        = 0x9345;
constexpr int GL_MAX_COMPUTE_FIXED_GROUP_SIZE_ARB           = 0x91BF;

void glDispatchComputeGroupSizeARB(GLuint num_groups_x,
                                   GLuint num_groups_y,
                                   GLuint num_groups_z,
                                   GLuint group_size_x,
                                   GLuint group_size_y,
                                   GLuint group_size_z);

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

typedef void (*GLDEBUGPROCARB)(GLenum source,
                               GLenum type,
                               GLuint id,
                               GLenum severity,
                               GLsizei length,
                               const GLchar* message,
                               const void* userParam);

constexpr int GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB         = 0x8242;
constexpr int GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH_ARB = 0x8243;
constexpr int GL_DEBUG_CALLBACK_FUNCTION_ARB          = 0x8244;
constexpr int GL_DEBUG_CALLBACK_USER_PARAM_ARB        = 0x8245;
constexpr int GL_DEBUG_SOURCE_API_ARB                 = 0x8246;
constexpr int GL_DEBUG_SOURCE_WINDOW_SYSTEM_ARB       = 0x8247;
constexpr int GL_DEBUG_SOURCE_SHADER_COMPILER_ARB     = 0x8248;
constexpr int GL_DEBUG_SOURCE_THIRD_PARTY_ARB         = 0x8249;
constexpr int GL_DEBUG_SOURCE_APPLICATION_ARB         = 0x824A;
constexpr int GL_DEBUG_SOURCE_OTHER_ARB               = 0x824B;
constexpr int GL_DEBUG_TYPE_ERROR_ARB                 = 0x824C;
constexpr int GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_ARB   = 0x824D;
constexpr int GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_ARB    = 0x824E;
constexpr int GL_DEBUG_TYPE_PORTABILITY_ARB           = 0x824F;
constexpr int GL_DEBUG_TYPE_PERFORMANCE_ARB           = 0x8250;
constexpr int GL_DEBUG_TYPE_OTHER_ARB                 = 0x8251;
constexpr int GL_MAX_DEBUG_MESSAGE_LENGTH_ARB         = 0x9143;
constexpr int GL_MAX_DEBUG_LOGGED_MESSAGES_ARB        = 0x9144;
constexpr int GL_DEBUG_LOGGED_MESSAGES_ARB            = 0x9145;
constexpr int GL_DEBUG_SEVERITY_HIGH_ARB              = 0x9146;
constexpr int GL_DEBUG_SEVERITY_MEDIUM_ARB            = 0x9147;
constexpr int GL_DEBUG_SEVERITY_LOW_ARB               = 0x9148;

void glDebugMessageControlARB(GLenum source,
                              GLenum type,
                              GLenum severity,
                              GLsizei count,
                              const GLuint* ids,
                              GLboolean enabled);
void glDebugMessageInsertARB(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf);
void glDebugMessageCallbackARB(GLDEBUGPROCARB callback, const void* userParam);
GLuint glGetDebugMessageLogARB(GLuint count,
                               GLsizei bufSize,
                               GLenum* sources,
                               GLenum* types,
                               GLuint* ids,
                               GLenum* severities,
                               GLsizei* lengths,
                               GLchar* messageLog);

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

void glBlendEquationiARB(GLuint buf, GLenum mode);
void glBlendEquationSeparateiARB(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
void glBlendFunciARB(GLuint buf, GLenum src, GLenum dst);
void glBlendFuncSeparateiARB(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);

#pragma endregion

#pragma region GL_ARB_draw_elements_base_vertex

#pragma endregion

#pragma region GL_ARB_draw_indirect

#pragma endregion

#pragma region GL_ARB_draw_instanced

void glDrawArraysInstancedARB(GLenum mode, GLint first, GLsizei count, GLsizei primcount);
void glDrawElementsInstancedARB(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei primcount);

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

constexpr int GL_LINES_ADJACENCY_ARB                      = 0x000A;
constexpr int GL_LINE_STRIP_ADJACENCY_ARB                 = 0x000B;
constexpr int GL_TRIANGLES_ADJACENCY_ARB                  = 0x000C;
constexpr int GL_TRIANGLE_STRIP_ADJACENCY_ARB             = 0x000D;
constexpr int GL_PROGRAM_POINT_SIZE_ARB                   = 0x8642;
constexpr int GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_ARB     = 0x8C29;
constexpr int GL_FRAMEBUFFER_ATTACHMENT_LAYERED_ARB       = 0x8DA7;
constexpr int GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_ARB = 0x8DA8;
constexpr int GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_ARB   = 0x8DA9;
constexpr int GL_GEOMETRY_SHADER_ARB                      = 0x8DD9;
constexpr int GL_GEOMETRY_VERTICES_OUT_ARB                = 0x8DDA;
constexpr int GL_GEOMETRY_INPUT_TYPE_ARB                  = 0x8DDB;
constexpr int GL_GEOMETRY_OUTPUT_TYPE_ARB                 = 0x8DDC;
constexpr int GL_MAX_GEOMETRY_VARYING_COMPONENTS_ARB      = 0x8DDD;
constexpr int GL_MAX_VERTEX_VARYING_COMPONENTS_ARB        = 0x8DDE;
constexpr int GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_ARB      = 0x8DDF;
constexpr int GL_MAX_GEOMETRY_OUTPUT_VERTICES_ARB         = 0x8DE0;
constexpr int GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_ARB = 0x8DE1;

void glProgramParameteriARB(GLuint program, GLenum pname, GLint value);
void glFramebufferTextureARB(GLenum target, GLenum attachment, GLuint texture, GLint level);
void glFramebufferTextureLayerARB(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
void glFramebufferTextureFaceARB(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);

#pragma endregion

#pragma region GL_ARB_get_program_binary

#pragma endregion

#pragma region GL_ARB_get_texture_sub_image

#pragma endregion

#pragma region GL_ARB_gl_spirv

constexpr int GL_SHADER_BINARY_FORMAT_SPIR_V_ARB = 0x9551;
constexpr int GL_SPIR_V_BINARY_ARB               = 0x9552;

void glSpecializeShaderARB(GLuint shader,
                           const GLchar* pEntryPoint,
                           GLuint numSpecializationConstants,
                           const GLuint* pConstantIndex,
                           const GLuint* pConstantValue);

#pragma endregion

#pragma region GL_ARB_gpu_shader5

#pragma endregion

#pragma region GL_ARB_gpu_shader_fp64

#pragma endregion

#pragma region GL_ARB_gpu_shader_int64

constexpr int GL_INT64_ARB               = 0x140E;
constexpr int GL_INT64_VEC2_ARB          = 0x8FE9;
constexpr int GL_INT64_VEC3_ARB          = 0x8FEA;
constexpr int GL_INT64_VEC4_ARB          = 0x8FEB;
constexpr int GL_UNSIGNED_INT64_VEC2_ARB = 0x8FF5;
constexpr int GL_UNSIGNED_INT64_VEC3_ARB = 0x8FF6;
constexpr int GL_UNSIGNED_INT64_VEC4_ARB = 0x8FF7;

void glUniform1i64ARB(GLint location, GLint64 x);
void glUniform2i64ARB(GLint location, GLint64 x, GLint64 y);
void glUniform3i64ARB(GLint location, GLint64 x, GLint64 y, GLint64 z);
void glUniform4i64ARB(GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w);
void glUniform1i64vARB(GLint location, GLsizei count, const GLint64* value);
void glUniform2i64vARB(GLint location, GLsizei count, const GLint64* value);
void glUniform3i64vARB(GLint location, GLsizei count, const GLint64* value);
void glUniform4i64vARB(GLint location, GLsizei count, const GLint64* value);
void glUniform1ui64ARB(GLint location, GLuint64 x);
void glUniform2ui64ARB(GLint location, GLuint64 x, GLuint64 y);
void glUniform3ui64ARB(GLint location, GLuint64 x, GLuint64 y, GLuint64 z);
void glUniform4ui64ARB(GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w);
void glUniform1ui64vARB(GLint location, GLsizei count, const GLuint64* value);
void glUniform2ui64vARB(GLint location, GLsizei count, const GLuint64* value);
void glUniform3ui64vARB(GLint location, GLsizei count, const GLuint64* value);
void glUniform4ui64vARB(GLint location, GLsizei count, const GLuint64* value);
void glGetUniformi64vARB(GLuint program, GLint location, GLint64* params);
void glGetUniformui64vARB(GLuint program, GLint location, GLuint64* params);
void glGetnUniformi64vARB(GLuint program, GLint location, GLsizei bufSize, GLint64* params);
void glGetnUniformui64vARB(GLuint program, GLint location, GLsizei bufSize, GLuint64* params);
void glProgramUniform1i64ARB(GLuint program, GLint location, GLint64 x);
void glProgramUniform2i64ARB(GLuint program, GLint location, GLint64 x, GLint64 y);
void glProgramUniform3i64ARB(GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z);
void glProgramUniform4i64ARB(GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w);
void glProgramUniform1i64vARB(GLuint program, GLint location, GLsizei count, const GLint64* value);
void glProgramUniform2i64vARB(GLuint program, GLint location, GLsizei count, const GLint64* value);
void glProgramUniform3i64vARB(GLuint program, GLint location, GLsizei count, const GLint64* value);
void glProgramUniform4i64vARB(GLuint program, GLint location, GLsizei count, const GLint64* value);
void glProgramUniform1ui64ARB(GLuint program, GLint location, GLuint64 x);
void glProgramUniform2ui64ARB(GLuint program, GLint location, GLuint64 x, GLuint64 y);
void glProgramUniform3ui64ARB(GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z);
void glProgramUniform4ui64ARB(GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w);
void glProgramUniform1ui64vARB(GLuint program, GLint location, GLsizei count, const GLuint64* value);
void glProgramUniform2ui64vARB(GLuint program, GLint location, GLsizei count, const GLuint64* value);
void glProgramUniform3ui64vARB(GLuint program, GLint location, GLsizei count, const GLuint64* value);
void glProgramUniform4ui64vARB(GLuint program, GLint location, GLsizei count, const GLuint64* value);

#pragma endregion

#pragma region GL_ARB_half_float_vertex

#pragma endregion

#pragma region GL_ARB_imaging

#pragma endregion

#pragma region GL_ARB_indirect_parameters

constexpr int GL_PARAMETER_BUFFER_ARB         = 0x80EE;
constexpr int GL_PARAMETER_BUFFER_BINDING_ARB = 0x80EF;

void glMultiDrawArraysIndirectCountARB(GLenum mode,
                                       const void* indirect,
                                       GLintptr drawcount,
                                       GLsizei maxdrawcount,
                                       GLsizei stride);
void glMultiDrawElementsIndirectCountARB(GLenum mode,
                                         GLenum type,
                                         const void* indirect,
                                         GLintptr drawcount,
                                         GLsizei maxdrawcount,
                                         GLsizei stride);

#pragma endregion

#pragma region GL_ARB_instanced_arrays

constexpr int GL_VERTEX_ATTRIB_ARRAY_DIVISOR_ARB = 0x88FE;

void glVertexAttribDivisorARB(GLuint index, GLuint divisor);

#pragma endregion

#pragma region GL_ARB_internalformat_query

#pragma endregion

#pragma region GL_ARB_internalformat_query2

constexpr int GL_SRGB_DECODE_ARB            = 0x8299;
constexpr int GL_VIEW_CLASS_EAC_R11         = 0x9383;
constexpr int GL_VIEW_CLASS_EAC_RG11        = 0x9384;
constexpr int GL_VIEW_CLASS_ETC2_RGB        = 0x9385;
constexpr int GL_VIEW_CLASS_ETC2_RGBA       = 0x9386;
constexpr int GL_VIEW_CLASS_ETC2_EAC_RGBA   = 0x9387;
constexpr int GL_VIEW_CLASS_ASTC_4x4_RGBA   = 0x9388;
constexpr int GL_VIEW_CLASS_ASTC_5x4_RGBA   = 0x9389;
constexpr int GL_VIEW_CLASS_ASTC_5x5_RGBA   = 0x938A;
constexpr int GL_VIEW_CLASS_ASTC_6x5_RGBA   = 0x938B;
constexpr int GL_VIEW_CLASS_ASTC_6x6_RGBA   = 0x938C;
constexpr int GL_VIEW_CLASS_ASTC_8x5_RGBA   = 0x938D;
constexpr int GL_VIEW_CLASS_ASTC_8x6_RGBA   = 0x938E;
constexpr int GL_VIEW_CLASS_ASTC_8x8_RGBA   = 0x938F;
constexpr int GL_VIEW_CLASS_ASTC_10x5_RGBA  = 0x9390;
constexpr int GL_VIEW_CLASS_ASTC_10x6_RGBA  = 0x9391;
constexpr int GL_VIEW_CLASS_ASTC_10x8_RGBA  = 0x9392;
constexpr int GL_VIEW_CLASS_ASTC_10x10_RGBA = 0x9393;
constexpr int GL_VIEW_CLASS_ASTC_12x10_RGBA = 0x9394;
constexpr int GL_VIEW_CLASS_ASTC_12x12_RGBA = 0x9395;

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

constexpr int GL_MAX_SHADER_COMPILER_THREADS_ARB = 0x91B0;
constexpr int GL_COMPLETION_STATUS_ARB           = 0x91B1;

void glMaxShaderCompilerThreadsARB(GLuint count);

#pragma endregion

#pragma region GL_ARB_pipeline_statistics_query

constexpr int GL_VERTICES_SUBMITTED_ARB                 = 0x82EE;
constexpr int GL_PRIMITIVES_SUBMITTED_ARB               = 0x82EF;
constexpr int GL_VERTEX_SHADER_INVOCATIONS_ARB          = 0x82F0;
constexpr int GL_TESS_CONTROL_SHADER_PATCHES_ARB        = 0x82F1;
constexpr int GL_TESS_EVALUATION_SHADER_INVOCATIONS_ARB = 0x82F2;
constexpr int GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED_ARB = 0x82F3;
constexpr int GL_FRAGMENT_SHADER_INVOCATIONS_ARB        = 0x82F4;
constexpr int GL_COMPUTE_SHADER_INVOCATIONS_ARB         = 0x82F5;
constexpr int GL_CLIPPING_INPUT_PRIMITIVES_ARB          = 0x82F6;
constexpr int GL_CLIPPING_OUTPUT_PRIMITIVES_ARB         = 0x82F7;

#pragma endregion

#pragma region GL_ARB_pixel_buffer_object

constexpr int GL_PIXEL_PACK_BUFFER_ARB           = 0x88EB;
constexpr int GL_PIXEL_UNPACK_BUFFER_ARB         = 0x88EC;
constexpr int GL_PIXEL_PACK_BUFFER_BINDING_ARB   = 0x88ED;
constexpr int GL_PIXEL_UNPACK_BUFFER_BINDING_ARB = 0x88EF;

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

constexpr int GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB = 0x00000004;
constexpr int GL_LOSE_CONTEXT_ON_RESET_ARB          = 0x8252;
constexpr int GL_GUILTY_CONTEXT_RESET_ARB           = 0x8253;
constexpr int GL_INNOCENT_CONTEXT_RESET_ARB         = 0x8254;
constexpr int GL_UNKNOWN_CONTEXT_RESET_ARB          = 0x8255;
constexpr int GL_RESET_NOTIFICATION_STRATEGY_ARB    = 0x8256;
constexpr int GL_NO_RESET_NOTIFICATION_ARB          = 0x8261;

GLenum glGetGraphicsResetStatusARB();
void glGetnTexImageARB(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* img);
void glReadnPixelsARB(GLint x,
                      GLint y,
                      GLsizei width,
                      GLsizei height,
                      GLenum format,
                      GLenum type,
                      GLsizei bufSize,
                      void* data);
void glGetnCompressedTexImageARB(GLenum target, GLint lod, GLsizei bufSize, void* img);
void glGetnUniformfvARB(GLuint program, GLint location, GLsizei bufSize, GLfloat* params);
void glGetnUniformivARB(GLuint program, GLint location, GLsizei bufSize, GLint* params);
void glGetnUniformuivARB(GLuint program, GLint location, GLsizei bufSize, GLuint* params);
void glGetnUniformdvARB(GLuint program, GLint location, GLsizei bufSize, GLdouble* params);

#pragma endregion

#pragma region GL_ARB_robustness_isolation

#pragma endregion

#pragma region GL_ARB_sample_locations

constexpr int GL_SAMPLE_LOCATION_SUBPIXEL_BITS_ARB             = 0x933D;
constexpr int GL_SAMPLE_LOCATION_PIXEL_GRID_WIDTH_ARB          = 0x933E;
constexpr int GL_SAMPLE_LOCATION_PIXEL_GRID_HEIGHT_ARB         = 0x933F;
constexpr int GL_PROGRAMMABLE_SAMPLE_LOCATION_TABLE_SIZE_ARB   = 0x9340;
constexpr int GL_SAMPLE_LOCATION_ARB                           = 0x8E50;
constexpr int GL_PROGRAMMABLE_SAMPLE_LOCATION_ARB              = 0x9341;
constexpr int GL_FRAMEBUFFER_PROGRAMMABLE_SAMPLE_LOCATIONS_ARB = 0x9342;
constexpr int GL_FRAMEBUFFER_SAMPLE_LOCATION_PIXEL_GRID_ARB    = 0x9343;

void glFramebufferSampleLocationsfvARB(GLenum target, GLuint start, GLsizei count, const GLfloat* v);
void glNamedFramebufferSampleLocationsfvARB(GLuint framebuffer, GLuint start, GLsizei count, const GLfloat* v);
void glEvaluateDepthValuesARB();

#pragma endregion

#pragma region GL_ARB_sample_shading

constexpr int GL_SAMPLE_SHADING_ARB           = 0x8C36;
constexpr int GL_MIN_SAMPLE_SHADING_VALUE_ARB = 0x8C37;

void glMinSampleShadingARB(GLfloat value);

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

constexpr int GL_SHADER_INCLUDE_ARB      = 0x8DAE;
constexpr int GL_NAMED_STRING_LENGTH_ARB = 0x8DE9;
constexpr int GL_NAMED_STRING_TYPE_ARB   = 0x8DEA;

void glNamedStringARB(GLenum type, GLint namelen, const GLchar* name, GLint stringlen, const GLchar* string);
void glDeleteNamedStringARB(GLint namelen, const GLchar* name);
void glCompileShaderIncludeARB(GLuint shader, GLsizei count, const GLchar* const* path, const GLint* length);
GLboolean glIsNamedStringARB(GLint namelen, const GLchar* name);
void glGetNamedStringARB(GLint namelen, const GLchar* name, GLsizei bufSize, GLint* stringlen, GLchar* string);
void glGetNamedStringivARB(GLint namelen, const GLchar* name, GLenum pname, GLint* params);

#pragma endregion

#pragma region GL_ARB_shading_language_packing

#pragma endregion

#pragma region GL_ARB_sparse_buffer

constexpr int GL_SPARSE_STORAGE_BIT_ARB      = 0x0400;
constexpr int GL_SPARSE_BUFFER_PAGE_SIZE_ARB = 0x82F8;

void glBufferPageCommitmentARB(GLenum target, GLintptr offset, GLsizeiptr size, GLboolean commit);
void glNamedBufferPageCommitmentEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
void glNamedBufferPageCommitmentARB(GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);

#pragma endregion

#pragma region GL_ARB_sparse_texture

constexpr int GL_TEXTURE_SPARSE_ARB                         = 0x91A6;
constexpr int GL_VIRTUAL_PAGE_SIZE_INDEX_ARB                = 0x91A7;
constexpr int GL_NUM_SPARSE_LEVELS_ARB                      = 0x91AA;
constexpr int GL_NUM_VIRTUAL_PAGE_SIZES_ARB                 = 0x91A8;
constexpr int GL_VIRTUAL_PAGE_SIZE_X_ARB                    = 0x9195;
constexpr int GL_VIRTUAL_PAGE_SIZE_Y_ARB                    = 0x9196;
constexpr int GL_VIRTUAL_PAGE_SIZE_Z_ARB                    = 0x9197;
constexpr int GL_MAX_SPARSE_TEXTURE_SIZE_ARB                = 0x9198;
constexpr int GL_MAX_SPARSE_3D_TEXTURE_SIZE_ARB             = 0x9199;
constexpr int GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS_ARB        = 0x919A;
constexpr int GL_SPARSE_TEXTURE_FULL_ARRAY_CUBE_MIPMAPS_ARB = 0x91A9;

void glTexPageCommitmentARB(GLenum target,
                            GLint level,
                            GLint xoffset,
                            GLint yoffset,
                            GLint zoffset,
                            GLsizei width,
                            GLsizei height,
                            GLsizei depth,
                            GLboolean commit);

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

constexpr int GL_CLAMP_TO_BORDER_ARB = 0x812D;

#pragma endregion

#pragma region GL_ARB_texture_buffer_object

constexpr int GL_TEXTURE_BUFFER_ARB                    = 0x8C2A;
constexpr int GL_MAX_TEXTURE_BUFFER_SIZE_ARB           = 0x8C2B;
constexpr int GL_TEXTURE_BINDING_BUFFER_ARB            = 0x8C2C;
constexpr int GL_TEXTURE_BUFFER_DATA_STORE_BINDING_ARB = 0x8C2D;
constexpr int GL_TEXTURE_BUFFER_FORMAT_ARB             = 0x8C2E;

void glTexBufferARB(GLenum target, GLenum internalformat, GLuint buffer);

#pragma endregion

#pragma region GL_ARB_texture_buffer_object_rgb32

#pragma endregion

#pragma region GL_ARB_texture_buffer_range

#pragma endregion

#pragma region GL_ARB_texture_compression_bptc

constexpr int GL_COMPRESSED_RGBA_BPTC_UNORM_ARB         = 0x8E8C;
constexpr int GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM_ARB   = 0x8E8D;
constexpr int GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT_ARB   = 0x8E8E;
constexpr int GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_ARB = 0x8E8F;

#pragma endregion

#pragma region GL_ARB_texture_compression_rgtc

#pragma endregion

#pragma region GL_ARB_texture_cube_map_array

constexpr int GL_TEXTURE_CUBE_MAP_ARRAY_ARB              = 0x9009;
constexpr int GL_TEXTURE_BINDING_CUBE_MAP_ARRAY_ARB      = 0x900A;
constexpr int GL_PROXY_TEXTURE_CUBE_MAP_ARRAY_ARB        = 0x900B;
constexpr int GL_SAMPLER_CUBE_MAP_ARRAY_ARB              = 0x900C;
constexpr int GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW_ARB       = 0x900D;
constexpr int GL_INT_SAMPLER_CUBE_MAP_ARRAY_ARB          = 0x900E;
constexpr int GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY_ARB = 0x900F;

#pragma endregion

#pragma region GL_ARB_texture_filter_anisotropic

#pragma endregion

#pragma region GL_ARB_texture_filter_minmax

constexpr int GL_TEXTURE_REDUCTION_MODE_ARB = 0x9366;
constexpr int GL_WEIGHTED_AVERAGE_ARB       = 0x9367;

#pragma endregion

#pragma region GL_ARB_texture_gather

constexpr int GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_ARB     = 0x8E5E;
constexpr int GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_ARB     = 0x8E5F;
constexpr int GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS_ARB = 0x8F9F;

#pragma endregion

#pragma region GL_ARB_texture_mirror_clamp_to_edge

#pragma endregion

#pragma region GL_ARB_texture_mirrored_repeat

constexpr int GL_MIRRORED_REPEAT_ARB = 0x8370;

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

constexpr int GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB        = 0x82EC;
constexpr int GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB = 0x82ED;

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

void glDepthRangeArraydvNV(GLuint first, GLsizei count, const GLdouble* v);
void glDepthRangeIndexeddNV(GLuint index, GLdouble n, GLdouble f);

#pragma endregion

#pragma region GL_EXT_EGL_image_storage

typedef void* GLeglImageOES;

void glEGLImageTargetTexStorageEXT(GLenum target, GLeglImageOES image, const GLint* attrib_list);
void glEGLImageTargetTextureStorageEXT(GLuint texture, GLeglImageOES image, const GLint* attrib_list);

#pragma endregion

#pragma region GL_EXT_EGL_sync

#pragma endregion

#pragma region GL_EXT_debug_label

constexpr int GL_PROGRAM_PIPELINE_OBJECT_EXT = 0x8A4F;
constexpr int GL_PROGRAM_OBJECT_EXT          = 0x8B40;
constexpr int GL_SHADER_OBJECT_EXT           = 0x8B48;
constexpr int GL_BUFFER_OBJECT_EXT           = 0x9151;
constexpr int GL_QUERY_OBJECT_EXT            = 0x9153;
constexpr int GL_VERTEX_ARRAY_OBJECT_EXT     = 0x9154;

void glLabelObjectEXT(GLenum type, GLuint object, GLsizei length, const GLchar* label);
void glGetObjectLabelEXT(GLenum type, GLuint object, GLsizei bufSize, GLsizei* length, GLchar* label);

#pragma endregion

#pragma region GL_EXT_debug_marker

void glInsertEventMarkerEXT(GLsizei length, const GLchar* marker);
void glPushGroupMarkerEXT(GLsizei length, const GLchar* marker);
void glPopGroupMarkerEXT();

#pragma endregion

#pragma region GL_EXT_direct_state_access

constexpr int GL_PROGRAM_MATRIX_EXT             = 0x8E2D;
constexpr int GL_TRANSPOSE_PROGRAM_MATRIX_EXT   = 0x8E2E;
constexpr int GL_PROGRAM_MATRIX_STACK_DEPTH_EXT = 0x8E2F;

void glMatrixLoadfEXT(GLenum mode, const GLfloat* m);
void glMatrixLoaddEXT(GLenum mode, const GLdouble* m);
void glMatrixMultfEXT(GLenum mode, const GLfloat* m);
void glMatrixMultdEXT(GLenum mode, const GLdouble* m);
void glMatrixLoadIdentityEXT(GLenum mode);
void glMatrixRotatefEXT(GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
void glMatrixRotatedEXT(GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
void glMatrixScalefEXT(GLenum mode, GLfloat x, GLfloat y, GLfloat z);
void glMatrixScaledEXT(GLenum mode, GLdouble x, GLdouble y, GLdouble z);
void glMatrixTranslatefEXT(GLenum mode, GLfloat x, GLfloat y, GLfloat z);
void glMatrixTranslatedEXT(GLenum mode, GLdouble x, GLdouble y, GLdouble z);
void glMatrixFrustumEXT(GLenum mode,
                        GLdouble left,
                        GLdouble right,
                        GLdouble bottom,
                        GLdouble top,
                        GLdouble zNear,
                        GLdouble zFar);
void glMatrixOrthoEXT(GLenum mode,
                      GLdouble left,
                      GLdouble right,
                      GLdouble bottom,
                      GLdouble top,
                      GLdouble zNear,
                      GLdouble zFar);
void glMatrixPopEXT(GLenum mode);
void glMatrixPushEXT(GLenum mode);
void glClientAttribDefaultEXT(GLbitfield mask);
void glPushClientAttribDefaultEXT(GLbitfield mask);
void glTextureParameterfEXT(GLuint texture, GLenum target, GLenum pname, GLfloat param);
void glTextureParameterfvEXT(GLuint texture, GLenum target, GLenum pname, const GLfloat* params);
void glTextureParameteriEXT(GLuint texture, GLenum target, GLenum pname, GLint param);
void glTextureParameterivEXT(GLuint texture, GLenum target, GLenum pname, const GLint* params);
void glTextureImage1DEXT(GLuint texture,
                         GLenum target,
                         GLint level,
                         GLint internalformat,
                         GLsizei width,
                         GLint border,
                         GLenum format,
                         GLenum type,
                         const void* pixels);
void glTextureImage2DEXT(GLuint texture,
                         GLenum target,
                         GLint level,
                         GLint internalformat,
                         GLsizei width,
                         GLsizei height,
                         GLint border,
                         GLenum format,
                         GLenum type,
                         const void* pixels);
void glTextureSubImage1DEXT(GLuint texture,
                            GLenum target,
                            GLint level,
                            GLint xoffset,
                            GLsizei width,
                            GLenum format,
                            GLenum type,
                            const void* pixels);
void glTextureSubImage2DEXT(GLuint texture,
                            GLenum target,
                            GLint level,
                            GLint xoffset,
                            GLint yoffset,
                            GLsizei width,
                            GLsizei height,
                            GLenum format,
                            GLenum type,
                            const void* pixels);
void glCopyTextureImage1DEXT(GLuint texture,
                             GLenum target,
                             GLint level,
                             GLenum internalformat,
                             GLint x,
                             GLint y,
                             GLsizei width,
                             GLint border);
void glCopyTextureImage2DEXT(GLuint texture,
                             GLenum target,
                             GLint level,
                             GLenum internalformat,
                             GLint x,
                             GLint y,
                             GLsizei width,
                             GLsizei height,
                             GLint border);
void glCopyTextureSubImage1DEXT(GLuint texture,
                                GLenum target,
                                GLint level,
                                GLint xoffset,
                                GLint x,
                                GLint y,
                                GLsizei width);
void glCopyTextureSubImage2DEXT(GLuint texture,
                                GLenum target,
                                GLint level,
                                GLint xoffset,
                                GLint yoffset,
                                GLint x,
                                GLint y,
                                GLsizei width,
                                GLsizei height);
void glGetTextureImageEXT(GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, void* pixels);
void glGetTextureParameterfvEXT(GLuint texture, GLenum target, GLenum pname, GLfloat* params);
void glGetTextureParameterivEXT(GLuint texture, GLenum target, GLenum pname, GLint* params);
void glGetTextureLevelParameterfvEXT(GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat* params);
void glGetTextureLevelParameterivEXT(GLuint texture, GLenum target, GLint level, GLenum pname, GLint* params);
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
                         const void* pixels);
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
                            const void* pixels);
void glCopyTextureSubImage3DEXT(GLuint texture,
                                GLenum target,
                                GLint level,
                                GLint xoffset,
                                GLint yoffset,
                                GLint zoffset,
                                GLint x,
                                GLint y,
                                GLsizei width,
                                GLsizei height);
void glBindMultiTextureEXT(GLenum texunit, GLenum target, GLuint texture);
void glMultiTexCoordPointerEXT(GLenum texunit, GLint size, GLenum type, GLsizei stride, const void* pointer);
void glMultiTexEnvfEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat param);
void glMultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum pname, const GLfloat* params);
void glMultiTexEnviEXT(GLenum texunit, GLenum target, GLenum pname, GLint param);
void glMultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum pname, const GLint* params);
void glMultiTexGendEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble param);
void glMultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum pname, const GLdouble* params);
void glMultiTexGenfEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat param);
void glMultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum pname, const GLfloat* params);
void glMultiTexGeniEXT(GLenum texunit, GLenum coord, GLenum pname, GLint param);
void glMultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum pname, const GLint* params);
void glGetMultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat* params);
void glGetMultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum pname, GLint* params);
void glGetMultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble* params);
void glGetMultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat* params);
void glGetMultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum pname, GLint* params);
void glMultiTexParameteriEXT(GLenum texunit, GLenum target, GLenum pname, GLint param);
void glMultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum pname, const GLint* params);
void glMultiTexParameterfEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat param);
void glMultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum pname, const GLfloat* params);
void glMultiTexImage1DEXT(GLenum texunit,
                          GLenum target,
                          GLint level,
                          GLint internalformat,
                          GLsizei width,
                          GLint border,
                          GLenum format,
                          GLenum type,
                          const void* pixels);
void glMultiTexImage2DEXT(GLenum texunit,
                          GLenum target,
                          GLint level,
                          GLint internalformat,
                          GLsizei width,
                          GLsizei height,
                          GLint border,
                          GLenum format,
                          GLenum type,
                          const void* pixels);
void glMultiTexSubImage1DEXT(GLenum texunit,
                             GLenum target,
                             GLint level,
                             GLint xoffset,
                             GLsizei width,
                             GLenum format,
                             GLenum type,
                             const void* pixels);
void glMultiTexSubImage2DEXT(GLenum texunit,
                             GLenum target,
                             GLint level,
                             GLint xoffset,
                             GLint yoffset,
                             GLsizei width,
                             GLsizei height,
                             GLenum format,
                             GLenum type,
                             const void* pixels);
void glCopyMultiTexImage1DEXT(GLenum texunit,
                              GLenum target,
                              GLint level,
                              GLenum internalformat,
                              GLint x,
                              GLint y,
                              GLsizei width,
                              GLint border);
void glCopyMultiTexImage2DEXT(GLenum texunit,
                              GLenum target,
                              GLint level,
                              GLenum internalformat,
                              GLint x,
                              GLint y,
                              GLsizei width,
                              GLsizei height,
                              GLint border);
void glCopyMultiTexSubImage1DEXT(GLenum texunit,
                                 GLenum target,
                                 GLint level,
                                 GLint xoffset,
                                 GLint x,
                                 GLint y,
                                 GLsizei width);
void glCopyMultiTexSubImage2DEXT(GLenum texunit,
                                 GLenum target,
                                 GLint level,
                                 GLint xoffset,
                                 GLint yoffset,
                                 GLint x,
                                 GLint y,
                                 GLsizei width,
                                 GLsizei height);
void glGetMultiTexImageEXT(GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, void* pixels);
void glGetMultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat* params);
void glGetMultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum pname, GLint* params);
void glGetMultiTexLevelParameterfvEXT(GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat* params);
void glGetMultiTexLevelParameterivEXT(GLenum texunit, GLenum target, GLint level, GLenum pname, GLint* params);
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
                          const void* pixels);
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
                             const void* pixels);
void glCopyMultiTexSubImage3DEXT(GLenum texunit,
                                 GLenum target,
                                 GLint level,
                                 GLint xoffset,
                                 GLint yoffset,
                                 GLint zoffset,
                                 GLint x,
                                 GLint y,
                                 GLsizei width,
                                 GLsizei height);
void glEnableClientStateIndexedEXT(GLenum array, GLuint index);
void glDisableClientStateIndexedEXT(GLenum array, GLuint index);
void glGetFloatIndexedvEXT(GLenum target, GLuint index, GLfloat* data);
void glGetDoubleIndexedvEXT(GLenum target, GLuint index, GLdouble* data);
void glGetPointerIndexedvEXT(GLenum target, GLuint index, void** data);
void glEnableIndexedEXT(GLenum target, GLuint index);
void glDisableIndexedEXT(GLenum target, GLuint index);
GLboolean glIsEnabledIndexedEXT(GLenum target, GLuint index);
void glGetIntegerIndexedvEXT(GLenum target, GLuint index, GLint* data);
void glGetBooleanIndexedvEXT(GLenum target, GLuint index, GLboolean* data);
void glCompressedTextureImage3DEXT(GLuint texture,
                                   GLenum target,
                                   GLint level,
                                   GLenum internalformat,
                                   GLsizei width,
                                   GLsizei height,
                                   GLsizei depth,
                                   GLint border,
                                   GLsizei imageSize,
                                   const void* bits);
void glCompressedTextureImage2DEXT(GLuint texture,
                                   GLenum target,
                                   GLint level,
                                   GLenum internalformat,
                                   GLsizei width,
                                   GLsizei height,
                                   GLint border,
                                   GLsizei imageSize,
                                   const void* bits);
void glCompressedTextureImage1DEXT(GLuint texture,
                                   GLenum target,
                                   GLint level,
                                   GLenum internalformat,
                                   GLsizei width,
                                   GLint border,
                                   GLsizei imageSize,
                                   const void* bits);
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
                                      const void* bits);
void glCompressedTextureSubImage2DEXT(GLuint texture,
                                      GLenum target,
                                      GLint level,
                                      GLint xoffset,
                                      GLint yoffset,
                                      GLsizei width,
                                      GLsizei height,
                                      GLenum format,
                                      GLsizei imageSize,
                                      const void* bits);
void glCompressedTextureSubImage1DEXT(GLuint texture,
                                      GLenum target,
                                      GLint level,
                                      GLint xoffset,
                                      GLsizei width,
                                      GLenum format,
                                      GLsizei imageSize,
                                      const void* bits);
void glGetCompressedTextureImageEXT(GLuint texture, GLenum target, GLint lod, void* img);
void glCompressedMultiTexImage3DEXT(GLenum texunit,
                                    GLenum target,
                                    GLint level,
                                    GLenum internalformat,
                                    GLsizei width,
                                    GLsizei height,
                                    GLsizei depth,
                                    GLint border,
                                    GLsizei imageSize,
                                    const void* bits);
void glCompressedMultiTexImage2DEXT(GLenum texunit,
                                    GLenum target,
                                    GLint level,
                                    GLenum internalformat,
                                    GLsizei width,
                                    GLsizei height,
                                    GLint border,
                                    GLsizei imageSize,
                                    const void* bits);
void glCompressedMultiTexImage1DEXT(GLenum texunit,
                                    GLenum target,
                                    GLint level,
                                    GLenum internalformat,
                                    GLsizei width,
                                    GLint border,
                                    GLsizei imageSize,
                                    const void* bits);
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
                                       const void* bits);
void glCompressedMultiTexSubImage2DEXT(GLenum texunit,
                                       GLenum target,
                                       GLint level,
                                       GLint xoffset,
                                       GLint yoffset,
                                       GLsizei width,
                                       GLsizei height,
                                       GLenum format,
                                       GLsizei imageSize,
                                       const void* bits);
void glCompressedMultiTexSubImage1DEXT(GLenum texunit,
                                       GLenum target,
                                       GLint level,
                                       GLint xoffset,
                                       GLsizei width,
                                       GLenum format,
                                       GLsizei imageSize,
                                       const void* bits);
void glGetCompressedMultiTexImageEXT(GLenum texunit, GLenum target, GLint lod, void* img);
void glMatrixLoadTransposefEXT(GLenum mode, const GLfloat* m);
void glMatrixLoadTransposedEXT(GLenum mode, const GLdouble* m);
void glMatrixMultTransposefEXT(GLenum mode, const GLfloat* m);
void glMatrixMultTransposedEXT(GLenum mode, const GLdouble* m);
void glNamedBufferDataEXT(GLuint buffer, GLsizeiptr size, const void* data, GLenum usage);
void glNamedBufferSubDataEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, const void* data);
void* glMapNamedBufferEXT(GLuint buffer, GLenum access);
GLboolean glUnmapNamedBufferEXT(GLuint buffer);
void glGetNamedBufferParameterivEXT(GLuint buffer, GLenum pname, GLint* params);
void glGetNamedBufferPointervEXT(GLuint buffer, GLenum pname, void** params);
void glGetNamedBufferSubDataEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, void* data);
void glProgramUniform1fEXT(GLuint program, GLint location, GLfloat v0);
void glProgramUniform2fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1);
void glProgramUniform3fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
void glProgramUniform4fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
void glProgramUniform1iEXT(GLuint program, GLint location, GLint v0);
void glProgramUniform2iEXT(GLuint program, GLint location, GLint v0, GLint v1);
void glProgramUniform3iEXT(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
void glProgramUniform4iEXT(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
void glProgramUniform1fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat* value);
void glProgramUniform2fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat* value);
void glProgramUniform3fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat* value);
void glProgramUniform4fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat* value);
void glProgramUniform1ivEXT(GLuint program, GLint location, GLsizei count, const GLint* value);
void glProgramUniform2ivEXT(GLuint program, GLint location, GLsizei count, const GLint* value);
void glProgramUniform3ivEXT(GLuint program, GLint location, GLsizei count, const GLint* value);
void glProgramUniform4ivEXT(GLuint program, GLint location, GLsizei count, const GLint* value);
void glProgramUniformMatrix2fvEXT(GLuint program,
                                  GLint location,
                                  GLsizei count,
                                  GLboolean transpose,
                                  const GLfloat* value);
void glProgramUniformMatrix3fvEXT(GLuint program,
                                  GLint location,
                                  GLsizei count,
                                  GLboolean transpose,
                                  const GLfloat* value);
void glProgramUniformMatrix4fvEXT(GLuint program,
                                  GLint location,
                                  GLsizei count,
                                  GLboolean transpose,
                                  const GLfloat* value);
void glProgramUniformMatrix2x3fvEXT(GLuint program,
                                    GLint location,
                                    GLsizei count,
                                    GLboolean transpose,
                                    const GLfloat* value);
void glProgramUniformMatrix3x2fvEXT(GLuint program,
                                    GLint location,
                                    GLsizei count,
                                    GLboolean transpose,
                                    const GLfloat* value);
void glProgramUniformMatrix2x4fvEXT(GLuint program,
                                    GLint location,
                                    GLsizei count,
                                    GLboolean transpose,
                                    const GLfloat* value);
void glProgramUniformMatrix4x2fvEXT(GLuint program,
                                    GLint location,
                                    GLsizei count,
                                    GLboolean transpose,
                                    const GLfloat* value);
void glProgramUniformMatrix3x4fvEXT(GLuint program,
                                    GLint location,
                                    GLsizei count,
                                    GLboolean transpose,
                                    const GLfloat* value);
void glProgramUniformMatrix4x3fvEXT(GLuint program,
                                    GLint location,
                                    GLsizei count,
                                    GLboolean transpose,
                                    const GLfloat* value);
void glTextureBufferEXT(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer);
void glMultiTexBufferEXT(GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer);
void glTextureParameterIivEXT(GLuint texture, GLenum target, GLenum pname, const GLint* params);
void glTextureParameterIuivEXT(GLuint texture, GLenum target, GLenum pname, const GLuint* params);
void glGetTextureParameterIivEXT(GLuint texture, GLenum target, GLenum pname, GLint* params);
void glGetTextureParameterIuivEXT(GLuint texture, GLenum target, GLenum pname, GLuint* params);
void glMultiTexParameterIivEXT(GLenum texunit, GLenum target, GLenum pname, const GLint* params);
void glMultiTexParameterIuivEXT(GLenum texunit, GLenum target, GLenum pname, const GLuint* params);
void glGetMultiTexParameterIivEXT(GLenum texunit, GLenum target, GLenum pname, GLint* params);
void glGetMultiTexParameterIuivEXT(GLenum texunit, GLenum target, GLenum pname, GLuint* params);
void glProgramUniform1uiEXT(GLuint program, GLint location, GLuint v0);
void glProgramUniform2uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1);
void glProgramUniform3uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
void glProgramUniform4uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
void glProgramUniform1uivEXT(GLuint program, GLint location, GLsizei count, const GLuint* value);
void glProgramUniform2uivEXT(GLuint program, GLint location, GLsizei count, const GLuint* value);
void glProgramUniform3uivEXT(GLuint program, GLint location, GLsizei count, const GLuint* value);
void glProgramUniform4uivEXT(GLuint program, GLint location, GLsizei count, const GLuint* value);
void glNamedProgramLocalParameters4fvEXT(GLuint program,
                                         GLenum target,
                                         GLuint index,
                                         GLsizei count,
                                         const GLfloat* params);
void glNamedProgramLocalParameterI4iEXT(GLuint program, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
void glNamedProgramLocalParameterI4ivEXT(GLuint program, GLenum target, GLuint index, const GLint* params);
void glNamedProgramLocalParametersI4ivEXT(GLuint program,
                                          GLenum target,
                                          GLuint index,
                                          GLsizei count,
                                          const GLint* params);
void glNamedProgramLocalParameterI4uiEXT(GLuint program,
                                         GLenum target,
                                         GLuint index,
                                         GLuint x,
                                         GLuint y,
                                         GLuint z,
                                         GLuint w);
void glNamedProgramLocalParameterI4uivEXT(GLuint program, GLenum target, GLuint index, const GLuint* params);
void glNamedProgramLocalParametersI4uivEXT(GLuint program,
                                           GLenum target,
                                           GLuint index,
                                           GLsizei count,
                                           const GLuint* params);
void glGetNamedProgramLocalParameterIivEXT(GLuint program, GLenum target, GLuint index, GLint* params);
void glGetNamedProgramLocalParameterIuivEXT(GLuint program, GLenum target, GLuint index, GLuint* params);
void glEnableClientStateiEXT(GLenum array, GLuint index);
void glDisableClientStateiEXT(GLenum array, GLuint index);
void glGetFloati_vEXT(GLenum pname, GLuint index, GLfloat* params);
void glGetDoublei_vEXT(GLenum pname, GLuint index, GLdouble* params);
void glGetPointeri_vEXT(GLenum pname, GLuint index, void** params);
void glNamedProgramStringEXT(GLuint program, GLenum target, GLenum format, GLsizei len, const void* string);
void glNamedProgramLocalParameter4dEXT(GLuint program,
                                       GLenum target,
                                       GLuint index,
                                       GLdouble x,
                                       GLdouble y,
                                       GLdouble z,
                                       GLdouble w);
void glNamedProgramLocalParameter4dvEXT(GLuint program, GLenum target, GLuint index, const GLdouble* params);
void glNamedProgramLocalParameter4fEXT(GLuint program,
                                       GLenum target,
                                       GLuint index,
                                       GLfloat x,
                                       GLfloat y,
                                       GLfloat z,
                                       GLfloat w);
void glNamedProgramLocalParameter4fvEXT(GLuint program, GLenum target, GLuint index, const GLfloat* params);
void glGetNamedProgramLocalParameterdvEXT(GLuint program, GLenum target, GLuint index, GLdouble* params);
void glGetNamedProgramLocalParameterfvEXT(GLuint program, GLenum target, GLuint index, GLfloat* params);
void glGetNamedProgramivEXT(GLuint program, GLenum target, GLenum pname, GLint* params);
void glGetNamedProgramStringEXT(GLuint program, GLenum target, GLenum pname, void* string);
void glNamedRenderbufferStorageEXT(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
void glGetNamedRenderbufferParameterivEXT(GLuint renderbuffer, GLenum pname, GLint* params);
void glNamedRenderbufferStorageMultisampleEXT(GLuint renderbuffer,
                                              GLsizei samples,
                                              GLenum internalformat,
                                              GLsizei width,
                                              GLsizei height);
void glNamedRenderbufferStorageMultisampleCoverageEXT(GLuint renderbuffer,
                                                      GLsizei coverageSamples,
                                                      GLsizei colorSamples,
                                                      GLenum internalformat,
                                                      GLsizei width,
                                                      GLsizei height);
GLenum glCheckNamedFramebufferStatusEXT(GLuint framebuffer, GLenum target);
void glNamedFramebufferTexture1DEXT(GLuint framebuffer,
                                    GLenum attachment,
                                    GLenum textarget,
                                    GLuint texture,
                                    GLint level);
void glNamedFramebufferTexture2DEXT(GLuint framebuffer,
                                    GLenum attachment,
                                    GLenum textarget,
                                    GLuint texture,
                                    GLint level);
void glNamedFramebufferTexture3DEXT(GLuint framebuffer,
                                    GLenum attachment,
                                    GLenum textarget,
                                    GLuint texture,
                                    GLint level,
                                    GLint zoffset);
void glNamedFramebufferRenderbufferEXT(GLuint framebuffer,
                                       GLenum attachment,
                                       GLenum renderbuffertarget,
                                       GLuint renderbuffer);
void glGetNamedFramebufferAttachmentParameterivEXT(GLuint framebuffer, GLenum attachment, GLenum pname, GLint* params);
void glGenerateTextureMipmapEXT(GLuint texture, GLenum target);
void glGenerateMultiTexMipmapEXT(GLenum texunit, GLenum target);
void glFramebufferDrawBufferEXT(GLuint framebuffer, GLenum mode);
void glFramebufferDrawBuffersEXT(GLuint framebuffer, GLsizei n, const GLenum* bufs);
void glFramebufferReadBufferEXT(GLuint framebuffer, GLenum mode);
void glGetFramebufferParameterivEXT(GLuint framebuffer, GLenum pname, GLint* params);
void glNamedCopyBufferSubDataEXT(GLuint readBuffer,
                                 GLuint writeBuffer,
                                 GLintptr readOffset,
                                 GLintptr writeOffset,
                                 GLsizeiptr size);
void glNamedFramebufferTextureEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
void glNamedFramebufferTextureLayerEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
void glNamedFramebufferTextureFaceEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face);
void glTextureRenderbufferEXT(GLuint texture, GLenum target, GLuint renderbuffer);
void glMultiTexRenderbufferEXT(GLenum texunit, GLenum target, GLuint renderbuffer);
void glVertexArrayVertexOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
void glVertexArrayColorOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
void glVertexArrayEdgeFlagOffsetEXT(GLuint vaobj, GLuint buffer, GLsizei stride, GLintptr offset);
void glVertexArrayIndexOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
void glVertexArrayNormalOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
void glVertexArrayTexCoordOffsetEXT(GLuint vaobj,
                                    GLuint buffer,
                                    GLint size,
                                    GLenum type,
                                    GLsizei stride,
                                    GLintptr offset);
void glVertexArrayMultiTexCoordOffsetEXT(GLuint vaobj,
                                         GLuint buffer,
                                         GLenum texunit,
                                         GLint size,
                                         GLenum type,
                                         GLsizei stride,
                                         GLintptr offset);
void glVertexArrayFogCoordOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
void glVertexArraySecondaryColorOffsetEXT(GLuint vaobj,
                                          GLuint buffer,
                                          GLint size,
                                          GLenum type,
                                          GLsizei stride,
                                          GLintptr offset);
void glVertexArrayVertexAttribOffsetEXT(GLuint vaobj,
                                        GLuint buffer,
                                        GLuint index,
                                        GLint size,
                                        GLenum type,
                                        GLboolean normalized,
                                        GLsizei stride,
                                        GLintptr offset);
void glVertexArrayVertexAttribIOffsetEXT(GLuint vaobj,
                                         GLuint buffer,
                                         GLuint index,
                                         GLint size,
                                         GLenum type,
                                         GLsizei stride,
                                         GLintptr offset);
void glEnableVertexArrayEXT(GLuint vaobj, GLenum array);
void glDisableVertexArrayEXT(GLuint vaobj, GLenum array);
void glEnableVertexArrayAttribEXT(GLuint vaobj, GLuint index);
void glDisableVertexArrayAttribEXT(GLuint vaobj, GLuint index);
void glGetVertexArrayIntegervEXT(GLuint vaobj, GLenum pname, GLint* param);
void glGetVertexArrayPointervEXT(GLuint vaobj, GLenum pname, void** param);
void glGetVertexArrayIntegeri_vEXT(GLuint vaobj, GLuint index, GLenum pname, GLint* param);
void glGetVertexArrayPointeri_vEXT(GLuint vaobj, GLuint index, GLenum pname, void** param);
void* glMapNamedBufferRangeEXT(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
void glFlushMappedNamedBufferRangeEXT(GLuint buffer, GLintptr offset, GLsizeiptr length);
void glNamedBufferStorageEXT(GLuint buffer, GLsizeiptr size, const void* data, GLbitfield flags);
void glClearNamedBufferDataEXT(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void* data);
void glClearNamedBufferSubDataEXT(GLuint buffer,
                                  GLenum internalformat,
                                  GLsizeiptr offset,
                                  GLsizeiptr size,
                                  GLenum format,
                                  GLenum type,
                                  const void* data);
void glNamedFramebufferParameteriEXT(GLuint framebuffer, GLenum pname, GLint param);
void glGetNamedFramebufferParameterivEXT(GLuint framebuffer, GLenum pname, GLint* params);
void glProgramUniform1dEXT(GLuint program, GLint location, GLdouble x);
void glProgramUniform2dEXT(GLuint program, GLint location, GLdouble x, GLdouble y);
void glProgramUniform3dEXT(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z);
void glProgramUniform4dEXT(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void glProgramUniform1dvEXT(GLuint program, GLint location, GLsizei count, const GLdouble* value);
void glProgramUniform2dvEXT(GLuint program, GLint location, GLsizei count, const GLdouble* value);
void glProgramUniform3dvEXT(GLuint program, GLint location, GLsizei count, const GLdouble* value);
void glProgramUniform4dvEXT(GLuint program, GLint location, GLsizei count, const GLdouble* value);
void glProgramUniformMatrix2dvEXT(GLuint program,
                                  GLint location,
                                  GLsizei count,
                                  GLboolean transpose,
                                  const GLdouble* value);
void glProgramUniformMatrix3dvEXT(GLuint program,
                                  GLint location,
                                  GLsizei count,
                                  GLboolean transpose,
                                  const GLdouble* value);
void glProgramUniformMatrix4dvEXT(GLuint program,
                                  GLint location,
                                  GLsizei count,
                                  GLboolean transpose,
                                  const GLdouble* value);
void glProgramUniformMatrix2x3dvEXT(GLuint program,
                                    GLint location,
                                    GLsizei count,
                                    GLboolean transpose,
                                    const GLdouble* value);
void glProgramUniformMatrix2x4dvEXT(GLuint program,
                                    GLint location,
                                    GLsizei count,
                                    GLboolean transpose,
                                    const GLdouble* value);
void glProgramUniformMatrix3x2dvEXT(GLuint program,
                                    GLint location,
                                    GLsizei count,
                                    GLboolean transpose,
                                    const GLdouble* value);
void glProgramUniformMatrix3x4dvEXT(GLuint program,
                                    GLint location,
                                    GLsizei count,
                                    GLboolean transpose,
                                    const GLdouble* value);
void glProgramUniformMatrix4x2dvEXT(GLuint program,
                                    GLint location,
                                    GLsizei count,
                                    GLboolean transpose,
                                    const GLdouble* value);
void glProgramUniformMatrix4x3dvEXT(GLuint program,
                                    GLint location,
                                    GLsizei count,
                                    GLboolean transpose,
                                    const GLdouble* value);
void glTextureBufferRangeEXT(GLuint texture,
                             GLenum target,
                             GLenum internalformat,
                             GLuint buffer,
                             GLintptr offset,
                             GLsizeiptr size);
void glTextureStorage1DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
void glTextureStorage2DEXT(GLuint texture,
                           GLenum target,
                           GLsizei levels,
                           GLenum internalformat,
                           GLsizei width,
                           GLsizei height);
void glTextureStorage3DEXT(GLuint texture,
                           GLenum target,
                           GLsizei levels,
                           GLenum internalformat,
                           GLsizei width,
                           GLsizei height,
                           GLsizei depth);
void glTextureStorage2DMultisampleEXT(GLuint texture,
                                      GLenum target,
                                      GLsizei samples,
                                      GLenum internalformat,
                                      GLsizei width,
                                      GLsizei height,
                                      GLboolean fixedsamplelocations);
void glTextureStorage3DMultisampleEXT(GLuint texture,
                                      GLenum target,
                                      GLsizei samples,
                                      GLenum internalformat,
                                      GLsizei width,
                                      GLsizei height,
                                      GLsizei depth,
                                      GLboolean fixedsamplelocations);
void glVertexArrayBindVertexBufferEXT(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
void glVertexArrayVertexAttribFormatEXT(GLuint vaobj,
                                        GLuint attribindex,
                                        GLint size,
                                        GLenum type,
                                        GLboolean normalized,
                                        GLuint relativeoffset);
void glVertexArrayVertexAttribIFormatEXT(GLuint vaobj,
                                         GLuint attribindex,
                                         GLint size,
                                         GLenum type,
                                         GLuint relativeoffset);
void glVertexArrayVertexAttribLFormatEXT(GLuint vaobj,
                                         GLuint attribindex,
                                         GLint size,
                                         GLenum type,
                                         GLuint relativeoffset);
void glVertexArrayVertexAttribBindingEXT(GLuint vaobj, GLuint attribindex, GLuint bindingindex);
void glVertexArrayVertexBindingDivisorEXT(GLuint vaobj, GLuint bindingindex, GLuint divisor);
void glVertexArrayVertexAttribLOffsetEXT(GLuint vaobj,
                                         GLuint buffer,
                                         GLuint index,
                                         GLint size,
                                         GLenum type,
                                         GLsizei stride,
                                         GLintptr offset);
void glTexturePageCommitmentEXT(GLuint texture,
                                GLint level,
                                GLint xoffset,
                                GLint yoffset,
                                GLint zoffset,
                                GLsizei width,
                                GLsizei height,
                                GLsizei depth,
                                GLboolean commit);
void glVertexArrayVertexAttribDivisorEXT(GLuint vaobj, GLuint index, GLuint divisor);

#pragma endregion

#pragma region GL_EXT_draw_instanced

void glDrawArraysInstancedEXT(GLenum mode, GLint start, GLsizei count, GLsizei primcount);
void glDrawElementsInstancedEXT(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei primcount);

#pragma endregion

#pragma region GL_EXT_multiview_tessellation_geometry_shader

#pragma endregion

#pragma region GL_EXT_multiview_texture_multisample

#pragma endregion

#pragma region GL_EXT_multiview_timer_query

#pragma endregion

#pragma region GL_EXT_polygon_offset_clamp

constexpr int GL_POLYGON_OFFSET_CLAMP_EXT = 0x8E1B;

void glPolygonOffsetClampEXT(GLfloat factor, GLfloat units, GLfloat clamp);

#pragma endregion

#pragma region GL_EXT_post_depth_coverage

#pragma endregion

#pragma region GL_EXT_raster_multisample

constexpr int GL_RASTER_MULTISAMPLE_EXT                = 0x9327;
constexpr int GL_RASTER_SAMPLES_EXT                    = 0x9328;
constexpr int GL_MAX_RASTER_SAMPLES_EXT                = 0x9329;
constexpr int GL_RASTER_FIXED_SAMPLE_LOCATIONS_EXT     = 0x932A;
constexpr int GL_MULTISAMPLE_RASTERIZATION_ALLOWED_EXT = 0x932B;
constexpr int GL_EFFECTIVE_RASTER_SAMPLES_EXT          = 0x932C;

void glRasterSamplesEXT(GLuint samples, GLboolean fixedsamplelocations);

#pragma endregion

#pragma region GL_EXT_separate_shader_objects

constexpr int GL_ACTIVE_PROGRAM_EXT           = 0x8B8D;
constexpr int GL_VERTEX_SHADER_BIT_EXT        = 0x00000001;
constexpr int GL_FRAGMENT_SHADER_BIT_EXT      = 0x00000002;
constexpr int GL_ALL_SHADER_BITS_EXT          = 0xFFFFFFFF;
constexpr int GL_PROGRAM_SEPARABLE_EXT        = 0x8258;
constexpr int GL_PROGRAM_PIPELINE_BINDING_EXT = 0x825A;

void glUseShaderProgramEXT(GLenum type, GLuint program);
void glActiveProgramEXT(GLuint program);
GLuint glCreateShaderProgramEXT(GLenum type, const GLchar* string);
void glActiveShaderProgramEXT(GLuint pipeline, GLuint program);
void glBindProgramPipelineEXT(GLuint pipeline);
GLuint glCreateShaderProgramvEXT(GLenum type, GLsizei count, const GLchar** strings);
void glDeleteProgramPipelinesEXT(GLsizei n, const GLuint* pipelines);
void glGenProgramPipelinesEXT(GLsizei n, GLuint* pipelines);
void glGetProgramPipelineInfoLogEXT(GLuint pipeline, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
void glGetProgramPipelineivEXT(GLuint pipeline, GLenum pname, GLint* params);
GLboolean glIsProgramPipelineEXT(GLuint pipeline);
void glProgramParameteriEXT(GLuint program, GLenum pname, GLint value);
void glUseProgramStagesEXT(GLuint pipeline, GLbitfield stages, GLuint program);
void glValidateProgramPipelineEXT(GLuint pipeline);

#pragma endregion

#pragma region GL_EXT_shader_framebuffer_fetch

constexpr int GL_FRAGMENT_SHADER_DISCARDS_SAMPLES_EXT = 0x8A52;

#pragma endregion

#pragma region GL_EXT_shader_framebuffer_fetch_non_coherent

void glFramebufferFetchBarrierEXT();

#pragma endregion

#pragma region GL_EXT_shader_integer_mix

#pragma endregion

#pragma region GL_EXT_texture_compression_s3tc

constexpr int GL_COMPRESSED_RGB_S3TC_DXT1_EXT  = 0x83F0;
constexpr int GL_COMPRESSED_RGBA_S3TC_DXT1_EXT = 0x83F1;
constexpr int GL_COMPRESSED_RGBA_S3TC_DXT3_EXT = 0x83F2;
constexpr int GL_COMPRESSED_RGBA_S3TC_DXT5_EXT = 0x83F3;

#pragma endregion

#pragma region GL_EXT_texture_filter_minmax

constexpr int GL_TEXTURE_REDUCTION_MODE_EXT = 0x9366;
constexpr int GL_WEIGHTED_AVERAGE_EXT       = 0x9367;

#pragma endregion

#pragma region GL_EXT_texture_sRGB_R8

constexpr int GL_SR8_EXT = 0x8FBD;

#pragma endregion

#pragma region GL_EXT_texture_sRGB_decode

constexpr int GL_TEXTURE_SRGB_DECODE_EXT = 0x8A48;
constexpr int GL_DECODE_EXT              = 0x8A49;
constexpr int GL_SKIP_DECODE_EXT         = 0x8A4A;

#pragma endregion

#pragma region GL_EXT_window_rectangles

constexpr int GL_INCLUSIVE_EXT             = 0x8F10;
constexpr int GL_EXCLUSIVE_EXT             = 0x8F11;
constexpr int GL_WINDOW_RECTANGLE_EXT      = 0x8F12;
constexpr int GL_WINDOW_RECTANGLE_MODE_EXT = 0x8F13;
constexpr int GL_MAX_WINDOW_RECTANGLES_EXT = 0x8F14;
constexpr int GL_NUM_WINDOW_RECTANGLES_EXT = 0x8F15;

void glWindowRectanglesEXT(GLenum mode, GLsizei count, const GLint* box);

#pragma endregion

#pragma region GL_INTEL_conservative_rasterization

constexpr int GL_CONSERVATIVE_RASTERIZATION_INTEL = 0x83FE;

#pragma endregion

#pragma region GL_INTEL_framebuffer_CMAA

void glApplyFramebufferAttachmentCMAAINTEL();

#pragma endregion

#pragma region GL_INTEL_blackhole_render

constexpr int GL_BLACKHOLE_RENDER_INTEL = 0x83FC;

#pragma endregion

#pragma region GL_INTEL_performance_query

constexpr int GL_PERFQUERY_SINGLE_CONTEXT_INTEL          = 0x00000000;
constexpr int GL_PERFQUERY_GLOBAL_CONTEXT_INTEL          = 0x00000001;
constexpr int GL_PERFQUERY_WAIT_INTEL                    = 0x83FB;
constexpr int GL_PERFQUERY_FLUSH_INTEL                   = 0x83FA;
constexpr int GL_PERFQUERY_DONOT_FLUSH_INTEL             = 0x83F9;
constexpr int GL_PERFQUERY_COUNTER_EVENT_INTEL           = 0x94F0;
constexpr int GL_PERFQUERY_COUNTER_DURATION_NORM_INTEL   = 0x94F1;
constexpr int GL_PERFQUERY_COUNTER_DURATION_RAW_INTEL    = 0x94F2;
constexpr int GL_PERFQUERY_COUNTER_THROUGHPUT_INTEL      = 0x94F3;
constexpr int GL_PERFQUERY_COUNTER_RAW_INTEL             = 0x94F4;
constexpr int GL_PERFQUERY_COUNTER_TIMESTAMP_INTEL       = 0x94F5;
constexpr int GL_PERFQUERY_COUNTER_DATA_UINT32_INTEL     = 0x94F8;
constexpr int GL_PERFQUERY_COUNTER_DATA_UINT64_INTEL     = 0x94F9;
constexpr int GL_PERFQUERY_COUNTER_DATA_FLOAT_INTEL      = 0x94FA;
constexpr int GL_PERFQUERY_COUNTER_DATA_DOUBLE_INTEL     = 0x94FB;
constexpr int GL_PERFQUERY_COUNTER_DATA_BOOL32_INTEL     = 0x94FC;
constexpr int GL_PERFQUERY_QUERY_NAME_LENGTH_MAX_INTEL   = 0x94FD;
constexpr int GL_PERFQUERY_COUNTER_NAME_LENGTH_MAX_INTEL = 0x94FE;
constexpr int GL_PERFQUERY_COUNTER_DESC_LENGTH_MAX_INTEL = 0x94FF;
constexpr int GL_PERFQUERY_GPA_EXTENDED_COUNTERS_INTEL   = 0x9500;

void glBeginPerfQueryINTEL(GLuint queryHandle);
void glCreatePerfQueryINTEL(GLuint queryId, GLuint* queryHandle);
void glDeletePerfQueryINTEL(GLuint queryHandle);
void glEndPerfQueryINTEL(GLuint queryHandle);
void glGetFirstPerfQueryIdINTEL(GLuint* queryId);
void glGetNextPerfQueryIdINTEL(GLuint queryId, GLuint* nextQueryId);
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
                               GLuint64* rawCounterMaxValue);
void glGetPerfQueryDataINTEL(GLuint queryHandle, GLuint flags, GLsizei dataSize, void* data, GLuint* bytesWritten);
void glGetPerfQueryIdByNameINTEL(GLchar* queryName, GLuint* queryId);
void glGetPerfQueryInfoINTEL(GLuint queryId,
                             GLuint queryNameLength,
                             GLchar* queryName,
                             GLuint* dataSize,
                             GLuint* noCounters,
                             GLuint* noInstances,
                             GLuint* capsMask);

#pragma endregion

#pragma region GL_KHR_blend_equation_advanced

constexpr int GL_MULTIPLY_KHR       = 0x9294;
constexpr int GL_SCREEN_KHR         = 0x9295;
constexpr int GL_OVERLAY_KHR        = 0x9296;
constexpr int GL_DARKEN_KHR         = 0x9297;
constexpr int GL_LIGHTEN_KHR        = 0x9298;
constexpr int GL_COLORDODGE_KHR     = 0x9299;
constexpr int GL_COLORBURN_KHR      = 0x929A;
constexpr int GL_HARDLIGHT_KHR      = 0x929B;
constexpr int GL_SOFTLIGHT_KHR      = 0x929C;
constexpr int GL_DIFFERENCE_KHR     = 0x929E;
constexpr int GL_EXCLUSION_KHR      = 0x92A0;
constexpr int GL_HSL_HUE_KHR        = 0x92AD;
constexpr int GL_HSL_SATURATION_KHR = 0x92AE;
constexpr int GL_HSL_COLOR_KHR      = 0x92AF;
constexpr int GL_HSL_LUMINOSITY_KHR = 0x92B0;

void glBlendBarrierKHR();

#pragma endregion

#pragma region GL_KHR_blend_equation_advanced_coherent

constexpr int GL_BLEND_ADVANCED_COHERENT_KHR = 0x9285;

#pragma endregion

#pragma region GL_KHR_context_flush_control

constexpr int GL_CONTEXT_RELEASE_BEHAVIOR_KHR       = 0x82FB;
constexpr int GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH_KHR = 0x82FC;

#pragma endregion

#pragma region GL_KHR_debug

typedef void (*GLDEBUGPROCKHR)(GLenum source,
                               GLenum type,
                               GLuint id,
                               GLenum severity,
                               GLsizei length,
                               const GLchar* message,
                               const void* userParam);

constexpr int GL_DEBUG_OUTPUT_SYNCHRONOUS_KHR         = 0x8242;
constexpr int GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH_KHR = 0x8243;
constexpr int GL_DEBUG_CALLBACK_FUNCTION_KHR          = 0x8244;
constexpr int GL_DEBUG_CALLBACK_USER_PARAM_KHR        = 0x8245;
constexpr int GL_DEBUG_SOURCE_API_KHR                 = 0x8246;
constexpr int GL_DEBUG_SOURCE_WINDOW_SYSTEM_KHR       = 0x8247;
constexpr int GL_DEBUG_SOURCE_SHADER_COMPILER_KHR     = 0x8248;
constexpr int GL_DEBUG_SOURCE_THIRD_PARTY_KHR         = 0x8249;
constexpr int GL_DEBUG_SOURCE_APPLICATION_KHR         = 0x824A;
constexpr int GL_DEBUG_SOURCE_OTHER_KHR               = 0x824B;
constexpr int GL_DEBUG_TYPE_ERROR_KHR                 = 0x824C;
constexpr int GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_KHR   = 0x824D;
constexpr int GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_KHR    = 0x824E;
constexpr int GL_DEBUG_TYPE_PORTABILITY_KHR           = 0x824F;
constexpr int GL_DEBUG_TYPE_PERFORMANCE_KHR           = 0x8250;
constexpr int GL_DEBUG_TYPE_OTHER_KHR                 = 0x8251;
constexpr int GL_DEBUG_TYPE_MARKER_KHR                = 0x8268;
constexpr int GL_DEBUG_TYPE_PUSH_GROUP_KHR            = 0x8269;
constexpr int GL_DEBUG_TYPE_POP_GROUP_KHR             = 0x826A;
constexpr int GL_DEBUG_SEVERITY_NOTIFICATION_KHR      = 0x826B;
constexpr int GL_MAX_DEBUG_GROUP_STACK_DEPTH_KHR      = 0x826C;
constexpr int GL_DEBUG_GROUP_STACK_DEPTH_KHR          = 0x826D;
constexpr int GL_BUFFER_KHR                           = 0x82E0;
constexpr int GL_SHADER_KHR                           = 0x82E1;
constexpr int GL_PROGRAM_KHR                          = 0x82E2;
constexpr int GL_VERTEX_ARRAY_KHR                     = 0x8074;
constexpr int GL_QUERY_KHR                            = 0x82E3;
constexpr int GL_PROGRAM_PIPELINE_KHR                 = 0x82E4;
constexpr int GL_SAMPLER_KHR                          = 0x82E6;
constexpr int GL_MAX_LABEL_LENGTH_KHR                 = 0x82E8;
constexpr int GL_MAX_DEBUG_MESSAGE_LENGTH_KHR         = 0x9143;
constexpr int GL_MAX_DEBUG_LOGGED_MESSAGES_KHR        = 0x9144;
constexpr int GL_DEBUG_LOGGED_MESSAGES_KHR            = 0x9145;
constexpr int GL_DEBUG_SEVERITY_HIGH_KHR              = 0x9146;
constexpr int GL_DEBUG_SEVERITY_MEDIUM_KHR            = 0x9147;
constexpr int GL_DEBUG_SEVERITY_LOW_KHR               = 0x9148;
constexpr int GL_DEBUG_OUTPUT_KHR                     = 0x92E0;
constexpr int GL_CONTEXT_FLAG_DEBUG_BIT_KHR           = 0x00000002;
constexpr int GL_STACK_OVERFLOW_KHR                   = 0x0503;
constexpr int GL_STACK_UNDERFLOW_KHR                  = 0x0504;

void glDebugMessageControlKHR(GLenum source,
                              GLenum type,
                              GLenum severity,
                              GLsizei count,
                              const GLuint* ids,
                              GLboolean enabled);
void glDebugMessageInsertKHR(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf);
void glDebugMessageCallbackKHR(GLDEBUGPROCKHR callback, const void* userParam);
GLuint glGetDebugMessageLogKHR(GLuint count,
                               GLsizei bufSize,
                               GLenum* sources,
                               GLenum* types,
                               GLuint* ids,
                               GLenum* severities,
                               GLsizei* lengths,
                               GLchar* messageLog);
void glPushDebugGroupKHR(GLenum source, GLuint id, GLsizei length, const GLchar* message);
void glPopDebugGroupKHR();
void glObjectLabelKHR(GLenum identifier, GLuint name, GLsizei length, const GLchar* label);
void glGetObjectLabelKHR(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei* length, GLchar* label);
void glObjectPtrLabelKHR(const void* ptr, GLsizei length, const GLchar* label);
void glGetObjectPtrLabelKHR(const void* ptr, GLsizei bufSize, GLsizei* length, GLchar* label);
void glGetPointervKHR(GLenum pname, void** params);

#pragma endregion

#pragma region GL_KHR_no_error

constexpr int GL_CONTEXT_FLAG_NO_ERROR_BIT_KHR = 0x00000008;

#pragma endregion

#pragma region GL_KHR_robust_buffer_access_behavior

#pragma endregion

#pragma region GL_KHR_robustness

constexpr int GL_CONTEXT_ROBUST_ACCESS           = 0x90F3;
constexpr int GL_CONTEXT_ROBUST_ACCESS_KHR       = 0x90F3;
constexpr int GL_LOSE_CONTEXT_ON_RESET_KHR       = 0x8252;
constexpr int GL_GUILTY_CONTEXT_RESET_KHR        = 0x8253;
constexpr int GL_INNOCENT_CONTEXT_RESET_KHR      = 0x8254;
constexpr int GL_UNKNOWN_CONTEXT_RESET_KHR       = 0x8255;
constexpr int GL_RESET_NOTIFICATION_STRATEGY_KHR = 0x8256;
constexpr int GL_NO_RESET_NOTIFICATION_KHR       = 0x8261;
constexpr int GL_CONTEXT_LOST_KHR                = 0x0507;

GLenum glGetGraphicsResetStatusKHR();
void glReadnPixelsKHR(GLint x,
                      GLint y,
                      GLsizei width,
                      GLsizei height,
                      GLenum format,
                      GLenum type,
                      GLsizei bufSize,
                      void* data);
void glGetnUniformfvKHR(GLuint program, GLint location, GLsizei bufSize, GLfloat* params);
void glGetnUniformivKHR(GLuint program, GLint location, GLsizei bufSize, GLint* params);
void glGetnUniformuivKHR(GLuint program, GLint location, GLsizei bufSize, GLuint* params);

#pragma endregion

#pragma region GL_KHR_shader_subgroup

constexpr int GL_SUBGROUP_SIZE_KHR                         = 0x9532;
constexpr int GL_SUBGROUP_SUPPORTED_STAGES_KHR             = 0x9533;
constexpr int GL_SUBGROUP_SUPPORTED_FEATURES_KHR           = 0x9534;
constexpr int GL_SUBGROUP_QUAD_ALL_STAGES_KHR              = 0x9535;
constexpr int GL_SUBGROUP_FEATURE_BASIC_BIT_KHR            = 0x00000001;
constexpr int GL_SUBGROUP_FEATURE_VOTE_BIT_KHR             = 0x00000002;
constexpr int GL_SUBGROUP_FEATURE_ARITHMETIC_BIT_KHR       = 0x00000004;
constexpr int GL_SUBGROUP_FEATURE_BALLOT_BIT_KHR           = 0x00000008;
constexpr int GL_SUBGROUP_FEATURE_SHUFFLE_BIT_KHR          = 0x00000010;
constexpr int GL_SUBGROUP_FEATURE_SHUFFLE_RELATIVE_BIT_KHR = 0x00000020;
constexpr int GL_SUBGROUP_FEATURE_CLUSTERED_BIT_KHR        = 0x00000040;
constexpr int GL_SUBGROUP_FEATURE_QUAD_BIT_KHR             = 0x00000080;

#pragma endregion

#pragma region GL_KHR_texture_compression_astc_hdr

constexpr int GL_COMPRESSED_RGBA_ASTC_4x4_KHR           = 0x93B0;
constexpr int GL_COMPRESSED_RGBA_ASTC_5x4_KHR           = 0x93B1;
constexpr int GL_COMPRESSED_RGBA_ASTC_5x5_KHR           = 0x93B2;
constexpr int GL_COMPRESSED_RGBA_ASTC_6x5_KHR           = 0x93B3;
constexpr int GL_COMPRESSED_RGBA_ASTC_6x6_KHR           = 0x93B4;
constexpr int GL_COMPRESSED_RGBA_ASTC_8x5_KHR           = 0x93B5;
constexpr int GL_COMPRESSED_RGBA_ASTC_8x6_KHR           = 0x93B6;
constexpr int GL_COMPRESSED_RGBA_ASTC_8x8_KHR           = 0x93B7;
constexpr int GL_COMPRESSED_RGBA_ASTC_10x5_KHR          = 0x93B8;
constexpr int GL_COMPRESSED_RGBA_ASTC_10x6_KHR          = 0x93B9;
constexpr int GL_COMPRESSED_RGBA_ASTC_10x8_KHR          = 0x93BA;
constexpr int GL_COMPRESSED_RGBA_ASTC_10x10_KHR         = 0x93BB;
constexpr int GL_COMPRESSED_RGBA_ASTC_12x10_KHR         = 0x93BC;
constexpr int GL_COMPRESSED_RGBA_ASTC_12x12_KHR         = 0x93BD;
constexpr int GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x4_KHR   = 0x93D0;
constexpr int GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x4_KHR   = 0x93D1;
constexpr int GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x5_KHR   = 0x93D2;
constexpr int GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x5_KHR   = 0x93D3;
constexpr int GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x6_KHR   = 0x93D4;
constexpr int GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x5_KHR   = 0x93D5;
constexpr int GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x6_KHR   = 0x93D6;
constexpr int GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x8_KHR   = 0x93D7;
constexpr int GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x5_KHR  = 0x93D8;
constexpr int GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x6_KHR  = 0x93D9;
constexpr int GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x8_KHR  = 0x93DA;
constexpr int GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x10_KHR = 0x93DB;
constexpr int GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x10_KHR = 0x93DC;
constexpr int GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x12_KHR = 0x93DD;

#pragma endregion

#pragma region GL_KHR_texture_compression_astc_ldr

#pragma endregion

#pragma region GL_KHR_texture_compression_astc_sliced_3d

#pragma endregion

#pragma region GL_KHR_parallel_shader_compile

constexpr int GL_MAX_SHADER_COMPILER_THREADS_KHR = 0x91B0;
constexpr int GL_COMPLETION_STATUS_KHR           = 0x91B1;

void glMaxShaderCompilerThreadsKHR(GLuint count);

#pragma endregion

#pragma region GL_MESA_framebuffer_flip_y

constexpr int GL_FRAMEBUFFER_FLIP_Y_MESA = 0x8BBB;

void glFramebufferParameteriMESA(GLenum target, GLenum pname, GLint param);
void glGetFramebufferParameterivMESA(GLenum target, GLenum pname, GLint* params);

#pragma endregion

#pragma region GL_NV_bindless_multi_draw_indirect

void glMultiDrawArraysIndirectBindlessNV(GLenum mode,
                                         const void* indirect,
                                         GLsizei drawCount,
                                         GLsizei stride,
                                         GLint vertexBufferCount);
void glMultiDrawElementsIndirectBindlessNV(GLenum mode,
                                           GLenum type,
                                           const void* indirect,
                                           GLsizei drawCount,
                                           GLsizei stride,
                                           GLint vertexBufferCount);

#pragma endregion

#pragma region GL_NV_bindless_multi_draw_indirect_count

void glMultiDrawArraysIndirectBindlessCountNV(GLenum mode,
                                              const void* indirect,
                                              GLsizei drawCount,
                                              GLsizei maxDrawCount,
                                              GLsizei stride,
                                              GLint vertexBufferCount);
void glMultiDrawElementsIndirectBindlessCountNV(GLenum mode,
                                                GLenum type,
                                                const void* indirect,
                                                GLsizei drawCount,
                                                GLsizei maxDrawCount,
                                                GLsizei stride,
                                                GLint vertexBufferCount);

#pragma endregion

#pragma region GL_NV_bindless_texture

GLuint64 glGetTextureHandleNV(GLuint texture);
GLuint64 glGetTextureSamplerHandleNV(GLuint texture, GLuint sampler);
void glMakeTextureHandleResidentNV(GLuint64 handle);
void glMakeTextureHandleNonResidentNV(GLuint64 handle);
GLuint64 glGetImageHandleNV(GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
void glMakeImageHandleResidentNV(GLuint64 handle, GLenum access);
void glMakeImageHandleNonResidentNV(GLuint64 handle);
void glUniformHandleui64NV(GLint location, GLuint64 value);
void glUniformHandleui64vNV(GLint location, GLsizei count, const GLuint64* value);
void glProgramUniformHandleui64NV(GLuint program, GLint location, GLuint64 value);
void glProgramUniformHandleui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64* values);
GLboolean glIsTextureHandleResidentNV(GLuint64 handle);
GLboolean glIsImageHandleResidentNV(GLuint64 handle);

#pragma endregion

#pragma region GL_NV_blend_equation_advanced

constexpr int GL_BLEND_OVERLAP_NV           = 0x9281;
constexpr int GL_BLEND_PREMULTIPLIED_SRC_NV = 0x9280;
constexpr int GL_BLUE_NV                    = 0x1905;
constexpr int GL_COLORBURN_NV               = 0x929A;
constexpr int GL_COLORDODGE_NV              = 0x9299;
constexpr int GL_CONJOINT_NV                = 0x9284;
constexpr int GL_CONTRAST_NV                = 0x92A1;
constexpr int GL_DARKEN_NV                  = 0x9297;
constexpr int GL_DIFFERENCE_NV              = 0x929E;
constexpr int GL_DISJOINT_NV                = 0x9283;
constexpr int GL_DST_ATOP_NV                = 0x928F;
constexpr int GL_DST_IN_NV                  = 0x928B;
constexpr int GL_DST_NV                     = 0x9287;
constexpr int GL_DST_OUT_NV                 = 0x928D;
constexpr int GL_DST_OVER_NV                = 0x9289;
constexpr int GL_EXCLUSION_NV               = 0x92A0;
constexpr int GL_GREEN_NV                   = 0x1904;
constexpr int GL_HARDLIGHT_NV               = 0x929B;
constexpr int GL_HARDMIX_NV                 = 0x92A9;
constexpr int GL_HSL_COLOR_NV               = 0x92AF;
constexpr int GL_HSL_HUE_NV                 = 0x92AD;
constexpr int GL_HSL_LUMINOSITY_NV          = 0x92B0;
constexpr int GL_HSL_SATURATION_NV          = 0x92AE;
constexpr int GL_INVERT_OVG_NV              = 0x92B4;
constexpr int GL_INVERT_RGB_NV              = 0x92A3;
constexpr int GL_LIGHTEN_NV                 = 0x9298;
constexpr int GL_LINEARBURN_NV              = 0x92A5;
constexpr int GL_LINEARDODGE_NV             = 0x92A4;
constexpr int GL_LINEARLIGHT_NV             = 0x92A7;
constexpr int GL_MINUS_CLAMPED_NV           = 0x92B3;
constexpr int GL_MINUS_NV                   = 0x929F;
constexpr int GL_MULTIPLY_NV                = 0x9294;
constexpr int GL_OVERLAY_NV                 = 0x9296;
constexpr int GL_PINLIGHT_NV                = 0x92A8;
constexpr int GL_PLUS_CLAMPED_ALPHA_NV      = 0x92B2;
constexpr int GL_PLUS_CLAMPED_NV            = 0x92B1;
constexpr int GL_PLUS_DARKER_NV             = 0x9292;
constexpr int GL_PLUS_NV                    = 0x9291;
constexpr int GL_RED_NV                     = 0x1903;
constexpr int GL_SCREEN_NV                  = 0x9295;
constexpr int GL_SOFTLIGHT_NV               = 0x929C;
constexpr int GL_SRC_ATOP_NV                = 0x928E;
constexpr int GL_SRC_IN_NV                  = 0x928A;
constexpr int GL_SRC_NV                     = 0x9286;
constexpr int GL_SRC_OUT_NV                 = 0x928C;
constexpr int GL_SRC_OVER_NV                = 0x9288;
constexpr int GL_UNCORRELATED_NV            = 0x9282;
constexpr int GL_VIVIDLIGHT_NV              = 0x92A6;
constexpr int GL_XOR_NV                     = 0x1506;

void glBlendParameteriNV(GLenum pname, GLint value);
void glBlendBarrierNV();

#pragma endregion

#pragma region GL_NV_blend_equation_advanced_coherent

constexpr int GL_BLEND_ADVANCED_COHERENT_NV = 0x9285;

#pragma endregion

#pragma region GL_NV_blend_minmax_factor

constexpr int GL_FACTOR_MIN_AMD = 0x901C;
constexpr int GL_FACTOR_MAX_AMD = 0x901D;

#pragma endregion

#pragma region GL_NV_clip_space_w_scaling

constexpr int GL_VIEWPORT_POSITION_W_SCALE_NV         = 0x937C;
constexpr int GL_VIEWPORT_POSITION_W_SCALE_X_COEFF_NV = 0x937D;
constexpr int GL_VIEWPORT_POSITION_W_SCALE_Y_COEFF_NV = 0x937E;

void glViewportPositionWScaleNV(GLuint index, GLfloat xcoeff, GLfloat ycoeff);

#pragma endregion

#pragma region GL_NV_command_list

constexpr int GL_TERMINATE_SEQUENCE_COMMAND_NV      = 0x0000;
constexpr int GL_NOP_COMMAND_NV                     = 0x0001;
constexpr int GL_DRAW_ELEMENTS_COMMAND_NV           = 0x0002;
constexpr int GL_DRAW_ARRAYS_COMMAND_NV             = 0x0003;
constexpr int GL_DRAW_ELEMENTS_STRIP_COMMAND_NV     = 0x0004;
constexpr int GL_DRAW_ARRAYS_STRIP_COMMAND_NV       = 0x0005;
constexpr int GL_DRAW_ELEMENTS_INSTANCED_COMMAND_NV = 0x0006;
constexpr int GL_DRAW_ARRAYS_INSTANCED_COMMAND_NV   = 0x0007;
constexpr int GL_ELEMENT_ADDRESS_COMMAND_NV         = 0x0008;
constexpr int GL_ATTRIBUTE_ADDRESS_COMMAND_NV       = 0x0009;
constexpr int GL_UNIFORM_ADDRESS_COMMAND_NV         = 0x000A;
constexpr int GL_BLEND_COLOR_COMMAND_NV             = 0x000B;
constexpr int GL_STENCIL_REF_COMMAND_NV             = 0x000C;
constexpr int GL_LINE_WIDTH_COMMAND_NV              = 0x000D;
constexpr int GL_POLYGON_OFFSET_COMMAND_NV          = 0x000E;
constexpr int GL_ALPHA_REF_COMMAND_NV               = 0x000F;
constexpr int GL_VIEWPORT_COMMAND_NV                = 0x0010;
constexpr int GL_SCISSOR_COMMAND_NV                 = 0x0011;
constexpr int GL_FRONT_FACE_COMMAND_NV              = 0x0012;

void glCreateStatesNV(GLsizei n, GLuint* states);
void glDeleteStatesNV(GLsizei n, const GLuint* states);
GLboolean glIsStateNV(GLuint state);
void glStateCaptureNV(GLuint state, GLenum mode);
GLuint glGetCommandHeaderNV(GLenum tokenID, GLuint size);
GLushort glGetStageIndexNV(GLenum shadertype);
void glDrawCommandsNV(GLenum primitiveMode,
                      GLuint buffer,
                      const GLintptr* indirects,
                      const GLsizei* sizes,
                      GLuint count);
void glDrawCommandsAddressNV(GLenum primitiveMode, const GLuint64* indirects, const GLsizei* sizes, GLuint count);
void glDrawCommandsStatesNV(GLuint buffer,
                            const GLintptr* indirects,
                            const GLsizei* sizes,
                            const GLuint* states,
                            const GLuint* fbos,
                            GLuint count);
void glDrawCommandsStatesAddressNV(const GLuint64* indirects,
                                   const GLsizei* sizes,
                                   const GLuint* states,
                                   const GLuint* fbos,
                                   GLuint count);
void glCreateCommandListsNV(GLsizei n, GLuint* lists);
void glDeleteCommandListsNV(GLsizei n, const GLuint* lists);
GLboolean glIsCommandListNV(GLuint list);
void glListDrawCommandsStatesClientNV(GLuint list,
                                      GLuint segment,
                                      const void** indirects,
                                      const GLsizei* sizes,
                                      const GLuint* states,
                                      const GLuint* fbos,
                                      GLuint count);
void glCommandListSegmentsNV(GLuint list, GLuint segments);
void glCompileCommandListNV(GLuint list);
void glCallCommandListNV(GLuint list);

#pragma endregion

#pragma region GL_NV_compute_shader_derivatives

#pragma endregion

#pragma region GL_NV_conditional_render

constexpr int GL_QUERY_WAIT_NV              = 0x8E13;
constexpr int GL_QUERY_NO_WAIT_NV           = 0x8E14;
constexpr int GL_QUERY_BY_REGION_WAIT_NV    = 0x8E15;
constexpr int GL_QUERY_BY_REGION_NO_WAIT_NV = 0x8E16;

void glBeginConditionalRenderNV(GLuint id, GLenum mode);
void glEndConditionalRenderNV();

#pragma endregion

#pragma region GL_NV_conservative_raster

constexpr int GL_CONSERVATIVE_RASTERIZATION_NV       = 0x9346;
constexpr int GL_SUBPIXEL_PRECISION_BIAS_X_BITS_NV   = 0x9347;
constexpr int GL_SUBPIXEL_PRECISION_BIAS_Y_BITS_NV   = 0x9348;
constexpr int GL_MAX_SUBPIXEL_PRECISION_BIAS_BITS_NV = 0x9349;

void glSubpixelPrecisionBiasNV(GLuint xbits, GLuint ybits);

#pragma endregion

#pragma region GL_NV_conservative_raster_dilate

constexpr int GL_CONSERVATIVE_RASTER_DILATE_NV             = 0x9379;
constexpr int GL_CONSERVATIVE_RASTER_DILATE_RANGE_NV       = 0x937A;
constexpr int GL_CONSERVATIVE_RASTER_DILATE_GRANULARITY_NV = 0x937B;

void glConservativeRasterParameterfNV(GLenum pname, GLfloat value);

#pragma endregion

#pragma region GL_NV_conservative_raster_pre_snap

constexpr int GL_CONSERVATIVE_RASTER_MODE_PRE_SNAP_NV = 0x9550;

#pragma endregion

#pragma region GL_NV_conservative_raster_pre_snap_triangles

constexpr int GL_CONSERVATIVE_RASTER_MODE_NV                    = 0x954D;
constexpr int GL_CONSERVATIVE_RASTER_MODE_POST_SNAP_NV          = 0x954E;
constexpr int GL_CONSERVATIVE_RASTER_MODE_PRE_SNAP_TRIANGLES_NV = 0x954F;

void glConservativeRasterParameteriNV(GLenum pname, GLint param);

#pragma endregion

#pragma region GL_NV_conservative_raster_underestimation

#pragma endregion

#pragma region GL_NV_depth_buffer_float

constexpr int GL_DEPTH_COMPONENT32F_NV             = 0x8DAB;
constexpr int GL_DEPTH32F_STENCIL8_NV              = 0x8DAC;
constexpr int GL_FLOAT_32_UNSIGNED_INT_24_8_REV_NV = 0x8DAD;
constexpr int GL_DEPTH_BUFFER_FLOAT_MODE_NV        = 0x8DAF;

void glDepthRangedNV(GLdouble zNear, GLdouble zFar);
void glClearDepthdNV(GLdouble depth);
void glDepthBoundsdNV(GLdouble zmin, GLdouble zmax);

#pragma endregion

#pragma region GL_NV_draw_vulkan_image

typedef void (*GLVULKANPROCNV)(void);

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
                     GLfloat t1);
GLVULKANPROCNV glGetVkProcAddrNV(const GLchar* name);
void glWaitVkSemaphoreNV(GLuint64 vkSemaphore);
void glSignalVkSemaphoreNV(GLuint64 vkSemaphore);
void glSignalVkFenceNV(GLuint64 vkFence);

#pragma endregion

#pragma region GL_NV_fill_rectangle

constexpr int GL_FILL_RECTANGLE_NV = 0x933C;

#pragma endregion

#pragma region GL_NV_fragment_coverage_to_color

constexpr int GL_FRAGMENT_COVERAGE_TO_COLOR_NV = 0x92DD;
constexpr int GL_FRAGMENT_COVERAGE_COLOR_NV    = 0x92DE;

void glFragmentCoverageColorNV(GLuint color);

#pragma endregion

#pragma region GL_NV_fragment_shader_barycentric

#pragma endregion

#pragma region GL_NV_fragment_shader_interlock

#pragma endregion

#pragma region GL_NV_framebuffer_mixed_samples

constexpr int GL_COVERAGE_MODULATION_TABLE_NV       = 0x9331;
constexpr int GL_COLOR_SAMPLES_NV                   = 0x8E20;
constexpr int GL_DEPTH_SAMPLES_NV                   = 0x932D;
constexpr int GL_STENCIL_SAMPLES_NV                 = 0x932E;
constexpr int GL_MIXED_DEPTH_SAMPLES_SUPPORTED_NV   = 0x932F;
constexpr int GL_MIXED_STENCIL_SAMPLES_SUPPORTED_NV = 0x9330;
constexpr int GL_COVERAGE_MODULATION_NV             = 0x9332;
constexpr int GL_COVERAGE_MODULATION_TABLE_SIZE_NV  = 0x9333;

void glCoverageModulationTableNV(GLsizei n, const GLfloat* v);
void glGetCoverageModulationTableNV(GLsizei bufSize, GLfloat* v);
void glCoverageModulationNV(GLenum components);

#pragma endregion

#pragma region GL_NV_framebuffer_multisample_coverage

constexpr int GL_RENDERBUFFER_COVERAGE_SAMPLES_NV  = 0x8CAB;
constexpr int GL_RENDERBUFFER_COLOR_SAMPLES_NV     = 0x8E10;
constexpr int GL_MAX_MULTISAMPLE_COVERAGE_MODES_NV = 0x8E11;
constexpr int GL_MULTISAMPLE_COVERAGE_MODES_NV     = 0x8E12;

void glRenderbufferStorageMultisampleCoverageNV(GLenum target,
                                                GLsizei coverageSamples,
                                                GLsizei colorSamples,
                                                GLenum internalformat,
                                                GLsizei width,
                                                GLsizei height);

#pragma endregion

#pragma region GL_NV_geometry_shader_passthrough

#pragma endregion

#pragma region GL_NV_gpu_shader5

typedef khronos_int64_t GLint64EXT;

constexpr int GL_INT64_NV               = 0x140E;
constexpr int GL_UNSIGNED_INT64_NV      = 0x140F;
constexpr int GL_INT8_NV                = 0x8FE0;
constexpr int GL_INT8_VEC2_NV           = 0x8FE1;
constexpr int GL_INT8_VEC3_NV           = 0x8FE2;
constexpr int GL_INT8_VEC4_NV           = 0x8FE3;
constexpr int GL_INT16_NV               = 0x8FE4;
constexpr int GL_INT16_VEC2_NV          = 0x8FE5;
constexpr int GL_INT16_VEC3_NV          = 0x8FE6;
constexpr int GL_INT16_VEC4_NV          = 0x8FE7;
constexpr int GL_INT64_VEC2_NV          = 0x8FE9;
constexpr int GL_INT64_VEC3_NV          = 0x8FEA;
constexpr int GL_INT64_VEC4_NV          = 0x8FEB;
constexpr int GL_UNSIGNED_INT8_NV       = 0x8FEC;
constexpr int GL_UNSIGNED_INT8_VEC2_NV  = 0x8FED;
constexpr int GL_UNSIGNED_INT8_VEC3_NV  = 0x8FEE;
constexpr int GL_UNSIGNED_INT8_VEC4_NV  = 0x8FEF;
constexpr int GL_UNSIGNED_INT16_NV      = 0x8FF0;
constexpr int GL_UNSIGNED_INT16_VEC2_NV = 0x8FF1;
constexpr int GL_UNSIGNED_INT16_VEC3_NV = 0x8FF2;
constexpr int GL_UNSIGNED_INT16_VEC4_NV = 0x8FF3;
constexpr int GL_UNSIGNED_INT64_VEC2_NV = 0x8FF5;
constexpr int GL_UNSIGNED_INT64_VEC3_NV = 0x8FF6;
constexpr int GL_UNSIGNED_INT64_VEC4_NV = 0x8FF7;
constexpr int GL_FLOAT16_NV             = 0x8FF8;
constexpr int GL_FLOAT16_VEC2_NV        = 0x8FF9;
constexpr int GL_FLOAT16_VEC3_NV        = 0x8FFA;
constexpr int GL_FLOAT16_VEC4_NV        = 0x8FFB;

void glUniform1i64NV(GLint location, GLint64EXT x);
void glUniform2i64NV(GLint location, GLint64EXT x, GLint64EXT y);
void glUniform3i64NV(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
void glUniform4i64NV(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
void glUniform1i64vNV(GLint location, GLsizei count, const GLint64EXT* value);
void glUniform2i64vNV(GLint location, GLsizei count, const GLint64EXT* value);
void glUniform3i64vNV(GLint location, GLsizei count, const GLint64EXT* value);
void glUniform4i64vNV(GLint location, GLsizei count, const GLint64EXT* value);
void glUniform1ui64NV(GLint location, GLuint64EXT x);
void glUniform2ui64NV(GLint location, GLuint64EXT x, GLuint64EXT y);
void glUniform3ui64NV(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
void glUniform4ui64NV(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
void glUniform1ui64vNV(GLint location, GLsizei count, const GLuint64EXT* value);
void glUniform2ui64vNV(GLint location, GLsizei count, const GLuint64EXT* value);
void glUniform3ui64vNV(GLint location, GLsizei count, const GLuint64EXT* value);
void glUniform4ui64vNV(GLint location, GLsizei count, const GLuint64EXT* value);
void glGetUniformi64vNV(GLuint program, GLint location, GLint64EXT* params);
void glProgramUniform1i64NV(GLuint program, GLint location, GLint64EXT x);
void glProgramUniform2i64NV(GLuint program, GLint location, GLint64EXT x, GLint64EXT y);
void glProgramUniform3i64NV(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
void glProgramUniform4i64NV(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
void glProgramUniform1i64vNV(GLuint program, GLint location, GLsizei count, const GLint64EXT* value);
void glProgramUniform2i64vNV(GLuint program, GLint location, GLsizei count, const GLint64EXT* value);
void glProgramUniform3i64vNV(GLuint program, GLint location, GLsizei count, const GLint64EXT* value);
void glProgramUniform4i64vNV(GLuint program, GLint location, GLsizei count, const GLint64EXT* value);
void glProgramUniform1ui64NV(GLuint program, GLint location, GLuint64EXT x);
void glProgramUniform2ui64NV(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y);
void glProgramUniform3ui64NV(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
void glProgramUniform4ui64NV(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
void glProgramUniform1ui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT* value);
void glProgramUniform2ui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT* value);
void glProgramUniform3ui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT* value);
void glProgramUniform4ui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT* value);

#pragma endregion

#pragma region GL_NV_internalformat_sample_query

constexpr int GL_MULTISAMPLES_NV        = 0x9371;
constexpr int GL_SUPERSAMPLE_SCALE_X_NV = 0x9372;
constexpr int GL_SUPERSAMPLE_SCALE_Y_NV = 0x9373;
constexpr int GL_CONFORMANT_NV          = 0x9374;

void glGetInternalformatSampleivNV(GLenum target,
                                   GLenum internalformat,
                                   GLsizei samples,
                                   GLenum pname,
                                   GLsizei count,
                                   GLint* params);

#pragma endregion

#pragma region GL_NV_memory_attachment

constexpr int GL_ATTACHED_MEMORY_OBJECT_NV      = 0x95A4;
constexpr int GL_ATTACHED_MEMORY_OFFSET_NV      = 0x95A5;
constexpr int GL_MEMORY_ATTACHABLE_ALIGNMENT_NV = 0x95A6;
constexpr int GL_MEMORY_ATTACHABLE_SIZE_NV      = 0x95A7;
constexpr int GL_MEMORY_ATTACHABLE_NV           = 0x95A8;
constexpr int GL_DETACHED_MEMORY_INCARNATION_NV = 0x95A9;
constexpr int GL_DETACHED_TEXTURES_NV           = 0x95AA;
constexpr int GL_DETACHED_BUFFERS_NV            = 0x95AB;
constexpr int GL_MAX_DETACHED_TEXTURES_NV       = 0x95AC;
constexpr int GL_MAX_DETACHED_BUFFERS_NV        = 0x95AD;

void glGetMemoryObjectDetachedResourcesuivNV(GLuint memory, GLenum pname, GLint first, GLsizei count, GLuint* params);
void glResetMemoryObjectParameterNV(GLuint memory, GLenum pname);
void glTexAttachMemoryNV(GLenum target, GLuint memory, GLuint64 offset);
void glBufferAttachMemoryNV(GLenum target, GLuint memory, GLuint64 offset);
void glTextureAttachMemoryNV(GLuint texture, GLuint memory, GLuint64 offset);
void glNamedBufferAttachMemoryNV(GLuint buffer, GLuint memory, GLuint64 offset);

#pragma endregion

#pragma region GL_NV_mesh_shader

constexpr int GL_MESH_SHADER_NV                                     = 0x9559;
constexpr int GL_TASK_SHADER_NV                                     = 0x955A;
constexpr int GL_MAX_MESH_UNIFORM_BLOCKS_NV                         = 0x8E60;
constexpr int GL_MAX_MESH_TEXTURE_IMAGE_UNITS_NV                    = 0x8E61;
constexpr int GL_MAX_MESH_IMAGE_UNIFORMS_NV                         = 0x8E62;
constexpr int GL_MAX_MESH_UNIFORM_COMPONENTS_NV                     = 0x8E63;
constexpr int GL_MAX_MESH_ATOMIC_COUNTER_BUFFERS_NV                 = 0x8E64;
constexpr int GL_MAX_MESH_ATOMIC_COUNTERS_NV                        = 0x8E65;
constexpr int GL_MAX_MESH_SHADER_STORAGE_BLOCKS_NV                  = 0x8E66;
constexpr int GL_MAX_COMBINED_MESH_UNIFORM_COMPONENTS_NV            = 0x8E67;
constexpr int GL_MAX_TASK_UNIFORM_BLOCKS_NV                         = 0x8E68;
constexpr int GL_MAX_TASK_TEXTURE_IMAGE_UNITS_NV                    = 0x8E69;
constexpr int GL_MAX_TASK_IMAGE_UNIFORMS_NV                         = 0x8E6A;
constexpr int GL_MAX_TASK_UNIFORM_COMPONENTS_NV                     = 0x8E6B;
constexpr int GL_MAX_TASK_ATOMIC_COUNTER_BUFFERS_NV                 = 0x8E6C;
constexpr int GL_MAX_TASK_ATOMIC_COUNTERS_NV                        = 0x8E6D;
constexpr int GL_MAX_TASK_SHADER_STORAGE_BLOCKS_NV                  = 0x8E6E;
constexpr int GL_MAX_COMBINED_TASK_UNIFORM_COMPONENTS_NV            = 0x8E6F;
constexpr int GL_MAX_MESH_WORK_GROUP_INVOCATIONS_NV                 = 0x95A2;
constexpr int GL_MAX_TASK_WORK_GROUP_INVOCATIONS_NV                 = 0x95A3;
constexpr int GL_MAX_MESH_TOTAL_MEMORY_SIZE_NV                      = 0x9536;
constexpr int GL_MAX_TASK_TOTAL_MEMORY_SIZE_NV                      = 0x9537;
constexpr int GL_MAX_MESH_OUTPUT_VERTICES_NV                        = 0x9538;
constexpr int GL_MAX_MESH_OUTPUT_PRIMITIVES_NV                      = 0x9539;
constexpr int GL_MAX_TASK_OUTPUT_COUNT_NV                           = 0x953A;
constexpr int GL_MAX_DRAW_MESH_TASKS_COUNT_NV                       = 0x953D;
constexpr int GL_MAX_MESH_VIEWS_NV                                  = 0x9557;
constexpr int GL_MESH_OUTPUT_PER_VERTEX_GRANULARITY_NV              = 0x92DF;
constexpr int GL_MESH_OUTPUT_PER_PRIMITIVE_GRANULARITY_NV           = 0x9543;
constexpr int GL_MAX_MESH_WORK_GROUP_SIZE_NV                        = 0x953B;
constexpr int GL_MAX_TASK_WORK_GROUP_SIZE_NV                        = 0x953C;
constexpr int GL_MESH_WORK_GROUP_SIZE_NV                            = 0x953E;
constexpr int GL_TASK_WORK_GROUP_SIZE_NV                            = 0x953F;
constexpr int GL_MESH_VERTICES_OUT_NV                               = 0x9579;
constexpr int GL_MESH_PRIMITIVES_OUT_NV                             = 0x957A;
constexpr int GL_MESH_OUTPUT_TYPE_NV                                = 0x957B;
constexpr int GL_UNIFORM_BLOCK_REFERENCED_BY_MESH_SHADER_NV         = 0x959C;
constexpr int GL_UNIFORM_BLOCK_REFERENCED_BY_TASK_SHADER_NV         = 0x959D;
constexpr int GL_REFERENCED_BY_MESH_SHADER_NV                       = 0x95A0;
constexpr int GL_REFERENCED_BY_TASK_SHADER_NV                       = 0x95A1;
constexpr int GL_MESH_SHADER_BIT_NV                                 = 0x00000040;
constexpr int GL_TASK_SHADER_BIT_NV                                 = 0x00000080;
constexpr int GL_MESH_SUBROUTINE_NV                                 = 0x957C;
constexpr int GL_TASK_SUBROUTINE_NV                                 = 0x957D;
constexpr int GL_MESH_SUBROUTINE_UNIFORM_NV                         = 0x957E;
constexpr int GL_TASK_SUBROUTINE_UNIFORM_NV                         = 0x957F;
constexpr int GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_MESH_SHADER_NV = 0x959E;
constexpr int GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TASK_SHADER_NV = 0x959F;

void glDrawMeshTasksNV(GLuint first, GLuint count);
void glDrawMeshTasksIndirectNV(GLintptr indirect);
void glMultiDrawMeshTasksIndirectNV(GLintptr indirect, GLsizei drawcount, GLsizei stride);
void glMultiDrawMeshTasksIndirectCountNV(GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);

#pragma endregion

#pragma region GL_NV_path_rendering

constexpr int GL_PATH_FORMAT_SVG_NV                      = 0x9070;
constexpr int GL_PATH_FORMAT_PS_NV                       = 0x9071;
constexpr int GL_STANDARD_FONT_NAME_NV                   = 0x9072;
constexpr int GL_SYSTEM_FONT_NAME_NV                     = 0x9073;
constexpr int GL_FILE_NAME_NV                            = 0x9074;
constexpr int GL_PATH_STROKE_WIDTH_NV                    = 0x9075;
constexpr int GL_PATH_END_CAPS_NV                        = 0x9076;
constexpr int GL_PATH_INITIAL_END_CAP_NV                 = 0x9077;
constexpr int GL_PATH_TERMINAL_END_CAP_NV                = 0x9078;
constexpr int GL_PATH_JOIN_STYLE_NV                      = 0x9079;
constexpr int GL_PATH_MITER_LIMIT_NV                     = 0x907A;
constexpr int GL_PATH_DASH_CAPS_NV                       = 0x907B;
constexpr int GL_PATH_INITIAL_DASH_CAP_NV                = 0x907C;
constexpr int GL_PATH_TERMINAL_DASH_CAP_NV               = 0x907D;
constexpr int GL_PATH_DASH_OFFSET_NV                     = 0x907E;
constexpr int GL_PATH_CLIENT_LENGTH_NV                   = 0x907F;
constexpr int GL_PATH_FILL_MODE_NV                       = 0x9080;
constexpr int GL_PATH_FILL_MASK_NV                       = 0x9081;
constexpr int GL_PATH_FILL_COVER_MODE_NV                 = 0x9082;
constexpr int GL_PATH_STROKE_COVER_MODE_NV               = 0x9083;
constexpr int GL_PATH_STROKE_MASK_NV                     = 0x9084;
constexpr int GL_COUNT_UP_NV                             = 0x9088;
constexpr int GL_COUNT_DOWN_NV                           = 0x9089;
constexpr int GL_PATH_OBJECT_BOUNDING_BOX_NV             = 0x908A;
constexpr int GL_CONVEX_HULL_NV                          = 0x908B;
constexpr int GL_BOUNDING_BOX_NV                         = 0x908D;
constexpr int GL_TRANSLATE_X_NV                          = 0x908E;
constexpr int GL_TRANSLATE_Y_NV                          = 0x908F;
constexpr int GL_TRANSLATE_2D_NV                         = 0x9090;
constexpr int GL_TRANSLATE_3D_NV                         = 0x9091;
constexpr int GL_AFFINE_2D_NV                            = 0x9092;
constexpr int GL_AFFINE_3D_NV                            = 0x9094;
constexpr int GL_TRANSPOSE_AFFINE_2D_NV                  = 0x9096;
constexpr int GL_TRANSPOSE_AFFINE_3D_NV                  = 0x9098;
constexpr int GL_UTF8_NV                                 = 0x909A;
constexpr int GL_UTF16_NV                                = 0x909B;
constexpr int GL_BOUNDING_BOX_OF_BOUNDING_BOXES_NV       = 0x909C;
constexpr int GL_PATH_COMMAND_COUNT_NV                   = 0x909D;
constexpr int GL_PATH_COORD_COUNT_NV                     = 0x909E;
constexpr int GL_PATH_DASH_ARRAY_COUNT_NV                = 0x909F;
constexpr int GL_PATH_COMPUTED_LENGTH_NV                 = 0x90A0;
constexpr int GL_PATH_FILL_BOUNDING_BOX_NV               = 0x90A1;
constexpr int GL_PATH_STROKE_BOUNDING_BOX_NV             = 0x90A2;
constexpr int GL_SQUARE_NV                               = 0x90A3;
constexpr int GL_ROUND_NV                                = 0x90A4;
constexpr int GL_TRIANGULAR_NV                           = 0x90A5;
constexpr int GL_BEVEL_NV                                = 0x90A6;
constexpr int GL_MITER_REVERT_NV                         = 0x90A7;
constexpr int GL_MITER_TRUNCATE_NV                       = 0x90A8;
constexpr int GL_SKIP_MISSING_GLYPH_NV                   = 0x90A9;
constexpr int GL_USE_MISSING_GLYPH_NV                    = 0x90AA;
constexpr int GL_PATH_ERROR_POSITION_NV                  = 0x90AB;
constexpr int GL_ACCUM_ADJACENT_PAIRS_NV                 = 0x90AD;
constexpr int GL_ADJACENT_PAIRS_NV                       = 0x90AE;
constexpr int GL_FIRST_TO_REST_NV                        = 0x90AF;
constexpr int GL_PATH_GEN_MODE_NV                        = 0x90B0;
constexpr int GL_PATH_GEN_COEFF_NV                       = 0x90B1;
constexpr int GL_PATH_GEN_COMPONENTS_NV                  = 0x90B3;
constexpr int GL_PATH_STENCIL_FUNC_NV                    = 0x90B7;
constexpr int GL_PATH_STENCIL_REF_NV                     = 0x90B8;
constexpr int GL_PATH_STENCIL_VALUE_MASK_NV              = 0x90B9;
constexpr int GL_PATH_STENCIL_DEPTH_OFFSET_FACTOR_NV     = 0x90BD;
constexpr int GL_PATH_STENCIL_DEPTH_OFFSET_UNITS_NV      = 0x90BE;
constexpr int GL_PATH_COVER_DEPTH_FUNC_NV                = 0x90BF;
constexpr int GL_PATH_DASH_OFFSET_RESET_NV               = 0x90B4;
constexpr int GL_MOVE_TO_RESETS_NV                       = 0x90B5;
constexpr int GL_MOVE_TO_CONTINUES_NV                    = 0x90B6;
constexpr int GL_CLOSE_PATH_NV                           = 0x00;
constexpr int GL_MOVE_TO_NV                              = 0x02;
constexpr int GL_RELATIVE_MOVE_TO_NV                     = 0x03;
constexpr int GL_LINE_TO_NV                              = 0x04;
constexpr int GL_RELATIVE_LINE_TO_NV                     = 0x05;
constexpr int GL_HORIZONTAL_LINE_TO_NV                   = 0x06;
constexpr int GL_RELATIVE_HORIZONTAL_LINE_TO_NV          = 0x07;
constexpr int GL_VERTICAL_LINE_TO_NV                     = 0x08;
constexpr int GL_RELATIVE_VERTICAL_LINE_TO_NV            = 0x09;
constexpr int GL_QUADRATIC_CURVE_TO_NV                   = 0x0A;
constexpr int GL_RELATIVE_QUADRATIC_CURVE_TO_NV          = 0x0B;
constexpr int GL_CUBIC_CURVE_TO_NV                       = 0x0C;
constexpr int GL_RELATIVE_CUBIC_CURVE_TO_NV              = 0x0D;
constexpr int GL_SMOOTH_QUADRATIC_CURVE_TO_NV            = 0x0E;
constexpr int GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV   = 0x0F;
constexpr int GL_SMOOTH_CUBIC_CURVE_TO_NV                = 0x10;
constexpr int GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV       = 0x11;
constexpr int GL_SMALL_CCW_ARC_TO_NV                     = 0x12;
constexpr int GL_RELATIVE_SMALL_CCW_ARC_TO_NV            = 0x13;
constexpr int GL_SMALL_CW_ARC_TO_NV                      = 0x14;
constexpr int GL_RELATIVE_SMALL_CW_ARC_TO_NV             = 0x15;
constexpr int GL_LARGE_CCW_ARC_TO_NV                     = 0x16;
constexpr int GL_RELATIVE_LARGE_CCW_ARC_TO_NV            = 0x17;
constexpr int GL_LARGE_CW_ARC_TO_NV                      = 0x18;
constexpr int GL_RELATIVE_LARGE_CW_ARC_TO_NV             = 0x19;
constexpr int GL_RESTART_PATH_NV                         = 0xF0;
constexpr int GL_DUP_FIRST_CUBIC_CURVE_TO_NV             = 0xF2;
constexpr int GL_DUP_LAST_CUBIC_CURVE_TO_NV              = 0xF4;
constexpr int GL_RECT_NV                                 = 0xF6;
constexpr int GL_CIRCULAR_CCW_ARC_TO_NV                  = 0xF8;
constexpr int GL_CIRCULAR_CW_ARC_TO_NV                   = 0xFA;
constexpr int GL_CIRCULAR_TANGENT_ARC_TO_NV              = 0xFC;
constexpr int GL_ARC_TO_NV                               = 0xFE;
constexpr int GL_RELATIVE_ARC_TO_NV                      = 0xFF;
constexpr int GL_BOLD_BIT_NV                             = 0x01;
constexpr int GL_ITALIC_BIT_NV                           = 0x02;
constexpr int GL_GLYPH_WIDTH_BIT_NV                      = 0x01;
constexpr int GL_GLYPH_HEIGHT_BIT_NV                     = 0x02;
constexpr int GL_GLYPH_HORIZONTAL_BEARING_X_BIT_NV       = 0x04;
constexpr int GL_GLYPH_HORIZONTAL_BEARING_Y_BIT_NV       = 0x08;
constexpr int GL_GLYPH_HORIZONTAL_BEARING_ADVANCE_BIT_NV = 0x10;
constexpr int GL_GLYPH_VERTICAL_BEARING_X_BIT_NV         = 0x20;
constexpr int GL_GLYPH_VERTICAL_BEARING_Y_BIT_NV         = 0x40;
constexpr int GL_GLYPH_VERTICAL_BEARING_ADVANCE_BIT_NV   = 0x80;
constexpr int GL_GLYPH_HAS_KERNING_BIT_NV                = 0x100;
constexpr int GL_FONT_X_MIN_BOUNDS_BIT_NV                = 0x00010000;
constexpr int GL_FONT_Y_MIN_BOUNDS_BIT_NV                = 0x00020000;
constexpr int GL_FONT_X_MAX_BOUNDS_BIT_NV                = 0x00040000;
constexpr int GL_FONT_Y_MAX_BOUNDS_BIT_NV                = 0x00080000;
constexpr int GL_FONT_UNITS_PER_EM_BIT_NV                = 0x00100000;
constexpr int GL_FONT_ASCENDER_BIT_NV                    = 0x00200000;
constexpr int GL_FONT_DESCENDER_BIT_NV                   = 0x00400000;
constexpr int GL_FONT_HEIGHT_BIT_NV                      = 0x00800000;
constexpr int GL_FONT_MAX_ADVANCE_WIDTH_BIT_NV           = 0x01000000;
constexpr int GL_FONT_MAX_ADVANCE_HEIGHT_BIT_NV          = 0x02000000;
constexpr int GL_FONT_UNDERLINE_POSITION_BIT_NV          = 0x04000000;
constexpr int GL_FONT_UNDERLINE_THICKNESS_BIT_NV         = 0x08000000;
constexpr int GL_FONT_HAS_KERNING_BIT_NV                 = 0x10000000;
constexpr int GL_ROUNDED_RECT_NV                         = 0xE8;
constexpr int GL_RELATIVE_ROUNDED_RECT_NV                = 0xE9;
constexpr int GL_ROUNDED_RECT2_NV                        = 0xEA;
constexpr int GL_RELATIVE_ROUNDED_RECT2_NV               = 0xEB;
constexpr int GL_ROUNDED_RECT4_NV                        = 0xEC;
constexpr int GL_RELATIVE_ROUNDED_RECT4_NV               = 0xED;
constexpr int GL_ROUNDED_RECT8_NV                        = 0xEE;
constexpr int GL_RELATIVE_ROUNDED_RECT8_NV               = 0xEF;
constexpr int GL_RELATIVE_RECT_NV                        = 0xF7;
constexpr int GL_FONT_GLYPHS_AVAILABLE_NV                = 0x9368;
constexpr int GL_FONT_TARGET_UNAVAILABLE_NV              = 0x9369;
constexpr int GL_FONT_UNAVAILABLE_NV                     = 0x936A;
constexpr int GL_FONT_UNINTELLIGIBLE_NV                  = 0x936B;
constexpr int GL_CONIC_CURVE_TO_NV                       = 0x1A;
constexpr int GL_RELATIVE_CONIC_CURVE_TO_NV              = 0x1B;
constexpr int GL_FONT_NUM_GLYPH_INDICES_BIT_NV           = 0x20000000;
constexpr int GL_STANDARD_FONT_FORMAT_NV                 = 0x936C;
constexpr int GL_PATH_PROJECTION_NV                      = 0x1701;
constexpr int GL_PATH_MODELVIEW_NV                       = 0x1700;
constexpr int GL_PATH_MODELVIEW_STACK_DEPTH_NV           = 0x0BA3;
constexpr int GL_PATH_MODELVIEW_MATRIX_NV                = 0x0BA6;
constexpr int GL_PATH_MAX_MODELVIEW_STACK_DEPTH_NV       = 0x0D36;
constexpr int GL_PATH_TRANSPOSE_MODELVIEW_MATRIX_NV      = 0x84E3;
constexpr int GL_PATH_PROJECTION_STACK_DEPTH_NV          = 0x0BA4;
constexpr int GL_PATH_PROJECTION_MATRIX_NV               = 0x0BA7;
constexpr int GL_PATH_MAX_PROJECTION_STACK_DEPTH_NV      = 0x0D38;
constexpr int GL_PATH_TRANSPOSE_PROJECTION_MATRIX_NV     = 0x84E4;
constexpr int GL_FRAGMENT_INPUT_NV                       = 0x936D;

GLuint glGenPathsNV(GLsizei range);
void glDeletePathsNV(GLuint path, GLsizei range);
GLboolean glIsPathNV(GLuint path);
void glPathCommandsNV(GLuint path,
                      GLsizei numCommands,
                      const GLubyte* commands,
                      GLsizei numCoords,
                      GLenum coordType,
                      const void* coords);
void glPathCoordsNV(GLuint path, GLsizei numCoords, GLenum coordType, const void* coords);
void glPathSubCommandsNV(GLuint path,
                         GLsizei commandStart,
                         GLsizei commandsToDelete,
                         GLsizei numCommands,
                         const GLubyte* commands,
                         GLsizei numCoords,
                         GLenum coordType,
                         const void* coords);
void glPathSubCoordsNV(GLuint path, GLsizei coordStart, GLsizei numCoords, GLenum coordType, const void* coords);
void glPathStringNV(GLuint path, GLenum format, GLsizei length, const void* pathString);
void glPathGlyphsNV(GLuint firstPathName,
                    GLenum fontTarget,
                    const void* fontName,
                    GLbitfield fontStyle,
                    GLsizei numGlyphs,
                    GLenum type,
                    const void* charcodes,
                    GLenum handleMissingGlyphs,
                    GLuint pathParameterTemplate,
                    GLfloat emScale);
void glPathGlyphRangeNV(GLuint firstPathName,
                        GLenum fontTarget,
                        const void* fontName,
                        GLbitfield fontStyle,
                        GLuint firstGlyph,
                        GLsizei numGlyphs,
                        GLenum handleMissingGlyphs,
                        GLuint pathParameterTemplate,
                        GLfloat emScale);
void glWeightPathsNV(GLuint resultPath, GLsizei numPaths, const GLuint* paths, const GLfloat* weights);
void glCopyPathNV(GLuint resultPath, GLuint srcPath);
void glInterpolatePathsNV(GLuint resultPath, GLuint pathA, GLuint pathB, GLfloat weight);
void glTransformPathNV(GLuint resultPath, GLuint srcPath, GLenum transformType, const GLfloat* transformValues);
void glPathParameterivNV(GLuint path, GLenum pname, const GLint* value);
void glPathParameteriNV(GLuint path, GLenum pname, GLint value);
void glPathParameterfvNV(GLuint path, GLenum pname, const GLfloat* value);
void glPathParameterfNV(GLuint path, GLenum pname, GLfloat value);
void glPathDashArrayNV(GLuint path, GLsizei dashCount, const GLfloat* dashArray);
void glPathStencilFuncNV(GLenum func, GLint ref, GLuint mask);
void glPathStencilDepthOffsetNV(GLfloat factor, GLfloat units);
void glStencilFillPathNV(GLuint path, GLenum fillMode, GLuint mask);
void glStencilStrokePathNV(GLuint path, GLint reference, GLuint mask);
void glStencilFillPathInstancedNV(GLsizei numPaths,
                                  GLenum pathNameType,
                                  const void* paths,
                                  GLuint pathBase,
                                  GLenum fillMode,
                                  GLuint mask,
                                  GLenum transformType,
                                  const GLfloat* transformValues);
void glStencilStrokePathInstancedNV(GLsizei numPaths,
                                    GLenum pathNameType,
                                    const void* paths,
                                    GLuint pathBase,
                                    GLint reference,
                                    GLuint mask,
                                    GLenum transformType,
                                    const GLfloat* transformValues);
void glPathCoverDepthFuncNV(GLenum func);
void glCoverFillPathNV(GLuint path, GLenum coverMode);
void glCoverStrokePathNV(GLuint path, GLenum coverMode);
void glCoverFillPathInstancedNV(GLsizei numPaths,
                                GLenum pathNameType,
                                const void* paths,
                                GLuint pathBase,
                                GLenum coverMode,
                                GLenum transformType,
                                const GLfloat* transformValues);
void glCoverStrokePathInstancedNV(GLsizei numPaths,
                                  GLenum pathNameType,
                                  const void* paths,
                                  GLuint pathBase,
                                  GLenum coverMode,
                                  GLenum transformType,
                                  const GLfloat* transformValues);
void glGetPathParameterivNV(GLuint path, GLenum pname, GLint* value);
void glGetPathParameterfvNV(GLuint path, GLenum pname, GLfloat* value);
void glGetPathCommandsNV(GLuint path, GLubyte* commands);
void glGetPathCoordsNV(GLuint path, GLfloat* coords);
void glGetPathDashArrayNV(GLuint path, GLfloat* dashArray);
void glGetPathMetricsNV(GLbitfield metricQueryMask,
                        GLsizei numPaths,
                        GLenum pathNameType,
                        const void* paths,
                        GLuint pathBase,
                        GLsizei stride,
                        GLfloat* metrics);
void glGetPathMetricRangeNV(GLbitfield metricQueryMask,
                            GLuint firstPathName,
                            GLsizei numPaths,
                            GLsizei stride,
                            GLfloat* metrics);
void glGetPathSpacingNV(GLenum pathListMode,
                        GLsizei numPaths,
                        GLenum pathNameType,
                        const void* paths,
                        GLuint pathBase,
                        GLfloat advanceScale,
                        GLfloat kerningScale,
                        GLenum transformType,
                        GLfloat* returnedSpacing);
GLboolean glIsPointInFillPathNV(GLuint path, GLuint mask, GLfloat x, GLfloat y);
GLboolean glIsPointInStrokePathNV(GLuint path, GLfloat x, GLfloat y);
GLfloat glGetPathLengthNV(GLuint path, GLsizei startSegment, GLsizei numSegments);
GLboolean glPointAlongPathNV(GLuint path,
                             GLsizei startSegment,
                             GLsizei numSegments,
                             GLfloat distance,
                             GLfloat* x,
                             GLfloat* y,
                             GLfloat* tangentX,
                             GLfloat* tangentY);
void glMatrixLoad3x2fNV(GLenum matrixMode, const GLfloat* m);
void glMatrixLoad3x3fNV(GLenum matrixMode, const GLfloat* m);
void glMatrixLoadTranspose3x3fNV(GLenum matrixMode, const GLfloat* m);
void glMatrixMult3x2fNV(GLenum matrixMode, const GLfloat* m);
void glMatrixMult3x3fNV(GLenum matrixMode, const GLfloat* m);
void glMatrixMultTranspose3x3fNV(GLenum matrixMode, const GLfloat* m);
void glStencilThenCoverFillPathNV(GLuint path, GLenum fillMode, GLuint mask, GLenum coverMode);
void glStencilThenCoverStrokePathNV(GLuint path, GLint reference, GLuint mask, GLenum coverMode);
void glStencilThenCoverFillPathInstancedNV(GLsizei numPaths,
                                           GLenum pathNameType,
                                           const void* paths,
                                           GLuint pathBase,
                                           GLenum fillMode,
                                           GLuint mask,
                                           GLenum coverMode,
                                           GLenum transformType,
                                           const GLfloat* transformValues);
void glStencilThenCoverStrokePathInstancedNV(GLsizei numPaths,
                                             GLenum pathNameType,
                                             const void* paths,
                                             GLuint pathBase,
                                             GLint reference,
                                             GLuint mask,
                                             GLenum coverMode,
                                             GLenum transformType,
                                             const GLfloat* transformValues);
GLenum glPathGlyphIndexRangeNV(GLenum fontTarget,
                               const void* fontName,
                               GLbitfield fontStyle,
                               GLuint pathParameterTemplate,
                               GLfloat emScale,
                               GLuint baseAndCount[2]);
GLenum glPathGlyphIndexArrayNV(GLuint firstPathName,
                               GLenum fontTarget,
                               const void* fontName,
                               GLbitfield fontStyle,
                               GLuint firstGlyphIndex,
                               GLsizei numGlyphs,
                               GLuint pathParameterTemplate,
                               GLfloat emScale);
GLenum glPathMemoryGlyphIndexArrayNV(GLuint firstPathName,
                                     GLenum fontTarget,
                                     GLsizeiptr fontSize,
                                     const void* fontData,
                                     GLsizei faceIndex,
                                     GLuint firstGlyphIndex,
                                     GLsizei numGlyphs,
                                     GLuint pathParameterTemplate,
                                     GLfloat emScale);
void glProgramPathFragmentInputGenNV(GLuint program,
                                     GLint location,
                                     GLenum genMode,
                                     GLint components,
                                     const GLfloat* coeffs);
void glGetProgramResourcefvNV(GLuint program,
                              GLenum programInterface,
                              GLuint index,
                              GLsizei propCount,
                              const GLenum* props,
                              GLsizei count,
                              GLsizei* length,
                              GLfloat* params);

#pragma endregion

#pragma region GL_NV_path_rendering_shared_edge

constexpr int GL_SHARED_EDGE_NV = 0xC0;

#pragma endregion

#pragma region GL_NV_representative_fragment_test

constexpr int GL_REPRESENTATIVE_FRAGMENT_TEST_NV = 0x937F;

#pragma endregion

#pragma region GL_NV_sample_locations

constexpr int GL_SAMPLE_LOCATION_SUBPIXEL_BITS_NV             = 0x933D;
constexpr int GL_SAMPLE_LOCATION_PIXEL_GRID_WIDTH_NV          = 0x933E;
constexpr int GL_SAMPLE_LOCATION_PIXEL_GRID_HEIGHT_NV         = 0x933F;
constexpr int GL_PROGRAMMABLE_SAMPLE_LOCATION_TABLE_SIZE_NV   = 0x9340;
constexpr int GL_SAMPLE_LOCATION_NV                           = 0x8E50;
constexpr int GL_PROGRAMMABLE_SAMPLE_LOCATION_NV              = 0x9341;
constexpr int GL_FRAMEBUFFER_PROGRAMMABLE_SAMPLE_LOCATIONS_NV = 0x9342;
constexpr int GL_FRAMEBUFFER_SAMPLE_LOCATION_PIXEL_GRID_NV    = 0x9343;

void glFramebufferSampleLocationsfvNV(GLenum target, GLuint start, GLsizei count, const GLfloat* v);
void glNamedFramebufferSampleLocationsfvNV(GLuint framebuffer, GLuint start, GLsizei count, const GLfloat* v);
void glResolveDepthValuesNV();

#pragma endregion

#pragma region GL_NV_sample_mask_override_coverage

#pragma endregion

#pragma region GL_NV_scissor_exclusive

constexpr int GL_SCISSOR_TEST_EXCLUSIVE_NV = 0x9555;
constexpr int GL_SCISSOR_BOX_EXCLUSIVE_NV  = 0x9556;

void glScissorExclusiveNV(GLint x, GLint y, GLsizei width, GLsizei height);
void glScissorExclusiveArrayvNV(GLuint first, GLsizei count, const GLint* v);

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

constexpr int GL_BUFFER_GPU_ADDRESS_NV        = 0x8F1D;
constexpr int GL_GPU_ADDRESS_NV               = 0x8F34;
constexpr int GL_MAX_SHADER_BUFFER_ADDRESS_NV = 0x8F35;

void glMakeBufferResidentNV(GLenum target, GLenum access);
void glMakeBufferNonResidentNV(GLenum target);
GLboolean glIsBufferResidentNV(GLenum target);
void glMakeNamedBufferResidentNV(GLuint buffer, GLenum access);
void glMakeNamedBufferNonResidentNV(GLuint buffer);
GLboolean glIsNamedBufferResidentNV(GLuint buffer);
void glGetBufferParameterui64vNV(GLenum target, GLenum pname, GLuint64EXT* params);
void glGetNamedBufferParameterui64vNV(GLuint buffer, GLenum pname, GLuint64EXT* params);
void glGetIntegerui64vNV(GLenum value, GLuint64EXT* result);
void glUniformui64NV(GLint location, GLuint64EXT value);
void glUniformui64vNV(GLint location, GLsizei count, const GLuint64EXT* value);
void glGetUniformui64vNV(GLuint program, GLint location, GLuint64EXT* params);
void glProgramUniformui64NV(GLuint program, GLint location, GLuint64EXT value);
void glProgramUniformui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT* value);

#pragma endregion

#pragma region GL_NV_shader_buffer_store

constexpr int GL_SHADER_GLOBAL_ACCESS_BARRIER_BIT_NV = 0x00000010;

#pragma endregion

#pragma region GL_NV_shader_subgroup_partitioned

constexpr int GL_SUBGROUP_FEATURE_PARTITIONED_BIT_NV = 0x00000100;

#pragma endregion

#pragma region GL_NV_shader_texture_footprint

#pragma endregion

#pragma region GL_NV_shader_thread_group

constexpr int GL_WARP_SIZE_NV    = 0x9339;
constexpr int GL_WARPS_PER_SM_NV = 0x933A;
constexpr int GL_SM_COUNT_NV     = 0x933B;

#pragma endregion

#pragma region GL_NV_shader_thread_shuffle

#pragma endregion

#pragma region GL_NV_shading_rate_image

constexpr int GL_SHADING_RATE_IMAGE_NV                       = 0x9563;
constexpr int GL_SHADING_RATE_NO_INVOCATIONS_NV              = 0x9564;
constexpr int GL_SHADING_RATE_1_INVOCATION_PER_PIXEL_NV      = 0x9565;
constexpr int GL_SHADING_RATE_1_INVOCATION_PER_1X2_PIXELS_NV = 0x9566;
constexpr int GL_SHADING_RATE_1_INVOCATION_PER_2X1_PIXELS_NV = 0x9567;
constexpr int GL_SHADING_RATE_1_INVOCATION_PER_2X2_PIXELS_NV = 0x9568;
constexpr int GL_SHADING_RATE_1_INVOCATION_PER_2X4_PIXELS_NV = 0x9569;
constexpr int GL_SHADING_RATE_1_INVOCATION_PER_4X2_PIXELS_NV = 0x956A;
constexpr int GL_SHADING_RATE_1_INVOCATION_PER_4X4_PIXELS_NV = 0x956B;
constexpr int GL_SHADING_RATE_2_INVOCATIONS_PER_PIXEL_NV     = 0x956C;
constexpr int GL_SHADING_RATE_4_INVOCATIONS_PER_PIXEL_NV     = 0x956D;
constexpr int GL_SHADING_RATE_8_INVOCATIONS_PER_PIXEL_NV     = 0x956E;
constexpr int GL_SHADING_RATE_16_INVOCATIONS_PER_PIXEL_NV    = 0x956F;
constexpr int GL_SHADING_RATE_IMAGE_BINDING_NV               = 0x955B;
constexpr int GL_SHADING_RATE_IMAGE_TEXEL_WIDTH_NV           = 0x955C;
constexpr int GL_SHADING_RATE_IMAGE_TEXEL_HEIGHT_NV          = 0x955D;
constexpr int GL_SHADING_RATE_IMAGE_PALETTE_SIZE_NV          = 0x955E;
constexpr int GL_MAX_COARSE_FRAGMENT_SAMPLES_NV              = 0x955F;
constexpr int GL_SHADING_RATE_SAMPLE_ORDER_DEFAULT_NV        = 0x95AE;
constexpr int GL_SHADING_RATE_SAMPLE_ORDER_PIXEL_MAJOR_NV    = 0x95AF;
constexpr int GL_SHADING_RATE_SAMPLE_ORDER_SAMPLE_MAJOR_NV   = 0x95B0;

void glBindShadingRateImageNV(GLuint texture);
void glGetShadingRateImagePaletteNV(GLuint viewport, GLuint entry, GLenum* rate);
void glGetShadingRateSampleLocationivNV(GLenum rate, GLuint samples, GLuint index, GLint* location);
void glShadingRateImageBarrierNV(GLboolean synchronize);
void glShadingRateImagePaletteNV(GLuint viewport, GLuint first, GLsizei count, const GLenum* rates);
void glShadingRateSampleOrderNV(GLenum order);
void glShadingRateSampleOrderCustomNV(GLenum rate, GLuint samples, const GLint* locations);

#pragma endregion

#pragma region GL_NV_stereo_view_rendering

#pragma endregion

#pragma region GL_NV_texture_barrier

void glTextureBarrierNV();

#pragma endregion

#pragma region GL_NV_texture_rectangle_compressed

#pragma endregion

#pragma region GL_NV_uniform_buffer_unified_memory

constexpr int GL_UNIFORM_BUFFER_UNIFIED_NV = 0x936E;
constexpr int GL_UNIFORM_BUFFER_ADDRESS_NV = 0x936F;
constexpr int GL_UNIFORM_BUFFER_LENGTH_NV  = 0x9370;

#pragma endregion

#pragma region GL_NV_vertex_attrib_integer_64bit

void glVertexAttribL1i64NV(GLuint index, GLint64EXT x);
void glVertexAttribL2i64NV(GLuint index, GLint64EXT x, GLint64EXT y);
void glVertexAttribL3i64NV(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z);
void glVertexAttribL4i64NV(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
void glVertexAttribL1i64vNV(GLuint index, const GLint64EXT* v);
void glVertexAttribL2i64vNV(GLuint index, const GLint64EXT* v);
void glVertexAttribL3i64vNV(GLuint index, const GLint64EXT* v);
void glVertexAttribL4i64vNV(GLuint index, const GLint64EXT* v);
void glVertexAttribL1ui64NV(GLuint index, GLuint64EXT x);
void glVertexAttribL2ui64NV(GLuint index, GLuint64EXT x, GLuint64EXT y);
void glVertexAttribL3ui64NV(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
void glVertexAttribL4ui64NV(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
void glVertexAttribL1ui64vNV(GLuint index, const GLuint64EXT* v);
void glVertexAttribL2ui64vNV(GLuint index, const GLuint64EXT* v);
void glVertexAttribL3ui64vNV(GLuint index, const GLuint64EXT* v);
void glVertexAttribL4ui64vNV(GLuint index, const GLuint64EXT* v);
void glGetVertexAttribLi64vNV(GLuint index, GLenum pname, GLint64EXT* params);
void glGetVertexAttribLui64vNV(GLuint index, GLenum pname, GLuint64EXT* params);
void glVertexAttribLFormatNV(GLuint index, GLint size, GLenum type, GLsizei stride);

#pragma endregion

#pragma region GL_NV_vertex_buffer_unified_memory

constexpr int GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV   = 0x8F1E;
constexpr int GL_ELEMENT_ARRAY_UNIFIED_NV         = 0x8F1F;
constexpr int GL_VERTEX_ATTRIB_ARRAY_ADDRESS_NV   = 0x8F20;
constexpr int GL_VERTEX_ARRAY_ADDRESS_NV          = 0x8F21;
constexpr int GL_NORMAL_ARRAY_ADDRESS_NV          = 0x8F22;
constexpr int GL_COLOR_ARRAY_ADDRESS_NV           = 0x8F23;
constexpr int GL_INDEX_ARRAY_ADDRESS_NV           = 0x8F24;
constexpr int GL_TEXTURE_COORD_ARRAY_ADDRESS_NV   = 0x8F25;
constexpr int GL_EDGE_FLAG_ARRAY_ADDRESS_NV       = 0x8F26;
constexpr int GL_SECONDARY_COLOR_ARRAY_ADDRESS_NV = 0x8F27;
constexpr int GL_FOG_COORD_ARRAY_ADDRESS_NV       = 0x8F28;
constexpr int GL_ELEMENT_ARRAY_ADDRESS_NV         = 0x8F29;
constexpr int GL_VERTEX_ATTRIB_ARRAY_LENGTH_NV    = 0x8F2A;
constexpr int GL_VERTEX_ARRAY_LENGTH_NV           = 0x8F2B;
constexpr int GL_NORMAL_ARRAY_LENGTH_NV           = 0x8F2C;
constexpr int GL_COLOR_ARRAY_LENGTH_NV            = 0x8F2D;
constexpr int GL_INDEX_ARRAY_LENGTH_NV            = 0x8F2E;
constexpr int GL_TEXTURE_COORD_ARRAY_LENGTH_NV    = 0x8F2F;
constexpr int GL_EDGE_FLAG_ARRAY_LENGTH_NV        = 0x8F30;
constexpr int GL_SECONDARY_COLOR_ARRAY_LENGTH_NV  = 0x8F31;
constexpr int GL_FOG_COORD_ARRAY_LENGTH_NV        = 0x8F32;
constexpr int GL_ELEMENT_ARRAY_LENGTH_NV          = 0x8F33;
constexpr int GL_DRAW_INDIRECT_UNIFIED_NV         = 0x8F40;
constexpr int GL_DRAW_INDIRECT_ADDRESS_NV         = 0x8F41;
constexpr int GL_DRAW_INDIRECT_LENGTH_NV          = 0x8F42;

void glBufferAddressRangeNV(GLenum pname, GLuint index, GLuint64EXT address, GLsizeiptr length);
void glVertexFormatNV(GLint size, GLenum type, GLsizei stride);
void glNormalFormatNV(GLenum type, GLsizei stride);
void glColorFormatNV(GLint size, GLenum type, GLsizei stride);
void glIndexFormatNV(GLenum type, GLsizei stride);
void glTexCoordFormatNV(GLint size, GLenum type, GLsizei stride);
void glEdgeFlagFormatNV(GLsizei stride);
void glSecondaryColorFormatNV(GLint size, GLenum type, GLsizei stride);
void glFogCoordFormatNV(GLenum type, GLsizei stride);
void glVertexAttribFormatNV(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride);
void glVertexAttribIFormatNV(GLuint index, GLint size, GLenum type, GLsizei stride);
void glGetIntegerui64i_vNV(GLenum value, GLuint index, GLuint64EXT* result);

#pragma endregion

#pragma region GL_NV_viewport_array2

#pragma endregion

#pragma region GL_NV_viewport_swizzle

constexpr int GL_VIEWPORT_SWIZZLE_POSITIVE_X_NV = 0x9350;
constexpr int GL_VIEWPORT_SWIZZLE_NEGATIVE_X_NV = 0x9351;
constexpr int GL_VIEWPORT_SWIZZLE_POSITIVE_Y_NV = 0x9352;
constexpr int GL_VIEWPORT_SWIZZLE_NEGATIVE_Y_NV = 0x9353;
constexpr int GL_VIEWPORT_SWIZZLE_POSITIVE_Z_NV = 0x9354;
constexpr int GL_VIEWPORT_SWIZZLE_NEGATIVE_Z_NV = 0x9355;
constexpr int GL_VIEWPORT_SWIZZLE_POSITIVE_W_NV = 0x9356;
constexpr int GL_VIEWPORT_SWIZZLE_NEGATIVE_W_NV = 0x9357;
constexpr int GL_VIEWPORT_SWIZZLE_X_NV          = 0x9358;
constexpr int GL_VIEWPORT_SWIZZLE_Y_NV          = 0x9359;
constexpr int GL_VIEWPORT_SWIZZLE_Z_NV          = 0x935A;
constexpr int GL_VIEWPORT_SWIZZLE_W_NV          = 0x935B;

void glViewportSwizzleNV(GLuint index, GLenum swizzlex, GLenum swizzley, GLenum swizzlez, GLenum swizzlew);

#pragma endregion

#pragma region GL_OVR_multiview

constexpr int GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_NUM_VIEWS_OVR       = 0x9630;
constexpr int GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_BASE_VIEW_INDEX_OVR = 0x9632;
constexpr int GL_MAX_VIEWS_OVR                                      = 0x9631;
constexpr int GL_FRAMEBUFFER_INCOMPLETE_VIEW_TARGETS_OVR            = 0x9633;

void glFramebufferTextureMultiviewOVR(GLenum target,
                                      GLenum attachment,
                                      GLuint texture,
                                      GLint level,
                                      GLint baseViewIndex,
                                      GLsizei numViews);

#pragma endregion

#pragma region GL_OVR_multiview2

#pragma endregion

#pragma region GL_EXT_texture_shadow_lod

#pragma endregion

enum class Feature
{
    GL_VERSION_1_0,
    GL_VERSION_1_1,
    GL_VERSION_1_2,
    GL_VERSION_1_3,
    GL_VERSION_1_4,
    GL_VERSION_1_5,
    GL_VERSION_2_0,
    GL_VERSION_2_1,
    GL_VERSION_3_0,
    GL_VERSION_3_1,
    GL_VERSION_3_2,
    GL_VERSION_3_3,
    GL_VERSION_4_0,
    GL_VERSION_4_1,
    GL_VERSION_4_2,
    GL_VERSION_4_3,
    GL_VERSION_4_4,
    GL_VERSION_4_5,
    GL_VERSION_4_6,
};

enum class Extension
{
    GL_AMD_framebuffer_multisample_advanced,
    GL_AMD_performance_monitor,
    GL_APPLE_rgb_422,
    GL_ARB_ES2_compatibility,
    GL_ARB_ES3_1_compatibility,
    GL_ARB_ES3_2_compatibility,
    GL_ARB_ES3_compatibility,
    GL_ARB_arrays_of_arrays,
    GL_ARB_base_instance,
    GL_ARB_bindless_texture,
    GL_ARB_blend_func_extended,
    GL_ARB_buffer_storage,
    GL_ARB_cl_event,
    GL_ARB_clear_buffer_object,
    GL_ARB_clear_texture,
    GL_ARB_clip_control,
    GL_ARB_compressed_texture_pixel_storage,
    GL_ARB_compute_shader,
    GL_ARB_compute_variable_group_size,
    GL_ARB_conditional_render_inverted,
    GL_ARB_conservative_depth,
    GL_ARB_copy_buffer,
    GL_ARB_copy_image,
    GL_ARB_cull_distance,
    GL_ARB_debug_output,
    GL_ARB_depth_buffer_float,
    GL_ARB_depth_clamp,
    GL_ARB_derivative_control,
    GL_ARB_direct_state_access,
    GL_ARB_draw_buffers_blend,
    GL_ARB_draw_elements_base_vertex,
    GL_ARB_draw_indirect,
    GL_ARB_draw_instanced,
    GL_ARB_enhanced_layouts,
    GL_ARB_explicit_attrib_location,
    GL_ARB_explicit_uniform_location,
    GL_ARB_fragment_coord_conventions,
    GL_ARB_fragment_layer_viewport,
    GL_ARB_fragment_shader_interlock,
    GL_ARB_framebuffer_no_attachments,
    GL_ARB_framebuffer_object,
    GL_ARB_framebuffer_sRGB,
    GL_ARB_geometry_shader4,
    GL_ARB_get_program_binary,
    GL_ARB_get_texture_sub_image,
    GL_ARB_gl_spirv,
    GL_ARB_gpu_shader5,
    GL_ARB_gpu_shader_fp64,
    GL_ARB_gpu_shader_int64,
    GL_ARB_half_float_vertex,
    GL_ARB_imaging,
    GL_ARB_indirect_parameters,
    GL_ARB_instanced_arrays,
    GL_ARB_internalformat_query,
    GL_ARB_internalformat_query2,
    GL_ARB_invalidate_subdata,
    GL_ARB_map_buffer_alignment,
    GL_ARB_map_buffer_range,
    GL_ARB_multi_bind,
    GL_ARB_multi_draw_indirect,
    GL_ARB_occlusion_query2,
    GL_ARB_parallel_shader_compile,
    GL_ARB_pipeline_statistics_query,
    GL_ARB_pixel_buffer_object,
    GL_ARB_polygon_offset_clamp,
    GL_ARB_post_depth_coverage,
    GL_ARB_program_interface_query,
    GL_ARB_provoking_vertex,
    GL_ARB_query_buffer_object,
    GL_ARB_robust_buffer_access_behavior,
    GL_ARB_robustness,
    GL_ARB_robustness_isolation,
    GL_ARB_sample_locations,
    GL_ARB_sample_shading,
    GL_ARB_sampler_objects,
    GL_ARB_seamless_cube_map,
    GL_ARB_seamless_cubemap_per_texture,
    GL_ARB_separate_shader_objects,
    GL_ARB_shader_atomic_counter_ops,
    GL_ARB_shader_atomic_counters,
    GL_ARB_shader_ballot,
    GL_ARB_shader_bit_encoding,
    GL_ARB_shader_clock,
    GL_ARB_shader_draw_parameters,
    GL_ARB_shader_group_vote,
    GL_ARB_shader_image_load_store,
    GL_ARB_shader_image_size,
    GL_ARB_shader_precision,
    GL_ARB_shader_stencil_export,
    GL_ARB_shader_storage_buffer_object,
    GL_ARB_shader_subroutine,
    GL_ARB_shader_texture_image_samples,
    GL_ARB_shader_viewport_layer_array,
    GL_ARB_shading_language_420pack,
    GL_ARB_shading_language_include,
    GL_ARB_shading_language_packing,
    GL_ARB_sparse_buffer,
    GL_ARB_sparse_texture,
    GL_ARB_sparse_texture2,
    GL_ARB_sparse_texture_clamp,
    GL_ARB_spirv_extensions,
    GL_ARB_stencil_texturing,
    GL_ARB_sync,
    GL_ARB_tessellation_shader,
    GL_ARB_texture_barrier,
    GL_ARB_texture_border_clamp,
    GL_ARB_texture_buffer_object,
    GL_ARB_texture_buffer_object_rgb32,
    GL_ARB_texture_buffer_range,
    GL_ARB_texture_compression_bptc,
    GL_ARB_texture_compression_rgtc,
    GL_ARB_texture_cube_map_array,
    GL_ARB_texture_filter_anisotropic,
    GL_ARB_texture_filter_minmax,
    GL_ARB_texture_gather,
    GL_ARB_texture_mirror_clamp_to_edge,
    GL_ARB_texture_mirrored_repeat,
    GL_ARB_texture_multisample,
    GL_ARB_texture_non_power_of_two,
    GL_ARB_texture_query_levels,
    GL_ARB_texture_query_lod,
    GL_ARB_texture_rg,
    GL_ARB_texture_rgb10_a2ui,
    GL_ARB_texture_stencil8,
    GL_ARB_texture_storage,
    GL_ARB_texture_storage_multisample,
    GL_ARB_texture_swizzle,
    GL_ARB_texture_view,
    GL_ARB_timer_query,
    GL_ARB_transform_feedback2,
    GL_ARB_transform_feedback3,
    GL_ARB_transform_feedback_instanced,
    GL_ARB_transform_feedback_overflow_query,
    GL_ARB_uniform_buffer_object,
    GL_ARB_vertex_array_bgra,
    GL_ARB_vertex_array_object,
    GL_ARB_vertex_attrib_64bit,
    GL_ARB_vertex_attrib_binding,
    GL_ARB_vertex_type_10f_11f_11f_rev,
    GL_ARB_vertex_type_2_10_10_10_rev,
    GL_ARB_viewport_array,
    GL_EXT_EGL_image_storage,
    GL_EXT_EGL_sync,
    GL_EXT_debug_label,
    GL_EXT_debug_marker,
    GL_EXT_direct_state_access,
    GL_EXT_draw_instanced,
    GL_EXT_multiview_tessellation_geometry_shader,
    GL_EXT_multiview_texture_multisample,
    GL_EXT_multiview_timer_query,
    GL_EXT_polygon_offset_clamp,
    GL_EXT_post_depth_coverage,
    GL_EXT_raster_multisample,
    GL_EXT_separate_shader_objects,
    GL_EXT_shader_framebuffer_fetch,
    GL_EXT_shader_framebuffer_fetch_non_coherent,
    GL_EXT_shader_integer_mix,
    GL_EXT_texture_compression_s3tc,
    GL_EXT_texture_filter_minmax,
    GL_EXT_texture_sRGB_R8,
    GL_EXT_texture_sRGB_decode,
    GL_EXT_window_rectangles,
    GL_INTEL_conservative_rasterization,
    GL_INTEL_framebuffer_CMAA,
    GL_INTEL_blackhole_render,
    GL_INTEL_performance_query,
    GL_KHR_blend_equation_advanced,
    GL_KHR_blend_equation_advanced_coherent,
    GL_KHR_context_flush_control,
    GL_KHR_debug,
    GL_KHR_no_error,
    GL_KHR_robust_buffer_access_behavior,
    GL_KHR_robustness,
    GL_KHR_shader_subgroup,
    GL_KHR_texture_compression_astc_hdr,
    GL_KHR_texture_compression_astc_ldr,
    GL_KHR_texture_compression_astc_sliced_3d,
    GL_KHR_parallel_shader_compile,
    GL_MESA_framebuffer_flip_y,
    GL_NV_bindless_multi_draw_indirect,
    GL_NV_bindless_multi_draw_indirect_count,
    GL_NV_bindless_texture,
    GL_NV_blend_equation_advanced,
    GL_NV_blend_equation_advanced_coherent,
    GL_NV_blend_minmax_factor,
    GL_NV_clip_space_w_scaling,
    GL_NV_command_list,
    GL_NV_compute_shader_derivatives,
    GL_NV_conditional_render,
    GL_NV_conservative_raster,
    GL_NV_conservative_raster_dilate,
    GL_NV_conservative_raster_pre_snap,
    GL_NV_conservative_raster_pre_snap_triangles,
    GL_NV_conservative_raster_underestimation,
    GL_NV_depth_buffer_float,
    GL_NV_draw_vulkan_image,
    GL_NV_fill_rectangle,
    GL_NV_fragment_coverage_to_color,
    GL_NV_fragment_shader_barycentric,
    GL_NV_fragment_shader_interlock,
    GL_NV_framebuffer_mixed_samples,
    GL_NV_framebuffer_multisample_coverage,
    GL_NV_geometry_shader_passthrough,
    GL_NV_gpu_shader5,
    GL_NV_internalformat_sample_query,
    GL_NV_memory_attachment,
    GL_NV_mesh_shader,
    GL_NV_path_rendering,
    GL_NV_path_rendering_shared_edge,
    GL_NV_representative_fragment_test,
    GL_NV_sample_locations,
    GL_NV_sample_mask_override_coverage,
    GL_NV_scissor_exclusive,
    GL_NV_shader_atomic_counters,
    GL_NV_shader_atomic_float,
    GL_NV_shader_atomic_float64,
    GL_NV_shader_atomic_fp16_vector,
    GL_NV_shader_atomic_int64,
    GL_NV_shader_buffer_load,
    GL_NV_shader_buffer_store,
    GL_NV_shader_subgroup_partitioned,
    GL_NV_shader_texture_footprint,
    GL_NV_shader_thread_group,
    GL_NV_shader_thread_shuffle,
    GL_NV_shading_rate_image,
    GL_NV_stereo_view_rendering,
    GL_NV_texture_barrier,
    GL_NV_texture_rectangle_compressed,
    GL_NV_uniform_buffer_unified_memory,
    GL_NV_vertex_attrib_integer_64bit,
    GL_NV_vertex_buffer_unified_memory,
    GL_NV_viewport_array2,
    GL_NV_viewport_swizzle,
    GL_OVR_multiview,
    GL_OVR_multiview2,
    GL_EXT_texture_shadow_lod,
};

using VoidFunctionPtr = void (*)();
using GetFunction     = std::function<VoidFunctionPtr(const char*)>;

void init_opengl(const GetFunction& get_function);

bool is_supported(Feature feature);
bool is_supported(Extension extension);

} // namespace framework::graphics::details::opengl

#endif
