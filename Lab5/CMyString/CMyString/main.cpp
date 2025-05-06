#include "CMyString.h"

int	main()
{
	const char* stri = "Done";
	CMyString str(stri);
	CMyString str1("Hello1 Hello World!!!!!!!");
	str += str1;
	std::cout << str;
	return EXIT_SUCCESS;
}