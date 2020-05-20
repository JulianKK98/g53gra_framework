#pragma once
#include<DisplayableObject.h>

class DrawerBox :
	public DisplayableObject
{
public:
	DrawerBox(float length, int *colourVals):length(length)
	{
		DrawerBox::colour[0] = colourVals[0];
		DrawerBox::colour[1] = colourVals[1];
		DrawerBox::colour[2] = colourVals[2];
	}
	~DrawerBox() {};
	void Display();
private:
	void makeBox(float width, float height, float thickness);
	float length;
	int colour[3];
};