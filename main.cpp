#include "Library.h"

int main() {
    Library::LibraryInit();
    Administrator administrator;
    CommonUser commonUser;
    MainMenu:
    if (Library::MainMenu(administrator, commonUser)) {
        string login = Library::LoginMenu(administrator, commonUser);
        if (login == "Administrator") {
            Library::UserMenu(administrator);
            goto MainMenu;
        } else if (login == "CommonUser") {
            Library::UserMenu(commonUser);
            goto MainMenu;
        } else {
            goto MainMenu;
        }
    } else {
        cout << "感谢您的使用" << endl;
    }
    administrator.exitSystem();
    commonUser.exitSystem();
    system("pause");
    return 0;
}