#ifndef __FACE_H__
#define __FACE_H__

#include "Vertex.h"

namespace mOGL
{
	class Face
	{

		public:
			Face(Vertex &v1, Vertex &v2, Vertex &v3);
			Vertex& operator[](size_t index);
		public:
			Vertex v[3];		// 3 vertex for each face
	};
}

#endif