#include "../pushswap.h"

t_stack	*create_node(t_stack *stack, int data)
{
	t_stack *node;

	node = (t_stack *) malloc (sizeof(t_stack));
	node->data = data;
	node->next = NULL;
	return (node);
}
