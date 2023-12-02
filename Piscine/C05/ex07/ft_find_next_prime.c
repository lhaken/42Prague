/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:22:24 by lhaken            #+#    #+#             */
/*   Updated: 2023/09/21 16:38:25 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	num;

	num = 2;
	if (nb < 2)
	{
		return (0);
	}
	else
	{
		while (num <= nb / num)
		{
			if (nb % num == 0)
			{
				return (0);
			}
			num++;
		}
		return (1);
	}
}

int	ft_find_next_prime(int nb)
{
	int	num;

	num = nb;
	if (nb < 2)
	{
		return (2);
	}
	else
	{
		while (ft_is_prime(num) != 1)
		{
			num++;
		}
		return (num);
	}
}
