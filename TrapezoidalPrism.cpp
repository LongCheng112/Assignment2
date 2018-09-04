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


#include <iostream>
#include "Vehicle.hpp"
#include "Cylinder.h"
#include "Shape.hpp"
#include <vector>
#include "Messages.hpp"
#include "MyVehicle.h"
#include "RectangularPrism.hpp"
#include "TriangularPrism.hpp"


using namespace std;






Trapezoidal::Trapezoidal() {

}


Trapezoidal::Trapezoidal(float alen, float blen, float height, float aoff, float depth) {
	Alen = alen;
	Blen = blen;
	Height = height;
	Aoff = aoff;
	Depth = depth;

}



void Trapezoidal::draw() {

	glColor3f(red, green, blue);
	glTranslatef(x, y, z);
	glRotatef(-rotation, 0, 1, 0);

	glBegin(GL_QUADS);//draw bottom side
	glVertex3f(Alen / 2, 0, -Depth / 2);//vertex 1
	glVertex3f(-Alen / 2, 0, -Depth / 2);//vertex 2
	glVertex3f(-Alen / 2, 0, Depth / 2);//vertex 3
	glVertex3f(Alen / 2, 0, Depth / 2);//vertex 4
	glEnd();


	glBegin(GL_QUADS);//draw up side
	glVertex3f(-Alen / 2 + Aoff, Height, -Depth / 2);//vertex 5
	glVertex3f(-Alen / 2 + Aoff + Blen, Height, -Depth / 2);//vertex 6
	glVertex3f(-Alen / 2 + Aoff + Blen, Height, Depth / 2);//vertex 7
	glVertex3f(-Alen / 2 + Aoff, Height, Depth / 2);//vertex 8
	glEnd();

	glBegin(GL_QUADS);//draw left surface , connect point 1,4,7,6
	glVertex3f(Alen / 2, 0, -Depth / 2);//vertex 1
	glVertex3f(Alen / 2, 0, Depth / 2);//vertex 4
	glVertex3f(-Alen / 2 + Aoff + Blen, Height, Depth / 2);//vertex 7
	glVertex3f(-Alen / 2 + Aoff + Blen, Height, -Depth / 2);//vertex 6
	glEnd();



	glBegin(GL_QUADS);//draw right surface, connect point 5,2,3,8
	glVertex3f(-Alen / 2 + Aoff, Height, -Depth / 2);//vertex 5
	glVertex3f(-Alen / 2, 0, -Depth / 2);//vertex 2
	glVertex3f(-Alen / 2, 0, Depth / 2);//vertex 3
	glVertex3f(-Alen / 2 + Aoff, Height, Depth / 2);//vertex 8
	glEnd();

	glBegin(GL_QUADS);//draw front surface, connect vertex 6,1,2,5
	glVertex3f(-Alen / 2 + Aoff + Blen, Height, -Depth / 2);//vertex 6
	glVertex3f(Alen / 2, 0, -Depth / 2);//vertex 1
	glVertex3f(-Alen / 2, 0, -Depth / 2);//vertex 2
	glVertex3f(-Alen / 2 + Aoff, Height, -Depth / 2);//vertex 5
	glEnd();


	glBegin(GL_QUADS);//draw bottom surface, connect vertex 7,4,3,8
	glVertex3f(-Alen / 2 + Aoff + Blen, Height, Depth / 2);//vertex 7
	glVertex3f(Alen / 2, 0, Depth / 2);//vertex 4
	glVertex3f(-Alen / 2, 0, Depth / 2);//vertex 3
	glVertex3f(-Alen / 2 + Aoff, Height, Depth / 2);//vertex 8
	glEnd();



}

Trapezoidal::~Trapezoidal() {




}