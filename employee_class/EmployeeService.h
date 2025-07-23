#pragma once

#include <vector>

#include "Employee.h"

class EmployeeService {
private:
	static EmployeeService* instance;
	std::vector<Employee> employees;
	int count;

	// Private constructor/destructor to ensure single instance
	EmployeeService();
	~EmployeeService();

	// Delete copy constructor and assignment operator to ensure single instance
	EmployeeService(const EmployeeService&) = delete;
    EmployeeService& operator=(const EmployeeService&) = delete;

public:
	static EmployeeService* getInstance();
	static void destroyInstance();

	Employee* addEmployee(const std::string&, const double);
	Employee* updateEmployee(const int, const std::string&, const double);
	bool deleteEmployee(const int);
	const Employee* getEmployee(const int) const;
	const std::vector<Employee>& getAllEmployees() const;

	int size() const;
};