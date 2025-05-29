#pragma once
#include "CPersonImpl.h"
#include <string>

template <typename Base>
class CStudentImpl : public CPersonImpl<Base>
{
public:
	CStudentImpl(
		const std::string& firstName,
		const std::string& lastName,
		const std::string& middleName,
		const std::string& address,
		const std::string& university,
		const std::string& studentId)
		: CPersonImpl<Base>(firstName, lastName, middleName, address)
		, m_university(university)
		, m_studentId(studentId)
	{
	}

	std::string GetUniversity() const
	{
		return m_university;
	}

	std::string GetStudentId() const 
	{
		return m_studentId;
	}

private:
	std::string m_university;
	std::string m_studentId;
};