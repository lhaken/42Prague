/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:52:41 by lhaken            #+#    #+#             */
/*   Updated: 2023/09/28 16:20:26 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str);
int	check(char *base);
int	in_base(char c, char *base);
int	from_base(char c, char *base);
int	ft_recursive_power(int nb, int power);

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

void	ft_fill_str(char *res, long long int nbr, char *base_to, int len)
{
	int	pwr;

	pwr = 1;
	while (nbr > ft_recursive_power(ft_strlen(base_to), pwr))
		pwr++;
	if (pwr != len)
		res[0] = '-';
	len--;
	if (check(base_to) == 1)
	{
		if (nbr == 0)
		{
			res[len] = base_to[nbr % ft_strlen(base_to)];
			return ;
		}
		while (len >= 0 && res[len] != '-')
		{
			res[len] = base_to[nbr % ft_strlen(base_to)];
			nbr = nbr / ft_strlen(base_to);
			len--;
		}
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char				*res;
	long long int		num;
	int					sign;
	int					pwr;

	sign = 0;
	pwr = 1;
	num = ft_atoi_base(nbr, base_from);
	if (num < 0)
	{
		num = -num;
		sign = 1;
	}
	while (num > ft_recursive_power(ft_strlen(base_to), pwr))
	{
		pwr++;
	}
	res = (char *) malloc(sign + pwr);
	ft_fill_str(res, num, base_to, pwr + sign);
	return (res);
}
