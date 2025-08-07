#include <iostream>
#include <deque>
#include <ctime>

void print(std::deque<int>);
void fill(std::deque<int>&, const size_t);
void sort(std::deque<int>&, const size_t, const size_t);
void reverse(std::deque<int>&);
void clear(std::deque<int>&);

int main() {
	std::deque<int> d;

	fill(d, 10);
	std::cout << "Initial deque:\n";
	print(d);
	std::cout << '\n';

	// Assignment 5
	sort(d, 0, d.size() - 1);
	std::cout << "Sorted deque:\n";
	print(d);
	std::cout << '\n';

	// Assignment 6
	reverse(d);
	std::cout << "Reversed deque:\n";
	print(d);
	std::cout << '\n';

	// Assignment 4
	clear(d);
	std::cout << "Cleared deque:\n";
	print(d);
	std::cout << '\n';

	return 0;
}

void print(std::deque<int> d) {
	if (d.empty()) {
		std::cout << "Deque empty.\n";
		return;
	}

	for (int i : d)
		std::cout << i << ' ';
	std::cout << '\n';
}

void fill(std::deque<int>& d, const size_t N) {
	std::srand(std::time({}));

	for (size_t i = 0; i < N; ++i)
		d.push_back(std::rand() % N + 1);
}

// Quicksort algorithm
void sort(std::deque<int>& d, const size_t left, const size_t right) {
	if (left >= right) return;

	const size_t pivot = d[(left + right) / 2];
	int i = left, j = right;

	while (i <= j) {
		while (d[i] < pivot) ++i;
		while (d[j] > pivot) --j;
		if (i <= j) std::swap(d[i++], d[j--]);
	}

	if (left < j) sort(d, left, j);
	if (i < right) sort(d, i, right);
}

void reverse(std::deque<int>& d) {
	std::deque<int> reversed;
	for (int i : d)
		reversed.push_front(i);
	d.swap(reversed);
}

void clear(std::deque<int>& d) {
	std::deque<int> empty;
	d.swap(empty);
}