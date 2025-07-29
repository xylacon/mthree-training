#include "Derived.h"

#include <iostream>

#include "BaseA.h"
#include "BaseB.h"

int main() {
	Derived obj1;
	std::cout << '\n';

	// ASSIGNMENT 2
	Derived obj2(1);
	std::cout << '\n';
	
	// ASSIGNMENT 1
	Derived obj3(2, 3);
	std::cout << '\n';

	return 0;
}