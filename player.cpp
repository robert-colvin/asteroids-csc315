#include "prototype.h"

struct vList *Player;
struct mList *missiles;

int numMissiles;

void playerInit(){

	numMissiles = 0;

	Player = new vList;
	missiles = new mList;
	missiles->next = missiles;

	struct vList *pStart = Player;

	cout << "loop starts\n" << endl;

	for(int i = 0; i < 3; i++){
		
		Player->info = new vertex;
		Player->next = new vList;
		cout << "Player set\n" << endl;
		Player = Player->next;
	}

	cout << "loop ends\n" << endl;

	Player->next = pStart;
	Player->info = new vertex;

	Player->info->x = -1.0; Player->info->y = -0.5; Player->info->z = 0.0; Player->info->w = 1.0;
	Player = Player->next;
	Player->info->x = 0.0; Player->info->y = 0; Player->info->z = 0; Player->info->w = 1.0;
	Player = Player->next;
	Player->info->x = 1.0; Player->info->y = -0.5; Player->info->z = 0; Player->info->w = 1.0;
	Player = Player->next;
	Player->info->x = 0.0; Player->info->y = 1.5; Player->info->z = 0; Player->info->w = 1.0;
	Player = Player->next;


	cout << "in player init \n" << endl;

}

void setMissleValues(struct mList *mis){

	struct vList *misStart = mis->edge;

	mis->edge->info = new vertex;
	mis->edge->next = new vList;
	mis->edge->info->x = -1.0; mis->edge->info->y = -2.0; mis->edge->info->z = 0; mis->edge->info->w = 1;
	mis->edge = mis->edge->next;

	mis->edge->info = new vertex;
	mis->edge->next = new vList;
	mis->edge->info->x =  1.0; mis->edge->info->y = -2.0; mis->edge->info->z = 0; mis->edge->info->w = 1;
	mis->edge = mis->edge->next;

	mis->edge->info = new vertex;
	mis->edge->info->x =  0.0; mis->edge->info->y =  1.0; mis->edge->info->z = 0; mis->edge->info->w = 1;
	mis->edge->next = misStart;


}

void fireMissile(struct mList *mis){

	//need to set the rotation of the missile to the same as the player		
	if(numMissiles == 0){
	
		mis->edge = new vList;
		setMissleValues(mis);
		
		mis->origin = new vertex;
		mis->origin->x = winWidth/2;
		mis->origin->y = winHeight/2 + winHeight/15;

		mis->xSpeed = 1;
		mis->ySpeed = 1;
		
		numMissiles++;
	
	}else{

		struct mList *mStart = mis;

		while(mis->next != mStart){
			mis = mis->next;
		}

	        mis->next = new mList;
	        mis = mis->next;
	        mis->edge = new vList;
	        mis->origin = new vertex;

		mis->origin->x = winWidth/2;
		mis->origin->y = winHeight/2 + winHeight/15;

		mis->xSpeed = 1;
		mis->ySpeed = 1;

		setMissleValues(mis);

		mis->next = mStart;

		numMissiles++;	

	}
}

void displayMissiles(){

	struct mList *mStart = missiles;
if(numMissiles != 0){
	glColor3f(1.0,0.0,0.0);
	do{

		missiles->origin->x += missiles->xSpeed;
		missiles->origin->y += missiles->ySpeed;

		cout << missiles->origin->x << endl;

		//go through all possible missiles on screen and print all of them out
		glBegin(GL_LINE_LOOP);
			glVertex2f(missiles->edge->info->x+missiles->origin->x, missiles->edge->info->y+missiles->origin->y);
			glVertex2f(missiles->edge->next->info->x+missiles->origin->x, missiles->edge->next->info->y+missiles->origin->y);
			glVertex2f(missiles->edge->next->next->info->x+missiles->origin->x, missiles->edge->next->next->info->y+missiles->origin->y);
		glEnd();
	
		missiles = missiles->next;	

	}while(mStart != missiles);	
}
	glFlush();
	
}

void displayPlayer(){

	Player = Player->next;
	struct vList *pStart = Player;
	//Player = Player->next;

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	do{

		glVertex2f(Player->info->x, Player->info->y);
		Player = Player->next;
	}while(Player->next != pStart);
	
	glBegin(GL_POLYGON);
	do{

		glVertex2f(Player->info->x, Player->info->y);
		Player = Player->next;
	}while(Player->next != pStart);
	glEnd();


}
