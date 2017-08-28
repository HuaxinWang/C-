#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	vector<int> vec;
	vec.push_back(67);
	vec.push_back(77);
	vec.push_back(88);
	vec.push_back(87);
	vec.push_back(97);
	vec.push_back(78);
	vec.push_back(57);
	//常迭代器，不能通过常迭代器修改数据
	//vector<int>::const_iterator iter;

	//反向迭代器
	vector<int>::reverse_iterator iter;
	iter = vec.rbegin(); //最后一个元素
	//rend():第一个元素的前一个
	for (; iter != vec.rend(); iter++)
	{
		cout << *iter << ' ';
	}
	cout << '\n';

	cout << "Hello World" << endl;

	return 0;
}
