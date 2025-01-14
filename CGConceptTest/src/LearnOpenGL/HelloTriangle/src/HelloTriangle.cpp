#if defined(GLFW_INCLUDE_NONE)
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#else
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#endif

#include "GLCore/Core/Log.h"
#include <iostream>

int main()
{
	GLCore::Log::Init();
	GLFWwindow* window{ nullptr };

	if (!glfwInit())
	{
		CG_ERROR("GLFW init failed!");
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
		CG_ERROR("Failed to initalize GLAD");
		return -1;
	}

	CG_INFO("The OpenGL version is: {0} {1}", glGetString(GL_VENDOR), glGetString(GL_VERSION));


	const char* vertexShaderSource =
		"#version 330 core\n                                                \
                    layout (location = 0) in vec3 aPos;\n                               \
                    \n                                                                  \
                    void main()\n                                                       \
                    {\n                                                                 \
                        gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n              \
                    }\n\0";

	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	const char* fragmentShaderSource =
		"#version 330 core\n                                                \
                    out vec4 FragColor;\n                                               \
                    \n                                                                  \
                    void main()\n                                                       \
                    {\n                                                                 \
                        FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n                     \
                    }\n\0";

	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	float vertices[] = {
			 0.5f,  0.5f, 0.0f,  // top right
			 0.5f, -0.5f, 0.0f,  // bottom right
			-0.5f, -0.5f, 0.0f,  // bottom left
			-0.5f,  0.5f, 0.0f   // top left 
	};
	unsigned int indices[] = {  // note that we start from 0!
		0, 1, 3,  // first Triangle
		1, 2, 3   // second Triangle
	};

	unsigned int vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	unsigned int vbo;
	glGenBuffers(1, &vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	unsigned int ebo;
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shaderProgram);
		glBindVertexArray(vao);

		//glDrawArrays(GL_TRIANGLES,0,3);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ebo);
	glDeleteProgram(shaderProgram);

	glfwTerminate();

	return 0;
}

