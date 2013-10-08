#ifndef __SCENE_H__
#define __SCENE_H__

#include <string>

namespace mOGL
{
	class ObjectManager;
	class LightManager;
	class CameraManager;
	class Scene
	{
	public:
		Scene( std::string name );
		std::string		getName( void );
	public:
		ObjectManager*	objetMgr;
		LightManager*	lightMgr;
		CameraManager*	cameraMgr;
	private:
		std::string mName;
	};
}

#endif