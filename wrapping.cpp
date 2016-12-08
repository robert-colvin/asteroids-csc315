#include "prototype.h"

void checkWrap(struct aList *Aster){
	
	struct aList *aStart = Aster->next;
		Aster = aStart;
	do{
		struct vList *eNow = Aster->info->edge;

		if(distAway((Aster->info->origin->x), (Aster->info->origin->y)) >= (viewWidth/2.0) /*|| Aster->info->origin->y <= scoreboardHeight+25*/){
			flipPoint(Aster->info->origin, winWidth/2.0-15.0, (winHeight)/2.0 + (winHeight)/20.0);
			/*do{
				//flipPoint(eNow->info, winWidth/2, winWidth/2 + scoreboardHeight);
				eNow = eNow->next;
			} while(eNow != Aster->info->edge);*/
		}

		Aster = Aster->next;
	
	} while(Aster->next != aStart);

}


float distAway(float x1, float y1){
	return sqrt(pow((winWidth/2.0-15.0) - x1, 2) + pow((winHeight)/2.0 + (winHeight)/20.0 - y1, 2));
}

void flipPoint(struct vertex * point, float centerX, float centerY){
	point->x = point->x + 2.0*(centerX-point->x);
	point->y = point->y + 2.0*(centerY-point->y);
}
