#include "CMyString.h"
#include <cassert>

int	main()
{
	const char* stri = "Done";
	CMyString str(stri);
	CMyString str1("Hello1 Hello World!!!!!!!");
	str += str1;
	std::cout << str;

	std::string test;
	test.begin();

	const CMyString cstr("World");
	for (auto it = cstr.cbegin(); it != cstr.cend(); ++it)
	{
		std::cout << *it;
	}

	CMyString str2("Hello");
	auto it1 = str2.begin();
	auto it2 = it1 + 3;
	assert(it2 - it1 == 3);
	assert(it1[2] == 'l');

	return EXIT_SUCCESS;
}