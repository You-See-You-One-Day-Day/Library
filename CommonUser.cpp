//
// Created by 伍淇铨 on 2020/12/29.
//

#include "CommonUser.h"
#include "Book.h"

using namespace std;

CommonUser::CommonUser(int) {
    char judge;
    cout << "您正在创建普通用户\n";

    cout << "请输入用户名： \n";
    start:
    cin >> m_username;

    FILE *fp = fopen("CommonUser.bin", "rb");
    if (fp != nullptr) {
        auto ap = new CommonUser;
        bool exist = false;
        while (true) {
            if (!fread(ap, sizeof(CommonUser), 1, fp)) {
                delete ap;
                break;
            }
            if (ap->getUsername() == m_username) {
                exist = true;
                delete ap;
                break;
            }
        }
        if (exist) {
            cout << "用户名已存在，请重新输入：\n";
            goto start;
        }
    }
    fclose(fp);
    cout << "是否使用默认密码123456？（Y/N）  ";
    cin >> judge;
    if (judge != 'Y') {
        string initialPassword, confirmPassword;
        input:
        cout << "请输入密码：\n";
        cin >> initialPassword;

        cout << "请确认密码：\n";
        cin >> confirmPassword;

        if (initialPassword != confirmPassword) {
            cout << "前后密码输入不一致，请重新输入\n";
            goto input;
        } else {
            m_password = initialPassword;
        }

    } else {
        cout << "您选择使用默认密码\n";
        m_password = "123456";
    }
    cout << "您已成功创建普通用户\n";
    cout << "您的用户名为： " << m_username << endl;
    cout << "您的密码为： " << m_password << endl;
    m_bookNumber = 0;
    for (auto & possessBook : possessBooks) {
        possessBook = "";
    }
}


//用户修改密码
void CommonUser::modifyPassword() {
    string originPassword, modifyPassword, confirmPassword;
    int times1 = 3, times2 = 3;
    cout << "您正在修改密码\n";
    start:
    cout << "请输入原密码：\n";
    cin >> originPassword;
    if (m_password == originPassword) {
        cout << "输入正确，请输入修改后的密码：\n";
        modify:
        cin >> modifyPassword;
        cout << "请确认密码：\n";
        cin >> confirmPassword;
        if (modifyPassword == confirmPassword) {
            m_password = modifyPassword;
            vector<CommonUser> CuList;
            CuList.clear();
            auto cp = new CommonUser();
            FILE *fp = fopen("CommonUser.bin", "rb+");
            while (true) {
                if (!fread(cp, sizeof(CommonUser), 1, fp)) {
                    delete cp;
                    break;
                }
                if (cp->getUsername() == m_username) {
                    *cp = *this;
                    cp->m_password = modifyPassword;
                }
                CuList.push_back(*cp);
            }
            fclose(fp);
            remove("CommonUser.bin");
            fp = fopen("CommonUser.bin", "ab+");
            fwrite(&CuList[0], CuList.size() * sizeof(CommonUser), 1, fp);
            fclose(fp);
            cout << "修改密码成功！\n";
        } else {
            times1--;
            if (times1 <= 0) {
                cout << "输入错误超过三次，拒绝修改\n";
                Online = false;
                RecordOnline();
                exitSystem();
                throw;
            }
            cout << "前后密码不一致，请重新输入：\n";

            goto modify;
        }
    } else {
        times2--;
        if (times2 <= 0) {
            cout << "输入错误超过三次，拒绝修改\n";
            exit(1);
        }
        cout << "密码输入错误，请重新输入\n";
        goto start;
    }
}


//管理员重制密码接口
void CommonUser::resetPassword() {
    m_password = "123456";
}


//普通用户借书
void CommonUser::borrowBook() {
    start:
    if (m_bookNumber < 3) {

        bool success = false;
        cout << "请输入您想要借阅的图书的名字、作者或者ISBN编号：\n";
        string message;
        cin >> message;
        vector<string> BookList;
        BookList.clear();
        ifstream ifs;
        ifs.open("books.txt", ios::in);
        string book;
        while (!ifs.eof()) {
            bool locate = false;
            getline(ifs, book);
            istringstream is(book);
            do {
                string word;
                is >> word;
                if (word == message) {
                    locate = true;
                    break;
                }
            } while (is);
            if (locate) {
                char judge;
                cout << book << endl;
                cout << "请问是否借阅这本书?     (Y/N)\n";
                cin >> judge;
                if (judge == 'Y') {
                    Book temp(book);
                    if (temp.BeBorrowed()) {
                        book = temp.IntoString(1);
                        for (auto &possessBook : possessBooks) {
                            if (possessBook.empty()) {
                                possessBook = temp.IntoString();
                                m_bookNumber++;
                                break;
                            }
                        }
                        writeRecord(temp, true);
                        success = true;
                    }
                }
            }
            BookList.push_back(book);
        }
        ifs.close();
        remove("books.txt");
        ofstream ofs;
        ofs.open("books.txt", ios::out);
        for (auto &i : BookList) {
            ofs << i << endl;
        }
        ofs.close();
        if (success) {
            cout << "借阅成功！\n";
        } else {
            cout << "借阅失败！\n";
        }
        char judge;
        cout << "是否继续借阅？    (Y/N)\n";
        cin >> judge;
        if (judge == 'Y') {
            goto start;
        }
    } else {
        cout << "您借阅的书籍数量超过规定数量，请归还后再进行借阅\n";
    }

}

//普通用户可以还书
void CommonUser::returnBook() {
    start:
    bool success = false;
    if (m_bookNumber >= 1) {
        cout << "您现在未归还的书籍有：\n";
        for (auto & possessBook : possessBooks) {
            cout << possessBook << endl;
        }
        cout << "请输入您想要归还的图书的名字，作者，出版号或者ISBN编号：\n";
        string message;
        cin >> message;
        vector<string> BookList;
        BookList.clear();
        ifstream ifs;
        ifs.open("books.txt", ios::in);
        string book;
        while (!ifs.eof()) {
            bool locate = false;
            getline(ifs, book);
            istringstream is(book);
            do {
                string word;
                is >> word;
                if (word == message) {
                    locate = true;
                    break;
                }
            } while (is);
            if (locate) {
                char judge;
                cout << book << endl;
                cout << "请问是否归还这本书?     (Y/N)\n";
                cin >> judge;
                if (judge == 'Y') {
                    Book temp(book);
                    book = temp.IntoString(1);
                    if (temp.BeReturned()) {
                        book = temp.IntoString(1);
                        for (auto &possessBook : possessBooks) {
                            if (possessBook == temp.IntoString()) {
                                possessBook = "";
                                writeRecord(temp, false);
                                success = true;
                            }
                            break;
                        }
                    }
                }
            }
            BookList.push_back(book);
        }
        ifs.close();
        remove("books.txt");
        ofstream ofs;
        ofs.open("books.txt", ios::out);
        for (auto &i : BookList) {
            ofs << i << endl;
        }
        ofs.close();
        if (success) {
            cout << "归还成功！\n";
        } else {
            cout << "您未借阅此书\n";
            cout << "归还失败！\n";
        }
        char judge;
        cout << "是否继续归还？    (Y/N)\n";
        cin >> judge;
        if (judge == 'Y') {
            goto start;
        }
    } else {
        cout << "您尚未借阅图书，无需归还\n";
    }
}

//普通用户记录借阅记录
void CommonUser::writeRecord(const Book &book, bool borrow) {
    if (borrow) {
        time_t tp;
        struct tm *p;
        time(&tp);
        p = localtime(&tp);
        FILE *fp = fopen("BookRecord.txt", "a+");
        fprintf(fp, "用户名： %s\t\t\t借书时间： %d/%d/%d\t%d:%02d:%02d\t\t书名：%s\tISBN：%s\t作者：%s\n",
                m_username.c_str(), 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec,
                book.GetTitle().c_str(), book.GetIsbn().c_str(), book.GetAuthor().c_str());
        fclose(fp);
    } else {
        time_t tp;
        struct tm *p;
        time(&tp);
        p = localtime(&tp);
        FILE *fp = fopen("BookRecord.txt", "a+");
        fprintf(fp, "用户名： %s\t\t\t还书时间： %d/%d/%d\t%d:%02d:%02d\t\t书名：%s\tISBN：%s\t作者：%s\n",
                m_username.c_str(), 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec,
                book.GetTitle().c_str(), book.GetIsbn().c_str(), book.GetAuthor().c_str());
        fclose(fp);
    }
}

//普通用户查看借阅记录
void CommonUser::viewRecord() {
    ifstream ifs;
    string str;
    ifs.open("BookRecord.txt", ios::in);
    while (!ifs.eof()) {
        bool locate = false;
        getline(ifs, str);
        istringstream is(str);
        do {
            string word;
            is >> word;
            if (word == m_username) {
                locate = true;
                break;
            }
        } while (is);
        if (locate) {
            cout << str << endl;
        }
    }
    ifs.close();
}

void CommonUser::exitSystem() {
    vector<CommonUser> CuList;
    CuList.clear();
    auto cp = new CommonUser();
    FILE *fp = fopen("CommonUser.bin", "rb+");
    while (true) {
        if (!fread(cp, sizeof(CommonUser), 1, fp)) {
            delete cp;
            break;
        }
        if (cp->getUsername() == m_username) {
            *cp = *this;
        }
        CuList.push_back(*cp);
    }
    fclose(fp);
    remove("CommonUser.bin");
    fp = fopen("CommonUser.bin", "ab+");
    fwrite(&CuList[0], CuList.size() * sizeof(CommonUser), 1, fp);
    fclose(fp);
}


