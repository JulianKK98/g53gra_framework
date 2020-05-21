#include "Screen.h"

void Screen::Display()
{
	//loadFrameTextures();
	glColor3f(1.f, 1.f, 1.f);
	glEnable(GL_TEXTURE_2D);
	int frame = floorf(aniStage);
	glBindTexture(GL_TEXTURE_2D, textureFrames[frame]);
	glBegin(GL_QUADS);
	//front
	glNormal3d(0, 0, 1);
	glTexCoord2d(0, 0); glVertex3f(0.f, 0.f, 0.f);
	glTexCoord2d(1, 0); glVertex3f(width, 0.f, 0.f);
	glTexCoord2d(1, 1); glVertex3f(width, length, 0.f);
	glTexCoord2d(0, 1); glVertex3f(0.f, length, 0.f);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);
}

void Screen::Update(const double &deltaTime)
{
	
	aniTime = fmod(aniTime + deltaTime, animationTime);

	aniStage = 11.f *aniTime / animationTime;
	
}

void Screen::loadFrameTextures()
{
	std::string filePath = "./Textures/Screen Frames/Frame";

	for(int i = 1; i <= 11; i++)
	{
		std::string imgPath = std::string(filePath+ " " + std::to_string(i) + ".bmp");
		textureFrames[i - 1] = Scene::GetTexture(imgPath);
	}
}