#ifndef __RENDERMANAGER_H__
#define __RENDERMANAGER_H__

#include "RenderTechnique\RenderTechnique.h"

namespace mOGL
{
	class RenderManager
	{
		public:
			RenderManager();
			void render();
			void setRenderingTechnique( RenderTechnique::RENDERING_TECHNIQUE tec );
			RenderTechnique::RENDERING_TECHNIQUE getRenderingTechnique( void );
		private:
			RenderTechnique::RENDERING_TECHNIQUE	mRenderTechniqueID;
			RenderTechnique*													mRenderTechnique;
	};
}

#endif