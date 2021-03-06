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

    void returnAllBook();

    //普通用户写入借阅记录
    void writeRecord(const Book &, bool);

    //普通用户查看借阅记录
    void viewRecord();

    //普通用户列表
    static void DisplayCommonUser();

    //退出系统
    void exitSystem();

    string possessBooks[3];

    int m_bookNumber{};
};


#endif //COMMON_USER_H
