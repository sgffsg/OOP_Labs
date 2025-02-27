#include <fstream>
#include <iostream>
#include <string>

enum InputMode
{
	HELP,
	STDIN,
	PARAMS
};

struct Args
{
	std::string inputFileName;
	std::string outputFileName;
	std::string searchString;
	std::string replacementString;
	InputMode inputMode;
};

Args ParseArgs(int argc, char* argv[])
{
	Args args;

	if (argc == 1)
	{
		args.inputMode = STDIN;
	}
	else if (argc == 2 && std::string(argv[1]) == "-h")
	{
		args.inputMode = HELP;
	}
	else if (argc == 5)
	{
		std::string inputFileName = argv[1];
		std::string outputFileName = argv[2];
		std::string searchString = argv[3];
		std::string replacementString = argv[4];
		args.inputMode = PARAMS;
	}
	else
	{
		throw std::runtime_error("Invalid aruments count\n");
		exit(1);
	}

	return args;
}

std::string ReplaceString(const std::string& subject, const std::string& searchString, const std::string& replacementString)
{
	if (searchString.empty())
	{
		return subject;
	}

	size_t pos = 0;

	std::string result;
	while (pos < subject.length())
	{
		size_t foundPos = subject.find(searchString, pos);
		if (foundPos == std::string::npos)
		{
			result.append(subject, pos);
			return result;
		}

		result.append(subject.substr(pos, foundPos - pos) + replacementString);
		pos = foundPos + searchString.length();
	}

	return result;
}

void CopyStreamWithReplacement(std::istream& inputFile, std::ostream& outputFile, const std::string& searchString, const std::string& replacementString)
{
	std::string line;
	while (std::getline(inputFile, line))
	{
		outputFile << ReplaceString(line, searchString, replacementString) << "\n";
	}
}

void CopyFileWithReplacement(const std::string& inputFileName, const std::string& outputFileName, const std::string& searchString, const std::string& replacementString)
{
	std::ifstream inputFile(inputFileName);
	std::ofstream outputFile(outputFileName);

	inputFile.open(inputFileName);
	outputFile.open(outputFileName);

	if (!inputFile.is_open())
	{
		throw std::runtime_error("Failed to open " + inputFileName + " for reading\n");
		exit(1);
	}

	if (!outputFile.is_open())
	{
		throw std::runtime_error("Failed to open " + outputFileName + " for writing\n");
		exit(1);
	}

	CopyStreamWithReplacement(inputFile, outputFile, searchString, replacementString);

	if (inputFile.bad())
	{
		throw std::runtime_error("Failed to read data from " + inputFileName + "\n");
		exit(1);
	}
	if (!outputFile.flush())
	{
		throw std::runtime_error("Failed to write data to " + outputFileName + "\n");
		exit(1);
	}
}

void ReplaceFromStdin()
{
	std::string searchString, replacementString, baseString, resultStr;

	if (!std::getline(std::cin, searchString))
	{
		throw std::runtime_error("ERROR");
	}

	if (!std::getline(std::cin, replacementString))
	{
		throw std::runtime_error("ERROR");
	}

	while (std::getline(std::cin, baseString))
	{
		std::cout << ReplaceString(baseString, searchString, replacementString) << "\n";
	}
}

void ShowHelp()
{
	std::cout << "Usage:" << std::endl;
	std::cout << "1) replace.exe <inputFile> <outputFile> <searchString> <replacementString>" << std::endl;
	std::cout << "or" << std::endl;
	std::cout << "2) replace.exe" << std::endl;
}

int main(int argc, char* argv[])
{
	try
	{
		Args args = ParseArgs(argc, argv);
		switch (args.inputMode)
		{
		case 0:
			ShowHelp();
			break;
		case 1:
			ReplaceFromStdin();
			break;
		case 2:
			CopyFileWithReplacement(args.inputFileName, args.outputFileName, args.searchString, args.replacementString);
			break;
		default:
			break;
		}
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
		return 1;
	}

	return 0;
}