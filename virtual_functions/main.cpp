#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"

#include <iostream>

void printMenu() {
	std::cout
		<< "1. Rectangle\n"
		<< "2. Triangle\n"
		<< "3. Circle\n";
}

int getChoice() {
	int choice;
	while (true) {
		std::cout << "Choose an option: ";
		std::cin >> choice;
		if (choice >= 1 && choice <= 3)
			break;
		
		std::cout << "Invalid option\n";
	}
	return choice;
}

void runRectangle() {
	std::cout << "Enter length & width: ";
	double length, width;
	std::cin >> length >> width;

	/*
		Assignment 3: Remove display_area()
		Below does not work when display_area() is removed
	*/
	Rectangle rectangle;

	rectangle.get_data(length, width);
	rectangle.display_area();
}

void runTriangle() {
	std::cout << "Enter base & height: ";
	double base, height;
	std::cin >> base >> height;
	Triangle triangle;
	triangle.get_data(base, height);
	triangle.display_area();
}

void runCircle() {
	std::cout << "Enter radius: ";
	double radius;
	std::cin >> radius;
	Circle circle;
	circle.get_data(radius);
	circle.display_area();
}

void run(const int choice) {
	switch (choice) {
		case 1:
			runRectangle();
			break;
		case 2:
			runTriangle();
			break;
		case 3:
			runCircle();
			break;
	}
}

int main() {
	std::cout << "AREA CALCULATOR\n\n";
	printMenu();
	std::cout << '\n';
	const int choice = getChoice();
	std::cout << '\n';
	run(choice);

	return 0;
}