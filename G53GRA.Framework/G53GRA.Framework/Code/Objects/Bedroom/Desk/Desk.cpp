#include "Desk.h"

void Desk::Display()
{
	std::string deskTexPath = "Textures/wood1.bmp";
	deskTex = Scene::GetTexture(deskTexPath);
	makeTableLegs();

	glPushMatrix();
	glTranslatef(0.f, height - tableThickness, length);
	glColor4f(1.f, 1.f, 1.f, 1.f);
	simpleShapes.makeCuboid(width, tableThickness, length, deskTex, 1);
	glPopMatrix();
	
}

//Makes table legs and applies shiny texture to them
void Desk::makeTableLegs()
{
	
	glColor4f(0.1f, 0.1f, 0.1f, 1.f);
	glPushMatrix();
	glTranslatef(0.f, 0.f, legWidth);
	simpleShapes.makeCuboid(legWidth, height - tableThickness, legWidth);
	glPopMatrix();

	glPushMatrix();
	
	glTranslatef(width-legWidth, 0.f, legWidth);
	simpleShapes.makeCuboid(legWidth, height - tableThickness, legWidth);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(width - legWidth, 0.f, length);
	simpleShapes.makeCuboid(legWidth, height - tableThickness, legWidth);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.f, 0.f, length);
	simpleShapes.makeCuboid(legWidth, height - tableThickness, legWidth);
	glPopMatrix();
}

