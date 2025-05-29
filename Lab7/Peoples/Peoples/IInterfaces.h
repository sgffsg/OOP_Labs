#pragma once
#include <string>

class IPerson
{
public:
	virtual ~IPerson() = default;
	virtual std::string GetFirstName() const = 0;
	virtual std::string GetLastName() const = 0;
	virtual std::string GetMiddleName() const = 0;
	virtual std::string GetAddress() const = 0;
};

class IPupil : public IPerson
{
public:
	virtual std::string GetSchool() const = 0;
	virtual std::string GetGrade() const = 0;
};

class ITeacher : public IPerson
{
public:
	virtual std::string GetSubject() const = 0;
};

class IStudent : public IPerson
{
public:
	virtual std::string GetUniversity() const = 0;
	virtual std::string GetStudentId() const = 0;
};

class IWorker : public IPerson
{
public:
	virtual std::string GetSpecialty() const = 0;
};

class IAdvancedStudent : public IStudent
{
public:
	virtual std::string GetDissertationTheme() const = 0;
};