//
// Created by 王雨梦 on 2021/1/7.
//

#include "Book.h"


using namespace std;

Book::Book(int num) {
    cout << "您正在创建第" << num << "图书\n";
    InputBook();
}


string Book::GetTitle() const {
    return m_title;
}


string Book::GetIsbn() const {
    return m_isbn;
}


string Book::GetAuthor() const {
    return m_author;
}

string Book::GetClass1() const {
    return m_class1;
}

string Book::GetClass2() const {
    return m_class2;
}

int Book::GetNumber() const {
    return m_number;
}

void Book::InputBook() {
    cout << "请输入书名：\n";
    cin >> m_title;
    cout << "请输入ISBN编号：\n";
    cin >> m_isbn;
    cout << "请输入作者：\n";
    cin >> m_author;
    cout << "请输入分类号：\n";
    m_class = to_string(scanf("%s/%s", m_class1, m_class2));
    cout << "请输入书的数量：\n";
    cin >> m_number;
}

void Book::DisplayBook() const {
    cout << setw(40) << left << "《" << GetTitle() << "》" << setw(20) << left
         << "ISBN：" << GetIsbn() << setw(30) << left << "作者：" << GetAuthor()
         << setw(20) << left << "数量：" << GetNumber() << endl;
}

//void Book::BookInit() {
//    auto book = new Book;
//    vector<Book> BookList;
//    BookList.clear();
//    FILE *fp = fopen("books.txt", "r+");
//    while (true) {
//        if (!fread(book, sizeof(Book), 1, fp)) {
//            delete book;
//            break;
//        }
//        BookList.push_back(*book);
//    }
//    sort(BookList.begin(), BookList.end());
//}


string Book::IntoString()const {
    string s;
    s = m_title + ' ' + m_isbn + ' ' + m_author + ' ' + m_class;
    return s;
}

bool Book::BeBorrowed() {
    if (m_number <= 0) {
        cout << "对不起，该书已无库存\n";
        return false;
    } else {
        m_number--;
        cout << "借阅成功！\n";
        return true;
    }
}

bool Book::BeReturned() {
    m_number++;
    return true;
}
