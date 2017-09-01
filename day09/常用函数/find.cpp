#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
 template<typename T, typename M>
 T find(T first, T last, M value)
 {
 	while (first != last)
	{
		if (*first == value)
		{
			break;
		}
		first++;
	}
	return first;
 }
 
 */

int main(void)
{
	//从头开始查找，找到第一个匹配的立即返回
	int a[9] = {12,3,4,56,3,61,2, 90, 78};
	//int *p = find(a, a+7, 100); //[a,a+7)
	int *p = find(a, a+7, 3); //[a,a+7)
	if (p == a+7)  //
	{
		cout << "not find\n";
	}
	else
	{
		cout << p-a+1 << endl;
	}

#if 0
	vector<int> vec;
	vec.push_back(23);
	vec.push_back(34);
	vec.push_back(12);
	vec.push_back(324);
	vec.push_back(34);
	vec.push_back(56);
	vec.push_back(12);
	vec.push_back(23);

	vector<int>::iterator iter; //[begin(), end())
	iter = find(vec.begin(), vec.end(), 12);
	if (iter != vec.end())
	{
		cout << "find\n";
		iter++;
		cout << *iter << endl;
	}
	else
	{
		cout << "not find\n";
	}
#endif

	return 0;
}
