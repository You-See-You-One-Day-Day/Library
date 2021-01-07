#include "Library.h"

int main() {
    Administrator administrator;
    CommonUser commonUser;
    MainMenu:
    if (Library::MainMenu(administrator, commonUser)) {
        if (Library::LoginMenu(administrator, commonUser)) {
            Library::UserMenu(administrator);
            goto MainMenu;
        } else {
            Library::UserMenu(commonUser);
            goto MainMenu;
        }
    } else {
        cout << "感谢您的使用" << endl;
    }
    system("pause");
    return 0;
}