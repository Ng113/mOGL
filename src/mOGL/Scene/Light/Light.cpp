#include "Light.h"

using namespace mOGL;

Light::Light( std::string objName )
{
	mLightType = POINT_LIGHT;
	name = objName;
}
Light::Light( LIGHT_TYPE type , std::string objName )
{
	mLightType = type;
	name = objName;
}
bool Light::setLightType( Light::LIGHT_TYPE type)
{
	return true;
}
Light::LIGHT_TYPE Light::getLightType( void )
{
	return mLightType;
}
std::string	 Light::getName( void )
{
	return name;
}