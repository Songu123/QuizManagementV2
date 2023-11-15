#include "MenuUser.h"
using namespace std;

void MenuUser::menuUser(int n) {
    int choice;
    while (true) {
        cout << "MENU NGƯỜI DÙNG" << endl;
        cout << "1. Đăng ký thi" << endl;
        cout << "2. Đăng nhập" << endl;
        cout << "0. Thoát" << endl;
        cout << "Nhập lựa chọn của bạn" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Bạn đã chọn đăng kí thi" << endl;
                break;
            case 2:
                cout << "Bạn đã chọn đăng nhập" << endl;
                break;
            case 0:
                cout << "Bạn đã chọn thoát!" << endl;
                return;
            default:
                cout << "Bạn đã chọn sai! Vui lòng nhập lại!" << endl;
        }
    }
}
