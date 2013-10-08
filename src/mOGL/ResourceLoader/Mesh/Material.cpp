#include "Material.h"

using namespace mOGL;

Material::Material()
{ 
	for (size_t i=0;i<4;i++)
		Ka[i] = Kd[i] = Ks[i] = 1;
	Ns = 0;
}