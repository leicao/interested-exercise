#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void _swap(void* vp1, void* vp2, unsigned long size)
{
	char tmp[size];
	memcpy(tmp, vp1, size);
	memcpy(vp1, vp2, size);
	memcpy(vp2, tmp, size);
}

int main(void)
{
	char vp1[] = "hello";
	char vp2[] = "world";
	
	//char *vp1 = "hello";
	//char *vp2 = "world";

	printf("%s\n", vp1);
	printf("%s\n", vp2);
	
	int _tmp = 0;

	_swap(&vp1, &vp2, sizeof(char*));

	printf("%s\n", vp1);
	printf("%s\n", vp2);

	return 0;
}

