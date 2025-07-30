#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
public:
	Student();
	Student(std::string, std::string);
	Student(std::string, std::string, const int);

	void setName(std::string);
	void setSpecial(std::string);
	void setGrade(const int);

	int getId() const;
	std::string getName() const;
	std::string getSpecial() const;
	int getGrade() const;

	void print() const;

private:
	static int baseId;

	int id;
	std::string name;
	std::string special;  // Specialization
	int grade;

	int generateId();
};

#endif