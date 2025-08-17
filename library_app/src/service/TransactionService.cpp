#include "service/TransactionService.h"

#include <iostream>

TransactionService::TransactionService(std::string& filename) { dao = TransactionDAO::get_instance(filename); }

void TransactionService::add(Transaction& transaction) {
	dao->insert(transaction.clone());
}
void TransactionService::update(Transaction& transaction) {
	dao->update(transaction.clone());
}
void TransactionService::remove(const int userId, const int mediaId) {
	dao->remove(userId, mediaId);
}

bool TransactionService::exists_media(const int id) const {
	return dao->exists_media(id);
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