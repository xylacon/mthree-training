#pragma once

#include "Account.h"

#include "Business.h"
#include "Transaction.h"

class CurrentAccount : public Account {
public:
	static constexpr double MIN_BALANCE = 1000.00;
	static constexpr double MAX_BALANCE = 50000.00;

	CurrentAccount(Business* _client, const double _balance) : Account(_client, _balance) {}

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