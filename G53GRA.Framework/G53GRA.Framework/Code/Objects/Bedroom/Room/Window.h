#pragma once
#include <DisplayableObject.h>

class Window :
	public DisplayableObject
{
	float width;
	float height;
	float frameThickness;

public:
	Window(
		float width, 
		float height, 
		float frameThickness
	):
		width(width),
		height(height),
		frameThickness(frameThickness)
	{}
	Window():
		width(0),
		height(0),
		frameThickness(0)
	{}
	~Window() {};
	void Display();
private: 
	void makeFrame();
	void makeWindow();
};