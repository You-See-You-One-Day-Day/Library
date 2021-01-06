//
// Created by 伍淇铨 on 2020/12/29.
//

#include "CommonUser.h"
//#include "book.h"

using namespace std;


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
            auto cp = new CommonUser();
            FILE *fp = fopen("CommonUSer.bin", "wb+");
            while (true) {
                if (!fread(cp, sizeof(CommonUser), 1, fp)) {
                    delete cp;
                    break;
                }
                if (cp->getUsername() == m_username) {
                    *cp = *this;
                    cp->m_password = modifyPassword;
                    fseek(fp, -int(sizeof(CommonUser)), SEEK_CUR);
                    fwrite(cp, sizeof(CommonUser), 1, fp);
                    delete cp;
                    break;
                }
            }
            fclose(fp);
            cout << "修改密码成功！\n";
        } else {
            times1--;
            if (times1 <= 0) {
                cout << "输入错误超过三次，拒绝修改\n";
                exit(1);
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
};


//管理员重制密码接口
void CommonUser::resetPassword() {
    m_password = "123456";
}


//普通用户搜索图书
void searchBook() {
//    FILE
}


//普通用户借书
void borrowBook();

//普通用户可以还书
void returnBook();

//普通用户查看借阅记录
void viewRecord();

