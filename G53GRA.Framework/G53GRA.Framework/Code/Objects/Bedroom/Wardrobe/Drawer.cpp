#include "Drawer.h"

Drawer::~Drawer()
{
	delete box1;
	delete box2;
	delete box3;
	delete box4;
}

void Drawer::Display()
{
	if (drawerTex == 0)
	{
		drawerTex = Scene::GetTexture("Textures/wood2.bmp");
	}
	makeFrame();
	makeDrawers();
}


void Drawer::makeFrame()
{
	frameWidth = length* 0.05f;

	//bottom side
	glColor3ub(255, 255, 255);
	simpleShape.makeCuboid(length, frameWidth, length * 0.5f, drawerTex,1);
	//left side
	glPushMatrix();
	glTranslatef(0.f, frameWidth, 0.f);
	simpleShape.makeCuboid(
		frameWidth, 
		length -(2.f*frameWidth), 
		length * 0.5f,
		drawerTex,
		1);
	glPopMatrix();
	//right side
	//left side
	glPushMatrix();
	glTranslatef(length- frameWidth, frameWidth, 0.f);
	simpleShape.makeCuboid(
		frameWidth, 
		length - (2.f*frameWidth), 
		length * 0.5f,
		drawerTex,
		1);
	glPopMatrix();
	//top side
	glPushMatrix();
	glTranslatef(0.f, length - frameWidth, 0.f);
	simpleShape.makeCuboid(length, frameWidth, length * 0.5f, drawerTex, 1);
	glPopMatrix();
	makeCross();
}

void Drawer::makeCross()
{
	crossWidth = frameWidth *0.33f;
	float vertLength = 0.5f*(length - (2.f*frameWidth));
	//horizontal
	glPushMatrix();
	glTranslatef(frameWidth, (length*0.5f) - crossWidth, 0.f);
	simpleShape.makeCuboid(
		length - (2.f*frameWidth), 
		crossWidth, 
		length * 0.5f, 
		drawerTex, 
		1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(length*0.5f, frameWidth, 0.f);
	simpleShape.makeCuboid(
		crossWidth, 
		vertLength, 
		length * 0.5f, 
		drawerTex, 
		1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(length*0.5f, (length*0.5f), 0.f);
	simpleShape.makeCuboid(crossWidth, vertLength, length * 0.5f, drawerTex, 1);
	glPopMatrix();
}

void Drawer::makeDrawers()
{
	float frameWidth = Drawer::frameWidth;
	float pos1[3] = {frameWidth + crossWidth, frameWidth, 0.f};
	float pos2[3] = { frameWidth + crossWidth, length * 0.5f, 0.f };
	float pos3[3] = {length*0.5f + crossWidth, frameWidth, 0.f};
	float pos4[3] = {length*0.5f + crossWidth, length * 0.5f, 0.f };
	float boxLength = (0.5f * length) - (frameWidth + crossWidth);
	int colour1[3] = {52, 232, 235};
	int colour2[3] = {52, 140, 235};

	glPushMatrix();
	glTranslatef(pos1[0], pos1[1], pos1[2]);
	if(box1 == NULL){}
		box1 = new DrawerBox(boxLength, colour1);
	box1->Display();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(pos2[0], pos2[1], pos2[2]);
	if (box2 == NULL)
		box2 = new DrawerBox(boxLength, colour2);
	box2->Display();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(pos3[0], pos3[1], pos3[2]);
	if (box3 == NULL)
		box3 = new DrawerBox(boxLength, colour2);
	box3->Display();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(pos4[0], pos4[1], pos4[2]);
	if (box4 == NULL)
		box4 = new DrawerBox(boxLength, colour1);
	box4->Display();
	glPopMatrix();
}