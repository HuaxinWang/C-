#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <string>

using namespace std;

class Admin
{
public:
    Admin(string name = "admin",string pwd = "888888");
    string getName();
    string getPwd();
    void adminMenu();
    void admin_costomer_menu();
    void admin_book_menu();
private:
    string m_strName;
    string m_strPwd;
};


#endif