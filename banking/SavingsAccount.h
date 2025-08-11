#pragma once

#include "Account.h"

#include "Individual.h"
#include "Transaction.h"

class SavingsAccount : public Account {
public:
	static constexpr double MIN_BALANCE = 500.00;
	static constexpr double MAX_BALANCE = 25000.00;

	SavingsAccount(Individual* _client, const double _balance) : Account(_client, _balance) {}

	bool deposit(const double amt) override {
		if (balance + amt <= MAX_BALANCE) {
			make_deposit(amt);
			return true;
		}

		return false;
	}

	bool withdraw(const double amt) override {
		if (balance - amt >= MIN_BALANCE) {
			make_withdraw(amt);
			return true;
		}

		return false;
	}
};