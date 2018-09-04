#ifndef MTRN3500_WHEEL_H
#define MTRN3500_WHEEL_H

#include "Vehicle.hpp"
#include <vector>

class Wheel : public Vehicle {

public:
	Wheel();//default constructor
	~Wheel();//default constructor

						  //set the speed of the additional object acccording to the speed of vehicle
	void SetWheelSpeed(Vehicle* localcar);

						  //set the steering of the addtional object according to the steering of the vehicle
	void SetWheelSteering(Vehicle* localcar);
	void draw();
};

#endif