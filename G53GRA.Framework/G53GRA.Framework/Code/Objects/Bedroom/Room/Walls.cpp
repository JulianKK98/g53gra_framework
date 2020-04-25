#include "Walls.h"

Walls::Walls(){}

void Walls::Display() 
{
	float length = 100.f;
	float width = 50.f;
	float height = 20.f;
	float doorWidth = width * 0.25;
	float doorHeight = height * 0.85;

	glTranslatef(pos[0], pos[1], pos[2]);
	glScalef(scale[0], scale[1], scale[2]);
	glRotatef(rotation[1], 0.f, 1.f, 0.f); //y
	glRotatef(rotation[2], 0.f, 0.f, 1.f); //z
	glRotatef(rotation[0], 1.f, 0.f, 0.f); //x
	
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

	glEnd();


}