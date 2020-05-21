#include "Wardrobe.h"

void Wardrobe::Display()
{
	glTranslatef(pos[0], pos[1], pos[2]);
	glScalef(scale[0], scale[1], scale[2]);
	glRotatef(rotation[0], 1.f, 0.f, 0.f); //x
	glRotatef(rotation[1], 0.f, 1.f, 0.f); //y
	glRotatef(rotation[2], 0.f, 0.f, 1.f); //z
	if(wardrobeTex == 0)
	{
		wardrobeTex = Scene::GetTexture("Textures/wood2.bmp");
	}
	float mat_colour[]                      // colour reflected by diffuse light
		= { 1.f, 1.f, 1.f, 1.f };
	float mat_ambient[]                     // ambient colour
		= { 0.29f, 0.14f, 0.11f, 1.f };
	float mat_spec[]                        // specular colour
		= { 0.1f, 0.1f, 0.1f, 1.f };        //  reflectance 
	glPushAttrib(GL_ALL_ATTRIB_BITS);       // save current style attributes (inc. material properties)
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient); // set colour for ambient reflectance
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_colour);  // set colour for diffuse reflectance
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_spec);   // set colour for specular reflectance

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
	glPopAttrib();
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

