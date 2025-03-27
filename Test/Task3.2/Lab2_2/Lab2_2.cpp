#include "Dictionary.h"
#include <Windows.h>
#include <iostream>
#include <string>
#include <algorithm>

const std::string EXIT_WORD = "...";

std::string ParseArgs(int argc, char* argv[])
{
	if (argc != 2)
	{
		throw std::runtime_error("Invalid arguments count\nUsage: Translator.exe <dictionary file name>\n");
	}

	return argv[1];
}

void DictionaryWasChanged(const Dictionary& dictionary, const std::string& dictionaryFileName)
{
	std::cout << "В словарь были внесены изменения. Введите Y или y для сохранения перед выходом.\n";

	std::string userAns;
	std::getline(std::cin, userAns);

	if (userAns == "Y" || userAns == "y")
	{
		SaveDictionaryToFile(dictionary, dictionaryFileName);

		std::cout << "Изменения сохранены.\n";
	}
	else
	{
		std::cout << "Изменения не были сохранены.\n";
	}
}

void SaveWordWithoutTranslation(std::string& word, Dictionary& dictionary, bool& isChanged)
{
	std::cout << "Неизвестное слово \"" + word + "\". Введите перевод или пустую строку для отказа.\n";

	std::string translate;
	std::getline(std::cin, translate);
	if (!translate.empty())
	{
		std::cout << "Слово \"" << word << "\" сохранено как \"" << translate << "\"\n";

		SaveWordToDictionary(dictionary, StringToLower(word), translate);
		isChanged = true;
	}
	else
	{
		std::cout << "Слово " + word + " проигноринованно\n";
	}
}

void CheckWordTranslate(Dictionary& dictionary, std::string word, bool& isChanged)
{
	auto translate = TranslateWord(dictionary, word);
	if (!translate)
	{
		SaveWordWithoutTranslation(word, dictionary, isChanged);
	}
	else
	{
		std::cout << translate.value() << "\n";
	}
}


int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string word;
	bool isChanged = false;

	try
	{
		
		std::string dictionaryFileName = ParseArgs(argc, argv);
		Dictionary dictionary = LoadDictionaryFromFile(dictionaryFileName);

		
		while (std::getline(std::cin, word))
		{
			if (word == EXIT_WORD)
			{
				if (isChanged)
				{
					DictionaryWasChanged(dictionary, dictionaryFileName);
				}

				std::cout << "Выход из программы.\n";
				break;
			}
			
			CheckWordTranslate(dictionary, word, isChanged);
		}
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
		return 1;
	}

	return 0;
}
