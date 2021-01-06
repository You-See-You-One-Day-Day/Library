//
// Created by 伍淇铨 on 2020/12/28.
//

#include "Administrator.h"
#include "CommonUser.h"


//管理员修改密码
void Administrator::modifyPassword() {
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
            auto ap = new Administrator();
            FILE *fp = fopen("Administrator.bin", "rb+");
            while (true) {
                if (!fread(ap, sizeof(Administrator), 1, fp)) {
                    delete ap;
                    break;
                }
                if (ap->getUsername() == m_username) {
                    *ap = *this;
                    ap->m_password = modifyPassword;
                    fseek(fp, -int(sizeof(Administrator)), SEEK_CUR);
                    fwrite(ap, sizeof(Administrator), 1, fp);
                    delete ap;
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
}

//管理员添加学校用户默认账号和密码
void Administrator::addCommonUser() {
    auto CU = new CommonUser(1);
    FILE *fp = fopen("CommonUser.bin", "ab+");
    fwrite(CU, sizeof(CommonUser), 1, fp);
    fclose(fp);
    delete CU;
}

//管理员删除学校用户默认账号和密码
void Administrator::deleteCommonUser() {
    auto cp = new CommonUser();
    string deleteUsername;
    cout <<"请输入您想删除的账户的用户名";
    cin >>deleteUsername;
    FILE *fp = fopen("CommonUser.bin", "rb");
    while (true) {
        if (!fread(cp, sizeof(CommonUser), 1, fp)) {
            delete cp;
            break;
        }
        if (cp->getUsername() ==deleteUsername) {
            auto null = new CommonUser();
            fseek(fp, -int(sizeof(CommonUser)), SEEK_CUR);
            fwrite(null, sizeof(CommonUser), 1, fp);
            delete cp;
            break;
        }
    }
    cout << "删除用户成功！";
}

//管理员恢复学校用户默认密码
void Administrator::resetCommonUser() {
    auto cp = new CommonUser();
    string resetUsername;
    cout <<"请输入您想恢复的账户的用户名";
    cin >>resetUsername;
    FILE *fp = fopen("CommonUser.bin", "rb");
    while (true) {
        if (!fread(cp, sizeof(CommonUser), 1, fp)) {
            delete cp;
            break;
        }
        if (cp->getUsername() ==resetUsername) {
            cp->resetPassword();
            fseek(fp, -int(sizeof(CommonUser)), SEEK_CUR);
            fwrite(cp, sizeof(CommonUser), 1, fp);
            delete cp;
            break;
        }
    }
    cout << "删除用户成功！";
}


//管理员修改图书信息
void Administrator::modifyBook() {

}

//管理员增加图书
void Administrator::addBook() {

}

//管理员删除图书
void Administrator::deleteBook() {

}

//管理员搜索图书
void Administrator::searchBook() {

}



