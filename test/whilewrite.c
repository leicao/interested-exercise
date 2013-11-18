#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	int fd = open("./test", O_RDWR | O_CREAT);
	char* buf = malloc(4*1024*1024);
	memset(buf, 'a', 4*1024*1024);
	if (buf == NULL)
	{
		printf("error\n");
		return -1;
	}
	while (1)
	{
		write(fd, buf, 4*1024*1024);
	}
	return 0;
}
