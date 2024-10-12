#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <stdio.h> // TODO - delete (i think lol - only for printf testing)
#include <unistd.h>
#include <stdlib.h>

/* LINKED LIST */
typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

# include "./ops/operations.h"
# include "./utils/utils.h"

/* MAIN */
int		main(int argc, char **argv);

#endif