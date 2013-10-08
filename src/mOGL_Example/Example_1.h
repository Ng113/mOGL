#include "../mOGL/mOGLApplication.h"

class ExampleApp : public mOGL::mOGLApplication
{
	public:
		ExampleApp( int argc, char *argv[] );
	protected:
		virtual void createScene( void );
};