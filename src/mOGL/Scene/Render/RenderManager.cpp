#include "RenderManager.h"
#include <stdlib.h>

#include "Render.h"

using namespace mOGL;

RenderManager::RenderManager()
{
	mRenderTechnique = NULL;
	mRenderScene	= NULL;
	setRenderingTechnique( RenderTechnique::GOURAUD_SHADING );
}
void RenderManager::render()
{
	if( mRenderTechnique == NULL ) return ;

	mRenderTechnique->render();
}
void RenderManager::setRenderingTechnique( RenderTechnique::RENDERING_TECHNIQUE tec )
{
	if( mRenderTechnique != NULL ) delete( mRenderTechnique );
	
	mRenderTechniqueID = tec;
	switch(mRenderTechniqueID)
	{
	case RenderTechnique::GOURAUD_SHADING:
		mRenderTechnique = new GouraudShading( getRenderScene() );
		break;
	case RenderTechnique::PHONG_SHADING:
		break;
	case RenderTechnique::RAY_TRACING:
		break;
	case RenderTechnique::PHOTON_MAPPING:
		break;
	}
}
void	RenderManager::setRenderScene( Scene* scene )
{
	mRenderScene = scene;
	mRenderTechnique->setRenderScene( scene );
}

Scene*	RenderManager::getRenderScene( void )
{
	return mRenderScene;
}

RenderTechnique::RENDERING_TECHNIQUE RenderManager::getRenderingTechnique( void )
{
	return mRenderTechniqueID;
}