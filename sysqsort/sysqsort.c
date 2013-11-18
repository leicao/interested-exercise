#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define N 30
#define ElemType int

int integer_cmp(const void* vp1, const void* vp2)
{
  return memcmp(vp1, vp2, sizeof(int));
}

int main(void)
{
  srand(time(NULL));
  ElemType a[N];

  int i;
  for (i = 0; i < N; ++i)
    a[i] = rand() % 100;
  
  for (i = 0; i < N; ++i)
    printf("%3d ", a[i]);
  printf("\n");
  
  qsort(a, sizeof(a)/sizeof(a[0]), sizeof(ElemType), integer_cmp);

  for (i = 0; i < N; ++i)
    printf("%3d ", a[i]);
  printf("\n");
  
  

  return 0;
}
