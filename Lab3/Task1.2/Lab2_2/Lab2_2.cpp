#include "CarController.h"
#include <iostream>

int main()
{
	Car car;
	CarController carController(car);
	carController.ProcessInput();
}