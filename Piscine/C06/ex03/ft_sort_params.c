/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:19:42 by lhaken            #+#    #+#             */
/*   Updated: 2023/09/21 14:41:04 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0')
	{
		if (*s1 > *s2)
		{
			return (*s1 - *s2);
		}
		else if (*s1 < *s2)
		{
			return (*s1 - *s2);
		}
		else
		{
			s1++;
			s2++;
		}
	}
	if (*s1 == '\0' && *s2 != '\0')
	{
		return (*s1 - *s2);
	}
	else
	{
		return (0);
	}
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_print_res(char	*ar[], int limit)
{
	int	idx;

	idx = 1;
	while (idx < limit)
	{
		ft_putstr(ar[idx]);
		write(1, "\n", 1);
		idx++;
	}
}

int	main(int argc, char	*argv[])
{
	int	idx_i;
	int	idx_j;
	int	min;

	idx_i = 1;
	while (idx_i < argc)
	{
		idx_j = idx_i + 1;
		min = idx_i;
		while (idx_j < argc)
		{
			if (ft_strcmp(argv[idx_j], argv[min]) < 0)
			{
				min = idx_j;
			}
			idx_j++;
		}
		ft_swap(&argv[min], &argv[idx_i]);
		idx_i++;
	}
	ft_print_res(argv, argc);
}
