#ifndef __SCENE_H__
#define __SCENE_H__

class ObjectManager;
class LightManager;

namespace mOGL
{
	class Scene
	{
	public:
		Scene();
		ObjectManager*	objetMgr;
		LightManager*    lightMgr;
	};
}

#endif