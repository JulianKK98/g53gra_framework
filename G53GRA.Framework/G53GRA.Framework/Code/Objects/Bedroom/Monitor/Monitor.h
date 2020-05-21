#pragma once
#include<DisplayableObject.h>
#include "..\..\SimpleShapes\SimpleShapes.h"
#include <Animation.h>
#include "..\Room\Room.h"

class Monitor :
	public DisplayableObject,
	public Animation
{
public:
	Room *room;
	Monitor(float l, float w, float h, float aniTime, Room *room);
	~Monitor() {};
	void Update(const double &deltaT);
	void Display();
private:
	void makeFrame();
	void makeStand();
	void makeScreen();
	float length, width, height;
	float frameHeight;
	float frameThickness;
	SimpleShapes simpleShape;

	//animation stuff
	int textureFrames[11];
	float aniStage = 0.f;
	float animationTime, aniTime = 0.f;
	void loadFrameTextures();

};

