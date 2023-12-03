#include "printf.h"

static void	ft_convert_hex(unsigned long int n, int *cnt)
{
	char	*base;
	int		res;

	(*cnt)++;
	base = "0123456789abcdef";
	res = base[n % 16];
	n = n / 16;
	if (n != 0)
		ft_convert_hex(n, cnt);
	write(1, &res, 1);
}

void	ft_putptr(void *ptr, int *cnt)
{
	unsigned long int	p;

	(*cnt) = (*cnt) + 2;
	p = (unsigned long int) ptr;
	ft_putstr("0x", cnt);
	if (!ptr)
	{
		(*cnt)++;
		write(1, "0", 1);
	}
	ft_convert_hex(p, cnt);
}
