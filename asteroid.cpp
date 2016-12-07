#include "prototype.h"

struct aList *Aster;

int gridX = 20; //Number of grid boxes in a row (100 boxes)
float gridWidth; //Height and width of each grid box;
float rMax = 15; //Maximum radius for any point (given 10x10 square)

void generate() {

	Aster = new aList; //Initialize list of asteroids

	struct aList *aStart = Aster; //Start node

	//Use clipping algorithm against viewport walls to determine legal areas for asteroid?

	for (int i=0;i<10;i=i+2) { //Loop thru generation of 50 asteroids, skipping over every other grid box
		for (int j=0;j<10;j++) {
			Aster->info = new asteroid;
			Aster->next = new aList;

				//Insert x and y of origin
			Aster->info->origin = new vertex;
			Aster->info->origin->x = i;
			Aster->info->origin->y = j;
				//Generate random spin value between 0 degrees and 10 degrees
			Aster->info->spin = (rand() % 5);
				//Generate random direction between 0 and 360
			Aster->info->xSpeed = -0.03 + ((rand() % 60)*0.001);
			Aster->info->ySpeed = -0.03 + ((rand() % 60)*0.001);
				//Generate random local vertices of asteroid
				//dimensions are x=0-10, y=0-10
			Aster->info->edge = new vList; //List of local vertices

			createVertices(Aster->info->edge);

			if(i==8 && j== 9){
				Aster->next = aStart;
			}else{
				Aster = Aster->next;
			}
			
		}
		
	}

}

void rotatePoint(struct vertex * point, float centerX, float centerY, float angle)
{
	cout << "point x: " << point->x << endl;
	angle *= (3.14159 / 180.0);
	point->x = cos(angle) * (point->x - centerX) - sin(angle) * (point->y - centerY) + centerX;
	point->y = sin(angle) * (point->x - centerX) + cos(angle) * (point->y - centerY) + centerY;
	cout << "point x changed: " << point->x << endl;
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

		float r = (((float)rand()/(float)RAND_MAX +0.5) * rMax); //radius of point between 0.0 and rMax

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

	struct aList *aStart = Aster; //Start node
	float vertX;
	float vertY;
	gridWidth = viewWidth*2.8/(float)gridX; //Height and width of each grid box;
	

	glPointSize(10.0);
	glColor3f(1.0, 0.0, 1.0);
	do{
		struct vList *eNow = Aster->info->edge;
		glPushMatrix();
		//glTranslatef(winWidth/3 + (rand() % 50), winHeight/3 + (rand() % 50), 0);
		glBegin(GL_LINE_LOOP);
		do{
				//Translate local coords to viewport coords
			vertX = ((Aster->info->origin->x * gridWidth) + rMax) +eNow->info->x;
			//cout << vertX << "            ";
			vertY = ((Aster->info->origin->y * gridWidth) + rMax) + eNow->info->y;
			//cout << vertY << endl;

			rotatePoint(eNow->info, Aster->info->origin->x, Aster->info->origin->y, Aster->info->spin);
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
	} while(Aster != aStart);
	
}
