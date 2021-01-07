//
// Created by 伍淇铨 on 2020/12/28.
//

#include "User.h"

using namespace std;


//获取用户名
string User::getUsername() const {
    string username = m_username;
    return username;
}

//获取密码
string User::getPassword() const {
    string password = m_password;
    return password;
}

//记录登录记录
void User::RecordOnline() {
    if (Online) {
        time_t tp;
        struct tm *p;
        time(&tp);
        p = localtime(&tp);
        FILE *fp = fopen("UserOnlineRecord.txt", "a+");
        fprintf(fp, "用户名： %s\t\t\t登录时间： %d/%d/%d\t%d:%02d:%02d\n", m_username.c_str(),
                1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec);
        fclose(fp);
    } else {
        time_t tp;
        struct tm *p;
        time(&tp);
        p = localtime(&tp);
        FILE *fp = fopen("UserOnlineRecord.txt", "a+");
        fprintf(fp, "用户名： %s\t\t\t退出时间： %d/%d/%d\t%d:%02d:%02d\n", m_username.c_str(),
                1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec);
        fclose(fp);
    }
}

void User::ViewOnlineRecord() {
    ifstream ifs;
    string str;
    ifs.open("UserOnlineRecord.txt", ios::in);
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