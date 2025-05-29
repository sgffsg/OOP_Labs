#pragma once
#include "CStudentImpl.h"
#include "IInterfaces.h"

class CStudent : public CStudentImpl<IStudent>
{
public:
	CStudent(
		const std::string& firstName,
		const std::string& lastName,
		const std::string& middleName,
		const std::string& address,
		const std::string& university,
		const std::string& studentId)
		: CStudentImpl<IStudent>(firstName, lastName, middleName, address, university, studentId)
	{
	}
};