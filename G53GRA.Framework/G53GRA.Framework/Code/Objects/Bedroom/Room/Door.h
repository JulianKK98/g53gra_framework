#pragma once
#include <DisplayableObject.h>

class Door :
	public DisplayableObject
{

public:
	Door();
	~Door() {};
	void Display();

private:
	float hingeLocation;
};