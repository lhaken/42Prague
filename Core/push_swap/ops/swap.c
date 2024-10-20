/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:45:33 by lhaken            #+#    #+#             */
/*   Updated: 2024/10/17 15:45:33 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	op_swap(t_stack **stack, char let)
{
	int	temp;

	if (get_stack_size(stack) > 1)
	{
		temp = (*stack)->data;
		(*stack)->data = (*stack)->next->data;
		(*stack)->next->data = temp;
		write_op("s", let);
	}
	else
	{
		return ;
	}
}

void	op_swap_both(t_stack **stack_a, t_stack **stack_b)
{
	if (get_stack_size(stack_a) < 2 || get_stack_size(stack_b) < 2)
		return ;
	op_swap(stack_a, 'x');
	op_swap(stack_b, 'x');
	write(1, "ss\n", 3);
}
