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

#include <iostream>
#include <cstdio>
#include "User.h"

#ifndef LIBRARY_ADMINISTRATOR_H
#define LIBRARY_ADMINISTRATOR_H


class Administrator : public User {
    //构造函数
    Administrator() {
        char judge;
        printf("您正在创建管理员用户\n");
        printf("请输入用户名： ");
        scanf("%s\n", &m_password);
        printf("是否使用默认密码123456？ Y/N\n");
        scanf("%c\n", &judge);
        if (judge != 'N') {
            std::string password;
            printf("请输入密码： \n");
            scanf("%s", &password);
            printf("请确认密码： ");

        }

    };

    //析构函数
    ~Administrator() override {


    }

    //管理员登录请求
    void loginRequest() override;

    //管理员修改密码
    void modifyPassword() override;

    //管理员添加学校用户默认账号和密码
    void addCommonUser();

    //管理员删除学校用户默认账号和密码
    void deleteCommonUser();

    //管理员恢复学校用户默认密码
    void resetCommonUser();

    //管理员修改图书信息
    void modifyBook();

    //管理员增加图书
    void addBook();

    //管理员删除图书
    void deleteBook();

    //管理员搜索图书
    void searchBook();


private:
    //管理员权限
    bool permission = true;
};


#endif //LIBRARY_ADMINISTRATOR_H
