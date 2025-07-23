#include "EmployeeService.h"

EmployeeService* EmployeeService::instance = nullptr;

EmployeeService::EmployeeService() : count(0) {}
EmployeeService::~EmployeeService() {}

EmployeeService* EmployeeService::getInstance() {
	if (instance == nullptr) {
		instance = new EmployeeService();
	}
	return instance;
}
void EmployeeService::destroyInstance() {
	delete instance;
	instance = nullptr;
}

Employee* EmployeeService::addEmployee(const std::string& name, const double salary) {
	employees.emplace_back(name, salary);
	++count;
	return &employees.back();
}

Employee* EmployeeService::updateEmployee(const int id, const std::string& name, const double salary) {
	for (Employee& e : employees) {
		if (e.getId() == id) {
			e.setName(name);
			e.setSalary(salary);
			return &e;
		}
	}

	return nullptr;
}

bool EmployeeService::deleteEmployee(const int id) {
	auto it(employees.begin());
	while (it != employees.end()) {
		if (it->getId() == id) {
			it = employees.erase(it);
			--count;
			return true;
		}
		else {
			++it;
		}
	}

	return false;
}

const Employee* EmployeeService::getEmployee(const int id) const {
	for (const Employee& e : employees) {
		if (e.getId() == id) {
			return &e;
		}
	}

	return nullptr;
}

const std::vector<Employee>& EmployeeService::getAllEmployees() const { return employees; }

int EmployeeService::size() const { return count; }