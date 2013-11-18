#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ElemType int
#define N         30

void insert_sort(ElemType* a, int l, int r)
{
  int i, j, tmp;
  for (i = l+1; i < r; ++i)
  {
    for (j = i-1, tmp = a[i]; j >= 0 && tmp < a[j]; --j)
      a[j+1] = a[j]; 
    a[j+1] = tmp;
  }
}


int main(void)
{
  srand(time(NULL));
  ElemType a[N];
  int i;
  for (i = 0; i < N; ++i)
  {
    a[i] = rand()%100;
  }

  for (i = 0; i < N; ++i)
  {
    printf("%3d ", a[i]);
  }
  printf("\n");

  insert_sort(a, 0, N);

  for (i = 0; i < N; ++i)
  {
    printf("%3d ", a[i]);
  }
  printf("\n");
    
  return 0;
}
