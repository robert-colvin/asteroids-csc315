#include "prototype.h"

void clipperInit(){
	glPointSize(1.0);
        glColor3f(0.0,1.0,0.0);         //set color 
        //drawing clipping area
	
	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glBegin(GL_POLYGON);
		glVertex3f(0, winHeight, 0);
		glVertex3f(clipperVerts[5].x, clipperVerts[5].y, 0);
		glVertex3f(clipperVerts[4].x, clipperVerts[4].y, 0);
		glVertex3f(0, scoreboardHeight, 0);
	glEnd();

        glBegin(GL_POLYGON);
		glVertex3f(clipperVerts[6].x, clipperVerts[6].y, 0);
		glVertex3f(clipperVerts[5].x, clipperVerts[5].y, 0);
		glVertex3f(0, winHeight, 0);
		glVertex3f(winWidth, winHeight, 0);
		glVertex3f(clipperVerts[7].x, clipperVerts[7].y, 0);	
	glEnd();

	glBegin(GL_POLYGON);	
		glVertex3f(clipperVerts[7].x, clipperVerts[7].y, 0);
		glVertex3f(clipperVerts[0].x, clipperVerts[0].y, 0);
		glVertex3f(winWidth, winHeight, 0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(winWidth, winHeight, 0);
		glVertex3f(clipperVerts[0].x, clipperVerts[0].y, 0);
		glVertex3f(clipperVerts[1].x, clipperVerts[1].y, 0);
		glVertex3f(winWidth, scoreboardHeight, 0);
	glEnd();

	glBegin(GL_POLYGON);	
		glVertex3f(clipperVerts[2].x, clipperVerts[2].y, 0);
		glVertex3f(clipperVerts[1].x, clipperVerts[1].y, 0);
		glVertex3f(winWidth, scoreboardHeight, 0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(winWidth, scoreboardHeight, 0);
		glVertex3f(clipperVerts[2].x, clipperVerts[2].y, 0);
		glVertex3f(clipperVerts[3].x, clipperVerts[3].y, 0);
		glVertex3f(0, scoreboardHeight, 0);
	glEnd();

	glBegin(GL_POLYGON);	
		glVertex3f(clipperVerts[3].x, clipperVerts[3].y, 0);
		glVertex3f(clipperVerts[4].x, clipperVerts[4].y, 0);
		glVertex3f(0, scoreboardHeight, 0);
	glEnd();
	
	glPopMatrix();
	glFlush();
	
}
