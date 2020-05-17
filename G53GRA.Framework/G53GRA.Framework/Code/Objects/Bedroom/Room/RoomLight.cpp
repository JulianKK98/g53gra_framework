#include "RoomLight.h"

SimpleShapes simpleShape;

RoomLight::RoomLight() 

{
	radius = 10.f;
	height = 0.25f;
	lampHead1 = new LampHead(3.f, 4.f, 10.f, 5.f, 3.f);
	lampHead2 = new LampHead(3.f, 4.f, 10.f, 5.f, 3.f);
	lampHead3 = new LampHead(3.f, 4.f, 10.f, 5.f, 3.f);
	lampHead4 = new LampHead(3.f, 4.f, 10.f, 5.f, 3.f);
}

RoomLight::~RoomLight() 
{
	delete lampHead1;
	delete lampHead2;
	delete lampHead3;
	delete lampHead4;

}


void RoomLight::Display()
{
	glTranslatef(pos[0], pos[1], pos[2]);
	glScalef(scale[0], scale[1], scale[2]);
	glRotatef(rotation[0], 1.f, 0.f, 0.f); //x
	glRotatef(rotation[1], 0.f, 1.f, 0.f); //y
	glRotatef(rotation[2], 0.f, 0.f, 1.f); //z

	float squarelength =  0.5f * radius;
	float scaleFactor = 0.5f;

	float yPos = 1.f;
	//Make base
	glPushMatrix();
	glColor3f(0.5f, 0.5f, 0.5f);
	simpleShape.makeCylinder(height, radius, true, true);
	glPopMatrix();
	
	//pivot point 1
	glPushMatrix();
	glColor3f(0.5f, 0.5f, 0.5f);
	glTranslatef(-squarelength, 0.f, -squarelength);
	simpleShape.makeCylinder(1.f, 1.f, true, true);
	glPushMatrix();
	glTranslatef(0.f, -yPos, 0.f);
	glutSolidSphere(0.9f, 15, 15);
	glScalef(scaleFactor, scaleFactor, scaleFactor);
	lampHead1->Display();
	glPopMatrix();

	glPopMatrix();
	
	//pivot point 2
	glPushMatrix();
	glColor3f(0.5f, 0.5f, 0.5f);
	glTranslatef(squarelength, 0.f, -squarelength);
	simpleShape.makeCylinder(1.f, 1.f, true, true);

	glPushMatrix();
	glTranslatef(0.f, -yPos, 0.f);
	glutSolidSphere(0.9f, 15, 15);
	glRotatef(45.f, 1.f, 0.f, 0.f);
	glScalef(scaleFactor, scaleFactor, scaleFactor);
	lampHead2->Display();
	glPopMatrix();

	glPopMatrix();

	//pivot point 3
	glPushMatrix();
	glColor3f(0.5f, 0.5f, 0.5f);
	glTranslatef(squarelength, 0.f, squarelength);
	simpleShape.makeCylinder(1.f, 1.f, true, true);

	glPushMatrix();
	glTranslatef(0.f, -yPos, 0.f);
	glutSolidSphere(0.9f, 15, 15);
	glRotatef(-30.f, 0.5f, 1.f, 0.f);
	glScalef(scaleFactor, scaleFactor, scaleFactor);
	lampHead3->Display();
	glPopMatrix();

	glPopMatrix();

	//pivot point 4
	glPushMatrix();
	glTranslatef(-squarelength, 0.f, squarelength);
	glColor3f(0.5f, 0.5f, 0.5f);
	simpleShape.makeCylinder(1.f, 1.f, true, true);

	glPushMatrix();
	glTranslatef(0.f, -yPos, 0.f);
	glutSolidSphere(0.9f, 15, 15);
	glRotatef(-45.f, 1.f, 1.f, 0.f);
	glScalef(scaleFactor, scaleFactor, scaleFactor);
	lampHead4->Display();
	glPopMatrix();

	glPopMatrix();
}

