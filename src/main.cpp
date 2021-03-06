#include "glew.h"
#include "glaux.h"
#include "glut.h"
#include "wglew.h"

void initial()
{

}

void Display(void)
{
    glPushMatrix();
    glBegin (GL_TRIANGLES);          // 開始劃三角形 
        glColor3f (1.0f, 0.0f, 0.0f);         // 設定輸出色為紅色 
        glVertex2f (0.0f, 1.0f);           //(x1,y1)=(0, 1)
        glColor3f (0.0f, 1.0f, 0.0f);         // 設定輸出色為綠色 
        glVertex2f (0.87f, -0.5f);            //(x2,y2)=(0.87,-0.5)
        glColor3f (0.0f, 0.0f, 1.0f);         // 設定輸出色為藍色 
        glVertex2f (-0.87f, -0.5f);           //(x3,y3)=(-0.87,-0.5)
    glEnd ();                               // 結束劃三角形 
    glPopMatrix();
    glutSwapBuffers();


}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(100, 100); // 設定視窗位置 
    glutInitWindowSize(400, 400); // 設定視窗大小 
    glutCreateWindow("Colorful Triangle "); // 設定視窗標題 
    glutDisplayFunc(Display);  // 呼叫函數 
   
	initial();
	
	glutMainLoop();
    return 0;
}