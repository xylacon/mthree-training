#pragma once

#include "models/Media.h"

#include <vector>
#include <string>
#include <memory>

// Singleton
class MediaDAO {
public:
	static std::shared_ptr<MediaDAO> get_instance(const std::string&, const std::string&);

	// Prevent copy/assignment
	MediaDAO(const MediaDAO&) = delete;
	MediaDAO& operator=(const MediaDAO&) = delete;

	void insert(std::unique_ptr<Media>);
	void update(std::unique_ptr<Media>);
	void remove(const int);

	std::unique_ptr<Media> find_by_id(const int) const;
	std::vector<std::unique_ptr<Media>> find_all() const;

	bool exists(const int) const;

private:
	std::string inFile; // Read data
	std::string outFile; // Write data
	std::vector<std::unique_ptr<Media>> items;

	MediaDAO(const std::string&, const std::string&);

	void load_all();
	void save_all();
};