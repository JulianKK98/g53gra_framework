#include <DisplayableObject.h>
#include "Window.h"

class Room :
	public DisplayableObject
{
	const float width, length, height;
	Window &window1;
	Window &window2;
	Window &window3;
public:
	Room(float w, float l, float h):
		width(w), length(l), height(h){}
	~Room();
	void Display();
private:
	Window windows[3];
	float pillarWidth;
	float windowSillHeight;
	float alcoveWidth;
	void makeWalls();
	void makeFloorNCeiling();
	void makeWindowSill(float thicknessMod, float heightMod);
	void makeWindows(float width, float height, float thickness);
	void makePillar();
};