#include <iostream>

using namespace std;

void bubble(int a[], int count)
{
	int i = 0;
	int j = 0;
	int tmp;
	for (; i < count-1; i++)
	{
		for (j=0; j < count-1-i; j++)
		{
			if (a[j] > a[j+1])
			{
				tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			}
		}
	}
}

void display(int a[], int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}

void bind(int a[], int n1, int b[], int n2
		  , int c[], int n3)
{
	if (n3 < n1+n2)
	{
		return;
	}	
	int i = 0;
	int j = 0;
	int m = 0;
	for (; i < n1 && j < n2; m++)
	{
		if (a[i] < b[j])
		{
			c[m] = a[i];
			i++;
		}
		else if (a[i] == b[j])
		{
			c[m] = a[i];
			m++;
			c[m] = b[j];
			i++;
			j++;
		}
		else if (a[i] > b[j])
		{
			c[m] = b[j];
			j++;
		}
	}
	if (i < n1)
	{
		for (; i < n1; i++, m++)
		{
			c[m] = a[i];
		}
	}
	else if (j < n2)
	{
		for (; j < n2; j++, m++)
		{
			c[m] = b[j];
		}
	}
}

int main(void)
{
	int a[] = {23, 12, 45, 7, 12, 15};
	int na = sizeof(a)/sizeof(int);
	int b[] = {33, 56, 21, 7, 5, 2, 18, 29};
	int nb = sizeof(b)/sizeof(int);
	//int c[(sizeof(a)+sizeof(b))/sizeof(int)];
	int c[na+nb] = {0};
	cout << sizeof(c)/sizeof(4) << endl;

	bubble(a, na);
	display(a, na);
	bubble(b, nb);
	display(b, nb);

	bind(a, na, b, nb, c, na+nb);
	display(c, na+nb);

	return 0;
}
