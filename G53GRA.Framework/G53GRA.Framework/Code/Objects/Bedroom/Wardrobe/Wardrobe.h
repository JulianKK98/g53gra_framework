#pragma once
#include <DisplayableObject.h>
#include "..\..\SimpleShapes\SimpleShapes.h"

class Wardrobe :
	public DisplayableObject
{
public:
	Wardrobe(float w, float h, float l) :
		width(w), height(h), length(l)
	{};
	Wardrobe() {};
	void Display();
private:
	int wardrobeTex = 0;
	float width, height, length;
	float topSectionThickness;
	float legWidth = width * 0.1f;
	SimpleShapes simpleShape;
	void makeBase();
	void makeSupports();
	void makeDoors();
	void wardrobeHandle(float w, float l, float h);
};
