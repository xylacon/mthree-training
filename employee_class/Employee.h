#pragma once
#include <string>

class Employee {
public:
	Employee();
	Employee(std::string, double);

	void setEmpId(int);
	void setName(std::string);
	void setSalary(double);

	void print();
private:
	static int count;
	int empId;
	std::string name;
	double salary;

	static int generateEmpId();
};