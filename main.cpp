//  main.cpp
//  图书管理系统 图书管理
//
//  Created by 王雨梦 on 2020/12/29.
//

#include "Library.h"


using namespace std;

void menu() {
    cout << "---------------【name 图书管理系统】--------------" << endl;
    cout << "\t\t1." << endl;

}


void Register(int AdministratorNumber) {
    char a;
    cout << "请问是否创建管理员用户    Y/N";
    cin >> a;
    if (a == 'Y') {
        auto *AD = new Administrator;
        FILE *fp = fopen("Administrator.bin","ab+");
        fwrite(AD,sizeof(Administrator),1,fp);
        fclose(fp);
    } else {
        auto *CU = new CommonUser;
        FILE *fp = fopen("CommonUser.bin","ab+");
        fwrite(CU,sizeof(CommonUser),1,fp);
        fclose(fp);
    }

}


int main() {
    Register(2);


    return 0;
}
