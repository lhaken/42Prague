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
