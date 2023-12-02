/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:06:42 by lhaken            #+#    #+#             */
/*   Updated: 2023/09/12 14:42:43 by lhaken           ###   ########.fr       */
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

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	idx;
	int				dest_len;

	idx = 0;
	dest_len = ft_get_len(dest);
	if (nb > 0)
	{
		while (src[idx] != '\0' && idx < nb)
		{
			dest[dest_len + idx] = src[idx];
			idx++;
		}
		dest[dest_len + idx] = '\0';
	}
	return (dest);
}
