#pragma once
#include <cctype>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

class ExpressionParser
{
public:
	int EvaluateExpression(const std::string& expression);

private:
	std::vector<std::string> Tokenize(const std::string& expression);
	bool IsOperator(const std::string& token);
	int ApplyOperator(const char math_operator, const std::vector<int> arguments);
};
