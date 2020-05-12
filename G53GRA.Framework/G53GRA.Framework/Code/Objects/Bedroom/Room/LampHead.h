#pragma once
#include<DisplayableObject.h>
#include "../../SimpleShapes/SimpleShapes.h"

class LampHead :
	public DisplayableObject
{
public:
	LampHead(float r1, float r2, float funnelLength, float rPivot, float lPivot) :
		r1funnel(r1),
		r2funnel(r2),
		funnelLength(funnelLength),
		rPivot(rPivot),
		lPivot(lPivot) {};
	~LampHead() {};
	void Display();
private:
	float r1funnel, r2funnel , funnelLength; //for funnel
	float rPivot, lPivot; 
	
	SimpleShapes simpleShape;

};