#include "RoomLight.h"

SimpleShapes simpleShape;

RoomLight::RoomLight() 
{
	radius = 5.f;
	height = 1.f;
	lampHeads = {
		new LampHead(),
		new LampHead(),
		new LampHead(),
		new LampHead()
	};
}
}

void RoomLight::Display()
{
	glTranslatef(pos[0], pos[1], pos[2]);
	glScalef(scale[0], scale[1], scale[2]);
	glRotatef(rotation[0], 1.f, 0.f, 0.f); //x
	glRotatef(rotation[1], 0.f, 1.f, 0.f); //y
	glRotatef(rotation[2], 0.f, 0.f, 1.f); //z

	glPushMatrix();
	glColor3f(0.5f, 0.5f, 0.5f);
	simpleShape.makeCylinder(radius, height, true, true);
	glPopMatrix();

}