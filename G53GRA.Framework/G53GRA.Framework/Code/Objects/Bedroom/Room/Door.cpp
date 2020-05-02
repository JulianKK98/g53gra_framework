#include "Door.h"
#include <cmath>
#include <VectorMath.h>
void Door::Display() {
	glTranslatef(pos[0], pos[1], pos[2]);
	glScalef(scale[0], scale[1], scale[2]);
	glRotatef(rotation[0], 1.f, 0.f, 0.f); //x
	glRotatef(rotation[1], 0.f, 1.f, 0.f); //y
	glRotatef(rotation[2], 0.f, 0.f, 1.f); //z
	makeDoor();
	makeDoorKnob();
}


void Door::makeDoor() {
	glBegin(GL_QUADS);
	glColor3f(1.f, 1.f, 1.f);
	//front
	glVertex3f(0.f, 0.f, thickness);
	glVertex3f(width, 0.f, thickness);
	glVertex3f(width, height, thickness);
	glVertex3f(0.f, height, thickness);

	//back
	glNormal3d(1, 1, 1);
	glVertex3f(width, 0.f, 0.f);
	glVertex3f(0.f, 0.f, 0.f);
	glVertex3f(0.f, height, 0.f);
	glVertex3f(width, height, 0.f);
	
	//left
	glNormal3d(1, 0, 0);
	glVertex3f(width, 0.f, thickness);
	glVertex3f(width, 0.f, 0.f);
	glVertex3f(width, height, 0.f);
	glVertex3f(width, height, thickness);
	//left
	glNormal3d(-1, 0, 0);
	glVertex3f(0.f, 0.f, 0.f);
	glVertex3f(0.f, 0.f, thickness);
	glVertex3f(0.f, height, thickness);
	glVertex3f(0.f, height, 0.f);
	//top
	glNormal3d(0, -1, 0);
	glVertex3f(0.f, height, thickness);
	glVertex3f(width, height, thickness);
	glVertex3f(width, height, 0.f);
	glVertex3f(0.f, height, 0.f);

	//bottom
	glNormal3d(0, 1, 0);
	glVertex3f(0.f, 0.f, 0.f);
	glVertex3f(width, 0.f, 0.f);
	glVertex3f(width, 0.f, thickness);
	glVertex3f(0.f, 0.f, thickness);

	glEnd();
}

void Door::makeDoorKnob() {
	float doorKnobX = 0.1f * width;
	float doorKnobY = 0.5f * height;
	
	glPushMatrix();
	glColor3f(0.f, 0.f, 1.f);
	glTranslatef(doorKnobX, doorKnobY, 2.f * thickness);
	glRotatef(90.f, 1.f, 0.f, 0.f);
	cylinder(2.f, 1.f);
	glPopMatrix();
}

/*
*Using cylinder implementation from lab 2
*/
void Door::cylinder(float h, float r)
{
	float res = 0.1*M_PI;           // resolution (in radians: equivalent to 18 degrees)
	float x = r, z = 0.f;           // initialise x and z on right of cylinder centre
	float t = 0.f;                  // initialise angle as 0

	do
	{
		glBegin(GL_QUADS);          // new QUAD
			// Create first points
		glVertex3f(x, h, z);    // top
		glVertex3f(x, 0.f, z);  // bottom
		// Iterate around circle
		t -= res;               // add increment to angle
		x = r * cos(t);           // move x and z around circle
		z = r * sin(t);
		// Close quad
		glVertex3f(x, 0.f, z);  // bottom
		glVertex3f(x, h, z);    // top
		glEnd();                    // end shape
	} while (t >= 2 * -M_PI);        // for a full circle (360 degrees)

	//make front face 
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(r / 2.f, 0.f, r / 2.f); //centre point
	do 
	{
		glVertex3f(x, 0.f, z);
		// Iterate around circle
		t -= res;               // add increment to angle
		x = r * cos(t);           // move x and z around circle
		z = r * sin(t);
		
		glVertex3f(x, 0.f, z);  // bottom
		
	} 
	while (t >= 2 * -M_PI);
	glEnd();


}
