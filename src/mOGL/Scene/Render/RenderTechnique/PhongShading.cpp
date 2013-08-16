#include "PhongShading.h"
#include "../../Scene.h"
#include "../../Object/ObjectManager.h"
#include "../../../ResourceLoader/Mesh/mesh.h"
#include "glut.h"
using namespace mOGL;
 
PhongShading::PhongShading( Scene* scene) : RenderTechnique( scene )
{
	mRenderTechniqueID = PHONG_SHADING;
}

/*
	現在沒有
	1.texture
	2.rotation
*/
void PhongShading::render()
{
	_renderView();
	_renderLight();
	_renderObject();
}
void PhongShading::_renderView( void )
{

}

void PhongShading::_renderLight( void )
{

}

void PhongShading::_renderObject( void )
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