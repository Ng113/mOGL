#include "ResourceLoader.h"
#include "Mesh\MeshManager.h"
#include "Texture\TextureManager.h"
#include <string>

using namespace mOGL;

MeshManager* ResourceLoader::MeshMgr = NULL;
TextureManager* ResourceLoader::TextureMgr = NULL;

void ResourceLoader::initial(void)
{
	MeshMgr = new MeshManager();
	TextureMgr = new TextureManager();
}