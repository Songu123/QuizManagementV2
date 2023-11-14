//
// Created by MacBook on 08/11/2023.
//


#include "UserManagement.h"

using namespace std;
using namespace mysqlpp;

//    HÀM MENU QUẢN LÝ NGƯỜI DÙNG
void UserManagement::run() {
    while (true) {
        cout << "QUẢN LÝ NGƯỜI DÙNG" << endl;
        cout << "1. Danh sách người dùng" << endl;
        cout << "2. Tạo người dùng mới" << endl;
        cout << "3. Cập nhật người dùng" << endl;
        cout << "4. Quản lý kết quả người dùng" << endl;
        cout << "0. Quay lại trang Admin" << endl;
        cout << "Chọn số: ";
        int choose;
        cin >> choose;
        switch (choose) {
            case 1:
                cout << "DANH SÁCH NGƯỜI DÙNG" << endl;
                UserManagement::listUsers();
                break;
            case 2:
                cout << "TẠO NGƯỜI DÙNG MỚI" << endl;
                UserManagement::createUser();
                break;
            case 3:
                cout << "CHỈNH SỬA NGƯỜI DÙNG" << endl;
                int id;
                cout << "Nhập id người dùng: ";
                cin >> id;
                UserManagement::updateUser(id);
                break;
            case 4:
                cout << "QUẢN LÝ KẾT QUẢ NGƯỜI DÙNG" << endl;
                break;
            case 0:
                return;
            default:
                cout << "Chọn sai! Vui lòng chọn lại" << endl;
                break;
        }
    }
}

// HÀM DANH SÁCH NGƯỜI DÙNG
void UserManagement::listUsers() {
    try {
        Database::connectToDatabase();
        Query q = Database::con.query(
                "SELECT id, username, date_of_birth, CAST(sex AS INT) AS sex, email, password FROM users where role = 'user'");
        StoreQueryResult sq = q.store();
        if (sq) {
            cout << "DANH SÁCH NGƯỜI DÙNG" << endl;
            for (size_t i = 0; i < sq.size(); ++i) {
                Row row = sq[i];
                cout << "\tID: " << row[0] << ", \t\tUsername: " << row[1]
                     << ", \t\tBirthdate: " << row[2] << ", \t\tGender: " << row[3]
                     << ", \t\tEmail: " << row[4] << ", \t\tPassword: " << row[5] << endl;
            }
        } else {
            cout << "Không có dữ liệu người dùng." << endl;
        }
    } catch (const Exception &e) {
        cerr << "Lỗi MySQL: " << e.what() << endl;
    }
}

//HÀM TẠO NGƯỜI DÙNG MỚI
void UserManagement::createUser() {
    string username, password, email, birthdate;
    int gender;
    cin.ignore();
    cout << "Nhập username: ";
    getline(cin, username);

    cout << "Nhập password: ";
    getline(cin, password);

    cout << "Nhập email: ";
    getline(cin, email);

    cout << "Nhập birthdate: ";
    getline(cin, birthdate);

    bool ok = true;
    int choose;
    while (ok) {
        cout << "Nhập gender (1)Nam, (2)Nữ: ";
        cin >> choose;
        cin.ignore();
        if (cin.fail()) {
            cout << "Nhập sai! Vui lòng nhập lại." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            switch (choose) {
                case 1:
                    gender = 1;
                    ok = false;
                    break;
                case 2:
                    gender = 0;
                    ok = false;
                    break;
                default:
                    cout << "Nhập sai! Vui lòng nhập lại." << endl;
                    break;
            }
        }
    }
    try {
        Database::connectToDatabase();
        Query query = Database::con.query("INSERT INTO users(username, date_of_birth, sex, email, password) VALUES"
                                          "('" + username + "', '" + birthdate + "', " + to_string(gender) + ", '" +
                                          email + "', '" + password + "');");
        query.execute();
    } catch (const Exception &e) {
        cout << "Lỗi MySQL: " << e.what() << endl;
    }
}

//    HÀM CẬP NHẬT NGƯỜI DÙNG
void UserManagement::updateUser(int id) {
    string username, password, email, birthdate;
    int gender;
    cin.ignore();
    cout << "Nhập username: ";
    getline(cin, username);

    cout << "Nhập password: ";
    getline(cin, password);

    cout << "Nhập email: ";
    getline(cin, email);

    cout << "Nhập birthdate: ";
    getline(cin, birthdate);

    bool ok = true;
    int choose;
    while (ok) {
        cout << "Nhập gender (1)Nam, (2)Nữ: ";
        cin >> choose;
        cin.ignore();
        if (cin.fail()) {
            cout << "Nhập sai! Vui lòng nhập lại." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            switch (choose) {
                case 1:
                    gender = 1;
                    ok = false;
                    break;
                case 2:
                    gender = 0;
                    ok = false;
                    break;
                default:
                    cout << "Nhập sai! Vui lòng nhập lại." << endl;
                    break;
            }
        }
    }
    try {
        Database::connectToDatabase();
        Query query = Database::con.query(
                "UPDATE users SET username = '" + username + "', date_of_birth = '" + birthdate + "', sex = " +
                to_string(gender) + ", email = '" + email + "', password = '" + password + "' WHERE id = " +
                to_string(id) + ";");
        query.execute();
    } catch (const Exception &e) {
        cout << "Lỗi MySQL: " << e.what() << endl;
    }
}







