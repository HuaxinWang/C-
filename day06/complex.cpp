#include <iostream>
using namespace std;

class Complex
{
public:
	explicit Complex(int real = 0, int vir = 0)
	{
		m_iReal = real;
		m_iVir = vir;
		cout << "Complex(int,int)\n";
	}

	Complex operator+(const Complex &c1)
	{
		Complex c;
   		c.m_iReal = m_iReal + c1.m_iReal;
		c.m_iVir = m_iVir + c1.m_iVir;
		return c;
	}
	operator int()
	{
		cout << "operator int()\n";
		return m_iReal;
	}
#if 0	
	Complex operator+(int data)
	{
		Complex c;
   		c.m_iReal = m_iReal + data;
		c.m_iVir = m_iVir;
		return c;
	}
#endif
	Complex operator-(const Complex &c1)
	{
		Complex c;
   		c.m_iReal = m_iReal - c1.m_iReal;
		c.m_iVir = m_iVir - c1.m_iVir;
		return c;
	}

	int m_iReal;
	int m_iVir;
};

ostream &operator<<(ostream &out, const Complex &c)
{
	out << '(' << c.m_iReal << ')' << '+'
		<< '(' << c.m_iVir << ')' << 'i';
	return out;
}

istream &operator>>(istream &in, Complex &c)
{
	in >> c.m_iReal >> c.m_iVir;
	return in;
}

int main(void)
{
//	Complex c1;
//	cin >> c1;
//	cout << c1 << endl;

	Complex c2(10, 18);
	cout << "c2:" << c2 << endl;
	cout << (c2 + 20) << endl;
	cout << (int)c2 << endl;
	//Complex c3 = c2+20; //error
	//Complex c3(c2+20);
	//cout << "c3:" << c3 << endl;

	return 0;
}
