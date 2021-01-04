//
// Created by 伍淇铨 on 2020/12/28.
//
#include "Administrator.h"
#include "CommonUser.h"
#include "Library.h"

using namespace std;

//注册模块
int getAdminNum() {
    auto *ap = new Administrator(1);
    int num = 1;
    FILE *fp = fopen("Administrator.bin", "rb");
    while (true) {
        if (!fread(ap, sizeof(Administrator), 1, fp)) {
            delete ap;
            break;
        };
        ++num;
    }
    return num;
}


void Register(int &AdministratorNumber) {
    int a;
    cout << "请选择注册用户类型：1管理员，2普通用户\n";
    cin >> a;
    start:
    switch (a) {
        case 1 : {
            if (AdministratorNumber <= 3) {
                auto *AD = new Administrator;
                FILE *fp = fopen("Administrator.bin", "ab+");
                fwrite(AD, sizeof(Administrator), 1, fp);
                fclose(fp);
                cout << "现在已有" << AdministratorNumber << "位管理员\n";
            } else {
                cout << "管理员人数超过三位，拒绝继续创建\n";
                exit(1);
            }
            break;
        }

        case 2: {
            auto *CU = new CommonUser;
            FILE *fp = fopen("CommonUser.bin", "ab+");
            fwrite(CU, sizeof(CommonUser), 1, fp);
            fclose(fp);
            break;
        }

        default:
            cout << "不存在该类型\n";
            cout << "请重新选择： ";
            goto start;
    }

}

void Login() {


}


void test01() {
    int num = getAdminNum();
    Register(num);
}

void test02() {

}

int main() {


    return 0;
}


