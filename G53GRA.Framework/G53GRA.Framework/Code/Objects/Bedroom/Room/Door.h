#pragma once
#include <DisplayableObject.h>
#include <cmath>
#include <VectorMath.h>
#include "../../SimpleShapes/SimpleShapes.h"

class Door :
	public DisplayableObject
{
	float width, height, thickness;
public:
	Door(float w, float h, float t):
		width(w), 
		height(h), 
		thickness(t),
		hingeLocation(w)
	{}
	~Door() {};
	void Display();

private:
	float hingeLocation;
	float maxRotationAngle;
	void makeDoor();
	void makeDoorKnob(
		float baseThickness,
		float baseRadius,
		float handleThickness,
		float cylinderHandleRadius
	);
};