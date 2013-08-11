#ifndef __SCENEMANAGER_H__
#define __SCENEMANAGER_H__

#include <vector>
#include <string>

namespace mOGL
{
	class Scene;
	class SceneManager
	{
	public:
		SceneManager();
		~SceneManager();
		Scene*	addScene( std::string name );
		void		removeAllScene( void );
		bool		removeScene( std::string name );
		Scene*	getScene( std::string name );
		int		getSceneNumber( void );
	private:
		int								mSceneNum;
		std::vector< Scene* > mScenes;
	};
}

#endif