#include "Room.h"

void Room::Display() {
	glTranslatef(pos[0], pos[1], pos[2]);
	glScalef(scale[0], scale[1], scale[2]);
	glRotatef(rotation[1], 0.f, 1.f, 0.f); //y
	glRotatef(rotation[2], 0.f, 0.f, 1.f); //z
	glRotatef(rotation[0], 1.f, 0.f, 0.f); //x
	makeWalls();
	makeFloorNCeiling();
	makeWindowSill(0.05f, 0.3f);
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
	float windowSillH = height * heightMod;
	float windowSillZ = thicknessMod * -length;
	//windowsill wall
	glBegin(GL_QUADS);
	glNormal3d(1, 1, 1);
	glColor3f(1.f, 1.f, 1.f);
	glVertex3f(0.f, 0.f, windowSillZ);
	glVertex3f(-width, 0.f, windowSillZ);
	glVertex3f(-width, windowSillH, windowSillZ);
	glVertex3f(0.f, windowSillH, windowSillZ);
	
	//windowSill
	glNormal3d(0, 0, 1);
	glVertex3f(0.f, windowSillH, 0.f);
	glVertex3f(0.f, windowSillH, windowSillZ);
	glVertex3f(-width, windowSillH, windowSillZ);
	glVertex3f(-width, windowSillH, 0.f);
	glEnd();
}

void makePillar() 
{
	//Make pillar
}

