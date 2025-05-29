#pragma once
#include "CPersonImpl.h"
#include "IInterfaces.h"
#include <string>

class CTeacher : public CPersonImpl<ITeacher>
{
public:
	CTeacher(
		const std::string& firstName,
		const std::string& lastName,
		const std::string& middleName,
		const std::string& address,
		const std::string& subject)
		: CPersonImpl<ITeacher>(firstName, lastName, middleName, address)
		, m_subject(subject)
	{
	}

	std::string GetSubject() const override
	{
		return m_subject;
	}

private:
	std::string m_subject;
};