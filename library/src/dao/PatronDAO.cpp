#include "dao/PatronDAO.h"
#include "models/Patron.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <memory>

std::shared_ptr<PatronDAO> PatronDAO::get_instance() {
	static std::shared_ptr<PatronDAO> instance(new PatronDAO());
	return instance;
}

std::vector<std::shared_ptr<Patron>> PatronDAO::load_all(const std::string& filename) const {
	std::vector<std::shared_ptr<Patron>> patrons;
	std::ifstream file(filename);
	if (!file) {
		std::cerr << "Failed to open " << filename << '\n';
		return patrons;
	}

	std::string line;
	std::getline(file, line); // Skip header line

	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string idStr, name;

		std::getline(ss, idStr, ',');
		const int id = std::stoi(idStr);
		std::getline(ss, name);

		auto patron = std::make_shared<Patron>(id, name);
		patrons.push_back(std::move(patron));
	}

	return patrons;
}

void PatronDAO::save_all(const std::string& filename, std::vector<std::shared_ptr<Patron>> patrons) const {
	std::ofstream file(filename);
	if (!file) {
		std::cerr << "Failed to open " << filename << '\n';
		return;
	}

	file << "id,name\n"; // CSV header

	for (const auto& patron : patrons) {
		file << patron->get_id() << ',' << patron->get_name() << '\n';
	}
}