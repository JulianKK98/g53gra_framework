#pragma once
#include <DisplayableObject.h>
#include "..\..\SimpleShapes\SimpleShapes.h"
#include "LampHead.h"

class RoomLight :
	public DisplayableObject
{

public:
	RoomLight();
		
	~RoomLight();
	void Display();
private:
	void setUpLight(GLenum lightNum, float cutoff);
	LampHead * lampHead1 = NULL;
	LampHead * lampHead2 = NULL;
	LampHead * lampHead3 = NULL;
	LampHead * lampHead4 = NULL;
	float radius;
	float height;
};