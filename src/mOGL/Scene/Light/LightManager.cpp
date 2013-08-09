#include "LightManager.h"
#include "../../String/String.h"
using namespace mOGL;

LightManager::LightManager()
{

}
Light*	LightManager::addLight( Light::LIGHT_TYPE type , std::string name )
{
	bool autoNaming;
	Light* newLight;
	if( name == "" ) autoNaming = true;
	else autoNaming = false;
	
	for( int i = 0 ; i < mLights.size() ; ++i )
	{
		if( mLights[i] != NULL ) continue ;
		
		if( autoNaming ) name = (String)"AutoNamingLight_" + i ;
		mLights[i] = new Light( type , name);
		
		return mLights[i] ;
	}

	if( autoNaming ) name = (String)"AutoNamingLight_" + (signed)mLights.size() ;
	newLight = new Light( type , name);
	mLights.push_back( newLight );
	return newLight;
}
void LightManager::destoryAll( void )
{
	for( int i = 0 ; i < mLights.size() ; ++i )
	{
		if( mLights[i] != NULL ) continue ;
		delete( mLights[i] );
		mLights[i] = NULL;
	}
}
bool LightManager::destoryLight( Light* light )
{
	for( int i = 0 ; i < mLights.size() ; ++i )
	{
		if( mLights[i] != light ) continue ;
		delete( mLights[i] );
		mLights[i] = NULL;

		return true;
	}
	return false;
}
bool LightManager::destoryLight( std::string name )
{
	for( int i = 0 ; i < mLights.size() ; ++i )
	{
		if( mLights[i]->getName() != name ) continue ;
		delete( mLights[i] );
		mLights[i] = NULL;

		return true;
	}
	return false;
}