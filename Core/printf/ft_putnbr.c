/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:33:43 by lhaken            #+#    #+#             */
/*   Updated: 2024/02/01 21:33:50 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
