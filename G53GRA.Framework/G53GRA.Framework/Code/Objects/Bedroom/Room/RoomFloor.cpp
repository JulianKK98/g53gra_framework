#include <RoomFloor.h>

RoomFloor::RoomFloor(){}

void RoomFloor::Display() 
{
	glTranslatef(pos[0], pos[1], pos[2]);
	glScalef(scale[0], scale[1], scale[2]);
	glRotatef(rotation[1], 0.f, 1.f, 0.f); //y
	glRotatef(rotation[2], 0.f, 0.f, 1.f); //z
	glRotatef(rotation[0], 1.f, 0.f, 0.f); //x

	glBegin(GL_POLYGON);

}
