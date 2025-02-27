#include "MultiplyToMinElt.h"
#include <iostream>
#include <vector>

int main()
{
	try
	{
		std::vector<float> vector = ReadVector(std::cin);
		MultiplyEltsToMinElt(vector);
		PrintVector(vector, std::cout);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}
}