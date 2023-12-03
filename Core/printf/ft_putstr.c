#include "ft_printf.h"

void	ft_putstr(char *s, int *cnt)
{
	int	size;

	size = ft_strlen(s);
	write(1, s, ft_strlen(s));
	(*cnt) = (*cnt) + size;
}
