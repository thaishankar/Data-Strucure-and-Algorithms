#include<stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;
	for (i = 0; i < argc; i++)
	{
		printf("%d arg is : %s\n", i, argv[i]);
	}
}	
