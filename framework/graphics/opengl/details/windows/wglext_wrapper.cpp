/// @file
/// @brief WGL extension functions wrapper.
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
#include <graphics/opengl/details/windows/wglext_wrapper.hpp>

namespace
{
#pragma region init_declarations

bool init_wgl_arb_buffer_region();
bool init_wgl_arb_create_context();
bool init_wgl_arb_extensions_string();
bool init_wgl_arb_make_current_read();
bool init_wgl_arb_pbuffer();
bool init_wgl_arb_pixel_format();
bool init_wgl_arb_render_texture();
bool init_wgl_3dl_stereo_control();
bool init_wgl_amd_gpu_association();
bool init_wgl_ext_display_color_table();
bool init_wgl_ext_extensions_string();
bool init_wgl_ext_make_current_read();
bool init_wgl_ext_pbuffer();
bool init_wgl_ext_pixel_format();
bool init_wgl_ext_swap_control();
bool init_wgl_i3d_digital_video_control();
bool init_wgl_i3d_gamma();
bool init_wgl_i3d_genlock();
bool init_wgl_i3d_image_buffer();
bool init_wgl_i3d_swap_frame_lock();
bool init_wgl_i3d_swap_frame_usage();
bool init_wgl_nv_dx_interop();
bool init_wgl_nv_copy_image();
bool init_wgl_nv_delay_before_swap();
bool init_wgl_nv_gpu_affinity();
bool init_wgl_nv_present_video();
bool init_wgl_nv_swap_group();
bool init_wgl_nv_vertex_array_range();
bool init_wgl_nv_video_capture();
bool init_wgl_nv_video_output();
bool init_wgl_oml_sync_control();

#pragma endregion

} // namespace

namespace framework::graphics::opengl::details
{
bool wgl_arb_buffer_region_supported         = false;
bool wgl_arb_create_context_supported        = false;
bool wgl_arb_extensions_string_supported     = false;
bool wgl_arb_make_current_read_supported     = false;
bool wgl_arb_pbuffer_supported               = false;
bool wgl_arb_pixel_format_supported          = false;
bool wgl_arb_render_texture_supported        = false;
bool wgl_3dl_stereo_control_supported        = false;
bool wgl_amd_gpu_association_supported       = false;
bool wgl_ext_display_color_table_supported   = false;
bool wgl_ext_extensions_string_supported     = false;
bool wgl_ext_make_current_read_supported     = false;
bool wgl_ext_pbuffer_supported               = false;
bool wgl_ext_pixel_format_supported          = false;
bool wgl_ext_swap_control_supported          = false;
bool wgl_i3d_digital_video_control_supported = false;
bool wgl_i3d_gamma_supported                 = false;
bool wgl_i3d_genlock_supported               = false;
bool wgl_i3d_image_buffer_supported          = false;
bool wgl_i3d_swap_frame_lock_supported       = false;
bool wgl_i3d_swap_frame_usage_supported      = false;
bool wgl_nv_dx_interop_supported             = false;
bool wgl_nv_copy_image_supported             = false;
bool wgl_nv_delay_before_swap_supported      = false;
bool wgl_nv_gpu_affinity_supported           = false;
bool wgl_nv_present_video_supported          = false;
bool wgl_nv_swap_group_supported             = false;
bool wgl_nv_vertex_array_range_supported     = false;
bool wgl_nv_video_capture_supported          = false;
bool wgl_nv_video_output_supported           = false;
bool wgl_oml_sync_control_supported          = false;

#pragma region WGL_ARB_buffer_region

PFNWGLCREATEBUFFERREGIONARBPROC wglCreateBufferRegionARB   = nullptr;
PFNWGLDELETEBUFFERREGIONARBPROC wglDeleteBufferRegionARB   = nullptr;
PFNWGLSAVEBUFFERREGIONARBPROC wglSaveBufferRegionARB       = nullptr;
PFNWGLRESTOREBUFFERREGIONARBPROC wglRestoreBufferRegionARB = nullptr;

#pragma endregion

#pragma region WGL_ARB_create_context

PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB = nullptr;

#pragma endregion

#pragma region WGL_ARB_extensions_string

PFNWGLGETEXTENSIONSSTRINGARBPROC wglGetExtensionsStringARB = nullptr;

#pragma endregion

#pragma region WGL_ARB_make_current_read

PFNWGLMAKECONTEXTCURRENTARBPROC wglMakeContextCurrentARB = nullptr;
PFNWGLGETCURRENTREADDCARBPROC wglGetCurrentReadDCARB     = nullptr;

#pragma endregion

#pragma region WGL_ARB_pbuffer

PFNWGLCREATEPBUFFERARBPROC wglCreatePbufferARB       = nullptr;
PFNWGLGETPBUFFERDCARBPROC wglGetPbufferDCARB         = nullptr;
PFNWGLRELEASEPBUFFERDCARBPROC wglReleasePbufferDCARB = nullptr;
PFNWGLDESTROYPBUFFERARBPROC wglDestroyPbufferARB     = nullptr;
PFNWGLQUERYPBUFFERARBPROC wglQueryPbufferARB         = nullptr;

#pragma endregion

#pragma region WGL_ARB_pixel_format

PFNWGLGETPIXELFORMATATTRIBIVARBPROC wglGetPixelFormatAttribivARB = nullptr;
PFNWGLGETPIXELFORMATATTRIBFVARBPROC wglGetPixelFormatAttribfvARB = nullptr;
PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB           = nullptr;

#pragma endregion

#pragma region WGL_ARB_render_texture

PFNWGLBINDTEXIMAGEARBPROC wglBindTexImageARB         = nullptr;
PFNWGLRELEASETEXIMAGEARBPROC wglReleaseTexImageARB   = nullptr;
PFNWGLSETPBUFFERATTRIBARBPROC wglSetPbufferAttribARB = nullptr;

#pragma endregion

#pragma region WGL_3DL_stereo_control

PFNWGLSETSTEREOEMITTERSTATE3DLPROC wglSetStereoEmitterState3DL = nullptr;

#pragma endregion

#pragma region WGL_AMD_gpu_association

PFNWGLGETGPUIDSAMDPROC wglGetGPUIDsAMD                                           = nullptr;
PFNWGLGETGPUINFOAMDPROC wglGetGPUInfoAMD                                         = nullptr;
PFNWGLGETCONTEXTGPUIDAMDPROC wglGetContextGPUIDAMD                               = nullptr;
PFNWGLCREATEASSOCIATEDCONTEXTAMDPROC wglCreateAssociatedContextAMD               = nullptr;
PFNWGLCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC wglCreateAssociatedContextAttribsAMD = nullptr;
PFNWGLDELETEASSOCIATEDCONTEXTAMDPROC wglDeleteAssociatedContextAMD               = nullptr;
PFNWGLMAKEASSOCIATEDCONTEXTCURRENTAMDPROC wglMakeAssociatedContextCurrentAMD     = nullptr;
PFNWGLGETCURRENTASSOCIATEDCONTEXTAMDPROC wglGetCurrentAssociatedContextAMD       = nullptr;
PFNWGLBLITCONTEXTFRAMEBUFFERAMDPROC wglBlitContextFramebufferAMD                 = nullptr;

#pragma endregion

#pragma region WGL_EXT_display_color_table

PFNWGLCREATEDISPLAYCOLORTABLEEXTPROC wglCreateDisplayColorTableEXT   = nullptr;
PFNWGLLOADDISPLAYCOLORTABLEEXTPROC wglLoadDisplayColorTableEXT       = nullptr;
PFNWGLBINDDISPLAYCOLORTABLEEXTPROC wglBindDisplayColorTableEXT       = nullptr;
PFNWGLDESTROYDISPLAYCOLORTABLEEXTPROC wglDestroyDisplayColorTableEXT = nullptr;

#pragma endregion

#pragma region WGL_EXT_extensions_string

PFNWGLGETEXTENSIONSSTRINGEXTPROC wglGetExtensionsStringEXT = nullptr;

#pragma endregion

#pragma region WGL_EXT_make_current_read

PFNWGLMAKECONTEXTCURRENTEXTPROC wglMakeContextCurrentEXT = nullptr;
PFNWGLGETCURRENTREADDCEXTPROC wglGetCurrentReadDCEXT     = nullptr;

#pragma endregion

#pragma region WGL_EXT_pbuffer

PFNWGLCREATEPBUFFEREXTPROC wglCreatePbufferEXT       = nullptr;
PFNWGLGETPBUFFERDCEXTPROC wglGetPbufferDCEXT         = nullptr;
PFNWGLRELEASEPBUFFERDCEXTPROC wglReleasePbufferDCEXT = nullptr;
PFNWGLDESTROYPBUFFEREXTPROC wglDestroyPbufferEXT     = nullptr;
PFNWGLQUERYPBUFFEREXTPROC wglQueryPbufferEXT         = nullptr;

#pragma endregion

#pragma region WGL_EXT_pixel_format

PFNWGLGETPIXELFORMATATTRIBIVEXTPROC wglGetPixelFormatAttribivEXT = nullptr;
PFNWGLGETPIXELFORMATATTRIBFVEXTPROC wglGetPixelFormatAttribfvEXT = nullptr;
PFNWGLCHOOSEPIXELFORMATEXTPROC wglChoosePixelFormatEXT           = nullptr;

#pragma endregion

#pragma region WGL_EXT_swap_control

PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT       = nullptr;
PFNWGLGETSWAPINTERVALEXTPROC wglGetSwapIntervalEXT = nullptr;

#pragma endregion

#pragma region WGL_I3D_digital_video_control

PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC wglGetDigitalVideoParametersI3D = nullptr;
PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC wglSetDigitalVideoParametersI3D = nullptr;

#pragma endregion

#pragma region WGL_I3D_gamma

PFNWGLGETGAMMATABLEPARAMETERSI3DPROC wglGetGammaTableParametersI3D = nullptr;
PFNWGLSETGAMMATABLEPARAMETERSI3DPROC wglSetGammaTableParametersI3D = nullptr;
PFNWGLGETGAMMATABLEI3DPROC wglGetGammaTableI3D                     = nullptr;
PFNWGLSETGAMMATABLEI3DPROC wglSetGammaTableI3D                     = nullptr;

#pragma endregion

#pragma region WGL_I3D_genlock

PFNWGLENABLEGENLOCKI3DPROC wglEnableGenlockI3D                           = nullptr;
PFNWGLDISABLEGENLOCKI3DPROC wglDisableGenlockI3D                         = nullptr;
PFNWGLISENABLEDGENLOCKI3DPROC wglIsEnabledGenlockI3D                     = nullptr;
PFNWGLGENLOCKSOURCEI3DPROC wglGenlockSourceI3D                           = nullptr;
PFNWGLGETGENLOCKSOURCEI3DPROC wglGetGenlockSourceI3D                     = nullptr;
PFNWGLGENLOCKSOURCEEDGEI3DPROC wglGenlockSourceEdgeI3D                   = nullptr;
PFNWGLGETGENLOCKSOURCEEDGEI3DPROC wglGetGenlockSourceEdgeI3D             = nullptr;
PFNWGLGENLOCKSAMPLERATEI3DPROC wglGenlockSampleRateI3D                   = nullptr;
PFNWGLGETGENLOCKSAMPLERATEI3DPROC wglGetGenlockSampleRateI3D             = nullptr;
PFNWGLGENLOCKSOURCEDELAYI3DPROC wglGenlockSourceDelayI3D                 = nullptr;
PFNWGLGETGENLOCKSOURCEDELAYI3DPROC wglGetGenlockSourceDelayI3D           = nullptr;
PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC wglQueryGenlockMaxSourceDelayI3D = nullptr;

#pragma endregion

#pragma region WGL_I3D_image_buffer

PFNWGLCREATEIMAGEBUFFERI3DPROC wglCreateImageBufferI3D                   = nullptr;
PFNWGLDESTROYIMAGEBUFFERI3DPROC wglDestroyImageBufferI3D                 = nullptr;
PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC wglAssociateImageBufferEventsI3D = nullptr;
PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC wglReleaseImageBufferEventsI3D     = nullptr;

#pragma endregion

#pragma region WGL_I3D_swap_frame_lock

PFNWGLENABLEFRAMELOCKI3DPROC wglEnableFrameLockI3D           = nullptr;
PFNWGLDISABLEFRAMELOCKI3DPROC wglDisableFrameLockI3D         = nullptr;
PFNWGLISENABLEDFRAMELOCKI3DPROC wglIsEnabledFrameLockI3D     = nullptr;
PFNWGLQUERYFRAMELOCKMASTERI3DPROC wglQueryFrameLockMasterI3D = nullptr;

#pragma endregion

#pragma region WGL_I3D_swap_frame_usage

PFNWGLGETFRAMEUSAGEI3DPROC wglGetFrameUsageI3D           = nullptr;
PFNWGLBEGINFRAMETRACKINGI3DPROC wglBeginFrameTrackingI3D = nullptr;
PFNWGLENDFRAMETRACKINGI3DPROC wglEndFrameTrackingI3D     = nullptr;
PFNWGLQUERYFRAMETRACKINGI3DPROC wglQueryFrameTrackingI3D = nullptr;

#pragma endregion

#pragma region WGL_NV_DX_interop

PFNWGLDXSETRESOURCESHAREHANDLENVPROC wglDXSetResourceShareHandleNV = nullptr;
PFNWGLDXOPENDEVICENVPROC wglDXOpenDeviceNV                         = nullptr;
PFNWGLDXCLOSEDEVICENVPROC wglDXCloseDeviceNV                       = nullptr;
PFNWGLDXREGISTEROBJECTNVPROC wglDXRegisterObjectNV                 = nullptr;
PFNWGLDXUNREGISTEROBJECTNVPROC wglDXUnregisterObjectNV             = nullptr;
PFNWGLDXOBJECTACCESSNVPROC wglDXObjectAccessNV                     = nullptr;
PFNWGLDXLOCKOBJECTSNVPROC wglDXLockObjectsNV                       = nullptr;
PFNWGLDXUNLOCKOBJECTSNVPROC wglDXUnlockObjectsNV                   = nullptr;

#pragma endregion

#pragma region WGL_NV_copy_image

PFNWGLCOPYIMAGESUBDATANVPROC wglCopyImageSubDataNV = nullptr;

#pragma endregion

#pragma region WGL_NV_delay_before_swap

PFNWGLDELAYBEFORESWAPNVPROC wglDelayBeforeSwapNV = nullptr;

#pragma endregion

#pragma region WGL_NV_gpu_affinity

PFNWGLENUMGPUSNVPROC wglEnumGpusNV                             = nullptr;
PFNWGLENUMGPUDEVICESNVPROC wglEnumGpuDevicesNV                 = nullptr;
PFNWGLCREATEAFFINITYDCNVPROC wglCreateAffinityDCNV             = nullptr;
PFNWGLENUMGPUSFROMAFFINITYDCNVPROC wglEnumGpusFromAffinityDCNV = nullptr;
PFNWGLDELETEDCNVPROC wglDeleteDCNV                             = nullptr;

#pragma endregion

#pragma region WGL_NV_present_video

PFNWGLENUMERATEVIDEODEVICESNVPROC wglEnumerateVideoDevicesNV = nullptr;
PFNWGLBINDVIDEODEVICENVPROC wglBindVideoDeviceNV             = nullptr;
PFNWGLQUERYCURRENTCONTEXTNVPROC wglQueryCurrentContextNV     = nullptr;

#pragma endregion

#pragma region WGL_NV_swap_group

PFNWGLJOINSWAPGROUPNVPROC wglJoinSwapGroupNV           = nullptr;
PFNWGLBINDSWAPBARRIERNVPROC wglBindSwapBarrierNV       = nullptr;
PFNWGLQUERYSWAPGROUPNVPROC wglQuerySwapGroupNV         = nullptr;
PFNWGLQUERYMAXSWAPGROUPSNVPROC wglQueryMaxSwapGroupsNV = nullptr;
PFNWGLQUERYFRAMECOUNTNVPROC wglQueryFrameCountNV       = nullptr;
PFNWGLRESETFRAMECOUNTNVPROC wglResetFrameCountNV       = nullptr;

#pragma endregion

#pragma region WGL_NV_vertex_array_range

PFNWGLALLOCATEMEMORYNVPROC wglAllocateMemoryNV = nullptr;
PFNWGLFREEMEMORYNVPROC wglFreeMemoryNV         = nullptr;

#pragma endregion

#pragma region WGL_NV_video_capture

PFNWGLBINDVIDEOCAPTUREDEVICENVPROC wglBindVideoCaptureDeviceNV             = nullptr;
PFNWGLENUMERATEVIDEOCAPTUREDEVICESNVPROC wglEnumerateVideoCaptureDevicesNV = nullptr;
PFNWGLLOCKVIDEOCAPTUREDEVICENVPROC wglLockVideoCaptureDeviceNV             = nullptr;
PFNWGLQUERYVIDEOCAPTUREDEVICENVPROC wglQueryVideoCaptureDeviceNV           = nullptr;
PFNWGLRELEASEVIDEOCAPTUREDEVICENVPROC wglReleaseVideoCaptureDeviceNV       = nullptr;

#pragma endregion

#pragma region WGL_NV_video_output

PFNWGLGETVIDEODEVICENVPROC wglGetVideoDeviceNV         = nullptr;
PFNWGLRELEASEVIDEODEVICENVPROC wglReleaseVideoDeviceNV = nullptr;
PFNWGLBINDVIDEOIMAGENVPROC wglBindVideoImageNV         = nullptr;
PFNWGLRELEASEVIDEOIMAGENVPROC wglReleaseVideoImageNV   = nullptr;
PFNWGLSENDPBUFFERTOVIDEONVPROC wglSendPbufferToVideoNV = nullptr;
PFNWGLGETVIDEOINFONVPROC wglGetVideoInfoNV             = nullptr;

#pragma endregion

#pragma region WGL_OML_sync_control

PFNWGLGETSYNCVALUESOMLPROC wglGetSyncValuesOML             = nullptr;
PFNWGLGETMSCRATEOMLPROC wglGetMscRateOML                   = nullptr;
PFNWGLSWAPBUFFERSMSCOMLPROC wglSwapBuffersMscOML           = nullptr;
PFNWGLSWAPLAYERBUFFERSMSCOMLPROC wglSwapLayerBuffersMscOML = nullptr;
PFNWGLWAITFORMSCOMLPROC wglWaitForMscOML                   = nullptr;
PFNWGLWAITFORSBCOMLPROC wglWaitForSbcOML                   = nullptr;

#pragma endregion

} // namespace framework::graphics::opengl::details

namespace
{
#pragma region init_definitions

bool init_wgl_arb_buffer_region()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::wglCreateBufferRegionARB = get_function<PFNWGLCREATEBUFFERREGIONARBPROC>("wglCreateBufferRegionARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglDeleteBufferRegionARB = get_function<PFNWGLDELETEBUFFERREGIONARBPROC>("wglDeleteBufferRegionARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglSaveBufferRegionARB = get_function<PFNWGLSAVEBUFFERREGIONARBPROC>("wglSaveBufferRegionARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglRestoreBufferRegionARB = get_function<PFNWGLRESTOREBUFFERREGIONARBPROC>("wglRestoreBufferRegionARB")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_arb_create_context()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::wglCreateContextAttribsARB = get_function<PFNWGLCREATECONTEXTATTRIBSARBPROC>("wglCreateContextAttribsARB")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_arb_extensions_string()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::wglGetExtensionsStringARB = get_function<PFNWGLGETEXTENSIONSSTRINGARBPROC>("wglGetExtensionsStringARB")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_arb_make_current_read()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::wglMakeContextCurrentARB = get_function<PFNWGLMAKECONTEXTCURRENTARBPROC>("wglMakeContextCurrentARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglGetCurrentReadDCARB = get_function<PFNWGLGETCURRENTREADDCARBPROC>("wglGetCurrentReadDCARB")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_arb_pbuffer()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::wglCreatePbufferARB = get_function<PFNWGLCREATEPBUFFERARBPROC>("wglCreatePbufferARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglGetPbufferDCARB = get_function<PFNWGLGETPBUFFERDCARBPROC>("wglGetPbufferDCARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglReleasePbufferDCARB = get_function<PFNWGLRELEASEPBUFFERDCARBPROC>("wglReleasePbufferDCARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglDestroyPbufferARB = get_function<PFNWGLDESTROYPBUFFERARBPROC>("wglDestroyPbufferARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglQueryPbufferARB = get_function<PFNWGLQUERYPBUFFERARBPROC>("wglQueryPbufferARB")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_arb_pixel_format()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::wglGetPixelFormatAttribivARB = get_function<PFNWGLGETPIXELFORMATATTRIBIVARBPROC>("wglGetPixelFormatAttribivARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglGetPixelFormatAttribfvARB = get_function<PFNWGLGETPIXELFORMATATTRIBFVARBPROC>("wglGetPixelFormatAttribfvARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglChoosePixelFormatARB = get_function<PFNWGLCHOOSEPIXELFORMATARBPROC>("wglChoosePixelFormatARB")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_arb_render_texture()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::wglBindTexImageARB = get_function<PFNWGLBINDTEXIMAGEARBPROC>("wglBindTexImageARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglReleaseTexImageARB = get_function<PFNWGLRELEASETEXIMAGEARBPROC>("wglReleaseTexImageARB")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglSetPbufferAttribARB = get_function<PFNWGLSETPBUFFERATTRIBARBPROC>("wglSetPbufferAttribARB")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_3dl_stereo_control()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::wglSetStereoEmitterState3DL = get_function<PFNWGLSETSTEREOEMITTERSTATE3DLPROC>("wglSetStereoEmitterState3DL")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_amd_gpu_association()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::wglGetGPUIDsAMD = get_function<PFNWGLGETGPUIDSAMDPROC>("wglGetGPUIDsAMD")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglGetGPUInfoAMD = get_function<PFNWGLGETGPUINFOAMDPROC>("wglGetGPUInfoAMD")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglGetContextGPUIDAMD = get_function<PFNWGLGETCONTEXTGPUIDAMDPROC>("wglGetContextGPUIDAMD")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglCreateAssociatedContextAMD = get_function<PFNWGLCREATEASSOCIATEDCONTEXTAMDPROC>("wglCreateAssociatedContextAMD")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglCreateAssociatedContextAttribsAMD = get_function<PFNWGLCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC>("wglCreateAssociatedContextAttribsAMD")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglDeleteAssociatedContextAMD = get_function<PFNWGLDELETEASSOCIATEDCONTEXTAMDPROC>("wglDeleteAssociatedContextAMD")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglMakeAssociatedContextCurrentAMD = get_function<PFNWGLMAKEASSOCIATEDCONTEXTCURRENTAMDPROC>("wglMakeAssociatedContextCurrentAMD")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglGetCurrentAssociatedContextAMD = get_function<PFNWGLGETCURRENTASSOCIATEDCONTEXTAMDPROC>("wglGetCurrentAssociatedContextAMD")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglBlitContextFramebufferAMD = get_function<PFNWGLBLITCONTEXTFRAMEBUFFERAMDPROC>("wglBlitContextFramebufferAMD")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_ext_display_color_table()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::wglCreateDisplayColorTableEXT = get_function<PFNWGLCREATEDISPLAYCOLORTABLEEXTPROC>("wglCreateDisplayColorTableEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglLoadDisplayColorTableEXT = get_function<PFNWGLLOADDISPLAYCOLORTABLEEXTPROC>("wglLoadDisplayColorTableEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglBindDisplayColorTableEXT = get_function<PFNWGLBINDDISPLAYCOLORTABLEEXTPROC>("wglBindDisplayColorTableEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglDestroyDisplayColorTableEXT = get_function<PFNWGLDESTROYDISPLAYCOLORTABLEEXTPROC>("wglDestroyDisplayColorTableEXT")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_ext_extensions_string()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::wglGetExtensionsStringEXT = get_function<PFNWGLGETEXTENSIONSSTRINGEXTPROC>("wglGetExtensionsStringEXT")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_ext_make_current_read()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::wglMakeContextCurrentEXT = get_function<PFNWGLMAKECONTEXTCURRENTEXTPROC>("wglMakeContextCurrentEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglGetCurrentReadDCEXT = get_function<PFNWGLGETCURRENTREADDCEXTPROC>("wglGetCurrentReadDCEXT")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_ext_pbuffer()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::wglCreatePbufferEXT = get_function<PFNWGLCREATEPBUFFEREXTPROC>("wglCreatePbufferEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglGetPbufferDCEXT = get_function<PFNWGLGETPBUFFERDCEXTPROC>("wglGetPbufferDCEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglReleasePbufferDCEXT = get_function<PFNWGLRELEASEPBUFFERDCEXTPROC>("wglReleasePbufferDCEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglDestroyPbufferEXT = get_function<PFNWGLDESTROYPBUFFEREXTPROC>("wglDestroyPbufferEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglQueryPbufferEXT = get_function<PFNWGLQUERYPBUFFEREXTPROC>("wglQueryPbufferEXT")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_ext_pixel_format()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::wglGetPixelFormatAttribivEXT = get_function<PFNWGLGETPIXELFORMATATTRIBIVEXTPROC>("wglGetPixelFormatAttribivEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglGetPixelFormatAttribfvEXT = get_function<PFNWGLGETPIXELFORMATATTRIBFVEXTPROC>("wglGetPixelFormatAttribfvEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglChoosePixelFormatEXT = get_function<PFNWGLCHOOSEPIXELFORMATEXTPROC>("wglChoosePixelFormatEXT")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_ext_swap_control()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::wglSwapIntervalEXT = get_function<PFNWGLSWAPINTERVALEXTPROC>("wglSwapIntervalEXT")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglGetSwapIntervalEXT = get_function<PFNWGLGETSWAPINTERVALEXTPROC>("wglGetSwapIntervalEXT")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_i3d_digital_video_control()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::wglGetDigitalVideoParametersI3D = get_function<PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC>("wglGetDigitalVideoParametersI3D")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglSetDigitalVideoParametersI3D = get_function<PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC>("wglSetDigitalVideoParametersI3D")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_i3d_gamma()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::wglGetGammaTableParametersI3D = get_function<PFNWGLGETGAMMATABLEPARAMETERSI3DPROC>("wglGetGammaTableParametersI3D")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglSetGammaTableParametersI3D = get_function<PFNWGLSETGAMMATABLEPARAMETERSI3DPROC>("wglSetGammaTableParametersI3D")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglGetGammaTableI3D = get_function<PFNWGLGETGAMMATABLEI3DPROC>("wglGetGammaTableI3D")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglSetGammaTableI3D = get_function<PFNWGLSETGAMMATABLEI3DPROC>("wglSetGammaTableI3D")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_i3d_genlock()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::wglEnableGenlockI3D = get_function<PFNWGLENABLEGENLOCKI3DPROC>("wglEnableGenlockI3D")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglDisableGenlockI3D = get_function<PFNWGLDISABLEGENLOCKI3DPROC>("wglDisableGenlockI3D")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglIsEnabledGenlockI3D = get_function<PFNWGLISENABLEDGENLOCKI3DPROC>("wglIsEnabledGenlockI3D")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglGenlockSourceI3D = get_function<PFNWGLGENLOCKSOURCEI3DPROC>("wglGenlockSourceI3D")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglGetGenlockSourceI3D = get_function<PFNWGLGETGENLOCKSOURCEI3DPROC>("wglGetGenlockSourceI3D")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglGenlockSourceEdgeI3D = get_function<PFNWGLGENLOCKSOURCEEDGEI3DPROC>("wglGenlockSourceEdgeI3D")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglGetGenlockSourceEdgeI3D = get_function<PFNWGLGETGENLOCKSOURCEEDGEI3DPROC>("wglGetGenlockSourceEdgeI3D")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglGenlockSampleRateI3D = get_function<PFNWGLGENLOCKSAMPLERATEI3DPROC>("wglGenlockSampleRateI3D")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglGetGenlockSampleRateI3D = get_function<PFNWGLGETGENLOCKSAMPLERATEI3DPROC>("wglGetGenlockSampleRateI3D")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglGenlockSourceDelayI3D = get_function<PFNWGLGENLOCKSOURCEDELAYI3DPROC>("wglGenlockSourceDelayI3D")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglGetGenlockSourceDelayI3D = get_function<PFNWGLGETGENLOCKSOURCEDELAYI3DPROC>("wglGetGenlockSourceDelayI3D")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglQueryGenlockMaxSourceDelayI3D = get_function<PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC>("wglQueryGenlockMaxSourceDelayI3D")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_i3d_image_buffer()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::wglCreateImageBufferI3D = get_function<PFNWGLCREATEIMAGEBUFFERI3DPROC>("wglCreateImageBufferI3D")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglDestroyImageBufferI3D = get_function<PFNWGLDESTROYIMAGEBUFFERI3DPROC>("wglDestroyImageBufferI3D")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglAssociateImageBufferEventsI3D = get_function<PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC>("wglAssociateImageBufferEventsI3D")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglReleaseImageBufferEventsI3D = get_function<PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC>("wglReleaseImageBufferEventsI3D")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_i3d_swap_frame_lock()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::wglEnableFrameLockI3D = get_function<PFNWGLENABLEFRAMELOCKI3DPROC>("wglEnableFrameLockI3D")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglDisableFrameLockI3D = get_function<PFNWGLDISABLEFRAMELOCKI3DPROC>("wglDisableFrameLockI3D")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglIsEnabledFrameLockI3D = get_function<PFNWGLISENABLEDFRAMELOCKI3DPROC>("wglIsEnabledFrameLockI3D")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglQueryFrameLockMasterI3D = get_function<PFNWGLQUERYFRAMELOCKMASTERI3DPROC>("wglQueryFrameLockMasterI3D")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_i3d_swap_frame_usage()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::wglGetFrameUsageI3D = get_function<PFNWGLGETFRAMEUSAGEI3DPROC>("wglGetFrameUsageI3D")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglBeginFrameTrackingI3D = get_function<PFNWGLBEGINFRAMETRACKINGI3DPROC>("wglBeginFrameTrackingI3D")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglEndFrameTrackingI3D = get_function<PFNWGLENDFRAMETRACKINGI3DPROC>("wglEndFrameTrackingI3D")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglQueryFrameTrackingI3D = get_function<PFNWGLQUERYFRAMETRACKINGI3DPROC>("wglQueryFrameTrackingI3D")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_nv_dx_interop()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::wglDXSetResourceShareHandleNV = get_function<PFNWGLDXSETRESOURCESHAREHANDLENVPROC>("wglDXSetResourceShareHandleNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglDXOpenDeviceNV = get_function<PFNWGLDXOPENDEVICENVPROC>("wglDXOpenDeviceNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglDXCloseDeviceNV = get_function<PFNWGLDXCLOSEDEVICENVPROC>("wglDXCloseDeviceNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglDXRegisterObjectNV = get_function<PFNWGLDXREGISTEROBJECTNVPROC>("wglDXRegisterObjectNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglDXUnregisterObjectNV = get_function<PFNWGLDXUNREGISTEROBJECTNVPROC>("wglDXUnregisterObjectNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglDXObjectAccessNV = get_function<PFNWGLDXOBJECTACCESSNVPROC>("wglDXObjectAccessNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglDXLockObjectsNV = get_function<PFNWGLDXLOCKOBJECTSNVPROC>("wglDXLockObjectsNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglDXUnlockObjectsNV = get_function<PFNWGLDXUNLOCKOBJECTSNVPROC>("wglDXUnlockObjectsNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_nv_copy_image()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::wglCopyImageSubDataNV = get_function<PFNWGLCOPYIMAGESUBDATANVPROC>("wglCopyImageSubDataNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_nv_delay_before_swap()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::wglDelayBeforeSwapNV = get_function<PFNWGLDELAYBEFORESWAPNVPROC>("wglDelayBeforeSwapNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_nv_gpu_affinity()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::wglEnumGpusNV = get_function<PFNWGLENUMGPUSNVPROC>("wglEnumGpusNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglEnumGpuDevicesNV = get_function<PFNWGLENUMGPUDEVICESNVPROC>("wglEnumGpuDevicesNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglCreateAffinityDCNV = get_function<PFNWGLCREATEAFFINITYDCNVPROC>("wglCreateAffinityDCNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglEnumGpusFromAffinityDCNV = get_function<PFNWGLENUMGPUSFROMAFFINITYDCNVPROC>("wglEnumGpusFromAffinityDCNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglDeleteDCNV = get_function<PFNWGLDELETEDCNVPROC>("wglDeleteDCNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_nv_present_video()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::wglEnumerateVideoDevicesNV = get_function<PFNWGLENUMERATEVIDEODEVICESNVPROC>("wglEnumerateVideoDevicesNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglBindVideoDeviceNV = get_function<PFNWGLBINDVIDEODEVICENVPROC>("wglBindVideoDeviceNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglQueryCurrentContextNV = get_function<PFNWGLQUERYCURRENTCONTEXTNVPROC>("wglQueryCurrentContextNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_nv_swap_group()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::wglJoinSwapGroupNV = get_function<PFNWGLJOINSWAPGROUPNVPROC>("wglJoinSwapGroupNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglBindSwapBarrierNV = get_function<PFNWGLBINDSWAPBARRIERNVPROC>("wglBindSwapBarrierNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglQuerySwapGroupNV = get_function<PFNWGLQUERYSWAPGROUPNVPROC>("wglQuerySwapGroupNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglQueryMaxSwapGroupsNV = get_function<PFNWGLQUERYMAXSWAPGROUPSNVPROC>("wglQueryMaxSwapGroupsNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglQueryFrameCountNV = get_function<PFNWGLQUERYFRAMECOUNTNVPROC>("wglQueryFrameCountNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglResetFrameCountNV = get_function<PFNWGLRESETFRAMECOUNTNVPROC>("wglResetFrameCountNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_nv_vertex_array_range()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::wglAllocateMemoryNV = get_function<PFNWGLALLOCATEMEMORYNVPROC>("wglAllocateMemoryNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglFreeMemoryNV = get_function<PFNWGLFREEMEMORYNVPROC>("wglFreeMemoryNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_nv_video_capture()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::wglBindVideoCaptureDeviceNV = get_function<PFNWGLBINDVIDEOCAPTUREDEVICENVPROC>("wglBindVideoCaptureDeviceNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglEnumerateVideoCaptureDevicesNV = get_function<PFNWGLENUMERATEVIDEOCAPTUREDEVICESNVPROC>("wglEnumerateVideoCaptureDevicesNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglLockVideoCaptureDeviceNV = get_function<PFNWGLLOCKVIDEOCAPTUREDEVICENVPROC>("wglLockVideoCaptureDeviceNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglQueryVideoCaptureDeviceNV = get_function<PFNWGLQUERYVIDEOCAPTUREDEVICENVPROC>("wglQueryVideoCaptureDeviceNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglReleaseVideoCaptureDeviceNV = get_function<PFNWGLRELEASEVIDEOCAPTUREDEVICENVPROC>("wglReleaseVideoCaptureDeviceNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_nv_video_output()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::wglGetVideoDeviceNV = get_function<PFNWGLGETVIDEODEVICENVPROC>("wglGetVideoDeviceNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglReleaseVideoDeviceNV = get_function<PFNWGLRELEASEVIDEODEVICENVPROC>("wglReleaseVideoDeviceNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglBindVideoImageNV = get_function<PFNWGLBINDVIDEOIMAGENVPROC>("wglBindVideoImageNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglReleaseVideoImageNV = get_function<PFNWGLRELEASEVIDEOIMAGENVPROC>("wglReleaseVideoImageNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglSendPbufferToVideoNV = get_function<PFNWGLSENDPBUFFERTOVIDEONVPROC>("wglSendPbufferToVideoNV")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglGetVideoInfoNV = get_function<PFNWGLGETVIDEOINFONVPROC>("wglGetVideoInfoNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_oml_sync_control()
{
    using ::framework::graphics::opengl::details::get_function;
    bool result = true;

    // clang-format off
    result = result && (framework::graphics::opengl::details::wglGetSyncValuesOML = get_function<PFNWGLGETSYNCVALUESOMLPROC>("wglGetSyncValuesOML")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglGetMscRateOML = get_function<PFNWGLGETMSCRATEOMLPROC>("wglGetMscRateOML")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglSwapBuffersMscOML = get_function<PFNWGLSWAPBUFFERSMSCOMLPROC>("wglSwapBuffersMscOML")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglSwapLayerBuffersMscOML = get_function<PFNWGLSWAPLAYERBUFFERSMSCOMLPROC>("wglSwapLayerBuffersMscOML")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglWaitForMscOML = get_function<PFNWGLWAITFORMSCOMLPROC>("wglWaitForMscOML")) != nullptr;
    result = result && (framework::graphics::opengl::details::wglWaitForSbcOML = get_function<PFNWGLWAITFORSBCOMLPROC>("wglWaitForSbcOML")) != nullptr;
    // clang-format on

    return result;
}

#pragma endregion

} // namespace

namespace framework::graphics::opengl::details
{
void init_wgl_functions()
{
    // clang-format off
    wgl_arb_buffer_region_supported = ::init_wgl_arb_buffer_region();
    wgl_arb_create_context_supported = ::init_wgl_arb_create_context();
    wgl_arb_extensions_string_supported = ::init_wgl_arb_extensions_string();
    wgl_arb_make_current_read_supported = ::init_wgl_arb_make_current_read();
    wgl_arb_pbuffer_supported = ::init_wgl_arb_pbuffer();
    wgl_arb_pixel_format_supported = ::init_wgl_arb_pixel_format();
    wgl_arb_render_texture_supported = ::init_wgl_arb_render_texture();
    wgl_3dl_stereo_control_supported = ::init_wgl_3dl_stereo_control();
    wgl_amd_gpu_association_supported = ::init_wgl_amd_gpu_association();
    wgl_ext_display_color_table_supported = ::init_wgl_ext_display_color_table();
    wgl_ext_extensions_string_supported = ::init_wgl_ext_extensions_string();
    wgl_ext_make_current_read_supported = ::init_wgl_ext_make_current_read();
    wgl_ext_pbuffer_supported = ::init_wgl_ext_pbuffer();
    wgl_ext_pixel_format_supported = ::init_wgl_ext_pixel_format();
    wgl_ext_swap_control_supported = ::init_wgl_ext_swap_control();
    wgl_i3d_digital_video_control_supported = ::init_wgl_i3d_digital_video_control();
    wgl_i3d_gamma_supported = ::init_wgl_i3d_gamma();
    wgl_i3d_genlock_supported = ::init_wgl_i3d_genlock();
    wgl_i3d_image_buffer_supported = ::init_wgl_i3d_image_buffer();
    wgl_i3d_swap_frame_lock_supported = ::init_wgl_i3d_swap_frame_lock();
    wgl_i3d_swap_frame_usage_supported = ::init_wgl_i3d_swap_frame_usage();
    wgl_nv_dx_interop_supported = ::init_wgl_nv_dx_interop();
    wgl_nv_copy_image_supported = ::init_wgl_nv_copy_image();
    wgl_nv_delay_before_swap_supported = ::init_wgl_nv_delay_before_swap();
    wgl_nv_gpu_affinity_supported = ::init_wgl_nv_gpu_affinity();
    wgl_nv_present_video_supported = ::init_wgl_nv_present_video();
    wgl_nv_swap_group_supported = ::init_wgl_nv_swap_group();
    wgl_nv_vertex_array_range_supported = ::init_wgl_nv_vertex_array_range();
    wgl_nv_video_capture_supported = ::init_wgl_nv_video_capture();
    wgl_nv_video_output_supported = ::init_wgl_nv_video_output();
    wgl_oml_sync_control_supported = ::init_wgl_oml_sync_control();
    // clang-format on
}

} // namespace framework::graphics::opengl::details
