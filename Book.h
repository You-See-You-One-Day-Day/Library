//
// Created by 王雨梦 on 2021/1/7.
//

#ifndef LIBRARY_BOOK_H
#define LIBRARY_BOOK_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;


class Book {
    //构造Book类

public:
    Book() = default;

    explicit Book(int);

    explicit Book(const string &);


    ~Book() = default;

public:
    [[nodiscard]] string GetTitle() const;                // 获取图书名称

    [[nodiscard]]  string GetIsbn() const;                // 获取图书ISBN编号

    [[nodiscard]]  string GetAuthor() const;              // 获取图书作者

    [[nodiscard]] int GetNumber() const;

    [[nodiscard]] string IntoString() const;

    [[nodiscard]] string GetClass() const;

    [[nodiscard]] string IntoString(int) const;

    static void BookInit();

    static void ClearLines();

    void InputBook();

    [[maybe_unused]] void DisplayBook() const;   // 查看图书的信息

    bool BeBorrowed();

    bool BeReturned();

    static void QuickInput();

protected:
    string m_title;
    string m_isbn;
    string m_author;
    int m_number = 0;
    string m_class;

};

#endif //LIBRARY_BOOK_H
