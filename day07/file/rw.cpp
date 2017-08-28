#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>

using namespace std;

int main(void)
{
	fstream file("test.data");

	if (file.is_open())
	{
		cout << "open file ok\n";
		string array[5] = {"apple", "banana", "pear"
		                  , "flower", "water"};
		for (int i = 0; i < 5; i++)
		{
			file << array[i] << ' ';
		}
		file << '\n';

		file.seekg(0, ios_base::beg);
		string tmp;
		while (1)
		{
			tmp.clear();
			file >> tmp;

			//eof():判断是否达到文件末尾
			if (file.eof())
			{
				break;
			}
#if 0
			if (tmp.empty())
			{
				break;
			}
#endif
			cout << tmp << endl;
			sleep(1);
		}

		file.close();
	}
	else
	{
		cout << "open file failed\n";
	}

	return 0;
}
