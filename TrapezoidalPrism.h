#pragma once
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "Shape.hpp"

class Trapezoidal : public Shape {

private:
	float Alen; //length of side A
	float Blen; //length of side B
	float Height; //height 
	float Aoff; //distance a is shifted from B from the left
	float Depth; //depth

public:
	Trapezoidal();
	Trapezoidal(float alen, float blen, float height, float aoff, float depth);
	void draw();
	~Trapezoidal();


};