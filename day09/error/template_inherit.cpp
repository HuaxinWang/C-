#include <iostream>
using namespace std;


template<typename T>
class Base
{
public:
	virtual T data() = 0;
};

template<typename T>
class A : public Base<T>
{
public:
	A(int a = 0):m_data(a){}
	int data()
	{
		return m_data;
	}
private:
	int m_data;
};
template<typename T>
class B : public Base<T>
{
public:
	B(string a = ""):m_data(a){}
	string  data()
	{
		return m_data;
	}
private:
	string m_data;
};

template<typename T>
void data(Base<T> *b)
{
	cout << b->data() << endl;
}

template<typename T>
void fun(T a)
{}

int main(void)
{
	//fun<int>(89); fun<string>("string");
	//fun(89); fun("string");

	data<int>(new A<int>(89));
	data<string>(new B<string>("hello"));
#if 0
	Base<int> *b = new A<int>(89);
	cout << b->data() << endl;

	Base<string> *b2 = new B<string>("hello");
	cout << b2->data() << endl;
#endif
	return 0;
}
