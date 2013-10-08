#include "Example_1.h"

ExampleApp::ExampleApp( int argc, char *argv[] ) : mOGL::mOGLApplication( argc , argv )
{
	/*
	不應該這樣寫但是現在想不到解法
	以後會需要一個root來處理這個問題
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