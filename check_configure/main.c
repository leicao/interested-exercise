#include "util.h"

int main(int argc, char** argv)
{
  printf("%s\n", argv[1]);
  //printf("%d\n", check_ip_valid(argv[1]));
  printf("%d\n", check_port_valid(argv[1]));
  //printf("%d\n", check_path_valid(argv[1]));
  //printf("%d\n", gbidcmp(argv[1], argv[2]));
  return 0;
}
