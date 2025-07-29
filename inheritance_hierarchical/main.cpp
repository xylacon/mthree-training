#include "DerivedC_public_public.h"
#include "DerivedC_public_virtual.h"
#include "DerivedC_virtual_public.h"
#include "DerivedC_virtual_virtual.h"

#include <iostream>
#include <string>

int main() {
	// ASSIGNMENT 5
	std::cout << "Construction Derived C (public,public):\n";
	DerivedC_public_public obj1(1, 2);
	std::cout << '\n';

	std::cout << "Construction Derived C (public,virtual):\n";
	DerivedC_public_virtual obj2(3, 4);
	std::cout << '\n';

	std::cout << "Construction Derived C (virtual,public):\n";
	DerivedC_virtual_public obj3(5, 6);
	std::cout << '\n';

	std::cout << "Construction Derived C (virtual,virtual):\n";
	DerivedC_virtual_virtual obj4(7, 8);
	std::cout << '\n';

	// ASSIGNMENT 3 & 4
	std::cout << "Derived C (public,public)\n";
	std::cout << "Parameterized constructor (1,2)...\n";
	std::cout << "\tDerivedA (public): var = " << obj1.DerivedA::var << '\n';
	std::cout << "\tDerivedB (public): var = " << obj1.DerivedB::var << '\n';
	std::cout << '\n';

	std::cout << "Derived C (public,virtual)\n";
	std::cout << "Parameterized constructor (3,4)...\n";
	std::cout << "\tDerivedA (public): var = " << obj2.DerivedA::var << '\n';
	std::cout << "\tDerivedB (virtual): var = " << obj2.DerivedB_virtual::var << '\n';
	std::cout << '\n';

	std::cout << "Derived C (virtual,public)\n";
	std::cout << "Parameterized constructor (5,6)...\n";
	std::cout << "\tDerivedA (virtual): var = " << obj3.DerivedA_virtual::var << '\n';
	std::cout << "\tDerivedB (public): var = " << obj3.DerivedB::var << '\n';
	std::cout << '\n';

	// Only case where we don't need to use scope resolution operator (::)
	std::cout << "Derived C (virtual,virtual)\n";
	std::cout << "Parameterized constructor (7,8)...\n";
	std::cout << "\tDerivedA (virtual): var = " << obj4.var << '\n';
	std::cout << "\tDerivedB (virtual): var = " << obj4.var << '\n';
	std::cout << '\n';

	return 0;
}