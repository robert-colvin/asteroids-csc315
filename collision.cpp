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
