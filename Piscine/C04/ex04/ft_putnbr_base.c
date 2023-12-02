/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 11:51:26 by lhaken            #+#    #+#             */
/*   Updated: 2023/09/24 11:31:44 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

int	check(char *base)
{
	int	idx_i;
	int	idx_j;

	idx_i = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[idx_i] != '\0')
	{
		if (base[idx_i] == '+' || base[idx_i] == '-')
			return (0);
		if (base[idx_i] < ' ' && base[idx_i] > '~')
			return (0);
		idx_j = idx_i + 1;
		while (base[idx_j] != '\0')
		{
			if (base[idx_i] == base[idx_j])
				return (0);
			idx_j++;
		}
		idx_i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long int		num;
	int					size;
	char				res;

	num = nbr;
	if (check(base) == 1)
	{
		if (num < 0)
		{
			write(1, "-", 1);
			num = -num;
		}
		size = ft_strlen(base);
		if (num >= 0)
		{
			res = base[num % size];
			num = num / size;
			if (num != 0)
				ft_putnbr_base(num, base);
			write(1, &res, 1);
		}
	}
}
