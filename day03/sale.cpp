#include <iostream>
#include <string>

using namespace std;

class Saler
{
public:
	Saler(string name)
	{
		m_strName = name;
		m_iSaledNum = 0;
	}
	void sale()
	{
		cout << "请输入销售数目:";
		int num = 0;
		cin >> num;
		m_iSaledNum += num;
		m_iTotalNum -= num;
		cout << m_strName << " 此次卖了 "
			 << num << " 量，共卖了 " 
			 << m_iSaledNum << endl;
		cout << "货品剩余量为: " << m_iTotalNum
			 << endl;
	}
private:
	string m_strName;
	int m_iSaledNum;
	static int m_iTotalNum;
};

int Saler::m_iTotalNum = 1000;

int main(void)
{
	Saler s("张三");
	Saler s1("李四");
	Saler s2("王五");
	
	s.sale();
	s1.sale();
	s2.sale();
	s.sale();
	s1.sale();
	s2.sale();
	


	return 0;
}
