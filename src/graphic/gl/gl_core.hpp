/// @file
/// @brief OpneGL core functionality wrapper.
/// @author Fedorov Alexey
/// @date 21.06.2018

#ifndef FRAMEWORK_GRAPHIC_GL_GL_CORE_HPP
#define FRAMEWORK_GRAPHIC_GL_GL_CORE_HPP

#include <common/types.hpp>

namespace framework
{
namespace graphic
{
namespace gl
{
/// Initialize GL core function
bool init_core();

// TODO(alex) should split thous constants by enums
using GLenum = uint32;

/// @name gl_version_1_0
/// @{
#pragma region gl_version_1_0

const uint32 gl_depth_buffer_bit        = 0x00000100;
const uint32 gl_stencil_buffer_bit      = 0x00000400;
const uint32 gl_color_buffer_bit        = 0x00004000;
const uint32 gl_points                  = 0x0000;
const uint32 gl_lines                   = 0x0001;
const uint32 gl_line_loop               = 0x0002;
const uint32 gl_line_strip              = 0x0003;
const uint32 gl_triangles               = 0x0004;
const uint32 gl_triangle_strip          = 0x0005;
const uint32 gl_triangle_fan            = 0x0006;
const uint32 gl_quads                   = 0x0007;
const uint32 gl_never                   = 0x0200;
const uint32 gl_less                    = 0x0201;
const uint32 gl_equal                   = 0x0202;
const uint32 gl_lequal                  = 0x0203;
const uint32 gl_greater                 = 0x0204;
const uint32 gl_notequal                = 0x0205;
const uint32 gl_gequal                  = 0x0206;
const uint32 gl_always                  = 0x0207;
const uint32 gl_zero                    = 0;
const uint32 gl_one                     = 1;
const uint32 gl_src_color               = 0x0300;
const uint32 gl_one_minus_src_color     = 0x0301;
const uint32 gl_src_alpha               = 0x0302;
const uint32 gl_one_minus_src_alpha     = 0x0303;
const uint32 gl_dst_alpha               = 0x0304;
const uint32 gl_one_minus_dst_alpha     = 0x0305;
const uint32 gl_dst_color               = 0x0306;
const uint32 gl_one_minus_dst_color     = 0x0307;
const uint32 gl_src_alpha_saturate      = 0x0308;
const uint32 gl_none                    = 0;
const uint32 gl_front_left              = 0x0400;
const uint32 gl_front_right             = 0x0401;
const uint32 gl_back_left               = 0x0402;
const uint32 gl_back_right              = 0x0403;
const uint32 gl_front                   = 0x0404;
const uint32 gl_back                    = 0x0405;
const uint32 gl_front_and_back          = 0x0408;
const uint32 gl_left                    = 0x0406;
const uint32 gl_right                   = 0x0407;
const uint32 gl_no_error                = 0;
const uint32 gl_invalid_enum            = 0x0500;
const uint32 gl_invalid_value           = 0x0501;
const uint32 gl_invalid_operation       = 0x0502;
const uint32 gl_out_of_memory           = 0x0505;
const uint32 gl_cw                      = 0x0900;
const uint32 gl_ccw                     = 0x0901;
const uint32 gl_point_size              = 0x0B11;
const uint32 gl_point_size_range        = 0x0B12;
const uint32 gl_point_size_granularity  = 0x0B13;
const uint32 gl_line_smooth             = 0x0B20;
const uint32 gl_line_width              = 0x0B21;
const uint32 gl_line_width_range        = 0x0B22;
const uint32 gl_line_width_granularity  = 0x0B23;
const uint32 gl_polygon_mode            = 0x0B40;
const uint32 gl_polygon_smooth          = 0x0B41;
const uint32 gl_cull_face               = 0x0B44;
const uint32 gl_cull_face_mode          = 0x0B45;
const uint32 gl_front_face              = 0x0B46;
const uint32 gl_depth_range             = 0x0B70;
const uint32 gl_depth_test              = 0x0B71;
const uint32 gl_depth_writemask         = 0x0B72;
const uint32 gl_depth_clear_value       = 0x0B73;
const uint32 gl_depth_func              = 0x0B74;
const uint32 gl_stencil_test            = 0x0B90;
const uint32 gl_stencil_clear_value     = 0x0B91;
const uint32 gl_stencil_func            = 0x0B92;
const uint32 gl_stencil_value_mask      = 0x0B93;
const uint32 gl_stencil_fail            = 0x0B94;
const uint32 gl_stencil_pass_depth_fail = 0x0B95;
const uint32 gl_stencil_pass_depth_pass = 0x0B96;
const uint32 gl_stencil_ref             = 0x0B97;
const uint32 gl_stencil_writemask       = 0x0B98;
const uint32 gl_viewport                = 0x0BA2;
const uint32 gl_dither                  = 0x0BD0;
const uint32 gl_blend_dst               = 0x0BE0;
const uint32 gl_blend_src               = 0x0BE1;
const uint32 gl_blend                   = 0x0BE2;
const uint32 gl_logic_op_mode           = 0x0BF0;
const uint32 gl_draw_buffer             = 0x0C01;
const uint32 gl_read_buffer             = 0x0C02;
const uint32 gl_scissor_box             = 0x0C10;
const uint32 gl_scissor_test            = 0x0C11;
const uint32 gl_color_clear_value       = 0x0C22;
const uint32 gl_color_writemask         = 0x0C23;
const uint32 gl_doublebuffer            = 0x0C32;
const uint32 gl_stereo                  = 0x0C33;
const uint32 gl_line_smooth_hint        = 0x0C52;
const uint32 gl_polygon_smooth_hint     = 0x0C53;
const uint32 gl_unpack_swap_bytes       = 0x0CF0;
const uint32 gl_unpack_lsb_first        = 0x0CF1;
const uint32 gl_unpack_row_length       = 0x0CF2;
const uint32 gl_unpack_skip_rows        = 0x0CF3;
const uint32 gl_unpack_skip_pixels      = 0x0CF4;
const uint32 gl_unpack_alignment        = 0x0CF5;
const uint32 gl_pack_swap_bytes         = 0x0D00;
const uint32 gl_pack_lsb_first          = 0x0D01;
const uint32 gl_pack_row_length         = 0x0D02;
const uint32 gl_pack_skip_rows          = 0x0D03;
const uint32 gl_pack_skip_pixels        = 0x0D04;
const uint32 gl_pack_alignment          = 0x0D05;
const uint32 gl_max_texture_size        = 0x0D33;
const uint32 gl_max_viewport_dims       = 0x0D3A;
const uint32 gl_subpixel_bits           = 0x0D50;
const uint32 gl_texture_1d              = 0x0DE0;
const uint32 gl_texture_2d              = 0x0DE1;
const uint32 gl_texture_width           = 0x1000;
const uint32 gl_texture_height          = 0x1001;
const uint32 gl_texture_border_color    = 0x1004;
const uint32 gl_dont_care               = 0x1100;
const uint32 gl_fastest                 = 0x1101;
const uint32 gl_nicest                  = 0x1102;
const uint32 gl_byte                    = 0x1400;
const uint32 gl_unsigned_byte           = 0x1401;
const uint32 gl_short                   = 0x1402;
const uint32 gl_unsigned_short          = 0x1403;
const uint32 gl_int                     = 0x1404;
const uint32 gl_unsigned_int            = 0x1405;
const uint32 gl_float                   = 0x1406;
const uint32 gl_stack_overflow          = 0x0503;
const uint32 gl_stack_underflow         = 0x0504;
const uint32 gl_clear                   = 0x1500;
const uint32 gl_and                     = 0x1501;
const uint32 gl_and_reverse             = 0x1502;
const uint32 gl_copy                    = 0x1503;
const uint32 gl_and_inverted            = 0x1504;
const uint32 gl_noop                    = 0x1505;
const uint32 gl_xor                     = 0x1506;
const uint32 gl_or                      = 0x1507;
const uint32 gl_nor                     = 0x1508;
const uint32 gl_equiv                   = 0x1509;
const uint32 gl_invert                  = 0x150A;
const uint32 gl_or_reverse              = 0x150B;
const uint32 gl_copy_inverted           = 0x150C;
const uint32 gl_or_inverted             = 0x150D;
const uint32 gl_nand                    = 0x150E;
const uint32 gl_set                     = 0x150F;
const uint32 gl_texture                 = 0x1702;
const uint32 gl_color                   = 0x1800;
const uint32 gl_depth                   = 0x1801;
const uint32 gl_stencil                 = 0x1802;
const uint32 gl_stencil_index           = 0x1901;
const uint32 gl_depth_component         = 0x1902;
const uint32 gl_red                     = 0x1903;
const uint32 gl_green                   = 0x1904;
const uint32 gl_blue                    = 0x1905;
const uint32 gl_alpha                   = 0x1906;
const uint32 gl_rgb                     = 0x1907;
const uint32 gl_rgba                    = 0x1908;
const uint32 gl_point                   = 0x1B00;
const uint32 gl_line                    = 0x1B01;
const uint32 gl_fill                    = 0x1B02;
const uint32 gl_keep                    = 0x1E00;
const uint32 gl_replace                 = 0x1E01;
const uint32 gl_incr                    = 0x1E02;
const uint32 gl_decr                    = 0x1E03;
const uint32 gl_vendor                  = 0x1F00;
const uint32 gl_renderer                = 0x1F01;
const uint32 gl_version                 = 0x1F02;
const uint32 gl_extensions              = 0x1F03;
const uint32 gl_nearest                 = 0x2600;
const uint32 gl_linear                  = 0x2601;
const uint32 gl_nearest_mipmap_nearest  = 0x2700;
const uint32 gl_linear_mipmap_nearest   = 0x2701;
const uint32 gl_nearest_mipmap_linear   = 0x2702;
const uint32 gl_linear_mipmap_linear    = 0x2703;
const uint32 gl_texture_mag_filter      = 0x2800;
const uint32 gl_texture_min_filter      = 0x2801;
const uint32 gl_texture_wrap_s          = 0x2802;
const uint32 gl_texture_wrap_t          = 0x2803;
const uint32 gl_repeat                  = 0x2901;

void glCullFace(GLenum mode);
void glFrontFace(GLenum mode);
void glHint(GLenum target, GLenum mode);
void glLineWidth(float32 width);
void glPointSize(float32 size);
void glPolygonMode(GLenum face, GLenum mode);
void glScissor(int32 x, int32 y, int32 width, int32 height);
void glTexParameterf(GLenum target, GLenum pname, float32 param);
void glTexParameterfv(GLenum target, GLenum pname, const float32* params);
void glTexParameteri(GLenum target, GLenum pname, int32 param);
void glTexParameteriv(GLenum target, GLenum pname, const int32* params);
void glTexImage1D(GLenum target,
                  int32 level,
                  int32 internalformat,
                  int32 width,
                  int32 border,
                  GLenum format,
                  GLenum type,
                  const void* pixels);
void glTexImage2D(GLenum target,
                  int32 level,
                  int32 internalformat,
                  int32 width,
                  int32 height,
                  int32 border,
                  GLenum format,
                  GLenum type,
                  const void* pixels);
void glDrawBuffer(GLenum buf);
void glClear(uint32 mask);
void glClearColor(float32 red, float32 green, float32 blue, float32 alpha);
void glClearStencil(int32 s);
void glClearDepth(float64 depth);
void glStencilMask(uint32 mask);
void glColorMask(bool red, bool green, bool blue, bool alpha);
void glDepthMask(bool flag);
void glDisable(GLenum cap);
void glEnable(GLenum cap);
void glFinish();
void glFlush();
void glBlendFunc(GLenum sfactor, GLenum dfactor);
void glLogicOp(GLenum opcode);
void glStencilFunc(GLenum func, int32 ref, uint32 mask);
void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass);
void glDepthFunc(GLenum func);
void glPixelStoref(GLenum pname, float32 param);
void glPixelStorei(GLenum pname, int32 param);
void glReadBuffer(GLenum src);
void glReadPixels(int32 x, int32 y, int32 width, int32 height, GLenum format, GLenum type, void* pixels);
void glGetBooleanv(GLenum pname, bool* data);
void glGetDoublev(GLenum pname, float64* data);
GLenum glGetError();
void glGetFloatv(GLenum pname, float32* data);
void glGetIntegerv(GLenum pname, int32* data);
const uint8* glGetString(GLenum name);
void glGetTexImage(GLenum target, int32 level, GLenum format, GLenum type, void* pixels);
void glGetTexParameterfv(GLenum target, GLenum pname, float32* params);
void glGetTexParameteriv(GLenum target, GLenum pname, int32* params);
void glGetTexLevelParameterfv(GLenum target, int32 level, GLenum pname, float32* params);
void glGetTexLevelParameteriv(GLenum target, int32 level, GLenum pname, int32* params);
bool glIsEnabled(GLenum cap);
void glDepthRange(float64 near, float64 far);
void glViewport(int32 x, int32 y, int32 width, int32 height);

#pragma endregion
/// @}

/// @name gl_version_1_1
/// @{
#pragma region gl_version_1_1

const uint32 gl_color_logic_op          = 0x0BF2;
const uint32 gl_polygon_offset_units    = 0x2A00;
const uint32 gl_polygon_offset_point    = 0x2A01;
const uint32 gl_polygon_offset_line     = 0x2A02;
const uint32 gl_polygon_offset_fill     = 0x8037;
const uint32 gl_polygon_offset_factor   = 0x8038;
const uint32 gl_texture_binding_1d      = 0x8068;
const uint32 gl_texture_binding_2d      = 0x8069;
const uint32 gl_texture_internal_format = 0x1003;
const uint32 gl_texture_red_size        = 0x805C;
const uint32 gl_texture_green_size      = 0x805D;
const uint32 gl_texture_blue_size       = 0x805E;
const uint32 gl_texture_alpha_size      = 0x805F;
const uint32 gl_double                  = 0x140A;
const uint32 gl_proxy_texture_1d        = 0x8063;
const uint32 gl_proxy_texture_2d        = 0x8064;
const uint32 gl_r3_g3_b2                = 0x2A10;
const uint32 gl_rgb4                    = 0x804F;
const uint32 gl_rgb5                    = 0x8050;
const uint32 gl_rgb8                    = 0x8051;
const uint32 gl_rgb10                   = 0x8052;
const uint32 gl_rgb12                   = 0x8053;
const uint32 gl_rgb16                   = 0x8054;
const uint32 gl_rgba2                   = 0x8055;
const uint32 gl_rgba4                   = 0x8056;
const uint32 gl_rgb5_a1                 = 0x8057;
const uint32 gl_rgba8                   = 0x8058;
const uint32 gl_rgb10_a2                = 0x8059;
const uint32 gl_rgba12                  = 0x805A;
const uint32 gl_rgba16                  = 0x805B;
const uint32 gl_vertex_array            = 0x8074;

void glDrawArrays(GLenum mode, int32 first, int32 count);
void glDrawElements(GLenum mode, int32 count, GLenum type, const void* indices);
void glGetPointerv(GLenum pname, void** params);
void glPolygonOffset(float32 factor, float32 units);
void glCopyTexImage1D(GLenum target, int32 level, GLenum internalformat, int32 x, int32 y, int32 width, int32 border);
void glCopyTexImage2D(GLenum target,
                      int32 level,
                      GLenum internalformat,
                      int32 x,
                      int32 y,
                      int32 width,
                      int32 height,
                      int32 border);
void glCopyTexSubImage1D(GLenum target, int32 level, int32 xoffset, int32 x, int32 y, int32 width);
void glCopyTexSubImage2D(GLenum target,
                         int32 level,
                         int32 xoffset,
                         int32 yoffset,
                         int32 x,
                         int32 y,
                         int32 width,
                         int32 height);
void glTexSubImage1D(GLenum target,
                     int32 level,
                     int32 xoffset,
                     int32 width,
                     GLenum format,
                     GLenum type,
                     const void* pixels);
void glTexSubImage2D(GLenum target,
                     int32 level,
                     int32 xoffset,
                     int32 yoffset,
                     int32 width,
                     int32 height,
                     GLenum format,
                     GLenum type,
                     const void* pixels);
void glBindTexture(GLenum target, uint32 texture);
void glDeleteTextures(int32 n, const uint32* textures);
void glGenTextures(int32 n, uint32* textures);
bool glIsTexture(uint32 texture);

#pragma endregion
/// @}

/// @name gl_version_1_2
/// @{
#pragma region gl_version_1_2

const uint32 gl_unsigned_byte_3_3_2           = 0x8032;
const uint32 gl_unsigned_short_4_4_4_4        = 0x8033;
const uint32 gl_unsigned_short_5_5_5_1        = 0x8034;
const uint32 gl_unsigned_int_8_8_8_8          = 0x8035;
const uint32 gl_unsigned_int_10_10_10_2       = 0x8036;
const uint32 gl_texture_binding_3d            = 0x806A;
const uint32 gl_pack_skip_images              = 0x806B;
const uint32 gl_pack_image_height             = 0x806C;
const uint32 gl_unpack_skip_images            = 0x806D;
const uint32 gl_unpack_image_height           = 0x806E;
const uint32 gl_texture_3d                    = 0x806F;
const uint32 gl_proxy_texture_3d              = 0x8070;
const uint32 gl_texture_depth                 = 0x8071;
const uint32 gl_texture_wrap_r                = 0x8072;
const uint32 gl_max_3d_texture_size           = 0x8073;
const uint32 gl_unsigned_byte_2_3_3_rev       = 0x8362;
const uint32 gl_unsigned_short_5_6_5          = 0x8363;
const uint32 gl_unsigned_short_5_6_5_rev      = 0x8364;
const uint32 gl_unsigned_short_4_4_4_4_rev    = 0x8365;
const uint32 gl_unsigned_short_1_5_5_5_rev    = 0x8366;
const uint32 gl_unsigned_int_8_8_8_8_rev      = 0x8367;
const uint32 gl_unsigned_int_2_10_10_10_rev   = 0x8368;
const uint32 gl_bgr                           = 0x80E0;
const uint32 gl_bgra                          = 0x80E1;
const uint32 gl_max_elements_vertices         = 0x80E8;
const uint32 gl_max_elements_indices          = 0x80E9;
const uint32 gl_clamp_to_edge                 = 0x812F;
const uint32 gl_texture_min_lod               = 0x813A;
const uint32 gl_texture_max_lod               = 0x813B;
const uint32 gl_texture_base_level            = 0x813C;
const uint32 gl_texture_max_level             = 0x813D;
const uint32 gl_smooth_point_size_range       = 0x0B12;
const uint32 gl_smooth_point_size_granularity = 0x0B13;
const uint32 gl_smooth_line_width_range       = 0x0B22;
const uint32 gl_smooth_line_width_granularity = 0x0B23;
const uint32 gl_aliased_line_width_range      = 0x846E;

void glDrawRangeElements(GLenum mode, uint32 start, uint32 end, int32 count, GLenum type, const void* indices);
void glTexImage3D(GLenum target,
                  int32 level,
                  int32 internalformat,
                  int32 width,
                  int32 height,
                  int32 depth,
                  int32 border,
                  GLenum format,
                  GLenum type,
                  const void* pixels);
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
                     const void* pixels);
void glCopyTexSubImage3D(GLenum target,
                         int32 level,
                         int32 xoffset,
                         int32 yoffset,
                         int32 zoffset,
                         int32 x,
                         int32 y,
                         int32 width,
                         int32 height);

#pragma endregion
/// @}

/// @name gl_version_1_3
/// @{
#pragma region gl_version_1_3

const uint32 gl_texture0                       = 0x84C0;
const uint32 gl_texture1                       = 0x84C1;
const uint32 gl_texture2                       = 0x84C2;
const uint32 gl_texture3                       = 0x84C3;
const uint32 gl_texture4                       = 0x84C4;
const uint32 gl_texture5                       = 0x84C5;
const uint32 gl_texture6                       = 0x84C6;
const uint32 gl_texture7                       = 0x84C7;
const uint32 gl_texture8                       = 0x84C8;
const uint32 gl_texture9                       = 0x84C9;
const uint32 gl_texture10                      = 0x84CA;
const uint32 gl_texture11                      = 0x84CB;
const uint32 gl_texture12                      = 0x84CC;
const uint32 gl_texture13                      = 0x84CD;
const uint32 gl_texture14                      = 0x84CE;
const uint32 gl_texture15                      = 0x84CF;
const uint32 gl_texture16                      = 0x84D0;
const uint32 gl_texture17                      = 0x84D1;
const uint32 gl_texture18                      = 0x84D2;
const uint32 gl_texture19                      = 0x84D3;
const uint32 gl_texture20                      = 0x84D4;
const uint32 gl_texture21                      = 0x84D5;
const uint32 gl_texture22                      = 0x84D6;
const uint32 gl_texture23                      = 0x84D7;
const uint32 gl_texture24                      = 0x84D8;
const uint32 gl_texture25                      = 0x84D9;
const uint32 gl_texture26                      = 0x84DA;
const uint32 gl_texture27                      = 0x84DB;
const uint32 gl_texture28                      = 0x84DC;
const uint32 gl_texture29                      = 0x84DD;
const uint32 gl_texture30                      = 0x84DE;
const uint32 gl_texture31                      = 0x84DF;
const uint32 gl_active_texture                 = 0x84E0;
const uint32 gl_multisample                    = 0x809D;
const uint32 gl_sample_alpha_to_coverage       = 0x809E;
const uint32 gl_sample_alpha_to_one            = 0x809F;
const uint32 gl_sample_coverage                = 0x80A0;
const uint32 gl_sample_buffers                 = 0x80A8;
const uint32 gl_samples                        = 0x80A9;
const uint32 gl_sample_coverage_value          = 0x80AA;
const uint32 gl_sample_coverage_invert         = 0x80AB;
const uint32 gl_texture_cube_map               = 0x8513;
const uint32 gl_texture_binding_cube_map       = 0x8514;
const uint32 gl_texture_cube_map_positive_x    = 0x8515;
const uint32 gl_texture_cube_map_negative_x    = 0x8516;
const uint32 gl_texture_cube_map_positive_y    = 0x8517;
const uint32 gl_texture_cube_map_negative_y    = 0x8518;
const uint32 gl_texture_cube_map_positive_z    = 0x8519;
const uint32 gl_texture_cube_map_negative_z    = 0x851A;
const uint32 gl_proxy_texture_cube_map         = 0x851B;
const uint32 gl_max_cube_map_texture_size      = 0x851C;
const uint32 gl_compressed_rgb                 = 0x84ED;
const uint32 gl_compressed_rgba                = 0x84EE;
const uint32 gl_texture_compression_hint       = 0x84EF;
const uint32 gl_texture_compressed_image_size  = 0x86A0;
const uint32 gl_texture_compressed             = 0x86A1;
const uint32 gl_num_compressed_texture_formats = 0x86A2;
const uint32 gl_compressed_texture_formats     = 0x86A3;
const uint32 gl_clamp_to_border                = 0x812D;

void glActiveTexture(GLenum texture);
void glSampleCoverage(float32 value, bool invert);
void glCompressedTexImage3D(GLenum target,
                            int32 level,
                            GLenum internalformat,
                            int32 width,
                            int32 height,
                            int32 depth,
                            int32 border,
                            int32 imageSize,
                            const void* data);
void glCompressedTexImage2D(GLenum target,
                            int32 level,
                            GLenum internalformat,
                            int32 width,
                            int32 height,
                            int32 border,
                            int32 imageSize,
                            const void* data);
void glCompressedTexImage1D(GLenum target,
                            int32 level,
                            GLenum internalformat,
                            int32 width,
                            int32 border,
                            int32 imageSize,
                            const void* data);
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
                               const void* data);
void glCompressedTexSubImage2D(GLenum target,
                               int32 level,
                               int32 xoffset,
                               int32 yoffset,
                               int32 width,
                               int32 height,
                               GLenum format,
                               int32 imageSize,
                               const void* data);
void glCompressedTexSubImage1D(GLenum target,
                               int32 level,
                               int32 xoffset,
                               int32 width,
                               GLenum format,
                               int32 imageSize,
                               const void* data);
void glGetCompressedTexImage(GLenum target, int32 level, void* img);

#pragma endregion
/// @}

/// @name gl_version_1_4
/// @{
#pragma region gl_version_1_4

const uint32 gl_blend_dst_rgb             = 0x80C8;
const uint32 gl_blend_src_rgb             = 0x80C9;
const uint32 gl_blend_dst_alpha           = 0x80CA;
const uint32 gl_blend_src_alpha           = 0x80CB;
const uint32 gl_point_fade_threshold_size = 0x8128;
const uint32 gl_depth_component16         = 0x81A5;
const uint32 gl_depth_component24         = 0x81A6;
const uint32 gl_depth_component32         = 0x81A7;
const uint32 gl_mirrored_repeat           = 0x8370;
const uint32 gl_max_texture_lod_bias      = 0x84FD;
const uint32 gl_texture_lod_bias          = 0x8501;
const uint32 gl_incr_wrap                 = 0x8507;
const uint32 gl_decr_wrap                 = 0x8508;
const uint32 gl_texture_depth_size        = 0x884A;
const uint32 gl_texture_compare_mode      = 0x884C;
const uint32 gl_texture_compare_func      = 0x884D;
const uint32 gl_blend_color               = 0x8005;
const uint32 gl_blend_equation            = 0x8009;
const uint32 gl_constant_color            = 0x8001;
const uint32 gl_one_minus_constant_color  = 0x8002;
const uint32 gl_constant_alpha            = 0x8003;
const uint32 gl_one_minus_constant_alpha  = 0x8004;
const uint32 gl_func_add                  = 0x8006;
const uint32 gl_func_reverse_subtract     = 0x800B;
const uint32 gl_func_subtract             = 0x800A;
const uint32 gl_min                       = 0x8007;
const uint32 gl_max                       = 0x8008;

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

const uint32 gl_buffer_size                        = 0x8764;
const uint32 gl_buffer_usage                       = 0x8765;
const uint32 gl_query_counter_bits                 = 0x8864;
const uint32 gl_current_query                      = 0x8865;
const uint32 gl_query_result                       = 0x8866;
const uint32 gl_query_result_available             = 0x8867;
const uint32 gl_array_buffer                       = 0x8892;
const uint32 gl_element_array_buffer               = 0x8893;
const uint32 gl_array_buffer_binding               = 0x8894;
const uint32 gl_element_array_buffer_binding       = 0x8895;
const uint32 gl_vertex_attrib_array_buffer_binding = 0x889F;
const uint32 gl_read_only                          = 0x88B8;
const uint32 gl_write_only                         = 0x88B9;
const uint32 gl_read_write                         = 0x88BA;
const uint32 gl_buffer_access                      = 0x88BB;
const uint32 gl_buffer_mapped                      = 0x88BC;
const uint32 gl_buffer_map_pointer                 = 0x88BD;
const uint32 gl_stream_draw                        = 0x88E0;
const uint32 gl_stream_read                        = 0x88E1;
const uint32 gl_stream_copy                        = 0x88E2;
const uint32 gl_static_draw                        = 0x88E4;
const uint32 gl_static_read                        = 0x88E5;
const uint32 gl_static_copy                        = 0x88E6;
const uint32 gl_dynamic_draw                       = 0x88E8;
const uint32 gl_dynamic_read                       = 0x88E9;
const uint32 gl_dynamic_copy                       = 0x88EA;
const uint32 gl_samples_passed                     = 0x8914;
const uint32 gl_src1_alpha                         = 0x8589;

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

const uint32 gl_blend_equation_rgb               = 0x8009;
const uint32 gl_vertex_attrib_array_enabled      = 0x8622;
const uint32 gl_vertex_attrib_array_size         = 0x8623;
const uint32 gl_vertex_attrib_array_stride       = 0x8624;
const uint32 gl_vertex_attrib_array_type         = 0x8625;
const uint32 gl_current_vertex_attrib            = 0x8626;
const uint32 gl_vertex_program_point_size        = 0x8642;
const uint32 gl_vertex_attrib_array_pointer      = 0x8645;
const uint32 gl_stencil_back_func                = 0x8800;
const uint32 gl_stencil_back_fail                = 0x8801;
const uint32 gl_stencil_back_pass_depth_fail     = 0x8802;
const uint32 gl_stencil_back_pass_depth_pass     = 0x8803;
const uint32 gl_max_draw_buffers                 = 0x8824;
const uint32 gl_draw_buffer0                     = 0x8825;
const uint32 gl_draw_buffer1                     = 0x8826;
const uint32 gl_draw_buffer2                     = 0x8827;
const uint32 gl_draw_buffer3                     = 0x8828;
const uint32 gl_draw_buffer4                     = 0x8829;
const uint32 gl_draw_buffer5                     = 0x882A;
const uint32 gl_draw_buffer6                     = 0x882B;
const uint32 gl_draw_buffer7                     = 0x882C;
const uint32 gl_draw_buffer8                     = 0x882D;
const uint32 gl_draw_buffer9                     = 0x882E;
const uint32 gl_draw_buffer10                    = 0x882F;
const uint32 gl_draw_buffer11                    = 0x8830;
const uint32 gl_draw_buffer12                    = 0x8831;
const uint32 gl_draw_buffer13                    = 0x8832;
const uint32 gl_draw_buffer14                    = 0x8833;
const uint32 gl_draw_buffer15                    = 0x8834;
const uint32 gl_blend_equation_alpha             = 0x883D;
const uint32 gl_max_vertex_attribs               = 0x8869;
const uint32 gl_vertex_attrib_array_normalized   = 0x886A;
const uint32 gl_max_texture_image_units          = 0x8872;
const uint32 gl_fragment_shader                  = 0x8B30;
const uint32 gl_vertex_shader                    = 0x8B31;
const uint32 gl_max_fragment_uniform_components  = 0x8B49;
const uint32 gl_max_vertex_uniform_components    = 0x8B4A;
const uint32 gl_max_varying_floats               = 0x8B4B;
const uint32 gl_max_vertex_texture_image_units   = 0x8B4C;
const uint32 gl_max_combined_texture_image_units = 0x8B4D;
const uint32 gl_shader_type                      = 0x8B4F;
const uint32 gl_float_vec2                       = 0x8B50;
const uint32 gl_float_vec3                       = 0x8B51;
const uint32 gl_float_vec4                       = 0x8B52;
const uint32 gl_int_vec2                         = 0x8B53;
const uint32 gl_int_vec3                         = 0x8B54;
const uint32 gl_int_vec4                         = 0x8B55;
const uint32 gl_bool                             = 0x8B56;
const uint32 gl_bool_vec2                        = 0x8B57;
const uint32 gl_bool_vec3                        = 0x8B58;
const uint32 gl_bool_vec4                        = 0x8B59;
const uint32 gl_float_mat2                       = 0x8B5A;
const uint32 gl_float_mat3                       = 0x8B5B;
const uint32 gl_float_mat4                       = 0x8B5C;
const uint32 gl_sampler_1d                       = 0x8B5D;
const uint32 gl_sampler_2d                       = 0x8B5E;
const uint32 gl_sampler_3d                       = 0x8B5F;
const uint32 gl_sampler_cube                     = 0x8B60;
const uint32 gl_sampler_1d_shadow                = 0x8B61;
const uint32 gl_sampler_2d_shadow                = 0x8B62;
const uint32 gl_delete_status                    = 0x8B80;
const uint32 gl_compile_status                   = 0x8B81;
const uint32 gl_link_status                      = 0x8B82;
const uint32 gl_validate_status                  = 0x8B83;
const uint32 gl_info_log_length                  = 0x8B84;
const uint32 gl_attached_shaders                 = 0x8B85;
const uint32 gl_active_uniforms                  = 0x8B86;
const uint32 gl_active_uniform_max_length        = 0x8B87;
const uint32 gl_shader_source_length             = 0x8B88;
const uint32 gl_active_attributes                = 0x8B89;
const uint32 gl_active_attribute_max_length      = 0x8B8A;
const uint32 gl_fragment_shader_derivative_hint  = 0x8B8B;
const uint32 gl_shading_language_version         = 0x8B8C;
const uint32 gl_current_program                  = 0x8B8D;
const uint32 gl_point_sprite_coord_origin        = 0x8CA0;
const uint32 gl_lower_left                       = 0x8CA1;
const uint32 gl_upper_left                       = 0x8CA2;
const uint32 gl_stencil_back_ref                 = 0x8CA3;
const uint32 gl_stencil_back_value_mask          = 0x8CA4;
const uint32 gl_stencil_back_writemask           = 0x8CA5;

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

const uint32 gl_pixel_pack_buffer           = 0x88EB;
const uint32 gl_pixel_unpack_buffer         = 0x88EC;
const uint32 gl_pixel_pack_buffer_binding   = 0x88ED;
const uint32 gl_pixel_unpack_buffer_binding = 0x88EF;
const uint32 gl_float_mat2x3                = 0x8B65;
const uint32 gl_float_mat2x4                = 0x8B66;
const uint32 gl_float_mat3x2                = 0x8B67;
const uint32 gl_float_mat3x4                = 0x8B68;
const uint32 gl_float_mat4x2                = 0x8B69;
const uint32 gl_float_mat4x3                = 0x8B6A;
const uint32 gl_srgb                        = 0x8C40;
const uint32 gl_srgb8                       = 0x8C41;
const uint32 gl_srgb_alpha                  = 0x8C42;
const uint32 gl_srgb8_alpha8                = 0x8C43;
const uint32 gl_compressed_srgb             = 0x8C48;
const uint32 gl_compressed_srgb_alpha       = 0x8C49;

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

const uint32 gl_compare_ref_to_texture                        = 0x884E;
const uint32 gl_clip_distance0                                = 0x3000;
const uint32 gl_clip_distance1                                = 0x3001;
const uint32 gl_clip_distance2                                = 0x3002;
const uint32 gl_clip_distance3                                = 0x3003;
const uint32 gl_clip_distance4                                = 0x3004;
const uint32 gl_clip_distance5                                = 0x3005;
const uint32 gl_clip_distance6                                = 0x3006;
const uint32 gl_clip_distance7                                = 0x3007;
const uint32 gl_max_clip_distances                            = 0x0D32;
const uint32 gl_major_version                                 = 0x821B;
const uint32 gl_minor_version                                 = 0x821C;
const uint32 gl_num_extensions                                = 0x821D;
const uint32 gl_context_flags                                 = 0x821E;
const uint32 gl_compressed_red                                = 0x8225;
const uint32 gl_compressed_rg                                 = 0x8226;
const uint32 gl_context_flag_forward_compatible_bit           = 0x00000001;
const uint32 gl_rgba32f                                       = 0x8814;
const uint32 gl_rgb32f                                        = 0x8815;
const uint32 gl_rgba16f                                       = 0x881A;
const uint32 gl_rgb16f                                        = 0x881B;
const uint32 gl_vertex_attrib_array_integer                   = 0x88FD;
const uint32 gl_max_array_texture_layers                      = 0x88FF;
const uint32 gl_min_program_texel_offset                      = 0x8904;
const uint32 gl_max_program_texel_offset                      = 0x8905;
const uint32 gl_clamp_read_color                              = 0x891C;
const uint32 gl_fixed_only                                    = 0x891D;
const uint32 gl_max_varying_components                        = 0x8B4B;
const uint32 gl_texture_1d_array                              = 0x8C18;
const uint32 gl_proxy_texture_1d_array                        = 0x8C19;
const uint32 gl_texture_2d_array                              = 0x8C1A;
const uint32 gl_proxy_texture_2d_array                        = 0x8C1B;
const uint32 gl_texture_binding_1d_array                      = 0x8C1C;
const uint32 gl_texture_binding_2d_array                      = 0x8C1D;
const uint32 gl_r11f_g11f_b10f                                = 0x8C3A;
const uint32 gl_unsigned_int_10f_11f_11f_rev                  = 0x8C3B;
const uint32 gl_rgb9_e5                                       = 0x8C3D;
const uint32 gl_unsigned_int_5_9_9_9_rev                      = 0x8C3E;
const uint32 gl_texture_shared_size                           = 0x8C3F;
const uint32 gl_transform_feedback_varying_max_length         = 0x8C76;
const uint32 gl_transform_feedback_buffer_mode                = 0x8C7F;
const uint32 gl_max_transform_feedback_separate_components    = 0x8C80;
const uint32 gl_transform_feedback_varyings                   = 0x8C83;
const uint32 gl_transform_feedback_buffer_start               = 0x8C84;
const uint32 gl_transform_feedback_buffer_size                = 0x8C85;
const uint32 gl_primitives_generated                          = 0x8C87;
const uint32 gl_transform_feedback_primitives_written         = 0x8C88;
const uint32 gl_rasterizer_discard                            = 0x8C89;
const uint32 gl_max_transform_feedback_interleaved_components = 0x8C8A;
const uint32 gl_max_transform_feedback_separate_attribs       = 0x8C8B;
const uint32 gl_interleaved_attribs                           = 0x8C8C;
const uint32 gl_separate_attribs                              = 0x8C8D;
const uint32 gl_transform_feedback_buffer                     = 0x8C8E;
const uint32 gl_transform_feedback_buffer_binding             = 0x8C8F;
const uint32 gl_rgba32ui                                      = 0x8D70;
const uint32 gl_rgb32ui                                       = 0x8D71;
const uint32 gl_rgba16ui                                      = 0x8D76;
const uint32 gl_rgb16ui                                       = 0x8D77;
const uint32 gl_rgba8ui                                       = 0x8D7C;
const uint32 gl_rgb8ui                                        = 0x8D7D;
const uint32 gl_rgba32i                                       = 0x8D82;
const uint32 gl_rgb32i                                        = 0x8D83;
const uint32 gl_rgba16i                                       = 0x8D88;
const uint32 gl_rgb16i                                        = 0x8D89;
const uint32 gl_rgba8i                                        = 0x8D8E;
const uint32 gl_rgb8i                                         = 0x8D8F;
const uint32 gl_red_integer                                   = 0x8D94;
const uint32 gl_green_integer                                 = 0x8D95;
const uint32 gl_blue_integer                                  = 0x8D96;
const uint32 gl_rgb_integer                                   = 0x8D98;
const uint32 gl_rgba_integer                                  = 0x8D99;
const uint32 gl_bgr_integer                                   = 0x8D9A;
const uint32 gl_bgra_integer                                  = 0x8D9B;
const uint32 gl_sampler_1d_array                              = 0x8DC0;
const uint32 gl_sampler_2d_array                              = 0x8DC1;
const uint32 gl_sampler_1d_array_shadow                       = 0x8DC3;
const uint32 gl_sampler_2d_array_shadow                       = 0x8DC4;
const uint32 gl_sampler_cube_shadow                           = 0x8DC5;
const uint32 gl_unsigned_int_vec2                             = 0x8DC6;
const uint32 gl_unsigned_int_vec3                             = 0x8DC7;
const uint32 gl_unsigned_int_vec4                             = 0x8DC8;
const uint32 gl_int_sampler_1d                                = 0x8DC9;
const uint32 gl_int_sampler_2d                                = 0x8DCA;
const uint32 gl_int_sampler_3d                                = 0x8DCB;
const uint32 gl_int_sampler_cube                              = 0x8DCC;
const uint32 gl_int_sampler_1d_array                          = 0x8DCE;
const uint32 gl_int_sampler_2d_array                          = 0x8DCF;
const uint32 gl_unsigned_int_sampler_1d                       = 0x8DD1;
const uint32 gl_unsigned_int_sampler_2d                       = 0x8DD2;
const uint32 gl_unsigned_int_sampler_3d                       = 0x8DD3;
const uint32 gl_unsigned_int_sampler_cube                     = 0x8DD4;
const uint32 gl_unsigned_int_sampler_1d_array                 = 0x8DD6;
const uint32 gl_unsigned_int_sampler_2d_array                 = 0x8DD7;
const uint32 gl_query_wait                                    = 0x8E13;
const uint32 gl_query_no_wait                                 = 0x8E14;
const uint32 gl_query_by_region_wait                          = 0x8E15;
const uint32 gl_query_by_region_no_wait                       = 0x8E16;
const uint32 gl_buffer_access_flags                           = 0x911F;
const uint32 gl_buffer_map_length                             = 0x9120;
const uint32 gl_buffer_map_offset                             = 0x9121;
const uint32 gl_depth_component32f                            = 0x8CAC;
const uint32 gl_depth32f_stencil8                             = 0x8CAD;
const uint32 gl_float_32_unsigned_int_24_8_rev                = 0x8DAD;
const uint32 gl_invalid_framebuffer_operation                 = 0x0506;
const uint32 gl_framebuffer_attachment_color_encoding         = 0x8210;
const uint32 gl_framebuffer_attachment_component_type         = 0x8211;
const uint32 gl_framebuffer_attachment_red_size               = 0x8212;
const uint32 gl_framebuffer_attachment_green_size             = 0x8213;
const uint32 gl_framebuffer_attachment_blue_size              = 0x8214;
const uint32 gl_framebuffer_attachment_alpha_size             = 0x8215;
const uint32 gl_framebuffer_attachment_depth_size             = 0x8216;
const uint32 gl_framebuffer_attachment_stencil_size           = 0x8217;
const uint32 gl_framebuffer_default                           = 0x8218;
const uint32 gl_framebuffer_undefined                         = 0x8219;
const uint32 gl_depth_stencil_attachment                      = 0x821A;
const uint32 gl_max_renderbuffer_size                         = 0x84E8;
const uint32 gl_depth_stencil                                 = 0x84F9;
const uint32 gl_unsigned_int_24_8                             = 0x84FA;
const uint32 gl_depth24_stencil8                              = 0x88F0;
const uint32 gl_texture_stencil_size                          = 0x88F1;
const uint32 gl_texture_red_type                              = 0x8C10;
const uint32 gl_texture_green_type                            = 0x8C11;
const uint32 gl_texture_blue_type                             = 0x8C12;
const uint32 gl_texture_alpha_type                            = 0x8C13;
const uint32 gl_texture_depth_type                            = 0x8C16;
const uint32 gl_unsigned_normalized                           = 0x8C17;
const uint32 gl_framebuffer_binding                           = 0x8CA6;
const uint32 gl_draw_framebuffer_binding                      = 0x8CA6;
const uint32 gl_renderbuffer_binding                          = 0x8CA7;
const uint32 gl_read_framebuffer                              = 0x8CA8;
const uint32 gl_draw_framebuffer                              = 0x8CA9;
const uint32 gl_read_framebuffer_binding                      = 0x8CAA;
const uint32 gl_renderbuffer_samples                          = 0x8CAB;
const uint32 gl_framebuffer_attachment_object_type            = 0x8CD0;
const uint32 gl_framebuffer_attachment_object_name            = 0x8CD1;
const uint32 gl_framebuffer_attachment_texture_level          = 0x8CD2;
const uint32 gl_framebuffer_attachment_texture_cube_map_face  = 0x8CD3;
const uint32 gl_framebuffer_attachment_texture_layer          = 0x8CD4;
const uint32 gl_framebuffer_complete                          = 0x8CD5;
const uint32 gl_framebuffer_incomplete_attachment             = 0x8CD6;
const uint32 gl_framebuffer_incomplete_missing_attachment     = 0x8CD7;
const uint32 gl_framebuffer_incomplete_draw_buffer            = 0x8CDB;
const uint32 gl_framebuffer_incomplete_read_buffer            = 0x8CDC;
const uint32 gl_framebuffer_unsupported                       = 0x8CDD;
const uint32 gl_max_color_attachments                         = 0x8CDF;
const uint32 gl_color_attachment0                             = 0x8CE0;
const uint32 gl_color_attachment1                             = 0x8CE1;
const uint32 gl_color_attachment2                             = 0x8CE2;
const uint32 gl_color_attachment3                             = 0x8CE3;
const uint32 gl_color_attachment4                             = 0x8CE4;
const uint32 gl_color_attachment5                             = 0x8CE5;
const uint32 gl_color_attachment6                             = 0x8CE6;
const uint32 gl_color_attachment7                             = 0x8CE7;
const uint32 gl_color_attachment8                             = 0x8CE8;
const uint32 gl_color_attachment9                             = 0x8CE9;
const uint32 gl_color_attachment10                            = 0x8CEA;
const uint32 gl_color_attachment11                            = 0x8CEB;
const uint32 gl_color_attachment12                            = 0x8CEC;
const uint32 gl_color_attachment13                            = 0x8CED;
const uint32 gl_color_attachment14                            = 0x8CEE;
const uint32 gl_color_attachment15                            = 0x8CEF;
const uint32 gl_color_attachment16                            = 0x8CF0;
const uint32 gl_color_attachment17                            = 0x8CF1;
const uint32 gl_color_attachment18                            = 0x8CF2;
const uint32 gl_color_attachment19                            = 0x8CF3;
const uint32 gl_color_attachment20                            = 0x8CF4;
const uint32 gl_color_attachment21                            = 0x8CF5;
const uint32 gl_color_attachment22                            = 0x8CF6;
const uint32 gl_color_attachment23                            = 0x8CF7;
const uint32 gl_color_attachment24                            = 0x8CF8;
const uint32 gl_color_attachment25                            = 0x8CF9;
const uint32 gl_color_attachment26                            = 0x8CFA;
const uint32 gl_color_attachment27                            = 0x8CFB;
const uint32 gl_color_attachment28                            = 0x8CFC;
const uint32 gl_color_attachment29                            = 0x8CFD;
const uint32 gl_color_attachment30                            = 0x8CFE;
const uint32 gl_color_attachment31                            = 0x8CFF;
const uint32 gl_depth_attachment                              = 0x8D00;
const uint32 gl_stencil_attachment                            = 0x8D20;
const uint32 gl_framebuffer                                   = 0x8D40;
const uint32 gl_renderbuffer                                  = 0x8D41;
const uint32 gl_renderbuffer_width                            = 0x8D42;
const uint32 gl_renderbuffer_height                           = 0x8D43;
const uint32 gl_renderbuffer_internal_format                  = 0x8D44;
const uint32 gl_stencil_index1                                = 0x8D46;
const uint32 gl_stencil_index4                                = 0x8D47;
const uint32 gl_stencil_index8                                = 0x8D48;
const uint32 gl_stencil_index16                               = 0x8D49;
const uint32 gl_renderbuffer_red_size                         = 0x8D50;
const uint32 gl_renderbuffer_green_size                       = 0x8D51;
const uint32 gl_renderbuffer_blue_size                        = 0x8D52;
const uint32 gl_renderbuffer_alpha_size                       = 0x8D53;
const uint32 gl_renderbuffer_depth_size                       = 0x8D54;
const uint32 gl_renderbuffer_stencil_size                     = 0x8D55;
const uint32 gl_framebuffer_incomplete_multisample            = 0x8D56;
const uint32 gl_max_samples                                   = 0x8D57;
const uint32 gl_framebuffer_srgb                              = 0x8DB9;
const uint32 gl_half_float                                    = 0x140B;
const uint32 gl_map_read_bit                                  = 0x0001;
const uint32 gl_map_write_bit                                 = 0x0002;
const uint32 gl_map_invalidate_range_bit                      = 0x0004;
const uint32 gl_map_invalidate_buffer_bit                     = 0x0008;
const uint32 gl_map_flush_explicit_bit                        = 0x0010;
const uint32 gl_map_unsynchronized_bit                        = 0x0020;
const uint32 gl_compressed_red_rgtc1                          = 0x8DBB;
const uint32 gl_compressed_signed_red_rgtc1                   = 0x8DBC;
const uint32 gl_compressed_rg_rgtc2                           = 0x8DBD;
const uint32 gl_compressed_signed_rg_rgtc2                    = 0x8DBE;
const uint32 gl_rg                                            = 0x8227;
const uint32 gl_rg_integer                                    = 0x8228;
const uint32 gl_r8                                            = 0x8229;
const uint32 gl_r16                                           = 0x822A;
const uint32 gl_rg8                                           = 0x822B;
const uint32 gl_rg16                                          = 0x822C;
const uint32 gl_r16f                                          = 0x822D;
const uint32 gl_r32f                                          = 0x822E;
const uint32 gl_rg16f                                         = 0x822F;
const uint32 gl_rg32f                                         = 0x8230;
const uint32 gl_r8i                                           = 0x8231;
const uint32 gl_r8ui                                          = 0x8232;
const uint32 gl_r16i                                          = 0x8233;
const uint32 gl_r16ui                                         = 0x8234;
const uint32 gl_r32i                                          = 0x8235;
const uint32 gl_r32ui                                         = 0x8236;
const uint32 gl_rg8i                                          = 0x8237;
const uint32 gl_rg8ui                                         = 0x8238;
const uint32 gl_rg16i                                         = 0x8239;
const uint32 gl_rg16ui                                        = 0x823A;
const uint32 gl_rg32i                                         = 0x823B;
const uint32 gl_rg32ui                                        = 0x823C;
const uint32 gl_vertex_array_binding                          = 0x85B5;

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

const uint32 gl_sampler_2d_rect                             = 0x8B63;
const uint32 gl_sampler_2d_rect_shadow                      = 0x8B64;
const uint32 gl_sampler_buffer                              = 0x8DC2;
const uint32 gl_int_sampler_2d_rect                         = 0x8DCD;
const uint32 gl_int_sampler_buffer                          = 0x8DD0;
const uint32 gl_unsigned_int_sampler_2d_rect                = 0x8DD5;
const uint32 gl_unsigned_int_sampler_buffer                 = 0x8DD8;
const uint32 gl_texture_buffer                              = 0x8C2A;
const uint32 gl_max_texture_buffer_size                     = 0x8C2B;
const uint32 gl_texture_binding_buffer                      = 0x8C2C;
const uint32 gl_texture_buffer_data_store_binding           = 0x8C2D;
const uint32 gl_texture_rectangle                           = 0x84F5;
const uint32 gl_texture_binding_rectangle                   = 0x84F6;
const uint32 gl_proxy_texture_rectangle                     = 0x84F7;
const uint32 gl_max_rectangle_texture_size                  = 0x84F8;
const uint32 gl_r8_snorm                                    = 0x8F94;
const uint32 gl_rg8_snorm                                   = 0x8F95;
const uint32 gl_rgb8_snorm                                  = 0x8F96;
const uint32 gl_rgba8_snorm                                 = 0x8F97;
const uint32 gl_r16_snorm                                   = 0x8F98;
const uint32 gl_rg16_snorm                                  = 0x8F99;
const uint32 gl_rgb16_snorm                                 = 0x8F9A;
const uint32 gl_rgba16_snorm                                = 0x8F9B;
const uint32 gl_signed_normalized                           = 0x8F9C;
const uint32 gl_primitive_restart                           = 0x8F9D;
const uint32 gl_primitive_restart_index                     = 0x8F9E;
const uint32 gl_copy_read_buffer                            = 0x8F36;
const uint32 gl_copy_write_buffer                           = 0x8F37;
const uint32 gl_uniform_buffer                              = 0x8A11;
const uint32 gl_uniform_buffer_binding                      = 0x8A28;
const uint32 gl_uniform_buffer_start                        = 0x8A29;
const uint32 gl_uniform_buffer_size                         = 0x8A2A;
const uint32 gl_max_vertex_uniform_blocks                   = 0x8A2B;
const uint32 gl_max_geometry_uniform_blocks                 = 0x8A2C;
const uint32 gl_max_fragment_uniform_blocks                 = 0x8A2D;
const uint32 gl_max_combined_uniform_blocks                 = 0x8A2E;
const uint32 gl_max_uniform_buffer_bindings                 = 0x8A2F;
const uint32 gl_max_uniform_block_size                      = 0x8A30;
const uint32 gl_max_combined_vertex_uniform_components      = 0x8A31;
const uint32 gl_max_combined_geometry_uniform_components    = 0x8A32;
const uint32 gl_max_combined_fragment_uniform_components    = 0x8A33;
const uint32 gl_uniform_buffer_offset_alignment             = 0x8A34;
const uint32 gl_active_uniform_block_max_name_length        = 0x8A35;
const uint32 gl_active_uniform_blocks                       = 0x8A36;
const uint32 gl_uniform_type                                = 0x8A37;
const uint32 gl_uniform_size                                = 0x8A38;
const uint32 gl_uniform_name_length                         = 0x8A39;
const uint32 gl_uniform_block_index                         = 0x8A3A;
const uint32 gl_uniform_offset                              = 0x8A3B;
const uint32 gl_uniform_array_stride                        = 0x8A3C;
const uint32 gl_uniform_matrix_stride                       = 0x8A3D;
const uint32 gl_uniform_is_row_major                        = 0x8A3E;
const uint32 gl_uniform_block_binding                       = 0x8A3F;
const uint32 gl_uniform_block_data_size                     = 0x8A40;
const uint32 gl_uniform_block_name_length                   = 0x8A41;
const uint32 gl_uniform_block_active_uniforms               = 0x8A42;
const uint32 gl_uniform_block_active_uniform_indices        = 0x8A43;
const uint32 gl_uniform_block_referenced_by_vertex_shader   = 0x8A44;
const uint32 gl_uniform_block_referenced_by_geometry_shader = 0x8A45;
const uint32 gl_uniform_block_referenced_by_fragment_shader = 0x8A46;
const uint32 gl_invalid_index                               = 0xFFFFFFFFu;

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

// TODO(alex) what is this???
using GLsync = struct __GLsync*;

const uint32 gl_context_core_profile_bit                  = 0x00000001;
const uint32 gl_context_compatibility_profile_bit         = 0x00000002;
const uint32 gl_lines_adjacency                           = 0x000A;
const uint32 gl_line_strip_adjacency                      = 0x000B;
const uint32 gl_triangles_adjacency                       = 0x000C;
const uint32 gl_triangle_strip_adjacency                  = 0x000D;
const uint32 gl_program_point_size                        = 0x8642;
const uint32 gl_max_geometry_texture_image_units          = 0x8C29;
const uint32 gl_framebuffer_attachment_layered            = 0x8DA7;
const uint32 gl_framebuffer_incomplete_layer_targets      = 0x8DA8;
const uint32 gl_geometry_shader                           = 0x8DD9;
const uint32 gl_geometry_vertices_out                     = 0x8916;
const uint32 gl_geometry_input_type                       = 0x8917;
const uint32 gl_geometry_output_type                      = 0x8918;
const uint32 gl_max_geometry_uniform_components           = 0x8DDF;
const uint32 gl_max_geometry_output_vertices              = 0x8DE0;
const uint32 gl_max_geometry_total_output_components      = 0x8DE1;
const uint32 gl_max_vertex_output_components              = 0x9122;
const uint32 gl_max_geometry_input_components             = 0x9123;
const uint32 gl_max_geometry_output_components            = 0x9124;
const uint32 gl_max_fragment_input_components             = 0x9125;
const uint32 gl_context_profile_mask                      = 0x9126;
const uint32 gl_depth_clamp                               = 0x864F;
const uint32 gl_quads_follow_provoking_vertex_convention  = 0x8E4C;
const uint32 gl_first_vertex_convention                   = 0x8E4D;
const uint32 gl_last_vertex_convention                    = 0x8E4E;
const uint32 gl_provoking_vertex                          = 0x8E4F;
const uint32 gl_texture_cube_map_seamless                 = 0x884F;
const uint32 gl_max_server_wait_timeout                   = 0x9111;
const uint32 gl_object_type                               = 0x9112;
const uint32 gl_sync_condition                            = 0x9113;
const uint32 gl_sync_status                               = 0x9114;
const uint32 gl_sync_flags                                = 0x9115;
const uint32 gl_sync_fence                                = 0x9116;
const uint32 gl_sync_gpu_commands_complete                = 0x9117;
const uint32 gl_unsignaled                                = 0x9118;
const uint32 gl_signaled                                  = 0x9119;
const uint32 gl_already_signaled                          = 0x911A;
const uint32 gl_timeout_expired                           = 0x911B;
const uint32 gl_condition_satisfied                       = 0x911C;
const uint32 gl_wait_failed                               = 0x911D;
const uint64 gl_timeout_ignored                           = 0xFFFFFFFFFFFFFFFFull;
const uint32 gl_sync_flush_commands_bit                   = 0x00000001;
const uint32 gl_sample_position                           = 0x8E50;
const uint32 gl_sample_mask                               = 0x8E51;
const uint32 gl_sample_mask_value                         = 0x8E52;
const uint32 gl_max_sample_mask_words                     = 0x8E59;
const uint32 gl_texture_2d_multisample                    = 0x9100;
const uint32 gl_proxy_texture_2d_multisample              = 0x9101;
const uint32 gl_texture_2d_multisample_array              = 0x9102;
const uint32 gl_proxy_texture_2d_multisample_array        = 0x9103;
const uint32 gl_texture_binding_2d_multisample            = 0x9104;
const uint32 gl_texture_binding_2d_multisample_array      = 0x9105;
const uint32 gl_texture_samples                           = 0x9106;
const uint32 gl_texture_fixed_sample_locations            = 0x9107;
const uint32 gl_sampler_2d_multisample                    = 0x9108;
const uint32 gl_int_sampler_2d_multisample                = 0x9109;
const uint32 gl_unsigned_int_sampler_2d_multisample       = 0x910A;
const uint32 gl_sampler_2d_multisample_array              = 0x910B;
const uint32 gl_int_sampler_2d_multisample_array          = 0x910C;
const uint32 gl_unsigned_int_sampler_2d_multisample_array = 0x910D;
const uint32 gl_max_color_texture_samples                 = 0x910E;
const uint32 gl_max_depth_texture_samples                 = 0x910F;
const uint32 gl_max_integer_samples                       = 0x9110;

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

const uint32 gl_vertex_attrib_array_divisor  = 0x88FE;
const uint32 gl_src1_color                   = 0x88F9;
const uint32 gl_one_minus_src1_color         = 0x88FA;
const uint32 gl_one_minus_src1_alpha         = 0x88FB;
const uint32 gl_max_dual_source_draw_buffers = 0x88FC;
const uint32 gl_any_samples_passed           = 0x8C2F;
const uint32 gl_sampler_binding              = 0x8919;
const uint32 gl_rgb10_a2ui                   = 0x906F;
const uint32 gl_texture_swizzle_r            = 0x8E42;
const uint32 gl_texture_swizzle_g            = 0x8E43;
const uint32 gl_texture_swizzle_b            = 0x8E44;
const uint32 gl_texture_swizzle_a            = 0x8E45;
const uint32 gl_texture_swizzle_rgba         = 0x8E46;
const uint32 gl_time_elapsed                 = 0x88BF;
const uint32 gl_timestamp                    = 0x8E28;
const uint32 gl_int_2_10_10_10_rev           = 0x8D9F;

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

const uint32 gl_sample_shading                                     = 0x8C36;
const uint32 gl_min_sample_shading_value                           = 0x8C37;
const uint32 gl_min_program_texture_gather_offset                  = 0x8E5E;
const uint32 gl_max_program_texture_gather_offset                  = 0x8E5F;
const uint32 gl_texture_cube_map_array                             = 0x9009;
const uint32 gl_texture_binding_cube_map_array                     = 0x900A;
const uint32 gl_proxy_texture_cube_map_array                       = 0x900B;
const uint32 gl_sampler_cube_map_array                             = 0x900C;
const uint32 gl_sampler_cube_map_array_shadow                      = 0x900D;
const uint32 gl_int_sampler_cube_map_array                         = 0x900E;
const uint32 gl_unsigned_int_sampler_cube_map_array                = 0x900F;
const uint32 gl_draw_indirect_buffer                               = 0x8F3F;
const uint32 gl_draw_indirect_buffer_binding                       = 0x8F43;
const uint32 gl_geometry_shader_invocations                        = 0x887F;
const uint32 gl_max_geometry_shader_invocations                    = 0x8E5A;
const uint32 gl_min_fragment_interpolation_offset                  = 0x8E5B;
const uint32 gl_max_fragment_interpolation_offset                  = 0x8E5C;
const uint32 gl_fragment_interpolation_offset_bits                 = 0x8E5D;
const uint32 gl_max_vertex_streams                                 = 0x8E71;
const uint32 gl_double_vec2                                        = 0x8FFC;
const uint32 gl_double_vec3                                        = 0x8FFD;
const uint32 gl_double_vec4                                        = 0x8FFE;
const uint32 gl_double_mat2                                        = 0x8F46;
const uint32 gl_double_mat3                                        = 0x8F47;
const uint32 gl_double_mat4                                        = 0x8F48;
const uint32 gl_double_mat2x3                                      = 0x8F49;
const uint32 gl_double_mat2x4                                      = 0x8F4A;
const uint32 gl_double_mat3x2                                      = 0x8F4B;
const uint32 gl_double_mat3x4                                      = 0x8F4C;
const uint32 gl_double_mat4x2                                      = 0x8F4D;
const uint32 gl_double_mat4x3                                      = 0x8F4E;
const uint32 gl_active_subroutines                                 = 0x8DE5;
const uint32 gl_active_subroutine_uniforms                         = 0x8DE6;
const uint32 gl_active_subroutine_uniform_locations                = 0x8E47;
const uint32 gl_active_subroutine_max_length                       = 0x8E48;
const uint32 gl_active_subroutine_uniform_max_length               = 0x8E49;
const uint32 gl_max_subroutines                                    = 0x8DE7;
const uint32 gl_max_subroutine_uniform_locations                   = 0x8DE8;
const uint32 gl_num_compatible_subroutines                         = 0x8E4A;
const uint32 gl_compatible_subroutines                             = 0x8E4B;
const uint32 gl_patches                                            = 0x000E;
const uint32 gl_patch_vertices                                     = 0x8E72;
const uint32 gl_patch_default_inner_level                          = 0x8E73;
const uint32 gl_patch_default_outer_level                          = 0x8E74;
const uint32 gl_tess_control_output_vertices                       = 0x8E75;
const uint32 gl_tess_gen_mode                                      = 0x8E76;
const uint32 gl_tess_gen_spacing                                   = 0x8E77;
const uint32 gl_tess_gen_vertex_order                              = 0x8E78;
const uint32 gl_tess_gen_point_mode                                = 0x8E79;
const uint32 gl_isolines                                           = 0x8E7A;
const uint32 gl_fractional_odd                                     = 0x8E7B;
const uint32 gl_fractional_even                                    = 0x8E7C;
const uint32 gl_max_patch_vertices                                 = 0x8E7D;
const uint32 gl_max_tess_gen_level                                 = 0x8E7E;
const uint32 gl_max_tess_control_uniform_components                = 0x8E7F;
const uint32 gl_max_tess_evaluation_uniform_components             = 0x8E80;
const uint32 gl_max_tess_control_texture_image_units               = 0x8E81;
const uint32 gl_max_tess_evaluation_texture_image_units            = 0x8E82;
const uint32 gl_max_tess_control_output_components                 = 0x8E83;
const uint32 gl_max_tess_patch_components                          = 0x8E84;
const uint32 gl_max_tess_control_total_output_components           = 0x8E85;
const uint32 gl_max_tess_evaluation_output_components              = 0x8E86;
const uint32 gl_max_tess_control_uniform_blocks                    = 0x8E89;
const uint32 gl_max_tess_evaluation_uniform_blocks                 = 0x8E8A;
const uint32 gl_max_tess_control_input_components                  = 0x886C;
const uint32 gl_max_tess_evaluation_input_components               = 0x886D;
const uint32 gl_max_combined_tess_control_uniform_components       = 0x8E1E;
const uint32 gl_max_combined_tess_evaluation_uniform_components    = 0x8E1F;
const uint32 gl_uniform_block_referenced_by_tess_control_shader    = 0x84F0;
const uint32 gl_uniform_block_referenced_by_tess_evaluation_shader = 0x84F1;
const uint32 gl_tess_evaluation_shader                             = 0x8E87;
const uint32 gl_tess_control_shader                                = 0x8E88;
const uint32 gl_transform_feedback                                 = 0x8E22;
const uint32 gl_transform_feedback_buffer_paused                   = 0x8E23;
const uint32 gl_transform_feedback_buffer_active                   = 0x8E24;
const uint32 gl_transform_feedback_binding                         = 0x8E25;
const uint32 gl_max_transform_feedback_buffers                     = 0x8E70;

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

const uint32 gl_fixed                            = 0x140C;
const uint32 gl_implementation_color_read_type   = 0x8B9A;
const uint32 gl_implementation_color_read_format = 0x8B9B;
const uint32 gl_low_float                        = 0x8DF0;
const uint32 gl_medium_float                     = 0x8DF1;
const uint32 gl_high_float                       = 0x8DF2;
const uint32 gl_low_int                          = 0x8DF3;
const uint32 gl_medium_int                       = 0x8DF4;
const uint32 gl_high_int                         = 0x8DF5;
const uint32 gl_shader_compiler                  = 0x8DFA;
const uint32 gl_shader_binary_formats            = 0x8DF8;
const uint32 gl_num_shader_binary_formats        = 0x8DF9;
const uint32 gl_max_vertex_uniform_vectors       = 0x8DFB;
const uint32 gl_max_varying_vectors              = 0x8DFC;
const uint32 gl_max_fragment_uniform_vectors     = 0x8DFD;
const uint32 gl_rgb565                           = 0x8D62;
const uint32 gl_program_binary_retrievable_hint  = 0x8257;
const uint32 gl_program_binary_length            = 0x8741;
const uint32 gl_num_program_binary_formats       = 0x87FE;
const uint32 gl_program_binary_formats           = 0x87FF;
const uint32 gl_vertex_shader_bit                = 0x00000001;
const uint32 gl_fragment_shader_bit              = 0x00000002;
const uint32 gl_geometry_shader_bit              = 0x00000004;
const uint32 gl_tess_control_shader_bit          = 0x00000008;
const uint32 gl_tess_evaluation_shader_bit       = 0x00000010;
const uint32 gl_all_shader_bits                  = 0xFFFFFFFF;
const uint32 gl_program_separable                = 0x8258;
const uint32 gl_active_program                   = 0x8259;
const uint32 gl_program_pipeline_binding         = 0x825A;
const uint32 gl_max_viewports                    = 0x825B;
const uint32 gl_viewport_subpixel_bits           = 0x825C;
const uint32 gl_viewport_bounds_range            = 0x825D;
const uint32 gl_layer_provoking_vertex           = 0x825E;
const uint32 gl_viewport_index_provoking_vertex  = 0x825F;
const uint32 gl_undefined_vertex                 = 0x8260;

void glReleaseShaderCompiler();
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

const uint32 gl_copy_read_buffer_binding                                   = 0x8F36;
const uint32 gl_copy_write_buffer_binding                                  = 0x8F37;
const uint32 gl_transform_feedback_active                                  = 0x8E24;
const uint32 gl_transform_feedback_paused                                  = 0x8E23;
const uint32 gl_unpack_compressed_block_width                              = 0x9127;
const uint32 gl_unpack_compressed_block_height                             = 0x9128;
const uint32 gl_unpack_compressed_block_depth                              = 0x9129;
const uint32 gl_unpack_compressed_block_size                               = 0x912A;
const uint32 gl_pack_compressed_block_width                                = 0x912B;
const uint32 gl_pack_compressed_block_height                               = 0x912C;
const uint32 gl_pack_compressed_block_depth                                = 0x912D;
const uint32 gl_pack_compressed_block_size                                 = 0x912E;
const uint32 gl_num_sample_counts                                          = 0x9380;
const uint32 gl_min_map_buffer_alignment                                   = 0x90BC;
const uint32 gl_atomic_counter_buffer                                      = 0x92C0;
const uint32 gl_atomic_counter_buffer_binding                              = 0x92C1;
const uint32 gl_atomic_counter_buffer_start                                = 0x92C2;
const uint32 gl_atomic_counter_buffer_size                                 = 0x92C3;
const uint32 gl_atomic_counter_buffer_data_size                            = 0x92C4;
const uint32 gl_atomic_counter_buffer_active_atomic_counters               = 0x92C5;
const uint32 gl_atomic_counter_buffer_active_atomic_counter_indices        = 0x92C6;
const uint32 gl_atomic_counter_buffer_referenced_by_vertex_shader          = 0x92C7;
const uint32 gl_atomic_counter_buffer_referenced_by_tess_control_shader    = 0x92C8;
const uint32 gl_atomic_counter_buffer_referenced_by_tess_evaluation_shader = 0x92C9;
const uint32 gl_atomic_counter_buffer_referenced_by_geometry_shader        = 0x92CA;
const uint32 gl_atomic_counter_buffer_referenced_by_fragment_shader        = 0x92CB;
const uint32 gl_max_vertex_atomic_counter_buffers                          = 0x92CC;
const uint32 gl_max_tess_control_atomic_counter_buffers                    = 0x92CD;
const uint32 gl_max_tess_evaluation_atomic_counter_buffers                 = 0x92CE;
const uint32 gl_max_geometry_atomic_counter_buffers                        = 0x92CF;
const uint32 gl_max_fragment_atomic_counter_buffers                        = 0x92D0;
const uint32 gl_max_combined_atomic_counter_buffers                        = 0x92D1;
const uint32 gl_max_vertex_atomic_counters                                 = 0x92D2;
const uint32 gl_max_tess_control_atomic_counters                           = 0x92D3;
const uint32 gl_max_tess_evaluation_atomic_counters                        = 0x92D4;
const uint32 gl_max_geometry_atomic_counters                               = 0x92D5;
const uint32 gl_max_fragment_atomic_counters                               = 0x92D6;
const uint32 gl_max_combined_atomic_counters                               = 0x92D7;
const uint32 gl_max_atomic_counter_buffer_size                             = 0x92D8;
const uint32 gl_max_atomic_counter_buffer_bindings                         = 0x92DC;
const uint32 gl_active_atomic_counter_buffers                              = 0x92D9;
const uint32 gl_uniform_atomic_counter_buffer_index                        = 0x92DA;
const uint32 gl_unsigned_int_atomic_counter                                = 0x92DB;
const uint32 gl_vertex_attrib_array_barrier_bit                            = 0x00000001;
const uint32 gl_element_array_barrier_bit                                  = 0x00000002;
const uint32 gl_uniform_barrier_bit                                        = 0x00000004;
const uint32 gl_texture_fetch_barrier_bit                                  = 0x00000008;
const uint32 gl_shader_image_access_barrier_bit                            = 0x00000020;
const uint32 gl_command_barrier_bit                                        = 0x00000040;
const uint32 gl_pixel_buffer_barrier_bit                                   = 0x00000080;
const uint32 gl_texture_update_barrier_bit                                 = 0x00000100;
const uint32 gl_buffer_update_barrier_bit                                  = 0x00000200;
const uint32 gl_framebuffer_barrier_bit                                    = 0x00000400;
const uint32 gl_transform_feedback_barrier_bit                             = 0x00000800;
const uint32 gl_atomic_counter_barrier_bit                                 = 0x00001000;
const uint32 gl_all_barrier_bits                                           = 0xFFFFFFFF;
const uint32 gl_max_image_units                                            = 0x8F38;
const uint32 gl_max_combined_image_units_and_fragment_outputs              = 0x8F39;
const uint32 gl_image_binding_name                                         = 0x8F3A;
const uint32 gl_image_binding_level                                        = 0x8F3B;
const uint32 gl_image_binding_layered                                      = 0x8F3C;
const uint32 gl_image_binding_layer                                        = 0x8F3D;
const uint32 gl_image_binding_access                                       = 0x8F3E;
const uint32 gl_image_1d                                                   = 0x904C;
const uint32 gl_image_2d                                                   = 0x904D;
const uint32 gl_image_3d                                                   = 0x904E;
const uint32 gl_image_2d_rect                                              = 0x904F;
const uint32 gl_image_cube                                                 = 0x9050;
const uint32 gl_image_buffer                                               = 0x9051;
const uint32 gl_image_1d_array                                             = 0x9052;
const uint32 gl_image_2d_array                                             = 0x9053;
const uint32 gl_image_cube_map_array                                       = 0x9054;
const uint32 gl_image_2d_multisample                                       = 0x9055;
const uint32 gl_image_2d_multisample_array                                 = 0x9056;
const uint32 gl_int_image_1d                                               = 0x9057;
const uint32 gl_int_image_2d                                               = 0x9058;
const uint32 gl_int_image_3d                                               = 0x9059;
const uint32 gl_int_image_2d_rect                                          = 0x905A;
const uint32 gl_int_image_cube                                             = 0x905B;
const uint32 gl_int_image_buffer                                           = 0x905C;
const uint32 gl_int_image_1d_array                                         = 0x905D;
const uint32 gl_int_image_2d_array                                         = 0x905E;
const uint32 gl_int_image_cube_map_array                                   = 0x905F;
const uint32 gl_int_image_2d_multisample                                   = 0x9060;
const uint32 gl_int_image_2d_multisample_array                             = 0x9061;
const uint32 gl_unsigned_int_image_1d                                      = 0x9062;
const uint32 gl_unsigned_int_image_2d                                      = 0x9063;
const uint32 gl_unsigned_int_image_3d                                      = 0x9064;
const uint32 gl_unsigned_int_image_2d_rect                                 = 0x9065;
const uint32 gl_unsigned_int_image_cube                                    = 0x9066;
const uint32 gl_unsigned_int_image_buffer                                  = 0x9067;
const uint32 gl_unsigned_int_image_1d_array                                = 0x9068;
const uint32 gl_unsigned_int_image_2d_array                                = 0x9069;
const uint32 gl_unsigned_int_image_cube_map_array                          = 0x906A;
const uint32 gl_unsigned_int_image_2d_multisample                          = 0x906B;
const uint32 gl_unsigned_int_image_2d_multisample_array                    = 0x906C;
const uint32 gl_max_image_samples                                          = 0x906D;
const uint32 gl_image_binding_format                                       = 0x906E;
const uint32 gl_image_format_compatibility_type                            = 0x90C7;
const uint32 gl_image_format_compatibility_by_size                         = 0x90C8;
const uint32 gl_image_format_compatibility_by_class                        = 0x90C9;
const uint32 gl_max_vertex_image_uniforms                                  = 0x90CA;
const uint32 gl_max_tess_control_image_uniforms                            = 0x90CB;
const uint32 gl_max_tess_evaluation_image_uniforms                         = 0x90CC;
const uint32 gl_max_geometry_image_uniforms                                = 0x90CD;
const uint32 gl_max_fragment_image_uniforms                                = 0x90CE;
const uint32 gl_max_combined_image_uniforms                                = 0x90CF;
const uint32 gl_compressed_rgba_bptc_unorm                                 = 0x8E8C;
const uint32 gl_compressed_srgb_alpha_bptc_unorm                           = 0x8E8D;
const uint32 gl_compressed_rgb_bptc_signed_float                           = 0x8E8E;
const uint32 gl_compressed_rgb_bptc_unsigned_float                         = 0x8E8F;
const uint32 gl_texture_immutable_format                                   = 0x912F;

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

using debug_proc_callback = void (*)(GLenum source,
                                     GLenum type,
                                     uint32 id,
                                     GLenum severity,
                                     int32 length,
                                     const char* message,
                                     const void* userParam);

const uint32 gl_num_shading_language_versions                      = 0x82E9;
const uint32 gl_vertex_attrib_array_long                           = 0x874E;
const uint32 gl_compressed_rgb8_etc2                               = 0x9274;
const uint32 gl_compressed_srgb8_etc2                              = 0x9275;
const uint32 gl_compressed_rgb8_punchthrough_alpha1_etc2           = 0x9276;
const uint32 gl_compressed_srgb8_punchthrough_alpha1_etc2          = 0x9277;
const uint32 gl_compressed_rgba8_etc2_eac                          = 0x9278;
const uint32 gl_compressed_srgb8_alpha8_etc2_eac                   = 0x9279;
const uint32 gl_compressed_r11_eac                                 = 0x9270;
const uint32 gl_compressed_signed_r11_eac                          = 0x9271;
const uint32 gl_compressed_rg11_eac                                = 0x9272;
const uint32 gl_compressed_signed_rg11_eac                         = 0x9273;
const uint32 gl_primitive_restart_fixed_index                      = 0x8D69;
const uint32 gl_any_samples_passed_conservative                    = 0x8D6A;
const uint32 gl_max_element_index                                  = 0x8D6B;
const uint32 gl_compute_shader                                     = 0x91B9;
const uint32 gl_max_compute_uniform_blocks                         = 0x91BB;
const uint32 gl_max_compute_texture_image_units                    = 0x91BC;
const uint32 gl_max_compute_image_uniforms                         = 0x91BD;
const uint32 gl_max_compute_shared_memory_size                     = 0x8262;
const uint32 gl_max_compute_uniform_components                     = 0x8263;
const uint32 gl_max_compute_atomic_counter_buffers                 = 0x8264;
const uint32 gl_max_compute_atomic_counters                        = 0x8265;
const uint32 gl_max_combined_compute_uniform_components            = 0x8266;
const uint32 gl_max_compute_work_group_invocations                 = 0x90EB;
const uint32 gl_max_compute_work_group_count                       = 0x91BE;
const uint32 gl_max_compute_work_group_size                        = 0x91BF;
const uint32 gl_compute_work_group_size                            = 0x8267;
const uint32 gl_uniform_block_referenced_by_compute_shader         = 0x90EC;
const uint32 gl_atomic_counter_buffer_referenced_by_compute_shader = 0x90ED;
const uint32 gl_dispatch_indirect_buffer                           = 0x90EE;
const uint32 gl_dispatch_indirect_buffer_binding                   = 0x90EF;
const uint32 gl_compute_shader_bit                                 = 0x00000020;
const uint32 gl_debug_output_synchronous                           = 0x8242;
const uint32 gl_debug_next_logged_message_length                   = 0x8243;
const uint32 gl_debug_callback_function                            = 0x8244;
const uint32 gl_debug_callback_user_param                          = 0x8245;
const uint32 gl_debug_source_api                                   = 0x8246;
const uint32 gl_debug_source_window_system                         = 0x8247;
const uint32 gl_debug_source_shader_compiler                       = 0x8248;
const uint32 gl_debug_source_third_party                           = 0x8249;
const uint32 gl_debug_source_application                           = 0x824A;
const uint32 gl_debug_source_other                                 = 0x824B;
const uint32 gl_debug_type_error                                   = 0x824C;
const uint32 gl_debug_type_deprecated_behavior                     = 0x824D;
const uint32 gl_debug_type_undefined_behavior                      = 0x824E;
const uint32 gl_debug_type_portability                             = 0x824F;
const uint32 gl_debug_type_performance                             = 0x8250;
const uint32 gl_debug_type_other                                   = 0x8251;
const uint32 gl_max_debug_message_length                           = 0x9143;
const uint32 gl_max_debug_logged_messages                          = 0x9144;
const uint32 gl_debug_logged_messages                              = 0x9145;
const uint32 gl_debug_severity_high                                = 0x9146;
const uint32 gl_debug_severity_medium                              = 0x9147;
const uint32 gl_debug_severity_low                                 = 0x9148;
const uint32 gl_debug_type_marker                                  = 0x8268;
const uint32 gl_debug_type_push_group                              = 0x8269;
const uint32 gl_debug_type_pop_group                               = 0x826A;
const uint32 gl_debug_severity_notification                        = 0x826B;
const uint32 gl_max_debug_group_stack_depth                        = 0x826C;
const uint32 gl_debug_group_stack_depth                            = 0x826D;
const uint32 gl_buffer                                             = 0x82E0;
const uint32 gl_shader                                             = 0x82E1;
const uint32 gl_program                                            = 0x82E2;
const uint32 gl_query                                              = 0x82E3;
const uint32 gl_program_pipeline                                   = 0x82E4;
const uint32 gl_sampler                                            = 0x82E6;
const uint32 gl_max_label_length                                   = 0x82E8;
const uint32 gl_debug_output                                       = 0x92E0;
const uint32 gl_context_flag_debug_bit                             = 0x00000002;
const uint32 gl_max_uniform_locations                              = 0x826E;
const uint32 gl_framebuffer_default_width                          = 0x9310;
const uint32 gl_framebuffer_default_height                         = 0x9311;
const uint32 gl_framebuffer_default_layers                         = 0x9312;
const uint32 gl_framebuffer_default_samples                        = 0x9313;
const uint32 gl_framebuffer_default_fixed_sample_locations         = 0x9314;
const uint32 gl_max_framebuffer_width                              = 0x9315;
const uint32 gl_max_framebuffer_height                             = 0x9316;
const uint32 gl_max_framebuffer_layers                             = 0x9317;
const uint32 gl_max_framebuffer_samples                            = 0x9318;
const uint32 gl_internalformat_supported                           = 0x826F;
const uint32 gl_internalformat_preferred                           = 0x8270;
const uint32 gl_internalformat_red_size                            = 0x8271;
const uint32 gl_internalformat_green_size                          = 0x8272;
const uint32 gl_internalformat_blue_size                           = 0x8273;
const uint32 gl_internalformat_alpha_size                          = 0x8274;
const uint32 gl_internalformat_depth_size                          = 0x8275;
const uint32 gl_internalformat_stencil_size                        = 0x8276;
const uint32 gl_internalformat_shared_size                         = 0x8277;
const uint32 gl_internalformat_red_type                            = 0x8278;
const uint32 gl_internalformat_green_type                          = 0x8279;
const uint32 gl_internalformat_blue_type                           = 0x827A;
const uint32 gl_internalformat_alpha_type                          = 0x827B;
const uint32 gl_internalformat_depth_type                          = 0x827C;
const uint32 gl_internalformat_stencil_type                        = 0x827D;
const uint32 gl_max_width                                          = 0x827E;
const uint32 gl_max_height                                         = 0x827F;
const uint32 gl_max_depth                                          = 0x8280;
const uint32 gl_max_layers                                         = 0x8281;
const uint32 gl_max_combined_dimensions                            = 0x8282;
const uint32 gl_color_components                                   = 0x8283;
const uint32 gl_depth_components                                   = 0x8284;
const uint32 gl_stencil_components                                 = 0x8285;
const uint32 gl_color_renderable                                   = 0x8286;
const uint32 gl_depth_renderable                                   = 0x8287;
const uint32 gl_stencil_renderable                                 = 0x8288;
const uint32 gl_framebuffer_renderable                             = 0x8289;
const uint32 gl_framebuffer_renderable_layered                     = 0x828A;
const uint32 gl_framebuffer_blend                                  = 0x828B;
const uint32 gl_read_pixels                                        = 0x828C;
const uint32 gl_read_pixels_format                                 = 0x828D;
const uint32 gl_read_pixels_type                                   = 0x828E;
const uint32 gl_texture_image_format                               = 0x828F;
const uint32 gl_texture_image_type                                 = 0x8290;
const uint32 gl_get_texture_image_format                           = 0x8291;
const uint32 gl_get_texture_image_type                             = 0x8292;
const uint32 gl_mipmap                                             = 0x8293;
const uint32 gl_manual_generate_mipmap                             = 0x8294;
const uint32 gl_auto_generate_mipmap                               = 0x8295;
const uint32 gl_color_encoding                                     = 0x8296;
const uint32 gl_srgb_read                                          = 0x8297;
const uint32 gl_srgb_write                                         = 0x8298;
const uint32 gl_filter                                             = 0x829A;
const uint32 gl_vertex_texture                                     = 0x829B;
const uint32 gl_tess_control_texture                               = 0x829C;
const uint32 gl_tess_evaluation_texture                            = 0x829D;
const uint32 gl_geometry_texture                                   = 0x829E;
const uint32 gl_fragment_texture                                   = 0x829F;
const uint32 gl_compute_texture                                    = 0x82A0;
const uint32 gl_texture_shadow                                     = 0x82A1;
const uint32 gl_texture_gather                                     = 0x82A2;
const uint32 gl_texture_gather_shadow                              = 0x82A3;
const uint32 gl_shader_image_load                                  = 0x82A4;
const uint32 gl_shader_image_store                                 = 0x82A5;
const uint32 gl_shader_image_atomic                                = 0x82A6;
const uint32 gl_image_texel_size                                   = 0x82A7;
const uint32 gl_image_compatibility_class                          = 0x82A8;
const uint32 gl_image_pixel_format                                 = 0x82A9;
const uint32 gl_image_pixel_type                                   = 0x82AA;
const uint32 gl_simultaneous_texture_and_depth_test                = 0x82AC;
const uint32 gl_simultaneous_texture_and_stencil_test              = 0x82AD;
const uint32 gl_simultaneous_texture_and_depth_write               = 0x82AE;
const uint32 gl_simultaneous_texture_and_stencil_write             = 0x82AF;
const uint32 gl_texture_compressed_block_width                     = 0x82B1;
const uint32 gl_texture_compressed_block_height                    = 0x82B2;
const uint32 gl_texture_compressed_block_size                      = 0x82B3;
const uint32 gl_clear_buffer                                       = 0x82B4;
const uint32 gl_texture_view                                       = 0x82B5;
const uint32 gl_view_compatibility_class                           = 0x82B6;
const uint32 gl_full_support                                       = 0x82B7;
const uint32 gl_caveat_support                                     = 0x82B8;
const uint32 gl_image_class_4_x_32                                 = 0x82B9;
const uint32 gl_image_class_2_x_32                                 = 0x82BA;
const uint32 gl_image_class_1_x_32                                 = 0x82BB;
const uint32 gl_image_class_4_x_16                                 = 0x82BC;
const uint32 gl_image_class_2_x_16                                 = 0x82BD;
const uint32 gl_image_class_1_x_16                                 = 0x82BE;
const uint32 gl_image_class_4_x_8                                  = 0x82BF;
const uint32 gl_image_class_2_x_8                                  = 0x82C0;
const uint32 gl_image_class_1_x_8                                  = 0x82C1;
const uint32 gl_image_class_11_11_10                               = 0x82C2;
const uint32 gl_image_class_10_10_10_2                             = 0x82C3;
const uint32 gl_view_class_128_bits                                = 0x82C4;
const uint32 gl_view_class_96_bits                                 = 0x82C5;
const uint32 gl_view_class_64_bits                                 = 0x82C6;
const uint32 gl_view_class_48_bits                                 = 0x82C7;
const uint32 gl_view_class_32_bits                                 = 0x82C8;
const uint32 gl_view_class_24_bits                                 = 0x82C9;
const uint32 gl_view_class_16_bits                                 = 0x82CA;
const uint32 gl_view_class_8_bits                                  = 0x82CB;
const uint32 gl_view_class_s3tc_dxt1_rgb                           = 0x82CC;
const uint32 gl_view_class_s3tc_dxt1_rgba                          = 0x82CD;
const uint32 gl_view_class_s3tc_dxt3_rgba                          = 0x82CE;
const uint32 gl_view_class_s3tc_dxt5_rgba                          = 0x82CF;
const uint32 gl_view_class_rgtc1_red                               = 0x82D0;
const uint32 gl_view_class_rgtc2_rg                                = 0x82D1;
const uint32 gl_view_class_bptc_unorm                              = 0x82D2;
const uint32 gl_view_class_bptc_float                              = 0x82D3;
const uint32 gl_uniform                                            = 0x92E1;
const uint32 gl_uniform_block                                      = 0x92E2;
const uint32 gl_program_input                                      = 0x92E3;
const uint32 gl_program_output                                     = 0x92E4;
const uint32 gl_buffer_variable                                    = 0x92E5;
const uint32 gl_shader_storage_block                               = 0x92E6;
const uint32 gl_vertex_subroutine                                  = 0x92E8;
const uint32 gl_tess_control_subroutine                            = 0x92E9;
const uint32 gl_tess_evaluation_subroutine                         = 0x92EA;
const uint32 gl_geometry_subroutine                                = 0x92EB;
const uint32 gl_fragment_subroutine                                = 0x92EC;
const uint32 gl_compute_subroutine                                 = 0x92ED;
const uint32 gl_vertex_subroutine_uniform                          = 0x92EE;
const uint32 gl_tess_control_subroutine_uniform                    = 0x92EF;
const uint32 gl_tess_evaluation_subroutine_uniform                 = 0x92F0;
const uint32 gl_geometry_subroutine_uniform                        = 0x92F1;
const uint32 gl_fragment_subroutine_uniform                        = 0x92F2;
const uint32 gl_compute_subroutine_uniform                         = 0x92F3;
const uint32 gl_transform_feedback_varying                         = 0x92F4;
const uint32 gl_active_resources                                   = 0x92F5;
const uint32 gl_max_name_length                                    = 0x92F6;
const uint32 gl_max_num_active_variables                           = 0x92F7;
const uint32 gl_max_num_compatible_subroutines                     = 0x92F8;
const uint32 gl_name_length                                        = 0x92F9;
const uint32 gl_type                                               = 0x92FA;
const uint32 gl_array_size                                         = 0x92FB;
const uint32 gl_offset                                             = 0x92FC;
const uint32 gl_block_index                                        = 0x92FD;
const uint32 gl_array_stride                                       = 0x92FE;
const uint32 gl_matrix_stride                                      = 0x92FF;
const uint32 gl_is_row_major                                       = 0x9300;
const uint32 gl_atomic_counter_buffer_index                        = 0x9301;
const uint32 gl_buffer_binding                                     = 0x9302;
const uint32 gl_buffer_data_size                                   = 0x9303;
const uint32 gl_num_active_variables                               = 0x9304;
const uint32 gl_active_variables                                   = 0x9305;
const uint32 gl_referenced_by_vertex_shader                        = 0x9306;
const uint32 gl_referenced_by_tess_control_shader                  = 0x9307;
const uint32 gl_referenced_by_tess_evaluation_shader               = 0x9308;
const uint32 gl_referenced_by_geometry_shader                      = 0x9309;
const uint32 gl_referenced_by_fragment_shader                      = 0x930A;
const uint32 gl_referenced_by_compute_shader                       = 0x930B;
const uint32 gl_top_level_array_size                               = 0x930C;
const uint32 gl_top_level_array_stride                             = 0x930D;
const uint32 gl_location                                           = 0x930E;
const uint32 gl_location_index                                     = 0x930F;
const uint32 gl_is_per_patch                                       = 0x92E7;
const uint32 gl_shader_storage_buffer                              = 0x90D2;
const uint32 gl_shader_storage_buffer_binding                      = 0x90D3;
const uint32 gl_shader_storage_buffer_start                        = 0x90D4;
const uint32 gl_shader_storage_buffer_size                         = 0x90D5;
const uint32 gl_max_vertex_shader_storage_blocks                   = 0x90D6;
const uint32 gl_max_geometry_shader_storage_blocks                 = 0x90D7;
const uint32 gl_max_tess_control_shader_storage_blocks             = 0x90D8;
const uint32 gl_max_tess_evaluation_shader_storage_blocks          = 0x90D9;
const uint32 gl_max_fragment_shader_storage_blocks                 = 0x90DA;
const uint32 gl_max_compute_shader_storage_blocks                  = 0x90DB;
const uint32 gl_max_combined_shader_storage_blocks                 = 0x90DC;
const uint32 gl_max_shader_storage_buffer_bindings                 = 0x90DD;
const uint32 gl_max_shader_storage_block_size                      = 0x90DE;
const uint32 gl_shader_storage_buffer_offset_alignment             = 0x90DF;
const uint32 gl_shader_storage_barrier_bit                         = 0x00002000;
const uint32 gl_max_combined_shader_output_resources               = 0x8F39;
const uint32 gl_depth_stencil_texture_mode                         = 0x90EA;
const uint32 gl_texture_buffer_offset                              = 0x919D;
const uint32 gl_texture_buffer_size                                = 0x919E;
const uint32 gl_texture_buffer_offset_alignment                    = 0x919F;
const uint32 gl_texture_view_min_level                             = 0x82DB;
const uint32 gl_texture_view_num_levels                            = 0x82DC;
const uint32 gl_texture_view_min_layer                             = 0x82DD;
const uint32 gl_texture_view_num_layers                            = 0x82DE;
const uint32 gl_texture_immutable_levels                           = 0x82DF;
const uint32 gl_vertex_attrib_binding                              = 0x82D4;
const uint32 gl_vertex_attrib_relative_offset                      = 0x82D5;
const uint32 gl_vertex_binding_divisor                             = 0x82D6;
const uint32 gl_vertex_binding_offset                              = 0x82D7;
const uint32 gl_vertex_binding_stride                              = 0x82D8;
const uint32 gl_max_vertex_attrib_relative_offset                  = 0x82D9;
const uint32 gl_max_vertex_attrib_bindings                         = 0x82DA;
const uint32 gl_vertex_binding_buffer                              = 0x8F4F;

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

const uint32 gl_max_vertex_attrib_stride                = 0x82E5;
const uint32 gl_primitive_restart_for_patches_supported = 0x8221;
const uint32 gl_texture_buffer_binding                  = 0x8C2A;
const uint32 gl_map_persistent_bit                      = 0x0040;
const uint32 gl_map_coherent_bit                        = 0x0080;
const uint32 gl_dynamic_storage_bit                     = 0x0100;
const uint32 gl_client_storage_bit                      = 0x0200;
const uint32 gl_client_mapped_buffer_barrier_bit        = 0x00004000;
const uint32 gl_buffer_immutable_storage                = 0x821F;
const uint32 gl_buffer_storage_flags                    = 0x8220;
const uint32 gl_clear_texture                           = 0x9365;
const uint32 gl_location_component                      = 0x934A;
const uint32 gl_transform_feedback_buffer_index         = 0x934B;
const uint32 gl_transform_feedback_buffer_stride        = 0x934C;
const uint32 gl_query_buffer                            = 0x9192;
const uint32 gl_query_buffer_barrier_bit                = 0x00008000;
const uint32 gl_query_buffer_binding                    = 0x9193;
const uint32 gl_query_result_no_wait                    = 0x9194;
const uint32 gl_mirror_clamp_to_edge                    = 0x8743;

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

const uint32 gl_context_lost                         = 0x0507;
const uint32 gl_negative_one_to_one                  = 0x935E;
const uint32 gl_zero_to_one                          = 0x935F;
const uint32 gl_clip_origin                          = 0x935C;
const uint32 gl_clip_depth_mode                      = 0x935D;
const uint32 gl_query_wait_inverted                  = 0x8E17;
const uint32 gl_query_no_wait_inverted               = 0x8E18;
const uint32 gl_query_by_region_wait_inverted        = 0x8E19;
const uint32 gl_query_by_region_no_wait_inverted     = 0x8E1A;
const uint32 gl_max_cull_distances                   = 0x82F9;
const uint32 gl_max_combined_clip_and_cull_distances = 0x82FA;
const uint32 gl_texture_target                       = 0x1006;
const uint32 gl_query_target                         = 0x82EA;
const uint32 gl_guilty_context_reset                 = 0x8253;
const uint32 gl_innocent_context_reset               = 0x8254;
const uint32 gl_unknown_context_reset                = 0x8255;
const uint32 gl_reset_notification_strategy          = 0x8256;
const uint32 gl_lose_context_on_reset                = 0x8252;
const uint32 gl_no_reset_notification                = 0x8261;
const uint32 gl_context_flag_robust_access_bit       = 0x00000004;
const uint32 gl_context_release_behavior             = 0x82FB;
const uint32 gl_context_release_behavior_flush       = 0x82FC;

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

const uint32 gl_shader_binary_format_spir_v        = 0x9551;
const uint32 gl_spir_v_binary                      = 0x9552;
const uint32 gl_parameter_buffer                   = 0x80EE;
const uint32 gl_parameter_buffer_binding           = 0x80EF;
const uint32 gl_context_flag_no_error_bit          = 0x00000008;
const uint32 gl_vertices_submitted                 = 0x82EE;
const uint32 gl_primitives_submitted               = 0x82EF;
const uint32 gl_vertex_shader_invocations          = 0x82F0;
const uint32 gl_tess_control_shader_patches        = 0x82F1;
const uint32 gl_tess_evaluation_shader_invocations = 0x82F2;
const uint32 gl_geometry_shader_primitives_emitted = 0x82F3;
const uint32 gl_fragment_shader_invocations        = 0x82F4;
const uint32 gl_compute_shader_invocations         = 0x82F5;
const uint32 gl_clipping_input_primitives          = 0x82F6;
const uint32 gl_clipping_output_primitives         = 0x82F7;
const uint32 gl_polygon_offset_clamp               = 0x8E1B;
const uint32 gl_spir_v_extensions                  = 0x9553;
const uint32 gl_num_spir_v_extensions              = 0x9554;
const uint32 gl_texture_max_anisotropy             = 0x84FE;
const uint32 gl_max_texture_max_anisotropy         = 0x84FF;
const uint32 gl_transform_feedback_overflow        = 0x82EC;
const uint32 gl_transform_feedback_stream_overflow = 0x82ED;

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

#endif