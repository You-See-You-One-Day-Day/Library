//
// Created by 王雨梦 on 2021/1/7.
//

#ifndef LIBRARY_BOOKLIST_H
#define LIBRARY_BOOKLIST_H


class book{
    //构造book类

public:
    book() {}
    book(char* title, char* isbn, char* author);
    ~book() {}
public:
    char*  GetTitle();                // 获取图书名称
    void  SetTitle(char* title);       // 设置图书名称
    char*  GetIsbn();                // 获取图书ISBN编号
    void  SetIsbn(char* isbn);       // 设置图书ISBN编号
    char*  GetAuthor();              // 获取图书作者
    void  SetAuthor(char* author);    // 设置图书作者
    void  WriteData();               // 写入图书
    void  DeleteData(int iCount);    // 删除图书
    void  GetBookFromFile(int iCount);   // 查看图书的信息
protected:
    char m_title[NUM1];
    char m_isbn[NUM1];
    char m_author[NUM2];
};

#endif //LIBRARY_BOOKLIST_H
