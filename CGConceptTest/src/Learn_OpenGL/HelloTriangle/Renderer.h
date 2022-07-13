#pragma once

#include "ver"

class Renderer
{
public:
	void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader);
};
