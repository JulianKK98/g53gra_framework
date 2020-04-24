#include "Walls.h"

Walls::Walls(){}

void Walls::Display() 
{
	glTranslatef(pos[0], pos[1], pos[2]);
	glScalef(scale[0], scale[1], scale[2]);
	glRotatef(rotation[1], 0.f, 1.f, 0.f); //y
	glRotatef(rotation[2], 0.f, 0.f, 1.f); //z
	glRotatef(rotation[0], 1.f, 0.f, 0.f); //x
	
	//Draw left wall
	glBegin(GL_QUAD_STRIP);
	glColor3f(0.3f, 0.3f, 0.9f);
	glVertex3f(-100.f, 0.f, 0.f);
	glVertex3f(-100.f, 0.f, 500.f);
	glVertex3f(-100.f, 100.f, 500.f);
	glVertex3f(-100.f, 100.f, 0.f);
	glEnd();


}