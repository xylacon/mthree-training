// It's a catch within a catch :O

#include <iostream>

int main() {
	std::cin.exceptions(std::ios::failbit);

	std::cout << "Enter an integer: ";
	int val;
	try {
		std::cin >> val;
		std::cout << "\nYou entered: " << val << '\n';
	} catch(const std::ios_base::failure& e) {
		std::cerr << "\nYou did not enter an integer >:(\n"
			<< "You have one chance left...\n"
			<< "Enter an I.N.T.E.G.E.R. (1, 2, 3, etc): ";
		
		std::cin.clear();
    	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		
		try {
			std::cin >> val;
			std::cout << "\nYou entered: " << val << '\n'
				<< "Thank you for complying this time.\n";
		} catch(const std::ios_base::failure& e) {
			std::cerr << "\nWow, I can't believe you disobeyed.\n"
			<< "You've lost the privilege to continue.\n";
		}
	}

	return 0;
}