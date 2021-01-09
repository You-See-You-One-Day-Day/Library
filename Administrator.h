//
// Created by 伍淇铨 on 2020/12/28.
//

/*
管理员模式类：
 图书管理系统最初提供一个默认的管理员账户以及默认密码；
 管理员具备以下功能：
    可以使用管理员账号登录
    支持对学校用户的账号进行基本管理
    添加、删除学校用户默认账号和密码(默认账号为学号/教师编号，密码为123456)
    恢复学校用户默认密码
    管理员可以对图书信息进行修改
    管理员可以增加、删除、`搜索图书`
*/



#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include<cstdio>
#include<string>
#include <vector>
#include "User.h"

using namespace std;

class Administrator : public User {
public:
//构造函数
    explicit Administrator(int);
    Administrator() = default;

    //析构函数
    ~Administrator() = default;


    //管理员修改密码
    void modifyPassword() override;

    //管理员添加学校用户默认账号和密码
    static void addCommonUser();

    //管理员删除学校用户默认账号和密码
    static void deleteCommonUser();

    //管理员恢复学校用户默认密码
    static void resetCommonUser();

    //管理员修改图书信息
    static void modifyBook();

    //管理员增加图书
    static void addBook();

    //管理员删除图书
   static void deleteBook();

    //退出系统
    void exitSystem();
};


#endif //ADMINISTRATOR_H

