/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:33:04 by lhaken            #+#    #+#             */
/*   Updated: 2023/09/24 09:49:27 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	int				rem;
	long long int	n;

	n = nb;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		rem = (n % 10) + 48;
		n = n / 10;
		ft_putnbr(n);
		write(1, &rem, 1);
	}
	else
	{
		n = n + 48;
		write(1, &n, 1);
	}
}

void	ft_print_comb2(void)
{
	int	x;
	int	y;

	x = 0;
	while (x < 99)
	{
		y = x + 1;
		while (y <= 99)
		{
			if (x <= 9)
				write(1, "0", 1);
			ft_putnbr(x);
			write(1, " ", 1);
			if (y <= 9)
				write(1, "0", 1);
			ft_putnbr(y);
			if (x != 98 || y != 99)
			{
				write(1, ", ", 2);
			}
			y++;
		}
		x++;
	}
}
