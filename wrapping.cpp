#include "prototype.h"

void checkWrap(struct aList *Aster){
	float gridWidth = viewWidth*2.8/20.0;
	struct aList *aStart = Aster;
	do{
		struct vList *eNow = Aster->info->edge;
		if(distAway(((Aster->info->origin->x * gridWidth) + 15) +eNow->info->x, ((Aster->info->origin->y * gridWidth) + 			15) + eNow->info->y) > (viewWidth/2 + 15)){
			
			do{
				rotatePoint(eNow->info, winWidth/2, viewWidth/2 + scoreboardHeight, 180);
				eNow = eNow->next;
			} while(eNow != Aster->info->edge);
		}

		Aster = Aster->next;
	
	} while(Aster != aStart);

}


float distAway(float x1, float y1){
	return sqrt(pow(winWidth/2 - x1, 2) + pow(viewWidth/2 + scoreboardHeight - y1, 2));
}
