#include "Window.h"

void Window::Display() {
	glTranslatef(pos[0], pos[1], pos[2]);
	glScalef(scale[0], scale[1], scale[2]);
	glRotatef(rotation[0], 1.f, 0.f, 0.f); //x
	glRotatef(rotation[1], 0.f, 1.f, 0.f); //y
	glRotatef(rotation[2], 0.f, 0.f, 1.f); //z
	makeWindow();
	makeFrame();

}

void Window::makeWindow()
{
	glBegin(GL_QUADS);
	glColor4f(0.3f, 0.3f, 1.f, 0.3f);
	glVertex3f(frameThickness, frameThickness, 0.f);
	glVertex3f(width - frameThickness, frameThickness, 0.f);
	glVertex3f(width - frameThickness, height - frameThickness, 0.f);
	glVertex3f(frameThickness, height - frameThickness, 0.f);
	glEnd();
}

void Window::makeFrame()
{
	glBegin(GL_QUADS);
	glColor3f(0.16f, 0.368f, 0.29f);

	glVertex3f(0.f, 0.f, 0.f);
	glVertex3f(frameThickness, 0.f, 0.f);
	glVertex3f(frameThickness, height, 0.f);
	glVertex3f(0.f, height, 0.f);

	glVertex3f(frameThickness, height - frameThickness, 0.f);
	glVertex3f(width - frameThickness, height - frameThickness, 0.f);
	glVertex3f(width - frameThickness, height, 0.f);
	glVertex3f(frameThickness, height, 0.f);
	
	glVertex3f(width - frameThickness, 0.f, 0.f);
	glVertex3f(width, 0.f, 0.f);
	glVertex3f(width, height, 0.f);
	glVertex3f(width - frameThickness, height, 0.f);
	
	glVertex3f(frameThickness, 0.f, 0.f);
	glVertex3f(width - frameThickness, 0.f, 0.f);
	glVertex3f(width - frameThickness, frameThickness, 0.f);
	glVertex3f(frameThickness, frameThickness, 0.f);
	
	glEnd();
}