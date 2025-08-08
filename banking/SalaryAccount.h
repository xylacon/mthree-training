#pragma once

#include "Account.h"

#include "Employee.h"

class SalaryAccount : public Account {
	SalaryAccount(Employee* _client, const double _balance) : Account(_client, _balance) {}
};