#pragma once
#include <DisplayableObject.h>
#include "..\..\SimpleShapes\SimpleShapes.h"
class Bed :
	public DisplayableObject
{
public:
	void Display();
	Bed(float l, float w, float h);
	~Bed() {};
private:
	int frameTex;
	float framePillarWidth;
	float length, width, height; // dimensions of bed frame
	void makePillow();
	void makeFrame();
	void makeBedding();
	SimpleShapes simpleShape;
};