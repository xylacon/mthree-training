#include "Student.h"

#include <iostream>
#include <string>

int getSize();
void collectStudents(Student**, const int);
void printStudents(Student**, const int);
void deleteStudents(Student**, const int);

int main() {
	const int N = getSize();

	Student** students = new Student*[N]{};
	collectStudents(students, N);
	printStudents(students, N);
	deleteStudents(students, N);

	return 0;
}

int getSize() {
	std::cout << "Enter number of students: ";
	int size;
	std::cin >> size;
	std::cout << '\n';

	return size;
}

void collectStudents(Student** students, const int N) {
	std::string name, special;
	int grade;
	for (int i = 0; i < N; ++i) {
		std::cin.ignore();
		std::cout << "Student " << i+1 << '\n';
		std::cout << "Enter name: ";
		getline(std::cin, name);
		std::cout << "Enter specialization: ";
		getline(std::cin, special);
		std::cout << "Enter grade: ";
		std::cin >> grade;
		std::cout << '\n';

		students[i] = new Student(name, special, grade);
	}
}

void printStudents(Student** students, const int N) {
	std::cout
		<< "STUDENT LIST\n"
		<< "------------\n";
	for (int i = 0; i < N; ++i) {
		students[i]->print();
		std::cout << '\n';
	}
}

void deleteStudents(Student** students, const int N) {
	for (int i = 0; i < N; ++i)
		delete students[i];
	delete[] students;
}