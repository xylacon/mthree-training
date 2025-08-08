#pragma once

#include "Account.h"

#include "Business.h"

class CurrentAccount : public Account {
public:
	CurrentAccount(Business* _client, const double _balance) : Account(_client, _balance) {}
};