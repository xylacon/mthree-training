#pragma once

#include "models/Patron.h"

#include <vector>
#include <string>
#include <memory>

class PatronDAO {
public:
	static std::shared_ptr<PatronDAO> get_instance();

	PatronDAO(const PatronDAO&) = delete;
	PatronDAO& operator=(const PatronDAO&) = delete;

	std::vector<std::shared_ptr<Patron>> load_all(const std::string&) const;
	void save_all(const std::string&, std::vector<std::shared_ptr<Patron>>) const;

private:
	PatronDAO() {}
};