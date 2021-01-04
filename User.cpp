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

