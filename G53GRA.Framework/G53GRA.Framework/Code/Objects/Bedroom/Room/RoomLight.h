#pragma once
#include <DisplayableObject.h>
#include "..\..\SimpleShapes\SimpleShapes.h"

class RoomLight :
	public DisplayableObject
{

public:
	RoomLight() {
		radius = 5.f;
		height = 1.f;
	}
	~RoomLight() {};
	void Display();
private:
	float radius;
	float height;
};