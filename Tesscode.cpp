
#include "headers.h"

using namespace std;


GLubyte red, green, blue;
int COLORS_DEFINED;

// Specity the values to place and size the window on the screen

const int WINDOW_POSITION_X = 0;
const int WINDOW_POSITION_Y = 0;
const int WINDOW_MAX_X = 700;
const int WINDOW_MAX_Y = 700;

// Specify the coordinate ranges for the world coordinates in the 2D Frame

const float WORLD_COORDINATE_MIN_X = 000.0;
const float WORLD_COORDINATE_MAX_X = 700.0;
const float WORLD_COORDINATE_MIN_Y = 000.0;
const float WORLD_COORDINATE_MAX_Y = 700.0;

unsigned int sleep(unsigned int seconds);

struct Point
{
    float x, y;
    Point * next;
    Point * back;
};
list< Point > points;

struct TessAngle
{
   float x1, y1, x2, y2, x3, y3;
};
list<TessAngle> myTess;

void myglutInit( int argc, char** argv )
{
    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); /* default, not needed */
    glutInitWindowSize(WINDOW_MAX_X,WINDOW_MAX_Y); /* set pixel window */
    glutInitWindowPosition(WINDOW_POSITION_X, WINDOW_POSITION_Y); /* place window top left on display */
    glutCreateWindow("Mouse and Keyboard Interaction"); /* window title */
}


void myInit(void)
{
 
/* standard OpenGL attributes */

      glClearColor(1.0, 1.0, 1.0, 1.0); /* white background */
      glColor3f(1.0, 0.0, 0.0); /* draw in red */
      glPointSize(5.0);

      COLORS_DEFINED = 0;

/* set up viewing window with origin lower left */

      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluOrtho2D(WORLD_COORDINATE_MIN_X, WORLD_COORDINATE_MAX_X,
                 WORLD_COORDINATE_MIN_Y, WORLD_COORDINATE_MAX_Y);
      glMatrixMode(GL_MODELVIEW);
}


void display( void )
{

/* define a point data type */

    typedef GLfloat point[2];     

    point p; /* A point in 2-D space */

    glClear(GL_COLOR_BUFFER_BIT);  /*clear the window */

    if (!COLORS_DEFINED) {
       red   = 255;
       green = 0; 
       blue  = 0;
    }

    glColor3ub( red, green, blue ); 
  
     
     glFlush(); /* clear buffers */

 }

bool doesIntersect(float thisX, float thisY){
	/* x1,y1 point to check
	  x2,y2 are the last point in list
	  iterate through list for x3,y3 + x4,y4
	  if any checks turn out true, break and return true for the whole method
	  put drawpoint in an if statement that will not work unless check intersect is false
	*/
	bool result = false;
	list< Point > myPoints = points;
	
	
	float temp = myPoints.size();
	float thePoints[myPoints.size()][2];
	
	for(int i = 0; i < temp; i++){
		thePoints[i][0] = (myPoints.back()).x;
		thePoints[i][1] = (myPoints.back()).y;
		myPoints.pop_back();
	}

	for(int k = 1; k < temp-1; k++)
	{
		double x1 = thisX*1.0;
		double y1 = thisY*1.0;
		double x2 = thePoints[0][0]*1.0;
		double y2 = thePoints[0][1]*1.0;
		double x3 = thePoints[k][0]*1.0;
		double y3 = thePoints[k][1]*1.0;
		double x4 = thePoints[k+1][0]*1.0;
		double y4 = thePoints[k+1][1]*1.0;

		double denom = (((x2-x1)*-1*(y4-y3))-((x4-x3)*-1*(y2-y1)));

		double uA = (((x3-x1)*-1*(y4-y3))-((x4-x3)*-1*(y3-y1)));

		uA = uA/denom;

		double uB = (((x2-x1)*(y3-y1))-((x3-x1)*(y2-y1)));

		uB = uB/denom;
		if((uA >0.0 && uA < 1.0) && (uB>0.0 && uB <1.0))
		{
			result = true;
			
			break;
		}
	
		
		
	}

	return result;
}

bool doesIntersect(float thisX, float thisY, float thisX2, float thisY2){
	
	bool result = false;
	list< Point > myPoints = points;
	
	
	float temp = myPoints.size();
	float thePoints[myPoints.size()][2];
	
	for(int i = 0; i < temp; i++){
		thePoints[i][0] = (myPoints.back()).x;
		thePoints[i][1] = (myPoints.back()).y;
		myPoints.pop_back();
	}

	for(int k = 0; k < temp-1; k++)
	{
		double x1 = thisX*1.0;
		double y1 = thisY*1.0;
		double x2 = thisX2*1.0;
		double y2 = thisY2*1.0;
		double x3 = thePoints[k][0]*1.0;
		double y3 = thePoints[k][1]*1.0;
		double x4 = thePoints[k+1][0]*1.0;
		double y4 = thePoints[k+1][1]*1.0;

		double denom = (((x2-x1)*-1*(y4-y3))-((x4-x3)*-1*(y2-y1)));

		double uA = (((x3-x1)*-1*(y4-y3))-((x4-x3)*-1*(y3-y1)));

		uA = uA/denom;

		double uB = (((x2-x1)*(y3-y1))-((x3-x1)*(y2-y1)));

		uB = uB/denom;
		if((uA >0.0 && uA < 1.0) && (uB>0.0 && uB <1.0))
		{
			result = true;
			
			break;
		}
	
		
		
	}

	return result;
}

int numIntersect(float thisX, float thisY, float thisX2, float thisY2){
	
	int result = 0;
	list< Point > myPoints = points;
	
	
	float temp = myPoints.size();
	float thePoints[myPoints.size()][2];
	
	for(int i = 0; i < temp; i++){
		thePoints[i][0] = (myPoints.back()).x;
		thePoints[i][1] = (myPoints.back()).y;
		myPoints.pop_back();
	}

	for(int k = 0; k < temp-1; k++)
	{
		double x1 = thisX*1.0;
		double y1 = thisY*1.0;
		double x2 = thisX2*1.0;
		double y2 = thisY2*1.0;
		double x3 = thePoints[k][0]*1.0;
		double y3 = thePoints[k][1]*1.0;
		double x4 = thePoints[k+1][0]*1.0;
		double y4 = thePoints[k+1][1]*1.0;

		double denom = (((x2-x1)*-1*(y4-y3))-((x4-x3)*-1*(y2-y1)));

		double uA = (((x3-x1)*-1*(y4-y3))-((x4-x3)*-1*(y3-y1)));

		uA = uA/denom;

		double uB = (((x2-x1)*(y3-y1))-((x3-x1)*(y2-y1)));

		uB = uB/denom;
		if((uA >0.0 && uA < 1.0) && (uB>0.0 && uB <1.0))
		{
			result++;
			
		}
	
		
		
	}

	return result;
}

bool isInside(float x1, float y1, float x2, float y2)
{

	double xCheck = (x1+x2)/2.0;
	double yCheck = (y1+y2)/2.0;

	int count = numIntersect(xCheck, yCheck, 700, yCheck);
	
	if (count%2 == 1)
	{
		return true;
	}
	else
	{
		return false;
	}



}

void drawPoint( int x, int y )
{

 float y_New = 1.0*WINDOW_MAX_Y - 1.0*y;
 float x_New = 1.0*WINDOW_MAX_X - 1.0*x;


 float WINDOW_SX = WORLD_COORDINATE_MIN_X - 1.0*WINDOW_POSITION_X + (1.0*WINDOW_MAX_X - x_New)/(1.0*WINDOW_MAX_X - 1.0*WINDOW_POSITION_X)*(WORLD_COORDINATE_MAX_X - WORLD_COORDINATE_MIN_X);

 float WINDOW_SY = (y_New)/(1.0*WINDOW_MAX_Y)*(WORLD_COORDINATE_MAX_Y) + (WORLD_COORDINATE_MAX_Y/(WINDOW_MAX_Y));

    typedef GLfloat point[2];     
    point p;
 
    glColor3ub( red, green, blue );
   
    p[0] =  WINDOW_SX;
    p[1] =  WINDOW_SY;
    	
	if(!doesIntersect(WINDOW_SX, WINDOW_SY))
	{
		struct Point newPoint;
		newPoint.x = WINDOW_SX;
		newPoint.y = WINDOW_SY; 
	 	newPoint.next = &(points.front());
		float tempX = points.back().x;
		float tempY = points.back().y;
		(points.back()).next = &newPoint; 
		points.push_back(newPoint);
	
	
		glBegin(GL_POINTS);
		    glVertex2f(newPoint.x, newPoint.y); 
		glEnd();
		glFlush();
	}
	else
	{
		printf("You cannot create an intersecting point at ");

	}

	
}

void clearBox()
{
       glClear(GL_COLOR_BUFFER_BIT); 
       glFlush();
}

void finishPoint( int x, int y )
{
	list< Point > tPoints = points;

	if(!doesIntersect((tPoints.back()).x, tPoints.back().y, tPoints.front().x, tPoints.front().y))
	{
		clearBox();
		tPoints.push_back(points.front());
	
		float temp = tPoints.size();
		float allPoints[tPoints.size()][2];
	
		for(int i = 0; i < temp; i++){
			allPoints[i][0] = (tPoints.back()).x;
			allPoints[i][1] = (tPoints.back()).y;
			tPoints.pop_back();
		}
	
		glBegin(GL_LINE_STRIP);
		for(int i =0; i < temp; i++)
			glVertex2f(allPoints[i][0], allPoints[i][1]);
	
		glEnd();
		glFlush();
	}
	
}

void polyDraw()
{
	clearBox();
	
	list< Point > tPoints = points;
	
	
	float temp = tPoints.size();
	float allPoints[tPoints.size()][2];
	
	for(int i = 0; i < temp; i++){
		allPoints[i][0] = (tPoints.back()).x;
		allPoints[i][1] = (tPoints.back()).y;
		tPoints.pop_back();
	}
	
        glBegin(GL_POLYGON);
	for(int i =0; i < temp; i++)
		glVertex2f(allPoints[i][0], allPoints[i][1]);
	
        glEnd();
        glFlush();


}

void lineMe()
{
	clearBox();

	list< Point > tPoints = points;
	
	
	float temp = tPoints.size();
	vector< vector <float> > allPoints(temp,vector<float>(2));
	
	for(int i = 0; i < temp; i++){
		allPoints[i][0] = (tPoints.back()).x;
		allPoints[i][1] = (tPoints.back()).y;
		tPoints.pop_back();
	}

	int size = 0;

	  glBegin(GL_LINE_STRIP);
	for(int i =0; i < temp; i++)
		glVertex2f(allPoints[i][0], allPoints[i][1]);

		glVertex2f(allPoints[0][0], allPoints[0][1]);
	
        glEnd();
        glFlush();

	while(allPoints.size() > 3)
	{
		size = allPoints.size();
		for(int k = 0; k <size-2; k++)
		{
			
			if(!doesIntersect(allPoints[k][0], allPoints[k][1], allPoints[k+2][0], allPoints[k+2][1]) && allPoints[k+2][1] != 0 && isInside(allPoints[k][0], allPoints[k][1], allPoints[k+2][0], allPoints[k+2][1]))
			{
				struct TessAngle myTess;
				myTess.x1 = allPoints[k][0];
				myTess.y1 = allPoints[k][1];		
				myTess.x2 = allPoints[k+1][0];
				myTess.y2 = allPoints[k+1][1];
				myTess.x3 = allPoints[k+2][0];
				myTess.y3 = allPoints[k+2][1];
				
				allPoints.erase(allPoints.begin() + (k+1));
				glBegin(GL_LINES);
					glVertex2f(myTess.x1, myTess.y1);
					//glVertex2f(myTess.x2, myTess.y2);
					glVertex2f(myTess.x3, myTess.y3);
				glEnd();
				glFlush();
   				
				
			}
		}
	}
	cout << endl;
	cout << "Lines have been tesselated";
	cout << endl;


}

void tesselateMe()
{
	clearBox();

	list< Point > tPoints = points;
	
	
	float temp = tPoints.size();
	vector< vector <float> > allPoints(temp,vector<float>(2));
	
	for(int i = 0; i < temp; i++){
		allPoints[i][0] = (tPoints.back()).x;
		allPoints[i][1] = (tPoints.back()).y;
		tPoints.pop_back();
	}

	int size = 0;

	  glBegin(GL_LINE_STRIP);
	for(int i =0; i < temp; i++)
		glVertex2f(allPoints[i][0], allPoints[i][1]);

		glVertex2f(allPoints[0][0], allPoints[0][1]);
	
        glEnd();
        glFlush();

	while(allPoints.size() > 3)
	{
		size = allPoints.size();
		for(int k = 0; k <size-2; k++)
		{
			
			if(!doesIntersect(allPoints[k][0], allPoints[k][1], allPoints[k+2][0], allPoints[k+2][1]) && allPoints[k+2][1] != 0 && isInside(allPoints[k][0], allPoints[k][1], allPoints[k+2][0], allPoints[k+2][1]))
			{
				sleep(1);
				struct TessAngle myTess;
				myTess.x1 = allPoints[k][0];
				myTess.y1 = allPoints[k][1];		
				myTess.x2 = allPoints[k+1][0];
				myTess.y2 = allPoints[k+1][1];
				myTess.x3 = allPoints[k+2][0];
				myTess.y3 = allPoints[k+2][1];
				
				allPoints.erase(allPoints.begin() + (k+1));
				glBegin(GL_POLYGON);
					glVertex2f(myTess.x1, myTess.y1);
					glVertex2f(myTess.x2, myTess.y2);
					glVertex2f(myTess.x3, myTess.y3);
				glEnd();
				glFlush();
   				
				
			}
		}
	
	}
	struct TessAngle myTess;
		myTess.x1 = allPoints[0][0];
		myTess.y1 = allPoints[0][1];		
		myTess.x2 = allPoints[1][0];
		myTess.y2 = allPoints[1][1];
		myTess.x3 = allPoints[2][0];
		myTess.y3 = allPoints[2][1];
		
		allPoints.erase(allPoints.begin() + 0 + 2);
		glBegin(GL_POLYGON);
			glVertex2f(myTess.x1, myTess.y1);
			glVertex2f(myTess.x2, myTess.y2);
			glVertex2f(myTess.x3, myTess.y3);
		glEnd();
		glFlush();
	
	cout << endl;
	cout << "Polygon has been drawn";
	cout << endl;

}

void mouse( int button, int state, int x, int y )
{ 

  if ( button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN )
     {
        printf ("%d   %d\n", x, y);
        drawPoint( x, y );
	

     }

  if ( button == GLUT_LEFT_BUTTON && state == GLUT_DOWN )
     {
        printf ("%d   %d\n", x, y);
        finishPoint( x, y );
     }
  
  if ( button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN )
     {
        printf ("%d   %d\n", x, y);
        clearBox();
     }
}


void keyboard( unsigned char key, int x, int y )
{ 
  if ( key == 'q' || key == 'Q') exit(0);
  if ( key == 'f' || key == 'F') polyDraw();
  if ( key == 'l' || key == 'L') finishPoint(x, y);
  if ( key == 'p' || key == 'p') tesselateMe();
  if ( key == 't' || key == 'T') lineMe();
}


int main(int argc, char** argv)
{

    myglutInit(argc,argv); /* Set up Window */
    myInit(); /* set attributes */

    // Now start the standard OpenGL glut callbacks //
    
    glutMouseFunc(mouse);  /* Define Mouse Handler */
    glutKeyboardFunc(keyboard); /* Define Keyboard Handler */
    glutDisplayFunc(display); /* Display callback invoked when window opened */
    glutMainLoop(); /* enter event loop */
    
}

