//
// Created by 伍淇铨 on 2020/12/28.
//

#include "Administrator.h"
#include "CommonUser.h"
#include "Book.h"

//构造函数
Administrator::Administrator(int) {
    char judge;
    cout << "您正在创建管理员用户\n";
    cout << "请输入用户名： \n";
    start:
    cin >> m_username;
    FILE *fp = fopen("Administrator.bin", "rb+");
    if (fp != nullptr) {
        auto ap = new Administrator;
        bool exist = false;
        while (true) {
            if (!fread(ap, sizeof(Administrator), 1, fp)) {
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
        cout << "请输入密码：";
        cin >> initialPassword;

        cout << "请确认密码：";
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
    cout << "您已成功创建管理员用户\n";
    cout << "您的用户名为： " << m_username << endl;
    cout << "您的密码为： " << m_password << endl;

}


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
            vector<Administrator> AdList;
            AdList.clear();
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
                }
                AdList.push_back(*ap);
            }
            fclose(fp);
            remove("Administrator.bin");
            fp = fopen("Administrator.bin", "ab+");
            fwrite(&AdList[0], AdList.size() * sizeof(Administrator), 1, fp);
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
    cout << "添加用户成功！\n";
}

//管理员删除学校用户默认账号和密码
void Administrator::deleteCommonUser() {
    auto cp = new CommonUser();
    string deleteUsername;
    bool success = false;
    cout << "请输入您想删除的账户的用户名\n";
    cin >> deleteUsername;
    vector<CommonUser> CuList;
    CuList.clear();
    FILE *fp = fopen("CommonUser.bin", "rb+");
    while (true) {
        if (!fread(cp, sizeof(CommonUser), 1, fp)) {
            delete cp;
            break;
        }
        if (cp->getUsername() == deleteUsername) {
            success = true;
        } else {
            CuList.push_back(*cp);
        }
    }
    fclose(fp);
    remove("CommonUser.bin");
    fp = fopen("CommonUser.bin", "ab+");
    fwrite(&CuList[0], CuList.size() * sizeof(CommonUser), 1, fp);
    fclose(fp);
    if (success) {
        cout << "删除用户成功！\n";
    } else {
        cout << "删除用户失败！\n";
    }
}

//管理员恢复学校用户默认密码
void Administrator::resetCommonUser() {
    auto cp = new CommonUser();
    string resetUsername;
    bool success = false;
    cout << "请输入您想重置的账户的用户名\n";
    cin >> resetUsername;
    vector<CommonUser> CuList;
    CuList.clear();
    FILE *fp = fopen("CommonUser.bin", "rb+");
    while (true) {
        if (!fread(cp, sizeof(CommonUser), 1, fp)) {
            delete cp;
            break;
        }
        if (cp->getUsername() == resetUsername) {
            cp->resetPassword();
            success = true;
        }
        CuList.push_back(*cp);
    }
    fclose(fp);
    remove("CommonUser.bin");
    fp = fopen("CommonUser.bin", "ab+");
    fwrite(&CuList[0], CuList.size() * sizeof(CommonUser), 1, fp);
    fclose(fp);
    if (success) {
        cout << "重置用户成功！\n";
    } else {
        cout << "重置用户失败！\n";
    }
}

//管理员修改图书信息
void Administrator::modifyBook() {
    bool success = false;
    auto book = new Book();
    cout << "请输入您想要修改的图书的名字、作者或者ISBN编号：\n";
    string message;
    cin >> message;
    vector<Book> BookList;
    BookList.clear();
    FILE *fp = fopen("books.txt", "r+");
    while (true) {
        if (!fread(book, sizeof(Book), 1, fp)) {
            delete book;
            break;
        }
        if (book->GetTitle() == message || book->GetIsbn() == message || book->GetAuthor() == message) {
            char judge;
            book->DisplayBook();
            cout << "请问是否需要修改本书？  （Y/N）\n";
            cin >> judge;
            if (judge == 'Y') {
                cout << "请输入修改后的书籍信息：\n";
                book->InputBook();
                success = true;
            }
        }
        BookList.push_back(*book);
    }
    fclose(fp);
    remove("books.txt");
    fp = fopen("books.txt", "ab+");
    fwrite(&BookList[0], BookList.size() * sizeof(Book), 1, fp);
    fclose(fp);
    if (success) {
        cout << "修改成功！\n";
    } else {
        cout << "修改失败！\n";
    }
}

//管理员增加图书
void Administrator::addBook() {
    int num;
    cout << "请问您想添加几本图书？";
    cin >> num;
    for (int i = 1; i <= num; i++) {
        auto book = new Book(i);
        FILE *fp = fopen("books.txt", "a+");
        fprintf(fp, "%s %s %s %s/%s %d",
                book->GetTitle().c_str(), book->GetIsbn().c_str(), book->GetAuthor().c_str(),
                book->GetClass1().c_str(), book->GetClass2().c_str(), book->GetNumber());
        fclose(fp);
        delete book;
    }

}

//管理员删除图书
void Administrator::deleteBook() {
    bool success = false;
    auto book = new Book();
    cout << "请输入您想要删除的图书的名字、作者或者ISBN编号：\n";
    string message;
    cin >> message;
    vector<Book> BookList;
    BookList.clear();
    FILE *fp = fopen("books.txt", "r+");
    while (true) {
        if (!fread(book, sizeof(Book), 1, fp)) {
            delete book;
            break;
        }
        if (book->GetTitle() == message || book->GetIsbn() == message || book->GetAuthor() == message) {
            char judge;
            book->DisplayBook();
            cout << "请问是否需要修改本书？  （Y/N）\n";
            cin >> judge;
            if (judge == 'Y') {
                success = true;
            } else {
                BookList.push_back(*book);
            }
        } else {
            BookList.push_back(*book);
        }
    }
    fclose(fp);
    remove("books.txt");
    fp = fopen("books.txt", "ab+");
    fwrite(&BookList[0], BookList.size() * sizeof(Book), 1, fp);
    fclose(fp);
    if (success) {
        cout << "删除成功！\n";
    } else {
        cout << "删除失败！\n";
    }
}

void Administrator::exitSystem() {
    vector<Administrator> AdList;
    AdList.clear();
    auto ap = new Administrator();
    FILE *fp = fopen("Administrator.bin", "rb+");
    while (true) {
        if (!fread(ap, sizeof(Administrator), 1, fp)) {
            delete ap;
            break;
        }
        if (ap->getUsername() == m_username) {
            *ap = *this;
        }
        AdList.push_back(*ap);
    }
    fclose(fp);
    remove("Administrator.bin");
    fp = fopen("Administrator.bin", "ab+");
    fwrite(&AdList[0], AdList.size() * sizeof(Administrator), 1, fp);
    fclose(fp);
}

int main() {
    Administrator(1);
}