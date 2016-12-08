#include "prototype.h"

struct vList *Player;
struct mList *missiles;
vList *p2;
void playerInit(){

	Player = new vList;
	p2 = new vList;
	missiles = new mList;

	struct vList *pStart = Player;
	struct vList *p2star = p2; 
	cout << "loop starts\n" << endl;

	for(int i = 0; i < 3; i++){
		
		Player->info = new vertex;
		Player->next = new vList;
		//cout << "Player set\n" << endl;
		Player = Player->next;
		
		p2->info = new vertex;
		p2->next = new vList;
		//cout << "Player set\n" << endl;
		p2 = p2->next;
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

/*
	p2->next = p2star;
	p2->info = new vertex;

	p2->info->x = -100.0; p2->info->y = -8710.5; p2->info->z = 1010.0; p2->info->w = 1.0;
	p2 = p2->next;
	p2->info->x = 1000.0; p2->info->y = 1990; p2->info->z = 1910; p2->info->w = 1.0;
	p2 = p2->next;
	p2->info->x = 1100.0; p2->info->y = -1800.5; p2->info->z = 1910; p2->info->w = 1.0;
	p2 = p2->next;
	p2->info->x = 190.0; p2->info->y = 1990.5; p2->info->z = 1710; p2->info->w = 1.0;
	p2 = p2->next;
//	cout << "in player init \n" << endl;
*/
}

void setMissleValues(struct triangle *mis){

	mis->a = new vertex;
	mis->b = new vertex;
	mis->c = new vertex;

	mis->a->x = -1.0; mis->a->y = -2.0; mis->a->z = 0; mis->a->w = 1;
	mis->a->x =  1.0; mis->a->y = -2.0; mis->a->z = 0; mis->a->w = 1;
	mis->a->x =  0.5; mis->a->y =  1.0; mis->a->z = 0; mis->a->w = 1;

}

void fireMissile(){

	//need to set the rotation of the missile to the same as the player		

}

void displayMissiles(){

	struct mList *mStart = missiles;

	do{

		//go through all possible missles on screen and print all of them out
	
		missiles = missiles->next;	

	}while(mStart != missiles);	
	
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
