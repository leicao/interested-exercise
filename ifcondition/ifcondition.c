#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char* _strcpy(char* pchto, char* pchfrom)
{
  char* pchstart = pchto;
  while ((*pchto++ = *pchfrom++) != '\0' )
    NULL;
  
  return pchstart;
}

void* _memcpy(void* pvTo, void* pvFrom, unsigned long size)
{
  char* pbTo = (char*)pvTo;
  char* pbFrom = (char*)pvFrom;

  assert(pvTo != NULL && pvFrom != NULL);
  
  while (size-- > 0)
  {
    *pbTo++ = *pbFrom++;
  }
  
  return pvTo;
}

int main(void)
{
  char* pchfrom = strdup("hello, world ");
  char* pchto = (char*)malloc(strlen(pchfrom)+1);
  memset(pchto, 0, strlen(pchfrom)+1);
  printf("pchfrom : %s\n", pchfrom);
  //pchto = _strcpy(pchto, pchfrom);
  //_strcpy(pchto, pchfrom);
  // _memcpy(pchto, pchfrom, strlen(pchfrom));
  // debug for assert
  _memcpy(NULL, pchfrom, strlen(pchfrom));
  printf("pchto   : %s\n", pchto);

  free(pchfrom);
  free(pchto);
  pchfrom = NULL;
  pchto = NULL;
  return 0;
}
