#include "./utils.h"

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

static void	sort_list(int *list, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (list[i] > list[j])
				ft_swap(&list[i], &list[j]);
			j++;
		}
		i++;
	}
}

int	*listize(t_stack *stack_a, int size)
{
	t_stack	*cur;
	int	*res;
	int	idx;

	cur = stack_a;
	res = (int*) malloc (sizeof(int) * size + 1);
	idx = 0;
	if (!res)
		return (0);
	while (cur)
	{
		res[idx] = cur->data;
		cur = cur->next;
		idx++;
	}
	sort_list(res, size);
	return (res);
}
