#include "RenderManager.h"
#include <stdlib.h>

using namespace mOGL;

RenderManager::RenderManager()
{
	mRenderTechnique = NULL;
	setRenderingTechnique( RenderTechnique::PHONG_SHADING );
}
void RenderManager::render()
{

}
void RenderManager::setRenderingTechnique( RenderTechnique::RENDERING_TECHNIQUE tec )
{
	if( mRenderTechnique != NULL ) delete( mRenderTechnique );
	
	mRenderTechniqueID = tec;
	switch(mRenderTechniqueID)
	{
	case RenderTechnique::PHONG_SHADING:
		break;
	case RenderTechnique::RAY_TRACING:
		break;
	case RenderTechnique::PHOTON_MAPPING:
		break;
	}
	mRenderTechniqueID = tec;
	
}
RenderTechnique::RENDERING_TECHNIQUE RenderManager::getRenderingTechnique( void )
{
	return mRenderTechniqueID;
}