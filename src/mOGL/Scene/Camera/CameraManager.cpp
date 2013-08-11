#include "CameraManager.h"
#include "Camera.h"
#include <stdlib.h>

using namespace mOGL;

CameraManager::CameraManager()
{
	nCameraNum = 0;
}

CameraManager::~CameraManager()
{
	removeAllCamera();
}

Camera*	CameraManager::addCamera( std::string name )
{
	for(int i=0;i<mCameras.size();++i)
	{
		if( mCameras[i] != NULL ) continue;
		mCameras[i] = new Camera( name );
		++nCameraNum;
		return mCameras[i];
	}

	mCameras.push_back( new Camera( name ) );
	++nCameraNum;
	return mCameras[ mCameras.size()-1 ];
}

void	CameraManager::removeAllCamera( void )
{
	for(int i=0;i<mCameras.size();++i)
	{
		if( mCameras[i] == NULL ) continue;
		delete( mCameras[i] );
		mCameras[i] = NULL;
	}
	nCameraNum = 0;
}

bool CameraManager::removeCamera( std::string name )
{
	for(int i=0;i<mCameras.size();++i)
	{
		if( mCameras[i] == NULL ) continue;
		if( mCameras[i]->getName() != name ) continue;
		
		delete( mCameras[i] );
		mCameras[i] = NULL;
		--nCameraNum;
		return  true;
	}

	return false;
}

Camera* CameraManager::getCamera( std::string name )
{
	for(int i=0;i<mCameras.size();++i)
	{
		if( mCameras[i] == NULL ) continue;
		if( mCameras[i]->getName() == name )
			return  mCameras[i];
	}

	return NULL;
}

int	CameraManager::getSceneNumber( void )
{
	return nCameraNum;
}