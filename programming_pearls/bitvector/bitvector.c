#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BITSPERWORD 32
#define SHIFT	     5
#define MASK	  0x1f
#define N         1000

int a[1+N/BITSPERWORD];

void set(int i) {a[i>>SHIFT] |= (1 << (i & MASK)); }
void clr(int i) {a[i>>SHIFT] &= ~(1 << (i & MASK)); }
int test(int i) {return a[i>>SHIFT] & (1 << (i & MASK)) ;}

int main(void)
{
	srand(time(NULL));
	int i;
	for (i = 0; i < N; ++i)
		clr(i);
	for (i = 0; i < N; ++i)
		set(rand()%N);
	for (i = 0; i < N; ++i)
		if (test(i))
			printf("%d\n", i);
	if (test(0))
		printf("0\n");
	return 0;
}
