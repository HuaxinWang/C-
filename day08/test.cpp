#include <iostream>
#include <list>
#include <vector>

using namespace std;
#if 1
template<typename T>
void display(const T &data)
{
	typename T::const_iterator iter = data.begin();
	for (; iter != data.end(); iter++)
	{
		cout << *iter << ' ';
	}
	cout << endl;
}
#endif

bool compare(int &a, int &b)
{
	return a > b;
}

int main(void)
{
	int a[7] = {89, 87, 56, 92, 13, 77, 90};
	vector<int> vec_int(a, a+7);
	display(vec_int);

	list<int> list(vec_int.begin(), vec_int.end());
	list.sort(compare);
	display(list);


	return 0;
}
