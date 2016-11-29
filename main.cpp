/*#define WINDOW_MAX 600
#define WINDOW_MIN 0
#define VIEWPORT_MAX 550
#define VIEWPORT_MIN 50*/

//using namespace std;

#include "prototype.h"

float winWidth, winHeight, viewWidth, accuracy;
int shotsFired, asteroidsHit, asteroidsOnScreen;

void myGlutInit(int argc, char** argv){

	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(winWidth,winHeight);
	glutInitWindowPosition(0,0);
	glutCreateWindow("You're Too SLOOOooooOOoOOOWWwW");

}

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
{

	//int test = Player->info->x;
	int test = 1;
	cout << "hello World \n" << endl;
	cout << test  << endl;

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

	myGlutInit(argc,argv);
	myinit(winWidth); 
	viewportInit();
	playerInit();
	cout << "after player init\n" << endl;
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display); 
	glutMainLoop();
}

