/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 11:08:21 by lhaken            #+#    #+#             */
/*   Updated: 2024/10/20 11:08:22 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static int	ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	write_op(char *op, char let)
{
	if (let == 'x')
		return ;
	write(1, op, ft_strlen(op));
	write(1, &let, 1);
	write(1, "\n", 1);
}
