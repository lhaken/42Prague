/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:34:14 by lhaken            #+#    #+#             */
/*   Updated: 2024/02/01 21:34:26 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned int n, char *base, size_t *cnt)
{
	int	res;

	(*cnt)++;
	res = base[n % 16];
	n = n / 16;
	if (n != 0)
		ft_puthex(n, base, cnt);
	write(1, &res, 1);
}
