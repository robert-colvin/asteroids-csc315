using namespace std;

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>

/*#define WINDOW_MAX 600
#define WINDOW_MIN 0
#define VIEWPORT_MAX 550
#define VIEWPORT_MIN 50*/

float winWidth, winHeight, viewWidth, accuracy;
int shotsFired, asteroidsHit, asteroidsOnScreen;

void myinit( int winSize )
{
/* attributes */

      glClearColor(0.0, 0.0, 0.0, 1.0); /* black background */

/* set up viewing */

      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluOrtho2D(0.0, (float) winWidth, 
                 0.0, (float) winHeight);
      glMatrixMode(GL_MODELVIEW);
}
void display(void)
{//kjrgbvkjrouerh8hkjeqihfklqi8fu3owp89qwkjg uq3tegueqijoteoheugepenisiuwefoi7guyewf87e7guveayg73434ekeayvt7u3r8gf3hgtu0734yr9
	glClear(GL_COLOR_BUFFER_BIT);   //clear window
	glColor3f(1.0,1.0,1.0);		//set color to white
//	glRecti(50.0,100.0, viewWidth+50, viewWidth+50);	//draw rectangular viewport
	//drawing octagonal viewport
	glBegin(GL_POLYGON);
		//left-most vertices
		glVertex2f(50.0, viewWidth*(2.0/3.0)+125.0);	
		glVertex2f(50.0, viewWidth*(1.0/3.0)+125.0);	
		
		//bottom vertices
		glVertex2f(50.0+viewWidth*(1.0/3.0), 125.0);
		glVertex2f(50.0+viewWidth*(2.0/3.0), 125.0);
		
		//right most vertices
		glVertex2f(50.0+viewWidth, 125.0+viewWidth*(1.0/3.0));
		glVertex2f(50.0+viewWidth, 125.0+viewWidth*(2.0/3.0));
		
		//top vertices
		glVertex2f(50.0+viewWidth*(2.0/3.0), 125.0+viewWidth);
		glVertex2f(50.0+viewWidth*(1.0/3.0), 125.0+viewWidth);
	glEnd();
	
	glutSwapBuffers();

	//Arrow stuff goes below


}
void mouse(int button, int state, int x, int y) 
{
      if ( button == GLUT_LEFT_BUTTON && state == GLUT_DOWN ) 
      {    
	glutPostRedisplay();
      }
}
void keyboard( unsigned char key, int x, int y )
{ 
    if ( key == 'q' || key == 'Q') exit(0);

}
int main(int argc, char** argv)
{
	cout<<"How wide would you like the viewport?"<<endl;
	cin>>viewWidth;

	winWidth = viewWidth+100;
	winHeight = viewWidth + 150;

    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB); 
    glutInitWindowSize(winWidth,winHeight); 
    glutInitWindowPosition(0,0); 
    glutCreateWindow("You're Too SLOOOooooOOoOOOWWwW"); 
    myinit(winWidth); 
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display); 
    glutMainLoop();
}

