#ifndef __MESH_H__
#define __MESH_H__

#include <stdio.h>

#include <map>
#include <vector>
#include <string>

#include "../../Math/Vector/Vector3.h"
#include "Material.h"
#include "Face.h"
#include "Vertex.h"

namespace mOGL
{

	class Mesh  
	{
		public:
			Mesh();
			Mesh(const char* obj_file);
			virtual ~Mesh();
			void	LoadMesh(std::string scene_file);
			void	Init(const char* obj_file);

		public:
			FILE							*scene, *texture;
			std::string						s_file, t_file;
			char							mat_file[256];		// matetial file name

			size_t							matTotal;	// total material 
			std::map<std::string,size_t>	matMap;		// matMap[material_name] = material_ID
			Material						mat[100];	// material ID (每個 mesh 最多有 100 種 material)	

			std::vector<Vector3>			vList;		// Vertex List (Position) - world cord.
			std::vector<Vector3>			nList;		// Normal List
			std::vector<Vector3>			tList;		// Texture List
			std::vector<Face>				faceList;	// Face List

			size_t	vTotal, tTotal, nTotal, fTotal;

		private:
			void	LoadMtl(std::string tex_file);



	};

}



#endif
