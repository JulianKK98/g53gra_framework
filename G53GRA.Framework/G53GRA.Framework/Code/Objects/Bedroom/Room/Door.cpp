#include "Door.h"
#include <cmath>
#include <VectorMath.h>
#include "../../SimpleShapes/SimpleShapes.h"

static SimpleShapes shape;

void Door::Display() {
	glTranslatef(pos[0], pos[1], pos[2]);
	glScalef(scale[0], scale[1], scale[2]);
	glRotatef(rotation[0], 1.f, 0.f, 0.f); //x
	glRotatef(rotation[1], 0.f, 1.f, 0.f); //y
	glRotatef(rotation[2], 0.f, 0.f, 1.f); //z

	float mat_colour[]                      // colour reflected by diffuse light
		= { 1.f, 1.f, 1.f, 1.f };
	float mat_ambient[]                     // ambient colour
		= { 1.f, 1.f, 1.f, 1.f };
	float mat_spec[]                        // specular colour
		= { 0.5f, 0.5f, 0.5f, 1.f };        //  reflectance 
	glPushAttrib(GL_ALL_ATTRIB_BITS);       // save current style attributes (inc. material properties)
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient); // set colour for ambient reflectance
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_colour);  // set colour for diffuse reflectance
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_spec);   // set colour for specular reflectance

	makeDoor();
	makeDoorKnob(2.f, 5.f, 6.f, 3.f);

	glPushMatrix();
	glRotatef(-180.f, 0.f, 1.f, 0.f);
	glRotatef(-180.f, 0.f, 0.f, 1.f);
	glTranslatef(0.f, -height, 3.f);
	makeDoorKnob(2.f, 5.f, 6.f, 3.f);
	glPopMatrix();
	glPopAttrib();
	
}


void Door::makeDoor() {
	glPushMatrix();
	glColor3f(1.f, 1.f, 1.f);
	shape.makeCuboid(width, height, thickness);
	glPopMatrix();
	
}

void Door::makeDoorKnob(float baseThickness,
	float baseRadius,
	float handleThickness,
	float cylinderHandleRadius
) 
{
	float doorKnobX = 0.1f * width;
	float doorKnobY = height / 2.f;
	float handlePosY = doorKnobY / 2.f;
	//base cylinder
	glPushMatrix();
	glColor3f(0.5f, 0.5f, 0.5f);
	glTranslatef(doorKnobX, doorKnobY, baseThickness);
	glRotatef(90.f, 1.f, 0.f, 0.f);
	shape.makeCylinder(baseThickness, baseRadius, true, false);
	glPopMatrix();

	//cylinder for handle
	glPushMatrix();
	glColor3f(0.8f, 0.8f, 0.8f);
	glTranslatef(doorKnobX, doorKnobY, baseThickness + handleThickness);
	glRotatef(90.f, 1.f, 0.f, 0.f);
	shape.makeCylinder(handleThickness, cylinderHandleRadius, true, false);
	glPopMatrix();
	
	//handle
	glPushMatrix();
	glColor3f(0.8f, 0.8f, 0.8f);
	glTranslatef(doorKnobX, doorKnobY + (cylinderHandleRadius / 2.f), baseThickness + handleThickness);
	glRotatef(-90.f, 0.f, 0.f, 1.f);
	shape.makeCuboid(2, 10.f, handleThickness);
	glPopMatrix();

}






