//
// Created by 伍淇铨 on 2020/12/28.
//

#include <cstdio>
#include "User.h"

#ifndef LIBRARY_ADMINISTRATOR_H
#define LIBRARY_ADMINISTRATOR_H


class Administrator : public User {
    //构造函数
    Administrator() {
        printf("您正在创建管理员用户\n");
        printf("请输入用户名： ");
        scanf("%s", &m_password);
        printf("是否使用默认密码123456？ Y/N")
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
