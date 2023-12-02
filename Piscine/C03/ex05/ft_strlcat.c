/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:31:49 by lhaken            #+#    #+#             */
/*   Updated: 2023/09/27 13:56:41 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	d_len;
	unsigned int	idx;

	if (size < 1)
	{
		return (ft_strlen(src) + size);
	}
	d_len = ft_strlen(dest);
	idx = 0;
	while (src[idx] != '\0' && d_len + idx < size - 1)
	{
		dest[d_len + idx] = src[idx];
		idx++;
	}
	dest[d_len + idx] = '\0';
	if (size < d_len)
	{
		return (size + ft_strlen(src));
	}
	else
	{
		return (d_len + ft_strlen(src));
	}
}
