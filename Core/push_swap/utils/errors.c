#include "./utils.h"

int	check_dup(int argc, char **argv)
{
	int	x;
	int	y;

	x = 1;
	while (x < argc - 1)
	{
		y = x + 1;
		while (y < argc)
		{
			if (ft_atoi(argv[x]) == ft_atoi(argv[y]))
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

int	is_valid(char *str)
{
	while (*str != '\0')
	{
		if ((*str < '0' && *str > '9') && *str != '-')
		{
			return (0);
		}
		str++;
	}
	return (1);
}

int	check_valid(int argc, char **argv)
{
	int	idx;

	idx = 1;
	while (idx < argc)
	{
		if (is_valid(argv[idx]) == 0)
			return (1);
		idx++;
	}
	return (0);
}

int	check_error(int argc, char **argv)
// TODO CHECK FOR HIGHER THAN MAX INT && FIX VAL ERROR
{
	if (argc <= 1)
	{
		write(1, "sorted\n", 8);
		exit(0);
	}
	if (check_dup(argc, argv))
	{
		printf("Error - dup\n");
		exit(1);
	}
	if (check_valid(argc, argv))
	{
		printf("Error - val\n");
		exit(1);
	}
	exit(0);
}
