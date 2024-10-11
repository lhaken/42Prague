# include "operations.h"

void	op_push(t_stack **src, t_stack **dest)
{
	t_stack	*temp;

	if (get_stack_size(src) == 0)
		return ;
	temp = *src;
	*src = (*src)->next;
	move_node(dest, temp->data);
	write(1, "push\n", 6); // TODO - correct letter
	free(temp);
}