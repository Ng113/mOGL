#ifndef __CAMERAMANAGER_H__
#define __CAMERAMANAGER_H__

#include "../../math/mMath.h"
#include <string>
#include <vector>

namespace mOGL
{
	class Camera;
	class CameraManager
	{
		public:
			CameraManager();
			~CameraManager();
			Camera*	addCamera( std::string name );
			void			removeAllCamera( void );
			bool			removeCamera( std::string name );
			Camera*	getCamera( std::string name );
			int			getSceneNumber( void ) ;
		private:
			int									nCameraNum;
			std::vector< Camera* >	mCameras;
	};
}
#endif