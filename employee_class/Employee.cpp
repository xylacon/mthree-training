#include <iostream>
#include <iomanip>

#include "Employee.h"

int Employee::sCount = 2000;
int Employee::generateId() { return ++sCount; }

// Constructors
Employee::Employee() {}
Employee::Employee(const std::string _name, const double _salary) : name(_name), salary(_salary) { id = generateId(); }

// Setters
void Employee::setName(const std::string _name) { name = std::move(_name); }
void Employee::setSalary(const double _salary) { salary = _salary; }

// Getters
int Employee::getId() const { return id; }
std::string Employee::getName() const { return name; }
double Employee::getSalary() const { return salary; }

// Utilities
void Employee::print() const {
	std::cout << "Employee ID: " << id << '\n'
		<< "Employee Name: " << name << '\n'
		<< "Employee Salary: $" << std::fixed << std::setprecision(2) << salary << '\n';
}

bool operator==(const Employee& left, const Employee& right) {
	return (
		left.id == right.id &&
		left.name == right.name &&
		left.salary == right.salary
	);
}