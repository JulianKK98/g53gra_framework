#include "MyScene.h"
#include "Objects/Bedroom/Room/Room.h"
#include "Objects/Bedroom/Room/Window.h"
#include "Objects/Bedroom/Room/Door.h"
#include "Objects/Bedroom/Room/RoomLight.h"

//test
#include "Objects/Bedroom/Room/LampHead.h"

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{

}




void MyScene::Initialise()
{
	
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	/*Room *testRoom = new Room(280.f, 400.f, 200.f);
	AddObjectToScene(testRoom);

	RoomLight * roomLight = new RoomLight();
	AddObjectToScene(roomLight);*/

	LampHead *lampHead = new LampHead();
	AddObjectToScene(lampHead);
	
	
}

void MyScene::Projection()
{
	GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
	gluPerspective(60.0, aspect, 1.0, 1000.0);
}
