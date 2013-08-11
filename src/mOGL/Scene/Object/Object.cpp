#include "Object.h"
#include "Mesh\mesh.h"

using namespace mOGL;

/*
	這裡才知道為何Ogre會需要用到Mesh這樣的東西
	因為不用每load一個物件就重讀一次擋案，不過目前先不做這個部分。
*/
Object::Object( std::string fileName , std::string objName ,int objID)
{
	id = objID;
	mMesh = new mesh( fileName.c_str() );
	position = mOGL::Vector3(0.0,0.0,0.0);
	lookDirection = mOGL::Vector3(0.0,0.0,1.0);
	visiable = true;
	meshName = fileName;
	localLightCoefficient = 1;
	reflectLightCoefficient = 1;
	transparentLightCoefficient = 0.0;
	name = objName;
}
Object::~Object()
{
	delete( mMesh );
}
void Object::setPosition( mOGL::Vector3 pos )
{
	position = pos;
}
void Object::setDirection( mOGL::Vector3 dir )
{
	lookDirection = dir;
}
void Object::setVisiable( bool v )
{
	visiable = v;
}
void Object::setLocalLightCoefficient( float local_c )
{
	localLightCoefficient = local_c;
}
void Object::setReflectLightCoefficient( float reflect_c )
{
	reflectLightCoefficient = reflect_c;
}
void Object::setTransparentLightCoefficient( float transparent_c )
{
	transparentLightCoefficient = transparent_c;
}
mOGL::Vector3 Object::getPosition(void)
{
	return position;
}
mOGL::Vector3 Object::getDirection(void)
{
	return lookDirection;
}
std::string Object::getName(void)
{
	return name;
}
float	Object::getLocalLightCoefficient(void)
{
	return localLightCoefficient;
}
float	Object::getReflectLightCoefficient(void)
{
	return reflectLightCoefficient;
}
float Object::getTransparentLightCoefficient(void)
{
	return transparentLightCoefficient;
}
bool Object::isVisiable(void)
{
	return visiable;
}

mesh* Object::getMeshPointer(void)
{
	return mMesh;
}