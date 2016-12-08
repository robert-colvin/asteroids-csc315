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
extern struct aList *Aster;
extern float playerRot;
extern bool startGame;
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
void displayAsteroids(bool);
void rotatePoint(struct vertex * point, float centerX, float centerY, float angle);
bool intersect(struct vertex *a, struct vertex *b, struct vertex *c, struct vertex *d);
void clipperInit();
void checkWrap(struct aList *Aster);
void flipPoint(struct vertex * point, float centerX, float centerY);
float distAway(float x1, float y1);
bool isInViewport(struct vertex * vert);


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

struct mList{
	struct vList *edge;
	struct vertex *origin;
	float xSpeed;
	float ySpeed;
	struct mList *next;

};

struct tList{

	struct triangle *info;
	struct tList *next;

};

struct aList{ 

	struct asteroid *info;
	struct aList *next;

};

struct asteroid{

	struct vertex *origin;
	float spin;	// degree value
	float xSpeed; //x speed value
	float ySpeed; //y speed value
	struct vList *edge;
	struct tList *tess;
	 

};

#endif
