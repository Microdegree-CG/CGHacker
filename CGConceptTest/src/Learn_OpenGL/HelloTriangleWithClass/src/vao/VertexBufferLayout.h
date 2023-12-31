#pragma once
#include <vector>
#include <glad/glad.h>

struct VertexBufferElement
{
	unsigned int type;
	unsigned int count;
	unsigned char normalized;

	static unsigned int GetSizeOfType(unsigned int type)
	{
		switch (type)
		{
			case GL_FLOAT: 
				return 4;
			case GL_UNSIGNED_INT: 
				return 4;
			case GL_UNSIGNED_BYTE: 
				return 1;
		}
		return 0;
	}
};


class VertexBufferLayout
{
private:
	std::vector<VertexBufferElement> m_Element;
	unsigned int m_Stride;

public:
	VertexBufferLayout()
		:m_Stride(0)
	{

	}

	template<typename T>
	void Push(unsigned int count)
	{
		static_assert(false);
	}

	//note(guoliang): count means the every vertex contains data number
	template<>
	void Push<float>(unsigned int count)
	{
		m_Element.push_back({ GL_FLOAT, count, GL_FALSE });
		m_Stride += VertexBufferElement::GetSizeOfType(GL_FLOAT) * count;
	}

	template<>
	void Push<unsigned int>(unsigned int count)
	{
		m_Element.push_back({ GL_UNSIGNED_INT, count, GL_TRUE });
		m_Stride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT) * count;
	}

	template<>
	void Push<unsigned char>(unsigned int count)
	{
		m_Element.push_back({ GL_UNSIGNED_BYTE, count, GL_FALSE });
		m_Stride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE) * count;
	}

	inline const std::vector<VertexBufferElement> GetElement() const { return m_Element; }
	inline unsigned int GetStride() const { return m_Stride; }
};

