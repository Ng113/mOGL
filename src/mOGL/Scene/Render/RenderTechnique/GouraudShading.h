#ifndef __GOURAUDSHADING_H__
#define __GOURAUDSHADING_H__

#include "RenderTechnique.h"

namespace mOGL
{
	class GouraudShading : public RenderTechnique
	{
		public:
			GouraudShading( Scene* scene);
			void render( void );
		private:
			void _renderView( void );
			void _renderLight( void );
			void _renderObject( void );
		private:
			
	};
}

#endif 