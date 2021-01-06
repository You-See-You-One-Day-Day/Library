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

    //获取管理员人数
    static int getAdminNum();

    //主菜单
    void MainMenu();

    //注册模块
    void RegisterMenu();

    //登录模块
    auto LoginMenu(User*);

    static void Login(CommonUser &);

    static void Login(Administrator &);

    //修改模块
    void ModifyPassword(Administrator &);

    //查询模块
    void ViewOnline();

};

#endif //LIBRARY_LIBRARY_H
