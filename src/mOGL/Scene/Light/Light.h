#ifndef __LIGHT_H__
#define __LIGHT_H__

#include "../../Math/mMath.h"
#include <string>
/*
	���w��point light�������B�z
	���u����light function���|�b�o��
	�o�̥u�n�x�s�򥻸�T�N�i�H�F
	�]���Y�ϬO�P�@��type��light
	�w�藍�P��render�ޥ� �|�ݭn���P���B�z
	<�Yrender���a��n�������C��light���B�z�覡>
	�o�̪�light�O"�@�q"��concept
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