#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

using namespace std;

class Employee
{
public:
    friend istream &operator>>(istream &input,employee &ob)
    {
        input >> ob.m_strName >> endl;
        return input;
    }
    friend ostream &operator<<(ostream &output,employee &ob)
    {
        output << ob.m_iNum << '\t'
               << ob.m_strName << '\t'
               << ob.m_strGrade << '\t'
               << ob.m_iPay << endl;
        return output;
    }

    friend void tianjia();
    friend void chaxun_num();
    friend void chaxun_name();
    friend void chaxun();
    friend void xianshi();
    friend void bianji();
    friend void shanchu_num();
    friend void shanchu_name();
    friend void shanchu();
    friend void tongji();
    friend void duqu();
    friend void getNum();
protected:
    int m_iNum;
    string m_strName;
    string m_strGrade;
    int m_iPay;
};

#endif
