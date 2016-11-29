<<<<<<< HEAD
#include "prototype.h"

void viewportInit(){

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

        glutSwapBuffers();


}
=======
>>>>>>> origin
