#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "../../math/mMath.h"
#include <string>

namespace mOGL
{
	class Camera
	{
		public:
			Camera( std::string name );
			Camera( std::string name , mOGL::Vector3	position , mOGL::Vector3	lookDirection , mOGL::Vector3	upDirection);
			void						move( mOGL::Vector3 translation );
			bool						lookAt( mOGL::Vector3 point );
			void						rotation( mOGL::Vector3 axis , float degree );
			void						setPosition( mOGL::Vector3 pos );
			bool						setDirection( mOGL::Vector3 direction );
			bool						setUpDirection( mOGL::Vector3 upDirection );
			std::string				getName( void );
			mOGL::Vector3	getPosition();
			mOGL::Vector3	getDirection();
			mOGL::Vector3	getUpDirection();
		private:
			bool	_reCalculateUpDirection();
		private:
			std::string				mName;
			mOGL::Vector3	position;
			mOGL::Vector3	lookDirection;
			mOGL::Vector3	upDirection;
			float fovy;
			float nearPlane;
			float farPlane;
			mOGL::Vector2 windowPos;
			mOGL::Vector2 windowLenght;
	};
}
#endif