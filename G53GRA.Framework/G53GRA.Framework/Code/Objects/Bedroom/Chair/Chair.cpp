#include "Chair.h"

void Chair::Display()
{
	glColor3f(0.1f, 0.1f, 0.1f);
	makeChair();
	makeBase();
}

void Chair::makeBase()
{
	legLength = width *2.f;
	legWidth = width * 0.5f;
	wheelRadius = 0.05f * height;
	glPushMatrix();
	glTranslatef(0.f,  wheelRadius + (height * 0.5f), 0.f);
	simpleShape.makeCylinder(height *0.5, width* 0.5f, false, false);
	glPopMatrix();
	glTranslatef(0.f, wheelRadius, 0.f);
	float angle = baseAngle;
	do
	{
		glPushMatrix();
		glRotatef(angle, 0.f, 1.f, 0.f);
		simpleShape.makeCuboid(legWidth, legWidth, legLength);

		glTranslatef((wheelRadius) + (0.5f* legWidth), -wheelRadius, legLength * 0.75f);
		glRotatef(90.f, 0.f, 0.f, 1.f);
		simpleShape.makeCylinder(wheelRadius *0.25f, wheelRadius, true, true);

		glPopMatrix();
		angle += baseAngle;
	} while (angle < 361);
}

void Chair::makeChair()
{
	glPushMatrix();
	glTranslatef(-2.f*width, height * 0.55f,  2.f * width);
	simpleShape.makeCuboid(4.f*width, height*0.05f, 4.f*width);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.f*width, height * 0.55f, -2.f * width);
	simpleShape.makeCuboid( 4.f*width, height *0.75f, height*0.05f);
	glPopMatrix();
}

