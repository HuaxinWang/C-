#ifndef COSTOMER_H
#define COSTOMER_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

class Costomer
{
public:
    int getId();
    string getName();
    string getPwd();
    string getLevel();
    string getPhone();
    string getAddr();
    void setId(int id);
    void setName(string name);
    void setPwd(string pwd);
    void setLevel(string level);
    void setPhone(string phone);
    void setAddr(string addr);
    void costomerMenu(int id); 
    void addCostomer();
    int delCostomer();
    int updateCostomer();
    int showCostomer();
    int save_costomer_to_mysql(list<Costomer *> &v);
    int buyBook();
    int show_history(int id);
    int initPwd();
private:
    string m_strName;
    string m_strPwd;
    string m_strLevel;
    string m_strPhone;
    string m_strAddr;
    static int costomerId;
    
};

ostream &operator<<(ostream &out, const Costomer *costomer);




#endif