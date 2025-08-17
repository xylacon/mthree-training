#pragma once

#include "models/User.h"

#include "dao/UserDAO.h"

#include <vector>
#include <string>
#include <memory>

class UserService {
public:
    UserService(std::string&);

    void add(User&);
    void update(User&);
    void remove(const int);

    std::unique_ptr<User> find_by_id(const int) const;
    std::unique_ptr<User> find_by_login(const std::string&, const std::string&) const;
    std::vector<std::unique_ptr<User>> find_all() const;

private:
    std::shared_ptr<UserDAO> dao;
};