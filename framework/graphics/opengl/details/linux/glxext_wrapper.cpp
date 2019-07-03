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

#include <common/types.hpp>
#include <graphics/opengl/details/gl_details.hpp>
#include <graphics/opengl/details/linux/glxext_wrapper.hpp>

namespace
{
#pragma region init_declarations

bool init_glx_version_1_3();
bool init_glx_version_1_4();
bool init_glx_arb_create_context();
bool init_glx_amd_gpu_association();
bool init_glx_ext_import_context();
bool init_glx_ext_swap_control();
bool init_glx_ext_texture_from_pixmap();
bool init_glx_mesa_agp_offset();
bool init_glx_mesa_copy_sub_buffer();
bool init_glx_mesa_pixmap_colormap();
bool init_glx_mesa_query_renderer();
bool init_glx_mesa_release_buffers();
bool init_glx_mesa_set_3dfx_mode();
bool init_glx_mesa_swap_control();
bool init_glx_nv_copy_buffer();
bool init_glx_nv_copy_image();
bool init_glx_nv_delay_before_swap();
bool init_glx_nv_present_video();
bool init_glx_nv_swap_group();
bool init_glx_nv_video_capture();
bool init_glx_nv_video_out();
bool init_glx_oml_sync_control();
bool init_glx_sgix_fbconfig();
bool init_glx_sgix_hyperpipe();
bool init_glx_sgix_pbuffer();
bool init_glx_sgix_swap_barrier();
bool init_glx_sgix_swap_group();
bool init_glx_sgix_video_resize();
bool init_glx_sgi_cushion();
bool init_glx_sgi_make_current_read();
bool init_glx_sgi_swap_control();
bool init_glx_sgi_video_sync();
bool init_glx_sun_get_transparent_index();

#pragma endregion

} // namespace

namespace framework::graphics::opengl::details
{
bool glx_version_1_3_supported               = false;
bool glx_version_1_4_supported               = false;
bool glx_arb_create_context_supported        = false;
bool glx_amd_gpu_association_supported       = false;
bool glx_ext_import_context_supported        = false;
bool glx_ext_swap_control_supported          = false;
bool glx_ext_texture_from_pixmap_supported   = false;
bool glx_mesa_agp_offset_supported           = false;
bool glx_mesa_copy_sub_buffer_supported      = false;
bool glx_mesa_pixmap_colormap_supported      = false;
bool glx_mesa_query_renderer_supported       = false;
bool glx_mesa_release_buffers_supported      = false;
bool glx_mesa_set_3dfx_mode_supported        = false;
bool glx_mesa_swap_control_supported         = false;
bool glx_nv_copy_buffer_supported            = false;
bool glx_nv_copy_image_supported             = false;
bool glx_nv_delay_before_swap_supported      = false;
bool glx_nv_present_video_supported          = false;
bool glx_nv_swap_group_supported             = false;
bool glx_nv_video_capture_supported          = false;
bool glx_nv_video_out_supported              = false;
bool glx_oml_sync_control_supported          = false;
bool glx_sgix_fbconfig_supported             = false;
bool glx_sgix_hyperpipe_supported            = false;
bool glx_sgix_pbuffer_supported              = false;
bool glx_sgix_swap_barrier_supported         = false;
bool glx_sgix_swap_group_supported           = false;
bool glx_sgix_video_resize_supported         = false;
bool glx_sgi_cushion_supported               = false;
bool glx_sgi_make_current_read_supported     = false;
bool glx_sgi_swap_control_supported          = false;
bool glx_sgi_video_sync_supported            = false;
bool glx_sun_get_transparent_index_supported = false;

#pragma region GLX_VERSION_1_3

PFNGLXGETFBCONFIGSPROC glXGetFBConfigs                     = nullptr;
PFNGLXCHOOSEFBCONFIGPROC glXChooseFBConfig                 = nullptr;
PFNGLXGETFBCONFIGATTRIBPROC glXGetFBConfigAttrib           = nullptr;
PFNGLXGETVISUALFROMFBCONFIGPROC glXGetVisualFromFBConfig   = nullptr;
PFNGLXCREATEWINDOWPROC glXCreateWindow                     = nullptr;
PFNGLXDESTROYWINDOWPROC glXDestroyWindow                   = nullptr;
PFNGLXCREATEPIXMAPPROC glXCreatePixmap                     = nullptr;
PFNGLXDESTROYPIXMAPPROC glXDestroyPixmap                   = nullptr;
PFNGLXCREATEPBUFFERPROC glXCreatePbuffer                   = nullptr;
PFNGLXDESTROYPBUFFERPROC glXDestroyPbuffer                 = nullptr;
PFNGLXQUERYDRAWABLEPROC glXQueryDrawable                   = nullptr;
PFNGLXCREATENEWCONTEXTPROC glXCreateNewContext             = nullptr;
PFNGLXMAKECONTEXTCURRENTPROC glXMakeContextCurrent         = nullptr;
PFNGLXGETCURRENTREADDRAWABLEPROC glXGetCurrentReadDrawable = nullptr;
PFNGLXQUERYCONTEXTPROC glXQueryContext                     = nullptr;
PFNGLXSELECTEVENTPROC glXSelectEvent                       = nullptr;
PFNGLXGETSELECTEDEVENTPROC glXGetSelectedEvent             = nullptr;

#pragma endregion

#pragma region GLX_VERSION_1_4

PFNGLXGETPROCADDRESSPROC glXGetProcAddress = nullptr;

#pragma endregion

#pragma region GLX_ARB_create_context

PFNGLXCREATECONTEXTATTRIBSARBPROC glXCreateContextAttribsARB = nullptr;

#pragma endregion

#pragma region GLX_AMD_gpu_association

PFNGLXGETGPUIDSAMDPROC glXGetGPUIDsAMD                                           = nullptr;
PFNGLXGETGPUINFOAMDPROC glXGetGPUInfoAMD                                         = nullptr;
PFNGLXGETCONTEXTGPUIDAMDPROC glXGetContextGPUIDAMD                               = nullptr;
PFNGLXCREATEASSOCIATEDCONTEXTAMDPROC glXCreateAssociatedContextAMD               = nullptr;
PFNGLXCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC glXCreateAssociatedContextAttribsAMD = nullptr;
PFNGLXDELETEASSOCIATEDCONTEXTAMDPROC glXDeleteAssociatedContextAMD               = nullptr;
PFNGLXMAKEASSOCIATEDCONTEXTCURRENTAMDPROC glXMakeAssociatedContextCurrentAMD     = nullptr;
PFNGLXGETCURRENTASSOCIATEDCONTEXTAMDPROC glXGetCurrentAssociatedContextAMD       = nullptr;
PFNGLXBLITCONTEXTFRAMEBUFFERAMDPROC glXBlitContextFramebufferAMD                 = nullptr;

#pragma endregion

#pragma region GLX_EXT_import_context

PFNGLXGETCURRENTDISPLAYEXTPROC glXGetCurrentDisplayEXT = nullptr;
PFNGLXQUERYCONTEXTINFOEXTPROC glXQueryContextInfoEXT   = nullptr;
PFNGLXGETCONTEXTIDEXTPROC glXGetContextIDEXT           = nullptr;
PFNGLXIMPORTCONTEXTEXTPROC glXImportContextEXT         = nullptr;
PFNGLXFREECONTEXTEXTPROC glXFreeContextEXT             = nullptr;

#pragma endregion

#pragma region GLX_EXT_swap_control

PFNGLXSWAPINTERVALEXTPROC glXSwapIntervalEXT = nullptr;

#pragma endregion

#pragma region GLX_EXT_texture_from_pixmap

PFNGLXBINDTEXIMAGEEXTPROC glXBindTexImageEXT       = nullptr;
PFNGLXRELEASETEXIMAGEEXTPROC glXReleaseTexImageEXT = nullptr;

#pragma endregion

#pragma region GLX_MESA_agp_offset

PFNGLXGETAGPOFFSETMESAPROC glXGetAGPOffsetMESA = nullptr;

#pragma endregion

#pragma region GLX_MESA_copy_sub_buffer

PFNGLXCOPYSUBBUFFERMESAPROC glXCopySubBufferMESA = nullptr;

#pragma endregion

#pragma region GLX_MESA_pixmap_colormap

PFNGLXCREATEGLXPIXMAPMESAPROC glXCreateGLXPixmapMESA = nullptr;

#pragma endregion

#pragma region GLX_MESA_query_renderer

PFNGLXQUERYCURRENTRENDERERINTEGERMESAPROC glXQueryCurrentRendererIntegerMESA = nullptr;
PFNGLXQUERYCURRENTRENDERERSTRINGMESAPROC glXQueryCurrentRendererStringMESA   = nullptr;
PFNGLXQUERYRENDERERINTEGERMESAPROC glXQueryRendererIntegerMESA               = nullptr;
PFNGLXQUERYRENDERERSTRINGMESAPROC glXQueryRendererStringMESA                 = nullptr;

#pragma endregion

#pragma region GLX_MESA_release_buffers

PFNGLXRELEASEBUFFERSMESAPROC glXReleaseBuffersMESA = nullptr;

#pragma endregion

#pragma region GLX_MESA_set_3dfx_mode

PFNGLXSET3DFXMODEMESAPROC glXSet3DfxModeMESA = nullptr;

#pragma endregion

#pragma region GLX_MESA_swap_control

PFNGLXGETSWAPINTERVALMESAPROC glXGetSwapIntervalMESA = nullptr;
PFNGLXSWAPINTERVALMESAPROC glXSwapIntervalMESA       = nullptr;

#pragma endregion

#pragma region GLX_NV_copy_buffer

PFNGLXCOPYBUFFERSUBDATANVPROC glXCopyBufferSubDataNV           = nullptr;
PFNGLXNAMEDCOPYBUFFERSUBDATANVPROC glXNamedCopyBufferSubDataNV = nullptr;

#pragma endregion

#pragma region GLX_NV_copy_image

PFNGLXCOPYIMAGESUBDATANVPROC glXCopyImageSubDataNV = nullptr;

#pragma endregion

#pragma region GLX_NV_delay_before_swap

PFNGLXDELAYBEFORESWAPNVPROC glXDelayBeforeSwapNV = nullptr;

#pragma endregion

#pragma region GLX_NV_present_video

PFNGLXENUMERATEVIDEODEVICESNVPROC glXEnumerateVideoDevicesNV = nullptr;
PFNGLXBINDVIDEODEVICENVPROC glXBindVideoDeviceNV             = nullptr;

#pragma endregion

#pragma region GLX_NV_swap_group

PFNGLXJOINSWAPGROUPNVPROC glXJoinSwapGroupNV           = nullptr;
PFNGLXBINDSWAPBARRIERNVPROC glXBindSwapBarrierNV       = nullptr;
PFNGLXQUERYSWAPGROUPNVPROC glXQuerySwapGroupNV         = nullptr;
PFNGLXQUERYMAXSWAPGROUPSNVPROC glXQueryMaxSwapGroupsNV = nullptr;
PFNGLXQUERYFRAMECOUNTNVPROC glXQueryFrameCountNV       = nullptr;
PFNGLXRESETFRAMECOUNTNVPROC glXResetFrameCountNV       = nullptr;

#pragma endregion

#pragma region GLX_NV_video_capture

PFNGLXBINDVIDEOCAPTUREDEVICENVPROC glXBindVideoCaptureDeviceNV             = nullptr;
PFNGLXENUMERATEVIDEOCAPTUREDEVICESNVPROC glXEnumerateVideoCaptureDevicesNV = nullptr;
PFNGLXLOCKVIDEOCAPTUREDEVICENVPROC glXLockVideoCaptureDeviceNV             = nullptr;
PFNGLXQUERYVIDEOCAPTUREDEVICENVPROC glXQueryVideoCaptureDeviceNV           = nullptr;
PFNGLXRELEASEVIDEOCAPTUREDEVICENVPROC glXReleaseVideoCaptureDeviceNV       = nullptr;

#pragma endregion

#pragma region GLX_NV_video_out

PFNGLXGETVIDEODEVICENVPROC glXGetVideoDeviceNV         = nullptr;
PFNGLXRELEASEVIDEODEVICENVPROC glXReleaseVideoDeviceNV = nullptr;
PFNGLXBINDVIDEOIMAGENVPROC glXBindVideoImageNV         = nullptr;
PFNGLXRELEASEVIDEOIMAGENVPROC glXReleaseVideoImageNV   = nullptr;
PFNGLXSENDPBUFFERTOVIDEONVPROC glXSendPbufferToVideoNV = nullptr;
PFNGLXGETVIDEOINFONVPROC glXGetVideoInfoNV             = nullptr;

#pragma endregion

#pragma region GLX_OML_sync_control

PFNGLXGETSYNCVALUESOMLPROC glXGetSyncValuesOML   = nullptr;
PFNGLXGETMSCRATEOMLPROC glXGetMscRateOML         = nullptr;
PFNGLXSWAPBUFFERSMSCOMLPROC glXSwapBuffersMscOML = nullptr;
PFNGLXWAITFORMSCOMLPROC glXWaitForMscOML         = nullptr;
PFNGLXWAITFORSBCOMLPROC glXWaitForSbcOML         = nullptr;

#pragma endregion

#pragma region GLX_SGIX_fbconfig

PFNGLXGETFBCONFIGATTRIBSGIXPROC glXGetFBConfigAttribSGIX                 = nullptr;
PFNGLXCHOOSEFBCONFIGSGIXPROC glXChooseFBConfigSGIX                       = nullptr;
PFNGLXCREATEGLXPIXMAPWITHCONFIGSGIXPROC glXCreateGLXPixmapWithConfigSGIX = nullptr;
PFNGLXCREATECONTEXTWITHCONFIGSGIXPROC glXCreateContextWithConfigSGIX     = nullptr;
PFNGLXGETVISUALFROMFBCONFIGSGIXPROC glXGetVisualFromFBConfigSGIX         = nullptr;
PFNGLXGETFBCONFIGFROMVISUALSGIXPROC glXGetFBConfigFromVisualSGIX         = nullptr;

#pragma endregion

#pragma region GLX_SGIX_hyperpipe

PFNGLXQUERYHYPERPIPENETWORKSGIXPROC glXQueryHyperpipeNetworkSGIX       = nullptr;
PFNGLXHYPERPIPECONFIGSGIXPROC glXHyperpipeConfigSGIX                   = nullptr;
PFNGLXQUERYHYPERPIPECONFIGSGIXPROC glXQueryHyperpipeConfigSGIX         = nullptr;
PFNGLXDESTROYHYPERPIPECONFIGSGIXPROC glXDestroyHyperpipeConfigSGIX     = nullptr;
PFNGLXBINDHYPERPIPESGIXPROC glXBindHyperpipeSGIX                       = nullptr;
PFNGLXQUERYHYPERPIPEBESTATTRIBSGIXPROC glXQueryHyperpipeBestAttribSGIX = nullptr;
PFNGLXHYPERPIPEATTRIBSGIXPROC glXHyperpipeAttribSGIX                   = nullptr;
PFNGLXQUERYHYPERPIPEATTRIBSGIXPROC glXQueryHyperpipeAttribSGIX         = nullptr;

#pragma endregion

#pragma region GLX_SGIX_pbuffer

PFNGLXCREATEGLXPBUFFERSGIXPROC glXCreateGLXPbufferSGIX   = nullptr;
PFNGLXDESTROYGLXPBUFFERSGIXPROC glXDestroyGLXPbufferSGIX = nullptr;
PFNGLXQUERYGLXPBUFFERSGIXPROC glXQueryGLXPbufferSGIX     = nullptr;
PFNGLXSELECTEVENTSGIXPROC glXSelectEventSGIX             = nullptr;
PFNGLXGETSELECTEDEVENTSGIXPROC glXGetSelectedEventSGIX   = nullptr;

#pragma endregion

#pragma region GLX_SGIX_swap_barrier

PFNGLXBINDSWAPBARRIERSGIXPROC glXBindSwapBarrierSGIX           = nullptr;
PFNGLXQUERYMAXSWAPBARRIERSSGIXPROC glXQueryMaxSwapBarriersSGIX = nullptr;

#pragma endregion

#pragma region GLX_SGIX_swap_group

PFNGLXJOINSWAPGROUPSGIXPROC glXJoinSwapGroupSGIX = nullptr;

#pragma endregion

#pragma region GLX_SGIX_video_resize

PFNGLXBINDCHANNELTOWINDOWSGIXPROC glXBindChannelToWindowSGIX = nullptr;
PFNGLXCHANNELRECTSGIXPROC glXChannelRectSGIX                 = nullptr;
PFNGLXQUERYCHANNELRECTSGIXPROC glXQueryChannelRectSGIX       = nullptr;
PFNGLXQUERYCHANNELDELTASSGIXPROC glXQueryChannelDeltasSGIX   = nullptr;
PFNGLXCHANNELRECTSYNCSGIXPROC glXChannelRectSyncSGIX         = nullptr;

#pragma endregion

#pragma region GLX_SGI_cushion

PFNGLXCUSHIONSGIPROC glXCushionSGI = nullptr;

#pragma endregion

#pragma region GLX_SGI_make_current_read

PFNGLXMAKECURRENTREADSGIPROC glXMakeCurrentReadSGI               = nullptr;
PFNGLXGETCURRENTREADDRAWABLESGIPROC glXGetCurrentReadDrawableSGI = nullptr;

#pragma endregion

#pragma region GLX_SGI_swap_control

PFNGLXSWAPINTERVALSGIPROC glXSwapIntervalSGI = nullptr;

#pragma endregion

#pragma region GLX_SGI_video_sync

PFNGLXGETVIDEOSYNCSGIPROC glXGetVideoSyncSGI   = nullptr;
PFNGLXWAITVIDEOSYNCSGIPROC glXWaitVideoSyncSGI = nullptr;

#pragma endregion

#pragma region GLX_SUN_get_transparent_index

PFNGLXGETTRANSPARENTINDEXSUNPROC glXGetTransparentIndexSUN = nullptr;

#pragma endregion

} // namespace framework::graphics::opengl::details

namespace
{
#pragma region init_definitions

bool init_glx_version_1_3()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glXGetFBConfigs = get_function<PFNGLXGETFBCONFIGSPROC>("glXGetFBConfigs")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXChooseFBConfig = get_function<PFNGLXCHOOSEFBCONFIGPROC>("glXChooseFBConfig")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXGetFBConfigAttrib = get_function<PFNGLXGETFBCONFIGATTRIBPROC>("glXGetFBConfigAttrib")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXGetVisualFromFBConfig = get_function<PFNGLXGETVISUALFROMFBCONFIGPROC>("glXGetVisualFromFBConfig")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXCreateWindow = get_function<PFNGLXCREATEWINDOWPROC>("glXCreateWindow")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXDestroyWindow = get_function<PFNGLXDESTROYWINDOWPROC>("glXDestroyWindow")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXCreatePixmap = get_function<PFNGLXCREATEPIXMAPPROC>("glXCreatePixmap")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXDestroyPixmap = get_function<PFNGLXDESTROYPIXMAPPROC>("glXDestroyPixmap")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXCreatePbuffer = get_function<PFNGLXCREATEPBUFFERPROC>("glXCreatePbuffer")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXDestroyPbuffer = get_function<PFNGLXDESTROYPBUFFERPROC>("glXDestroyPbuffer")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXQueryDrawable = get_function<PFNGLXQUERYDRAWABLEPROC>("glXQueryDrawable")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXCreateNewContext = get_function<PFNGLXCREATENEWCONTEXTPROC>("glXCreateNewContext")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXMakeContextCurrent = get_function<PFNGLXMAKECONTEXTCURRENTPROC>("glXMakeContextCurrent")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXGetCurrentReadDrawable = get_function<PFNGLXGETCURRENTREADDRAWABLEPROC>("glXGetCurrentReadDrawable")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXQueryContext = get_function<PFNGLXQUERYCONTEXTPROC>("glXQueryContext")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXSelectEvent = get_function<PFNGLXSELECTEVENTPROC>("glXSelectEvent")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXGetSelectedEvent = get_function<PFNGLXGETSELECTEDEVENTPROC>("glXGetSelectedEvent")) != nullptr;
    // clang-format on

    return result;
}

bool init_glx_version_1_4()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glXGetProcAddress = get_function<PFNGLXGETPROCADDRESSPROC>("glXGetProcAddress")) != nullptr;
    // clang-format on

    return result;
}

bool init_glx_arb_create_context()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glXCreateContextAttribsARB = get_function<PFNGLXCREATECONTEXTATTRIBSARBPROC>("glXCreateContextAttribsARB")) != nullptr;
    // clang-format on

    return result;
}

bool init_glx_amd_gpu_association()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glXGetGPUIDsAMD = get_function<PFNGLXGETGPUIDSAMDPROC>("glXGetGPUIDsAMD")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXGetGPUInfoAMD = get_function<PFNGLXGETGPUINFOAMDPROC>("glXGetGPUInfoAMD")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXGetContextGPUIDAMD = get_function<PFNGLXGETCONTEXTGPUIDAMDPROC>("glXGetContextGPUIDAMD")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXCreateAssociatedContextAMD = get_function<PFNGLXCREATEASSOCIATEDCONTEXTAMDPROC>("glXCreateAssociatedContextAMD")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXCreateAssociatedContextAttribsAMD = get_function<PFNGLXCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC>("glXCreateAssociatedContextAttribsAMD")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXDeleteAssociatedContextAMD = get_function<PFNGLXDELETEASSOCIATEDCONTEXTAMDPROC>("glXDeleteAssociatedContextAMD")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXMakeAssociatedContextCurrentAMD = get_function<PFNGLXMAKEASSOCIATEDCONTEXTCURRENTAMDPROC>("glXMakeAssociatedContextCurrentAMD")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXGetCurrentAssociatedContextAMD = get_function<PFNGLXGETCURRENTASSOCIATEDCONTEXTAMDPROC>("glXGetCurrentAssociatedContextAMD")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXBlitContextFramebufferAMD = get_function<PFNGLXBLITCONTEXTFRAMEBUFFERAMDPROC>("glXBlitContextFramebufferAMD")) != nullptr;
    // clang-format on

    return result;
}

bool init_glx_ext_import_context()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glXGetCurrentDisplayEXT = get_function<PFNGLXGETCURRENTDISPLAYEXTPROC>("glXGetCurrentDisplayEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXQueryContextInfoEXT = get_function<PFNGLXQUERYCONTEXTINFOEXTPROC>("glXQueryContextInfoEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXGetContextIDEXT = get_function<PFNGLXGETCONTEXTIDEXTPROC>("glXGetContextIDEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXImportContextEXT = get_function<PFNGLXIMPORTCONTEXTEXTPROC>("glXImportContextEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXFreeContextEXT = get_function<PFNGLXFREECONTEXTEXTPROC>("glXFreeContextEXT")) != nullptr;
    // clang-format on

    return result;
}

bool init_glx_ext_swap_control()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glXSwapIntervalEXT = get_function<PFNGLXSWAPINTERVALEXTPROC>("glXSwapIntervalEXT")) != nullptr;
    // clang-format on

    return result;
}

bool init_glx_ext_texture_from_pixmap()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glXBindTexImageEXT = get_function<PFNGLXBINDTEXIMAGEEXTPROC>("glXBindTexImageEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXReleaseTexImageEXT = get_function<PFNGLXRELEASETEXIMAGEEXTPROC>("glXReleaseTexImageEXT")) != nullptr;
    // clang-format on

    return result;
}

bool init_glx_mesa_agp_offset()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glXGetAGPOffsetMESA = get_function<PFNGLXGETAGPOFFSETMESAPROC>("glXGetAGPOffsetMESA")) != nullptr;
    // clang-format on

    return result;
}

bool init_glx_mesa_copy_sub_buffer()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glXCopySubBufferMESA = get_function<PFNGLXCOPYSUBBUFFERMESAPROC>("glXCopySubBufferMESA")) != nullptr;
    // clang-format on

    return result;
}

bool init_glx_mesa_pixmap_colormap()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glXCreateGLXPixmapMESA = get_function<PFNGLXCREATEGLXPIXMAPMESAPROC>("glXCreateGLXPixmapMESA")) != nullptr;
    // clang-format on

    return result;
}

bool init_glx_mesa_query_renderer()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glXQueryCurrentRendererIntegerMESA = get_function<PFNGLXQUERYCURRENTRENDERERINTEGERMESAPROC>("glXQueryCurrentRendererIntegerMESA")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXQueryCurrentRendererStringMESA = get_function<PFNGLXQUERYCURRENTRENDERERSTRINGMESAPROC>("glXQueryCurrentRendererStringMESA")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXQueryRendererIntegerMESA = get_function<PFNGLXQUERYRENDERERINTEGERMESAPROC>("glXQueryRendererIntegerMESA")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXQueryRendererStringMESA = get_function<PFNGLXQUERYRENDERERSTRINGMESAPROC>("glXQueryRendererStringMESA")) != nullptr;
    // clang-format on

    return result;
}

bool init_glx_mesa_release_buffers()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glXReleaseBuffersMESA = get_function<PFNGLXRELEASEBUFFERSMESAPROC>("glXReleaseBuffersMESA")) != nullptr;
    // clang-format on

    return result;
}

bool init_glx_mesa_set_3dfx_mode()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glXSet3DfxModeMESA = get_function<PFNGLXSET3DFXMODEMESAPROC>("glXSet3DfxModeMESA")) != nullptr;
    // clang-format on

    return result;
}

bool init_glx_mesa_swap_control()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glXGetSwapIntervalMESA = get_function<PFNGLXGETSWAPINTERVALMESAPROC>("glXGetSwapIntervalMESA")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXSwapIntervalMESA = get_function<PFNGLXSWAPINTERVALMESAPROC>("glXSwapIntervalMESA")) != nullptr;
    // clang-format on

    return result;
}

bool init_glx_nv_copy_buffer()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glXCopyBufferSubDataNV = get_function<PFNGLXCOPYBUFFERSUBDATANVPROC>("glXCopyBufferSubDataNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXNamedCopyBufferSubDataNV = get_function<PFNGLXNAMEDCOPYBUFFERSUBDATANVPROC>("glXNamedCopyBufferSubDataNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_glx_nv_copy_image()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glXCopyImageSubDataNV = get_function<PFNGLXCOPYIMAGESUBDATANVPROC>("glXCopyImageSubDataNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_glx_nv_delay_before_swap()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glXDelayBeforeSwapNV = get_function<PFNGLXDELAYBEFORESWAPNVPROC>("glXDelayBeforeSwapNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_glx_nv_present_video()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glXEnumerateVideoDevicesNV = get_function<PFNGLXENUMERATEVIDEODEVICESNVPROC>("glXEnumerateVideoDevicesNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXBindVideoDeviceNV = get_function<PFNGLXBINDVIDEODEVICENVPROC>("glXBindVideoDeviceNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_glx_nv_swap_group()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glXJoinSwapGroupNV = get_function<PFNGLXJOINSWAPGROUPNVPROC>("glXJoinSwapGroupNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXBindSwapBarrierNV = get_function<PFNGLXBINDSWAPBARRIERNVPROC>("glXBindSwapBarrierNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXQuerySwapGroupNV = get_function<PFNGLXQUERYSWAPGROUPNVPROC>("glXQuerySwapGroupNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXQueryMaxSwapGroupsNV = get_function<PFNGLXQUERYMAXSWAPGROUPSNVPROC>("glXQueryMaxSwapGroupsNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXQueryFrameCountNV = get_function<PFNGLXQUERYFRAMECOUNTNVPROC>("glXQueryFrameCountNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXResetFrameCountNV = get_function<PFNGLXRESETFRAMECOUNTNVPROC>("glXResetFrameCountNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_glx_nv_video_capture()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glXBindVideoCaptureDeviceNV = get_function<PFNGLXBINDVIDEOCAPTUREDEVICENVPROC>("glXBindVideoCaptureDeviceNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXEnumerateVideoCaptureDevicesNV = get_function<PFNGLXENUMERATEVIDEOCAPTUREDEVICESNVPROC>("glXEnumerateVideoCaptureDevicesNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXLockVideoCaptureDeviceNV = get_function<PFNGLXLOCKVIDEOCAPTUREDEVICENVPROC>("glXLockVideoCaptureDeviceNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXQueryVideoCaptureDeviceNV = get_function<PFNGLXQUERYVIDEOCAPTUREDEVICENVPROC>("glXQueryVideoCaptureDeviceNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXReleaseVideoCaptureDeviceNV = get_function<PFNGLXRELEASEVIDEOCAPTUREDEVICENVPROC>("glXReleaseVideoCaptureDeviceNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_glx_nv_video_out()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glXGetVideoDeviceNV = get_function<PFNGLXGETVIDEODEVICENVPROC>("glXGetVideoDeviceNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXReleaseVideoDeviceNV = get_function<PFNGLXRELEASEVIDEODEVICENVPROC>("glXReleaseVideoDeviceNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXBindVideoImageNV = get_function<PFNGLXBINDVIDEOIMAGENVPROC>("glXBindVideoImageNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXReleaseVideoImageNV = get_function<PFNGLXRELEASEVIDEOIMAGENVPROC>("glXReleaseVideoImageNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXSendPbufferToVideoNV = get_function<PFNGLXSENDPBUFFERTOVIDEONVPROC>("glXSendPbufferToVideoNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXGetVideoInfoNV = get_function<PFNGLXGETVIDEOINFONVPROC>("glXGetVideoInfoNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_glx_oml_sync_control()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glXGetSyncValuesOML = get_function<PFNGLXGETSYNCVALUESOMLPROC>("glXGetSyncValuesOML")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXGetMscRateOML = get_function<PFNGLXGETMSCRATEOMLPROC>("glXGetMscRateOML")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXSwapBuffersMscOML = get_function<PFNGLXSWAPBUFFERSMSCOMLPROC>("glXSwapBuffersMscOML")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXWaitForMscOML = get_function<PFNGLXWAITFORMSCOMLPROC>("glXWaitForMscOML")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXWaitForSbcOML = get_function<PFNGLXWAITFORSBCOMLPROC>("glXWaitForSbcOML")) != nullptr;
    // clang-format on

    return result;
}

bool init_glx_sgix_fbconfig()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glXGetFBConfigAttribSGIX = get_function<PFNGLXGETFBCONFIGATTRIBSGIXPROC>("glXGetFBConfigAttribSGIX")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXChooseFBConfigSGIX = get_function<PFNGLXCHOOSEFBCONFIGSGIXPROC>("glXChooseFBConfigSGIX")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXCreateGLXPixmapWithConfigSGIX = get_function<PFNGLXCREATEGLXPIXMAPWITHCONFIGSGIXPROC>("glXCreateGLXPixmapWithConfigSGIX")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXCreateContextWithConfigSGIX = get_function<PFNGLXCREATECONTEXTWITHCONFIGSGIXPROC>("glXCreateContextWithConfigSGIX")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXGetVisualFromFBConfigSGIX = get_function<PFNGLXGETVISUALFROMFBCONFIGSGIXPROC>("glXGetVisualFromFBConfigSGIX")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXGetFBConfigFromVisualSGIX = get_function<PFNGLXGETFBCONFIGFROMVISUALSGIXPROC>("glXGetFBConfigFromVisualSGIX")) != nullptr;
    // clang-format on

    return result;
}

bool init_glx_sgix_hyperpipe()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glXQueryHyperpipeNetworkSGIX = get_function<PFNGLXQUERYHYPERPIPENETWORKSGIXPROC>("glXQueryHyperpipeNetworkSGIX")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXHyperpipeConfigSGIX = get_function<PFNGLXHYPERPIPECONFIGSGIXPROC>("glXHyperpipeConfigSGIX")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXQueryHyperpipeConfigSGIX = get_function<PFNGLXQUERYHYPERPIPECONFIGSGIXPROC>("glXQueryHyperpipeConfigSGIX")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXDestroyHyperpipeConfigSGIX = get_function<PFNGLXDESTROYHYPERPIPECONFIGSGIXPROC>("glXDestroyHyperpipeConfigSGIX")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXBindHyperpipeSGIX = get_function<PFNGLXBINDHYPERPIPESGIXPROC>("glXBindHyperpipeSGIX")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXQueryHyperpipeBestAttribSGIX = get_function<PFNGLXQUERYHYPERPIPEBESTATTRIBSGIXPROC>("glXQueryHyperpipeBestAttribSGIX")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXHyperpipeAttribSGIX = get_function<PFNGLXHYPERPIPEATTRIBSGIXPROC>("glXHyperpipeAttribSGIX")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXQueryHyperpipeAttribSGIX = get_function<PFNGLXQUERYHYPERPIPEATTRIBSGIXPROC>("glXQueryHyperpipeAttribSGIX")) != nullptr;
    // clang-format on

    return result;
}

bool init_glx_sgix_pbuffer()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glXCreateGLXPbufferSGIX = get_function<PFNGLXCREATEGLXPBUFFERSGIXPROC>("glXCreateGLXPbufferSGIX")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXDestroyGLXPbufferSGIX = get_function<PFNGLXDESTROYGLXPBUFFERSGIXPROC>("glXDestroyGLXPbufferSGIX")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXQueryGLXPbufferSGIX = get_function<PFNGLXQUERYGLXPBUFFERSGIXPROC>("glXQueryGLXPbufferSGIX")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXSelectEventSGIX = get_function<PFNGLXSELECTEVENTSGIXPROC>("glXSelectEventSGIX")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXGetSelectedEventSGIX = get_function<PFNGLXGETSELECTEDEVENTSGIXPROC>("glXGetSelectedEventSGIX")) != nullptr;
    // clang-format on

    return result;
}

bool init_glx_sgix_swap_barrier()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glXBindSwapBarrierSGIX = get_function<PFNGLXBINDSWAPBARRIERSGIXPROC>("glXBindSwapBarrierSGIX")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXQueryMaxSwapBarriersSGIX = get_function<PFNGLXQUERYMAXSWAPBARRIERSSGIXPROC>("glXQueryMaxSwapBarriersSGIX")) != nullptr;
    // clang-format on

    return result;
}

bool init_glx_sgix_swap_group()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glXJoinSwapGroupSGIX = get_function<PFNGLXJOINSWAPGROUPSGIXPROC>("glXJoinSwapGroupSGIX")) != nullptr;
    // clang-format on

    return result;
}

bool init_glx_sgix_video_resize()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glXBindChannelToWindowSGIX = get_function<PFNGLXBINDCHANNELTOWINDOWSGIXPROC>("glXBindChannelToWindowSGIX")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXChannelRectSGIX = get_function<PFNGLXCHANNELRECTSGIXPROC>("glXChannelRectSGIX")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXQueryChannelRectSGIX = get_function<PFNGLXQUERYCHANNELRECTSGIXPROC>("glXQueryChannelRectSGIX")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXQueryChannelDeltasSGIX = get_function<PFNGLXQUERYCHANNELDELTASSGIXPROC>("glXQueryChannelDeltasSGIX")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXChannelRectSyncSGIX = get_function<PFNGLXCHANNELRECTSYNCSGIXPROC>("glXChannelRectSyncSGIX")) != nullptr;
    // clang-format on

    return result;
}

bool init_glx_sgi_cushion()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glXCushionSGI = get_function<PFNGLXCUSHIONSGIPROC>("glXCushionSGI")) != nullptr;
    // clang-format on

    return result;
}

bool init_glx_sgi_make_current_read()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glXMakeCurrentReadSGI = get_function<PFNGLXMAKECURRENTREADSGIPROC>("glXMakeCurrentReadSGI")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXGetCurrentReadDrawableSGI = get_function<PFNGLXGETCURRENTREADDRAWABLESGIPROC>("glXGetCurrentReadDrawableSGI")) != nullptr;
    // clang-format on

    return result;
}

bool init_glx_sgi_swap_control()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glXSwapIntervalSGI = get_function<PFNGLXSWAPINTERVALSGIPROC>("glXSwapIntervalSGI")) != nullptr;
    // clang-format on

    return result;
}

bool init_glx_sgi_video_sync()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glXGetVideoSyncSGI = get_function<PFNGLXGETVIDEOSYNCSGIPROC>("glXGetVideoSyncSGI")) != nullptr;
    result = result && (framework::graphics::opengl::details::glXWaitVideoSyncSGI = get_function<PFNGLXWAITVIDEOSYNCSGIPROC>("glXWaitVideoSyncSGI")) != nullptr;
    // clang-format on

    return result;
}

bool init_glx_sun_get_transparent_index()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::glXGetTransparentIndexSUN = get_function<PFNGLXGETTRANSPARENTINDEXSUNPROC>("glXGetTransparentIndexSUN")) != nullptr;
    // clang-format on

    return result;
}

#pragma endregion

} // namespace

namespace framework::graphics::opengl::details
{
void init_glx_functions()
{
    // clang-format off
    glx_version_1_3_supported = ::init_glx_version_1_3();
    glx_version_1_4_supported = ::init_glx_version_1_4();
    glx_arb_create_context_supported = ::init_glx_arb_create_context();
    glx_amd_gpu_association_supported = ::init_glx_amd_gpu_association();
    glx_ext_import_context_supported = ::init_glx_ext_import_context();
    glx_ext_swap_control_supported = ::init_glx_ext_swap_control();
    glx_ext_texture_from_pixmap_supported = ::init_glx_ext_texture_from_pixmap();
    glx_mesa_agp_offset_supported = ::init_glx_mesa_agp_offset();
    glx_mesa_copy_sub_buffer_supported = ::init_glx_mesa_copy_sub_buffer();
    glx_mesa_pixmap_colormap_supported = ::init_glx_mesa_pixmap_colormap();
    glx_mesa_query_renderer_supported = ::init_glx_mesa_query_renderer();
    glx_mesa_release_buffers_supported = ::init_glx_mesa_release_buffers();
    glx_mesa_set_3dfx_mode_supported = ::init_glx_mesa_set_3dfx_mode();
    glx_mesa_swap_control_supported = ::init_glx_mesa_swap_control();
    glx_nv_copy_buffer_supported = ::init_glx_nv_copy_buffer();
    glx_nv_copy_image_supported = ::init_glx_nv_copy_image();
    glx_nv_delay_before_swap_supported = ::init_glx_nv_delay_before_swap();
    glx_nv_present_video_supported = ::init_glx_nv_present_video();
    glx_nv_swap_group_supported = ::init_glx_nv_swap_group();
    glx_nv_video_capture_supported = ::init_glx_nv_video_capture();
    glx_nv_video_out_supported = ::init_glx_nv_video_out();
    glx_oml_sync_control_supported = ::init_glx_oml_sync_control();
    glx_sgix_fbconfig_supported = ::init_glx_sgix_fbconfig();
    glx_sgix_hyperpipe_supported = ::init_glx_sgix_hyperpipe();
    glx_sgix_pbuffer_supported = ::init_glx_sgix_pbuffer();
    glx_sgix_swap_barrier_supported = ::init_glx_sgix_swap_barrier();
    glx_sgix_swap_group_supported = ::init_glx_sgix_swap_group();
    glx_sgix_video_resize_supported = ::init_glx_sgix_video_resize();
    glx_sgi_cushion_supported = ::init_glx_sgi_cushion();
    glx_sgi_make_current_read_supported = ::init_glx_sgi_make_current_read();
    glx_sgi_swap_control_supported = ::init_glx_sgi_swap_control();
    glx_sgi_video_sync_supported = ::init_glx_sgi_video_sync();
    glx_sun_get_transparent_index_supported = ::init_glx_sun_get_transparent_index();
    // clang-format on
}

} // namespace framework::graphics::opengl::details
