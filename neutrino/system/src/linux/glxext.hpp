#ifndef FRAMEWORK_SYSTEM_SRC_LINUX_GLXEXT_HPP
#define FRAMEWORK_SYSTEM_SRC_LINUX_GLXEXT_HPP

#include <functional>

#include <GL/glx.h>

namespace framework::system::details::glx
{

#pragma region GLX_3DFX_multisample

constexpr int GLX_SAMPLE_BUFFERS_3DFX = 0x8050;
constexpr int GLX_SAMPLES_3DFX        = 0x8051;

#pragma endregion

#pragma region GLX_AMD_gpu_association

typedef struct __GLXcontextRec* GLXContext;

constexpr int GLX_GPU_VENDOR_AMD                = 0x1F00;
constexpr int GLX_GPU_RENDERER_STRING_AMD       = 0x1F01;
constexpr int GLX_GPU_OPENGL_VERSION_STRING_AMD = 0x1F02;
constexpr int GLX_GPU_FASTEST_TARGET_GPUS_AMD   = 0x21A2;
constexpr int GLX_GPU_RAM_AMD                   = 0x21A3;
constexpr int GLX_GPU_CLOCK_AMD                 = 0x21A4;
constexpr int GLX_GPU_NUM_PIPES_AMD             = 0x21A5;
constexpr int GLX_GPU_NUM_SIMD_AMD              = 0x21A6;
constexpr int GLX_GPU_NUM_RB_AMD                = 0x21A7;
constexpr int GLX_GPU_NUM_SPI_AMD               = 0x21A8;

unsigned int glXGetGPUIDsAMD(unsigned int maxCount, unsigned int* ids);
int glXGetGPUInfoAMD(unsigned int id, int property, GLenum dataType, unsigned int size, void* data);
unsigned int glXGetContextGPUIDAMD(GLXContext ctx);
GLXContext glXCreateAssociatedContextAMD(unsigned int id, GLXContext share_list);
GLXContext glXCreateAssociatedContextAttribsAMD(unsigned int id, GLXContext share_context, const int* attribList);
Bool glXDeleteAssociatedContextAMD(GLXContext ctx);
Bool glXMakeAssociatedContextCurrentAMD(GLXContext ctx);
GLXContext glXGetCurrentAssociatedContextAMD();
void glXBlitContextFramebufferAMD(GLXContext dstCtx,
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

#pragma region GLX_ARB_context_flush_control

constexpr int GLX_CONTEXT_RELEASE_BEHAVIOR_ARB       = 0x2097;
constexpr int GLX_CONTEXT_RELEASE_BEHAVIOR_NONE_ARB  = 0;
constexpr int GLX_CONTEXT_RELEASE_BEHAVIOR_FLUSH_ARB = 0x2098;

#pragma endregion

#pragma region GLX_ARB_create_context

typedef struct __GLXFBConfigRec* GLXFBConfig;

constexpr int GLX_CONTEXT_DEBUG_BIT_ARB              = 0x00000001;
constexpr int GLX_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB = 0x00000002;
constexpr int GLX_CONTEXT_MAJOR_VERSION_ARB          = 0x2091;
constexpr int GLX_CONTEXT_MINOR_VERSION_ARB          = 0x2092;
constexpr int GLX_CONTEXT_FLAGS_ARB                  = 0x2094;

GLXContext glXCreateContextAttribsARB(Display* dpy,
                                      GLXFBConfig config,
                                      GLXContext share_context,
                                      Bool direct,
                                      const int* attrib_list);

#pragma endregion

#pragma region GLX_ARB_create_context_no_error

constexpr int GLX_CONTEXT_OPENGL_NO_ERROR_ARB = 0x31B3;

#pragma endregion

#pragma region GLX_ARB_create_context_profile

constexpr int GLX_CONTEXT_CORE_PROFILE_BIT_ARB          = 0x00000001;
constexpr int GLX_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB = 0x00000002;
constexpr int GLX_CONTEXT_PROFILE_MASK_ARB              = 0x9126;

#pragma endregion

#pragma region GLX_ARB_create_context_robustness

constexpr int GLX_CONTEXT_ROBUST_ACCESS_BIT_ARB           = 0x00000004;
constexpr int GLX_LOSE_CONTEXT_ON_RESET_ARB               = 0x8252;
constexpr int GLX_CONTEXT_RESET_NOTIFICATION_STRATEGY_ARB = 0x8256;
constexpr int GLX_NO_RESET_NOTIFICATION_ARB               = 0x8261;

#pragma endregion

#pragma region GLX_ARB_fbconfig_float

constexpr int GLX_RGBA_FLOAT_TYPE_ARB = 0x20B9;
constexpr int GLX_RGBA_FLOAT_BIT_ARB  = 0x00000004;

#pragma endregion

#pragma region GLX_ARB_framebuffer_sRGB

constexpr int GLX_FRAMEBUFFER_SRGB_CAPABLE_ARB = 0x20B2;

#pragma endregion

#pragma region GLX_ARB_get_proc_address

typedef void (*__GLXextFuncPtr)(void);

__GLXextFuncPtr glXGetProcAddressARB(const GLubyte* procName);

#pragma endregion

#pragma region GLX_ARB_multisample

constexpr int GLX_SAMPLE_BUFFERS_ARB = 100000;
constexpr int GLX_SAMPLES_ARB        = 100001;

#pragma endregion

#pragma region GLX_ARB_robustness_application_isolation

constexpr int GLX_CONTEXT_RESET_ISOLATION_BIT_ARB = 0x00000008;

#pragma endregion

#pragma region GLX_ARB_robustness_share_group_isolation

#pragma endregion

#pragma region GLX_ARB_vertex_buffer_object

constexpr int GLX_CONTEXT_ALLOW_BUFFER_BYTE_ORDER_MISMATCH_ARB = 0x2095;

#pragma endregion

#pragma region GLX_EXT_buffer_age

constexpr int GLX_BACK_BUFFER_AGE_EXT = 0x20F4;

#pragma endregion

#pragma region GLX_EXT_context_priority

constexpr int GLX_CONTEXT_PRIORITY_LEVEL_EXT  = 0x3100;
constexpr int GLX_CONTEXT_PRIORITY_HIGH_EXT   = 0x3101;
constexpr int GLX_CONTEXT_PRIORITY_MEDIUM_EXT = 0x3102;
constexpr int GLX_CONTEXT_PRIORITY_LOW_EXT    = 0x3103;

#pragma endregion

#pragma region GLX_EXT_create_context_es_profile

constexpr int GLX_CONTEXT_ES_PROFILE_BIT_EXT = 0x00000004;

#pragma endregion

#pragma region GLX_EXT_create_context_es2_profile

constexpr int GLX_CONTEXT_ES2_PROFILE_BIT_EXT = 0x00000004;

#pragma endregion

#pragma region GLX_EXT_fbconfig_packed_float

constexpr int GLX_RGBA_UNSIGNED_FLOAT_TYPE_EXT = 0x20B1;
constexpr int GLX_RGBA_UNSIGNED_FLOAT_BIT_EXT  = 0x00000008;

#pragma endregion

#pragma region GLX_EXT_framebuffer_sRGB

constexpr int GLX_FRAMEBUFFER_SRGB_CAPABLE_EXT = 0x20B2;

#pragma endregion

#pragma region GLX_EXT_get_drawable_type

constexpr int GLX_DRAWABLE_TYPE = 0x8010;

#pragma endregion

#pragma region GLX_EXT_import_context

typedef XID GLXContextID;

constexpr int GLX_SHARE_CONTEXT_EXT = 0x800A;
constexpr int GLX_VISUAL_ID_EXT     = 0x800B;
constexpr int GLX_SCREEN_EXT        = 0x800C;

Display* glXGetCurrentDisplayEXT();
int glXQueryContextInfoEXT(Display* dpy, GLXContext context, int attribute, int* value);
GLXContextID glXGetContextIDEXT(const GLXContext context);
GLXContext glXImportContextEXT(Display* dpy, GLXContextID contextID);
void glXFreeContextEXT(Display* dpy, GLXContext context);

#pragma endregion

#pragma region GLX_EXT_libglvnd

constexpr int GLX_VENDOR_NAMES_EXT = 0x20F6;

#pragma endregion

#pragma region GLX_EXT_no_config_context

#pragma endregion

#pragma region GLX_EXT_stereo_tree

typedef struct
{
    int type;
    unsigned long serial;
    Bool send_event;
    Display* display;
    int extension;
    int evtype;
    GLXDrawable window;
    Bool stereo_tree;
} GLXStereoNotifyEventEXT;

constexpr int GLX_STEREO_TREE_EXT        = 0x20F5;
constexpr int GLX_STEREO_NOTIFY_MASK_EXT = 0x00000001;
constexpr int GLX_STEREO_NOTIFY_EXT      = 0x00000000;

#pragma endregion

#pragma region GLX_EXT_swap_control

typedef XID GLXDrawable;

constexpr int GLX_SWAP_INTERVAL_EXT     = 0x20F1;
constexpr int GLX_MAX_SWAP_INTERVAL_EXT = 0x20F2;

void glXSwapIntervalEXT(Display* dpy, GLXDrawable drawable, int interval);

#pragma endregion

#pragma region GLX_EXT_swap_control_tear

constexpr int GLX_LATE_SWAPS_TEAR_EXT = 0x20F3;

#pragma endregion

#pragma region GLX_EXT_texture_from_pixmap

constexpr int GLX_TEXTURE_1D_BIT_EXT          = 0x00000001;
constexpr int GLX_TEXTURE_2D_BIT_EXT          = 0x00000002;
constexpr int GLX_TEXTURE_RECTANGLE_BIT_EXT   = 0x00000004;
constexpr int GLX_BIND_TO_TEXTURE_RGB_EXT     = 0x20D0;
constexpr int GLX_BIND_TO_TEXTURE_RGBA_EXT    = 0x20D1;
constexpr int GLX_BIND_TO_MIPMAP_TEXTURE_EXT  = 0x20D2;
constexpr int GLX_BIND_TO_TEXTURE_TARGETS_EXT = 0x20D3;
constexpr int GLX_Y_INVERTED_EXT              = 0x20D4;
constexpr int GLX_TEXTURE_FORMAT_EXT          = 0x20D5;
constexpr int GLX_TEXTURE_TARGET_EXT          = 0x20D6;
constexpr int GLX_MIPMAP_TEXTURE_EXT          = 0x20D7;
constexpr int GLX_TEXTURE_FORMAT_NONE_EXT     = 0x20D8;
constexpr int GLX_TEXTURE_FORMAT_RGB_EXT      = 0x20D9;
constexpr int GLX_TEXTURE_FORMAT_RGBA_EXT     = 0x20DA;
constexpr int GLX_TEXTURE_1D_EXT              = 0x20DB;
constexpr int GLX_TEXTURE_2D_EXT              = 0x20DC;
constexpr int GLX_TEXTURE_RECTANGLE_EXT       = 0x20DD;
constexpr int GLX_FRONT_LEFT_EXT              = 0x20DE;
constexpr int GLX_FRONT_RIGHT_EXT             = 0x20DF;
constexpr int GLX_BACK_LEFT_EXT               = 0x20E0;
constexpr int GLX_BACK_RIGHT_EXT              = 0x20E1;
constexpr int GLX_FRONT_EXT                   = 0x20DE;
constexpr int GLX_BACK_EXT                    = 0x20E0;
constexpr int GLX_AUX0_EXT                    = 0x20E2;
constexpr int GLX_AUX1_EXT                    = 0x20E3;
constexpr int GLX_AUX2_EXT                    = 0x20E4;
constexpr int GLX_AUX3_EXT                    = 0x20E5;
constexpr int GLX_AUX4_EXT                    = 0x20E6;
constexpr int GLX_AUX5_EXT                    = 0x20E7;
constexpr int GLX_AUX6_EXT                    = 0x20E8;
constexpr int GLX_AUX7_EXT                    = 0x20E9;
constexpr int GLX_AUX8_EXT                    = 0x20EA;
constexpr int GLX_AUX9_EXT                    = 0x20EB;

void glXBindTexImageEXT(Display* dpy, GLXDrawable drawable, int buffer, const int* attrib_list);
void glXReleaseTexImageEXT(Display* dpy, GLXDrawable drawable, int buffer);

#pragma endregion

#pragma region GLX_EXT_visual_info

constexpr int GLX_X_VISUAL_TYPE_EXT           = 0x22;
constexpr int GLX_TRANSPARENT_TYPE_EXT        = 0x23;
constexpr int GLX_TRANSPARENT_INDEX_VALUE_EXT = 0x24;
constexpr int GLX_TRANSPARENT_RED_VALUE_EXT   = 0x25;
constexpr int GLX_TRANSPARENT_GREEN_VALUE_EXT = 0x26;
constexpr int GLX_TRANSPARENT_BLUE_VALUE_EXT  = 0x27;
constexpr int GLX_TRANSPARENT_ALPHA_VALUE_EXT = 0x28;
constexpr int GLX_NONE_EXT                    = 0x8000;
constexpr int GLX_TRUE_COLOR_EXT              = 0x8002;
constexpr int GLX_DIRECT_COLOR_EXT            = 0x8003;
constexpr int GLX_PSEUDO_COLOR_EXT            = 0x8004;
constexpr int GLX_STATIC_COLOR_EXT            = 0x8005;
constexpr int GLX_GRAY_SCALE_EXT              = 0x8006;
constexpr int GLX_STATIC_GRAY_EXT             = 0x8007;
constexpr int GLX_TRANSPARENT_RGB_EXT         = 0x8008;
constexpr int GLX_TRANSPARENT_INDEX_EXT       = 0x8009;

#pragma endregion

#pragma region GLX_EXT_visual_rating

constexpr int GLX_VISUAL_CAVEAT_EXT         = 0x20;
constexpr int GLX_SLOW_VISUAL_EXT           = 0x8001;
constexpr int GLX_NON_CONFORMANT_VISUAL_EXT = 0x800D;

#pragma endregion

#pragma region GLX_INTEL_swap_event

constexpr int GLX_BUFFER_SWAP_COMPLETE_INTEL_MASK = 0x04000000;
constexpr int GLX_EXCHANGE_COMPLETE_INTEL         = 0x8180;
constexpr int GLX_COPY_COMPLETE_INTEL             = 0x8181;
constexpr int GLX_FLIP_COMPLETE_INTEL             = 0x8182;

#pragma endregion

#pragma region GLX_MESA_agp_offset

unsigned int glXGetAGPOffsetMESA(const void* pointer);

#pragma endregion

#pragma region GLX_MESA_copy_sub_buffer

void glXCopySubBufferMESA(Display* dpy, GLXDrawable drawable, int x, int y, int width, int height);

#pragma endregion

#pragma region GLX_MESA_pixmap_colormap

typedef XID GLXPixmap;

GLXPixmap glXCreateGLXPixmapMESA(Display* dpy, XVisualInfo* visual, Pixmap pixmap, Colormap cmap);

#pragma endregion

#pragma region GLX_MESA_query_renderer

constexpr int GLX_RENDERER_VENDOR_ID_MESA                            = 0x8183;
constexpr int GLX_RENDERER_DEVICE_ID_MESA                            = 0x8184;
constexpr int GLX_RENDERER_VERSION_MESA                              = 0x8185;
constexpr int GLX_RENDERER_ACCELERATED_MESA                          = 0x8186;
constexpr int GLX_RENDERER_VIDEO_MEMORY_MESA                         = 0x8187;
constexpr int GLX_RENDERER_UNIFIED_MEMORY_ARCHITECTURE_MESA          = 0x8188;
constexpr int GLX_RENDERER_PREFERRED_PROFILE_MESA                    = 0x8189;
constexpr int GLX_RENDERER_OPENGL_CORE_PROFILE_VERSION_MESA          = 0x818A;
constexpr int GLX_RENDERER_OPENGL_COMPATIBILITY_PROFILE_VERSION_MESA = 0x818B;
constexpr int GLX_RENDERER_OPENGL_ES_PROFILE_VERSION_MESA            = 0x818C;
constexpr int GLX_RENDERER_OPENGL_ES2_PROFILE_VERSION_MESA           = 0x818D;

Bool glXQueryCurrentRendererIntegerMESA(int attribute, unsigned int* value);
const char* glXQueryCurrentRendererStringMESA(int attribute);
Bool glXQueryRendererIntegerMESA(Display* dpy, int screen, int renderer, int attribute, unsigned int* value);
const char* glXQueryRendererStringMESA(Display* dpy, int screen, int renderer, int attribute);

#pragma endregion

#pragma region GLX_MESA_release_buffers

Bool glXReleaseBuffersMESA(Display* dpy, GLXDrawable drawable);

#pragma endregion

#pragma region GLX_MESA_set_3dfx_mode

constexpr int GLX_3DFX_WINDOW_MODE_MESA     = 0x1;
constexpr int GLX_3DFX_FULLSCREEN_MODE_MESA = 0x2;

GLboolean glXSet3DfxModeMESA(GLint mode);

#pragma endregion

#pragma region GLX_MESA_swap_control

int glXGetSwapIntervalMESA();
int glXSwapIntervalMESA(unsigned int interval);

#pragma endregion

#pragma region GLX_NV_copy_buffer

void glXCopyBufferSubDataNV(Display* dpy,
                            GLXContext readCtx,
                            GLXContext writeCtx,
                            GLenum readTarget,
                            GLenum writeTarget,
                            GLintptr readOffset,
                            GLintptr writeOffset,
                            GLsizeiptr size);
void glXNamedCopyBufferSubDataNV(Display* dpy,
                                 GLXContext readCtx,
                                 GLXContext writeCtx,
                                 GLuint readBuffer,
                                 GLuint writeBuffer,
                                 GLintptr readOffset,
                                 GLintptr writeOffset,
                                 GLsizeiptr size);

#pragma endregion

#pragma region GLX_NV_copy_image

void glXCopyImageSubDataNV(Display* dpy,
                           GLXContext srcCtx,
                           GLuint srcName,
                           GLenum srcTarget,
                           GLint srcLevel,
                           GLint srcX,
                           GLint srcY,
                           GLint srcZ,
                           GLXContext dstCtx,
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

#pragma region GLX_NV_delay_before_swap

Bool glXDelayBeforeSwapNV(Display* dpy, GLXDrawable drawable, GLfloat seconds);

#pragma endregion

#pragma region GLX_NV_float_buffer

constexpr int GLX_FLOAT_COMPONENTS_NV = 0x20B0;

#pragma endregion

#pragma region GLX_NV_multisample_coverage

constexpr int GLX_COVERAGE_SAMPLES_NV = 100001;
constexpr int GLX_COLOR_SAMPLES_NV    = 0x20B3;

#pragma endregion

#pragma region GLX_NV_present_video

constexpr int GLX_NUM_VIDEO_SLOTS_NV = 0x20F0;

unsigned int* glXEnumerateVideoDevicesNV(Display* dpy, int screen, int* nelements);
int glXBindVideoDeviceNV(Display* dpy, unsigned int video_slot, unsigned int video_device, const int* attrib_list);

#pragma endregion

#pragma region GLX_NV_robustness_video_memory_purge

constexpr int GLX_GENERATE_RESET_ON_VIDEO_MEMORY_PURGE_NV = 0x20F7;

#pragma endregion

#pragma region GLX_NV_swap_group

Bool glXJoinSwapGroupNV(Display* dpy, GLXDrawable drawable, GLuint group);
Bool glXBindSwapBarrierNV(Display* dpy, GLuint group, GLuint barrier);
Bool glXQuerySwapGroupNV(Display* dpy, GLXDrawable drawable, GLuint* group, GLuint* barrier);
Bool glXQueryMaxSwapGroupsNV(Display* dpy, int screen, GLuint* maxGroups, GLuint* maxBarriers);
Bool glXQueryFrameCountNV(Display* dpy, int screen, GLuint* count);
Bool glXResetFrameCountNV(Display* dpy, int screen);

#pragma endregion

#pragma region GLX_NV_video_capture

typedef XID GLXVideoCaptureDeviceNV;

constexpr int GLX_DEVICE_ID_NV               = 0x20CD;
constexpr int GLX_UNIQUE_ID_NV               = 0x20CE;
constexpr int GLX_NUM_VIDEO_CAPTURE_SLOTS_NV = 0x20CF;

int glXBindVideoCaptureDeviceNV(Display* dpy, unsigned int video_capture_slot, GLXVideoCaptureDeviceNV device);
GLXVideoCaptureDeviceNV* glXEnumerateVideoCaptureDevicesNV(Display* dpy, int screen, int* nelements);
void glXLockVideoCaptureDeviceNV(Display* dpy, GLXVideoCaptureDeviceNV device);
int glXQueryVideoCaptureDeviceNV(Display* dpy, GLXVideoCaptureDeviceNV device, int attribute, int* value);
void glXReleaseVideoCaptureDeviceNV(Display* dpy, GLXVideoCaptureDeviceNV device);

#pragma endregion

#pragma region GLX_NV_video_out

typedef unsigned int GLXVideoDeviceNV;
typedef XID GLXPbuffer;

constexpr int GLX_VIDEO_OUT_COLOR_NV              = 0x20C3;
constexpr int GLX_VIDEO_OUT_ALPHA_NV              = 0x20C4;
constexpr int GLX_VIDEO_OUT_DEPTH_NV              = 0x20C5;
constexpr int GLX_VIDEO_OUT_COLOR_AND_ALPHA_NV    = 0x20C6;
constexpr int GLX_VIDEO_OUT_COLOR_AND_DEPTH_NV    = 0x20C7;
constexpr int GLX_VIDEO_OUT_FRAME_NV              = 0x20C8;
constexpr int GLX_VIDEO_OUT_FIELD_1_NV            = 0x20C9;
constexpr int GLX_VIDEO_OUT_FIELD_2_NV            = 0x20CA;
constexpr int GLX_VIDEO_OUT_STACKED_FIELDS_1_2_NV = 0x20CB;
constexpr int GLX_VIDEO_OUT_STACKED_FIELDS_2_1_NV = 0x20CC;

int glXGetVideoDeviceNV(Display* dpy, int screen, int numVideoDevices, GLXVideoDeviceNV* pVideoDevice);
int glXReleaseVideoDeviceNV(Display* dpy, int screen, GLXVideoDeviceNV VideoDevice);
int glXBindVideoImageNV(Display* dpy, GLXVideoDeviceNV VideoDevice, GLXPbuffer pbuf, int iVideoBuffer);
int glXReleaseVideoImageNV(Display* dpy, GLXPbuffer pbuf);
int glXSendPbufferToVideoNV(Display* dpy,
                            GLXPbuffer pbuf,
                            int iBufferType,
                            unsigned long* pulCounterPbuffer,
                            GLboolean bBlock);
int glXGetVideoInfoNV(Display* dpy,
                      int screen,
                      GLXVideoDeviceNV VideoDevice,
                      unsigned long* pulCounterOutputPbuffer,
                      unsigned long* pulCounterOutputVideo);

#pragma endregion

#pragma region GLX_OML_swap_method

constexpr int GLX_SWAP_METHOD_OML    = 0x8060;
constexpr int GLX_SWAP_EXCHANGE_OML  = 0x8061;
constexpr int GLX_SWAP_COPY_OML      = 0x8062;
constexpr int GLX_SWAP_UNDEFINED_OML = 0x8063;

#pragma endregion

#pragma region GLX_OML_sync_control

Bool glXGetSyncValuesOML(Display* dpy, GLXDrawable drawable, int64_t* ust, int64_t* msc, int64_t* sbc);
Bool glXGetMscRateOML(Display* dpy, GLXDrawable drawable, int32_t* numerator, int32_t* denominator);
int64_t glXSwapBuffersMscOML(Display* dpy, GLXDrawable drawable, int64_t target_msc, int64_t divisor, int64_t remainder);
Bool glXWaitForMscOML(Display* dpy,
                      GLXDrawable drawable,
                      int64_t target_msc,
                      int64_t divisor,
                      int64_t remainder,
                      int64_t* ust,
                      int64_t* msc,
                      int64_t* sbc);
Bool glXWaitForSbcOML(Display* dpy, GLXDrawable drawable, int64_t target_sbc, int64_t* ust, int64_t* msc, int64_t* sbc);

#pragma endregion

#pragma region GLX_SGI_cushion

void glXCushionSGI(Display* dpy, Window window, float cushion);

#pragma endregion

#pragma region GLX_SGI_make_current_read

Bool glXMakeCurrentReadSGI(Display* dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx);
GLXDrawable glXGetCurrentReadDrawableSGI();

#pragma endregion

#pragma region GLX_SGI_swap_control

int glXSwapIntervalSGI(int interval);

#pragma endregion

#pragma region GLX_SGI_video_sync

int glXGetVideoSyncSGI(unsigned int* count);
int glXWaitVideoSyncSGI(int divisor, int remainder, unsigned int* count);

#pragma endregion

#pragma region GLX_SGIS_blended_overlay

constexpr int GLX_BLENDED_RGBA_SGIS = 0x8025;

#pragma endregion

#pragma region GLX_SGIS_multisample

constexpr int GLX_SAMPLE_BUFFERS_SGIS = 100000;
constexpr int GLX_SAMPLES_SGIS        = 100001;

#pragma endregion

#pragma region GLX_SGIS_shared_multisample

constexpr int GLX_MULTISAMPLE_SUB_RECT_WIDTH_SGIS  = 0x8026;
constexpr int GLX_MULTISAMPLE_SUB_RECT_HEIGHT_SGIS = 0x8027;

#pragma endregion

#pragma region GLX_SGIX_dmbuffer

typedef XID GLXPbufferSGIX;

constexpr int GLX_DIGITAL_MEDIA_PBUFFER_SGIX = 0x8024;

Bool glXAssociateDMPbufferSGIX(Display* dpy, GLXPbufferSGIX pbuffer, DMparams* params, DMbuffer dmbuffer);

#pragma endregion

#pragma region GLX_SGIX_fbconfig

typedef struct __GLXFBConfigRec* GLXFBConfigSGIX;

constexpr int GLX_WINDOW_BIT_SGIX       = 0x00000001;
constexpr int GLX_PIXMAP_BIT_SGIX       = 0x00000002;
constexpr int GLX_RGBA_BIT_SGIX         = 0x00000001;
constexpr int GLX_COLOR_INDEX_BIT_SGIX  = 0x00000002;
constexpr int GLX_DRAWABLE_TYPE_SGIX    = 0x8010;
constexpr int GLX_RENDER_TYPE_SGIX      = 0x8011;
constexpr int GLX_X_RENDERABLE_SGIX     = 0x8012;
constexpr int GLX_FBCONFIG_ID_SGIX      = 0x8013;
constexpr int GLX_RGBA_TYPE_SGIX        = 0x8014;
constexpr int GLX_COLOR_INDEX_TYPE_SGIX = 0x8015;

int glXGetFBConfigAttribSGIX(Display* dpy, GLXFBConfigSGIX config, int attribute, int* value);
GLXFBConfigSGIX* glXChooseFBConfigSGIX(Display* dpy, int screen, int* attrib_list, int* nelements);
GLXPixmap glXCreateGLXPixmapWithConfigSGIX(Display* dpy, GLXFBConfigSGIX config, Pixmap pixmap);
GLXContext glXCreateContextWithConfigSGIX(Display* dpy,
                                          GLXFBConfigSGIX config,
                                          int render_type,
                                          GLXContext share_list,
                                          Bool direct);
XVisualInfo* glXGetVisualFromFBConfigSGIX(Display* dpy, GLXFBConfigSGIX config);
GLXFBConfigSGIX glXGetFBConfigFromVisualSGIX(Display* dpy, XVisualInfo* vis);

#pragma endregion

#pragma region GLX_SGIX_hyperpipe

typedef struct
{
    char pipeName[80]; /* Should be [GLX_HYPERPIPE_PIPE_NAME_LENGTH_SGIX] */
    int networkId;
} GLXHyperpipeNetworkSGIX;
typedef struct
{
    char pipeName[80]; /* Should be [GLX_HYPERPIPE_PIPE_NAME_LENGTH_SGIX] */
    int channel;
    unsigned int participationType;
    int timeSlice;
} GLXHyperpipeConfigSGIX;
typedef struct
{
    char pipeName[80]; /* Should be [GLX_HYPERPIPE_PIPE_NAME_LENGTH_SGIX] */
    int srcXOrigin, srcYOrigin, srcWidth, srcHeight;
    int destXOrigin, destYOrigin, destWidth, destHeight;
} GLXPipeRect;
typedef struct
{
    char pipeName[80]; /* Should be [GLX_HYPERPIPE_PIPE_NAME_LENGTH_SGIX] */
    int XOrigin, YOrigin, maxHeight, maxWidth;
} GLXPipeRectLimits;

constexpr int GLX_HYPERPIPE_PIPE_NAME_LENGTH_SGIX = 80;
constexpr int GLX_BAD_HYPERPIPE_CONFIG_SGIX       = 91;
constexpr int GLX_BAD_HYPERPIPE_SGIX              = 92;
constexpr int GLX_HYPERPIPE_DISPLAY_PIPE_SGIX     = 0x00000001;
constexpr int GLX_HYPERPIPE_RENDER_PIPE_SGIX      = 0x00000002;
constexpr int GLX_PIPE_RECT_SGIX                  = 0x00000001;
constexpr int GLX_PIPE_RECT_LIMITS_SGIX           = 0x00000002;
constexpr int GLX_HYPERPIPE_STEREO_SGIX           = 0x00000003;
constexpr int GLX_HYPERPIPE_PIXEL_AVERAGE_SGIX    = 0x00000004;
constexpr int GLX_HYPERPIPE_ID_SGIX               = 0x8030;

GLXHyperpipeNetworkSGIX* glXQueryHyperpipeNetworkSGIX(Display* dpy, int* npipes);
int glXHyperpipeConfigSGIX(Display* dpy, int networkId, int npipes, GLXHyperpipeConfigSGIX* cfg, int* hpId);
GLXHyperpipeConfigSGIX* glXQueryHyperpipeConfigSGIX(Display* dpy, int hpId, int* npipes);
int glXDestroyHyperpipeConfigSGIX(Display* dpy, int hpId);
int glXBindHyperpipeSGIX(Display* dpy, int hpId);
int glXQueryHyperpipeBestAttribSGIX(Display* dpy,
                                    int timeSlice,
                                    int attrib,
                                    int size,
                                    void* attribList,
                                    void* returnAttribList);
int glXHyperpipeAttribSGIX(Display* dpy, int timeSlice, int attrib, int size, void* attribList);
int glXQueryHyperpipeAttribSGIX(Display* dpy, int timeSlice, int attrib, int size, void* returnAttribList);

#pragma endregion

#pragma region GLX_SGIX_pbuffer

constexpr int GLX_PBUFFER_BIT_SGIX            = 0x00000004;
constexpr int GLX_BUFFER_CLOBBER_MASK_SGIX    = 0x08000000;
constexpr int GLX_FRONT_LEFT_BUFFER_BIT_SGIX  = 0x00000001;
constexpr int GLX_FRONT_RIGHT_BUFFER_BIT_SGIX = 0x00000002;
constexpr int GLX_BACK_LEFT_BUFFER_BIT_SGIX   = 0x00000004;
constexpr int GLX_BACK_RIGHT_BUFFER_BIT_SGIX  = 0x00000008;
constexpr int GLX_AUX_BUFFERS_BIT_SGIX        = 0x00000010;
constexpr int GLX_DEPTH_BUFFER_BIT_SGIX       = 0x00000020;
constexpr int GLX_STENCIL_BUFFER_BIT_SGIX     = 0x00000040;
constexpr int GLX_ACCUM_BUFFER_BIT_SGIX       = 0x00000080;
constexpr int GLX_SAMPLE_BUFFERS_BIT_SGIX     = 0x00000100;
constexpr int GLX_MAX_PBUFFER_WIDTH_SGIX      = 0x8016;
constexpr int GLX_MAX_PBUFFER_HEIGHT_SGIX     = 0x8017;
constexpr int GLX_MAX_PBUFFER_PIXELS_SGIX     = 0x8018;
constexpr int GLX_OPTIMAL_PBUFFER_WIDTH_SGIX  = 0x8019;
constexpr int GLX_OPTIMAL_PBUFFER_HEIGHT_SGIX = 0x801A;
constexpr int GLX_PRESERVED_CONTENTS_SGIX     = 0x801B;
constexpr int GLX_LARGEST_PBUFFER_SGIX        = 0x801C;
constexpr int GLX_WIDTH_SGIX                  = 0x801D;
constexpr int GLX_HEIGHT_SGIX                 = 0x801E;
constexpr int GLX_EVENT_MASK_SGIX             = 0x801F;
constexpr int GLX_DAMAGED_SGIX                = 0x8020;
constexpr int GLX_SAVED_SGIX                  = 0x8021;
constexpr int GLX_WINDOW_SGIX                 = 0x8022;
constexpr int GLX_PBUFFER_SGIX                = 0x8023;

GLXPbufferSGIX glXCreateGLXPbufferSGIX(Display* dpy,
                                       GLXFBConfigSGIX config,
                                       unsigned int width,
                                       unsigned int height,
                                       int* attrib_list);
void glXDestroyGLXPbufferSGIX(Display* dpy, GLXPbufferSGIX pbuf);
void glXQueryGLXPbufferSGIX(Display* dpy, GLXPbufferSGIX pbuf, int attribute, unsigned int* value);
void glXSelectEventSGIX(Display* dpy, GLXDrawable drawable, unsigned long mask);
void glXGetSelectedEventSGIX(Display* dpy, GLXDrawable drawable, unsigned long* mask);

#pragma endregion

#pragma region GLX_SGIX_swap_barrier

void glXBindSwapBarrierSGIX(Display* dpy, GLXDrawable drawable, int barrier);
Bool glXQueryMaxSwapBarriersSGIX(Display* dpy, int screen, int* max);

#pragma endregion

#pragma region GLX_SGIX_swap_group

void glXJoinSwapGroupSGIX(Display* dpy, GLXDrawable drawable, GLXDrawable member);

#pragma endregion

#pragma region GLX_SGIX_video_resize

constexpr int GLX_SYNC_FRAME_SGIX = 0x00000000;
constexpr int GLX_SYNC_SWAP_SGIX  = 0x00000001;

int glXBindChannelToWindowSGIX(Display* display, int screen, int channel, Window window);
int glXChannelRectSGIX(Display* display, int screen, int channel, int x, int y, int w, int h);
int glXQueryChannelRectSGIX(Display* display, int screen, int channel, int* dx, int* dy, int* dw, int* dh);
int glXQueryChannelDeltasSGIX(Display* display, int screen, int channel, int* x, int* y, int* w, int* h);
int glXChannelRectSyncSGIX(Display* display, int screen, int channel, GLenum synctype);

#pragma endregion

#pragma region GLX_SGIX_video_source

typedef XID GLXVideoSourceSGIX;

GLXVideoSourceSGIX glXCreateGLXVideoSourceSGIX(Display* display,
                                               int screen,
                                               VLServer server,
                                               VLPath path,
                                               int nodeClass,
                                               VLNode drainNode);
void glXDestroyGLXVideoSourceSGIX(Display* dpy, GLXVideoSourceSGIX glxvideosource);

#pragma endregion

#pragma region GLX_SGIX_visual_select_group

constexpr int GLX_VISUAL_SELECT_GROUP_SGIX = 0x8028;

#pragma endregion

#pragma region GLX_SUN_get_transparent_index

Status glXGetTransparentIndexSUN(Display* dpy, Window overlay, Window underlay, unsigned long* pTransparentIndex);

#pragma endregion

#pragma region GLX_NV_multigpu_context

constexpr int GLX_CONTEXT_MULTIGPU_ATTRIB_NV                         = 0x20AA;
constexpr int GLX_CONTEXT_MULTIGPU_ATTRIB_SINGLE_NV                  = 0x20AB;
constexpr int GLX_CONTEXT_MULTIGPU_ATTRIB_AFR_NV                     = 0x20AC;
constexpr int GLX_CONTEXT_MULTIGPU_ATTRIB_MULTICAST_NV               = 0x20AD;
constexpr int GLX_CONTEXT_MULTIGPU_ATTRIB_MULTI_DISPLAY_MULTICAST_NV = 0x20AE;

#pragma endregion

enum class Feature
{

};

enum class Extension
{
    GLX_3DFX_multisample,
    GLX_AMD_gpu_association,
    GLX_ARB_context_flush_control,
    GLX_ARB_create_context,
    GLX_ARB_create_context_no_error,
    GLX_ARB_create_context_profile,
    GLX_ARB_create_context_robustness,
    GLX_ARB_fbconfig_float,
    GLX_ARB_framebuffer_sRGB,
    GLX_ARB_get_proc_address,
    GLX_ARB_multisample,
    GLX_ARB_robustness_application_isolation,
    GLX_ARB_robustness_share_group_isolation,
    GLX_ARB_vertex_buffer_object,
    GLX_EXT_buffer_age,
    GLX_EXT_context_priority,
    GLX_EXT_create_context_es_profile,
    GLX_EXT_create_context_es2_profile,
    GLX_EXT_fbconfig_packed_float,
    GLX_EXT_framebuffer_sRGB,
    GLX_EXT_get_drawable_type,
    GLX_EXT_import_context,
    GLX_EXT_libglvnd,
    GLX_EXT_no_config_context,
    GLX_EXT_stereo_tree,
    GLX_EXT_swap_control,
    GLX_EXT_swap_control_tear,
    GLX_EXT_texture_from_pixmap,
    GLX_EXT_visual_info,
    GLX_EXT_visual_rating,
    GLX_INTEL_swap_event,
    GLX_MESA_agp_offset,
    GLX_MESA_copy_sub_buffer,
    GLX_MESA_pixmap_colormap,
    GLX_MESA_query_renderer,
    GLX_MESA_release_buffers,
    GLX_MESA_set_3dfx_mode,
    GLX_MESA_swap_control,
    GLX_NV_copy_buffer,
    GLX_NV_copy_image,
    GLX_NV_delay_before_swap,
    GLX_NV_float_buffer,
    GLX_NV_multisample_coverage,
    GLX_NV_present_video,
    GLX_NV_robustness_video_memory_purge,
    GLX_NV_swap_group,
    GLX_NV_video_capture,
    GLX_NV_video_out,
    GLX_OML_swap_method,
    GLX_OML_sync_control,
    GLX_SGI_cushion,
    GLX_SGI_make_current_read,
    GLX_SGI_swap_control,
    GLX_SGI_video_sync,
    GLX_SGIS_blended_overlay,
    GLX_SGIS_multisample,
    GLX_SGIS_shared_multisample,
    GLX_SGIX_dmbuffer,
    GLX_SGIX_fbconfig,
    GLX_SGIX_hyperpipe,
    GLX_SGIX_pbuffer,
    GLX_SGIX_swap_barrier,
    GLX_SGIX_swap_group,
    GLX_SGIX_video_resize,
    GLX_SGIX_video_source,
    GLX_SGIX_visual_select_group,
    GLX_SUN_get_transparent_index,
    GLX_NV_multigpu_context,
};

using VoidFunctionPtr = void (*)();
using GetFunction     = std::function<VoidFunctionPtr(const char*)>;

void init_glx(const GetFunction& get_function);

bool is_supported(Feature feature);
bool is_supported(Extension extension);

} // namespace framework::system::details::glx

#endif
