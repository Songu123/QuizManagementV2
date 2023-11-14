
cmake_minimum_required(VERSION 3.26)
project(QuizManagementV2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
add_executable(QuizManagementV2 main.cpp
        Database.cpp
        MenuAdmin.cpp
        MenuUser.cpp
        TestManagement.cpp
        UserManagement.cpp
        ResultManagement.cpp
        Database.h
        CurrentUser.cpp
        CurrentUser.h
        CurrentUser.h
        MenuUser.h
        TestManagement.h
        MenuUpdateQuiz.h
        MenuUpdateQuiz.cpp
        MenuUpdateQuestion.cpp
        UserManagement.h
)
include_directories(/usr/local/include/mysql++)
include_directories(/usr/local/include/mysql)

# Link the required libraries
find_library(MYSQLPP_LIBRARY mysqlpp)
find_library(MYSQLCLIENT_LIBRARY mysqlclient)
target_link_libraries(QuizManagementV2 ${MYSQLPP_LIBRARY} ${MYSQLCLIENT_LIBRARY})
