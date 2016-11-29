using namespace std;

#include <string.h>
#include <sstream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>


float winWidth, winHeight, viewWidth, scoreboardHeight, scoreboardWidth;
int shotsFired = 0;  int asteroidsHit = 0;  int asteroidsOnScreen = 50;//  float accuracy = 00.00;

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

void printToScoreboard()
{
	int i,len;
//	char *ss = itoa(shotsFired);
	char shots[] = "Shots fired: ";// + string(ss);
	char hit[] = "Asteroids hit: ";
	char onscreen[] = "Asteroids on screen: ";  
	char accuracyPrint[] = "Accuracy percentage: ";

	void *font = GLUT_STROKE_ROMAN;

	ostringstream printyS;
	string printy;

	glColor3f(0.0,0.0,0.0);

	glPushMatrix();

	glTranslatef(0.0, scoreboardHeight-25, 0.0);
	glScalef(scoreboardWidth/2800,0.125,0.0);
	len = (int) strlen(shots);
	for(i=0;i<len;i++)
		glutStrokeCharacter(font,shots[i]);

	glColor3f(1.0,0.0,0.0);
	printyS << shotsFired;
	printy = printyS.str();
	len = (int) strlen(&printy[0]);
	for(i=0;i<len;i++)
		glutStrokeCharacter(font, printy[i]);

	printyS.str("");
	glPopMatrix();
//-----------------------------------------------------------------------------------------
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);

	glTranslatef(0.0, 10.0, 0.0);
	glScalef(scoreboardWidth/2800,0.125,1.0);
	len = (int) strlen(hit);
	for(i=0;i<len;i++)
		glutStrokeCharacter(font,hit[i]);

	glColor3f(1.0,0.0,0.0);
	printyS << asteroidsHit;
	printy = printyS.str();
	len = (int) strlen(&printy[0]);
	for(i=0;i<len;i++)
		glutStrokeCharacter(font, printy[i]);

	printyS.str("");
	glPopMatrix();
	
//--------------------------------------------------------------------------------------------
	glColor3f(0.0,0.0,0.0);
	glPushMatrix();

	glTranslatef(winWidth/2.5, scoreboardHeight-25, 0.0);
	glScalef(scoreboardWidth/2800,0.125,1.0);
	len = (int) strlen(onscreen);
	for(i=0;i<len;i++)
		glutStrokeCharacter(font,onscreen[i]);

	glColor3f(1.0,0.0,0.0);
	printyS << asteroidsOnScreen;
	printy = printyS.str();
	len = (int) strlen(&printy[0]);
	for(i=0;i<len;i++)
		glutStrokeCharacter(font, printy[i]);

	printyS.str("");
	glPopMatrix();
//----------------------------------------------------------------------------------------------	
	glColor3f(0.0,0.0,0.0);
	glPushMatrix();

	glTranslatef(winWidth/2.5, 10.0, 0.0);
	glScalef(scoreboardWidth/2950,0.12,1.0);
	len = (int) strlen(accuracyPrint);
	for(i=0;i<len;i++)
		glutStrokeCharacter(font,accuracyPrint[i]);

	if (shotsFired != 0)
	{
		float accuracy = (float)asteroidsHit/(float)shotsFired;
		printyS << accuracy;
		printy = printyS.str();
	//	len = (int) strlen(&printy[0]); cout << printy << endl;
	}
	else
		printy = "00.00";
	
	glColor3f(1.0,0.0,0.0);
	for(i=0;i<5;i++)
		glutStrokeCharacter(font, printy[i]);
	printyS.str("");
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
	
	glBegin(GL_POLYGON);
		glVertex2f(1.0,1.0);
		glVertex2f(winWidth-1,1.0);
		glVertex2f(winWidth-1, scoreboardHeight);
		glVertex2f(1.0, scoreboardHeight);

	glEnd();

	printToScoreboard();
	
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
	
	//testing output changes
	if (key == 'a')
		shotsFired++;
	if (key == 's')
		asteroidsHit++;
	if (key == 'd')
		asteroidsOnScreen--;	

	glutPostRedisplay();

}
int main(int argc, char** argv)
{
	cout<<"How wide would you like the viewport?"<<endl;
	cin>>viewWidth;

	winWidth = viewWidth+100;
	winHeight = viewWidth + 150;

	scoreboardWidth = winWidth-2;
	scoreboardHeight = winHeight-(winHeight-100);
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

