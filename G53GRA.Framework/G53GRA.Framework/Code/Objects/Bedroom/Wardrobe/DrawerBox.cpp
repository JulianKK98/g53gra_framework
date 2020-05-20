#include "DrawerBox.h"

void DrawerBox::Display()
{
	glColor3ub(colour[0], colour[0], colour[0]);
	makeBox(length, length, length);
}

void DrawerBox::makeBox(float width, float height, float thickness) {
	glBegin(GL_QUADS);
	//front
	glNormal3d(0, 0, 1);
	glVertex3f(0.f, 0.f, 0.f);
	glVertex3f(width, 0.f, 0.f);
	glVertex3f(width, height, 0.f);
	glVertex3f(0.f, height, 0.f);
	//back
	glNormal3d(0, 0, -1);
	glVertex3f(width, 0.f, -thickness);
	glVertex3f(0.f, 0.f, -thickness);
	glVertex3f(0.f, height, -thickness);
	glVertex3f(width, height, -thickness);
	//left
	glNormal3d(1, 0, 0);
	glVertex3f(0.f, 0.f, 0.f);
	glVertex3f(0.f, height, 0.f);
	glVertex3f(0.f, height, -thickness);
	glVertex3f(0.f, 0.f, -thickness);
	//right
	glNormal3d(-1, 0, 0);
	glVertex3f(width, 0.f, 0.f);
	glVertex3f(width, 0.f, -thickness);
	glVertex3f(width, height, -thickness);
	glVertex3f(width, height, 0.f);
	//bottom
	glNormal3d(0, 1, 0);
	glVertex3f(0.f, 0.f, -thickness);
	glVertex3f(width, 0.f, -thickness);
	glVertex3f(width, 0.f, 0.f);
	glVertex3f(0.f, 0.f, 0.f);
	glEnd();
}