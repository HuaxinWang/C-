#include <stdio.h>

int main(void)
{
	const int a = 90;
	*(int *)&a = 999;
	printf("a = %d\n", a);
	int *p = (int *)&a;
	*p = 1000;

	printf("a = %d\n", a);
	printf("*p = %d\n", *p);


	return 0;
}
