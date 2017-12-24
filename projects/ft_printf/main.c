#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "printf.h"

int main()
{
	long long int a = 21474836822;
	int b = ft_printf("abc  %s  %s %- 25ld %p  %x %d  aaa %  Zoo\n", "cde", "efg", 1234567890123456789, &a, a, NULL);
	//ft_printf("%ld   %i\n", a, 555);
	int c = printf("abc  %s  %s %- 25ld %p  %x %d  aaa %  Zoo\n", "cde", "efg", 1234567890123456789, &a, a, NULL);
	printf("%d  %d\n", b, c);
	int aa = ft_printf("%-20.12d|\n", 1234567890);
	int bb = printf("%-20.12d|\n", 1234567890);
	printf("%d   %d\n", aa, bb);
	int q = ft_printf("%- 10.7d|\n", -12345);
	int w = printf("%- 10.7d|\n", -12345);
	printf("%d  %d\n", q, w);
	int qq = ft_printf("% .5c|\n", -11);
	int ww = printf("% .5c|\n", -11);
	printf("%d   %d\n", qq, ww);
	int oo = ft_printf("%015.14u\n", -12345);
	int	hh = printf("%015.14u\n", -12345);
	printf("%d   %d\n", oo, hh);
	int	h = printf("%#-011.4x|\n", 232442);
	printf("%d\n", h);
	return (0);
}
