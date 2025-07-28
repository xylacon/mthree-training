#ifndef DERIVED_PUBLIC_H
#define DERIVED_PUBLIC_H

#include "Base.h"

class DerivedPublic : public Base {
public:
	DerivedPublic() : Base("DerivedPublic", "DerivedPublic", "DerivedPublic") {}

	void print() override {
		std::cout << "DERIVED_PUBLIC\n"
			<< "publicVar: " << publicVar << '\n'
			<< "protectedVar: " << protectedVar << '\n'
			<< "privateVar: inaccessible" << '\n'; 
	}
};

#endif