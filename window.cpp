#include "prototype.h"


void viewportInit(){
	
	glPointSize(1.0);
	glClear(GL_COLOR_BUFFER_BIT);   //clear window
        glColor3f(1.0,1.0,1.0);         //set color to white
//      glRecti(50.0,100.0, viewWidth+50, viewWidth+50);        //draw rectangular viewport
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

	
	//drawing rectangular scoreboard below viewport starting w/ bottom left corner and going ccw
	
	glBegin(GL_POLYGON);
		glVertex2f(1.0,1.0);
		glVertex2f(winWidth-1,1.0);
		glVertex2f(winWidth-1, scoreboardHeight);
		glVertex2f(1.0, scoreboardHeight);

	glEnd();
	
        //glutSwapBuffers();
	printToScoreboard();
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
