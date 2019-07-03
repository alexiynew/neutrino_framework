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

#include <common/types.hpp>
#include <graphics/opengl/details/gl_details.hpp>
#include <graphics/opengl/details/gl_wrapper.hpp>

namespace
{
#pragma region init_declarations

bool init_gl_version_1_0();
bool init_gl_version_1_1();
bool init_gl_version_1_2();
bool init_gl_version_1_3();
bool init_gl_version_1_4();
bool init_gl_version_1_5();
bool init_gl_version_2_0();
bool init_gl_version_2_1();
bool init_gl_version_3_0();
bool init_gl_version_3_1();
bool init_gl_version_3_2();
bool init_gl_version_3_3();
bool init_gl_version_4_0();
bool init_gl_version_4_1();
bool init_gl_version_4_2();
bool init_gl_version_4_3();
bool init_gl_version_4_4();
bool init_gl_version_4_5();
bool init_gl_version_4_6();
bool init_gl_arb_es3_2_compatibility();
bool init_gl_arb_bindless_texture();
bool init_gl_arb_cl_event();
bool init_gl_arb_compute_variable_group_size();
bool init_gl_arb_debug_output();
bool init_gl_arb_draw_buffers_blend();
bool init_gl_arb_draw_instanced();
bool init_gl_arb_geometry_shader4();
bool init_gl_arb_gl_spirv();
bool init_gl_arb_gpu_shader_int64();
bool init_gl_arb_indirect_parameters();
bool init_gl_arb_instanced_arrays();
bool init_gl_arb_parallel_shader_compile();
bool init_gl_arb_robustness();
bool init_gl_arb_sample_locations();
bool init_gl_arb_sample_shading();
bool init_gl_arb_shading_language_include();
bool init_gl_arb_sparse_buffer();
bool init_gl_arb_sparse_texture();
bool init_gl_arb_texture_buffer_object();
bool init_gl_khr_blend_equation_advanced();
bool init_gl_khr_parallel_shader_compile();
bool init_gl_amd_framebuffer_multisample_advanced();
bool init_gl_amd_performance_monitor();
bool init_gl_ext_egl_image_storage();
bool init_gl_ext_debug_label();
bool init_gl_ext_debug_marker();
bool init_gl_ext_direct_state_access();
bool init_gl_ext_draw_instanced();
bool init_gl_ext_polygon_offset_clamp();
bool init_gl_ext_raster_multisample();
bool init_gl_ext_separate_shader_objects();
bool init_gl_ext_shader_framebuffer_fetch_non_coherent();
bool init_gl_ext_window_rectangles();
bool init_gl_intel_framebuffer_cmaa();
bool init_gl_intel_performance_query();
bool init_gl_nv_bindless_multi_draw_indirect();
bool init_gl_nv_bindless_multi_draw_indirect_count();
bool init_gl_nv_bindless_texture();
bool init_gl_nv_blend_equation_advanced();
bool init_gl_nv_clip_space_w_scaling();
bool init_gl_nv_command_list();
bool init_gl_nv_conditional_render();
bool init_gl_nv_conservative_raster();
bool init_gl_nv_conservative_raster_dilate();
bool init_gl_nv_conservative_raster_pre_snap_triangles();
bool init_gl_nv_draw_vulkan_image();
bool init_gl_nv_fragment_coverage_to_color();
bool init_gl_nv_framebuffer_mixed_samples();
bool init_gl_nv_framebuffer_multisample_coverage();
bool init_gl_nv_gpu_shader5();
bool init_gl_nv_internalformat_sample_query();
bool init_gl_nv_path_rendering();
bool init_gl_nv_sample_locations();
bool init_gl_nv_shader_buffer_load();
bool init_gl_nv_texture_barrier();
bool init_gl_nv_vertex_attrib_integer_64bit();
bool init_gl_nv_vertex_buffer_unified_memory();
bool init_gl_nv_viewport_swizzle();
bool init_gl_ovr_multiview();

#pragma endregion

} // namespace

namespace framework::graphics::opengl::details
{
bool gl_version_1_0_supported                               = false;
bool gl_version_1_1_supported                               = false;
bool gl_version_1_2_supported                               = false;
bool gl_version_1_3_supported                               = false;
bool gl_version_1_4_supported                               = false;
bool gl_version_1_5_supported                               = false;
bool gl_version_2_0_supported                               = false;
bool gl_version_2_1_supported                               = false;
bool gl_version_3_0_supported                               = false;
bool gl_version_3_1_supported                               = false;
bool gl_version_3_2_supported                               = false;
bool gl_version_3_3_supported                               = false;
bool gl_version_4_0_supported                               = false;
bool gl_version_4_1_supported                               = false;
bool gl_version_4_2_supported                               = false;
bool gl_version_4_3_supported                               = false;
bool gl_version_4_4_supported                               = false;
bool gl_version_4_5_supported                               = false;
bool gl_version_4_6_supported                               = false;
bool gl_arb_es3_2_compatibility_supported                   = false;
bool gl_arb_bindless_texture_supported                      = false;
bool gl_arb_cl_event_supported                              = false;
bool gl_arb_compute_variable_group_size_supported           = false;
bool gl_arb_debug_output_supported                          = false;
bool gl_arb_draw_buffers_blend_supported                    = false;
bool gl_arb_draw_instanced_supported                        = false;
bool gl_arb_geometry_shader4_supported                      = false;
bool gl_arb_gl_spirv_supported                              = false;
bool gl_arb_gpu_shader_int64_supported                      = false;
bool gl_arb_indirect_parameters_supported                   = false;
bool gl_arb_instanced_arrays_supported                      = false;
bool gl_arb_parallel_shader_compile_supported               = false;
bool gl_arb_robustness_supported                            = false;
bool gl_arb_sample_locations_supported                      = false;
bool gl_arb_sample_shading_supported                        = false;
bool gl_arb_shading_language_include_supported              = false;
bool gl_arb_sparse_buffer_supported                         = false;
bool gl_arb_sparse_texture_supported                        = false;
bool gl_arb_texture_buffer_object_supported                 = false;
bool gl_khr_blend_equation_advanced_supported               = false;
bool gl_khr_parallel_shader_compile_supported               = false;
bool gl_amd_framebuffer_multisample_advanced_supported      = false;
bool gl_amd_performance_monitor_supported                   = false;
bool gl_ext_egl_image_storage_supported                     = false;
bool gl_ext_debug_label_supported                           = false;
bool gl_ext_debug_marker_supported                          = false;
bool gl_ext_direct_state_access_supported                   = false;
bool gl_ext_draw_instanced_supported                        = false;
bool gl_ext_polygon_offset_clamp_supported                  = false;
bool gl_ext_raster_multisample_supported                    = false;
bool gl_ext_separate_shader_objects_supported               = false;
bool gl_ext_shader_framebuffer_fetch_non_coherent_supported = false;
bool gl_ext_window_rectangles_supported                     = false;
bool gl_intel_framebuffer_cmaa_supported                    = false;
bool gl_intel_performance_query_supported                   = false;
bool gl_nv_bindless_multi_draw_indirect_supported           = false;
bool gl_nv_bindless_multi_draw_indirect_count_supported     = false;
bool gl_nv_bindless_texture_supported                       = false;
bool gl_nv_blend_equation_advanced_supported                = false;
bool gl_nv_clip_space_w_scaling_supported                   = false;
bool gl_nv_command_list_supported                           = false;
bool gl_nv_conditional_render_supported                     = false;
bool gl_nv_conservative_raster_supported                    = false;
bool gl_nv_conservative_raster_dilate_supported             = false;
bool gl_nv_conservative_raster_pre_snap_triangles_supported = false;
bool gl_nv_draw_vulkan_image_supported                      = false;
bool gl_nv_fragment_coverage_to_color_supported             = false;
bool gl_nv_framebuffer_mixed_samples_supported              = false;
bool gl_nv_framebuffer_multisample_coverage_supported       = false;
bool gl_nv_gpu_shader5_supported                            = false;
bool gl_nv_internalformat_sample_query_supported            = false;
bool gl_nv_path_rendering_supported                         = false;
bool gl_nv_sample_locations_supported                       = false;
bool gl_nv_shader_buffer_load_supported                     = false;
bool gl_nv_texture_barrier_supported                        = false;
bool gl_nv_vertex_attrib_integer_64bit_supported            = false;
bool gl_nv_vertex_buffer_unified_memory_supported           = false;
bool gl_nv_viewport_swizzle_supported                       = false;
bool gl_ovr_multiview_supported                             = false;

#pragma region GL_VERSION_1_0

PFNGLCULLFACEPROC glCullFace                             = nullptr;
PFNGLFRONTFACEPROC glFrontFace                           = nullptr;
PFNGLHINTPROC glHint                                     = nullptr;
PFNGLLINEWIDTHPROC glLineWidth                           = nullptr;
PFNGLPOINTSIZEPROC glPointSize                           = nullptr;
PFNGLPOLYGONMODEPROC glPolygonMode                       = nullptr;
PFNGLSCISSORPROC glScissor                               = nullptr;
PFNGLTEXPARAMETERFPROC glTexParameterf                   = nullptr;
PFNGLTEXPARAMETERFVPROC glTexParameterfv                 = nullptr;
PFNGLTEXPARAMETERIPROC glTexParameteri                   = nullptr;
PFNGLTEXPARAMETERIVPROC glTexParameteriv                 = nullptr;
PFNGLTEXIMAGE1DPROC glTexImage1D                         = nullptr;
PFNGLTEXIMAGE2DPROC glTexImage2D                         = nullptr;
PFNGLDRAWBUFFERPROC glDrawBuffer                         = nullptr;
PFNGLCLEARPROC glClear                                   = nullptr;
PFNGLCLEARCOLORPROC glClearColor                         = nullptr;
PFNGLCLEARSTENCILPROC glClearStencil                     = nullptr;
PFNGLCLEARDEPTHPROC glClearDepth                         = nullptr;
PFNGLSTENCILMASKPROC glStencilMask                       = nullptr;
PFNGLCOLORMASKPROC glColorMask                           = nullptr;
PFNGLDEPTHMASKPROC glDepthMask                           = nullptr;
PFNGLDISABLEPROC glDisable                               = nullptr;
PFNGLENABLEPROC glEnable                                 = nullptr;
PFNGLFINISHPROC glFinish                                 = nullptr;
PFNGLFLUSHPROC glFlush                                   = nullptr;
PFNGLBLENDFUNCPROC glBlendFunc                           = nullptr;
PFNGLLOGICOPPROC glLogicOp                               = nullptr;
PFNGLSTENCILFUNCPROC glStencilFunc                       = nullptr;
PFNGLSTENCILOPPROC glStencilOp                           = nullptr;
PFNGLDEPTHFUNCPROC glDepthFunc                           = nullptr;
PFNGLPIXELSTOREFPROC glPixelStoref                       = nullptr;
PFNGLPIXELSTOREIPROC glPixelStorei                       = nullptr;
PFNGLREADBUFFERPROC glReadBuffer                         = nullptr;
PFNGLREADPIXELSPROC glReadPixels                         = nullptr;
PFNGLGETBOOLEANVPROC glGetBooleanv                       = nullptr;
PFNGLGETDOUBLEVPROC glGetDoublev                         = nullptr;
PFNGLGETERRORPROC glGetError                             = nullptr;
PFNGLGETFLOATVPROC glGetFloatv                           = nullptr;
PFNGLGETINTEGERVPROC glGetIntegerv                       = nullptr;
PFNGLGETSTRINGPROC glGetString                           = nullptr;
PFNGLGETTEXIMAGEPROC glGetTexImage                       = nullptr;
PFNGLGETTEXPARAMETERFVPROC glGetTexParameterfv           = nullptr;
PFNGLGETTEXPARAMETERIVPROC glGetTexParameteriv           = nullptr;
PFNGLGETTEXLEVELPARAMETERFVPROC glGetTexLevelParameterfv = nullptr;
PFNGLGETTEXLEVELPARAMETERIVPROC glGetTexLevelParameteriv = nullptr;
PFNGLISENABLEDPROC glIsEnabled                           = nullptr;
PFNGLDEPTHRANGEPROC glDepthRange                         = nullptr;
PFNGLVIEWPORTPROC glViewport                             = nullptr;

#pragma endregion

#pragma region GL_VERSION_1_1

PFNGLDRAWARRAYSPROC glDrawArrays               = nullptr;
PFNGLDRAWELEMENTSPROC glDrawElements           = nullptr;
PFNGLGETPOINTERVPROC glGetPointerv             = nullptr;
PFNGLPOLYGONOFFSETPROC glPolygonOffset         = nullptr;
PFNGLCOPYTEXIMAGE1DPROC glCopyTexImage1D       = nullptr;
PFNGLCOPYTEXIMAGE2DPROC glCopyTexImage2D       = nullptr;
PFNGLCOPYTEXSUBIMAGE1DPROC glCopyTexSubImage1D = nullptr;
PFNGLCOPYTEXSUBIMAGE2DPROC glCopyTexSubImage2D = nullptr;
PFNGLTEXSUBIMAGE1DPROC glTexSubImage1D         = nullptr;
PFNGLTEXSUBIMAGE2DPROC glTexSubImage2D         = nullptr;
PFNGLBINDTEXTUREPROC glBindTexture             = nullptr;
PFNGLDELETETEXTURESPROC glDeleteTextures       = nullptr;
PFNGLGENTEXTURESPROC glGenTextures             = nullptr;
PFNGLISTEXTUREPROC glIsTexture                 = nullptr;

#pragma endregion

#pragma region GL_VERSION_1_2

PFNGLDRAWRANGEELEMENTSPROC glDrawRangeElements = nullptr;
PFNGLTEXIMAGE3DPROC glTexImage3D               = nullptr;
PFNGLTEXSUBIMAGE3DPROC glTexSubImage3D         = nullptr;
PFNGLCOPYTEXSUBIMAGE3DPROC glCopyTexSubImage3D = nullptr;

#pragma endregion

#pragma region GL_VERSION_1_3

PFNGLACTIVETEXTUREPROC glActiveTexture                     = nullptr;
PFNGLSAMPLECOVERAGEPROC glSampleCoverage                   = nullptr;
PFNGLCOMPRESSEDTEXIMAGE3DPROC glCompressedTexImage3D       = nullptr;
PFNGLCOMPRESSEDTEXIMAGE2DPROC glCompressedTexImage2D       = nullptr;
PFNGLCOMPRESSEDTEXIMAGE1DPROC glCompressedTexImage1D       = nullptr;
PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glCompressedTexSubImage3D = nullptr;
PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glCompressedTexSubImage2D = nullptr;
PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC glCompressedTexSubImage1D = nullptr;
PFNGLGETCOMPRESSEDTEXIMAGEPROC glGetCompressedTexImage     = nullptr;

#pragma endregion

#pragma region GL_VERSION_1_4

PFNGLBLENDFUNCSEPARATEPROC glBlendFuncSeparate = nullptr;
PFNGLMULTIDRAWARRAYSPROC glMultiDrawArrays     = nullptr;
PFNGLMULTIDRAWELEMENTSPROC glMultiDrawElements = nullptr;
PFNGLPOINTPARAMETERFPROC glPointParameterf     = nullptr;
PFNGLPOINTPARAMETERFVPROC glPointParameterfv   = nullptr;
PFNGLPOINTPARAMETERIPROC glPointParameteri     = nullptr;
PFNGLPOINTPARAMETERIVPROC glPointParameteriv   = nullptr;
PFNGLBLENDCOLORPROC glBlendColor               = nullptr;
PFNGLBLENDEQUATIONPROC glBlendEquation         = nullptr;

#pragma endregion

#pragma region GL_VERSION_1_5

PFNGLGENQUERIESPROC glGenQueries                     = nullptr;
PFNGLDELETEQUERIESPROC glDeleteQueries               = nullptr;
PFNGLISQUERYPROC glIsQuery                           = nullptr;
PFNGLBEGINQUERYPROC glBeginQuery                     = nullptr;
PFNGLENDQUERYPROC glEndQuery                         = nullptr;
PFNGLGETQUERYIVPROC glGetQueryiv                     = nullptr;
PFNGLGETQUERYOBJECTIVPROC glGetQueryObjectiv         = nullptr;
PFNGLGETQUERYOBJECTUIVPROC glGetQueryObjectuiv       = nullptr;
PFNGLBINDBUFFERPROC glBindBuffer                     = nullptr;
PFNGLDELETEBUFFERSPROC glDeleteBuffers               = nullptr;
PFNGLGENBUFFERSPROC glGenBuffers                     = nullptr;
PFNGLISBUFFERPROC glIsBuffer                         = nullptr;
PFNGLBUFFERDATAPROC glBufferData                     = nullptr;
PFNGLBUFFERSUBDATAPROC glBufferSubData               = nullptr;
PFNGLGETBUFFERSUBDATAPROC glGetBufferSubData         = nullptr;
PFNGLMAPBUFFERPROC glMapBuffer                       = nullptr;
PFNGLUNMAPBUFFERPROC glUnmapBuffer                   = nullptr;
PFNGLGETBUFFERPARAMETERIVPROC glGetBufferParameteriv = nullptr;
PFNGLGETBUFFERPOINTERVPROC glGetBufferPointerv       = nullptr;

#pragma endregion

#pragma region GL_VERSION_2_0

PFNGLBLENDEQUATIONSEPARATEPROC glBlendEquationSeparate       = nullptr;
PFNGLDRAWBUFFERSPROC glDrawBuffers                           = nullptr;
PFNGLSTENCILOPSEPARATEPROC glStencilOpSeparate               = nullptr;
PFNGLSTENCILFUNCSEPARATEPROC glStencilFuncSeparate           = nullptr;
PFNGLSTENCILMASKSEPARATEPROC glStencilMaskSeparate           = nullptr;
PFNGLATTACHSHADERPROC glAttachShader                         = nullptr;
PFNGLBINDATTRIBLOCATIONPROC glBindAttribLocation             = nullptr;
PFNGLCOMPILESHADERPROC glCompileShader                       = nullptr;
PFNGLCREATEPROGRAMPROC glCreateProgram                       = nullptr;
PFNGLCREATESHADERPROC glCreateShader                         = nullptr;
PFNGLDELETEPROGRAMPROC glDeleteProgram                       = nullptr;
PFNGLDELETESHADERPROC glDeleteShader                         = nullptr;
PFNGLDETACHSHADERPROC glDetachShader                         = nullptr;
PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray = nullptr;
PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray   = nullptr;
PFNGLGETACTIVEATTRIBPROC glGetActiveAttrib                   = nullptr;
PFNGLGETACTIVEUNIFORMPROC glGetActiveUniform                 = nullptr;
PFNGLGETATTACHEDSHADERSPROC glGetAttachedShaders             = nullptr;
PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation               = nullptr;
PFNGLGETPROGRAMIVPROC glGetProgramiv                         = nullptr;
PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog               = nullptr;
PFNGLGETSHADERIVPROC glGetShaderiv                           = nullptr;
PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog                 = nullptr;
PFNGLGETSHADERSOURCEPROC glGetShaderSource                   = nullptr;
PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation             = nullptr;
PFNGLGETUNIFORMFVPROC glGetUniformfv                         = nullptr;
PFNGLGETUNIFORMIVPROC glGetUniformiv                         = nullptr;
PFNGLGETVERTEXATTRIBDVPROC glGetVertexAttribdv               = nullptr;
PFNGLGETVERTEXATTRIBFVPROC glGetVertexAttribfv               = nullptr;
PFNGLGETVERTEXATTRIBIVPROC glGetVertexAttribiv               = nullptr;
PFNGLGETVERTEXATTRIBPOINTERVPROC glGetVertexAttribPointerv   = nullptr;
PFNGLISPROGRAMPROC glIsProgram                               = nullptr;
PFNGLISSHADERPROC glIsShader                                 = nullptr;
PFNGLLINKPROGRAMPROC glLinkProgram                           = nullptr;
PFNGLSHADERSOURCEPROC glShaderSource                         = nullptr;
PFNGLUSEPROGRAMPROC glUseProgram                             = nullptr;
PFNGLUNIFORM1FPROC glUniform1f                               = nullptr;
PFNGLUNIFORM2FPROC glUniform2f                               = nullptr;
PFNGLUNIFORM3FPROC glUniform3f                               = nullptr;
PFNGLUNIFORM4FPROC glUniform4f                               = nullptr;
PFNGLUNIFORM1IPROC glUniform1i                               = nullptr;
PFNGLUNIFORM2IPROC glUniform2i                               = nullptr;
PFNGLUNIFORM3IPROC glUniform3i                               = nullptr;
PFNGLUNIFORM4IPROC glUniform4i                               = nullptr;
PFNGLUNIFORM1FVPROC glUniform1fv                             = nullptr;
PFNGLUNIFORM2FVPROC glUniform2fv                             = nullptr;
PFNGLUNIFORM3FVPROC glUniform3fv                             = nullptr;
PFNGLUNIFORM4FVPROC glUniform4fv                             = nullptr;
PFNGLUNIFORM1IVPROC glUniform1iv                             = nullptr;
PFNGLUNIFORM2IVPROC glUniform2iv                             = nullptr;
PFNGLUNIFORM3IVPROC glUniform3iv                             = nullptr;
PFNGLUNIFORM4IVPROC glUniform4iv                             = nullptr;
PFNGLUNIFORMMATRIX2FVPROC glUniformMatrix2fv                 = nullptr;
PFNGLUNIFORMMATRIX3FVPROC glUniformMatrix3fv                 = nullptr;
PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv                 = nullptr;
PFNGLVALIDATEPROGRAMPROC glValidateProgram                   = nullptr;
PFNGLVERTEXATTRIB1DPROC glVertexAttrib1d                     = nullptr;
PFNGLVERTEXATTRIB1DVPROC glVertexAttrib1dv                   = nullptr;
PFNGLVERTEXATTRIB1FPROC glVertexAttrib1f                     = nullptr;
PFNGLVERTEXATTRIB1FVPROC glVertexAttrib1fv                   = nullptr;
PFNGLVERTEXATTRIB1SPROC glVertexAttrib1s                     = nullptr;
PFNGLVERTEXATTRIB1SVPROC glVertexAttrib1sv                   = nullptr;
PFNGLVERTEXATTRIB2DPROC glVertexAttrib2d                     = nullptr;
PFNGLVERTEXATTRIB2DVPROC glVertexAttrib2dv                   = nullptr;
PFNGLVERTEXATTRIB2FPROC glVertexAttrib2f                     = nullptr;
PFNGLVERTEXATTRIB2FVPROC glVertexAttrib2fv                   = nullptr;
PFNGLVERTEXATTRIB2SPROC glVertexAttrib2s                     = nullptr;
PFNGLVERTEXATTRIB2SVPROC glVertexAttrib2sv                   = nullptr;
PFNGLVERTEXATTRIB3DPROC glVertexAttrib3d                     = nullptr;
PFNGLVERTEXATTRIB3DVPROC glVertexAttrib3dv                   = nullptr;
PFNGLVERTEXATTRIB3FPROC glVertexAttrib3f                     = nullptr;
PFNGLVERTEXATTRIB3FVPROC glVertexAttrib3fv                   = nullptr;
PFNGLVERTEXATTRIB3SPROC glVertexAttrib3s                     = nullptr;
PFNGLVERTEXATTRIB3SVPROC glVertexAttrib3sv                   = nullptr;
PFNGLVERTEXATTRIB4NBVPROC glVertexAttrib4Nbv                 = nullptr;
PFNGLVERTEXATTRIB4NIVPROC glVertexAttrib4Niv                 = nullptr;
PFNGLVERTEXATTRIB4NSVPROC glVertexAttrib4Nsv                 = nullptr;
PFNGLVERTEXATTRIB4NUBPROC glVertexAttrib4Nub                 = nullptr;
PFNGLVERTEXATTRIB4NUBVPROC glVertexAttrib4Nubv               = nullptr;
PFNGLVERTEXATTRIB4NUIVPROC glVertexAttrib4Nuiv               = nullptr;
PFNGLVERTEXATTRIB4NUSVPROC glVertexAttrib4Nusv               = nullptr;
PFNGLVERTEXATTRIB4BVPROC glVertexAttrib4bv                   = nullptr;
PFNGLVERTEXATTRIB4DPROC glVertexAttrib4d                     = nullptr;
PFNGLVERTEXATTRIB4DVPROC glVertexAttrib4dv                   = nullptr;
PFNGLVERTEXATTRIB4FPROC glVertexAttrib4f                     = nullptr;
PFNGLVERTEXATTRIB4FVPROC glVertexAttrib4fv                   = nullptr;
PFNGLVERTEXATTRIB4IVPROC glVertexAttrib4iv                   = nullptr;
PFNGLVERTEXATTRIB4SPROC glVertexAttrib4s                     = nullptr;
PFNGLVERTEXATTRIB4SVPROC glVertexAttrib4sv                   = nullptr;
PFNGLVERTEXATTRIB4UBVPROC glVertexAttrib4ubv                 = nullptr;
PFNGLVERTEXATTRIB4UIVPROC glVertexAttrib4uiv                 = nullptr;
PFNGLVERTEXATTRIB4USVPROC glVertexAttrib4usv                 = nullptr;
PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer           = nullptr;

#pragma endregion

#pragma region GL_VERSION_2_1

PFNGLUNIFORMMATRIX2X3FVPROC glUniformMatrix2x3fv = nullptr;
PFNGLUNIFORMMATRIX3X2FVPROC glUniformMatrix3x2fv = nullptr;
PFNGLUNIFORMMATRIX2X4FVPROC glUniformMatrix2x4fv = nullptr;
PFNGLUNIFORMMATRIX4X2FVPROC glUniformMatrix4x2fv = nullptr;
PFNGLUNIFORMMATRIX3X4FVPROC glUniformMatrix3x4fv = nullptr;
PFNGLUNIFORMMATRIX4X3FVPROC glUniformMatrix4x3fv = nullptr;

#pragma endregion

#pragma region GL_VERSION_3_0

PFNGLCOLORMASKIPROC glColorMaski                                                   = nullptr;
PFNGLGETBOOLEANI_VPROC glGetBooleani_v                                             = nullptr;
PFNGLGETINTEGERI_VPROC glGetIntegeri_v                                             = nullptr;
PFNGLENABLEIPROC glEnablei                                                         = nullptr;
PFNGLDISABLEIPROC glDisablei                                                       = nullptr;
PFNGLISENABLEDIPROC glIsEnabledi                                                   = nullptr;
PFNGLBEGINTRANSFORMFEEDBACKPROC glBeginTransformFeedback                           = nullptr;
PFNGLENDTRANSFORMFEEDBACKPROC glEndTransformFeedback                               = nullptr;
PFNGLBINDBUFFERRANGEPROC glBindBufferRange                                         = nullptr;
PFNGLBINDBUFFERBASEPROC glBindBufferBase                                           = nullptr;
PFNGLTRANSFORMFEEDBACKVARYINGSPROC glTransformFeedbackVaryings                     = nullptr;
PFNGLGETTRANSFORMFEEDBACKVARYINGPROC glGetTransformFeedbackVarying                 = nullptr;
PFNGLCLAMPCOLORPROC glClampColor                                                   = nullptr;
PFNGLBEGINCONDITIONALRENDERPROC glBeginConditionalRender                           = nullptr;
PFNGLENDCONDITIONALRENDERPROC glEndConditionalRender                               = nullptr;
PFNGLVERTEXATTRIBIPOINTERPROC glVertexAttribIPointer                               = nullptr;
PFNGLGETVERTEXATTRIBIIVPROC glGetVertexAttribIiv                                   = nullptr;
PFNGLGETVERTEXATTRIBIUIVPROC glGetVertexAttribIuiv                                 = nullptr;
PFNGLVERTEXATTRIBI1IPROC glVertexAttribI1i                                         = nullptr;
PFNGLVERTEXATTRIBI2IPROC glVertexAttribI2i                                         = nullptr;
PFNGLVERTEXATTRIBI3IPROC glVertexAttribI3i                                         = nullptr;
PFNGLVERTEXATTRIBI4IPROC glVertexAttribI4i                                         = nullptr;
PFNGLVERTEXATTRIBI1UIPROC glVertexAttribI1ui                                       = nullptr;
PFNGLVERTEXATTRIBI2UIPROC glVertexAttribI2ui                                       = nullptr;
PFNGLVERTEXATTRIBI3UIPROC glVertexAttribI3ui                                       = nullptr;
PFNGLVERTEXATTRIBI4UIPROC glVertexAttribI4ui                                       = nullptr;
PFNGLVERTEXATTRIBI1IVPROC glVertexAttribI1iv                                       = nullptr;
PFNGLVERTEXATTRIBI2IVPROC glVertexAttribI2iv                                       = nullptr;
PFNGLVERTEXATTRIBI3IVPROC glVertexAttribI3iv                                       = nullptr;
PFNGLVERTEXATTRIBI4IVPROC glVertexAttribI4iv                                       = nullptr;
PFNGLVERTEXATTRIBI1UIVPROC glVertexAttribI1uiv                                     = nullptr;
PFNGLVERTEXATTRIBI2UIVPROC glVertexAttribI2uiv                                     = nullptr;
PFNGLVERTEXATTRIBI3UIVPROC glVertexAttribI3uiv                                     = nullptr;
PFNGLVERTEXATTRIBI4UIVPROC glVertexAttribI4uiv                                     = nullptr;
PFNGLVERTEXATTRIBI4BVPROC glVertexAttribI4bv                                       = nullptr;
PFNGLVERTEXATTRIBI4SVPROC glVertexAttribI4sv                                       = nullptr;
PFNGLVERTEXATTRIBI4UBVPROC glVertexAttribI4ubv                                     = nullptr;
PFNGLVERTEXATTRIBI4USVPROC glVertexAttribI4usv                                     = nullptr;
PFNGLGETUNIFORMUIVPROC glGetUniformuiv                                             = nullptr;
PFNGLBINDFRAGDATALOCATIONPROC glBindFragDataLocation                               = nullptr;
PFNGLGETFRAGDATALOCATIONPROC glGetFragDataLocation                                 = nullptr;
PFNGLUNIFORM1UIPROC glUniform1ui                                                   = nullptr;
PFNGLUNIFORM2UIPROC glUniform2ui                                                   = nullptr;
PFNGLUNIFORM3UIPROC glUniform3ui                                                   = nullptr;
PFNGLUNIFORM4UIPROC glUniform4ui                                                   = nullptr;
PFNGLUNIFORM1UIVPROC glUniform1uiv                                                 = nullptr;
PFNGLUNIFORM2UIVPROC glUniform2uiv                                                 = nullptr;
PFNGLUNIFORM3UIVPROC glUniform3uiv                                                 = nullptr;
PFNGLUNIFORM4UIVPROC glUniform4uiv                                                 = nullptr;
PFNGLTEXPARAMETERIIVPROC glTexParameterIiv                                         = nullptr;
PFNGLTEXPARAMETERIUIVPROC glTexParameterIuiv                                       = nullptr;
PFNGLGETTEXPARAMETERIIVPROC glGetTexParameterIiv                                   = nullptr;
PFNGLGETTEXPARAMETERIUIVPROC glGetTexParameterIuiv                                 = nullptr;
PFNGLCLEARBUFFERIVPROC glClearBufferiv                                             = nullptr;
PFNGLCLEARBUFFERUIVPROC glClearBufferuiv                                           = nullptr;
PFNGLCLEARBUFFERFVPROC glClearBufferfv                                             = nullptr;
PFNGLCLEARBUFFERFIPROC glClearBufferfi                                             = nullptr;
PFNGLGETSTRINGIPROC glGetStringi                                                   = nullptr;
PFNGLISRENDERBUFFERPROC glIsRenderbuffer                                           = nullptr;
PFNGLBINDRENDERBUFFERPROC glBindRenderbuffer                                       = nullptr;
PFNGLDELETERENDERBUFFERSPROC glDeleteRenderbuffers                                 = nullptr;
PFNGLGENRENDERBUFFERSPROC glGenRenderbuffers                                       = nullptr;
PFNGLRENDERBUFFERSTORAGEPROC glRenderbufferStorage                                 = nullptr;
PFNGLGETRENDERBUFFERPARAMETERIVPROC glGetRenderbufferParameteriv                   = nullptr;
PFNGLISFRAMEBUFFERPROC glIsFramebuffer                                             = nullptr;
PFNGLBINDFRAMEBUFFERPROC glBindFramebuffer                                         = nullptr;
PFNGLDELETEFRAMEBUFFERSPROC glDeleteFramebuffers                                   = nullptr;
PFNGLGENFRAMEBUFFERSPROC glGenFramebuffers                                         = nullptr;
PFNGLCHECKFRAMEBUFFERSTATUSPROC glCheckFramebufferStatus                           = nullptr;
PFNGLFRAMEBUFFERTEXTURE1DPROC glFramebufferTexture1D                               = nullptr;
PFNGLFRAMEBUFFERTEXTURE2DPROC glFramebufferTexture2D                               = nullptr;
PFNGLFRAMEBUFFERTEXTURE3DPROC glFramebufferTexture3D                               = nullptr;
PFNGLFRAMEBUFFERRENDERBUFFERPROC glFramebufferRenderbuffer                         = nullptr;
PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetFramebufferAttachmentParameteriv = nullptr;
PFNGLGENERATEMIPMAPPROC glGenerateMipmap                                           = nullptr;
PFNGLBLITFRAMEBUFFERPROC glBlitFramebuffer                                         = nullptr;
PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC glRenderbufferStorageMultisample           = nullptr;
PFNGLFRAMEBUFFERTEXTURELAYERPROC glFramebufferTextureLayer                         = nullptr;
PFNGLMAPBUFFERRANGEPROC glMapBufferRange                                           = nullptr;
PFNGLFLUSHMAPPEDBUFFERRANGEPROC glFlushMappedBufferRange                           = nullptr;
PFNGLBINDVERTEXARRAYPROC glBindVertexArray                                         = nullptr;
PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays                                   = nullptr;
PFNGLGENVERTEXARRAYSPROC glGenVertexArrays                                         = nullptr;
PFNGLISVERTEXARRAYPROC glIsVertexArray                                             = nullptr;

#pragma endregion

#pragma region GL_VERSION_3_1

PFNGLDRAWARRAYSINSTANCEDPROC glDrawArraysInstanced             = nullptr;
PFNGLDRAWELEMENTSINSTANCEDPROC glDrawElementsInstanced         = nullptr;
PFNGLTEXBUFFERPROC glTexBuffer                                 = nullptr;
PFNGLPRIMITIVERESTARTINDEXPROC glPrimitiveRestartIndex         = nullptr;
PFNGLCOPYBUFFERSUBDATAPROC glCopyBufferSubData                 = nullptr;
PFNGLGETUNIFORMINDICESPROC glGetUniformIndices                 = nullptr;
PFNGLGETACTIVEUNIFORMSIVPROC glGetActiveUniformsiv             = nullptr;
PFNGLGETACTIVEUNIFORMNAMEPROC glGetActiveUniformName           = nullptr;
PFNGLGETUNIFORMBLOCKINDEXPROC glGetUniformBlockIndex           = nullptr;
PFNGLGETACTIVEUNIFORMBLOCKIVPROC glGetActiveUniformBlockiv     = nullptr;
PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glGetActiveUniformBlockName = nullptr;
PFNGLUNIFORMBLOCKBINDINGPROC glUniformBlockBinding             = nullptr;

#pragma endregion

#pragma region GL_VERSION_3_2

PFNGLDRAWELEMENTSBASEVERTEXPROC glDrawElementsBaseVertex                   = nullptr;
PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC glDrawRangeElementsBaseVertex         = nullptr;
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC glDrawElementsInstancedBaseVertex = nullptr;
PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC glMultiDrawElementsBaseVertex         = nullptr;
PFNGLPROVOKINGVERTEXPROC glProvokingVertex                                 = nullptr;
PFNGLFENCESYNCPROC glFenceSync                                             = nullptr;
PFNGLISSYNCPROC glIsSync                                                   = nullptr;
PFNGLDELETESYNCPROC glDeleteSync                                           = nullptr;
PFNGLCLIENTWAITSYNCPROC glClientWaitSync                                   = nullptr;
PFNGLWAITSYNCPROC glWaitSync                                               = nullptr;
PFNGLGETINTEGER64VPROC glGetInteger64v                                     = nullptr;
PFNGLGETSYNCIVPROC glGetSynciv                                             = nullptr;
PFNGLGETINTEGER64I_VPROC glGetInteger64i_v                                 = nullptr;
PFNGLGETBUFFERPARAMETERI64VPROC glGetBufferParameteri64v                   = nullptr;
PFNGLFRAMEBUFFERTEXTUREPROC glFramebufferTexture                           = nullptr;
PFNGLTEXIMAGE2DMULTISAMPLEPROC glTexImage2DMultisample                     = nullptr;
PFNGLTEXIMAGE3DMULTISAMPLEPROC glTexImage3DMultisample                     = nullptr;
PFNGLGETMULTISAMPLEFVPROC glGetMultisamplefv                               = nullptr;
PFNGLSAMPLEMASKIPROC glSampleMaski                                         = nullptr;

#pragma endregion

#pragma region GL_VERSION_3_3

PFNGLBINDFRAGDATALOCATIONINDEXEDPROC glBindFragDataLocationIndexed = nullptr;
PFNGLGETFRAGDATAINDEXPROC glGetFragDataIndex                       = nullptr;
PFNGLGENSAMPLERSPROC glGenSamplers                                 = nullptr;
PFNGLDELETESAMPLERSPROC glDeleteSamplers                           = nullptr;
PFNGLISSAMPLERPROC glIsSampler                                     = nullptr;
PFNGLBINDSAMPLERPROC glBindSampler                                 = nullptr;
PFNGLSAMPLERPARAMETERIPROC glSamplerParameteri                     = nullptr;
PFNGLSAMPLERPARAMETERIVPROC glSamplerParameteriv                   = nullptr;
PFNGLSAMPLERPARAMETERFPROC glSamplerParameterf                     = nullptr;
PFNGLSAMPLERPARAMETERFVPROC glSamplerParameterfv                   = nullptr;
PFNGLSAMPLERPARAMETERIIVPROC glSamplerParameterIiv                 = nullptr;
PFNGLSAMPLERPARAMETERIUIVPROC glSamplerParameterIuiv               = nullptr;
PFNGLGETSAMPLERPARAMETERIVPROC glGetSamplerParameteriv             = nullptr;
PFNGLGETSAMPLERPARAMETERIIVPROC glGetSamplerParameterIiv           = nullptr;
PFNGLGETSAMPLERPARAMETERFVPROC glGetSamplerParameterfv             = nullptr;
PFNGLGETSAMPLERPARAMETERIUIVPROC glGetSamplerParameterIuiv         = nullptr;
PFNGLQUERYCOUNTERPROC glQueryCounter                               = nullptr;
PFNGLGETQUERYOBJECTI64VPROC glGetQueryObjecti64v                   = nullptr;
PFNGLGETQUERYOBJECTUI64VPROC glGetQueryObjectui64v                 = nullptr;
PFNGLVERTEXATTRIBDIVISORPROC glVertexAttribDivisor                 = nullptr;
PFNGLVERTEXATTRIBP1UIPROC glVertexAttribP1ui                       = nullptr;
PFNGLVERTEXATTRIBP1UIVPROC glVertexAttribP1uiv                     = nullptr;
PFNGLVERTEXATTRIBP2UIPROC glVertexAttribP2ui                       = nullptr;
PFNGLVERTEXATTRIBP2UIVPROC glVertexAttribP2uiv                     = nullptr;
PFNGLVERTEXATTRIBP3UIPROC glVertexAttribP3ui                       = nullptr;
PFNGLVERTEXATTRIBP3UIVPROC glVertexAttribP3uiv                     = nullptr;
PFNGLVERTEXATTRIBP4UIPROC glVertexAttribP4ui                       = nullptr;
PFNGLVERTEXATTRIBP4UIVPROC glVertexAttribP4uiv                     = nullptr;

#pragma endregion

#pragma region GL_VERSION_4_0

PFNGLMINSAMPLESHADINGPROC glMinSampleShading                             = nullptr;
PFNGLBLENDEQUATIONIPROC glBlendEquationi                                 = nullptr;
PFNGLBLENDEQUATIONSEPARATEIPROC glBlendEquationSeparatei                 = nullptr;
PFNGLBLENDFUNCIPROC glBlendFunci                                         = nullptr;
PFNGLBLENDFUNCSEPARATEIPROC glBlendFuncSeparatei                         = nullptr;
PFNGLDRAWARRAYSINDIRECTPROC glDrawArraysIndirect                         = nullptr;
PFNGLDRAWELEMENTSINDIRECTPROC glDrawElementsIndirect                     = nullptr;
PFNGLUNIFORM1DPROC glUniform1d                                           = nullptr;
PFNGLUNIFORM2DPROC glUniform2d                                           = nullptr;
PFNGLUNIFORM3DPROC glUniform3d                                           = nullptr;
PFNGLUNIFORM4DPROC glUniform4d                                           = nullptr;
PFNGLUNIFORM1DVPROC glUniform1dv                                         = nullptr;
PFNGLUNIFORM2DVPROC glUniform2dv                                         = nullptr;
PFNGLUNIFORM3DVPROC glUniform3dv                                         = nullptr;
PFNGLUNIFORM4DVPROC glUniform4dv                                         = nullptr;
PFNGLUNIFORMMATRIX2DVPROC glUniformMatrix2dv                             = nullptr;
PFNGLUNIFORMMATRIX3DVPROC glUniformMatrix3dv                             = nullptr;
PFNGLUNIFORMMATRIX4DVPROC glUniformMatrix4dv                             = nullptr;
PFNGLUNIFORMMATRIX2X3DVPROC glUniformMatrix2x3dv                         = nullptr;
PFNGLUNIFORMMATRIX2X4DVPROC glUniformMatrix2x4dv                         = nullptr;
PFNGLUNIFORMMATRIX3X2DVPROC glUniformMatrix3x2dv                         = nullptr;
PFNGLUNIFORMMATRIX3X4DVPROC glUniformMatrix3x4dv                         = nullptr;
PFNGLUNIFORMMATRIX4X2DVPROC glUniformMatrix4x2dv                         = nullptr;
PFNGLUNIFORMMATRIX4X3DVPROC glUniformMatrix4x3dv                         = nullptr;
PFNGLGETUNIFORMDVPROC glGetUniformdv                                     = nullptr;
PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC glGetSubroutineUniformLocation     = nullptr;
PFNGLGETSUBROUTINEINDEXPROC glGetSubroutineIndex                         = nullptr;
PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC glGetActiveSubroutineUniformiv     = nullptr;
PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC glGetActiveSubroutineUniformName = nullptr;
PFNGLGETACTIVESUBROUTINENAMEPROC glGetActiveSubroutineName               = nullptr;
PFNGLUNIFORMSUBROUTINESUIVPROC glUniformSubroutinesuiv                   = nullptr;
PFNGLGETUNIFORMSUBROUTINEUIVPROC glGetUniformSubroutineuiv               = nullptr;
PFNGLGETPROGRAMSTAGEIVPROC glGetProgramStageiv                           = nullptr;
PFNGLPATCHPARAMETERIPROC glPatchParameteri                               = nullptr;
PFNGLPATCHPARAMETERFVPROC glPatchParameterfv                             = nullptr;
PFNGLBINDTRANSFORMFEEDBACKPROC glBindTransformFeedback                   = nullptr;
PFNGLDELETETRANSFORMFEEDBACKSPROC glDeleteTransformFeedbacks             = nullptr;
PFNGLGENTRANSFORMFEEDBACKSPROC glGenTransformFeedbacks                   = nullptr;
PFNGLISTRANSFORMFEEDBACKPROC glIsTransformFeedback                       = nullptr;
PFNGLPAUSETRANSFORMFEEDBACKPROC glPauseTransformFeedback                 = nullptr;
PFNGLRESUMETRANSFORMFEEDBACKPROC glResumeTransformFeedback               = nullptr;
PFNGLDRAWTRANSFORMFEEDBACKPROC glDrawTransformFeedback                   = nullptr;
PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC glDrawTransformFeedbackStream       = nullptr;
PFNGLBEGINQUERYINDEXEDPROC glBeginQueryIndexed                           = nullptr;
PFNGLENDQUERYINDEXEDPROC glEndQueryIndexed                               = nullptr;
PFNGLGETQUERYINDEXEDIVPROC glGetQueryIndexediv                           = nullptr;

#pragma endregion

#pragma region GL_VERSION_4_1

PFNGLRELEASESHADERCOMPILERPROC glReleaseShaderCompiler         = nullptr;
PFNGLSHADERBINARYPROC glShaderBinary                           = nullptr;
PFNGLGETSHADERPRECISIONFORMATPROC glGetShaderPrecisionFormat   = nullptr;
PFNGLDEPTHRANGEFPROC glDepthRangef                             = nullptr;
PFNGLCLEARDEPTHFPROC glClearDepthf                             = nullptr;
PFNGLGETPROGRAMBINARYPROC glGetProgramBinary                   = nullptr;
PFNGLPROGRAMBINARYPROC glProgramBinary                         = nullptr;
PFNGLPROGRAMPARAMETERIPROC glProgramParameteri                 = nullptr;
PFNGLUSEPROGRAMSTAGESPROC glUseProgramStages                   = nullptr;
PFNGLACTIVESHADERPROGRAMPROC glActiveShaderProgram             = nullptr;
PFNGLCREATESHADERPROGRAMVPROC glCreateShaderProgramv           = nullptr;
PFNGLBINDPROGRAMPIPELINEPROC glBindProgramPipeline             = nullptr;
PFNGLDELETEPROGRAMPIPELINESPROC glDeleteProgramPipelines       = nullptr;
PFNGLGENPROGRAMPIPELINESPROC glGenProgramPipelines             = nullptr;
PFNGLISPROGRAMPIPELINEPROC glIsProgramPipeline                 = nullptr;
PFNGLGETPROGRAMPIPELINEIVPROC glGetProgramPipelineiv           = nullptr;
PFNGLPROGRAMUNIFORM1IPROC glProgramUniform1i                   = nullptr;
PFNGLPROGRAMUNIFORM1IVPROC glProgramUniform1iv                 = nullptr;
PFNGLPROGRAMUNIFORM1FPROC glProgramUniform1f                   = nullptr;
PFNGLPROGRAMUNIFORM1FVPROC glProgramUniform1fv                 = nullptr;
PFNGLPROGRAMUNIFORM1DPROC glProgramUniform1d                   = nullptr;
PFNGLPROGRAMUNIFORM1DVPROC glProgramUniform1dv                 = nullptr;
PFNGLPROGRAMUNIFORM1UIPROC glProgramUniform1ui                 = nullptr;
PFNGLPROGRAMUNIFORM1UIVPROC glProgramUniform1uiv               = nullptr;
PFNGLPROGRAMUNIFORM2IPROC glProgramUniform2i                   = nullptr;
PFNGLPROGRAMUNIFORM2IVPROC glProgramUniform2iv                 = nullptr;
PFNGLPROGRAMUNIFORM2FPROC glProgramUniform2f                   = nullptr;
PFNGLPROGRAMUNIFORM2FVPROC glProgramUniform2fv                 = nullptr;
PFNGLPROGRAMUNIFORM2DPROC glProgramUniform2d                   = nullptr;
PFNGLPROGRAMUNIFORM2DVPROC glProgramUniform2dv                 = nullptr;
PFNGLPROGRAMUNIFORM2UIPROC glProgramUniform2ui                 = nullptr;
PFNGLPROGRAMUNIFORM2UIVPROC glProgramUniform2uiv               = nullptr;
PFNGLPROGRAMUNIFORM3IPROC glProgramUniform3i                   = nullptr;
PFNGLPROGRAMUNIFORM3IVPROC glProgramUniform3iv                 = nullptr;
PFNGLPROGRAMUNIFORM3FPROC glProgramUniform3f                   = nullptr;
PFNGLPROGRAMUNIFORM3FVPROC glProgramUniform3fv                 = nullptr;
PFNGLPROGRAMUNIFORM3DPROC glProgramUniform3d                   = nullptr;
PFNGLPROGRAMUNIFORM3DVPROC glProgramUniform3dv                 = nullptr;
PFNGLPROGRAMUNIFORM3UIPROC glProgramUniform3ui                 = nullptr;
PFNGLPROGRAMUNIFORM3UIVPROC glProgramUniform3uiv               = nullptr;
PFNGLPROGRAMUNIFORM4IPROC glProgramUniform4i                   = nullptr;
PFNGLPROGRAMUNIFORM4IVPROC glProgramUniform4iv                 = nullptr;
PFNGLPROGRAMUNIFORM4FPROC glProgramUniform4f                   = nullptr;
PFNGLPROGRAMUNIFORM4FVPROC glProgramUniform4fv                 = nullptr;
PFNGLPROGRAMUNIFORM4DPROC glProgramUniform4d                   = nullptr;
PFNGLPROGRAMUNIFORM4DVPROC glProgramUniform4dv                 = nullptr;
PFNGLPROGRAMUNIFORM4UIPROC glProgramUniform4ui                 = nullptr;
PFNGLPROGRAMUNIFORM4UIVPROC glProgramUniform4uiv               = nullptr;
PFNGLPROGRAMUNIFORMMATRIX2FVPROC glProgramUniformMatrix2fv     = nullptr;
PFNGLPROGRAMUNIFORMMATRIX3FVPROC glProgramUniformMatrix3fv     = nullptr;
PFNGLPROGRAMUNIFORMMATRIX4FVPROC glProgramUniformMatrix4fv     = nullptr;
PFNGLPROGRAMUNIFORMMATRIX2DVPROC glProgramUniformMatrix2dv     = nullptr;
PFNGLPROGRAMUNIFORMMATRIX3DVPROC glProgramUniformMatrix3dv     = nullptr;
PFNGLPROGRAMUNIFORMMATRIX4DVPROC glProgramUniformMatrix4dv     = nullptr;
PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC glProgramUniformMatrix2x3fv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC glProgramUniformMatrix3x2fv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC glProgramUniformMatrix2x4fv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC glProgramUniformMatrix4x2fv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC glProgramUniformMatrix3x4fv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC glProgramUniformMatrix4x3fv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC glProgramUniformMatrix2x3dv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC glProgramUniformMatrix3x2dv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC glProgramUniformMatrix2x4dv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC glProgramUniformMatrix4x2dv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC glProgramUniformMatrix3x4dv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC glProgramUniformMatrix4x3dv = nullptr;
PFNGLVALIDATEPROGRAMPIPELINEPROC glValidateProgramPipeline     = nullptr;
PFNGLGETPROGRAMPIPELINEINFOLOGPROC glGetProgramPipelineInfoLog = nullptr;
PFNGLVERTEXATTRIBL1DPROC glVertexAttribL1d                     = nullptr;
PFNGLVERTEXATTRIBL2DPROC glVertexAttribL2d                     = nullptr;
PFNGLVERTEXATTRIBL3DPROC glVertexAttribL3d                     = nullptr;
PFNGLVERTEXATTRIBL4DPROC glVertexAttribL4d                     = nullptr;
PFNGLVERTEXATTRIBL1DVPROC glVertexAttribL1dv                   = nullptr;
PFNGLVERTEXATTRIBL2DVPROC glVertexAttribL2dv                   = nullptr;
PFNGLVERTEXATTRIBL3DVPROC glVertexAttribL3dv                   = nullptr;
PFNGLVERTEXATTRIBL4DVPROC glVertexAttribL4dv                   = nullptr;
PFNGLVERTEXATTRIBLPOINTERPROC glVertexAttribLPointer           = nullptr;
PFNGLGETVERTEXATTRIBLDVPROC glGetVertexAttribLdv               = nullptr;
PFNGLVIEWPORTARRAYVPROC glViewportArrayv                       = nullptr;
PFNGLVIEWPORTINDEXEDFPROC glViewportIndexedf                   = nullptr;
PFNGLVIEWPORTINDEXEDFVPROC glViewportIndexedfv                 = nullptr;
PFNGLSCISSORARRAYVPROC glScissorArrayv                         = nullptr;
PFNGLSCISSORINDEXEDPROC glScissorIndexed                       = nullptr;
PFNGLSCISSORINDEXEDVPROC glScissorIndexedv                     = nullptr;
PFNGLDEPTHRANGEARRAYVPROC glDepthRangeArrayv                   = nullptr;
PFNGLDEPTHRANGEINDEXEDPROC glDepthRangeIndexed                 = nullptr;
PFNGLGETFLOATI_VPROC glGetFloati_v                             = nullptr;
PFNGLGETDOUBLEI_VPROC glGetDoublei_v                           = nullptr;

#pragma endregion

#pragma region GL_VERSION_4_2

PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC glDrawArraysInstancedBaseInstance                         = nullptr;
PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC glDrawElementsInstancedBaseInstance                     = nullptr;
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC glDrawElementsInstancedBaseVertexBaseInstance = nullptr;
PFNGLGETINTERNALFORMATIVPROC glGetInternalformativ                                                 = nullptr;
PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC glGetActiveAtomicCounterBufferiv                           = nullptr;
PFNGLBINDIMAGETEXTUREPROC glBindImageTexture                                                       = nullptr;
PFNGLMEMORYBARRIERPROC glMemoryBarrier                                                             = nullptr;
PFNGLTEXSTORAGE1DPROC glTexStorage1D                                                               = nullptr;
PFNGLTEXSTORAGE2DPROC glTexStorage2D                                                               = nullptr;
PFNGLTEXSTORAGE3DPROC glTexStorage3D                                                               = nullptr;
PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC glDrawTransformFeedbackInstanced                           = nullptr;
PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC glDrawTransformFeedbackStreamInstanced               = nullptr;

#pragma endregion

#pragma region GL_VERSION_4_3

PFNGLCLEARBUFFERDATAPROC glClearBufferData                                 = nullptr;
PFNGLCLEARBUFFERSUBDATAPROC glClearBufferSubData                           = nullptr;
PFNGLDISPATCHCOMPUTEPROC glDispatchCompute                                 = nullptr;
PFNGLDISPATCHCOMPUTEINDIRECTPROC glDispatchComputeIndirect                 = nullptr;
PFNGLCOPYIMAGESUBDATAPROC glCopyImageSubData                               = nullptr;
PFNGLFRAMEBUFFERPARAMETERIPROC glFramebufferParameteri                     = nullptr;
PFNGLGETFRAMEBUFFERPARAMETERIVPROC glGetFramebufferParameteriv             = nullptr;
PFNGLGETINTERNALFORMATI64VPROC glGetInternalformati64v                     = nullptr;
PFNGLINVALIDATETEXSUBIMAGEPROC glInvalidateTexSubImage                     = nullptr;
PFNGLINVALIDATETEXIMAGEPROC glInvalidateTexImage                           = nullptr;
PFNGLINVALIDATEBUFFERSUBDATAPROC glInvalidateBufferSubData                 = nullptr;
PFNGLINVALIDATEBUFFERDATAPROC glInvalidateBufferData                       = nullptr;
PFNGLINVALIDATEFRAMEBUFFERPROC glInvalidateFramebuffer                     = nullptr;
PFNGLINVALIDATESUBFRAMEBUFFERPROC glInvalidateSubFramebuffer               = nullptr;
PFNGLMULTIDRAWARRAYSINDIRECTPROC glMultiDrawArraysIndirect                 = nullptr;
PFNGLMULTIDRAWELEMENTSINDIRECTPROC glMultiDrawElementsIndirect             = nullptr;
PFNGLGETPROGRAMINTERFACEIVPROC glGetProgramInterfaceiv                     = nullptr;
PFNGLGETPROGRAMRESOURCEINDEXPROC glGetProgramResourceIndex                 = nullptr;
PFNGLGETPROGRAMRESOURCENAMEPROC glGetProgramResourceName                   = nullptr;
PFNGLGETPROGRAMRESOURCEIVPROC glGetProgramResourceiv                       = nullptr;
PFNGLGETPROGRAMRESOURCELOCATIONPROC glGetProgramResourceLocation           = nullptr;
PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC glGetProgramResourceLocationIndex = nullptr;
PFNGLSHADERSTORAGEBLOCKBINDINGPROC glShaderStorageBlockBinding             = nullptr;
PFNGLTEXBUFFERRANGEPROC glTexBufferRange                                   = nullptr;
PFNGLTEXSTORAGE2DMULTISAMPLEPROC glTexStorage2DMultisample                 = nullptr;
PFNGLTEXSTORAGE3DMULTISAMPLEPROC glTexStorage3DMultisample                 = nullptr;
PFNGLTEXTUREVIEWPROC glTextureView                                         = nullptr;
PFNGLBINDVERTEXBUFFERPROC glBindVertexBuffer                               = nullptr;
PFNGLVERTEXATTRIBFORMATPROC glVertexAttribFormat                           = nullptr;
PFNGLVERTEXATTRIBIFORMATPROC glVertexAttribIFormat                         = nullptr;
PFNGLVERTEXATTRIBLFORMATPROC glVertexAttribLFormat                         = nullptr;
PFNGLVERTEXATTRIBBINDINGPROC glVertexAttribBinding                         = nullptr;
PFNGLVERTEXBINDINGDIVISORPROC glVertexBindingDivisor                       = nullptr;
PFNGLDEBUGMESSAGECONTROLPROC glDebugMessageControl                         = nullptr;
PFNGLDEBUGMESSAGEINSERTPROC glDebugMessageInsert                           = nullptr;
PFNGLDEBUGMESSAGECALLBACKPROC glDebugMessageCallback                       = nullptr;
PFNGLGETDEBUGMESSAGELOGPROC glGetDebugMessageLog                           = nullptr;
PFNGLPUSHDEBUGGROUPPROC glPushDebugGroup                                   = nullptr;
PFNGLPOPDEBUGGROUPPROC glPopDebugGroup                                     = nullptr;
PFNGLOBJECTLABELPROC glObjectLabel                                         = nullptr;
PFNGLGETOBJECTLABELPROC glGetObjectLabel                                   = nullptr;
PFNGLOBJECTPTRLABELPROC glObjectPtrLabel                                   = nullptr;
PFNGLGETOBJECTPTRLABELPROC glGetObjectPtrLabel                             = nullptr;

#pragma endregion

#pragma region GL_VERSION_4_4

PFNGLBUFFERSTORAGEPROC glBufferStorage         = nullptr;
PFNGLCLEARTEXIMAGEPROC glClearTexImage         = nullptr;
PFNGLCLEARTEXSUBIMAGEPROC glClearTexSubImage   = nullptr;
PFNGLBINDBUFFERSBASEPROC glBindBuffersBase     = nullptr;
PFNGLBINDBUFFERSRANGEPROC glBindBuffersRange   = nullptr;
PFNGLBINDTEXTURESPROC glBindTextures           = nullptr;
PFNGLBINDSAMPLERSPROC glBindSamplers           = nullptr;
PFNGLBINDIMAGETEXTURESPROC glBindImageTextures = nullptr;
PFNGLBINDVERTEXBUFFERSPROC glBindVertexBuffers = nullptr;

#pragma endregion

#pragma region GL_VERSION_4_5

PFNGLCLIPCONTROLPROC glClipControl                                                           = nullptr;
PFNGLCREATETRANSFORMFEEDBACKSPROC glCreateTransformFeedbacks                                 = nullptr;
PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC glTransformFeedbackBufferBase                           = nullptr;
PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC glTransformFeedbackBufferRange                         = nullptr;
PFNGLGETTRANSFORMFEEDBACKIVPROC glGetTransformFeedbackiv                                     = nullptr;
PFNGLGETTRANSFORMFEEDBACKI_VPROC glGetTransformFeedbacki_v                                   = nullptr;
PFNGLGETTRANSFORMFEEDBACKI64_VPROC glGetTransformFeedbacki64_v                               = nullptr;
PFNGLCREATEBUFFERSPROC glCreateBuffers                                                       = nullptr;
PFNGLNAMEDBUFFERSTORAGEPROC glNamedBufferStorage                                             = nullptr;
PFNGLNAMEDBUFFERDATAPROC glNamedBufferData                                                   = nullptr;
PFNGLNAMEDBUFFERSUBDATAPROC glNamedBufferSubData                                             = nullptr;
PFNGLCOPYNAMEDBUFFERSUBDATAPROC glCopyNamedBufferSubData                                     = nullptr;
PFNGLCLEARNAMEDBUFFERDATAPROC glClearNamedBufferData                                         = nullptr;
PFNGLCLEARNAMEDBUFFERSUBDATAPROC glClearNamedBufferSubData                                   = nullptr;
PFNGLMAPNAMEDBUFFERPROC glMapNamedBuffer                                                     = nullptr;
PFNGLMAPNAMEDBUFFERRANGEPROC glMapNamedBufferRange                                           = nullptr;
PFNGLUNMAPNAMEDBUFFERPROC glUnmapNamedBuffer                                                 = nullptr;
PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC glFlushMappedNamedBufferRange                           = nullptr;
PFNGLGETNAMEDBUFFERPARAMETERIVPROC glGetNamedBufferParameteriv                               = nullptr;
PFNGLGETNAMEDBUFFERPARAMETERI64VPROC glGetNamedBufferParameteri64v                           = nullptr;
PFNGLGETNAMEDBUFFERPOINTERVPROC glGetNamedBufferPointerv                                     = nullptr;
PFNGLGETNAMEDBUFFERSUBDATAPROC glGetNamedBufferSubData                                       = nullptr;
PFNGLCREATEFRAMEBUFFERSPROC glCreateFramebuffers                                             = nullptr;
PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC glNamedFramebufferRenderbuffer                         = nullptr;
PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC glNamedFramebufferParameteri                             = nullptr;
PFNGLNAMEDFRAMEBUFFERTEXTUREPROC glNamedFramebufferTexture                                   = nullptr;
PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC glNamedFramebufferTextureLayer                         = nullptr;
PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC glNamedFramebufferDrawBuffer                             = nullptr;
PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC glNamedFramebufferDrawBuffers                           = nullptr;
PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC glNamedFramebufferReadBuffer                             = nullptr;
PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC glInvalidateNamedFramebufferData                     = nullptr;
PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC glInvalidateNamedFramebufferSubData               = nullptr;
PFNGLCLEARNAMEDFRAMEBUFFERIVPROC glClearNamedFramebufferiv                                   = nullptr;
PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC glClearNamedFramebufferuiv                                 = nullptr;
PFNGLCLEARNAMEDFRAMEBUFFERFVPROC glClearNamedFramebufferfv                                   = nullptr;
PFNGLCLEARNAMEDFRAMEBUFFERFIPROC glClearNamedFramebufferfi                                   = nullptr;
PFNGLBLITNAMEDFRAMEBUFFERPROC glBlitNamedFramebuffer                                         = nullptr;
PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC glCheckNamedFramebufferStatus                           = nullptr;
PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC glGetNamedFramebufferParameteriv                     = nullptr;
PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetNamedFramebufferAttachmentParameteriv = nullptr;
PFNGLCREATERENDERBUFFERSPROC glCreateRenderbuffers                                           = nullptr;
PFNGLNAMEDRENDERBUFFERSTORAGEPROC glNamedRenderbufferStorage                                 = nullptr;
PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC glNamedRenderbufferStorageMultisample           = nullptr;
PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC glGetNamedRenderbufferParameteriv                   = nullptr;
PFNGLCREATETEXTURESPROC glCreateTextures                                                     = nullptr;
PFNGLTEXTUREBUFFERPROC glTextureBuffer                                                       = nullptr;
PFNGLTEXTUREBUFFERRANGEPROC glTextureBufferRange                                             = nullptr;
PFNGLTEXTURESTORAGE1DPROC glTextureStorage1D                                                 = nullptr;
PFNGLTEXTURESTORAGE2DPROC glTextureStorage2D                                                 = nullptr;
PFNGLTEXTURESTORAGE3DPROC glTextureStorage3D                                                 = nullptr;
PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC glTextureStorage2DMultisample                           = nullptr;
PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC glTextureStorage3DMultisample                           = nullptr;
PFNGLTEXTURESUBIMAGE1DPROC glTextureSubImage1D                                               = nullptr;
PFNGLTEXTURESUBIMAGE2DPROC glTextureSubImage2D                                               = nullptr;
PFNGLTEXTURESUBIMAGE3DPROC glTextureSubImage3D                                               = nullptr;
PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC glCompressedTextureSubImage1D                           = nullptr;
PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC glCompressedTextureSubImage2D                           = nullptr;
PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC glCompressedTextureSubImage3D                           = nullptr;
PFNGLCOPYTEXTURESUBIMAGE1DPROC glCopyTextureSubImage1D                                       = nullptr;
PFNGLCOPYTEXTURESUBIMAGE2DPROC glCopyTextureSubImage2D                                       = nullptr;
PFNGLCOPYTEXTURESUBIMAGE3DPROC glCopyTextureSubImage3D                                       = nullptr;
PFNGLTEXTUREPARAMETERFPROC glTextureParameterf                                               = nullptr;
PFNGLTEXTUREPARAMETERFVPROC glTextureParameterfv                                             = nullptr;
PFNGLTEXTUREPARAMETERIPROC glTextureParameteri                                               = nullptr;
PFNGLTEXTUREPARAMETERIIVPROC glTextureParameterIiv                                           = nullptr;
PFNGLTEXTUREPARAMETERIUIVPROC glTextureParameterIuiv                                         = nullptr;
PFNGLTEXTUREPARAMETERIVPROC glTextureParameteriv                                             = nullptr;
PFNGLGENERATETEXTUREMIPMAPPROC glGenerateTextureMipmap                                       = nullptr;
PFNGLBINDTEXTUREUNITPROC glBindTextureUnit                                                   = nullptr;
PFNGLGETTEXTUREIMAGEPROC glGetTextureImage                                                   = nullptr;
PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC glGetCompressedTextureImage                               = nullptr;
PFNGLGETTEXTURELEVELPARAMETERFVPROC glGetTextureLevelParameterfv                             = nullptr;
PFNGLGETTEXTURELEVELPARAMETERIVPROC glGetTextureLevelParameteriv                             = nullptr;
PFNGLGETTEXTUREPARAMETERFVPROC glGetTextureParameterfv                                       = nullptr;
PFNGLGETTEXTUREPARAMETERIIVPROC glGetTextureParameterIiv                                     = nullptr;
PFNGLGETTEXTUREPARAMETERIUIVPROC glGetTextureParameterIuiv                                   = nullptr;
PFNGLGETTEXTUREPARAMETERIVPROC glGetTextureParameteriv                                       = nullptr;
PFNGLCREATEVERTEXARRAYSPROC glCreateVertexArrays                                             = nullptr;
PFNGLDISABLEVERTEXARRAYATTRIBPROC glDisableVertexArrayAttrib                                 = nullptr;
PFNGLENABLEVERTEXARRAYATTRIBPROC glEnableVertexArrayAttrib                                   = nullptr;
PFNGLVERTEXARRAYELEMENTBUFFERPROC glVertexArrayElementBuffer                                 = nullptr;
PFNGLVERTEXARRAYVERTEXBUFFERPROC glVertexArrayVertexBuffer                                   = nullptr;
PFNGLVERTEXARRAYVERTEXBUFFERSPROC glVertexArrayVertexBuffers                                 = nullptr;
PFNGLVERTEXARRAYATTRIBBINDINGPROC glVertexArrayAttribBinding                                 = nullptr;
PFNGLVERTEXARRAYATTRIBFORMATPROC glVertexArrayAttribFormat                                   = nullptr;
PFNGLVERTEXARRAYATTRIBIFORMATPROC glVertexArrayAttribIFormat                                 = nullptr;
PFNGLVERTEXARRAYATTRIBLFORMATPROC glVertexArrayAttribLFormat                                 = nullptr;
PFNGLVERTEXARRAYBINDINGDIVISORPROC glVertexArrayBindingDivisor                               = nullptr;
PFNGLGETVERTEXARRAYIVPROC glGetVertexArrayiv                                                 = nullptr;
PFNGLGETVERTEXARRAYINDEXEDIVPROC glGetVertexArrayIndexediv                                   = nullptr;
PFNGLGETVERTEXARRAYINDEXED64IVPROC glGetVertexArrayIndexed64iv                               = nullptr;
PFNGLCREATESAMPLERSPROC glCreateSamplers                                                     = nullptr;
PFNGLCREATEPROGRAMPIPELINESPROC glCreateProgramPipelines                                     = nullptr;
PFNGLCREATEQUERIESPROC glCreateQueries                                                       = nullptr;
PFNGLGETQUERYBUFFEROBJECTI64VPROC glGetQueryBufferObjecti64v                                 = nullptr;
PFNGLGETQUERYBUFFEROBJECTIVPROC glGetQueryBufferObjectiv                                     = nullptr;
PFNGLGETQUERYBUFFEROBJECTUI64VPROC glGetQueryBufferObjectui64v                               = nullptr;
PFNGLGETQUERYBUFFEROBJECTUIVPROC glGetQueryBufferObjectuiv                                   = nullptr;
PFNGLMEMORYBARRIERBYREGIONPROC glMemoryBarrierByRegion                                       = nullptr;
PFNGLGETTEXTURESUBIMAGEPROC glGetTextureSubImage                                             = nullptr;
PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC glGetCompressedTextureSubImage                         = nullptr;
PFNGLGETGRAPHICSRESETSTATUSPROC glGetGraphicsResetStatus                                     = nullptr;
PFNGLGETNCOMPRESSEDTEXIMAGEPROC glGetnCompressedTexImage                                     = nullptr;
PFNGLGETNTEXIMAGEPROC glGetnTexImage                                                         = nullptr;
PFNGLGETNUNIFORMDVPROC glGetnUniformdv                                                       = nullptr;
PFNGLGETNUNIFORMFVPROC glGetnUniformfv                                                       = nullptr;
PFNGLGETNUNIFORMIVPROC glGetnUniformiv                                                       = nullptr;
PFNGLGETNUNIFORMUIVPROC glGetnUniformuiv                                                     = nullptr;
PFNGLREADNPIXELSPROC glReadnPixels                                                           = nullptr;
PFNGLTEXTUREBARRIERPROC glTextureBarrier                                                     = nullptr;

#pragma endregion

#pragma region GL_VERSION_4_6

PFNGLSPECIALIZESHADERPROC glSpecializeShader                             = nullptr;
PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC glMultiDrawArraysIndirectCount     = nullptr;
PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC glMultiDrawElementsIndirectCount = nullptr;
PFNGLPOLYGONOFFSETCLAMPPROC glPolygonOffsetClamp                         = nullptr;

#pragma endregion

#pragma region GL_ARB_ES3_2_compatibility

PFNGLPRIMITIVEBOUNDINGBOXARBPROC glPrimitiveBoundingBoxARB = nullptr;

#pragma endregion

#pragma region GL_ARB_bindless_texture

PFNGLGETTEXTUREHANDLEARBPROC glGetTextureHandleARB                         = nullptr;
PFNGLGETTEXTURESAMPLERHANDLEARBPROC glGetTextureSamplerHandleARB           = nullptr;
PFNGLMAKETEXTUREHANDLERESIDENTARBPROC glMakeTextureHandleResidentARB       = nullptr;
PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC glMakeTextureHandleNonResidentARB = nullptr;
PFNGLGETIMAGEHANDLEARBPROC glGetImageHandleARB                             = nullptr;
PFNGLMAKEIMAGEHANDLERESIDENTARBPROC glMakeImageHandleResidentARB           = nullptr;
PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC glMakeImageHandleNonResidentARB     = nullptr;
PFNGLUNIFORMHANDLEUI64ARBPROC glUniformHandleui64ARB                       = nullptr;
PFNGLUNIFORMHANDLEUI64VARBPROC glUniformHandleui64vARB                     = nullptr;
PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC glProgramUniformHandleui64ARB         = nullptr;
PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC glProgramUniformHandleui64vARB       = nullptr;
PFNGLISTEXTUREHANDLERESIDENTARBPROC glIsTextureHandleResidentARB           = nullptr;
PFNGLISIMAGEHANDLERESIDENTARBPROC glIsImageHandleResidentARB               = nullptr;
PFNGLVERTEXATTRIBL1UI64ARBPROC glVertexAttribL1ui64ARB                     = nullptr;
PFNGLVERTEXATTRIBL1UI64VARBPROC glVertexAttribL1ui64vARB                   = nullptr;
PFNGLGETVERTEXATTRIBLUI64VARBPROC glGetVertexAttribLui64vARB               = nullptr;

#pragma endregion

#pragma region GL_ARB_cl_event

PFNGLCREATESYNCFROMCLEVENTARBPROC glCreateSyncFromCLeventARB = nullptr;

#pragma endregion

#pragma region GL_ARB_compute_variable_group_size

PFNGLDISPATCHCOMPUTEGROUPSIZEARBPROC glDispatchComputeGroupSizeARB = nullptr;

#pragma endregion

#pragma region GL_ARB_debug_output

PFNGLDEBUGMESSAGECONTROLARBPROC glDebugMessageControlARB   = nullptr;
PFNGLDEBUGMESSAGEINSERTARBPROC glDebugMessageInsertARB     = nullptr;
PFNGLDEBUGMESSAGECALLBACKARBPROC glDebugMessageCallbackARB = nullptr;
PFNGLGETDEBUGMESSAGELOGARBPROC glGetDebugMessageLogARB     = nullptr;

#pragma endregion

#pragma region GL_ARB_draw_buffers_blend

PFNGLBLENDEQUATIONIARBPROC glBlendEquationiARB                 = nullptr;
PFNGLBLENDEQUATIONSEPARATEIARBPROC glBlendEquationSeparateiARB = nullptr;
PFNGLBLENDFUNCIARBPROC glBlendFunciARB                         = nullptr;
PFNGLBLENDFUNCSEPARATEIARBPROC glBlendFuncSeparateiARB         = nullptr;

#pragma endregion

#pragma region GL_ARB_draw_instanced

PFNGLDRAWARRAYSINSTANCEDARBPROC glDrawArraysInstancedARB     = nullptr;
PFNGLDRAWELEMENTSINSTANCEDARBPROC glDrawElementsInstancedARB = nullptr;

#pragma endregion

#pragma region GL_ARB_geometry_shader4

PFNGLPROGRAMPARAMETERIARBPROC glProgramParameteriARB             = nullptr;
PFNGLFRAMEBUFFERTEXTUREARBPROC glFramebufferTextureARB           = nullptr;
PFNGLFRAMEBUFFERTEXTURELAYERARBPROC glFramebufferTextureLayerARB = nullptr;
PFNGLFRAMEBUFFERTEXTUREFACEARBPROC glFramebufferTextureFaceARB   = nullptr;

#pragma endregion

#pragma region GL_ARB_gl_spirv

PFNGLSPECIALIZESHADERARBPROC glSpecializeShaderARB = nullptr;

#pragma endregion

#pragma region GL_ARB_gpu_shader_int64

PFNGLUNIFORM1I64ARBPROC glUniform1i64ARB                   = nullptr;
PFNGLUNIFORM2I64ARBPROC glUniform2i64ARB                   = nullptr;
PFNGLUNIFORM3I64ARBPROC glUniform3i64ARB                   = nullptr;
PFNGLUNIFORM4I64ARBPROC glUniform4i64ARB                   = nullptr;
PFNGLUNIFORM1I64VARBPROC glUniform1i64vARB                 = nullptr;
PFNGLUNIFORM2I64VARBPROC glUniform2i64vARB                 = nullptr;
PFNGLUNIFORM3I64VARBPROC glUniform3i64vARB                 = nullptr;
PFNGLUNIFORM4I64VARBPROC glUniform4i64vARB                 = nullptr;
PFNGLUNIFORM1UI64ARBPROC glUniform1ui64ARB                 = nullptr;
PFNGLUNIFORM2UI64ARBPROC glUniform2ui64ARB                 = nullptr;
PFNGLUNIFORM3UI64ARBPROC glUniform3ui64ARB                 = nullptr;
PFNGLUNIFORM4UI64ARBPROC glUniform4ui64ARB                 = nullptr;
PFNGLUNIFORM1UI64VARBPROC glUniform1ui64vARB               = nullptr;
PFNGLUNIFORM2UI64VARBPROC glUniform2ui64vARB               = nullptr;
PFNGLUNIFORM3UI64VARBPROC glUniform3ui64vARB               = nullptr;
PFNGLUNIFORM4UI64VARBPROC glUniform4ui64vARB               = nullptr;
PFNGLGETUNIFORMI64VARBPROC glGetUniformi64vARB             = nullptr;
PFNGLGETUNIFORMUI64VARBPROC glGetUniformui64vARB           = nullptr;
PFNGLGETNUNIFORMI64VARBPROC glGetnUniformi64vARB           = nullptr;
PFNGLGETNUNIFORMUI64VARBPROC glGetnUniformui64vARB         = nullptr;
PFNGLPROGRAMUNIFORM1I64ARBPROC glProgramUniform1i64ARB     = nullptr;
PFNGLPROGRAMUNIFORM2I64ARBPROC glProgramUniform2i64ARB     = nullptr;
PFNGLPROGRAMUNIFORM3I64ARBPROC glProgramUniform3i64ARB     = nullptr;
PFNGLPROGRAMUNIFORM4I64ARBPROC glProgramUniform4i64ARB     = nullptr;
PFNGLPROGRAMUNIFORM1I64VARBPROC glProgramUniform1i64vARB   = nullptr;
PFNGLPROGRAMUNIFORM2I64VARBPROC glProgramUniform2i64vARB   = nullptr;
PFNGLPROGRAMUNIFORM3I64VARBPROC glProgramUniform3i64vARB   = nullptr;
PFNGLPROGRAMUNIFORM4I64VARBPROC glProgramUniform4i64vARB   = nullptr;
PFNGLPROGRAMUNIFORM1UI64ARBPROC glProgramUniform1ui64ARB   = nullptr;
PFNGLPROGRAMUNIFORM2UI64ARBPROC glProgramUniform2ui64ARB   = nullptr;
PFNGLPROGRAMUNIFORM3UI64ARBPROC glProgramUniform3ui64ARB   = nullptr;
PFNGLPROGRAMUNIFORM4UI64ARBPROC glProgramUniform4ui64ARB   = nullptr;
PFNGLPROGRAMUNIFORM1UI64VARBPROC glProgramUniform1ui64vARB = nullptr;
PFNGLPROGRAMUNIFORM2UI64VARBPROC glProgramUniform2ui64vARB = nullptr;
PFNGLPROGRAMUNIFORM3UI64VARBPROC glProgramUniform3ui64vARB = nullptr;
PFNGLPROGRAMUNIFORM4UI64VARBPROC glProgramUniform4ui64vARB = nullptr;

#pragma endregion

#pragma region GL_ARB_indirect_parameters

PFNGLMULTIDRAWARRAYSINDIRECTCOUNTARBPROC glMultiDrawArraysIndirectCountARB     = nullptr;
PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTARBPROC glMultiDrawElementsIndirectCountARB = nullptr;

#pragma endregion

#pragma region GL_ARB_instanced_arrays

PFNGLVERTEXATTRIBDIVISORARBPROC glVertexAttribDivisorARB = nullptr;

#pragma endregion

#pragma region GL_ARB_parallel_shader_compile

PFNGLMAXSHADERCOMPILERTHREADSARBPROC glMaxShaderCompilerThreadsARB = nullptr;

#pragma endregion

#pragma region GL_ARB_robustness

PFNGLGETGRAPHICSRESETSTATUSARBPROC glGetGraphicsResetStatusARB = nullptr;
PFNGLGETNTEXIMAGEARBPROC glGetnTexImageARB                     = nullptr;
PFNGLREADNPIXELSARBPROC glReadnPixelsARB                       = nullptr;
PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC glGetnCompressedTexImageARB = nullptr;
PFNGLGETNUNIFORMFVARBPROC glGetnUniformfvARB                   = nullptr;
PFNGLGETNUNIFORMIVARBPROC glGetnUniformivARB                   = nullptr;
PFNGLGETNUNIFORMUIVARBPROC glGetnUniformuivARB                 = nullptr;
PFNGLGETNUNIFORMDVARBPROC glGetnUniformdvARB                   = nullptr;

#pragma endregion

#pragma region GL_ARB_sample_locations

PFNGLFRAMEBUFFERSAMPLELOCATIONSFVARBPROC glFramebufferSampleLocationsfvARB           = nullptr;
PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVARBPROC glNamedFramebufferSampleLocationsfvARB = nullptr;
PFNGLEVALUATEDEPTHVALUESARBPROC glEvaluateDepthValuesARB                             = nullptr;

#pragma endregion

#pragma region GL_ARB_sample_shading

PFNGLMINSAMPLESHADINGARBPROC glMinSampleShadingARB = nullptr;

#pragma endregion

#pragma region GL_ARB_shading_language_include

PFNGLNAMEDSTRINGARBPROC glNamedStringARB                   = nullptr;
PFNGLDELETENAMEDSTRINGARBPROC glDeleteNamedStringARB       = nullptr;
PFNGLCOMPILESHADERINCLUDEARBPROC glCompileShaderIncludeARB = nullptr;
PFNGLISNAMEDSTRINGARBPROC glIsNamedStringARB               = nullptr;
PFNGLGETNAMEDSTRINGARBPROC glGetNamedStringARB             = nullptr;
PFNGLGETNAMEDSTRINGIVARBPROC glGetNamedStringivARB         = nullptr;

#pragma endregion

#pragma region GL_ARB_sparse_buffer

PFNGLBUFFERPAGECOMMITMENTARBPROC glBufferPageCommitmentARB           = nullptr;
PFNGLNAMEDBUFFERPAGECOMMITMENTEXTPROC glNamedBufferPageCommitmentEXT = nullptr;
PFNGLNAMEDBUFFERPAGECOMMITMENTARBPROC glNamedBufferPageCommitmentARB = nullptr;

#pragma endregion

#pragma region GL_ARB_sparse_texture

PFNGLTEXPAGECOMMITMENTARBPROC glTexPageCommitmentARB = nullptr;

#pragma endregion

#pragma region GL_ARB_texture_buffer_object

PFNGLTEXBUFFERARBPROC glTexBufferARB = nullptr;

#pragma endregion

#pragma region GL_KHR_blend_equation_advanced

PFNGLBLENDBARRIERKHRPROC glBlendBarrierKHR = nullptr;

#pragma endregion

#pragma region GL_KHR_parallel_shader_compile

PFNGLMAXSHADERCOMPILERTHREADSKHRPROC glMaxShaderCompilerThreadsKHR = nullptr;

#pragma endregion

#pragma region GL_AMD_framebuffer_multisample_advanced

PFNGLRENDERBUFFERSTORAGEMULTISAMPLEADVANCEDAMDPROC glRenderbufferStorageMultisampleAdvancedAMD           = nullptr;
PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEADVANCEDAMDPROC glNamedRenderbufferStorageMultisampleAdvancedAMD = nullptr;

#pragma endregion

#pragma region GL_AMD_performance_monitor

PFNGLGETPERFMONITORGROUPSAMDPROC glGetPerfMonitorGroupsAMD               = nullptr;
PFNGLGETPERFMONITORCOUNTERSAMDPROC glGetPerfMonitorCountersAMD           = nullptr;
PFNGLGETPERFMONITORGROUPSTRINGAMDPROC glGetPerfMonitorGroupStringAMD     = nullptr;
PFNGLGETPERFMONITORCOUNTERSTRINGAMDPROC glGetPerfMonitorCounterStringAMD = nullptr;
PFNGLGETPERFMONITORCOUNTERINFOAMDPROC glGetPerfMonitorCounterInfoAMD     = nullptr;
PFNGLGENPERFMONITORSAMDPROC glGenPerfMonitorsAMD                         = nullptr;
PFNGLDELETEPERFMONITORSAMDPROC glDeletePerfMonitorsAMD                   = nullptr;
PFNGLSELECTPERFMONITORCOUNTERSAMDPROC glSelectPerfMonitorCountersAMD     = nullptr;
PFNGLBEGINPERFMONITORAMDPROC glBeginPerfMonitorAMD                       = nullptr;
PFNGLENDPERFMONITORAMDPROC glEndPerfMonitorAMD                           = nullptr;
PFNGLGETPERFMONITORCOUNTERDATAAMDPROC glGetPerfMonitorCounterDataAMD     = nullptr;

#pragma endregion

#pragma region GL_EXT_EGL_image_storage

PFNGLEGLIMAGETARGETTEXSTORAGEEXTPROC glEGLImageTargetTexStorageEXT         = nullptr;
PFNGLEGLIMAGETARGETTEXTURESTORAGEEXTPROC glEGLImageTargetTextureStorageEXT = nullptr;

#pragma endregion

#pragma region GL_EXT_debug_label

PFNGLLABELOBJECTEXTPROC glLabelObjectEXT       = nullptr;
PFNGLGETOBJECTLABELEXTPROC glGetObjectLabelEXT = nullptr;

#pragma endregion

#pragma region GL_EXT_debug_marker

PFNGLINSERTEVENTMARKEREXTPROC glInsertEventMarkerEXT = nullptr;
PFNGLPUSHGROUPMARKEREXTPROC glPushGroupMarkerEXT     = nullptr;
PFNGLPOPGROUPMARKEREXTPROC glPopGroupMarkerEXT       = nullptr;

#pragma endregion

#pragma region GL_EXT_direct_state_access

PFNGLMATRIXLOADFEXTPROC glMatrixLoadfEXT                                                                 = nullptr;
PFNGLMATRIXLOADDEXTPROC glMatrixLoaddEXT                                                                 = nullptr;
PFNGLMATRIXMULTFEXTPROC glMatrixMultfEXT                                                                 = nullptr;
PFNGLMATRIXMULTDEXTPROC glMatrixMultdEXT                                                                 = nullptr;
PFNGLMATRIXLOADIDENTITYEXTPROC glMatrixLoadIdentityEXT                                                   = nullptr;
PFNGLMATRIXROTATEFEXTPROC glMatrixRotatefEXT                                                             = nullptr;
PFNGLMATRIXROTATEDEXTPROC glMatrixRotatedEXT                                                             = nullptr;
PFNGLMATRIXSCALEFEXTPROC glMatrixScalefEXT                                                               = nullptr;
PFNGLMATRIXSCALEDEXTPROC glMatrixScaledEXT                                                               = nullptr;
PFNGLMATRIXTRANSLATEFEXTPROC glMatrixTranslatefEXT                                                       = nullptr;
PFNGLMATRIXTRANSLATEDEXTPROC glMatrixTranslatedEXT                                                       = nullptr;
PFNGLMATRIXFRUSTUMEXTPROC glMatrixFrustumEXT                                                             = nullptr;
PFNGLMATRIXORTHOEXTPROC glMatrixOrthoEXT                                                                 = nullptr;
PFNGLMATRIXPOPEXTPROC glMatrixPopEXT                                                                     = nullptr;
PFNGLMATRIXPUSHEXTPROC glMatrixPushEXT                                                                   = nullptr;
PFNGLCLIENTATTRIBDEFAULTEXTPROC glClientAttribDefaultEXT                                                 = nullptr;
PFNGLPUSHCLIENTATTRIBDEFAULTEXTPROC glPushClientAttribDefaultEXT                                         = nullptr;
PFNGLTEXTUREPARAMETERFEXTPROC glTextureParameterfEXT                                                     = nullptr;
PFNGLTEXTUREPARAMETERFVEXTPROC glTextureParameterfvEXT                                                   = nullptr;
PFNGLTEXTUREPARAMETERIEXTPROC glTextureParameteriEXT                                                     = nullptr;
PFNGLTEXTUREPARAMETERIVEXTPROC glTextureParameterivEXT                                                   = nullptr;
PFNGLTEXTUREIMAGE1DEXTPROC glTextureImage1DEXT                                                           = nullptr;
PFNGLTEXTUREIMAGE2DEXTPROC glTextureImage2DEXT                                                           = nullptr;
PFNGLTEXTURESUBIMAGE1DEXTPROC glTextureSubImage1DEXT                                                     = nullptr;
PFNGLTEXTURESUBIMAGE2DEXTPROC glTextureSubImage2DEXT                                                     = nullptr;
PFNGLCOPYTEXTUREIMAGE1DEXTPROC glCopyTextureImage1DEXT                                                   = nullptr;
PFNGLCOPYTEXTUREIMAGE2DEXTPROC glCopyTextureImage2DEXT                                                   = nullptr;
PFNGLCOPYTEXTURESUBIMAGE1DEXTPROC glCopyTextureSubImage1DEXT                                             = nullptr;
PFNGLCOPYTEXTURESUBIMAGE2DEXTPROC glCopyTextureSubImage2DEXT                                             = nullptr;
PFNGLGETTEXTUREIMAGEEXTPROC glGetTextureImageEXT                                                         = nullptr;
PFNGLGETTEXTUREPARAMETERFVEXTPROC glGetTextureParameterfvEXT                                             = nullptr;
PFNGLGETTEXTUREPARAMETERIVEXTPROC glGetTextureParameterivEXT                                             = nullptr;
PFNGLGETTEXTURELEVELPARAMETERFVEXTPROC glGetTextureLevelParameterfvEXT                                   = nullptr;
PFNGLGETTEXTURELEVELPARAMETERIVEXTPROC glGetTextureLevelParameterivEXT                                   = nullptr;
PFNGLTEXTUREIMAGE3DEXTPROC glTextureImage3DEXT                                                           = nullptr;
PFNGLTEXTURESUBIMAGE3DEXTPROC glTextureSubImage3DEXT                                                     = nullptr;
PFNGLCOPYTEXTURESUBIMAGE3DEXTPROC glCopyTextureSubImage3DEXT                                             = nullptr;
PFNGLBINDMULTITEXTUREEXTPROC glBindMultiTextureEXT                                                       = nullptr;
PFNGLMULTITEXCOORDPOINTEREXTPROC glMultiTexCoordPointerEXT                                               = nullptr;
PFNGLMULTITEXENVFEXTPROC glMultiTexEnvfEXT                                                               = nullptr;
PFNGLMULTITEXENVFVEXTPROC glMultiTexEnvfvEXT                                                             = nullptr;
PFNGLMULTITEXENVIEXTPROC glMultiTexEnviEXT                                                               = nullptr;
PFNGLMULTITEXENVIVEXTPROC glMultiTexEnvivEXT                                                             = nullptr;
PFNGLMULTITEXGENDEXTPROC glMultiTexGendEXT                                                               = nullptr;
PFNGLMULTITEXGENDVEXTPROC glMultiTexGendvEXT                                                             = nullptr;
PFNGLMULTITEXGENFEXTPROC glMultiTexGenfEXT                                                               = nullptr;
PFNGLMULTITEXGENFVEXTPROC glMultiTexGenfvEXT                                                             = nullptr;
PFNGLMULTITEXGENIEXTPROC glMultiTexGeniEXT                                                               = nullptr;
PFNGLMULTITEXGENIVEXTPROC glMultiTexGenivEXT                                                             = nullptr;
PFNGLGETMULTITEXENVFVEXTPROC glGetMultiTexEnvfvEXT                                                       = nullptr;
PFNGLGETMULTITEXENVIVEXTPROC glGetMultiTexEnvivEXT                                                       = nullptr;
PFNGLGETMULTITEXGENDVEXTPROC glGetMultiTexGendvEXT                                                       = nullptr;
PFNGLGETMULTITEXGENFVEXTPROC glGetMultiTexGenfvEXT                                                       = nullptr;
PFNGLGETMULTITEXGENIVEXTPROC glGetMultiTexGenivEXT                                                       = nullptr;
PFNGLMULTITEXPARAMETERIEXTPROC glMultiTexParameteriEXT                                                   = nullptr;
PFNGLMULTITEXPARAMETERIVEXTPROC glMultiTexParameterivEXT                                                 = nullptr;
PFNGLMULTITEXPARAMETERFEXTPROC glMultiTexParameterfEXT                                                   = nullptr;
PFNGLMULTITEXPARAMETERFVEXTPROC glMultiTexParameterfvEXT                                                 = nullptr;
PFNGLMULTITEXIMAGE1DEXTPROC glMultiTexImage1DEXT                                                         = nullptr;
PFNGLMULTITEXIMAGE2DEXTPROC glMultiTexImage2DEXT                                                         = nullptr;
PFNGLMULTITEXSUBIMAGE1DEXTPROC glMultiTexSubImage1DEXT                                                   = nullptr;
PFNGLMULTITEXSUBIMAGE2DEXTPROC glMultiTexSubImage2DEXT                                                   = nullptr;
PFNGLCOPYMULTITEXIMAGE1DEXTPROC glCopyMultiTexImage1DEXT                                                 = nullptr;
PFNGLCOPYMULTITEXIMAGE2DEXTPROC glCopyMultiTexImage2DEXT                                                 = nullptr;
PFNGLCOPYMULTITEXSUBIMAGE1DEXTPROC glCopyMultiTexSubImage1DEXT                                           = nullptr;
PFNGLCOPYMULTITEXSUBIMAGE2DEXTPROC glCopyMultiTexSubImage2DEXT                                           = nullptr;
PFNGLGETMULTITEXIMAGEEXTPROC glGetMultiTexImageEXT                                                       = nullptr;
PFNGLGETMULTITEXPARAMETERFVEXTPROC glGetMultiTexParameterfvEXT                                           = nullptr;
PFNGLGETMULTITEXPARAMETERIVEXTPROC glGetMultiTexParameterivEXT                                           = nullptr;
PFNGLGETMULTITEXLEVELPARAMETERFVEXTPROC glGetMultiTexLevelParameterfvEXT                                 = nullptr;
PFNGLGETMULTITEXLEVELPARAMETERIVEXTPROC glGetMultiTexLevelParameterivEXT                                 = nullptr;
PFNGLMULTITEXIMAGE3DEXTPROC glMultiTexImage3DEXT                                                         = nullptr;
PFNGLMULTITEXSUBIMAGE3DEXTPROC glMultiTexSubImage3DEXT                                                   = nullptr;
PFNGLCOPYMULTITEXSUBIMAGE3DEXTPROC glCopyMultiTexSubImage3DEXT                                           = nullptr;
PFNGLENABLECLIENTSTATEINDEXEDEXTPROC glEnableClientStateIndexedEXT                                       = nullptr;
PFNGLDISABLECLIENTSTATEINDEXEDEXTPROC glDisableClientStateIndexedEXT                                     = nullptr;
PFNGLGETFLOATINDEXEDVEXTPROC glGetFloatIndexedvEXT                                                       = nullptr;
PFNGLGETDOUBLEINDEXEDVEXTPROC glGetDoubleIndexedvEXT                                                     = nullptr;
PFNGLGETPOINTERINDEXEDVEXTPROC glGetPointerIndexedvEXT                                                   = nullptr;
PFNGLENABLEINDEXEDEXTPROC glEnableIndexedEXT                                                             = nullptr;
PFNGLDISABLEINDEXEDEXTPROC glDisableIndexedEXT                                                           = nullptr;
PFNGLISENABLEDINDEXEDEXTPROC glIsEnabledIndexedEXT                                                       = nullptr;
PFNGLGETINTEGERINDEXEDVEXTPROC glGetIntegerIndexedvEXT                                                   = nullptr;
PFNGLGETBOOLEANINDEXEDVEXTPROC glGetBooleanIndexedvEXT                                                   = nullptr;
PFNGLCOMPRESSEDTEXTUREIMAGE3DEXTPROC glCompressedTextureImage3DEXT                                       = nullptr;
PFNGLCOMPRESSEDTEXTUREIMAGE2DEXTPROC glCompressedTextureImage2DEXT                                       = nullptr;
PFNGLCOMPRESSEDTEXTUREIMAGE1DEXTPROC glCompressedTextureImage1DEXT                                       = nullptr;
PFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXTPROC glCompressedTextureSubImage3DEXT                                 = nullptr;
PFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXTPROC glCompressedTextureSubImage2DEXT                                 = nullptr;
PFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXTPROC glCompressedTextureSubImage1DEXT                                 = nullptr;
PFNGLGETCOMPRESSEDTEXTUREIMAGEEXTPROC glGetCompressedTextureImageEXT                                     = nullptr;
PFNGLCOMPRESSEDMULTITEXIMAGE3DEXTPROC glCompressedMultiTexImage3DEXT                                     = nullptr;
PFNGLCOMPRESSEDMULTITEXIMAGE2DEXTPROC glCompressedMultiTexImage2DEXT                                     = nullptr;
PFNGLCOMPRESSEDMULTITEXIMAGE1DEXTPROC glCompressedMultiTexImage1DEXT                                     = nullptr;
PFNGLCOMPRESSEDMULTITEXSUBIMAGE3DEXTPROC glCompressedMultiTexSubImage3DEXT                               = nullptr;
PFNGLCOMPRESSEDMULTITEXSUBIMAGE2DEXTPROC glCompressedMultiTexSubImage2DEXT                               = nullptr;
PFNGLCOMPRESSEDMULTITEXSUBIMAGE1DEXTPROC glCompressedMultiTexSubImage1DEXT                               = nullptr;
PFNGLGETCOMPRESSEDMULTITEXIMAGEEXTPROC glGetCompressedMultiTexImageEXT                                   = nullptr;
PFNGLMATRIXLOADTRANSPOSEFEXTPROC glMatrixLoadTransposefEXT                                               = nullptr;
PFNGLMATRIXLOADTRANSPOSEDEXTPROC glMatrixLoadTransposedEXT                                               = nullptr;
PFNGLMATRIXMULTTRANSPOSEFEXTPROC glMatrixMultTransposefEXT                                               = nullptr;
PFNGLMATRIXMULTTRANSPOSEDEXTPROC glMatrixMultTransposedEXT                                               = nullptr;
PFNGLNAMEDBUFFERDATAEXTPROC glNamedBufferDataEXT                                                         = nullptr;
PFNGLNAMEDBUFFERSUBDATAEXTPROC glNamedBufferSubDataEXT                                                   = nullptr;
PFNGLMAPNAMEDBUFFEREXTPROC glMapNamedBufferEXT                                                           = nullptr;
PFNGLUNMAPNAMEDBUFFEREXTPROC glUnmapNamedBufferEXT                                                       = nullptr;
PFNGLGETNAMEDBUFFERPARAMETERIVEXTPROC glGetNamedBufferParameterivEXT                                     = nullptr;
PFNGLGETNAMEDBUFFERPOINTERVEXTPROC glGetNamedBufferPointervEXT                                           = nullptr;
PFNGLGETNAMEDBUFFERSUBDATAEXTPROC glGetNamedBufferSubDataEXT                                             = nullptr;
PFNGLPROGRAMUNIFORM1FEXTPROC glProgramUniform1fEXT                                                       = nullptr;
PFNGLPROGRAMUNIFORM2FEXTPROC glProgramUniform2fEXT                                                       = nullptr;
PFNGLPROGRAMUNIFORM3FEXTPROC glProgramUniform3fEXT                                                       = nullptr;
PFNGLPROGRAMUNIFORM4FEXTPROC glProgramUniform4fEXT                                                       = nullptr;
PFNGLPROGRAMUNIFORM1IEXTPROC glProgramUniform1iEXT                                                       = nullptr;
PFNGLPROGRAMUNIFORM2IEXTPROC glProgramUniform2iEXT                                                       = nullptr;
PFNGLPROGRAMUNIFORM3IEXTPROC glProgramUniform3iEXT                                                       = nullptr;
PFNGLPROGRAMUNIFORM4IEXTPROC glProgramUniform4iEXT                                                       = nullptr;
PFNGLPROGRAMUNIFORM1FVEXTPROC glProgramUniform1fvEXT                                                     = nullptr;
PFNGLPROGRAMUNIFORM2FVEXTPROC glProgramUniform2fvEXT                                                     = nullptr;
PFNGLPROGRAMUNIFORM3FVEXTPROC glProgramUniform3fvEXT                                                     = nullptr;
PFNGLPROGRAMUNIFORM4FVEXTPROC glProgramUniform4fvEXT                                                     = nullptr;
PFNGLPROGRAMUNIFORM1IVEXTPROC glProgramUniform1ivEXT                                                     = nullptr;
PFNGLPROGRAMUNIFORM2IVEXTPROC glProgramUniform2ivEXT                                                     = nullptr;
PFNGLPROGRAMUNIFORM3IVEXTPROC glProgramUniform3ivEXT                                                     = nullptr;
PFNGLPROGRAMUNIFORM4IVEXTPROC glProgramUniform4ivEXT                                                     = nullptr;
PFNGLPROGRAMUNIFORMMATRIX2FVEXTPROC glProgramUniformMatrix2fvEXT                                         = nullptr;
PFNGLPROGRAMUNIFORMMATRIX3FVEXTPROC glProgramUniformMatrix3fvEXT                                         = nullptr;
PFNGLPROGRAMUNIFORMMATRIX4FVEXTPROC glProgramUniformMatrix4fvEXT                                         = nullptr;
PFNGLPROGRAMUNIFORMMATRIX2X3FVEXTPROC glProgramUniformMatrix2x3fvEXT                                     = nullptr;
PFNGLPROGRAMUNIFORMMATRIX3X2FVEXTPROC glProgramUniformMatrix3x2fvEXT                                     = nullptr;
PFNGLPROGRAMUNIFORMMATRIX2X4FVEXTPROC glProgramUniformMatrix2x4fvEXT                                     = nullptr;
PFNGLPROGRAMUNIFORMMATRIX4X2FVEXTPROC glProgramUniformMatrix4x2fvEXT                                     = nullptr;
PFNGLPROGRAMUNIFORMMATRIX3X4FVEXTPROC glProgramUniformMatrix3x4fvEXT                                     = nullptr;
PFNGLPROGRAMUNIFORMMATRIX4X3FVEXTPROC glProgramUniformMatrix4x3fvEXT                                     = nullptr;
PFNGLTEXTUREBUFFEREXTPROC glTextureBufferEXT                                                             = nullptr;
PFNGLMULTITEXBUFFEREXTPROC glMultiTexBufferEXT                                                           = nullptr;
PFNGLTEXTUREPARAMETERIIVEXTPROC glTextureParameterIivEXT                                                 = nullptr;
PFNGLTEXTUREPARAMETERIUIVEXTPROC glTextureParameterIuivEXT                                               = nullptr;
PFNGLGETTEXTUREPARAMETERIIVEXTPROC glGetTextureParameterIivEXT                                           = nullptr;
PFNGLGETTEXTUREPARAMETERIUIVEXTPROC glGetTextureParameterIuivEXT                                         = nullptr;
PFNGLMULTITEXPARAMETERIIVEXTPROC glMultiTexParameterIivEXT                                               = nullptr;
PFNGLMULTITEXPARAMETERIUIVEXTPROC glMultiTexParameterIuivEXT                                             = nullptr;
PFNGLGETMULTITEXPARAMETERIIVEXTPROC glGetMultiTexParameterIivEXT                                         = nullptr;
PFNGLGETMULTITEXPARAMETERIUIVEXTPROC glGetMultiTexParameterIuivEXT                                       = nullptr;
PFNGLPROGRAMUNIFORM1UIEXTPROC glProgramUniform1uiEXT                                                     = nullptr;
PFNGLPROGRAMUNIFORM2UIEXTPROC glProgramUniform2uiEXT                                                     = nullptr;
PFNGLPROGRAMUNIFORM3UIEXTPROC glProgramUniform3uiEXT                                                     = nullptr;
PFNGLPROGRAMUNIFORM4UIEXTPROC glProgramUniform4uiEXT                                                     = nullptr;
PFNGLPROGRAMUNIFORM1UIVEXTPROC glProgramUniform1uivEXT                                                   = nullptr;
PFNGLPROGRAMUNIFORM2UIVEXTPROC glProgramUniform2uivEXT                                                   = nullptr;
PFNGLPROGRAMUNIFORM3UIVEXTPROC glProgramUniform3uivEXT                                                   = nullptr;
PFNGLPROGRAMUNIFORM4UIVEXTPROC glProgramUniform4uivEXT                                                   = nullptr;
PFNGLNAMEDPROGRAMLOCALPARAMETERS4FVEXTPROC glNamedProgramLocalParameters4fvEXT                           = nullptr;
PFNGLNAMEDPROGRAMLOCALPARAMETERI4IEXTPROC glNamedProgramLocalParameterI4iEXT                             = nullptr;
PFNGLNAMEDPROGRAMLOCALPARAMETERI4IVEXTPROC glNamedProgramLocalParameterI4ivEXT                           = nullptr;
PFNGLNAMEDPROGRAMLOCALPARAMETERSI4IVEXTPROC glNamedProgramLocalParametersI4ivEXT                         = nullptr;
PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIEXTPROC glNamedProgramLocalParameterI4uiEXT                           = nullptr;
PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIVEXTPROC glNamedProgramLocalParameterI4uivEXT                         = nullptr;
PFNGLNAMEDPROGRAMLOCALPARAMETERSI4UIVEXTPROC glNamedProgramLocalParametersI4uivEXT                       = nullptr;
PFNGLGETNAMEDPROGRAMLOCALPARAMETERIIVEXTPROC glGetNamedProgramLocalParameterIivEXT                       = nullptr;
PFNGLGETNAMEDPROGRAMLOCALPARAMETERIUIVEXTPROC glGetNamedProgramLocalParameterIuivEXT                     = nullptr;
PFNGLENABLECLIENTSTATEIEXTPROC glEnableClientStateiEXT                                                   = nullptr;
PFNGLDISABLECLIENTSTATEIEXTPROC glDisableClientStateiEXT                                                 = nullptr;
PFNGLGETFLOATI_VEXTPROC glGetFloati_vEXT                                                                 = nullptr;
PFNGLGETDOUBLEI_VEXTPROC glGetDoublei_vEXT                                                               = nullptr;
PFNGLGETPOINTERI_VEXTPROC glGetPointeri_vEXT                                                             = nullptr;
PFNGLNAMEDPROGRAMSTRINGEXTPROC glNamedProgramStringEXT                                                   = nullptr;
PFNGLNAMEDPROGRAMLOCALPARAMETER4DEXTPROC glNamedProgramLocalParameter4dEXT                               = nullptr;
PFNGLNAMEDPROGRAMLOCALPARAMETER4DVEXTPROC glNamedProgramLocalParameter4dvEXT                             = nullptr;
PFNGLNAMEDPROGRAMLOCALPARAMETER4FEXTPROC glNamedProgramLocalParameter4fEXT                               = nullptr;
PFNGLNAMEDPROGRAMLOCALPARAMETER4FVEXTPROC glNamedProgramLocalParameter4fvEXT                             = nullptr;
PFNGLGETNAMEDPROGRAMLOCALPARAMETERDVEXTPROC glGetNamedProgramLocalParameterdvEXT                         = nullptr;
PFNGLGETNAMEDPROGRAMLOCALPARAMETERFVEXTPROC glGetNamedProgramLocalParameterfvEXT                         = nullptr;
PFNGLGETNAMEDPROGRAMIVEXTPROC glGetNamedProgramivEXT                                                     = nullptr;
PFNGLGETNAMEDPROGRAMSTRINGEXTPROC glGetNamedProgramStringEXT                                             = nullptr;
PFNGLNAMEDRENDERBUFFERSTORAGEEXTPROC glNamedRenderbufferStorageEXT                                       = nullptr;
PFNGLGETNAMEDRENDERBUFFERPARAMETERIVEXTPROC glGetNamedRenderbufferParameterivEXT                         = nullptr;
PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC glNamedRenderbufferStorageMultisampleEXT                 = nullptr;
PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXTPROC glNamedRenderbufferStorageMultisampleCoverageEXT = nullptr;
PFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXTPROC glCheckNamedFramebufferStatusEXT                                 = nullptr;
PFNGLNAMEDFRAMEBUFFERTEXTURE1DEXTPROC glNamedFramebufferTexture1DEXT                                     = nullptr;
PFNGLNAMEDFRAMEBUFFERTEXTURE2DEXTPROC glNamedFramebufferTexture2DEXT                                     = nullptr;
PFNGLNAMEDFRAMEBUFFERTEXTURE3DEXTPROC glNamedFramebufferTexture3DEXT                                     = nullptr;
PFNGLNAMEDFRAMEBUFFERRENDERBUFFEREXTPROC glNamedFramebufferRenderbufferEXT                               = nullptr;
PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC glGetNamedFramebufferAttachmentParameterivEXT       = nullptr;
PFNGLGENERATETEXTUREMIPMAPEXTPROC glGenerateTextureMipmapEXT                                             = nullptr;
PFNGLGENERATEMULTITEXMIPMAPEXTPROC glGenerateMultiTexMipmapEXT                                           = nullptr;
PFNGLFRAMEBUFFERDRAWBUFFEREXTPROC glFramebufferDrawBufferEXT                                             = nullptr;
PFNGLFRAMEBUFFERDRAWBUFFERSEXTPROC glFramebufferDrawBuffersEXT                                           = nullptr;
PFNGLFRAMEBUFFERREADBUFFEREXTPROC glFramebufferReadBufferEXT                                             = nullptr;
PFNGLGETFRAMEBUFFERPARAMETERIVEXTPROC glGetFramebufferParameterivEXT                                     = nullptr;
PFNGLNAMEDCOPYBUFFERSUBDATAEXTPROC glNamedCopyBufferSubDataEXT                                           = nullptr;
PFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC glNamedFramebufferTextureEXT                                         = nullptr;
PFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXTPROC glNamedFramebufferTextureLayerEXT                               = nullptr;
PFNGLNAMEDFRAMEBUFFERTEXTUREFACEEXTPROC glNamedFramebufferTextureFaceEXT                                 = nullptr;
PFNGLTEXTURERENDERBUFFEREXTPROC glTextureRenderbufferEXT                                                 = nullptr;
PFNGLMULTITEXRENDERBUFFEREXTPROC glMultiTexRenderbufferEXT                                               = nullptr;
PFNGLVERTEXARRAYVERTEXOFFSETEXTPROC glVertexArrayVertexOffsetEXT                                         = nullptr;
PFNGLVERTEXARRAYCOLOROFFSETEXTPROC glVertexArrayColorOffsetEXT                                           = nullptr;
PFNGLVERTEXARRAYEDGEFLAGOFFSETEXTPROC glVertexArrayEdgeFlagOffsetEXT                                     = nullptr;
PFNGLVERTEXARRAYINDEXOFFSETEXTPROC glVertexArrayIndexOffsetEXT                                           = nullptr;
PFNGLVERTEXARRAYNORMALOFFSETEXTPROC glVertexArrayNormalOffsetEXT                                         = nullptr;
PFNGLVERTEXARRAYTEXCOORDOFFSETEXTPROC glVertexArrayTexCoordOffsetEXT                                     = nullptr;
PFNGLVERTEXARRAYMULTITEXCOORDOFFSETEXTPROC glVertexArrayMultiTexCoordOffsetEXT                           = nullptr;
PFNGLVERTEXARRAYFOGCOORDOFFSETEXTPROC glVertexArrayFogCoordOffsetEXT                                     = nullptr;
PFNGLVERTEXARRAYSECONDARYCOLOROFFSETEXTPROC glVertexArraySecondaryColorOffsetEXT                         = nullptr;
PFNGLVERTEXARRAYVERTEXATTRIBOFFSETEXTPROC glVertexArrayVertexAttribOffsetEXT                             = nullptr;
PFNGLVERTEXARRAYVERTEXATTRIBIOFFSETEXTPROC glVertexArrayVertexAttribIOffsetEXT                           = nullptr;
PFNGLENABLEVERTEXARRAYEXTPROC glEnableVertexArrayEXT                                                     = nullptr;
PFNGLDISABLEVERTEXARRAYEXTPROC glDisableVertexArrayEXT                                                   = nullptr;
PFNGLENABLEVERTEXARRAYATTRIBEXTPROC glEnableVertexArrayAttribEXT                                         = nullptr;
PFNGLDISABLEVERTEXARRAYATTRIBEXTPROC glDisableVertexArrayAttribEXT                                       = nullptr;
PFNGLGETVERTEXARRAYINTEGERVEXTPROC glGetVertexArrayIntegervEXT                                           = nullptr;
PFNGLGETVERTEXARRAYPOINTERVEXTPROC glGetVertexArrayPointervEXT                                           = nullptr;
PFNGLGETVERTEXARRAYINTEGERI_VEXTPROC glGetVertexArrayIntegeri_vEXT                                       = nullptr;
PFNGLGETVERTEXARRAYPOINTERI_VEXTPROC glGetVertexArrayPointeri_vEXT                                       = nullptr;
PFNGLMAPNAMEDBUFFERRANGEEXTPROC glMapNamedBufferRangeEXT                                                 = nullptr;
PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEEXTPROC glFlushMappedNamedBufferRangeEXT                                 = nullptr;
PFNGLNAMEDBUFFERSTORAGEEXTPROC glNamedBufferStorageEXT                                                   = nullptr;
PFNGLCLEARNAMEDBUFFERDATAEXTPROC glClearNamedBufferDataEXT                                               = nullptr;
PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC glClearNamedBufferSubDataEXT                                         = nullptr;
PFNGLNAMEDFRAMEBUFFERPARAMETERIEXTPROC glNamedFramebufferParameteriEXT                                   = nullptr;
PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXTPROC glGetNamedFramebufferParameterivEXT                           = nullptr;
PFNGLPROGRAMUNIFORM1DEXTPROC glProgramUniform1dEXT                                                       = nullptr;
PFNGLPROGRAMUNIFORM2DEXTPROC glProgramUniform2dEXT                                                       = nullptr;
PFNGLPROGRAMUNIFORM3DEXTPROC glProgramUniform3dEXT                                                       = nullptr;
PFNGLPROGRAMUNIFORM4DEXTPROC glProgramUniform4dEXT                                                       = nullptr;
PFNGLPROGRAMUNIFORM1DVEXTPROC glProgramUniform1dvEXT                                                     = nullptr;
PFNGLPROGRAMUNIFORM2DVEXTPROC glProgramUniform2dvEXT                                                     = nullptr;
PFNGLPROGRAMUNIFORM3DVEXTPROC glProgramUniform3dvEXT                                                     = nullptr;
PFNGLPROGRAMUNIFORM4DVEXTPROC glProgramUniform4dvEXT                                                     = nullptr;
PFNGLPROGRAMUNIFORMMATRIX2DVEXTPROC glProgramUniformMatrix2dvEXT                                         = nullptr;
PFNGLPROGRAMUNIFORMMATRIX3DVEXTPROC glProgramUniformMatrix3dvEXT                                         = nullptr;
PFNGLPROGRAMUNIFORMMATRIX4DVEXTPROC glProgramUniformMatrix4dvEXT                                         = nullptr;
PFNGLPROGRAMUNIFORMMATRIX2X3DVEXTPROC glProgramUniformMatrix2x3dvEXT                                     = nullptr;
PFNGLPROGRAMUNIFORMMATRIX2X4DVEXTPROC glProgramUniformMatrix2x4dvEXT                                     = nullptr;
PFNGLPROGRAMUNIFORMMATRIX3X2DVEXTPROC glProgramUniformMatrix3x2dvEXT                                     = nullptr;
PFNGLPROGRAMUNIFORMMATRIX3X4DVEXTPROC glProgramUniformMatrix3x4dvEXT                                     = nullptr;
PFNGLPROGRAMUNIFORMMATRIX4X2DVEXTPROC glProgramUniformMatrix4x2dvEXT                                     = nullptr;
PFNGLPROGRAMUNIFORMMATRIX4X3DVEXTPROC glProgramUniformMatrix4x3dvEXT                                     = nullptr;
PFNGLTEXTUREBUFFERRANGEEXTPROC glTextureBufferRangeEXT                                                   = nullptr;
PFNGLTEXTURESTORAGE1DEXTPROC glTextureStorage1DEXT                                                       = nullptr;
PFNGLTEXTURESTORAGE2DEXTPROC glTextureStorage2DEXT                                                       = nullptr;
PFNGLTEXTURESTORAGE3DEXTPROC glTextureStorage3DEXT                                                       = nullptr;
PFNGLTEXTURESTORAGE2DMULTISAMPLEEXTPROC glTextureStorage2DMultisampleEXT                                 = nullptr;
PFNGLTEXTURESTORAGE3DMULTISAMPLEEXTPROC glTextureStorage3DMultisampleEXT                                 = nullptr;
PFNGLVERTEXARRAYBINDVERTEXBUFFEREXTPROC glVertexArrayBindVertexBufferEXT                                 = nullptr;
PFNGLVERTEXARRAYVERTEXATTRIBFORMATEXTPROC glVertexArrayVertexAttribFormatEXT                             = nullptr;
PFNGLVERTEXARRAYVERTEXATTRIBIFORMATEXTPROC glVertexArrayVertexAttribIFormatEXT                           = nullptr;
PFNGLVERTEXARRAYVERTEXATTRIBLFORMATEXTPROC glVertexArrayVertexAttribLFormatEXT                           = nullptr;
PFNGLVERTEXARRAYVERTEXATTRIBBINDINGEXTPROC glVertexArrayVertexAttribBindingEXT                           = nullptr;
PFNGLVERTEXARRAYVERTEXBINDINGDIVISOREXTPROC glVertexArrayVertexBindingDivisorEXT                         = nullptr;
PFNGLVERTEXARRAYVERTEXATTRIBLOFFSETEXTPROC glVertexArrayVertexAttribLOffsetEXT                           = nullptr;
PFNGLTEXTUREPAGECOMMITMENTEXTPROC glTexturePageCommitmentEXT                                             = nullptr;
PFNGLVERTEXARRAYVERTEXATTRIBDIVISOREXTPROC glVertexArrayVertexAttribDivisorEXT                           = nullptr;

#pragma endregion

#pragma region GL_EXT_draw_instanced

PFNGLDRAWARRAYSINSTANCEDEXTPROC glDrawArraysInstancedEXT     = nullptr;
PFNGLDRAWELEMENTSINSTANCEDEXTPROC glDrawElementsInstancedEXT = nullptr;

#pragma endregion

#pragma region GL_EXT_polygon_offset_clamp

PFNGLPOLYGONOFFSETCLAMPEXTPROC glPolygonOffsetClampEXT = nullptr;

#pragma endregion

#pragma region GL_EXT_raster_multisample

PFNGLRASTERSAMPLESEXTPROC glRasterSamplesEXT = nullptr;

#pragma endregion

#pragma region GL_EXT_separate_shader_objects

PFNGLUSESHADERPROGRAMEXTPROC glUseShaderProgramEXT       = nullptr;
PFNGLACTIVEPROGRAMEXTPROC glActiveProgramEXT             = nullptr;
PFNGLCREATESHADERPROGRAMEXTPROC glCreateShaderProgramEXT = nullptr;

#pragma endregion

#pragma region GL_EXT_shader_framebuffer_fetch_non_coherent

PFNGLFRAMEBUFFERFETCHBARRIEREXTPROC glFramebufferFetchBarrierEXT = nullptr;

#pragma endregion

#pragma region GL_EXT_window_rectangles

PFNGLWINDOWRECTANGLESEXTPROC glWindowRectanglesEXT = nullptr;

#pragma endregion

#pragma region GL_INTEL_framebuffer_CMAA

PFNGLAPPLYFRAMEBUFFERATTACHMENTCMAAINTELPROC glApplyFramebufferAttachmentCMAAINTEL = nullptr;

#pragma endregion

#pragma region GL_INTEL_performance_query

PFNGLBEGINPERFQUERYINTELPROC glBeginPerfQueryINTEL             = nullptr;
PFNGLCREATEPERFQUERYINTELPROC glCreatePerfQueryINTEL           = nullptr;
PFNGLDELETEPERFQUERYINTELPROC glDeletePerfQueryINTEL           = nullptr;
PFNGLENDPERFQUERYINTELPROC glEndPerfQueryINTEL                 = nullptr;
PFNGLGETFIRSTPERFQUERYIDINTELPROC glGetFirstPerfQueryIdINTEL   = nullptr;
PFNGLGETNEXTPERFQUERYIDINTELPROC glGetNextPerfQueryIdINTEL     = nullptr;
PFNGLGETPERFCOUNTERINFOINTELPROC glGetPerfCounterInfoINTEL     = nullptr;
PFNGLGETPERFQUERYDATAINTELPROC glGetPerfQueryDataINTEL         = nullptr;
PFNGLGETPERFQUERYIDBYNAMEINTELPROC glGetPerfQueryIdByNameINTEL = nullptr;
PFNGLGETPERFQUERYINFOINTELPROC glGetPerfQueryInfoINTEL         = nullptr;

#pragma endregion

#pragma region GL_NV_bindless_multi_draw_indirect

PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSNVPROC glMultiDrawArraysIndirectBindlessNV     = nullptr;
PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSNVPROC glMultiDrawElementsIndirectBindlessNV = nullptr;

#pragma endregion

#pragma region GL_NV_bindless_multi_draw_indirect_count

PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSCOUNTNVPROC glMultiDrawArraysIndirectBindlessCountNV     = nullptr;
PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSCOUNTNVPROC glMultiDrawElementsIndirectBindlessCountNV = nullptr;

#pragma endregion

#pragma region GL_NV_bindless_texture

PFNGLGETTEXTUREHANDLENVPROC glGetTextureHandleNV                         = nullptr;
PFNGLGETTEXTURESAMPLERHANDLENVPROC glGetTextureSamplerHandleNV           = nullptr;
PFNGLMAKETEXTUREHANDLERESIDENTNVPROC glMakeTextureHandleResidentNV       = nullptr;
PFNGLMAKETEXTUREHANDLENONRESIDENTNVPROC glMakeTextureHandleNonResidentNV = nullptr;
PFNGLGETIMAGEHANDLENVPROC glGetImageHandleNV                             = nullptr;
PFNGLMAKEIMAGEHANDLERESIDENTNVPROC glMakeImageHandleResidentNV           = nullptr;
PFNGLMAKEIMAGEHANDLENONRESIDENTNVPROC glMakeImageHandleNonResidentNV     = nullptr;
PFNGLUNIFORMHANDLEUI64NVPROC glUniformHandleui64NV                       = nullptr;
PFNGLUNIFORMHANDLEUI64VNVPROC glUniformHandleui64vNV                     = nullptr;
PFNGLPROGRAMUNIFORMHANDLEUI64NVPROC glProgramUniformHandleui64NV         = nullptr;
PFNGLPROGRAMUNIFORMHANDLEUI64VNVPROC glProgramUniformHandleui64vNV       = nullptr;
PFNGLISTEXTUREHANDLERESIDENTNVPROC glIsTextureHandleResidentNV           = nullptr;
PFNGLISIMAGEHANDLERESIDENTNVPROC glIsImageHandleResidentNV               = nullptr;

#pragma endregion

#pragma region GL_NV_blend_equation_advanced

PFNGLBLENDPARAMETERINVPROC glBlendParameteriNV = nullptr;
PFNGLBLENDBARRIERNVPROC glBlendBarrierNV       = nullptr;

#pragma endregion

#pragma region GL_NV_clip_space_w_scaling

PFNGLVIEWPORTPOSITIONWSCALENVPROC glViewportPositionWScaleNV = nullptr;

#pragma endregion

#pragma region GL_NV_command_list

PFNGLCREATESTATESNVPROC glCreateStatesNV                                 = nullptr;
PFNGLDELETESTATESNVPROC glDeleteStatesNV                                 = nullptr;
PFNGLISSTATENVPROC glIsStateNV                                           = nullptr;
PFNGLSTATECAPTURENVPROC glStateCaptureNV                                 = nullptr;
PFNGLGETCOMMANDHEADERNVPROC glGetCommandHeaderNV                         = nullptr;
PFNGLGETSTAGEINDEXNVPROC glGetStageIndexNV                               = nullptr;
PFNGLDRAWCOMMANDSNVPROC glDrawCommandsNV                                 = nullptr;
PFNGLDRAWCOMMANDSADDRESSNVPROC glDrawCommandsAddressNV                   = nullptr;
PFNGLDRAWCOMMANDSSTATESNVPROC glDrawCommandsStatesNV                     = nullptr;
PFNGLDRAWCOMMANDSSTATESADDRESSNVPROC glDrawCommandsStatesAddressNV       = nullptr;
PFNGLCREATECOMMANDLISTSNVPROC glCreateCommandListsNV                     = nullptr;
PFNGLDELETECOMMANDLISTSNVPROC glDeleteCommandListsNV                     = nullptr;
PFNGLISCOMMANDLISTNVPROC glIsCommandListNV                               = nullptr;
PFNGLLISTDRAWCOMMANDSSTATESCLIENTNVPROC glListDrawCommandsStatesClientNV = nullptr;
PFNGLCOMMANDLISTSEGMENTSNVPROC glCommandListSegmentsNV                   = nullptr;
PFNGLCOMPILECOMMANDLISTNVPROC glCompileCommandListNV                     = nullptr;
PFNGLCALLCOMMANDLISTNVPROC glCallCommandListNV                           = nullptr;

#pragma endregion

#pragma region GL_NV_conditional_render

PFNGLBEGINCONDITIONALRENDERNVPROC glBeginConditionalRenderNV = nullptr;
PFNGLENDCONDITIONALRENDERNVPROC glEndConditionalRenderNV     = nullptr;

#pragma endregion

#pragma region GL_NV_conservative_raster

PFNGLSUBPIXELPRECISIONBIASNVPROC glSubpixelPrecisionBiasNV = nullptr;

#pragma endregion

#pragma region GL_NV_conservative_raster_dilate

PFNGLCONSERVATIVERASTERPARAMETERFNVPROC glConservativeRasterParameterfNV = nullptr;

#pragma endregion

#pragma region GL_NV_conservative_raster_pre_snap_triangles

PFNGLCONSERVATIVERASTERPARAMETERINVPROC glConservativeRasterParameteriNV = nullptr;

#pragma endregion

#pragma region GL_NV_draw_vulkan_image

PFNGLDRAWVKIMAGENVPROC glDrawVkImageNV             = nullptr;
PFNGLGETVKPROCADDRNVPROC glGetVkProcAddrNV         = nullptr;
PFNGLWAITVKSEMAPHORENVPROC glWaitVkSemaphoreNV     = nullptr;
PFNGLSIGNALVKSEMAPHORENVPROC glSignalVkSemaphoreNV = nullptr;
PFNGLSIGNALVKFENCENVPROC glSignalVkFenceNV         = nullptr;

#pragma endregion

#pragma region GL_NV_fragment_coverage_to_color

PFNGLFRAGMENTCOVERAGECOLORNVPROC glFragmentCoverageColorNV = nullptr;

#pragma endregion

#pragma region GL_NV_framebuffer_mixed_samples

PFNGLCOVERAGEMODULATIONTABLENVPROC glCoverageModulationTableNV       = nullptr;
PFNGLGETCOVERAGEMODULATIONTABLENVPROC glGetCoverageModulationTableNV = nullptr;
PFNGLCOVERAGEMODULATIONNVPROC glCoverageModulationNV                 = nullptr;

#pragma endregion

#pragma region GL_NV_framebuffer_multisample_coverage

PFNGLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENVPROC glRenderbufferStorageMultisampleCoverageNV = nullptr;

#pragma endregion

#pragma region GL_NV_gpu_shader5

PFNGLUNIFORM1I64NVPROC glUniform1i64NV                   = nullptr;
PFNGLUNIFORM2I64NVPROC glUniform2i64NV                   = nullptr;
PFNGLUNIFORM3I64NVPROC glUniform3i64NV                   = nullptr;
PFNGLUNIFORM4I64NVPROC glUniform4i64NV                   = nullptr;
PFNGLUNIFORM1I64VNVPROC glUniform1i64vNV                 = nullptr;
PFNGLUNIFORM2I64VNVPROC glUniform2i64vNV                 = nullptr;
PFNGLUNIFORM3I64VNVPROC glUniform3i64vNV                 = nullptr;
PFNGLUNIFORM4I64VNVPROC glUniform4i64vNV                 = nullptr;
PFNGLUNIFORM1UI64NVPROC glUniform1ui64NV                 = nullptr;
PFNGLUNIFORM2UI64NVPROC glUniform2ui64NV                 = nullptr;
PFNGLUNIFORM3UI64NVPROC glUniform3ui64NV                 = nullptr;
PFNGLUNIFORM4UI64NVPROC glUniform4ui64NV                 = nullptr;
PFNGLUNIFORM1UI64VNVPROC glUniform1ui64vNV               = nullptr;
PFNGLUNIFORM2UI64VNVPROC glUniform2ui64vNV               = nullptr;
PFNGLUNIFORM3UI64VNVPROC glUniform3ui64vNV               = nullptr;
PFNGLUNIFORM4UI64VNVPROC glUniform4ui64vNV               = nullptr;
PFNGLGETUNIFORMI64VNVPROC glGetUniformi64vNV             = nullptr;
PFNGLPROGRAMUNIFORM1I64NVPROC glProgramUniform1i64NV     = nullptr;
PFNGLPROGRAMUNIFORM2I64NVPROC glProgramUniform2i64NV     = nullptr;
PFNGLPROGRAMUNIFORM3I64NVPROC glProgramUniform3i64NV     = nullptr;
PFNGLPROGRAMUNIFORM4I64NVPROC glProgramUniform4i64NV     = nullptr;
PFNGLPROGRAMUNIFORM1I64VNVPROC glProgramUniform1i64vNV   = nullptr;
PFNGLPROGRAMUNIFORM2I64VNVPROC glProgramUniform2i64vNV   = nullptr;
PFNGLPROGRAMUNIFORM3I64VNVPROC glProgramUniform3i64vNV   = nullptr;
PFNGLPROGRAMUNIFORM4I64VNVPROC glProgramUniform4i64vNV   = nullptr;
PFNGLPROGRAMUNIFORM1UI64NVPROC glProgramUniform1ui64NV   = nullptr;
PFNGLPROGRAMUNIFORM2UI64NVPROC glProgramUniform2ui64NV   = nullptr;
PFNGLPROGRAMUNIFORM3UI64NVPROC glProgramUniform3ui64NV   = nullptr;
PFNGLPROGRAMUNIFORM4UI64NVPROC glProgramUniform4ui64NV   = nullptr;
PFNGLPROGRAMUNIFORM1UI64VNVPROC glProgramUniform1ui64vNV = nullptr;
PFNGLPROGRAMUNIFORM2UI64VNVPROC glProgramUniform2ui64vNV = nullptr;
PFNGLPROGRAMUNIFORM3UI64VNVPROC glProgramUniform3ui64vNV = nullptr;
PFNGLPROGRAMUNIFORM4UI64VNVPROC glProgramUniform4ui64vNV = nullptr;

#pragma endregion

#pragma region GL_NV_internalformat_sample_query

PFNGLGETINTERNALFORMATSAMPLEIVNVPROC glGetInternalformatSampleivNV = nullptr;

#pragma endregion

#pragma region GL_NV_path_rendering

PFNGLGENPATHSNVPROC glGenPathsNV                                                       = nullptr;
PFNGLDELETEPATHSNVPROC glDeletePathsNV                                                 = nullptr;
PFNGLISPATHNVPROC glIsPathNV                                                           = nullptr;
PFNGLPATHCOMMANDSNVPROC glPathCommandsNV                                               = nullptr;
PFNGLPATHCOORDSNVPROC glPathCoordsNV                                                   = nullptr;
PFNGLPATHSUBCOMMANDSNVPROC glPathSubCommandsNV                                         = nullptr;
PFNGLPATHSUBCOORDSNVPROC glPathSubCoordsNV                                             = nullptr;
PFNGLPATHSTRINGNVPROC glPathStringNV                                                   = nullptr;
PFNGLPATHGLYPHSNVPROC glPathGlyphsNV                                                   = nullptr;
PFNGLPATHGLYPHRANGENVPROC glPathGlyphRangeNV                                           = nullptr;
PFNGLWEIGHTPATHSNVPROC glWeightPathsNV                                                 = nullptr;
PFNGLCOPYPATHNVPROC glCopyPathNV                                                       = nullptr;
PFNGLINTERPOLATEPATHSNVPROC glInterpolatePathsNV                                       = nullptr;
PFNGLTRANSFORMPATHNVPROC glTransformPathNV                                             = nullptr;
PFNGLPATHPARAMETERIVNVPROC glPathParameterivNV                                         = nullptr;
PFNGLPATHPARAMETERINVPROC glPathParameteriNV                                           = nullptr;
PFNGLPATHPARAMETERFVNVPROC glPathParameterfvNV                                         = nullptr;
PFNGLPATHPARAMETERFNVPROC glPathParameterfNV                                           = nullptr;
PFNGLPATHDASHARRAYNVPROC glPathDashArrayNV                                             = nullptr;
PFNGLPATHSTENCILFUNCNVPROC glPathStencilFuncNV                                         = nullptr;
PFNGLPATHSTENCILDEPTHOFFSETNVPROC glPathStencilDepthOffsetNV                           = nullptr;
PFNGLSTENCILFILLPATHNVPROC glStencilFillPathNV                                         = nullptr;
PFNGLSTENCILSTROKEPATHNVPROC glStencilStrokePathNV                                     = nullptr;
PFNGLSTENCILFILLPATHINSTANCEDNVPROC glStencilFillPathInstancedNV                       = nullptr;
PFNGLSTENCILSTROKEPATHINSTANCEDNVPROC glStencilStrokePathInstancedNV                   = nullptr;
PFNGLPATHCOVERDEPTHFUNCNVPROC glPathCoverDepthFuncNV                                   = nullptr;
PFNGLCOVERFILLPATHNVPROC glCoverFillPathNV                                             = nullptr;
PFNGLCOVERSTROKEPATHNVPROC glCoverStrokePathNV                                         = nullptr;
PFNGLCOVERFILLPATHINSTANCEDNVPROC glCoverFillPathInstancedNV                           = nullptr;
PFNGLCOVERSTROKEPATHINSTANCEDNVPROC glCoverStrokePathInstancedNV                       = nullptr;
PFNGLGETPATHPARAMETERIVNVPROC glGetPathParameterivNV                                   = nullptr;
PFNGLGETPATHPARAMETERFVNVPROC glGetPathParameterfvNV                                   = nullptr;
PFNGLGETPATHCOMMANDSNVPROC glGetPathCommandsNV                                         = nullptr;
PFNGLGETPATHCOORDSNVPROC glGetPathCoordsNV                                             = nullptr;
PFNGLGETPATHDASHARRAYNVPROC glGetPathDashArrayNV                                       = nullptr;
PFNGLGETPATHMETRICSNVPROC glGetPathMetricsNV                                           = nullptr;
PFNGLGETPATHMETRICRANGENVPROC glGetPathMetricRangeNV                                   = nullptr;
PFNGLGETPATHSPACINGNVPROC glGetPathSpacingNV                                           = nullptr;
PFNGLISPOINTINFILLPATHNVPROC glIsPointInFillPathNV                                     = nullptr;
PFNGLISPOINTINSTROKEPATHNVPROC glIsPointInStrokePathNV                                 = nullptr;
PFNGLGETPATHLENGTHNVPROC glGetPathLengthNV                                             = nullptr;
PFNGLPOINTALONGPATHNVPROC glPointAlongPathNV                                           = nullptr;
PFNGLMATRIXLOAD3X2FNVPROC glMatrixLoad3x2fNV                                           = nullptr;
PFNGLMATRIXLOAD3X3FNVPROC glMatrixLoad3x3fNV                                           = nullptr;
PFNGLMATRIXLOADTRANSPOSE3X3FNVPROC glMatrixLoadTranspose3x3fNV                         = nullptr;
PFNGLMATRIXMULT3X2FNVPROC glMatrixMult3x2fNV                                           = nullptr;
PFNGLMATRIXMULT3X3FNVPROC glMatrixMult3x3fNV                                           = nullptr;
PFNGLMATRIXMULTTRANSPOSE3X3FNVPROC glMatrixMultTranspose3x3fNV                         = nullptr;
PFNGLSTENCILTHENCOVERFILLPATHNVPROC glStencilThenCoverFillPathNV                       = nullptr;
PFNGLSTENCILTHENCOVERSTROKEPATHNVPROC glStencilThenCoverStrokePathNV                   = nullptr;
PFNGLSTENCILTHENCOVERFILLPATHINSTANCEDNVPROC glStencilThenCoverFillPathInstancedNV     = nullptr;
PFNGLSTENCILTHENCOVERSTROKEPATHINSTANCEDNVPROC glStencilThenCoverStrokePathInstancedNV = nullptr;
PFNGLPATHGLYPHINDEXRANGENVPROC glPathGlyphIndexRangeNV                                 = nullptr;
PFNGLPATHGLYPHINDEXARRAYNVPROC glPathGlyphIndexArrayNV                                 = nullptr;
PFNGLPATHMEMORYGLYPHINDEXARRAYNVPROC glPathMemoryGlyphIndexArrayNV                     = nullptr;
PFNGLPROGRAMPATHFRAGMENTINPUTGENNVPROC glProgramPathFragmentInputGenNV                 = nullptr;
PFNGLGETPROGRAMRESOURCEFVNVPROC glGetProgramResourcefvNV                               = nullptr;

#pragma endregion

#pragma region GL_NV_sample_locations

PFNGLFRAMEBUFFERSAMPLELOCATIONSFVNVPROC glFramebufferSampleLocationsfvNV           = nullptr;
PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVNVPROC glNamedFramebufferSampleLocationsfvNV = nullptr;
PFNGLRESOLVEDEPTHVALUESNVPROC glResolveDepthValuesNV                               = nullptr;

#pragma endregion

#pragma region GL_NV_shader_buffer_load

PFNGLMAKEBUFFERRESIDENTNVPROC glMakeBufferResidentNV                     = nullptr;
PFNGLMAKEBUFFERNONRESIDENTNVPROC glMakeBufferNonResidentNV               = nullptr;
PFNGLISBUFFERRESIDENTNVPROC glIsBufferResidentNV                         = nullptr;
PFNGLMAKENAMEDBUFFERRESIDENTNVPROC glMakeNamedBufferResidentNV           = nullptr;
PFNGLMAKENAMEDBUFFERNONRESIDENTNVPROC glMakeNamedBufferNonResidentNV     = nullptr;
PFNGLISNAMEDBUFFERRESIDENTNVPROC glIsNamedBufferResidentNV               = nullptr;
PFNGLGETBUFFERPARAMETERUI64VNVPROC glGetBufferParameterui64vNV           = nullptr;
PFNGLGETNAMEDBUFFERPARAMETERUI64VNVPROC glGetNamedBufferParameterui64vNV = nullptr;
PFNGLGETINTEGERUI64VNVPROC glGetIntegerui64vNV                           = nullptr;
PFNGLUNIFORMUI64NVPROC glUniformui64NV                                   = nullptr;
PFNGLUNIFORMUI64VNVPROC glUniformui64vNV                                 = nullptr;
PFNGLGETUNIFORMUI64VNVPROC glGetUniformui64vNV                           = nullptr;
PFNGLPROGRAMUNIFORMUI64NVPROC glProgramUniformui64NV                     = nullptr;
PFNGLPROGRAMUNIFORMUI64VNVPROC glProgramUniformui64vNV                   = nullptr;

#pragma endregion

#pragma region GL_NV_texture_barrier

PFNGLTEXTUREBARRIERNVPROC glTextureBarrierNV = nullptr;

#pragma endregion

#pragma region GL_NV_vertex_attrib_integer_64bit

PFNGLVERTEXATTRIBL1I64NVPROC glVertexAttribL1i64NV         = nullptr;
PFNGLVERTEXATTRIBL2I64NVPROC glVertexAttribL2i64NV         = nullptr;
PFNGLVERTEXATTRIBL3I64NVPROC glVertexAttribL3i64NV         = nullptr;
PFNGLVERTEXATTRIBL4I64NVPROC glVertexAttribL4i64NV         = nullptr;
PFNGLVERTEXATTRIBL1I64VNVPROC glVertexAttribL1i64vNV       = nullptr;
PFNGLVERTEXATTRIBL2I64VNVPROC glVertexAttribL2i64vNV       = nullptr;
PFNGLVERTEXATTRIBL3I64VNVPROC glVertexAttribL3i64vNV       = nullptr;
PFNGLVERTEXATTRIBL4I64VNVPROC glVertexAttribL4i64vNV       = nullptr;
PFNGLVERTEXATTRIBL1UI64NVPROC glVertexAttribL1ui64NV       = nullptr;
PFNGLVERTEXATTRIBL2UI64NVPROC glVertexAttribL2ui64NV       = nullptr;
PFNGLVERTEXATTRIBL3UI64NVPROC glVertexAttribL3ui64NV       = nullptr;
PFNGLVERTEXATTRIBL4UI64NVPROC glVertexAttribL4ui64NV       = nullptr;
PFNGLVERTEXATTRIBL1UI64VNVPROC glVertexAttribL1ui64vNV     = nullptr;
PFNGLVERTEXATTRIBL2UI64VNVPROC glVertexAttribL2ui64vNV     = nullptr;
PFNGLVERTEXATTRIBL3UI64VNVPROC glVertexAttribL3ui64vNV     = nullptr;
PFNGLVERTEXATTRIBL4UI64VNVPROC glVertexAttribL4ui64vNV     = nullptr;
PFNGLGETVERTEXATTRIBLI64VNVPROC glGetVertexAttribLi64vNV   = nullptr;
PFNGLGETVERTEXATTRIBLUI64VNVPROC glGetVertexAttribLui64vNV = nullptr;
PFNGLVERTEXATTRIBLFORMATNVPROC glVertexAttribLFormatNV     = nullptr;

#pragma endregion

#pragma region GL_NV_vertex_buffer_unified_memory

PFNGLBUFFERADDRESSRANGENVPROC glBufferAddressRangeNV     = nullptr;
PFNGLVERTEXFORMATNVPROC glVertexFormatNV                 = nullptr;
PFNGLNORMALFORMATNVPROC glNormalFormatNV                 = nullptr;
PFNGLCOLORFORMATNVPROC glColorFormatNV                   = nullptr;
PFNGLINDEXFORMATNVPROC glIndexFormatNV                   = nullptr;
PFNGLTEXCOORDFORMATNVPROC glTexCoordFormatNV             = nullptr;
PFNGLEDGEFLAGFORMATNVPROC glEdgeFlagFormatNV             = nullptr;
PFNGLSECONDARYCOLORFORMATNVPROC glSecondaryColorFormatNV = nullptr;
PFNGLFOGCOORDFORMATNVPROC glFogCoordFormatNV             = nullptr;
PFNGLVERTEXATTRIBFORMATNVPROC glVertexAttribFormatNV     = nullptr;
PFNGLVERTEXATTRIBIFORMATNVPROC glVertexAttribIFormatNV   = nullptr;
PFNGLGETINTEGERUI64I_VNVPROC glGetIntegerui64i_vNV       = nullptr;

#pragma endregion

#pragma region GL_NV_viewport_swizzle

PFNGLVIEWPORTSWIZZLENVPROC glViewportSwizzleNV = nullptr;

#pragma endregion

#pragma region GL_OVR_multiview

PFNGLFRAMEBUFFERTEXTUREMULTIVIEWOVRPROC glFramebufferTextureMultiviewOVR = nullptr;

#pragma endregion

} // namespace framework::graphics::opengl::details

namespace
{
#pragma region init_definitions

bool init_gl_version_1_0()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glCullFace = get_function<PFNGLCULLFACEPROC>("glCullFace")) != nullptr;
    result = result && (framework::graphics::opengl::details::glFrontFace = get_function<PFNGLFRONTFACEPROC>("glFrontFace")) != nullptr;
    result = result && (framework::graphics::opengl::details::glHint = get_function<PFNGLHINTPROC>("glHint")) != nullptr;
    result = result && (framework::graphics::opengl::details::glLineWidth = get_function<PFNGLLINEWIDTHPROC>("glLineWidth")) != nullptr;
    result = result && (framework::graphics::opengl::details::glPointSize = get_function<PFNGLPOINTSIZEPROC>("glPointSize")) != nullptr;
    result = result && (framework::graphics::opengl::details::glPolygonMode = get_function<PFNGLPOLYGONMODEPROC>("glPolygonMode")) != nullptr;
    result = result && (framework::graphics::opengl::details::glScissor = get_function<PFNGLSCISSORPROC>("glScissor")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTexParameterf = get_function<PFNGLTEXPARAMETERFPROC>("glTexParameterf")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTexParameterfv = get_function<PFNGLTEXPARAMETERFVPROC>("glTexParameterfv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTexParameteri = get_function<PFNGLTEXPARAMETERIPROC>("glTexParameteri")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTexParameteriv = get_function<PFNGLTEXPARAMETERIVPROC>("glTexParameteriv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTexImage1D = get_function<PFNGLTEXIMAGE1DPROC>("glTexImage1D")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTexImage2D = get_function<PFNGLTEXIMAGE2DPROC>("glTexImage2D")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDrawBuffer = get_function<PFNGLDRAWBUFFERPROC>("glDrawBuffer")) != nullptr;
    result = result && (framework::graphics::opengl::details::glClear = get_function<PFNGLCLEARPROC>("glClear")) != nullptr;
    result = result && (framework::graphics::opengl::details::glClearColor = get_function<PFNGLCLEARCOLORPROC>("glClearColor")) != nullptr;
    result = result && (framework::graphics::opengl::details::glClearStencil = get_function<PFNGLCLEARSTENCILPROC>("glClearStencil")) != nullptr;
    result = result && (framework::graphics::opengl::details::glClearDepth = get_function<PFNGLCLEARDEPTHPROC>("glClearDepth")) != nullptr;
    result = result && (framework::graphics::opengl::details::glStencilMask = get_function<PFNGLSTENCILMASKPROC>("glStencilMask")) != nullptr;
    result = result && (framework::graphics::opengl::details::glColorMask = get_function<PFNGLCOLORMASKPROC>("glColorMask")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDepthMask = get_function<PFNGLDEPTHMASKPROC>("glDepthMask")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDisable = get_function<PFNGLDISABLEPROC>("glDisable")) != nullptr;
    result = result && (framework::graphics::opengl::details::glEnable = get_function<PFNGLENABLEPROC>("glEnable")) != nullptr;
    result = result && (framework::graphics::opengl::details::glFinish = get_function<PFNGLFINISHPROC>("glFinish")) != nullptr;
    result = result && (framework::graphics::opengl::details::glFlush = get_function<PFNGLFLUSHPROC>("glFlush")) != nullptr;
    result = result && (framework::graphics::opengl::details::glBlendFunc = get_function<PFNGLBLENDFUNCPROC>("glBlendFunc")) != nullptr;
    result = result && (framework::graphics::opengl::details::glLogicOp = get_function<PFNGLLOGICOPPROC>("glLogicOp")) != nullptr;
    result = result && (framework::graphics::opengl::details::glStencilFunc = get_function<PFNGLSTENCILFUNCPROC>("glStencilFunc")) != nullptr;
    result = result && (framework::graphics::opengl::details::glStencilOp = get_function<PFNGLSTENCILOPPROC>("glStencilOp")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDepthFunc = get_function<PFNGLDEPTHFUNCPROC>("glDepthFunc")) != nullptr;
    result = result && (framework::graphics::opengl::details::glPixelStoref = get_function<PFNGLPIXELSTOREFPROC>("glPixelStoref")) != nullptr;
    result = result && (framework::graphics::opengl::details::glPixelStorei = get_function<PFNGLPIXELSTOREIPROC>("glPixelStorei")) != nullptr;
    result = result && (framework::graphics::opengl::details::glReadBuffer = get_function<PFNGLREADBUFFERPROC>("glReadBuffer")) != nullptr;
    result = result && (framework::graphics::opengl::details::glReadPixels = get_function<PFNGLREADPIXELSPROC>("glReadPixels")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetBooleanv = get_function<PFNGLGETBOOLEANVPROC>("glGetBooleanv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetDoublev = get_function<PFNGLGETDOUBLEVPROC>("glGetDoublev")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetError = get_function<PFNGLGETERRORPROC>("glGetError")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetFloatv = get_function<PFNGLGETFLOATVPROC>("glGetFloatv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetIntegerv = get_function<PFNGLGETINTEGERVPROC>("glGetIntegerv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetString = get_function<PFNGLGETSTRINGPROC>("glGetString")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetTexImage = get_function<PFNGLGETTEXIMAGEPROC>("glGetTexImage")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetTexParameterfv = get_function<PFNGLGETTEXPARAMETERFVPROC>("glGetTexParameterfv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetTexParameteriv = get_function<PFNGLGETTEXPARAMETERIVPROC>("glGetTexParameteriv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetTexLevelParameterfv = get_function<PFNGLGETTEXLEVELPARAMETERFVPROC>("glGetTexLevelParameterfv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetTexLevelParameteriv = get_function<PFNGLGETTEXLEVELPARAMETERIVPROC>("glGetTexLevelParameteriv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glIsEnabled = get_function<PFNGLISENABLEDPROC>("glIsEnabled")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDepthRange = get_function<PFNGLDEPTHRANGEPROC>("glDepthRange")) != nullptr;
    result = result && (framework::graphics::opengl::details::glViewport = get_function<PFNGLVIEWPORTPROC>("glViewport")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_version_1_1()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glDrawArrays = get_function<PFNGLDRAWARRAYSPROC>("glDrawArrays")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDrawElements = get_function<PFNGLDRAWELEMENTSPROC>("glDrawElements")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetPointerv = get_function<PFNGLGETPOINTERVPROC>("glGetPointerv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glPolygonOffset = get_function<PFNGLPOLYGONOFFSETPROC>("glPolygonOffset")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCopyTexImage1D = get_function<PFNGLCOPYTEXIMAGE1DPROC>("glCopyTexImage1D")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCopyTexImage2D = get_function<PFNGLCOPYTEXIMAGE2DPROC>("glCopyTexImage2D")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCopyTexSubImage1D = get_function<PFNGLCOPYTEXSUBIMAGE1DPROC>("glCopyTexSubImage1D")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCopyTexSubImage2D = get_function<PFNGLCOPYTEXSUBIMAGE2DPROC>("glCopyTexSubImage2D")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTexSubImage1D = get_function<PFNGLTEXSUBIMAGE1DPROC>("glTexSubImage1D")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTexSubImage2D = get_function<PFNGLTEXSUBIMAGE2DPROC>("glTexSubImage2D")) != nullptr;
    result = result && (framework::graphics::opengl::details::glBindTexture = get_function<PFNGLBINDTEXTUREPROC>("glBindTexture")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDeleteTextures = get_function<PFNGLDELETETEXTURESPROC>("glDeleteTextures")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGenTextures = get_function<PFNGLGENTEXTURESPROC>("glGenTextures")) != nullptr;
    result = result && (framework::graphics::opengl::details::glIsTexture = get_function<PFNGLISTEXTUREPROC>("glIsTexture")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_version_1_2()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glDrawRangeElements = get_function<PFNGLDRAWRANGEELEMENTSPROC>("glDrawRangeElements")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTexImage3D = get_function<PFNGLTEXIMAGE3DPROC>("glTexImage3D")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTexSubImage3D = get_function<PFNGLTEXSUBIMAGE3DPROC>("glTexSubImage3D")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCopyTexSubImage3D = get_function<PFNGLCOPYTEXSUBIMAGE3DPROC>("glCopyTexSubImage3D")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_version_1_3()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glActiveTexture = get_function<PFNGLACTIVETEXTUREPROC>("glActiveTexture")) != nullptr;
    result = result && (framework::graphics::opengl::details::glSampleCoverage = get_function<PFNGLSAMPLECOVERAGEPROC>("glSampleCoverage")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCompressedTexImage3D = get_function<PFNGLCOMPRESSEDTEXIMAGE3DPROC>("glCompressedTexImage3D")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCompressedTexImage2D = get_function<PFNGLCOMPRESSEDTEXIMAGE2DPROC>("glCompressedTexImage2D")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCompressedTexImage1D = get_function<PFNGLCOMPRESSEDTEXIMAGE1DPROC>("glCompressedTexImage1D")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCompressedTexSubImage3D = get_function<PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC>("glCompressedTexSubImage3D")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCompressedTexSubImage2D = get_function<PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC>("glCompressedTexSubImage2D")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCompressedTexSubImage1D = get_function<PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC>("glCompressedTexSubImage1D")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetCompressedTexImage = get_function<PFNGLGETCOMPRESSEDTEXIMAGEPROC>("glGetCompressedTexImage")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_version_1_4()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glBlendFuncSeparate = get_function<PFNGLBLENDFUNCSEPARATEPROC>("glBlendFuncSeparate")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMultiDrawArrays = get_function<PFNGLMULTIDRAWARRAYSPROC>("glMultiDrawArrays")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMultiDrawElements = get_function<PFNGLMULTIDRAWELEMENTSPROC>("glMultiDrawElements")) != nullptr;
    result = result && (framework::graphics::opengl::details::glPointParameterf = get_function<PFNGLPOINTPARAMETERFPROC>("glPointParameterf")) != nullptr;
    result = result && (framework::graphics::opengl::details::glPointParameterfv = get_function<PFNGLPOINTPARAMETERFVPROC>("glPointParameterfv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glPointParameteri = get_function<PFNGLPOINTPARAMETERIPROC>("glPointParameteri")) != nullptr;
    result = result && (framework::graphics::opengl::details::glPointParameteriv = get_function<PFNGLPOINTPARAMETERIVPROC>("glPointParameteriv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glBlendColor = get_function<PFNGLBLENDCOLORPROC>("glBlendColor")) != nullptr;
    result = result && (framework::graphics::opengl::details::glBlendEquation = get_function<PFNGLBLENDEQUATIONPROC>("glBlendEquation")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_version_1_5()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glGenQueries = get_function<PFNGLGENQUERIESPROC>("glGenQueries")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDeleteQueries = get_function<PFNGLDELETEQUERIESPROC>("glDeleteQueries")) != nullptr;
    result = result && (framework::graphics::opengl::details::glIsQuery = get_function<PFNGLISQUERYPROC>("glIsQuery")) != nullptr;
    result = result && (framework::graphics::opengl::details::glBeginQuery = get_function<PFNGLBEGINQUERYPROC>("glBeginQuery")) != nullptr;
    result = result && (framework::graphics::opengl::details::glEndQuery = get_function<PFNGLENDQUERYPROC>("glEndQuery")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetQueryiv = get_function<PFNGLGETQUERYIVPROC>("glGetQueryiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetQueryObjectiv = get_function<PFNGLGETQUERYOBJECTIVPROC>("glGetQueryObjectiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetQueryObjectuiv = get_function<PFNGLGETQUERYOBJECTUIVPROC>("glGetQueryObjectuiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glBindBuffer = get_function<PFNGLBINDBUFFERPROC>("glBindBuffer")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDeleteBuffers = get_function<PFNGLDELETEBUFFERSPROC>("glDeleteBuffers")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGenBuffers = get_function<PFNGLGENBUFFERSPROC>("glGenBuffers")) != nullptr;
    result = result && (framework::graphics::opengl::details::glIsBuffer = get_function<PFNGLISBUFFERPROC>("glIsBuffer")) != nullptr;
    result = result && (framework::graphics::opengl::details::glBufferData = get_function<PFNGLBUFFERDATAPROC>("glBufferData")) != nullptr;
    result = result && (framework::graphics::opengl::details::glBufferSubData = get_function<PFNGLBUFFERSUBDATAPROC>("glBufferSubData")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetBufferSubData = get_function<PFNGLGETBUFFERSUBDATAPROC>("glGetBufferSubData")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMapBuffer = get_function<PFNGLMAPBUFFERPROC>("glMapBuffer")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUnmapBuffer = get_function<PFNGLUNMAPBUFFERPROC>("glUnmapBuffer")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetBufferParameteriv = get_function<PFNGLGETBUFFERPARAMETERIVPROC>("glGetBufferParameteriv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetBufferPointerv = get_function<PFNGLGETBUFFERPOINTERVPROC>("glGetBufferPointerv")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_version_2_0()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glBlendEquationSeparate = get_function<PFNGLBLENDEQUATIONSEPARATEPROC>("glBlendEquationSeparate")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDrawBuffers = get_function<PFNGLDRAWBUFFERSPROC>("glDrawBuffers")) != nullptr;
    result = result && (framework::graphics::opengl::details::glStencilOpSeparate = get_function<PFNGLSTENCILOPSEPARATEPROC>("glStencilOpSeparate")) != nullptr;
    result = result && (framework::graphics::opengl::details::glStencilFuncSeparate = get_function<PFNGLSTENCILFUNCSEPARATEPROC>("glStencilFuncSeparate")) != nullptr;
    result = result && (framework::graphics::opengl::details::glStencilMaskSeparate = get_function<PFNGLSTENCILMASKSEPARATEPROC>("glStencilMaskSeparate")) != nullptr;
    result = result && (framework::graphics::opengl::details::glAttachShader = get_function<PFNGLATTACHSHADERPROC>("glAttachShader")) != nullptr;
    result = result && (framework::graphics::opengl::details::glBindAttribLocation = get_function<PFNGLBINDATTRIBLOCATIONPROC>("glBindAttribLocation")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCompileShader = get_function<PFNGLCOMPILESHADERPROC>("glCompileShader")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCreateProgram = get_function<PFNGLCREATEPROGRAMPROC>("glCreateProgram")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCreateShader = get_function<PFNGLCREATESHADERPROC>("glCreateShader")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDeleteProgram = get_function<PFNGLDELETEPROGRAMPROC>("glDeleteProgram")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDeleteShader = get_function<PFNGLDELETESHADERPROC>("glDeleteShader")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDetachShader = get_function<PFNGLDETACHSHADERPROC>("glDetachShader")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDisableVertexAttribArray = get_function<PFNGLDISABLEVERTEXATTRIBARRAYPROC>("glDisableVertexAttribArray")) != nullptr;
    result = result && (framework::graphics::opengl::details::glEnableVertexAttribArray = get_function<PFNGLENABLEVERTEXATTRIBARRAYPROC>("glEnableVertexAttribArray")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetActiveAttrib = get_function<PFNGLGETACTIVEATTRIBPROC>("glGetActiveAttrib")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetActiveUniform = get_function<PFNGLGETACTIVEUNIFORMPROC>("glGetActiveUniform")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetAttachedShaders = get_function<PFNGLGETATTACHEDSHADERSPROC>("glGetAttachedShaders")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetAttribLocation = get_function<PFNGLGETATTRIBLOCATIONPROC>("glGetAttribLocation")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetProgramiv = get_function<PFNGLGETPROGRAMIVPROC>("glGetProgramiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetProgramInfoLog = get_function<PFNGLGETPROGRAMINFOLOGPROC>("glGetProgramInfoLog")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetShaderiv = get_function<PFNGLGETSHADERIVPROC>("glGetShaderiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetShaderInfoLog = get_function<PFNGLGETSHADERINFOLOGPROC>("glGetShaderInfoLog")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetShaderSource = get_function<PFNGLGETSHADERSOURCEPROC>("glGetShaderSource")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetUniformLocation = get_function<PFNGLGETUNIFORMLOCATIONPROC>("glGetUniformLocation")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetUniformfv = get_function<PFNGLGETUNIFORMFVPROC>("glGetUniformfv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetUniformiv = get_function<PFNGLGETUNIFORMIVPROC>("glGetUniformiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetVertexAttribdv = get_function<PFNGLGETVERTEXATTRIBDVPROC>("glGetVertexAttribdv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetVertexAttribfv = get_function<PFNGLGETVERTEXATTRIBFVPROC>("glGetVertexAttribfv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetVertexAttribiv = get_function<PFNGLGETVERTEXATTRIBIVPROC>("glGetVertexAttribiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetVertexAttribPointerv = get_function<PFNGLGETVERTEXATTRIBPOINTERVPROC>("glGetVertexAttribPointerv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glIsProgram = get_function<PFNGLISPROGRAMPROC>("glIsProgram")) != nullptr;
    result = result && (framework::graphics::opengl::details::glIsShader = get_function<PFNGLISSHADERPROC>("glIsShader")) != nullptr;
    result = result && (framework::graphics::opengl::details::glLinkProgram = get_function<PFNGLLINKPROGRAMPROC>("glLinkProgram")) != nullptr;
    result = result && (framework::graphics::opengl::details::glShaderSource = get_function<PFNGLSHADERSOURCEPROC>("glShaderSource")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUseProgram = get_function<PFNGLUSEPROGRAMPROC>("glUseProgram")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform1f = get_function<PFNGLUNIFORM1FPROC>("glUniform1f")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform2f = get_function<PFNGLUNIFORM2FPROC>("glUniform2f")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform3f = get_function<PFNGLUNIFORM3FPROC>("glUniform3f")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform4f = get_function<PFNGLUNIFORM4FPROC>("glUniform4f")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform1i = get_function<PFNGLUNIFORM1IPROC>("glUniform1i")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform2i = get_function<PFNGLUNIFORM2IPROC>("glUniform2i")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform3i = get_function<PFNGLUNIFORM3IPROC>("glUniform3i")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform4i = get_function<PFNGLUNIFORM4IPROC>("glUniform4i")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform1fv = get_function<PFNGLUNIFORM1FVPROC>("glUniform1fv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform2fv = get_function<PFNGLUNIFORM2FVPROC>("glUniform2fv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform3fv = get_function<PFNGLUNIFORM3FVPROC>("glUniform3fv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform4fv = get_function<PFNGLUNIFORM4FVPROC>("glUniform4fv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform1iv = get_function<PFNGLUNIFORM1IVPROC>("glUniform1iv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform2iv = get_function<PFNGLUNIFORM2IVPROC>("glUniform2iv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform3iv = get_function<PFNGLUNIFORM3IVPROC>("glUniform3iv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform4iv = get_function<PFNGLUNIFORM4IVPROC>("glUniform4iv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniformMatrix2fv = get_function<PFNGLUNIFORMMATRIX2FVPROC>("glUniformMatrix2fv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniformMatrix3fv = get_function<PFNGLUNIFORMMATRIX3FVPROC>("glUniformMatrix3fv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniformMatrix4fv = get_function<PFNGLUNIFORMMATRIX4FVPROC>("glUniformMatrix4fv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glValidateProgram = get_function<PFNGLVALIDATEPROGRAMPROC>("glValidateProgram")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttrib1d = get_function<PFNGLVERTEXATTRIB1DPROC>("glVertexAttrib1d")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttrib1dv = get_function<PFNGLVERTEXATTRIB1DVPROC>("glVertexAttrib1dv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttrib1f = get_function<PFNGLVERTEXATTRIB1FPROC>("glVertexAttrib1f")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttrib1fv = get_function<PFNGLVERTEXATTRIB1FVPROC>("glVertexAttrib1fv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttrib1s = get_function<PFNGLVERTEXATTRIB1SPROC>("glVertexAttrib1s")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttrib1sv = get_function<PFNGLVERTEXATTRIB1SVPROC>("glVertexAttrib1sv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttrib2d = get_function<PFNGLVERTEXATTRIB2DPROC>("glVertexAttrib2d")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttrib2dv = get_function<PFNGLVERTEXATTRIB2DVPROC>("glVertexAttrib2dv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttrib2f = get_function<PFNGLVERTEXATTRIB2FPROC>("glVertexAttrib2f")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttrib2fv = get_function<PFNGLVERTEXATTRIB2FVPROC>("glVertexAttrib2fv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttrib2s = get_function<PFNGLVERTEXATTRIB2SPROC>("glVertexAttrib2s")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttrib2sv = get_function<PFNGLVERTEXATTRIB2SVPROC>("glVertexAttrib2sv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttrib3d = get_function<PFNGLVERTEXATTRIB3DPROC>("glVertexAttrib3d")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttrib3dv = get_function<PFNGLVERTEXATTRIB3DVPROC>("glVertexAttrib3dv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttrib3f = get_function<PFNGLVERTEXATTRIB3FPROC>("glVertexAttrib3f")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttrib3fv = get_function<PFNGLVERTEXATTRIB3FVPROC>("glVertexAttrib3fv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttrib3s = get_function<PFNGLVERTEXATTRIB3SPROC>("glVertexAttrib3s")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttrib3sv = get_function<PFNGLVERTEXATTRIB3SVPROC>("glVertexAttrib3sv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttrib4Nbv = get_function<PFNGLVERTEXATTRIB4NBVPROC>("glVertexAttrib4Nbv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttrib4Niv = get_function<PFNGLVERTEXATTRIB4NIVPROC>("glVertexAttrib4Niv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttrib4Nsv = get_function<PFNGLVERTEXATTRIB4NSVPROC>("glVertexAttrib4Nsv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttrib4Nub = get_function<PFNGLVERTEXATTRIB4NUBPROC>("glVertexAttrib4Nub")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttrib4Nubv = get_function<PFNGLVERTEXATTRIB4NUBVPROC>("glVertexAttrib4Nubv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttrib4Nuiv = get_function<PFNGLVERTEXATTRIB4NUIVPROC>("glVertexAttrib4Nuiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttrib4Nusv = get_function<PFNGLVERTEXATTRIB4NUSVPROC>("glVertexAttrib4Nusv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttrib4bv = get_function<PFNGLVERTEXATTRIB4BVPROC>("glVertexAttrib4bv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttrib4d = get_function<PFNGLVERTEXATTRIB4DPROC>("glVertexAttrib4d")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttrib4dv = get_function<PFNGLVERTEXATTRIB4DVPROC>("glVertexAttrib4dv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttrib4f = get_function<PFNGLVERTEXATTRIB4FPROC>("glVertexAttrib4f")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttrib4fv = get_function<PFNGLVERTEXATTRIB4FVPROC>("glVertexAttrib4fv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttrib4iv = get_function<PFNGLVERTEXATTRIB4IVPROC>("glVertexAttrib4iv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttrib4s = get_function<PFNGLVERTEXATTRIB4SPROC>("glVertexAttrib4s")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttrib4sv = get_function<PFNGLVERTEXATTRIB4SVPROC>("glVertexAttrib4sv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttrib4ubv = get_function<PFNGLVERTEXATTRIB4UBVPROC>("glVertexAttrib4ubv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttrib4uiv = get_function<PFNGLVERTEXATTRIB4UIVPROC>("glVertexAttrib4uiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttrib4usv = get_function<PFNGLVERTEXATTRIB4USVPROC>("glVertexAttrib4usv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribPointer = get_function<PFNGLVERTEXATTRIBPOINTERPROC>("glVertexAttribPointer")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_version_2_1()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glUniformMatrix2x3fv = get_function<PFNGLUNIFORMMATRIX2X3FVPROC>("glUniformMatrix2x3fv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniformMatrix3x2fv = get_function<PFNGLUNIFORMMATRIX3X2FVPROC>("glUniformMatrix3x2fv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniformMatrix2x4fv = get_function<PFNGLUNIFORMMATRIX2X4FVPROC>("glUniformMatrix2x4fv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniformMatrix4x2fv = get_function<PFNGLUNIFORMMATRIX4X2FVPROC>("glUniformMatrix4x2fv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniformMatrix3x4fv = get_function<PFNGLUNIFORMMATRIX3X4FVPROC>("glUniformMatrix3x4fv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniformMatrix4x3fv = get_function<PFNGLUNIFORMMATRIX4X3FVPROC>("glUniformMatrix4x3fv")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_version_3_0()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glColorMaski = get_function<PFNGLCOLORMASKIPROC>("glColorMaski")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetBooleani_v = get_function<PFNGLGETBOOLEANI_VPROC>("glGetBooleani_v")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetIntegeri_v = get_function<PFNGLGETINTEGERI_VPROC>("glGetIntegeri_v")) != nullptr;
    result = result && (framework::graphics::opengl::details::glEnablei = get_function<PFNGLENABLEIPROC>("glEnablei")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDisablei = get_function<PFNGLDISABLEIPROC>("glDisablei")) != nullptr;
    result = result && (framework::graphics::opengl::details::glIsEnabledi = get_function<PFNGLISENABLEDIPROC>("glIsEnabledi")) != nullptr;
    result = result && (framework::graphics::opengl::details::glBeginTransformFeedback = get_function<PFNGLBEGINTRANSFORMFEEDBACKPROC>("glBeginTransformFeedback")) != nullptr;
    result = result && (framework::graphics::opengl::details::glEndTransformFeedback = get_function<PFNGLENDTRANSFORMFEEDBACKPROC>("glEndTransformFeedback")) != nullptr;
    result = result && (framework::graphics::opengl::details::glBindBufferRange = get_function<PFNGLBINDBUFFERRANGEPROC>("glBindBufferRange")) != nullptr;
    result = result && (framework::graphics::opengl::details::glBindBufferBase = get_function<PFNGLBINDBUFFERBASEPROC>("glBindBufferBase")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTransformFeedbackVaryings = get_function<PFNGLTRANSFORMFEEDBACKVARYINGSPROC>("glTransformFeedbackVaryings")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetTransformFeedbackVarying = get_function<PFNGLGETTRANSFORMFEEDBACKVARYINGPROC>("glGetTransformFeedbackVarying")) != nullptr;
    result = result && (framework::graphics::opengl::details::glClampColor = get_function<PFNGLCLAMPCOLORPROC>("glClampColor")) != nullptr;
    result = result && (framework::graphics::opengl::details::glBeginConditionalRender = get_function<PFNGLBEGINCONDITIONALRENDERPROC>("glBeginConditionalRender")) != nullptr;
    result = result && (framework::graphics::opengl::details::glEndConditionalRender = get_function<PFNGLENDCONDITIONALRENDERPROC>("glEndConditionalRender")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribIPointer = get_function<PFNGLVERTEXATTRIBIPOINTERPROC>("glVertexAttribIPointer")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetVertexAttribIiv = get_function<PFNGLGETVERTEXATTRIBIIVPROC>("glGetVertexAttribIiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetVertexAttribIuiv = get_function<PFNGLGETVERTEXATTRIBIUIVPROC>("glGetVertexAttribIuiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribI1i = get_function<PFNGLVERTEXATTRIBI1IPROC>("glVertexAttribI1i")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribI2i = get_function<PFNGLVERTEXATTRIBI2IPROC>("glVertexAttribI2i")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribI3i = get_function<PFNGLVERTEXATTRIBI3IPROC>("glVertexAttribI3i")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribI4i = get_function<PFNGLVERTEXATTRIBI4IPROC>("glVertexAttribI4i")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribI1ui = get_function<PFNGLVERTEXATTRIBI1UIPROC>("glVertexAttribI1ui")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribI2ui = get_function<PFNGLVERTEXATTRIBI2UIPROC>("glVertexAttribI2ui")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribI3ui = get_function<PFNGLVERTEXATTRIBI3UIPROC>("glVertexAttribI3ui")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribI4ui = get_function<PFNGLVERTEXATTRIBI4UIPROC>("glVertexAttribI4ui")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribI1iv = get_function<PFNGLVERTEXATTRIBI1IVPROC>("glVertexAttribI1iv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribI2iv = get_function<PFNGLVERTEXATTRIBI2IVPROC>("glVertexAttribI2iv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribI3iv = get_function<PFNGLVERTEXATTRIBI3IVPROC>("glVertexAttribI3iv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribI4iv = get_function<PFNGLVERTEXATTRIBI4IVPROC>("glVertexAttribI4iv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribI1uiv = get_function<PFNGLVERTEXATTRIBI1UIVPROC>("glVertexAttribI1uiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribI2uiv = get_function<PFNGLVERTEXATTRIBI2UIVPROC>("glVertexAttribI2uiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribI3uiv = get_function<PFNGLVERTEXATTRIBI3UIVPROC>("glVertexAttribI3uiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribI4uiv = get_function<PFNGLVERTEXATTRIBI4UIVPROC>("glVertexAttribI4uiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribI4bv = get_function<PFNGLVERTEXATTRIBI4BVPROC>("glVertexAttribI4bv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribI4sv = get_function<PFNGLVERTEXATTRIBI4SVPROC>("glVertexAttribI4sv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribI4ubv = get_function<PFNGLVERTEXATTRIBI4UBVPROC>("glVertexAttribI4ubv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribI4usv = get_function<PFNGLVERTEXATTRIBI4USVPROC>("glVertexAttribI4usv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetUniformuiv = get_function<PFNGLGETUNIFORMUIVPROC>("glGetUniformuiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glBindFragDataLocation = get_function<PFNGLBINDFRAGDATALOCATIONPROC>("glBindFragDataLocation")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetFragDataLocation = get_function<PFNGLGETFRAGDATALOCATIONPROC>("glGetFragDataLocation")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform1ui = get_function<PFNGLUNIFORM1UIPROC>("glUniform1ui")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform2ui = get_function<PFNGLUNIFORM2UIPROC>("glUniform2ui")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform3ui = get_function<PFNGLUNIFORM3UIPROC>("glUniform3ui")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform4ui = get_function<PFNGLUNIFORM4UIPROC>("glUniform4ui")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform1uiv = get_function<PFNGLUNIFORM1UIVPROC>("glUniform1uiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform2uiv = get_function<PFNGLUNIFORM2UIVPROC>("glUniform2uiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform3uiv = get_function<PFNGLUNIFORM3UIVPROC>("glUniform3uiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform4uiv = get_function<PFNGLUNIFORM4UIVPROC>("glUniform4uiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTexParameterIiv = get_function<PFNGLTEXPARAMETERIIVPROC>("glTexParameterIiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTexParameterIuiv = get_function<PFNGLTEXPARAMETERIUIVPROC>("glTexParameterIuiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetTexParameterIiv = get_function<PFNGLGETTEXPARAMETERIIVPROC>("glGetTexParameterIiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetTexParameterIuiv = get_function<PFNGLGETTEXPARAMETERIUIVPROC>("glGetTexParameterIuiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glClearBufferiv = get_function<PFNGLCLEARBUFFERIVPROC>("glClearBufferiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glClearBufferuiv = get_function<PFNGLCLEARBUFFERUIVPROC>("glClearBufferuiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glClearBufferfv = get_function<PFNGLCLEARBUFFERFVPROC>("glClearBufferfv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glClearBufferfi = get_function<PFNGLCLEARBUFFERFIPROC>("glClearBufferfi")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetStringi = get_function<PFNGLGETSTRINGIPROC>("glGetStringi")) != nullptr;
    result = result && (framework::graphics::opengl::details::glIsRenderbuffer = get_function<PFNGLISRENDERBUFFERPROC>("glIsRenderbuffer")) != nullptr;
    result = result && (framework::graphics::opengl::details::glBindRenderbuffer = get_function<PFNGLBINDRENDERBUFFERPROC>("glBindRenderbuffer")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDeleteRenderbuffers = get_function<PFNGLDELETERENDERBUFFERSPROC>("glDeleteRenderbuffers")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGenRenderbuffers = get_function<PFNGLGENRENDERBUFFERSPROC>("glGenRenderbuffers")) != nullptr;
    result = result && (framework::graphics::opengl::details::glRenderbufferStorage = get_function<PFNGLRENDERBUFFERSTORAGEPROC>("glRenderbufferStorage")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetRenderbufferParameteriv = get_function<PFNGLGETRENDERBUFFERPARAMETERIVPROC>("glGetRenderbufferParameteriv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glIsFramebuffer = get_function<PFNGLISFRAMEBUFFERPROC>("glIsFramebuffer")) != nullptr;
    result = result && (framework::graphics::opengl::details::glBindFramebuffer = get_function<PFNGLBINDFRAMEBUFFERPROC>("glBindFramebuffer")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDeleteFramebuffers = get_function<PFNGLDELETEFRAMEBUFFERSPROC>("glDeleteFramebuffers")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGenFramebuffers = get_function<PFNGLGENFRAMEBUFFERSPROC>("glGenFramebuffers")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCheckFramebufferStatus = get_function<PFNGLCHECKFRAMEBUFFERSTATUSPROC>("glCheckFramebufferStatus")) != nullptr;
    result = result && (framework::graphics::opengl::details::glFramebufferTexture1D = get_function<PFNGLFRAMEBUFFERTEXTURE1DPROC>("glFramebufferTexture1D")) != nullptr;
    result = result && (framework::graphics::opengl::details::glFramebufferTexture2D = get_function<PFNGLFRAMEBUFFERTEXTURE2DPROC>("glFramebufferTexture2D")) != nullptr;
    result = result && (framework::graphics::opengl::details::glFramebufferTexture3D = get_function<PFNGLFRAMEBUFFERTEXTURE3DPROC>("glFramebufferTexture3D")) != nullptr;
    result = result && (framework::graphics::opengl::details::glFramebufferRenderbuffer = get_function<PFNGLFRAMEBUFFERRENDERBUFFERPROC>("glFramebufferRenderbuffer")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetFramebufferAttachmentParameteriv = get_function<PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC>("glGetFramebufferAttachmentParameteriv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGenerateMipmap = get_function<PFNGLGENERATEMIPMAPPROC>("glGenerateMipmap")) != nullptr;
    result = result && (framework::graphics::opengl::details::glBlitFramebuffer = get_function<PFNGLBLITFRAMEBUFFERPROC>("glBlitFramebuffer")) != nullptr;
    result = result && (framework::graphics::opengl::details::glRenderbufferStorageMultisample = get_function<PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC>("glRenderbufferStorageMultisample")) != nullptr;
    result = result && (framework::graphics::opengl::details::glFramebufferTextureLayer = get_function<PFNGLFRAMEBUFFERTEXTURELAYERPROC>("glFramebufferTextureLayer")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMapBufferRange = get_function<PFNGLMAPBUFFERRANGEPROC>("glMapBufferRange")) != nullptr;
    result = result && (framework::graphics::opengl::details::glFlushMappedBufferRange = get_function<PFNGLFLUSHMAPPEDBUFFERRANGEPROC>("glFlushMappedBufferRange")) != nullptr;
    result = result && (framework::graphics::opengl::details::glBindVertexArray = get_function<PFNGLBINDVERTEXARRAYPROC>("glBindVertexArray")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDeleteVertexArrays = get_function<PFNGLDELETEVERTEXARRAYSPROC>("glDeleteVertexArrays")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGenVertexArrays = get_function<PFNGLGENVERTEXARRAYSPROC>("glGenVertexArrays")) != nullptr;
    result = result && (framework::graphics::opengl::details::glIsVertexArray = get_function<PFNGLISVERTEXARRAYPROC>("glIsVertexArray")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_version_3_1()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glDrawArraysInstanced = get_function<PFNGLDRAWARRAYSINSTANCEDPROC>("glDrawArraysInstanced")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDrawElementsInstanced = get_function<PFNGLDRAWELEMENTSINSTANCEDPROC>("glDrawElementsInstanced")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTexBuffer = get_function<PFNGLTEXBUFFERPROC>("glTexBuffer")) != nullptr;
    result = result && (framework::graphics::opengl::details::glPrimitiveRestartIndex = get_function<PFNGLPRIMITIVERESTARTINDEXPROC>("glPrimitiveRestartIndex")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCopyBufferSubData = get_function<PFNGLCOPYBUFFERSUBDATAPROC>("glCopyBufferSubData")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetUniformIndices = get_function<PFNGLGETUNIFORMINDICESPROC>("glGetUniformIndices")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetActiveUniformsiv = get_function<PFNGLGETACTIVEUNIFORMSIVPROC>("glGetActiveUniformsiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetActiveUniformName = get_function<PFNGLGETACTIVEUNIFORMNAMEPROC>("glGetActiveUniformName")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetUniformBlockIndex = get_function<PFNGLGETUNIFORMBLOCKINDEXPROC>("glGetUniformBlockIndex")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetActiveUniformBlockiv = get_function<PFNGLGETACTIVEUNIFORMBLOCKIVPROC>("glGetActiveUniformBlockiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetActiveUniformBlockName = get_function<PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC>("glGetActiveUniformBlockName")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniformBlockBinding = get_function<PFNGLUNIFORMBLOCKBINDINGPROC>("glUniformBlockBinding")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_version_3_2()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glDrawElementsBaseVertex = get_function<PFNGLDRAWELEMENTSBASEVERTEXPROC>("glDrawElementsBaseVertex")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDrawRangeElementsBaseVertex = get_function<PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC>("glDrawRangeElementsBaseVertex")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDrawElementsInstancedBaseVertex = get_function<PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC>("glDrawElementsInstancedBaseVertex")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMultiDrawElementsBaseVertex = get_function<PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC>("glMultiDrawElementsBaseVertex")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProvokingVertex = get_function<PFNGLPROVOKINGVERTEXPROC>("glProvokingVertex")) != nullptr;
    result = result && (framework::graphics::opengl::details::glFenceSync = get_function<PFNGLFENCESYNCPROC>("glFenceSync")) != nullptr;
    result = result && (framework::graphics::opengl::details::glIsSync = get_function<PFNGLISSYNCPROC>("glIsSync")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDeleteSync = get_function<PFNGLDELETESYNCPROC>("glDeleteSync")) != nullptr;
    result = result && (framework::graphics::opengl::details::glClientWaitSync = get_function<PFNGLCLIENTWAITSYNCPROC>("glClientWaitSync")) != nullptr;
    result = result && (framework::graphics::opengl::details::glWaitSync = get_function<PFNGLWAITSYNCPROC>("glWaitSync")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetInteger64v = get_function<PFNGLGETINTEGER64VPROC>("glGetInteger64v")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetSynciv = get_function<PFNGLGETSYNCIVPROC>("glGetSynciv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetInteger64i_v = get_function<PFNGLGETINTEGER64I_VPROC>("glGetInteger64i_v")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetBufferParameteri64v = get_function<PFNGLGETBUFFERPARAMETERI64VPROC>("glGetBufferParameteri64v")) != nullptr;
    result = result && (framework::graphics::opengl::details::glFramebufferTexture = get_function<PFNGLFRAMEBUFFERTEXTUREPROC>("glFramebufferTexture")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTexImage2DMultisample = get_function<PFNGLTEXIMAGE2DMULTISAMPLEPROC>("glTexImage2DMultisample")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTexImage3DMultisample = get_function<PFNGLTEXIMAGE3DMULTISAMPLEPROC>("glTexImage3DMultisample")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetMultisamplefv = get_function<PFNGLGETMULTISAMPLEFVPROC>("glGetMultisamplefv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glSampleMaski = get_function<PFNGLSAMPLEMASKIPROC>("glSampleMaski")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_version_3_3()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glBindFragDataLocationIndexed = get_function<PFNGLBINDFRAGDATALOCATIONINDEXEDPROC>("glBindFragDataLocationIndexed")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetFragDataIndex = get_function<PFNGLGETFRAGDATAINDEXPROC>("glGetFragDataIndex")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGenSamplers = get_function<PFNGLGENSAMPLERSPROC>("glGenSamplers")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDeleteSamplers = get_function<PFNGLDELETESAMPLERSPROC>("glDeleteSamplers")) != nullptr;
    result = result && (framework::graphics::opengl::details::glIsSampler = get_function<PFNGLISSAMPLERPROC>("glIsSampler")) != nullptr;
    result = result && (framework::graphics::opengl::details::glBindSampler = get_function<PFNGLBINDSAMPLERPROC>("glBindSampler")) != nullptr;
    result = result && (framework::graphics::opengl::details::glSamplerParameteri = get_function<PFNGLSAMPLERPARAMETERIPROC>("glSamplerParameteri")) != nullptr;
    result = result && (framework::graphics::opengl::details::glSamplerParameteriv = get_function<PFNGLSAMPLERPARAMETERIVPROC>("glSamplerParameteriv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glSamplerParameterf = get_function<PFNGLSAMPLERPARAMETERFPROC>("glSamplerParameterf")) != nullptr;
    result = result && (framework::graphics::opengl::details::glSamplerParameterfv = get_function<PFNGLSAMPLERPARAMETERFVPROC>("glSamplerParameterfv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glSamplerParameterIiv = get_function<PFNGLSAMPLERPARAMETERIIVPROC>("glSamplerParameterIiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glSamplerParameterIuiv = get_function<PFNGLSAMPLERPARAMETERIUIVPROC>("glSamplerParameterIuiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetSamplerParameteriv = get_function<PFNGLGETSAMPLERPARAMETERIVPROC>("glGetSamplerParameteriv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetSamplerParameterIiv = get_function<PFNGLGETSAMPLERPARAMETERIIVPROC>("glGetSamplerParameterIiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetSamplerParameterfv = get_function<PFNGLGETSAMPLERPARAMETERFVPROC>("glGetSamplerParameterfv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetSamplerParameterIuiv = get_function<PFNGLGETSAMPLERPARAMETERIUIVPROC>("glGetSamplerParameterIuiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glQueryCounter = get_function<PFNGLQUERYCOUNTERPROC>("glQueryCounter")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetQueryObjecti64v = get_function<PFNGLGETQUERYOBJECTI64VPROC>("glGetQueryObjecti64v")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetQueryObjectui64v = get_function<PFNGLGETQUERYOBJECTUI64VPROC>("glGetQueryObjectui64v")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribDivisor = get_function<PFNGLVERTEXATTRIBDIVISORPROC>("glVertexAttribDivisor")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribP1ui = get_function<PFNGLVERTEXATTRIBP1UIPROC>("glVertexAttribP1ui")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribP1uiv = get_function<PFNGLVERTEXATTRIBP1UIVPROC>("glVertexAttribP1uiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribP2ui = get_function<PFNGLVERTEXATTRIBP2UIPROC>("glVertexAttribP2ui")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribP2uiv = get_function<PFNGLVERTEXATTRIBP2UIVPROC>("glVertexAttribP2uiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribP3ui = get_function<PFNGLVERTEXATTRIBP3UIPROC>("glVertexAttribP3ui")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribP3uiv = get_function<PFNGLVERTEXATTRIBP3UIVPROC>("glVertexAttribP3uiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribP4ui = get_function<PFNGLVERTEXATTRIBP4UIPROC>("glVertexAttribP4ui")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribP4uiv = get_function<PFNGLVERTEXATTRIBP4UIVPROC>("glVertexAttribP4uiv")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_version_4_0()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glMinSampleShading = get_function<PFNGLMINSAMPLESHADINGPROC>("glMinSampleShading")) != nullptr;
    result = result && (framework::graphics::opengl::details::glBlendEquationi = get_function<PFNGLBLENDEQUATIONIPROC>("glBlendEquationi")) != nullptr;
    result = result && (framework::graphics::opengl::details::glBlendEquationSeparatei = get_function<PFNGLBLENDEQUATIONSEPARATEIPROC>("glBlendEquationSeparatei")) != nullptr;
    result = result && (framework::graphics::opengl::details::glBlendFunci = get_function<PFNGLBLENDFUNCIPROC>("glBlendFunci")) != nullptr;
    result = result && (framework::graphics::opengl::details::glBlendFuncSeparatei = get_function<PFNGLBLENDFUNCSEPARATEIPROC>("glBlendFuncSeparatei")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDrawArraysIndirect = get_function<PFNGLDRAWARRAYSINDIRECTPROC>("glDrawArraysIndirect")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDrawElementsIndirect = get_function<PFNGLDRAWELEMENTSINDIRECTPROC>("glDrawElementsIndirect")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform1d = get_function<PFNGLUNIFORM1DPROC>("glUniform1d")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform2d = get_function<PFNGLUNIFORM2DPROC>("glUniform2d")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform3d = get_function<PFNGLUNIFORM3DPROC>("glUniform3d")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform4d = get_function<PFNGLUNIFORM4DPROC>("glUniform4d")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform1dv = get_function<PFNGLUNIFORM1DVPROC>("glUniform1dv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform2dv = get_function<PFNGLUNIFORM2DVPROC>("glUniform2dv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform3dv = get_function<PFNGLUNIFORM3DVPROC>("glUniform3dv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform4dv = get_function<PFNGLUNIFORM4DVPROC>("glUniform4dv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniformMatrix2dv = get_function<PFNGLUNIFORMMATRIX2DVPROC>("glUniformMatrix2dv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniformMatrix3dv = get_function<PFNGLUNIFORMMATRIX3DVPROC>("glUniformMatrix3dv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniformMatrix4dv = get_function<PFNGLUNIFORMMATRIX4DVPROC>("glUniformMatrix4dv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniformMatrix2x3dv = get_function<PFNGLUNIFORMMATRIX2X3DVPROC>("glUniformMatrix2x3dv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniformMatrix2x4dv = get_function<PFNGLUNIFORMMATRIX2X4DVPROC>("glUniformMatrix2x4dv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniformMatrix3x2dv = get_function<PFNGLUNIFORMMATRIX3X2DVPROC>("glUniformMatrix3x2dv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniformMatrix3x4dv = get_function<PFNGLUNIFORMMATRIX3X4DVPROC>("glUniformMatrix3x4dv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniformMatrix4x2dv = get_function<PFNGLUNIFORMMATRIX4X2DVPROC>("glUniformMatrix4x2dv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniformMatrix4x3dv = get_function<PFNGLUNIFORMMATRIX4X3DVPROC>("glUniformMatrix4x3dv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetUniformdv = get_function<PFNGLGETUNIFORMDVPROC>("glGetUniformdv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetSubroutineUniformLocation = get_function<PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC>("glGetSubroutineUniformLocation")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetSubroutineIndex = get_function<PFNGLGETSUBROUTINEINDEXPROC>("glGetSubroutineIndex")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetActiveSubroutineUniformiv = get_function<PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC>("glGetActiveSubroutineUniformiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetActiveSubroutineUniformName = get_function<PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC>("glGetActiveSubroutineUniformName")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetActiveSubroutineName = get_function<PFNGLGETACTIVESUBROUTINENAMEPROC>("glGetActiveSubroutineName")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniformSubroutinesuiv = get_function<PFNGLUNIFORMSUBROUTINESUIVPROC>("glUniformSubroutinesuiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetUniformSubroutineuiv = get_function<PFNGLGETUNIFORMSUBROUTINEUIVPROC>("glGetUniformSubroutineuiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetProgramStageiv = get_function<PFNGLGETPROGRAMSTAGEIVPROC>("glGetProgramStageiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glPatchParameteri = get_function<PFNGLPATCHPARAMETERIPROC>("glPatchParameteri")) != nullptr;
    result = result && (framework::graphics::opengl::details::glPatchParameterfv = get_function<PFNGLPATCHPARAMETERFVPROC>("glPatchParameterfv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glBindTransformFeedback = get_function<PFNGLBINDTRANSFORMFEEDBACKPROC>("glBindTransformFeedback")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDeleteTransformFeedbacks = get_function<PFNGLDELETETRANSFORMFEEDBACKSPROC>("glDeleteTransformFeedbacks")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGenTransformFeedbacks = get_function<PFNGLGENTRANSFORMFEEDBACKSPROC>("glGenTransformFeedbacks")) != nullptr;
    result = result && (framework::graphics::opengl::details::glIsTransformFeedback = get_function<PFNGLISTRANSFORMFEEDBACKPROC>("glIsTransformFeedback")) != nullptr;
    result = result && (framework::graphics::opengl::details::glPauseTransformFeedback = get_function<PFNGLPAUSETRANSFORMFEEDBACKPROC>("glPauseTransformFeedback")) != nullptr;
    result = result && (framework::graphics::opengl::details::glResumeTransformFeedback = get_function<PFNGLRESUMETRANSFORMFEEDBACKPROC>("glResumeTransformFeedback")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDrawTransformFeedback = get_function<PFNGLDRAWTRANSFORMFEEDBACKPROC>("glDrawTransformFeedback")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDrawTransformFeedbackStream = get_function<PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC>("glDrawTransformFeedbackStream")) != nullptr;
    result = result && (framework::graphics::opengl::details::glBeginQueryIndexed = get_function<PFNGLBEGINQUERYINDEXEDPROC>("glBeginQueryIndexed")) != nullptr;
    result = result && (framework::graphics::opengl::details::glEndQueryIndexed = get_function<PFNGLENDQUERYINDEXEDPROC>("glEndQueryIndexed")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetQueryIndexediv = get_function<PFNGLGETQUERYINDEXEDIVPROC>("glGetQueryIndexediv")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_version_4_1()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glReleaseShaderCompiler = get_function<PFNGLRELEASESHADERCOMPILERPROC>("glReleaseShaderCompiler")) != nullptr;
    result = result && (framework::graphics::opengl::details::glShaderBinary = get_function<PFNGLSHADERBINARYPROC>("glShaderBinary")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetShaderPrecisionFormat = get_function<PFNGLGETSHADERPRECISIONFORMATPROC>("glGetShaderPrecisionFormat")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDepthRangef = get_function<PFNGLDEPTHRANGEFPROC>("glDepthRangef")) != nullptr;
    result = result && (framework::graphics::opengl::details::glClearDepthf = get_function<PFNGLCLEARDEPTHFPROC>("glClearDepthf")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetProgramBinary = get_function<PFNGLGETPROGRAMBINARYPROC>("glGetProgramBinary")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramBinary = get_function<PFNGLPROGRAMBINARYPROC>("glProgramBinary")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramParameteri = get_function<PFNGLPROGRAMPARAMETERIPROC>("glProgramParameteri")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUseProgramStages = get_function<PFNGLUSEPROGRAMSTAGESPROC>("glUseProgramStages")) != nullptr;
    result = result && (framework::graphics::opengl::details::glActiveShaderProgram = get_function<PFNGLACTIVESHADERPROGRAMPROC>("glActiveShaderProgram")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCreateShaderProgramv = get_function<PFNGLCREATESHADERPROGRAMVPROC>("glCreateShaderProgramv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glBindProgramPipeline = get_function<PFNGLBINDPROGRAMPIPELINEPROC>("glBindProgramPipeline")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDeleteProgramPipelines = get_function<PFNGLDELETEPROGRAMPIPELINESPROC>("glDeleteProgramPipelines")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGenProgramPipelines = get_function<PFNGLGENPROGRAMPIPELINESPROC>("glGenProgramPipelines")) != nullptr;
    result = result && (framework::graphics::opengl::details::glIsProgramPipeline = get_function<PFNGLISPROGRAMPIPELINEPROC>("glIsProgramPipeline")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetProgramPipelineiv = get_function<PFNGLGETPROGRAMPIPELINEIVPROC>("glGetProgramPipelineiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform1i = get_function<PFNGLPROGRAMUNIFORM1IPROC>("glProgramUniform1i")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform1iv = get_function<PFNGLPROGRAMUNIFORM1IVPROC>("glProgramUniform1iv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform1f = get_function<PFNGLPROGRAMUNIFORM1FPROC>("glProgramUniform1f")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform1fv = get_function<PFNGLPROGRAMUNIFORM1FVPROC>("glProgramUniform1fv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform1d = get_function<PFNGLPROGRAMUNIFORM1DPROC>("glProgramUniform1d")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform1dv = get_function<PFNGLPROGRAMUNIFORM1DVPROC>("glProgramUniform1dv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform1ui = get_function<PFNGLPROGRAMUNIFORM1UIPROC>("glProgramUniform1ui")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform1uiv = get_function<PFNGLPROGRAMUNIFORM1UIVPROC>("glProgramUniform1uiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform2i = get_function<PFNGLPROGRAMUNIFORM2IPROC>("glProgramUniform2i")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform2iv = get_function<PFNGLPROGRAMUNIFORM2IVPROC>("glProgramUniform2iv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform2f = get_function<PFNGLPROGRAMUNIFORM2FPROC>("glProgramUniform2f")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform2fv = get_function<PFNGLPROGRAMUNIFORM2FVPROC>("glProgramUniform2fv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform2d = get_function<PFNGLPROGRAMUNIFORM2DPROC>("glProgramUniform2d")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform2dv = get_function<PFNGLPROGRAMUNIFORM2DVPROC>("glProgramUniform2dv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform2ui = get_function<PFNGLPROGRAMUNIFORM2UIPROC>("glProgramUniform2ui")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform2uiv = get_function<PFNGLPROGRAMUNIFORM2UIVPROC>("glProgramUniform2uiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform3i = get_function<PFNGLPROGRAMUNIFORM3IPROC>("glProgramUniform3i")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform3iv = get_function<PFNGLPROGRAMUNIFORM3IVPROC>("glProgramUniform3iv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform3f = get_function<PFNGLPROGRAMUNIFORM3FPROC>("glProgramUniform3f")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform3fv = get_function<PFNGLPROGRAMUNIFORM3FVPROC>("glProgramUniform3fv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform3d = get_function<PFNGLPROGRAMUNIFORM3DPROC>("glProgramUniform3d")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform3dv = get_function<PFNGLPROGRAMUNIFORM3DVPROC>("glProgramUniform3dv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform3ui = get_function<PFNGLPROGRAMUNIFORM3UIPROC>("glProgramUniform3ui")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform3uiv = get_function<PFNGLPROGRAMUNIFORM3UIVPROC>("glProgramUniform3uiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform4i = get_function<PFNGLPROGRAMUNIFORM4IPROC>("glProgramUniform4i")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform4iv = get_function<PFNGLPROGRAMUNIFORM4IVPROC>("glProgramUniform4iv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform4f = get_function<PFNGLPROGRAMUNIFORM4FPROC>("glProgramUniform4f")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform4fv = get_function<PFNGLPROGRAMUNIFORM4FVPROC>("glProgramUniform4fv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform4d = get_function<PFNGLPROGRAMUNIFORM4DPROC>("glProgramUniform4d")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform4dv = get_function<PFNGLPROGRAMUNIFORM4DVPROC>("glProgramUniform4dv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform4ui = get_function<PFNGLPROGRAMUNIFORM4UIPROC>("glProgramUniform4ui")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform4uiv = get_function<PFNGLPROGRAMUNIFORM4UIVPROC>("glProgramUniform4uiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniformMatrix2fv = get_function<PFNGLPROGRAMUNIFORMMATRIX2FVPROC>("glProgramUniformMatrix2fv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniformMatrix3fv = get_function<PFNGLPROGRAMUNIFORMMATRIX3FVPROC>("glProgramUniformMatrix3fv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniformMatrix4fv = get_function<PFNGLPROGRAMUNIFORMMATRIX4FVPROC>("glProgramUniformMatrix4fv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniformMatrix2dv = get_function<PFNGLPROGRAMUNIFORMMATRIX2DVPROC>("glProgramUniformMatrix2dv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniformMatrix3dv = get_function<PFNGLPROGRAMUNIFORMMATRIX3DVPROC>("glProgramUniformMatrix3dv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniformMatrix4dv = get_function<PFNGLPROGRAMUNIFORMMATRIX4DVPROC>("glProgramUniformMatrix4dv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniformMatrix2x3fv = get_function<PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC>("glProgramUniformMatrix2x3fv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniformMatrix3x2fv = get_function<PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC>("glProgramUniformMatrix3x2fv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniformMatrix2x4fv = get_function<PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC>("glProgramUniformMatrix2x4fv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniformMatrix4x2fv = get_function<PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC>("glProgramUniformMatrix4x2fv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniformMatrix3x4fv = get_function<PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC>("glProgramUniformMatrix3x4fv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniformMatrix4x3fv = get_function<PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC>("glProgramUniformMatrix4x3fv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniformMatrix2x3dv = get_function<PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC>("glProgramUniformMatrix2x3dv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniformMatrix3x2dv = get_function<PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC>("glProgramUniformMatrix3x2dv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniformMatrix2x4dv = get_function<PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC>("glProgramUniformMatrix2x4dv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniformMatrix4x2dv = get_function<PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC>("glProgramUniformMatrix4x2dv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniformMatrix3x4dv = get_function<PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC>("glProgramUniformMatrix3x4dv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniformMatrix4x3dv = get_function<PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC>("glProgramUniformMatrix4x3dv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glValidateProgramPipeline = get_function<PFNGLVALIDATEPROGRAMPIPELINEPROC>("glValidateProgramPipeline")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetProgramPipelineInfoLog = get_function<PFNGLGETPROGRAMPIPELINEINFOLOGPROC>("glGetProgramPipelineInfoLog")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribL1d = get_function<PFNGLVERTEXATTRIBL1DPROC>("glVertexAttribL1d")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribL2d = get_function<PFNGLVERTEXATTRIBL2DPROC>("glVertexAttribL2d")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribL3d = get_function<PFNGLVERTEXATTRIBL3DPROC>("glVertexAttribL3d")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribL4d = get_function<PFNGLVERTEXATTRIBL4DPROC>("glVertexAttribL4d")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribL1dv = get_function<PFNGLVERTEXATTRIBL1DVPROC>("glVertexAttribL1dv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribL2dv = get_function<PFNGLVERTEXATTRIBL2DVPROC>("glVertexAttribL2dv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribL3dv = get_function<PFNGLVERTEXATTRIBL3DVPROC>("glVertexAttribL3dv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribL4dv = get_function<PFNGLVERTEXATTRIBL4DVPROC>("glVertexAttribL4dv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribLPointer = get_function<PFNGLVERTEXATTRIBLPOINTERPROC>("glVertexAttribLPointer")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetVertexAttribLdv = get_function<PFNGLGETVERTEXATTRIBLDVPROC>("glGetVertexAttribLdv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glViewportArrayv = get_function<PFNGLVIEWPORTARRAYVPROC>("glViewportArrayv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glViewportIndexedf = get_function<PFNGLVIEWPORTINDEXEDFPROC>("glViewportIndexedf")) != nullptr;
    result = result && (framework::graphics::opengl::details::glViewportIndexedfv = get_function<PFNGLVIEWPORTINDEXEDFVPROC>("glViewportIndexedfv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glScissorArrayv = get_function<PFNGLSCISSORARRAYVPROC>("glScissorArrayv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glScissorIndexed = get_function<PFNGLSCISSORINDEXEDPROC>("glScissorIndexed")) != nullptr;
    result = result && (framework::graphics::opengl::details::glScissorIndexedv = get_function<PFNGLSCISSORINDEXEDVPROC>("glScissorIndexedv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDepthRangeArrayv = get_function<PFNGLDEPTHRANGEARRAYVPROC>("glDepthRangeArrayv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDepthRangeIndexed = get_function<PFNGLDEPTHRANGEINDEXEDPROC>("glDepthRangeIndexed")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetFloati_v = get_function<PFNGLGETFLOATI_VPROC>("glGetFloati_v")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetDoublei_v = get_function<PFNGLGETDOUBLEI_VPROC>("glGetDoublei_v")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_version_4_2()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glDrawArraysInstancedBaseInstance = get_function<PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC>("glDrawArraysInstancedBaseInstance")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDrawElementsInstancedBaseInstance = get_function<PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC>("glDrawElementsInstancedBaseInstance")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDrawElementsInstancedBaseVertexBaseInstance = get_function<PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC>("glDrawElementsInstancedBaseVertexBaseInstance")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetInternalformativ = get_function<PFNGLGETINTERNALFORMATIVPROC>("glGetInternalformativ")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetActiveAtomicCounterBufferiv = get_function<PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC>("glGetActiveAtomicCounterBufferiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glBindImageTexture = get_function<PFNGLBINDIMAGETEXTUREPROC>("glBindImageTexture")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMemoryBarrier = get_function<PFNGLMEMORYBARRIERPROC>("glMemoryBarrier")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTexStorage1D = get_function<PFNGLTEXSTORAGE1DPROC>("glTexStorage1D")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTexStorage2D = get_function<PFNGLTEXSTORAGE2DPROC>("glTexStorage2D")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTexStorage3D = get_function<PFNGLTEXSTORAGE3DPROC>("glTexStorage3D")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDrawTransformFeedbackInstanced = get_function<PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC>("glDrawTransformFeedbackInstanced")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDrawTransformFeedbackStreamInstanced = get_function<PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC>("glDrawTransformFeedbackStreamInstanced")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_version_4_3()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glClearBufferData = get_function<PFNGLCLEARBUFFERDATAPROC>("glClearBufferData")) != nullptr;
    result = result && (framework::graphics::opengl::details::glClearBufferSubData = get_function<PFNGLCLEARBUFFERSUBDATAPROC>("glClearBufferSubData")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDispatchCompute = get_function<PFNGLDISPATCHCOMPUTEPROC>("glDispatchCompute")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDispatchComputeIndirect = get_function<PFNGLDISPATCHCOMPUTEINDIRECTPROC>("glDispatchComputeIndirect")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCopyImageSubData = get_function<PFNGLCOPYIMAGESUBDATAPROC>("glCopyImageSubData")) != nullptr;
    result = result && (framework::graphics::opengl::details::glFramebufferParameteri = get_function<PFNGLFRAMEBUFFERPARAMETERIPROC>("glFramebufferParameteri")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetFramebufferParameteriv = get_function<PFNGLGETFRAMEBUFFERPARAMETERIVPROC>("glGetFramebufferParameteriv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetInternalformati64v = get_function<PFNGLGETINTERNALFORMATI64VPROC>("glGetInternalformati64v")) != nullptr;
    result = result && (framework::graphics::opengl::details::glInvalidateTexSubImage = get_function<PFNGLINVALIDATETEXSUBIMAGEPROC>("glInvalidateTexSubImage")) != nullptr;
    result = result && (framework::graphics::opengl::details::glInvalidateTexImage = get_function<PFNGLINVALIDATETEXIMAGEPROC>("glInvalidateTexImage")) != nullptr;
    result = result && (framework::graphics::opengl::details::glInvalidateBufferSubData = get_function<PFNGLINVALIDATEBUFFERSUBDATAPROC>("glInvalidateBufferSubData")) != nullptr;
    result = result && (framework::graphics::opengl::details::glInvalidateBufferData = get_function<PFNGLINVALIDATEBUFFERDATAPROC>("glInvalidateBufferData")) != nullptr;
    result = result && (framework::graphics::opengl::details::glInvalidateFramebuffer = get_function<PFNGLINVALIDATEFRAMEBUFFERPROC>("glInvalidateFramebuffer")) != nullptr;
    result = result && (framework::graphics::opengl::details::glInvalidateSubFramebuffer = get_function<PFNGLINVALIDATESUBFRAMEBUFFERPROC>("glInvalidateSubFramebuffer")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMultiDrawArraysIndirect = get_function<PFNGLMULTIDRAWARRAYSINDIRECTPROC>("glMultiDrawArraysIndirect")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMultiDrawElementsIndirect = get_function<PFNGLMULTIDRAWELEMENTSINDIRECTPROC>("glMultiDrawElementsIndirect")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetProgramInterfaceiv = get_function<PFNGLGETPROGRAMINTERFACEIVPROC>("glGetProgramInterfaceiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetProgramResourceIndex = get_function<PFNGLGETPROGRAMRESOURCEINDEXPROC>("glGetProgramResourceIndex")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetProgramResourceName = get_function<PFNGLGETPROGRAMRESOURCENAMEPROC>("glGetProgramResourceName")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetProgramResourceiv = get_function<PFNGLGETPROGRAMRESOURCEIVPROC>("glGetProgramResourceiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetProgramResourceLocation = get_function<PFNGLGETPROGRAMRESOURCELOCATIONPROC>("glGetProgramResourceLocation")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetProgramResourceLocationIndex = get_function<PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC>("glGetProgramResourceLocationIndex")) != nullptr;
    result = result && (framework::graphics::opengl::details::glShaderStorageBlockBinding = get_function<PFNGLSHADERSTORAGEBLOCKBINDINGPROC>("glShaderStorageBlockBinding")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTexBufferRange = get_function<PFNGLTEXBUFFERRANGEPROC>("glTexBufferRange")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTexStorage2DMultisample = get_function<PFNGLTEXSTORAGE2DMULTISAMPLEPROC>("glTexStorage2DMultisample")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTexStorage3DMultisample = get_function<PFNGLTEXSTORAGE3DMULTISAMPLEPROC>("glTexStorage3DMultisample")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTextureView = get_function<PFNGLTEXTUREVIEWPROC>("glTextureView")) != nullptr;
    result = result && (framework::graphics::opengl::details::glBindVertexBuffer = get_function<PFNGLBINDVERTEXBUFFERPROC>("glBindVertexBuffer")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribFormat = get_function<PFNGLVERTEXATTRIBFORMATPROC>("glVertexAttribFormat")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribIFormat = get_function<PFNGLVERTEXATTRIBIFORMATPROC>("glVertexAttribIFormat")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribLFormat = get_function<PFNGLVERTEXATTRIBLFORMATPROC>("glVertexAttribLFormat")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribBinding = get_function<PFNGLVERTEXATTRIBBINDINGPROC>("glVertexAttribBinding")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexBindingDivisor = get_function<PFNGLVERTEXBINDINGDIVISORPROC>("glVertexBindingDivisor")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDebugMessageControl = get_function<PFNGLDEBUGMESSAGECONTROLPROC>("glDebugMessageControl")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDebugMessageInsert = get_function<PFNGLDEBUGMESSAGEINSERTPROC>("glDebugMessageInsert")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDebugMessageCallback = get_function<PFNGLDEBUGMESSAGECALLBACKPROC>("glDebugMessageCallback")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetDebugMessageLog = get_function<PFNGLGETDEBUGMESSAGELOGPROC>("glGetDebugMessageLog")) != nullptr;
    result = result && (framework::graphics::opengl::details::glPushDebugGroup = get_function<PFNGLPUSHDEBUGGROUPPROC>("glPushDebugGroup")) != nullptr;
    result = result && (framework::graphics::opengl::details::glPopDebugGroup = get_function<PFNGLPOPDEBUGGROUPPROC>("glPopDebugGroup")) != nullptr;
    result = result && (framework::graphics::opengl::details::glObjectLabel = get_function<PFNGLOBJECTLABELPROC>("glObjectLabel")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetObjectLabel = get_function<PFNGLGETOBJECTLABELPROC>("glGetObjectLabel")) != nullptr;
    result = result && (framework::graphics::opengl::details::glObjectPtrLabel = get_function<PFNGLOBJECTPTRLABELPROC>("glObjectPtrLabel")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetObjectPtrLabel = get_function<PFNGLGETOBJECTPTRLABELPROC>("glGetObjectPtrLabel")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_version_4_4()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glBufferStorage = get_function<PFNGLBUFFERSTORAGEPROC>("glBufferStorage")) != nullptr;
    result = result && (framework::graphics::opengl::details::glClearTexImage = get_function<PFNGLCLEARTEXIMAGEPROC>("glClearTexImage")) != nullptr;
    result = result && (framework::graphics::opengl::details::glClearTexSubImage = get_function<PFNGLCLEARTEXSUBIMAGEPROC>("glClearTexSubImage")) != nullptr;
    result = result && (framework::graphics::opengl::details::glBindBuffersBase = get_function<PFNGLBINDBUFFERSBASEPROC>("glBindBuffersBase")) != nullptr;
    result = result && (framework::graphics::opengl::details::glBindBuffersRange = get_function<PFNGLBINDBUFFERSRANGEPROC>("glBindBuffersRange")) != nullptr;
    result = result && (framework::graphics::opengl::details::glBindTextures = get_function<PFNGLBINDTEXTURESPROC>("glBindTextures")) != nullptr;
    result = result && (framework::graphics::opengl::details::glBindSamplers = get_function<PFNGLBINDSAMPLERSPROC>("glBindSamplers")) != nullptr;
    result = result && (framework::graphics::opengl::details::glBindImageTextures = get_function<PFNGLBINDIMAGETEXTURESPROC>("glBindImageTextures")) != nullptr;
    result = result && (framework::graphics::opengl::details::glBindVertexBuffers = get_function<PFNGLBINDVERTEXBUFFERSPROC>("glBindVertexBuffers")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_version_4_5()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glClipControl = get_function<PFNGLCLIPCONTROLPROC>("glClipControl")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCreateTransformFeedbacks = get_function<PFNGLCREATETRANSFORMFEEDBACKSPROC>("glCreateTransformFeedbacks")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTransformFeedbackBufferBase = get_function<PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC>("glTransformFeedbackBufferBase")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTransformFeedbackBufferRange = get_function<PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC>("glTransformFeedbackBufferRange")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetTransformFeedbackiv = get_function<PFNGLGETTRANSFORMFEEDBACKIVPROC>("glGetTransformFeedbackiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetTransformFeedbacki_v = get_function<PFNGLGETTRANSFORMFEEDBACKI_VPROC>("glGetTransformFeedbacki_v")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetTransformFeedbacki64_v = get_function<PFNGLGETTRANSFORMFEEDBACKI64_VPROC>("glGetTransformFeedbacki64_v")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCreateBuffers = get_function<PFNGLCREATEBUFFERSPROC>("glCreateBuffers")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedBufferStorage = get_function<PFNGLNAMEDBUFFERSTORAGEPROC>("glNamedBufferStorage")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedBufferData = get_function<PFNGLNAMEDBUFFERDATAPROC>("glNamedBufferData")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedBufferSubData = get_function<PFNGLNAMEDBUFFERSUBDATAPROC>("glNamedBufferSubData")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCopyNamedBufferSubData = get_function<PFNGLCOPYNAMEDBUFFERSUBDATAPROC>("glCopyNamedBufferSubData")) != nullptr;
    result = result && (framework::graphics::opengl::details::glClearNamedBufferData = get_function<PFNGLCLEARNAMEDBUFFERDATAPROC>("glClearNamedBufferData")) != nullptr;
    result = result && (framework::graphics::opengl::details::glClearNamedBufferSubData = get_function<PFNGLCLEARNAMEDBUFFERSUBDATAPROC>("glClearNamedBufferSubData")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMapNamedBuffer = get_function<PFNGLMAPNAMEDBUFFERPROC>("glMapNamedBuffer")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMapNamedBufferRange = get_function<PFNGLMAPNAMEDBUFFERRANGEPROC>("glMapNamedBufferRange")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUnmapNamedBuffer = get_function<PFNGLUNMAPNAMEDBUFFERPROC>("glUnmapNamedBuffer")) != nullptr;
    result = result && (framework::graphics::opengl::details::glFlushMappedNamedBufferRange = get_function<PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC>("glFlushMappedNamedBufferRange")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetNamedBufferParameteriv = get_function<PFNGLGETNAMEDBUFFERPARAMETERIVPROC>("glGetNamedBufferParameteriv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetNamedBufferParameteri64v = get_function<PFNGLGETNAMEDBUFFERPARAMETERI64VPROC>("glGetNamedBufferParameteri64v")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetNamedBufferPointerv = get_function<PFNGLGETNAMEDBUFFERPOINTERVPROC>("glGetNamedBufferPointerv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetNamedBufferSubData = get_function<PFNGLGETNAMEDBUFFERSUBDATAPROC>("glGetNamedBufferSubData")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCreateFramebuffers = get_function<PFNGLCREATEFRAMEBUFFERSPROC>("glCreateFramebuffers")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedFramebufferRenderbuffer = get_function<PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC>("glNamedFramebufferRenderbuffer")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedFramebufferParameteri = get_function<PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC>("glNamedFramebufferParameteri")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedFramebufferTexture = get_function<PFNGLNAMEDFRAMEBUFFERTEXTUREPROC>("glNamedFramebufferTexture")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedFramebufferTextureLayer = get_function<PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC>("glNamedFramebufferTextureLayer")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedFramebufferDrawBuffer = get_function<PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC>("glNamedFramebufferDrawBuffer")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedFramebufferDrawBuffers = get_function<PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC>("glNamedFramebufferDrawBuffers")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedFramebufferReadBuffer = get_function<PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC>("glNamedFramebufferReadBuffer")) != nullptr;
    result = result && (framework::graphics::opengl::details::glInvalidateNamedFramebufferData = get_function<PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC>("glInvalidateNamedFramebufferData")) != nullptr;
    result = result && (framework::graphics::opengl::details::glInvalidateNamedFramebufferSubData = get_function<PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC>("glInvalidateNamedFramebufferSubData")) != nullptr;
    result = result && (framework::graphics::opengl::details::glClearNamedFramebufferiv = get_function<PFNGLCLEARNAMEDFRAMEBUFFERIVPROC>("glClearNamedFramebufferiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glClearNamedFramebufferuiv = get_function<PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC>("glClearNamedFramebufferuiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glClearNamedFramebufferfv = get_function<PFNGLCLEARNAMEDFRAMEBUFFERFVPROC>("glClearNamedFramebufferfv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glClearNamedFramebufferfi = get_function<PFNGLCLEARNAMEDFRAMEBUFFERFIPROC>("glClearNamedFramebufferfi")) != nullptr;
    result = result && (framework::graphics::opengl::details::glBlitNamedFramebuffer = get_function<PFNGLBLITNAMEDFRAMEBUFFERPROC>("glBlitNamedFramebuffer")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCheckNamedFramebufferStatus = get_function<PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC>("glCheckNamedFramebufferStatus")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetNamedFramebufferParameteriv = get_function<PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC>("glGetNamedFramebufferParameteriv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetNamedFramebufferAttachmentParameteriv = get_function<PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC>("glGetNamedFramebufferAttachmentParameteriv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCreateRenderbuffers = get_function<PFNGLCREATERENDERBUFFERSPROC>("glCreateRenderbuffers")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedRenderbufferStorage = get_function<PFNGLNAMEDRENDERBUFFERSTORAGEPROC>("glNamedRenderbufferStorage")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedRenderbufferStorageMultisample = get_function<PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC>("glNamedRenderbufferStorageMultisample")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetNamedRenderbufferParameteriv = get_function<PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC>("glGetNamedRenderbufferParameteriv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCreateTextures = get_function<PFNGLCREATETEXTURESPROC>("glCreateTextures")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTextureBuffer = get_function<PFNGLTEXTUREBUFFERPROC>("glTextureBuffer")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTextureBufferRange = get_function<PFNGLTEXTUREBUFFERRANGEPROC>("glTextureBufferRange")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTextureStorage1D = get_function<PFNGLTEXTURESTORAGE1DPROC>("glTextureStorage1D")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTextureStorage2D = get_function<PFNGLTEXTURESTORAGE2DPROC>("glTextureStorage2D")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTextureStorage3D = get_function<PFNGLTEXTURESTORAGE3DPROC>("glTextureStorage3D")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTextureStorage2DMultisample = get_function<PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC>("glTextureStorage2DMultisample")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTextureStorage3DMultisample = get_function<PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC>("glTextureStorage3DMultisample")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTextureSubImage1D = get_function<PFNGLTEXTURESUBIMAGE1DPROC>("glTextureSubImage1D")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTextureSubImage2D = get_function<PFNGLTEXTURESUBIMAGE2DPROC>("glTextureSubImage2D")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTextureSubImage3D = get_function<PFNGLTEXTURESUBIMAGE3DPROC>("glTextureSubImage3D")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCompressedTextureSubImage1D = get_function<PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC>("glCompressedTextureSubImage1D")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCompressedTextureSubImage2D = get_function<PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC>("glCompressedTextureSubImage2D")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCompressedTextureSubImage3D = get_function<PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC>("glCompressedTextureSubImage3D")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCopyTextureSubImage1D = get_function<PFNGLCOPYTEXTURESUBIMAGE1DPROC>("glCopyTextureSubImage1D")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCopyTextureSubImage2D = get_function<PFNGLCOPYTEXTURESUBIMAGE2DPROC>("glCopyTextureSubImage2D")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCopyTextureSubImage3D = get_function<PFNGLCOPYTEXTURESUBIMAGE3DPROC>("glCopyTextureSubImage3D")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTextureParameterf = get_function<PFNGLTEXTUREPARAMETERFPROC>("glTextureParameterf")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTextureParameterfv = get_function<PFNGLTEXTUREPARAMETERFVPROC>("glTextureParameterfv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTextureParameteri = get_function<PFNGLTEXTUREPARAMETERIPROC>("glTextureParameteri")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTextureParameterIiv = get_function<PFNGLTEXTUREPARAMETERIIVPROC>("glTextureParameterIiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTextureParameterIuiv = get_function<PFNGLTEXTUREPARAMETERIUIVPROC>("glTextureParameterIuiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTextureParameteriv = get_function<PFNGLTEXTUREPARAMETERIVPROC>("glTextureParameteriv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGenerateTextureMipmap = get_function<PFNGLGENERATETEXTUREMIPMAPPROC>("glGenerateTextureMipmap")) != nullptr;
    result = result && (framework::graphics::opengl::details::glBindTextureUnit = get_function<PFNGLBINDTEXTUREUNITPROC>("glBindTextureUnit")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetTextureImage = get_function<PFNGLGETTEXTUREIMAGEPROC>("glGetTextureImage")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetCompressedTextureImage = get_function<PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC>("glGetCompressedTextureImage")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetTextureLevelParameterfv = get_function<PFNGLGETTEXTURELEVELPARAMETERFVPROC>("glGetTextureLevelParameterfv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetTextureLevelParameteriv = get_function<PFNGLGETTEXTURELEVELPARAMETERIVPROC>("glGetTextureLevelParameteriv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetTextureParameterfv = get_function<PFNGLGETTEXTUREPARAMETERFVPROC>("glGetTextureParameterfv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetTextureParameterIiv = get_function<PFNGLGETTEXTUREPARAMETERIIVPROC>("glGetTextureParameterIiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetTextureParameterIuiv = get_function<PFNGLGETTEXTUREPARAMETERIUIVPROC>("glGetTextureParameterIuiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetTextureParameteriv = get_function<PFNGLGETTEXTUREPARAMETERIVPROC>("glGetTextureParameteriv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCreateVertexArrays = get_function<PFNGLCREATEVERTEXARRAYSPROC>("glCreateVertexArrays")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDisableVertexArrayAttrib = get_function<PFNGLDISABLEVERTEXARRAYATTRIBPROC>("glDisableVertexArrayAttrib")) != nullptr;
    result = result && (framework::graphics::opengl::details::glEnableVertexArrayAttrib = get_function<PFNGLENABLEVERTEXARRAYATTRIBPROC>("glEnableVertexArrayAttrib")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexArrayElementBuffer = get_function<PFNGLVERTEXARRAYELEMENTBUFFERPROC>("glVertexArrayElementBuffer")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexArrayVertexBuffer = get_function<PFNGLVERTEXARRAYVERTEXBUFFERPROC>("glVertexArrayVertexBuffer")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexArrayVertexBuffers = get_function<PFNGLVERTEXARRAYVERTEXBUFFERSPROC>("glVertexArrayVertexBuffers")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexArrayAttribBinding = get_function<PFNGLVERTEXARRAYATTRIBBINDINGPROC>("glVertexArrayAttribBinding")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexArrayAttribFormat = get_function<PFNGLVERTEXARRAYATTRIBFORMATPROC>("glVertexArrayAttribFormat")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexArrayAttribIFormat = get_function<PFNGLVERTEXARRAYATTRIBIFORMATPROC>("glVertexArrayAttribIFormat")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexArrayAttribLFormat = get_function<PFNGLVERTEXARRAYATTRIBLFORMATPROC>("glVertexArrayAttribLFormat")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexArrayBindingDivisor = get_function<PFNGLVERTEXARRAYBINDINGDIVISORPROC>("glVertexArrayBindingDivisor")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetVertexArrayiv = get_function<PFNGLGETVERTEXARRAYIVPROC>("glGetVertexArrayiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetVertexArrayIndexediv = get_function<PFNGLGETVERTEXARRAYINDEXEDIVPROC>("glGetVertexArrayIndexediv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetVertexArrayIndexed64iv = get_function<PFNGLGETVERTEXARRAYINDEXED64IVPROC>("glGetVertexArrayIndexed64iv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCreateSamplers = get_function<PFNGLCREATESAMPLERSPROC>("glCreateSamplers")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCreateProgramPipelines = get_function<PFNGLCREATEPROGRAMPIPELINESPROC>("glCreateProgramPipelines")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCreateQueries = get_function<PFNGLCREATEQUERIESPROC>("glCreateQueries")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetQueryBufferObjecti64v = get_function<PFNGLGETQUERYBUFFEROBJECTI64VPROC>("glGetQueryBufferObjecti64v")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetQueryBufferObjectiv = get_function<PFNGLGETQUERYBUFFEROBJECTIVPROC>("glGetQueryBufferObjectiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetQueryBufferObjectui64v = get_function<PFNGLGETQUERYBUFFEROBJECTUI64VPROC>("glGetQueryBufferObjectui64v")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetQueryBufferObjectuiv = get_function<PFNGLGETQUERYBUFFEROBJECTUIVPROC>("glGetQueryBufferObjectuiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMemoryBarrierByRegion = get_function<PFNGLMEMORYBARRIERBYREGIONPROC>("glMemoryBarrierByRegion")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetTextureSubImage = get_function<PFNGLGETTEXTURESUBIMAGEPROC>("glGetTextureSubImage")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetCompressedTextureSubImage = get_function<PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC>("glGetCompressedTextureSubImage")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetGraphicsResetStatus = get_function<PFNGLGETGRAPHICSRESETSTATUSPROC>("glGetGraphicsResetStatus")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetnCompressedTexImage = get_function<PFNGLGETNCOMPRESSEDTEXIMAGEPROC>("glGetnCompressedTexImage")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetnTexImage = get_function<PFNGLGETNTEXIMAGEPROC>("glGetnTexImage")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetnUniformdv = get_function<PFNGLGETNUNIFORMDVPROC>("glGetnUniformdv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetnUniformfv = get_function<PFNGLGETNUNIFORMFVPROC>("glGetnUniformfv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetnUniformiv = get_function<PFNGLGETNUNIFORMIVPROC>("glGetnUniformiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetnUniformuiv = get_function<PFNGLGETNUNIFORMUIVPROC>("glGetnUniformuiv")) != nullptr;
    result = result && (framework::graphics::opengl::details::glReadnPixels = get_function<PFNGLREADNPIXELSPROC>("glReadnPixels")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTextureBarrier = get_function<PFNGLTEXTUREBARRIERPROC>("glTextureBarrier")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_version_4_6()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glSpecializeShader = get_function<PFNGLSPECIALIZESHADERPROC>("glSpecializeShader")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMultiDrawArraysIndirectCount = get_function<PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC>("glMultiDrawArraysIndirectCount")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMultiDrawElementsIndirectCount = get_function<PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC>("glMultiDrawElementsIndirectCount")) != nullptr;
    result = result && (framework::graphics::opengl::details::glPolygonOffsetClamp = get_function<PFNGLPOLYGONOFFSETCLAMPPROC>("glPolygonOffsetClamp")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_arb_es3_2_compatibility()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glPrimitiveBoundingBoxARB = get_function<PFNGLPRIMITIVEBOUNDINGBOXARBPROC>("glPrimitiveBoundingBoxARB")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_arb_bindless_texture()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glGetTextureHandleARB = get_function<PFNGLGETTEXTUREHANDLEARBPROC>("glGetTextureHandleARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetTextureSamplerHandleARB = get_function<PFNGLGETTEXTURESAMPLERHANDLEARBPROC>("glGetTextureSamplerHandleARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMakeTextureHandleResidentARB = get_function<PFNGLMAKETEXTUREHANDLERESIDENTARBPROC>("glMakeTextureHandleResidentARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMakeTextureHandleNonResidentARB = get_function<PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC>("glMakeTextureHandleNonResidentARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetImageHandleARB = get_function<PFNGLGETIMAGEHANDLEARBPROC>("glGetImageHandleARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMakeImageHandleResidentARB = get_function<PFNGLMAKEIMAGEHANDLERESIDENTARBPROC>("glMakeImageHandleResidentARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMakeImageHandleNonResidentARB = get_function<PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC>("glMakeImageHandleNonResidentARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniformHandleui64ARB = get_function<PFNGLUNIFORMHANDLEUI64ARBPROC>("glUniformHandleui64ARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniformHandleui64vARB = get_function<PFNGLUNIFORMHANDLEUI64VARBPROC>("glUniformHandleui64vARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniformHandleui64ARB = get_function<PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC>("glProgramUniformHandleui64ARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniformHandleui64vARB = get_function<PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC>("glProgramUniformHandleui64vARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glIsTextureHandleResidentARB = get_function<PFNGLISTEXTUREHANDLERESIDENTARBPROC>("glIsTextureHandleResidentARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glIsImageHandleResidentARB = get_function<PFNGLISIMAGEHANDLERESIDENTARBPROC>("glIsImageHandleResidentARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribL1ui64ARB = get_function<PFNGLVERTEXATTRIBL1UI64ARBPROC>("glVertexAttribL1ui64ARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribL1ui64vARB = get_function<PFNGLVERTEXATTRIBL1UI64VARBPROC>("glVertexAttribL1ui64vARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetVertexAttribLui64vARB = get_function<PFNGLGETVERTEXATTRIBLUI64VARBPROC>("glGetVertexAttribLui64vARB")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_arb_cl_event()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glCreateSyncFromCLeventARB = get_function<PFNGLCREATESYNCFROMCLEVENTARBPROC>("glCreateSyncFromCLeventARB")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_arb_compute_variable_group_size()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glDispatchComputeGroupSizeARB = get_function<PFNGLDISPATCHCOMPUTEGROUPSIZEARBPROC>("glDispatchComputeGroupSizeARB")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_arb_debug_output()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glDebugMessageControlARB = get_function<PFNGLDEBUGMESSAGECONTROLARBPROC>("glDebugMessageControlARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDebugMessageInsertARB = get_function<PFNGLDEBUGMESSAGEINSERTARBPROC>("glDebugMessageInsertARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDebugMessageCallbackARB = get_function<PFNGLDEBUGMESSAGECALLBACKARBPROC>("glDebugMessageCallbackARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetDebugMessageLogARB = get_function<PFNGLGETDEBUGMESSAGELOGARBPROC>("glGetDebugMessageLogARB")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_arb_draw_buffers_blend()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glBlendEquationiARB = get_function<PFNGLBLENDEQUATIONIARBPROC>("glBlendEquationiARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glBlendEquationSeparateiARB = get_function<PFNGLBLENDEQUATIONSEPARATEIARBPROC>("glBlendEquationSeparateiARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glBlendFunciARB = get_function<PFNGLBLENDFUNCIARBPROC>("glBlendFunciARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glBlendFuncSeparateiARB = get_function<PFNGLBLENDFUNCSEPARATEIARBPROC>("glBlendFuncSeparateiARB")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_arb_draw_instanced()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glDrawArraysInstancedARB = get_function<PFNGLDRAWARRAYSINSTANCEDARBPROC>("glDrawArraysInstancedARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDrawElementsInstancedARB = get_function<PFNGLDRAWELEMENTSINSTANCEDARBPROC>("glDrawElementsInstancedARB")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_arb_geometry_shader4()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glProgramParameteriARB = get_function<PFNGLPROGRAMPARAMETERIARBPROC>("glProgramParameteriARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glFramebufferTextureARB = get_function<PFNGLFRAMEBUFFERTEXTUREARBPROC>("glFramebufferTextureARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glFramebufferTextureLayerARB = get_function<PFNGLFRAMEBUFFERTEXTURELAYERARBPROC>("glFramebufferTextureLayerARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glFramebufferTextureFaceARB = get_function<PFNGLFRAMEBUFFERTEXTUREFACEARBPROC>("glFramebufferTextureFaceARB")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_arb_gl_spirv()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glSpecializeShaderARB = get_function<PFNGLSPECIALIZESHADERARBPROC>("glSpecializeShaderARB")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_arb_gpu_shader_int64()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glUniform1i64ARB = get_function<PFNGLUNIFORM1I64ARBPROC>("glUniform1i64ARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform2i64ARB = get_function<PFNGLUNIFORM2I64ARBPROC>("glUniform2i64ARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform3i64ARB = get_function<PFNGLUNIFORM3I64ARBPROC>("glUniform3i64ARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform4i64ARB = get_function<PFNGLUNIFORM4I64ARBPROC>("glUniform4i64ARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform1i64vARB = get_function<PFNGLUNIFORM1I64VARBPROC>("glUniform1i64vARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform2i64vARB = get_function<PFNGLUNIFORM2I64VARBPROC>("glUniform2i64vARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform3i64vARB = get_function<PFNGLUNIFORM3I64VARBPROC>("glUniform3i64vARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform4i64vARB = get_function<PFNGLUNIFORM4I64VARBPROC>("glUniform4i64vARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform1ui64ARB = get_function<PFNGLUNIFORM1UI64ARBPROC>("glUniform1ui64ARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform2ui64ARB = get_function<PFNGLUNIFORM2UI64ARBPROC>("glUniform2ui64ARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform3ui64ARB = get_function<PFNGLUNIFORM3UI64ARBPROC>("glUniform3ui64ARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform4ui64ARB = get_function<PFNGLUNIFORM4UI64ARBPROC>("glUniform4ui64ARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform1ui64vARB = get_function<PFNGLUNIFORM1UI64VARBPROC>("glUniform1ui64vARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform2ui64vARB = get_function<PFNGLUNIFORM2UI64VARBPROC>("glUniform2ui64vARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform3ui64vARB = get_function<PFNGLUNIFORM3UI64VARBPROC>("glUniform3ui64vARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform4ui64vARB = get_function<PFNGLUNIFORM4UI64VARBPROC>("glUniform4ui64vARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetUniformi64vARB = get_function<PFNGLGETUNIFORMI64VARBPROC>("glGetUniformi64vARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetUniformui64vARB = get_function<PFNGLGETUNIFORMUI64VARBPROC>("glGetUniformui64vARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetnUniformi64vARB = get_function<PFNGLGETNUNIFORMI64VARBPROC>("glGetnUniformi64vARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetnUniformui64vARB = get_function<PFNGLGETNUNIFORMUI64VARBPROC>("glGetnUniformui64vARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform1i64ARB = get_function<PFNGLPROGRAMUNIFORM1I64ARBPROC>("glProgramUniform1i64ARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform2i64ARB = get_function<PFNGLPROGRAMUNIFORM2I64ARBPROC>("glProgramUniform2i64ARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform3i64ARB = get_function<PFNGLPROGRAMUNIFORM3I64ARBPROC>("glProgramUniform3i64ARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform4i64ARB = get_function<PFNGLPROGRAMUNIFORM4I64ARBPROC>("glProgramUniform4i64ARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform1i64vARB = get_function<PFNGLPROGRAMUNIFORM1I64VARBPROC>("glProgramUniform1i64vARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform2i64vARB = get_function<PFNGLPROGRAMUNIFORM2I64VARBPROC>("glProgramUniform2i64vARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform3i64vARB = get_function<PFNGLPROGRAMUNIFORM3I64VARBPROC>("glProgramUniform3i64vARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform4i64vARB = get_function<PFNGLPROGRAMUNIFORM4I64VARBPROC>("glProgramUniform4i64vARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform1ui64ARB = get_function<PFNGLPROGRAMUNIFORM1UI64ARBPROC>("glProgramUniform1ui64ARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform2ui64ARB = get_function<PFNGLPROGRAMUNIFORM2UI64ARBPROC>("glProgramUniform2ui64ARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform3ui64ARB = get_function<PFNGLPROGRAMUNIFORM3UI64ARBPROC>("glProgramUniform3ui64ARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform4ui64ARB = get_function<PFNGLPROGRAMUNIFORM4UI64ARBPROC>("glProgramUniform4ui64ARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform1ui64vARB = get_function<PFNGLPROGRAMUNIFORM1UI64VARBPROC>("glProgramUniform1ui64vARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform2ui64vARB = get_function<PFNGLPROGRAMUNIFORM2UI64VARBPROC>("glProgramUniform2ui64vARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform3ui64vARB = get_function<PFNGLPROGRAMUNIFORM3UI64VARBPROC>("glProgramUniform3ui64vARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform4ui64vARB = get_function<PFNGLPROGRAMUNIFORM4UI64VARBPROC>("glProgramUniform4ui64vARB")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_arb_indirect_parameters()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glMultiDrawArraysIndirectCountARB = get_function<PFNGLMULTIDRAWARRAYSINDIRECTCOUNTARBPROC>("glMultiDrawArraysIndirectCountARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMultiDrawElementsIndirectCountARB = get_function<PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTARBPROC>("glMultiDrawElementsIndirectCountARB")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_arb_instanced_arrays()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glVertexAttribDivisorARB = get_function<PFNGLVERTEXATTRIBDIVISORARBPROC>("glVertexAttribDivisorARB")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_arb_parallel_shader_compile()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glMaxShaderCompilerThreadsARB = get_function<PFNGLMAXSHADERCOMPILERTHREADSARBPROC>("glMaxShaderCompilerThreadsARB")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_arb_robustness()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glGetGraphicsResetStatusARB = get_function<PFNGLGETGRAPHICSRESETSTATUSARBPROC>("glGetGraphicsResetStatusARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetnTexImageARB = get_function<PFNGLGETNTEXIMAGEARBPROC>("glGetnTexImageARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glReadnPixelsARB = get_function<PFNGLREADNPIXELSARBPROC>("glReadnPixelsARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetnCompressedTexImageARB = get_function<PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC>("glGetnCompressedTexImageARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetnUniformfvARB = get_function<PFNGLGETNUNIFORMFVARBPROC>("glGetnUniformfvARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetnUniformivARB = get_function<PFNGLGETNUNIFORMIVARBPROC>("glGetnUniformivARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetnUniformuivARB = get_function<PFNGLGETNUNIFORMUIVARBPROC>("glGetnUniformuivARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetnUniformdvARB = get_function<PFNGLGETNUNIFORMDVARBPROC>("glGetnUniformdvARB")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_arb_sample_locations()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glFramebufferSampleLocationsfvARB = get_function<PFNGLFRAMEBUFFERSAMPLELOCATIONSFVARBPROC>("glFramebufferSampleLocationsfvARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedFramebufferSampleLocationsfvARB = get_function<PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVARBPROC>("glNamedFramebufferSampleLocationsfvARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glEvaluateDepthValuesARB = get_function<PFNGLEVALUATEDEPTHVALUESARBPROC>("glEvaluateDepthValuesARB")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_arb_sample_shading()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glMinSampleShadingARB = get_function<PFNGLMINSAMPLESHADINGARBPROC>("glMinSampleShadingARB")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_arb_shading_language_include()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glNamedStringARB = get_function<PFNGLNAMEDSTRINGARBPROC>("glNamedStringARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDeleteNamedStringARB = get_function<PFNGLDELETENAMEDSTRINGARBPROC>("glDeleteNamedStringARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCompileShaderIncludeARB = get_function<PFNGLCOMPILESHADERINCLUDEARBPROC>("glCompileShaderIncludeARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glIsNamedStringARB = get_function<PFNGLISNAMEDSTRINGARBPROC>("glIsNamedStringARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetNamedStringARB = get_function<PFNGLGETNAMEDSTRINGARBPROC>("glGetNamedStringARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetNamedStringivARB = get_function<PFNGLGETNAMEDSTRINGIVARBPROC>("glGetNamedStringivARB")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_arb_sparse_buffer()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glBufferPageCommitmentARB = get_function<PFNGLBUFFERPAGECOMMITMENTARBPROC>("glBufferPageCommitmentARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedBufferPageCommitmentEXT = get_function<PFNGLNAMEDBUFFERPAGECOMMITMENTEXTPROC>("glNamedBufferPageCommitmentEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedBufferPageCommitmentARB = get_function<PFNGLNAMEDBUFFERPAGECOMMITMENTARBPROC>("glNamedBufferPageCommitmentARB")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_arb_sparse_texture()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glTexPageCommitmentARB = get_function<PFNGLTEXPAGECOMMITMENTARBPROC>("glTexPageCommitmentARB")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_arb_texture_buffer_object()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glTexBufferARB = get_function<PFNGLTEXBUFFERARBPROC>("glTexBufferARB")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_khr_blend_equation_advanced()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glBlendBarrierKHR = get_function<PFNGLBLENDBARRIERKHRPROC>("glBlendBarrierKHR")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_khr_parallel_shader_compile()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glMaxShaderCompilerThreadsKHR = get_function<PFNGLMAXSHADERCOMPILERTHREADSKHRPROC>("glMaxShaderCompilerThreadsKHR")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_amd_framebuffer_multisample_advanced()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glRenderbufferStorageMultisampleAdvancedAMD = get_function<PFNGLRENDERBUFFERSTORAGEMULTISAMPLEADVANCEDAMDPROC>("glRenderbufferStorageMultisampleAdvancedAMD")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedRenderbufferStorageMultisampleAdvancedAMD = get_function<PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEADVANCEDAMDPROC>("glNamedRenderbufferStorageMultisampleAdvancedAMD")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_amd_performance_monitor()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glGetPerfMonitorGroupsAMD = get_function<PFNGLGETPERFMONITORGROUPSAMDPROC>("glGetPerfMonitorGroupsAMD")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetPerfMonitorCountersAMD = get_function<PFNGLGETPERFMONITORCOUNTERSAMDPROC>("glGetPerfMonitorCountersAMD")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetPerfMonitorGroupStringAMD = get_function<PFNGLGETPERFMONITORGROUPSTRINGAMDPROC>("glGetPerfMonitorGroupStringAMD")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetPerfMonitorCounterStringAMD = get_function<PFNGLGETPERFMONITORCOUNTERSTRINGAMDPROC>("glGetPerfMonitorCounterStringAMD")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetPerfMonitorCounterInfoAMD = get_function<PFNGLGETPERFMONITORCOUNTERINFOAMDPROC>("glGetPerfMonitorCounterInfoAMD")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGenPerfMonitorsAMD = get_function<PFNGLGENPERFMONITORSAMDPROC>("glGenPerfMonitorsAMD")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDeletePerfMonitorsAMD = get_function<PFNGLDELETEPERFMONITORSAMDPROC>("glDeletePerfMonitorsAMD")) != nullptr;
    result = result && (framework::graphics::opengl::details::glSelectPerfMonitorCountersAMD = get_function<PFNGLSELECTPERFMONITORCOUNTERSAMDPROC>("glSelectPerfMonitorCountersAMD")) != nullptr;
    result = result && (framework::graphics::opengl::details::glBeginPerfMonitorAMD = get_function<PFNGLBEGINPERFMONITORAMDPROC>("glBeginPerfMonitorAMD")) != nullptr;
    result = result && (framework::graphics::opengl::details::glEndPerfMonitorAMD = get_function<PFNGLENDPERFMONITORAMDPROC>("glEndPerfMonitorAMD")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetPerfMonitorCounterDataAMD = get_function<PFNGLGETPERFMONITORCOUNTERDATAAMDPROC>("glGetPerfMonitorCounterDataAMD")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_ext_egl_image_storage()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glEGLImageTargetTexStorageEXT = get_function<PFNGLEGLIMAGETARGETTEXSTORAGEEXTPROC>("glEGLImageTargetTexStorageEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glEGLImageTargetTextureStorageEXT = get_function<PFNGLEGLIMAGETARGETTEXTURESTORAGEEXTPROC>("glEGLImageTargetTextureStorageEXT")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_ext_debug_label()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glLabelObjectEXT = get_function<PFNGLLABELOBJECTEXTPROC>("glLabelObjectEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetObjectLabelEXT = get_function<PFNGLGETOBJECTLABELEXTPROC>("glGetObjectLabelEXT")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_ext_debug_marker()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glInsertEventMarkerEXT = get_function<PFNGLINSERTEVENTMARKEREXTPROC>("glInsertEventMarkerEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glPushGroupMarkerEXT = get_function<PFNGLPUSHGROUPMARKEREXTPROC>("glPushGroupMarkerEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glPopGroupMarkerEXT = get_function<PFNGLPOPGROUPMARKEREXTPROC>("glPopGroupMarkerEXT")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_ext_direct_state_access()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glMatrixLoadfEXT = get_function<PFNGLMATRIXLOADFEXTPROC>("glMatrixLoadfEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMatrixLoaddEXT = get_function<PFNGLMATRIXLOADDEXTPROC>("glMatrixLoaddEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMatrixMultfEXT = get_function<PFNGLMATRIXMULTFEXTPROC>("glMatrixMultfEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMatrixMultdEXT = get_function<PFNGLMATRIXMULTDEXTPROC>("glMatrixMultdEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMatrixLoadIdentityEXT = get_function<PFNGLMATRIXLOADIDENTITYEXTPROC>("glMatrixLoadIdentityEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMatrixRotatefEXT = get_function<PFNGLMATRIXROTATEFEXTPROC>("glMatrixRotatefEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMatrixRotatedEXT = get_function<PFNGLMATRIXROTATEDEXTPROC>("glMatrixRotatedEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMatrixScalefEXT = get_function<PFNGLMATRIXSCALEFEXTPROC>("glMatrixScalefEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMatrixScaledEXT = get_function<PFNGLMATRIXSCALEDEXTPROC>("glMatrixScaledEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMatrixTranslatefEXT = get_function<PFNGLMATRIXTRANSLATEFEXTPROC>("glMatrixTranslatefEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMatrixTranslatedEXT = get_function<PFNGLMATRIXTRANSLATEDEXTPROC>("glMatrixTranslatedEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMatrixFrustumEXT = get_function<PFNGLMATRIXFRUSTUMEXTPROC>("glMatrixFrustumEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMatrixOrthoEXT = get_function<PFNGLMATRIXORTHOEXTPROC>("glMatrixOrthoEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMatrixPopEXT = get_function<PFNGLMATRIXPOPEXTPROC>("glMatrixPopEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMatrixPushEXT = get_function<PFNGLMATRIXPUSHEXTPROC>("glMatrixPushEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glClientAttribDefaultEXT = get_function<PFNGLCLIENTATTRIBDEFAULTEXTPROC>("glClientAttribDefaultEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glPushClientAttribDefaultEXT = get_function<PFNGLPUSHCLIENTATTRIBDEFAULTEXTPROC>("glPushClientAttribDefaultEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTextureParameterfEXT = get_function<PFNGLTEXTUREPARAMETERFEXTPROC>("glTextureParameterfEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTextureParameterfvEXT = get_function<PFNGLTEXTUREPARAMETERFVEXTPROC>("glTextureParameterfvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTextureParameteriEXT = get_function<PFNGLTEXTUREPARAMETERIEXTPROC>("glTextureParameteriEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTextureParameterivEXT = get_function<PFNGLTEXTUREPARAMETERIVEXTPROC>("glTextureParameterivEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTextureImage1DEXT = get_function<PFNGLTEXTUREIMAGE1DEXTPROC>("glTextureImage1DEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTextureImage2DEXT = get_function<PFNGLTEXTUREIMAGE2DEXTPROC>("glTextureImage2DEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTextureSubImage1DEXT = get_function<PFNGLTEXTURESUBIMAGE1DEXTPROC>("glTextureSubImage1DEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTextureSubImage2DEXT = get_function<PFNGLTEXTURESUBIMAGE2DEXTPROC>("glTextureSubImage2DEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCopyTextureImage1DEXT = get_function<PFNGLCOPYTEXTUREIMAGE1DEXTPROC>("glCopyTextureImage1DEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCopyTextureImage2DEXT = get_function<PFNGLCOPYTEXTUREIMAGE2DEXTPROC>("glCopyTextureImage2DEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCopyTextureSubImage1DEXT = get_function<PFNGLCOPYTEXTURESUBIMAGE1DEXTPROC>("glCopyTextureSubImage1DEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCopyTextureSubImage2DEXT = get_function<PFNGLCOPYTEXTURESUBIMAGE2DEXTPROC>("glCopyTextureSubImage2DEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetTextureImageEXT = get_function<PFNGLGETTEXTUREIMAGEEXTPROC>("glGetTextureImageEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetTextureParameterfvEXT = get_function<PFNGLGETTEXTUREPARAMETERFVEXTPROC>("glGetTextureParameterfvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetTextureParameterivEXT = get_function<PFNGLGETTEXTUREPARAMETERIVEXTPROC>("glGetTextureParameterivEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetTextureLevelParameterfvEXT = get_function<PFNGLGETTEXTURELEVELPARAMETERFVEXTPROC>("glGetTextureLevelParameterfvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetTextureLevelParameterivEXT = get_function<PFNGLGETTEXTURELEVELPARAMETERIVEXTPROC>("glGetTextureLevelParameterivEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTextureImage3DEXT = get_function<PFNGLTEXTUREIMAGE3DEXTPROC>("glTextureImage3DEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTextureSubImage3DEXT = get_function<PFNGLTEXTURESUBIMAGE3DEXTPROC>("glTextureSubImage3DEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCopyTextureSubImage3DEXT = get_function<PFNGLCOPYTEXTURESUBIMAGE3DEXTPROC>("glCopyTextureSubImage3DEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glBindMultiTextureEXT = get_function<PFNGLBINDMULTITEXTUREEXTPROC>("glBindMultiTextureEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMultiTexCoordPointerEXT = get_function<PFNGLMULTITEXCOORDPOINTEREXTPROC>("glMultiTexCoordPointerEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMultiTexEnvfEXT = get_function<PFNGLMULTITEXENVFEXTPROC>("glMultiTexEnvfEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMultiTexEnvfvEXT = get_function<PFNGLMULTITEXENVFVEXTPROC>("glMultiTexEnvfvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMultiTexEnviEXT = get_function<PFNGLMULTITEXENVIEXTPROC>("glMultiTexEnviEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMultiTexEnvivEXT = get_function<PFNGLMULTITEXENVIVEXTPROC>("glMultiTexEnvivEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMultiTexGendEXT = get_function<PFNGLMULTITEXGENDEXTPROC>("glMultiTexGendEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMultiTexGendvEXT = get_function<PFNGLMULTITEXGENDVEXTPROC>("glMultiTexGendvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMultiTexGenfEXT = get_function<PFNGLMULTITEXGENFEXTPROC>("glMultiTexGenfEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMultiTexGenfvEXT = get_function<PFNGLMULTITEXGENFVEXTPROC>("glMultiTexGenfvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMultiTexGeniEXT = get_function<PFNGLMULTITEXGENIEXTPROC>("glMultiTexGeniEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMultiTexGenivEXT = get_function<PFNGLMULTITEXGENIVEXTPROC>("glMultiTexGenivEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetMultiTexEnvfvEXT = get_function<PFNGLGETMULTITEXENVFVEXTPROC>("glGetMultiTexEnvfvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetMultiTexEnvivEXT = get_function<PFNGLGETMULTITEXENVIVEXTPROC>("glGetMultiTexEnvivEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetMultiTexGendvEXT = get_function<PFNGLGETMULTITEXGENDVEXTPROC>("glGetMultiTexGendvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetMultiTexGenfvEXT = get_function<PFNGLGETMULTITEXGENFVEXTPROC>("glGetMultiTexGenfvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetMultiTexGenivEXT = get_function<PFNGLGETMULTITEXGENIVEXTPROC>("glGetMultiTexGenivEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMultiTexParameteriEXT = get_function<PFNGLMULTITEXPARAMETERIEXTPROC>("glMultiTexParameteriEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMultiTexParameterivEXT = get_function<PFNGLMULTITEXPARAMETERIVEXTPROC>("glMultiTexParameterivEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMultiTexParameterfEXT = get_function<PFNGLMULTITEXPARAMETERFEXTPROC>("glMultiTexParameterfEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMultiTexParameterfvEXT = get_function<PFNGLMULTITEXPARAMETERFVEXTPROC>("glMultiTexParameterfvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMultiTexImage1DEXT = get_function<PFNGLMULTITEXIMAGE1DEXTPROC>("glMultiTexImage1DEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMultiTexImage2DEXT = get_function<PFNGLMULTITEXIMAGE2DEXTPROC>("glMultiTexImage2DEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMultiTexSubImage1DEXT = get_function<PFNGLMULTITEXSUBIMAGE1DEXTPROC>("glMultiTexSubImage1DEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMultiTexSubImage2DEXT = get_function<PFNGLMULTITEXSUBIMAGE2DEXTPROC>("glMultiTexSubImage2DEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCopyMultiTexImage1DEXT = get_function<PFNGLCOPYMULTITEXIMAGE1DEXTPROC>("glCopyMultiTexImage1DEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCopyMultiTexImage2DEXT = get_function<PFNGLCOPYMULTITEXIMAGE2DEXTPROC>("glCopyMultiTexImage2DEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCopyMultiTexSubImage1DEXT = get_function<PFNGLCOPYMULTITEXSUBIMAGE1DEXTPROC>("glCopyMultiTexSubImage1DEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCopyMultiTexSubImage2DEXT = get_function<PFNGLCOPYMULTITEXSUBIMAGE2DEXTPROC>("glCopyMultiTexSubImage2DEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetMultiTexImageEXT = get_function<PFNGLGETMULTITEXIMAGEEXTPROC>("glGetMultiTexImageEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetMultiTexParameterfvEXT = get_function<PFNGLGETMULTITEXPARAMETERFVEXTPROC>("glGetMultiTexParameterfvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetMultiTexParameterivEXT = get_function<PFNGLGETMULTITEXPARAMETERIVEXTPROC>("glGetMultiTexParameterivEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetMultiTexLevelParameterfvEXT = get_function<PFNGLGETMULTITEXLEVELPARAMETERFVEXTPROC>("glGetMultiTexLevelParameterfvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetMultiTexLevelParameterivEXT = get_function<PFNGLGETMULTITEXLEVELPARAMETERIVEXTPROC>("glGetMultiTexLevelParameterivEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMultiTexImage3DEXT = get_function<PFNGLMULTITEXIMAGE3DEXTPROC>("glMultiTexImage3DEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMultiTexSubImage3DEXT = get_function<PFNGLMULTITEXSUBIMAGE3DEXTPROC>("glMultiTexSubImage3DEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCopyMultiTexSubImage3DEXT = get_function<PFNGLCOPYMULTITEXSUBIMAGE3DEXTPROC>("glCopyMultiTexSubImage3DEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glEnableClientStateIndexedEXT = get_function<PFNGLENABLECLIENTSTATEINDEXEDEXTPROC>("glEnableClientStateIndexedEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDisableClientStateIndexedEXT = get_function<PFNGLDISABLECLIENTSTATEINDEXEDEXTPROC>("glDisableClientStateIndexedEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetFloatIndexedvEXT = get_function<PFNGLGETFLOATINDEXEDVEXTPROC>("glGetFloatIndexedvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetDoubleIndexedvEXT = get_function<PFNGLGETDOUBLEINDEXEDVEXTPROC>("glGetDoubleIndexedvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetPointerIndexedvEXT = get_function<PFNGLGETPOINTERINDEXEDVEXTPROC>("glGetPointerIndexedvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glEnableIndexedEXT = get_function<PFNGLENABLEINDEXEDEXTPROC>("glEnableIndexedEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDisableIndexedEXT = get_function<PFNGLDISABLEINDEXEDEXTPROC>("glDisableIndexedEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glIsEnabledIndexedEXT = get_function<PFNGLISENABLEDINDEXEDEXTPROC>("glIsEnabledIndexedEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetIntegerIndexedvEXT = get_function<PFNGLGETINTEGERINDEXEDVEXTPROC>("glGetIntegerIndexedvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetBooleanIndexedvEXT = get_function<PFNGLGETBOOLEANINDEXEDVEXTPROC>("glGetBooleanIndexedvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCompressedTextureImage3DEXT = get_function<PFNGLCOMPRESSEDTEXTUREIMAGE3DEXTPROC>("glCompressedTextureImage3DEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCompressedTextureImage2DEXT = get_function<PFNGLCOMPRESSEDTEXTUREIMAGE2DEXTPROC>("glCompressedTextureImage2DEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCompressedTextureImage1DEXT = get_function<PFNGLCOMPRESSEDTEXTUREIMAGE1DEXTPROC>("glCompressedTextureImage1DEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCompressedTextureSubImage3DEXT = get_function<PFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXTPROC>("glCompressedTextureSubImage3DEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCompressedTextureSubImage2DEXT = get_function<PFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXTPROC>("glCompressedTextureSubImage2DEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCompressedTextureSubImage1DEXT = get_function<PFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXTPROC>("glCompressedTextureSubImage1DEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetCompressedTextureImageEXT = get_function<PFNGLGETCOMPRESSEDTEXTUREIMAGEEXTPROC>("glGetCompressedTextureImageEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCompressedMultiTexImage3DEXT = get_function<PFNGLCOMPRESSEDMULTITEXIMAGE3DEXTPROC>("glCompressedMultiTexImage3DEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCompressedMultiTexImage2DEXT = get_function<PFNGLCOMPRESSEDMULTITEXIMAGE2DEXTPROC>("glCompressedMultiTexImage2DEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCompressedMultiTexImage1DEXT = get_function<PFNGLCOMPRESSEDMULTITEXIMAGE1DEXTPROC>("glCompressedMultiTexImage1DEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCompressedMultiTexSubImage3DEXT = get_function<PFNGLCOMPRESSEDMULTITEXSUBIMAGE3DEXTPROC>("glCompressedMultiTexSubImage3DEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCompressedMultiTexSubImage2DEXT = get_function<PFNGLCOMPRESSEDMULTITEXSUBIMAGE2DEXTPROC>("glCompressedMultiTexSubImage2DEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCompressedMultiTexSubImage1DEXT = get_function<PFNGLCOMPRESSEDMULTITEXSUBIMAGE1DEXTPROC>("glCompressedMultiTexSubImage1DEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetCompressedMultiTexImageEXT = get_function<PFNGLGETCOMPRESSEDMULTITEXIMAGEEXTPROC>("glGetCompressedMultiTexImageEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMatrixLoadTransposefEXT = get_function<PFNGLMATRIXLOADTRANSPOSEFEXTPROC>("glMatrixLoadTransposefEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMatrixLoadTransposedEXT = get_function<PFNGLMATRIXLOADTRANSPOSEDEXTPROC>("glMatrixLoadTransposedEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMatrixMultTransposefEXT = get_function<PFNGLMATRIXMULTTRANSPOSEFEXTPROC>("glMatrixMultTransposefEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMatrixMultTransposedEXT = get_function<PFNGLMATRIXMULTTRANSPOSEDEXTPROC>("glMatrixMultTransposedEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedBufferDataEXT = get_function<PFNGLNAMEDBUFFERDATAEXTPROC>("glNamedBufferDataEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedBufferSubDataEXT = get_function<PFNGLNAMEDBUFFERSUBDATAEXTPROC>("glNamedBufferSubDataEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMapNamedBufferEXT = get_function<PFNGLMAPNAMEDBUFFEREXTPROC>("glMapNamedBufferEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUnmapNamedBufferEXT = get_function<PFNGLUNMAPNAMEDBUFFEREXTPROC>("glUnmapNamedBufferEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetNamedBufferParameterivEXT = get_function<PFNGLGETNAMEDBUFFERPARAMETERIVEXTPROC>("glGetNamedBufferParameterivEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetNamedBufferPointervEXT = get_function<PFNGLGETNAMEDBUFFERPOINTERVEXTPROC>("glGetNamedBufferPointervEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetNamedBufferSubDataEXT = get_function<PFNGLGETNAMEDBUFFERSUBDATAEXTPROC>("glGetNamedBufferSubDataEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform1fEXT = get_function<PFNGLPROGRAMUNIFORM1FEXTPROC>("glProgramUniform1fEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform2fEXT = get_function<PFNGLPROGRAMUNIFORM2FEXTPROC>("glProgramUniform2fEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform3fEXT = get_function<PFNGLPROGRAMUNIFORM3FEXTPROC>("glProgramUniform3fEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform4fEXT = get_function<PFNGLPROGRAMUNIFORM4FEXTPROC>("glProgramUniform4fEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform1iEXT = get_function<PFNGLPROGRAMUNIFORM1IEXTPROC>("glProgramUniform1iEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform2iEXT = get_function<PFNGLPROGRAMUNIFORM2IEXTPROC>("glProgramUniform2iEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform3iEXT = get_function<PFNGLPROGRAMUNIFORM3IEXTPROC>("glProgramUniform3iEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform4iEXT = get_function<PFNGLPROGRAMUNIFORM4IEXTPROC>("glProgramUniform4iEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform1fvEXT = get_function<PFNGLPROGRAMUNIFORM1FVEXTPROC>("glProgramUniform1fvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform2fvEXT = get_function<PFNGLPROGRAMUNIFORM2FVEXTPROC>("glProgramUniform2fvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform3fvEXT = get_function<PFNGLPROGRAMUNIFORM3FVEXTPROC>("glProgramUniform3fvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform4fvEXT = get_function<PFNGLPROGRAMUNIFORM4FVEXTPROC>("glProgramUniform4fvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform1ivEXT = get_function<PFNGLPROGRAMUNIFORM1IVEXTPROC>("glProgramUniform1ivEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform2ivEXT = get_function<PFNGLPROGRAMUNIFORM2IVEXTPROC>("glProgramUniform2ivEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform3ivEXT = get_function<PFNGLPROGRAMUNIFORM3IVEXTPROC>("glProgramUniform3ivEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform4ivEXT = get_function<PFNGLPROGRAMUNIFORM4IVEXTPROC>("glProgramUniform4ivEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniformMatrix2fvEXT = get_function<PFNGLPROGRAMUNIFORMMATRIX2FVEXTPROC>("glProgramUniformMatrix2fvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniformMatrix3fvEXT = get_function<PFNGLPROGRAMUNIFORMMATRIX3FVEXTPROC>("glProgramUniformMatrix3fvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniformMatrix4fvEXT = get_function<PFNGLPROGRAMUNIFORMMATRIX4FVEXTPROC>("glProgramUniformMatrix4fvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniformMatrix2x3fvEXT = get_function<PFNGLPROGRAMUNIFORMMATRIX2X3FVEXTPROC>("glProgramUniformMatrix2x3fvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniformMatrix3x2fvEXT = get_function<PFNGLPROGRAMUNIFORMMATRIX3X2FVEXTPROC>("glProgramUniformMatrix3x2fvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniformMatrix2x4fvEXT = get_function<PFNGLPROGRAMUNIFORMMATRIX2X4FVEXTPROC>("glProgramUniformMatrix2x4fvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniformMatrix4x2fvEXT = get_function<PFNGLPROGRAMUNIFORMMATRIX4X2FVEXTPROC>("glProgramUniformMatrix4x2fvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniformMatrix3x4fvEXT = get_function<PFNGLPROGRAMUNIFORMMATRIX3X4FVEXTPROC>("glProgramUniformMatrix3x4fvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniformMatrix4x3fvEXT = get_function<PFNGLPROGRAMUNIFORMMATRIX4X3FVEXTPROC>("glProgramUniformMatrix4x3fvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTextureBufferEXT = get_function<PFNGLTEXTUREBUFFEREXTPROC>("glTextureBufferEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMultiTexBufferEXT = get_function<PFNGLMULTITEXBUFFEREXTPROC>("glMultiTexBufferEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTextureParameterIivEXT = get_function<PFNGLTEXTUREPARAMETERIIVEXTPROC>("glTextureParameterIivEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTextureParameterIuivEXT = get_function<PFNGLTEXTUREPARAMETERIUIVEXTPROC>("glTextureParameterIuivEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetTextureParameterIivEXT = get_function<PFNGLGETTEXTUREPARAMETERIIVEXTPROC>("glGetTextureParameterIivEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetTextureParameterIuivEXT = get_function<PFNGLGETTEXTUREPARAMETERIUIVEXTPROC>("glGetTextureParameterIuivEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMultiTexParameterIivEXT = get_function<PFNGLMULTITEXPARAMETERIIVEXTPROC>("glMultiTexParameterIivEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMultiTexParameterIuivEXT = get_function<PFNGLMULTITEXPARAMETERIUIVEXTPROC>("glMultiTexParameterIuivEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetMultiTexParameterIivEXT = get_function<PFNGLGETMULTITEXPARAMETERIIVEXTPROC>("glGetMultiTexParameterIivEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetMultiTexParameterIuivEXT = get_function<PFNGLGETMULTITEXPARAMETERIUIVEXTPROC>("glGetMultiTexParameterIuivEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform1uiEXT = get_function<PFNGLPROGRAMUNIFORM1UIEXTPROC>("glProgramUniform1uiEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform2uiEXT = get_function<PFNGLPROGRAMUNIFORM2UIEXTPROC>("glProgramUniform2uiEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform3uiEXT = get_function<PFNGLPROGRAMUNIFORM3UIEXTPROC>("glProgramUniform3uiEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform4uiEXT = get_function<PFNGLPROGRAMUNIFORM4UIEXTPROC>("glProgramUniform4uiEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform1uivEXT = get_function<PFNGLPROGRAMUNIFORM1UIVEXTPROC>("glProgramUniform1uivEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform2uivEXT = get_function<PFNGLPROGRAMUNIFORM2UIVEXTPROC>("glProgramUniform2uivEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform3uivEXT = get_function<PFNGLPROGRAMUNIFORM3UIVEXTPROC>("glProgramUniform3uivEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform4uivEXT = get_function<PFNGLPROGRAMUNIFORM4UIVEXTPROC>("glProgramUniform4uivEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedProgramLocalParameters4fvEXT = get_function<PFNGLNAMEDPROGRAMLOCALPARAMETERS4FVEXTPROC>("glNamedProgramLocalParameters4fvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedProgramLocalParameterI4iEXT = get_function<PFNGLNAMEDPROGRAMLOCALPARAMETERI4IEXTPROC>("glNamedProgramLocalParameterI4iEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedProgramLocalParameterI4ivEXT = get_function<PFNGLNAMEDPROGRAMLOCALPARAMETERI4IVEXTPROC>("glNamedProgramLocalParameterI4ivEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedProgramLocalParametersI4ivEXT = get_function<PFNGLNAMEDPROGRAMLOCALPARAMETERSI4IVEXTPROC>("glNamedProgramLocalParametersI4ivEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedProgramLocalParameterI4uiEXT = get_function<PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIEXTPROC>("glNamedProgramLocalParameterI4uiEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedProgramLocalParameterI4uivEXT = get_function<PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIVEXTPROC>("glNamedProgramLocalParameterI4uivEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedProgramLocalParametersI4uivEXT = get_function<PFNGLNAMEDPROGRAMLOCALPARAMETERSI4UIVEXTPROC>("glNamedProgramLocalParametersI4uivEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetNamedProgramLocalParameterIivEXT = get_function<PFNGLGETNAMEDPROGRAMLOCALPARAMETERIIVEXTPROC>("glGetNamedProgramLocalParameterIivEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetNamedProgramLocalParameterIuivEXT = get_function<PFNGLGETNAMEDPROGRAMLOCALPARAMETERIUIVEXTPROC>("glGetNamedProgramLocalParameterIuivEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glEnableClientStateiEXT = get_function<PFNGLENABLECLIENTSTATEIEXTPROC>("glEnableClientStateiEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDisableClientStateiEXT = get_function<PFNGLDISABLECLIENTSTATEIEXTPROC>("glDisableClientStateiEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetFloati_vEXT = get_function<PFNGLGETFLOATI_VEXTPROC>("glGetFloati_vEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetDoublei_vEXT = get_function<PFNGLGETDOUBLEI_VEXTPROC>("glGetDoublei_vEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetPointeri_vEXT = get_function<PFNGLGETPOINTERI_VEXTPROC>("glGetPointeri_vEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedProgramStringEXT = get_function<PFNGLNAMEDPROGRAMSTRINGEXTPROC>("glNamedProgramStringEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedProgramLocalParameter4dEXT = get_function<PFNGLNAMEDPROGRAMLOCALPARAMETER4DEXTPROC>("glNamedProgramLocalParameter4dEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedProgramLocalParameter4dvEXT = get_function<PFNGLNAMEDPROGRAMLOCALPARAMETER4DVEXTPROC>("glNamedProgramLocalParameter4dvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedProgramLocalParameter4fEXT = get_function<PFNGLNAMEDPROGRAMLOCALPARAMETER4FEXTPROC>("glNamedProgramLocalParameter4fEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedProgramLocalParameter4fvEXT = get_function<PFNGLNAMEDPROGRAMLOCALPARAMETER4FVEXTPROC>("glNamedProgramLocalParameter4fvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetNamedProgramLocalParameterdvEXT = get_function<PFNGLGETNAMEDPROGRAMLOCALPARAMETERDVEXTPROC>("glGetNamedProgramLocalParameterdvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetNamedProgramLocalParameterfvEXT = get_function<PFNGLGETNAMEDPROGRAMLOCALPARAMETERFVEXTPROC>("glGetNamedProgramLocalParameterfvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetNamedProgramivEXT = get_function<PFNGLGETNAMEDPROGRAMIVEXTPROC>("glGetNamedProgramivEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetNamedProgramStringEXT = get_function<PFNGLGETNAMEDPROGRAMSTRINGEXTPROC>("glGetNamedProgramStringEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedRenderbufferStorageEXT = get_function<PFNGLNAMEDRENDERBUFFERSTORAGEEXTPROC>("glNamedRenderbufferStorageEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetNamedRenderbufferParameterivEXT = get_function<PFNGLGETNAMEDRENDERBUFFERPARAMETERIVEXTPROC>("glGetNamedRenderbufferParameterivEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedRenderbufferStorageMultisampleEXT = get_function<PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC>("glNamedRenderbufferStorageMultisampleEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedRenderbufferStorageMultisampleCoverageEXT = get_function<PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXTPROC>("glNamedRenderbufferStorageMultisampleCoverageEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCheckNamedFramebufferStatusEXT = get_function<PFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXTPROC>("glCheckNamedFramebufferStatusEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedFramebufferTexture1DEXT = get_function<PFNGLNAMEDFRAMEBUFFERTEXTURE1DEXTPROC>("glNamedFramebufferTexture1DEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedFramebufferTexture2DEXT = get_function<PFNGLNAMEDFRAMEBUFFERTEXTURE2DEXTPROC>("glNamedFramebufferTexture2DEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedFramebufferTexture3DEXT = get_function<PFNGLNAMEDFRAMEBUFFERTEXTURE3DEXTPROC>("glNamedFramebufferTexture3DEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedFramebufferRenderbufferEXT = get_function<PFNGLNAMEDFRAMEBUFFERRENDERBUFFEREXTPROC>("glNamedFramebufferRenderbufferEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetNamedFramebufferAttachmentParameterivEXT = get_function<PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC>("glGetNamedFramebufferAttachmentParameterivEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGenerateTextureMipmapEXT = get_function<PFNGLGENERATETEXTUREMIPMAPEXTPROC>("glGenerateTextureMipmapEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGenerateMultiTexMipmapEXT = get_function<PFNGLGENERATEMULTITEXMIPMAPEXTPROC>("glGenerateMultiTexMipmapEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glFramebufferDrawBufferEXT = get_function<PFNGLFRAMEBUFFERDRAWBUFFEREXTPROC>("glFramebufferDrawBufferEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glFramebufferDrawBuffersEXT = get_function<PFNGLFRAMEBUFFERDRAWBUFFERSEXTPROC>("glFramebufferDrawBuffersEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glFramebufferReadBufferEXT = get_function<PFNGLFRAMEBUFFERREADBUFFEREXTPROC>("glFramebufferReadBufferEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetFramebufferParameterivEXT = get_function<PFNGLGETFRAMEBUFFERPARAMETERIVEXTPROC>("glGetFramebufferParameterivEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedCopyBufferSubDataEXT = get_function<PFNGLNAMEDCOPYBUFFERSUBDATAEXTPROC>("glNamedCopyBufferSubDataEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedFramebufferTextureEXT = get_function<PFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC>("glNamedFramebufferTextureEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedFramebufferTextureLayerEXT = get_function<PFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXTPROC>("glNamedFramebufferTextureLayerEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedFramebufferTextureFaceEXT = get_function<PFNGLNAMEDFRAMEBUFFERTEXTUREFACEEXTPROC>("glNamedFramebufferTextureFaceEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTextureRenderbufferEXT = get_function<PFNGLTEXTURERENDERBUFFEREXTPROC>("glTextureRenderbufferEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMultiTexRenderbufferEXT = get_function<PFNGLMULTITEXRENDERBUFFEREXTPROC>("glMultiTexRenderbufferEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexArrayVertexOffsetEXT = get_function<PFNGLVERTEXARRAYVERTEXOFFSETEXTPROC>("glVertexArrayVertexOffsetEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexArrayColorOffsetEXT = get_function<PFNGLVERTEXARRAYCOLOROFFSETEXTPROC>("glVertexArrayColorOffsetEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexArrayEdgeFlagOffsetEXT = get_function<PFNGLVERTEXARRAYEDGEFLAGOFFSETEXTPROC>("glVertexArrayEdgeFlagOffsetEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexArrayIndexOffsetEXT = get_function<PFNGLVERTEXARRAYINDEXOFFSETEXTPROC>("glVertexArrayIndexOffsetEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexArrayNormalOffsetEXT = get_function<PFNGLVERTEXARRAYNORMALOFFSETEXTPROC>("glVertexArrayNormalOffsetEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexArrayTexCoordOffsetEXT = get_function<PFNGLVERTEXARRAYTEXCOORDOFFSETEXTPROC>("glVertexArrayTexCoordOffsetEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexArrayMultiTexCoordOffsetEXT = get_function<PFNGLVERTEXARRAYMULTITEXCOORDOFFSETEXTPROC>("glVertexArrayMultiTexCoordOffsetEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexArrayFogCoordOffsetEXT = get_function<PFNGLVERTEXARRAYFOGCOORDOFFSETEXTPROC>("glVertexArrayFogCoordOffsetEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexArraySecondaryColorOffsetEXT = get_function<PFNGLVERTEXARRAYSECONDARYCOLOROFFSETEXTPROC>("glVertexArraySecondaryColorOffsetEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexArrayVertexAttribOffsetEXT = get_function<PFNGLVERTEXARRAYVERTEXATTRIBOFFSETEXTPROC>("glVertexArrayVertexAttribOffsetEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexArrayVertexAttribIOffsetEXT = get_function<PFNGLVERTEXARRAYVERTEXATTRIBIOFFSETEXTPROC>("glVertexArrayVertexAttribIOffsetEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glEnableVertexArrayEXT = get_function<PFNGLENABLEVERTEXARRAYEXTPROC>("glEnableVertexArrayEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDisableVertexArrayEXT = get_function<PFNGLDISABLEVERTEXARRAYEXTPROC>("glDisableVertexArrayEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glEnableVertexArrayAttribEXT = get_function<PFNGLENABLEVERTEXARRAYATTRIBEXTPROC>("glEnableVertexArrayAttribEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDisableVertexArrayAttribEXT = get_function<PFNGLDISABLEVERTEXARRAYATTRIBEXTPROC>("glDisableVertexArrayAttribEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetVertexArrayIntegervEXT = get_function<PFNGLGETVERTEXARRAYINTEGERVEXTPROC>("glGetVertexArrayIntegervEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetVertexArrayPointervEXT = get_function<PFNGLGETVERTEXARRAYPOINTERVEXTPROC>("glGetVertexArrayPointervEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetVertexArrayIntegeri_vEXT = get_function<PFNGLGETVERTEXARRAYINTEGERI_VEXTPROC>("glGetVertexArrayIntegeri_vEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetVertexArrayPointeri_vEXT = get_function<PFNGLGETVERTEXARRAYPOINTERI_VEXTPROC>("glGetVertexArrayPointeri_vEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMapNamedBufferRangeEXT = get_function<PFNGLMAPNAMEDBUFFERRANGEEXTPROC>("glMapNamedBufferRangeEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glFlushMappedNamedBufferRangeEXT = get_function<PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEEXTPROC>("glFlushMappedNamedBufferRangeEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedBufferStorageEXT = get_function<PFNGLNAMEDBUFFERSTORAGEEXTPROC>("glNamedBufferStorageEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glClearNamedBufferDataEXT = get_function<PFNGLCLEARNAMEDBUFFERDATAEXTPROC>("glClearNamedBufferDataEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glClearNamedBufferSubDataEXT = get_function<PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC>("glClearNamedBufferSubDataEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedFramebufferParameteriEXT = get_function<PFNGLNAMEDFRAMEBUFFERPARAMETERIEXTPROC>("glNamedFramebufferParameteriEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetNamedFramebufferParameterivEXT = get_function<PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXTPROC>("glGetNamedFramebufferParameterivEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform1dEXT = get_function<PFNGLPROGRAMUNIFORM1DEXTPROC>("glProgramUniform1dEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform2dEXT = get_function<PFNGLPROGRAMUNIFORM2DEXTPROC>("glProgramUniform2dEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform3dEXT = get_function<PFNGLPROGRAMUNIFORM3DEXTPROC>("glProgramUniform3dEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform4dEXT = get_function<PFNGLPROGRAMUNIFORM4DEXTPROC>("glProgramUniform4dEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform1dvEXT = get_function<PFNGLPROGRAMUNIFORM1DVEXTPROC>("glProgramUniform1dvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform2dvEXT = get_function<PFNGLPROGRAMUNIFORM2DVEXTPROC>("glProgramUniform2dvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform3dvEXT = get_function<PFNGLPROGRAMUNIFORM3DVEXTPROC>("glProgramUniform3dvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform4dvEXT = get_function<PFNGLPROGRAMUNIFORM4DVEXTPROC>("glProgramUniform4dvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniformMatrix2dvEXT = get_function<PFNGLPROGRAMUNIFORMMATRIX2DVEXTPROC>("glProgramUniformMatrix2dvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniformMatrix3dvEXT = get_function<PFNGLPROGRAMUNIFORMMATRIX3DVEXTPROC>("glProgramUniformMatrix3dvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniformMatrix4dvEXT = get_function<PFNGLPROGRAMUNIFORMMATRIX4DVEXTPROC>("glProgramUniformMatrix4dvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniformMatrix2x3dvEXT = get_function<PFNGLPROGRAMUNIFORMMATRIX2X3DVEXTPROC>("glProgramUniformMatrix2x3dvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniformMatrix2x4dvEXT = get_function<PFNGLPROGRAMUNIFORMMATRIX2X4DVEXTPROC>("glProgramUniformMatrix2x4dvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniformMatrix3x2dvEXT = get_function<PFNGLPROGRAMUNIFORMMATRIX3X2DVEXTPROC>("glProgramUniformMatrix3x2dvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniformMatrix3x4dvEXT = get_function<PFNGLPROGRAMUNIFORMMATRIX3X4DVEXTPROC>("glProgramUniformMatrix3x4dvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniformMatrix4x2dvEXT = get_function<PFNGLPROGRAMUNIFORMMATRIX4X2DVEXTPROC>("glProgramUniformMatrix4x2dvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniformMatrix4x3dvEXT = get_function<PFNGLPROGRAMUNIFORMMATRIX4X3DVEXTPROC>("glProgramUniformMatrix4x3dvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTextureBufferRangeEXT = get_function<PFNGLTEXTUREBUFFERRANGEEXTPROC>("glTextureBufferRangeEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTextureStorage1DEXT = get_function<PFNGLTEXTURESTORAGE1DEXTPROC>("glTextureStorage1DEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTextureStorage2DEXT = get_function<PFNGLTEXTURESTORAGE2DEXTPROC>("glTextureStorage2DEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTextureStorage3DEXT = get_function<PFNGLTEXTURESTORAGE3DEXTPROC>("glTextureStorage3DEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTextureStorage2DMultisampleEXT = get_function<PFNGLTEXTURESTORAGE2DMULTISAMPLEEXTPROC>("glTextureStorage2DMultisampleEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTextureStorage3DMultisampleEXT = get_function<PFNGLTEXTURESTORAGE3DMULTISAMPLEEXTPROC>("glTextureStorage3DMultisampleEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexArrayBindVertexBufferEXT = get_function<PFNGLVERTEXARRAYBINDVERTEXBUFFEREXTPROC>("glVertexArrayBindVertexBufferEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexArrayVertexAttribFormatEXT = get_function<PFNGLVERTEXARRAYVERTEXATTRIBFORMATEXTPROC>("glVertexArrayVertexAttribFormatEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexArrayVertexAttribIFormatEXT = get_function<PFNGLVERTEXARRAYVERTEXATTRIBIFORMATEXTPROC>("glVertexArrayVertexAttribIFormatEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexArrayVertexAttribLFormatEXT = get_function<PFNGLVERTEXARRAYVERTEXATTRIBLFORMATEXTPROC>("glVertexArrayVertexAttribLFormatEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexArrayVertexAttribBindingEXT = get_function<PFNGLVERTEXARRAYVERTEXATTRIBBINDINGEXTPROC>("glVertexArrayVertexAttribBindingEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexArrayVertexBindingDivisorEXT = get_function<PFNGLVERTEXARRAYVERTEXBINDINGDIVISOREXTPROC>("glVertexArrayVertexBindingDivisorEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexArrayVertexAttribLOffsetEXT = get_function<PFNGLVERTEXARRAYVERTEXATTRIBLOFFSETEXTPROC>("glVertexArrayVertexAttribLOffsetEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTexturePageCommitmentEXT = get_function<PFNGLTEXTUREPAGECOMMITMENTEXTPROC>("glTexturePageCommitmentEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexArrayVertexAttribDivisorEXT = get_function<PFNGLVERTEXARRAYVERTEXATTRIBDIVISOREXTPROC>("glVertexArrayVertexAttribDivisorEXT")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_ext_draw_instanced()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glDrawArraysInstancedEXT = get_function<PFNGLDRAWARRAYSINSTANCEDEXTPROC>("glDrawArraysInstancedEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDrawElementsInstancedEXT = get_function<PFNGLDRAWELEMENTSINSTANCEDEXTPROC>("glDrawElementsInstancedEXT")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_ext_polygon_offset_clamp()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glPolygonOffsetClampEXT = get_function<PFNGLPOLYGONOFFSETCLAMPEXTPROC>("glPolygonOffsetClampEXT")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_ext_raster_multisample()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glRasterSamplesEXT = get_function<PFNGLRASTERSAMPLESEXTPROC>("glRasterSamplesEXT")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_ext_separate_shader_objects()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glUseShaderProgramEXT = get_function<PFNGLUSESHADERPROGRAMEXTPROC>("glUseShaderProgramEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glActiveProgramEXT = get_function<PFNGLACTIVEPROGRAMEXTPROC>("glActiveProgramEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCreateShaderProgramEXT = get_function<PFNGLCREATESHADERPROGRAMEXTPROC>("glCreateShaderProgramEXT")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_ext_shader_framebuffer_fetch_non_coherent()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glFramebufferFetchBarrierEXT = get_function<PFNGLFRAMEBUFFERFETCHBARRIEREXTPROC>("glFramebufferFetchBarrierEXT")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_ext_window_rectangles()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glWindowRectanglesEXT = get_function<PFNGLWINDOWRECTANGLESEXTPROC>("glWindowRectanglesEXT")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_intel_framebuffer_cmaa()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glApplyFramebufferAttachmentCMAAINTEL = get_function<PFNGLAPPLYFRAMEBUFFERATTACHMENTCMAAINTELPROC>("glApplyFramebufferAttachmentCMAAINTEL")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_intel_performance_query()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glBeginPerfQueryINTEL = get_function<PFNGLBEGINPERFQUERYINTELPROC>("glBeginPerfQueryINTEL")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCreatePerfQueryINTEL = get_function<PFNGLCREATEPERFQUERYINTELPROC>("glCreatePerfQueryINTEL")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDeletePerfQueryINTEL = get_function<PFNGLDELETEPERFQUERYINTELPROC>("glDeletePerfQueryINTEL")) != nullptr;
    result = result && (framework::graphics::opengl::details::glEndPerfQueryINTEL = get_function<PFNGLENDPERFQUERYINTELPROC>("glEndPerfQueryINTEL")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetFirstPerfQueryIdINTEL = get_function<PFNGLGETFIRSTPERFQUERYIDINTELPROC>("glGetFirstPerfQueryIdINTEL")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetNextPerfQueryIdINTEL = get_function<PFNGLGETNEXTPERFQUERYIDINTELPROC>("glGetNextPerfQueryIdINTEL")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetPerfCounterInfoINTEL = get_function<PFNGLGETPERFCOUNTERINFOINTELPROC>("glGetPerfCounterInfoINTEL")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetPerfQueryDataINTEL = get_function<PFNGLGETPERFQUERYDATAINTELPROC>("glGetPerfQueryDataINTEL")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetPerfQueryIdByNameINTEL = get_function<PFNGLGETPERFQUERYIDBYNAMEINTELPROC>("glGetPerfQueryIdByNameINTEL")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetPerfQueryInfoINTEL = get_function<PFNGLGETPERFQUERYINFOINTELPROC>("glGetPerfQueryInfoINTEL")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_nv_bindless_multi_draw_indirect()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glMultiDrawArraysIndirectBindlessNV = get_function<PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSNVPROC>("glMultiDrawArraysIndirectBindlessNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMultiDrawElementsIndirectBindlessNV = get_function<PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSNVPROC>("glMultiDrawElementsIndirectBindlessNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_nv_bindless_multi_draw_indirect_count()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glMultiDrawArraysIndirectBindlessCountNV = get_function<PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSCOUNTNVPROC>("glMultiDrawArraysIndirectBindlessCountNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMultiDrawElementsIndirectBindlessCountNV = get_function<PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSCOUNTNVPROC>("glMultiDrawElementsIndirectBindlessCountNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_nv_bindless_texture()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glGetTextureHandleNV = get_function<PFNGLGETTEXTUREHANDLENVPROC>("glGetTextureHandleNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetTextureSamplerHandleNV = get_function<PFNGLGETTEXTURESAMPLERHANDLENVPROC>("glGetTextureSamplerHandleNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMakeTextureHandleResidentNV = get_function<PFNGLMAKETEXTUREHANDLERESIDENTNVPROC>("glMakeTextureHandleResidentNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMakeTextureHandleNonResidentNV = get_function<PFNGLMAKETEXTUREHANDLENONRESIDENTNVPROC>("glMakeTextureHandleNonResidentNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetImageHandleNV = get_function<PFNGLGETIMAGEHANDLENVPROC>("glGetImageHandleNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMakeImageHandleResidentNV = get_function<PFNGLMAKEIMAGEHANDLERESIDENTNVPROC>("glMakeImageHandleResidentNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMakeImageHandleNonResidentNV = get_function<PFNGLMAKEIMAGEHANDLENONRESIDENTNVPROC>("glMakeImageHandleNonResidentNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniformHandleui64NV = get_function<PFNGLUNIFORMHANDLEUI64NVPROC>("glUniformHandleui64NV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniformHandleui64vNV = get_function<PFNGLUNIFORMHANDLEUI64VNVPROC>("glUniformHandleui64vNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniformHandleui64NV = get_function<PFNGLPROGRAMUNIFORMHANDLEUI64NVPROC>("glProgramUniformHandleui64NV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniformHandleui64vNV = get_function<PFNGLPROGRAMUNIFORMHANDLEUI64VNVPROC>("glProgramUniformHandleui64vNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glIsTextureHandleResidentNV = get_function<PFNGLISTEXTUREHANDLERESIDENTNVPROC>("glIsTextureHandleResidentNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glIsImageHandleResidentNV = get_function<PFNGLISIMAGEHANDLERESIDENTNVPROC>("glIsImageHandleResidentNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_nv_blend_equation_advanced()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glBlendParameteriNV = get_function<PFNGLBLENDPARAMETERINVPROC>("glBlendParameteriNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glBlendBarrierNV = get_function<PFNGLBLENDBARRIERNVPROC>("glBlendBarrierNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_nv_clip_space_w_scaling()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glViewportPositionWScaleNV = get_function<PFNGLVIEWPORTPOSITIONWSCALENVPROC>("glViewportPositionWScaleNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_nv_command_list()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glCreateStatesNV = get_function<PFNGLCREATESTATESNVPROC>("glCreateStatesNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDeleteStatesNV = get_function<PFNGLDELETESTATESNVPROC>("glDeleteStatesNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glIsStateNV = get_function<PFNGLISSTATENVPROC>("glIsStateNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glStateCaptureNV = get_function<PFNGLSTATECAPTURENVPROC>("glStateCaptureNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetCommandHeaderNV = get_function<PFNGLGETCOMMANDHEADERNVPROC>("glGetCommandHeaderNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetStageIndexNV = get_function<PFNGLGETSTAGEINDEXNVPROC>("glGetStageIndexNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDrawCommandsNV = get_function<PFNGLDRAWCOMMANDSNVPROC>("glDrawCommandsNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDrawCommandsAddressNV = get_function<PFNGLDRAWCOMMANDSADDRESSNVPROC>("glDrawCommandsAddressNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDrawCommandsStatesNV = get_function<PFNGLDRAWCOMMANDSSTATESNVPROC>("glDrawCommandsStatesNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDrawCommandsStatesAddressNV = get_function<PFNGLDRAWCOMMANDSSTATESADDRESSNVPROC>("glDrawCommandsStatesAddressNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCreateCommandListsNV = get_function<PFNGLCREATECOMMANDLISTSNVPROC>("glCreateCommandListsNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDeleteCommandListsNV = get_function<PFNGLDELETECOMMANDLISTSNVPROC>("glDeleteCommandListsNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glIsCommandListNV = get_function<PFNGLISCOMMANDLISTNVPROC>("glIsCommandListNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glListDrawCommandsStatesClientNV = get_function<PFNGLLISTDRAWCOMMANDSSTATESCLIENTNVPROC>("glListDrawCommandsStatesClientNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCommandListSegmentsNV = get_function<PFNGLCOMMANDLISTSEGMENTSNVPROC>("glCommandListSegmentsNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCompileCommandListNV = get_function<PFNGLCOMPILECOMMANDLISTNVPROC>("glCompileCommandListNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCallCommandListNV = get_function<PFNGLCALLCOMMANDLISTNVPROC>("glCallCommandListNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_nv_conditional_render()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glBeginConditionalRenderNV = get_function<PFNGLBEGINCONDITIONALRENDERNVPROC>("glBeginConditionalRenderNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glEndConditionalRenderNV = get_function<PFNGLENDCONDITIONALRENDERNVPROC>("glEndConditionalRenderNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_nv_conservative_raster()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glSubpixelPrecisionBiasNV = get_function<PFNGLSUBPIXELPRECISIONBIASNVPROC>("glSubpixelPrecisionBiasNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_nv_conservative_raster_dilate()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glConservativeRasterParameterfNV = get_function<PFNGLCONSERVATIVERASTERPARAMETERFNVPROC>("glConservativeRasterParameterfNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_nv_conservative_raster_pre_snap_triangles()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glConservativeRasterParameteriNV = get_function<PFNGLCONSERVATIVERASTERPARAMETERINVPROC>("glConservativeRasterParameteriNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_nv_draw_vulkan_image()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glDrawVkImageNV = get_function<PFNGLDRAWVKIMAGENVPROC>("glDrawVkImageNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetVkProcAddrNV = get_function<PFNGLGETVKPROCADDRNVPROC>("glGetVkProcAddrNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glWaitVkSemaphoreNV = get_function<PFNGLWAITVKSEMAPHORENVPROC>("glWaitVkSemaphoreNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glSignalVkSemaphoreNV = get_function<PFNGLSIGNALVKSEMAPHORENVPROC>("glSignalVkSemaphoreNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glSignalVkFenceNV = get_function<PFNGLSIGNALVKFENCENVPROC>("glSignalVkFenceNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_nv_fragment_coverage_to_color()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glFragmentCoverageColorNV = get_function<PFNGLFRAGMENTCOVERAGECOLORNVPROC>("glFragmentCoverageColorNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_nv_framebuffer_mixed_samples()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glCoverageModulationTableNV = get_function<PFNGLCOVERAGEMODULATIONTABLENVPROC>("glCoverageModulationTableNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetCoverageModulationTableNV = get_function<PFNGLGETCOVERAGEMODULATIONTABLENVPROC>("glGetCoverageModulationTableNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCoverageModulationNV = get_function<PFNGLCOVERAGEMODULATIONNVPROC>("glCoverageModulationNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_nv_framebuffer_multisample_coverage()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glRenderbufferStorageMultisampleCoverageNV = get_function<PFNGLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENVPROC>("glRenderbufferStorageMultisampleCoverageNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_nv_gpu_shader5()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glUniform1i64NV = get_function<PFNGLUNIFORM1I64NVPROC>("glUniform1i64NV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform2i64NV = get_function<PFNGLUNIFORM2I64NVPROC>("glUniform2i64NV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform3i64NV = get_function<PFNGLUNIFORM3I64NVPROC>("glUniform3i64NV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform4i64NV = get_function<PFNGLUNIFORM4I64NVPROC>("glUniform4i64NV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform1i64vNV = get_function<PFNGLUNIFORM1I64VNVPROC>("glUniform1i64vNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform2i64vNV = get_function<PFNGLUNIFORM2I64VNVPROC>("glUniform2i64vNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform3i64vNV = get_function<PFNGLUNIFORM3I64VNVPROC>("glUniform3i64vNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform4i64vNV = get_function<PFNGLUNIFORM4I64VNVPROC>("glUniform4i64vNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform1ui64NV = get_function<PFNGLUNIFORM1UI64NVPROC>("glUniform1ui64NV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform2ui64NV = get_function<PFNGLUNIFORM2UI64NVPROC>("glUniform2ui64NV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform3ui64NV = get_function<PFNGLUNIFORM3UI64NVPROC>("glUniform3ui64NV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform4ui64NV = get_function<PFNGLUNIFORM4UI64NVPROC>("glUniform4ui64NV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform1ui64vNV = get_function<PFNGLUNIFORM1UI64VNVPROC>("glUniform1ui64vNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform2ui64vNV = get_function<PFNGLUNIFORM2UI64VNVPROC>("glUniform2ui64vNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform3ui64vNV = get_function<PFNGLUNIFORM3UI64VNVPROC>("glUniform3ui64vNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniform4ui64vNV = get_function<PFNGLUNIFORM4UI64VNVPROC>("glUniform4ui64vNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetUniformi64vNV = get_function<PFNGLGETUNIFORMI64VNVPROC>("glGetUniformi64vNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform1i64NV = get_function<PFNGLPROGRAMUNIFORM1I64NVPROC>("glProgramUniform1i64NV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform2i64NV = get_function<PFNGLPROGRAMUNIFORM2I64NVPROC>("glProgramUniform2i64NV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform3i64NV = get_function<PFNGLPROGRAMUNIFORM3I64NVPROC>("glProgramUniform3i64NV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform4i64NV = get_function<PFNGLPROGRAMUNIFORM4I64NVPROC>("glProgramUniform4i64NV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform1i64vNV = get_function<PFNGLPROGRAMUNIFORM1I64VNVPROC>("glProgramUniform1i64vNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform2i64vNV = get_function<PFNGLPROGRAMUNIFORM2I64VNVPROC>("glProgramUniform2i64vNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform3i64vNV = get_function<PFNGLPROGRAMUNIFORM3I64VNVPROC>("glProgramUniform3i64vNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform4i64vNV = get_function<PFNGLPROGRAMUNIFORM4I64VNVPROC>("glProgramUniform4i64vNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform1ui64NV = get_function<PFNGLPROGRAMUNIFORM1UI64NVPROC>("glProgramUniform1ui64NV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform2ui64NV = get_function<PFNGLPROGRAMUNIFORM2UI64NVPROC>("glProgramUniform2ui64NV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform3ui64NV = get_function<PFNGLPROGRAMUNIFORM3UI64NVPROC>("glProgramUniform3ui64NV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform4ui64NV = get_function<PFNGLPROGRAMUNIFORM4UI64NVPROC>("glProgramUniform4ui64NV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform1ui64vNV = get_function<PFNGLPROGRAMUNIFORM1UI64VNVPROC>("glProgramUniform1ui64vNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform2ui64vNV = get_function<PFNGLPROGRAMUNIFORM2UI64VNVPROC>("glProgramUniform2ui64vNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform3ui64vNV = get_function<PFNGLPROGRAMUNIFORM3UI64VNVPROC>("glProgramUniform3ui64vNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniform4ui64vNV = get_function<PFNGLPROGRAMUNIFORM4UI64VNVPROC>("glProgramUniform4ui64vNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_nv_internalformat_sample_query()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glGetInternalformatSampleivNV = get_function<PFNGLGETINTERNALFORMATSAMPLEIVNVPROC>("glGetInternalformatSampleivNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_nv_path_rendering()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glGenPathsNV = get_function<PFNGLGENPATHSNVPROC>("glGenPathsNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glDeletePathsNV = get_function<PFNGLDELETEPATHSNVPROC>("glDeletePathsNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glIsPathNV = get_function<PFNGLISPATHNVPROC>("glIsPathNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glPathCommandsNV = get_function<PFNGLPATHCOMMANDSNVPROC>("glPathCommandsNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glPathCoordsNV = get_function<PFNGLPATHCOORDSNVPROC>("glPathCoordsNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glPathSubCommandsNV = get_function<PFNGLPATHSUBCOMMANDSNVPROC>("glPathSubCommandsNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glPathSubCoordsNV = get_function<PFNGLPATHSUBCOORDSNVPROC>("glPathSubCoordsNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glPathStringNV = get_function<PFNGLPATHSTRINGNVPROC>("glPathStringNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glPathGlyphsNV = get_function<PFNGLPATHGLYPHSNVPROC>("glPathGlyphsNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glPathGlyphRangeNV = get_function<PFNGLPATHGLYPHRANGENVPROC>("glPathGlyphRangeNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glWeightPathsNV = get_function<PFNGLWEIGHTPATHSNVPROC>("glWeightPathsNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCopyPathNV = get_function<PFNGLCOPYPATHNVPROC>("glCopyPathNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glInterpolatePathsNV = get_function<PFNGLINTERPOLATEPATHSNVPROC>("glInterpolatePathsNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTransformPathNV = get_function<PFNGLTRANSFORMPATHNVPROC>("glTransformPathNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glPathParameterivNV = get_function<PFNGLPATHPARAMETERIVNVPROC>("glPathParameterivNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glPathParameteriNV = get_function<PFNGLPATHPARAMETERINVPROC>("glPathParameteriNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glPathParameterfvNV = get_function<PFNGLPATHPARAMETERFVNVPROC>("glPathParameterfvNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glPathParameterfNV = get_function<PFNGLPATHPARAMETERFNVPROC>("glPathParameterfNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glPathDashArrayNV = get_function<PFNGLPATHDASHARRAYNVPROC>("glPathDashArrayNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glPathStencilFuncNV = get_function<PFNGLPATHSTENCILFUNCNVPROC>("glPathStencilFuncNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glPathStencilDepthOffsetNV = get_function<PFNGLPATHSTENCILDEPTHOFFSETNVPROC>("glPathStencilDepthOffsetNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glStencilFillPathNV = get_function<PFNGLSTENCILFILLPATHNVPROC>("glStencilFillPathNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glStencilStrokePathNV = get_function<PFNGLSTENCILSTROKEPATHNVPROC>("glStencilStrokePathNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glStencilFillPathInstancedNV = get_function<PFNGLSTENCILFILLPATHINSTANCEDNVPROC>("glStencilFillPathInstancedNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glStencilStrokePathInstancedNV = get_function<PFNGLSTENCILSTROKEPATHINSTANCEDNVPROC>("glStencilStrokePathInstancedNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glPathCoverDepthFuncNV = get_function<PFNGLPATHCOVERDEPTHFUNCNVPROC>("glPathCoverDepthFuncNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCoverFillPathNV = get_function<PFNGLCOVERFILLPATHNVPROC>("glCoverFillPathNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCoverStrokePathNV = get_function<PFNGLCOVERSTROKEPATHNVPROC>("glCoverStrokePathNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCoverFillPathInstancedNV = get_function<PFNGLCOVERFILLPATHINSTANCEDNVPROC>("glCoverFillPathInstancedNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glCoverStrokePathInstancedNV = get_function<PFNGLCOVERSTROKEPATHINSTANCEDNVPROC>("glCoverStrokePathInstancedNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetPathParameterivNV = get_function<PFNGLGETPATHPARAMETERIVNVPROC>("glGetPathParameterivNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetPathParameterfvNV = get_function<PFNGLGETPATHPARAMETERFVNVPROC>("glGetPathParameterfvNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetPathCommandsNV = get_function<PFNGLGETPATHCOMMANDSNVPROC>("glGetPathCommandsNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetPathCoordsNV = get_function<PFNGLGETPATHCOORDSNVPROC>("glGetPathCoordsNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetPathDashArrayNV = get_function<PFNGLGETPATHDASHARRAYNVPROC>("glGetPathDashArrayNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetPathMetricsNV = get_function<PFNGLGETPATHMETRICSNVPROC>("glGetPathMetricsNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetPathMetricRangeNV = get_function<PFNGLGETPATHMETRICRANGENVPROC>("glGetPathMetricRangeNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetPathSpacingNV = get_function<PFNGLGETPATHSPACINGNVPROC>("glGetPathSpacingNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glIsPointInFillPathNV = get_function<PFNGLISPOINTINFILLPATHNVPROC>("glIsPointInFillPathNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glIsPointInStrokePathNV = get_function<PFNGLISPOINTINSTROKEPATHNVPROC>("glIsPointInStrokePathNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetPathLengthNV = get_function<PFNGLGETPATHLENGTHNVPROC>("glGetPathLengthNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glPointAlongPathNV = get_function<PFNGLPOINTALONGPATHNVPROC>("glPointAlongPathNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMatrixLoad3x2fNV = get_function<PFNGLMATRIXLOAD3X2FNVPROC>("glMatrixLoad3x2fNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMatrixLoad3x3fNV = get_function<PFNGLMATRIXLOAD3X3FNVPROC>("glMatrixLoad3x3fNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMatrixLoadTranspose3x3fNV = get_function<PFNGLMATRIXLOADTRANSPOSE3X3FNVPROC>("glMatrixLoadTranspose3x3fNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMatrixMult3x2fNV = get_function<PFNGLMATRIXMULT3X2FNVPROC>("glMatrixMult3x2fNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMatrixMult3x3fNV = get_function<PFNGLMATRIXMULT3X3FNVPROC>("glMatrixMult3x3fNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMatrixMultTranspose3x3fNV = get_function<PFNGLMATRIXMULTTRANSPOSE3X3FNVPROC>("glMatrixMultTranspose3x3fNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glStencilThenCoverFillPathNV = get_function<PFNGLSTENCILTHENCOVERFILLPATHNVPROC>("glStencilThenCoverFillPathNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glStencilThenCoverStrokePathNV = get_function<PFNGLSTENCILTHENCOVERSTROKEPATHNVPROC>("glStencilThenCoverStrokePathNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glStencilThenCoverFillPathInstancedNV = get_function<PFNGLSTENCILTHENCOVERFILLPATHINSTANCEDNVPROC>("glStencilThenCoverFillPathInstancedNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glStencilThenCoverStrokePathInstancedNV = get_function<PFNGLSTENCILTHENCOVERSTROKEPATHINSTANCEDNVPROC>("glStencilThenCoverStrokePathInstancedNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glPathGlyphIndexRangeNV = get_function<PFNGLPATHGLYPHINDEXRANGENVPROC>("glPathGlyphIndexRangeNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glPathGlyphIndexArrayNV = get_function<PFNGLPATHGLYPHINDEXARRAYNVPROC>("glPathGlyphIndexArrayNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glPathMemoryGlyphIndexArrayNV = get_function<PFNGLPATHMEMORYGLYPHINDEXARRAYNVPROC>("glPathMemoryGlyphIndexArrayNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramPathFragmentInputGenNV = get_function<PFNGLPROGRAMPATHFRAGMENTINPUTGENNVPROC>("glProgramPathFragmentInputGenNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetProgramResourcefvNV = get_function<PFNGLGETPROGRAMRESOURCEFVNVPROC>("glGetProgramResourcefvNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_nv_sample_locations()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glFramebufferSampleLocationsfvNV = get_function<PFNGLFRAMEBUFFERSAMPLELOCATIONSFVNVPROC>("glFramebufferSampleLocationsfvNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNamedFramebufferSampleLocationsfvNV = get_function<PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVNVPROC>("glNamedFramebufferSampleLocationsfvNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glResolveDepthValuesNV = get_function<PFNGLRESOLVEDEPTHVALUESNVPROC>("glResolveDepthValuesNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_nv_shader_buffer_load()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glMakeBufferResidentNV = get_function<PFNGLMAKEBUFFERRESIDENTNVPROC>("glMakeBufferResidentNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMakeBufferNonResidentNV = get_function<PFNGLMAKEBUFFERNONRESIDENTNVPROC>("glMakeBufferNonResidentNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glIsBufferResidentNV = get_function<PFNGLISBUFFERRESIDENTNVPROC>("glIsBufferResidentNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMakeNamedBufferResidentNV = get_function<PFNGLMAKENAMEDBUFFERRESIDENTNVPROC>("glMakeNamedBufferResidentNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glMakeNamedBufferNonResidentNV = get_function<PFNGLMAKENAMEDBUFFERNONRESIDENTNVPROC>("glMakeNamedBufferNonResidentNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glIsNamedBufferResidentNV = get_function<PFNGLISNAMEDBUFFERRESIDENTNVPROC>("glIsNamedBufferResidentNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetBufferParameterui64vNV = get_function<PFNGLGETBUFFERPARAMETERUI64VNVPROC>("glGetBufferParameterui64vNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetNamedBufferParameterui64vNV = get_function<PFNGLGETNAMEDBUFFERPARAMETERUI64VNVPROC>("glGetNamedBufferParameterui64vNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetIntegerui64vNV = get_function<PFNGLGETINTEGERUI64VNVPROC>("glGetIntegerui64vNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniformui64NV = get_function<PFNGLUNIFORMUI64NVPROC>("glUniformui64NV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glUniformui64vNV = get_function<PFNGLUNIFORMUI64VNVPROC>("glUniformui64vNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetUniformui64vNV = get_function<PFNGLGETUNIFORMUI64VNVPROC>("glGetUniformui64vNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniformui64NV = get_function<PFNGLPROGRAMUNIFORMUI64NVPROC>("glProgramUniformui64NV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glProgramUniformui64vNV = get_function<PFNGLPROGRAMUNIFORMUI64VNVPROC>("glProgramUniformui64vNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_nv_texture_barrier()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glTextureBarrierNV = get_function<PFNGLTEXTUREBARRIERNVPROC>("glTextureBarrierNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_nv_vertex_attrib_integer_64bit()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glVertexAttribL1i64NV = get_function<PFNGLVERTEXATTRIBL1I64NVPROC>("glVertexAttribL1i64NV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribL2i64NV = get_function<PFNGLVERTEXATTRIBL2I64NVPROC>("glVertexAttribL2i64NV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribL3i64NV = get_function<PFNGLVERTEXATTRIBL3I64NVPROC>("glVertexAttribL3i64NV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribL4i64NV = get_function<PFNGLVERTEXATTRIBL4I64NVPROC>("glVertexAttribL4i64NV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribL1i64vNV = get_function<PFNGLVERTEXATTRIBL1I64VNVPROC>("glVertexAttribL1i64vNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribL2i64vNV = get_function<PFNGLVERTEXATTRIBL2I64VNVPROC>("glVertexAttribL2i64vNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribL3i64vNV = get_function<PFNGLVERTEXATTRIBL3I64VNVPROC>("glVertexAttribL3i64vNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribL4i64vNV = get_function<PFNGLVERTEXATTRIBL4I64VNVPROC>("glVertexAttribL4i64vNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribL1ui64NV = get_function<PFNGLVERTEXATTRIBL1UI64NVPROC>("glVertexAttribL1ui64NV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribL2ui64NV = get_function<PFNGLVERTEXATTRIBL2UI64NVPROC>("glVertexAttribL2ui64NV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribL3ui64NV = get_function<PFNGLVERTEXATTRIBL3UI64NVPROC>("glVertexAttribL3ui64NV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribL4ui64NV = get_function<PFNGLVERTEXATTRIBL4UI64NVPROC>("glVertexAttribL4ui64NV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribL1ui64vNV = get_function<PFNGLVERTEXATTRIBL1UI64VNVPROC>("glVertexAttribL1ui64vNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribL2ui64vNV = get_function<PFNGLVERTEXATTRIBL2UI64VNVPROC>("glVertexAttribL2ui64vNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribL3ui64vNV = get_function<PFNGLVERTEXATTRIBL3UI64VNVPROC>("glVertexAttribL3ui64vNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribL4ui64vNV = get_function<PFNGLVERTEXATTRIBL4UI64VNVPROC>("glVertexAttribL4ui64vNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetVertexAttribLi64vNV = get_function<PFNGLGETVERTEXATTRIBLI64VNVPROC>("glGetVertexAttribLi64vNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetVertexAttribLui64vNV = get_function<PFNGLGETVERTEXATTRIBLUI64VNVPROC>("glGetVertexAttribLui64vNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribLFormatNV = get_function<PFNGLVERTEXATTRIBLFORMATNVPROC>("glVertexAttribLFormatNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_nv_vertex_buffer_unified_memory()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glBufferAddressRangeNV = get_function<PFNGLBUFFERADDRESSRANGENVPROC>("glBufferAddressRangeNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexFormatNV = get_function<PFNGLVERTEXFORMATNVPROC>("glVertexFormatNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glNormalFormatNV = get_function<PFNGLNORMALFORMATNVPROC>("glNormalFormatNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glColorFormatNV = get_function<PFNGLCOLORFORMATNVPROC>("glColorFormatNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glIndexFormatNV = get_function<PFNGLINDEXFORMATNVPROC>("glIndexFormatNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glTexCoordFormatNV = get_function<PFNGLTEXCOORDFORMATNVPROC>("glTexCoordFormatNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glEdgeFlagFormatNV = get_function<PFNGLEDGEFLAGFORMATNVPROC>("glEdgeFlagFormatNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glSecondaryColorFormatNV = get_function<PFNGLSECONDARYCOLORFORMATNVPROC>("glSecondaryColorFormatNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glFogCoordFormatNV = get_function<PFNGLFOGCOORDFORMATNVPROC>("glFogCoordFormatNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribFormatNV = get_function<PFNGLVERTEXATTRIBFORMATNVPROC>("glVertexAttribFormatNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glVertexAttribIFormatNV = get_function<PFNGLVERTEXATTRIBIFORMATNVPROC>("glVertexAttribIFormatNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glGetIntegerui64i_vNV = get_function<PFNGLGETINTEGERUI64I_VNVPROC>("glGetIntegerui64i_vNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_nv_viewport_swizzle()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glViewportSwizzleNV = get_function<PFNGLVIEWPORTSWIZZLENVPROC>("glViewportSwizzleNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_gl_ovr_multiview()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glFramebufferTextureMultiviewOVR = get_function<PFNGLFRAMEBUFFERTEXTUREMULTIVIEWOVRPROC>("glFramebufferTextureMultiviewOVR")) != nullptr;
    // clang-format on

    return result;
}

#pragma endregion

} // namespace

namespace framework::graphics::opengl::details
{
void init_gl_functions()
{
    // clang-format off
    gl_version_1_0_supported = ::init_gl_version_1_0();
    gl_version_1_1_supported = ::init_gl_version_1_1();
    gl_version_1_2_supported = ::init_gl_version_1_2();
    gl_version_1_3_supported = ::init_gl_version_1_3();
    gl_version_1_4_supported = ::init_gl_version_1_4();
    gl_version_1_5_supported = ::init_gl_version_1_5();
    gl_version_2_0_supported = ::init_gl_version_2_0();
    gl_version_2_1_supported = ::init_gl_version_2_1();
    gl_version_3_0_supported = ::init_gl_version_3_0();
    gl_version_3_1_supported = ::init_gl_version_3_1();
    gl_version_3_2_supported = ::init_gl_version_3_2();
    gl_version_3_3_supported = ::init_gl_version_3_3();
    gl_version_4_0_supported = ::init_gl_version_4_0();
    gl_version_4_1_supported = ::init_gl_version_4_1();
    gl_version_4_2_supported = ::init_gl_version_4_2();
    gl_version_4_3_supported = ::init_gl_version_4_3();
    gl_version_4_4_supported = ::init_gl_version_4_4();
    gl_version_4_5_supported = ::init_gl_version_4_5();
    gl_version_4_6_supported = ::init_gl_version_4_6();
    gl_arb_es3_2_compatibility_supported = ::init_gl_arb_es3_2_compatibility();
    gl_arb_bindless_texture_supported = ::init_gl_arb_bindless_texture();
    gl_arb_cl_event_supported = ::init_gl_arb_cl_event();
    gl_arb_compute_variable_group_size_supported = ::init_gl_arb_compute_variable_group_size();
    gl_arb_debug_output_supported = ::init_gl_arb_debug_output();
    gl_arb_draw_buffers_blend_supported = ::init_gl_arb_draw_buffers_blend();
    gl_arb_draw_instanced_supported = ::init_gl_arb_draw_instanced();
    gl_arb_geometry_shader4_supported = ::init_gl_arb_geometry_shader4();
    gl_arb_gl_spirv_supported = ::init_gl_arb_gl_spirv();
    gl_arb_gpu_shader_int64_supported = ::init_gl_arb_gpu_shader_int64();
    gl_arb_indirect_parameters_supported = ::init_gl_arb_indirect_parameters();
    gl_arb_instanced_arrays_supported = ::init_gl_arb_instanced_arrays();
    gl_arb_parallel_shader_compile_supported = ::init_gl_arb_parallel_shader_compile();
    gl_arb_robustness_supported = ::init_gl_arb_robustness();
    gl_arb_sample_locations_supported = ::init_gl_arb_sample_locations();
    gl_arb_sample_shading_supported = ::init_gl_arb_sample_shading();
    gl_arb_shading_language_include_supported = ::init_gl_arb_shading_language_include();
    gl_arb_sparse_buffer_supported = ::init_gl_arb_sparse_buffer();
    gl_arb_sparse_texture_supported = ::init_gl_arb_sparse_texture();
    gl_arb_texture_buffer_object_supported = ::init_gl_arb_texture_buffer_object();
    gl_khr_blend_equation_advanced_supported = ::init_gl_khr_blend_equation_advanced();
    gl_khr_parallel_shader_compile_supported = ::init_gl_khr_parallel_shader_compile();
    gl_amd_framebuffer_multisample_advanced_supported = ::init_gl_amd_framebuffer_multisample_advanced();
    gl_amd_performance_monitor_supported = ::init_gl_amd_performance_monitor();
    gl_ext_egl_image_storage_supported = ::init_gl_ext_egl_image_storage();
    gl_ext_debug_label_supported = ::init_gl_ext_debug_label();
    gl_ext_debug_marker_supported = ::init_gl_ext_debug_marker();
    gl_ext_direct_state_access_supported = ::init_gl_ext_direct_state_access();
    gl_ext_draw_instanced_supported = ::init_gl_ext_draw_instanced();
    gl_ext_polygon_offset_clamp_supported = ::init_gl_ext_polygon_offset_clamp();
    gl_ext_raster_multisample_supported = ::init_gl_ext_raster_multisample();
    gl_ext_separate_shader_objects_supported = ::init_gl_ext_separate_shader_objects();
    gl_ext_shader_framebuffer_fetch_non_coherent_supported = ::init_gl_ext_shader_framebuffer_fetch_non_coherent();
    gl_ext_window_rectangles_supported = ::init_gl_ext_window_rectangles();
    gl_intel_framebuffer_cmaa_supported = ::init_gl_intel_framebuffer_cmaa();
    gl_intel_performance_query_supported = ::init_gl_intel_performance_query();
    gl_nv_bindless_multi_draw_indirect_supported = ::init_gl_nv_bindless_multi_draw_indirect();
    gl_nv_bindless_multi_draw_indirect_count_supported = ::init_gl_nv_bindless_multi_draw_indirect_count();
    gl_nv_bindless_texture_supported = ::init_gl_nv_bindless_texture();
    gl_nv_blend_equation_advanced_supported = ::init_gl_nv_blend_equation_advanced();
    gl_nv_clip_space_w_scaling_supported = ::init_gl_nv_clip_space_w_scaling();
    gl_nv_command_list_supported = ::init_gl_nv_command_list();
    gl_nv_conditional_render_supported = ::init_gl_nv_conditional_render();
    gl_nv_conservative_raster_supported = ::init_gl_nv_conservative_raster();
    gl_nv_conservative_raster_dilate_supported = ::init_gl_nv_conservative_raster_dilate();
    gl_nv_conservative_raster_pre_snap_triangles_supported = ::init_gl_nv_conservative_raster_pre_snap_triangles();
    gl_nv_draw_vulkan_image_supported = ::init_gl_nv_draw_vulkan_image();
    gl_nv_fragment_coverage_to_color_supported = ::init_gl_nv_fragment_coverage_to_color();
    gl_nv_framebuffer_mixed_samples_supported = ::init_gl_nv_framebuffer_mixed_samples();
    gl_nv_framebuffer_multisample_coverage_supported = ::init_gl_nv_framebuffer_multisample_coverage();
    gl_nv_gpu_shader5_supported = ::init_gl_nv_gpu_shader5();
    gl_nv_internalformat_sample_query_supported = ::init_gl_nv_internalformat_sample_query();
    gl_nv_path_rendering_supported = ::init_gl_nv_path_rendering();
    gl_nv_sample_locations_supported = ::init_gl_nv_sample_locations();
    gl_nv_shader_buffer_load_supported = ::init_gl_nv_shader_buffer_load();
    gl_nv_texture_barrier_supported = ::init_gl_nv_texture_barrier();
    gl_nv_vertex_attrib_integer_64bit_supported = ::init_gl_nv_vertex_attrib_integer_64bit();
    gl_nv_vertex_buffer_unified_memory_supported = ::init_gl_nv_vertex_buffer_unified_memory();
    gl_nv_viewport_swizzle_supported = ::init_gl_nv_viewport_swizzle();
    gl_ovr_multiview_supported = ::init_gl_ovr_multiview();
    // clang-format on
}

} // namespace framework::graphics::opengl::details
