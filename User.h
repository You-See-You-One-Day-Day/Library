//
// Created by 伍淇铨 on 2020/12/28.
//

//用户基类

#ifndef LIBRARY_USER_H
#define LIBRARY_USER_H

#include <iostream>
#include <ctime>
#include <fstream>
#include <sstream>
#include <vector>
#include <regex>
#include "Book.h"
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ifaddrs.h>


using namespace std;

class User {


public:
    //构造函数
    User() = default;

    //析构函数
    ~User() = default;

    //获取用户名
    [[nodiscard]] string getUsername() const;

    //获取密码
    [[nodiscard]] string getPassword() const;

    //

    //修改密码
    virtual void modifyPassword() = 0;

    //记录登录记录
    void RecordOnline();

    //查询登录记录
    void  ViewOnlineRecord();

    //搜索图书
    static void searchBook();


    bool Online{};  //在线状态
protected:
    string m_username;  //账号
    string m_password;  //密码
};


#endif //LIBRARY_USER_H
