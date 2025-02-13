//#include <fstream>
//#include <iostream>
//#include <optional>
//#include <string>
//
//struct Args
//{
//	std::string inputFilePath;
//	std::string outputFilePath;
//	std::string searchString;
//	std::string replacementString;
//};
//
//std::optional<Args> ParseArgs(int argc, char* argv[])
//{
//	if (argc != 5)
//	{
//		std::cout << "Invalid argument count\n"
//				  << "Usage: replace.exe <inputFile> <outputFile> <searchString> <replacementString>\n";
//		exit(1);
//	}
//	Args args;
//	args.inputFilePath = argv[1];
//	args.outputFilePath = argv[2];
//	args.searchString = argv[3];
//	args.replacementString = argv[4];
//
//	return args;
//}
//
//std::string ReplaceString(const std::string line, const std::string searchString, const std::string replacementString) // const
//{
//	size_t pos = 0;
//	std::string result;
//
//	while (true)
//	{
//		size_t findPos = line.find(searchString, pos);
//		if (findPos != std::string::npos)
//		{
//			result.append(line, pos, findPos - pos);
//			result.append(replacementString);
//			pos = findPos + searchString.length();
//		}
//		else
//		{
//			break;
//		}
//	}
//
//	return result.append(line, pos, line.length() - pos);
//}
//
//void CopyFileWithReplace(std::ifstream& inputFile, const std::string searchString,
//	const std::string replacementString, std::ofstream& outputFile)
//{
//	std::string line;
//
//	while (std::getline(inputFile, line))
//	{
//		outputFile << ReplaceString(line, searchString, replacementString) << "\n";
//	}
//	outputFile.flush();
//}
//
//void OpenInOutFiles(std::ifstream& inputFile, std::ofstream& outputFile, const std::optional<Args> args)
//{
//	inputFile.open(args->inputFilePath);
//	if (!inputFile.is_open())
//	{
//		std::cout << "Filed to open '" << args->inputFilePath << "' for reading\n";
//		exit(1);
//	}
//
//	outputFile.open(args->outputFilePath);
//	if (!outputFile.is_open())
//	{
//		std::cout << "Filed to open '" << args->outputFilePath << "' for writing\n";
//		exit(1);
//	}
//}
//
//int main(int argc, char* argv[])
//{
//	auto args = ParseArgs(argc, argv);
//
//	std::ifstream inputFile;
//	std::ofstream outputFile;
//
//	OpenInOutFiles(inputFile, outputFile, args);
//
//	std::string searchString;
//	searchString = args->searchString;
//
//	std::string replacementString;
//	replacementString = args->replacementString;
//
//	CopyFileWithReplace(inputFile, searchString, replacementString, outputFile);
//
//	outputFile.flush();
//
//	return 0;
//}
