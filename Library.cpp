//
// Created by 伍淇铨 on 2020/12/29.
//

#include "Library.h"

using namespace std;




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
    int AdministratorNumber = getAdminNum();
    registerStart:
    cout << "请选择注册用户类型：1管理员，2普通用户\n";
    cin >> a;
    switch (a) {
        case 1 : {
            if (AdministratorNumber < 4) {
                auto *AD = new Administrator(a);
                FILE *fp = fopen("Administrator.bin", "ab+");
                fwrite(AD, sizeof(Administrator), 1, fp);
                fclose(fp);
                delete AD;
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
            delete CU;
            break;
        }

        default: {
            cout << "不存在该类型,请重新选择\n";
            goto registerStart;
        }


    }

}


//登录模块
string Library::LoginMenu(Administrator &a, CommonUser &b) {
    int select;
    LoginStart:
    cout << "请选择您的登录模式：1管理员模式，2普通用户模式\n";
    cin >> select;
    switch (select) {
        case 1: {
            if (Login(a)) {
                return "Administrator";
            } else {
                return "failed";
            }
        }
        case 2: {
            if (Login(b)) {
                return "CommonUser";
            } else {
                return "failed";
            }
        }
        default: {
            goto LoginStart;
        }
    }
}

bool Library::Login(Administrator &a) {
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
        a.Online = true;
        a.RecordOnline();
        cout << "恭喜您登录成功\n";
        return true;
    } else {
        ++times;
        if (times >= 3) {
            cout << "输入错误达到三次，拒绝访问\n";
        } else {
            char select;
            cout << "用户名或密码输入错误，是否继续登录？ （Y/N）";
            cin >> select;
            if (select == 'Y') {
                goto loginStart;
            }
        }
    }
    return false;
}

bool Library::Login(CommonUser &a) {
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
        a.RecordOnline();
        cout << "恭喜您登录成功\n";
        return true;
    } else {
        ++times;
        if (times >= 3) {
            cout << "输入错误达到三次，拒绝访问\n";
        } else {
            char select;
            cout << "用户名或密码输入错误，是否继续登录？ （Y/N）";
            cin >> select;
            if (select == 'Y') {
                goto loginStart;
            }
        }
    }
    return false;
}

//主菜单
bool Library::MainMenu(Administrator &a, CommonUser &b) {
    int select;
    start:
    cout << "\t\t\t ============ 图 书 管 理 系 统 ============\n";
    cout << "\t\t\t|************** 0.用户文档  **************｜\n";
    cout << "\t\t\t|************** 1.注册     **************｜\n";
    cout << "\t\t\t|************** 2.登录     **************｜\n";
    cout << "\t\t\t|************** 3.退出     **************｜\n\n";
    cout << "请输入您的选择：";
    select:
    cin >> select;
    switch (select) {
        case 0: {
            cout << "用户文档，不存在的，想都不要想" << endl;
            goto start;
        }
        case 1: {
            RegisterMenu();
            goto start;
        }
        case 2: {
            return true;
        }
        case 3:
            return false;
        default:
            cout << "没有这个选项，请重新选择：";
            goto select;
    }
}


//用户菜单
void Library::UserMenu(Administrator &administrator) {
    int select;
    start:
    cout << "\t\t\t=============== 管 理 员 菜 单 ===============\n";
    cout << "\t\t\t|************** 0.修改密码     **************｜\n";
    cout << "\t\t\t|************** 1.搜索图书     **************｜\n";
    cout << "\t\t\t|************** 2.增加图书     **************｜\n";
    cout << "\t\t\t|************** 3.删除图书     **************｜\n";
    cout << "\t\t\t|************** 4.修改图书信息  **************｜\n";
    cout << "\t\t\t|************** 5.添加普通用户  **************｜\n";
    cout << "\t\t\t|************** 6.删除普通用户  **************｜\n";
    cout << "\t\t\t|************** 7.重置普通用户  **************｜\n";
    cout << "\t\t\t|************** 8.查询登录记录  **************｜\n";
    cout << "\t\t\t|************** 9.退出登录     **************｜\n\n";
    cout << "请输入您的选择：";
    select:
    cin >> select;
    switch (select) {
        case 0: {
            administrator.modifyPassword();
            cout << "检测到密码已修改，请重新登录\n";
            break;
        }
        case 1: {
            Administrator::searchBook();
            goto start;

        }
        case 2: {
            Administrator::addBook();
            goto start;

        }
        case 3: {
            Administrator::deleteBook();
            goto start;
        }
        case 4: {
            Administrator::modifyBook();
            goto start;
        }
        case 5: {
            Administrator::addCommonUser();
            goto start;
        }
        case 6: {
            Administrator::deleteCommonUser();
            goto start;
        }
        case 7: {
            Administrator::resetCommonUser();
            goto start;
        }
        case 8: {
            administrator.ViewOnlineRecord();
            goto start;
        }
        case 9: {
            administrator.Online = false;
            administrator.RecordOnline();
            break;
        }
        default: {
            cout << "没有这个选项，请重新选择：";
            goto select;
        }
    }
}

void Library::UserMenu(CommonUser &commonUser) {
    int select;
    start:
    cout << "\t\t\t ================ 用 户 菜 单 ================\n";
    cout << "\t\t\t|************** 0.更改密码     **************｜\n";
    cout << "\t\t\t|************** 1.查询图书     **************｜\n";
    cout << "\t\t\t|************** 2.借阅图书     **************｜\n";
    cout << "\t\t\t|************** 3.归还图书     **************｜\n";
    cout << "\t\t\t|************** 4.查询登录记录  **************｜\n";
    cout << "\t\t\t|************** 5.查询借阅记录  **************｜\n";
    cout << "\t\t\t|************** 6.退出登录     **************｜\n\n";
    cout << "请输入您的选择：";
    select:
    cin >> select;
    switch (select) {
        case 0: {
            commonUser.modifyPassword();
            cout << "检测到密码已修改，请重新登录\n";
            break;
        }
        case 1: {
            CommonUser::searchBook();
            goto start;
        }
        case 2: {
            commonUser.borrowBook();
            goto start;
        }
        case 3: {
            commonUser.returnBook();
            goto start;
        }
        case 4: {
            commonUser.ViewOnlineRecord();
            goto start;
        }
        case 5: {
            commonUser.viewRecord();
            goto start;
        }
        case 6: {
            commonUser.Online = false;
            commonUser.RecordOnline();
            break;
        }
        default: {
            cout << "没有这个选项，请重新选择：";
            goto select;
        }
    }
}

void Library::LibraryInit() {
    FILE *ad = fopen("Administrator.bin", "ab+");
    FILE *cu = fopen("CommonUser.bin", "ab+");
    FILE *book = fopen("books.txt","a+");
    fclose(ad);
    fclose(cu);
    fclose(book);
    Book::BookInit();
}



