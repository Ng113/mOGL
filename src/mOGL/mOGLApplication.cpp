#include "glew.h"
#include "glaux.h"
#include "wglew.h"
#include <time.h>
#include "mOGLApplication.h"

using namespace mOGL;

mOGLApplication* mOGL::mOGLApplication::nowFocus = NULL;

mOGL::mOGLApplication::mOGLApplication(int argc, char *argv[]) : width( 1024 ) ,height( 768 )
{
	getFocus();
	glutInit(&argc, argv);
	glutInitWindowSize( 1024 , 768 );
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutCreateWindow("mOGL Example");
	glewInit();
	glutDisplayFunc( FunPtrDisplay );
	glutKeyboardFunc( FunPtrKeyboard );
	glutReshapeFunc( FunPtrWindowReshape );
	glutMouseFunc( FunPtrMouseClick ); 
	glutMotionFunc( FunPtrMouseMove );
}

void mOGL::mOGLApplication::initial()
{
	
}

void mOGL::mOGLApplication::run()
{
	lastFrameTimer = time( NULL );
	glutMainLoop();
}

void mOGL::mOGLApplication::getFocus()
{
	nowFocus = this;
}

void mOGL::mOGLApplication::display()
{
	mOGL::mRenderMgr->render();
	float timeStep = time( NULL ) - lastFrameTimer ;
	update( timeStep );
}
void mOGL::mOGLApplication::keyboard(unsigned char key, int x, int y)
{

}
void mOGL::mOGLApplication::mouseClick(int button, int state, int x, int y)
{

}
void mOGL::mOGLApplication::mouseMove(int x, int y)
{

}
void	mOGL::mOGLApplication::windowReshape(GLsizei w, GLsizei h)
{
	width = w;
	height = h;
}
void mOGL::mOGLApplication::update( float timeSinceLastFrame )
{

}

void	mOGL::mOGLApplication::FunPtrDisplay( void )
{
	nowFocus->display();
}
void	mOGL::mOGLApplication::FunPtrKeyboard(unsigned char key, int x, int y)
{
	nowFocus->keyboard(key,x,y);
}
void	mOGL::mOGLApplication::FunPtrMouseClick(int button, int state, int x, int y)
{
	nowFocus->mouseClick( button , state , x , y );
}
void	mOGL::mOGLApplication::FunPtrMouseMove(int x, int y)
{
	nowFocus->mouseMove( x , y ); 
}
void	mOGL::mOGLApplication::FunPtrWindowReshape(GLsizei w, GLsizei h)
{
	nowFocus->windowReshape( w , h );
}