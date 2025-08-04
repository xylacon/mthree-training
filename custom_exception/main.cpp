#include "LowerLengthOfCharacters.h"
#include "HigherLengthOfCharacters.h"
#include "UnderAgeException.h"
#include "OverAgeException.h"

#include <iostream>
#include <string>

int main() {
	std::cout << "STUDENT ENROLLMENT\n\n";

	std::string name;
	int age;
	try {
		std::cout << "Enter name between 10-30 characters: ";
		std::getline(std::cin, name);
		if (name.size() < 10) throw LowerLengthOfCharacters(name.size());
		if (name.size() > 30) throw HigherLengthOfCharacters(name.size());

		std::cout << "Enter age between 15-22: ";
		std::cin >> age;
		if (age < 15) throw UnderAgeException(age);
		if (age > 22) throw OverAgeException(age);

		std::cout << "\nSuccessfully enrolled student:\n"
		<< "Name: " << name << '\n'
		<< "Age: " << age << '\n';
	} catch(const LowerLengthOfCharacters& e) {
		std::cerr << e.what() << '\n';
	} catch(const HigherLengthOfCharacters& e) {
		std::cerr << e.what() << '\n';
	} catch(const UnderAgeException& e) {
		std::cerr << e.what() << '\n';
	} catch(const OverAgeException& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << '\n';

	return 0;
}