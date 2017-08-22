#include <stdio.h>

void test(char *str)
{
	str = (char *)malloc(1024);
	strcpy(str, "nihaoa");
	printf("%s\n", str);
}

int main(void)
{
	//int *p = (int *)malloc(1024);
	//p = "hello";

	char *p = NULL;
	test(p);
	printf("%s\n", p);

	//int *p2 = (int *)malloc(sizeof(int)*2*3);
	//int (*p3)[3] = ()p2;





	return 0;
}
