#include "prototype.h"


struct vList * copyvList(struct vList *original){

	struct vList *oStart = original;

	struct vList *copy = new vList;
	struct vList *cStart = copy;
	copy->info = new vertex;

	do{
		
		copy->info->x = original->info->x;
		copy->info->y = original->info->y;	
		//these are not necessary unless we can come up with a reason later

		//copy->info->z = original->info->z;
		//copy->info->w = original->info->w;		

		copy->info->z = 0;
		copy->info->w = 1;

		original = original->next;
		if(oStart != original){
			copy->next = new vList;
			copy = copy->next;
			copy->info = new vertex;
		}else{
			copy->next = cStart;
		}
	}while(original != oStart);

	

	return copy;

}

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

	if((ua/denom > 0 && ua/denom < 1) && (ub/denom > 0 && ub/denom < 1)){
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

	//cout << "start tesselate" << endl;

	glColor3f(0.0,0.0,0.0);

	struct vList *copy = copyvList(original);

	struct vList *vTemp = original;
	struct tList *newlist = new tList;
	struct tList *nlStart = newlist;
	newlist->info = new triangle;

	//cout << "before while loop" << endl;
	cout << vTemp->next->info->x << endl;
	while(vTemp->next->next->next != vTemp){
		//cout << "before if statement" << endl;
		if(crossProd(vTemp->info,vTemp->next->info,vTemp->next->next->info) > 0){

			cout << "start of loop" << endl;


			struct vertex *thirda = vTemp->info;
                        struct vertex *thirdb = vTemp->next->next->info;
                        struct vertex *thirdabi = new vertex;
                        struct vertex *thirdbbi = vTemp->next->info;
			//cout << "after the thirds" << endl;
			
			thirdabi->x = (thirda->x+thirdb->x)/2;
			thirdabi->y = (thirda->y+thirdb->y)/2;
			//thirdbbi->x = vTemp->next->info->x;
			//thirdbbi->y = vTemp->next->info->y;

			int inter = 0;
			struct vList *iter = vTemp->next;
			
			while(inter == 0 && iter != vTemp){
				
				if(intersect(thirda,thirdb,iter->info, iter->next->info)){
					inter++;
				}else if(intersect(thirdabi,thirdbbi,iter->info, iter->next->info)){
					inter++;
				}else{
					cout << "ivfvfiyfiv"<<endl;
					iter = iter->next;
				}
			}
			cout <<inter<<endl;
			if(inter == 0){
				cout << "good news brah"<<endl;
				newlist->info->a = thirda;
                                newlist->info->b = vTemp->next->info;
                                newlist->info->c = thirdb;

				cout << "cy" << newlist->info->c->y << endl;

				newlist->next = new tList;
				newlist = newlist->next;
				newlist->info = new triangle;			
	
				vTemp->info = thirda;
				vTemp->next = vTemp->next->next;
			}else{
				//cout << "moving down the list because i have intersected"<<endl;
				//vTemp = vTemp->next;
			}
		}else{
			//cout << "am clockwise"<<endl;
			vTemp = vTemp->next;
		}

	}

	//newlist->info = new triangle;
	cout << "got through the loop" << endl;

	struct vertex *thirdc = new vertex;
	struct vertex *thirdd = new vertex;
	thirdc->x = vTemp->info->x;
	thirdc->y = vTemp->info->y;
	thirdd->x = vTemp->next->info->x;
	thirdd->y = vTemp->next->info->y;

	//cout << "cy" << vTemp->next->next->info->y << endl;

	newlist->info->a = thirdc;
	newlist->info->b = thirdd;
	newlist->info->c = vTemp->next->next->info;
	//newlist->info->c->y = vTemp->next->next->info->y;
	newlist->next = nlStart;
	
	return newlist;	
}
