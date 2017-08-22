#include <iostream>
#include <string>
#include <stdlib.h>  //srand  rand
#include <time.h>  //用于产生随机种子
using namespace std;

class Commodity
{
public:
    Commodity():m_name("雪碧"),m_price(3.5)
    {}
    string m_name;
    float m_price;
    static int m_totalNum;
};

int Commodity::m_totalNum = 1000;

class Saler
{
public:
    Saler(string name,int num):m_name(name),m_saledNum(0),m_num(num),m_com()
    {}
    void showSale()
    {
        Market m;
        m.work();
        m_saledNum += salerNum2;
        m_com.m_totalNum -= salerNum2;
        cout << salerNum << "号销售员" << m_name << "此次卖了" << m_com.m_name << num << "瓶,共卖了" << m_saledNum << endl;
        cout << "还剩余" << m_com.m_totalNum << endl;
    }
private:
    string m_name;
    int m_saledNum;
    int m_num;
    Commodity m_com;
};

class Market
{
public:
    Market(string name,int num):m_sale(name,num),m_com()
    {}

    void work()
    {
        int salerNum = 0;
        srand((unsigned int)time(NULL));
        salerNum = rand() % 3 +1;
        int salerNum2 = 0;
        salerNum2 = rand() % 50 +1;
       // m_sale.m_saledNum += salerNum2;
        //m_com.m_totalNum -= salerNum2;
        //cout << salerNum << "号销售员" << m_sale.m_name << "此次卖了" 
        //    << m_com.m_name << salerNum2<< "瓶,共卖了" << m_sale.m_saledNum << endl;
       // cout << "还剩余" << m_com.m_totalNum << endl;
    }
    
    void show()
    {
        m_sale.showSale();
    }
private:
    Saler m_sale;
    Commodity m_com;
};

int main(void)
{
    Market m("张三",1);
    Market m1("李四",2);
    Market m2("王五",3);

    m.show();
    m1.show();
    m2.show();
    m.show();
    m1.show();
    m2.show();

    
    return 0;
}
