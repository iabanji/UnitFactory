#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "printf.h"
#include "libft.h"
#include <locale.h>

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
	int o = ft_printf("%#.o|\n", 232442);
	int	h = printf("%#.o|\n", 232442);
	printf("%d   %d\n", o, h);
	int	zz = ft_printf("%21.16p|\n", &h);
	int	z = printf("%21.16p|\n", &h);
	printf("%d   %d\n", zz, z);
	int ee = ft_printf("%20.6s|\n", "I have one dream!");
	int e = printf("%20.6s|\n", "I have one dream!");
	printf("%d   %d\n",ee, e);
	setlocale (LC_ALL, "");
	int	uu = ft_printf("%10.5S|\n", NULL);
	int u = printf("%10.5S|\n", NULL);
	printf("%d   %d\n", uu, u);
	ft_printf("{%03c}\n", 0);
	printf("{%03c}\n", 0);
	return (0);
}
