//
// Created by MacBook on 14/11/2023.
//

#include "MenuUpdateQuestion.h"

using namespace std;
using namespace mysqlpp;

//HÀM CẬP NHẬT CÂU HỎI BỔ SUNG
void MenuUpdateQuestion::updateQuestion(int question_id) {
    Database::connectToDatabase();
    string content;
    int point;
    bool ok = true;
    try {
        cout << "Nhập nội dung câu hỏi: ";
        getline(cin, content);
        while (ok) {
            cout << "Nhập điểm của câu: ";
            cin >> point;
            if (cin.fail() || point <= 0) {
                cout << "Nhập sai!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                ok = false;
            }
        }
        Query q = Database::con.query(
                "UPDATE questions SET content = '" + content + "', point = " + to_string(point) + " WHERE id = " +
                to_string(question_id) + ";");
        q.execute();
        MenuUpdateQuestion::menuMenuAnswer(question_id);
    } catch (Exception &e) {
        cerr << "Lỗi MySQL: " << e.what() << endl;
    }
}

//MENU CẬP NHÂT ĐÁP ÁN
void MenuUpdateQuestion::menuMenuAnswer(int question_id) {
    while (true) {
        cout << "SỬA ĐÁP ÁN" << endl;
        cout << "1. Sửa đáp án" << endl;
        cout << "0. Quay lại" << endl;
        cout << "Chọn: ";
        int choose;
        cin >> choose;
        cin.ignore();
        if (cin.fail()) {
            cout << "Nhập sai! Vui lòng nhập lại." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            switch (choose) {
                case 1:
                    MenuUpdateQuestion::updateAnswer(question_id);
                    break;
                case 0:
                    return;
                default:
                    cout << "Nhập sai! Vui lòng nhập lại." << endl;
            }
        }
    }
}

//HÀM CẬP NHẬT ĐÁP ÁN
void MenuUpdateQuestion::updateAnswer(int question_id) {
    Database::connectToDatabase();
    string content;
    bool success, ok = true;
    int answer_id;
    try {
        Query query = Database::con.query(
                "SELECT id, questions_id, content, is FROM answers WHERE questions_id = " + to_string(question_id) +
                ";");
        StoreQueryResult sq = query.store();
        if (sq) {
            cout << "DANH SÁCH CÁC ĐÁP ÁN" << endl;
            for (size_t i = 0; i < sq.size(); i++) {
                Row row = sq[i];
                cout << "ID: " << row[0] << ", ID question: " << row[1] << ", Content: " << row[2] << ", Is True: "
                     << row[3] << endl;
            }
            cout << "Nhập id: ";
            cin >> answer_id;
            cin.ignore();
            cout << "Nhập nội dung: ";
            getline(cin, content);
            while (ok) {
                cout << "Nhập (1)Đúng, (0)Sai: ";
                int choose;
                cin >> choose;
                cin.ignore();
                if (cin.fail()) {
                    cout << "Nhập sai! Vui lòng nhập lại." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    switch (choose) {
                        case 1:
                            success = true;
                            ok = false;
                            break;
                        case 0:
                            success = false;
                            ok = false;
                            break;
                        default:
                            cout << "Nhập sai! Vui lòng nhập lại." << endl;
                    }
                }
                Query q = Database::con.query(
                        "UPDATE answers SET content = '" + content + "', is_true = " + to_string(success) + ";");
                q.execute();
            }
        } else {
            cout << "Không có dữ liệu!" << endl;
        }

    } catch (Exception &e) {
        cerr << "Lỗi MySQL: " << e.what() << endl;
    }
}