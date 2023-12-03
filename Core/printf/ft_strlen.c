#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx] != '\0')
	{
		idx++;
	}
	return (idx);
}
