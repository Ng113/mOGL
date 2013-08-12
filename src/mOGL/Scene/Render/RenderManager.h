#ifndef __RENDERMANAGER_H__
#define __RENDERMANAGER_H__

#include "RenderTechnique\RenderTechnique.h"

namespace mOGL
{
	class Scene;
	class RenderManager
	{
		public:
			RenderManager();
			void		render();
			void		setRenderingTechnique( RenderTechnique::RENDERING_TECHNIQUE tec );
			void		setRenderScene( Scene* scene );
			Scene*	getRenderScene( void );
			RenderTechnique::RENDERING_TECHNIQUE getRenderingTechnique( void );
		private:
			RenderTechnique::RENDERING_TECHNIQUE	mRenderTechniqueID;
			RenderTechnique*													mRenderTechnique;
			Scene*																		mRenderScene;
	};
}

#endif