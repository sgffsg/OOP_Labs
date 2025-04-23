#pragma once
#include "Calculator.h"
#include "Commands.h"
#include <iomanip>
#include <regex>

class CalculatorController
{
public:
	CalculatorController(Calculator& calculator);
	void ProcessInput(std::istream& in, std::ostream& out);

private:
	const int PRECISION = 2;
	Calculator m_calculator;
	void HandleCommand(const std::string& str, std::ostream& out);
	void ParseCommand(const std::regex& pattern, std::smatch& match, const std::string& command) const;
	void VarCommand(const std::string& identifier);
	void LetCommand(const std::string& identifier, const std::string& value);
	void FnCommand(const std::string& identifier, const std::string& arg1, const std::string& operation, const std::string& arg2);
	void PrintCommand(const std::string& identifier, std::ostream& out) const;
	void PrintVarsCommand(std::ostream& out) const;
	void PrintFnsCommand(std::ostream& out) const;
	void CheckIdentifierWithReservedWords(const std::string& identifier) const;
	std::function<void(std::string, double)> CreateFnToPrintValue(std::ostream& out) const;
};