/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:04:02 by lhaken            #+#    #+#             */
/*   Updated: 2023/09/28 13:54:44 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_recursive_power(int nb, int power)
{
	if (power <= 0)
	{
		if (power == 0)
		{
			return (1);
		}
		else
		{
			return (0);
		}
	}
	else if (power != 0)
	{
		return (ft_recursive_power(nb, power - 1) * nb);
	}
	else
	{
		return (0);
	}
}
