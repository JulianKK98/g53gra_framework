#pragma once
#include <DisplayableObject.h>
#include "..\..\SimpleShapes\SimpleShapes.h"
#include "DrawerBox.h"

class Drawer :
	public DisplayableObject
{
public:

	Drawer(float l) : // square so width not needed
		length(l)
	{};
	~Drawer();
	void Display();
private:
	void makeFrame();
	void makeCross();
	void makeDrawers();
	float crossWidth;
	float frameWidth;
	float length, thickness;
	int drawerTex = 0;
	SimpleShapes simpleShape;
	DrawerBox *box1 = NULL;
	DrawerBox *box2 = NULL;
	DrawerBox *box3 = NULL;
	DrawerBox *box4 = NULL;
};