#pragma once

#include "Account.h"

#include "Individual.h"

class SavingsAccount : public Account {
	SavingsAccount(Individual* _client, const double _balance) : Account(_client, _balance) {}
};