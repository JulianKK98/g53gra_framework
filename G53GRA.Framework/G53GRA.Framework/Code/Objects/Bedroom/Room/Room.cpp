#include "Room.h"

Room:: ~Room()
{
	delete[] windows;

}





Room::Room(float w, float l, float h) :
	width(w), length(l), height(h)
{

}



void Room::Display() {
	glTranslatef(pos[0], pos[1], pos[2]);
	glScalef(scale[0], scale[1], scale[2]);
	glRotatef(rotation[0], 1.f, 0.f, 0.f); //x
	glRotatef(rotation[1], 0.f, 1.f, 0.f); //y
	glRotatef(rotation[2], 0.f, 0.f, 1.f); //z
	makeFloorNCeiling();
	makeWalls();
	pillarWidth = 0.15f * width;
	makePillar();
	makeWindowSill(0.05f, 0.3f);
	makeDoor();
	float winWidth = ((width * 0.5f) - (pillarWidth / 2.f)) / 2.f;
	makeWindows(winWidth , height - windowSillHeight, 5.f);
	makeRoomLight(-width*0.5f, height, -length*0.5f);
	
}


void Room::makeWalls() {
	std::string wallTexPath = "Textures/wall - smaller.bmp";
	wallTex = Scene::GetTexture(wallTexPath);
	
	doorWidth = width * 0.25f;
	doorHeight = height * 0.80f;
	alcoveWidth = width - (doorWidth / 2.f);
	//Draw right wall
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, wallTex);
	glBegin(GL_QUADS);
	glNormal3d(-1, 0, 0);
	glColor3f(0.8f, 0.8f, 0.8f);
	glTexCoord2f(0, 0); glVertex3f(0.f, 0.f, 0.f);
	glTexCoord2f(4, 0); glVertex3f(0.f, height, 0.f);
	glTexCoord2f(4, 4); glVertex3f(0.f, height, -length);
	glTexCoord2f(0, 4); glVertex3f(0.f, 0.f, -length);
	
	
	glColor3f(1.f, 1.f, 1.f);
	//Above door
	glNormal3d(0, 0, 0);
	glTexCoord2f(0, 0); glVertex3f(0.f, doorHeight, -length);
	glTexCoord2f(4, 0); glVertex3f(0.f, height, -length);
	glTexCoord2f(4, 4); glVertex3f(-doorWidth, height, -length);
	glTexCoord2f(0, 4); glVertex3f(-doorWidth, doorHeight, -length);
	//wall next to door
	glTexCoord2f(0, 0); glVertex3f(-doorWidth, 0.f, -length);
	glTexCoord2f(4, 0); glVertex3f(-doorWidth, height, -length);
	glTexCoord2f(4, 4); glVertex3f(-width, height, -length);
	glTexCoord2f(0, 4); glVertex3f(-width, 0.f, -length);

	//Left wall alcove
	glNormal3d(1, 0, 0);
	glColor3f(0.396f, 0.58f, 0.56f);
	glTexCoord2f(0, 0);	glVertex3f(-width, 0.f, -length);
	glTexCoord2f(4, 0); glVertex3f(-width, height, -length);
	glTexCoord2f(4, 4); glVertex3f(-width, height, -length * 0.4f);
	glTexCoord2f(0, 4); glVertex3f(-width, 0.f, -length * 0.4f);

	//alcove
	glNormal3d(1, 1, 1);
	glTexCoord2f(0, 0); glVertex3f(-width, 0.f, -length * 0.4f);
	glTexCoord2f(4, 0); glVertex3f(-width, height, -length * 0.4f);
	glTexCoord2f(4, 4); glVertex3f(-alcoveWidth, height, -length * 0.4f);
	glTexCoord2f(0, 4); glVertex3f(-alcoveWidth, 0.f, -length * 0.4f);
	//left wall
	glNormal3d(1, 0, 0);
	glTexCoord2f(0, 0); glVertex3f(-alcoveWidth, 0.f, -length * 0.4f);
	glTexCoord2f(4, 0); glVertex3f(-alcoveWidth, height, -length * 0.4f);
	glTexCoord2f(4, 4); glVertex3f(-alcoveWidth, height, 0.0f);
	glTexCoord2f(0, 4); glVertex3f(-alcoveWidth, 0.0f, 0.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}



void Room::makeFloorNCeiling() 
{
	std::string floorTexPath = "Textures/floor.bmp";
	floorTex = Scene::GetTexture(floorTexPath);
	//floor
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, floorTex);
	glBegin(GL_QUADS);
	glNormal3d(0, 1, 0);
	glColor3f(1.f, 1.f, 1.f);
	glTexCoord2d(0, 0);	glVertex3f(0.f, 0.f, 0.f);
	glTexCoord2d(1, 0); glVertex3f(0.f, 0.f, -length);
	glTexCoord2d(1, 1); glVertex3f(-width, 0.f, -length);
	glTexCoord2d(0, 1); glVertex3f(-width, 0.f, 0.f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	

	//ceiling

	glBegin(GL_QUADS);
	glNormal3d(0, -1, 0);
	glColor3f(1.f, 1.f, 1.f);
	glVertex3f(-width, height, 0.f);
	glVertex3f(-width, height, -length);
	glVertex3f(0.f, height, -length);
	glVertex3f(0.f, height, 0.f);
	glEnd();
}


void Room::makeWindowSill(float thicknessMod, float heightMod)
{
	windowSillHeight = height * heightMod;
	float windowSillZ = thicknessMod * - length;
	
	//windowsill wall
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, wallTex);
	glBegin(GL_QUADS);
	glNormal3d(1, 1, 1);
	glColor3f(1.f, 1.f, 1.f);
	glTexCoord2f(0, 0); glVertex3f(0.f, 0.f, windowSillZ);
	glTexCoord2f(2, 0); glVertex3f(-width, 0.f, windowSillZ);
	glTexCoord2f(2, 2); glVertex3f(-width, windowSillHeight, windowSillZ);
	glTexCoord2f(0, 2); glVertex3f(0.f, windowSillHeight, windowSillZ);
	
	//windowSill
	glNormal3d(0, 0, 1);
	glTexCoord2f(0, 0); glVertex3f(0.f, windowSillHeight, 0.f);
	glTexCoord2f(2, 0); glVertex3f(0.f, windowSillHeight, windowSillZ);
	glTexCoord2f(2, 2); glVertex3f(-width, windowSillHeight, windowSillZ);
	glTexCoord2f(0, 2); glVertex3f(-width, windowSillHeight, 0.f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void Room::makePillar() 
{
	float pillarXPos = -0.5f* width;
	float pillarLeft = pillarXPos + (pillarWidth /2.f);
	float pillarRight = pillarXPos - (pillarWidth / 2.f);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, wallTex);
	glBegin(GL_QUADS);
	glColor3f(1.f, 1.f, 1.f);
	//right side
	glNormal3d(-1, 0, 0);
	glTexCoord2f(0, 0); glVertex3f(pillarLeft, 0.f, 0.f);
	glTexCoord2f(2, 0); glVertex3f(pillarLeft, 0.f, -pillarWidth);
	glTexCoord2f(2, 2); glVertex3f(pillarLeft, height, -pillarWidth);
	glTexCoord2f(0, 2); glVertex3f(pillarLeft, height, 0.f);
	//back
	glNormal3d(1, 1, 1);
	glTexCoord2f(0, 0); glVertex3f(pillarLeft, 0.f, -pillarWidth);
	glTexCoord2f(2, 0); glVertex3f(pillarRight, 0.f, -pillarWidth);
	glTexCoord2f(2, 2); glVertex3f(pillarRight, height, -pillarWidth);
	glTexCoord2f(0, 2); glVertex3f(pillarLeft, height, -pillarWidth);
	//left side
	glNormal3d(1, 0, 0);
	glTexCoord2f(0, 0); glVertex3f(pillarRight, height, 0.f);
	glTexCoord2f(2, 0); glVertex3f(pillarRight, height, -pillarWidth);
	glTexCoord2f(2, 2); glVertex3f(pillarRight, 0.f, -pillarWidth);
	glTexCoord2f(0, 2); glVertex3f(pillarRight, 0.f, 0.f);
	glEnd();
}

void Room::makeWindows(float width, float height, float thickness)
{
	Window *window1 = new Window(width, height, thickness);
	Window *window2 = new Window(width, height, thickness);


	float win3Width = (2.f * width) - (Room::width - alcoveWidth);

	Window *window3 = new Window(win3Width, height, thickness);
	float windowHeight = windowSillHeight;
	windows[0] = *window1;
	windows[2] = *window2;
	windows[3] = *window3;

	//window 1;
	glPushMatrix();
	glTranslatef(0.f, windowHeight, 0.f);
	glRotatef(180.f, 0.f, 1.f, 0.f);
	window1->Display();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0.f - width, windowHeight, 0.f);
	glRotatef(180.f, 0.f, 1.f, 0.f);
	window2->Display();
	glPopMatrix();

	glPushMatrix();
	glTranslatef((-2 * width) + pillarWidth, windowHeight, 0.f);
	glRotatef(180.f, 0.f, 1.f, 0.f);
	window3->Display();
	glPopMatrix();

}

void Room::makeDoor() 
{

	glPushMatrix();
	glTranslatef(-doorWidth, 0.f, -length);
	Door *door = new Door(doorWidth , doorHeight, 2.f);
	door->Display();
	glPopMatrix();
}

void Room::makeRoomLight(float x, float y, float z) 
{
	roomLight = new RoomLight();
	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(1.5f, 1.5f, 1.5f);
	roomLight->Display();
	glPopMatrix();
}
