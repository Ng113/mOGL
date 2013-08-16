#include "GouraudShading.h"
#include "../../Scene.h"
#include "../../Object/ObjectManager.h"
#include "../../Camera/CameraManager.h"
#include "../../Light/LightManager.h"
#include "../../../ResourceLoader/Mesh/mesh.h"
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
}
void GouraudShading::_renderView( void )
{
	CameraManager* cameraMgr = mScene->cameraMgr;
}

void GouraudShading::_renderLight( void )
{
	LightManager* lightMgr = mScene->lightMgr;
}

void GouraudShading::_renderObject( void )
{
	ObjectManager* objMgr = mScene->objetMgr;
	for( int i = 0 ; i < objMgr->NumberOfObject() ; ++i )
	{
		Object* obj = objMgr->getObject( i );
		if( obj == NULL ) continue;
		mesh* objMesh = obj->getMeshPointer();
		
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
			
			glBegin(GL_TRIANGLES);
			for ( size_t j = 0 ; j < 3 ; ++j )
			{	
				glNormal3fv( objMesh->nList[ objMesh->faceList[i][j].n ].ptr );
				glVertex3fv( objMesh->vList[ objMesh->faceList[i][j].v].ptr );	
			}
			glEnd();
			glPopMatrix();
		}
	/////////////////////////////////////////////////////////////////////
	}
}