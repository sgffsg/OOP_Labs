#pragma once
#include "CarDirection.h"

class Car
{
public:
	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gear);
	bool SetSpeed(int speed);
	bool IsTurnedOn();
	CarDirection GetDirection();
	int GetSpeed();
	int GetGear();

private:
	bool m_isTurnedOn = false;
	CarDirection m_direction = CarDirection::Standing;
	int m_speed = 0;
	int m_gear = 0;
};
