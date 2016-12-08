#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include <string.h>
#include <sstream>
#include <cstdlib>
#include <cmath>


#ifndef PROTO
#define PROTO

using namespace std;

extern float winWidth, winHeight, viewWidth, scoreboardHeight, scoreboardWidth;
extern int shotsFired, asteroidsHit, asteroidsOnScreen;
extern struct vertex clipperVerts[8];
extern struct vList *Player;
extern struct vList *p2;
extern struct aList *Aster;
extern float playerRot;
extern bool startGame;
extern bool filled;
extern struct mList *missiles;

extern struct asteroid *test;

void reset();
void viewportInit();
void playerInit();
void printToScoreboard();
void displayPlayer();
void generate();
void createVertices(struct vList * edge);
struct tList *tesselate(struct vList *original);
void displayAsteroids(bool,bool);
bool intersect(struct vertex *a, struct vertex *b, struct vertex *c, struct vertex *d);
bool isInViewport(struct vertex * vert);
bool noIntersectsVList4Gray(vList*,vList*);
void checkCollisions(asteroid *astNow);
struct vList * copyvList(struct vList *original);
typedef struct vertex{

	float x;
	float y;
	float z;
	float w;

}vertex;

typedef struct vList{
	bool broken;
	struct vertex *info;
	struct vList *next;

}vList;

typedef struct triangle{

	struct vertex *a;
	struct vertex *b;
	struct vertex *c;

}triangle;

typedef struct mList{
	struct vList *edge;
	struct vertex *origin;
	float xSpeed;
	float ySpeed;
	struct mList *next;

}mList;

typedef struct tList{

	struct triangle *info;
	struct tList *next;

}tList;

typedef struct aList{ 

	struct asteroid *info;
	struct aList *next;

}aList;

typedef struct asteroid{

//	bool broken;
	struct vertex *origin;
	float spin;	// degree value
	float xSpeed; //x speed value
	float ySpeed; //y speed value
	struct vList *edge;
	struct tList *tess;
	 

}asteroid;

#endif
