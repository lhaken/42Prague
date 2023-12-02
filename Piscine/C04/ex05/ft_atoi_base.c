/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:30:01 by lhaken            #+#    #+#             */
/*   Updated: 2023/09/25 10:15:04 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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

int	in_base(char c, char *base)
{
	while (*base != '\0')
	{
		if (c == *base)
		{
			return (1);
		}
		base++;
	}
	return (0);
}

int	from_base(char c, char *base)
{
	int	val;

	val = 0;
	while (*base != '\0' && *base != c)
	{
		val++;
		base++;
	}
	return (val);
}

int	ft_atoi_base(char *str, char *base)
{
	int	minus;
	int	res;
	int	base_size;

	if (check(base) == 0)
		return (0);
	minus = 1;
	res = 0;
	base_size = ft_strlen(base);
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\f' || *str == '\r' || *str == '\v')
	{
		str++;
	}
	while (*str != '\0' && (*str == '+' || *str == '-'
			|| in_base(*str, base) == 1))
	{
		if (*str == '-')
			minus *= -1;
		else if (in_base(*str, base))
			res = (base_size * res) + from_base(*str, base);
		str++;
	}
	return (minus * res);
}
