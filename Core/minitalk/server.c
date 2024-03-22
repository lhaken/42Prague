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
	static int	num_to_char; // static sets the value to 0 by default, also doesnt change in between calls i guess (find it in chat)
	static int	num_of_bits;

	if (signum == SIGUSR1)
		bit = 0;
	else
		bit = 1;
	num_to_char = (num_to_char << 1) + bit; // creating the byte
	num_of_bits++;
	if (num_of_bits == 8) // full byte constructed
	{
		write(1, &num_to_char, 1);
		num_to_char = 0;
		num_of_bits = 0;
	}
}

int	main(void)
{
	struct sigaction	s;

	s.sa_flags = SA_RESTART; // man -> when using custom handler
	sigemptyset(&s.sa_mask); // no signals blocked -> passing everything to handler
	s.sa_handler = &ft_byte_decoder;
	sigaction(SIGUSR1, &s, 0); // takes a signum, structure, "next" structure -> 0 tells us we don't care about the prev
	sigaction(SIGUSR2, &s, 0);
	write(1, "\n", 1);
	write(1, "\e[0;45mminitalk PID: ", 21);
	ft_putpid(getpid());
	write(1, "\e[0;0m\n\n", 8);
	while (1)
		pause();
	return (0);
}
