#include "SceneManager.h"
#include "Scene.h"

using namespace mOGL;

SceneManager::SceneManager()
{
	mSceneNum = 0;
}

SceneManager::~SceneManager()
{
	for(int i=0;i<mScenes.size();++i)
	{
		if( mScenes[i] == NULL ) continue;
		delete( mScenes[i] );
	}
}

Scene* SceneManager::addScene( std::string name )
{
	for(int i=0;i<mScenes.size();++i)
	{
		if( mScenes[i] != NULL ) continue;
		mScenes[i] = new Scene( name );
		mSceneNum ++;
		return mScenes[i];
	}

	mScenes.push_back( new Scene( name ) );
	mSceneNum ++;
	return mScenes[ mScenes.size()-1 ];
}

void	SceneManager::removeAllScene( void )
{
	for(int i=0;i<mScenes.size();++i)
	{
		if( mScenes[i] == NULL ) continue;
		delete( mScenes[i] );
		mScenes[i] = NULL;
	}
	mSceneNum = 0;
}

bool	SceneManager::removeScene( std::string name )
{
	for(int i=0;i<mScenes.size();++i)
	{
		if( mScenes[i] == NULL ) continue;
		if( mScenes[i]->getName() != name ) continue;
		
		delete( mScenes[i] );
		mScenes[i] = NULL;
		--mSceneNum;
		return  true;
	}

	return false;
}

Scene*	SceneManager::getScene( std::string name )
{
	for(int i=0;i<mScenes.size();++i)
	{
		if( mScenes[i] == NULL ) continue;
		if( mScenes[i]->getName() == name )
			return  mScenes[i];
	}

	return NULL;
}

int	SceneManager::getSceneNumber( void )
{
	return mSceneNum;
}