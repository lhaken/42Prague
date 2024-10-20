/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:48:28 by lhaken            #+#    #+#             */
/*   Updated: 2024/10/17 15:48:29 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_stack	*create_node(int data)
{
	t_stack	*node;

	node = (t_stack *) malloc (sizeof(t_stack));
	node->data = data;
	node->next = NULL;
	return (node);
}

void	move_node(t_stack **stack, int data)
{
	t_stack	*node;

	node = create_node(data);
	node->next = *stack;
	*stack = node;
}

void	init_stack(t_stack **stack, char **argv, int idx)
{
	char **nums;
	
	idx = idx - 1;
	if (idx == 1)
	{
		nums = ft_split(argv[1], ' '); // HAVE TO MAKE THIS WORK
		while (*nums)
		{
			move_node(stack, ft_atoi(*nums));
			nums++;
		}
		printf("A:\n");
		print_stack(stack);
		return ;
	}
	while (idx >= 2)
	{
		move_node(stack, ft_atoi(argv[idx]));
		idx--;
	}
}

void	free_stack(t_stack **stack)
{
	t_stack	*next;

	while (*stack != NULL)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
}
