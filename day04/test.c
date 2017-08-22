#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct Test
{
	char *pData;
}string;

void fun()
{
	string t;
	t.pData = (char *)malloc(1024);
	// sizeof(t) = 4;
	strcpy(t.pData, "Hello World");
	string t2 = t;
	free(t.pData);
	free(t2.pData);
}

int main(void)
{
	fun();
	

	return 0;
}
