#include "Room.h"

Room:: ~Room()
{
	delete[] windows;
	delete bed;
	delete desk;
	delete chair;
}


Room::Room(float w, float l, float h) :
	width(w), length(l), height(h)
{

}

void Room::Display() {
	glEnable(GL_LIGHTING);
	glTranslatef(pos[0], pos[1], pos[2]);
	glScalef(scale[0], scale[1], scale[2]);
	glRotatef(rotation[0], 1.f, 0.f, 0.f); //x
	glRotatef(rotation[1], 0.f, 1.f, 0.f); //y
	glRotatef(rotation[2], 0.f, 0.f, 1.f); //z
	makeFloorNCeiling();
	makeWalls();
	pillarWidth = 0.15f * width;
	makePillar();
	float windowSillZ = makeWindowSill(0.05f, 0.3f);
	makeDoor();
	float winWidth = ((width * 0.5f) - (pillarWidth / 2.f)) / 2.f;
	makeWindows(winWidth , height - windowSillHeight, 5.f);
	makeRoomLight(-width * 0.5f, height, -length * 0.5f);
	makeBed();

	glPushMatrix();
	glTranslatef(-width + (width * 0.125f), 0.f, windowSillZ *2.f);
	glRotatef(90.0f, 0.f, 1.f, 0.f);
	desk = new Desk(width * 0.15f, length*0.25f, 60.f);
	desk->Display();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-width *0.7f, 5.f, windowSillZ *4.5f );
	glRotatef(-90.f, 0.f, 1.f, 0.f);
	glScalef(0.8f, 0.8f, 0.8f);
	chair = new Chair(10.f, 20.f, 100.f);
	chair->Display();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-width*0.25f, 0.f,-length * 0.25f);
	glRotatef(90, 0.f, 1.f, 0.f);
	wardrobe = new Wardrobe(width * 0.25f, height * 0.75f, width *0.25f);
	wardrobe->Display();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0.f, 0.f, -length * 0.5f);
	glRotatef(90, 0.f, 1.f, 0.f);
	Drawer *drawer = new Drawer(width * 0.30f);
	drawer->Display();
	glPopMatrix();

}


/*
*Constructs walls with GL_QUADS
*/
void Room::makeWalls() {
	wallTex = Scene::GetTexture("Textures/wall - smaller.bmp");
	
	float mat_colour[]                      // colour reflected by diffuse light
		= { 1.f, 1.f, 1.f, 1.f };         
	float mat_ambient[]                     // ambient colour
		= { 1.f, 1.f, 1.f, 1.f };         
	float mat_spec[]                        // specular colour
		= { 0.1f, 0.1f, 0.1f, 1.f };        //  reflectance 
	glPushAttrib(GL_ALL_ATTRIB_BITS);       // save current style attributes (inc. material properties)
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient); // set colour for ambient reflectance
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_colour);  // set colour for diffuse reflectance
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_spec);   // set colour for specular reflectance

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
	glNormal3d(0, 0, 1);
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
	glNormal3d(0, 0, -1);
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
	glPopAttrib();    
}

/*
*
*/
void Room::makeFloorNCeiling() 
{
	floorTex = Scene::GetTexture("Textures/floor.bmp"); 
	float mat_colour[]                      // colour reflected by diffuse light
		= { 1.f, 1.f, 1.f, 1.f };
	float mat_ambient[]                     // ambient colour
		= { 0.29f, 0.14f, 0.11f, 1.f };
	float mat_spec[]                        // specular colour
		= { 0.5f, 0.5f, 0.5f, 1.f };        //  reflectance 
	glPushAttrib(GL_ALL_ATTRIB_BITS);       // save current style attributes (inc. material properties)
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient); // set colour for ambient reflectance
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_colour);  // set colour for diffuse reflectance
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_spec);   // set colour for specular reflectance
	
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
	glPopAttrib();
	

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

/*
* Makes the windowsill 
*/
float Room::makeWindowSill(float thicknessMod, float heightMod)
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
	return windowSillZ;
}

/*
* Creates the pillar next to the window
*/
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

/*
* Makes 3 windows. 2 with the same thickness. 
* the other's dimensions are calculated from the other 2 windows.
*/
void Room::makeWindows(float width, float height, float thickness)
{
	Window *window1 = new Window(width, height, thickness);
	Window *window2 = new Window(width, height, thickness);
	float pillarWidth = Room::pillarWidth;


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
	glTranslatef(-width, windowHeight, 0.f);
	glRotatef(180.f, 0.f, 1.f, 0.f);
	window2->Display();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-(2*width) - pillarWidth, windowHeight, 0.f);
	glRotatef(180.f, 0.f, 1.f, 0.f);
	window3->Display();
	glPopMatrix();

}

/*
*
*/
void Room::makeDoor() 
{

	glPushMatrix();
	glTranslatef(-doorWidth, 0.f, -length);
	Door *door = new Door(doorWidth , doorHeight, 2.f);
	door->Display();
	glPopMatrix();
}

/*
* Creates and resizes the room light
*/
void Room::makeRoomLight(float x, float y, float z) 
{
	roomLight = new RoomLight();
	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(1.5f, 1.5f, 1.5f);
	roomLight->Display();
	glPopMatrix();
}

void Room::makeBed()
{
	bed = new Bed(200.f, 100.f, 60.f);
	float len = Room::length;
	glPushMatrix();
	glTranslatef(-width + 110.f, 0.f, -len * 0.5f);
	glRotatef(180.f, 0.f, 1.f, 0.f);
	bed->Display();
	glPopMatrix();
}

float * Room::getMonitorCoords()
{
	float res[3] = { -width * 0.8f, length*0.151f , -0.18*length };
	return res;
}
