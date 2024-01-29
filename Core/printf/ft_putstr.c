#include "ft_printf.h"

void	ft_putstr(char *s, size_t *cnt)
{
	int	size;

	size = ft_strlen(s);
	write(1, s, ft_strlen(s));
	(*cnt) = (*cnt) + size;
}