#include <iostream>
using namespace std;
//private:id name score  public:setInfo show
struct Test
{
	int a;
};

class People
{
private:
	//private说明的对象只能通过共有的接口间接访问
	//成员变量
	string m_strId;
	string m_strName;
	string m_strAddr;
	string m_strDate;
public:
	//public说明的成员可以通过对象直接访问
	//成员函数
	void fun()
	{
		m_strId = "1121212112";
		cout << m_strId << endl;
	}
	string m_strFace;
};

int main(void)
{
	Test t;
	//结构体成员默认是共有的
	//可以通过对象直接访问
	t.a = 90;

	People p;
	//类中的成员默认是私有的
	//不能通过对象直接访问
	//可以通过共有的接口间接的进行访问
	//p.strId = "10101022112"; //error
	p.fun();
	p.m_strFace = "cool";
	cout << p.m_strFace << endl;

	return 0;
}
