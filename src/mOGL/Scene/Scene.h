#ifndef __SCENE_H__
#define __SCENE_H__

class ObjectManager;

namespace mOGL
{
	class Scene
	{
	public:
		Scene();
	private:
		ObjectManager*	mObjetMgr;
	};
}

#endif