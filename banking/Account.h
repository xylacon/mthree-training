#pragma once

#include "Client.h"
#include "Transaction.h"

#include <string>
#include <vector>

class Account {
public:
	Account(Client* _client, const double _balance) : id(generate_id()), dateCreated(generate_date()), balance(_balance), client(_client) {}

	void add_transaction(Transaction* transaction) {
		transactions.push_back(transaction);
	}

	void display() const;
	void display_transactions() const;

protected:
	int id;
	std::string dateCreated;
	double balance;
	Client* client;
	std::vector<Transaction*> transactions;

private:
	static int counter;

	int generate_id();
	std::string generate_date();
};