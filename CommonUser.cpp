//
// Created by 伍淇铨 on 2020/12/29.
//

#include "CommonUser.h"
#include "Book.h"

using namespace std;

CommonUser::CommonUser(int) {
    char judge;
    cout << "您正在创建普通用户\n";

    cout << "请输入用户名： \n";
    start:
    cin >> m_username;

    FILE *fp = fopen("CommonUser.bin", "rb");
    if (fp != nullptr) {
        auto ap = new CommonUser;
        bool exist = false;
        while (true) {
            if (!fread(ap, sizeof(CommonUser), 1, fp)) {
                delete ap;
                break;
            }
            if (ap->getUsername() == m_username) {
                exist = true;
                delete ap;
                break;
            }
        }
        if (exist) {
            cout << "用户名已存在，请重新输入：\n";
            goto start;
        }
    }
    fclose(fp);
    cout << "是否使用默认密码123456？（Y/N）  ";
    cin >> judge;
    if (judge != 'Y') {
        string initialPassword, confirmPassword;
        input:
        cout << "请输入密码：\n";
        cin >> initialPassword;

        cout << "请确认密码：\n";
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


//用户修改密码
void CommonUser::modifyPassword() {
    string originPassword, modifyPassword, confirmPassword;
    int times1 = 3, times2 = 3;
    cout << "您正在修改密码\n";
    start:
    cout << "请输入原密码：\n";
    cin >> originPassword;
    if (m_password == originPassword) {
        cout << "输入正确，请输入修改后的密码：\n";
        modify:
        cin >> modifyPassword;
        cout << "请确认密码：\n";
        cin >> confirmPassword;
        if (modifyPassword == confirmPassword) {
            m_password = modifyPassword;
            vector<CommonUser> CuList;
            CuList.clear();
            auto cp = new CommonUser();
            FILE *fp = fopen("CommonUser.bin", "ab+");
            while (true) {
                if (!fread(cp, sizeof(CommonUser), 1, fp)) {
                    delete cp;
                    break;
                }
                if (cp->getUsername() == m_username) {
                    *cp = *this;
                    cp->m_password = modifyPassword;
                }
                CuList.push_back(*cp);
            }
            fwrite(&CuList[0], CuList.size() * sizeof(CommonUser), 1, fp);
            fclose(fp);
            cout << "修改密码成功！\n";
        } else {
            times1--;
            if (times1 <= 0) {
                cout << "输入错误超过三次，拒绝修改\n";
                Online = false;
                RecordOnline();
                throw;
            }
            cout << "前后密码不一致，请重新输入：\n";

            goto modify;
        }
    } else {
        times2--;
        if (times2 <= 0) {
            cout << "输入错误超过三次，拒绝修改\n";
            exit(1);
        }
        cout << "密码输入错误，请重新输入\n";
        goto start;
    }
}


//管理员重制密码接口
void CommonUser::resetPassword() {
    m_password = "123456";
}


//普通用户搜索图书
void CommonUser::searchBook() {
//    FILE
}


//普通用户借书
void CommonUser::borrowBook() {

}

//普通用户可以还书
void CommonUser::returnBook() {

}

//普通用户记录借阅记录
void CommonUser::writeRecord() {

}

//普通用户查看借阅记录
void CommonUser::viewRecord() {

}


