/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:16:24 by lhaken            #+#    #+#             */
/*   Updated: 2023/09/14 10:31:20 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb <= 0)
	{
		if (nb == 0)
		{
			return (1);
		}
		else
		{
			return (0);
		}
	}
	else if (nb > 0)
	{
		return (ft_recursive_factorial(nb - 1) * nb);
	}
	return (0);
}
