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

#ifndef FRAMEWORK_GRAPHICS_OPENGL_DETAILS_WINDOWS_WGLEXT_WRAPPER_HPP
#define FRAMEWORK_GRAPHICS_OPENGL_DETAILS_WINDOWS_WGLEXT_WRAPPER_HPP

#include <GL/glcorearb.h>
#include <GL/wglext.h>

namespace framework::gl::wgl
{
extern bool wgl_arb_buffer_region_supported;
extern bool wgl_arb_create_context_supported;
extern bool wgl_arb_extensions_string_supported;
extern bool wgl_arb_make_current_read_supported;
extern bool wgl_arb_pbuffer_supported;
extern bool wgl_arb_pixel_format_supported;
extern bool wgl_arb_render_texture_supported;
extern bool wgl_3dl_stereo_control_supported;
extern bool wgl_amd_gpu_association_supported;
extern bool wgl_ext_display_color_table_supported;
extern bool wgl_ext_extensions_string_supported;
extern bool wgl_ext_make_current_read_supported;
extern bool wgl_ext_pbuffer_supported;
extern bool wgl_ext_pixel_format_supported;
extern bool wgl_ext_swap_control_supported;
extern bool wgl_i3d_digital_video_control_supported;
extern bool wgl_i3d_gamma_supported;
extern bool wgl_i3d_genlock_supported;
extern bool wgl_i3d_image_buffer_supported;
extern bool wgl_i3d_swap_frame_lock_supported;
extern bool wgl_i3d_swap_frame_usage_supported;
extern bool wgl_nv_dx_interop_supported;
extern bool wgl_nv_copy_image_supported;
extern bool wgl_nv_delay_before_swap_supported;
extern bool wgl_nv_gpu_affinity_supported;
extern bool wgl_nv_present_video_supported;
extern bool wgl_nv_swap_group_supported;
extern bool wgl_nv_vertex_array_range_supported;
extern bool wgl_nv_video_capture_supported;
extern bool wgl_nv_video_output_supported;
extern bool wgl_oml_sync_control_supported;

#pragma region WGL_ARB_buffer_region

extern PFNWGLCREATEBUFFERREGIONARBPROC wglCreateBufferRegionARB;
extern PFNWGLDELETEBUFFERREGIONARBPROC wglDeleteBufferRegionARB;
extern PFNWGLSAVEBUFFERREGIONARBPROC wglSaveBufferRegionARB;
extern PFNWGLRESTOREBUFFERREGIONARBPROC wglRestoreBufferRegionARB;

#pragma endregion

#pragma region WGL_ARB_create_context

extern PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB;

#pragma endregion

#pragma region WGL_ARB_extensions_string

extern PFNWGLGETEXTENSIONSSTRINGARBPROC wglGetExtensionsStringARB;

#pragma endregion

#pragma region WGL_ARB_make_current_read

extern PFNWGLMAKECONTEXTCURRENTARBPROC wglMakeContextCurrentARB;
extern PFNWGLGETCURRENTREADDCARBPROC wglGetCurrentReadDCARB;

#pragma endregion

#pragma region WGL_ARB_pbuffer

extern PFNWGLCREATEPBUFFERARBPROC wglCreatePbufferARB;
extern PFNWGLGETPBUFFERDCARBPROC wglGetPbufferDCARB;
extern PFNWGLRELEASEPBUFFERDCARBPROC wglReleasePbufferDCARB;
extern PFNWGLDESTROYPBUFFERARBPROC wglDestroyPbufferARB;
extern PFNWGLQUERYPBUFFERARBPROC wglQueryPbufferARB;

#pragma endregion

#pragma region WGL_ARB_pixel_format

extern PFNWGLGETPIXELFORMATATTRIBIVARBPROC wglGetPixelFormatAttribivARB;
extern PFNWGLGETPIXELFORMATATTRIBFVARBPROC wglGetPixelFormatAttribfvARB;
extern PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB;

#pragma endregion

#pragma region WGL_ARB_render_texture

extern PFNWGLBINDTEXIMAGEARBPROC wglBindTexImageARB;
extern PFNWGLRELEASETEXIMAGEARBPROC wglReleaseTexImageARB;
extern PFNWGLSETPBUFFERATTRIBARBPROC wglSetPbufferAttribARB;

#pragma endregion

#pragma region WGL_3DL_stereo_control

extern PFNWGLSETSTEREOEMITTERSTATE3DLPROC wglSetStereoEmitterState3DL;

#pragma endregion

#pragma region WGL_AMD_gpu_association

extern PFNWGLGETGPUIDSAMDPROC wglGetGPUIDsAMD;
extern PFNWGLGETGPUINFOAMDPROC wglGetGPUInfoAMD;
extern PFNWGLGETCONTEXTGPUIDAMDPROC wglGetContextGPUIDAMD;
extern PFNWGLCREATEASSOCIATEDCONTEXTAMDPROC wglCreateAssociatedContextAMD;
extern PFNWGLCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC wglCreateAssociatedContextAttribsAMD;
extern PFNWGLDELETEASSOCIATEDCONTEXTAMDPROC wglDeleteAssociatedContextAMD;
extern PFNWGLMAKEASSOCIATEDCONTEXTCURRENTAMDPROC wglMakeAssociatedContextCurrentAMD;
extern PFNWGLGETCURRENTASSOCIATEDCONTEXTAMDPROC wglGetCurrentAssociatedContextAMD;
extern PFNWGLBLITCONTEXTFRAMEBUFFERAMDPROC wglBlitContextFramebufferAMD;

#pragma endregion

#pragma region WGL_EXT_display_color_table

extern PFNWGLCREATEDISPLAYCOLORTABLEEXTPROC wglCreateDisplayColorTableEXT;
extern PFNWGLLOADDISPLAYCOLORTABLEEXTPROC wglLoadDisplayColorTableEXT;
extern PFNWGLBINDDISPLAYCOLORTABLEEXTPROC wglBindDisplayColorTableEXT;
extern PFNWGLDESTROYDISPLAYCOLORTABLEEXTPROC wglDestroyDisplayColorTableEXT;

#pragma endregion

#pragma region WGL_EXT_extensions_string

extern PFNWGLGETEXTENSIONSSTRINGEXTPROC wglGetExtensionsStringEXT;

#pragma endregion

#pragma region WGL_EXT_make_current_read

extern PFNWGLMAKECONTEXTCURRENTEXTPROC wglMakeContextCurrentEXT;
extern PFNWGLGETCURRENTREADDCEXTPROC wglGetCurrentReadDCEXT;

#pragma endregion

#pragma region WGL_EXT_pbuffer

extern PFNWGLCREATEPBUFFEREXTPROC wglCreatePbufferEXT;
extern PFNWGLGETPBUFFERDCEXTPROC wglGetPbufferDCEXT;
extern PFNWGLRELEASEPBUFFERDCEXTPROC wglReleasePbufferDCEXT;
extern PFNWGLDESTROYPBUFFEREXTPROC wglDestroyPbufferEXT;
extern PFNWGLQUERYPBUFFEREXTPROC wglQueryPbufferEXT;

#pragma endregion

#pragma region WGL_EXT_pixel_format

extern PFNWGLGETPIXELFORMATATTRIBIVEXTPROC wglGetPixelFormatAttribivEXT;
extern PFNWGLGETPIXELFORMATATTRIBFVEXTPROC wglGetPixelFormatAttribfvEXT;
extern PFNWGLCHOOSEPIXELFORMATEXTPROC wglChoosePixelFormatEXT;

#pragma endregion

#pragma region WGL_EXT_swap_control

extern PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT;
extern PFNWGLGETSWAPINTERVALEXTPROC wglGetSwapIntervalEXT;

#pragma endregion

#pragma region WGL_I3D_digital_video_control

extern PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC wglGetDigitalVideoParametersI3D;
extern PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC wglSetDigitalVideoParametersI3D;

#pragma endregion

#pragma region WGL_I3D_gamma

extern PFNWGLGETGAMMATABLEPARAMETERSI3DPROC wglGetGammaTableParametersI3D;
extern PFNWGLSETGAMMATABLEPARAMETERSI3DPROC wglSetGammaTableParametersI3D;
extern PFNWGLGETGAMMATABLEI3DPROC wglGetGammaTableI3D;
extern PFNWGLSETGAMMATABLEI3DPROC wglSetGammaTableI3D;

#pragma endregion

#pragma region WGL_I3D_genlock

extern PFNWGLENABLEGENLOCKI3DPROC wglEnableGenlockI3D;
extern PFNWGLDISABLEGENLOCKI3DPROC wglDisableGenlockI3D;
extern PFNWGLISENABLEDGENLOCKI3DPROC wglIsEnabledGenlockI3D;
extern PFNWGLGENLOCKSOURCEI3DPROC wglGenlockSourceI3D;
extern PFNWGLGETGENLOCKSOURCEI3DPROC wglGetGenlockSourceI3D;
extern PFNWGLGENLOCKSOURCEEDGEI3DPROC wglGenlockSourceEdgeI3D;
extern PFNWGLGETGENLOCKSOURCEEDGEI3DPROC wglGetGenlockSourceEdgeI3D;
extern PFNWGLGENLOCKSAMPLERATEI3DPROC wglGenlockSampleRateI3D;
extern PFNWGLGETGENLOCKSAMPLERATEI3DPROC wglGetGenlockSampleRateI3D;
extern PFNWGLGENLOCKSOURCEDELAYI3DPROC wglGenlockSourceDelayI3D;
extern PFNWGLGETGENLOCKSOURCEDELAYI3DPROC wglGetGenlockSourceDelayI3D;
extern PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC wglQueryGenlockMaxSourceDelayI3D;

#pragma endregion

#pragma region WGL_I3D_image_buffer

extern PFNWGLCREATEIMAGEBUFFERI3DPROC wglCreateImageBufferI3D;
extern PFNWGLDESTROYIMAGEBUFFERI3DPROC wglDestroyImageBufferI3D;
extern PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC wglAssociateImageBufferEventsI3D;
extern PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC wglReleaseImageBufferEventsI3D;

#pragma endregion

#pragma region WGL_I3D_swap_frame_lock

extern PFNWGLENABLEFRAMELOCKI3DPROC wglEnableFrameLockI3D;
extern PFNWGLDISABLEFRAMELOCKI3DPROC wglDisableFrameLockI3D;
extern PFNWGLISENABLEDFRAMELOCKI3DPROC wglIsEnabledFrameLockI3D;
extern PFNWGLQUERYFRAMELOCKMASTERI3DPROC wglQueryFrameLockMasterI3D;

#pragma endregion

#pragma region WGL_I3D_swap_frame_usage

extern PFNWGLGETFRAMEUSAGEI3DPROC wglGetFrameUsageI3D;
extern PFNWGLBEGINFRAMETRACKINGI3DPROC wglBeginFrameTrackingI3D;
extern PFNWGLENDFRAMETRACKINGI3DPROC wglEndFrameTrackingI3D;
extern PFNWGLQUERYFRAMETRACKINGI3DPROC wglQueryFrameTrackingI3D;

#pragma endregion

#pragma region WGL_NV_DX_interop

extern PFNWGLDXSETRESOURCESHAREHANDLENVPROC wglDXSetResourceShareHandleNV;
extern PFNWGLDXOPENDEVICENVPROC wglDXOpenDeviceNV;
extern PFNWGLDXCLOSEDEVICENVPROC wglDXCloseDeviceNV;
extern PFNWGLDXREGISTEROBJECTNVPROC wglDXRegisterObjectNV;
extern PFNWGLDXUNREGISTEROBJECTNVPROC wglDXUnregisterObjectNV;
extern PFNWGLDXOBJECTACCESSNVPROC wglDXObjectAccessNV;
extern PFNWGLDXLOCKOBJECTSNVPROC wglDXLockObjectsNV;
extern PFNWGLDXUNLOCKOBJECTSNVPROC wglDXUnlockObjectsNV;

#pragma endregion

#pragma region WGL_NV_copy_image

extern PFNWGLCOPYIMAGESUBDATANVPROC wglCopyImageSubDataNV;

#pragma endregion

#pragma region WGL_NV_delay_before_swap

extern PFNWGLDELAYBEFORESWAPNVPROC wglDelayBeforeSwapNV;

#pragma endregion

#pragma region WGL_NV_gpu_affinity

extern PFNWGLENUMGPUSNVPROC wglEnumGpusNV;
extern PFNWGLENUMGPUDEVICESNVPROC wglEnumGpuDevicesNV;
extern PFNWGLCREATEAFFINITYDCNVPROC wglCreateAffinityDCNV;
extern PFNWGLENUMGPUSFROMAFFINITYDCNVPROC wglEnumGpusFromAffinityDCNV;
extern PFNWGLDELETEDCNVPROC wglDeleteDCNV;

#pragma endregion

#pragma region WGL_NV_present_video

extern PFNWGLENUMERATEVIDEODEVICESNVPROC wglEnumerateVideoDevicesNV;
extern PFNWGLBINDVIDEODEVICENVPROC wglBindVideoDeviceNV;
extern PFNWGLQUERYCURRENTCONTEXTNVPROC wglQueryCurrentContextNV;

#pragma endregion

#pragma region WGL_NV_swap_group

extern PFNWGLJOINSWAPGROUPNVPROC wglJoinSwapGroupNV;
extern PFNWGLBINDSWAPBARRIERNVPROC wglBindSwapBarrierNV;
extern PFNWGLQUERYSWAPGROUPNVPROC wglQuerySwapGroupNV;
extern PFNWGLQUERYMAXSWAPGROUPSNVPROC wglQueryMaxSwapGroupsNV;
extern PFNWGLQUERYFRAMECOUNTNVPROC wglQueryFrameCountNV;
extern PFNWGLRESETFRAMECOUNTNVPROC wglResetFrameCountNV;

#pragma endregion

#pragma region WGL_NV_vertex_array_range

extern PFNWGLALLOCATEMEMORYNVPROC wglAllocateMemoryNV;
extern PFNWGLFREEMEMORYNVPROC wglFreeMemoryNV;

#pragma endregion

#pragma region WGL_NV_video_capture

extern PFNWGLBINDVIDEOCAPTUREDEVICENVPROC wglBindVideoCaptureDeviceNV;
extern PFNWGLENUMERATEVIDEOCAPTUREDEVICESNVPROC wglEnumerateVideoCaptureDevicesNV;
extern PFNWGLLOCKVIDEOCAPTUREDEVICENVPROC wglLockVideoCaptureDeviceNV;
extern PFNWGLQUERYVIDEOCAPTUREDEVICENVPROC wglQueryVideoCaptureDeviceNV;
extern PFNWGLRELEASEVIDEOCAPTUREDEVICENVPROC wglReleaseVideoCaptureDeviceNV;

#pragma endregion

#pragma region WGL_NV_video_output

extern PFNWGLGETVIDEODEVICENVPROC wglGetVideoDeviceNV;
extern PFNWGLRELEASEVIDEODEVICENVPROC wglReleaseVideoDeviceNV;
extern PFNWGLBINDVIDEOIMAGENVPROC wglBindVideoImageNV;
extern PFNWGLRELEASEVIDEOIMAGENVPROC wglReleaseVideoImageNV;
extern PFNWGLSENDPBUFFERTOVIDEONVPROC wglSendPbufferToVideoNV;
extern PFNWGLGETVIDEOINFONVPROC wglGetVideoInfoNV;

#pragma endregion

#pragma region WGL_OML_sync_control

extern PFNWGLGETSYNCVALUESOMLPROC wglGetSyncValuesOML;
extern PFNWGLGETMSCRATEOMLPROC wglGetMscRateOML;
extern PFNWGLSWAPBUFFERSMSCOMLPROC wglSwapBuffersMscOML;
extern PFNWGLSWAPLAYERBUFFERSMSCOMLPROC wglSwapLayerBuffersMscOML;
extern PFNWGLWAITFORMSCOMLPROC wglWaitForMscOML;
extern PFNWGLWAITFORSBCOMLPROC wglWaitForSbcOML;

#pragma endregion

void init_wgl_functions();

} // namespace framework::gl::wgl

#endif
