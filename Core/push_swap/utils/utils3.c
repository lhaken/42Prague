#include "./utils.h"

void	move_chunks(t_stack **stack_a, t_stack **stack_b, int mid, int idx)
{
	int	hold;

	hold = (*stack_a)->data;
	idx = mid - idx;
	op_rotate(stack_a); // WRITE MOVE
	while ((*stack_a)->data != hold && idx > 0)
	{
		if ((*stack_a)->data <= mid)
		{
			op_push(stack_a, stack_b); // WRITE MOVE
			idx--;
		}
		else
			op_rotate(stack_a); // WRITE MOVE
	}
	if ((*stack_a)->data <= mid)
		op_push(stack_a, stack_b); // WRITE MOVE
}

static int	shortest(t_stack *stack, int data)
{
	int	size;
	int	idx;
	int steps;

	size = get_stack_size(&stack);
	idx = 0;
	steps = 0;
	while (stack->data != data)
	{
		stack = stack->next;
		idx++;
	}
	if (idx <= size / 2)
		steps += idx;
	else
		steps = (-1 * (size - idx));
	return (steps);
}

void	push_back(t_stack **stack_a, t_stack **stack_b, int *list, int *size)
{
	int steps;
	
	steps = shortest(*stack_b, list[*size]);
	while ((*stack_b)->data != list[*size])
	{
		if ((*stack_b)->next)
		{
			if((*stack_b)->next->data == list[*size])
			{
				op_swap(stack_b); // WRITE MOVE
				break ;
			}
		}
		if (steps < 0)
			op_rev_rotate(stack_b); // WRITE MOVE
		else
			op_rotate(stack_b); // WRITE MOVE
	}
	*size--;
	op_push(stack_b, stack_a); // WRITE MOVE
}
