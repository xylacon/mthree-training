#ifndef BASE_H
#define BASE_H

#include <string>
#include <iostream>

/*
	publicVar is PUBLIC (access by all)
	protectedVar is PROTECTED (access by derived)
	privateVar is PRIVATE (no access)
*/

class Base {
public:
	std::string publicVar;

	Base() : publicVar("Base"), protectedVar("Base"), privateVar("Base") {}
	Base(const std::string _publicVar, const std::string _protectedVar, const std::string _privateVar)
		: publicVar(_publicVar), protectedVar(_protectedVar), privateVar(_privateVar) {}

	virtual void print() {
		std::cout << "BASE\n"
			<< "publicVar: " << publicVar << '\n'
			<< "protectedVar: " << protectedVar << '\n'
			<< "privateVar: " << privateVar << '\n';
	}

protected:
	std::string protectedVar;

private:
	std::string privateVar;
};

#endif