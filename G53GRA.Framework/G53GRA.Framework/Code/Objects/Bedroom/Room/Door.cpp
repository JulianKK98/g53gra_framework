#include "Door.h"


static SimpleShapes shape;

void Door::Display() {
	glRotatef(180, 0.f, 1.f, 0.f);
	glPushMatrix();
	glTranslatef(
		room->getDoorCoords()[0],
		room->getDoorCoords()[1],
		room->getDoorCoords()[2]
	);
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

	rotation[1] = doorAngle;


	makeDoor();
	glPopAttrib();
	glPopMatrix();
}

/*
*Handles the rotation of the door
*/
void Door::Update(const double &deltaT)
{
	
	aniTime = fmod(aniTime + deltaT, animationTime);
	float stage = 10.f * aniTime / animationTime;

	if (stage < 1.f || stage > 9.f) { doorAngle = 0.f; }
	else if(stage < 1.f || stage > 9.f) {  doorAngle = 20.f;}
	else if(stage < 2.f || stage > 8.f) { doorAngle = 40.f; }
	else if(stage < 3.f || stage > 7.f) { doorAngle = 60.f; }
	else if(stage < 4.f || stage > 6.f) { doorAngle = 80.f; }
	else { doorAngle = 90.f; }
	
	
}

//Uses a simple cuboid to make a door
void Door::makeDoor() {
	glPushMatrix();
	glColor3f(1.f, 1.f, 1.f);
	shape.makeCuboid(width, height, thickness);
	glPopMatrix();
	
	makeDoorKnob(2.f, 5.f, 6.f, 3.f);

	glPushMatrix();
	glRotatef(-180.f, 0.f, 1.f, 0.f);
	glRotatef(-180.f, 0.f, 0.f, 1.f);
	glTranslatef(0.f, -height, 10.f);
	makeDoorKnob(2.f, 5.f, 6.f, 3.f);
	glPopMatrix();
	
}

/*
* combines a cuboid with 2 cylinders to make a doorknob
*float baseRadius - radius of the largest cylinder
*float handleThickness - thickness of the handle
*float cylinderHandleRadius - radius of the smaller cylinder
*/
void Door::makeDoorKnob(float baseThickness,
	float baseRadius,
	float handleThickness,
	float cylinderHandleRadius
) 
{
	float doorKnobX = 0.9f * width;
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
	glRotatef(90.f, 0.f, 0.f, 1.f);
	shape.makeCuboid(2, 10.f, handleThickness);
	glPopMatrix();

}






