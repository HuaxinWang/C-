#include <iostream>  //#include <stdio.h>
#include <string>
using namespace std;

void show(string str[6])
{
	int i = 0;
	for (; i < 6; i++)
	{
		cout << str[i] << ' ';
	}
	cout << endl;
}

void bubble(string str[6])
{
	int i = 0;
	int j = 0;
	string tmp;
	for (; i < 6-1; i++)
	{
		for (j = 0; j < 6-1-i; j++)
		{
			if (str[j] > str[j+1])
			{
				tmp = str[j];
				str[j] = str[j+1];
				str[j+1] = tmp;	
			}
		}
	}
}

int main(void)
{
	string str[6] = {"orange", "apple"
			         , "banana", "pear"
	                 , "watermelon"
					 , "pineapple"};
	show(str);

	bubble(str);
	show(str);

	cout << "Hello World\n";	

	return 0;
}
