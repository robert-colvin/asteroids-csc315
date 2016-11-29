#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>

#ifndef PROTO
#define PROTO

extern float winWidth, winHeight, viewWidth, accuracy;
extern int shotsFired, asteroidsHit, asteroidsOnScreen;

void viewportInit();

struct vertex{

	float x;
	float y;
	float z;
	float w;

};

struct vList{

	struct vertex *info;
	struct vList *next;

};

struct triangle{

	struct vertex *a;
	struct vertex *b;
	struct vertex *c;

};

struct tList{

	struct triangle *info;
	struct tList *next;

};

struct asteroid{

	struct vertex *origin;
	float spin;	// need to determine if this is in degrees or radians
	struct vList *edge;
	struct tList *tess;
	 

};
#endif
