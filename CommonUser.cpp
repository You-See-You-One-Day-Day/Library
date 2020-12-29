//
// Created by 伍淇铨 on 2020/12/29.
//

#include "CommonUser.h"


//获取用户名
std::string getUsername();

//获取密码
std::string getPassword();

//用户登录请求
void loginRequest() {

};

//用户修改密码
void modifyPassword() {

};


std::string m_username;  //账号
std::string m_password;  //密码
bool m_permission = false;  //管理员权限