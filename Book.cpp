//
// Created by 王雨梦 on 2021/1/7.
//

#include "Book.h"
#include<iostream>
#include<string>

using namespace std;

Book::Book(int num) {
    cout << "您正在创建第"<<num<<"图书\n";
    cout << "请输入书名：\n";
    cin >> m_title;
    cout << "请输入ISBN编号：\n";
    cin >> m_isbn;
    cout << "请输入作者：\n";
    cin >> m_author;
    cout << "请分别三级输入图书分类（依照《中图法》）：\n";
    cin >> m_class1 >> m_class2 >> m_class3;
}


string Book::GetTitle() {
    return m_title;
}


string Book::GetIsbn() {
    return m_isbn;
}


string Book::GetAuthor() {
    return m_author;
}

string Book::GetClass1(){
    return m_class1;
}

string Book::GetClass2(){
    return m_class2;
}

string Book::GetClass3(){
    return m_class3;
}

// 函数GetBook
/*
// 成员函数GetBook能够实现从文件中读取数据来构建对象。
void Book::GetBook(int count) {
    char title[num1];
    char isbn[num1];
    char author[num2];

    ifstream File;
    File.open("Book 2.txt", ios::binary);
    try {
        File.seekg(count * (num1 + num1 + num2), ios::beg);
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
    catch (...) {
        throw "file error occurred";
        File.close();
    }
    File.close();
}
*/
