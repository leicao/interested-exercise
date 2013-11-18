#include <stdio.h>

int first_character_in_str(char* str)
{
  if (str == NULL || *str == '\0')
  {
    return -1;
  }
  
  // 256 is for ASCII characters
  //unsigned long count[256] = {0};
  char count[256] = {0};
  
  for (; *str != '\0'; ++str)
  {
    count[*str]++;
  }

  int i;
  for (i = 0; i < 256; ++i)
  {
    if (count[i] == 1)
    {
     printf("%c\n", i);
     return i;
    }
  }
    
  return 0;

}

int main(void)
{
  int ret = 0;
  ret = first_character_in_str(NULL);
  printf("NULL return value : %d\n", ret);
  ret = first_character_in_str("");
  printf("EMPTY return value : %d\n", ret);
  first_character_in_str("abbacddeef");
  return 0;
}
