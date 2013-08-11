#include "PhongShading.h"
#include "../../mOGLData.h"
#include "../../Scene/Object/ObjectManager.h"
#include "../../Scene/Object/Mesh/mesh.h"
#include "glut.h"
using namespace mOGL;

PhongShading::PhongShading()
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
	for( int i = 0 ; i < mOGL::mObjetMgr->NumberOfObject() ; ++i )
	{
		Object* obj = mObjetMgr->getObject( i );
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