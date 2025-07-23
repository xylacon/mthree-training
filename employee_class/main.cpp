#include <iostream>
#include <string>

#include "Employee.h"

int main() {
	std::string name;
	double salary;

	std::cout << "Enter employee name: ";
	std::getline(std::cin, name);
	std::cout << "Enter employee salary: ";
	std::cin >> salary;

	Employee emp(name, salary);
	emp.print();

	return 0;
}