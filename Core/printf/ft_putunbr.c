#include "ft_printf.h"

void	ft_putunbr(unsigned int n, int *cnt)
{
	unsigned int	rem;

	(*cnt)++;
	if (n > 9)
	{
		rem = (n % 10) + '0';
		n = n / 10;
		ft_putunbr(n, cnt);
		write(1, &rem, 1);
	}
	else
	{
		n = n + '0';
		write(1, &n, 1);
	}
}