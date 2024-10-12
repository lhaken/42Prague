#include "operations.h"

void	op_rotate(t_stack **stack)
{
	t_stack	*add;
	t_stack	*remove;
	t_stack	*temp;

	if (get_stack_size(stack) == 0)
		return ;
	add = create_node((*stack)->data);
	remove = *stack;
	*stack = (*stack)->next;
	free(remove);
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = add;
	write(1, "rotate\n", 8); // TODO - correct letter
}

void	op_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	if (get_stack_size(stack_a) < 2 || get_stack_size(stack_b) < 2)
		return ;
	op_rotate(stack_a);
	op_rotate(stack_b);
	write(1, "rr\n", 3);
}
