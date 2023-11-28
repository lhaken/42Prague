/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:58:29 by lhaken            #+#    #+#             */
/*   Updated: 2023/11/18 13:11:26 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_sep(char c, char sep)
{
	if (c == '\0')
		return (1);
	if (c == sep)
		return (1);
	return (0);
}

static int	count_words(char const *str, char sep)
{
	int	idx;
	int	count;

	idx = 0;
	count = 0;
	while (str[idx] != '\0')
	{
		if (check_sep(str[idx], sep) == 0
			&& check_sep(str[idx + 1], sep) == 1)
			count++;
		idx++;
	}
	return (count);
}

static void	copy_word(char *d, char const *s, char sep)
{
	int	idx;

	idx = 0;
	while (!check_sep(s[idx], sep))
	{
		d[idx] = s[idx];
		idx++;
	}
	d[idx] = '\0';
}

static void	get_words(char **ar, char const *str, char sep)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (check_sep(str[i], sep))
			i++;
		else
		{
			j = 0;
			while (!check_sep(str[i + j], sep))
				j++;
			ar[count] = (char *) malloc (j + 1);
			copy_word(ar[count], &str[i], sep);
			i = i + j;
			count++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**ar;

	count = count_words(s, c);
	ar = (char **) malloc (sizeof(char *) * (count + 1));
	if (!ar)
		return (NULL);
	get_words(ar, s, c);
	ar[count] = NULL;
	return (ar);
}
