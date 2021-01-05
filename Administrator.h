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
#include "User.h"

using namespace std;

class Administrator : public User { ;
public:
//构造函数
    explicit Administrator(int) {
        char judge;
        cout << "您正在创建管理员用户\n";

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
        cout << "您已成功创建管理员用户\n";
        cout << "您的用户名为： " << m_username << endl;
        cout << "您的密码为： " << m_password << endl;

    }

    Administrator() = default;

    //析构函数
    ~Administrator() = default;


    //管理员修改密码
    void modifyPassword() override;

    //管理员添加学校用户默认账号和密码
    static void addCommonUser();

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


#endif //ADMINISTRATOR_H

