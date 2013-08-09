#ifndef __MOGLAPPLICATION_H__
#define __MOGLAPPLICATION_H__

#include "glut.h"
#include "mOGLData.h"
#include "mOGL.h"

namespace mOGL
{

	class mOGLApplication
	{
		public:
			mOGLApplication(int argc, char *argv[]);
			void getFocus();
			void	run();
		protected:
			virtual void initial();
			virtual void	keyboard(unsigned char key, int x, int y);
			virtual void	mouseClick(int button, int state, int x, int y);
			virtual void	mouseMove(int x, int y);
			virtual void	windowReshape(GLsizei w, GLsizei h);
			virtual void update( float timeSinceLastFrame );
		protected:
			unsigned int width , height ;
		private:
			static void	FunPtrDisplay( void );
			static void	FunPtrKeyboard(unsigned char key, int x, int y);
			static void	FunPtrMouseClick(int button, int state, int x, int y);
			static void	FunPtrMouseMove(int x, int y);
			static void	FunPtrWindowReshape(GLsizei w, GLsizei h);
			static mOGLApplication*	nowFocus; 

			void	display( void );
		private:
			float	lastFrameTimer;
	};

}

#endif