#if defined(GLFW_INCLUDE_NONE)
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#else
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#endif

#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

#include "Renderer.h"

#include <iostream>
#include "cg.h"


int main()
{
	CG::Log::Init("Core", "Triangle","HelloTriangle.log");
	GLFWwindow* window{ nullptr };

	if (!glfwInit())
	{
		std::cout << "GLFW init failed!" << std::endl;
		return -1;
	}

	CG_INFO("The GLFW version is: {0}", glfwGetVersionString());

	window = glfwCreateWindow(800, 600, "Hello Triangle", nullptr, nullptr);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initalize GLAD" << std::endl;
		return -1;
	}

	CG_INFO("The OpenGL version is: {0} {1}", glGetString(GL_VENDOR), glGetString(GL_VERSION));
	float vertices[] = {
		0.5f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f ,
	};

	unsigned int indices[] = {
		0, 1, 3,
		1, 2, 3
	};

	VertexArray va;
	VertexBuffer vb(vertices, 4 * 3 * sizeof(float));

	VertexBufferLayout layout;
	layout.Push<float>(3);
	va.AddBuffer(vb, layout);

	IndexBuffer ib(indices, 6);


	float timeValue = glfwGetTime();
	float greenValue = sin(timeValue) / 2.0f + 0.5f;
	Shader shader("res/shaders/Basic.shader");

	va.Unbind();
	vb.Unbind();
	ib.Unbind();
	shader.Unbind();


	Renderer renderer;
	while (!glfwWindowShouldClose(window))
	{
		renderer.Clear();
		shader.Bind();
		shader.setUniform4f("u_Color",0.0f, greenValue, 0.0f, 1.0f);
		renderer.Draw(va, ib, shader);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}

