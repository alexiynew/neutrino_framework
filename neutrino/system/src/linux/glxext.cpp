#include <mutex>
#include <type_traits>

#include <system/src/linux/glxext.hpp>

namespace
{

using namespace framework::system::details::glx;

#pragma region GLX_3DFX_multisample

bool init_glx_3dfx_multisample([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GLX_AMD_gpu_association

using glXGetGPUIDsAMDPtr                      = std::add_pointer_t<decltype(glXGetGPUIDsAMD)>;
using glXGetGPUInfoAMDPtr                     = std::add_pointer_t<decltype(glXGetGPUInfoAMD)>;
using glXGetContextGPUIDAMDPtr                = std::add_pointer_t<decltype(glXGetContextGPUIDAMD)>;
using glXCreateAssociatedContextAMDPtr        = std::add_pointer_t<decltype(glXCreateAssociatedContextAMD)>;
using glXCreateAssociatedContextAttribsAMDPtr = std::add_pointer_t<decltype(glXCreateAssociatedContextAttribsAMD)>;
using glXDeleteAssociatedContextAMDPtr        = std::add_pointer_t<decltype(glXDeleteAssociatedContextAMD)>;
using glXMakeAssociatedContextCurrentAMDPtr   = std::add_pointer_t<decltype(glXMakeAssociatedContextCurrentAMD)>;
using glXGetCurrentAssociatedContextAMDPtr    = std::add_pointer_t<decltype(glXGetCurrentAssociatedContextAMD)>;
using glXBlitContextFramebufferAMDPtr         = std::add_pointer_t<decltype(glXBlitContextFramebufferAMD)>;

glXGetGPUIDsAMDPtr glXGetGPUIDsAMD_ptr                                           = nullptr;
glXGetGPUInfoAMDPtr glXGetGPUInfoAMD_ptr                                         = nullptr;
glXGetContextGPUIDAMDPtr glXGetContextGPUIDAMD_ptr                               = nullptr;
glXCreateAssociatedContextAMDPtr glXCreateAssociatedContextAMD_ptr               = nullptr;
glXCreateAssociatedContextAttribsAMDPtr glXCreateAssociatedContextAttribsAMD_ptr = nullptr;
glXDeleteAssociatedContextAMDPtr glXDeleteAssociatedContextAMD_ptr               = nullptr;
glXMakeAssociatedContextCurrentAMDPtr glXMakeAssociatedContextCurrentAMD_ptr     = nullptr;
glXGetCurrentAssociatedContextAMDPtr glXGetCurrentAssociatedContextAMD_ptr       = nullptr;
glXBlitContextFramebufferAMDPtr glXBlitContextFramebufferAMD_ptr                 = nullptr;

bool init_glx_amd_gpu_association([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glXGetGPUIDsAMD_ptr = reinterpret_cast<glXGetGPUIDsAMDPtr>(get_function("glXGetGPUIDsAMD"))) == nullptr || result;
    result = (glXGetGPUInfoAMD_ptr = reinterpret_cast<glXGetGPUInfoAMDPtr>(get_function("glXGetGPUInfoAMD"))) == nullptr || result;
    result = (glXGetContextGPUIDAMD_ptr = reinterpret_cast<glXGetContextGPUIDAMDPtr>(get_function("glXGetContextGPUIDAMD"))) == nullptr || result;
    result = (glXCreateAssociatedContextAMD_ptr = reinterpret_cast<glXCreateAssociatedContextAMDPtr>(get_function("glXCreateAssociatedContextAMD"))) == nullptr || result;
    result = (glXCreateAssociatedContextAttribsAMD_ptr = reinterpret_cast<glXCreateAssociatedContextAttribsAMDPtr>(get_function("glXCreateAssociatedContextAttribsAMD"))) == nullptr || result;
    result = (glXDeleteAssociatedContextAMD_ptr = reinterpret_cast<glXDeleteAssociatedContextAMDPtr>(get_function("glXDeleteAssociatedContextAMD"))) == nullptr || result;
    result = (glXMakeAssociatedContextCurrentAMD_ptr = reinterpret_cast<glXMakeAssociatedContextCurrentAMDPtr>(get_function("glXMakeAssociatedContextCurrentAMD"))) == nullptr || result;
    result = (glXGetCurrentAssociatedContextAMD_ptr = reinterpret_cast<glXGetCurrentAssociatedContextAMDPtr>(get_function("glXGetCurrentAssociatedContextAMD"))) == nullptr || result;
    result = (glXBlitContextFramebufferAMD_ptr = reinterpret_cast<glXBlitContextFramebufferAMDPtr>(get_function("glXBlitContextFramebufferAMD"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GLX_ARB_context_flush_control

bool init_glx_arb_context_flush_control([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GLX_ARB_create_context

using glXCreateContextAttribsARBPtr = std::add_pointer_t<decltype(glXCreateContextAttribsARB)>;

glXCreateContextAttribsARBPtr glXCreateContextAttribsARB_ptr = nullptr;

bool init_glx_arb_create_context([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glXCreateContextAttribsARB_ptr = reinterpret_cast<glXCreateContextAttribsARBPtr>(get_function("glXCreateContextAttribsARB"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GLX_ARB_create_context_no_error

bool init_glx_arb_create_context_no_error([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GLX_ARB_create_context_profile

bool init_glx_arb_create_context_profile([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GLX_ARB_create_context_robustness

bool init_glx_arb_create_context_robustness([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GLX_ARB_fbconfig_float

bool init_glx_arb_fbconfig_float([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GLX_ARB_framebuffer_sRGB

bool init_glx_arb_framebuffer_srgb([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GLX_ARB_get_proc_address

using glXGetProcAddressARBPtr = std::add_pointer_t<decltype(glXGetProcAddressARB)>;

glXGetProcAddressARBPtr glXGetProcAddressARB_ptr = nullptr;

bool init_glx_arb_get_proc_address([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glXGetProcAddressARB_ptr = reinterpret_cast<glXGetProcAddressARBPtr>(get_function("glXGetProcAddressARB"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GLX_ARB_multisample

bool init_glx_arb_multisample([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GLX_ARB_robustness_application_isolation

bool init_glx_arb_robustness_application_isolation([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GLX_ARB_robustness_share_group_isolation

bool init_glx_arb_robustness_share_group_isolation([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GLX_ARB_vertex_buffer_object

bool init_glx_arb_vertex_buffer_object([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GLX_EXT_buffer_age

bool init_glx_ext_buffer_age([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GLX_EXT_context_priority

bool init_glx_ext_context_priority([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GLX_EXT_create_context_es_profile

bool init_glx_ext_create_context_es_profile([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GLX_EXT_create_context_es2_profile

bool init_glx_ext_create_context_es2_profile([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GLX_EXT_fbconfig_packed_float

bool init_glx_ext_fbconfig_packed_float([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GLX_EXT_framebuffer_sRGB

bool init_glx_ext_framebuffer_srgb([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GLX_EXT_get_drawable_type

bool init_glx_ext_get_drawable_type([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GLX_EXT_import_context

using glXGetCurrentDisplayEXTPtr = std::add_pointer_t<decltype(glXGetCurrentDisplayEXT)>;
using glXQueryContextInfoEXTPtr  = std::add_pointer_t<decltype(glXQueryContextInfoEXT)>;
using glXGetContextIDEXTPtr      = std::add_pointer_t<decltype(glXGetContextIDEXT)>;
using glXImportContextEXTPtr     = std::add_pointer_t<decltype(glXImportContextEXT)>;
using glXFreeContextEXTPtr       = std::add_pointer_t<decltype(glXFreeContextEXT)>;

glXGetCurrentDisplayEXTPtr glXGetCurrentDisplayEXT_ptr = nullptr;
glXQueryContextInfoEXTPtr glXQueryContextInfoEXT_ptr   = nullptr;
glXGetContextIDEXTPtr glXGetContextIDEXT_ptr           = nullptr;
glXImportContextEXTPtr glXImportContextEXT_ptr         = nullptr;
glXFreeContextEXTPtr glXFreeContextEXT_ptr             = nullptr;

bool init_glx_ext_import_context([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glXGetCurrentDisplayEXT_ptr = reinterpret_cast<glXGetCurrentDisplayEXTPtr>(get_function("glXGetCurrentDisplayEXT"))) == nullptr || result;
    result = (glXQueryContextInfoEXT_ptr = reinterpret_cast<glXQueryContextInfoEXTPtr>(get_function("glXQueryContextInfoEXT"))) == nullptr || result;
    result = (glXGetContextIDEXT_ptr = reinterpret_cast<glXGetContextIDEXTPtr>(get_function("glXGetContextIDEXT"))) == nullptr || result;
    result = (glXImportContextEXT_ptr = reinterpret_cast<glXImportContextEXTPtr>(get_function("glXImportContextEXT"))) == nullptr || result;
    result = (glXFreeContextEXT_ptr = reinterpret_cast<glXFreeContextEXTPtr>(get_function("glXFreeContextEXT"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GLX_EXT_libglvnd

bool init_glx_ext_libglvnd([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GLX_EXT_no_config_context

bool init_glx_ext_no_config_context([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GLX_EXT_stereo_tree

bool init_glx_ext_stereo_tree([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GLX_EXT_swap_control

using glXSwapIntervalEXTPtr = std::add_pointer_t<decltype(glXSwapIntervalEXT)>;

glXSwapIntervalEXTPtr glXSwapIntervalEXT_ptr = nullptr;

bool init_glx_ext_swap_control([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glXSwapIntervalEXT_ptr = reinterpret_cast<glXSwapIntervalEXTPtr>(get_function("glXSwapIntervalEXT"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GLX_EXT_swap_control_tear

bool init_glx_ext_swap_control_tear([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GLX_EXT_texture_from_pixmap

using glXBindTexImageEXTPtr    = std::add_pointer_t<decltype(glXBindTexImageEXT)>;
using glXReleaseTexImageEXTPtr = std::add_pointer_t<decltype(glXReleaseTexImageEXT)>;

glXBindTexImageEXTPtr glXBindTexImageEXT_ptr       = nullptr;
glXReleaseTexImageEXTPtr glXReleaseTexImageEXT_ptr = nullptr;

bool init_glx_ext_texture_from_pixmap([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glXBindTexImageEXT_ptr = reinterpret_cast<glXBindTexImageEXTPtr>(get_function("glXBindTexImageEXT"))) == nullptr || result;
    result = (glXReleaseTexImageEXT_ptr = reinterpret_cast<glXReleaseTexImageEXTPtr>(get_function("glXReleaseTexImageEXT"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GLX_EXT_visual_info

bool init_glx_ext_visual_info([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GLX_EXT_visual_rating

bool init_glx_ext_visual_rating([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GLX_INTEL_swap_event

bool init_glx_intel_swap_event([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GLX_MESA_agp_offset

using glXGetAGPOffsetMESAPtr = std::add_pointer_t<decltype(glXGetAGPOffsetMESA)>;

glXGetAGPOffsetMESAPtr glXGetAGPOffsetMESA_ptr = nullptr;

bool init_glx_mesa_agp_offset([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glXGetAGPOffsetMESA_ptr = reinterpret_cast<glXGetAGPOffsetMESAPtr>(get_function("glXGetAGPOffsetMESA"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GLX_MESA_copy_sub_buffer

using glXCopySubBufferMESAPtr = std::add_pointer_t<decltype(glXCopySubBufferMESA)>;

glXCopySubBufferMESAPtr glXCopySubBufferMESA_ptr = nullptr;

bool init_glx_mesa_copy_sub_buffer([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glXCopySubBufferMESA_ptr = reinterpret_cast<glXCopySubBufferMESAPtr>(get_function("glXCopySubBufferMESA"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GLX_MESA_pixmap_colormap

using glXCreateGLXPixmapMESAPtr = std::add_pointer_t<decltype(glXCreateGLXPixmapMESA)>;

glXCreateGLXPixmapMESAPtr glXCreateGLXPixmapMESA_ptr = nullptr;

bool init_glx_mesa_pixmap_colormap([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glXCreateGLXPixmapMESA_ptr = reinterpret_cast<glXCreateGLXPixmapMESAPtr>(get_function("glXCreateGLXPixmapMESA"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GLX_MESA_query_renderer

using glXQueryCurrentRendererIntegerMESAPtr = std::add_pointer_t<decltype(glXQueryCurrentRendererIntegerMESA)>;
using glXQueryCurrentRendererStringMESAPtr  = std::add_pointer_t<decltype(glXQueryCurrentRendererStringMESA)>;
using glXQueryRendererIntegerMESAPtr        = std::add_pointer_t<decltype(glXQueryRendererIntegerMESA)>;
using glXQueryRendererStringMESAPtr         = std::add_pointer_t<decltype(glXQueryRendererStringMESA)>;

glXQueryCurrentRendererIntegerMESAPtr glXQueryCurrentRendererIntegerMESA_ptr = nullptr;
glXQueryCurrentRendererStringMESAPtr glXQueryCurrentRendererStringMESA_ptr   = nullptr;
glXQueryRendererIntegerMESAPtr glXQueryRendererIntegerMESA_ptr               = nullptr;
glXQueryRendererStringMESAPtr glXQueryRendererStringMESA_ptr                 = nullptr;

bool init_glx_mesa_query_renderer([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glXQueryCurrentRendererIntegerMESA_ptr = reinterpret_cast<glXQueryCurrentRendererIntegerMESAPtr>(get_function("glXQueryCurrentRendererIntegerMESA"))) == nullptr || result;
    result = (glXQueryCurrentRendererStringMESA_ptr = reinterpret_cast<glXQueryCurrentRendererStringMESAPtr>(get_function("glXQueryCurrentRendererStringMESA"))) == nullptr || result;
    result = (glXQueryRendererIntegerMESA_ptr = reinterpret_cast<glXQueryRendererIntegerMESAPtr>(get_function("glXQueryRendererIntegerMESA"))) == nullptr || result;
    result = (glXQueryRendererStringMESA_ptr = reinterpret_cast<glXQueryRendererStringMESAPtr>(get_function("glXQueryRendererStringMESA"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GLX_MESA_release_buffers

using glXReleaseBuffersMESAPtr = std::add_pointer_t<decltype(glXReleaseBuffersMESA)>;

glXReleaseBuffersMESAPtr glXReleaseBuffersMESA_ptr = nullptr;

bool init_glx_mesa_release_buffers([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glXReleaseBuffersMESA_ptr = reinterpret_cast<glXReleaseBuffersMESAPtr>(get_function("glXReleaseBuffersMESA"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GLX_MESA_set_3dfx_mode

using glXSet3DfxModeMESAPtr = std::add_pointer_t<decltype(glXSet3DfxModeMESA)>;

glXSet3DfxModeMESAPtr glXSet3DfxModeMESA_ptr = nullptr;

bool init_glx_mesa_set_3dfx_mode([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glXSet3DfxModeMESA_ptr = reinterpret_cast<glXSet3DfxModeMESAPtr>(get_function("glXSet3DfxModeMESA"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GLX_MESA_swap_control

using glXGetSwapIntervalMESAPtr = std::add_pointer_t<decltype(glXGetSwapIntervalMESA)>;
using glXSwapIntervalMESAPtr    = std::add_pointer_t<decltype(glXSwapIntervalMESA)>;

glXGetSwapIntervalMESAPtr glXGetSwapIntervalMESA_ptr = nullptr;
glXSwapIntervalMESAPtr glXSwapIntervalMESA_ptr       = nullptr;

bool init_glx_mesa_swap_control([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glXGetSwapIntervalMESA_ptr = reinterpret_cast<glXGetSwapIntervalMESAPtr>(get_function("glXGetSwapIntervalMESA"))) == nullptr || result;
    result = (glXSwapIntervalMESA_ptr = reinterpret_cast<glXSwapIntervalMESAPtr>(get_function("glXSwapIntervalMESA"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GLX_NV_copy_buffer

using glXCopyBufferSubDataNVPtr      = std::add_pointer_t<decltype(glXCopyBufferSubDataNV)>;
using glXNamedCopyBufferSubDataNVPtr = std::add_pointer_t<decltype(glXNamedCopyBufferSubDataNV)>;

glXCopyBufferSubDataNVPtr glXCopyBufferSubDataNV_ptr           = nullptr;
glXNamedCopyBufferSubDataNVPtr glXNamedCopyBufferSubDataNV_ptr = nullptr;

bool init_glx_nv_copy_buffer([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glXCopyBufferSubDataNV_ptr = reinterpret_cast<glXCopyBufferSubDataNVPtr>(get_function("glXCopyBufferSubDataNV"))) == nullptr || result;
    result = (glXNamedCopyBufferSubDataNV_ptr = reinterpret_cast<glXNamedCopyBufferSubDataNVPtr>(get_function("glXNamedCopyBufferSubDataNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GLX_NV_copy_image

using glXCopyImageSubDataNVPtr = std::add_pointer_t<decltype(glXCopyImageSubDataNV)>;

glXCopyImageSubDataNVPtr glXCopyImageSubDataNV_ptr = nullptr;

bool init_glx_nv_copy_image([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glXCopyImageSubDataNV_ptr = reinterpret_cast<glXCopyImageSubDataNVPtr>(get_function("glXCopyImageSubDataNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GLX_NV_delay_before_swap

using glXDelayBeforeSwapNVPtr = std::add_pointer_t<decltype(glXDelayBeforeSwapNV)>;

glXDelayBeforeSwapNVPtr glXDelayBeforeSwapNV_ptr = nullptr;

bool init_glx_nv_delay_before_swap([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glXDelayBeforeSwapNV_ptr = reinterpret_cast<glXDelayBeforeSwapNVPtr>(get_function("glXDelayBeforeSwapNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GLX_NV_float_buffer

bool init_glx_nv_float_buffer([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GLX_NV_multisample_coverage

bool init_glx_nv_multisample_coverage([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GLX_NV_present_video

using glXEnumerateVideoDevicesNVPtr = std::add_pointer_t<decltype(glXEnumerateVideoDevicesNV)>;
using glXBindVideoDeviceNVPtr       = std::add_pointer_t<decltype(glXBindVideoDeviceNV)>;

glXEnumerateVideoDevicesNVPtr glXEnumerateVideoDevicesNV_ptr = nullptr;
glXBindVideoDeviceNVPtr glXBindVideoDeviceNV_ptr             = nullptr;

bool init_glx_nv_present_video([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glXEnumerateVideoDevicesNV_ptr = reinterpret_cast<glXEnumerateVideoDevicesNVPtr>(get_function("glXEnumerateVideoDevicesNV"))) == nullptr || result;
    result = (glXBindVideoDeviceNV_ptr = reinterpret_cast<glXBindVideoDeviceNVPtr>(get_function("glXBindVideoDeviceNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GLX_NV_robustness_video_memory_purge

bool init_glx_nv_robustness_video_memory_purge([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GLX_NV_swap_group

using glXJoinSwapGroupNVPtr      = std::add_pointer_t<decltype(glXJoinSwapGroupNV)>;
using glXBindSwapBarrierNVPtr    = std::add_pointer_t<decltype(glXBindSwapBarrierNV)>;
using glXQuerySwapGroupNVPtr     = std::add_pointer_t<decltype(glXQuerySwapGroupNV)>;
using glXQueryMaxSwapGroupsNVPtr = std::add_pointer_t<decltype(glXQueryMaxSwapGroupsNV)>;
using glXQueryFrameCountNVPtr    = std::add_pointer_t<decltype(glXQueryFrameCountNV)>;
using glXResetFrameCountNVPtr    = std::add_pointer_t<decltype(glXResetFrameCountNV)>;

glXJoinSwapGroupNVPtr glXJoinSwapGroupNV_ptr           = nullptr;
glXBindSwapBarrierNVPtr glXBindSwapBarrierNV_ptr       = nullptr;
glXQuerySwapGroupNVPtr glXQuerySwapGroupNV_ptr         = nullptr;
glXQueryMaxSwapGroupsNVPtr glXQueryMaxSwapGroupsNV_ptr = nullptr;
glXQueryFrameCountNVPtr glXQueryFrameCountNV_ptr       = nullptr;
glXResetFrameCountNVPtr glXResetFrameCountNV_ptr       = nullptr;

bool init_glx_nv_swap_group([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glXJoinSwapGroupNV_ptr = reinterpret_cast<glXJoinSwapGroupNVPtr>(get_function("glXJoinSwapGroupNV"))) == nullptr || result;
    result = (glXBindSwapBarrierNV_ptr = reinterpret_cast<glXBindSwapBarrierNVPtr>(get_function("glXBindSwapBarrierNV"))) == nullptr || result;
    result = (glXQuerySwapGroupNV_ptr = reinterpret_cast<glXQuerySwapGroupNVPtr>(get_function("glXQuerySwapGroupNV"))) == nullptr || result;
    result = (glXQueryMaxSwapGroupsNV_ptr = reinterpret_cast<glXQueryMaxSwapGroupsNVPtr>(get_function("glXQueryMaxSwapGroupsNV"))) == nullptr || result;
    result = (glXQueryFrameCountNV_ptr = reinterpret_cast<glXQueryFrameCountNVPtr>(get_function("glXQueryFrameCountNV"))) == nullptr || result;
    result = (glXResetFrameCountNV_ptr = reinterpret_cast<glXResetFrameCountNVPtr>(get_function("glXResetFrameCountNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GLX_NV_video_capture

using glXBindVideoCaptureDeviceNVPtr       = std::add_pointer_t<decltype(glXBindVideoCaptureDeviceNV)>;
using glXEnumerateVideoCaptureDevicesNVPtr = std::add_pointer_t<decltype(glXEnumerateVideoCaptureDevicesNV)>;
using glXLockVideoCaptureDeviceNVPtr       = std::add_pointer_t<decltype(glXLockVideoCaptureDeviceNV)>;
using glXQueryVideoCaptureDeviceNVPtr      = std::add_pointer_t<decltype(glXQueryVideoCaptureDeviceNV)>;
using glXReleaseVideoCaptureDeviceNVPtr    = std::add_pointer_t<decltype(glXReleaseVideoCaptureDeviceNV)>;

glXBindVideoCaptureDeviceNVPtr glXBindVideoCaptureDeviceNV_ptr             = nullptr;
glXEnumerateVideoCaptureDevicesNVPtr glXEnumerateVideoCaptureDevicesNV_ptr = nullptr;
glXLockVideoCaptureDeviceNVPtr glXLockVideoCaptureDeviceNV_ptr             = nullptr;
glXQueryVideoCaptureDeviceNVPtr glXQueryVideoCaptureDeviceNV_ptr           = nullptr;
glXReleaseVideoCaptureDeviceNVPtr glXReleaseVideoCaptureDeviceNV_ptr       = nullptr;

bool init_glx_nv_video_capture([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glXBindVideoCaptureDeviceNV_ptr = reinterpret_cast<glXBindVideoCaptureDeviceNVPtr>(get_function("glXBindVideoCaptureDeviceNV"))) == nullptr || result;
    result = (glXEnumerateVideoCaptureDevicesNV_ptr = reinterpret_cast<glXEnumerateVideoCaptureDevicesNVPtr>(get_function("glXEnumerateVideoCaptureDevicesNV"))) == nullptr || result;
    result = (glXLockVideoCaptureDeviceNV_ptr = reinterpret_cast<glXLockVideoCaptureDeviceNVPtr>(get_function("glXLockVideoCaptureDeviceNV"))) == nullptr || result;
    result = (glXQueryVideoCaptureDeviceNV_ptr = reinterpret_cast<glXQueryVideoCaptureDeviceNVPtr>(get_function("glXQueryVideoCaptureDeviceNV"))) == nullptr || result;
    result = (glXReleaseVideoCaptureDeviceNV_ptr = reinterpret_cast<glXReleaseVideoCaptureDeviceNVPtr>(get_function("glXReleaseVideoCaptureDeviceNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GLX_NV_video_out

using glXGetVideoDeviceNVPtr     = std::add_pointer_t<decltype(glXGetVideoDeviceNV)>;
using glXReleaseVideoDeviceNVPtr = std::add_pointer_t<decltype(glXReleaseVideoDeviceNV)>;
using glXBindVideoImageNVPtr     = std::add_pointer_t<decltype(glXBindVideoImageNV)>;
using glXReleaseVideoImageNVPtr  = std::add_pointer_t<decltype(glXReleaseVideoImageNV)>;
using glXSendPbufferToVideoNVPtr = std::add_pointer_t<decltype(glXSendPbufferToVideoNV)>;
using glXGetVideoInfoNVPtr       = std::add_pointer_t<decltype(glXGetVideoInfoNV)>;

glXGetVideoDeviceNVPtr glXGetVideoDeviceNV_ptr         = nullptr;
glXReleaseVideoDeviceNVPtr glXReleaseVideoDeviceNV_ptr = nullptr;
glXBindVideoImageNVPtr glXBindVideoImageNV_ptr         = nullptr;
glXReleaseVideoImageNVPtr glXReleaseVideoImageNV_ptr   = nullptr;
glXSendPbufferToVideoNVPtr glXSendPbufferToVideoNV_ptr = nullptr;
glXGetVideoInfoNVPtr glXGetVideoInfoNV_ptr             = nullptr;

bool init_glx_nv_video_out([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glXGetVideoDeviceNV_ptr = reinterpret_cast<glXGetVideoDeviceNVPtr>(get_function("glXGetVideoDeviceNV"))) == nullptr || result;
    result = (glXReleaseVideoDeviceNV_ptr = reinterpret_cast<glXReleaseVideoDeviceNVPtr>(get_function("glXReleaseVideoDeviceNV"))) == nullptr || result;
    result = (glXBindVideoImageNV_ptr = reinterpret_cast<glXBindVideoImageNVPtr>(get_function("glXBindVideoImageNV"))) == nullptr || result;
    result = (glXReleaseVideoImageNV_ptr = reinterpret_cast<glXReleaseVideoImageNVPtr>(get_function("glXReleaseVideoImageNV"))) == nullptr || result;
    result = (glXSendPbufferToVideoNV_ptr = reinterpret_cast<glXSendPbufferToVideoNVPtr>(get_function("glXSendPbufferToVideoNV"))) == nullptr || result;
    result = (glXGetVideoInfoNV_ptr = reinterpret_cast<glXGetVideoInfoNVPtr>(get_function("glXGetVideoInfoNV"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GLX_OML_swap_method

bool init_glx_oml_swap_method([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GLX_OML_sync_control

using glXGetSyncValuesOMLPtr  = std::add_pointer_t<decltype(glXGetSyncValuesOML)>;
using glXGetMscRateOMLPtr     = std::add_pointer_t<decltype(glXGetMscRateOML)>;
using glXSwapBuffersMscOMLPtr = std::add_pointer_t<decltype(glXSwapBuffersMscOML)>;
using glXWaitForMscOMLPtr     = std::add_pointer_t<decltype(glXWaitForMscOML)>;
using glXWaitForSbcOMLPtr     = std::add_pointer_t<decltype(glXWaitForSbcOML)>;

glXGetSyncValuesOMLPtr glXGetSyncValuesOML_ptr   = nullptr;
glXGetMscRateOMLPtr glXGetMscRateOML_ptr         = nullptr;
glXSwapBuffersMscOMLPtr glXSwapBuffersMscOML_ptr = nullptr;
glXWaitForMscOMLPtr glXWaitForMscOML_ptr         = nullptr;
glXWaitForSbcOMLPtr glXWaitForSbcOML_ptr         = nullptr;

bool init_glx_oml_sync_control([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glXGetSyncValuesOML_ptr = reinterpret_cast<glXGetSyncValuesOMLPtr>(get_function("glXGetSyncValuesOML"))) == nullptr || result;
    result = (glXGetMscRateOML_ptr = reinterpret_cast<glXGetMscRateOMLPtr>(get_function("glXGetMscRateOML"))) == nullptr || result;
    result = (glXSwapBuffersMscOML_ptr = reinterpret_cast<glXSwapBuffersMscOMLPtr>(get_function("glXSwapBuffersMscOML"))) == nullptr || result;
    result = (glXWaitForMscOML_ptr = reinterpret_cast<glXWaitForMscOMLPtr>(get_function("glXWaitForMscOML"))) == nullptr || result;
    result = (glXWaitForSbcOML_ptr = reinterpret_cast<glXWaitForSbcOMLPtr>(get_function("glXWaitForSbcOML"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GLX_SGI_cushion

using glXCushionSGIPtr = std::add_pointer_t<decltype(glXCushionSGI)>;

glXCushionSGIPtr glXCushionSGI_ptr = nullptr;

bool init_glx_sgi_cushion([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glXCushionSGI_ptr = reinterpret_cast<glXCushionSGIPtr>(get_function("glXCushionSGI"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GLX_SGI_make_current_read

using glXMakeCurrentReadSGIPtr        = std::add_pointer_t<decltype(glXMakeCurrentReadSGI)>;
using glXGetCurrentReadDrawableSGIPtr = std::add_pointer_t<decltype(glXGetCurrentReadDrawableSGI)>;

glXMakeCurrentReadSGIPtr glXMakeCurrentReadSGI_ptr               = nullptr;
glXGetCurrentReadDrawableSGIPtr glXGetCurrentReadDrawableSGI_ptr = nullptr;

bool init_glx_sgi_make_current_read([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glXMakeCurrentReadSGI_ptr = reinterpret_cast<glXMakeCurrentReadSGIPtr>(get_function("glXMakeCurrentReadSGI"))) == nullptr || result;
    result = (glXGetCurrentReadDrawableSGI_ptr = reinterpret_cast<glXGetCurrentReadDrawableSGIPtr>(get_function("glXGetCurrentReadDrawableSGI"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GLX_SGI_swap_control

using glXSwapIntervalSGIPtr = std::add_pointer_t<decltype(glXSwapIntervalSGI)>;

glXSwapIntervalSGIPtr glXSwapIntervalSGI_ptr = nullptr;

bool init_glx_sgi_swap_control([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glXSwapIntervalSGI_ptr = reinterpret_cast<glXSwapIntervalSGIPtr>(get_function("glXSwapIntervalSGI"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GLX_SGI_video_sync

using glXGetVideoSyncSGIPtr  = std::add_pointer_t<decltype(glXGetVideoSyncSGI)>;
using glXWaitVideoSyncSGIPtr = std::add_pointer_t<decltype(glXWaitVideoSyncSGI)>;

glXGetVideoSyncSGIPtr glXGetVideoSyncSGI_ptr   = nullptr;
glXWaitVideoSyncSGIPtr glXWaitVideoSyncSGI_ptr = nullptr;

bool init_glx_sgi_video_sync([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glXGetVideoSyncSGI_ptr = reinterpret_cast<glXGetVideoSyncSGIPtr>(get_function("glXGetVideoSyncSGI"))) == nullptr || result;
    result = (glXWaitVideoSyncSGI_ptr = reinterpret_cast<glXWaitVideoSyncSGIPtr>(get_function("glXWaitVideoSyncSGI"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GLX_SGIS_blended_overlay

bool init_glx_sgis_blended_overlay([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GLX_SGIS_multisample

bool init_glx_sgis_multisample([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GLX_SGIS_shared_multisample

bool init_glx_sgis_shared_multisample([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GLX_SGIX_dmbuffer

using glXAssociateDMPbufferSGIXPtr = std::add_pointer_t<decltype(glXAssociateDMPbufferSGIX)>;

glXAssociateDMPbufferSGIXPtr glXAssociateDMPbufferSGIX_ptr = nullptr;

bool init_glx_sgix_dmbuffer([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glXAssociateDMPbufferSGIX_ptr = reinterpret_cast<glXAssociateDMPbufferSGIXPtr>(get_function("glXAssociateDMPbufferSGIX"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GLX_SGIX_fbconfig

using glXGetFBConfigAttribSGIXPtr         = std::add_pointer_t<decltype(glXGetFBConfigAttribSGIX)>;
using glXChooseFBConfigSGIXPtr            = std::add_pointer_t<decltype(glXChooseFBConfigSGIX)>;
using glXCreateGLXPixmapWithConfigSGIXPtr = std::add_pointer_t<decltype(glXCreateGLXPixmapWithConfigSGIX)>;
using glXCreateContextWithConfigSGIXPtr   = std::add_pointer_t<decltype(glXCreateContextWithConfigSGIX)>;
using glXGetVisualFromFBConfigSGIXPtr     = std::add_pointer_t<decltype(glXGetVisualFromFBConfigSGIX)>;
using glXGetFBConfigFromVisualSGIXPtr     = std::add_pointer_t<decltype(glXGetFBConfigFromVisualSGIX)>;

glXGetFBConfigAttribSGIXPtr glXGetFBConfigAttribSGIX_ptr                 = nullptr;
glXChooseFBConfigSGIXPtr glXChooseFBConfigSGIX_ptr                       = nullptr;
glXCreateGLXPixmapWithConfigSGIXPtr glXCreateGLXPixmapWithConfigSGIX_ptr = nullptr;
glXCreateContextWithConfigSGIXPtr glXCreateContextWithConfigSGIX_ptr     = nullptr;
glXGetVisualFromFBConfigSGIXPtr glXGetVisualFromFBConfigSGIX_ptr         = nullptr;
glXGetFBConfigFromVisualSGIXPtr glXGetFBConfigFromVisualSGIX_ptr         = nullptr;

bool init_glx_sgix_fbconfig([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glXGetFBConfigAttribSGIX_ptr = reinterpret_cast<glXGetFBConfigAttribSGIXPtr>(get_function("glXGetFBConfigAttribSGIX"))) == nullptr || result;
    result = (glXChooseFBConfigSGIX_ptr = reinterpret_cast<glXChooseFBConfigSGIXPtr>(get_function("glXChooseFBConfigSGIX"))) == nullptr || result;
    result = (glXCreateGLXPixmapWithConfigSGIX_ptr = reinterpret_cast<glXCreateGLXPixmapWithConfigSGIXPtr>(get_function("glXCreateGLXPixmapWithConfigSGIX"))) == nullptr || result;
    result = (glXCreateContextWithConfigSGIX_ptr = reinterpret_cast<glXCreateContextWithConfigSGIXPtr>(get_function("glXCreateContextWithConfigSGIX"))) == nullptr || result;
    result = (glXGetVisualFromFBConfigSGIX_ptr = reinterpret_cast<glXGetVisualFromFBConfigSGIXPtr>(get_function("glXGetVisualFromFBConfigSGIX"))) == nullptr || result;
    result = (glXGetFBConfigFromVisualSGIX_ptr = reinterpret_cast<glXGetFBConfigFromVisualSGIXPtr>(get_function("glXGetFBConfigFromVisualSGIX"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GLX_SGIX_hyperpipe

using glXQueryHyperpipeNetworkSGIXPtr    = std::add_pointer_t<decltype(glXQueryHyperpipeNetworkSGIX)>;
using glXHyperpipeConfigSGIXPtr          = std::add_pointer_t<decltype(glXHyperpipeConfigSGIX)>;
using glXQueryHyperpipeConfigSGIXPtr     = std::add_pointer_t<decltype(glXQueryHyperpipeConfigSGIX)>;
using glXDestroyHyperpipeConfigSGIXPtr   = std::add_pointer_t<decltype(glXDestroyHyperpipeConfigSGIX)>;
using glXBindHyperpipeSGIXPtr            = std::add_pointer_t<decltype(glXBindHyperpipeSGIX)>;
using glXQueryHyperpipeBestAttribSGIXPtr = std::add_pointer_t<decltype(glXQueryHyperpipeBestAttribSGIX)>;
using glXHyperpipeAttribSGIXPtr          = std::add_pointer_t<decltype(glXHyperpipeAttribSGIX)>;
using glXQueryHyperpipeAttribSGIXPtr     = std::add_pointer_t<decltype(glXQueryHyperpipeAttribSGIX)>;

glXQueryHyperpipeNetworkSGIXPtr glXQueryHyperpipeNetworkSGIX_ptr       = nullptr;
glXHyperpipeConfigSGIXPtr glXHyperpipeConfigSGIX_ptr                   = nullptr;
glXQueryHyperpipeConfigSGIXPtr glXQueryHyperpipeConfigSGIX_ptr         = nullptr;
glXDestroyHyperpipeConfigSGIXPtr glXDestroyHyperpipeConfigSGIX_ptr     = nullptr;
glXBindHyperpipeSGIXPtr glXBindHyperpipeSGIX_ptr                       = nullptr;
glXQueryHyperpipeBestAttribSGIXPtr glXQueryHyperpipeBestAttribSGIX_ptr = nullptr;
glXHyperpipeAttribSGIXPtr glXHyperpipeAttribSGIX_ptr                   = nullptr;
glXQueryHyperpipeAttribSGIXPtr glXQueryHyperpipeAttribSGIX_ptr         = nullptr;

bool init_glx_sgix_hyperpipe([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glXQueryHyperpipeNetworkSGIX_ptr = reinterpret_cast<glXQueryHyperpipeNetworkSGIXPtr>(get_function("glXQueryHyperpipeNetworkSGIX"))) == nullptr || result;
    result = (glXHyperpipeConfigSGIX_ptr = reinterpret_cast<glXHyperpipeConfigSGIXPtr>(get_function("glXHyperpipeConfigSGIX"))) == nullptr || result;
    result = (glXQueryHyperpipeConfigSGIX_ptr = reinterpret_cast<glXQueryHyperpipeConfigSGIXPtr>(get_function("glXQueryHyperpipeConfigSGIX"))) == nullptr || result;
    result = (glXDestroyHyperpipeConfigSGIX_ptr = reinterpret_cast<glXDestroyHyperpipeConfigSGIXPtr>(get_function("glXDestroyHyperpipeConfigSGIX"))) == nullptr || result;
    result = (glXBindHyperpipeSGIX_ptr = reinterpret_cast<glXBindHyperpipeSGIXPtr>(get_function("glXBindHyperpipeSGIX"))) == nullptr || result;
    result = (glXQueryHyperpipeBestAttribSGIX_ptr = reinterpret_cast<glXQueryHyperpipeBestAttribSGIXPtr>(get_function("glXQueryHyperpipeBestAttribSGIX"))) == nullptr || result;
    result = (glXHyperpipeAttribSGIX_ptr = reinterpret_cast<glXHyperpipeAttribSGIXPtr>(get_function("glXHyperpipeAttribSGIX"))) == nullptr || result;
    result = (glXQueryHyperpipeAttribSGIX_ptr = reinterpret_cast<glXQueryHyperpipeAttribSGIXPtr>(get_function("glXQueryHyperpipeAttribSGIX"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GLX_SGIX_pbuffer

using glXCreateGLXPbufferSGIXPtr  = std::add_pointer_t<decltype(glXCreateGLXPbufferSGIX)>;
using glXDestroyGLXPbufferSGIXPtr = std::add_pointer_t<decltype(glXDestroyGLXPbufferSGIX)>;
using glXQueryGLXPbufferSGIXPtr   = std::add_pointer_t<decltype(glXQueryGLXPbufferSGIX)>;
using glXSelectEventSGIXPtr       = std::add_pointer_t<decltype(glXSelectEventSGIX)>;
using glXGetSelectedEventSGIXPtr  = std::add_pointer_t<decltype(glXGetSelectedEventSGIX)>;

glXCreateGLXPbufferSGIXPtr glXCreateGLXPbufferSGIX_ptr   = nullptr;
glXDestroyGLXPbufferSGIXPtr glXDestroyGLXPbufferSGIX_ptr = nullptr;
glXQueryGLXPbufferSGIXPtr glXQueryGLXPbufferSGIX_ptr     = nullptr;
glXSelectEventSGIXPtr glXSelectEventSGIX_ptr             = nullptr;
glXGetSelectedEventSGIXPtr glXGetSelectedEventSGIX_ptr   = nullptr;

bool init_glx_sgix_pbuffer([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glXCreateGLXPbufferSGIX_ptr = reinterpret_cast<glXCreateGLXPbufferSGIXPtr>(get_function("glXCreateGLXPbufferSGIX"))) == nullptr || result;
    result = (glXDestroyGLXPbufferSGIX_ptr = reinterpret_cast<glXDestroyGLXPbufferSGIXPtr>(get_function("glXDestroyGLXPbufferSGIX"))) == nullptr || result;
    result = (glXQueryGLXPbufferSGIX_ptr = reinterpret_cast<glXQueryGLXPbufferSGIXPtr>(get_function("glXQueryGLXPbufferSGIX"))) == nullptr || result;
    result = (glXSelectEventSGIX_ptr = reinterpret_cast<glXSelectEventSGIXPtr>(get_function("glXSelectEventSGIX"))) == nullptr || result;
    result = (glXGetSelectedEventSGIX_ptr = reinterpret_cast<glXGetSelectedEventSGIXPtr>(get_function("glXGetSelectedEventSGIX"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GLX_SGIX_swap_barrier

using glXBindSwapBarrierSGIXPtr      = std::add_pointer_t<decltype(glXBindSwapBarrierSGIX)>;
using glXQueryMaxSwapBarriersSGIXPtr = std::add_pointer_t<decltype(glXQueryMaxSwapBarriersSGIX)>;

glXBindSwapBarrierSGIXPtr glXBindSwapBarrierSGIX_ptr           = nullptr;
glXQueryMaxSwapBarriersSGIXPtr glXQueryMaxSwapBarriersSGIX_ptr = nullptr;

bool init_glx_sgix_swap_barrier([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glXBindSwapBarrierSGIX_ptr = reinterpret_cast<glXBindSwapBarrierSGIXPtr>(get_function("glXBindSwapBarrierSGIX"))) == nullptr || result;
    result = (glXQueryMaxSwapBarriersSGIX_ptr = reinterpret_cast<glXQueryMaxSwapBarriersSGIXPtr>(get_function("glXQueryMaxSwapBarriersSGIX"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GLX_SGIX_swap_group

using glXJoinSwapGroupSGIXPtr = std::add_pointer_t<decltype(glXJoinSwapGroupSGIX)>;

glXJoinSwapGroupSGIXPtr glXJoinSwapGroupSGIX_ptr = nullptr;

bool init_glx_sgix_swap_group([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glXJoinSwapGroupSGIX_ptr = reinterpret_cast<glXJoinSwapGroupSGIXPtr>(get_function("glXJoinSwapGroupSGIX"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GLX_SGIX_video_resize

using glXBindChannelToWindowSGIXPtr = std::add_pointer_t<decltype(glXBindChannelToWindowSGIX)>;
using glXChannelRectSGIXPtr         = std::add_pointer_t<decltype(glXChannelRectSGIX)>;
using glXQueryChannelRectSGIXPtr    = std::add_pointer_t<decltype(glXQueryChannelRectSGIX)>;
using glXQueryChannelDeltasSGIXPtr  = std::add_pointer_t<decltype(glXQueryChannelDeltasSGIX)>;
using glXChannelRectSyncSGIXPtr     = std::add_pointer_t<decltype(glXChannelRectSyncSGIX)>;

glXBindChannelToWindowSGIXPtr glXBindChannelToWindowSGIX_ptr = nullptr;
glXChannelRectSGIXPtr glXChannelRectSGIX_ptr                 = nullptr;
glXQueryChannelRectSGIXPtr glXQueryChannelRectSGIX_ptr       = nullptr;
glXQueryChannelDeltasSGIXPtr glXQueryChannelDeltasSGIX_ptr   = nullptr;
glXChannelRectSyncSGIXPtr glXChannelRectSyncSGIX_ptr         = nullptr;

bool init_glx_sgix_video_resize([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glXBindChannelToWindowSGIX_ptr = reinterpret_cast<glXBindChannelToWindowSGIXPtr>(get_function("glXBindChannelToWindowSGIX"))) == nullptr || result;
    result = (glXChannelRectSGIX_ptr = reinterpret_cast<glXChannelRectSGIXPtr>(get_function("glXChannelRectSGIX"))) == nullptr || result;
    result = (glXQueryChannelRectSGIX_ptr = reinterpret_cast<glXQueryChannelRectSGIXPtr>(get_function("glXQueryChannelRectSGIX"))) == nullptr || result;
    result = (glXQueryChannelDeltasSGIX_ptr = reinterpret_cast<glXQueryChannelDeltasSGIXPtr>(get_function("glXQueryChannelDeltasSGIX"))) == nullptr || result;
    result = (glXChannelRectSyncSGIX_ptr = reinterpret_cast<glXChannelRectSyncSGIXPtr>(get_function("glXChannelRectSyncSGIX"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GLX_SGIX_video_source

using glXCreateGLXVideoSourceSGIXPtr  = std::add_pointer_t<decltype(glXCreateGLXVideoSourceSGIX)>;
using glXDestroyGLXVideoSourceSGIXPtr = std::add_pointer_t<decltype(glXDestroyGLXVideoSourceSGIX)>;

glXCreateGLXVideoSourceSGIXPtr glXCreateGLXVideoSourceSGIX_ptr   = nullptr;
glXDestroyGLXVideoSourceSGIXPtr glXDestroyGLXVideoSourceSGIX_ptr = nullptr;

bool init_glx_sgix_video_source([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glXCreateGLXVideoSourceSGIX_ptr = reinterpret_cast<glXCreateGLXVideoSourceSGIXPtr>(get_function("glXCreateGLXVideoSourceSGIX"))) == nullptr || result;
    result = (glXDestroyGLXVideoSourceSGIX_ptr = reinterpret_cast<glXDestroyGLXVideoSourceSGIXPtr>(get_function("glXDestroyGLXVideoSourceSGIX"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GLX_SGIX_visual_select_group

bool init_glx_sgix_visual_select_group([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

#pragma region GLX_SUN_get_transparent_index

using glXGetTransparentIndexSUNPtr = std::add_pointer_t<decltype(glXGetTransparentIndexSUN)>;

glXGetTransparentIndexSUNPtr glXGetTransparentIndexSUN_ptr = nullptr;

bool init_glx_sun_get_transparent_index([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;

    // clang-format off
    result = (glXGetTransparentIndexSUN_ptr = reinterpret_cast<glXGetTransparentIndexSUNPtr>(get_function("glXGetTransparentIndexSUN"))) == nullptr || result;
    // clang-format on

    return !result;
}

#pragma endregion

#pragma region GLX_NV_multigpu_context

bool init_glx_nv_multigpu_context([[maybe_unused]] const GetFunction& get_function)
{
    bool result = false;
    return !result;
}

#pragma endregion

std::once_flag init_flag;

bool extension_cache[68] = {};

void init_features([[maybe_unused]] const GetFunction& get_function)
{
    // clang-format off

    // clang-format on
}

void init_extensions([[maybe_unused]] const GetFunction& get_function)
{
    // clang-format off
    extension_cache[static_cast<int>(Extension::GLX_3DFX_multisample)] = init_glx_3dfx_multisample(get_function);
    extension_cache[static_cast<int>(Extension::GLX_AMD_gpu_association)] = init_glx_amd_gpu_association(get_function);
    extension_cache[static_cast<int>(Extension::GLX_ARB_context_flush_control)] = init_glx_arb_context_flush_control(get_function);
    extension_cache[static_cast<int>(Extension::GLX_ARB_create_context)] = init_glx_arb_create_context(get_function);
    extension_cache[static_cast<int>(Extension::GLX_ARB_create_context_no_error)] = init_glx_arb_create_context_no_error(get_function);
    extension_cache[static_cast<int>(Extension::GLX_ARB_create_context_profile)] = init_glx_arb_create_context_profile(get_function);
    extension_cache[static_cast<int>(Extension::GLX_ARB_create_context_robustness)] = init_glx_arb_create_context_robustness(get_function);
    extension_cache[static_cast<int>(Extension::GLX_ARB_fbconfig_float)] = init_glx_arb_fbconfig_float(get_function);
    extension_cache[static_cast<int>(Extension::GLX_ARB_framebuffer_sRGB)] = init_glx_arb_framebuffer_srgb(get_function);
    extension_cache[static_cast<int>(Extension::GLX_ARB_get_proc_address)] = init_glx_arb_get_proc_address(get_function);
    extension_cache[static_cast<int>(Extension::GLX_ARB_multisample)] = init_glx_arb_multisample(get_function);
    extension_cache[static_cast<int>(Extension::GLX_ARB_robustness_application_isolation)] = init_glx_arb_robustness_application_isolation(get_function);
    extension_cache[static_cast<int>(Extension::GLX_ARB_robustness_share_group_isolation)] = init_glx_arb_robustness_share_group_isolation(get_function);
    extension_cache[static_cast<int>(Extension::GLX_ARB_vertex_buffer_object)] = init_glx_arb_vertex_buffer_object(get_function);
    extension_cache[static_cast<int>(Extension::GLX_EXT_buffer_age)] = init_glx_ext_buffer_age(get_function);
    extension_cache[static_cast<int>(Extension::GLX_EXT_context_priority)] = init_glx_ext_context_priority(get_function);
    extension_cache[static_cast<int>(Extension::GLX_EXT_create_context_es_profile)] = init_glx_ext_create_context_es_profile(get_function);
    extension_cache[static_cast<int>(Extension::GLX_EXT_create_context_es2_profile)] = init_glx_ext_create_context_es2_profile(get_function);
    extension_cache[static_cast<int>(Extension::GLX_EXT_fbconfig_packed_float)] = init_glx_ext_fbconfig_packed_float(get_function);
    extension_cache[static_cast<int>(Extension::GLX_EXT_framebuffer_sRGB)] = init_glx_ext_framebuffer_srgb(get_function);
    extension_cache[static_cast<int>(Extension::GLX_EXT_get_drawable_type)] = init_glx_ext_get_drawable_type(get_function);
    extension_cache[static_cast<int>(Extension::GLX_EXT_import_context)] = init_glx_ext_import_context(get_function);
    extension_cache[static_cast<int>(Extension::GLX_EXT_libglvnd)] = init_glx_ext_libglvnd(get_function);
    extension_cache[static_cast<int>(Extension::GLX_EXT_no_config_context)] = init_glx_ext_no_config_context(get_function);
    extension_cache[static_cast<int>(Extension::GLX_EXT_stereo_tree)] = init_glx_ext_stereo_tree(get_function);
    extension_cache[static_cast<int>(Extension::GLX_EXT_swap_control)] = init_glx_ext_swap_control(get_function);
    extension_cache[static_cast<int>(Extension::GLX_EXT_swap_control_tear)] = init_glx_ext_swap_control_tear(get_function);
    extension_cache[static_cast<int>(Extension::GLX_EXT_texture_from_pixmap)] = init_glx_ext_texture_from_pixmap(get_function);
    extension_cache[static_cast<int>(Extension::GLX_EXT_visual_info)] = init_glx_ext_visual_info(get_function);
    extension_cache[static_cast<int>(Extension::GLX_EXT_visual_rating)] = init_glx_ext_visual_rating(get_function);
    extension_cache[static_cast<int>(Extension::GLX_INTEL_swap_event)] = init_glx_intel_swap_event(get_function);
    extension_cache[static_cast<int>(Extension::GLX_MESA_agp_offset)] = init_glx_mesa_agp_offset(get_function);
    extension_cache[static_cast<int>(Extension::GLX_MESA_copy_sub_buffer)] = init_glx_mesa_copy_sub_buffer(get_function);
    extension_cache[static_cast<int>(Extension::GLX_MESA_pixmap_colormap)] = init_glx_mesa_pixmap_colormap(get_function);
    extension_cache[static_cast<int>(Extension::GLX_MESA_query_renderer)] = init_glx_mesa_query_renderer(get_function);
    extension_cache[static_cast<int>(Extension::GLX_MESA_release_buffers)] = init_glx_mesa_release_buffers(get_function);
    extension_cache[static_cast<int>(Extension::GLX_MESA_set_3dfx_mode)] = init_glx_mesa_set_3dfx_mode(get_function);
    extension_cache[static_cast<int>(Extension::GLX_MESA_swap_control)] = init_glx_mesa_swap_control(get_function);
    extension_cache[static_cast<int>(Extension::GLX_NV_copy_buffer)] = init_glx_nv_copy_buffer(get_function);
    extension_cache[static_cast<int>(Extension::GLX_NV_copy_image)] = init_glx_nv_copy_image(get_function);
    extension_cache[static_cast<int>(Extension::GLX_NV_delay_before_swap)] = init_glx_nv_delay_before_swap(get_function);
    extension_cache[static_cast<int>(Extension::GLX_NV_float_buffer)] = init_glx_nv_float_buffer(get_function);
    extension_cache[static_cast<int>(Extension::GLX_NV_multisample_coverage)] = init_glx_nv_multisample_coverage(get_function);
    extension_cache[static_cast<int>(Extension::GLX_NV_present_video)] = init_glx_nv_present_video(get_function);
    extension_cache[static_cast<int>(Extension::GLX_NV_robustness_video_memory_purge)] = init_glx_nv_robustness_video_memory_purge(get_function);
    extension_cache[static_cast<int>(Extension::GLX_NV_swap_group)] = init_glx_nv_swap_group(get_function);
    extension_cache[static_cast<int>(Extension::GLX_NV_video_capture)] = init_glx_nv_video_capture(get_function);
    extension_cache[static_cast<int>(Extension::GLX_NV_video_out)] = init_glx_nv_video_out(get_function);
    extension_cache[static_cast<int>(Extension::GLX_OML_swap_method)] = init_glx_oml_swap_method(get_function);
    extension_cache[static_cast<int>(Extension::GLX_OML_sync_control)] = init_glx_oml_sync_control(get_function);
    extension_cache[static_cast<int>(Extension::GLX_SGI_cushion)] = init_glx_sgi_cushion(get_function);
    extension_cache[static_cast<int>(Extension::GLX_SGI_make_current_read)] = init_glx_sgi_make_current_read(get_function);
    extension_cache[static_cast<int>(Extension::GLX_SGI_swap_control)] = init_glx_sgi_swap_control(get_function);
    extension_cache[static_cast<int>(Extension::GLX_SGI_video_sync)] = init_glx_sgi_video_sync(get_function);
    extension_cache[static_cast<int>(Extension::GLX_SGIS_blended_overlay)] = init_glx_sgis_blended_overlay(get_function);
    extension_cache[static_cast<int>(Extension::GLX_SGIS_multisample)] = init_glx_sgis_multisample(get_function);
    extension_cache[static_cast<int>(Extension::GLX_SGIS_shared_multisample)] = init_glx_sgis_shared_multisample(get_function);
    extension_cache[static_cast<int>(Extension::GLX_SGIX_dmbuffer)] = init_glx_sgix_dmbuffer(get_function);
    extension_cache[static_cast<int>(Extension::GLX_SGIX_fbconfig)] = init_glx_sgix_fbconfig(get_function);
    extension_cache[static_cast<int>(Extension::GLX_SGIX_hyperpipe)] = init_glx_sgix_hyperpipe(get_function);
    extension_cache[static_cast<int>(Extension::GLX_SGIX_pbuffer)] = init_glx_sgix_pbuffer(get_function);
    extension_cache[static_cast<int>(Extension::GLX_SGIX_swap_barrier)] = init_glx_sgix_swap_barrier(get_function);
    extension_cache[static_cast<int>(Extension::GLX_SGIX_swap_group)] = init_glx_sgix_swap_group(get_function);
    extension_cache[static_cast<int>(Extension::GLX_SGIX_video_resize)] = init_glx_sgix_video_resize(get_function);
    extension_cache[static_cast<int>(Extension::GLX_SGIX_video_source)] = init_glx_sgix_video_source(get_function);
    extension_cache[static_cast<int>(Extension::GLX_SGIX_visual_select_group)] = init_glx_sgix_visual_select_group(get_function);
    extension_cache[static_cast<int>(Extension::GLX_SUN_get_transparent_index)] = init_glx_sun_get_transparent_index(get_function);
    extension_cache[static_cast<int>(Extension::GLX_NV_multigpu_context)] = init_glx_nv_multigpu_context(get_function);
    // clang-format on
}

} // namespace

namespace framework::system::details::glx
{

#pragma region GLX_3DFX_multisample

#pragma endregion

#pragma region GLX_AMD_gpu_association

unsigned int glXGetGPUIDsAMD(unsigned int maxCount, unsigned int* ids)
{
    return glXGetGPUIDsAMD_ptr(maxCount, ids);
}

int glXGetGPUInfoAMD(unsigned int id, int property, GLenum dataType, unsigned int size, void* data)
{
    return glXGetGPUInfoAMD_ptr(id, property, dataType, size, data);
}

unsigned int glXGetContextGPUIDAMD(GLXContext ctx)
{
    return glXGetContextGPUIDAMD_ptr(ctx);
}

GLXContext glXCreateAssociatedContextAMD(unsigned int id, GLXContext share_list)
{
    return glXCreateAssociatedContextAMD_ptr(id, share_list);
}

GLXContext glXCreateAssociatedContextAttribsAMD(unsigned int id, GLXContext share_context, const int* attribList)
{
    return glXCreateAssociatedContextAttribsAMD_ptr(id, share_context, attribList);
}

Bool glXDeleteAssociatedContextAMD(GLXContext ctx)
{
    return glXDeleteAssociatedContextAMD_ptr(ctx);
}

Bool glXMakeAssociatedContextCurrentAMD(GLXContext ctx)
{
    return glXMakeAssociatedContextCurrentAMD_ptr(ctx);
}

GLXContext glXGetCurrentAssociatedContextAMD()
{
    return glXGetCurrentAssociatedContextAMD_ptr();
}

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
                                  GLenum filter)
{
    glXBlitContextFramebufferAMD_ptr(dstCtx, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}

#pragma endregion

#pragma region GLX_ARB_context_flush_control

#pragma endregion

#pragma region GLX_ARB_create_context

GLXContext glXCreateContextAttribsARB(Display* dpy,
                                      GLXFBConfig config,
                                      GLXContext share_context,
                                      Bool direct,
                                      const int* attrib_list)
{
    return glXCreateContextAttribsARB_ptr(dpy, config, share_context, direct, attrib_list);
}

#pragma endregion

#pragma region GLX_ARB_create_context_no_error

#pragma endregion

#pragma region GLX_ARB_create_context_profile

#pragma endregion

#pragma region GLX_ARB_create_context_robustness

#pragma endregion

#pragma region GLX_ARB_fbconfig_float

#pragma endregion

#pragma region GLX_ARB_framebuffer_sRGB

#pragma endregion

#pragma region GLX_ARB_get_proc_address

__GLXextFuncPtr glXGetProcAddressARB(const GLubyte* procName)
{
    return glXGetProcAddressARB_ptr(procName);
}

#pragma endregion

#pragma region GLX_ARB_multisample

#pragma endregion

#pragma region GLX_ARB_robustness_application_isolation

#pragma endregion

#pragma region GLX_ARB_robustness_share_group_isolation

#pragma endregion

#pragma region GLX_ARB_vertex_buffer_object

#pragma endregion

#pragma region GLX_EXT_buffer_age

#pragma endregion

#pragma region GLX_EXT_context_priority

#pragma endregion

#pragma region GLX_EXT_create_context_es_profile

#pragma endregion

#pragma region GLX_EXT_create_context_es2_profile

#pragma endregion

#pragma region GLX_EXT_fbconfig_packed_float

#pragma endregion

#pragma region GLX_EXT_framebuffer_sRGB

#pragma endregion

#pragma region GLX_EXT_get_drawable_type

#pragma endregion

#pragma region GLX_EXT_import_context

Display* glXGetCurrentDisplayEXT()
{
    return glXGetCurrentDisplayEXT_ptr();
}

int glXQueryContextInfoEXT(Display* dpy, GLXContext context, int attribute, int* value)
{
    return glXQueryContextInfoEXT_ptr(dpy, context, attribute, value);
}

GLXContextID glXGetContextIDEXT(const GLXContext context)
{
    return glXGetContextIDEXT_ptr(context);
}

GLXContext glXImportContextEXT(Display* dpy, GLXContextID contextID)
{
    return glXImportContextEXT_ptr(dpy, contextID);
}

void glXFreeContextEXT(Display* dpy, GLXContext context)
{
    glXFreeContextEXT_ptr(dpy, context);
}

#pragma endregion

#pragma region GLX_EXT_libglvnd

#pragma endregion

#pragma region GLX_EXT_no_config_context

#pragma endregion

#pragma region GLX_EXT_stereo_tree

#pragma endregion

#pragma region GLX_EXT_swap_control

void glXSwapIntervalEXT(Display* dpy, GLXDrawable drawable, int interval)
{
    glXSwapIntervalEXT_ptr(dpy, drawable, interval);
}

#pragma endregion

#pragma region GLX_EXT_swap_control_tear

#pragma endregion

#pragma region GLX_EXT_texture_from_pixmap

void glXBindTexImageEXT(Display* dpy, GLXDrawable drawable, int buffer, const int* attrib_list)
{
    glXBindTexImageEXT_ptr(dpy, drawable, buffer, attrib_list);
}

void glXReleaseTexImageEXT(Display* dpy, GLXDrawable drawable, int buffer)
{
    glXReleaseTexImageEXT_ptr(dpy, drawable, buffer);
}

#pragma endregion

#pragma region GLX_EXT_visual_info

#pragma endregion

#pragma region GLX_EXT_visual_rating

#pragma endregion

#pragma region GLX_INTEL_swap_event

#pragma endregion

#pragma region GLX_MESA_agp_offset

unsigned int glXGetAGPOffsetMESA(const void* pointer)
{
    return glXGetAGPOffsetMESA_ptr(pointer);
}

#pragma endregion

#pragma region GLX_MESA_copy_sub_buffer

void glXCopySubBufferMESA(Display* dpy, GLXDrawable drawable, int x, int y, int width, int height)
{
    glXCopySubBufferMESA_ptr(dpy, drawable, x, y, width, height);
}

#pragma endregion

#pragma region GLX_MESA_pixmap_colormap

GLXPixmap glXCreateGLXPixmapMESA(Display* dpy, XVisualInfo* visual, Pixmap pixmap, Colormap cmap)
{
    return glXCreateGLXPixmapMESA_ptr(dpy, visual, pixmap, cmap);
}

#pragma endregion

#pragma region GLX_MESA_query_renderer

Bool glXQueryCurrentRendererIntegerMESA(int attribute, unsigned int* value)
{
    return glXQueryCurrentRendererIntegerMESA_ptr(attribute, value);
}

const char* glXQueryCurrentRendererStringMESA(int attribute)
{
    return glXQueryCurrentRendererStringMESA_ptr(attribute);
}

Bool glXQueryRendererIntegerMESA(Display* dpy, int screen, int renderer, int attribute, unsigned int* value)
{
    return glXQueryRendererIntegerMESA_ptr(dpy, screen, renderer, attribute, value);
}

const char* glXQueryRendererStringMESA(Display* dpy, int screen, int renderer, int attribute)
{
    return glXQueryRendererStringMESA_ptr(dpy, screen, renderer, attribute);
}

#pragma endregion

#pragma region GLX_MESA_release_buffers

Bool glXReleaseBuffersMESA(Display* dpy, GLXDrawable drawable)
{
    return glXReleaseBuffersMESA_ptr(dpy, drawable);
}

#pragma endregion

#pragma region GLX_MESA_set_3dfx_mode

GLboolean glXSet3DfxModeMESA(GLint mode)
{
    return glXSet3DfxModeMESA_ptr(mode);
}

#pragma endregion

#pragma region GLX_MESA_swap_control

int glXGetSwapIntervalMESA()
{
    return glXGetSwapIntervalMESA_ptr();
}

int glXSwapIntervalMESA(unsigned int interval)
{
    return glXSwapIntervalMESA_ptr(interval);
}

#pragma endregion

#pragma region GLX_NV_copy_buffer

void glXCopyBufferSubDataNV(Display* dpy,
                            GLXContext readCtx,
                            GLXContext writeCtx,
                            GLenum readTarget,
                            GLenum writeTarget,
                            GLintptr readOffset,
                            GLintptr writeOffset,
                            GLsizeiptr size)
{
    glXCopyBufferSubDataNV_ptr(dpy, readCtx, writeCtx, readTarget, writeTarget, readOffset, writeOffset, size);
}

void glXNamedCopyBufferSubDataNV(Display* dpy,
                                 GLXContext readCtx,
                                 GLXContext writeCtx,
                                 GLuint readBuffer,
                                 GLuint writeBuffer,
                                 GLintptr readOffset,
                                 GLintptr writeOffset,
                                 GLsizeiptr size)
{
    glXNamedCopyBufferSubDataNV_ptr(dpy, readCtx, writeCtx, readBuffer, writeBuffer, readOffset, writeOffset, size);
}

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
                           GLsizei depth)
{
    glXCopyImageSubDataNV_ptr(dpy,
                              srcCtx,
                              srcName,
                              srcTarget,
                              srcLevel,
                              srcX,
                              srcY,
                              srcZ,
                              dstCtx,
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

#pragma region GLX_NV_delay_before_swap

Bool glXDelayBeforeSwapNV(Display* dpy, GLXDrawable drawable, GLfloat seconds)
{
    return glXDelayBeforeSwapNV_ptr(dpy, drawable, seconds);
}

#pragma endregion

#pragma region GLX_NV_float_buffer

#pragma endregion

#pragma region GLX_NV_multisample_coverage

#pragma endregion

#pragma region GLX_NV_present_video

unsigned int* glXEnumerateVideoDevicesNV(Display* dpy, int screen, int* nelements)
{
    return glXEnumerateVideoDevicesNV_ptr(dpy, screen, nelements);
}

int glXBindVideoDeviceNV(Display* dpy, unsigned int video_slot, unsigned int video_device, const int* attrib_list)
{
    return glXBindVideoDeviceNV_ptr(dpy, video_slot, video_device, attrib_list);
}

#pragma endregion

#pragma region GLX_NV_robustness_video_memory_purge

#pragma endregion

#pragma region GLX_NV_swap_group

Bool glXJoinSwapGroupNV(Display* dpy, GLXDrawable drawable, GLuint group)
{
    return glXJoinSwapGroupNV_ptr(dpy, drawable, group);
}

Bool glXBindSwapBarrierNV(Display* dpy, GLuint group, GLuint barrier)
{
    return glXBindSwapBarrierNV_ptr(dpy, group, barrier);
}

Bool glXQuerySwapGroupNV(Display* dpy, GLXDrawable drawable, GLuint* group, GLuint* barrier)
{
    return glXQuerySwapGroupNV_ptr(dpy, drawable, group, barrier);
}

Bool glXQueryMaxSwapGroupsNV(Display* dpy, int screen, GLuint* maxGroups, GLuint* maxBarriers)
{
    return glXQueryMaxSwapGroupsNV_ptr(dpy, screen, maxGroups, maxBarriers);
}

Bool glXQueryFrameCountNV(Display* dpy, int screen, GLuint* count)
{
    return glXQueryFrameCountNV_ptr(dpy, screen, count);
}

Bool glXResetFrameCountNV(Display* dpy, int screen)
{
    return glXResetFrameCountNV_ptr(dpy, screen);
}

#pragma endregion

#pragma region GLX_NV_video_capture

int glXBindVideoCaptureDeviceNV(Display* dpy, unsigned int video_capture_slot, GLXVideoCaptureDeviceNV device)
{
    return glXBindVideoCaptureDeviceNV_ptr(dpy, video_capture_slot, device);
}

GLXVideoCaptureDeviceNV* glXEnumerateVideoCaptureDevicesNV(Display* dpy, int screen, int* nelements)
{
    return glXEnumerateVideoCaptureDevicesNV_ptr(dpy, screen, nelements);
}

void glXLockVideoCaptureDeviceNV(Display* dpy, GLXVideoCaptureDeviceNV device)
{
    glXLockVideoCaptureDeviceNV_ptr(dpy, device);
}

int glXQueryVideoCaptureDeviceNV(Display* dpy, GLXVideoCaptureDeviceNV device, int attribute, int* value)
{
    return glXQueryVideoCaptureDeviceNV_ptr(dpy, device, attribute, value);
}

void glXReleaseVideoCaptureDeviceNV(Display* dpy, GLXVideoCaptureDeviceNV device)
{
    glXReleaseVideoCaptureDeviceNV_ptr(dpy, device);
}

#pragma endregion

#pragma region GLX_NV_video_out

int glXGetVideoDeviceNV(Display* dpy, int screen, int numVideoDevices, GLXVideoDeviceNV* pVideoDevice)
{
    return glXGetVideoDeviceNV_ptr(dpy, screen, numVideoDevices, pVideoDevice);
}

int glXReleaseVideoDeviceNV(Display* dpy, int screen, GLXVideoDeviceNV VideoDevice)
{
    return glXReleaseVideoDeviceNV_ptr(dpy, screen, VideoDevice);
}

int glXBindVideoImageNV(Display* dpy, GLXVideoDeviceNV VideoDevice, GLXPbuffer pbuf, int iVideoBuffer)
{
    return glXBindVideoImageNV_ptr(dpy, VideoDevice, pbuf, iVideoBuffer);
}

int glXReleaseVideoImageNV(Display* dpy, GLXPbuffer pbuf)
{
    return glXReleaseVideoImageNV_ptr(dpy, pbuf);
}

int glXSendPbufferToVideoNV(Display* dpy,
                            GLXPbuffer pbuf,
                            int iBufferType,
                            unsigned long* pulCounterPbuffer,
                            GLboolean bBlock)
{
    return glXSendPbufferToVideoNV_ptr(dpy, pbuf, iBufferType, pulCounterPbuffer, bBlock);
}

int glXGetVideoInfoNV(Display* dpy,
                      int screen,
                      GLXVideoDeviceNV VideoDevice,
                      unsigned long* pulCounterOutputPbuffer,
                      unsigned long* pulCounterOutputVideo)
{
    return glXGetVideoInfoNV_ptr(dpy, screen, VideoDevice, pulCounterOutputPbuffer, pulCounterOutputVideo);
}

#pragma endregion

#pragma region GLX_OML_swap_method

#pragma endregion

#pragma region GLX_OML_sync_control

Bool glXGetSyncValuesOML(Display* dpy, GLXDrawable drawable, int64_t* ust, int64_t* msc, int64_t* sbc)
{
    return glXGetSyncValuesOML_ptr(dpy, drawable, ust, msc, sbc);
}

Bool glXGetMscRateOML(Display* dpy, GLXDrawable drawable, int32_t* numerator, int32_t* denominator)
{
    return glXGetMscRateOML_ptr(dpy, drawable, numerator, denominator);
}

int64_t glXSwapBuffersMscOML(Display* dpy, GLXDrawable drawable, int64_t target_msc, int64_t divisor, int64_t remainder)
{
    return glXSwapBuffersMscOML_ptr(dpy, drawable, target_msc, divisor, remainder);
}

Bool glXWaitForMscOML(Display* dpy,
                      GLXDrawable drawable,
                      int64_t target_msc,
                      int64_t divisor,
                      int64_t remainder,
                      int64_t* ust,
                      int64_t* msc,
                      int64_t* sbc)
{
    return glXWaitForMscOML_ptr(dpy, drawable, target_msc, divisor, remainder, ust, msc, sbc);
}

Bool glXWaitForSbcOML(Display* dpy, GLXDrawable drawable, int64_t target_sbc, int64_t* ust, int64_t* msc, int64_t* sbc)
{
    return glXWaitForSbcOML_ptr(dpy, drawable, target_sbc, ust, msc, sbc);
}

#pragma endregion

#pragma region GLX_SGI_cushion

void glXCushionSGI(Display* dpy, Window window, float cushion)
{
    glXCushionSGI_ptr(dpy, window, cushion);
}

#pragma endregion

#pragma region GLX_SGI_make_current_read

Bool glXMakeCurrentReadSGI(Display* dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx)
{
    return glXMakeCurrentReadSGI_ptr(dpy, draw, read, ctx);
}

GLXDrawable glXGetCurrentReadDrawableSGI()
{
    return glXGetCurrentReadDrawableSGI_ptr();
}

#pragma endregion

#pragma region GLX_SGI_swap_control

int glXSwapIntervalSGI(int interval)
{
    return glXSwapIntervalSGI_ptr(interval);
}

#pragma endregion

#pragma region GLX_SGI_video_sync

int glXGetVideoSyncSGI(unsigned int* count)
{
    return glXGetVideoSyncSGI_ptr(count);
}

int glXWaitVideoSyncSGI(int divisor, int remainder, unsigned int* count)
{
    return glXWaitVideoSyncSGI_ptr(divisor, remainder, count);
}

#pragma endregion

#pragma region GLX_SGIS_blended_overlay

#pragma endregion

#pragma region GLX_SGIS_multisample

#pragma endregion

#pragma region GLX_SGIS_shared_multisample

#pragma endregion

#pragma region GLX_SGIX_dmbuffer

Bool glXAssociateDMPbufferSGIX(Display* dpy, GLXPbufferSGIX pbuffer, DMparams* params, DMbuffer dmbuffer)
{
    return glXAssociateDMPbufferSGIX_ptr(dpy, pbuffer, params, dmbuffer);
}

#pragma endregion

#pragma region GLX_SGIX_fbconfig

int glXGetFBConfigAttribSGIX(Display* dpy, GLXFBConfigSGIX config, int attribute, int* value)
{
    return glXGetFBConfigAttribSGIX_ptr(dpy, config, attribute, value);
}

GLXFBConfigSGIX* glXChooseFBConfigSGIX(Display* dpy, int screen, int* attrib_list, int* nelements)
{
    return glXChooseFBConfigSGIX_ptr(dpy, screen, attrib_list, nelements);
}

GLXPixmap glXCreateGLXPixmapWithConfigSGIX(Display* dpy, GLXFBConfigSGIX config, Pixmap pixmap)
{
    return glXCreateGLXPixmapWithConfigSGIX_ptr(dpy, config, pixmap);
}

GLXContext glXCreateContextWithConfigSGIX(Display* dpy,
                                          GLXFBConfigSGIX config,
                                          int render_type,
                                          GLXContext share_list,
                                          Bool direct)
{
    return glXCreateContextWithConfigSGIX_ptr(dpy, config, render_type, share_list, direct);
}

XVisualInfo* glXGetVisualFromFBConfigSGIX(Display* dpy, GLXFBConfigSGIX config)
{
    return glXGetVisualFromFBConfigSGIX_ptr(dpy, config);
}

GLXFBConfigSGIX glXGetFBConfigFromVisualSGIX(Display* dpy, XVisualInfo* vis)
{
    return glXGetFBConfigFromVisualSGIX_ptr(dpy, vis);
}

#pragma endregion

#pragma region GLX_SGIX_hyperpipe

GLXHyperpipeNetworkSGIX* glXQueryHyperpipeNetworkSGIX(Display* dpy, int* npipes)
{
    return glXQueryHyperpipeNetworkSGIX_ptr(dpy, npipes);
}

int glXHyperpipeConfigSGIX(Display* dpy, int networkId, int npipes, GLXHyperpipeConfigSGIX* cfg, int* hpId)
{
    return glXHyperpipeConfigSGIX_ptr(dpy, networkId, npipes, cfg, hpId);
}

GLXHyperpipeConfigSGIX* glXQueryHyperpipeConfigSGIX(Display* dpy, int hpId, int* npipes)
{
    return glXQueryHyperpipeConfigSGIX_ptr(dpy, hpId, npipes);
}

int glXDestroyHyperpipeConfigSGIX(Display* dpy, int hpId)
{
    return glXDestroyHyperpipeConfigSGIX_ptr(dpy, hpId);
}

int glXBindHyperpipeSGIX(Display* dpy, int hpId)
{
    return glXBindHyperpipeSGIX_ptr(dpy, hpId);
}

int glXQueryHyperpipeBestAttribSGIX(Display* dpy,
                                    int timeSlice,
                                    int attrib,
                                    int size,
                                    void* attribList,
                                    void* returnAttribList)
{
    return glXQueryHyperpipeBestAttribSGIX_ptr(dpy, timeSlice, attrib, size, attribList, returnAttribList);
}

int glXHyperpipeAttribSGIX(Display* dpy, int timeSlice, int attrib, int size, void* attribList)
{
    return glXHyperpipeAttribSGIX_ptr(dpy, timeSlice, attrib, size, attribList);
}

int glXQueryHyperpipeAttribSGIX(Display* dpy, int timeSlice, int attrib, int size, void* returnAttribList)
{
    return glXQueryHyperpipeAttribSGIX_ptr(dpy, timeSlice, attrib, size, returnAttribList);
}

#pragma endregion

#pragma region GLX_SGIX_pbuffer

GLXPbufferSGIX glXCreateGLXPbufferSGIX(Display* dpy,
                                       GLXFBConfigSGIX config,
                                       unsigned int width,
                                       unsigned int height,
                                       int* attrib_list)
{
    return glXCreateGLXPbufferSGIX_ptr(dpy, config, width, height, attrib_list);
}

void glXDestroyGLXPbufferSGIX(Display* dpy, GLXPbufferSGIX pbuf)
{
    glXDestroyGLXPbufferSGIX_ptr(dpy, pbuf);
}

void glXQueryGLXPbufferSGIX(Display* dpy, GLXPbufferSGIX pbuf, int attribute, unsigned int* value)
{
    glXQueryGLXPbufferSGIX_ptr(dpy, pbuf, attribute, value);
}

void glXSelectEventSGIX(Display* dpy, GLXDrawable drawable, unsigned long mask)
{
    glXSelectEventSGIX_ptr(dpy, drawable, mask);
}

void glXGetSelectedEventSGIX(Display* dpy, GLXDrawable drawable, unsigned long* mask)
{
    glXGetSelectedEventSGIX_ptr(dpy, drawable, mask);
}

#pragma endregion

#pragma region GLX_SGIX_swap_barrier

void glXBindSwapBarrierSGIX(Display* dpy, GLXDrawable drawable, int barrier)
{
    glXBindSwapBarrierSGIX_ptr(dpy, drawable, barrier);
}

Bool glXQueryMaxSwapBarriersSGIX(Display* dpy, int screen, int* max)
{
    return glXQueryMaxSwapBarriersSGIX_ptr(dpy, screen, max);
}

#pragma endregion

#pragma region GLX_SGIX_swap_group

void glXJoinSwapGroupSGIX(Display* dpy, GLXDrawable drawable, GLXDrawable member)
{
    glXJoinSwapGroupSGIX_ptr(dpy, drawable, member);
}

#pragma endregion

#pragma region GLX_SGIX_video_resize

int glXBindChannelToWindowSGIX(Display* display, int screen, int channel, Window window)
{
    return glXBindChannelToWindowSGIX_ptr(display, screen, channel, window);
}

int glXChannelRectSGIX(Display* display, int screen, int channel, int x, int y, int w, int h)
{
    return glXChannelRectSGIX_ptr(display, screen, channel, x, y, w, h);
}

int glXQueryChannelRectSGIX(Display* display, int screen, int channel, int* dx, int* dy, int* dw, int* dh)
{
    return glXQueryChannelRectSGIX_ptr(display, screen, channel, dx, dy, dw, dh);
}

int glXQueryChannelDeltasSGIX(Display* display, int screen, int channel, int* x, int* y, int* w, int* h)
{
    return glXQueryChannelDeltasSGIX_ptr(display, screen, channel, x, y, w, h);
}

int glXChannelRectSyncSGIX(Display* display, int screen, int channel, GLenum synctype)
{
    return glXChannelRectSyncSGIX_ptr(display, screen, channel, synctype);
}

#pragma endregion

#pragma region GLX_SGIX_video_source

GLXVideoSourceSGIX glXCreateGLXVideoSourceSGIX(Display* display,
                                               int screen,
                                               VLServer server,
                                               VLPath path,
                                               int nodeClass,
                                               VLNode drainNode)
{
    return glXCreateGLXVideoSourceSGIX_ptr(display, screen, server, path, nodeClass, drainNode);
}

void glXDestroyGLXVideoSourceSGIX(Display* dpy, GLXVideoSourceSGIX glxvideosource)
{
    glXDestroyGLXVideoSourceSGIX_ptr(dpy, glxvideosource);
}

#pragma endregion

#pragma region GLX_SGIX_visual_select_group

#pragma endregion

#pragma region GLX_SUN_get_transparent_index

Status glXGetTransparentIndexSUN(Display* dpy, Window overlay, Window underlay, unsigned long* pTransparentIndex)
{
    return glXGetTransparentIndexSUN_ptr(dpy, overlay, underlay, pTransparentIndex);
}

#pragma endregion

#pragma region GLX_NV_multigpu_context

#pragma endregion

void init_glx(const GetFunction& get_function)
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

} // namespace framework::system::details::glx
