#include "HTMLDecode.h"
#include <iostream>

int main()
{
	std::string line;
	while (std::getline(std::cin, line))
	{
		std::cout << HtmlDecode(line) << "\n";
	}
}
