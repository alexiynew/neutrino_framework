

#ifndef GL_ARB_ES2_compatibility
#define GL_ARB_ES2_compatibility 1
#endif /* GL_ARB_ES2_compatibility */

#ifndef GL_ARB_ES3_1_compatibility
#define GL_ARB_ES3_1_compatibility 1
#endif /* GL_ARB_ES3_1_compatibility */

#ifndef GL_ARB_ES3_2_compatibility
#define GL_ARB_ES3_2_compatibility 1
#define GL_PRIMITIVE_BOUNDING_BOX_ARB 0x92BE
#define GL_MULTISAMPLE_LINE_WIDTH_RANGE_ARB 0x9381
#define GL_MULTISAMPLE_LINE_WIDTH_GRANULARITY_ARB 0x9382
typedef void(APIENTRYP PFNGLPRIMITIVEBOUNDINGBOXARBPROC)(GLfloat minX,
                                                         GLfloat minY,
                                                         GLfloat minZ,
                                                         GLfloat minW,
                                                         GLfloat maxX,
                                                         GLfloat maxY,
                                                         GLfloat maxZ,
                                                         GLfloat maxW);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glPrimitiveBoundingBoxARB(GLfloat minX,
                                              GLfloat minY,
                                              GLfloat minZ,
                                              GLfloat minW,
                                              GLfloat maxX,
                                              GLfloat maxY,
                                              GLfloat maxZ,
                                              GLfloat maxW);
#endif
#endif /* GL_ARB_ES3_2_compatibility */

#ifndef GL_ARB_ES3_compatibility
#define GL_ARB_ES3_compatibility 1
#endif /* GL_ARB_ES3_compatibility */

#ifndef GL_ARB_arrays_of_arrays
#define GL_ARB_arrays_of_arrays 1
#endif /* GL_ARB_arrays_of_arrays */

#ifndef GL_ARB_base_instance
#define GL_ARB_base_instance 1
#endif /* GL_ARB_base_instance */

#ifndef GL_ARB_bindless_texture
#define GL_ARB_bindless_texture 1
typedef uint64_t GLuint64EXT;
#define GL_UNSIGNED_INT64_ARB 0x140F
typedef GLuint64(APIENTRYP PFNGLGETTEXTUREHANDLEARBPROC)(GLuint texture);
typedef GLuint64(APIENTRYP PFNGLGETTEXTURESAMPLERHANDLEARBPROC)(GLuint texture, GLuint sampler);
typedef void(APIENTRYP PFNGLMAKETEXTUREHANDLERESIDENTARBPROC)(GLuint64 handle);
typedef void(APIENTRYP PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC)(GLuint64 handle);
typedef GLuint64(
APIENTRYP PFNGLGETIMAGEHANDLEARBPROC)(GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
typedef void(APIENTRYP PFNGLMAKEIMAGEHANDLERESIDENTARBPROC)(GLuint64 handle, GLenum access);
typedef void(APIENTRYP PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC)(GLuint64 handle);
typedef void(APIENTRYP PFNGLUNIFORMHANDLEUI64ARBPROC)(GLint location, GLuint64 value);
typedef void(APIENTRYP PFNGLUNIFORMHANDLEUI64VARBPROC)(GLint location, GLsizei count, const GLuint64* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC)(GLuint program, GLint location, GLuint64 value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC)(GLuint program,
                                                              GLint location,
                                                              GLsizei count,
                                                              const GLuint64* values);
typedef GLboolean(APIENTRYP PFNGLISTEXTUREHANDLERESIDENTARBPROC)(GLuint64 handle);
typedef GLboolean(APIENTRYP PFNGLISIMAGEHANDLERESIDENTARBPROC)(GLuint64 handle);
typedef void(APIENTRYP PFNGLVERTEXATTRIBL1UI64ARBPROC)(GLuint index, GLuint64EXT x);
typedef void(APIENTRYP PFNGLVERTEXATTRIBL1UI64VARBPROC)(GLuint index, const GLuint64EXT* v);
typedef void(APIENTRYP PFNGLGETVERTEXATTRIBLUI64VARBPROC)(GLuint index, GLenum pname, GLuint64EXT* params);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI GLuint64 APIENTRY glGetTextureHandleARB(GLuint texture);
GLAPI GLuint64 APIENTRY glGetTextureSamplerHandleARB(GLuint texture, GLuint sampler);
GLAPI void APIENTRY glMakeTextureHandleResidentARB(GLuint64 handle);
GLAPI void APIENTRY glMakeTextureHandleNonResidentARB(GLuint64 handle);
GLAPI GLuint64 APIENTRY glGetImageHandleARB(GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
GLAPI void APIENTRY glMakeImageHandleResidentARB(GLuint64 handle, GLenum access);
GLAPI void APIENTRY glMakeImageHandleNonResidentARB(GLuint64 handle);
GLAPI void APIENTRY glUniformHandleui64ARB(GLint location, GLuint64 value);
GLAPI void APIENTRY glUniformHandleui64vARB(GLint location, GLsizei count, const GLuint64* value);
GLAPI void APIENTRY glProgramUniformHandleui64ARB(GLuint program, GLint location, GLuint64 value);
GLAPI void APIENTRY glProgramUniformHandleui64vARB(GLuint program,
                                                   GLint location,
                                                   GLsizei count,
                                                   const GLuint64* values);
GLAPI GLboolean APIENTRY glIsTextureHandleResidentARB(GLuint64 handle);
GLAPI GLboolean APIENTRY glIsImageHandleResidentARB(GLuint64 handle);
GLAPI void APIENTRY glVertexAttribL1ui64ARB(GLuint index, GLuint64EXT x);
GLAPI void APIENTRY glVertexAttribL1ui64vARB(GLuint index, const GLuint64EXT* v);
GLAPI void APIENTRY glGetVertexAttribLui64vARB(GLuint index, GLenum pname, GLuint64EXT* params);
#endif
#endif /* GL_ARB_bindless_texture */

#ifndef GL_ARB_blend_func_extended
#define GL_ARB_blend_func_extended 1
#endif /* GL_ARB_blend_func_extended */

#ifndef GL_ARB_buffer_storage
#define GL_ARB_buffer_storage 1
#endif /* GL_ARB_buffer_storage */

#ifndef GL_ARB_cl_event
#define GL_ARB_cl_event 1
struct _cl_context;
struct _cl_event;
#define GL_SYNC_CL_EVENT_ARB 0x8240
#define GL_SYNC_CL_EVENT_COMPLETE_ARB 0x8241
typedef GLsync(APIENTRYP PFNGLCREATESYNCFROMCLEVENTARBPROC)(struct _cl_context* context,
                                                            struct _cl_event* event,
                                                            GLbitfield flags);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI GLsync APIENTRY glCreateSyncFromCLeventARB(struct _cl_context* context,
                                                 struct _cl_event* event,
                                                 GLbitfield flags);
#endif
#endif /* GL_ARB_cl_event */

#ifndef GL_ARB_clear_buffer_object
#define GL_ARB_clear_buffer_object 1
#endif /* GL_ARB_clear_buffer_object */

#ifndef GL_ARB_clear_texture
#define GL_ARB_clear_texture 1
#endif /* GL_ARB_clear_texture */

#ifndef GL_ARB_clip_control
#define GL_ARB_clip_control 1
#endif /* GL_ARB_clip_control */

#ifndef GL_ARB_compressed_texture_pixel_storage
#define GL_ARB_compressed_texture_pixel_storage 1
#endif /* GL_ARB_compressed_texture_pixel_storage */

#ifndef GL_ARB_compute_shader
#define GL_ARB_compute_shader 1
#endif /* GL_ARB_compute_shader */

#ifndef GL_ARB_compute_variable_group_size
#define GL_ARB_compute_variable_group_size 1
#define GL_MAX_COMPUTE_VARIABLE_GROUP_INVOCATIONS_ARB 0x9344
#define GL_MAX_COMPUTE_FIXED_GROUP_INVOCATIONS_ARB 0x90EB
#define GL_MAX_COMPUTE_VARIABLE_GROUP_SIZE_ARB 0x9345
#define GL_MAX_COMPUTE_FIXED_GROUP_SIZE_ARB 0x91BF
typedef void(APIENTRYP PFNGLDISPATCHCOMPUTEGROUPSIZEARBPROC)(GLuint num_groups_x,
                                                             GLuint num_groups_y,
                                                             GLuint num_groups_z,
                                                             GLuint group_size_x,
                                                             GLuint group_size_y,
                                                             GLuint group_size_z);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glDispatchComputeGroupSizeARB(GLuint num_groups_x,
                                                  GLuint num_groups_y,
                                                  GLuint num_groups_z,
                                                  GLuint group_size_x,
                                                  GLuint group_size_y,
                                                  GLuint group_size_z);
#endif
#endif /* GL_ARB_compute_variable_group_size */

#ifndef GL_ARB_conditional_render_inverted
#define GL_ARB_conditional_render_inverted 1
#endif /* GL_ARB_conditional_render_inverted */

#ifndef GL_ARB_conservative_depth
#define GL_ARB_conservative_depth 1
#endif /* GL_ARB_conservative_depth */

#ifndef GL_ARB_copy_buffer
#define GL_ARB_copy_buffer 1
#endif /* GL_ARB_copy_buffer */

#ifndef GL_ARB_copy_image
#define GL_ARB_copy_image 1
#endif /* GL_ARB_copy_image */

#ifndef GL_ARB_cull_distance
#define GL_ARB_cull_distance 1
#endif /* GL_ARB_cull_distance */

#ifndef GL_ARB_debug_output
#define GL_ARB_debug_output 1
typedef void(APIENTRY* GLDEBUGPROCARB)(GLenum source,
                                       GLenum type,
                                       GLuint id,
                                       GLenum severity,
                                       GLsizei length,
                                       const GLchar* message,
                                       const void* userParam);
#define GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB 0x8242
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH_ARB 0x8243
#define GL_DEBUG_CALLBACK_FUNCTION_ARB 0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM_ARB 0x8245
#define GL_DEBUG_SOURCE_API_ARB 0x8246
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM_ARB 0x8247
#define GL_DEBUG_SOURCE_SHADER_COMPILER_ARB 0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY_ARB 0x8249
#define GL_DEBUG_SOURCE_APPLICATION_ARB 0x824A
#define GL_DEBUG_SOURCE_OTHER_ARB 0x824B
#define GL_DEBUG_TYPE_ERROR_ARB 0x824C
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_ARB 0x824D
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_ARB 0x824E
#define GL_DEBUG_TYPE_PORTABILITY_ARB 0x824F
#define GL_DEBUG_TYPE_PERFORMANCE_ARB 0x8250
#define GL_DEBUG_TYPE_OTHER_ARB 0x8251
#define GL_MAX_DEBUG_MESSAGE_LENGTH_ARB 0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES_ARB 0x9144
#define GL_DEBUG_LOGGED_MESSAGES_ARB 0x9145
#define GL_DEBUG_SEVERITY_HIGH_ARB 0x9146
#define GL_DEBUG_SEVERITY_MEDIUM_ARB 0x9147
#define GL_DEBUG_SEVERITY_LOW_ARB 0x9148
typedef void(APIENTRYP PFNGLDEBUGMESSAGECONTROLARBPROC)(GLenum source,
                                                        GLenum type,
                                                        GLenum severity,
                                                        GLsizei count,
                                                        const GLuint* ids,
                                                        GLboolean enabled);
typedef void(APIENTRYP PFNGLDEBUGMESSAGEINSERTARBPROC)(GLenum source,
                                                       GLenum type,
                                                       GLuint id,
                                                       GLenum severity,
                                                       GLsizei length,
                                                       const GLchar* buf);
typedef void(APIENTRYP PFNGLDEBUGMESSAGECALLBACKARBPROC)(GLDEBUGPROCARB callback, const void* userParam);
typedef GLuint(APIENTRYP PFNGLGETDEBUGMESSAGELOGARBPROC)(GLuint count,
                                                         GLsizei bufSize,
                                                         GLenum* sources,
                                                         GLenum* types,
                                                         GLuint* ids,
                                                         GLenum* severities,
                                                         GLsizei* lengths,
                                                         GLchar* messageLog);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glDebugMessageControlARB(GLenum source,
                                             GLenum type,
                                             GLenum severity,
                                             GLsizei count,
                                             const GLuint* ids,
                                             GLboolean enabled);
GLAPI void APIENTRY
glDebugMessageInsertARB(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf);
GLAPI void APIENTRY glDebugMessageCallbackARB(GLDEBUGPROCARB callback, const void* userParam);
GLAPI GLuint APIENTRY glGetDebugMessageLogARB(GLuint count,
                                              GLsizei bufSize,
                                              GLenum* sources,
                                              GLenum* types,
                                              GLuint* ids,
                                              GLenum* severities,
                                              GLsizei* lengths,
                                              GLchar* messageLog);
#endif
#endif /* GL_ARB_debug_output */

#ifndef GL_ARB_depth_buffer_float
#define GL_ARB_depth_buffer_float 1
#endif /* GL_ARB_depth_buffer_float */

#ifndef GL_ARB_depth_clamp
#define GL_ARB_depth_clamp 1
#endif /* GL_ARB_depth_clamp */

#ifndef GL_ARB_derivative_control
#define GL_ARB_derivative_control 1
#endif /* GL_ARB_derivative_control */

#ifndef GL_ARB_direct_state_access
#define GL_ARB_direct_state_access 1
#endif /* GL_ARB_direct_state_access */

#ifndef GL_ARB_draw_buffers_blend
#define GL_ARB_draw_buffers_blend 1
typedef void(APIENTRYP PFNGLBLENDEQUATIONIARBPROC)(GLuint buf, GLenum mode);
typedef void(APIENTRYP PFNGLBLENDEQUATIONSEPARATEIARBPROC)(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
typedef void(APIENTRYP PFNGLBLENDFUNCIARBPROC)(GLuint buf, GLenum src, GLenum dst);
typedef void(
APIENTRYP PFNGLBLENDFUNCSEPARATEIARBPROC)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glBlendEquationiARB(GLuint buf, GLenum mode);
GLAPI void APIENTRY glBlendEquationSeparateiARB(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
GLAPI void APIENTRY glBlendFunciARB(GLuint buf, GLenum src, GLenum dst);
GLAPI void APIENTRY glBlendFuncSeparateiARB(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
#endif
#endif /* GL_ARB_draw_buffers_blend */

#ifndef GL_ARB_draw_elements_base_vertex
#define GL_ARB_draw_elements_base_vertex 1
#endif /* GL_ARB_draw_elements_base_vertex */

#ifndef GL_ARB_draw_indirect
#define GL_ARB_draw_indirect 1
#endif /* GL_ARB_draw_indirect */

#ifndef GL_ARB_draw_instanced
#define GL_ARB_draw_instanced 1
typedef void(APIENTRYP PFNGLDRAWARRAYSINSTANCEDARBPROC)(GLenum mode, GLint first, GLsizei count, GLsizei primcount);
typedef void(APIENTRYP PFNGLDRAWELEMENTSINSTANCEDARBPROC)(GLenum mode,
                                                          GLsizei count,
                                                          GLenum type,
                                                          const void* indices,
                                                          GLsizei primcount);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glDrawArraysInstancedARB(GLenum mode, GLint first, GLsizei count, GLsizei primcount);
GLAPI void APIENTRY
glDrawElementsInstancedARB(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei primcount);
#endif
#endif /* GL_ARB_draw_instanced */

#ifndef GL_ARB_enhanced_layouts
#define GL_ARB_enhanced_layouts 1
#endif /* GL_ARB_enhanced_layouts */

#ifndef GL_ARB_explicit_attrib_location
#define GL_ARB_explicit_attrib_location 1
#endif /* GL_ARB_explicit_attrib_location */

#ifndef GL_ARB_explicit_uniform_location
#define GL_ARB_explicit_uniform_location 1
#endif /* GL_ARB_explicit_uniform_location */

#ifndef GL_ARB_fragment_coord_conventions
#define GL_ARB_fragment_coord_conventions 1
#endif /* GL_ARB_fragment_coord_conventions */

#ifndef GL_ARB_fragment_layer_viewport
#define GL_ARB_fragment_layer_viewport 1
#endif /* GL_ARB_fragment_layer_viewport */

#ifndef GL_ARB_fragment_shader_interlock
#define GL_ARB_fragment_shader_interlock 1
#endif /* GL_ARB_fragment_shader_interlock */

#ifndef GL_ARB_framebuffer_no_attachments
#define GL_ARB_framebuffer_no_attachments 1
#endif /* GL_ARB_framebuffer_no_attachments */

#ifndef GL_ARB_framebuffer_object
#define GL_ARB_framebuffer_object 1
#endif /* GL_ARB_framebuffer_object */

#ifndef GL_ARB_framebuffer_sRGB
#define GL_ARB_framebuffer_sRGB 1
#endif /* GL_ARB_framebuffer_sRGB */

#ifndef GL_ARB_geometry_shader4
#define GL_ARB_geometry_shader4 1
#define GL_LINES_ADJACENCY_ARB 0x000A
#define GL_LINE_STRIP_ADJACENCY_ARB 0x000B
#define GL_TRIANGLES_ADJACENCY_ARB 0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY_ARB 0x000D
#define GL_PROGRAM_POINT_SIZE_ARB 0x8642
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_ARB 0x8C29
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED_ARB 0x8DA7
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_ARB 0x8DA8
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_ARB 0x8DA9
#define GL_GEOMETRY_SHADER_ARB 0x8DD9
#define GL_GEOMETRY_VERTICES_OUT_ARB 0x8DDA
#define GL_GEOMETRY_INPUT_TYPE_ARB 0x8DDB
#define GL_GEOMETRY_OUTPUT_TYPE_ARB 0x8DDC
#define GL_MAX_GEOMETRY_VARYING_COMPONENTS_ARB 0x8DDD
#define GL_MAX_VERTEX_VARYING_COMPONENTS_ARB 0x8DDE
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_ARB 0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES_ARB 0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_ARB 0x8DE1
typedef void(APIENTRYP PFNGLPROGRAMPARAMETERIARBPROC)(GLuint program, GLenum pname, GLint value);
typedef void(APIENTRYP PFNGLFRAMEBUFFERTEXTUREARBPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level);
typedef void(APIENTRYP PFNGLFRAMEBUFFERTEXTURELAYERARBPROC)(GLenum target,
                                                            GLenum attachment,
                                                            GLuint texture,
                                                            GLint level,
                                                            GLint layer);
typedef void(APIENTRYP PFNGLFRAMEBUFFERTEXTUREFACEARBPROC)(GLenum target,
                                                           GLenum attachment,
                                                           GLuint texture,
                                                           GLint level,
                                                           GLenum face);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glProgramParameteriARB(GLuint program, GLenum pname, GLint value);
GLAPI void APIENTRY glFramebufferTextureARB(GLenum target, GLenum attachment, GLuint texture, GLint level);
GLAPI void APIENTRY
glFramebufferTextureLayerARB(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
GLAPI void APIENTRY
glFramebufferTextureFaceARB(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);
#endif
#endif /* GL_ARB_geometry_shader4 */

#ifndef GL_ARB_get_program_binary
#define GL_ARB_get_program_binary 1
#endif /* GL_ARB_get_program_binary */

#ifndef GL_ARB_get_texture_sub_image
#define GL_ARB_get_texture_sub_image 1
#endif /* GL_ARB_get_texture_sub_image */

#ifndef GL_ARB_gl_spirv
#define GL_ARB_gl_spirv 1
#define GL_SHADER_BINARY_FORMAT_SPIR_V_ARB 0x9551
#define GL_SPIR_V_BINARY_ARB 0x9552
typedef void(APIENTRYP PFNGLSPECIALIZESHADERARBPROC)(GLuint shader,
                                                     const GLchar* pEntryPoint,
                                                     GLuint numSpecializationConstants,
                                                     const GLuint* pConstantIndex,
                                                     const GLuint* pConstantValue);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glSpecializeShaderARB(GLuint shader,
                                          const GLchar* pEntryPoint,
                                          GLuint numSpecializationConstants,
                                          const GLuint* pConstantIndex,
                                          const GLuint* pConstantValue);
#endif
#endif /* GL_ARB_gl_spirv */

#ifndef GL_ARB_gpu_shader5
#define GL_ARB_gpu_shader5 1
#endif /* GL_ARB_gpu_shader5 */

#ifndef GL_ARB_gpu_shader_fp64
#define GL_ARB_gpu_shader_fp64 1
#endif /* GL_ARB_gpu_shader_fp64 */

#ifndef GL_ARB_gpu_shader_int64
#define GL_ARB_gpu_shader_int64 1
#define GL_INT64_ARB 0x140E
#define GL_INT64_VEC2_ARB 0x8FE9
#define GL_INT64_VEC3_ARB 0x8FEA
#define GL_INT64_VEC4_ARB 0x8FEB
#define GL_UNSIGNED_INT64_VEC2_ARB 0x8FF5
#define GL_UNSIGNED_INT64_VEC3_ARB 0x8FF6
#define GL_UNSIGNED_INT64_VEC4_ARB 0x8FF7
typedef void(APIENTRYP PFNGLUNIFORM1I64ARBPROC)(GLint location, GLint64 x);
typedef void(APIENTRYP PFNGLUNIFORM2I64ARBPROC)(GLint location, GLint64 x, GLint64 y);
typedef void(APIENTRYP PFNGLUNIFORM3I64ARBPROC)(GLint location, GLint64 x, GLint64 y, GLint64 z);
typedef void(APIENTRYP PFNGLUNIFORM4I64ARBPROC)(GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w);
typedef void(APIENTRYP PFNGLUNIFORM1I64VARBPROC)(GLint location, GLsizei count, const GLint64* value);
typedef void(APIENTRYP PFNGLUNIFORM2I64VARBPROC)(GLint location, GLsizei count, const GLint64* value);
typedef void(APIENTRYP PFNGLUNIFORM3I64VARBPROC)(GLint location, GLsizei count, const GLint64* value);
typedef void(APIENTRYP PFNGLUNIFORM4I64VARBPROC)(GLint location, GLsizei count, const GLint64* value);
typedef void(APIENTRYP PFNGLUNIFORM1UI64ARBPROC)(GLint location, GLuint64 x);
typedef void(APIENTRYP PFNGLUNIFORM2UI64ARBPROC)(GLint location, GLuint64 x, GLuint64 y);
typedef void(APIENTRYP PFNGLUNIFORM3UI64ARBPROC)(GLint location, GLuint64 x, GLuint64 y, GLuint64 z);
typedef void(APIENTRYP PFNGLUNIFORM4UI64ARBPROC)(GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w);
typedef void(APIENTRYP PFNGLUNIFORM1UI64VARBPROC)(GLint location, GLsizei count, const GLuint64* value);
typedef void(APIENTRYP PFNGLUNIFORM2UI64VARBPROC)(GLint location, GLsizei count, const GLuint64* value);
typedef void(APIENTRYP PFNGLUNIFORM3UI64VARBPROC)(GLint location, GLsizei count, const GLuint64* value);
typedef void(APIENTRYP PFNGLUNIFORM4UI64VARBPROC)(GLint location, GLsizei count, const GLuint64* value);
typedef void(APIENTRYP PFNGLGETUNIFORMI64VARBPROC)(GLuint program, GLint location, GLint64* params);
typedef void(APIENTRYP PFNGLGETUNIFORMUI64VARBPROC)(GLuint program, GLint location, GLuint64* params);
typedef void(APIENTRYP PFNGLGETNUNIFORMI64VARBPROC)(GLuint program, GLint location, GLsizei bufSize, GLint64* params);
typedef void(APIENTRYP PFNGLGETNUNIFORMUI64VARBPROC)(GLuint program, GLint location, GLsizei bufSize, GLuint64* params);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM1I64ARBPROC)(GLuint program, GLint location, GLint64 x);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM2I64ARBPROC)(GLuint program, GLint location, GLint64 x, GLint64 y);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM3I64ARBPROC)(GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z);
typedef void(
APIENTRYP PFNGLPROGRAMUNIFORM4I64ARBPROC)(GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM1I64VARBPROC)(GLuint program,
                                                        GLint location,
                                                        GLsizei count,
                                                        const GLint64* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM2I64VARBPROC)(GLuint program,
                                                        GLint location,
                                                        GLsizei count,
                                                        const GLint64* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM3I64VARBPROC)(GLuint program,
                                                        GLint location,
                                                        GLsizei count,
                                                        const GLint64* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM4I64VARBPROC)(GLuint program,
                                                        GLint location,
                                                        GLsizei count,
                                                        const GLint64* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM1UI64ARBPROC)(GLuint program, GLint location, GLuint64 x);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM2UI64ARBPROC)(GLuint program, GLint location, GLuint64 x, GLuint64 y);
typedef void(
APIENTRYP PFNGLPROGRAMUNIFORM3UI64ARBPROC)(GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM4UI64ARBPROC)(GLuint program,
                                                        GLint location,
                                                        GLuint64 x,
                                                        GLuint64 y,
                                                        GLuint64 z,
                                                        GLuint64 w);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM1UI64VARBPROC)(GLuint program,
                                                         GLint location,
                                                         GLsizei count,
                                                         const GLuint64* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM2UI64VARBPROC)(GLuint program,
                                                         GLint location,
                                                         GLsizei count,
                                                         const GLuint64* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM3UI64VARBPROC)(GLuint program,
                                                         GLint location,
                                                         GLsizei count,
                                                         const GLuint64* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM4UI64VARBPROC)(GLuint program,
                                                         GLint location,
                                                         GLsizei count,
                                                         const GLuint64* value);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glUniform1i64ARB(GLint location, GLint64 x);
GLAPI void APIENTRY glUniform2i64ARB(GLint location, GLint64 x, GLint64 y);
GLAPI void APIENTRY glUniform3i64ARB(GLint location, GLint64 x, GLint64 y, GLint64 z);
GLAPI void APIENTRY glUniform4i64ARB(GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w);
GLAPI void APIENTRY glUniform1i64vARB(GLint location, GLsizei count, const GLint64* value);
GLAPI void APIENTRY glUniform2i64vARB(GLint location, GLsizei count, const GLint64* value);
GLAPI void APIENTRY glUniform3i64vARB(GLint location, GLsizei count, const GLint64* value);
GLAPI void APIENTRY glUniform4i64vARB(GLint location, GLsizei count, const GLint64* value);
GLAPI void APIENTRY glUniform1ui64ARB(GLint location, GLuint64 x);
GLAPI void APIENTRY glUniform2ui64ARB(GLint location, GLuint64 x, GLuint64 y);
GLAPI void APIENTRY glUniform3ui64ARB(GLint location, GLuint64 x, GLuint64 y, GLuint64 z);
GLAPI void APIENTRY glUniform4ui64ARB(GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w);
GLAPI void APIENTRY glUniform1ui64vARB(GLint location, GLsizei count, const GLuint64* value);
GLAPI void APIENTRY glUniform2ui64vARB(GLint location, GLsizei count, const GLuint64* value);
GLAPI void APIENTRY glUniform3ui64vARB(GLint location, GLsizei count, const GLuint64* value);
GLAPI void APIENTRY glUniform4ui64vARB(GLint location, GLsizei count, const GLuint64* value);
GLAPI void APIENTRY glGetUniformi64vARB(GLuint program, GLint location, GLint64* params);
GLAPI void APIENTRY glGetUniformui64vARB(GLuint program, GLint location, GLuint64* params);
GLAPI void APIENTRY glGetnUniformi64vARB(GLuint program, GLint location, GLsizei bufSize, GLint64* params);
GLAPI void APIENTRY glGetnUniformui64vARB(GLuint program, GLint location, GLsizei bufSize, GLuint64* params);
GLAPI void APIENTRY glProgramUniform1i64ARB(GLuint program, GLint location, GLint64 x);
GLAPI void APIENTRY glProgramUniform2i64ARB(GLuint program, GLint location, GLint64 x, GLint64 y);
GLAPI void APIENTRY glProgramUniform3i64ARB(GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z);
GLAPI void APIENTRY glProgramUniform4i64ARB(GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w);
GLAPI void APIENTRY glProgramUniform1i64vARB(GLuint program, GLint location, GLsizei count, const GLint64* value);
GLAPI void APIENTRY glProgramUniform2i64vARB(GLuint program, GLint location, GLsizei count, const GLint64* value);
GLAPI void APIENTRY glProgramUniform3i64vARB(GLuint program, GLint location, GLsizei count, const GLint64* value);
GLAPI void APIENTRY glProgramUniform4i64vARB(GLuint program, GLint location, GLsizei count, const GLint64* value);
GLAPI void APIENTRY glProgramUniform1ui64ARB(GLuint program, GLint location, GLuint64 x);
GLAPI void APIENTRY glProgramUniform2ui64ARB(GLuint program, GLint location, GLuint64 x, GLuint64 y);
GLAPI void APIENTRY glProgramUniform3ui64ARB(GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z);
GLAPI void APIENTRY
glProgramUniform4ui64ARB(GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w);
GLAPI void APIENTRY glProgramUniform1ui64vARB(GLuint program, GLint location, GLsizei count, const GLuint64* value);
GLAPI void APIENTRY glProgramUniform2ui64vARB(GLuint program, GLint location, GLsizei count, const GLuint64* value);
GLAPI void APIENTRY glProgramUniform3ui64vARB(GLuint program, GLint location, GLsizei count, const GLuint64* value);
GLAPI void APIENTRY glProgramUniform4ui64vARB(GLuint program, GLint location, GLsizei count, const GLuint64* value);
#endif
#endif /* GL_ARB_gpu_shader_int64 */

#ifndef GL_ARB_half_float_vertex
#define GL_ARB_half_float_vertex 1
#endif /* GL_ARB_half_float_vertex */

#ifndef GL_ARB_imaging
#define GL_ARB_imaging 1
#endif /* GL_ARB_imaging */

#ifndef GL_ARB_indirect_parameters
#define GL_ARB_indirect_parameters 1
#define GL_PARAMETER_BUFFER_ARB 0x80EE
#define GL_PARAMETER_BUFFER_BINDING_ARB 0x80EF
typedef void(APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTCOUNTARBPROC)(GLenum mode,
                                                                 const void* indirect,
                                                                 GLintptr drawcount,
                                                                 GLsizei maxdrawcount,
                                                                 GLsizei stride);
typedef void(APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTARBPROC)(GLenum mode,
                                                                   GLenum type,
                                                                   const void* indirect,
                                                                   GLintptr drawcount,
                                                                   GLsizei maxdrawcount,
                                                                   GLsizei stride);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glMultiDrawArraysIndirectCountARB(GLenum mode,
                                                      const void* indirect,
                                                      GLintptr drawcount,
                                                      GLsizei maxdrawcount,
                                                      GLsizei stride);
GLAPI void APIENTRY glMultiDrawElementsIndirectCountARB(GLenum mode,
                                                        GLenum type,
                                                        const void* indirect,
                                                        GLintptr drawcount,
                                                        GLsizei maxdrawcount,
                                                        GLsizei stride);
#endif
#endif /* GL_ARB_indirect_parameters */

#ifndef GL_ARB_instanced_arrays
#define GL_ARB_instanced_arrays 1
#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR_ARB 0x88FE
typedef void(APIENTRYP PFNGLVERTEXATTRIBDIVISORARBPROC)(GLuint index, GLuint divisor);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glVertexAttribDivisorARB(GLuint index, GLuint divisor);
#endif
#endif /* GL_ARB_instanced_arrays */

#ifndef GL_ARB_internalformat_query
#define GL_ARB_internalformat_query 1
#endif /* GL_ARB_internalformat_query */

#ifndef GL_ARB_internalformat_query2
#define GL_ARB_internalformat_query2 1
#define GL_SRGB_DECODE_ARB 0x8299
#endif /* GL_ARB_internalformat_query2 */

#ifndef GL_ARB_invalidate_subdata
#define GL_ARB_invalidate_subdata 1
#endif /* GL_ARB_invalidate_subdata */

#ifndef GL_ARB_map_buffer_alignment
#define GL_ARB_map_buffer_alignment 1
#endif /* GL_ARB_map_buffer_alignment */

#ifndef GL_ARB_map_buffer_range
#define GL_ARB_map_buffer_range 1
#endif /* GL_ARB_map_buffer_range */

#ifndef GL_ARB_multi_bind
#define GL_ARB_multi_bind 1
#endif /* GL_ARB_multi_bind */

#ifndef GL_ARB_multi_draw_indirect
#define GL_ARB_multi_draw_indirect 1
#endif /* GL_ARB_multi_draw_indirect */

#ifndef GL_ARB_occlusion_query2
#define GL_ARB_occlusion_query2 1
#endif /* GL_ARB_occlusion_query2 */

#ifndef GL_ARB_parallel_shader_compile
#define GL_ARB_parallel_shader_compile 1
#define GL_MAX_SHADER_COMPILER_THREADS_ARB 0x91B0
#define GL_COMPLETION_STATUS_ARB 0x91B1
typedef void(APIENTRYP PFNGLMAXSHADERCOMPILERTHREADSARBPROC)(GLuint count);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glMaxShaderCompilerThreadsARB(GLuint count);
#endif
#endif /* GL_ARB_parallel_shader_compile */

#ifndef GL_ARB_pipeline_statistics_query
#define GL_ARB_pipeline_statistics_query 1
#define GL_VERTICES_SUBMITTED_ARB 0x82EE
#define GL_PRIMITIVES_SUBMITTED_ARB 0x82EF
#define GL_VERTEX_SHADER_INVOCATIONS_ARB 0x82F0
#define GL_TESS_CONTROL_SHADER_PATCHES_ARB 0x82F1
#define GL_TESS_EVALUATION_SHADER_INVOCATIONS_ARB 0x82F2
#define GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED_ARB 0x82F3
#define GL_FRAGMENT_SHADER_INVOCATIONS_ARB 0x82F4
#define GL_COMPUTE_SHADER_INVOCATIONS_ARB 0x82F5
#define GL_CLIPPING_INPUT_PRIMITIVES_ARB 0x82F6
#define GL_CLIPPING_OUTPUT_PRIMITIVES_ARB 0x82F7
#endif /* GL_ARB_pipeline_statistics_query */

#ifndef GL_ARB_pixel_buffer_object
#define GL_ARB_pixel_buffer_object 1
#define GL_PIXEL_PACK_BUFFER_ARB 0x88EB
#define GL_PIXEL_UNPACK_BUFFER_ARB 0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING_ARB 0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING_ARB 0x88EF
#endif /* GL_ARB_pixel_buffer_object */

#ifndef GL_ARB_polygon_offset_clamp
#define GL_ARB_polygon_offset_clamp 1
#endif /* GL_ARB_polygon_offset_clamp */

#ifndef GL_ARB_post_depth_coverage
#define GL_ARB_post_depth_coverage 1
#endif /* GL_ARB_post_depth_coverage */

#ifndef GL_ARB_program_interface_query
#define GL_ARB_program_interface_query 1
#endif /* GL_ARB_program_interface_query */

#ifndef GL_ARB_provoking_vertex
#define GL_ARB_provoking_vertex 1
#endif /* GL_ARB_provoking_vertex */

#ifndef GL_ARB_query_buffer_object
#define GL_ARB_query_buffer_object 1
#endif /* GL_ARB_query_buffer_object */

#ifndef GL_ARB_robust_buffer_access_behavior
#define GL_ARB_robust_buffer_access_behavior 1
#endif /* GL_ARB_robust_buffer_access_behavior */

#ifndef GL_ARB_robustness
#define GL_ARB_robustness 1
#define GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB 0x00000004
#define GL_LOSE_CONTEXT_ON_RESET_ARB 0x8252
#define GL_GUILTY_CONTEXT_RESET_ARB 0x8253
#define GL_INNOCENT_CONTEXT_RESET_ARB 0x8254
#define GL_UNKNOWN_CONTEXT_RESET_ARB 0x8255
#define GL_RESET_NOTIFICATION_STRATEGY_ARB 0x8256
#define GL_NO_RESET_NOTIFICATION_ARB 0x8261
typedef GLenum(APIENTRYP PFNGLGETGRAPHICSRESETSTATUSARBPROC)(void);
typedef void(
APIENTRYP PFNGLGETNTEXIMAGEARBPROC)(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* img);
typedef void(APIENTRYP PFNGLREADNPIXELSARBPROC)(GLint x,
                                                GLint y,
                                                GLsizei width,
                                                GLsizei height,
                                                GLenum format,
                                                GLenum type,
                                                GLsizei bufSize,
                                                void* data);
typedef void(APIENTRYP PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC)(GLenum target, GLint lod, GLsizei bufSize, void* img);
typedef void(APIENTRYP PFNGLGETNUNIFORMFVARBPROC)(GLuint program, GLint location, GLsizei bufSize, GLfloat* params);
typedef void(APIENTRYP PFNGLGETNUNIFORMIVARBPROC)(GLuint program, GLint location, GLsizei bufSize, GLint* params);
typedef void(APIENTRYP PFNGLGETNUNIFORMUIVARBPROC)(GLuint program, GLint location, GLsizei bufSize, GLuint* params);
typedef void(APIENTRYP PFNGLGETNUNIFORMDVARBPROC)(GLuint program, GLint location, GLsizei bufSize, GLdouble* params);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI GLenum APIENTRY glGetGraphicsResetStatusARB(void);
GLAPI void APIENTRY
glGetnTexImageARB(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* img);
GLAPI void APIENTRY glReadnPixelsARB(GLint x,
                                     GLint y,
                                     GLsizei width,
                                     GLsizei height,
                                     GLenum format,
                                     GLenum type,
                                     GLsizei bufSize,
                                     void* data);
GLAPI void APIENTRY glGetnCompressedTexImageARB(GLenum target, GLint lod, GLsizei bufSize, void* img);
GLAPI void APIENTRY glGetnUniformfvARB(GLuint program, GLint location, GLsizei bufSize, GLfloat* params);
GLAPI void APIENTRY glGetnUniformivARB(GLuint program, GLint location, GLsizei bufSize, GLint* params);
GLAPI void APIENTRY glGetnUniformuivARB(GLuint program, GLint location, GLsizei bufSize, GLuint* params);
GLAPI void APIENTRY glGetnUniformdvARB(GLuint program, GLint location, GLsizei bufSize, GLdouble* params);
#endif
#endif /* GL_ARB_robustness */

#ifndef GL_ARB_robustness_isolation
#define GL_ARB_robustness_isolation 1
#endif /* GL_ARB_robustness_isolation */

#ifndef GL_ARB_sample_locations
#define GL_ARB_sample_locations 1
#define GL_SAMPLE_LOCATION_SUBPIXEL_BITS_ARB 0x933D
#define GL_SAMPLE_LOCATION_PIXEL_GRID_WIDTH_ARB 0x933E
#define GL_SAMPLE_LOCATION_PIXEL_GRID_HEIGHT_ARB 0x933F
#define GL_PROGRAMMABLE_SAMPLE_LOCATION_TABLE_SIZE_ARB 0x9340
#define GL_SAMPLE_LOCATION_ARB 0x8E50
#define GL_PROGRAMMABLE_SAMPLE_LOCATION_ARB 0x9341
#define GL_FRAMEBUFFER_PROGRAMMABLE_SAMPLE_LOCATIONS_ARB 0x9342
#define GL_FRAMEBUFFER_SAMPLE_LOCATION_PIXEL_GRID_ARB 0x9343
typedef void(APIENTRYP PFNGLFRAMEBUFFERSAMPLELOCATIONSFVARBPROC)(GLenum target,
                                                                 GLuint start,
                                                                 GLsizei count,
                                                                 const GLfloat* v);
typedef void(APIENTRYP PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVARBPROC)(GLuint framebuffer,
                                                                      GLuint start,
                                                                      GLsizei count,
                                                                      const GLfloat* v);
typedef void(APIENTRYP PFNGLEVALUATEDEPTHVALUESARBPROC)(void);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glFramebufferSampleLocationsfvARB(GLenum target, GLuint start, GLsizei count, const GLfloat* v);
GLAPI void APIENTRY glNamedFramebufferSampleLocationsfvARB(GLuint framebuffer,
                                                           GLuint start,
                                                           GLsizei count,
                                                           const GLfloat* v);
GLAPI void APIENTRY glEvaluateDepthValuesARB(void);
#endif
#endif /* GL_ARB_sample_locations */

#ifndef GL_ARB_sample_shading
#define GL_ARB_sample_shading 1
#define GL_SAMPLE_SHADING_ARB 0x8C36
#define GL_MIN_SAMPLE_SHADING_VALUE_ARB 0x8C37
typedef void(APIENTRYP PFNGLMINSAMPLESHADINGARBPROC)(GLfloat value);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glMinSampleShadingARB(GLfloat value);
#endif
#endif /* GL_ARB_sample_shading */

#ifndef GL_ARB_sampler_objects
#define GL_ARB_sampler_objects 1
#endif /* GL_ARB_sampler_objects */

#ifndef GL_ARB_seamless_cube_map
#define GL_ARB_seamless_cube_map 1
#endif /* GL_ARB_seamless_cube_map */

#ifndef GL_ARB_seamless_cubemap_per_texture
#define GL_ARB_seamless_cubemap_per_texture 1
#endif /* GL_ARB_seamless_cubemap_per_texture */

#ifndef GL_ARB_separate_shader_objects
#define GL_ARB_separate_shader_objects 1
#endif /* GL_ARB_separate_shader_objects */

#ifndef GL_ARB_shader_atomic_counter_ops
#define GL_ARB_shader_atomic_counter_ops 1
#endif /* GL_ARB_shader_atomic_counter_ops */

#ifndef GL_ARB_shader_atomic_counters
#define GL_ARB_shader_atomic_counters 1
#endif /* GL_ARB_shader_atomic_counters */

#ifndef GL_ARB_shader_ballot
#define GL_ARB_shader_ballot 1
#endif /* GL_ARB_shader_ballot */

#ifndef GL_ARB_shader_bit_encoding
#define GL_ARB_shader_bit_encoding 1
#endif /* GL_ARB_shader_bit_encoding */

#ifndef GL_ARB_shader_clock
#define GL_ARB_shader_clock 1
#endif /* GL_ARB_shader_clock */

#ifndef GL_ARB_shader_draw_parameters
#define GL_ARB_shader_draw_parameters 1
#endif /* GL_ARB_shader_draw_parameters */

#ifndef GL_ARB_shader_group_vote
#define GL_ARB_shader_group_vote 1
#endif /* GL_ARB_shader_group_vote */

#ifndef GL_ARB_shader_image_load_store
#define GL_ARB_shader_image_load_store 1
#endif /* GL_ARB_shader_image_load_store */

#ifndef GL_ARB_shader_image_size
#define GL_ARB_shader_image_size 1
#endif /* GL_ARB_shader_image_size */

#ifndef GL_ARB_shader_precision
#define GL_ARB_shader_precision 1
#endif /* GL_ARB_shader_precision */

#ifndef GL_ARB_shader_stencil_export
#define GL_ARB_shader_stencil_export 1
#endif /* GL_ARB_shader_stencil_export */

#ifndef GL_ARB_shader_storage_buffer_object
#define GL_ARB_shader_storage_buffer_object 1
#endif /* GL_ARB_shader_storage_buffer_object */

#ifndef GL_ARB_shader_subroutine
#define GL_ARB_shader_subroutine 1
#endif /* GL_ARB_shader_subroutine */

#ifndef GL_ARB_shader_texture_image_samples
#define GL_ARB_shader_texture_image_samples 1
#endif /* GL_ARB_shader_texture_image_samples */

#ifndef GL_ARB_shader_viewport_layer_array
#define GL_ARB_shader_viewport_layer_array 1
#endif /* GL_ARB_shader_viewport_layer_array */

#ifndef GL_ARB_shading_language_420pack
#define GL_ARB_shading_language_420pack 1
#endif /* GL_ARB_shading_language_420pack */

#ifndef GL_ARB_shading_language_include
#define GL_ARB_shading_language_include 1
#define GL_SHADER_INCLUDE_ARB 0x8DAE
#define GL_NAMED_STRING_LENGTH_ARB 0x8DE9
#define GL_NAMED_STRING_TYPE_ARB 0x8DEA
typedef void(APIENTRYP PFNGLNAMEDSTRINGARBPROC)(GLenum type,
                                                GLint namelen,
                                                const GLchar* name,
                                                GLint stringlen,
                                                const GLchar* string);
typedef void(APIENTRYP PFNGLDELETENAMEDSTRINGARBPROC)(GLint namelen, const GLchar* name);
typedef void(APIENTRYP PFNGLCOMPILESHADERINCLUDEARBPROC)(GLuint shader,
                                                         GLsizei count,
                                                         const GLchar* const* path,
                                                         const GLint* length);
typedef GLboolean(APIENTRYP PFNGLISNAMEDSTRINGARBPROC)(GLint namelen, const GLchar* name);
typedef void(APIENTRYP PFNGLGETNAMEDSTRINGARBPROC)(GLint namelen,
                                                   const GLchar* name,
                                                   GLsizei bufSize,
                                                   GLint* stringlen,
                                                   GLchar* string);
typedef void(APIENTRYP PFNGLGETNAMEDSTRINGIVARBPROC)(GLint namelen, const GLchar* name, GLenum pname, GLint* params);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY
glNamedStringARB(GLenum type, GLint namelen, const GLchar* name, GLint stringlen, const GLchar* string);
GLAPI void APIENTRY glDeleteNamedStringARB(GLint namelen, const GLchar* name);
GLAPI void APIENTRY glCompileShaderIncludeARB(GLuint shader,
                                              GLsizei count,
                                              const GLchar* const* path,
                                              const GLint* length);
GLAPI GLboolean APIENTRY glIsNamedStringARB(GLint namelen, const GLchar* name);
GLAPI void APIENTRY
glGetNamedStringARB(GLint namelen, const GLchar* name, GLsizei bufSize, GLint* stringlen, GLchar* string);
GLAPI void APIENTRY glGetNamedStringivARB(GLint namelen, const GLchar* name, GLenum pname, GLint* params);
#endif
#endif /* GL_ARB_shading_language_include */

#ifndef GL_ARB_shading_language_packing
#define GL_ARB_shading_language_packing 1
#endif /* GL_ARB_shading_language_packing */

#ifndef GL_ARB_sparse_buffer
#define GL_ARB_sparse_buffer 1
#define GL_SPARSE_STORAGE_BIT_ARB 0x0400
#define GL_SPARSE_BUFFER_PAGE_SIZE_ARB 0x82F8
typedef void(APIENTRYP PFNGLBUFFERPAGECOMMITMENTARBPROC)(GLenum target,
                                                         GLintptr offset,
                                                         GLsizeiptr size,
                                                         GLboolean commit);
typedef void(APIENTRYP PFNGLNAMEDBUFFERPAGECOMMITMENTEXTPROC)(GLuint buffer,
                                                              GLintptr offset,
                                                              GLsizeiptr size,
                                                              GLboolean commit);
typedef void(APIENTRYP PFNGLNAMEDBUFFERPAGECOMMITMENTARBPROC)(GLuint buffer,
                                                              GLintptr offset,
                                                              GLsizeiptr size,
                                                              GLboolean commit);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glBufferPageCommitmentARB(GLenum target, GLintptr offset, GLsizeiptr size, GLboolean commit);
GLAPI void APIENTRY glNamedBufferPageCommitmentEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
GLAPI void APIENTRY glNamedBufferPageCommitmentARB(GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
#endif
#endif /* GL_ARB_sparse_buffer */

#ifndef GL_ARB_sparse_texture
#define GL_ARB_sparse_texture 1
#define GL_TEXTURE_SPARSE_ARB 0x91A6
#define GL_VIRTUAL_PAGE_SIZE_INDEX_ARB 0x91A7
#define GL_NUM_SPARSE_LEVELS_ARB 0x91AA
#define GL_NUM_VIRTUAL_PAGE_SIZES_ARB 0x91A8
#define GL_VIRTUAL_PAGE_SIZE_X_ARB 0x9195
#define GL_VIRTUAL_PAGE_SIZE_Y_ARB 0x9196
#define GL_VIRTUAL_PAGE_SIZE_Z_ARB 0x9197
#define GL_MAX_SPARSE_TEXTURE_SIZE_ARB 0x9198
#define GL_MAX_SPARSE_3D_TEXTURE_SIZE_ARB 0x9199
#define GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS_ARB 0x919A
#define GL_SPARSE_TEXTURE_FULL_ARRAY_CUBE_MIPMAPS_ARB 0x91A9
typedef void(APIENTRYP PFNGLTEXPAGECOMMITMENTARBPROC)(GLenum target,
                                                      GLint level,
                                                      GLint xoffset,
                                                      GLint yoffset,
                                                      GLint zoffset,
                                                      GLsizei width,
                                                      GLsizei height,
                                                      GLsizei depth,
                                                      GLboolean commit);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glTexPageCommitmentARB(GLenum target,
                                           GLint level,
                                           GLint xoffset,
                                           GLint yoffset,
                                           GLint zoffset,
                                           GLsizei width,
                                           GLsizei height,
                                           GLsizei depth,
                                           GLboolean commit);
#endif
#endif /* GL_ARB_sparse_texture */

#ifndef GL_ARB_sparse_texture2
#define GL_ARB_sparse_texture2 1
#endif /* GL_ARB_sparse_texture2 */

#ifndef GL_ARB_sparse_texture_clamp
#define GL_ARB_sparse_texture_clamp 1
#endif /* GL_ARB_sparse_texture_clamp */

#ifndef GL_ARB_spirv_extensions
#define GL_ARB_spirv_extensions 1
#endif /* GL_ARB_spirv_extensions */

#ifndef GL_ARB_stencil_texturing
#define GL_ARB_stencil_texturing 1
#endif /* GL_ARB_stencil_texturing */

#ifndef GL_ARB_sync
#define GL_ARB_sync 1
#endif /* GL_ARB_sync */

#ifndef GL_ARB_tessellation_shader
#define GL_ARB_tessellation_shader 1
#endif /* GL_ARB_tessellation_shader */

#ifndef GL_ARB_texture_barrier
#define GL_ARB_texture_barrier 1
#endif /* GL_ARB_texture_barrier */

#ifndef GL_ARB_texture_border_clamp
#define GL_ARB_texture_border_clamp 1
#define GL_CLAMP_TO_BORDER_ARB 0x812D
#endif /* GL_ARB_texture_border_clamp */

#ifndef GL_ARB_texture_buffer_object
#define GL_ARB_texture_buffer_object 1
#define GL_TEXTURE_BUFFER_ARB 0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE_ARB 0x8C2B
#define GL_TEXTURE_BINDING_BUFFER_ARB 0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING_ARB 0x8C2D
#define GL_TEXTURE_BUFFER_FORMAT_ARB 0x8C2E
typedef void(APIENTRYP PFNGLTEXBUFFERARBPROC)(GLenum target, GLenum internalformat, GLuint buffer);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glTexBufferARB(GLenum target, GLenum internalformat, GLuint buffer);
#endif
#endif /* GL_ARB_texture_buffer_object */

#ifndef GL_ARB_texture_buffer_object_rgb32
#define GL_ARB_texture_buffer_object_rgb32 1
#endif /* GL_ARB_texture_buffer_object_rgb32 */

#ifndef GL_ARB_texture_buffer_range
#define GL_ARB_texture_buffer_range 1
#endif /* GL_ARB_texture_buffer_range */

#ifndef GL_ARB_texture_compression_bptc
#define GL_ARB_texture_compression_bptc 1
#define GL_COMPRESSED_RGBA_BPTC_UNORM_ARB 0x8E8C
#define GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM_ARB 0x8E8D
#define GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT_ARB 0x8E8E
#define GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_ARB 0x8E8F
#endif /* GL_ARB_texture_compression_bptc */

#ifndef GL_ARB_texture_compression_rgtc
#define GL_ARB_texture_compression_rgtc 1
#endif /* GL_ARB_texture_compression_rgtc */

#ifndef GL_ARB_texture_cube_map_array
#define GL_ARB_texture_cube_map_array 1
#define GL_TEXTURE_CUBE_MAP_ARRAY_ARB 0x9009
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY_ARB 0x900A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY_ARB 0x900B
#define GL_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW_ARB 0x900D
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900E
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900F
#endif /* GL_ARB_texture_cube_map_array */

#ifndef GL_ARB_texture_filter_anisotropic
#define GL_ARB_texture_filter_anisotropic 1
#endif /* GL_ARB_texture_filter_anisotropic */

#ifndef GL_ARB_texture_filter_minmax
#define GL_ARB_texture_filter_minmax 1
#define GL_TEXTURE_REDUCTION_MODE_ARB 0x9366
#define GL_WEIGHTED_AVERAGE_ARB 0x9367
#endif /* GL_ARB_texture_filter_minmax */

#ifndef GL_ARB_texture_gather
#define GL_ARB_texture_gather 1
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_ARB 0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_ARB 0x8E5F
#define GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS_ARB 0x8F9F
#endif /* GL_ARB_texture_gather */

#ifndef GL_ARB_texture_mirror_clamp_to_edge
#define GL_ARB_texture_mirror_clamp_to_edge 1
#endif /* GL_ARB_texture_mirror_clamp_to_edge */

#ifndef GL_ARB_texture_mirrored_repeat
#define GL_ARB_texture_mirrored_repeat 1
#define GL_MIRRORED_REPEAT_ARB 0x8370
#endif /* GL_ARB_texture_mirrored_repeat */

#ifndef GL_ARB_texture_multisample
#define GL_ARB_texture_multisample 1
#endif /* GL_ARB_texture_multisample */

#ifndef GL_ARB_texture_non_power_of_two
#define GL_ARB_texture_non_power_of_two 1
#endif /* GL_ARB_texture_non_power_of_two */

#ifndef GL_ARB_texture_query_levels
#define GL_ARB_texture_query_levels 1
#endif /* GL_ARB_texture_query_levels */

#ifndef GL_ARB_texture_query_lod
#define GL_ARB_texture_query_lod 1
#endif /* GL_ARB_texture_query_lod */

#ifndef GL_ARB_texture_rg
#define GL_ARB_texture_rg 1
#endif /* GL_ARB_texture_rg */

#ifndef GL_ARB_texture_rgb10_a2ui
#define GL_ARB_texture_rgb10_a2ui 1
#endif /* GL_ARB_texture_rgb10_a2ui */

#ifndef GL_ARB_texture_stencil8
#define GL_ARB_texture_stencil8 1
#endif /* GL_ARB_texture_stencil8 */

#ifndef GL_ARB_texture_storage
#define GL_ARB_texture_storage 1
#endif /* GL_ARB_texture_storage */

#ifndef GL_ARB_texture_storage_multisample
#define GL_ARB_texture_storage_multisample 1
#endif /* GL_ARB_texture_storage_multisample */

#ifndef GL_ARB_texture_swizzle
#define GL_ARB_texture_swizzle 1
#endif /* GL_ARB_texture_swizzle */

#ifndef GL_ARB_texture_view
#define GL_ARB_texture_view 1
#endif /* GL_ARB_texture_view */

#ifndef GL_ARB_timer_query
#define GL_ARB_timer_query 1
#endif /* GL_ARB_timer_query */

#ifndef GL_ARB_transform_feedback2
#define GL_ARB_transform_feedback2 1
#endif /* GL_ARB_transform_feedback2 */

#ifndef GL_ARB_transform_feedback3
#define GL_ARB_transform_feedback3 1
#endif /* GL_ARB_transform_feedback3 */

#ifndef GL_ARB_transform_feedback_instanced
#define GL_ARB_transform_feedback_instanced 1
#endif /* GL_ARB_transform_feedback_instanced */

#ifndef GL_ARB_transform_feedback_overflow_query
#define GL_ARB_transform_feedback_overflow_query 1
#define GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB 0x82EC
#define GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB 0x82ED
#endif /* GL_ARB_transform_feedback_overflow_query */

#ifndef GL_ARB_uniform_buffer_object
#define GL_ARB_uniform_buffer_object 1
#endif /* GL_ARB_uniform_buffer_object */

#ifndef GL_ARB_vertex_array_bgra
#define GL_ARB_vertex_array_bgra 1
#endif /* GL_ARB_vertex_array_bgra */

#ifndef GL_ARB_vertex_array_object
#define GL_ARB_vertex_array_object 1
#endif /* GL_ARB_vertex_array_object */

#ifndef GL_ARB_vertex_attrib_64bit
#define GL_ARB_vertex_attrib_64bit 1
#endif /* GL_ARB_vertex_attrib_64bit */

#ifndef GL_ARB_vertex_attrib_binding
#define GL_ARB_vertex_attrib_binding 1
#endif /* GL_ARB_vertex_attrib_binding */

#ifndef GL_ARB_vertex_type_10f_11f_11f_rev
#define GL_ARB_vertex_type_10f_11f_11f_rev 1
#endif /* GL_ARB_vertex_type_10f_11f_11f_rev */

#ifndef GL_ARB_vertex_type_2_10_10_10_rev
#define GL_ARB_vertex_type_2_10_10_10_rev 1
#endif /* GL_ARB_vertex_type_2_10_10_10_rev */

#ifndef GL_ARB_viewport_array
#define GL_ARB_viewport_array 1
#endif /* GL_ARB_viewport_array */

#ifndef GL_KHR_blend_equation_advanced
#define GL_KHR_blend_equation_advanced 1
#define GL_MULTIPLY_KHR 0x9294
#define GL_SCREEN_KHR 0x9295
#define GL_OVERLAY_KHR 0x9296
#define GL_DARKEN_KHR 0x9297
#define GL_LIGHTEN_KHR 0x9298
#define GL_COLORDODGE_KHR 0x9299
#define GL_COLORBURN_KHR 0x929A
#define GL_HARDLIGHT_KHR 0x929B
#define GL_SOFTLIGHT_KHR 0x929C
#define GL_DIFFERENCE_KHR 0x929E
#define GL_EXCLUSION_KHR 0x92A0
#define GL_HSL_HUE_KHR 0x92AD
#define GL_HSL_SATURATION_KHR 0x92AE
#define GL_HSL_COLOR_KHR 0x92AF
#define GL_HSL_LUMINOSITY_KHR 0x92B0
typedef void(APIENTRYP PFNGLBLENDBARRIERKHRPROC)(void);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glBlendBarrierKHR(void);
#endif
#endif /* GL_KHR_blend_equation_advanced */

#ifndef GL_KHR_blend_equation_advanced_coherent
#define GL_KHR_blend_equation_advanced_coherent 1
#define GL_BLEND_ADVANCED_COHERENT_KHR 0x9285
#endif /* GL_KHR_blend_equation_advanced_coherent */

#ifndef GL_KHR_context_flush_control
#define GL_KHR_context_flush_control 1
#endif /* GL_KHR_context_flush_control */

#ifndef GL_KHR_debug
#define GL_KHR_debug 1
#endif /* GL_KHR_debug */

#ifndef GL_KHR_no_error
#define GL_KHR_no_error 1
#define GL_CONTEXT_FLAG_NO_ERROR_BIT_KHR 0x00000008
#endif /* GL_KHR_no_error */

#ifndef GL_KHR_parallel_shader_compile
#define GL_KHR_parallel_shader_compile 1
#define GL_MAX_SHADER_COMPILER_THREADS_KHR 0x91B0
#define GL_COMPLETION_STATUS_KHR 0x91B1
typedef void(APIENTRYP PFNGLMAXSHADERCOMPILERTHREADSKHRPROC)(GLuint count);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glMaxShaderCompilerThreadsKHR(GLuint count);
#endif
#endif /* GL_KHR_parallel_shader_compile */

#ifndef GL_KHR_robust_buffer_access_behavior
#define GL_KHR_robust_buffer_access_behavior 1
#endif /* GL_KHR_robust_buffer_access_behavior */

#ifndef GL_KHR_robustness
#define GL_KHR_robustness 1
#define GL_CONTEXT_ROBUST_ACCESS 0x90F3
#endif /* GL_KHR_robustness */

#ifndef GL_KHR_texture_compression_astc_hdr
#define GL_KHR_texture_compression_astc_hdr 1
#define GL_COMPRESSED_RGBA_ASTC_4x4_KHR 0x93B0
#define GL_COMPRESSED_RGBA_ASTC_5x4_KHR 0x93B1
#define GL_COMPRESSED_RGBA_ASTC_5x5_KHR 0x93B2
#define GL_COMPRESSED_RGBA_ASTC_6x5_KHR 0x93B3
#define GL_COMPRESSED_RGBA_ASTC_6x6_KHR 0x93B4
#define GL_COMPRESSED_RGBA_ASTC_8x5_KHR 0x93B5
#define GL_COMPRESSED_RGBA_ASTC_8x6_KHR 0x93B6
#define GL_COMPRESSED_RGBA_ASTC_8x8_KHR 0x93B7
#define GL_COMPRESSED_RGBA_ASTC_10x5_KHR 0x93B8
#define GL_COMPRESSED_RGBA_ASTC_10x6_KHR 0x93B9
#define GL_COMPRESSED_RGBA_ASTC_10x8_KHR 0x93BA
#define GL_COMPRESSED_RGBA_ASTC_10x10_KHR 0x93BB
#define GL_COMPRESSED_RGBA_ASTC_12x10_KHR 0x93BC
#define GL_COMPRESSED_RGBA_ASTC_12x12_KHR 0x93BD
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x4_KHR 0x93D0
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x4_KHR 0x93D1
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x5_KHR 0x93D2
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x5_KHR 0x93D3
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x6_KHR 0x93D4
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x5_KHR 0x93D5
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x6_KHR 0x93D6
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x8_KHR 0x93D7
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x5_KHR 0x93D8
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x6_KHR 0x93D9
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x8_KHR 0x93DA
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x10_KHR 0x93DB
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x10_KHR 0x93DC
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x12_KHR 0x93DD
#endif /* GL_KHR_texture_compression_astc_hdr */

#ifndef GL_KHR_texture_compression_astc_ldr
#define GL_KHR_texture_compression_astc_ldr 1
#endif /* GL_KHR_texture_compression_astc_ldr */

#ifndef GL_KHR_texture_compression_astc_sliced_3d
#define GL_KHR_texture_compression_astc_sliced_3d 1
#endif /* GL_KHR_texture_compression_astc_sliced_3d */

#ifndef GL_AMD_performance_monitor
#define GL_AMD_performance_monitor 1
#define GL_COUNTER_TYPE_AMD 0x8BC0
#define GL_COUNTER_RANGE_AMD 0x8BC1
#define GL_UNSIGNED_INT64_AMD 0x8BC2
#define GL_PERCENTAGE_AMD 0x8BC3
#define GL_PERFMON_RESULT_AVAILABLE_AMD 0x8BC4
#define GL_PERFMON_RESULT_SIZE_AMD 0x8BC5
#define GL_PERFMON_RESULT_AMD 0x8BC6
typedef void(APIENTRYP PFNGLGETPERFMONITORGROUPSAMDPROC)(GLint* numGroups, GLsizei groupsSize, GLuint* groups);
typedef void(APIENTRYP PFNGLGETPERFMONITORCOUNTERSAMDPROC)(GLuint group,
                                                           GLint* numCounters,
                                                           GLint* maxActiveCounters,
                                                           GLsizei counterSize,
                                                           GLuint* counters);
typedef void(APIENTRYP PFNGLGETPERFMONITORGROUPSTRINGAMDPROC)(GLuint group,
                                                              GLsizei bufSize,
                                                              GLsizei* length,
                                                              GLchar* groupString);
typedef void(APIENTRYP PFNGLGETPERFMONITORCOUNTERSTRINGAMDPROC)(GLuint group,
                                                                GLuint counter,
                                                                GLsizei bufSize,
                                                                GLsizei* length,
                                                                GLchar* counterString);
typedef void(APIENTRYP PFNGLGETPERFMONITORCOUNTERINFOAMDPROC)(GLuint group, GLuint counter, GLenum pname, void* data);
typedef void(APIENTRYP PFNGLGENPERFMONITORSAMDPROC)(GLsizei n, GLuint* monitors);
typedef void(APIENTRYP PFNGLDELETEPERFMONITORSAMDPROC)(GLsizei n, GLuint* monitors);
typedef void(APIENTRYP PFNGLSELECTPERFMONITORCOUNTERSAMDPROC)(GLuint monitor,
                                                              GLboolean enable,
                                                              GLuint group,
                                                              GLint numCounters,
                                                              GLuint* counterList);
typedef void(APIENTRYP PFNGLBEGINPERFMONITORAMDPROC)(GLuint monitor);
typedef void(APIENTRYP PFNGLENDPERFMONITORAMDPROC)(GLuint monitor);
typedef void(APIENTRYP PFNGLGETPERFMONITORCOUNTERDATAAMDPROC)(GLuint monitor,
                                                              GLenum pname,
                                                              GLsizei dataSize,
                                                              GLuint* data,
                                                              GLint* bytesWritten);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glGetPerfMonitorGroupsAMD(GLint* numGroups, GLsizei groupsSize, GLuint* groups);
GLAPI void APIENTRY glGetPerfMonitorCountersAMD(GLuint group,
                                                GLint* numCounters,
                                                GLint* maxActiveCounters,
                                                GLsizei counterSize,
                                                GLuint* counters);
GLAPI void APIENTRY glGetPerfMonitorGroupStringAMD(GLuint group, GLsizei bufSize, GLsizei* length, GLchar* groupString);
GLAPI void APIENTRY
glGetPerfMonitorCounterStringAMD(GLuint group, GLuint counter, GLsizei bufSize, GLsizei* length, GLchar* counterString);
GLAPI void APIENTRY glGetPerfMonitorCounterInfoAMD(GLuint group, GLuint counter, GLenum pname, void* data);
GLAPI void APIENTRY glGenPerfMonitorsAMD(GLsizei n, GLuint* monitors);
GLAPI void APIENTRY glDeletePerfMonitorsAMD(GLsizei n, GLuint* monitors);
GLAPI void APIENTRY
glSelectPerfMonitorCountersAMD(GLuint monitor, GLboolean enable, GLuint group, GLint numCounters, GLuint* counterList);
GLAPI void APIENTRY glBeginPerfMonitorAMD(GLuint monitor);
GLAPI void APIENTRY glEndPerfMonitorAMD(GLuint monitor);
GLAPI void APIENTRY
glGetPerfMonitorCounterDataAMD(GLuint monitor, GLenum pname, GLsizei dataSize, GLuint* data, GLint* bytesWritten);
#endif
#endif /* GL_AMD_performance_monitor */

#ifndef GL_APPLE_rgb_422
#define GL_APPLE_rgb_422 1
#define GL_RGB_422_APPLE 0x8A1F
#define GL_UNSIGNED_SHORT_8_8_APPLE 0x85BA
#define GL_UNSIGNED_SHORT_8_8_REV_APPLE 0x85BB
#define GL_RGB_RAW_422_APPLE 0x8A51
#endif /* GL_APPLE_rgb_422 */

#ifndef GL_EXT_debug_label
#define GL_EXT_debug_label 1
#define GL_PROGRAM_PIPELINE_OBJECT_EXT 0x8A4F
#define GL_PROGRAM_OBJECT_EXT 0x8B40
#define GL_SHADER_OBJECT_EXT 0x8B48
#define GL_BUFFER_OBJECT_EXT 0x9151
#define GL_QUERY_OBJECT_EXT 0x9153
#define GL_VERTEX_ARRAY_OBJECT_EXT 0x9154
typedef void(APIENTRYP PFNGLLABELOBJECTEXTPROC)(GLenum type, GLuint object, GLsizei length, const GLchar* label);
typedef void(
APIENTRYP PFNGLGETOBJECTLABELEXTPROC)(GLenum type, GLuint object, GLsizei bufSize, GLsizei* length, GLchar* label);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glLabelObjectEXT(GLenum type, GLuint object, GLsizei length, const GLchar* label);
GLAPI void APIENTRY glGetObjectLabelEXT(GLenum type, GLuint object, GLsizei bufSize, GLsizei* length, GLchar* label);
#endif
#endif /* GL_EXT_debug_label */

#ifndef GL_EXT_debug_marker
#define GL_EXT_debug_marker 1
typedef void(APIENTRYP PFNGLINSERTEVENTMARKEREXTPROC)(GLsizei length, const GLchar* marker);
typedef void(APIENTRYP PFNGLPUSHGROUPMARKEREXTPROC)(GLsizei length, const GLchar* marker);
typedef void(APIENTRYP PFNGLPOPGROUPMARKEREXTPROC)(void);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glInsertEventMarkerEXT(GLsizei length, const GLchar* marker);
GLAPI void APIENTRY glPushGroupMarkerEXT(GLsizei length, const GLchar* marker);
GLAPI void APIENTRY glPopGroupMarkerEXT(void);
#endif
#endif /* GL_EXT_debug_marker */

#ifndef GL_EXT_direct_state_access
#define GL_EXT_direct_state_access 1
#define GL_PROGRAM_MATRIX_EXT 0x8E2D
#define GL_TRANSPOSE_PROGRAM_MATRIX_EXT 0x8E2E
#define GL_PROGRAM_MATRIX_STACK_DEPTH_EXT 0x8E2F
typedef void(APIENTRYP PFNGLMATRIXLOADFEXTPROC)(GLenum mode, const GLfloat* m);
typedef void(APIENTRYP PFNGLMATRIXLOADDEXTPROC)(GLenum mode, const GLdouble* m);
typedef void(APIENTRYP PFNGLMATRIXMULTFEXTPROC)(GLenum mode, const GLfloat* m);
typedef void(APIENTRYP PFNGLMATRIXMULTDEXTPROC)(GLenum mode, const GLdouble* m);
typedef void(APIENTRYP PFNGLMATRIXLOADIDENTITYEXTPROC)(GLenum mode);
typedef void(APIENTRYP PFNGLMATRIXROTATEFEXTPROC)(GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
typedef void(APIENTRYP PFNGLMATRIXROTATEDEXTPROC)(GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
typedef void(APIENTRYP PFNGLMATRIXSCALEFEXTPROC)(GLenum mode, GLfloat x, GLfloat y, GLfloat z);
typedef void(APIENTRYP PFNGLMATRIXSCALEDEXTPROC)(GLenum mode, GLdouble x, GLdouble y, GLdouble z);
typedef void(APIENTRYP PFNGLMATRIXTRANSLATEFEXTPROC)(GLenum mode, GLfloat x, GLfloat y, GLfloat z);
typedef void(APIENTRYP PFNGLMATRIXTRANSLATEDEXTPROC)(GLenum mode, GLdouble x, GLdouble y, GLdouble z);
typedef void(APIENTRYP PFNGLMATRIXFRUSTUMEXTPROC)(GLenum mode,
                                                  GLdouble left,
                                                  GLdouble right,
                                                  GLdouble bottom,
                                                  GLdouble top,
                                                  GLdouble zNear,
                                                  GLdouble zFar);
typedef void(APIENTRYP PFNGLMATRIXORTHOEXTPROC)(GLenum mode,
                                                GLdouble left,
                                                GLdouble right,
                                                GLdouble bottom,
                                                GLdouble top,
                                                GLdouble zNear,
                                                GLdouble zFar);
typedef void(APIENTRYP PFNGLMATRIXPOPEXTPROC)(GLenum mode);
typedef void(APIENTRYP PFNGLMATRIXPUSHEXTPROC)(GLenum mode);
typedef void(APIENTRYP PFNGLCLIENTATTRIBDEFAULTEXTPROC)(GLbitfield mask);
typedef void(APIENTRYP PFNGLPUSHCLIENTATTRIBDEFAULTEXTPROC)(GLbitfield mask);
typedef void(APIENTRYP PFNGLTEXTUREPARAMETERFEXTPROC)(GLuint texture, GLenum target, GLenum pname, GLfloat param);
typedef void(APIENTRYP PFNGLTEXTUREPARAMETERFVEXTPROC)(GLuint texture,
                                                       GLenum target,
                                                       GLenum pname,
                                                       const GLfloat* params);
typedef void(APIENTRYP PFNGLTEXTUREPARAMETERIEXTPROC)(GLuint texture, GLenum target, GLenum pname, GLint param);
typedef void(APIENTRYP PFNGLTEXTUREPARAMETERIVEXTPROC)(GLuint texture, GLenum target, GLenum pname, const GLint* params);
typedef void(APIENTRYP PFNGLTEXTUREIMAGE1DEXTPROC)(GLuint texture,
                                                   GLenum target,
                                                   GLint level,
                                                   GLint internalformat,
                                                   GLsizei width,
                                                   GLint border,
                                                   GLenum format,
                                                   GLenum type,
                                                   const void* pixels);
typedef void(APIENTRYP PFNGLTEXTUREIMAGE2DEXTPROC)(GLuint texture,
                                                   GLenum target,
                                                   GLint level,
                                                   GLint internalformat,
                                                   GLsizei width,
                                                   GLsizei height,
                                                   GLint border,
                                                   GLenum format,
                                                   GLenum type,
                                                   const void* pixels);
typedef void(APIENTRYP PFNGLTEXTURESUBIMAGE1DEXTPROC)(GLuint texture,
                                                      GLenum target,
                                                      GLint level,
                                                      GLint xoffset,
                                                      GLsizei width,
                                                      GLenum format,
                                                      GLenum type,
                                                      const void* pixels);
typedef void(APIENTRYP PFNGLTEXTURESUBIMAGE2DEXTPROC)(GLuint texture,
                                                      GLenum target,
                                                      GLint level,
                                                      GLint xoffset,
                                                      GLint yoffset,
                                                      GLsizei width,
                                                      GLsizei height,
                                                      GLenum format,
                                                      GLenum type,
                                                      const void* pixels);
typedef void(APIENTRYP PFNGLCOPYTEXTUREIMAGE1DEXTPROC)(GLuint texture,
                                                       GLenum target,
                                                       GLint level,
                                                       GLenum internalformat,
                                                       GLint x,
                                                       GLint y,
                                                       GLsizei width,
                                                       GLint border);
typedef void(APIENTRYP PFNGLCOPYTEXTUREIMAGE2DEXTPROC)(GLuint texture,
                                                       GLenum target,
                                                       GLint level,
                                                       GLenum internalformat,
                                                       GLint x,
                                                       GLint y,
                                                       GLsizei width,
                                                       GLsizei height,
                                                       GLint border);
typedef void(APIENTRYP PFNGLCOPYTEXTURESUBIMAGE1DEXTPROC)(GLuint texture,
                                                          GLenum target,
                                                          GLint level,
                                                          GLint xoffset,
                                                          GLint x,
                                                          GLint y,
                                                          GLsizei width);
typedef void(APIENTRYP PFNGLCOPYTEXTURESUBIMAGE2DEXTPROC)(GLuint texture,
                                                          GLenum target,
                                                          GLint level,
                                                          GLint xoffset,
                                                          GLint yoffset,
                                                          GLint x,
                                                          GLint y,
                                                          GLsizei width,
                                                          GLsizei height);
typedef void(APIENTRYP PFNGLGETTEXTUREIMAGEEXTPROC)(GLuint texture,
                                                    GLenum target,
                                                    GLint level,
                                                    GLenum format,
                                                    GLenum type,
                                                    void* pixels);
typedef void(APIENTRYP PFNGLGETTEXTUREPARAMETERFVEXTPROC)(GLuint texture, GLenum target, GLenum pname, GLfloat* params);
typedef void(APIENTRYP PFNGLGETTEXTUREPARAMETERIVEXTPROC)(GLuint texture, GLenum target, GLenum pname, GLint* params);
typedef void(APIENTRYP PFNGLGETTEXTURELEVELPARAMETERFVEXTPROC)(GLuint texture,
                                                               GLenum target,
                                                               GLint level,
                                                               GLenum pname,
                                                               GLfloat* params);
typedef void(APIENTRYP PFNGLGETTEXTURELEVELPARAMETERIVEXTPROC)(GLuint texture,
                                                               GLenum target,
                                                               GLint level,
                                                               GLenum pname,
                                                               GLint* params);
typedef void(APIENTRYP PFNGLTEXTUREIMAGE3DEXTPROC)(GLuint texture,
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
typedef void(APIENTRYP PFNGLTEXTURESUBIMAGE3DEXTPROC)(GLuint texture,
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
typedef void(APIENTRYP PFNGLCOPYTEXTURESUBIMAGE3DEXTPROC)(GLuint texture,
                                                          GLenum target,
                                                          GLint level,
                                                          GLint xoffset,
                                                          GLint yoffset,
                                                          GLint zoffset,
                                                          GLint x,
                                                          GLint y,
                                                          GLsizei width,
                                                          GLsizei height);
typedef void(APIENTRYP PFNGLBINDMULTITEXTUREEXTPROC)(GLenum texunit, GLenum target, GLuint texture);
typedef void(APIENTRYP PFNGLMULTITEXCOORDPOINTEREXTPROC)(GLenum texunit,
                                                         GLint size,
                                                         GLenum type,
                                                         GLsizei stride,
                                                         const void* pointer);
typedef void(APIENTRYP PFNGLMULTITEXENVFEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLfloat param);
typedef void(APIENTRYP PFNGLMULTITEXENVFVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, const GLfloat* params);
typedef void(APIENTRYP PFNGLMULTITEXENVIEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLint param);
typedef void(APIENTRYP PFNGLMULTITEXENVIVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, const GLint* params);
typedef void(APIENTRYP PFNGLMULTITEXGENDEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, GLdouble param);
typedef void(APIENTRYP PFNGLMULTITEXGENDVEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, const GLdouble* params);
typedef void(APIENTRYP PFNGLMULTITEXGENFEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, GLfloat param);
typedef void(APIENTRYP PFNGLMULTITEXGENFVEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, const GLfloat* params);
typedef void(APIENTRYP PFNGLMULTITEXGENIEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, GLint param);
typedef void(APIENTRYP PFNGLMULTITEXGENIVEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, const GLint* params);
typedef void(APIENTRYP PFNGLGETMULTITEXENVFVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLfloat* params);
typedef void(APIENTRYP PFNGLGETMULTITEXENVIVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLint* params);
typedef void(APIENTRYP PFNGLGETMULTITEXGENDVEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, GLdouble* params);
typedef void(APIENTRYP PFNGLGETMULTITEXGENFVEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, GLfloat* params);
typedef void(APIENTRYP PFNGLGETMULTITEXGENIVEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, GLint* params);
typedef void(APIENTRYP PFNGLMULTITEXPARAMETERIEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLint param);
typedef void(APIENTRYP PFNGLMULTITEXPARAMETERIVEXTPROC)(GLenum texunit,
                                                        GLenum target,
                                                        GLenum pname,
                                                        const GLint* params);
typedef void(APIENTRYP PFNGLMULTITEXPARAMETERFEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLfloat param);
typedef void(APIENTRYP PFNGLMULTITEXPARAMETERFVEXTPROC)(GLenum texunit,
                                                        GLenum target,
                                                        GLenum pname,
                                                        const GLfloat* params);
typedef void(APIENTRYP PFNGLMULTITEXIMAGE1DEXTPROC)(GLenum texunit,
                                                    GLenum target,
                                                    GLint level,
                                                    GLint internalformat,
                                                    GLsizei width,
                                                    GLint border,
                                                    GLenum format,
                                                    GLenum type,
                                                    const void* pixels);
typedef void(APIENTRYP PFNGLMULTITEXIMAGE2DEXTPROC)(GLenum texunit,
                                                    GLenum target,
                                                    GLint level,
                                                    GLint internalformat,
                                                    GLsizei width,
                                                    GLsizei height,
                                                    GLint border,
                                                    GLenum format,
                                                    GLenum type,
                                                    const void* pixels);
typedef void(APIENTRYP PFNGLMULTITEXSUBIMAGE1DEXTPROC)(GLenum texunit,
                                                       GLenum target,
                                                       GLint level,
                                                       GLint xoffset,
                                                       GLsizei width,
                                                       GLenum format,
                                                       GLenum type,
                                                       const void* pixels);
typedef void(APIENTRYP PFNGLMULTITEXSUBIMAGE2DEXTPROC)(GLenum texunit,
                                                       GLenum target,
                                                       GLint level,
                                                       GLint xoffset,
                                                       GLint yoffset,
                                                       GLsizei width,
                                                       GLsizei height,
                                                       GLenum format,
                                                       GLenum type,
                                                       const void* pixels);
typedef void(APIENTRYP PFNGLCOPYMULTITEXIMAGE1DEXTPROC)(GLenum texunit,
                                                        GLenum target,
                                                        GLint level,
                                                        GLenum internalformat,
                                                        GLint x,
                                                        GLint y,
                                                        GLsizei width,
                                                        GLint border);
typedef void(APIENTRYP PFNGLCOPYMULTITEXIMAGE2DEXTPROC)(GLenum texunit,
                                                        GLenum target,
                                                        GLint level,
                                                        GLenum internalformat,
                                                        GLint x,
                                                        GLint y,
                                                        GLsizei width,
                                                        GLsizei height,
                                                        GLint border);
typedef void(APIENTRYP PFNGLCOPYMULTITEXSUBIMAGE1DEXTPROC)(GLenum texunit,
                                                           GLenum target,
                                                           GLint level,
                                                           GLint xoffset,
                                                           GLint x,
                                                           GLint y,
                                                           GLsizei width);
typedef void(APIENTRYP PFNGLCOPYMULTITEXSUBIMAGE2DEXTPROC)(GLenum texunit,
                                                           GLenum target,
                                                           GLint level,
                                                           GLint xoffset,
                                                           GLint yoffset,
                                                           GLint x,
                                                           GLint y,
                                                           GLsizei width,
                                                           GLsizei height);
typedef void(APIENTRYP PFNGLGETMULTITEXIMAGEEXTPROC)(GLenum texunit,
                                                     GLenum target,
                                                     GLint level,
                                                     GLenum format,
                                                     GLenum type,
                                                     void* pixels);
typedef void(APIENTRYP PFNGLGETMULTITEXPARAMETERFVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLfloat* params);
typedef void(APIENTRYP PFNGLGETMULTITEXPARAMETERIVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLint* params);
typedef void(APIENTRYP PFNGLGETMULTITEXLEVELPARAMETERFVEXTPROC)(GLenum texunit,
                                                                GLenum target,
                                                                GLint level,
                                                                GLenum pname,
                                                                GLfloat* params);
typedef void(APIENTRYP PFNGLGETMULTITEXLEVELPARAMETERIVEXTPROC)(GLenum texunit,
                                                                GLenum target,
                                                                GLint level,
                                                                GLenum pname,
                                                                GLint* params);
typedef void(APIENTRYP PFNGLMULTITEXIMAGE3DEXTPROC)(GLenum texunit,
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
typedef void(APIENTRYP PFNGLMULTITEXSUBIMAGE3DEXTPROC)(GLenum texunit,
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
typedef void(APIENTRYP PFNGLCOPYMULTITEXSUBIMAGE3DEXTPROC)(GLenum texunit,
                                                           GLenum target,
                                                           GLint level,
                                                           GLint xoffset,
                                                           GLint yoffset,
                                                           GLint zoffset,
                                                           GLint x,
                                                           GLint y,
                                                           GLsizei width,
                                                           GLsizei height);
typedef void(APIENTRYP PFNGLENABLECLIENTSTATEINDEXEDEXTPROC)(GLenum array, GLuint index);
typedef void(APIENTRYP PFNGLDISABLECLIENTSTATEINDEXEDEXTPROC)(GLenum array, GLuint index);
typedef void(APIENTRYP PFNGLGETFLOATINDEXEDVEXTPROC)(GLenum target, GLuint index, GLfloat* data);
typedef void(APIENTRYP PFNGLGETDOUBLEINDEXEDVEXTPROC)(GLenum target, GLuint index, GLdouble* data);
typedef void(APIENTRYP PFNGLGETPOINTERINDEXEDVEXTPROC)(GLenum target, GLuint index, void** data);
typedef void(APIENTRYP PFNGLENABLEINDEXEDEXTPROC)(GLenum target, GLuint index);
typedef void(APIENTRYP PFNGLDISABLEINDEXEDEXTPROC)(GLenum target, GLuint index);
typedef GLboolean(APIENTRYP PFNGLISENABLEDINDEXEDEXTPROC)(GLenum target, GLuint index);
typedef void(APIENTRYP PFNGLGETINTEGERINDEXEDVEXTPROC)(GLenum target, GLuint index, GLint* data);
typedef void(APIENTRYP PFNGLGETBOOLEANINDEXEDVEXTPROC)(GLenum target, GLuint index, GLboolean* data);
typedef void(APIENTRYP PFNGLCOMPRESSEDTEXTUREIMAGE3DEXTPROC)(GLuint texture,
                                                             GLenum target,
                                                             GLint level,
                                                             GLenum internalformat,
                                                             GLsizei width,
                                                             GLsizei height,
                                                             GLsizei depth,
                                                             GLint border,
                                                             GLsizei imageSize,
                                                             const void* bits);
typedef void(APIENTRYP PFNGLCOMPRESSEDTEXTUREIMAGE2DEXTPROC)(GLuint texture,
                                                             GLenum target,
                                                             GLint level,
                                                             GLenum internalformat,
                                                             GLsizei width,
                                                             GLsizei height,
                                                             GLint border,
                                                             GLsizei imageSize,
                                                             const void* bits);
typedef void(APIENTRYP PFNGLCOMPRESSEDTEXTUREIMAGE1DEXTPROC)(GLuint texture,
                                                             GLenum target,
                                                             GLint level,
                                                             GLenum internalformat,
                                                             GLsizei width,
                                                             GLint border,
                                                             GLsizei imageSize,
                                                             const void* bits);
typedef void(APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXTPROC)(GLuint texture,
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
typedef void(APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXTPROC)(GLuint texture,
                                                                GLenum target,
                                                                GLint level,
                                                                GLint xoffset,
                                                                GLint yoffset,
                                                                GLsizei width,
                                                                GLsizei height,
                                                                GLenum format,
                                                                GLsizei imageSize,
                                                                const void* bits);
typedef void(APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXTPROC)(GLuint texture,
                                                                GLenum target,
                                                                GLint level,
                                                                GLint xoffset,
                                                                GLsizei width,
                                                                GLenum format,
                                                                GLsizei imageSize,
                                                                const void* bits);
typedef void(APIENTRYP PFNGLGETCOMPRESSEDTEXTUREIMAGEEXTPROC)(GLuint texture, GLenum target, GLint lod, void* img);
typedef void(APIENTRYP PFNGLCOMPRESSEDMULTITEXIMAGE3DEXTPROC)(GLenum texunit,
                                                              GLenum target,
                                                              GLint level,
                                                              GLenum internalformat,
                                                              GLsizei width,
                                                              GLsizei height,
                                                              GLsizei depth,
                                                              GLint border,
                                                              GLsizei imageSize,
                                                              const void* bits);
typedef void(APIENTRYP PFNGLCOMPRESSEDMULTITEXIMAGE2DEXTPROC)(GLenum texunit,
                                                              GLenum target,
                                                              GLint level,
                                                              GLenum internalformat,
                                                              GLsizei width,
                                                              GLsizei height,
                                                              GLint border,
                                                              GLsizei imageSize,
                                                              const void* bits);
typedef void(APIENTRYP PFNGLCOMPRESSEDMULTITEXIMAGE1DEXTPROC)(GLenum texunit,
                                                              GLenum target,
                                                              GLint level,
                                                              GLenum internalformat,
                                                              GLsizei width,
                                                              GLint border,
                                                              GLsizei imageSize,
                                                              const void* bits);
typedef void(APIENTRYP PFNGLCOMPRESSEDMULTITEXSUBIMAGE3DEXTPROC)(GLenum texunit,
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
typedef void(APIENTRYP PFNGLCOMPRESSEDMULTITEXSUBIMAGE2DEXTPROC)(GLenum texunit,
                                                                 GLenum target,
                                                                 GLint level,
                                                                 GLint xoffset,
                                                                 GLint yoffset,
                                                                 GLsizei width,
                                                                 GLsizei height,
                                                                 GLenum format,
                                                                 GLsizei imageSize,
                                                                 const void* bits);
typedef void(APIENTRYP PFNGLCOMPRESSEDMULTITEXSUBIMAGE1DEXTPROC)(GLenum texunit,
                                                                 GLenum target,
                                                                 GLint level,
                                                                 GLint xoffset,
                                                                 GLsizei width,
                                                                 GLenum format,
                                                                 GLsizei imageSize,
                                                                 const void* bits);
typedef void(APIENTRYP PFNGLGETCOMPRESSEDMULTITEXIMAGEEXTPROC)(GLenum texunit, GLenum target, GLint lod, void* img);
typedef void(APIENTRYP PFNGLMATRIXLOADTRANSPOSEFEXTPROC)(GLenum mode, const GLfloat* m);
typedef void(APIENTRYP PFNGLMATRIXLOADTRANSPOSEDEXTPROC)(GLenum mode, const GLdouble* m);
typedef void(APIENTRYP PFNGLMATRIXMULTTRANSPOSEFEXTPROC)(GLenum mode, const GLfloat* m);
typedef void(APIENTRYP PFNGLMATRIXMULTTRANSPOSEDEXTPROC)(GLenum mode, const GLdouble* m);
typedef void(APIENTRYP PFNGLNAMEDBUFFERDATAEXTPROC)(GLuint buffer, GLsizeiptr size, const void* data, GLenum usage);
typedef void(APIENTRYP PFNGLNAMEDBUFFERSUBDATAEXTPROC)(GLuint buffer,
                                                       GLintptr offset,
                                                       GLsizeiptr size,
                                                       const void* data);
typedef void*(APIENTRYP PFNGLMAPNAMEDBUFFEREXTPROC)(GLuint buffer, GLenum access);
typedef GLboolean(APIENTRYP PFNGLUNMAPNAMEDBUFFEREXTPROC)(GLuint buffer);
typedef void(APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERIVEXTPROC)(GLuint buffer, GLenum pname, GLint* params);
typedef void(APIENTRYP PFNGLGETNAMEDBUFFERPOINTERVEXTPROC)(GLuint buffer, GLenum pname, void** params);
typedef void(APIENTRYP PFNGLGETNAMEDBUFFERSUBDATAEXTPROC)(GLuint buffer, GLintptr offset, GLsizeiptr size, void* data);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM1FEXTPROC)(GLuint program, GLint location, GLfloat v0);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM2FEXTPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM3FEXTPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void(
APIENTRYP PFNGLPROGRAMUNIFORM4FEXTPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM1IEXTPROC)(GLuint program, GLint location, GLint v0);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM2IEXTPROC)(GLuint program, GLint location, GLint v0, GLint v1);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM3IEXTPROC)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
typedef void(
APIENTRYP PFNGLPROGRAMUNIFORM4IEXTPROC)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM1FVEXTPROC)(GLuint program,
                                                      GLint location,
                                                      GLsizei count,
                                                      const GLfloat* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM2FVEXTPROC)(GLuint program,
                                                      GLint location,
                                                      GLsizei count,
                                                      const GLfloat* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM3FVEXTPROC)(GLuint program,
                                                      GLint location,
                                                      GLsizei count,
                                                      const GLfloat* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM4FVEXTPROC)(GLuint program,
                                                      GLint location,
                                                      GLsizei count,
                                                      const GLfloat* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM1IVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLint* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM2IVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLint* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM3IVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLint* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM4IVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLint* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2FVEXTPROC)(GLuint program,
                                                            GLint location,
                                                            GLsizei count,
                                                            GLboolean transpose,
                                                            const GLfloat* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3FVEXTPROC)(GLuint program,
                                                            GLint location,
                                                            GLsizei count,
                                                            GLboolean transpose,
                                                            const GLfloat* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4FVEXTPROC)(GLuint program,
                                                            GLint location,
                                                            GLsizei count,
                                                            GLboolean transpose,
                                                            const GLfloat* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3FVEXTPROC)(GLuint program,
                                                              GLint location,
                                                              GLsizei count,
                                                              GLboolean transpose,
                                                              const GLfloat* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2FVEXTPROC)(GLuint program,
                                                              GLint location,
                                                              GLsizei count,
                                                              GLboolean transpose,
                                                              const GLfloat* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4FVEXTPROC)(GLuint program,
                                                              GLint location,
                                                              GLsizei count,
                                                              GLboolean transpose,
                                                              const GLfloat* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2FVEXTPROC)(GLuint program,
                                                              GLint location,
                                                              GLsizei count,
                                                              GLboolean transpose,
                                                              const GLfloat* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4FVEXTPROC)(GLuint program,
                                                              GLint location,
                                                              GLsizei count,
                                                              GLboolean transpose,
                                                              const GLfloat* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3FVEXTPROC)(GLuint program,
                                                              GLint location,
                                                              GLsizei count,
                                                              GLboolean transpose,
                                                              const GLfloat* value);
typedef void(APIENTRYP PFNGLTEXTUREBUFFEREXTPROC)(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer);
typedef void(APIENTRYP PFNGLMULTITEXBUFFEREXTPROC)(GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer);
typedef void(APIENTRYP PFNGLTEXTUREPARAMETERIIVEXTPROC)(GLuint texture,
                                                        GLenum target,
                                                        GLenum pname,
                                                        const GLint* params);
typedef void(APIENTRYP PFNGLTEXTUREPARAMETERIUIVEXTPROC)(GLuint texture,
                                                         GLenum target,
                                                         GLenum pname,
                                                         const GLuint* params);
typedef void(APIENTRYP PFNGLGETTEXTUREPARAMETERIIVEXTPROC)(GLuint texture, GLenum target, GLenum pname, GLint* params);
typedef void(APIENTRYP PFNGLGETTEXTUREPARAMETERIUIVEXTPROC)(GLuint texture, GLenum target, GLenum pname, GLuint* params);
typedef void(APIENTRYP PFNGLMULTITEXPARAMETERIIVEXTPROC)(GLenum texunit,
                                                         GLenum target,
                                                         GLenum pname,
                                                         const GLint* params);
typedef void(APIENTRYP PFNGLMULTITEXPARAMETERIUIVEXTPROC)(GLenum texunit,
                                                          GLenum target,
                                                          GLenum pname,
                                                          const GLuint* params);
typedef void(APIENTRYP PFNGLGETMULTITEXPARAMETERIIVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLint* params);
typedef void(APIENTRYP PFNGLGETMULTITEXPARAMETERIUIVEXTPROC)(GLenum texunit,
                                                             GLenum target,
                                                             GLenum pname,
                                                             GLuint* params);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM1UIEXTPROC)(GLuint program, GLint location, GLuint v0);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM2UIEXTPROC)(GLuint program, GLint location, GLuint v0, GLuint v1);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM3UIEXTPROC)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
typedef void(
APIENTRYP PFNGLPROGRAMUNIFORM4UIEXTPROC)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM1UIVEXTPROC)(GLuint program,
                                                       GLint location,
                                                       GLsizei count,
                                                       const GLuint* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM2UIVEXTPROC)(GLuint program,
                                                       GLint location,
                                                       GLsizei count,
                                                       const GLuint* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM3UIVEXTPROC)(GLuint program,
                                                       GLint location,
                                                       GLsizei count,
                                                       const GLuint* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM4UIVEXTPROC)(GLuint program,
                                                       GLint location,
                                                       GLsizei count,
                                                       const GLuint* value);
typedef void(APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERS4FVEXTPROC)(GLuint program,
                                                                   GLenum target,
                                                                   GLuint index,
                                                                   GLsizei count,
                                                                   const GLfloat* params);
typedef void(APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERI4IEXTPROC)(GLuint program,
                                                                  GLenum target,
                                                                  GLuint index,
                                                                  GLint x,
                                                                  GLint y,
                                                                  GLint z,
                                                                  GLint w);
typedef void(APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERI4IVEXTPROC)(GLuint program,
                                                                   GLenum target,
                                                                   GLuint index,
                                                                   const GLint* params);
typedef void(APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERSI4IVEXTPROC)(GLuint program,
                                                                    GLenum target,
                                                                    GLuint index,
                                                                    GLsizei count,
                                                                    const GLint* params);
typedef void(APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIEXTPROC)(GLuint program,
                                                                   GLenum target,
                                                                   GLuint index,
                                                                   GLuint x,
                                                                   GLuint y,
                                                                   GLuint z,
                                                                   GLuint w);
typedef void(APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIVEXTPROC)(GLuint program,
                                                                    GLenum target,
                                                                    GLuint index,
                                                                    const GLuint* params);
typedef void(APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERSI4UIVEXTPROC)(GLuint program,
                                                                     GLenum target,
                                                                     GLuint index,
                                                                     GLsizei count,
                                                                     const GLuint* params);
typedef void(APIENTRYP PFNGLGETNAMEDPROGRAMLOCALPARAMETERIIVEXTPROC)(GLuint program,
                                                                     GLenum target,
                                                                     GLuint index,
                                                                     GLint* params);
typedef void(APIENTRYP PFNGLGETNAMEDPROGRAMLOCALPARAMETERIUIVEXTPROC)(GLuint program,
                                                                      GLenum target,
                                                                      GLuint index,
                                                                      GLuint* params);
typedef void(APIENTRYP PFNGLENABLECLIENTSTATEIEXTPROC)(GLenum array, GLuint index);
typedef void(APIENTRYP PFNGLDISABLECLIENTSTATEIEXTPROC)(GLenum array, GLuint index);
typedef void(APIENTRYP PFNGLGETFLOATI_VEXTPROC)(GLenum pname, GLuint index, GLfloat* params);
typedef void(APIENTRYP PFNGLGETDOUBLEI_VEXTPROC)(GLenum pname, GLuint index, GLdouble* params);
typedef void(APIENTRYP PFNGLGETPOINTERI_VEXTPROC)(GLenum pname, GLuint index, void** params);
typedef void(APIENTRYP PFNGLNAMEDPROGRAMSTRINGEXTPROC)(GLuint program,
                                                       GLenum target,
                                                       GLenum format,
                                                       GLsizei len,
                                                       const void* string);
typedef void(APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETER4DEXTPROC)(GLuint program,
                                                                 GLenum target,
                                                                 GLuint index,
                                                                 GLdouble x,
                                                                 GLdouble y,
                                                                 GLdouble z,
                                                                 GLdouble w);
typedef void(APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETER4DVEXTPROC)(GLuint program,
                                                                  GLenum target,
                                                                  GLuint index,
                                                                  const GLdouble* params);
typedef void(APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETER4FEXTPROC)(GLuint program,
                                                                 GLenum target,
                                                                 GLuint index,
                                                                 GLfloat x,
                                                                 GLfloat y,
                                                                 GLfloat z,
                                                                 GLfloat w);
typedef void(APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETER4FVEXTPROC)(GLuint program,
                                                                  GLenum target,
                                                                  GLuint index,
                                                                  const GLfloat* params);
typedef void(APIENTRYP PFNGLGETNAMEDPROGRAMLOCALPARAMETERDVEXTPROC)(GLuint program,
                                                                    GLenum target,
                                                                    GLuint index,
                                                                    GLdouble* params);
typedef void(APIENTRYP PFNGLGETNAMEDPROGRAMLOCALPARAMETERFVEXTPROC)(GLuint program,
                                                                    GLenum target,
                                                                    GLuint index,
                                                                    GLfloat* params);
typedef void(APIENTRYP PFNGLGETNAMEDPROGRAMIVEXTPROC)(GLuint program, GLenum target, GLenum pname, GLint* params);
typedef void(APIENTRYP PFNGLGETNAMEDPROGRAMSTRINGEXTPROC)(GLuint program, GLenum target, GLenum pname, void* string);
typedef void(APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEEXTPROC)(GLuint renderbuffer,
                                                             GLenum internalformat,
                                                             GLsizei width,
                                                             GLsizei height);
typedef void(APIENTRYP PFNGLGETNAMEDRENDERBUFFERPARAMETERIVEXTPROC)(GLuint renderbuffer, GLenum pname, GLint* params);
typedef void(APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC)(GLuint renderbuffer,
                                                                        GLsizei samples,
                                                                        GLenum internalformat,
                                                                        GLsizei width,
                                                                        GLsizei height);
typedef void(APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXTPROC)(GLuint renderbuffer,
                                                                                GLsizei coverageSamples,
                                                                                GLsizei colorSamples,
                                                                                GLenum internalformat,
                                                                                GLsizei width,
                                                                                GLsizei height);
typedef GLenum(APIENTRYP PFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXTPROC)(GLuint framebuffer, GLenum target);
typedef void(APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURE1DEXTPROC)(GLuint framebuffer,
                                                              GLenum attachment,
                                                              GLenum textarget,
                                                              GLuint texture,
                                                              GLint level);
typedef void(APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURE2DEXTPROC)(GLuint framebuffer,
                                                              GLenum attachment,
                                                              GLenum textarget,
                                                              GLuint texture,
                                                              GLint level);
typedef void(APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURE3DEXTPROC)(GLuint framebuffer,
                                                              GLenum attachment,
                                                              GLenum textarget,
                                                              GLuint texture,
                                                              GLint level,
                                                              GLint zoffset);
typedef void(APIENTRYP PFNGLNAMEDFRAMEBUFFERRENDERBUFFEREXTPROC)(GLuint framebuffer,
                                                                 GLenum attachment,
                                                                 GLenum renderbuffertarget,
                                                                 GLuint renderbuffer);
typedef void(APIENTRYP PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC)(GLuint framebuffer,
                                                                             GLenum attachment,
                                                                             GLenum pname,
                                                                             GLint* params);
typedef void(APIENTRYP PFNGLGENERATETEXTUREMIPMAPEXTPROC)(GLuint texture, GLenum target);
typedef void(APIENTRYP PFNGLGENERATEMULTITEXMIPMAPEXTPROC)(GLenum texunit, GLenum target);
typedef void(APIENTRYP PFNGLFRAMEBUFFERDRAWBUFFEREXTPROC)(GLuint framebuffer, GLenum mode);
typedef void(APIENTRYP PFNGLFRAMEBUFFERDRAWBUFFERSEXTPROC)(GLuint framebuffer, GLsizei n, const GLenum* bufs);
typedef void(APIENTRYP PFNGLFRAMEBUFFERREADBUFFEREXTPROC)(GLuint framebuffer, GLenum mode);
typedef void(APIENTRYP PFNGLGETFRAMEBUFFERPARAMETERIVEXTPROC)(GLuint framebuffer, GLenum pname, GLint* params);
typedef void(APIENTRYP PFNGLNAMEDCOPYBUFFERSUBDATAEXTPROC)(GLuint readBuffer,
                                                           GLuint writeBuffer,
                                                           GLintptr readOffset,
                                                           GLintptr writeOffset,
                                                           GLsizeiptr size);
typedef void(APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC)(GLuint framebuffer,
                                                            GLenum attachment,
                                                            GLuint texture,
                                                            GLint level);
typedef void(APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXTPROC)(GLuint framebuffer,
                                                                 GLenum attachment,
                                                                 GLuint texture,
                                                                 GLint level,
                                                                 GLint layer);
typedef void(APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTUREFACEEXTPROC)(GLuint framebuffer,
                                                                GLenum attachment,
                                                                GLuint texture,
                                                                GLint level,
                                                                GLenum face);
typedef void(APIENTRYP PFNGLTEXTURERENDERBUFFEREXTPROC)(GLuint texture, GLenum target, GLuint renderbuffer);
typedef void(APIENTRYP PFNGLMULTITEXRENDERBUFFEREXTPROC)(GLenum texunit, GLenum target, GLuint renderbuffer);
typedef void(APIENTRYP PFNGLVERTEXARRAYVERTEXOFFSETEXTPROC)(GLuint vaobj,
                                                            GLuint buffer,
                                                            GLint size,
                                                            GLenum type,
                                                            GLsizei stride,
                                                            GLintptr offset);
typedef void(APIENTRYP PFNGLVERTEXARRAYCOLOROFFSETEXTPROC)(GLuint vaobj,
                                                           GLuint buffer,
                                                           GLint size,
                                                           GLenum type,
                                                           GLsizei stride,
                                                           GLintptr offset);
typedef void(APIENTRYP PFNGLVERTEXARRAYEDGEFLAGOFFSETEXTPROC)(GLuint vaobj,
                                                              GLuint buffer,
                                                              GLsizei stride,
                                                              GLintptr offset);
typedef void(APIENTRYP PFNGLVERTEXARRAYINDEXOFFSETEXTPROC)(GLuint vaobj,
                                                           GLuint buffer,
                                                           GLenum type,
                                                           GLsizei stride,
                                                           GLintptr offset);
typedef void(APIENTRYP PFNGLVERTEXARRAYNORMALOFFSETEXTPROC)(GLuint vaobj,
                                                            GLuint buffer,
                                                            GLenum type,
                                                            GLsizei stride,
                                                            GLintptr offset);
typedef void(APIENTRYP PFNGLVERTEXARRAYTEXCOORDOFFSETEXTPROC)(GLuint vaobj,
                                                              GLuint buffer,
                                                              GLint size,
                                                              GLenum type,
                                                              GLsizei stride,
                                                              GLintptr offset);
typedef void(APIENTRYP PFNGLVERTEXARRAYMULTITEXCOORDOFFSETEXTPROC)(GLuint vaobj,
                                                                   GLuint buffer,
                                                                   GLenum texunit,
                                                                   GLint size,
                                                                   GLenum type,
                                                                   GLsizei stride,
                                                                   GLintptr offset);
typedef void(APIENTRYP PFNGLVERTEXARRAYFOGCOORDOFFSETEXTPROC)(GLuint vaobj,
                                                              GLuint buffer,
                                                              GLenum type,
                                                              GLsizei stride,
                                                              GLintptr offset);
typedef void(APIENTRYP PFNGLVERTEXARRAYSECONDARYCOLOROFFSETEXTPROC)(GLuint vaobj,
                                                                    GLuint buffer,
                                                                    GLint size,
                                                                    GLenum type,
                                                                    GLsizei stride,
                                                                    GLintptr offset);
typedef void(APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBOFFSETEXTPROC)(GLuint vaobj,
                                                                  GLuint buffer,
                                                                  GLuint index,
                                                                  GLint size,
                                                                  GLenum type,
                                                                  GLboolean normalized,
                                                                  GLsizei stride,
                                                                  GLintptr offset);
typedef void(APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBIOFFSETEXTPROC)(GLuint vaobj,
                                                                   GLuint buffer,
                                                                   GLuint index,
                                                                   GLint size,
                                                                   GLenum type,
                                                                   GLsizei stride,
                                                                   GLintptr offset);
typedef void(APIENTRYP PFNGLENABLEVERTEXARRAYEXTPROC)(GLuint vaobj, GLenum array);
typedef void(APIENTRYP PFNGLDISABLEVERTEXARRAYEXTPROC)(GLuint vaobj, GLenum array);
typedef void(APIENTRYP PFNGLENABLEVERTEXARRAYATTRIBEXTPROC)(GLuint vaobj, GLuint index);
typedef void(APIENTRYP PFNGLDISABLEVERTEXARRAYATTRIBEXTPROC)(GLuint vaobj, GLuint index);
typedef void(APIENTRYP PFNGLGETVERTEXARRAYINTEGERVEXTPROC)(GLuint vaobj, GLenum pname, GLint* param);
typedef void(APIENTRYP PFNGLGETVERTEXARRAYPOINTERVEXTPROC)(GLuint vaobj, GLenum pname, void** param);
typedef void(APIENTRYP PFNGLGETVERTEXARRAYINTEGERI_VEXTPROC)(GLuint vaobj, GLuint index, GLenum pname, GLint* param);
typedef void(APIENTRYP PFNGLGETVERTEXARRAYPOINTERI_VEXTPROC)(GLuint vaobj, GLuint index, GLenum pname, void** param);
typedef void*(APIENTRYP PFNGLMAPNAMEDBUFFERRANGEEXTPROC)(GLuint buffer,
                                                         GLintptr offset,
                                                         GLsizeiptr length,
                                                         GLbitfield access);
typedef void(APIENTRYP PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEEXTPROC)(GLuint buffer, GLintptr offset, GLsizeiptr length);
typedef void(APIENTRYP PFNGLNAMEDBUFFERSTORAGEEXTPROC)(GLuint buffer,
                                                       GLsizeiptr size,
                                                       const void* data,
                                                       GLbitfield flags);
typedef void(APIENTRYP PFNGLCLEARNAMEDBUFFERDATAEXTPROC)(GLuint buffer,
                                                         GLenum internalformat,
                                                         GLenum format,
                                                         GLenum type,
                                                         const void* data);
typedef void(APIENTRYP PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC)(GLuint buffer,
                                                            GLenum internalformat,
                                                            GLsizeiptr offset,
                                                            GLsizeiptr size,
                                                            GLenum format,
                                                            GLenum type,
                                                            const void* data);
typedef void(APIENTRYP PFNGLNAMEDFRAMEBUFFERPARAMETERIEXTPROC)(GLuint framebuffer, GLenum pname, GLint param);
typedef void(APIENTRYP PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXTPROC)(GLuint framebuffer, GLenum pname, GLint* params);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM1DEXTPROC)(GLuint program, GLint location, GLdouble x);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM2DEXTPROC)(GLuint program, GLint location, GLdouble x, GLdouble y);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM3DEXTPROC)(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z);
typedef void(
APIENTRYP PFNGLPROGRAMUNIFORM4DEXTPROC)(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM1DVEXTPROC)(GLuint program,
                                                      GLint location,
                                                      GLsizei count,
                                                      const GLdouble* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM2DVEXTPROC)(GLuint program,
                                                      GLint location,
                                                      GLsizei count,
                                                      const GLdouble* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM3DVEXTPROC)(GLuint program,
                                                      GLint location,
                                                      GLsizei count,
                                                      const GLdouble* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM4DVEXTPROC)(GLuint program,
                                                      GLint location,
                                                      GLsizei count,
                                                      const GLdouble* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2DVEXTPROC)(GLuint program,
                                                            GLint location,
                                                            GLsizei count,
                                                            GLboolean transpose,
                                                            const GLdouble* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3DVEXTPROC)(GLuint program,
                                                            GLint location,
                                                            GLsizei count,
                                                            GLboolean transpose,
                                                            const GLdouble* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4DVEXTPROC)(GLuint program,
                                                            GLint location,
                                                            GLsizei count,
                                                            GLboolean transpose,
                                                            const GLdouble* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3DVEXTPROC)(GLuint program,
                                                              GLint location,
                                                              GLsizei count,
                                                              GLboolean transpose,
                                                              const GLdouble* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4DVEXTPROC)(GLuint program,
                                                              GLint location,
                                                              GLsizei count,
                                                              GLboolean transpose,
                                                              const GLdouble* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2DVEXTPROC)(GLuint program,
                                                              GLint location,
                                                              GLsizei count,
                                                              GLboolean transpose,
                                                              const GLdouble* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4DVEXTPROC)(GLuint program,
                                                              GLint location,
                                                              GLsizei count,
                                                              GLboolean transpose,
                                                              const GLdouble* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2DVEXTPROC)(GLuint program,
                                                              GLint location,
                                                              GLsizei count,
                                                              GLboolean transpose,
                                                              const GLdouble* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3DVEXTPROC)(GLuint program,
                                                              GLint location,
                                                              GLsizei count,
                                                              GLboolean transpose,
                                                              const GLdouble* value);
typedef void(APIENTRYP PFNGLTEXTUREBUFFERRANGEEXTPROC)(GLuint texture,
                                                       GLenum target,
                                                       GLenum internalformat,
                                                       GLuint buffer,
                                                       GLintptr offset,
                                                       GLsizeiptr size);
typedef void(APIENTRYP PFNGLTEXTURESTORAGE1DEXTPROC)(GLuint texture,
                                                     GLenum target,
                                                     GLsizei levels,
                                                     GLenum internalformat,
                                                     GLsizei width);
typedef void(APIENTRYP PFNGLTEXTURESTORAGE2DEXTPROC)(GLuint texture,
                                                     GLenum target,
                                                     GLsizei levels,
                                                     GLenum internalformat,
                                                     GLsizei width,
                                                     GLsizei height);
typedef void(APIENTRYP PFNGLTEXTURESTORAGE3DEXTPROC)(GLuint texture,
                                                     GLenum target,
                                                     GLsizei levels,
                                                     GLenum internalformat,
                                                     GLsizei width,
                                                     GLsizei height,
                                                     GLsizei depth);
typedef void(APIENTRYP PFNGLTEXTURESTORAGE2DMULTISAMPLEEXTPROC)(GLuint texture,
                                                                GLenum target,
                                                                GLsizei samples,
                                                                GLenum internalformat,
                                                                GLsizei width,
                                                                GLsizei height,
                                                                GLboolean fixedsamplelocations);
typedef void(APIENTRYP PFNGLTEXTURESTORAGE3DMULTISAMPLEEXTPROC)(GLuint texture,
                                                                GLenum target,
                                                                GLsizei samples,
                                                                GLenum internalformat,
                                                                GLsizei width,
                                                                GLsizei height,
                                                                GLsizei depth,
                                                                GLboolean fixedsamplelocations);
typedef void(APIENTRYP PFNGLVERTEXARRAYBINDVERTEXBUFFEREXTPROC)(GLuint vaobj,
                                                                GLuint bindingindex,
                                                                GLuint buffer,
                                                                GLintptr offset,
                                                                GLsizei stride);
typedef void(APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBFORMATEXTPROC)(GLuint vaobj,
                                                                  GLuint attribindex,
                                                                  GLint size,
                                                                  GLenum type,
                                                                  GLboolean normalized,
                                                                  GLuint relativeoffset);
typedef void(APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBIFORMATEXTPROC)(GLuint vaobj,
                                                                   GLuint attribindex,
                                                                   GLint size,
                                                                   GLenum type,
                                                                   GLuint relativeoffset);
typedef void(APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBLFORMATEXTPROC)(GLuint vaobj,
                                                                   GLuint attribindex,
                                                                   GLint size,
                                                                   GLenum type,
                                                                   GLuint relativeoffset);
typedef void(APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBBINDINGEXTPROC)(GLuint vaobj,
                                                                   GLuint attribindex,
                                                                   GLuint bindingindex);
typedef void(APIENTRYP PFNGLVERTEXARRAYVERTEXBINDINGDIVISOREXTPROC)(GLuint vaobj, GLuint bindingindex, GLuint divisor);
typedef void(APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBLOFFSETEXTPROC)(GLuint vaobj,
                                                                   GLuint buffer,
                                                                   GLuint index,
                                                                   GLint size,
                                                                   GLenum type,
                                                                   GLsizei stride,
                                                                   GLintptr offset);
typedef void(APIENTRYP PFNGLTEXTUREPAGECOMMITMENTEXTPROC)(GLuint texture,
                                                          GLint level,
                                                          GLint xoffset,
                                                          GLint yoffset,
                                                          GLint zoffset,
                                                          GLsizei width,
                                                          GLsizei height,
                                                          GLsizei depth,
                                                          GLboolean commit);
typedef void(APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBDIVISOREXTPROC)(GLuint vaobj, GLuint index, GLuint divisor);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glMatrixLoadfEXT(GLenum mode, const GLfloat* m);
GLAPI void APIENTRY glMatrixLoaddEXT(GLenum mode, const GLdouble* m);
GLAPI void APIENTRY glMatrixMultfEXT(GLenum mode, const GLfloat* m);
GLAPI void APIENTRY glMatrixMultdEXT(GLenum mode, const GLdouble* m);
GLAPI void APIENTRY glMatrixLoadIdentityEXT(GLenum mode);
GLAPI void APIENTRY glMatrixRotatefEXT(GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
GLAPI void APIENTRY glMatrixRotatedEXT(GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
GLAPI void APIENTRY glMatrixScalefEXT(GLenum mode, GLfloat x, GLfloat y, GLfloat z);
GLAPI void APIENTRY glMatrixScaledEXT(GLenum mode, GLdouble x, GLdouble y, GLdouble z);
GLAPI void APIENTRY glMatrixTranslatefEXT(GLenum mode, GLfloat x, GLfloat y, GLfloat z);
GLAPI void APIENTRY glMatrixTranslatedEXT(GLenum mode, GLdouble x, GLdouble y, GLdouble z);
GLAPI void APIENTRY glMatrixFrustumEXT(GLenum mode,
                                       GLdouble left,
                                       GLdouble right,
                                       GLdouble bottom,
                                       GLdouble top,
                                       GLdouble zNear,
                                       GLdouble zFar);
GLAPI void APIENTRY glMatrixOrthoEXT(GLenum mode,
                                     GLdouble left,
                                     GLdouble right,
                                     GLdouble bottom,
                                     GLdouble top,
                                     GLdouble zNear,
                                     GLdouble zFar);
GLAPI void APIENTRY glMatrixPopEXT(GLenum mode);
GLAPI void APIENTRY glMatrixPushEXT(GLenum mode);
GLAPI void APIENTRY glClientAttribDefaultEXT(GLbitfield mask);
GLAPI void APIENTRY glPushClientAttribDefaultEXT(GLbitfield mask);
GLAPI void APIENTRY glTextureParameterfEXT(GLuint texture, GLenum target, GLenum pname, GLfloat param);
GLAPI void APIENTRY glTextureParameterfvEXT(GLuint texture, GLenum target, GLenum pname, const GLfloat* params);
GLAPI void APIENTRY glTextureParameteriEXT(GLuint texture, GLenum target, GLenum pname, GLint param);
GLAPI void APIENTRY glTextureParameterivEXT(GLuint texture, GLenum target, GLenum pname, const GLint* params);
GLAPI void APIENTRY glTextureImage1DEXT(GLuint texture,
                                        GLenum target,
                                        GLint level,
                                        GLint internalformat,
                                        GLsizei width,
                                        GLint border,
                                        GLenum format,
                                        GLenum type,
                                        const void* pixels);
GLAPI void APIENTRY glTextureImage2DEXT(GLuint texture,
                                        GLenum target,
                                        GLint level,
                                        GLint internalformat,
                                        GLsizei width,
                                        GLsizei height,
                                        GLint border,
                                        GLenum format,
                                        GLenum type,
                                        const void* pixels);
GLAPI void APIENTRY glTextureSubImage1DEXT(GLuint texture,
                                           GLenum target,
                                           GLint level,
                                           GLint xoffset,
                                           GLsizei width,
                                           GLenum format,
                                           GLenum type,
                                           const void* pixels);
GLAPI void APIENTRY glTextureSubImage2DEXT(GLuint texture,
                                           GLenum target,
                                           GLint level,
                                           GLint xoffset,
                                           GLint yoffset,
                                           GLsizei width,
                                           GLsizei height,
                                           GLenum format,
                                           GLenum type,
                                           const void* pixels);
GLAPI void APIENTRY glCopyTextureImage1DEXT(GLuint texture,
                                            GLenum target,
                                            GLint level,
                                            GLenum internalformat,
                                            GLint x,
                                            GLint y,
                                            GLsizei width,
                                            GLint border);
GLAPI void APIENTRY glCopyTextureImage2DEXT(GLuint texture,
                                            GLenum target,
                                            GLint level,
                                            GLenum internalformat,
                                            GLint x,
                                            GLint y,
                                            GLsizei width,
                                            GLsizei height,
                                            GLint border);
GLAPI void APIENTRY
glCopyTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
GLAPI void APIENTRY glCopyTextureSubImage2DEXT(GLuint texture,
                                               GLenum target,
                                               GLint level,
                                               GLint xoffset,
                                               GLint yoffset,
                                               GLint x,
                                               GLint y,
                                               GLsizei width,
                                               GLsizei height);
GLAPI void APIENTRY
glGetTextureImageEXT(GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, void* pixels);
GLAPI void APIENTRY glGetTextureParameterfvEXT(GLuint texture, GLenum target, GLenum pname, GLfloat* params);
GLAPI void APIENTRY glGetTextureParameterivEXT(GLuint texture, GLenum target, GLenum pname, GLint* params);
GLAPI void APIENTRY
glGetTextureLevelParameterfvEXT(GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat* params);
GLAPI void APIENTRY
glGetTextureLevelParameterivEXT(GLuint texture, GLenum target, GLint level, GLenum pname, GLint* params);
GLAPI void APIENTRY glTextureImage3DEXT(GLuint texture,
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
GLAPI void APIENTRY glTextureSubImage3DEXT(GLuint texture,
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
GLAPI void APIENTRY glCopyTextureSubImage3DEXT(GLuint texture,
                                               GLenum target,
                                               GLint level,
                                               GLint xoffset,
                                               GLint yoffset,
                                               GLint zoffset,
                                               GLint x,
                                               GLint y,
                                               GLsizei width,
                                               GLsizei height);
GLAPI void APIENTRY glBindMultiTextureEXT(GLenum texunit, GLenum target, GLuint texture);
GLAPI void APIENTRY
glMultiTexCoordPointerEXT(GLenum texunit, GLint size, GLenum type, GLsizei stride, const void* pointer);
GLAPI void APIENTRY glMultiTexEnvfEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat param);
GLAPI void APIENTRY glMultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum pname, const GLfloat* params);
GLAPI void APIENTRY glMultiTexEnviEXT(GLenum texunit, GLenum target, GLenum pname, GLint param);
GLAPI void APIENTRY glMultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum pname, const GLint* params);
GLAPI void APIENTRY glMultiTexGendEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble param);
GLAPI void APIENTRY glMultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum pname, const GLdouble* params);
GLAPI void APIENTRY glMultiTexGenfEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat param);
GLAPI void APIENTRY glMultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum pname, const GLfloat* params);
GLAPI void APIENTRY glMultiTexGeniEXT(GLenum texunit, GLenum coord, GLenum pname, GLint param);
GLAPI void APIENTRY glMultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum pname, const GLint* params);
GLAPI void APIENTRY glGetMultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat* params);
GLAPI void APIENTRY glGetMultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum pname, GLint* params);
GLAPI void APIENTRY glGetMultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble* params);
GLAPI void APIENTRY glGetMultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat* params);
GLAPI void APIENTRY glGetMultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum pname, GLint* params);
GLAPI void APIENTRY glMultiTexParameteriEXT(GLenum texunit, GLenum target, GLenum pname, GLint param);
GLAPI void APIENTRY glMultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum pname, const GLint* params);
GLAPI void APIENTRY glMultiTexParameterfEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat param);
GLAPI void APIENTRY glMultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum pname, const GLfloat* params);
GLAPI void APIENTRY glMultiTexImage1DEXT(GLenum texunit,
                                         GLenum target,
                                         GLint level,
                                         GLint internalformat,
                                         GLsizei width,
                                         GLint border,
                                         GLenum format,
                                         GLenum type,
                                         const void* pixels);
GLAPI void APIENTRY glMultiTexImage2DEXT(GLenum texunit,
                                         GLenum target,
                                         GLint level,
                                         GLint internalformat,
                                         GLsizei width,
                                         GLsizei height,
                                         GLint border,
                                         GLenum format,
                                         GLenum type,
                                         const void* pixels);
GLAPI void APIENTRY glMultiTexSubImage1DEXT(GLenum texunit,
                                            GLenum target,
                                            GLint level,
                                            GLint xoffset,
                                            GLsizei width,
                                            GLenum format,
                                            GLenum type,
                                            const void* pixels);
GLAPI void APIENTRY glMultiTexSubImage2DEXT(GLenum texunit,
                                            GLenum target,
                                            GLint level,
                                            GLint xoffset,
                                            GLint yoffset,
                                            GLsizei width,
                                            GLsizei height,
                                            GLenum format,
                                            GLenum type,
                                            const void* pixels);
GLAPI void APIENTRY glCopyMultiTexImage1DEXT(GLenum texunit,
                                             GLenum target,
                                             GLint level,
                                             GLenum internalformat,
                                             GLint x,
                                             GLint y,
                                             GLsizei width,
                                             GLint border);
GLAPI void APIENTRY glCopyMultiTexImage2DEXT(GLenum texunit,
                                             GLenum target,
                                             GLint level,
                                             GLenum internalformat,
                                             GLint x,
                                             GLint y,
                                             GLsizei width,
                                             GLsizei height,
                                             GLint border);
GLAPI void APIENTRY
glCopyMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
GLAPI void APIENTRY glCopyMultiTexSubImage2DEXT(GLenum texunit,
                                                GLenum target,
                                                GLint level,
                                                GLint xoffset,
                                                GLint yoffset,
                                                GLint x,
                                                GLint y,
                                                GLsizei width,
                                                GLsizei height);
GLAPI void APIENTRY
glGetMultiTexImageEXT(GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, void* pixels);
GLAPI void APIENTRY glGetMultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat* params);
GLAPI void APIENTRY glGetMultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum pname, GLint* params);
GLAPI void APIENTRY
glGetMultiTexLevelParameterfvEXT(GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat* params);
GLAPI void APIENTRY
glGetMultiTexLevelParameterivEXT(GLenum texunit, GLenum target, GLint level, GLenum pname, GLint* params);
GLAPI void APIENTRY glMultiTexImage3DEXT(GLenum texunit,
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
GLAPI void APIENTRY glMultiTexSubImage3DEXT(GLenum texunit,
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
GLAPI void APIENTRY glCopyMultiTexSubImage3DEXT(GLenum texunit,
                                                GLenum target,
                                                GLint level,
                                                GLint xoffset,
                                                GLint yoffset,
                                                GLint zoffset,
                                                GLint x,
                                                GLint y,
                                                GLsizei width,
                                                GLsizei height);
GLAPI void APIENTRY glEnableClientStateIndexedEXT(GLenum array, GLuint index);
GLAPI void APIENTRY glDisableClientStateIndexedEXT(GLenum array, GLuint index);
GLAPI void APIENTRY glGetFloatIndexedvEXT(GLenum target, GLuint index, GLfloat* data);
GLAPI void APIENTRY glGetDoubleIndexedvEXT(GLenum target, GLuint index, GLdouble* data);
GLAPI void APIENTRY glGetPointerIndexedvEXT(GLenum target, GLuint index, void** data);
GLAPI void APIENTRY glEnableIndexedEXT(GLenum target, GLuint index);
GLAPI void APIENTRY glDisableIndexedEXT(GLenum target, GLuint index);
GLAPI GLboolean APIENTRY glIsEnabledIndexedEXT(GLenum target, GLuint index);
GLAPI void APIENTRY glGetIntegerIndexedvEXT(GLenum target, GLuint index, GLint* data);
GLAPI void APIENTRY glGetBooleanIndexedvEXT(GLenum target, GLuint index, GLboolean* data);
GLAPI void APIENTRY glCompressedTextureImage3DEXT(GLuint texture,
                                                  GLenum target,
                                                  GLint level,
                                                  GLenum internalformat,
                                                  GLsizei width,
                                                  GLsizei height,
                                                  GLsizei depth,
                                                  GLint border,
                                                  GLsizei imageSize,
                                                  const void* bits);
GLAPI void APIENTRY glCompressedTextureImage2DEXT(GLuint texture,
                                                  GLenum target,
                                                  GLint level,
                                                  GLenum internalformat,
                                                  GLsizei width,
                                                  GLsizei height,
                                                  GLint border,
                                                  GLsizei imageSize,
                                                  const void* bits);
GLAPI void APIENTRY glCompressedTextureImage1DEXT(GLuint texture,
                                                  GLenum target,
                                                  GLint level,
                                                  GLenum internalformat,
                                                  GLsizei width,
                                                  GLint border,
                                                  GLsizei imageSize,
                                                  const void* bits);
GLAPI void APIENTRY glCompressedTextureSubImage3DEXT(GLuint texture,
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
GLAPI void APIENTRY glCompressedTextureSubImage2DEXT(GLuint texture,
                                                     GLenum target,
                                                     GLint level,
                                                     GLint xoffset,
                                                     GLint yoffset,
                                                     GLsizei width,
                                                     GLsizei height,
                                                     GLenum format,
                                                     GLsizei imageSize,
                                                     const void* bits);
GLAPI void APIENTRY glCompressedTextureSubImage1DEXT(GLuint texture,
                                                     GLenum target,
                                                     GLint level,
                                                     GLint xoffset,
                                                     GLsizei width,
                                                     GLenum format,
                                                     GLsizei imageSize,
                                                     const void* bits);
GLAPI void APIENTRY glGetCompressedTextureImageEXT(GLuint texture, GLenum target, GLint lod, void* img);
GLAPI void APIENTRY glCompressedMultiTexImage3DEXT(GLenum texunit,
                                                   GLenum target,
                                                   GLint level,
                                                   GLenum internalformat,
                                                   GLsizei width,
                                                   GLsizei height,
                                                   GLsizei depth,
                                                   GLint border,
                                                   GLsizei imageSize,
                                                   const void* bits);
GLAPI void APIENTRY glCompressedMultiTexImage2DEXT(GLenum texunit,
                                                   GLenum target,
                                                   GLint level,
                                                   GLenum internalformat,
                                                   GLsizei width,
                                                   GLsizei height,
                                                   GLint border,
                                                   GLsizei imageSize,
                                                   const void* bits);
GLAPI void APIENTRY glCompressedMultiTexImage1DEXT(GLenum texunit,
                                                   GLenum target,
                                                   GLint level,
                                                   GLenum internalformat,
                                                   GLsizei width,
                                                   GLint border,
                                                   GLsizei imageSize,
                                                   const void* bits);
GLAPI void APIENTRY glCompressedMultiTexSubImage3DEXT(GLenum texunit,
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
GLAPI void APIENTRY glCompressedMultiTexSubImage2DEXT(GLenum texunit,
                                                      GLenum target,
                                                      GLint level,
                                                      GLint xoffset,
                                                      GLint yoffset,
                                                      GLsizei width,
                                                      GLsizei height,
                                                      GLenum format,
                                                      GLsizei imageSize,
                                                      const void* bits);
GLAPI void APIENTRY glCompressedMultiTexSubImage1DEXT(GLenum texunit,
                                                      GLenum target,
                                                      GLint level,
                                                      GLint xoffset,
                                                      GLsizei width,
                                                      GLenum format,
                                                      GLsizei imageSize,
                                                      const void* bits);
GLAPI void APIENTRY glGetCompressedMultiTexImageEXT(GLenum texunit, GLenum target, GLint lod, void* img);
GLAPI void APIENTRY glMatrixLoadTransposefEXT(GLenum mode, const GLfloat* m);
GLAPI void APIENTRY glMatrixLoadTransposedEXT(GLenum mode, const GLdouble* m);
GLAPI void APIENTRY glMatrixMultTransposefEXT(GLenum mode, const GLfloat* m);
GLAPI void APIENTRY glMatrixMultTransposedEXT(GLenum mode, const GLdouble* m);
GLAPI void APIENTRY glNamedBufferDataEXT(GLuint buffer, GLsizeiptr size, const void* data, GLenum usage);
GLAPI void APIENTRY glNamedBufferSubDataEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, const void* data);
GLAPI void* APIENTRY glMapNamedBufferEXT(GLuint buffer, GLenum access);
GLAPI GLboolean APIENTRY glUnmapNamedBufferEXT(GLuint buffer);
GLAPI void APIENTRY glGetNamedBufferParameterivEXT(GLuint buffer, GLenum pname, GLint* params);
GLAPI void APIENTRY glGetNamedBufferPointervEXT(GLuint buffer, GLenum pname, void** params);
GLAPI void APIENTRY glGetNamedBufferSubDataEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, void* data);
GLAPI void APIENTRY glProgramUniform1fEXT(GLuint program, GLint location, GLfloat v0);
GLAPI void APIENTRY glProgramUniform2fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1);
GLAPI void APIENTRY glProgramUniform3fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
GLAPI void APIENTRY
glProgramUniform4fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
GLAPI void APIENTRY glProgramUniform1iEXT(GLuint program, GLint location, GLint v0);
GLAPI void APIENTRY glProgramUniform2iEXT(GLuint program, GLint location, GLint v0, GLint v1);
GLAPI void APIENTRY glProgramUniform3iEXT(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
GLAPI void APIENTRY glProgramUniform4iEXT(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
GLAPI void APIENTRY glProgramUniform1fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat* value);
GLAPI void APIENTRY glProgramUniform2fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat* value);
GLAPI void APIENTRY glProgramUniform3fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat* value);
GLAPI void APIENTRY glProgramUniform4fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat* value);
GLAPI void APIENTRY glProgramUniform1ivEXT(GLuint program, GLint location, GLsizei count, const GLint* value);
GLAPI void APIENTRY glProgramUniform2ivEXT(GLuint program, GLint location, GLsizei count, const GLint* value);
GLAPI void APIENTRY glProgramUniform3ivEXT(GLuint program, GLint location, GLsizei count, const GLint* value);
GLAPI void APIENTRY glProgramUniform4ivEXT(GLuint program, GLint location, GLsizei count, const GLint* value);
GLAPI void APIENTRY
glProgramUniformMatrix2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void APIENTRY
glProgramUniformMatrix3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void APIENTRY
glProgramUniformMatrix4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void APIENTRY glProgramUniformMatrix2x3fvEXT(GLuint program,
                                                   GLint location,
                                                   GLsizei count,
                                                   GLboolean transpose,
                                                   const GLfloat* value);
GLAPI void APIENTRY glProgramUniformMatrix3x2fvEXT(GLuint program,
                                                   GLint location,
                                                   GLsizei count,
                                                   GLboolean transpose,
                                                   const GLfloat* value);
GLAPI void APIENTRY glProgramUniformMatrix2x4fvEXT(GLuint program,
                                                   GLint location,
                                                   GLsizei count,
                                                   GLboolean transpose,
                                                   const GLfloat* value);
GLAPI void APIENTRY glProgramUniformMatrix4x2fvEXT(GLuint program,
                                                   GLint location,
                                                   GLsizei count,
                                                   GLboolean transpose,
                                                   const GLfloat* value);
GLAPI void APIENTRY glProgramUniformMatrix3x4fvEXT(GLuint program,
                                                   GLint location,
                                                   GLsizei count,
                                                   GLboolean transpose,
                                                   const GLfloat* value);
GLAPI void APIENTRY glProgramUniformMatrix4x3fvEXT(GLuint program,
                                                   GLint location,
                                                   GLsizei count,
                                                   GLboolean transpose,
                                                   const GLfloat* value);
GLAPI void APIENTRY glTextureBufferEXT(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer);
GLAPI void APIENTRY glMultiTexBufferEXT(GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer);
GLAPI void APIENTRY glTextureParameterIivEXT(GLuint texture, GLenum target, GLenum pname, const GLint* params);
GLAPI void APIENTRY glTextureParameterIuivEXT(GLuint texture, GLenum target, GLenum pname, const GLuint* params);
GLAPI void APIENTRY glGetTextureParameterIivEXT(GLuint texture, GLenum target, GLenum pname, GLint* params);
GLAPI void APIENTRY glGetTextureParameterIuivEXT(GLuint texture, GLenum target, GLenum pname, GLuint* params);
GLAPI void APIENTRY glMultiTexParameterIivEXT(GLenum texunit, GLenum target, GLenum pname, const GLint* params);
GLAPI void APIENTRY glMultiTexParameterIuivEXT(GLenum texunit, GLenum target, GLenum pname, const GLuint* params);
GLAPI void APIENTRY glGetMultiTexParameterIivEXT(GLenum texunit, GLenum target, GLenum pname, GLint* params);
GLAPI void APIENTRY glGetMultiTexParameterIuivEXT(GLenum texunit, GLenum target, GLenum pname, GLuint* params);
GLAPI void APIENTRY glProgramUniform1uiEXT(GLuint program, GLint location, GLuint v0);
GLAPI void APIENTRY glProgramUniform2uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1);
GLAPI void APIENTRY glProgramUniform3uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
GLAPI void APIENTRY glProgramUniform4uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
GLAPI void APIENTRY glProgramUniform1uivEXT(GLuint program, GLint location, GLsizei count, const GLuint* value);
GLAPI void APIENTRY glProgramUniform2uivEXT(GLuint program, GLint location, GLsizei count, const GLuint* value);
GLAPI void APIENTRY glProgramUniform3uivEXT(GLuint program, GLint location, GLsizei count, const GLuint* value);
GLAPI void APIENTRY glProgramUniform4uivEXT(GLuint program, GLint location, GLsizei count, const GLuint* value);
GLAPI void APIENTRY
glNamedProgramLocalParameters4fvEXT(GLuint program, GLenum target, GLuint index, GLsizei count, const GLfloat* params);
GLAPI void APIENTRY
glNamedProgramLocalParameterI4iEXT(GLuint program, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
GLAPI void APIENTRY glNamedProgramLocalParameterI4ivEXT(GLuint program,
                                                        GLenum target,
                                                        GLuint index,
                                                        const GLint* params);
GLAPI void APIENTRY
glNamedProgramLocalParametersI4ivEXT(GLuint program, GLenum target, GLuint index, GLsizei count, const GLint* params);
GLAPI void APIENTRY
glNamedProgramLocalParameterI4uiEXT(GLuint program, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
GLAPI void APIENTRY glNamedProgramLocalParameterI4uivEXT(GLuint program,
                                                         GLenum target,
                                                         GLuint index,
                                                         const GLuint* params);
GLAPI void APIENTRY
glNamedProgramLocalParametersI4uivEXT(GLuint program, GLenum target, GLuint index, GLsizei count, const GLuint* params);
GLAPI void APIENTRY glGetNamedProgramLocalParameterIivEXT(GLuint program, GLenum target, GLuint index, GLint* params);
GLAPI void APIENTRY glGetNamedProgramLocalParameterIuivEXT(GLuint program, GLenum target, GLuint index, GLuint* params);
GLAPI void APIENTRY glEnableClientStateiEXT(GLenum array, GLuint index);
GLAPI void APIENTRY glDisableClientStateiEXT(GLenum array, GLuint index);
GLAPI void APIENTRY glGetFloati_vEXT(GLenum pname, GLuint index, GLfloat* params);
GLAPI void APIENTRY glGetDoublei_vEXT(GLenum pname, GLuint index, GLdouble* params);
GLAPI void APIENTRY glGetPointeri_vEXT(GLenum pname, GLuint index, void** params);
GLAPI void APIENTRY
glNamedProgramStringEXT(GLuint program, GLenum target, GLenum format, GLsizei len, const void* string);
GLAPI void APIENTRY glNamedProgramLocalParameter4dEXT(GLuint program,
                                                      GLenum target,
                                                      GLuint index,
                                                      GLdouble x,
                                                      GLdouble y,
                                                      GLdouble z,
                                                      GLdouble w);
GLAPI void APIENTRY glNamedProgramLocalParameter4dvEXT(GLuint program,
                                                       GLenum target,
                                                       GLuint index,
                                                       const GLdouble* params);
GLAPI void APIENTRY glNamedProgramLocalParameter4fEXT(GLuint program,
                                                      GLenum target,
                                                      GLuint index,
                                                      GLfloat x,
                                                      GLfloat y,
                                                      GLfloat z,
                                                      GLfloat w);
GLAPI void APIENTRY glNamedProgramLocalParameter4fvEXT(GLuint program,
                                                       GLenum target,
                                                       GLuint index,
                                                       const GLfloat* params);
GLAPI void APIENTRY glGetNamedProgramLocalParameterdvEXT(GLuint program, GLenum target, GLuint index, GLdouble* params);
GLAPI void APIENTRY glGetNamedProgramLocalParameterfvEXT(GLuint program, GLenum target, GLuint index, GLfloat* params);
GLAPI void APIENTRY glGetNamedProgramivEXT(GLuint program, GLenum target, GLenum pname, GLint* params);
GLAPI void APIENTRY glGetNamedProgramStringEXT(GLuint program, GLenum target, GLenum pname, void* string);
GLAPI void APIENTRY glNamedRenderbufferStorageEXT(GLuint renderbuffer,
                                                  GLenum internalformat,
                                                  GLsizei width,
                                                  GLsizei height);
GLAPI void APIENTRY glGetNamedRenderbufferParameterivEXT(GLuint renderbuffer, GLenum pname, GLint* params);
GLAPI void APIENTRY glNamedRenderbufferStorageMultisampleEXT(GLuint renderbuffer,
                                                             GLsizei samples,
                                                             GLenum internalformat,
                                                             GLsizei width,
                                                             GLsizei height);
GLAPI void APIENTRY glNamedRenderbufferStorageMultisampleCoverageEXT(GLuint renderbuffer,
                                                                     GLsizei coverageSamples,
                                                                     GLsizei colorSamples,
                                                                     GLenum internalformat,
                                                                     GLsizei width,
                                                                     GLsizei height);
GLAPI GLenum APIENTRY glCheckNamedFramebufferStatusEXT(GLuint framebuffer, GLenum target);
GLAPI void APIENTRY
glNamedFramebufferTexture1DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
GLAPI void APIENTRY
glNamedFramebufferTexture2DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
GLAPI void APIENTRY glNamedFramebufferTexture3DEXT(GLuint framebuffer,
                                                   GLenum attachment,
                                                   GLenum textarget,
                                                   GLuint texture,
                                                   GLint level,
                                                   GLint zoffset);
GLAPI void APIENTRY glNamedFramebufferRenderbufferEXT(GLuint framebuffer,
                                                      GLenum attachment,
                                                      GLenum renderbuffertarget,
                                                      GLuint renderbuffer);
GLAPI void APIENTRY glGetNamedFramebufferAttachmentParameterivEXT(GLuint framebuffer,
                                                                  GLenum attachment,
                                                                  GLenum pname,
                                                                  GLint* params);
GLAPI void APIENTRY glGenerateTextureMipmapEXT(GLuint texture, GLenum target);
GLAPI void APIENTRY glGenerateMultiTexMipmapEXT(GLenum texunit, GLenum target);
GLAPI void APIENTRY glFramebufferDrawBufferEXT(GLuint framebuffer, GLenum mode);
GLAPI void APIENTRY glFramebufferDrawBuffersEXT(GLuint framebuffer, GLsizei n, const GLenum* bufs);
GLAPI void APIENTRY glFramebufferReadBufferEXT(GLuint framebuffer, GLenum mode);
GLAPI void APIENTRY glGetFramebufferParameterivEXT(GLuint framebuffer, GLenum pname, GLint* params);
GLAPI void APIENTRY glNamedCopyBufferSubDataEXT(GLuint readBuffer,
                                                GLuint writeBuffer,
                                                GLintptr readOffset,
                                                GLintptr writeOffset,
                                                GLsizeiptr size);
GLAPI void APIENTRY glNamedFramebufferTextureEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
GLAPI void APIENTRY
glNamedFramebufferTextureLayerEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
GLAPI void APIENTRY
glNamedFramebufferTextureFaceEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face);
GLAPI void APIENTRY glTextureRenderbufferEXT(GLuint texture, GLenum target, GLuint renderbuffer);
GLAPI void APIENTRY glMultiTexRenderbufferEXT(GLenum texunit, GLenum target, GLuint renderbuffer);
GLAPI void APIENTRY
glVertexArrayVertexOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
GLAPI void APIENTRY
glVertexArrayColorOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
GLAPI void APIENTRY glVertexArrayEdgeFlagOffsetEXT(GLuint vaobj, GLuint buffer, GLsizei stride, GLintptr offset);
GLAPI void APIENTRY
glVertexArrayIndexOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
GLAPI void APIENTRY
glVertexArrayNormalOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
GLAPI void APIENTRY
glVertexArrayTexCoordOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
GLAPI void APIENTRY glVertexArrayMultiTexCoordOffsetEXT(GLuint vaobj,
                                                        GLuint buffer,
                                                        GLenum texunit,
                                                        GLint size,
                                                        GLenum type,
                                                        GLsizei stride,
                                                        GLintptr offset);
GLAPI void APIENTRY
glVertexArrayFogCoordOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
GLAPI void APIENTRY glVertexArraySecondaryColorOffsetEXT(GLuint vaobj,
                                                         GLuint buffer,
                                                         GLint size,
                                                         GLenum type,
                                                         GLsizei stride,
                                                         GLintptr offset);
GLAPI void APIENTRY glVertexArrayVertexAttribOffsetEXT(GLuint vaobj,
                                                       GLuint buffer,
                                                       GLuint index,
                                                       GLint size,
                                                       GLenum type,
                                                       GLboolean normalized,
                                                       GLsizei stride,
                                                       GLintptr offset);
GLAPI void APIENTRY glVertexArrayVertexAttribIOffsetEXT(GLuint vaobj,
                                                        GLuint buffer,
                                                        GLuint index,
                                                        GLint size,
                                                        GLenum type,
                                                        GLsizei stride,
                                                        GLintptr offset);
GLAPI void APIENTRY glEnableVertexArrayEXT(GLuint vaobj, GLenum array);
GLAPI void APIENTRY glDisableVertexArrayEXT(GLuint vaobj, GLenum array);
GLAPI void APIENTRY glEnableVertexArrayAttribEXT(GLuint vaobj, GLuint index);
GLAPI void APIENTRY glDisableVertexArrayAttribEXT(GLuint vaobj, GLuint index);
GLAPI void APIENTRY glGetVertexArrayIntegervEXT(GLuint vaobj, GLenum pname, GLint* param);
GLAPI void APIENTRY glGetVertexArrayPointervEXT(GLuint vaobj, GLenum pname, void** param);
GLAPI void APIENTRY glGetVertexArrayIntegeri_vEXT(GLuint vaobj, GLuint index, GLenum pname, GLint* param);
GLAPI void APIENTRY glGetVertexArrayPointeri_vEXT(GLuint vaobj, GLuint index, GLenum pname, void** param);
GLAPI void* APIENTRY glMapNamedBufferRangeEXT(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
GLAPI void APIENTRY glFlushMappedNamedBufferRangeEXT(GLuint buffer, GLintptr offset, GLsizeiptr length);
GLAPI void APIENTRY glNamedBufferStorageEXT(GLuint buffer, GLsizeiptr size, const void* data, GLbitfield flags);
GLAPI void APIENTRY
glClearNamedBufferDataEXT(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void* data);
GLAPI void APIENTRY glClearNamedBufferSubDataEXT(GLuint buffer,
                                                 GLenum internalformat,
                                                 GLsizeiptr offset,
                                                 GLsizeiptr size,
                                                 GLenum format,
                                                 GLenum type,
                                                 const void* data);
GLAPI void APIENTRY glNamedFramebufferParameteriEXT(GLuint framebuffer, GLenum pname, GLint param);
GLAPI void APIENTRY glGetNamedFramebufferParameterivEXT(GLuint framebuffer, GLenum pname, GLint* params);
GLAPI void APIENTRY glProgramUniform1dEXT(GLuint program, GLint location, GLdouble x);
GLAPI void APIENTRY glProgramUniform2dEXT(GLuint program, GLint location, GLdouble x, GLdouble y);
GLAPI void APIENTRY glProgramUniform3dEXT(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z);
GLAPI void APIENTRY
glProgramUniform4dEXT(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void APIENTRY glProgramUniform1dvEXT(GLuint program, GLint location, GLsizei count, const GLdouble* value);
GLAPI void APIENTRY glProgramUniform2dvEXT(GLuint program, GLint location, GLsizei count, const GLdouble* value);
GLAPI void APIENTRY glProgramUniform3dvEXT(GLuint program, GLint location, GLsizei count, const GLdouble* value);
GLAPI void APIENTRY glProgramUniform4dvEXT(GLuint program, GLint location, GLsizei count, const GLdouble* value);
GLAPI void APIENTRY
glProgramUniformMatrix2dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void APIENTRY
glProgramUniformMatrix3dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void APIENTRY
glProgramUniformMatrix4dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void APIENTRY glProgramUniformMatrix2x3dvEXT(GLuint program,
                                                   GLint location,
                                                   GLsizei count,
                                                   GLboolean transpose,
                                                   const GLdouble* value);
GLAPI void APIENTRY glProgramUniformMatrix2x4dvEXT(GLuint program,
                                                   GLint location,
                                                   GLsizei count,
                                                   GLboolean transpose,
                                                   const GLdouble* value);
GLAPI void APIENTRY glProgramUniformMatrix3x2dvEXT(GLuint program,
                                                   GLint location,
                                                   GLsizei count,
                                                   GLboolean transpose,
                                                   const GLdouble* value);
GLAPI void APIENTRY glProgramUniformMatrix3x4dvEXT(GLuint program,
                                                   GLint location,
                                                   GLsizei count,
                                                   GLboolean transpose,
                                                   const GLdouble* value);
GLAPI void APIENTRY glProgramUniformMatrix4x2dvEXT(GLuint program,
                                                   GLint location,
                                                   GLsizei count,
                                                   GLboolean transpose,
                                                   const GLdouble* value);
GLAPI void APIENTRY glProgramUniformMatrix4x3dvEXT(GLuint program,
                                                   GLint location,
                                                   GLsizei count,
                                                   GLboolean transpose,
                                                   const GLdouble* value);
GLAPI void APIENTRY glTextureBufferRangeEXT(GLuint texture,
                                            GLenum target,
                                            GLenum internalformat,
                                            GLuint buffer,
                                            GLintptr offset,
                                            GLsizeiptr size);
GLAPI void APIENTRY
glTextureStorage1DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
GLAPI void APIENTRY glTextureStorage2DEXT(GLuint texture,
                                          GLenum target,
                                          GLsizei levels,
                                          GLenum internalformat,
                                          GLsizei width,
                                          GLsizei height);
GLAPI void APIENTRY glTextureStorage3DEXT(GLuint texture,
                                          GLenum target,
                                          GLsizei levels,
                                          GLenum internalformat,
                                          GLsizei width,
                                          GLsizei height,
                                          GLsizei depth);
GLAPI void APIENTRY glTextureStorage2DMultisampleEXT(GLuint texture,
                                                     GLenum target,
                                                     GLsizei samples,
                                                     GLenum internalformat,
                                                     GLsizei width,
                                                     GLsizei height,
                                                     GLboolean fixedsamplelocations);
GLAPI void APIENTRY glTextureStorage3DMultisampleEXT(GLuint texture,
                                                     GLenum target,
                                                     GLsizei samples,
                                                     GLenum internalformat,
                                                     GLsizei width,
                                                     GLsizei height,
                                                     GLsizei depth,
                                                     GLboolean fixedsamplelocations);
GLAPI void APIENTRY
glVertexArrayBindVertexBufferEXT(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
GLAPI void APIENTRY glVertexArrayVertexAttribFormatEXT(GLuint vaobj,
                                                       GLuint attribindex,
                                                       GLint size,
                                                       GLenum type,
                                                       GLboolean normalized,
                                                       GLuint relativeoffset);
GLAPI void APIENTRY
glVertexArrayVertexAttribIFormatEXT(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLAPI void APIENTRY
glVertexArrayVertexAttribLFormatEXT(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLAPI void APIENTRY glVertexArrayVertexAttribBindingEXT(GLuint vaobj, GLuint attribindex, GLuint bindingindex);
GLAPI void APIENTRY glVertexArrayVertexBindingDivisorEXT(GLuint vaobj, GLuint bindingindex, GLuint divisor);
GLAPI void APIENTRY glVertexArrayVertexAttribLOffsetEXT(GLuint vaobj,
                                                        GLuint buffer,
                                                        GLuint index,
                                                        GLint size,
                                                        GLenum type,
                                                        GLsizei stride,
                                                        GLintptr offset);
GLAPI void APIENTRY glTexturePageCommitmentEXT(GLuint texture,
                                               GLint level,
                                               GLint xoffset,
                                               GLint yoffset,
                                               GLint zoffset,
                                               GLsizei width,
                                               GLsizei height,
                                               GLsizei depth,
                                               GLboolean commit);
GLAPI void APIENTRY glVertexArrayVertexAttribDivisorEXT(GLuint vaobj, GLuint index, GLuint divisor);
#endif
#endif /* GL_EXT_direct_state_access */

#ifndef GL_EXT_draw_instanced
#define GL_EXT_draw_instanced 1
typedef void(APIENTRYP PFNGLDRAWARRAYSINSTANCEDEXTPROC)(GLenum mode, GLint start, GLsizei count, GLsizei primcount);
typedef void(APIENTRYP PFNGLDRAWELEMENTSINSTANCEDEXTPROC)(GLenum mode,
                                                          GLsizei count,
                                                          GLenum type,
                                                          const void* indices,
                                                          GLsizei primcount);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glDrawArraysInstancedEXT(GLenum mode, GLint start, GLsizei count, GLsizei primcount);
GLAPI void APIENTRY
glDrawElementsInstancedEXT(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei primcount);
#endif
#endif /* GL_EXT_draw_instanced */

#ifndef GL_EXT_polygon_offset_clamp
#define GL_EXT_polygon_offset_clamp 1
#define GL_POLYGON_OFFSET_CLAMP_EXT 0x8E1B
typedef void(APIENTRYP PFNGLPOLYGONOFFSETCLAMPEXTPROC)(GLfloat factor, GLfloat units, GLfloat clamp);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glPolygonOffsetClampEXT(GLfloat factor, GLfloat units, GLfloat clamp);
#endif
#endif /* GL_EXT_polygon_offset_clamp */

#ifndef GL_EXT_post_depth_coverage
#define GL_EXT_post_depth_coverage 1
#endif /* GL_EXT_post_depth_coverage */

#ifndef GL_EXT_raster_multisample
#define GL_EXT_raster_multisample 1
#define GL_RASTER_MULTISAMPLE_EXT 0x9327
#define GL_RASTER_SAMPLES_EXT 0x9328
#define GL_MAX_RASTER_SAMPLES_EXT 0x9329
#define GL_RASTER_FIXED_SAMPLE_LOCATIONS_EXT 0x932A
#define GL_MULTISAMPLE_RASTERIZATION_ALLOWED_EXT 0x932B
#define GL_EFFECTIVE_RASTER_SAMPLES_EXT 0x932C
typedef void(APIENTRYP PFNGLRASTERSAMPLESEXTPROC)(GLuint samples, GLboolean fixedsamplelocations);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glRasterSamplesEXT(GLuint samples, GLboolean fixedsamplelocations);
#endif
#endif /* GL_EXT_raster_multisample */

#ifndef GL_EXT_separate_shader_objects
#define GL_EXT_separate_shader_objects 1
#define GL_ACTIVE_PROGRAM_EXT 0x8B8D
typedef void(APIENTRYP PFNGLUSESHADERPROGRAMEXTPROC)(GLenum type, GLuint program);
typedef void(APIENTRYP PFNGLACTIVEPROGRAMEXTPROC)(GLuint program);
typedef GLuint(APIENTRYP PFNGLCREATESHADERPROGRAMEXTPROC)(GLenum type, const GLchar* string);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glUseShaderProgramEXT(GLenum type, GLuint program);
GLAPI void APIENTRY glActiveProgramEXT(GLuint program);
GLAPI GLuint APIENTRY glCreateShaderProgramEXT(GLenum type, const GLchar* string);
#endif
#endif /* GL_EXT_separate_shader_objects */

#ifndef GL_EXT_shader_integer_mix
#define GL_EXT_shader_integer_mix 1
#endif /* GL_EXT_shader_integer_mix */

#ifndef GL_EXT_texture_compression_s3tc
#define GL_EXT_texture_compression_s3tc 1
#define GL_COMPRESSED_RGB_S3TC_DXT1_EXT 0x83F0
#define GL_COMPRESSED_RGBA_S3TC_DXT1_EXT 0x83F1
#define GL_COMPRESSED_RGBA_S3TC_DXT3_EXT 0x83F2
#define GL_COMPRESSED_RGBA_S3TC_DXT5_EXT 0x83F3
#endif /* GL_EXT_texture_compression_s3tc */

#ifndef GL_EXT_texture_filter_minmax
#define GL_EXT_texture_filter_minmax 1
#endif /* GL_EXT_texture_filter_minmax */

#ifndef GL_EXT_texture_sRGB_decode
#define GL_EXT_texture_sRGB_decode 1
#define GL_TEXTURE_SRGB_DECODE_EXT 0x8A48
#define GL_DECODE_EXT 0x8A49
#define GL_SKIP_DECODE_EXT 0x8A4A
#endif /* GL_EXT_texture_sRGB_decode */

#ifndef GL_EXT_window_rectangles
#define GL_EXT_window_rectangles 1
#define GL_INCLUSIVE_EXT 0x8F10
#define GL_EXCLUSIVE_EXT 0x8F11
#define GL_WINDOW_RECTANGLE_EXT 0x8F12
#define GL_WINDOW_RECTANGLE_MODE_EXT 0x8F13
#define GL_MAX_WINDOW_RECTANGLES_EXT 0x8F14
#define GL_NUM_WINDOW_RECTANGLES_EXT 0x8F15
typedef void(APIENTRYP PFNGLWINDOWRECTANGLESEXTPROC)(GLenum mode, GLsizei count, const GLint* box);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glWindowRectanglesEXT(GLenum mode, GLsizei count, const GLint* box);
#endif
#endif /* GL_EXT_window_rectangles */

#ifndef GL_INTEL_conservative_rasterization
#define GL_INTEL_conservative_rasterization 1
#define GL_CONSERVATIVE_RASTERIZATION_INTEL 0x83FE
#endif /* GL_INTEL_conservative_rasterization */

#ifndef GL_INTEL_framebuffer_CMAA
#define GL_INTEL_framebuffer_CMAA 1
typedef void(APIENTRYP PFNGLAPPLYFRAMEBUFFERATTACHMENTCMAAINTELPROC)(void);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glApplyFramebufferAttachmentCMAAINTEL(void);
#endif
#endif /* GL_INTEL_framebuffer_CMAA */

#ifndef GL_INTEL_performance_query
#define GL_INTEL_performance_query 1
#define GL_PERFQUERY_SINGLE_CONTEXT_INTEL 0x00000000
#define GL_PERFQUERY_GLOBAL_CONTEXT_INTEL 0x00000001
#define GL_PERFQUERY_WAIT_INTEL 0x83FB
#define GL_PERFQUERY_FLUSH_INTEL 0x83FA
#define GL_PERFQUERY_DONOT_FLUSH_INTEL 0x83F9
#define GL_PERFQUERY_COUNTER_EVENT_INTEL 0x94F0
#define GL_PERFQUERY_COUNTER_DURATION_NORM_INTEL 0x94F1
#define GL_PERFQUERY_COUNTER_DURATION_RAW_INTEL 0x94F2
#define GL_PERFQUERY_COUNTER_THROUGHPUT_INTEL 0x94F3
#define GL_PERFQUERY_COUNTER_RAW_INTEL 0x94F4
#define GL_PERFQUERY_COUNTER_TIMESTAMP_INTEL 0x94F5
#define GL_PERFQUERY_COUNTER_DATA_UINT32_INTEL 0x94F8
#define GL_PERFQUERY_COUNTER_DATA_UINT64_INTEL 0x94F9
#define GL_PERFQUERY_COUNTER_DATA_FLOAT_INTEL 0x94FA
#define GL_PERFQUERY_COUNTER_DATA_DOUBLE_INTEL 0x94FB
#define GL_PERFQUERY_COUNTER_DATA_BOOL32_INTEL 0x94FC
#define GL_PERFQUERY_QUERY_NAME_LENGTH_MAX_INTEL 0x94FD
#define GL_PERFQUERY_COUNTER_NAME_LENGTH_MAX_INTEL 0x94FE
#define GL_PERFQUERY_COUNTER_DESC_LENGTH_MAX_INTEL 0x94FF
#define GL_PERFQUERY_GPA_EXTENDED_COUNTERS_INTEL 0x9500
typedef void(APIENTRYP PFNGLBEGINPERFQUERYINTELPROC)(GLuint queryHandle);
typedef void(APIENTRYP PFNGLCREATEPERFQUERYINTELPROC)(GLuint queryId, GLuint* queryHandle);
typedef void(APIENTRYP PFNGLDELETEPERFQUERYINTELPROC)(GLuint queryHandle);
typedef void(APIENTRYP PFNGLENDPERFQUERYINTELPROC)(GLuint queryHandle);
typedef void(APIENTRYP PFNGLGETFIRSTPERFQUERYIDINTELPROC)(GLuint* queryId);
typedef void(APIENTRYP PFNGLGETNEXTPERFQUERYIDINTELPROC)(GLuint queryId, GLuint* nextQueryId);
typedef void(APIENTRYP PFNGLGETPERFCOUNTERINFOINTELPROC)(GLuint queryId,
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
typedef void(APIENTRYP PFNGLGETPERFQUERYDATAINTELPROC)(GLuint queryHandle,
                                                       GLuint flags,
                                                       GLsizei dataSize,
                                                       GLvoid* data,
                                                       GLuint* bytesWritten);
typedef void(APIENTRYP PFNGLGETPERFQUERYIDBYNAMEINTELPROC)(GLchar* queryName, GLuint* queryId);
typedef void(APIENTRYP PFNGLGETPERFQUERYINFOINTELPROC)(GLuint queryId,
                                                       GLuint queryNameLength,
                                                       GLchar* queryName,
                                                       GLuint* dataSize,
                                                       GLuint* noCounters,
                                                       GLuint* noInstances,
                                                       GLuint* capsMask);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glBeginPerfQueryINTEL(GLuint queryHandle);
GLAPI void APIENTRY glCreatePerfQueryINTEL(GLuint queryId, GLuint* queryHandle);
GLAPI void APIENTRY glDeletePerfQueryINTEL(GLuint queryHandle);
GLAPI void APIENTRY glEndPerfQueryINTEL(GLuint queryHandle);
GLAPI void APIENTRY glGetFirstPerfQueryIdINTEL(GLuint* queryId);
GLAPI void APIENTRY glGetNextPerfQueryIdINTEL(GLuint queryId, GLuint* nextQueryId);
GLAPI void APIENTRY glGetPerfCounterInfoINTEL(GLuint queryId,
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
GLAPI void APIENTRY
glGetPerfQueryDataINTEL(GLuint queryHandle, GLuint flags, GLsizei dataSize, GLvoid* data, GLuint* bytesWritten);
GLAPI void APIENTRY glGetPerfQueryIdByNameINTEL(GLchar* queryName, GLuint* queryId);
GLAPI void APIENTRY glGetPerfQueryInfoINTEL(GLuint queryId,
                                            GLuint queryNameLength,
                                            GLchar* queryName,
                                            GLuint* dataSize,
                                            GLuint* noCounters,
                                            GLuint* noInstances,
                                            GLuint* capsMask);
#endif
#endif /* GL_INTEL_performance_query */

#ifndef GL_NV_bindless_multi_draw_indirect
#define GL_NV_bindless_multi_draw_indirect 1
typedef void(APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSNVPROC)(GLenum mode,
                                                                   const void* indirect,
                                                                   GLsizei drawCount,
                                                                   GLsizei stride,
                                                                   GLint vertexBufferCount);
typedef void(APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSNVPROC)(GLenum mode,
                                                                     GLenum type,
                                                                     const void* indirect,
                                                                     GLsizei drawCount,
                                                                     GLsizei stride,
                                                                     GLint vertexBufferCount);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glMultiDrawArraysIndirectBindlessNV(GLenum mode,
                                                        const void* indirect,
                                                        GLsizei drawCount,
                                                        GLsizei stride,
                                                        GLint vertexBufferCount);
GLAPI void APIENTRY glMultiDrawElementsIndirectBindlessNV(GLenum mode,
                                                          GLenum type,
                                                          const void* indirect,
                                                          GLsizei drawCount,
                                                          GLsizei stride,
                                                          GLint vertexBufferCount);
#endif
#endif /* GL_NV_bindless_multi_draw_indirect */

#ifndef GL_NV_bindless_multi_draw_indirect_count
#define GL_NV_bindless_multi_draw_indirect_count 1
typedef void(APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSCOUNTNVPROC)(GLenum mode,
                                                                        const void* indirect,
                                                                        GLsizei drawCount,
                                                                        GLsizei maxDrawCount,
                                                                        GLsizei stride,
                                                                        GLint vertexBufferCount);
typedef void(APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSCOUNTNVPROC)(GLenum mode,
                                                                          GLenum type,
                                                                          const void* indirect,
                                                                          GLsizei drawCount,
                                                                          GLsizei maxDrawCount,
                                                                          GLsizei stride,
                                                                          GLint vertexBufferCount);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glMultiDrawArraysIndirectBindlessCountNV(GLenum mode,
                                                             const void* indirect,
                                                             GLsizei drawCount,
                                                             GLsizei maxDrawCount,
                                                             GLsizei stride,
                                                             GLint vertexBufferCount);
GLAPI void APIENTRY glMultiDrawElementsIndirectBindlessCountNV(GLenum mode,
                                                               GLenum type,
                                                               const void* indirect,
                                                               GLsizei drawCount,
                                                               GLsizei maxDrawCount,
                                                               GLsizei stride,
                                                               GLint vertexBufferCount);
#endif
#endif /* GL_NV_bindless_multi_draw_indirect_count */

#ifndef GL_NV_bindless_texture
#define GL_NV_bindless_texture 1
typedef GLuint64(APIENTRYP PFNGLGETTEXTUREHANDLENVPROC)(GLuint texture);
typedef GLuint64(APIENTRYP PFNGLGETTEXTURESAMPLERHANDLENVPROC)(GLuint texture, GLuint sampler);
typedef void(APIENTRYP PFNGLMAKETEXTUREHANDLERESIDENTNVPROC)(GLuint64 handle);
typedef void(APIENTRYP PFNGLMAKETEXTUREHANDLENONRESIDENTNVPROC)(GLuint64 handle);
typedef GLuint64(
APIENTRYP PFNGLGETIMAGEHANDLENVPROC)(GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
typedef void(APIENTRYP PFNGLMAKEIMAGEHANDLERESIDENTNVPROC)(GLuint64 handle, GLenum access);
typedef void(APIENTRYP PFNGLMAKEIMAGEHANDLENONRESIDENTNVPROC)(GLuint64 handle);
typedef void(APIENTRYP PFNGLUNIFORMHANDLEUI64NVPROC)(GLint location, GLuint64 value);
typedef void(APIENTRYP PFNGLUNIFORMHANDLEUI64VNVPROC)(GLint location, GLsizei count, const GLuint64* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORMHANDLEUI64NVPROC)(GLuint program, GLint location, GLuint64 value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORMHANDLEUI64VNVPROC)(GLuint program,
                                                             GLint location,
                                                             GLsizei count,
                                                             const GLuint64* values);
typedef GLboolean(APIENTRYP PFNGLISTEXTUREHANDLERESIDENTNVPROC)(GLuint64 handle);
typedef GLboolean(APIENTRYP PFNGLISIMAGEHANDLERESIDENTNVPROC)(GLuint64 handle);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI GLuint64 APIENTRY glGetTextureHandleNV(GLuint texture);
GLAPI GLuint64 APIENTRY glGetTextureSamplerHandleNV(GLuint texture, GLuint sampler);
GLAPI void APIENTRY glMakeTextureHandleResidentNV(GLuint64 handle);
GLAPI void APIENTRY glMakeTextureHandleNonResidentNV(GLuint64 handle);
GLAPI GLuint64 APIENTRY glGetImageHandleNV(GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
GLAPI void APIENTRY glMakeImageHandleResidentNV(GLuint64 handle, GLenum access);
GLAPI void APIENTRY glMakeImageHandleNonResidentNV(GLuint64 handle);
GLAPI void APIENTRY glUniformHandleui64NV(GLint location, GLuint64 value);
GLAPI void APIENTRY glUniformHandleui64vNV(GLint location, GLsizei count, const GLuint64* value);
GLAPI void APIENTRY glProgramUniformHandleui64NV(GLuint program, GLint location, GLuint64 value);
GLAPI void APIENTRY glProgramUniformHandleui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64* values);
GLAPI GLboolean APIENTRY glIsTextureHandleResidentNV(GLuint64 handle);
GLAPI GLboolean APIENTRY glIsImageHandleResidentNV(GLuint64 handle);
#endif
#endif /* GL_NV_bindless_texture */

#ifndef GL_NV_blend_equation_advanced
#define GL_NV_blend_equation_advanced 1
#define GL_BLEND_OVERLAP_NV 0x9281
#define GL_BLEND_PREMULTIPLIED_SRC_NV 0x9280
#define GL_BLUE_NV 0x1905
#define GL_COLORBURN_NV 0x929A
#define GL_COLORDODGE_NV 0x9299
#define GL_CONJOINT_NV 0x9284
#define GL_CONTRAST_NV 0x92A1
#define GL_DARKEN_NV 0x9297
#define GL_DIFFERENCE_NV 0x929E
#define GL_DISJOINT_NV 0x9283
#define GL_DST_ATOP_NV 0x928F
#define GL_DST_IN_NV 0x928B
#define GL_DST_NV 0x9287
#define GL_DST_OUT_NV 0x928D
#define GL_DST_OVER_NV 0x9289
#define GL_EXCLUSION_NV 0x92A0
#define GL_GREEN_NV 0x1904
#define GL_HARDLIGHT_NV 0x929B
#define GL_HARDMIX_NV 0x92A9
#define GL_HSL_COLOR_NV 0x92AF
#define GL_HSL_HUE_NV 0x92AD
#define GL_HSL_LUMINOSITY_NV 0x92B0
#define GL_HSL_SATURATION_NV 0x92AE
#define GL_INVERT_OVG_NV 0x92B4
#define GL_INVERT_RGB_NV 0x92A3
#define GL_LIGHTEN_NV 0x9298
#define GL_LINEARBURN_NV 0x92A5
#define GL_LINEARDODGE_NV 0x92A4
#define GL_LINEARLIGHT_NV 0x92A7
#define GL_MINUS_CLAMPED_NV 0x92B3
#define GL_MINUS_NV 0x929F
#define GL_MULTIPLY_NV 0x9294
#define GL_OVERLAY_NV 0x9296
#define GL_PINLIGHT_NV 0x92A8
#define GL_PLUS_CLAMPED_ALPHA_NV 0x92B2
#define GL_PLUS_CLAMPED_NV 0x92B1
#define GL_PLUS_DARKER_NV 0x9292
#define GL_PLUS_NV 0x9291
#define GL_RED_NV 0x1903
#define GL_SCREEN_NV 0x9295
#define GL_SOFTLIGHT_NV 0x929C
#define GL_SRC_ATOP_NV 0x928E
#define GL_SRC_IN_NV 0x928A
#define GL_SRC_NV 0x9286
#define GL_SRC_OUT_NV 0x928C
#define GL_SRC_OVER_NV 0x9288
#define GL_UNCORRELATED_NV 0x9282
#define GL_VIVIDLIGHT_NV 0x92A6
#define GL_XOR_NV 0x1506
typedef void(APIENTRYP PFNGLBLENDPARAMETERINVPROC)(GLenum pname, GLint value);
typedef void(APIENTRYP PFNGLBLENDBARRIERNVPROC)(void);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glBlendParameteriNV(GLenum pname, GLint value);
GLAPI void APIENTRY glBlendBarrierNV(void);
#endif
#endif /* GL_NV_blend_equation_advanced */

#ifndef GL_NV_blend_equation_advanced_coherent
#define GL_NV_blend_equation_advanced_coherent 1
#define GL_BLEND_ADVANCED_COHERENT_NV 0x9285
#endif /* GL_NV_blend_equation_advanced_coherent */

#ifndef GL_NV_blend_minmax_factor
#define GL_NV_blend_minmax_factor 1
#define GL_FACTOR_MIN_AMD 0x901C
#define GL_FACTOR_MAX_AMD 0x901D
#endif /* GL_NV_blend_minmax_factor */

#ifndef GL_NV_clip_space_w_scaling
#define GL_NV_clip_space_w_scaling 1
#define GL_VIEWPORT_POSITION_W_SCALE_NV 0x937C
#define GL_VIEWPORT_POSITION_W_SCALE_X_COEFF_NV 0x937D
#define GL_VIEWPORT_POSITION_W_SCALE_Y_COEFF_NV 0x937E
typedef void(APIENTRYP PFNGLVIEWPORTPOSITIONWSCALENVPROC)(GLuint index, GLfloat xcoeff, GLfloat ycoeff);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glViewportPositionWScaleNV(GLuint index, GLfloat xcoeff, GLfloat ycoeff);
#endif
#endif /* GL_NV_clip_space_w_scaling */

#ifndef GL_NV_command_list
#define GL_NV_command_list 1
#define GL_TERMINATE_SEQUENCE_COMMAND_NV 0x0000
#define GL_NOP_COMMAND_NV 0x0001
#define GL_DRAW_ELEMENTS_COMMAND_NV 0x0002
#define GL_DRAW_ARRAYS_COMMAND_NV 0x0003
#define GL_DRAW_ELEMENTS_STRIP_COMMAND_NV 0x0004
#define GL_DRAW_ARRAYS_STRIP_COMMAND_NV 0x0005
#define GL_DRAW_ELEMENTS_INSTANCED_COMMAND_NV 0x0006
#define GL_DRAW_ARRAYS_INSTANCED_COMMAND_NV 0x0007
#define GL_ELEMENT_ADDRESS_COMMAND_NV 0x0008
#define GL_ATTRIBUTE_ADDRESS_COMMAND_NV 0x0009
#define GL_UNIFORM_ADDRESS_COMMAND_NV 0x000A
#define GL_BLEND_COLOR_COMMAND_NV 0x000B
#define GL_STENCIL_REF_COMMAND_NV 0x000C
#define GL_LINE_WIDTH_COMMAND_NV 0x000D
#define GL_POLYGON_OFFSET_COMMAND_NV 0x000E
#define GL_ALPHA_REF_COMMAND_NV 0x000F
#define GL_VIEWPORT_COMMAND_NV 0x0010
#define GL_SCISSOR_COMMAND_NV 0x0011
#define GL_FRONT_FACE_COMMAND_NV 0x0012
typedef void(APIENTRYP PFNGLCREATESTATESNVPROC)(GLsizei n, GLuint* states);
typedef void(APIENTRYP PFNGLDELETESTATESNVPROC)(GLsizei n, const GLuint* states);
typedef GLboolean(APIENTRYP PFNGLISSTATENVPROC)(GLuint state);
typedef void(APIENTRYP PFNGLSTATECAPTURENVPROC)(GLuint state, GLenum mode);
typedef GLuint(APIENTRYP PFNGLGETCOMMANDHEADERNVPROC)(GLenum tokenID, GLuint size);
typedef GLushort(APIENTRYP PFNGLGETSTAGEINDEXNVPROC)(GLenum shadertype);
typedef void(APIENTRYP PFNGLDRAWCOMMANDSNVPROC)(GLenum primitiveMode,
                                                GLuint buffer,
                                                const GLintptr* indirects,
                                                const GLsizei* sizes,
                                                GLuint count);
typedef void(APIENTRYP PFNGLDRAWCOMMANDSADDRESSNVPROC)(GLenum primitiveMode,
                                                       const GLuint64* indirects,
                                                       const GLsizei* sizes,
                                                       GLuint count);
typedef void(APIENTRYP PFNGLDRAWCOMMANDSSTATESNVPROC)(GLuint buffer,
                                                      const GLintptr* indirects,
                                                      const GLsizei* sizes,
                                                      const GLuint* states,
                                                      const GLuint* fbos,
                                                      GLuint count);
typedef void(APIENTRYP PFNGLDRAWCOMMANDSSTATESADDRESSNVPROC)(const GLuint64* indirects,
                                                             const GLsizei* sizes,
                                                             const GLuint* states,
                                                             const GLuint* fbos,
                                                             GLuint count);
typedef void(APIENTRYP PFNGLCREATECOMMANDLISTSNVPROC)(GLsizei n, GLuint* lists);
typedef void(APIENTRYP PFNGLDELETECOMMANDLISTSNVPROC)(GLsizei n, const GLuint* lists);
typedef GLboolean(APIENTRYP PFNGLISCOMMANDLISTNVPROC)(GLuint list);
typedef void(APIENTRYP PFNGLLISTDRAWCOMMANDSSTATESCLIENTNVPROC)(GLuint list,
                                                                GLuint segment,
                                                                const void** indirects,
                                                                const GLsizei* sizes,
                                                                const GLuint* states,
                                                                const GLuint* fbos,
                                                                GLuint count);
typedef void(APIENTRYP PFNGLCOMMANDLISTSEGMENTSNVPROC)(GLuint list, GLuint segments);
typedef void(APIENTRYP PFNGLCOMPILECOMMANDLISTNVPROC)(GLuint list);
typedef void(APIENTRYP PFNGLCALLCOMMANDLISTNVPROC)(GLuint list);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glCreateStatesNV(GLsizei n, GLuint* states);
GLAPI void APIENTRY glDeleteStatesNV(GLsizei n, const GLuint* states);
GLAPI GLboolean APIENTRY glIsStateNV(GLuint state);
GLAPI void APIENTRY glStateCaptureNV(GLuint state, GLenum mode);
GLAPI GLuint APIENTRY glGetCommandHeaderNV(GLenum tokenID, GLuint size);
GLAPI GLushort APIENTRY glGetStageIndexNV(GLenum shadertype);
GLAPI void APIENTRY
glDrawCommandsNV(GLenum primitiveMode, GLuint buffer, const GLintptr* indirects, const GLsizei* sizes, GLuint count);
GLAPI void APIENTRY glDrawCommandsAddressNV(GLenum primitiveMode,
                                            const GLuint64* indirects,
                                            const GLsizei* sizes,
                                            GLuint count);
GLAPI void APIENTRY glDrawCommandsStatesNV(GLuint buffer,
                                           const GLintptr* indirects,
                                           const GLsizei* sizes,
                                           const GLuint* states,
                                           const GLuint* fbos,
                                           GLuint count);
GLAPI void APIENTRY glDrawCommandsStatesAddressNV(const GLuint64* indirects,
                                                  const GLsizei* sizes,
                                                  const GLuint* states,
                                                  const GLuint* fbos,
                                                  GLuint count);
GLAPI void APIENTRY glCreateCommandListsNV(GLsizei n, GLuint* lists);
GLAPI void APIENTRY glDeleteCommandListsNV(GLsizei n, const GLuint* lists);
GLAPI GLboolean APIENTRY glIsCommandListNV(GLuint list);
GLAPI void APIENTRY glListDrawCommandsStatesClientNV(GLuint list,
                                                     GLuint segment,
                                                     const void** indirects,
                                                     const GLsizei* sizes,
                                                     const GLuint* states,
                                                     const GLuint* fbos,
                                                     GLuint count);
GLAPI void APIENTRY glCommandListSegmentsNV(GLuint list, GLuint segments);
GLAPI void APIENTRY glCompileCommandListNV(GLuint list);
GLAPI void APIENTRY glCallCommandListNV(GLuint list);
#endif
#endif /* GL_NV_command_list */

#ifndef GL_NV_conditional_render
#define GL_NV_conditional_render 1
#define GL_QUERY_WAIT_NV 0x8E13
#define GL_QUERY_NO_WAIT_NV 0x8E14
#define GL_QUERY_BY_REGION_WAIT_NV 0x8E15
#define GL_QUERY_BY_REGION_NO_WAIT_NV 0x8E16
typedef void(APIENTRYP PFNGLBEGINCONDITIONALRENDERNVPROC)(GLuint id, GLenum mode);
typedef void(APIENTRYP PFNGLENDCONDITIONALRENDERNVPROC)(void);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glBeginConditionalRenderNV(GLuint id, GLenum mode);
GLAPI void APIENTRY glEndConditionalRenderNV(void);
#endif
#endif /* GL_NV_conditional_render */

#ifndef GL_NV_conservative_raster
#define GL_NV_conservative_raster 1
#define GL_CONSERVATIVE_RASTERIZATION_NV 0x9346
#define GL_SUBPIXEL_PRECISION_BIAS_X_BITS_NV 0x9347
#define GL_SUBPIXEL_PRECISION_BIAS_Y_BITS_NV 0x9348
#define GL_MAX_SUBPIXEL_PRECISION_BIAS_BITS_NV 0x9349
typedef void(APIENTRYP PFNGLSUBPIXELPRECISIONBIASNVPROC)(GLuint xbits, GLuint ybits);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glSubpixelPrecisionBiasNV(GLuint xbits, GLuint ybits);
#endif
#endif /* GL_NV_conservative_raster */

#ifndef GL_NV_conservative_raster_dilate
#define GL_NV_conservative_raster_dilate 1
#define GL_CONSERVATIVE_RASTER_DILATE_NV 0x9379
#define GL_CONSERVATIVE_RASTER_DILATE_RANGE_NV 0x937A
#define GL_CONSERVATIVE_RASTER_DILATE_GRANULARITY_NV 0x937B
typedef void(APIENTRYP PFNGLCONSERVATIVERASTERPARAMETERFNVPROC)(GLenum pname, GLfloat value);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glConservativeRasterParameterfNV(GLenum pname, GLfloat value);
#endif
#endif /* GL_NV_conservative_raster_dilate */

#ifndef GL_NV_conservative_raster_pre_snap_triangles
#define GL_NV_conservative_raster_pre_snap_triangles 1
#define GL_CONSERVATIVE_RASTER_MODE_NV 0x954D
#define GL_CONSERVATIVE_RASTER_MODE_POST_SNAP_NV 0x954E
#define GL_CONSERVATIVE_RASTER_MODE_PRE_SNAP_TRIANGLES_NV 0x954F
typedef void(APIENTRYP PFNGLCONSERVATIVERASTERPARAMETERINVPROC)(GLenum pname, GLint param);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glConservativeRasterParameteriNV(GLenum pname, GLint param);
#endif
#endif /* GL_NV_conservative_raster_pre_snap_triangles */

#ifndef GL_NV_draw_vulkan_image
#define GL_NV_draw_vulkan_image 1
typedef void(APIENTRY* GLVULKANPROCNV)(void);
typedef void(APIENTRYP PFNGLDRAWVKIMAGENVPROC)(GLuint64 vkImage,
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
typedef GLVULKANPROCNV(APIENTRYP PFNGLGETVKPROCADDRNVPROC)(const GLchar* name);
typedef void(APIENTRYP PFNGLWAITVKSEMAPHORENVPROC)(GLuint64 vkSemaphore);
typedef void(APIENTRYP PFNGLSIGNALVKSEMAPHORENVPROC)(GLuint64 vkSemaphore);
typedef void(APIENTRYP PFNGLSIGNALVKFENCENVPROC)(GLuint64 vkFence);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glDrawVkImageNV(GLuint64 vkImage,
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
GLAPI GLVULKANPROCNV APIENTRY glGetVkProcAddrNV(const GLchar* name);
GLAPI void APIENTRY glWaitVkSemaphoreNV(GLuint64 vkSemaphore);
GLAPI void APIENTRY glSignalVkSemaphoreNV(GLuint64 vkSemaphore);
GLAPI void APIENTRY glSignalVkFenceNV(GLuint64 vkFence);
#endif
#endif /* GL_NV_draw_vulkan_image */

#ifndef GL_NV_fill_rectangle
#define GL_NV_fill_rectangle 1
#define GL_FILL_RECTANGLE_NV 0x933C
#endif /* GL_NV_fill_rectangle */

#ifndef GL_NV_fragment_coverage_to_color
#define GL_NV_fragment_coverage_to_color 1
#define GL_FRAGMENT_COVERAGE_TO_COLOR_NV 0x92DD
#define GL_FRAGMENT_COVERAGE_COLOR_NV 0x92DE
typedef void(APIENTRYP PFNGLFRAGMENTCOVERAGECOLORNVPROC)(GLuint color);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glFragmentCoverageColorNV(GLuint color);
#endif
#endif /* GL_NV_fragment_coverage_to_color */

#ifndef GL_NV_fragment_shader_interlock
#define GL_NV_fragment_shader_interlock 1
#endif /* GL_NV_fragment_shader_interlock */

#ifndef GL_NV_framebuffer_mixed_samples
#define GL_NV_framebuffer_mixed_samples 1
#define GL_COVERAGE_MODULATION_TABLE_NV 0x9331
#define GL_COLOR_SAMPLES_NV 0x8E20
#define GL_DEPTH_SAMPLES_NV 0x932D
#define GL_STENCIL_SAMPLES_NV 0x932E
#define GL_MIXED_DEPTH_SAMPLES_SUPPORTED_NV 0x932F
#define GL_MIXED_STENCIL_SAMPLES_SUPPORTED_NV 0x9330
#define GL_COVERAGE_MODULATION_NV 0x9332
#define GL_COVERAGE_MODULATION_TABLE_SIZE_NV 0x9333
typedef void(APIENTRYP PFNGLCOVERAGEMODULATIONTABLENVPROC)(GLsizei n, const GLfloat* v);
typedef void(APIENTRYP PFNGLGETCOVERAGEMODULATIONTABLENVPROC)(GLsizei bufsize, GLfloat* v);
typedef void(APIENTRYP PFNGLCOVERAGEMODULATIONNVPROC)(GLenum components);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glCoverageModulationTableNV(GLsizei n, const GLfloat* v);
GLAPI void APIENTRY glGetCoverageModulationTableNV(GLsizei bufsize, GLfloat* v);
GLAPI void APIENTRY glCoverageModulationNV(GLenum components);
#endif
#endif /* GL_NV_framebuffer_mixed_samples */

#ifndef GL_NV_framebuffer_multisample_coverage
#define GL_NV_framebuffer_multisample_coverage 1
#define GL_RENDERBUFFER_COVERAGE_SAMPLES_NV 0x8CAB
#define GL_RENDERBUFFER_COLOR_SAMPLES_NV 0x8E10
#define GL_MAX_MULTISAMPLE_COVERAGE_MODES_NV 0x8E11
#define GL_MULTISAMPLE_COVERAGE_MODES_NV 0x8E12
typedef void(APIENTRYP PFNGLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENVPROC)(GLenum target,
                                                                          GLsizei coverageSamples,
                                                                          GLsizei colorSamples,
                                                                          GLenum internalformat,
                                                                          GLsizei width,
                                                                          GLsizei height);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glRenderbufferStorageMultisampleCoverageNV(GLenum target,
                                                               GLsizei coverageSamples,
                                                               GLsizei colorSamples,
                                                               GLenum internalformat,
                                                               GLsizei width,
                                                               GLsizei height);
#endif
#endif /* GL_NV_framebuffer_multisample_coverage */

#ifndef GL_NV_geometry_shader_passthrough
#define GL_NV_geometry_shader_passthrough 1
#endif /* GL_NV_geometry_shader_passthrough */

#ifndef GL_NV_gpu_shader5
#define GL_NV_gpu_shader5 1
typedef int64_t GLint64EXT;
#define GL_INT64_NV 0x140E
#define GL_UNSIGNED_INT64_NV 0x140F
#define GL_INT8_NV 0x8FE0
#define GL_INT8_VEC2_NV 0x8FE1
#define GL_INT8_VEC3_NV 0x8FE2
#define GL_INT8_VEC4_NV 0x8FE3
#define GL_INT16_NV 0x8FE4
#define GL_INT16_VEC2_NV 0x8FE5
#define GL_INT16_VEC3_NV 0x8FE6
#define GL_INT16_VEC4_NV 0x8FE7
#define GL_INT64_VEC2_NV 0x8FE9
#define GL_INT64_VEC3_NV 0x8FEA
#define GL_INT64_VEC4_NV 0x8FEB
#define GL_UNSIGNED_INT8_NV 0x8FEC
#define GL_UNSIGNED_INT8_VEC2_NV 0x8FED
#define GL_UNSIGNED_INT8_VEC3_NV 0x8FEE
#define GL_UNSIGNED_INT8_VEC4_NV 0x8FEF
#define GL_UNSIGNED_INT16_NV 0x8FF0
#define GL_UNSIGNED_INT16_VEC2_NV 0x8FF1
#define GL_UNSIGNED_INT16_VEC3_NV 0x8FF2
#define GL_UNSIGNED_INT16_VEC4_NV 0x8FF3
#define GL_UNSIGNED_INT64_VEC2_NV 0x8FF5
#define GL_UNSIGNED_INT64_VEC3_NV 0x8FF6
#define GL_UNSIGNED_INT64_VEC4_NV 0x8FF7
#define GL_FLOAT16_NV 0x8FF8
#define GL_FLOAT16_VEC2_NV 0x8FF9
#define GL_FLOAT16_VEC3_NV 0x8FFA
#define GL_FLOAT16_VEC4_NV 0x8FFB
typedef void(APIENTRYP PFNGLUNIFORM1I64NVPROC)(GLint location, GLint64EXT x);
typedef void(APIENTRYP PFNGLUNIFORM2I64NVPROC)(GLint location, GLint64EXT x, GLint64EXT y);
typedef void(APIENTRYP PFNGLUNIFORM3I64NVPROC)(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
typedef void(APIENTRYP PFNGLUNIFORM4I64NVPROC)(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
typedef void(APIENTRYP PFNGLUNIFORM1I64VNVPROC)(GLint location, GLsizei count, const GLint64EXT* value);
typedef void(APIENTRYP PFNGLUNIFORM2I64VNVPROC)(GLint location, GLsizei count, const GLint64EXT* value);
typedef void(APIENTRYP PFNGLUNIFORM3I64VNVPROC)(GLint location, GLsizei count, const GLint64EXT* value);
typedef void(APIENTRYP PFNGLUNIFORM4I64VNVPROC)(GLint location, GLsizei count, const GLint64EXT* value);
typedef void(APIENTRYP PFNGLUNIFORM1UI64NVPROC)(GLint location, GLuint64EXT x);
typedef void(APIENTRYP PFNGLUNIFORM2UI64NVPROC)(GLint location, GLuint64EXT x, GLuint64EXT y);
typedef void(APIENTRYP PFNGLUNIFORM3UI64NVPROC)(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
typedef void(
APIENTRYP PFNGLUNIFORM4UI64NVPROC)(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
typedef void(APIENTRYP PFNGLUNIFORM1UI64VNVPROC)(GLint location, GLsizei count, const GLuint64EXT* value);
typedef void(APIENTRYP PFNGLUNIFORM2UI64VNVPROC)(GLint location, GLsizei count, const GLuint64EXT* value);
typedef void(APIENTRYP PFNGLUNIFORM3UI64VNVPROC)(GLint location, GLsizei count, const GLuint64EXT* value);
typedef void(APIENTRYP PFNGLUNIFORM4UI64VNVPROC)(GLint location, GLsizei count, const GLuint64EXT* value);
typedef void(APIENTRYP PFNGLGETUNIFORMI64VNVPROC)(GLuint program, GLint location, GLint64EXT* params);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM1I64NVPROC)(GLuint program, GLint location, GLint64EXT x);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM2I64NVPROC)(GLuint program, GLint location, GLint64EXT x, GLint64EXT y);
typedef void(
APIENTRYP PFNGLPROGRAMUNIFORM3I64NVPROC)(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM4I64NVPROC)(GLuint program,
                                                      GLint location,
                                                      GLint64EXT x,
                                                      GLint64EXT y,
                                                      GLint64EXT z,
                                                      GLint64EXT w);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM1I64VNVPROC)(GLuint program,
                                                       GLint location,
                                                       GLsizei count,
                                                       const GLint64EXT* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM2I64VNVPROC)(GLuint program,
                                                       GLint location,
                                                       GLsizei count,
                                                       const GLint64EXT* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM3I64VNVPROC)(GLuint program,
                                                       GLint location,
                                                       GLsizei count,
                                                       const GLint64EXT* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM4I64VNVPROC)(GLuint program,
                                                       GLint location,
                                                       GLsizei count,
                                                       const GLint64EXT* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM1UI64NVPROC)(GLuint program, GLint location, GLuint64EXT x);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM2UI64NVPROC)(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y);
typedef void(
APIENTRYP PFNGLPROGRAMUNIFORM3UI64NVPROC)(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM4UI64NVPROC)(GLuint program,
                                                       GLint location,
                                                       GLuint64EXT x,
                                                       GLuint64EXT y,
                                                       GLuint64EXT z,
                                                       GLuint64EXT w);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM1UI64VNVPROC)(GLuint program,
                                                        GLint location,
                                                        GLsizei count,
                                                        const GLuint64EXT* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM2UI64VNVPROC)(GLuint program,
                                                        GLint location,
                                                        GLsizei count,
                                                        const GLuint64EXT* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM3UI64VNVPROC)(GLuint program,
                                                        GLint location,
                                                        GLsizei count,
                                                        const GLuint64EXT* value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORM4UI64VNVPROC)(GLuint program,
                                                        GLint location,
                                                        GLsizei count,
                                                        const GLuint64EXT* value);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glUniform1i64NV(GLint location, GLint64EXT x);
GLAPI void APIENTRY glUniform2i64NV(GLint location, GLint64EXT x, GLint64EXT y);
GLAPI void APIENTRY glUniform3i64NV(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
GLAPI void APIENTRY glUniform4i64NV(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
GLAPI void APIENTRY glUniform1i64vNV(GLint location, GLsizei count, const GLint64EXT* value);
GLAPI void APIENTRY glUniform2i64vNV(GLint location, GLsizei count, const GLint64EXT* value);
GLAPI void APIENTRY glUniform3i64vNV(GLint location, GLsizei count, const GLint64EXT* value);
GLAPI void APIENTRY glUniform4i64vNV(GLint location, GLsizei count, const GLint64EXT* value);
GLAPI void APIENTRY glUniform1ui64NV(GLint location, GLuint64EXT x);
GLAPI void APIENTRY glUniform2ui64NV(GLint location, GLuint64EXT x, GLuint64EXT y);
GLAPI void APIENTRY glUniform3ui64NV(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
GLAPI void APIENTRY glUniform4ui64NV(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
GLAPI void APIENTRY glUniform1ui64vNV(GLint location, GLsizei count, const GLuint64EXT* value);
GLAPI void APIENTRY glUniform2ui64vNV(GLint location, GLsizei count, const GLuint64EXT* value);
GLAPI void APIENTRY glUniform3ui64vNV(GLint location, GLsizei count, const GLuint64EXT* value);
GLAPI void APIENTRY glUniform4ui64vNV(GLint location, GLsizei count, const GLuint64EXT* value);
GLAPI void APIENTRY glGetUniformi64vNV(GLuint program, GLint location, GLint64EXT* params);
GLAPI void APIENTRY glProgramUniform1i64NV(GLuint program, GLint location, GLint64EXT x);
GLAPI void APIENTRY glProgramUniform2i64NV(GLuint program, GLint location, GLint64EXT x, GLint64EXT y);
GLAPI void APIENTRY glProgramUniform3i64NV(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
GLAPI void APIENTRY
glProgramUniform4i64NV(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
GLAPI void APIENTRY glProgramUniform1i64vNV(GLuint program, GLint location, GLsizei count, const GLint64EXT* value);
GLAPI void APIENTRY glProgramUniform2i64vNV(GLuint program, GLint location, GLsizei count, const GLint64EXT* value);
GLAPI void APIENTRY glProgramUniform3i64vNV(GLuint program, GLint location, GLsizei count, const GLint64EXT* value);
GLAPI void APIENTRY glProgramUniform4i64vNV(GLuint program, GLint location, GLsizei count, const GLint64EXT* value);
GLAPI void APIENTRY glProgramUniform1ui64NV(GLuint program, GLint location, GLuint64EXT x);
GLAPI void APIENTRY glProgramUniform2ui64NV(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y);
GLAPI void APIENTRY glProgramUniform3ui64NV(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
GLAPI void APIENTRY
glProgramUniform4ui64NV(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
GLAPI void APIENTRY glProgramUniform1ui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT* value);
GLAPI void APIENTRY glProgramUniform2ui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT* value);
GLAPI void APIENTRY glProgramUniform3ui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT* value);
GLAPI void APIENTRY glProgramUniform4ui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT* value);
#endif
#endif /* GL_NV_gpu_shader5 */

#ifndef GL_NV_internalformat_sample_query
#define GL_NV_internalformat_sample_query 1
#define GL_MULTISAMPLES_NV 0x9371
#define GL_SUPERSAMPLE_SCALE_X_NV 0x9372
#define GL_SUPERSAMPLE_SCALE_Y_NV 0x9373
#define GL_CONFORMANT_NV 0x9374
typedef void(APIENTRYP PFNGLGETINTERNALFORMATSAMPLEIVNVPROC)(GLenum target,
                                                             GLenum internalformat,
                                                             GLsizei samples,
                                                             GLenum pname,
                                                             GLsizei bufSize,
                                                             GLint* params);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glGetInternalformatSampleivNV(GLenum target,
                                                  GLenum internalformat,
                                                  GLsizei samples,
                                                  GLenum pname,
                                                  GLsizei bufSize,
                                                  GLint* params);
#endif
#endif /* GL_NV_internalformat_sample_query */

#ifndef GL_NV_path_rendering
#define GL_NV_path_rendering 1
#define GL_PATH_FORMAT_SVG_NV 0x9070
#define GL_PATH_FORMAT_PS_NV 0x9071
#define GL_STANDARD_FONT_NAME_NV 0x9072
#define GL_SYSTEM_FONT_NAME_NV 0x9073
#define GL_FILE_NAME_NV 0x9074
#define GL_PATH_STROKE_WIDTH_NV 0x9075
#define GL_PATH_END_CAPS_NV 0x9076
#define GL_PATH_INITIAL_END_CAP_NV 0x9077
#define GL_PATH_TERMINAL_END_CAP_NV 0x9078
#define GL_PATH_JOIN_STYLE_NV 0x9079
#define GL_PATH_MITER_LIMIT_NV 0x907A
#define GL_PATH_DASH_CAPS_NV 0x907B
#define GL_PATH_INITIAL_DASH_CAP_NV 0x907C
#define GL_PATH_TERMINAL_DASH_CAP_NV 0x907D
#define GL_PATH_DASH_OFFSET_NV 0x907E
#define GL_PATH_CLIENT_LENGTH_NV 0x907F
#define GL_PATH_FILL_MODE_NV 0x9080
#define GL_PATH_FILL_MASK_NV 0x9081
#define GL_PATH_FILL_COVER_MODE_NV 0x9082
#define GL_PATH_STROKE_COVER_MODE_NV 0x9083
#define GL_PATH_STROKE_MASK_NV 0x9084
#define GL_COUNT_UP_NV 0x9088
#define GL_COUNT_DOWN_NV 0x9089
#define GL_PATH_OBJECT_BOUNDING_BOX_NV 0x908A
#define GL_CONVEX_HULL_NV 0x908B
#define GL_BOUNDING_BOX_NV 0x908D
#define GL_TRANSLATE_X_NV 0x908E
#define GL_TRANSLATE_Y_NV 0x908F
#define GL_TRANSLATE_2D_NV 0x9090
#define GL_TRANSLATE_3D_NV 0x9091
#define GL_AFFINE_2D_NV 0x9092
#define GL_AFFINE_3D_NV 0x9094
#define GL_TRANSPOSE_AFFINE_2D_NV 0x9096
#define GL_TRANSPOSE_AFFINE_3D_NV 0x9098
#define GL_UTF8_NV 0x909A
#define GL_UTF16_NV 0x909B
#define GL_BOUNDING_BOX_OF_BOUNDING_BOXES_NV 0x909C
#define GL_PATH_COMMAND_COUNT_NV 0x909D
#define GL_PATH_COORD_COUNT_NV 0x909E
#define GL_PATH_DASH_ARRAY_COUNT_NV 0x909F
#define GL_PATH_COMPUTED_LENGTH_NV 0x90A0
#define GL_PATH_FILL_BOUNDING_BOX_NV 0x90A1
#define GL_PATH_STROKE_BOUNDING_BOX_NV 0x90A2
#define GL_SQUARE_NV 0x90A3
#define GL_ROUND_NV 0x90A4
#define GL_TRIANGULAR_NV 0x90A5
#define GL_BEVEL_NV 0x90A6
#define GL_MITER_REVERT_NV 0x90A7
#define GL_MITER_TRUNCATE_NV 0x90A8
#define GL_SKIP_MISSING_GLYPH_NV 0x90A9
#define GL_USE_MISSING_GLYPH_NV 0x90AA
#define GL_PATH_ERROR_POSITION_NV 0x90AB
#define GL_ACCUM_ADJACENT_PAIRS_NV 0x90AD
#define GL_ADJACENT_PAIRS_NV 0x90AE
#define GL_FIRST_TO_REST_NV 0x90AF
#define GL_PATH_GEN_MODE_NV 0x90B0
#define GL_PATH_GEN_COEFF_NV 0x90B1
#define GL_PATH_GEN_COMPONENTS_NV 0x90B3
#define GL_PATH_STENCIL_FUNC_NV 0x90B7
#define GL_PATH_STENCIL_REF_NV 0x90B8
#define GL_PATH_STENCIL_VALUE_MASK_NV 0x90B9
#define GL_PATH_STENCIL_DEPTH_OFFSET_FACTOR_NV 0x90BD
#define GL_PATH_STENCIL_DEPTH_OFFSET_UNITS_NV 0x90BE
#define GL_PATH_COVER_DEPTH_FUNC_NV 0x90BF
#define GL_PATH_DASH_OFFSET_RESET_NV 0x90B4
#define GL_MOVE_TO_RESETS_NV 0x90B5
#define GL_MOVE_TO_CONTINUES_NV 0x90B6
#define GL_CLOSE_PATH_NV 0x00
#define GL_MOVE_TO_NV 0x02
#define GL_RELATIVE_MOVE_TO_NV 0x03
#define GL_LINE_TO_NV 0x04
#define GL_RELATIVE_LINE_TO_NV 0x05
#define GL_HORIZONTAL_LINE_TO_NV 0x06
#define GL_RELATIVE_HORIZONTAL_LINE_TO_NV 0x07
#define GL_VERTICAL_LINE_TO_NV 0x08
#define GL_RELATIVE_VERTICAL_LINE_TO_NV 0x09
#define GL_QUADRATIC_CURVE_TO_NV 0x0A
#define GL_RELATIVE_QUADRATIC_CURVE_TO_NV 0x0B
#define GL_CUBIC_CURVE_TO_NV 0x0C
#define GL_RELATIVE_CUBIC_CURVE_TO_NV 0x0D
#define GL_SMOOTH_QUADRATIC_CURVE_TO_NV 0x0E
#define GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV 0x0F
#define GL_SMOOTH_CUBIC_CURVE_TO_NV 0x10
#define GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV 0x11
#define GL_SMALL_CCW_ARC_TO_NV 0x12
#define GL_RELATIVE_SMALL_CCW_ARC_TO_NV 0x13
#define GL_SMALL_CW_ARC_TO_NV 0x14
#define GL_RELATIVE_SMALL_CW_ARC_TO_NV 0x15
#define GL_LARGE_CCW_ARC_TO_NV 0x16
#define GL_RELATIVE_LARGE_CCW_ARC_TO_NV 0x17
#define GL_LARGE_CW_ARC_TO_NV 0x18
#define GL_RELATIVE_LARGE_CW_ARC_TO_NV 0x19
#define GL_RESTART_PATH_NV 0xF0
#define GL_DUP_FIRST_CUBIC_CURVE_TO_NV 0xF2
#define GL_DUP_LAST_CUBIC_CURVE_TO_NV 0xF4
#define GL_RECT_NV 0xF6
#define GL_CIRCULAR_CCW_ARC_TO_NV 0xF8
#define GL_CIRCULAR_CW_ARC_TO_NV 0xFA
#define GL_CIRCULAR_TANGENT_ARC_TO_NV 0xFC
#define GL_ARC_TO_NV 0xFE
#define GL_RELATIVE_ARC_TO_NV 0xFF
#define GL_BOLD_BIT_NV 0x01
#define GL_ITALIC_BIT_NV 0x02
#define GL_GLYPH_WIDTH_BIT_NV 0x01
#define GL_GLYPH_HEIGHT_BIT_NV 0x02
#define GL_GLYPH_HORIZONTAL_BEARING_X_BIT_NV 0x04
#define GL_GLYPH_HORIZONTAL_BEARING_Y_BIT_NV 0x08
#define GL_GLYPH_HORIZONTAL_BEARING_ADVANCE_BIT_NV 0x10
#define GL_GLYPH_VERTICAL_BEARING_X_BIT_NV 0x20
#define GL_GLYPH_VERTICAL_BEARING_Y_BIT_NV 0x40
#define GL_GLYPH_VERTICAL_BEARING_ADVANCE_BIT_NV 0x80
#define GL_GLYPH_HAS_KERNING_BIT_NV 0x100
#define GL_FONT_X_MIN_BOUNDS_BIT_NV 0x00010000
#define GL_FONT_Y_MIN_BOUNDS_BIT_NV 0x00020000
#define GL_FONT_X_MAX_BOUNDS_BIT_NV 0x00040000
#define GL_FONT_Y_MAX_BOUNDS_BIT_NV 0x00080000
#define GL_FONT_UNITS_PER_EM_BIT_NV 0x00100000
#define GL_FONT_ASCENDER_BIT_NV 0x00200000
#define GL_FONT_DESCENDER_BIT_NV 0x00400000
#define GL_FONT_HEIGHT_BIT_NV 0x00800000
#define GL_FONT_MAX_ADVANCE_WIDTH_BIT_NV 0x01000000
#define GL_FONT_MAX_ADVANCE_HEIGHT_BIT_NV 0x02000000
#define GL_FONT_UNDERLINE_POSITION_BIT_NV 0x04000000
#define GL_FONT_UNDERLINE_THICKNESS_BIT_NV 0x08000000
#define GL_FONT_HAS_KERNING_BIT_NV 0x10000000
#define GL_ROUNDED_RECT_NV 0xE8
#define GL_RELATIVE_ROUNDED_RECT_NV 0xE9
#define GL_ROUNDED_RECT2_NV 0xEA
#define GL_RELATIVE_ROUNDED_RECT2_NV 0xEB
#define GL_ROUNDED_RECT4_NV 0xEC
#define GL_RELATIVE_ROUNDED_RECT4_NV 0xED
#define GL_ROUNDED_RECT8_NV 0xEE
#define GL_RELATIVE_ROUNDED_RECT8_NV 0xEF
#define GL_RELATIVE_RECT_NV 0xF7
#define GL_FONT_GLYPHS_AVAILABLE_NV 0x9368
#define GL_FONT_TARGET_UNAVAILABLE_NV 0x9369
#define GL_FONT_UNAVAILABLE_NV 0x936A
#define GL_FONT_UNINTELLIGIBLE_NV 0x936B
#define GL_CONIC_CURVE_TO_NV 0x1A
#define GL_RELATIVE_CONIC_CURVE_TO_NV 0x1B
#define GL_FONT_NUM_GLYPH_INDICES_BIT_NV 0x20000000
#define GL_STANDARD_FONT_FORMAT_NV 0x936C
#define GL_PATH_PROJECTION_NV 0x1701
#define GL_PATH_MODELVIEW_NV 0x1700
#define GL_PATH_MODELVIEW_STACK_DEPTH_NV 0x0BA3
#define GL_PATH_MODELVIEW_MATRIX_NV 0x0BA6
#define GL_PATH_MAX_MODELVIEW_STACK_DEPTH_NV 0x0D36
#define GL_PATH_TRANSPOSE_MODELVIEW_MATRIX_NV 0x84E3
#define GL_PATH_PROJECTION_STACK_DEPTH_NV 0x0BA4
#define GL_PATH_PROJECTION_MATRIX_NV 0x0BA7
#define GL_PATH_MAX_PROJECTION_STACK_DEPTH_NV 0x0D38
#define GL_PATH_TRANSPOSE_PROJECTION_MATRIX_NV 0x84E4
#define GL_FRAGMENT_INPUT_NV 0x936D
typedef GLuint(APIENTRYP PFNGLGENPATHSNVPROC)(GLsizei range);
typedef void(APIENTRYP PFNGLDELETEPATHSNVPROC)(GLuint path, GLsizei range);
typedef GLboolean(APIENTRYP PFNGLISPATHNVPROC)(GLuint path);
typedef void(APIENTRYP PFNGLPATHCOMMANDSNVPROC)(GLuint path,
                                                GLsizei numCommands,
                                                const GLubyte* commands,
                                                GLsizei numCoords,
                                                GLenum coordType,
                                                const void* coords);
typedef void(APIENTRYP PFNGLPATHCOORDSNVPROC)(GLuint path, GLsizei numCoords, GLenum coordType, const void* coords);
typedef void(APIENTRYP PFNGLPATHSUBCOMMANDSNVPROC)(GLuint path,
                                                   GLsizei commandStart,
                                                   GLsizei commandsToDelete,
                                                   GLsizei numCommands,
                                                   const GLubyte* commands,
                                                   GLsizei numCoords,
                                                   GLenum coordType,
                                                   const void* coords);
typedef void(APIENTRYP PFNGLPATHSUBCOORDSNVPROC)(GLuint path,
                                                 GLsizei coordStart,
                                                 GLsizei numCoords,
                                                 GLenum coordType,
                                                 const void* coords);
typedef void(APIENTRYP PFNGLPATHSTRINGNVPROC)(GLuint path, GLenum format, GLsizei length, const void* pathString);
typedef void(APIENTRYP PFNGLPATHGLYPHSNVPROC)(GLuint firstPathName,
                                              GLenum fontTarget,
                                              const void* fontName,
                                              GLbitfield fontStyle,
                                              GLsizei numGlyphs,
                                              GLenum type,
                                              const void* charcodes,
                                              GLenum handleMissingGlyphs,
                                              GLuint pathParameterTemplate,
                                              GLfloat emScale);
typedef void(APIENTRYP PFNGLPATHGLYPHRANGENVPROC)(GLuint firstPathName,
                                                  GLenum fontTarget,
                                                  const void* fontName,
                                                  GLbitfield fontStyle,
                                                  GLuint firstGlyph,
                                                  GLsizei numGlyphs,
                                                  GLenum handleMissingGlyphs,
                                                  GLuint pathParameterTemplate,
                                                  GLfloat emScale);
typedef void(APIENTRYP PFNGLWEIGHTPATHSNVPROC)(GLuint resultPath,
                                               GLsizei numPaths,
                                               const GLuint* paths,
                                               const GLfloat* weights);
typedef void(APIENTRYP PFNGLCOPYPATHNVPROC)(GLuint resultPath, GLuint srcPath);
typedef void(APIENTRYP PFNGLINTERPOLATEPATHSNVPROC)(GLuint resultPath, GLuint pathA, GLuint pathB, GLfloat weight);
typedef void(APIENTRYP PFNGLTRANSFORMPATHNVPROC)(GLuint resultPath,
                                                 GLuint srcPath,
                                                 GLenum transformType,
                                                 const GLfloat* transformValues);
typedef void(APIENTRYP PFNGLPATHPARAMETERIVNVPROC)(GLuint path, GLenum pname, const GLint* value);
typedef void(APIENTRYP PFNGLPATHPARAMETERINVPROC)(GLuint path, GLenum pname, GLint value);
typedef void(APIENTRYP PFNGLPATHPARAMETERFVNVPROC)(GLuint path, GLenum pname, const GLfloat* value);
typedef void(APIENTRYP PFNGLPATHPARAMETERFNVPROC)(GLuint path, GLenum pname, GLfloat value);
typedef void(APIENTRYP PFNGLPATHDASHARRAYNVPROC)(GLuint path, GLsizei dashCount, const GLfloat* dashArray);
typedef void(APIENTRYP PFNGLPATHSTENCILFUNCNVPROC)(GLenum func, GLint ref, GLuint mask);
typedef void(APIENTRYP PFNGLPATHSTENCILDEPTHOFFSETNVPROC)(GLfloat factor, GLfloat units);
typedef void(APIENTRYP PFNGLSTENCILFILLPATHNVPROC)(GLuint path, GLenum fillMode, GLuint mask);
typedef void(APIENTRYP PFNGLSTENCILSTROKEPATHNVPROC)(GLuint path, GLint reference, GLuint mask);
typedef void(APIENTRYP PFNGLSTENCILFILLPATHINSTANCEDNVPROC)(GLsizei numPaths,
                                                            GLenum pathNameType,
                                                            const void* paths,
                                                            GLuint pathBase,
                                                            GLenum fillMode,
                                                            GLuint mask,
                                                            GLenum transformType,
                                                            const GLfloat* transformValues);
typedef void(APIENTRYP PFNGLSTENCILSTROKEPATHINSTANCEDNVPROC)(GLsizei numPaths,
                                                              GLenum pathNameType,
                                                              const void* paths,
                                                              GLuint pathBase,
                                                              GLint reference,
                                                              GLuint mask,
                                                              GLenum transformType,
                                                              const GLfloat* transformValues);
typedef void(APIENTRYP PFNGLPATHCOVERDEPTHFUNCNVPROC)(GLenum func);
typedef void(APIENTRYP PFNGLCOVERFILLPATHNVPROC)(GLuint path, GLenum coverMode);
typedef void(APIENTRYP PFNGLCOVERSTROKEPATHNVPROC)(GLuint path, GLenum coverMode);
typedef void(APIENTRYP PFNGLCOVERFILLPATHINSTANCEDNVPROC)(GLsizei numPaths,
                                                          GLenum pathNameType,
                                                          const void* paths,
                                                          GLuint pathBase,
                                                          GLenum coverMode,
                                                          GLenum transformType,
                                                          const GLfloat* transformValues);
typedef void(APIENTRYP PFNGLCOVERSTROKEPATHINSTANCEDNVPROC)(GLsizei numPaths,
                                                            GLenum pathNameType,
                                                            const void* paths,
                                                            GLuint pathBase,
                                                            GLenum coverMode,
                                                            GLenum transformType,
                                                            const GLfloat* transformValues);
typedef void(APIENTRYP PFNGLGETPATHPARAMETERIVNVPROC)(GLuint path, GLenum pname, GLint* value);
typedef void(APIENTRYP PFNGLGETPATHPARAMETERFVNVPROC)(GLuint path, GLenum pname, GLfloat* value);
typedef void(APIENTRYP PFNGLGETPATHCOMMANDSNVPROC)(GLuint path, GLubyte* commands);
typedef void(APIENTRYP PFNGLGETPATHCOORDSNVPROC)(GLuint path, GLfloat* coords);
typedef void(APIENTRYP PFNGLGETPATHDASHARRAYNVPROC)(GLuint path, GLfloat* dashArray);
typedef void(APIENTRYP PFNGLGETPATHMETRICSNVPROC)(GLbitfield metricQueryMask,
                                                  GLsizei numPaths,
                                                  GLenum pathNameType,
                                                  const void* paths,
                                                  GLuint pathBase,
                                                  GLsizei stride,
                                                  GLfloat* metrics);
typedef void(APIENTRYP PFNGLGETPATHMETRICRANGENVPROC)(GLbitfield metricQueryMask,
                                                      GLuint firstPathName,
                                                      GLsizei numPaths,
                                                      GLsizei stride,
                                                      GLfloat* metrics);
typedef void(APIENTRYP PFNGLGETPATHSPACINGNVPROC)(GLenum pathListMode,
                                                  GLsizei numPaths,
                                                  GLenum pathNameType,
                                                  const void* paths,
                                                  GLuint pathBase,
                                                  GLfloat advanceScale,
                                                  GLfloat kerningScale,
                                                  GLenum transformType,
                                                  GLfloat* returnedSpacing);
typedef GLboolean(APIENTRYP PFNGLISPOINTINFILLPATHNVPROC)(GLuint path, GLuint mask, GLfloat x, GLfloat y);
typedef GLboolean(APIENTRYP PFNGLISPOINTINSTROKEPATHNVPROC)(GLuint path, GLfloat x, GLfloat y);
typedef GLfloat(APIENTRYP PFNGLGETPATHLENGTHNVPROC)(GLuint path, GLsizei startSegment, GLsizei numSegments);
typedef GLboolean(APIENTRYP PFNGLPOINTALONGPATHNVPROC)(GLuint path,
                                                       GLsizei startSegment,
                                                       GLsizei numSegments,
                                                       GLfloat distance,
                                                       GLfloat* x,
                                                       GLfloat* y,
                                                       GLfloat* tangentX,
                                                       GLfloat* tangentY);
typedef void(APIENTRYP PFNGLMATRIXLOAD3X2FNVPROC)(GLenum matrixMode, const GLfloat* m);
typedef void(APIENTRYP PFNGLMATRIXLOAD3X3FNVPROC)(GLenum matrixMode, const GLfloat* m);
typedef void(APIENTRYP PFNGLMATRIXLOADTRANSPOSE3X3FNVPROC)(GLenum matrixMode, const GLfloat* m);
typedef void(APIENTRYP PFNGLMATRIXMULT3X2FNVPROC)(GLenum matrixMode, const GLfloat* m);
typedef void(APIENTRYP PFNGLMATRIXMULT3X3FNVPROC)(GLenum matrixMode, const GLfloat* m);
typedef void(APIENTRYP PFNGLMATRIXMULTTRANSPOSE3X3FNVPROC)(GLenum matrixMode, const GLfloat* m);
typedef void(APIENTRYP PFNGLSTENCILTHENCOVERFILLPATHNVPROC)(GLuint path, GLenum fillMode, GLuint mask, GLenum coverMode);
typedef void(APIENTRYP PFNGLSTENCILTHENCOVERSTROKEPATHNVPROC)(GLuint path,
                                                              GLint reference,
                                                              GLuint mask,
                                                              GLenum coverMode);
typedef void(APIENTRYP PFNGLSTENCILTHENCOVERFILLPATHINSTANCEDNVPROC)(GLsizei numPaths,
                                                                     GLenum pathNameType,
                                                                     const void* paths,
                                                                     GLuint pathBase,
                                                                     GLenum fillMode,
                                                                     GLuint mask,
                                                                     GLenum coverMode,
                                                                     GLenum transformType,
                                                                     const GLfloat* transformValues);
typedef void(APIENTRYP PFNGLSTENCILTHENCOVERSTROKEPATHINSTANCEDNVPROC)(GLsizei numPaths,
                                                                       GLenum pathNameType,
                                                                       const void* paths,
                                                                       GLuint pathBase,
                                                                       GLint reference,
                                                                       GLuint mask,
                                                                       GLenum coverMode,
                                                                       GLenum transformType,
                                                                       const GLfloat* transformValues);
typedef GLenum(APIENTRYP PFNGLPATHGLYPHINDEXRANGENVPROC)(GLenum fontTarget,
                                                         const void* fontName,
                                                         GLbitfield fontStyle,
                                                         GLuint pathParameterTemplate,
                                                         GLfloat emScale,
                                                         GLuint baseAndCount[2]);
typedef GLenum(APIENTRYP PFNGLPATHGLYPHINDEXARRAYNVPROC)(GLuint firstPathName,
                                                         GLenum fontTarget,
                                                         const void* fontName,
                                                         GLbitfield fontStyle,
                                                         GLuint firstGlyphIndex,
                                                         GLsizei numGlyphs,
                                                         GLuint pathParameterTemplate,
                                                         GLfloat emScale);
typedef GLenum(APIENTRYP PFNGLPATHMEMORYGLYPHINDEXARRAYNVPROC)(GLuint firstPathName,
                                                               GLenum fontTarget,
                                                               GLsizeiptr fontSize,
                                                               const void* fontData,
                                                               GLsizei faceIndex,
                                                               GLuint firstGlyphIndex,
                                                               GLsizei numGlyphs,
                                                               GLuint pathParameterTemplate,
                                                               GLfloat emScale);
typedef void(APIENTRYP PFNGLPROGRAMPATHFRAGMENTINPUTGENNVPROC)(GLuint program,
                                                               GLint location,
                                                               GLenum genMode,
                                                               GLint components,
                                                               const GLfloat* coeffs);
typedef void(APIENTRYP PFNGLGETPROGRAMRESOURCEFVNVPROC)(GLuint program,
                                                        GLenum programInterface,
                                                        GLuint index,
                                                        GLsizei propCount,
                                                        const GLenum* props,
                                                        GLsizei bufSize,
                                                        GLsizei* length,
                                                        GLfloat* params);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI GLuint APIENTRY glGenPathsNV(GLsizei range);
GLAPI void APIENTRY glDeletePathsNV(GLuint path, GLsizei range);
GLAPI GLboolean APIENTRY glIsPathNV(GLuint path);
GLAPI void APIENTRY glPathCommandsNV(GLuint path,
                                     GLsizei numCommands,
                                     const GLubyte* commands,
                                     GLsizei numCoords,
                                     GLenum coordType,
                                     const void* coords);
GLAPI void APIENTRY glPathCoordsNV(GLuint path, GLsizei numCoords, GLenum coordType, const void* coords);
GLAPI void APIENTRY glPathSubCommandsNV(GLuint path,
                                        GLsizei commandStart,
                                        GLsizei commandsToDelete,
                                        GLsizei numCommands,
                                        const GLubyte* commands,
                                        GLsizei numCoords,
                                        GLenum coordType,
                                        const void* coords);
GLAPI void APIENTRY
glPathSubCoordsNV(GLuint path, GLsizei coordStart, GLsizei numCoords, GLenum coordType, const void* coords);
GLAPI void APIENTRY glPathStringNV(GLuint path, GLenum format, GLsizei length, const void* pathString);
GLAPI void APIENTRY glPathGlyphsNV(GLuint firstPathName,
                                   GLenum fontTarget,
                                   const void* fontName,
                                   GLbitfield fontStyle,
                                   GLsizei numGlyphs,
                                   GLenum type,
                                   const void* charcodes,
                                   GLenum handleMissingGlyphs,
                                   GLuint pathParameterTemplate,
                                   GLfloat emScale);
GLAPI void APIENTRY glPathGlyphRangeNV(GLuint firstPathName,
                                       GLenum fontTarget,
                                       const void* fontName,
                                       GLbitfield fontStyle,
                                       GLuint firstGlyph,
                                       GLsizei numGlyphs,
                                       GLenum handleMissingGlyphs,
                                       GLuint pathParameterTemplate,
                                       GLfloat emScale);
GLAPI void APIENTRY glWeightPathsNV(GLuint resultPath, GLsizei numPaths, const GLuint* paths, const GLfloat* weights);
GLAPI void APIENTRY glCopyPathNV(GLuint resultPath, GLuint srcPath);
GLAPI void APIENTRY glInterpolatePathsNV(GLuint resultPath, GLuint pathA, GLuint pathB, GLfloat weight);
GLAPI void APIENTRY glTransformPathNV(GLuint resultPath,
                                      GLuint srcPath,
                                      GLenum transformType,
                                      const GLfloat* transformValues);
GLAPI void APIENTRY glPathParameterivNV(GLuint path, GLenum pname, const GLint* value);
GLAPI void APIENTRY glPathParameteriNV(GLuint path, GLenum pname, GLint value);
GLAPI void APIENTRY glPathParameterfvNV(GLuint path, GLenum pname, const GLfloat* value);
GLAPI void APIENTRY glPathParameterfNV(GLuint path, GLenum pname, GLfloat value);
GLAPI void APIENTRY glPathDashArrayNV(GLuint path, GLsizei dashCount, const GLfloat* dashArray);
GLAPI void APIENTRY glPathStencilFuncNV(GLenum func, GLint ref, GLuint mask);
GLAPI void APIENTRY glPathStencilDepthOffsetNV(GLfloat factor, GLfloat units);
GLAPI void APIENTRY glStencilFillPathNV(GLuint path, GLenum fillMode, GLuint mask);
GLAPI void APIENTRY glStencilStrokePathNV(GLuint path, GLint reference, GLuint mask);
GLAPI void APIENTRY glStencilFillPathInstancedNV(GLsizei numPaths,
                                                 GLenum pathNameType,
                                                 const void* paths,
                                                 GLuint pathBase,
                                                 GLenum fillMode,
                                                 GLuint mask,
                                                 GLenum transformType,
                                                 const GLfloat* transformValues);
GLAPI void APIENTRY glStencilStrokePathInstancedNV(GLsizei numPaths,
                                                   GLenum pathNameType,
                                                   const void* paths,
                                                   GLuint pathBase,
                                                   GLint reference,
                                                   GLuint mask,
                                                   GLenum transformType,
                                                   const GLfloat* transformValues);
GLAPI void APIENTRY glPathCoverDepthFuncNV(GLenum func);
GLAPI void APIENTRY glCoverFillPathNV(GLuint path, GLenum coverMode);
GLAPI void APIENTRY glCoverStrokePathNV(GLuint path, GLenum coverMode);
GLAPI void APIENTRY glCoverFillPathInstancedNV(GLsizei numPaths,
                                               GLenum pathNameType,
                                               const void* paths,
                                               GLuint pathBase,
                                               GLenum coverMode,
                                               GLenum transformType,
                                               const GLfloat* transformValues);
GLAPI void APIENTRY glCoverStrokePathInstancedNV(GLsizei numPaths,
                                                 GLenum pathNameType,
                                                 const void* paths,
                                                 GLuint pathBase,
                                                 GLenum coverMode,
                                                 GLenum transformType,
                                                 const GLfloat* transformValues);
GLAPI void APIENTRY glGetPathParameterivNV(GLuint path, GLenum pname, GLint* value);
GLAPI void APIENTRY glGetPathParameterfvNV(GLuint path, GLenum pname, GLfloat* value);
GLAPI void APIENTRY glGetPathCommandsNV(GLuint path, GLubyte* commands);
GLAPI void APIENTRY glGetPathCoordsNV(GLuint path, GLfloat* coords);
GLAPI void APIENTRY glGetPathDashArrayNV(GLuint path, GLfloat* dashArray);
GLAPI void APIENTRY glGetPathMetricsNV(GLbitfield metricQueryMask,
                                       GLsizei numPaths,
                                       GLenum pathNameType,
                                       const void* paths,
                                       GLuint pathBase,
                                       GLsizei stride,
                                       GLfloat* metrics);
GLAPI void APIENTRY glGetPathMetricRangeNV(GLbitfield metricQueryMask,
                                           GLuint firstPathName,
                                           GLsizei numPaths,
                                           GLsizei stride,
                                           GLfloat* metrics);
GLAPI void APIENTRY glGetPathSpacingNV(GLenum pathListMode,
                                       GLsizei numPaths,
                                       GLenum pathNameType,
                                       const void* paths,
                                       GLuint pathBase,
                                       GLfloat advanceScale,
                                       GLfloat kerningScale,
                                       GLenum transformType,
                                       GLfloat* returnedSpacing);
GLAPI GLboolean APIENTRY glIsPointInFillPathNV(GLuint path, GLuint mask, GLfloat x, GLfloat y);
GLAPI GLboolean APIENTRY glIsPointInStrokePathNV(GLuint path, GLfloat x, GLfloat y);
GLAPI GLfloat APIENTRY glGetPathLengthNV(GLuint path, GLsizei startSegment, GLsizei numSegments);
GLAPI GLboolean APIENTRY glPointAlongPathNV(GLuint path,
                                            GLsizei startSegment,
                                            GLsizei numSegments,
                                            GLfloat distance,
                                            GLfloat* x,
                                            GLfloat* y,
                                            GLfloat* tangentX,
                                            GLfloat* tangentY);
GLAPI void APIENTRY glMatrixLoad3x2fNV(GLenum matrixMode, const GLfloat* m);
GLAPI void APIENTRY glMatrixLoad3x3fNV(GLenum matrixMode, const GLfloat* m);
GLAPI void APIENTRY glMatrixLoadTranspose3x3fNV(GLenum matrixMode, const GLfloat* m);
GLAPI void APIENTRY glMatrixMult3x2fNV(GLenum matrixMode, const GLfloat* m);
GLAPI void APIENTRY glMatrixMult3x3fNV(GLenum matrixMode, const GLfloat* m);
GLAPI void APIENTRY glMatrixMultTranspose3x3fNV(GLenum matrixMode, const GLfloat* m);
GLAPI void APIENTRY glStencilThenCoverFillPathNV(GLuint path, GLenum fillMode, GLuint mask, GLenum coverMode);
GLAPI void APIENTRY glStencilThenCoverStrokePathNV(GLuint path, GLint reference, GLuint mask, GLenum coverMode);
GLAPI void APIENTRY glStencilThenCoverFillPathInstancedNV(GLsizei numPaths,
                                                          GLenum pathNameType,
                                                          const void* paths,
                                                          GLuint pathBase,
                                                          GLenum fillMode,
                                                          GLuint mask,
                                                          GLenum coverMode,
                                                          GLenum transformType,
                                                          const GLfloat* transformValues);
GLAPI void APIENTRY glStencilThenCoverStrokePathInstancedNV(GLsizei numPaths,
                                                            GLenum pathNameType,
                                                            const void* paths,
                                                            GLuint pathBase,
                                                            GLint reference,
                                                            GLuint mask,
                                                            GLenum coverMode,
                                                            GLenum transformType,
                                                            const GLfloat* transformValues);
GLAPI GLenum APIENTRY glPathGlyphIndexRangeNV(GLenum fontTarget,
                                              const void* fontName,
                                              GLbitfield fontStyle,
                                              GLuint pathParameterTemplate,
                                              GLfloat emScale,
                                              GLuint baseAndCount[2]);
GLAPI GLenum APIENTRY glPathGlyphIndexArrayNV(GLuint firstPathName,
                                              GLenum fontTarget,
                                              const void* fontName,
                                              GLbitfield fontStyle,
                                              GLuint firstGlyphIndex,
                                              GLsizei numGlyphs,
                                              GLuint pathParameterTemplate,
                                              GLfloat emScale);
GLAPI GLenum APIENTRY glPathMemoryGlyphIndexArrayNV(GLuint firstPathName,
                                                    GLenum fontTarget,
                                                    GLsizeiptr fontSize,
                                                    const void* fontData,
                                                    GLsizei faceIndex,
                                                    GLuint firstGlyphIndex,
                                                    GLsizei numGlyphs,
                                                    GLuint pathParameterTemplate,
                                                    GLfloat emScale);
GLAPI void APIENTRY glProgramPathFragmentInputGenNV(GLuint program,
                                                    GLint location,
                                                    GLenum genMode,
                                                    GLint components,
                                                    const GLfloat* coeffs);
GLAPI void APIENTRY glGetProgramResourcefvNV(GLuint program,
                                             GLenum programInterface,
                                             GLuint index,
                                             GLsizei propCount,
                                             const GLenum* props,
                                             GLsizei bufSize,
                                             GLsizei* length,
                                             GLfloat* params);
#endif
#endif /* GL_NV_path_rendering */

#ifndef GL_NV_path_rendering_shared_edge
#define GL_NV_path_rendering_shared_edge 1
#define GL_SHARED_EDGE_NV 0xC0
#endif /* GL_NV_path_rendering_shared_edge */

#ifndef GL_NV_sample_locations
#define GL_NV_sample_locations 1
#define GL_SAMPLE_LOCATION_SUBPIXEL_BITS_NV 0x933D
#define GL_SAMPLE_LOCATION_PIXEL_GRID_WIDTH_NV 0x933E
#define GL_SAMPLE_LOCATION_PIXEL_GRID_HEIGHT_NV 0x933F
#define GL_PROGRAMMABLE_SAMPLE_LOCATION_TABLE_SIZE_NV 0x9340
#define GL_SAMPLE_LOCATION_NV 0x8E50
#define GL_PROGRAMMABLE_SAMPLE_LOCATION_NV 0x9341
#define GL_FRAMEBUFFER_PROGRAMMABLE_SAMPLE_LOCATIONS_NV 0x9342
#define GL_FRAMEBUFFER_SAMPLE_LOCATION_PIXEL_GRID_NV 0x9343
typedef void(APIENTRYP PFNGLFRAMEBUFFERSAMPLELOCATIONSFVNVPROC)(GLenum target,
                                                                GLuint start,
                                                                GLsizei count,
                                                                const GLfloat* v);
typedef void(APIENTRYP PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVNVPROC)(GLuint framebuffer,
                                                                     GLuint start,
                                                                     GLsizei count,
                                                                     const GLfloat* v);
typedef void(APIENTRYP PFNGLRESOLVEDEPTHVALUESNVPROC)(void);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glFramebufferSampleLocationsfvNV(GLenum target, GLuint start, GLsizei count, const GLfloat* v);
GLAPI void APIENTRY glNamedFramebufferSampleLocationsfvNV(GLuint framebuffer,
                                                          GLuint start,
                                                          GLsizei count,
                                                          const GLfloat* v);
GLAPI void APIENTRY glResolveDepthValuesNV(void);
#endif
#endif /* GL_NV_sample_locations */

#ifndef GL_NV_sample_mask_override_coverage
#define GL_NV_sample_mask_override_coverage 1
#endif /* GL_NV_sample_mask_override_coverage */

#ifndef GL_NV_shader_atomic_counters
#define GL_NV_shader_atomic_counters 1
#endif /* GL_NV_shader_atomic_counters */

#ifndef GL_NV_shader_atomic_float
#define GL_NV_shader_atomic_float 1
#endif /* GL_NV_shader_atomic_float */

#ifndef GL_NV_shader_atomic_float64
#define GL_NV_shader_atomic_float64 1
#endif /* GL_NV_shader_atomic_float64 */

#ifndef GL_NV_shader_atomic_fp16_vector
#define GL_NV_shader_atomic_fp16_vector 1
#endif /* GL_NV_shader_atomic_fp16_vector */

#ifndef GL_NV_shader_atomic_int64
#define GL_NV_shader_atomic_int64 1
#endif /* GL_NV_shader_atomic_int64 */

#ifndef GL_NV_shader_buffer_load
#define GL_NV_shader_buffer_load 1
#define GL_BUFFER_GPU_ADDRESS_NV 0x8F1D
#define GL_GPU_ADDRESS_NV 0x8F34
#define GL_MAX_SHADER_BUFFER_ADDRESS_NV 0x8F35
typedef void(APIENTRYP PFNGLMAKEBUFFERRESIDENTNVPROC)(GLenum target, GLenum access);
typedef void(APIENTRYP PFNGLMAKEBUFFERNONRESIDENTNVPROC)(GLenum target);
typedef GLboolean(APIENTRYP PFNGLISBUFFERRESIDENTNVPROC)(GLenum target);
typedef void(APIENTRYP PFNGLMAKENAMEDBUFFERRESIDENTNVPROC)(GLuint buffer, GLenum access);
typedef void(APIENTRYP PFNGLMAKENAMEDBUFFERNONRESIDENTNVPROC)(GLuint buffer);
typedef GLboolean(APIENTRYP PFNGLISNAMEDBUFFERRESIDENTNVPROC)(GLuint buffer);
typedef void(APIENTRYP PFNGLGETBUFFERPARAMETERUI64VNVPROC)(GLenum target, GLenum pname, GLuint64EXT* params);
typedef void(APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERUI64VNVPROC)(GLuint buffer, GLenum pname, GLuint64EXT* params);
typedef void(APIENTRYP PFNGLGETINTEGERUI64VNVPROC)(GLenum value, GLuint64EXT* result);
typedef void(APIENTRYP PFNGLUNIFORMUI64NVPROC)(GLint location, GLuint64EXT value);
typedef void(APIENTRYP PFNGLUNIFORMUI64VNVPROC)(GLint location, GLsizei count, const GLuint64EXT* value);
typedef void(APIENTRYP PFNGLGETUNIFORMUI64VNVPROC)(GLuint program, GLint location, GLuint64EXT* params);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORMUI64NVPROC)(GLuint program, GLint location, GLuint64EXT value);
typedef void(APIENTRYP PFNGLPROGRAMUNIFORMUI64VNVPROC)(GLuint program,
                                                       GLint location,
                                                       GLsizei count,
                                                       const GLuint64EXT* value);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glMakeBufferResidentNV(GLenum target, GLenum access);
GLAPI void APIENTRY glMakeBufferNonResidentNV(GLenum target);
GLAPI GLboolean APIENTRY glIsBufferResidentNV(GLenum target);
GLAPI void APIENTRY glMakeNamedBufferResidentNV(GLuint buffer, GLenum access);
GLAPI void APIENTRY glMakeNamedBufferNonResidentNV(GLuint buffer);
GLAPI GLboolean APIENTRY glIsNamedBufferResidentNV(GLuint buffer);
GLAPI void APIENTRY glGetBufferParameterui64vNV(GLenum target, GLenum pname, GLuint64EXT* params);
GLAPI void APIENTRY glGetNamedBufferParameterui64vNV(GLuint buffer, GLenum pname, GLuint64EXT* params);
GLAPI void APIENTRY glGetIntegerui64vNV(GLenum value, GLuint64EXT* result);
GLAPI void APIENTRY glUniformui64NV(GLint location, GLuint64EXT value);
GLAPI void APIENTRY glUniformui64vNV(GLint location, GLsizei count, const GLuint64EXT* value);
GLAPI void APIENTRY glGetUniformui64vNV(GLuint program, GLint location, GLuint64EXT* params);
GLAPI void APIENTRY glProgramUniformui64NV(GLuint program, GLint location, GLuint64EXT value);
GLAPI void APIENTRY glProgramUniformui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT* value);
#endif
#endif /* GL_NV_shader_buffer_load */

#ifndef GL_NV_shader_buffer_store
#define GL_NV_shader_buffer_store 1
#define GL_SHADER_GLOBAL_ACCESS_BARRIER_BIT_NV 0x00000010
#endif /* GL_NV_shader_buffer_store */

#ifndef GL_NV_shader_thread_group
#define GL_NV_shader_thread_group 1
#define GL_WARP_SIZE_NV 0x9339
#define GL_WARPS_PER_SM_NV 0x933A
#define GL_SM_COUNT_NV 0x933B
#endif /* GL_NV_shader_thread_group */

#ifndef GL_NV_shader_thread_shuffle
#define GL_NV_shader_thread_shuffle 1
#endif /* GL_NV_shader_thread_shuffle */

#ifndef GL_NV_stereo_view_rendering
#define GL_NV_stereo_view_rendering 1
#endif /* GL_NV_stereo_view_rendering */

#ifndef GL_NV_texture_barrier
#define GL_NV_texture_barrier 1
typedef void(APIENTRYP PFNGLTEXTUREBARRIERNVPROC)(void);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glTextureBarrierNV(void);
#endif
#endif /* GL_NV_texture_barrier */

#ifndef GL_NV_texture_rectangle_compressed
#define GL_NV_texture_rectangle_compressed 1
#endif /* GL_NV_texture_rectangle_compressed */

#ifndef GL_NV_uniform_buffer_unified_memory
#define GL_NV_uniform_buffer_unified_memory 1
#define GL_UNIFORM_BUFFER_UNIFIED_NV 0x936E
#define GL_UNIFORM_BUFFER_ADDRESS_NV 0x936F
#define GL_UNIFORM_BUFFER_LENGTH_NV 0x9370
#endif /* GL_NV_uniform_buffer_unified_memory */

#ifndef GL_NV_vertex_attrib_integer_64bit
#define GL_NV_vertex_attrib_integer_64bit 1
typedef void(APIENTRYP PFNGLVERTEXATTRIBL1I64NVPROC)(GLuint index, GLint64EXT x);
typedef void(APIENTRYP PFNGLVERTEXATTRIBL2I64NVPROC)(GLuint index, GLint64EXT x, GLint64EXT y);
typedef void(APIENTRYP PFNGLVERTEXATTRIBL3I64NVPROC)(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z);
typedef void(
APIENTRYP PFNGLVERTEXATTRIBL4I64NVPROC)(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
typedef void(APIENTRYP PFNGLVERTEXATTRIBL1I64VNVPROC)(GLuint index, const GLint64EXT* v);
typedef void(APIENTRYP PFNGLVERTEXATTRIBL2I64VNVPROC)(GLuint index, const GLint64EXT* v);
typedef void(APIENTRYP PFNGLVERTEXATTRIBL3I64VNVPROC)(GLuint index, const GLint64EXT* v);
typedef void(APIENTRYP PFNGLVERTEXATTRIBL4I64VNVPROC)(GLuint index, const GLint64EXT* v);
typedef void(APIENTRYP PFNGLVERTEXATTRIBL1UI64NVPROC)(GLuint index, GLuint64EXT x);
typedef void(APIENTRYP PFNGLVERTEXATTRIBL2UI64NVPROC)(GLuint index, GLuint64EXT x, GLuint64EXT y);
typedef void(APIENTRYP PFNGLVERTEXATTRIBL3UI64NVPROC)(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
typedef void(
APIENTRYP PFNGLVERTEXATTRIBL4UI64NVPROC)(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
typedef void(APIENTRYP PFNGLVERTEXATTRIBL1UI64VNVPROC)(GLuint index, const GLuint64EXT* v);
typedef void(APIENTRYP PFNGLVERTEXATTRIBL2UI64VNVPROC)(GLuint index, const GLuint64EXT* v);
typedef void(APIENTRYP PFNGLVERTEXATTRIBL3UI64VNVPROC)(GLuint index, const GLuint64EXT* v);
typedef void(APIENTRYP PFNGLVERTEXATTRIBL4UI64VNVPROC)(GLuint index, const GLuint64EXT* v);
typedef void(APIENTRYP PFNGLGETVERTEXATTRIBLI64VNVPROC)(GLuint index, GLenum pname, GLint64EXT* params);
typedef void(APIENTRYP PFNGLGETVERTEXATTRIBLUI64VNVPROC)(GLuint index, GLenum pname, GLuint64EXT* params);
typedef void(APIENTRYP PFNGLVERTEXATTRIBLFORMATNVPROC)(GLuint index, GLint size, GLenum type, GLsizei stride);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glVertexAttribL1i64NV(GLuint index, GLint64EXT x);
GLAPI void APIENTRY glVertexAttribL2i64NV(GLuint index, GLint64EXT x, GLint64EXT y);
GLAPI void APIENTRY glVertexAttribL3i64NV(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z);
GLAPI void APIENTRY glVertexAttribL4i64NV(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
GLAPI void APIENTRY glVertexAttribL1i64vNV(GLuint index, const GLint64EXT* v);
GLAPI void APIENTRY glVertexAttribL2i64vNV(GLuint index, const GLint64EXT* v);
GLAPI void APIENTRY glVertexAttribL3i64vNV(GLuint index, const GLint64EXT* v);
GLAPI void APIENTRY glVertexAttribL4i64vNV(GLuint index, const GLint64EXT* v);
GLAPI void APIENTRY glVertexAttribL1ui64NV(GLuint index, GLuint64EXT x);
GLAPI void APIENTRY glVertexAttribL2ui64NV(GLuint index, GLuint64EXT x, GLuint64EXT y);
GLAPI void APIENTRY glVertexAttribL3ui64NV(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
GLAPI void APIENTRY glVertexAttribL4ui64NV(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
GLAPI void APIENTRY glVertexAttribL1ui64vNV(GLuint index, const GLuint64EXT* v);
GLAPI void APIENTRY glVertexAttribL2ui64vNV(GLuint index, const GLuint64EXT* v);
GLAPI void APIENTRY glVertexAttribL3ui64vNV(GLuint index, const GLuint64EXT* v);
GLAPI void APIENTRY glVertexAttribL4ui64vNV(GLuint index, const GLuint64EXT* v);
GLAPI void APIENTRY glGetVertexAttribLi64vNV(GLuint index, GLenum pname, GLint64EXT* params);
GLAPI void APIENTRY glGetVertexAttribLui64vNV(GLuint index, GLenum pname, GLuint64EXT* params);
GLAPI void APIENTRY glVertexAttribLFormatNV(GLuint index, GLint size, GLenum type, GLsizei stride);
#endif
#endif /* GL_NV_vertex_attrib_integer_64bit */

#ifndef GL_NV_vertex_buffer_unified_memory
#define GL_NV_vertex_buffer_unified_memory 1
#define GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV 0x8F1E
#define GL_ELEMENT_ARRAY_UNIFIED_NV 0x8F1F
#define GL_VERTEX_ATTRIB_ARRAY_ADDRESS_NV 0x8F20
#define GL_VERTEX_ARRAY_ADDRESS_NV 0x8F21
#define GL_NORMAL_ARRAY_ADDRESS_NV 0x8F22
#define GL_COLOR_ARRAY_ADDRESS_NV 0x8F23
#define GL_INDEX_ARRAY_ADDRESS_NV 0x8F24
#define GL_TEXTURE_COORD_ARRAY_ADDRESS_NV 0x8F25
#define GL_EDGE_FLAG_ARRAY_ADDRESS_NV 0x8F26
#define GL_SECONDARY_COLOR_ARRAY_ADDRESS_NV 0x8F27
#define GL_FOG_COORD_ARRAY_ADDRESS_NV 0x8F28
#define GL_ELEMENT_ARRAY_ADDRESS_NV 0x8F29
#define GL_VERTEX_ATTRIB_ARRAY_LENGTH_NV 0x8F2A
#define GL_VERTEX_ARRAY_LENGTH_NV 0x8F2B
#define GL_NORMAL_ARRAY_LENGTH_NV 0x8F2C
#define GL_COLOR_ARRAY_LENGTH_NV 0x8F2D
#define GL_INDEX_ARRAY_LENGTH_NV 0x8F2E
#define GL_TEXTURE_COORD_ARRAY_LENGTH_NV 0x8F2F
#define GL_EDGE_FLAG_ARRAY_LENGTH_NV 0x8F30
#define GL_SECONDARY_COLOR_ARRAY_LENGTH_NV 0x8F31
#define GL_FOG_COORD_ARRAY_LENGTH_NV 0x8F32
#define GL_ELEMENT_ARRAY_LENGTH_NV 0x8F33
#define GL_DRAW_INDIRECT_UNIFIED_NV 0x8F40
#define GL_DRAW_INDIRECT_ADDRESS_NV 0x8F41
#define GL_DRAW_INDIRECT_LENGTH_NV 0x8F42
typedef void(APIENTRYP PFNGLBUFFERADDRESSRANGENVPROC)(GLenum pname,
                                                      GLuint index,
                                                      GLuint64EXT address,
                                                      GLsizeiptr length);
typedef void(APIENTRYP PFNGLVERTEXFORMATNVPROC)(GLint size, GLenum type, GLsizei stride);
typedef void(APIENTRYP PFNGLNORMALFORMATNVPROC)(GLenum type, GLsizei stride);
typedef void(APIENTRYP PFNGLCOLORFORMATNVPROC)(GLint size, GLenum type, GLsizei stride);
typedef void(APIENTRYP PFNGLINDEXFORMATNVPROC)(GLenum type, GLsizei stride);
typedef void(APIENTRYP PFNGLTEXCOORDFORMATNVPROC)(GLint size, GLenum type, GLsizei stride);
typedef void(APIENTRYP PFNGLEDGEFLAGFORMATNVPROC)(GLsizei stride);
typedef void(APIENTRYP PFNGLSECONDARYCOLORFORMATNVPROC)(GLint size, GLenum type, GLsizei stride);
typedef void(APIENTRYP PFNGLFOGCOORDFORMATNVPROC)(GLenum type, GLsizei stride);
typedef void(
APIENTRYP PFNGLVERTEXATTRIBFORMATNVPROC)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride);
typedef void(APIENTRYP PFNGLVERTEXATTRIBIFORMATNVPROC)(GLuint index, GLint size, GLenum type, GLsizei stride);
typedef void(APIENTRYP PFNGLGETINTEGERUI64I_VNVPROC)(GLenum value, GLuint index, GLuint64EXT* result);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glBufferAddressRangeNV(GLenum pname, GLuint index, GLuint64EXT address, GLsizeiptr length);
GLAPI void APIENTRY glVertexFormatNV(GLint size, GLenum type, GLsizei stride);
GLAPI void APIENTRY glNormalFormatNV(GLenum type, GLsizei stride);
GLAPI void APIENTRY glColorFormatNV(GLint size, GLenum type, GLsizei stride);
GLAPI void APIENTRY glIndexFormatNV(GLenum type, GLsizei stride);
GLAPI void APIENTRY glTexCoordFormatNV(GLint size, GLenum type, GLsizei stride);
GLAPI void APIENTRY glEdgeFlagFormatNV(GLsizei stride);
GLAPI void APIENTRY glSecondaryColorFormatNV(GLint size, GLenum type, GLsizei stride);
GLAPI void APIENTRY glFogCoordFormatNV(GLenum type, GLsizei stride);
GLAPI void APIENTRY glVertexAttribFormatNV(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride);
GLAPI void APIENTRY glVertexAttribIFormatNV(GLuint index, GLint size, GLenum type, GLsizei stride);
GLAPI void APIENTRY glGetIntegerui64i_vNV(GLenum value, GLuint index, GLuint64EXT* result);
#endif
#endif /* GL_NV_vertex_buffer_unified_memory */

#ifndef GL_NV_viewport_array2
#define GL_NV_viewport_array2 1
#endif /* GL_NV_viewport_array2 */

#ifndef GL_NV_viewport_swizzle
#define GL_NV_viewport_swizzle 1
#define GL_VIEWPORT_SWIZZLE_POSITIVE_X_NV 0x9350
#define GL_VIEWPORT_SWIZZLE_NEGATIVE_X_NV 0x9351
#define GL_VIEWPORT_SWIZZLE_POSITIVE_Y_NV 0x9352
#define GL_VIEWPORT_SWIZZLE_NEGATIVE_Y_NV 0x9353
#define GL_VIEWPORT_SWIZZLE_POSITIVE_Z_NV 0x9354
#define GL_VIEWPORT_SWIZZLE_NEGATIVE_Z_NV 0x9355
#define GL_VIEWPORT_SWIZZLE_POSITIVE_W_NV 0x9356
#define GL_VIEWPORT_SWIZZLE_NEGATIVE_W_NV 0x9357
#define GL_VIEWPORT_SWIZZLE_X_NV 0x9358
#define GL_VIEWPORT_SWIZZLE_Y_NV 0x9359
#define GL_VIEWPORT_SWIZZLE_Z_NV 0x935A
#define GL_VIEWPORT_SWIZZLE_W_NV 0x935B
typedef void(
APIENTRYP PFNGLVIEWPORTSWIZZLENVPROC)(GLuint index, GLenum swizzlex, GLenum swizzley, GLenum swizzlez, GLenum swizzlew);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY
glViewportSwizzleNV(GLuint index, GLenum swizzlex, GLenum swizzley, GLenum swizzlez, GLenum swizzlew);
#endif
#endif /* GL_NV_viewport_swizzle */

#ifndef GL_OVR_multiview
#define GL_OVR_multiview 1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_NUM_VIEWS_OVR 0x9630
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_BASE_VIEW_INDEX_OVR 0x9632
#define GL_MAX_VIEWS_OVR 0x9631
#define GL_FRAMEBUFFER_INCOMPLETE_VIEW_TARGETS_OVR 0x9633
typedef void(APIENTRYP PFNGLFRAMEBUFFERTEXTUREMULTIVIEWOVRPROC)(GLenum target,
                                                                GLenum attachment,
                                                                GLuint texture,
                                                                GLint level,
                                                                GLint baseViewIndex,
                                                                GLsizei numViews);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glFramebufferTextureMultiviewOVR(GLenum target,
                                                     GLenum attachment,
                                                     GLuint texture,
                                                     GLint level,
                                                     GLint baseViewIndex,
                                                     GLsizei numViews);
#endif
#endif /* GL_OVR_multiview */

#ifndef GL_OVR_multiview2
#define GL_OVR_multiview2 1
#endif /* GL_OVR_multiview2 */

#ifdef __cplusplus
}
#endif

#endif
