#include "Example_1.h"

ExampleApp::ExampleApp( int argc, char *argv[] ) : mOGL::mOGLApplication( argc , argv )
{
	/*
	�����ӳo�˼g���O�{�b�Q����Ѫk
	�H��|�ݭn�@��root�ӳB�z�o�Ӱ��D
	*/
	createScene();
}

void ExampleApp::createScene( void )
{
	mMainScene->objetMgr->addObject("ball.obj","obj_1");
	mOGL::Object* object = mMainScene->objetMgr->getObject("obj_1");
	object->setPosition( mOGL::Vector3(0,0,0) );

	mMainScene->objetMgr->addObject("box.obj","obj_2");
	object = mMainScene->objetMgr->getObject("obj_2");
	object->setPosition( mOGL::Vector3(0,-80,0) );

	mOGL::Vector3 pos = mMainCamera->getPosition();
	mMainCamera->setPosition( pos + mOGL::Vector3(0,20,80) );
	mMainCamera->setDirection( mOGL::Vector3(0,20,0) - mOGL::Vector3(0,20,80) );
}