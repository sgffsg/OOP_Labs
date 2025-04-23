#include "CalculatorController.h"
#include <iostream>

int main()
{
	Calculator calculator;
	CalculatorController calculatorController(calculator);
	calculatorController.ProcessInput(std::cin, std::cout);
}