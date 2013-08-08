#include "ObjectManager.h"
#include "../../String/String.h"

using namespace mOGL;

ObjectManager::ObjectManager()
{
	TotalNum = 0;
}

bool ObjectManager::addObject(  std::string  meshName)
{
	return addObject(  meshName  , "" );
}
bool ObjectManager::addObject(  std::string  meshName  , std::string objName )
{	
	bool autoNaming = false;
	if( objName == "" ) autoNaming = true;

	int i;
	for( i=0;i< (signed)objects.size();++i)
	{
		if( objects[i] != NULL) continue;
		
		mOGL::Object* newObj;
		if( autoNaming ) newObj = new  mOGL::Object(meshName, (String)"AutoNamingObject_" + i  ,i);
		else newObj = new  mOGL::Object(meshName, objName ,i);
		
		objects[i] = newObj;
		++TotalNum;
		return true;
	}

	mOGL::Object* newObj;
	if( autoNaming ) newObj = new  mOGL::Object(meshName, (String)"AutoNamingObject_" + i  ,i);
	else newObj = new  mOGL::Object(meshName, objName ,i);
	objects.push_back( newObj );
	++TotalNum;

	return true;
}
bool ObjectManager::reMoveObject( std::string objName )
{
	for( int i=0 ; i < (signed)objects.size() ; ++i )
	{
		if( objects[i]->getName() != objName ) continue;

		delete( objects[i] );
		objects[i] = NULL;
		--TotalNum;
		return true;
	}
	return false;
}
void ObjectManager::reMoveAllObject(void)
{
	for( int i=0 ; i < (signed)objects.size() ; ++i )
	{
		delete( objects[i] );
	}
	objects.clear();
	TotalNum = 0;
}
mOGL::Object* ObjectManager::getObject( std::string objName )
{
	for( int i=0 ; i < (signed)objects.size() ; ++i )
	{
		if( objects[i]->getName() != objName ) continue;
		return objects[i];
	}
	return NULL;
}
int ObjectManager::NumberOfObject(void)
{
	return TotalNum;
}

mOGL::Object* ObjectManager::getObject( int index )
{
	if( index < 0 || index >= TotalNum ) return NULL;

	return objects[index] ;
}