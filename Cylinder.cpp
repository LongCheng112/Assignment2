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

#include "Cylinder.h"
#define PI 3.14159265358979323846


Cylinder::Cylinder() {

}

Cylinder::Cylinder(double _radius, double _height, bool isrolling, bool issteering) {
	Radius = _radius;
	Height = _height;
	isRolling = isrolling;
	isSteering = issteering;
	rotation_rate = 0;
}


bool Cylinder::IsRolling() {

	return isRolling;
}



bool Cylinder::IsSteering() {

	return isSteering;
}


void Cylinder::setSteer(double angle) {
	steer = angle;
}




double Cylinder::getSteer() {

	return steer;
}





void Cylinder::setRotationRate(double rate) {
	rotation_rate = rotation_rate + rate;
}


double Cylinder::getRotationRate() {

	return rotation_rate;

}


void  Cylinder::draw() {
	glColor3f(red, green, blue);
	glTranslatef(x, y, z);
	glTranslatef(0.0, Radius, 0.0);
	glRotatef(-rotation, 0, 1, 0);//rotation
	glRotatef(-steer, 0, 1, 0);//steering
	if (IsRolling() == true) {
		glRotatef(-rotation_rate, 0, 0, 1);//rolling
	}





	glTranslatef(0.0, 0.0, -Height / 2);//start to draw the cylinder
	GLUquadricObj *CylPtr; // Create pointer for our cylinder
	CylPtr = gluNewQuadric(); // Create our new quadric object
	gluCylinder(CylPtr, Radius, Radius, Height, 100, 200);

	//draw the disk
	//also draw the point on the disk to detect the rolling 
	glColor3f(red, green, blue);//draw the disk
	gluDisk(CylPtr, 0, Radius, 32, 1);

	if (IsRolling() == true) {
		glPointSize(8.0);
		glBegin(GL_POINTS);
		glColor3f(0.0, 0.0, 1.0);//draw the blue point 
		glVertex3f(Radius / 2, 0.0, -0.1);
		glEnd();
	}

	glTranslatef(0, 0, Height);//move to another side to draw another disk
	glColor3f(red, green, blue);
	gluDisk(CylPtr, 0, Radius, 32, 1);// draw another disk



	if (IsRolling() == true) {
		glPointSize(8.0);
		glBegin(GL_POINTS);
		glColor3f(0.0, 0.0, 1.0);//draw the blue point 
		glVertex3f(Radius / 2, 0.0, 0.1);
		glEnd();
	}



}

Cylinder::~Cylinder() {

}
