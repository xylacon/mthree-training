#include "service/MediaService.h"

MediaService::MediaService(std::string& filename) { dao = MediaDAO::get_instance(filename); }

void MediaService::add(Media& item) {
	dao->insert(item.clone());
}
void MediaService::update(Media& item) {
	dao->update(item.clone());
}
void MediaService::remove(const int id) {
	dao->remove(id);
}

bool MediaService::exists(const int id) const {
	return dao->exists(id);
}

int MediaService::get_size() const {
	return dao->get_size();
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