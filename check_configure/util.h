#ifndef _UTIL_H_
#define _UTIL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define PATH_MAX    4096
#define NAME_MAX     255
#define IP_MAX        15
#define IP_MIN         7
#define PORT_MAX   65535
#define PORT_MIN       0

int check_ip_valid(const char* ip);
int check_port_valid(const char* port);
int check_path_valid(const char* path);
int gbidcmp(const char* gbid1, const char* gbid2);

#endif
