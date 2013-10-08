#include "Vertex.h"

using namespace mOGL;

Vertex::Vertex()
{

}

Vertex::Vertex(size_t v_index, size_t n_index, size_t t_index, size_t m_index)
{
	v = v_index;
	n = n_index;
	t = t_index;
	m = m_index;
}