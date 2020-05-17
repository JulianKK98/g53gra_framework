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
	LampHead * lampHead1;
	LampHead * lampHead2;
	LampHead * lampHead3;
	LampHead * lampHead4;
	float radius;
	float height;
};