/*#define WINDOW_MAX 600
#define WINDOW_MIN 0
#define VIEWPORT_MAX 550
#define VIEWPORT_MIN 50*/

//using namespace std;

#include "prototype.h"

float winWidth, winHeight, viewWidth, scoreboardHeight, scoreboardWidth;
int shotsFired = 0, asteroidsHit = 0, asteroidsOnScreen = 50;
bool started = false;
bool paused = false;
//array of vertex structs to define octagonal clipper
vertex clipperVerts[8];

float playerRot;

struct asteroid *test;

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

	playerRot = 0;

//
	glColor3f(0.0,0.5,0.5);
	test = new asteroid;
	test->edge = new vList;
	test->edge->info = new vertex;
	test->edge->next = new vList;
        test->edge->next->info = new vertex;
	test->edge->next->next = new vList;
        test->edge->next->next->info = new vertex;
	test->edge->next->next->next = new vList;
	test->edge->next->next->next->info = new vertex;
	test->edge->next->next->next->next = test->edge;

	test->edge->info->x = 150;
	test->edge->info->y = 150;
	test->edge->next->info->x = 200;
	test->edge->next->info->y = 150;
	test->edge->next->next->info->x = 200;
	test->edge->next->next->info->y = 200;
	test->edge->next->next->next->info->x = 150;
	test->edge->next->next->next->info->y = 200;

	
	test->tess = tesselate(test->edge);
	
	cout << test->tess->info->a->x << endl;
	//cout << test->tess->next->info->a->x << endl;

	glColor3f(0.0,0.5,0.5);

	glBegin(GL_POLYGON);
		glVertex2f(test->tess->info->a->x,test->tess->info->a->y);
		glVertex2f(test->tess->info->b->x,test->tess->info->b->y);
		glVertex2f(test->tess->info->c->x,test->tess->info->c->y);
	glEnd();
	glFlush();

	//test->tess

//
	int blah;
	//cin >> blah;

}

void calmTheFuckDown()
{//cout <<"calm the fuck down bro"<<endl;
}


void display(void)
{
	 
	//int test = Player->info->x;
	//int test = 1;
//if(!paused){	
	viewportInit();
	
	glPushMatrix();
	glTranslatef(winWidth/2, winHeight/2 + winHeight/15, 0);
	glScalef(10,10,0);
	glRotatef(playerRot, 0, 0, 1);
	displayPlayer();
	
	glPopMatrix();
	displayAsteroids(paused);
	glFlush();	

	glColor3f(0.0,0.5,0.5);

	cout << test->tess << endl;
        glBegin(GL_POLYGON);
                glVertex2f(test->tess->next->info->a->x,test->tess->next->info->a->y);
                glVertex2f(test->tess->next->info->b->x,test->tess->next->info->b->y);
                glVertex2f(test->tess->next->info->c->x,test->tess->next->info->c->y);
        glEnd();
        glFlush();


	
	glColor3f(1.0,1.0,1.0);
	
	glutSwapBuffers();
/*}
else 
	calmTheFuckDown();*/
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
	
	if (key == 'a')
		shotsFired++;
	if (key == 's')
		asteroidsHit++;
	if (key == 'd')
		asteroidsOnScreen--;	
	if (key == 'e')
		playerRot += 10;
	if (key == 'r')
		playerRot -= 10;
	if (key == 'p')
		paused = !paused;
	if (key == 'm'){
//		paused = true;
		reset();
		glutPostRedisplay();	
	}
	//if (key == 'o')
	//	startGame = !startGame;
	//glClear(GL_COLOR_BUFFER_BIT);
	//viewportInit();
	//glutPostRedisplay();
	//glutSwapBuffers();
}
void refresh(){
	
	display();
}
void reset()
{
	shotsFired = 0; asteroidsHit = 0; asteroidsOnScreen = 50;paused=true; 
//	myGlutInit(argc,argv);
	myinit(winWidth); 
	
	viewportInit();
	playerInit();
	generate();
	//cout << "after player init\n" << endl;
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display); 
	glutIdleFunc(refresh);
	glutMainLoop();
}
int main(int argc, char** argv)
{
	cout<<"How wide would you like the viewport?"<<endl;
	cin>>viewWidth;
	viewWidth *= 1.0;

	winWidth = viewWidth+100;
	winHeight = viewWidth + 150;
	
	scoreboardWidth = winWidth-2;
	scoreboardHeight = winHeight-(winHeight-100);

	myGlutInit(argc,argv);
	reset();
/*	myinit(nWidth); 
	viewportInit();
	playerInit();
	generate();
	cout << "after player init\n" << endl;
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display); 
	glutIdleFunc(refresh);
	glutMainLoop();
*/
}
