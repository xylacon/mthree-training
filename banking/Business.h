#pragma once

#include "Client.h"

#include <string>

class Business : public Client {
public:
	Business(const std::string& _name, const std::string& _address, const long _phone, const std::string& _email) : Client(_name, _address, _phone, _email) {}
};