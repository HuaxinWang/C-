#include <iostream>
using namespace std;

class Complex
{
public:
	Complex(int real = 0, int vir = 0)
	{
		m_iReal = real;
		m_iVir = vir;
	}
	void show()
	{
		cout << '(' << m_iReal << ')' 
			 << '+' << '(' << m_iVir << ')'
			 << 'i' << endl;
	}
//private:
	int m_iReal;
	int m_iVir;
};

Complex operator+(const Complex &c1
			      , const Complex &c2)
{
	Complex c;
   	c.m_iReal = c1.m_iReal + c2.m_iReal;
	c.m_iVir = c1.m_iVir + c2.m_iVir;
	return c;
}

Complex operator-(const Complex &c1
			      , const Complex &c2)
{
	Complex c;
   	c.m_iReal = c1.m_iReal - c2.m_iReal;
	c.m_iVir = c1.m_iVir - c2.m_iVir;
	return c;
}

int main(void)
{
	Complex c1(3, 4);
	c1.show();
	
	Complex c2(5, 9);
	c2.show();

	//Complex c3 = c1+c2;
	Complex c3 = operator+(c1, c2);
	c3.show();

	Complex c4 = c1-c2;
	c4.show();

	return 0;
}
