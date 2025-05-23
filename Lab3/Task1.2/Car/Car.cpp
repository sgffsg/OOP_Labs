#include "Car.h"
#include <map>
#include <iostream>

const int MIN_GEAR = -1;
const int MAX_GEAR = 5;

struct SpeedRange
{
	int minSpeed;
	int maxSpeed;
};

const std::map<int, SpeedRange> GEAR_SPEED_RANGE{
	{ -1, SpeedRange{ 0, 20 } },
	{ 1, SpeedRange{ 0, 30 } },
	{ 2, SpeedRange{ 20, 50 } },
	{ 3, SpeedRange{ 30, 60 } },
	{ 4, SpeedRange{ 40, 90 } },
	{ 5, SpeedRange{ 50, 150 } }
};

bool Car::TurnOnEngine()
{
	m_isTurnedOn = true;
	return true;
}

bool Car::TurnOffEngine()
{
	if (m_gear != 0 || m_speed != 0)
	{
		std::cout << "Car must be stopped and in neutral gear\n";
		return false;
	}

	m_isTurnedOn = false;
	return true;
}

bool Car::SetGear(int gear)
{
	if (gear < MIN_GEAR || gear > MAX_GEAR)
	{
		std::cout << "Invalid gear\n";
		return false;
	}
	if (gear != 0)
	{
		if (!m_isTurnedOn)
		{
			std::cout << "�annot set gear while engine is off\n";
			return false;
		}
		if (gear == -1)
		{
			if (m_direction != CarDirection::Standing)
			{
				return false;
			}
		}
		else
		{
			SpeedRange speedRange = GEAR_SPEED_RANGE.at(gear);
			if (m_direction == CarDirection::Backward || m_speed < speedRange.minSpeed || m_speed > speedRange.maxSpeed)
			{
				return false;
			}
		}
	}

	m_gear = gear;
	return true;
}

bool Car::SetSpeed(int speed)
{
	speed = abs(speed);
	if (!m_isTurnedOn)
	{
		std::cout << "Cannot set speed while engine is off\n";
		return false;
	}
	if (m_gear == 0)
	{
		if (speed >= m_speed)
		{
			std::cout << "Cannot accelerate on neutral\n";
			return false;
		}
	}
	else
	{
		SpeedRange speedRange = GEAR_SPEED_RANGE.at(m_gear);
		if (speed < speedRange.minSpeed || speed > speedRange.maxSpeed)
		{
			std::cout << "Speed is out of gear range\n";
			return false;
		}
	}
	m_speed = speed;
	if (m_speed == 0)
	{
		m_direction = CarDirection::Standing;
	}
	else
	{
		if (m_gear > 0)
		{
			m_direction = CarDirection::Forward;
		}
		if (m_gear < 0)
		{
			m_direction = CarDirection::Backward;
		}
	}
	return true;
}

bool Car::IsTurnedOn()
{
	return m_isTurnedOn;
}

CarDirection Car::GetDirection()
{
	return m_direction;
}

int Car::GetSpeed()
{
	return m_speed;
}

int Car::GetGear()
{
	return m_gear;
}
