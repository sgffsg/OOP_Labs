#pragma once
#include <string>

template <typename Base>
class CPersonImpl : public Base
{
public:
	CPersonImpl(
		std::string firstName,
		std::string lastName,
		std::string middleName,
		std::string address)
		: m_firstName(firstName)
		, m_lastName(lastName)
		, m_middleName(middleName)
		, m_address(address)
	{
	}


	std::string GetFirstName() const override
	{
		return m_firstName;
	}

	std::string GetLastName() const override
	{
		return m_lastName;
	}

	std::string GetMiddleName() const override
	{
		return m_middleName;
	}

	std::string GetAddress() const override
	{
		return m_address;
	}

private:
	std::string m_firstName;
	std::string m_lastName;
	std::string m_middleName;
	std::string m_address;
};