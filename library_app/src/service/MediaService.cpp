#include "service/MediaService.h"

#include "models/Media.h"
#include "dao/MediaDAO.h"

#include <string>
#include <iostream>
#include <memory>

MediaService::MediaService(const std::string& inFile) {
	dao = MediaDAO::get_instance(inFile, inFile);
}
MediaService::MediaService(const std::string& inFile, const std::string& outFile) {
	dao = MediaDAO::get_instance(inFile, outFile);
}

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
std::vector<std::unique_ptr<Media>> MediaService::find_all() const {
	return dao->find_all();
}