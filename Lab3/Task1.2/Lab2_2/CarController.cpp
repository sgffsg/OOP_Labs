#include "CarController.h"

static std::string StringToLower(const std::string str)
{
	std::string lowerStr;
	for (const char& c : str)
	{
		lowerStr += tolower(c);
	}

	return lowerStr;
}

CarController::CarController(Car& car)
{
	this->m_car = car;
}

void CarController::HandleCommand(const std::string& command)
{
	auto it = this->CONTROLLER_COMMAND_STRING.find(command);
	if (it != this->CONTROLLER_COMMAND_STRING.end())
	{
		auto actionIt = this->m_command.find(it->second);
		if (actionIt != this->m_command.end())
		{
			actionIt->second(); 
		}
	}
	else
	{
		std::cout << "Unknown command: " << command << "\n";
	}
}

void CarController::ProcessInput()
{
	std::string command;

	while (std::cout << ">")
	{
		std::cin >> command;
		command = StringToLower(command);
		this->HandleCommand(command);
		if (command == "shutdown")
			break;
	}
}

void CarController::TurnOnEngineCommand()
{
	this->m_car.TurnOnEngine();
}

void CarController::TurnOffEngineCommand()
{
	this->m_car.TurnOffEngine();
}

void CarController::SetGearCommand()
{
	int gear;
	std::string gearLine;

	if (!std::getline(std::cin, gearLine))
	{
		std::cerr << "Cannot read argument" << std::endl;
	}

	try
	{
		gear = std::stoi(gearLine);
		this->m_car.SetGear(gear);
	}
	catch (const std::exception&)
	{
		std::cout << "Invalid command argument\n"
				  << std::endl;
	}
}

void CarController::SetSpeedCommand()
{
	int speed;
	std::string speedLine;

	if (!std::getline(std::cin, speedLine))
	{
		std::cerr << "Cannot read argument" << std::endl;
	}

	try
	{
		speed = std::stoi(speedLine);
		this->m_car.SetSpeed(speed);
	}
	catch (const std::exception&)
	{
		std::cout << "Invalid command argument\n" << std::endl;
	}
}

void CarController::ShutdownCommand()
{
	std::cout << "Thanks for use. Bye.\n";
}

void CarController::ShowHelpCommand()
{
	std::cout << "EngineOn - Set car engine on \n"
			  << "EngineOff - Set car engine on\n"
			  << "SetGear <value> - Set gear value\n"
			  << "SetSpeed <value> - Set speed value\n"
			  << "Shutdown - Close Program\n"
			  << "Help - Show available commands\n"
			  << "Info - Show car state\n";
}

void CarController::ShowInfoCommand()
{
	std::cout << "Engine: " << (this->m_car.IsTurnedOn() ? "On" : "Off") << "\n"
			  << "Direction: " << DIRECTION_STRING.at(this->m_car.GetDirection()) << "\n"
			  << "Speed: " << (this->m_car.GetDirection() == CarDirection::Backward ? "-" : "") << this->m_car.GetSpeed() << "\n"
			  << "Gear: "	<< this->m_car.GetGear() << "\n";
}