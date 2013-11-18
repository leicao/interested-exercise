#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void str_compression(const char* str)
{
  if (str == NULL || *str == '\0')
    return ;

  char count[256] = {0};
  const char* sc = str;
  unsigned long offset = 0;

  int i;
  for (i = 0; i < 256 && *str != '\0'; ++i)
  {
    ++count[*str++];
  }
  
  while (*(sc+offset) != '\0')
  {
    if (count[*(sc+offset)] == 1)
    {
      printf("%c", *(sc+offset));
      offset += 1;
    }
    else
    {
      printf("%u%c", count[*(sc+offset)], *(sc+offset));
      offset += count[*(sc+offset)];
    }
  }
  
  printf("\n");
}

unsigned int longlen(unsigned long num)
{
  unsigned int len = 1;
  while (num /= 10) ++len;
  return len;
} 

char* str_compression_2(const char* str)
{
  if (str == NULL || *str == '\0')
    return NULL;

  unsigned long count = 1;
  unsigned long sum = 0;
  char tmp_str[19] = {0};
  const char* sc = NULL;
  for (sc = str; *sc != '\0'; ++sc)
  {
    if (*sc == *(sc+1))
    {
      ++count;
    }
    else 
    {
      if (count == 1)
      {
	sum += 1;
      }
      else 
      {
	sum += longlen(count)+1;
      }
    }
  }

  char* compress_str = (char*)malloc(sum+1);
  if (compress_str == NULL)
  {
    return NULL;
  }
  
  char* dest = compress_str;

  for (sc = str, count = 1; *sc != '\0'; ++sc)
  {
    if (*sc == *(sc+1))
    {
      ++count;
    }
    else
    {
      if (count == 1)
      {
	//printf("%c", *sc);
	*compress_str++ = *sc;
      }
      else 
      {
	//printf("%lu%c", count, *sc);
	//*compress_str++ = count + '0';
	sprintf(tmp_str, "%lu", count);
	//printf("tmp_str : %s\n", tmp_str);
	memcpy(compress_str, tmp_str, longlen(count));
	compress_str += longlen(count);
	*compress_str++ = *sc;
      }
      count = 1;
    }
  }
  //printf("\n");
  *compress_str = '\0';
  return dest;
}

char* str_decompression(const char* src)
{
  if (src == NULL || *src == '\0')
  {
    return NULL;
  }

  unsigned int dest_str_size = 0;
  unsigned int src_str_size = strlen(src);
  unsigned int tmp_sum = 0;
  unsigned int dest_offset = 0;
  
  int i;
  for (i = 0; i < src_str_size; ++i)
  {
    if (src[i] >= '0' && src[i] <= '9')
    {
      tmp_sum = tmp_sum*10 + src[i]-'0';
      continue ;
    }
    
    if (src[i-1] >= '0' && src[i-1] <= '9')
    {
      dest_str_size += tmp_sum;
      tmp_sum = 0;
      continue ;
    }

    dest_str_size += 1;

  }

  char* dest = (char*)malloc(dest_str_size+1);
  memset(dest, 0, dest_str_size+1);
  
  for (i = 0, tmp_sum = 0; i < src_str_size; ++i)
  {
    if (src[i] >= '0' && src[i] <= '9')
    {
      tmp_sum = tmp_sum*10 + src[i]-'0';
      continue ;
    }
    
    if (src[i-1] >= '0' && src[i-1] <= '9')
    {
      memset(dest+dest_offset, src[i], tmp_sum);
      //printf("tmp_sum : %u\n", tmp_sum);
      dest_offset += tmp_sum;
      tmp_sum = 0;
      continue ;
    }

    memset(dest+dest_offset, src[i], 1);
    dest_offset ++;
  }
  
  return dest;
}



int main(int argc, char** argv)
{
  if (argc != 2)
    return -1;

  printf("%s : %lu\n", argv[1], strlen(argv[1]));

  //str_compression(argv[1]);
  char* compress_str = str_compression_2(argv[1]);
  
  printf("%s : %lu\n", compress_str, strlen(compress_str));

  char* decompress_str = str_decompression(compress_str);
  
  printf("%s : %lu\n", decompress_str, strlen(decompress_str));

  //printf("10 : %u\n", intlen(10));
  //printf("0 : %u\n", intlen(0));
  //printf("0x7fffffffffffffff : %u\n", intlen(0x7fffffffffffffff));

  return 0;
}
