/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:57:42 by lhaken            #+#    #+#             */
/*   Updated: 2023/11/18 12:57:44 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int				rem;
	long long int	num;

	num = n;
	if (num < 0)
	{
		write(fd, "-", 1);
		num *= -1;
	}
	if (num > 9)
	{
		rem = (num % 10) + '0';
		num = num / 10;
		ft_putnbr_fd(num, fd);
		write(fd, &rem, 1);
	}
	else
	{
		num = num + '0';
		write(fd, &num, 1);
	}
}
