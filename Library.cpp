//
// Created by 伍淇铨 on 2020/12/29.
//

#include "Library.h"

using namespace std;


 auto Library::LoginMenu(User *pUser) {
    int a;
    LoginStart:
    cout << "请选择您的登录模式：1管理员模式，2普通用户模式\n";
    cin >> a;
    switch (a) {
        case 1: {
            auto user = new Administrator();
            Login(*user);
            pUser = user;
            return pUser;
        }
        case 2: {
            auto user = new CommonUser();
            Login(*user);
            pUser = user;
            return pUser;
        }
        default: {
            cout << "不存在该类型,请重新选择\n";
            goto LoginStart;
        }
    }
}


//注册模块

int Library::getAdminNum() {                        //获取管理员人数
    auto *ap = new Administrator();
    int num = 1;
    FILE *fp = fopen("Administrator.bin", "rb");
    while (true) {
        if (!fread(ap, sizeof(Administrator), 1, fp)) {
            delete ap;
            break;
        }
        ++num;
    }
    return num;
}
void Library::RegisterMenu() {
    int a;
    int AdministratorNumber = this->getAdminNum();
    registerStart:
    cout << "请选择注册用户类型：1管理员，2普通用户\n";
    cin >> a;
    switch (a) {
        case 1 : {
            if (AdministratorNumber <= 4) {
                auto *AD = new Administrator(a);
                FILE *fp = fopen("Administrator.bin", "ab+");
                fwrite(AD, sizeof(Administrator), 1, fp);
                fclose(fp);
                cout << "现在已有" << AdministratorNumber << "位管理员\n";
            } else {
                cout << "管理员人数超过" << AdministratorNumber << "位，拒绝继续创建\n";
            }
            break;
        }

        case 2: {
            auto *CU = new CommonUser(a);
            FILE *fp = fopen("CommonUser.bin", "ab+");
            fwrite(CU, sizeof(CommonUser), 1, fp);
            fclose(fp);
            break;
        }

        default: {
            cout << "不存在该类型,请重新选择\n";
            goto registerStart;
        }


    }

}



//登录模块
void Library::Login(Administrator &a) {
    string username, password;
    int times = 0;
    cout << "您正以管理员身份登录\n";
    loginStart:
    cout << "请输入用户名：\n";
    cin >> username;
    cout << "请输入密码：\n";
    cin >> password;

    bool log = false;
    auto *ap = new Administrator();
    FILE *fp = fopen("Administrator.bin", "rb");
    while (true) {
        if (!fread(ap, sizeof(Administrator), 1, fp)) {
            delete ap;
            break;
        }
        if (ap->getUsername() == username && ap->getPassword() == password) {
            log = true;
            a = *ap;
            delete ap;
            break;
        }

    }
    if (log) {
        cout << "恭喜您登录成功\n";
    } else {
        ++times;
        if (times >= 3) {
            cout << "输入错误达到三次，拒绝访问\n";
            exit(1);
        } else {
            cout << "用户名或密码输入错误，请重新输入\n";
            goto loginStart;
        }
    }
}

void Library::Login(CommonUser &a) {
    string username, password;
    int times = 0;
    cout << "您正以普通用户身份登录\n";
    loginStart:
    cout << "请输入用户名：\n";
    cin >> username;
    cout << "请输入密码：\n";
    cin >> password;

    bool log = false;
    auto *ap = new CommonUser();
    FILE *fp = fopen("CommonUser.bin", "rb");
    while (true) {
        if (!fread(ap, sizeof(CommonUser), 1, fp)) {
            delete ap;
            break;
        }
        if (ap->getUsername() == username && ap->getPassword() == password) {
            log = true;
            a = *ap;
            delete ap;
            break;
        }

    }
    if (log) {
        a.Online = true;
        cout << "恭喜您登录成功\n";
    } else {
        ++times;
        if (times >= 3) {
            cout << "输入错误达到三次，拒绝访问\n";
            exit(1);
        } else {
            cout << "用户名或密码输入错误，请重新输入\n";
            goto loginStart;
        }
    }
}





//修改密码模块
void Library::ModifyPassword(Administrator &a){
    a.modifyPassword();
}

void Library::MainMenu() {
    int select;
    cout << "\t\t\t ============ 图书管理系统 ============\n";
    cout << "\t\t\t|************** 1.注册  **************｜\n";
    cout << "\t\t\t|************** 2.登录  **************｜\n";
    cout << "\t\t\t|************** 3.退出  **************｜\n";
//    cout << "\t\t\t|************** 4.  **************｜\n";
//    cout << "\t\t\t|************** 5.  **************｜\n";
    cout <<"\n\n\n\n";
    cout << "请输入您的选择：";
    cin >> select;
    switch (select) {
        case 1:{


        }
        case 2:{

        }
        case 3:
    }


}



