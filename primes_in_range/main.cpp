// Author: Richard Denton
// Date: July 17, 2025

#include <iostream>
using namespace std;

bool isPrime(const int num) {
  const int half(num / 2);
  for (int i(2); i <= half; ++i)
    if (num % i == 0)
        return false;
  return true;
}

void findPrimes(const int first, const int last) {
    cout << "Primes: ";
    for (int i(first); i <= last; ++i) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    cout << "PRIMES IN RANGE\n";
    cout << "Enter the start and end integers: ";
    int first, last;
    do {
        cin >> first >> last;
        if (first < 2) cout << "Minimum is 2\n";
        if (last <= first) cout << "End must be > start\n";
    } while (first < 2 || last <= first);
    
    findPrimes(first, last);

    return 0;
}
