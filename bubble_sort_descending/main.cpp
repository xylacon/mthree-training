#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

template <typename T>
void swap(std::vector<T>& arr, const size_t idx1, const size_t idx2) {
	const T temp( arr[idx1] );
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

template <typename T>
size_t sort(std::vector<T>& arr) {
	// Bubble sort algorithm - descending

	const size_t N = arr.size();
	bool swapped;
	size_t swaps = 0;

	for (size_t i = 0; i < N-1; ++i) {
		swapped = false;
		for (size_t j = 0; j < N-1-i; ++j) {
			if (arr[j] < arr[j+1]) {
				swap(arr, j, j+1);
				swapped = true;
				++swaps;
			}
		}
		if (!swapped) break;
	}

	return swaps;
}

template <typename T>
void display(const std::vector<T>& arr) {
	for (const T& element : arr)
		std::cout << element << ' ';
	std::cout << '\n';
}

std::vector<int> create_arr(const size_t size, const int lower_bound, const int upper_bound) {
	std::vector<int> arr(size);
	for (size_t i = 0; i < size; ++i)
		arr[i] = rand() % upper_bound + lower_bound;
	
	return arr;
}

void run(const size_t size, const int lower_bound = 0, const int upper_bound = 10) {
	std::vector<int> arr = create_arr(size, lower_bound, upper_bound);
	std::cout << "Unsorted: ";
	display(arr);

	const size_t swaps = sort(arr);

	std::cout << "Unsorted: ";
	display(arr);
	std::cout << "Number of swaps: " << swaps << "\n\n";
}

int main() {
	srand(time(0));

	run(10);
	run(10);
	run(10);
	run(10);
	run(10);

	// run(15, 0, 50);
	// run(500, 0, 100);

	return 0;
}