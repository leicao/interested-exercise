#include "util.h"

int check_ip_valid(const char* ip)
{
  if (ip == NULL || *ip == '\0' || strlen(ip) > IP_MAX || strlen(ip) < IP_MIN)
    return -1;
  if (*ip == '.' || *(ip+strlen(ip)-1) == '.')
    return -1;

  unsigned char period_count = 0;
  unsigned char num_count = 0;
  char tmp[4] = {0};
  
  int i;
  for (i = 0; *(ip+i) != '\0'; ++i)
  {
    if (*(ip+i) == '.')
      ++period_count;
  }

  if (period_count != 3)
    return -1;
  
  for (i = 0; *(ip+i) != '\0'; ++i)
  {
    if (*(ip+i) != '.' && (*(ip+i) < '0' || *(ip+i) > '9'))
      return -1;
    if (*(ip+i) == '.' && *(ip+i+1) == '.')
      return -1;
  }

  int j;
  for (i = 0, j = 0; *(ip+i) != '\0'; ++i)
  {
    if (num_count > 3)
      return -1;
    if (*(ip+i) >= '0' && *(ip+i) <= '9')
    {
      ++num_count;
      tmp[j++] = *(ip+i);
    }
    else if (*(ip+i) == '.')
    {
      num_count = 0;
      j = 0;
      if (atoi(tmp) > 255)
	return -1;
    }
  }

  if (atoi(tmp) > 255)
    return -1;

  return 0;
}

int check_port_valid(const char* port)
{
  if (port == NULL || *port == '\0' || strlen(port) > 5)
    return -1;

  int i;
  for (i = 0; i < strlen(port); ++i)
  {
    if (*(port+i) < '0' || *(port+i) > '6')
      return -1;
  }
  
  int tmp = atoi(port);
  if (tmp < PORT_MIN || tmp > PORT_MAX)
    return -1;

  return 0;
}

int check_path_valid(const char* path)
{
  if (path == NULL || *path == '\0' || strlen(path) > PATH_MAX)
    return -1;

  int i;
  for (i = 0; i < strlen(path)-1; ++i)
  {
    if (path[i] == '/' && path[i+1] == '/')
      return -1;
  }  

  return 0;
}

int gbidcmp(const char* gbid1, const char* gbid2)
{
  if (gbid1 == NULL || *gbid1 == '\0' || gbid2 == NULL || *gbid2 == '\0')
    return -2;
  
  if (strlen(gbid1) != 20 || strlen(gbid2) != 20)
    return -2;

  unsigned int len = strlen(gbid1);

  int i, j;
  for (i = 0; i < len; ++i)
  {
    if (gbid1[i] < '0' || gbid1[i] > '9')
      return -2;
  }
  
  for (i = 0; i < len; ++i)
  {
    if (gbid2[i] < '0' || gbid2[i] > '9')
      return -2;
  }

  for (i = 0; i < len; ++i)
  {
    if (gbid1[i] != '0')
      break ;
  }
  for (j = 0; j < len; ++j)
  {
    if (gbid2[j] != '0')
      break ;
  }
  if (i < j)
    return 1;
  else if (i > j)
    return -1;
  else 
  {
    for (; i < len; ++i)
    {
      if (gbid1[i] > gbid2[i])
      {
	return 1;
      }
      else if (gbid1[i] < gbid2[i])
      {
	return -1;
      }
      else
      {
	;
      }
    }
  }
  return 0;
}

