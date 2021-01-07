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
        ofstream ofs;
        ofs.open("UserOnlineRecord.txt", ios::app);
        ofs << "用户名：" << m_username << "\t登录时间：" << 1900 + p->tm_year << "/" << 1 + p->tm_mon
            << "/" << p->tm_mday << ' ' << p->tm_hour << ':' << p->tm_min << ':' << p->tm_sec << endl;
    } else{
        time_t tp;
        struct tm *p;
        time(&tp);
        p = localtime(&tp);
        ofstream ofs;
        ofs.open("UserOnlineRecord.txt", ios::app);
        ofs << "用户名：" << m_username << "\t退出时间：" << 1900 + p->tm_year << "/" << 1 + p->tm_mon
            << "/" << p->tm_mday << ' ' << p->tm_hour << ':' << p->tm_min << ':' << p->tm_sec << endl;
    }
}

