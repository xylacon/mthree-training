// Write a program to accept annual salary
// Calculate HRA 25% of salary
// Calculate MedicalAllowances 20% of salary
// Calculate tax of salary
// After deducting HRA and Medical, tax should be calculated
// 500000  - 1000000 -> 2%
// 1000001 - 1500000 -> 5%
// 1500000 - 2000000 -> 10%
// 2000001 - 2500000 -> 15%
// 2500001 -         -> 20%

#include <iostream>
#include <string>
#include <iomanip>

template<typename T>
T calcHRA(const T amt) {
	return amt * 0.25;
}

template<typename T>
T calcMedAllowance(const T amt) {
	return amt * 0.2;
}

template<typename T>
T calcTax(const T amt) {
	if (amt < 500000)
		return 0.0;
	if (amt >= 500000 && amt <= 1000000)
		return amt * 0.02;
	if (amt >= 1000001 && amt <= 1500000)
		return amt * 0.05;
	if (amt >= 1500000 && amt <= 2000000)
		return amt * 0.1;
	if (amt >= 2000001 && amt <= 2500000)
		return amt * 0.15;
	if (amt >= 2500001)
		return amt * 0.2;
	
	return -1.0;
}

template<typename T>
T calcNetSalary(const T gross, const bool print) {
	const T hra(calcHRA(gross));
	const T med(calcMedAllowance(gross));
	const T tax(calcTax(gross - hra - med));
	const T net(gross - hra - med - tax);

	if (print) {
		std::cout << "\n" << std::fixed << std::setprecision(2);

		auto printLine = [](const std::string& text, const T value) {
			std::cout << std::setw(30) << text << ": "
				<< std::right << std::setw(12) << value << "\n";
		};

		printLine("Gross salary", gross);
		printLine("HRA contribution", hra);
		printLine("Medical Allowance contribution", med);
		printLine("Income tax", tax);
		printLine("Net salary", net);

		std::cout << std::endl;
	}

	return net;
}

int main() {
	std::cout << "Enter your gross salary: ";
	long double gross;
	std::cin >> gross;

	calcNetSalary(gross, true);

	return 0;
}