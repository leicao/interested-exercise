#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/time.h>

typedef struct str_info_s
{
	unsigned long src;
	char* buf;
	unsigned long bits;
}str_info_t;

static int generate_str(unsigned long src, char* buf, const unsigned long bits)
{
	if (buf == NULL)
	{
		printf("buf is null");
		return -1;
	}


	char tmp[bits+1];
	memset(tmp, 0, bits+1);
	char c;
	int i;
	unsigned char len = 0;
	for (i = 0; src; src/=10, ++i)
	{
		tmp[i] = src%10 + '0';
	}
	
	len = strlen(tmp);
	for (i = 0; i < len/2; ++i)
	{
		c = tmp[i];
		tmp[i] = tmp[len-i-1];
		tmp[len-i-1] = c;
	}
	
	memset(buf, 0, bits+1);
	memset(buf, '0', bits);
	memcpy(buf+bits-len, tmp, len);

	return 0;
}

void generate_str_worker(void* param)
{
	str_info_t* str_info = (str_info_t*)param;
	generate_str(str_info->src, str_info->buf, str_info->bits);
}

int main(void)
{
	
	char buf[21] = {0};
	unsigned long i;
	struct timeval t1, t2;
	memset(&t1, 0, sizeof(struct timeval));
	memset(&t2, 0, sizeof(struct timeval));
	gettimeofday(&t1, NULL);
	for (i = 0; i < 0x7fffffffffffffff; ++i)
	//for (i = 0x7fffffffffff0000; i < 0x7fffffffffffffff; ++i)
	{
	}
	gettimeofday(&t2, NULL);
	printf("%s : %lu\n", buf, strlen(buf));
	printf("%lu\n", t2.tv_sec-t1.tv_sec) ;

	return 0;
}

