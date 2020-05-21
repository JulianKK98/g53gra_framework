#include "Monitor.h"

Monitor::Monitor(float l, float w, float h, float aniTime, Room *room) :
	length(l), width(w), height(h), animationTime(aniTime), room(room)
{
	loadFrameTextures();
};

void Monitor::Display()
{
	 
	glTranslatef(room->getMonitorCoords()[0],
		room->getMonitorCoords()[1],
		room->getMonitorCoords()[2]
	);
	glRotatef(90.f, 0.f, 1.f, 0.f);
	glScalef(scale[0] * 0.50f, scale[1] * 0.50f, scale[2] * 0.50f);
	glRotatef(rotation[0], 1.f, 0.f, 0.f); //x
	glRotatef(rotation[1], 0.f, 1.f, 0.f); //y
	glRotatef(rotation[2], 0.f, 0.f, 1.f); //z
	glColor3ub(20, 20, 20);
	makeStand();
	makeFrame();
	makeScreen();
}

void Monitor::makeFrame()
{
	frameThickness = width* 0.01f;
	frameHeight = 0.6f*height;
	float yPos = 0.4 * frameHeight;
	//bottom side

	glPushMatrix();
	glTranslatef(0.f, yPos, 0);
	//bottom side
	simpleShape.makeCuboid(width, frameThickness,frameThickness);
	//left side
	simpleShape.makeCuboid(frameThickness, height, frameThickness);
	
	//right side
	glPushMatrix();
	glTranslatef(width, 0.f, 0.f);
	simpleShape.makeCuboid(frameThickness, height, frameThickness);
	glPopMatrix();
	//top side
	glPushMatrix();
	glTranslatef(0.f, height-frameThickness, 0.f);
	simpleShape.makeCuboid(width, frameThickness, frameThickness);
	glPopMatrix();

	//backpiece
	glPushMatrix();
	glTranslatef(0.f, 0.f, -frameThickness);
	simpleShape.makeCuboid(width + frameThickness, height, frameThickness);
	glPopMatrix();

	glPopMatrix();
}

void Monitor::makeStand()
{
	float midX = width * 0.5;
	float baseRad = 0.33f * width;
	float armThickness = baseRad *0.1f;
	glPushMatrix();
	glTranslatef(midX, 0.f, 0.f);
	//base
	simpleShape.makeCylinder(frameThickness, baseRad, true, true);

	glPushMatrix();
	glTranslatef(0.f, 0.f, -baseRad + (2.f* armThickness));
	simpleShape.makeCuboid(armThickness, armThickness * 1.2f, armThickness);
	glPopMatrix();

	//arm
	float armLen = (baseRad + armThickness) * cosf(35.f);
	glPushMatrix();
	glTranslatef(-0.5f * armThickness, height * 0.4f, -frameThickness);
	glRotatef(-35.f, 1.f, 0.f, 0.f);
	simpleShape.makeCuboid(armThickness, armThickness, -armLen);
	glPopMatrix();

	float armEndYPos = (baseRad + armThickness) * sinf(35.f);
	glTranslatef(
		-armThickness, 
		-armEndYPos + armThickness, 
		-armThickness + 2.f* frameThickness
	);
	simpleShape.makeCuboid(2.f*armThickness, 2.f*armThickness, armThickness);

	glPopMatrix();
}

void Monitor::makeScreen()
{
	float screenWidth = width -  frameThickness;
	float screenHeight = frameHeight ;
	
	glTranslatef(frameThickness, height *0.4f, 0.f);
	glColor3f(1.f, 1.f, 1.f);
	glEnable(GL_TEXTURE_2D);
	int frame = floorf(aniStage);
	glBindTexture(GL_TEXTURE_2D, textureFrames[frame]);
	glBegin(GL_QUADS);
	//front
	glNormal3d(0, 0, 1);
	glTexCoord2d(0, 0); glVertex3f(0.f, 0.f, 0.f);
	glTexCoord2d(1, 0); glVertex3f(screenWidth, 0.f, 0.f);
	glTexCoord2d(1, 1); glVertex3f(screenWidth, screenHeight, 0.f);
	glTexCoord2d(0, 1); glVertex3f(0.f, screenHeight, 0.f);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);
}

void Monitor::Update(const double &deltaTime)
{

	aniTime = fmod(aniTime + deltaTime, animationTime);

	aniStage = 11.f *aniTime / animationTime;

}

/*
*Loads all the frames for the screen texture animation
*/
void Monitor::loadFrameTextures()
{
	std::string filePath = "./Textures/Screen Frames/Frame";

	for (int i = 1; i <= 11; i++)
	{
		std::string imgPath = std::string(filePath + " " + std::to_string(i) + ".bmp");
		textureFrames[i - 1] = Scene::GetTexture(imgPath);
	}
}
