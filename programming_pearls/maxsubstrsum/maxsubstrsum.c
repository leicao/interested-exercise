#include <stdio.h>

#define N 10
#define ElemType int

long max(long a, long b)
{
  return a > b ? a : b;
}

long maxsubstrsum(ElemType* a)
{
  long maxsofar = 0;
  long maxendinghere = 0;
  int i;
  for (i = 0; i < N; ++i)
  {
    maxendinghere = max(maxendinghere+a[i], 0);
    maxsofar = max(maxendinghere, maxsofar);
  }
  
  return maxsofar;
}

int main(void)
{
  long sum = 0;
  int a[N] = {-1, 2, 3, -4, 6, 2, 3, 4, -1, 0};
  sum = maxsubstrsum(a);
  printf("%ld\n", sum);
  return 0;
}
