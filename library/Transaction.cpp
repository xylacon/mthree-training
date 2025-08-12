#include "Transaction.h"

#include <string>

Transaction::Transaction(const int _patronId, const int _bookId, std::string _loanDate, std::string _dueDate) : patronId(_patronId), bookId(_bookId), loanDate(_loanDate), dueDate(_dueDate) {}

int Transaction::get_patron_id() const { return patronId; }
int Transaction::get_book_id() const { return bookId; }
const std::string& Transaction::get_loan_date() const { return loanDate; }
const std::string& Transaction::get_due_date() const { return dueDate; }