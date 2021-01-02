//
// Created by 伍淇铨 on 2020/12/28.
//

#include "User.h"

std::string m_username;  //账号
std::string m_password;  //密码

//获取用户名
string User::getUsername() {
    std::string username = m_username;
    return username;
}

//获取密码
string User::getPassword() {
    std::string password = m_password;
    return password;
}

