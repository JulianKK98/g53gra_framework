#include "Bed.h"

Bed::Bed(float l, float w, float h):
	length(l), width(w), height(h)
{
	framePillarWidth = 0.1f * width;
}

void Bed::Display()
{
	glTranslatef(pos[0], pos[1], pos[2]);
	glScalef(scale[0], scale[1], scale[2]);
	glRotatef(rotation[0], 1.f, 0.f, 0.f); //x
	glRotatef(rotation[1], 0.f, 1.f, 0.f); //y
	glRotatef(rotation[2], 0.f, 0.f, 1.f); //z
	makeFrame();
	makeBedding();
	makePillow();
	
}

void Bed::makePillow()
{
	const float pillowHeight = (height*0.55) - (height * 0.4);
	
	glPushMatrix();
	glColor3f(0.9f, 0.9f, 0.9f);
	glTranslatef(framePillarWidth, height * 0.65f, length * 0.25f);
	simpleShape.makeCuboid(width *0.35, pillowHeight, length * 0.2f);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.9f, 0.9f, 0.9f);
	glTranslatef(framePillarWidth + (width * 0.5f), height * 0.65f, length * 0.25f);
	simpleShape.makeCuboid(width *0.35, pillowHeight, length * 0.2f);
	glPopMatrix();
}

void Bed::makeFrame()
{
	std::string floorTexPath = "Textures/wood2.bmp";
	frameTex = Scene::GetTexture(floorTexPath);

	const float plankThickness = framePillarWidth * 0.25;
	//Pillar at 0,0,0 local
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(0.f, 0.f, framePillarWidth *0.5);
	simpleShape.makeCuboid(framePillarWidth, height, framePillarWidth, frameTex, 1);
	glPopMatrix();

	//front plank 1 - lower
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(framePillarWidth, height * 0.3, 0);
	simpleShape.makeCuboid(width - framePillarWidth, framePillarWidth, plankThickness, frameTex, 1);
	glPopMatrix();

	//front plank 2 - upper
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(framePillarWidth, height * 0.75, 0);
	simpleShape.makeCuboid(width - framePillarWidth, framePillarWidth, plankThickness, frameTex, 1);
	glPopMatrix();

	//Pillar at width,0,0 - local
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(width, 0.f, framePillarWidth *0.5);
	simpleShape.makeCuboid(framePillarWidth, height, framePillarWidth, frameTex, 1);
	glPopMatrix();

	//Side - lower frame left
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(framePillarWidth * 0.5f, height * 0.3, length);
	simpleShape.makeCuboid(framePillarWidth * 0.5f, framePillarWidth, length, frameTex, 1);
	glPopMatrix();

	//Side - lower frame right
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(width + (0.125f * framePillarWidth), height * 0.3, length);
	simpleShape.makeCuboid(framePillarWidth * 0.5f, framePillarWidth, length, frameTex, 1);
	glPopMatrix();

	//Pillar at width,0,length
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(width, 0.f, length);
	simpleShape.makeCuboid(framePillarWidth, height * 0.75f, framePillarWidth, frameTex, 1);
	glPopMatrix();

	//Pillar at 0, 0,length
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(0.f, 0.f, length);
	simpleShape.makeCuboid(framePillarWidth, height * 0.75f, framePillarWidth, frameTex, 1);
	glPopMatrix();

	//Back plank 1 - lower
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(framePillarWidth, height * 0.3, length - (0.25f * framePillarWidth));
	simpleShape.makeCuboid(
		width - framePillarWidth, 
		framePillarWidth, 
		plankThickness, 
		frameTex,
		1
	);
	glPopMatrix();

	//Back plank 1 - upper
	glPushMatrix();
	glTranslatef(framePillarWidth, height * 0.55f, length - (0.25f * framePillarWidth));
	simpleShape.makeCuboid(
		width - framePillarWidth, 
		framePillarWidth, 
		plankThickness, 
		frameTex,
		1
	);
	glPopMatrix();

}

void Bed::makeBedding()
{
	float beddingHeight = (height*0.55) - (height * 0.3);
	glPushMatrix();
	glTranslatef(framePillarWidth, height * 0.4f, length * 0.25f);
	glColor3f(1.f, 1.f, 1.f);
	simpleShape.makeCuboid(width - framePillarWidth, beddingHeight, length *0.25f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(framePillarWidth, height * 0.4f, length);
	glColor3f(0.3f, 0.3f, 0.3f);
	simpleShape.makeCuboid(width - framePillarWidth, beddingHeight, length *0.75f);
	glPopMatrix();
}