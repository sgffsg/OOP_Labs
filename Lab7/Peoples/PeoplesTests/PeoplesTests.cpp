#define CATCH_CONFIG_MAIN 
#include <stdexcept>
#include "../../../Catch/catch.hpp"
#include "../Peoples/CAdvancedStudent.h"
#include "../Peoples/CStudentImpl.h"
#include "../Peoples/CPersonImpl.h"
#include "../Peoples/CStudent.h"
#include "../Peoples/CPupil.h"
#include "../Peoples/CTeacher.h"
#include "../Peoples/CWorker.h"
#include "../Peoples/IInterfaces.h"


TEST_CASE("CPersonImpl constructor and methods")
{
	const std::string firstName = "Ivan";
	const std::string lastName = "Ivanov";
	const std::string middleName = "Ivanovich";
	const std::string address = "Moscow, Red Square";

	SECTION("Basic person properties")
	{
		CPersonImpl<IPerson> person(firstName, lastName, middleName, address);

		REQUIRE(person.GetFirstName() == firstName);
		REQUIRE(person.GetLastName() == lastName);
		REQUIRE(person.GetMiddleName() == middleName);
		REQUIRE(person.GetAddress() == address);
	}
}

TEST_CASE("CPupil constructor and methods")
{
	const std::string firstName = "Petr";
	const std::string lastName = "Petrov";
	const std::string middleName = "Petrovich";
	const std::string address = "St. Petersburg, Nevsky Prospect";
	const std::string school = "School #123";
	const std::string grade = "10A";

	SECTION("Pupil properties")
	{
		CPupil pupil(firstName, lastName, middleName, address, school, grade);

		REQUIRE(pupil.GetFirstName() == firstName);
		REQUIRE(pupil.GetLastName() == lastName);
		REQUIRE(pupil.GetMiddleName() == middleName);
		REQUIRE(pupil.GetAddress() == address);
		REQUIRE(pupil.GetSchool() == school);
		REQUIRE(pupil.GetGrade() == grade);
	}
}

TEST_CASE("CTeacher constructor and methods")
{
	const std::string firstName = "Maria";
	const std::string lastName = "Sidorova";
	const std::string middleName = "Vasilievna";
	const std::string address = "Kazan, Kremlin str.";
	const std::string subject = "Mathematics";

	SECTION("Teacher properties")
	{
		CTeacher teacher(firstName, lastName, middleName, address, subject);

		REQUIRE(teacher.GetFirstName() == firstName);
		REQUIRE(teacher.GetLastName() == lastName);
		REQUIRE(teacher.GetMiddleName() == middleName);
		REQUIRE(teacher.GetAddress() == address);
		REQUIRE(teacher.GetSubject() == subject);
	}
}

TEST_CASE("CWorker constructor and methods")
{
	const std::string firstName = "Alexey";
	const std::string lastName = "Smirnov";
	const std::string middleName = "Olegovich";
	const std::string address = "Novosibirsk, Lenina str.";
	const std::string specialty = "Electrician";

	SECTION("Worker properties")
	{
		CWorker worker(firstName, lastName, middleName, address, specialty);

		REQUIRE(worker.GetFirstName() == firstName);
		REQUIRE(worker.GetLastName() == lastName);
		REQUIRE(worker.GetMiddleName() == middleName);
		REQUIRE(worker.GetAddress() == address);
		REQUIRE(worker.GetSpecialty() == specialty);
	}
}

TEST_CASE("CStudent constructor and methods")
{
	const std::string firstName = "Anna";
	const std::string lastName = "Kuznetsova";
	const std::string middleName = "Sergeevna";
	const std::string address = "Ekaterinburg, Mira str.";
	const std::string university = "UrFU";
	const std::string studentId = "12345678";

	SECTION("Student properties")
	{
		CStudent student(firstName, lastName, middleName, address, university, studentId);

		REQUIRE(student.GetFirstName() == firstName);
		REQUIRE(student.GetLastName() == lastName);
		REQUIRE(student.GetMiddleName() == middleName);
		REQUIRE(student.GetAddress() == address);
		REQUIRE(student.GetUniversity() == university);
		REQUIRE(student.GetStudentId() == studentId);
	}
}

TEST_CASE("CAdvancedStudent constructor and methods")
{
	const std::string firstName = "Dmitry";
	const std::string lastName = "Volkov";
	const std::string middleName = "Andreevich";
	const std::string address = "Tomsk, Lenin str.";
	const std::string university = "TSU";
	const std::string studentId = "87654321";
	const std::string dissertationTopic = "Quantum Computing Algorithms";

	SECTION("Advanced student properties")
	{
		CAdvancedStudent advancedStudent(
			firstName, lastName, middleName, address,
			university, studentId, dissertationTopic);

		REQUIRE(advancedStudent.GetFirstName() == firstName);
		REQUIRE(advancedStudent.GetLastName() == lastName);
		REQUIRE(advancedStudent.GetMiddleName() == middleName);
		REQUIRE(advancedStudent.GetAddress() == address);
		REQUIRE(advancedStudent.GetUniversity() == university);
		REQUIRE(advancedStudent.GetStudentId() == studentId);
		REQUIRE(advancedStudent.GetDissertationTheme() == dissertationTopic);
	}
}

TEST_CASE("CStudentImpl inheritance test")
{
	const std::string firstName = "Test";
	const std::string lastName = "Testov";
	const std::string middleName = "Testovich";
	const std::string address = "Test City";
	const std::string university = "Test University";
	const std::string studentId = "TEST123";

	SECTION("StudentImpl inherits from CPersonImpl")
	{
		CStudentImpl<IPerson> studentImpl(
			firstName, lastName, middleName, address, university, studentId);

		REQUIRE(studentImpl.GetFirstName() == firstName);
		REQUIRE(studentImpl.GetLastName() == lastName);
		REQUIRE(studentImpl.GetMiddleName() == middleName);
		REQUIRE(studentImpl.GetAddress() == address);
		REQUIRE(studentImpl.GetUniversity() == university);
		REQUIRE(studentImpl.GetStudentId() == studentId);
	}
}