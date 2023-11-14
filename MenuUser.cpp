#include "MenuUser.h"

MenuUser::MenuUser() {
    options = {
            {"1", "Đăng kí thi"},
            {"2", "Đăng nhập"},
            {"0", "Thoát"}
    };
}

void MenuUser::display() {
    std::cout << "MENU USER" << std::endl;
    for (auto option: options) {
        std::cout << option.first << ". " << option.second << std::endl;
    }
}

void MenuUser::run() {
    int choice;
    while (true) {
        display();
        std::cout << "Nhập lựa chọn của bạn" << std::endl;
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << "Bạn đã chọn đăng kí thi" << std::endl;
                break;
            case 2:
                std::cout << "Bạn đã chọn đăng nhập" << std::endl;
                break;
            case 0:
                std::cout << "Bạn đã chọn thoát!" << std::endl;
                return;
            default:
                std::cout << "Bạn đã chọn sai! Vui lòng nhập lại!" << std::endl;
        }
    }
}
