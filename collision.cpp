#include "prototype.h"

bool isInViewport(struct vertex * vert) {
	struct vertex * lineA, * lineB;

	bool inside = false;

	int intersections;
	
	lineA->x = vert->x;
	lineA->y = vert->y;

	lineB->x = viewWidth;
	lineB->y = vert->y;

	for (int i = 0;i<8;i++) {
		if (i!=7) {
			if (intersect(lineA, lineB, &clipperVerts[i], &clipperVerts[i+1]))
				intersections++;
		}
		else {
			if (intersect(lineA, lineB, &clipperVerts[i], &clipperVerts[0]))
				intersections++;
		}
	}

	if (intersections % 2 == 1)
		inside = true;

	return inside;
}
bool noIntersectsVList4Gray(vList *list0,  vList *list1)
{
	vList *speed = new vList;
	vList *fast  = new vList;
	speed = list0;
	fast  = list1;
	
	do
	{
		vertex *a,*b,*c,*d;
		a = list0->info;
		b = list0->next->info;
		do
		{
			c = list1->info;
			d = list1->next->info;
			if(intersect(a,b,c,d))
				return false;
			list1=list1->next;
//			cout << "no intersect"<<endl;
		}while(list1!=fast);

		list0=list0->next;

	}while(list0!=speed);
//	cout << "NO INTERSECTS AT ALL" <<endl;
	return true;

}
//bool intersect(struct vertex *a, struct vertex *b, struct vertex *c, struct vertex *d){
