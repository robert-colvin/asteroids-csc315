#include "prototype.h"

void clipperInit(){
	glPointSize(1.0);
        glColor3f(0.0,0.0,0.0);         //set color 
        //drawing clipping area
	
	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glBegin(GL_POLYGON);
		glVertex3f(0, winHeight, 0);
		glVertex3f(50.0, viewWidth*(2.0/3.0)+140.0, 0);
		glVertex3f(50.0, viewWidth*(1.0/3.0)+110.0, 0);
		glVertex3f(0, scoreboardHeight, 0);
	glEnd();

        glBegin(GL_POLYGON);
		glVertex3f(35.0+viewWidth*(1.0/3.0), 100.0+viewWidth, 0);
		glVertex3f(50.0, viewWidth*(2.0/3.0)+140.0, 0);
		glVertex3f(0, winHeight, 0);
		glVertex3f(winWidth, winHeight, 0);
		glVertex3f(65.0+viewWidth*(2.0/3.0), 100.0+viewWidth, 0);	
	glEnd();

	glBegin(GL_POLYGON);	
		glVertex3f(65.0+viewWidth*(2.0/3.0), 100.0+viewWidth, 0);
		glVertex3f(50.0+viewWidth, 140.0+viewWidth*(2.0/3.0), 0);
		glVertex3f(winWidth, winHeight, 0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(winWidth, winHeight, 0);
		glVertex3f(50.0+viewWidth, 140.0+viewWidth*(2.0/3.0), 0);
		glVertex3f(50.0+viewWidth, 110.0+viewWidth*(1.0/3.0), 0);
		glVertex3f(winWidth, scoreboardHeight, 0);
	glEnd();

	glBegin(GL_POLYGON);	
		glVertex3f(50.0+viewWidth, 110.0+viewWidth*(1.0/3.0), 0);
		glVertex3f(65.0+viewWidth*(2.0/3.0), 150.0, 0);
		glVertex3f(winWidth, scoreboardHeight, 0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(winWidth, scoreboardHeight, 0);
		glVertex3f(65.0+viewWidth*(2.0/3.0), 150.0, 0);
		glVertex3f(35.0+viewWidth*(1.0/3.0), 150.0, 0);
		glVertex3f(0, scoreboardHeight, 0);
	glEnd();

	glBegin(GL_POLYGON);	
		glVertex3f(35.0+viewWidth*(1.0/3.0), 150.0, 0);
		glVertex3f(50.0, viewWidth*(1.0/3.0)+110.0, 0);
		glVertex3f(0, scoreboardHeight, 0);
	glEnd();
	
	glPopMatrix();
	glFlush();
	
}
