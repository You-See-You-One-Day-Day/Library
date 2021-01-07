//
// Created by 王雨梦 on 2021/1/7.
//

#include "Booklist.h"
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<cstring>
#include<string.h>

using namespace std;


book::book(char* name, char* isbn, char* author)
{
    strncpy(m_title, title, num1);
    strncpy(m_isbn, isbn, num1);
    strncpy(m_author, author, num2);
    //运用strncpy函数将title中的字符串复制到m_title里面去，num指复制的字符串长度
}

char* book::GetTitle()
{
    return m_title;
}

void book::SetTitle(char* title)
{
    strncpy(m_title, title, num1);
}

char* book::GetIsbn()
{
    return m_isbn;
}

void book::SetIsbn(char* isbn)
{
    strncpy(m_isbn, isbn, num1);
}

char* book::GetAuthor()
{
    return m_author;
}

void book::SetAuthor(char* author)
{
    strncpy(m_author, author, num2);
}


// 函数GetBook

// 成员函数GetBook能够实现从文件中读取数据来构建对象。
void book::GetBook(int count)
{
    char title[num1];
    char isbn[num1];
    char author[num2];

    ifstream File;
    File.open("books 2.txt", ios::binary);
    try
    {
        File.seekg(count*(num1 + num1 + num2), ios::beg);
        File.read(title, num1);
        if (File.tellg() > 0)
            strncpy(m_title, title, num1);
        File.read(isbn, num1);
        if (File.tellg() > 0)
            strncpy(m_isbn, isbn, num1);
        File.read(author, num2);
        if (File.tellg() > 0)
            strncpy(m_author, author, num2);
    }
    catch (...)
    {
        throw "file error occurred";
        File.close();
    }
    File.close();
}

