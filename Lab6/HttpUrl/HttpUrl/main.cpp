#include "HttpUrlHandler.h"
#include <iostream>

int main()
{
	HttpUrlHandler handler;
	handler.Handle(std::cin, std::cout);
}
