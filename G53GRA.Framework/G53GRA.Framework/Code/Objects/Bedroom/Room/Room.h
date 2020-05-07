#include <DisplayableObject.h>
#include "Window.h"
#include "Door.h"
#include "Texture.h"

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
	int *floorTex, *wallTex;
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
};