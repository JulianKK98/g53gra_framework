#include <DisplayableObject.h>
#include "Window.h"
#include "Door.h"
#include "Texture.h"
#include "RoomLight.h"
#include "Bed.h"

class Room :
	public DisplayableObject
{
	const float width, length, height;
	
public:
	Room(float w, float l, float h);
	~Room();
	void Display();
private:
	Window windows[3];
	RoomLight *roomLight;
	int floorTex, wallTex;
	float pillarWidth;
	float windowSillHeight;
	float alcoveWidth;
	float doorWidth, doorHeight;
	void makeWalls();
	void makeFloorNCeiling();
	void makeWindowSill(float thicknessMod, float heightMod);
	void makeWindows(float width, float height, float thickness);
	void makePillar();
	void makeDoor();
	void makeRoomLight(float x, float y, float z);
};