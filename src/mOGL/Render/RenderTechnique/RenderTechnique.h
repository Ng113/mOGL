#ifndef __RENDERTECHNIQUE_H__
#define __RENDERTECHNIQUE_H__

namespace mOGL
{
	class RenderTechnique
	{
		public:
			typedef enum
			{
				PHONG_SHADING,
				RAY_TRACING,
				PHOTON_MAPPING
			} RENDERING_TECHNIQUE;
		public:
			RenderTechnique();
			virtual void render() =0;
		protected:
			RENDERING_TECHNIQUE mRenderTechniqueID;
	};
}

#endif