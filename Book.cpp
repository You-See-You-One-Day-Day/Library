//
// Created by 王雨梦 on 2021/1/7.
//

#include "Book.h"


using namespace std;

Book::Book(int num) {
    cout << "您正在创建第" << num << "种图书\n";
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


[[maybe_unused]] string Book::GetClass() const {
    return m_class;
}

[[maybe_unused]] int Book::GetNumber() const {
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
    cin >> m_class;
    cout << "请输入书的数量：\n";
    cin >> m_number;
}

[[maybe_unused]] void Book::DisplayBook() const {
    cout << IntoString(1) << endl;
}

string Book::IntoString() const {
    string s;
    s = m_title + ' ' + m_isbn + ' ' + m_author + ' ' + m_class;
    return s;
}

string Book::IntoString(int) const {
    string s;
    s = m_title + ' ' + m_isbn + ' ' + m_author + ' ' + m_class + ' ' + to_string(m_number) + '\n';
    return s;
}

bool Book::BeBorrowed() {
    if (m_number <= 0) {
        cout << "对不起，该书已无库存\n";
        return false;
    } else {
        m_number--;
        vector<string> BookList;
        BookList.clear();
        ifstream ifs;
        ifs.open("books.txt", ios::in);
        string book;
        while (!ifs.eof()) {
            getline(ifs, book);
            istringstream is(book);
            do {
                string word;
                is >> word;
                if (word == m_title || word == m_isbn) {
                    book = IntoString(1);
                    break;
                }
            } while (is);
            BookList.push_back(book);
        }
        ifs.close();
        remove("books.txt");
        ofstream ofs;
        ofs.open("books.txt", ios::app);
        for (auto &i : BookList) {
            ofs << i;
            ofs << endl;

        }
        ofs.close();
        return true;
    }
}

bool Book::BeReturned() {
    m_number++;
    vector<string> BookList;
    BookList.clear();
    ifstream ifs;
    ifs.open("books.txt", ios::in);
    string book;
    while (!ifs.eof()) {
        getline(ifs, book);
        istringstream is(book);
        do {
            string word;
            is >> word;
            if (word == m_title || word == m_isbn) {
                book = IntoString(1);
                break;
            }
        } while (is);
        BookList.push_back(book);
    }
    ifs.close();
    remove("books.txt");
    ofstream ofs;
    ofs.open("books.txt", ios::app);
    for (auto &i : BookList) {
        ofs << i;
        ofs << endl;
    }
    ofs.close();
    return true;
}

Book::Book(const string &book) {
    vector<string> message;
    string result;
    stringstream input(book);
    while (input >> result) {
        message.push_back(result);
    }
    m_title = message[0];
    m_isbn = message[1];
    m_author = message[2];
    m_class = message[3];
    m_number = stoi(message[4]);
}

void Book::BookInit() {
    vector<string> BookList;
    BookList.clear();
    ifstream ifs;
    ifs.open("books.txt", ios::in);
    string book;
    while (!ifs.eof()) {
        getline(ifs, book);
        BookList.push_back(book);
    }
    ifs.close();
    sort(BookList.begin(), BookList.end());
    remove("books.txt");
    ofstream ofs;
    ofs.open("books.txt", ios::app);
    for (auto &i : BookList) {
        ofs << i;
        ofs << endl;

    }
    ofs.close();
}
