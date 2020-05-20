#pragma once
#include <DisplayableObject.h>
#include "..\..\SimpleShapes\SimpleShapes.h"

class Chair :
	public DisplayableObject
{
public:
	Chair(float w, float l, float h) :
		width(w), length(l), height(h)
	{
	};
	~Chair() {};
	void Display();

private:
	const float baseAngle = 360.f / 5.f;
	float legLength;
	float legWidth;
	float wheelRadius;
	float width, length, height;
	void makeBase();
	void makeChair();
	SimpleShapes simpleShape;
};