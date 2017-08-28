#include <iostream>
#include <vector>
#include <string>

using namespace std;

void display(const vector<int> &vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << ' ';
	}
	cout << endl;
}

int main(void)
{	
	int a[7] = {89, 76, 56, 45, 98, 88, 67};
	vector<int> vec(a, a+7); //[a,a+7)
	display(vec);

	vector<int>::iterator iter = vec.begin();
	iter++;
	iter++;
	//若空间不够则自动增长空间
	//vec.insert(iter, 888); //在指定位置插入888
	//vec.insert(iter, 3, 888); //在指定位置插入3个888
	

	int a2[5] = {189, 176, 156, 145, 198};
	vector<int> vec2(a2, a2+5); 
	//在指定位置插入一个区间的数据
	vec.insert(iter, vec2.begin(), vec2.end());//[)

	display(vec);

	return 0;
}



