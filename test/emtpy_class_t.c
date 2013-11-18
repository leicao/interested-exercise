#include <stdio.h>

struct s
{
};

enum e
{
};

int main(void)
{
	struct s s1;
	enum e e1;
	printf("empty struct without virtual has %lu bytes\n", sizeof(s1));
	printf("empty enum e has %lu bytes\n", sizeof(e1));

	return 0;
}
