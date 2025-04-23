#pragma once
#include "CarControllerCommand.h"
#include "Car.h"
#include <functional>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>

class CarController
{
public:
	CarController(Car& car);
	void HandleCommand(const std::string& command);
	void ProcessInput();

private:
	Car m_car;

	void TurnOnEngineCommand();
	void TurnOffEngineCommand();
	void SetGearCommand();
	void SetSpeedCommand();
	void ShutdownCommand();
	void ShowHelpCommand();
	void ShowInfoCommand();

	std::map<CarControllerCommand, std::function<void()>> m_command = {
		{ CarControllerCommand::TurnOnEngine,	[this]() { TurnOnEngineCommand(); } },
		{ CarControllerCommand::TurnOffEngine,	[this]() { TurnOffEngineCommand(); } },
		{ CarControllerCommand::SetGear,		[this]() { SetGearCommand(); } },
		{ CarControllerCommand::SetSpeed,		[this]() { SetSpeedCommand(); } },
		{ CarControllerCommand::Shutdown,		[this]() { ShutdownCommand(); } },
		{ CarControllerCommand::Help,			[this]() { ShowHelpCommand(); } },
		{ CarControllerCommand::Info,			[this]() { ShowInfoCommand(); } },
	};
	
	const std::map<std::string, CarControllerCommand> CONTROLLER_COMMAND_STRING{
		{ "engineon", CarControllerCommand::TurnOnEngine },
		{ "engineoff", CarControllerCommand::TurnOffEngine },
		{ "setgear", CarControllerCommand::SetGear },
		{ "setspeed", CarControllerCommand::SetSpeed },
		{ "shutdown", CarControllerCommand::Shutdown },
		{ "help", CarControllerCommand::Help },
		{ "info", CarControllerCommand::Info }
	};

	const std::map<CarDirection, std::string> DIRECTION_STRING{
		{ CarDirection::Backward, "Backward" },
		{ CarDirection::Forward, "Forward" },
		{ CarDirection::Standing, "Is staying" }
	};
};

/*
	TO DO:
	1) выделить логику carController
	2) вынести в map название команды и функция
	3) добавление тестов на пограничное значение скорости при 4 передаче
*/