#include <stdio.h>

int main(void)
{
  int i = 0x7fffffff + 1;
  printf("i : %d\n", i);
  i = -i;
  printf("-i : %d\n", i);

  int a = -2147483647;
  int b = -2147483647;
  printf("%d\n", (a+b)/2);
  printf("%d\n", (a+b) >> 1);
  return 0;
}
