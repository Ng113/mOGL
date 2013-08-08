#include "Light.h"

using namespace mOGL;

Light::Light()
{
	mLightType = POINT_LIGHT;
}
Light::Light( LIGHT_TYPE type )
{

}
bool Light::setLightType( Light::LIGHT_TYPE type)
{
	return true;
}
Light::LIGHT_TYPE Light::getLightType( void )
{
	return mLightType;
}