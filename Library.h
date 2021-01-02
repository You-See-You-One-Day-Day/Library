//
// Created by 伍淇铨 on 2020/12/28.
//


//图书馆类

#include "Administrator.h"
#include "CommonUser.h"

#ifndef LIBRARY_LIBRARY_H
#define LIBRARY_LIBRARY_H


class Library {

public:
    //构造函数
    Library() = default;

    //析构函数
    ~Library() = default;

    //注册模块
    bool Register(int &AdministratorNumber, Administrator *head1, CommonUser *head2);

    //登录模块
    bool Login();
};


#endif //LIBRARY_LIBRARY_H
