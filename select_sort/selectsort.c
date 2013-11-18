#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define ElemType int
#define N         30

void _swap(void* vp1, void* vp2, unsigned int size)
{
  if (vp1 == NULL || vp2 == NULL || vp1 == vp2 || size == 0)
    return ;

  char buff[size];
  memcpy(buff, vp1, size);
  memcpy(vp1, vp2, size);
  memcpy(vp2, buff, size);
    
}

void select_sort(ElemType* a, int l, int r)
{
  if (a == NULL || l >= r)
    return ;
  int i, j, min;
  for (i = l; i < r-1; ++i)
  {
    for (j = i+1, min = i; j < r; ++j)
    {
      if (a[j] < a[min]) min = j;
    }
    _swap(&a[i], &a[min], sizeof(ElemType));
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

  select_sort(a, 0, N);
  
  for (i = 0; i < N; ++i)
  {
    printf("%3d ", a[i]);
  }
  printf("\n");

  return 0;
}
