#include "service/PatronService.h"

#include "models/Patron.h"
#include "dao/PatronDAO.h"

#include <string>
#include <memory>

PatronService::PatronService(const std::string& filename) {
	dao = PatronDAO::get_instance();
	patrons = dao->load_all(filename);
}

void PatronService::save_patrons(const std::string& filename) const {
	dao->save_all(filename, patrons);
}

void PatronService::add_patron(Patron patron) {
	patrons.push_back(std::make_shared<Patron>(patron));
}
std::shared_ptr<Patron> PatronService::find_patron_by_id(const int id) const {
	for (const auto& patron : patrons) {
        if (patron->get_id() == id)
            return patron;
    }
    return nullptr;
}