#ifndef __LIGHTMANAGER_H__
#define __LIGHTMANAGER_H__

#include <stdlib.h>
#include <vector>
#include "Light.h"

namespace mOGL
{
	class LightManager
	{
	public:
		LightManager();
		Light*	addLight( Light::LIGHT_TYPE type , std::string name );
		bool		destoryAll( void );
		bool		destoryLight( Light* light );
		bool		destoryLight( std::string name );
	private:
		std::vector<Light> mLights;
	};
}

#endif