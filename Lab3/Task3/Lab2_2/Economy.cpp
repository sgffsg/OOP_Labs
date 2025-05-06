#include <optional>
#include <iostream>
#include <string>
#include "Bank.h"


struct Args
{
	int iteratonsCount;
};

Args ParseArgs(int argc, char* argv[])
{
	Args args;
	if (argc != 2)
	{
		int iterationsCount = 0;
		std::cout << "Enter Economy Iterations Count:\n";
		std::cin >> iterationsCount;
		args.iteratonsCount = iterationsCount;
	}
	else
	{
		try
		{
			args.iteratonsCount = std::stoi(argv[1]);
		}
		catch (const std::exception& e)
		{
			throw std::invalid_argument("Invalid argument value");
			std::cout << e.what() << "\n";
		}
	}

	
	return args;
}

int main(int argc, char* argv[])
{
	try
	{

		Bank bank(10000000);

		auto args = ParseArgs(argc, argv);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << "\n";
		return 1;
	}
}