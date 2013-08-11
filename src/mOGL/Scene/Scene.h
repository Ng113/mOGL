#ifndef __SCENE_H__
#define __SCENE_H__

class ObjectManager;
class LightManager;

#include <string>

namespace mOGL
{
	class Scene
	{
	public:
		Scene( std::string name );
		std::string		getName( void );
	public:
		ObjectManager*	objetMgr;
		LightManager*    lightMgr;
	private:
		std::string mName;
	};
}

#endif