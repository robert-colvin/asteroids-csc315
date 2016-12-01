#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include <string.h>
#include <sstream>

#ifndef PROTO
#define PROTO

using namespace std;

extern float winWidth, winHeight, viewWidth, scoreboardHeight, scoreboardWidth;
extern int shotsFired, asteroidsHit, asteroidsOnScreen;
extern struct vertex clipperVerts[8];
extern float playerRot;

void viewportInit();
void playerInit();
void printToScoreboard();
void displayPlayer();

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

extern struct vList *Player;

#endif
