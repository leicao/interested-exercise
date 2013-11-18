#include <stdio.h>

int main(void)
{
  char buf[20] = {0};
  sprintf(buf, "%d", -100000);
  printf("%s\n", buf);
  return 0;
}
