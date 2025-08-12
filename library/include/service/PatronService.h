#pragma once

#include "models/Patron.h"
#include "dao/PatronDAO.h"

#include <vector>
#include <string>
#include <memory>

class PatronService {
public:
	PatronService(const std::string&);

    void save_patrons(const std::string&) const;

    void add_patron(const Patron);
    std::shared_ptr<Patron> find_patron_by_id(const int) const;

private:
    std::shared_ptr<PatronDAO> dao;
    std::vector<std::shared_ptr<Patron>> patrons;
};