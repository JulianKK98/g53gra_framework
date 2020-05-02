#pragma once
#include <DisplayableObject.h>

class Door :
	public DisplayableObject
{
	float width, height, thickness;
public:
	Door(float w, float h, float t):
		width(w), 
		height(h), 
		thickness(t)
	{}
	~Door() {};
	void Display();

private:
	float hingeLocation;
	float maxRotationAngle;
	void makeDoor();
	void makeDoorKnob();
	void cylinder(float h, float r);
};