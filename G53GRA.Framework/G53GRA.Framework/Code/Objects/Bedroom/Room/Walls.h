#pragma once
#include <DisplayableObject.h>

class Walls: 
	public DisplayableObject
{
public:
	Walls();
	~Walls() {};
	void Display();
};