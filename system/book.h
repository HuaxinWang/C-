#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include <list>


using namespace std;

class Book
{
public:
    string getName();
    string getAuthor();
    string getPress();
    float getPrice();
    void setName(string name);
    void setAuthor(string author);
    void setPress(string press);
    void setPrice(float price);
    void addBook();
    int delBook();
    int updateBook();
    int showBook();
    int save_book_to_mysql(list<Book *> &v);
private:
    string m_strName;
    string m_strAuthor;
    string m_strPress;
    float m_fPrice;
};
ostream &operator<<(ostream &out, const Book *book);



#endif