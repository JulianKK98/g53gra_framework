#include "LampHead.h"

void LampHead::Display() 
{
	glTranslatef(pos[0], pos[1], pos[2]);
	glScalef(scale[0], scale[1], scale[2]);
	glRotatef(rotation[0], 1.f, 0.f, 0.f); //x
	glRotatef(rotation[1], 0.f, 1.f, 0.f); //y
	glRotatef(rotation[2], 0.f, 0.f, 1.f); //z
	
	glColor3f(0.5f, 0.5f, 0.5f);
	simpleShape.makeCylinder(rPivot, lPivot, false, true);
	glPushMatrix();
	glTranslatef(0.f, funnelLength, 0.f);
	simpleShape.makeFunnel(r1funnel, r2funnel, funnelLength);
	glPopMatrix();
}