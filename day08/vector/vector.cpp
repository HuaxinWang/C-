#include <iostream>
#include <vector>
#include <string>


using namespace std;


int main(void)
{
	//string str;
	vector<int> vec;
	//实际有效数据的量
	cout << vec.size() << endl;	
	//实际存储空间大小
	cout << vec.capacity() << endl;
	//使用push_back赋值，空间不够则自动增长空间
	vec.push_back(67);
	vec.push_back(77);
	vec.push_back(88);
	vec.push_back(87);
	vec.push_back(97);
	vec.push_back(78);
	vec.push_back(57);
	cout << vec.size() << endl;	
	cout << vec.capacity() << endl;
#if 1
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << ' ';
		//若使用下标赋值，越界不会自动增长空间
		vec[i] += 100; //不能越界
	}
	cout << '\n';
#endif

	for (int i = 0; i < vec.size(); i++)
	{
		//at访问数据时，首先会做越界检查
		//如果越界了，直接抛出错误
		//比使用下标直接访问更安全
		cout << vec.at(i) << ' ';
	}
	cout << '\n';

	vector<int>::iterator iter;
	iter = vec.begin();
	for (; iter != vec.end(); iter++)
	{
		cout << *iter << ' ';
//		*iter += 90;
	}
	cout << '\n';

	int oddNum = 0;  //奇数
	int evenNum = 0; //偶数
	for (iter = vec.begin(); iter != vec.end()
		 ; iter++)
	{
		if (0 == *iter%2)
		{
			evenNum++;
		}
		else if (1 == *iter%2)
		{
			oddNum++;
		}
	}
	cout << "奇数个数:" << oddNum << endl;
	cout << "偶数个数:" << evenNum << endl;

	//若容器中的数据发生增减
	//则所有迭代器失效，必须对迭代器重新赋值
	//erase():返回值为下一个数据的迭代器
#if 0   //错误写法
	for (iter = vec.begin(); iter != vec.end()
		 ; iter++)
	{
		if (0 == *iter%2)
		{
			vec.erase(iter);
		}
	}
#endif
	for (iter = vec.begin(); iter != vec.end();)
	{
		if (0 == *iter%2)
		{
			iter = vec.erase(iter);
		}
		else
		{
			iter++;
		}
	}
	
	iter = vec.begin();
	for (; iter != vec.end(); iter++)
	{
		cout << *iter << ' ';
	}
	cout << '\n';

	cout << "Hello World" << endl;

	return 0;
}
