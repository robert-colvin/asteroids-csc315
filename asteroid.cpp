#include "prototype.h"

struct aList *Aster;
float gridWidth;
int gridX = 10; //Number of grid boxes in a row (100 boxes)
float rMax = 5.0; //Maximum radius for any point (given 10x10 square)

void generate() {

	gridWidth = viewWidth/(float)gridX; //Height and width of each grid box

	Aster = new aList; //Initialize list of asteroids

	struct aList *aStart = Aster; //Start node

	//Use clipping algorithm against viewport walls to determine legal areas for asteroid?

	for (int i=0;i<10;i=i+2) { //Loop thru generation of 50 asteroids, skipping over every other grid box
		for (int j=0;j<10;j=j+2) {
			Aster->info = new asteroid;
			Aster->next = new aList;

				//Insert x and y of origin
			Aster->info->origin = new vertex;
			Aster->info->origin->x = i;
			Aster->info->origin->y = j;
				//Generate random spin value between 0 degrees and 10 degrees
			Aster->info->spin = rand() % 10;
				//Generate random direction between 0 and 360
			Aster->info->direction = rand() % 360;
				//Generate random local vertices of asteroid
				//dimensions are x=0-10, y=0-10
			Aster->info->edge = new vList; //List of local vertices

			createVertices(Aster->info->edge);

			Aster = Aster->next;
		}
	}
}

void createVertices(struct vList * edge) {
		//Randomize sides from 4 to 12
	int sides = (rand() % 9) + 4;

	float angle = 0;
	float angleStep = 360.0 / sides;

	//float rMin = 0.0;

	for (int k=0;k<sides;k++) { //Create random-distance vertex for each point
		edge->info = new vertex;
		edge->next = new vList;

		float r = (((float)rand()/(float)RAND_MAX) * rMax); //radius of point between 0.0 and rMax

		float x = r * sin(angle); //Local coords
		float y = r * cos(angle);
		

		edge->info->x = x;
		edge->info->y = y;

		angle += angleStep;
	}
}

void displayAsteroids() {

	struct aList *aStart = Aster; //Start node

	float vertX;
	float vertY;

	gridWidth = viewWidth/(float)gridX; //Height and width of each grid box

	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	do{
			//Translate local coords to viewport coords
		vertX = ((Aster->info->origin->x * gridWidth) + rMax) + Aster->info->edge->info->x;
		vertY = ((Aster->info->origin->y * gridWidth) + rMax) + Aster->info->edge->info->y;
		glVertex2f(vertX, vertY);
		Aster = Aster->next;
	} while(Aster->next != aStart);
	glEnd();
}