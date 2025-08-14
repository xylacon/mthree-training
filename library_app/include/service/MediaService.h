#pragma once

#include "models/Media.h"
#include "dao/MediaDAO.h"

#include <vector>
#include <string>
#include <memory>

class MediaService {
public:
    MediaService(const std::string&);
	MediaService(const std::string&, const std::string&);

    void add(Media&);
    void update(Media&);
    void remove(const int);

    std::unique_ptr<Media> find_by_id(const int) const;
    std::vector<std::unique_ptr<Media>> find_all() const;

private:
    std::shared_ptr<MediaDAO> dao;
};