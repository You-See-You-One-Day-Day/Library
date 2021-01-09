//
// Created by 伍淇铨 on 2020/12/28.
//


//图书馆类
#ifndef LIBRARY_LIBRARY_H
#define LIBRARY_LIBRARY_H

#include "Administrator.h"
#include "CommonUser.h"
#include "Book.h"


class Library {

public:
    //构造函数
    Library() = default;

    //析构函数
    ~Library() = default;

    //初始化函数
    static void LibraryInit();

    //获取管理员人数
    static int getAdminNum();

    //主菜单
    static bool MainMenu(Administrator &, CommonUser &);

    //用户菜单
    static void UserMenu(Administrator&);
    static void UserMenu(CommonUser&);

    //注册模块
    static void RegisterMenu();

    //登录模块
    static string LoginMenu(Administrator &, CommonUser &);

    static bool Login(CommonUser &);

    static bool Login(Administrator &);

};

#endif //LIBRARY_LIBRARY_H
