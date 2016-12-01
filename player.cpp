#include "prototype.h"

struct vList *Player;

void playerInit(){

	Player = new vList;

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

void displayPlayer(){

	Player = Player->next;
	struct vList *pStart = Player;
	//Player = Player->next;

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	do{

		glVertex2f(Player->info->x, Player->info->y);
		Player = Player->next;
	}while(Player != pStart);
	glEnd();


}
