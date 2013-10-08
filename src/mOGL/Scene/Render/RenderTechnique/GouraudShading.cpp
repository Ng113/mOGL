#include "GouraudShading.h"
#include "../../Scene.h"
#include "../../Object/ObjectManager.h"
#include "../../Camera/CameraManager.h"
#include "../../Camera/Camera.h"
#include "../../Light/LightManager.h"
#include "../../../ResourceLoader/Mesh/Mesh.h"
#include <stdlib.h>
#include "glut.h"
using namespace mOGL;
 
GouraudShading::GouraudShading( Scene* scene) : RenderTechnique( scene )
{
	mRenderTechniqueID = GOURAUD_SHADING;
}

/*
	現在沒有
	1.texture
	2.rotation
*/
void GouraudShading::render()
{
	_renderView();
	_renderLight();
	_renderObject();

	glutSwapBuffers();
	glutPostRedisplay();
}
void GouraudShading::_renderView( void )
{
	CameraManager* cameraMgr = mScene->cameraMgr;
	Camera* camera = cameraMgr->getCamera();
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);      //清除用color
	glClearDepth(1.0f);                        // Depth Buffer (就是z buffer) Setup
	glEnable(GL_DEPTH_TEST);                   // Enables Depth Testing
	glDepthFunc(GL_LEQUAL);                    // The Type Of Depth Test To Do
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//這行把畫面清成黑色並且清除z buffer

	
	/*
	有些基本的東西像是 Viewport我還沒有開始做 改天需要補上

	glViewport(view_data->view_x, view_data->view_y, view_data->view_w, view_data->view_h);
	// projection transformation
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(view_data->fovy, (GLfloat)view_data->view_w/(GLfloat)view_data->view_h,view_data->dnear, view_data->dfar);
	// viewing and modeling transformation
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(	view_data->eye_x,view_data->eye_y,view_data->eye_z,// eye
			view_data->vat_x,view_data->vat_y,view_data->vat_z,     // center
			view_data->vup_x,view_data->vup_y,view_data->vup_z);    // up
	*/

	glViewport( 0 , 0 , 1024 , 768 );
	// projection transformation
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective( 45 , (GLfloat)1024/(GLfloat)768 , 5 , 1000 );
	// viewing and modeling transformation
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	
	mOGL::Vector3 cameraPos = camera->getPosition();
	mOGL::Vector3 cameraLookAt = camera->getDirection() + cameraPos;
	mOGL::Vector3 cameraUp = camera->getUpDirection();
	gluLookAt( (GLdouble)cameraPos.x , (GLdouble)cameraPos.y , (GLdouble)cameraPos.z ,// eye
			(GLdouble)cameraLookAt.x , (GLdouble)cameraLookAt.y , (GLdouble)cameraLookAt.z ,     // center
			(GLdouble)cameraUp.x , (GLdouble)cameraUp.y , (GLdouble)cameraUp.z );    // up
}

void GouraudShading::_renderLight( void )
{
	LightManager* lightMgr = mScene->lightMgr;


	//for test
	GLfloat light_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat light_diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat light_ambient[] = {0.1f, 0.1f, 0.1f, 1.0f};
    GLfloat light_position[] = {50.0f, 50.0f, 10.0f, 0.0f};

	 // enable lighting
    glEnable(GL_LIGHTING);
	//glDisable(GL_LIGHTING);
    // set light property
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
}

void GouraudShading::_renderObject( void )
{
	ObjectManager* objMgr = mScene->objetMgr;
	for( int i = 0 ; i < objMgr->NumberOfObject() ; ++i )
	{
		Object* obj = objMgr->getObject( i );
		if( obj == NULL ) continue;
		Mesh* objMesh = obj->getMeshPointer();
		
	/////////////////////////////////////////////////////////////////////
		for( size_t i = 0 ; i < objMesh->fTotal ; ++i )
		{
			glMaterialfv( GL_FRONT, GL_AMBIENT  , objMesh->mat[ objMesh->faceList[i][0].m ].Ka );
			glMaterialfv( GL_FRONT, GL_DIFFUSE  , objMesh->mat[objMesh->faceList[i][0].m ].Kd );
			glMaterialfv( GL_FRONT, GL_SPECULAR , objMesh->mat[objMesh->faceList[i][0].m ].Ks );
			glMaterialfv( GL_FRONT, GL_SHININESS, &objMesh->mat[objMesh->faceList[i][0].m ].Ns );

			glMatrixMode( GL_MODELVIEW );
			glPushMatrix();

			mOGL::Vector3 pos = obj->getPosition();
			glTranslatef( pos.x , pos.y , pos.z );
			//glRotatef(obj_data[nn]->rotate_x, 1.0, 0.0 , 0.0);
			//glRotatef(obj_data[nn]->rotate_y, 0.0, 1.0 , 0.0);
			
			float data[3];
			glBegin(GL_TRIANGLES);
			for ( size_t j = 0 ; j < 3 ; ++j )
			{	
				glNormal3fv( objMesh->nList[ objMesh->faceList[i][j].n ].ptr(data) );
				glVertex3fv( objMesh->vList[ objMesh->faceList[i][j].v].ptr(data) );	
			}
			glEnd();
			glPopMatrix();
		}
	/////////////////////////////////////////////////////////////////////
	}
}