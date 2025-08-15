#include "service/TransactionService.h"

#include "models/Transaction.h"
#include "dao/TransactionDAO.h"

#include <string>
#include <iostream>
#include <memory>

TransactionService::TransactionService(std::string& filename) { dao = TransactionDAO::get_instance(filename); }

bool TransactionService::add(Transaction& transaction) {
	if (!dao->exists(transaction.get_user_id(), transaction.get_media_id())) {
		dao->insert(transaction.clone());
		return true;
	}
	
	return false;
}
bool TransactionService::update(Transaction& transaction) {
	if (dao->exists(transaction.get_user_id(), transaction.get_media_id())) {
		dao->update(transaction.clone());
		return true;
	}
		
	return false;
}
bool TransactionService::remove(const int userId, const int mediaId) {
	if (dao->exists(userId, mediaId)) {
		dao->remove(userId, mediaId);
		return true;
	}
		
	return false;
}

std::unique_ptr<Transaction> TransactionService::find(const int userId, const int mediaId) const {
	return dao->find(userId, mediaId);
}
std::vector<std::unique_ptr<Transaction>> TransactionService::find_by_user_id(const int id) const {
	return dao->find_by_user_id(id);
}
std::vector<std::unique_ptr<Transaction>> TransactionService::find_by_media_id(const int id) const {
	return dao->find_by_media_id(id);
}
std::vector<std::unique_ptr<Transaction>> TransactionService::find_all() const {
	return dao->find_all();
}

bool TransactionService::exists_book(const int id) const {
	return dao->exists_book(id);
}