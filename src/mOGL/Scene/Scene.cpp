#include "Scene.h"
#include "Object\ObjectManager.h"
#include "Light\LightManager.h"
#include "Camera\CameraManager.h"

using namespace mOGL;

Scene::Scene( std::string name )
{
	mName = name;

	cameraMgr = new CameraManager();
	lightMgr = new LightManager();
	objetMgr = new ObjectManager();
}

std::string	 Scene::getName( void )
{
	return mName;
}