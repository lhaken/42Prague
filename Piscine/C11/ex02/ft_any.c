/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:10:37 by lhaken            #+#    #+#             */
/*   Updated: 2023/09/26 11:18:12 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char *))
{
	while (*tab)
	{
		if (f(*tab) != 0)
		{
			return (1);
		}
		tab++;
	}
	return (0);
}