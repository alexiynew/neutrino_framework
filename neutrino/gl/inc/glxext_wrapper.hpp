/// @file
/// @brief GLX extension functions wrapper.
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

#ifndef FRAMEWORK_GL_INC_GLXEXT_WRAPPER_HPP
#define FRAMEWORK_GL_INC_GLXEXT_WRAPPER_HPP

#include <GL/glx.h>

namespace framework::gl::glx
{
extern bool glx_version_1_3_supported;
extern bool glx_version_1_4_supported;
extern bool glx_arb_create_context_supported;
extern bool glx_amd_gpu_association_supported;
extern bool glx_ext_import_context_supported;
extern bool glx_ext_swap_control_supported;
extern bool glx_ext_texture_from_pixmap_supported;
extern bool glx_mesa_agp_offset_supported;
extern bool glx_mesa_copy_sub_buffer_supported;
extern bool glx_mesa_pixmap_colormap_supported;
extern bool glx_mesa_query_renderer_supported;
extern bool glx_mesa_release_buffers_supported;
extern bool glx_mesa_set_3dfx_mode_supported;
extern bool glx_mesa_swap_control_supported;
extern bool glx_nv_copy_buffer_supported;
extern bool glx_nv_copy_image_supported;
extern bool glx_nv_delay_before_swap_supported;
extern bool glx_nv_present_video_supported;
extern bool glx_nv_swap_group_supported;
extern bool glx_nv_video_capture_supported;
extern bool glx_nv_video_out_supported;
extern bool glx_oml_sync_control_supported;
extern bool glx_sgix_fbconfig_supported;
extern bool glx_sgix_hyperpipe_supported;
extern bool glx_sgix_pbuffer_supported;
extern bool glx_sgix_swap_barrier_supported;
extern bool glx_sgix_swap_group_supported;
extern bool glx_sgix_video_resize_supported;
extern bool glx_sgi_cushion_supported;
extern bool glx_sgi_make_current_read_supported;
extern bool glx_sgi_swap_control_supported;
extern bool glx_sgi_video_sync_supported;
extern bool glx_sun_get_transparent_index_supported;

#pragma region GLX_VERSION_1_3

extern PFNGLXGETFBCONFIGSPROC glXGetFBConfigs;
extern PFNGLXCHOOSEFBCONFIGPROC glXChooseFBConfig;
extern PFNGLXGETFBCONFIGATTRIBPROC glXGetFBConfigAttrib;
extern PFNGLXGETVISUALFROMFBCONFIGPROC glXGetVisualFromFBConfig;
extern PFNGLXCREATEWINDOWPROC glXCreateWindow;
extern PFNGLXDESTROYWINDOWPROC glXDestroyWindow;
extern PFNGLXCREATEPIXMAPPROC glXCreatePixmap;
extern PFNGLXDESTROYPIXMAPPROC glXDestroyPixmap;
extern PFNGLXCREATEPBUFFERPROC glXCreatePbuffer;
extern PFNGLXDESTROYPBUFFERPROC glXDestroyPbuffer;
extern PFNGLXQUERYDRAWABLEPROC glXQueryDrawable;
extern PFNGLXCREATENEWCONTEXTPROC glXCreateNewContext;
extern PFNGLXMAKECONTEXTCURRENTPROC glXMakeContextCurrent;
extern PFNGLXGETCURRENTREADDRAWABLEPROC glXGetCurrentReadDrawable;
extern PFNGLXQUERYCONTEXTPROC glXQueryContext;
extern PFNGLXSELECTEVENTPROC glXSelectEvent;
extern PFNGLXGETSELECTEDEVENTPROC glXGetSelectedEvent;

#pragma endregion

#pragma region GLX_VERSION_1_4

extern PFNGLXGETPROCADDRESSPROC glXGetProcAddress;

#pragma endregion

#pragma region GLX_ARB_create_context

extern PFNGLXCREATECONTEXTATTRIBSARBPROC glXCreateContextAttribsARB;

#pragma endregion

#pragma region GLX_AMD_gpu_association

extern PFNGLXGETGPUIDSAMDPROC glXGetGPUIDsAMD;
extern PFNGLXGETGPUINFOAMDPROC glXGetGPUInfoAMD;
extern PFNGLXGETCONTEXTGPUIDAMDPROC glXGetContextGPUIDAMD;
extern PFNGLXCREATEASSOCIATEDCONTEXTAMDPROC glXCreateAssociatedContextAMD;
extern PFNGLXCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC glXCreateAssociatedContextAttribsAMD;
extern PFNGLXDELETEASSOCIATEDCONTEXTAMDPROC glXDeleteAssociatedContextAMD;
extern PFNGLXMAKEASSOCIATEDCONTEXTCURRENTAMDPROC glXMakeAssociatedContextCurrentAMD;
extern PFNGLXGETCURRENTASSOCIATEDCONTEXTAMDPROC glXGetCurrentAssociatedContextAMD;
extern PFNGLXBLITCONTEXTFRAMEBUFFERAMDPROC glXBlitContextFramebufferAMD;

#pragma endregion

#pragma region GLX_EXT_import_context

extern PFNGLXGETCURRENTDISPLAYEXTPROC glXGetCurrentDisplayEXT;
extern PFNGLXQUERYCONTEXTINFOEXTPROC glXQueryContextInfoEXT;
extern PFNGLXGETCONTEXTIDEXTPROC glXGetContextIDEXT;
extern PFNGLXIMPORTCONTEXTEXTPROC glXImportContextEXT;
extern PFNGLXFREECONTEXTEXTPROC glXFreeContextEXT;

#pragma endregion

#pragma region GLX_EXT_swap_control

extern PFNGLXSWAPINTERVALEXTPROC glXSwapIntervalEXT;

#pragma endregion

#pragma region GLX_EXT_texture_from_pixmap

extern PFNGLXBINDTEXIMAGEEXTPROC glXBindTexImageEXT;
extern PFNGLXRELEASETEXIMAGEEXTPROC glXReleaseTexImageEXT;

#pragma endregion

#pragma region GLX_MESA_agp_offset

extern PFNGLXGETAGPOFFSETMESAPROC glXGetAGPOffsetMESA;

#pragma endregion

#pragma region GLX_MESA_copy_sub_buffer

extern PFNGLXCOPYSUBBUFFERMESAPROC glXCopySubBufferMESA;

#pragma endregion

#pragma region GLX_MESA_pixmap_colormap

extern PFNGLXCREATEGLXPIXMAPMESAPROC glXCreateGLXPixmapMESA;

#pragma endregion

#pragma region GLX_MESA_query_renderer

extern PFNGLXQUERYCURRENTRENDERERINTEGERMESAPROC glXQueryCurrentRendererIntegerMESA;
extern PFNGLXQUERYCURRENTRENDERERSTRINGMESAPROC glXQueryCurrentRendererStringMESA;
extern PFNGLXQUERYRENDERERINTEGERMESAPROC glXQueryRendererIntegerMESA;
extern PFNGLXQUERYRENDERERSTRINGMESAPROC glXQueryRendererStringMESA;

#pragma endregion

#pragma region GLX_MESA_release_buffers

extern PFNGLXRELEASEBUFFERSMESAPROC glXReleaseBuffersMESA;

#pragma endregion

#pragma region GLX_MESA_set_3dfx_mode

extern PFNGLXSET3DFXMODEMESAPROC glXSet3DfxModeMESA;

#pragma endregion

#pragma region GLX_MESA_swap_control

extern PFNGLXGETSWAPINTERVALMESAPROC glXGetSwapIntervalMESA;
extern PFNGLXSWAPINTERVALMESAPROC glXSwapIntervalMESA;

#pragma endregion

#pragma region GLX_NV_copy_buffer

extern PFNGLXCOPYBUFFERSUBDATANVPROC glXCopyBufferSubDataNV;
extern PFNGLXNAMEDCOPYBUFFERSUBDATANVPROC glXNamedCopyBufferSubDataNV;

#pragma endregion

#pragma region GLX_NV_copy_image

extern PFNGLXCOPYIMAGESUBDATANVPROC glXCopyImageSubDataNV;

#pragma endregion

#pragma region GLX_NV_delay_before_swap

extern PFNGLXDELAYBEFORESWAPNVPROC glXDelayBeforeSwapNV;

#pragma endregion

#pragma region GLX_NV_present_video

extern PFNGLXENUMERATEVIDEODEVICESNVPROC glXEnumerateVideoDevicesNV;
extern PFNGLXBINDVIDEODEVICENVPROC glXBindVideoDeviceNV;

#pragma endregion

#pragma region GLX_NV_swap_group

extern PFNGLXJOINSWAPGROUPNVPROC glXJoinSwapGroupNV;
extern PFNGLXBINDSWAPBARRIERNVPROC glXBindSwapBarrierNV;
extern PFNGLXQUERYSWAPGROUPNVPROC glXQuerySwapGroupNV;
extern PFNGLXQUERYMAXSWAPGROUPSNVPROC glXQueryMaxSwapGroupsNV;
extern PFNGLXQUERYFRAMECOUNTNVPROC glXQueryFrameCountNV;
extern PFNGLXRESETFRAMECOUNTNVPROC glXResetFrameCountNV;

#pragma endregion

#pragma region GLX_NV_video_capture

extern PFNGLXBINDVIDEOCAPTUREDEVICENVPROC glXBindVideoCaptureDeviceNV;
extern PFNGLXENUMERATEVIDEOCAPTUREDEVICESNVPROC glXEnumerateVideoCaptureDevicesNV;
extern PFNGLXLOCKVIDEOCAPTUREDEVICENVPROC glXLockVideoCaptureDeviceNV;
extern PFNGLXQUERYVIDEOCAPTUREDEVICENVPROC glXQueryVideoCaptureDeviceNV;
extern PFNGLXRELEASEVIDEOCAPTUREDEVICENVPROC glXReleaseVideoCaptureDeviceNV;

#pragma endregion

#pragma region GLX_NV_video_out

extern PFNGLXGETVIDEODEVICENVPROC glXGetVideoDeviceNV;
extern PFNGLXRELEASEVIDEODEVICENVPROC glXReleaseVideoDeviceNV;
extern PFNGLXBINDVIDEOIMAGENVPROC glXBindVideoImageNV;
extern PFNGLXRELEASEVIDEOIMAGENVPROC glXReleaseVideoImageNV;
extern PFNGLXSENDPBUFFERTOVIDEONVPROC glXSendPbufferToVideoNV;
extern PFNGLXGETVIDEOINFONVPROC glXGetVideoInfoNV;

#pragma endregion

#pragma region GLX_OML_sync_control

extern PFNGLXGETSYNCVALUESOMLPROC glXGetSyncValuesOML;
extern PFNGLXGETMSCRATEOMLPROC glXGetMscRateOML;
extern PFNGLXSWAPBUFFERSMSCOMLPROC glXSwapBuffersMscOML;
extern PFNGLXWAITFORMSCOMLPROC glXWaitForMscOML;
extern PFNGLXWAITFORSBCOMLPROC glXWaitForSbcOML;

#pragma endregion

#pragma region GLX_SGIX_fbconfig

extern PFNGLXGETFBCONFIGATTRIBSGIXPROC glXGetFBConfigAttribSGIX;
extern PFNGLXCHOOSEFBCONFIGSGIXPROC glXChooseFBConfigSGIX;
extern PFNGLXCREATEGLXPIXMAPWITHCONFIGSGIXPROC glXCreateGLXPixmapWithConfigSGIX;
extern PFNGLXCREATECONTEXTWITHCONFIGSGIXPROC glXCreateContextWithConfigSGIX;
extern PFNGLXGETVISUALFROMFBCONFIGSGIXPROC glXGetVisualFromFBConfigSGIX;
extern PFNGLXGETFBCONFIGFROMVISUALSGIXPROC glXGetFBConfigFromVisualSGIX;

#pragma endregion

#pragma region GLX_SGIX_hyperpipe

extern PFNGLXQUERYHYPERPIPENETWORKSGIXPROC glXQueryHyperpipeNetworkSGIX;
extern PFNGLXHYPERPIPECONFIGSGIXPROC glXHyperpipeConfigSGIX;
extern PFNGLXQUERYHYPERPIPECONFIGSGIXPROC glXQueryHyperpipeConfigSGIX;
extern PFNGLXDESTROYHYPERPIPECONFIGSGIXPROC glXDestroyHyperpipeConfigSGIX;
extern PFNGLXBINDHYPERPIPESGIXPROC glXBindHyperpipeSGIX;
extern PFNGLXQUERYHYPERPIPEBESTATTRIBSGIXPROC glXQueryHyperpipeBestAttribSGIX;
extern PFNGLXHYPERPIPEATTRIBSGIXPROC glXHyperpipeAttribSGIX;
extern PFNGLXQUERYHYPERPIPEATTRIBSGIXPROC glXQueryHyperpipeAttribSGIX;

#pragma endregion

#pragma region GLX_SGIX_pbuffer

extern PFNGLXCREATEGLXPBUFFERSGIXPROC glXCreateGLXPbufferSGIX;
extern PFNGLXDESTROYGLXPBUFFERSGIXPROC glXDestroyGLXPbufferSGIX;
extern PFNGLXQUERYGLXPBUFFERSGIXPROC glXQueryGLXPbufferSGIX;
extern PFNGLXSELECTEVENTSGIXPROC glXSelectEventSGIX;
extern PFNGLXGETSELECTEDEVENTSGIXPROC glXGetSelectedEventSGIX;

#pragma endregion

#pragma region GLX_SGIX_swap_barrier

extern PFNGLXBINDSWAPBARRIERSGIXPROC glXBindSwapBarrierSGIX;
extern PFNGLXQUERYMAXSWAPBARRIERSSGIXPROC glXQueryMaxSwapBarriersSGIX;

#pragma endregion

#pragma region GLX_SGIX_swap_group

extern PFNGLXJOINSWAPGROUPSGIXPROC glXJoinSwapGroupSGIX;

#pragma endregion

#pragma region GLX_SGIX_video_resize

extern PFNGLXBINDCHANNELTOWINDOWSGIXPROC glXBindChannelToWindowSGIX;
extern PFNGLXCHANNELRECTSGIXPROC glXChannelRectSGIX;
extern PFNGLXQUERYCHANNELRECTSGIXPROC glXQueryChannelRectSGIX;
extern PFNGLXQUERYCHANNELDELTASSGIXPROC glXQueryChannelDeltasSGIX;
extern PFNGLXCHANNELRECTSYNCSGIXPROC glXChannelRectSyncSGIX;

#pragma endregion

#pragma region GLX_SGI_cushion

extern PFNGLXCUSHIONSGIPROC glXCushionSGI;

#pragma endregion

#pragma region GLX_SGI_make_current_read

extern PFNGLXMAKECURRENTREADSGIPROC glXMakeCurrentReadSGI;
extern PFNGLXGETCURRENTREADDRAWABLESGIPROC glXGetCurrentReadDrawableSGI;

#pragma endregion

#pragma region GLX_SGI_swap_control

extern PFNGLXSWAPINTERVALSGIPROC glXSwapIntervalSGI;

#pragma endregion

#pragma region GLX_SGI_video_sync

extern PFNGLXGETVIDEOSYNCSGIPROC glXGetVideoSyncSGI;
extern PFNGLXWAITVIDEOSYNCSGIPROC glXWaitVideoSyncSGI;

#pragma endregion

#pragma region GLX_SUN_get_transparent_index

extern PFNGLXGETTRANSPARENTINDEXSUNPROC glXGetTransparentIndexSUN;

#pragma endregion

void init_glx_functions();

} // namespace framework::gl::glx

#endif
