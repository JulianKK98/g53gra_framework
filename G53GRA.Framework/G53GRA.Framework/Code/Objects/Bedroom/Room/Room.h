#pragma once
#include <DisplayableObject.h>
#include "Window.h"
#include "Texture.h"
#include "RoomLight.h"
#include "Bed.h"
#include "../Chair/Chair.h"
#include "../Desk/Desk.h"
#include "../Wardrobe/Wardrobe.h"
#include "../Wardrobe/Drawer.h"

class Room :
	public DisplayableObject
{
public:
	Room(float w, float l, float h);
	~Room();
	void Display();
	float * getDoorCoords();
	float * getMonitorCoords();
private:
	float width, length, height;

	Window windows[3];
	RoomLight *roomLight;
	Bed *bed;
	Desk *desk;
	Chair *chair;
	Wardrobe *wardrobe;
	int floorTex = 0;
	int	wallTex = 0;
	float pillarWidth;
	float windowSillHeight;
	float alcoveWidth;
	float doorWidth, doorHeight;
	void makeWalls();
	void makeFloorNCeiling();
	float makeWindowSill(float thicknessMod, float heightMod);
	void makeWindows(float width, float height, float thickness);
	void makePillar();
	void makeRoomLight(float x, float y, float z);
	void makeBed();
};