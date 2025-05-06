#pragma once
#include <cctype>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <stack>

class ExpressionParser
{
public:
	int EvaluateExpression(const std::string& expression);

private:
	std::vector<std::string> Tokenize(const std::string& expression);

	bool IsOperator(const std::string& token);
	std::vector<int> ParseArguments(const std::vector<std::string>& current);

	int HandleCloseBracket(std::stack<std::vector<std::string>>& stack);
	int ApplyOperator(const char math_operator, const std::vector<int> arguments);

	void HandleToken(std::stack<std::vector<std::string>>& stack, const std::string& token);
};
