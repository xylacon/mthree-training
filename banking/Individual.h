#pragma once

#include "Client.h"

#include <string>

class Individual : public Client {
public:
	Individual(const std::string& _name, const std::string& _address, const long _phone, const std::string& _email) : Client(_name, _address, _phone, _email) {}
};