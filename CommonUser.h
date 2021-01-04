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
    CommonUser() = default;;

    explicit CommonUser(int) {
        char judge;
        cout << "您正在创建普通用户\n";

        cout << "请输入用户名： \n";
        cin >> m_username;

        cout << "是否使用默认密码123456？（Y/N）  ";
        cin >> judge;
        if (judge != 'Y') {
            string initialPassword, confirmPassword;
            input:
            cout << "请输入密码：";
            cin >> initialPassword;

            cout << "请确认密码：";
            cin >> confirmPassword;

            if (initialPassword != confirmPassword) {
                cout << "前后密码输入不一致，请重新输入\n";
                goto input;
            } else {
                m_password = initialPassword;
            }

        } else {
            cout << "您选择使用默认密码\n";
            m_password = "123456";
        }
        cout << "您已成功创建普通用户\n";
        cout << "您的用户名为： " << m_username << endl;
        cout << "您的密码为： " << m_password << endl;

    }


    //析构函数
    ~CommonUser() = default;


    //普通用户修改密码
    void modifyPassword() override;

    //学校用户搜索图书
    void searchBook();

    //学校用户借书
    void borrowBook();

    //学校用户可以还书
    void returnBook();

    //学校用户查看借阅记录
    void viewRecord();


};


#endif //COMMON_USER_H
