#pragma once

#include "Book.h"
#include "Patron.h"
#include "Transaction.h"

#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

class Library {
public:
	struct Stock {
		int total;
		int current;
	};

	static Library& get_library() {
		static Library instance;
		return instance;
	}

	Library(const Library&) = delete;
	Library& operator=(const Library&) = delete;

	// Add book
	// Update book
	// Get all books
	// Get book by id
	// Get books by name
	// Get books by author
	// Get books by genre

	// Add patron
	// Update patron
	// Get all patrons
	// Get patron by id

	// Add inventory
	// Update inventory
	// 

	// Add transaction
	// Update transaction

private:
	std::string name;
	std::vector<std::unique_ptr<Book>> books;
	std::vector<std::unique_ptr<Patron>> patrons;
	std::unordered_map<int, Stock> inventory;
	std::vector<std::unique_ptr<Transaction>> transactions;

	Library() {}
};