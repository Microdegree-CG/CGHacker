#include "glpch.h"
#include "OpenGLDebug.h"

namespace GLCore::Utils {

	static DebugLogLevel s_DebugLogLevel = DebugLogLevel::HighAssert;

	void SetGLDebugLogLevel(DebugLogLevel level)
	{
		s_DebugLogLevel = level;
	}

	void OpenGLLogMessage(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
	{
		switch (severity)
		{
		case GL_DEBUG_SEVERITY_HIGH:
			if ((int)s_DebugLogLevel > 0)
			{
				CG_ERROR("[OpenGL Debug HIGH] {0}", message);
				if (s_DebugLogLevel == DebugLogLevel::HighAssert)
					GLCORE_ASSERT(false, "GL_DEBUG_SEVERITY_HIGH");
			}
			break;
		case GL_DEBUG_SEVERITY_MEDIUM:
			if ((int)s_DebugLogLevel > 2)
				CG_WARN("[OpenGL Debug MEDIUM] {0}", message);
			break;
		case GL_DEBUG_SEVERITY_LOW:
			if ((int)s_DebugLogLevel > 3)
				CG_INFO("[OpenGL Debug LOW] {0}", message);
			break;
		case GL_DEBUG_SEVERITY_NOTIFICATION:
			if ((int)s_DebugLogLevel > 4)
				CG_TRACE("[OpenGL Debug NOTIFICATION] {0}", message);
			break;
		}
	}

	void EnableGLDebugging()
	{
		glDebugMessageCallback(OpenGLLogMessage, nullptr);
		glEnable(GL_DEBUG_OUTPUT);
		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
	}

}