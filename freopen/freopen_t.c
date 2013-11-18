#include <stdio.h>
#include <assert.h>

void test_freopen_1(const char* path, const char* mode, FILE* stream)
{
	assert(path != NULL && mode != NULL && stream != NULL);
	if (freopen(path, mode, stream) == NULL)
	{
		perror("freopen error ");
		return ;
	}
	int i;
	for (i = 0; i < 10; ++i)
	{
		printf("%d: hello\n", i);
	}
	
}

void test_freopen(const char* path1, const char* mode1, FILE* stream1,
                  const char* path2, const char* mode2, FILE* stream2
                 )
{
	assert(path1 != NULL && mode1 != NULL && stream1 != NULL);
	assert(path2 != NULL && mode2 != NULL && stream2 != NULL);

	if (freopen(path1, mode1, stream1) == NULL)
	{
		perror("freopen stdout error");
		return ;
	}

	if (freopen(path2, mode2, stream2) == NULL)
	{
		perror("freopen stdin error\n");
		return ;
	}

	unsigned long line_no = 0;
	char str[21] = {0};
	
	
	int i;
	for (i = 0; i < 10; ++i)
	{
		scanf("%lu %s", &line_no, str);
		printf("%lu : %s\n", line_no, str);
	}


	fclose(stream1);
	fclose(stream2);

	if (freopen("/dev/tty", "r", stream2) == NULL)
	{
		perror("back to console error");
	}

	if (freopen("/dev/tty", "w", stream1) == NULL)
	{
		perror("back to console error");
	}
	
}

int main(void)
{
	printf("start\n");
	test_freopen("./test_out", "w", stdout,
	             "./test_in", "r", stdin
	            );
	printf("finish\n");
	int n;
	scanf("%d", &n);
	printf("%d\n", n);
	return 0;
}

