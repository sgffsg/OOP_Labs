#pragma once
#include "CPersonImpl.h"
#include "IInterfaces.h"


class CWorker : public CPersonImpl<IWorker>
{
public:
	CWorker(
		const std::string& firstName,
		const std::string& lastName,
		const std::string& middleName,
		const std::string& address,
		const std::string& specialty)
		: CPersonImpl<IWorker>(firstName, lastName, middleName, address)
		, m_specialty(specialty)
	{
	}

	std::string GetSpecialty() const override
	{
		return m_specialty;
	}

private:
	std::string m_specialty;
};