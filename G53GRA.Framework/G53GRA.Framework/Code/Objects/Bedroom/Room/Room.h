#include <DisplayableObject.h>

class Room :
	public DisplayableObject
{
	const float width, length, height;
public:
	Room(float w, float l, float h):
		width(w), length(l), height(h){}
	~Room() {};
	void Display();
private:
	float alcoveWidth;
	void makeWalls();
	void makeFloorNCeiling();
	void makeWindowSill(float thickness, float heightMod);
};