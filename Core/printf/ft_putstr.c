/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:34:40 by lhaken            #+#    #+#             */
/*   Updated: 2024/02/01 21:52:37 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, size_t *cnt)
{
	int	size;

	if (s == NULL)
	{
		s = "(null)";
		size = ft_strlen(s);
		write(1, s, ft_strlen(s));
	}
	else
	{
		size = ft_strlen(s);
		write(1, s, ft_strlen(s));
	}
	(*cnt) = (*cnt) + size;
}
