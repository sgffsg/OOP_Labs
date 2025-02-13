#include <fstream>
#include <iostream>
#include <string>

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

		// Если не найдено, добавляем остаток и выходим
		if (foundPos == std::string::npos)
		{ 
			result.append(subject, pos, subject.length() - pos);
			break;
		}

		// В результирующую строку записываем текст из диапазона [pos,foundPos)
		result.append(subject, pos, foundPos - pos);
		result.append(replacementString); 
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

	outputFile.flush();
}


void CopyFileWithReplacement(const std::string& inputFileName, const std::string& outputFileName, const std::string& searchString, const std::string& replacementString)
{
	std::ifstream inputFile(inputFileName);
	std::ofstream outputFile(outputFileName);

	if (!inputFile.is_open())
	{
		std::cout << "Failed to open '" << inputFileName << "' for reading\n";
		exit(1);
	}

	if (!outputFile.is_open())
	{
		std::cout << "Failed to open '" << outputFileName << "' for writing\n";
		exit(1);
	}

	CopyStreamWithReplacement(inputFile, outputFile, searchString, replacementString);
}



void ReplaceFromStdin()
{
	std::string searchString, replacementString, baseString;

	if (!std::getline(std::cin, searchString))
	{
		std::cout << "ERROR" << std::endl;
		exit(0);
	}

	if (!std::getline(std::cin, replacementString))
	{
		std::cout << "ERROR" << std::endl;
		exit(0);
	}

	while (std::getline(std::cin, baseString))
	{
		std::cout << ReplaceString(baseString, searchString, replacementString) << "\n"; 
	}
}

void ShowHelp()
{
	std::cout << "Программа replace.exe, выполняет замену всех вхождений подстроки в текстовом файле на другую строку, и записывает результат в выходной файл." << std::endl;
	std::cout << "Использование:" << std::endl;
	std::cout << "1) Ввод через командную строку:" << std::endl;
	std::cout << "replace.exe <inputFile> <outputFile> <searchString> <replacementString>" << std::endl;
	std::cout << "2) Ввод через stdin:" << std::endl;
	std::cout << "replace.exe" << std::endl;
	std::cout << "Принимает первой строкой искомую строку, второй строкой - строку-заменитель, затем текст для замены." << std::endl;
	exit(0);
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "russian");

	if (argc == 1)
	{
		ReplaceFromStdin();
	}
	else if (argc == 2 && std::string(argv[1]) == "-h")
	{
		ShowHelp();
	}
	else if (argc == 5)
	{
		std::string inputFile = argv[1];
		std::string outputFile = argv[2];
		std::string searchString = argv[3];
		std::string replacementString = argv[4];
		CopyFileWithReplacement(inputFile, outputFile, searchString, replacementString);
	}
	else
	{
		std::cout << "ERROR" << std::endl;
		exit(1);
	}

	return 0;
}