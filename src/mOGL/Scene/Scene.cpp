#include "Scene.h"

using namespace mOGL;

Scene::Scene( std::string name )
{
	mName = name;

}
std::string	 Scene::getName( void )
{
	return mName;
}