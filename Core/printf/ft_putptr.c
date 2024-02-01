/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:34:02 by lhaken            #+#    #+#             */
/*   Updated: 2024/02/01 22:15:59 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_convert_hex(unsigned long int n, size_t *cnt)
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

void	ft_putptr(void *ptr, size_t *cnt)
{
	unsigned long int	p;

	p = (unsigned long int) ptr;
	if (!ptr)
	{
		(*cnt) = (*cnt) + 5;
		write(1, "(nil)", 5);
	}
	else
	{
		(*cnt) = (*cnt) + 2;
		write(1, "0x", 2);
		ft_convert_hex(p, cnt);
	}
}
