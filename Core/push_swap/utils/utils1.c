#include "../pushswap.h"
#include "./utils.h"

void	print_stack(t_stack **stack)
{
	t_stack	*curr;

	curr = *stack;
	if (curr != NULL)
	{
		while (curr->next != NULL)
		{
			printf("%d\n", curr->data);
			curr = curr->next;
		}
		printf("%d\n", curr->data);
	}
	else
	{
		printf("(empty)\n");
	}
}

int	get_stack_size(t_stack **stack)
{
	t_stack	*curr;
	int		size;

	curr = *stack;
	size = 0;
	if (curr != NULL)
	{
		while (curr->next != NULL)
		{
			size++;
			curr = curr->next;
		}
		size++;
		return (size);
	}
	else
	{
		return (0);
	}
}

int	check_sort(t_stack *stack)
{
	t_stack	*next;

	if (get_stack_size(&stack) == 0)
		return (0);
	while (stack)
	{
		next = stack->next;
		while (next)
		{
			if (stack->data > next->data)
				return (0);
			next = next->next;
		}
		stack = stack->next;
	}
	return (1);
}

int	get_last(t_stack *stack) // do i need size?
{
	while ((stack)->next != NULL)
	{
		(stack) = (stack)->next;
	}
	return ((stack)->data);
}

void	check_last(t_stack **stack, int low, int size)
{
	if (size == 5)
	{
		if (low == get_last(*stack))
			op_rev_rotate(stack);
	}
	if (low == (*stack)->next->next->next->data)
	{
		op_rev_rotate(stack);
		if (size == 5)
			op_rev_rotate(stack);
	}
}

int	get_lowest(t_stack *stack) // low as return arg, return val -> pos, to determin if rot or rev_rot for push_low()
{
	int	low;

	low = (stack)->data;
	while ((stack)->next != NULL)
	{
		(stack) = (stack)->next;
		if ((stack)->data < low)
			low = (stack)->data;
	}
	return (low);
}

void	push_lowest(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	cnt;

	cnt = 0;
	while (cnt != 1)
	{
		if ((*stack_a)->data == get_lowest(*stack_a))
		{
			op_push(stack_a, stack_b);
			if (size == 5)
				op_push(stack_a, stack_b);
			cnt++;
		}
		else
			op_rotate(stack_a);
	}
}

void	worst_case(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_b)->data > (*stack_a)->next->data
		&& (*stack_b)->data < get_last(*stack_a))
	{
		op_rev_rotate(stack_a);
		op_push(stack_b, stack_a);
		op_rotate(stack_a);
		op_rotate(stack_a);
	}
}
