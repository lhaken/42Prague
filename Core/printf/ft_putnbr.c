#include "ft_printf.h"

void	ft_putnbr(int n, size_t *cnt)
{
	int				rem;
	long long int	num;

	num = n;
	(*cnt)++;
	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
	}
	if (num > 9)
	{
		rem = (num % 10) + '0';
		num = num / 10;
		ft_putnbr(num, cnt);
		write(1, &rem, 1);
	}
	else
	{
		num = num + '0';
		write(1, &num, 1);
	}
}