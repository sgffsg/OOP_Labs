#include <cctype>
#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>
#include "ExpressionParser.h"

int main()
{
	std::string line;
	ExpressionParser expressionParser;

	while (std::getline(std::cin, line))
	{
		try
		{
			int result = expressionParser.EvaluateExpression(line);
			std::cout << result << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "ERROR" << std::endl;
		}
	}
	return 0;
}