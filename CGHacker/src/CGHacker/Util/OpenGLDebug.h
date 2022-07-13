#pragma once

#include <glad/glad.h>
#include <CGHacker/Core/Log.h>

namespace CG::Utils 
{
	enum class DebugLogLevel 
	{
		None = 0,
		HighAssert = 1,
		High = 2,
		Medium = 3,
		Low = 4,
		Notification = 5
	};

	void EnableDebugging();
	void SetGLDebugLogLevel(DebugLogLevel level);
	void OpenGLLogMessage(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);
}
