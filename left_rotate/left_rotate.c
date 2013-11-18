#include <stdio.h>
#include <string.h>
#include <assert.h>

void reverse(char *str, unsigned long begin, unsigned long end)
{
	assert(str != NULL);
	char tmp;
	unsigned long mid = (begin+end) >> 1;
	for (; begin < mid; ++begin, --end)
	{	
                tmp = str[begin];
		str[begin] = str[end-1];
		str[end-1] = tmp;
	}
}

void left_ronate(char *str, unsigned long bits, unsigned long len)
{
	assert(str != NULL);
	bits %= len;
	reverse(str, 0, bits);
	reverse(str, bits, len);
	reverse(str, 0, len);
}

void right_ronate(char *str, unsigned long bits, unsigned long len)
{
	assert(str != NULL);
	bits %= len;
	bits = len - bits;
	left_ronate(str, bits, len);
	
}

int main(void)
{
	//char str[] = "you are the apple of my eye";
	//char str[] = "abcdefg";
	char str[] = "abcdefg123456789009876543211234567890098765432112345678909876543211234567890098765432112345678900987654321abcdefgabcd";
	printf("before ronate : %s\n", str);
	//reverse(str, 0, strlen(str));
	//left_ronate(str, 4+strlen(str) * 10, strlen(str));
	right_ronate(str, 4+strlen(str) * 10, strlen(str));
	printf("after  ronate : %s\n", str);
	return 0;
}


