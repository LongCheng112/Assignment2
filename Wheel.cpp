#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <unistd.h>
#include <sys/time.h>
#elif defined(WIN32)
#include <Windows.h>
#include <tchar.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <unistd.h>
#include <sys/time.h>
#endif



#include "Shape.hpp"
#include "Vehicle.hpp"
#include "RectangularPrism.hpp"
#include "Cylinder.h"
#include "Wheel.h"
#include <math.h>

using namespace std;

//definition of the default constructor
Wheel::Wheel() {
	setPosition(0.0, 0.0, 6.0);
	setColor(1.0, 1.0, 0.0);
	setRotation(0.0);
}


//default constructor
Wheel::~Wheel() {


}

//draw the additional object
void Wheel::draw() {
	//move to the local frame
	glPushMatrix();
	positionInGL();

	glBegin(GL_TRIANGLES);
	glVertex3f(3, 0, 0);
	glVertex3f(-3, 0, 0);
	glVertex3f(0, 3, 0);

	glBegin(GL_TRIANGLES);
	glVertex3f(3, 0, 0);
	glVertex3f(-3, 0, 0);
	glVertex3f(0, -3, 0);

	//pop back to global frame
	glPopMatrix();


}
