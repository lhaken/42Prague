#include "ft_printf.h"

void	ft_putchar(char c, int *cnt)
{
	write(1, &c, 1);
	(*cnt)++;
}