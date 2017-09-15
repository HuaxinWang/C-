#include "book.h"
#include<mysql/mysql.h>
#include <string.h>
#include<stdlib.h>
#include<stdio.h>

string Book::getName()
{
    return m_strName;
}

string Book::getAuthor()
{
    return m_strAuthor;
}
string Book::getPress()
{
    return m_strPress;
}

float Book::getPrice()
{
    return m_fPrice;
}
void Book::setName(string name)
{
    m_strName = name;
}
void Book::setAuthor(string author)
{
    m_strAuthor = author;
}
void Book::setPress(string press)
{
    m_strPress = press;
}
void Book::setPrice(float price)
{
    m_fPrice = price;
}
ostream &operator<<(ostream &out,Book *book)
{
    out << "书名：" << book->getName() << endl
        << "作者：" << book->getAuthor() <<endl
        << "出版社：" << book->getPress() << endl
        << "价钱：" << book->getPrice() << endl;
	return out;
}

int Book::save_book_to_mysql(list<Book *> &v)
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
	char buf[100] = "insert into book values(";
	list<Book *>::iterator i = v.begin();
	while(i != v.end())
	{
		sprintf(buff,"%s'%s','%s','%s',%f)",buf,
        (*i)->m_strName.data(),
        (*i)->m_strAuthor.data(),
        (*i)->m_strPress.data(),
        (*i)->m_fPrice);
        mysql_query(conn,buff);
        i++;
	}
    mysql_close(conn);
}

void Book::addBook()
{
    while(1)
    {
        Book *book = new Book();
        cout << "请输入书籍名称：";
        string name;
        cin >> name;
        book->setName(name);
        cout << "请输入书籍作者：";
        string author;
        cin >> author;
        book->setAuthor(author);
        cout << "请输入书籍出版社：";
        string press;
        cin >> press;
        book->setPress(press);
        cout << "请输入书籍价格:";
        float price;
        cin >> price;
        book->setPrice(price);
        cout << "请核对该书籍信息" << endl;
        list<Book *> book_list;
        book_list.push_back(book);
        list<Book *>::iterator iter = book_list.begin();
        cout << "----------------------------------------------------------------------------------" << endl;
        for(;iter != book_list.end();iter++)
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
        save_book_to_mysql(book_list);
        cout << "添加成功！！！" << endl;
        cout << "y-->继续添加" << endl;
        cout << "n-->返回上一层" << endl;
        string choice1;
        cin >> choice1;
        if("n" == choice1)
        {
            delete book;
            book = NULL;
            return;
        }
    }
}

int Book::delBook()
{
    while(1)
    {
        cout << "----------------------------------------------------------------------------------" << endl;
        cout << "1-->按书名删除书籍信息" << endl;
        cout << "2-->按作者删除书籍信息" << endl;
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
                string bookName;
                cout << "请输入想要删除的书籍名字：";
                cin >> bookName;
                cout << "该书籍的已有信息如下：" << endl;
                char buff[1024] = {'\0'};
                sprintf(buff,"select * from book where 书名='%s'",bookName.data());
                if(mysql_query(conn,buff))
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
                cout << "确认删除吗？ y/n\t";
                string choice;
                cin >> choice;
                if("y" == choice)
                {
                    char buff[1024] = {'\0'};
                    sprintf(buff,"delete from book where 书名='%s'",bookName.data());
                    if(mysql_query(conn,buff))
                    {
                        cout<<"数据库指令发送失败"<<endl;
                        return -1;
                    }
                    cout << "成功删除该书籍信息" << endl;
                }
                else
                {
                    break;
                }
                mysql_free_result(res);
                mysql_close(conn);
                break;
            }
            case 2:
            {
                string authorName;
                cout << "请输入想要删除的书籍的作者名字：";
                cin >> authorName;
                cout << "该书籍的已有信息如下：" << endl;
                char buff[1024] = {'\0'};
                sprintf(buff,"select * from book where 作者='%s'",authorName.data());
                if(mysql_query(conn,buff))
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
                cout << "确认删除吗？ y/n\t";
                string choice;
                cin >> choice;
                if("y" == choice)
                {
                    char buff[1024] = {'\0'};
                    sprintf(buff,"delete from book where 作者='%s'",authorName.data());
                    if(mysql_query(conn,buff))
                    {
                        cout<<"数据库指令发送失败"<<endl;
                        return -1;
                    }
                    cout << "成功删除该书籍信息" << endl;
                }
                else
                {
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

int Book::updateBook()
{
    while(1)
    {
        cout << "----------------------------------------------------------------------------------" << endl;
        cout << "1-->按书名修改书籍信息" << endl;
        cout << "2-->按作者修改书籍信息" << endl;
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
                string bookName;
                cout << "请输入想要修改的书籍的名字：";
                cin >> bookName;
                cout << "该书籍的已有信息如下：" << endl;
                char buff[1024] = {'\0'};
                sprintf(buff,"select * from book where 书名='%s'",bookName.data());
                if(mysql_query(conn,buff))
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
                while(1)
                {
                    cout << "修改  1->作者  2->出版社  3->价钱  0->退出修改" << endl;
                    cout << "请选择：";
                    int choice;
                    cin >> choice;
                    switch(choice)
                    {
                        case 1:
                        {
                            string newAuthor;
                            cout << "请输入新的作者：";
                            cin >> newAuthor;
                            char buff[1024] = {'\0'};
                            sprintf(buff,"update book set 作者='%s' where 书名='%s'",newAuthor.data(),bookName.data());
                            if(mysql_query(conn,buff))
                            {
                                cout<<"数据库指令发送失败"<<endl;
                                return -1;
                            }
                            cout << "修改成功，新的作者为：" << newAuthor << endl;
                            break;
                        }
                        case 2:
                        {
                            string newPress;
                            cout << "请输入新的出版社：";
                            cin >> newPress;
                            char buff[1024] = {'\0'};
                            sprintf(buff,"update book set 出版社='%s' where 书名='%s'",newPress.data(),bookName.data());
                            if(mysql_query(conn,buff))
                            {
                                cout<<"数据库指令发送失败"<<endl;
                                return -1;
                            }
                            cout << "修改成功，新的出版社为：" << newPress << endl;
                            break;
                        }
                        case 3:
                        {
                            float newPrice;
                            cout << "请输入新的价钱：";
                            cin >> newPrice;
                            char buff[1024] = {'\0'};
                            sprintf(buff,"update book set 价钱=%f where 书名='%s'",newPrice,bookName.data());
                            if(mysql_query(conn,buff))
                            {
                                cout<<"数据库指令发送失败"<<endl;
                                return -1;
                            }
                            cout << "修改成功，新的价钱为：" << newPrice << endl;
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
                string authorName;
                cout << "请输入想要修改的书籍的作者名字：";
                cin >> authorName;
                cout << "该书籍的已有信息如下：" << endl;
                char buff[1024] = {'\0'};
                sprintf(buff,"select * from book where 作者='%s'",authorName.data());
                if(mysql_query(conn,buff))
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
                while(1)
                {
                    cout << "修改  1->书名  2->出版社  3->价钱  0->退出修改" << endl;
                    cout << "请选择：";
                    int choice;
                    cin >> choice;
                    switch(choice)
                    {
                        case 1:
                        {
                            string bookName;
                            cout << "请输入新的书名：";
                            cin >> bookName;
                            char buff[1024] = {'\0'};
                            sprintf(buff,"update book set 书名='%s' where 作者='%s'",bookName.data(),authorName.data());
                            if(mysql_query(conn,buff))
                            {
                                cout<<"数据库指令发送失败"<<endl;
                                return -1;
                            }
                            cout << "修改成功，新的书名为：" << bookName << endl;
                            break;
                        }
                        case 2:
                        {
                            string newPress;
                            cout << "请输入新的出版社：";
                            cin >> newPress;
                            char buff[1024] = {'\0'};
                            sprintf(buff,"update book set 出版社='%s' where 作者='%s'",newPress.data(),authorName.data());
                            if(mysql_query(conn,buff))
                            {
                                cout<<"数据库指令发送失败"<<endl;
                                return -1;
                            }
                            cout << "修改成功，新的出版社为：" << newPress << endl;
                            break;
                        }
                        case 3:
                        {
                            float newPrice;
                            cout << "请输入新的价钱：";
                            cin >> newPrice;
                            char buff[1024] = {'\0'};
                            sprintf(buff,"update book set 价钱=%f where 作者='%s'",newPrice,authorName.data());
                            if(mysql_query(conn,buff))
                            {
                                cout<<"数据库指令发送失败"<<endl;
                                return -1;
                            }
                            cout << "修改成功，新的价钱为：" << newPrice << endl;
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

int Book::showBook()
{
    while(1)
    {
        cout << "----------------------------------------------------------------------------------" << endl;
        cout << "1-->按书名查找" << endl;
        cout << "2-->按作者查找" << endl;
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
                mysql_close(conn);
                break;
            case 2:
                if(mysql_query(conn,"select * from book order by 作者"))
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
