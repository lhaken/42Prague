#include "printf.h"

void    ft_puthex(unsigned int n, char *base, int *cnt)
{
	int	res;

	(*cnt)++;
	res = base[n % 16];
	n = n / 16;
	if (n != 0)
		ft_puthex(n, base, cnt);
	write(1, &res, 1);
}
