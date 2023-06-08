#if defined(GLFW_INCLUDE_NONE)
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#else
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#endif

#include "cg.h"

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, 400, 300);
}

void process_input(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

int main()
{

	CG::Log::Init("Core", "GladConf");
	glfwInit();

	// Create window use glfw

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	CG_INFO("The GLFW version is: {0}", glfwGetVersionString());

	GLFWwindow* window = glfwCreateWindow(800, 600, "Glad Test", NULL, NULL);
	if (window == NULL)
	{
		CG_ERROR("Failed to create GLFW window");
		glfwTerminate();
		return -1;
	}

	// Create opengl context
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		CG_ERROR("Failed to initalize GLAD");
		return -1;
	}

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	CG_INFO("The OpenGL version is: {0} {1}", glGetString(GL_VENDOR), glGetString(GL_VERSION));

	while (!glfwWindowShouldClose(window))
	{
		process_input(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
}
