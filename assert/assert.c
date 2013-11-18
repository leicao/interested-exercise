#include <assert.h>
#include <stdlib.h>

int main(void)
{
	int *p = NULL;
	assert (p == NULL);

	int a = 10;
	assert(a == 10);
	
	return 0;
}
