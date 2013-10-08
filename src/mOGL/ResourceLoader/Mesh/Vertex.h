#ifndef __VERTEX_H__
#define __VERTEX_H__

namespace mOGL
{
	class Vertex	
	{
		public:
			Vertex();
			Vertex(size_t v_index, size_t n_index, size_t t_index=0, size_t m_index=0);
		public:
			size_t v;		// vertex (index of vList)
			size_t n;		// normal (index of nList)
			size_t t;		// texture (index of tList)
			size_t m;		// material (index of material)
	};
}


#endif