#include "Base.h"
#include "DerivedPublic.h"
#include "DerivedProtected.h"
#include "DerivedPrivate.h"

#include <iostream>

void printFriend(const Base* obj) {
	std::cout << "This is a friend of Base, with full access\n"
		<< "to Base methods/attributes:\n"
		<< "publicVar: " << obj->publicVar << '\n'
		<< "protectedVar: " << obj->protectedVar << '\n'
		<< "privateVar: " << obj->privateVar << '\n';
}

int main() {
	Base base;
	DerivedPublic derivedPublic;
	DerivedProtected derivedProtected;
	DerivedPrivate derivedPrivate;

	// Internal
	std::cout << "Internally accessible\n"
		<< "---------------------\n";

	base.print();
	std::cout << '\n';

	derivedPublic.print();
	std::cout << '\n';

	derivedProtected.print();
	std::cout << '\n';

	derivedPrivate.print();
	std::cout << '\n';

	// External
	std::cout << "Externally accessible\n"
		<< "---------------------\n";

	std::cout << "BASE\n";
	std::cout << "publicVar: PUBLIC (access by all)\n";
	std::cout << "protectedVar: PROTECTED (access by derived)\n";
	std::cout << "privateVar: PRIVATE (inaccessible)\n";
	std::cout << '\n';

	std::cout << "DERIVED_PUBLIC\n";
	std::cout << "publicVar: PUBLIC (access by all)\n";
	std::cout << "protectedVar: PROTECTED (access by derived)\n";
	std::cout << "privateVar: NOT PASSED DOWN\n";
	std::cout << '\n';

	std::cout << "DERIVED_PROTECTED\n";
	std::cout << "publicVar: PROTECTED (access by derived)\n";
	std::cout << "protectedVar: PROTECTED (access by derived)\n";
	std::cout << "privateVar: NOT PASSED DOWN\n";
	std::cout << '\n';

	std::cout << "DERIVED_PRIVATE\n";
	std::cout << "publicVar: PRIVATE (inaccessible)\n";
	std::cout << "protectedVar: PRIVATE (inaccessible)\n";
	std::cout << "privateVar: NOT PASSED DOWN\n";
	std::cout << '\n';

	printFriend(&base);
	std::cout << '\n';

	return 0;
}