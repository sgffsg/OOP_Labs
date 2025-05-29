#pragma once
#include "CPersonImpl.h"
#include "IInterfaces.h"

class CPupil : public CPersonImpl<IPupil>
{
public:
	CPupil(
		const std::string& firstName,
		const std::string& lastName,
		const std::string& middleName,
		const std::string& address,
		const std::string& school,
		const std::string& grade)
		: CPersonImpl<IPupil>(firstName, lastName, middleName, address)
		, m_school(school)
		, m_grade(grade)
	{
	}

	std::string GetSchool() const override
	{
		return m_school;
	}

	std::string GetGrade() const override
	{
		return m_grade;
	}

private:
	std::string m_school;
	std::string m_grade;
};