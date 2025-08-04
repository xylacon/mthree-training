#include "NameException.h"
#include "AgeException.h"

#include <iostream>
#include <string>

int main() {
	std::cout << "STUDENT ENROLLMENT\n\n";

	std::string name;
	int age;
	try {
		std::cout << "Enter name between 10-30 characters: ";
		std::getline(std::cin, name);
		if (name.size() < 10) throw NameException("too short");
		if (name.size() > 30) throw NameException("too long");

		std::cout << "Enter age between 15-22: ";
		std::cin >> age;
		if (age < 15) throw AgeException("too low");
		if (age > 22) throw AgeException("too high");

		std::cout << "\nSuccessfully nrolled student:\n"
		<< "Name: " << name << '\n'
		<< "Age: " << age << '\n';
	} catch(const NameException& e) {
		std::cerr << "Exception: Name is " << e.what() << '\n';
	} catch(const AgeException& e) {
		std::cerr << "Exception: Age is " << e.what() << '\n';
	}
	std::cout << '\n';

	return 0;
}