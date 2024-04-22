/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:45:53 by lhaken            #+#    #+#             */
/*   Updated: 2024/04/22 11:47:06 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_putpid(unsigned int n)
{
	char	tmp;

	if (n / 10 > 0)
		ft_putpid(n / 10);
	tmp = n % 10 + '0';
	write(1, &tmp, 1);
}

static void	ft_byte_decoder(int signum)
{
	int			bit;
	static int	num_to_char;
	static int	num_of_bits;

	if (signum == SIGUSR1)
		bit = 0;
	else
		bit = 1;
	num_to_char = (num_to_char << 1) + bit;
	num_of_bits++;
	if (num_of_bits == 8)
	{
		write(1, &num_to_char, 1);
		num_to_char = 0;
		num_of_bits = 0;
	}
}

int	main(void)
{
	struct sigaction	s;

	s.sa_flags = SA_RESTART;
	sigemptyset(&s.sa_mask);
	s.sa_handler = &ft_byte_decoder;
	sigaction(SIGUSR1, &s, 0);
	sigaction(SIGUSR2, &s, 0);
	write(1, "\n", 1);
	write(1, "\e[0;45mminitalk PID: ", 21);
	ft_putpid(getpid());
	write(1, "\e[0;0m\n\n", 8);
	while (1)
		pause();
	return (0);
}
