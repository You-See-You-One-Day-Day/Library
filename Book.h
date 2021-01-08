//
// Created by 王雨梦 on 2021/1/7.
//

#ifndef LIBRARY_BOOK_H
#define LIBRARY_BOOK_H

#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<cstring>
#include<cstring>
#include <algorithm>
#include <vector>

using namespace std;


class Book {
    //构造Book类

public:
    Book() = default;

    explicit Book(int);


    ~Book() = default;

public:
    [[nodiscard]] string GetTitle() const;                // 获取图书名称

    [[nodiscard]] string GetIsbn() const;                // 获取图书ISBN编号

    [[nodiscard]] string GetAuthor() const;              // 获取图书作者

    [[nodiscard]] string GetClass1() const;

    [[nodiscard]] string GetClass2() const;

    [[nodiscard]] int GetNumber() const;

    [[nodiscard]] string IntoString() const;

    [[nodiscard]] string GetClass() const;
//    static void BookInit();

    void InputBook();

    void DisplayBook() const;   // 查看图书的信息

    bool BeBorrowed();

    bool BeReturned();


protected:
    string m_title;
    string m_isbn;
    string m_author;
    int m_number{};
    char m_class1[128]{};
    char m_class2[128]{};
    string m_class;

};

#endif //LIBRARY_BOOK_H
