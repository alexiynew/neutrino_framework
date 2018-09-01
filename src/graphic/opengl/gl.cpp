/// @file
/// @brief OpneGL functions wrapper.
/// @author Fedorov Alexey
/// @date 21.06.2018

#include <graphic/opengl/gl.hpp>
#include <graphic/opengl/gl_details.hpp>

namespace
{
template <typename F>
F get_function(const char* function_name)
{
    return reinterpret_cast<F>(framework::graphic::gl::details::get_function(function_name));
}

} // namespace

namespace framework::graphic::gl
{
#pragma region GL_VERSION_1_0

#ifdef GL_VERSION_1_0

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

bool init_gl_version_1_0()
{
    bool result = true;

    result = result && (glCullFace = get_function<PFNGLCULLFACEPROC>("glCullFace")) != nullptr;
    result = result && (glFrontFace = get_function<PFNGLFRONTFACEPROC>("glFrontFace")) != nullptr;
    result = result && (glHint = get_function<PFNGLHINTPROC>("glHint")) != nullptr;
    result = result && (glLineWidth = get_function<PFNGLLINEWIDTHPROC>("glLineWidth")) != nullptr;
    result = result && (glPointSize = get_function<PFNGLPOINTSIZEPROC>("glPointSize")) != nullptr;
    result = result && (glPolygonMode = get_function<PFNGLPOLYGONMODEPROC>("glPolygonMode")) != nullptr;
    result = result && (glScissor = get_function<PFNGLSCISSORPROC>("glScissor")) != nullptr;
    result = result && (glTexParameterf = get_function<PFNGLTEXPARAMETERFPROC>("glTexParameterf")) != nullptr;
    result = result && (glTexParameterfv = get_function<PFNGLTEXPARAMETERFVPROC>("glTexParameterfv")) != nullptr;
    result = result && (glTexParameteri = get_function<PFNGLTEXPARAMETERIPROC>("glTexParameteri")) != nullptr;
    result = result && (glTexParameteriv = get_function<PFNGLTEXPARAMETERIVPROC>("glTexParameteriv")) != nullptr;
    result = result && (glTexImage1D = get_function<PFNGLTEXIMAGE1DPROC>("glTexImage1D")) != nullptr;
    result = result && (glTexImage2D = get_function<PFNGLTEXIMAGE2DPROC>("glTexImage2D")) != nullptr;
    result = result && (glDrawBuffer = get_function<PFNGLDRAWBUFFERPROC>("glDrawBuffer")) != nullptr;
    result = result && (glClear = get_function<PFNGLCLEARPROC>("glClear")) != nullptr;
    result = result && (glClearColor = get_function<PFNGLCLEARCOLORPROC>("glClearColor")) != nullptr;
    result = result && (glClearStencil = get_function<PFNGLCLEARSTENCILPROC>("glClearStencil")) != nullptr;
    result = result && (glClearDepth = get_function<PFNGLCLEARDEPTHPROC>("glClearDepth")) != nullptr;
    result = result && (glStencilMask = get_function<PFNGLSTENCILMASKPROC>("glStencilMask")) != nullptr;
    result = result && (glColorMask = get_function<PFNGLCOLORMASKPROC>("glColorMask")) != nullptr;
    result = result && (glDepthMask = get_function<PFNGLDEPTHMASKPROC>("glDepthMask")) != nullptr;
    result = result && (glDisable = get_function<PFNGLDISABLEPROC>("glDisable")) != nullptr;
    result = result && (glEnable = get_function<PFNGLENABLEPROC>("glEnable")) != nullptr;
    result = result && (glFinish = get_function<PFNGLFINISHPROC>("glFinish")) != nullptr;
    result = result && (glFlush = get_function<PFNGLFLUSHPROC>("glFlush")) != nullptr;
    result = result && (glBlendFunc = get_function<PFNGLBLENDFUNCPROC>("glBlendFunc")) != nullptr;
    result = result && (glLogicOp = get_function<PFNGLLOGICOPPROC>("glLogicOp")) != nullptr;
    result = result && (glStencilFunc = get_function<PFNGLSTENCILFUNCPROC>("glStencilFunc")) != nullptr;
    result = result && (glStencilOp = get_function<PFNGLSTENCILOPPROC>("glStencilOp")) != nullptr;
    result = result && (glDepthFunc = get_function<PFNGLDEPTHFUNCPROC>("glDepthFunc")) != nullptr;
    result = result && (glPixelStoref = get_function<PFNGLPIXELSTOREFPROC>("glPixelStoref")) != nullptr;
    result = result && (glPixelStorei = get_function<PFNGLPIXELSTOREIPROC>("glPixelStorei")) != nullptr;
    result = result && (glReadBuffer = get_function<PFNGLREADBUFFERPROC>("glReadBuffer")) != nullptr;
    result = result && (glReadPixels = get_function<PFNGLREADPIXELSPROC>("glReadPixels")) != nullptr;
    result = result && (glGetBooleanv = get_function<PFNGLGETBOOLEANVPROC>("glGetBooleanv")) != nullptr;
    result = result && (glGetDoublev = get_function<PFNGLGETDOUBLEVPROC>("glGetDoublev")) != nullptr;
    result = result && (glGetError = get_function<PFNGLGETERRORPROC>("glGetError")) != nullptr;
    result = result && (glGetFloatv = get_function<PFNGLGETFLOATVPROC>("glGetFloatv")) != nullptr;
    result = result && (glGetIntegerv = get_function<PFNGLGETINTEGERVPROC>("glGetIntegerv")) != nullptr;
    result = result && (glGetString = get_function<PFNGLGETSTRINGPROC>("glGetString")) != nullptr;
    result = result && (glGetTexImage = get_function<PFNGLGETTEXIMAGEPROC>("glGetTexImage")) != nullptr;
    result = result &&
             (glGetTexParameterfv = get_function<PFNGLGETTEXPARAMETERFVPROC>("glGetTexParameterfv")) != nullptr;
    result = result &&
             (glGetTexParameteriv = get_function<PFNGLGETTEXPARAMETERIVPROC>("glGetTexParameteriv")) != nullptr;
    result = result &&
             (glGetTexLevelParameterfv = get_function<PFNGLGETTEXLEVELPARAMETERFVPROC>("glGetTexLevelParameterfv")) !=
             nullptr;
    result = result &&
             (glGetTexLevelParameteriv = get_function<PFNGLGETTEXLEVELPARAMETERIVPROC>("glGetTexLevelParameteriv")) !=
             nullptr;
    result = result && (glIsEnabled = get_function<PFNGLISENABLEDPROC>("glIsEnabled")) != nullptr;
    result = result && (glDepthRange = get_function<PFNGLDEPTHRANGEPROC>("glDepthRange")) != nullptr;
    result = result && (glViewport = get_function<PFNGLVIEWPORTPROC>("glViewport")) != nullptr;

    return result;
}

#endif // GL_VERSION_1_0

#pragma endregion

#pragma region GL_VERSION_1_1

#ifdef GL_VERSION_1_1

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

bool init_gl_version_1_1()
{
    bool result = true;

    // clang-format off
    result = result && (glDrawArrays = get_function<PFNGLDRAWARRAYSPROC>("glDrawArrays")) != nullptr;
    result = result && (glDrawElements = get_function<PFNGLDRAWELEMENTSPROC>("glDrawElements")) != nullptr;
    result = result && (glGetPointerv = get_function<PFNGLGETPOINTERVPROC>("glGetPointerv")) != nullptr;
    result = result && (glPolygonOffset = get_function<PFNGLPOLYGONOFFSETPROC>("glPolygonOffset")) != nullptr;
    result = result && (glCopyTexImage1D = get_function<PFNGLCOPYTEXIMAGE1DPROC>("glCopyTexImage1D")) != nullptr;
    result = result && (glCopyTexImage2D = get_function<PFNGLCOPYTEXIMAGE2DPROC>("glCopyTexImage2D")) != nullptr;
    result = result && (glCopyTexSubImage1D = get_function<PFNGLCOPYTEXSUBIMAGE1DPROC>("glCopyTexSubImage1D")) != nullptr;
    result = result && (glCopyTexSubImage2D = get_function<PFNGLCOPYTEXSUBIMAGE2DPROC>("glCopyTexSubImage2D")) != nullptr;
    result = result && (glTexSubImage1D = get_function<PFNGLTEXSUBIMAGE1DPROC>("glTexSubImage1D")) != nullptr;
    result = result && (glTexSubImage2D = get_function<PFNGLTEXSUBIMAGE2DPROC>("glTexSubImage2D")) != nullptr;
    result = result && (glBindTexture = get_function<PFNGLBINDTEXTUREPROC>("glBindTexture")) != nullptr;
    result = result && (glDeleteTextures = get_function<PFNGLDELETETEXTURESPROC>("glDeleteTextures")) != nullptr;
    result = result && (glGenTextures = get_function<PFNGLGENTEXTURESPROC>("glGenTextures")) != nullptr;
    result = result && (glIsTexture = get_function<PFNGLISTEXTUREPROC>("glIsTexture")) != nullptr;
    // clang-format on

    return result;
}

#endif // GL_VERSION_1_1

#pragma endregion

#pragma region GL_VERSION_1_2

#ifdef GL_VERSION_1_2

PFNGLDRAWRANGEELEMENTSPROC glDrawRangeElements = nullptr;
PFNGLTEXIMAGE3DPROC glTexImage3D               = nullptr;
PFNGLTEXSUBIMAGE3DPROC glTexSubImage3D         = nullptr;
PFNGLCOPYTEXSUBIMAGE3DPROC glCopyTexSubImage3D = nullptr;

bool init_gl_version_1_2()
{
    bool result = true;

    // clang-format off
    result = result && (glDrawRangeElements = get_function<PFNGLDRAWRANGEELEMENTSPROC>("glDrawRangeElements")) != nullptr;
    result = result && (glTexImage3D = get_function<PFNGLTEXIMAGE3DPROC>("glTexImage3D")) != nullptr;
    result = result && (glTexSubImage3D = get_function<PFNGLTEXSUBIMAGE3DPROC>("glTexSubImage3D")) != nullptr;
    result = result && (glCopyTexSubImage3D = get_function<PFNGLCOPYTEXSUBIMAGE3DPROC>("glCopyTexSubImage3D")) != nullptr;
    // clang-format on

    return result;
}

#endif // GL_VERSION_1_2

#pragma endregion

#pragma region GL_VERSION_1_3

#ifdef GL_VERSION_1_3

PFNGLACTIVETEXTUREPROC glActiveTexture                     = nullptr;
PFNGLSAMPLECOVERAGEPROC glSampleCoverage                   = nullptr;
PFNGLCOMPRESSEDTEXIMAGE3DPROC glCompressedTexImage3D       = nullptr;
PFNGLCOMPRESSEDTEXIMAGE2DPROC glCompressedTexImage2D       = nullptr;
PFNGLCOMPRESSEDTEXIMAGE1DPROC glCompressedTexImage1D       = nullptr;
PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glCompressedTexSubImage3D = nullptr;
PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glCompressedTexSubImage2D = nullptr;
PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC glCompressedTexSubImage1D = nullptr;
PFNGLGETCOMPRESSEDTEXIMAGEPROC glGetCompressedTexImage     = nullptr;

bool init_gl_version_1_3()
{
    bool result = true;

    // clang-format off
    result = result && (glActiveTexture = get_function<PFNGLACTIVETEXTUREPROC>("glActiveTexture")) != nullptr;
    result = result && (glSampleCoverage = get_function<PFNGLSAMPLECOVERAGEPROC>("glSampleCoverage")) != nullptr;
    result = result && (glCompressedTexImage3D = get_function<PFNGLCOMPRESSEDTEXIMAGE3DPROC>("glCompressedTexImage3D")) != nullptr;
    result = result && (glCompressedTexImage2D = get_function<PFNGLCOMPRESSEDTEXIMAGE2DPROC>("glCompressedTexImage2D")) != nullptr;
    result = result && (glCompressedTexImage1D = get_function<PFNGLCOMPRESSEDTEXIMAGE1DPROC>("glCompressedTexImage1D")) != nullptr;
    result = result && (glCompressedTexSubImage3D = get_function<PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC>("glCompressedTexSubImage3D")) != nullptr;
    result = result && (glCompressedTexSubImage2D = get_function<PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC>("glCompressedTexSubImage2D")) != nullptr;
    result = result && (glCompressedTexSubImage1D = get_function<PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC>("glCompressedTexSubImage1D")) != nullptr;
    result = result && (glGetCompressedTexImage = get_function<PFNGLGETCOMPRESSEDTEXIMAGEPROC>("glGetCompressedTexImage")) != nullptr;
    // clang-format on

    return result;
}

#endif // GL_VERSION_1_3

#pragma endregion

#pragma region GL_VERSION_1_4

#ifdef GL_VERSION_1_4

PFNGLBLENDFUNCSEPARATEPROC glBlendFuncSeparate = nullptr;
PFNGLMULTIDRAWARRAYSPROC glMultiDrawArrays     = nullptr;
PFNGLMULTIDRAWELEMENTSPROC glMultiDrawElements = nullptr;
PFNGLPOINTPARAMETERFPROC glPointParameterf     = nullptr;
PFNGLPOINTPARAMETERFVPROC glPointParameterfv   = nullptr;
PFNGLPOINTPARAMETERIPROC glPointParameteri     = nullptr;
PFNGLPOINTPARAMETERIVPROC glPointParameteriv   = nullptr;
PFNGLBLENDCOLORPROC glBlendColor               = nullptr;
PFNGLBLENDEQUATIONPROC glBlendEquation         = nullptr;

bool init_gl_version_1_4()
{
    bool result = true;

    // clang-format off
    result = result && (glBlendFuncSeparate = get_function<PFNGLBLENDFUNCSEPARATEPROC>("glBlendFuncSeparate")) != nullptr;
    result = result && (glMultiDrawArrays = get_function<PFNGLMULTIDRAWARRAYSPROC>("glMultiDrawArrays")) != nullptr;
    result = result && (glMultiDrawElements = get_function<PFNGLMULTIDRAWELEMENTSPROC>("glMultiDrawElements")) != nullptr;
    result = result && (glPointParameterf = get_function<PFNGLPOINTPARAMETERFPROC>("glPointParameterf")) != nullptr;
    result = result && (glPointParameterfv = get_function<PFNGLPOINTPARAMETERFVPROC>("glPointParameterfv")) != nullptr;
    result = result && (glPointParameteri = get_function<PFNGLPOINTPARAMETERIPROC>("glPointParameteri")) != nullptr;
    result = result && (glPointParameteriv = get_function<PFNGLPOINTPARAMETERIVPROC>("glPointParameteriv")) != nullptr;
    result = result && (glBlendColor = get_function<PFNGLBLENDCOLORPROC>("glBlendColor")) != nullptr;
    result = result && (glBlendEquation = get_function<PFNGLBLENDEQUATIONPROC>("glBlendEquation")) != nullptr;
    // clang-format on

    return result;
}

#endif // GL_VERSION_1_4

#pragma endregion

#pragma region GL_VERSION_1_5

#ifdef GL_VERSION_1_5

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

bool init_gl_version_1_5()
{
    bool result = true;

    // clang-format off
    result = result && (glGenQueries = get_function<PFNGLGENQUERIESPROC>("glGenQueries")) != nullptr;
    result = result && (glDeleteQueries = get_function<PFNGLDELETEQUERIESPROC>("glDeleteQueries")) != nullptr;
    result = result && (glIsQuery = get_function<PFNGLISQUERYPROC>("glIsQuery")) != nullptr;
    result = result && (glBeginQuery = get_function<PFNGLBEGINQUERYPROC>("glBeginQuery")) != nullptr;
    result = result && (glEndQuery = get_function<PFNGLENDQUERYPROC>("glEndQuery")) != nullptr;
    result = result && (glGetQueryiv = get_function<PFNGLGETQUERYIVPROC>("glGetQueryiv")) != nullptr;
    result = result && (glGetQueryObjectiv = get_function<PFNGLGETQUERYOBJECTIVPROC>("glGetQueryObjectiv")) != nullptr;
    result = result && (glGetQueryObjectuiv = get_function<PFNGLGETQUERYOBJECTUIVPROC>("glGetQueryObjectuiv")) != nullptr;
    result = result && (glBindBuffer = get_function<PFNGLBINDBUFFERPROC>("glBindBuffer")) != nullptr;
    result = result && (glDeleteBuffers = get_function<PFNGLDELETEBUFFERSPROC>("glDeleteBuffers")) != nullptr;
    result = result && (glGenBuffers = get_function<PFNGLGENBUFFERSPROC>("glGenBuffers")) != nullptr;
    result = result && (glIsBuffer = get_function<PFNGLISBUFFERPROC>("glIsBuffer")) != nullptr;
    result = result && (glBufferData = get_function<PFNGLBUFFERDATAPROC>("glBufferData")) != nullptr;
    result = result && (glBufferSubData = get_function<PFNGLBUFFERSUBDATAPROC>("glBufferSubData")) != nullptr;
    result = result && (glGetBufferSubData = get_function<PFNGLGETBUFFERSUBDATAPROC>("glGetBufferSubData")) != nullptr;
    result = result && (glMapBuffer = get_function<PFNGLMAPBUFFERPROC>("glMapBuffer")) != nullptr;
    result = result && (glUnmapBuffer = get_function<PFNGLUNMAPBUFFERPROC>("glUnmapBuffer")) != nullptr;
    result = result && (glGetBufferParameteriv = get_function<PFNGLGETBUFFERPARAMETERIVPROC>("glGetBufferParameteriv")) != nullptr;
    result = result && (glGetBufferPointerv = get_function<PFNGLGETBUFFERPOINTERVPROC>("glGetBufferPointerv")) != nullptr;
    // clang-format on

    return result;
}

#endif // GL_VERSION_1_5

#pragma endregion

#pragma region GL_VERSION_2_0

#ifdef GL_VERSION_2_0

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

bool init_gl_version_2_0()
{
    bool result = true;

    // clang-format off
    result = result && (glBlendEquationSeparate = get_function<PFNGLBLENDEQUATIONSEPARATEPROC>("glBlendEquationSeparate")) != nullptr;
    result = result && (glDrawBuffers = get_function<PFNGLDRAWBUFFERSPROC>("glDrawBuffers")) != nullptr;
    result = result && (glStencilOpSeparate = get_function<PFNGLSTENCILOPSEPARATEPROC>("glStencilOpSeparate")) != nullptr;
    result = result && (glStencilFuncSeparate = get_function<PFNGLSTENCILFUNCSEPARATEPROC>("glStencilFuncSeparate")) != nullptr;
    result = result && (glStencilMaskSeparate = get_function<PFNGLSTENCILMASKSEPARATEPROC>("glStencilMaskSeparate")) != nullptr;
    result = result && (glAttachShader = get_function<PFNGLATTACHSHADERPROC>("glAttachShader")) != nullptr;
    result = result && (glBindAttribLocation = get_function<PFNGLBINDATTRIBLOCATIONPROC>("glBindAttribLocation")) != nullptr;
    result = result && (glCompileShader = get_function<PFNGLCOMPILESHADERPROC>("glCompileShader")) != nullptr;
    result = result && (glCreateProgram = get_function<PFNGLCREATEPROGRAMPROC>("glCreateProgram")) != nullptr;
    result = result && (glCreateShader = get_function<PFNGLCREATESHADERPROC>("glCreateShader")) != nullptr;
    result = result && (glDeleteProgram = get_function<PFNGLDELETEPROGRAMPROC>("glDeleteProgram")) != nullptr;
    result = result && (glDeleteShader = get_function<PFNGLDELETESHADERPROC>("glDeleteShader")) != nullptr;
    result = result && (glDetachShader = get_function<PFNGLDETACHSHADERPROC>("glDetachShader")) != nullptr;
    result = result && (glDisableVertexAttribArray = get_function<PFNGLDISABLEVERTEXATTRIBARRAYPROC>("glDisableVertexAttribArray")) != nullptr;
    result = result && (glEnableVertexAttribArray = get_function<PFNGLENABLEVERTEXATTRIBARRAYPROC>("glEnableVertexAttribArray")) != nullptr;
    result = result && (glGetActiveAttrib = get_function<PFNGLGETACTIVEATTRIBPROC>("glGetActiveAttrib")) != nullptr;
    result = result && (glGetActiveUniform = get_function<PFNGLGETACTIVEUNIFORMPROC>("glGetActiveUniform")) != nullptr;
    result = result && (glGetAttachedShaders = get_function<PFNGLGETATTACHEDSHADERSPROC>("glGetAttachedShaders")) != nullptr;
    result = result && (glGetAttribLocation = get_function<PFNGLGETATTRIBLOCATIONPROC>("glGetAttribLocation")) != nullptr;
    result = result && (glGetProgramiv = get_function<PFNGLGETPROGRAMIVPROC>("glGetProgramiv")) != nullptr;
    result = result && (glGetProgramInfoLog = get_function<PFNGLGETPROGRAMINFOLOGPROC>("glGetProgramInfoLog")) != nullptr;
    result = result && (glGetShaderiv = get_function<PFNGLGETSHADERIVPROC>("glGetShaderiv")) != nullptr;
    result = result && (glGetShaderInfoLog = get_function<PFNGLGETSHADERINFOLOGPROC>("glGetShaderInfoLog")) != nullptr;
    result = result && (glGetShaderSource = get_function<PFNGLGETSHADERSOURCEPROC>("glGetShaderSource")) != nullptr;
    result = result && (glGetUniformLocation = get_function<PFNGLGETUNIFORMLOCATIONPROC>("glGetUniformLocation")) != nullptr;
    result = result && (glGetUniformfv = get_function<PFNGLGETUNIFORMFVPROC>("glGetUniformfv")) != nullptr;
    result = result && (glGetUniformiv = get_function<PFNGLGETUNIFORMIVPROC>("glGetUniformiv")) != nullptr;
    result = result && (glGetVertexAttribdv = get_function<PFNGLGETVERTEXATTRIBDVPROC>("glGetVertexAttribdv")) != nullptr;
    result = result && (glGetVertexAttribfv = get_function<PFNGLGETVERTEXATTRIBFVPROC>("glGetVertexAttribfv")) != nullptr;
    result = result && (glGetVertexAttribiv = get_function<PFNGLGETVERTEXATTRIBIVPROC>("glGetVertexAttribiv")) != nullptr;
    result = result && (glGetVertexAttribPointerv = get_function<PFNGLGETVERTEXATTRIBPOINTERVPROC>("glGetVertexAttribPointerv")) != nullptr;
    result = result && (glIsProgram = get_function<PFNGLISPROGRAMPROC>("glIsProgram")) != nullptr;
    result = result && (glIsShader = get_function<PFNGLISSHADERPROC>("glIsShader")) != nullptr;
    result = result && (glLinkProgram = get_function<PFNGLLINKPROGRAMPROC>("glLinkProgram")) != nullptr;
    result = result && (glShaderSource = get_function<PFNGLSHADERSOURCEPROC>("glShaderSource")) != nullptr;
    result = result && (glUseProgram = get_function<PFNGLUSEPROGRAMPROC>("glUseProgram")) != nullptr;
    result = result && (glUniform1f = get_function<PFNGLUNIFORM1FPROC>("glUniform1f")) != nullptr;
    result = result && (glUniform2f = get_function<PFNGLUNIFORM2FPROC>("glUniform2f")) != nullptr;
    result = result && (glUniform3f = get_function<PFNGLUNIFORM3FPROC>("glUniform3f")) != nullptr;
    result = result && (glUniform4f = get_function<PFNGLUNIFORM4FPROC>("glUniform4f")) != nullptr;
    result = result && (glUniform1i = get_function<PFNGLUNIFORM1IPROC>("glUniform1i")) != nullptr;
    result = result && (glUniform2i = get_function<PFNGLUNIFORM2IPROC>("glUniform2i")) != nullptr;
    result = result && (glUniform3i = get_function<PFNGLUNIFORM3IPROC>("glUniform3i")) != nullptr;
    result = result && (glUniform4i = get_function<PFNGLUNIFORM4IPROC>("glUniform4i")) != nullptr;
    result = result && (glUniform1fv = get_function<PFNGLUNIFORM1FVPROC>("glUniform1fv")) != nullptr;
    result = result && (glUniform2fv = get_function<PFNGLUNIFORM2FVPROC>("glUniform2fv")) != nullptr;
    result = result && (glUniform3fv = get_function<PFNGLUNIFORM3FVPROC>("glUniform3fv")) != nullptr;
    result = result && (glUniform4fv = get_function<PFNGLUNIFORM4FVPROC>("glUniform4fv")) != nullptr;
    result = result && (glUniform1iv = get_function<PFNGLUNIFORM1IVPROC>("glUniform1iv")) != nullptr;
    result = result && (glUniform2iv = get_function<PFNGLUNIFORM2IVPROC>("glUniform2iv")) != nullptr;
    result = result && (glUniform3iv = get_function<PFNGLUNIFORM3IVPROC>("glUniform3iv")) != nullptr;
    result = result && (glUniform4iv = get_function<PFNGLUNIFORM4IVPROC>("glUniform4iv")) != nullptr;
    result = result && (glUniformMatrix2fv = get_function<PFNGLUNIFORMMATRIX2FVPROC>("glUniformMatrix2fv")) != nullptr;
    result = result && (glUniformMatrix3fv = get_function<PFNGLUNIFORMMATRIX3FVPROC>("glUniformMatrix3fv")) != nullptr;
    result = result && (glUniformMatrix4fv = get_function<PFNGLUNIFORMMATRIX4FVPROC>("glUniformMatrix4fv")) != nullptr;
    result = result && (glValidateProgram = get_function<PFNGLVALIDATEPROGRAMPROC>("glValidateProgram")) != nullptr;
    result = result && (glVertexAttrib1d = get_function<PFNGLVERTEXATTRIB1DPROC>("glVertexAttrib1d")) != nullptr;
    result = result && (glVertexAttrib1dv = get_function<PFNGLVERTEXATTRIB1DVPROC>("glVertexAttrib1dv")) != nullptr;
    result = result && (glVertexAttrib1f = get_function<PFNGLVERTEXATTRIB1FPROC>("glVertexAttrib1f")) != nullptr;
    result = result && (glVertexAttrib1fv = get_function<PFNGLVERTEXATTRIB1FVPROC>("glVertexAttrib1fv")) != nullptr;
    result = result && (glVertexAttrib1s = get_function<PFNGLVERTEXATTRIB1SPROC>("glVertexAttrib1s")) != nullptr;
    result = result && (glVertexAttrib1sv = get_function<PFNGLVERTEXATTRIB1SVPROC>("glVertexAttrib1sv")) != nullptr;
    result = result && (glVertexAttrib2d = get_function<PFNGLVERTEXATTRIB2DPROC>("glVertexAttrib2d")) != nullptr;
    result = result && (glVertexAttrib2dv = get_function<PFNGLVERTEXATTRIB2DVPROC>("glVertexAttrib2dv")) != nullptr;
    result = result && (glVertexAttrib2f = get_function<PFNGLVERTEXATTRIB2FPROC>("glVertexAttrib2f")) != nullptr;
    result = result && (glVertexAttrib2fv = get_function<PFNGLVERTEXATTRIB2FVPROC>("glVertexAttrib2fv")) != nullptr;
    result = result && (glVertexAttrib2s = get_function<PFNGLVERTEXATTRIB2SPROC>("glVertexAttrib2s")) != nullptr;
    result = result && (glVertexAttrib2sv = get_function<PFNGLVERTEXATTRIB2SVPROC>("glVertexAttrib2sv")) != nullptr;
    result = result && (glVertexAttrib3d = get_function<PFNGLVERTEXATTRIB3DPROC>("glVertexAttrib3d")) != nullptr;
    result = result && (glVertexAttrib3dv = get_function<PFNGLVERTEXATTRIB3DVPROC>("glVertexAttrib3dv")) != nullptr;
    result = result && (glVertexAttrib3f = get_function<PFNGLVERTEXATTRIB3FPROC>("glVertexAttrib3f")) != nullptr;
    result = result && (glVertexAttrib3fv = get_function<PFNGLVERTEXATTRIB3FVPROC>("glVertexAttrib3fv")) != nullptr;
    result = result && (glVertexAttrib3s = get_function<PFNGLVERTEXATTRIB3SPROC>("glVertexAttrib3s")) != nullptr;
    result = result && (glVertexAttrib3sv = get_function<PFNGLVERTEXATTRIB3SVPROC>("glVertexAttrib3sv")) != nullptr;
    result = result && (glVertexAttrib4Nbv = get_function<PFNGLVERTEXATTRIB4NBVPROC>("glVertexAttrib4Nbv")) != nullptr;
    result = result && (glVertexAttrib4Niv = get_function<PFNGLVERTEXATTRIB4NIVPROC>("glVertexAttrib4Niv")) != nullptr;
    result = result && (glVertexAttrib4Nsv = get_function<PFNGLVERTEXATTRIB4NSVPROC>("glVertexAttrib4Nsv")) != nullptr;
    result = result && (glVertexAttrib4Nub = get_function<PFNGLVERTEXATTRIB4NUBPROC>("glVertexAttrib4Nub")) != nullptr;
    result = result && (glVertexAttrib4Nubv = get_function<PFNGLVERTEXATTRIB4NUBVPROC>("glVertexAttrib4Nubv")) != nullptr;
    result = result && (glVertexAttrib4Nuiv = get_function<PFNGLVERTEXATTRIB4NUIVPROC>("glVertexAttrib4Nuiv")) != nullptr;
    result = result && (glVertexAttrib4Nusv = get_function<PFNGLVERTEXATTRIB4NUSVPROC>("glVertexAttrib4Nusv")) != nullptr;
    result = result && (glVertexAttrib4bv = get_function<PFNGLVERTEXATTRIB4BVPROC>("glVertexAttrib4bv")) != nullptr;
    result = result && (glVertexAttrib4d = get_function<PFNGLVERTEXATTRIB4DPROC>("glVertexAttrib4d")) != nullptr;
    result = result && (glVertexAttrib4dv = get_function<PFNGLVERTEXATTRIB4DVPROC>("glVertexAttrib4dv")) != nullptr;
    result = result && (glVertexAttrib4f = get_function<PFNGLVERTEXATTRIB4FPROC>("glVertexAttrib4f")) != nullptr;
    result = result && (glVertexAttrib4fv = get_function<PFNGLVERTEXATTRIB4FVPROC>("glVertexAttrib4fv")) != nullptr;
    result = result && (glVertexAttrib4iv = get_function<PFNGLVERTEXATTRIB4IVPROC>("glVertexAttrib4iv")) != nullptr;
    result = result && (glVertexAttrib4s = get_function<PFNGLVERTEXATTRIB4SPROC>("glVertexAttrib4s")) != nullptr;
    result = result && (glVertexAttrib4sv = get_function<PFNGLVERTEXATTRIB4SVPROC>("glVertexAttrib4sv")) != nullptr;
    result = result && (glVertexAttrib4ubv = get_function<PFNGLVERTEXATTRIB4UBVPROC>("glVertexAttrib4ubv")) != nullptr;
    result = result && (glVertexAttrib4uiv = get_function<PFNGLVERTEXATTRIB4UIVPROC>("glVertexAttrib4uiv")) != nullptr;
    result = result && (glVertexAttrib4usv = get_function<PFNGLVERTEXATTRIB4USVPROC>("glVertexAttrib4usv")) != nullptr;
    result = result && (glVertexAttribPointer = get_function<PFNGLVERTEXATTRIBPOINTERPROC>("glVertexAttribPointer")) != nullptr;
    // clang-format on

    return result;
}

#endif // GL_VERSION_2_0

#pragma endregion

#pragma region GL_VERSION_2_1

#ifdef GL_VERSION_2_1

PFNGLUNIFORMMATRIX2X3FVPROC glUniformMatrix2x3fv = nullptr;
PFNGLUNIFORMMATRIX3X2FVPROC glUniformMatrix3x2fv = nullptr;
PFNGLUNIFORMMATRIX2X4FVPROC glUniformMatrix2x4fv = nullptr;
PFNGLUNIFORMMATRIX4X2FVPROC glUniformMatrix4x2fv = nullptr;
PFNGLUNIFORMMATRIX3X4FVPROC glUniformMatrix3x4fv = nullptr;
PFNGLUNIFORMMATRIX4X3FVPROC glUniformMatrix4x3fv = nullptr;

bool init_gl_version_2_1()
{
    bool result = true;

    // clanf-format off
    result = result &&
             (glUniformMatrix2x3fv = get_function<PFNGLUNIFORMMATRIX2X3FVPROC>("glUniformMatrix2x3fv")) != nullptr;
    result = result &&
             (glUniformMatrix3x2fv = get_function<PFNGLUNIFORMMATRIX3X2FVPROC>("glUniformMatrix3x2fv")) != nullptr;
    result = result &&
             (glUniformMatrix2x4fv = get_function<PFNGLUNIFORMMATRIX2X4FVPROC>("glUniformMatrix2x4fv")) != nullptr;
    result = result &&
             (glUniformMatrix4x2fv = get_function<PFNGLUNIFORMMATRIX4X2FVPROC>("glUniformMatrix4x2fv")) != nullptr;
    result = result &&
             (glUniformMatrix3x4fv = get_function<PFNGLUNIFORMMATRIX3X4FVPROC>("glUniformMatrix3x4fv")) != nullptr;
    result = result &&
             (glUniformMatrix4x3fv = get_function<PFNGLUNIFORMMATRIX4X3FVPROC>("glUniformMatrix4x3fv")) != nullptr;
    // clanf-format on

    return result;
}

#endif // GL_VERSION_2_1

#pragma endregion

#pragma region GL_VERSION_3_0

#ifdef GL_VERSION_3_0

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

bool init_gl_version_3_0()
{
    bool result = true;

    // clang-format off
    result = result && (glColorMaski = get_function<PFNGLCOLORMASKIPROC>("glColorMaski")) != nullptr;
    result = result && (glGetBooleani_v = get_function<PFNGLGETBOOLEANI_VPROC>("glGetBooleani_v")) != nullptr;
    result = result && (glGetIntegeri_v = get_function<PFNGLGETINTEGERI_VPROC>("glGetIntegeri_v")) != nullptr;
    result = result && (glEnablei = get_function<PFNGLENABLEIPROC>("glEnablei")) != nullptr;
    result = result && (glDisablei = get_function<PFNGLDISABLEIPROC>("glDisablei")) != nullptr;
    result = result && (glIsEnabledi = get_function<PFNGLISENABLEDIPROC>("glIsEnabledi")) != nullptr;
    result = result && (glBeginTransformFeedback = get_function<PFNGLBEGINTRANSFORMFEEDBACKPROC>("glBeginTransformFeedback")) != nullptr;
    result = result && (glEndTransformFeedback = get_function<PFNGLENDTRANSFORMFEEDBACKPROC>("glEndTransformFeedback")) != nullptr;
    result = result && (glBindBufferRange = get_function<PFNGLBINDBUFFERRANGEPROC>("glBindBufferRange")) != nullptr;
    result = result && (glBindBufferBase = get_function<PFNGLBINDBUFFERBASEPROC>("glBindBufferBase")) != nullptr;
    result = result && (glTransformFeedbackVaryings = get_function<PFNGLTRANSFORMFEEDBACKVARYINGSPROC>("glTransformFeedbackVaryings")) != nullptr;
    result = result && (glGetTransformFeedbackVarying = get_function<PFNGLGETTRANSFORMFEEDBACKVARYINGPROC>("glGetTransformFeedbackVarying")) != nullptr;
    result = result && (glClampColor = get_function<PFNGLCLAMPCOLORPROC>("glClampColor")) != nullptr;
    result = result && (glBeginConditionalRender = get_function<PFNGLBEGINCONDITIONALRENDERPROC>("glBeginConditionalRender")) != nullptr;
    result = result && (glEndConditionalRender = get_function<PFNGLENDCONDITIONALRENDERPROC>("glEndConditionalRender")) != nullptr;
    result = result && (glVertexAttribIPointer = get_function<PFNGLVERTEXATTRIBIPOINTERPROC>("glVertexAttribIPointer")) != nullptr;
    result = result && (glGetVertexAttribIiv = get_function<PFNGLGETVERTEXATTRIBIIVPROC>("glGetVertexAttribIiv")) != nullptr;
    result = result && (glGetVertexAttribIuiv = get_function<PFNGLGETVERTEXATTRIBIUIVPROC>("glGetVertexAttribIuiv")) != nullptr;
    result = result && (glVertexAttribI1i = get_function<PFNGLVERTEXATTRIBI1IPROC>("glVertexAttribI1i")) != nullptr;
    result = result && (glVertexAttribI2i = get_function<PFNGLVERTEXATTRIBI2IPROC>("glVertexAttribI2i")) != nullptr;
    result = result && (glVertexAttribI3i = get_function<PFNGLVERTEXATTRIBI3IPROC>("glVertexAttribI3i")) != nullptr;
    result = result && (glVertexAttribI4i = get_function<PFNGLVERTEXATTRIBI4IPROC>("glVertexAttribI4i")) != nullptr;
    result = result && (glVertexAttribI1ui = get_function<PFNGLVERTEXATTRIBI1UIPROC>("glVertexAttribI1ui")) != nullptr;
    result = result && (glVertexAttribI2ui = get_function<PFNGLVERTEXATTRIBI2UIPROC>("glVertexAttribI2ui")) != nullptr;
    result = result && (glVertexAttribI3ui = get_function<PFNGLVERTEXATTRIBI3UIPROC>("glVertexAttribI3ui")) != nullptr;
    result = result && (glVertexAttribI4ui = get_function<PFNGLVERTEXATTRIBI4UIPROC>("glVertexAttribI4ui")) != nullptr;
    result = result && (glVertexAttribI1iv = get_function<PFNGLVERTEXATTRIBI1IVPROC>("glVertexAttribI1iv")) != nullptr;
    result = result && (glVertexAttribI2iv = get_function<PFNGLVERTEXATTRIBI2IVPROC>("glVertexAttribI2iv")) != nullptr;
    result = result && (glVertexAttribI3iv = get_function<PFNGLVERTEXATTRIBI3IVPROC>("glVertexAttribI3iv")) != nullptr;
    result = result && (glVertexAttribI4iv = get_function<PFNGLVERTEXATTRIBI4IVPROC>("glVertexAttribI4iv")) != nullptr;
    result = result && (glVertexAttribI1uiv = get_function<PFNGLVERTEXATTRIBI1UIVPROC>("glVertexAttribI1uiv")) != nullptr;
    result = result && (glVertexAttribI2uiv = get_function<PFNGLVERTEXATTRIBI2UIVPROC>("glVertexAttribI2uiv")) != nullptr;
    result = result && (glVertexAttribI3uiv = get_function<PFNGLVERTEXATTRIBI3UIVPROC>("glVertexAttribI3uiv")) != nullptr;
    result = result && (glVertexAttribI4uiv = get_function<PFNGLVERTEXATTRIBI4UIVPROC>("glVertexAttribI4uiv")) != nullptr;
    result = result && (glVertexAttribI4bv = get_function<PFNGLVERTEXATTRIBI4BVPROC>("glVertexAttribI4bv")) != nullptr;
    result = result && (glVertexAttribI4sv = get_function<PFNGLVERTEXATTRIBI4SVPROC>("glVertexAttribI4sv")) != nullptr;
    result = result && (glVertexAttribI4ubv = get_function<PFNGLVERTEXATTRIBI4UBVPROC>("glVertexAttribI4ubv")) != nullptr;
    result = result && (glVertexAttribI4usv = get_function<PFNGLVERTEXATTRIBI4USVPROC>("glVertexAttribI4usv")) != nullptr;
    result = result && (glGetUniformuiv = get_function<PFNGLGETUNIFORMUIVPROC>("glGetUniformuiv")) != nullptr;
    result = result && (glBindFragDataLocation = get_function<PFNGLBINDFRAGDATALOCATIONPROC>("glBindFragDataLocation")) != nullptr;
    result = result && (glGetFragDataLocation = get_function<PFNGLGETFRAGDATALOCATIONPROC>("glGetFragDataLocation")) != nullptr;
    result = result && (glUniform1ui = get_function<PFNGLUNIFORM1UIPROC>("glUniform1ui")) != nullptr;
    result = result && (glUniform2ui = get_function<PFNGLUNIFORM2UIPROC>("glUniform2ui")) != nullptr;
    result = result && (glUniform3ui = get_function<PFNGLUNIFORM3UIPROC>("glUniform3ui")) != nullptr;
    result = result && (glUniform4ui = get_function<PFNGLUNIFORM4UIPROC>("glUniform4ui")) != nullptr;
    result = result && (glUniform1uiv = get_function<PFNGLUNIFORM1UIVPROC>("glUniform1uiv")) != nullptr;
    result = result && (glUniform2uiv = get_function<PFNGLUNIFORM2UIVPROC>("glUniform2uiv")) != nullptr;
    result = result && (glUniform3uiv = get_function<PFNGLUNIFORM3UIVPROC>("glUniform3uiv")) != nullptr;
    result = result && (glUniform4uiv = get_function<PFNGLUNIFORM4UIVPROC>("glUniform4uiv")) != nullptr;
    result = result && (glTexParameterIiv = get_function<PFNGLTEXPARAMETERIIVPROC>("glTexParameterIiv")) != nullptr;
    result = result && (glTexParameterIuiv = get_function<PFNGLTEXPARAMETERIUIVPROC>("glTexParameterIuiv")) != nullptr;
    result = result && (glGetTexParameterIiv = get_function<PFNGLGETTEXPARAMETERIIVPROC>("glGetTexParameterIiv")) != nullptr;
    result = result && (glGetTexParameterIuiv = get_function<PFNGLGETTEXPARAMETERIUIVPROC>("glGetTexParameterIuiv")) != nullptr;
    result = result && (glClearBufferiv = get_function<PFNGLCLEARBUFFERIVPROC>("glClearBufferiv")) != nullptr;
    result = result && (glClearBufferuiv = get_function<PFNGLCLEARBUFFERUIVPROC>("glClearBufferuiv")) != nullptr;
    result = result && (glClearBufferfv = get_function<PFNGLCLEARBUFFERFVPROC>("glClearBufferfv")) != nullptr;
    result = result && (glClearBufferfi = get_function<PFNGLCLEARBUFFERFIPROC>("glClearBufferfi")) != nullptr;
    result = result && (glGetStringi = get_function<PFNGLGETSTRINGIPROC>("glGetStringi")) != nullptr;
    result = result && (glIsRenderbuffer = get_function<PFNGLISRENDERBUFFERPROC>("glIsRenderbuffer")) != nullptr;
    result = result && (glBindRenderbuffer = get_function<PFNGLBINDRENDERBUFFERPROC>("glBindRenderbuffer")) != nullptr;
    result = result && (glDeleteRenderbuffers = get_function<PFNGLDELETERENDERBUFFERSPROC>("glDeleteRenderbuffers")) != nullptr;
    result = result && (glGenRenderbuffers = get_function<PFNGLGENRENDERBUFFERSPROC>("glGenRenderbuffers")) != nullptr;
    result = result && (glRenderbufferStorage = get_function<PFNGLRENDERBUFFERSTORAGEPROC>("glRenderbufferStorage")) != nullptr;
    result = result && (glGetRenderbufferParameteriv = get_function<PFNGLGETRENDERBUFFERPARAMETERIVPROC>("glGetRenderbufferParameteriv")) != nullptr;
    result = result && (glIsFramebuffer = get_function<PFNGLISFRAMEBUFFERPROC>("glIsFramebuffer")) != nullptr;
    result = result && (glBindFramebuffer = get_function<PFNGLBINDFRAMEBUFFERPROC>("glBindFramebuffer")) != nullptr;
    result = result && (glDeleteFramebuffers = get_function<PFNGLDELETEFRAMEBUFFERSPROC>("glDeleteFramebuffers")) != nullptr;
    result = result && (glGenFramebuffers = get_function<PFNGLGENFRAMEBUFFERSPROC>("glGenFramebuffers")) != nullptr;
    result = result && (glCheckFramebufferStatus = get_function<PFNGLCHECKFRAMEBUFFERSTATUSPROC>("glCheckFramebufferStatus")) != nullptr;
    result = result && (glFramebufferTexture1D = get_function<PFNGLFRAMEBUFFERTEXTURE1DPROC>("glFramebufferTexture1D")) != nullptr;
    result = result && (glFramebufferTexture2D = get_function<PFNGLFRAMEBUFFERTEXTURE2DPROC>("glFramebufferTexture2D")) != nullptr;
    result = result && (glFramebufferTexture3D = get_function<PFNGLFRAMEBUFFERTEXTURE3DPROC>("glFramebufferTexture3D")) != nullptr;
    result = result && (glFramebufferRenderbuffer = get_function<PFNGLFRAMEBUFFERRENDERBUFFERPROC>("glFramebufferRenderbuffer")) != nullptr;
    result = result && (glGetFramebufferAttachmentParameteriv = get_function<PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC>("glGetFramebufferAttachmentParameteriv")) != nullptr;
    result = result && (glGenerateMipmap = get_function<PFNGLGENERATEMIPMAPPROC>("glGenerateMipmap")) != nullptr;
    result = result && (glBlitFramebuffer = get_function<PFNGLBLITFRAMEBUFFERPROC>("glBlitFramebuffer")) != nullptr;
    result = result && (glRenderbufferStorageMultisample = get_function<PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC>("glRenderbufferStorageMultisample")) != nullptr;
    result = result && (glFramebufferTextureLayer = get_function<PFNGLFRAMEBUFFERTEXTURELAYERPROC>("glFramebufferTextureLayer")) != nullptr;
    result = result && (glMapBufferRange = get_function<PFNGLMAPBUFFERRANGEPROC>("glMapBufferRange")) != nullptr;
    result = result && (glFlushMappedBufferRange = get_function<PFNGLFLUSHMAPPEDBUFFERRANGEPROC>("glFlushMappedBufferRange")) != nullptr;
    result = result && (glBindVertexArray = get_function<PFNGLBINDVERTEXARRAYPROC>("glBindVertexArray")) != nullptr;
    result = result && (glDeleteVertexArrays = get_function<PFNGLDELETEVERTEXARRAYSPROC>("glDeleteVertexArrays")) != nullptr;
    result = result && (glGenVertexArrays = get_function<PFNGLGENVERTEXARRAYSPROC>("glGenVertexArrays")) != nullptr;
    result = result && (glIsVertexArray = get_function<PFNGLISVERTEXARRAYPROC>("glIsVertexArray")) != nullptr;
    // clang-format on

    return result;
}

#endif // GL_VERSION_3_0

#pragma endregion

#pragma region GL_VERSION_3_1

#ifdef GL_VERSION_3_1

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

bool init_gl_version_3_1()
{
    bool result = true;

    // clang-format off
    result = result && (glDrawArraysInstanced = get_function<PFNGLDRAWARRAYSINSTANCEDPROC>("glDrawArraysInstanced")) != nullptr;
    result = result && (glDrawElementsInstanced = get_function<PFNGLDRAWELEMENTSINSTANCEDPROC>("glDrawElementsInstanced")) != nullptr;
    result = result && (glTexBuffer = get_function<PFNGLTEXBUFFERPROC>("glTexBuffer")) != nullptr;
    result = result && (glPrimitiveRestartIndex = get_function<PFNGLPRIMITIVERESTARTINDEXPROC>("glPrimitiveRestartIndex")) != nullptr;
    result = result && (glCopyBufferSubData = get_function<PFNGLCOPYBUFFERSUBDATAPROC>("glCopyBufferSubData")) != nullptr;
    result = result && (glGetUniformIndices = get_function<PFNGLGETUNIFORMINDICESPROC>("glGetUniformIndices")) != nullptr;
    result = result && (glGetActiveUniformsiv = get_function<PFNGLGETACTIVEUNIFORMSIVPROC>("glGetActiveUniformsiv")) != nullptr;
    result = result && (glGetActiveUniformName = get_function<PFNGLGETACTIVEUNIFORMNAMEPROC>("glGetActiveUniformName")) != nullptr;
    result = result && (glGetUniformBlockIndex = get_function<PFNGLGETUNIFORMBLOCKINDEXPROC>("glGetUniformBlockIndex")) != nullptr;
    result = result && (glGetActiveUniformBlockiv = get_function<PFNGLGETACTIVEUNIFORMBLOCKIVPROC>("glGetActiveUniformBlockiv")) != nullptr;
    result = result && (glGetActiveUniformBlockName = get_function<PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC>("glGetActiveUniformBlockName")) != nullptr;
    result = result && (glUniformBlockBinding = get_function<PFNGLUNIFORMBLOCKBINDINGPROC>("glUniformBlockBinding")) != nullptr;
    // clang-format on

    return result;
}

#endif // GL_VERSION_3_1

#pragma endregion

#pragma region GL_VERSION_3_2

#ifdef GL_VERSION_3_2

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

bool init_gl_version_3_2()
{
    bool result = true;

    // clang-format off
    result = result && (glDrawElementsBaseVertex = get_function<PFNGLDRAWELEMENTSBASEVERTEXPROC>("glDrawElementsBaseVertex")) != nullptr;
    result = result && (glDrawRangeElementsBaseVertex = get_function<PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC>("glDrawRangeElementsBaseVertex")) != nullptr;
    result = result && (glDrawElementsInstancedBaseVertex = get_function<PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC>("glDrawElementsInstancedBaseVertex")) != nullptr;
    result = result && (glMultiDrawElementsBaseVertex = get_function<PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC>("glMultiDrawElementsBaseVertex")) != nullptr;
    result = result && (glProvokingVertex = get_function<PFNGLPROVOKINGVERTEXPROC>("glProvokingVertex")) != nullptr;
    result = result && (glFenceSync = get_function<PFNGLFENCESYNCPROC>("glFenceSync")) != nullptr;
    result = result && (glIsSync = get_function<PFNGLISSYNCPROC>("glIsSync")) != nullptr;
    result = result && (glDeleteSync = get_function<PFNGLDELETESYNCPROC>("glDeleteSync")) != nullptr;
    result = result && (glClientWaitSync = get_function<PFNGLCLIENTWAITSYNCPROC>("glClientWaitSync")) != nullptr;
    result = result && (glWaitSync = get_function<PFNGLWAITSYNCPROC>("glWaitSync")) != nullptr;
    result = result && (glGetInteger64v = get_function<PFNGLGETINTEGER64VPROC>("glGetInteger64v")) != nullptr;
    result = result && (glGetSynciv = get_function<PFNGLGETSYNCIVPROC>("glGetSynciv")) != nullptr;
    result = result && (glGetInteger64i_v = get_function<PFNGLGETINTEGER64I_VPROC>("glGetInteger64i_v")) != nullptr;
    result = result && (glGetBufferParameteri64v = get_function<PFNGLGETBUFFERPARAMETERI64VPROC>("glGetBufferParameteri64v")) != nullptr;
    result = result && (glFramebufferTexture = get_function<PFNGLFRAMEBUFFERTEXTUREPROC>("glFramebufferTexture")) != nullptr;
    result = result && (glTexImage2DMultisample = get_function<PFNGLTEXIMAGE2DMULTISAMPLEPROC>("glTexImage2DMultisample")) != nullptr;
    result = result && (glTexImage3DMultisample = get_function<PFNGLTEXIMAGE3DMULTISAMPLEPROC>("glTexImage3DMultisample")) != nullptr;
    result = result && (glGetMultisamplefv = get_function<PFNGLGETMULTISAMPLEFVPROC>("glGetMultisamplefv")) != nullptr;
    result = result && (glSampleMaski = get_function<PFNGLSAMPLEMASKIPROC>("glSampleMaski")) != nullptr;
    // clang-format on

    return result;
}

#endif // GL_VERSION_3_2

#pragma endregion

#pragma region GL_VERSION_3_3

#ifdef GL_VERSION_3_3

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

bool init_gl_version_3_3()
{
    bool result = true;

    // clang-format off
    result = result && (glBindFragDataLocationIndexed = get_function<PFNGLBINDFRAGDATALOCATIONINDEXEDPROC>("glBindFragDataLocationIndexed")) != nullptr;
    result = result && (glGetFragDataIndex = get_function<PFNGLGETFRAGDATAINDEXPROC>("glGetFragDataIndex")) != nullptr;
    result = result && (glGenSamplers = get_function<PFNGLGENSAMPLERSPROC>("glGenSamplers")) != nullptr;
    result = result && (glDeleteSamplers = get_function<PFNGLDELETESAMPLERSPROC>("glDeleteSamplers")) != nullptr;
    result = result && (glIsSampler = get_function<PFNGLISSAMPLERPROC>("glIsSampler")) != nullptr;
    result = result && (glBindSampler = get_function<PFNGLBINDSAMPLERPROC>("glBindSampler")) != nullptr;
    result = result && (glSamplerParameteri = get_function<PFNGLSAMPLERPARAMETERIPROC>("glSamplerParameteri")) != nullptr;
    result = result && (glSamplerParameteriv = get_function<PFNGLSAMPLERPARAMETERIVPROC>("glSamplerParameteriv")) != nullptr;
    result = result && (glSamplerParameterf = get_function<PFNGLSAMPLERPARAMETERFPROC>("glSamplerParameterf")) != nullptr;
    result = result && (glSamplerParameterfv = get_function<PFNGLSAMPLERPARAMETERFVPROC>("glSamplerParameterfv")) != nullptr;
    result = result && (glSamplerParameterIiv = get_function<PFNGLSAMPLERPARAMETERIIVPROC>("glSamplerParameterIiv")) != nullptr;
    result = result && (glSamplerParameterIuiv = get_function<PFNGLSAMPLERPARAMETERIUIVPROC>("glSamplerParameterIuiv")) != nullptr;
    result = result && (glGetSamplerParameteriv = get_function<PFNGLGETSAMPLERPARAMETERIVPROC>("glGetSamplerParameteriv")) != nullptr;
    result = result && (glGetSamplerParameterIiv = get_function<PFNGLGETSAMPLERPARAMETERIIVPROC>("glGetSamplerParameterIiv")) != nullptr;
    result = result && (glGetSamplerParameterfv = get_function<PFNGLGETSAMPLERPARAMETERFVPROC>("glGetSamplerParameterfv")) != nullptr;
    result = result && (glGetSamplerParameterIuiv = get_function<PFNGLGETSAMPLERPARAMETERIUIVPROC>("glGetSamplerParameterIuiv")) != nullptr;
    result = result && (glQueryCounter = get_function<PFNGLQUERYCOUNTERPROC>("glQueryCounter")) != nullptr;
    result = result && (glGetQueryObjecti64v = get_function<PFNGLGETQUERYOBJECTI64VPROC>("glGetQueryObjecti64v")) != nullptr;
    result = result && (glGetQueryObjectui64v = get_function<PFNGLGETQUERYOBJECTUI64VPROC>("glGetQueryObjectui64v")) != nullptr;
    result = result && (glVertexAttribDivisor = get_function<PFNGLVERTEXATTRIBDIVISORPROC>("glVertexAttribDivisor")) != nullptr;
    result = result && (glVertexAttribP1ui = get_function<PFNGLVERTEXATTRIBP1UIPROC>("glVertexAttribP1ui")) != nullptr;
    result = result && (glVertexAttribP1uiv = get_function<PFNGLVERTEXATTRIBP1UIVPROC>("glVertexAttribP1uiv")) != nullptr;
    result = result && (glVertexAttribP2ui = get_function<PFNGLVERTEXATTRIBP2UIPROC>("glVertexAttribP2ui")) != nullptr;
    result = result && (glVertexAttribP2uiv = get_function<PFNGLVERTEXATTRIBP2UIVPROC>("glVertexAttribP2uiv")) != nullptr;
    result = result && (glVertexAttribP3ui = get_function<PFNGLVERTEXATTRIBP3UIPROC>("glVertexAttribP3ui")) != nullptr;
    result = result && (glVertexAttribP3uiv = get_function<PFNGLVERTEXATTRIBP3UIVPROC>("glVertexAttribP3uiv")) != nullptr;
    result = result && (glVertexAttribP4ui = get_function<PFNGLVERTEXATTRIBP4UIPROC>("glVertexAttribP4ui")) != nullptr;
    result = result && (glVertexAttribP4uiv = get_function<PFNGLVERTEXATTRIBP4UIVPROC>("glVertexAttribP4uiv")) != nullptr;
    // clang-format on

    return result;
}

#endif // GL_VERSION_3_3

#pragma endregion

#pragma region GL_VERSION_4_0

#ifdef GL_VERSION_4_0

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

bool init_gl_version_4_0()
{
    bool result = true;

    // clang-format off
    result = result && (glMinSampleShading = get_function<PFNGLMINSAMPLESHADINGPROC>("glMinSampleShading")) != nullptr;
    result = result && (glBlendEquationi = get_function<PFNGLBLENDEQUATIONIPROC>("glBlendEquationi")) != nullptr;
    result = result && (glBlendEquationSeparatei = get_function<PFNGLBLENDEQUATIONSEPARATEIPROC>("glBlendEquationSeparatei")) != nullptr;
    result = result && (glBlendFunci = get_function<PFNGLBLENDFUNCIPROC>("glBlendFunci")) != nullptr;
    result = result && (glBlendFuncSeparatei = get_function<PFNGLBLENDFUNCSEPARATEIPROC>("glBlendFuncSeparatei")) != nullptr;
    result = result && (glDrawArraysIndirect = get_function<PFNGLDRAWARRAYSINDIRECTPROC>("glDrawArraysIndirect")) != nullptr;
    result = result && (glDrawElementsIndirect = get_function<PFNGLDRAWELEMENTSINDIRECTPROC>("glDrawElementsIndirect")) != nullptr;
    result = result && (glUniform1d = get_function<PFNGLUNIFORM1DPROC>("glUniform1d")) != nullptr;
    result = result && (glUniform2d = get_function<PFNGLUNIFORM2DPROC>("glUniform2d")) != nullptr;
    result = result && (glUniform3d = get_function<PFNGLUNIFORM3DPROC>("glUniform3d")) != nullptr;
    result = result && (glUniform4d = get_function<PFNGLUNIFORM4DPROC>("glUniform4d")) != nullptr;
    result = result && (glUniform1dv = get_function<PFNGLUNIFORM1DVPROC>("glUniform1dv")) != nullptr;
    result = result && (glUniform2dv = get_function<PFNGLUNIFORM2DVPROC>("glUniform2dv")) != nullptr;
    result = result && (glUniform3dv = get_function<PFNGLUNIFORM3DVPROC>("glUniform3dv")) != nullptr;
    result = result && (glUniform4dv = get_function<PFNGLUNIFORM4DVPROC>("glUniform4dv")) != nullptr;
    result = result && (glUniformMatrix2dv = get_function<PFNGLUNIFORMMATRIX2DVPROC>("glUniformMatrix2dv")) != nullptr;
    result = result && (glUniformMatrix3dv = get_function<PFNGLUNIFORMMATRIX3DVPROC>("glUniformMatrix3dv")) != nullptr;
    result = result && (glUniformMatrix4dv = get_function<PFNGLUNIFORMMATRIX4DVPROC>("glUniformMatrix4dv")) != nullptr;
    result = result && (glUniformMatrix2x3dv = get_function<PFNGLUNIFORMMATRIX2X3DVPROC>("glUniformMatrix2x3dv")) != nullptr;
    result = result && (glUniformMatrix2x4dv = get_function<PFNGLUNIFORMMATRIX2X4DVPROC>("glUniformMatrix2x4dv")) != nullptr;
    result = result && (glUniformMatrix3x2dv = get_function<PFNGLUNIFORMMATRIX3X2DVPROC>("glUniformMatrix3x2dv")) != nullptr;
    result = result && (glUniformMatrix3x4dv = get_function<PFNGLUNIFORMMATRIX3X4DVPROC>("glUniformMatrix3x4dv")) != nullptr;
    result = result && (glUniformMatrix4x2dv = get_function<PFNGLUNIFORMMATRIX4X2DVPROC>("glUniformMatrix4x2dv")) != nullptr;
    result = result && (glUniformMatrix4x3dv = get_function<PFNGLUNIFORMMATRIX4X3DVPROC>("glUniformMatrix4x3dv")) != nullptr;
    result = result && (glGetUniformdv = get_function<PFNGLGETUNIFORMDVPROC>("glGetUniformdv")) != nullptr;
    result = result && (glGetSubroutineUniformLocation = get_function<PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC>("glGetSubroutineUniformLocation")) != nullptr;
    result = result && (glGetSubroutineIndex = get_function<PFNGLGETSUBROUTINEINDEXPROC>("glGetSubroutineIndex")) != nullptr;
    result = result && (glGetActiveSubroutineUniformiv = get_function<PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC>("glGetActiveSubroutineUniformiv")) != nullptr;
    result = result && (glGetActiveSubroutineUniformName = get_function<PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC>("glGetActiveSubroutineUniformName")) != nullptr;
    result = result && (glGetActiveSubroutineName = get_function<PFNGLGETACTIVESUBROUTINENAMEPROC>("glGetActiveSubroutineName")) != nullptr;
    result = result && (glUniformSubroutinesuiv = get_function<PFNGLUNIFORMSUBROUTINESUIVPROC>("glUniformSubroutinesuiv")) != nullptr;
    result = result && (glGetUniformSubroutineuiv = get_function<PFNGLGETUNIFORMSUBROUTINEUIVPROC>("glGetUniformSubroutineuiv")) != nullptr;
    result = result && (glGetProgramStageiv = get_function<PFNGLGETPROGRAMSTAGEIVPROC>("glGetProgramStageiv")) != nullptr;
    result = result && (glPatchParameteri = get_function<PFNGLPATCHPARAMETERIPROC>("glPatchParameteri")) != nullptr;
    result = result && (glPatchParameterfv = get_function<PFNGLPATCHPARAMETERFVPROC>("glPatchParameterfv")) != nullptr;
    result = result && (glBindTransformFeedback = get_function<PFNGLBINDTRANSFORMFEEDBACKPROC>("glBindTransformFeedback")) != nullptr;
    result = result && (glDeleteTransformFeedbacks = get_function<PFNGLDELETETRANSFORMFEEDBACKSPROC>("glDeleteTransformFeedbacks")) != nullptr;
    result = result && (glGenTransformFeedbacks = get_function<PFNGLGENTRANSFORMFEEDBACKSPROC>("glGenTransformFeedbacks")) != nullptr;
    result = result && (glIsTransformFeedback = get_function<PFNGLISTRANSFORMFEEDBACKPROC>("glIsTransformFeedback")) != nullptr;
    result = result && (glPauseTransformFeedback = get_function<PFNGLPAUSETRANSFORMFEEDBACKPROC>("glPauseTransformFeedback")) != nullptr;
    result = result && (glResumeTransformFeedback = get_function<PFNGLRESUMETRANSFORMFEEDBACKPROC>("glResumeTransformFeedback")) != nullptr;
    result = result && (glDrawTransformFeedback = get_function<PFNGLDRAWTRANSFORMFEEDBACKPROC>("glDrawTransformFeedback")) != nullptr;
    result = result && (glDrawTransformFeedbackStream = get_function<PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC>("glDrawTransformFeedbackStream")) != nullptr;
    result = result && (glBeginQueryIndexed = get_function<PFNGLBEGINQUERYINDEXEDPROC>("glBeginQueryIndexed")) != nullptr;
    result = result && (glEndQueryIndexed = get_function<PFNGLENDQUERYINDEXEDPROC>("glEndQueryIndexed")) != nullptr;
    result = result && (glGetQueryIndexediv = get_function<PFNGLGETQUERYINDEXEDIVPROC>("glGetQueryIndexediv")) != nullptr;
    // clang-format on

    return result;
}

#endif // GL_VERSION_4_0

#pragma endregion

#pragma region GL_VERSION_4_1

#ifdef GL_VERSION_4_1

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

bool init_gl_version_4_1()
{
    bool result = true;

    // clang-format off
    result = result && (glReleaseShaderCompiler = get_function<PFNGLRELEASESHADERCOMPILERPROC>("glReleaseShaderCompiler")) != nullptr;
    result = result && (glShaderBinary = get_function<PFNGLSHADERBINARYPROC>("glShaderBinary")) != nullptr;
    result = result && (glGetShaderPrecisionFormat = get_function<PFNGLGETSHADERPRECISIONFORMATPROC>("glGetShaderPrecisionFormat")) != nullptr;
    result = result && (glDepthRangef = get_function<PFNGLDEPTHRANGEFPROC>("glDepthRangef")) != nullptr;
    result = result && (glClearDepthf = get_function<PFNGLCLEARDEPTHFPROC>("glClearDepthf")) != nullptr;
    result = result && (glGetProgramBinary = get_function<PFNGLGETPROGRAMBINARYPROC>("glGetProgramBinary")) != nullptr;
    result = result && (glProgramBinary = get_function<PFNGLPROGRAMBINARYPROC>("glProgramBinary")) != nullptr;
    result = result && (glProgramParameteri = get_function<PFNGLPROGRAMPARAMETERIPROC>("glProgramParameteri")) != nullptr;
    result = result && (glUseProgramStages = get_function<PFNGLUSEPROGRAMSTAGESPROC>("glUseProgramStages")) != nullptr;
    result = result && (glActiveShaderProgram = get_function<PFNGLACTIVESHADERPROGRAMPROC>("glActiveShaderProgram")) != nullptr;
    result = result && (glCreateShaderProgramv = get_function<PFNGLCREATESHADERPROGRAMVPROC>("glCreateShaderProgramv")) != nullptr;
    result = result && (glBindProgramPipeline = get_function<PFNGLBINDPROGRAMPIPELINEPROC>("glBindProgramPipeline")) != nullptr;
    result = result && (glDeleteProgramPipelines = get_function<PFNGLDELETEPROGRAMPIPELINESPROC>("glDeleteProgramPipelines")) != nullptr;
    result = result && (glGenProgramPipelines = get_function<PFNGLGENPROGRAMPIPELINESPROC>("glGenProgramPipelines")) != nullptr;
    result = result && (glIsProgramPipeline = get_function<PFNGLISPROGRAMPIPELINEPROC>("glIsProgramPipeline")) != nullptr;
    result = result && (glGetProgramPipelineiv = get_function<PFNGLGETPROGRAMPIPELINEIVPROC>("glGetProgramPipelineiv")) != nullptr;
    result = result && (glProgramUniform1i = get_function<PFNGLPROGRAMUNIFORM1IPROC>("glProgramUniform1i")) != nullptr;
    result = result && (glProgramUniform1iv = get_function<PFNGLPROGRAMUNIFORM1IVPROC>("glProgramUniform1iv")) != nullptr;
    result = result && (glProgramUniform1f = get_function<PFNGLPROGRAMUNIFORM1FPROC>("glProgramUniform1f")) != nullptr;
    result = result && (glProgramUniform1fv = get_function<PFNGLPROGRAMUNIFORM1FVPROC>("glProgramUniform1fv")) != nullptr;
    result = result && (glProgramUniform1d = get_function<PFNGLPROGRAMUNIFORM1DPROC>("glProgramUniform1d")) != nullptr;
    result = result && (glProgramUniform1dv = get_function<PFNGLPROGRAMUNIFORM1DVPROC>("glProgramUniform1dv")) != nullptr;
    result = result && (glProgramUniform1ui = get_function<PFNGLPROGRAMUNIFORM1UIPROC>("glProgramUniform1ui")) != nullptr;
    result = result && (glProgramUniform1uiv = get_function<PFNGLPROGRAMUNIFORM1UIVPROC>("glProgramUniform1uiv")) != nullptr;
    result = result && (glProgramUniform2i = get_function<PFNGLPROGRAMUNIFORM2IPROC>("glProgramUniform2i")) != nullptr;
    result = result && (glProgramUniform2iv = get_function<PFNGLPROGRAMUNIFORM2IVPROC>("glProgramUniform2iv")) != nullptr;
    result = result && (glProgramUniform2f = get_function<PFNGLPROGRAMUNIFORM2FPROC>("glProgramUniform2f")) != nullptr;
    result = result && (glProgramUniform2fv = get_function<PFNGLPROGRAMUNIFORM2FVPROC>("glProgramUniform2fv")) != nullptr;
    result = result && (glProgramUniform2d = get_function<PFNGLPROGRAMUNIFORM2DPROC>("glProgramUniform2d")) != nullptr;
    result = result && (glProgramUniform2dv = get_function<PFNGLPROGRAMUNIFORM2DVPROC>("glProgramUniform2dv")) != nullptr;
    result = result && (glProgramUniform2ui = get_function<PFNGLPROGRAMUNIFORM2UIPROC>("glProgramUniform2ui")) != nullptr;
    result = result && (glProgramUniform2uiv = get_function<PFNGLPROGRAMUNIFORM2UIVPROC>("glProgramUniform2uiv")) != nullptr;
    result = result && (glProgramUniform3i = get_function<PFNGLPROGRAMUNIFORM3IPROC>("glProgramUniform3i")) != nullptr;
    result = result && (glProgramUniform3iv = get_function<PFNGLPROGRAMUNIFORM3IVPROC>("glProgramUniform3iv")) != nullptr;
    result = result && (glProgramUniform3f = get_function<PFNGLPROGRAMUNIFORM3FPROC>("glProgramUniform3f")) != nullptr;
    result = result && (glProgramUniform3fv = get_function<PFNGLPROGRAMUNIFORM3FVPROC>("glProgramUniform3fv")) != nullptr;
    result = result && (glProgramUniform3d = get_function<PFNGLPROGRAMUNIFORM3DPROC>("glProgramUniform3d")) != nullptr;
    result = result && (glProgramUniform3dv = get_function<PFNGLPROGRAMUNIFORM3DVPROC>("glProgramUniform3dv")) != nullptr;
    result = result && (glProgramUniform3ui = get_function<PFNGLPROGRAMUNIFORM3UIPROC>("glProgramUniform3ui")) != nullptr;
    result = result && (glProgramUniform3uiv = get_function<PFNGLPROGRAMUNIFORM3UIVPROC>("glProgramUniform3uiv")) != nullptr;
    result = result && (glProgramUniform4i = get_function<PFNGLPROGRAMUNIFORM4IPROC>("glProgramUniform4i")) != nullptr;
    result = result && (glProgramUniform4iv = get_function<PFNGLPROGRAMUNIFORM4IVPROC>("glProgramUniform4iv")) != nullptr;
    result = result && (glProgramUniform4f = get_function<PFNGLPROGRAMUNIFORM4FPROC>("glProgramUniform4f")) != nullptr;
    result = result && (glProgramUniform4fv = get_function<PFNGLPROGRAMUNIFORM4FVPROC>("glProgramUniform4fv")) != nullptr;
    result = result && (glProgramUniform4d = get_function<PFNGLPROGRAMUNIFORM4DPROC>("glProgramUniform4d")) != nullptr;
    result = result && (glProgramUniform4dv = get_function<PFNGLPROGRAMUNIFORM4DVPROC>("glProgramUniform4dv")) != nullptr;
    result = result && (glProgramUniform4ui = get_function<PFNGLPROGRAMUNIFORM4UIPROC>("glProgramUniform4ui")) != nullptr;
    result = result && (glProgramUniform4uiv = get_function<PFNGLPROGRAMUNIFORM4UIVPROC>("glProgramUniform4uiv")) != nullptr;
    result = result && (glProgramUniformMatrix2fv = get_function<PFNGLPROGRAMUNIFORMMATRIX2FVPROC>("glProgramUniformMatrix2fv")) != nullptr;
    result = result && (glProgramUniformMatrix3fv = get_function<PFNGLPROGRAMUNIFORMMATRIX3FVPROC>("glProgramUniformMatrix3fv")) != nullptr;
    result = result && (glProgramUniformMatrix4fv = get_function<PFNGLPROGRAMUNIFORMMATRIX4FVPROC>("glProgramUniformMatrix4fv")) != nullptr;
    result = result && (glProgramUniformMatrix2dv = get_function<PFNGLPROGRAMUNIFORMMATRIX2DVPROC>("glProgramUniformMatrix2dv")) != nullptr;
    result = result && (glProgramUniformMatrix3dv = get_function<PFNGLPROGRAMUNIFORMMATRIX3DVPROC>("glProgramUniformMatrix3dv")) != nullptr;
    result = result && (glProgramUniformMatrix4dv = get_function<PFNGLPROGRAMUNIFORMMATRIX4DVPROC>("glProgramUniformMatrix4dv")) != nullptr;
    result = result && (glProgramUniformMatrix2x3fv = get_function<PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC>("glProgramUniformMatrix2x3fv")) != nullptr;
    result = result && (glProgramUniformMatrix3x2fv = get_function<PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC>("glProgramUniformMatrix3x2fv")) != nullptr;
    result = result && (glProgramUniformMatrix2x4fv = get_function<PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC>("glProgramUniformMatrix2x4fv")) != nullptr;
    result = result && (glProgramUniformMatrix4x2fv = get_function<PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC>("glProgramUniformMatrix4x2fv")) != nullptr;
    result = result && (glProgramUniformMatrix3x4fv = get_function<PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC>("glProgramUniformMatrix3x4fv")) != nullptr;
    result = result && (glProgramUniformMatrix4x3fv = get_function<PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC>("glProgramUniformMatrix4x3fv")) != nullptr;
    result = result && (glProgramUniformMatrix2x3dv = get_function<PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC>("glProgramUniformMatrix2x3dv")) != nullptr;
    result = result && (glProgramUniformMatrix3x2dv = get_function<PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC>("glProgramUniformMatrix3x2dv")) != nullptr;
    result = result && (glProgramUniformMatrix2x4dv = get_function<PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC>("glProgramUniformMatrix2x4dv")) != nullptr;
    result = result && (glProgramUniformMatrix4x2dv = get_function<PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC>("glProgramUniformMatrix4x2dv")) != nullptr;
    result = result && (glProgramUniformMatrix3x4dv = get_function<PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC>("glProgramUniformMatrix3x4dv")) != nullptr;
    result = result && (glProgramUniformMatrix4x3dv = get_function<PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC>("glProgramUniformMatrix4x3dv")) != nullptr;
    result = result && (glValidateProgramPipeline = get_function<PFNGLVALIDATEPROGRAMPIPELINEPROC>("glValidateProgramPipeline")) != nullptr;
    result = result && (glGetProgramPipelineInfoLog = get_function<PFNGLGETPROGRAMPIPELINEINFOLOGPROC>("glGetProgramPipelineInfoLog")) != nullptr;
    result = result && (glVertexAttribL1d = get_function<PFNGLVERTEXATTRIBL1DPROC>("glVertexAttribL1d")) != nullptr;
    result = result && (glVertexAttribL2d = get_function<PFNGLVERTEXATTRIBL2DPROC>("glVertexAttribL2d")) != nullptr;
    result = result && (glVertexAttribL3d = get_function<PFNGLVERTEXATTRIBL3DPROC>("glVertexAttribL3d")) != nullptr;
    result = result && (glVertexAttribL4d = get_function<PFNGLVERTEXATTRIBL4DPROC>("glVertexAttribL4d")) != nullptr;
    result = result && (glVertexAttribL1dv = get_function<PFNGLVERTEXATTRIBL1DVPROC>("glVertexAttribL1dv")) != nullptr;
    result = result && (glVertexAttribL2dv = get_function<PFNGLVERTEXATTRIBL2DVPROC>("glVertexAttribL2dv")) != nullptr;
    result = result && (glVertexAttribL3dv = get_function<PFNGLVERTEXATTRIBL3DVPROC>("glVertexAttribL3dv")) != nullptr;
    result = result && (glVertexAttribL4dv = get_function<PFNGLVERTEXATTRIBL4DVPROC>("glVertexAttribL4dv")) != nullptr;
    result = result && (glVertexAttribLPointer = get_function<PFNGLVERTEXATTRIBLPOINTERPROC>("glVertexAttribLPointer")) != nullptr;
    result = result && (glGetVertexAttribLdv = get_function<PFNGLGETVERTEXATTRIBLDVPROC>("glGetVertexAttribLdv")) != nullptr;
    result = result && (glViewportArrayv = get_function<PFNGLVIEWPORTARRAYVPROC>("glViewportArrayv")) != nullptr;
    result = result && (glViewportIndexedf = get_function<PFNGLVIEWPORTINDEXEDFPROC>("glViewportIndexedf")) != nullptr;
    result = result && (glViewportIndexedfv = get_function<PFNGLVIEWPORTINDEXEDFVPROC>("glViewportIndexedfv")) != nullptr;
    result = result && (glScissorArrayv = get_function<PFNGLSCISSORARRAYVPROC>("glScissorArrayv")) != nullptr;
    result = result && (glScissorIndexed = get_function<PFNGLSCISSORINDEXEDPROC>("glScissorIndexed")) != nullptr;
    result = result && (glScissorIndexedv = get_function<PFNGLSCISSORINDEXEDVPROC>("glScissorIndexedv")) != nullptr;
    result = result && (glDepthRangeArrayv = get_function<PFNGLDEPTHRANGEARRAYVPROC>("glDepthRangeArrayv")) != nullptr;
    result = result && (glDepthRangeIndexed = get_function<PFNGLDEPTHRANGEINDEXEDPROC>("glDepthRangeIndexed")) != nullptr;
    result = result && (glGetFloati_v = get_function<PFNGLGETFLOATI_VPROC>("glGetFloati_v")) != nullptr;
    result = result && (glGetDoublei_v = get_function<PFNGLGETDOUBLEI_VPROC>("glGetDoublei_v")) != nullptr;
    // clang-format on

    return result;
}

#endif // GL_VERSION_4_1

#pragma endregion

#pragma region GL_VERSION_4_2

#ifdef GL_VERSION_4_2

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

bool init_gl_version_4_2()
{
    bool result = true;

    // clang-format off
    result = result && (glDrawArraysInstancedBaseInstance = get_function<PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC>("glDrawArraysInstancedBaseInstance")) != nullptr;
    result = result && (glDrawElementsInstancedBaseInstance = get_function<PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC>("glDrawElementsInstancedBaseInstance")) != nullptr;
    result = result && (glDrawElementsInstancedBaseVertexBaseInstance = get_function<PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC>("glDrawElementsInstancedBaseVertexBaseInstance")) != nullptr;
    result = result && (glGetInternalformativ = get_function<PFNGLGETINTERNALFORMATIVPROC>("glGetInternalformativ")) != nullptr;
    result = result && (glGetActiveAtomicCounterBufferiv = get_function<PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC>("glGetActiveAtomicCounterBufferiv")) != nullptr;
    result = result && (glBindImageTexture = get_function<PFNGLBINDIMAGETEXTUREPROC>("glBindImageTexture")) != nullptr;
    result = result && (glMemoryBarrier = get_function<PFNGLMEMORYBARRIERPROC>("glMemoryBarrier")) != nullptr;
    result = result && (glTexStorage1D = get_function<PFNGLTEXSTORAGE1DPROC>("glTexStorage1D")) != nullptr;
    result = result && (glTexStorage2D = get_function<PFNGLTEXSTORAGE2DPROC>("glTexStorage2D")) != nullptr;
    result = result && (glTexStorage3D = get_function<PFNGLTEXSTORAGE3DPROC>("glTexStorage3D")) != nullptr;
    result = result && (glDrawTransformFeedbackInstanced = get_function<PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC>("glDrawTransformFeedbackInstanced")) != nullptr;
    result = result && (glDrawTransformFeedbackStreamInstanced = get_function<PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC>("glDrawTransformFeedbackStreamInstanced")) != nullptr;
    // clang-format on

    return result;
}

#endif // GL_VERSION_4_2

#pragma endregion

#pragma region GL_VERSION_4_3

#ifdef GL_VERSION_4_3

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

bool init_gl_version_4_3()
{
    bool result = true;

    // clang-format off
    result = result && (glClearBufferData = get_function<PFNGLCLEARBUFFERDATAPROC>("glClearBufferData")) != nullptr;
    result = result && (glClearBufferSubData = get_function<PFNGLCLEARBUFFERSUBDATAPROC>("glClearBufferSubData")) != nullptr;
    result = result && (glDispatchCompute = get_function<PFNGLDISPATCHCOMPUTEPROC>("glDispatchCompute")) != nullptr;
    result = result && (glDispatchComputeIndirect = get_function<PFNGLDISPATCHCOMPUTEINDIRECTPROC>("glDispatchComputeIndirect")) != nullptr;
    result = result && (glCopyImageSubData = get_function<PFNGLCOPYIMAGESUBDATAPROC>("glCopyImageSubData")) != nullptr;
    result = result && (glFramebufferParameteri = get_function<PFNGLFRAMEBUFFERPARAMETERIPROC>("glFramebufferParameteri")) != nullptr;
    result = result && (glGetFramebufferParameteriv = get_function<PFNGLGETFRAMEBUFFERPARAMETERIVPROC>("glGetFramebufferParameteriv")) != nullptr;
    result = result && (glGetInternalformati64v = get_function<PFNGLGETINTERNALFORMATI64VPROC>("glGetInternalformati64v")) != nullptr;
    result = result && (glInvalidateTexSubImage = get_function<PFNGLINVALIDATETEXSUBIMAGEPROC>("glInvalidateTexSubImage")) != nullptr;
    result = result && (glInvalidateTexImage = get_function<PFNGLINVALIDATETEXIMAGEPROC>("glInvalidateTexImage")) != nullptr;
    result = result && (glInvalidateBufferSubData = get_function<PFNGLINVALIDATEBUFFERSUBDATAPROC>("glInvalidateBufferSubData")) != nullptr;
    result = result && (glInvalidateBufferData = get_function<PFNGLINVALIDATEBUFFERDATAPROC>("glInvalidateBufferData")) != nullptr;
    result = result && (glInvalidateFramebuffer = get_function<PFNGLINVALIDATEFRAMEBUFFERPROC>("glInvalidateFramebuffer")) != nullptr;
    result = result && (glInvalidateSubFramebuffer = get_function<PFNGLINVALIDATESUBFRAMEBUFFERPROC>("glInvalidateSubFramebuffer")) != nullptr;
    result = result && (glMultiDrawArraysIndirect = get_function<PFNGLMULTIDRAWARRAYSINDIRECTPROC>("glMultiDrawArraysIndirect")) != nullptr;
    result = result && (glMultiDrawElementsIndirect = get_function<PFNGLMULTIDRAWELEMENTSINDIRECTPROC>("glMultiDrawElementsIndirect")) != nullptr;
    result = result && (glGetProgramInterfaceiv = get_function<PFNGLGETPROGRAMINTERFACEIVPROC>("glGetProgramInterfaceiv")) != nullptr;
    result = result && (glGetProgramResourceIndex = get_function<PFNGLGETPROGRAMRESOURCEINDEXPROC>("glGetProgramResourceIndex")) != nullptr;
    result = result && (glGetProgramResourceName = get_function<PFNGLGETPROGRAMRESOURCENAMEPROC>("glGetProgramResourceName")) != nullptr;
    result = result && (glGetProgramResourceiv = get_function<PFNGLGETPROGRAMRESOURCEIVPROC>("glGetProgramResourceiv")) != nullptr;
    result = result && (glGetProgramResourceLocation = get_function<PFNGLGETPROGRAMRESOURCELOCATIONPROC>("glGetProgramResourceLocation")) != nullptr;
    result = result && (glGetProgramResourceLocationIndex = get_function<PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC>("glGetProgramResourceLocationIndex")) != nullptr;
    result = result && (glShaderStorageBlockBinding = get_function<PFNGLSHADERSTORAGEBLOCKBINDINGPROC>("glShaderStorageBlockBinding")) != nullptr;
    result = result && (glTexBufferRange = get_function<PFNGLTEXBUFFERRANGEPROC>("glTexBufferRange")) != nullptr;
    result = result && (glTexStorage2DMultisample = get_function<PFNGLTEXSTORAGE2DMULTISAMPLEPROC>("glTexStorage2DMultisample")) != nullptr;
    result = result && (glTexStorage3DMultisample = get_function<PFNGLTEXSTORAGE3DMULTISAMPLEPROC>("glTexStorage3DMultisample")) != nullptr;
    result = result && (glTextureView = get_function<PFNGLTEXTUREVIEWPROC>("glTextureView")) != nullptr;
    result = result && (glBindVertexBuffer = get_function<PFNGLBINDVERTEXBUFFERPROC>("glBindVertexBuffer")) != nullptr;
    result = result && (glVertexAttribFormat = get_function<PFNGLVERTEXATTRIBFORMATPROC>("glVertexAttribFormat")) != nullptr;
    result = result && (glVertexAttribIFormat = get_function<PFNGLVERTEXATTRIBIFORMATPROC>("glVertexAttribIFormat")) != nullptr;
    result = result && (glVertexAttribLFormat = get_function<PFNGLVERTEXATTRIBLFORMATPROC>("glVertexAttribLFormat")) != nullptr;
    result = result && (glVertexAttribBinding = get_function<PFNGLVERTEXATTRIBBINDINGPROC>("glVertexAttribBinding")) != nullptr;
    result = result && (glVertexBindingDivisor = get_function<PFNGLVERTEXBINDINGDIVISORPROC>("glVertexBindingDivisor")) != nullptr;
    result = result && (glDebugMessageControl = get_function<PFNGLDEBUGMESSAGECONTROLPROC>("glDebugMessageControl")) != nullptr;
    result = result && (glDebugMessageInsert = get_function<PFNGLDEBUGMESSAGEINSERTPROC>("glDebugMessageInsert")) != nullptr;
    result = result && (glDebugMessageCallback = get_function<PFNGLDEBUGMESSAGECALLBACKPROC>("glDebugMessageCallback")) != nullptr;
    result = result && (glGetDebugMessageLog = get_function<PFNGLGETDEBUGMESSAGELOGPROC>("glGetDebugMessageLog")) != nullptr;
    result = result && (glPushDebugGroup = get_function<PFNGLPUSHDEBUGGROUPPROC>("glPushDebugGroup")) != nullptr;
    result = result && (glPopDebugGroup = get_function<PFNGLPOPDEBUGGROUPPROC>("glPopDebugGroup")) != nullptr;
    result = result && (glObjectLabel = get_function<PFNGLOBJECTLABELPROC>("glObjectLabel")) != nullptr;
    result = result && (glGetObjectLabel = get_function<PFNGLGETOBJECTLABELPROC>("glGetObjectLabel")) != nullptr;
    result = result && (glObjectPtrLabel = get_function<PFNGLOBJECTPTRLABELPROC>("glObjectPtrLabel")) != nullptr;
    result = result && (glGetObjectPtrLabel = get_function<PFNGLGETOBJECTPTRLABELPROC>("glGetObjectPtrLabel")) != nullptr;
    // clang-format on

    return result;
}

#endif // GL_VERSION_4_3

#pragma endregion

#pragma region GL_VERSION_4_4

#ifdef GL_VERSION_4_4

PFNGLBUFFERSTORAGEPROC glBufferStorage         = nullptr;
PFNGLCLEARTEXIMAGEPROC glClearTexImage         = nullptr;
PFNGLCLEARTEXSUBIMAGEPROC glClearTexSubImage   = nullptr;
PFNGLBINDBUFFERSBASEPROC glBindBuffersBase     = nullptr;
PFNGLBINDBUFFERSRANGEPROC glBindBuffersRange   = nullptr;
PFNGLBINDTEXTURESPROC glBindTextures           = nullptr;
PFNGLBINDSAMPLERSPROC glBindSamplers           = nullptr;
PFNGLBINDIMAGETEXTURESPROC glBindImageTextures = nullptr;
PFNGLBINDVERTEXBUFFERSPROC glBindVertexBuffers = nullptr;

bool init_gl_version_4_4()
{
    bool result = true;

    // clang-format off
    result = result && (glBufferStorage = get_function<PFNGLBUFFERSTORAGEPROC>("glBufferStorage")) != nullptr;
    result = result && (glClearTexImage = get_function<PFNGLCLEARTEXIMAGEPROC>("glClearTexImage")) != nullptr;
    result = result && (glClearTexSubImage = get_function<PFNGLCLEARTEXSUBIMAGEPROC>("glClearTexSubImage")) != nullptr;
    result = result && (glBindBuffersBase = get_function<PFNGLBINDBUFFERSBASEPROC>("glBindBuffersBase")) != nullptr;
    result = result && (glBindBuffersRange = get_function<PFNGLBINDBUFFERSRANGEPROC>("glBindBuffersRange")) != nullptr;
    result = result && (glBindTextures = get_function<PFNGLBINDTEXTURESPROC>("glBindTextures")) != nullptr;
    result = result && (glBindSamplers = get_function<PFNGLBINDSAMPLERSPROC>("glBindSamplers")) != nullptr;
    result = result && (glBindImageTextures = get_function<PFNGLBINDIMAGETEXTURESPROC>("glBindImageTextures")) != nullptr;
    result = result && (glBindVertexBuffers = get_function<PFNGLBINDVERTEXBUFFERSPROC>("glBindVertexBuffers")) != nullptr;
    // clang-format on

    return result;
}

#endif // GL_VERSION_4_4

#pragma endregion

#pragma region GL_VERSION_4_5

#ifdef GL_VERSION_4_5

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

bool init_gl_version_4_5()
{
    bool result = true;

    // clang-format off
    result = result && (glClipControl = get_function<PFNGLCLIPCONTROLPROC>("glClipControl")) != nullptr;
    result = result && (glCreateTransformFeedbacks = get_function<PFNGLCREATETRANSFORMFEEDBACKSPROC>("glCreateTransformFeedbacks")) != nullptr;
    result = result && (glTransformFeedbackBufferBase = get_function<PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC>("glTransformFeedbackBufferBase")) != nullptr;
    result = result && (glTransformFeedbackBufferRange = get_function<PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC>("glTransformFeedbackBufferRange")) != nullptr;
    result = result && (glGetTransformFeedbackiv = get_function<PFNGLGETTRANSFORMFEEDBACKIVPROC>("glGetTransformFeedbackiv")) != nullptr;
    result = result && (glGetTransformFeedbacki_v = get_function<PFNGLGETTRANSFORMFEEDBACKI_VPROC>("glGetTransformFeedbacki_v")) != nullptr;
    result = result && (glGetTransformFeedbacki64_v = get_function<PFNGLGETTRANSFORMFEEDBACKI64_VPROC>("glGetTransformFeedbacki64_v")) != nullptr;
    result = result && (glCreateBuffers = get_function<PFNGLCREATEBUFFERSPROC>("glCreateBuffers")) != nullptr;
    result = result && (glNamedBufferStorage = get_function<PFNGLNAMEDBUFFERSTORAGEPROC>("glNamedBufferStorage")) != nullptr;
    result = result && (glNamedBufferData = get_function<PFNGLNAMEDBUFFERDATAPROC>("glNamedBufferData")) != nullptr;
    result = result && (glNamedBufferSubData = get_function<PFNGLNAMEDBUFFERSUBDATAPROC>("glNamedBufferSubData")) != nullptr;
    result = result && (glCopyNamedBufferSubData = get_function<PFNGLCOPYNAMEDBUFFERSUBDATAPROC>("glCopyNamedBufferSubData")) != nullptr;
    result = result && (glClearNamedBufferData = get_function<PFNGLCLEARNAMEDBUFFERDATAPROC>("glClearNamedBufferData")) != nullptr;
    result = result && (glClearNamedBufferSubData = get_function<PFNGLCLEARNAMEDBUFFERSUBDATAPROC>("glClearNamedBufferSubData")) != nullptr;
    result = result && (glMapNamedBuffer = get_function<PFNGLMAPNAMEDBUFFERPROC>("glMapNamedBuffer")) != nullptr;
    result = result && (glMapNamedBufferRange = get_function<PFNGLMAPNAMEDBUFFERRANGEPROC>("glMapNamedBufferRange")) != nullptr;
    result = result && (glUnmapNamedBuffer = get_function<PFNGLUNMAPNAMEDBUFFERPROC>("glUnmapNamedBuffer")) != nullptr;
    result = result && (glFlushMappedNamedBufferRange = get_function<PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC>("glFlushMappedNamedBufferRange")) != nullptr;
    result = result && (glGetNamedBufferParameteriv = get_function<PFNGLGETNAMEDBUFFERPARAMETERIVPROC>("glGetNamedBufferParameteriv")) != nullptr;
    result = result && (glGetNamedBufferParameteri64v = get_function<PFNGLGETNAMEDBUFFERPARAMETERI64VPROC>("glGetNamedBufferParameteri64v")) != nullptr;
    result = result && (glGetNamedBufferPointerv = get_function<PFNGLGETNAMEDBUFFERPOINTERVPROC>("glGetNamedBufferPointerv")) != nullptr;
    result = result && (glGetNamedBufferSubData = get_function<PFNGLGETNAMEDBUFFERSUBDATAPROC>("glGetNamedBufferSubData")) != nullptr;
    result = result && (glCreateFramebuffers = get_function<PFNGLCREATEFRAMEBUFFERSPROC>("glCreateFramebuffers")) != nullptr;
    result = result && (glNamedFramebufferRenderbuffer = get_function<PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC>("glNamedFramebufferRenderbuffer")) != nullptr;
    result = result && (glNamedFramebufferParameteri = get_function<PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC>("glNamedFramebufferParameteri")) != nullptr;
    result = result && (glNamedFramebufferTexture = get_function<PFNGLNAMEDFRAMEBUFFERTEXTUREPROC>("glNamedFramebufferTexture")) != nullptr;
    result = result && (glNamedFramebufferTextureLayer = get_function<PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC>("glNamedFramebufferTextureLayer")) != nullptr;
    result = result && (glNamedFramebufferDrawBuffer = get_function<PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC>("glNamedFramebufferDrawBuffer")) != nullptr;
    result = result && (glNamedFramebufferDrawBuffers = get_function<PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC>("glNamedFramebufferDrawBuffers")) != nullptr;
    result = result && (glNamedFramebufferReadBuffer = get_function<PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC>("glNamedFramebufferReadBuffer")) != nullptr;
    result = result && (glInvalidateNamedFramebufferData = get_function<PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC>("glInvalidateNamedFramebufferData")) != nullptr;
    result = result && (glInvalidateNamedFramebufferSubData = get_function<PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC>("glInvalidateNamedFramebufferSubData")) != nullptr;
    result = result && (glClearNamedFramebufferiv = get_function<PFNGLCLEARNAMEDFRAMEBUFFERIVPROC>("glClearNamedFramebufferiv")) != nullptr;
    result = result && (glClearNamedFramebufferuiv = get_function<PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC>("glClearNamedFramebufferuiv")) != nullptr;
    result = result && (glClearNamedFramebufferfv = get_function<PFNGLCLEARNAMEDFRAMEBUFFERFVPROC>("glClearNamedFramebufferfv")) != nullptr;
    result = result && (glClearNamedFramebufferfi = get_function<PFNGLCLEARNAMEDFRAMEBUFFERFIPROC>("glClearNamedFramebufferfi")) != nullptr;
    result = result && (glBlitNamedFramebuffer = get_function<PFNGLBLITNAMEDFRAMEBUFFERPROC>("glBlitNamedFramebuffer")) != nullptr;
    result = result && (glCheckNamedFramebufferStatus = get_function<PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC>("glCheckNamedFramebufferStatus")) != nullptr;
    result = result && (glGetNamedFramebufferParameteriv = get_function<PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC>("glGetNamedFramebufferParameteriv")) != nullptr;
    result = result && (glGetNamedFramebufferAttachmentParameteriv = get_function<PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC>("glGetNamedFramebufferAttachmentParameteriv")) != nullptr;
    result = result && (glCreateRenderbuffers = get_function<PFNGLCREATERENDERBUFFERSPROC>("glCreateRenderbuffers")) != nullptr;
    result = result && (glNamedRenderbufferStorage = get_function<PFNGLNAMEDRENDERBUFFERSTORAGEPROC>("glNamedRenderbufferStorage")) != nullptr;
    result = result && (glNamedRenderbufferStorageMultisample = get_function<PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC>("glNamedRenderbufferStorageMultisample")) != nullptr;
    result = result && (glGetNamedRenderbufferParameteriv = get_function<PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC>("glGetNamedRenderbufferParameteriv")) != nullptr;
    result = result && (glCreateTextures = get_function<PFNGLCREATETEXTURESPROC>("glCreateTextures")) != nullptr;
    result = result && (glTextureBuffer = get_function<PFNGLTEXTUREBUFFERPROC>("glTextureBuffer")) != nullptr;
    result = result && (glTextureBufferRange = get_function<PFNGLTEXTUREBUFFERRANGEPROC>("glTextureBufferRange")) != nullptr;
    result = result && (glTextureStorage1D = get_function<PFNGLTEXTURESTORAGE1DPROC>("glTextureStorage1D")) != nullptr;
    result = result && (glTextureStorage2D = get_function<PFNGLTEXTURESTORAGE2DPROC>("glTextureStorage2D")) != nullptr;
    result = result && (glTextureStorage3D = get_function<PFNGLTEXTURESTORAGE3DPROC>("glTextureStorage3D")) != nullptr;
    result = result && (glTextureStorage2DMultisample = get_function<PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC>("glTextureStorage2DMultisample")) != nullptr;
    result = result && (glTextureStorage3DMultisample = get_function<PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC>("glTextureStorage3DMultisample")) != nullptr;
    result = result && (glTextureSubImage1D = get_function<PFNGLTEXTURESUBIMAGE1DPROC>("glTextureSubImage1D")) != nullptr;
    result = result && (glTextureSubImage2D = get_function<PFNGLTEXTURESUBIMAGE2DPROC>("glTextureSubImage2D")) != nullptr;
    result = result && (glTextureSubImage3D = get_function<PFNGLTEXTURESUBIMAGE3DPROC>("glTextureSubImage3D")) != nullptr;
    result = result && (glCompressedTextureSubImage1D = get_function<PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC>("glCompressedTextureSubImage1D")) != nullptr;
    result = result && (glCompressedTextureSubImage2D = get_function<PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC>("glCompressedTextureSubImage2D")) != nullptr;
    result = result && (glCompressedTextureSubImage3D = get_function<PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC>("glCompressedTextureSubImage3D")) != nullptr;
    result = result && (glCopyTextureSubImage1D = get_function<PFNGLCOPYTEXTURESUBIMAGE1DPROC>("glCopyTextureSubImage1D")) != nullptr;
    result = result && (glCopyTextureSubImage2D = get_function<PFNGLCOPYTEXTURESUBIMAGE2DPROC>("glCopyTextureSubImage2D")) != nullptr;
    result = result && (glCopyTextureSubImage3D = get_function<PFNGLCOPYTEXTURESUBIMAGE3DPROC>("glCopyTextureSubImage3D")) != nullptr;
    result = result && (glTextureParameterf = get_function<PFNGLTEXTUREPARAMETERFPROC>("glTextureParameterf")) != nullptr;
    result = result && (glTextureParameterfv = get_function<PFNGLTEXTUREPARAMETERFVPROC>("glTextureParameterfv")) != nullptr;
    result = result && (glTextureParameteri = get_function<PFNGLTEXTUREPARAMETERIPROC>("glTextureParameteri")) != nullptr;
    result = result && (glTextureParameterIiv = get_function<PFNGLTEXTUREPARAMETERIIVPROC>("glTextureParameterIiv")) != nullptr;
    result = result && (glTextureParameterIuiv = get_function<PFNGLTEXTUREPARAMETERIUIVPROC>("glTextureParameterIuiv")) != nullptr;
    result = result && (glTextureParameteriv = get_function<PFNGLTEXTUREPARAMETERIVPROC>("glTextureParameteriv")) != nullptr;
    result = result && (glGenerateTextureMipmap = get_function<PFNGLGENERATETEXTUREMIPMAPPROC>("glGenerateTextureMipmap")) != nullptr;
    result = result && (glBindTextureUnit = get_function<PFNGLBINDTEXTUREUNITPROC>("glBindTextureUnit")) != nullptr;
    result = result && (glGetTextureImage = get_function<PFNGLGETTEXTUREIMAGEPROC>("glGetTextureImage")) != nullptr;
    result = result && (glGetCompressedTextureImage = get_function<PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC>("glGetCompressedTextureImage")) != nullptr;
    result = result && (glGetTextureLevelParameterfv = get_function<PFNGLGETTEXTURELEVELPARAMETERFVPROC>("glGetTextureLevelParameterfv")) != nullptr;
    result = result && (glGetTextureLevelParameteriv = get_function<PFNGLGETTEXTURELEVELPARAMETERIVPROC>("glGetTextureLevelParameteriv")) != nullptr;
    result = result && (glGetTextureParameterfv = get_function<PFNGLGETTEXTUREPARAMETERFVPROC>("glGetTextureParameterfv")) != nullptr;
    result = result && (glGetTextureParameterIiv = get_function<PFNGLGETTEXTUREPARAMETERIIVPROC>("glGetTextureParameterIiv")) != nullptr;
    result = result && (glGetTextureParameterIuiv = get_function<PFNGLGETTEXTUREPARAMETERIUIVPROC>("glGetTextureParameterIuiv")) != nullptr;
    result = result && (glGetTextureParameteriv = get_function<PFNGLGETTEXTUREPARAMETERIVPROC>("glGetTextureParameteriv")) != nullptr;
    result = result && (glCreateVertexArrays = get_function<PFNGLCREATEVERTEXARRAYSPROC>("glCreateVertexArrays")) != nullptr;
    result = result && (glDisableVertexArrayAttrib = get_function<PFNGLDISABLEVERTEXARRAYATTRIBPROC>("glDisableVertexArrayAttrib")) != nullptr;
    result = result && (glEnableVertexArrayAttrib = get_function<PFNGLENABLEVERTEXARRAYATTRIBPROC>("glEnableVertexArrayAttrib")) != nullptr;
    result = result && (glVertexArrayElementBuffer = get_function<PFNGLVERTEXARRAYELEMENTBUFFERPROC>("glVertexArrayElementBuffer")) != nullptr;
    result = result && (glVertexArrayVertexBuffer = get_function<PFNGLVERTEXARRAYVERTEXBUFFERPROC>("glVertexArrayVertexBuffer")) != nullptr;
    result = result && (glVertexArrayVertexBuffers = get_function<PFNGLVERTEXARRAYVERTEXBUFFERSPROC>("glVertexArrayVertexBuffers")) != nullptr;
    result = result && (glVertexArrayAttribBinding = get_function<PFNGLVERTEXARRAYATTRIBBINDINGPROC>("glVertexArrayAttribBinding")) != nullptr;
    result = result && (glVertexArrayAttribFormat = get_function<PFNGLVERTEXARRAYATTRIBFORMATPROC>("glVertexArrayAttribFormat")) != nullptr;
    result = result && (glVertexArrayAttribIFormat = get_function<PFNGLVERTEXARRAYATTRIBIFORMATPROC>("glVertexArrayAttribIFormat")) != nullptr;
    result = result && (glVertexArrayAttribLFormat = get_function<PFNGLVERTEXARRAYATTRIBLFORMATPROC>("glVertexArrayAttribLFormat")) != nullptr;
    result = result && (glVertexArrayBindingDivisor = get_function<PFNGLVERTEXARRAYBINDINGDIVISORPROC>("glVertexArrayBindingDivisor")) != nullptr;
    result = result && (glGetVertexArrayiv = get_function<PFNGLGETVERTEXARRAYIVPROC>("glGetVertexArrayiv")) != nullptr;
    result = result && (glGetVertexArrayIndexediv = get_function<PFNGLGETVERTEXARRAYINDEXEDIVPROC>("glGetVertexArrayIndexediv")) != nullptr;
    result = result && (glGetVertexArrayIndexed64iv = get_function<PFNGLGETVERTEXARRAYINDEXED64IVPROC>("glGetVertexArrayIndexed64iv")) != nullptr;
    result = result && (glCreateSamplers = get_function<PFNGLCREATESAMPLERSPROC>("glCreateSamplers")) != nullptr;
    result = result && (glCreateProgramPipelines = get_function<PFNGLCREATEPROGRAMPIPELINESPROC>("glCreateProgramPipelines")) != nullptr;
    result = result && (glCreateQueries = get_function<PFNGLCREATEQUERIESPROC>("glCreateQueries")) != nullptr;
    result = result && (glGetQueryBufferObjecti64v = get_function<PFNGLGETQUERYBUFFEROBJECTI64VPROC>("glGetQueryBufferObjecti64v")) != nullptr;
    result = result && (glGetQueryBufferObjectiv = get_function<PFNGLGETQUERYBUFFEROBJECTIVPROC>("glGetQueryBufferObjectiv")) != nullptr;
    result = result && (glGetQueryBufferObjectui64v = get_function<PFNGLGETQUERYBUFFEROBJECTUI64VPROC>("glGetQueryBufferObjectui64v")) != nullptr;
    result = result && (glGetQueryBufferObjectuiv = get_function<PFNGLGETQUERYBUFFEROBJECTUIVPROC>("glGetQueryBufferObjectuiv")) != nullptr;
    result = result && (glMemoryBarrierByRegion = get_function<PFNGLMEMORYBARRIERBYREGIONPROC>("glMemoryBarrierByRegion")) != nullptr;
    result = result && (glGetTextureSubImage = get_function<PFNGLGETTEXTURESUBIMAGEPROC>("glGetTextureSubImage")) != nullptr;
    result = result && (glGetCompressedTextureSubImage = get_function<PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC>("glGetCompressedTextureSubImage")) != nullptr;
    result = result && (glGetGraphicsResetStatus = get_function<PFNGLGETGRAPHICSRESETSTATUSPROC>("glGetGraphicsResetStatus")) != nullptr;
    result = result && (glGetnCompressedTexImage = get_function<PFNGLGETNCOMPRESSEDTEXIMAGEPROC>("glGetnCompressedTexImage")) != nullptr;
    result = result && (glGetnTexImage = get_function<PFNGLGETNTEXIMAGEPROC>("glGetnTexImage")) != nullptr;
    result = result && (glGetnUniformdv = get_function<PFNGLGETNUNIFORMDVPROC>("glGetnUniformdv")) != nullptr;
    result = result && (glGetnUniformfv = get_function<PFNGLGETNUNIFORMFVPROC>("glGetnUniformfv")) != nullptr;
    result = result && (glGetnUniformiv = get_function<PFNGLGETNUNIFORMIVPROC>("glGetnUniformiv")) != nullptr;
    result = result && (glGetnUniformuiv = get_function<PFNGLGETNUNIFORMUIVPROC>("glGetnUniformuiv")) != nullptr;
    result = result && (glReadnPixels = get_function<PFNGLREADNPIXELSPROC>("glReadnPixels")) != nullptr;
    result = result && (glTextureBarrier = get_function<PFNGLTEXTUREBARRIERPROC>("glTextureBarrier")) != nullptr;
    // clang-format on

    return result;
}

#endif // GL_VERSION_4_5

#pragma endregion

#pragma region GL_VERSION_4_6

#ifdef GL_VERSION_4_6

PFNGLSPECIALIZESHADERPROC glSpecializeShader                             = nullptr;
PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC glMultiDrawArraysIndirectCount     = nullptr;
PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC glMultiDrawElementsIndirectCount = nullptr;
PFNGLPOLYGONOFFSETCLAMPPROC glPolygonOffsetClamp                         = nullptr;

bool init_gl_version_4_6()
{
    bool result = true;

    // clang-format off
    result = result && (glSpecializeShader = get_function<PFNGLSPECIALIZESHADERPROC>("glSpecializeShader")) != nullptr;
    result = result && (glMultiDrawArraysIndirectCount = get_function<PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC>("glMultiDrawArraysIndirectCount")) != nullptr;
    result = result && (glMultiDrawElementsIndirectCount = get_function<PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC>("glMultiDrawElementsIndirectCount")) != nullptr;
    result = result && (glPolygonOffsetClamp = get_function<PFNGLPOLYGONOFFSETCLAMPPROC>("glPolygonOffsetClamp")) != nullptr;
    // clang-format on

    return result;
}

#endif // GL_VERSION_4_6

#pragma endregion

#pragma regin init

bool init()
{
    bool result = true;

#ifdef GL_VERSION_1_0
    result = result && init_gl_version_1_0();
#endif
#ifdef GL_VERSION_1_1
    result = result && init_gl_version_1_1();
#endif
#ifdef GL_VERSION_1_2
    result = result && init_gl_version_1_2();
#endif
#ifdef GL_VERSION_1_3
    result = result && init_gl_version_1_3();
#endif
#ifdef GL_VERSION_1_4
    result = result && init_gl_version_1_4();
#endif
#ifdef GL_VERSION_1_5
    result = result && init_gl_version_1_5();
#endif
#ifdef GL_VERSION_2_0
    result = result && init_gl_version_2_0();
#endif
#ifdef GL_VERSION_2_1
    result = result && init_gl_version_2_1();
#endif
#ifdef GL_VERSION_3_0
    result = result && init_gl_version_3_0();
#endif
#ifdef GL_VERSION_3_1
    result = result && init_gl_version_3_1();
#endif
#ifdef GL_VERSION_3_2
    result = result && init_gl_version_3_2();
#endif
#ifdef GL_VERSION_3_3
    result = result && init_gl_version_3_3();
#endif
#ifdef GL_VERSION_4_0
    result = result && init_gl_version_4_0();
#endif
#ifdef GL_VERSION_4_1
    result = result && init_gl_version_4_1();
#endif
#ifdef GL_VERSION_4_2
    result = result && init_gl_version_4_2();
#endif
#ifdef GL_VERSION_4_3
    result = result && init_gl_version_4_3();
#endif
#ifdef GL_VERSION_4_4
    result = result && init_gl_version_4_4();
#endif
#ifdef GL_VERSION_4_5
    result = result && init_gl_version_4_5();
#endif
#ifdef GL_VERSION_4_6
    result = result && init_gl_version_4_6();
#endif

    return result;
}

#pragma endregion

} // namespace framework::graphic::gl
