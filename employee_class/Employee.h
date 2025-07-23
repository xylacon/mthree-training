#pragma once
#include <string>

class Employee {
private:
	static int sCount;
	int id;
	std::string name;
	double salary;

	static int generateId();

public:
	Employee();
	Employee(std::string, const double);

	void setName(std::string);
	void setSalary(const double);

	int getId() const;
	std::string getName() const;
	double getSalary() const;

	void print() const;

	friend bool operator==(const Employee&, const Employee&);
};