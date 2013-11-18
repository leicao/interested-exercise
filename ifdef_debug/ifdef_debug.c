#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define DEBUG

char* _strcpy(char* strTo, char* strFrom)
{
  #ifdef DEBUG
  printf("debug module\n");
  if (strTo == NULL || strFrom == NULL)
  {
    printf("strTo is NULL or strFrom is NULL.\n");
    return NULL;
  }
  #endif
  char* strStart = strTo;
  while ((*strTo++ = *strFrom++) != '\0') NULL;

  return strStart;
  
}

void* _memcpy(void* pvTo, void* pvFrom, unsigned long size)
{
  assert(pvTo !l= NULL && pvFrom != NULL);
  char* pcTo = (char*)pvTo;
  char* pcFrom = (char*)pvFrom;

  while (size-- > 0) *pcTo++ = *pcFrom++;

  return pvTo;
  
}

void* _memchr(void* pvh, unsigned char ch, size_t size)
{
  assert(pvh != NULL);
  char* pch = (char*)pvh;
  while (size-- > 0)
  {
    if (*pch == ch)
    {
      return pch;
    }
    pch ++;
  }
  return NULL;
}

int main(void)
{
  char* src = strdup("hello, world!");
  //printf("%c\n", *(char*)(_memchr(src, 'E', strlen(src)-1)));
  
  char* dest = (char*)malloc(strlen(src)+1);
  //_strcpy(dest, src);
  _memcpy(dest, src, strlen(src)+1);
  printf("%s\n", src);
  printf("%s\n", dest);
  
  return 0;
}
