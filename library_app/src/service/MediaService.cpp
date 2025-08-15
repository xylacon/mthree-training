#include "service/MediaService.h"

#include "models/Media.h"
#include "dao/MediaDAO.h"

#include <string>
#include <iostream>
#include <memory>

MediaService::MediaService(std::string& filename) { dao = MediaDAO::get_instance(filename); }

void MediaService::add(Media& item) {
	dao->insert(item.clone());
}
void MediaService::update(Media& item) {
	if (dao->exists(item.get_id()))
		dao->update(item.clone());
	else
		std::cout << "Update failed. Media not found.\n";
}
void MediaService::remove(const int id) {
	if (dao->exists(id))
		dao->remove(id);
	else
		std::cout << "Deletion failed. Media not found.\n";
}

std::unique_ptr<Media> MediaService::find_by_id(const int id) const {
	return dao->find_by_id(id);
}
std::vector<std::unique_ptr<Media>> MediaService::find_by_title(const std::string& title) const {
	return dao->find_by_title(title);
}
std::vector<std::unique_ptr<Media>> MediaService::find_by_author(const std::string& author) const {
	return dao->find_by_author(author);
}
std::vector<std::unique_ptr<Media>> MediaService::find_by_type(const std::string& type) const {
	return dao->find_by_type(type);
}
std::vector<std::unique_ptr<Media>> MediaService::find_all() const {
	return dao->find_all();
}