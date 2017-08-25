#include <iostream>

using namespace std;

//template<class T>
template<typename T>
class Compare
{
public:
	bool operator()(T &a, T &b)
	{
		return a < b;
	}	
};

int main(void)
{
	int a = 90;
	int b = 87;
	Compare<int> com;
	if (com(a, b))
	{
		cout << "a < b\n";
	}
	else
	{
		cout << "a >= b\n";
	}



	return 0;
}
