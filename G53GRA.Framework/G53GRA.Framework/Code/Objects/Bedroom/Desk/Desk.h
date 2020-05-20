#pragma once
#include <DisplayableObject.h>
#include "..\..\SimpleShapes\SimpleShapes.h"
class Desk :
	public DisplayableObject
{
public:
	void Display();
	Desk(float l, float w, float h) :
		length(l), width(w), height(h)
	{
		legWidth = width * 0.1f;
		tableThickness = height * 0.1f;
	};
	~Desk() {  };
private:
	void makeTableLegs();
	int deskTex;
	float length, width, height;
	float tableThickness;
	float legWidth;
	SimpleShapes simpleShapes;
};