#pragma once
#include <string>
#include "IInterfaces.h"
#include "CStudentImpl.h"

class CAdvancedStudent : public CStudentImpl<IAdvancedStudent>
{
public:
	CAdvancedStudent(
		const std::string& firstName,
		const std::string& lastName,
		const std::string& middleName,
		const std::string& address,
		const std::string& university,
		const std::string& studentId,
		const std::string& dissertationTheme)
		: CStudentImpl<IAdvancedStudent>(firstName, lastName, middleName, address, university, studentId)
		, m_dissertationTheme(dissertationTheme)
	{
	}

	std::string GetDissertationTheme() const override
	{
		return m_dissertationTheme;
	}

private:
	std::string m_dissertationTheme;
};