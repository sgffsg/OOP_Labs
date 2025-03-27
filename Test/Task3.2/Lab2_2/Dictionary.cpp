#include "Dictionary.h"
#include <fstream>
#include <string>
#include <iostream>

std::string StringToLower(const std::string& str)
{
	std::string lowerStr;
	for (const char& c : str)
	{
		lowerStr += tolower(c);
	}

	return lowerStr;
}

Dictionary LoadDictionaryFromFile(const std::string& fileName)
{
	if (fileName.empty())
	{
		throw std::runtime_error("Filename can not be empty");
	}

	std::ifstream file(fileName);

	if (!file.is_open())
	{
		return std::map<std::string, std::string>();
	}

	std::map<std::string, std::string> dictionary;
	std::string word;
	std::string translate;

	while (std::getline(file, word) && std::getline(file, translate))
	{
		if (word.empty() || translate.empty())
		{
			break;
		}
		dictionary[word] = translate;
	}

	if (!file.eof())
	{
		throw std::runtime_error("Failed to read data from " + fileName);
	}

	return dictionary;
}

std::optional<std::string> TranslateWord(const Dictionary& dictionary, const std::string& word)
{
	std::string wordToTranslate = StringToLower(word);
	if (dictionary.find(wordToTranslate) == dictionary.end())
	{
		return std::nullopt;
	}

	return dictionary.at(wordToTranslate);
}

void SaveWordToDictionary(Dictionary& dictionary, const std::string& word, const std::string& translate)
{
	if (dictionary.find(word) != dictionary.end() || word.empty() || translate.empty())
	{
		return;
	}

	dictionary[word] = translate;
}

void SaveDictionaryToFile(const Dictionary& dictionary, const std::string& fileName)
{
	if (fileName.empty())
	{
		throw std::runtime_error("File name can not be empty");
	}

	std::ofstream file(fileName);

	for (const auto& [word, translate] : dictionary)
	{
		file << word << "\n"
			 << translate << "\n";
	}

	if (!file.flush())
	{
		throw std::runtime_error("Failed write data to " + fileName);
	}
}

