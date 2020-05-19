#pragma once
#include <DisplayableObject.h>

class Pillow :
	public DisplayableObject
{
public:
	Pillow(int sDNum) :
		subDivisionNum(sDNum)
	{};
	~Pillow() {};
	void Display();
private:
	void SubDivide(int subDivisionNum);
	int subDivisionNum;
	float front[4];
	float top[4];
	float bottom[4];
	float back[4];
	float left[4];
	float right[4];


};