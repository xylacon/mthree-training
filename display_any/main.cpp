#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <deque>

// These iterate differently
#include <stack>
#include <queue>
#include <map>

template <typename Container>
void display(const Container& container, const std::string& label) {
	std::cout << label << ": ";
	for (const auto& value : container)
		std::cout << value << ' ';
	std::cout << '\n';
}

template <typename T>
void display(std::stack<T> s) {
	std::cout << "stack: ";
	while (!s.empty()) {
		std::cout << s.top() << ' ';
		s.pop();
	}
	std::cout << '\n';
}

template <typename T>
void display(std::queue<T> q) {
	std::cout << "queue: ";
	while (!q.empty()) {
		std::cout << q.front() << ' ';
		q.pop();
	}
	std::cout << '\n';
}

template <typename T, typename U>
void display(const std::map<T, U>& q) {
	std::cout << "map: ";
	for (const auto& pair : q)
		std::cout << '(' << pair.first << ',' << pair.second << ") ";
	std::cout << '\n';
}

// template <typename Container, typename T>
// void create(Container& container, T init, const size_t N) {
// 	for (size_t i = 0; i < N; ++i)
// 		container.emplace_back(init++);
// }

template <typename T>
void create(std::stack<T>& s, T init, const size_t N) {
	for (size_t i = 0; i < N; ++i)
		s.emplace(init++);
}

template <typename T>
void create(std::queue<T>& q, T init, const size_t N) {
	for (size_t i = 0; i < N; ++i)
		q.emplace(init++);
}

template <typename T, typename U>
void create(std::map<T, U>& m, T init1, U init2, const size_t N) {
	for (size_t i = 0; i < N; ++i)
		m.emplace(init1++, init2++);
}

int main() {
	std::vector<int> v = {1, 2, 3, 4, 5};
	std::list<double> l = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::set<char> se = {'a', 'b', 'c', 'd', 'e'};
	std::deque<std::string> d = {"One", "Two", "Three", "Four", "Five"};

	display(v, "vector");
	display(l, "list");
	display(se, "set");
	display(d, "deque");

	std::stack<char> st;
	create(st, 'a', 5);
	display(st);

	std::queue<float> q;
	create(q, 1.0f, 5);
	display(q);

	std::map<int, char> m;
	create(m, 1, 'm', 5);
	display(m);

	return 0;
}