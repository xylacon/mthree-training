#include <iostream>
#include <stack>

void print(std::stack<int>);
void fill(std::stack<int>&, const size_t);
void reverse(std::stack<int>&);
void clear(std::stack<int>&);

int main() {
	std::stack<int> s;

	fill(s, 5);
	std::cout << "Initial stack:\n";
	print(s);
	std::cout << '\n';

	// Assignment 1
	reverse(s);
	std::cout << "Reversed stack:\n";
	print(s);
	std::cout << '\n';

	// Assignment 2
	clear(s);
	std::cout << "Cleared stack:\n";
	print(s);
	std::cout << '\n';

	return 0;
}

void print(std::stack<int> s) {
	if (s.empty()) {
		std::cout << "Stack empty.\n";
		return;
	}

	while (!s.empty()) {
		std::cout << s.top() << ' ';
		s.pop();
	}
	std::cout << '\n';
}

void fill(std::stack<int>& s, const size_t N) {
	for (size_t i = N; i > 0; --i)
		s.push(i);
}

void reverse(std::stack<int>& s) {
	std::stack<int> reversed;
	while (!s.empty()) {
		reversed.push(s.top());
		s.pop();
	}
	s.swap(reversed);
}

void clear(std::stack<int>& s) {
	std::stack<int> empty;
	s.swap(empty);
}