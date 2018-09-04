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
#include "MyVehicle.h"
#include "RectangularPrism.hpp"
#include "TrapezoidalPrism.h"
#include "TriangularPrism.hpp"
#include "Messages.hpp"
#include "Wheel.h"
#include "KeyManager.hpp"

#include <vector>

#define PI 3.1415926 

void MyVehicle::draw() {

	Cylinder* CylinPtr = NULL;
	for (vector<Shape*>::iterator iter = shapes.begin(); iter != shapes.end(); ++iter) {
		glPushMatrix();
		positionInGL();
		CylinPtr = dynamic_cast<Cylinder*>(*iter);

		if (CylinPtr != NULL) {
			if ((CylinPtr->IsSteering()) == true) {
				CylinPtr->setSteer(steering);
			}
			else {
				CylinPtr->setSteer(0);
			}


			if ((CylinPtr->IsRolling()) == true) {
				CylinPtr->setRotationRate(speed);
			}
			else {
				CylinPtr->setRotationRate(0);

			}
		}

		(*iter)->draw();
		glPopMatrix();

	}

}