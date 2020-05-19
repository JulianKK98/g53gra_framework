#include "SimpleShapes.h"

void SimpleShapes::makeCircle(float r) {
	float res = 0.1*M_PI;           // resolution (in radians: equivalent to 18 degrees)
	float x = r, z = 0.f;           // initialise x and z on right of cylinder centre
	float t = 0.f;                  // initialise angle as 0

	//make front face 
	glBegin(GL_POLYGON);
	do
	{
		x = r * cos(t);
		z = r * sin(t);
		glVertex3f(x, 0.f, z); // move x and z around circle
		t -= res;// add increment to angle

	} while (t > 2 * -M_PI);
	glEnd();
}

void SimpleShapes::makeCuboid(float width, float height, float thickness) {
	glBegin(GL_QUADS);
	//front
	glVertex3f(0.f, 0.f, 0.f);
	glVertex3f(width, 0.f, 0.f);
	glVertex3f(width, height, 0.f);
	glVertex3f(0.f, height, 0.f);
	//back
	glNormal3d(1, 1, 1);
	glVertex3f(width, 0.f, -thickness);
	glVertex3f(0.f, 0.f, -thickness);
	glVertex3f(0.f, height, -thickness);
	glVertex3f(width, height, -thickness);
	//left
	glNormal3d(1, 0, 0);
	glVertex3f(0.f, 0.f, 0.f);
	glVertex3f(0.f, height, 0.f);
	glVertex3f(0.f, height, -thickness);
	glVertex3f(0.f, 0.f, -thickness);
	//right
	glNormal3d(-1, 0, 0);
	glVertex3f(width, 0.f, 0.f);
	glVertex3f(width, 0.f, -thickness);
	glVertex3f(width, height, -thickness);
	glVertex3f(width, height, 0.f);
	//top
	glNormal3d(0, -1, 0);
	glVertex3f(0.f, height, 0.f);
	glVertex3f(width, height, 0.f);
	glVertex3f(width, height, -thickness);
	glVertex3f(0.f, height, -thickness);
	//bottom
	glNormal3d(0, 1, 0);
	glVertex3f(0.f, 0.f, -thickness);
	glVertex3f(width, 0.f, -thickness);
	glVertex3f(width, 0.f, 0.f);
	glVertex3f(0.f, 0.f, 0.f);
	glEnd();
}

void SimpleShapes::makeCuboid(float width, float height, float thickness, int texId) {

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texId);
	glBegin(GL_QUADS);
	//front
	glTexCoord2d(0, 0); glVertex3f(0.f, 0.f, 0.f);
	glTexCoord2d(1, 0); glVertex3f(width, 0.f, 0.f);
	glTexCoord2d(1, 1); glVertex3f(width, height, 0.f);
	glTexCoord2d(0, 1); glVertex3f(0.f, height, 0.f);
	//back
	glNormal3d(1, 1, 1);
	glTexCoord2d(0, 0); glVertex3f(width, 0.f, -thickness);
	glTexCoord2d(1, 0); glVertex3f(0.f, 0.f, -thickness);
	glTexCoord2d(1, 1); glVertex3f(0.f, height, -thickness);
	glTexCoord2d(0, 1); glVertex3f(width, height, -thickness);
	//left
	glNormal3d(1, 0, 0);
	glTexCoord2d(0, 0); glVertex3f(0.f, 0.f, 0.f);
	glTexCoord2d(1, 0); glVertex3f(0.f, height, 0.f);
	glTexCoord2d(1, 1); glVertex3f(0.f, height, -thickness);
	glTexCoord2d(0, 1); glVertex3f(0.f, 0.f, -thickness);
	//right
	glNormal3d(-1, 0, 0);
	glTexCoord2d(0, 0); glVertex3f(width, 0.f, 0.f);
	glTexCoord2d(1, 0); glVertex3f(width, 0.f, -thickness);
	glTexCoord2d(1, 1); glVertex3f(width, height, -thickness);
	glTexCoord2d(0, 1); glVertex3f(width, height, 0.f);
	//top
	glNormal3d(0, -1, 0);
	glTexCoord2d(0, 0); glVertex3f(0.f, height, 0.f);
	glTexCoord2d(1, 0); glVertex3f(width, height, 0.f);
	glTexCoord2d(1, 1); glVertex3f(width, height, -thickness);
	glTexCoord2d(0, 1); glVertex3f(0.f, height, -thickness);
	//bottom
	glNormal3d(0, 1, 0);
	glTexCoord2d(0, 0); glVertex3f(0.f, 0.f, -thickness);
	glTexCoord2d(1, 0); glVertex3f(width, 0.f, -thickness);
	glTexCoord2d(1, 1); glVertex3f(width, 0.f, 0.f);
	glTexCoord2d(0, 1); glVertex3f(0.f, 0.f, 0.f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void SimpleShapes::makeCylinder(float h, float r, bool frontClosed, bool backClosed) {
	float res = 0.1*M_PI;           // resolution (in radians: equivalent to 18 degrees)
	float x = r, z = 0.f;           // initialise x and z on right of cylinder centre
	float t = 0.f;                  // initialise angle as 0

	if(frontClosed)
	{
		glPushMatrix();
		glTranslatef(0.f, -h, 0.f);
		glRotatef(180.f, 1.f, 0.f, 0.f);
		makeCircle(r);
		glPopMatrix();
	}
	do
	{
		glBegin(GL_QUADS);          // new QUAD
			// Create first points
		glVertex3f(x, 0.f, z);    // top
		glVertex3f(x, -h, z);  // bottom
		// Iterate around circle
		t -= res;               // add increment to angle
		x = r * cos(t);           // move x and z around circle
		z = r * sin(t);
		// Close quad
		glVertex3f(x, -h, z);  // bottom
		glVertex3f(x, 0.f, z);    // top
		glEnd();                    // end shape
	} while (t >= 2 * -M_PI);        // for a full circle (360 degrees)

	if (backClosed) 
	{
		glPushMatrix();
		glNormal3d(1, 1, 1);
		makeCircle(r);
		glPopMatrix();
	}
}

void SimpleShapes::makeFunnel(float h, float r1, float r2) {
	float res = 0.1*M_PI;           // resolution (in radians: equivalent to 18 degrees)
	float x = r1, z = 0.f;           // initialise x and z on right of cylinder centre
	float x2 = r2, z2 = 0.f;           // initialise x and z on right of cylinder centre
	float t = 0.f;                  // initialise angle as 0

	do
	{
		glBegin(GL_QUADS);          // new QUAD
			// Create first points
		glVertex3f(x, 0.f, z);    // top
		glVertex3f(x2, -h, z2);  // bottom
		t -= res;               // add increment to angle
		x = r1 * cos(t);           // move x and z around circle
		z = r1 * sin(t);

		x2 = r2 * cos(t);
		z2 = r2 * sin(t);
		// Iterate around circle
		// Close quad
		glVertex3f(x2, -h, z2);  // bottom
		glVertex3f(x, 0.f, z);    // top
		glEnd();                    // end shape
	} while (t >= 2 * -M_PI);        // for a full circle (360 degrees)


}

void SimpleShapes::makeFunnelInverse(float h, float r1, float r2) {
	float res = 0.1*M_PI;           // resolution (in radians: equivalent to 18 degrees)
	float x = r1, z = 0.f;           // initialise x and z on right of cylinder centre
	float x2 = r2, z2 = 0.f;           // initialise x and z on right of cylinder centre
	float t = 0.f;                  // initialise angle as 0

	do
	{
		glBegin(GL_QUADS);          // new QUAD
			// Create first points
		glVertex3f(x, 0.f, z);    // top
		glVertex3f(x2, -h, z2);  // bottom
		t += res;               // add increment to angle
		x = r1 * cos(t);           // move x and z around circle
		z = r1 * sin(t);

		x2 = r2 * cos(t);
		z2 = r2 * sin(t);
		// Iterate around circle
		// Close quad
		glVertex3f(x2, -h, z2);  // bottom
		glVertex3f(x, 0.f, z);    // top
		glEnd();                    // end shape
	} while (t <= 2 * M_PI);        // for a full circle (360 degrees)


}