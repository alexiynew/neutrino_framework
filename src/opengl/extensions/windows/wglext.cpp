/// @file
/// @brief WGL extension functions wrapper.
/// @author Fedorov Alexey
/// @date 16.09.2018

// =============================================================================
// MIT License
//
// Copyright (c) 2017-2018 Fedorov Alexey
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

#include <array>
#include <mutex>

#include <common/types.hpp>
#include <opengl/details/gl_details.hpp>
#include <opengl/extensions/windows/wglext.hpp>

namespace
{
std::once_flag init_flag;

template <typename F>
F get_function(const char* function_name)
{
    return reinterpret_cast<F>(framework::opengl::details::get_function(function_name));
}

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

void init_extensions();

#pragma endregion

} // namespace

namespace framework::opengl
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

void init_wgl()
{
    std::call_once(init_flag, []() { ::init_extensions(); });
}

} // namespace framework::opengl

#pragma region init_definitions

namespace
{
bool init_wgl_arb_buffer_region()
{
    bool result = true;

    // clang-format off
    result = result && (framework::opengl::wglCreateBufferRegionARB = get_function<PFNWGLCREATEBUFFERREGIONARBPROC>("wglCreateBufferRegionARB")) != nullptr;
    result = result && (framework::opengl::wglDeleteBufferRegionARB = get_function<PFNWGLDELETEBUFFERREGIONARBPROC>("wglDeleteBufferRegionARB")) != nullptr;
    result = result && (framework::opengl::wglSaveBufferRegionARB = get_function<PFNWGLSAVEBUFFERREGIONARBPROC>("wglSaveBufferRegionARB")) != nullptr;
    result = result && (framework::opengl::wglRestoreBufferRegionARB = get_function<PFNWGLRESTOREBUFFERREGIONARBPROC>("wglRestoreBufferRegionARB")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_arb_create_context()
{
    bool result = true;

    // clang-format off
    result = result && (framework::opengl::wglCreateContextAttribsARB = get_function<PFNWGLCREATECONTEXTATTRIBSARBPROC>("wglCreateContextAttribsARB")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_arb_extensions_string()
{
    bool result = true;

    // clang-format off
    result = result && (framework::opengl::wglGetExtensionsStringARB = get_function<PFNWGLGETEXTENSIONSSTRINGARBPROC>("wglGetExtensionsStringARB")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_arb_make_current_read()
{
    bool result = true;

    // clang-format off
    result = result && (framework::opengl::wglMakeContextCurrentARB = get_function<PFNWGLMAKECONTEXTCURRENTARBPROC>("wglMakeContextCurrentARB")) != nullptr;
    result = result && (framework::opengl::wglGetCurrentReadDCARB = get_function<PFNWGLGETCURRENTREADDCARBPROC>("wglGetCurrentReadDCARB")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_arb_pbuffer()
{
    bool result = true;

    // clang-format off
    result = result && (framework::opengl::wglCreatePbufferARB = get_function<PFNWGLCREATEPBUFFERARBPROC>("wglCreatePbufferARB")) != nullptr;
    result = result && (framework::opengl::wglGetPbufferDCARB = get_function<PFNWGLGETPBUFFERDCARBPROC>("wglGetPbufferDCARB")) != nullptr;
    result = result && (framework::opengl::wglReleasePbufferDCARB = get_function<PFNWGLRELEASEPBUFFERDCARBPROC>("wglReleasePbufferDCARB")) != nullptr;
    result = result && (framework::opengl::wglDestroyPbufferARB = get_function<PFNWGLDESTROYPBUFFERARBPROC>("wglDestroyPbufferARB")) != nullptr;
    result = result && (framework::opengl::wglQueryPbufferARB = get_function<PFNWGLQUERYPBUFFERARBPROC>("wglQueryPbufferARB")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_arb_pixel_format()
{
    bool result = true;

    // clang-format off
    result = result && (framework::opengl::wglGetPixelFormatAttribivARB = get_function<PFNWGLGETPIXELFORMATATTRIBIVARBPROC>("wglGetPixelFormatAttribivARB")) != nullptr;
    result = result && (framework::opengl::wglGetPixelFormatAttribfvARB = get_function<PFNWGLGETPIXELFORMATATTRIBFVARBPROC>("wglGetPixelFormatAttribfvARB")) != nullptr;
    result = result && (framework::opengl::wglChoosePixelFormatARB = get_function<PFNWGLCHOOSEPIXELFORMATARBPROC>("wglChoosePixelFormatARB")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_arb_render_texture()
{
    bool result = true;

    // clang-format off
    result = result && (framework::opengl::wglBindTexImageARB = get_function<PFNWGLBINDTEXIMAGEARBPROC>("wglBindTexImageARB")) != nullptr;
    result = result && (framework::opengl::wglReleaseTexImageARB = get_function<PFNWGLRELEASETEXIMAGEARBPROC>("wglReleaseTexImageARB")) != nullptr;
    result = result && (framework::opengl::wglSetPbufferAttribARB = get_function<PFNWGLSETPBUFFERATTRIBARBPROC>("wglSetPbufferAttribARB")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_3dl_stereo_control()
{
    bool result = true;

    // clang-format off
    result = result && (framework::opengl::wglSetStereoEmitterState3DL = get_function<PFNWGLSETSTEREOEMITTERSTATE3DLPROC>("wglSetStereoEmitterState3DL")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_amd_gpu_association()
{
    bool result = true;

    // clang-format off
    result = result && (framework::opengl::wglGetGPUIDsAMD = get_function<PFNWGLGETGPUIDSAMDPROC>("wglGetGPUIDsAMD")) != nullptr;
    result = result && (framework::opengl::wglGetGPUInfoAMD = get_function<PFNWGLGETGPUINFOAMDPROC>("wglGetGPUInfoAMD")) != nullptr;
    result = result && (framework::opengl::wglGetContextGPUIDAMD = get_function<PFNWGLGETCONTEXTGPUIDAMDPROC>("wglGetContextGPUIDAMD")) != nullptr;
    result = result && (framework::opengl::wglCreateAssociatedContextAMD = get_function<PFNWGLCREATEASSOCIATEDCONTEXTAMDPROC>("wglCreateAssociatedContextAMD")) != nullptr;
    result = result && (framework::opengl::wglCreateAssociatedContextAttribsAMD = get_function<PFNWGLCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC>("wglCreateAssociatedContextAttribsAMD")) != nullptr;
    result = result && (framework::opengl::wglDeleteAssociatedContextAMD = get_function<PFNWGLDELETEASSOCIATEDCONTEXTAMDPROC>("wglDeleteAssociatedContextAMD")) != nullptr;
    result = result && (framework::opengl::wglMakeAssociatedContextCurrentAMD = get_function<PFNWGLMAKEASSOCIATEDCONTEXTCURRENTAMDPROC>("wglMakeAssociatedContextCurrentAMD")) != nullptr;
    result = result && (framework::opengl::wglGetCurrentAssociatedContextAMD = get_function<PFNWGLGETCURRENTASSOCIATEDCONTEXTAMDPROC>("wglGetCurrentAssociatedContextAMD")) != nullptr;
    result = result && (framework::opengl::wglBlitContextFramebufferAMD = get_function<PFNWGLBLITCONTEXTFRAMEBUFFERAMDPROC>("wglBlitContextFramebufferAMD")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_ext_display_color_table()
{
    bool result = true;

    // clang-format off
    result = result && (framework::opengl::wglCreateDisplayColorTableEXT = get_function<PFNWGLCREATEDISPLAYCOLORTABLEEXTPROC>("wglCreateDisplayColorTableEXT")) != nullptr;
    result = result && (framework::opengl::wglLoadDisplayColorTableEXT = get_function<PFNWGLLOADDISPLAYCOLORTABLEEXTPROC>("wglLoadDisplayColorTableEXT")) != nullptr;
    result = result && (framework::opengl::wglBindDisplayColorTableEXT = get_function<PFNWGLBINDDISPLAYCOLORTABLEEXTPROC>("wglBindDisplayColorTableEXT")) != nullptr;
    result = result && (framework::opengl::wglDestroyDisplayColorTableEXT = get_function<PFNWGLDESTROYDISPLAYCOLORTABLEEXTPROC>("wglDestroyDisplayColorTableEXT")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_ext_extensions_string()
{
    bool result = true;

    // clang-format off
    result = result && (framework::opengl::wglGetExtensionsStringEXT = get_function<PFNWGLGETEXTENSIONSSTRINGEXTPROC>("wglGetExtensionsStringEXT")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_ext_make_current_read()
{
    bool result = true;

    // clang-format off
    result = result && (framework::opengl::wglMakeContextCurrentEXT = get_function<PFNWGLMAKECONTEXTCURRENTEXTPROC>("wglMakeContextCurrentEXT")) != nullptr;
    result = result && (framework::opengl::wglGetCurrentReadDCEXT = get_function<PFNWGLGETCURRENTREADDCEXTPROC>("wglGetCurrentReadDCEXT")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_ext_pbuffer()
{
    bool result = true;

    // clang-format off
    result = result && (framework::opengl::wglCreatePbufferEXT = get_function<PFNWGLCREATEPBUFFEREXTPROC>("wglCreatePbufferEXT")) != nullptr;
    result = result && (framework::opengl::wglGetPbufferDCEXT = get_function<PFNWGLGETPBUFFERDCEXTPROC>("wglGetPbufferDCEXT")) != nullptr;
    result = result && (framework::opengl::wglReleasePbufferDCEXT = get_function<PFNWGLRELEASEPBUFFERDCEXTPROC>("wglReleasePbufferDCEXT")) != nullptr;
    result = result && (framework::opengl::wglDestroyPbufferEXT = get_function<PFNWGLDESTROYPBUFFEREXTPROC>("wglDestroyPbufferEXT")) != nullptr;
    result = result && (framework::opengl::wglQueryPbufferEXT = get_function<PFNWGLQUERYPBUFFEREXTPROC>("wglQueryPbufferEXT")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_ext_pixel_format()
{
    bool result = true;

    // clang-format off
    result = result && (framework::opengl::wglGetPixelFormatAttribivEXT = get_function<PFNWGLGETPIXELFORMATATTRIBIVEXTPROC>("wglGetPixelFormatAttribivEXT")) != nullptr;
    result = result && (framework::opengl::wglGetPixelFormatAttribfvEXT = get_function<PFNWGLGETPIXELFORMATATTRIBFVEXTPROC>("wglGetPixelFormatAttribfvEXT")) != nullptr;
    result = result && (framework::opengl::wglChoosePixelFormatEXT = get_function<PFNWGLCHOOSEPIXELFORMATEXTPROC>("wglChoosePixelFormatEXT")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_ext_swap_control()
{
    bool result = true;

    // clang-format off
    result = result && (framework::opengl::wglSwapIntervalEXT = get_function<PFNWGLSWAPINTERVALEXTPROC>("wglSwapIntervalEXT")) != nullptr;
    result = result && (framework::opengl::wglGetSwapIntervalEXT = get_function<PFNWGLGETSWAPINTERVALEXTPROC>("wglGetSwapIntervalEXT")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_i3d_digital_video_control()
{
    bool result = true;

    // clang-format off
    result = result && (framework::opengl::wglGetDigitalVideoParametersI3D = get_function<PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC>("wglGetDigitalVideoParametersI3D")) != nullptr;
    result = result && (framework::opengl::wglSetDigitalVideoParametersI3D = get_function<PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC>("wglSetDigitalVideoParametersI3D")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_i3d_gamma()
{
    bool result = true;

    // clang-format off
    result = result && (framework::opengl::wglGetGammaTableParametersI3D = get_function<PFNWGLGETGAMMATABLEPARAMETERSI3DPROC>("wglGetGammaTableParametersI3D")) != nullptr;
    result = result && (framework::opengl::wglSetGammaTableParametersI3D = get_function<PFNWGLSETGAMMATABLEPARAMETERSI3DPROC>("wglSetGammaTableParametersI3D")) != nullptr;
    result = result && (framework::opengl::wglGetGammaTableI3D = get_function<PFNWGLGETGAMMATABLEI3DPROC>("wglGetGammaTableI3D")) != nullptr;
    result = result && (framework::opengl::wglSetGammaTableI3D = get_function<PFNWGLSETGAMMATABLEI3DPROC>("wglSetGammaTableI3D")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_i3d_genlock()
{
    bool result = true;

    // clang-format off
    result = result && (framework::opengl::wglEnableGenlockI3D = get_function<PFNWGLENABLEGENLOCKI3DPROC>("wglEnableGenlockI3D")) != nullptr;
    result = result && (framework::opengl::wglDisableGenlockI3D = get_function<PFNWGLDISABLEGENLOCKI3DPROC>("wglDisableGenlockI3D")) != nullptr;
    result = result && (framework::opengl::wglIsEnabledGenlockI3D = get_function<PFNWGLISENABLEDGENLOCKI3DPROC>("wglIsEnabledGenlockI3D")) != nullptr;
    result = result && (framework::opengl::wglGenlockSourceI3D = get_function<PFNWGLGENLOCKSOURCEI3DPROC>("wglGenlockSourceI3D")) != nullptr;
    result = result && (framework::opengl::wglGetGenlockSourceI3D = get_function<PFNWGLGETGENLOCKSOURCEI3DPROC>("wglGetGenlockSourceI3D")) != nullptr;
    result = result && (framework::opengl::wglGenlockSourceEdgeI3D = get_function<PFNWGLGENLOCKSOURCEEDGEI3DPROC>("wglGenlockSourceEdgeI3D")) != nullptr;
    result = result && (framework::opengl::wglGetGenlockSourceEdgeI3D = get_function<PFNWGLGETGENLOCKSOURCEEDGEI3DPROC>("wglGetGenlockSourceEdgeI3D")) != nullptr;
    result = result && (framework::opengl::wglGenlockSampleRateI3D = get_function<PFNWGLGENLOCKSAMPLERATEI3DPROC>("wglGenlockSampleRateI3D")) != nullptr;
    result = result && (framework::opengl::wglGetGenlockSampleRateI3D = get_function<PFNWGLGETGENLOCKSAMPLERATEI3DPROC>("wglGetGenlockSampleRateI3D")) != nullptr;
    result = result && (framework::opengl::wglGenlockSourceDelayI3D = get_function<PFNWGLGENLOCKSOURCEDELAYI3DPROC>("wglGenlockSourceDelayI3D")) != nullptr;
    result = result && (framework::opengl::wglGetGenlockSourceDelayI3D = get_function<PFNWGLGETGENLOCKSOURCEDELAYI3DPROC>("wglGetGenlockSourceDelayI3D")) != nullptr;
    result = result && (framework::opengl::wglQueryGenlockMaxSourceDelayI3D = get_function<PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC>("wglQueryGenlockMaxSourceDelayI3D")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_i3d_image_buffer()
{
    bool result = true;

    // clang-format off
    result = result && (framework::opengl::wglCreateImageBufferI3D = get_function<PFNWGLCREATEIMAGEBUFFERI3DPROC>("wglCreateImageBufferI3D")) != nullptr;
    result = result && (framework::opengl::wglDestroyImageBufferI3D = get_function<PFNWGLDESTROYIMAGEBUFFERI3DPROC>("wglDestroyImageBufferI3D")) != nullptr;
    result = result && (framework::opengl::wglAssociateImageBufferEventsI3D = get_function<PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC>("wglAssociateImageBufferEventsI3D")) != nullptr;
    result = result && (framework::opengl::wglReleaseImageBufferEventsI3D = get_function<PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC>("wglReleaseImageBufferEventsI3D")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_i3d_swap_frame_lock()
{
    bool result = true;

    // clang-format off
    result = result && (framework::opengl::wglEnableFrameLockI3D = get_function<PFNWGLENABLEFRAMELOCKI3DPROC>("wglEnableFrameLockI3D")) != nullptr;
    result = result && (framework::opengl::wglDisableFrameLockI3D = get_function<PFNWGLDISABLEFRAMELOCKI3DPROC>("wglDisableFrameLockI3D")) != nullptr;
    result = result && (framework::opengl::wglIsEnabledFrameLockI3D = get_function<PFNWGLISENABLEDFRAMELOCKI3DPROC>("wglIsEnabledFrameLockI3D")) != nullptr;
    result = result && (framework::opengl::wglQueryFrameLockMasterI3D = get_function<PFNWGLQUERYFRAMELOCKMASTERI3DPROC>("wglQueryFrameLockMasterI3D")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_i3d_swap_frame_usage()
{
    bool result = true;

    // clang-format off
    result = result && (framework::opengl::wglGetFrameUsageI3D = get_function<PFNWGLGETFRAMEUSAGEI3DPROC>("wglGetFrameUsageI3D")) != nullptr;
    result = result && (framework::opengl::wglBeginFrameTrackingI3D = get_function<PFNWGLBEGINFRAMETRACKINGI3DPROC>("wglBeginFrameTrackingI3D")) != nullptr;
    result = result && (framework::opengl::wglEndFrameTrackingI3D = get_function<PFNWGLENDFRAMETRACKINGI3DPROC>("wglEndFrameTrackingI3D")) != nullptr;
    result = result && (framework::opengl::wglQueryFrameTrackingI3D = get_function<PFNWGLQUERYFRAMETRACKINGI3DPROC>("wglQueryFrameTrackingI3D")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_nv_dx_interop()
{
    bool result = true;

    // clang-format off
    result = result && (framework::opengl::wglDXSetResourceShareHandleNV = get_function<PFNWGLDXSETRESOURCESHAREHANDLENVPROC>("wglDXSetResourceShareHandleNV")) != nullptr;
    result = result && (framework::opengl::wglDXOpenDeviceNV = get_function<PFNWGLDXOPENDEVICENVPROC>("wglDXOpenDeviceNV")) != nullptr;
    result = result && (framework::opengl::wglDXCloseDeviceNV = get_function<PFNWGLDXCLOSEDEVICENVPROC>("wglDXCloseDeviceNV")) != nullptr;
    result = result && (framework::opengl::wglDXRegisterObjectNV = get_function<PFNWGLDXREGISTEROBJECTNVPROC>("wglDXRegisterObjectNV")) != nullptr;
    result = result && (framework::opengl::wglDXUnregisterObjectNV = get_function<PFNWGLDXUNREGISTEROBJECTNVPROC>("wglDXUnregisterObjectNV")) != nullptr;
    result = result && (framework::opengl::wglDXObjectAccessNV = get_function<PFNWGLDXOBJECTACCESSNVPROC>("wglDXObjectAccessNV")) != nullptr;
    result = result && (framework::opengl::wglDXLockObjectsNV = get_function<PFNWGLDXLOCKOBJECTSNVPROC>("wglDXLockObjectsNV")) != nullptr;
    result = result && (framework::opengl::wglDXUnlockObjectsNV = get_function<PFNWGLDXUNLOCKOBJECTSNVPROC>("wglDXUnlockObjectsNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_nv_copy_image()
{
    bool result = true;

    // clang-format off
    result = result && (framework::opengl::wglCopyImageSubDataNV = get_function<PFNWGLCOPYIMAGESUBDATANVPROC>("wglCopyImageSubDataNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_nv_delay_before_swap()
{
    bool result = true;

    // clang-format off
    result = result && (framework::opengl::wglDelayBeforeSwapNV = get_function<PFNWGLDELAYBEFORESWAPNVPROC>("wglDelayBeforeSwapNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_nv_gpu_affinity()
{
    bool result = true;

    // clang-format off
    result = result && (framework::opengl::wglEnumGpusNV = get_function<PFNWGLENUMGPUSNVPROC>("wglEnumGpusNV")) != nullptr;
    result = result && (framework::opengl::wglEnumGpuDevicesNV = get_function<PFNWGLENUMGPUDEVICESNVPROC>("wglEnumGpuDevicesNV")) != nullptr;
    result = result && (framework::opengl::wglCreateAffinityDCNV = get_function<PFNWGLCREATEAFFINITYDCNVPROC>("wglCreateAffinityDCNV")) != nullptr;
    result = result && (framework::opengl::wglEnumGpusFromAffinityDCNV = get_function<PFNWGLENUMGPUSFROMAFFINITYDCNVPROC>("wglEnumGpusFromAffinityDCNV")) != nullptr;
    result = result && (framework::opengl::wglDeleteDCNV = get_function<PFNWGLDELETEDCNVPROC>("wglDeleteDCNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_nv_present_video()
{
    bool result = true;

    // clang-format off
    result = result && (framework::opengl::wglEnumerateVideoDevicesNV = get_function<PFNWGLENUMERATEVIDEODEVICESNVPROC>("wglEnumerateVideoDevicesNV")) != nullptr;
    result = result && (framework::opengl::wglBindVideoDeviceNV = get_function<PFNWGLBINDVIDEODEVICENVPROC>("wglBindVideoDeviceNV")) != nullptr;
    result = result && (framework::opengl::wglQueryCurrentContextNV = get_function<PFNWGLQUERYCURRENTCONTEXTNVPROC>("wglQueryCurrentContextNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_nv_swap_group()
{
    bool result = true;

    // clang-format off
    result = result && (framework::opengl::wglJoinSwapGroupNV = get_function<PFNWGLJOINSWAPGROUPNVPROC>("wglJoinSwapGroupNV")) != nullptr;
    result = result && (framework::opengl::wglBindSwapBarrierNV = get_function<PFNWGLBINDSWAPBARRIERNVPROC>("wglBindSwapBarrierNV")) != nullptr;
    result = result && (framework::opengl::wglQuerySwapGroupNV = get_function<PFNWGLQUERYSWAPGROUPNVPROC>("wglQuerySwapGroupNV")) != nullptr;
    result = result && (framework::opengl::wglQueryMaxSwapGroupsNV = get_function<PFNWGLQUERYMAXSWAPGROUPSNVPROC>("wglQueryMaxSwapGroupsNV")) != nullptr;
    result = result && (framework::opengl::wglQueryFrameCountNV = get_function<PFNWGLQUERYFRAMECOUNTNVPROC>("wglQueryFrameCountNV")) != nullptr;
    result = result && (framework::opengl::wglResetFrameCountNV = get_function<PFNWGLRESETFRAMECOUNTNVPROC>("wglResetFrameCountNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_nv_vertex_array_range()
{
    bool result = true;

    // clang-format off
    result = result && (framework::opengl::wglAllocateMemoryNV = get_function<PFNWGLALLOCATEMEMORYNVPROC>("wglAllocateMemoryNV")) != nullptr;
    result = result && (framework::opengl::wglFreeMemoryNV = get_function<PFNWGLFREEMEMORYNVPROC>("wglFreeMemoryNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_nv_video_capture()
{
    bool result = true;

    // clang-format off
    result = result && (framework::opengl::wglBindVideoCaptureDeviceNV = get_function<PFNWGLBINDVIDEOCAPTUREDEVICENVPROC>("wglBindVideoCaptureDeviceNV")) != nullptr;
    result = result && (framework::opengl::wglEnumerateVideoCaptureDevicesNV = get_function<PFNWGLENUMERATEVIDEOCAPTUREDEVICESNVPROC>("wglEnumerateVideoCaptureDevicesNV")) != nullptr;
    result = result && (framework::opengl::wglLockVideoCaptureDeviceNV = get_function<PFNWGLLOCKVIDEOCAPTUREDEVICENVPROC>("wglLockVideoCaptureDeviceNV")) != nullptr;
    result = result && (framework::opengl::wglQueryVideoCaptureDeviceNV = get_function<PFNWGLQUERYVIDEOCAPTUREDEVICENVPROC>("wglQueryVideoCaptureDeviceNV")) != nullptr;
    result = result && (framework::opengl::wglReleaseVideoCaptureDeviceNV = get_function<PFNWGLRELEASEVIDEOCAPTUREDEVICENVPROC>("wglReleaseVideoCaptureDeviceNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_nv_video_output()
{
    bool result = true;

    // clang-format off
    result = result && (framework::opengl::wglGetVideoDeviceNV = get_function<PFNWGLGETVIDEODEVICENVPROC>("wglGetVideoDeviceNV")) != nullptr;
    result = result && (framework::opengl::wglReleaseVideoDeviceNV = get_function<PFNWGLRELEASEVIDEODEVICENVPROC>("wglReleaseVideoDeviceNV")) != nullptr;
    result = result && (framework::opengl::wglBindVideoImageNV = get_function<PFNWGLBINDVIDEOIMAGENVPROC>("wglBindVideoImageNV")) != nullptr;
    result = result && (framework::opengl::wglReleaseVideoImageNV = get_function<PFNWGLRELEASEVIDEOIMAGENVPROC>("wglReleaseVideoImageNV")) != nullptr;
    result = result && (framework::opengl::wglSendPbufferToVideoNV = get_function<PFNWGLSENDPBUFFERTOVIDEONVPROC>("wglSendPbufferToVideoNV")) != nullptr;
    result = result && (framework::opengl::wglGetVideoInfoNV = get_function<PFNWGLGETVIDEOINFONVPROC>("wglGetVideoInfoNV")) != nullptr;
    // clang-format on

    return result;
}

bool init_wgl_oml_sync_control()
{
    bool result = true;

    // clang-format off
    result = result && (framework::opengl::wglGetSyncValuesOML = get_function<PFNWGLGETSYNCVALUESOMLPROC>("wglGetSyncValuesOML")) != nullptr;
    result = result && (framework::opengl::wglGetMscRateOML = get_function<PFNWGLGETMSCRATEOMLPROC>("wglGetMscRateOML")) != nullptr;
    result = result && (framework::opengl::wglSwapBuffersMscOML = get_function<PFNWGLSWAPBUFFERSMSCOMLPROC>("wglSwapBuffersMscOML")) != nullptr;
    result = result && (framework::opengl::wglSwapLayerBuffersMscOML = get_function<PFNWGLSWAPLAYERBUFFERSMSCOMLPROC>("wglSwapLayerBuffersMscOML")) != nullptr;
    result = result && (framework::opengl::wglWaitForMscOML = get_function<PFNWGLWAITFORMSCOMLPROC>("wglWaitForMscOML")) != nullptr;
    result = result && (framework::opengl::wglWaitForSbcOML = get_function<PFNWGLWAITFORSBCOMLPROC>("wglWaitForSbcOML")) != nullptr;
    // clang-format on

    return result;
}

void init_extensions()
{
    HDC hdc = GetDC(nullptr);

    if (hdc == nullptr) {
        return;
    }

    PIXELFORMATDESCRIPTOR pfd{0};
    pfd.nSize    = sizeof(PIXELFORMATDESCRIPTOR);
    pfd.nVersion = 1;
    pfd.dwFlags  = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;

    int pixelFormat = ChoosePixelFormat(hdc, &pfd);
    if (pixelFormat == 0) {
        ReleaseDC(nullptr, hdc);
        return;
    }

    if (!SetPixelFormat(hdc, pixelFormat, &pfd)) {
        ReleaseDC(nullptr, hdc);
        return;
    }

    HGLRC hglrc = wglCreateContext(hdc);
    if (hglrc == nullptr) {
        ReleaseDC(nullptr, hdc);
        return;
    }

    wglMakeCurrent(hdc, hglrc);

    // clang-format off
    framework::opengl::wgl_arb_buffer_region_supported = init_wgl_arb_buffer_region();
    framework::opengl::wgl_arb_create_context_supported = init_wgl_arb_create_context();
    framework::opengl::wgl_arb_extensions_string_supported = init_wgl_arb_extensions_string();
    framework::opengl::wgl_arb_make_current_read_supported = init_wgl_arb_make_current_read();
    framework::opengl::wgl_arb_pbuffer_supported = init_wgl_arb_pbuffer();
    framework::opengl::wgl_arb_pixel_format_supported = init_wgl_arb_pixel_format();
    framework::opengl::wgl_arb_render_texture_supported = init_wgl_arb_render_texture();
    framework::opengl::wgl_3dl_stereo_control_supported = init_wgl_3dl_stereo_control();
    framework::opengl::wgl_amd_gpu_association_supported = init_wgl_amd_gpu_association();
    framework::opengl::wgl_ext_display_color_table_supported = init_wgl_ext_display_color_table();
    framework::opengl::wgl_ext_extensions_string_supported = init_wgl_ext_extensions_string();
    framework::opengl::wgl_ext_make_current_read_supported = init_wgl_ext_make_current_read();
    framework::opengl::wgl_ext_pbuffer_supported = init_wgl_ext_pbuffer();
    framework::opengl::wgl_ext_pixel_format_supported = init_wgl_ext_pixel_format();
    framework::opengl::wgl_ext_swap_control_supported = init_wgl_ext_swap_control();
    framework::opengl::wgl_i3d_digital_video_control_supported = init_wgl_i3d_digital_video_control();
    framework::opengl::wgl_i3d_gamma_supported = init_wgl_i3d_gamma();
    framework::opengl::wgl_i3d_genlock_supported = init_wgl_i3d_genlock();
    framework::opengl::wgl_i3d_image_buffer_supported = init_wgl_i3d_image_buffer();
    framework::opengl::wgl_i3d_swap_frame_lock_supported = init_wgl_i3d_swap_frame_lock();
    framework::opengl::wgl_i3d_swap_frame_usage_supported = init_wgl_i3d_swap_frame_usage();
    framework::opengl::wgl_nv_dx_interop_supported = init_wgl_nv_dx_interop();
    framework::opengl::wgl_nv_copy_image_supported = init_wgl_nv_copy_image();
    framework::opengl::wgl_nv_delay_before_swap_supported = init_wgl_nv_delay_before_swap();
    framework::opengl::wgl_nv_gpu_affinity_supported = init_wgl_nv_gpu_affinity();
    framework::opengl::wgl_nv_present_video_supported = init_wgl_nv_present_video();
    framework::opengl::wgl_nv_swap_group_supported = init_wgl_nv_swap_group();
    framework::opengl::wgl_nv_vertex_array_range_supported = init_wgl_nv_vertex_array_range();
    framework::opengl::wgl_nv_video_capture_supported = init_wgl_nv_video_capture();
    framework::opengl::wgl_nv_video_output_supported = init_wgl_nv_video_output();
    framework::opengl::wgl_oml_sync_control_supported = init_wgl_oml_sync_control();
    // clang-format on

    wglMakeCurrent(nullptr, nullptr);
    wglDeleteContext(hglrc);
    ReleaseDC(nullptr, hdc);
}

} // namespace

#pragma endregion
