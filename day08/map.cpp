#include <iostream>
#include <map>
#include <string>

using namespace std;

void display(const map<int, string> &m)
{
	map<int, string>::const_iterator iter = m.begin();
	for (; iter != m.end(); iter++)
	{
		cout << iter->first << ' ' << iter->second << endl;
	}
}

int main(void)
{
	//自动根据键，从小到大排序
	map<int, string> stu;
	pair<int, string> p(1001, "aa");
	//stu.insert(pair<int, string>(1001, "aa"));
	stu.insert(p);
	stu.insert(pair<int, string>(1006, "ff"));
	stu.insert(pair<int, string>(1002, "bb"));
	stu.insert(pair<int, string>(1008, "hh"));
	stu.insert(pair<int, string>(1003, "cc"));
	stu.insert(pair<int, string>(1005, "ee"));
	stu.insert(pair<int, string>(1007, "gg"));
	stu.insert(pair<int, string>(1004, "dd"));
	display(stu);

	return 0;
}
