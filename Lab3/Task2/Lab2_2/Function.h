#pragma once
#include "Operations.h"
#include <functional>
#include <iostream>
#include <vector>
#include <string>
#include <map>

class Function
{
public:
	Function();
	Function(const std::string& identifier);
	Function(const std::string& firstIdentifier, const Operations& operation, const std::string& secondIdentifier);
	
	double Execute(const std::function<double(std::string)>& GetValue) const;

private:
	std::vector<std::string> m_identifiers;
	Operations m_operation = Operations::NONE;

	double CalculateOperationResult(double firstArg, double secondArg) const;
};
