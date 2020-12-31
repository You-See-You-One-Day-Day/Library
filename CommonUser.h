//
// Created by 伍淇铨 on 2020/12/29.
//





#include <cstdio>
#include "User.h"

#ifndef LIBRARY_STUDENTS_H
#define LIBRARY_STUDENTS_H


class CommonUser : public User {
    CommonUser() {
        printf("您正在创建")

    }

    ~CommonUser() {

    }

public:
    //获取用户名
    std::string getUsername();

    //获取密码
    std::string getPassword();

    //普通用户登录请求
    void loginRequest();

    //普通用户修改密码
    void modifyPassword();

    //学校用户搜索图书
    void searchBook();

    //学校用户借书
    void borrowBook();

    //学校用户可以还书
    void returnBook();

    //学校用户查看借阅记录
    void viewRecord();

private:
    std::string m_username;  //账号
    std::string m_password;  //密码
    bool m_permission;  //管理员权限
    bool Online;

};


#endif //LIBRARY_STUDENTS_H
