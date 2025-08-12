#pragma once

#include "Client.h"
#include "Transaction.h"

#include <string>
#include <vector>

class Account {
public:
	Account(Client*, const double);

	virtual bool deposit(const double) = 0;
	virtual bool withdraw(const double) = 0;

	int get_id() const;
	double get_balance() const;
	Client* get_client() const;

	void display() const;
	void display_transactions() const;

protected:
	int id;
	std::string dateCreated;
	double balance;
	Client* client;
	std::vector<Transaction*> transactions;

	void make_deposit(const double);
	void make_withdraw(const double);

private:
	static int counter;

	void add_transaction(Transaction*);

	int generate_id();
	std::string generate_date();
};