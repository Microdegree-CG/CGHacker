#pragma once

#include <string>
#include <unordered_map>

struct ShaderSource
{
	std::string vectexShader;
	std::string fragmentShader;
};

class Shader
{
private:
	std::string m_FilePath;
	unsigned int m_RendererID;
	std::unordered_map<std::string, int>  m_UniformLocationCache;

public:
	Shader(const std::string& filepath);
	~Shader();

	void Bind() const;
	void Unbind() const;

	void setUniform4f(const std::string& name, float v0, float v1, float v2, float v3);

private:
	ShaderSource ParseShader(const std::string& filepath);
	unsigned int CompileShader(unsigned int type, const std::string& source);
	unsigned int CreateShader(const std::string& vs, const std::string& fs);

	unsigned int GetUniformLocation(const std::string& name);
};
