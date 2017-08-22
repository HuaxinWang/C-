#include <stdio.h>

struct Test
{
	int a;
	float c;
};

int main(void)
{
	struct Test t;
	t.a = 90;
	t.c = 2.3;

#if 0
	if (1)
	{
		int i = 90;
	}
//	printf("i = %d\n", i);
	char a[]= "hello";
	char *p = "hello";
	printf("%p, %p\n", p, "hello");
	printf("%c\n", "hello"[0]);
	printf("%c\n", p[0]);
#endif
	return 0;
}
