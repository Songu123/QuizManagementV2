//
// Created by MacBook on 15/11/2023.
//

#ifndef QUIZMANAGEMENTCOPY_USERMANAGEMENT_H
#define QUIZMANAGEMENTCOPY_USERMANAGEMENT_H

#include <iostream>
#include <string>
#include "Database.h"
#include <mysql++.h>
class UserManagement {
public:
    void listUsers();
    void createUser();
    void updateUser(int id);
    void run();
};
#endif //QUIZMANAGEMENTCOPY_USERMANAGEMENT_H
