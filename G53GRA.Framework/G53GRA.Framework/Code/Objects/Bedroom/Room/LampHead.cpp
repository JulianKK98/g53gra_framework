#include "LampHead.h"

void LampHead::Display() 
{
	glTranslatef(pos[0], pos[1], pos[2]);
	glScalef(scale[0], scale[1], scale[2]);
	glRotatef(rotation[0], 1.f, 0.f, 0.f); //x
	glRotatef(rotation[1], 0.f, 1.f, 0.f); //y
	glRotatef(rotation[2], 0.f, 0.f, 1.f); //z
	
	glColor3f(0.5f, 0.5f, 0.5f);
	simpleShape.makeCylinder(lPivot, r1funnel, true, true);
	glPushMatrix();
	glTranslatef(0.f, -lPivot, 0.f);
	simpleShape.makeFunnel(funnelLength, r1funnel, r2funnel);
	simpleShape.makeFunnelInverse(funnelLength, r1funnel, r2funnel);
	simpleShape.makeCylinder(r1funnel * 0.125f, r1funnel * 0.25f, false, false);

	glPushMatrix();
	glColor3d(1, 1, 1);
	//make lightbulb
	glTranslatef(0, -r1funnel * 0.5f, 0.f);
	glutSolidSphere(r1funnel * 0.5f, 10, 10);
	//add light here
	glPopMatrix();

	glPopMatrix();

	
}