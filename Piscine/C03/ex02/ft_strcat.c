/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:33:24 by lhaken            #+#    #+#             */
/*   Updated: 2023/09/12 13:04:04 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_get_len(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	idx;
	int	dest_len;

	idx = 0;
	dest_len = ft_get_len(dest);
	while (src[idx] != '\0')
	{
		dest[dest_len + idx] = src[idx];
		idx++;
	}
	dest[dest_len + idx] = '\0';
	return (dest);
}
