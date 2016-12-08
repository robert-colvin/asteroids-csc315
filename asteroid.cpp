#include "prototype.h"

struct aList *Aster;

int gridX = 20; //Number of grid boxes in a row (100 boxes)
float gridWidth; //Height and width of each grid box;
float rMax = 15;//*(viewWidth/(rMax*20)); //Maximum radius for any point (given 10x10 square)

void generate() {

	Aster = new aList; //Initialize list of asteroids

	struct aList *aStart = Aster; //Start node

	//Use clipping algorithm against viewport walls to determine legal areas for asteroid?
	
	int aCount = 0;
	
	struct vertex *origVert = new vertex;
	
	do {//Loop thru generation of 50 asteroids, skipping over every other grid box
			Aster->info = new asteroid;
			Aster->next = new aList;

				//Insert x and y of origin
			Aster->info->origin = new vertex;
			do {
				origVert->x = rand() % (int)winWidth;
				origVert->y = (rand() % (int)(winHeight - scoreboardHeight)) + scoreboardHeight;

			} while (!isInViewport(origVert));
			
			cout << "i made a good asteroid: " << aCount << "\n";
			
			Aster->info->origin->x = origVert->x;
			Aster->info->origin->y = origVert->y;
			
			cout <<Aster->info->origin->x<<"    "<<Aster->info->origin->y<<endl;
				//Generate random spin value between 0 degrees and 10 degrees
			Aster->info->spin = -5 + (rand() % 10);
				//Generate random direction between 0 and 360
			Aster->info->xSpeed = -0.3 + ((rand() % 6000)*0.0001);
			Aster->info->ySpeed = -0.3 + ((rand() % 6000)*0.0001);
				//Generate random local vertices of asteroid
				//dimensions are x=0-10, y=0-10
			Aster->info->edge = new vList; //List of local vertices

			createVertices(Aster->info->edge);

			//Check each vertex for insideViewport

			Aster = Aster->next;

			aCount++;
		
	}
	while (aCount < 50);
	
	Aster->next = aStart;

}

void rotatePoint(struct vertex * point, float centerX, float centerY, float angle)
{
	//cout << "point x: " << point->x << endl;
	angle *= (3.14159 / 180.0);
	float tempx = point->x;
	float tempy = point->y;
	point->x = cos(angle) * (tempx - centerX) - sin(angle) * (tempy - centerY) + centerX;
	point->y = sin(angle) * (tempx - centerX) + cos(angle) * (tempy - centerY) + centerY;
	//cout << "point x changed: " << point->x << endl;
}

void createVertices(struct vList * edge) {
		//Randomize sides from 4 to 12
	
	struct vList *eStart = edge;
	int sides = (rand() % 9) + 5;

	float angle = 0;
	float angleStep = 360.0 / sides;

	angleStep *= (3.14159 / 180.0);

	//float rMin = 0.0;

	for (int k=0;k<sides;k++) { //Create random-distance vertex for each point
		edge->info = new vertex;
		edge->next = new vList;

		float r = ((((float)rand()/(float)RAND_MAX) +0.5) * rMax*(viewWidth/(rMax*40))); //radius of point between 0.0 and rMax

		float x = r * sin(angle); //Local coords
		float y = r * cos(angle);
		

		edge->info->x = x;
		edge->info->y = y;

		angle += angleStep;

		if(k == sides-1){
			edge->next = eStart;
		}else{
			edge = edge->next;
		}
	}
}

void displayAsteroids(bool paused) {

	struct aList *aStart = Aster->next; //Start node
	Aster = aStart;
	float vertX;
	float vertY;
	gridWidth = viewWidth*2.8/(float)gridX; //Height and width of each grid box;
	

	glPointSize(10.0);
	glColor3f(1.0, 0.0, 1.0);
	do{
		struct vList *eNow = new vList;
		cout << "aster is doing shit\n";
		eNow = Aster->info->edge;
		glPushMatrix();
		//glTranslatef(winWidth/3 + (rand() % 50), winHeight/3 + (rand() % 50), 0);
		glBegin(GL_LINE_LOOP);
		do{
				//Translate local coords to viewport coords
			vertX = ((Aster->info->origin->x /* gridWidth*/) + rMax) +eNow->info->x;
			//cout << vertX << "            ";
			vertY = ((Aster->info->origin->y /** gridWidth*/) + rMax) + eNow->info->y;
			//cout << vertY << endl;
			if (!paused){
			rotatePoint(eNow->info, 0, 0, Aster->info->spin);
			}
			glVertex2f(vertX, vertY);

			eNow = eNow->next;
		} while(eNow != Aster->info->edge);
		glEnd();
		if (!paused){
		Aster->info->origin->x += Aster->info->xSpeed;
		Aster->info->origin->y += Aster->info->ySpeed;
		}
		glPopMatrix();
		Aster = Aster->next;
	} while(Aster->next != aStart);
}
