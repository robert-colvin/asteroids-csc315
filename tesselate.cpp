#include "prototype.h"


bool intersect(struct vertex *a, struct vertex *b, struct vertex *c, struct vertex *d){
/*
	float denom = ((ab.b[0]-ab.a[0])*(cd.a[1]-cd.b[1])-(cd.a[0]-cd.b[0])*(ab.b[1]-ab.a[1]));
	float ua = ((cd.a[0]-ab.a[0])*(cd.a[1]-cd.b[1])-(cd.a[1]-ab.a[1])*(cd.a[0]-cd.b[0]));
	float ub = ((ab.b[0]-ab.a[0])*(cd.a[1]-ab.a[1])-(cd.a[0]-ab.a[0])*(ab.b[1]-ab.a[1]));

	ab.a[0] = a->x
	ab.a[1] = a->y
	ab.b[0] = b->x
	ab.b[1] = b->y
	cd.a[0] = c->x
	cd.a[1] = c->y
	cd.b[0] = d->x
	cd.b[1] = d->y

*/

	float denom = ((b->x-a->x)*(c->y-d->y) - (c->x-d->x)*(b->y-a->y));
	float ua = ((c->x-a->x)*(c->y-d->y) - (c->y-a->y)*(c->x-d->x));
	float ub = ((b->x-a->x)*(c->y-a->y) - (c->x-a->x)*(b->y-a->y));

	if(denom == 0){
		return true;
	}else if((ua/denom > 0 && ua/denom < 1) && (ub/denom > 0 && ub/denom < 1)){
		return true;
	}
	
	return false;

}

//GLfloat crossProd(struct *vList){
GLfloat crossProd(struct vertex *a, struct vertex *b, struct vertex *c){

	//The first beginning version will deal with getting the first vertex from the list
		// while the second beginning simply takes in each vertex individually

	GLfloat cross = (a->x-b->x)*(b->y-c->y)-(a->y-b->y)*(b->x-c->x);

	return cross;

}

struct tList *tesselate(struct vList *original){

	cout << "start tesselate" << endl;

	glColor3f(0.0,0.0,0.0);

	struct vList *vTemp = original;
	struct tList * newlist = new tList;
	newlist->info = new triangle;

	cout << "before while loop" << endl;
	cout << vTemp->next->info->x << endl;
	while(vTemp->next->next->next != vTemp){
		cout << "before if statement" << endl;
		if(crossProd(vTemp->info,vTemp->next->info,vTemp->next->next->info) > 0){

			cout << "start of loop" << endl;

			struct vertex *thirda = new vertex;
			struct vertex *thirdb = new vertex;
			struct vertex *thirdabi = new vertex;
			struct vertex *thirdbbi = new vertex;
			thirda->x = vTemp->info->x;
			thirda->y = vTemp->info->y;
			thirdb->x = vTemp->next->next->info->x;
			thirdb->y = vTemp->next->next->info->y;
			
			cout << "after the thirds" << endl;
			
			thirdabi->x = (thirda->x+thirdb->x)/2;
			thirdabi->y = (thirda->y+thirdb->y)/2;
			thirdbbi->x = vTemp->next->info->x;
			thirdbbi->y = vTemp->next->info->y;

			int inter = 0;
			struct vList *iter = vTemp->next;
			
			while(inter == 0 && iter != vTemp){
				if(intersect(thirda,thirdb,iter->info, iter->next->info)){
					inter++;
				}else if(intersect(thirdabi,thirdbbi,iter->info, iter->next->info)){
					inter++;
				}else{
					iter = iter->next;
				}
			}
			if(inter == 0){
				newlist->info->a->x = vTemp->info->x;
				newlist->info->a->y = vTemp->info->y;
				newlist->info->b->x = vTemp->next->info->x;
				newlist->info->b->y = vTemp->next->info->y;
				newlist->info->c->x = thirdb->x;
				newlist->info->c->y = thirdb->y;
				newlist->next = new tList;
				newlist = newlist->next;
				
				vTemp->info = thirda;
				vTemp->next = vTemp->next->next;
			}else{
				vTemp = vTemp->next;
			}
		}else{
			vTemp = vTemp->next;
		}

	}

	cout << "got through the loop" << endl;

	struct vertex *thirdc = new struct vertex;
	struct vertex *thirdd = new vertex;
	thirdc->x = vTemp->info->x;
	thirdc->y = vTemp->info->y;
	thirdd->x = vTemp->next->info->x;
	thirdd->y = vTemp->next->info->y;
	//newlist = newlist->next;
	

	return newlist;	
}
