#pragma once

#include "models/Media.h"

#include "dao/MediaDAO.h"

#include <vector>
#include <string>
#include <memory>

class MediaService {
public:
    MediaService(std::string&);

    void add(Media&);
    void update(Media&);
    void remove(const int);

    bool exists(const int id) const;

    int get_size() const;

    std::unique_ptr<Media> find_by_id(const int) const;
    std::vector<std::unique_ptr<Media>> find_by_title(const std::string&) const;
    std::vector<std::unique_ptr<Media>> find_by_author(const std::string&) const;
    std::vector<std::unique_ptr<Media>> find_by_type(const std::string&) const;
    std::vector<std::unique_ptr<Media>> find_all() const;

private:
    std::shared_ptr<MediaDAO> dao;
};