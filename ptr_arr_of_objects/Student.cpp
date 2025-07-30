#include "Student.h"

#include <iostream>
#include <string>

int Student::baseId = 100000;

// Constructors
Student::Student() : id(generateId()), name("none"), special("none"), grade(0) {}

Student::Student(std::string _name, std::string _special) : id(generateId()), name(_name), special(_special), grade(0) {}

Student::Student(std::string _name, std::string _special, const int _grade) : id(generateId()), name(_name), special(_special), grade(_grade) {}

// Setters
void Student::setName(std::string _name) { name = std::move(_name); }
void Student::setSpecial(std::string _special) { special = std::move(_special); }
void Student::setGrade(const int _grade) { grade = _grade; }

// Getters
int Student::getId() const { return id; }
std::string Student::getName() const { return name; }
std::string Student::getSpecial() const { return special; }
int Student::getGrade() const { return grade; }

// Utilities
void Student::print() const {
	std::cout
		<< "ID: " << id << '\n'
		<< "Name: " << name << '\n'
		<< "Special: " << special << '\n'
		<< "Grade: " << grade << '\n';
}

int Student::generateId() {
	return ++Student::baseId;
}