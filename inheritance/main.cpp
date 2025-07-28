#include "Base.h"
#include "DerivedPublic.h"
#include "DerivedProtected.h"
#include "DerivedPrivate.h"

#include <iostream>

int main() {
	Base* base = new Base();
	DerivedPublic* derivedPublic = new DerivedPublic();
	DerivedProtected* derivedProtected = new DerivedProtected();
	DerivedPrivate* derivedPrivate = new DerivedPrivate();

	base->print();
	std::cout << '\n';

	derivedPublic->print();
	std::cout << '\n';

	derivedProtected->print();
	std::cout << '\n';

	derivedPrivate->print();
	std::cout << '\n';

	return 0;
}