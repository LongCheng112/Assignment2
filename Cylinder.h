#pragma once
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "Shape.hpp"

class Cylinder : public Shape {
private:
	double Height;
	double Radius;
	bool isRolling;//whether the cylinder is rolling 
	bool isSteering;//whether the cylinder 
	double steer;//angle of the steering
	double rotation_rate;//the rotation rate of the wheels
public:
	Cylinder();//default constructor
	Cylinder(double _height, double _radius, bool isrolling, bool issteering);//non-default constructor
	bool IsRolling();
	bool IsSteering();
	void setSteer(double angle);
	double getSteer();
	void setRotationRate(double rate);
	double getRotationRate();
	void draw();
	~Cylinder();
	//double speed;

};