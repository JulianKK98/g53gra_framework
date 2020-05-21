#include "MyScene.h"
#include "Objects/Bedroom/Room/Room.h"
#include "Objects/Bedroom/Room/Door.h"
#include "Objects/Bedroom/Monitor/Monitor.h"






MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{

}




void MyScene::Initialise()
{
	float width = 280.f;
	float height = 400.f;
	float length = 200.f;
	float doorWidth = width * 0.25f;
	float doorHeight = height * 0.80f;
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	Room *room = new Room(width, height, length);
	Monitor *monitor = new Monitor(10.f, 100.f, 50.f, 1.5, room);
	Door *door = new Door(doorWidth, 0.5*doorHeight, 10.f , 8, room);
	AddObjectToScene(room);
	AddObjectToScene(door);
	AddObjectToScene(monitor);
}

void MyScene::Projection()
{
	GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
	gluPerspective(60.0, aspect, 1.0, 1000.0);
}
