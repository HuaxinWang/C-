#include <iostream>
#include <string>
using namespace std;

class MyError
{
public:
	MyError(string error="unknow error")
	{
		m_strError = error;
	}
	string &data()
	{
		return m_strError;
	}
private:
	string m_strError;
};
//c++函数默认可以抛出任意类型的错误(异常)
void fun(float a, float b) //(int, float)
{
	if (-0.000001 <= b && b <= 0.000001)
	{
		//int iErrno = -1;
		//throw iErrno;
		string strError = "除数为0";
		//错误抛出之后，后面的代码将不会被执行
		throw strError;
	}
	float m = a/b;
	cout << "m=" << m << endl;	
	try
	{
		char *p = NULL;
		if (NULL == p)
		{
//			int errno = -1;
	//		throw errno;
			MyError error("指针为空");
			throw error;
		}
		*p = 90;
	}
	catch(MyError &error)
	{
		cout << "catch myerror...\n";
		throw error;	
	}
	catch (...)
	{
		cout << ",,,,,,,\n";
	}
}

int main(void)
{
	try
	{
		fun(3, 5);
//		fun(3, 0);
	}
	catch (string error)
	{
		cout << error << endl;
	}
	catch (int error)
	{
		cout << error << endl;
	}
	catch (float error)
	{
	
	}
	catch (MyError &error)
	{
		cout << error.data() << endl;
	}
	catch (...)
	{
		cout << "unknow error" << endl;
	}

	cout << "Hello World" << endl;
	return 0;
}
