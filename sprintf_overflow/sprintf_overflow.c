#include <stdio.h>

const char* format = 
  "%d";


int main(void)
{
  char buf[1024] = {0};
  sprintf(buf, format, 2147483648);
  printf("%s\n", buf); // result : -2147483648 overflow
  return 0;
  
}
