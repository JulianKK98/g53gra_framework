#pragma once
#include<DisplayableObject.h>
#include <VectorMath.h>

class SimpleShapes
{
public:
	SimpleShapes() {};
	~SimpleShapes() {};
	void makeCircle(float r);
	void makeFunnel(float h, float r1, float r2);
	void makeFunnelInverse(float h, float r1, float r2);
	void makeCylinder(float h, float r, bool frontClosed, bool backClosed);
	void makeCuboid(float width, float height, float thickness);
};
