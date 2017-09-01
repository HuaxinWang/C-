#ifndef MANAGER_H
#define MANAGER_H

class Manager:virtual public Employee
{
public:
    void get()
    {
        m_strGrade = 'A';
        m_iPay = 5000;
        m_iNum = getNum();
    }
};

#endif
