#include <iostream>
using namespace std;

class People
{
public:
    People(string name,string born,string addr,string sex)
    {
        m_strName = name;
        m_strBorn = born;
        m_strAddr = addr;
        m_strSex = sex;
    }
    
    void info()
    {
        cout << m_strName << ' ' << m_strBorn << ' '
            << m_strAddr << ' ' << m_strSex << endl;
    }
private:
    string m_strName;
    string m_strBorn;
    string m_strAddr;
    string m_strSex;
};

class Teacher:public People
{
public:
    Teacher(string name,string born,string addr
            ,string sex,string id
            ,string level,int pay):People(name,born,addr,sex)
    {
        m_strId = id;
        m_strLevel = level;
        m_iPay = pay;
    }

    void info()
    {
        People::info();
        cout << m_strId << ' ' << m_strLevel << ' ' << m_iPay << endl;
    }
private:
    string m_strId;
    string m_strLevel;
    int m_iPay;
};

int main(void)
{
    Teacher t("壮志","1995,7,26","上海","女","250","班主任",8000);
    t.info();
    return 0;
}
