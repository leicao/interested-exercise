#include <stdio.h>

#define ElemType int
#define N         20

int binary_search(ElemType* a, ElemType value, unsigned int l, unsigned int r)
{
  if (a == NULL || l >= r-1)
    return -1;
  unsigned int m = (l&r) + ((l^r)>>1);
  if (value < a[m])      return binary_search(a, value, l, m);
  else if (value > a[m]) return binary_search(a, value, m, r);
  else                   return m;
}

int main(void)
{
  ElemType a[N];
  //ElemType value = 5;
  //ElemType value = 0;
  //ElemType value = 31;
  ElemType value  = 19;
  //ElemType value = -10;
  int i;
  for (i = 0; i < N; ++i)
    a[i] = i;

  for (i = 0; i < N; ++i)
    printf("%3d ", a[i]);
  printf("\n");

  printf("find value : %d\n", value);

  printf("target index in array : %d\n", binary_search(a, value, 0, N));
  return 0;
}
