#pragma once
#include <DisplayableObject.h>
#include <Animation.h>
class Screen :
	public DisplayableObject,
	public Animation
{

public:
	void Update(const double &deltaTime);
	Screen(float w, float l, float aniTime):
		width(w), length(l), animationTime(aniTime)
	{};
	~Screen() {};
	void Display();
	void loadFrameTextures();
private:
	int textureFrames[11];
	float aniStage = 0.f;
	float animationTime, aniTime = 0.f;
	float width, length;
};