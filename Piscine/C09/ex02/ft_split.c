/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:15:56 by lhaken            #+#    #+#             */
/*   Updated: 2023/09/25 14:50:31 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_sep(char c, char *charset)
{
	if (c == '\0')
		return (1);
	while (*charset != '\0')
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	idx;
	int	count;

	idx = 0;
	count = 0;
	while (str[idx] != '\0')
	{
		if (check_sep(str[idx], charset) == 0
			&& check_sep(str[idx + 1], charset) == 1)
			count++;
		idx++;
	}
	return (count);
}

void	cpy_word(char *dest, char *src, char *charset)
{
	while (!check_sep(*src, charset))
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
}

void	get_words(char **array, char *str, char *charset)
{
	int	idx_i;
	int	idx_j;
	int	count;

	idx_i = 0;
	count = 0;
	while (str[idx_i] != '\0')
	{
		if (check_sep(str[idx_i], charset))
			idx_i++;
		else
		{
			idx_j = 0;
			while (!check_sep(str[idx_i + idx_j], charset))
				idx_j++;
			array[count] = (char *) malloc(idx_j + 1);
			cpy_word(array[count], str + idx_i, charset);
			idx_i = idx_i + idx_j;
			count++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	int		count;
	char	**ar;

	count = count_words(str, charset);
	ar = (char **) malloc(sizeof(char *) * (count + 1));
	ar[count] = 0;
	get_words(ar, str, charset);
	return (ar);
}
