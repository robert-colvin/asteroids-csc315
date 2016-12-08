#include "prototype.h"

struct vList *Player;
struct mList *missiles;

void playerInit(){

	Player = new vList;
	missiles = new mList;

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

void setMissleValues(struct triangle *mis){

	mis->a = new vertex;
	mis->b = new vertex;
	mis->c = new vertex;

	mis->a->x = -1.0; mis->a->y = -2.0; mis->a->z = 0; mis->a->w = 1;
	mis->a->x =  1.0; mis->a->y = -2.0; mis->a->z = 0; mis->a->w = 1;
	mis->a->x =  0.5; mis->a->y =  1.0; mis->a->z = 0; mis->a->w = 1;

}

void fireMissile(){

		

}

void displayMissiles(){

	
	
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
