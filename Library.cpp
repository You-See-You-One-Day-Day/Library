//
// Created by 伍淇铨 on 2020/12/28.
//
#include "Administrator.h"
#include "CommonUser.h"
#include "Library.h"



//注册模块
bool Library::Register(int &AdministratorNumber, Administrator *head1, CommonUser *head2) {
    char a;
    cout << "请问是否创建管理员用户    Y/N";
    cin >> a;
    if (a == 'Y') {
        if (AdministratorNumber <= 3) {
            FILE *fp = fopen("Administrator.bin", "ab+");
            fwrite(head1, sizeof(Administrator), 1, fp);
            fclose(fp);
            AdministratorNumber++;
            return true;
        } else {
            cout << "已有三位管理员用户，拒绝继续创建新管理员用户";
            return false;
        }
    } else {
        FILE *fp;
        fp = fopen("CommonUser.bin", "ab+");
        fwrite(head2, sizeof(CommonUser), 1, fp);
        fclose(fp);
        return true;
    }
}


//登录模块
bool Library::Login() {
    cout << "您正在以管理员权限登入\n";
    string username, password;
    cout << "用户名：";
    cin >> username;
    cout << "密码： ";
    cin >> password;

    FILE *fp = fopen("Administrator.txt", "r");
    Administrator *p = new Administrator;
    if (fp==nullptr){
        cout <<"不存在管理员用户，登录失败";
        return false;
    }
    for (int times = 3; times >= 0; times--) {
        if (times <= 0) return false;
        if (p->getUsername() == username && p->getPassword() == password) {
            cout << "登录成功";
            return true;
        } else {
            cout << "用户名或密码出错，您还有" << times << "次登录机会";
            continue;
        }
    }
    return false;
}

