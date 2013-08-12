#ifndef __RESOURCELOADER_H__
#define __RESOURCELOADER_H__

namespace mOGL
{
	class MeshManager;
	class TextureManager;
	class ResourceLoader
	{
	public:
		static void initial(void);
	public:
		static MeshManager*		MeshMgr;
		static TextureManager*	TextureMgr;
	};
}

#endif