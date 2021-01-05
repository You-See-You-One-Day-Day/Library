//
// Created by 伍淇铨 on 2020/12/29.
//

#include "CommonUser.h"

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
            auto ap = new CommonUser();
            FILE *fp = fopen("Administrator.bin", "wb+");
            while (true) {
                if (!fread(ap, sizeof(CommonUser), 1, fp)) {
                    delete ap;
                    break;
                }
                if (ap->getUsername() == m_username) {
                    *ap = *this;
                    ap->m_password = modifyPassword;
                    fseek(fp, -int(sizeof(CommonUser)), SEEK_CUR);
                    fwrite(ap, sizeof(CommonUser), 1, fp);
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

};

