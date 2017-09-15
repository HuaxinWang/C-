#include "login.h"
#include "admin.h"
#include "costomer.h"
#include "book.h"
#include <mysql/mysql.h>
#include <unistd.h>

void Login::loginMenu()
{
   while(1)
   {
       cout << "----------------------------------------------------------------------------------" << endl;
       cout << "欢迎使用sq图书销售系统" << endl;
       cout << "1-->管理员入口" << endl;
       cout << "2-->会员登录" << endl;
       cout << "0-->退出系统" << endl;
       cout << "请输入你的选择：";
       int num;
       cin >> num;
       switch(num)
       {
           case 1:
                adminLoginMenu();
                break;
           case 2:
                costomerLoginMenu();
                break;
           case 0:
                cout << "谢谢使用！！！" << endl;
                exit(EXIT_SUCCESS);
           default:
                cout << "输入有误，请重新输入！！！" << endl;
                break;
       }
   }
}
void Login::adminLoginMenu()
{
    int i = 2;
    while(1)
    {
        cout << "----------------------------------------------------------------------------------" << endl;
        cout << "请输入管理员账号密码登录" << endl;
        cout << "请输入管理员账号：";
        string count;
        cin >> count;
        cout << "请输入管理员密码：";
        string pwd;
        pwd = getpass("");
        if(count == "admin" && pwd == "888888")
        {
            Admin admin;
            admin.adminMenu();
            return;
        }
        else
        {
            cout << "管理员账号密码不匹配，你还有" << i << "次输入机会！！！" << endl;
            i--;
            if(-1 == i)
            {
                return;
            }
        }
    }
}

void Login::costomerLoginMenu()
{
    int i = 2;
    while(1)
    {
        cout << "----------------------------------------------------------------------------------" << endl;
        cout << "请输入会员账号密码登录" << endl;
        cout << "请输入会员账号：";
        string count;
        cin >> count;
        cout << "请输入会员密码：";
        string mypwd;
        mypwd = getpass("");
        MYSQL_RES *res;
        MYSQL_ROW row;
        MYSQL * conn = NULL;	
        conn = mysql_init(NULL); //初始化句柄
        if(conn == NULL)
        {
            cout<<"数据库初始化失败"<<endl;
            return;
        }
        const char *host = "localhost";  //主机
        const char *user = "root";       //用户名
        const char *pwd = "1";      //用户密码
        const char *db = "system"; //数据库名称
        conn = mysql_real_connect(conn,host,user,pwd,db,0,NULL,0);  //连接
        if(conn == NULL)
        {
            cout<<"连接数据库失败"<<endl;
            return;
        }
        mysql_set_character_set(conn,"utf8");
        if(mysql_query(conn,"select ID,姓名,密码 from costomer"))
        {
            cout<<"数据库指令发送失败"<<endl;
            return;
        }
        res=mysql_use_result(conn);
        while((row=mysql_fetch_row(res))!=NULL)
        {
            if(count == row[0] && mypwd == row[2])
            {
                cout << "----------------------------------------------------------------------------------" << endl;
                cout << "欢迎 " << row[1] << " 进入本系统" << endl;
                Costomer costomer;
                costomer.costomerMenu(atoi(row[0]));
                return;
            }
        } 
        cout << "会员账号密码不匹配，你还有" << i << "次输入机会！！！" << endl;
        i--;
        if(-1 == i)
        {
            return;
        }
        mysql_free_result(res);
        mysql_close(conn);
    }
}