#ifndef MTRN3500_MY_VEHICLE_H
#define MTRN3500_MY_VEHICLE_H

#include "Cylinder.h"
#include "Shape.hpp"
#include "Vehicle.hpp"
#include "RectangularPrism.hpp"
#include "TrapezoidalPrism.h"
#include "TriangularPrism.hpp"
#include "Messages.hpp"
#include <vector>


class MyVehicle : public Vehicle {
protected:
	VehicleModel model;



public:
	MyVehicle();
	~MyVehicle();
	VehicleModel GetModel();
	virtual void draw();

};

#endif