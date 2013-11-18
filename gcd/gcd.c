#include <stdio.h>
#include <stdlib.h>

// error code between annotation below
/*
unsigned long gcd(unsigned long m, unsigned long n)
{
	unsigned long r = m%n;
	while (r > 0)
	{
		m = n;
		n = r;
		r = m%n;
	}

	return n;
}
*/

unsigned long gcd(unsigned long m, unsigned long n)
{
  unsigned long r;
  while (n > 0)
  {
    r = m % n;
    m = n;
    n = r;
  }  
  return m;
}

int main(int argc, char** argv)
{
	if (argc != 3)
	{
		printf("illegal input.\n");
		return -1;
	}
	
	//printf("gcd(544, 119)  == %lu\n", gcd(544, 119));
	printf("gcd(%lu, %lu)  == %lu\n", atol(argv[1]), atol(argv[2]), gcd(atol(argv[1]), atol(argv[2])));
	
	
	
	return 0;
}

