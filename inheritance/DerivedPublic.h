#ifndef DERIVED_PUBLIC_H
#define DERIVED_PUBLIC_H

#include "Base.h"

/*
	Receives the following attributes from Base:
	publicVar is PUBLIC (access by all)
	protectedVar is PROTECTED (access by derived)
*/

class DerivedPublic : public Base {
public:
	DerivedPublic() : Base("DerivedPublic", "DerivedPublic", "DerivedPublic") {}

	void print() override {
		std::cout << "DERIVED_PUBLIC\n"
			<< "publicVar: " << publicVar << '\n'
			<< "protectedVar: " << protectedVar << '\n'; 
	}
};

#endif