// Author: Richard Denton
// Date: July 17, 2025

#include <iostream>
#include <string>

using namespace std;

bool isPrime(const int);
bool isPalindrome(const int);
int sumOfDigits(int);
int reverse(int);
int getInput();
string trueOrFalse(const bool);

int main() {
    string welcomeMsg;
    welcomeMsg
        .append("1. Get sum of digits in number\n")
        .append("2. Reverse a given number\n")
        .append("3. Determine if number is prime\n")
        .append("4. Determine if number is palindrome\n")
        .append("5. Exit\n");
    
    int choice;
    do {
        cout << welcomeMsg << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        
        int num;
        switch (choice) {
            case 1:
                cout << "SUM OF DIGITS\n";
                num = getInput();
                cout << "Sum: " << sumOfDigits(num) << "\n";
                break;
            case 2:
                cout << "REVERSE NUMBER\n";
                num = getInput();
                cout << "Reverse: " << reverse(num) << "\n";
                break;
            case 3:
                cout << "DETERMINE IF NUMBER IS PRIME\n";
                num = getInput();
                cout << "Is prime: " << trueOrFalse(isPrime(num)) << "\n";
                break;
            case 4:
                cout << "DETERMINE IF NUMBER IS PALINDROME\n";
                num = getInput();
                cout << "Is palindrome: " << trueOrFalse(isPalindrome(num)) << "\n";
                break;
            case 5:
                cout << "Exit program\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n\n";
        }
        cout << endl;
    } while (choice != 5);
    
    return 0;
}

int getInput() {
    cout << "Enter an integer: ";
    int num;
    cin >> num;
    return num;
}

string trueOrFalse(bool b) {
    return b ? "true" : "false";
}

bool isPrime(const int num) {
  const int half(num / 2);
  for (int i(2); i <= half; ++i)
    if (num % i == 0)
        return false;
  return true;
}

bool isPalindrome(const int num) {
  return reverse(num) == num;
}

int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
      sum += num % 10;
      num /= 10;
    }
    return sum;
}

int reverse(int num) {
  int result = 0;
  while (num > 0) {
    int curr = num % 10;
    result = result * 10 + curr;
    num /= 10;
  }
  return result;
}
