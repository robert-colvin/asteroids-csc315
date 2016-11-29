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

	Player->info->x = 100.0; Player->info->y = 0.0; Player->info->z = 0.0; Player->info->w = 0;
	Player->info->x = 100; Player->info->y = 0; Player->info->z = 0; Player->info->w = 0;
	Player->info->x = 100; Player->info->y = 0; Player->info->z = 0; Player->info->w = 0;
	Player->info->x = 100; Player->info->y = 0; Player->info->z = 0; Player->info->w = 0;



	cout << "in player init \n" << endl;

}

