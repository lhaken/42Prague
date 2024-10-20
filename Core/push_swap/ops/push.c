/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:45:23 by lhaken            #+#    #+#             */
/*   Updated: 2024/10/17 15:45:24 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	op_push(t_stack **src, t_stack **dest, char let)
{
	t_stack	*temp;

	if (get_stack_size(src) == 0)
		return ;
	temp = *src;
	*src = (*src)->next;
	move_node(dest, temp->data);
	write_op("p", let);
	free(temp);
}
