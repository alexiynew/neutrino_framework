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

#include <mutex>
#include <type_traits>

#include <system/src/windows/wglext.hpp>

namespace
{

using namespace framework::system::details::wgl;

#pragma region WGL_3DFX_multisample

bool init_wgl_3dfx_multisample([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region WGL_3DL_stereo_control

using wglSetStereoEmitterState3DLPtr = std::add_pointer_t<decltype(wglSetStereoEmitterState3DL)>;

wglSetStereoEmitterState3DLPtr wglSetStereoEmitterState3DL_ptr = nullptr;

bool init_wgl_3dl_stereo_control([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (wglSetStereoEmitterState3DL_ptr = reinterpret_cast<wglSetStereoEmitterState3DLPtr>(get_function("wglSetStereoEmitterState3DL"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region WGL_AMD_gpu_association

using wglGetGPUIDsAMDPtr                      = std::add_pointer_t<decltype(wglGetGPUIDsAMD)>;
using wglGetGPUInfoAMDPtr                     = std::add_pointer_t<decltype(wglGetGPUInfoAMD)>;
using wglGetContextGPUIDAMDPtr                = std::add_pointer_t<decltype(wglGetContextGPUIDAMD)>;
using wglCreateAssociatedContextAMDPtr        = std::add_pointer_t<decltype(wglCreateAssociatedContextAMD)>;
using wglCreateAssociatedContextAttribsAMDPtr = std::add_pointer_t<decltype(wglCreateAssociatedContextAttribsAMD)>;
using wglDeleteAssociatedContextAMDPtr        = std::add_pointer_t<decltype(wglDeleteAssociatedContextAMD)>;
using wglMakeAssociatedContextCurrentAMDPtr   = std::add_pointer_t<decltype(wglMakeAssociatedContextCurrentAMD)>;
using wglGetCurrentAssociatedContextAMDPtr    = std::add_pointer_t<decltype(wglGetCurrentAssociatedContextAMD)>;
using wglBlitContextFramebufferAMDPtr         = std::add_pointer_t<decltype(wglBlitContextFramebufferAMD)>;

wglGetGPUIDsAMDPtr wglGetGPUIDsAMD_ptr                                           = nullptr;
wglGetGPUInfoAMDPtr wglGetGPUInfoAMD_ptr                                         = nullptr;
wglGetContextGPUIDAMDPtr wglGetContextGPUIDAMD_ptr                               = nullptr;
wglCreateAssociatedContextAMDPtr wglCreateAssociatedContextAMD_ptr               = nullptr;
wglCreateAssociatedContextAttribsAMDPtr wglCreateAssociatedContextAttribsAMD_ptr = nullptr;
wglDeleteAssociatedContextAMDPtr wglDeleteAssociatedContextAMD_ptr               = nullptr;
wglMakeAssociatedContextCurrentAMDPtr wglMakeAssociatedContextCurrentAMD_ptr     = nullptr;
wglGetCurrentAssociatedContextAMDPtr wglGetCurrentAssociatedContextAMD_ptr       = nullptr;
wglBlitContextFramebufferAMDPtr wglBlitContextFramebufferAMD_ptr                 = nullptr;

bool init_wgl_amd_gpu_association([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (wglGetGPUIDsAMD_ptr = reinterpret_cast<wglGetGPUIDsAMDPtr>(get_function("wglGetGPUIDsAMD"))) == nullptr || result;
    result = (wglGetGPUInfoAMD_ptr = reinterpret_cast<wglGetGPUInfoAMDPtr>(get_function("wglGetGPUInfoAMD"))) == nullptr || result;
    result = (wglGetContextGPUIDAMD_ptr = reinterpret_cast<wglGetContextGPUIDAMDPtr>(get_function("wglGetContextGPUIDAMD"))) == nullptr || result;
    result = (wglCreateAssociatedContextAMD_ptr = reinterpret_cast<wglCreateAssociatedContextAMDPtr>(get_function("wglCreateAssociatedContextAMD"))) == nullptr || result;
    result = (wglCreateAssociatedContextAttribsAMD_ptr = reinterpret_cast<wglCreateAssociatedContextAttribsAMDPtr>(get_function("wglCreateAssociatedContextAttribsAMD"))) == nullptr || result;
    result = (wglDeleteAssociatedContextAMD_ptr = reinterpret_cast<wglDeleteAssociatedContextAMDPtr>(get_function("wglDeleteAssociatedContextAMD"))) == nullptr || result;
    result = (wglMakeAssociatedContextCurrentAMD_ptr = reinterpret_cast<wglMakeAssociatedContextCurrentAMDPtr>(get_function("wglMakeAssociatedContextCurrentAMD"))) == nullptr || result;
    result = (wglGetCurrentAssociatedContextAMD_ptr = reinterpret_cast<wglGetCurrentAssociatedContextAMDPtr>(get_function("wglGetCurrentAssociatedContextAMD"))) == nullptr || result;
    result = (wglBlitContextFramebufferAMD_ptr = reinterpret_cast<wglBlitContextFramebufferAMDPtr>(get_function("wglBlitContextFramebufferAMD"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region WGL_ARB_buffer_region

using wglCreateBufferRegionARBPtr  = std::add_pointer_t<decltype(wglCreateBufferRegionARB)>;
using wglDeleteBufferRegionARBPtr  = std::add_pointer_t<decltype(wglDeleteBufferRegionARB)>;
using wglSaveBufferRegionARBPtr    = std::add_pointer_t<decltype(wglSaveBufferRegionARB)>;
using wglRestoreBufferRegionARBPtr = std::add_pointer_t<decltype(wglRestoreBufferRegionARB)>;

wglCreateBufferRegionARBPtr wglCreateBufferRegionARB_ptr   = nullptr;
wglDeleteBufferRegionARBPtr wglDeleteBufferRegionARB_ptr   = nullptr;
wglSaveBufferRegionARBPtr wglSaveBufferRegionARB_ptr       = nullptr;
wglRestoreBufferRegionARBPtr wglRestoreBufferRegionARB_ptr = nullptr;

bool init_wgl_arb_buffer_region([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (wglCreateBufferRegionARB_ptr = reinterpret_cast<wglCreateBufferRegionARBPtr>(get_function("wglCreateBufferRegionARB"))) == nullptr || result;
    result = (wglDeleteBufferRegionARB_ptr = reinterpret_cast<wglDeleteBufferRegionARBPtr>(get_function("wglDeleteBufferRegionARB"))) == nullptr || result;
    result = (wglSaveBufferRegionARB_ptr = reinterpret_cast<wglSaveBufferRegionARBPtr>(get_function("wglSaveBufferRegionARB"))) == nullptr || result;
    result = (wglRestoreBufferRegionARB_ptr = reinterpret_cast<wglRestoreBufferRegionARBPtr>(get_function("wglRestoreBufferRegionARB"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region WGL_ARB_context_flush_control

bool init_wgl_arb_context_flush_control([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region WGL_ARB_create_context

using wglCreateContextAttribsARBPtr = std::add_pointer_t<decltype(wglCreateContextAttribsARB)>;

wglCreateContextAttribsARBPtr wglCreateContextAttribsARB_ptr = nullptr;

bool init_wgl_arb_create_context([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (wglCreateContextAttribsARB_ptr = reinterpret_cast<wglCreateContextAttribsARBPtr>(get_function("wglCreateContextAttribsARB"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region WGL_ARB_create_context_no_error

bool init_wgl_arb_create_context_no_error([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region WGL_ARB_create_context_profile

bool init_wgl_arb_create_context_profile([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region WGL_ARB_create_context_robustness

bool init_wgl_arb_create_context_robustness([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region WGL_ARB_extensions_string

using wglGetExtensionsStringARBPtr = std::add_pointer_t<decltype(wglGetExtensionsStringARB)>;

wglGetExtensionsStringARBPtr wglGetExtensionsStringARB_ptr = nullptr;

bool init_wgl_arb_extensions_string([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (wglGetExtensionsStringARB_ptr = reinterpret_cast<wglGetExtensionsStringARBPtr>(get_function("wglGetExtensionsStringARB"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region WGL_ARB_framebuffer_sRGB

bool init_wgl_arb_framebuffer_srgb([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region WGL_ARB_make_current_read

using wglMakeContextCurrentARBPtr = std::add_pointer_t<decltype(wglMakeContextCurrentARB)>;
using wglGetCurrentReadDCARBPtr   = std::add_pointer_t<decltype(wglGetCurrentReadDCARB)>;

wglMakeContextCurrentARBPtr wglMakeContextCurrentARB_ptr = nullptr;
wglGetCurrentReadDCARBPtr wglGetCurrentReadDCARB_ptr     = nullptr;

bool init_wgl_arb_make_current_read([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (wglMakeContextCurrentARB_ptr = reinterpret_cast<wglMakeContextCurrentARBPtr>(get_function("wglMakeContextCurrentARB"))) == nullptr || result;
    result = (wglGetCurrentReadDCARB_ptr = reinterpret_cast<wglGetCurrentReadDCARBPtr>(get_function("wglGetCurrentReadDCARB"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region WGL_ARB_multisample

bool init_wgl_arb_multisample([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region WGL_ARB_pbuffer

using wglCreatePbufferARBPtr    = std::add_pointer_t<decltype(wglCreatePbufferARB)>;
using wglGetPbufferDCARBPtr     = std::add_pointer_t<decltype(wglGetPbufferDCARB)>;
using wglReleasePbufferDCARBPtr = std::add_pointer_t<decltype(wglReleasePbufferDCARB)>;
using wglDestroyPbufferARBPtr   = std::add_pointer_t<decltype(wglDestroyPbufferARB)>;
using wglQueryPbufferARBPtr     = std::add_pointer_t<decltype(wglQueryPbufferARB)>;

wglCreatePbufferARBPtr wglCreatePbufferARB_ptr       = nullptr;
wglGetPbufferDCARBPtr wglGetPbufferDCARB_ptr         = nullptr;
wglReleasePbufferDCARBPtr wglReleasePbufferDCARB_ptr = nullptr;
wglDestroyPbufferARBPtr wglDestroyPbufferARB_ptr     = nullptr;
wglQueryPbufferARBPtr wglQueryPbufferARB_ptr         = nullptr;

bool init_wgl_arb_pbuffer([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (wglCreatePbufferARB_ptr = reinterpret_cast<wglCreatePbufferARBPtr>(get_function("wglCreatePbufferARB"))) == nullptr || result;
    result = (wglGetPbufferDCARB_ptr = reinterpret_cast<wglGetPbufferDCARBPtr>(get_function("wglGetPbufferDCARB"))) == nullptr || result;
    result = (wglReleasePbufferDCARB_ptr = reinterpret_cast<wglReleasePbufferDCARBPtr>(get_function("wglReleasePbufferDCARB"))) == nullptr || result;
    result = (wglDestroyPbufferARB_ptr = reinterpret_cast<wglDestroyPbufferARBPtr>(get_function("wglDestroyPbufferARB"))) == nullptr || result;
    result = (wglQueryPbufferARB_ptr = reinterpret_cast<wglQueryPbufferARBPtr>(get_function("wglQueryPbufferARB"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region WGL_ARB_pixel_format

using wglGetPixelFormatAttribivARBPtr = std::add_pointer_t<decltype(wglGetPixelFormatAttribivARB)>;
using wglGetPixelFormatAttribfvARBPtr = std::add_pointer_t<decltype(wglGetPixelFormatAttribfvARB)>;
using wglChoosePixelFormatARBPtr      = std::add_pointer_t<decltype(wglChoosePixelFormatARB)>;

wglGetPixelFormatAttribivARBPtr wglGetPixelFormatAttribivARB_ptr = nullptr;
wglGetPixelFormatAttribfvARBPtr wglGetPixelFormatAttribfvARB_ptr = nullptr;
wglChoosePixelFormatARBPtr wglChoosePixelFormatARB_ptr           = nullptr;

bool init_wgl_arb_pixel_format([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (wglGetPixelFormatAttribivARB_ptr = reinterpret_cast<wglGetPixelFormatAttribivARBPtr>(get_function("wglGetPixelFormatAttribivARB"))) == nullptr || result;
    result = (wglGetPixelFormatAttribfvARB_ptr = reinterpret_cast<wglGetPixelFormatAttribfvARBPtr>(get_function("wglGetPixelFormatAttribfvARB"))) == nullptr || result;
    result = (wglChoosePixelFormatARB_ptr = reinterpret_cast<wglChoosePixelFormatARBPtr>(get_function("wglChoosePixelFormatARB"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region WGL_ARB_pixel_format_float

bool init_wgl_arb_pixel_format_float([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region WGL_ARB_render_texture

using wglBindTexImageARBPtr     = std::add_pointer_t<decltype(wglBindTexImageARB)>;
using wglReleaseTexImageARBPtr  = std::add_pointer_t<decltype(wglReleaseTexImageARB)>;
using wglSetPbufferAttribARBPtr = std::add_pointer_t<decltype(wglSetPbufferAttribARB)>;

wglBindTexImageARBPtr wglBindTexImageARB_ptr         = nullptr;
wglReleaseTexImageARBPtr wglReleaseTexImageARB_ptr   = nullptr;
wglSetPbufferAttribARBPtr wglSetPbufferAttribARB_ptr = nullptr;

bool init_wgl_arb_render_texture([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (wglBindTexImageARB_ptr = reinterpret_cast<wglBindTexImageARBPtr>(get_function("wglBindTexImageARB"))) == nullptr || result;
    result = (wglReleaseTexImageARB_ptr = reinterpret_cast<wglReleaseTexImageARBPtr>(get_function("wglReleaseTexImageARB"))) == nullptr || result;
    result = (wglSetPbufferAttribARB_ptr = reinterpret_cast<wglSetPbufferAttribARBPtr>(get_function("wglSetPbufferAttribARB"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region WGL_ARB_robustness_application_isolation

bool init_wgl_arb_robustness_application_isolation([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region WGL_ARB_robustness_share_group_isolation

bool init_wgl_arb_robustness_share_group_isolation([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region WGL_ATI_pixel_format_float

bool init_wgl_ati_pixel_format_float([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region WGL_ATI_render_texture_rectangle

bool init_wgl_ati_render_texture_rectangle([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region WGL_EXT_colorspace

bool init_wgl_ext_colorspace([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region WGL_EXT_create_context_es_profile

bool init_wgl_ext_create_context_es_profile([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region WGL_EXT_create_context_es2_profile

bool init_wgl_ext_create_context_es2_profile([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region WGL_EXT_depth_float

bool init_wgl_ext_depth_float([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region WGL_EXT_display_color_table

using wglCreateDisplayColorTableEXTPtr  = std::add_pointer_t<decltype(wglCreateDisplayColorTableEXT)>;
using wglLoadDisplayColorTableEXTPtr    = std::add_pointer_t<decltype(wglLoadDisplayColorTableEXT)>;
using wglBindDisplayColorTableEXTPtr    = std::add_pointer_t<decltype(wglBindDisplayColorTableEXT)>;
using wglDestroyDisplayColorTableEXTPtr = std::add_pointer_t<decltype(wglDestroyDisplayColorTableEXT)>;

wglCreateDisplayColorTableEXTPtr wglCreateDisplayColorTableEXT_ptr   = nullptr;
wglLoadDisplayColorTableEXTPtr wglLoadDisplayColorTableEXT_ptr       = nullptr;
wglBindDisplayColorTableEXTPtr wglBindDisplayColorTableEXT_ptr       = nullptr;
wglDestroyDisplayColorTableEXTPtr wglDestroyDisplayColorTableEXT_ptr = nullptr;

bool init_wgl_ext_display_color_table([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (wglCreateDisplayColorTableEXT_ptr = reinterpret_cast<wglCreateDisplayColorTableEXTPtr>(get_function("wglCreateDisplayColorTableEXT"))) == nullptr || result;
    result = (wglLoadDisplayColorTableEXT_ptr = reinterpret_cast<wglLoadDisplayColorTableEXTPtr>(get_function("wglLoadDisplayColorTableEXT"))) == nullptr || result;
    result = (wglBindDisplayColorTableEXT_ptr = reinterpret_cast<wglBindDisplayColorTableEXTPtr>(get_function("wglBindDisplayColorTableEXT"))) == nullptr || result;
    result = (wglDestroyDisplayColorTableEXT_ptr = reinterpret_cast<wglDestroyDisplayColorTableEXTPtr>(get_function("wglDestroyDisplayColorTableEXT"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region WGL_EXT_extensions_string

using wglGetExtensionsStringEXTPtr = std::add_pointer_t<decltype(wglGetExtensionsStringEXT)>;

wglGetExtensionsStringEXTPtr wglGetExtensionsStringEXT_ptr = nullptr;

bool init_wgl_ext_extensions_string([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (wglGetExtensionsStringEXT_ptr = reinterpret_cast<wglGetExtensionsStringEXTPtr>(get_function("wglGetExtensionsStringEXT"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region WGL_EXT_framebuffer_sRGB

bool init_wgl_ext_framebuffer_srgb([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region WGL_EXT_make_current_read

using wglMakeContextCurrentEXTPtr = std::add_pointer_t<decltype(wglMakeContextCurrentEXT)>;
using wglGetCurrentReadDCEXTPtr   = std::add_pointer_t<decltype(wglGetCurrentReadDCEXT)>;

wglMakeContextCurrentEXTPtr wglMakeContextCurrentEXT_ptr = nullptr;
wglGetCurrentReadDCEXTPtr wglGetCurrentReadDCEXT_ptr     = nullptr;

bool init_wgl_ext_make_current_read([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (wglMakeContextCurrentEXT_ptr = reinterpret_cast<wglMakeContextCurrentEXTPtr>(get_function("wglMakeContextCurrentEXT"))) == nullptr || result;
    result = (wglGetCurrentReadDCEXT_ptr = reinterpret_cast<wglGetCurrentReadDCEXTPtr>(get_function("wglGetCurrentReadDCEXT"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region WGL_EXT_multisample

bool init_wgl_ext_multisample([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region WGL_EXT_pbuffer

using wglCreatePbufferEXTPtr    = std::add_pointer_t<decltype(wglCreatePbufferEXT)>;
using wglGetPbufferDCEXTPtr     = std::add_pointer_t<decltype(wglGetPbufferDCEXT)>;
using wglReleasePbufferDCEXTPtr = std::add_pointer_t<decltype(wglReleasePbufferDCEXT)>;
using wglDestroyPbufferEXTPtr   = std::add_pointer_t<decltype(wglDestroyPbufferEXT)>;
using wglQueryPbufferEXTPtr     = std::add_pointer_t<decltype(wglQueryPbufferEXT)>;

wglCreatePbufferEXTPtr wglCreatePbufferEXT_ptr       = nullptr;
wglGetPbufferDCEXTPtr wglGetPbufferDCEXT_ptr         = nullptr;
wglReleasePbufferDCEXTPtr wglReleasePbufferDCEXT_ptr = nullptr;
wglDestroyPbufferEXTPtr wglDestroyPbufferEXT_ptr     = nullptr;
wglQueryPbufferEXTPtr wglQueryPbufferEXT_ptr         = nullptr;

bool init_wgl_ext_pbuffer([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (wglCreatePbufferEXT_ptr = reinterpret_cast<wglCreatePbufferEXTPtr>(get_function("wglCreatePbufferEXT"))) == nullptr || result;
    result = (wglGetPbufferDCEXT_ptr = reinterpret_cast<wglGetPbufferDCEXTPtr>(get_function("wglGetPbufferDCEXT"))) == nullptr || result;
    result = (wglReleasePbufferDCEXT_ptr = reinterpret_cast<wglReleasePbufferDCEXTPtr>(get_function("wglReleasePbufferDCEXT"))) == nullptr || result;
    result = (wglDestroyPbufferEXT_ptr = reinterpret_cast<wglDestroyPbufferEXTPtr>(get_function("wglDestroyPbufferEXT"))) == nullptr || result;
    result = (wglQueryPbufferEXT_ptr = reinterpret_cast<wglQueryPbufferEXTPtr>(get_function("wglQueryPbufferEXT"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region WGL_EXT_pixel_format

using wglGetPixelFormatAttribivEXTPtr = std::add_pointer_t<decltype(wglGetPixelFormatAttribivEXT)>;
using wglGetPixelFormatAttribfvEXTPtr = std::add_pointer_t<decltype(wglGetPixelFormatAttribfvEXT)>;
using wglChoosePixelFormatEXTPtr      = std::add_pointer_t<decltype(wglChoosePixelFormatEXT)>;

wglGetPixelFormatAttribivEXTPtr wglGetPixelFormatAttribivEXT_ptr = nullptr;
wglGetPixelFormatAttribfvEXTPtr wglGetPixelFormatAttribfvEXT_ptr = nullptr;
wglChoosePixelFormatEXTPtr wglChoosePixelFormatEXT_ptr           = nullptr;

bool init_wgl_ext_pixel_format([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (wglGetPixelFormatAttribivEXT_ptr = reinterpret_cast<wglGetPixelFormatAttribivEXTPtr>(get_function("wglGetPixelFormatAttribivEXT"))) == nullptr || result;
    result = (wglGetPixelFormatAttribfvEXT_ptr = reinterpret_cast<wglGetPixelFormatAttribfvEXTPtr>(get_function("wglGetPixelFormatAttribfvEXT"))) == nullptr || result;
    result = (wglChoosePixelFormatEXT_ptr = reinterpret_cast<wglChoosePixelFormatEXTPtr>(get_function("wglChoosePixelFormatEXT"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region WGL_EXT_pixel_format_packed_float

bool init_wgl_ext_pixel_format_packed_float([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region WGL_EXT_swap_control

using wglSwapIntervalEXTPtr    = std::add_pointer_t<decltype(wglSwapIntervalEXT)>;
using wglGetSwapIntervalEXTPtr = std::add_pointer_t<decltype(wglGetSwapIntervalEXT)>;

wglSwapIntervalEXTPtr wglSwapIntervalEXT_ptr       = nullptr;
wglGetSwapIntervalEXTPtr wglGetSwapIntervalEXT_ptr = nullptr;

bool init_wgl_ext_swap_control([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (wglSwapIntervalEXT_ptr = reinterpret_cast<wglSwapIntervalEXTPtr>(get_function("wglSwapIntervalEXT"))) == nullptr || result;
    result = (wglGetSwapIntervalEXT_ptr = reinterpret_cast<wglGetSwapIntervalEXTPtr>(get_function("wglGetSwapIntervalEXT"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region WGL_EXT_swap_control_tear

bool init_wgl_ext_swap_control_tear([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region WGL_I3D_digital_video_control

using wglGetDigitalVideoParametersI3DPtr = std::add_pointer_t<decltype(wglGetDigitalVideoParametersI3D)>;
using wglSetDigitalVideoParametersI3DPtr = std::add_pointer_t<decltype(wglSetDigitalVideoParametersI3D)>;

wglGetDigitalVideoParametersI3DPtr wglGetDigitalVideoParametersI3D_ptr = nullptr;
wglSetDigitalVideoParametersI3DPtr wglSetDigitalVideoParametersI3D_ptr = nullptr;

bool init_wgl_i3d_digital_video_control([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (wglGetDigitalVideoParametersI3D_ptr = reinterpret_cast<wglGetDigitalVideoParametersI3DPtr>(get_function("wglGetDigitalVideoParametersI3D"))) == nullptr || result;
    result = (wglSetDigitalVideoParametersI3D_ptr = reinterpret_cast<wglSetDigitalVideoParametersI3DPtr>(get_function("wglSetDigitalVideoParametersI3D"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region WGL_I3D_gamma

using wglGetGammaTableParametersI3DPtr = std::add_pointer_t<decltype(wglGetGammaTableParametersI3D)>;
using wglSetGammaTableParametersI3DPtr = std::add_pointer_t<decltype(wglSetGammaTableParametersI3D)>;
using wglGetGammaTableI3DPtr           = std::add_pointer_t<decltype(wglGetGammaTableI3D)>;
using wglSetGammaTableI3DPtr           = std::add_pointer_t<decltype(wglSetGammaTableI3D)>;

wglGetGammaTableParametersI3DPtr wglGetGammaTableParametersI3D_ptr = nullptr;
wglSetGammaTableParametersI3DPtr wglSetGammaTableParametersI3D_ptr = nullptr;
wglGetGammaTableI3DPtr wglGetGammaTableI3D_ptr                     = nullptr;
wglSetGammaTableI3DPtr wglSetGammaTableI3D_ptr                     = nullptr;

bool init_wgl_i3d_gamma([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (wglGetGammaTableParametersI3D_ptr = reinterpret_cast<wglGetGammaTableParametersI3DPtr>(get_function("wglGetGammaTableParametersI3D"))) == nullptr || result;
    result = (wglSetGammaTableParametersI3D_ptr = reinterpret_cast<wglSetGammaTableParametersI3DPtr>(get_function("wglSetGammaTableParametersI3D"))) == nullptr || result;
    result = (wglGetGammaTableI3D_ptr = reinterpret_cast<wglGetGammaTableI3DPtr>(get_function("wglGetGammaTableI3D"))) == nullptr || result;
    result = (wglSetGammaTableI3D_ptr = reinterpret_cast<wglSetGammaTableI3DPtr>(get_function("wglSetGammaTableI3D"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region WGL_I3D_genlock

using wglEnableGenlockI3DPtr              = std::add_pointer_t<decltype(wglEnableGenlockI3D)>;
using wglDisableGenlockI3DPtr             = std::add_pointer_t<decltype(wglDisableGenlockI3D)>;
using wglIsEnabledGenlockI3DPtr           = std::add_pointer_t<decltype(wglIsEnabledGenlockI3D)>;
using wglGenlockSourceI3DPtr              = std::add_pointer_t<decltype(wglGenlockSourceI3D)>;
using wglGetGenlockSourceI3DPtr           = std::add_pointer_t<decltype(wglGetGenlockSourceI3D)>;
using wglGenlockSourceEdgeI3DPtr          = std::add_pointer_t<decltype(wglGenlockSourceEdgeI3D)>;
using wglGetGenlockSourceEdgeI3DPtr       = std::add_pointer_t<decltype(wglGetGenlockSourceEdgeI3D)>;
using wglGenlockSampleRateI3DPtr          = std::add_pointer_t<decltype(wglGenlockSampleRateI3D)>;
using wglGetGenlockSampleRateI3DPtr       = std::add_pointer_t<decltype(wglGetGenlockSampleRateI3D)>;
using wglGenlockSourceDelayI3DPtr         = std::add_pointer_t<decltype(wglGenlockSourceDelayI3D)>;
using wglGetGenlockSourceDelayI3DPtr      = std::add_pointer_t<decltype(wglGetGenlockSourceDelayI3D)>;
using wglQueryGenlockMaxSourceDelayI3DPtr = std::add_pointer_t<decltype(wglQueryGenlockMaxSourceDelayI3D)>;

wglEnableGenlockI3DPtr wglEnableGenlockI3D_ptr                           = nullptr;
wglDisableGenlockI3DPtr wglDisableGenlockI3D_ptr                         = nullptr;
wglIsEnabledGenlockI3DPtr wglIsEnabledGenlockI3D_ptr                     = nullptr;
wglGenlockSourceI3DPtr wglGenlockSourceI3D_ptr                           = nullptr;
wglGetGenlockSourceI3DPtr wglGetGenlockSourceI3D_ptr                     = nullptr;
wglGenlockSourceEdgeI3DPtr wglGenlockSourceEdgeI3D_ptr                   = nullptr;
wglGetGenlockSourceEdgeI3DPtr wglGetGenlockSourceEdgeI3D_ptr             = nullptr;
wglGenlockSampleRateI3DPtr wglGenlockSampleRateI3D_ptr                   = nullptr;
wglGetGenlockSampleRateI3DPtr wglGetGenlockSampleRateI3D_ptr             = nullptr;
wglGenlockSourceDelayI3DPtr wglGenlockSourceDelayI3D_ptr                 = nullptr;
wglGetGenlockSourceDelayI3DPtr wglGetGenlockSourceDelayI3D_ptr           = nullptr;
wglQueryGenlockMaxSourceDelayI3DPtr wglQueryGenlockMaxSourceDelayI3D_ptr = nullptr;

bool init_wgl_i3d_genlock([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (wglEnableGenlockI3D_ptr = reinterpret_cast<wglEnableGenlockI3DPtr>(get_function("wglEnableGenlockI3D"))) == nullptr || result;
    result = (wglDisableGenlockI3D_ptr = reinterpret_cast<wglDisableGenlockI3DPtr>(get_function("wglDisableGenlockI3D"))) == nullptr || result;
    result = (wglIsEnabledGenlockI3D_ptr = reinterpret_cast<wglIsEnabledGenlockI3DPtr>(get_function("wglIsEnabledGenlockI3D"))) == nullptr || result;
    result = (wglGenlockSourceI3D_ptr = reinterpret_cast<wglGenlockSourceI3DPtr>(get_function("wglGenlockSourceI3D"))) == nullptr || result;
    result = (wglGetGenlockSourceI3D_ptr = reinterpret_cast<wglGetGenlockSourceI3DPtr>(get_function("wglGetGenlockSourceI3D"))) == nullptr || result;
    result = (wglGenlockSourceEdgeI3D_ptr = reinterpret_cast<wglGenlockSourceEdgeI3DPtr>(get_function("wglGenlockSourceEdgeI3D"))) == nullptr || result;
    result = (wglGetGenlockSourceEdgeI3D_ptr = reinterpret_cast<wglGetGenlockSourceEdgeI3DPtr>(get_function("wglGetGenlockSourceEdgeI3D"))) == nullptr || result;
    result = (wglGenlockSampleRateI3D_ptr = reinterpret_cast<wglGenlockSampleRateI3DPtr>(get_function("wglGenlockSampleRateI3D"))) == nullptr || result;
    result = (wglGetGenlockSampleRateI3D_ptr = reinterpret_cast<wglGetGenlockSampleRateI3DPtr>(get_function("wglGetGenlockSampleRateI3D"))) == nullptr || result;
    result = (wglGenlockSourceDelayI3D_ptr = reinterpret_cast<wglGenlockSourceDelayI3DPtr>(get_function("wglGenlockSourceDelayI3D"))) == nullptr || result;
    result = (wglGetGenlockSourceDelayI3D_ptr = reinterpret_cast<wglGetGenlockSourceDelayI3DPtr>(get_function("wglGetGenlockSourceDelayI3D"))) == nullptr || result;
    result = (wglQueryGenlockMaxSourceDelayI3D_ptr = reinterpret_cast<wglQueryGenlockMaxSourceDelayI3DPtr>(get_function("wglQueryGenlockMaxSourceDelayI3D"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region WGL_I3D_image_buffer

using wglCreateImageBufferI3DPtr          = std::add_pointer_t<decltype(wglCreateImageBufferI3D)>;
using wglDestroyImageBufferI3DPtr         = std::add_pointer_t<decltype(wglDestroyImageBufferI3D)>;
using wglAssociateImageBufferEventsI3DPtr = std::add_pointer_t<decltype(wglAssociateImageBufferEventsI3D)>;
using wglReleaseImageBufferEventsI3DPtr   = std::add_pointer_t<decltype(wglReleaseImageBufferEventsI3D)>;

wglCreateImageBufferI3DPtr wglCreateImageBufferI3D_ptr                   = nullptr;
wglDestroyImageBufferI3DPtr wglDestroyImageBufferI3D_ptr                 = nullptr;
wglAssociateImageBufferEventsI3DPtr wglAssociateImageBufferEventsI3D_ptr = nullptr;
wglReleaseImageBufferEventsI3DPtr wglReleaseImageBufferEventsI3D_ptr     = nullptr;

bool init_wgl_i3d_image_buffer([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (wglCreateImageBufferI3D_ptr = reinterpret_cast<wglCreateImageBufferI3DPtr>(get_function("wglCreateImageBufferI3D"))) == nullptr || result;
    result = (wglDestroyImageBufferI3D_ptr = reinterpret_cast<wglDestroyImageBufferI3DPtr>(get_function("wglDestroyImageBufferI3D"))) == nullptr || result;
    result = (wglAssociateImageBufferEventsI3D_ptr = reinterpret_cast<wglAssociateImageBufferEventsI3DPtr>(get_function("wglAssociateImageBufferEventsI3D"))) == nullptr || result;
    result = (wglReleaseImageBufferEventsI3D_ptr = reinterpret_cast<wglReleaseImageBufferEventsI3DPtr>(get_function("wglReleaseImageBufferEventsI3D"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region WGL_I3D_swap_frame_lock

using wglEnableFrameLockI3DPtr      = std::add_pointer_t<decltype(wglEnableFrameLockI3D)>;
using wglDisableFrameLockI3DPtr     = std::add_pointer_t<decltype(wglDisableFrameLockI3D)>;
using wglIsEnabledFrameLockI3DPtr   = std::add_pointer_t<decltype(wglIsEnabledFrameLockI3D)>;
using wglQueryFrameLockMasterI3DPtr = std::add_pointer_t<decltype(wglQueryFrameLockMasterI3D)>;

wglEnableFrameLockI3DPtr wglEnableFrameLockI3D_ptr           = nullptr;
wglDisableFrameLockI3DPtr wglDisableFrameLockI3D_ptr         = nullptr;
wglIsEnabledFrameLockI3DPtr wglIsEnabledFrameLockI3D_ptr     = nullptr;
wglQueryFrameLockMasterI3DPtr wglQueryFrameLockMasterI3D_ptr = nullptr;

bool init_wgl_i3d_swap_frame_lock([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (wglEnableFrameLockI3D_ptr = reinterpret_cast<wglEnableFrameLockI3DPtr>(get_function("wglEnableFrameLockI3D"))) == nullptr || result;
    result = (wglDisableFrameLockI3D_ptr = reinterpret_cast<wglDisableFrameLockI3DPtr>(get_function("wglDisableFrameLockI3D"))) == nullptr || result;
    result = (wglIsEnabledFrameLockI3D_ptr = reinterpret_cast<wglIsEnabledFrameLockI3DPtr>(get_function("wglIsEnabledFrameLockI3D"))) == nullptr || result;
    result = (wglQueryFrameLockMasterI3D_ptr = reinterpret_cast<wglQueryFrameLockMasterI3DPtr>(get_function("wglQueryFrameLockMasterI3D"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region WGL_I3D_swap_frame_usage

using wglGetFrameUsageI3DPtr      = std::add_pointer_t<decltype(wglGetFrameUsageI3D)>;
using wglBeginFrameTrackingI3DPtr = std::add_pointer_t<decltype(wglBeginFrameTrackingI3D)>;
using wglEndFrameTrackingI3DPtr   = std::add_pointer_t<decltype(wglEndFrameTrackingI3D)>;
using wglQueryFrameTrackingI3DPtr = std::add_pointer_t<decltype(wglQueryFrameTrackingI3D)>;

wglGetFrameUsageI3DPtr wglGetFrameUsageI3D_ptr           = nullptr;
wglBeginFrameTrackingI3DPtr wglBeginFrameTrackingI3D_ptr = nullptr;
wglEndFrameTrackingI3DPtr wglEndFrameTrackingI3D_ptr     = nullptr;
wglQueryFrameTrackingI3DPtr wglQueryFrameTrackingI3D_ptr = nullptr;

bool init_wgl_i3d_swap_frame_usage([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (wglGetFrameUsageI3D_ptr = reinterpret_cast<wglGetFrameUsageI3DPtr>(get_function("wglGetFrameUsageI3D"))) == nullptr || result;
    result = (wglBeginFrameTrackingI3D_ptr = reinterpret_cast<wglBeginFrameTrackingI3DPtr>(get_function("wglBeginFrameTrackingI3D"))) == nullptr || result;
    result = (wglEndFrameTrackingI3D_ptr = reinterpret_cast<wglEndFrameTrackingI3DPtr>(get_function("wglEndFrameTrackingI3D"))) == nullptr || result;
    result = (wglQueryFrameTrackingI3D_ptr = reinterpret_cast<wglQueryFrameTrackingI3DPtr>(get_function("wglQueryFrameTrackingI3D"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region WGL_NV_copy_image

using wglCopyImageSubDataNVPtr = std::add_pointer_t<decltype(wglCopyImageSubDataNV)>;

wglCopyImageSubDataNVPtr wglCopyImageSubDataNV_ptr = nullptr;

bool init_wgl_nv_copy_image([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (wglCopyImageSubDataNV_ptr = reinterpret_cast<wglCopyImageSubDataNVPtr>(get_function("wglCopyImageSubDataNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region WGL_NV_delay_before_swap

using wglDelayBeforeSwapNVPtr = std::add_pointer_t<decltype(wglDelayBeforeSwapNV)>;

wglDelayBeforeSwapNVPtr wglDelayBeforeSwapNV_ptr = nullptr;

bool init_wgl_nv_delay_before_swap([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (wglDelayBeforeSwapNV_ptr = reinterpret_cast<wglDelayBeforeSwapNVPtr>(get_function("wglDelayBeforeSwapNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region WGL_NV_DX_interop

using wglDXSetResourceShareHandleNVPtr = std::add_pointer_t<decltype(wglDXSetResourceShareHandleNV)>;
using wglDXOpenDeviceNVPtr             = std::add_pointer_t<decltype(wglDXOpenDeviceNV)>;
using wglDXCloseDeviceNVPtr            = std::add_pointer_t<decltype(wglDXCloseDeviceNV)>;
using wglDXRegisterObjectNVPtr         = std::add_pointer_t<decltype(wglDXRegisterObjectNV)>;
using wglDXUnregisterObjectNVPtr       = std::add_pointer_t<decltype(wglDXUnregisterObjectNV)>;
using wglDXObjectAccessNVPtr           = std::add_pointer_t<decltype(wglDXObjectAccessNV)>;
using wglDXLockObjectsNVPtr            = std::add_pointer_t<decltype(wglDXLockObjectsNV)>;
using wglDXUnlockObjectsNVPtr          = std::add_pointer_t<decltype(wglDXUnlockObjectsNV)>;

wglDXSetResourceShareHandleNVPtr wglDXSetResourceShareHandleNV_ptr = nullptr;
wglDXOpenDeviceNVPtr wglDXOpenDeviceNV_ptr                         = nullptr;
wglDXCloseDeviceNVPtr wglDXCloseDeviceNV_ptr                       = nullptr;
wglDXRegisterObjectNVPtr wglDXRegisterObjectNV_ptr                 = nullptr;
wglDXUnregisterObjectNVPtr wglDXUnregisterObjectNV_ptr             = nullptr;
wglDXObjectAccessNVPtr wglDXObjectAccessNV_ptr                     = nullptr;
wglDXLockObjectsNVPtr wglDXLockObjectsNV_ptr                       = nullptr;
wglDXUnlockObjectsNVPtr wglDXUnlockObjectsNV_ptr                   = nullptr;

bool init_wgl_nv_dx_interop([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (wglDXSetResourceShareHandleNV_ptr = reinterpret_cast<wglDXSetResourceShareHandleNVPtr>(get_function("wglDXSetResourceShareHandleNV"))) == nullptr || result;
    result = (wglDXOpenDeviceNV_ptr = reinterpret_cast<wglDXOpenDeviceNVPtr>(get_function("wglDXOpenDeviceNV"))) == nullptr || result;
    result = (wglDXCloseDeviceNV_ptr = reinterpret_cast<wglDXCloseDeviceNVPtr>(get_function("wglDXCloseDeviceNV"))) == nullptr || result;
    result = (wglDXRegisterObjectNV_ptr = reinterpret_cast<wglDXRegisterObjectNVPtr>(get_function("wglDXRegisterObjectNV"))) == nullptr || result;
    result = (wglDXUnregisterObjectNV_ptr = reinterpret_cast<wglDXUnregisterObjectNVPtr>(get_function("wglDXUnregisterObjectNV"))) == nullptr || result;
    result = (wglDXObjectAccessNV_ptr = reinterpret_cast<wglDXObjectAccessNVPtr>(get_function("wglDXObjectAccessNV"))) == nullptr || result;
    result = (wglDXLockObjectsNV_ptr = reinterpret_cast<wglDXLockObjectsNVPtr>(get_function("wglDXLockObjectsNV"))) == nullptr || result;
    result = (wglDXUnlockObjectsNV_ptr = reinterpret_cast<wglDXUnlockObjectsNVPtr>(get_function("wglDXUnlockObjectsNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region WGL_NV_DX_interop2

bool init_wgl_nv_dx_interop2([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region WGL_NV_float_buffer

bool init_wgl_nv_float_buffer([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region WGL_NV_gpu_affinity

using wglEnumGpusNVPtr               = std::add_pointer_t<decltype(wglEnumGpusNV)>;
using wglEnumGpuDevicesNVPtr         = std::add_pointer_t<decltype(wglEnumGpuDevicesNV)>;
using wglCreateAffinityDCNVPtr       = std::add_pointer_t<decltype(wglCreateAffinityDCNV)>;
using wglEnumGpusFromAffinityDCNVPtr = std::add_pointer_t<decltype(wglEnumGpusFromAffinityDCNV)>;
using wglDeleteDCNVPtr               = std::add_pointer_t<decltype(wglDeleteDCNV)>;

wglEnumGpusNVPtr wglEnumGpusNV_ptr                             = nullptr;
wglEnumGpuDevicesNVPtr wglEnumGpuDevicesNV_ptr                 = nullptr;
wglCreateAffinityDCNVPtr wglCreateAffinityDCNV_ptr             = nullptr;
wglEnumGpusFromAffinityDCNVPtr wglEnumGpusFromAffinityDCNV_ptr = nullptr;
wglDeleteDCNVPtr wglDeleteDCNV_ptr                             = nullptr;

bool init_wgl_nv_gpu_affinity([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (wglEnumGpusNV_ptr = reinterpret_cast<wglEnumGpusNVPtr>(get_function("wglEnumGpusNV"))) == nullptr || result;
    result = (wglEnumGpuDevicesNV_ptr = reinterpret_cast<wglEnumGpuDevicesNVPtr>(get_function("wglEnumGpuDevicesNV"))) == nullptr || result;
    result = (wglCreateAffinityDCNV_ptr = reinterpret_cast<wglCreateAffinityDCNVPtr>(get_function("wglCreateAffinityDCNV"))) == nullptr || result;
    result = (wglEnumGpusFromAffinityDCNV_ptr = reinterpret_cast<wglEnumGpusFromAffinityDCNVPtr>(get_function("wglEnumGpusFromAffinityDCNV"))) == nullptr || result;
    result = (wglDeleteDCNV_ptr = reinterpret_cast<wglDeleteDCNVPtr>(get_function("wglDeleteDCNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region WGL_NV_multisample_coverage

bool init_wgl_nv_multisample_coverage([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region WGL_NV_present_video

using wglEnumerateVideoDevicesNVPtr = std::add_pointer_t<decltype(wglEnumerateVideoDevicesNV)>;
using wglBindVideoDeviceNVPtr       = std::add_pointer_t<decltype(wglBindVideoDeviceNV)>;
using wglQueryCurrentContextNVPtr   = std::add_pointer_t<decltype(wglQueryCurrentContextNV)>;

wglEnumerateVideoDevicesNVPtr wglEnumerateVideoDevicesNV_ptr = nullptr;
wglBindVideoDeviceNVPtr wglBindVideoDeviceNV_ptr             = nullptr;
wglQueryCurrentContextNVPtr wglQueryCurrentContextNV_ptr     = nullptr;

bool init_wgl_nv_present_video([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (wglEnumerateVideoDevicesNV_ptr = reinterpret_cast<wglEnumerateVideoDevicesNVPtr>(get_function("wglEnumerateVideoDevicesNV"))) == nullptr || result;
    result = (wglBindVideoDeviceNV_ptr = reinterpret_cast<wglBindVideoDeviceNVPtr>(get_function("wglBindVideoDeviceNV"))) == nullptr || result;
    result = (wglQueryCurrentContextNV_ptr = reinterpret_cast<wglQueryCurrentContextNVPtr>(get_function("wglQueryCurrentContextNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region WGL_NV_render_depth_texture

bool init_wgl_nv_render_depth_texture([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region WGL_NV_render_texture_rectangle

bool init_wgl_nv_render_texture_rectangle([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region WGL_NV_swap_group

using wglJoinSwapGroupNVPtr      = std::add_pointer_t<decltype(wglJoinSwapGroupNV)>;
using wglBindSwapBarrierNVPtr    = std::add_pointer_t<decltype(wglBindSwapBarrierNV)>;
using wglQuerySwapGroupNVPtr     = std::add_pointer_t<decltype(wglQuerySwapGroupNV)>;
using wglQueryMaxSwapGroupsNVPtr = std::add_pointer_t<decltype(wglQueryMaxSwapGroupsNV)>;
using wglQueryFrameCountNVPtr    = std::add_pointer_t<decltype(wglQueryFrameCountNV)>;
using wglResetFrameCountNVPtr    = std::add_pointer_t<decltype(wglResetFrameCountNV)>;

wglJoinSwapGroupNVPtr wglJoinSwapGroupNV_ptr           = nullptr;
wglBindSwapBarrierNVPtr wglBindSwapBarrierNV_ptr       = nullptr;
wglQuerySwapGroupNVPtr wglQuerySwapGroupNV_ptr         = nullptr;
wglQueryMaxSwapGroupsNVPtr wglQueryMaxSwapGroupsNV_ptr = nullptr;
wglQueryFrameCountNVPtr wglQueryFrameCountNV_ptr       = nullptr;
wglResetFrameCountNVPtr wglResetFrameCountNV_ptr       = nullptr;

bool init_wgl_nv_swap_group([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (wglJoinSwapGroupNV_ptr = reinterpret_cast<wglJoinSwapGroupNVPtr>(get_function("wglJoinSwapGroupNV"))) == nullptr || result;
    result = (wglBindSwapBarrierNV_ptr = reinterpret_cast<wglBindSwapBarrierNVPtr>(get_function("wglBindSwapBarrierNV"))) == nullptr || result;
    result = (wglQuerySwapGroupNV_ptr = reinterpret_cast<wglQuerySwapGroupNVPtr>(get_function("wglQuerySwapGroupNV"))) == nullptr || result;
    result = (wglQueryMaxSwapGroupsNV_ptr = reinterpret_cast<wglQueryMaxSwapGroupsNVPtr>(get_function("wglQueryMaxSwapGroupsNV"))) == nullptr || result;
    result = (wglQueryFrameCountNV_ptr = reinterpret_cast<wglQueryFrameCountNVPtr>(get_function("wglQueryFrameCountNV"))) == nullptr || result;
    result = (wglResetFrameCountNV_ptr = reinterpret_cast<wglResetFrameCountNVPtr>(get_function("wglResetFrameCountNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region WGL_NV_video_capture

using wglBindVideoCaptureDeviceNVPtr       = std::add_pointer_t<decltype(wglBindVideoCaptureDeviceNV)>;
using wglEnumerateVideoCaptureDevicesNVPtr = std::add_pointer_t<decltype(wglEnumerateVideoCaptureDevicesNV)>;
using wglLockVideoCaptureDeviceNVPtr       = std::add_pointer_t<decltype(wglLockVideoCaptureDeviceNV)>;
using wglQueryVideoCaptureDeviceNVPtr      = std::add_pointer_t<decltype(wglQueryVideoCaptureDeviceNV)>;
using wglReleaseVideoCaptureDeviceNVPtr    = std::add_pointer_t<decltype(wglReleaseVideoCaptureDeviceNV)>;

wglBindVideoCaptureDeviceNVPtr wglBindVideoCaptureDeviceNV_ptr             = nullptr;
wglEnumerateVideoCaptureDevicesNVPtr wglEnumerateVideoCaptureDevicesNV_ptr = nullptr;
wglLockVideoCaptureDeviceNVPtr wglLockVideoCaptureDeviceNV_ptr             = nullptr;
wglQueryVideoCaptureDeviceNVPtr wglQueryVideoCaptureDeviceNV_ptr           = nullptr;
wglReleaseVideoCaptureDeviceNVPtr wglReleaseVideoCaptureDeviceNV_ptr       = nullptr;

bool init_wgl_nv_video_capture([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (wglBindVideoCaptureDeviceNV_ptr = reinterpret_cast<wglBindVideoCaptureDeviceNVPtr>(get_function("wglBindVideoCaptureDeviceNV"))) == nullptr || result;
    result = (wglEnumerateVideoCaptureDevicesNV_ptr = reinterpret_cast<wglEnumerateVideoCaptureDevicesNVPtr>(get_function("wglEnumerateVideoCaptureDevicesNV"))) == nullptr || result;
    result = (wglLockVideoCaptureDeviceNV_ptr = reinterpret_cast<wglLockVideoCaptureDeviceNVPtr>(get_function("wglLockVideoCaptureDeviceNV"))) == nullptr || result;
    result = (wglQueryVideoCaptureDeviceNV_ptr = reinterpret_cast<wglQueryVideoCaptureDeviceNVPtr>(get_function("wglQueryVideoCaptureDeviceNV"))) == nullptr || result;
    result = (wglReleaseVideoCaptureDeviceNV_ptr = reinterpret_cast<wglReleaseVideoCaptureDeviceNVPtr>(get_function("wglReleaseVideoCaptureDeviceNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region WGL_NV_video_output

using wglGetVideoDeviceNVPtr     = std::add_pointer_t<decltype(wglGetVideoDeviceNV)>;
using wglReleaseVideoDeviceNVPtr = std::add_pointer_t<decltype(wglReleaseVideoDeviceNV)>;
using wglBindVideoImageNVPtr     = std::add_pointer_t<decltype(wglBindVideoImageNV)>;
using wglReleaseVideoImageNVPtr  = std::add_pointer_t<decltype(wglReleaseVideoImageNV)>;
using wglSendPbufferToVideoNVPtr = std::add_pointer_t<decltype(wglSendPbufferToVideoNV)>;
using wglGetVideoInfoNVPtr       = std::add_pointer_t<decltype(wglGetVideoInfoNV)>;

wglGetVideoDeviceNVPtr wglGetVideoDeviceNV_ptr         = nullptr;
wglReleaseVideoDeviceNVPtr wglReleaseVideoDeviceNV_ptr = nullptr;
wglBindVideoImageNVPtr wglBindVideoImageNV_ptr         = nullptr;
wglReleaseVideoImageNVPtr wglReleaseVideoImageNV_ptr   = nullptr;
wglSendPbufferToVideoNVPtr wglSendPbufferToVideoNV_ptr = nullptr;
wglGetVideoInfoNVPtr wglGetVideoInfoNV_ptr             = nullptr;

bool init_wgl_nv_video_output([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (wglGetVideoDeviceNV_ptr = reinterpret_cast<wglGetVideoDeviceNVPtr>(get_function("wglGetVideoDeviceNV"))) == nullptr || result;
    result = (wglReleaseVideoDeviceNV_ptr = reinterpret_cast<wglReleaseVideoDeviceNVPtr>(get_function("wglReleaseVideoDeviceNV"))) == nullptr || result;
    result = (wglBindVideoImageNV_ptr = reinterpret_cast<wglBindVideoImageNVPtr>(get_function("wglBindVideoImageNV"))) == nullptr || result;
    result = (wglReleaseVideoImageNV_ptr = reinterpret_cast<wglReleaseVideoImageNVPtr>(get_function("wglReleaseVideoImageNV"))) == nullptr || result;
    result = (wglSendPbufferToVideoNV_ptr = reinterpret_cast<wglSendPbufferToVideoNVPtr>(get_function("wglSendPbufferToVideoNV"))) == nullptr || result;
    result = (wglGetVideoInfoNV_ptr = reinterpret_cast<wglGetVideoInfoNVPtr>(get_function("wglGetVideoInfoNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region WGL_NV_vertex_array_range

using wglAllocateMemoryNVPtr = std::add_pointer_t<decltype(wglAllocateMemoryNV)>;
using wglFreeMemoryNVPtr     = std::add_pointer_t<decltype(wglFreeMemoryNV)>;

wglAllocateMemoryNVPtr wglAllocateMemoryNV_ptr = nullptr;
wglFreeMemoryNVPtr wglFreeMemoryNV_ptr         = nullptr;

bool init_wgl_nv_vertex_array_range([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (wglAllocateMemoryNV_ptr = reinterpret_cast<wglAllocateMemoryNVPtr>(get_function("wglAllocateMemoryNV"))) == nullptr || result;
    result = (wglFreeMemoryNV_ptr = reinterpret_cast<wglFreeMemoryNVPtr>(get_function("wglFreeMemoryNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region WGL_OML_sync_control

using wglGetSyncValuesOMLPtr       = std::add_pointer_t<decltype(wglGetSyncValuesOML)>;
using wglGetMscRateOMLPtr          = std::add_pointer_t<decltype(wglGetMscRateOML)>;
using wglSwapBuffersMscOMLPtr      = std::add_pointer_t<decltype(wglSwapBuffersMscOML)>;
using wglSwapLayerBuffersMscOMLPtr = std::add_pointer_t<decltype(wglSwapLayerBuffersMscOML)>;
using wglWaitForMscOMLPtr          = std::add_pointer_t<decltype(wglWaitForMscOML)>;
using wglWaitForSbcOMLPtr          = std::add_pointer_t<decltype(wglWaitForSbcOML)>;

wglGetSyncValuesOMLPtr wglGetSyncValuesOML_ptr             = nullptr;
wglGetMscRateOMLPtr wglGetMscRateOML_ptr                   = nullptr;
wglSwapBuffersMscOMLPtr wglSwapBuffersMscOML_ptr           = nullptr;
wglSwapLayerBuffersMscOMLPtr wglSwapLayerBuffersMscOML_ptr = nullptr;
wglWaitForMscOMLPtr wglWaitForMscOML_ptr                   = nullptr;
wglWaitForSbcOMLPtr wglWaitForSbcOML_ptr                   = nullptr;

bool init_wgl_oml_sync_control([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (wglGetSyncValuesOML_ptr = reinterpret_cast<wglGetSyncValuesOMLPtr>(get_function("wglGetSyncValuesOML"))) == nullptr || result;
    result = (wglGetMscRateOML_ptr = reinterpret_cast<wglGetMscRateOMLPtr>(get_function("wglGetMscRateOML"))) == nullptr || result;
    result = (wglSwapBuffersMscOML_ptr = reinterpret_cast<wglSwapBuffersMscOMLPtr>(get_function("wglSwapBuffersMscOML"))) == nullptr || result;
    result = (wglSwapLayerBuffersMscOML_ptr = reinterpret_cast<wglSwapLayerBuffersMscOMLPtr>(get_function("wglSwapLayerBuffersMscOML"))) == nullptr || result;
    result = (wglWaitForMscOML_ptr = reinterpret_cast<wglWaitForMscOMLPtr>(get_function("wglWaitForMscOML"))) == nullptr || result;
    result = (wglWaitForSbcOML_ptr = reinterpret_cast<wglWaitForSbcOMLPtr>(get_function("wglWaitForSbcOML"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region WGL_NV_multigpu_context

bool init_wgl_nv_multigpu_context([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

std::once_flag init_flag;

bool extension_cache[57] = {};

void init_features([[maybe_unused]] const GetFunction& get_function)
{
    // clang-format off

    // clang-format on
}

void init_extensions([[maybe_unused]] const GetFunction& get_function)
{
    // clang-format off
    extension_cache[static_cast<int>(Extension::WGL_3DFX_multisample)] = init_wgl_3dfx_multisample(get_function);
    extension_cache[static_cast<int>(Extension::WGL_3DL_stereo_control)] = init_wgl_3dl_stereo_control(get_function);
    extension_cache[static_cast<int>(Extension::WGL_AMD_gpu_association)] = init_wgl_amd_gpu_association(get_function);
    extension_cache[static_cast<int>(Extension::WGL_ARB_buffer_region)] = init_wgl_arb_buffer_region(get_function);
    extension_cache[static_cast<int>(Extension::WGL_ARB_context_flush_control)] = init_wgl_arb_context_flush_control(get_function);
    extension_cache[static_cast<int>(Extension::WGL_ARB_create_context)] = init_wgl_arb_create_context(get_function);
    extension_cache[static_cast<int>(Extension::WGL_ARB_create_context_no_error)] = init_wgl_arb_create_context_no_error(get_function);
    extension_cache[static_cast<int>(Extension::WGL_ARB_create_context_profile)] = init_wgl_arb_create_context_profile(get_function);
    extension_cache[static_cast<int>(Extension::WGL_ARB_create_context_robustness)] = init_wgl_arb_create_context_robustness(get_function);
    extension_cache[static_cast<int>(Extension::WGL_ARB_extensions_string)] = init_wgl_arb_extensions_string(get_function);
    extension_cache[static_cast<int>(Extension::WGL_ARB_framebuffer_sRGB)] = init_wgl_arb_framebuffer_srgb(get_function);
    extension_cache[static_cast<int>(Extension::WGL_ARB_make_current_read)] = init_wgl_arb_make_current_read(get_function);
    extension_cache[static_cast<int>(Extension::WGL_ARB_multisample)] = init_wgl_arb_multisample(get_function);
    extension_cache[static_cast<int>(Extension::WGL_ARB_pbuffer)] = init_wgl_arb_pbuffer(get_function);
    extension_cache[static_cast<int>(Extension::WGL_ARB_pixel_format)] = init_wgl_arb_pixel_format(get_function);
    extension_cache[static_cast<int>(Extension::WGL_ARB_pixel_format_float)] = init_wgl_arb_pixel_format_float(get_function);
    extension_cache[static_cast<int>(Extension::WGL_ARB_render_texture)] = init_wgl_arb_render_texture(get_function);
    extension_cache[static_cast<int>(Extension::WGL_ARB_robustness_application_isolation)] = init_wgl_arb_robustness_application_isolation(get_function);
    extension_cache[static_cast<int>(Extension::WGL_ARB_robustness_share_group_isolation)] = init_wgl_arb_robustness_share_group_isolation(get_function);
    extension_cache[static_cast<int>(Extension::WGL_ATI_pixel_format_float)] = init_wgl_ati_pixel_format_float(get_function);
    extension_cache[static_cast<int>(Extension::WGL_ATI_render_texture_rectangle)] = init_wgl_ati_render_texture_rectangle(get_function);
    extension_cache[static_cast<int>(Extension::WGL_EXT_colorspace)] = init_wgl_ext_colorspace(get_function);
    extension_cache[static_cast<int>(Extension::WGL_EXT_create_context_es_profile)] = init_wgl_ext_create_context_es_profile(get_function);
    extension_cache[static_cast<int>(Extension::WGL_EXT_create_context_es2_profile)] = init_wgl_ext_create_context_es2_profile(get_function);
    extension_cache[static_cast<int>(Extension::WGL_EXT_depth_float)] = init_wgl_ext_depth_float(get_function);
    extension_cache[static_cast<int>(Extension::WGL_EXT_display_color_table)] = init_wgl_ext_display_color_table(get_function);
    extension_cache[static_cast<int>(Extension::WGL_EXT_extensions_string)] = init_wgl_ext_extensions_string(get_function);
    extension_cache[static_cast<int>(Extension::WGL_EXT_framebuffer_sRGB)] = init_wgl_ext_framebuffer_srgb(get_function);
    extension_cache[static_cast<int>(Extension::WGL_EXT_make_current_read)] = init_wgl_ext_make_current_read(get_function);
    extension_cache[static_cast<int>(Extension::WGL_EXT_multisample)] = init_wgl_ext_multisample(get_function);
    extension_cache[static_cast<int>(Extension::WGL_EXT_pbuffer)] = init_wgl_ext_pbuffer(get_function);
    extension_cache[static_cast<int>(Extension::WGL_EXT_pixel_format)] = init_wgl_ext_pixel_format(get_function);
    extension_cache[static_cast<int>(Extension::WGL_EXT_pixel_format_packed_float)] = init_wgl_ext_pixel_format_packed_float(get_function);
    extension_cache[static_cast<int>(Extension::WGL_EXT_swap_control)] = init_wgl_ext_swap_control(get_function);
    extension_cache[static_cast<int>(Extension::WGL_EXT_swap_control_tear)] = init_wgl_ext_swap_control_tear(get_function);
    extension_cache[static_cast<int>(Extension::WGL_I3D_digital_video_control)] = init_wgl_i3d_digital_video_control(get_function);
    extension_cache[static_cast<int>(Extension::WGL_I3D_gamma)] = init_wgl_i3d_gamma(get_function);
    extension_cache[static_cast<int>(Extension::WGL_I3D_genlock)] = init_wgl_i3d_genlock(get_function);
    extension_cache[static_cast<int>(Extension::WGL_I3D_image_buffer)] = init_wgl_i3d_image_buffer(get_function);
    extension_cache[static_cast<int>(Extension::WGL_I3D_swap_frame_lock)] = init_wgl_i3d_swap_frame_lock(get_function);
    extension_cache[static_cast<int>(Extension::WGL_I3D_swap_frame_usage)] = init_wgl_i3d_swap_frame_usage(get_function);
    extension_cache[static_cast<int>(Extension::WGL_NV_copy_image)] = init_wgl_nv_copy_image(get_function);
    extension_cache[static_cast<int>(Extension::WGL_NV_delay_before_swap)] = init_wgl_nv_delay_before_swap(get_function);
    extension_cache[static_cast<int>(Extension::WGL_NV_DX_interop)] = init_wgl_nv_dx_interop(get_function);
    extension_cache[static_cast<int>(Extension::WGL_NV_DX_interop2)] = init_wgl_nv_dx_interop2(get_function);
    extension_cache[static_cast<int>(Extension::WGL_NV_float_buffer)] = init_wgl_nv_float_buffer(get_function);
    extension_cache[static_cast<int>(Extension::WGL_NV_gpu_affinity)] = init_wgl_nv_gpu_affinity(get_function);
    extension_cache[static_cast<int>(Extension::WGL_NV_multisample_coverage)] = init_wgl_nv_multisample_coverage(get_function);
    extension_cache[static_cast<int>(Extension::WGL_NV_present_video)] = init_wgl_nv_present_video(get_function);
    extension_cache[static_cast<int>(Extension::WGL_NV_render_depth_texture)] = init_wgl_nv_render_depth_texture(get_function);
    extension_cache[static_cast<int>(Extension::WGL_NV_render_texture_rectangle)] = init_wgl_nv_render_texture_rectangle(get_function);
    extension_cache[static_cast<int>(Extension::WGL_NV_swap_group)] = init_wgl_nv_swap_group(get_function);
    extension_cache[static_cast<int>(Extension::WGL_NV_video_capture)] = init_wgl_nv_video_capture(get_function);
    extension_cache[static_cast<int>(Extension::WGL_NV_video_output)] = init_wgl_nv_video_output(get_function);
    extension_cache[static_cast<int>(Extension::WGL_NV_vertex_array_range)] = init_wgl_nv_vertex_array_range(get_function);
    extension_cache[static_cast<int>(Extension::WGL_OML_sync_control)] = init_wgl_oml_sync_control(get_function);
    extension_cache[static_cast<int>(Extension::WGL_NV_multigpu_context)] = init_wgl_nv_multigpu_context(get_function);
    // clang-format on
}

} // namespace

namespace framework::system::details::wgl
{

#pragma region WGL_3DFX_multisample

#pragma endregion

#pragma region WGL_3DL_stereo_control

BOOL wglSetStereoEmitterState3DL(HDC hDC, UINT uState)
{
    return wglSetStereoEmitterState3DL_ptr(hDC, uState);
}

#pragma endregion

#pragma region WGL_AMD_gpu_association

UINT wglGetGPUIDsAMD(UINT maxCount, UINT* ids)
{
    return wglGetGPUIDsAMD_ptr(maxCount, ids);
}

INT wglGetGPUInfoAMD(UINT id, INT property, GLenum dataType, UINT size, void* data)
{
    return wglGetGPUInfoAMD_ptr(id, property, dataType, size, data);
}

UINT wglGetContextGPUIDAMD(HGLRC hglrc)
{
    return wglGetContextGPUIDAMD_ptr(hglrc);
}

HGLRC wglCreateAssociatedContextAMD(UINT id)
{
    return wglCreateAssociatedContextAMD_ptr(id);
}

HGLRC wglCreateAssociatedContextAttribsAMD(UINT id, HGLRC hShareContext, const int* attribList)
{
    return wglCreateAssociatedContextAttribsAMD_ptr(id, hShareContext, attribList);
}

BOOL wglDeleteAssociatedContextAMD(HGLRC hglrc)
{
    return wglDeleteAssociatedContextAMD_ptr(hglrc);
}

BOOL wglMakeAssociatedContextCurrentAMD(HGLRC hglrc)
{
    return wglMakeAssociatedContextCurrentAMD_ptr(hglrc);
}

HGLRC wglGetCurrentAssociatedContextAMD()
{
    return wglGetCurrentAssociatedContextAMD_ptr();
}

VOID wglBlitContextFramebufferAMD(HGLRC dstCtx,
                                  GLint srcX0,
                                  GLint srcY0,
                                  GLint srcX1,
                                  GLint srcY1,
                                  GLint dstX0,
                                  GLint dstY0,
                                  GLint dstX1,
                                  GLint dstY1,
                                  GLbitfield mask,
                                  GLenum filter)
{
    wglBlitContextFramebufferAMD_ptr(dstCtx, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}

#pragma endregion

#pragma region WGL_ARB_buffer_region

HANDLE wglCreateBufferRegionARB(HDC hDC, int iLayerPlane, UINT uType)
{
    return wglCreateBufferRegionARB_ptr(hDC, iLayerPlane, uType);
}

VOID wglDeleteBufferRegionARB(HANDLE hRegion)
{
    wglDeleteBufferRegionARB_ptr(hRegion);
}

BOOL wglSaveBufferRegionARB(HANDLE hRegion, int x, int y, int width, int height)
{
    return wglSaveBufferRegionARB_ptr(hRegion, x, y, width, height);
}

BOOL wglRestoreBufferRegionARB(HANDLE hRegion, int x, int y, int width, int height, int xSrc, int ySrc)
{
    return wglRestoreBufferRegionARB_ptr(hRegion, x, y, width, height, xSrc, ySrc);
}

#pragma endregion

#pragma region WGL_ARB_context_flush_control

#pragma endregion

#pragma region WGL_ARB_create_context

HGLRC wglCreateContextAttribsARB(HDC hDC, HGLRC hShareContext, const int* attribList)
{
    return wglCreateContextAttribsARB_ptr(hDC, hShareContext, attribList);
}

#pragma endregion

#pragma region WGL_ARB_create_context_no_error

#pragma endregion

#pragma region WGL_ARB_create_context_profile

#pragma endregion

#pragma region WGL_ARB_create_context_robustness

#pragma endregion

#pragma region WGL_ARB_extensions_string

const char* wglGetExtensionsStringARB(HDC hdc)
{
    return wglGetExtensionsStringARB_ptr(hdc);
}

#pragma endregion

#pragma region WGL_ARB_framebuffer_sRGB

#pragma endregion

#pragma region WGL_ARB_make_current_read

BOOL wglMakeContextCurrentARB(HDC hDrawDC, HDC hReadDC, HGLRC hglrc)
{
    return wglMakeContextCurrentARB_ptr(hDrawDC, hReadDC, hglrc);
}

HDC wglGetCurrentReadDCARB()
{
    return wglGetCurrentReadDCARB_ptr();
}

#pragma endregion

#pragma region WGL_ARB_multisample

#pragma endregion

#pragma region WGL_ARB_pbuffer

HPBUFFERARB wglCreatePbufferARB(HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int* piAttribList)
{
    return wglCreatePbufferARB_ptr(hDC, iPixelFormat, iWidth, iHeight, piAttribList);
}

HDC wglGetPbufferDCARB(HPBUFFERARB hPbuffer)
{
    return wglGetPbufferDCARB_ptr(hPbuffer);
}

int wglReleasePbufferDCARB(HPBUFFERARB hPbuffer, HDC hDC)
{
    return wglReleasePbufferDCARB_ptr(hPbuffer, hDC);
}

BOOL wglDestroyPbufferARB(HPBUFFERARB hPbuffer)
{
    return wglDestroyPbufferARB_ptr(hPbuffer);
}

BOOL wglQueryPbufferARB(HPBUFFERARB hPbuffer, int iAttribute, int* piValue)
{
    return wglQueryPbufferARB_ptr(hPbuffer, iAttribute, piValue);
}

#pragma endregion

#pragma region WGL_ARB_pixel_format

BOOL wglGetPixelFormatAttribivARB(HDC hdc,
                                  int iPixelFormat,
                                  int iLayerPlane,
                                  UINT nAttributes,
                                  const int* piAttributes,
                                  int* piValues)
{
    return wglGetPixelFormatAttribivARB_ptr(hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues);
}

BOOL wglGetPixelFormatAttribfvARB(HDC hdc,
                                  int iPixelFormat,
                                  int iLayerPlane,
                                  UINT nAttributes,
                                  const int* piAttributes,
                                  FLOAT* pfValues)
{
    return wglGetPixelFormatAttribfvARB_ptr(hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues);
}

BOOL wglChoosePixelFormatARB(HDC hdc,
                             const int* piAttribIList,
                             const FLOAT* pfAttribFList,
                             UINT nMaxFormats,
                             int* piFormats,
                             UINT* nNumFormats)
{
    return wglChoosePixelFormatARB_ptr(hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats);
}

#pragma endregion

#pragma region WGL_ARB_pixel_format_float

#pragma endregion

#pragma region WGL_ARB_render_texture

BOOL wglBindTexImageARB(HPBUFFERARB hPbuffer, int iBuffer)
{
    return wglBindTexImageARB_ptr(hPbuffer, iBuffer);
}

BOOL wglReleaseTexImageARB(HPBUFFERARB hPbuffer, int iBuffer)
{
    return wglReleaseTexImageARB_ptr(hPbuffer, iBuffer);
}

BOOL wglSetPbufferAttribARB(HPBUFFERARB hPbuffer, const int* piAttribList)
{
    return wglSetPbufferAttribARB_ptr(hPbuffer, piAttribList);
}

#pragma endregion

#pragma region WGL_ARB_robustness_application_isolation

#pragma endregion

#pragma region WGL_ARB_robustness_share_group_isolation

#pragma endregion

#pragma region WGL_ATI_pixel_format_float

#pragma endregion

#pragma region WGL_ATI_render_texture_rectangle

#pragma endregion

#pragma region WGL_EXT_colorspace

#pragma endregion

#pragma region WGL_EXT_create_context_es_profile

#pragma endregion

#pragma region WGL_EXT_create_context_es2_profile

#pragma endregion

#pragma region WGL_EXT_depth_float

#pragma endregion

#pragma region WGL_EXT_display_color_table

GLboolean wglCreateDisplayColorTableEXT(GLushort id)
{
    return wglCreateDisplayColorTableEXT_ptr(id);
}

GLboolean wglLoadDisplayColorTableEXT(const GLushort* table, GLuint length)
{
    return wglLoadDisplayColorTableEXT_ptr(table, length);
}

GLboolean wglBindDisplayColorTableEXT(GLushort id)
{
    return wglBindDisplayColorTableEXT_ptr(id);
}

VOID wglDestroyDisplayColorTableEXT(GLushort id)
{
    wglDestroyDisplayColorTableEXT_ptr(id);
}

#pragma endregion

#pragma region WGL_EXT_extensions_string

const char* wglGetExtensionsStringEXT()
{
    return wglGetExtensionsStringEXT_ptr();
}

#pragma endregion

#pragma region WGL_EXT_framebuffer_sRGB

#pragma endregion

#pragma region WGL_EXT_make_current_read

BOOL wglMakeContextCurrentEXT(HDC hDrawDC, HDC hReadDC, HGLRC hglrc)
{
    return wglMakeContextCurrentEXT_ptr(hDrawDC, hReadDC, hglrc);
}

HDC wglGetCurrentReadDCEXT()
{
    return wglGetCurrentReadDCEXT_ptr();
}

#pragma endregion

#pragma region WGL_EXT_multisample

#pragma endregion

#pragma region WGL_EXT_pbuffer

HPBUFFEREXT wglCreatePbufferEXT(HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int* piAttribList)
{
    return wglCreatePbufferEXT_ptr(hDC, iPixelFormat, iWidth, iHeight, piAttribList);
}

HDC wglGetPbufferDCEXT(HPBUFFEREXT hPbuffer)
{
    return wglGetPbufferDCEXT_ptr(hPbuffer);
}

int wglReleasePbufferDCEXT(HPBUFFEREXT hPbuffer, HDC hDC)
{
    return wglReleasePbufferDCEXT_ptr(hPbuffer, hDC);
}

BOOL wglDestroyPbufferEXT(HPBUFFEREXT hPbuffer)
{
    return wglDestroyPbufferEXT_ptr(hPbuffer);
}

BOOL wglQueryPbufferEXT(HPBUFFEREXT hPbuffer, int iAttribute, int* piValue)
{
    return wglQueryPbufferEXT_ptr(hPbuffer, iAttribute, piValue);
}

#pragma endregion

#pragma region WGL_EXT_pixel_format

BOOL wglGetPixelFormatAttribivEXT(HDC hdc,
                                  int iPixelFormat,
                                  int iLayerPlane,
                                  UINT nAttributes,
                                  int* piAttributes,
                                  int* piValues)
{
    return wglGetPixelFormatAttribivEXT_ptr(hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues);
}

BOOL wglGetPixelFormatAttribfvEXT(HDC hdc,
                                  int iPixelFormat,
                                  int iLayerPlane,
                                  UINT nAttributes,
                                  int* piAttributes,
                                  FLOAT* pfValues)
{
    return wglGetPixelFormatAttribfvEXT_ptr(hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues);
}

BOOL wglChoosePixelFormatEXT(HDC hdc,
                             const int* piAttribIList,
                             const FLOAT* pfAttribFList,
                             UINT nMaxFormats,
                             int* piFormats,
                             UINT* nNumFormats)
{
    return wglChoosePixelFormatEXT_ptr(hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats);
}

#pragma endregion

#pragma region WGL_EXT_pixel_format_packed_float

#pragma endregion

#pragma region WGL_EXT_swap_control

BOOL wglSwapIntervalEXT(int interval)
{
    return wglSwapIntervalEXT_ptr(interval);
}

int wglGetSwapIntervalEXT()
{
    return wglGetSwapIntervalEXT_ptr();
}

#pragma endregion

#pragma region WGL_EXT_swap_control_tear

#pragma endregion

#pragma region WGL_I3D_digital_video_control

BOOL wglGetDigitalVideoParametersI3D(HDC hDC, int iAttribute, int* piValue)
{
    return wglGetDigitalVideoParametersI3D_ptr(hDC, iAttribute, piValue);
}

BOOL wglSetDigitalVideoParametersI3D(HDC hDC, int iAttribute, const int* piValue)
{
    return wglSetDigitalVideoParametersI3D_ptr(hDC, iAttribute, piValue);
}

#pragma endregion

#pragma region WGL_I3D_gamma

BOOL wglGetGammaTableParametersI3D(HDC hDC, int iAttribute, int* piValue)
{
    return wglGetGammaTableParametersI3D_ptr(hDC, iAttribute, piValue);
}

BOOL wglSetGammaTableParametersI3D(HDC hDC, int iAttribute, const int* piValue)
{
    return wglSetGammaTableParametersI3D_ptr(hDC, iAttribute, piValue);
}

BOOL wglGetGammaTableI3D(HDC hDC, int iEntries, USHORT* puRed, USHORT* puGreen, USHORT* puBlue)
{
    return wglGetGammaTableI3D_ptr(hDC, iEntries, puRed, puGreen, puBlue);
}

BOOL wglSetGammaTableI3D(HDC hDC, int iEntries, const USHORT* puRed, const USHORT* puGreen, const USHORT* puBlue)
{
    return wglSetGammaTableI3D_ptr(hDC, iEntries, puRed, puGreen, puBlue);
}

#pragma endregion

#pragma region WGL_I3D_genlock

BOOL wglEnableGenlockI3D(HDC hDC)
{
    return wglEnableGenlockI3D_ptr(hDC);
}

BOOL wglDisableGenlockI3D(HDC hDC)
{
    return wglDisableGenlockI3D_ptr(hDC);
}

BOOL wglIsEnabledGenlockI3D(HDC hDC, BOOL* pFlag)
{
    return wglIsEnabledGenlockI3D_ptr(hDC, pFlag);
}

BOOL wglGenlockSourceI3D(HDC hDC, UINT uSource)
{
    return wglGenlockSourceI3D_ptr(hDC, uSource);
}

BOOL wglGetGenlockSourceI3D(HDC hDC, UINT* uSource)
{
    return wglGetGenlockSourceI3D_ptr(hDC, uSource);
}

BOOL wglGenlockSourceEdgeI3D(HDC hDC, UINT uEdge)
{
    return wglGenlockSourceEdgeI3D_ptr(hDC, uEdge);
}

BOOL wglGetGenlockSourceEdgeI3D(HDC hDC, UINT* uEdge)
{
    return wglGetGenlockSourceEdgeI3D_ptr(hDC, uEdge);
}

BOOL wglGenlockSampleRateI3D(HDC hDC, UINT uRate)
{
    return wglGenlockSampleRateI3D_ptr(hDC, uRate);
}

BOOL wglGetGenlockSampleRateI3D(HDC hDC, UINT* uRate)
{
    return wglGetGenlockSampleRateI3D_ptr(hDC, uRate);
}

BOOL wglGenlockSourceDelayI3D(HDC hDC, UINT uDelay)
{
    return wglGenlockSourceDelayI3D_ptr(hDC, uDelay);
}

BOOL wglGetGenlockSourceDelayI3D(HDC hDC, UINT* uDelay)
{
    return wglGetGenlockSourceDelayI3D_ptr(hDC, uDelay);
}

BOOL wglQueryGenlockMaxSourceDelayI3D(HDC hDC, UINT* uMaxLineDelay, UINT* uMaxPixelDelay)
{
    return wglQueryGenlockMaxSourceDelayI3D_ptr(hDC, uMaxLineDelay, uMaxPixelDelay);
}

#pragma endregion

#pragma region WGL_I3D_image_buffer

LPVOID wglCreateImageBufferI3D(HDC hDC, DWORD dwSize, UINT uFlags)
{
    return wglCreateImageBufferI3D_ptr(hDC, dwSize, uFlags);
}

BOOL wglDestroyImageBufferI3D(HDC hDC, LPVOID pAddress)
{
    return wglDestroyImageBufferI3D_ptr(hDC, pAddress);
}

BOOL wglAssociateImageBufferEventsI3D(HDC hDC,
                                      const HANDLE* pEvent,
                                      const LPVOID* pAddress,
                                      const DWORD* pSize,
                                      UINT count)
{
    return wglAssociateImageBufferEventsI3D_ptr(hDC, pEvent, pAddress, pSize, count);
}

BOOL wglReleaseImageBufferEventsI3D(HDC hDC, const LPVOID* pAddress, UINT count)
{
    return wglReleaseImageBufferEventsI3D_ptr(hDC, pAddress, count);
}

#pragma endregion

#pragma region WGL_I3D_swap_frame_lock

BOOL wglEnableFrameLockI3D()
{
    return wglEnableFrameLockI3D_ptr();
}

BOOL wglDisableFrameLockI3D()
{
    return wglDisableFrameLockI3D_ptr();
}

BOOL wglIsEnabledFrameLockI3D(BOOL* pFlag)
{
    return wglIsEnabledFrameLockI3D_ptr(pFlag);
}

BOOL wglQueryFrameLockMasterI3D(BOOL* pFlag)
{
    return wglQueryFrameLockMasterI3D_ptr(pFlag);
}

#pragma endregion

#pragma region WGL_I3D_swap_frame_usage

BOOL wglGetFrameUsageI3D(float* pUsage)
{
    return wglGetFrameUsageI3D_ptr(pUsage);
}

BOOL wglBeginFrameTrackingI3D()
{
    return wglBeginFrameTrackingI3D_ptr();
}

BOOL wglEndFrameTrackingI3D()
{
    return wglEndFrameTrackingI3D_ptr();
}

BOOL wglQueryFrameTrackingI3D(DWORD* pFrameCount, DWORD* pMissedFrames, float* pLastMissedUsage)
{
    return wglQueryFrameTrackingI3D_ptr(pFrameCount, pMissedFrames, pLastMissedUsage);
}

#pragma endregion

#pragma region WGL_NV_copy_image

BOOL wglCopyImageSubDataNV(HGLRC hSrcRC,
                           GLuint srcName,
                           GLenum srcTarget,
                           GLint srcLevel,
                           GLint srcX,
                           GLint srcY,
                           GLint srcZ,
                           HGLRC hDstRC,
                           GLuint dstName,
                           GLenum dstTarget,
                           GLint dstLevel,
                           GLint dstX,
                           GLint dstY,
                           GLint dstZ,
                           GLsizei width,
                           GLsizei height,
                           GLsizei depth)
{
    return wglCopyImageSubDataNV_ptr(hSrcRC,
                                     srcName,
                                     srcTarget,
                                     srcLevel,
                                     srcX,
                                     srcY,
                                     srcZ,
                                     hDstRC,
                                     dstName,
                                     dstTarget,
                                     dstLevel,
                                     dstX,
                                     dstY,
                                     dstZ,
                                     width,
                                     height,
                                     depth);
}

#pragma endregion

#pragma region WGL_NV_delay_before_swap

BOOL wglDelayBeforeSwapNV(HDC hDC, GLfloat seconds)
{
    return wglDelayBeforeSwapNV_ptr(hDC, seconds);
}

#pragma endregion

#pragma region WGL_NV_DX_interop

BOOL wglDXSetResourceShareHandleNV(void* dxObject, HANDLE shareHandle)
{
    return wglDXSetResourceShareHandleNV_ptr(dxObject, shareHandle);
}

HANDLE wglDXOpenDeviceNV(void* dxDevice)
{
    return wglDXOpenDeviceNV_ptr(dxDevice);
}

BOOL wglDXCloseDeviceNV(HANDLE hDevice)
{
    return wglDXCloseDeviceNV_ptr(hDevice);
}

HANDLE wglDXRegisterObjectNV(HANDLE hDevice, void* dxObject, GLuint name, GLenum type, GLenum access)
{
    return wglDXRegisterObjectNV_ptr(hDevice, dxObject, name, type, access);
}

BOOL wglDXUnregisterObjectNV(HANDLE hDevice, HANDLE hObject)
{
    return wglDXUnregisterObjectNV_ptr(hDevice, hObject);
}

BOOL wglDXObjectAccessNV(HANDLE hObject, GLenum access)
{
    return wglDXObjectAccessNV_ptr(hObject, access);
}

BOOL wglDXLockObjectsNV(HANDLE hDevice, GLint count, HANDLE* hObjects)
{
    return wglDXLockObjectsNV_ptr(hDevice, count, hObjects);
}

BOOL wglDXUnlockObjectsNV(HANDLE hDevice, GLint count, HANDLE* hObjects)
{
    return wglDXUnlockObjectsNV_ptr(hDevice, count, hObjects);
}

#pragma endregion

#pragma region WGL_NV_DX_interop2

#pragma endregion

#pragma region WGL_NV_float_buffer

#pragma endregion

#pragma region WGL_NV_gpu_affinity

BOOL wglEnumGpusNV(UINT iGpuIndex, HGPUNV* phGpu)
{
    return wglEnumGpusNV_ptr(iGpuIndex, phGpu);
}

BOOL wglEnumGpuDevicesNV(HGPUNV hGpu, UINT iDeviceIndex, PGPU_DEVICE lpGpuDevice)
{
    return wglEnumGpuDevicesNV_ptr(hGpu, iDeviceIndex, lpGpuDevice);
}

HDC wglCreateAffinityDCNV(const HGPUNV* phGpuList)
{
    return wglCreateAffinityDCNV_ptr(phGpuList);
}

BOOL wglEnumGpusFromAffinityDCNV(HDC hAffinityDC, UINT iGpuIndex, HGPUNV* hGpu)
{
    return wglEnumGpusFromAffinityDCNV_ptr(hAffinityDC, iGpuIndex, hGpu);
}

BOOL wglDeleteDCNV(HDC hdc)
{
    return wglDeleteDCNV_ptr(hdc);
}

#pragma endregion

#pragma region WGL_NV_multisample_coverage

#pragma endregion

#pragma region WGL_NV_present_video

int wglEnumerateVideoDevicesNV(HDC hDc, HVIDEOOUTPUTDEVICENV* phDeviceList)
{
    return wglEnumerateVideoDevicesNV_ptr(hDc, phDeviceList);
}

BOOL wglBindVideoDeviceNV(HDC hDc, unsigned int uVideoSlot, HVIDEOOUTPUTDEVICENV hVideoDevice, const int* piAttribList)
{
    return wglBindVideoDeviceNV_ptr(hDc, uVideoSlot, hVideoDevice, piAttribList);
}

BOOL wglQueryCurrentContextNV(int iAttribute, int* piValue)
{
    return wglQueryCurrentContextNV_ptr(iAttribute, piValue);
}

#pragma endregion

#pragma region WGL_NV_render_depth_texture

#pragma endregion

#pragma region WGL_NV_render_texture_rectangle

#pragma endregion

#pragma region WGL_NV_swap_group

BOOL wglJoinSwapGroupNV(HDC hDC, GLuint group)
{
    return wglJoinSwapGroupNV_ptr(hDC, group);
}

BOOL wglBindSwapBarrierNV(GLuint group, GLuint barrier)
{
    return wglBindSwapBarrierNV_ptr(group, barrier);
}

BOOL wglQuerySwapGroupNV(HDC hDC, GLuint* group, GLuint* barrier)
{
    return wglQuerySwapGroupNV_ptr(hDC, group, barrier);
}

BOOL wglQueryMaxSwapGroupsNV(HDC hDC, GLuint* maxGroups, GLuint* maxBarriers)
{
    return wglQueryMaxSwapGroupsNV_ptr(hDC, maxGroups, maxBarriers);
}

BOOL wglQueryFrameCountNV(HDC hDC, GLuint* count)
{
    return wglQueryFrameCountNV_ptr(hDC, count);
}

BOOL wglResetFrameCountNV(HDC hDC)
{
    return wglResetFrameCountNV_ptr(hDC);
}

#pragma endregion

#pragma region WGL_NV_video_capture

BOOL wglBindVideoCaptureDeviceNV(UINT uVideoSlot, HVIDEOINPUTDEVICENV hDevice)
{
    return wglBindVideoCaptureDeviceNV_ptr(uVideoSlot, hDevice);
}

UINT wglEnumerateVideoCaptureDevicesNV(HDC hDc, HVIDEOINPUTDEVICENV* phDeviceList)
{
    return wglEnumerateVideoCaptureDevicesNV_ptr(hDc, phDeviceList);
}

BOOL wglLockVideoCaptureDeviceNV(HDC hDc, HVIDEOINPUTDEVICENV hDevice)
{
    return wglLockVideoCaptureDeviceNV_ptr(hDc, hDevice);
}

BOOL wglQueryVideoCaptureDeviceNV(HDC hDc, HVIDEOINPUTDEVICENV hDevice, int iAttribute, int* piValue)
{
    return wglQueryVideoCaptureDeviceNV_ptr(hDc, hDevice, iAttribute, piValue);
}

BOOL wglReleaseVideoCaptureDeviceNV(HDC hDc, HVIDEOINPUTDEVICENV hDevice)
{
    return wglReleaseVideoCaptureDeviceNV_ptr(hDc, hDevice);
}

#pragma endregion

#pragma region WGL_NV_video_output

BOOL wglGetVideoDeviceNV(HDC hDC, int numDevices, HPVIDEODEV* hVideoDevice)
{
    return wglGetVideoDeviceNV_ptr(hDC, numDevices, hVideoDevice);
}

BOOL wglReleaseVideoDeviceNV(HPVIDEODEV hVideoDevice)
{
    return wglReleaseVideoDeviceNV_ptr(hVideoDevice);
}

BOOL wglBindVideoImageNV(HPVIDEODEV hVideoDevice, HPBUFFERARB hPbuffer, int iVideoBuffer)
{
    return wglBindVideoImageNV_ptr(hVideoDevice, hPbuffer, iVideoBuffer);
}

BOOL wglReleaseVideoImageNV(HPBUFFERARB hPbuffer, int iVideoBuffer)
{
    return wglReleaseVideoImageNV_ptr(hPbuffer, iVideoBuffer);
}

BOOL wglSendPbufferToVideoNV(HPBUFFERARB hPbuffer, int iBufferType, unsigned long* pulCounterPbuffer, BOOL bBlock)
{
    return wglSendPbufferToVideoNV_ptr(hPbuffer, iBufferType, pulCounterPbuffer, bBlock);
}

BOOL wglGetVideoInfoNV(HPVIDEODEV hpVideoDevice,
                       unsigned long* pulCounterOutputPbuffer,
                       unsigned long* pulCounterOutputVideo)
{
    return wglGetVideoInfoNV_ptr(hpVideoDevice, pulCounterOutputPbuffer, pulCounterOutputVideo);
}

#pragma endregion

#pragma region WGL_NV_vertex_array_range

void* wglAllocateMemoryNV(GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority)
{
    return wglAllocateMemoryNV_ptr(size, readfreq, writefreq, priority);
}

void wglFreeMemoryNV(void* pointer)
{
    wglFreeMemoryNV_ptr(pointer);
}

#pragma endregion

#pragma region WGL_OML_sync_control

BOOL wglGetSyncValuesOML(HDC hdc, INT64* ust, INT64* msc, INT64* sbc)
{
    return wglGetSyncValuesOML_ptr(hdc, ust, msc, sbc);
}

BOOL wglGetMscRateOML(HDC hdc, INT32* numerator, INT32* denominator)
{
    return wglGetMscRateOML_ptr(hdc, numerator, denominator);
}

INT64 wglSwapBuffersMscOML(HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder)
{
    return wglSwapBuffersMscOML_ptr(hdc, target_msc, divisor, remainder);
}

INT64 wglSwapLayerBuffersMscOML(HDC hdc, INT fuPlanes, INT64 target_msc, INT64 divisor, INT64 remainder)
{
    return wglSwapLayerBuffersMscOML_ptr(hdc, fuPlanes, target_msc, divisor, remainder);
}

BOOL wglWaitForMscOML(HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder, INT64* ust, INT64* msc, INT64* sbc)
{
    return wglWaitForMscOML_ptr(hdc, target_msc, divisor, remainder, ust, msc, sbc);
}

BOOL wglWaitForSbcOML(HDC hdc, INT64 target_sbc, INT64* ust, INT64* msc, INT64* sbc)
{
    return wglWaitForSbcOML_ptr(hdc, target_sbc, ust, msc, sbc);
}

#pragma endregion

#pragma region WGL_NV_multigpu_context

#pragma endregion

void init_wgl(const GetFunction& get_function)
{
    std::call_once(init_flag, [&get_function]() {
        init_features(get_function);
        init_extensions(get_function);
    });
}

bool is_supported(Extension extension)
{
    return extension_cache[static_cast<int>(extension)];
}

} // namespace framework::system::details::wgl
