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

using namespace std;


class Book {
    //构造Book类

public:
     explicit Book(int);


    ~Book() = default;

public:
    string GetTitle();                // 获取图书名称

    string GetIsbn();                // 获取图书ISBN编号

    string GetAuthor();              // 获取图书作者

    string GetClass1();

    string GetClass2();

    string GetClass3();
//    void DisplayBook(int iCount);   // 查看图书的信息

protected:
    string m_title;
    string m_isbn;
    string m_author;
    string m_class1;
    string m_class2;
    string m_class3;

};

#endif //LIBRARY_BOOK_H
