#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./ops/operations.h"
# include "./utils/utils.h"

/* LINKED LIST */
typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

/* MAIN */
int		main(int argc, char **argv);

/* OPS */
void	swap_stack(t_stack **stack);
void	swap(t_stack **stack_a, t_stack **stack_b);

/* UTILS */

#endif