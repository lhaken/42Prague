#include "../pushswap.h"

void	swap_stack(t_stack **stack)
{
	int	temp;

	temp = (*stack)->data;
	(*stack)->data = (*stack)->next->data;
	(*stack)->next->data = temp;
}

void	swap(t_stack **stack_a, t_stack **stack_b)
{
	swap_stack(stack_a);
	swap_stack(stack_b);
}
