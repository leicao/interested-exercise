#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNT 10
#define CALCULATOR(x, y) (((x)/2)+((y)*((x)+1)))

void show_these_num()
{
	unsigned long x, y;
	for (y = 1; y < COUNT; ++y)
	{
		for (x = 1; x < COUNT; ++x)
			printf("y = %lu\t x = %lu\t r = %lu\t\n", y, x, CALCULATOR(x, y));
	}
}

void calculator(char* p)
{
	unsigned long x, y;
	for (y = 1; y < 1000000; ++y)
	{
		for (x = 1; x < 1000000; ++x)
		{
			memset(p+CALCULATOR(x, y), 1, 1);
		}
	}

}

void show_result(char* p)
{
	unsigned int i;
	unsigned long j;
	for (i = 1, j = 1; j < 1024*1024*1024LL; ++j)
	{
		if (p[j] == 0)
		{
			printf("line : %d, %lu\n", i++, j);
		}

		if (i == 41)
		{
			break ;
		}
	}

	/*
	   for (j = 0; j < 1024*1024*1024LL; ++j)
	   {
	   if (j % 80 == 0)
	   {
	   printf("\n");
	   }
	   printf("%c ", p[j]+'0');
	   }
	 */


}

void check_result(unsigned long num)
{
	unsigned long i, j;
	for (i = 1; i < 100000; ++i)
	{
		for (j = 1; j < 10000; ++j)
		{
			if (num == CALCULATOR(i, j))
			{	
				printf("%lu, check\n", num);
				return ;
			}
		}
	}
}

int main(void)
{
	//show_these_num();
	char* p = (char*)malloc(1024*1024*1024*sizeof(char));
	if (p == NULL)
	{
		printf("malloc failed\n");
		return -1;
	}
	memset(p, 0, 1024*1024*1024LL);
	calculator(p);
	show_result(p);
	//check_result(22716);
	//check_result(1);
	//check_result(3);
	//check_result(22776);
	//check_result(22740);

	free(p);

	return 0;
}
