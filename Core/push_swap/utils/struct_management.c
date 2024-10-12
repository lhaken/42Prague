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
	idx = idx - 1;
	while (idx >= 1)
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
