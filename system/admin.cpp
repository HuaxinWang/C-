#include "admin.h"
#include "costomer.h"
#include "book.h"

Admin::Admin(string name,string pwd)
{
    m_strName = name;
    m_strPwd = pwd;
}
string Admin::getName()
{
    return m_strName;
}
string Admin::getPwd()
{
    return m_strPwd;
}
void Admin::adminMenu()
{
    while(1)
    {
        cout << "----------------------------------------------------------------------------------" << endl;
        cout << "欢迎 admin 登录" << endl;
        cout << "1-->对会员信息进行操作" << endl;
        cout << "2-->对书籍信息进行操作" << endl;
        cout << "0-->返回登录界面" << endl;
        cout << "请输入你的选择：";
        int num;
        cin >> num;
        switch(num)
        {
            case 1:
                admin_costomer_menu();
                break;
            case 2:
                admin_book_menu();
                break;
            case 0:
                return;
            default:
                cout << "输入有误，请重新输入！！！" << endl;
                break;
        }
    }
}

void Admin::admin_costomer_menu()
{
    while(1)
    {
        cout << "----------------------------------------------------------------------------------" << endl;
        cout << "1-->添加会员信息" << endl;
        cout << "2-->删除会员信息" << endl;
        cout << "3-->修改会员信息" << endl;
        cout << "4-->查询会员信息" << endl;
        cout << "5-->重置会员密码" << endl;
        cout << "0-->返回上一层" << endl;
        cout << "请输入你的选择：";
        int num;
        cin >> num;
        Costomer cos;
        switch(num)
        {
            case 1:
                cos.addCostomer();
                break;
            case 2:
                cos.delCostomer();
                break;
            case 3:
                cos.updateCostomer();
                break;
            case 4:
                cos.showCostomer();
                break;
            case 5:
                cos.initPwd();
                break;
            case 0:
                return;
            default:
                cout << "输入有误，请重新输入！！！" << endl;
                break;
        }
    }
}


void Admin::admin_book_menu()
{
    while(1)
    {
        cout << "----------------------------------------------------------------------------------" << endl;
        cout << "1-->添加书籍信息" << endl;
        cout << "2-->删除书籍信息" << endl;
        cout << "3-->修改书籍信息" << endl;
        cout << "4-->查询书籍信息" << endl;
        cout << "0-->返回上一层" << endl;
        cout << "请输入你的选择：";
        int num;
        cin >> num;
        Book book;
        switch(num)
        {
            case 1:
                book.addBook();
                break;
            case 2:
                book.delBook();    
                break;
            case 3:
                book.updateBook();
                break;
            case 4:
                book.showBook();
                break;
            case 0:
                return;
            default:
                cout << "输入有误，请重新输入！！！" << endl;
                break;
        }
    }
}
