#include <stdio.h>

int main(void)
{
  int a = -1;
  int b = 40;
  int c = 41;
  int d = -40;
  int e = -41;
  
  printf("-1&31 : %d\n", a&31);
  printf("-1%%32 : %d\n", a%32);
  
  printf("40&31 : %d\n", b&31);
  printf("40%%32 : %d\n", b%32);

  printf("41&31 : %d\n", c&31);
  printf("41%%32 : %d\n", c%32);

  printf("-40&31: %d\n", d&31);
  printf("-40%%32: %d\n", d%32);

  printf("-41&31: %d\n", e&31);
  printf("-41%%32: %d\n", e%32);

  printf("100&0x3f   : %d\n", 100&0x3f);
  printf("100%%64     : %d\n", 100%64);

  return 0;
}
