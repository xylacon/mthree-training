#ifndef DERIVED_PRIVATE_H
#define DERIVED_PRIVATE_H

#include "Base.h"

#include <string>

class DerivedPrivate : private Base {
public:
	DerivedPrivate() : Base("DerivedPrivate", "DerivedPrivate", "DerivedPrivate") {}

	void print() override {
		std::cout << "DERIVED_PRIVATE\n"
			<< "publicVar: " << publicVar << '\n'
			<< "protectedVar: " << protectedVar << '\n'
			<< "privateVar: inaccessible" << '\n'; 
	}
};

#endif