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
	glEnable(GL_LIGHTING);
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
	setUpLight(GL_LIGHT0, 50.f);
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
	glDisable(GL_LIGHTING);
}

void RoomLight::setUpLight(GLenum lightNum, float cutoffDegree)
{
	float dir[3] = { 0.0, -1.0, 0.0 };
	float amb[4] = { 1.0, 0.93f, 0.85, 1.0f };
	float diff[4] = { 0.9f, 0.9f, 0.9f, 1.0f };
	float spec[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float pos[3] = { 0.f, 100.f, 0.f};
	glLightfv(lightNum, GL_AMBIENT, amb);
	glLightfv(lightNum, GL_DIFFUSE, diff);
	glLightfv(lightNum, GL_SPECULAR, spec);
	glLightfv(lightNum, GL_POSITION, pos);

	glLightfv(lightNum, GL_SPOT_DIRECTION, dir);
	glLightf(lightNum, GL_SPOT_CUTOFF, cutoffDegree);
}

