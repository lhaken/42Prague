#include "pushswap.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/* STRUCT DEF */
/*typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;*/

/* PROTOTYPES */
/*int	get_stack_size(t_stack **stack);*/

/* LIBFT */
/*static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	minus;
	int	sign;
	int	res;

	res = 0;
	while (ft_isspace(*nptr))
		nptr++;
	sign = 0;
	minus = 1;
	while (*nptr == '+' || *nptr == '-')
	{
		sign++;
		if (*nptr == '-')
			minus *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9' && sign <= 1)
	{
		res = res * 10 + (*nptr - 48);
		nptr++;
	}
	return (res * minus);
}*/

/* STRUCT MANAGEMENT */
/*t_stack	*create_node(int data)
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
}*/

/* OPS */
/*void	op_swap(t_stack **stack)
{
	int	temp;

	if (get_stack_size(stack) > 1)
	{
		temp = (*stack)->data;
		(*stack)->data = (*stack)->next->data;
		(*stack)->next->data = temp;
		write(1, "swap\n", 6);
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
	op_swap(stack_a);
	op_swap(stack_b);
	write(1, "swap both\n", 11);
}

void	op_push(t_stack **src, t_stack **dest)
{
	t_stack	*temp;

	if (get_stack_size(src) == 0)
		return ;
	temp = *src;
	*src = (*src)->next;
	move_node(dest, temp->data);
	write(1, "push\n", 6);
	free(temp);
}

void	op_rotate(t_stack **stack) // first becomes last
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
	write(1, "rotate\n", 8);
}

void	op_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	if (get_stack_size(stack_a) < 2 || get_stack_size(stack_b) < 2)
		return ;
	op_rotate(stack_a);
	op_rotate(stack_b);
	write(1, "rr\n", 3);
}

void	op_rev_rotate(t_stack **stack)
{
	t_stack	*new_last;

	if (get_stack_size(stack) == 0)
		return ;
	new_last = *stack;
	while (new_last->next->next != NULL)
		new_last = new_last->next;
	move_node(stack, new_last->next->data);
	if (new_last->next != NULL)
	{
		free(new_last->next);
		new_last->next = NULL;
	}
	write(1, "rev rotate\n", 12);
}

void	op_rev_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	if (get_stack_size(stack_a) < 2 || get_stack_size(stack_b) < 2)
		return ;
	op_rev_rotate(stack_a);
	op_rev_rotate(stack_b);
	write(1, "rrr\n", 3);
}*/

/* DEBUG */
/*void	print_stack(t_stack **stack)
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
}*/

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

void	med_sort(t_stack **stack_a, t_stack **stack_b, int size) // for 4 or 5 args
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

void	big_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	*list;
	int	ctrl;
	int	mid;
	int	last;
	int idx;

	idx = size - 1;
	last = 0;
	list = listize(*stack_a, size);
	if (size <= 100)
		ctrl = 2;
	else
		ctrl = 1;
	while (get_stack_size(stack_a) > 0 && ctrl <= 10)
	{
		if  (ctrl == 10)
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
		push_back(stack_a, stack_b, list, &idx);
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

/* ERRORS */
/*int	check_dup(int argc, char **argv)
{
	int	x;
	int	y;

	x = 1;
	while (x < argc - 1)
	{
		y = x + 1;
		while (y < argc)
		{
			if (ft_atoi(argv[x]) == ft_atoi(argv[y]))
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

int	is_valid(char *str)
{
	while (*str != '\0')
	{
		if ((*str < '0' && *str > '9') && *str != '-')
		{
			return (0);
		}
		str++;
	}
	return (1);
}

int	check_valid(int argc, char **argv)
{
	int	idx;

	idx = 1;
	while (idx < argc)
	{
		if (is_valid(argv[idx]) == 0)
			return (1);
		idx++;
	}
	return (0);
}

int	check_error(int argc, char **argv) // TODO CHECK FOR HIGHER THAN MAX INT && FIX VAL ERROR
{
	if (argc <= 1)
	{
		write(1, "sorted\n", 8);
		exit(0);
	}
	if (check_dup(argc, argv))
	{
		printf("Error - dup\n");
		exit(1);
	}
	if (check_valid(argc, argv))
	{
		printf("Error - val\n");
		exit(1);
	}
}*/

/* MAIN */
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	check_error(argc, argv);
	init_stack(&stack_a, argv, argc);
	/*printf("low: %d\n", get_lowest(stack_a));
	printf("last: %d\n", get_last(stack_a));
	printf("low: %d\n", get_lowest(stack_a));*/
	sort(&stack_a, &stack_b);
	printf("A\n=\n");
	print_stack(&stack_a);
	printf("B\n=\n");
	print_stack(&stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	printf("DONE");
}
