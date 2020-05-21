#pragma once
#include <DisplayableObject.h>
#include <Animation.h>
#include <cmath>
#include <VectorMath.h>
#include "../../SimpleShapes/SimpleShapes.h"
#include "Room.h"

class Door :
	public DisplayableObject,
	public Animation
{
	float width, height, thickness;
public:
	Room *room;
	Door(float w, float h, float t, float animationT, Room *room) :
		width(w),
		height(h),
		thickness(t),
		animationTime(animationT),
		room(room)
	{};
	~Door() {};
	void Display();
	void Update(const double &deltaT);

private:
	float aniTime = 0;
	float animationTime = 0;
	float hingeLocation;
	float doorAngle = 0;
	void makeDoor();
	void makeDoorKnob(
		float baseThickness,
		float baseRadius,
		float handleThickness,
		float cylinderHandleRadius
	);
	
};