#include "GLFW/glfw3.h"
#include "cg.h"

int main()
{
	CG::Log::Init("CORE", "GLFWConf");
	GLFWwindow* window;

	if (!glfwInit())
		return -1;
	else
		CG_INFO("Init GLFW");

	//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	CG_INFO("The GLFW version is: {0}", glfwGetVersionString());

	window = glfwCreateWindow(640, 480, "Hello Window", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	//note(guoliang): Tell GLFW to make the context of our window the main context on the current thread.
	glfwMakeContextCurrent(window);
	CG_INFO("The OpenGL version is: {0} {1}", glGetString(GL_VENDOR), glGetString(GL_VERSION));
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		//note(guoliang): Set the background color of the window by oldschool method
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}
	
	glfwTerminate();
}
