#include <stdio.h>

int itostr(const int num)
{
  char buf[100] = {0};
  sprintf(buf, "%d", num);
  printf("%s\n", buf);
  return 0;
}

int main(void)
{
  itostr(10000);
  return 0;
}
