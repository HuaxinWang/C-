#include <iostream>

using namespace std;

template<typename M, typename N>
void fun(M a, N b)
{
	cout << "first:" << a 
		 << " second:" << b << endl;	
}

int main(void)
{
	fun(34, 8.9f);
	fun("Hello", 3.14);

	return 0;
}
