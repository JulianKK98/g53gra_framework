#pragma once
#include<DisplayableObject.h>
#include "Screen.h"

class Monitor :
	public DisplayableObject
{
public:
	Monitor(float length, float width, float height);
	void Display();
private:
	float length, width, height;
	Screen screen;
};

