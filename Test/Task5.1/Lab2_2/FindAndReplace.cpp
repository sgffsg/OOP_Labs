#include "FindAndReplace.h"

std::string FindAndReplace(const std::string subject, const std::string search, const std::string replace)
{
	size_t pos = 0;
	std::string result;

	while (true)
	{
		size_t findPos = subject.find(search, pos);
		if (findPos != std::string::npos)
		{
			result.append(subject, pos, findPos - pos);
			result.append(replace);
			pos = findPos + search.length();
		}
		else
		{
			break;
		}
	}

	return result.append(subject, pos, subject.length() - pos);
}