#ifndef __OBJECTMANAGER_H__
#define __OBJECTMANAGER_H__

#include <iostream>
#include <vector>
#include "Object.h"

namespace mOGL
{
	class ObjectManager
	{
		public:
			ObjectManager();
			~ObjectManager();
			bool						addObject(  std::string  meshName);
			bool						addObject(  std::string  meshName  , std::string objName );
			bool						reMoveObject( std::string objName );
			void						reMoveAllObject(void);
			mOGL::Object*	getObject( std::string objName );
			mOGL::Object*	getObject( int index );
			int						NumberOfObject(void);
		private:
		private:
			int												TotalNum;
			std::vector< mOGL::Object* >	objects;
	};
}
#endif