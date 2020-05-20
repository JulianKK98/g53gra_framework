#include "Wardrobe.h"

void Wardrobe::Display()
{
	if(wardrobeTex == 0)
	{
		wardrobeTex = Scene::GetTexture("Textures/wood2.bmp");
	}
	topSectionThickness = height * 0.1f;
	glColor3ub(168, 121, 54);
	glPushMatrix();
	glTranslatef(0.f, height - topSectionThickness, length);
	simpleShape.makeCuboid(
		width, 
		topSectionThickness, 
		length,
		wardrobeTex,
		1);
	glPopMatrix();
	makeBase(); 
	makeSupports();
	makeDoors();
}

void Wardrobe::makeBase()
{
	glPushMatrix();
	glTranslatef(legWidth, legWidth, length - legWidth);
	simpleShape.makeCuboid(
		width-(2.f*legWidth), 
		height - topSectionThickness, 
		length - (2.f*legWidth),
		wardrobeTex,
		1
	);
	glPopMatrix();
}

void Wardrobe::makeSupports()
{
	float legHeight = height - topSectionThickness;
	//leg 1
	glPushMatrix();
	glTranslatef(0.f, 0.f, legWidth);
	simpleShape.makeCuboid(
		legWidth, 
		legHeight, 
		legWidth,
		wardrobeTex,
		1
	);
	glPopMatrix();

	//support 1
	glPushMatrix();
	glTranslatef(legWidth, legWidth, legWidth);
	simpleShape.makeCuboid(
		width - (2*legWidth),
		legWidth, 
		legWidth,
		wardrobeTex,
		1
	);
	glPopMatrix();

	//leg 2
	glPushMatrix();
	glTranslatef(width -legWidth, 0.f, legWidth);
	simpleShape.makeCuboid(
		legWidth, 
		legHeight, 
		legWidth,
		wardrobeTex,
		1
	);
	glPopMatrix();

	//support 2 
	glPushMatrix();
	glTranslatef(0.f, legWidth, length - legWidth);
	simpleShape.makeCuboid(
		legWidth, 
		legWidth, 
		width - (legWidth * 4.f),
		wardrobeTex,
		1
	);
	glPopMatrix();

	//leg 3
	glPushMatrix();
	glTranslatef(width - legWidth, 0.f, length);
	simpleShape.makeCuboid(
		legWidth, 
		legHeight, 
		legWidth,
		wardrobeTex,
		1
	);
	glPopMatrix();

	//support 3
	glPushMatrix();
	glTranslatef(legWidth, legWidth, length);
	simpleShape.makeCuboid(
		width - (2 * legWidth), 
		legWidth, 
		legWidth,
		wardrobeTex,
		1
	);
	glPopMatrix();

	//leg 4
	glPushMatrix();
	glTranslatef(0.f, 0.f, length);
	simpleShape.makeCuboid(
		legWidth, 
		legHeight, 
		legWidth,
		wardrobeTex,
		1);
	glPopMatrix();

	//support 4
	glPushMatrix();
	glTranslatef(width - legWidth, legWidth, length - legWidth);
	simpleShape.makeCuboid(
		legWidth, 
		legWidth, 
		width - (legWidth * 4.f),
		wardrobeTex,
		1);
	glPopMatrix();
}

void Wardrobe::makeDoors()
{
	float doorWidth = (width * 0.5f) - legWidth;
	float leftHandleX = doorWidth * 0.8f;
	float rightHandleX = doorWidth * 0.2f;
	float doorHeight = height - (topSectionThickness + 2.f*legWidth);
	glColor3ub(227, 182, 118);
	glPushMatrix();
	glTranslatef(legWidth, legWidth*2.f, legWidth);
	simpleShape.makeCuboid(
		doorWidth,
		doorHeight, 
		legWidth * 0.5f,
		wardrobeTex,
		2
	);
	glPushMatrix();
	glColor3f(0.3f, 0.3f, 0.3f);
	glTranslatef(leftHandleX, doorHeight * 0.5f, -doorWidth*0.1f);
	simpleShape.makeCuboid(
		doorWidth*0.1f,
		doorWidth*0.1f,
		doorWidth*0.1f);
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glColor3ub(227, 182, 118);
	glTranslatef((width*0.5f), legWidth*2.f, legWidth);
	simpleShape.makeCuboid(
		doorWidth,
		doorHeight,
		legWidth * 0.5f,
		wardrobeTex,
		2
	);

	glPushMatrix();
	glColor3f(0.3f, 0.3f, 0.3f);
	glTranslatef(rightHandleX - doorWidth * 0.1f, doorHeight * 0.5f, -doorWidth * 0.1f);
	simpleShape.makeCuboid(
		doorWidth*0.1f, 
		doorWidth*0.1f, 
		doorWidth*0.1f);
	glPopMatrix();;

	glPopMatrix();
}

