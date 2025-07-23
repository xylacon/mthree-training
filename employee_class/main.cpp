#include <iostream>
#include <string>
#include <vector>
#include <limits>

#include "Employee.h"
#include "EmployeeService.h"

void printMenu();
int getUserChoice(const int, const int);
void clearInput();
void run(EmployeeService*, const int);

template<typename T>
void getNum(T&);

void addEmployee(EmployeeService*);
void updateEmployee(EmployeeService*);
void deleteEmployee(EmployeeService*);
void deleteAll(EmployeeService*);
const Employee* getEmployee(EmployeeService*);
void printEmployee(const Employee*);
void printAll(EmployeeService*);
void compareEmployees(EmployeeService*);
void quit();

int main() {
	EmployeeService* service = EmployeeService::getInstance();
	int choice(0);
	while (choice != 7) {
		printMenu();
		std::cout << '\n';
		choice = getUserChoice(1, 7);
		std::cout << '\n';
		run(service, choice);
		std::cout << '\n';
	}

	// Clean up
	EmployeeService::destroyInstance();

	return 0;
}

// Employee functions
void addEmployee(EmployeeService* service) {
	std::string name;
	double salary;

	std::cout << "ADD EMPLOYEE\n\n";
	std::cout << "Enter employee name: ";
	std::getline(std::cin, name);
	std::cout << "Enter employee salary: ";
	getNum(salary);
	std::cout << '\n';

	const Employee* employee = service->addEmployee(name, salary);
	if(employee) {
		std::cout << "Employee added:\n";
		printEmployee(employee);
	}
	else {
		std::cout << "Failed to add employee\n";
	}
}

void updateEmployee(EmployeeService* service) {
	int id;
	std::string name;
	double salary;
	
	std::cout << "UPDATE EMPLOYEE\n\n";
	std::cout << "Enter employee ID: ";
	getNum(id);

	if (service->getEmployee(id) == nullptr) {
		std::cout << "Employee not found\n";
		return;
	}

	std::cout << "Enter new name: ";
	std::getline(std::cin, name);
	std::cout << "Enter new salary: ";
	getNum(salary);
	std::cout << '\n';

	const Employee* employee = service->updateEmployee(id, name, salary);
	if(employee) {
		std::cout << "Employee updated:\n";
		printEmployee(employee);
	}
	else {
		std::cout << "Failed to update employee\n";
	}
}

void deleteEmployee(EmployeeService* service) {
	int id;
	
	std::cout << "DELETE EMPLOYEE\n\n";
	std::cout << "Enter employee ID: ";
	getNum(id);
	std::cout << '\n';

	if(service->deleteEmployee(id)) {
		std::cout << "Employee deleted\n";
	}
	else {
		std::cout << "Employee not found\n";
	}
}

const Employee* getEmployee(EmployeeService* service) {
	std::cout << "PRINT EMPLOYEE\n\n";
	int id;
	std::cout << "Enter employee ID: ";
	getNum(id);

	return service->getEmployee(id);
}

void printEmployee(const Employee* employee) {
	if (employee == nullptr) {
		std::cout << "Employee does not exist\n";
	}
	else {
		std::cout
			<< "ID: " << employee->getId() << '\n'
			<< "Name: " << employee->getName() << '\n'
			<< "Salary: " << employee->getSalary() << '\n';
	}
}

void printAll(EmployeeService* service) {
	std::cout << "PRINT ALL EMPLOYEES\n\n";
	if (service->size() == 0) {
		std::cout << "There are no employees\n";
	}
	else {
		for (const Employee& e : service->getAllEmployees()) {
			printEmployee(&e);
			std::cout << '\n';
		}
	}
}

void compareEmployees(EmployeeService* service) {
	int id;
	
	std::cout << "COMPARE EMPLOYEES\n\n";
	std::cout << "Enter first employee ID: ";
	getNum(id);

	const Employee* e1 = service->getEmployee(id);

	if (e1 == nullptr) {
		std::cout << "Employee not found\n";
		return;
	}

	std::cout << "Enter second employee ID: ";
	getNum(id);
	std::cout << '\n';

	const Employee* e2 = service->getEmployee(id);

	if (e2 == nullptr) {
		std::cout << "Employee not found\n";
		return;
	}

	if (*e1 == *e2) {
		std::cout << "Employees are equal\n";
	}
	else {
		std::cout << "Employees are not equal\n";
	}
}

void quit() {
	std::cout << "Quitting...\n";
}

// Utilities
void printMenu() {
	std::cout
		<< "1. Add employee\n"
		<< "2. Update employee\n"
		<< "3. Delete employee\n"
		<< "4. Print employee\n"
		<< "5. Print all\n"
		<< "6. Compare employees\n"
		<< "7. Quit\n";
}

int getUserChoice(const int min, const int max) {
	int choice;
	while (true) {
		std::cout << "Enter an option number (" << min << "-" << max << "): ";
		getNum(choice);

		if (choice < min || choice > max) {
			std::cout << "Invalid choice\n";
		}
		else {
			return choice;
		}
	}
}

void clearInput() {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

template<typename T>
void getNum(T& val) {
	while (true) {
		std::cin >> val;
		if (std::cin.fail()) {
			std::cin.clear();  // Clear error flag
			clearInput();  // Discard remaining input
			std::cout << "Invalid input\n";
		}
		else {
			clearInput();
			return;
		}
	}
}

void run(EmployeeService* service, const int choice) {
	switch (choice) {
		case 1:
			addEmployee(service);
			break;
		case 2:
			updateEmployee(service);
			break;
		case 3:
			deleteEmployee(service);
			break;
		case 4:
			printEmployee(getEmployee(service));
			break;
		case 5:
			printAll(service);
			break;
		case 6:
			compareEmployees(service);
			break;
		case 7:
			quit();
			break;
		default:
			std::cout << "Invalid choice: " << choice << '\n';
	}
}