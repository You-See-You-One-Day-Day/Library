//
// Created by 伍淇铨 on 2020/12/28.
//

//用户基类
#include<iostream>

#ifndef LIBRARY_USER_H
#define LIBRARY_USER_H


class User {


public:
    //获取用户名
    std::string getUsername();

    //获取密码
    std::string getPassword();

    //用户登录请求
//    virtual void loginRequest() = 0;

    //用户修改密码
//    virtual void modifyPassword() = 0;


protected:
    std::string m_username;  //账号
    std::string m_password;  //密码
    bool m_permission;  //管理员权限
    bool Online;  //在线状态

    //构造函数
    User() {

    }

    //析构函数
    virtual ~User() {

    }
};


#endif //LIBRARY_USER_H
