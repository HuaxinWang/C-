#include "costomer.h"
#include<mysql/mysql.h>
#include<stdlib.h>
#include<stdio.h>
#include <string.h>
#include <ctime>
int Costomer::costomerId = 1000;

int Costomer::getId()
{
    return costomerId;
}

string Costomer::getName()
{
    return m_strName;
}
string Costomer::getPwd()
{
    return m_strPwd;
}
string Costomer::getLevel()
{
    return m_strLevel;
}
string Costomer::getPhone()
{
    return m_strPhone;
}
string Costomer::getAddr()
{
    return m_strAddr;
}
void Costomer::setId(int id)
{
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
    if(mysql_query(conn,"select max(ID) from costomer"))
    {
        cout<<"数据库指令发送失败"<<endl;
        return;
    }
    res=mysql_use_result(conn);
    while((row=mysql_fetch_row(res))!=NULL)
    {
        id = atoi(row[0]);
    }
    mysql_free_result(res);
    mysql_close(conn);
    costomerId = id + 1;
}
void Costomer::setName(string name)
{
    m_strName = name;
}
void Costomer::setPwd(string pwd)
{
    m_strPwd = pwd;
}
void Costomer::setLevel(string level)
{
    m_strLevel = level;
}
void Costomer::setPhone(string phone)
{
    m_strPhone = phone;
}
void Costomer::setAddr(string addr)
{
    m_strAddr = addr;
}
void Costomer::costomerMenu(int id)
{
    while(1)
    {
        cout << "----------------------------------------------------------------------------------" << endl;
        cout << "1-->选购图书" << endl;
        cout << "2-->查看自己的购买记录" << endl;
        cout << "0-->返回登录界面" << endl;
        cout << "请输入你的选择：";
        int num;
        cin >> num;
        switch(num)
        {
            case 1:
                buyBook();
                break;
            case 2:
                show_history(id);
                break;
            case 0:
                return;
            default:
                cout << "输入有误，请重新输入！！！" << endl;
                break;
        }
    }
}

int Costomer::buyBook()
{
    while(1)
    {
        cout << "----------------------------------------------------------------------------------" << endl;
        cout << "1-->浏览书籍信息并购买" << endl;
        cout << "0-->返回上一层" << endl;
        cout << "请输入你的选择：";
        int num;
        cin >> num;
        MYSQL_RES *res;
        MYSQL_ROW row;
        MYSQL * conn = NULL;	
        conn = mysql_init(NULL); //初始化句柄
        if(conn == NULL)
        {
            cout<<"数据库初始化失败"<<endl;
            return -1;
        }
        const char *host = "localhost";  //主机
        const char *user = "root";       //用户名
        const char *pwd = "1";      //用户密码
        const char *db = "system"; //数据库名称
        conn = mysql_real_connect(conn,host,user,pwd,db,0,NULL,0);  //连接
        if(conn == NULL)
        {
            cout<<"连接数据库失败"<<endl;
            return -1;
        }
        mysql_set_character_set(conn,"utf8");
        switch(num)
        {
            case 1:
            {
                if(mysql_query(conn,"select * from book order by 书名"))
                {
                    cout<<"数据库指令发送失败"<<endl;
                    return -1;
                }
                res=mysql_use_result(conn);
                cout << "----------------------------------------------------------------------------------" << endl;
                printf("书名\t作者\t出版社\t价钱\n");
                while((row=mysql_fetch_row(res))!=NULL)
                {
                    printf("%s\t%s\t%s\t%s\n",row[0],row[1],row[2],row[3]);
                }
                cout << "----------------------------------------------------------------------------------" << endl;
                mysql_free_result(res);
                cout << "你想要购买的书籍书名为：";
                string buyBookName;
                cin >> buyBookName;
                cout << "该书籍的购买数量为：";
                int buyNum;
                cin >> buyNum;
                cout << "请输入你的ID确认身份：";
                int tmpId;
                cin >> tmpId;
                cout << "请确认你的基本信息和购买书籍的基本信息：" << endl;
                char buff[1024] = {'\0'};
                sprintf(buff,"select * from costomer where ID=%d",tmpId);
                if(mysql_query(conn,buff))
                {
                    cout<<"数据库指令发送失败"<<endl;
                    return -1;
                }
                res=mysql_use_result(conn);
                cout << "----------------------------------------------------------------------------------" << endl;
                printf("ID\t姓名\t密码\t会员等级\t联系电话\t邮购地址\n");
                string isVip;
                while((row=mysql_fetch_row(res))!=NULL)
                {
                    printf("%s\t%s\t%s\t%s\t\t%s\t%s\n",row[0],row[1],row[2],row[3],row[4],row[5]);
                    isVip = row[3];
                }
                cout << "----------------------------------------------------------------------------------" << endl;
                mysql_free_result(res);
                char buff1[1024] = {'\0'};
                sprintf(buff1,"select * from book where 书名='%s'",buyBookName.data());
                if(mysql_query(conn,buff1))
                {
                    cout<<"数据库指令发送失败"<<endl;
                    return -1;
                }
                res=mysql_use_result(conn);
                cout << "----------------------------------------------------------------------------------" << endl;
                printf("书名\t作者\t出版社\t价钱\n");
                float danjia = 0.00;
                while((row=mysql_fetch_row(res))!=NULL)
                {
                    printf("%s\t%s\t%s\t%s\n",row[0],row[1],row[2],row[3]);
                    danjia = atof(row[3]);
                }
                cout << "----------------------------------------------------------------------------------" << endl;
                cout << "确认信息无误？ y/n  ";
                string choice;
                cin >> choice;
                if("y" == choice)
                {
                    if("vip" == isVip)
                    {
                        float price;
                        float discount = 0.95;
                        price = danjia*discount*buyNum;
                        cout << "vip用户享受所有书籍" << discount << "折优惠" << endl;
                        int youfei = 0;
                        if(100 < price)
                        {   
                            cout << "满100元包邮" << endl;
                        }
                        else
                        {
                            cout << "未购买100元，需付邮费10元" << endl;
                            youfei = youfei+10;
                            price  = price + youfei;
                        }
                        cout << "----------------------------------------------------------------------------------" << endl;
                        printf("ID\t书籍\t折扣\t邮费\t总额\n");
                        cout << tmpId << '\t'
                             << buyBookName << '\t'
                             << discount << '\t'
                             << youfei << '\t'
                             << price << endl;
                        cout << "----------------------------------------------------------------------------------" << endl;                        
                        cout << "确认购买？ y/n  ";
                        string buyChoice;
                        cin >> buyChoice;
                        if("y" == buyChoice)
                        {
                            time_t t;
                            t = time(&t);
                            string time = ctime(&t);
                            strtok((char *)time.data(),"\n");
                            char buff[1024] = {'\0'};
                            char buf[100] = "insert into history values(";
                            sprintf(buff,"%s%d,'%s',%f,%d,%f,'%s')",buf,tmpId,buyBookName.data(),discount,youfei,price,time.data());
                            mysql_query(conn,buff);
                            cout << "支付成功！！！" << endl;
                        }
                        else
                        {
                            cout << "支付失败，订单取消" << endl;
                        }                      
                    }
                    else
                    {
                        float price;
                        float discount = 0.95;
                        price = danjia*buyNum;
                        int youfei = 0;
                        if(100 < price)
                        {   
                            cout << "普通用户享受满100元" << discount << "折优惠" << endl;
                            price = price*discount;
                            if(150 < price)
                            {
                                cout << "满150包邮" << endl;
                            }
                            else
                            {
                                youfei = youfei+10;
                                price  = price + youfei;
                            }
                        }
                        else
                        {
                            cout << "未购买100元，不享受折扣以及包邮优惠" << endl;
                            discount = 1;
                            youfei = youfei+10;
                            price  = price + youfei;
                        }
                        cout << "----------------------------------------------------------------------------------" << endl;                        
                        printf("ID\t书籍\t折扣\t邮费\t总额\n");
                        cout << tmpId << '\t'
                             << buyBookName << '\t'
                             << discount << '\t'
                             << youfei << '\t'
                             << price << endl;
                        cout << "----------------------------------------------------------------------------------" << endl;                        
                        cout << "确认购买？ y/n  ";
                        string buyChoice;
                        cin >> buyChoice;
                        if("y" == buyChoice)
                        {
                            time_t t;
                            t = time(&t);
                            string time = ctime(&t);
                            strtok((char *)time.data(),"\n");
                            char buff[1024] = {'\0'};
                            char buf[100] = "insert into history values(";
                            sprintf(buff,"%s%d,'%s',%f,%d,%f,'%s')",buf,tmpId,buyBookName.data(),discount,youfei,price,time.data());
                            mysql_query(conn,buff);
                            cout << "支付成功！！！" << endl;
                        }
                        else
                        {
                            cout << "支付失败，订单取消" << endl;
                        } 
                    }
                }
                mysql_free_result(res);
                mysql_close(conn);
                break;
            }
            case 0:
                mysql_close(conn);
                return -1;
            default:
                mysql_close(conn);
                cout << "输入有误，请重新输入！！！" << endl;
                break;
        }
    }
}

ostream &operator<<(ostream &out,Costomer *costomer)
{
    out << "ID：" << costomer->getId() << endl
        << "姓名：" << costomer->getName() << endl
        << "密码：" << costomer->getPwd() << endl
        << "会员等级：" << costomer->getLevel() << endl
        << "联系电话：" << costomer->getPhone() << endl
        << "邮购地址：" << costomer->getAddr() << endl; 
	return out;
}

void Costomer::addCostomer()
{
    while(1)
    {
        Costomer *cos = new Costomer();
        cos->setId(costomerId);
        cout << "请输入会员姓名：";
        string name;
        cin >> name;
        cos->setName(name);
        cout << "请设置会员密码：";
        string pwd;
        cin >> pwd;
        cos->setPwd(pwd);
        cout << "请设置会员等级（普通/vip）：";
        string level;
        cin >> level;
        cos->setLevel(level);
        cout << "请输入会员联系电话:";
        string phone;
        cin >> phone;
        cos->setPhone(phone);
        cout << "请输入会员邮购地址：";
        string addr;
        cin >> addr;
        cos->setAddr(addr);
        cout << "请核对该会员信息" << endl;
        list<Costomer *> costomer_list;
        costomer_list.push_back(cos);
        list<Costomer *>::iterator iter = costomer_list.begin();
        cout << "----------------------------------------------------------------------------------" << endl;        
        for(;iter != costomer_list.end();iter++)
        {
            cout << *iter << endl;
        }
        cout << "----------------------------------------------------------------------------------" << endl;        
        cout << "y-->确认无误，提交信息" << endl;
        cout << "n-->输入有误，重新输入" << endl;
        string choice;
        cin >> choice;
        if("n" == choice)
        {
            continue;
        }
        save_costomer_to_mysql(costomer_list);
        cout << "添加成功！！！" << endl;
        cout << "y-->继续添加" << endl;
        cout << "n-->返回上一层" << endl;
        string choice1;
        cin >> choice1;
        if("n" == choice1)
        {
            delete cos;
            cos = NULL;
            return;
        }
    }
}


int Costomer::delCostomer()
{
    while(1)
    {
        cout << "----------------------------------------------------------------------------------" << endl;        
        cout << "1-->输入ID删除会员信息" << endl;
        cout << "0-->返回上一层" << endl;
        cout << "请输入你的选择：";
        int num;
        cin >> num;
        MYSQL_RES *res;
        MYSQL_ROW row;
        MYSQL * conn = NULL;	
        conn = mysql_init(NULL); //初始化句柄
        if(conn == NULL)
        {
            cout<<"数据库初始化失败"<<endl;
            return -1;
        }
        const char *host = "localhost";  //主机
        const char *user = "root";       //用户名
        const char *pwd = "1";      //用户密码
        const char *db = "system"; //数据库名称
        conn = mysql_real_connect(conn,host,user,pwd,db,0,NULL,0);  //连接
        if(conn == NULL)
        {
            cout<<"连接数据库失败"<<endl;
            return -1;
        }
        mysql_set_character_set(conn,"utf8");
        switch(num)
        {
            case 1:
            {
                int searchId;
                cout << "请输入想要删除的会员ID：";
                cin >> searchId;
                cout << "该会员的已有信息如下：" << endl;
                char buff[1024] = {'\0'};
                sprintf(buff,"select * from costomer where ID=%d",searchId);
                if(mysql_query(conn,buff))
                {
                    cout<<"数据库指令发送失败"<<endl;
                    return -1;
                }
                res=mysql_use_result(conn);
                cout << "----------------------------------------------------------------------------------" << endl;                
                printf("ID\t姓名\t密码\t会员等级\t联系电话\t邮购地址\n");
                while((row=mysql_fetch_row(res))!=NULL)
                {
                    printf("%s\t%s\t%s\t%s\t\t%s\t%s\n",row[0],row[1],row[2],row[3],row[4],row[5]);
                }
                cout << "----------------------------------------------------------------------------------" << endl;                
                cout << "确认删除吗？ y/n\t";
                string choice;
                cin >> choice;
                if("y" == choice)
                {
                    char buff[1024] = {'\0'};
                    sprintf(buff,"delete from costomer where ID=%d",searchId);
                    if(mysql_query(conn,buff))
                    {
                        cout<<"数据库指令发送失败"<<endl;
                        return -1;
                    }
                    cout << "成功删除该会员信息" << endl;
                }
                else
                {
                    cout << "取消删除" << endl;
                    break;
                }
                mysql_free_result(res);
                mysql_close(conn);
                break;
            }
            case 0:
                mysql_close(conn);
                return -1;
            default:
                mysql_close(conn);
                cout << "输入有误，请重新输入！！！" << endl;
                break;
        }
    }
}

int Costomer::updateCostomer()
{
    while(1)
    {
        cout << "----------------------------------------------------------------------------------" << endl;        
        cout << "1-->按编号修改会员信息" << endl;
        cout << "2-->按姓名修改会员信息" << endl;
        cout << "0-->返回上一层" << endl;
        cout << "请输入你的选择：";
        int num;
        cin >> num;
        MYSQL_RES *res;
        MYSQL_ROW row;
        MYSQL * conn = NULL;	
        conn = mysql_init(NULL); //初始化句柄
        if(conn == NULL)
        {
            cout<<"数据库初始化失败"<<endl;
            return -1;
        }
        const char *host = "localhost";  //主机
        const char *user = "root";       //用户名
        const char *pwd = "1";      //用户密码
        const char *db = "system"; //数据库名称
        conn = mysql_real_connect(conn,host,user,pwd,db,0,NULL,0);  //连接
        if(conn == NULL)
        {
            cout<<"连接数据库失败"<<endl;
            return -1;
        }
        mysql_set_character_set(conn,"utf8");
        switch(num)
        {
            case 1:
            {   
                int searchId;
                cout << "请输入想要修改的会员的ID：";
                cin >> searchId;
                cout << "该会员的已有信息如下：" << endl;
                char buff[1024] = {'\0'};
                sprintf(buff,"select * from costomer where ID=%d",searchId);
                if(mysql_query(conn,buff))
                {
                    cout<<"数据库指令发送失败"<<endl;
                    return -1;
                }
                res=mysql_use_result(conn);
                cout << "----------------------------------------------------------------------------------" << endl;                
                printf("ID\t姓名\t密码\t会员等级\t联系电话\t邮购地址\n");
                while((row=mysql_fetch_row(res))!=NULL)
                {
                    printf("%s\t%s\t%s\t%s\t\t%s\t%s\n",row[0],row[1],row[2],row[3],row[4],row[5]);
                }
                cout << "----------------------------------------------------------------------------------" << endl;
                while(1)
                {
                    cout << "修改  1->姓名  2->密码  3->会员等级  4->联系电话  5->邮购地址  0->退出修改" << endl;
                    cout << "请选择：";
                    int choice;
                    cin >> choice;
                    switch(choice)
                    {
                        case 1:
                        {
                            string newName;
                            cout << "请输入新的姓名：";
                            cin >> newName;
                            char buff[1024] = {'\0'};
                            sprintf(buff,"update costomer set 姓名='%s' where ID=%d",newName.data(),searchId);
                            if(mysql_query(conn,buff))
                            {
                                cout<<"数据库指令发送失败"<<endl;
                                return -1;
                            }
                            cout << "修改成功，新的姓名为：" << newName << endl;
                            break;
                        }
                        case 2:
                        {
                            string newPwd;
                            cout << "请输入新的密码：";
                            cin >> newPwd;
                            char buff[1024] = {'\0'};
                            sprintf(buff,"update costomer set 密码='%s' where ID=%d",newPwd.data(),searchId);
                            if(mysql_query(conn,buff))
                            {
                                cout<<"数据库指令发送失败"<<endl;
                                return -1;
                            }
                            cout << "修改成功，新的密码为：" << newPwd << endl;
                            break;
                        }
                        case 3:
                        {
                            string newLevel;
                            cout << "请输入新的会员等级：";
                            cin >> newLevel;
                            char buff[1024] = {'\0'};
                            sprintf(buff,"update costomer set 会员等级='%s' where ID=%d",newLevel.data(),searchId);
                            if(mysql_query(conn,buff))
                            {
                                cout<<"数据库指令发送失败"<<endl;
                                return -1;
                            }
                            cout << "修改成功，新的会员等级为：" << newLevel << endl;
                            break;
                        }
                        case 4:
                        {
                            string newPhone;
                            cout << "请输入新的联系电话：";
                            cin >> newPhone;
                            char buff[1024] = {'\0'};
                            sprintf(buff,"update costomer set 联系电话='%s' where ID=%d",newPhone.data(),searchId);
                            if(mysql_query(conn,buff))
                            {
                                cout<<"数据库指令发送失败"<<endl;
                                return -1;
                            }
                            cout << "修改成功，新的联系电话为：" << newPhone << endl;
                            break;
                        }
                        case 5:
                        {
                            string newAddr;
                            cout << "请输入新的邮购地址：";
                            cin >> newAddr;
                            char buff[1024] = {'\0'};
                            sprintf(buff,"update costomer set 邮购地址='%s' where ID=%d",newAddr.data(),searchId);
                            if(mysql_query(conn,buff))
                            {
                                cout<<"数据库指令发送失败"<<endl;
                                return -1;
                            }
                            cout << "修改成功，新的邮购地址为：" << newAddr << endl;
                            break;
                        } 
                        case 0:
                            return -1;
                        default:
                            cout << "输入有误，请重新输入！！！" << endl;
                            break;
                    }
                }
                mysql_free_result(res);
                mysql_close(conn);
                break;
            }
            case 2:
            {
                string searchName;
                cout << "请输入想要要修改的会员的姓名：";
                cin >> searchName;
                cout << "该会员的已有信息如下：" << endl;
                char buff[1024] = {'\0'};
                sprintf(buff,"select * from costomer where 姓名='%s'",searchName.data());
                if(mysql_query(conn,buff))
                {
                    cout<<"数据库指令发送失败"<<endl;
                    return -1;
                }
                res=mysql_use_result(conn);
                cout << "----------------------------------------------------------------------------------" << endl;                
                printf("ID\t姓名\t密码\t会员等级\t联系电话\t邮购地址\n");
                while((row=mysql_fetch_row(res))!=NULL)
                {
                    printf("%s\t%s\t%s\t%s\t\t%s\t%s\n",row[0],row[1],row[2],row[3],row[4],row[5]);
                }
                cout << "----------------------------------------------------------------------------------" << endl;                
                while(1)
                {
                    cout << "修改  1->密码  2->会员等级  3->联系电话  4->邮购地址  0->退出修改" << endl;
                    cout << "请选择：";
                    int choice;
                    cin >> choice;
                    switch(choice)
                    {
                        case 1:
                        {
                            string newPwd;
                            cout << "请输入新的密码：";
                            cin >> newPwd;
                            char buff[1024] = {'\0'};
                            sprintf(buff,"update costomer set 密码='%s' where 姓名='%s'",newPwd.data(),searchName.data());
                            if(mysql_query(conn,buff))
                            {
                                cout<<"数据库指令发送失败"<<endl;
                                return -1;
                            }
                            cout << "修改成功，新的密码为：" << newPwd << endl;
                            break;
                        }
                        case 3:
                        {
                            string newLevel;
                            cout << "请输入新的会员等级：";
                            cin >> newLevel;
                            char buff[1024] = {'\0'};
                            sprintf(buff,"update costomer set 会员等级='%s' where 姓名='%s'",newLevel.data(),searchName.data());
                            if(mysql_query(conn,buff))
                            {
                                cout<<"数据库指令发送失败"<<endl;
                                return -1;
                            }
                            cout << "修改成功，新的会员等级为：" << newLevel << endl;
                            break;
                        }
                        case 4:
                        {
                            string newPhone;
                            cout << "请输入新的联系电话：";
                            cin >> newPhone;
                            char buff[1024] = {'\0'};
                            sprintf(buff,"update costomer set 联系电话='%s' where 姓名='%s'",newPhone.data(),searchName.data());
                            if(mysql_query(conn,buff))
                            {
                                cout<<"数据库指令发送失败"<<endl;
                                return -1;
                            }
                            cout << "修改成功，新的联系电话为：" << newPhone << endl;
                            break;
                        }
                        case 5:
                        {
                            string newAddr;
                            cout << "请输入新的邮购地址：";
                            cin >> newAddr;
                            char buff[1024] = {'\0'};
                            sprintf(buff,"update costomer set 邮购地址='%s' where 姓名='%s'",newAddr.data(),searchName.data());
                            if(mysql_query(conn,buff))
                            {
                                cout<<"数据库指令发送失败"<<endl;
                                return -1;
                            }
                            cout << "修改成功，新的邮购地址为：" << newAddr << endl;
                            break;
                        } 
                        case 0:
                            return -1;
                        default:
                            cout << "输入有误，请重新输入！！！" << endl;
                            break;
                    }
                }
                mysql_free_result(res);
                mysql_close(conn);
                break;
            }
            case 0:
                mysql_close(conn);
                return -1;
            default:
                mysql_close(conn);
                cout << "输入有误，请重新输入！！！" << endl;
                break;
        }
    }
}

int Costomer::showCostomer()
{
    while(1)
    {
        cout << "----------------------------------------------------------------------------------" << endl;        
        cout << "1-->按编号顺序显示会员信息" << endl;
        cout << "2-->按级别顺序显示会员信息" << endl;
        cout << "0-->返回上一层" << endl;
        cout << "请输入你的选择：";
        int num;
        cin >> num;
        MYSQL_RES *res;
        MYSQL_ROW row;
        MYSQL * conn = NULL;	
        conn = mysql_init(NULL); //初始化句柄
        if(conn == NULL)
        {
            cout<<"数据库初始化失败"<<endl;
            return -1;
        }
        const char *host = "localhost";  //主机
        const char *user = "root";       //用户名
        const char *pwd = "1";      //用户密码
        const char *db = "system"; //数据库名称
        conn = mysql_real_connect(conn,host,user,pwd,db,0,NULL,0);  //连接
        if(conn == NULL)
        {
            cout<<"连接数据库失败"<<endl;
            return -1;
        }
        mysql_set_character_set(conn,"utf8");
        switch(num)
        {
            case 1:
                if(mysql_query(conn,"select * from costomer order by ID"))
                {
                    cout<<"数据库指令发送失败"<<endl;
                    return -1;
                }
                res=mysql_use_result(conn);
                cout << "----------------------------------------------------------------------------------" << endl;                
                printf("ID\t姓名\t密码\t会员等级\t联系电话\t邮购地址\n");
                while((row=mysql_fetch_row(res))!=NULL)
                {
                    printf("%s\t%s\t%s\t%s\t\t%s\t%s\n",row[0],row[1],row[2],row[3],row[4],row[5]);
                }
                cout << "----------------------------------------------------------------------------------" << endl;                
                mysql_free_result(res);
                mysql_close(conn);
                break;
            case 2:
                if(mysql_query(conn,"select * from costomer order by 会员等级"))
                {
                    cout<<"数据库指令发送失败"<<endl;
                    return -1;
                }
                res=mysql_use_result(conn);
                cout << "----------------------------------------------------------------------------------" << endl;                
                printf("ID\t姓名\t密码\t会员等级\t联系电话\t邮购地址\n");
                while((row=mysql_fetch_row(res))!=NULL)
                {

                    printf("%s\t%s\t%s\t%s\t\t%s\t%s\n",row[0],row[1],row[2],row[3],row[4],row[5]);
                }
                cout << "----------------------------------------------------------------------------------" << endl;                
                mysql_free_result(res);
                mysql_close(conn);
                break;
            case 0:
                mysql_close(conn);
                return -1;
            default:
                mysql_close(conn);
                cout << "输入有误，请重新输入！！！" << endl;
                break;
        }
    }
}

int Costomer::save_costomer_to_mysql(list<Costomer *> &v)
{
	MYSQL * conn = NULL;	
	conn = mysql_init(NULL); //初始化句柄
	if(conn == NULL)
	{
		cout<<"数据库初始化失败"<<endl;
		return -1;
    }
	const char *host = "localhost";  //主机
	const char *user = "root";       //用户名
	const char *pwd = "1";      //用户密码
	const char *db = "system"; //数据库名称
	conn = mysql_real_connect(conn,host,user,pwd,db,0,NULL,0);  //连接
	if(conn == NULL)
	{
		cout<<"连接数据库失败"<<endl;
		return -1;
    }
    mysql_set_character_set(conn,"utf8");
	const char *q = "use system";
	mysql_real_query(conn, q, strlen(q));
    char buff[1024] = {'\0'};
	char buf[100] = "insert into costomer values(";
	list<Costomer *>::iterator i = v.begin();
	while(i != v.end())
	{
		sprintf(buff,"%s%d,'%s','%s','%s','%s','%s')",buf,
		(*i)->costomerId,
		(*i)->m_strName.data(),
		(*i)->m_strPwd.data(),
        (*i)->m_strLevel.data(),
        (*i)->m_strPhone.data(),
        (*i)->m_strAddr.data());
        mysql_query(conn,buff);
		i++;
	}
    mysql_close(conn);
}

int Costomer::show_history(int id)
{
    MYSQL_RES *res;
    MYSQL_ROW row;
    MYSQL * conn = NULL;	
    conn = mysql_init(NULL); //初始化句柄
    if(conn == NULL)
    {
        cout<<"数据库初始化失败"<<endl;
        return -1;
    }
    const char *host = "localhost";  //主机
    const char *user = "root";       //用户名
    const char *pwd = "1";      //用户密码
    const char *db = "system"; //数据库名称
    conn = mysql_real_connect(conn,host,user,pwd,db,0,NULL,0);  //连接
    if(conn == NULL)
    {
        cout<<"连接数据库失败"<<endl;
        return -1;
    }
    mysql_set_character_set(conn,"utf8");
    char buff[1024] = {'\0'};
    sprintf(buff,"select * from history where ID=%d",id);
    if(mysql_query(conn,buff))
    {
        cout<<"数据库指令发送失败"<<endl;
        return -1;
    }
    res=mysql_use_result(conn);
    cout << "----------------------------------------------------------------------------------" << endl;    
    printf("ID\t书籍\t折扣\t邮费\t总额\t购买时间\n");
    while((row=mysql_fetch_row(res))!=NULL)
    {
        printf("%s\t%s\t%s\t%s\t%s\t%s\n",row[0],row[1],row[2],row[3],row[4],row[5]);
    }
    cout << "----------------------------------------------------------------------------------" << endl;
    mysql_free_result(res);
    mysql_close(conn);
}

int Costomer::initPwd()
{
    cout << "请输入要初始化密码的会员的ID：";
    int initId;
    cin >> initId;
    MYSQL * conn = NULL;	
    conn = mysql_init(NULL); //初始化句柄
    if(conn == NULL)
    {
        cout<<"数据库初始化失败"<<endl;
        return -1;
    }
    const char *host = "localhost";  //主机
    const char *user = "root";       //用户名
    const char *pwd = "1";      //用户密码
    const char *db = "system"; //数据库名称
    conn = mysql_real_connect(conn,host,user,pwd,db,0,NULL,0);  //连接
    if(conn == NULL)
    {
        cout<<"连接数据库失败"<<endl;
        return -1;
    }
    mysql_set_character_set(conn,"utf8");
    char buff[1024] = {'\0'};
    sprintf(buff,"update costomer set 密码='123' where ID=%d",initId);
    if(mysql_query(conn,buff))
    {
        cout<<"数据库指令发送失败"<<endl;
        return -1;
    }
    cout << "ID为" << initId << "的会员的密码已经重置为 123；" << endl;
    mysql_close(conn);
}