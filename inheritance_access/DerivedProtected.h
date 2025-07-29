#ifndef DERIVED_PROTECTED_H
#define DERIVED_PROTECTED_H

#include "Base.h"

/*
	Receives the following attributes from Base:
	publicVar is PROTECTED (access by derived)
	protectedVar is PROTECTED (access by derived)
*/

class DerivedProtected : protected Base {
public:
	DerivedProtected() : Base("DerivedProtected", "DerivedProtected", "DerivedProtected") {}

	void print() override {
		std::cout << "DERIVED_PROTECTED\n"
			<< "publicVar: " << publicVar << '\n'
			<< "protectedVar: " << protectedVar << '\n'; 
	}
};

#endif