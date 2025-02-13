#include <cmath>
#include <fstream>
#include <iostream>
#include <optional>
#include <string>

struct Args
{
	int sourceN;
	int destN;
	std::string value;
};

int CharToNumber(const char ch)
{
	int number = 0;

	if (ch <= '9' && ch >= '0')
	{
		number = ch - '0';
	}
	else
	{
		number = ch - 'A' + 10;
	}
	return number;
}

int StringToInt(const std::string value, const int radix, bool& wasError)
{
	int result = 0;
	int maxInt = 2147483647; // MAX_INT
	size_t countOfRanks;
	countOfRanks = value.length();

	int deltaMinus = value[0] == '-' ? 1 : 0;

	int tmpNum = 0;
	for (int i = 0; i < countOfRanks - deltaMinus; i++)
	{
		tmpNum = CharToNumber(value[countOfRanks - 1 - i]);
		if (tmpNum < radix)
		{
			if (maxInt - result - tmpNum * pow(radix, i) >= 0)
			{
				result += tmpNum * pow(radix, i);
			}
			else
			{
				std::cout << "Invalid value\n"
						  << "Max value is 2147483647\n";
				wasError = true;
			}
		}
		else
		{
			std::cout << "Invalid value\n"
					  << "Value must be of the <radix> number system\n";
			wasError = true;
			break;
		}
	}

	return deltaMinus == 1 ? -result : result;
}

char NumberToChar(const int number, const int radix)
{
	char ch;

	if (number % radix > 9)
	{
		ch = char('A' + (number % radix) - 10);
	}
	else
	{
		ch = char((number % radix) + '0');
	}
	return ch;
}

std::string IntToString(int value, int radix, bool& wasError)
{
	std::string res;
	int workValue;
	workValue = abs(value);

	if (value == 0)
	{
		return "0";
	}

	for (int i = 0; workValue > 0; i++)
	{
		if (workValue == radix)
		{
			res = "10" + res;
			break;
		}
		else
		{
			res = NumberToChar(workValue, radix) + res;
		}

		workValue /= radix;
	}

	if (value < 0)
	{
		return "-" + res;
	}
	return res;
}

std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 4)
	{
		std::cout << "Invalid argument count\n"
				  << "Usage: radix.exe <source notation> <destination notation> <value>\n";
		exit(1);
	}
	bool wasError = false;
	Args args;
	args.sourceN = StringToInt(argv[1], 10, wasError);
	args.destN = StringToInt(argv[2], 10, wasError);

	int minNotation = 2;
	int maxNotation = 36;
	if (args.sourceN < minNotation || args.destN < minNotation || args.sourceN > maxNotation || args.destN > maxNotation)
	{
		std::cout << "Invalid notation value\n"
				  << "Notation must be greater than or equal to 2 and less than or equal to 36\n";
		wasError = true;
	}
	args.value = argv[3];
	if (wasError)
	{
		exit(1);
	}
	return args;
}

int main(int argc, char* argv[])
{
	bool wasErr = false;
	auto args = ParseArgs(argc, argv);

	std::string resStr;
	resStr = IntToString(StringToInt(args->value, args->sourceN, wasErr), args->destN, wasErr);

	if (wasErr)
	{
		return 1;
	}

	std::cout << resStr << "\n";

	return 0;
}