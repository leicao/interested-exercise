#include <stdio.h>
#include <string.h>

int main(void)
{
	char buf[21] = {0};
	memcpy(buf, "00000000000000000001", strlen("00000000000000000001"));
	printf("%lu\n", strlen("00000000000000000001"));
	printf("%lu\n", strlen(buf));
	return 0;
}
