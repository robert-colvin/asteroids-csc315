#include "prototype.h"

bool isInViewport(struct vertex * vert) {
	struct vertex * lineA = new vertex;
	struct vertex * lineB = new vertex;

	bool inside = false;

	int intersections = 0;
	
	lineA->x = vert->x;
	lineA->y = vert->y;

	lineB->x = winWidth;
	lineB->y = vert->y;

	for (int i = 0;i<8;i++) {
		if (i!=7) {
			if (intersect(lineA, lineB, &clipperVerts[i], &clipperVerts[i+1])) {
				intersections++;
				cout << "im intersecting right now\n";
			}
		}
		else {
			if (intersect(lineA, lineB, &clipperVerts[i], &clipperVerts[0])) {
				intersections++;
				cout << "im intersecting right now\n";
			}
		}
	}

	cout << "intersections is " << intersections << "\n";

	if (intersections == 1) {
		inside = true;
		cout << "im in the viewport right now\n";
	}

	cout << "im returning " << inside << "\n";

	return inside;
}
