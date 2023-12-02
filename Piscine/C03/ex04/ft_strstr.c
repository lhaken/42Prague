/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:54:12 by lhaken            #+#    #+#             */
/*   Updated: 2023/09/26 14:30:22 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*res;
	char	*tmp_s;
	char	*tmp_f;

	if (*to_find == '\0')
	{
		return (str);
	}
	while (*str != '\0')
	{
		tmp_s = str;
		tmp_f = to_find;
		res = str;
		while (*tmp_s == *tmp_f)
		{
			tmp_s++;
			tmp_f++;
			if (*tmp_f == '\0')
			{
				return (res);
			}
		}
		str++;
	}
	return (0);
}
