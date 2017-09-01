#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
 template<typename M, typename N>
 int count(M first, M last, N value)
 {
 	int num = 0;
	while (first != last)
	{
		if (*first == value)
		{
			num++;
		}
		first++;
	}
	return num;
 }
 
 */


int main(void)
{
	int a[7] = {4,4,3,4,5,4,4};
	//在指定区间内[)，查找某个数据的个数
	//cout << count(a, a+7, 4) << endl;
	cout << count(a, a+3, 4) << endl;

	vector<int> vec;
	vec.push_back(5);
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(6);
	vec.push_back(7);
	vec.push_back(5);
	cout << count(vec.begin(), vec.end(), 5) << endl;

	return 0;
}
