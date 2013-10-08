#include "RenderTechnique.h"
#include "../../Scene.h"
using namespace mOGL;

RenderTechnique::RenderTechnique( Scene* scene )
{
	mScene = scene;
}

void RenderTechnique::setRenderScene( Scene* scene )
{
	mScene = scene;
}