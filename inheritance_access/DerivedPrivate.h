#ifndef DERIVED_PRIVATE_H
#define DERIVED_PRIVATE_H

#include "Base.h"

/*
	Receives the following attributes from Base:
	publicVar is PRIVATE (inaccessible)
	protectedVar is PRIVATE (inaccessible)
*/

class DerivedPrivate : private Base {
public:
	DerivedPrivate() : Base("DerivedPrivate", "DerivedPrivate", "DerivedPrivate") {}

	void print() override {
		std::cout << "DERIVED_PRIVATE\n"
			<< "publicVar: " << publicVar << '\n'
			<< "protectedVar: " << protectedVar << '\n'; 
	}
};

#endif