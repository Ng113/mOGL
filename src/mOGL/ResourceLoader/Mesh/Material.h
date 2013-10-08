#ifndef __MATERIAL_H__
#define __MATERIAL_H__

namespace mOGL
{
	class Material
	{
		public:
			Material();
		public:
			float Ka[4];
			float Kd[4];
			float Ks[4];
			float Ns;		// shiness
	};
}


#endif