#include "dao/MediaDAO.h"

#include "models/Media.h"
#include "models/Book.h"

#include "utility.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <memory>

// PUBLIC
std::shared_ptr<MediaDAO> MediaDAO::get_instance(std::string& _filename) {
	static std::shared_ptr<MediaDAO> instance(new MediaDAO(_filename));
	return instance;
}

void MediaDAO::insert(std::unique_ptr<Media> item) {
	items.push_back(std::move(item));

	// Update data file
	std::ofstream file(filename, std::ios::app);
	if (!file) {
		std::cerr << "Failed to open " << filename << '\n';
		return;
	}

	file << items.back()->print_csv() << '\n';
}
void MediaDAO::update(std::unique_ptr<Media> item) {
	const int id = item->get_id();
	for (auto& i : items) {
		if (i->get_id() == id) {
			i = std::move(item);
			break;
		}
	}

	save_all();
}
void MediaDAO::remove(const int id) {
	for (auto it = items.begin(); it != items.end(); ++it) {
        if ((*it)->get_id() == id) {
            items.erase(it);
			break;
		}
	}

	save_all();
}

std::unique_ptr<Media> MediaDAO::find_by_id(const int id) const {
	for (const auto& item : items)
        if (item->get_id() == id)
            return item->clone();
    return nullptr;
}
std::vector<std::unique_ptr<Media>> MediaDAO::find_by_title(const std::string& title) const {
	std::vector<std::unique_ptr<Media>> copy;

	for (const auto& item : items)
		if (item->get_title() == title)
			copy.push_back(item->clone());
	
	return copy;
}
std::vector<std::unique_ptr<Media>> MediaDAO::find_by_author(const std::string& author) const {
	std::vector<std::unique_ptr<Media>> copy;

	for (const auto& item : items)
		if (item->get_author() == author)
			copy.push_back(item->clone());
	
	return copy;
}
std::vector<std::unique_ptr<Media>> MediaDAO::find_by_type(const std::string& type) const {
	std::vector<std::unique_ptr<Media>> copy;

	for (const auto& item : items)
		if (item->get_type() == type)
			copy.push_back(item->clone());
	
	return copy;
}
std::vector<std::unique_ptr<Media>> MediaDAO::find_all() const {
	std::vector<std::unique_ptr<Media>> copy;
	copy.reserve(items.size());

	for (const auto& item : items)
		copy.push_back(item->clone());
	
	return copy;
}

bool MediaDAO::exists(const int id) const {
	for (const auto& item : items)
        if (item->get_id() == id)
            return true;
    return false;
}

// PRIVATE
MediaDAO::MediaDAO(std::string& _filename) : filename(_filename) { load_all(); }

void MediaDAO::load_all() {
	if (!utils::file_exists(filename)) {
		std::ofstream file(filename);
		file.close();
	}

	std::ifstream file(filename);
	if (!file) {
		std::cerr << "Failed to open " << filename << '\n';
		return;
	}

	std::string line;
	std::string idStr, type, title, author, purchaseDate;
	int id;

	while (std::getline(file, line)) {
		std::stringstream ss(line);

		std::getline(ss, idStr, ',');
		id = std::stoi(idStr);
		std::getline(ss, type, ',');
		std::getline(ss, title, ',');
		std::getline(ss, author, ',');
		std::getline(ss, purchaseDate, ',');

		if (type == "book")
			items.push_back(std::make_unique<Book>(id, type, title, author, purchaseDate, ss));
		// else if (type == "admin")
		// 	items.push_back(std::make_unique<Admin>(id, type, itemname, password, name, ss));
		else
			std::cout << "Could not read invalid item type.\n";
	}

	file.close();
}

void MediaDAO::save_all() {
	std::ofstream file(filename);
	if (!file) {
		std::cerr << "Failed to open " << filename << '\n';
		return;
	}

	for (const auto& item : items)
		file << item->print_csv() << '\n';

	file.close();
}