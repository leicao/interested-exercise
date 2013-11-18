#include <stdio.h>

unsigned char str_valid = 1;

unsigned long _strlen(const char* s)
{
  if (s == NULL)
  {
    str_valid = 0;
    return 0;
  }
  const char* sc = s;
  for (sc = s; *sc != '\0'; ++sc) ;
  return sc - s;
}

/*
unsigned long _strlen(const char* s)
{
  if (s == NULL)
  {
    str_valid = 0;
    return 0;
  }
  const char* sc = s;
  while (*sc) ++sc;
  return sc - s;
}
*/

int main(void)
{
  char* str_empty = "";
  char* str_null  = NULL;
  char* str_hello = "hello";
  printf("str_empty : %lu\n", _strlen(str_empty));
  printf("str_null  : %lu\n", _strlen(str_null));
  printf("str valid : %u\n", str_valid);
  printf("str_hello : %lu\n", _strlen(str_hello));
  return 0;
}
