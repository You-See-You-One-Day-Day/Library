//
// Created by 伍淇铨 on 2020/12/29.
//





#include <cstdio>
#include "User.h"

using namespace std;

#ifndef COMMON_USER_H
#define COMMON_USER_H


class CommonUser : public User {

public:
    //构造函数
    CommonUser() = default;

    explicit CommonUser(int);

    //析构函数
    ~CommonUser() = default;


    //普通用户修改密码
    void modifyPassword() override;

    //管理员重置密码接口
    void resetPassword();

    //普通用户借书
    void borrowBook();

    //普通用户还书
    void returnBook();

//
    //普通用户写入借阅记录
    void writeRecord(const Book&,bool);

    //普通用户查看借阅记录
    void viewRecord();

    //退出系统
    void exitSystem();

    int m_bookNumber = 0;
    string possessBooks[3]={};


};


#endif //COMMON_USER_H
