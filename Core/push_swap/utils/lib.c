#include "./utils.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	minus;
	int	sign;
	int	res;

	res = 0;
	while (ft_isspace(*nptr))
		nptr++;
	sign = 0;
	minus = 1;
	while (*nptr == '+' || *nptr == '-')
	{
		sign++;
		if (*nptr == '-')
			minus *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9' && sign <= 1)
	{
		res = res * 10 + (*nptr - 48);
		nptr++;
	}
	return (res * minus);
}
