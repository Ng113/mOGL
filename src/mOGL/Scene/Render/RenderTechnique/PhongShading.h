#ifndef __PHONGSHADING_H__
#define __PHONGSHADING_H__

#include "RenderTechnique.h"

namespace mOGL
{
	class PhongShading : public RenderTechnique
	{
		public:
			PhongShading( Scene* scene);
			void render( void );
		private:
			void _renderView( void );
			void _renderLight( void );
			void _renderObject( void );
		private:
			
	};
}

#endif 