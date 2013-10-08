#include "Face.h"

using namespace mOGL;

Face::Face(Vertex &v1, Vertex &v2, Vertex &v3) 
{
	v[0] = v1; 
	v[1] = v2;
	v[2] = v3;
}

Vertex& Face::operator[](size_t index)
{
	return v[index];
}