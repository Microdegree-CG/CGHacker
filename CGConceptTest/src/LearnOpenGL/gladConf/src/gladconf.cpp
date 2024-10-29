#if defined(GLFW_INCLUDE_NONE)
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#else
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#endif

#include "GLCore/Core/log.h"
#include <iostream>

void process_input(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

int main()
{

	GLCore::Log::Init();
	glfwInit();

	// Create window use glfw

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	CG_INFO("The GLFW version is: {0}", glfwGetVersionString());

	GLFWwindow* window = glfwCreateWindow(800, 600, "GLAD Test", NULL, NULL);
	if (window == NULL)
	{
		CG_ERROR("Failed to create GLFW window");
		glfwTerminate();
		return -1;
	}

	// NOTE:(guoliang): Tell GLFW to make the context of our window the main context on the current thread.
	// NOTE:(guoliang): Must call before gladLoadGLLoader
	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		CG_ERROR("Failed to initalize GLAD");
		return -1;
	}

	CG_INFO("The OpenGL version is: {0} {1}", glGetString(GL_VENDOR), glGetString(GL_VERSION));

	while (!glfwWindowShouldClose(window))
	{
		process_input(window);

		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
}
