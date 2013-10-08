#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <iostream>
#include "../../math/mMath.h"



namespace mOGL
{
	class Mesh;
	class Object
	{
		public:
			Object( std::string fileName , std::string objName  , int objID );
			~Object();
			void			setPosition( mOGL::Vector3 pos );
			void			setDirection( mOGL::Vector3 dir );
			void			setVisiable( bool v );
			void			setLocalLightCoefficient( float local_c );
			void			setReflectLightCoefficient( float reflect_c );
			void			setTransparentLightCoefficient( float transparent_c );
			mOGL::Vector3	getPosition(void);
			mOGL::Vector3	getDirection(void);
			std::string		getName(void);
			float			getLocalLightCoefficient(void);
			float			getReflectLightCoefficient(void);
			float			getTransparentLightCoefficient(void);
			bool			isVisiable(void);
			Mesh*			getMeshPointer(void);
		private:
			int				id;
			mOGL::Vector3	position;
			mOGL::Vector3	lookDirection;
			bool			visiable;
			std::string		meshName;
			std::string		name;
			float			localLightCoefficient;
			float			reflectLightCoefficient;
			float			transparentLightCoefficient;
			Mesh*			mMesh;
	};
}
#endif