/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:44:41 by lhaken            #+#    #+#             */
/*   Updated: 2024/10/17 15:44:42 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	op_rev_rotate(t_stack **stack)
{
	t_stack	*new_last;

	if (get_stack_size(stack) == 0)
		return ;
	new_last = *stack;
	while (new_last->next->next != NULL)
		new_last = new_last->next;
	move_node(stack, new_last->next->data);
	if (new_last->next != NULL)
	{
		free(new_last->next);
		new_last->next = NULL;
	}
	write(1, "rev rotate\n", 12); // TODO - correct letter
}

void	op_rev_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	if (get_stack_size(stack_a) < 2 || get_stack_size(stack_b) < 2)
		return ;
	op_rev_rotate(stack_a);
	op_rev_rotate(stack_b);
	write(1, "rrr\n", 3);
}
