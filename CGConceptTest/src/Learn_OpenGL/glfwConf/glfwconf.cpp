#include <GLFW/glfw3.h>
#include "cg.h"

void process_input(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

int main()
{
	CG::Log::Init("CORE", "GLFWConf");

	if (!glfwInit())
		return -1;
	else
		CG_INFO("Init GLFW");

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	CG_INFO("The GLFW version is: {0}", glfwGetVersionString());

	GLFWwindow* window = glfwCreateWindow(800, 600, "GLFW Test", NULL, NULL);
	if (!window)
	{
		CG_ERROR("Failed to create GLFW window");
		glfwTerminate();
		return -1;
	}

	// NOTE:(guoliang): Tell GLFW to make the context of our window the main context on the current thread.
	glfwMakeContextCurrent(window);
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
