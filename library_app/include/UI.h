#pragma once

#include "models/Media.h"
#include "models/Transaction.h"

#include <vector>
#include <memory>

class UI {
public:
	int get_choice(const int, const int) const;
	void print_media(std::vector<std::unique_ptr<Media>>&);
	void print_transactions(std::vector<std::unique_ptr<Transaction>>&);
};