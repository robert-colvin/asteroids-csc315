using namespace std;

#include <string.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>

/*#define WINDOW_MAX 600
#define WINDOW_MIN 0
#define VIEWPORT_MAX 550
#define VIEWPORT_MIN 50*/

float winWidth, winHeight, viewWidth, accuracy;
int shotsFired, asteroidsHit;
int asteroidsOnScreen = 50;

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

void printToScoreboard(float scoreboardHeight)
{
	int i,len;

	char shots[] = "Shots fired: ";
	char hit[] = "Asteroids hit: ";
	char onscreen[] = "Asteroids on screen: ";  
	char accuracy[] = "% of shots on target: ";

	void *font = GLUT_STROKE_ROMAN;

	glColor3f(1.0,0.0,0.0);

	glPushMatrix();

	glTranslatef(0.0, scoreboardHeight-25, 0.0);
	glScalef(0.125,0.125,1.0);
	len = (int) strlen(shots);
	for(i=0;i<len;i++)
		glutStrokeCharacter(font,shots[i]);

	glPopMatrix();

	glPushMatrix();

	glTranslatef(0.0, /*scoreboardHeight-55*/10.0, 0.0);
	glScalef(0.125,0.125,1.0);
	len = (int) strlen(hit);
	for(i=0;i<len;i++)
		glutStrokeCharacter(font,hit[i]);

	glPopMatrix();
	

	glPushMatrix();

	glTranslatef(winWidth/2.5, scoreboardHeight-25, 0.0);
	glScalef(0.125,0.125,1.0);
	len = (int) strlen(onscreen);
	for(i=0;i<len;i++)
		glutStrokeCharacter(font,onscreen[i]);

	glPopMatrix();
	
	glPushMatrix();

	glTranslatef(winWidth/2.5, /*scoreboardHeight-55*/10.0, 0.0);
	glScalef(0.125,0.125,1.0);
	len = (int) strlen(accuracy);
	for(i=0;i<len;i++)
		glutStrokeCharacter(font,accuracy[i]);

	glPopMatrix();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);   //clear window
	glColor3f(1.0,1.0,1.0);		//set color to white
//	glRecti(50.0,100.0, viewWidth+50, viewWidth+50);
//	//drawing octagonal viewport
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

	//drawing rectangular scoreboard below viewport starting w/ bottom left corner and going ccw
	
	float scoreboardHeight = winHeight-(winHeight-100);
	glBegin(GL_POLYGON);
		glVertex2f(1.0,1.0);
		glVertex2f(winWidth-1,1.0);
		glVertex2f(winWidth-1, scoreboardHeight);
		glVertex2f(1.0, scoreboardHeight);

	glEnd();

	printToScoreboard(scoreboardHeight);
	
	glutSwapBuffers();
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

