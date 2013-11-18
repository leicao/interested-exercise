#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int *p[4] = {NULL, NULL, NULL, NULL};
	
	
	int *pp[4] = {NULL, NULL, NULL, NULL};
	int i;
	for (i = 0; i < 4; ++i)
	{
		p[i] = malloc(sizeof(int*));
		*p[i] = i; 
	}

	for (i = 0; i < 4; ++i)
	{
		printf("p : %d\n", *p[i]);
	}

	for (i = 0; i < 4; ++i)
	{
		//pp[i] = malloc(sizeof(int*));
		//pp[i] = p[i];
	}

	memcpy(&pp[0], &p[0], 32);

	for (i = 0; i < 4; ++i)
	{
		printf("pp : %d\n", *pp[i]);
	}

	return 0;
}
