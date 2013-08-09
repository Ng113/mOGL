#ifndef __LIGHT_H__
#define __LIGHT_H__

#include "../../Math/mMath.h"
#include <string>
/*
	先針對point light的部分處理
	其實真正的light function不會在這裡
	這裡只要儲存基本資訊就可以了
	因為即使是同一種type的light
	針對不同的render技巧 會需要不同的處理
	<即render的地方要有對應每種light的處理方式>
	這裡的light是"共通"的concept
*/

namespace mOGL
{
	class Light
	{
		public:
			typedef enum
			{
				POINT_LIGHT,
				AMBIENT_LIGHT,
				DIRECTIONAL_LIGHT,
				SPOTLIGHT,
			}LIGHT_TYPE;
		public:
			Light( std::string objName );
			Light( LIGHT_TYPE type , std::string objName );
			bool					setLightType( LIGHT_TYPE type);
			LIGHT_TYPE	getLightType( void );
			std::string			getName( void );
		protected:
			std::string				name;
			LIGHT_TYPE		mLightType;
			mOGL::Vector3	position;
			mOGL::Vector3	direction;
	};
}

#endif