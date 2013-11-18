#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ElemType int
#define N         30

void show_array(ElemType* a, unsigned long num)
{
  int i;
  for (i = 0; i < num; ++i)
  {
    printf("%d ", a[i]);
  }
  printf("\n");
}

void isort(ElemType* a, unsigned long num)
{
  ElemType t;
  int i, j;
  for (i = 1; i < num; ++i)
  {
    t = a[i];
    for (j = i; j > 0 && a[j-1] > t; --j)
    {
      a[j] = a[j-1];
    }
    a[j] = t;
  }
}

int main(void)
{
  srand(time(NULL));
  ElemType a[N];
  int i;
  for (i = 0; i < N; ++i)
  {
    a[i] = rand() % 100;
  }
  
  show_array(a, N);
  isort(a, N);
  show_array(a, N);
  
  return 0;
}
