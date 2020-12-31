//
// Created by 伍淇铨 on 2020/12/28.
//
#include "Administrator.h"
#include "CommonUser.h"
#include "Library.h"
#include <fstream>


//注册模块
void Register(Administrator *head) {
    FILE *fp;
    fp = fopen("Administrator.txt", "a");
    fwrite(fp, sizeof(Administrator), 1, fp);
    fclose(fp);
}

void Register(CommonUser *head) {
    FILE *fp;
    fp = fopen("CommonUser.txt", "a");
    fwrite(fp, sizeof(CommonUser), 1, );
    fclose(fp);
}

//登录模块
void Login(bool permission) {
    if (permission){
        cout << "您正在以管理员权限登入\n";
        string username,password;
        cout << "用户名：";
        cin >> username;
        cout << "密码： ";
        cin >> password;
        FILE *fp;
        Administrator *p;
        fp = fopen("Administrator.txt","r");
        while (!fread(p,sizeof(Administrator),1, fp)){

        }
    }
}