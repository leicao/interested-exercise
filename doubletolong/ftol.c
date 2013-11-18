#include <stdio.h>

union luai_Cast { double l_d; long l_l; };
#define lua_number2int(i, d)\
{ volatile union luai_Cast u; u.l_d = (d)+6755399441055744.0; (i) = u.l_l; }

int main(void)
{
	int a = 0;
	double b = 1.2;
	lua_number2int(a, b);
	printf("%d\n", a);
	return 0;
}
