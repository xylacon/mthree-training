#pragma once

#include "Book.h"
#include "Patron.h"
#include "Transaction.h"

#include <string>
#include <unordered_map>
#include <vector>

class Library {
public:
	struct Stock {
		int total;
		int current;
	};

private:
	std::string name;
	std::unordered_map<int, Stock> inventory;
	std::vector<Patron*> patrons;
	std::vector<Transaction*> transactions;
	std::vector<Transaction*> loans;

	Library();
};