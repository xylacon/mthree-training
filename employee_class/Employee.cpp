#include <iostream>
#include <iomanip>

#include "Employee.h"

int Employee::count = 2000;

int Employee::generateEmpId() { return ++count; }

Employee::Employee() {}
Employee::Employee(std::string _name, double _salary) : name(_name), salary(_salary) { empId = generateEmpId(); }

void Employee::print() {
	std::cout << "Employee ID: " << empId << '\n'
		<< "Employee Name: " << name << '\n'
		<< "Employee Salary: $" << std::fixed << std::setprecision(2) << salary << '\n';
}