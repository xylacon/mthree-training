#pragma once

#include "models/Transaction.h"
#include "dao/TransactionDAO.h"

#include <vector>
#include <string>
#include <memory>

class TransactionService {
public:
    TransactionService(std::string&);

    bool add(Transaction&);
    bool update(Transaction&);
    bool remove(const int, const int);

    std::unique_ptr<Transaction> find(const int, const int) const;
    std::vector<std::unique_ptr<Transaction>> find_by_user_id(const int) const;
	std::vector<std::unique_ptr<Transaction>> find_by_media_id(const int) const;
    std::vector<std::unique_ptr<Transaction>> find_all() const;

    bool exists_book(const int id) const;

private:
    std::shared_ptr<TransactionDAO> dao;
};