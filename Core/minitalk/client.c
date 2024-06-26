/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:47:32 by lhaken            #+#    #+#             */
/*   Updated: 2024/04/22 11:48:36 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_atoi(char *str)
{
	int	minus;
	int	res;

	minus = 1;
	res = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\f' || *str == '\r' || *str == '\v')
	{
		str++;
	}
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			minus *= -1;
		}
		str++;
	}
	while (*str >= '0' && *str <= '9' && *str != '\0')
	{
		res = 10 * res + (*str - 48);
		str++;
	}
	return (minus * res);
}

static void	ft_byte_encoder(int pid, char c)
{
	int	byte[8];
	int	byte_idx;
	int	char_to_num;

	byte_idx = 8;
	char_to_num = c;
	while (--byte_idx >= 0)
	{
		if ((char_to_num & 1) == 1)
			byte[byte_idx] = 1;
		else if (char_to_num == 0 || (char_to_num & 1) == 0)
			byte[byte_idx] = 0;
		if (char_to_num > 0)
			char_to_num >>= 1;
	}
	while (++byte_idx < 8)
	{
		if (byte[byte_idx] == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1000);
	}
}

int	main(int argc, char *argv[])
{
	unsigned int	pid;
	char			*msg;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		msg = argv[2];
		while (*msg != '\0')
		{
			ft_byte_encoder(pid, *msg);
			msg++;
		}
		ft_byte_encoder(pid, '\n');
	}
	else
	{
		write(1, "\e[0;31mError:\e[0;0m Args\n", 26);
	}
	return (0);
}
