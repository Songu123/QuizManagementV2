//
// Created by MacBook on 14/11/2023.
//

#ifndef QUIZMANAGEMENT_MENUUPDATEQUESTION_H
#define QUIZMANAGEMENT_MENUUPDATEQUESTION_H
#include <iostream>
#include <string>
#include <mysql++.h>
#include <mysql.h>
#include "Database.h"
#include "CurrentUser.h"

class MenuUpdateQuestion {
public:
    void updateAnswer(int question_id);
    void menuMenuAnswer(int question_id);
    void updateQuestion(int question_id);
};


#endif //QUIZMANAGEMENT_MENUUPDATEQUESTION_H
