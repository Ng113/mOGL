#ifndef __RENDERTECHNIQUE_H__
#define __RENDERTECHNIQUE_H__

namespace mOGL
{
	class Scene;
	class RenderTechnique
	{
		public:
			typedef enum
			{
				GOURAUD_SHADING,
				PHONG_SHADING,
				RAY_TRACING,
				PHOTON_MAPPING
			} RENDERING_TECHNIQUE;
		public:
			RenderTechnique( Scene* scene );
			virtual void render() =0;
		protected:
			RENDERING_TECHNIQUE	mRenderTechniqueID;
			Scene*										mScene;
	};
}

#endif