#include "Room.h"


Room:: ~Room()
{
	delete[] windows;
}

void Room::Display() {
	glTranslatef(pos[0], pos[1], pos[2]);
	glScalef(scale[0], scale[1], scale[2]);
	glRotatef(rotation[0], 1.f, 0.f, 0.f); //x
	glRotatef(rotation[1], 0.f, 1.f, 0.f); //y
	glRotatef(rotation[2], 0.f, 0.f, 1.f); //z
	makeWalls();
	makeFloorNCeiling();
	pillarWidth = 0.3f * width;
	makeWindowSill(0.05f, 0.3f);
	makeWindows();
	
}


void Room::makeWalls() {
	float doorWidth = width * 0.25;
	float doorHeight = height * 0.80;
	alcoveWidth = -width + (doorWidth / 2.f);
	//Draw right wall
	glBegin(GL_QUADS);
	glNormal3d(-1, 0, 0);
	glColor3f(1.f, 1.f, 1.f);
	glVertex3f(0.f, 0.f, 0.f);
	glVertex3f(0.f, height, 0.f);
	glVertex3f(0.f, height, -length);
	glVertex3f(0.f, 0.f, -length);
	//Above door
	glNormal3d(0, 0, 0);
	glVertex3f(0.f, doorHeight, -length);
	glVertex3f(0.f, height, -length);
	glVertex3f(-doorWidth, height, -length);
	glVertex3f(-doorWidth, doorHeight, -length);
	//wall next to door
	glVertex3f(-doorWidth, 0.f, -length);
	glVertex3f(-doorWidth, height, -length);
	glVertex3f(-width, height, -length);
	glVertex3f(-width, 0.f, -length);

	//Left wall alcove
	glNormal3d(1, 0, 0);
	glColor3f(0.5f, 0.5f, 1.f);
	glVertex3f(-width, 0.f, -length);
	glVertex3f(-width, height, -length);
	glVertex3f(-width, height, -length * 0.5f);
	glVertex3f(-width, 0.f, -length * 0.5f);

	//alcove
	glNormal3d(1, 1, 1);
	glVertex3f(-width, 0.f, -length * 0.5f);
	glVertex3f(-width, height, -length * 0.5f);
	glVertex3f(alcoveWidth, height, -length * 0.5f);
	glVertex3f(alcoveWidth, 0.f, -length * 0.5f);
	//left wall
	glNormal3d(1, 0, 0);
	glVertex3f(alcoveWidth, 0.f, -length * 0.5f);
	glVertex3f(alcoveWidth, height, -length * 0.5f);
	glVertex3f(alcoveWidth, height, 0.0f);
	glVertex3f(alcoveWidth, 0.0f, 0.0f);
	glEnd();
}

void Room::makeFloorNCeiling() 
{
	//floor
	glBegin(GL_QUADS);
	glNormal3d(0, 1, 0);
	glColor3f(0.65f, 0.16f, 0.16f);
	glVertex3f(0.f, 0.f, 0.f);
	glVertex3f(0.f, 0.f, -length);
	glVertex3f(-width, 0.f, -length);
	glVertex3f(-width, 0.f, 0.f);

	//ceiling
	glNormal3d(0, -1, 0);
	glColor3f(1.f, 1.f, 1.f);
	glVertex3f(-width, height, 0.f);
	glVertex3f(-width, height, -length);
	glVertex3f(0.f, height, -length);
	glVertex3f(0.f, height, 0.f);
	glEnd();
}


void Room::makeWindowSill(float thicknessMod, float heightMod)
{
	windowSillHeight = height * heightMod;
	float windowSillZ = thicknessMod * - length;
	
	//windowsill wall
	glBegin(GL_QUADS);
	glNormal3d(1, 1, 1);
	glColor3f(1.f, 1.f, 1.f);
	glVertex3f(0.f, 0.f, windowSillZ);
	glVertex3f(-width, 0.f, windowSillZ);
	glVertex3f(-width, windowSillHeight, windowSillZ);
	glVertex3f(0.f, windowSillHeight, windowSillZ);
	
	//windowSill
	glNormal3d(0, 0, 1);
	glVertex3f(0.f, windowSillHeight, 0.f);
	glVertex3f(0.f, windowSillHeight, windowSillZ);
	glVertex3f(-width, windowSillHeight, windowSillZ);
	glVertex3f(-width, windowSillHeight, 0.f);
	glEnd();
}

void Room::makePillar() 
{
	float pillarXPos = -0.5* width;
	float pillarLeft = pillarXPos + (pillarWidth /2.f);
	float pillarRight = pillarXPos - (pillarWidth / 2.f);

	glBegin(GL_QUADS);
	//right side
	glNormal3d(-1, 0, 0);
	glVertex3f(pillarLeft, 0.f, 0.f);
	glVertex3f(pillarLeft, 0.f, -pillarWidth);
	glVertex3f(pillarLeft, height, -pillarWidth);
	glVertex3f(pillarLeft, height, 0.f);
	//back
	glNormal3d(1, 1, 1);
	glVertex3f(pillarLeft, 0.f, -pillarWidth);
	glVertex3f(pillarRight, 0.f, -pillarWidth);
	glVertex3f(pillarRight, height, -pillarWidth);
	glVertex3f(pillarLeft, height, -pillarWidth);
	//left side
	glNormal3d(1, 0, 0);
	glVertex3f(pillarRight, height, 0.f);
	glVertex3f(pillarRight, height, -pillarWidth);
	glVertex3f(pillarRight, 0.f, -pillarWidth);
	glVertex3f(pillarRight, 0.f, 0.f);
	glEnd();
}

void Room::makeWindows() 
{
	Window window1;
	Window window2;
	Window window3;

	glPushMatrix();

	//work on making the windows

	glPopMatrix();
}

