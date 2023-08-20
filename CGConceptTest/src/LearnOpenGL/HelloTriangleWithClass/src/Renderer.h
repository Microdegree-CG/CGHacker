#pragma once

#include "ebo/IndexBuffer.h"
#include "shader/Shader.h"
#include "vao/VertexArray.h"

class Renderer {
public:
  void Clear() const;
  void Draw(const VertexArray &va, const IndexBuffer &ib,
            const Shader &shader) const;
};
