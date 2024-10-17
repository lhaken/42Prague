/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:41:43 by lhaken            #+#    #+#             */
/*   Updated: 2024/10/17 15:43:59 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "pushswap.h"

/* SORTS */
void	small_sort(t_stack **stack)
{
	if ((*stack)->data < (*stack)->next->data
		&& (*stack)->next->data > (*stack)->next->next->data
		&& (*stack)->next->next->data > (*stack)->data)
	{
		op_swap(stack);
		op_rotate(stack);
	}
	else if ((*stack)->data > (*stack)->next->data
		&& (*stack)->next->next->data < (*stack)->data
		&& (*stack)->next->data > (*stack)->next->next->data)
	{
		op_rotate(stack);
		op_swap(stack);
	}
	else if ((*stack)->data < (*stack)->next->data
		&& (*stack)->next->data > (*stack)->next->next->data)
		op_rev_rotate(stack);
	else if ((*stack)->data > (*stack)->next->data
		&& (*stack)->data > (*stack)->next->next->data)
		op_rotate(stack);
	else if ((*stack)->data > (*stack)->next->data
		&& (*stack)->data < (*stack)->next->next->data)
		op_swap(stack);
}

void	med_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	check_last(stack_a, get_lowest(*stack_a), size);
	push_lowest(stack_a, stack_b, size);
	small_sort(stack_a);
	if (size == 4)
	{
		op_push(stack_b, stack_a);
		write(1, "MED sorted\n", 8);
		return ;
	}
	worst_case(stack_a, stack_b);
	op_push(stack_b, stack_a);
	if ((*stack_a)->data > (*stack_a)->next->data
		&& (*stack_a)->data < (*stack_a)->next->next->data)
		op_swap(stack_a);
	else if ((*stack_a)->data > get_last(*stack_a))
		op_rotate(stack_a);
	op_push(stack_b, stack_a);
}

void	big_sort(t_stack **stack_a, t_stack **stack_b, int size) // TOO MANY LINES
{
	int	*list;
	int	ctrl;
	int	mid;
	int	last;
	int	idx;

	idx = size - 1;
	last = 0;
	list = listize(*stack_a, size);
	if (size <= 100)
		ctrl = 2;
	else
		ctrl = 1;
	while (get_stack_size(stack_a) > 0 && ctrl <= 10)
	{
		if (ctrl == 10)
			mid = list[idx];
		else
			mid = list[(size / 10) * ctrl];
		move_chunks(stack_a, stack_b, mid, last);
		last = mid;
		if (size <= 100)
			ctrl += 2;
		else
			ctrl++;
	}
	while (get_stack_size(stack_b) > 0)
		idx = push_back(stack_a, stack_b, list, idx);
	free(list);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = get_stack_size(stack_a);
	if (check_sort(*stack_a) && get_stack_size(stack_b) == 0)
	{
		free_stack(stack_a);
		write(1, "2nd sorted\n", 12);
		exit (0);
	}
	if (size == 2 && check_sort(*stack_a) != 1)
		op_rotate(stack_a);
	else if (size == 3)
		small_sort(stack_a);
	else if (size >= 4 && size <= 5)
		med_sort(stack_a, stack_b, size);
	else
		big_sort(stack_a, stack_b, size);
	write(1, "1st sorted\n", 12);
}

/* MAIN */
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	check_error(argc, argv);
	init_stack(&stack_a, argv, argc);
	sort(&stack_a, &stack_b);
	printf("A\n=\n");
	print_stack(&stack_a);
	printf("B\n=\n");
	print_stack(&stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
}
