#ifndef MENUUSER_H
#define MENUUSER_H

#include <iostream>
#include <map>
#include <string>

class MenuUser {
public:
    MenuUser();
    void display();
    void run();

private:
    std::map<std::string, std::string> options;
};

#endif // MENUUSER_H
