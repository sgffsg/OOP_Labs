#include "ParseURL.h"
#include <iostream>

int main(int argc, char* argv[])
{
	int port = 0;
	Protocol protocol;
	std::string url, host, doc;

	while (std::cin >> url)
	{
		try
		{	
			ParseURL(url, protocol, port, host, doc);
			
			std::cout << url << "\n"
						  << "HOST: " << host << "\n"
						  << "PORT: " << port << "\n"
						  << "DOC: " << doc << "\n";
			
			
		}
		catch (const std::out_of_range& e)
		{
			std::cout << "Some value has exceeded the acceptable range\n";
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << "\n";
		}
	}
}